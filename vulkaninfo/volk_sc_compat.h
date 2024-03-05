// Copyright 2024 The Khronos Group Inc.
// Copyright 2024 RasterGrid Kft.
//
// SPDX-License-Identifier: Apache-2.0
//
// Simple header-only limited functionality compatibility layer for volk on Vulkan SC.
// Necessary, because volk is a Vulkan API loader library but is now a dependency of
// the vulkaninfo tool and thus its Vulkan SC equivalent: the vulkanscinfo tool
#pragma once

#ifdef VULKANSC

VkResult volkInitializeSC(void)
{
#if defined(_WIN32)
    HMODULE module = LoadLibraryA("vulkansc-1.dll");
    if (!module)
        return VK_ERROR_INITIALIZATION_FAILED;

    // note: function pointer is cast through void function pointer to silence cast-function-type warning on gcc8
    vkGetInstanceProcAddr = (PFN_vkGetInstanceProcAddr)(void(*)(void))GetProcAddress(module, "vkGetInstanceProcAddr");
#elif defined(__APPLE__)
    void* module = dlopen("libvulkansc.dylib", RTLD_NOW | RTLD_LOCAL);
    if (!module)
        module = dlopen("libvulkansc.1.dylib", RTLD_NOW | RTLD_LOCAL);
    // modern versions of macOS don't search /usr/local/lib automatically contrary to what man dlopen says
    // Vulkan SDK uses this as the system-wide installation location, so we're going to fallback to this if all else fails
    if (!module && getenv("DYLD_FALLBACK_LIBRARY_PATH") == NULL)
        module = dlopen("/usr/local/lib/libvulkansc.dylib", RTLD_NOW | RTLD_LOCAL);
    if (!module)
        return VK_ERROR_INITIALIZATION_FAILED;

    vkGetInstanceProcAddr = (PFN_vkGetInstanceProcAddr)dlsym(module, "vkGetInstanceProcAddr");
#else
    void* module = dlopen("libvulkansc.so.1", RTLD_NOW | RTLD_LOCAL);
    if (!module)
        module = dlopen("libvulkansc.so", RTLD_NOW | RTLD_LOCAL);
    if (!module)
        return VK_ERROR_INITIALIZATION_FAILED;

    vkGetInstanceProcAddr = (PFN_vkGetInstanceProcAddr)dlsym(module, "vkGetInstanceProcAddr");
#endif

    loadedModule = module;
    volkGenLoadLoader(NULL, vkGetInstanceProcAddrStub);

    return VK_SUCCESS;
}

void volkLoadInstanceSC(VkInstance instance)
{
    loadedInstance = instance;
    volkGenLoadInstance(instance, vkGetInstanceProcAddrStub);
    volkGenLoadDevice(instance, vkGetInstanceProcAddrStub);

    // Make the needed extension function pointers part of Vulkan SC 1.0 core available
    vkEnumeratePhysicalDeviceGroupsKHR = vkEnumeratePhysicalDeviceGroups;
    vkGetPhysicalDeviceFeatures2KHR = vkGetPhysicalDeviceFeatures2;
    vkGetPhysicalDeviceProperties2KHR = vkGetPhysicalDeviceProperties2;
    vkGetPhysicalDeviceFormatProperties2KHR = vkGetPhysicalDeviceFormatProperties2;
    vkGetPhysicalDeviceImageFormatProperties2KHR = vkGetPhysicalDeviceImageFormatProperties2;
    vkGetPhysicalDeviceQueueFamilyProperties2KHR = vkGetPhysicalDeviceQueueFamilyProperties2;
    vkGetPhysicalDeviceMemoryProperties2KHR = vkGetPhysicalDeviceMemoryProperties2;
}

#define volkInitialize volkInitializeSC
#define volkLoadInstance volkLoadInstanceSC

#endif  // VULKANSC
