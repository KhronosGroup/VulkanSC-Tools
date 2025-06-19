/*
 * Copyright (c) 2015-2025 The Khronos Group Inc.
 * Copyright (c) 2015-2019 Valve Corporation
 * Copyright (c) 2015-2019 LunarG, Inc.
 * Copyright (c) 2025 RasterGrid Kft.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#define _GNU_SOURCE
#include <ctype.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <signal.h>

#include <vulkan/vulkan_sc.h>

#include "linmath.h"
#include "object_type_string_helper.h"

#include "gettime.h"
#include "inttypes.h"
#define MILLION 1000000L
#define BILLION 1000000000L

// Safety critical high watermarks
#define MAX_INSTANCE_LAYER_COUNT 16
#define MAX_INSTANCE_EXTENSION_COUNT 64
#define MAX_PHYSICAL_DEVICE_COUNT 16
#define MAX_PHYSICAL_DEVICE_EXTENSION_COUNT 256
#define MAX_QUEUE_FAMILY_COUNT 32
#define MAX_SWAPCHAIN_IMAGE_COUNT 16
#define MAX_PRESENT_MODE_COUNT 16
#define MAX_DISPLAY_COUNT 32
#define MAX_DISPLAY_PLANE_COUNT 32
#define MAX_SURFACE_FORMAT_COUNT 256
#define MAX_DEBUG_MESSAGE_LENGTH 8192
#define MAX_PIPELINE_POOL_SIZE 1048576
#define MAX_COMMAND_POOL_SIZE 1048576
#define DEMO_TEXTURE_COUNT 1
#define APP_SHORT_NAME "vksccube"
#define APP_LONG_NAME "Vulkan SC Cube"

// Allow a maximum of two outstanding presentation operations.
#define FRAME_LAG 2

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

#if defined(NDEBUG) && defined(__GNUC__)
#define U_ASSERT_ONLY __attribute__((unused))
#else
#define U_ASSERT_ONLY
#endif

#if defined(__GNUC__)
#define UNUSED __attribute__((unused))
#else
#define UNUSED
#endif

#define ERR_EXIT(err_msg, err_class) \
    do {                             \
        printf("%s\n", err_msg);     \
        fflush(stdout);              \
        exit(1);                     \
    } while (0)
void DbgMsg(char *fmt, ...) {
    va_list va;
    va_start(va, fmt);
    vprintf(fmt, va);
    va_end(va);
    fflush(stdout);
}

PFN_vkSetDebugUtilsObjectNameEXT fpnSetDebugUtilsObjectNameEXT;
PFN_vkCmdBeginDebugUtilsLabelEXT pfnCmdBeginDebugUtilsLabelEXT;
PFN_vkCmdEndDebugUtilsLabelEXT pfnCmdEndDebugUtilsLabelEXT;
PFN_vkCreateDebugUtilsMessengerEXT pfnCreateDebugUtilsMessengerEXT;
PFN_vkGetPhysicalDeviceSurfaceSupportKHR pfnGetPhysicalDeviceSurfaceSupportKHR;
PFN_vkGetPhysicalDeviceSurfaceFormatsKHR pfnGetPhysicalDeviceSurfaceFormatsKHR;
PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR pfnGetPhysicalDeviceSurfaceCapabilitiesKHR;
PFN_vkGetPhysicalDeviceSurfacePresentModesKHR pfnGetPhysicalDeviceSurfacePresentModesKHR;
PFN_vkCreateSwapchainKHR pfnCreateSwapchainKHR;
PFN_vkGetSwapchainImagesKHR pfnGetSwapchainImagesKHR;
PFN_vkReleaseDisplayEXT pfnReleaseDisplayEXT;
#ifdef VK_USE_PLATFORM_WIN32_KHR
PFN_vkAcquireWinrtDisplayNV pfnAcquireWinrtDisplayNV;
#endif

void initialize_entry_points(VkInstance instance) {
    fpnSetDebugUtilsObjectNameEXT =
        (PFN_vkSetDebugUtilsObjectNameEXT)vkGetInstanceProcAddr(instance, "vkSetDebugUtilsObjectNameEXT");
    pfnCmdBeginDebugUtilsLabelEXT =
        (PFN_vkCmdBeginDebugUtilsLabelEXT)vkGetInstanceProcAddr(instance, "vkCmdBeginDebugUtilsLabelEXT");
    pfnCmdEndDebugUtilsLabelEXT = (PFN_vkCmdEndDebugUtilsLabelEXT)vkGetInstanceProcAddr(instance, "vkCmdEndDebugUtilsLabelEXT");
    pfnCreateDebugUtilsMessengerEXT = (PFN_vkCreateDebugUtilsMessengerEXT)vkGetInstanceProcAddr(instance, "vkCreateDebugUtilsMessengerEXT");
    pfnGetPhysicalDeviceSurfaceSupportKHR = (PFN_vkGetPhysicalDeviceSurfaceSupportKHR)vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceSurfaceSupportKHR");
    pfnGetPhysicalDeviceSurfaceFormatsKHR = (PFN_vkGetPhysicalDeviceSurfaceFormatsKHR)vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceSurfaceFormatsKHR");
    pfnGetPhysicalDeviceSurfaceCapabilitiesKHR = (PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR)vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceSurfaceCapabilitiesKHR");
    pfnGetPhysicalDeviceSurfacePresentModesKHR = (PFN_vkGetPhysicalDeviceSurfacePresentModesKHR)vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceSurfacePresentModesKHR");
    pfnCreateSwapchainKHR = (PFN_vkCreateSwapchainKHR)vkGetInstanceProcAddr(instance, "vkCreateSwapchainKHR");
    pfnGetSwapchainImagesKHR = (PFN_vkGetSwapchainImagesKHR)vkGetInstanceProcAddr(instance, "vkGetSwapchainImagesKHR");
    pfnReleaseDisplayEXT = (PFN_vkReleaseDisplayEXT)vkGetInstanceProcAddr(instance, "vkReleaseDisplayEXT");
#ifdef VK_USE_PLATFORM_WIN32_KHR
    pfnAcquireWinrtDisplayNV = (PFN_vkAcquireWinrtDisplayNV)vkGetInstanceProcAddr(instance, "vkAcquireWinrtDisplayNV");
#endif
}

/*
 * structure to track all objects related to a texture.
 */
struct texture_object {
    VkSampler sampler;

    VkImage image;
    VkBuffer buffer;
    VkImageLayout imageLayout;

    VkMemoryAllocateInfo mem_alloc;
    VkDeviceMemory mem;
    VkImageView view;
    int32_t tex_width, tex_height;
};

static char *tex_files[] = {"logo.ppm"};

static int validation_error = 0;

struct vktexcube_vs_uniform {
    // Must start with MVP
    float mvp[4][4];
    float position[12 * 3][4];
    float attr[12 * 3][4];
};

//--------------------------------------------------------------------------------------
// Mesh and VertexFormat Data
//--------------------------------------------------------------------------------------
// clang-format off
static const float g_vertex_buffer_data[] = {
    -1.0f,-1.0f,-1.0f,  // -X side
    -1.0f,-1.0f, 1.0f,
    -1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f,-1.0f,
    -1.0f,-1.0f,-1.0f,

    -1.0f,-1.0f,-1.0f,  // -Z side
     1.0f, 1.0f,-1.0f,
     1.0f,-1.0f,-1.0f,
    -1.0f,-1.0f,-1.0f,
    -1.0f, 1.0f,-1.0f,
     1.0f, 1.0f,-1.0f,

    -1.0f,-1.0f,-1.0f,  // -Y side
     1.0f,-1.0f,-1.0f,
     1.0f,-1.0f, 1.0f,
    -1.0f,-1.0f,-1.0f,
     1.0f,-1.0f, 1.0f,
    -1.0f,-1.0f, 1.0f,

    -1.0f, 1.0f,-1.0f,  // +Y side
    -1.0f, 1.0f, 1.0f,
     1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f,-1.0f,
     1.0f, 1.0f, 1.0f,
     1.0f, 1.0f,-1.0f,

     1.0f, 1.0f,-1.0f,  // +X side
     1.0f, 1.0f, 1.0f,
     1.0f,-1.0f, 1.0f,
     1.0f,-1.0f, 1.0f,
     1.0f,-1.0f,-1.0f,
     1.0f, 1.0f,-1.0f,

    -1.0f, 1.0f, 1.0f,  // +Z side
    -1.0f,-1.0f, 1.0f,
     1.0f, 1.0f, 1.0f,
    -1.0f,-1.0f, 1.0f,
     1.0f,-1.0f, 1.0f,
     1.0f, 1.0f, 1.0f,
};

static const float g_uv_buffer_data[] = {
    0.0f, 1.0f,  // -X side
    1.0f, 1.0f,
    1.0f, 0.0f,
    1.0f, 0.0f,
    0.0f, 0.0f,
    0.0f, 1.0f,

    1.0f, 1.0f,  // -Z side
    0.0f, 0.0f,
    0.0f, 1.0f,
    1.0f, 1.0f,
    1.0f, 0.0f,
    0.0f, 0.0f,

    1.0f, 0.0f,  // -Y side
    1.0f, 1.0f,
    0.0f, 1.0f,
    1.0f, 0.0f,
    0.0f, 1.0f,
    0.0f, 0.0f,

    1.0f, 0.0f,  // +Y side
    0.0f, 0.0f,
    0.0f, 1.0f,
    1.0f, 0.0f,
    0.0f, 1.0f,
    1.0f, 1.0f,

    1.0f, 0.0f,  // +X side
    0.0f, 0.0f,
    0.0f, 1.0f,
    0.0f, 1.0f,
    1.0f, 1.0f,
    1.0f, 0.0f,

    0.0f, 0.0f,  // +Z side
    0.0f, 1.0f,
    1.0f, 0.0f,
    0.0f, 1.0f,
    1.0f, 1.0f,
    1.0f, 0.0f,
};
// clang-format on

void dumpMatrix(const char *note, mat4x4 MVP) {
    int i;

    printf("%s: \n", note);
    for (i = 0; i < 4; i++) {
        printf("%f, %f, %f, %f\n", MVP[i][0], MVP[i][1], MVP[i][2], MVP[i][3]);
    }
    printf("\n");
    fflush(stdout);
}

void dumpVec4(const char *note, vec4 vector) {
    printf("%s: \n", note);
    printf("%f, %f, %f, %f\n", vector[0], vector[1], vector[2], vector[3]);
    printf("\n");
    fflush(stdout);
}

char const *to_string(VkPhysicalDeviceType const type) {
    switch (type) {
        case VK_PHYSICAL_DEVICE_TYPE_OTHER:
            return "Other";
        case VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU:
            return "IntegratedGpu";
        case VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU:
            return "DiscreteGpu";
        case VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU:
            return "VirtualGpu";
        case VK_PHYSICAL_DEVICE_TYPE_CPU:
            return "Cpu";
        default:
            return "Unknown";
    }
}

typedef enum WSI_PLATFORM {
    WSI_PLATFORM_AUTO = 0,
    WSI_PLATFORM_DISPLAY,
    WSI_PLATFORM_FILE,
    WSI_PLATFORM_INVALID,  // Sentinel just to indicate invalid user input
} WSI_PLATFORM;

WSI_PLATFORM wsi_from_string(const char *str) {
    if (strcmp(str, "auto") == 0) return WSI_PLATFORM_AUTO;
#if defined(VK_USE_PLATFORM_DISPLAY_KHR)
    if (strcmp(str, "display") == 0) return WSI_PLATFORM_DISPLAY;
#endif
    if (strcmp(str, "file") == 0) return WSI_PLATFORM_FILE;
    return WSI_PLATFORM_INVALID;
};

const char *wsi_to_string(WSI_PLATFORM wsi_platform) {
    switch (wsi_platform) {
        case (WSI_PLATFORM_AUTO):
            return "auto";
#if defined(VK_USE_PLATFORM_DISPLAY_KHR)
        case (WSI_PLATFORM_DISPLAY):
            return "display";
#endif
        case (WSI_PLATFORM_FILE):
            return "file";
        default:
            return "unknown";
    }
};

typedef struct {
    VkImage image;
    VkCommandBuffer cmd;
    VkCommandBuffer graphics_to_present_cmd;
    VkImageView view;
    VkBuffer uniform_buffer;
    VkDeviceMemory uniform_memory;
    void *uniform_memory_ptr;
    VkFramebuffer framebuffer;
    VkDescriptorSet descriptor_set;
} SwapchainImageResources;

struct demo {
#if defined(VK_USE_PLATFORM_DISPLAY_KHR)
    VkDisplayKHR display;
#endif
    WSI_PLATFORM wsi_platform;
    VkSurfaceKHR surface;
    bool prepared;
    bool use_staging_buffer;
    bool separate_present_queue;
    bool is_minimized;
    bool invalid_gpu_selection;
    int32_t gpu_number;

    bool VK_KHR_incremental_present_enabled;
    bool VK_NV_acquire_winrt_display_supported;

    VkInstance inst;
    VkPhysicalDevice gpu;
    VkDevice device;
    VkQueue graphics_queue;
    VkQueue present_queue;
    uint32_t graphics_queue_family_index;
    uint32_t present_queue_family_index;
    VkSemaphore image_acquired_semaphores[FRAME_LAG];
    VkSemaphore draw_complete_semaphores[FRAME_LAG];
    VkSemaphore image_ownership_semaphores[FRAME_LAG];
    VkPhysicalDeviceProperties gpu_props;
    VkQueueFamilyProperties queue_props[MAX_QUEUE_FAMILY_COUNT];
    VkPhysicalDeviceMemoryProperties memory_properties;

    uint32_t enabled_extension_count;
    uint32_t enabled_layer_count;
    char *extension_names[64];
    char *enabled_layers[64];

    int width, height;
    VkFormat format;
    VkColorSpaceKHR color_space;

    uint32_t swapchainImageCount;
    VkSwapchainKHR swapchain;
    SwapchainImageResources swapchain_image_resources[MAX_SWAPCHAIN_IMAGE_COUNT];
    VkPresentModeKHR presentMode;
    VkFence fences[FRAME_LAG];
    int frame_index;
    bool first_swapchain_frame;

    VkCommandPool cmd_pool;
    VkCommandPool present_cmd_pool;

    struct {
        VkFormat format;

        VkImage image;
        VkMemoryAllocateInfo mem_alloc;
        VkDeviceMemory mem;
        VkImageView view;
    } depth;

    struct {
        struct {
            VkImage image;
            VkMemoryAllocateInfo mem_alloc;
            VkDeviceMemory mem;
            VkImageView view;
        } img;

        struct {
            VkBuffer buffer;
            VkMemoryAllocateInfo mem_alloc;
            VkDeviceMemory mem;
        } staging;
    } offscreen_texture;

    struct texture_object textures[DEMO_TEXTURE_COUNT];
    struct texture_object staging_texture;

    VkCommandBuffer cmd;  // Buffer for initialization commands
    VkPipelineLayout pipeline_layout;
    VkDescriptorSetLayout desc_layout;
    VkPipelineCache pipeline_cache;
    char* pipeline_cache_path;
    VkRenderPass render_pass;
    VkPipeline pipeline;

    mat4x4 projection_matrix;
    mat4x4 view_matrix;
    mat4x4 model_matrix;

    float spin_angle;
    float spin_increment;
    bool pause;

    VkDescriptorPool desc_pool;

    bool quit;
    int32_t curFrame;
    int32_t frameCount;
    bool validate;
    bool use_break;
    bool suppress_popups;
    bool force_errors;

    VkDebugUtilsMessengerEXT dbg_messenger;

    uint32_t current_buffer;
    uint32_t queue_family_count;
};

VKAPI_ATTR VkBool32 VKAPI_CALL debug_messenger_callback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
                                                        VkDebugUtilsMessageTypeFlagsEXT messageType,
                                                        const VkDebugUtilsMessengerCallbackDataEXT *pCallbackData,
                                                        void *pUserData) {
    char prefix[64] = "";
    static char message[MAX_DEBUG_MESSAGE_LENGTH];
    memset(message, 0, MAX_DEBUG_MESSAGE_LENGTH);
    struct demo *demo = (struct demo *)pUserData;

    if (demo->use_break) {
#ifndef WIN32
        raise(SIGTRAP);
#else
        DebugBreak();
#endif
    }

    if (messageSeverity & VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT) {
        strcat(prefix, "VERBOSE : ");
    } else if (messageSeverity & VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT) {
        strcat(prefix, "INFO : ");
    } else if (messageSeverity & VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT) {
        strcat(prefix, "WARNING : ");
    } else if (messageSeverity & VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT) {
        strcat(prefix, "ERROR : ");
    }

    if (messageType & VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT) {
        strcat(prefix, "GENERAL");
    } else {
        if (messageType & VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT) {
            strcat(prefix, "VALIDATION");
            validation_error = 1;
        }
        if (messageType & VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT) {
            if (messageType & VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT) {
                strcat(prefix, "|");
            }
            strcat(prefix, "PERFORMANCE");
        }
    }

    sprintf(message, "%s - Message Id Number: %d | Message Id Name: %s\n\t%s\n", prefix, pCallbackData->messageIdNumber,
            pCallbackData->pMessageIdName == NULL ? "" : pCallbackData->pMessageIdName, pCallbackData->pMessage);
    if (pCallbackData->objectCount > 0) {
        char tmp_message[500];
        sprintf(tmp_message, "\n\tObjects - %d\n", pCallbackData->objectCount);
        strcat(message, tmp_message);
        for (uint32_t object = 0; object < pCallbackData->objectCount; ++object) {
            sprintf(tmp_message, "\t\tObject[%d] - %s", object, string_VkObjectType(pCallbackData->pObjects[object].objectType));
            strcat(message, tmp_message);

            VkObjectType t = pCallbackData->pObjects[object].objectType;
            if (t == VK_OBJECT_TYPE_INSTANCE || t == VK_OBJECT_TYPE_PHYSICAL_DEVICE || t == VK_OBJECT_TYPE_DEVICE ||
                t == VK_OBJECT_TYPE_COMMAND_BUFFER || t == VK_OBJECT_TYPE_QUEUE) {
                sprintf(tmp_message, ", Handle %p", (void *)(uintptr_t)(pCallbackData->pObjects[object].objectHandle));
                strcat(message, tmp_message);
            } else {
                sprintf(tmp_message, ", Handle Ox%" PRIx64, (pCallbackData->pObjects[object].objectHandle));
                strcat(message, tmp_message);
            }

            if (NULL != pCallbackData->pObjects[object].pObjectName && strlen(pCallbackData->pObjects[object].pObjectName) > 0) {
                sprintf(tmp_message, ", Name \"%s\"", pCallbackData->pObjects[object].pObjectName);
                strcat(message, tmp_message);
            }
            sprintf(tmp_message, "\n");
            strcat(message, tmp_message);
        }
    }
    if (pCallbackData->cmdBufLabelCount > 0) {
        char tmp_message[500];
        sprintf(tmp_message, "\n\tCommand Buffer Labels - %d\n", pCallbackData->cmdBufLabelCount);
        strcat(message, tmp_message);
        for (uint32_t cmd_buf_label = 0; cmd_buf_label < pCallbackData->cmdBufLabelCount; ++cmd_buf_label) {
            sprintf(tmp_message, "\t\tLabel[%d] - %s { %f, %f, %f, %f}\n", cmd_buf_label,
                    pCallbackData->pCmdBufLabels[cmd_buf_label].pLabelName, pCallbackData->pCmdBufLabels[cmd_buf_label].color[0],
                    pCallbackData->pCmdBufLabels[cmd_buf_label].color[1], pCallbackData->pCmdBufLabels[cmd_buf_label].color[2],
                    pCallbackData->pCmdBufLabels[cmd_buf_label].color[3]);
            strcat(message, tmp_message);
        }
    }

    printf("%s\n", message);
    fflush(stdout);

    // Don't bail out, but keep going.
    return false;
}

bool ActualTimeLate(uint64_t desired, uint64_t actual, uint64_t rdur) {
    // The desired time was the earliest time that the present should have
    // occured.  In almost every case, the actual time should be later than the
    // desired time.  We should only consider the actual time "late" if it is
    // after "desired + rdur".
    if (actual <= desired) {
        // The actual time was before or equal to the desired time.  This will
        // probably never happen, but in case it does, return false since the
        // present was obviously NOT late.
        return false;
    }
    uint64_t deadline = desired + rdur;
    if (actual > deadline) {
        return true;
    } else {
        return false;
    }
}
bool CanPresentEarlier(uint64_t earliest, uint64_t actual, uint64_t margin, uint64_t rdur) {
    if (earliest < actual) {
        // Consider whether this present could have occured earlier.  Make sure
        // that earliest time was at least 2msec earlier than actual time, and
        // that the margin was at least 2msec:
        uint64_t diff = actual - earliest;
        if ((diff >= (2 * MILLION)) && (margin >= (2 * MILLION))) {
            // This present could have occured earlier because both: 1) the
            // earliest time was at least 2 msec before actual time, and 2) the
            // margin was at least 2msec.
            return true;
        }
    }
    return false;
}

// Forward declarations:
static void demo_resize(struct demo *demo);
static void demo_create_surface(struct demo *demo);

#if defined(__GNUC__) || defined(__clang__)
#define DECORATE_PRINTF(_fmt_argnum, _first_param_num) __attribute__((format(printf, _fmt_argnum, _first_param_num)))
#else
#define DECORATE_PRINTF(_fmt_num, _first_param_num)
#endif

DECORATE_PRINTF(4, 5)
static void demo_name_object(struct demo *demo, VkObjectType object_type, uint64_t vulkan_handle, const char *format, ...) {
    if (!demo->validate) {
        return;
    }
    VkResult U_ASSERT_ONLY err;
    char name[1024];
    va_list argptr;
    va_start(argptr, format);
    vsnprintf(name, sizeof(name), format, argptr);
    va_end(argptr);
    name[sizeof(name) - 1] = '\0';

    VkDebugUtilsObjectNameInfoEXT obj_name = {
        .sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT,
        .pNext = NULL,
        .objectType = object_type,
        .objectHandle = vulkan_handle,
        .pObjectName = name,
    };
    err = fpnSetDebugUtilsObjectNameEXT(demo->device, &obj_name);
    assert(!err);
}

DECORATE_PRINTF(4, 5)
static void demo_push_cb_label(struct demo *demo, VkCommandBuffer cb, const float *color, const char *format, ...) {
    if (!demo->validate) {
        return;
    }
    char name[1024];
    va_list argptr;
    va_start(argptr, format);
    vsnprintf(name, sizeof(name), format, argptr);
    va_end(argptr);
    name[sizeof(name) - 1] = '\0';

    VkDebugUtilsLabelEXT label = {
        .sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT,
        .pNext = NULL,
        .pLabelName = name,
    };
    if (color) {
        memcpy(label.color, color, sizeof(label.color));
    }

    pfnCmdBeginDebugUtilsLabelEXT(cb, &label);
}

static void demo_pop_cb_label(struct demo *demo, VkCommandBuffer cb) {
    if (!demo->validate) {
        return;
    }
    pfnCmdEndDebugUtilsLabelEXT(cb);
}

static bool memory_type_from_properties(struct demo *demo, uint32_t typeBits, VkFlags requirements_mask, uint32_t *typeIndex) {
    // Search memtypes to find first index with those properties
    for (uint32_t i = 0; i < VK_MAX_MEMORY_TYPES; i++) {
        if ((typeBits & 1) == 1) {
            // Type is available, does it match user properties?
            if ((demo->memory_properties.memoryTypes[i].propertyFlags & requirements_mask) == requirements_mask) {
                *typeIndex = i;
                return true;
            }
        }
        typeBits >>= 1;
    }
    // No memory types matched, return failure
    return false;
}

static void demo_flush_init_cmd(struct demo *demo) {
    VkResult U_ASSERT_ONLY err;

    // This function could get called twice if the texture uses a staging buffer
    // In that case the second call should be ignored
    if (demo->cmd == VK_NULL_HANDLE) return;

    err = vkEndCommandBuffer(demo->cmd);
    assert(!err);

    VkFence fence;
    VkFenceCreateInfo fence_ci = {.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO, .pNext = NULL, .flags = 0};
    if (demo->force_errors) {
        // Remove sType to intentionally force validation layer errors.
        fence_ci.sType = 0;
    }
    err = vkCreateFence(demo->device, &fence_ci, NULL, &fence);
    assert(!err);
    demo_name_object(demo, VK_OBJECT_TYPE_FENCE, (uint64_t)fence, "InitFence");

    const VkCommandBuffer cmd_bufs[] = {demo->cmd};
    VkSubmitInfo submit_info = {.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO,
                                .pNext = NULL,
                                .waitSemaphoreCount = 0,
                                .pWaitSemaphores = NULL,
                                .pWaitDstStageMask = NULL,
                                .commandBufferCount = 1,
                                .pCommandBuffers = cmd_bufs,
                                .signalSemaphoreCount = 0,
                                .pSignalSemaphores = NULL};

    err = vkQueueSubmit(demo->graphics_queue, 1, &submit_info, fence);
    assert(!err);

    err = vkWaitForFences(demo->device, 1, &fence, VK_TRUE, UINT64_MAX);
    assert(!err);

    vkFreeCommandBuffers(demo->device, demo->cmd_pool, 1, cmd_bufs);
    vkDestroyFence(demo->device, fence, NULL);
    demo->cmd = VK_NULL_HANDLE;
}

static void demo_set_image_layout(struct demo *demo, VkImage image, VkImageAspectFlags aspectMask, VkImageLayout old_image_layout,
                                  VkImageLayout new_image_layout, VkAccessFlagBits srcAccessMask, VkPipelineStageFlags src_stages,
                                  VkPipelineStageFlags dest_stages) {
    assert(demo->cmd);

    VkImageMemoryBarrier image_memory_barrier = {.sType = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER,
                                                 .pNext = NULL,
                                                 .srcAccessMask = srcAccessMask,
                                                 .dstAccessMask = 0,
                                                 .srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED,
                                                 .dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED,
                                                 .oldLayout = old_image_layout,
                                                 .newLayout = new_image_layout,
                                                 .image = image,
                                                 .subresourceRange = {aspectMask, 0, 1, 0, 1}};

    switch (new_image_layout) {
        case VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL:
            /* Make sure anything that was copying from this image has completed */
            image_memory_barrier.dstAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
            break;

        case VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL:
            image_memory_barrier.dstAccessMask = VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;
            break;

        case VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL:
            image_memory_barrier.dstAccessMask = VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT;
            break;

        case VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL:
            image_memory_barrier.dstAccessMask = VK_ACCESS_SHADER_READ_BIT | VK_ACCESS_INPUT_ATTACHMENT_READ_BIT;
            break;

        case VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL:
            image_memory_barrier.dstAccessMask = VK_ACCESS_TRANSFER_READ_BIT;
            break;

        case VK_IMAGE_LAYOUT_PRESENT_SRC_KHR:
            image_memory_barrier.dstAccessMask = VK_ACCESS_MEMORY_READ_BIT;
            break;

        default:
            image_memory_barrier.dstAccessMask = 0;
            break;
    }

    VkImageMemoryBarrier *pmemory_barrier = &image_memory_barrier;

    vkCmdPipelineBarrier(demo->cmd, src_stages, dest_stages, 0, 0, NULL, 0, NULL, 1, pmemory_barrier);
}

static void demo_draw_build_cmd(struct demo *demo, VkCommandBuffer cmd_buf) {
    const VkCommandBufferBeginInfo cmd_buf_info = {
        .sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO,
        .pNext = NULL,
        .flags = VK_COMMAND_BUFFER_USAGE_SIMULTANEOUS_USE_BIT,
        .pInheritanceInfo = NULL,
    };
    const VkClearValue clear_values[2] = {
        [0] = {.color.float32 = {0.2f, 0.2f, 0.2f, 0.2f}},
        [1] = {.depthStencil = {1.0f, 0}},
    };
    const VkRenderPassBeginInfo rp_begin = {
        .sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO,
        .pNext = NULL,
        .renderPass = demo->render_pass,
        .framebuffer = demo->swapchain_image_resources[demo->current_buffer].framebuffer,
        .renderArea.offset.x = 0,
        .renderArea.offset.y = 0,
        .renderArea.extent.width = demo->width,
        .renderArea.extent.height = demo->height,
        .clearValueCount = 2,
        .pClearValues = clear_values,
    };
    VkResult U_ASSERT_ONLY err;

    err = vkBeginCommandBuffer(cmd_buf, &cmd_buf_info);

    demo_name_object(demo, VK_OBJECT_TYPE_COMMAND_BUFFER, (uint64_t)cmd_buf, "CubeDrawCommandBuf");

    const float begin_color[4] = {0.4f, 0.3f, 0.2f, 0.1f};
    demo_push_cb_label(demo, cmd_buf, begin_color, "DrawBegin");

    assert(!err);
    vkCmdBeginRenderPass(cmd_buf, &rp_begin, VK_SUBPASS_CONTENTS_INLINE);

    const float renderpass_color[4] = {8.4f, 7.3f, 6.2f, 7.1f};
    demo_push_cb_label(demo, cmd_buf, renderpass_color, "InsideRenderPass");

    vkCmdBindPipeline(cmd_buf, VK_PIPELINE_BIND_POINT_GRAPHICS, demo->pipeline);
    vkCmdBindDescriptorSets(cmd_buf, VK_PIPELINE_BIND_POINT_GRAPHICS, demo->pipeline_layout, 0, 1,
                            &demo->swapchain_image_resources[demo->current_buffer].descriptor_set, 0, NULL);
    VkViewport viewport;
    memset(&viewport, 0, sizeof(viewport));
    float viewport_dimension;
    if (demo->width < demo->height) {
        viewport_dimension = (float)demo->width;
        viewport.y = (demo->height - demo->width) / 2.0f;
    } else {
        viewport_dimension = (float)demo->height;
        viewport.x = (demo->width - demo->height) / 2.0f;
    }
    viewport.height = viewport_dimension;
    viewport.width = viewport_dimension;
    viewport.minDepth = (float)0.0f;
    viewport.maxDepth = (float)1.0f;
    vkCmdSetViewport(cmd_buf, 0, 1, &viewport);

    VkRect2D scissor;
    memset(&scissor, 0, sizeof(scissor));
    scissor.extent.width = demo->width;
    scissor.extent.height = demo->height;
    scissor.offset.x = 0;
    scissor.offset.y = 0;
    vkCmdSetScissor(cmd_buf, 0, 1, &scissor);

    const float draw_color[4] = {-0.4f, -0.3f, -0.2f, -0.1f};
    demo_push_cb_label(demo, cmd_buf, draw_color, "ActualDraw");
    vkCmdDraw(cmd_buf, 12 * 3, 1, 0, 0);
    demo_pop_cb_label(demo, cmd_buf);

    // Note that ending the renderpass changes the image's layout from
    // COLOR_ATTACHMENT_OPTIMAL to PRESENT_SRC_KHR
    vkCmdEndRenderPass(cmd_buf);
    demo_pop_cb_label(demo, cmd_buf);

    if (demo->separate_present_queue) {
        // We have to transfer ownership from the graphics queue family to the
        // present queue family to be able to present.  Note that we don't have
        // to transfer from present queue family back to graphics queue family at
        // the start of the next frame because we don't care about the image's
        // contents at that point.
        VkImageMemoryBarrier image_ownership_barrier = {.sType = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER,
                                                        .pNext = NULL,
                                                        .srcAccessMask = 0,
                                                        .dstAccessMask = 0,
                                                        .oldLayout = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR,
                                                        .newLayout = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR,
                                                        .srcQueueFamilyIndex = demo->graphics_queue_family_index,
                                                        .dstQueueFamilyIndex = demo->present_queue_family_index,
                                                        .image = demo->swapchain_image_resources[demo->current_buffer].image,
                                                        .subresourceRange = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 0, 1}};

        vkCmdPipelineBarrier(cmd_buf, VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT, VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT, 0, 0, NULL, 0,
                             NULL, 1, &image_ownership_barrier);
    }

    if (demo->wsi_platform == WSI_PLATFORM_FILE) {
        VkImageMemoryBarrier image_wait_barrier = {.sType = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER,
                                                   .pNext = NULL,
                                                   .srcAccessMask = VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT,
                                                   .dstAccessMask = VK_ACCESS_TRANSFER_READ_BIT,
                                                   .oldLayout = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
                                                   .newLayout = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
                                                   .srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED,
                                                   .dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED,
                                                   .image = demo->offscreen_texture.img.image,
                                                   .subresourceRange = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 0, 1}};

        vkCmdPipelineBarrier(cmd_buf, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT, 0, 0, NULL, 0, NULL, 1,
                             &image_wait_barrier);

        VkBufferImageCopy copy_region = {
            .bufferOffset = 0,
            .bufferRowLength = demo->width,
            .bufferImageHeight = demo->height,
            .imageSubresource = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 0, 1},
            .imageOffset = {0, 0, 0},
            .imageExtent = {demo->width, demo->height, 1},
        };

        vkCmdCopyImageToBuffer(cmd_buf, demo->offscreen_texture.img.image, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
                               demo->offscreen_texture.staging.buffer, 1, &copy_region);
    }

    demo_pop_cb_label(demo, cmd_buf);
    err = vkEndCommandBuffer(cmd_buf);
    assert(!err);
}

void demo_build_image_ownership_cmd(struct demo *demo, int i) {
    VkResult U_ASSERT_ONLY err;

    const VkCommandBufferBeginInfo cmd_buf_info = {
        .sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO,
        .pNext = NULL,
        .flags = VK_COMMAND_BUFFER_USAGE_SIMULTANEOUS_USE_BIT,
        .pInheritanceInfo = NULL,
    };
    err = vkBeginCommandBuffer(demo->swapchain_image_resources[i].graphics_to_present_cmd, &cmd_buf_info);
    assert(!err);

    VkImageMemoryBarrier image_ownership_barrier = {.sType = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER,
                                                    .pNext = NULL,
                                                    .srcAccessMask = 0,
                                                    .dstAccessMask = 0,
                                                    .oldLayout = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR,
                                                    .newLayout = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR,
                                                    .srcQueueFamilyIndex = demo->graphics_queue_family_index,
                                                    .dstQueueFamilyIndex = demo->present_queue_family_index,
                                                    .image = demo->swapchain_image_resources[i].image,
                                                    .subresourceRange = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 0, 1}};

    vkCmdPipelineBarrier(demo->swapchain_image_resources[i].graphics_to_present_cmd, VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT,
                         VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT, 0, 0, NULL, 0, NULL, 1, &image_ownership_barrier);
    err = vkEndCommandBuffer(demo->swapchain_image_resources[i].graphics_to_present_cmd);
    assert(!err);
}

void demo_update_data_buffer(struct demo *demo) {
    mat4x4 MVP, Model, VP;
    int matrixSize = sizeof(MVP);

    mat4x4_mul(VP, demo->projection_matrix, demo->view_matrix);

    // Rotate around the Y axis
    mat4x4_dup(Model, demo->model_matrix);
    mat4x4_rotate_Y(demo->model_matrix, Model, (float)degreesToRadians(demo->spin_angle));
    mat4x4_orthonormalize(demo->model_matrix, demo->model_matrix);
    mat4x4_mul(MVP, VP, demo->model_matrix);

    memcpy(demo->swapchain_image_resources[demo->current_buffer].uniform_memory_ptr, (const void *)&MVP[0][0], matrixSize);
}

static void demo_draw(struct demo *demo) {
    VkResult U_ASSERT_ONLY err;

    // Ensure no more than FRAME_LAG renderings are outstanding
    vkWaitForFences(demo->device, 1, &demo->fences[demo->frame_index], VK_TRUE, UINT64_MAX);
    vkResetFences(demo->device, 1, &demo->fences[demo->frame_index]);

    if (demo->wsi_platform != WSI_PLATFORM_FILE) {
        do {
            // Get the index of the next available swapchain image:
            err = vkAcquireNextImageKHR(demo->device, demo->swapchain, UINT64_MAX,
                                        demo->image_acquired_semaphores[demo->frame_index], VK_NULL_HANDLE, &demo->current_buffer);

            if (err == VK_ERROR_OUT_OF_DATE_KHR) {
                // demo->swapchain is out of date (e.g. the window was resized) and
                // must be recreated:
                demo_resize(demo);
            } else if (err == VK_SUBOPTIMAL_KHR) {
                // demo->swapchain is not as optimal as it could be, but the platform's
                // presentation engine will still present the image correctly.
                break;
            } else if (err == VK_ERROR_SURFACE_LOST_KHR) {
                vkDestroySurfaceKHR(demo->inst, demo->surface, NULL);
                demo_create_surface(demo);
                demo_resize(demo);
            } else {
                assert(!err);
            }
        } while (err != VK_SUCCESS);
    }

    demo_update_data_buffer(demo);

    // Wait for the image acquired semaphore to be signaled to ensure
    // that the image won't be rendered to until the presentation
    // engine has fully released ownership to the application, and it is
    // okay to render to the image.
    // In case of saving the rendered images to file the graphics queue
    // is fully executed after every frame, so we do not have to synchronize
    // the graphics queue with the present queue
    VkPipelineStageFlags pipe_stage_flags;
    VkSubmitInfo submit_info;
    uint32_t semaphore_count = (demo->wsi_platform != WSI_PLATFORM_FILE) ? 1 : 0;
    submit_info.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
    submit_info.pNext = NULL;
    pipe_stage_flags = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
    submit_info.pWaitDstStageMask = &pipe_stage_flags;
    submit_info.waitSemaphoreCount = semaphore_count;
    submit_info.pWaitSemaphores = &demo->image_acquired_semaphores[demo->frame_index];
    submit_info.commandBufferCount = 1;
    submit_info.pCommandBuffers = &demo->swapchain_image_resources[demo->current_buffer].cmd;
    submit_info.signalSemaphoreCount = semaphore_count;
    submit_info.pSignalSemaphores = &demo->draw_complete_semaphores[demo->frame_index];
    err = vkQueueSubmit(demo->graphics_queue, 1, &submit_info, demo->fences[demo->frame_index]);
    assert(!err);

    if (demo->wsi_platform == WSI_PLATFORM_FILE) {
        // In case of image dump instead of present we wait for graphics queue execution
        // to safely read back the offscreen backbuffer
        vkQueueWaitIdle(demo->graphics_queue);
        return;
    }

    if (demo->separate_present_queue) {
        // If we are using separate queues, change image ownership to the
        // present queue before presenting, waiting for the draw complete
        // semaphore and signalling the ownership released semaphore when finished
        VkFence nullFence = VK_NULL_HANDLE;
        pipe_stage_flags = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
        submit_info.waitSemaphoreCount = 1;
        submit_info.pWaitSemaphores = &demo->draw_complete_semaphores[demo->frame_index];
        submit_info.commandBufferCount = 1;
        submit_info.pCommandBuffers = &demo->swapchain_image_resources[demo->current_buffer].graphics_to_present_cmd;
        submit_info.signalSemaphoreCount = 1;
        submit_info.pSignalSemaphores = &demo->image_ownership_semaphores[demo->frame_index];
        err = vkQueueSubmit(demo->present_queue, 1, &submit_info, nullFence);
        assert(!err);
    }

    // If we are using separate queues we have to wait for image ownership,
    // otherwise wait for draw complete
    VkPresentInfoKHR present = {
        .sType = VK_STRUCTURE_TYPE_PRESENT_INFO_KHR,
        .pNext = NULL,
        .waitSemaphoreCount = 1,
        .pWaitSemaphores = (demo->separate_present_queue) ? &demo->image_ownership_semaphores[demo->frame_index]
                                                          : &demo->draw_complete_semaphores[demo->frame_index],
        .swapchainCount = 1,
        .pSwapchains = &demo->swapchain,
        .pImageIndices = &demo->current_buffer,
    };

    VkRectLayerKHR rect;
    VkPresentRegionKHR region;
    VkPresentRegionsKHR regions;
    if (demo->VK_KHR_incremental_present_enabled) {
        // If using VK_KHR_incremental_present, we provide a hint of the region
        // that contains changed content relative to the previously-presented
        // image.  The implementation can use this hint in order to save
        // work/power (by only copying the region in the hint).  The
        // implementation is free to ignore the hint though, and so we must
        // ensure that the entire image has the correctly-drawn content.
        uint32_t eighthOfWidth = demo->width / 8;
        uint32_t eighthOfHeight = demo->height / 8;

        if (demo->first_swapchain_frame) {
            rect.offset.x = 0;
            rect.offset.y = 0;
            rect.extent.width = demo->width;
            rect.extent.height = demo->height;
        } else {
            rect.offset.x = eighthOfWidth;
            rect.offset.y = eighthOfHeight;
            rect.extent.width = eighthOfWidth * 6;
            rect.extent.height = eighthOfHeight * 6;
        }
        rect.layer = 0;

        region.rectangleCount = 1;
        region.pRectangles = &rect;

        regions.sType = VK_STRUCTURE_TYPE_PRESENT_REGIONS_KHR;
        regions.pNext = present.pNext;
        regions.swapchainCount = present.swapchainCount;
        regions.pRegions = &region;
        present.pNext = &regions;
    }

    err = vkQueuePresentKHR(demo->present_queue, &present);
    demo->frame_index += 1;
    demo->frame_index %= FRAME_LAG;
    demo->first_swapchain_frame = false;

    if (err == VK_ERROR_OUT_OF_DATE_KHR) {
        // demo->swapchain is out of date (e.g. the window was resized) and
        // must be recreated:
        demo_resize(demo);
    } else if (err == VK_SUBOPTIMAL_KHR) {
        // SUBOPTIMAL could be due to a resize
        VkSurfaceCapabilitiesKHR surfCapabilities;
        err = vkGetPhysicalDeviceSurfaceCapabilitiesKHR(demo->gpu, demo->surface, &surfCapabilities);
        if (err != VK_SUCCESS) {
            ERR_EXIT("Failed to get surface capabilities", "vkGetPhysicalDeviceSurfaceCapabilitiesKHR Failure");
        }
        if (surfCapabilities.currentExtent.width != (uint32_t)demo->width ||
            surfCapabilities.currentExtent.height != (uint32_t)demo->height) {
            demo_resize(demo);
        }
    } else if (err == VK_ERROR_SURFACE_LOST_KHR) {
        vkDestroySurfaceKHR(demo->inst, demo->surface, NULL);
        demo_create_surface(demo);
        demo_resize(demo);
    } else {
        assert(!err);
    }
}

static void demo_prepare_buffers(struct demo *demo) {
    VkResult U_ASSERT_ONLY err;

    // Check the surface capabilities and formats
    VkSurfaceCapabilitiesKHR surfCapabilities;
    err = pfnGetPhysicalDeviceSurfaceCapabilitiesKHR(demo->gpu, demo->surface, &surfCapabilities);
    if (err != VK_SUCCESS) {
        ERR_EXIT("Failed to get surface capabilities", "vkGetPhysicalDeviceSurfaceCapabilitiesKHR Failure");
    }

    uint32_t presentModeCount;
    err = pfnGetPhysicalDeviceSurfacePresentModesKHR(demo->gpu, demo->surface, &presentModeCount, NULL);
    if (err != VK_SUCCESS) {
        ERR_EXIT("Failed to get surface present mode count", "vkGetPhysicalDeviceSurfacePresentModesKHR Failure");
    }
    VkPresentModeKHR presentModes[MAX_PRESENT_MODE_COUNT];
    err = pfnGetPhysicalDeviceSurfacePresentModesKHR(demo->gpu, demo->surface, &presentModeCount, presentModes);
    if (err != VK_SUCCESS) {
        ERR_EXIT("Failed to get surface present modes", "vkGetPhysicalDeviceSurfacePresentModesKHR Failure");
    }

    VkExtent2D swapchainExtent;
    // width and height are either both 0xFFFFFFFF, or both not 0xFFFFFFFF.
    if (surfCapabilities.currentExtent.width == 0xFFFFFFFF) {
        // If the surface size is undefined, the size is set to the size
        // of the images requested, which must fit within the minimum and
        // maximum values.
        swapchainExtent.width = demo->width;
        swapchainExtent.height = demo->height;

        if (swapchainExtent.width < surfCapabilities.minImageExtent.width) {
            swapchainExtent.width = surfCapabilities.minImageExtent.width;
        } else if (swapchainExtent.width > surfCapabilities.maxImageExtent.width) {
            swapchainExtent.width = surfCapabilities.maxImageExtent.width;
        }

        if (swapchainExtent.height < surfCapabilities.minImageExtent.height) {
            swapchainExtent.height = surfCapabilities.minImageExtent.height;
        } else if (swapchainExtent.height > surfCapabilities.maxImageExtent.height) {
            swapchainExtent.height = surfCapabilities.maxImageExtent.height;
        }
    } else {
        // If the surface size is defined, the swap chain size must match
        swapchainExtent = surfCapabilities.currentExtent;
        demo->width = surfCapabilities.currentExtent.width;
        demo->height = surfCapabilities.currentExtent.height;
    }

    if (surfCapabilities.maxImageExtent.width == 0 || surfCapabilities.maxImageExtent.height == 0) {
        demo->is_minimized = true;
        return;
    } else {
        demo->is_minimized = false;
    }

    // The FIFO present mode is guaranteed by the spec to be supported
    // and to have no tearing.  It's a great default present mode to use.
    VkPresentModeKHR swapchainPresentMode = VK_PRESENT_MODE_FIFO_KHR;

    //  There are times when you may wish to use another present mode.  The
    //  following code shows how to select them, and the comments provide some
    //  reasons you may wish to use them.
    //
    // It should be noted that Vulkan 1.0 doesn't provide a method for
    // synchronizing rendering with the presentation engine's display.  There
    // is a method provided for throttling rendering with the display, but
    // there are some presentation engines for which this method will not work.
    // If an application doesn't throttle its rendering, and if it renders much
    // faster than the refresh rate of the display, this can waste power on
    // mobile devices.  That is because power is being spent rendering images
    // that may never be seen.

    // VK_PRESENT_MODE_IMMEDIATE_KHR is for applications that don't care about
    // tearing, or have some way of synchronizing their rendering with the
    // display.
    // VK_PRESENT_MODE_MAILBOX_KHR may be useful for applications that
    // generally render a new presentable image every refresh cycle, but are
    // occasionally early.  In this case, the application wants the new image
    // to be displayed instead of the previously-queued-for-presentation image
    // that has not yet been displayed.
    // VK_PRESENT_MODE_FIFO_RELAXED_KHR is for applications that generally
    // render a new presentable image every refresh cycle, but are occasionally
    // late.  In this case (perhaps because of stuttering/latency concerns),
    // the application wants the late image to be immediately displayed, even
    // though that may mean some tearing.

    if (demo->presentMode != swapchainPresentMode) {
        for (size_t i = 0; i < presentModeCount; ++i) {
            if (presentModes[i] == demo->presentMode) {
                swapchainPresentMode = demo->presentMode;
                break;
            }
        }
    }
    if (swapchainPresentMode != demo->presentMode) {
        ERR_EXIT("Present mode specified is not supported", "Present mode unsupported");
    }

    // Determine the number of VkImages to use in the swap chain.
    // Application desires to acquire 3 images at a time for triple
    // buffering
    uint32_t desiredNumOfSwapchainImages = 3;
    if (desiredNumOfSwapchainImages < surfCapabilities.minImageCount) {
        desiredNumOfSwapchainImages = surfCapabilities.minImageCount;
    }
    // If maxImageCount is 0, we can ask for as many images as we want;
    // otherwise we're limited to maxImageCount
    if ((surfCapabilities.maxImageCount > 0) && (desiredNumOfSwapchainImages > surfCapabilities.maxImageCount)) {
        // Application must settle for fewer images than desired:
        desiredNumOfSwapchainImages = surfCapabilities.maxImageCount;
    }

    VkSurfaceTransformFlagsKHR preTransform;
    if (surfCapabilities.supportedTransforms & VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR) {
        preTransform = VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR;
    } else {
        preTransform = surfCapabilities.currentTransform;
    }

    // Find a supported composite alpha mode - one of these is guaranteed to be set
    VkCompositeAlphaFlagBitsKHR compositeAlpha = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR;
    VkCompositeAlphaFlagBitsKHR compositeAlphaFlags[4] = {
        VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR,
        VK_COMPOSITE_ALPHA_PRE_MULTIPLIED_BIT_KHR,
        VK_COMPOSITE_ALPHA_POST_MULTIPLIED_BIT_KHR,
        VK_COMPOSITE_ALPHA_INHERIT_BIT_KHR,
    };
    for (uint32_t i = 0; i < ARRAY_SIZE(compositeAlphaFlags); i++) {
        if (surfCapabilities.supportedCompositeAlpha & compositeAlphaFlags[i]) {
            compositeAlpha = compositeAlphaFlags[i];
            break;
        }
    }

    VkSwapchainCreateInfoKHR swapchain_ci = {
        .sType = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR,
        .pNext = NULL,
        .surface = demo->surface,
        .minImageCount = desiredNumOfSwapchainImages,
        .imageFormat = demo->format,
        .imageColorSpace = demo->color_space,
        .imageExtent =
            {
                .width = swapchainExtent.width,
                .height = swapchainExtent.height,
            },
        .imageUsage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT,
        .preTransform = preTransform,
        .compositeAlpha = compositeAlpha,
        .imageArrayLayers = 1,
        .imageSharingMode = VK_SHARING_MODE_EXCLUSIVE,
        .queueFamilyIndexCount = 0,
        .pQueueFamilyIndices = NULL,
        .presentMode = swapchainPresentMode,
        .oldSwapchain = VK_NULL_HANDLE,
        .clipped = true,
    };
    uint32_t i;
    err = pfnCreateSwapchainKHR(demo->device, &swapchain_ci, NULL, &demo->swapchain);
    assert(!err);

    err = pfnGetSwapchainImagesKHR(demo->device, demo->swapchain, &demo->swapchainImageCount, NULL);
    assert(!err);
    if (demo->swapchainImageCount > MAX_SWAPCHAIN_IMAGE_COUNT) {
        ERR_EXIT("Swapchain image count exceeds application assumed maximum", "App logic assumption violation");
    }

    VkImage swapchainImages[MAX_SWAPCHAIN_IMAGE_COUNT];
    err = pfnGetSwapchainImagesKHR(demo->device, demo->swapchain, &demo->swapchainImageCount, swapchainImages);
    assert(!err);

    for (i = 0; i < demo->swapchainImageCount; i++) {
        demo_name_object(demo, VK_OBJECT_TYPE_IMAGE, (uint64_t)swapchainImages[i], "SwapchainImage(%u)", i);
    }
    for (i = 0; i < demo->swapchainImageCount; i++) {
        VkImageViewCreateInfo color_image_view = {
            .sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO,
            .pNext = NULL,
            .format = demo->format,
            .components =
                {
                    .r = VK_COMPONENT_SWIZZLE_IDENTITY,
                    .g = VK_COMPONENT_SWIZZLE_IDENTITY,
                    .b = VK_COMPONENT_SWIZZLE_IDENTITY,
                    .a = VK_COMPONENT_SWIZZLE_IDENTITY,
                },
            .subresourceRange =
                {.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT, .baseMipLevel = 0, .levelCount = 1, .baseArrayLayer = 0, .layerCount = 1},
            .viewType = VK_IMAGE_VIEW_TYPE_2D,
            .flags = 0,
        };

        demo->swapchain_image_resources[i].image = swapchainImages[i];

        color_image_view.image = demo->swapchain_image_resources[i].image;

        err = vkCreateImageView(demo->device, &color_image_view, NULL, &demo->swapchain_image_resources[i].view);
        assert(!err);
        demo_name_object(demo, VK_OBJECT_TYPE_IMAGE_VIEW, (uint64_t)demo->swapchain_image_resources[i].view, "SwapchainView(%u)",
                         i);
    }
}

static VkResult demo_prepare_offscreen_texture(struct demo *demo) {
    VkResult U_ASSERT_ONLY err;
    bool U_ASSERT_ONLY pass;

    demo->swapchainImageCount = 1;

    const VkBufferCreateInfo buffer_create_info = {.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO,
                                                   .pNext = NULL,
                                                   .flags = 0,
                                                   .size = demo->width * demo->height * 4,
                                                   .usage = VK_BUFFER_USAGE_TRANSFER_DST_BIT,
                                                   .sharingMode = VK_SHARING_MODE_EXCLUSIVE,
                                                   .queueFamilyIndexCount = 0,
                                                   .pQueueFamilyIndices = NULL};

    err = vkCreateBuffer(demo->device, &buffer_create_info, NULL, &demo->offscreen_texture.staging.buffer);
    assert(!err);
    demo_name_object(demo, VK_OBJECT_TYPE_BUFFER, (uint64_t)demo->offscreen_texture.staging.buffer, "StagingBuffer");

    VkMemoryRequirements mem_reqs;
    vkGetBufferMemoryRequirements(demo->device, demo->offscreen_texture.staging.buffer, &mem_reqs);

    demo->offscreen_texture.staging.mem_alloc.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
    demo->offscreen_texture.staging.mem_alloc.pNext = NULL;
    demo->offscreen_texture.staging.mem_alloc.allocationSize = mem_reqs.size;
    demo->offscreen_texture.staging.mem_alloc.memoryTypeIndex = 0;

    VkFlags requirements = VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT;
    pass = memory_type_from_properties(demo, mem_reqs.memoryTypeBits, requirements,
                                       &demo->offscreen_texture.staging.mem_alloc.memoryTypeIndex);
    assert(pass);

    err = vkAllocateMemory(demo->device, &demo->offscreen_texture.staging.mem_alloc, NULL, &demo->offscreen_texture.staging.mem);
    assert(!err);
    demo_name_object(demo, VK_OBJECT_TYPE_DEVICE_MEMORY, (uint64_t)demo->offscreen_texture.staging.mem, "StagingBufferMemory");

    /* bind memory */
    err = vkBindBufferMemory(demo->device, demo->offscreen_texture.staging.buffer, demo->offscreen_texture.staging.mem, 0);
    assert(!err);

    const VkFormat display_format = VK_FORMAT_R8G8B8A8_UNORM;
    const VkImageCreateInfo image = {
        .sType = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO,
        .pNext = NULL,
        .imageType = VK_IMAGE_TYPE_2D,
        .format = display_format,
        .extent = {demo->width, demo->height, 1},
        .mipLevels = 1,
        .arrayLayers = 1,
        .samples = VK_SAMPLE_COUNT_1_BIT,
        .tiling = VK_IMAGE_TILING_OPTIMAL,
        .usage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT | VK_IMAGE_USAGE_TRANSFER_SRC_BIT,
        .flags = 0,
    };

    VkImageViewCreateInfo view = {
        .sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO,
        .pNext = NULL,
        .image = VK_NULL_HANDLE,
        .format = display_format,
        .subresourceRange =
            {.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT, .baseMipLevel = 0, .levelCount = 1, .baseArrayLayer = 0, .layerCount = 1},
        .flags = 0,
        .viewType = VK_IMAGE_VIEW_TYPE_2D,
    };

    demo->format = display_format;

    /* create image */
    err = vkCreateImage(demo->device, &image, NULL, &demo->offscreen_texture.img.image);
    assert(!err);
    demo_name_object(demo, VK_OBJECT_TYPE_IMAGE, (uint64_t)demo->offscreen_texture.img.image, "SurfaceImage");

    vkGetImageMemoryRequirements(demo->device, demo->offscreen_texture.img.image, &mem_reqs);
    assert(!err);

    demo->offscreen_texture.img.mem_alloc.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
    demo->offscreen_texture.img.mem_alloc.pNext = NULL;
    demo->offscreen_texture.img.mem_alloc.allocationSize = mem_reqs.size;
    demo->offscreen_texture.img.mem_alloc.memoryTypeIndex = 0;

    pass = memory_type_from_properties(demo, mem_reqs.memoryTypeBits, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT,
                                       &demo->offscreen_texture.img.mem_alloc.memoryTypeIndex);
    assert(pass);

    /* allocate memory */
    err = vkAllocateMemory(demo->device, &demo->offscreen_texture.img.mem_alloc, NULL, &demo->offscreen_texture.img.mem);
    assert(!err);
    demo_name_object(demo, VK_OBJECT_TYPE_DEVICE_MEMORY, (uint64_t)demo->offscreen_texture.img.mem, "SurfaceImageMem");

    /* bind memory */
    err = vkBindImageMemory(demo->device, demo->offscreen_texture.img.image, demo->offscreen_texture.img.mem, 0);
    assert(!err);

    /* create image view */
    view.image = demo->offscreen_texture.img.image;
    err = vkCreateImageView(demo->device, &view, NULL, &demo->offscreen_texture.img.view);
    assert(!err);
    demo_name_object(demo, VK_OBJECT_TYPE_IMAGE_VIEW, (uint64_t)demo->offscreen_texture.img.view, "SurfaceImageView");

    demo->swapchain_image_resources[0].uniform_memory = demo->offscreen_texture.img.mem;
    demo->swapchain_image_resources[0].image = demo->offscreen_texture.img.image;
    demo->swapchain_image_resources[0].view = demo->offscreen_texture.img.view;

    return err;
}

static void demo_prepare_depth(struct demo *demo) {
    const VkFormat depth_format = VK_FORMAT_D16_UNORM;
    const VkImageCreateInfo image = {
        .sType = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO,
        .pNext = NULL,
        .imageType = VK_IMAGE_TYPE_2D,
        .format = depth_format,
        .extent = {demo->width, demo->height, 1},
        .mipLevels = 1,
        .arrayLayers = 1,
        .samples = VK_SAMPLE_COUNT_1_BIT,
        .tiling = VK_IMAGE_TILING_OPTIMAL,
        .usage = VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT,
        .flags = 0,
    };

    VkImageViewCreateInfo view = {
        .sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO,
        .pNext = NULL,
        .image = VK_NULL_HANDLE,
        .format = depth_format,
        .subresourceRange =
            {.aspectMask = VK_IMAGE_ASPECT_DEPTH_BIT, .baseMipLevel = 0, .levelCount = 1, .baseArrayLayer = 0, .layerCount = 1},
        .flags = 0,
        .viewType = VK_IMAGE_VIEW_TYPE_2D,
    };

    if (demo->force_errors) {
        // Intentionally force a bad pNext value to generate a validation layer error
        view.pNext = &image;
    }

    VkMemoryRequirements mem_reqs;
    VkResult U_ASSERT_ONLY err;
    bool U_ASSERT_ONLY pass;

    demo->depth.format = depth_format;

    /* create image */
    err = vkCreateImage(demo->device, &image, NULL, &demo->depth.image);
    assert(!err);
    demo_name_object(demo, VK_OBJECT_TYPE_IMAGE, (uint64_t)demo->depth.image, "DepthImage");

    vkGetImageMemoryRequirements(demo->device, demo->depth.image, &mem_reqs);
    assert(!err);

    demo->depth.mem_alloc.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
    demo->depth.mem_alloc.pNext = NULL;
    demo->depth.mem_alloc.allocationSize = mem_reqs.size;
    demo->depth.mem_alloc.memoryTypeIndex = 0;

    pass = memory_type_from_properties(demo, mem_reqs.memoryTypeBits, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT,
                                       &demo->depth.mem_alloc.memoryTypeIndex);
    assert(pass);

    /* allocate memory */
    err = vkAllocateMemory(demo->device, &demo->depth.mem_alloc, NULL, &demo->depth.mem);
    assert(!err);
    demo_name_object(demo, VK_OBJECT_TYPE_DEVICE_MEMORY, (uint64_t)demo->depth.mem, "DepthMem");

    /* bind memory */
    err = vkBindImageMemory(demo->device, demo->depth.image, demo->depth.mem, 0);
    assert(!err);

    /* create image view */
    view.image = demo->depth.image;
    err = vkCreateImageView(demo->device, &view, NULL, &demo->depth.view);
    assert(!err);
    demo_name_object(demo, VK_OBJECT_TYPE_IMAGE_VIEW, (uint64_t)demo->depth.view, "DepthView");
}

/* Convert ppm image data from header file into RGBA texture image */
bool loadTexture(const char *filename, uint8_t *rgba_data, VkSubresourceLayout *layout, int32_t *width, int32_t *height) {
    (void)filename;
    static const uint8_t logo_ppm[] = {
#include "logo.ppm.h"
    };
    static const size_t logo_ppm_len = sizeof(logo_ppm);
    char *cPtr;
    cPtr = (char *)logo_ppm;
    if ((unsigned char *)cPtr >= (logo_ppm + logo_ppm_len) || strncmp(cPtr, "P6\n", 3)) {
        return false;
    }
    while (strncmp(cPtr++, "\n", 1))
        ;
    sscanf(cPtr, "%u %u", width, height);
    if (rgba_data == NULL) {
        return true;
    }
    while (strncmp(cPtr++, "\n", 1))
        ;
    if ((unsigned char *)cPtr >= (logo_ppm + logo_ppm_len) || strncmp(cPtr, "255\n", 4)) {
        return false;
    }
    while (strncmp(cPtr++, "\n", 1))
        ;
    for (int y = 0; y < *height; y++) {
        uint8_t *rowPtr = rgba_data;
        for (int x = 0; x < *width; x++) {
            memcpy(rowPtr, cPtr, 3);
            rowPtr[3] = 255; /* Alpha of 1 */
            rowPtr += 4;
            cPtr += 3;
        }
        rgba_data += layout->rowPitch;
    }
    return true;
}

static void demo_prepare_texture_buffer(struct demo *demo, const char *filename, struct texture_object *tex_obj) {
    int32_t tex_width;
    int32_t tex_height;
    VkResult U_ASSERT_ONLY err;
    bool U_ASSERT_ONLY pass;

    if (!loadTexture(filename, NULL, NULL, &tex_width, &tex_height)) {
        ERR_EXIT("Failed to load textures", "Load Texture Failure");
    }

    tex_obj->tex_width = tex_width;
    tex_obj->tex_height = tex_height;

    const VkBufferCreateInfo buffer_create_info = {.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO,
                                                   .pNext = NULL,
                                                   .flags = 0,
                                                   .size = tex_width * tex_height * 4,
                                                   .usage = VK_BUFFER_USAGE_TRANSFER_SRC_BIT,
                                                   .sharingMode = VK_SHARING_MODE_EXCLUSIVE,
                                                   .queueFamilyIndexCount = 0,
                                                   .pQueueFamilyIndices = NULL};

    err = vkCreateBuffer(demo->device, &buffer_create_info, NULL, &tex_obj->buffer);
    assert(!err);
    demo_name_object(demo, VK_OBJECT_TYPE_BUFFER, (uint64_t)tex_obj->buffer, "TexBuffer(%s)", filename);

    VkMemoryRequirements mem_reqs;
    vkGetBufferMemoryRequirements(demo->device, tex_obj->buffer, &mem_reqs);

    tex_obj->mem_alloc.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
    tex_obj->mem_alloc.pNext = NULL;
    tex_obj->mem_alloc.allocationSize = mem_reqs.size;
    tex_obj->mem_alloc.memoryTypeIndex = 0;

    VkFlags requirements = VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT;
    pass = memory_type_from_properties(demo, mem_reqs.memoryTypeBits, requirements, &tex_obj->mem_alloc.memoryTypeIndex);
    assert(pass);

    err = vkAllocateMemory(demo->device, &tex_obj->mem_alloc, NULL, &(tex_obj->mem));
    assert(!err);
    demo_name_object(demo, VK_OBJECT_TYPE_DEVICE_MEMORY, (uint64_t)tex_obj->mem, "TexBufMemory(%s)", filename);

    /* bind memory */
    err = vkBindBufferMemory(demo->device, tex_obj->buffer, tex_obj->mem, 0);
    assert(!err);

    VkSubresourceLayout layout;
    memset(&layout, 0, sizeof(layout));
    layout.rowPitch = tex_width * 4;

    void *data;
    err = vkMapMemory(demo->device, tex_obj->mem, 0, tex_obj->mem_alloc.allocationSize, 0, &data);
    assert(!err);

    if (!loadTexture(filename, data, &layout, &tex_width, &tex_height)) {
        fprintf(stderr, "Error loading texture: %s\n", filename);
    }

    vkUnmapMemory(demo->device, tex_obj->mem);
}

static void demo_prepare_texture_image(struct demo *demo, const char *filename, struct texture_object *tex_obj,
                                       VkImageTiling tiling, VkImageUsageFlags usage, VkFlags required_props) {
    const VkFormat tex_format = VK_FORMAT_R8G8B8A8_UNORM;
    int32_t tex_width;
    int32_t tex_height;
    VkResult U_ASSERT_ONLY err;
    bool U_ASSERT_ONLY pass;

    if (!loadTexture(filename, NULL, NULL, &tex_width, &tex_height)) {
        ERR_EXIT("Failed to load textures", "Load Texture Failure");
    }

    tex_obj->tex_width = tex_width;
    tex_obj->tex_height = tex_height;

    const VkImageCreateInfo image_create_info = {
        .sType = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO,
        .pNext = NULL,
        .imageType = VK_IMAGE_TYPE_2D,
        .format = tex_format,
        .extent = {tex_width, tex_height, 1},
        .mipLevels = 1,
        .arrayLayers = 1,
        .samples = VK_SAMPLE_COUNT_1_BIT,
        .tiling = tiling,
        .usage = usage,
        .flags = 0,
        .initialLayout = VK_IMAGE_LAYOUT_PREINITIALIZED,
    };

    VkMemoryRequirements mem_reqs;

    err = vkCreateImage(demo->device, &image_create_info, NULL, &tex_obj->image);
    assert(!err);
    demo_name_object(demo, VK_OBJECT_TYPE_IMAGE, (uint64_t)tex_obj->image, "TexImage(%s)", filename);

    vkGetImageMemoryRequirements(demo->device, tex_obj->image, &mem_reqs);

    tex_obj->mem_alloc.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
    tex_obj->mem_alloc.pNext = NULL;
    tex_obj->mem_alloc.allocationSize = mem_reqs.size;
    tex_obj->mem_alloc.memoryTypeIndex = 0;

    pass = memory_type_from_properties(demo, mem_reqs.memoryTypeBits, required_props, &tex_obj->mem_alloc.memoryTypeIndex);
    assert(pass);

    /* allocate memory */
    err = vkAllocateMemory(demo->device, &tex_obj->mem_alloc, NULL, &(tex_obj->mem));
    assert(!err);
    demo_name_object(demo, VK_OBJECT_TYPE_DEVICE_MEMORY, (uint64_t)tex_obj->mem, "TexImageMem(%s)", filename);

    /* bind memory */
    err = vkBindImageMemory(demo->device, tex_obj->image, tex_obj->mem, 0);
    assert(!err);

    if (required_props & VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT) {
        const VkImageSubresource subres = {
            .aspectMask = VK_IMAGE_ASPECT_COLOR_BIT,
            .mipLevel = 0,
            .arrayLayer = 0,
        };
        VkSubresourceLayout layout;
        void *data;

        vkGetImageSubresourceLayout(demo->device, tex_obj->image, &subres, &layout);

        err = vkMapMemory(demo->device, tex_obj->mem, 0, tex_obj->mem_alloc.allocationSize, 0, &data);
        assert(!err);

        if (!loadTexture(filename, data, &layout, &tex_width, &tex_height)) {
            fprintf(stderr, "Error loading texture: %s\n", filename);
        }

        vkUnmapMemory(demo->device, tex_obj->mem);
    }

    tex_obj->imageLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
}

static void demo_destroy_texture(struct demo *demo, struct texture_object *tex_objs) {
    /* clean up staging resources */
    if (tex_objs->image) vkDestroyImage(demo->device, tex_objs->image, NULL);
    if (tex_objs->buffer) vkDestroyBuffer(demo->device, tex_objs->buffer, NULL);
}

static void demo_prepare_textures(struct demo *demo) {
    const VkFormat tex_format = VK_FORMAT_R8G8B8A8_UNORM;
    VkFormatProperties props;
    uint32_t i;

    vkGetPhysicalDeviceFormatProperties(demo->gpu, tex_format, &props);

    for (i = 0; i < DEMO_TEXTURE_COUNT; i++) {
        VkResult U_ASSERT_ONLY err;

        if ((props.linearTilingFeatures & VK_FORMAT_FEATURE_SAMPLED_IMAGE_BIT) && !demo->use_staging_buffer) {
            demo_push_cb_label(demo, demo->cmd, NULL, "DirectTexture(%u)", i);
            /* Device can texture using linear textures */
            demo_prepare_texture_image(demo, tex_files[i], &demo->textures[i], VK_IMAGE_TILING_LINEAR, VK_IMAGE_USAGE_SAMPLED_BIT,
                                       VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT);
            // Nothing in the pipeline needs to be complete to start, and don't allow fragment
            // shader to run until layout transition completes
            demo_set_image_layout(demo, demo->textures[i].image, VK_IMAGE_ASPECT_COLOR_BIT, VK_IMAGE_LAYOUT_PREINITIALIZED,
                                  demo->textures[i].imageLayout, 0, VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                                  VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT);
            demo->staging_texture.image = 0;
            demo_pop_cb_label(demo, demo->cmd);  // "DirectTexture"
        } else if (props.optimalTilingFeatures & VK_FORMAT_FEATURE_SAMPLED_IMAGE_BIT) {
            /* Must use staging buffer to copy linear texture to optimized */
            demo_push_cb_label(demo, demo->cmd, NULL, "StagingTexture(%u)", i);

            memset(&demo->staging_texture, 0, sizeof(demo->staging_texture));
            demo_prepare_texture_buffer(demo, tex_files[i], &demo->staging_texture);

            demo_prepare_texture_image(demo, tex_files[i], &demo->textures[i], VK_IMAGE_TILING_OPTIMAL,
                                       (VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_SAMPLED_BIT),
                                       VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);

            demo_set_image_layout(demo, demo->textures[i].image, VK_IMAGE_ASPECT_COLOR_BIT, VK_IMAGE_LAYOUT_PREINITIALIZED,
                                  VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, 0, VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                                  VK_PIPELINE_STAGE_TRANSFER_BIT);

            demo_push_cb_label(demo, demo->cmd, NULL, "StagingBufferCopy(%u)", i);

            VkBufferImageCopy copy_region = {
                .bufferOffset = 0,
                .bufferRowLength = demo->staging_texture.tex_width,
                .bufferImageHeight = demo->staging_texture.tex_height,
                .imageSubresource = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 0, 1},
                .imageOffset = {0, 0, 0},
                .imageExtent = {demo->staging_texture.tex_width, demo->staging_texture.tex_height, 1},
            };

            vkCmdCopyBufferToImage(demo->cmd, demo->staging_texture.buffer, demo->textures[i].image,
                                   VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, 1, &copy_region);
            demo_pop_cb_label(demo, demo->cmd);  // "StagingBufferCopy"

            demo_set_image_layout(demo, demo->textures[i].image, VK_IMAGE_ASPECT_COLOR_BIT, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,
                                  demo->textures[i].imageLayout, VK_ACCESS_TRANSFER_WRITE_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT,
                                  VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT);
            demo_pop_cb_label(demo, demo->cmd);  // "StagingTexture"

        } else {
            /* Can't support VK_FORMAT_R8G8B8A8_UNORM !? */
            assert(!"No support for R8G8B8A8_UNORM as texture image format");
        }

        const VkSamplerCreateInfo sampler = {
            .sType = VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO,
            .pNext = NULL,
            .magFilter = VK_FILTER_NEAREST,
            .minFilter = VK_FILTER_NEAREST,
            .mipmapMode = VK_SAMPLER_MIPMAP_MODE_NEAREST,
            .addressModeU = VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE,
            .addressModeV = VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE,
            .addressModeW = VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE,
            .mipLodBias = 0.0f,
            .anisotropyEnable = VK_FALSE,
            .maxAnisotropy = 1,
            .compareOp = VK_COMPARE_OP_NEVER,
            .minLod = 0.0f,
            .maxLod = 0.0f,
            .borderColor = VK_BORDER_COLOR_FLOAT_OPAQUE_WHITE,
            .unnormalizedCoordinates = VK_FALSE,
        };

        VkImageViewCreateInfo view = {
            .sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO,
            .pNext = NULL,
            .image = VK_NULL_HANDLE,
            .viewType = VK_IMAGE_VIEW_TYPE_2D,
            .format = tex_format,
            .components =
                {
                    VK_COMPONENT_SWIZZLE_IDENTITY,
                    VK_COMPONENT_SWIZZLE_IDENTITY,
                    VK_COMPONENT_SWIZZLE_IDENTITY,
                    VK_COMPONENT_SWIZZLE_IDENTITY,
                },
            .subresourceRange = {VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 0, 1},
            .flags = 0,
        };

        /* create sampler */
        err = vkCreateSampler(demo->device, &sampler, NULL, &demo->textures[i].sampler);
        assert(!err);
        demo_name_object(demo, VK_OBJECT_TYPE_SAMPLER, (uint64_t)demo->textures[i].sampler, "Sampler(%u)", i);

        /* create image view */
        view.image = demo->textures[i].image;
        err = vkCreateImageView(demo->device, &view, NULL, &demo->textures[i].view);
        demo_name_object(demo, VK_OBJECT_TYPE_IMAGE_VIEW, (uint64_t)demo->textures[i].view, "TexImageView(%u)", i);
        assert(!err);
    }
}

void demo_prepare_cube_data_buffers(struct demo *demo) {
    VkBufferCreateInfo buf_info;
    VkMemoryRequirements mem_reqs;
    VkMemoryAllocateInfo mem_alloc;
    mat4x4 MVP, VP;
    VkResult U_ASSERT_ONLY err;
    bool U_ASSERT_ONLY pass;
    struct vktexcube_vs_uniform data;

    mat4x4_mul(VP, demo->projection_matrix, demo->view_matrix);
    mat4x4_mul(MVP, VP, demo->model_matrix);
    memcpy(data.mvp, MVP, sizeof(MVP));
    //    dumpMatrix("MVP", MVP);

    for (unsigned int i = 0; i < 12 * 3; i++) {
        data.position[i][0] = g_vertex_buffer_data[i * 3];
        data.position[i][1] = g_vertex_buffer_data[i * 3 + 1];
        data.position[i][2] = g_vertex_buffer_data[i * 3 + 2];
        data.position[i][3] = 1.0f;
        data.attr[i][0] = g_uv_buffer_data[2 * i];
        data.attr[i][1] = g_uv_buffer_data[2 * i + 1];
        data.attr[i][2] = 0;
        data.attr[i][3] = 0;
    }

    memset(&buf_info, 0, sizeof(buf_info));
    buf_info.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
    buf_info.usage = VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT;
    buf_info.size = sizeof(data);

    for (unsigned int i = 0; i < demo->swapchainImageCount; i++) {
        err = vkCreateBuffer(demo->device, &buf_info, NULL, &demo->swapchain_image_resources[i].uniform_buffer);
        assert(!err);
        demo_name_object(demo, VK_OBJECT_TYPE_BUFFER, (uint64_t)demo->swapchain_image_resources[i].uniform_buffer,
                         "SwapchainUniformBuf(%u)", i);

        vkGetBufferMemoryRequirements(demo->device, demo->swapchain_image_resources[i].uniform_buffer, &mem_reqs);

        mem_alloc.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
        mem_alloc.pNext = NULL;
        mem_alloc.allocationSize = mem_reqs.size;
        mem_alloc.memoryTypeIndex = 0;

        pass = memory_type_from_properties(demo, mem_reqs.memoryTypeBits,
                                           VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT,
                                           &mem_alloc.memoryTypeIndex);
        assert(pass);

        err = vkAllocateMemory(demo->device, &mem_alloc, NULL, &demo->swapchain_image_resources[i].uniform_memory);
        assert(!err);
        demo_name_object(demo, VK_OBJECT_TYPE_DEVICE_MEMORY, (uint64_t)demo->swapchain_image_resources[i].uniform_memory,
                         "SwapchainUniformMem(%u)", i);

        err = vkMapMemory(demo->device, demo->swapchain_image_resources[i].uniform_memory, 0, VK_WHOLE_SIZE, 0,
                          &demo->swapchain_image_resources[i].uniform_memory_ptr);
        assert(!err);

        memcpy(demo->swapchain_image_resources[i].uniform_memory_ptr, &data, sizeof data);

        err = vkBindBufferMemory(demo->device, demo->swapchain_image_resources[i].uniform_buffer,
                                 demo->swapchain_image_resources[i].uniform_memory, 0);
        assert(!err);
    }
}

static void demo_prepare_descriptor_layout(struct demo *demo) {
    const VkDescriptorSetLayoutBinding layout_bindings[2] = {
        [0] =
            {
                .binding = 0,
                .descriptorType = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER,
                .descriptorCount = 1,
                .stageFlags = VK_SHADER_STAGE_VERTEX_BIT,
                .pImmutableSamplers = NULL,
            },
        [1] =
            {
                .binding = 1,
                .descriptorType = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER,
                .descriptorCount = DEMO_TEXTURE_COUNT,
                .stageFlags = VK_SHADER_STAGE_FRAGMENT_BIT,
                .pImmutableSamplers = NULL,
            },
    };
    const VkDescriptorSetLayoutCreateInfo descriptor_layout = {
        .sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO,
        .pNext = NULL,
        .bindingCount = 2,
        .pBindings = layout_bindings,
    };
    VkResult U_ASSERT_ONLY err;

    err = vkCreateDescriptorSetLayout(demo->device, &descriptor_layout, NULL, &demo->desc_layout);
    assert(!err);

    const VkPipelineLayoutCreateInfo pPipelineLayoutCreateInfo = {
        .sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO,
        .pNext = NULL,
        .setLayoutCount = 1,
        .pSetLayouts = &demo->desc_layout,
    };

    err = vkCreatePipelineLayout(demo->device, &pPipelineLayoutCreateInfo, NULL, &demo->pipeline_layout);
    assert(!err);
}

static void demo_prepare_render_pass(struct demo *demo) {
    // The initial layout for the color and depth attachments will be LAYOUT_UNDEFINED
    // because at the start of the renderpass, we don't care about their contents.
    // At the start of the subpass, the color attachment's layout will be transitioned
    // to LAYOUT_COLOR_ATTACHMENT_OPTIMAL and the depth stencil attachment's layout
    // will be transitioned to LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL.  At the end of
    // the renderpass, the color attachment's layout will be transitioned to
    // LAYOUT_PRESENT_SRC_KHR or LAYOUT_TRANSFER_SRC_OPTIMAL depending on it is
    // presented or saved to file. This is all done as part of the renderpass.
    VkImageLayout final_layout =
        (demo->wsi_platform != WSI_PLATFORM_FILE) ? VK_IMAGE_LAYOUT_PRESENT_SRC_KHR : VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
    const VkAttachmentDescription attachments[2] = {
        [0] =
            {
                .format = demo->format,
                .flags = 0,
                .samples = VK_SAMPLE_COUNT_1_BIT,
                .loadOp = VK_ATTACHMENT_LOAD_OP_CLEAR,
                .storeOp = VK_ATTACHMENT_STORE_OP_STORE,
                .stencilLoadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE,
                .stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE,
                .initialLayout = VK_IMAGE_LAYOUT_UNDEFINED,
                .finalLayout = final_layout,
            },
        [1] =
            {
                .format = demo->depth.format,
                .flags = 0,
                .samples = VK_SAMPLE_COUNT_1_BIT,
                .loadOp = VK_ATTACHMENT_LOAD_OP_CLEAR,
                .storeOp = VK_ATTACHMENT_STORE_OP_DONT_CARE,
                .stencilLoadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE,
                .stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE,
                .initialLayout = VK_IMAGE_LAYOUT_UNDEFINED,
                .finalLayout = VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL,
            },
    };
    const VkAttachmentReference color_reference = {
        .attachment = 0,
        .layout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL,
    };
    const VkAttachmentReference depth_reference = {
        .attachment = 1,
        .layout = VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL,
    };
    const VkSubpassDescription subpass = {
        .pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS,
        .flags = 0,
        .inputAttachmentCount = 0,
        .pInputAttachments = NULL,
        .colorAttachmentCount = 1,
        .pColorAttachments = &color_reference,
        .pResolveAttachments = NULL,
        .pDepthStencilAttachment = &depth_reference,
        .preserveAttachmentCount = 0,
        .pPreserveAttachments = NULL,
    };

    VkSubpassDependency attachmentDependencies[2] = {
        [0] =
            {
                // Depth buffer is shared between swapchain images
                .srcSubpass = VK_SUBPASS_EXTERNAL,
                .dstSubpass = 0,
                .srcStageMask = VK_PIPELINE_STAGE_EARLY_FRAGMENT_TESTS_BIT | VK_PIPELINE_STAGE_LATE_FRAGMENT_TESTS_BIT,
                .dstStageMask = VK_PIPELINE_STAGE_EARLY_FRAGMENT_TESTS_BIT | VK_PIPELINE_STAGE_LATE_FRAGMENT_TESTS_BIT,
                .srcAccessMask = VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT,
                .dstAccessMask = VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_READ_BIT | VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT,
                .dependencyFlags = 0,
            },
        [1] =
            {
                // Image Layout Transition
                .srcSubpass = VK_SUBPASS_EXTERNAL,
                .dstSubpass = 0,
                .srcStageMask = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT,
                .dstStageMask = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT,
                .srcAccessMask = 0,
                .dstAccessMask = VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT | VK_ACCESS_COLOR_ATTACHMENT_READ_BIT,
                .dependencyFlags = 0,
            },
    };

    const VkRenderPassCreateInfo rp_info = {
        .sType = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO,
        .pNext = NULL,
        .flags = 0,
        .attachmentCount = 2,
        .pAttachments = attachments,
        .subpassCount = 1,
        .pSubpasses = &subpass,
        .dependencyCount = 2,
        .pDependencies = attachmentDependencies,
    };
    VkResult U_ASSERT_ONLY err;

    err = vkCreateRenderPass(demo->device, &rp_info, NULL, &demo->render_pass);
    assert(!err);
}

static VkPipelineCacheCreateInfo demo_get_pipeline_cache_info(struct demo *demo) {
    static const uint8_t embedded_data[] = {
#include "pipeline_cache.h"
    };
    static uint8_t file_data[MAX_PIPELINE_POOL_SIZE];
    size_t file_size = 0;
    bool pc_from_file = demo->pipeline_cache_path != NULL;
    if (pc_from_file) {
        FILE* file = fopen(demo->pipeline_cache_path, "rb");
        if (file == NULL) {
            ERR_EXIT("Failed to open pipeline cache.","I/O error");
        }
        file_size = fread(file_data, sizeof(char), MAX_PIPELINE_POOL_SIZE, file);
        if (feof(file) == 0) {
            char msg[64];
            sprintf(msg, "Pipeline cache too large. Max available size: %d", MAX_PIPELINE_POOL_SIZE);
            ERR_EXIT(msg,"");
        }
        fclose(file);
    }
    const VkPipelineCacheCreateInfo result = {
        .sType = VK_STRUCTURE_TYPE_PIPELINE_CACHE_CREATE_INFO,
        .flags = VK_PIPELINE_CACHE_CREATE_READ_ONLY_BIT | VK_PIPELINE_CACHE_CREATE_USE_APPLICATION_STORAGE_BIT,
        .initialDataSize = pc_from_file ? file_size : sizeof(embedded_data),
        .pInitialData = pc_from_file ? file_data : embedded_data
    };
    return result;
}

static VkPipelineOfflineCreateInfo demo_get_pipeline_offline_info() {
    const VkPipelineOfflineCreateInfo result = {
        .sType = VK_STRUCTURE_TYPE_PIPELINE_OFFLINE_CREATE_INFO,
        .pNext = NULL,
        .pipelineIdentifier = {245, 154, 136, 152, 244, 195, 139, 123, 0, 0, 0, 0, 0, 0, 0, 0},
        .matchControl = VK_PIPELINE_MATCH_CONTROL_APPLICATION_UUID_EXACT_MATCH,
        // We assume no pipeline entry is greater than 1MB
        .poolEntrySize = MAX_PIPELINE_POOL_SIZE};
    return result;
}

static void demo_prepare_pipeline(struct demo *demo) {
#define NUM_DYNAMIC_STATES 2 /*Viewport + Scissor*/

    VkGraphicsPipelineCreateInfo pipeline;
    VkPipelineCacheCreateInfo pipelineCache;
    VkPipelineVertexInputStateCreateInfo vi;
    VkPipelineInputAssemblyStateCreateInfo ia;
    VkPipelineRasterizationStateCreateInfo rs;
    VkPipelineColorBlendStateCreateInfo cb;
    VkPipelineDepthStencilStateCreateInfo ds;
    VkPipelineViewportStateCreateInfo vp;
    VkPipelineMultisampleStateCreateInfo ms;
    VkDynamicState dynamicStateEnables[NUM_DYNAMIC_STATES];
    VkPipelineDynamicStateCreateInfo dynamicState;
    VkResult U_ASSERT_ONLY err;

    memset(dynamicStateEnables, 0, sizeof dynamicStateEnables);
    memset(&dynamicState, 0, sizeof dynamicState);
    dynamicState.sType = VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO;
    dynamicState.pDynamicStates = dynamicStateEnables;

    memset(&pipeline, 0, sizeof(pipeline));
    pipeline.sType = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO;
    pipeline.layout = demo->pipeline_layout;

    VkPipelineOfflineCreateInfo oi = demo_get_pipeline_offline_info();
    pipeline.pNext = &oi;

    memset(&vi, 0, sizeof(vi));
    vi.sType = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO;

    memset(&ia, 0, sizeof(ia));
    ia.sType = VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO;
    ia.topology = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;

    memset(&rs, 0, sizeof(rs));
    rs.sType = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO;
    rs.polygonMode = VK_POLYGON_MODE_FILL;
    rs.cullMode = VK_CULL_MODE_BACK_BIT;
    rs.frontFace = VK_FRONT_FACE_COUNTER_CLOCKWISE;
    rs.depthClampEnable = VK_FALSE;
    rs.rasterizerDiscardEnable = VK_FALSE;
    rs.depthBiasEnable = VK_FALSE;
    rs.lineWidth = 1.0f;

    memset(&cb, 0, sizeof(cb));
    cb.sType = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO;
    VkPipelineColorBlendAttachmentState att_state[1];
    memset(att_state, 0, sizeof(att_state));
    att_state[0].colorWriteMask = 0xf;
    att_state[0].blendEnable = VK_FALSE;
    cb.attachmentCount = 1;
    cb.pAttachments = att_state;

    memset(&vp, 0, sizeof(vp));
    vp.sType = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO;
    vp.viewportCount = 1;
    dynamicStateEnables[dynamicState.dynamicStateCount++] = VK_DYNAMIC_STATE_VIEWPORT;
    vp.scissorCount = 1;
    dynamicStateEnables[dynamicState.dynamicStateCount++] = VK_DYNAMIC_STATE_SCISSOR;

    memset(&ds, 0, sizeof(ds));
    ds.sType = VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO;
    ds.depthTestEnable = VK_TRUE;
    ds.depthWriteEnable = VK_TRUE;
    ds.depthCompareOp = VK_COMPARE_OP_LESS_OR_EQUAL;
    ds.depthBoundsTestEnable = VK_FALSE;
    ds.back.failOp = VK_STENCIL_OP_KEEP;
    ds.back.passOp = VK_STENCIL_OP_KEEP;
    ds.back.compareOp = VK_COMPARE_OP_ALWAYS;
    ds.stencilTestEnable = VK_FALSE;
    ds.front = ds.back;

    memset(&ms, 0, sizeof(ms));
    ms.sType = VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO;
    ms.pSampleMask = NULL;
    ms.rasterizationSamples = VK_SAMPLE_COUNT_1_BIT;

    // Two stages: vs and fs
    VkPipelineShaderStageCreateInfo shaderStages[2];
    memset(&shaderStages, 0, 2 * sizeof(VkPipelineShaderStageCreateInfo));

    shaderStages[0].sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
    shaderStages[0].stage = VK_SHADER_STAGE_VERTEX_BIT;

    shaderStages[1].sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
    shaderStages[1].stage = VK_SHADER_STAGE_FRAGMENT_BIT;

    pipelineCache = demo_get_pipeline_cache_info(demo);

    err = vkCreatePipelineCache(demo->device, &pipelineCache, NULL, &demo->pipeline_cache);
    assert(!err);

    pipeline.pVertexInputState = &vi;
    pipeline.pInputAssemblyState = &ia;
    pipeline.pRasterizationState = &rs;
    pipeline.pColorBlendState = &cb;
    pipeline.pMultisampleState = &ms;
    pipeline.pViewportState = &vp;
    pipeline.pDepthStencilState = &ds;
    pipeline.stageCount = ARRAY_SIZE(shaderStages);
    pipeline.pStages = shaderStages;
    pipeline.renderPass = demo->render_pass;
    pipeline.pDynamicState = &dynamicState;

    err = vkCreateGraphicsPipelines(demo->device, demo->pipeline_cache, 1, &pipeline, NULL, &demo->pipeline);
    assert(!err);
}

static void demo_prepare_descriptor_pool(struct demo *demo) {
    const VkDescriptorPoolSize type_counts[2] = {
        [0] =
            {
                .type = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER,
                .descriptorCount = demo->swapchainImageCount,
            },
        [1] =
            {
                .type = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER,
                .descriptorCount = demo->swapchainImageCount * DEMO_TEXTURE_COUNT,
            },
    };
    const VkDescriptorPoolCreateInfo descriptor_pool = {
        .sType = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO,
        .pNext = NULL,
        .maxSets = demo->swapchainImageCount,
        .poolSizeCount = 2,
        .pPoolSizes = type_counts,
    };
    VkResult U_ASSERT_ONLY err;

    err = vkCreateDescriptorPool(demo->device, &descriptor_pool, NULL, &demo->desc_pool);
    assert(!err);
}

static void demo_prepare_descriptor_set(struct demo *demo) {
    VkDescriptorImageInfo tex_descs[DEMO_TEXTURE_COUNT];
    VkWriteDescriptorSet writes[2];
    VkResult U_ASSERT_ONLY err;

    VkDescriptorSetAllocateInfo alloc_info = {.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO,
                                              .pNext = NULL,
                                              .descriptorPool = demo->desc_pool,
                                              .descriptorSetCount = 1,
                                              .pSetLayouts = &demo->desc_layout};

    VkDescriptorBufferInfo buffer_info;
    buffer_info.offset = 0;
    buffer_info.range = sizeof(struct vktexcube_vs_uniform);

    memset(&tex_descs, 0, sizeof(tex_descs));
    for (unsigned int i = 0; i < DEMO_TEXTURE_COUNT; i++) {
        tex_descs[i].sampler = demo->textures[i].sampler;
        tex_descs[i].imageView = demo->textures[i].view;
        tex_descs[i].imageLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
    }

    memset(&writes, 0, sizeof(writes));

    writes[0].sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
    writes[0].descriptorCount = 1;
    writes[0].descriptorType = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
    writes[0].pBufferInfo = &buffer_info;

    writes[1].sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
    writes[1].dstBinding = 1;
    writes[1].descriptorCount = DEMO_TEXTURE_COUNT;
    writes[1].descriptorType = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
    writes[1].pImageInfo = tex_descs;

    for (unsigned int i = 0; i < demo->swapchainImageCount; i++) {
        err = vkAllocateDescriptorSets(demo->device, &alloc_info, &demo->swapchain_image_resources[i].descriptor_set);
        assert(!err);
        buffer_info.buffer = demo->swapchain_image_resources[i].uniform_buffer;
        writes[0].dstSet = demo->swapchain_image_resources[i].descriptor_set;
        writes[1].dstSet = demo->swapchain_image_resources[i].descriptor_set;
        vkUpdateDescriptorSets(demo->device, 2, writes, 0, NULL);
    }
}

static void demo_prepare_framebuffers(struct demo *demo) {
    VkImageView attachments[2];
    attachments[1] = demo->depth.view;

    const VkFramebufferCreateInfo fb_info = {
        .sType = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO,
        .pNext = NULL,
        .renderPass = demo->render_pass,
        .attachmentCount = 2,
        .pAttachments = attachments,
        .width = demo->width,
        .height = demo->height,
        .layers = 1,
    };
    VkResult U_ASSERT_ONLY err;
    uint32_t i;

    for (i = 0; i < demo->swapchainImageCount; i++) {
        attachments[0] = demo->swapchain_image_resources[i].view;
        err = vkCreateFramebuffer(demo->device, &fb_info, NULL, &demo->swapchain_image_resources[i].framebuffer);
        assert(!err);
        demo_name_object(demo, VK_OBJECT_TYPE_FRAMEBUFFER, (uint64_t)demo->swapchain_image_resources[i].framebuffer,
                         "Framebuffer(%u)", i);
    }
}

static void demo_prepare(struct demo *demo) {
    if (demo->wsi_platform != WSI_PLATFORM_FILE) {
        demo_prepare_buffers(demo);
    } else {  
        if (demo->width == -1) {
            demo->width = 512;
        }
        if (demo->height == -1) {
            demo->height = 512;
        }
        if (demo->frameCount == INT32_MAX) {
            demo->frameCount = 1;
        }

        demo_prepare_offscreen_texture(demo);
    }

    if (demo->is_minimized) {
        demo->prepared = false;
        return;
    }

    VkResult U_ASSERT_ONLY err;
    if (demo->cmd_pool == VK_NULL_HANDLE) {
        const VkCommandPoolMemoryReservationCreateInfo reservation_info = {
            .sType = VK_STRUCTURE_TYPE_COMMAND_POOL_MEMORY_RESERVATION_CREATE_INFO,
            .pNext = NULL,
            // We need one command buffer for preparation and one for each swapchain image
            .commandPoolMaxCommandBuffers = demo->swapchainImageCount + 1,
            .commandPoolReservedSize = (demo->swapchainImageCount + 1) * MAX_COMMAND_POOL_SIZE
        };
        const VkCommandPoolCreateInfo cmd_pool_info = {
            .sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO,
            .pNext = &reservation_info,
            .queueFamilyIndex = demo->graphics_queue_family_index,
            .flags = 0,
        };
        err = vkCreateCommandPool(demo->device, &cmd_pool_info, NULL, &demo->cmd_pool);
        assert(!err);
    }

    const VkCommandBufferAllocateInfo cmd = {
        .sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO,
        .pNext = NULL,
        .commandPool = demo->cmd_pool,
        .level = VK_COMMAND_BUFFER_LEVEL_PRIMARY,
        .commandBufferCount = 1,
    };
    err = vkAllocateCommandBuffers(demo->device, &cmd, &demo->cmd);
    assert(!err);
    demo_name_object(demo, VK_OBJECT_TYPE_COMMAND_BUFFER, (uint64_t)demo->cmd, "PrepareCB");
    VkCommandBufferBeginInfo cmd_buf_info = {
        .sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO,
        .pNext = NULL,
        .flags = 0,
        .pInheritanceInfo = NULL,
    };
    err = vkBeginCommandBuffer(demo->cmd, &cmd_buf_info);
    demo_push_cb_label(demo, demo->cmd, NULL, "Prepare");
    assert(!err);

    demo_prepare_depth(demo);
    demo_prepare_textures(demo);
    demo_prepare_cube_data_buffers(demo);

    demo_prepare_descriptor_layout(demo);
    demo_prepare_render_pass(demo);
    demo_prepare_pipeline(demo);

    for (uint32_t i = 0; i < demo->swapchainImageCount; i++) {
        err = vkAllocateCommandBuffers(demo->device, &cmd, &demo->swapchain_image_resources[i].cmd);
        assert(!err);
    }

    if (demo->separate_present_queue) {
        const VkCommandPoolMemoryReservationCreateInfo reservation_info = {
            .sType = VK_STRUCTURE_TYPE_COMMAND_POOL_MEMORY_RESERVATION_CREATE_INFO,
            .pNext = NULL,
            // We need one command buffer for for each swapchain image
            .commandPoolMaxCommandBuffers = demo->swapchainImageCount,
            .commandPoolReservedSize = demo->swapchainImageCount * MAX_COMMAND_POOL_SIZE
        };
        const VkCommandPoolCreateInfo present_cmd_pool_info = {
            .sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO,
            .pNext = &reservation_info,
            .queueFamilyIndex = demo->present_queue_family_index,
            .flags = 0,
        };
        err = vkCreateCommandPool(demo->device, &present_cmd_pool_info, NULL, &demo->present_cmd_pool);
        assert(!err);
        const VkCommandBufferAllocateInfo present_cmd_info = {
            .sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO,
            .pNext = NULL,
            .commandPool = demo->present_cmd_pool,
            .level = VK_COMMAND_BUFFER_LEVEL_PRIMARY,
            .commandBufferCount = 1,
        };
        for (uint32_t i = 0; i < demo->swapchainImageCount; i++) {
            err = vkAllocateCommandBuffers(demo->device, &present_cmd_info,
                                           &demo->swapchain_image_resources[i].graphics_to_present_cmd);
            assert(!err);
            demo_build_image_ownership_cmd(demo, i);
            demo_name_object(demo, VK_OBJECT_TYPE_COMMAND_BUFFER,
                             (uint64_t)demo->swapchain_image_resources[i].graphics_to_present_cmd, "GfxToPresent(%u)", i);
        }
    }

    demo_prepare_descriptor_pool(demo);
    demo_prepare_descriptor_set(demo);

    demo_prepare_framebuffers(demo);

    /*
     * Prepare functions above may generate pipeline commands
     * that need to be flushed before beginning the render loop.
     */
    demo_pop_cb_label(demo, demo->cmd);  // "Prepare"
    demo_flush_init_cmd(demo);
    if (demo->staging_texture.buffer) {
        demo_destroy_texture(demo, &demo->staging_texture);
    }

    for (uint32_t i = 0; i < demo->swapchainImageCount; i++) {
        demo->current_buffer = i;
        demo_draw_build_cmd(demo, demo->swapchain_image_resources[i].cmd);
    }

    demo->current_buffer = 0;
    demo->prepared = true;
    demo->first_swapchain_frame = true;
}

static void demo_cleanup(struct demo *demo) {
    uint32_t i;

    demo->prepared = false;
    vkDeviceWaitIdle(demo->device);

    // Wait for fences from present operations
    for (i = 0; i < FRAME_LAG; i++) {
        vkWaitForFences(demo->device, 1, &demo->fences[i], VK_TRUE, UINT64_MAX);
        vkDestroyFence(demo->device, demo->fences[i], NULL);
        vkDestroySemaphore(demo->device, demo->image_acquired_semaphores[i], NULL);
        vkDestroySemaphore(demo->device, demo->draw_complete_semaphores[i], NULL);
        if (demo->separate_present_queue) {
            vkDestroySemaphore(demo->device, demo->image_ownership_semaphores[i], NULL);
        }
    }

    // If the window is currently minimized, demo_resize has already done some cleanup for us.
    if (!demo->is_minimized) {
        for (i = 0; i < demo->swapchainImageCount; i++) {
            vkDestroyFramebuffer(demo->device, demo->swapchain_image_resources[i].framebuffer, NULL);
        }

        vkDestroyPipeline(demo->device, demo->pipeline, NULL);
        vkDestroyPipelineCache(demo->device, demo->pipeline_cache, NULL);
        vkDestroyRenderPass(demo->device, demo->render_pass, NULL);
        vkDestroyPipelineLayout(demo->device, demo->pipeline_layout, NULL);
        vkDestroyDescriptorSetLayout(demo->device, demo->desc_layout, NULL);

        for (i = 0; i < DEMO_TEXTURE_COUNT; i++) {
            vkDestroyImageView(demo->device, demo->textures[i].view, NULL);
            vkDestroyImage(demo->device, demo->textures[i].image, NULL);
            vkDestroySampler(demo->device, demo->textures[i].sampler, NULL);
        }

        vkDestroyImageView(demo->device, demo->depth.view, NULL);
        vkDestroyImage(demo->device, demo->depth.image, NULL);

        for (i = 0; i < demo->swapchainImageCount; i++) {
            vkDestroyImageView(demo->device, demo->swapchain_image_resources[i].view, NULL);
            vkFreeCommandBuffers(demo->device, demo->cmd_pool, 1, &demo->swapchain_image_resources[i].cmd);
            vkDestroyBuffer(demo->device, demo->swapchain_image_resources[i].uniform_buffer, NULL);
            vkUnmapMemory(demo->device, demo->swapchain_image_resources[i].uniform_memory);
        }

        if (demo->wsi_platform == WSI_PLATFORM_FILE) {
            vkDestroyImage(demo->device, demo->offscreen_texture.img.image, NULL);
            vkDestroyBuffer(demo->device, demo->offscreen_texture.staging.buffer, NULL);
        }
    }
    vkDeviceWaitIdle(demo->device);
    vkDestroyDevice(demo->device, NULL);

    if (demo->VK_NV_acquire_winrt_display_supported && demo->wsi_platform == WSI_PLATFORM_DISPLAY) {
        pfnReleaseDisplayEXT(demo->gpu, demo->display);
    }

    vkDestroySurfaceKHR(demo->inst, demo->surface, NULL);
    vkDestroyInstance(demo->inst, NULL);
}

static void demo_resize(struct demo *demo) {
    // Don't react to resize until after first initialization.
    if (!demo->prepared) {
        if (demo->is_minimized) {
            demo_prepare(demo);
        }
        return;
    } else {
        // NOTE: surface resize is not supported by Vulkan SC Cube so any attempt of it signals the destruction
        // of the display window, so we terminate gracefully
        demo->quit = true;
    }
}

#if defined(VK_USE_PLATFORM_DISPLAY_KHR)
static VkResult demo_create_display_surface(struct demo *demo) {
    VkResult U_ASSERT_ONLY err;
    uint32_t display_count;
    uint32_t mode_count;
    uint32_t plane_count;
    VkDisplayPropertiesKHR display_props;
    VkDisplayModeKHR mode;
    VkDisplayModePropertiesKHR mode_props;
    VkDisplayPlanePropertiesKHR plane_props[MAX_DISPLAY_PLANE_COUNT];
    VkBool32 found_plane = VK_FALSE;
    uint32_t plane_index;
    VkExtent2D image_extent;
    VkDisplaySurfaceCreateInfoKHR create_info;

    // Get the first display
    display_count = 1;
    err = vkGetPhysicalDeviceDisplayPropertiesKHR(demo->gpu, &display_count, &display_props);
    assert(!err || (err == VK_INCOMPLETE));

    demo->display = display_props.display;

#ifdef VK_USE_PLATFORM_WIN32_KHR
    // If we can, and need to, acquire the display if supported
    if (demo->VK_NV_acquire_winrt_display_supported && demo->wsi_platform != WSI_PLATFORM_DISPLAY) {
        err = pfnAcquireWinrtDisplayNV(demo->gpu, demo->display);
        if (err != VK_SUCCESS) {
            ERR_EXIT("Failed to get acqurie display", "vkAcquireWinrtDisplayNV Failure");
        }
    }
#endif

    // Get the first mode of the display
    err = vkGetDisplayModePropertiesKHR(demo->gpu, demo->display, &mode_count, NULL);
    assert(!err);

    if (mode_count == 0) {
        printf("Cannot find any mode for the display!\n");
        fflush(stdout);
        exit(1);
    }

    mode_count = 1;
    err = vkGetDisplayModePropertiesKHR(demo->gpu, demo->display, &mode_count, &mode_props);
    assert(!err || (err == VK_INCOMPLETE));
    if (demo->width != -1 && demo->height != -1) {
        VkDisplayModeCreateInfoKHR mode_create_info;
        mode_create_info.sType = VK_STRUCTURE_TYPE_DISPLAY_MODE_CREATE_INFO_KHR;
        mode_create_info.pNext = NULL;
        mode_create_info.flags = 0;
        mode_create_info.parameters.visibleRegion.width = (uint32_t)demo->width;
        mode_create_info.parameters.visibleRegion.height = (uint32_t)demo->height;
        mode_create_info.parameters.refreshRate = mode_props.parameters.refreshRate;
        err = vkCreateDisplayModeKHR(demo->gpu, demo->display, &mode_create_info, NULL, &mode);
        assert(!err);
    }
    else {
        mode = mode_props.displayMode;
        demo->width = mode_props.parameters.visibleRegion.width;
        demo->height = mode_props.parameters.visibleRegion.height;
    }

    // Get the list of planes
    err = vkGetPhysicalDeviceDisplayPlanePropertiesKHR(demo->gpu, &plane_count, NULL);
    assert(!err);

    if (plane_count == 0) {
        printf("Cannot find any plane!\n");
        fflush(stdout);
        exit(1);
    }

    err = vkGetPhysicalDeviceDisplayPlanePropertiesKHR(demo->gpu, &plane_count, plane_props);
    assert(!err);

    // Find a plane compatible with the display
    for (plane_index = 0; plane_index < plane_count; plane_index++) {
        uint32_t supported_count;
        VkDisplayKHR supported_displays[MAX_DISPLAY_COUNT];

        // Disqualify planes that are bound to a different display
        if ((plane_props[plane_index].currentDisplay != VK_NULL_HANDLE) && (plane_props[plane_index].currentDisplay != demo->display)) {
            continue;
        }

        err = vkGetDisplayPlaneSupportedDisplaysKHR(demo->gpu, plane_index, &supported_count, NULL);
        assert(!err);

        if (supported_count == 0) {
            continue;
        }

        err = vkGetDisplayPlaneSupportedDisplaysKHR(demo->gpu, plane_index, &supported_count, supported_displays);
        assert(!err);

        for (uint32_t i = 0; i < supported_count; i++) {
            if (supported_displays[i] == demo->display) {
                found_plane = VK_TRUE;
                break;
            }
        }

        if (found_plane) {
            break;
        }
    }

    if (!found_plane) {
        printf("Cannot find a plane compatible with the display!\n");
        fflush(stdout);
        exit(1);
    }

    VkDisplayPlaneCapabilitiesKHR planeCaps;
    vkGetDisplayPlaneCapabilitiesKHR(demo->gpu, mode_props.displayMode, plane_index, &planeCaps);
    // Find a supported alpha mode
    VkDisplayPlaneAlphaFlagBitsKHR alphaMode = VK_DISPLAY_PLANE_ALPHA_OPAQUE_BIT_KHR;
    VkDisplayPlaneAlphaFlagBitsKHR alphaModes[4] = {
        VK_DISPLAY_PLANE_ALPHA_OPAQUE_BIT_KHR,
        VK_DISPLAY_PLANE_ALPHA_GLOBAL_BIT_KHR,
        VK_DISPLAY_PLANE_ALPHA_PER_PIXEL_BIT_KHR,
        VK_DISPLAY_PLANE_ALPHA_PER_PIXEL_PREMULTIPLIED_BIT_KHR,
    };
    for (uint32_t i = 0; i < sizeof(alphaModes); i++) {
        if (planeCaps.supportedAlpha & alphaModes[i]) {
            alphaMode = alphaModes[i];
            break;
        }
    }
    image_extent.width = (uint32_t)demo->width;
    image_extent.height = (uint32_t)demo->height;

    create_info.sType = VK_STRUCTURE_TYPE_DISPLAY_SURFACE_CREATE_INFO_KHR;
    create_info.pNext = NULL;
    create_info.flags = 0;
    create_info.displayMode = mode;
    create_info.planeIndex = plane_index;
    create_info.planeStackIndex = plane_props[plane_index].currentStackIndex;
    create_info.transform = VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR;
    create_info.alphaMode = alphaMode;
    create_info.globalAlpha = 1.0f;
    create_info.imageExtent = image_extent;

    return vkCreateDisplayPlaneSurfaceKHR(demo->inst, &create_info, NULL, &demo->surface);
}

static void demo_run_display(struct demo *demo) {
    while (!demo->quit) {
        demo_draw(demo);
        demo->curFrame++;

        if (demo->frameCount != INT32_MAX && demo->curFrame == demo->frameCount) {
            demo->quit = true;
        }
    }
}
#endif

void save_rgba_to_ppm(const char *filename, int width, int height, const unsigned char *rgba_data) {
    FILE *f = fopen(filename, "wb");
    if (!f) {
        perror("fopen");
        ERR_EXIT("Failed to open ppm output file", "Save RGBA to PPM failure");
    }

    char header[64];
    int header_len = snprintf(header, sizeof(header), "P6\n%d %d\n255\n", width, height);
    fwrite(header, 1, header_len, f);

    unsigned char *rgb_data = (unsigned char *)malloc(width * height * 3);
    if (!rgb_data) {
        perror("malloc");
        fclose(f);
        ERR_EXIT("Failed to malloc temp buffer for rgba/rgb conversion", "Save RGBA to PPM failure");
    }

    for (int i = 0; i < width * height; ++i) {
        rgb_data[i * 3 + 0] = rgba_data[i * 4 + 0];  // R
        rgb_data[i * 3 + 1] = rgba_data[i * 4 + 1];  // G
        rgb_data[i * 3 + 2] = rgba_data[i * 4 + 2];  // B
    }

    fwrite(rgb_data, 1, width * height * 3, f);

    free(rgb_data);
    fclose(f);
}

void save_frame(struct demo *demo, uint32_t frame_id) {
    VkResult U_ASSERT_ONLY err;

    void *data;
    err = vkMapMemory(demo->device, demo->offscreen_texture.staging.mem, 0,
                      demo->offscreen_texture.staging.mem_alloc.allocationSize, 0, &data);
    assert(!err);

#define MAX_FILENAME_LENGTH 100
    char filename[MAX_FILENAME_LENGTH];

    snprintf(filename, MAX_FILENAME_LENGTH, "frame_%05d.ppm", frame_id);
    save_rgba_to_ppm(filename, demo->width, demo->height, data);

    vkUnmapMemory(demo->device, demo->offscreen_texture.staging.mem);
}

static void demo_run_image_dump(struct demo *demo) {
    for (int32_t i = 0; i < demo->frameCount; i++) {
        demo_draw(demo);
        save_frame(demo, i);
    }
}

/*
 * Return 1 (true) if all layer names specified in check_names
 * can be found in given layer properties.
 */
static VkBool32 demo_check_layers(uint32_t check_count, char **check_names, uint32_t layer_count, VkLayerProperties *layers) {
    for (uint32_t i = 0; i < check_count; i++) {
        VkBool32 found = 0;
        for (uint32_t j = 0; j < layer_count; j++) {
            if (!strcmp(check_names[i], layers[j].layerName)) {
                found = 1;
                break;
            }
        }
        if (!found) {
            fprintf(stderr, "Cannot find layer: %s\n", check_names[i]);
            return 0;
        }
    }
    return 1;
}
#if defined(VK_USE_PLATFORM_DISPLAY_KHR)
int find_display_gpu(int gpu_number, uint32_t gpu_count, VkPhysicalDevice *physical_devices) {
    uint32_t display_count = 0;
    VkResult U_ASSERT_ONLY result;
    int gpu_return = gpu_number;
    if (gpu_number >= 0) {
        result = vkGetPhysicalDeviceDisplayPropertiesKHR(physical_devices[gpu_number], &display_count, NULL);
        assert(!result);
    } else {
        for (uint32_t i = 0; i < gpu_count; i++) {
            result = vkGetPhysicalDeviceDisplayPropertiesKHR(physical_devices[i], &display_count, NULL);
            assert(!result);
            if (display_count) {
                gpu_return = i;
                break;
            }
        }
    }
    if (display_count > 0)
        return gpu_return;
    else
        return -1;
}
#endif

// Check that WSI platforms are available - only necessary when multiple WSI platforms exist, like on linux
// If the wsi_platform is AUTO, this function also sets wsi_platform to the first available WSI platform
// Otherwise, it errors out if the specified wsi_platform isn't available
static void demo_check_and_set_wsi_platform(struct demo *demo) {
#if defined(VK_USE_PLATFORM_DISPLAY_KHR)
    if (demo->wsi_platform == WSI_PLATFORM_DISPLAY || demo->wsi_platform == WSI_PLATFORM_AUTO) {
        bool display_extension_available = false;
        for (uint32_t i = 0; i < demo->enabled_extension_count; i++) {
            if (strcmp(demo->extension_names[i], VK_KHR_DISPLAY_EXTENSION_NAME) == 0) {
                display_extension_available = true;
                break;
            }
        }
        if (display_extension_available) {
            // Because DISPLAY doesn't require additional libraries, we can assume that it works if we got here
            demo->wsi_platform = WSI_PLATFORM_DISPLAY;
            return;
        }
    }
#endif
}

static void demo_init_vk(struct demo *demo) {
    VkResult err;
    uint32_t instance_extension_count = 0;
    uint32_t instance_layer_count = 0;
    char *instance_validation_layers[] = {"VK_LAYER_KHRONOS_validation"};
    demo->enabled_extension_count = 0;
    demo->enabled_layer_count = 0;
    demo->is_minimized = false;
    demo->cmd_pool = VK_NULL_HANDLE;

    // Look for validation layers
    VkBool32 validation_found = 0;
    if (demo->validate) {
        err = vkEnumerateInstanceLayerProperties(&instance_layer_count, NULL);
        assert(!err);

        if (instance_layer_count > 0) {
            VkLayerProperties instance_layers[MAX_INSTANCE_LAYER_COUNT];
            err = vkEnumerateInstanceLayerProperties(&instance_layer_count, instance_layers);
            assert(!err);

            validation_found = demo_check_layers(ARRAY_SIZE(instance_validation_layers), instance_validation_layers,
                                                 instance_layer_count, instance_layers);
            if (validation_found) {
                demo->enabled_layer_count = ARRAY_SIZE(instance_validation_layers);
                demo->enabled_layers[0] = "VK_LAYER_KHRONOS_validation";
            }
        }

        if (!validation_found) {
            ERR_EXIT(
                "vkEnumerateInstanceLayerProperties failed to find required validation layer.\n\n"
                "Please look at the Getting Started guide for additional information.\n",
                "vkCreateInstance Failure");
        }
    }

    /* Look for instance extensions */
    VkBool32 surfaceExtFound = false;
    VkBool32 platformSurfaceExtFound = false;
    VkBool32 releaseDispExtFound = false;
    memset(demo->extension_names, 0, sizeof(demo->extension_names));

    err = vkEnumerateInstanceExtensionProperties(NULL, &instance_extension_count, NULL);
    assert(!err);

    if (instance_extension_count > 0) {
        VkExtensionProperties instance_extensions[MAX_INSTANCE_EXTENSION_COUNT];
        err = vkEnumerateInstanceExtensionProperties(NULL, &instance_extension_count, instance_extensions);
        assert(!err);
        for (uint32_t i = 0; i < instance_extension_count; i++) {
            if (!strcmp(VK_KHR_SURFACE_EXTENSION_NAME, instance_extensions[i].extensionName)) {
                surfaceExtFound = true;
                demo->extension_names[demo->enabled_extension_count++] = VK_KHR_SURFACE_EXTENSION_NAME;
            }
#if defined(VK_USE_PLATFORM_DISPLAY_KHR)
            if (demo->wsi_platform == WSI_PLATFORM_AUTO || demo->wsi_platform == WSI_PLATFORM_DISPLAY) {
                if (!strcmp(VK_KHR_DISPLAY_EXTENSION_NAME, instance_extensions[i].extensionName)) {
                    platformSurfaceExtFound = true;
                    demo->extension_names[demo->enabled_extension_count++] = VK_KHR_DISPLAY_EXTENSION_NAME;
                }
                if (!strcmp(VK_EXT_DIRECT_MODE_DISPLAY_EXTENSION_NAME, instance_extensions[i].extensionName)) {
                    releaseDispExtFound = true;
                    demo->extension_names[demo->enabled_extension_count++] = VK_EXT_DIRECT_MODE_DISPLAY_EXTENSION_NAME;
                }
            }
#endif
            if (!strcmp(VK_EXT_DEBUG_UTILS_EXTENSION_NAME, instance_extensions[i].extensionName)) {
                if (demo->validate) {
                    demo->extension_names[demo->enabled_extension_count++] = VK_EXT_DEBUG_UTILS_EXTENSION_NAME;
                }
            }
            assert(demo->enabled_extension_count < 64);
        }
    }

    if (demo->wsi_platform != WSI_PLATFORM_FILE) {
        if (!surfaceExtFound) {
            ERR_EXIT("vkEnumerateInstanceExtensionProperties failed to find the " VK_KHR_SURFACE_EXTENSION_NAME
                     " extension.\n\n"
                     "Do you have a compatible Vulkan installable client driver (ICD) installed?\n"
                     "Please look at the Getting Started guide for additional information.\n",
                     "vkCreateInstance Failure");
        }
        if (!platformSurfaceExtFound) {
#if defined(VK_USE_PLATFORM_DISPLAY_KHR)
            if (demo->wsi_platform == WSI_PLATFORM_DISPLAY) {
                ERR_EXIT("vkEnumerateInstanceExtensionProperties failed to find the " VK_KHR_DISPLAY_EXTENSION_NAME
                         " extension.\n\n"
                         "Do you have a compatible Vulkan installable client driver (ICD) installed?\n"
                         "Please look at the Getting Started guide for additional information.\n",
                         "vkCreateInstance Failure");
            }
#endif
            ERR_EXIT(
                "vkEnumerateInstanceExtensionProperties failed to find any supported WSI surface extension.\n\n"
                "Do you have a compatible Vulkan installable client driver (ICD) installed?\n"
                "Please look at the Getting Started guide for additional information.\n",
                "vkCreateInstance Failure");
        }
    }

    bool auto_wsi_platform = demo->wsi_platform == WSI_PLATFORM_AUTO;

    demo_check_and_set_wsi_platform(demo);

    // Print a message to indicate the automatically set WSI platform
    if (auto_wsi_platform && demo->wsi_platform != WSI_PLATFORM_AUTO) {
        fprintf(stderr, "Selected WSI platform: %s\n", wsi_to_string(demo->wsi_platform));
    }

    const VkApplicationInfo app = {
        .sType = VK_STRUCTURE_TYPE_APPLICATION_INFO,
        .pNext = NULL,
        .pApplicationName = APP_SHORT_NAME,
        .applicationVersion = 0,
        .pEngineName = APP_SHORT_NAME,
        .engineVersion = 0,
        .apiVersion = VKSC_API_VERSION_1_0,
    };
    VkInstanceCreateInfo inst_info = {
        .sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
        .pNext = NULL,
        .flags = 0,
        .pApplicationInfo = &app,
        .enabledLayerCount = demo->enabled_layer_count,
        .ppEnabledLayerNames = (const char *const *)instance_validation_layers,
        .enabledExtensionCount = demo->enabled_extension_count,
        .ppEnabledExtensionNames = (const char *const *)demo->extension_names,
    };

    /*
     * This is info for a temp callback to use during CreateInstance.
     * After the instance is created, we use the instance-based
     * function to register the final callback.
     */
    VkDebugUtilsMessengerCreateInfoEXT dbg_messenger_create_info;
    if (demo->validate) {
        // VK_EXT_debug_utils style
        dbg_messenger_create_info.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
        dbg_messenger_create_info.pNext = NULL;
        dbg_messenger_create_info.flags = 0;
        dbg_messenger_create_info.messageSeverity =
            VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
        dbg_messenger_create_info.messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT |
                                                VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT |
                                                VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
        dbg_messenger_create_info.pfnUserCallback = debug_messenger_callback;
        dbg_messenger_create_info.pUserData = demo;
        inst_info.pNext = &dbg_messenger_create_info;
    }

    err = vkCreateInstance(&inst_info, NULL, &demo->inst);
    if (err == VK_ERROR_INCOMPATIBLE_DRIVER) {
        ERR_EXIT(
            "Cannot find a compatible Vulkan installable client driver (ICD).\n\n"
            "Please look at the Getting Started guide for additional information.\n",
            "vkCreateInstance Failure");
    } else if (err == VK_ERROR_EXTENSION_NOT_PRESENT) {
        ERR_EXIT(
            "Cannot find a specified extension library.\n"
            "Make sure your layers path is set appropriately.\n",
            "vkCreateInstance Failure");
    } else if (err) {
        ERR_EXIT(
            "vkCreateInstance failed.\n\n"
            "Do you have a compatible Vulkan installable client driver (ICD) installed?\n"
            "Please look at the Getting Started guide for additional information.\n",
            "vkCreateInstance Failure");
    }

    initialize_entry_points(demo->inst);

    /* Make initial call to query gpu_count, then second call for gpu info */
    uint32_t gpu_count = 0;
    err = vkEnumeratePhysicalDevices(demo->inst, &gpu_count, NULL);
    assert(!err);

    if (gpu_count <= 0) {
        ERR_EXIT(
            "vkEnumeratePhysicalDevices reported zero accessible devices.\n",
            "vkEnumeratePhysicalDevices Failure");
    }

    VkPhysicalDevice physical_devices[MAX_PHYSICAL_DEVICE_COUNT];
    err = vkEnumeratePhysicalDevices(demo->inst, &gpu_count, physical_devices);
    assert(!err);
    if (demo->invalid_gpu_selection || (demo->gpu_number >= 0 && !((uint32_t)demo->gpu_number < gpu_count))) {
        fprintf(stderr, "GPU %d specified is not present, GPU count = %u\n", demo->gpu_number, gpu_count);
        ERR_EXIT("Specified GPU number is not present", "User Error");
    }

    if (demo->wsi_platform == WSI_PLATFORM_DISPLAY) {
#if defined(VK_USE_PLATFORM_DISPLAY_KHR)
        demo->gpu_number = find_display_gpu(demo->gpu_number, gpu_count, physical_devices);
        if (demo->gpu_number < 0) {
            printf("Cannot find any display!\n");
            fflush(stdout);
            exit(1);
        }
#else
        printf("WSI selection was set to DISPLAY but vksccube was not compiled with support for the DISPLAY platform, exiting \n");
        fflush(stdout);
        exit(1);
#endif
    } else {
        /* Try to auto select most suitable device */
        if (demo->gpu_number == -1) {
            uint32_t count_device_type[VK_PHYSICAL_DEVICE_TYPE_CPU + 1];
            memset(count_device_type, 0, sizeof(count_device_type));

            VkPhysicalDeviceProperties physicalDeviceProperties;
            for (uint32_t i = 0; i < gpu_count; i++) {
                vkGetPhysicalDeviceProperties(physical_devices[i], &physicalDeviceProperties);
                assert(physicalDeviceProperties.deviceType <= VK_PHYSICAL_DEVICE_TYPE_CPU);
                count_device_type[physicalDeviceProperties.deviceType]++;
            }

            VkPhysicalDeviceType search_for_device_type = VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU;
            if (count_device_type[VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU]) {
                search_for_device_type = VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU;
            } else if (count_device_type[VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU]) {
                search_for_device_type = VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU;
            } else if (count_device_type[VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU]) {
                search_for_device_type = VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU;
            } else if (count_device_type[VK_PHYSICAL_DEVICE_TYPE_CPU]) {
                search_for_device_type = VK_PHYSICAL_DEVICE_TYPE_CPU;
            } else if (count_device_type[VK_PHYSICAL_DEVICE_TYPE_OTHER]) {
                search_for_device_type = VK_PHYSICAL_DEVICE_TYPE_OTHER;
            }

            for (uint32_t i = 0; i < gpu_count; i++) {
                vkGetPhysicalDeviceProperties(physical_devices[i], &physicalDeviceProperties);
                if (physicalDeviceProperties.deviceType == search_for_device_type) {
                    demo->gpu_number = i;
                    break;
                }
            }
        }
    }

    assert(demo->gpu_number >= 0);
    demo->gpu = physical_devices[demo->gpu_number];
    {
        VkPhysicalDeviceProperties physicalDeviceProperties;
        vkGetPhysicalDeviceProperties(demo->gpu, &physicalDeviceProperties);
        fprintf(stderr, "Selected GPU %d: %s, type: %s\n", demo->gpu_number, physicalDeviceProperties.deviceName,
                to_string(physicalDeviceProperties.deviceType));
    }

    // Get Memory information and properties as soon as we picked a physical device
    vkGetPhysicalDeviceMemoryProperties(demo->gpu, &demo->memory_properties);

    /* Look for device extensions */
    uint32_t device_extension_count = 0;
    VkBool32 swapchainExtFound = 0;
    VkBool32 acquireDispExtFound = 0;
    demo->enabled_extension_count = 0;
    memset(demo->extension_names, 0, sizeof(demo->extension_names));

    err = vkEnumerateDeviceExtensionProperties(demo->gpu, NULL, &device_extension_count, NULL);
    assert(!err);

    if (device_extension_count > 0) {
        VkExtensionProperties device_extensions[MAX_PHYSICAL_DEVICE_EXTENSION_COUNT];
        err = vkEnumerateDeviceExtensionProperties(demo->gpu, NULL, &device_extension_count, device_extensions);
        assert(!err);

        for (uint32_t i = 0; i < device_extension_count; i++) {
            if (!strcmp(VK_KHR_SWAPCHAIN_EXTENSION_NAME, device_extensions[i].extensionName)) {
                swapchainExtFound = 1;
                demo->extension_names[demo->enabled_extension_count++] = VK_KHR_SWAPCHAIN_EXTENSION_NAME;
            }
#ifdef VK_USE_PLATFORM_WIN32_KHR
            if (!strcmp(VK_NV_ACQUIRE_WINRT_DISPLAY_EXTENSION_NAME, device_extensions[i].extensionName) &&
                (demo->wsi_platform == WSI_PLATFORM_AUTO || demo->wsi_platform == WSI_PLATFORM_DISPLAY)) {
                acquireDispExtFound = 1;
                demo->extension_names[demo->enabled_extension_count++] = VK_NV_ACQUIRE_WINRT_DISPLAY_EXTENSION_NAME;
            }
#endif
        }

        if (demo->VK_KHR_incremental_present_enabled) {
            // Even though the user "enabled" the extension via the command
            // line, we must make sure that it's enumerated for use with the
            // device.  Therefore, disable it here, and re-enable it again if
            // enumerated.
            demo->VK_KHR_incremental_present_enabled = false;
            for (uint32_t i = 0; i < device_extension_count; i++) {
                if (!strcmp(VK_KHR_INCREMENTAL_PRESENT_EXTENSION_NAME, device_extensions[i].extensionName)) {
                    demo->extension_names[demo->enabled_extension_count++] = VK_KHR_INCREMENTAL_PRESENT_EXTENSION_NAME;
                    demo->VK_KHR_incremental_present_enabled = true;
                    DbgMsg("VK_KHR_incremental_present extension enabled\n");
                }
                assert(demo->enabled_extension_count < 64);
            }
            if (!demo->VK_KHR_incremental_present_enabled) {
                DbgMsg("VK_KHR_incremental_present extension NOT AVAILABLE\n");
            }
        }
    }

    if (!swapchainExtFound) {
        ERR_EXIT("vkEnumerateDeviceExtensionProperties failed to find the " VK_KHR_SWAPCHAIN_EXTENSION_NAME
                 " extension.\n\nDo you have a compatible Vulkan installable client driver (ICD) installed?\n"
                 "Please look at the Getting Started guide for additional information.\n",
                 "vkCreateInstance Failure");
    }

    if (acquireDispExtFound && releaseDispExtFound) {
        demo->VK_NV_acquire_winrt_display_supported = true;
    }

    if (demo->validate) {
        err = pfnCreateDebugUtilsMessengerEXT(demo->inst, &dbg_messenger_create_info, NULL, &demo->dbg_messenger);
        switch (err) {
            case VK_SUCCESS:
                break;
            case VK_ERROR_OUT_OF_HOST_MEMORY:
                ERR_EXIT("CreateDebugUtilsMessengerEXT: out of host memory\n", "CreateDebugUtilsMessengerEXT Failure");
                break;
            default:
                ERR_EXIT("CreateDebugUtilsMessengerEXT: unknown failure\n", "CreateDebugUtilsMessengerEXT Failure");
                break;
        }
    }
    vkGetPhysicalDeviceProperties(demo->gpu, &demo->gpu_props);

    /* Call with NULL data to get count */
    vkGetPhysicalDeviceQueueFamilyProperties(demo->gpu, &demo->queue_family_count, NULL);
    assert(demo->queue_family_count >= 1);

    vkGetPhysicalDeviceQueueFamilyProperties(demo->gpu, &demo->queue_family_count, demo->queue_props);

    // Query fine-grained feature support for this device.
    //  If app has specific feature requirements it should check supported
    //  features based on this query
    VkPhysicalDeviceFeatures physDevFeatures;
    vkGetPhysicalDeviceFeatures(demo->gpu, &physDevFeatures);
}

static void demo_create_device(struct demo *demo) {
    VkResult U_ASSERT_ONLY err;
    float queue_priorities[1] = {0.0};
    VkDeviceQueueCreateInfo queues[2];
    queues[0].sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
    queues[0].pNext = NULL;
    queues[0].queueFamilyIndex = demo->graphics_queue_family_index;
    queues[0].queueCount = 1;
    queues[0].pQueuePriorities = queue_priorities;
    queues[0].flags = 0;

    VkPipelineCacheCreateInfo pipelineCache = demo_get_pipeline_cache_info(demo);
    const VkPipelinePoolSize pipelinePoolSize = {
        .sType = VK_STRUCTURE_TYPE_PIPELINE_POOL_SIZE,
        .pNext = NULL,
        .poolEntryCount = 1,
        .poolEntrySize = MAX_PIPELINE_POOL_SIZE
    };
    VkDeviceObjectReservationCreateInfo objectReservation = {
        .sType = VK_STRUCTURE_TYPE_DEVICE_OBJECT_RESERVATION_CREATE_INFO,
        .pNext = NULL,
        .pipelineCacheCreateInfoCount = 1,
        .pPipelineCacheCreateInfos = &pipelineCache,
        .pipelinePoolSizeCount = 1,
        .pPipelinePoolSizes = &pipelinePoolSize,
        .semaphoreRequestCount = FRAME_LAG * 3,
        .commandBufferRequestCount = MAX_SWAPCHAIN_IMAGE_COUNT * 2 + 1,
        .fenceRequestCount = FRAME_LAG + 1,
        .deviceMemoryRequestCount = MAX_SWAPCHAIN_IMAGE_COUNT + 3,
        .bufferRequestCount = MAX_SWAPCHAIN_IMAGE_COUNT + 1,
        .imageRequestCount = 3,
        .eventRequestCount = 0,
        .queryPoolRequestCount = 0,
        .bufferViewRequestCount = 0,
        .imageViewRequestCount = DEMO_TEXTURE_COUNT + MAX_SWAPCHAIN_IMAGE_COUNT + 1,
        .layeredImageViewRequestCount = 0,
        .pipelineCacheRequestCount = 1,
        .pipelineLayoutRequestCount = 1,
        .renderPassRequestCount = 1,
        .graphicsPipelineRequestCount = 1,
        .computePipelineRequestCount = 0,
        .descriptorSetLayoutRequestCount = 1,
        .samplerRequestCount = DEMO_TEXTURE_COUNT,
        .descriptorPoolRequestCount = 1,
        .descriptorSetRequestCount = MAX_SWAPCHAIN_IMAGE_COUNT,
        .framebufferRequestCount = MAX_SWAPCHAIN_IMAGE_COUNT,
        .commandPoolRequestCount = 2,
        .samplerYcbcrConversionRequestCount = 0,
        .surfaceRequestCount = 0,
        .swapchainRequestCount = 1,
        .displayModeRequestCount = 0,
        .subpassDescriptionRequestCount = 1,
        .attachmentDescriptionRequestCount = 2,
        .descriptorSetLayoutBindingRequestCount = 2,
        .descriptorSetLayoutBindingLimit = 2,
        .maxImageViewMipLevels = 1,
        .maxImageViewArrayLayers = 1,
        .maxLayeredImageViewMipLevels = 0,
        .maxOcclusionQueriesPerPool = 0,
        .maxPipelineStatisticsQueriesPerPool = 0,
        .maxTimestampQueriesPerPool = 0,
        .maxImmutableSamplersPerDescriptorSetLayout = 0
    };
    VkPhysicalDeviceVulkanSC10Features sc10Features = {
        .sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_SC_1_0_FEATURES,
        .pNext = &objectReservation,
        .shaderAtomicInstructions = VK_FALSE
    };
    VkDeviceCreateInfo device = {
        .sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO,
        .pNext = &sc10Features,
        .queueCreateInfoCount = 1,
        .pQueueCreateInfos = queues,
        .enabledLayerCount = 0,
        .ppEnabledLayerNames = NULL,
        .enabledExtensionCount = demo->enabled_extension_count,
        .ppEnabledExtensionNames = (const char *const *)demo->extension_names,
        .pEnabledFeatures = NULL,  // If specific features are required, pass them in here
    };
    if (demo->separate_present_queue) {
        queues[1].sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
        queues[1].pNext = NULL;
        queues[1].queueFamilyIndex = demo->present_queue_family_index;
        queues[1].queueCount = 1;
        queues[1].pQueuePriorities = queue_priorities;
        queues[1].flags = 0;
        device.queueCreateInfoCount = 2;
    }
    err = vkCreateDevice(demo->gpu, &device, NULL, &demo->device);
    if (err == VK_ERROR_INVALID_PIPELINE_CACHE_DATA) {
        if (demo->pipeline_cache_path == NULL) {
            ERR_EXIT(
                "vkCreateDevice failed with VK_ERROR_INVALID_PIPELINE_CACHE_DATA.\n\n"
                "The pipeline cache data built into vksccube is likely incompatible with the target device.\n"
                "Please specify the pipeline cache binary compatible with the target device using the --pipeline-cache option.\n",
                "vkCreateDevice Failure");
        } else {
            ERR_EXIT(
                "vkCreateDevice failed with VK_ERROR_INVALID_PIPELINE_CACHE_DATA.\n\n"
                "The pipeline cache data provided using the --pipeline-cache option is likely incompatible with the target device.\n",
                "vkCreateDevice Failure");
        }
    } else if (err) {
        ERR_EXIT("vkCreateDevice failed.\n", "vkCreateDevice Failure");
    }
}

static void demo_create_surface(struct demo *demo) {
    VkResult U_ASSERT_ONLY err = VK_SUCCESS;

// Create a WSI surface for the window:
#if defined(VK_USE_PLATFORM_DISPLAY_KHR)
    if (demo->wsi_platform == WSI_PLATFORM_DISPLAY) {
        err = demo_create_display_surface(demo);
    }
#endif
    if (err != VK_SUCCESS) {
        ERR_EXIT("Could not create display surface", "Surface Initialization Failure");
    }
}

static VkSurfaceFormatKHR pick_surface_format(const VkSurfaceFormatKHR *surfaceFormats, uint32_t count) {
    // Prefer non-SRGB formats...
    for (uint32_t i = 0; i < count; i++) {
        const VkFormat format = surfaceFormats[i].format;

        if (format == VK_FORMAT_R8G8B8A8_UNORM || format == VK_FORMAT_B8G8R8A8_UNORM ||
            format == VK_FORMAT_A2B10G10R10_UNORM_PACK32 || format == VK_FORMAT_A2R10G10B10_UNORM_PACK32 ||
            format == VK_FORMAT_A1R5G5B5_UNORM_PACK16 || format == VK_FORMAT_R5G6B5_UNORM_PACK16 ||
            format == VK_FORMAT_R16G16B16A16_SFLOAT) {
            return surfaceFormats[i];
        }
    }

    printf("Can't find our preferred formats... Falling back to first exposed format. Rendering may be incorrect.\n");

    assert(count >= 1);
    return surfaceFormats[0];
}

static void demo_init_vk_swapchain(struct demo *demo) {
    VkResult U_ASSERT_ONLY err;

    demo_create_surface(demo);

    if (demo->wsi_platform == WSI_PLATFORM_FILE) {
        // Search for the first graphics queue
        uint32_t graphicsQueueFamilyIndex = UINT32_MAX;
        for (uint32_t i = 0; i < demo->queue_family_count; i++) {
            if ((demo->queue_props[i].queueFlags & VK_QUEUE_GRAPHICS_BIT) != 0) {
                graphicsQueueFamilyIndex = i;
                break;
            }
        }
        if (graphicsQueueFamilyIndex == UINT32_MAX) {
            ERR_EXIT("Failed to find graphics queue", "Vulkan init failure");
        }
        demo->graphics_queue_family_index = graphicsQueueFamilyIndex;
        demo->separate_present_queue = false;
    } else {
        // Iterate over each queue to learn whether it supports presenting:
        VkBool32 supportsPresent[MAX_QUEUE_FAMILY_COUNT];
        for (uint32_t i = 0; i < demo->queue_family_count; i++) {
            vkGetPhysicalDeviceSurfaceSupportKHR(demo->gpu, i, demo->surface, &supportsPresent[i]);
        }

        // Search for a graphics and a present queue in the array of queue
        // families, try to find one that supports both
        uint32_t graphicsQueueFamilyIndex = UINT32_MAX;
        uint32_t presentQueueFamilyIndex = UINT32_MAX;
        for (uint32_t i = 0; i < demo->queue_family_count; i++) {
            if ((demo->queue_props[i].queueFlags & VK_QUEUE_GRAPHICS_BIT) != 0) {
                if (graphicsQueueFamilyIndex == UINT32_MAX) {
                    graphicsQueueFamilyIndex = i;
                }

                if (supportsPresent[i] == VK_TRUE) {
                    graphicsQueueFamilyIndex = i;
                    presentQueueFamilyIndex = i;
                    break;
                }
            }
        }

        if (presentQueueFamilyIndex == UINT32_MAX) {
            // If didn't find a queue that supports both graphics and present, then
            // find a separate present queue.
            for (uint32_t i = 0; i < demo->queue_family_count; ++i) {
                if (supportsPresent[i] == VK_TRUE) {
                    presentQueueFamilyIndex = i;
                    break;
                }
            }
        }

        // Generate error if could not find both a graphics and a present queue
        if (graphicsQueueFamilyIndex == UINT32_MAX || presentQueueFamilyIndex == UINT32_MAX) {
            ERR_EXIT("Could not find both graphics and present queues\n", "Swapchain Initialization Failure");
        }

        demo->graphics_queue_family_index = graphicsQueueFamilyIndex;
        demo->present_queue_family_index = presentQueueFamilyIndex;
        demo->separate_present_queue = (demo->graphics_queue_family_index != demo->present_queue_family_index);
    }

    demo_create_device(demo);

    vkGetDeviceQueue(demo->device, demo->graphics_queue_family_index, 0, &demo->graphics_queue);

    if (!demo->separate_present_queue) {
        demo->present_queue = demo->graphics_queue;
    } else {
        vkGetDeviceQueue(demo->device, demo->present_queue_family_index, 0, &demo->present_queue);
    }

    if (demo->wsi_platform != WSI_PLATFORM_FILE) {
        // Get the list of VkFormat's that are supported:
        uint32_t formatCount;
        err = pfnGetPhysicalDeviceSurfaceFormatsKHR(demo->gpu, demo->surface, &formatCount, NULL);
        assert(!err);
        VkSurfaceFormatKHR surfFormats[MAX_SURFACE_FORMAT_COUNT];
        err = pfnGetPhysicalDeviceSurfaceFormatsKHR(demo->gpu, demo->surface, &formatCount, surfFormats);
        assert(!err);
        VkSurfaceFormatKHR surfaceFormat = pick_surface_format(surfFormats, formatCount);
        demo->format = surfaceFormat.format;
        demo->color_space = surfaceFormat.colorSpace;
    }

    demo->quit = false;
    demo->curFrame = 0;

    // Create semaphores to synchronize acquiring presentable buffers before
    // rendering and waiting for drawing to be complete before presenting
    VkSemaphoreCreateInfo semaphoreCreateInfo = {
        .sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO,
        .pNext = NULL,
        .flags = 0,
    };

    // Create fences that we can use to throttle if we get too far
    // ahead of the image presents
    VkFenceCreateInfo fence_ci = {
        .sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO, .pNext = NULL, .flags = VK_FENCE_CREATE_SIGNALED_BIT};
    for (uint32_t i = 0; i < FRAME_LAG; i++) {
        err = vkCreateFence(demo->device, &fence_ci, NULL, &demo->fences[i]);
        assert(!err);

        if (demo->wsi_platform != WSI_PLATFORM_FILE)
        {
            err = vkCreateSemaphore(demo->device, &semaphoreCreateInfo, NULL, &demo->image_acquired_semaphores[i]);
            assert(!err);
            demo_name_object(demo, VK_OBJECT_TYPE_SEMAPHORE, (uint64_t)demo->image_acquired_semaphores[i], "AcquireSem(%u)", i);

            err = vkCreateSemaphore(demo->device, &semaphoreCreateInfo, NULL, &demo->draw_complete_semaphores[i]);
            assert(!err);
            demo_name_object(demo, VK_OBJECT_TYPE_SEMAPHORE, (uint64_t)demo->draw_complete_semaphores[i], "DrawCompleteSem(%u)", i);

            if (demo->separate_present_queue) {
                err = vkCreateSemaphore(demo->device, &semaphoreCreateInfo, NULL, &demo->image_ownership_semaphores[i]);
                assert(!err);
                demo_name_object(demo, VK_OBJECT_TYPE_SEMAPHORE, (uint64_t)demo->image_ownership_semaphores[i], "ImageOwnerSem(%u)", i);
            }
        }
    }
    demo->frame_index = 0;
    demo->first_swapchain_frame = true;
}

static void demo_init(struct demo *demo, int argc, char **argv) {
    vec3 eye = {0.0f, 3.0f, 5.0f};
    vec3 origin = {0, 0, 0};
    vec3 up = {0.0f, 1.0f, 0.0};

    memset(demo, 0, sizeof(*demo));
    demo->presentMode = VK_PRESENT_MODE_FIFO_KHR;
    demo->frameCount = INT32_MAX;
    /* Autodetect suitable / best GPU by default */
    demo->gpu_number = -1;
    demo->width = -1;
    demo->height = -1;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--use_staging") == 0) {
            demo->use_staging_buffer = true;
            continue;
        }
        if ((strcmp(argv[i], "--present_mode") == 0) && (i < argc - 1)) {
            demo->presentMode = atoi(argv[i + 1]);
            i++;
            continue;
        }
        if (strcmp(argv[i], "--break") == 0) {
            demo->use_break = true;
            continue;
        }
        if (strcmp(argv[i], "--validate") == 0) {
            demo->validate = true;
            continue;
        }
        if (strcmp(argv[i], "--c") == 0 && demo->frameCount == INT32_MAX && i < argc - 1 &&
            sscanf(argv[i + 1], "%d", &demo->frameCount) == 1 && demo->frameCount >= 0) {
            i++;
            continue;
        }
        if (strcmp(argv[i], "--width") == 0) {
            if (i < argc - 1 && sscanf(argv[i + 1], "%d", &demo->width) == 1) {
                if (demo->width > 0) {
                    i++;
                    continue;
                } else {
                    ERR_EXIT("The --width parameter must be greater than 0", "User Error");
                }
            }
            ERR_EXIT("The --width parameter must be followed by a number", "User Error");
        }
        if (strcmp(argv[i], "--height") == 0) {
            if (i < argc - 1 && sscanf(argv[i + 1], "%d", &demo->height) == 1) {
                if (demo->height > 0) {
                    i++;
                    continue;
                } else {
                    ERR_EXIT("The --height parameter must be greater than 0", "User Error");
                }
            }
            ERR_EXIT("The --height parameter must be followed by a number", "User Error");
        }
        if (strcmp(argv[i], "--pipeline-cache") == 0) {
            if (i < argc - 1) {
                demo->pipeline_cache_path = argv[++i];
                continue;
            }
            ERR_EXIT("The --pipeline-cache parameter must be followed by a path", "User Error");
        }
        if (strcmp(argv[i], "--suppress_popups") == 0) {
            demo->suppress_popups = true;
            continue;
        }
        if (strcmp(argv[i], "--incremental_present") == 0) {
            demo->VK_KHR_incremental_present_enabled = true;
            continue;
        }
        if ((strcmp(argv[i], "--gpu_number") == 0) && (i < argc - 1)) {
            demo->gpu_number = atoi(argv[i + 1]);
            if (demo->gpu_number < 0) demo->invalid_gpu_selection = true;
            i++;
            continue;
        }
        if (strcmp(argv[i], "--force_errors") == 0) {
            demo->force_errors = true;
            continue;
        }
        if ((strcmp(argv[i], "--wsi") == 0) && (i < argc - 1)) {
            size_t argc_len = strlen(argv[i + 1]);
            for (size_t argc_i = 0; argc_i < argc_len; argc_i++) {
                argv[i + 1][argc_i] = tolower(argv[i + 1][argc_i]);
            }
            WSI_PLATFORM selection = wsi_from_string(argv[i + 1]);
            if (selection == WSI_PLATFORM_INVALID) {
                printf(
                    "The --wsi parameter %s is not a supported WSI platform. The list of available platforms is available from "
                    "--help\n",
                    (const char *)&(argv[i + 1][0]));
                fflush(stdout);
                exit(1);
            }
            demo->wsi_platform = selection;
            i++;
            continue;
        }

        // Making the help for --wsi nice requires a little extra work since the list depends on what is available at
        // compile time
#define MAX_STR_LEN 100
        char available_wsi_platforms[MAX_STR_LEN];
        memset(available_wsi_platforms, 0, MAX_STR_LEN);
#if defined(VK_USE_PLATFORM_DISPLAY_KHR)
        if (strlen(available_wsi_platforms) > 0) {
            strncat(available_wsi_platforms, "|", MAX_STR_LEN - 1);
        }
        strncat(available_wsi_platforms, "display", MAX_STR_LEN - 1);
#endif
        if (strlen(available_wsi_platforms) > 0) {
            strncat(available_wsi_platforms, "|", MAX_STR_LEN - 1);
        }
        strncat(available_wsi_platforms, "file", MAX_STR_LEN - 1);

        char *message =
            "Usage:\n  %s\t[--use_staging] [--validate]\n"
            "\t[--pipeline-cache <file>]\n"
            "\t[--break] [--c <framecount>] [--suppress_popups]\n"
            "\t[--incremental_present] [--display_timing]\n"
            "\t[--gpu_number <index of physical device>]\n"
            "\t[--present_mode <present mode enum>]\n"
            "\t[--width <width>] [--height <height>]\n"
            "\t[--force_errors]\n"
            "\t[--wsi <%s>]\n"
            "\t<present_mode_enum>\n"
            "\t\tVK_PRESENT_MODE_IMMEDIATE_KHR = %d\n"
            "\t\tVK_PRESENT_MODE_MAILBOX_KHR = %d\n"
            "\t\tVK_PRESENT_MODE_FIFO_KHR = %d\n"
            "\t\tVK_PRESENT_MODE_FIFO_RELAXED_KHR = %d\n";
#define MAX_MSG_LEN 2048
        int length = snprintf(NULL, 0, message, APP_SHORT_NAME, available_wsi_platforms, VK_PRESENT_MODE_IMMEDIATE_KHR,
                              VK_PRESENT_MODE_MAILBOX_KHR, VK_PRESENT_MODE_FIFO_KHR, VK_PRESENT_MODE_FIFO_RELAXED_KHR);
        char usage[MAX_MSG_LEN];
        snprintf(usage, length + 1, message, APP_SHORT_NAME, available_wsi_platforms, VK_PRESENT_MODE_IMMEDIATE_KHR,
                 VK_PRESENT_MODE_MAILBOX_KHR, VK_PRESENT_MODE_FIFO_KHR, VK_PRESENT_MODE_FIFO_RELAXED_KHR);
#if defined(_WIN32)
        if (!demo->suppress_popups) MessageBox(NULL, usage, "Usage Error", MB_OK);
#else
        fprintf(stderr, "%s", usage);
        fflush(stderr);
#endif
        exit(1);
    }

    demo_init_vk(demo);

    demo->spin_angle = 4.0f;
    demo->spin_increment = 0.2f;
    demo->pause = false;

    mat4x4_perspective(demo->projection_matrix, (float)degreesToRadians(45.0f), 1.0f, 0.1f, 100.0f);
    mat4x4_look_at(demo->view_matrix, eye, origin, up);
    mat4x4_identity(demo->model_matrix);

    demo->projection_matrix[1][1] *= -1;  // Flip projection matrix from GL to Vulkan orientation.
}

int main(int argc, char **argv) {
    struct demo demo;

    demo_init(&demo, argc, argv);
    switch (demo.wsi_platform) {
        default:
        case (WSI_PLATFORM_AUTO):
            fprintf(stderr,
                    "WSI platform should have already been set, indicating a bug. Please set a WSI platform manually with "
                    "--wsi\n");
            exit(1);
            break;
#if defined(VK_USE_PLATFORM_DISPLAY_KHR)
        case (WSI_PLATFORM_DISPLAY):
            // nothing to do here
            break;
#endif
        case (WSI_PLATFORM_FILE):
            // nothing to do here
            break;
    }

    demo_init_vk_swapchain(&demo);

    demo_prepare(&demo);

    switch (demo.wsi_platform) {
        default:
        case (WSI_PLATFORM_AUTO):
            fprintf(stderr,
                    "WSI platform should have already been set, indicating a bug. Please set a WSI platform manually with "
                    "--wsi\n");
            exit(1);
            break;
#if defined(VK_USE_PLATFORM_DISPLAY_KHR)
        case (WSI_PLATFORM_DISPLAY):
            demo_run_display(&demo);
            break;
#endif
        case (WSI_PLATFORM_FILE):
            demo_run_image_dump(&demo);
            break;
    }

    demo_cleanup(&demo);

    return validation_error;
}
