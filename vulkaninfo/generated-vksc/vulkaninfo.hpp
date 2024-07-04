
/*
 * Copyright (c) 2019-2022 The Khronos Group Inc.
 * Copyright (c) 2019-2022 Valve Corporation
 * Copyright (c) 2019-2022 LunarG, Inc.
 * Copyright (c) 2023-2023 RasterGrid Kft.
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
 * Author: Charles Giessen <charles@lunarg.com>
 *
 */

/*
 * This file is generated from the Khronos Vulkan XML API Registry.
 */

#include "vulkaninfo.h"
#include "outputprinter.h"

template <typename T>
std::string to_hex_str(const T i) {
    std::stringstream stream;
    stream << "0x" << std::setfill('0') << std::setw(sizeof(T)) << std::hex << i;
    return stream.str();
}

template <typename T>
std::string to_hex_str(Printer &p, const T i) {
    if (p.Type() == OutputType::json)
        return std::to_string(i);
    else if (p.Type() == OutputType::vkconfig_output)
        return std::string("\"") + to_hex_str(i) + std::string("\"");
    else
        return to_hex_str(i);
}

std::string VkColorSpaceKHRString(VkColorSpaceKHR value) {
    switch (value) {
        case (VK_COLOR_SPACE_SRGB_NONLINEAR_KHR): return "COLOR_SPACE_SRGB_NONLINEAR_KHR";
        case (VK_COLOR_SPACE_DISPLAY_P3_NONLINEAR_EXT): return "COLOR_SPACE_DISPLAY_P3_NONLINEAR_EXT";
        case (VK_COLOR_SPACE_EXTENDED_SRGB_LINEAR_EXT): return "COLOR_SPACE_EXTENDED_SRGB_LINEAR_EXT";
        case (VK_COLOR_SPACE_DISPLAY_P3_LINEAR_EXT): return "COLOR_SPACE_DISPLAY_P3_LINEAR_EXT";
        case (VK_COLOR_SPACE_DCI_P3_NONLINEAR_EXT): return "COLOR_SPACE_DCI_P3_NONLINEAR_EXT";
        case (VK_COLOR_SPACE_BT709_LINEAR_EXT): return "COLOR_SPACE_BT709_LINEAR_EXT";
        case (VK_COLOR_SPACE_BT709_NONLINEAR_EXT): return "COLOR_SPACE_BT709_NONLINEAR_EXT";
        case (VK_COLOR_SPACE_BT2020_LINEAR_EXT): return "COLOR_SPACE_BT2020_LINEAR_EXT";
        case (VK_COLOR_SPACE_HDR10_ST2084_EXT): return "COLOR_SPACE_HDR10_ST2084_EXT";
        case (VK_COLOR_SPACE_DOLBYVISION_EXT): return "COLOR_SPACE_DOLBYVISION_EXT";
        case (VK_COLOR_SPACE_HDR10_HLG_EXT): return "COLOR_SPACE_HDR10_HLG_EXT";
        case (VK_COLOR_SPACE_ADOBERGB_LINEAR_EXT): return "COLOR_SPACE_ADOBERGB_LINEAR_EXT";
        case (VK_COLOR_SPACE_ADOBERGB_NONLINEAR_EXT): return "COLOR_SPACE_ADOBERGB_NONLINEAR_EXT";
        case (VK_COLOR_SPACE_PASS_THROUGH_EXT): return "COLOR_SPACE_PASS_THROUGH_EXT";
        case (VK_COLOR_SPACE_EXTENDED_SRGB_NONLINEAR_EXT): return "COLOR_SPACE_EXTENDED_SRGB_NONLINEAR_EXT";
        case (VK_COLOR_SPACE_DISPLAY_NATIVE_AMD): return "COLOR_SPACE_DISPLAY_NATIVE_AMD";
        default: return std::string("UNKNOWN_VkColorSpaceKHR_value") + std::to_string(value);
    }
}
void DumpVkColorSpaceKHR(Printer &p, std::string name, VkColorSpaceKHR value) {
    if (p.Type() == OutputType::json)
        p.PrintKeyString(name, std::string("VK_") + VkColorSpaceKHRString(value));
    else
        p.PrintKeyString(name, VkColorSpaceKHRString(value));
}
std::string VkDriverIdString(VkDriverId value) {
    switch (value) {
        case (VK_DRIVER_ID_AMD_PROPRIETARY): return "DRIVER_ID_AMD_PROPRIETARY";
        case (VK_DRIVER_ID_AMD_OPEN_SOURCE): return "DRIVER_ID_AMD_OPEN_SOURCE";
        case (VK_DRIVER_ID_MESA_RADV): return "DRIVER_ID_MESA_RADV";
        case (VK_DRIVER_ID_NVIDIA_PROPRIETARY): return "DRIVER_ID_NVIDIA_PROPRIETARY";
        case (VK_DRIVER_ID_INTEL_PROPRIETARY_WINDOWS): return "DRIVER_ID_INTEL_PROPRIETARY_WINDOWS";
        case (VK_DRIVER_ID_INTEL_OPEN_SOURCE_MESA): return "DRIVER_ID_INTEL_OPEN_SOURCE_MESA";
        case (VK_DRIVER_ID_IMAGINATION_PROPRIETARY): return "DRIVER_ID_IMAGINATION_PROPRIETARY";
        case (VK_DRIVER_ID_QUALCOMM_PROPRIETARY): return "DRIVER_ID_QUALCOMM_PROPRIETARY";
        case (VK_DRIVER_ID_ARM_PROPRIETARY): return "DRIVER_ID_ARM_PROPRIETARY";
        case (VK_DRIVER_ID_GOOGLE_SWIFTSHADER): return "DRIVER_ID_GOOGLE_SWIFTSHADER";
        case (VK_DRIVER_ID_GGP_PROPRIETARY): return "DRIVER_ID_GGP_PROPRIETARY";
        case (VK_DRIVER_ID_BROADCOM_PROPRIETARY): return "DRIVER_ID_BROADCOM_PROPRIETARY";
        case (VK_DRIVER_ID_MESA_LLVMPIPE): return "DRIVER_ID_MESA_LLVMPIPE";
        case (VK_DRIVER_ID_MOLTENVK): return "DRIVER_ID_MOLTENVK";
        case (VK_DRIVER_ID_COREAVI_PROPRIETARY): return "DRIVER_ID_COREAVI_PROPRIETARY";
        case (VK_DRIVER_ID_JUICE_PROPRIETARY): return "DRIVER_ID_JUICE_PROPRIETARY";
        case (VK_DRIVER_ID_VERISILICON_PROPRIETARY): return "DRIVER_ID_VERISILICON_PROPRIETARY";
        case (VK_DRIVER_ID_MESA_TURNIP): return "DRIVER_ID_MESA_TURNIP";
        case (VK_DRIVER_ID_MESA_V3DV): return "DRIVER_ID_MESA_V3DV";
        case (VK_DRIVER_ID_MESA_PANVK): return "DRIVER_ID_MESA_PANVK";
        case (VK_DRIVER_ID_SAMSUNG_PROPRIETARY): return "DRIVER_ID_SAMSUNG_PROPRIETARY";
        case (VK_DRIVER_ID_MESA_VENUS): return "DRIVER_ID_MESA_VENUS";
        case (VK_DRIVER_ID_MESA_DOZEN): return "DRIVER_ID_MESA_DOZEN";
        case (VK_DRIVER_ID_MESA_NVK): return "DRIVER_ID_MESA_NVK";
        case (VK_DRIVER_ID_IMAGINATION_OPEN_SOURCE_MESA): return "DRIVER_ID_IMAGINATION_OPEN_SOURCE_MESA";
        case (VK_DRIVER_ID_MESA_AGXV): return "DRIVER_ID_MESA_AGXV";
        case (VK_DRIVER_ID_RESERVED_27): return "DRIVER_ID_RESERVED_27";
        default: return std::string("UNKNOWN_VkDriverId_value") + std::to_string(value);
    }
}
void DumpVkDriverId(Printer &p, std::string name, VkDriverId value) {
    if (p.Type() == OutputType::json)
        p.PrintKeyString(name, std::string("VK_") + VkDriverIdString(value));
    else
        p.PrintKeyString(name, VkDriverIdString(value));
}
std::string VkFormatString(VkFormat value) {
    switch (value) {
        case (VK_FORMAT_UNDEFINED): return "FORMAT_UNDEFINED";
        case (VK_FORMAT_R4G4_UNORM_PACK8): return "FORMAT_R4G4_UNORM_PACK8";
        case (VK_FORMAT_R4G4B4A4_UNORM_PACK16): return "FORMAT_R4G4B4A4_UNORM_PACK16";
        case (VK_FORMAT_B4G4R4A4_UNORM_PACK16): return "FORMAT_B4G4R4A4_UNORM_PACK16";
        case (VK_FORMAT_R5G6B5_UNORM_PACK16): return "FORMAT_R5G6B5_UNORM_PACK16";
        case (VK_FORMAT_B5G6R5_UNORM_PACK16): return "FORMAT_B5G6R5_UNORM_PACK16";
        case (VK_FORMAT_R5G5B5A1_UNORM_PACK16): return "FORMAT_R5G5B5A1_UNORM_PACK16";
        case (VK_FORMAT_B5G5R5A1_UNORM_PACK16): return "FORMAT_B5G5R5A1_UNORM_PACK16";
        case (VK_FORMAT_A1R5G5B5_UNORM_PACK16): return "FORMAT_A1R5G5B5_UNORM_PACK16";
        case (VK_FORMAT_R8_UNORM): return "FORMAT_R8_UNORM";
        case (VK_FORMAT_R8_SNORM): return "FORMAT_R8_SNORM";
        case (VK_FORMAT_R8_USCALED): return "FORMAT_R8_USCALED";
        case (VK_FORMAT_R8_SSCALED): return "FORMAT_R8_SSCALED";
        case (VK_FORMAT_R8_UINT): return "FORMAT_R8_UINT";
        case (VK_FORMAT_R8_SINT): return "FORMAT_R8_SINT";
        case (VK_FORMAT_R8_SRGB): return "FORMAT_R8_SRGB";
        case (VK_FORMAT_R8G8_UNORM): return "FORMAT_R8G8_UNORM";
        case (VK_FORMAT_R8G8_SNORM): return "FORMAT_R8G8_SNORM";
        case (VK_FORMAT_R8G8_USCALED): return "FORMAT_R8G8_USCALED";
        case (VK_FORMAT_R8G8_SSCALED): return "FORMAT_R8G8_SSCALED";
        case (VK_FORMAT_R8G8_UINT): return "FORMAT_R8G8_UINT";
        case (VK_FORMAT_R8G8_SINT): return "FORMAT_R8G8_SINT";
        case (VK_FORMAT_R8G8_SRGB): return "FORMAT_R8G8_SRGB";
        case (VK_FORMAT_R8G8B8_UNORM): return "FORMAT_R8G8B8_UNORM";
        case (VK_FORMAT_R8G8B8_SNORM): return "FORMAT_R8G8B8_SNORM";
        case (VK_FORMAT_R8G8B8_USCALED): return "FORMAT_R8G8B8_USCALED";
        case (VK_FORMAT_R8G8B8_SSCALED): return "FORMAT_R8G8B8_SSCALED";
        case (VK_FORMAT_R8G8B8_UINT): return "FORMAT_R8G8B8_UINT";
        case (VK_FORMAT_R8G8B8_SINT): return "FORMAT_R8G8B8_SINT";
        case (VK_FORMAT_R8G8B8_SRGB): return "FORMAT_R8G8B8_SRGB";
        case (VK_FORMAT_B8G8R8_UNORM): return "FORMAT_B8G8R8_UNORM";
        case (VK_FORMAT_B8G8R8_SNORM): return "FORMAT_B8G8R8_SNORM";
        case (VK_FORMAT_B8G8R8_USCALED): return "FORMAT_B8G8R8_USCALED";
        case (VK_FORMAT_B8G8R8_SSCALED): return "FORMAT_B8G8R8_SSCALED";
        case (VK_FORMAT_B8G8R8_UINT): return "FORMAT_B8G8R8_UINT";
        case (VK_FORMAT_B8G8R8_SINT): return "FORMAT_B8G8R8_SINT";
        case (VK_FORMAT_B8G8R8_SRGB): return "FORMAT_B8G8R8_SRGB";
        case (VK_FORMAT_R8G8B8A8_UNORM): return "FORMAT_R8G8B8A8_UNORM";
        case (VK_FORMAT_R8G8B8A8_SNORM): return "FORMAT_R8G8B8A8_SNORM";
        case (VK_FORMAT_R8G8B8A8_USCALED): return "FORMAT_R8G8B8A8_USCALED";
        case (VK_FORMAT_R8G8B8A8_SSCALED): return "FORMAT_R8G8B8A8_SSCALED";
        case (VK_FORMAT_R8G8B8A8_UINT): return "FORMAT_R8G8B8A8_UINT";
        case (VK_FORMAT_R8G8B8A8_SINT): return "FORMAT_R8G8B8A8_SINT";
        case (VK_FORMAT_R8G8B8A8_SRGB): return "FORMAT_R8G8B8A8_SRGB";
        case (VK_FORMAT_B8G8R8A8_UNORM): return "FORMAT_B8G8R8A8_UNORM";
        case (VK_FORMAT_B8G8R8A8_SNORM): return "FORMAT_B8G8R8A8_SNORM";
        case (VK_FORMAT_B8G8R8A8_USCALED): return "FORMAT_B8G8R8A8_USCALED";
        case (VK_FORMAT_B8G8R8A8_SSCALED): return "FORMAT_B8G8R8A8_SSCALED";
        case (VK_FORMAT_B8G8R8A8_UINT): return "FORMAT_B8G8R8A8_UINT";
        case (VK_FORMAT_B8G8R8A8_SINT): return "FORMAT_B8G8R8A8_SINT";
        case (VK_FORMAT_B8G8R8A8_SRGB): return "FORMAT_B8G8R8A8_SRGB";
        case (VK_FORMAT_A8B8G8R8_UNORM_PACK32): return "FORMAT_A8B8G8R8_UNORM_PACK32";
        case (VK_FORMAT_A8B8G8R8_SNORM_PACK32): return "FORMAT_A8B8G8R8_SNORM_PACK32";
        case (VK_FORMAT_A8B8G8R8_USCALED_PACK32): return "FORMAT_A8B8G8R8_USCALED_PACK32";
        case (VK_FORMAT_A8B8G8R8_SSCALED_PACK32): return "FORMAT_A8B8G8R8_SSCALED_PACK32";
        case (VK_FORMAT_A8B8G8R8_UINT_PACK32): return "FORMAT_A8B8G8R8_UINT_PACK32";
        case (VK_FORMAT_A8B8G8R8_SINT_PACK32): return "FORMAT_A8B8G8R8_SINT_PACK32";
        case (VK_FORMAT_A8B8G8R8_SRGB_PACK32): return "FORMAT_A8B8G8R8_SRGB_PACK32";
        case (VK_FORMAT_A2R10G10B10_UNORM_PACK32): return "FORMAT_A2R10G10B10_UNORM_PACK32";
        case (VK_FORMAT_A2R10G10B10_SNORM_PACK32): return "FORMAT_A2R10G10B10_SNORM_PACK32";
        case (VK_FORMAT_A2R10G10B10_USCALED_PACK32): return "FORMAT_A2R10G10B10_USCALED_PACK32";
        case (VK_FORMAT_A2R10G10B10_SSCALED_PACK32): return "FORMAT_A2R10G10B10_SSCALED_PACK32";
        case (VK_FORMAT_A2R10G10B10_UINT_PACK32): return "FORMAT_A2R10G10B10_UINT_PACK32";
        case (VK_FORMAT_A2R10G10B10_SINT_PACK32): return "FORMAT_A2R10G10B10_SINT_PACK32";
        case (VK_FORMAT_A2B10G10R10_UNORM_PACK32): return "FORMAT_A2B10G10R10_UNORM_PACK32";
        case (VK_FORMAT_A2B10G10R10_SNORM_PACK32): return "FORMAT_A2B10G10R10_SNORM_PACK32";
        case (VK_FORMAT_A2B10G10R10_USCALED_PACK32): return "FORMAT_A2B10G10R10_USCALED_PACK32";
        case (VK_FORMAT_A2B10G10R10_SSCALED_PACK32): return "FORMAT_A2B10G10R10_SSCALED_PACK32";
        case (VK_FORMAT_A2B10G10R10_UINT_PACK32): return "FORMAT_A2B10G10R10_UINT_PACK32";
        case (VK_FORMAT_A2B10G10R10_SINT_PACK32): return "FORMAT_A2B10G10R10_SINT_PACK32";
        case (VK_FORMAT_R16_UNORM): return "FORMAT_R16_UNORM";
        case (VK_FORMAT_R16_SNORM): return "FORMAT_R16_SNORM";
        case (VK_FORMAT_R16_USCALED): return "FORMAT_R16_USCALED";
        case (VK_FORMAT_R16_SSCALED): return "FORMAT_R16_SSCALED";
        case (VK_FORMAT_R16_UINT): return "FORMAT_R16_UINT";
        case (VK_FORMAT_R16_SINT): return "FORMAT_R16_SINT";
        case (VK_FORMAT_R16_SFLOAT): return "FORMAT_R16_SFLOAT";
        case (VK_FORMAT_R16G16_UNORM): return "FORMAT_R16G16_UNORM";
        case (VK_FORMAT_R16G16_SNORM): return "FORMAT_R16G16_SNORM";
        case (VK_FORMAT_R16G16_USCALED): return "FORMAT_R16G16_USCALED";
        case (VK_FORMAT_R16G16_SSCALED): return "FORMAT_R16G16_SSCALED";
        case (VK_FORMAT_R16G16_UINT): return "FORMAT_R16G16_UINT";
        case (VK_FORMAT_R16G16_SINT): return "FORMAT_R16G16_SINT";
        case (VK_FORMAT_R16G16_SFLOAT): return "FORMAT_R16G16_SFLOAT";
        case (VK_FORMAT_R16G16B16_UNORM): return "FORMAT_R16G16B16_UNORM";
        case (VK_FORMAT_R16G16B16_SNORM): return "FORMAT_R16G16B16_SNORM";
        case (VK_FORMAT_R16G16B16_USCALED): return "FORMAT_R16G16B16_USCALED";
        case (VK_FORMAT_R16G16B16_SSCALED): return "FORMAT_R16G16B16_SSCALED";
        case (VK_FORMAT_R16G16B16_UINT): return "FORMAT_R16G16B16_UINT";
        case (VK_FORMAT_R16G16B16_SINT): return "FORMAT_R16G16B16_SINT";
        case (VK_FORMAT_R16G16B16_SFLOAT): return "FORMAT_R16G16B16_SFLOAT";
        case (VK_FORMAT_R16G16B16A16_UNORM): return "FORMAT_R16G16B16A16_UNORM";
        case (VK_FORMAT_R16G16B16A16_SNORM): return "FORMAT_R16G16B16A16_SNORM";
        case (VK_FORMAT_R16G16B16A16_USCALED): return "FORMAT_R16G16B16A16_USCALED";
        case (VK_FORMAT_R16G16B16A16_SSCALED): return "FORMAT_R16G16B16A16_SSCALED";
        case (VK_FORMAT_R16G16B16A16_UINT): return "FORMAT_R16G16B16A16_UINT";
        case (VK_FORMAT_R16G16B16A16_SINT): return "FORMAT_R16G16B16A16_SINT";
        case (VK_FORMAT_R16G16B16A16_SFLOAT): return "FORMAT_R16G16B16A16_SFLOAT";
        case (VK_FORMAT_R32_UINT): return "FORMAT_R32_UINT";
        case (VK_FORMAT_R32_SINT): return "FORMAT_R32_SINT";
        case (VK_FORMAT_R32_SFLOAT): return "FORMAT_R32_SFLOAT";
        case (VK_FORMAT_R32G32_UINT): return "FORMAT_R32G32_UINT";
        case (VK_FORMAT_R32G32_SINT): return "FORMAT_R32G32_SINT";
        case (VK_FORMAT_R32G32_SFLOAT): return "FORMAT_R32G32_SFLOAT";
        case (VK_FORMAT_R32G32B32_UINT): return "FORMAT_R32G32B32_UINT";
        case (VK_FORMAT_R32G32B32_SINT): return "FORMAT_R32G32B32_SINT";
        case (VK_FORMAT_R32G32B32_SFLOAT): return "FORMAT_R32G32B32_SFLOAT";
        case (VK_FORMAT_R32G32B32A32_UINT): return "FORMAT_R32G32B32A32_UINT";
        case (VK_FORMAT_R32G32B32A32_SINT): return "FORMAT_R32G32B32A32_SINT";
        case (VK_FORMAT_R32G32B32A32_SFLOAT): return "FORMAT_R32G32B32A32_SFLOAT";
        case (VK_FORMAT_R64_UINT): return "FORMAT_R64_UINT";
        case (VK_FORMAT_R64_SINT): return "FORMAT_R64_SINT";
        case (VK_FORMAT_R64_SFLOAT): return "FORMAT_R64_SFLOAT";
        case (VK_FORMAT_R64G64_UINT): return "FORMAT_R64G64_UINT";
        case (VK_FORMAT_R64G64_SINT): return "FORMAT_R64G64_SINT";
        case (VK_FORMAT_R64G64_SFLOAT): return "FORMAT_R64G64_SFLOAT";
        case (VK_FORMAT_R64G64B64_UINT): return "FORMAT_R64G64B64_UINT";
        case (VK_FORMAT_R64G64B64_SINT): return "FORMAT_R64G64B64_SINT";
        case (VK_FORMAT_R64G64B64_SFLOAT): return "FORMAT_R64G64B64_SFLOAT";
        case (VK_FORMAT_R64G64B64A64_UINT): return "FORMAT_R64G64B64A64_UINT";
        case (VK_FORMAT_R64G64B64A64_SINT): return "FORMAT_R64G64B64A64_SINT";
        case (VK_FORMAT_R64G64B64A64_SFLOAT): return "FORMAT_R64G64B64A64_SFLOAT";
        case (VK_FORMAT_B10G11R11_UFLOAT_PACK32): return "FORMAT_B10G11R11_UFLOAT_PACK32";
        case (VK_FORMAT_E5B9G9R9_UFLOAT_PACK32): return "FORMAT_E5B9G9R9_UFLOAT_PACK32";
        case (VK_FORMAT_D16_UNORM): return "FORMAT_D16_UNORM";
        case (VK_FORMAT_X8_D24_UNORM_PACK32): return "FORMAT_X8_D24_UNORM_PACK32";
        case (VK_FORMAT_D32_SFLOAT): return "FORMAT_D32_SFLOAT";
        case (VK_FORMAT_S8_UINT): return "FORMAT_S8_UINT";
        case (VK_FORMAT_D16_UNORM_S8_UINT): return "FORMAT_D16_UNORM_S8_UINT";
        case (VK_FORMAT_D24_UNORM_S8_UINT): return "FORMAT_D24_UNORM_S8_UINT";
        case (VK_FORMAT_D32_SFLOAT_S8_UINT): return "FORMAT_D32_SFLOAT_S8_UINT";
        case (VK_FORMAT_BC1_RGB_UNORM_BLOCK): return "FORMAT_BC1_RGB_UNORM_BLOCK";
        case (VK_FORMAT_BC1_RGB_SRGB_BLOCK): return "FORMAT_BC1_RGB_SRGB_BLOCK";
        case (VK_FORMAT_BC1_RGBA_UNORM_BLOCK): return "FORMAT_BC1_RGBA_UNORM_BLOCK";
        case (VK_FORMAT_BC1_RGBA_SRGB_BLOCK): return "FORMAT_BC1_RGBA_SRGB_BLOCK";
        case (VK_FORMAT_BC2_UNORM_BLOCK): return "FORMAT_BC2_UNORM_BLOCK";
        case (VK_FORMAT_BC2_SRGB_BLOCK): return "FORMAT_BC2_SRGB_BLOCK";
        case (VK_FORMAT_BC3_UNORM_BLOCK): return "FORMAT_BC3_UNORM_BLOCK";
        case (VK_FORMAT_BC3_SRGB_BLOCK): return "FORMAT_BC3_SRGB_BLOCK";
        case (VK_FORMAT_BC4_UNORM_BLOCK): return "FORMAT_BC4_UNORM_BLOCK";
        case (VK_FORMAT_BC4_SNORM_BLOCK): return "FORMAT_BC4_SNORM_BLOCK";
        case (VK_FORMAT_BC5_UNORM_BLOCK): return "FORMAT_BC5_UNORM_BLOCK";
        case (VK_FORMAT_BC5_SNORM_BLOCK): return "FORMAT_BC5_SNORM_BLOCK";
        case (VK_FORMAT_BC6H_UFLOAT_BLOCK): return "FORMAT_BC6H_UFLOAT_BLOCK";
        case (VK_FORMAT_BC6H_SFLOAT_BLOCK): return "FORMAT_BC6H_SFLOAT_BLOCK";
        case (VK_FORMAT_BC7_UNORM_BLOCK): return "FORMAT_BC7_UNORM_BLOCK";
        case (VK_FORMAT_BC7_SRGB_BLOCK): return "FORMAT_BC7_SRGB_BLOCK";
        case (VK_FORMAT_ETC2_R8G8B8_UNORM_BLOCK): return "FORMAT_ETC2_R8G8B8_UNORM_BLOCK";
        case (VK_FORMAT_ETC2_R8G8B8_SRGB_BLOCK): return "FORMAT_ETC2_R8G8B8_SRGB_BLOCK";
        case (VK_FORMAT_ETC2_R8G8B8A1_UNORM_BLOCK): return "FORMAT_ETC2_R8G8B8A1_UNORM_BLOCK";
        case (VK_FORMAT_ETC2_R8G8B8A1_SRGB_BLOCK): return "FORMAT_ETC2_R8G8B8A1_SRGB_BLOCK";
        case (VK_FORMAT_ETC2_R8G8B8A8_UNORM_BLOCK): return "FORMAT_ETC2_R8G8B8A8_UNORM_BLOCK";
        case (VK_FORMAT_ETC2_R8G8B8A8_SRGB_BLOCK): return "FORMAT_ETC2_R8G8B8A8_SRGB_BLOCK";
        case (VK_FORMAT_EAC_R11_UNORM_BLOCK): return "FORMAT_EAC_R11_UNORM_BLOCK";
        case (VK_FORMAT_EAC_R11_SNORM_BLOCK): return "FORMAT_EAC_R11_SNORM_BLOCK";
        case (VK_FORMAT_EAC_R11G11_UNORM_BLOCK): return "FORMAT_EAC_R11G11_UNORM_BLOCK";
        case (VK_FORMAT_EAC_R11G11_SNORM_BLOCK): return "FORMAT_EAC_R11G11_SNORM_BLOCK";
        case (VK_FORMAT_ASTC_4x4_UNORM_BLOCK): return "FORMAT_ASTC_4x4_UNORM_BLOCK";
        case (VK_FORMAT_ASTC_4x4_SRGB_BLOCK): return "FORMAT_ASTC_4x4_SRGB_BLOCK";
        case (VK_FORMAT_ASTC_5x4_UNORM_BLOCK): return "FORMAT_ASTC_5x4_UNORM_BLOCK";
        case (VK_FORMAT_ASTC_5x4_SRGB_BLOCK): return "FORMAT_ASTC_5x4_SRGB_BLOCK";
        case (VK_FORMAT_ASTC_5x5_UNORM_BLOCK): return "FORMAT_ASTC_5x5_UNORM_BLOCK";
        case (VK_FORMAT_ASTC_5x5_SRGB_BLOCK): return "FORMAT_ASTC_5x5_SRGB_BLOCK";
        case (VK_FORMAT_ASTC_6x5_UNORM_BLOCK): return "FORMAT_ASTC_6x5_UNORM_BLOCK";
        case (VK_FORMAT_ASTC_6x5_SRGB_BLOCK): return "FORMAT_ASTC_6x5_SRGB_BLOCK";
        case (VK_FORMAT_ASTC_6x6_UNORM_BLOCK): return "FORMAT_ASTC_6x6_UNORM_BLOCK";
        case (VK_FORMAT_ASTC_6x6_SRGB_BLOCK): return "FORMAT_ASTC_6x6_SRGB_BLOCK";
        case (VK_FORMAT_ASTC_8x5_UNORM_BLOCK): return "FORMAT_ASTC_8x5_UNORM_BLOCK";
        case (VK_FORMAT_ASTC_8x5_SRGB_BLOCK): return "FORMAT_ASTC_8x5_SRGB_BLOCK";
        case (VK_FORMAT_ASTC_8x6_UNORM_BLOCK): return "FORMAT_ASTC_8x6_UNORM_BLOCK";
        case (VK_FORMAT_ASTC_8x6_SRGB_BLOCK): return "FORMAT_ASTC_8x6_SRGB_BLOCK";
        case (VK_FORMAT_ASTC_8x8_UNORM_BLOCK): return "FORMAT_ASTC_8x8_UNORM_BLOCK";
        case (VK_FORMAT_ASTC_8x8_SRGB_BLOCK): return "FORMAT_ASTC_8x8_SRGB_BLOCK";
        case (VK_FORMAT_ASTC_10x5_UNORM_BLOCK): return "FORMAT_ASTC_10x5_UNORM_BLOCK";
        case (VK_FORMAT_ASTC_10x5_SRGB_BLOCK): return "FORMAT_ASTC_10x5_SRGB_BLOCK";
        case (VK_FORMAT_ASTC_10x6_UNORM_BLOCK): return "FORMAT_ASTC_10x6_UNORM_BLOCK";
        case (VK_FORMAT_ASTC_10x6_SRGB_BLOCK): return "FORMAT_ASTC_10x6_SRGB_BLOCK";
        case (VK_FORMAT_ASTC_10x8_UNORM_BLOCK): return "FORMAT_ASTC_10x8_UNORM_BLOCK";
        case (VK_FORMAT_ASTC_10x8_SRGB_BLOCK): return "FORMAT_ASTC_10x8_SRGB_BLOCK";
        case (VK_FORMAT_ASTC_10x10_UNORM_BLOCK): return "FORMAT_ASTC_10x10_UNORM_BLOCK";
        case (VK_FORMAT_ASTC_10x10_SRGB_BLOCK): return "FORMAT_ASTC_10x10_SRGB_BLOCK";
        case (VK_FORMAT_ASTC_12x10_UNORM_BLOCK): return "FORMAT_ASTC_12x10_UNORM_BLOCK";
        case (VK_FORMAT_ASTC_12x10_SRGB_BLOCK): return "FORMAT_ASTC_12x10_SRGB_BLOCK";
        case (VK_FORMAT_ASTC_12x12_UNORM_BLOCK): return "FORMAT_ASTC_12x12_UNORM_BLOCK";
        case (VK_FORMAT_ASTC_12x12_SRGB_BLOCK): return "FORMAT_ASTC_12x12_SRGB_BLOCK";
        case (VK_FORMAT_G8B8G8R8_422_UNORM): return "FORMAT_G8B8G8R8_422_UNORM";
        case (VK_FORMAT_B8G8R8G8_422_UNORM): return "FORMAT_B8G8R8G8_422_UNORM";
        case (VK_FORMAT_G8_B8_R8_3PLANE_420_UNORM): return "FORMAT_G8_B8_R8_3PLANE_420_UNORM";
        case (VK_FORMAT_G8_B8R8_2PLANE_420_UNORM): return "FORMAT_G8_B8R8_2PLANE_420_UNORM";
        case (VK_FORMAT_G8_B8_R8_3PLANE_422_UNORM): return "FORMAT_G8_B8_R8_3PLANE_422_UNORM";
        case (VK_FORMAT_G8_B8R8_2PLANE_422_UNORM): return "FORMAT_G8_B8R8_2PLANE_422_UNORM";
        case (VK_FORMAT_G8_B8_R8_3PLANE_444_UNORM): return "FORMAT_G8_B8_R8_3PLANE_444_UNORM";
        case (VK_FORMAT_R10X6_UNORM_PACK16): return "FORMAT_R10X6_UNORM_PACK16";
        case (VK_FORMAT_R10X6G10X6_UNORM_2PACK16): return "FORMAT_R10X6G10X6_UNORM_2PACK16";
        case (VK_FORMAT_R10X6G10X6B10X6A10X6_UNORM_4PACK16): return "FORMAT_R10X6G10X6B10X6A10X6_UNORM_4PACK16";
        case (VK_FORMAT_G10X6B10X6G10X6R10X6_422_UNORM_4PACK16): return "FORMAT_G10X6B10X6G10X6R10X6_422_UNORM_4PACK16";
        case (VK_FORMAT_B10X6G10X6R10X6G10X6_422_UNORM_4PACK16): return "FORMAT_B10X6G10X6R10X6G10X6_422_UNORM_4PACK16";
        case (VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_420_UNORM_3PACK16): return "FORMAT_G10X6_B10X6_R10X6_3PLANE_420_UNORM_3PACK16";
        case (VK_FORMAT_G10X6_B10X6R10X6_2PLANE_420_UNORM_3PACK16): return "FORMAT_G10X6_B10X6R10X6_2PLANE_420_UNORM_3PACK16";
        case (VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_422_UNORM_3PACK16): return "FORMAT_G10X6_B10X6_R10X6_3PLANE_422_UNORM_3PACK16";
        case (VK_FORMAT_G10X6_B10X6R10X6_2PLANE_422_UNORM_3PACK16): return "FORMAT_G10X6_B10X6R10X6_2PLANE_422_UNORM_3PACK16";
        case (VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_444_UNORM_3PACK16): return "FORMAT_G10X6_B10X6_R10X6_3PLANE_444_UNORM_3PACK16";
        case (VK_FORMAT_R12X4_UNORM_PACK16): return "FORMAT_R12X4_UNORM_PACK16";
        case (VK_FORMAT_R12X4G12X4_UNORM_2PACK16): return "FORMAT_R12X4G12X4_UNORM_2PACK16";
        case (VK_FORMAT_R12X4G12X4B12X4A12X4_UNORM_4PACK16): return "FORMAT_R12X4G12X4B12X4A12X4_UNORM_4PACK16";
        case (VK_FORMAT_G12X4B12X4G12X4R12X4_422_UNORM_4PACK16): return "FORMAT_G12X4B12X4G12X4R12X4_422_UNORM_4PACK16";
        case (VK_FORMAT_B12X4G12X4R12X4G12X4_422_UNORM_4PACK16): return "FORMAT_B12X4G12X4R12X4G12X4_422_UNORM_4PACK16";
        case (VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_420_UNORM_3PACK16): return "FORMAT_G12X4_B12X4_R12X4_3PLANE_420_UNORM_3PACK16";
        case (VK_FORMAT_G12X4_B12X4R12X4_2PLANE_420_UNORM_3PACK16): return "FORMAT_G12X4_B12X4R12X4_2PLANE_420_UNORM_3PACK16";
        case (VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_422_UNORM_3PACK16): return "FORMAT_G12X4_B12X4_R12X4_3PLANE_422_UNORM_3PACK16";
        case (VK_FORMAT_G12X4_B12X4R12X4_2PLANE_422_UNORM_3PACK16): return "FORMAT_G12X4_B12X4R12X4_2PLANE_422_UNORM_3PACK16";
        case (VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_444_UNORM_3PACK16): return "FORMAT_G12X4_B12X4_R12X4_3PLANE_444_UNORM_3PACK16";
        case (VK_FORMAT_G16B16G16R16_422_UNORM): return "FORMAT_G16B16G16R16_422_UNORM";
        case (VK_FORMAT_B16G16R16G16_422_UNORM): return "FORMAT_B16G16R16G16_422_UNORM";
        case (VK_FORMAT_G16_B16_R16_3PLANE_420_UNORM): return "FORMAT_G16_B16_R16_3PLANE_420_UNORM";
        case (VK_FORMAT_G16_B16R16_2PLANE_420_UNORM): return "FORMAT_G16_B16R16_2PLANE_420_UNORM";
        case (VK_FORMAT_G16_B16_R16_3PLANE_422_UNORM): return "FORMAT_G16_B16_R16_3PLANE_422_UNORM";
        case (VK_FORMAT_G16_B16R16_2PLANE_422_UNORM): return "FORMAT_G16_B16R16_2PLANE_422_UNORM";
        case (VK_FORMAT_G16_B16_R16_3PLANE_444_UNORM): return "FORMAT_G16_B16_R16_3PLANE_444_UNORM";
        case (VK_FORMAT_G8_B8R8_2PLANE_444_UNORM): return "FORMAT_G8_B8R8_2PLANE_444_UNORM";
        case (VK_FORMAT_G10X6_B10X6R10X6_2PLANE_444_UNORM_3PACK16): return "FORMAT_G10X6_B10X6R10X6_2PLANE_444_UNORM_3PACK16";
        case (VK_FORMAT_G12X4_B12X4R12X4_2PLANE_444_UNORM_3PACK16): return "FORMAT_G12X4_B12X4R12X4_2PLANE_444_UNORM_3PACK16";
        case (VK_FORMAT_G16_B16R16_2PLANE_444_UNORM): return "FORMAT_G16_B16R16_2PLANE_444_UNORM";
        case (VK_FORMAT_A4R4G4B4_UNORM_PACK16): return "FORMAT_A4R4G4B4_UNORM_PACK16";
        case (VK_FORMAT_A4B4G4R4_UNORM_PACK16): return "FORMAT_A4B4G4R4_UNORM_PACK16";
        case (VK_FORMAT_ASTC_4x4_SFLOAT_BLOCK): return "FORMAT_ASTC_4x4_SFLOAT_BLOCK";
        case (VK_FORMAT_ASTC_5x4_SFLOAT_BLOCK): return "FORMAT_ASTC_5x4_SFLOAT_BLOCK";
        case (VK_FORMAT_ASTC_5x5_SFLOAT_BLOCK): return "FORMAT_ASTC_5x5_SFLOAT_BLOCK";
        case (VK_FORMAT_ASTC_6x5_SFLOAT_BLOCK): return "FORMAT_ASTC_6x5_SFLOAT_BLOCK";
        case (VK_FORMAT_ASTC_6x6_SFLOAT_BLOCK): return "FORMAT_ASTC_6x6_SFLOAT_BLOCK";
        case (VK_FORMAT_ASTC_8x5_SFLOAT_BLOCK): return "FORMAT_ASTC_8x5_SFLOAT_BLOCK";
        case (VK_FORMAT_ASTC_8x6_SFLOAT_BLOCK): return "FORMAT_ASTC_8x6_SFLOAT_BLOCK";
        case (VK_FORMAT_ASTC_8x8_SFLOAT_BLOCK): return "FORMAT_ASTC_8x8_SFLOAT_BLOCK";
        case (VK_FORMAT_ASTC_10x5_SFLOAT_BLOCK): return "FORMAT_ASTC_10x5_SFLOAT_BLOCK";
        case (VK_FORMAT_ASTC_10x6_SFLOAT_BLOCK): return "FORMAT_ASTC_10x6_SFLOAT_BLOCK";
        case (VK_FORMAT_ASTC_10x8_SFLOAT_BLOCK): return "FORMAT_ASTC_10x8_SFLOAT_BLOCK";
        case (VK_FORMAT_ASTC_10x10_SFLOAT_BLOCK): return "FORMAT_ASTC_10x10_SFLOAT_BLOCK";
        case (VK_FORMAT_ASTC_12x10_SFLOAT_BLOCK): return "FORMAT_ASTC_12x10_SFLOAT_BLOCK";
        case (VK_FORMAT_ASTC_12x12_SFLOAT_BLOCK): return "FORMAT_ASTC_12x12_SFLOAT_BLOCK";
        case (VK_FORMAT_PVRTC1_2BPP_UNORM_BLOCK_IMG): return "FORMAT_PVRTC1_2BPP_UNORM_BLOCK_IMG";
        case (VK_FORMAT_PVRTC1_4BPP_UNORM_BLOCK_IMG): return "FORMAT_PVRTC1_4BPP_UNORM_BLOCK_IMG";
        case (VK_FORMAT_PVRTC2_2BPP_UNORM_BLOCK_IMG): return "FORMAT_PVRTC2_2BPP_UNORM_BLOCK_IMG";
        case (VK_FORMAT_PVRTC2_4BPP_UNORM_BLOCK_IMG): return "FORMAT_PVRTC2_4BPP_UNORM_BLOCK_IMG";
        case (VK_FORMAT_PVRTC1_2BPP_SRGB_BLOCK_IMG): return "FORMAT_PVRTC1_2BPP_SRGB_BLOCK_IMG";
        case (VK_FORMAT_PVRTC1_4BPP_SRGB_BLOCK_IMG): return "FORMAT_PVRTC1_4BPP_SRGB_BLOCK_IMG";
        case (VK_FORMAT_PVRTC2_2BPP_SRGB_BLOCK_IMG): return "FORMAT_PVRTC2_2BPP_SRGB_BLOCK_IMG";
        case (VK_FORMAT_PVRTC2_4BPP_SRGB_BLOCK_IMG): return "FORMAT_PVRTC2_4BPP_SRGB_BLOCK_IMG";
        case (VK_FORMAT_R16G16_SFIXED5_NV): return "FORMAT_R16G16_SFIXED5_NV";
        case (VK_FORMAT_A1B5G5R5_UNORM_PACK16_KHR): return "FORMAT_A1B5G5R5_UNORM_PACK16_KHR";
        case (VK_FORMAT_A8_UNORM_KHR): return "FORMAT_A8_UNORM_KHR";
        default: return std::string("UNKNOWN_VkFormat_value") + std::to_string(value);
    }
}
void DumpVkFormat(Printer &p, std::string name, VkFormat value) {
    if (p.Type() == OutputType::json)
        p.PrintKeyString(name, std::string("VK_") + VkFormatString(value));
    else
        p.PrintKeyString(name, VkFormatString(value));
}
std::string VkImageTilingString(VkImageTiling value) {
    switch (value) {
        case (VK_IMAGE_TILING_OPTIMAL): return "IMAGE_TILING_OPTIMAL";
        case (VK_IMAGE_TILING_LINEAR): return "IMAGE_TILING_LINEAR";
        case (VK_IMAGE_TILING_DRM_FORMAT_MODIFIER_EXT): return "IMAGE_TILING_DRM_FORMAT_MODIFIER_EXT";
        default: return std::string("UNKNOWN_VkImageTiling_value") + std::to_string(value);
    }
}
void DumpVkImageTiling(Printer &p, std::string name, VkImageTiling value) {
    if (p.Type() == OutputType::json)
        p.PrintKeyString(name, std::string("VK_") + VkImageTilingString(value));
    else
        p.PrintKeyString(name, VkImageTilingString(value));
}
std::string VkPhysicalDeviceTypeString(VkPhysicalDeviceType value) {
    switch (value) {
        case (VK_PHYSICAL_DEVICE_TYPE_OTHER): return "PHYSICAL_DEVICE_TYPE_OTHER";
        case (VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU): return "PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU";
        case (VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU): return "PHYSICAL_DEVICE_TYPE_DISCRETE_GPU";
        case (VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU): return "PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU";
        case (VK_PHYSICAL_DEVICE_TYPE_CPU): return "PHYSICAL_DEVICE_TYPE_CPU";
        default: return std::string("UNKNOWN_VkPhysicalDeviceType_value") + std::to_string(value);
    }
}
void DumpVkPhysicalDeviceType(Printer &p, std::string name, VkPhysicalDeviceType value) {
    if (p.Type() == OutputType::json)
        p.PrintKeyString(name, std::string("VK_") + VkPhysicalDeviceTypeString(value));
    else
        p.PrintKeyString(name, VkPhysicalDeviceTypeString(value));
}
std::string VkPointClippingBehaviorString(VkPointClippingBehavior value) {
    switch (value) {
        case (VK_POINT_CLIPPING_BEHAVIOR_ALL_CLIP_PLANES): return "POINT_CLIPPING_BEHAVIOR_ALL_CLIP_PLANES";
        case (VK_POINT_CLIPPING_BEHAVIOR_USER_CLIP_PLANES_ONLY): return "POINT_CLIPPING_BEHAVIOR_USER_CLIP_PLANES_ONLY";
        default: return std::string("UNKNOWN_VkPointClippingBehavior_value") + std::to_string(value);
    }
}
void DumpVkPointClippingBehavior(Printer &p, std::string name, VkPointClippingBehavior value) {
    if (p.Type() == OutputType::json)
        p.PrintKeyString(name, std::string("VK_") + VkPointClippingBehaviorString(value));
    else
        p.PrintKeyString(name, VkPointClippingBehaviorString(value));
}
std::string VkPresentModeKHRString(VkPresentModeKHR value) {
    switch (value) {
        case (VK_PRESENT_MODE_IMMEDIATE_KHR): return "PRESENT_MODE_IMMEDIATE_KHR";
        case (VK_PRESENT_MODE_MAILBOX_KHR): return "PRESENT_MODE_MAILBOX_KHR";
        case (VK_PRESENT_MODE_FIFO_KHR): return "PRESENT_MODE_FIFO_KHR";
        case (VK_PRESENT_MODE_FIFO_RELAXED_KHR): return "PRESENT_MODE_FIFO_RELAXED_KHR";
        case (VK_PRESENT_MODE_SHARED_DEMAND_REFRESH_KHR): return "PRESENT_MODE_SHARED_DEMAND_REFRESH_KHR";
        case (VK_PRESENT_MODE_SHARED_CONTINUOUS_REFRESH_KHR): return "PRESENT_MODE_SHARED_CONTINUOUS_REFRESH_KHR";
        default: return std::string("UNKNOWN_VkPresentModeKHR_value") + std::to_string(value);
    }
}
void DumpVkPresentModeKHR(Printer &p, std::string name, VkPresentModeKHR value) {
    if (p.Type() == OutputType::json)
        p.PrintKeyString(name, std::string("VK_") + VkPresentModeKHRString(value));
    else
        p.PrintKeyString(name, VkPresentModeKHRString(value));
}
std::string VkQueueGlobalPriorityKHRString(VkQueueGlobalPriorityKHR value) {
    switch (value) {
        case (VK_QUEUE_GLOBAL_PRIORITY_LOW_KHR): return "QUEUE_GLOBAL_PRIORITY_LOW_KHR";
        case (VK_QUEUE_GLOBAL_PRIORITY_MEDIUM_KHR): return "QUEUE_GLOBAL_PRIORITY_MEDIUM_KHR";
        case (VK_QUEUE_GLOBAL_PRIORITY_HIGH_KHR): return "QUEUE_GLOBAL_PRIORITY_HIGH_KHR";
        case (VK_QUEUE_GLOBAL_PRIORITY_REALTIME_KHR): return "QUEUE_GLOBAL_PRIORITY_REALTIME_KHR";
        default: return std::string("UNKNOWN_VkQueueGlobalPriorityKHR_value") + std::to_string(value);
    }
}
void DumpVkQueueGlobalPriorityKHR(Printer &p, std::string name, VkQueueGlobalPriorityKHR value) {
    if (p.Type() == OutputType::json)
        p.PrintKeyString(name, std::string("VK_") + VkQueueGlobalPriorityKHRString(value));
    else
        p.PrintKeyString(name, VkQueueGlobalPriorityKHRString(value));
}
std::string VkResultString(VkResult value) {
    switch (value) {
        case (VK_SUCCESS): return "SUCCESS";
        case (VK_NOT_READY): return "NOT_READY";
        case (VK_TIMEOUT): return "TIMEOUT";
        case (VK_EVENT_SET): return "EVENT_SET";
        case (VK_EVENT_RESET): return "EVENT_RESET";
        case (VK_INCOMPLETE): return "INCOMPLETE";
        case (VK_ERROR_OUT_OF_HOST_MEMORY): return "ERROR_OUT_OF_HOST_MEMORY";
        case (VK_ERROR_OUT_OF_DEVICE_MEMORY): return "ERROR_OUT_OF_DEVICE_MEMORY";
        case (VK_ERROR_INITIALIZATION_FAILED): return "ERROR_INITIALIZATION_FAILED";
        case (VK_ERROR_DEVICE_LOST): return "ERROR_DEVICE_LOST";
        case (VK_ERROR_MEMORY_MAP_FAILED): return "ERROR_MEMORY_MAP_FAILED";
        case (VK_ERROR_LAYER_NOT_PRESENT): return "ERROR_LAYER_NOT_PRESENT";
        case (VK_ERROR_EXTENSION_NOT_PRESENT): return "ERROR_EXTENSION_NOT_PRESENT";
        case (VK_ERROR_FEATURE_NOT_PRESENT): return "ERROR_FEATURE_NOT_PRESENT";
        case (VK_ERROR_INCOMPATIBLE_DRIVER): return "ERROR_INCOMPATIBLE_DRIVER";
        case (VK_ERROR_TOO_MANY_OBJECTS): return "ERROR_TOO_MANY_OBJECTS";
        case (VK_ERROR_FORMAT_NOT_SUPPORTED): return "ERROR_FORMAT_NOT_SUPPORTED";
        case (VK_ERROR_FRAGMENTED_POOL): return "ERROR_FRAGMENTED_POOL";
        case (VK_ERROR_UNKNOWN): return "ERROR_UNKNOWN";
        case (VK_ERROR_OUT_OF_POOL_MEMORY): return "ERROR_OUT_OF_POOL_MEMORY";
        case (VK_ERROR_INVALID_EXTERNAL_HANDLE): return "ERROR_INVALID_EXTERNAL_HANDLE";
        case (VK_ERROR_FRAGMENTATION): return "ERROR_FRAGMENTATION";
        case (VK_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS): return "ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS";
        case (VK_PIPELINE_COMPILE_REQUIRED): return "PIPELINE_COMPILE_REQUIRED";
        case (VK_ERROR_VALIDATION_FAILED): return "ERROR_VALIDATION_FAILED";
        case (VK_ERROR_INVALID_PIPELINE_CACHE_DATA): return "ERROR_INVALID_PIPELINE_CACHE_DATA";
        case (VK_ERROR_NO_PIPELINE_MATCH): return "ERROR_NO_PIPELINE_MATCH";
        case (VK_ERROR_SURFACE_LOST_KHR): return "ERROR_SURFACE_LOST_KHR";
        case (VK_ERROR_NATIVE_WINDOW_IN_USE_KHR): return "ERROR_NATIVE_WINDOW_IN_USE_KHR";
        case (VK_SUBOPTIMAL_KHR): return "SUBOPTIMAL_KHR";
        case (VK_ERROR_OUT_OF_DATE_KHR): return "ERROR_OUT_OF_DATE_KHR";
        case (VK_ERROR_INCOMPATIBLE_DISPLAY_KHR): return "ERROR_INCOMPATIBLE_DISPLAY_KHR";
        case (VK_ERROR_INVALID_SHADER_NV): return "ERROR_INVALID_SHADER_NV";
        case (VK_ERROR_IMAGE_USAGE_NOT_SUPPORTED_KHR): return "ERROR_IMAGE_USAGE_NOT_SUPPORTED_KHR";
        case (VK_ERROR_VIDEO_PICTURE_LAYOUT_NOT_SUPPORTED_KHR): return "ERROR_VIDEO_PICTURE_LAYOUT_NOT_SUPPORTED_KHR";
        case (VK_ERROR_VIDEO_PROFILE_OPERATION_NOT_SUPPORTED_KHR): return "ERROR_VIDEO_PROFILE_OPERATION_NOT_SUPPORTED_KHR";
        case (VK_ERROR_VIDEO_PROFILE_FORMAT_NOT_SUPPORTED_KHR): return "ERROR_VIDEO_PROFILE_FORMAT_NOT_SUPPORTED_KHR";
        case (VK_ERROR_VIDEO_PROFILE_CODEC_NOT_SUPPORTED_KHR): return "ERROR_VIDEO_PROFILE_CODEC_NOT_SUPPORTED_KHR";
        case (VK_ERROR_VIDEO_STD_VERSION_NOT_SUPPORTED_KHR): return "ERROR_VIDEO_STD_VERSION_NOT_SUPPORTED_KHR";
        case (VK_ERROR_INVALID_DRM_FORMAT_MODIFIER_PLANE_LAYOUT_EXT): return "ERROR_INVALID_DRM_FORMAT_MODIFIER_PLANE_LAYOUT_EXT";
        case (VK_ERROR_NOT_PERMITTED_KHR): return "ERROR_NOT_PERMITTED_KHR";
        case (VK_ERROR_FULL_SCREEN_EXCLUSIVE_MODE_LOST_EXT): return "ERROR_FULL_SCREEN_EXCLUSIVE_MODE_LOST_EXT";
        case (VK_THREAD_IDLE_KHR): return "THREAD_IDLE_KHR";
        case (VK_THREAD_DONE_KHR): return "THREAD_DONE_KHR";
        case (VK_OPERATION_DEFERRED_KHR): return "OPERATION_DEFERRED_KHR";
        case (VK_OPERATION_NOT_DEFERRED_KHR): return "OPERATION_NOT_DEFERRED_KHR";
        case (VK_ERROR_INVALID_VIDEO_STD_PARAMETERS_KHR): return "ERROR_INVALID_VIDEO_STD_PARAMETERS_KHR";
        case (VK_ERROR_COMPRESSION_EXHAUSTED_EXT): return "ERROR_COMPRESSION_EXHAUSTED_EXT";
        case (VK_INCOMPATIBLE_SHADER_BINARY_EXT): return "INCOMPATIBLE_SHADER_BINARY_EXT";
        default: return std::string("UNKNOWN_VkResult_value") + std::to_string(value);
    }
}
void DumpVkResult(Printer &p, std::string name, VkResult value) {
    if (p.Type() == OutputType::json)
        p.PrintKeyString(name, std::string("VK_") + VkResultString(value));
    else
        p.PrintKeyString(name, VkResultString(value));
}
std::string VkShaderFloatControlsIndependenceString(VkShaderFloatControlsIndependence value) {
    switch (value) {
        case (VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_32_BIT_ONLY): return "SHADER_FLOAT_CONTROLS_INDEPENDENCE_32_BIT_ONLY";
        case (VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_ALL): return "SHADER_FLOAT_CONTROLS_INDEPENDENCE_ALL";
        case (VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_NONE): return "SHADER_FLOAT_CONTROLS_INDEPENDENCE_NONE";
        default: return std::string("UNKNOWN_VkShaderFloatControlsIndependence_value") + std::to_string(value);
    }
}
void DumpVkShaderFloatControlsIndependence(Printer &p, std::string name, VkShaderFloatControlsIndependence value) {
    if (p.Type() == OutputType::json)
        p.PrintKeyString(name, std::string("VK_") + VkShaderFloatControlsIndependenceString(value));
    else
        p.PrintKeyString(name, VkShaderFloatControlsIndependenceString(value));
}
std::vector<const char *> VkCompositeAlphaFlagBitsKHRGetStrings(VkCompositeAlphaFlagBitsKHR value) {
    std::vector<const char *> strings;
    if (value == 0) { strings.push_back("None"); return strings; }
    if (VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR & value) strings.push_back("COMPOSITE_ALPHA_OPAQUE_BIT_KHR");
    if (VK_COMPOSITE_ALPHA_PRE_MULTIPLIED_BIT_KHR & value) strings.push_back("COMPOSITE_ALPHA_PRE_MULTIPLIED_BIT_KHR");
    if (VK_COMPOSITE_ALPHA_POST_MULTIPLIED_BIT_KHR & value) strings.push_back("COMPOSITE_ALPHA_POST_MULTIPLIED_BIT_KHR");
    if (VK_COMPOSITE_ALPHA_INHERIT_BIT_KHR & value) strings.push_back("COMPOSITE_ALPHA_INHERIT_BIT_KHR");
    return strings;
}
void DumpVkCompositeAlphaFlagsKHR(Printer &p, std::string name, VkCompositeAlphaFlagsKHR value) {
    if (static_cast<VkCompositeAlphaFlagBitsKHR>(value) == 0) {
        ArrayWrapper arr(p, name, 0);
        if (p.Type() != OutputType::json && p.Type() != OutputType::vkconfig_output)
            p.SetAsType().PrintString("None");
        return;
    }
    auto strings = VkCompositeAlphaFlagBitsKHRGetStrings(static_cast<VkCompositeAlphaFlagBitsKHR>(value));
    ArrayWrapper arr(p, name, strings.size());
    for(auto& str : strings){
        if (p.Type() == OutputType::json)
            p.SetAsType().PrintString(std::string("VK_") + str);
        else
            p.SetAsType().PrintString(str);
    }
}
void DumpVkCompositeAlphaFlagBitsKHR(Printer &p, std::string name, VkCompositeAlphaFlagBitsKHR value) {
    auto strings = VkCompositeAlphaFlagBitsKHRGetStrings(value);
    if (strings.size() > 0) {
        if (p.Type() == OutputType::json)
            p.PrintKeyString(name, std::string("VK_") + strings.at(0));
        else
            p.PrintKeyString(name, strings.at(0));
    }
}

std::vector<const char *> VkDeviceGroupPresentModeFlagBitsKHRGetStrings(VkDeviceGroupPresentModeFlagBitsKHR value) {
    std::vector<const char *> strings;
    if (value == 0) { strings.push_back("None"); return strings; }
    if (VK_DEVICE_GROUP_PRESENT_MODE_LOCAL_BIT_KHR & value) strings.push_back("DEVICE_GROUP_PRESENT_MODE_LOCAL_BIT_KHR");
    if (VK_DEVICE_GROUP_PRESENT_MODE_REMOTE_BIT_KHR & value) strings.push_back("DEVICE_GROUP_PRESENT_MODE_REMOTE_BIT_KHR");
    if (VK_DEVICE_GROUP_PRESENT_MODE_SUM_BIT_KHR & value) strings.push_back("DEVICE_GROUP_PRESENT_MODE_SUM_BIT_KHR");
    if (VK_DEVICE_GROUP_PRESENT_MODE_LOCAL_MULTI_DEVICE_BIT_KHR & value) strings.push_back("DEVICE_GROUP_PRESENT_MODE_LOCAL_MULTI_DEVICE_BIT_KHR");
    return strings;
}
void DumpVkDeviceGroupPresentModeFlagsKHR(Printer &p, std::string name, VkDeviceGroupPresentModeFlagsKHR value) {
    if (static_cast<VkDeviceGroupPresentModeFlagBitsKHR>(value) == 0) {
        ArrayWrapper arr(p, name, 0);
        if (p.Type() != OutputType::json && p.Type() != OutputType::vkconfig_output)
            p.SetAsType().PrintString("None");
        return;
    }
    auto strings = VkDeviceGroupPresentModeFlagBitsKHRGetStrings(static_cast<VkDeviceGroupPresentModeFlagBitsKHR>(value));
    ArrayWrapper arr(p, name, strings.size());
    for(auto& str : strings){
        if (p.Type() == OutputType::json)
            p.SetAsType().PrintString(std::string("VK_") + str);
        else
            p.SetAsType().PrintString(str);
    }
}
void DumpVkDeviceGroupPresentModeFlagBitsKHR(Printer &p, std::string name, VkDeviceGroupPresentModeFlagBitsKHR value) {
    auto strings = VkDeviceGroupPresentModeFlagBitsKHRGetStrings(value);
    if (strings.size() > 0) {
        if (p.Type() == OutputType::json)
            p.PrintKeyString(name, std::string("VK_") + strings.at(0));
        else
            p.PrintKeyString(name, strings.at(0));
    }
}

std::vector<const char *> VkFormatFeatureFlagBitsGetStrings(VkFormatFeatureFlagBits value) {
    std::vector<const char *> strings;
    if (value == 0) { strings.push_back("None"); return strings; }
    if (VK_FORMAT_FEATURE_SAMPLED_IMAGE_BIT & value) strings.push_back("FORMAT_FEATURE_SAMPLED_IMAGE_BIT");
    if (VK_FORMAT_FEATURE_STORAGE_IMAGE_BIT & value) strings.push_back("FORMAT_FEATURE_STORAGE_IMAGE_BIT");
    if (VK_FORMAT_FEATURE_STORAGE_IMAGE_ATOMIC_BIT & value) strings.push_back("FORMAT_FEATURE_STORAGE_IMAGE_ATOMIC_BIT");
    if (VK_FORMAT_FEATURE_UNIFORM_TEXEL_BUFFER_BIT & value) strings.push_back("FORMAT_FEATURE_UNIFORM_TEXEL_BUFFER_BIT");
    if (VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_BIT & value) strings.push_back("FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_BIT");
    if (VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_ATOMIC_BIT & value) strings.push_back("FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_ATOMIC_BIT");
    if (VK_FORMAT_FEATURE_VERTEX_BUFFER_BIT & value) strings.push_back("FORMAT_FEATURE_VERTEX_BUFFER_BIT");
    if (VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BIT & value) strings.push_back("FORMAT_FEATURE_COLOR_ATTACHMENT_BIT");
    if (VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BLEND_BIT & value) strings.push_back("FORMAT_FEATURE_COLOR_ATTACHMENT_BLEND_BIT");
    if (VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT & value) strings.push_back("FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT");
    if (VK_FORMAT_FEATURE_BLIT_SRC_BIT & value) strings.push_back("FORMAT_FEATURE_BLIT_SRC_BIT");
    if (VK_FORMAT_FEATURE_BLIT_DST_BIT & value) strings.push_back("FORMAT_FEATURE_BLIT_DST_BIT");
    if (VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_LINEAR_BIT & value) strings.push_back("FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_LINEAR_BIT");
    if (VK_FORMAT_FEATURE_TRANSFER_SRC_BIT & value) strings.push_back("FORMAT_FEATURE_TRANSFER_SRC_BIT");
    if (VK_FORMAT_FEATURE_TRANSFER_DST_BIT & value) strings.push_back("FORMAT_FEATURE_TRANSFER_DST_BIT");
    if (VK_FORMAT_FEATURE_MIDPOINT_CHROMA_SAMPLES_BIT & value) strings.push_back("FORMAT_FEATURE_MIDPOINT_CHROMA_SAMPLES_BIT");
    if (VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER_BIT & value) strings.push_back("FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER_BIT");
    if (VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_SEPARATE_RECONSTRUCTION_FILTER_BIT & value) strings.push_back("FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_SEPARATE_RECONSTRUCTION_FILTER_BIT");
    if (VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_BIT & value) strings.push_back("FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_BIT");
    if (VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_FORCEABLE_BIT & value) strings.push_back("FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_FORCEABLE_BIT");
    if (VK_FORMAT_FEATURE_DISJOINT_BIT & value) strings.push_back("FORMAT_FEATURE_DISJOINT_BIT");
    if (VK_FORMAT_FEATURE_COSITED_CHROMA_SAMPLES_BIT & value) strings.push_back("FORMAT_FEATURE_COSITED_CHROMA_SAMPLES_BIT");
    if (VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_MINMAX_BIT & value) strings.push_back("FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_MINMAX_BIT");
    if (VK_FORMAT_FEATURE_VIDEO_DECODE_OUTPUT_BIT_KHR & value) strings.push_back("FORMAT_FEATURE_VIDEO_DECODE_OUTPUT_BIT_KHR");
    if (VK_FORMAT_FEATURE_VIDEO_DECODE_DPB_BIT_KHR & value) strings.push_back("FORMAT_FEATURE_VIDEO_DECODE_DPB_BIT_KHR");
    if (VK_FORMAT_FEATURE_ACCELERATION_STRUCTURE_VERTEX_BUFFER_BIT_KHR & value) strings.push_back("FORMAT_FEATURE_ACCELERATION_STRUCTURE_VERTEX_BUFFER_BIT_KHR");
    if (VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_CUBIC_BIT_EXT & value) strings.push_back("FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_CUBIC_BIT_EXT");
    if (VK_FORMAT_FEATURE_FRAGMENT_DENSITY_MAP_BIT_EXT & value) strings.push_back("FORMAT_FEATURE_FRAGMENT_DENSITY_MAP_BIT_EXT");
    if (VK_FORMAT_FEATURE_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR & value) strings.push_back("FORMAT_FEATURE_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR");
    if (VK_FORMAT_FEATURE_VIDEO_ENCODE_INPUT_BIT_KHR & value) strings.push_back("FORMAT_FEATURE_VIDEO_ENCODE_INPUT_BIT_KHR");
    if (VK_FORMAT_FEATURE_VIDEO_ENCODE_DPB_BIT_KHR & value) strings.push_back("FORMAT_FEATURE_VIDEO_ENCODE_DPB_BIT_KHR");
    return strings;
}
void DumpVkFormatFeatureFlags(Printer &p, std::string name, VkFormatFeatureFlags value) {
    if (static_cast<VkFormatFeatureFlagBits>(value) == 0) {
        ArrayWrapper arr(p, name, 0);
        if (p.Type() != OutputType::json && p.Type() != OutputType::vkconfig_output)
            p.SetAsType().PrintString("None");
        return;
    }
    auto strings = VkFormatFeatureFlagBitsGetStrings(static_cast<VkFormatFeatureFlagBits>(value));
    ArrayWrapper arr(p, name, strings.size());
    for(auto& str : strings){
        if (p.Type() == OutputType::json)
            p.SetAsType().PrintString(std::string("VK_") + str);
        else
            p.SetAsType().PrintString(str);
    }
}
void DumpVkFormatFeatureFlagBits(Printer &p, std::string name, VkFormatFeatureFlagBits value) {
    auto strings = VkFormatFeatureFlagBitsGetStrings(value);
    if (strings.size() > 0) {
        if (p.Type() == OutputType::json)
            p.PrintKeyString(name, std::string("VK_") + strings.at(0));
        else
            p.PrintKeyString(name, strings.at(0));
    }
}

std::vector<const char *> VkFormatFeatureFlagBits2GetStrings(VkFormatFeatureFlagBits2 value) {
    std::vector<const char *> strings;
    if (value == 0) { strings.push_back("None"); return strings; }
    if (VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_BIT & value) strings.push_back("FORMAT_FEATURE_2_SAMPLED_IMAGE_BIT");
    if (VK_FORMAT_FEATURE_2_STORAGE_IMAGE_BIT & value) strings.push_back("FORMAT_FEATURE_2_STORAGE_IMAGE_BIT");
    if (VK_FORMAT_FEATURE_2_STORAGE_IMAGE_ATOMIC_BIT & value) strings.push_back("FORMAT_FEATURE_2_STORAGE_IMAGE_ATOMIC_BIT");
    if (VK_FORMAT_FEATURE_2_UNIFORM_TEXEL_BUFFER_BIT & value) strings.push_back("FORMAT_FEATURE_2_UNIFORM_TEXEL_BUFFER_BIT");
    if (VK_FORMAT_FEATURE_2_STORAGE_TEXEL_BUFFER_BIT & value) strings.push_back("FORMAT_FEATURE_2_STORAGE_TEXEL_BUFFER_BIT");
    if (VK_FORMAT_FEATURE_2_STORAGE_TEXEL_BUFFER_ATOMIC_BIT & value) strings.push_back("FORMAT_FEATURE_2_STORAGE_TEXEL_BUFFER_ATOMIC_BIT");
    if (VK_FORMAT_FEATURE_2_VERTEX_BUFFER_BIT & value) strings.push_back("FORMAT_FEATURE_2_VERTEX_BUFFER_BIT");
    if (VK_FORMAT_FEATURE_2_COLOR_ATTACHMENT_BIT & value) strings.push_back("FORMAT_FEATURE_2_COLOR_ATTACHMENT_BIT");
    if (VK_FORMAT_FEATURE_2_COLOR_ATTACHMENT_BLEND_BIT & value) strings.push_back("FORMAT_FEATURE_2_COLOR_ATTACHMENT_BLEND_BIT");
    if (VK_FORMAT_FEATURE_2_DEPTH_STENCIL_ATTACHMENT_BIT & value) strings.push_back("FORMAT_FEATURE_2_DEPTH_STENCIL_ATTACHMENT_BIT");
    if (VK_FORMAT_FEATURE_2_BLIT_SRC_BIT & value) strings.push_back("FORMAT_FEATURE_2_BLIT_SRC_BIT");
    if (VK_FORMAT_FEATURE_2_BLIT_DST_BIT & value) strings.push_back("FORMAT_FEATURE_2_BLIT_DST_BIT");
    if (VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_LINEAR_BIT & value) strings.push_back("FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_LINEAR_BIT");
    if (VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_CUBIC_BIT & value) strings.push_back("FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_CUBIC_BIT");
    if (VK_FORMAT_FEATURE_2_TRANSFER_SRC_BIT & value) strings.push_back("FORMAT_FEATURE_2_TRANSFER_SRC_BIT");
    if (VK_FORMAT_FEATURE_2_TRANSFER_DST_BIT & value) strings.push_back("FORMAT_FEATURE_2_TRANSFER_DST_BIT");
    if (VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_MINMAX_BIT & value) strings.push_back("FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_MINMAX_BIT");
    if (VK_FORMAT_FEATURE_2_MIDPOINT_CHROMA_SAMPLES_BIT & value) strings.push_back("FORMAT_FEATURE_2_MIDPOINT_CHROMA_SAMPLES_BIT");
    if (VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER_BIT & value) strings.push_back("FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER_BIT");
    if (VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_SEPARATE_RECONSTRUCTION_FILTER_BIT & value) strings.push_back("FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_SEPARATE_RECONSTRUCTION_FILTER_BIT");
    if (VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_BIT & value) strings.push_back("FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_BIT");
    if (VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_FORCEABLE_BIT & value) strings.push_back("FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_FORCEABLE_BIT");
    if (VK_FORMAT_FEATURE_2_DISJOINT_BIT & value) strings.push_back("FORMAT_FEATURE_2_DISJOINT_BIT");
    if (VK_FORMAT_FEATURE_2_COSITED_CHROMA_SAMPLES_BIT & value) strings.push_back("FORMAT_FEATURE_2_COSITED_CHROMA_SAMPLES_BIT");
    if (VK_FORMAT_FEATURE_2_STORAGE_READ_WITHOUT_FORMAT_BIT & value) strings.push_back("FORMAT_FEATURE_2_STORAGE_READ_WITHOUT_FORMAT_BIT");
    if (VK_FORMAT_FEATURE_2_STORAGE_WRITE_WITHOUT_FORMAT_BIT & value) strings.push_back("FORMAT_FEATURE_2_STORAGE_WRITE_WITHOUT_FORMAT_BIT");
    if (VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_DEPTH_COMPARISON_BIT & value) strings.push_back("FORMAT_FEATURE_2_SAMPLED_IMAGE_DEPTH_COMPARISON_BIT");
    if (VK_FORMAT_FEATURE_2_VIDEO_DECODE_OUTPUT_BIT_KHR & value) strings.push_back("FORMAT_FEATURE_2_VIDEO_DECODE_OUTPUT_BIT_KHR");
    if (VK_FORMAT_FEATURE_2_VIDEO_DECODE_DPB_BIT_KHR & value) strings.push_back("FORMAT_FEATURE_2_VIDEO_DECODE_DPB_BIT_KHR");
    if (VK_FORMAT_FEATURE_2_ACCELERATION_STRUCTURE_VERTEX_BUFFER_BIT_KHR & value) strings.push_back("FORMAT_FEATURE_2_ACCELERATION_STRUCTURE_VERTEX_BUFFER_BIT_KHR");
    if (VK_FORMAT_FEATURE_2_FRAGMENT_DENSITY_MAP_BIT_EXT & value) strings.push_back("FORMAT_FEATURE_2_FRAGMENT_DENSITY_MAP_BIT_EXT");
    if (VK_FORMAT_FEATURE_2_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR & value) strings.push_back("FORMAT_FEATURE_2_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR");
    if (VK_FORMAT_FEATURE_2_HOST_IMAGE_TRANSFER_BIT_EXT & value) strings.push_back("FORMAT_FEATURE_2_HOST_IMAGE_TRANSFER_BIT_EXT");
    if (VK_FORMAT_FEATURE_2_VIDEO_ENCODE_INPUT_BIT_KHR & value) strings.push_back("FORMAT_FEATURE_2_VIDEO_ENCODE_INPUT_BIT_KHR");
    if (VK_FORMAT_FEATURE_2_VIDEO_ENCODE_DPB_BIT_KHR & value) strings.push_back("FORMAT_FEATURE_2_VIDEO_ENCODE_DPB_BIT_KHR");
    if (VK_FORMAT_FEATURE_2_LINEAR_COLOR_ATTACHMENT_BIT_NV & value) strings.push_back("FORMAT_FEATURE_2_LINEAR_COLOR_ATTACHMENT_BIT_NV");
    if (VK_FORMAT_FEATURE_2_WEIGHT_IMAGE_BIT_QCOM & value) strings.push_back("FORMAT_FEATURE_2_WEIGHT_IMAGE_BIT_QCOM");
    if (VK_FORMAT_FEATURE_2_WEIGHT_SAMPLED_IMAGE_BIT_QCOM & value) strings.push_back("FORMAT_FEATURE_2_WEIGHT_SAMPLED_IMAGE_BIT_QCOM");
    if (VK_FORMAT_FEATURE_2_BLOCK_MATCHING_BIT_QCOM & value) strings.push_back("FORMAT_FEATURE_2_BLOCK_MATCHING_BIT_QCOM");
    if (VK_FORMAT_FEATURE_2_BOX_FILTER_SAMPLED_BIT_QCOM & value) strings.push_back("FORMAT_FEATURE_2_BOX_FILTER_SAMPLED_BIT_QCOM");
    if (VK_FORMAT_FEATURE_2_OPTICAL_FLOW_IMAGE_BIT_NV & value) strings.push_back("FORMAT_FEATURE_2_OPTICAL_FLOW_IMAGE_BIT_NV");
    if (VK_FORMAT_FEATURE_2_OPTICAL_FLOW_VECTOR_BIT_NV & value) strings.push_back("FORMAT_FEATURE_2_OPTICAL_FLOW_VECTOR_BIT_NV");
    if (VK_FORMAT_FEATURE_2_OPTICAL_FLOW_COST_BIT_NV & value) strings.push_back("FORMAT_FEATURE_2_OPTICAL_FLOW_COST_BIT_NV");
    return strings;
}
void DumpVkFormatFeatureFlags2(Printer &p, std::string name, VkFormatFeatureFlags2 value) {
    if (static_cast<VkFormatFeatureFlagBits2>(value) == 0) {
        ArrayWrapper arr(p, name, 0);
        if (p.Type() != OutputType::json && p.Type() != OutputType::vkconfig_output)
            p.SetAsType().PrintString("None");
        return;
    }
    auto strings = VkFormatFeatureFlagBits2GetStrings(static_cast<VkFormatFeatureFlagBits2>(value));
    ArrayWrapper arr(p, name, strings.size());
    for(auto& str : strings){
        if (p.Type() == OutputType::json)
            p.SetAsType().PrintString(std::string("VK_") + str);
        else
            p.SetAsType().PrintString(str);
    }
}
void DumpVkFormatFeatureFlagBits2(Printer &p, std::string name, VkFormatFeatureFlagBits2 value) {
    auto strings = VkFormatFeatureFlagBits2GetStrings(value);
    if (strings.size() > 0) {
        if (p.Type() == OutputType::json)
            p.PrintKeyString(name, std::string("VK_") + strings.at(0));
        else
            p.PrintKeyString(name, strings.at(0));
    }
}

std::vector<const char *> VkImageUsageFlagBitsGetStrings(VkImageUsageFlagBits value) {
    std::vector<const char *> strings;
    if (value == 0) { strings.push_back("None"); return strings; }
    if (VK_IMAGE_USAGE_TRANSFER_SRC_BIT & value) strings.push_back("IMAGE_USAGE_TRANSFER_SRC_BIT");
    if (VK_IMAGE_USAGE_TRANSFER_DST_BIT & value) strings.push_back("IMAGE_USAGE_TRANSFER_DST_BIT");
    if (VK_IMAGE_USAGE_SAMPLED_BIT & value) strings.push_back("IMAGE_USAGE_SAMPLED_BIT");
    if (VK_IMAGE_USAGE_STORAGE_BIT & value) strings.push_back("IMAGE_USAGE_STORAGE_BIT");
    if (VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT & value) strings.push_back("IMAGE_USAGE_COLOR_ATTACHMENT_BIT");
    if (VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT & value) strings.push_back("IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT");
    if (VK_IMAGE_USAGE_TRANSIENT_ATTACHMENT_BIT & value) strings.push_back("IMAGE_USAGE_TRANSIENT_ATTACHMENT_BIT");
    if (VK_IMAGE_USAGE_INPUT_ATTACHMENT_BIT & value) strings.push_back("IMAGE_USAGE_INPUT_ATTACHMENT_BIT");
    if (VK_IMAGE_USAGE_VIDEO_DECODE_DST_BIT_KHR & value) strings.push_back("IMAGE_USAGE_VIDEO_DECODE_DST_BIT_KHR");
    if (VK_IMAGE_USAGE_VIDEO_DECODE_SRC_BIT_KHR & value) strings.push_back("IMAGE_USAGE_VIDEO_DECODE_SRC_BIT_KHR");
    if (VK_IMAGE_USAGE_VIDEO_DECODE_DPB_BIT_KHR & value) strings.push_back("IMAGE_USAGE_VIDEO_DECODE_DPB_BIT_KHR");
    if (VK_IMAGE_USAGE_FRAGMENT_DENSITY_MAP_BIT_EXT & value) strings.push_back("IMAGE_USAGE_FRAGMENT_DENSITY_MAP_BIT_EXT");
    if (VK_IMAGE_USAGE_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR & value) strings.push_back("IMAGE_USAGE_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR");
    if (VK_IMAGE_USAGE_HOST_TRANSFER_BIT_EXT & value) strings.push_back("IMAGE_USAGE_HOST_TRANSFER_BIT_EXT");
    if (VK_IMAGE_USAGE_VIDEO_ENCODE_DST_BIT_KHR & value) strings.push_back("IMAGE_USAGE_VIDEO_ENCODE_DST_BIT_KHR");
    if (VK_IMAGE_USAGE_VIDEO_ENCODE_SRC_BIT_KHR & value) strings.push_back("IMAGE_USAGE_VIDEO_ENCODE_SRC_BIT_KHR");
    if (VK_IMAGE_USAGE_VIDEO_ENCODE_DPB_BIT_KHR & value) strings.push_back("IMAGE_USAGE_VIDEO_ENCODE_DPB_BIT_KHR");
    if (VK_IMAGE_USAGE_ATTACHMENT_FEEDBACK_LOOP_BIT_EXT & value) strings.push_back("IMAGE_USAGE_ATTACHMENT_FEEDBACK_LOOP_BIT_EXT");
    if (VK_IMAGE_USAGE_INVOCATION_MASK_BIT_HUAWEI & value) strings.push_back("IMAGE_USAGE_INVOCATION_MASK_BIT_HUAWEI");
    if (VK_IMAGE_USAGE_SAMPLE_WEIGHT_BIT_QCOM & value) strings.push_back("IMAGE_USAGE_SAMPLE_WEIGHT_BIT_QCOM");
    if (VK_IMAGE_USAGE_SAMPLE_BLOCK_MATCH_BIT_QCOM & value) strings.push_back("IMAGE_USAGE_SAMPLE_BLOCK_MATCH_BIT_QCOM");
    return strings;
}
void DumpVkImageUsageFlags(Printer &p, std::string name, VkImageUsageFlags value) {
    if (static_cast<VkImageUsageFlagBits>(value) == 0) {
        ArrayWrapper arr(p, name, 0);
        if (p.Type() != OutputType::json && p.Type() != OutputType::vkconfig_output)
            p.SetAsType().PrintString("None");
        return;
    }
    auto strings = VkImageUsageFlagBitsGetStrings(static_cast<VkImageUsageFlagBits>(value));
    ArrayWrapper arr(p, name, strings.size());
    for(auto& str : strings){
        if (p.Type() == OutputType::json)
            p.SetAsType().PrintString(std::string("VK_") + str);
        else
            p.SetAsType().PrintString(str);
    }
}
void DumpVkImageUsageFlagBits(Printer &p, std::string name, VkImageUsageFlagBits value) {
    auto strings = VkImageUsageFlagBitsGetStrings(value);
    if (strings.size() > 0) {
        if (p.Type() == OutputType::json)
            p.PrintKeyString(name, std::string("VK_") + strings.at(0));
        else
            p.PrintKeyString(name, strings.at(0));
    }
}

std::vector<const char *> VkMemoryHeapFlagBitsGetStrings(VkMemoryHeapFlagBits value) {
    std::vector<const char *> strings;
    if (value == 0) { strings.push_back("None"); return strings; }
    if (VK_MEMORY_HEAP_DEVICE_LOCAL_BIT & value) strings.push_back("MEMORY_HEAP_DEVICE_LOCAL_BIT");
    if (VK_MEMORY_HEAP_MULTI_INSTANCE_BIT & value) strings.push_back("MEMORY_HEAP_MULTI_INSTANCE_BIT");
    if (VK_MEMORY_HEAP_SEU_SAFE_BIT & value) strings.push_back("MEMORY_HEAP_SEU_SAFE_BIT");
    return strings;
}
void DumpVkMemoryHeapFlags(Printer &p, std::string name, VkMemoryHeapFlags value) {
    if (static_cast<VkMemoryHeapFlagBits>(value) == 0) {
        ArrayWrapper arr(p, name, 0);
        if (p.Type() != OutputType::json && p.Type() != OutputType::vkconfig_output)
            p.SetAsType().PrintString("None");
        return;
    }
    auto strings = VkMemoryHeapFlagBitsGetStrings(static_cast<VkMemoryHeapFlagBits>(value));
    ArrayWrapper arr(p, name, strings.size());
    for(auto& str : strings){
        if (p.Type() == OutputType::json)
            p.SetAsType().PrintString(std::string("VK_") + str);
        else
            p.SetAsType().PrintString(str);
    }
}
void DumpVkMemoryHeapFlagBits(Printer &p, std::string name, VkMemoryHeapFlagBits value) {
    auto strings = VkMemoryHeapFlagBitsGetStrings(value);
    if (strings.size() > 0) {
        if (p.Type() == OutputType::json)
            p.PrintKeyString(name, std::string("VK_") + strings.at(0));
        else
            p.PrintKeyString(name, strings.at(0));
    }
}

std::vector<const char *> VkMemoryPropertyFlagBitsGetStrings(VkMemoryPropertyFlagBits value) {
    std::vector<const char *> strings;
    if (value == 0) { strings.push_back("None"); return strings; }
    if (VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT & value) strings.push_back("MEMORY_PROPERTY_DEVICE_LOCAL_BIT");
    if (VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT & value) strings.push_back("MEMORY_PROPERTY_HOST_VISIBLE_BIT");
    if (VK_MEMORY_PROPERTY_HOST_COHERENT_BIT & value) strings.push_back("MEMORY_PROPERTY_HOST_COHERENT_BIT");
    if (VK_MEMORY_PROPERTY_HOST_CACHED_BIT & value) strings.push_back("MEMORY_PROPERTY_HOST_CACHED_BIT");
    if (VK_MEMORY_PROPERTY_LAZILY_ALLOCATED_BIT & value) strings.push_back("MEMORY_PROPERTY_LAZILY_ALLOCATED_BIT");
    if (VK_MEMORY_PROPERTY_PROTECTED_BIT & value) strings.push_back("MEMORY_PROPERTY_PROTECTED_BIT");
    if (VK_MEMORY_PROPERTY_DEVICE_COHERENT_BIT_AMD & value) strings.push_back("MEMORY_PROPERTY_DEVICE_COHERENT_BIT_AMD");
    if (VK_MEMORY_PROPERTY_DEVICE_UNCACHED_BIT_AMD & value) strings.push_back("MEMORY_PROPERTY_DEVICE_UNCACHED_BIT_AMD");
    if (VK_MEMORY_PROPERTY_RDMA_CAPABLE_BIT_NV & value) strings.push_back("MEMORY_PROPERTY_RDMA_CAPABLE_BIT_NV");
    return strings;
}
void DumpVkMemoryPropertyFlags(Printer &p, std::string name, VkMemoryPropertyFlags value) {
    if (static_cast<VkMemoryPropertyFlagBits>(value) == 0) {
        ArrayWrapper arr(p, name, 0);
        if (p.Type() != OutputType::json && p.Type() != OutputType::vkconfig_output)
            p.SetAsType().PrintString("None");
        return;
    }
    auto strings = VkMemoryPropertyFlagBitsGetStrings(static_cast<VkMemoryPropertyFlagBits>(value));
    ArrayWrapper arr(p, name, strings.size());
    for(auto& str : strings){
        if (p.Type() == OutputType::json)
            p.SetAsType().PrintString(std::string("VK_") + str);
        else
            p.SetAsType().PrintString(str);
    }
}
void DumpVkMemoryPropertyFlagBits(Printer &p, std::string name, VkMemoryPropertyFlagBits value) {
    auto strings = VkMemoryPropertyFlagBitsGetStrings(value);
    if (strings.size() > 0) {
        if (p.Type() == OutputType::json)
            p.PrintKeyString(name, std::string("VK_") + strings.at(0));
        else
            p.PrintKeyString(name, strings.at(0));
    }
}

std::vector<const char *> VkQueueFlagBitsGetStrings(VkQueueFlagBits value) {
    std::vector<const char *> strings;
    if (value == 0) { strings.push_back("None"); return strings; }
    if (VK_QUEUE_GRAPHICS_BIT & value) strings.push_back("QUEUE_GRAPHICS_BIT");
    if (VK_QUEUE_COMPUTE_BIT & value) strings.push_back("QUEUE_COMPUTE_BIT");
    if (VK_QUEUE_TRANSFER_BIT & value) strings.push_back("QUEUE_TRANSFER_BIT");
    if (VK_QUEUE_PROTECTED_BIT & value) strings.push_back("QUEUE_PROTECTED_BIT");
    if (VK_QUEUE_VIDEO_DECODE_BIT_KHR & value) strings.push_back("QUEUE_VIDEO_DECODE_BIT_KHR");
    if (VK_QUEUE_VIDEO_ENCODE_BIT_KHR & value) strings.push_back("QUEUE_VIDEO_ENCODE_BIT_KHR");
    if (VK_QUEUE_OPTICAL_FLOW_BIT_NV & value) strings.push_back("QUEUE_OPTICAL_FLOW_BIT_NV");
    return strings;
}
void DumpVkQueueFlags(Printer &p, std::string name, VkQueueFlags value) {
    if (static_cast<VkQueueFlagBits>(value) == 0) {
        ArrayWrapper arr(p, name, 0);
        if (p.Type() != OutputType::json && p.Type() != OutputType::vkconfig_output)
            p.SetAsType().PrintString("None");
        return;
    }
    auto strings = VkQueueFlagBitsGetStrings(static_cast<VkQueueFlagBits>(value));
    ArrayWrapper arr(p, name, strings.size());
    for(auto& str : strings){
        if (p.Type() == OutputType::json)
            p.SetAsType().PrintString(std::string("VK_") + str);
        else
            p.SetAsType().PrintString(str);
    }
}
void DumpVkQueueFlagBits(Printer &p, std::string name, VkQueueFlagBits value) {
    auto strings = VkQueueFlagBitsGetStrings(value);
    if (strings.size() > 0) {
        if (p.Type() == OutputType::json)
            p.PrintKeyString(name, std::string("VK_") + strings.at(0));
        else
            p.PrintKeyString(name, strings.at(0));
    }
}

std::string VkQueueFlagsString(VkQueueFlags value) {
    std::string out;
    bool is_first = true;
    if (VK_QUEUE_GRAPHICS_BIT & value) {
        if (is_first) { is_first = false; } else { out += " | "; }
        out += "QUEUE_GRAPHICS_BIT";
    }
    if (VK_QUEUE_COMPUTE_BIT & value) {
        if (is_first) { is_first = false; } else { out += " | "; }
        out += "QUEUE_COMPUTE_BIT";
    }
    if (VK_QUEUE_TRANSFER_BIT & value) {
        if (is_first) { is_first = false; } else { out += " | "; }
        out += "QUEUE_TRANSFER_BIT";
    }
    if (VK_QUEUE_PROTECTED_BIT & value) {
        if (is_first) { is_first = false; } else { out += " | "; }
        out += "QUEUE_PROTECTED_BIT";
    }
    if (VK_QUEUE_VIDEO_DECODE_BIT_KHR & value) {
        if (is_first) { is_first = false; } else { out += " | "; }
        out += "QUEUE_VIDEO_DECODE_BIT_KHR";
    }
    if (VK_QUEUE_VIDEO_ENCODE_BIT_KHR & value) {
        if (is_first) { is_first = false; } else { out += " | "; }
        out += "QUEUE_VIDEO_ENCODE_BIT_KHR";
    }
    if (VK_QUEUE_OPTICAL_FLOW_BIT_NV & value) {
        if (is_first) { is_first = false; } else { out += " | "; }
        out += "QUEUE_OPTICAL_FLOW_BIT_NV";
    }
    return out;
}
std::vector<const char *> VkResolveModeFlagBitsGetStrings(VkResolveModeFlagBits value) {
    std::vector<const char *> strings;
    if (VK_RESOLVE_MODE_NONE & value) strings.push_back("RESOLVE_MODE_NONE");
    if (VK_RESOLVE_MODE_SAMPLE_ZERO_BIT & value) strings.push_back("RESOLVE_MODE_SAMPLE_ZERO_BIT");
    if (VK_RESOLVE_MODE_AVERAGE_BIT & value) strings.push_back("RESOLVE_MODE_AVERAGE_BIT");
    if (VK_RESOLVE_MODE_MIN_BIT & value) strings.push_back("RESOLVE_MODE_MIN_BIT");
    if (VK_RESOLVE_MODE_MAX_BIT & value) strings.push_back("RESOLVE_MODE_MAX_BIT");
    if (VK_RESOLVE_MODE_EXTERNAL_FORMAT_DOWNSAMPLE_ANDROID & value) strings.push_back("RESOLVE_MODE_EXTERNAL_FORMAT_DOWNSAMPLE_ANDROID");
    return strings;
}
void DumpVkResolveModeFlags(Printer &p, std::string name, VkResolveModeFlags value) {
    if (static_cast<VkResolveModeFlagBits>(value) == 0) {
        ArrayWrapper arr(p, name, 0);
        if (p.Type() != OutputType::json && p.Type() != OutputType::vkconfig_output)
            p.SetAsType().PrintString("None");
        return;
    }
    auto strings = VkResolveModeFlagBitsGetStrings(static_cast<VkResolveModeFlagBits>(value));
    ArrayWrapper arr(p, name, strings.size());
    for(auto& str : strings){
        if (p.Type() == OutputType::json)
            p.SetAsType().PrintString(std::string("VK_") + str);
        else
            p.SetAsType().PrintString(str);
    }
}
void DumpVkResolveModeFlagBits(Printer &p, std::string name, VkResolveModeFlagBits value) {
    auto strings = VkResolveModeFlagBitsGetStrings(value);
    if (strings.size() > 0) {
        if (p.Type() == OutputType::json)
            p.PrintKeyString(name, std::string("VK_") + strings.at(0));
        else
            p.PrintKeyString(name, strings.at(0));
    }
}

std::vector<const char *> VkSampleCountFlagBitsGetStrings(VkSampleCountFlagBits value) {
    std::vector<const char *> strings;
    if (value == 0) { strings.push_back("None"); return strings; }
    if (VK_SAMPLE_COUNT_1_BIT & value) strings.push_back("SAMPLE_COUNT_1_BIT");
    if (VK_SAMPLE_COUNT_2_BIT & value) strings.push_back("SAMPLE_COUNT_2_BIT");
    if (VK_SAMPLE_COUNT_4_BIT & value) strings.push_back("SAMPLE_COUNT_4_BIT");
    if (VK_SAMPLE_COUNT_8_BIT & value) strings.push_back("SAMPLE_COUNT_8_BIT");
    if (VK_SAMPLE_COUNT_16_BIT & value) strings.push_back("SAMPLE_COUNT_16_BIT");
    if (VK_SAMPLE_COUNT_32_BIT & value) strings.push_back("SAMPLE_COUNT_32_BIT");
    if (VK_SAMPLE_COUNT_64_BIT & value) strings.push_back("SAMPLE_COUNT_64_BIT");
    return strings;
}
void DumpVkSampleCountFlags(Printer &p, std::string name, VkSampleCountFlags value) {
    if (static_cast<VkSampleCountFlagBits>(value) == 0) {
        ArrayWrapper arr(p, name, 0);
        if (p.Type() != OutputType::json && p.Type() != OutputType::vkconfig_output)
            p.SetAsType().PrintString("None");
        return;
    }
    auto strings = VkSampleCountFlagBitsGetStrings(static_cast<VkSampleCountFlagBits>(value));
    ArrayWrapper arr(p, name, strings.size());
    for(auto& str : strings){
        if (p.Type() == OutputType::json)
            p.SetAsType().PrintString(std::string("VK_") + str);
        else
            p.SetAsType().PrintString(str);
    }
}
void DumpVkSampleCountFlagBits(Printer &p, std::string name, VkSampleCountFlagBits value) {
    auto strings = VkSampleCountFlagBitsGetStrings(value);
    if (strings.size() > 0) {
        if (p.Type() == OutputType::json)
            p.PrintKeyString(name, std::string("VK_") + strings.at(0));
        else
            p.PrintKeyString(name, strings.at(0));
    }
}

std::vector<const char *> VkShaderStageFlagBitsGetStrings(VkShaderStageFlagBits value) {
    std::vector<const char *> strings;
    if (value == 0) { strings.push_back("None"); return strings; }
    if (VK_SHADER_STAGE_VERTEX_BIT & value) strings.push_back("SHADER_STAGE_VERTEX_BIT");
    if (VK_SHADER_STAGE_TESSELLATION_CONTROL_BIT & value) strings.push_back("SHADER_STAGE_TESSELLATION_CONTROL_BIT");
    if (VK_SHADER_STAGE_TESSELLATION_EVALUATION_BIT & value) strings.push_back("SHADER_STAGE_TESSELLATION_EVALUATION_BIT");
    if (VK_SHADER_STAGE_GEOMETRY_BIT & value) strings.push_back("SHADER_STAGE_GEOMETRY_BIT");
    if (VK_SHADER_STAGE_FRAGMENT_BIT & value) strings.push_back("SHADER_STAGE_FRAGMENT_BIT");
    if (VK_SHADER_STAGE_COMPUTE_BIT & value) strings.push_back("SHADER_STAGE_COMPUTE_BIT");
    if (VK_SHADER_STAGE_RAYGEN_BIT_KHR & value) strings.push_back("SHADER_STAGE_RAYGEN_BIT_KHR");
    if (VK_SHADER_STAGE_ANY_HIT_BIT_KHR & value) strings.push_back("SHADER_STAGE_ANY_HIT_BIT_KHR");
    if (VK_SHADER_STAGE_CLOSEST_HIT_BIT_KHR & value) strings.push_back("SHADER_STAGE_CLOSEST_HIT_BIT_KHR");
    if (VK_SHADER_STAGE_MISS_BIT_KHR & value) strings.push_back("SHADER_STAGE_MISS_BIT_KHR");
    if (VK_SHADER_STAGE_INTERSECTION_BIT_KHR & value) strings.push_back("SHADER_STAGE_INTERSECTION_BIT_KHR");
    if (VK_SHADER_STAGE_CALLABLE_BIT_KHR & value) strings.push_back("SHADER_STAGE_CALLABLE_BIT_KHR");
    if (VK_SHADER_STAGE_TASK_BIT_EXT & value) strings.push_back("SHADER_STAGE_TASK_BIT_EXT");
    if (VK_SHADER_STAGE_MESH_BIT_EXT & value) strings.push_back("SHADER_STAGE_MESH_BIT_EXT");
    if (VK_SHADER_STAGE_SUBPASS_SHADING_BIT_HUAWEI & value) strings.push_back("SHADER_STAGE_SUBPASS_SHADING_BIT_HUAWEI");
    if (VK_SHADER_STAGE_CLUSTER_CULLING_BIT_HUAWEI & value) strings.push_back("SHADER_STAGE_CLUSTER_CULLING_BIT_HUAWEI");
    return strings;
}
void DumpVkShaderStageFlags(Printer &p, std::string name, VkShaderStageFlags value) {
    if (static_cast<VkShaderStageFlagBits>(value) == 0) {
        ArrayWrapper arr(p, name, 0);
        if (p.Type() != OutputType::json && p.Type() != OutputType::vkconfig_output)
            p.SetAsType().PrintString("None");
        return;
    }
    auto strings = VkShaderStageFlagBitsGetStrings(static_cast<VkShaderStageFlagBits>(value));
    ArrayWrapper arr(p, name, strings.size());
    for(auto& str : strings){
        if (p.Type() == OutputType::json)
            p.SetAsType().PrintString(std::string("VK_") + str);
        else
            p.SetAsType().PrintString(str);
    }
}
void DumpVkShaderStageFlagBits(Printer &p, std::string name, VkShaderStageFlagBits value) {
    auto strings = VkShaderStageFlagBitsGetStrings(value);
    if (strings.size() > 0) {
        if (p.Type() == OutputType::json)
            p.PrintKeyString(name, std::string("VK_") + strings.at(0));
        else
            p.PrintKeyString(name, strings.at(0));
    }
}

std::vector<const char *> VkSubgroupFeatureFlagBitsGetStrings(VkSubgroupFeatureFlagBits value) {
    std::vector<const char *> strings;
    if (value == 0) { strings.push_back("None"); return strings; }
    if (VK_SUBGROUP_FEATURE_BASIC_BIT & value) strings.push_back("SUBGROUP_FEATURE_BASIC_BIT");
    if (VK_SUBGROUP_FEATURE_VOTE_BIT & value) strings.push_back("SUBGROUP_FEATURE_VOTE_BIT");
    if (VK_SUBGROUP_FEATURE_ARITHMETIC_BIT & value) strings.push_back("SUBGROUP_FEATURE_ARITHMETIC_BIT");
    if (VK_SUBGROUP_FEATURE_BALLOT_BIT & value) strings.push_back("SUBGROUP_FEATURE_BALLOT_BIT");
    if (VK_SUBGROUP_FEATURE_SHUFFLE_BIT & value) strings.push_back("SUBGROUP_FEATURE_SHUFFLE_BIT");
    if (VK_SUBGROUP_FEATURE_SHUFFLE_RELATIVE_BIT & value) strings.push_back("SUBGROUP_FEATURE_SHUFFLE_RELATIVE_BIT");
    if (VK_SUBGROUP_FEATURE_CLUSTERED_BIT & value) strings.push_back("SUBGROUP_FEATURE_CLUSTERED_BIT");
    if (VK_SUBGROUP_FEATURE_QUAD_BIT & value) strings.push_back("SUBGROUP_FEATURE_QUAD_BIT");
    if (VK_SUBGROUP_FEATURE_PARTITIONED_BIT_NV & value) strings.push_back("SUBGROUP_FEATURE_PARTITIONED_BIT_NV");
    if (VK_SUBGROUP_FEATURE_ROTATE_BIT_KHR & value) strings.push_back("SUBGROUP_FEATURE_ROTATE_BIT_KHR");
    if (VK_SUBGROUP_FEATURE_ROTATE_CLUSTERED_BIT_KHR & value) strings.push_back("SUBGROUP_FEATURE_ROTATE_CLUSTERED_BIT_KHR");
    return strings;
}
void DumpVkSubgroupFeatureFlags(Printer &p, std::string name, VkSubgroupFeatureFlags value) {
    if (static_cast<VkSubgroupFeatureFlagBits>(value) == 0) {
        ArrayWrapper arr(p, name, 0);
        if (p.Type() != OutputType::json && p.Type() != OutputType::vkconfig_output)
            p.SetAsType().PrintString("None");
        return;
    }
    auto strings = VkSubgroupFeatureFlagBitsGetStrings(static_cast<VkSubgroupFeatureFlagBits>(value));
    ArrayWrapper arr(p, name, strings.size());
    for(auto& str : strings){
        if (p.Type() == OutputType::json)
            p.SetAsType().PrintString(std::string("VK_") + str);
        else
            p.SetAsType().PrintString(str);
    }
}
void DumpVkSubgroupFeatureFlagBits(Printer &p, std::string name, VkSubgroupFeatureFlagBits value) {
    auto strings = VkSubgroupFeatureFlagBitsGetStrings(value);
    if (strings.size() > 0) {
        if (p.Type() == OutputType::json)
            p.PrintKeyString(name, std::string("VK_") + strings.at(0));
        else
            p.PrintKeyString(name, strings.at(0));
    }
}

std::vector<const char *> VkSurfaceCounterFlagBitsEXTGetStrings(VkSurfaceCounterFlagBitsEXT value) {
    std::vector<const char *> strings;
    if (value == 0) { strings.push_back("None"); return strings; }
    if (VK_SURFACE_COUNTER_VBLANK_BIT_EXT & value) strings.push_back("SURFACE_COUNTER_VBLANK_BIT_EXT");
    return strings;
}
void DumpVkSurfaceCounterFlagsEXT(Printer &p, std::string name, VkSurfaceCounterFlagsEXT value) {
    if (static_cast<VkSurfaceCounterFlagBitsEXT>(value) == 0) {
        ArrayWrapper arr(p, name, 0);
        if (p.Type() != OutputType::json && p.Type() != OutputType::vkconfig_output)
            p.SetAsType().PrintString("None");
        return;
    }
    auto strings = VkSurfaceCounterFlagBitsEXTGetStrings(static_cast<VkSurfaceCounterFlagBitsEXT>(value));
    ArrayWrapper arr(p, name, strings.size());
    for(auto& str : strings){
        if (p.Type() == OutputType::json)
            p.SetAsType().PrintString(std::string("VK_") + str);
        else
            p.SetAsType().PrintString(str);
    }
}
void DumpVkSurfaceCounterFlagBitsEXT(Printer &p, std::string name, VkSurfaceCounterFlagBitsEXT value) {
    auto strings = VkSurfaceCounterFlagBitsEXTGetStrings(value);
    if (strings.size() > 0) {
        if (p.Type() == OutputType::json)
            p.PrintKeyString(name, std::string("VK_") + strings.at(0));
        else
            p.PrintKeyString(name, strings.at(0));
    }
}

std::vector<const char *> VkSurfaceTransformFlagBitsKHRGetStrings(VkSurfaceTransformFlagBitsKHR value) {
    std::vector<const char *> strings;
    if (value == 0) { strings.push_back("None"); return strings; }
    if (VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR & value) strings.push_back("SURFACE_TRANSFORM_IDENTITY_BIT_KHR");
    if (VK_SURFACE_TRANSFORM_ROTATE_90_BIT_KHR & value) strings.push_back("SURFACE_TRANSFORM_ROTATE_90_BIT_KHR");
    if (VK_SURFACE_TRANSFORM_ROTATE_180_BIT_KHR & value) strings.push_back("SURFACE_TRANSFORM_ROTATE_180_BIT_KHR");
    if (VK_SURFACE_TRANSFORM_ROTATE_270_BIT_KHR & value) strings.push_back("SURFACE_TRANSFORM_ROTATE_270_BIT_KHR");
    if (VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_BIT_KHR & value) strings.push_back("SURFACE_TRANSFORM_HORIZONTAL_MIRROR_BIT_KHR");
    if (VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_90_BIT_KHR & value) strings.push_back("SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_90_BIT_KHR");
    if (VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_180_BIT_KHR & value) strings.push_back("SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_180_BIT_KHR");
    if (VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_270_BIT_KHR & value) strings.push_back("SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_270_BIT_KHR");
    if (VK_SURFACE_TRANSFORM_INHERIT_BIT_KHR & value) strings.push_back("SURFACE_TRANSFORM_INHERIT_BIT_KHR");
    return strings;
}
void DumpVkSurfaceTransformFlagsKHR(Printer &p, std::string name, VkSurfaceTransformFlagsKHR value) {
    if (static_cast<VkSurfaceTransformFlagBitsKHR>(value) == 0) {
        ArrayWrapper arr(p, name, 0);
        if (p.Type() != OutputType::json && p.Type() != OutputType::vkconfig_output)
            p.SetAsType().PrintString("None");
        return;
    }
    auto strings = VkSurfaceTransformFlagBitsKHRGetStrings(static_cast<VkSurfaceTransformFlagBitsKHR>(value));
    ArrayWrapper arr(p, name, strings.size());
    for(auto& str : strings){
        if (p.Type() == OutputType::json)
            p.SetAsType().PrintString(std::string("VK_") + str);
        else
            p.SetAsType().PrintString(str);
    }
}
void DumpVkSurfaceTransformFlagBitsKHR(Printer &p, std::string name, VkSurfaceTransformFlagBitsKHR value) {
    auto strings = VkSurfaceTransformFlagBitsKHRGetStrings(value);
    if (strings.size() > 0) {
        if (p.Type() == OutputType::json)
            p.PrintKeyString(name, std::string("VK_") + strings.at(0));
        else
            p.PrintKeyString(name, strings.at(0));
    }
}

std::vector<const char *> VkToolPurposeFlagBitsGetStrings(VkToolPurposeFlagBits value) {
    std::vector<const char *> strings;
    if (value == 0) { strings.push_back("None"); return strings; }
    if (VK_TOOL_PURPOSE_VALIDATION_BIT & value) strings.push_back("TOOL_PURPOSE_VALIDATION_BIT");
    if (VK_TOOL_PURPOSE_PROFILING_BIT & value) strings.push_back("TOOL_PURPOSE_PROFILING_BIT");
    if (VK_TOOL_PURPOSE_TRACING_BIT & value) strings.push_back("TOOL_PURPOSE_TRACING_BIT");
    if (VK_TOOL_PURPOSE_ADDITIONAL_FEATURES_BIT & value) strings.push_back("TOOL_PURPOSE_ADDITIONAL_FEATURES_BIT");
    if (VK_TOOL_PURPOSE_MODIFYING_FEATURES_BIT & value) strings.push_back("TOOL_PURPOSE_MODIFYING_FEATURES_BIT");
    if (VK_TOOL_PURPOSE_DEBUG_REPORTING_BIT_EXT & value) strings.push_back("TOOL_PURPOSE_DEBUG_REPORTING_BIT_EXT");
    if (VK_TOOL_PURPOSE_DEBUG_MARKERS_BIT_EXT & value) strings.push_back("TOOL_PURPOSE_DEBUG_MARKERS_BIT_EXT");
    return strings;
}
void DumpVkToolPurposeFlags(Printer &p, std::string name, VkToolPurposeFlags value) {
    if (static_cast<VkToolPurposeFlagBits>(value) == 0) {
        ArrayWrapper arr(p, name, 0);
        if (p.Type() != OutputType::json && p.Type() != OutputType::vkconfig_output)
            p.SetAsType().PrintString("None");
        return;
    }
    auto strings = VkToolPurposeFlagBitsGetStrings(static_cast<VkToolPurposeFlagBits>(value));
    ArrayWrapper arr(p, name, strings.size());
    for(auto& str : strings){
        if (p.Type() == OutputType::json)
            p.SetAsType().PrintString(std::string("VK_") + str);
        else
            p.SetAsType().PrintString(str);
    }
}
void DumpVkToolPurposeFlagBits(Printer &p, std::string name, VkToolPurposeFlagBits value) {
    auto strings = VkToolPurposeFlagBitsGetStrings(value);
    if (strings.size() > 0) {
        if (p.Type() == OutputType::json)
            p.PrintKeyString(name, std::string("VK_") + strings.at(0));
        else
            p.PrintKeyString(name, strings.at(0));
    }
}

void DumpVkConformanceVersion(Printer &p, std::string name, const VkConformanceVersion &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(8);
    p.PrintKeyValue("major", static_cast<uint32_t>(obj.major));
    p.PrintKeyValue("minor", static_cast<uint32_t>(obj.minor));
    p.PrintKeyValue("subminor", static_cast<uint32_t>(obj.subminor));
    p.PrintKeyValue("patch", static_cast<uint32_t>(obj.patch));
}
void DumpVkDrmFormatModifierProperties2EXT(Printer &p, std::string name, const VkDrmFormatModifierProperties2EXT &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(27);
    p.PrintKeyValue("drmFormatModifier", obj.drmFormatModifier);
    p.PrintKeyValue("drmFormatModifierPlaneCount", obj.drmFormatModifierPlaneCount);
    p.SetOpenDetails();
    DumpVkFormatFeatureFlags2(p, "drmFormatModifierTilingFeatures", obj.drmFormatModifierTilingFeatures);
}
void DumpVkExtent2D(Printer &p, std::string name, const VkExtent2D &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(6);
    p.PrintKeyValue("width", obj.width);
    p.PrintKeyValue("height", obj.height);
}
void DumpVkExtent3D(Printer &p, std::string name, const VkExtent3D &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(6);
    p.PrintKeyValue("width", obj.width);
    p.PrintKeyValue("height", obj.height);
    p.PrintKeyValue("depth", obj.depth);
}
void DumpVkFormatProperties(Printer &p, std::string name, const VkFormatProperties &obj) {
    ObjectWrapper object{p, name};
    p.SetOpenDetails();
    DumpVkFormatFeatureFlags(p, "linearTilingFeatures", obj.linearTilingFeatures);
    p.SetOpenDetails();
    DumpVkFormatFeatureFlags(p, "optimalTilingFeatures", obj.optimalTilingFeatures);
    p.SetOpenDetails();
    DumpVkFormatFeatureFlags(p, "bufferFeatures", obj.bufferFeatures);
}
void DumpVkFormatProperties3(Printer &p, std::string name, const VkFormatProperties3 &obj) {
    ObjectWrapper object{p, name};
    p.SetOpenDetails();
    DumpVkFormatFeatureFlags2(p, "linearTilingFeatures", obj.linearTilingFeatures);
    p.SetOpenDetails();
    DumpVkFormatFeatureFlags2(p, "optimalTilingFeatures", obj.optimalTilingFeatures);
    p.SetOpenDetails();
    DumpVkFormatFeatureFlags2(p, "bufferFeatures", obj.bufferFeatures);
}
void DumpVkLayerProperties(Printer &p, std::string name, const VkLayerProperties &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(21);
    p.PrintKeyString("layerName", obj.layerName);
    p.PrintKeyValue("specVersion", obj.specVersion);
    p.PrintKeyValue("implementationVersion", obj.implementationVersion);
    p.PrintKeyString("description", obj.description);
}
void DumpVkPhysicalDevice16BitStorageFeatures(Printer &p, std::string name, const VkPhysicalDevice16BitStorageFeatures &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(34);
    p.PrintKeyBool("storageBuffer16BitAccess", static_cast<bool>(obj.storageBuffer16BitAccess));
    p.PrintKeyBool("uniformAndStorageBuffer16BitAccess", static_cast<bool>(obj.uniformAndStorageBuffer16BitAccess));
    p.PrintKeyBool("storagePushConstant16", static_cast<bool>(obj.storagePushConstant16));
    p.PrintKeyBool("storageInputOutput16", static_cast<bool>(obj.storageInputOutput16));
}
void DumpVkPhysicalDevice4444FormatsFeaturesEXT(Printer &p, std::string name, const VkPhysicalDevice4444FormatsFeaturesEXT &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(14);
    p.PrintKeyBool("formatA4R4G4B4", static_cast<bool>(obj.formatA4R4G4B4));
    p.PrintKeyBool("formatA4B4G4R4", static_cast<bool>(obj.formatA4B4G4R4));
}
void DumpVkPhysicalDevice8BitStorageFeatures(Printer &p, std::string name, const VkPhysicalDevice8BitStorageFeatures &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(33);
    p.PrintKeyBool("storageBuffer8BitAccess", static_cast<bool>(obj.storageBuffer8BitAccess));
    p.PrintKeyBool("uniformAndStorageBuffer8BitAccess", static_cast<bool>(obj.uniformAndStorageBuffer8BitAccess));
    p.PrintKeyBool("storagePushConstant8", static_cast<bool>(obj.storagePushConstant8));
}
void DumpVkPhysicalDeviceASTCDecodeFeaturesEXT(Printer &p, std::string name, const VkPhysicalDeviceASTCDecodeFeaturesEXT &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(24);
    p.PrintKeyBool("decodeModeSharedExponent", static_cast<bool>(obj.decodeModeSharedExponent));
}
void DumpVkPhysicalDeviceBlendOperationAdvancedFeaturesEXT(Printer &p, std::string name, const VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(31);
    p.PrintKeyBool("advancedBlendCoherentOperations", static_cast<bool>(obj.advancedBlendCoherentOperations));
}
void DumpVkPhysicalDeviceBlendOperationAdvancedPropertiesEXT(Printer &p, std::string name, const VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(37);
    p.PrintKeyValue("advancedBlendMaxColorAttachments", obj.advancedBlendMaxColorAttachments);
    p.PrintKeyBool("advancedBlendIndependentBlend", static_cast<bool>(obj.advancedBlendIndependentBlend));
    p.PrintKeyBool("advancedBlendNonPremultipliedSrcColor", static_cast<bool>(obj.advancedBlendNonPremultipliedSrcColor));
    p.PrintKeyBool("advancedBlendNonPremultipliedDstColor", static_cast<bool>(obj.advancedBlendNonPremultipliedDstColor));
    p.PrintKeyBool("advancedBlendCorrelatedOverlap", static_cast<bool>(obj.advancedBlendCorrelatedOverlap));
    p.PrintKeyBool("advancedBlendAllOperations", static_cast<bool>(obj.advancedBlendAllOperations));
}
void DumpVkPhysicalDeviceBufferDeviceAddressFeatures(Printer &p, std::string name, const VkPhysicalDeviceBufferDeviceAddressFeatures &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(32);
    p.PrintKeyBool("bufferDeviceAddress", static_cast<bool>(obj.bufferDeviceAddress));
    p.PrintKeyBool("bufferDeviceAddressCaptureReplay", static_cast<bool>(obj.bufferDeviceAddressCaptureReplay));
    p.PrintKeyBool("bufferDeviceAddressMultiDevice", static_cast<bool>(obj.bufferDeviceAddressMultiDevice));
}
void DumpVkPhysicalDeviceColorWriteEnableFeaturesEXT(Printer &p, std::string name, const VkPhysicalDeviceColorWriteEnableFeaturesEXT &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(16);
    p.PrintKeyBool("colorWriteEnable", static_cast<bool>(obj.colorWriteEnable));
}
void DumpVkPhysicalDeviceConservativeRasterizationPropertiesEXT(Printer &p, std::string name, const VkPhysicalDeviceConservativeRasterizationPropertiesEXT &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(43);
    p.PrintKeyValue("primitiveOverestimationSize", obj.primitiveOverestimationSize);
    p.PrintKeyValue("maxExtraPrimitiveOverestimationSize", obj.maxExtraPrimitiveOverestimationSize);
    p.PrintKeyValue("extraPrimitiveOverestimationSizeGranularity", obj.extraPrimitiveOverestimationSizeGranularity);
    p.PrintKeyBool("primitiveUnderestimation", static_cast<bool>(obj.primitiveUnderestimation));
    p.PrintKeyBool("conservativePointAndLineRasterization", static_cast<bool>(obj.conservativePointAndLineRasterization));
    p.PrintKeyBool("degenerateTrianglesRasterized", static_cast<bool>(obj.degenerateTrianglesRasterized));
    p.PrintKeyBool("degenerateLinesRasterized", static_cast<bool>(obj.degenerateLinesRasterized));
    p.PrintKeyBool("fullyCoveredFragmentShaderInputVariable", static_cast<bool>(obj.fullyCoveredFragmentShaderInputVariable));
    p.PrintKeyBool("conservativeRasterizationPostDepthCoverage", static_cast<bool>(obj.conservativeRasterizationPostDepthCoverage));
}
void DumpVkPhysicalDeviceCustomBorderColorFeaturesEXT(Printer &p, std::string name, const VkPhysicalDeviceCustomBorderColorFeaturesEXT &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(30);
    p.PrintKeyBool("customBorderColors", static_cast<bool>(obj.customBorderColors));
    p.PrintKeyBool("customBorderColorWithoutFormat", static_cast<bool>(obj.customBorderColorWithoutFormat));
}
void DumpVkPhysicalDeviceCustomBorderColorPropertiesEXT(Printer &p, std::string name, const VkPhysicalDeviceCustomBorderColorPropertiesEXT &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(28);
    p.PrintKeyValue("maxCustomBorderColorSamplers", obj.maxCustomBorderColorSamplers);
}
void DumpVkPhysicalDeviceDepthClipEnableFeaturesEXT(Printer &p, std::string name, const VkPhysicalDeviceDepthClipEnableFeaturesEXT &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(15);
    p.PrintKeyBool("depthClipEnable", static_cast<bool>(obj.depthClipEnable));
}
void DumpVkPhysicalDeviceDepthStencilResolveProperties(Printer &p, std::string name, const VkPhysicalDeviceDepthStencilResolveProperties &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(22);
    DumpVkResolveModeFlags(p, "supportedDepthResolveModes", obj.supportedDepthResolveModes);
    DumpVkResolveModeFlags(p, "supportedStencilResolveModes", obj.supportedStencilResolveModes);
    p.PrintKeyBool("independentResolveNone", static_cast<bool>(obj.independentResolveNone));
    p.PrintKeyBool("independentResolve", static_cast<bool>(obj.independentResolve));
}
void DumpVkPhysicalDeviceDescriptorIndexingFeatures(Printer &p, std::string name, const VkPhysicalDeviceDescriptorIndexingFeatures &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(50);
    p.PrintKeyBool("shaderInputAttachmentArrayDynamicIndexing", static_cast<bool>(obj.shaderInputAttachmentArrayDynamicIndexing));
    p.PrintKeyBool("shaderUniformTexelBufferArrayDynamicIndexing", static_cast<bool>(obj.shaderUniformTexelBufferArrayDynamicIndexing));
    p.PrintKeyBool("shaderStorageTexelBufferArrayDynamicIndexing", static_cast<bool>(obj.shaderStorageTexelBufferArrayDynamicIndexing));
    p.PrintKeyBool("shaderUniformBufferArrayNonUniformIndexing", static_cast<bool>(obj.shaderUniformBufferArrayNonUniformIndexing));
    p.PrintKeyBool("shaderSampledImageArrayNonUniformIndexing", static_cast<bool>(obj.shaderSampledImageArrayNonUniformIndexing));
    p.PrintKeyBool("shaderStorageBufferArrayNonUniformIndexing", static_cast<bool>(obj.shaderStorageBufferArrayNonUniformIndexing));
    p.PrintKeyBool("shaderStorageImageArrayNonUniformIndexing", static_cast<bool>(obj.shaderStorageImageArrayNonUniformIndexing));
    p.PrintKeyBool("shaderInputAttachmentArrayNonUniformIndexing", static_cast<bool>(obj.shaderInputAttachmentArrayNonUniformIndexing));
    p.PrintKeyBool("shaderUniformTexelBufferArrayNonUniformIndexing", static_cast<bool>(obj.shaderUniformTexelBufferArrayNonUniformIndexing));
    p.PrintKeyBool("shaderStorageTexelBufferArrayNonUniformIndexing", static_cast<bool>(obj.shaderStorageTexelBufferArrayNonUniformIndexing));
    p.PrintKeyBool("descriptorBindingUniformBufferUpdateAfterBind", static_cast<bool>(obj.descriptorBindingUniformBufferUpdateAfterBind));
    p.PrintKeyBool("descriptorBindingSampledImageUpdateAfterBind", static_cast<bool>(obj.descriptorBindingSampledImageUpdateAfterBind));
    p.PrintKeyBool("descriptorBindingStorageImageUpdateAfterBind", static_cast<bool>(obj.descriptorBindingStorageImageUpdateAfterBind));
    p.PrintKeyBool("descriptorBindingStorageBufferUpdateAfterBind", static_cast<bool>(obj.descriptorBindingStorageBufferUpdateAfterBind));
    p.PrintKeyBool("descriptorBindingUniformTexelBufferUpdateAfterBind", static_cast<bool>(obj.descriptorBindingUniformTexelBufferUpdateAfterBind));
    p.PrintKeyBool("descriptorBindingStorageTexelBufferUpdateAfterBind", static_cast<bool>(obj.descriptorBindingStorageTexelBufferUpdateAfterBind));
    p.PrintKeyBool("descriptorBindingUpdateUnusedWhilePending", static_cast<bool>(obj.descriptorBindingUpdateUnusedWhilePending));
    p.PrintKeyBool("descriptorBindingPartiallyBound", static_cast<bool>(obj.descriptorBindingPartiallyBound));
    p.PrintKeyBool("descriptorBindingVariableDescriptorCount", static_cast<bool>(obj.descriptorBindingVariableDescriptorCount));
    p.PrintKeyBool("runtimeDescriptorArray", static_cast<bool>(obj.runtimeDescriptorArray));
}
void DumpVkPhysicalDeviceDescriptorIndexingProperties(Printer &p, std::string name, const VkPhysicalDeviceDescriptorIndexingProperties &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(52);
    p.PrintKeyValue("maxUpdateAfterBindDescriptorsInAllPools", obj.maxUpdateAfterBindDescriptorsInAllPools);
    p.PrintKeyBool("shaderUniformBufferArrayNonUniformIndexingNative", static_cast<bool>(obj.shaderUniformBufferArrayNonUniformIndexingNative));
    p.PrintKeyBool("shaderSampledImageArrayNonUniformIndexingNative", static_cast<bool>(obj.shaderSampledImageArrayNonUniformIndexingNative));
    p.PrintKeyBool("shaderStorageBufferArrayNonUniformIndexingNative", static_cast<bool>(obj.shaderStorageBufferArrayNonUniformIndexingNative));
    p.PrintKeyBool("shaderStorageImageArrayNonUniformIndexingNative", static_cast<bool>(obj.shaderStorageImageArrayNonUniformIndexingNative));
    p.PrintKeyBool("shaderInputAttachmentArrayNonUniformIndexingNative", static_cast<bool>(obj.shaderInputAttachmentArrayNonUniformIndexingNative));
    p.PrintKeyBool("robustBufferAccessUpdateAfterBind", static_cast<bool>(obj.robustBufferAccessUpdateAfterBind));
    p.PrintKeyBool("quadDivergentImplicitLod", static_cast<bool>(obj.quadDivergentImplicitLod));
    p.PrintKeyValue("maxPerStageDescriptorUpdateAfterBindSamplers", obj.maxPerStageDescriptorUpdateAfterBindSamplers);
    p.PrintKeyValue("maxPerStageDescriptorUpdateAfterBindUniformBuffers", obj.maxPerStageDescriptorUpdateAfterBindUniformBuffers);
    p.PrintKeyValue("maxPerStageDescriptorUpdateAfterBindStorageBuffers", obj.maxPerStageDescriptorUpdateAfterBindStorageBuffers);
    p.PrintKeyValue("maxPerStageDescriptorUpdateAfterBindSampledImages", obj.maxPerStageDescriptorUpdateAfterBindSampledImages);
    p.PrintKeyValue("maxPerStageDescriptorUpdateAfterBindStorageImages", obj.maxPerStageDescriptorUpdateAfterBindStorageImages);
    p.PrintKeyValue("maxPerStageDescriptorUpdateAfterBindInputAttachments", obj.maxPerStageDescriptorUpdateAfterBindInputAttachments);
    p.PrintKeyValue("maxPerStageUpdateAfterBindResources", obj.maxPerStageUpdateAfterBindResources);
    p.PrintKeyValue("maxDescriptorSetUpdateAfterBindSamplers", obj.maxDescriptorSetUpdateAfterBindSamplers);
    p.PrintKeyValue("maxDescriptorSetUpdateAfterBindUniformBuffers", obj.maxDescriptorSetUpdateAfterBindUniformBuffers);
    p.PrintKeyValue("maxDescriptorSetUpdateAfterBindUniformBuffersDynamic", obj.maxDescriptorSetUpdateAfterBindUniformBuffersDynamic);
    p.PrintKeyValue("maxDescriptorSetUpdateAfterBindStorageBuffers", obj.maxDescriptorSetUpdateAfterBindStorageBuffers);
    p.PrintKeyValue("maxDescriptorSetUpdateAfterBindStorageBuffersDynamic", obj.maxDescriptorSetUpdateAfterBindStorageBuffersDynamic);
    p.PrintKeyValue("maxDescriptorSetUpdateAfterBindSampledImages", obj.maxDescriptorSetUpdateAfterBindSampledImages);
    p.PrintKeyValue("maxDescriptorSetUpdateAfterBindStorageImages", obj.maxDescriptorSetUpdateAfterBindStorageImages);
    p.PrintKeyValue("maxDescriptorSetUpdateAfterBindInputAttachments", obj.maxDescriptorSetUpdateAfterBindInputAttachments);
}
void DumpVkPhysicalDeviceDiscardRectanglePropertiesEXT(Printer &p, std::string name, const VkPhysicalDeviceDiscardRectanglePropertiesEXT &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(20);
    p.PrintKeyValue("maxDiscardRectangles", obj.maxDiscardRectangles);
}
void DumpVkPhysicalDeviceDriverProperties(Printer &p, std::string name, const VkPhysicalDeviceDriverProperties &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(15);
    DumpVkDriverId(p, "driverID", obj.driverID);
    p.PrintKeyString("driverName", obj.driverName);
    p.PrintKeyString("driverInfo", obj.driverInfo);
    DumpVkConformanceVersion(p, "conformanceVersion", obj.conformanceVersion);
}
void DumpVkPhysicalDeviceDynamicRenderingFeatures(Printer &p, std::string name, const VkPhysicalDeviceDynamicRenderingFeatures &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(16);
    p.PrintKeyBool("dynamicRendering", static_cast<bool>(obj.dynamicRendering));
}
void DumpVkPhysicalDeviceExtendedDynamicState2FeaturesEXT(Printer &p, std::string name, const VkPhysicalDeviceExtendedDynamicState2FeaturesEXT &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(39);
    p.PrintKeyBool("extendedDynamicState2", static_cast<bool>(obj.extendedDynamicState2));
    p.PrintKeyBool("extendedDynamicState2LogicOp", static_cast<bool>(obj.extendedDynamicState2LogicOp));
    p.PrintKeyBool("extendedDynamicState2PatchControlPoints", static_cast<bool>(obj.extendedDynamicState2PatchControlPoints));
}
void DumpVkPhysicalDeviceExtendedDynamicStateFeaturesEXT(Printer &p, std::string name, const VkPhysicalDeviceExtendedDynamicStateFeaturesEXT &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(20);
    p.PrintKeyBool("extendedDynamicState", static_cast<bool>(obj.extendedDynamicState));
}
void DumpVkPhysicalDeviceExternalMemoryHostPropertiesEXT(Printer &p, std::string name, const VkPhysicalDeviceExternalMemoryHostPropertiesEXT &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(31);
    p.PrintKeyValue("minImportedHostPointerAlignment", to_hex_str(p, obj.minImportedHostPointerAlignment));
}
void DumpVkPhysicalDeviceFeatures(Printer &p, std::string name, const VkPhysicalDeviceFeatures &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(39);
    p.PrintKeyBool("robustBufferAccess", static_cast<bool>(obj.robustBufferAccess));
    p.PrintKeyBool("fullDrawIndexUint32", static_cast<bool>(obj.fullDrawIndexUint32));
    p.PrintKeyBool("imageCubeArray", static_cast<bool>(obj.imageCubeArray));
    p.PrintKeyBool("independentBlend", static_cast<bool>(obj.independentBlend));
    p.PrintKeyBool("geometryShader", static_cast<bool>(obj.geometryShader));
    p.PrintKeyBool("tessellationShader", static_cast<bool>(obj.tessellationShader));
    p.PrintKeyBool("sampleRateShading", static_cast<bool>(obj.sampleRateShading));
    p.PrintKeyBool("dualSrcBlend", static_cast<bool>(obj.dualSrcBlend));
    p.PrintKeyBool("logicOp", static_cast<bool>(obj.logicOp));
    p.PrintKeyBool("multiDrawIndirect", static_cast<bool>(obj.multiDrawIndirect));
    p.PrintKeyBool("drawIndirectFirstInstance", static_cast<bool>(obj.drawIndirectFirstInstance));
    p.PrintKeyBool("depthClamp", static_cast<bool>(obj.depthClamp));
    p.PrintKeyBool("depthBiasClamp", static_cast<bool>(obj.depthBiasClamp));
    p.PrintKeyBool("fillModeNonSolid", static_cast<bool>(obj.fillModeNonSolid));
    p.PrintKeyBool("depthBounds", static_cast<bool>(obj.depthBounds));
    p.PrintKeyBool("wideLines", static_cast<bool>(obj.wideLines));
    p.PrintKeyBool("largePoints", static_cast<bool>(obj.largePoints));
    p.PrintKeyBool("alphaToOne", static_cast<bool>(obj.alphaToOne));
    p.PrintKeyBool("multiViewport", static_cast<bool>(obj.multiViewport));
    p.PrintKeyBool("samplerAnisotropy", static_cast<bool>(obj.samplerAnisotropy));
    p.PrintKeyBool("textureCompressionETC2", static_cast<bool>(obj.textureCompressionETC2));
    p.PrintKeyBool("textureCompressionASTC_LDR", static_cast<bool>(obj.textureCompressionASTC_LDR));
    p.PrintKeyBool("textureCompressionBC", static_cast<bool>(obj.textureCompressionBC));
    p.PrintKeyBool("occlusionQueryPrecise", static_cast<bool>(obj.occlusionQueryPrecise));
    p.PrintKeyBool("pipelineStatisticsQuery", static_cast<bool>(obj.pipelineStatisticsQuery));
    p.PrintKeyBool("vertexPipelineStoresAndAtomics", static_cast<bool>(obj.vertexPipelineStoresAndAtomics));
    p.PrintKeyBool("fragmentStoresAndAtomics", static_cast<bool>(obj.fragmentStoresAndAtomics));
    p.PrintKeyBool("shaderTessellationAndGeometryPointSize", static_cast<bool>(obj.shaderTessellationAndGeometryPointSize));
    p.PrintKeyBool("shaderImageGatherExtended", static_cast<bool>(obj.shaderImageGatherExtended));
    p.PrintKeyBool("shaderStorageImageExtendedFormats", static_cast<bool>(obj.shaderStorageImageExtendedFormats));
    p.PrintKeyBool("shaderStorageImageMultisample", static_cast<bool>(obj.shaderStorageImageMultisample));
    p.PrintKeyBool("shaderStorageImageReadWithoutFormat", static_cast<bool>(obj.shaderStorageImageReadWithoutFormat));
    p.PrintKeyBool("shaderStorageImageWriteWithoutFormat", static_cast<bool>(obj.shaderStorageImageWriteWithoutFormat));
    p.PrintKeyBool("shaderUniformBufferArrayDynamicIndexing", static_cast<bool>(obj.shaderUniformBufferArrayDynamicIndexing));
    p.PrintKeyBool("shaderSampledImageArrayDynamicIndexing", static_cast<bool>(obj.shaderSampledImageArrayDynamicIndexing));
    p.PrintKeyBool("shaderStorageBufferArrayDynamicIndexing", static_cast<bool>(obj.shaderStorageBufferArrayDynamicIndexing));
    p.PrintKeyBool("shaderStorageImageArrayDynamicIndexing", static_cast<bool>(obj.shaderStorageImageArrayDynamicIndexing));
    p.PrintKeyBool("shaderClipDistance", static_cast<bool>(obj.shaderClipDistance));
    p.PrintKeyBool("shaderCullDistance", static_cast<bool>(obj.shaderCullDistance));
    p.PrintKeyBool("shaderFloat64", static_cast<bool>(obj.shaderFloat64));
    p.PrintKeyBool("shaderInt64", static_cast<bool>(obj.shaderInt64));
    p.PrintKeyBool("shaderInt16", static_cast<bool>(obj.shaderInt16));
    p.PrintKeyBool("shaderResourceResidency", static_cast<bool>(obj.shaderResourceResidency));
    p.PrintKeyBool("shaderResourceMinLod", static_cast<bool>(obj.shaderResourceMinLod));
    p.PrintKeyBool("sparseBinding", static_cast<bool>(obj.sparseBinding));
    p.PrintKeyBool("sparseResidencyBuffer", static_cast<bool>(obj.sparseResidencyBuffer));
    p.PrintKeyBool("sparseResidencyImage2D", static_cast<bool>(obj.sparseResidencyImage2D));
    p.PrintKeyBool("sparseResidencyImage3D", static_cast<bool>(obj.sparseResidencyImage3D));
    p.PrintKeyBool("sparseResidency2Samples", static_cast<bool>(obj.sparseResidency2Samples));
    p.PrintKeyBool("sparseResidency4Samples", static_cast<bool>(obj.sparseResidency4Samples));
    p.PrintKeyBool("sparseResidency8Samples", static_cast<bool>(obj.sparseResidency8Samples));
    p.PrintKeyBool("sparseResidency16Samples", static_cast<bool>(obj.sparseResidency16Samples));
    p.PrintKeyBool("sparseResidencyAliased", static_cast<bool>(obj.sparseResidencyAliased));
    p.PrintKeyBool("variableMultisampleRate", static_cast<bool>(obj.variableMultisampleRate));
    p.PrintKeyBool("inheritedQueries", static_cast<bool>(obj.inheritedQueries));
}
void DumpVkPhysicalDeviceFloatControlsProperties(Printer &p, std::string name, const VkPhysicalDeviceFloatControlsProperties &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(37);
    DumpVkShaderFloatControlsIndependence(p, "denormBehaviorIndependence", obj.denormBehaviorIndependence);
    DumpVkShaderFloatControlsIndependence(p, "roundingModeIndependence", obj.roundingModeIndependence);
    p.PrintKeyBool("shaderSignedZeroInfNanPreserveFloat16", static_cast<bool>(obj.shaderSignedZeroInfNanPreserveFloat16));
    p.PrintKeyBool("shaderSignedZeroInfNanPreserveFloat32", static_cast<bool>(obj.shaderSignedZeroInfNanPreserveFloat32));
    p.PrintKeyBool("shaderSignedZeroInfNanPreserveFloat64", static_cast<bool>(obj.shaderSignedZeroInfNanPreserveFloat64));
    p.PrintKeyBool("shaderDenormPreserveFloat16", static_cast<bool>(obj.shaderDenormPreserveFloat16));
    p.PrintKeyBool("shaderDenormPreserveFloat32", static_cast<bool>(obj.shaderDenormPreserveFloat32));
    p.PrintKeyBool("shaderDenormPreserveFloat64", static_cast<bool>(obj.shaderDenormPreserveFloat64));
    p.PrintKeyBool("shaderDenormFlushToZeroFloat16", static_cast<bool>(obj.shaderDenormFlushToZeroFloat16));
    p.PrintKeyBool("shaderDenormFlushToZeroFloat32", static_cast<bool>(obj.shaderDenormFlushToZeroFloat32));
    p.PrintKeyBool("shaderDenormFlushToZeroFloat64", static_cast<bool>(obj.shaderDenormFlushToZeroFloat64));
    p.PrintKeyBool("shaderRoundingModeRTEFloat16", static_cast<bool>(obj.shaderRoundingModeRTEFloat16));
    p.PrintKeyBool("shaderRoundingModeRTEFloat32", static_cast<bool>(obj.shaderRoundingModeRTEFloat32));
    p.PrintKeyBool("shaderRoundingModeRTEFloat64", static_cast<bool>(obj.shaderRoundingModeRTEFloat64));
    p.PrintKeyBool("shaderRoundingModeRTZFloat16", static_cast<bool>(obj.shaderRoundingModeRTZFloat16));
    p.PrintKeyBool("shaderRoundingModeRTZFloat32", static_cast<bool>(obj.shaderRoundingModeRTZFloat32));
    p.PrintKeyBool("shaderRoundingModeRTZFloat64", static_cast<bool>(obj.shaderRoundingModeRTZFloat64));
}
void DumpVkPhysicalDeviceFragmentShaderInterlockFeaturesEXT(Printer &p, std::string name, const VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(34);
    p.PrintKeyBool("fragmentShaderSampleInterlock", static_cast<bool>(obj.fragmentShaderSampleInterlock));
    p.PrintKeyBool("fragmentShaderPixelInterlock", static_cast<bool>(obj.fragmentShaderPixelInterlock));
    p.PrintKeyBool("fragmentShaderShadingRateInterlock", static_cast<bool>(obj.fragmentShaderShadingRateInterlock));
}
void DumpVkPhysicalDeviceFragmentShadingRateFeaturesKHR(Printer &p, std::string name, const VkPhysicalDeviceFragmentShadingRateFeaturesKHR &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(29);
    p.PrintKeyBool("pipelineFragmentShadingRate", static_cast<bool>(obj.pipelineFragmentShadingRate));
    p.PrintKeyBool("primitiveFragmentShadingRate", static_cast<bool>(obj.primitiveFragmentShadingRate));
    p.PrintKeyBool("attachmentFragmentShadingRate", static_cast<bool>(obj.attachmentFragmentShadingRate));
}
void DumpVkPhysicalDeviceFragmentShadingRatePropertiesKHR(Printer &p, std::string name, const VkPhysicalDeviceFragmentShadingRatePropertiesKHR &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(52);
    DumpVkExtent2D(p, "minFragmentShadingRateAttachmentTexelSize", obj.minFragmentShadingRateAttachmentTexelSize);
    DumpVkExtent2D(p, "maxFragmentShadingRateAttachmentTexelSize", obj.maxFragmentShadingRateAttachmentTexelSize);
    p.PrintKeyValue("maxFragmentShadingRateAttachmentTexelSizeAspectRatio", obj.maxFragmentShadingRateAttachmentTexelSizeAspectRatio);
    p.PrintKeyBool("primitiveFragmentShadingRateWithMultipleViewports", static_cast<bool>(obj.primitiveFragmentShadingRateWithMultipleViewports));
    p.PrintKeyBool("layeredShadingRateAttachments", static_cast<bool>(obj.layeredShadingRateAttachments));
    p.PrintKeyBool("fragmentShadingRateNonTrivialCombinerOps", static_cast<bool>(obj.fragmentShadingRateNonTrivialCombinerOps));
    DumpVkExtent2D(p, "maxFragmentSize", obj.maxFragmentSize);
    p.PrintKeyValue("maxFragmentSizeAspectRatio", obj.maxFragmentSizeAspectRatio);
    p.PrintKeyValue("maxFragmentShadingRateCoverageSamples", obj.maxFragmentShadingRateCoverageSamples);
    DumpVkSampleCountFlagBits(p, "maxFragmentShadingRateRasterizationSamples", obj.maxFragmentShadingRateRasterizationSamples);
    p.PrintKeyBool("fragmentShadingRateWithShaderDepthStencilWrites", static_cast<bool>(obj.fragmentShadingRateWithShaderDepthStencilWrites));
    p.PrintKeyBool("fragmentShadingRateWithSampleMask", static_cast<bool>(obj.fragmentShadingRateWithSampleMask));
    p.PrintKeyBool("fragmentShadingRateWithShaderSampleMask", static_cast<bool>(obj.fragmentShadingRateWithShaderSampleMask));
    p.PrintKeyBool("fragmentShadingRateWithConservativeRasterization", static_cast<bool>(obj.fragmentShadingRateWithConservativeRasterization));
    p.PrintKeyBool("fragmentShadingRateWithFragmentShaderInterlock", static_cast<bool>(obj.fragmentShadingRateWithFragmentShaderInterlock));
    p.PrintKeyBool("fragmentShadingRateWithCustomSampleLocations", static_cast<bool>(obj.fragmentShadingRateWithCustomSampleLocations));
    p.PrintKeyBool("fragmentShadingRateStrictMultiplyCombiner", static_cast<bool>(obj.fragmentShadingRateStrictMultiplyCombiner));
}
void DumpVkPhysicalDeviceGlobalPriorityQueryFeaturesKHR(Printer &p, std::string name, const VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(19);
    p.PrintKeyBool("globalPriorityQuery", static_cast<bool>(obj.globalPriorityQuery));
}
void DumpVkPhysicalDeviceHostQueryResetFeatures(Printer &p, std::string name, const VkPhysicalDeviceHostQueryResetFeatures &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(14);
    p.PrintKeyBool("hostQueryReset", static_cast<bool>(obj.hostQueryReset));
}
void DumpVkPhysicalDeviceIDProperties(Printer &p, std::string name, const VkPhysicalDeviceIDProperties &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(15);
    p.PrintKeyValue("deviceUUID", obj.deviceUUID);
    p.PrintKeyValue("driverUUID", obj.driverUUID);
    if (obj.deviceLUIDValid) { // special case
    p.PrintKeyValue("deviceLUID", obj.deviceLUID);
    }
    p.PrintKeyValue("deviceNodeMask", obj.deviceNodeMask);
    p.PrintKeyBool("deviceLUIDValid", static_cast<bool>(obj.deviceLUIDValid));
}
void DumpVkPhysicalDeviceImageRobustnessFeatures(Printer &p, std::string name, const VkPhysicalDeviceImageRobustnessFeatures &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(17);
    p.PrintKeyBool("robustImageAccess", static_cast<bool>(obj.robustImageAccess));
}
void DumpVkPhysicalDeviceImagelessFramebufferFeatures(Printer &p, std::string name, const VkPhysicalDeviceImagelessFramebufferFeatures &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(20);
    p.PrintKeyBool("imagelessFramebuffer", static_cast<bool>(obj.imagelessFramebuffer));
}
void DumpVkPhysicalDeviceIndexTypeUint8FeaturesKHR(Printer &p, std::string name, const VkPhysicalDeviceIndexTypeUint8FeaturesKHR &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(14);
    p.PrintKeyBool("indexTypeUint8", static_cast<bool>(obj.indexTypeUint8));
}
void DumpVkPhysicalDeviceInlineUniformBlockFeatures(Printer &p, std::string name, const VkPhysicalDeviceInlineUniformBlockFeatures &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(50);
    p.PrintKeyBool("inlineUniformBlock", static_cast<bool>(obj.inlineUniformBlock));
    p.PrintKeyBool("descriptorBindingInlineUniformBlockUpdateAfterBind", static_cast<bool>(obj.descriptorBindingInlineUniformBlockUpdateAfterBind));
}
void DumpVkPhysicalDeviceInlineUniformBlockProperties(Printer &p, std::string name, const VkPhysicalDeviceInlineUniformBlockProperties &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(55);
    p.PrintKeyValue("maxInlineUniformBlockSize", obj.maxInlineUniformBlockSize);
    p.PrintKeyValue("maxPerStageDescriptorInlineUniformBlocks", obj.maxPerStageDescriptorInlineUniformBlocks);
    p.PrintKeyValue("maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks", obj.maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks);
    p.PrintKeyValue("maxDescriptorSetInlineUniformBlocks", obj.maxDescriptorSetInlineUniformBlocks);
    p.PrintKeyValue("maxDescriptorSetUpdateAfterBindInlineUniformBlocks", obj.maxDescriptorSetUpdateAfterBindInlineUniformBlocks);
}
void DumpVkPhysicalDeviceLimits(Printer &p, std::string name, const VkPhysicalDeviceLimits &obj) {
    if (p.Type() == OutputType::json)
        p.ObjectStart("limits");
    else
        p.SetSubHeader().ObjectStart(name);
    p.SetMinKeyWidth(47);
    p.PrintKeyValue("maxImageDimension1D", obj.maxImageDimension1D);
    p.PrintKeyValue("maxImageDimension2D", obj.maxImageDimension2D);
    p.PrintKeyValue("maxImageDimension3D", obj.maxImageDimension3D);
    p.PrintKeyValue("maxImageDimensionCube", obj.maxImageDimensionCube);
    p.PrintKeyValue("maxImageArrayLayers", obj.maxImageArrayLayers);
    p.PrintKeyValue("maxTexelBufferElements", obj.maxTexelBufferElements);
    p.PrintKeyValue("maxUniformBufferRange", obj.maxUniformBufferRange);
    p.PrintKeyValue("maxStorageBufferRange", obj.maxStorageBufferRange);
    p.PrintKeyValue("maxPushConstantsSize", obj.maxPushConstantsSize);
    p.PrintKeyValue("maxMemoryAllocationCount", obj.maxMemoryAllocationCount);
    p.PrintKeyValue("maxSamplerAllocationCount", obj.maxSamplerAllocationCount);
    p.PrintKeyValue("bufferImageGranularity", to_hex_str(p, obj.bufferImageGranularity));
    p.PrintKeyValue("sparseAddressSpaceSize", to_hex_str(p, obj.sparseAddressSpaceSize));
    p.PrintKeyValue("maxBoundDescriptorSets", obj.maxBoundDescriptorSets);
    p.PrintKeyValue("maxPerStageDescriptorSamplers", obj.maxPerStageDescriptorSamplers);
    p.PrintKeyValue("maxPerStageDescriptorUniformBuffers", obj.maxPerStageDescriptorUniformBuffers);
    p.PrintKeyValue("maxPerStageDescriptorStorageBuffers", obj.maxPerStageDescriptorStorageBuffers);
    p.PrintKeyValue("maxPerStageDescriptorSampledImages", obj.maxPerStageDescriptorSampledImages);
    p.PrintKeyValue("maxPerStageDescriptorStorageImages", obj.maxPerStageDescriptorStorageImages);
    p.PrintKeyValue("maxPerStageDescriptorInputAttachments", obj.maxPerStageDescriptorInputAttachments);
    p.PrintKeyValue("maxPerStageResources", obj.maxPerStageResources);
    p.PrintKeyValue("maxDescriptorSetSamplers", obj.maxDescriptorSetSamplers);
    p.PrintKeyValue("maxDescriptorSetUniformBuffers", obj.maxDescriptorSetUniformBuffers);
    p.PrintKeyValue("maxDescriptorSetUniformBuffersDynamic", obj.maxDescriptorSetUniformBuffersDynamic);
    p.PrintKeyValue("maxDescriptorSetStorageBuffers", obj.maxDescriptorSetStorageBuffers);
    p.PrintKeyValue("maxDescriptorSetStorageBuffersDynamic", obj.maxDescriptorSetStorageBuffersDynamic);
    p.PrintKeyValue("maxDescriptorSetSampledImages", obj.maxDescriptorSetSampledImages);
    p.PrintKeyValue("maxDescriptorSetStorageImages", obj.maxDescriptorSetStorageImages);
    p.PrintKeyValue("maxDescriptorSetInputAttachments", obj.maxDescriptorSetInputAttachments);
    p.PrintKeyValue("maxVertexInputAttributes", obj.maxVertexInputAttributes);
    p.PrintKeyValue("maxVertexInputBindings", obj.maxVertexInputBindings);
    p.PrintKeyValue("maxVertexInputAttributeOffset", obj.maxVertexInputAttributeOffset);
    p.PrintKeyValue("maxVertexInputBindingStride", obj.maxVertexInputBindingStride);
    p.PrintKeyValue("maxVertexOutputComponents", obj.maxVertexOutputComponents);
    p.PrintKeyValue("maxTessellationGenerationLevel", obj.maxTessellationGenerationLevel);
    p.PrintKeyValue("maxTessellationPatchSize", obj.maxTessellationPatchSize);
    p.PrintKeyValue("maxTessellationControlPerVertexInputComponents", obj.maxTessellationControlPerVertexInputComponents);
    p.PrintKeyValue("maxTessellationControlPerVertexOutputComponents", obj.maxTessellationControlPerVertexOutputComponents);
    p.PrintKeyValue("maxTessellationControlPerPatchOutputComponents", obj.maxTessellationControlPerPatchOutputComponents);
    p.PrintKeyValue("maxTessellationControlTotalOutputComponents", obj.maxTessellationControlTotalOutputComponents);
    p.PrintKeyValue("maxTessellationEvaluationInputComponents", obj.maxTessellationEvaluationInputComponents);
    p.PrintKeyValue("maxTessellationEvaluationOutputComponents", obj.maxTessellationEvaluationOutputComponents);
    p.PrintKeyValue("maxGeometryShaderInvocations", obj.maxGeometryShaderInvocations);
    p.PrintKeyValue("maxGeometryInputComponents", obj.maxGeometryInputComponents);
    p.PrintKeyValue("maxGeometryOutputComponents", obj.maxGeometryOutputComponents);
    p.PrintKeyValue("maxGeometryOutputVertices", obj.maxGeometryOutputVertices);
    p.PrintKeyValue("maxGeometryTotalOutputComponents", obj.maxGeometryTotalOutputComponents);
    p.PrintKeyValue("maxFragmentInputComponents", obj.maxFragmentInputComponents);
    p.PrintKeyValue("maxFragmentOutputAttachments", obj.maxFragmentOutputAttachments);
    p.PrintKeyValue("maxFragmentDualSrcAttachments", obj.maxFragmentDualSrcAttachments);
    p.PrintKeyValue("maxFragmentCombinedOutputResources", obj.maxFragmentCombinedOutputResources);
    p.PrintKeyValue("maxComputeSharedMemorySize", obj.maxComputeSharedMemorySize);
    {
        ArrayWrapper arr(p,"maxComputeWorkGroupCount", 3);
        for (uint32_t i = 0; i < 3; i++) { p.PrintElement(obj.maxComputeWorkGroupCount[i]); }
    }
    p.PrintKeyValue("maxComputeWorkGroupInvocations", obj.maxComputeWorkGroupInvocations);
    {
        ArrayWrapper arr(p,"maxComputeWorkGroupSize", 3);
        for (uint32_t i = 0; i < 3; i++) { p.PrintElement(obj.maxComputeWorkGroupSize[i]); }
    }
    p.PrintKeyValue("subPixelPrecisionBits", obj.subPixelPrecisionBits);
    p.PrintKeyValue("subTexelPrecisionBits", obj.subTexelPrecisionBits);
    p.PrintKeyValue("mipmapPrecisionBits", obj.mipmapPrecisionBits);
    p.PrintKeyValue("maxDrawIndexedIndexValue", obj.maxDrawIndexedIndexValue);
    p.PrintKeyValue("maxDrawIndirectCount", obj.maxDrawIndirectCount);
    p.PrintKeyValue("maxSamplerLodBias", obj.maxSamplerLodBias);
    p.PrintKeyValue("maxSamplerAnisotropy", obj.maxSamplerAnisotropy);
    p.PrintKeyValue("maxViewports", obj.maxViewports);
    {
        ArrayWrapper arr(p,"maxViewportDimensions", 2);
        for (uint32_t i = 0; i < 2; i++) { p.PrintElement(obj.maxViewportDimensions[i]); }
    }
    {
        ArrayWrapper arr(p,"viewportBoundsRange", 2);
        for (uint32_t i = 0; i < 2; i++) { p.PrintElement(obj.viewportBoundsRange[i]); }
    }
    p.PrintKeyValue("viewportSubPixelBits", obj.viewportSubPixelBits);
    p.PrintKeyValue("minMemoryMapAlignment", obj.minMemoryMapAlignment);
    p.PrintKeyValue("minTexelBufferOffsetAlignment", to_hex_str(p, obj.minTexelBufferOffsetAlignment));
    p.PrintKeyValue("minUniformBufferOffsetAlignment", to_hex_str(p, obj.minUniformBufferOffsetAlignment));
    p.PrintKeyValue("minStorageBufferOffsetAlignment", to_hex_str(p, obj.minStorageBufferOffsetAlignment));
    p.PrintKeyValue("minTexelOffset", obj.minTexelOffset);
    p.PrintKeyValue("maxTexelOffset", obj.maxTexelOffset);
    p.PrintKeyValue("minTexelGatherOffset", obj.minTexelGatherOffset);
    p.PrintKeyValue("maxTexelGatherOffset", obj.maxTexelGatherOffset);
    p.PrintKeyValue("minInterpolationOffset", obj.minInterpolationOffset);
    p.PrintKeyValue("maxInterpolationOffset", obj.maxInterpolationOffset);
    p.PrintKeyValue("subPixelInterpolationOffsetBits", obj.subPixelInterpolationOffsetBits);
    p.PrintKeyValue("maxFramebufferWidth", obj.maxFramebufferWidth);
    p.PrintKeyValue("maxFramebufferHeight", obj.maxFramebufferHeight);
    p.PrintKeyValue("maxFramebufferLayers", obj.maxFramebufferLayers);
    DumpVkSampleCountFlags(p, "framebufferColorSampleCounts", obj.framebufferColorSampleCounts);
    DumpVkSampleCountFlags(p, "framebufferDepthSampleCounts", obj.framebufferDepthSampleCounts);
    DumpVkSampleCountFlags(p, "framebufferStencilSampleCounts", obj.framebufferStencilSampleCounts);
    DumpVkSampleCountFlags(p, "framebufferNoAttachmentsSampleCounts", obj.framebufferNoAttachmentsSampleCounts);
    p.PrintKeyValue("maxColorAttachments", obj.maxColorAttachments);
    DumpVkSampleCountFlags(p, "sampledImageColorSampleCounts", obj.sampledImageColorSampleCounts);
    DumpVkSampleCountFlags(p, "sampledImageIntegerSampleCounts", obj.sampledImageIntegerSampleCounts);
    DumpVkSampleCountFlags(p, "sampledImageDepthSampleCounts", obj.sampledImageDepthSampleCounts);
    DumpVkSampleCountFlags(p, "sampledImageStencilSampleCounts", obj.sampledImageStencilSampleCounts);
    DumpVkSampleCountFlags(p, "storageImageSampleCounts", obj.storageImageSampleCounts);
    p.PrintKeyValue("maxSampleMaskWords", obj.maxSampleMaskWords);
    p.PrintKeyBool("timestampComputeAndGraphics", static_cast<bool>(obj.timestampComputeAndGraphics));
    p.PrintKeyValue("timestampPeriod", obj.timestampPeriod);
    p.PrintKeyValue("maxClipDistances", obj.maxClipDistances);
    p.PrintKeyValue("maxCullDistances", obj.maxCullDistances);
    p.PrintKeyValue("maxCombinedClipAndCullDistances", obj.maxCombinedClipAndCullDistances);
    p.PrintKeyValue("discreteQueuePriorities", obj.discreteQueuePriorities);
    {
        ArrayWrapper arr(p,"pointSizeRange", 2);
        for (uint32_t i = 0; i < 2; i++) { p.PrintElement(obj.pointSizeRange[i]); }
    }
    {
        ArrayWrapper arr(p,"lineWidthRange", 2);
        for (uint32_t i = 0; i < 2; i++) { p.PrintElement(obj.lineWidthRange[i]); }
    }
    p.PrintKeyValue("pointSizeGranularity", obj.pointSizeGranularity);
    p.PrintKeyValue("lineWidthGranularity", obj.lineWidthGranularity);
    p.PrintKeyBool("strictLines", static_cast<bool>(obj.strictLines));
    p.PrintKeyBool("standardSampleLocations", static_cast<bool>(obj.standardSampleLocations));
    p.PrintKeyValue("optimalBufferCopyOffsetAlignment", to_hex_str(p, obj.optimalBufferCopyOffsetAlignment));
    p.PrintKeyValue("optimalBufferCopyRowPitchAlignment", to_hex_str(p, obj.optimalBufferCopyRowPitchAlignment));
    p.PrintKeyValue("nonCoherentAtomSize", to_hex_str(p, obj.nonCoherentAtomSize));
    p.ObjectEnd();
}
void DumpVkPhysicalDeviceLineRasterizationFeaturesKHR(Printer &p, std::string name, const VkPhysicalDeviceLineRasterizationFeaturesKHR &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(24);
    p.PrintKeyBool("rectangularLines", static_cast<bool>(obj.rectangularLines));
    p.PrintKeyBool("bresenhamLines", static_cast<bool>(obj.bresenhamLines));
    p.PrintKeyBool("smoothLines", static_cast<bool>(obj.smoothLines));
    p.PrintKeyBool("stippledRectangularLines", static_cast<bool>(obj.stippledRectangularLines));
    p.PrintKeyBool("stippledBresenhamLines", static_cast<bool>(obj.stippledBresenhamLines));
    p.PrintKeyBool("stippledSmoothLines", static_cast<bool>(obj.stippledSmoothLines));
}
void DumpVkPhysicalDeviceLineRasterizationPropertiesKHR(Printer &p, std::string name, const VkPhysicalDeviceLineRasterizationPropertiesKHR &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(25);
    p.PrintKeyValue("lineSubPixelPrecisionBits", obj.lineSubPixelPrecisionBits);
}
void DumpVkPhysicalDeviceMaintenance3Properties(Printer &p, std::string name, const VkPhysicalDeviceMaintenance3Properties &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(23);
    p.PrintKeyValue("maxPerSetDescriptors", obj.maxPerSetDescriptors);
    p.PrintKeyValue("maxMemoryAllocationSize", to_hex_str(p, obj.maxMemoryAllocationSize));
}
void DumpVkPhysicalDeviceMaintenance4Features(Printer &p, std::string name, const VkPhysicalDeviceMaintenance4Features &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(12);
    p.PrintKeyBool("maintenance4", static_cast<bool>(obj.maintenance4));
}
void DumpVkPhysicalDeviceMaintenance4Properties(Printer &p, std::string name, const VkPhysicalDeviceMaintenance4Properties &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(13);
    p.PrintKeyValue("maxBufferSize", to_hex_str(p, obj.maxBufferSize));
}
void DumpVkPhysicalDeviceMemoryBudgetPropertiesEXT(Printer &p, std::string name, const VkPhysicalDeviceMemoryBudgetPropertiesEXT &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(14);
    {
        ArrayWrapper arr(p,"heapBudget", 16);
        for (uint32_t i = 0; i < 16; i++) { p.PrintElement(obj.heapBudget[i]); }
    }
    {
        ArrayWrapper arr(p,"heapUsage", 16);
        for (uint32_t i = 0; i < 16; i++) { p.PrintElement(obj.heapUsage[i]); }
    }
}
void DumpVkPhysicalDeviceMultiviewFeatures(Printer &p, std::string name, const VkPhysicalDeviceMultiviewFeatures &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(27);
    p.PrintKeyBool("multiview", static_cast<bool>(obj.multiview));
    p.PrintKeyBool("multiviewGeometryShader", static_cast<bool>(obj.multiviewGeometryShader));
    p.PrintKeyBool("multiviewTessellationShader", static_cast<bool>(obj.multiviewTessellationShader));
}
void DumpVkPhysicalDeviceMultiviewProperties(Printer &p, std::string name, const VkPhysicalDeviceMultiviewProperties &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(25);
    p.PrintKeyValue("maxMultiviewViewCount", obj.maxMultiviewViewCount);
    p.PrintKeyValue("maxMultiviewInstanceIndex", obj.maxMultiviewInstanceIndex);
}
void DumpVkPhysicalDevicePCIBusInfoPropertiesEXT(Printer &p, std::string name, const VkPhysicalDevicePCIBusInfoPropertiesEXT &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(11);
    p.PrintKeyValue("pciDomain", obj.pciDomain);
    p.PrintKeyValue("pciBus", obj.pciBus);
    p.PrintKeyValue("pciDevice", obj.pciDevice);
    p.PrintKeyValue("pciFunction", obj.pciFunction);
}
void DumpVkPhysicalDevicePerformanceQueryFeaturesKHR(Printer &p, std::string name, const VkPhysicalDevicePerformanceQueryFeaturesKHR &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(36);
    p.PrintKeyBool("performanceCounterQueryPools", static_cast<bool>(obj.performanceCounterQueryPools));
    p.PrintKeyBool("performanceCounterMultipleQueryPools", static_cast<bool>(obj.performanceCounterMultipleQueryPools));
}
void DumpVkPhysicalDevicePerformanceQueryPropertiesKHR(Printer &p, std::string name, const VkPhysicalDevicePerformanceQueryPropertiesKHR &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(29);
    p.PrintKeyBool("allowCommandBufferQueryCopies", static_cast<bool>(obj.allowCommandBufferQueryCopies));
}
void DumpVkPhysicalDevicePipelineCreationCacheControlFeatures(Printer &p, std::string name, const VkPhysicalDevicePipelineCreationCacheControlFeatures &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(28);
    p.PrintKeyBool("pipelineCreationCacheControl", static_cast<bool>(obj.pipelineCreationCacheControl));
}
void DumpVkPhysicalDevicePointClippingProperties(Printer &p, std::string name, const VkPhysicalDevicePointClippingProperties &obj) {
    ObjectWrapper object{p, name};
    DumpVkPointClippingBehavior(p, "pointClippingBehavior", obj.pointClippingBehavior);
}
void DumpVkPhysicalDevicePrivateDataFeatures(Printer &p, std::string name, const VkPhysicalDevicePrivateDataFeatures &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(11);
    p.PrintKeyBool("privateData", static_cast<bool>(obj.privateData));
}
void DumpVkPhysicalDeviceProtectedMemoryFeatures(Printer &p, std::string name, const VkPhysicalDeviceProtectedMemoryFeatures &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(15);
    p.PrintKeyBool("protectedMemory", static_cast<bool>(obj.protectedMemory));
}
void DumpVkPhysicalDeviceProtectedMemoryProperties(Printer &p, std::string name, const VkPhysicalDeviceProtectedMemoryProperties &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(16);
    p.PrintKeyBool("protectedNoFault", static_cast<bool>(obj.protectedNoFault));
}
void DumpVkPhysicalDeviceRobustness2FeaturesEXT(Printer &p, std::string name, const VkPhysicalDeviceRobustness2FeaturesEXT &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(19);
    p.PrintKeyBool("robustBufferAccess2", static_cast<bool>(obj.robustBufferAccess2));
    p.PrintKeyBool("robustImageAccess2", static_cast<bool>(obj.robustImageAccess2));
    p.PrintKeyBool("nullDescriptor", static_cast<bool>(obj.nullDescriptor));
}
void DumpVkPhysicalDeviceRobustness2PropertiesEXT(Printer &p, std::string name, const VkPhysicalDeviceRobustness2PropertiesEXT &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(38);
    p.PrintKeyValue("robustStorageBufferAccessSizeAlignment", to_hex_str(p, obj.robustStorageBufferAccessSizeAlignment));
    p.PrintKeyValue("robustUniformBufferAccessSizeAlignment", to_hex_str(p, obj.robustUniformBufferAccessSizeAlignment));
}
void DumpVkPhysicalDeviceSampleLocationsPropertiesEXT(Printer &p, std::string name, const VkPhysicalDeviceSampleLocationsPropertiesEXT &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(32);
    DumpVkSampleCountFlags(p, "sampleLocationSampleCounts", obj.sampleLocationSampleCounts);
    DumpVkExtent2D(p, "maxSampleLocationGridSize", obj.maxSampleLocationGridSize);
    {
        ArrayWrapper arr(p,"sampleLocationCoordinateRange", 2);
        for (uint32_t i = 0; i < 2; i++) { p.PrintElement(obj.sampleLocationCoordinateRange[i]); }
    }
    p.PrintKeyValue("sampleLocationSubPixelBits", obj.sampleLocationSubPixelBits);
    p.PrintKeyBool("variableSampleLocations", static_cast<bool>(obj.variableSampleLocations));
}
void DumpVkPhysicalDeviceSamplerFilterMinmaxProperties(Printer &p, std::string name, const VkPhysicalDeviceSamplerFilterMinmaxProperties &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(34);
    p.PrintKeyBool("filterMinmaxSingleComponentFormats", static_cast<bool>(obj.filterMinmaxSingleComponentFormats));
    p.PrintKeyBool("filterMinmaxImageComponentMapping", static_cast<bool>(obj.filterMinmaxImageComponentMapping));
}
void DumpVkPhysicalDeviceSamplerYcbcrConversionFeatures(Printer &p, std::string name, const VkPhysicalDeviceSamplerYcbcrConversionFeatures &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(22);
    p.PrintKeyBool("samplerYcbcrConversion", static_cast<bool>(obj.samplerYcbcrConversion));
}
void DumpVkPhysicalDeviceScalarBlockLayoutFeatures(Printer &p, std::string name, const VkPhysicalDeviceScalarBlockLayoutFeatures &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(17);
    p.PrintKeyBool("scalarBlockLayout", static_cast<bool>(obj.scalarBlockLayout));
}
void DumpVkPhysicalDeviceSeparateDepthStencilLayoutsFeatures(Printer &p, std::string name, const VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(27);
    p.PrintKeyBool("separateDepthStencilLayouts", static_cast<bool>(obj.separateDepthStencilLayouts));
}
void DumpVkPhysicalDeviceShaderAtomicFloatFeaturesEXT(Printer &p, std::string name, const VkPhysicalDeviceShaderAtomicFloatFeaturesEXT &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(28);
    p.PrintKeyBool("shaderBufferFloat32Atomics", static_cast<bool>(obj.shaderBufferFloat32Atomics));
    p.PrintKeyBool("shaderBufferFloat32AtomicAdd", static_cast<bool>(obj.shaderBufferFloat32AtomicAdd));
    p.PrintKeyBool("shaderBufferFloat64Atomics", static_cast<bool>(obj.shaderBufferFloat64Atomics));
    p.PrintKeyBool("shaderBufferFloat64AtomicAdd", static_cast<bool>(obj.shaderBufferFloat64AtomicAdd));
    p.PrintKeyBool("shaderSharedFloat32Atomics", static_cast<bool>(obj.shaderSharedFloat32Atomics));
    p.PrintKeyBool("shaderSharedFloat32AtomicAdd", static_cast<bool>(obj.shaderSharedFloat32AtomicAdd));
    p.PrintKeyBool("shaderSharedFloat64Atomics", static_cast<bool>(obj.shaderSharedFloat64Atomics));
    p.PrintKeyBool("shaderSharedFloat64AtomicAdd", static_cast<bool>(obj.shaderSharedFloat64AtomicAdd));
    p.PrintKeyBool("shaderImageFloat32Atomics", static_cast<bool>(obj.shaderImageFloat32Atomics));
    p.PrintKeyBool("shaderImageFloat32AtomicAdd", static_cast<bool>(obj.shaderImageFloat32AtomicAdd));
    p.PrintKeyBool("sparseImageFloat32Atomics", static_cast<bool>(obj.sparseImageFloat32Atomics));
    p.PrintKeyBool("sparseImageFloat32AtomicAdd", static_cast<bool>(obj.sparseImageFloat32AtomicAdd));
}
void DumpVkPhysicalDeviceShaderAtomicInt64Features(Printer &p, std::string name, const VkPhysicalDeviceShaderAtomicInt64Features &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(24);
    p.PrintKeyBool("shaderBufferInt64Atomics", static_cast<bool>(obj.shaderBufferInt64Atomics));
    p.PrintKeyBool("shaderSharedInt64Atomics", static_cast<bool>(obj.shaderSharedInt64Atomics));
}
void DumpVkPhysicalDeviceShaderClockFeaturesKHR(Printer &p, std::string name, const VkPhysicalDeviceShaderClockFeaturesKHR &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(19);
    p.PrintKeyBool("shaderSubgroupClock", static_cast<bool>(obj.shaderSubgroupClock));
    p.PrintKeyBool("shaderDeviceClock", static_cast<bool>(obj.shaderDeviceClock));
}
void DumpVkPhysicalDeviceShaderDemoteToHelperInvocationFeatures(Printer &p, std::string name, const VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(30);
    p.PrintKeyBool("shaderDemoteToHelperInvocation", static_cast<bool>(obj.shaderDemoteToHelperInvocation));
}
void DumpVkPhysicalDeviceShaderDrawParametersFeatures(Printer &p, std::string name, const VkPhysicalDeviceShaderDrawParametersFeatures &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(20);
    p.PrintKeyBool("shaderDrawParameters", static_cast<bool>(obj.shaderDrawParameters));
}
void DumpVkPhysicalDeviceShaderFloat16Int8Features(Printer &p, std::string name, const VkPhysicalDeviceShaderFloat16Int8Features &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(13);
    p.PrintKeyBool("shaderFloat16", static_cast<bool>(obj.shaderFloat16));
    p.PrintKeyBool("shaderInt8", static_cast<bool>(obj.shaderInt8));
}
void DumpVkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT(Printer &p, std::string name, const VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(23);
    p.PrintKeyBool("shaderImageInt64Atomics", static_cast<bool>(obj.shaderImageInt64Atomics));
    p.PrintKeyBool("sparseImageInt64Atomics", static_cast<bool>(obj.sparseImageInt64Atomics));
}
void DumpVkPhysicalDeviceShaderIntegerDotProductFeatures(Printer &p, std::string name, const VkPhysicalDeviceShaderIntegerDotProductFeatures &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(23);
    p.PrintKeyBool("shaderIntegerDotProduct", static_cast<bool>(obj.shaderIntegerDotProduct));
}
void DumpVkPhysicalDeviceShaderIntegerDotProductProperties(Printer &p, std::string name, const VkPhysicalDeviceShaderIntegerDotProductProperties &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(77);
    p.PrintKeyBool("integerDotProduct8BitUnsignedAccelerated", static_cast<bool>(obj.integerDotProduct8BitUnsignedAccelerated));
    p.PrintKeyBool("integerDotProduct8BitSignedAccelerated", static_cast<bool>(obj.integerDotProduct8BitSignedAccelerated));
    p.PrintKeyBool("integerDotProduct8BitMixedSignednessAccelerated", static_cast<bool>(obj.integerDotProduct8BitMixedSignednessAccelerated));
    p.PrintKeyBool("integerDotProduct4x8BitPackedUnsignedAccelerated", static_cast<bool>(obj.integerDotProduct4x8BitPackedUnsignedAccelerated));
    p.PrintKeyBool("integerDotProduct4x8BitPackedSignedAccelerated", static_cast<bool>(obj.integerDotProduct4x8BitPackedSignedAccelerated));
    p.PrintKeyBool("integerDotProduct4x8BitPackedMixedSignednessAccelerated", static_cast<bool>(obj.integerDotProduct4x8BitPackedMixedSignednessAccelerated));
    p.PrintKeyBool("integerDotProduct16BitUnsignedAccelerated", static_cast<bool>(obj.integerDotProduct16BitUnsignedAccelerated));
    p.PrintKeyBool("integerDotProduct16BitSignedAccelerated", static_cast<bool>(obj.integerDotProduct16BitSignedAccelerated));
    p.PrintKeyBool("integerDotProduct16BitMixedSignednessAccelerated", static_cast<bool>(obj.integerDotProduct16BitMixedSignednessAccelerated));
    p.PrintKeyBool("integerDotProduct32BitUnsignedAccelerated", static_cast<bool>(obj.integerDotProduct32BitUnsignedAccelerated));
    p.PrintKeyBool("integerDotProduct32BitSignedAccelerated", static_cast<bool>(obj.integerDotProduct32BitSignedAccelerated));
    p.PrintKeyBool("integerDotProduct32BitMixedSignednessAccelerated", static_cast<bool>(obj.integerDotProduct32BitMixedSignednessAccelerated));
    p.PrintKeyBool("integerDotProduct64BitUnsignedAccelerated", static_cast<bool>(obj.integerDotProduct64BitUnsignedAccelerated));
    p.PrintKeyBool("integerDotProduct64BitSignedAccelerated", static_cast<bool>(obj.integerDotProduct64BitSignedAccelerated));
    p.PrintKeyBool("integerDotProduct64BitMixedSignednessAccelerated", static_cast<bool>(obj.integerDotProduct64BitMixedSignednessAccelerated));
    p.PrintKeyBool("integerDotProductAccumulatingSaturating8BitUnsignedAccelerated", static_cast<bool>(obj.integerDotProductAccumulatingSaturating8BitUnsignedAccelerated));
    p.PrintKeyBool("integerDotProductAccumulatingSaturating8BitSignedAccelerated", static_cast<bool>(obj.integerDotProductAccumulatingSaturating8BitSignedAccelerated));
    p.PrintKeyBool("integerDotProductAccumulatingSaturating8BitMixedSignednessAccelerated", static_cast<bool>(obj.integerDotProductAccumulatingSaturating8BitMixedSignednessAccelerated));
    p.PrintKeyBool("integerDotProductAccumulatingSaturating4x8BitPackedUnsignedAccelerated", static_cast<bool>(obj.integerDotProductAccumulatingSaturating4x8BitPackedUnsignedAccelerated));
    p.PrintKeyBool("integerDotProductAccumulatingSaturating4x8BitPackedSignedAccelerated", static_cast<bool>(obj.integerDotProductAccumulatingSaturating4x8BitPackedSignedAccelerated));
    p.PrintKeyBool("integerDotProductAccumulatingSaturating4x8BitPackedMixedSignednessAccelerated", static_cast<bool>(obj.integerDotProductAccumulatingSaturating4x8BitPackedMixedSignednessAccelerated));
    p.PrintKeyBool("integerDotProductAccumulatingSaturating16BitUnsignedAccelerated", static_cast<bool>(obj.integerDotProductAccumulatingSaturating16BitUnsignedAccelerated));
    p.PrintKeyBool("integerDotProductAccumulatingSaturating16BitSignedAccelerated", static_cast<bool>(obj.integerDotProductAccumulatingSaturating16BitSignedAccelerated));
    p.PrintKeyBool("integerDotProductAccumulatingSaturating16BitMixedSignednessAccelerated", static_cast<bool>(obj.integerDotProductAccumulatingSaturating16BitMixedSignednessAccelerated));
    p.PrintKeyBool("integerDotProductAccumulatingSaturating32BitUnsignedAccelerated", static_cast<bool>(obj.integerDotProductAccumulatingSaturating32BitUnsignedAccelerated));
    p.PrintKeyBool("integerDotProductAccumulatingSaturating32BitSignedAccelerated", static_cast<bool>(obj.integerDotProductAccumulatingSaturating32BitSignedAccelerated));
    p.PrintKeyBool("integerDotProductAccumulatingSaturating32BitMixedSignednessAccelerated", static_cast<bool>(obj.integerDotProductAccumulatingSaturating32BitMixedSignednessAccelerated));
    p.PrintKeyBool("integerDotProductAccumulatingSaturating64BitUnsignedAccelerated", static_cast<bool>(obj.integerDotProductAccumulatingSaturating64BitUnsignedAccelerated));
    p.PrintKeyBool("integerDotProductAccumulatingSaturating64BitSignedAccelerated", static_cast<bool>(obj.integerDotProductAccumulatingSaturating64BitSignedAccelerated));
    p.PrintKeyBool("integerDotProductAccumulatingSaturating64BitMixedSignednessAccelerated", static_cast<bool>(obj.integerDotProductAccumulatingSaturating64BitMixedSignednessAccelerated));
}
void DumpVkPhysicalDeviceShaderSubgroupExtendedTypesFeatures(Printer &p, std::string name, const VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(27);
    p.PrintKeyBool("shaderSubgroupExtendedTypes", static_cast<bool>(obj.shaderSubgroupExtendedTypes));
}
void DumpVkPhysicalDeviceShaderTerminateInvocationFeatures(Printer &p, std::string name, const VkPhysicalDeviceShaderTerminateInvocationFeatures &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(25);
    p.PrintKeyBool("shaderTerminateInvocation", static_cast<bool>(obj.shaderTerminateInvocation));
}
void DumpVkPhysicalDeviceSparseProperties(Printer &p, std::string name, const VkPhysicalDeviceSparseProperties &obj) {
    if (p.Type() == OutputType::json)
        p.ObjectStart("sparseProperties");
    else
        p.SetSubHeader().ObjectStart(name);
    p.SetMinKeyWidth(40);
    p.PrintKeyBool("residencyStandard2DBlockShape", static_cast<bool>(obj.residencyStandard2DBlockShape));
    p.PrintKeyBool("residencyStandard2DMultisampleBlockShape", static_cast<bool>(obj.residencyStandard2DMultisampleBlockShape));
    p.PrintKeyBool("residencyStandard3DBlockShape", static_cast<bool>(obj.residencyStandard3DBlockShape));
    p.PrintKeyBool("residencyAlignedMipSize", static_cast<bool>(obj.residencyAlignedMipSize));
    p.PrintKeyBool("residencyNonResidentStrict", static_cast<bool>(obj.residencyNonResidentStrict));
    p.ObjectEnd();
}
void DumpVkPhysicalDeviceSubgroupProperties(Printer &p, std::string name, const VkPhysicalDeviceSubgroupProperties &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(25);
    p.PrintKeyValue("subgroupSize", obj.subgroupSize);
    DumpVkShaderStageFlags(p, "supportedStages", obj.supportedStages);
    DumpVkSubgroupFeatureFlags(p, "supportedOperations", obj.supportedOperations);
    p.PrintKeyBool("quadOperationsInAllStages", static_cast<bool>(obj.quadOperationsInAllStages));
}
void DumpVkPhysicalDeviceSubgroupSizeControlFeatures(Printer &p, std::string name, const VkPhysicalDeviceSubgroupSizeControlFeatures &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(20);
    p.PrintKeyBool("subgroupSizeControl", static_cast<bool>(obj.subgroupSizeControl));
    p.PrintKeyBool("computeFullSubgroups", static_cast<bool>(obj.computeFullSubgroups));
}
void DumpVkPhysicalDeviceSubgroupSizeControlProperties(Printer &p, std::string name, const VkPhysicalDeviceSubgroupSizeControlProperties &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(28);
    p.PrintKeyValue("minSubgroupSize", obj.minSubgroupSize);
    p.PrintKeyValue("maxSubgroupSize", obj.maxSubgroupSize);
    p.PrintKeyValue("maxComputeWorkgroupSubgroups", obj.maxComputeWorkgroupSubgroups);
    DumpVkShaderStageFlags(p, "requiredSubgroupSizeStages", obj.requiredSubgroupSizeStages);
}
void DumpVkPhysicalDeviceSynchronization2Features(Printer &p, std::string name, const VkPhysicalDeviceSynchronization2Features &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(16);
    p.PrintKeyBool("synchronization2", static_cast<bool>(obj.synchronization2));
}
void DumpVkPhysicalDeviceTexelBufferAlignmentFeaturesEXT(Printer &p, std::string name, const VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(20);
    p.PrintKeyBool("texelBufferAlignment", static_cast<bool>(obj.texelBufferAlignment));
}
void DumpVkPhysicalDeviceTexelBufferAlignmentProperties(Printer &p, std::string name, const VkPhysicalDeviceTexelBufferAlignmentProperties &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(44);
    p.PrintKeyValue("storageTexelBufferOffsetAlignmentBytes", to_hex_str(p, obj.storageTexelBufferOffsetAlignmentBytes));
    p.PrintKeyBool("storageTexelBufferOffsetSingleTexelAlignment", static_cast<bool>(obj.storageTexelBufferOffsetSingleTexelAlignment));
    p.PrintKeyValue("uniformTexelBufferOffsetAlignmentBytes", to_hex_str(p, obj.uniformTexelBufferOffsetAlignmentBytes));
    p.PrintKeyBool("uniformTexelBufferOffsetSingleTexelAlignment", static_cast<bool>(obj.uniformTexelBufferOffsetSingleTexelAlignment));
}
void DumpVkPhysicalDeviceTextureCompressionASTCHDRFeatures(Printer &p, std::string name, const VkPhysicalDeviceTextureCompressionASTCHDRFeatures &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(26);
    p.PrintKeyBool("textureCompressionASTC_HDR", static_cast<bool>(obj.textureCompressionASTC_HDR));
}
void DumpVkPhysicalDeviceTimelineSemaphoreFeatures(Printer &p, std::string name, const VkPhysicalDeviceTimelineSemaphoreFeatures &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(17);
    p.PrintKeyBool("timelineSemaphore", static_cast<bool>(obj.timelineSemaphore));
}
void DumpVkPhysicalDeviceTimelineSemaphoreProperties(Printer &p, std::string name, const VkPhysicalDeviceTimelineSemaphoreProperties &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(35);
    p.PrintKeyValue("maxTimelineSemaphoreValueDifference", obj.maxTimelineSemaphoreValueDifference);
}
void DumpVkPhysicalDeviceToolProperties(Printer &p, std::string name, const VkPhysicalDeviceToolProperties &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(16);
    p.PrintKeyString("name", obj.name);
    p.PrintKeyString("version", obj.version);
    DumpVkToolPurposeFlags(p, "purposes", obj.purposes);
    p.PrintKeyString("description", obj.description);
    p.PrintKeyString("layer", obj.layer);
}
void DumpVkPhysicalDeviceUniformBufferStandardLayoutFeatures(Printer &p, std::string name, const VkPhysicalDeviceUniformBufferStandardLayoutFeatures &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(27);
    p.PrintKeyBool("uniformBufferStandardLayout", static_cast<bool>(obj.uniformBufferStandardLayout));
}
void DumpVkPhysicalDeviceVariablePointersFeatures(Printer &p, std::string name, const VkPhysicalDeviceVariablePointersFeatures &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(29);
    p.PrintKeyBool("variablePointersStorageBuffer", static_cast<bool>(obj.variablePointersStorageBuffer));
    p.PrintKeyBool("variablePointers", static_cast<bool>(obj.variablePointers));
}
void DumpVkPhysicalDeviceVertexAttributeDivisorFeaturesKHR(Printer &p, std::string name, const VkPhysicalDeviceVertexAttributeDivisorFeaturesKHR &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(38);
    p.PrintKeyBool("vertexAttributeInstanceRateDivisor", static_cast<bool>(obj.vertexAttributeInstanceRateDivisor));
    p.PrintKeyBool("vertexAttributeInstanceRateZeroDivisor", static_cast<bool>(obj.vertexAttributeInstanceRateZeroDivisor));
}
void DumpVkPhysicalDeviceVertexAttributeDivisorPropertiesKHR(Printer &p, std::string name, const VkPhysicalDeviceVertexAttributeDivisorPropertiesKHR &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(28);
    p.PrintKeyValue("maxVertexAttribDivisor", obj.maxVertexAttribDivisor);
    p.PrintKeyBool("supportsNonZeroFirstInstance", static_cast<bool>(obj.supportsNonZeroFirstInstance));
}
void DumpVkPhysicalDeviceVertexInputDynamicStateFeaturesEXT(Printer &p, std::string name, const VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(23);
    p.PrintKeyBool("vertexInputDynamicState", static_cast<bool>(obj.vertexInputDynamicState));
}
void DumpVkPhysicalDeviceVulkan11Features(Printer &p, std::string name, const VkPhysicalDeviceVulkan11Features &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(34);
    p.PrintKeyBool("storageBuffer16BitAccess", static_cast<bool>(obj.storageBuffer16BitAccess));
    p.PrintKeyBool("uniformAndStorageBuffer16BitAccess", static_cast<bool>(obj.uniformAndStorageBuffer16BitAccess));
    p.PrintKeyBool("storagePushConstant16", static_cast<bool>(obj.storagePushConstant16));
    p.PrintKeyBool("storageInputOutput16", static_cast<bool>(obj.storageInputOutput16));
    p.PrintKeyBool("multiview", static_cast<bool>(obj.multiview));
    p.PrintKeyBool("multiviewGeometryShader", static_cast<bool>(obj.multiviewGeometryShader));
    p.PrintKeyBool("multiviewTessellationShader", static_cast<bool>(obj.multiviewTessellationShader));
    p.PrintKeyBool("variablePointersStorageBuffer", static_cast<bool>(obj.variablePointersStorageBuffer));
    p.PrintKeyBool("variablePointers", static_cast<bool>(obj.variablePointers));
    p.PrintKeyBool("protectedMemory", static_cast<bool>(obj.protectedMemory));
    p.PrintKeyBool("samplerYcbcrConversion", static_cast<bool>(obj.samplerYcbcrConversion));
    p.PrintKeyBool("shaderDrawParameters", static_cast<bool>(obj.shaderDrawParameters));
}
void DumpVkPhysicalDeviceVulkan11Properties(Printer &p, std::string name, const VkPhysicalDeviceVulkan11Properties &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(33);
    p.PrintKeyValue("deviceUUID", obj.deviceUUID);
    p.PrintKeyValue("driverUUID", obj.driverUUID);
    if (obj.deviceLUIDValid) { // special case
    p.PrintKeyValue("deviceLUID", obj.deviceLUID);
    }
    p.PrintKeyValue("deviceNodeMask", obj.deviceNodeMask);
    p.PrintKeyBool("deviceLUIDValid", static_cast<bool>(obj.deviceLUIDValid));
    p.PrintKeyValue("subgroupSize", obj.subgroupSize);
    DumpVkShaderStageFlags(p, "subgroupSupportedStages", obj.subgroupSupportedStages);
    DumpVkSubgroupFeatureFlags(p, "subgroupSupportedOperations", obj.subgroupSupportedOperations);
    p.PrintKeyBool("subgroupQuadOperationsInAllStages", static_cast<bool>(obj.subgroupQuadOperationsInAllStages));
    DumpVkPointClippingBehavior(p, "pointClippingBehavior", obj.pointClippingBehavior);
    p.PrintKeyValue("maxMultiviewViewCount", obj.maxMultiviewViewCount);
    p.PrintKeyValue("maxMultiviewInstanceIndex", obj.maxMultiviewInstanceIndex);
    p.PrintKeyBool("protectedNoFault", static_cast<bool>(obj.protectedNoFault));
    p.PrintKeyValue("maxPerSetDescriptors", obj.maxPerSetDescriptors);
    p.PrintKeyValue("maxMemoryAllocationSize", to_hex_str(p, obj.maxMemoryAllocationSize));
}
void DumpVkPhysicalDeviceVulkan12Features(Printer &p, std::string name, const VkPhysicalDeviceVulkan12Features &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(50);
    p.PrintKeyBool("samplerMirrorClampToEdge", static_cast<bool>(obj.samplerMirrorClampToEdge));
    p.PrintKeyBool("drawIndirectCount", static_cast<bool>(obj.drawIndirectCount));
    p.PrintKeyBool("storageBuffer8BitAccess", static_cast<bool>(obj.storageBuffer8BitAccess));
    p.PrintKeyBool("uniformAndStorageBuffer8BitAccess", static_cast<bool>(obj.uniformAndStorageBuffer8BitAccess));
    p.PrintKeyBool("storagePushConstant8", static_cast<bool>(obj.storagePushConstant8));
    p.PrintKeyBool("shaderBufferInt64Atomics", static_cast<bool>(obj.shaderBufferInt64Atomics));
    p.PrintKeyBool("shaderSharedInt64Atomics", static_cast<bool>(obj.shaderSharedInt64Atomics));
    p.PrintKeyBool("shaderFloat16", static_cast<bool>(obj.shaderFloat16));
    p.PrintKeyBool("shaderInt8", static_cast<bool>(obj.shaderInt8));
    p.PrintKeyBool("descriptorIndexing", static_cast<bool>(obj.descriptorIndexing));
    p.PrintKeyBool("shaderInputAttachmentArrayDynamicIndexing", static_cast<bool>(obj.shaderInputAttachmentArrayDynamicIndexing));
    p.PrintKeyBool("shaderUniformTexelBufferArrayDynamicIndexing", static_cast<bool>(obj.shaderUniformTexelBufferArrayDynamicIndexing));
    p.PrintKeyBool("shaderStorageTexelBufferArrayDynamicIndexing", static_cast<bool>(obj.shaderStorageTexelBufferArrayDynamicIndexing));
    p.PrintKeyBool("shaderUniformBufferArrayNonUniformIndexing", static_cast<bool>(obj.shaderUniformBufferArrayNonUniformIndexing));
    p.PrintKeyBool("shaderSampledImageArrayNonUniformIndexing", static_cast<bool>(obj.shaderSampledImageArrayNonUniformIndexing));
    p.PrintKeyBool("shaderStorageBufferArrayNonUniformIndexing", static_cast<bool>(obj.shaderStorageBufferArrayNonUniformIndexing));
    p.PrintKeyBool("shaderStorageImageArrayNonUniformIndexing", static_cast<bool>(obj.shaderStorageImageArrayNonUniformIndexing));
    p.PrintKeyBool("shaderInputAttachmentArrayNonUniformIndexing", static_cast<bool>(obj.shaderInputAttachmentArrayNonUniformIndexing));
    p.PrintKeyBool("shaderUniformTexelBufferArrayNonUniformIndexing", static_cast<bool>(obj.shaderUniformTexelBufferArrayNonUniformIndexing));
    p.PrintKeyBool("shaderStorageTexelBufferArrayNonUniformIndexing", static_cast<bool>(obj.shaderStorageTexelBufferArrayNonUniformIndexing));
    p.PrintKeyBool("descriptorBindingUniformBufferUpdateAfterBind", static_cast<bool>(obj.descriptorBindingUniformBufferUpdateAfterBind));
    p.PrintKeyBool("descriptorBindingSampledImageUpdateAfterBind", static_cast<bool>(obj.descriptorBindingSampledImageUpdateAfterBind));
    p.PrintKeyBool("descriptorBindingStorageImageUpdateAfterBind", static_cast<bool>(obj.descriptorBindingStorageImageUpdateAfterBind));
    p.PrintKeyBool("descriptorBindingStorageBufferUpdateAfterBind", static_cast<bool>(obj.descriptorBindingStorageBufferUpdateAfterBind));
    p.PrintKeyBool("descriptorBindingUniformTexelBufferUpdateAfterBind", static_cast<bool>(obj.descriptorBindingUniformTexelBufferUpdateAfterBind));
    p.PrintKeyBool("descriptorBindingStorageTexelBufferUpdateAfterBind", static_cast<bool>(obj.descriptorBindingStorageTexelBufferUpdateAfterBind));
    p.PrintKeyBool("descriptorBindingUpdateUnusedWhilePending", static_cast<bool>(obj.descriptorBindingUpdateUnusedWhilePending));
    p.PrintKeyBool("descriptorBindingPartiallyBound", static_cast<bool>(obj.descriptorBindingPartiallyBound));
    p.PrintKeyBool("descriptorBindingVariableDescriptorCount", static_cast<bool>(obj.descriptorBindingVariableDescriptorCount));
    p.PrintKeyBool("runtimeDescriptorArray", static_cast<bool>(obj.runtimeDescriptorArray));
    p.PrintKeyBool("samplerFilterMinmax", static_cast<bool>(obj.samplerFilterMinmax));
    p.PrintKeyBool("scalarBlockLayout", static_cast<bool>(obj.scalarBlockLayout));
    p.PrintKeyBool("imagelessFramebuffer", static_cast<bool>(obj.imagelessFramebuffer));
    p.PrintKeyBool("uniformBufferStandardLayout", static_cast<bool>(obj.uniformBufferStandardLayout));
    p.PrintKeyBool("shaderSubgroupExtendedTypes", static_cast<bool>(obj.shaderSubgroupExtendedTypes));
    p.PrintKeyBool("separateDepthStencilLayouts", static_cast<bool>(obj.separateDepthStencilLayouts));
    p.PrintKeyBool("hostQueryReset", static_cast<bool>(obj.hostQueryReset));
    p.PrintKeyBool("timelineSemaphore", static_cast<bool>(obj.timelineSemaphore));
    p.PrintKeyBool("bufferDeviceAddress", static_cast<bool>(obj.bufferDeviceAddress));
    p.PrintKeyBool("bufferDeviceAddressCaptureReplay", static_cast<bool>(obj.bufferDeviceAddressCaptureReplay));
    p.PrintKeyBool("bufferDeviceAddressMultiDevice", static_cast<bool>(obj.bufferDeviceAddressMultiDevice));
    p.PrintKeyBool("vulkanMemoryModel", static_cast<bool>(obj.vulkanMemoryModel));
    p.PrintKeyBool("vulkanMemoryModelDeviceScope", static_cast<bool>(obj.vulkanMemoryModelDeviceScope));
    p.PrintKeyBool("vulkanMemoryModelAvailabilityVisibilityChains", static_cast<bool>(obj.vulkanMemoryModelAvailabilityVisibilityChains));
    p.PrintKeyBool("shaderOutputViewportIndex", static_cast<bool>(obj.shaderOutputViewportIndex));
    p.PrintKeyBool("shaderOutputLayer", static_cast<bool>(obj.shaderOutputLayer));
    p.PrintKeyBool("subgroupBroadcastDynamicId", static_cast<bool>(obj.subgroupBroadcastDynamicId));
}
void DumpVkPhysicalDeviceVulkan12Properties(Printer &p, std::string name, const VkPhysicalDeviceVulkan12Properties &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(52);
    DumpVkDriverId(p, "driverID", obj.driverID);
    p.PrintKeyString("driverName", obj.driverName);
    p.PrintKeyString("driverInfo", obj.driverInfo);
    DumpVkConformanceVersion(p, "conformanceVersion", obj.conformanceVersion);
    DumpVkShaderFloatControlsIndependence(p, "denormBehaviorIndependence", obj.denormBehaviorIndependence);
    DumpVkShaderFloatControlsIndependence(p, "roundingModeIndependence", obj.roundingModeIndependence);
    p.PrintKeyBool("shaderSignedZeroInfNanPreserveFloat16", static_cast<bool>(obj.shaderSignedZeroInfNanPreserveFloat16));
    p.PrintKeyBool("shaderSignedZeroInfNanPreserveFloat32", static_cast<bool>(obj.shaderSignedZeroInfNanPreserveFloat32));
    p.PrintKeyBool("shaderSignedZeroInfNanPreserveFloat64", static_cast<bool>(obj.shaderSignedZeroInfNanPreserveFloat64));
    p.PrintKeyBool("shaderDenormPreserveFloat16", static_cast<bool>(obj.shaderDenormPreserveFloat16));
    p.PrintKeyBool("shaderDenormPreserveFloat32", static_cast<bool>(obj.shaderDenormPreserveFloat32));
    p.PrintKeyBool("shaderDenormPreserveFloat64", static_cast<bool>(obj.shaderDenormPreserveFloat64));
    p.PrintKeyBool("shaderDenormFlushToZeroFloat16", static_cast<bool>(obj.shaderDenormFlushToZeroFloat16));
    p.PrintKeyBool("shaderDenormFlushToZeroFloat32", static_cast<bool>(obj.shaderDenormFlushToZeroFloat32));
    p.PrintKeyBool("shaderDenormFlushToZeroFloat64", static_cast<bool>(obj.shaderDenormFlushToZeroFloat64));
    p.PrintKeyBool("shaderRoundingModeRTEFloat16", static_cast<bool>(obj.shaderRoundingModeRTEFloat16));
    p.PrintKeyBool("shaderRoundingModeRTEFloat32", static_cast<bool>(obj.shaderRoundingModeRTEFloat32));
    p.PrintKeyBool("shaderRoundingModeRTEFloat64", static_cast<bool>(obj.shaderRoundingModeRTEFloat64));
    p.PrintKeyBool("shaderRoundingModeRTZFloat16", static_cast<bool>(obj.shaderRoundingModeRTZFloat16));
    p.PrintKeyBool("shaderRoundingModeRTZFloat32", static_cast<bool>(obj.shaderRoundingModeRTZFloat32));
    p.PrintKeyBool("shaderRoundingModeRTZFloat64", static_cast<bool>(obj.shaderRoundingModeRTZFloat64));
    p.PrintKeyValue("maxUpdateAfterBindDescriptorsInAllPools", obj.maxUpdateAfterBindDescriptorsInAllPools);
    p.PrintKeyBool("shaderUniformBufferArrayNonUniformIndexingNative", static_cast<bool>(obj.shaderUniformBufferArrayNonUniformIndexingNative));
    p.PrintKeyBool("shaderSampledImageArrayNonUniformIndexingNative", static_cast<bool>(obj.shaderSampledImageArrayNonUniformIndexingNative));
    p.PrintKeyBool("shaderStorageBufferArrayNonUniformIndexingNative", static_cast<bool>(obj.shaderStorageBufferArrayNonUniformIndexingNative));
    p.PrintKeyBool("shaderStorageImageArrayNonUniformIndexingNative", static_cast<bool>(obj.shaderStorageImageArrayNonUniformIndexingNative));
    p.PrintKeyBool("shaderInputAttachmentArrayNonUniformIndexingNative", static_cast<bool>(obj.shaderInputAttachmentArrayNonUniformIndexingNative));
    p.PrintKeyBool("robustBufferAccessUpdateAfterBind", static_cast<bool>(obj.robustBufferAccessUpdateAfterBind));
    p.PrintKeyBool("quadDivergentImplicitLod", static_cast<bool>(obj.quadDivergentImplicitLod));
    p.PrintKeyValue("maxPerStageDescriptorUpdateAfterBindSamplers", obj.maxPerStageDescriptorUpdateAfterBindSamplers);
    p.PrintKeyValue("maxPerStageDescriptorUpdateAfterBindUniformBuffers", obj.maxPerStageDescriptorUpdateAfterBindUniformBuffers);
    p.PrintKeyValue("maxPerStageDescriptorUpdateAfterBindStorageBuffers", obj.maxPerStageDescriptorUpdateAfterBindStorageBuffers);
    p.PrintKeyValue("maxPerStageDescriptorUpdateAfterBindSampledImages", obj.maxPerStageDescriptorUpdateAfterBindSampledImages);
    p.PrintKeyValue("maxPerStageDescriptorUpdateAfterBindStorageImages", obj.maxPerStageDescriptorUpdateAfterBindStorageImages);
    p.PrintKeyValue("maxPerStageDescriptorUpdateAfterBindInputAttachments", obj.maxPerStageDescriptorUpdateAfterBindInputAttachments);
    p.PrintKeyValue("maxPerStageUpdateAfterBindResources", obj.maxPerStageUpdateAfterBindResources);
    p.PrintKeyValue("maxDescriptorSetUpdateAfterBindSamplers", obj.maxDescriptorSetUpdateAfterBindSamplers);
    p.PrintKeyValue("maxDescriptorSetUpdateAfterBindUniformBuffers", obj.maxDescriptorSetUpdateAfterBindUniformBuffers);
    p.PrintKeyValue("maxDescriptorSetUpdateAfterBindUniformBuffersDynamic", obj.maxDescriptorSetUpdateAfterBindUniformBuffersDynamic);
    p.PrintKeyValue("maxDescriptorSetUpdateAfterBindStorageBuffers", obj.maxDescriptorSetUpdateAfterBindStorageBuffers);
    p.PrintKeyValue("maxDescriptorSetUpdateAfterBindStorageBuffersDynamic", obj.maxDescriptorSetUpdateAfterBindStorageBuffersDynamic);
    p.PrintKeyValue("maxDescriptorSetUpdateAfterBindSampledImages", obj.maxDescriptorSetUpdateAfterBindSampledImages);
    p.PrintKeyValue("maxDescriptorSetUpdateAfterBindStorageImages", obj.maxDescriptorSetUpdateAfterBindStorageImages);
    p.PrintKeyValue("maxDescriptorSetUpdateAfterBindInputAttachments", obj.maxDescriptorSetUpdateAfterBindInputAttachments);
    DumpVkResolveModeFlags(p, "supportedDepthResolveModes", obj.supportedDepthResolveModes);
    DumpVkResolveModeFlags(p, "supportedStencilResolveModes", obj.supportedStencilResolveModes);
    p.PrintKeyBool("independentResolveNone", static_cast<bool>(obj.independentResolveNone));
    p.PrintKeyBool("independentResolve", static_cast<bool>(obj.independentResolve));
    p.PrintKeyBool("filterMinmaxSingleComponentFormats", static_cast<bool>(obj.filterMinmaxSingleComponentFormats));
    p.PrintKeyBool("filterMinmaxImageComponentMapping", static_cast<bool>(obj.filterMinmaxImageComponentMapping));
    p.PrintKeyValue("maxTimelineSemaphoreValueDifference", obj.maxTimelineSemaphoreValueDifference);
    DumpVkSampleCountFlags(p, "framebufferIntegerColorSampleCounts", obj.framebufferIntegerColorSampleCounts);
}
void DumpVkPhysicalDeviceVulkan13Features(Printer &p, std::string name, const VkPhysicalDeviceVulkan13Features &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(50);
    p.PrintKeyBool("robustImageAccess", static_cast<bool>(obj.robustImageAccess));
    p.PrintKeyBool("inlineUniformBlock", static_cast<bool>(obj.inlineUniformBlock));
    p.PrintKeyBool("descriptorBindingInlineUniformBlockUpdateAfterBind", static_cast<bool>(obj.descriptorBindingInlineUniformBlockUpdateAfterBind));
    p.PrintKeyBool("pipelineCreationCacheControl", static_cast<bool>(obj.pipelineCreationCacheControl));
    p.PrintKeyBool("privateData", static_cast<bool>(obj.privateData));
    p.PrintKeyBool("shaderDemoteToHelperInvocation", static_cast<bool>(obj.shaderDemoteToHelperInvocation));
    p.PrintKeyBool("shaderTerminateInvocation", static_cast<bool>(obj.shaderTerminateInvocation));
    p.PrintKeyBool("subgroupSizeControl", static_cast<bool>(obj.subgroupSizeControl));
    p.PrintKeyBool("computeFullSubgroups", static_cast<bool>(obj.computeFullSubgroups));
    p.PrintKeyBool("synchronization2", static_cast<bool>(obj.synchronization2));
    p.PrintKeyBool("textureCompressionASTC_HDR", static_cast<bool>(obj.textureCompressionASTC_HDR));
    p.PrintKeyBool("shaderZeroInitializeWorkgroupMemory", static_cast<bool>(obj.shaderZeroInitializeWorkgroupMemory));
    p.PrintKeyBool("dynamicRendering", static_cast<bool>(obj.dynamicRendering));
    p.PrintKeyBool("shaderIntegerDotProduct", static_cast<bool>(obj.shaderIntegerDotProduct));
    p.PrintKeyBool("maintenance4", static_cast<bool>(obj.maintenance4));
}
void DumpVkPhysicalDeviceVulkan13Properties(Printer &p, std::string name, const VkPhysicalDeviceVulkan13Properties &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(77);
    p.PrintKeyValue("minSubgroupSize", obj.minSubgroupSize);
    p.PrintKeyValue("maxSubgroupSize", obj.maxSubgroupSize);
    p.PrintKeyValue("maxComputeWorkgroupSubgroups", obj.maxComputeWorkgroupSubgroups);
    DumpVkShaderStageFlags(p, "requiredSubgroupSizeStages", obj.requiredSubgroupSizeStages);
    p.PrintKeyValue("maxInlineUniformBlockSize", obj.maxInlineUniformBlockSize);
    p.PrintKeyValue("maxPerStageDescriptorInlineUniformBlocks", obj.maxPerStageDescriptorInlineUniformBlocks);
    p.PrintKeyValue("maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks", obj.maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks);
    p.PrintKeyValue("maxDescriptorSetInlineUniformBlocks", obj.maxDescriptorSetInlineUniformBlocks);
    p.PrintKeyValue("maxDescriptorSetUpdateAfterBindInlineUniformBlocks", obj.maxDescriptorSetUpdateAfterBindInlineUniformBlocks);
    p.PrintKeyValue("maxInlineUniformTotalSize", obj.maxInlineUniformTotalSize);
    p.PrintKeyBool("integerDotProduct8BitUnsignedAccelerated", static_cast<bool>(obj.integerDotProduct8BitUnsignedAccelerated));
    p.PrintKeyBool("integerDotProduct8BitSignedAccelerated", static_cast<bool>(obj.integerDotProduct8BitSignedAccelerated));
    p.PrintKeyBool("integerDotProduct8BitMixedSignednessAccelerated", static_cast<bool>(obj.integerDotProduct8BitMixedSignednessAccelerated));
    p.PrintKeyBool("integerDotProduct4x8BitPackedUnsignedAccelerated", static_cast<bool>(obj.integerDotProduct4x8BitPackedUnsignedAccelerated));
    p.PrintKeyBool("integerDotProduct4x8BitPackedSignedAccelerated", static_cast<bool>(obj.integerDotProduct4x8BitPackedSignedAccelerated));
    p.PrintKeyBool("integerDotProduct4x8BitPackedMixedSignednessAccelerated", static_cast<bool>(obj.integerDotProduct4x8BitPackedMixedSignednessAccelerated));
    p.PrintKeyBool("integerDotProduct16BitUnsignedAccelerated", static_cast<bool>(obj.integerDotProduct16BitUnsignedAccelerated));
    p.PrintKeyBool("integerDotProduct16BitSignedAccelerated", static_cast<bool>(obj.integerDotProduct16BitSignedAccelerated));
    p.PrintKeyBool("integerDotProduct16BitMixedSignednessAccelerated", static_cast<bool>(obj.integerDotProduct16BitMixedSignednessAccelerated));
    p.PrintKeyBool("integerDotProduct32BitUnsignedAccelerated", static_cast<bool>(obj.integerDotProduct32BitUnsignedAccelerated));
    p.PrintKeyBool("integerDotProduct32BitSignedAccelerated", static_cast<bool>(obj.integerDotProduct32BitSignedAccelerated));
    p.PrintKeyBool("integerDotProduct32BitMixedSignednessAccelerated", static_cast<bool>(obj.integerDotProduct32BitMixedSignednessAccelerated));
    p.PrintKeyBool("integerDotProduct64BitUnsignedAccelerated", static_cast<bool>(obj.integerDotProduct64BitUnsignedAccelerated));
    p.PrintKeyBool("integerDotProduct64BitSignedAccelerated", static_cast<bool>(obj.integerDotProduct64BitSignedAccelerated));
    p.PrintKeyBool("integerDotProduct64BitMixedSignednessAccelerated", static_cast<bool>(obj.integerDotProduct64BitMixedSignednessAccelerated));
    p.PrintKeyBool("integerDotProductAccumulatingSaturating8BitUnsignedAccelerated", static_cast<bool>(obj.integerDotProductAccumulatingSaturating8BitUnsignedAccelerated));
    p.PrintKeyBool("integerDotProductAccumulatingSaturating8BitSignedAccelerated", static_cast<bool>(obj.integerDotProductAccumulatingSaturating8BitSignedAccelerated));
    p.PrintKeyBool("integerDotProductAccumulatingSaturating8BitMixedSignednessAccelerated", static_cast<bool>(obj.integerDotProductAccumulatingSaturating8BitMixedSignednessAccelerated));
    p.PrintKeyBool("integerDotProductAccumulatingSaturating4x8BitPackedUnsignedAccelerated", static_cast<bool>(obj.integerDotProductAccumulatingSaturating4x8BitPackedUnsignedAccelerated));
    p.PrintKeyBool("integerDotProductAccumulatingSaturating4x8BitPackedSignedAccelerated", static_cast<bool>(obj.integerDotProductAccumulatingSaturating4x8BitPackedSignedAccelerated));
    p.PrintKeyBool("integerDotProductAccumulatingSaturating4x8BitPackedMixedSignednessAccelerated", static_cast<bool>(obj.integerDotProductAccumulatingSaturating4x8BitPackedMixedSignednessAccelerated));
    p.PrintKeyBool("integerDotProductAccumulatingSaturating16BitUnsignedAccelerated", static_cast<bool>(obj.integerDotProductAccumulatingSaturating16BitUnsignedAccelerated));
    p.PrintKeyBool("integerDotProductAccumulatingSaturating16BitSignedAccelerated", static_cast<bool>(obj.integerDotProductAccumulatingSaturating16BitSignedAccelerated));
    p.PrintKeyBool("integerDotProductAccumulatingSaturating16BitMixedSignednessAccelerated", static_cast<bool>(obj.integerDotProductAccumulatingSaturating16BitMixedSignednessAccelerated));
    p.PrintKeyBool("integerDotProductAccumulatingSaturating32BitUnsignedAccelerated", static_cast<bool>(obj.integerDotProductAccumulatingSaturating32BitUnsignedAccelerated));
    p.PrintKeyBool("integerDotProductAccumulatingSaturating32BitSignedAccelerated", static_cast<bool>(obj.integerDotProductAccumulatingSaturating32BitSignedAccelerated));
    p.PrintKeyBool("integerDotProductAccumulatingSaturating32BitMixedSignednessAccelerated", static_cast<bool>(obj.integerDotProductAccumulatingSaturating32BitMixedSignednessAccelerated));
    p.PrintKeyBool("integerDotProductAccumulatingSaturating64BitUnsignedAccelerated", static_cast<bool>(obj.integerDotProductAccumulatingSaturating64BitUnsignedAccelerated));
    p.PrintKeyBool("integerDotProductAccumulatingSaturating64BitSignedAccelerated", static_cast<bool>(obj.integerDotProductAccumulatingSaturating64BitSignedAccelerated));
    p.PrintKeyBool("integerDotProductAccumulatingSaturating64BitMixedSignednessAccelerated", static_cast<bool>(obj.integerDotProductAccumulatingSaturating64BitMixedSignednessAccelerated));
    p.PrintKeyValue("storageTexelBufferOffsetAlignmentBytes", to_hex_str(p, obj.storageTexelBufferOffsetAlignmentBytes));
    p.PrintKeyBool("storageTexelBufferOffsetSingleTexelAlignment", static_cast<bool>(obj.storageTexelBufferOffsetSingleTexelAlignment));
    p.PrintKeyValue("uniformTexelBufferOffsetAlignmentBytes", to_hex_str(p, obj.uniformTexelBufferOffsetAlignmentBytes));
    p.PrintKeyBool("uniformTexelBufferOffsetSingleTexelAlignment", static_cast<bool>(obj.uniformTexelBufferOffsetSingleTexelAlignment));
    p.PrintKeyValue("maxBufferSize", to_hex_str(p, obj.maxBufferSize));
}
void DumpVkPhysicalDeviceVulkanMemoryModelFeatures(Printer &p, std::string name, const VkPhysicalDeviceVulkanMemoryModelFeatures &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(45);
    p.PrintKeyBool("vulkanMemoryModel", static_cast<bool>(obj.vulkanMemoryModel));
    p.PrintKeyBool("vulkanMemoryModelDeviceScope", static_cast<bool>(obj.vulkanMemoryModelDeviceScope));
    p.PrintKeyBool("vulkanMemoryModelAvailabilityVisibilityChains", static_cast<bool>(obj.vulkanMemoryModelAvailabilityVisibilityChains));
}
void DumpVkPhysicalDeviceVulkanSC10Features(Printer &p, std::string name, const VkPhysicalDeviceVulkanSC10Features &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(24);
    p.PrintKeyBool("shaderAtomicInstructions", static_cast<bool>(obj.shaderAtomicInstructions));
}
void DumpVkPhysicalDeviceVulkanSC10Properties(Printer &p, std::string name, const VkPhysicalDeviceVulkanSC10Properties &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(48);
    p.PrintKeyBool("deviceNoDynamicHostAllocations", static_cast<bool>(obj.deviceNoDynamicHostAllocations));
    p.PrintKeyBool("deviceDestroyFreesMemory", static_cast<bool>(obj.deviceDestroyFreesMemory));
    p.PrintKeyBool("commandPoolMultipleCommandBuffersRecording", static_cast<bool>(obj.commandPoolMultipleCommandBuffersRecording));
    p.PrintKeyBool("commandPoolResetCommandBuffer", static_cast<bool>(obj.commandPoolResetCommandBuffer));
    p.PrintKeyBool("commandBufferSimultaneousUse", static_cast<bool>(obj.commandBufferSimultaneousUse));
    p.PrintKeyBool("secondaryCommandBufferNullOrImagelessFramebuffer", static_cast<bool>(obj.secondaryCommandBufferNullOrImagelessFramebuffer));
    p.PrintKeyBool("recycleDescriptorSetMemory", static_cast<bool>(obj.recycleDescriptorSetMemory));
    p.PrintKeyBool("recyclePipelineMemory", static_cast<bool>(obj.recyclePipelineMemory));
    p.PrintKeyValue("maxRenderPassSubpasses", obj.maxRenderPassSubpasses);
    p.PrintKeyValue("maxRenderPassDependencies", obj.maxRenderPassDependencies);
    p.PrintKeyValue("maxSubpassInputAttachments", obj.maxSubpassInputAttachments);
    p.PrintKeyValue("maxSubpassPreserveAttachments", obj.maxSubpassPreserveAttachments);
    p.PrintKeyValue("maxFramebufferAttachments", obj.maxFramebufferAttachments);
    p.PrintKeyValue("maxDescriptorSetLayoutBindings", obj.maxDescriptorSetLayoutBindings);
    p.PrintKeyValue("maxQueryFaultCount", obj.maxQueryFaultCount);
    p.PrintKeyValue("maxCallbackFaultCount", obj.maxCallbackFaultCount);
    p.PrintKeyValue("maxCommandPoolCommandBuffers", obj.maxCommandPoolCommandBuffers);
    p.PrintKeyValue("maxCommandBufferSize", to_hex_str(p, obj.maxCommandBufferSize));
}
void DumpVkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT(Printer &p, std::string name, const VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(21);
    p.PrintKeyBool("ycbcr2plane444Formats", static_cast<bool>(obj.ycbcr2plane444Formats));
}
void DumpVkPhysicalDeviceYcbcrImageArraysFeaturesEXT(Printer &p, std::string name, const VkPhysicalDeviceYcbcrImageArraysFeaturesEXT &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(16);
    p.PrintKeyBool("ycbcrImageArrays", static_cast<bool>(obj.ycbcrImageArrays));
}
void DumpVkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures(Printer &p, std::string name, const VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(35);
    p.PrintKeyBool("shaderZeroInitializeWorkgroupMemory", static_cast<bool>(obj.shaderZeroInitializeWorkgroupMemory));
}
void DumpVkQueueFamilyGlobalPriorityPropertiesKHR(Printer &p, std::string name, const VkQueueFamilyGlobalPriorityPropertiesKHR &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(14);
    p.PrintKeyValue("priorityCount", obj.priorityCount);
    ArrayWrapper arr(p,"priorities", obj.priorityCount);
    for (uint32_t i = 0; i < obj.priorityCount; i++) {
       if (p.Type() == OutputType::json)
           p.PrintString(std::string("VK_") + VkQueueGlobalPriorityKHRString(obj.priorities[i]));
       else
           p.PrintString(VkQueueGlobalPriorityKHRString(obj.priorities[i]));
    }
}
void DumpVkSharedPresentSurfaceCapabilitiesKHR(Printer &p, std::string name, const VkSharedPresentSurfaceCapabilitiesKHR &obj) {
    ObjectWrapper object{p, name};
    DumpVkImageUsageFlags(p, "sharedPresentSupportedUsageFlags", obj.sharedPresentSupportedUsageFlags);
}
void DumpVkSurfaceCapabilitiesKHR(Printer &p, std::string name, const VkSurfaceCapabilitiesKHR &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(19);
    p.PrintKeyValue("minImageCount", obj.minImageCount);
    p.PrintKeyValue("maxImageCount", obj.maxImageCount);
    DumpVkExtent2D(p, "currentExtent", obj.currentExtent);
    DumpVkExtent2D(p, "minImageExtent", obj.minImageExtent);
    DumpVkExtent2D(p, "maxImageExtent", obj.maxImageExtent);
    p.PrintKeyValue("maxImageArrayLayers", obj.maxImageArrayLayers);
    DumpVkSurfaceTransformFlagsKHR(p, "supportedTransforms", obj.supportedTransforms);
    DumpVkSurfaceTransformFlagBitsKHR(p, "currentTransform", obj.currentTransform);
    DumpVkCompositeAlphaFlagsKHR(p, "supportedCompositeAlpha", obj.supportedCompositeAlpha);
    DumpVkImageUsageFlags(p, "supportedUsageFlags", obj.supportedUsageFlags);
}
void DumpVkSurfaceFormatKHR(Printer &p, std::string name, const VkSurfaceFormatKHR &obj) {
    ObjectWrapper object{p, name};
    DumpVkFormat(p, "format", obj.format);
    DumpVkColorSpaceKHR(p, "colorSpace", obj.colorSpace);
}
struct phys_device_props2_chain {
    phys_device_props2_chain() = default;
    phys_device_props2_chain(const phys_device_props2_chain &) = delete;
    phys_device_props2_chain& operator=(const phys_device_props2_chain &) = delete;
    phys_device_props2_chain(phys_device_props2_chain &&) = delete;
    phys_device_props2_chain& operator=(phys_device_props2_chain &&) = delete;
    void* start_of_chain = nullptr;
    VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT PhysicalDeviceBlendOperationAdvancedPropertiesEXT{};
    VkPhysicalDeviceConservativeRasterizationPropertiesEXT PhysicalDeviceConservativeRasterizationPropertiesEXT{};
    VkPhysicalDeviceCustomBorderColorPropertiesEXT PhysicalDeviceCustomBorderColorPropertiesEXT{};
    VkPhysicalDeviceDepthStencilResolveProperties PhysicalDeviceDepthStencilResolveProperties{};
    VkPhysicalDeviceDescriptorIndexingProperties PhysicalDeviceDescriptorIndexingProperties{};
    VkPhysicalDeviceDiscardRectanglePropertiesEXT PhysicalDeviceDiscardRectanglePropertiesEXT{};
    VkPhysicalDeviceDriverProperties PhysicalDeviceDriverProperties{};
    VkPhysicalDeviceExternalMemoryHostPropertiesEXT PhysicalDeviceExternalMemoryHostPropertiesEXT{};
    VkPhysicalDeviceFloatControlsProperties PhysicalDeviceFloatControlsProperties{};
    VkPhysicalDeviceFragmentShadingRatePropertiesKHR PhysicalDeviceFragmentShadingRatePropertiesKHR{};
    VkPhysicalDeviceIDProperties PhysicalDeviceIDProperties{};
    VkPhysicalDeviceInlineUniformBlockProperties PhysicalDeviceInlineUniformBlockProperties{};
    VkPhysicalDeviceLineRasterizationPropertiesKHR PhysicalDeviceLineRasterizationPropertiesKHR{};
    VkPhysicalDeviceMaintenance3Properties PhysicalDeviceMaintenance3Properties{};
    VkPhysicalDeviceMaintenance4Properties PhysicalDeviceMaintenance4Properties{};
    VkPhysicalDeviceMultiviewProperties PhysicalDeviceMultiviewProperties{};
    VkPhysicalDevicePCIBusInfoPropertiesEXT PhysicalDevicePCIBusInfoPropertiesEXT{};
    VkPhysicalDevicePerformanceQueryPropertiesKHR PhysicalDevicePerformanceQueryPropertiesKHR{};
    VkPhysicalDevicePointClippingProperties PhysicalDevicePointClippingProperties{};
    VkPhysicalDeviceProtectedMemoryProperties PhysicalDeviceProtectedMemoryProperties{};
    VkPhysicalDeviceRobustness2PropertiesEXT PhysicalDeviceRobustness2PropertiesEXT{};
    VkPhysicalDeviceSampleLocationsPropertiesEXT PhysicalDeviceSampleLocationsPropertiesEXT{};
    VkPhysicalDeviceSamplerFilterMinmaxProperties PhysicalDeviceSamplerFilterMinmaxProperties{};
    VkPhysicalDeviceShaderIntegerDotProductProperties PhysicalDeviceShaderIntegerDotProductProperties{};
    VkPhysicalDeviceSubgroupProperties PhysicalDeviceSubgroupProperties{};
    VkPhysicalDeviceSubgroupSizeControlProperties PhysicalDeviceSubgroupSizeControlProperties{};
    VkPhysicalDeviceTexelBufferAlignmentProperties PhysicalDeviceTexelBufferAlignmentProperties{};
    VkPhysicalDeviceTimelineSemaphoreProperties PhysicalDeviceTimelineSemaphoreProperties{};
    VkPhysicalDeviceVertexAttributeDivisorPropertiesKHR PhysicalDeviceVertexAttributeDivisorPropertiesKHR{};
    VkPhysicalDeviceVulkan11Properties PhysicalDeviceVulkan11Properties{};
    VkPhysicalDeviceVulkan12Properties PhysicalDeviceVulkan12Properties{};
    VkPhysicalDeviceVulkan13Properties PhysicalDeviceVulkan13Properties{};
    VkPhysicalDeviceVulkanSC10Properties PhysicalDeviceVulkanSC10Properties{};
    void initialize_chain(AppInstance &inst, AppGpu &gpu ) noexcept {
        PhysicalDeviceBlendOperationAdvancedPropertiesEXT.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT;
        PhysicalDeviceConservativeRasterizationPropertiesEXT.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT;
        PhysicalDeviceCustomBorderColorPropertiesEXT.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_PROPERTIES_EXT;
        PhysicalDeviceDepthStencilResolveProperties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES;
        PhysicalDeviceDescriptorIndexingProperties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES;
        PhysicalDeviceDiscardRectanglePropertiesEXT.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT;
        PhysicalDeviceDriverProperties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES;
        PhysicalDeviceExternalMemoryHostPropertiesEXT.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT;
        PhysicalDeviceFloatControlsProperties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES;
        PhysicalDeviceFragmentShadingRatePropertiesKHR.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_PROPERTIES_KHR;
        PhysicalDeviceIDProperties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES;
        PhysicalDeviceInlineUniformBlockProperties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES;
        PhysicalDeviceLineRasterizationPropertiesKHR.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_PROPERTIES_KHR;
        PhysicalDeviceMaintenance3Properties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES;
        PhysicalDeviceMaintenance4Properties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_PROPERTIES;
        PhysicalDeviceMultiviewProperties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES;
        PhysicalDevicePCIBusInfoPropertiesEXT.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT;
        PhysicalDevicePerformanceQueryPropertiesKHR.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_PROPERTIES_KHR;
        PhysicalDevicePointClippingProperties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES;
        PhysicalDeviceProtectedMemoryProperties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES;
        PhysicalDeviceRobustness2PropertiesEXT.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_PROPERTIES_EXT;
        PhysicalDeviceSampleLocationsPropertiesEXT.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT;
        PhysicalDeviceSamplerFilterMinmaxProperties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES;
        PhysicalDeviceShaderIntegerDotProductProperties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_PROPERTIES;
        PhysicalDeviceSubgroupProperties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES;
        PhysicalDeviceSubgroupSizeControlProperties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_PROPERTIES;
        PhysicalDeviceTexelBufferAlignmentProperties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES;
        PhysicalDeviceTimelineSemaphoreProperties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES;
        PhysicalDeviceVertexAttributeDivisorPropertiesKHR.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_KHR;
        PhysicalDeviceVulkan11Properties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES;
        PhysicalDeviceVulkan12Properties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES;
        PhysicalDeviceVulkan13Properties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES;
        PhysicalDeviceVulkanSC10Properties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_SC_1_0_PROPERTIES;
        std::vector<VkBaseOutStructure*> chain_members{};
        if (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_BLEND_OPERATION_ADVANCED_EXTENSION_NAME))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceBlendOperationAdvancedPropertiesEXT));
        if (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_CONSERVATIVE_RASTERIZATION_EXTENSION_NAME))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceConservativeRasterizationPropertiesEXT));
        if (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_CUSTOM_BORDER_COLOR_EXTENSION_NAME))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceCustomBorderColorPropertiesEXT));
        if (gpu.api_version >= VK_API_VERSION_1_2)
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceDepthStencilResolveProperties));
        if (gpu.api_version >= VK_API_VERSION_1_2)
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceDescriptorIndexingProperties));
        if (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_DISCARD_RECTANGLES_EXTENSION_NAME))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceDiscardRectanglePropertiesEXT));
        if (gpu.api_version >= VK_API_VERSION_1_2)
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceDriverProperties));
        if (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_EXTERNAL_MEMORY_HOST_EXTENSION_NAME))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceExternalMemoryHostPropertiesEXT));
        if (gpu.api_version >= VK_API_VERSION_1_2)
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceFloatControlsProperties));
        if (gpu.CheckPhysicalDeviceExtensionIncluded(VK_KHR_FRAGMENT_SHADING_RATE_EXTENSION_NAME))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceFragmentShadingRatePropertiesKHR));
        if (gpu.api_version >= VK_API_VERSION_1_1)
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceIDProperties));
        if (gpu.api_version >= VK_API_VERSION_1_3)
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceInlineUniformBlockProperties));
        if (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_LINE_RASTERIZATION_EXTENSION_NAME)
         || gpu.CheckPhysicalDeviceExtensionIncluded(VK_KHR_LINE_RASTERIZATION_EXTENSION_NAME))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceLineRasterizationPropertiesKHR));
        if (gpu.api_version >= VK_API_VERSION_1_1)
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceMaintenance3Properties));
        if (gpu.api_version >= VK_API_VERSION_1_3)
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceMaintenance4Properties));
        if (gpu.api_version >= VK_API_VERSION_1_1)
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceMultiviewProperties));
        if (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_PCI_BUS_INFO_EXTENSION_NAME))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDevicePCIBusInfoPropertiesEXT));
        if (gpu.CheckPhysicalDeviceExtensionIncluded(VK_KHR_PERFORMANCE_QUERY_EXTENSION_NAME))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDevicePerformanceQueryPropertiesKHR));
        if (gpu.api_version >= VK_API_VERSION_1_1)
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDevicePointClippingProperties));
        if (gpu.api_version == VK_API_VERSION_1_1)
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceProtectedMemoryProperties));
        if (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_ROBUSTNESS_2_EXTENSION_NAME))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceRobustness2PropertiesEXT));
        if (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_SAMPLE_LOCATIONS_EXTENSION_NAME))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceSampleLocationsPropertiesEXT));
        if (gpu.api_version >= VK_API_VERSION_1_2)
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceSamplerFilterMinmaxProperties));
        if (gpu.api_version >= VK_API_VERSION_1_3)
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceShaderIntegerDotProductProperties));
        if (gpu.api_version == VK_API_VERSION_1_1)
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceSubgroupProperties));
        if ((gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_SUBGROUP_SIZE_CONTROL_EXTENSION_NAME))
            && gpu.api_version < VK_API_VERSION_1_3)
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceSubgroupSizeControlProperties));
        if ((gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_TEXEL_BUFFER_ALIGNMENT_EXTENSION_NAME))
            && gpu.api_version < VK_API_VERSION_1_3)
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceTexelBufferAlignmentProperties));
        if (gpu.api_version >= VK_API_VERSION_1_2)
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceTimelineSemaphoreProperties));
        if (gpu.CheckPhysicalDeviceExtensionIncluded(VK_KHR_VERTEX_ATTRIBUTE_DIVISOR_EXTENSION_NAME))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceVertexAttributeDivisorPropertiesKHR));
        if (gpu.api_version >= VK_API_VERSION_1_2)
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceVulkan11Properties));
        if (gpu.api_version >= VK_API_VERSION_1_2)
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceVulkan12Properties));
        if (gpu.api_version >= VK_API_VERSION_1_3)
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceVulkan13Properties));
        if (gpu.api_version >= VKSC_API_VERSION_1_0)
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceVulkanSC10Properties));

        if (!chain_members.empty()) {
            for(size_t i = 0; i < chain_members.size() - 1; i++){
                chain_members[i]->pNext = chain_members[i + 1];
            }
            start_of_chain = chain_members[0];
        }
    }
};
void setup_phys_device_props2_chain(VkPhysicalDeviceProperties2& start, std::unique_ptr<phys_device_props2_chain>& chain, AppInstance &inst,AppGpu &gpu){
    chain = std::unique_ptr<phys_device_props2_chain>(new phys_device_props2_chain());
    chain->initialize_chain(inst,gpu);
    start.pNext = chain->start_of_chain;
};

void chain_iterator_phys_device_props2(Printer &p, AppInstance &inst, AppGpu &gpu, void * place) {
    while (place) {
        struct VkBaseOutStructure *structure = (struct VkBaseOutStructure *)place;
        p.SetSubHeader();
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT &&
           (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_BLEND_OPERATION_ADVANCED_EXTENSION_NAME))) {
            VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT* props = (VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT*)structure;
            DumpVkPhysicalDeviceBlendOperationAdvancedPropertiesEXT(p, "VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT &&
           (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_CONSERVATIVE_RASTERIZATION_EXTENSION_NAME))) {
            VkPhysicalDeviceConservativeRasterizationPropertiesEXT* props = (VkPhysicalDeviceConservativeRasterizationPropertiesEXT*)structure;
            DumpVkPhysicalDeviceConservativeRasterizationPropertiesEXT(p, "VkPhysicalDeviceConservativeRasterizationPropertiesEXT", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_PROPERTIES_EXT &&
           (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_CUSTOM_BORDER_COLOR_EXTENSION_NAME))) {
            VkPhysicalDeviceCustomBorderColorPropertiesEXT* props = (VkPhysicalDeviceCustomBorderColorPropertiesEXT*)structure;
            DumpVkPhysicalDeviceCustomBorderColorPropertiesEXT(p, "VkPhysicalDeviceCustomBorderColorPropertiesEXT", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES &&
           (gpu.api_version >= VK_API_VERSION_1_2)) {
            VkPhysicalDeviceDepthStencilResolveProperties* props = (VkPhysicalDeviceDepthStencilResolveProperties*)structure;
            DumpVkPhysicalDeviceDepthStencilResolveProperties(p, "VkPhysicalDeviceDepthStencilResolveProperties", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES &&
           (gpu.api_version >= VK_API_VERSION_1_2)) {
            VkPhysicalDeviceDescriptorIndexingProperties* props = (VkPhysicalDeviceDescriptorIndexingProperties*)structure;
            DumpVkPhysicalDeviceDescriptorIndexingProperties(p, "VkPhysicalDeviceDescriptorIndexingProperties", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT &&
           (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_DISCARD_RECTANGLES_EXTENSION_NAME))) {
            VkPhysicalDeviceDiscardRectanglePropertiesEXT* props = (VkPhysicalDeviceDiscardRectanglePropertiesEXT*)structure;
            DumpVkPhysicalDeviceDiscardRectanglePropertiesEXT(p, "VkPhysicalDeviceDiscardRectanglePropertiesEXT", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES &&
           (gpu.api_version >= VK_API_VERSION_1_2)) {
            VkPhysicalDeviceDriverProperties* props = (VkPhysicalDeviceDriverProperties*)structure;
            DumpVkPhysicalDeviceDriverProperties(p, "VkPhysicalDeviceDriverProperties", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT &&
           (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_EXTERNAL_MEMORY_HOST_EXTENSION_NAME))) {
            VkPhysicalDeviceExternalMemoryHostPropertiesEXT* props = (VkPhysicalDeviceExternalMemoryHostPropertiesEXT*)structure;
            DumpVkPhysicalDeviceExternalMemoryHostPropertiesEXT(p, "VkPhysicalDeviceExternalMemoryHostPropertiesEXT", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES &&
           (gpu.api_version >= VK_API_VERSION_1_2)) {
            VkPhysicalDeviceFloatControlsProperties* props = (VkPhysicalDeviceFloatControlsProperties*)structure;
            DumpVkPhysicalDeviceFloatControlsProperties(p, "VkPhysicalDeviceFloatControlsProperties", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_PROPERTIES_KHR &&
           (gpu.CheckPhysicalDeviceExtensionIncluded(VK_KHR_FRAGMENT_SHADING_RATE_EXTENSION_NAME))) {
            VkPhysicalDeviceFragmentShadingRatePropertiesKHR* props = (VkPhysicalDeviceFragmentShadingRatePropertiesKHR*)structure;
            DumpVkPhysicalDeviceFragmentShadingRatePropertiesKHR(p, "VkPhysicalDeviceFragmentShadingRatePropertiesKHR", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES &&
           (gpu.api_version >= VK_API_VERSION_1_1)) {
            VkPhysicalDeviceIDProperties* props = (VkPhysicalDeviceIDProperties*)structure;
            DumpVkPhysicalDeviceIDProperties(p, "VkPhysicalDeviceIDProperties", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES &&
           (gpu.api_version >= VK_API_VERSION_1_3)) {
            VkPhysicalDeviceInlineUniformBlockProperties* props = (VkPhysicalDeviceInlineUniformBlockProperties*)structure;
            DumpVkPhysicalDeviceInlineUniformBlockProperties(p, "VkPhysicalDeviceInlineUniformBlockProperties", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_PROPERTIES_KHR &&
           (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_LINE_RASTERIZATION_EXTENSION_NAME) || gpu.CheckPhysicalDeviceExtensionIncluded(VK_KHR_LINE_RASTERIZATION_EXTENSION_NAME))) {
            VkPhysicalDeviceLineRasterizationPropertiesKHR* props = (VkPhysicalDeviceLineRasterizationPropertiesKHR*)structure;
            DumpVkPhysicalDeviceLineRasterizationPropertiesKHR(p, "VkPhysicalDeviceLineRasterizationPropertiesKHR", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES &&
           (gpu.api_version >= VK_API_VERSION_1_1)) {
            VkPhysicalDeviceMaintenance3Properties* props = (VkPhysicalDeviceMaintenance3Properties*)structure;
            DumpVkPhysicalDeviceMaintenance3Properties(p, "VkPhysicalDeviceMaintenance3Properties", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_PROPERTIES &&
           (gpu.api_version >= VK_API_VERSION_1_3)) {
            VkPhysicalDeviceMaintenance4Properties* props = (VkPhysicalDeviceMaintenance4Properties*)structure;
            DumpVkPhysicalDeviceMaintenance4Properties(p, "VkPhysicalDeviceMaintenance4Properties", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES &&
           (gpu.api_version >= VK_API_VERSION_1_1)) {
            VkPhysicalDeviceMultiviewProperties* props = (VkPhysicalDeviceMultiviewProperties*)structure;
            DumpVkPhysicalDeviceMultiviewProperties(p, "VkPhysicalDeviceMultiviewProperties", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT &&
           (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_PCI_BUS_INFO_EXTENSION_NAME))) {
            VkPhysicalDevicePCIBusInfoPropertiesEXT* props = (VkPhysicalDevicePCIBusInfoPropertiesEXT*)structure;
            DumpVkPhysicalDevicePCIBusInfoPropertiesEXT(p, "VkPhysicalDevicePCIBusInfoPropertiesEXT", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_PROPERTIES_KHR &&
           (gpu.CheckPhysicalDeviceExtensionIncluded(VK_KHR_PERFORMANCE_QUERY_EXTENSION_NAME))) {
            VkPhysicalDevicePerformanceQueryPropertiesKHR* props = (VkPhysicalDevicePerformanceQueryPropertiesKHR*)structure;
            DumpVkPhysicalDevicePerformanceQueryPropertiesKHR(p, "VkPhysicalDevicePerformanceQueryPropertiesKHR", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES &&
           (gpu.api_version >= VK_API_VERSION_1_1)) {
            VkPhysicalDevicePointClippingProperties* props = (VkPhysicalDevicePointClippingProperties*)structure;
            DumpVkPhysicalDevicePointClippingProperties(p, "VkPhysicalDevicePointClippingProperties", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES &&
           (gpu.api_version == VK_API_VERSION_1_1)) {
            VkPhysicalDeviceProtectedMemoryProperties* props = (VkPhysicalDeviceProtectedMemoryProperties*)structure;
            DumpVkPhysicalDeviceProtectedMemoryProperties(p, "VkPhysicalDeviceProtectedMemoryProperties", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_PROPERTIES_EXT &&
           (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_ROBUSTNESS_2_EXTENSION_NAME))) {
            VkPhysicalDeviceRobustness2PropertiesEXT* props = (VkPhysicalDeviceRobustness2PropertiesEXT*)structure;
            DumpVkPhysicalDeviceRobustness2PropertiesEXT(p, "VkPhysicalDeviceRobustness2PropertiesEXT", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT &&
           (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_SAMPLE_LOCATIONS_EXTENSION_NAME))) {
            VkPhysicalDeviceSampleLocationsPropertiesEXT* props = (VkPhysicalDeviceSampleLocationsPropertiesEXT*)structure;
            DumpVkPhysicalDeviceSampleLocationsPropertiesEXT(p, "VkPhysicalDeviceSampleLocationsPropertiesEXT", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES &&
           (gpu.api_version >= VK_API_VERSION_1_2)) {
            VkPhysicalDeviceSamplerFilterMinmaxProperties* props = (VkPhysicalDeviceSamplerFilterMinmaxProperties*)structure;
            DumpVkPhysicalDeviceSamplerFilterMinmaxProperties(p, "VkPhysicalDeviceSamplerFilterMinmaxProperties", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_PROPERTIES &&
           (gpu.api_version >= VK_API_VERSION_1_3)) {
            VkPhysicalDeviceShaderIntegerDotProductProperties* props = (VkPhysicalDeviceShaderIntegerDotProductProperties*)structure;
            DumpVkPhysicalDeviceShaderIntegerDotProductProperties(p, "VkPhysicalDeviceShaderIntegerDotProductProperties", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES &&
           (gpu.api_version == VK_API_VERSION_1_1)) {
            VkPhysicalDeviceSubgroupProperties* props = (VkPhysicalDeviceSubgroupProperties*)structure;
            DumpVkPhysicalDeviceSubgroupProperties(p, "VkPhysicalDeviceSubgroupProperties", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_PROPERTIES &&
           ((gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_SUBGROUP_SIZE_CONTROL_EXTENSION_NAME)) &&
            gpu.api_version < VK_API_VERSION_1_3)) {
            VkPhysicalDeviceSubgroupSizeControlProperties* props = (VkPhysicalDeviceSubgroupSizeControlProperties*)structure;
            DumpVkPhysicalDeviceSubgroupSizeControlProperties(p, gpu.api_version >= VK_API_VERSION_1_3 ?"VkPhysicalDeviceSubgroupSizeControlProperties":"VkPhysicalDeviceSubgroupSizeControlPropertiesEXT", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES &&
           ((gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_TEXEL_BUFFER_ALIGNMENT_EXTENSION_NAME)) &&
            gpu.api_version < VK_API_VERSION_1_3)) {
            VkPhysicalDeviceTexelBufferAlignmentProperties* props = (VkPhysicalDeviceTexelBufferAlignmentProperties*)structure;
            DumpVkPhysicalDeviceTexelBufferAlignmentProperties(p, gpu.api_version >= VK_API_VERSION_1_3 ?"VkPhysicalDeviceTexelBufferAlignmentProperties":"VkPhysicalDeviceTexelBufferAlignmentPropertiesEXT", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES &&
           (gpu.api_version >= VK_API_VERSION_1_2)) {
            VkPhysicalDeviceTimelineSemaphoreProperties* props = (VkPhysicalDeviceTimelineSemaphoreProperties*)structure;
            DumpVkPhysicalDeviceTimelineSemaphoreProperties(p, "VkPhysicalDeviceTimelineSemaphoreProperties", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_KHR &&
           (gpu.CheckPhysicalDeviceExtensionIncluded(VK_KHR_VERTEX_ATTRIBUTE_DIVISOR_EXTENSION_NAME))) {
            VkPhysicalDeviceVertexAttributeDivisorPropertiesKHR* props = (VkPhysicalDeviceVertexAttributeDivisorPropertiesKHR*)structure;
            DumpVkPhysicalDeviceVertexAttributeDivisorPropertiesKHR(p, "VkPhysicalDeviceVertexAttributeDivisorPropertiesKHR", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES &&
           (gpu.api_version >= VK_API_VERSION_1_2)) {
            VkPhysicalDeviceVulkan11Properties* props = (VkPhysicalDeviceVulkan11Properties*)structure;
            DumpVkPhysicalDeviceVulkan11Properties(p, "VkPhysicalDeviceVulkan11Properties", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES &&
           (gpu.api_version >= VK_API_VERSION_1_2)) {
            VkPhysicalDeviceVulkan12Properties* props = (VkPhysicalDeviceVulkan12Properties*)structure;
            DumpVkPhysicalDeviceVulkan12Properties(p, "VkPhysicalDeviceVulkan12Properties", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES &&
           (gpu.api_version >= VK_API_VERSION_1_3)) {
            VkPhysicalDeviceVulkan13Properties* props = (VkPhysicalDeviceVulkan13Properties*)structure;
            DumpVkPhysicalDeviceVulkan13Properties(p, "VkPhysicalDeviceVulkan13Properties", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_SC_1_0_PROPERTIES &&
           (gpu.api_version >= VKSC_API_VERSION_1_0)) {
            VkPhysicalDeviceVulkanSC10Properties* props = (VkPhysicalDeviceVulkanSC10Properties*)structure;
            DumpVkPhysicalDeviceVulkanSC10Properties(p, "VkPhysicalDeviceVulkanSC10Properties", *props);
            p.AddNewline();
        }
        place = structure->pNext;
    }
}
struct phys_device_mem_props2_chain {
    phys_device_mem_props2_chain() = default;
    phys_device_mem_props2_chain(const phys_device_mem_props2_chain &) = delete;
    phys_device_mem_props2_chain& operator=(const phys_device_mem_props2_chain &) = delete;
    phys_device_mem_props2_chain(phys_device_mem_props2_chain &&) = delete;
    phys_device_mem_props2_chain& operator=(phys_device_mem_props2_chain &&) = delete;
    void* start_of_chain = nullptr;
    VkPhysicalDeviceMemoryBudgetPropertiesEXT PhysicalDeviceMemoryBudgetPropertiesEXT{};
    void initialize_chain(AppGpu &gpu ) noexcept {
        PhysicalDeviceMemoryBudgetPropertiesEXT.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_BUDGET_PROPERTIES_EXT;
        std::vector<VkBaseOutStructure*> chain_members{};
        if (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_MEMORY_BUDGET_EXTENSION_NAME))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceMemoryBudgetPropertiesEXT));

        if (!chain_members.empty()) {
            for(size_t i = 0; i < chain_members.size() - 1; i++){
                chain_members[i]->pNext = chain_members[i + 1];
            }
            start_of_chain = chain_members[0];
        }
    }
};
void setup_phys_device_mem_props2_chain(VkPhysicalDeviceMemoryProperties2& start, std::unique_ptr<phys_device_mem_props2_chain>& chain, AppGpu &gpu){
    chain = std::unique_ptr<phys_device_mem_props2_chain>(new phys_device_mem_props2_chain());
    chain->initialize_chain(gpu);
    start.pNext = chain->start_of_chain;
};
struct phys_device_features2_chain {
    phys_device_features2_chain() = default;
    phys_device_features2_chain(const phys_device_features2_chain &) = delete;
    phys_device_features2_chain& operator=(const phys_device_features2_chain &) = delete;
    phys_device_features2_chain(phys_device_features2_chain &&) = delete;
    phys_device_features2_chain& operator=(phys_device_features2_chain &&) = delete;
    void* start_of_chain = nullptr;
    VkPhysicalDevice16BitStorageFeatures PhysicalDevice16BitStorageFeatures{};
    VkPhysicalDevice4444FormatsFeaturesEXT PhysicalDevice4444FormatsFeaturesEXT{};
    VkPhysicalDevice8BitStorageFeatures PhysicalDevice8BitStorageFeatures{};
    VkPhysicalDeviceASTCDecodeFeaturesEXT PhysicalDeviceASTCDecodeFeaturesEXT{};
    VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT PhysicalDeviceBlendOperationAdvancedFeaturesEXT{};
    VkPhysicalDeviceBufferDeviceAddressFeatures PhysicalDeviceBufferDeviceAddressFeatures{};
    VkPhysicalDeviceColorWriteEnableFeaturesEXT PhysicalDeviceColorWriteEnableFeaturesEXT{};
    VkPhysicalDeviceCustomBorderColorFeaturesEXT PhysicalDeviceCustomBorderColorFeaturesEXT{};
    VkPhysicalDeviceDepthClipEnableFeaturesEXT PhysicalDeviceDepthClipEnableFeaturesEXT{};
    VkPhysicalDeviceDescriptorIndexingFeatures PhysicalDeviceDescriptorIndexingFeatures{};
    VkPhysicalDeviceDynamicRenderingFeatures PhysicalDeviceDynamicRenderingFeatures{};
    VkPhysicalDeviceExtendedDynamicState2FeaturesEXT PhysicalDeviceExtendedDynamicState2FeaturesEXT{};
    VkPhysicalDeviceExtendedDynamicStateFeaturesEXT PhysicalDeviceExtendedDynamicStateFeaturesEXT{};
    VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT PhysicalDeviceFragmentShaderInterlockFeaturesEXT{};
    VkPhysicalDeviceFragmentShadingRateFeaturesKHR PhysicalDeviceFragmentShadingRateFeaturesKHR{};
    VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR PhysicalDeviceGlobalPriorityQueryFeaturesKHR{};
    VkPhysicalDeviceHostQueryResetFeatures PhysicalDeviceHostQueryResetFeatures{};
    VkPhysicalDeviceImageRobustnessFeatures PhysicalDeviceImageRobustnessFeatures{};
    VkPhysicalDeviceImagelessFramebufferFeatures PhysicalDeviceImagelessFramebufferFeatures{};
    VkPhysicalDeviceIndexTypeUint8FeaturesKHR PhysicalDeviceIndexTypeUint8FeaturesKHR{};
    VkPhysicalDeviceInlineUniformBlockFeatures PhysicalDeviceInlineUniformBlockFeatures{};
    VkPhysicalDeviceLineRasterizationFeaturesKHR PhysicalDeviceLineRasterizationFeaturesKHR{};
    VkPhysicalDeviceMaintenance4Features PhysicalDeviceMaintenance4Features{};
    VkPhysicalDeviceMultiviewFeatures PhysicalDeviceMultiviewFeatures{};
    VkPhysicalDevicePerformanceQueryFeaturesKHR PhysicalDevicePerformanceQueryFeaturesKHR{};
    VkPhysicalDevicePipelineCreationCacheControlFeatures PhysicalDevicePipelineCreationCacheControlFeatures{};
    VkPhysicalDevicePrivateDataFeatures PhysicalDevicePrivateDataFeatures{};
    VkPhysicalDeviceProtectedMemoryFeatures PhysicalDeviceProtectedMemoryFeatures{};
    VkPhysicalDeviceRobustness2FeaturesEXT PhysicalDeviceRobustness2FeaturesEXT{};
    VkPhysicalDeviceSamplerYcbcrConversionFeatures PhysicalDeviceSamplerYcbcrConversionFeatures{};
    VkPhysicalDeviceScalarBlockLayoutFeatures PhysicalDeviceScalarBlockLayoutFeatures{};
    VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures PhysicalDeviceSeparateDepthStencilLayoutsFeatures{};
    VkPhysicalDeviceShaderAtomicFloatFeaturesEXT PhysicalDeviceShaderAtomicFloatFeaturesEXT{};
    VkPhysicalDeviceShaderAtomicInt64Features PhysicalDeviceShaderAtomicInt64Features{};
    VkPhysicalDeviceShaderClockFeaturesKHR PhysicalDeviceShaderClockFeaturesKHR{};
    VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures PhysicalDeviceShaderDemoteToHelperInvocationFeatures{};
    VkPhysicalDeviceShaderDrawParametersFeatures PhysicalDeviceShaderDrawParametersFeatures{};
    VkPhysicalDeviceShaderFloat16Int8Features PhysicalDeviceShaderFloat16Int8Features{};
    VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT PhysicalDeviceShaderImageAtomicInt64FeaturesEXT{};
    VkPhysicalDeviceShaderIntegerDotProductFeatures PhysicalDeviceShaderIntegerDotProductFeatures{};
    char VkPhysicalDeviceShaderIntegerDotProductFeatures_padding[64];
    VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures PhysicalDeviceShaderSubgroupExtendedTypesFeatures{};
    VkPhysicalDeviceShaderTerminateInvocationFeatures PhysicalDeviceShaderTerminateInvocationFeatures{};
    VkPhysicalDeviceSubgroupSizeControlFeatures PhysicalDeviceSubgroupSizeControlFeatures{};
    VkPhysicalDeviceSynchronization2Features PhysicalDeviceSynchronization2Features{};
    VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT PhysicalDeviceTexelBufferAlignmentFeaturesEXT{};
    VkPhysicalDeviceTextureCompressionASTCHDRFeatures PhysicalDeviceTextureCompressionASTCHDRFeatures{};
    VkPhysicalDeviceTimelineSemaphoreFeatures PhysicalDeviceTimelineSemaphoreFeatures{};
    VkPhysicalDeviceUniformBufferStandardLayoutFeatures PhysicalDeviceUniformBufferStandardLayoutFeatures{};
    VkPhysicalDeviceVariablePointersFeatures PhysicalDeviceVariablePointersFeatures{};
    VkPhysicalDeviceVertexAttributeDivisorFeaturesKHR PhysicalDeviceVertexAttributeDivisorFeaturesKHR{};
    VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT PhysicalDeviceVertexInputDynamicStateFeaturesEXT{};
    VkPhysicalDeviceVulkan11Features PhysicalDeviceVulkan11Features{};
    VkPhysicalDeviceVulkan12Features PhysicalDeviceVulkan12Features{};
    VkPhysicalDeviceVulkan13Features PhysicalDeviceVulkan13Features{};
    VkPhysicalDeviceVulkanMemoryModelFeatures PhysicalDeviceVulkanMemoryModelFeatures{};
    VkPhysicalDeviceVulkanSC10Features PhysicalDeviceVulkanSC10Features{};
    VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT PhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT{};
    VkPhysicalDeviceYcbcrImageArraysFeaturesEXT PhysicalDeviceYcbcrImageArraysFeaturesEXT{};
    VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures PhysicalDeviceZeroInitializeWorkgroupMemoryFeatures{};
    void initialize_chain(AppGpu &gpu ) noexcept {
        PhysicalDevice16BitStorageFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES;
        PhysicalDevice4444FormatsFeaturesEXT.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_4444_FORMATS_FEATURES_EXT;
        PhysicalDevice8BitStorageFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES;
        PhysicalDeviceASTCDecodeFeaturesEXT.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT;
        PhysicalDeviceBlendOperationAdvancedFeaturesEXT.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT;
        PhysicalDeviceBufferDeviceAddressFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES;
        PhysicalDeviceColorWriteEnableFeaturesEXT.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COLOR_WRITE_ENABLE_FEATURES_EXT;
        PhysicalDeviceCustomBorderColorFeaturesEXT.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_FEATURES_EXT;
        PhysicalDeviceDepthClipEnableFeaturesEXT.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT;
        PhysicalDeviceDescriptorIndexingFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES;
        PhysicalDeviceDynamicRenderingFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_FEATURES;
        PhysicalDeviceExtendedDynamicState2FeaturesEXT.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_2_FEATURES_EXT;
        PhysicalDeviceExtendedDynamicStateFeaturesEXT.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_FEATURES_EXT;
        PhysicalDeviceFragmentShaderInterlockFeaturesEXT.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT;
        PhysicalDeviceFragmentShadingRateFeaturesKHR.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_FEATURES_KHR;
        PhysicalDeviceGlobalPriorityQueryFeaturesKHR.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES_KHR;
        PhysicalDeviceHostQueryResetFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES;
        PhysicalDeviceImageRobustnessFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES;
        PhysicalDeviceImagelessFramebufferFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES;
        PhysicalDeviceIndexTypeUint8FeaturesKHR.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES_KHR;
        PhysicalDeviceInlineUniformBlockFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES;
        PhysicalDeviceLineRasterizationFeaturesKHR.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_KHR;
        PhysicalDeviceMaintenance4Features.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_FEATURES;
        PhysicalDeviceMultiviewFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES;
        PhysicalDevicePerformanceQueryFeaturesKHR.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_FEATURES_KHR;
        PhysicalDevicePipelineCreationCacheControlFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES;
        PhysicalDevicePrivateDataFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIVATE_DATA_FEATURES;
        PhysicalDeviceProtectedMemoryFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES;
        PhysicalDeviceRobustness2FeaturesEXT.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_EXT;
        PhysicalDeviceSamplerYcbcrConversionFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES;
        PhysicalDeviceScalarBlockLayoutFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES;
        PhysicalDeviceSeparateDepthStencilLayoutsFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES;
        PhysicalDeviceShaderAtomicFloatFeaturesEXT.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_FEATURES_EXT;
        PhysicalDeviceShaderAtomicInt64Features.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES;
        PhysicalDeviceShaderClockFeaturesKHR.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR;
        PhysicalDeviceShaderDemoteToHelperInvocationFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES;
        PhysicalDeviceShaderDrawParametersFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES;
        PhysicalDeviceShaderFloat16Int8Features.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES;
        PhysicalDeviceShaderImageAtomicInt64FeaturesEXT.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_ATOMIC_INT64_FEATURES_EXT;
        PhysicalDeviceShaderIntegerDotProductFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_FEATURES;
        PhysicalDeviceShaderSubgroupExtendedTypesFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES;
        PhysicalDeviceShaderTerminateInvocationFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TERMINATE_INVOCATION_FEATURES;
        PhysicalDeviceSubgroupSizeControlFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES;
        PhysicalDeviceSynchronization2Features.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SYNCHRONIZATION_2_FEATURES;
        PhysicalDeviceTexelBufferAlignmentFeaturesEXT.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT;
        PhysicalDeviceTextureCompressionASTCHDRFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES;
        PhysicalDeviceTimelineSemaphoreFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES;
        PhysicalDeviceUniformBufferStandardLayoutFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES;
        PhysicalDeviceVariablePointersFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES;
        PhysicalDeviceVertexAttributeDivisorFeaturesKHR.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_KHR;
        PhysicalDeviceVertexInputDynamicStateFeaturesEXT.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_INPUT_DYNAMIC_STATE_FEATURES_EXT;
        PhysicalDeviceVulkan11Features.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES;
        PhysicalDeviceVulkan12Features.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES;
        PhysicalDeviceVulkan13Features.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES;
        PhysicalDeviceVulkanMemoryModelFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES;
        PhysicalDeviceVulkanSC10Features.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_SC_1_0_FEATURES;
        PhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_2_PLANE_444_FORMATS_FEATURES_EXT;
        PhysicalDeviceYcbcrImageArraysFeaturesEXT.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT;
        PhysicalDeviceZeroInitializeWorkgroupMemoryFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_WORKGROUP_MEMORY_FEATURES;
        std::vector<VkBaseOutStructure*> chain_members{};
        if (gpu.api_version >= VK_API_VERSION_1_1)
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDevice16BitStorageFeatures));
        if (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_4444_FORMATS_EXTENSION_NAME))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDevice4444FormatsFeaturesEXT));
        if (gpu.api_version >= VK_API_VERSION_1_2)
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDevice8BitStorageFeatures));
        if (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_ASTC_DECODE_MODE_EXTENSION_NAME))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceASTCDecodeFeaturesEXT));
        if (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_BLEND_OPERATION_ADVANCED_EXTENSION_NAME))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceBlendOperationAdvancedFeaturesEXT));
        if (gpu.api_version >= VK_API_VERSION_1_2)
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceBufferDeviceAddressFeatures));
        if (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_COLOR_WRITE_ENABLE_EXTENSION_NAME))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceColorWriteEnableFeaturesEXT));
        if (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_CUSTOM_BORDER_COLOR_EXTENSION_NAME))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceCustomBorderColorFeaturesEXT));
        if (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_DEPTH_CLIP_ENABLE_EXTENSION_NAME))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceDepthClipEnableFeaturesEXT));
        if (gpu.api_version >= VK_API_VERSION_1_2)
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceDescriptorIndexingFeatures));
        if (gpu.api_version >= VK_API_VERSION_1_3)
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceDynamicRenderingFeatures));
        if (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_EXTENDED_DYNAMIC_STATE_2_EXTENSION_NAME))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceExtendedDynamicState2FeaturesEXT));
        if (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_EXTENDED_DYNAMIC_STATE_EXTENSION_NAME))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceExtendedDynamicStateFeaturesEXT));
        if (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_FRAGMENT_SHADER_INTERLOCK_EXTENSION_NAME))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceFragmentShaderInterlockFeaturesEXT));
        if (gpu.CheckPhysicalDeviceExtensionIncluded(VK_KHR_FRAGMENT_SHADING_RATE_EXTENSION_NAME))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceFragmentShadingRateFeaturesKHR));
        if (gpu.CheckPhysicalDeviceExtensionIncluded(VK_KHR_GLOBAL_PRIORITY_EXTENSION_NAME))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceGlobalPriorityQueryFeaturesKHR));
        if (gpu.api_version >= VK_API_VERSION_1_2)
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceHostQueryResetFeatures));
        if ((gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_IMAGE_ROBUSTNESS_EXTENSION_NAME))
            && gpu.api_version < VK_API_VERSION_1_3)
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceImageRobustnessFeatures));
        if (gpu.api_version >= VK_API_VERSION_1_2)
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceImagelessFramebufferFeatures));
        if (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_INDEX_TYPE_UINT8_EXTENSION_NAME)
         || gpu.CheckPhysicalDeviceExtensionIncluded(VK_KHR_INDEX_TYPE_UINT8_EXTENSION_NAME))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceIndexTypeUint8FeaturesKHR));
        if (gpu.api_version >= VK_API_VERSION_1_3)
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceInlineUniformBlockFeatures));
        if (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_LINE_RASTERIZATION_EXTENSION_NAME)
         || gpu.CheckPhysicalDeviceExtensionIncluded(VK_KHR_LINE_RASTERIZATION_EXTENSION_NAME))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceLineRasterizationFeaturesKHR));
        if (gpu.api_version >= VK_API_VERSION_1_3)
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceMaintenance4Features));
        if (gpu.api_version >= VK_API_VERSION_1_1)
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceMultiviewFeatures));
        if (gpu.CheckPhysicalDeviceExtensionIncluded(VK_KHR_PERFORMANCE_QUERY_EXTENSION_NAME))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDevicePerformanceQueryFeaturesKHR));
        if (gpu.api_version >= VK_API_VERSION_1_3)
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDevicePipelineCreationCacheControlFeatures));
        if (gpu.api_version >= VK_API_VERSION_1_3)
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDevicePrivateDataFeatures));
        if (gpu.api_version == VK_API_VERSION_1_1)
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceProtectedMemoryFeatures));
        if (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_ROBUSTNESS_2_EXTENSION_NAME))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceRobustness2FeaturesEXT));
        if (gpu.api_version >= VK_API_VERSION_1_1)
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceSamplerYcbcrConversionFeatures));
        if (gpu.api_version >= VK_API_VERSION_1_2)
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceScalarBlockLayoutFeatures));
        if (gpu.api_version >= VK_API_VERSION_1_2)
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceSeparateDepthStencilLayoutsFeatures));
        if (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_SHADER_ATOMIC_FLOAT_EXTENSION_NAME))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceShaderAtomicFloatFeaturesEXT));
        if (gpu.api_version >= VK_API_VERSION_1_2)
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceShaderAtomicInt64Features));
        if (gpu.CheckPhysicalDeviceExtensionIncluded(VK_KHR_SHADER_CLOCK_EXTENSION_NAME))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceShaderClockFeaturesKHR));
        if ((gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_SHADER_DEMOTE_TO_HELPER_INVOCATION_EXTENSION_NAME))
            && gpu.api_version < VK_API_VERSION_1_3)
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceShaderDemoteToHelperInvocationFeatures));
        if (gpu.api_version == VK_API_VERSION_1_1)
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceShaderDrawParametersFeatures));
        if (gpu.api_version >= VK_API_VERSION_1_2)
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceShaderFloat16Int8Features));
        if (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_SHADER_IMAGE_ATOMIC_INT64_EXTENSION_NAME))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceShaderImageAtomicInt64FeaturesEXT));
        if (gpu.api_version >= VK_API_VERSION_1_3)
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceShaderIntegerDotProductFeatures));
        if (gpu.api_version >= VK_API_VERSION_1_2)
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceShaderSubgroupExtendedTypesFeatures));
        if ((gpu.CheckPhysicalDeviceExtensionIncluded(VK_KHR_SHADER_TERMINATE_INVOCATION_EXTENSION_NAME))
            && gpu.api_version < VK_API_VERSION_1_3)
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceShaderTerminateInvocationFeatures));
        if ((gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_SUBGROUP_SIZE_CONTROL_EXTENSION_NAME))
            && gpu.api_version < VK_API_VERSION_1_3)
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceSubgroupSizeControlFeatures));
        if ((gpu.CheckPhysicalDeviceExtensionIncluded(VK_KHR_SYNCHRONIZATION_2_EXTENSION_NAME))
            && gpu.api_version < VK_API_VERSION_1_3)
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceSynchronization2Features));
        if (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_TEXEL_BUFFER_ALIGNMENT_EXTENSION_NAME))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceTexelBufferAlignmentFeaturesEXT));
        if ((gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_TEXTURE_COMPRESSION_ASTC_HDR_EXTENSION_NAME))
            && gpu.api_version < VK_API_VERSION_1_3)
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceTextureCompressionASTCHDRFeatures));
        if (gpu.api_version >= VK_API_VERSION_1_2)
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceTimelineSemaphoreFeatures));
        if (gpu.api_version >= VK_API_VERSION_1_2)
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceUniformBufferStandardLayoutFeatures));
        if (gpu.api_version >= VK_API_VERSION_1_1)
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceVariablePointersFeatures));
        if (gpu.CheckPhysicalDeviceExtensionIncluded(VK_KHR_VERTEX_ATTRIBUTE_DIVISOR_EXTENSION_NAME))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceVertexAttributeDivisorFeaturesKHR));
        if (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_VERTEX_INPUT_DYNAMIC_STATE_EXTENSION_NAME))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceVertexInputDynamicStateFeaturesEXT));
        if (gpu.api_version >= VK_API_VERSION_1_2)
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceVulkan11Features));
        if (gpu.api_version >= VK_API_VERSION_1_2)
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceVulkan12Features));
        if (gpu.api_version >= VK_API_VERSION_1_3)
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceVulkan13Features));
        if (gpu.api_version >= VK_API_VERSION_1_2)
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceVulkanMemoryModelFeatures));
        if (gpu.api_version >= VKSC_API_VERSION_1_0)
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceVulkanSC10Features));
        if (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_YCBCR_2PLANE_444_FORMATS_EXTENSION_NAME))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT));
        if (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_YCBCR_IMAGE_ARRAYS_EXTENSION_NAME))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceYcbcrImageArraysFeaturesEXT));
        if (gpu.api_version >= VK_API_VERSION_1_3)
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceZeroInitializeWorkgroupMemoryFeatures));

        if (!chain_members.empty()) {
            for(size_t i = 0; i < chain_members.size() - 1; i++){
                chain_members[i]->pNext = chain_members[i + 1];
            }
            start_of_chain = chain_members[0];
        }
    }
};
void setup_phys_device_features2_chain(VkPhysicalDeviceFeatures2& start, std::unique_ptr<phys_device_features2_chain>& chain, AppGpu &gpu){
    chain = std::unique_ptr<phys_device_features2_chain>(new phys_device_features2_chain());
    chain->initialize_chain(gpu);
    start.pNext = chain->start_of_chain;
};

void chain_iterator_phys_device_features2(Printer &p, AppGpu &gpu, void * place) {
    while (place) {
        struct VkBaseOutStructure *structure = (struct VkBaseOutStructure *)place;
        p.SetSubHeader();
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES &&
           (gpu.api_version >= VK_API_VERSION_1_1)) {
            VkPhysicalDevice16BitStorageFeatures* props = (VkPhysicalDevice16BitStorageFeatures*)structure;
            DumpVkPhysicalDevice16BitStorageFeatures(p, "VkPhysicalDevice16BitStorageFeatures", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_4444_FORMATS_FEATURES_EXT &&
           (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_4444_FORMATS_EXTENSION_NAME))) {
            VkPhysicalDevice4444FormatsFeaturesEXT* props = (VkPhysicalDevice4444FormatsFeaturesEXT*)structure;
            DumpVkPhysicalDevice4444FormatsFeaturesEXT(p, "VkPhysicalDevice4444FormatsFeaturesEXT", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES &&
           (gpu.api_version >= VK_API_VERSION_1_2)) {
            VkPhysicalDevice8BitStorageFeatures* props = (VkPhysicalDevice8BitStorageFeatures*)structure;
            DumpVkPhysicalDevice8BitStorageFeatures(p, "VkPhysicalDevice8BitStorageFeatures", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT &&
           (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_ASTC_DECODE_MODE_EXTENSION_NAME))) {
            VkPhysicalDeviceASTCDecodeFeaturesEXT* props = (VkPhysicalDeviceASTCDecodeFeaturesEXT*)structure;
            DumpVkPhysicalDeviceASTCDecodeFeaturesEXT(p, "VkPhysicalDeviceASTCDecodeFeaturesEXT", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT &&
           (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_BLEND_OPERATION_ADVANCED_EXTENSION_NAME))) {
            VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT* props = (VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT*)structure;
            DumpVkPhysicalDeviceBlendOperationAdvancedFeaturesEXT(p, "VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES &&
           (gpu.api_version >= VK_API_VERSION_1_2)) {
            VkPhysicalDeviceBufferDeviceAddressFeatures* props = (VkPhysicalDeviceBufferDeviceAddressFeatures*)structure;
            DumpVkPhysicalDeviceBufferDeviceAddressFeatures(p, "VkPhysicalDeviceBufferDeviceAddressFeatures", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COLOR_WRITE_ENABLE_FEATURES_EXT &&
           (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_COLOR_WRITE_ENABLE_EXTENSION_NAME))) {
            VkPhysicalDeviceColorWriteEnableFeaturesEXT* props = (VkPhysicalDeviceColorWriteEnableFeaturesEXT*)structure;
            DumpVkPhysicalDeviceColorWriteEnableFeaturesEXT(p, "VkPhysicalDeviceColorWriteEnableFeaturesEXT", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_FEATURES_EXT &&
           (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_CUSTOM_BORDER_COLOR_EXTENSION_NAME))) {
            VkPhysicalDeviceCustomBorderColorFeaturesEXT* props = (VkPhysicalDeviceCustomBorderColorFeaturesEXT*)structure;
            DumpVkPhysicalDeviceCustomBorderColorFeaturesEXT(p, "VkPhysicalDeviceCustomBorderColorFeaturesEXT", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT &&
           (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_DEPTH_CLIP_ENABLE_EXTENSION_NAME))) {
            VkPhysicalDeviceDepthClipEnableFeaturesEXT* props = (VkPhysicalDeviceDepthClipEnableFeaturesEXT*)structure;
            DumpVkPhysicalDeviceDepthClipEnableFeaturesEXT(p, "VkPhysicalDeviceDepthClipEnableFeaturesEXT", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES &&
           (gpu.api_version >= VK_API_VERSION_1_2)) {
            VkPhysicalDeviceDescriptorIndexingFeatures* props = (VkPhysicalDeviceDescriptorIndexingFeatures*)structure;
            DumpVkPhysicalDeviceDescriptorIndexingFeatures(p, "VkPhysicalDeviceDescriptorIndexingFeatures", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_FEATURES &&
           (gpu.api_version >= VK_API_VERSION_1_3)) {
            VkPhysicalDeviceDynamicRenderingFeatures* props = (VkPhysicalDeviceDynamicRenderingFeatures*)structure;
            DumpVkPhysicalDeviceDynamicRenderingFeatures(p, "VkPhysicalDeviceDynamicRenderingFeatures", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_2_FEATURES_EXT &&
           (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_EXTENDED_DYNAMIC_STATE_2_EXTENSION_NAME))) {
            VkPhysicalDeviceExtendedDynamicState2FeaturesEXT* props = (VkPhysicalDeviceExtendedDynamicState2FeaturesEXT*)structure;
            DumpVkPhysicalDeviceExtendedDynamicState2FeaturesEXT(p, "VkPhysicalDeviceExtendedDynamicState2FeaturesEXT", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_FEATURES_EXT &&
           (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_EXTENDED_DYNAMIC_STATE_EXTENSION_NAME))) {
            VkPhysicalDeviceExtendedDynamicStateFeaturesEXT* props = (VkPhysicalDeviceExtendedDynamicStateFeaturesEXT*)structure;
            DumpVkPhysicalDeviceExtendedDynamicStateFeaturesEXT(p, "VkPhysicalDeviceExtendedDynamicStateFeaturesEXT", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT &&
           (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_FRAGMENT_SHADER_INTERLOCK_EXTENSION_NAME))) {
            VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT* props = (VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT*)structure;
            DumpVkPhysicalDeviceFragmentShaderInterlockFeaturesEXT(p, "VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_FEATURES_KHR &&
           (gpu.CheckPhysicalDeviceExtensionIncluded(VK_KHR_FRAGMENT_SHADING_RATE_EXTENSION_NAME))) {
            VkPhysicalDeviceFragmentShadingRateFeaturesKHR* props = (VkPhysicalDeviceFragmentShadingRateFeaturesKHR*)structure;
            DumpVkPhysicalDeviceFragmentShadingRateFeaturesKHR(p, "VkPhysicalDeviceFragmentShadingRateFeaturesKHR", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES_KHR &&
           (gpu.CheckPhysicalDeviceExtensionIncluded(VK_KHR_GLOBAL_PRIORITY_EXTENSION_NAME))) {
            VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR* props = (VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR*)structure;
            DumpVkPhysicalDeviceGlobalPriorityQueryFeaturesKHR(p, "VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES &&
           (gpu.api_version >= VK_API_VERSION_1_2)) {
            VkPhysicalDeviceHostQueryResetFeatures* props = (VkPhysicalDeviceHostQueryResetFeatures*)structure;
            DumpVkPhysicalDeviceHostQueryResetFeatures(p, "VkPhysicalDeviceHostQueryResetFeatures", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES &&
           ((gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_IMAGE_ROBUSTNESS_EXTENSION_NAME)) &&
            gpu.api_version < VK_API_VERSION_1_3)) {
            VkPhysicalDeviceImageRobustnessFeatures* props = (VkPhysicalDeviceImageRobustnessFeatures*)structure;
            DumpVkPhysicalDeviceImageRobustnessFeatures(p, gpu.api_version >= VK_API_VERSION_1_3 ?"VkPhysicalDeviceImageRobustnessFeatures":"VkPhysicalDeviceImageRobustnessFeaturesEXT", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES &&
           (gpu.api_version >= VK_API_VERSION_1_2)) {
            VkPhysicalDeviceImagelessFramebufferFeatures* props = (VkPhysicalDeviceImagelessFramebufferFeatures*)structure;
            DumpVkPhysicalDeviceImagelessFramebufferFeatures(p, "VkPhysicalDeviceImagelessFramebufferFeatures", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES_KHR &&
           (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_INDEX_TYPE_UINT8_EXTENSION_NAME) || gpu.CheckPhysicalDeviceExtensionIncluded(VK_KHR_INDEX_TYPE_UINT8_EXTENSION_NAME))) {
            VkPhysicalDeviceIndexTypeUint8FeaturesKHR* props = (VkPhysicalDeviceIndexTypeUint8FeaturesKHR*)structure;
            DumpVkPhysicalDeviceIndexTypeUint8FeaturesKHR(p, "VkPhysicalDeviceIndexTypeUint8FeaturesKHR", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES &&
           (gpu.api_version >= VK_API_VERSION_1_3)) {
            VkPhysicalDeviceInlineUniformBlockFeatures* props = (VkPhysicalDeviceInlineUniformBlockFeatures*)structure;
            DumpVkPhysicalDeviceInlineUniformBlockFeatures(p, "VkPhysicalDeviceInlineUniformBlockFeatures", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_KHR &&
           (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_LINE_RASTERIZATION_EXTENSION_NAME) || gpu.CheckPhysicalDeviceExtensionIncluded(VK_KHR_LINE_RASTERIZATION_EXTENSION_NAME))) {
            VkPhysicalDeviceLineRasterizationFeaturesKHR* props = (VkPhysicalDeviceLineRasterizationFeaturesKHR*)structure;
            DumpVkPhysicalDeviceLineRasterizationFeaturesKHR(p, "VkPhysicalDeviceLineRasterizationFeaturesKHR", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_FEATURES &&
           (gpu.api_version >= VK_API_VERSION_1_3)) {
            VkPhysicalDeviceMaintenance4Features* props = (VkPhysicalDeviceMaintenance4Features*)structure;
            DumpVkPhysicalDeviceMaintenance4Features(p, "VkPhysicalDeviceMaintenance4Features", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES &&
           (gpu.api_version >= VK_API_VERSION_1_1)) {
            VkPhysicalDeviceMultiviewFeatures* props = (VkPhysicalDeviceMultiviewFeatures*)structure;
            DumpVkPhysicalDeviceMultiviewFeatures(p, "VkPhysicalDeviceMultiviewFeatures", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_FEATURES_KHR &&
           (gpu.CheckPhysicalDeviceExtensionIncluded(VK_KHR_PERFORMANCE_QUERY_EXTENSION_NAME))) {
            VkPhysicalDevicePerformanceQueryFeaturesKHR* props = (VkPhysicalDevicePerformanceQueryFeaturesKHR*)structure;
            DumpVkPhysicalDevicePerformanceQueryFeaturesKHR(p, "VkPhysicalDevicePerformanceQueryFeaturesKHR", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES &&
           (gpu.api_version >= VK_API_VERSION_1_3)) {
            VkPhysicalDevicePipelineCreationCacheControlFeatures* props = (VkPhysicalDevicePipelineCreationCacheControlFeatures*)structure;
            DumpVkPhysicalDevicePipelineCreationCacheControlFeatures(p, "VkPhysicalDevicePipelineCreationCacheControlFeatures", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIVATE_DATA_FEATURES &&
           (gpu.api_version >= VK_API_VERSION_1_3)) {
            VkPhysicalDevicePrivateDataFeatures* props = (VkPhysicalDevicePrivateDataFeatures*)structure;
            DumpVkPhysicalDevicePrivateDataFeatures(p, "VkPhysicalDevicePrivateDataFeatures", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES &&
           (gpu.api_version == VK_API_VERSION_1_1)) {
            VkPhysicalDeviceProtectedMemoryFeatures* props = (VkPhysicalDeviceProtectedMemoryFeatures*)structure;
            DumpVkPhysicalDeviceProtectedMemoryFeatures(p, "VkPhysicalDeviceProtectedMemoryFeatures", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_EXT &&
           (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_ROBUSTNESS_2_EXTENSION_NAME))) {
            VkPhysicalDeviceRobustness2FeaturesEXT* props = (VkPhysicalDeviceRobustness2FeaturesEXT*)structure;
            DumpVkPhysicalDeviceRobustness2FeaturesEXT(p, "VkPhysicalDeviceRobustness2FeaturesEXT", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES &&
           (gpu.api_version >= VK_API_VERSION_1_1)) {
            VkPhysicalDeviceSamplerYcbcrConversionFeatures* props = (VkPhysicalDeviceSamplerYcbcrConversionFeatures*)structure;
            DumpVkPhysicalDeviceSamplerYcbcrConversionFeatures(p, "VkPhysicalDeviceSamplerYcbcrConversionFeatures", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES &&
           (gpu.api_version >= VK_API_VERSION_1_2)) {
            VkPhysicalDeviceScalarBlockLayoutFeatures* props = (VkPhysicalDeviceScalarBlockLayoutFeatures*)structure;
            DumpVkPhysicalDeviceScalarBlockLayoutFeatures(p, "VkPhysicalDeviceScalarBlockLayoutFeatures", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES &&
           (gpu.api_version >= VK_API_VERSION_1_2)) {
            VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures* props = (VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures*)structure;
            DumpVkPhysicalDeviceSeparateDepthStencilLayoutsFeatures(p, "VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_FEATURES_EXT &&
           (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_SHADER_ATOMIC_FLOAT_EXTENSION_NAME))) {
            VkPhysicalDeviceShaderAtomicFloatFeaturesEXT* props = (VkPhysicalDeviceShaderAtomicFloatFeaturesEXT*)structure;
            DumpVkPhysicalDeviceShaderAtomicFloatFeaturesEXT(p, "VkPhysicalDeviceShaderAtomicFloatFeaturesEXT", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES &&
           (gpu.api_version >= VK_API_VERSION_1_2)) {
            VkPhysicalDeviceShaderAtomicInt64Features* props = (VkPhysicalDeviceShaderAtomicInt64Features*)structure;
            DumpVkPhysicalDeviceShaderAtomicInt64Features(p, "VkPhysicalDeviceShaderAtomicInt64Features", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR &&
           (gpu.CheckPhysicalDeviceExtensionIncluded(VK_KHR_SHADER_CLOCK_EXTENSION_NAME))) {
            VkPhysicalDeviceShaderClockFeaturesKHR* props = (VkPhysicalDeviceShaderClockFeaturesKHR*)structure;
            DumpVkPhysicalDeviceShaderClockFeaturesKHR(p, "VkPhysicalDeviceShaderClockFeaturesKHR", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES &&
           ((gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_SHADER_DEMOTE_TO_HELPER_INVOCATION_EXTENSION_NAME)) &&
            gpu.api_version < VK_API_VERSION_1_3)) {
            VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures* props = (VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures*)structure;
            DumpVkPhysicalDeviceShaderDemoteToHelperInvocationFeatures(p, gpu.api_version >= VK_API_VERSION_1_3 ?"VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures":"VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES &&
           (gpu.api_version == VK_API_VERSION_1_1)) {
            VkPhysicalDeviceShaderDrawParametersFeatures* props = (VkPhysicalDeviceShaderDrawParametersFeatures*)structure;
            DumpVkPhysicalDeviceShaderDrawParametersFeatures(p, gpu.api_version >= VK_API_VERSION_1_1 ?"VkPhysicalDeviceShaderDrawParametersFeatures":"VkPhysicalDeviceShaderDrawParameterFeatures", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES &&
           (gpu.api_version >= VK_API_VERSION_1_2)) {
            VkPhysicalDeviceShaderFloat16Int8Features* props = (VkPhysicalDeviceShaderFloat16Int8Features*)structure;
            DumpVkPhysicalDeviceShaderFloat16Int8Features(p, "VkPhysicalDeviceShaderFloat16Int8Features", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_ATOMIC_INT64_FEATURES_EXT &&
           (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_SHADER_IMAGE_ATOMIC_INT64_EXTENSION_NAME))) {
            VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT* props = (VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT*)structure;
            DumpVkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT(p, "VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_FEATURES &&
           (gpu.api_version >= VK_API_VERSION_1_3)) {
            VkPhysicalDeviceShaderIntegerDotProductFeatures* props = (VkPhysicalDeviceShaderIntegerDotProductFeatures*)structure;
            DumpVkPhysicalDeviceShaderIntegerDotProductFeatures(p, "VkPhysicalDeviceShaderIntegerDotProductFeatures", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES &&
           (gpu.api_version >= VK_API_VERSION_1_2)) {
            VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures* props = (VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures*)structure;
            DumpVkPhysicalDeviceShaderSubgroupExtendedTypesFeatures(p, "VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TERMINATE_INVOCATION_FEATURES &&
           ((gpu.CheckPhysicalDeviceExtensionIncluded(VK_KHR_SHADER_TERMINATE_INVOCATION_EXTENSION_NAME)) &&
            gpu.api_version < VK_API_VERSION_1_3)) {
            VkPhysicalDeviceShaderTerminateInvocationFeatures* props = (VkPhysicalDeviceShaderTerminateInvocationFeatures*)structure;
            DumpVkPhysicalDeviceShaderTerminateInvocationFeatures(p, gpu.api_version >= VK_API_VERSION_1_3 ?"VkPhysicalDeviceShaderTerminateInvocationFeatures":"VkPhysicalDeviceShaderTerminateInvocationFeaturesKHR", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES &&
           ((gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_SUBGROUP_SIZE_CONTROL_EXTENSION_NAME)) &&
            gpu.api_version < VK_API_VERSION_1_3)) {
            VkPhysicalDeviceSubgroupSizeControlFeatures* props = (VkPhysicalDeviceSubgroupSizeControlFeatures*)structure;
            DumpVkPhysicalDeviceSubgroupSizeControlFeatures(p, gpu.api_version >= VK_API_VERSION_1_3 ?"VkPhysicalDeviceSubgroupSizeControlFeatures":"VkPhysicalDeviceSubgroupSizeControlFeaturesEXT", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SYNCHRONIZATION_2_FEATURES &&
           ((gpu.CheckPhysicalDeviceExtensionIncluded(VK_KHR_SYNCHRONIZATION_2_EXTENSION_NAME)) &&
            gpu.api_version < VK_API_VERSION_1_3)) {
            VkPhysicalDeviceSynchronization2Features* props = (VkPhysicalDeviceSynchronization2Features*)structure;
            DumpVkPhysicalDeviceSynchronization2Features(p, gpu.api_version >= VK_API_VERSION_1_3 ?"VkPhysicalDeviceSynchronization2Features":"VkPhysicalDeviceSynchronization2FeaturesKHR", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT &&
           (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_TEXEL_BUFFER_ALIGNMENT_EXTENSION_NAME))) {
            VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT* props = (VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT*)structure;
            DumpVkPhysicalDeviceTexelBufferAlignmentFeaturesEXT(p, "VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES &&
           ((gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_TEXTURE_COMPRESSION_ASTC_HDR_EXTENSION_NAME)) &&
            gpu.api_version < VK_API_VERSION_1_3)) {
            VkPhysicalDeviceTextureCompressionASTCHDRFeatures* props = (VkPhysicalDeviceTextureCompressionASTCHDRFeatures*)structure;
            DumpVkPhysicalDeviceTextureCompressionASTCHDRFeatures(p, gpu.api_version >= VK_API_VERSION_1_3 ?"VkPhysicalDeviceTextureCompressionASTCHDRFeatures":"VkPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES &&
           (gpu.api_version >= VK_API_VERSION_1_2)) {
            VkPhysicalDeviceTimelineSemaphoreFeatures* props = (VkPhysicalDeviceTimelineSemaphoreFeatures*)structure;
            DumpVkPhysicalDeviceTimelineSemaphoreFeatures(p, "VkPhysicalDeviceTimelineSemaphoreFeatures", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES &&
           (gpu.api_version >= VK_API_VERSION_1_2)) {
            VkPhysicalDeviceUniformBufferStandardLayoutFeatures* props = (VkPhysicalDeviceUniformBufferStandardLayoutFeatures*)structure;
            DumpVkPhysicalDeviceUniformBufferStandardLayoutFeatures(p, "VkPhysicalDeviceUniformBufferStandardLayoutFeatures", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES &&
           (gpu.api_version >= VK_API_VERSION_1_1)) {
            VkPhysicalDeviceVariablePointersFeatures* props = (VkPhysicalDeviceVariablePointersFeatures*)structure;
            DumpVkPhysicalDeviceVariablePointersFeatures(p, gpu.api_version >= VK_API_VERSION_1_1 ?"VkPhysicalDeviceVariablePointersFeatures":"VkPhysicalDeviceVariablePointerFeatures", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_KHR &&
           (gpu.CheckPhysicalDeviceExtensionIncluded(VK_KHR_VERTEX_ATTRIBUTE_DIVISOR_EXTENSION_NAME))) {
            VkPhysicalDeviceVertexAttributeDivisorFeaturesKHR* props = (VkPhysicalDeviceVertexAttributeDivisorFeaturesKHR*)structure;
            DumpVkPhysicalDeviceVertexAttributeDivisorFeaturesKHR(p, "VkPhysicalDeviceVertexAttributeDivisorFeaturesKHR", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_INPUT_DYNAMIC_STATE_FEATURES_EXT &&
           (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_VERTEX_INPUT_DYNAMIC_STATE_EXTENSION_NAME))) {
            VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT* props = (VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT*)structure;
            DumpVkPhysicalDeviceVertexInputDynamicStateFeaturesEXT(p, "VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES &&
           (gpu.api_version >= VK_API_VERSION_1_2)) {
            VkPhysicalDeviceVulkan11Features* props = (VkPhysicalDeviceVulkan11Features*)structure;
            DumpVkPhysicalDeviceVulkan11Features(p, "VkPhysicalDeviceVulkan11Features", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES &&
           (gpu.api_version >= VK_API_VERSION_1_2)) {
            VkPhysicalDeviceVulkan12Features* props = (VkPhysicalDeviceVulkan12Features*)structure;
            DumpVkPhysicalDeviceVulkan12Features(p, "VkPhysicalDeviceVulkan12Features", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES &&
           (gpu.api_version >= VK_API_VERSION_1_3)) {
            VkPhysicalDeviceVulkan13Features* props = (VkPhysicalDeviceVulkan13Features*)structure;
            DumpVkPhysicalDeviceVulkan13Features(p, "VkPhysicalDeviceVulkan13Features", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES &&
           (gpu.api_version >= VK_API_VERSION_1_2)) {
            VkPhysicalDeviceVulkanMemoryModelFeatures* props = (VkPhysicalDeviceVulkanMemoryModelFeatures*)structure;
            DumpVkPhysicalDeviceVulkanMemoryModelFeatures(p, "VkPhysicalDeviceVulkanMemoryModelFeatures", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_SC_1_0_FEATURES &&
           (gpu.api_version >= VKSC_API_VERSION_1_0)) {
            VkPhysicalDeviceVulkanSC10Features* props = (VkPhysicalDeviceVulkanSC10Features*)structure;
            DumpVkPhysicalDeviceVulkanSC10Features(p, "VkPhysicalDeviceVulkanSC10Features", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_2_PLANE_444_FORMATS_FEATURES_EXT &&
           (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_YCBCR_2PLANE_444_FORMATS_EXTENSION_NAME))) {
            VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT* props = (VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT*)structure;
            DumpVkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT(p, "VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT &&
           (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_YCBCR_IMAGE_ARRAYS_EXTENSION_NAME))) {
            VkPhysicalDeviceYcbcrImageArraysFeaturesEXT* props = (VkPhysicalDeviceYcbcrImageArraysFeaturesEXT*)structure;
            DumpVkPhysicalDeviceYcbcrImageArraysFeaturesEXT(p, "VkPhysicalDeviceYcbcrImageArraysFeaturesEXT", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_WORKGROUP_MEMORY_FEATURES &&
           (gpu.api_version >= VK_API_VERSION_1_3)) {
            VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures* props = (VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures*)structure;
            DumpVkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures(p, "VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures", *props);
            p.AddNewline();
        }
        place = structure->pNext;
    }
}
struct surface_capabilities2_chain {
    surface_capabilities2_chain() = default;
    surface_capabilities2_chain(const surface_capabilities2_chain &) = delete;
    surface_capabilities2_chain& operator=(const surface_capabilities2_chain &) = delete;
    surface_capabilities2_chain(surface_capabilities2_chain &&) = delete;
    surface_capabilities2_chain& operator=(surface_capabilities2_chain &&) = delete;
    void* start_of_chain = nullptr;
    VkSharedPresentSurfaceCapabilitiesKHR SharedPresentSurfaceCapabilitiesKHR{};
    void initialize_chain(AppInstance &inst, AppGpu &gpu ) noexcept {
        SharedPresentSurfaceCapabilitiesKHR.sType = VK_STRUCTURE_TYPE_SHARED_PRESENT_SURFACE_CAPABILITIES_KHR;
        std::vector<VkBaseOutStructure*> chain_members{};
        if (gpu.CheckPhysicalDeviceExtensionIncluded(VK_KHR_SHARED_PRESENTABLE_IMAGE_EXTENSION_NAME))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&SharedPresentSurfaceCapabilitiesKHR));

        if (!chain_members.empty()) {
            for(size_t i = 0; i < chain_members.size() - 1; i++){
                chain_members[i]->pNext = chain_members[i + 1];
            }
            start_of_chain = chain_members[0];
        }
    }
};
void setup_surface_capabilities2_chain(VkSurfaceCapabilities2KHR& start, std::unique_ptr<surface_capabilities2_chain>& chain, AppInstance &inst,AppGpu &gpu){
    chain = std::unique_ptr<surface_capabilities2_chain>(new surface_capabilities2_chain());
    chain->initialize_chain(inst,gpu);
    start.pNext = chain->start_of_chain;
};

void chain_iterator_surface_capabilities2(Printer &p, AppInstance &inst, AppGpu &gpu, void * place) {
    while (place) {
        struct VkBaseOutStructure *structure = (struct VkBaseOutStructure *)place;
        p.SetSubHeader();
        if (structure->sType == VK_STRUCTURE_TYPE_SHARED_PRESENT_SURFACE_CAPABILITIES_KHR &&
           (gpu.CheckPhysicalDeviceExtensionIncluded(VK_KHR_SHARED_PRESENTABLE_IMAGE_EXTENSION_NAME))) {
            VkSharedPresentSurfaceCapabilitiesKHR* props = (VkSharedPresentSurfaceCapabilitiesKHR*)structure;
            DumpVkSharedPresentSurfaceCapabilitiesKHR(p, "VkSharedPresentSurfaceCapabilitiesKHR", *props);
            p.AddNewline();
        }
        place = structure->pNext;
    }
}
struct format_properties2_chain {
    format_properties2_chain() = default;
    format_properties2_chain(const format_properties2_chain &) = delete;
    format_properties2_chain& operator=(const format_properties2_chain &) = delete;
    format_properties2_chain(format_properties2_chain &&) = delete;
    format_properties2_chain& operator=(format_properties2_chain &&) = delete;
    void* start_of_chain = nullptr;
    VkFormatProperties3 FormatProperties3{};
    void initialize_chain(AppGpu &gpu ) noexcept {
        FormatProperties3.sType = VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_3;
        std::vector<VkBaseOutStructure*> chain_members{};
        if (gpu.api_version >= VK_API_VERSION_1_3)
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&FormatProperties3));

        if (!chain_members.empty()) {
            for(size_t i = 0; i < chain_members.size() - 1; i++){
                chain_members[i]->pNext = chain_members[i + 1];
            }
            start_of_chain = chain_members[0];
        }
    }
};
void setup_format_properties2_chain(VkFormatProperties2& start, std::unique_ptr<format_properties2_chain>& chain, AppGpu &gpu){
    chain = std::unique_ptr<format_properties2_chain>(new format_properties2_chain());
    chain->initialize_chain(gpu);
    start.pNext = chain->start_of_chain;
};

void chain_iterator_format_properties2(Printer &p, AppGpu &gpu, void * place) {
    while (place) {
        struct VkBaseOutStructure *structure = (struct VkBaseOutStructure *)place;
        p.SetSubHeader();
        if (structure->sType == VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_3 &&
           (gpu.api_version >= VK_API_VERSION_1_3)) {
            VkFormatProperties3* props = (VkFormatProperties3*)structure;
            DumpVkFormatProperties3(p, "VkFormatProperties3", *props);
            p.AddNewline();
        }
        place = structure->pNext;
    }
}
struct queue_properties2_chain {
    queue_properties2_chain() = default;
    queue_properties2_chain(const queue_properties2_chain &) = delete;
    queue_properties2_chain& operator=(const queue_properties2_chain &) = delete;
    queue_properties2_chain(queue_properties2_chain &&) = delete;
    queue_properties2_chain& operator=(queue_properties2_chain &&) = delete;
    void* start_of_chain = nullptr;
    VkQueueFamilyGlobalPriorityPropertiesKHR QueueFamilyGlobalPriorityPropertiesKHR{};
    void initialize_chain(AppGpu &gpu ) noexcept {
        QueueFamilyGlobalPriorityPropertiesKHR.sType = VK_STRUCTURE_TYPE_QUEUE_FAMILY_GLOBAL_PRIORITY_PROPERTIES_KHR;
        std::vector<VkBaseOutStructure*> chain_members{};
        if (gpu.CheckPhysicalDeviceExtensionIncluded(VK_KHR_GLOBAL_PRIORITY_EXTENSION_NAME))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&QueueFamilyGlobalPriorityPropertiesKHR));

        if (!chain_members.empty()) {
            for(size_t i = 0; i < chain_members.size() - 1; i++){
                chain_members[i]->pNext = chain_members[i + 1];
            }
            start_of_chain = chain_members[0];
        }
    }
};
void setup_queue_properties2_chain(VkQueueFamilyProperties2& start, std::unique_ptr<queue_properties2_chain>& chain, AppGpu &gpu){
    chain = std::unique_ptr<queue_properties2_chain>(new queue_properties2_chain());
    chain->initialize_chain(gpu);
    start.pNext = chain->start_of_chain;
};

void chain_iterator_queue_properties2(Printer &p, AppGpu &gpu, void * place) {
    while (place) {
        struct VkBaseOutStructure *structure = (struct VkBaseOutStructure *)place;
        p.SetSubHeader();
        if (structure->sType == VK_STRUCTURE_TYPE_QUEUE_FAMILY_GLOBAL_PRIORITY_PROPERTIES_KHR &&
           (gpu.CheckPhysicalDeviceExtensionIncluded(VK_KHR_GLOBAL_PRIORITY_EXTENSION_NAME))) {
            VkQueueFamilyGlobalPriorityPropertiesKHR* props = (VkQueueFamilyGlobalPriorityPropertiesKHR*)structure;
            DumpVkQueueFamilyGlobalPriorityPropertiesKHR(p, "VkQueueFamilyGlobalPriorityPropertiesKHR", *props);
            p.AddNewline();
        }
        place = structure->pNext;
    }
}
bool operator==(const VkExtent2D & a, const VkExtent2D b);
bool operator==(const VkSurfaceCapabilities2EXT & a, const VkSurfaceCapabilities2EXT b);
bool operator==(const VkSurfaceCapabilities2KHR & a, const VkSurfaceCapabilities2KHR b);
bool operator==(const VkSurfaceCapabilitiesKHR & a, const VkSurfaceCapabilitiesKHR b);
bool operator==(const VkSurfaceFormat2KHR & a, const VkSurfaceFormat2KHR b);
bool operator==(const VkSurfaceFormatKHR & a, const VkSurfaceFormatKHR b);
bool operator==(const VkExtent2D & a, const VkExtent2D b) {
    return a.width == b.width
        && a.height == b.height;
}
bool operator==(const VkSurfaceCapabilities2EXT & a, const VkSurfaceCapabilities2EXT b) {
    return a.minImageCount == b.minImageCount
        && a.maxImageCount == b.maxImageCount
        && a.currentExtent == b.currentExtent
        && a.minImageExtent == b.minImageExtent
        && a.maxImageExtent == b.maxImageExtent
        && a.maxImageArrayLayers == b.maxImageArrayLayers
        && a.supportedTransforms == b.supportedTransforms
        && a.currentTransform == b.currentTransform
        && a.supportedCompositeAlpha == b.supportedCompositeAlpha
        && a.supportedUsageFlags == b.supportedUsageFlags
        && a.supportedSurfaceCounters == b.supportedSurfaceCounters;
}
bool operator==(const VkSurfaceCapabilities2KHR & a, const VkSurfaceCapabilities2KHR b) {
    return a.surfaceCapabilities == b.surfaceCapabilities;
}
bool operator==(const VkSurfaceCapabilitiesKHR & a, const VkSurfaceCapabilitiesKHR b) {
    return a.minImageCount == b.minImageCount
        && a.maxImageCount == b.maxImageCount
        && a.currentExtent == b.currentExtent
        && a.minImageExtent == b.minImageExtent
        && a.maxImageExtent == b.maxImageExtent
        && a.maxImageArrayLayers == b.maxImageArrayLayers
        && a.supportedTransforms == b.supportedTransforms
        && a.currentTransform == b.currentTransform
        && a.supportedCompositeAlpha == b.supportedCompositeAlpha
        && a.supportedUsageFlags == b.supportedUsageFlags;
}
bool operator==(const VkSurfaceFormat2KHR & a, const VkSurfaceFormat2KHR b) {
    return a.surfaceFormat == b.surfaceFormat;
}
bool operator==(const VkSurfaceFormatKHR & a, const VkSurfaceFormatKHR b) {
    return a.format == b.format
        && a.colorSpace == b.colorSpace;
}
std::ostream &operator<<(std::ostream &o, VkExtent3D &obj) {
    return o << "(" << obj.width << ',' << obj.height << ',' << obj.depth << ")";
}
auto format_ranges = std::array{
    FormatRange{0, nullptr, static_cast<VkFormat>(0), static_cast<VkFormat>(184)},
    FormatRange{VK_API_VERSION_1_1, nullptr, static_cast<VkFormat>(1000156000), static_cast<VkFormat>(1000156033)},
    FormatRange{0, VK_KHR_SAMPLER_YCBCR_CONVERSION_EXTENSION_NAME, static_cast<VkFormat>(1000156000), static_cast<VkFormat>(1000156033)},
    FormatRange{VK_API_VERSION_1_3, nullptr, static_cast<VkFormat>(1000330000), static_cast<VkFormat>(1000330003)},
    FormatRange{0, VK_EXT_YCBCR_2PLANE_444_FORMATS_EXTENSION_NAME, static_cast<VkFormat>(1000330000), static_cast<VkFormat>(1000330003)},
    FormatRange{VK_API_VERSION_1_3, nullptr, static_cast<VkFormat>(1000340000), static_cast<VkFormat>(1000340001)},
    FormatRange{0, VK_EXT_4444_FORMATS_EXTENSION_NAME, static_cast<VkFormat>(1000340000), static_cast<VkFormat>(1000340001)},
    FormatRange{VK_API_VERSION_1_3, nullptr, static_cast<VkFormat>(1000066000), static_cast<VkFormat>(1000066013)},
    FormatRange{0, VK_EXT_TEXTURE_COMPRESSION_ASTC_HDR_EXTENSION_NAME, static_cast<VkFormat>(1000066000), static_cast<VkFormat>(1000066013)},
};

