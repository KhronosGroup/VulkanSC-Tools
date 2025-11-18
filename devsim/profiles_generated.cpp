
/*
 * Copyright (C) 2015-2024 Valve Corporation
 * Copyright (C) 2015-2024 LunarG, Inc.
 * Copyright (C) 2023-2024 RasterGrid Kft.
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
 *
 * Authors:
 * - Ziga Markus <ziga@lunarg.com>
 * - Christophe Riccio <christophe@lunarg.com>
 * - Mark Lobodzinski <mark@lunarg.com>
 * - Mike Weiblen
 * - Arda Coskunses
 * - Jeremy Kniager

 * This file is ***GENERATED***.  Do Not Edit.
 * See scripts/gen_profiles_layer.py for modifications.
 */

/*
 * layer/profiles.cpp - The VK_LAYER_KHRONOS_profiles layer.
 * This Profiles layer simulates a device by loading a JSON configuration file to override values that would normally be returned
 * from a Vulkan implementation.  Configuration files must validate with the Profiles schema; this layer does not redundantly
 * check for configuration errors that would be caught by schema validation.
 *
 * References (several documents are also included in the LunarG Vulkan SDK, see [SDK]):
 * [SPEC]   https://www.khronos.org/registry/vulkan/specs/1.0-extensions/html/vkspec.html
 * [SDK]    https://vulkan.lunarg.com/sdk/home
 * [LALI]   https://github.com/KhronosGroup/Vulkan-Loader/blob/main/loader/LoaderAndLayerInterface.md
 *
 * Misc notes:
 * This code generally follows the spirit of the Google C++ styleguide, while accommodating conventions of the Vulkan styleguide.
 * https://google.github.io/styleguide/cppguide.html
 * https://www.khronos.org/registry/vulkan/specs/1.1/styleguide.html
 */

#include "profiles.h"
#include "profiles_util.h"
#include "profiles_json.h"
#include "profiles_settings.h"
#include <algorithm>
#include <filesystem>
#include <functional>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <optional>

namespace fs = std::filesystem;

SimulateCapabilityFlags GetSimulateCapabilityFlags(const std::vector<std::string> &values) {
    SimulateCapabilityFlags result = 0;

    for (std::size_t i = 0, n = values.size(); i < n; ++i) {
        if (values[i] == "SIMULATE_API_VERSION_BIT") {
            result |= SIMULATE_API_VERSION_BIT;
        } else if (values[i] == "SIMULATE_FEATURES_BIT") {
            result |= SIMULATE_FEATURES_BIT;
        } else if (values[i] == "SIMULATE_PROPERTIES_BIT") {
            result |= SIMULATE_PROPERTIES_BIT;
        } else if (values[i] == "SIMULATE_EXTENSIONS_BIT") {
            result |= SIMULATE_EXTENSIONS_BIT;
        } else if (values[i] == "SIMULATE_FORMATS_BIT") {
            result |= SIMULATE_FORMATS_BIT;
        } else if (values[i] == "SIMULATE_QUEUE_FAMILY_PROPERTIES_BIT") {
            result |= SIMULATE_QUEUE_FAMILY_PROPERTIES_BIT;
        } else if (values[i] == "SIMULATE_VIDEO_CAPABILITIES_BIT") {
            result |= SIMULATE_VIDEO_CAPABILITIES_BIT;
        } else if (values[i] == "SIMULATE_VIDEO_FORMATS_BIT") {
            result |= SIMULATE_VIDEO_FORMATS_BIT;
        } else if (values[i] == "SIMULATE_MAX_ENUM") {
            result |= SIMULATE_MAX_ENUM;
        }
    }

    return result;
}

std::string GetSimulateCapabilitiesLog(SimulateCapabilityFlags flags) {
    std::string result = {};

    if (flags & SIMULATE_API_VERSION_BIT) {
        result += "SIMULATE_API_VERSION_BIT";
    }
    if (flags & SIMULATE_FEATURES_BIT) {
        if (!result.empty()) result += ", ";
        result += "SIMULATE_FEATURES_BIT";
    }
    if (flags & SIMULATE_PROPERTIES_BIT) {
        if (!result.empty()) result += ", ";
        result += "SIMULATE_PROPERTIES_BIT";
    }
    if (flags & SIMULATE_EXTENSIONS_BIT) {
        if (!result.empty()) result += ", ";
        result += "SIMULATE_EXTENSIONS_BIT";
    }
    if (flags & SIMULATE_FORMATS_BIT) {
        if (!result.empty()) result += ", ";
        result += "SIMULATE_FORMATS_BIT";
    }
    if (flags & SIMULATE_QUEUE_FAMILY_PROPERTIES_BIT) {
        if (!result.empty()) result += ", ";
        result += "SIMULATE_QUEUE_FAMILY_PROPERTIES_BIT";
    }
    if (flags & SIMULATE_VIDEO_CAPABILITIES_BIT) {
        if (!result.empty()) result += ", ";
        result += "SIMULATE_VIDEO_CAPABILITIES_BIT";
    }
    if (flags & SIMULATE_VIDEO_FORMATS_BIT) {
        if (!result.empty()) result += ", ";
        result += "SIMULATE_VIDEO_FORMATS_BIT";
    }

    return result;
}

std::string GetDebugReportsLog(DebugActionFlags flags) {
    std::string result = {};

    if (flags & DEBUG_REPORT_NOTIFICATION_BIT) {
        result += "DEBUG_REPORT_NOTIFICATION_BIT";
    }
    if (flags & DEBUG_REPORT_WARNING_BIT) {
        if (!result.empty()) result += ", ";
        result += "DEBUG_REPORT_WARNING_BIT";
    }
    if (flags & DEBUG_REPORT_ERROR_BIT) {
        if (!result.empty()) result += ", ";
        result += "DEBUG_REPORT_ERROR_BIT";
    }
    if (flags & DEBUG_REPORT_DEBUG_BIT) {
        if (!result.empty()) result += ", ";
        result += "DEBUG_REPORT_DEBUG_BIT";
    }

    return result;
}

std::string GetFormatFeatureString(VkFormatFeatureFlags flags) {
    std::string result = {};

    if (flags & VK_FORMAT_FEATURE_SAMPLED_IMAGE_BIT) {
        result += "VK_FORMAT_FEATURE_SAMPLED_IMAGE_BIT";
    }
    if (flags & VK_FORMAT_FEATURE_STORAGE_IMAGE_BIT) {
        if (!result.empty()) result += ", ";
        result += "VK_FORMAT_FEATURE_STORAGE_IMAGE_BIT";
    }
    if (flags & VK_FORMAT_FEATURE_STORAGE_IMAGE_ATOMIC_BIT) {
        if (!result.empty()) result += ", ";
        result += "VK_FORMAT_FEATURE_STORAGE_IMAGE_ATOMIC_BIT";
    }
    if (flags & VK_FORMAT_FEATURE_UNIFORM_TEXEL_BUFFER_BIT) {
        if (!result.empty()) result += ", ";
        result += "VK_FORMAT_FEATURE_UNIFORM_TEXEL_BUFFER_BIT";
    }
    if (flags & VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_BIT) {
        if (!result.empty()) result += ", ";
        result += "VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_BIT";
    }
    if (flags & VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_ATOMIC_BIT) {
        if (!result.empty()) result += ", ";
        result += "VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_ATOMIC_BIT";
    }
    if (flags & VK_FORMAT_FEATURE_VERTEX_BUFFER_BIT) {
        if (!result.empty()) result += ", ";
        result += "VK_FORMAT_FEATURE_VERTEX_BUFFER_BIT";
    }
    if (flags & VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BIT) {
        if (!result.empty()) result += ", ";
        result += "VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BIT";
    }
    if (flags & VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BLEND_BIT) {
        if (!result.empty()) result += ", ";
        result += "VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BLEND_BIT";
    }
    if (flags & VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT) {
        if (!result.empty()) result += ", ";
        result += "VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT";
    }
    if (flags & VK_FORMAT_FEATURE_BLIT_SRC_BIT) {
        if (!result.empty()) result += ", ";
        result += "VK_FORMAT_FEATURE_BLIT_SRC_BIT";
    }
    if (flags & VK_FORMAT_FEATURE_BLIT_DST_BIT) {
        if (!result.empty()) result += ", ";
        result += "VK_FORMAT_FEATURE_BLIT_DST_BIT";
    }
    if (flags & VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_LINEAR_BIT) {
        if (!result.empty()) result += ", ";
        result += "VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_LINEAR_BIT";
    }
    if (flags & VK_FORMAT_FEATURE_TRANSFER_SRC_BIT) {
        if (!result.empty()) result += ", ";
        result += "VK_FORMAT_FEATURE_TRANSFER_SRC_BIT";
    }
    if (flags & VK_FORMAT_FEATURE_TRANSFER_DST_BIT) {
        if (!result.empty()) result += ", ";
        result += "VK_FORMAT_FEATURE_TRANSFER_DST_BIT";
    }
    if (flags & VK_FORMAT_FEATURE_MIDPOINT_CHROMA_SAMPLES_BIT) {
        if (!result.empty()) result += ", ";
        result += "VK_FORMAT_FEATURE_MIDPOINT_CHROMA_SAMPLES_BIT";
    }
    if (flags & VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER_BIT) {
        if (!result.empty()) result += ", ";
        result += "VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER_BIT";
    }
    if (flags & VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_SEPARATE_RECONSTRUCTION_FILTER_BIT) {
        if (!result.empty()) result += ", ";
        result += "VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_SEPARATE_RECONSTRUCTION_FILTER_BIT";
    }
    if (flags & VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_BIT) {
        if (!result.empty()) result += ", ";
        result += "VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_BIT";
    }
    if (flags & VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_FORCEABLE_BIT) {
        if (!result.empty()) result += ", ";
        result += "VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_FORCEABLE_BIT";
    }
    if (flags & VK_FORMAT_FEATURE_DISJOINT_BIT) {
        if (!result.empty()) result += ", ";
        result += "VK_FORMAT_FEATURE_DISJOINT_BIT";
    }
    if (flags & VK_FORMAT_FEATURE_COSITED_CHROMA_SAMPLES_BIT) {
        if (!result.empty()) result += ", ";
        result += "VK_FORMAT_FEATURE_COSITED_CHROMA_SAMPLES_BIT";
    }
    if (flags & VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_MINMAX_BIT) {
        if (!result.empty()) result += ", ";
        result += "VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_MINMAX_BIT";
    }
    if (flags & VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_CUBIC_BIT_EXT) {
        if (!result.empty()) result += ", ";
        result += "VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_CUBIC_BIT_EXT";
    }
    if (flags & VK_FORMAT_FEATURE_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR) {
        if (!result.empty()) result += ", ";
        result += "VK_FORMAT_FEATURE_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR";
    }

    return result;
}

std::string GetFormatFeature2String(VkFormatFeatureFlags2 flags) {
    std::string result = {};

    if (flags & VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_BIT) {
        result += "VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_BIT";
    }
    if (flags & VK_FORMAT_FEATURE_2_STORAGE_IMAGE_BIT) {
        if (!result.empty()) result += ", ";
        result += "VK_FORMAT_FEATURE_2_STORAGE_IMAGE_BIT";
    }
    if (flags & VK_FORMAT_FEATURE_2_STORAGE_IMAGE_ATOMIC_BIT) {
        if (!result.empty()) result += ", ";
        result += "VK_FORMAT_FEATURE_2_STORAGE_IMAGE_ATOMIC_BIT";
    }
    if (flags & VK_FORMAT_FEATURE_2_UNIFORM_TEXEL_BUFFER_BIT) {
        if (!result.empty()) result += ", ";
        result += "VK_FORMAT_FEATURE_2_UNIFORM_TEXEL_BUFFER_BIT";
    }
    if (flags & VK_FORMAT_FEATURE_2_STORAGE_TEXEL_BUFFER_BIT) {
        if (!result.empty()) result += ", ";
        result += "VK_FORMAT_FEATURE_2_STORAGE_TEXEL_BUFFER_BIT";
    }
    if (flags & VK_FORMAT_FEATURE_2_STORAGE_TEXEL_BUFFER_ATOMIC_BIT) {
        if (!result.empty()) result += ", ";
        result += "VK_FORMAT_FEATURE_2_STORAGE_TEXEL_BUFFER_ATOMIC_BIT";
    }
    if (flags & VK_FORMAT_FEATURE_2_VERTEX_BUFFER_BIT) {
        if (!result.empty()) result += ", ";
        result += "VK_FORMAT_FEATURE_2_VERTEX_BUFFER_BIT";
    }
    if (flags & VK_FORMAT_FEATURE_2_COLOR_ATTACHMENT_BIT) {
        if (!result.empty()) result += ", ";
        result += "VK_FORMAT_FEATURE_2_COLOR_ATTACHMENT_BIT";
    }
    if (flags & VK_FORMAT_FEATURE_2_COLOR_ATTACHMENT_BLEND_BIT) {
        if (!result.empty()) result += ", ";
        result += "VK_FORMAT_FEATURE_2_COLOR_ATTACHMENT_BLEND_BIT";
    }
    if (flags & VK_FORMAT_FEATURE_2_DEPTH_STENCIL_ATTACHMENT_BIT) {
        if (!result.empty()) result += ", ";
        result += "VK_FORMAT_FEATURE_2_DEPTH_STENCIL_ATTACHMENT_BIT";
    }
    if (flags & VK_FORMAT_FEATURE_2_BLIT_SRC_BIT) {
        if (!result.empty()) result += ", ";
        result += "VK_FORMAT_FEATURE_2_BLIT_SRC_BIT";
    }
    if (flags & VK_FORMAT_FEATURE_2_BLIT_DST_BIT) {
        if (!result.empty()) result += ", ";
        result += "VK_FORMAT_FEATURE_2_BLIT_DST_BIT";
    }
    if (flags & VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_LINEAR_BIT) {
        if (!result.empty()) result += ", ";
        result += "VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_LINEAR_BIT";
    }
    if (flags & VK_FORMAT_FEATURE_2_TRANSFER_SRC_BIT) {
        if (!result.empty()) result += ", ";
        result += "VK_FORMAT_FEATURE_2_TRANSFER_SRC_BIT";
    }
    if (flags & VK_FORMAT_FEATURE_2_TRANSFER_DST_BIT) {
        if (!result.empty()) result += ", ";
        result += "VK_FORMAT_FEATURE_2_TRANSFER_DST_BIT";
    }
    if (flags & VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_MINMAX_BIT) {
        if (!result.empty()) result += ", ";
        result += "VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_MINMAX_BIT";
    }
    if (flags & VK_FORMAT_FEATURE_2_MIDPOINT_CHROMA_SAMPLES_BIT) {
        if (!result.empty()) result += ", ";
        result += "VK_FORMAT_FEATURE_2_MIDPOINT_CHROMA_SAMPLES_BIT";
    }
    if (flags & VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER_BIT) {
        if (!result.empty()) result += ", ";
        result += "VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER_BIT";
    }
    if (flags & VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_SEPARATE_RECONSTRUCTION_FILTER_BIT) {
        if (!result.empty()) result += ", ";
        result += "VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_SEPARATE_RECONSTRUCTION_FILTER_BIT";
    }
    if (flags & VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_BIT) {
        if (!result.empty()) result += ", ";
        result += "VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_BIT";
    }
    if (flags & VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_FORCEABLE_BIT) {
        if (!result.empty()) result += ", ";
        result += "VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_FORCEABLE_BIT";
    }
    if (flags & VK_FORMAT_FEATURE_2_DISJOINT_BIT) {
        if (!result.empty()) result += ", ";
        result += "VK_FORMAT_FEATURE_2_DISJOINT_BIT";
    }
    if (flags & VK_FORMAT_FEATURE_2_COSITED_CHROMA_SAMPLES_BIT) {
        if (!result.empty()) result += ", ";
        result += "VK_FORMAT_FEATURE_2_COSITED_CHROMA_SAMPLES_BIT";
    }
    if (flags & VK_FORMAT_FEATURE_2_STORAGE_READ_WITHOUT_FORMAT_BIT) {
        if (!result.empty()) result += ", ";
        result += "VK_FORMAT_FEATURE_2_STORAGE_READ_WITHOUT_FORMAT_BIT";
    }
    if (flags & VK_FORMAT_FEATURE_2_STORAGE_WRITE_WITHOUT_FORMAT_BIT) {
        if (!result.empty()) result += ", ";
        result += "VK_FORMAT_FEATURE_2_STORAGE_WRITE_WITHOUT_FORMAT_BIT";
    }
    if (flags & VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_DEPTH_COMPARISON_BIT) {
        if (!result.empty()) result += ", ";
        result += "VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_DEPTH_COMPARISON_BIT";
    }
    if (flags & VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_CUBIC_BIT) {
        if (!result.empty()) result += ", ";
        result += "VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_CUBIC_BIT";
    }
    if (flags & VK_FORMAT_FEATURE_2_HOST_IMAGE_TRANSFER_BIT) {
        if (!result.empty()) result += ", ";
        result += "VK_FORMAT_FEATURE_2_HOST_IMAGE_TRANSFER_BIT";
    }
    if (flags & VK_FORMAT_FEATURE_2_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR) {
        if (!result.empty()) result += ", ";
        result += "VK_FORMAT_FEATURE_2_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR";
    }

    return result;
}

std::string GetQueueFlagsToString(VkQueueFlags flags) {
    std::string result = {};

    if (flags & VK_QUEUE_GRAPHICS_BIT) {
        result += "VK_QUEUE_GRAPHICS_BIT";
    }
    if (flags & VK_QUEUE_COMPUTE_BIT) {
        if (!result.empty()) result += ", ";
        result += "VK_QUEUE_COMPUTE_BIT";
    }
    if (flags & VK_QUEUE_TRANSFER_BIT) {
        if (!result.empty()) result += ", ";
        result += "VK_QUEUE_TRANSFER_BIT";
    }
    if (flags & VK_QUEUE_PROTECTED_BIT) {
        if (!result.empty()) result += ", ";
        result += "VK_QUEUE_PROTECTED_BIT";
    }

    return result;
}

std::string vkFormatToString(VkFormat fmt) {
    switch (fmt) {
        case VK_FORMAT_UNDEFINED:
            return "VK_FORMAT_UNDEFINED";
        case VK_FORMAT_R4G4_UNORM_PACK8:
            return "VK_FORMAT_R4G4_UNORM_PACK8";
        case VK_FORMAT_R4G4B4A4_UNORM_PACK16:
            return "VK_FORMAT_R4G4B4A4_UNORM_PACK16";
        case VK_FORMAT_B4G4R4A4_UNORM_PACK16:
            return "VK_FORMAT_B4G4R4A4_UNORM_PACK16";
        case VK_FORMAT_R5G6B5_UNORM_PACK16:
            return "VK_FORMAT_R5G6B5_UNORM_PACK16";
        case VK_FORMAT_B5G6R5_UNORM_PACK16:
            return "VK_FORMAT_B5G6R5_UNORM_PACK16";
        case VK_FORMAT_R5G5B5A1_UNORM_PACK16:
            return "VK_FORMAT_R5G5B5A1_UNORM_PACK16";
        case VK_FORMAT_B5G5R5A1_UNORM_PACK16:
            return "VK_FORMAT_B5G5R5A1_UNORM_PACK16";
        case VK_FORMAT_A1R5G5B5_UNORM_PACK16:
            return "VK_FORMAT_A1R5G5B5_UNORM_PACK16";
        case VK_FORMAT_R8_UNORM:
            return "VK_FORMAT_R8_UNORM";
        case VK_FORMAT_R8_SNORM:
            return "VK_FORMAT_R8_SNORM";
        case VK_FORMAT_R8_USCALED:
            return "VK_FORMAT_R8_USCALED";
        case VK_FORMAT_R8_SSCALED:
            return "VK_FORMAT_R8_SSCALED";
        case VK_FORMAT_R8_UINT:
            return "VK_FORMAT_R8_UINT";
        case VK_FORMAT_R8_SINT:
            return "VK_FORMAT_R8_SINT";
        case VK_FORMAT_R8_SRGB:
            return "VK_FORMAT_R8_SRGB";
        case VK_FORMAT_R8G8_UNORM:
            return "VK_FORMAT_R8G8_UNORM";
        case VK_FORMAT_R8G8_SNORM:
            return "VK_FORMAT_R8G8_SNORM";
        case VK_FORMAT_R8G8_USCALED:
            return "VK_FORMAT_R8G8_USCALED";
        case VK_FORMAT_R8G8_SSCALED:
            return "VK_FORMAT_R8G8_SSCALED";
        case VK_FORMAT_R8G8_UINT:
            return "VK_FORMAT_R8G8_UINT";
        case VK_FORMAT_R8G8_SINT:
            return "VK_FORMAT_R8G8_SINT";
        case VK_FORMAT_R8G8_SRGB:
            return "VK_FORMAT_R8G8_SRGB";
        case VK_FORMAT_R8G8B8_UNORM:
            return "VK_FORMAT_R8G8B8_UNORM";
        case VK_FORMAT_R8G8B8_SNORM:
            return "VK_FORMAT_R8G8B8_SNORM";
        case VK_FORMAT_R8G8B8_USCALED:
            return "VK_FORMAT_R8G8B8_USCALED";
        case VK_FORMAT_R8G8B8_SSCALED:
            return "VK_FORMAT_R8G8B8_SSCALED";
        case VK_FORMAT_R8G8B8_UINT:
            return "VK_FORMAT_R8G8B8_UINT";
        case VK_FORMAT_R8G8B8_SINT:
            return "VK_FORMAT_R8G8B8_SINT";
        case VK_FORMAT_R8G8B8_SRGB:
            return "VK_FORMAT_R8G8B8_SRGB";
        case VK_FORMAT_B8G8R8_UNORM:
            return "VK_FORMAT_B8G8R8_UNORM";
        case VK_FORMAT_B8G8R8_SNORM:
            return "VK_FORMAT_B8G8R8_SNORM";
        case VK_FORMAT_B8G8R8_USCALED:
            return "VK_FORMAT_B8G8R8_USCALED";
        case VK_FORMAT_B8G8R8_SSCALED:
            return "VK_FORMAT_B8G8R8_SSCALED";
        case VK_FORMAT_B8G8R8_UINT:
            return "VK_FORMAT_B8G8R8_UINT";
        case VK_FORMAT_B8G8R8_SINT:
            return "VK_FORMAT_B8G8R8_SINT";
        case VK_FORMAT_B8G8R8_SRGB:
            return "VK_FORMAT_B8G8R8_SRGB";
        case VK_FORMAT_R8G8B8A8_UNORM:
            return "VK_FORMAT_R8G8B8A8_UNORM";
        case VK_FORMAT_R8G8B8A8_SNORM:
            return "VK_FORMAT_R8G8B8A8_SNORM";
        case VK_FORMAT_R8G8B8A8_USCALED:
            return "VK_FORMAT_R8G8B8A8_USCALED";
        case VK_FORMAT_R8G8B8A8_SSCALED:
            return "VK_FORMAT_R8G8B8A8_SSCALED";
        case VK_FORMAT_R8G8B8A8_UINT:
            return "VK_FORMAT_R8G8B8A8_UINT";
        case VK_FORMAT_R8G8B8A8_SINT:
            return "VK_FORMAT_R8G8B8A8_SINT";
        case VK_FORMAT_R8G8B8A8_SRGB:
            return "VK_FORMAT_R8G8B8A8_SRGB";
        case VK_FORMAT_B8G8R8A8_UNORM:
            return "VK_FORMAT_B8G8R8A8_UNORM";
        case VK_FORMAT_B8G8R8A8_SNORM:
            return "VK_FORMAT_B8G8R8A8_SNORM";
        case VK_FORMAT_B8G8R8A8_USCALED:
            return "VK_FORMAT_B8G8R8A8_USCALED";
        case VK_FORMAT_B8G8R8A8_SSCALED:
            return "VK_FORMAT_B8G8R8A8_SSCALED";
        case VK_FORMAT_B8G8R8A8_UINT:
            return "VK_FORMAT_B8G8R8A8_UINT";
        case VK_FORMAT_B8G8R8A8_SINT:
            return "VK_FORMAT_B8G8R8A8_SINT";
        case VK_FORMAT_B8G8R8A8_SRGB:
            return "VK_FORMAT_B8G8R8A8_SRGB";
        case VK_FORMAT_A8B8G8R8_UNORM_PACK32:
            return "VK_FORMAT_A8B8G8R8_UNORM_PACK32";
        case VK_FORMAT_A8B8G8R8_SNORM_PACK32:
            return "VK_FORMAT_A8B8G8R8_SNORM_PACK32";
        case VK_FORMAT_A8B8G8R8_USCALED_PACK32:
            return "VK_FORMAT_A8B8G8R8_USCALED_PACK32";
        case VK_FORMAT_A8B8G8R8_SSCALED_PACK32:
            return "VK_FORMAT_A8B8G8R8_SSCALED_PACK32";
        case VK_FORMAT_A8B8G8R8_UINT_PACK32:
            return "VK_FORMAT_A8B8G8R8_UINT_PACK32";
        case VK_FORMAT_A8B8G8R8_SINT_PACK32:
            return "VK_FORMAT_A8B8G8R8_SINT_PACK32";
        case VK_FORMAT_A8B8G8R8_SRGB_PACK32:
            return "VK_FORMAT_A8B8G8R8_SRGB_PACK32";
        case VK_FORMAT_A2R10G10B10_UNORM_PACK32:
            return "VK_FORMAT_A2R10G10B10_UNORM_PACK32";
        case VK_FORMAT_A2R10G10B10_SNORM_PACK32:
            return "VK_FORMAT_A2R10G10B10_SNORM_PACK32";
        case VK_FORMAT_A2R10G10B10_USCALED_PACK32:
            return "VK_FORMAT_A2R10G10B10_USCALED_PACK32";
        case VK_FORMAT_A2R10G10B10_SSCALED_PACK32:
            return "VK_FORMAT_A2R10G10B10_SSCALED_PACK32";
        case VK_FORMAT_A2R10G10B10_UINT_PACK32:
            return "VK_FORMAT_A2R10G10B10_UINT_PACK32";
        case VK_FORMAT_A2R10G10B10_SINT_PACK32:
            return "VK_FORMAT_A2R10G10B10_SINT_PACK32";
        case VK_FORMAT_A2B10G10R10_UNORM_PACK32:
            return "VK_FORMAT_A2B10G10R10_UNORM_PACK32";
        case VK_FORMAT_A2B10G10R10_SNORM_PACK32:
            return "VK_FORMAT_A2B10G10R10_SNORM_PACK32";
        case VK_FORMAT_A2B10G10R10_USCALED_PACK32:
            return "VK_FORMAT_A2B10G10R10_USCALED_PACK32";
        case VK_FORMAT_A2B10G10R10_SSCALED_PACK32:
            return "VK_FORMAT_A2B10G10R10_SSCALED_PACK32";
        case VK_FORMAT_A2B10G10R10_UINT_PACK32:
            return "VK_FORMAT_A2B10G10R10_UINT_PACK32";
        case VK_FORMAT_A2B10G10R10_SINT_PACK32:
            return "VK_FORMAT_A2B10G10R10_SINT_PACK32";
        case VK_FORMAT_R16_UNORM:
            return "VK_FORMAT_R16_UNORM";
        case VK_FORMAT_R16_SNORM:
            return "VK_FORMAT_R16_SNORM";
        case VK_FORMAT_R16_USCALED:
            return "VK_FORMAT_R16_USCALED";
        case VK_FORMAT_R16_SSCALED:
            return "VK_FORMAT_R16_SSCALED";
        case VK_FORMAT_R16_UINT:
            return "VK_FORMAT_R16_UINT";
        case VK_FORMAT_R16_SINT:
            return "VK_FORMAT_R16_SINT";
        case VK_FORMAT_R16_SFLOAT:
            return "VK_FORMAT_R16_SFLOAT";
        case VK_FORMAT_R16G16_UNORM:
            return "VK_FORMAT_R16G16_UNORM";
        case VK_FORMAT_R16G16_SNORM:
            return "VK_FORMAT_R16G16_SNORM";
        case VK_FORMAT_R16G16_USCALED:
            return "VK_FORMAT_R16G16_USCALED";
        case VK_FORMAT_R16G16_SSCALED:
            return "VK_FORMAT_R16G16_SSCALED";
        case VK_FORMAT_R16G16_UINT:
            return "VK_FORMAT_R16G16_UINT";
        case VK_FORMAT_R16G16_SINT:
            return "VK_FORMAT_R16G16_SINT";
        case VK_FORMAT_R16G16_SFLOAT:
            return "VK_FORMAT_R16G16_SFLOAT";
        case VK_FORMAT_R16G16B16_UNORM:
            return "VK_FORMAT_R16G16B16_UNORM";
        case VK_FORMAT_R16G16B16_SNORM:
            return "VK_FORMAT_R16G16B16_SNORM";
        case VK_FORMAT_R16G16B16_USCALED:
            return "VK_FORMAT_R16G16B16_USCALED";
        case VK_FORMAT_R16G16B16_SSCALED:
            return "VK_FORMAT_R16G16B16_SSCALED";
        case VK_FORMAT_R16G16B16_UINT:
            return "VK_FORMAT_R16G16B16_UINT";
        case VK_FORMAT_R16G16B16_SINT:
            return "VK_FORMAT_R16G16B16_SINT";
        case VK_FORMAT_R16G16B16_SFLOAT:
            return "VK_FORMAT_R16G16B16_SFLOAT";
        case VK_FORMAT_R16G16B16A16_UNORM:
            return "VK_FORMAT_R16G16B16A16_UNORM";
        case VK_FORMAT_R16G16B16A16_SNORM:
            return "VK_FORMAT_R16G16B16A16_SNORM";
        case VK_FORMAT_R16G16B16A16_USCALED:
            return "VK_FORMAT_R16G16B16A16_USCALED";
        case VK_FORMAT_R16G16B16A16_SSCALED:
            return "VK_FORMAT_R16G16B16A16_SSCALED";
        case VK_FORMAT_R16G16B16A16_UINT:
            return "VK_FORMAT_R16G16B16A16_UINT";
        case VK_FORMAT_R16G16B16A16_SINT:
            return "VK_FORMAT_R16G16B16A16_SINT";
        case VK_FORMAT_R16G16B16A16_SFLOAT:
            return "VK_FORMAT_R16G16B16A16_SFLOAT";
        case VK_FORMAT_R32_UINT:
            return "VK_FORMAT_R32_UINT";
        case VK_FORMAT_R32_SINT:
            return "VK_FORMAT_R32_SINT";
        case VK_FORMAT_R32_SFLOAT:
            return "VK_FORMAT_R32_SFLOAT";
        case VK_FORMAT_R32G32_UINT:
            return "VK_FORMAT_R32G32_UINT";
        case VK_FORMAT_R32G32_SINT:
            return "VK_FORMAT_R32G32_SINT";
        case VK_FORMAT_R32G32_SFLOAT:
            return "VK_FORMAT_R32G32_SFLOAT";
        case VK_FORMAT_R32G32B32_UINT:
            return "VK_FORMAT_R32G32B32_UINT";
        case VK_FORMAT_R32G32B32_SINT:
            return "VK_FORMAT_R32G32B32_SINT";
        case VK_FORMAT_R32G32B32_SFLOAT:
            return "VK_FORMAT_R32G32B32_SFLOAT";
        case VK_FORMAT_R32G32B32A32_UINT:
            return "VK_FORMAT_R32G32B32A32_UINT";
        case VK_FORMAT_R32G32B32A32_SINT:
            return "VK_FORMAT_R32G32B32A32_SINT";
        case VK_FORMAT_R32G32B32A32_SFLOAT:
            return "VK_FORMAT_R32G32B32A32_SFLOAT";
        case VK_FORMAT_R64_UINT:
            return "VK_FORMAT_R64_UINT";
        case VK_FORMAT_R64_SINT:
            return "VK_FORMAT_R64_SINT";
        case VK_FORMAT_R64_SFLOAT:
            return "VK_FORMAT_R64_SFLOAT";
        case VK_FORMAT_R64G64_UINT:
            return "VK_FORMAT_R64G64_UINT";
        case VK_FORMAT_R64G64_SINT:
            return "VK_FORMAT_R64G64_SINT";
        case VK_FORMAT_R64G64_SFLOAT:
            return "VK_FORMAT_R64G64_SFLOAT";
        case VK_FORMAT_R64G64B64_UINT:
            return "VK_FORMAT_R64G64B64_UINT";
        case VK_FORMAT_R64G64B64_SINT:
            return "VK_FORMAT_R64G64B64_SINT";
        case VK_FORMAT_R64G64B64_SFLOAT:
            return "VK_FORMAT_R64G64B64_SFLOAT";
        case VK_FORMAT_R64G64B64A64_UINT:
            return "VK_FORMAT_R64G64B64A64_UINT";
        case VK_FORMAT_R64G64B64A64_SINT:
            return "VK_FORMAT_R64G64B64A64_SINT";
        case VK_FORMAT_R64G64B64A64_SFLOAT:
            return "VK_FORMAT_R64G64B64A64_SFLOAT";
        case VK_FORMAT_B10G11R11_UFLOAT_PACK32:
            return "VK_FORMAT_B10G11R11_UFLOAT_PACK32";
        case VK_FORMAT_E5B9G9R9_UFLOAT_PACK32:
            return "VK_FORMAT_E5B9G9R9_UFLOAT_PACK32";
        case VK_FORMAT_D16_UNORM:
            return "VK_FORMAT_D16_UNORM";
        case VK_FORMAT_X8_D24_UNORM_PACK32:
            return "VK_FORMAT_X8_D24_UNORM_PACK32";
        case VK_FORMAT_D32_SFLOAT:
            return "VK_FORMAT_D32_SFLOAT";
        case VK_FORMAT_S8_UINT:
            return "VK_FORMAT_S8_UINT";
        case VK_FORMAT_D16_UNORM_S8_UINT:
            return "VK_FORMAT_D16_UNORM_S8_UINT";
        case VK_FORMAT_D24_UNORM_S8_UINT:
            return "VK_FORMAT_D24_UNORM_S8_UINT";
        case VK_FORMAT_D32_SFLOAT_S8_UINT:
            return "VK_FORMAT_D32_SFLOAT_S8_UINT";
        case VK_FORMAT_BC1_RGB_UNORM_BLOCK:
            return "VK_FORMAT_BC1_RGB_UNORM_BLOCK";
        case VK_FORMAT_BC1_RGB_SRGB_BLOCK:
            return "VK_FORMAT_BC1_RGB_SRGB_BLOCK";
        case VK_FORMAT_BC1_RGBA_UNORM_BLOCK:
            return "VK_FORMAT_BC1_RGBA_UNORM_BLOCK";
        case VK_FORMAT_BC1_RGBA_SRGB_BLOCK:
            return "VK_FORMAT_BC1_RGBA_SRGB_BLOCK";
        case VK_FORMAT_BC2_UNORM_BLOCK:
            return "VK_FORMAT_BC2_UNORM_BLOCK";
        case VK_FORMAT_BC2_SRGB_BLOCK:
            return "VK_FORMAT_BC2_SRGB_BLOCK";
        case VK_FORMAT_BC3_UNORM_BLOCK:
            return "VK_FORMAT_BC3_UNORM_BLOCK";
        case VK_FORMAT_BC3_SRGB_BLOCK:
            return "VK_FORMAT_BC3_SRGB_BLOCK";
        case VK_FORMAT_BC4_UNORM_BLOCK:
            return "VK_FORMAT_BC4_UNORM_BLOCK";
        case VK_FORMAT_BC4_SNORM_BLOCK:
            return "VK_FORMAT_BC4_SNORM_BLOCK";
        case VK_FORMAT_BC5_UNORM_BLOCK:
            return "VK_FORMAT_BC5_UNORM_BLOCK";
        case VK_FORMAT_BC5_SNORM_BLOCK:
            return "VK_FORMAT_BC5_SNORM_BLOCK";
        case VK_FORMAT_BC6H_UFLOAT_BLOCK:
            return "VK_FORMAT_BC6H_UFLOAT_BLOCK";
        case VK_FORMAT_BC6H_SFLOAT_BLOCK:
            return "VK_FORMAT_BC6H_SFLOAT_BLOCK";
        case VK_FORMAT_BC7_UNORM_BLOCK:
            return "VK_FORMAT_BC7_UNORM_BLOCK";
        case VK_FORMAT_BC7_SRGB_BLOCK:
            return "VK_FORMAT_BC7_SRGB_BLOCK";
        case VK_FORMAT_ETC2_R8G8B8_UNORM_BLOCK:
            return "VK_FORMAT_ETC2_R8G8B8_UNORM_BLOCK";
        case VK_FORMAT_ETC2_R8G8B8_SRGB_BLOCK:
            return "VK_FORMAT_ETC2_R8G8B8_SRGB_BLOCK";
        case VK_FORMAT_ETC2_R8G8B8A1_UNORM_BLOCK:
            return "VK_FORMAT_ETC2_R8G8B8A1_UNORM_BLOCK";
        case VK_FORMAT_ETC2_R8G8B8A1_SRGB_BLOCK:
            return "VK_FORMAT_ETC2_R8G8B8A1_SRGB_BLOCK";
        case VK_FORMAT_ETC2_R8G8B8A8_UNORM_BLOCK:
            return "VK_FORMAT_ETC2_R8G8B8A8_UNORM_BLOCK";
        case VK_FORMAT_ETC2_R8G8B8A8_SRGB_BLOCK:
            return "VK_FORMAT_ETC2_R8G8B8A8_SRGB_BLOCK";
        case VK_FORMAT_EAC_R11_UNORM_BLOCK:
            return "VK_FORMAT_EAC_R11_UNORM_BLOCK";
        case VK_FORMAT_EAC_R11_SNORM_BLOCK:
            return "VK_FORMAT_EAC_R11_SNORM_BLOCK";
        case VK_FORMAT_EAC_R11G11_UNORM_BLOCK:
            return "VK_FORMAT_EAC_R11G11_UNORM_BLOCK";
        case VK_FORMAT_EAC_R11G11_SNORM_BLOCK:
            return "VK_FORMAT_EAC_R11G11_SNORM_BLOCK";
        case VK_FORMAT_ASTC_4x4_UNORM_BLOCK:
            return "VK_FORMAT_ASTC_4x4_UNORM_BLOCK";
        case VK_FORMAT_ASTC_4x4_SRGB_BLOCK:
            return "VK_FORMAT_ASTC_4x4_SRGB_BLOCK";
        case VK_FORMAT_ASTC_5x4_UNORM_BLOCK:
            return "VK_FORMAT_ASTC_5x4_UNORM_BLOCK";
        case VK_FORMAT_ASTC_5x4_SRGB_BLOCK:
            return "VK_FORMAT_ASTC_5x4_SRGB_BLOCK";
        case VK_FORMAT_ASTC_5x5_UNORM_BLOCK:
            return "VK_FORMAT_ASTC_5x5_UNORM_BLOCK";
        case VK_FORMAT_ASTC_5x5_SRGB_BLOCK:
            return "VK_FORMAT_ASTC_5x5_SRGB_BLOCK";
        case VK_FORMAT_ASTC_6x5_UNORM_BLOCK:
            return "VK_FORMAT_ASTC_6x5_UNORM_BLOCK";
        case VK_FORMAT_ASTC_6x5_SRGB_BLOCK:
            return "VK_FORMAT_ASTC_6x5_SRGB_BLOCK";
        case VK_FORMAT_ASTC_6x6_UNORM_BLOCK:
            return "VK_FORMAT_ASTC_6x6_UNORM_BLOCK";
        case VK_FORMAT_ASTC_6x6_SRGB_BLOCK:
            return "VK_FORMAT_ASTC_6x6_SRGB_BLOCK";
        case VK_FORMAT_ASTC_8x5_UNORM_BLOCK:
            return "VK_FORMAT_ASTC_8x5_UNORM_BLOCK";
        case VK_FORMAT_ASTC_8x5_SRGB_BLOCK:
            return "VK_FORMAT_ASTC_8x5_SRGB_BLOCK";
        case VK_FORMAT_ASTC_8x6_UNORM_BLOCK:
            return "VK_FORMAT_ASTC_8x6_UNORM_BLOCK";
        case VK_FORMAT_ASTC_8x6_SRGB_BLOCK:
            return "VK_FORMAT_ASTC_8x6_SRGB_BLOCK";
        case VK_FORMAT_ASTC_8x8_UNORM_BLOCK:
            return "VK_FORMAT_ASTC_8x8_UNORM_BLOCK";
        case VK_FORMAT_ASTC_8x8_SRGB_BLOCK:
            return "VK_FORMAT_ASTC_8x8_SRGB_BLOCK";
        case VK_FORMAT_ASTC_10x5_UNORM_BLOCK:
            return "VK_FORMAT_ASTC_10x5_UNORM_BLOCK";
        case VK_FORMAT_ASTC_10x5_SRGB_BLOCK:
            return "VK_FORMAT_ASTC_10x5_SRGB_BLOCK";
        case VK_FORMAT_ASTC_10x6_UNORM_BLOCK:
            return "VK_FORMAT_ASTC_10x6_UNORM_BLOCK";
        case VK_FORMAT_ASTC_10x6_SRGB_BLOCK:
            return "VK_FORMAT_ASTC_10x6_SRGB_BLOCK";
        case VK_FORMAT_ASTC_10x8_UNORM_BLOCK:
            return "VK_FORMAT_ASTC_10x8_UNORM_BLOCK";
        case VK_FORMAT_ASTC_10x8_SRGB_BLOCK:
            return "VK_FORMAT_ASTC_10x8_SRGB_BLOCK";
        case VK_FORMAT_ASTC_10x10_UNORM_BLOCK:
            return "VK_FORMAT_ASTC_10x10_UNORM_BLOCK";
        case VK_FORMAT_ASTC_10x10_SRGB_BLOCK:
            return "VK_FORMAT_ASTC_10x10_SRGB_BLOCK";
        case VK_FORMAT_ASTC_12x10_UNORM_BLOCK:
            return "VK_FORMAT_ASTC_12x10_UNORM_BLOCK";
        case VK_FORMAT_ASTC_12x10_SRGB_BLOCK:
            return "VK_FORMAT_ASTC_12x10_SRGB_BLOCK";
        case VK_FORMAT_ASTC_12x12_UNORM_BLOCK:
            return "VK_FORMAT_ASTC_12x12_UNORM_BLOCK";
        case VK_FORMAT_ASTC_12x12_SRGB_BLOCK:
            return "VK_FORMAT_ASTC_12x12_SRGB_BLOCK";
        case VK_FORMAT_G8B8G8R8_422_UNORM:
            return "VK_FORMAT_G8B8G8R8_422_UNORM";
        case VK_FORMAT_B8G8R8G8_422_UNORM:
            return "VK_FORMAT_B8G8R8G8_422_UNORM";
        case VK_FORMAT_G8_B8_R8_3PLANE_420_UNORM:
            return "VK_FORMAT_G8_B8_R8_3PLANE_420_UNORM";
        case VK_FORMAT_G8_B8R8_2PLANE_420_UNORM:
            return "VK_FORMAT_G8_B8R8_2PLANE_420_UNORM";
        case VK_FORMAT_G8_B8_R8_3PLANE_422_UNORM:
            return "VK_FORMAT_G8_B8_R8_3PLANE_422_UNORM";
        case VK_FORMAT_G8_B8R8_2PLANE_422_UNORM:
            return "VK_FORMAT_G8_B8R8_2PLANE_422_UNORM";
        case VK_FORMAT_G8_B8_R8_3PLANE_444_UNORM:
            return "VK_FORMAT_G8_B8_R8_3PLANE_444_UNORM";
        case VK_FORMAT_R10X6_UNORM_PACK16:
            return "VK_FORMAT_R10X6_UNORM_PACK16";
        case VK_FORMAT_R10X6G10X6_UNORM_2PACK16:
            return "VK_FORMAT_R10X6G10X6_UNORM_2PACK16";
        case VK_FORMAT_R10X6G10X6B10X6A10X6_UNORM_4PACK16:
            return "VK_FORMAT_R10X6G10X6B10X6A10X6_UNORM_4PACK16";
        case VK_FORMAT_G10X6B10X6G10X6R10X6_422_UNORM_4PACK16:
            return "VK_FORMAT_G10X6B10X6G10X6R10X6_422_UNORM_4PACK16";
        case VK_FORMAT_B10X6G10X6R10X6G10X6_422_UNORM_4PACK16:
            return "VK_FORMAT_B10X6G10X6R10X6G10X6_422_UNORM_4PACK16";
        case VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_420_UNORM_3PACK16:
            return "VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_420_UNORM_3PACK16";
        case VK_FORMAT_G10X6_B10X6R10X6_2PLANE_420_UNORM_3PACK16:
            return "VK_FORMAT_G10X6_B10X6R10X6_2PLANE_420_UNORM_3PACK16";
        case VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_422_UNORM_3PACK16:
            return "VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_422_UNORM_3PACK16";
        case VK_FORMAT_G10X6_B10X6R10X6_2PLANE_422_UNORM_3PACK16:
            return "VK_FORMAT_G10X6_B10X6R10X6_2PLANE_422_UNORM_3PACK16";
        case VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_444_UNORM_3PACK16:
            return "VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_444_UNORM_3PACK16";
        case VK_FORMAT_R12X4_UNORM_PACK16:
            return "VK_FORMAT_R12X4_UNORM_PACK16";
        case VK_FORMAT_R12X4G12X4_UNORM_2PACK16:
            return "VK_FORMAT_R12X4G12X4_UNORM_2PACK16";
        case VK_FORMAT_R12X4G12X4B12X4A12X4_UNORM_4PACK16:
            return "VK_FORMAT_R12X4G12X4B12X4A12X4_UNORM_4PACK16";
        case VK_FORMAT_G12X4B12X4G12X4R12X4_422_UNORM_4PACK16:
            return "VK_FORMAT_G12X4B12X4G12X4R12X4_422_UNORM_4PACK16";
        case VK_FORMAT_B12X4G12X4R12X4G12X4_422_UNORM_4PACK16:
            return "VK_FORMAT_B12X4G12X4R12X4G12X4_422_UNORM_4PACK16";
        case VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_420_UNORM_3PACK16:
            return "VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_420_UNORM_3PACK16";
        case VK_FORMAT_G12X4_B12X4R12X4_2PLANE_420_UNORM_3PACK16:
            return "VK_FORMAT_G12X4_B12X4R12X4_2PLANE_420_UNORM_3PACK16";
        case VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_422_UNORM_3PACK16:
            return "VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_422_UNORM_3PACK16";
        case VK_FORMAT_G12X4_B12X4R12X4_2PLANE_422_UNORM_3PACK16:
            return "VK_FORMAT_G12X4_B12X4R12X4_2PLANE_422_UNORM_3PACK16";
        case VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_444_UNORM_3PACK16:
            return "VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_444_UNORM_3PACK16";
        case VK_FORMAT_G16B16G16R16_422_UNORM:
            return "VK_FORMAT_G16B16G16R16_422_UNORM";
        case VK_FORMAT_B16G16R16G16_422_UNORM:
            return "VK_FORMAT_B16G16R16G16_422_UNORM";
        case VK_FORMAT_G16_B16_R16_3PLANE_420_UNORM:
            return "VK_FORMAT_G16_B16_R16_3PLANE_420_UNORM";
        case VK_FORMAT_G16_B16R16_2PLANE_420_UNORM:
            return "VK_FORMAT_G16_B16R16_2PLANE_420_UNORM";
        case VK_FORMAT_G16_B16_R16_3PLANE_422_UNORM:
            return "VK_FORMAT_G16_B16_R16_3PLANE_422_UNORM";
        case VK_FORMAT_G16_B16R16_2PLANE_422_UNORM:
            return "VK_FORMAT_G16_B16R16_2PLANE_422_UNORM";
        case VK_FORMAT_G16_B16_R16_3PLANE_444_UNORM:
            return "VK_FORMAT_G16_B16_R16_3PLANE_444_UNORM";
        case VK_FORMAT_G8_B8R8_2PLANE_444_UNORM:
            return "VK_FORMAT_G8_B8R8_2PLANE_444_UNORM";
        case VK_FORMAT_G10X6_B10X6R10X6_2PLANE_444_UNORM_3PACK16:
            return "VK_FORMAT_G10X6_B10X6R10X6_2PLANE_444_UNORM_3PACK16";
        case VK_FORMAT_G12X4_B12X4R12X4_2PLANE_444_UNORM_3PACK16:
            return "VK_FORMAT_G12X4_B12X4R12X4_2PLANE_444_UNORM_3PACK16";
        case VK_FORMAT_G16_B16R16_2PLANE_444_UNORM:
            return "VK_FORMAT_G16_B16R16_2PLANE_444_UNORM";
        case VK_FORMAT_A4R4G4B4_UNORM_PACK16:
            return "VK_FORMAT_A4R4G4B4_UNORM_PACK16";
        case VK_FORMAT_A4B4G4R4_UNORM_PACK16:
            return "VK_FORMAT_A4B4G4R4_UNORM_PACK16";
        case VK_FORMAT_ASTC_4x4_SFLOAT_BLOCK:
            return "VK_FORMAT_ASTC_4x4_SFLOAT_BLOCK";
        case VK_FORMAT_ASTC_5x4_SFLOAT_BLOCK:
            return "VK_FORMAT_ASTC_5x4_SFLOAT_BLOCK";
        case VK_FORMAT_ASTC_5x5_SFLOAT_BLOCK:
            return "VK_FORMAT_ASTC_5x5_SFLOAT_BLOCK";
        case VK_FORMAT_ASTC_6x5_SFLOAT_BLOCK:
            return "VK_FORMAT_ASTC_6x5_SFLOAT_BLOCK";
        case VK_FORMAT_ASTC_6x6_SFLOAT_BLOCK:
            return "VK_FORMAT_ASTC_6x6_SFLOAT_BLOCK";
        case VK_FORMAT_ASTC_8x5_SFLOAT_BLOCK:
            return "VK_FORMAT_ASTC_8x5_SFLOAT_BLOCK";
        case VK_FORMAT_ASTC_8x6_SFLOAT_BLOCK:
            return "VK_FORMAT_ASTC_8x6_SFLOAT_BLOCK";
        case VK_FORMAT_ASTC_8x8_SFLOAT_BLOCK:
            return "VK_FORMAT_ASTC_8x8_SFLOAT_BLOCK";
        case VK_FORMAT_ASTC_10x5_SFLOAT_BLOCK:
            return "VK_FORMAT_ASTC_10x5_SFLOAT_BLOCK";
        case VK_FORMAT_ASTC_10x6_SFLOAT_BLOCK:
            return "VK_FORMAT_ASTC_10x6_SFLOAT_BLOCK";
        case VK_FORMAT_ASTC_10x8_SFLOAT_BLOCK:
            return "VK_FORMAT_ASTC_10x8_SFLOAT_BLOCK";
        case VK_FORMAT_ASTC_10x10_SFLOAT_BLOCK:
            return "VK_FORMAT_ASTC_10x10_SFLOAT_BLOCK";
        case VK_FORMAT_ASTC_12x10_SFLOAT_BLOCK:
            return "VK_FORMAT_ASTC_12x10_SFLOAT_BLOCK";
        case VK_FORMAT_ASTC_12x12_SFLOAT_BLOCK:
            return "VK_FORMAT_ASTC_12x12_SFLOAT_BLOCK";
        case VK_FORMAT_A1B5G5R5_UNORM_PACK16:
            return "VK_FORMAT_A1B5G5R5_UNORM_PACK16";
        case VK_FORMAT_A8_UNORM:
            return "VK_FORMAT_A8_UNORM";
        default:
            return "VK_FORMAT_UNDEFINED";
    }
}

static VkFormat StringToFormat(const std::string &input_value) {
    static const std::unordered_map<std::string, VkFormat> map = {
        {"VK_FORMAT_UNDEFINED", VK_FORMAT_UNDEFINED},
        {"VK_FORMAT_R4G4_UNORM_PACK8", VK_FORMAT_R4G4_UNORM_PACK8},
        {"VK_FORMAT_R4G4B4A4_UNORM_PACK16", VK_FORMAT_R4G4B4A4_UNORM_PACK16},
        {"VK_FORMAT_B4G4R4A4_UNORM_PACK16", VK_FORMAT_B4G4R4A4_UNORM_PACK16},
        {"VK_FORMAT_R5G6B5_UNORM_PACK16", VK_FORMAT_R5G6B5_UNORM_PACK16},
        {"VK_FORMAT_B5G6R5_UNORM_PACK16", VK_FORMAT_B5G6R5_UNORM_PACK16},
        {"VK_FORMAT_R5G5B5A1_UNORM_PACK16", VK_FORMAT_R5G5B5A1_UNORM_PACK16},
        {"VK_FORMAT_B5G5R5A1_UNORM_PACK16", VK_FORMAT_B5G5R5A1_UNORM_PACK16},
        {"VK_FORMAT_A1R5G5B5_UNORM_PACK16", VK_FORMAT_A1R5G5B5_UNORM_PACK16},
        {"VK_FORMAT_R8_UNORM", VK_FORMAT_R8_UNORM},
        {"VK_FORMAT_R8_SNORM", VK_FORMAT_R8_SNORM},
        {"VK_FORMAT_R8_USCALED", VK_FORMAT_R8_USCALED},
        {"VK_FORMAT_R8_SSCALED", VK_FORMAT_R8_SSCALED},
        {"VK_FORMAT_R8_UINT", VK_FORMAT_R8_UINT},
        {"VK_FORMAT_R8_SINT", VK_FORMAT_R8_SINT},
        {"VK_FORMAT_R8_SRGB", VK_FORMAT_R8_SRGB},
        {"VK_FORMAT_R8G8_UNORM", VK_FORMAT_R8G8_UNORM},
        {"VK_FORMAT_R8G8_SNORM", VK_FORMAT_R8G8_SNORM},
        {"VK_FORMAT_R8G8_USCALED", VK_FORMAT_R8G8_USCALED},
        {"VK_FORMAT_R8G8_SSCALED", VK_FORMAT_R8G8_SSCALED},
        {"VK_FORMAT_R8G8_UINT", VK_FORMAT_R8G8_UINT},
        {"VK_FORMAT_R8G8_SINT", VK_FORMAT_R8G8_SINT},
        {"VK_FORMAT_R8G8_SRGB", VK_FORMAT_R8G8_SRGB},
        {"VK_FORMAT_R8G8B8_UNORM", VK_FORMAT_R8G8B8_UNORM},
        {"VK_FORMAT_R8G8B8_SNORM", VK_FORMAT_R8G8B8_SNORM},
        {"VK_FORMAT_R8G8B8_USCALED", VK_FORMAT_R8G8B8_USCALED},
        {"VK_FORMAT_R8G8B8_SSCALED", VK_FORMAT_R8G8B8_SSCALED},
        {"VK_FORMAT_R8G8B8_UINT", VK_FORMAT_R8G8B8_UINT},
        {"VK_FORMAT_R8G8B8_SINT", VK_FORMAT_R8G8B8_SINT},
        {"VK_FORMAT_R8G8B8_SRGB", VK_FORMAT_R8G8B8_SRGB},
        {"VK_FORMAT_B8G8R8_UNORM", VK_FORMAT_B8G8R8_UNORM},
        {"VK_FORMAT_B8G8R8_SNORM", VK_FORMAT_B8G8R8_SNORM},
        {"VK_FORMAT_B8G8R8_USCALED", VK_FORMAT_B8G8R8_USCALED},
        {"VK_FORMAT_B8G8R8_SSCALED", VK_FORMAT_B8G8R8_SSCALED},
        {"VK_FORMAT_B8G8R8_UINT", VK_FORMAT_B8G8R8_UINT},
        {"VK_FORMAT_B8G8R8_SINT", VK_FORMAT_B8G8R8_SINT},
        {"VK_FORMAT_B8G8R8_SRGB", VK_FORMAT_B8G8R8_SRGB},
        {"VK_FORMAT_R8G8B8A8_UNORM", VK_FORMAT_R8G8B8A8_UNORM},
        {"VK_FORMAT_R8G8B8A8_SNORM", VK_FORMAT_R8G8B8A8_SNORM},
        {"VK_FORMAT_R8G8B8A8_USCALED", VK_FORMAT_R8G8B8A8_USCALED},
        {"VK_FORMAT_R8G8B8A8_SSCALED", VK_FORMAT_R8G8B8A8_SSCALED},
        {"VK_FORMAT_R8G8B8A8_UINT", VK_FORMAT_R8G8B8A8_UINT},
        {"VK_FORMAT_R8G8B8A8_SINT", VK_FORMAT_R8G8B8A8_SINT},
        {"VK_FORMAT_R8G8B8A8_SRGB", VK_FORMAT_R8G8B8A8_SRGB},
        {"VK_FORMAT_B8G8R8A8_UNORM", VK_FORMAT_B8G8R8A8_UNORM},
        {"VK_FORMAT_B8G8R8A8_SNORM", VK_FORMAT_B8G8R8A8_SNORM},
        {"VK_FORMAT_B8G8R8A8_USCALED", VK_FORMAT_B8G8R8A8_USCALED},
        {"VK_FORMAT_B8G8R8A8_SSCALED", VK_FORMAT_B8G8R8A8_SSCALED},
        {"VK_FORMAT_B8G8R8A8_UINT", VK_FORMAT_B8G8R8A8_UINT},
        {"VK_FORMAT_B8G8R8A8_SINT", VK_FORMAT_B8G8R8A8_SINT},
        {"VK_FORMAT_B8G8R8A8_SRGB", VK_FORMAT_B8G8R8A8_SRGB},
        {"VK_FORMAT_A8B8G8R8_UNORM_PACK32", VK_FORMAT_A8B8G8R8_UNORM_PACK32},
        {"VK_FORMAT_A8B8G8R8_SNORM_PACK32", VK_FORMAT_A8B8G8R8_SNORM_PACK32},
        {"VK_FORMAT_A8B8G8R8_USCALED_PACK32", VK_FORMAT_A8B8G8R8_USCALED_PACK32},
        {"VK_FORMAT_A8B8G8R8_SSCALED_PACK32", VK_FORMAT_A8B8G8R8_SSCALED_PACK32},
        {"VK_FORMAT_A8B8G8R8_UINT_PACK32", VK_FORMAT_A8B8G8R8_UINT_PACK32},
        {"VK_FORMAT_A8B8G8R8_SINT_PACK32", VK_FORMAT_A8B8G8R8_SINT_PACK32},
        {"VK_FORMAT_A8B8G8R8_SRGB_PACK32", VK_FORMAT_A8B8G8R8_SRGB_PACK32},
        {"VK_FORMAT_A2R10G10B10_UNORM_PACK32", VK_FORMAT_A2R10G10B10_UNORM_PACK32},
        {"VK_FORMAT_A2R10G10B10_SNORM_PACK32", VK_FORMAT_A2R10G10B10_SNORM_PACK32},
        {"VK_FORMAT_A2R10G10B10_USCALED_PACK32", VK_FORMAT_A2R10G10B10_USCALED_PACK32},
        {"VK_FORMAT_A2R10G10B10_SSCALED_PACK32", VK_FORMAT_A2R10G10B10_SSCALED_PACK32},
        {"VK_FORMAT_A2R10G10B10_UINT_PACK32", VK_FORMAT_A2R10G10B10_UINT_PACK32},
        {"VK_FORMAT_A2R10G10B10_SINT_PACK32", VK_FORMAT_A2R10G10B10_SINT_PACK32},
        {"VK_FORMAT_A2B10G10R10_UNORM_PACK32", VK_FORMAT_A2B10G10R10_UNORM_PACK32},
        {"VK_FORMAT_A2B10G10R10_SNORM_PACK32", VK_FORMAT_A2B10G10R10_SNORM_PACK32},
        {"VK_FORMAT_A2B10G10R10_USCALED_PACK32", VK_FORMAT_A2B10G10R10_USCALED_PACK32},
        {"VK_FORMAT_A2B10G10R10_SSCALED_PACK32", VK_FORMAT_A2B10G10R10_SSCALED_PACK32},
        {"VK_FORMAT_A2B10G10R10_UINT_PACK32", VK_FORMAT_A2B10G10R10_UINT_PACK32},
        {"VK_FORMAT_A2B10G10R10_SINT_PACK32", VK_FORMAT_A2B10G10R10_SINT_PACK32},
        {"VK_FORMAT_R16_UNORM", VK_FORMAT_R16_UNORM},
        {"VK_FORMAT_R16_SNORM", VK_FORMAT_R16_SNORM},
        {"VK_FORMAT_R16_USCALED", VK_FORMAT_R16_USCALED},
        {"VK_FORMAT_R16_SSCALED", VK_FORMAT_R16_SSCALED},
        {"VK_FORMAT_R16_UINT", VK_FORMAT_R16_UINT},
        {"VK_FORMAT_R16_SINT", VK_FORMAT_R16_SINT},
        {"VK_FORMAT_R16_SFLOAT", VK_FORMAT_R16_SFLOAT},
        {"VK_FORMAT_R16G16_UNORM", VK_FORMAT_R16G16_UNORM},
        {"VK_FORMAT_R16G16_SNORM", VK_FORMAT_R16G16_SNORM},
        {"VK_FORMAT_R16G16_USCALED", VK_FORMAT_R16G16_USCALED},
        {"VK_FORMAT_R16G16_SSCALED", VK_FORMAT_R16G16_SSCALED},
        {"VK_FORMAT_R16G16_UINT", VK_FORMAT_R16G16_UINT},
        {"VK_FORMAT_R16G16_SINT", VK_FORMAT_R16G16_SINT},
        {"VK_FORMAT_R16G16_SFLOAT", VK_FORMAT_R16G16_SFLOAT},
        {"VK_FORMAT_R16G16B16_UNORM", VK_FORMAT_R16G16B16_UNORM},
        {"VK_FORMAT_R16G16B16_SNORM", VK_FORMAT_R16G16B16_SNORM},
        {"VK_FORMAT_R16G16B16_USCALED", VK_FORMAT_R16G16B16_USCALED},
        {"VK_FORMAT_R16G16B16_SSCALED", VK_FORMAT_R16G16B16_SSCALED},
        {"VK_FORMAT_R16G16B16_UINT", VK_FORMAT_R16G16B16_UINT},
        {"VK_FORMAT_R16G16B16_SINT", VK_FORMAT_R16G16B16_SINT},
        {"VK_FORMAT_R16G16B16_SFLOAT", VK_FORMAT_R16G16B16_SFLOAT},
        {"VK_FORMAT_R16G16B16A16_UNORM", VK_FORMAT_R16G16B16A16_UNORM},
        {"VK_FORMAT_R16G16B16A16_SNORM", VK_FORMAT_R16G16B16A16_SNORM},
        {"VK_FORMAT_R16G16B16A16_USCALED", VK_FORMAT_R16G16B16A16_USCALED},
        {"VK_FORMAT_R16G16B16A16_SSCALED", VK_FORMAT_R16G16B16A16_SSCALED},
        {"VK_FORMAT_R16G16B16A16_UINT", VK_FORMAT_R16G16B16A16_UINT},
        {"VK_FORMAT_R16G16B16A16_SINT", VK_FORMAT_R16G16B16A16_SINT},
        {"VK_FORMAT_R16G16B16A16_SFLOAT", VK_FORMAT_R16G16B16A16_SFLOAT},
        {"VK_FORMAT_R32_UINT", VK_FORMAT_R32_UINT},
        {"VK_FORMAT_R32_SINT", VK_FORMAT_R32_SINT},
        {"VK_FORMAT_R32_SFLOAT", VK_FORMAT_R32_SFLOAT},
        {"VK_FORMAT_R32G32_UINT", VK_FORMAT_R32G32_UINT},
        {"VK_FORMAT_R32G32_SINT", VK_FORMAT_R32G32_SINT},
        {"VK_FORMAT_R32G32_SFLOAT", VK_FORMAT_R32G32_SFLOAT},
        {"VK_FORMAT_R32G32B32_UINT", VK_FORMAT_R32G32B32_UINT},
        {"VK_FORMAT_R32G32B32_SINT", VK_FORMAT_R32G32B32_SINT},
        {"VK_FORMAT_R32G32B32_SFLOAT", VK_FORMAT_R32G32B32_SFLOAT},
        {"VK_FORMAT_R32G32B32A32_UINT", VK_FORMAT_R32G32B32A32_UINT},
        {"VK_FORMAT_R32G32B32A32_SINT", VK_FORMAT_R32G32B32A32_SINT},
        {"VK_FORMAT_R32G32B32A32_SFLOAT", VK_FORMAT_R32G32B32A32_SFLOAT},
        {"VK_FORMAT_R64_UINT", VK_FORMAT_R64_UINT},
        {"VK_FORMAT_R64_SINT", VK_FORMAT_R64_SINT},
        {"VK_FORMAT_R64_SFLOAT", VK_FORMAT_R64_SFLOAT},
        {"VK_FORMAT_R64G64_UINT", VK_FORMAT_R64G64_UINT},
        {"VK_FORMAT_R64G64_SINT", VK_FORMAT_R64G64_SINT},
        {"VK_FORMAT_R64G64_SFLOAT", VK_FORMAT_R64G64_SFLOAT},
        {"VK_FORMAT_R64G64B64_UINT", VK_FORMAT_R64G64B64_UINT},
        {"VK_FORMAT_R64G64B64_SINT", VK_FORMAT_R64G64B64_SINT},
        {"VK_FORMAT_R64G64B64_SFLOAT", VK_FORMAT_R64G64B64_SFLOAT},
        {"VK_FORMAT_R64G64B64A64_UINT", VK_FORMAT_R64G64B64A64_UINT},
        {"VK_FORMAT_R64G64B64A64_SINT", VK_FORMAT_R64G64B64A64_SINT},
        {"VK_FORMAT_R64G64B64A64_SFLOAT", VK_FORMAT_R64G64B64A64_SFLOAT},
        {"VK_FORMAT_B10G11R11_UFLOAT_PACK32", VK_FORMAT_B10G11R11_UFLOAT_PACK32},
        {"VK_FORMAT_E5B9G9R9_UFLOAT_PACK32", VK_FORMAT_E5B9G9R9_UFLOAT_PACK32},
        {"VK_FORMAT_D16_UNORM", VK_FORMAT_D16_UNORM},
        {"VK_FORMAT_X8_D24_UNORM_PACK32", VK_FORMAT_X8_D24_UNORM_PACK32},
        {"VK_FORMAT_D32_SFLOAT", VK_FORMAT_D32_SFLOAT},
        {"VK_FORMAT_S8_UINT", VK_FORMAT_S8_UINT},
        {"VK_FORMAT_D16_UNORM_S8_UINT", VK_FORMAT_D16_UNORM_S8_UINT},
        {"VK_FORMAT_D24_UNORM_S8_UINT", VK_FORMAT_D24_UNORM_S8_UINT},
        {"VK_FORMAT_D32_SFLOAT_S8_UINT", VK_FORMAT_D32_SFLOAT_S8_UINT},
        {"VK_FORMAT_BC1_RGB_UNORM_BLOCK", VK_FORMAT_BC1_RGB_UNORM_BLOCK},
        {"VK_FORMAT_BC1_RGB_SRGB_BLOCK", VK_FORMAT_BC1_RGB_SRGB_BLOCK},
        {"VK_FORMAT_BC1_RGBA_UNORM_BLOCK", VK_FORMAT_BC1_RGBA_UNORM_BLOCK},
        {"VK_FORMAT_BC1_RGBA_SRGB_BLOCK", VK_FORMAT_BC1_RGBA_SRGB_BLOCK},
        {"VK_FORMAT_BC2_UNORM_BLOCK", VK_FORMAT_BC2_UNORM_BLOCK},
        {"VK_FORMAT_BC2_SRGB_BLOCK", VK_FORMAT_BC2_SRGB_BLOCK},
        {"VK_FORMAT_BC3_UNORM_BLOCK", VK_FORMAT_BC3_UNORM_BLOCK},
        {"VK_FORMAT_BC3_SRGB_BLOCK", VK_FORMAT_BC3_SRGB_BLOCK},
        {"VK_FORMAT_BC4_UNORM_BLOCK", VK_FORMAT_BC4_UNORM_BLOCK},
        {"VK_FORMAT_BC4_SNORM_BLOCK", VK_FORMAT_BC4_SNORM_BLOCK},
        {"VK_FORMAT_BC5_UNORM_BLOCK", VK_FORMAT_BC5_UNORM_BLOCK},
        {"VK_FORMAT_BC5_SNORM_BLOCK", VK_FORMAT_BC5_SNORM_BLOCK},
        {"VK_FORMAT_BC6H_UFLOAT_BLOCK", VK_FORMAT_BC6H_UFLOAT_BLOCK},
        {"VK_FORMAT_BC6H_SFLOAT_BLOCK", VK_FORMAT_BC6H_SFLOAT_BLOCK},
        {"VK_FORMAT_BC7_UNORM_BLOCK", VK_FORMAT_BC7_UNORM_BLOCK},
        {"VK_FORMAT_BC7_SRGB_BLOCK", VK_FORMAT_BC7_SRGB_BLOCK},
        {"VK_FORMAT_ETC2_R8G8B8_UNORM_BLOCK", VK_FORMAT_ETC2_R8G8B8_UNORM_BLOCK},
        {"VK_FORMAT_ETC2_R8G8B8_SRGB_BLOCK", VK_FORMAT_ETC2_R8G8B8_SRGB_BLOCK},
        {"VK_FORMAT_ETC2_R8G8B8A1_UNORM_BLOCK", VK_FORMAT_ETC2_R8G8B8A1_UNORM_BLOCK},
        {"VK_FORMAT_ETC2_R8G8B8A1_SRGB_BLOCK", VK_FORMAT_ETC2_R8G8B8A1_SRGB_BLOCK},
        {"VK_FORMAT_ETC2_R8G8B8A8_UNORM_BLOCK", VK_FORMAT_ETC2_R8G8B8A8_UNORM_BLOCK},
        {"VK_FORMAT_ETC2_R8G8B8A8_SRGB_BLOCK", VK_FORMAT_ETC2_R8G8B8A8_SRGB_BLOCK},
        {"VK_FORMAT_EAC_R11_UNORM_BLOCK", VK_FORMAT_EAC_R11_UNORM_BLOCK},
        {"VK_FORMAT_EAC_R11_SNORM_BLOCK", VK_FORMAT_EAC_R11_SNORM_BLOCK},
        {"VK_FORMAT_EAC_R11G11_UNORM_BLOCK", VK_FORMAT_EAC_R11G11_UNORM_BLOCK},
        {"VK_FORMAT_EAC_R11G11_SNORM_BLOCK", VK_FORMAT_EAC_R11G11_SNORM_BLOCK},
        {"VK_FORMAT_ASTC_4x4_UNORM_BLOCK", VK_FORMAT_ASTC_4x4_UNORM_BLOCK},
        {"VK_FORMAT_ASTC_4x4_SRGB_BLOCK", VK_FORMAT_ASTC_4x4_SRGB_BLOCK},
        {"VK_FORMAT_ASTC_5x4_UNORM_BLOCK", VK_FORMAT_ASTC_5x4_UNORM_BLOCK},
        {"VK_FORMAT_ASTC_5x4_SRGB_BLOCK", VK_FORMAT_ASTC_5x4_SRGB_BLOCK},
        {"VK_FORMAT_ASTC_5x5_UNORM_BLOCK", VK_FORMAT_ASTC_5x5_UNORM_BLOCK},
        {"VK_FORMAT_ASTC_5x5_SRGB_BLOCK", VK_FORMAT_ASTC_5x5_SRGB_BLOCK},
        {"VK_FORMAT_ASTC_6x5_UNORM_BLOCK", VK_FORMAT_ASTC_6x5_UNORM_BLOCK},
        {"VK_FORMAT_ASTC_6x5_SRGB_BLOCK", VK_FORMAT_ASTC_6x5_SRGB_BLOCK},
        {"VK_FORMAT_ASTC_6x6_UNORM_BLOCK", VK_FORMAT_ASTC_6x6_UNORM_BLOCK},
        {"VK_FORMAT_ASTC_6x6_SRGB_BLOCK", VK_FORMAT_ASTC_6x6_SRGB_BLOCK},
        {"VK_FORMAT_ASTC_8x5_UNORM_BLOCK", VK_FORMAT_ASTC_8x5_UNORM_BLOCK},
        {"VK_FORMAT_ASTC_8x5_SRGB_BLOCK", VK_FORMAT_ASTC_8x5_SRGB_BLOCK},
        {"VK_FORMAT_ASTC_8x6_UNORM_BLOCK", VK_FORMAT_ASTC_8x6_UNORM_BLOCK},
        {"VK_FORMAT_ASTC_8x6_SRGB_BLOCK", VK_FORMAT_ASTC_8x6_SRGB_BLOCK},
        {"VK_FORMAT_ASTC_8x8_UNORM_BLOCK", VK_FORMAT_ASTC_8x8_UNORM_BLOCK},
        {"VK_FORMAT_ASTC_8x8_SRGB_BLOCK", VK_FORMAT_ASTC_8x8_SRGB_BLOCK},
        {"VK_FORMAT_ASTC_10x5_UNORM_BLOCK", VK_FORMAT_ASTC_10x5_UNORM_BLOCK},
        {"VK_FORMAT_ASTC_10x5_SRGB_BLOCK", VK_FORMAT_ASTC_10x5_SRGB_BLOCK},
        {"VK_FORMAT_ASTC_10x6_UNORM_BLOCK", VK_FORMAT_ASTC_10x6_UNORM_BLOCK},
        {"VK_FORMAT_ASTC_10x6_SRGB_BLOCK", VK_FORMAT_ASTC_10x6_SRGB_BLOCK},
        {"VK_FORMAT_ASTC_10x8_UNORM_BLOCK", VK_FORMAT_ASTC_10x8_UNORM_BLOCK},
        {"VK_FORMAT_ASTC_10x8_SRGB_BLOCK", VK_FORMAT_ASTC_10x8_SRGB_BLOCK},
        {"VK_FORMAT_ASTC_10x10_UNORM_BLOCK", VK_FORMAT_ASTC_10x10_UNORM_BLOCK},
        {"VK_FORMAT_ASTC_10x10_SRGB_BLOCK", VK_FORMAT_ASTC_10x10_SRGB_BLOCK},
        {"VK_FORMAT_ASTC_12x10_UNORM_BLOCK", VK_FORMAT_ASTC_12x10_UNORM_BLOCK},
        {"VK_FORMAT_ASTC_12x10_SRGB_BLOCK", VK_FORMAT_ASTC_12x10_SRGB_BLOCK},
        {"VK_FORMAT_ASTC_12x12_UNORM_BLOCK", VK_FORMAT_ASTC_12x12_UNORM_BLOCK},
        {"VK_FORMAT_ASTC_12x12_SRGB_BLOCK", VK_FORMAT_ASTC_12x12_SRGB_BLOCK},
        {"VK_FORMAT_G8B8G8R8_422_UNORM", VK_FORMAT_G8B8G8R8_422_UNORM},
        {"VK_FORMAT_B8G8R8G8_422_UNORM", VK_FORMAT_B8G8R8G8_422_UNORM},
        {"VK_FORMAT_G8_B8_R8_3PLANE_420_UNORM", VK_FORMAT_G8_B8_R8_3PLANE_420_UNORM},
        {"VK_FORMAT_G8_B8R8_2PLANE_420_UNORM", VK_FORMAT_G8_B8R8_2PLANE_420_UNORM},
        {"VK_FORMAT_G8_B8_R8_3PLANE_422_UNORM", VK_FORMAT_G8_B8_R8_3PLANE_422_UNORM},
        {"VK_FORMAT_G8_B8R8_2PLANE_422_UNORM", VK_FORMAT_G8_B8R8_2PLANE_422_UNORM},
        {"VK_FORMAT_G8_B8_R8_3PLANE_444_UNORM", VK_FORMAT_G8_B8_R8_3PLANE_444_UNORM},
        {"VK_FORMAT_R10X6_UNORM_PACK16", VK_FORMAT_R10X6_UNORM_PACK16},
        {"VK_FORMAT_R10X6G10X6_UNORM_2PACK16", VK_FORMAT_R10X6G10X6_UNORM_2PACK16},
        {"VK_FORMAT_R10X6G10X6B10X6A10X6_UNORM_4PACK16", VK_FORMAT_R10X6G10X6B10X6A10X6_UNORM_4PACK16},
        {"VK_FORMAT_G10X6B10X6G10X6R10X6_422_UNORM_4PACK16", VK_FORMAT_G10X6B10X6G10X6R10X6_422_UNORM_4PACK16},
        {"VK_FORMAT_B10X6G10X6R10X6G10X6_422_UNORM_4PACK16", VK_FORMAT_B10X6G10X6R10X6G10X6_422_UNORM_4PACK16},
        {"VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_420_UNORM_3PACK16", VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_420_UNORM_3PACK16},
        {"VK_FORMAT_G10X6_B10X6R10X6_2PLANE_420_UNORM_3PACK16", VK_FORMAT_G10X6_B10X6R10X6_2PLANE_420_UNORM_3PACK16},
        {"VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_422_UNORM_3PACK16", VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_422_UNORM_3PACK16},
        {"VK_FORMAT_G10X6_B10X6R10X6_2PLANE_422_UNORM_3PACK16", VK_FORMAT_G10X6_B10X6R10X6_2PLANE_422_UNORM_3PACK16},
        {"VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_444_UNORM_3PACK16", VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_444_UNORM_3PACK16},
        {"VK_FORMAT_R12X4_UNORM_PACK16", VK_FORMAT_R12X4_UNORM_PACK16},
        {"VK_FORMAT_R12X4G12X4_UNORM_2PACK16", VK_FORMAT_R12X4G12X4_UNORM_2PACK16},
        {"VK_FORMAT_R12X4G12X4B12X4A12X4_UNORM_4PACK16", VK_FORMAT_R12X4G12X4B12X4A12X4_UNORM_4PACK16},
        {"VK_FORMAT_G12X4B12X4G12X4R12X4_422_UNORM_4PACK16", VK_FORMAT_G12X4B12X4G12X4R12X4_422_UNORM_4PACK16},
        {"VK_FORMAT_B12X4G12X4R12X4G12X4_422_UNORM_4PACK16", VK_FORMAT_B12X4G12X4R12X4G12X4_422_UNORM_4PACK16},
        {"VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_420_UNORM_3PACK16", VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_420_UNORM_3PACK16},
        {"VK_FORMAT_G12X4_B12X4R12X4_2PLANE_420_UNORM_3PACK16", VK_FORMAT_G12X4_B12X4R12X4_2PLANE_420_UNORM_3PACK16},
        {"VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_422_UNORM_3PACK16", VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_422_UNORM_3PACK16},
        {"VK_FORMAT_G12X4_B12X4R12X4_2PLANE_422_UNORM_3PACK16", VK_FORMAT_G12X4_B12X4R12X4_2PLANE_422_UNORM_3PACK16},
        {"VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_444_UNORM_3PACK16", VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_444_UNORM_3PACK16},
        {"VK_FORMAT_G16B16G16R16_422_UNORM", VK_FORMAT_G16B16G16R16_422_UNORM},
        {"VK_FORMAT_B16G16R16G16_422_UNORM", VK_FORMAT_B16G16R16G16_422_UNORM},
        {"VK_FORMAT_G16_B16_R16_3PLANE_420_UNORM", VK_FORMAT_G16_B16_R16_3PLANE_420_UNORM},
        {"VK_FORMAT_G16_B16R16_2PLANE_420_UNORM", VK_FORMAT_G16_B16R16_2PLANE_420_UNORM},
        {"VK_FORMAT_G16_B16_R16_3PLANE_422_UNORM", VK_FORMAT_G16_B16_R16_3PLANE_422_UNORM},
        {"VK_FORMAT_G16_B16R16_2PLANE_422_UNORM", VK_FORMAT_G16_B16R16_2PLANE_422_UNORM},
        {"VK_FORMAT_G16_B16_R16_3PLANE_444_UNORM", VK_FORMAT_G16_B16_R16_3PLANE_444_UNORM},
        {"VK_FORMAT_G8_B8R8_2PLANE_444_UNORM", VK_FORMAT_G8_B8R8_2PLANE_444_UNORM},
        {"VK_FORMAT_G10X6_B10X6R10X6_2PLANE_444_UNORM_3PACK16", VK_FORMAT_G10X6_B10X6R10X6_2PLANE_444_UNORM_3PACK16},
        {"VK_FORMAT_G12X4_B12X4R12X4_2PLANE_444_UNORM_3PACK16", VK_FORMAT_G12X4_B12X4R12X4_2PLANE_444_UNORM_3PACK16},
        {"VK_FORMAT_G16_B16R16_2PLANE_444_UNORM", VK_FORMAT_G16_B16R16_2PLANE_444_UNORM},
        {"VK_FORMAT_A4R4G4B4_UNORM_PACK16", VK_FORMAT_A4R4G4B4_UNORM_PACK16},
        {"VK_FORMAT_A4B4G4R4_UNORM_PACK16", VK_FORMAT_A4B4G4R4_UNORM_PACK16},
        {"VK_FORMAT_ASTC_4x4_SFLOAT_BLOCK", VK_FORMAT_ASTC_4x4_SFLOAT_BLOCK},
        {"VK_FORMAT_ASTC_5x4_SFLOAT_BLOCK", VK_FORMAT_ASTC_5x4_SFLOAT_BLOCK},
        {"VK_FORMAT_ASTC_5x5_SFLOAT_BLOCK", VK_FORMAT_ASTC_5x5_SFLOAT_BLOCK},
        {"VK_FORMAT_ASTC_6x5_SFLOAT_BLOCK", VK_FORMAT_ASTC_6x5_SFLOAT_BLOCK},
        {"VK_FORMAT_ASTC_6x6_SFLOAT_BLOCK", VK_FORMAT_ASTC_6x6_SFLOAT_BLOCK},
        {"VK_FORMAT_ASTC_8x5_SFLOAT_BLOCK", VK_FORMAT_ASTC_8x5_SFLOAT_BLOCK},
        {"VK_FORMAT_ASTC_8x6_SFLOAT_BLOCK", VK_FORMAT_ASTC_8x6_SFLOAT_BLOCK},
        {"VK_FORMAT_ASTC_8x8_SFLOAT_BLOCK", VK_FORMAT_ASTC_8x8_SFLOAT_BLOCK},
        {"VK_FORMAT_ASTC_10x5_SFLOAT_BLOCK", VK_FORMAT_ASTC_10x5_SFLOAT_BLOCK},
        {"VK_FORMAT_ASTC_10x6_SFLOAT_BLOCK", VK_FORMAT_ASTC_10x6_SFLOAT_BLOCK},
        {"VK_FORMAT_ASTC_10x8_SFLOAT_BLOCK", VK_FORMAT_ASTC_10x8_SFLOAT_BLOCK},
        {"VK_FORMAT_ASTC_10x10_SFLOAT_BLOCK", VK_FORMAT_ASTC_10x10_SFLOAT_BLOCK},
        {"VK_FORMAT_ASTC_12x10_SFLOAT_BLOCK", VK_FORMAT_ASTC_12x10_SFLOAT_BLOCK},
        {"VK_FORMAT_ASTC_12x12_SFLOAT_BLOCK", VK_FORMAT_ASTC_12x12_SFLOAT_BLOCK},
        {"VK_FORMAT_A1B5G5R5_UNORM_PACK16", VK_FORMAT_A1B5G5R5_UNORM_PACK16},
        {"VK_FORMAT_A8_UNORM", VK_FORMAT_A8_UNORM},
        {"VK_FORMAT_ASTC_4x4_SFLOAT_BLOCK_EXT", VK_FORMAT_ASTC_4x4_SFLOAT_BLOCK_EXT},
        {"VK_FORMAT_ASTC_5x4_SFLOAT_BLOCK_EXT", VK_FORMAT_ASTC_5x4_SFLOAT_BLOCK_EXT},
        {"VK_FORMAT_ASTC_5x5_SFLOAT_BLOCK_EXT", VK_FORMAT_ASTC_5x5_SFLOAT_BLOCK_EXT},
        {"VK_FORMAT_ASTC_6x5_SFLOAT_BLOCK_EXT", VK_FORMAT_ASTC_6x5_SFLOAT_BLOCK_EXT},
        {"VK_FORMAT_ASTC_6x6_SFLOAT_BLOCK_EXT", VK_FORMAT_ASTC_6x6_SFLOAT_BLOCK_EXT},
        {"VK_FORMAT_ASTC_8x5_SFLOAT_BLOCK_EXT", VK_FORMAT_ASTC_8x5_SFLOAT_BLOCK_EXT},
        {"VK_FORMAT_ASTC_8x6_SFLOAT_BLOCK_EXT", VK_FORMAT_ASTC_8x6_SFLOAT_BLOCK_EXT},
        {"VK_FORMAT_ASTC_8x8_SFLOAT_BLOCK_EXT", VK_FORMAT_ASTC_8x8_SFLOAT_BLOCK_EXT},
        {"VK_FORMAT_ASTC_10x5_SFLOAT_BLOCK_EXT", VK_FORMAT_ASTC_10x5_SFLOAT_BLOCK_EXT},
        {"VK_FORMAT_ASTC_10x6_SFLOAT_BLOCK_EXT", VK_FORMAT_ASTC_10x6_SFLOAT_BLOCK_EXT},
        {"VK_FORMAT_ASTC_10x8_SFLOAT_BLOCK_EXT", VK_FORMAT_ASTC_10x8_SFLOAT_BLOCK_EXT},
        {"VK_FORMAT_ASTC_10x10_SFLOAT_BLOCK_EXT", VK_FORMAT_ASTC_10x10_SFLOAT_BLOCK_EXT},
        {"VK_FORMAT_ASTC_12x10_SFLOAT_BLOCK_EXT", VK_FORMAT_ASTC_12x10_SFLOAT_BLOCK_EXT},
        {"VK_FORMAT_ASTC_12x12_SFLOAT_BLOCK_EXT", VK_FORMAT_ASTC_12x12_SFLOAT_BLOCK_EXT},
        {"VK_FORMAT_G8_B8R8_2PLANE_444_UNORM_EXT", VK_FORMAT_G8_B8R8_2PLANE_444_UNORM_EXT},
        {"VK_FORMAT_G10X6_B10X6R10X6_2PLANE_444_UNORM_3PACK16_EXT", VK_FORMAT_G10X6_B10X6R10X6_2PLANE_444_UNORM_3PACK16_EXT},
        {"VK_FORMAT_G12X4_B12X4R12X4_2PLANE_444_UNORM_3PACK16_EXT", VK_FORMAT_G12X4_B12X4R12X4_2PLANE_444_UNORM_3PACK16_EXT},
        {"VK_FORMAT_G16_B16R16_2PLANE_444_UNORM_EXT", VK_FORMAT_G16_B16R16_2PLANE_444_UNORM_EXT},
        {"VK_FORMAT_A4R4G4B4_UNORM_PACK16_EXT", VK_FORMAT_A4R4G4B4_UNORM_PACK16_EXT},
        {"VK_FORMAT_A4B4G4R4_UNORM_PACK16_EXT", VK_FORMAT_A4B4G4R4_UNORM_PACK16_EXT},
    };
    const auto it = map.find(input_value);
    if (it != map.end()) {
        return it->second;
    }
    return VK_FORMAT_UNDEFINED;
}

static VkImageLayout StringToImageLayout(const std::string &input_value) {
    static const std::unordered_map<std::string, VkImageLayout> map = {
        {"VK_IMAGE_LAYOUT_UNDEFINED", VK_IMAGE_LAYOUT_UNDEFINED},
        {"VK_IMAGE_LAYOUT_GENERAL", VK_IMAGE_LAYOUT_GENERAL},
        {"VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL", VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL},
        {"VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL", VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL},
        {"VK_IMAGE_LAYOUT_DEPTH_STENCIL_READ_ONLY_OPTIMAL", VK_IMAGE_LAYOUT_DEPTH_STENCIL_READ_ONLY_OPTIMAL},
        {"VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL", VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL},
        {"VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL", VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL},
        {"VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL", VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL},
        {"VK_IMAGE_LAYOUT_PREINITIALIZED", VK_IMAGE_LAYOUT_PREINITIALIZED},
        {"VK_IMAGE_LAYOUT_DEPTH_READ_ONLY_STENCIL_ATTACHMENT_OPTIMAL", VK_IMAGE_LAYOUT_DEPTH_READ_ONLY_STENCIL_ATTACHMENT_OPTIMAL},
        {"VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_STENCIL_READ_ONLY_OPTIMAL", VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_STENCIL_READ_ONLY_OPTIMAL},
        {"VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_OPTIMAL", VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_OPTIMAL},
        {"VK_IMAGE_LAYOUT_DEPTH_READ_ONLY_OPTIMAL", VK_IMAGE_LAYOUT_DEPTH_READ_ONLY_OPTIMAL},
        {"VK_IMAGE_LAYOUT_STENCIL_ATTACHMENT_OPTIMAL", VK_IMAGE_LAYOUT_STENCIL_ATTACHMENT_OPTIMAL},
        {"VK_IMAGE_LAYOUT_STENCIL_READ_ONLY_OPTIMAL", VK_IMAGE_LAYOUT_STENCIL_READ_ONLY_OPTIMAL},
        {"VK_IMAGE_LAYOUT_READ_ONLY_OPTIMAL", VK_IMAGE_LAYOUT_READ_ONLY_OPTIMAL},
        {"VK_IMAGE_LAYOUT_ATTACHMENT_OPTIMAL", VK_IMAGE_LAYOUT_ATTACHMENT_OPTIMAL},
        {"VK_IMAGE_LAYOUT_RENDERING_LOCAL_READ", VK_IMAGE_LAYOUT_RENDERING_LOCAL_READ},
        {"VK_IMAGE_LAYOUT_PRESENT_SRC_KHR", VK_IMAGE_LAYOUT_PRESENT_SRC_KHR},
        {"VK_IMAGE_LAYOUT_SHARED_PRESENT_KHR", VK_IMAGE_LAYOUT_SHARED_PRESENT_KHR},
        {"VK_IMAGE_LAYOUT_FRAGMENT_SHADING_RATE_ATTACHMENT_OPTIMAL_KHR", VK_IMAGE_LAYOUT_FRAGMENT_SHADING_RATE_ATTACHMENT_OPTIMAL_KHR},
        {"VK_IMAGE_LAYOUT_READ_ONLY_OPTIMAL_KHR", VK_IMAGE_LAYOUT_READ_ONLY_OPTIMAL_KHR},
        {"VK_IMAGE_LAYOUT_ATTACHMENT_OPTIMAL_KHR", VK_IMAGE_LAYOUT_ATTACHMENT_OPTIMAL_KHR},
    };
    const auto it = map.find(input_value);
    if (it != map.end()) {
        return it->second;
    }
    return VK_IMAGE_LAYOUT_UNDEFINED;
}

static uint64_t VkStringToUint64(const std::string &input_value) {
    static const std::unordered_map<std::string, uint64_t> map = {
        // VkShaderStageFlagBits
        {"VK_SHADER_STAGE_VERTEX_BIT", static_cast<uint64_t>(VK_SHADER_STAGE_VERTEX_BIT)},
        {"VK_SHADER_STAGE_TESSELLATION_CONTROL_BIT", static_cast<uint64_t>(VK_SHADER_STAGE_TESSELLATION_CONTROL_BIT)},
        {"VK_SHADER_STAGE_TESSELLATION_EVALUATION_BIT", static_cast<uint64_t>(VK_SHADER_STAGE_TESSELLATION_EVALUATION_BIT)},
        {"VK_SHADER_STAGE_GEOMETRY_BIT", static_cast<uint64_t>(VK_SHADER_STAGE_GEOMETRY_BIT)},
        {"VK_SHADER_STAGE_FRAGMENT_BIT", static_cast<uint64_t>(VK_SHADER_STAGE_FRAGMENT_BIT)},
        {"VK_SHADER_STAGE_COMPUTE_BIT", static_cast<uint64_t>(VK_SHADER_STAGE_COMPUTE_BIT)},
        {"VK_SHADER_STAGE_ALL_GRAPHICS", static_cast<uint64_t>(VK_SHADER_STAGE_ALL_GRAPHICS)},
        {"VK_SHADER_STAGE_ALL", static_cast<uint64_t>(VK_SHADER_STAGE_ALL)},
        // VkPipelineRobustnessImageBehavior
        {"VK_PIPELINE_ROBUSTNESS_IMAGE_BEHAVIOR_DEVICE_DEFAULT", static_cast<uint64_t>(VK_PIPELINE_ROBUSTNESS_IMAGE_BEHAVIOR_DEVICE_DEFAULT)},
        {"VK_PIPELINE_ROBUSTNESS_IMAGE_BEHAVIOR_DISABLED", static_cast<uint64_t>(VK_PIPELINE_ROBUSTNESS_IMAGE_BEHAVIOR_DISABLED)},
        {"VK_PIPELINE_ROBUSTNESS_IMAGE_BEHAVIOR_ROBUST_IMAGE_ACCESS", static_cast<uint64_t>(VK_PIPELINE_ROBUSTNESS_IMAGE_BEHAVIOR_ROBUST_IMAGE_ACCESS)},
        {"VK_PIPELINE_ROBUSTNESS_IMAGE_BEHAVIOR_ROBUST_IMAGE_ACCESS_2", static_cast<uint64_t>(VK_PIPELINE_ROBUSTNESS_IMAGE_BEHAVIOR_ROBUST_IMAGE_ACCESS_2)},
        // VkQueueFlagBits
        {"VK_QUEUE_GRAPHICS_BIT", static_cast<uint64_t>(VK_QUEUE_GRAPHICS_BIT)},
        {"VK_QUEUE_COMPUTE_BIT", static_cast<uint64_t>(VK_QUEUE_COMPUTE_BIT)},
        {"VK_QUEUE_TRANSFER_BIT", static_cast<uint64_t>(VK_QUEUE_TRANSFER_BIT)},
        {"VK_QUEUE_PROTECTED_BIT", static_cast<uint64_t>(VK_QUEUE_PROTECTED_BIT)},
        // VkToolPurposeFlagBits
        {"VK_TOOL_PURPOSE_VALIDATION_BIT", static_cast<uint64_t>(VK_TOOL_PURPOSE_VALIDATION_BIT)},
        {"VK_TOOL_PURPOSE_PROFILING_BIT", static_cast<uint64_t>(VK_TOOL_PURPOSE_PROFILING_BIT)},
        {"VK_TOOL_PURPOSE_TRACING_BIT", static_cast<uint64_t>(VK_TOOL_PURPOSE_TRACING_BIT)},
        {"VK_TOOL_PURPOSE_ADDITIONAL_FEATURES_BIT", static_cast<uint64_t>(VK_TOOL_PURPOSE_ADDITIONAL_FEATURES_BIT)},
        {"VK_TOOL_PURPOSE_MODIFYING_FEATURES_BIT", static_cast<uint64_t>(VK_TOOL_PURPOSE_MODIFYING_FEATURES_BIT)},
        // VkPointClippingBehavior
        {"VK_POINT_CLIPPING_BEHAVIOR_ALL_CLIP_PLANES", static_cast<uint64_t>(VK_POINT_CLIPPING_BEHAVIOR_ALL_CLIP_PLANES)},
        {"VK_POINT_CLIPPING_BEHAVIOR_USER_CLIP_PLANES_ONLY", static_cast<uint64_t>(VK_POINT_CLIPPING_BEHAVIOR_USER_CLIP_PLANES_ONLY)},
        // VkBufferUsageFlagBits
        {"VK_BUFFER_USAGE_TRANSFER_SRC_BIT", static_cast<uint64_t>(VK_BUFFER_USAGE_TRANSFER_SRC_BIT)},
        {"VK_BUFFER_USAGE_TRANSFER_DST_BIT", static_cast<uint64_t>(VK_BUFFER_USAGE_TRANSFER_DST_BIT)},
        {"VK_BUFFER_USAGE_UNIFORM_TEXEL_BUFFER_BIT", static_cast<uint64_t>(VK_BUFFER_USAGE_UNIFORM_TEXEL_BUFFER_BIT)},
        {"VK_BUFFER_USAGE_STORAGE_TEXEL_BUFFER_BIT", static_cast<uint64_t>(VK_BUFFER_USAGE_STORAGE_TEXEL_BUFFER_BIT)},
        {"VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT", static_cast<uint64_t>(VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT)},
        {"VK_BUFFER_USAGE_STORAGE_BUFFER_BIT", static_cast<uint64_t>(VK_BUFFER_USAGE_STORAGE_BUFFER_BIT)},
        {"VK_BUFFER_USAGE_INDEX_BUFFER_BIT", static_cast<uint64_t>(VK_BUFFER_USAGE_INDEX_BUFFER_BIT)},
        {"VK_BUFFER_USAGE_VERTEX_BUFFER_BIT", static_cast<uint64_t>(VK_BUFFER_USAGE_VERTEX_BUFFER_BIT)},
        {"VK_BUFFER_USAGE_INDIRECT_BUFFER_BIT", static_cast<uint64_t>(VK_BUFFER_USAGE_INDIRECT_BUFFER_BIT)},
        {"VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT", static_cast<uint64_t>(VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT)},
        // VkResolveModeFlagBits
        {"VK_RESOLVE_MODE_NONE", static_cast<uint64_t>(VK_RESOLVE_MODE_NONE)},
        {"VK_RESOLVE_MODE_SAMPLE_ZERO_BIT", static_cast<uint64_t>(VK_RESOLVE_MODE_SAMPLE_ZERO_BIT)},
        {"VK_RESOLVE_MODE_AVERAGE_BIT", static_cast<uint64_t>(VK_RESOLVE_MODE_AVERAGE_BIT)},
        {"VK_RESOLVE_MODE_MIN_BIT", static_cast<uint64_t>(VK_RESOLVE_MODE_MIN_BIT)},
        {"VK_RESOLVE_MODE_MAX_BIT", static_cast<uint64_t>(VK_RESOLVE_MODE_MAX_BIT)},
        // VkSubgroupFeatureFlagBits
        {"VK_SUBGROUP_FEATURE_BASIC_BIT", static_cast<uint64_t>(VK_SUBGROUP_FEATURE_BASIC_BIT)},
        {"VK_SUBGROUP_FEATURE_VOTE_BIT", static_cast<uint64_t>(VK_SUBGROUP_FEATURE_VOTE_BIT)},
        {"VK_SUBGROUP_FEATURE_ARITHMETIC_BIT", static_cast<uint64_t>(VK_SUBGROUP_FEATURE_ARITHMETIC_BIT)},
        {"VK_SUBGROUP_FEATURE_BALLOT_BIT", static_cast<uint64_t>(VK_SUBGROUP_FEATURE_BALLOT_BIT)},
        {"VK_SUBGROUP_FEATURE_SHUFFLE_BIT", static_cast<uint64_t>(VK_SUBGROUP_FEATURE_SHUFFLE_BIT)},
        {"VK_SUBGROUP_FEATURE_SHUFFLE_RELATIVE_BIT", static_cast<uint64_t>(VK_SUBGROUP_FEATURE_SHUFFLE_RELATIVE_BIT)},
        {"VK_SUBGROUP_FEATURE_CLUSTERED_BIT", static_cast<uint64_t>(VK_SUBGROUP_FEATURE_CLUSTERED_BIT)},
        {"VK_SUBGROUP_FEATURE_QUAD_BIT", static_cast<uint64_t>(VK_SUBGROUP_FEATURE_QUAD_BIT)},
        {"VK_SUBGROUP_FEATURE_ROTATE_BIT", static_cast<uint64_t>(VK_SUBGROUP_FEATURE_ROTATE_BIT)},
        {"VK_SUBGROUP_FEATURE_ROTATE_CLUSTERED_BIT", static_cast<uint64_t>(VK_SUBGROUP_FEATURE_ROTATE_CLUSTERED_BIT)},
        // VkSampleCountFlagBits
        {"VK_SAMPLE_COUNT_1_BIT", static_cast<uint64_t>(VK_SAMPLE_COUNT_1_BIT)},
        {"VK_SAMPLE_COUNT_2_BIT", static_cast<uint64_t>(VK_SAMPLE_COUNT_2_BIT)},
        {"VK_SAMPLE_COUNT_4_BIT", static_cast<uint64_t>(VK_SAMPLE_COUNT_4_BIT)},
        {"VK_SAMPLE_COUNT_8_BIT", static_cast<uint64_t>(VK_SAMPLE_COUNT_8_BIT)},
        {"VK_SAMPLE_COUNT_16_BIT", static_cast<uint64_t>(VK_SAMPLE_COUNT_16_BIT)},
        {"VK_SAMPLE_COUNT_32_BIT", static_cast<uint64_t>(VK_SAMPLE_COUNT_32_BIT)},
        {"VK_SAMPLE_COUNT_64_BIT", static_cast<uint64_t>(VK_SAMPLE_COUNT_64_BIT)},
        // VkImageUsageFlagBits
        {"VK_IMAGE_USAGE_TRANSFER_SRC_BIT", static_cast<uint64_t>(VK_IMAGE_USAGE_TRANSFER_SRC_BIT)},
        {"VK_IMAGE_USAGE_TRANSFER_DST_BIT", static_cast<uint64_t>(VK_IMAGE_USAGE_TRANSFER_DST_BIT)},
        {"VK_IMAGE_USAGE_SAMPLED_BIT", static_cast<uint64_t>(VK_IMAGE_USAGE_SAMPLED_BIT)},
        {"VK_IMAGE_USAGE_STORAGE_BIT", static_cast<uint64_t>(VK_IMAGE_USAGE_STORAGE_BIT)},
        {"VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT", static_cast<uint64_t>(VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT)},
        {"VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT", static_cast<uint64_t>(VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT)},
        {"VK_IMAGE_USAGE_TRANSIENT_ATTACHMENT_BIT", static_cast<uint64_t>(VK_IMAGE_USAGE_TRANSIENT_ATTACHMENT_BIT)},
        {"VK_IMAGE_USAGE_INPUT_ATTACHMENT_BIT", static_cast<uint64_t>(VK_IMAGE_USAGE_INPUT_ATTACHMENT_BIT)},
        {"VK_IMAGE_USAGE_HOST_TRANSFER_BIT", static_cast<uint64_t>(VK_IMAGE_USAGE_HOST_TRANSFER_BIT)},
        {"VK_IMAGE_USAGE_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR", static_cast<uint64_t>(VK_IMAGE_USAGE_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR)},
        // VkShaderFloatControlsIndependence
        {"VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_32_BIT_ONLY", static_cast<uint64_t>(VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_32_BIT_ONLY)},
        {"VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_ALL", static_cast<uint64_t>(VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_ALL)},
        {"VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_NONE", static_cast<uint64_t>(VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_NONE)},
        // VkPipelineRobustnessBufferBehavior
        {"VK_PIPELINE_ROBUSTNESS_BUFFER_BEHAVIOR_DEVICE_DEFAULT", static_cast<uint64_t>(VK_PIPELINE_ROBUSTNESS_BUFFER_BEHAVIOR_DEVICE_DEFAULT)},
        {"VK_PIPELINE_ROBUSTNESS_BUFFER_BEHAVIOR_DISABLED", static_cast<uint64_t>(VK_PIPELINE_ROBUSTNESS_BUFFER_BEHAVIOR_DISABLED)},
        {"VK_PIPELINE_ROBUSTNESS_BUFFER_BEHAVIOR_ROBUST_BUFFER_ACCESS", static_cast<uint64_t>(VK_PIPELINE_ROBUSTNESS_BUFFER_BEHAVIOR_ROBUST_BUFFER_ACCESS)},
        {"VK_PIPELINE_ROBUSTNESS_BUFFER_BEHAVIOR_ROBUST_BUFFER_ACCESS_2", static_cast<uint64_t>(VK_PIPELINE_ROBUSTNESS_BUFFER_BEHAVIOR_ROBUST_BUFFER_ACCESS_2)},
    };
    const auto it = map.find(input_value);
    if (it != map.end()) {
        return it->second;
    }
    return 0;
}

static VkFormatFeatureFlags StringToVkFormatFeatureFlags(const std::string &input_value) {
    static const std::unordered_map<std::string, VkFormatFeatureFlags> map = {
        {"VK_FORMAT_FEATURE_SAMPLED_IMAGE_BIT", VK_FORMAT_FEATURE_SAMPLED_IMAGE_BIT},
        {"VK_FORMAT_FEATURE_STORAGE_IMAGE_BIT", VK_FORMAT_FEATURE_STORAGE_IMAGE_BIT},
        {"VK_FORMAT_FEATURE_STORAGE_IMAGE_ATOMIC_BIT", VK_FORMAT_FEATURE_STORAGE_IMAGE_ATOMIC_BIT},
        {"VK_FORMAT_FEATURE_UNIFORM_TEXEL_BUFFER_BIT", VK_FORMAT_FEATURE_UNIFORM_TEXEL_BUFFER_BIT},
        {"VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_BIT", VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_BIT},
        {"VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_ATOMIC_BIT", VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_ATOMIC_BIT},
        {"VK_FORMAT_FEATURE_VERTEX_BUFFER_BIT", VK_FORMAT_FEATURE_VERTEX_BUFFER_BIT},
        {"VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BIT", VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BIT},
        {"VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BLEND_BIT", VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BLEND_BIT},
        {"VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT", VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT},
        {"VK_FORMAT_FEATURE_BLIT_SRC_BIT", VK_FORMAT_FEATURE_BLIT_SRC_BIT},
        {"VK_FORMAT_FEATURE_BLIT_DST_BIT", VK_FORMAT_FEATURE_BLIT_DST_BIT},
        {"VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_LINEAR_BIT", VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_LINEAR_BIT},
        {"VK_FORMAT_FEATURE_TRANSFER_SRC_BIT", VK_FORMAT_FEATURE_TRANSFER_SRC_BIT},
        {"VK_FORMAT_FEATURE_TRANSFER_DST_BIT", VK_FORMAT_FEATURE_TRANSFER_DST_BIT},
        {"VK_FORMAT_FEATURE_MIDPOINT_CHROMA_SAMPLES_BIT", VK_FORMAT_FEATURE_MIDPOINT_CHROMA_SAMPLES_BIT},
        {"VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER_BIT", VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER_BIT},
        {"VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_SEPARATE_RECONSTRUCTION_FILTER_BIT", VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_SEPARATE_RECONSTRUCTION_FILTER_BIT},
        {"VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_BIT", VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_BIT},
        {"VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_FORCEABLE_BIT", VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_FORCEABLE_BIT},
        {"VK_FORMAT_FEATURE_DISJOINT_BIT", VK_FORMAT_FEATURE_DISJOINT_BIT},
        {"VK_FORMAT_FEATURE_COSITED_CHROMA_SAMPLES_BIT", VK_FORMAT_FEATURE_COSITED_CHROMA_SAMPLES_BIT},
        {"VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_MINMAX_BIT", VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_MINMAX_BIT},
        {"VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_CUBIC_BIT_EXT", VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_CUBIC_BIT_EXT},
        {"VK_FORMAT_FEATURE_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR", VK_FORMAT_FEATURE_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR},
    };
    const auto it = map.find(input_value);
    if (it != map.end()) {
        return it->second;
    }
    return VkFormatFeatureFlags{};
}

static VkQueueFlags StringToVkQueueFlags(const std::string &input_value) {
    static const std::unordered_map<std::string, VkQueueFlags> map = {
        {"VK_QUEUE_GRAPHICS_BIT", VK_QUEUE_GRAPHICS_BIT},
        {"VK_QUEUE_COMPUTE_BIT", VK_QUEUE_COMPUTE_BIT},
        {"VK_QUEUE_TRANSFER_BIT", VK_QUEUE_TRANSFER_BIT},
        {"VK_QUEUE_PROTECTED_BIT", VK_QUEUE_PROTECTED_BIT},
    };
    const auto it = map.find(input_value);
    if (it != map.end()) {
        return it->second;
    }
    return VkQueueFlags{};
}

static VkQueueGlobalPriorityKHR StringToVkQueueGlobalPriorityKHR(const std::string &input_value) {
    static const std::unordered_map<std::string, VkQueueGlobalPriorityKHR> map = {
        {"VK_QUEUE_GLOBAL_PRIORITY_LOW", VK_QUEUE_GLOBAL_PRIORITY_LOW},
        {"VK_QUEUE_GLOBAL_PRIORITY_MEDIUM", VK_QUEUE_GLOBAL_PRIORITY_MEDIUM},
        {"VK_QUEUE_GLOBAL_PRIORITY_HIGH", VK_QUEUE_GLOBAL_PRIORITY_HIGH},
        {"VK_QUEUE_GLOBAL_PRIORITY_REALTIME", VK_QUEUE_GLOBAL_PRIORITY_REALTIME},
        {"VK_QUEUE_GLOBAL_PRIORITY_LOW_KHR", VK_QUEUE_GLOBAL_PRIORITY_LOW_KHR},
        {"VK_QUEUE_GLOBAL_PRIORITY_MEDIUM_KHR", VK_QUEUE_GLOBAL_PRIORITY_MEDIUM_KHR},
        {"VK_QUEUE_GLOBAL_PRIORITY_HIGH_KHR", VK_QUEUE_GLOBAL_PRIORITY_HIGH_KHR},
        {"VK_QUEUE_GLOBAL_PRIORITY_REALTIME_KHR", VK_QUEUE_GLOBAL_PRIORITY_REALTIME_KHR},
    };
    const auto it = map.find(input_value);
    if (it != map.end()) {
        return it->second;
    }
    return VkQueueGlobalPriorityKHR{};
}

static VkPipelineStageFlags StringToVkPipelineStageFlags(const std::string &input_value) {
    static const std::unordered_map<std::string, VkPipelineStageFlags> map = {
        {"VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT", VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT},
        {"VK_PIPELINE_STAGE_DRAW_INDIRECT_BIT", VK_PIPELINE_STAGE_DRAW_INDIRECT_BIT},
        {"VK_PIPELINE_STAGE_VERTEX_INPUT_BIT", VK_PIPELINE_STAGE_VERTEX_INPUT_BIT},
        {"VK_PIPELINE_STAGE_VERTEX_SHADER_BIT", VK_PIPELINE_STAGE_VERTEX_SHADER_BIT},
        {"VK_PIPELINE_STAGE_TESSELLATION_CONTROL_SHADER_BIT", VK_PIPELINE_STAGE_TESSELLATION_CONTROL_SHADER_BIT},
        {"VK_PIPELINE_STAGE_TESSELLATION_EVALUATION_SHADER_BIT", VK_PIPELINE_STAGE_TESSELLATION_EVALUATION_SHADER_BIT},
        {"VK_PIPELINE_STAGE_GEOMETRY_SHADER_BIT", VK_PIPELINE_STAGE_GEOMETRY_SHADER_BIT},
        {"VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT", VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT},
        {"VK_PIPELINE_STAGE_EARLY_FRAGMENT_TESTS_BIT", VK_PIPELINE_STAGE_EARLY_FRAGMENT_TESTS_BIT},
        {"VK_PIPELINE_STAGE_LATE_FRAGMENT_TESTS_BIT", VK_PIPELINE_STAGE_LATE_FRAGMENT_TESTS_BIT},
        {"VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT", VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT},
        {"VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT", VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT},
        {"VK_PIPELINE_STAGE_TRANSFER_BIT", VK_PIPELINE_STAGE_TRANSFER_BIT},
        {"VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT", VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT},
        {"VK_PIPELINE_STAGE_HOST_BIT", VK_PIPELINE_STAGE_HOST_BIT},
        {"VK_PIPELINE_STAGE_ALL_GRAPHICS_BIT", VK_PIPELINE_STAGE_ALL_GRAPHICS_BIT},
        {"VK_PIPELINE_STAGE_ALL_COMMANDS_BIT", VK_PIPELINE_STAGE_ALL_COMMANDS_BIT},
        {"VK_PIPELINE_STAGE_NONE", VK_PIPELINE_STAGE_NONE},
        {"VK_PIPELINE_STAGE_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR", VK_PIPELINE_STAGE_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR},
        {"VK_PIPELINE_STAGE_NONE_KHR", VK_PIPELINE_STAGE_NONE_KHR},
    };
    const auto it = map.find(input_value);
    if (it != map.end()) {
        return it->second;
    }
    return VkPipelineStageFlags{};
}

static VkPipelineStageFlags2 StringToVkPipelineStageFlags2(const std::string &input_value) {
    static const std::unordered_map<std::string, VkPipelineStageFlags2> map = {
        {"VK_PIPELINE_STAGE_2_NONE", VK_PIPELINE_STAGE_2_NONE},
        {"VK_PIPELINE_STAGE_2_TOP_OF_PIPE_BIT", VK_PIPELINE_STAGE_2_TOP_OF_PIPE_BIT},
        {"VK_PIPELINE_STAGE_2_DRAW_INDIRECT_BIT", VK_PIPELINE_STAGE_2_DRAW_INDIRECT_BIT},
        {"VK_PIPELINE_STAGE_2_VERTEX_INPUT_BIT", VK_PIPELINE_STAGE_2_VERTEX_INPUT_BIT},
        {"VK_PIPELINE_STAGE_2_VERTEX_SHADER_BIT", VK_PIPELINE_STAGE_2_VERTEX_SHADER_BIT},
        {"VK_PIPELINE_STAGE_2_TESSELLATION_CONTROL_SHADER_BIT", VK_PIPELINE_STAGE_2_TESSELLATION_CONTROL_SHADER_BIT},
        {"VK_PIPELINE_STAGE_2_TESSELLATION_EVALUATION_SHADER_BIT", VK_PIPELINE_STAGE_2_TESSELLATION_EVALUATION_SHADER_BIT},
        {"VK_PIPELINE_STAGE_2_GEOMETRY_SHADER_BIT", VK_PIPELINE_STAGE_2_GEOMETRY_SHADER_BIT},
        {"VK_PIPELINE_STAGE_2_FRAGMENT_SHADER_BIT", VK_PIPELINE_STAGE_2_FRAGMENT_SHADER_BIT},
        {"VK_PIPELINE_STAGE_2_EARLY_FRAGMENT_TESTS_BIT", VK_PIPELINE_STAGE_2_EARLY_FRAGMENT_TESTS_BIT},
        {"VK_PIPELINE_STAGE_2_LATE_FRAGMENT_TESTS_BIT", VK_PIPELINE_STAGE_2_LATE_FRAGMENT_TESTS_BIT},
        {"VK_PIPELINE_STAGE_2_COLOR_ATTACHMENT_OUTPUT_BIT", VK_PIPELINE_STAGE_2_COLOR_ATTACHMENT_OUTPUT_BIT},
        {"VK_PIPELINE_STAGE_2_COMPUTE_SHADER_BIT", VK_PIPELINE_STAGE_2_COMPUTE_SHADER_BIT},
        {"VK_PIPELINE_STAGE_2_ALL_TRANSFER_BIT", VK_PIPELINE_STAGE_2_ALL_TRANSFER_BIT},
        {"VK_PIPELINE_STAGE_2_BOTTOM_OF_PIPE_BIT", VK_PIPELINE_STAGE_2_BOTTOM_OF_PIPE_BIT},
        {"VK_PIPELINE_STAGE_2_HOST_BIT", VK_PIPELINE_STAGE_2_HOST_BIT},
        {"VK_PIPELINE_STAGE_2_ALL_GRAPHICS_BIT", VK_PIPELINE_STAGE_2_ALL_GRAPHICS_BIT},
        {"VK_PIPELINE_STAGE_2_ALL_COMMANDS_BIT", VK_PIPELINE_STAGE_2_ALL_COMMANDS_BIT},
        {"VK_PIPELINE_STAGE_2_COPY_BIT", VK_PIPELINE_STAGE_2_COPY_BIT},
        {"VK_PIPELINE_STAGE_2_RESOLVE_BIT", VK_PIPELINE_STAGE_2_RESOLVE_BIT},
        {"VK_PIPELINE_STAGE_2_BLIT_BIT", VK_PIPELINE_STAGE_2_BLIT_BIT},
        {"VK_PIPELINE_STAGE_2_CLEAR_BIT", VK_PIPELINE_STAGE_2_CLEAR_BIT},
        {"VK_PIPELINE_STAGE_2_INDEX_INPUT_BIT", VK_PIPELINE_STAGE_2_INDEX_INPUT_BIT},
        {"VK_PIPELINE_STAGE_2_VERTEX_ATTRIBUTE_INPUT_BIT", VK_PIPELINE_STAGE_2_VERTEX_ATTRIBUTE_INPUT_BIT},
        {"VK_PIPELINE_STAGE_2_PRE_RASTERIZATION_SHADERS_BIT", VK_PIPELINE_STAGE_2_PRE_RASTERIZATION_SHADERS_BIT},
        {"VK_PIPELINE_STAGE_2_TRANSFORM_FEEDBACK_BIT_EXT", VK_PIPELINE_STAGE_2_TRANSFORM_FEEDBACK_BIT_EXT},
        {"VK_PIPELINE_STAGE_2_CONDITIONAL_RENDERING_BIT_EXT", VK_PIPELINE_STAGE_2_CONDITIONAL_RENDERING_BIT_EXT},
        {"VK_PIPELINE_STAGE_2_COMMAND_PREPROCESS_BIT_EXT", VK_PIPELINE_STAGE_2_COMMAND_PREPROCESS_BIT_EXT},
        {"VK_PIPELINE_STAGE_2_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR", VK_PIPELINE_STAGE_2_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR},
        {"VK_PIPELINE_STAGE_2_ACCELERATION_STRUCTURE_BUILD_BIT_KHR", VK_PIPELINE_STAGE_2_ACCELERATION_STRUCTURE_BUILD_BIT_KHR},
        {"VK_PIPELINE_STAGE_2_RAY_TRACING_SHADER_BIT_KHR", VK_PIPELINE_STAGE_2_RAY_TRACING_SHADER_BIT_KHR},
        {"VK_PIPELINE_STAGE_2_FRAGMENT_DENSITY_PROCESS_BIT_EXT", VK_PIPELINE_STAGE_2_FRAGMENT_DENSITY_PROCESS_BIT_EXT},
        {"VK_PIPELINE_STAGE_2_TASK_SHADER_BIT_EXT", VK_PIPELINE_STAGE_2_TASK_SHADER_BIT_EXT},
        {"VK_PIPELINE_STAGE_2_MESH_SHADER_BIT_EXT", VK_PIPELINE_STAGE_2_MESH_SHADER_BIT_EXT},
        {"VK_PIPELINE_STAGE_2_TRANSFER_BIT", VK_PIPELINE_STAGE_2_TRANSFER_BIT},
        {"VK_PIPELINE_STAGE_2_NONE_KHR", VK_PIPELINE_STAGE_2_NONE_KHR},
        {"VK_PIPELINE_STAGE_2_TOP_OF_PIPE_BIT_KHR", VK_PIPELINE_STAGE_2_TOP_OF_PIPE_BIT_KHR},
        {"VK_PIPELINE_STAGE_2_DRAW_INDIRECT_BIT_KHR", VK_PIPELINE_STAGE_2_DRAW_INDIRECT_BIT_KHR},
        {"VK_PIPELINE_STAGE_2_VERTEX_INPUT_BIT_KHR", VK_PIPELINE_STAGE_2_VERTEX_INPUT_BIT_KHR},
        {"VK_PIPELINE_STAGE_2_VERTEX_SHADER_BIT_KHR", VK_PIPELINE_STAGE_2_VERTEX_SHADER_BIT_KHR},
        {"VK_PIPELINE_STAGE_2_TESSELLATION_CONTROL_SHADER_BIT_KHR", VK_PIPELINE_STAGE_2_TESSELLATION_CONTROL_SHADER_BIT_KHR},
        {"VK_PIPELINE_STAGE_2_TESSELLATION_EVALUATION_SHADER_BIT_KHR", VK_PIPELINE_STAGE_2_TESSELLATION_EVALUATION_SHADER_BIT_KHR},
        {"VK_PIPELINE_STAGE_2_GEOMETRY_SHADER_BIT_KHR", VK_PIPELINE_STAGE_2_GEOMETRY_SHADER_BIT_KHR},
        {"VK_PIPELINE_STAGE_2_FRAGMENT_SHADER_BIT_KHR", VK_PIPELINE_STAGE_2_FRAGMENT_SHADER_BIT_KHR},
        {"VK_PIPELINE_STAGE_2_EARLY_FRAGMENT_TESTS_BIT_KHR", VK_PIPELINE_STAGE_2_EARLY_FRAGMENT_TESTS_BIT_KHR},
        {"VK_PIPELINE_STAGE_2_LATE_FRAGMENT_TESTS_BIT_KHR", VK_PIPELINE_STAGE_2_LATE_FRAGMENT_TESTS_BIT_KHR},
        {"VK_PIPELINE_STAGE_2_COLOR_ATTACHMENT_OUTPUT_BIT_KHR", VK_PIPELINE_STAGE_2_COLOR_ATTACHMENT_OUTPUT_BIT_KHR},
        {"VK_PIPELINE_STAGE_2_COMPUTE_SHADER_BIT_KHR", VK_PIPELINE_STAGE_2_COMPUTE_SHADER_BIT_KHR},
        {"VK_PIPELINE_STAGE_2_ALL_TRANSFER_BIT_KHR", VK_PIPELINE_STAGE_2_ALL_TRANSFER_BIT_KHR},
        {"VK_PIPELINE_STAGE_2_TRANSFER_BIT_KHR", VK_PIPELINE_STAGE_2_TRANSFER_BIT_KHR},
        {"VK_PIPELINE_STAGE_2_BOTTOM_OF_PIPE_BIT_KHR", VK_PIPELINE_STAGE_2_BOTTOM_OF_PIPE_BIT_KHR},
        {"VK_PIPELINE_STAGE_2_HOST_BIT_KHR", VK_PIPELINE_STAGE_2_HOST_BIT_KHR},
        {"VK_PIPELINE_STAGE_2_ALL_GRAPHICS_BIT_KHR", VK_PIPELINE_STAGE_2_ALL_GRAPHICS_BIT_KHR},
        {"VK_PIPELINE_STAGE_2_ALL_COMMANDS_BIT_KHR", VK_PIPELINE_STAGE_2_ALL_COMMANDS_BIT_KHR},
        {"VK_PIPELINE_STAGE_2_COPY_BIT_KHR", VK_PIPELINE_STAGE_2_COPY_BIT_KHR},
        {"VK_PIPELINE_STAGE_2_RESOLVE_BIT_KHR", VK_PIPELINE_STAGE_2_RESOLVE_BIT_KHR},
        {"VK_PIPELINE_STAGE_2_BLIT_BIT_KHR", VK_PIPELINE_STAGE_2_BLIT_BIT_KHR},
        {"VK_PIPELINE_STAGE_2_CLEAR_BIT_KHR", VK_PIPELINE_STAGE_2_CLEAR_BIT_KHR},
        {"VK_PIPELINE_STAGE_2_INDEX_INPUT_BIT_KHR", VK_PIPELINE_STAGE_2_INDEX_INPUT_BIT_KHR},
        {"VK_PIPELINE_STAGE_2_VERTEX_ATTRIBUTE_INPUT_BIT_KHR", VK_PIPELINE_STAGE_2_VERTEX_ATTRIBUTE_INPUT_BIT_KHR},
        {"VK_PIPELINE_STAGE_2_PRE_RASTERIZATION_SHADERS_BIT_KHR", VK_PIPELINE_STAGE_2_PRE_RASTERIZATION_SHADERS_BIT_KHR},
        {"VK_PIPELINE_STAGE_2_COMMAND_PREPROCESS_BIT_NV", VK_PIPELINE_STAGE_2_COMMAND_PREPROCESS_BIT_NV},
        {"VK_PIPELINE_STAGE_2_SHADING_RATE_IMAGE_BIT_NV", VK_PIPELINE_STAGE_2_SHADING_RATE_IMAGE_BIT_NV},
        {"VK_PIPELINE_STAGE_2_RAY_TRACING_SHADER_BIT_NV", VK_PIPELINE_STAGE_2_RAY_TRACING_SHADER_BIT_NV},
        {"VK_PIPELINE_STAGE_2_ACCELERATION_STRUCTURE_BUILD_BIT_NV", VK_PIPELINE_STAGE_2_ACCELERATION_STRUCTURE_BUILD_BIT_NV},
        {"VK_PIPELINE_STAGE_2_TASK_SHADER_BIT_NV", VK_PIPELINE_STAGE_2_TASK_SHADER_BIT_NV},
        {"VK_PIPELINE_STAGE_2_MESH_SHADER_BIT_NV", VK_PIPELINE_STAGE_2_MESH_SHADER_BIT_NV},
    };
    const auto it = map.find(input_value);
    if (it != map.end()) {
        return it->second;
    }
    return VkPipelineStageFlags2{};
}

static VkFormatFeatureFlags2 StringToVkFormatFeatureFlags2(const std::string &input_value) {
    static const std::unordered_map<std::string, VkFormatFeatureFlags2> map = {
        {"VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_BIT", VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_BIT},
        {"VK_FORMAT_FEATURE_2_STORAGE_IMAGE_BIT", VK_FORMAT_FEATURE_2_STORAGE_IMAGE_BIT},
        {"VK_FORMAT_FEATURE_2_STORAGE_IMAGE_ATOMIC_BIT", VK_FORMAT_FEATURE_2_STORAGE_IMAGE_ATOMIC_BIT},
        {"VK_FORMAT_FEATURE_2_UNIFORM_TEXEL_BUFFER_BIT", VK_FORMAT_FEATURE_2_UNIFORM_TEXEL_BUFFER_BIT},
        {"VK_FORMAT_FEATURE_2_STORAGE_TEXEL_BUFFER_BIT", VK_FORMAT_FEATURE_2_STORAGE_TEXEL_BUFFER_BIT},
        {"VK_FORMAT_FEATURE_2_STORAGE_TEXEL_BUFFER_ATOMIC_BIT", VK_FORMAT_FEATURE_2_STORAGE_TEXEL_BUFFER_ATOMIC_BIT},
        {"VK_FORMAT_FEATURE_2_VERTEX_BUFFER_BIT", VK_FORMAT_FEATURE_2_VERTEX_BUFFER_BIT},
        {"VK_FORMAT_FEATURE_2_COLOR_ATTACHMENT_BIT", VK_FORMAT_FEATURE_2_COLOR_ATTACHMENT_BIT},
        {"VK_FORMAT_FEATURE_2_COLOR_ATTACHMENT_BLEND_BIT", VK_FORMAT_FEATURE_2_COLOR_ATTACHMENT_BLEND_BIT},
        {"VK_FORMAT_FEATURE_2_DEPTH_STENCIL_ATTACHMENT_BIT", VK_FORMAT_FEATURE_2_DEPTH_STENCIL_ATTACHMENT_BIT},
        {"VK_FORMAT_FEATURE_2_BLIT_SRC_BIT", VK_FORMAT_FEATURE_2_BLIT_SRC_BIT},
        {"VK_FORMAT_FEATURE_2_BLIT_DST_BIT", VK_FORMAT_FEATURE_2_BLIT_DST_BIT},
        {"VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_LINEAR_BIT", VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_LINEAR_BIT},
        {"VK_FORMAT_FEATURE_2_TRANSFER_SRC_BIT", VK_FORMAT_FEATURE_2_TRANSFER_SRC_BIT},
        {"VK_FORMAT_FEATURE_2_TRANSFER_DST_BIT", VK_FORMAT_FEATURE_2_TRANSFER_DST_BIT},
        {"VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_MINMAX_BIT", VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_MINMAX_BIT},
        {"VK_FORMAT_FEATURE_2_MIDPOINT_CHROMA_SAMPLES_BIT", VK_FORMAT_FEATURE_2_MIDPOINT_CHROMA_SAMPLES_BIT},
        {"VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER_BIT", VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER_BIT},
        {"VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_SEPARATE_RECONSTRUCTION_FILTER_BIT", VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_SEPARATE_RECONSTRUCTION_FILTER_BIT},
        {"VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_BIT", VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_BIT},
        {"VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_FORCEABLE_BIT", VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_FORCEABLE_BIT},
        {"VK_FORMAT_FEATURE_2_DISJOINT_BIT", VK_FORMAT_FEATURE_2_DISJOINT_BIT},
        {"VK_FORMAT_FEATURE_2_COSITED_CHROMA_SAMPLES_BIT", VK_FORMAT_FEATURE_2_COSITED_CHROMA_SAMPLES_BIT},
        {"VK_FORMAT_FEATURE_2_STORAGE_READ_WITHOUT_FORMAT_BIT", VK_FORMAT_FEATURE_2_STORAGE_READ_WITHOUT_FORMAT_BIT},
        {"VK_FORMAT_FEATURE_2_STORAGE_WRITE_WITHOUT_FORMAT_BIT", VK_FORMAT_FEATURE_2_STORAGE_WRITE_WITHOUT_FORMAT_BIT},
        {"VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_DEPTH_COMPARISON_BIT", VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_DEPTH_COMPARISON_BIT},
        {"VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_CUBIC_BIT", VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_CUBIC_BIT},
        {"VK_FORMAT_FEATURE_2_HOST_IMAGE_TRANSFER_BIT", VK_FORMAT_FEATURE_2_HOST_IMAGE_TRANSFER_BIT},
        {"VK_FORMAT_FEATURE_2_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR", VK_FORMAT_FEATURE_2_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR},
    };
    const auto it = map.find(input_value);
    if (it != map.end()) {
        return it->second;
    }
    return VkFormatFeatureFlags2{};
}

static bool operator==(const VkOffset2D& lhs, const VkOffset2D& rhs) {
    if (lhs.x != rhs.x) return false;
    if (lhs.y != rhs.y) return false;
    return true;
}

static bool operator!=(const VkOffset2D& lhs, const VkOffset2D& rhs) {
    return !operator==(lhs, rhs);
}

template <>
struct std::hash<VkOffset2D> {
    std::size_t operator()(const VkOffset2D& k) const {        const std::size_t kMagic = 0x9e3779b97f4a7c16UL;
        std::size_t h = 0;
        h ^= std::hash<decltype(k.x)>{}(k.x) + kMagic + (h << 6) + (h >> 2);
        h ^= std::hash<decltype(k.y)>{}(k.y) + kMagic + (h << 6) + (h >> 2);
        return h;
    }
};

static bool operator==(const VkOffset3D& lhs, const VkOffset3D& rhs) {
    if (lhs.x != rhs.x) return false;
    if (lhs.y != rhs.y) return false;
    if (lhs.z != rhs.z) return false;
    return true;
}

static bool operator!=(const VkOffset3D& lhs, const VkOffset3D& rhs) {
    return !operator==(lhs, rhs);
}

template <>
struct std::hash<VkOffset3D> {
    std::size_t operator()(const VkOffset3D& k) const {        const std::size_t kMagic = 0x9e3779b97f4a7c16UL;
        std::size_t h = 0;
        h ^= std::hash<decltype(k.x)>{}(k.x) + kMagic + (h << 6) + (h >> 2);
        h ^= std::hash<decltype(k.y)>{}(k.y) + kMagic + (h << 6) + (h >> 2);
        h ^= std::hash<decltype(k.z)>{}(k.z) + kMagic + (h << 6) + (h >> 2);
        return h;
    }
};

static bool operator==(const VkExtent2D& lhs, const VkExtent2D& rhs) {
    if (lhs.width != rhs.width) return false;
    if (lhs.height != rhs.height) return false;
    return true;
}

static bool operator!=(const VkExtent2D& lhs, const VkExtent2D& rhs) {
    return !operator==(lhs, rhs);
}

template <>
struct std::hash<VkExtent2D> {
    std::size_t operator()(const VkExtent2D& k) const {        const std::size_t kMagic = 0x9e3779b97f4a7c16UL;
        std::size_t h = 0;
        h ^= std::hash<decltype(k.width)>{}(k.width) + kMagic + (h << 6) + (h >> 2);
        h ^= std::hash<decltype(k.height)>{}(k.height) + kMagic + (h << 6) + (h >> 2);
        return h;
    }
};

static bool operator==(const VkExtent3D& lhs, const VkExtent3D& rhs) {
    if (lhs.width != rhs.width) return false;
    if (lhs.height != rhs.height) return false;
    if (lhs.depth != rhs.depth) return false;
    return true;
}

static bool operator!=(const VkExtent3D& lhs, const VkExtent3D& rhs) {
    return !operator==(lhs, rhs);
}

template <>
struct std::hash<VkExtent3D> {
    std::size_t operator()(const VkExtent3D& k) const {        const std::size_t kMagic = 0x9e3779b97f4a7c16UL;
        std::size_t h = 0;
        h ^= std::hash<decltype(k.width)>{}(k.width) + kMagic + (h << 6) + (h >> 2);
        h ^= std::hash<decltype(k.height)>{}(k.height) + kMagic + (h << 6) + (h >> 2);
        h ^= std::hash<decltype(k.depth)>{}(k.depth) + kMagic + (h << 6) + (h >> 2);
        return h;
    }
};

static bool operator==(const VkComponentMapping& lhs, const VkComponentMapping& rhs) {
    if (lhs.r != rhs.r) return false;
    if (lhs.g != rhs.g) return false;
    if (lhs.b != rhs.b) return false;
    if (lhs.a != rhs.a) return false;
    return true;
}

static bool operator!=(const VkComponentMapping& lhs, const VkComponentMapping& rhs) {
    return !operator==(lhs, rhs);
}

template <>
struct std::hash<VkComponentMapping> {
    std::size_t operator()(const VkComponentMapping& k) const {        const std::size_t kMagic = 0x9e3779b97f4a7c16UL;
        std::size_t h = 0;
        h ^= std::hash<decltype(k.r)>{}(k.r) + kMagic + (h << 6) + (h >> 2);
        h ^= std::hash<decltype(k.g)>{}(k.g) + kMagic + (h << 6) + (h >> 2);
        h ^= std::hash<decltype(k.b)>{}(k.b) + kMagic + (h << 6) + (h >> 2);
        h ^= std::hash<decltype(k.a)>{}(k.a) + kMagic + (h << 6) + (h >> 2);
        return h;
    }
};

// Global constants //////////////////////////////////////////////////////////////////////////////////////////////////////////////

// For new features/functionality, increment the minor level and reset patch level to zero.
// For any changes, at least increment the patch level.  See https://semver.org/
// When updating the version, be sure to make corresponding changes to the layer manifest file at
// layer/VkLayer_khronos_profiles.json.in

const uint32_t kVersionProfilesMajor = 1;
#ifdef VULKANSC
const uint32_t kVersionProfilesMinor = 0;
#else
const uint32_t kVersionProfilesMinor = 3;
#endif
const uint32_t kVersionProfilesPatch = 0;
const uint32_t kVersionProfilesImplementation =
    VK_MAKE_VERSION(kVersionProfilesMajor, kVersionProfilesMinor, kVersionProfilesPatch);

#ifdef VULKANSC
static const char *SCHEMA_URI_BASE = "https://schema.khronos.org/vulkansc/profiles-";
#else
static const char *SCHEMA_URI_BASE = "https://schema.khronos.org/vulkan/profiles-";
#endif

// Properties of this layer:
const VkLayerProperties kLayerProperties[] = {{
    kLayerName,                   // layerName
    VK_MAKE_VERSION(1, 0, 68),       // specVersion (clamped to final 1.0 spec version)
    kVersionProfilesImplementation,  // implementationVersion
    "Khronos Profiles layer"         // description
}};
const uint32_t kLayerPropertiesCount = (sizeof(kLayerProperties) / sizeof(kLayerProperties[0]));

#ifndef VULKANSC
// Instance extensions that this layer provides:
const VkExtensionProperties kInstanceExtensionProperties[] = {
    VkExtensionProperties{VK_EXT_LAYER_SETTINGS_EXTENSION_NAME, VK_EXT_LAYER_SETTINGS_SPEC_VERSION}};
const uint32_t kInstanceExtensionPropertiesCount = static_cast<uint32_t>(std::size(kInstanceExtensionProperties));
#endif

// Device extensions that this layer provides:
#ifdef VULKANSC
const std::array<VkExtensionProperties, 0> kDeviceExtensionProperties = {};
#else
const std::array<VkExtensionProperties, 2> kDeviceExtensionProperties = {
    {{VK_EXT_TOOLING_INFO_EXTENSION_NAME, VK_EXT_TOOLING_INFO_SPEC_VERSION},
     {VK_KHR_PORTABILITY_SUBSET_EXTENSION_NAME, VK_KHR_PORTABILITY_SUBSET_SPEC_VERSION}}};
#endif
const uint32_t kDeviceExtensionPropertiesCount = static_cast<uint32_t>(kDeviceExtensionProperties.size());

// Global variables //////////////////////////////////////////////////////////////////////////////////////////////////////////////

uint32_t requested_version = 0;
bool device_has_astc_hdr = false;
bool device_has_astc = false;
bool device_has_etc2 = false;
bool device_has_bc = false;
bool device_has_pvrtc = false;

std::recursive_mutex global_lock;  // Enforce thread-safety for this layer.

#define GET_VALUE(member, name, not_modifiable, requested_profile) GetValue(device_name, parent, member, #name, &dest->name, not_modifiable, requested_profile)
#define GET_ARRAY(member, name, not_modifiable) GetArray(device_name, parent, member, #name, dest->name, not_modifiable)

#define GET_VALUE_WARN(member, name, not_modifiable, requested_profile, warn_func)                     \
    if (!GetValue(device_name, parent, member, #name, &dest->name, not_modifiable, requested_profile, warn_func)) { \
        valid = false;                                                              \
    }
#define GET_VALUE_SIZE_T_WARN(member, name, not_modifiable, requested_profile, warn_func)                   \
    if (!GetValueSizet(device_name, parent, member, #name, &dest->name, not_modifiable, requested_profile, warn_func)) { \
        valid = false;                                                                   \
    }
#define GET_VALUE_FLAG_WARN(member, name, not_modifiable, requested_profile)                    \
    if (!GetValueFlag(device_name, parent, member, #name, &dest->name, not_modifiable, requested_profile)) { \
        valid = false;                                                       \
    }
#define GET_VALUE_ENUM_WARN(member, name, not_modifiable, requested_profile, warn_func)                    \
    if (!GetValueEnum(device_name, parent, member, #name, &dest->name, not_modifiable, requested_profile, warn_func)) { \
        valid = false;                                                                  \
    }

static bool IsInstanceExtension(const char* name) {
	 const char* table[] = {
          "VK_KHR_surface",
          "VK_KHR_display",
          "VK_EXT_direct_mode_display",
          "VK_EXT_display_surface_counter",
          "VK_EXT_swapchain_colorspace",
          "VK_KHR_get_surface_capabilities2",
          "VK_KHR_get_display_properties2",
          "VK_EXT_debug_utils",
          "VK_EXT_validation_features",
          "VK_EXT_headless_surface",
          "VK_EXT_application_parameters",
          "VK_EXT_layer_settings"
     };

     bool result = false;
     for (std::size_t i = 0, n = std::size(table); i < n; ++i) {
           if (strcmp(table[i], name) == 0) {
               result = true;
               break;
           }
     }

     return result;
}

// PhysicalDeviceData : creates and manages the simulated device configurations //////////////////////////////////////////////////

class PhysicalDeviceData {
   public:
    // Create a new PDD element during vkCreateInstance(), and preserve in map, indexed by physical_device.
    static PhysicalDeviceData &Create(VkPhysicalDevice pd, VkInstance instance) {
        assert(pd != VK_NULL_HANDLE);
        assert(instance != VK_NULL_HANDLE);
        assert(!Find(pd));  // Verify this instance does not already exist.

        const auto result = map().emplace(pd, instance);
        assert(result.second);  // true=insertion, false=replacement
        auto iter = result.first;
        PhysicalDeviceData *pdd = &iter->second;
        assert(Find(pd) == pdd);  // Verify we get the same instance we just inserted.
        return *pdd;
    }

    static void Destroy(const VkPhysicalDevice pd) {
        map().erase(pd);
    }

    // Find a PDD from our map, or nullptr if doesn't exist.
    static PhysicalDeviceData *Find(VkPhysicalDevice pd) {
        const auto iter = map().find(pd);
        return (iter != map().end()) ? &iter->second : nullptr;
    }

    static bool HasExtension(PhysicalDeviceData *pdd, const char *extension_name) {
        return pdd->device_extensions_.count(extension_name) > 0;
    }

    static bool HasSimulatedExtension(VkPhysicalDevice pd, const char *extension_name) {
        return HasSimulatedExtension(Find(pd), extension_name);
    }

    static bool HasSimulatedExtension(PhysicalDeviceData *pdd, const char *extension_name) {
        return pdd->simulation_extensions_.count(extension_name) > 0;
    }

    static bool HasSimulatedOrRealExtension(VkPhysicalDevice pd, const char *extension_name) {
        return HasSimulatedOrRealExtension(Find(pd), extension_name);
    }

    static bool HasSimulatedOrRealExtension(PhysicalDeviceData *pdd, const char *extension_name) {
        return HasSimulatedExtension(pdd, extension_name) || HasExtension(pdd, extension_name);
    }

    uint32_t GetEffectiveVersion() {
        return requested_version < physical_device_properties_.apiVersion ? requested_version
                                                                          : physical_device_properties_.apiVersion;

    }

    VkInstance instance() const { return instance_; }

    MapOfVkExtensionProperties device_extensions_{};
    MapOfVkFormatProperties device_formats_{};
    MapOfVkFormatProperties3 device_formats_3_{};
    ArrayOfVkQueueFamilyProperties device_queue_family_properties_{};
#ifndef VULKANSC
    SetOfVideoProfiles set_of_device_video_profiles_{};
#endif
    MapOfVkExtensionProperties simulation_extensions_{};
    VkPhysicalDeviceProperties physical_device_properties_{};
    VkPhysicalDeviceFeatures physical_device_features_{};
    VkPhysicalDeviceMemoryProperties physical_device_memory_properties_{};
    VkPhysicalDeviceToolProperties physical_device_tool_properties_{};
    VkSurfaceCapabilitiesKHR surface_capabilities_{};
    MapOfVkFormatProperties map_of_format_properties_{};
    MapOfVkFormatProperties3 map_of_format_properties_3_{};
    MapOfVkExtensionProperties map_of_extension_properties_{};
    ArrayOfVkQueueFamilyProperties arrayof_queue_family_properties_{};
#ifndef VULKANSC
    SetOfVideoProfiles set_of_video_profiles_{};
#endif

    // Space for array queries:
    //
    // - From VkPhysicalDeviceHostImageCopyPropertiesEXT
    std::vector<VkImageLayout> pCopySrcLayouts_;
    std::vector<VkImageLayout> pCopyDstLayouts_;

    bool vulkan_1_1_properties_written_;
    bool vulkan_1_2_properties_written_;
    bool vulkan_1_3_properties_written_;
    bool vulkan_1_4_properties_written_;

    bool vulkan_1_1_features_written_;
    bool vulkan_1_2_features_written_;
    bool vulkan_1_3_features_written_;
    bool vulkan_1_4_features_written_;

    // Core properties
    VkPhysicalDevicePushDescriptorProperties physical_device_push_descriptor_properties_;
    VkPhysicalDeviceDriverProperties physical_device_driver_properties_;
    VkPhysicalDeviceIDProperties physical_device_idproperties_;
    VkPhysicalDeviceMultiviewProperties physical_device_multiview_properties_;
    VkPhysicalDeviceSubgroupProperties physical_device_subgroup_properties_;
    VkPhysicalDevicePointClippingProperties physical_device_point_clipping_properties_;
    VkPhysicalDeviceProtectedMemoryProperties physical_device_protected_memory_properties_;
    VkPhysicalDeviceSamplerFilterMinmaxProperties physical_device_sampler_filter_minmax_properties_;
    VkPhysicalDeviceInlineUniformBlockProperties physical_device_inline_uniform_block_properties_;
    VkPhysicalDeviceMaintenance3Properties physical_device_maintenance_3_properties_;
    VkPhysicalDeviceMaintenance4Properties physical_device_maintenance_4_properties_;
    VkPhysicalDeviceMaintenance5Properties physical_device_maintenance_5_properties_;
    VkPhysicalDeviceMaintenance6Properties physical_device_maintenance_6_properties_;
    VkPhysicalDeviceFloatControlsProperties physical_device_float_controls_properties_;
    VkPhysicalDeviceDescriptorIndexingProperties physical_device_descriptor_indexing_properties_;
    VkPhysicalDeviceTimelineSemaphoreProperties physical_device_timeline_semaphore_properties_;
    VkPhysicalDeviceDepthStencilResolveProperties physical_device_depth_stencil_resolve_properties_;
    VkPhysicalDeviceVulkan11Properties physical_device_vulkan_11_properties_;
    VkPhysicalDeviceVulkan12Properties physical_device_vulkan_12_properties_;
    VkPhysicalDeviceVulkan13Properties physical_device_vulkan_13_properties_;
    VkPhysicalDeviceVulkan14Properties physical_device_vulkan_14_properties_;
    VkPhysicalDeviceHostImageCopyProperties physical_device_host_image_copy_properties_;
    VkPhysicalDeviceVulkanSC10Properties physical_device_vulkan_sc_10_properties_;
    VkPhysicalDeviceShaderIntegerDotProductProperties physical_device_shader_integer_dot_product_properties_;
    VkPhysicalDevicePipelineRobustnessProperties physical_device_pipeline_robustness_properties_;

    // Core features
    VkPhysicalDevicePrivateDataFeatures physical_device_private_data_features_;
    VkPhysicalDeviceVariablePointersFeatures physical_device_variable_pointer_features_;
    VkPhysicalDeviceMultiviewFeatures physical_device_multiview_features_;
    VkPhysicalDevice16BitStorageFeatures physical_device_16_bit_storage_features_;
    VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures physical_device_shader_subgroup_extended_types_features_;
    VkPhysicalDeviceSamplerYcbcrConversionFeatures physical_device_sampler_ycbcr_conversion_features_;
    VkPhysicalDeviceProtectedMemoryFeatures physical_device_protected_memory_features_;
    VkPhysicalDeviceInlineUniformBlockFeatures physical_device_inline_uniform_block_features_;
    VkPhysicalDeviceMaintenance4Features physical_device_maintenance_4_features_;
    VkPhysicalDeviceMaintenance5Features physical_device_maintenance_5_features_;
    VkPhysicalDeviceMaintenance6Features physical_device_maintenance_6_features_;
    VkPhysicalDeviceShaderDrawParametersFeatures physical_device_shader_draw_parameter_features_;
    VkPhysicalDeviceShaderFloat16Int8Features physical_device_float_16_int_8_features_;
    VkPhysicalDeviceHostQueryResetFeatures physical_device_host_query_reset_features_;
    VkPhysicalDeviceDescriptorIndexingFeatures physical_device_descriptor_indexing_features_;
    VkPhysicalDeviceTimelineSemaphoreFeatures physical_device_timeline_semaphore_features_;
    VkPhysicalDevice8BitStorageFeatures physical_device_8_bit_storage_features_;
    VkPhysicalDeviceVulkanMemoryModelFeatures physical_device_vulkan_memory_model_features_;
    VkPhysicalDeviceShaderAtomicInt64Features physical_device_shader_atomic_int_64_features_;
    VkPhysicalDeviceScalarBlockLayoutFeatures physical_device_scalar_block_layout_features_;
    VkPhysicalDeviceUniformBufferStandardLayoutFeatures physical_device_uniform_buffer_standard_layout_features_;
    VkPhysicalDeviceBufferDeviceAddressFeatures physical_device_buffer_device_address_features_;
    VkPhysicalDeviceImagelessFramebufferFeatures physical_device_imageless_framebuffer_features_;
    VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures physical_device_separate_depth_stencil_layouts_features_;
    VkPhysicalDevicePipelineCreationCacheControlFeatures physical_device_pipeline_creation_cache_control_features_;
    VkPhysicalDeviceVulkan11Features physical_device_vulkan_11_features_;
    VkPhysicalDeviceVulkan12Features physical_device_vulkan_12_features_;
    VkPhysicalDeviceVulkan13Features physical_device_vulkan_13_features_;
    VkPhysicalDeviceVulkan14Features physical_device_vulkan_14_features_;
    VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures physical_device_zero_initialize_workgroup_memory_features_;
    VkPhysicalDeviceHostImageCopyFeatures physical_device_host_image_copy_features_;
    VkPhysicalDeviceVulkanSC10Features physical_device_vulkan_sc_10_features_;
    VkPhysicalDevicePipelineProtectedAccessFeatures physical_device_pipeline_protected_access_features_;
    VkPhysicalDeviceShaderIntegerDotProductFeatures physical_device_shader_integer_dot_product_features_;
    VkPhysicalDeviceDynamicRenderingFeatures physical_device_dynamic_rendering_features_;
    VkPhysicalDevicePipelineRobustnessFeatures physical_device_pipeline_robustness_features_;
    VkPhysicalDeviceShaderSubgroupRotateFeatures physical_device_shader_subgroup_rotate_features_;
    VkPhysicalDeviceShaderExpectAssumeFeatures physical_device_shader_expect_assume_features_;
    VkPhysicalDeviceShaderFloatControls2Features physical_device_shader_float_controls_2_features_;
    VkPhysicalDeviceDynamicRenderingLocalReadFeatures physical_device_dynamic_rendering_local_read_features_;

    // VK_EXT_texture_compression_astc_hdr structs
    VkPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT physical_device_texture_compression_astchdrfeatures_;

    // VK_EXT_astc_decode_mode structs
    VkPhysicalDeviceASTCDecodeFeaturesEXT physical_device_astcdecode_features_;

    // VK_EXT_discard_rectangles structs
    VkPhysicalDeviceDiscardRectanglePropertiesEXT physical_device_discard_rectangle_properties_;

    // VK_EXT_conservative_rasterization structs
    VkPhysicalDeviceConservativeRasterizationPropertiesEXT physical_device_conservative_rasterization_properties_;

    // VK_EXT_depth_clip_enable structs
    VkPhysicalDeviceDepthClipEnableFeaturesEXT physical_device_depth_clip_enable_features_;

    // VK_KHR_performance_query structs
    VkPhysicalDevicePerformanceQueryPropertiesKHR physical_device_performance_query_properties_;
    VkPhysicalDevicePerformanceQueryFeaturesKHR physical_device_performance_query_features_;

    // VK_EXT_sample_locations structs
    VkPhysicalDeviceSampleLocationsPropertiesEXT physical_device_sample_locations_properties_;

    // VK_EXT_blend_operation_advanced structs
    VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT physical_device_blend_operation_advanced_properties_;
    VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT physical_device_blend_operation_advanced_features_;

    // VK_EXT_external_memory_host structs
    VkPhysicalDeviceExternalMemoryHostPropertiesEXT physical_device_external_memory_host_properties_;

    // VK_KHR_shader_clock structs
    VkPhysicalDeviceShaderClockFeaturesKHR physical_device_shader_clock_features_;

    // VK_KHR_global_priority structs
    VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR physical_device_global_priority_query_features_;

    // VK_EXT_pci_bus_info structs
    VkPhysicalDevicePCIBusInfoPropertiesEXT physical_device_pcibus_info_properties_;

    // VK_KHR_shader_terminate_invocation structs
    VkPhysicalDeviceShaderTerminateInvocationFeaturesKHR physical_device_shader_terminate_invocation_features_;

    // VK_EXT_subgroup_size_control structs
    VkPhysicalDeviceSubgroupSizeControlPropertiesEXT physical_device_subgroup_size_control_properties_;
    VkPhysicalDeviceSubgroupSizeControlFeaturesEXT physical_device_subgroup_size_control_features_;

    // VK_KHR_fragment_shading_rate structs
    VkPhysicalDeviceFragmentShadingRatePropertiesKHR physical_device_fragment_shading_rate_properties_;
    VkPhysicalDeviceFragmentShadingRateFeaturesKHR physical_device_fragment_shading_rate_features_;

    // VK_EXT_shader_image_atomic_int64 structs
    VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT physical_device_shader_image_atomic_int_64_features_;

    // VK_EXT_fragment_shader_interlock structs
    VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT physical_device_fragment_shader_interlock_features_;

    // VK_EXT_ycbcr_image_arrays structs
    VkPhysicalDeviceYcbcrImageArraysFeaturesEXT physical_device_ycbcr_image_arrays_features_;

    // VK_EXT_line_rasterization structs
    VkPhysicalDeviceLineRasterizationPropertiesEXT physical_device_line_rasterization_properties_;
    VkPhysicalDeviceLineRasterizationFeaturesEXT physical_device_line_rasterization_features_;

    // VK_EXT_shader_atomic_float structs
    VkPhysicalDeviceShaderAtomicFloatFeaturesEXT physical_device_shader_atomic_float_features_;

    // VK_EXT_index_type_uint8 structs
    VkPhysicalDeviceIndexTypeUint8FeaturesEXT physical_device_index_type_uint_8_features_;

    // VK_EXT_extended_dynamic_state structs
    VkPhysicalDeviceExtendedDynamicStateFeaturesEXT physical_device_extended_dynamic_state_features_;

    // VK_EXT_shader_demote_to_helper_invocation structs
    VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT physical_device_shader_demote_to_helper_invocation_features_;

    // VK_EXT_texel_buffer_alignment structs
    VkPhysicalDeviceTexelBufferAlignmentPropertiesEXT physical_device_texel_buffer_alignment_properties_;
    VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT physical_device_texel_buffer_alignment_features_;

    // VK_EXT_robustness2 structs
    VkPhysicalDeviceRobustness2PropertiesEXT physical_device_robustness_2_properties_;
    VkPhysicalDeviceRobustness2FeaturesEXT physical_device_robustness_2_features_;

    // VK_EXT_custom_border_color structs
    VkPhysicalDeviceCustomBorderColorPropertiesEXT physical_device_custom_border_color_properties_;
    VkPhysicalDeviceCustomBorderColorFeaturesEXT physical_device_custom_border_color_features_;

    // VK_KHR_synchronization2 structs
    VkPhysicalDeviceSynchronization2FeaturesKHR physical_device_synchronization_2_features_;

    // VK_EXT_ycbcr_2plane_444_formats structs
    VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT physical_device_ycbcr_2_plane_444_formats_features_;

    // VK_EXT_image_robustness structs
    VkPhysicalDeviceImageRobustnessFeaturesEXT physical_device_image_robustness_features_;

    // VK_EXT_4444_formats structs
    VkPhysicalDevice4444FormatsFeaturesEXT physical_device_4444_formats_features_;

    // VK_EXT_vertex_input_dynamic_state structs
    VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT physical_device_vertex_input_dynamic_state_features_;

    // VK_NV_external_sci_sync structs
#ifdef VK_USE_PLATFORM_SCI
    VkPhysicalDeviceExternalSciSyncFeaturesNV physical_device_external_sci_sync_features_;
#endif // VK_USE_PLATFORM_SCI

    // VK_NV_external_memory_sci_buf structs
#ifdef VK_USE_PLATFORM_SCI
    VkPhysicalDeviceExternalMemorySciBufFeaturesNV physical_device_external_memory_sci_buf_features_;
#endif // VK_USE_PLATFORM_SCI

    // VK_EXT_extended_dynamic_state2 structs
    VkPhysicalDeviceExtendedDynamicState2FeaturesEXT physical_device_extended_dynamic_state_2_features_;

    // VK_EXT_color_write_enable structs
    VkPhysicalDeviceColorWriteEnableFeaturesEXT physical_device_color_write_enable_features_;

    // VK_NV_external_sci_sync2 structs
#ifdef VK_USE_PLATFORM_SCI
    VkPhysicalDeviceExternalSciSync2FeaturesNV physical_device_external_sci_sync_2_features_;
#endif // VK_USE_PLATFORM_SCI

    // VK_KHR_vertex_attribute_divisor structs
    VkPhysicalDeviceVertexAttributeDivisorPropertiesKHR physical_device_vertex_attribute_divisor_properties_;
    VkPhysicalDeviceVertexAttributeDivisorFeaturesKHR physical_device_vertex_attribute_divisor_features_;

    // VK_QNX_external_memory_screen_buffer structs
#ifdef VK_USE_PLATFORM_SCREEN_QNX
    VkPhysicalDeviceExternalMemoryScreenBufferFeaturesQNX physical_device_external_memory_screen_buffer_features_;
#endif // VK_USE_PLATFORM_SCREEN_QNX

    PhysicalDeviceData(VkInstance instance) : instance_(instance) {
        physical_device_properties_ = {};
        physical_device_features_ = {};
        physical_device_memory_properties_ = {};
        surface_capabilities_ = {};

        vulkan_1_1_properties_written_ = false;
        vulkan_1_2_properties_written_ = false;
        vulkan_1_3_properties_written_ = false;
        vulkan_1_4_properties_written_ = false;

        vulkan_1_1_features_written_ = false;
        vulkan_1_2_features_written_ = false;
        vulkan_1_3_features_written_ = false;
        vulkan_1_4_features_written_ = false;

        // Core properties
        physical_device_push_descriptor_properties_ = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES };
        physical_device_driver_properties_ = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES };
        physical_device_idproperties_ = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES };
        physical_device_multiview_properties_ = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES };
        physical_device_subgroup_properties_ = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES };
        physical_device_point_clipping_properties_ = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES };
        physical_device_protected_memory_properties_ = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES };
        physical_device_sampler_filter_minmax_properties_ = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES };
        physical_device_inline_uniform_block_properties_ = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES };
        physical_device_maintenance_3_properties_ = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES };
        physical_device_maintenance_4_properties_ = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_PROPERTIES };
        physical_device_maintenance_5_properties_ = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_PROPERTIES };
        physical_device_maintenance_6_properties_ = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_6_PROPERTIES };
        physical_device_float_controls_properties_ = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES };
        physical_device_descriptor_indexing_properties_ = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES };
        physical_device_timeline_semaphore_properties_ = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES };
        physical_device_depth_stencil_resolve_properties_ = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES };
        physical_device_vulkan_11_properties_ = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES };
        physical_device_vulkan_12_properties_ = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES };
        physical_device_vulkan_13_properties_ = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES };
        physical_device_vulkan_14_properties_ = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_4_PROPERTIES };
        physical_device_host_image_copy_properties_ = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_IMAGE_COPY_PROPERTIES };
        physical_device_vulkan_sc_10_properties_ = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_SC_1_0_PROPERTIES };
        physical_device_shader_integer_dot_product_properties_ = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_PROPERTIES };
        physical_device_pipeline_robustness_properties_ = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_PROPERTIES };

        // Core features
        physical_device_private_data_features_ = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIVATE_DATA_FEATURES };
        physical_device_variable_pointer_features_ = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES };
        physical_device_multiview_features_ = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES };
        physical_device_16_bit_storage_features_ = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES };
        physical_device_shader_subgroup_extended_types_features_ = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES };
        physical_device_sampler_ycbcr_conversion_features_ = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES };
        physical_device_protected_memory_features_ = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES };
        physical_device_inline_uniform_block_features_ = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES };
        physical_device_maintenance_4_features_ = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_FEATURES };
        physical_device_maintenance_5_features_ = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_FEATURES };
        physical_device_maintenance_6_features_ = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_6_FEATURES };
        physical_device_shader_draw_parameter_features_ = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES };
        physical_device_float_16_int_8_features_ = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES };
        physical_device_host_query_reset_features_ = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES };
        physical_device_descriptor_indexing_features_ = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES };
        physical_device_timeline_semaphore_features_ = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES };
        physical_device_8_bit_storage_features_ = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES };
        physical_device_vulkan_memory_model_features_ = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES };
        physical_device_shader_atomic_int_64_features_ = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES };
        physical_device_scalar_block_layout_features_ = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES };
        physical_device_uniform_buffer_standard_layout_features_ = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES };
        physical_device_buffer_device_address_features_ = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES };
        physical_device_imageless_framebuffer_features_ = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES };
        physical_device_separate_depth_stencil_layouts_features_ = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES };
        physical_device_pipeline_creation_cache_control_features_ = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES };
        physical_device_vulkan_11_features_ = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES };
        physical_device_vulkan_12_features_ = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES };
        physical_device_vulkan_13_features_ = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES };
        physical_device_vulkan_14_features_ = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_4_FEATURES };
        physical_device_zero_initialize_workgroup_memory_features_ = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_WORKGROUP_MEMORY_FEATURES };
        physical_device_host_image_copy_features_ = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_IMAGE_COPY_FEATURES };
        physical_device_vulkan_sc_10_features_ = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_SC_1_0_FEATURES };
        physical_device_pipeline_protected_access_features_ = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_PROTECTED_ACCESS_FEATURES };
        physical_device_shader_integer_dot_product_features_ = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_FEATURES };
        physical_device_dynamic_rendering_features_ = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_FEATURES };
        physical_device_pipeline_robustness_features_ = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_FEATURES };
        physical_device_shader_subgroup_rotate_features_ = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_ROTATE_FEATURES };
        physical_device_shader_expect_assume_features_ = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EXPECT_ASSUME_FEATURES };
        physical_device_shader_float_controls_2_features_ = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT_CONTROLS_2_FEATURES };
        physical_device_dynamic_rendering_local_read_features_ = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_LOCAL_READ_FEATURES };

        // VK_EXT_texture_compression_astc_hdr structs
        physical_device_texture_compression_astchdrfeatures_ = {VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES_EXT};

        // VK_EXT_astc_decode_mode structs
        physical_device_astcdecode_features_ = {VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT};

        // VK_EXT_discard_rectangles structs
        physical_device_discard_rectangle_properties_ = {VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT};

        // VK_EXT_conservative_rasterization structs
        physical_device_conservative_rasterization_properties_ = {VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT};

        // VK_EXT_depth_clip_enable structs
        physical_device_depth_clip_enable_features_ = {VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT};

        // VK_KHR_performance_query structs
        physical_device_performance_query_properties_ = {VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_PROPERTIES_KHR};
        physical_device_performance_query_features_ = {VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_FEATURES_KHR};

        // VK_EXT_sample_locations structs
        physical_device_sample_locations_properties_ = {VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT};

        // VK_EXT_blend_operation_advanced structs
        physical_device_blend_operation_advanced_properties_ = {VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT};
        physical_device_blend_operation_advanced_features_ = {VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT};

        // VK_EXT_external_memory_host structs
        physical_device_external_memory_host_properties_ = {VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT};

        // VK_KHR_shader_clock structs
        physical_device_shader_clock_features_ = {VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR};

        // VK_KHR_global_priority structs
        physical_device_global_priority_query_features_ = {VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES_KHR};

        // VK_EXT_pci_bus_info structs
        physical_device_pcibus_info_properties_ = {VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT};

        // VK_KHR_shader_terminate_invocation structs
        physical_device_shader_terminate_invocation_features_ = {VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TERMINATE_INVOCATION_FEATURES_KHR};

        // VK_EXT_subgroup_size_control structs
        physical_device_subgroup_size_control_properties_ = {VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_PROPERTIES_EXT};
        physical_device_subgroup_size_control_features_ = {VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES_EXT};

        // VK_KHR_fragment_shading_rate structs
        physical_device_fragment_shading_rate_properties_ = {VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_PROPERTIES_KHR};
        physical_device_fragment_shading_rate_features_ = {VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_FEATURES_KHR};

        // VK_EXT_shader_image_atomic_int64 structs
        physical_device_shader_image_atomic_int_64_features_ = {VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_ATOMIC_INT64_FEATURES_EXT};

        // VK_EXT_fragment_shader_interlock structs
        physical_device_fragment_shader_interlock_features_ = {VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT};

        // VK_EXT_ycbcr_image_arrays structs
        physical_device_ycbcr_image_arrays_features_ = {VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT};

        // VK_EXT_line_rasterization structs
        physical_device_line_rasterization_properties_ = {VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_PROPERTIES_EXT};
        physical_device_line_rasterization_features_ = {VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_EXT};

        // VK_EXT_shader_atomic_float structs
        physical_device_shader_atomic_float_features_ = {VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_FEATURES_EXT};

        // VK_EXT_index_type_uint8 structs
        physical_device_index_type_uint_8_features_ = {VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES_EXT};

        // VK_EXT_extended_dynamic_state structs
        physical_device_extended_dynamic_state_features_ = {VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_FEATURES_EXT};

        // VK_EXT_shader_demote_to_helper_invocation structs
        physical_device_shader_demote_to_helper_invocation_features_ = {VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES_EXT};

        // VK_EXT_texel_buffer_alignment structs
        physical_device_texel_buffer_alignment_properties_ = {VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES_EXT};
        physical_device_texel_buffer_alignment_features_ = {VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT};

        // VK_EXT_robustness2 structs
        physical_device_robustness_2_properties_ = {VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_PROPERTIES_EXT};
        physical_device_robustness_2_features_ = {VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_EXT};

        // VK_EXT_custom_border_color structs
        physical_device_custom_border_color_properties_ = {VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_PROPERTIES_EXT};
        physical_device_custom_border_color_features_ = {VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_FEATURES_EXT};

        // VK_KHR_synchronization2 structs
        physical_device_synchronization_2_features_ = {VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SYNCHRONIZATION_2_FEATURES_KHR};

        // VK_EXT_ycbcr_2plane_444_formats structs
        physical_device_ycbcr_2_plane_444_formats_features_ = {VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_2_PLANE_444_FORMATS_FEATURES_EXT};

        // VK_EXT_image_robustness structs
        physical_device_image_robustness_features_ = {VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES_EXT};

        // VK_EXT_4444_formats structs
        physical_device_4444_formats_features_ = {VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_4444_FORMATS_FEATURES_EXT};

        // VK_EXT_vertex_input_dynamic_state structs
        physical_device_vertex_input_dynamic_state_features_ = {VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_INPUT_DYNAMIC_STATE_FEATURES_EXT};

        // VK_NV_external_sci_sync structs
#ifdef VK_USE_PLATFORM_SCI
        physical_device_external_sci_sync_features_ = {VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SCI_SYNC_FEATURES_NV};
#endif // VK_USE_PLATFORM_SCI

        // VK_NV_external_memory_sci_buf structs
#ifdef VK_USE_PLATFORM_SCI
        physical_device_external_memory_sci_buf_features_ = {VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_SCI_BUF_FEATURES_NV};
#endif // VK_USE_PLATFORM_SCI

        // VK_EXT_extended_dynamic_state2 structs
        physical_device_extended_dynamic_state_2_features_ = {VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_2_FEATURES_EXT};

        // VK_EXT_color_write_enable structs
        physical_device_color_write_enable_features_ = {VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COLOR_WRITE_ENABLE_FEATURES_EXT};

        // VK_NV_external_sci_sync2 structs
#ifdef VK_USE_PLATFORM_SCI
        physical_device_external_sci_sync_2_features_ = {VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SCI_SYNC_2_FEATURES_NV};
#endif // VK_USE_PLATFORM_SCI

        // VK_KHR_vertex_attribute_divisor structs
        physical_device_vertex_attribute_divisor_properties_ = {VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_KHR};
        physical_device_vertex_attribute_divisor_features_ = {VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_KHR};

        // VK_QNX_external_memory_screen_buffer structs
#ifdef VK_USE_PLATFORM_SCREEN_QNX
        physical_device_external_memory_screen_buffer_features_ = {VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_SCREEN_BUFFER_FEATURES_QNX};
#endif // VK_USE_PLATFORM_SCREEN_QNX
    }
    PhysicalDeviceData(const PhysicalDeviceData &) = delete;
    PhysicalDeviceData &operator=(const PhysicalDeviceData &) = delete;
  private:

    const VkInstance instance_;

    typedef std::unordered_map<VkPhysicalDevice, PhysicalDeviceData> Map;
    static Map& map() {
        static Map map_;
        return map_;
    }
};


// Loader for Profiles JSON configuration files ////////////////////////////////////////////////////////////////////////////////////

class JsonLoader {
   public:
    JsonLoader()
        : layer_settings{},
          pdd_(nullptr),
          profile_api_version_(0),
          excluded_extensions_(),
          excluded_formats_()
    {}
    JsonLoader(const JsonLoader &) = delete;
    JsonLoader &operator=(const JsonLoader &rhs) = delete;

    static JsonLoader &Create() {
        VkInstance temporary = VK_NULL_HANDLE;
        const auto result = profile_map().emplace(std::piecewise_construct, std::make_tuple(temporary), std::make_tuple());
        assert(result.second);  // true=insertion, false=replacement
        auto iter = result.first;
        JsonLoader *profile = &iter->second;
        return *profile;
    }

    static void Store(VkInstance instance) {
        auto nh = profile_map().extract(VK_NULL_HANDLE);
        nh.key() = instance;
        profile_map().insert(std::move(nh));
    }

    static JsonLoader *Find(VkInstance instance) {
        const auto iter = profile_map().find(instance);
        return (iter != profile_map().end()) ? &iter->second : nullptr;
    }

    static void Destroy(VkInstance instance) {
        profile_map().erase(instance);
    }

    void LogFoundProfiles();
    const Json::Value& FindRootFromProfileName(const std::string& profile_name) const;
    VkResult LoadProfilesDatabase();
    VkResult LoadFile(const std::string& filename);
    void ReadProfileApiVersion();
    VkResult LoadDevice(const char* device_name, PhysicalDeviceData *pdd);
    VkResult ReadProfile(const char* device_name, const Json::Value& root, const std::vector<std::vector<std::string>> &capabilities, bool requested_profile, bool enable_warnings);
    uint32_t GetProfileApiVersion() const { return profile_api_version_; }
    void CollectProfiles(const std::string& profile_name, std::vector<std::string>& results) const;

    ProfileLayerSettings layer_settings;

   private:
    PhysicalDeviceData *pdd_;

    std::map<std::string, Json::Value> profiles_file_roots_;

    std::uint32_t profile_api_version_;
    std::vector<std::string> excluded_extensions_;
    std::vector<std::string> excluded_formats_;

    struct Extension {
        std::string name;
        int specVersion;
    };

    enum ExtensionSupport {
        UNSUPPORTED,
        EXCLUDED,
        SUPPORTED,
    };

    bool WarnDuplicatedFeature(const Json::Value &parent);
    bool WarnDuplicatedProperty(const Json::Value &parent);
    bool GetFeature(const char *device_name, bool requested_profile, const Json::Value &features, const std::string &name);
    bool GetProperty(const char *device_name, bool requested_profile, const Json::Value &props, const std::string &name);
    bool GetFormat(const char *device_name, bool requested_profile, const Json::Value &formats, const std::string &format_name, MapOfVkFormatProperties *dest,
                   MapOfVkFormatProperties3 *dest3);
    bool CheckVersionSupport(uint32_t version, const std::string &name);
    ExtensionSupport CheckExtensionSupport(const char *extension, const std::string &name);
    bool valid(ExtensionSupport support);
    bool GetQueueFamilyProperties(const char* device_name, const Json::Value &qf_props, QueueFamilyProperties *dest);
    bool OrderQueueFamilyProperties(ArrayOfVkQueueFamilyProperties *qfp);
    void AddPromotedExtensions(uint32_t api_level);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDevicePushDescriptorProperties *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceDriverProperties *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceIDProperties *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceMultiviewProperties *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceSubgroupProperties *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDevicePointClippingProperties *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceProtectedMemoryProperties *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceSamplerFilterMinmaxProperties *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceInlineUniformBlockProperties *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceMaintenance3Properties *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceMaintenance4Properties *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceMaintenance5Properties *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceMaintenance6Properties *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceFloatControlsProperties *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceDescriptorIndexingProperties *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceTimelineSemaphoreProperties *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceDepthStencilResolveProperties *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceVulkan11Properties *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceVulkan12Properties *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceVulkan13Properties *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceVulkan14Properties *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceHostImageCopyProperties *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceVulkanSC10Properties *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceShaderIntegerDotProductProperties *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDevicePipelineRobustnessProperties *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDevicePrivateDataFeatures *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceVariablePointerFeatures *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceMultiviewFeatures *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDevice16BitStorageFeatures *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceSamplerYcbcrConversionFeatures *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceProtectedMemoryFeatures *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceInlineUniformBlockFeatures *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceMaintenance4Features *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceMaintenance5Features *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceMaintenance6Features *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceShaderDrawParameterFeatures *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceShaderFloat16Int8Features *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceHostQueryResetFeatures *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceDescriptorIndexingFeatures *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceTimelineSemaphoreFeatures *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDevice8BitStorageFeatures *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceVulkanMemoryModelFeatures *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceShaderAtomicInt64Features *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceScalarBlockLayoutFeatures *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceUniformBufferStandardLayoutFeatures *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceBufferDeviceAddressFeatures *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceImagelessFramebufferFeatures *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDevicePipelineCreationCacheControlFeatures *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceVulkan11Features *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceVulkan12Features *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceVulkan13Features *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceVulkan14Features *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceHostImageCopyFeatures *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceVulkanSC10Features *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDevicePipelineProtectedAccessFeatures *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceShaderIntegerDotProductFeatures *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceDynamicRenderingFeatures *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDevicePipelineRobustnessFeatures *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceShaderSubgroupRotateFeatures *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceShaderExpectAssumeFeatures *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceShaderFloatControls2Features *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceDynamicRenderingLocalReadFeatures *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceASTCDecodeFeaturesEXT *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceDiscardRectanglePropertiesEXT *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceConservativeRasterizationPropertiesEXT *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceDepthClipEnableFeaturesEXT *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDevicePerformanceQueryPropertiesKHR *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDevicePerformanceQueryFeaturesKHR *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceSampleLocationsPropertiesEXT *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceExternalMemoryHostPropertiesEXT *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceShaderClockFeaturesKHR *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDevicePCIBusInfoPropertiesEXT *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceShaderTerminateInvocationFeaturesKHR *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceSubgroupSizeControlPropertiesEXT *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceSubgroupSizeControlFeaturesEXT *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceFragmentShadingRatePropertiesKHR *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceFragmentShadingRateFeaturesKHR *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceYcbcrImageArraysFeaturesEXT *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceLineRasterizationPropertiesEXT *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceLineRasterizationFeaturesEXT *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceShaderAtomicFloatFeaturesEXT *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceIndexTypeUint8FeaturesEXT *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceExtendedDynamicStateFeaturesEXT *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceTexelBufferAlignmentPropertiesEXT *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceRobustness2PropertiesEXT *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceRobustness2FeaturesEXT *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceCustomBorderColorPropertiesEXT *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceCustomBorderColorFeaturesEXT *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceSynchronization2FeaturesKHR *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceImageRobustnessFeaturesEXT *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDevice4444FormatsFeaturesEXT *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT *dest);
#ifdef VK_USE_PLATFORM_SCI
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceExternalSciSyncFeaturesNV *dest);
#endif // VK_USE_PLATFORM_SCI
#ifdef VK_USE_PLATFORM_SCI
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceExternalMemorySciBufFeaturesNV *dest);
#endif // VK_USE_PLATFORM_SCI
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceExtendedDynamicState2FeaturesEXT *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceColorWriteEnableFeaturesEXT *dest);
#ifdef VK_USE_PLATFORM_SCI
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceExternalSciSync2FeaturesNV *dest);
#endif // VK_USE_PLATFORM_SCI
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceVertexAttributeDivisorPropertiesKHR *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceVertexAttributeDivisorFeaturesKHR *dest);
#ifdef VK_USE_PLATFORM_SCREEN_QNX
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceExternalMemoryScreenBufferFeaturesQNX *dest);
#endif // VK_USE_PLATFORM_SCREEN_QNX
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceFeatures *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDevicePortabilitySubsetFeaturesKHR *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceProperties *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceLimits *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceSparseProperties *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceToolProperties *dest);
    bool GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDevicePortabilitySubsetPropertiesKHR *dest);

    static bool WarnIfNotEqualFloat(ProfileLayerSettings *layer_settings, bool enable_warnings, const char* device_name, const char *cap_name, const float new_value, const float old_value, const bool not_modifiable) {
        if (std::abs(new_value - old_value) > 0.0001f) {
            if (enable_warnings) {
                if (not_modifiable) {
                    LogMessage(layer_settings, DEBUG_REPORT_WARNING_BIT,
                        "'%s' is not modifiable but the profile value (%3.2f) is different from the device (%s) value (%3.2f)\n", cap_name, new_value, device_name, old_value);
                } else {
                    LogMessage(layer_settings, DEBUG_REPORT_WARNING_BIT,
                        "'%s' profile value (%3.2f) is different from the device (%s) supported value (%3.2f)\n", cap_name, new_value, device_name, old_value);
                }
            }
            return true;
        }
        return false;
    }

    static bool WarnIfNotEqualBool(ProfileLayerSettings *layer_settings, bool enable_warnings, const char* device_name, const char *cap_name, const bool new_value, const bool old_value, const bool not_modifiable) {
        if (new_value != old_value) {
            if (enable_warnings) {
                if (not_modifiable) {
                    LogMessage(layer_settings, DEBUG_REPORT_WARNING_BIT,
                        "'%s' is not modifiable but the profile value (%s) is different from the device (%s) value (%s)\n", cap_name, new_value ? "true" : "false", device_name, old_value ? "true" : "false");
                } else if (new_value) {
                    LogMessage(layer_settings, DEBUG_REPORT_WARNING_BIT,
                        "'%s' profile value is enabled in the profile, but the device (%s) does not support it\n", cap_name, device_name);
                }
            }
            return true;
        }
        return false;
    }

    static bool WarnIfNotEqualEnum(ProfileLayerSettings *layer_settings, bool enable_warnings, const char* device_name, const char *cap_name, const uint32_t new_value, const uint32_t old_value, const bool not_modifiable) {
        if (new_value != old_value) {
            if (enable_warnings) {
                if (not_modifiable) {
                    LogMessage(layer_settings, DEBUG_REPORT_WARNING_BIT,
                        "'%s' is not modifiable but the profile value (%" PRIu32 ") is different from the device (%s) value (%" PRIu32 ")\n", cap_name, new_value, device_name, old_value);
                } else {
                    LogMessage(layer_settings, DEBUG_REPORT_WARNING_BIT,
                        "'%s' profile value (%" PRIu32 ") is different from the device (%s) value (%" PRIu32 ")\n", cap_name, new_value, device_name, old_value);
                }
            }
            return true;
        }
        return false;
    }

    static bool WarnIfNotEqual(ProfileLayerSettings *layer_settings, bool enable_warnings, const char* device_name, const char *cap_name, const uint32_t new_value, const uint32_t old_value, const bool not_modifiable) {
        if (new_value != old_value) {
            if (enable_warnings) {
                if (not_modifiable) {
                    LogMessage(layer_settings, DEBUG_REPORT_WARNING_BIT,
                        "'%s' is not modifiable but the profile value (%" PRIu32 ") is different from the device (%s) value (%" PRIu32 ")\n", cap_name, new_value, device_name, old_value);
                } else {
                    LogMessage(layer_settings, DEBUG_REPORT_WARNING_BIT,
                        "'%s' profile value (%" PRIu32 ") is different from the device (%s) value (%" PRIu32 ")\n", cap_name, new_value, device_name, old_value);
                }
            }
            return true;
        }
        return false;
    }

    static bool WarnIfNotEqual32u(ProfileLayerSettings *layer_settings, bool enable_warnings, const char* device_name, const char *cap_name, const uint32_t new_value, const uint32_t old_value, const bool not_modifiable) {
        if (new_value != old_value) {
            if (enable_warnings) {
                if (not_modifiable) {
                    LogMessage(layer_settings, DEBUG_REPORT_WARNING_BIT,
                        "'%s' is not modifiable but the profile value (%" PRIu32 ") is different from the device (%s) value (%" PRIu32 ")\n", cap_name, new_value, device_name, old_value);
                } else {
                    LogMessage(layer_settings, DEBUG_REPORT_WARNING_BIT,
                        "'%s' profile value (%" PRIu32 ") is different from the device (%s) value (%" PRIu32 ")\n", cap_name, new_value, device_name, old_value);
                }
            }
            return true;
        }
        return false;
    }

    static bool WarnIfNotEqual(ProfileLayerSettings *layer_settings, bool enable_warnings, const char* device_name, const char *cap_name, const int32_t new_value, const int32_t old_value, const bool not_modifiable) {
        if (new_value != old_value) {
            if (enable_warnings) {
                if (not_modifiable) {
                    LogMessage(layer_settings, DEBUG_REPORT_WARNING_BIT,
                        "'%s' is not modifiable but the profile value (%" PRIi32 ") is different from the device (%s) value (%" PRIi32 ")\n", cap_name, new_value, device_name, old_value);
                } else {
                    LogMessage(layer_settings, DEBUG_REPORT_WARNING_BIT,
                        "'%s' profile value (%" PRIi32 ") is different from the device (%s) value (%" PRIi32 ")\n", cap_name, new_value, device_name, old_value);
                }
            }
            return true;
        }
        return false;
    }

    static bool WarnIfNotEqual64u(ProfileLayerSettings *layer_settings, bool enable_warnings, const char* device_name, const char *cap_name, const uint64_t new_value, const uint64_t old_value, const bool not_modifiable) {
        if (new_value != old_value) {
            if (enable_warnings) {
                if (not_modifiable) {
                    LogMessage(layer_settings, DEBUG_REPORT_WARNING_BIT,
                        "'%s' is not modifiable but the profile value (%" PRIu64 ") is different from the device (%s) value (%" PRIu64 ")\n", cap_name, new_value, device_name, old_value);
                } else {
                    LogMessage(layer_settings, DEBUG_REPORT_WARNING_BIT,
                        "'%s' profile value (%" PRIu64 ") is different from the device (%s) value (%" PRIu64 ")\n", cap_name, new_value, device_name, old_value);
                }
            }
            return true;
        }
        return false;
    }

    static bool WarnIfNotEquali64(ProfileLayerSettings *layer_settings, bool enable_warnings, const char* device_name, const char *cap_name, const int64_t new_value, const int64_t old_value, const bool not_modifiable) {
        if (new_value != old_value) {
            if (enable_warnings) {
                if (not_modifiable) {
                    LogMessage(layer_settings, DEBUG_REPORT_WARNING_BIT,
                        "'%s' is not modifiable but the profile value (%" PRIi64 ") is different from the device (%s) value (%" PRIi64 ")\n", cap_name, new_value, device_name, old_value);
                } else {
                    LogMessage(layer_settings, DEBUG_REPORT_WARNING_BIT,
                        "'%s' profile value (%" PRIi64 ") is different from the device (%s) value (%" PRIi64 ")\n", cap_name, new_value, device_name, old_value);
                }
            }
            return true;
        }
        return false;
    }

    static bool WarnIfNotEqualSizet(ProfileLayerSettings *layer_settings, bool enable_warnings, const char* device_name, const char *cap_name, const size_t new_value, const size_t old_value, const bool not_modifiable) {
        if (new_value != old_value) {
            if (enable_warnings) {
                if (not_modifiable) {
                    LogMessage(layer_settings, DEBUG_REPORT_WARNING_BIT,
                        "'%s' is not modifiable but the profile value (%" PRIuLEAST64 ") is different from the device (%s) value (%" PRIuLEAST64 ")\n", cap_name, new_value, device_name, old_value);
                } else {
                    LogMessage(layer_settings, DEBUG_REPORT_WARNING_BIT,
                        "'%s' profile value (%" PRIuLEAST64 ") is different from the device (%s) value (%" PRIuLEAST64 ")\n", cap_name, new_value, device_name, old_value);
                }
            }
            return true;
        }
        return false;
    }

    static bool WarnIfMissingBit(ProfileLayerSettings *layer_settings, bool enable_warnings, const char* device_name, const char *cap_name, const uint64_t new_value, const uint64_t old_value, const bool not_modifiable) {
        if ((old_value | new_value) != old_value) {
            if (enable_warnings) {
                if (not_modifiable) {
                    LogMessage(layer_settings, DEBUG_REPORT_WARNING_BIT,
                        "'%s' is not modifiable but the profile value (%" PRIu64 ") is different from the device (%s) value (%" PRIu64 ")\n", cap_name, new_value, device_name, old_value);
                } else {
                    LogMessage(layer_settings, DEBUG_REPORT_WARNING_BIT,
                        "'%s' profile value (%" PRIu64 ") has bits set that the device (%s) value (%" PRIu64 ") does not\n", cap_name, new_value, device_name, old_value);
                }
            }
            return true;
        }
        return false;
    }

    static bool WarnIfGreater(ProfileLayerSettings *layer_settings, bool enable_warnings, const char* device_name, const char *cap_name, const uint64_t new_value, const uint64_t old_value, const bool not_modifiable) {
        (void)not_modifiable;

        if (new_value > old_value) {
            if (enable_warnings) {
                LogMessage(layer_settings, DEBUG_REPORT_WARNING_BIT,
                    "'%s' profile value (%" PRIu64 ") is greater than device (%s) value (%" PRIu64 ")\n", cap_name, new_value, device_name, old_value);
            }
            return true;
        }
        return false;
    }

    static bool WarnIfGreaterSizet(ProfileLayerSettings *layer_settings, bool enable_warnings, const char* device_name, const char *cap_name, const size_t new_value, const size_t old_value, const bool not_modifiable) {
        (void)not_modifiable;

        if (new_value > old_value) {
            if (enable_warnings) {
                LogMessage(layer_settings, DEBUG_REPORT_WARNING_BIT,
                    "'%s' profile value (%" PRIuLEAST64 ") is greater than device (%s) value (%" PRIuLEAST64 ")\n", cap_name, new_value, device_name, old_value);
            }
            return true;
        }
        return false;
    }

    static bool WarnIfGreaterFloat(ProfileLayerSettings *layer_settings, bool enable_warnings, const char* device_name, const char *cap_name, const float new_value, const float old_value, const bool not_modifiable) {
        (void)not_modifiable;

        if (new_value > old_value) {
            if (enable_warnings) {
                LogMessage(layer_settings, DEBUG_REPORT_WARNING_BIT,
                    "'%s' profile value (%3.2f) is greater than device (%s) value (%3.2f)\n", cap_name, new_value, device_name, old_value);
            }
            return true;
        }
        return false;
    }

    static bool WarnIfLesser(ProfileLayerSettings *layer_settings, bool enable_warnings, const char* device_name, const char *cap_name, const uint64_t new_value, const uint64_t old_value, const bool not_modifiable) {
        (void)not_modifiable;

        if (new_value < old_value) {
            if (enable_warnings) {
                LogMessage(layer_settings, DEBUG_REPORT_WARNING_BIT,
                "'%s' profile value (%" PRIu64 ") is lesser than device (%s) value (%" PRIu64 ")\n", cap_name, new_value, device_name, old_value);
            }
            return true;
        }
        return false;
    }

    static bool WarnIfLesserSizet(ProfileLayerSettings *layer_settings, bool enable_warnings, const char* device_name, const char *cap_name, const size_t new_value, const size_t old_value, const bool not_modifiable) {
        (void)not_modifiable;

        if (new_value < old_value) {
            if (enable_warnings) {
                LogMessage(layer_settings, DEBUG_REPORT_WARNING_BIT,
                    "'%s' profile value (%" PRIuLEAST64 ") is lesser than device (%s) value (%" PRIuLEAST64 ")\n", cap_name, new_value, device_name, old_value);
            }
            return true;
        }
        return false;
    }

    static bool WarnIfLesserFloat(ProfileLayerSettings *layer_settings, bool enable_warnings, const char* device_name, const char *cap_name, const float new_value, const float old_value, const bool not_modifiable) {
        (void)not_modifiable;

        if (new_value < old_value) {
            if (enable_warnings) {
                LogMessage(layer_settings, DEBUG_REPORT_WARNING_BIT,
                    "'%s' profile value (%3.2f) is lesser than device (%s) value (%3.2f)\n", cap_name, new_value, device_name, old_value);
            }
            return true;
        }
        return false;
    }

    bool GetValue(const char* device_name, const Json::Value &parent, const std::string &member, const char *name, float *dest, bool not_modifiable, bool requested_profile,
                  std::function<bool(ProfileLayerSettings *, bool, const char *, const char *, float, float, bool)> warn_func = nullptr) {
        if (member != name) {
            return true;
        }
        // If the value is not modifiable and we don't warn, we can return immediately, we will use the native value
        if (not_modifiable && warn_func == nullptr) {
            return true;
        }

        const Json::Value value = parent[name];
        if (!value.isDouble()) {
            return true;
        }
        bool valid = true;
        const float new_value = value.asFloat();
        if (warn_func) {
            if (warn_func(&layer_settings, requested_profile, device_name, name, new_value, *dest, not_modifiable)) {
                valid = false;
            }
        }
        if (!not_modifiable) {
            *dest = new_value;
        }

        return valid;
    }

    bool GetValue(const char* device_name, const Json::Value &parent, const std::string &member, const char *name, uint8_t *dest, bool not_modifiable, bool requested_profile,
                  std::function<bool(ProfileLayerSettings *, bool, const char *, const char *, uint8_t, uint8_t, bool)> warn_func = nullptr) {
        if (member != name) {
            return true;
        }
        // If the value is not modifiable and we don't warn, we can return immediately, we will use the native value
        if (not_modifiable && warn_func == nullptr) {
            return true;
        }

        const Json::Value value = parent[name];
        bool valid = true;
        if (value.isBool()) {
            const bool new_value = value.asBool();
            if (warn_func) {
                if (warn_func(&layer_settings, requested_profile, device_name, name, new_value, *dest, not_modifiable)) {
                    valid = false;
                }
            }
            *dest = static_cast<uint8_t>(new_value);
        } else if (value.isArray()) {
            uint64_t sum_bits = 0;
            for (const auto &entry : value) {
                if (entry.isString()) {
                    sum_bits |= VkStringToUint64(entry.asString());
                }
            }
            if (!not_modifiable) {
                *dest = static_cast<uint8_t>(sum_bits);
            }
        } else if (value.isUInt()) {
            const uint8_t new_value = static_cast<uint8_t>(value.asUInt());
            if (warn_func) {
                if (warn_func(&layer_settings, requested_profile, device_name, name, new_value, *dest, not_modifiable)) {
                    valid = false;
                }
            }
            if (!not_modifiable) {
                *dest = static_cast<uint8_t>(new_value);
            }
        }
        return valid;
    }

    bool GetValue(const char* device_name, const Json::Value &parent, const std::string &member, const char *name, int32_t *dest, bool not_modifiable, bool requested_profile,
                  std::function<bool(ProfileLayerSettings *, bool, const char *, const char *, int32_t, int32_t, bool)> warn_func = nullptr) {
        if (member != name) {
            return true;
        }
        // If the value is not modifiable and we don't warn, we can return immediately, we will use the native value
        if (not_modifiable && warn_func == nullptr) {
            return true;
        }

        const Json::Value value = parent[name];
        if (!value.isInt()) {
            return true;
        }
        bool valid = true;
        const int32_t new_value = value.asInt();
        if (warn_func) {
            if (warn_func(&layer_settings, requested_profile, device_name, name, new_value, *dest, not_modifiable)) {
                valid = false;
            }
        }

        if (!not_modifiable) {
            *dest = new_value;
        }
        return valid;
    }

    bool GetValue(const char* device_name, const Json::Value &parent, const std::string &member, const char *name, int64_t *dest, bool not_modifiable, bool requested_profile,
                  std::function<bool(ProfileLayerSettings *, bool, const char *, const char *, int64_t, int64_t, bool)> warn_func = nullptr) {
        if (member != name) {
            return true;
        }
        // If the value is not modifiable and we don't warn, we can return immediately, we will use the native value
        if (not_modifiable && warn_func == nullptr) {
            return true;
        }

        const Json::Value value = parent[name];
        if (!value.isInt64()) {
            return true;
        }
        bool valid = true;
        const int64_t new_value = value.asInt64();
        if (warn_func) {
            if (warn_func(&layer_settings, requested_profile, device_name, name, new_value, *dest, not_modifiable)) {
                valid = false;
            }
        }

        if (!not_modifiable) {
            *dest = new_value;
        }
        return valid;
    }

    bool GetValue(const char* device_name, const Json::Value &parent, const std::string &member, const char *name, uint32_t *dest, bool not_modifiable, bool requested_profile,
                  std::function<bool(ProfileLayerSettings *, bool, const char *, const char *, uint32_t, uint32_t, bool)> warn_func = nullptr) {
        if (member != name) {
            return true;
        }
        // If the value is not modifiable and we don't warn, we can return immediately, we will use the native value
        if (not_modifiable && warn_func == nullptr) {
            return true;
        }

        const Json::Value value = parent[name];
        bool valid = true;
        if (value.isBool()) {
            const bool new_value = value.asBool();
            if (warn_func) {
                if (warn_func(&layer_settings, requested_profile, device_name, name, new_value, *dest, not_modifiable)) {
                    valid = false;
                }
            }

            if (!not_modifiable) {
                *dest = static_cast<uint32_t>(new_value);
            }
        } else if (value.isArray()) {
            uint64_t sum_bits = 0;
            for (const auto &entry : value) {
                if (entry.isString()) {
                    sum_bits |= VkStringToUint64(entry.asString());
                }
            }

            if (!not_modifiable) {
                *dest = static_cast<uint32_t>(sum_bits);
            }
        } else if (value.isUInt()) {
            const uint32_t new_value = value.asUInt();
            if (warn_func) {
                if (warn_func(&layer_settings, requested_profile, device_name, name, new_value, *dest, not_modifiable)) {
                    valid = false;
                }
            }

            if (!not_modifiable) {
                *dest = new_value;
            }
        }
        return valid;
    }

    bool GetValue(const char* device_name, const Json::Value &parent, const std::string &member, const char *name, uint64_t *dest, bool not_modifiable, bool requested_profile,
                  std::function<bool(ProfileLayerSettings *, bool, const char *, const char *, uint64_t, uint64_t, bool)> warn_func = nullptr) {
        if (member != name) {
            return true;
        }
        // If the value is not modifiable and we don't warn, we can return immediately, we will use the native value
        if (not_modifiable && warn_func == nullptr) {
            return true;
        }

        const Json::Value value = parent[name];
        if (!value.isUInt64()) {
            return true;
        }
        bool valid = true;
        const uint64_t new_value = value.asUInt64();
        if (warn_func) {
            if (warn_func(&layer_settings, requested_profile, device_name, name, new_value, *dest, not_modifiable)) {
                valid = false;
            }
        }

        if (!not_modifiable) {
            *dest = new_value;
        }
        return valid;
    }

    bool GetValue(const char* device_name, const Json::Value &pparent, const std::string &member, const char *name, VkExtent2D *dest, bool not_modifiable, bool requested_profile,
                  std::function<bool(ProfileLayerSettings *, bool, const char *, const char *, uint32_t, uint32_t, bool)> warn_func = nullptr) {
        if (member != name) {
            return true;
        }
        // If the value is not modifiable and we don't warn, we can return immediately, we will use the native value
        if (not_modifiable && warn_func == nullptr) {
            return true;
        }

        const Json::Value parent = pparent[name];
        if (parent.type() != Json::objectValue) {
            return true;
        }
        bool valid = true;
        for (const auto &prop : parent.getMemberNames()) {
            GET_VALUE_WARN(prop, width, not_modifiable, requested_profile, warn_func);
            GET_VALUE_WARN(prop, height, not_modifiable, requested_profile, warn_func);
        }
        return valid;
    }

    bool GetValue(const char* device_name, const Json::Value &pparent, const std::string &member, const char *name, VkExtent3D *dest, bool not_modifiable, bool requested_profile,
                  std::function<bool(ProfileLayerSettings *, bool, const char *, const char *, uint32_t, uint32_t, bool)> warn_func = nullptr) {
        if (member != name) {
            return true;
        }
        // If the value is not modifiable and we don't warn, we can return immediately, we will use the native value
        if (not_modifiable && warn_func == nullptr) {
            return true;
        }

        const Json::Value parent = pparent[name];
        if (parent.type() != Json::objectValue) {
            return true;
        }
        bool valid = true;
        for (const auto &prop : parent.getMemberNames()) {
            GET_VALUE_WARN(prop, width, not_modifiable, requested_profile, warn_func);
            GET_VALUE_WARN(prop, height, not_modifiable, requested_profile, warn_func);
            GET_VALUE_WARN(prop, depth, not_modifiable, requested_profile, warn_func);
        }
        return valid;
    }

    bool GetValueSizet(const char* device_name, const Json::Value &parent, const std::string &member, const char *name, size_t *dest, bool not_modifiable, bool requested_profile,
                       std::function<bool(ProfileLayerSettings *, bool, const char *, const char *, size_t, size_t, bool)> warn_func = nullptr) {
        if (member != name) {
            return true;
        }
        // If the value is not modifiable and we don't warn, we can return immediately, we will use the native value
        if (not_modifiable && warn_func == nullptr) {
            return true;
        }

        const Json::Value value = parent[name];
        bool valid = true;
        if (value.isUInt()) {
            const size_t new_value = value.asUInt();
            if (warn_func) {
                if (warn_func(&layer_settings, requested_profile, device_name, name, new_value, *dest, not_modifiable)) {
                    valid = false;
                }
            }

            if (!not_modifiable) {
                *dest = new_value;
            }
        }
        return valid;
    }

    template <typename T>  // for Vulkan enum types
    bool GetValueFlag(const char* device_name, const Json::Value &parent, const std::string &member, const char *name, T *dest, bool not_modifiable, bool requested_profile,
                      std::function<bool(ProfileLayerSettings *, bool, const char *, const char *, T, T, bool)> warn_func = nullptr) {
        if (member != name) {
            return true;
        }
        // If the value is not modifiable and we don't warn, we can return immediately, we will use the native value
        if (not_modifiable && warn_func == nullptr) {
            return true;
        }

        const Json::Value value = parent[name];
        bool valid = true;
        uint64_t new_value = 0;
        if (value.isArray()) {
            for (const auto &entry : value) {
                if (entry.isString()) {
                    new_value |= VkStringToUint64(entry.asString());
                }
            }
        }
        if (WarnIfMissingBit(&layer_settings, requested_profile, device_name, name, new_value, static_cast<uint64_t>(*dest), not_modifiable)) {
            valid = false;
        }

        if (!not_modifiable) {
            *dest = static_cast<T>(new_value);
        }
        return valid;
    }

    template <typename T>  // for Vulkan enum types
    bool GetValueEnum(const char* device_name, const Json::Value &parent, const std::string &member, const char *name, T *dest, bool not_modifiable, bool requested_profile,
                      std::function<bool(ProfileLayerSettings *, bool, const char *, const char *, uint32_t, uint32_t, bool)> warn_func = nullptr) {
        if (member != name) {
            return true;
        }
        // If the value is not modifiable and we don't warn, we can return immediately, we will use the native value
        if (not_modifiable && warn_func == nullptr) {
            return true;
        }

        const Json::Value value = parent[name];
        bool valid = true;
        uint32_t new_value = 0;
        if (value.isString()) {
            new_value = static_cast<T>(VkStringToUint64(value.asString()));
        }
        if (warn_func) {
            if (warn_func(&layer_settings, requested_profile, device_name, name, new_value, *dest, not_modifiable)) {
                valid = false;
            }
        } else {
            if (WarnIfNotEqualEnum(&layer_settings, requested_profile, device_name, name, new_value, *dest, not_modifiable)) {
                valid = false;
            }
        }

        if (!not_modifiable) {
            *dest = static_cast<T>(new_value);
        }
        return valid;
    }

    int GetArray(const char* device_name, const Json::Value &parent, const std::string &member, const char *name, uint8_t *dest, bool not_modifiable) {
        (void)device_name;

        if (member != name) {
            return -1;
        }

        const Json::Value value = parent[name];
        if (value.type() != Json::arrayValue) {
            return -1;
        }
        const int count = static_cast<int>(value.size());
        if (!not_modifiable) {
            for (int i = 0; i < count; ++i) {
                dest[i] = static_cast<uint8_t>(value[i].asUInt());
            }
        }
        return count;
    }

    int GetArray(const char* device_name, const Json::Value &parent, const std::string &member, const char *name, uint32_t *dest, bool not_modifiable) {
        (void)device_name;

        if (member != name) {
            return -1;
        }

        const Json::Value value = parent[name];
        if (value.type() != Json::arrayValue) {
            return -1;
        }
        const int count = static_cast<int>(value.size());
        if (!not_modifiable) {
            for (int i = 0; i < count; ++i) {
                dest[i] = static_cast<uint32_t>(value[i].asUInt());
            }
        }
        return count;
    }

    int GetArray(const char* device_name, const Json::Value &parent, const std::string &member, const char *name, float *dest, bool not_modifiable) {
        (void)device_name;

        if (member != name) {
            return -1;
        }

        const Json::Value value = parent[name];
        if (value.type() != Json::arrayValue) {
            return -1;
        }
        const int count = static_cast<int>(value.size());
        if (!not_modifiable) {
            for (int i = 0; i < count; ++i) {
                dest[i] = value[i].asFloat();
            }
        }
        return count;
    }

    int GetArray(const char* device_name, const Json::Value &parent, const std::string &member, const char *name, char *dest, bool not_modifiable) {
        (void)device_name;

        if (member != name) {
            return -1;
        }

        const Json::Value value = parent[name];
        if (!value.isString()) {
            return -1;
        }
        const char *new_value = value.asCString();
        int count = 0;
        if (!not_modifiable) {
            dest[0] = '\0';
            if (new_value) {
                count = static_cast<int>(strlen(new_value));
                strcpy(dest, new_value);
            }
        }
        return count;
    }

    int GetArray(const char* device_name, const Json::Value &parent, const std::string &member, const char *name, VkImageLayout *dest, uint32_t *destCount, bool not_modifiable) {
        (void)device_name;

        if (member != name) {
            return -1;
        }

        const Json::Value value = parent[name];
        if (value.type() != Json::arrayValue) {
            return -1;
        }
        const int count = static_cast<int>(value.size());
        if (!not_modifiable) {
            *destCount = static_cast<uint32_t>(count);
            for (int i = 0; i < count; ++i) {
                dest[i] = StringToImageLayout(value[i].asCString());
            }
        }
        return count;
    }

    typedef std::unordered_map<VkInstance, JsonLoader> ProfileMap;
    static ProfileMap& profile_map() {
        static ProfileMap profile_map_;
        return profile_map_;
    }
};

static bool IsASTCHDRFormat(VkFormat format) {
    switch (format) {
        case VK_FORMAT_ASTC_4x4_SFLOAT_BLOCK:
        case VK_FORMAT_ASTC_5x4_SFLOAT_BLOCK:
        case VK_FORMAT_ASTC_5x5_SFLOAT_BLOCK:
        case VK_FORMAT_ASTC_6x5_SFLOAT_BLOCK:
        case VK_FORMAT_ASTC_6x6_SFLOAT_BLOCK:
        case VK_FORMAT_ASTC_8x5_SFLOAT_BLOCK:
        case VK_FORMAT_ASTC_8x6_SFLOAT_BLOCK:
        case VK_FORMAT_ASTC_8x8_SFLOAT_BLOCK:
        case VK_FORMAT_ASTC_10x5_SFLOAT_BLOCK:
        case VK_FORMAT_ASTC_10x6_SFLOAT_BLOCK:
        case VK_FORMAT_ASTC_10x8_SFLOAT_BLOCK:
        case VK_FORMAT_ASTC_10x10_SFLOAT_BLOCK:
        case VK_FORMAT_ASTC_12x10_SFLOAT_BLOCK:
        case VK_FORMAT_ASTC_12x12_SFLOAT_BLOCK:
            return true;
        default:
            return false;
    }
}

static bool IsASTCLDRFormat(VkFormat format) {
    switch (format) {
        case VK_FORMAT_ASTC_4x4_UNORM_BLOCK:
        case VK_FORMAT_ASTC_4x4_SRGB_BLOCK:
        case VK_FORMAT_ASTC_5x4_UNORM_BLOCK:
        case VK_FORMAT_ASTC_5x4_SRGB_BLOCK:
        case VK_FORMAT_ASTC_5x5_UNORM_BLOCK:
        case VK_FORMAT_ASTC_5x5_SRGB_BLOCK:
        case VK_FORMAT_ASTC_6x5_UNORM_BLOCK:
        case VK_FORMAT_ASTC_6x5_SRGB_BLOCK:
        case VK_FORMAT_ASTC_6x6_UNORM_BLOCK:
        case VK_FORMAT_ASTC_6x6_SRGB_BLOCK:
        case VK_FORMAT_ASTC_8x5_UNORM_BLOCK:
        case VK_FORMAT_ASTC_8x5_SRGB_BLOCK:
        case VK_FORMAT_ASTC_8x6_UNORM_BLOCK:
        case VK_FORMAT_ASTC_8x6_SRGB_BLOCK:
        case VK_FORMAT_ASTC_8x8_UNORM_BLOCK:
        case VK_FORMAT_ASTC_8x8_SRGB_BLOCK:
        case VK_FORMAT_ASTC_10x5_UNORM_BLOCK:
        case VK_FORMAT_ASTC_10x5_SRGB_BLOCK:
        case VK_FORMAT_ASTC_10x6_UNORM_BLOCK:
        case VK_FORMAT_ASTC_10x6_SRGB_BLOCK:
        case VK_FORMAT_ASTC_10x8_UNORM_BLOCK:
        case VK_FORMAT_ASTC_10x8_SRGB_BLOCK:
        case VK_FORMAT_ASTC_10x10_UNORM_BLOCK:
        case VK_FORMAT_ASTC_10x10_SRGB_BLOCK:
        case VK_FORMAT_ASTC_12x10_UNORM_BLOCK:
        case VK_FORMAT_ASTC_12x10_SRGB_BLOCK:
        case VK_FORMAT_ASTC_12x12_UNORM_BLOCK:
        case VK_FORMAT_ASTC_12x12_SRGB_BLOCK:
            return true;
        default:
            return false;
    }
}

static bool IsBCFormat(VkFormat format) {
    switch (format) {
        case VK_FORMAT_BC1_RGB_UNORM_BLOCK:
        case VK_FORMAT_BC1_RGB_SRGB_BLOCK:
        case VK_FORMAT_BC1_RGBA_UNORM_BLOCK:
        case VK_FORMAT_BC1_RGBA_SRGB_BLOCK:
        case VK_FORMAT_BC2_UNORM_BLOCK:
        case VK_FORMAT_BC2_SRGB_BLOCK:
        case VK_FORMAT_BC3_UNORM_BLOCK:
        case VK_FORMAT_BC3_SRGB_BLOCK:
        case VK_FORMAT_BC4_UNORM_BLOCK:
        case VK_FORMAT_BC4_SNORM_BLOCK:
        case VK_FORMAT_BC5_UNORM_BLOCK:
        case VK_FORMAT_BC5_SNORM_BLOCK:
        case VK_FORMAT_BC6H_UFLOAT_BLOCK:
        case VK_FORMAT_BC6H_SFLOAT_BLOCK:
        case VK_FORMAT_BC7_UNORM_BLOCK:
        case VK_FORMAT_BC7_SRGB_BLOCK:
            return true;
        default:
            return false;
    }
}

static bool IsEACFormat(VkFormat format) {
    switch (format) {
        case VK_FORMAT_EAC_R11_UNORM_BLOCK:
        case VK_FORMAT_EAC_R11_SNORM_BLOCK:
        case VK_FORMAT_EAC_R11G11_UNORM_BLOCK:
        case VK_FORMAT_EAC_R11G11_SNORM_BLOCK:
            return true;
        default:
            return false;
    }
}

static bool IsETC2Format(VkFormat format) {
    switch (format) {
        case VK_FORMAT_ETC2_R8G8B8_UNORM_BLOCK:
        case VK_FORMAT_ETC2_R8G8B8_SRGB_BLOCK:
        case VK_FORMAT_ETC2_R8G8B8A1_UNORM_BLOCK:
        case VK_FORMAT_ETC2_R8G8B8A1_SRGB_BLOCK:
        case VK_FORMAT_ETC2_R8G8B8A8_UNORM_BLOCK:
        case VK_FORMAT_ETC2_R8G8B8A8_SRGB_BLOCK:
            return true;
        default:
            return false;
    }
}

static bool IsPVRTCFormat(VkFormat format) {
    switch (format) {
        case VK_FORMAT_PVRTC1_2BPP_UNORM_BLOCK_IMG:
        case VK_FORMAT_PVRTC1_4BPP_UNORM_BLOCK_IMG:
        case VK_FORMAT_PVRTC2_2BPP_UNORM_BLOCK_IMG:
        case VK_FORMAT_PVRTC2_4BPP_UNORM_BLOCK_IMG:
        case VK_FORMAT_PVRTC1_2BPP_SRGB_BLOCK_IMG:
        case VK_FORMAT_PVRTC1_4BPP_SRGB_BLOCK_IMG:
        case VK_FORMAT_PVRTC2_2BPP_SRGB_BLOCK_IMG:
        case VK_FORMAT_PVRTC2_4BPP_SRGB_BLOCK_IMG:
            return true;
        default:
            return false;
    }
}

bool JsonLoader::WarnDuplicatedFeature(const Json::Value &parent) {
    bool valid = true;
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDeviceExternalMemorySciBufFeaturesNV", "VkPhysicalDeviceExternalSciBufFeaturesNV"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDevicePrivateDataFeatures", "VkPhysicalDeviceVulkanSC10Features"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDeviceVariablePointersFeatures", "VkPhysicalDeviceVariablePointerFeatures", "VkPhysicalDeviceVulkanSC10Features"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDeviceMultiviewFeatures", "VkPhysicalDeviceVulkanSC10Features"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDevice16BitStorageFeatures", "VkPhysicalDeviceVulkanSC10Features"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures", "VkPhysicalDeviceVulkanSC10Features"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDeviceSamplerYcbcrConversionFeatures", "VkPhysicalDeviceVulkanSC10Features"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDeviceProtectedMemoryFeatures", "VkPhysicalDeviceVulkanSC10Features"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDeviceInlineUniformBlockFeatures", "VkPhysicalDeviceVulkanSC10Features"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDeviceMaintenance4Features", "VkPhysicalDeviceVulkanSC10Features"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDeviceMaintenance5Features", "VkPhysicalDeviceVulkanSC10Features"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDeviceMaintenance6Features", "VkPhysicalDeviceVulkanSC10Features"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDeviceShaderDrawParametersFeatures", "VkPhysicalDeviceShaderDrawParameterFeatures", "VkPhysicalDeviceVulkanSC10Features"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDeviceShaderFloat16Int8Features", "VkPhysicalDeviceVulkanSC10Features"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDeviceHostQueryResetFeatures", "VkPhysicalDeviceVulkanSC10Features"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDeviceGlobalPriorityQueryFeatures", "VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR", "VkPhysicalDeviceVulkanSC10Features"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDeviceDescriptorIndexingFeatures", "VkPhysicalDeviceVulkanSC10Features"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDeviceTimelineSemaphoreFeatures", "VkPhysicalDeviceVulkanSC10Features"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDevice8BitStorageFeatures", "VkPhysicalDeviceVulkanSC10Features"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDeviceVulkanMemoryModelFeatures", "VkPhysicalDeviceVulkanSC10Features"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDeviceShaderAtomicInt64Features", "VkPhysicalDeviceVulkanSC10Features"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDeviceVertexAttributeDivisorFeatures", "VkPhysicalDeviceVertexAttributeDivisorFeaturesKHR", "VkPhysicalDeviceVulkanSC10Features"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDeviceScalarBlockLayoutFeatures", "VkPhysicalDeviceVulkanSC10Features"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDeviceUniformBufferStandardLayoutFeatures", "VkPhysicalDeviceVulkanSC10Features"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDeviceBufferDeviceAddressFeatures", "VkPhysicalDeviceVulkanSC10Features"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDeviceImagelessFramebufferFeatures", "VkPhysicalDeviceVulkanSC10Features"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDeviceTextureCompressionASTCHDRFeatures", "VkPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT", "VkPhysicalDeviceVulkanSC10Features"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDeviceIndexTypeUint8Features", "VkPhysicalDeviceIndexTypeUint8FeaturesKHR", "VkPhysicalDeviceIndexTypeUint8FeaturesEXT", "VkPhysicalDeviceVulkanSC10Features"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures", "VkPhysicalDeviceVulkanSC10Features"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures", "VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT", "VkPhysicalDeviceVulkanSC10Features"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDeviceSubgroupSizeControlFeatures", "VkPhysicalDeviceSubgroupSizeControlFeaturesEXT", "VkPhysicalDeviceVulkanSC10Features"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDeviceLineRasterizationFeatures", "VkPhysicalDeviceLineRasterizationFeaturesKHR", "VkPhysicalDeviceLineRasterizationFeaturesEXT", "VkPhysicalDeviceVulkanSC10Features"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDevicePipelineCreationCacheControlFeatures", "VkPhysicalDeviceVulkanSC10Features"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures", "VkPhysicalDeviceVulkanSC10Features"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDeviceRobustness2FeaturesKHR", "VkPhysicalDeviceRobustness2FeaturesEXT"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDeviceImageRobustnessFeatures", "VkPhysicalDeviceImageRobustnessFeaturesEXT", "VkPhysicalDeviceVulkanSC10Features"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDeviceShaderTerminateInvocationFeatures", "VkPhysicalDeviceShaderTerminateInvocationFeaturesKHR", "VkPhysicalDeviceVulkanSC10Features"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDeviceSynchronization2Features", "VkPhysicalDeviceSynchronization2FeaturesKHR", "VkPhysicalDeviceVulkanSC10Features"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDeviceHostImageCopyFeatures", "VkPhysicalDeviceVulkanSC10Features"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDevicePipelineProtectedAccessFeatures", "VkPhysicalDeviceVulkanSC10Features"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDeviceShaderIntegerDotProductFeatures", "VkPhysicalDeviceVulkanSC10Features"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDeviceDynamicRenderingFeatures", "VkPhysicalDeviceVulkanSC10Features"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDevicePipelineRobustnessFeatures", "VkPhysicalDeviceVulkanSC10Features"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDeviceShaderSubgroupRotateFeatures", "VkPhysicalDeviceVulkanSC10Features"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDeviceShaderExpectAssumeFeatures", "VkPhysicalDeviceVulkanSC10Features"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDeviceShaderFloatControls2Features", "VkPhysicalDeviceVulkanSC10Features"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDeviceDynamicRenderingLocalReadFeatures", "VkPhysicalDeviceVulkanSC10Features"});
    return valid;
}

bool JsonLoader::WarnDuplicatedProperty(const Json::Value &parent) {
    bool valid = true;
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDevicePushDescriptorProperties", "VkPhysicalDeviceVulkanSC10Properties"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDeviceDriverProperties", "VkPhysicalDeviceVulkanSC10Properties"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDeviceIDProperties", "VkPhysicalDeviceVulkanSC10Properties"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDeviceMultiviewProperties", "VkPhysicalDeviceVulkanSC10Properties"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDeviceSubgroupProperties", "VkPhysicalDeviceVulkanSC10Properties"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDevicePointClippingProperties", "VkPhysicalDeviceVulkanSC10Properties"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDeviceProtectedMemoryProperties", "VkPhysicalDeviceVulkanSC10Properties"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDeviceSamplerFilterMinmaxProperties", "VkPhysicalDeviceVulkanSC10Properties"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDeviceInlineUniformBlockProperties", "VkPhysicalDeviceVulkanSC10Properties"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDeviceMaintenance3Properties", "VkPhysicalDeviceVulkanSC10Properties"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDeviceMaintenance4Properties", "VkPhysicalDeviceVulkanSC10Properties"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDeviceMaintenance5Properties", "VkPhysicalDeviceVulkanSC10Properties"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDeviceMaintenance6Properties", "VkPhysicalDeviceVulkanSC10Properties"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDeviceFloatControlsProperties", "VkPhysicalDeviceVulkanSC10Properties"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDeviceDescriptorIndexingProperties", "VkPhysicalDeviceVulkanSC10Properties"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDeviceTimelineSemaphoreProperties", "VkPhysicalDeviceVulkanSC10Properties"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDeviceVertexAttributeDivisorProperties", "VkPhysicalDeviceVertexAttributeDivisorPropertiesKHR", "VkPhysicalDeviceVulkanSC10Properties"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDeviceDepthStencilResolveProperties", "VkPhysicalDeviceVulkanSC10Properties"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDeviceTexelBufferAlignmentProperties", "VkPhysicalDeviceTexelBufferAlignmentPropertiesEXT", "VkPhysicalDeviceVulkanSC10Properties"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDeviceSubgroupSizeControlProperties", "VkPhysicalDeviceSubgroupSizeControlPropertiesEXT", "VkPhysicalDeviceVulkanSC10Properties"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDeviceLineRasterizationProperties", "VkPhysicalDeviceLineRasterizationPropertiesKHR", "VkPhysicalDeviceLineRasterizationPropertiesEXT", "VkPhysicalDeviceVulkanSC10Properties"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDeviceRobustness2PropertiesKHR", "VkPhysicalDeviceRobustness2PropertiesEXT"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDeviceHostImageCopyProperties", "VkPhysicalDeviceVulkanSC10Properties"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDeviceShaderIntegerDotProductProperties", "VkPhysicalDeviceVulkanSC10Properties"});
    valid &= WarnDuplicated(&layer_settings, parent, {"VkPhysicalDevicePipelineRobustnessProperties", "VkPhysicalDeviceVulkanSC10Properties"});
    return valid;
}

bool JsonLoader::GetFeature(const char *device_name, bool requested_profile, const Json::Value &features, const std::string &name) {
    const Json::Value &feature = features[name];

    if (name == "VkPhysicalDeviceFeatures") {
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_features_);
    } else if (name == "VkPhysicalDeviceExternalSciBufFeaturesNV" || name == "VkPhysicalDeviceExternalMemorySciBufFeaturesNV") {
#ifdef VK_USE_PLATFORM_SCI
        auto support = CheckExtensionSupport(VK_NV_EXTERNAL_MEMORY_SCI_BUF_EXTENSION_NAME, name);
        if (support != ExtensionSupport::SUPPORTED) return valid(support);
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_external_memory_sci_buf_features_);
#else
        return false;
#endif // VK_USE_PLATFORM_SCI
    } else if (name == "VkPhysicalDevicePrivateDataFeatures") {
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_private_data_features_);
    } else if (name == "VkPhysicalDeviceVariablePointerFeatures" || name == "VkPhysicalDeviceVariablePointersFeatures") {
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_variable_pointer_features_);
    } else if (name == "VkPhysicalDeviceExternalSciSyncFeaturesNV") {
#ifdef VK_USE_PLATFORM_SCI
        auto support = CheckExtensionSupport(VK_NV_EXTERNAL_SCI_SYNC_EXTENSION_NAME, name);
        if (support != ExtensionSupport::SUPPORTED) return valid(support);
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_external_sci_sync_features_);
#else
        return false;
#endif // VK_USE_PLATFORM_SCI
    } else if (name == "VkPhysicalDeviceExternalSciSync2FeaturesNV") {
#ifdef VK_USE_PLATFORM_SCI
        auto support = CheckExtensionSupport(VK_NV_EXTERNAL_SCI_SYNC_2_EXTENSION_NAME, name);
        if (support != ExtensionSupport::SUPPORTED) return valid(support);
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_external_sci_sync_2_features_);
#else
        return false;
#endif // VK_USE_PLATFORM_SCI
    } else if (name == "VkPhysicalDeviceMultiviewFeatures") {
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_multiview_features_);
    } else if (name == "VkPhysicalDevice16BitStorageFeatures") {
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_16_bit_storage_features_);
    } else if (name == "VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures") {
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_shader_subgroup_extended_types_features_);
    } else if (name == "VkPhysicalDeviceSamplerYcbcrConversionFeatures") {
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_sampler_ycbcr_conversion_features_);
    } else if (name == "VkPhysicalDeviceProtectedMemoryFeatures") {
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_protected_memory_features_);
    } else if (name == "VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT") {
        auto support = CheckExtensionSupport(VK_EXT_BLEND_OPERATION_ADVANCED_EXTENSION_NAME, name);
        if (support != ExtensionSupport::SUPPORTED) return valid(support);
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_blend_operation_advanced_features_);
    } else if (name == "VkPhysicalDeviceInlineUniformBlockFeatures") {
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_inline_uniform_block_features_);
    } else if (name == "VkPhysicalDeviceMaintenance4Features") {
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_maintenance_4_features_);
    } else if (name == "VkPhysicalDeviceMaintenance5Features") {
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_maintenance_5_features_);
    } else if (name == "VkPhysicalDeviceMaintenance6Features") {
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_maintenance_6_features_);
    } else if (name == "VkPhysicalDeviceShaderDrawParameterFeatures" || name == "VkPhysicalDeviceShaderDrawParametersFeatures") {
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_shader_draw_parameter_features_);
    } else if (name == "VkPhysicalDeviceShaderFloat16Int8Features") {
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_float_16_int_8_features_);
    } else if (name == "VkPhysicalDeviceHostQueryResetFeatures") {
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_host_query_reset_features_);
    } else if (name == "VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR") {
        auto support = CheckExtensionSupport(VK_KHR_GLOBAL_PRIORITY_EXTENSION_NAME, name);
        if (support != ExtensionSupport::SUPPORTED) return valid(support);
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_global_priority_query_features_);
    } else if (name == "VkPhysicalDeviceGlobalPriorityQueryFeatures") {
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_global_priority_query_features_);
    } else if (name == "VkPhysicalDeviceDescriptorIndexingFeatures") {
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_descriptor_indexing_features_);
    } else if (name == "VkPhysicalDeviceTimelineSemaphoreFeatures") {
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_timeline_semaphore_features_);
    } else if (name == "VkPhysicalDevice8BitStorageFeatures") {
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_8_bit_storage_features_);
    } else if (name == "VkPhysicalDeviceVulkanMemoryModelFeatures") {
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_vulkan_memory_model_features_);
    } else if (name == "VkPhysicalDeviceShaderAtomicInt64Features") {
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_shader_atomic_int_64_features_);
    } else if (name == "VkPhysicalDeviceShaderAtomicFloatFeaturesEXT") {
        auto support = CheckExtensionSupport(VK_EXT_SHADER_ATOMIC_FLOAT_EXTENSION_NAME, name);
        if (support != ExtensionSupport::SUPPORTED) return valid(support);
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_shader_atomic_float_features_);
    } else if (name == "VkPhysicalDeviceVertexAttributeDivisorFeaturesKHR") {
        auto support = CheckExtensionSupport(VK_KHR_VERTEX_ATTRIBUTE_DIVISOR_EXTENSION_NAME, name);
        if (support != ExtensionSupport::SUPPORTED) return valid(support);
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_vertex_attribute_divisor_features_);
    } else if (name == "VkPhysicalDeviceVertexAttributeDivisorFeatures") {
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_vertex_attribute_divisor_features_);
    } else if (name == "VkPhysicalDeviceASTCDecodeFeaturesEXT") {
        auto support = CheckExtensionSupport(VK_EXT_ASTC_DECODE_MODE_EXTENSION_NAME, name);
        if (support != ExtensionSupport::SUPPORTED) return valid(support);
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_astcdecode_features_);
    } else if (name == "VkPhysicalDeviceScalarBlockLayoutFeatures") {
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_scalar_block_layout_features_);
    } else if (name == "VkPhysicalDeviceUniformBufferStandardLayoutFeatures") {
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_uniform_buffer_standard_layout_features_);
    } else if (name == "VkPhysicalDeviceDepthClipEnableFeaturesEXT") {
        auto support = CheckExtensionSupport(VK_EXT_DEPTH_CLIP_ENABLE_EXTENSION_NAME, name);
        if (support != ExtensionSupport::SUPPORTED) return valid(support);
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_depth_clip_enable_features_);
    } else if (name == "VkPhysicalDeviceBufferDeviceAddressFeatures") {
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_buffer_device_address_features_);
    } else if (name == "VkPhysicalDeviceImagelessFramebufferFeatures") {
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_imageless_framebuffer_features_);
    } else if (name == "VkPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT") {
        auto support = CheckExtensionSupport(VK_EXT_TEXTURE_COMPRESSION_ASTC_HDR_EXTENSION_NAME, name);
        if (support != ExtensionSupport::SUPPORTED) return valid(support);
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_texture_compression_astchdrfeatures_);
    } else if (name == "VkPhysicalDeviceTextureCompressionASTCHDRFeatures") {
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_texture_compression_astchdrfeatures_);
    } else if (name == "VkPhysicalDeviceYcbcrImageArraysFeaturesEXT") {
        auto support = CheckExtensionSupport(VK_EXT_YCBCR_IMAGE_ARRAYS_EXTENSION_NAME, name);
        if (support != ExtensionSupport::SUPPORTED) return valid(support);
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_ycbcr_image_arrays_features_);
    } else if (name == "VkPhysicalDevicePerformanceQueryFeaturesKHR") {
        auto support = CheckExtensionSupport(VK_KHR_PERFORMANCE_QUERY_EXTENSION_NAME, name);
        if (support != ExtensionSupport::SUPPORTED) return valid(support);
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_performance_query_features_);
    } else if (name == "VkPhysicalDeviceShaderClockFeaturesKHR") {
        auto support = CheckExtensionSupport(VK_KHR_SHADER_CLOCK_EXTENSION_NAME, name);
        if (support != ExtensionSupport::SUPPORTED) return valid(support);
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_shader_clock_features_);
    } else if (name == "VkPhysicalDeviceIndexTypeUint8FeaturesEXT") {
        auto support = CheckExtensionSupport(VK_EXT_INDEX_TYPE_UINT8_EXTENSION_NAME, name);
        if (support != ExtensionSupport::SUPPORTED) return valid(support);
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_index_type_uint_8_features_);
    } else if (name == "VkPhysicalDeviceIndexTypeUint8FeaturesKHR") {
        auto support = CheckExtensionSupport(VK_KHR_INDEX_TYPE_UINT8_EXTENSION_NAME, name);
        if (support != ExtensionSupport::SUPPORTED) return valid(support);
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_index_type_uint_8_features_);
    } else if (name == "VkPhysicalDeviceIndexTypeUint8Features") {
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_index_type_uint_8_features_);
    } else if (name == "VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT") {
        auto support = CheckExtensionSupport(VK_EXT_FRAGMENT_SHADER_INTERLOCK_EXTENSION_NAME, name);
        if (support != ExtensionSupport::SUPPORTED) return valid(support);
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_fragment_shader_interlock_features_);
    } else if (name == "VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures") {
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_separate_depth_stencil_layouts_features_);
    } else if (name == "VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT") {
        auto support = CheckExtensionSupport(VK_EXT_SHADER_DEMOTE_TO_HELPER_INVOCATION_EXTENSION_NAME, name);
        if (support != ExtensionSupport::SUPPORTED) return valid(support);
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_shader_demote_to_helper_invocation_features_);
    } else if (name == "VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures") {
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_shader_demote_to_helper_invocation_features_);
    } else if (name == "VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT") {
        auto support = CheckExtensionSupport(VK_EXT_TEXEL_BUFFER_ALIGNMENT_EXTENSION_NAME, name);
        if (support != ExtensionSupport::SUPPORTED) return valid(support);
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_texel_buffer_alignment_features_);
    } else if (name == "VkPhysicalDeviceSubgroupSizeControlFeaturesEXT") {
        auto support = CheckExtensionSupport(VK_EXT_SUBGROUP_SIZE_CONTROL_EXTENSION_NAME, name);
        if (support != ExtensionSupport::SUPPORTED) return valid(support);
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_subgroup_size_control_features_);
    } else if (name == "VkPhysicalDeviceSubgroupSizeControlFeatures") {
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_subgroup_size_control_features_);
    } else if (name == "VkPhysicalDeviceLineRasterizationFeaturesEXT") {
        auto support = CheckExtensionSupport(VK_EXT_LINE_RASTERIZATION_EXTENSION_NAME, name);
        if (support != ExtensionSupport::SUPPORTED) return valid(support);
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_line_rasterization_features_);
    } else if (name == "VkPhysicalDeviceLineRasterizationFeaturesKHR") {
        auto support = CheckExtensionSupport(VK_KHR_LINE_RASTERIZATION_EXTENSION_NAME, name);
        if (support != ExtensionSupport::SUPPORTED) return valid(support);
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_line_rasterization_features_);
    } else if (name == "VkPhysicalDeviceLineRasterizationFeatures") {
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_line_rasterization_features_);
    } else if (name == "VkPhysicalDevicePipelineCreationCacheControlFeatures") {
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_pipeline_creation_cache_control_features_);
    } else if (name == "VkPhysicalDeviceVulkan11Features") {
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_vulkan_11_features_);
    } else if (name == "VkPhysicalDeviceVulkan12Features") {
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_vulkan_12_features_);
    } else if (name == "VkPhysicalDeviceVulkan13Features") {
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_vulkan_13_features_);
    } else if (name == "VkPhysicalDeviceVulkan14Features") {
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_vulkan_14_features_);
    } else if (name == "VkPhysicalDeviceCustomBorderColorFeaturesEXT") {
        auto support = CheckExtensionSupport(VK_EXT_CUSTOM_BORDER_COLOR_EXTENSION_NAME, name);
        if (support != ExtensionSupport::SUPPORTED) return valid(support);
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_custom_border_color_features_);
    } else if (name == "VkPhysicalDeviceExtendedDynamicStateFeaturesEXT") {
        auto support = CheckExtensionSupport(VK_EXT_EXTENDED_DYNAMIC_STATE_EXTENSION_NAME, name);
        if (support != ExtensionSupport::SUPPORTED) return valid(support);
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_extended_dynamic_state_features_);
    } else if (name == "VkPhysicalDeviceExtendedDynamicState2FeaturesEXT") {
        auto support = CheckExtensionSupport(VK_EXT_EXTENDED_DYNAMIC_STATE_2_EXTENSION_NAME, name);
        if (support != ExtensionSupport::SUPPORTED) return valid(support);
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_extended_dynamic_state_2_features_);
    } else if (name == "VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures") {
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_zero_initialize_workgroup_memory_features_);
    } else if (name == "VkPhysicalDeviceRobustness2FeaturesEXT" || name == "VkPhysicalDeviceRobustness2FeaturesKHR") {
        auto support = CheckExtensionSupport(VK_EXT_ROBUSTNESS_2_EXTENSION_NAME, name);
        if (support != ExtensionSupport::SUPPORTED) return valid(support);
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_robustness_2_features_);
    } else if (name == "VkPhysicalDeviceImageRobustnessFeaturesEXT") {
        auto support = CheckExtensionSupport(VK_EXT_IMAGE_ROBUSTNESS_EXTENSION_NAME, name);
        if (support != ExtensionSupport::SUPPORTED) return valid(support);
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_image_robustness_features_);
    } else if (name == "VkPhysicalDeviceImageRobustnessFeatures") {
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_image_robustness_features_);
    } else if (name == "VkPhysicalDevice4444FormatsFeaturesEXT") {
        auto support = CheckExtensionSupport(VK_EXT_4444_FORMATS_EXTENSION_NAME, name);
        if (support != ExtensionSupport::SUPPORTED) return valid(support);
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_4444_formats_features_);
    } else if (name == "VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT") {
        auto support = CheckExtensionSupport(VK_EXT_SHADER_IMAGE_ATOMIC_INT64_EXTENSION_NAME, name);
        if (support != ExtensionSupport::SUPPORTED) return valid(support);
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_shader_image_atomic_int_64_features_);
    } else if (name == "VkPhysicalDeviceFragmentShadingRateFeaturesKHR") {
        auto support = CheckExtensionSupport(VK_KHR_FRAGMENT_SHADING_RATE_EXTENSION_NAME, name);
        if (support != ExtensionSupport::SUPPORTED) return valid(support);
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_fragment_shading_rate_features_);
    } else if (name == "VkPhysicalDeviceShaderTerminateInvocationFeaturesKHR") {
        auto support = CheckExtensionSupport(VK_KHR_SHADER_TERMINATE_INVOCATION_EXTENSION_NAME, name);
        if (support != ExtensionSupport::SUPPORTED) return valid(support);
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_shader_terminate_invocation_features_);
    } else if (name == "VkPhysicalDeviceShaderTerminateInvocationFeatures") {
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_shader_terminate_invocation_features_);
    } else if (name == "VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT") {
        auto support = CheckExtensionSupport(VK_EXT_VERTEX_INPUT_DYNAMIC_STATE_EXTENSION_NAME, name);
        if (support != ExtensionSupport::SUPPORTED) return valid(support);
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_vertex_input_dynamic_state_features_);
    } else if (name == "VkPhysicalDeviceColorWriteEnableFeaturesEXT") {
        auto support = CheckExtensionSupport(VK_EXT_COLOR_WRITE_ENABLE_EXTENSION_NAME, name);
        if (support != ExtensionSupport::SUPPORTED) return valid(support);
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_color_write_enable_features_);
    } else if (name == "VkPhysicalDeviceSynchronization2FeaturesKHR") {
        auto support = CheckExtensionSupport(VK_KHR_SYNCHRONIZATION_2_EXTENSION_NAME, name);
        if (support != ExtensionSupport::SUPPORTED) return valid(support);
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_synchronization_2_features_);
    } else if (name == "VkPhysicalDeviceSynchronization2Features") {
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_synchronization_2_features_);
    } else if (name == "VkPhysicalDeviceHostImageCopyFeatures") {
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_host_image_copy_features_);
    } else if (name == "VkPhysicalDeviceVulkanSC10Features") {
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_vulkan_sc_10_features_);
    } else if (name == "VkPhysicalDevicePipelineProtectedAccessFeatures") {
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_pipeline_protected_access_features_);
    } else if (name == "VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT") {
        auto support = CheckExtensionSupport(VK_EXT_YCBCR_2PLANE_444_FORMATS_EXTENSION_NAME, name);
        if (support != ExtensionSupport::SUPPORTED) return valid(support);
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_ycbcr_2_plane_444_formats_features_);
    } else if (name == "VkPhysicalDeviceShaderIntegerDotProductFeatures") {
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_shader_integer_dot_product_features_);
    } else if (name == "VkPhysicalDeviceDynamicRenderingFeatures") {
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_dynamic_rendering_features_);
    } else if (name == "VkPhysicalDevicePipelineRobustnessFeatures") {
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_pipeline_robustness_features_);
    } else if (name == "VkPhysicalDeviceExternalMemoryScreenBufferFeaturesQNX") {
#ifdef VK_USE_PLATFORM_SCREEN_QNX
        auto support = CheckExtensionSupport(VK_QNX_EXTERNAL_MEMORY_SCREEN_BUFFER_EXTENSION_NAME, name);
        if (support != ExtensionSupport::SUPPORTED) return valid(support);
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_external_memory_screen_buffer_features_);
#else
        return false;
#endif // VK_USE_PLATFORM_SCREEN_QNX
    } else if (name == "VkPhysicalDeviceShaderSubgroupRotateFeatures") {
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_shader_subgroup_rotate_features_);
    } else if (name == "VkPhysicalDeviceShaderExpectAssumeFeatures") {
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_shader_expect_assume_features_);
    } else if (name == "VkPhysicalDeviceShaderFloatControls2Features") {
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_shader_float_controls_2_features_);
    } else if (name == "VkPhysicalDeviceDynamicRenderingLocalReadFeatures") {
        return GetStruct(device_name, requested_profile, feature, &pdd_->physical_device_dynamic_rendering_local_read_features_);
    }

    return true;
}

bool JsonLoader::GetProperty(const char *device_name, bool requested_profile, const Json::Value &props, const std::string &name) {
    const Json::Value &property = props[name];

    if (name == "VkPhysicalDeviceProperties") {
        return GetStruct(device_name, requested_profile, property, &pdd_->physical_device_properties_);
    } else if (name == "VkPhysicalDeviceSparseProperties") {
        return GetStruct(device_name, requested_profile, property, &pdd_->physical_device_properties_.sparseProperties);
    } else if (name == "VkPhysicalDeviceLimits") {
        return GetStruct(device_name, requested_profile, property, &pdd_->physical_device_properties_.limits);
    } else if (name == "VkPhysicalDevicePushDescriptorProperties") {
        return GetStruct(device_name, requested_profile, property, &pdd_->physical_device_push_descriptor_properties_);
    } else if (name == "VkPhysicalDeviceDriverProperties") {
        return GetStruct(device_name, requested_profile, property, &pdd_->physical_device_driver_properties_);
    } else if (name == "VkPhysicalDeviceIDProperties") {
        return GetStruct(device_name, requested_profile, property, &pdd_->physical_device_idproperties_);
    } else if (name == "VkPhysicalDeviceMultiviewProperties") {
        return GetStruct(device_name, requested_profile, property, &pdd_->physical_device_multiview_properties_);
    } else if (name == "VkPhysicalDeviceDiscardRectanglePropertiesEXT") {
        auto support = CheckExtensionSupport(VK_EXT_DISCARD_RECTANGLES_EXTENSION_NAME, name);
        if (support != ExtensionSupport::SUPPORTED) return valid(support);
        return GetStruct(device_name, requested_profile, property, &pdd_->physical_device_discard_rectangle_properties_);
    } else if (name == "VkPhysicalDeviceSubgroupProperties") {
        return GetStruct(device_name, requested_profile, property, &pdd_->physical_device_subgroup_properties_);
    } else if (name == "VkPhysicalDevicePointClippingProperties") {
        return GetStruct(device_name, requested_profile, property, &pdd_->physical_device_point_clipping_properties_);
    } else if (name == "VkPhysicalDeviceProtectedMemoryProperties") {
        return GetStruct(device_name, requested_profile, property, &pdd_->physical_device_protected_memory_properties_);
    } else if (name == "VkPhysicalDeviceSamplerFilterMinmaxProperties") {
        return GetStruct(device_name, requested_profile, property, &pdd_->physical_device_sampler_filter_minmax_properties_);
    } else if (name == "VkPhysicalDeviceSampleLocationsPropertiesEXT") {
        auto support = CheckExtensionSupport(VK_EXT_SAMPLE_LOCATIONS_EXTENSION_NAME, name);
        if (support != ExtensionSupport::SUPPORTED) return valid(support);
        return GetStruct(device_name, requested_profile, property, &pdd_->physical_device_sample_locations_properties_);
    } else if (name == "VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT") {
        auto support = CheckExtensionSupport(VK_EXT_BLEND_OPERATION_ADVANCED_EXTENSION_NAME, name);
        if (support != ExtensionSupport::SUPPORTED) return valid(support);
        return GetStruct(device_name, requested_profile, property, &pdd_->physical_device_blend_operation_advanced_properties_);
    } else if (name == "VkPhysicalDeviceInlineUniformBlockProperties") {
        return GetStruct(device_name, requested_profile, property, &pdd_->physical_device_inline_uniform_block_properties_);
    } else if (name == "VkPhysicalDeviceMaintenance3Properties") {
        return GetStruct(device_name, requested_profile, property, &pdd_->physical_device_maintenance_3_properties_);
    } else if (name == "VkPhysicalDeviceMaintenance4Properties") {
        return GetStruct(device_name, requested_profile, property, &pdd_->physical_device_maintenance_4_properties_);
    } else if (name == "VkPhysicalDeviceMaintenance5Properties") {
        return GetStruct(device_name, requested_profile, property, &pdd_->physical_device_maintenance_5_properties_);
    } else if (name == "VkPhysicalDeviceMaintenance6Properties") {
        return GetStruct(device_name, requested_profile, property, &pdd_->physical_device_maintenance_6_properties_);
    } else if (name == "VkPhysicalDeviceFloatControlsProperties") {
        return GetStruct(device_name, requested_profile, property, &pdd_->physical_device_float_controls_properties_);
    } else if (name == "VkPhysicalDeviceExternalMemoryHostPropertiesEXT") {
        auto support = CheckExtensionSupport(VK_EXT_EXTERNAL_MEMORY_HOST_EXTENSION_NAME, name);
        if (support != ExtensionSupport::SUPPORTED) return valid(support);
        return GetStruct(device_name, requested_profile, property, &pdd_->physical_device_external_memory_host_properties_);
    } else if (name == "VkPhysicalDeviceConservativeRasterizationPropertiesEXT") {
        auto support = CheckExtensionSupport(VK_EXT_CONSERVATIVE_RASTERIZATION_EXTENSION_NAME, name);
        if (support != ExtensionSupport::SUPPORTED) return valid(support);
        return GetStruct(device_name, requested_profile, property, &pdd_->physical_device_conservative_rasterization_properties_);
    } else if (name == "VkPhysicalDeviceDescriptorIndexingProperties") {
        return GetStruct(device_name, requested_profile, property, &pdd_->physical_device_descriptor_indexing_properties_);
    } else if (name == "VkPhysicalDeviceTimelineSemaphoreProperties") {
        return GetStruct(device_name, requested_profile, property, &pdd_->physical_device_timeline_semaphore_properties_);
    } else if (name == "VkPhysicalDeviceVertexAttributeDivisorPropertiesKHR") {
        auto support = CheckExtensionSupport(VK_KHR_VERTEX_ATTRIBUTE_DIVISOR_EXTENSION_NAME, name);
        if (support != ExtensionSupport::SUPPORTED) return valid(support);
        return GetStruct(device_name, requested_profile, property, &pdd_->physical_device_vertex_attribute_divisor_properties_);
    } else if (name == "VkPhysicalDeviceVertexAttributeDivisorProperties") {
        return GetStruct(device_name, requested_profile, property, &pdd_->physical_device_vertex_attribute_divisor_properties_);
    } else if (name == "VkPhysicalDevicePCIBusInfoPropertiesEXT") {
        auto support = CheckExtensionSupport(VK_EXT_PCI_BUS_INFO_EXTENSION_NAME, name);
        if (support != ExtensionSupport::SUPPORTED) return valid(support);
        return GetStruct(device_name, requested_profile, property, &pdd_->physical_device_pcibus_info_properties_);
    } else if (name == "VkPhysicalDeviceDepthStencilResolveProperties") {
        return GetStruct(device_name, requested_profile, property, &pdd_->physical_device_depth_stencil_resolve_properties_);
    } else if (name == "VkPhysicalDevicePerformanceQueryPropertiesKHR") {
        auto support = CheckExtensionSupport(VK_KHR_PERFORMANCE_QUERY_EXTENSION_NAME, name);
        if (support != ExtensionSupport::SUPPORTED) return valid(support);
        return GetStruct(device_name, requested_profile, property, &pdd_->physical_device_performance_query_properties_);
    } else if (name == "VkPhysicalDeviceTexelBufferAlignmentPropertiesEXT") {
        auto support = CheckExtensionSupport(VK_EXT_TEXEL_BUFFER_ALIGNMENT_EXTENSION_NAME, name);
        if (support != ExtensionSupport::SUPPORTED) return valid(support);
        return GetStruct(device_name, requested_profile, property, &pdd_->physical_device_texel_buffer_alignment_properties_);
    } else if (name == "VkPhysicalDeviceTexelBufferAlignmentProperties") {
        return GetStruct(device_name, requested_profile, property, &pdd_->physical_device_texel_buffer_alignment_properties_);
    } else if (name == "VkPhysicalDeviceSubgroupSizeControlPropertiesEXT") {
        auto support = CheckExtensionSupport(VK_EXT_SUBGROUP_SIZE_CONTROL_EXTENSION_NAME, name);
        if (support != ExtensionSupport::SUPPORTED) return valid(support);
        return GetStruct(device_name, requested_profile, property, &pdd_->physical_device_subgroup_size_control_properties_);
    } else if (name == "VkPhysicalDeviceSubgroupSizeControlProperties") {
        return GetStruct(device_name, requested_profile, property, &pdd_->physical_device_subgroup_size_control_properties_);
    } else if (name == "VkPhysicalDeviceLineRasterizationPropertiesEXT") {
        auto support = CheckExtensionSupport(VK_EXT_LINE_RASTERIZATION_EXTENSION_NAME, name);
        if (support != ExtensionSupport::SUPPORTED) return valid(support);
        return GetStruct(device_name, requested_profile, property, &pdd_->physical_device_line_rasterization_properties_);
    } else if (name == "VkPhysicalDeviceLineRasterizationPropertiesKHR") {
        auto support = CheckExtensionSupport(VK_KHR_LINE_RASTERIZATION_EXTENSION_NAME, name);
        if (support != ExtensionSupport::SUPPORTED) return valid(support);
        return GetStruct(device_name, requested_profile, property, &pdd_->physical_device_line_rasterization_properties_);
    } else if (name == "VkPhysicalDeviceLineRasterizationProperties") {
        return GetStruct(device_name, requested_profile, property, &pdd_->physical_device_line_rasterization_properties_);
    } else if (name == "VkPhysicalDeviceVulkan11Properties") {
        return GetStruct(device_name, requested_profile, property, &pdd_->physical_device_vulkan_11_properties_);
    } else if (name == "VkPhysicalDeviceVulkan12Properties") {
        return GetStruct(device_name, requested_profile, property, &pdd_->physical_device_vulkan_12_properties_);
    } else if (name == "VkPhysicalDeviceVulkan13Properties") {
        return GetStruct(device_name, requested_profile, property, &pdd_->physical_device_vulkan_13_properties_);
    } else if (name == "VkPhysicalDeviceVulkan14Properties") {
        pdd_->pCopySrcLayouts_.resize(64);
        pdd_->pCopyDstLayouts_.resize(64);
        pdd_->physical_device_vulkan_14_properties_.pCopySrcLayouts = pdd_->pCopySrcLayouts_.data();
        pdd_->physical_device_vulkan_14_properties_.pCopyDstLayouts = pdd_->pCopyDstLayouts_.data();
        return GetStruct(device_name, requested_profile, property, &pdd_->physical_device_vulkan_14_properties_);
    } else if (name == "VkPhysicalDeviceToolProperties") {
        return GetStruct(device_name, requested_profile, property, &pdd_->physical_device_tool_properties_);
    } else if (name == "VkPhysicalDeviceCustomBorderColorPropertiesEXT") {
        auto support = CheckExtensionSupport(VK_EXT_CUSTOM_BORDER_COLOR_EXTENSION_NAME, name);
        if (support != ExtensionSupport::SUPPORTED) return valid(support);
        return GetStruct(device_name, requested_profile, property, &pdd_->physical_device_custom_border_color_properties_);
    } else if (name == "VkPhysicalDeviceRobustness2PropertiesEXT" || name == "VkPhysicalDeviceRobustness2PropertiesKHR") {
        auto support = CheckExtensionSupport(VK_EXT_ROBUSTNESS_2_EXTENSION_NAME, name);
        if (support != ExtensionSupport::SUPPORTED) return valid(support);
        return GetStruct(device_name, requested_profile, property, &pdd_->physical_device_robustness_2_properties_);
    } else if (name == "VkPhysicalDeviceFragmentShadingRatePropertiesKHR") {
        auto support = CheckExtensionSupport(VK_KHR_FRAGMENT_SHADING_RATE_EXTENSION_NAME, name);
        if (support != ExtensionSupport::SUPPORTED) return valid(support);
        return GetStruct(device_name, requested_profile, property, &pdd_->physical_device_fragment_shading_rate_properties_);
    } else if (name == "VkPhysicalDeviceHostImageCopyProperties") {
        pdd_->pCopySrcLayouts_.resize(64);
        pdd_->pCopyDstLayouts_.resize(64);
        pdd_->physical_device_host_image_copy_properties_.pCopySrcLayouts = pdd_->pCopySrcLayouts_.data();
        pdd_->physical_device_host_image_copy_properties_.pCopyDstLayouts = pdd_->pCopyDstLayouts_.data();
        return GetStruct(device_name, requested_profile, property, &pdd_->physical_device_host_image_copy_properties_);
    } else if (name == "VkPhysicalDeviceVulkanSC10Properties") {
        return GetStruct(device_name, requested_profile, property, &pdd_->physical_device_vulkan_sc_10_properties_);
    } else if (name == "VkPhysicalDeviceShaderIntegerDotProductProperties") {
        return GetStruct(device_name, requested_profile, property, &pdd_->physical_device_shader_integer_dot_product_properties_);
    } else if (name == "VkPhysicalDevicePipelineRobustnessProperties") {
        return GetStruct(device_name, requested_profile, property, &pdd_->physical_device_pipeline_robustness_properties_);
    }

    return true;
}

bool JsonLoader::GetFormat(const char *device_name, bool requested_profile, const Json::Value &formats, const std::string &format_name, MapOfVkFormatProperties *dest,
                           MapOfVkFormatProperties3 *dest3) {
    (void)requested_profile;

    VkFormat format = StringToFormat(format_name);
    VkFormatProperties profile_properties = {};
    VkFormatProperties3 profile_properties_3 = {VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_3};
    const auto &member = formats[format_name];
    for (const auto &name : member.getMemberNames()) {
        const auto &props = member[name];
        if (name == "VkFormatProperties") {
            for (const auto &feature : props["linearTilingFeatures"]) {
                profile_properties.linearTilingFeatures |= StringToVkFormatFeatureFlags(feature.asString());
            }
            for (const auto &feature : props["optimalTilingFeatures"]) {
                profile_properties.optimalTilingFeatures |= StringToVkFormatFeatureFlags(feature.asString());
            }
            for (const auto &feature : props["bufferFeatures"]) {
                profile_properties.bufferFeatures |= StringToVkFormatFeatureFlags(feature.asString());
            }
        } else if (name == "VkFormatProperties2" || name == "VkFormatProperties2KHR") {
            const auto &format_properties = props["formatProperties"];
            for (const auto &feature : format_properties["linearTilingFeatures"]) {
                profile_properties.linearTilingFeatures |= StringToVkFormatFeatureFlags(feature.asString());
            }
            for (const auto &feature : format_properties["optimalTilingFeatures"]) {
                profile_properties.optimalTilingFeatures |= StringToVkFormatFeatureFlags(feature.asString());
            }
            for (const auto &feature : format_properties["bufferFeatures"]) {
                profile_properties.bufferFeatures |= StringToVkFormatFeatureFlags(feature.asString());
            }
        } else if (name == "VkFormatProperties3" || name == "VkFormatProperties3KHR") {
            for (const auto &feature : props["linearTilingFeatures"]) {
                profile_properties_3.linearTilingFeatures |= StringToVkFormatFeatureFlags2(feature.asString());
            }
            for (const auto &feature : props["optimalTilingFeatures"]) {
                profile_properties_3.optimalTilingFeatures |= StringToVkFormatFeatureFlags2(feature.asString());
            }
            for (const auto &feature : props["bufferFeatures"]) {
                profile_properties_3.bufferFeatures |= StringToVkFormatFeatureFlags2(feature.asString());
            }
        }
    }

    profile_properties_3.linearTilingFeatures |= profile_properties.linearTilingFeatures;
    profile_properties_3.optimalTilingFeatures |= profile_properties.optimalTilingFeatures;
    profile_properties_3.bufferFeatures |= profile_properties.bufferFeatures;

    profile_properties.linearTilingFeatures |= static_cast<VkFormatFeatureFlags>(profile_properties_3.linearTilingFeatures);
    profile_properties.optimalTilingFeatures |= static_cast<VkFormatFeatureFlags>(profile_properties_3.optimalTilingFeatures);
    profile_properties.bufferFeatures |= static_cast<VkFormatFeatureFlags>(profile_properties_3.bufferFeatures);

    (*dest)[format] = profile_properties;
    (*dest3)[format] = profile_properties_3;

    if (IsASTCHDRFormat(format) && !device_has_astc_hdr) {
        // We already notified that ASTC HDR is not supported, no spamming
        return false;
    }
    if (IsASTCLDRFormat(format) && !device_has_astc) {
        // We already notified that ASTC is not supported, no spamming
        return false;
    }
    if ((IsETC2Format(format) || IsEACFormat(format)) && !device_has_etc2) {
        // We already notified that ETC2 is not supported, no spamming
        return false;
    }
    if (IsBCFormat(format) && !device_has_bc) {
        // We already notified that BC is not supported, no spamming
        return false;
    }
    if (IsPVRTCFormat(format) &&!device_has_pvrtc) {
        // We already notified that PVRTC is not supported, no spamming
        return false;
    }

    bool valid = true;

    const VkFormatProperties &device_properties = pdd_->device_formats_[format];
    if (!HasFlags(device_properties.linearTilingFeatures, profile_properties.linearTilingFeatures)) {
        WarnMissingFormatFeatures(&layer_settings, device_name, format_name, "linearTilingFeatures", profile_properties.linearTilingFeatures,
                                  device_properties.linearTilingFeatures);
        valid = false;
    }
    if (!HasFlags(device_properties.optimalTilingFeatures, profile_properties.optimalTilingFeatures)) {
        WarnMissingFormatFeatures(&layer_settings, device_name, format_name, "optimalTilingFeatures", profile_properties.optimalTilingFeatures,
                                  device_properties.optimalTilingFeatures);
        valid = false;
    }
    if (!HasFlags(device_properties.bufferFeatures, profile_properties.bufferFeatures)) {
        WarnMissingFormatFeatures(&layer_settings, device_name, format_name, "bufferFeatures", profile_properties.bufferFeatures,
                                  device_properties.bufferFeatures);
        valid = false;
    }

    const VkFormatProperties3 &device_properties_3 = pdd_->device_formats_3_[format];
    if (!HasFlags(device_properties_3.linearTilingFeatures, profile_properties_3.linearTilingFeatures)) {
        WarnMissingFormatFeatures2(&layer_settings, device_name, format_name, "linearTilingFeatures", profile_properties_3.linearTilingFeatures,
                                   device_properties_3.linearTilingFeatures);
        valid = false;
    }
    if (!HasFlags(device_properties_3.optimalTilingFeatures, profile_properties_3.optimalTilingFeatures)) {
        WarnMissingFormatFeatures2(&layer_settings, device_name, format_name, "optimalTilingFeatures", profile_properties_3.optimalTilingFeatures,
                                   device_properties_3.optimalTilingFeatures);
        valid = false;
    }
    if (!HasFlags(device_properties_3.bufferFeatures, profile_properties_3.bufferFeatures)) {
        WarnMissingFormatFeatures2(&layer_settings, device_name, format_name, "bufferFeatures", profile_properties_3.bufferFeatures,
                                   device_properties_3.bufferFeatures);
        valid = false;
    }

    return valid;
}

bool JsonLoader::CheckVersionSupport(uint32_t version, const std::string &name) {
    if (pdd_->GetEffectiveVersion() < version) {
        LogMessage(&layer_settings,
            DEBUG_REPORT_ERROR_BIT,
            "Profile sets %s which is provided by Vulkan version %s, but the current effective API version is %s.\n",
                     name.c_str(), StringAPIVersion(version).c_str(), StringAPIVersion(pdd_->GetEffectiveVersion()).c_str());
        return false;
    }
    return true;
}

JsonLoader::ExtensionSupport JsonLoader::CheckExtensionSupport(const char *extension, const std::string &name) {
    for (const auto &ext : excluded_extensions_) {
        if (ext == extension) {
            LogMessage(&layer_settings, DEBUG_REPORT_NOTIFICATION_BIT,
                       "Profile requires %s capabilities, but %s is excluded, device values are used.\n", name.c_str(),
                                extension);
            return JsonLoader::ExtensionSupport::EXCLUDED;
        }
    }
    if (layer_settings.simulate.capabilities & SIMULATE_EXTENSIONS_BIT) {
        if (!PhysicalDeviceData::HasSimulatedExtension(pdd_, extension)) {
            LogMessage(&layer_settings, DEBUG_REPORT_ERROR_BIT,
                "Profile requires %s capabilitiess, but %s is not required by the profile, device values are used.\n",
                         name.c_str(), extension);
            if (layer_settings.log.debug_fail_on_error) {
                return JsonLoader::ExtensionSupport::UNSUPPORTED;
            }
        }
    } else {
        if (!PhysicalDeviceData::HasExtension(pdd_, extension)) {
            LogMessage(&layer_settings,
                DEBUG_REPORT_WARNING_BIT,
                "Profile requires by %s capabilities, but %s is not supported by the device.\n", name.c_str(), extension);
        }
    }
    return JsonLoader::ExtensionSupport::SUPPORTED;
}

bool JsonLoader::valid(ExtensionSupport support) {
    if (support == JsonLoader::ExtensionSupport::UNSUPPORTED) {
        return false;
    }
    return true;
}

bool JsonLoader::GetQueueFamilyProperties(const char* device_name, const Json::Value &qf_props, QueueFamilyProperties *dest) {
    for (const auto &name : qf_props.getMemberNames()) {
        const auto &props = qf_props[name];
        if (name == "VkQueueFamilyProperties") {
            for (const auto &feature : props["queueFlags"]) {
                dest->properties_2.queueFamilyProperties.queueFlags |= StringToVkQueueFlags(feature.asString());
            }
            dest->properties_2.queueFamilyProperties.queueCount = static_cast<uint32_t>(props["queueCount"].asInt());
            dest->properties_2.queueFamilyProperties.timestampValidBits = props["timestampValidBits"].asUInt();
            const auto &minImagetransferGranularity = props["minImageTransferGranularity"];
            dest->properties_2.queueFamilyProperties.minImageTransferGranularity.width =
                minImagetransferGranularity["width"].asUInt();
            dest->properties_2.queueFamilyProperties.minImageTransferGranularity.height =
                minImagetransferGranularity["height"].asUInt();
            dest->properties_2.queueFamilyProperties.minImageTransferGranularity.depth =
                minImagetransferGranularity["depth"].asUInt();
        } else if (name == "VkQueueFamilyProperties2" || name == "VkQueueFamilyProperties2KHR") {
            const auto &props2 = props["queueFamilyProperties"];
            for (const auto &feature : props2["queueFlags"]) {
                dest->properties_2.queueFamilyProperties.queueFlags |= StringToVkQueueFlags(feature.asString());
            }
            dest->properties_2.queueFamilyProperties.queueCount = static_cast<uint32_t>(props2["queueCount"].asInt());
            dest->properties_2.queueFamilyProperties.timestampValidBits = props2["timestampValidBits"].asUInt();
            const auto &minImagetransferGranularity = props2["minImageTransferGranularity"];
            dest->properties_2.queueFamilyProperties.minImageTransferGranularity.width =
                minImagetransferGranularity["width"].asUInt();
            dest->properties_2.queueFamilyProperties.minImageTransferGranularity.height =
                minImagetransferGranularity["height"].asUInt();
            dest->properties_2.queueFamilyProperties.minImageTransferGranularity.depth =
                minImagetransferGranularity["depth"].asUInt();
        } else if (name == "VkQueueFamilyOwnershipTransferPropertiesKHR") {
            for (const auto &feature : props["optimalImageTransferToQueueFamilies"]) {
                dest->ownership_transfer_properties_.optimalImageTransferToQueueFamilies |= feature.asUInt();
            }
        } else if (name == "VkQueueFamilyGlobalPriorityPropertiesKHR" || name == "VkQueueFamilyGlobalPriorityPropertiesEXT") {
            uint32_t i = 0;
            for (const auto &feature : props["priorities"]) {
                dest->global_priority_properties_.priorities[i++] = StringToVkQueueGlobalPriorityKHR(feature.asString());
            }
            dest->global_priority_properties_.priorityCount = props["priorityCount"].asUInt();
#ifndef VULKANSC
        } else if (name == "VkQueueFamilyVideoPropertiesKHR") {
            for (const auto &feature : props["videoCodecOperations"]) {
                dest->video_properties_.videoCodecOperations |= StringToVkVideoCodecOperationFlagsKHR(feature.asString());
            }
#endif
        } else if (name == "VkQueueFamilyCheckpointProperties2NV") {
            for (const auto &feature : props["checkpointExecutionStageMask"]) {
                dest->checkpoint_properties_2_.checkpointExecutionStageMask |= StringToVkPipelineStageFlags2(feature.asString());
            }
        } else if (name == "VkQueueFamilyCheckpointPropertiesNV") {
            for (const auto &feature : props["checkpointExecutionStageMask"]) {
                dest->checkpoint_properties_.checkpointExecutionStageMask |= StringToVkPipelineStageFlags(feature.asString());
            }
        } else if (name == "VkQueueFamilyQueryResultStatusPropertiesKHR") {
            dest->query_result_status_properties_.queryResultStatusSupport = props["queryResultStatusSupport"].asBool() ? VK_TRUE : VK_FALSE;
        }
    }

    bool valid = true;

    bool supported = false;
    for (const auto &device_qfp : pdd_->device_queue_family_properties_) {
        if (!QueueFamilyMatch(device_qfp.properties_2.queueFamilyProperties, dest->properties_2.queueFamilyProperties)) {
            continue;
        }
        if ((device_qfp.ownership_transfer_properties_.optimalImageTransferToQueueFamilies & dest->ownership_transfer_properties_.optimalImageTransferToQueueFamilies) !=
             dest->ownership_transfer_properties_.optimalImageTransferToQueueFamilies) {
            continue;
        }
        if (!GlobalPriorityMatch(device_qfp.global_priority_properties_, dest->global_priority_properties_)) {
            continue;
        }
        if ((device_qfp.video_properties_.videoCodecOperations & dest->video_properties_.videoCodecOperations) !=
            dest->video_properties_.videoCodecOperations) {
            continue;
        }
        if ((device_qfp.checkpoint_properties_.checkpointExecutionStageMask &
             dest->checkpoint_properties_.checkpointExecutionStageMask) !=
            dest->checkpoint_properties_.checkpointExecutionStageMask) {
            continue;
        }
        if ((device_qfp.checkpoint_properties_2_.checkpointExecutionStageMask &
             dest->checkpoint_properties_2_.checkpointExecutionStageMask) !=
            dest->checkpoint_properties_2_.checkpointExecutionStageMask) {
            continue;
        }
        if (device_qfp.query_result_status_properties_.queryResultStatusSupport != dest->query_result_status_properties_.queryResultStatusSupport) {
            continue;
        }
        supported = true;
        break;
    }
    if (!supported) {
        std::string message =
            format("Device (%s) has no queue family that supports VkQueueFamilyProperties [queueFlags: %s, queueCount: %" PRIu32
                   ", timestampValidBits: %" PRIu32 ", minImageTransferGranularity: [%" PRIu32 ", %" PRIu32 ", %" PRIu32 "]]",
                   device_name,
                   GetQueueFlagsToString(dest->properties_2.queueFamilyProperties.queueFlags).c_str(),
                   dest->properties_2.queueFamilyProperties.queueCount, dest->properties_2.queueFamilyProperties.timestampValidBits,
                   dest->properties_2.queueFamilyProperties.minImageTransferGranularity.width,
                   dest->properties_2.queueFamilyProperties.minImageTransferGranularity.height,
                   dest->properties_2.queueFamilyProperties.minImageTransferGranularity.depth);
        if (dest->ownership_transfer_properties_.optimalImageTransferToQueueFamilies > 0) {
            message += format(", VkQueueFamilyOwnershipTransferPropertiesKHR [optimalImageTransferToQueueFamilies: %" PRIu32 "]",
                              dest->ownership_transfer_properties_.optimalImageTransferToQueueFamilies);
        }
        if (dest->global_priority_properties_.priorityCount > 0) {
            std::string priorities = "[";
            for (uint32_t i = 0; i < dest->global_priority_properties_.priorityCount; ++i) {
                if (i > 0) {
                    priorities += ", ";
                }
                priorities += string_VkQueueGlobalPriority(dest->global_priority_properties_.priorities[i]);
            }
            priorities += "]";

            message += format(", VkQueueFamilyGlobalPriorityPropertiesKHR [priorityCount: %" PRIu32 ", priorities: %s]",
                              dest->global_priority_properties_.priorityCount, priorities.c_str());
        }
        if (dest->video_properties_.videoCodecOperations > 0) {
            message += format(", VkQueueFamilyVideoPropertiesKHR [videoCodecOperations: %s]",
                              string_VkVideoCodecOperationFlagsKHR(dest->video_properties_.videoCodecOperations).c_str());
        }
        if (dest->checkpoint_properties_.checkpointExecutionStageMask > 0) {
            message += format(", VkQueueFamilyCheckpointPropertiesNV [checkpointExecutionStageMask: %s]",
                              string_VkPipelineStageFlags(dest->checkpoint_properties_.checkpointExecutionStageMask).c_str());
        }
        if (dest->checkpoint_properties_2_.checkpointExecutionStageMask > 0) {
            message += format(", VkQueueFamilyCheckpointProperties2NV [checkpointExecutionStageMask: %s]",
                              string_VkPipelineStageFlags2(dest->checkpoint_properties_2_.checkpointExecutionStageMask).c_str());
        }
        if (dest->query_result_status_properties_.queryResultStatusSupport) {
            message += format(", VkQueueFamilyQueryResultStatusPropertiesKHR [queryResultStatusSupport: VK_TRUE]");
        }
        message += ".\n";
        LogMessage(&layer_settings, DEBUG_REPORT_WARNING_BIT, message.c_str());
        valid = false;
    }

    return valid;
}

bool QueueFamilyAndExtensionsMatch(const QueueFamilyProperties &device, const QueueFamilyProperties &profile) {
    if (!QueueFamilyMatch(device.properties_2.queueFamilyProperties, profile.properties_2.queueFamilyProperties)) {
        return false;
    }
    if ((device.ownership_transfer_properties_.optimalImageTransferToQueueFamilies & profile.ownership_transfer_properties_.optimalImageTransferToQueueFamilies) !=
         profile.ownership_transfer_properties_.optimalImageTransferToQueueFamilies) {
        return false;
    }
    if (!GlobalPriorityMatch(device.global_priority_properties_, profile.global_priority_properties_)) {
        return false;
    }
    if ((device.video_properties_.videoCodecOperations & profile.video_properties_.videoCodecOperations) !=
        profile.video_properties_.videoCodecOperations) {
        return false;
    }
    if ((device.checkpoint_properties_.checkpointExecutionStageMask &
         profile.checkpoint_properties_.checkpointExecutionStageMask) !=
        profile.checkpoint_properties_.checkpointExecutionStageMask) {
        return false;
    }
    if ((device.checkpoint_properties_2_.checkpointExecutionStageMask &
         profile.checkpoint_properties_2_.checkpointExecutionStageMask) !=
        profile.checkpoint_properties_2_.checkpointExecutionStageMask) {
        return false;
    }
    if (device.query_result_status_properties_.queryResultStatusSupport != profile.query_result_status_properties_.queryResultStatusSupport) {
        return false;
    }
    return true;
}

void CopyUnsetQueueFamilyProperties(const QueueFamilyProperties *device, QueueFamilyProperties *profile) {
    if (profile->properties_2.queueFamilyProperties.queueFlags == 0) {
        profile->properties_2.queueFamilyProperties.queueFlags = device->properties_2.queueFamilyProperties.queueFlags;
    }
    if (profile->properties_2.queueFamilyProperties.queueCount == 0) {
        profile->properties_2.queueFamilyProperties.queueCount = device->properties_2.queueFamilyProperties.queueCount;
    }
    if (profile->properties_2.queueFamilyProperties.timestampValidBits == 0) {
        profile->properties_2.queueFamilyProperties.timestampValidBits =
            device->properties_2.queueFamilyProperties.timestampValidBits;
    }
    if (profile->properties_2.queueFamilyProperties.minImageTransferGranularity.width == 0) {
        profile->properties_2.queueFamilyProperties.minImageTransferGranularity.width =
            device->properties_2.queueFamilyProperties.minImageTransferGranularity.width;
    }
    if (profile->properties_2.queueFamilyProperties.minImageTransferGranularity.height == 0) {
        profile->properties_2.queueFamilyProperties.minImageTransferGranularity.height =
            device->properties_2.queueFamilyProperties.minImageTransferGranularity.height;
    }
    if (profile->properties_2.queueFamilyProperties.minImageTransferGranularity.depth == 0) {
        profile->properties_2.queueFamilyProperties.minImageTransferGranularity.depth =
            device->properties_2.queueFamilyProperties.minImageTransferGranularity.depth;
    }
}

bool JsonLoader::OrderQueueFamilyProperties(ArrayOfVkQueueFamilyProperties *qfp) {
    if (qfp->empty()) {
        return true;
    }
    // If device has less queue families than needed we can't load all profile queue families
    if (pdd_->device_queue_family_properties_.size() < qfp->size()) {
        return false;
    }
    // Find all permutations and see if any of them supports profile queue families
    std::vector<uint32_t> permutations(pdd_->device_queue_family_properties_.size());
    uint32_t count = static_cast<uint32_t>(permutations.size());
    for (uint32_t i = 0; i < count; ++i) {
        permutations[i] = i;
    }
    do {
        bool match = true;
        for (uint32_t i = 0; i < count; ++i) {
            if (permutations[i] < qfp->size() &&
                !QueueFamilyAndExtensionsMatch(pdd_->device_queue_family_properties_[i], (*qfp)[permutations[i]])) {
                match = false;
                break;
            }
        }
        if (match) {
            // Empty queue families at the end are not needed
            while (permutations[count - 1] >= qfp->size()) {
                --count;
            }
            ArrayOfVkQueueFamilyProperties ordered;
            for (uint32_t i = 0; i < count; ++i) {
                if (permutations[i] < qfp->size()) {
                    ordered.push_back((*qfp)[permutations[i]]);
                } else {
                    ordered.push_back(QueueFamilyProperties());
                }
            }
            *qfp = ordered;
            for (uint32_t i = 0; i < count; ++i) {
                CopyUnsetQueueFamilyProperties(&pdd_->device_queue_family_properties_[i], &(*qfp)[i]);
            }
            return true;
        }
    } while (std::next_permutation(permutations.begin(), permutations.end()));
    LogMessage(&layer_settings, DEBUG_REPORT_WARNING_BIT,
               "Device supports all individual profile queue families, but not all of them simultaneously.\n");
    return false;
}

void JsonLoader::AddPromotedExtensions(uint32_t api_version) {
	const uint32_t minor = VK_API_VERSION_MINOR(api_version);
	const uint32_t major = VK_API_VERSION_MAJOR(api_version);
	LogMessage(&layer_settings, DEBUG_REPORT_NOTIFICATION_BIT,
	"- Adding promoted extensions to core in Vulkan (%" PRIu32 ".%" PRIu32 ").\n", major, minor);

}

VkResult JsonLoader::ReadProfile(const char *device_name, const Json::Value& root, const std::vector<std::vector<std::string>> &capabilities, bool requested_profile, bool enable_warnings) {
    bool failed = false;

    uint32_t properties_api_version = 0;
    uint32_t simulated_version = 0;

    const auto &cap_definisions = root["capabilities"];
    for (const auto &capability_variants : capabilities) {
        for (const auto &cap_variant : capability_variants) {
            const auto &cap_definision = cap_definisions[cap_variant];

            const auto &properties = cap_definision["properties"];
            if (properties.isMember("VkPhysicalDeviceProperties") && properties["VkPhysicalDeviceProperties"].isMember("apiVersion")) {
                properties_api_version = static_cast<uint32_t>(properties["VkPhysicalDeviceProperties"]["apiVersion"].asInt());
                simulated_version = properties_api_version;
            } else if (layer_settings.simulate.capabilities & SIMULATE_API_VERSION_BIT) {
                simulated_version = profile_api_version_;
            }
        }
    }
    if (simulated_version != 0 && requested_profile) {
        AddPromotedExtensions(simulated_version);
    }

    for (const auto &capability_variants : capabilities) {
        for (const auto &capability_variant : capability_variants) {
            const auto &cap_definision = cap_definisions[capability_variant];
            const auto &properties = cap_definision["properties"];

            if (VK_API_VERSION_PATCH(this->profile_api_version_) > VK_API_VERSION_PATCH(pdd_->physical_device_properties_.apiVersion)) {
                LogMessage(&layer_settings, DEBUG_REPORT_WARNING_BIT,
                    "Profile apiVersion (%" PRIu32 ".%" PRIu32 ".%" PRIu32 ") is greater than the device apiVersion (%" PRIu32 ".%" PRIu32 ".%" PRIu32 ").\n",
                        VK_API_VERSION_MAJOR(this->profile_api_version_),
                        VK_API_VERSION_MINOR(this->profile_api_version_),
                        VK_API_VERSION_PATCH(this->profile_api_version_),
                        VK_API_VERSION_MAJOR(pdd_->physical_device_properties_.apiVersion),
                        VK_API_VERSION_MINOR(pdd_->physical_device_properties_.apiVersion),
                        VK_API_VERSION_PATCH(pdd_->physical_device_properties_.apiVersion));
                failed = true;
            }

            if (layer_settings.simulate.capabilities & SIMULATE_EXTENSIONS_BIT) {
                const auto &extensions = cap_definision["extensions"];

                pdd_->map_of_extension_properties_.reserve(extensions.size());
                for (const auto &e : extensions.getMemberNames()) {
                    VkExtensionProperties extension;
                    strcpy(extension.extensionName, e.c_str());
                    extension.specVersion = static_cast<uint32_t>(extensions[e].asInt());

                    bool found = pdd_->map_of_extension_properties_.count(e) > 0;

                    if (IsInstanceExtension(e.c_str())) {
                        LogMessage(&layer_settings, DEBUG_REPORT_NOTIFICATION_BIT,
                            "Required %s extension is an instance extension. The Profiles layer can't override instance extension, the extension is ignored.\n", e.c_str());
                    }

                    if (!found) {
                        bool supported_on_device = pdd_->device_extensions_.count(e) > 0;

                        if (!supported_on_device) {
                            failed = true;
                        }
                        pdd_->map_of_extension_properties_.insert({e, extension});
                        if (!PhysicalDeviceData::HasSimulatedExtension(pdd_, extension.extensionName)) {
                            pdd_->simulation_extensions_.insert({e, extension});
                        }
                    }
                }
            }

            if (layer_settings.simulate.capabilities & SIMULATE_FEATURES_BIT) {
                const auto &features = cap_definision["features"];

                bool duplicated = !WarnDuplicatedFeature(features);
                if (duplicated) {
                    failed = true;
                }

                for (const auto &feature : features.getMemberNames()) {
                    if (features.isMember("VkPhysicalDeviceVulkan11Features")) {
                        pdd_->vulkan_1_1_features_written_ = true;
                    }
                    if (features.isMember("VkPhysicalDeviceVulkan12Features")) {
                        pdd_->vulkan_1_2_features_written_ = true;
                    }
                    if (features.isMember("VkPhysicalDeviceVulkan13Features")) {
                        pdd_->vulkan_1_3_features_written_ = true;
                    }
                    if (features.isMember("VkPhysicalDeviceVulkan14Features")) {
                        pdd_->vulkan_1_4_features_written_ = true;
                    }
                    bool success = GetFeature(device_name, enable_warnings, features, feature);
                    if (!success) {
                        failed = true;
                    }
                }
            }

            if (layer_settings.simulate.capabilities & SIMULATE_PROPERTIES_BIT) {
                bool duplicated = !WarnDuplicatedProperty(properties);
                if (duplicated) {
                    failed = true;
                }

                if (properties.isMember("VkPhysicalDeviceVulkan11Properties")) {
                    pdd_->vulkan_1_1_properties_written_ = true;
                }
                if (properties.isMember("VkPhysicalDeviceVulkan12Properties")) {
                    pdd_->vulkan_1_2_properties_written_ = true;
                }
                if (properties.isMember("VkPhysicalDeviceVulkan13Properties")) {
                    pdd_->vulkan_1_3_properties_written_ = true;
                }
                if (properties.isMember("VkPhysicalDeviceVulkan14Properties")) {
                    pdd_->vulkan_1_4_properties_written_ = true;
                }
                for (const auto &prop : properties.getMemberNames()) {
                    bool success = GetProperty(device_name, enable_warnings, properties, prop);
                    if (!success) {
                        failed = true;
                    }
                }
            }

            if (layer_settings.simulate.capabilities & SIMULATE_FORMATS_BIT) {
                const auto &formats = cap_definision["formats"];

                for (const auto &format : formats.getMemberNames()) {
                    bool success = GetFormat(device_name, enable_warnings, formats, format, &pdd_->map_of_format_properties_, &pdd_->map_of_format_properties_3_);
                    if (!success) {
                        failed = true;
                    }
                }
            }

            if (layer_settings.simulate.capabilities & SIMULATE_QUEUE_FAMILY_PROPERTIES_BIT) {
                const auto &qf_props = cap_definision["queueFamiliesProperties"];

                bool queue_families_supported = true;
                for (const auto &qfp : qf_props) {
                    pdd_->arrayof_queue_family_properties_.emplace_back();
                    bool success = GetQueueFamilyProperties(device_name, qfp, &pdd_->arrayof_queue_family_properties_.back());
                    if (!success) {
                        queue_families_supported = false;
                        failed = true;
                    }
                }
                if (queue_families_supported) {
                    bool success = OrderQueueFamilyProperties(&pdd_->arrayof_queue_family_properties_);
                    if (!success) {
                        failed = true;
                    }
                }
            }
        }
    }

#ifndef VULKANSC
    if (layer_settings.simulate.capabilities & (SIMULATE_VIDEO_CAPABILITIES_BIT | SIMULATE_VIDEO_FORMATS_BIT)) {
        // Handle video profiles

        struct JsonVideoProfileData {
            JsonVideoProfileInfo info{};
            JsonVideoProfileCaps caps{};
            std::vector<JsonVideoProfileFormat> formats{};
        };
        std::vector<JsonVideoProfileData> parsed_video_profiles{};

        for (const auto &capability_variants : capabilities) {
            for (const auto &capability_variant : capability_variants) {
                const auto &cap_definition = cap_definisions[capability_variant];
                if (cap_definition.isMember("videoProfiles")) {
                    const auto &json_video_profiles = cap_definition["videoProfiles"];
                    parsed_video_profiles.reserve(json_video_profiles.size());
                    for (const auto &json_video_profile : json_video_profiles) {
                        JsonVideoProfileData video_profile{};

                        video_profile.info = JsonVideoProfileInfo(json_video_profile);
                        if (!video_profile.info.IsValid()) {
                            LogMessage(&layer_settings, DEBUG_REPORT_ERROR_BIT, "Invalid video profile info defined in the profile\n");
                            failed = true;
                            continue;
                        }

                        video_profile.caps = JsonVideoProfileCaps(json_video_profile);
                        if (!video_profile.caps.IsValid()) {
                            LogMessage(&layer_settings, DEBUG_REPORT_ERROR_BIT, "Invalid video profile capabilities defined in the profile\n");
                            failed = true;
                            continue;
                        }

                        if (json_video_profile.isMember("formats")) {
                            const auto &formats = json_video_profile["formats"];
                            video_profile.formats.reserve(formats.size());
                            for (const auto &format : formats) {
                                JsonVideoProfileFormat fmt(format);
                                if (fmt.IsValid()) {
                                    video_profile.formats.push_back(std::move(fmt));
                                } else {
                                    LogMessage(&layer_settings, DEBUG_REPORT_ERROR_BIT, "Invalid video profile format defined in the profile\n");
                                    failed = true;
                                    continue;
                                }
                            }
                        }

                        parsed_video_profiles.push_back(std::move(video_profile));
                    }
                }
            }
        }

        if (!parsed_video_profiles.empty()) {
            auto for_each_matching_video_profile = [&](const VideoProfileInfoChain &video_profile_info,
                                                    std::function<void(const JsonVideoProfileData&)> callback) {
                for (const auto &parsed_video_profile : parsed_video_profiles) {
                    if (parsed_video_profile.info.IsMatching(video_profile_info)) {
                        callback(parsed_video_profile);
                    }
                }
            };
            auto for_each_matching_video_profile_format = [&](const VideoProfileInfoChain &video_profile_info,
                                                            std::function<void(const JsonVideoProfileFormat&)> callback) {
                for_each_matching_video_profile(video_profile_info, [&](const JsonVideoProfileData &json_video_profile) {
                    for (const auto &json_video_format : json_video_profile.formats) {
                        callback(json_video_format);
                    }
                });
            };
            auto check_api_version = [&](uint32_t api_version) { return this->profile_api_version_ >= api_version; };
            auto check_extension = [&](const char* extension) { return PhysicalDeviceData::HasSimulatedExtension(pdd_, extension); };

            ForEachVideoProfile([&](const VkVideoProfileInfoKHR& info, const char *name) {
                std::string device_and_profile_name = std::string(device_name) + ", video profile '" + name + "'";
                bool insert_video_profile_data = false;
                VideoProfileData video_profile{};

                // Construct and verify video profile info chain
                video_profile.info = VideoProfileInfoChain(&info);
                if (!video_profile.info.valid) {
                    LogMessage(&layer_settings, DEBUG_REPORT_ERROR_BIT, "Invalid video profile info chain for video profile '%s'\n", name);
                    failed = true;
                    return;
                }

                // Construct and verify video profile capabilities chain
                video_profile.caps = VideoCapabilitiesChain(info.videoCodecOperation, check_api_version, check_extension);
                if (!video_profile.caps.valid) {
                    LogMessage(&layer_settings, DEBUG_REPORT_ERROR_BIT, "Invalid video capabilities chain for video profile '%s'\n", name);
                    failed = true;
                    return;
                }

                // Track whether the video profile is supported by the device or profile, as simulation flags indicate
                bool supported = false;

                // Initialize capabilities with the physical device supported video profile data, if available
                auto pd_video_profile = pdd_->set_of_device_video_profiles_.find(video_profile);
                if (pd_video_profile != pdd_->set_of_device_video_profiles_.end()) {
                    // We update and not copy the capabilities object here because the supported API version and
                    // extensions may be different between the physical device and the simulated device so
                    // the list of structures supported and available in the pNext chain may also be different
                    video_profile.caps.UpdateFrom(pd_video_profile->caps);
                    supported = true;
                }

                if (layer_settings.simulate.capabilities & SIMULATE_VIDEO_CAPABILITIES_BIT) {
                    // Find matching video profiles defined in the profile and aggregate their video capabilities
                    bool found_matching = false;
                    bool found_matching_completely_defined = false;
                    JsonVideoProfileCaps merged_caps{};
                    for_each_matching_video_profile(video_profile.info, [&](const JsonVideoProfileData &json_video_profile) {
                        found_matching = true;
                        if (!found_matching_completely_defined &&
                            json_video_profile.info.IsComplete(video_profile.info)) {
                            found_matching_completely_defined = true;
                        }

                        bool success = merged_caps.Combine(&layer_settings, json_video_profile.caps);
                        if (!success) {
                            LogMessage(&layer_settings, DEBUG_REPORT_ERROR_BIT,
                                       "Failed to merge video capabilities for video profile '%s'\n", name);
                            failed = true;
                        }
                    });

                    if (found_matching) {
                        bool supported_by_device = supported;
                        if (!supported_by_device && found_matching_completely_defined) {
                            LogMessage(&layer_settings, DEBUG_REPORT_WARNING_BIT,
                                       "Simulating video profile '%s' that is not supported by the device\n", name);
                            supported = true;
                        }

                        if (supported) {
                            // Replace video capabilities with the values defined in the profile
                            if (supported_by_device) {
                                if (!merged_caps.Override(&layer_settings, video_profile.caps, name, enable_warnings)) {
                                    failed = true;
                                }
                            } else {
                                merged_caps.CopyTo(video_profile.caps);
                            }

                            // Special case: if neither distinct nor coincide output is supported by a decode profile
                            // then enable distinct by default
                            const VkVideoDecodeCapabilityFlagsKHR output_mode_flags = VK_VIDEO_DECODE_CAPABILITY_DPB_AND_OUTPUT_DISTINCT_BIT_KHR |
                                                                                    VK_VIDEO_DECODE_CAPABILITY_DPB_AND_OUTPUT_COINCIDE_BIT_KHR;
                            if ((video_profile.caps.video_decode_capabilities_.flags & output_mode_flags) == 0) {
                                video_profile.caps.video_decode_capabilities_.flags |= VK_VIDEO_DECODE_CAPABILITY_DPB_AND_OUTPUT_DISTINCT_BIT_KHR;
                            }

                            // Make sure the video profile will be inserted
                            insert_video_profile_data = true;
                        }
                    } else {
                        supported = false;
                    }
                }

                if (layer_settings.simulate.capabilities & SIMULATE_VIDEO_FORMATS_BIT && supported) {
                    // Go through each video format category supported by the video profile
                    for (const auto usage : video_profile.GetSupportedFormatCategories()) {
                        std::vector<VideoFormatPropertiesChain> formats{};
                        SetOfVideoProfileFormats device_formats{};

                        // The initial set of formats is taken from the physical device supported ones, if there are any,
                        // and they match any of the profile defined ones
                        if (pd_video_profile != pdd_->set_of_device_video_profiles_.end()) {
                            auto pd_video_formats = pd_video_profile->formats.find(usage);
                            if (pd_video_formats != pd_video_profile->formats.end()) {
                                for (const auto &pd_video_format : pd_video_formats->second) {
                                    bool found_matching = false;
                                    for_each_matching_video_profile_format(video_profile.info, [&](const JsonVideoProfileFormat &json_video_format) {
                                        if (json_video_format.IsMatchingUsage(usage) &&
                                            json_video_format.IsMatching(pd_video_format)) {
                                            found_matching = true;
                                        }
                                    });
                                    if (found_matching) {
                                        // We create and update a new format object here because the supported API version and
                                        // extensions may be different between the physical device and the simulated device so
                                        // the list of structures supported and available in the pNext chain may also be different
                                        VideoFormatPropertiesChain format(info.videoCodecOperation, usage, check_api_version, check_extension);
                                        format.UpdateFrom(pd_video_format);
                                        formats.push_back(format);
                                        device_formats.insert(format);
                                    }
                                }
                            }
                        }

                        // Then, additional formats are added that are fully defined in the profile and do not match
                        // any of the existing ones already included
                        for_each_matching_video_profile_format(video_profile.info, [&](const JsonVideoProfileFormat &json_video_format) {
                            if (!json_video_format.IsMatchingUsage(usage)) return;

                            bool found_matching = false;
                            for (const auto &format : formats) {
                                if (json_video_format.IsMatching(format)) {
                                    found_matching = true;
                                    break;
                                }
                            }
                            if (!found_matching) {
                                VideoFormatPropertiesChain format(info.videoCodecOperation, usage, check_api_version, check_extension);
                                if (json_video_format.IsComplete(format)) {
                                    json_video_format.CopyTo(format);
                                    LogMessage(&layer_settings, DEBUG_REPORT_WARNING_BIT,
                                               "Simulating video format %s for video profile '%s' that is not supported by the device\n",
                                               vkFormatToString(format.video_format_properties_.format).c_str(), name);
                                    formats.push_back(format);
                                }
                            }
                        });

                        // Now it is time to find all matching video formats defined in the profile and aggregate their properties
                        for (auto &format : formats) {
                            JsonVideoProfileFormat merged_props{};
                            for_each_matching_video_profile_format(video_profile.info, [&](const JsonVideoProfileFormat &json_video_format) {
                                if (json_video_format.IsMatchingUsage(usage) &&
                                    json_video_format.IsMatching(format)) {
                                    bool success = merged_props.Combine(&layer_settings, json_video_format);
                                    if (!success) {
                                        LogMessage(&layer_settings, DEBUG_REPORT_ERROR_BIT,
                                                   "Failed to merge video format %s data for video profile '%s'\n",
                                                   vkFormatToString(format.video_format_properties_.format).c_str(), name);
                                        failed = true;
                                    }
                                }
                            });
                            // Replace video format properties with the values defined in the profile
                            // Only enable warnings if we're replacing the properties of a device supported video format
                            if (device_formats.find(format) != device_formats.end()) {
                                if (!merged_props.Override(&layer_settings, format, name, enable_warnings)) {
                                    failed = true;
                                }
                            } else {
                                merged_props.Override(&layer_settings, format, name, false);
                            }

                            // Make sure that usage is kept even if the profile data did not explicitly include it
                            format.video_format_properties_.imageUsageFlags |= usage;
                        }

                        // Special case: if coincide decode output mode is supported, then we need to have at least one
                        // format that supports both decode output and decode DPB usage, so if no such format is found
                        // then replace coincide decode output mode with distinct
                        // if necessary
                        if (video_profile.caps.video_decode_capabilities_.flags & VK_VIDEO_DECODE_CAPABILITY_DPB_AND_OUTPUT_COINCIDE_BIT_KHR) {
                            const VkImageUsageFlags coincide_usage = VK_IMAGE_USAGE_VIDEO_DECODE_DST_BIT_KHR;
                            bool found_coincide_format = false;
                            for (const auto &format : formats) {
                                if ((format.video_format_properties_.imageUsageFlags & coincide_usage) == coincide_usage) {
                                    found_coincide_format = true;
                                    break;
                                }
                            }
                            if (!found_coincide_format) {
                                video_profile.caps.video_decode_capabilities_.flags ^= VK_VIDEO_DECODE_CAPABILITY_DPB_AND_OUTPUT_COINCIDE_BIT_KHR;
                                video_profile.caps.video_decode_capabilities_.flags |= VK_VIDEO_DECODE_CAPABILITY_DPB_AND_OUTPUT_DISTINCT_BIT_KHR;
                            }
                        }

                        // Store the formats and make sure the video profile will be inserted
                        for (const auto &format : formats) {
                            video_profile.formats[usage].insert(format);
                        }
                        insert_video_profile_data = true;
                    }
                }

                // Insert the video profile data if any profile simulated video capability or video format indicates so
                if (insert_video_profile_data) {
                    pdd_->set_of_video_profiles_.insert(video_profile);
                }
            });
        }
    }
#endif  // VULKANSC

    if (requested_profile) {
        if (properties_api_version != 0) {
            LogMessage(&layer_settings, DEBUG_REPORT_NOTIFICATION_BIT,
                "- VkPhysicalDeviceProperties API version: %" PRIu32 ".%" PRIu32 ".%" PRIu32 ". Using the API version specified by the profile VkPhysicalDeviceProperties structure.\n",
                VK_API_VERSION_MAJOR(properties_api_version), VK_API_VERSION_MINOR(properties_api_version), VK_API_VERSION_PATCH(properties_api_version));
        } else if (layer_settings.simulate.capabilities & SIMULATE_API_VERSION_BIT) {
            LogMessage(&layer_settings, DEBUG_REPORT_NOTIFICATION_BIT,
                "- VkPhysicalDeviceProperties API version: %" PRIu32 ".%" PRIu32 ".%" PRIu32". Using the API version specified by the profile.\n",
                VK_API_VERSION_MAJOR(this->profile_api_version_), VK_API_VERSION_MINOR(this->profile_api_version_), VK_API_VERSION_PATCH(this->profile_api_version_));

            pdd_->physical_device_properties_.apiVersion = this->profile_api_version_;
        } else {
            LogMessage(&layer_settings, DEBUG_REPORT_NOTIFICATION_BIT,
                "- VkPhysicalDeviceProperties API version: %" PRIu32 ".%" PRIu32 ".%" PRIu32 ". Using the device version.\n",
                    VK_API_VERSION_MAJOR(pdd_->physical_device_properties_.apiVersion),
                    VK_API_VERSION_MINOR(pdd_->physical_device_properties_.apiVersion),
                    VK_API_VERSION_PATCH(pdd_->physical_device_properties_.apiVersion));
        }
    }

    if (failed && layer_settings.log.debug_fail_on_error) {
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    return VK_SUCCESS;
}

VkResult JsonLoader::LoadFile(const std::string& filename) {
    if (filename.empty()) {
        return VK_SUCCESS;
    }
    std::ifstream json_file(filename);
    if (!json_file) {
        LogMessage(&layer_settings, DEBUG_REPORT_ERROR_BIT, "Fail to open file \"%s\"\n", filename.c_str());
        return VK_SUCCESS;
    }

    Json::Value root = Json::nullValue;
    Json::CharReaderBuilder builder;
    std::string errs;
    bool success = Json::parseFromStream(builder, json_file, &root, &errs);
    if (!success) {
        LogMessage(&layer_settings, DEBUG_REPORT_ERROR_BIT, "Fail to parse file \"%s\" {\n%s}\n", filename.c_str(), errs.c_str());
        return VK_SUCCESS;
    }
    json_file.close();

    if (root.type() != Json::objectValue) {
        LogMessage(&layer_settings, DEBUG_REPORT_ERROR_BIT, "Json document root is not an object in file \"%s\"\n", filename.c_str());
        return VK_SUCCESS;
    }

#ifndef VULKANSC
    const Json::Value& schema_node = root["$schema"];
    if (schema_node == Json::Value::nullSingleton()) {
        return VK_SUCCESS;
    }

    const std::string &schema = schema_node.asCString();
    if (schema.find("https://schema.khronos.org/vulkan/profiles") == std::string::npos) {
        return VK_SUCCESS;
    }
#endif  // VULKANSC

    LogMessage(&layer_settings, DEBUG_REPORT_NOTIFICATION_BIT, "Loading \"%s\"\n", filename.c_str());

    if (layer_settings.simulate.profile_validation) {
        JsonValidator validator;
        if (!validator.Init()) {
            LogMessage(&layer_settings, DEBUG_REPORT_WARNING_BIT,
                "%s could not find the profile schema file to validate filename. This operation requires the Vulkan SDK to be installed. Skipping profile file validation.\n",
                kLayerName, filename.c_str());
        } else if (!validator.Check(root)) {
            LogMessage(&layer_settings, DEBUG_REPORT_ERROR_BIT,
                "%s is not a valid JSON profile file.\n", filename.c_str());
            if (layer_settings.log.debug_fail_on_error) {
                return VK_ERROR_INITIALIZATION_FAILED;
            } else {
                return VK_SUCCESS;
            }
        }
    }

    this->profiles_file_roots_.insert(std::pair(filename, root));

    return VK_SUCCESS;
}

VkResult JsonLoader::LoadProfilesDatabase() {
    if (!layer_settings.simulate.profile_file.empty()) {
        VkResult result = this->LoadFile(layer_settings.simulate.profile_file);
        if (result != VK_SUCCESS) {
            return result;
        }
    }

    for (std::size_t i = 0, n = layer_settings.simulate.profile_dirs.size(); i < n; ++i) {
        const std::string& path = layer_settings.simulate.profile_dirs[i];

        if (fs::is_regular_file(path)) {
            this->LoadFile(path);
            continue;
        }

        for (const auto& entry : fs::directory_iterator(path)) {
            if (fs::is_directory(entry.path())) {
                continue;
            }

            const std::string& file_path = entry.path().generic_string();
            if (!EndsWith(file_path, ".json")) {
                continue;
            }

            VkResult result = this->LoadFile(file_path);
            if (result != VK_SUCCESS) {
                continue;
            }
        }
    }

    LogFoundProfiles();

    ReadProfileApiVersion();

    return VK_SUCCESS;
}

void JsonLoader::LogFoundProfiles() {
    for (const auto& root : this->profiles_file_roots_) {
        LogMessage(&layer_settings, DEBUG_REPORT_NOTIFICATION_BIT, "Profiles found in '%s' file:\n", root.first.c_str());

        const Json::Value &profiles = root.second["profiles"];

        for (const std::string &profile : profiles.getMemberNames()) {
            LogMessage(&layer_settings, DEBUG_REPORT_NOTIFICATION_BIT, "- %s\n", profile.c_str());
        }
    }
}

const Json::Value& JsonLoader::FindRootFromProfileName(const std::string& profile_name) const {
    for (const auto& root : this->profiles_file_roots_) {
        const Json::Value &profiles = root.second["profiles"];

        for (const auto &profile : profiles.getMemberNames()) {
            if (profile_name.empty() || profile_name == "${VP_DEFAULT}" || profile == profile_name) {
                return root.second;
            }
        }
    }

    return Json::Value::nullSingleton();
}

void JsonLoader::ReadProfileApiVersion() {
    const std::string &profile_name = layer_settings.simulate.profile_name;
    const Json::Value &profiles = FindRootFromProfileName(profile_name)["profiles"];
    bool found_profile = false;
    for (const auto &profile : profiles.getMemberNames()) {
        if (profile_name.empty() || profile_name == "${VP_DEFAULT}" || profile == profile_name) {
            const std::string version_string = profiles[profile]["api-version"].asCString();

            uint32_t api_major = 0;
            uint32_t api_minor = 0;
            uint32_t api_patch = 0;
            std::sscanf(version_string.c_str(), "%u.%u.%u", &api_major, &api_minor, &api_patch);
#ifdef VULKANSC
            profile_api_version_ = VK_MAKE_API_VERSION(VKSC_API_VARIANT, api_major, api_minor, api_patch);
#else
            profile_api_version_ = VK_MAKE_API_VERSION(0, api_major, api_minor, api_patch);
#endif
            found_profile = true;
            break;
        }
    }
    if (!found_profile && profiles) {
        // Systematically load the first and default profile when the profile is not found
        const auto profile = profiles.getMemberNames()[0];
        const std::string version_string = profiles[profile]["api-version"].asCString();

        uint32_t api_major = 0;
        uint32_t api_minor = 0;
        uint32_t api_patch = 0;
        std::sscanf(version_string.c_str(), "%u.%u.%u", &api_major, &api_minor, &api_patch);
#ifdef VULKANSC
        profile_api_version_ = VK_MAKE_API_VERSION(VKSC_API_VARIANT, api_major, api_minor, api_patch);
#else
        profile_api_version_ = VK_MAKE_API_VERSION(0, api_major, api_minor, api_patch);
#endif
    }

    for (const auto& extension : layer_settings.simulate.exclude_device_extensions) {
        if (extension.empty()) continue;
        excluded_extensions_.push_back(extension);
    }
    for (const auto& format : layer_settings.simulate.exclude_formats) {
        if (format.empty()) continue;
        excluded_formats_.push_back(format);
    }
}

void JsonLoader::CollectProfiles(const std::string& profile_name, std::vector<std::string>& results) const {
    const auto &root = FindRootFromProfileName(profile_name);

    if (root != Json::Value::nullSingleton()) {
        const Json::Value &profiles = root["profiles"];
        std::vector<std::vector<std::string>> capabilities;

        for (const auto &profile : profiles.getMemberNames()) {
            if (profile == profile_name) {
                const auto &required_profiles = profiles[profile]["profiles"];

                for (const auto &required_profile : required_profiles) {
                    this->CollectProfiles(required_profile.asString().c_str(), results);
                }

                break;  // load a single profile
            }
        }
    }

    results.push_back(profile_name);
}

VkResult JsonLoader::LoadDevice(const char* device_name, PhysicalDeviceData *pdd) {
    pdd_ = pdd;

    const std::string &requested_profile_name = layer_settings.simulate.profile_name;

    if (this->profiles_file_roots_.empty() && (requested_profile_name.empty() || requested_profile_name == "${VP_DEFAULT}")) {
        return VK_SUCCESS;
    }

    VkResult result = VK_SUCCESS;

    std::vector<std::string> required_profiles;
    CollectProfiles(requested_profile_name, required_profiles);

    for (const std::string& profile_name : required_profiles) {
        const auto& root = FindRootFromProfileName(profile_name);

        if (root == Json::Value::nullSingleton()) {
            if (requested_profile_name == profile_name) {
                LogMessage(&layer_settings, DEBUG_REPORT_ERROR_BIT, "- '%s' profile not found.\n", profile_name.c_str());
            } else {
                LogMessage(&layer_settings, DEBUG_REPORT_ERROR_BIT, "- '%s' profile required by '%s' not found.\n", profile_name.c_str(), requested_profile_name.c_str());
            }

            result = VK_ERROR_UNKNOWN;
        } else {
            if (requested_profile_name == profile_name) {
                LogMessage(&layer_settings, DEBUG_REPORT_NOTIFICATION_BIT, "- Overriding device capabilities with the '%s' profile capabilities.\n", profile_name.c_str());
            } else {
                LogMessage(&layer_settings, DEBUG_REPORT_NOTIFICATION_BIT, "- Overriding device capabilities with the '%s' profile capabilities required by the requested '%s' profile.\n", profile_name.c_str(), requested_profile_name.c_str());
            }

            const Json::Value &profiles = root["profiles"];
            std::vector<std::vector<std::string>> capabilities;

            bool found_profile = false;
            for (const auto &profile : profiles.getMemberNames()) {
                if (profile_name.empty() || profile_name == "${VP_DEFAULT}" || profile == profile_name) {
                    const auto &caps = profiles[profile]["capabilities"];

                    for (const auto &cap : caps) {
                        std::vector<std::string> cap_variants;
                        if (cap.isArray()) {
                            for (const auto &cap_variant : cap) {
                                cap_variants.push_back(cap_variant.asString());
                            }
                        } else {
                            cap_variants.push_back(cap.asString());
                        }
                        capabilities.push_back(cap_variants);
                    }

                    found_profile = true;
                    break;  // load a single profile
                }
            }
            if (!found_profile && profiles) {
                // Systematically load the first and default profile
                const auto profile = profiles.getMemberNames()[0];
                const auto &caps = profiles[profile]["capabilities"];

                for (const auto &cap : caps) {
                    std::vector<std::string> cap_variants;
                    if (cap.isArray()) {
                        for (const auto &cap_variant : cap) {
                            cap_variants.push_back(cap_variant.asString());
                        }
                    } else {
                        cap_variants.push_back(cap.asString());
                    }
                    capabilities.push_back(cap_variants);
                }
            }

            if (capabilities.empty()) {
                return VK_SUCCESS;
            }

            const Json::Value schema_value = root["$schema"];
            if (!schema_value.isString()) {
                LogMessage(&layer_settings, DEBUG_REPORT_ERROR_BIT, "JSON element \"$schema\" is not a string\n");
                return layer_settings.log.debug_fail_on_error ? VK_ERROR_INITIALIZATION_FAILED : VK_SUCCESS;
            }

            const std::string schema = schema_value.asCString();
            if (schema.find(SCHEMA_URI_BASE) == std::string::npos) {
                LogMessage(&layer_settings, DEBUG_REPORT_ERROR_BIT, "Document schema \"%s\" not supported by %s\n", schema.c_str(), kLayerName);
                return layer_settings.log.debug_fail_on_error ? VK_ERROR_INITIALIZATION_FAILED : VK_SUCCESS;
            }

            const std::size_t size_schema = schema.size();
            const std::size_t size_base = std::strlen(SCHEMA_URI_BASE);
            const std::size_t size_version = std::strlen(".json#");
            const std::string version = schema.substr(size_base, size_schema - size_base - size_version);

            uint32_t version_major = 0;
            uint32_t version_minor = 0;
            uint32_t version_patch = 0;
            std::sscanf(version.c_str(), "%u.%u.%u", &version_major, &version_minor, &version_patch);
            if (VK_HEADER_VERSION < version_patch) {
                LogMessage(&layer_settings, DEBUG_REPORT_WARNING_BIT,
                    "%s is built against Vulkan Header %d but the profile is written against Vulkan Header %d.\n\t- All newer capabilities in the profile will be ignored by the layer.\n",
                    kLayerName, VK_HEADER_VERSION, version_patch);
            }

            VkResult tmp_result = VK_SUCCESS;
            if (layer_settings.simulate.capabilities & SIMULATE_EXTENSIONS_BIT) {
                pdd_->simulation_extensions_.clear();
            }

            tmp_result = ReadProfile(device_name, root, capabilities, requested_profile_name == profile_name, required_profiles.size() == 1);
            if (tmp_result != VK_SUCCESS) {
                result = tmp_result;
            }
        }

        if (result != VK_SUCCESS) {
            break;
        }
    }

    return result;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDevicePushDescriptorProperties *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDevicePushDescriptorProperties)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, maxPushDescriptors, false, requested_profile, WarnIfGreater);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceDriverProperties *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceDriverProperties)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_ENUM_WARN(member, driverID, true, requested_profile, WarnIfNotEqualEnum);
        GetArray(device_name, parent, member, "driverName", dest->driverName, true);
        GetArray(device_name, parent, member, "driverInfo", dest->driverInfo, true);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceIDProperties *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceIDProperties)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GetArray(device_name, parent, member, "deviceUUID", dest->deviceUUID, true);
        GetArray(device_name, parent, member, "driverUUID", dest->driverUUID, true);
        GetArray(device_name, parent, member, "deviceLUID", dest->deviceLUID, false);
        GET_VALUE_WARN(member, deviceNodeMask, true, requested_profile, WarnIfNotEqual32u);
        GET_VALUE_WARN(member, deviceLUIDValid, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceMultiviewProperties *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceMultiviewProperties)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, maxMultiviewViewCount, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxMultiviewInstanceIndex, false, requested_profile, WarnIfGreater);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceSubgroupProperties *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceSubgroupProperties)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, subgroupSize, false, requested_profile, WarnIfGreater);
        GET_VALUE_FLAG_WARN(member, supportedStages, false, requested_profile);
        GET_VALUE_FLAG_WARN(member, supportedOperations, false, requested_profile);
        GET_VALUE_WARN(member, quadOperationsInAllStages, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDevicePointClippingProperties *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDevicePointClippingProperties)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_ENUM_WARN(member, pointClippingBehavior, true, requested_profile, WarnIfNotEqualEnum);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceProtectedMemoryProperties *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceProtectedMemoryProperties)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, protectedNoFault, true, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceSamplerFilterMinmaxProperties *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceSamplerFilterMinmaxProperties)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, filterMinmaxSingleComponentFormats, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, filterMinmaxImageComponentMapping, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceInlineUniformBlockProperties *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceInlineUniformBlockProperties)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, maxInlineUniformBlockSize, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxPerStageDescriptorInlineUniformBlocks, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxDescriptorSetInlineUniformBlocks, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxDescriptorSetUpdateAfterBindInlineUniformBlocks, false, requested_profile, WarnIfGreater);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceMaintenance3Properties *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceMaintenance3Properties)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, maxPerSetDescriptors, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxMemoryAllocationSize, false, requested_profile, WarnIfGreater);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceMaintenance4Properties *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceMaintenance4Properties)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, maxBufferSize, false, requested_profile, WarnIfGreater);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceMaintenance5Properties *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceMaintenance5Properties)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, earlyFragmentMultisampleCoverageAfterSampleCounting, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, earlyFragmentSampleMaskTestBeforeSampleCounting, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, depthStencilSwizzleOneSupport, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, polygonModePointSize, true, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, nonStrictSinglePixelWideLinesUseParallelogram, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, nonStrictWideLinesUseParallelogram, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceMaintenance6Properties *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceMaintenance6Properties)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, blockTexelViewCompatibleMultipleLayers, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, maxCombinedImageSamplerDescriptorCount, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, fragmentShadingRateClampCombinerInputs, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceFloatControlsProperties *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceFloatControlsProperties)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_ENUM_WARN(member, denormBehaviorIndependence, true, requested_profile, WarnIfNotEqualEnum);
        GET_VALUE_ENUM_WARN(member, roundingModeIndependence, true, requested_profile, WarnIfNotEqualEnum);
        GET_VALUE_WARN(member, shaderSignedZeroInfNanPreserveFloat16, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderSignedZeroInfNanPreserveFloat32, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderSignedZeroInfNanPreserveFloat64, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderDenormPreserveFloat16, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderDenormPreserveFloat32, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderDenormPreserveFloat64, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderDenormFlushToZeroFloat16, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderDenormFlushToZeroFloat32, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderDenormFlushToZeroFloat64, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderRoundingModeRTEFloat16, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderRoundingModeRTEFloat32, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderRoundingModeRTEFloat64, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderRoundingModeRTZFloat16, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderRoundingModeRTZFloat32, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderRoundingModeRTZFloat64, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceDescriptorIndexingProperties *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceDescriptorIndexingProperties)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, maxUpdateAfterBindDescriptorsInAllPools, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, shaderUniformBufferArrayNonUniformIndexingNative, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderSampledImageArrayNonUniformIndexingNative, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderStorageBufferArrayNonUniformIndexingNative, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderStorageImageArrayNonUniformIndexingNative, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderInputAttachmentArrayNonUniformIndexingNative, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, robustBufferAccessUpdateAfterBind, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, quadDivergentImplicitLod, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, maxPerStageDescriptorUpdateAfterBindSamplers, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxPerStageDescriptorUpdateAfterBindUniformBuffers, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxPerStageDescriptorUpdateAfterBindStorageBuffers, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxPerStageDescriptorUpdateAfterBindSampledImages, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxPerStageDescriptorUpdateAfterBindStorageImages, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxPerStageDescriptorUpdateAfterBindInputAttachments, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxPerStageUpdateAfterBindResources, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxDescriptorSetUpdateAfterBindSamplers, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxDescriptorSetUpdateAfterBindUniformBuffers, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxDescriptorSetUpdateAfterBindUniformBuffersDynamic, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxDescriptorSetUpdateAfterBindStorageBuffers, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxDescriptorSetUpdateAfterBindStorageBuffersDynamic, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxDescriptorSetUpdateAfterBindSampledImages, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxDescriptorSetUpdateAfterBindStorageImages, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxDescriptorSetUpdateAfterBindInputAttachments, false, requested_profile, WarnIfGreater);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceTimelineSemaphoreProperties *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceTimelineSemaphoreProperties)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, maxTimelineSemaphoreValueDifference, false, requested_profile, WarnIfGreater);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceDepthStencilResolveProperties *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceDepthStencilResolveProperties)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_FLAG_WARN(member, supportedDepthResolveModes, false, requested_profile);
        GET_VALUE_FLAG_WARN(member, supportedStencilResolveModes, false, requested_profile);
        GET_VALUE_WARN(member, independentResolveNone, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, independentResolve, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceVulkan11Properties *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceVulkan11Properties)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GetArray(device_name, parent, member, "deviceUUID", dest->deviceUUID, true);
        GetArray(device_name, parent, member, "driverUUID", dest->driverUUID, true);
        GetArray(device_name, parent, member, "deviceLUID", dest->deviceLUID, true);
        GET_VALUE_WARN(member, deviceNodeMask, true, requested_profile, WarnIfNotEqual32u);
        GET_VALUE_WARN(member, deviceLUIDValid, true, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, subgroupSize, false, requested_profile, WarnIfGreater);
        GET_VALUE_FLAG_WARN(member, subgroupSupportedStages, false, requested_profile);
        GET_VALUE_FLAG_WARN(member, subgroupSupportedOperations, false, requested_profile);
        GET_VALUE_WARN(member, subgroupQuadOperationsInAllStages, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_ENUM_WARN(member, pointClippingBehavior, true, requested_profile, WarnIfNotEqualEnum);
        GET_VALUE_WARN(member, maxMultiviewViewCount, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxMultiviewInstanceIndex, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, protectedNoFault, true, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, maxPerSetDescriptors, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxMemoryAllocationSize, false, requested_profile, WarnIfGreater);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceVulkan12Properties *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceVulkan12Properties)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_ENUM_WARN(member, driverID, true, requested_profile, WarnIfNotEqualEnum);
        GetArray(device_name, parent, member, "driverName", dest->driverName, true);
        GetArray(device_name, parent, member, "driverInfo", dest->driverInfo, true);
        GET_VALUE_ENUM_WARN(member, denormBehaviorIndependence, true, requested_profile, WarnIfNotEqualEnum);
        GET_VALUE_ENUM_WARN(member, roundingModeIndependence, true, requested_profile, WarnIfNotEqualEnum);
        GET_VALUE_WARN(member, shaderSignedZeroInfNanPreserveFloat16, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderSignedZeroInfNanPreserveFloat32, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderSignedZeroInfNanPreserveFloat64, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderDenormPreserveFloat16, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderDenormPreserveFloat32, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderDenormPreserveFloat64, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderDenormFlushToZeroFloat16, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderDenormFlushToZeroFloat32, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderDenormFlushToZeroFloat64, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderRoundingModeRTEFloat16, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderRoundingModeRTEFloat32, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderRoundingModeRTEFloat64, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderRoundingModeRTZFloat16, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderRoundingModeRTZFloat32, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderRoundingModeRTZFloat64, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, maxUpdateAfterBindDescriptorsInAllPools, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, shaderUniformBufferArrayNonUniformIndexingNative, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderSampledImageArrayNonUniformIndexingNative, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderStorageBufferArrayNonUniformIndexingNative, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderStorageImageArrayNonUniformIndexingNative, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderInputAttachmentArrayNonUniformIndexingNative, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, robustBufferAccessUpdateAfterBind, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, quadDivergentImplicitLod, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, maxPerStageDescriptorUpdateAfterBindSamplers, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxPerStageDescriptorUpdateAfterBindUniformBuffers, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxPerStageDescriptorUpdateAfterBindStorageBuffers, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxPerStageDescriptorUpdateAfterBindSampledImages, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxPerStageDescriptorUpdateAfterBindStorageImages, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxPerStageDescriptorUpdateAfterBindInputAttachments, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxPerStageUpdateAfterBindResources, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxDescriptorSetUpdateAfterBindSamplers, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxDescriptorSetUpdateAfterBindUniformBuffers, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxDescriptorSetUpdateAfterBindUniformBuffersDynamic, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxDescriptorSetUpdateAfterBindStorageBuffers, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxDescriptorSetUpdateAfterBindStorageBuffersDynamic, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxDescriptorSetUpdateAfterBindSampledImages, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxDescriptorSetUpdateAfterBindStorageImages, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxDescriptorSetUpdateAfterBindInputAttachments, false, requested_profile, WarnIfGreater);
        GET_VALUE_FLAG_WARN(member, supportedDepthResolveModes, false, requested_profile);
        GET_VALUE_FLAG_WARN(member, supportedStencilResolveModes, false, requested_profile);
        GET_VALUE_WARN(member, independentResolveNone, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, independentResolve, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, filterMinmaxSingleComponentFormats, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, filterMinmaxImageComponentMapping, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, maxTimelineSemaphoreValueDifference, false, requested_profile, WarnIfGreater);
        GET_VALUE_FLAG_WARN(member, framebufferIntegerColorSampleCounts, false, requested_profile);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceVulkan13Properties *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceVulkan13Properties)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, minSubgroupSize, false, requested_profile, WarnIfLesser);
        GET_VALUE_WARN(member, maxSubgroupSize, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxComputeWorkgroupSubgroups, false, requested_profile, WarnIfGreater);
        GET_VALUE_FLAG_WARN(member, requiredSubgroupSizeStages, false, requested_profile);
        GET_VALUE_WARN(member, maxInlineUniformBlockSize, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxPerStageDescriptorInlineUniformBlocks, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxDescriptorSetInlineUniformBlocks, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxDescriptorSetUpdateAfterBindInlineUniformBlocks, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxInlineUniformTotalSize, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, integerDotProduct8BitUnsignedAccelerated, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, integerDotProduct8BitSignedAccelerated, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, integerDotProduct8BitMixedSignednessAccelerated, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, integerDotProduct4x8BitPackedUnsignedAccelerated, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, integerDotProduct4x8BitPackedSignedAccelerated, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, integerDotProduct4x8BitPackedMixedSignednessAccelerated, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, integerDotProduct16BitUnsignedAccelerated, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, integerDotProduct16BitSignedAccelerated, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, integerDotProduct16BitMixedSignednessAccelerated, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, integerDotProduct32BitUnsignedAccelerated, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, integerDotProduct32BitSignedAccelerated, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, integerDotProduct32BitMixedSignednessAccelerated, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, integerDotProduct64BitUnsignedAccelerated, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, integerDotProduct64BitSignedAccelerated, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, integerDotProduct64BitMixedSignednessAccelerated, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, integerDotProductAccumulatingSaturating8BitUnsignedAccelerated, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, integerDotProductAccumulatingSaturating8BitSignedAccelerated, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, integerDotProductAccumulatingSaturating8BitMixedSignednessAccelerated, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, integerDotProductAccumulatingSaturating4x8BitPackedUnsignedAccelerated, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, integerDotProductAccumulatingSaturating4x8BitPackedSignedAccelerated, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, integerDotProductAccumulatingSaturating4x8BitPackedMixedSignednessAccelerated, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, integerDotProductAccumulatingSaturating16BitUnsignedAccelerated, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, integerDotProductAccumulatingSaturating16BitSignedAccelerated, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, integerDotProductAccumulatingSaturating16BitMixedSignednessAccelerated, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, integerDotProductAccumulatingSaturating32BitUnsignedAccelerated, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, integerDotProductAccumulatingSaturating32BitSignedAccelerated, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, integerDotProductAccumulatingSaturating32BitMixedSignednessAccelerated, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, integerDotProductAccumulatingSaturating64BitUnsignedAccelerated, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, integerDotProductAccumulatingSaturating64BitSignedAccelerated, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, integerDotProductAccumulatingSaturating64BitMixedSignednessAccelerated, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, storageTexelBufferOffsetAlignmentBytes, false, requested_profile, WarnIfLesser);
        GET_VALUE_WARN(member, storageTexelBufferOffsetSingleTexelAlignment, true, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, uniformTexelBufferOffsetAlignmentBytes, false, requested_profile, WarnIfLesser);
        GET_VALUE_WARN(member, uniformTexelBufferOffsetSingleTexelAlignment, true, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, maxBufferSize, false, requested_profile, WarnIfGreater);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceVulkan14Properties *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceVulkan14Properties)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, lineSubPixelPrecisionBits, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxVertexAttribDivisor, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, supportsNonZeroFirstInstance, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, maxPushDescriptors, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, dynamicRenderingLocalReadDepthStencilAttachments, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, dynamicRenderingLocalReadMultisampledAttachments, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, earlyFragmentMultisampleCoverageAfterSampleCounting, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, earlyFragmentSampleMaskTestBeforeSampleCounting, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, depthStencilSwizzleOneSupport, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, polygonModePointSize, true, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, nonStrictSinglePixelWideLinesUseParallelogram, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, nonStrictWideLinesUseParallelogram, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, blockTexelViewCompatibleMultipleLayers, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, maxCombinedImageSamplerDescriptorCount, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, fragmentShadingRateClampCombinerInputs, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_ENUM_WARN(member, defaultRobustnessStorageBuffers, true, requested_profile, WarnIfNotEqualEnum);
        GET_VALUE_ENUM_WARN(member, defaultRobustnessUniformBuffers, true, requested_profile, WarnIfNotEqualEnum);
        GET_VALUE_ENUM_WARN(member, defaultRobustnessVertexInputs, true, requested_profile, WarnIfNotEqualEnum);
        GET_VALUE_ENUM_WARN(member, defaultRobustnessImages, true, requested_profile, WarnIfNotEqualEnum);
        GET_VALUE_WARN(member, copySrcLayoutCount, true, requested_profile, WarnIfNotEqual32u);
        GetArray(device_name, parent, member, "pCopySrcLayouts", dest->pCopySrcLayouts, &dest->copySrcLayoutCount, false);
        GET_VALUE_WARN(member, copyDstLayoutCount, true, requested_profile, WarnIfNotEqual32u);
        GetArray(device_name, parent, member, "pCopyDstLayouts", dest->pCopyDstLayouts, &dest->copyDstLayoutCount, false);
        GetArray(device_name, parent, member, "optimalTilingLayoutUUID", dest->optimalTilingLayoutUUID, true);
        GET_VALUE_WARN(member, identicalMemoryTypeRequirements, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceHostImageCopyProperties *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceHostImageCopyProperties)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, copySrcLayoutCount, true, requested_profile, WarnIfNotEqual32u);
        GetArray(device_name, parent, member, "pCopySrcLayouts", dest->pCopySrcLayouts, &dest->copySrcLayoutCount, false);
        GET_VALUE_WARN(member, copyDstLayoutCount, true, requested_profile, WarnIfNotEqual32u);
        GetArray(device_name, parent, member, "pCopyDstLayouts", dest->pCopyDstLayouts, &dest->copyDstLayoutCount, false);
        GetArray(device_name, parent, member, "optimalTilingLayoutUUID", dest->optimalTilingLayoutUUID, true);
        GET_VALUE_WARN(member, identicalMemoryTypeRequirements, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceVulkanSC10Properties *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceVulkanSC10Properties)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, deviceNoDynamicHostAllocations, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, deviceDestroyFreesMemory, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, commandPoolMultipleCommandBuffersRecording, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, commandPoolResetCommandBuffer, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, commandBufferSimultaneousUse, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, secondaryCommandBufferNullOrImagelessFramebuffer, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, recycleDescriptorSetMemory, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, recyclePipelineMemory, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, maxRenderPassSubpasses, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxRenderPassDependencies, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxSubpassInputAttachments, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxSubpassPreserveAttachments, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxFramebufferAttachments, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxDescriptorSetLayoutBindings, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxQueryFaultCount, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxCallbackFaultCount, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxCommandPoolCommandBuffers, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxCommandBufferSize, false, requested_profile, WarnIfGreater);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceShaderIntegerDotProductProperties *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceShaderIntegerDotProductProperties)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, integerDotProduct8BitUnsignedAccelerated, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, integerDotProduct8BitSignedAccelerated, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, integerDotProduct8BitMixedSignednessAccelerated, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, integerDotProduct4x8BitPackedUnsignedAccelerated, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, integerDotProduct4x8BitPackedSignedAccelerated, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, integerDotProduct4x8BitPackedMixedSignednessAccelerated, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, integerDotProduct16BitUnsignedAccelerated, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, integerDotProduct16BitSignedAccelerated, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, integerDotProduct16BitMixedSignednessAccelerated, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, integerDotProduct32BitUnsignedAccelerated, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, integerDotProduct32BitSignedAccelerated, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, integerDotProduct32BitMixedSignednessAccelerated, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, integerDotProduct64BitUnsignedAccelerated, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, integerDotProduct64BitSignedAccelerated, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, integerDotProduct64BitMixedSignednessAccelerated, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, integerDotProductAccumulatingSaturating8BitUnsignedAccelerated, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, integerDotProductAccumulatingSaturating8BitSignedAccelerated, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, integerDotProductAccumulatingSaturating8BitMixedSignednessAccelerated, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, integerDotProductAccumulatingSaturating4x8BitPackedUnsignedAccelerated, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, integerDotProductAccumulatingSaturating4x8BitPackedSignedAccelerated, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, integerDotProductAccumulatingSaturating4x8BitPackedMixedSignednessAccelerated, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, integerDotProductAccumulatingSaturating16BitUnsignedAccelerated, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, integerDotProductAccumulatingSaturating16BitSignedAccelerated, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, integerDotProductAccumulatingSaturating16BitMixedSignednessAccelerated, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, integerDotProductAccumulatingSaturating32BitUnsignedAccelerated, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, integerDotProductAccumulatingSaturating32BitSignedAccelerated, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, integerDotProductAccumulatingSaturating32BitMixedSignednessAccelerated, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, integerDotProductAccumulatingSaturating64BitUnsignedAccelerated, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, integerDotProductAccumulatingSaturating64BitSignedAccelerated, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, integerDotProductAccumulatingSaturating64BitMixedSignednessAccelerated, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDevicePipelineRobustnessProperties *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDevicePipelineRobustnessProperties)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_ENUM_WARN(member, defaultRobustnessStorageBuffers, true, requested_profile, WarnIfNotEqualEnum);
        GET_VALUE_ENUM_WARN(member, defaultRobustnessUniformBuffers, true, requested_profile, WarnIfNotEqualEnum);
        GET_VALUE_ENUM_WARN(member, defaultRobustnessVertexInputs, true, requested_profile, WarnIfNotEqualEnum);
        GET_VALUE_ENUM_WARN(member, defaultRobustnessImages, true, requested_profile, WarnIfNotEqualEnum);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDevicePrivateDataFeatures *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDevicePrivateDataFeatures)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, privateData, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceVariablePointerFeatures *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceVariablePointerFeatures)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, variablePointersStorageBuffer, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, variablePointers, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceMultiviewFeatures *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceMultiviewFeatures)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, multiview, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, multiviewGeometryShader, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, multiviewTessellationShader, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDevice16BitStorageFeatures *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDevice16BitStorageFeatures)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, storageBuffer16BitAccess, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, uniformAndStorageBuffer16BitAccess, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, storagePushConstant16, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, storageInputOutput16, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, shaderSubgroupExtendedTypes, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceSamplerYcbcrConversionFeatures *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceSamplerYcbcrConversionFeatures)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, samplerYcbcrConversion, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceProtectedMemoryFeatures *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceProtectedMemoryFeatures)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, protectedMemory, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceInlineUniformBlockFeatures *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceInlineUniformBlockFeatures)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, inlineUniformBlock, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, descriptorBindingInlineUniformBlockUpdateAfterBind, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceMaintenance4Features *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceMaintenance4Features)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, maintenance4, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceMaintenance5Features *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceMaintenance5Features)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, maintenance5, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceMaintenance6Features *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceMaintenance6Features)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, maintenance6, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceShaderDrawParameterFeatures *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceShaderDrawParameterFeatures)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, shaderDrawParameters, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceShaderFloat16Int8Features *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceShaderFloat16Int8Features)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, shaderFloat16, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderInt8, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceHostQueryResetFeatures *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceHostQueryResetFeatures)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, hostQueryReset, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceDescriptorIndexingFeatures *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceDescriptorIndexingFeatures)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, shaderInputAttachmentArrayDynamicIndexing, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderUniformTexelBufferArrayDynamicIndexing, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderStorageTexelBufferArrayDynamicIndexing, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderUniformBufferArrayNonUniformIndexing, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderSampledImageArrayNonUniformIndexing, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderStorageBufferArrayNonUniformIndexing, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderStorageImageArrayNonUniformIndexing, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderInputAttachmentArrayNonUniformIndexing, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderUniformTexelBufferArrayNonUniformIndexing, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderStorageTexelBufferArrayNonUniformIndexing, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, descriptorBindingUniformBufferUpdateAfterBind, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, descriptorBindingSampledImageUpdateAfterBind, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, descriptorBindingStorageImageUpdateAfterBind, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, descriptorBindingStorageBufferUpdateAfterBind, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, descriptorBindingUniformTexelBufferUpdateAfterBind, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, descriptorBindingStorageTexelBufferUpdateAfterBind, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, descriptorBindingUpdateUnusedWhilePending, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, descriptorBindingPartiallyBound, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, descriptorBindingVariableDescriptorCount, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, runtimeDescriptorArray, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceTimelineSemaphoreFeatures *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceTimelineSemaphoreFeatures)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, timelineSemaphore, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDevice8BitStorageFeatures *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDevice8BitStorageFeatures)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, storageBuffer8BitAccess, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, uniformAndStorageBuffer8BitAccess, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, storagePushConstant8, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceVulkanMemoryModelFeatures *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceVulkanMemoryModelFeatures)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, vulkanMemoryModel, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, vulkanMemoryModelDeviceScope, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, vulkanMemoryModelAvailabilityVisibilityChains, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceShaderAtomicInt64Features *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceShaderAtomicInt64Features)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, shaderBufferInt64Atomics, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderSharedInt64Atomics, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceScalarBlockLayoutFeatures *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceScalarBlockLayoutFeatures)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, scalarBlockLayout, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceUniformBufferStandardLayoutFeatures *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceUniformBufferStandardLayoutFeatures)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, uniformBufferStandardLayout, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceBufferDeviceAddressFeatures *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceBufferDeviceAddressFeatures)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, bufferDeviceAddress, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, bufferDeviceAddressCaptureReplay, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, bufferDeviceAddressMultiDevice, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceImagelessFramebufferFeatures *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceImagelessFramebufferFeatures)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, imagelessFramebuffer, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, separateDepthStencilLayouts, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDevicePipelineCreationCacheControlFeatures *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDevicePipelineCreationCacheControlFeatures)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, pipelineCreationCacheControl, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceVulkan11Features *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceVulkan11Features)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, storageBuffer16BitAccess, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, uniformAndStorageBuffer16BitAccess, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, storagePushConstant16, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, storageInputOutput16, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, multiview, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, multiviewGeometryShader, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, multiviewTessellationShader, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, variablePointersStorageBuffer, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, variablePointers, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, protectedMemory, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, samplerYcbcrConversion, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderDrawParameters, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceVulkan12Features *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceVulkan12Features)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, samplerMirrorClampToEdge, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, drawIndirectCount, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, storageBuffer8BitAccess, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, uniformAndStorageBuffer8BitAccess, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, storagePushConstant8, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderBufferInt64Atomics, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderSharedInt64Atomics, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderFloat16, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderInt8, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, descriptorIndexing, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderInputAttachmentArrayDynamicIndexing, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderUniformTexelBufferArrayDynamicIndexing, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderStorageTexelBufferArrayDynamicIndexing, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderUniformBufferArrayNonUniformIndexing, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderSampledImageArrayNonUniformIndexing, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderStorageBufferArrayNonUniformIndexing, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderStorageImageArrayNonUniformIndexing, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderInputAttachmentArrayNonUniformIndexing, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderUniformTexelBufferArrayNonUniformIndexing, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderStorageTexelBufferArrayNonUniformIndexing, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, descriptorBindingUniformBufferUpdateAfterBind, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, descriptorBindingSampledImageUpdateAfterBind, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, descriptorBindingStorageImageUpdateAfterBind, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, descriptorBindingStorageBufferUpdateAfterBind, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, descriptorBindingUniformTexelBufferUpdateAfterBind, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, descriptorBindingStorageTexelBufferUpdateAfterBind, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, descriptorBindingUpdateUnusedWhilePending, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, descriptorBindingPartiallyBound, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, descriptorBindingVariableDescriptorCount, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, runtimeDescriptorArray, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, samplerFilterMinmax, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, scalarBlockLayout, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, imagelessFramebuffer, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, uniformBufferStandardLayout, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderSubgroupExtendedTypes, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, separateDepthStencilLayouts, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, hostQueryReset, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, timelineSemaphore, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, bufferDeviceAddress, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, bufferDeviceAddressCaptureReplay, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, bufferDeviceAddressMultiDevice, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, vulkanMemoryModel, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, vulkanMemoryModelDeviceScope, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, vulkanMemoryModelAvailabilityVisibilityChains, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderOutputViewportIndex, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderOutputLayer, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, subgroupBroadcastDynamicId, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceVulkan13Features *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceVulkan13Features)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, robustImageAccess, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, inlineUniformBlock, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, descriptorBindingInlineUniformBlockUpdateAfterBind, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, pipelineCreationCacheControl, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, privateData, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderDemoteToHelperInvocation, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderTerminateInvocation, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, subgroupSizeControl, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, computeFullSubgroups, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, synchronization2, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, textureCompressionASTC_HDR, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderZeroInitializeWorkgroupMemory, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, dynamicRendering, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderIntegerDotProduct, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, maintenance4, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceVulkan14Features *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceVulkan14Features)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, globalPriorityQuery, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderSubgroupRotate, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderSubgroupRotateClustered, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderFloatControls2, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderExpectAssume, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, rectangularLines, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, bresenhamLines, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, smoothLines, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, stippledRectangularLines, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, stippledBresenhamLines, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, stippledSmoothLines, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, vertexAttributeInstanceRateDivisor, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, vertexAttributeInstanceRateZeroDivisor, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, indexTypeUint8, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, dynamicRenderingLocalRead, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, maintenance5, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, maintenance6, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, pipelineProtectedAccess, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, pipelineRobustness, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, hostImageCopy, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, pushDescriptor, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, shaderZeroInitializeWorkgroupMemory, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceHostImageCopyFeatures *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceHostImageCopyFeatures)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, hostImageCopy, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceVulkanSC10Features *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceVulkanSC10Features)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, shaderAtomicInstructions, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDevicePipelineProtectedAccessFeatures *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDevicePipelineProtectedAccessFeatures)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, pipelineProtectedAccess, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceShaderIntegerDotProductFeatures *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceShaderIntegerDotProductFeatures)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, shaderIntegerDotProduct, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceDynamicRenderingFeatures *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceDynamicRenderingFeatures)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, dynamicRendering, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDevicePipelineRobustnessFeatures *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDevicePipelineRobustnessFeatures)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, pipelineRobustness, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceShaderSubgroupRotateFeatures *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceShaderSubgroupRotateFeatures)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, shaderSubgroupRotate, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderSubgroupRotateClustered, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceShaderExpectAssumeFeatures *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceShaderExpectAssumeFeatures)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, shaderExpectAssume, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceShaderFloatControls2Features *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceShaderFloatControls2Features)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, shaderFloatControls2, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceDynamicRenderingLocalReadFeatures *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceDynamicRenderingLocalReadFeatures)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, dynamicRenderingLocalRead, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, textureCompressionASTC_HDR, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceASTCDecodeFeaturesEXT *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceASTCDecodeFeaturesEXT)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, decodeModeSharedExponent, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceDiscardRectanglePropertiesEXT *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceDiscardRectanglePropertiesEXT)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, maxDiscardRectangles, false, requested_profile, WarnIfGreater);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceConservativeRasterizationPropertiesEXT *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceConservativeRasterizationPropertiesEXT)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, primitiveOverestimationSize, true, requested_profile, WarnIfNotEqualFloat);
        GET_VALUE_WARN(member, maxExtraPrimitiveOverestimationSize, false, requested_profile, WarnIfGreaterFloat);
        GET_VALUE_WARN(member, extraPrimitiveOverestimationSizeGranularity, false, requested_profile, WarnIfLesserFloat);
        GET_VALUE_WARN(member, primitiveUnderestimation, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, conservativePointAndLineRasterization, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, degenerateTrianglesRasterized, true, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, degenerateLinesRasterized, true, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, fullyCoveredFragmentShaderInputVariable, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, conservativeRasterizationPostDepthCoverage, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceDepthClipEnableFeaturesEXT *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceDepthClipEnableFeaturesEXT)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, depthClipEnable, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDevicePerformanceQueryPropertiesKHR *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDevicePerformanceQueryPropertiesKHR)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, allowCommandBufferQueryCopies, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDevicePerformanceQueryFeaturesKHR *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDevicePerformanceQueryFeaturesKHR)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, performanceCounterQueryPools, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, performanceCounterMultipleQueryPools, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceSampleLocationsPropertiesEXT *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceSampleLocationsPropertiesEXT)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_FLAG_WARN(member, sampleLocationSampleCounts, false, requested_profile);
        GET_VALUE_WARN(member, maxSampleLocationGridSize, false, requested_profile, WarnIfGreater);
        GetArray(device_name, parent, member, "sampleLocationCoordinateRange", dest->sampleLocationCoordinateRange, false);
        GET_VALUE_WARN(member, sampleLocationSubPixelBits, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, variableSampleLocations, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, advancedBlendMaxColorAttachments, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, advancedBlendIndependentBlend, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, advancedBlendNonPremultipliedSrcColor, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, advancedBlendNonPremultipliedDstColor, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, advancedBlendCorrelatedOverlap, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, advancedBlendAllOperations, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, advancedBlendCoherentOperations, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceExternalMemoryHostPropertiesEXT *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceExternalMemoryHostPropertiesEXT)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, minImportedHostPointerAlignment, false, requested_profile, WarnIfLesser);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceShaderClockFeaturesKHR *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceShaderClockFeaturesKHR)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, shaderSubgroupClock, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderDeviceClock, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, globalPriorityQuery, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDevicePCIBusInfoPropertiesEXT *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDevicePCIBusInfoPropertiesEXT)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, pciDomain, true, requested_profile, WarnIfNotEqual32u);
        GET_VALUE_WARN(member, pciBus, true, requested_profile, WarnIfNotEqual32u);
        GET_VALUE_WARN(member, pciDevice, true, requested_profile, WarnIfNotEqual32u);
        GET_VALUE_WARN(member, pciFunction, true, requested_profile, WarnIfNotEqual32u);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceShaderTerminateInvocationFeaturesKHR *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceShaderTerminateInvocationFeaturesKHR)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, shaderTerminateInvocation, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceSubgroupSizeControlPropertiesEXT *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceSubgroupSizeControlPropertiesEXT)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, minSubgroupSize, false, requested_profile, WarnIfLesser);
        GET_VALUE_WARN(member, maxSubgroupSize, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxComputeWorkgroupSubgroups, false, requested_profile, WarnIfGreater);
        GET_VALUE_FLAG_WARN(member, requiredSubgroupSizeStages, false, requested_profile);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceSubgroupSizeControlFeaturesEXT *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceSubgroupSizeControlFeaturesEXT)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, subgroupSizeControl, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, computeFullSubgroups, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceFragmentShadingRatePropertiesKHR *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceFragmentShadingRatePropertiesKHR)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, minFragmentShadingRateAttachmentTexelSize, false, requested_profile, WarnIfLesser);
        GET_VALUE_WARN(member, maxFragmentShadingRateAttachmentTexelSize, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxFragmentShadingRateAttachmentTexelSizeAspectRatio, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, primitiveFragmentShadingRateWithMultipleViewports, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, layeredShadingRateAttachments, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, fragmentShadingRateNonTrivialCombinerOps, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, maxFragmentSize, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxFragmentSizeAspectRatio, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxFragmentShadingRateCoverageSamples, false, requested_profile, WarnIfGreater);
        GET_VALUE_ENUM_WARN(member, maxFragmentShadingRateRasterizationSamples, false, requested_profile, WarnIfNotEqualEnum);
        GET_VALUE_WARN(member, fragmentShadingRateWithShaderDepthStencilWrites, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, fragmentShadingRateWithSampleMask, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, fragmentShadingRateWithShaderSampleMask, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, fragmentShadingRateWithConservativeRasterization, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, fragmentShadingRateWithFragmentShaderInterlock, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, fragmentShadingRateWithCustomSampleLocations, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, fragmentShadingRateStrictMultiplyCombiner, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceFragmentShadingRateFeaturesKHR *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceFragmentShadingRateFeaturesKHR)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, pipelineFragmentShadingRate, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, primitiveFragmentShadingRate, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, attachmentFragmentShadingRate, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, shaderImageInt64Atomics, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, sparseImageInt64Atomics, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, fragmentShaderSampleInterlock, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, fragmentShaderPixelInterlock, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, fragmentShaderShadingRateInterlock, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceYcbcrImageArraysFeaturesEXT *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceYcbcrImageArraysFeaturesEXT)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, ycbcrImageArrays, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceLineRasterizationPropertiesEXT *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceLineRasterizationPropertiesEXT)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, lineSubPixelPrecisionBits, false, requested_profile, WarnIfGreater);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceLineRasterizationFeaturesEXT *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceLineRasterizationFeaturesEXT)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, rectangularLines, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, bresenhamLines, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, smoothLines, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, stippledRectangularLines, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, stippledBresenhamLines, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, stippledSmoothLines, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceShaderAtomicFloatFeaturesEXT *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceShaderAtomicFloatFeaturesEXT)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, shaderBufferFloat32Atomics, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderBufferFloat32AtomicAdd, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderBufferFloat64Atomics, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderBufferFloat64AtomicAdd, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderSharedFloat32Atomics, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderSharedFloat32AtomicAdd, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderSharedFloat64Atomics, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderSharedFloat64AtomicAdd, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderImageFloat32Atomics, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderImageFloat32AtomicAdd, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, sparseImageFloat32Atomics, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, sparseImageFloat32AtomicAdd, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceIndexTypeUint8FeaturesEXT *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceIndexTypeUint8FeaturesEXT)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, indexTypeUint8, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceExtendedDynamicStateFeaturesEXT *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceExtendedDynamicStateFeaturesEXT)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, extendedDynamicState, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, shaderDemoteToHelperInvocation, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceTexelBufferAlignmentPropertiesEXT *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceTexelBufferAlignmentPropertiesEXT)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, storageTexelBufferOffsetAlignmentBytes, false, requested_profile, WarnIfLesser);
        GET_VALUE_WARN(member, storageTexelBufferOffsetSingleTexelAlignment, true, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, uniformTexelBufferOffsetAlignmentBytes, false, requested_profile, WarnIfLesser);
        GET_VALUE_WARN(member, uniformTexelBufferOffsetSingleTexelAlignment, true, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, texelBufferAlignment, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceRobustness2PropertiesEXT *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceRobustness2PropertiesEXT)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, robustStorageBufferAccessSizeAlignment, false, requested_profile, WarnIfLesser);
        GET_VALUE_WARN(member, robustUniformBufferAccessSizeAlignment, false, requested_profile, WarnIfLesser);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceRobustness2FeaturesEXT *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceRobustness2FeaturesEXT)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, robustBufferAccess2, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, robustImageAccess2, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, nullDescriptor, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceCustomBorderColorPropertiesEXT *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceCustomBorderColorPropertiesEXT)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, maxCustomBorderColorSamplers, false, requested_profile, WarnIfGreater);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceCustomBorderColorFeaturesEXT *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceCustomBorderColorFeaturesEXT)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, customBorderColors, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, customBorderColorWithoutFormat, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceSynchronization2FeaturesKHR *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceSynchronization2FeaturesKHR)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, synchronization2, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, ycbcr2plane444Formats, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceImageRobustnessFeaturesEXT *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceImageRobustnessFeaturesEXT)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, robustImageAccess, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDevice4444FormatsFeaturesEXT *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDevice4444FormatsFeaturesEXT)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, formatA4R4G4B4, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, formatA4B4G4R4, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, vertexInputDynamicState, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

#ifdef VK_USE_PLATFORM_SCI
bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceExternalSciSyncFeaturesNV *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceExternalSciSyncFeaturesNV)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, sciSyncFence, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, sciSyncSemaphore, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, sciSyncImport, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, sciSyncExport, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

#endif // VK_USE_PLATFORM_SCI
#ifdef VK_USE_PLATFORM_SCI
bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceExternalMemorySciBufFeaturesNV *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceExternalMemorySciBufFeaturesNV)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, sciBufImport, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, sciBufExport, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

#endif // VK_USE_PLATFORM_SCI
bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceExtendedDynamicState2FeaturesEXT *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceExtendedDynamicState2FeaturesEXT)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, extendedDynamicState2, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, extendedDynamicState2LogicOp, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, extendedDynamicState2PatchControlPoints, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceColorWriteEnableFeaturesEXT *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceColorWriteEnableFeaturesEXT)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, colorWriteEnable, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

#ifdef VK_USE_PLATFORM_SCI
bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceExternalSciSync2FeaturesNV *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceExternalSciSync2FeaturesNV)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, sciSyncFence, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, sciSyncSemaphore2, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, sciSyncImport, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, sciSyncExport, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

#endif // VK_USE_PLATFORM_SCI
bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceVertexAttributeDivisorPropertiesKHR *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceVertexAttributeDivisorPropertiesKHR)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, maxVertexAttribDivisor, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, supportsNonZeroFirstInstance, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceVertexAttributeDivisorFeaturesKHR *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceVertexAttributeDivisorFeaturesKHR)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, vertexAttributeInstanceRateDivisor, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, vertexAttributeInstanceRateZeroDivisor, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

#ifdef VK_USE_PLATFORM_SCREEN_QNX
bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceExternalMemoryScreenBufferFeaturesQNX *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceExternalMemoryScreenBufferFeaturesQNX)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, screenBufferImport, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

#endif // VK_USE_PLATFORM_SCREEN_QNX
bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceFeatures *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceFeatures)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, robustBufferAccess, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, fullDrawIndexUint32, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, imageCubeArray, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, independentBlend, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, geometryShader, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, tessellationShader, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, sampleRateShading, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, dualSrcBlend, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, logicOp, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, multiDrawIndirect, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, drawIndirectFirstInstance, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, depthClamp, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, depthBiasClamp, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, fillModeNonSolid, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, depthBounds, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, wideLines, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, largePoints, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, alphaToOne, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, multiViewport, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, samplerAnisotropy, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, textureCompressionETC2, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, textureCompressionASTC_LDR, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, textureCompressionBC, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, occlusionQueryPrecise, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, pipelineStatisticsQuery, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, vertexPipelineStoresAndAtomics, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, fragmentStoresAndAtomics, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderTessellationAndGeometryPointSize, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderImageGatherExtended, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderStorageImageExtendedFormats, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderStorageImageMultisample, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderStorageImageReadWithoutFormat, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderStorageImageWriteWithoutFormat, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderUniformBufferArrayDynamicIndexing, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderSampledImageArrayDynamicIndexing, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderStorageBufferArrayDynamicIndexing, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderStorageImageArrayDynamicIndexing, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderClipDistance, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderCullDistance, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderFloat64, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderInt64, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderInt16, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderResourceResidency, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, shaderResourceMinLod, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, sparseBinding, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, sparseResidencyBuffer, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, sparseResidencyImage2D, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, sparseResidencyImage3D, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, sparseResidency2Samples, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, sparseResidency4Samples, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, sparseResidency8Samples, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, sparseResidency16Samples, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, sparseResidencyAliased, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, variableMultisampleRate, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, inheritedQueries, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}


bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDevicePortabilitySubsetFeaturesKHR *dest) {
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDevicePortabilitySubsetFeaturesKHR)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        if (layer_settings.simulate.emulate_portability) {
            dest->constantAlphaColorBlendFactors = layer_settings.portability.constantAlphaColorBlendFactors;
            dest->events = layer_settings.portability.events;
            dest->imageViewFormatReinterpretation = layer_settings.portability.imageViewFormatReinterpretation;
            dest->imageViewFormatSwizzle = layer_settings.portability.imageViewFormatSwizzle;
            dest->imageView2DOn3DImage = layer_settings.portability.imageView2DOn3DImage;
            dest->multisampleArrayImage = layer_settings.portability.multisampleArrayImage;
            dest->mutableComparisonSamplers = layer_settings.portability.mutableComparisonSamplers;
            dest->pointPolygons = layer_settings.portability.pointPolygons;
            dest->samplerMipLodBias = layer_settings.portability.samplerMipLodBias;
            dest->separateStencilMaskRef = layer_settings.portability.separateStencilMaskRef;
            dest->shaderSampleRateInterpolationFunctions = layer_settings.portability.shaderSampleRateInterpolationFunctions;
            dest->tessellationIsolines = layer_settings.portability.tessellationIsolines;
            dest->tessellationPointMode = layer_settings.portability.tessellationPointMode;
            dest->triangleFans = layer_settings.portability.triangleFans;
            dest->vertexAttributeAccessBeyondStride = layer_settings.portability.vertexAttributeAccessBeyondStride;
        } else {
            GET_VALUE_WARN(member, constantAlphaColorBlendFactors, false, requested_profile, WarnIfNotEqualBool);
            GET_VALUE_WARN(member, events, false, requested_profile, WarnIfNotEqualBool);
            GET_VALUE_WARN(member, imageViewFormatReinterpretation, false, requested_profile, WarnIfNotEqualBool);
            GET_VALUE_WARN(member, imageViewFormatSwizzle, false, requested_profile, WarnIfNotEqualBool);
            GET_VALUE_WARN(member, imageView2DOn3DImage, false, requested_profile, WarnIfNotEqualBool);
            GET_VALUE_WARN(member, multisampleArrayImage, false, requested_profile, WarnIfNotEqualBool);
            GET_VALUE_WARN(member, mutableComparisonSamplers, false, requested_profile, WarnIfNotEqualBool);
            GET_VALUE_WARN(member, pointPolygons, false, requested_profile, WarnIfNotEqualBool);
            GET_VALUE_WARN(member, samplerMipLodBias, false, requested_profile, WarnIfNotEqualBool);
            GET_VALUE_WARN(member, separateStencilMaskRef, false, requested_profile, WarnIfNotEqualBool);
            GET_VALUE_WARN(member, shaderSampleRateInterpolationFunctions, false, requested_profile, WarnIfNotEqualBool);
            GET_VALUE_WARN(member, tessellationIsolines, false, requested_profile, WarnIfNotEqualBool);
            GET_VALUE_WARN(member, tessellationPointMode, false, requested_profile, WarnIfNotEqualBool);
            GET_VALUE_WARN(member, triangleFans, false, requested_profile, WarnIfNotEqualBool);
            GET_VALUE_WARN(member, vertexAttributeAccessBeyondStride, false, requested_profile, WarnIfNotEqualBool);
        }
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceProperties *dest) {
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceProperties)\n");
    bool valid = true;
    if (!GetStruct(device_name, requested_profile, parent["limits"], &dest->limits)) {
        valid = false;
    }
    if (!GetStruct(device_name, requested_profile, parent["sparseProperties"], &dest->sparseProperties)) {
        valid = false;
    }
    for (const auto &prop : parent.getMemberNames()) {
        GET_VALUE(prop, apiVersion, false, requested_profile);
        GET_VALUE(prop, driverVersion, true, requested_profile);
        GET_VALUE(prop, vendorID, true, requested_profile);
        GET_VALUE(prop, deviceID, true, requested_profile);
        GET_VALUE_ENUM_WARN(prop, deviceType, true, requested_profile, WarnIfNotEqualEnum);
        GetArray(device_name, parent, prop, "deviceName", dest->deviceName, true);         // size < VK_MAX_PHYSICAL_DEVICE_NAME_SIZE
        GetArray(device_name, parent, prop, "pipelineCacheUUID", dest->pipelineCacheUUID, true);  // size == VK_UUID_SIZE*/
    }
    return valid;
}
bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceLimits *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceLimits)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, maxImageDimension1D, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxImageDimension2D, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxImageDimension3D, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxImageDimensionCube, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxImageArrayLayers, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxTexelBufferElements, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxUniformBufferRange, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxStorageBufferRange, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxPushConstantsSize, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxMemoryAllocationCount, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxSamplerAllocationCount, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, bufferImageGranularity, false, requested_profile, WarnIfLesser);
        GET_VALUE_WARN(member, sparseAddressSpaceSize, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxBoundDescriptorSets, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxPerStageDescriptorSamplers, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxPerStageDescriptorUniformBuffers, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxPerStageDescriptorStorageBuffers, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxPerStageDescriptorSampledImages, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxPerStageDescriptorStorageImages, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxPerStageDescriptorInputAttachments, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxPerStageResources, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxDescriptorSetSamplers, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxDescriptorSetUniformBuffers, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxDescriptorSetUniformBuffersDynamic, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxDescriptorSetStorageBuffers, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxDescriptorSetStorageBuffersDynamic, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxDescriptorSetSampledImages, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxDescriptorSetStorageImages, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxDescriptorSetInputAttachments, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxVertexInputAttributes, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxVertexInputBindings, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxVertexInputAttributeOffset, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxVertexInputBindingStride, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxVertexOutputComponents, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxTessellationGenerationLevel, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxTessellationPatchSize, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxTessellationControlPerVertexInputComponents, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxTessellationControlPerVertexOutputComponents, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxTessellationControlPerPatchOutputComponents, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxTessellationControlTotalOutputComponents, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxTessellationEvaluationInputComponents, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxTessellationEvaluationOutputComponents, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxGeometryShaderInvocations, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxGeometryInputComponents, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxGeometryOutputComponents, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxGeometryOutputVertices, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxGeometryTotalOutputComponents, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxFragmentInputComponents, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxFragmentOutputAttachments, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxFragmentDualSrcAttachments, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxFragmentCombinedOutputResources, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxComputeSharedMemorySize, false, requested_profile, WarnIfGreater);
        GetArray(device_name, parent, member, "maxComputeWorkGroupCount", dest->maxComputeWorkGroupCount, false);
        GET_VALUE_WARN(member, maxComputeWorkGroupInvocations, false, requested_profile, WarnIfGreater);
        GetArray(device_name, parent, member, "maxComputeWorkGroupSize", dest->maxComputeWorkGroupSize, false);
        GET_VALUE_WARN(member, subPixelPrecisionBits, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, subTexelPrecisionBits, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, mipmapPrecisionBits, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxDrawIndexedIndexValue, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxDrawIndirectCount, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxSamplerLodBias, false, requested_profile, WarnIfGreaterFloat);
        GET_VALUE_WARN(member, maxSamplerAnisotropy, false, requested_profile, WarnIfGreaterFloat);
        GET_VALUE_WARN(member, maxViewports, false, requested_profile, WarnIfGreater);
        GetArray(device_name, parent, member, "maxViewportDimensions", dest->maxViewportDimensions, false);
        GetArray(device_name, parent, member, "viewportBoundsRange", dest->viewportBoundsRange, false);
        GET_VALUE_WARN(member, viewportSubPixelBits, false, requested_profile, WarnIfGreater);
        GET_VALUE_SIZE_T_WARN(member, minMemoryMapAlignment, false, requested_profile, WarnIfGreaterSizet);
        GET_VALUE_WARN(member, minTexelBufferOffsetAlignment, false, requested_profile, WarnIfLesser);
        GET_VALUE_WARN(member, minUniformBufferOffsetAlignment, false, requested_profile, WarnIfLesser);
        GET_VALUE_WARN(member, minStorageBufferOffsetAlignment, false, requested_profile, WarnIfLesser);
        GET_VALUE_WARN(member, minTexelOffset, false, requested_profile, WarnIfLesser);
        GET_VALUE_WARN(member, maxTexelOffset, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, minTexelGatherOffset, false, requested_profile, WarnIfLesser);
        GET_VALUE_WARN(member, maxTexelGatherOffset, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, minInterpolationOffset, false, requested_profile, WarnIfLesserFloat);
        GET_VALUE_WARN(member, maxInterpolationOffset, false, requested_profile, WarnIfGreaterFloat);
        GET_VALUE_WARN(member, subPixelInterpolationOffsetBits, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxFramebufferWidth, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxFramebufferHeight, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxFramebufferLayers, false, requested_profile, WarnIfGreater);
        GET_VALUE_FLAG_WARN(member, framebufferColorSampleCounts, false, requested_profile);
        GET_VALUE_FLAG_WARN(member, framebufferDepthSampleCounts, false, requested_profile);
        GET_VALUE_FLAG_WARN(member, framebufferStencilSampleCounts, false, requested_profile);
        GET_VALUE_FLAG_WARN(member, framebufferNoAttachmentsSampleCounts, false, requested_profile);
        GET_VALUE_WARN(member, maxColorAttachments, false, requested_profile, WarnIfGreater);
        GET_VALUE_FLAG_WARN(member, sampledImageColorSampleCounts, false, requested_profile);
        GET_VALUE_FLAG_WARN(member, sampledImageIntegerSampleCounts, false, requested_profile);
        GET_VALUE_FLAG_WARN(member, sampledImageDepthSampleCounts, false, requested_profile);
        GET_VALUE_FLAG_WARN(member, sampledImageStencilSampleCounts, false, requested_profile);
        GET_VALUE_FLAG_WARN(member, storageImageSampleCounts, false, requested_profile);
        GET_VALUE_WARN(member, maxSampleMaskWords, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, timestampComputeAndGraphics, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, timestampPeriod, true, requested_profile, WarnIfNotEqualFloat);
        GET_VALUE_WARN(member, maxClipDistances, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxCullDistances, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, maxCombinedClipAndCullDistances, false, requested_profile, WarnIfGreater);
        GET_VALUE_WARN(member, discreteQueuePriorities, false, requested_profile, WarnIfGreater);
        GetArray(device_name, parent, member, "pointSizeRange", dest->pointSizeRange, false);
        GetArray(device_name, parent, member, "lineWidthRange", dest->lineWidthRange, false);
        GET_VALUE_WARN(member, pointSizeGranularity, false, requested_profile, WarnIfLesserFloat);
        GET_VALUE_WARN(member, lineWidthGranularity, false, requested_profile, WarnIfLesserFloat);
        GET_VALUE_WARN(member, strictLines, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, standardSampleLocations, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, optimalBufferCopyOffsetAlignment, false, requested_profile, WarnIfLesser);
        GET_VALUE_WARN(member, optimalBufferCopyRowPitchAlignment, false, requested_profile, WarnIfLesser);
        GET_VALUE_WARN(member, nonCoherentAtomSize, false, requested_profile, WarnIfLesser);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceSparseProperties *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceSparseProperties)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, residencyStandard2DBlockShape, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, residencyStandard2DMultisampleBlockShape, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, residencyStandard3DBlockShape, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, residencyAlignedMipSize, false, requested_profile, WarnIfNotEqualBool);
        GET_VALUE_WARN(member, residencyNonResidentStrict, false, requested_profile, WarnIfNotEqualBool);
    }
    return valid;
}

bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDeviceToolProperties *dest) {
    (void)dest;
    (void)requested_profile;
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDeviceToolProperties)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GetArray(device_name, parent, member, "name", dest->name, true);
        GetArray(device_name, parent, member, "version", dest->version, true);
        GetArray(device_name, parent, member, "description", dest->description, true);
        GetArray(device_name, parent, member, "layer", dest->layer, true);
    }
    return valid;
}


bool JsonLoader::GetStruct(const char* device_name, bool requested_profile, const Json::Value &parent, VkPhysicalDevicePortabilitySubsetPropertiesKHR *dest) {
    LogMessage(&layer_settings, DEBUG_REPORT_DEBUG_BIT, "\tJsonLoader::GetStruct(VkPhysicalDevicePortabilitySubsetPropertiesKHR)\n");
    bool valid = true;
    for (const auto &member : parent.getMemberNames()) {
        GET_VALUE_WARN(member, minVertexInputBindingStrideAlignment, false, requested_profile, WarnIfLesser);
    }
    return valid;
}

#undef GET_VALUE
#undef GET_ARRAY

// Generic layer dispatch table setup, see [LALI].
static VkResult LayerSetupCreateInstance(const VkInstanceCreateInfo *pCreateInfo, const VkAllocationCallbacks *pAllocator,
                                         VkInstance *pInstance) {
    VkLayerInstanceCreateInfo *chain_info = get_chain_info(pCreateInfo, VK_LAYER_LINK_INFO);
    assert(chain_info->u.pLayerInfo);

    PFN_vkGetInstanceProcAddr fp_get_instance_proc_addr = chain_info->u.pLayerInfo->pfnNextGetInstanceProcAddr;
    PFN_vkCreateInstance fp_create_instance = (PFN_vkCreateInstance)fp_get_instance_proc_addr(nullptr, "vkCreateInstance");
    if (!fp_create_instance) {
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    chain_info->u.pLayerInfo = chain_info->u.pLayerInfo->pNext;
    VkResult result = fp_create_instance(pCreateInfo, pAllocator, pInstance);
    if (result == VK_SUCCESS) {
        initInstanceTable(*pInstance, fp_get_instance_proc_addr);
        JsonLoader::Store(*pInstance);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateInstance(const VkInstanceCreateInfo *pCreateInfo, const VkAllocationCallbacks *pAllocator,
                                              VkInstance *pInstance) {
    JsonLoader &json_loader = JsonLoader::Create();

    ProfileLayerSettings *layer_settings = &json_loader.layer_settings;

    InitProfilesLayerSettings(pCreateInfo, pAllocator, layer_settings);

    LogMessage(layer_settings, DEBUG_REPORT_DEBUG_BIT, "CreateInstance\n");
    LogMessage(layer_settings, DEBUG_REPORT_DEBUG_BIT, "JsonCpp version %s\n", JSONCPP_VERSION_STRING);
    LogMessage(layer_settings, DEBUG_REPORT_NOTIFICATION_BIT, "%s version %d.%d.%d\n", kLayerName, kVersionProfilesMajor,
                                                       kVersionProfilesMinor, kVersionProfilesPatch);

    VkResult result = json_loader.LoadProfilesDatabase();
    if (result != VK_SUCCESS) {
        return result;
    }

    const VkApplicationInfo *app_info = pCreateInfo->pApplicationInfo;
    requested_version = (app_info && app_info->apiVersion) ? app_info->apiVersion : VK_API_VERSION_1_0;
    if (VK_API_VERSION_MAJOR(requested_version) > VK_API_VERSION_MAJOR(VK_HEADER_VERSION_COMPLETE) ||
        VK_API_VERSION_MINOR(requested_version) > VK_API_VERSION_MINOR(VK_HEADER_VERSION_COMPLETE)) {
        LogMessage(layer_settings, DEBUG_REPORT_ERROR_BIT, "The Vulkan application requested a Vulkan %s instance but the %s was build "
                                                    "against %s. Please, update the layer.\n",
                                                    StringAPIVersion(requested_version).c_str(), kLayerName,
                                                    StringAPIVersion(VK_HEADER_VERSION_COMPLETE).c_str());
        if (layer_settings->log.debug_fail_on_error) {
            return VK_ERROR_INITIALIZATION_FAILED;
        }
    }


    bool changed_version = false;
    if (!layer_settings->simulate.profile_file.empty() || !layer_settings->simulate.profile_dirs.empty()) {
        const uint32_t profile_api_version = json_loader.GetProfileApiVersion();
        if (VK_API_VERSION_MAJOR(requested_version) < VK_API_VERSION_MAJOR(profile_api_version) ||
            VK_API_VERSION_MINOR(requested_version) < VK_API_VERSION_MINOR(profile_api_version)) {
            if (layer_settings->simulate.capabilities & SIMULATE_API_VERSION_BIT) {
                if (layer_settings->simulate.profile_name.empty()) {
                    LogMessage(layer_settings,
                        DEBUG_REPORT_NOTIFICATION_BIT,
                        "The Vulkan application requested a Vulkan %s instance but the selected %s file requires %s. The "
                                 "application requested instance version is overridden to %s.\n",
                                 StringAPIVersion(requested_version).c_str(), layer_settings->simulate.profile_file.c_str(),
                                 StringAPIVersion(profile_api_version).c_str(), StringAPIVersion(profile_api_version).c_str());
                } else {
                    LogMessage(layer_settings,
                        DEBUG_REPORT_NOTIFICATION_BIT,
                        "The Vulkan application requested a Vulkan %s instance but the selected %s profile requires %s. "
                                 "The application requested instance version is overridden to %s.\n",
                                 StringAPIVersion(requested_version).c_str(), layer_settings->simulate.profile_name.c_str(),
                                 StringAPIVersion(profile_api_version).c_str(), StringAPIVersion(profile_api_version).c_str());
                }
                requested_version = profile_api_version;
                changed_version = true;
            } else {
                if (layer_settings->simulate.profile_name.empty()) {
                    LogMessage(layer_settings,
                        DEBUG_REPORT_WARNING_BIT,
                        "The Vulkan application requested a Vulkan %s instance but the selected %s file requires %s. The "
                                 "profile may not be initialized correctly which will produce unexpected warning messages.\n",
                                 StringAPIVersion(requested_version).c_str(), layer_settings->simulate.profile_file.c_str(),
                                 StringAPIVersion(profile_api_version).c_str());
                } else {
                    LogMessage(layer_settings,
                        DEBUG_REPORT_WARNING_BIT,
                        "The Vulkan application requested a Vulkan %s instance but the selected %s profile requires %s. "
                                 "The profile may not be initialized correctly which will produce unexpected warning messages.\n",
                                 StringAPIVersion(requested_version).c_str(), layer_settings->simulate.profile_name.c_str(),
                                 StringAPIVersion(profile_api_version).c_str());
                }
            }
        }
    }

    std::lock_guard<std::recursive_mutex> lock(global_lock);

    bool get_physical_device_properties2_active = false;
    if (VK_API_VERSION_MINOR(requested_version) > 0) {
        get_physical_device_properties2_active = true;
    } else {
        for (uint32_t i = 0; i < pCreateInfo->enabledExtensionCount; i++) {
            if (strncmp(pCreateInfo->ppEnabledExtensionNames[i], VK_KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_EXTENSION_NAME,
                        VK_MAX_EXTENSION_NAME_SIZE) == 0) {
                get_physical_device_properties2_active = true;
                break;
            }
        }
    }
    if (!changed_version && get_physical_device_properties2_active) {
        return LayerSetupCreateInstance(pCreateInfo, pAllocator, pInstance);
    }

    if (!get_physical_device_properties2_active) {
        LogMessage(layer_settings, DEBUG_REPORT_NOTIFICATION_BIT,
                   "The Profiles Layer requires the %s extension, but it was not included in "
                            "VkInstanceCreateInfo::ppEnabledExtensionNames, adding the extension.\n",
                            VK_KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_EXTENSION_NAME);
    }

    // Handle VK_KHR_PORTABILITY_ENUMERATION_EXTENSION_NAME
    bool has_port_enum = false;
    for (uint32_t i = 0; i < pCreateInfo->enabledExtensionCount; i++) {
        if (strncmp(pCreateInfo->ppEnabledExtensionNames[i], VK_KHR_PORTABILITY_ENUMERATION_EXTENSION_NAME,
                    VK_MAX_EXTENSION_NAME_SIZE) == 0) {
            has_port_enum = true;
            break;
        }
    }

    VkInstanceCreateInfo create_info;
    create_info.sType = pCreateInfo->sType;
    create_info.pNext = pCreateInfo->pNext;
    create_info.flags = pCreateInfo->flags;
    if (has_port_enum) {
        create_info.flags |= VK_INSTANCE_CREATE_ENUMERATE_PORTABILITY_BIT_KHR;
    }

    VkApplicationInfo new_app_info;
    if (changed_version) {
        if (app_info) {
            new_app_info.sType = app_info->sType;
            new_app_info.pNext = app_info->pNext;
            new_app_info.pApplicationName = app_info->pApplicationName;
            new_app_info.applicationVersion = app_info->applicationVersion;
            new_app_info.pEngineName = app_info->pEngineName;
            new_app_info.engineVersion = app_info->engineVersion;
            new_app_info.apiVersion = requested_version;
        } else {
            new_app_info = {VK_STRUCTURE_TYPE_APPLICATION_INFO};
            new_app_info.apiVersion = requested_version;
        }

        create_info.pApplicationInfo = &new_app_info;
    } else {
        create_info.pApplicationInfo = app_info;
    }
    create_info.enabledLayerCount = pCreateInfo->enabledLayerCount;
    create_info.ppEnabledLayerNames = pCreateInfo->ppEnabledLayerNames;

    // Add VK_KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_EXTENSION_NAME
    std::vector<const char *> extension_names;
    if (!get_physical_device_properties2_active) {
        create_info.enabledExtensionCount = pCreateInfo->enabledExtensionCount + 1;
        extension_names.resize(create_info.enabledExtensionCount);
        for (uint32_t i = 0; i < pCreateInfo->enabledExtensionCount; ++i) {
            extension_names[i] = pCreateInfo->ppEnabledExtensionNames[i];
        }
        extension_names[pCreateInfo->enabledExtensionCount] = VK_KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_EXTENSION_NAME;
        create_info.ppEnabledExtensionNames = extension_names.data();
    } else {
        create_info.enabledExtensionCount = pCreateInfo->enabledExtensionCount;
        create_info.ppEnabledExtensionNames = pCreateInfo->ppEnabledExtensionNames;
    }
    return LayerSetupCreateInstance(&create_info, pAllocator, pInstance);
}

VKAPI_ATTR void VKAPI_CALL DestroyInstance(VkInstance instance, const VkAllocationCallbacks *pAllocator) {
    if (instance) {
        std::lock_guard<std::recursive_mutex> lock(global_lock);

        ProfileLayerSettings* layer_settings = &JsonLoader::Find(instance)->layer_settings;

        LogMessage(layer_settings, DEBUG_REPORT_DEBUG_BIT, "DestroyInstance\n");

        {
            const auto dt = instance_dispatch_table(instance);

            std::vector<VkPhysicalDevice> physical_devices;
            VkResult err = EnumerateAll<VkPhysicalDevice>(physical_devices, [&](uint32_t *count, VkPhysicalDevice *results) {
                return dt->EnumeratePhysicalDevices(instance, count, results);
            });
            assert(!err);
            if (!err)
                for (const auto pd : physical_devices) PhysicalDeviceData::Destroy(pd);

            dt->DestroyInstance(instance, pAllocator);
        }
        destroy_instance_dispatch_table(get_dispatch_key(instance));

        JsonLoader::Destroy(instance);
    }
}

void FillPNextChain(PhysicalDeviceData *physicalDeviceData, void *place) {
    while (place) {
        VkBaseOutStructure *structure = (VkBaseOutStructure *)place;

        // These switch statements check which struct is in the pNext chain and, if the physical device has the proper extension,
        // fill the struct with any override data provided by the PhysicalDeviceData object.

        switch (structure->sType) {
#ifndef VULKANSC
            // VK_KHR_portability_subset is a special case since it can also be emulated by the Profiles layer.
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_PROPERTIES_KHR:
                if (PhysicalDeviceData::HasSimulatedExtension(physicalDeviceData, VK_KHR_PORTABILITY_SUBSET_EXTENSION_NAME) ||
                    layer_settings->simulate.emulate_portability) {
                    VkPhysicalDevicePortabilitySubsetPropertiesKHR *psp = (VkPhysicalDevicePortabilitySubsetPropertiesKHR *)place;
                    void *pNext = psp->pNext;
                    *psp = physicalDeviceData->physical_device_portability_subset_properties_;
                    if (layer_settings->portability.vertexAttributeAccessBeyondStride) {
                        psp->minVertexInputBindingStrideAlignment = layer_settings->portability.minVertexInputBindingStrideAlignment;
                    }
                    psp->pNext = pNext;
                }
                break;
#endif
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES:
                {
                    VkPhysicalDevicePushDescriptorProperties *data = (VkPhysicalDevicePushDescriptorProperties *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_push_descriptor_properties_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES:
                {
                    VkPhysicalDeviceDriverProperties *data = (VkPhysicalDeviceDriverProperties *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_driver_properties_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES:
                {
                    VkPhysicalDeviceIDProperties *data = (VkPhysicalDeviceIDProperties *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_idproperties_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES:
                {
                    VkPhysicalDeviceMultiviewProperties *data = (VkPhysicalDeviceMultiviewProperties *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_multiview_properties_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES:
                {
                    VkPhysicalDeviceSubgroupProperties *data = (VkPhysicalDeviceSubgroupProperties *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_subgroup_properties_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES:
                {
                    VkPhysicalDevicePointClippingProperties *data = (VkPhysicalDevicePointClippingProperties *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_point_clipping_properties_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES:
                {
                    VkPhysicalDeviceProtectedMemoryProperties *data = (VkPhysicalDeviceProtectedMemoryProperties *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_protected_memory_properties_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES:
                {
                    VkPhysicalDeviceSamplerFilterMinmaxProperties *data = (VkPhysicalDeviceSamplerFilterMinmaxProperties *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_sampler_filter_minmax_properties_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES:
                {
                    VkPhysicalDeviceInlineUniformBlockProperties *data = (VkPhysicalDeviceInlineUniformBlockProperties *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_inline_uniform_block_properties_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES:
                {
                    VkPhysicalDeviceMaintenance3Properties *data = (VkPhysicalDeviceMaintenance3Properties *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_maintenance_3_properties_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_PROPERTIES:
                {
                    VkPhysicalDeviceMaintenance4Properties *data = (VkPhysicalDeviceMaintenance4Properties *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_maintenance_4_properties_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_PROPERTIES:
                {
                    VkPhysicalDeviceMaintenance5Properties *data = (VkPhysicalDeviceMaintenance5Properties *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_maintenance_5_properties_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_6_PROPERTIES:
                {
                    VkPhysicalDeviceMaintenance6Properties *data = (VkPhysicalDeviceMaintenance6Properties *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_maintenance_6_properties_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES:
                {
                    VkPhysicalDeviceFloatControlsProperties *data = (VkPhysicalDeviceFloatControlsProperties *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_float_controls_properties_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES:
                {
                    VkPhysicalDeviceDescriptorIndexingProperties *data = (VkPhysicalDeviceDescriptorIndexingProperties *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_descriptor_indexing_properties_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES:
                {
                    VkPhysicalDeviceTimelineSemaphoreProperties *data = (VkPhysicalDeviceTimelineSemaphoreProperties *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_timeline_semaphore_properties_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES:
                {
                    VkPhysicalDeviceDepthStencilResolveProperties *data = (VkPhysicalDeviceDepthStencilResolveProperties *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_depth_stencil_resolve_properties_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES:
                {
                    VkPhysicalDeviceVulkan11Properties *data = (VkPhysicalDeviceVulkan11Properties *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_vulkan_11_properties_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES:
                {
                    VkPhysicalDeviceVulkan12Properties *data = (VkPhysicalDeviceVulkan12Properties *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_vulkan_12_properties_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES:
                {
                    VkPhysicalDeviceVulkan13Properties *data = (VkPhysicalDeviceVulkan13Properties *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_vulkan_13_properties_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_4_PROPERTIES:
                {
                    VkPhysicalDeviceVulkan14Properties *data = (VkPhysicalDeviceVulkan14Properties *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_vulkan_14_properties_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_IMAGE_COPY_PROPERTIES:
                {
                    VkPhysicalDeviceHostImageCopyProperties *data = (VkPhysicalDeviceHostImageCopyProperties *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_host_image_copy_properties_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_SC_1_0_PROPERTIES:
                {
                    VkPhysicalDeviceVulkanSC10Properties *data = (VkPhysicalDeviceVulkanSC10Properties *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_vulkan_sc_10_properties_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_PROPERTIES:
                {
                    VkPhysicalDeviceShaderIntegerDotProductProperties *data = (VkPhysicalDeviceShaderIntegerDotProductProperties *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_shader_integer_dot_product_properties_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_PROPERTIES:
                {
                    VkPhysicalDevicePipelineRobustnessProperties *data = (VkPhysicalDevicePipelineRobustnessProperties *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_pipeline_robustness_properties_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIVATE_DATA_FEATURES:
                {
                    VkPhysicalDevicePrivateDataFeatures *data = (VkPhysicalDevicePrivateDataFeatures *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_private_data_features_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES:
                {
                    VkPhysicalDeviceVariablePointerFeatures *data = (VkPhysicalDeviceVariablePointerFeatures *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_variable_pointer_features_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES:
                {
                    VkPhysicalDeviceMultiviewFeatures *data = (VkPhysicalDeviceMultiviewFeatures *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_multiview_features_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES:
                {
                    VkPhysicalDevice16BitStorageFeatures *data = (VkPhysicalDevice16BitStorageFeatures *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_16_bit_storage_features_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES:
                {
                    VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures *data = (VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_shader_subgroup_extended_types_features_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES:
                {
                    VkPhysicalDeviceSamplerYcbcrConversionFeatures *data = (VkPhysicalDeviceSamplerYcbcrConversionFeatures *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_sampler_ycbcr_conversion_features_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES:
                {
                    VkPhysicalDeviceProtectedMemoryFeatures *data = (VkPhysicalDeviceProtectedMemoryFeatures *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_protected_memory_features_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES:
                {
                    VkPhysicalDeviceInlineUniformBlockFeatures *data = (VkPhysicalDeviceInlineUniformBlockFeatures *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_inline_uniform_block_features_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_FEATURES:
                {
                    VkPhysicalDeviceMaintenance4Features *data = (VkPhysicalDeviceMaintenance4Features *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_maintenance_4_features_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_FEATURES:
                {
                    VkPhysicalDeviceMaintenance5Features *data = (VkPhysicalDeviceMaintenance5Features *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_maintenance_5_features_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_6_FEATURES:
                {
                    VkPhysicalDeviceMaintenance6Features *data = (VkPhysicalDeviceMaintenance6Features *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_maintenance_6_features_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES:
                {
                    VkPhysicalDeviceShaderDrawParameterFeatures *data = (VkPhysicalDeviceShaderDrawParameterFeatures *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_shader_draw_parameter_features_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES:
                {
                    VkPhysicalDeviceShaderFloat16Int8Features *data = (VkPhysicalDeviceShaderFloat16Int8Features *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_float_16_int_8_features_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES:
                {
                    VkPhysicalDeviceHostQueryResetFeatures *data = (VkPhysicalDeviceHostQueryResetFeatures *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_host_query_reset_features_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES:
                {
                    VkPhysicalDeviceDescriptorIndexingFeatures *data = (VkPhysicalDeviceDescriptorIndexingFeatures *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_descriptor_indexing_features_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES:
                {
                    VkPhysicalDeviceTimelineSemaphoreFeatures *data = (VkPhysicalDeviceTimelineSemaphoreFeatures *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_timeline_semaphore_features_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES:
                {
                    VkPhysicalDevice8BitStorageFeatures *data = (VkPhysicalDevice8BitStorageFeatures *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_8_bit_storage_features_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES:
                {
                    VkPhysicalDeviceVulkanMemoryModelFeatures *data = (VkPhysicalDeviceVulkanMemoryModelFeatures *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_vulkan_memory_model_features_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES:
                {
                    VkPhysicalDeviceShaderAtomicInt64Features *data = (VkPhysicalDeviceShaderAtomicInt64Features *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_shader_atomic_int_64_features_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES:
                {
                    VkPhysicalDeviceScalarBlockLayoutFeatures *data = (VkPhysicalDeviceScalarBlockLayoutFeatures *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_scalar_block_layout_features_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES:
                {
                    VkPhysicalDeviceUniformBufferStandardLayoutFeatures *data = (VkPhysicalDeviceUniformBufferStandardLayoutFeatures *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_uniform_buffer_standard_layout_features_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES:
                {
                    VkPhysicalDeviceBufferDeviceAddressFeatures *data = (VkPhysicalDeviceBufferDeviceAddressFeatures *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_buffer_device_address_features_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES:
                {
                    VkPhysicalDeviceImagelessFramebufferFeatures *data = (VkPhysicalDeviceImagelessFramebufferFeatures *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_imageless_framebuffer_features_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES:
                {
                    VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures *data = (VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_separate_depth_stencil_layouts_features_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES:
                {
                    VkPhysicalDevicePipelineCreationCacheControlFeatures *data = (VkPhysicalDevicePipelineCreationCacheControlFeatures *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_pipeline_creation_cache_control_features_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES:
                {
                    VkPhysicalDeviceVulkan11Features *data = (VkPhysicalDeviceVulkan11Features *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_vulkan_11_features_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES:
                {
                    VkPhysicalDeviceVulkan12Features *data = (VkPhysicalDeviceVulkan12Features *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_vulkan_12_features_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES:
                {
                    VkPhysicalDeviceVulkan13Features *data = (VkPhysicalDeviceVulkan13Features *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_vulkan_13_features_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_4_FEATURES:
                {
                    VkPhysicalDeviceVulkan14Features *data = (VkPhysicalDeviceVulkan14Features *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_vulkan_14_features_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_WORKGROUP_MEMORY_FEATURES:
                {
                    VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures *data = (VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_zero_initialize_workgroup_memory_features_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_IMAGE_COPY_FEATURES:
                {
                    VkPhysicalDeviceHostImageCopyFeatures *data = (VkPhysicalDeviceHostImageCopyFeatures *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_host_image_copy_features_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_SC_1_0_FEATURES:
                {
                    VkPhysicalDeviceVulkanSC10Features *data = (VkPhysicalDeviceVulkanSC10Features *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_vulkan_sc_10_features_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_PROTECTED_ACCESS_FEATURES:
                {
                    VkPhysicalDevicePipelineProtectedAccessFeatures *data = (VkPhysicalDevicePipelineProtectedAccessFeatures *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_pipeline_protected_access_features_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_FEATURES:
                {
                    VkPhysicalDeviceShaderIntegerDotProductFeatures *data = (VkPhysicalDeviceShaderIntegerDotProductFeatures *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_shader_integer_dot_product_features_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_FEATURES:
                {
                    VkPhysicalDeviceDynamicRenderingFeatures *data = (VkPhysicalDeviceDynamicRenderingFeatures *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_dynamic_rendering_features_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_FEATURES:
                {
                    VkPhysicalDevicePipelineRobustnessFeatures *data = (VkPhysicalDevicePipelineRobustnessFeatures *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_pipeline_robustness_features_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_ROTATE_FEATURES:
                {
                    VkPhysicalDeviceShaderSubgroupRotateFeatures *data = (VkPhysicalDeviceShaderSubgroupRotateFeatures *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_shader_subgroup_rotate_features_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EXPECT_ASSUME_FEATURES:
                {
                    VkPhysicalDeviceShaderExpectAssumeFeatures *data = (VkPhysicalDeviceShaderExpectAssumeFeatures *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_shader_expect_assume_features_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT_CONTROLS_2_FEATURES:
                {
                    VkPhysicalDeviceShaderFloatControls2Features *data = (VkPhysicalDeviceShaderFloatControls2Features *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_shader_float_controls_2_features_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_LOCAL_READ_FEATURES:
                {
                    VkPhysicalDeviceDynamicRenderingLocalReadFeatures *data = (VkPhysicalDeviceDynamicRenderingLocalReadFeatures *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_dynamic_rendering_local_read_features_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES_EXT:
                if ((PhysicalDeviceData::HasSimulatedExtension(physicalDeviceData, VK_EXT_TEXTURE_COMPRESSION_ASTC_HDR_EXTENSION_NAME))) {
                    VkPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT *data = (VkPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_texture_compression_astchdrfeatures_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT:
                if ((PhysicalDeviceData::HasSimulatedExtension(physicalDeviceData, VK_EXT_ASTC_DECODE_MODE_EXTENSION_NAME))) {
                    VkPhysicalDeviceASTCDecodeFeaturesEXT *data = (VkPhysicalDeviceASTCDecodeFeaturesEXT *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_astcdecode_features_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT:
                if ((PhysicalDeviceData::HasSimulatedExtension(physicalDeviceData, VK_EXT_DISCARD_RECTANGLES_EXTENSION_NAME))) {
                    VkPhysicalDeviceDiscardRectanglePropertiesEXT *data = (VkPhysicalDeviceDiscardRectanglePropertiesEXT *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_discard_rectangle_properties_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT:
                if ((PhysicalDeviceData::HasSimulatedExtension(physicalDeviceData, VK_EXT_CONSERVATIVE_RASTERIZATION_EXTENSION_NAME))) {
                    VkPhysicalDeviceConservativeRasterizationPropertiesEXT *data = (VkPhysicalDeviceConservativeRasterizationPropertiesEXT *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_conservative_rasterization_properties_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT:
                if ((PhysicalDeviceData::HasSimulatedExtension(physicalDeviceData, VK_EXT_DEPTH_CLIP_ENABLE_EXTENSION_NAME))) {
                    VkPhysicalDeviceDepthClipEnableFeaturesEXT *data = (VkPhysicalDeviceDepthClipEnableFeaturesEXT *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_depth_clip_enable_features_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_PROPERTIES_KHR:
                if ((PhysicalDeviceData::HasSimulatedExtension(physicalDeviceData, VK_KHR_PERFORMANCE_QUERY_EXTENSION_NAME))) {
                    VkPhysicalDevicePerformanceQueryPropertiesKHR *data = (VkPhysicalDevicePerformanceQueryPropertiesKHR *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_performance_query_properties_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_FEATURES_KHR:
                if ((PhysicalDeviceData::HasSimulatedExtension(physicalDeviceData, VK_KHR_PERFORMANCE_QUERY_EXTENSION_NAME))) {
                    VkPhysicalDevicePerformanceQueryFeaturesKHR *data = (VkPhysicalDevicePerformanceQueryFeaturesKHR *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_performance_query_features_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT:
                if ((PhysicalDeviceData::HasSimulatedExtension(physicalDeviceData, VK_EXT_SAMPLE_LOCATIONS_EXTENSION_NAME))) {
                    VkPhysicalDeviceSampleLocationsPropertiesEXT *data = (VkPhysicalDeviceSampleLocationsPropertiesEXT *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_sample_locations_properties_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT:
                if ((PhysicalDeviceData::HasSimulatedExtension(physicalDeviceData, VK_EXT_BLEND_OPERATION_ADVANCED_EXTENSION_NAME))) {
                    VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT *data = (VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_blend_operation_advanced_properties_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT:
                if ((PhysicalDeviceData::HasSimulatedExtension(physicalDeviceData, VK_EXT_BLEND_OPERATION_ADVANCED_EXTENSION_NAME))) {
                    VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT *data = (VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_blend_operation_advanced_features_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT:
                if ((PhysicalDeviceData::HasSimulatedExtension(physicalDeviceData, VK_EXT_EXTERNAL_MEMORY_HOST_EXTENSION_NAME))) {
                    VkPhysicalDeviceExternalMemoryHostPropertiesEXT *data = (VkPhysicalDeviceExternalMemoryHostPropertiesEXT *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_external_memory_host_properties_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR:
                if ((PhysicalDeviceData::HasSimulatedExtension(physicalDeviceData, VK_KHR_SHADER_CLOCK_EXTENSION_NAME))) {
                    VkPhysicalDeviceShaderClockFeaturesKHR *data = (VkPhysicalDeviceShaderClockFeaturesKHR *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_shader_clock_features_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES_KHR:
                if ((PhysicalDeviceData::HasSimulatedExtension(physicalDeviceData, VK_KHR_GLOBAL_PRIORITY_EXTENSION_NAME))) {
                    VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR *data = (VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_global_priority_query_features_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT:
                if ((PhysicalDeviceData::HasSimulatedExtension(physicalDeviceData, VK_EXT_PCI_BUS_INFO_EXTENSION_NAME))) {
                    VkPhysicalDevicePCIBusInfoPropertiesEXT *data = (VkPhysicalDevicePCIBusInfoPropertiesEXT *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_pcibus_info_properties_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TERMINATE_INVOCATION_FEATURES_KHR:
                if ((PhysicalDeviceData::HasSimulatedExtension(physicalDeviceData, VK_KHR_SHADER_TERMINATE_INVOCATION_EXTENSION_NAME))) {
                    VkPhysicalDeviceShaderTerminateInvocationFeaturesKHR *data = (VkPhysicalDeviceShaderTerminateInvocationFeaturesKHR *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_shader_terminate_invocation_features_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_PROPERTIES_EXT:
                if ((PhysicalDeviceData::HasSimulatedExtension(physicalDeviceData, VK_EXT_SUBGROUP_SIZE_CONTROL_EXTENSION_NAME))) {
                    VkPhysicalDeviceSubgroupSizeControlPropertiesEXT *data = (VkPhysicalDeviceSubgroupSizeControlPropertiesEXT *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_subgroup_size_control_properties_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES_EXT:
                if ((PhysicalDeviceData::HasSimulatedExtension(physicalDeviceData, VK_EXT_SUBGROUP_SIZE_CONTROL_EXTENSION_NAME))) {
                    VkPhysicalDeviceSubgroupSizeControlFeaturesEXT *data = (VkPhysicalDeviceSubgroupSizeControlFeaturesEXT *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_subgroup_size_control_features_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_PROPERTIES_KHR:
                if ((PhysicalDeviceData::HasSimulatedExtension(physicalDeviceData, VK_KHR_FRAGMENT_SHADING_RATE_EXTENSION_NAME))) {
                    VkPhysicalDeviceFragmentShadingRatePropertiesKHR *data = (VkPhysicalDeviceFragmentShadingRatePropertiesKHR *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_fragment_shading_rate_properties_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_FEATURES_KHR:
                if ((PhysicalDeviceData::HasSimulatedExtension(physicalDeviceData, VK_KHR_FRAGMENT_SHADING_RATE_EXTENSION_NAME))) {
                    VkPhysicalDeviceFragmentShadingRateFeaturesKHR *data = (VkPhysicalDeviceFragmentShadingRateFeaturesKHR *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_fragment_shading_rate_features_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_ATOMIC_INT64_FEATURES_EXT:
                if ((PhysicalDeviceData::HasSimulatedExtension(physicalDeviceData, VK_EXT_SHADER_IMAGE_ATOMIC_INT64_EXTENSION_NAME))) {
                    VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT *data = (VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_shader_image_atomic_int_64_features_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT:
                if ((PhysicalDeviceData::HasSimulatedExtension(physicalDeviceData, VK_EXT_FRAGMENT_SHADER_INTERLOCK_EXTENSION_NAME))) {
                    VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT *data = (VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_fragment_shader_interlock_features_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT:
                if ((PhysicalDeviceData::HasSimulatedExtension(physicalDeviceData, VK_EXT_YCBCR_IMAGE_ARRAYS_EXTENSION_NAME))) {
                    VkPhysicalDeviceYcbcrImageArraysFeaturesEXT *data = (VkPhysicalDeviceYcbcrImageArraysFeaturesEXT *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_ycbcr_image_arrays_features_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_PROPERTIES_EXT:
                if ((PhysicalDeviceData::HasSimulatedExtension(physicalDeviceData, VK_EXT_LINE_RASTERIZATION_EXTENSION_NAME) || PhysicalDeviceData::HasSimulatedExtension(physicalDeviceData, VK_KHR_LINE_RASTERIZATION_EXTENSION_NAME))) {
                    VkPhysicalDeviceLineRasterizationPropertiesEXT *data = (VkPhysicalDeviceLineRasterizationPropertiesEXT *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_line_rasterization_properties_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_EXT:
                if ((PhysicalDeviceData::HasSimulatedExtension(physicalDeviceData, VK_EXT_LINE_RASTERIZATION_EXTENSION_NAME) || PhysicalDeviceData::HasSimulatedExtension(physicalDeviceData, VK_KHR_LINE_RASTERIZATION_EXTENSION_NAME))) {
                    VkPhysicalDeviceLineRasterizationFeaturesEXT *data = (VkPhysicalDeviceLineRasterizationFeaturesEXT *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_line_rasterization_features_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_FEATURES_EXT:
                if ((PhysicalDeviceData::HasSimulatedExtension(physicalDeviceData, VK_EXT_SHADER_ATOMIC_FLOAT_EXTENSION_NAME))) {
                    VkPhysicalDeviceShaderAtomicFloatFeaturesEXT *data = (VkPhysicalDeviceShaderAtomicFloatFeaturesEXT *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_shader_atomic_float_features_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES_EXT:
                if ((PhysicalDeviceData::HasSimulatedExtension(physicalDeviceData, VK_EXT_INDEX_TYPE_UINT8_EXTENSION_NAME) || PhysicalDeviceData::HasSimulatedExtension(physicalDeviceData, VK_KHR_INDEX_TYPE_UINT8_EXTENSION_NAME))) {
                    VkPhysicalDeviceIndexTypeUint8FeaturesEXT *data = (VkPhysicalDeviceIndexTypeUint8FeaturesEXT *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_index_type_uint_8_features_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_FEATURES_EXT:
                if ((PhysicalDeviceData::HasSimulatedExtension(physicalDeviceData, VK_EXT_EXTENDED_DYNAMIC_STATE_EXTENSION_NAME))) {
                    VkPhysicalDeviceExtendedDynamicStateFeaturesEXT *data = (VkPhysicalDeviceExtendedDynamicStateFeaturesEXT *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_extended_dynamic_state_features_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES_EXT:
                if ((PhysicalDeviceData::HasSimulatedExtension(physicalDeviceData, VK_EXT_SHADER_DEMOTE_TO_HELPER_INVOCATION_EXTENSION_NAME))) {
                    VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT *data = (VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_shader_demote_to_helper_invocation_features_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES_EXT:
                if ((PhysicalDeviceData::HasSimulatedExtension(physicalDeviceData, VK_EXT_TEXEL_BUFFER_ALIGNMENT_EXTENSION_NAME))) {
                    VkPhysicalDeviceTexelBufferAlignmentPropertiesEXT *data = (VkPhysicalDeviceTexelBufferAlignmentPropertiesEXT *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_texel_buffer_alignment_properties_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT:
                if ((PhysicalDeviceData::HasSimulatedExtension(physicalDeviceData, VK_EXT_TEXEL_BUFFER_ALIGNMENT_EXTENSION_NAME))) {
                    VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT *data = (VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_texel_buffer_alignment_features_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_PROPERTIES_EXT:
                if ((PhysicalDeviceData::HasSimulatedExtension(physicalDeviceData, VK_EXT_ROBUSTNESS_2_EXTENSION_NAME))) {
                    VkPhysicalDeviceRobustness2PropertiesEXT *data = (VkPhysicalDeviceRobustness2PropertiesEXT *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_robustness_2_properties_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_EXT:
                if ((PhysicalDeviceData::HasSimulatedExtension(physicalDeviceData, VK_EXT_ROBUSTNESS_2_EXTENSION_NAME))) {
                    VkPhysicalDeviceRobustness2FeaturesEXT *data = (VkPhysicalDeviceRobustness2FeaturesEXT *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_robustness_2_features_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_PROPERTIES_EXT:
                if ((PhysicalDeviceData::HasSimulatedExtension(physicalDeviceData, VK_EXT_CUSTOM_BORDER_COLOR_EXTENSION_NAME))) {
                    VkPhysicalDeviceCustomBorderColorPropertiesEXT *data = (VkPhysicalDeviceCustomBorderColorPropertiesEXT *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_custom_border_color_properties_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_FEATURES_EXT:
                if ((PhysicalDeviceData::HasSimulatedExtension(physicalDeviceData, VK_EXT_CUSTOM_BORDER_COLOR_EXTENSION_NAME))) {
                    VkPhysicalDeviceCustomBorderColorFeaturesEXT *data = (VkPhysicalDeviceCustomBorderColorFeaturesEXT *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_custom_border_color_features_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SYNCHRONIZATION_2_FEATURES_KHR:
                if ((PhysicalDeviceData::HasSimulatedExtension(physicalDeviceData, VK_KHR_SYNCHRONIZATION_2_EXTENSION_NAME))) {
                    VkPhysicalDeviceSynchronization2FeaturesKHR *data = (VkPhysicalDeviceSynchronization2FeaturesKHR *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_synchronization_2_features_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_2_PLANE_444_FORMATS_FEATURES_EXT:
                if ((PhysicalDeviceData::HasSimulatedExtension(physicalDeviceData, VK_EXT_YCBCR_2PLANE_444_FORMATS_EXTENSION_NAME))) {
                    VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT *data = (VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_ycbcr_2_plane_444_formats_features_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES_EXT:
                if ((PhysicalDeviceData::HasSimulatedExtension(physicalDeviceData, VK_EXT_IMAGE_ROBUSTNESS_EXTENSION_NAME))) {
                    VkPhysicalDeviceImageRobustnessFeaturesEXT *data = (VkPhysicalDeviceImageRobustnessFeaturesEXT *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_image_robustness_features_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_4444_FORMATS_FEATURES_EXT:
                if ((PhysicalDeviceData::HasSimulatedExtension(physicalDeviceData, VK_EXT_4444_FORMATS_EXTENSION_NAME))) {
                    VkPhysicalDevice4444FormatsFeaturesEXT *data = (VkPhysicalDevice4444FormatsFeaturesEXT *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_4444_formats_features_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_INPUT_DYNAMIC_STATE_FEATURES_EXT:
                if ((PhysicalDeviceData::HasSimulatedExtension(physicalDeviceData, VK_EXT_VERTEX_INPUT_DYNAMIC_STATE_EXTENSION_NAME))) {
                    VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT *data = (VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_vertex_input_dynamic_state_features_;
                    data->pNext = pNext;
                }
                break;
#ifdef VK_USE_PLATFORM_SCI
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SCI_SYNC_FEATURES_NV:
                if ((PhysicalDeviceData::HasSimulatedExtension(physicalDeviceData, VK_NV_EXTERNAL_SCI_SYNC_EXTENSION_NAME))) {
                    VkPhysicalDeviceExternalSciSyncFeaturesNV *data = (VkPhysicalDeviceExternalSciSyncFeaturesNV *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_external_sci_sync_features_;
                    data->pNext = pNext;
                }
                break;
#endif // VK_USE_PLATFORM_SCI
#ifdef VK_USE_PLATFORM_SCI
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_SCI_BUF_FEATURES_NV:
                if ((PhysicalDeviceData::HasSimulatedExtension(physicalDeviceData, VK_NV_EXTERNAL_MEMORY_SCI_BUF_EXTENSION_NAME))) {
                    VkPhysicalDeviceExternalMemorySciBufFeaturesNV *data = (VkPhysicalDeviceExternalMemorySciBufFeaturesNV *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_external_memory_sci_buf_features_;
                    data->pNext = pNext;
                }
                break;
#endif // VK_USE_PLATFORM_SCI
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_2_FEATURES_EXT:
                if ((PhysicalDeviceData::HasSimulatedExtension(physicalDeviceData, VK_EXT_EXTENDED_DYNAMIC_STATE_2_EXTENSION_NAME))) {
                    VkPhysicalDeviceExtendedDynamicState2FeaturesEXT *data = (VkPhysicalDeviceExtendedDynamicState2FeaturesEXT *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_extended_dynamic_state_2_features_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COLOR_WRITE_ENABLE_FEATURES_EXT:
                if ((PhysicalDeviceData::HasSimulatedExtension(physicalDeviceData, VK_EXT_COLOR_WRITE_ENABLE_EXTENSION_NAME))) {
                    VkPhysicalDeviceColorWriteEnableFeaturesEXT *data = (VkPhysicalDeviceColorWriteEnableFeaturesEXT *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_color_write_enable_features_;
                    data->pNext = pNext;
                }
                break;
#ifdef VK_USE_PLATFORM_SCI
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SCI_SYNC_2_FEATURES_NV:
                if ((PhysicalDeviceData::HasSimulatedExtension(physicalDeviceData, VK_NV_EXTERNAL_SCI_SYNC_2_EXTENSION_NAME))) {
                    VkPhysicalDeviceExternalSciSync2FeaturesNV *data = (VkPhysicalDeviceExternalSciSync2FeaturesNV *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_external_sci_sync_2_features_;
                    data->pNext = pNext;
                }
                break;
#endif // VK_USE_PLATFORM_SCI
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_KHR:
                if ((PhysicalDeviceData::HasSimulatedExtension(physicalDeviceData, VK_KHR_VERTEX_ATTRIBUTE_DIVISOR_EXTENSION_NAME))) {
                    VkPhysicalDeviceVertexAttributeDivisorPropertiesKHR *data = (VkPhysicalDeviceVertexAttributeDivisorPropertiesKHR *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_vertex_attribute_divisor_properties_;
                    data->pNext = pNext;
                }
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_KHR:
                if ((PhysicalDeviceData::HasSimulatedExtension(physicalDeviceData, VK_KHR_VERTEX_ATTRIBUTE_DIVISOR_EXTENSION_NAME))) {
                    VkPhysicalDeviceVertexAttributeDivisorFeaturesKHR *data = (VkPhysicalDeviceVertexAttributeDivisorFeaturesKHR *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_vertex_attribute_divisor_features_;
                    data->pNext = pNext;
                }
                break;
#ifdef VK_USE_PLATFORM_SCREEN_QNX
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_SCREEN_BUFFER_FEATURES_QNX:
                if ((PhysicalDeviceData::HasSimulatedExtension(physicalDeviceData, VK_QNX_EXTERNAL_MEMORY_SCREEN_BUFFER_EXTENSION_NAME))) {
                    VkPhysicalDeviceExternalMemoryScreenBufferFeaturesQNX *data = (VkPhysicalDeviceExternalMemoryScreenBufferFeaturesQNX *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->physical_device_external_memory_screen_buffer_features_;
                    data->pNext = pNext;
                }
                break;
#endif // VK_USE_PLATFORM_SCREEN_QNX
            default:
                break;
        }

        place = structure->pNext;
    }
}

void FillQueueFamilyPropertiesPNextChain(PhysicalDeviceData *physicalDeviceData, VkQueueFamilyProperties2KHR *pQueueFamilyProperties2, uint32_t count) {
    for (uint32_t i = 0; i < count; ++i) {
        void* place = pQueueFamilyProperties2[i].pNext;
        while (place) {
            VkBaseOutStructure *structure = (VkBaseOutStructure *)place;

            switch (structure->sType) {
                case VK_STRUCTURE_TYPE_QUEUE_FAMILY_GLOBAL_PRIORITY_PROPERTIES: {
                    VkQueueFamilyGlobalPriorityProperties *data = (VkQueueFamilyGlobalPriorityProperties *)place;
                    void *pNext = data->pNext;
                    *data = physicalDeviceData->arrayof_queue_family_properties_[i].global_priority_properties_;
                    data->pNext = pNext;
                } break;
                default:
                    break;
            }

            place = structure->pNext;
        }
    }
}

void FillFormatPropertiesPNextChain(PhysicalDeviceData *physicalDeviceData, void *place, VkFormat format) {
    while (place) {
        VkBaseOutStructure *structure = (VkBaseOutStructure *)place;

        // These switch statements check which struct is in the pNext chain and, if the physical device has the proper extension,
        // fill the struct with any override data provided by the PhysicalDeviceData object.

        switch (structure->sType) {
            case VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_3: {
                if (!physicalDeviceData->map_of_format_properties_3_.empty()) {
                    VkFormatProperties3 *sp = (VkFormatProperties3 *)place;
                    void *pNext = sp->pNext;
                    *sp = physicalDeviceData->map_of_format_properties_3_[format];
                    sp->pNext = pNext;
                }
            } break;
            default:
                break;
        }

        place = structure->pNext;
    }
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceProperties(VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties *pProperties) {
    std::lock_guard<std::recursive_mutex> lock(global_lock);
    const auto dt = instance_dispatch_table(physicalDevice);

    PhysicalDeviceData *pdd = PhysicalDeviceData::Find(physicalDevice);
    if (pdd) {
        *pProperties = pdd->physical_device_properties_;
    } else {
        dt->GetPhysicalDeviceProperties(physicalDevice, pProperties);
    }
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceProperties2(VkPhysicalDevice physicalDevice,
                                                        VkPhysicalDeviceProperties2KHR *pProperties) {
    std::lock_guard<std::recursive_mutex> lock(global_lock);
    const auto dt = instance_dispatch_table(physicalDevice);
    dt->GetPhysicalDeviceProperties2(physicalDevice, pProperties);
    GetPhysicalDeviceProperties(physicalDevice, &pProperties->properties);
    PhysicalDeviceData *pdd = PhysicalDeviceData::Find(physicalDevice);
    FillPNextChain(pdd, pProperties->pNext);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceProperties2KHR(VkPhysicalDevice physicalDevice,
                                                           VkPhysicalDeviceProperties2KHR *pProperties) {
    GetPhysicalDeviceProperties2(physicalDevice, pProperties);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFeatures(VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures *pFeatures) {
    std::lock_guard<std::recursive_mutex> lock(global_lock);
    const auto dt = instance_dispatch_table(physicalDevice);

    PhysicalDeviceData *pdd = PhysicalDeviceData::Find(physicalDevice);
    if (pdd) {
        *pFeatures = pdd->physical_device_features_;
    } else {
        dt->GetPhysicalDeviceFeatures(physicalDevice, pFeatures);
    }
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFeatures2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures2KHR *pFeatures) {
    std::lock_guard<std::recursive_mutex> lock(global_lock);
    const auto dt = instance_dispatch_table(physicalDevice);

    PhysicalDeviceData *pdd = PhysicalDeviceData::Find(physicalDevice);
    if (pdd) {
        ProfileLayerSettings *layer_settings = &JsonLoader::Find(pdd->instance())->layer_settings;
        if (layer_settings->simulate.unknown_feature_values == UNKNOWN_FEATURE_VALUES_DEVICE) {
            dt->GetPhysicalDeviceFeatures2(physicalDevice, pFeatures);
        }
        FillPNextChain(pdd, pFeatures->pNext);
    } else {
        dt->GetPhysicalDeviceFeatures2(physicalDevice, pFeatures);
    }

    GetPhysicalDeviceFeatures(physicalDevice, &pFeatures->features);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFeatures2KHR(VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures2KHR *pFeatures) {
    GetPhysicalDeviceFeatures2(physicalDevice, pFeatures);
}

VKAPI_ATTR VkResult VKAPI_CALL EnumerateInstanceLayerProperties(uint32_t *pCount, VkLayerProperties *pProperties) {
    return EnumerateProperties(kLayerPropertiesCount, kLayerProperties, pCount, pProperties);
}

VKAPI_ATTR VkResult VKAPI_CALL EnumerateInstanceExtensionProperties(const char *pLayerName, uint32_t *pCount,
                                                                    VkExtensionProperties *pProperties) {
    if (pLayerName && !strcmp(pLayerName, kLayerName)) {
#ifdef VULKANSC
        return EnumerateProperties(0, (VkExtensionProperties*)nullptr, pCount, pProperties);
#else
        return EnumerateProperties(kInstanceExtensionPropertiesCount, kInstanceExtensionProperties, pCount, pProperties);
#endif
    }
    return VK_ERROR_LAYER_NOT_PRESENT;
}

// Per [LALI], EnumerateDeviceLayerProperties() is deprecated.

VKAPI_ATTR VkResult VKAPI_CALL EnumerateDeviceExtensionProperties(VkPhysicalDevice physicalDevice, const char *pLayerName,
                                                                  uint32_t *pCount, VkExtensionProperties *pProperties) {
    VkResult result = VK_SUCCESS;
    std::lock_guard<std::recursive_mutex> lock(global_lock);
    const auto dt = instance_dispatch_table(physicalDevice);

    uint32_t pCount_copy = *pCount;

    PhysicalDeviceData *pdd = PhysicalDeviceData::Find(physicalDevice);
    ProfileLayerSettings* layer_settings = &JsonLoader::Find(pdd->instance())->layer_settings;
    if (pLayerName) {
        if (strcmp(pLayerName, kLayerName) == 0)
            result = EnumerateProperties(kDeviceExtensionPropertiesCount, kDeviceExtensionProperties.data(), pCount, pProperties);
        else
            result = dt->EnumerateDeviceExtensionProperties(physicalDevice, pLayerName, pCount, pProperties);
    } else if (pdd == nullptr || (!(layer_settings->simulate.capabilities & SIMULATE_EXTENSIONS_BIT) &&
                                  layer_settings->simulate.exclude_device_extensions.empty())) {
        result = dt->EnumerateDeviceExtensionProperties(physicalDevice, pLayerName, pCount, pProperties);
    } else {
        result = EnumerateExtensions(pdd->simulation_extensions_, pCount, pProperties);
    }

    if (result == VK_SUCCESS && !pLayerName && layer_settings->simulate.emulate_portability &&
        !PhysicalDeviceData::HasSimulatedOrRealExtension(physicalDevice, VK_KHR_PORTABILITY_SUBSET_EXTENSION_NAME)) {
        if (pProperties) {
            if (pCount_copy >= *pCount + 1) {
                strncpy(pProperties[*pCount].extensionName, VK_KHR_PORTABILITY_SUBSET_EXTENSION_NAME, VK_MAX_EXTENSION_NAME_SIZE);
                pProperties[*pCount].specVersion = VK_KHR_PORTABILITY_SUBSET_SPEC_VERSION;
                *pCount += 1;
            }
        } else {
            *pCount += 1;
        }
    }

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceQueueFamilyProperties(VkPhysicalDevice physicalDevice,
                                                                  uint32_t *pQueueFamilyPropertyCount,
                                                                  VkQueueFamilyProperties *pQueueFamilyProperties) {
    std::lock_guard<std::recursive_mutex> lock(global_lock);
    const auto dt = instance_dispatch_table(physicalDevice);

    // Are there JSON overrides, or should we call down to return the original values?
    PhysicalDeviceData *pdd = PhysicalDeviceData::Find(physicalDevice);
    const uint32_t src_count = (pdd) ? static_cast<uint32_t>(pdd->arrayof_queue_family_properties_.size()) : 0;
    if (src_count == 0) {
        dt->GetPhysicalDeviceQueueFamilyProperties(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
        return;
    }

    // Careful: cannot use EnumerateProperties() here! (because src and dst structs are not the same type)
    if (!pQueueFamilyProperties) {
        *pQueueFamilyPropertyCount = src_count;
        return;
    }
    const uint32_t copy_count = (*pQueueFamilyPropertyCount < src_count) ? *pQueueFamilyPropertyCount : src_count;
    const QueueFamilyProperties *src_props = pdd->arrayof_queue_family_properties_.data();
    for (uint32_t i = 0; i < copy_count; ++i) {
        pQueueFamilyProperties[i] = src_props[i].properties_2.queueFamilyProperties;
    }
    *pQueueFamilyPropertyCount = copy_count;
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceQueueFamilyProperties2KHR(VkPhysicalDevice physicalDevice,
                                                                      uint32_t *pQueueFamilyPropertyCount,
                                                                      VkQueueFamilyProperties2KHR *pQueueFamilyProperties2) {
    std::lock_guard<std::recursive_mutex> lock(global_lock);
    const auto dt = instance_dispatch_table(physicalDevice);

    // Are there JSON overrides, or should we call down to return the original values?
    PhysicalDeviceData *pdd = PhysicalDeviceData::Find(physicalDevice);
    const uint32_t src_count = (pdd) ? static_cast<uint32_t>(pdd->arrayof_queue_family_properties_.size()) : 0;
    if (src_count == 0) {
        dt->GetPhysicalDeviceQueueFamilyProperties2(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties2);
        return;
    }

    if (!pQueueFamilyProperties2) {
        *pQueueFamilyPropertyCount = src_count;
        return;
    }

    // Careful: cannot use EnumerateProperties() here! (because src and dst structs are not the same type)
    const uint32_t copy_count = (*pQueueFamilyPropertyCount < src_count) ? *pQueueFamilyPropertyCount : src_count;
    const QueueFamilyProperties *src_props = pdd->arrayof_queue_family_properties_.data();
    for (uint32_t i = 0; i < copy_count; ++i) {
        pQueueFamilyProperties2[i].queueFamilyProperties = src_props[i].properties_2.queueFamilyProperties;
    }
    *pQueueFamilyPropertyCount = copy_count;
    FillQueueFamilyPropertiesPNextChain(pdd, pQueueFamilyProperties2, copy_count);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceQueueFamilyProperties2(VkPhysicalDevice physicalDevice,
                                                                   uint32_t *pQueueFamilyPropertyCount,
                                                                   VkQueueFamilyProperties2KHR *pQueueFamilyProperties2) {
    GetPhysicalDeviceQueueFamilyProperties2KHR(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties2);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFormatProperties(VkPhysicalDevice physicalDevice, VkFormat format,
                                                             VkFormatProperties *pFormatProperties) {
    std::lock_guard<std::recursive_mutex> lock(global_lock);
    const auto dt = instance_dispatch_table(physicalDevice);

    // Are there JSON overrides, or should we call down to return the original values?
    PhysicalDeviceData *pdd = PhysicalDeviceData::Find(physicalDevice);
    ProfileLayerSettings* layer_settings = &JsonLoader::Find(pdd->instance())->layer_settings;

    // Check if Format was excluded
    for (std::size_t j = 0, m = layer_settings->simulate.exclude_formats.size(); j < m; ++j) {
        const std::string &excluded_format = layer_settings->simulate.exclude_formats[j];
        if (excluded_format.empty()) continue;

        if (StringToFormat(excluded_format) == format) {
            *pFormatProperties = VkFormatProperties{};
            return;
        }
    }

    const uint32_t src_count = (pdd) ? static_cast<uint32_t>(pdd->map_of_format_properties_.size()) : 0;
    if (src_count == 0) {
        dt->GetPhysicalDeviceFormatProperties(physicalDevice, format, pFormatProperties);
    } else {
        VkFormatProperties device_format = {};
        dt->GetPhysicalDeviceFormatProperties(physicalDevice, format, &device_format);
        const auto iter = pdd->map_of_format_properties_.find(format);

        if ((layer_settings->simulate.capabilities & SIMULATE_FORMATS_BIT)) {
            *pFormatProperties = (iter != pdd->map_of_format_properties_.end()) ? iter->second : VkFormatProperties{};
        } else {
            *pFormatProperties = device_format;
        }

        if (IsFormatSupported(*pFormatProperties) && iter != pdd->map_of_format_properties_.end()) {
            if ((layer_settings->simulate.capabilities & SIMULATE_FORMATS_BIT)) {
                *pFormatProperties = iter->second;
            } else {
                *pFormatProperties = device_format;
            }

            if (!HasFlags(device_format.linearTilingFeatures, pFormatProperties->linearTilingFeatures) ||
                !HasFlags(device_format.optimalTilingFeatures, pFormatProperties->optimalTilingFeatures) ||
                !HasFlags(device_format.bufferFeatures, pFormatProperties->bufferFeatures)) {
                LogMessage(layer_settings, DEBUG_REPORT_WARNING_BIT,
                           "format %s is simulating unsupported features!\n", vkFormatToString(format).c_str());
            }
        }
    }

    LogFlush(layer_settings);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFormatProperties2(VkPhysicalDevice physicalDevice, VkFormat format,
                                                              VkFormatProperties2KHR *pFormatProperties) {
    std::lock_guard<std::recursive_mutex> lock(global_lock);
    const auto dt = instance_dispatch_table(physicalDevice);
    dt->GetPhysicalDeviceFormatProperties2(physicalDevice, format, pFormatProperties);
    GetPhysicalDeviceFormatProperties(physicalDevice, format, &pFormatProperties->formatProperties);
    PhysicalDeviceData *pdd = PhysicalDeviceData::Find(physicalDevice);
    FillFormatPropertiesPNextChain(pdd, pFormatProperties->pNext, format);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFormatProperties2KHR(VkPhysicalDevice physicalDevice, VkFormat format,
                                                                 VkFormatProperties2KHR *pFormatProperties) {
    GetPhysicalDeviceFormatProperties2(physicalDevice, format, pFormatProperties);
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceImageFormatProperties(VkPhysicalDevice physicalDevice, VkFormat format,
                                                                      VkImageType type, VkImageTiling tiling,
                                                                      VkImageUsageFlags usage, VkImageCreateFlags flags,
                                                                      VkImageFormatProperties *pImageFormatProperties) {
    std::lock_guard<std::recursive_mutex> lock(global_lock);
    const auto dt = instance_dispatch_table(physicalDevice);

    PhysicalDeviceData *pdd = PhysicalDeviceData::Find(physicalDevice);
    ProfileLayerSettings* layer_settings = &JsonLoader::Find(pdd->instance())->layer_settings;

    // Are there JSON overrides, or should we call down to return the original values?
    if (!(layer_settings->simulate.capabilities & SIMULATE_FORMATS_BIT)) {
        return dt->GetPhysicalDeviceImageFormatProperties(physicalDevice, format, type, tiling, usage, flags,
                                                          pImageFormatProperties);
    }

    VkFormatProperties fmt_props = {};
    GetPhysicalDeviceFormatProperties(physicalDevice, format, &fmt_props);

    if (!IsFormatSupported(fmt_props)) {
        *pImageFormatProperties = VkImageFormatProperties{};
        return VK_ERROR_FORMAT_NOT_SUPPORTED;
    }

    VkResult result =
        dt->GetPhysicalDeviceImageFormatProperties(physicalDevice, format, type, tiling, usage, flags, pImageFormatProperties);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceImageFormatProperties2KHR(
    VkPhysicalDevice physicalDevice, const VkPhysicalDeviceImageFormatInfo2KHR *pImageFormatInfo,
    VkImageFormatProperties2KHR *pImageFormatProperties) {
    std::lock_guard<std::recursive_mutex> lock(global_lock);
    const auto dt = instance_dispatch_table(physicalDevice);

#ifndef VULKANSC
    PhysicalDeviceData *pdd = PhysicalDeviceData::Find(physicalDevice);
    ProfileLayerSettings* layer_settings = &JsonLoader::Find(pdd->instance())->layer_settings;

    if (layer_settings->simulate.capabilities & SIMULATE_VIDEO_FORMATS_BIT) {
        // If video profile lists are provided, make sure to only report support for actually supported video formats
        auto p = reinterpret_cast<const VkBaseInStructure*>(pImageFormatInfo);
        while (p != nullptr && p->sType != VK_STRUCTURE_TYPE_VIDEO_PROFILE_LIST_INFO_KHR) {
            p = p->pNext;
        }
        if (p != nullptr) {
            const auto video_profile_list = reinterpret_cast<const VkVideoProfileListInfoKHR*>(p);
            for (uint32_t i = 0; i < video_profile_list->profileCount; ++i) {
                VideoProfileData in_video_profile{};

                // Construct and verify video profile info chain
                in_video_profile.info = VideoProfileInfoChain(&video_profile_list->pProfiles[i]);
                if (!in_video_profile.info.valid) {
                    return VK_ERROR_VIDEO_PROFILE_CODEC_NOT_SUPPORTED_KHR;
                }

                auto video_profile_data_it = pdd->set_of_video_profiles_.find(in_video_profile);
                if (video_profile_data_it == pdd->set_of_video_profiles_.end()) {
                    return VK_ERROR_VIDEO_PROFILE_CODEC_NOT_SUPPORTED_KHR;
                }

                // VK_IMAGE_CREATE_VIDEO_PROFILE_INDEPENDENT_BIT_KHR is ignored from compatibility perspective
                const VkImageCreateFlags ignored_create_flags = VK_IMAGE_CREATE_VIDEO_PROFILE_INDEPENDENT_BIT_KHR;
                const VkImageCreateFlags image_create_flags = pImageFormatInfo->flags & ~ignored_create_flags;

                bool found_matching = false;
                for (const auto &formats_per_category_it : video_profile_data_it->formats) {
                    for (const auto &format : formats_per_category_it.second) {
                        if (pImageFormatInfo->format == format.video_format_properties_.format &&
                            pImageFormatInfo->type == format.video_format_properties_.imageType &&
                            pImageFormatInfo->tiling == format.video_format_properties_.imageTiling &&
                            (pImageFormatInfo->usage & format.video_format_properties_.imageUsageFlags) == pImageFormatInfo->usage &&
                            (image_create_flags & format.video_format_properties_.imageCreateFlags) == image_create_flags) {
                            found_matching = true;
                            break;
                        }
                    }
                    if (found_matching) break;
                }
                if (!found_matching) {
                    return VK_ERROR_VIDEO_PROFILE_FORMAT_NOT_SUPPORTED_KHR;
                }
            }
        }
    }
#endif  // VULKANSC

    return dt->GetPhysicalDeviceImageFormatProperties2(physicalDevice, pImageFormatInfo, pImageFormatProperties);
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceImageFormatProperties2(VkPhysicalDevice physicalDevice,
                                                                       const VkPhysicalDeviceImageFormatInfo2 *pImageFormatInfo,
                                                                       VkImageFormatProperties2 *pImageFormatProperties) {
    return GetPhysicalDeviceImageFormatProperties2KHR(physicalDevice, pImageFormatInfo, pImageFormatProperties);
}

#ifndef VULKANSC
VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceVideoCapabilitiesKHR(VkPhysicalDevice physicalDevice,
                                                                     const VkVideoProfileInfoKHR *pVideoProfile,
                                                                     VkVideoCapabilitiesKHR *pCapabilities) {
    std::lock_guard<std::recursive_mutex> lock(global_lock);
    const auto dt = instance_dispatch_table(physicalDevice);

    PhysicalDeviceData *pdd = PhysicalDeviceData::Find(physicalDevice);
    ProfileLayerSettings* layer_settings = &JsonLoader::Find(pdd->instance())->layer_settings;

    if (layer_settings->simulate.capabilities & SIMULATE_VIDEO_CAPABILITIES_BIT) {
        VideoProfileData in_video_profile{};

        // Construct and verify video profile info chain
        in_video_profile.info = VideoProfileInfoChain(pVideoProfile);
        if (!in_video_profile.info.valid) {
            return VK_ERROR_VIDEO_PROFILE_CODEC_NOT_SUPPORTED_KHR;
        }

        auto video_profile_data_it = pdd->set_of_video_profiles_.find(in_video_profile);
        if (video_profile_data_it == pdd->set_of_video_profiles_.end()) {
            return VK_ERROR_VIDEO_PROFILE_CODEC_NOT_SUPPORTED_KHR;
        }

        video_profile_data_it->caps.CopyTo(pCapabilities);
        return VK_SUCCESS;
    } else {
        return dt->GetPhysicalDeviceVideoCapabilitiesKHR(physicalDevice, pVideoProfile, pCapabilities);
    }
}


VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceVideoFormatPropertiesKHR(VkPhysicalDevice physicalDevice,
                                                                         const VkPhysicalDeviceVideoFormatInfoKHR *pVideoFormatInfo,
                                                                         uint32_t *pVideoFormatPropertyCount,
                                                                         VkVideoFormatPropertiesKHR *pVideoFormatProperties) {
    std::lock_guard<std::recursive_mutex> lock(global_lock);
    const auto dt = instance_dispatch_table(physicalDevice);

    PhysicalDeviceData *pdd = PhysicalDeviceData::Find(physicalDevice);
    ProfileLayerSettings* layer_settings = &JsonLoader::Find(pdd->instance())->layer_settings;

    if (layer_settings->simulate.capabilities & SIMULATE_VIDEO_FORMATS_BIT) {
        auto p = reinterpret_cast<const VkBaseInStructure*>(pVideoFormatInfo);
        while (p != nullptr && p->sType != VK_STRUCTURE_TYPE_VIDEO_PROFILE_LIST_INFO_KHR) {
            p = p->pNext;
        }
        if (p == nullptr) {
            return VK_ERROR_VIDEO_PROFILE_OPERATION_NOT_SUPPORTED_KHR;
        }

        SetOfVideoProfileFormats formats{};
        const auto video_profile_list = reinterpret_cast<const VkVideoProfileListInfoKHR*>(p);
        for (uint32_t i = 0; i < video_profile_list->profileCount; ++i) {
            VideoProfileData in_video_profile{};

            // Construct and verify video profile info chain
            in_video_profile.info = VideoProfileInfoChain(&video_profile_list->pProfiles[i]);
            if (!in_video_profile.info.valid) {
                return VK_ERROR_VIDEO_PROFILE_CODEC_NOT_SUPPORTED_KHR;
            }

            auto video_profile_data_it = pdd->set_of_video_profiles_.find(in_video_profile);
            if (video_profile_data_it == pdd->set_of_video_profiles_.end()) {
                return VK_ERROR_VIDEO_PROFILE_CODEC_NOT_SUPPORTED_KHR;
            }

            if (i == 0) {
                // First video profile, just take all matching formats as the initial set
                const auto in_usage = pVideoFormatInfo->imageUsage;
                for (const auto &formats_per_category_it : video_profile_data_it->formats) {
                    for (const auto &format : formats_per_category_it.second) {
                        if ((format.video_format_properties_.imageUsageFlags & in_usage) == in_usage) {
                            formats.insert(format);
                        }
                    }
                }
            } else {
                // For all other video profiles find any matching formats and intersect the properties
                SetOfVideoProfileFormats common_formats{};
                for (const auto &format : formats) {
                    for (const auto &formats_per_category_it : video_profile_data_it->formats) {
                        auto format_it = formats_per_category_it.second.find(format);
                        if (format_it != formats_per_category_it.second.end()) {
                            auto common_format = format;
                            common_format.IntersectWith(*format_it);
                            common_formats.insert(common_format);
                        }
                    }
                }
                formats = std::move(common_formats);
            }
        }

        VkResult result = VK_SUCCESS;
        if (pVideoFormatProperties != nullptr) {
            if (*pVideoFormatPropertyCount < formats.size()) {
                result = VK_INCOMPLETE;
            } else {
                *pVideoFormatPropertyCount = static_cast<uint32_t>(formats.size());
            }
            uint32_t i = 0;
            for (const auto &format : formats) {
                if (i >= *pVideoFormatPropertyCount) break;
                format.CopyTo(&pVideoFormatProperties[i]);
                i++;
            }
        } else {
            *pVideoFormatPropertyCount = static_cast<uint32_t>(formats.size());
        }
        return result;
    } else {
        return dt->GetPhysicalDeviceVideoFormatPropertiesKHR(physicalDevice, pVideoFormatInfo,
                                                             pVideoFormatPropertyCount, pVideoFormatProperties);
    }
}
#endif  // VULKANSC

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceToolPropertiesEXT(VkPhysicalDevice physicalDevice, uint32_t *pToolCount,
                                                                  VkPhysicalDeviceToolPropertiesEXT *pToolProperties) {
    std::stringstream version_stream;
    version_stream << kVersionProfilesMajor << "." << kVersionProfilesMinor << "." << kVersionProfilesPatch;
    std::string version_string(version_stream.str());

    static VkPhysicalDeviceToolPropertiesEXT profiles_layer_tool_props = {};
    profiles_layer_tool_props.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TOOL_PROPERTIES_EXT;
    profiles_layer_tool_props.pNext = nullptr;
    strcpy(profiles_layer_tool_props.name, kLayerProperties[0].description);
    strcpy(profiles_layer_tool_props.version, version_string.c_str());
    profiles_layer_tool_props.purposes = VK_TOOL_PURPOSE_MODIFYING_FEATURES_BIT_EXT;
    strcpy(profiles_layer_tool_props.description, kLayerProperties[0].description);
    strcpy(profiles_layer_tool_props.layer, kLayerProperties[0].layerName);

    auto original_pToolProperties = pToolProperties;
    if (pToolProperties != nullptr) {
        *pToolProperties = profiles_layer_tool_props;
        pToolProperties = ((*pToolCount > 1) ? &pToolProperties[1] : nullptr);
        (*pToolCount)--;
    }

    VkuInstanceDispatchTable *pInstanceTable = instance_dispatch_table(physicalDevice);
    VkResult result = pInstanceTable->GetPhysicalDeviceToolPropertiesEXT(physicalDevice, pToolCount, pToolProperties);

    if (original_pToolProperties != nullptr) {
        pToolProperties = original_pToolProperties;
    }

    (*pToolCount)++;

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceToolProperties(VkPhysicalDevice physicalDevice, uint32_t *pToolCount,
                                                               VkPhysicalDeviceToolProperties *pToolProperties) {
    return GetPhysicalDeviceToolPropertiesEXT(physicalDevice, pToolCount, pToolProperties);
}

#define TRANSFER_VALUE(name)    \
    if (promoted_written) {     \
        std::memmove(&src->name, &dest->name, sizeof(src->name)); \
    } else {                    \
        std::memmove(&dest->name, &src->name, sizeof(dest->name)); \
    }

#define TRANSFER_VALUE_ARRAY(name)    \
    if (promoted_written) {     \
        std::memmove(src->name, dest->name, sizeof(src->name)); \
    } else {                    \
        std::memmove(dest->name, src->name, sizeof(dest->name)); \
    }

#undef TRANSFER_VALUE_ARRAY
#undef TRANSFER_VALUE

void LoadDeviceFormats(VkInstance instance, PhysicalDeviceData *pdd, VkPhysicalDevice pd, MapOfVkFormatProperties *dest,
                       MapOfVkFormatProperties3 *dest3) {
    std::vector<VkFormat> formats = {
        VK_FORMAT_UNDEFINED,
        VK_FORMAT_R4G4_UNORM_PACK8,
        VK_FORMAT_R4G4B4A4_UNORM_PACK16,
        VK_FORMAT_B4G4R4A4_UNORM_PACK16,
        VK_FORMAT_R5G6B5_UNORM_PACK16,
        VK_FORMAT_B5G6R5_UNORM_PACK16,
        VK_FORMAT_R5G5B5A1_UNORM_PACK16,
        VK_FORMAT_B5G5R5A1_UNORM_PACK16,
        VK_FORMAT_A1R5G5B5_UNORM_PACK16,
        VK_FORMAT_R8_UNORM,
        VK_FORMAT_R8_SNORM,
        VK_FORMAT_R8_USCALED,
        VK_FORMAT_R8_SSCALED,
        VK_FORMAT_R8_UINT,
        VK_FORMAT_R8_SINT,
        VK_FORMAT_R8_SRGB,
        VK_FORMAT_R8G8_UNORM,
        VK_FORMAT_R8G8_SNORM,
        VK_FORMAT_R8G8_USCALED,
        VK_FORMAT_R8G8_SSCALED,
        VK_FORMAT_R8G8_UINT,
        VK_FORMAT_R8G8_SINT,
        VK_FORMAT_R8G8_SRGB,
        VK_FORMAT_R8G8B8_UNORM,
        VK_FORMAT_R8G8B8_SNORM,
        VK_FORMAT_R8G8B8_USCALED,
        VK_FORMAT_R8G8B8_SSCALED,
        VK_FORMAT_R8G8B8_UINT,
        VK_FORMAT_R8G8B8_SINT,
        VK_FORMAT_R8G8B8_SRGB,
        VK_FORMAT_B8G8R8_UNORM,
        VK_FORMAT_B8G8R8_SNORM,
        VK_FORMAT_B8G8R8_USCALED,
        VK_FORMAT_B8G8R8_SSCALED,
        VK_FORMAT_B8G8R8_UINT,
        VK_FORMAT_B8G8R8_SINT,
        VK_FORMAT_B8G8R8_SRGB,
        VK_FORMAT_R8G8B8A8_UNORM,
        VK_FORMAT_R8G8B8A8_SNORM,
        VK_FORMAT_R8G8B8A8_USCALED,
        VK_FORMAT_R8G8B8A8_SSCALED,
        VK_FORMAT_R8G8B8A8_UINT,
        VK_FORMAT_R8G8B8A8_SINT,
        VK_FORMAT_R8G8B8A8_SRGB,
        VK_FORMAT_B8G8R8A8_UNORM,
        VK_FORMAT_B8G8R8A8_SNORM,
        VK_FORMAT_B8G8R8A8_USCALED,
        VK_FORMAT_B8G8R8A8_SSCALED,
        VK_FORMAT_B8G8R8A8_UINT,
        VK_FORMAT_B8G8R8A8_SINT,
        VK_FORMAT_B8G8R8A8_SRGB,
        VK_FORMAT_A8B8G8R8_UNORM_PACK32,
        VK_FORMAT_A8B8G8R8_SNORM_PACK32,
        VK_FORMAT_A8B8G8R8_USCALED_PACK32,
        VK_FORMAT_A8B8G8R8_SSCALED_PACK32,
        VK_FORMAT_A8B8G8R8_UINT_PACK32,
        VK_FORMAT_A8B8G8R8_SINT_PACK32,
        VK_FORMAT_A8B8G8R8_SRGB_PACK32,
        VK_FORMAT_A2R10G10B10_UNORM_PACK32,
        VK_FORMAT_A2R10G10B10_SNORM_PACK32,
        VK_FORMAT_A2R10G10B10_USCALED_PACK32,
        VK_FORMAT_A2R10G10B10_SSCALED_PACK32,
        VK_FORMAT_A2R10G10B10_UINT_PACK32,
        VK_FORMAT_A2R10G10B10_SINT_PACK32,
        VK_FORMAT_A2B10G10R10_UNORM_PACK32,
        VK_FORMAT_A2B10G10R10_SNORM_PACK32,
        VK_FORMAT_A2B10G10R10_USCALED_PACK32,
        VK_FORMAT_A2B10G10R10_SSCALED_PACK32,
        VK_FORMAT_A2B10G10R10_UINT_PACK32,
        VK_FORMAT_A2B10G10R10_SINT_PACK32,
        VK_FORMAT_R16_UNORM,
        VK_FORMAT_R16_SNORM,
        VK_FORMAT_R16_USCALED,
        VK_FORMAT_R16_SSCALED,
        VK_FORMAT_R16_UINT,
        VK_FORMAT_R16_SINT,
        VK_FORMAT_R16_SFLOAT,
        VK_FORMAT_R16G16_UNORM,
        VK_FORMAT_R16G16_SNORM,
        VK_FORMAT_R16G16_USCALED,
        VK_FORMAT_R16G16_SSCALED,
        VK_FORMAT_R16G16_UINT,
        VK_FORMAT_R16G16_SINT,
        VK_FORMAT_R16G16_SFLOAT,
        VK_FORMAT_R16G16B16_UNORM,
        VK_FORMAT_R16G16B16_SNORM,
        VK_FORMAT_R16G16B16_USCALED,
        VK_FORMAT_R16G16B16_SSCALED,
        VK_FORMAT_R16G16B16_UINT,
        VK_FORMAT_R16G16B16_SINT,
        VK_FORMAT_R16G16B16_SFLOAT,
        VK_FORMAT_R16G16B16A16_UNORM,
        VK_FORMAT_R16G16B16A16_SNORM,
        VK_FORMAT_R16G16B16A16_USCALED,
        VK_FORMAT_R16G16B16A16_SSCALED,
        VK_FORMAT_R16G16B16A16_UINT,
        VK_FORMAT_R16G16B16A16_SINT,
        VK_FORMAT_R16G16B16A16_SFLOAT,
        VK_FORMAT_R32_UINT,
        VK_FORMAT_R32_SINT,
        VK_FORMAT_R32_SFLOAT,
        VK_FORMAT_R32G32_UINT,
        VK_FORMAT_R32G32_SINT,
        VK_FORMAT_R32G32_SFLOAT,
        VK_FORMAT_R32G32B32_UINT,
        VK_FORMAT_R32G32B32_SINT,
        VK_FORMAT_R32G32B32_SFLOAT,
        VK_FORMAT_R32G32B32A32_UINT,
        VK_FORMAT_R32G32B32A32_SINT,
        VK_FORMAT_R32G32B32A32_SFLOAT,
        VK_FORMAT_R64_UINT,
        VK_FORMAT_R64_SINT,
        VK_FORMAT_R64_SFLOAT,
        VK_FORMAT_R64G64_UINT,
        VK_FORMAT_R64G64_SINT,
        VK_FORMAT_R64G64_SFLOAT,
        VK_FORMAT_R64G64B64_UINT,
        VK_FORMAT_R64G64B64_SINT,
        VK_FORMAT_R64G64B64_SFLOAT,
        VK_FORMAT_R64G64B64A64_UINT,
        VK_FORMAT_R64G64B64A64_SINT,
        VK_FORMAT_R64G64B64A64_SFLOAT,
        VK_FORMAT_B10G11R11_UFLOAT_PACK32,
        VK_FORMAT_E5B9G9R9_UFLOAT_PACK32,
        VK_FORMAT_D16_UNORM,
        VK_FORMAT_X8_D24_UNORM_PACK32,
        VK_FORMAT_D32_SFLOAT,
        VK_FORMAT_S8_UINT,
        VK_FORMAT_D16_UNORM_S8_UINT,
        VK_FORMAT_D24_UNORM_S8_UINT,
        VK_FORMAT_D32_SFLOAT_S8_UINT,
        VK_FORMAT_BC1_RGB_UNORM_BLOCK,
        VK_FORMAT_BC1_RGB_SRGB_BLOCK,
        VK_FORMAT_BC1_RGBA_UNORM_BLOCK,
        VK_FORMAT_BC1_RGBA_SRGB_BLOCK,
        VK_FORMAT_BC2_UNORM_BLOCK,
        VK_FORMAT_BC2_SRGB_BLOCK,
        VK_FORMAT_BC3_UNORM_BLOCK,
        VK_FORMAT_BC3_SRGB_BLOCK,
        VK_FORMAT_BC4_UNORM_BLOCK,
        VK_FORMAT_BC4_SNORM_BLOCK,
        VK_FORMAT_BC5_UNORM_BLOCK,
        VK_FORMAT_BC5_SNORM_BLOCK,
        VK_FORMAT_BC6H_UFLOAT_BLOCK,
        VK_FORMAT_BC6H_SFLOAT_BLOCK,
        VK_FORMAT_BC7_UNORM_BLOCK,
        VK_FORMAT_BC7_SRGB_BLOCK,
        VK_FORMAT_ETC2_R8G8B8_UNORM_BLOCK,
        VK_FORMAT_ETC2_R8G8B8_SRGB_BLOCK,
        VK_FORMAT_ETC2_R8G8B8A1_UNORM_BLOCK,
        VK_FORMAT_ETC2_R8G8B8A1_SRGB_BLOCK,
        VK_FORMAT_ETC2_R8G8B8A8_UNORM_BLOCK,
        VK_FORMAT_ETC2_R8G8B8A8_SRGB_BLOCK,
        VK_FORMAT_EAC_R11_UNORM_BLOCK,
        VK_FORMAT_EAC_R11_SNORM_BLOCK,
        VK_FORMAT_EAC_R11G11_UNORM_BLOCK,
        VK_FORMAT_EAC_R11G11_SNORM_BLOCK,
        VK_FORMAT_ASTC_4x4_UNORM_BLOCK,
        VK_FORMAT_ASTC_4x4_SRGB_BLOCK,
        VK_FORMAT_ASTC_5x4_UNORM_BLOCK,
        VK_FORMAT_ASTC_5x4_SRGB_BLOCK,
        VK_FORMAT_ASTC_5x5_UNORM_BLOCK,
        VK_FORMAT_ASTC_5x5_SRGB_BLOCK,
        VK_FORMAT_ASTC_6x5_UNORM_BLOCK,
        VK_FORMAT_ASTC_6x5_SRGB_BLOCK,
        VK_FORMAT_ASTC_6x6_UNORM_BLOCK,
        VK_FORMAT_ASTC_6x6_SRGB_BLOCK,
        VK_FORMAT_ASTC_8x5_UNORM_BLOCK,
        VK_FORMAT_ASTC_8x5_SRGB_BLOCK,
        VK_FORMAT_ASTC_8x6_UNORM_BLOCK,
        VK_FORMAT_ASTC_8x6_SRGB_BLOCK,
        VK_FORMAT_ASTC_8x8_UNORM_BLOCK,
        VK_FORMAT_ASTC_8x8_SRGB_BLOCK,
        VK_FORMAT_ASTC_10x5_UNORM_BLOCK,
        VK_FORMAT_ASTC_10x5_SRGB_BLOCK,
        VK_FORMAT_ASTC_10x6_UNORM_BLOCK,
        VK_FORMAT_ASTC_10x6_SRGB_BLOCK,
        VK_FORMAT_ASTC_10x8_UNORM_BLOCK,
        VK_FORMAT_ASTC_10x8_SRGB_BLOCK,
        VK_FORMAT_ASTC_10x10_UNORM_BLOCK,
        VK_FORMAT_ASTC_10x10_SRGB_BLOCK,
        VK_FORMAT_ASTC_12x10_UNORM_BLOCK,
        VK_FORMAT_ASTC_12x10_SRGB_BLOCK,
        VK_FORMAT_ASTC_12x12_UNORM_BLOCK,
        VK_FORMAT_ASTC_12x12_SRGB_BLOCK,
        VK_FORMAT_G8B8G8R8_422_UNORM,
        VK_FORMAT_B8G8R8G8_422_UNORM,
        VK_FORMAT_G8_B8_R8_3PLANE_420_UNORM,
        VK_FORMAT_G8_B8R8_2PLANE_420_UNORM,
        VK_FORMAT_G8_B8_R8_3PLANE_422_UNORM,
        VK_FORMAT_G8_B8R8_2PLANE_422_UNORM,
        VK_FORMAT_G8_B8_R8_3PLANE_444_UNORM,
        VK_FORMAT_R10X6_UNORM_PACK16,
        VK_FORMAT_R10X6G10X6_UNORM_2PACK16,
        VK_FORMAT_R10X6G10X6B10X6A10X6_UNORM_4PACK16,
        VK_FORMAT_G10X6B10X6G10X6R10X6_422_UNORM_4PACK16,
        VK_FORMAT_B10X6G10X6R10X6G10X6_422_UNORM_4PACK16,
        VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_420_UNORM_3PACK16,
        VK_FORMAT_G10X6_B10X6R10X6_2PLANE_420_UNORM_3PACK16,
        VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_422_UNORM_3PACK16,
        VK_FORMAT_G10X6_B10X6R10X6_2PLANE_422_UNORM_3PACK16,
        VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_444_UNORM_3PACK16,
        VK_FORMAT_R12X4_UNORM_PACK16,
        VK_FORMAT_R12X4G12X4_UNORM_2PACK16,
        VK_FORMAT_R12X4G12X4B12X4A12X4_UNORM_4PACK16,
        VK_FORMAT_G12X4B12X4G12X4R12X4_422_UNORM_4PACK16,
        VK_FORMAT_B12X4G12X4R12X4G12X4_422_UNORM_4PACK16,
        VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_420_UNORM_3PACK16,
        VK_FORMAT_G12X4_B12X4R12X4_2PLANE_420_UNORM_3PACK16,
        VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_422_UNORM_3PACK16,
        VK_FORMAT_G12X4_B12X4R12X4_2PLANE_422_UNORM_3PACK16,
        VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_444_UNORM_3PACK16,
        VK_FORMAT_G16B16G16R16_422_UNORM,
        VK_FORMAT_B16G16R16G16_422_UNORM,
        VK_FORMAT_G16_B16_R16_3PLANE_420_UNORM,
        VK_FORMAT_G16_B16R16_2PLANE_420_UNORM,
        VK_FORMAT_G16_B16_R16_3PLANE_422_UNORM,
        VK_FORMAT_G16_B16R16_2PLANE_422_UNORM,
        VK_FORMAT_G16_B16_R16_3PLANE_444_UNORM,
        VK_FORMAT_G8_B8R8_2PLANE_444_UNORM,
        VK_FORMAT_G10X6_B10X6R10X6_2PLANE_444_UNORM_3PACK16,
        VK_FORMAT_G12X4_B12X4R12X4_2PLANE_444_UNORM_3PACK16,
        VK_FORMAT_G16_B16R16_2PLANE_444_UNORM,
        VK_FORMAT_A4R4G4B4_UNORM_PACK16,
        VK_FORMAT_A4B4G4R4_UNORM_PACK16,
        VK_FORMAT_ASTC_4x4_SFLOAT_BLOCK,
        VK_FORMAT_ASTC_5x4_SFLOAT_BLOCK,
        VK_FORMAT_ASTC_5x5_SFLOAT_BLOCK,
        VK_FORMAT_ASTC_6x5_SFLOAT_BLOCK,
        VK_FORMAT_ASTC_6x6_SFLOAT_BLOCK,
        VK_FORMAT_ASTC_8x5_SFLOAT_BLOCK,
        VK_FORMAT_ASTC_8x6_SFLOAT_BLOCK,
        VK_FORMAT_ASTC_8x8_SFLOAT_BLOCK,
        VK_FORMAT_ASTC_10x5_SFLOAT_BLOCK,
        VK_FORMAT_ASTC_10x6_SFLOAT_BLOCK,
        VK_FORMAT_ASTC_10x8_SFLOAT_BLOCK,
        VK_FORMAT_ASTC_10x10_SFLOAT_BLOCK,
        VK_FORMAT_ASTC_12x10_SFLOAT_BLOCK,
        VK_FORMAT_ASTC_12x12_SFLOAT_BLOCK,
        VK_FORMAT_A1B5G5R5_UNORM_PACK16,
        VK_FORMAT_A8_UNORM,
    };
    const auto dt = instance_dispatch_table(instance);
    for (const auto format : formats) {
        VkFormatProperties3KHR format_properties_3 = {};
        format_properties_3.sType = VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_3_KHR;

        VkFormatProperties2 format_properties = {};
        format_properties.sType = VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2;
        format_properties.pNext = &format_properties_3;

        if (pdd->GetEffectiveVersion() >= VK_API_VERSION_1_1) {
            dt->GetPhysicalDeviceFormatProperties2(pd, format, &format_properties);
        } else {
            dt->GetPhysicalDeviceFormatProperties2KHR(pd, format, &format_properties);
        }
        (*dest)[format] = format_properties.formatProperties;
        (*dest3)[format] = format_properties_3;
    }
}

void LoadQueueFamilyProperties(VkInstance instance, VkPhysicalDevice pd, PhysicalDeviceData *pdd) {
    const auto dt = instance_dispatch_table(instance);
    uint32_t count = 0;
    if (pdd->GetEffectiveVersion() >= VK_API_VERSION_1_1) {
        dt->GetPhysicalDeviceQueueFamilyProperties2(pd, &count, nullptr);
    } else {
        dt->GetPhysicalDeviceQueueFamilyProperties2KHR(pd, &count, nullptr);
    }
    if (count > 0) {
        pdd->device_queue_family_properties_.resize(count);
        std::vector<void *> pNext(count);
        std::vector<VkQueueFamilyProperties2> props(count);
        for (uint32_t i = 0; i < count; ++i) {
            if (PhysicalDeviceData::HasExtension(pdd, VK_KHR_MAINTENANCE_9_EXTENSION_NAME)) {
                pdd->device_queue_family_properties_[i].ownership_transfer_properties_.pNext = pNext[i];

                pNext[i] = &pdd->device_queue_family_properties_[i].ownership_transfer_properties_;
            }
            if (PhysicalDeviceData::HasExtension(pdd, VK_KHR_GLOBAL_PRIORITY_EXTENSION_NAME)) {
                pdd->device_queue_family_properties_[i].global_priority_properties_.pNext = pNext[i];

                pNext[i] = &pdd->device_queue_family_properties_[i].global_priority_properties_;
            }
            if (PhysicalDeviceData::HasExtension(pdd, VK_KHR_VIDEO_QUEUE_EXTENSION_NAME)) {
                pdd->device_queue_family_properties_[i].video_properties_.pNext = pNext[i];

                pNext[i] = &pdd->device_queue_family_properties_[i].video_properties_;

                pdd->device_queue_family_properties_[i].query_result_status_properties_.pNext = pNext[i];

                pNext[i] = &pdd->device_queue_family_properties_[i].query_result_status_properties_;
            }
            if (PhysicalDeviceData::HasExtension(pdd, VK_NV_DEVICE_DIAGNOSTIC_CHECKPOINTS_EXTENSION_NAME)) {
                pdd->device_queue_family_properties_[i].checkpoint_properties_.pNext = pNext[i];

                pNext[i] = &pdd->device_queue_family_properties_[i].checkpoint_properties_;

                if (PhysicalDeviceData::HasExtension(pdd, VK_KHR_SYNCHRONIZATION_2_EXTENSION_NAME)) {
                    pdd->device_queue_family_properties_[i].checkpoint_properties_2_.pNext = pNext[i];

                    pNext[i] = &pdd->device_queue_family_properties_[i].checkpoint_properties_2_;
                }
            }
            pdd->device_queue_family_properties_[i].properties_2.pNext = pNext[i];
            props[i] = pdd->device_queue_family_properties_[i].properties_2;
        }
        if (pdd->GetEffectiveVersion() >= VK_API_VERSION_1_1) {
            dt->GetPhysicalDeviceQueueFamilyProperties2(pd, &count, props.data());
        } else {
            dt->GetPhysicalDeviceQueueFamilyProperties2KHR(pd, &count, props.data());
        }
        for (uint32_t i = 0; i < count; ++i) {
            pdd->device_queue_family_properties_[i].properties_2 = props[i];
        }
    }
}

#ifndef VULKANSC
static void LoadVideoProfiles(VkInstance instance, VkPhysicalDevice pd, PhysicalDeviceData *pdd, SimulateCapabilityFlags flags) {
    if (!PhysicalDeviceData::HasExtension(pdd, "VK_KHR_video_queue")) {
        return;
    }

    auto check_api_version = [&](uint32_t api_version) { return pdd->GetEffectiveVersion() >= api_version; };
    auto check_extension = [&](const char* extension) { return PhysicalDeviceData::HasExtension(pdd, extension); };

    const auto dt = instance_dispatch_table(instance);
    ProfileLayerSettings *layer_settings = &JsonLoader::Find(instance)->layer_settings;
    ForEachVideoProfile([&](const VkVideoProfileInfoKHR& info, const char *name) {
        VideoProfileData video_profile{};

        // Construct and verify video profile info chain
        video_profile.info = VideoProfileInfoChain(&info);
        if (!video_profile.info.valid) {
            LogMessage(layer_settings, DEBUG_REPORT_ERROR_BIT, "Invalid video profile info chain for video profile '%s'.\n", name);
            return;
        }

        // Construct and verify video profile capabilities chain
        video_profile.caps = VideoCapabilitiesChain(info.videoCodecOperation, check_api_version, check_extension);
        if (!video_profile.caps.valid) {
            LogMessage(layer_settings, DEBUG_REPORT_ERROR_BIT, "Invalid video capabilities chain for video profile '%s'.\n", name);
            return;
        }

        // Query physical device support and capabilities
        VkResult result = dt->GetPhysicalDeviceVideoCapabilitiesKHR(pd, &video_profile.info.video_profile_info_,
                                                                    &video_profile.caps.video_capabilities_);
        if (result < VK_SUCCESS) return;

        // If needed, also load video format data
        if (flags & SIMULATE_VIDEO_FORMATS_BIT) {
            VkVideoProfileListInfoKHR video_profile_list{VK_STRUCTURE_TYPE_VIDEO_PROFILE_LIST_INFO_KHR};
            video_profile_list.profileCount = 1;
            video_profile_list.pProfiles = &info;
            VkPhysicalDeviceVideoFormatInfoKHR video_format_info{VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_FORMAT_INFO_KHR,
                                                                 &video_profile_list};
            for (const auto usage : video_profile.GetSupportedFormatCategories()) {
                video_format_info.imageUsage = usage;

                // Query number of video formats for the given usage
                uint32_t format_count = 0;
                result = dt->GetPhysicalDeviceVideoFormatPropertiesKHR(pd, &video_format_info, &format_count, nullptr);
                if (result < VK_SUCCESS) continue;
                if (format_count == 0) continue;

                // Construct and verify video profile format chains
                std::vector<VkVideoFormatPropertiesKHR> video_format_props(format_count);
                std::vector<VideoFormatPropertiesChain> video_profile_formats(format_count,
                    VideoFormatPropertiesChain(info.videoCodecOperation, usage, check_api_version, check_extension));
                if (!video_profile_formats[0].valid) {
                    LogMessage(layer_settings, DEBUG_REPORT_ERROR_BIT,
                               "Invalid video format properties chain for video profile '%s'.\n", name);
                    continue;
                }
                for (uint32_t i = 0; i < format_count; ++i) {
                    video_format_props[i] = video_profile_formats[i].video_format_properties_;
                }
                result = dt->GetPhysicalDeviceVideoFormatPropertiesKHR(pd, &video_format_info, &format_count, video_format_props.data());
                if (result < VK_SUCCESS) {
                    LogMessage(layer_settings, DEBUG_REPORT_ERROR_BIT,
                               "Failed to query video format properties for video profile '%s'.\n", name);
                    continue;
                }

                // Store video formats in the video profile data
                for (uint32_t i = 0; i < format_count; ++i) {
                    video_profile_formats[i].video_format_properties_ = video_format_props[i];
                    video_profile.formats[usage].insert(video_profile_formats[i]);
                }
            }
        }

        // Store video profile data in the physical device data
        pdd->set_of_device_video_profiles_.insert(video_profile);
    });
}
#endif  // VULKANSC

VKAPI_ATTR VkResult VKAPI_CALL EnumeratePhysicalDevices(VkInstance instance, uint32_t *pPhysicalDeviceCount,
                                                        VkPhysicalDevice *pPhysicalDevices) {
    // Our layer-specific initialization...

    std::lock_guard<std::recursive_mutex> lock(global_lock);
    const auto dt = instance_dispatch_table(instance);

    ProfileLayerSettings *layer_settings = &JsonLoader::Find(instance)->layer_settings;

    VkResult result = VK_SUCCESS;
    result = dt->EnumeratePhysicalDevices(instance, pPhysicalDeviceCount, pPhysicalDevices);

    // HACK!! epd_count is used to ensure the following code only gets called _after_ vkCreateInstance finishes *in the "vkcube +
    // profiles" use case*
    if (pPhysicalDevices && (VK_SUCCESS == result)) {
        std::vector<VkPhysicalDevice> physical_devices;
        result = EnumerateAll<VkPhysicalDevice>(physical_devices, [&](uint32_t *count, VkPhysicalDevice *results) {
            return dt->EnumeratePhysicalDevices(instance, count, results);
        });

        if (result != VK_SUCCESS) {
            return result;
        }

        if (layer_settings->device.force_device != FORCE_DEVICE_OFF && *pPhysicalDeviceCount == 1) {
            LogMessage(layer_settings, DEBUG_REPORT_NOTIFICATION_BIT, "Forced physical device is disabled because a single physical device was found.\n");
            layer_settings->device.force_device = FORCE_DEVICE_OFF;
        }

        switch (layer_settings->device.force_device) {
            default:
            case FORCE_DEVICE_OFF: {
                break;
            }
            case FORCE_DEVICE_WITH_UUID: {
                bool found = false;
                for (std::size_t i = 0, n = physical_devices.size(); i < n; ++i) {
                    VkPhysicalDeviceIDPropertiesKHR properties_deviceid{VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES_KHR};
                    VkPhysicalDeviceProperties2 properties2{VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2, &properties_deviceid};

                    dt->GetPhysicalDeviceProperties2(physical_devices[i], &properties2);

                    if (layer_settings->device.force_device_uuid == GetUUIDString(properties_deviceid.deviceUUID)) {
                        layer_settings->device.force_device_name = properties2.properties.deviceName;
                        *pPhysicalDevices = physical_devices[i];
                        found = true;
                        break;
                    }
                }

                static bool force_physical_device_log_once = false;
                if (found) {
                    *pPhysicalDeviceCount = 1;

                    std::vector<VkPhysicalDevice> physical_devices_tmp;
                    physical_devices_tmp.push_back(*pPhysicalDevices);
                    std::swap(physical_devices, physical_devices_tmp);

                    if (!force_physical_device_log_once) {
                        LogMessage(layer_settings, DEBUG_REPORT_NOTIFICATION_BIT,
                            "Force physical device by device UUID: '%s'('%s').\n",
                            layer_settings->device.force_device_uuid.c_str(),
                            layer_settings->device.force_device_name.c_str());
                    }
                } else {
                    if (!force_physical_device_log_once) {
                        LogMessage(layer_settings, DEBUG_REPORT_ERROR_BIT,
                            "Force physical device by device UUID is active but the requested physical device '%s'('%s') couldn't be found.\n",
                            layer_settings->device.force_device_uuid.c_str(),
                            layer_settings->device.force_device_name.c_str());
                    }
                }
                force_physical_device_log_once = true;
                break;
            }
            case FORCE_DEVICE_WITH_NAME: {
                bool found = false;
                for (std::size_t i = 0, n = physical_devices.size(); i < n; ++i) {
                    VkPhysicalDeviceProperties physical_device_properties;
                    dt->GetPhysicalDeviceProperties(physical_devices[i], &physical_device_properties);

                    if (layer_settings->device.force_device_name == physical_device_properties.deviceName) {
                        *pPhysicalDevices = physical_devices[i];
                        found = true;
                        break;
                    }
                }

                static bool force_physical_device_log_once = false;
                if (found) {
                    *pPhysicalDeviceCount = 1;

                    std::vector<VkPhysicalDevice> physical_devices_tmp;
                    physical_devices_tmp.push_back(*pPhysicalDevices);
                    std::swap(physical_devices, physical_devices_tmp);

                    if (!force_physical_device_log_once) {
                        LogMessage(layer_settings, DEBUG_REPORT_NOTIFICATION_BIT,
                            "Force physical device by device name: '%s'.\n",
                            layer_settings->device.force_device_name.c_str());
                    }
                }
                else {
                    if (!force_physical_device_log_once) {
                        LogMessage(layer_settings, DEBUG_REPORT_ERROR_BIT,
                            "Force physical device by device name is active but the requested physical device '%s' couldn't be found.\n",
                            layer_settings->device.force_device_name.c_str());
                    }
                }
                force_physical_device_log_once = true;
                break;
            }
        }

        // For each physical device, create and populate a PDD instance.
        for (const auto &physical_device : physical_devices) {
            if (PhysicalDeviceData::Find(physical_device)) {
                continue;
            }

            PhysicalDeviceData &pdd = PhysicalDeviceData::Create(physical_device, instance);
            ArrayOfVkExtensionProperties local_device_extensions;
            EnumerateAll<VkExtensionProperties>(local_device_extensions, [&](uint32_t *count, VkExtensionProperties *results) {
                return dt->EnumerateDeviceExtensionProperties(physical_device, nullptr, count, results);
            });

            pdd.device_extensions_.reserve(local_device_extensions.size());
            for(const auto& ext: local_device_extensions) {
                pdd.device_extensions_.insert({&(ext.extensionName[0]), ext});
            }

            pdd.simulation_extensions_ = pdd.device_extensions_;

            dt->GetPhysicalDeviceProperties(physical_device, &pdd.physical_device_properties_);
            uint32_t effective_api_version = pdd.GetEffectiveVersion();
#ifdef VULKANSC
            bool api_version_above_1_0 = effective_api_version >= VKSC_API_VERSION_1_0;
#else
            bool api_version_above_1_1 = effective_api_version >= VK_API_VERSION_1_1;
            bool api_version_above_1_2 = effective_api_version >= VK_API_VERSION_1_2;
            bool api_version_above_1_3 = effective_api_version >= VK_API_VERSION_1_3;
            bool api_version_above_1_4 = effective_api_version >= VK_API_VERSION_1_4;
#endif

            ::device_has_astc_hdr = ::PhysicalDeviceData::HasExtension(&pdd, VK_EXT_TEXTURE_COMPRESSION_ASTC_HDR_EXTENSION_NAME);
            ::device_has_pvrtc = ::PhysicalDeviceData::HasExtension(&pdd, VK_IMG_FORMAT_PVRTC_EXTENSION_NAME);

            // Initialize PDD members to the actual Vulkan implementation's defaults.
            {
                VkPhysicalDeviceProperties2KHR property_chain = {VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2_KHR};
                VkPhysicalDeviceFeatures2KHR feature_chain = {VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2_KHR};
                VkPhysicalDeviceMemoryProperties2KHR memory_chain = {VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2_KHR};

#ifndef VULKANSC
                if (PhysicalDeviceData::HasExtension(&pdd, VK_KHR_PORTABILITY_SUBSET_EXTENSION_NAME)) {
                    property_chain.pNext = &(pdd.physical_device_portability_subset_properties_);
                    feature_chain.pNext = &(pdd.physical_device_portability_subset_features_);
                } else if (layer_settings->simulate.emulate_portability) {
                    pdd.physical_device_portability_subset_properties_ = {
                        VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_PROPERTIES_KHR, nullptr, layer_settings->portability.minVertexInputBindingStrideAlignment};
                    pdd.physical_device_portability_subset_features_ = {
                        VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_FEATURES_KHR,
                        nullptr,
                        layer_settings->portability.constantAlphaColorBlendFactors,
                        layer_settings->portability.events,
                        layer_settings->portability.imageViewFormatReinterpretation,
                        layer_settings->portability.imageViewFormatSwizzle,
                        layer_settings->portability.imageView2DOn3DImage,
                        layer_settings->portability.multisampleArrayImage,
                        layer_settings->portability.mutableComparisonSamplers,
                        layer_settings->portability.pointPolygons,
                        layer_settings->portability.samplerMipLodBias,
                        layer_settings->portability.separateStencilMaskRef,
                        layer_settings->portability.shaderSampleRateInterpolationFunctions,
                        layer_settings->portability.tessellationIsolines,
                        layer_settings->portability.tessellationPointMode,
                        layer_settings->portability.triangleFans,
                        layer_settings->portability.vertexAttributeAccessBeyondStride};
                }
#endif

                if (PhysicalDeviceData::HasExtension(&pdd, VK_EXT_TEXTURE_COMPRESSION_ASTC_HDR_EXTENSION_NAME)) {
                    pdd.physical_device_texture_compression_astchdrfeatures_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_texture_compression_astchdrfeatures_);
                }

                if (PhysicalDeviceData::HasExtension(&pdd, VK_EXT_ASTC_DECODE_MODE_EXTENSION_NAME)) {
                    pdd.physical_device_astcdecode_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_astcdecode_features_);
                }

                if (PhysicalDeviceData::HasExtension(&pdd, VK_EXT_DISCARD_RECTANGLES_EXTENSION_NAME)) {
                    pdd.physical_device_discard_rectangle_properties_.pNext = property_chain.pNext;

                    property_chain.pNext = &(pdd.physical_device_discard_rectangle_properties_);
                }

                if (PhysicalDeviceData::HasExtension(&pdd, VK_EXT_CONSERVATIVE_RASTERIZATION_EXTENSION_NAME)) {
                    pdd.physical_device_conservative_rasterization_properties_.pNext = property_chain.pNext;

                    property_chain.pNext = &(pdd.physical_device_conservative_rasterization_properties_);
                }

                if (PhysicalDeviceData::HasExtension(&pdd, VK_EXT_DEPTH_CLIP_ENABLE_EXTENSION_NAME)) {
                    pdd.physical_device_depth_clip_enable_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_depth_clip_enable_features_);
                }

                if (PhysicalDeviceData::HasExtension(&pdd, VK_KHR_PERFORMANCE_QUERY_EXTENSION_NAME)) {
                    pdd.physical_device_performance_query_properties_.pNext = property_chain.pNext;

                    property_chain.pNext = &(pdd.physical_device_performance_query_properties_);
                    pdd.physical_device_performance_query_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_performance_query_features_);
                }

                if (PhysicalDeviceData::HasExtension(&pdd, VK_EXT_SAMPLE_LOCATIONS_EXTENSION_NAME)) {
                    pdd.physical_device_sample_locations_properties_.pNext = property_chain.pNext;

                    property_chain.pNext = &(pdd.physical_device_sample_locations_properties_);
                }

                if (PhysicalDeviceData::HasExtension(&pdd, VK_EXT_BLEND_OPERATION_ADVANCED_EXTENSION_NAME)) {
                    pdd.physical_device_blend_operation_advanced_properties_.pNext = property_chain.pNext;

                    property_chain.pNext = &(pdd.physical_device_blend_operation_advanced_properties_);
                    pdd.physical_device_blend_operation_advanced_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_blend_operation_advanced_features_);
                }

                if (PhysicalDeviceData::HasExtension(&pdd, VK_EXT_EXTERNAL_MEMORY_HOST_EXTENSION_NAME)) {
                    pdd.physical_device_external_memory_host_properties_.pNext = property_chain.pNext;

                    property_chain.pNext = &(pdd.physical_device_external_memory_host_properties_);
                }

                if (PhysicalDeviceData::HasExtension(&pdd, VK_KHR_SHADER_CLOCK_EXTENSION_NAME)) {
                    pdd.physical_device_shader_clock_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_shader_clock_features_);
                }

                if (PhysicalDeviceData::HasExtension(&pdd, VK_KHR_GLOBAL_PRIORITY_EXTENSION_NAME)) {
                    pdd.physical_device_global_priority_query_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_global_priority_query_features_);
                }

                if (PhysicalDeviceData::HasExtension(&pdd, VK_EXT_PCI_BUS_INFO_EXTENSION_NAME)) {
                    pdd.physical_device_pcibus_info_properties_.pNext = property_chain.pNext;

                    property_chain.pNext = &(pdd.physical_device_pcibus_info_properties_);
                }

                if (PhysicalDeviceData::HasExtension(&pdd, VK_KHR_SHADER_TERMINATE_INVOCATION_EXTENSION_NAME)) {
                    pdd.physical_device_shader_terminate_invocation_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_shader_terminate_invocation_features_);
                }

                if (PhysicalDeviceData::HasExtension(&pdd, VK_EXT_SUBGROUP_SIZE_CONTROL_EXTENSION_NAME)) {
                    pdd.physical_device_subgroup_size_control_properties_.pNext = property_chain.pNext;

                    property_chain.pNext = &(pdd.physical_device_subgroup_size_control_properties_);
                    pdd.physical_device_subgroup_size_control_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_subgroup_size_control_features_);
                }

                if (PhysicalDeviceData::HasExtension(&pdd, VK_KHR_FRAGMENT_SHADING_RATE_EXTENSION_NAME)) {
                    pdd.physical_device_fragment_shading_rate_properties_.pNext = property_chain.pNext;

                    property_chain.pNext = &(pdd.physical_device_fragment_shading_rate_properties_);
                    pdd.physical_device_fragment_shading_rate_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_fragment_shading_rate_features_);
                }

                if (PhysicalDeviceData::HasExtension(&pdd, VK_EXT_SHADER_IMAGE_ATOMIC_INT64_EXTENSION_NAME)) {
                    pdd.physical_device_shader_image_atomic_int_64_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_shader_image_atomic_int_64_features_);
                }

                if (PhysicalDeviceData::HasExtension(&pdd, VK_EXT_FRAGMENT_SHADER_INTERLOCK_EXTENSION_NAME)) {
                    pdd.physical_device_fragment_shader_interlock_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_fragment_shader_interlock_features_);
                }

                if (PhysicalDeviceData::HasExtension(&pdd, VK_EXT_YCBCR_IMAGE_ARRAYS_EXTENSION_NAME)) {
                    pdd.physical_device_ycbcr_image_arrays_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_ycbcr_image_arrays_features_);
                }

                if (PhysicalDeviceData::HasExtension(&pdd, VK_EXT_LINE_RASTERIZATION_EXTENSION_NAME) || PhysicalDeviceData::HasExtension(&pdd, VK_KHR_LINE_RASTERIZATION_EXTENSION_NAME)) {
                    pdd.physical_device_line_rasterization_properties_.pNext = property_chain.pNext;

                    property_chain.pNext = &(pdd.physical_device_line_rasterization_properties_);
                    pdd.physical_device_line_rasterization_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_line_rasterization_features_);
                }

                if (PhysicalDeviceData::HasExtension(&pdd, VK_EXT_SHADER_ATOMIC_FLOAT_EXTENSION_NAME)) {
                    pdd.physical_device_shader_atomic_float_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_shader_atomic_float_features_);
                }

                if (PhysicalDeviceData::HasExtension(&pdd, VK_EXT_INDEX_TYPE_UINT8_EXTENSION_NAME) || PhysicalDeviceData::HasExtension(&pdd, VK_KHR_INDEX_TYPE_UINT8_EXTENSION_NAME)) {
                    pdd.physical_device_index_type_uint_8_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_index_type_uint_8_features_);
                }

                if (PhysicalDeviceData::HasExtension(&pdd, VK_EXT_EXTENDED_DYNAMIC_STATE_EXTENSION_NAME)) {
                    pdd.physical_device_extended_dynamic_state_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_extended_dynamic_state_features_);
                }

                if (PhysicalDeviceData::HasExtension(&pdd, VK_EXT_SHADER_DEMOTE_TO_HELPER_INVOCATION_EXTENSION_NAME)) {
                    pdd.physical_device_shader_demote_to_helper_invocation_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_shader_demote_to_helper_invocation_features_);
                }

                if (PhysicalDeviceData::HasExtension(&pdd, VK_EXT_TEXEL_BUFFER_ALIGNMENT_EXTENSION_NAME)) {
                    pdd.physical_device_texel_buffer_alignment_properties_.pNext = property_chain.pNext;

                    property_chain.pNext = &(pdd.physical_device_texel_buffer_alignment_properties_);
                    pdd.physical_device_texel_buffer_alignment_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_texel_buffer_alignment_features_);
                }

                if (PhysicalDeviceData::HasExtension(&pdd, VK_EXT_ROBUSTNESS_2_EXTENSION_NAME)) {
                    pdd.physical_device_robustness_2_properties_.pNext = property_chain.pNext;

                    property_chain.pNext = &(pdd.physical_device_robustness_2_properties_);
                    pdd.physical_device_robustness_2_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_robustness_2_features_);
                }

                if (PhysicalDeviceData::HasExtension(&pdd, VK_EXT_CUSTOM_BORDER_COLOR_EXTENSION_NAME)) {
                    pdd.physical_device_custom_border_color_properties_.pNext = property_chain.pNext;

                    property_chain.pNext = &(pdd.physical_device_custom_border_color_properties_);
                    pdd.physical_device_custom_border_color_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_custom_border_color_features_);
                }

                if (PhysicalDeviceData::HasExtension(&pdd, VK_KHR_SYNCHRONIZATION_2_EXTENSION_NAME)) {
                    pdd.physical_device_synchronization_2_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_synchronization_2_features_);
                }

                if (PhysicalDeviceData::HasExtension(&pdd, VK_EXT_YCBCR_2PLANE_444_FORMATS_EXTENSION_NAME)) {
                    pdd.physical_device_ycbcr_2_plane_444_formats_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_ycbcr_2_plane_444_formats_features_);
                }

                if (PhysicalDeviceData::HasExtension(&pdd, VK_EXT_IMAGE_ROBUSTNESS_EXTENSION_NAME)) {
                    pdd.physical_device_image_robustness_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_image_robustness_features_);
                }

                if (PhysicalDeviceData::HasExtension(&pdd, VK_EXT_4444_FORMATS_EXTENSION_NAME)) {
                    pdd.physical_device_4444_formats_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_4444_formats_features_);
                }

                if (PhysicalDeviceData::HasExtension(&pdd, VK_EXT_VERTEX_INPUT_DYNAMIC_STATE_EXTENSION_NAME)) {
                    pdd.physical_device_vertex_input_dynamic_state_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_vertex_input_dynamic_state_features_);
                }
#ifdef VK_USE_PLATFORM_SCI

                if (PhysicalDeviceData::HasExtension(&pdd, VK_NV_EXTERNAL_SCI_SYNC_EXTENSION_NAME)) {
                    pdd.physical_device_external_sci_sync_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_external_sci_sync_features_);
                }
#endif // VK_USE_PLATFORM_SCI
#ifdef VK_USE_PLATFORM_SCI

                if (PhysicalDeviceData::HasExtension(&pdd, VK_NV_EXTERNAL_MEMORY_SCI_BUF_EXTENSION_NAME)) {
                    pdd.physical_device_external_memory_sci_buf_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_external_memory_sci_buf_features_);
                }
#endif // VK_USE_PLATFORM_SCI

                if (PhysicalDeviceData::HasExtension(&pdd, VK_EXT_EXTENDED_DYNAMIC_STATE_2_EXTENSION_NAME)) {
                    pdd.physical_device_extended_dynamic_state_2_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_extended_dynamic_state_2_features_);
                }

                if (PhysicalDeviceData::HasExtension(&pdd, VK_EXT_COLOR_WRITE_ENABLE_EXTENSION_NAME)) {
                    pdd.physical_device_color_write_enable_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_color_write_enable_features_);
                }
#ifdef VK_USE_PLATFORM_SCI

                if (PhysicalDeviceData::HasExtension(&pdd, VK_NV_EXTERNAL_SCI_SYNC_2_EXTENSION_NAME)) {
                    pdd.physical_device_external_sci_sync_2_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_external_sci_sync_2_features_);
                }
#endif // VK_USE_PLATFORM_SCI

                if (PhysicalDeviceData::HasExtension(&pdd, VK_KHR_VERTEX_ATTRIBUTE_DIVISOR_EXTENSION_NAME)) {
                    pdd.physical_device_vertex_attribute_divisor_properties_.pNext = property_chain.pNext;

                    property_chain.pNext = &(pdd.physical_device_vertex_attribute_divisor_properties_);
                    pdd.physical_device_vertex_attribute_divisor_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_vertex_attribute_divisor_features_);
                }
#ifdef VK_USE_PLATFORM_SCREEN_QNX

                if (PhysicalDeviceData::HasExtension(&pdd, VK_QNX_EXTERNAL_MEMORY_SCREEN_BUFFER_EXTENSION_NAME)) {
                    pdd.physical_device_external_memory_screen_buffer_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_external_memory_screen_buffer_features_);
                }
#endif // VK_USE_PLATFORM_SCREEN_QNX

                if (api_version_above_1_0) {
                    pdd.physical_device_push_descriptor_properties_.pNext = property_chain.pNext;

                    property_chain.pNext = &(pdd.physical_device_push_descriptor_properties_);
                }

                if (api_version_above_1_0) {
                    pdd.physical_device_driver_properties_.pNext = property_chain.pNext;

                    property_chain.pNext = &(pdd.physical_device_driver_properties_);
                }

                if (api_version_above_1_0) {
                    pdd.physical_device_idproperties_.pNext = property_chain.pNext;

                    property_chain.pNext = &(pdd.physical_device_idproperties_);
                }

                if (api_version_above_1_0) {
                    pdd.physical_device_multiview_properties_.pNext = property_chain.pNext;

                    property_chain.pNext = &(pdd.physical_device_multiview_properties_);
                }

                if (api_version_above_1_0) {
                    pdd.physical_device_subgroup_properties_.pNext = property_chain.pNext;

                    property_chain.pNext = &(pdd.physical_device_subgroup_properties_);
                }

                if (api_version_above_1_0) {
                    pdd.physical_device_point_clipping_properties_.pNext = property_chain.pNext;

                    property_chain.pNext = &(pdd.physical_device_point_clipping_properties_);
                }

                if (api_version_above_1_0) {
                    pdd.physical_device_protected_memory_properties_.pNext = property_chain.pNext;

                    property_chain.pNext = &(pdd.physical_device_protected_memory_properties_);
                }

                if (api_version_above_1_0) {
                    pdd.physical_device_sampler_filter_minmax_properties_.pNext = property_chain.pNext;

                    property_chain.pNext = &(pdd.physical_device_sampler_filter_minmax_properties_);
                }

                if (api_version_above_1_0) {
                    pdd.physical_device_inline_uniform_block_properties_.pNext = property_chain.pNext;

                    property_chain.pNext = &(pdd.physical_device_inline_uniform_block_properties_);
                }

                if (api_version_above_1_0) {
                    pdd.physical_device_maintenance_3_properties_.pNext = property_chain.pNext;

                    property_chain.pNext = &(pdd.physical_device_maintenance_3_properties_);
                }

                if (api_version_above_1_0) {
                    pdd.physical_device_maintenance_4_properties_.pNext = property_chain.pNext;

                    property_chain.pNext = &(pdd.physical_device_maintenance_4_properties_);
                }

                if (api_version_above_1_0) {
                    pdd.physical_device_maintenance_5_properties_.pNext = property_chain.pNext;

                    property_chain.pNext = &(pdd.physical_device_maintenance_5_properties_);
                }

                if (api_version_above_1_0) {
                    pdd.physical_device_maintenance_6_properties_.pNext = property_chain.pNext;

                    property_chain.pNext = &(pdd.physical_device_maintenance_6_properties_);
                }

                if (api_version_above_1_0) {
                    pdd.physical_device_float_controls_properties_.pNext = property_chain.pNext;

                    property_chain.pNext = &(pdd.physical_device_float_controls_properties_);
                }

                if (api_version_above_1_0) {
                    pdd.physical_device_descriptor_indexing_properties_.pNext = property_chain.pNext;

                    property_chain.pNext = &(pdd.physical_device_descriptor_indexing_properties_);
                }

                if (api_version_above_1_0) {
                    pdd.physical_device_timeline_semaphore_properties_.pNext = property_chain.pNext;

                    property_chain.pNext = &(pdd.physical_device_timeline_semaphore_properties_);
                }

                if (api_version_above_1_0) {
                    pdd.physical_device_depth_stencil_resolve_properties_.pNext = property_chain.pNext;

                    property_chain.pNext = &(pdd.physical_device_depth_stencil_resolve_properties_);
                }

                if (api_version_above_1_0) {
                    pdd.physical_device_vulkan_11_properties_.pNext = property_chain.pNext;

                    property_chain.pNext = &(pdd.physical_device_vulkan_11_properties_);
                }

                if (api_version_above_1_0) {
                    pdd.physical_device_vulkan_12_properties_.pNext = property_chain.pNext;

                    property_chain.pNext = &(pdd.physical_device_vulkan_12_properties_);
                }

                if (api_version_above_1_0) {
                    pdd.physical_device_vulkan_13_properties_.pNext = property_chain.pNext;

                    property_chain.pNext = &(pdd.physical_device_vulkan_13_properties_);
                }

                if (api_version_above_1_0) {
                    pdd.physical_device_vulkan_14_properties_.pNext = property_chain.pNext;

                    property_chain.pNext = &(pdd.physical_device_vulkan_14_properties_);
                }

                if (api_version_above_1_0) {
                    pdd.physical_device_host_image_copy_properties_.pNext = property_chain.pNext;

                    property_chain.pNext = &(pdd.physical_device_host_image_copy_properties_);
                }

                if (api_version_above_1_0) {
                    pdd.physical_device_vulkan_sc_10_properties_.pNext = property_chain.pNext;

                    property_chain.pNext = &(pdd.physical_device_vulkan_sc_10_properties_);
                }

                if (api_version_above_1_0) {
                    pdd.physical_device_shader_integer_dot_product_properties_.pNext = property_chain.pNext;

                    property_chain.pNext = &(pdd.physical_device_shader_integer_dot_product_properties_);
                }

                if (api_version_above_1_0) {
                    pdd.physical_device_pipeline_robustness_properties_.pNext = property_chain.pNext;

                    property_chain.pNext = &(pdd.physical_device_pipeline_robustness_properties_);
                }

                if (api_version_above_1_0) {
                    pdd.physical_device_private_data_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_private_data_features_);
                }

                if (api_version_above_1_0) {
                    pdd.physical_device_variable_pointer_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_variable_pointer_features_);
                }

                if (api_version_above_1_0) {
                    pdd.physical_device_multiview_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_multiview_features_);
                }

                if (api_version_above_1_0) {
                    pdd.physical_device_16_bit_storage_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_16_bit_storage_features_);
                }

                if (api_version_above_1_0) {
                    pdd.physical_device_shader_subgroup_extended_types_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_shader_subgroup_extended_types_features_);
                }

                if (api_version_above_1_0) {
                    pdd.physical_device_sampler_ycbcr_conversion_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_sampler_ycbcr_conversion_features_);
                }

                if (api_version_above_1_0) {
                    pdd.physical_device_protected_memory_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_protected_memory_features_);
                }

                if (api_version_above_1_0) {
                    pdd.physical_device_inline_uniform_block_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_inline_uniform_block_features_);
                }

                if (api_version_above_1_0) {
                    pdd.physical_device_maintenance_4_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_maintenance_4_features_);
                }

                if (api_version_above_1_0) {
                    pdd.physical_device_maintenance_5_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_maintenance_5_features_);
                }

                if (api_version_above_1_0) {
                    pdd.physical_device_maintenance_6_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_maintenance_6_features_);
                }

                if (api_version_above_1_0) {
                    pdd.physical_device_shader_draw_parameter_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_shader_draw_parameter_features_);
                }

                if (api_version_above_1_0) {
                    pdd.physical_device_float_16_int_8_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_float_16_int_8_features_);
                }

                if (api_version_above_1_0) {
                    pdd.physical_device_host_query_reset_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_host_query_reset_features_);
                }

                if (api_version_above_1_0) {
                    pdd.physical_device_descriptor_indexing_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_descriptor_indexing_features_);
                }

                if (api_version_above_1_0) {
                    pdd.physical_device_timeline_semaphore_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_timeline_semaphore_features_);
                }

                if (api_version_above_1_0) {
                    pdd.physical_device_8_bit_storage_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_8_bit_storage_features_);
                }

                if (api_version_above_1_0) {
                    pdd.physical_device_vulkan_memory_model_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_vulkan_memory_model_features_);
                }

                if (api_version_above_1_0) {
                    pdd.physical_device_shader_atomic_int_64_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_shader_atomic_int_64_features_);
                }

                if (api_version_above_1_0) {
                    pdd.physical_device_scalar_block_layout_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_scalar_block_layout_features_);
                }

                if (api_version_above_1_0) {
                    pdd.physical_device_uniform_buffer_standard_layout_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_uniform_buffer_standard_layout_features_);
                }

                if (api_version_above_1_0) {
                    pdd.physical_device_buffer_device_address_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_buffer_device_address_features_);
                }

                if (api_version_above_1_0) {
                    pdd.physical_device_imageless_framebuffer_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_imageless_framebuffer_features_);
                }

                if (api_version_above_1_0) {
                    pdd.physical_device_separate_depth_stencil_layouts_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_separate_depth_stencil_layouts_features_);
                }

                if (api_version_above_1_0) {
                    pdd.physical_device_pipeline_creation_cache_control_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_pipeline_creation_cache_control_features_);
                }

                if (api_version_above_1_0) {
                    pdd.physical_device_vulkan_11_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_vulkan_11_features_);
                }

                if (api_version_above_1_0) {
                    pdd.physical_device_vulkan_12_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_vulkan_12_features_);
                }

                if (api_version_above_1_0) {
                    pdd.physical_device_vulkan_13_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_vulkan_13_features_);
                }

                if (api_version_above_1_0) {
                    pdd.physical_device_vulkan_14_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_vulkan_14_features_);
                }

                if (api_version_above_1_0) {
                    pdd.physical_device_zero_initialize_workgroup_memory_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_zero_initialize_workgroup_memory_features_);
                }

                if (api_version_above_1_0) {
                    pdd.physical_device_host_image_copy_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_host_image_copy_features_);
                }

                if (api_version_above_1_0) {
                    pdd.physical_device_vulkan_sc_10_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_vulkan_sc_10_features_);
                }

                if (api_version_above_1_0) {
                    pdd.physical_device_pipeline_protected_access_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_pipeline_protected_access_features_);
                }

                if (api_version_above_1_0) {
                    pdd.physical_device_shader_integer_dot_product_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_shader_integer_dot_product_features_);
                }

                if (api_version_above_1_0) {
                    pdd.physical_device_dynamic_rendering_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_dynamic_rendering_features_);
                }

                if (api_version_above_1_0) {
                    pdd.physical_device_pipeline_robustness_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_pipeline_robustness_features_);
                }

                if (api_version_above_1_0) {
                    pdd.physical_device_shader_subgroup_rotate_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_shader_subgroup_rotate_features_);
                }

                if (api_version_above_1_0) {
                    pdd.physical_device_shader_expect_assume_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_shader_expect_assume_features_);
                }

                if (api_version_above_1_0) {
                    pdd.physical_device_shader_float_controls_2_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_shader_float_controls_2_features_);
                }

                if (api_version_above_1_0) {
                    pdd.physical_device_dynamic_rendering_local_read_features_.pNext = feature_chain.pNext;

                    feature_chain.pNext = &(pdd.physical_device_dynamic_rendering_local_read_features_);
                }

                if (pdd.GetEffectiveVersion() >= VK_API_VERSION_1_1) {
                    dt->GetPhysicalDeviceProperties2(physical_device, &property_chain);
                    if (layer_settings->simulate.default_feature_values == DEFAULT_FEATURE_VALUES_DEVICE) {
                        dt->GetPhysicalDeviceFeatures2(physical_device, &feature_chain);
                    }
                    dt->GetPhysicalDeviceMemoryProperties2(physical_device, &memory_chain);
                } else {
                    dt->GetPhysicalDeviceProperties2(physical_device, &property_chain);
                    if (layer_settings->simulate.default_feature_values == DEFAULT_FEATURE_VALUES_DEVICE) {
                        dt->GetPhysicalDeviceFeatures2(physical_device, &feature_chain);
                    }
                    dt->GetPhysicalDeviceMemoryProperties2(physical_device, &memory_chain);
                }

                pdd.physical_device_properties_ = property_chain.properties;
                pdd.physical_device_features_ = feature_chain.features;
                pdd.physical_device_memory_properties_ = memory_chain.memoryProperties;
            }

            ::device_has_astc = pdd.physical_device_features_.textureCompressionASTC_LDR == VK_TRUE;
            ::device_has_bc = pdd.physical_device_features_.textureCompressionBC == VK_TRUE;
            ::device_has_etc2 = pdd.physical_device_features_.textureCompressionETC2 == VK_TRUE;

            if (layer_settings->simulate.capabilities & SIMULATE_FORMATS_BIT) {
                LoadDeviceFormats(instance, &pdd, physical_device, &pdd.device_formats_, &pdd.device_formats_3_);
            }
            if (layer_settings->simulate.capabilities & SIMULATE_QUEUE_FAMILY_PROPERTIES_BIT) {
                LoadQueueFamilyProperties(instance, physical_device, &pdd);
            }
#ifndef VULKANSC
            if (layer_settings->simulate.capabilities & (SIMULATE_VIDEO_CAPABILITIES_BIT | SIMULATE_VIDEO_FORMATS_BIT)) {
                LoadVideoProfiles(instance, physical_device, &pdd, layer_settings->simulate.capabilities);
            }
#endif  // VULKANSC

            LogMessage(layer_settings, DEBUG_REPORT_NOTIFICATION_BIT,
                       "Found \"%s\" with Vulkan %d.%d.%d driver.\n", pdd.physical_device_properties_.deviceName,
                              VK_API_VERSION_MAJOR(pdd.physical_device_properties_.apiVersion),
                              VK_API_VERSION_MINOR(pdd.physical_device_properties_.apiVersion),
                              VK_API_VERSION_PATCH(pdd.physical_device_properties_.apiVersion));

            // Override PDD members with values from configuration file(s).
            if (result == VK_SUCCESS) {
                JsonLoader &json_loader = *JsonLoader::Find(instance);
                result = json_loader.LoadDevice(pdd.physical_device_properties_.deviceName, &pdd);
            }

            if (layer_settings->simulate.capabilities & SIMULATE_EXTENSIONS_BIT) {
                pdd.simulation_extensions_ = pdd.map_of_extension_properties_;
            } else {
                pdd.simulation_extensions_ = pdd.device_extensions_;
            }

            for (std::size_t j = 0, m = layer_settings->simulate.exclude_device_extensions.size(); j < m; ++j) {
                pdd.simulation_extensions_.erase(layer_settings->simulate.exclude_device_extensions[j].c_str());
            }
        }
    }

    LogFlush(layer_settings);

    return result;
}

VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL GetInstanceProcAddr(VkInstance instance, const char *pName) {
// Apply the DRY principle, see https://en.wikipedia.org/wiki/Don%27t_repeat_yourself
#define GET_PROC_ADDR(func) \
    if (strcmp("vk" #func, pName) == 0) return reinterpret_cast<PFN_vkVoidFunction>(func);
    GET_PROC_ADDR(GetInstanceProcAddr);
    GET_PROC_ADDR(CreateInstance);
    GET_PROC_ADDR(EnumerateInstanceLayerProperties);
    GET_PROC_ADDR(EnumerateInstanceExtensionProperties);
    GET_PROC_ADDR(EnumerateDeviceExtensionProperties);
    GET_PROC_ADDR(EnumeratePhysicalDevices);
    GET_PROC_ADDR(DestroyInstance);
    GET_PROC_ADDR(GetPhysicalDeviceProperties);
    GET_PROC_ADDR(GetPhysicalDeviceProperties2);
    GET_PROC_ADDR(GetPhysicalDeviceProperties2KHR);
    GET_PROC_ADDR(GetPhysicalDeviceFeatures);
    GET_PROC_ADDR(GetPhysicalDeviceFeatures2);
    GET_PROC_ADDR(GetPhysicalDeviceFeatures2KHR);
    GET_PROC_ADDR(GetPhysicalDeviceFormatProperties);
    GET_PROC_ADDR(GetPhysicalDeviceFormatProperties2);
    GET_PROC_ADDR(GetPhysicalDeviceFormatProperties2KHR);
    GET_PROC_ADDR(GetPhysicalDeviceImageFormatProperties);
    GET_PROC_ADDR(GetPhysicalDeviceImageFormatProperties2);
    GET_PROC_ADDR(GetPhysicalDeviceImageFormatProperties2KHR);
    GET_PROC_ADDR(GetPhysicalDeviceToolProperties);
    GET_PROC_ADDR(GetPhysicalDeviceToolPropertiesEXT);
    GET_PROC_ADDR(GetPhysicalDeviceQueueFamilyProperties);
    GET_PROC_ADDR(GetPhysicalDeviceQueueFamilyProperties2);
    GET_PROC_ADDR(GetPhysicalDeviceQueueFamilyProperties2KHR);
#ifndef VULKANSC
    GET_PROC_ADDR(GetPhysicalDeviceVideoCapabilitiesKHR);
    GET_PROC_ADDR(GetPhysicalDeviceVideoFormatPropertiesKHR);
#endif  // VULKANSC
#undef GET_PROC_ADDR

    if (!instance) {
        return nullptr;
    }

    std::lock_guard<std::recursive_mutex> lock(global_lock);
    const auto dt = instance_dispatch_table(instance);

    if (!dt->GetInstanceProcAddr) {
        return nullptr;
    }
    return dt->GetInstanceProcAddr(instance, pName);
}
