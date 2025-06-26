
/*
 * Copyright (c) 2019-2022 The Khronos Group Inc.
 * Copyright (c) 2019-2022 Valve Corporation
 * Copyright (c) 2019-2022 LunarG, Inc.
 * Copyright (c) 2023-2024 RasterGrid Kft.
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

std::string StdVideoH264ChromaFormatIdcString(StdVideoH264ChromaFormatIdc value) {
    switch (value) {
        case STD_VIDEO_H264_CHROMA_FORMAT_IDC_MONOCHROME: return "STD_VIDEO_H264_CHROMA_FORMAT_IDC_MONOCHROME";
        case STD_VIDEO_H264_CHROMA_FORMAT_IDC_420: return "STD_VIDEO_H264_CHROMA_FORMAT_IDC_420";
        case STD_VIDEO_H264_CHROMA_FORMAT_IDC_422: return "STD_VIDEO_H264_CHROMA_FORMAT_IDC_422";
        case STD_VIDEO_H264_CHROMA_FORMAT_IDC_444: return "STD_VIDEO_H264_CHROMA_FORMAT_IDC_444";
        case STD_VIDEO_H264_CHROMA_FORMAT_IDC_INVALID: return "STD_VIDEO_H264_CHROMA_FORMAT_IDC_INVALID";
        default: return std::string("UNKNOWN_StdVideoH264ChromaFormatIdc_value") + std::to_string(value);
    }
}
void DumpStdVideoH264ChromaFormatIdc(Printer &p, std::string name, StdVideoH264ChromaFormatIdc value) {
    p.PrintKeyString(name, StdVideoH264ChromaFormatIdcString(value));
}
std::string StdVideoH264ProfileIdcString(StdVideoH264ProfileIdc value) {
    switch (value) {
        case STD_VIDEO_H264_PROFILE_IDC_BASELINE: return "STD_VIDEO_H264_PROFILE_IDC_BASELINE";
        case STD_VIDEO_H264_PROFILE_IDC_MAIN: return "STD_VIDEO_H264_PROFILE_IDC_MAIN";
        case STD_VIDEO_H264_PROFILE_IDC_HIGH: return "STD_VIDEO_H264_PROFILE_IDC_HIGH";
        case STD_VIDEO_H264_PROFILE_IDC_HIGH_444_PREDICTIVE: return "STD_VIDEO_H264_PROFILE_IDC_HIGH_444_PREDICTIVE";
        case STD_VIDEO_H264_PROFILE_IDC_INVALID: return "STD_VIDEO_H264_PROFILE_IDC_INVALID";
        default: return std::string("UNKNOWN_StdVideoH264ProfileIdc_value") + std::to_string(value);
    }
}
void DumpStdVideoH264ProfileIdc(Printer &p, std::string name, StdVideoH264ProfileIdc value) {
    p.PrintKeyString(name, StdVideoH264ProfileIdcString(value));
}
std::string StdVideoH264LevelIdcString(StdVideoH264LevelIdc value) {
    switch (value) {
        case STD_VIDEO_H264_LEVEL_IDC_1_0: return "STD_VIDEO_H264_LEVEL_IDC_1_0";
        case STD_VIDEO_H264_LEVEL_IDC_1_1: return "STD_VIDEO_H264_LEVEL_IDC_1_1";
        case STD_VIDEO_H264_LEVEL_IDC_1_2: return "STD_VIDEO_H264_LEVEL_IDC_1_2";
        case STD_VIDEO_H264_LEVEL_IDC_1_3: return "STD_VIDEO_H264_LEVEL_IDC_1_3";
        case STD_VIDEO_H264_LEVEL_IDC_2_0: return "STD_VIDEO_H264_LEVEL_IDC_2_0";
        case STD_VIDEO_H264_LEVEL_IDC_2_1: return "STD_VIDEO_H264_LEVEL_IDC_2_1";
        case STD_VIDEO_H264_LEVEL_IDC_2_2: return "STD_VIDEO_H264_LEVEL_IDC_2_2";
        case STD_VIDEO_H264_LEVEL_IDC_3_0: return "STD_VIDEO_H264_LEVEL_IDC_3_0";
        case STD_VIDEO_H264_LEVEL_IDC_3_1: return "STD_VIDEO_H264_LEVEL_IDC_3_1";
        case STD_VIDEO_H264_LEVEL_IDC_3_2: return "STD_VIDEO_H264_LEVEL_IDC_3_2";
        case STD_VIDEO_H264_LEVEL_IDC_4_0: return "STD_VIDEO_H264_LEVEL_IDC_4_0";
        case STD_VIDEO_H264_LEVEL_IDC_4_1: return "STD_VIDEO_H264_LEVEL_IDC_4_1";
        case STD_VIDEO_H264_LEVEL_IDC_4_2: return "STD_VIDEO_H264_LEVEL_IDC_4_2";
        case STD_VIDEO_H264_LEVEL_IDC_5_0: return "STD_VIDEO_H264_LEVEL_IDC_5_0";
        case STD_VIDEO_H264_LEVEL_IDC_5_1: return "STD_VIDEO_H264_LEVEL_IDC_5_1";
        case STD_VIDEO_H264_LEVEL_IDC_5_2: return "STD_VIDEO_H264_LEVEL_IDC_5_2";
        case STD_VIDEO_H264_LEVEL_IDC_6_0: return "STD_VIDEO_H264_LEVEL_IDC_6_0";
        case STD_VIDEO_H264_LEVEL_IDC_6_1: return "STD_VIDEO_H264_LEVEL_IDC_6_1";
        case STD_VIDEO_H264_LEVEL_IDC_6_2: return "STD_VIDEO_H264_LEVEL_IDC_6_2";
        case STD_VIDEO_H264_LEVEL_IDC_INVALID: return "STD_VIDEO_H264_LEVEL_IDC_INVALID";
        default: return std::string("UNKNOWN_StdVideoH264LevelIdc_value") + std::to_string(value);
    }
}
void DumpStdVideoH264LevelIdc(Printer &p, std::string name, StdVideoH264LevelIdc value) {
    p.PrintKeyString(name, StdVideoH264LevelIdcString(value));
}
std::string StdVideoH264PocTypeString(StdVideoH264PocType value) {
    switch (value) {
        case STD_VIDEO_H264_POC_TYPE_0: return "STD_VIDEO_H264_POC_TYPE_0";
        case STD_VIDEO_H264_POC_TYPE_1: return "STD_VIDEO_H264_POC_TYPE_1";
        case STD_VIDEO_H264_POC_TYPE_2: return "STD_VIDEO_H264_POC_TYPE_2";
        case STD_VIDEO_H264_POC_TYPE_INVALID: return "STD_VIDEO_H264_POC_TYPE_INVALID";
        default: return std::string("UNKNOWN_StdVideoH264PocType_value") + std::to_string(value);
    }
}
void DumpStdVideoH264PocType(Printer &p, std::string name, StdVideoH264PocType value) {
    p.PrintKeyString(name, StdVideoH264PocTypeString(value));
}
std::string StdVideoH264AspectRatioIdcString(StdVideoH264AspectRatioIdc value) {
    switch (value) {
        case STD_VIDEO_H264_ASPECT_RATIO_IDC_UNSPECIFIED: return "STD_VIDEO_H264_ASPECT_RATIO_IDC_UNSPECIFIED";
        case STD_VIDEO_H264_ASPECT_RATIO_IDC_SQUARE: return "STD_VIDEO_H264_ASPECT_RATIO_IDC_SQUARE";
        case STD_VIDEO_H264_ASPECT_RATIO_IDC_12_11: return "STD_VIDEO_H264_ASPECT_RATIO_IDC_12_11";
        case STD_VIDEO_H264_ASPECT_RATIO_IDC_10_11: return "STD_VIDEO_H264_ASPECT_RATIO_IDC_10_11";
        case STD_VIDEO_H264_ASPECT_RATIO_IDC_16_11: return "STD_VIDEO_H264_ASPECT_RATIO_IDC_16_11";
        case STD_VIDEO_H264_ASPECT_RATIO_IDC_40_33: return "STD_VIDEO_H264_ASPECT_RATIO_IDC_40_33";
        case STD_VIDEO_H264_ASPECT_RATIO_IDC_24_11: return "STD_VIDEO_H264_ASPECT_RATIO_IDC_24_11";
        case STD_VIDEO_H264_ASPECT_RATIO_IDC_20_11: return "STD_VIDEO_H264_ASPECT_RATIO_IDC_20_11";
        case STD_VIDEO_H264_ASPECT_RATIO_IDC_32_11: return "STD_VIDEO_H264_ASPECT_RATIO_IDC_32_11";
        case STD_VIDEO_H264_ASPECT_RATIO_IDC_80_33: return "STD_VIDEO_H264_ASPECT_RATIO_IDC_80_33";
        case STD_VIDEO_H264_ASPECT_RATIO_IDC_18_11: return "STD_VIDEO_H264_ASPECT_RATIO_IDC_18_11";
        case STD_VIDEO_H264_ASPECT_RATIO_IDC_15_11: return "STD_VIDEO_H264_ASPECT_RATIO_IDC_15_11";
        case STD_VIDEO_H264_ASPECT_RATIO_IDC_64_33: return "STD_VIDEO_H264_ASPECT_RATIO_IDC_64_33";
        case STD_VIDEO_H264_ASPECT_RATIO_IDC_160_99: return "STD_VIDEO_H264_ASPECT_RATIO_IDC_160_99";
        case STD_VIDEO_H264_ASPECT_RATIO_IDC_4_3: return "STD_VIDEO_H264_ASPECT_RATIO_IDC_4_3";
        case STD_VIDEO_H264_ASPECT_RATIO_IDC_3_2: return "STD_VIDEO_H264_ASPECT_RATIO_IDC_3_2";
        case STD_VIDEO_H264_ASPECT_RATIO_IDC_2_1: return "STD_VIDEO_H264_ASPECT_RATIO_IDC_2_1";
        case STD_VIDEO_H264_ASPECT_RATIO_IDC_EXTENDED_SAR: return "STD_VIDEO_H264_ASPECT_RATIO_IDC_EXTENDED_SAR";
        case STD_VIDEO_H264_ASPECT_RATIO_IDC_INVALID: return "STD_VIDEO_H264_ASPECT_RATIO_IDC_INVALID";
        default: return std::string("UNKNOWN_StdVideoH264AspectRatioIdc_value") + std::to_string(value);
    }
}
void DumpStdVideoH264AspectRatioIdc(Printer &p, std::string name, StdVideoH264AspectRatioIdc value) {
    p.PrintKeyString(name, StdVideoH264AspectRatioIdcString(value));
}
std::string StdVideoH264WeightedBipredIdcString(StdVideoH264WeightedBipredIdc value) {
    switch (value) {
        case STD_VIDEO_H264_WEIGHTED_BIPRED_IDC_DEFAULT: return "STD_VIDEO_H264_WEIGHTED_BIPRED_IDC_DEFAULT";
        case STD_VIDEO_H264_WEIGHTED_BIPRED_IDC_EXPLICIT: return "STD_VIDEO_H264_WEIGHTED_BIPRED_IDC_EXPLICIT";
        case STD_VIDEO_H264_WEIGHTED_BIPRED_IDC_IMPLICIT: return "STD_VIDEO_H264_WEIGHTED_BIPRED_IDC_IMPLICIT";
        case STD_VIDEO_H264_WEIGHTED_BIPRED_IDC_INVALID: return "STD_VIDEO_H264_WEIGHTED_BIPRED_IDC_INVALID";
        default: return std::string("UNKNOWN_StdVideoH264WeightedBipredIdc_value") + std::to_string(value);
    }
}
void DumpStdVideoH264WeightedBipredIdc(Printer &p, std::string name, StdVideoH264WeightedBipredIdc value) {
    p.PrintKeyString(name, StdVideoH264WeightedBipredIdcString(value));
}
std::string StdVideoH264ModificationOfPicNumsIdcString(StdVideoH264ModificationOfPicNumsIdc value) {
    switch (value) {
        case STD_VIDEO_H264_MODIFICATION_OF_PIC_NUMS_IDC_SHORT_TERM_SUBTRACT: return "STD_VIDEO_H264_MODIFICATION_OF_PIC_NUMS_IDC_SHORT_TERM_SUBTRACT";
        case STD_VIDEO_H264_MODIFICATION_OF_PIC_NUMS_IDC_SHORT_TERM_ADD: return "STD_VIDEO_H264_MODIFICATION_OF_PIC_NUMS_IDC_SHORT_TERM_ADD";
        case STD_VIDEO_H264_MODIFICATION_OF_PIC_NUMS_IDC_LONG_TERM: return "STD_VIDEO_H264_MODIFICATION_OF_PIC_NUMS_IDC_LONG_TERM";
        case STD_VIDEO_H264_MODIFICATION_OF_PIC_NUMS_IDC_END: return "STD_VIDEO_H264_MODIFICATION_OF_PIC_NUMS_IDC_END";
        case STD_VIDEO_H264_MODIFICATION_OF_PIC_NUMS_IDC_INVALID: return "STD_VIDEO_H264_MODIFICATION_OF_PIC_NUMS_IDC_INVALID";
        default: return std::string("UNKNOWN_StdVideoH264ModificationOfPicNumsIdc_value") + std::to_string(value);
    }
}
void DumpStdVideoH264ModificationOfPicNumsIdc(Printer &p, std::string name, StdVideoH264ModificationOfPicNumsIdc value) {
    p.PrintKeyString(name, StdVideoH264ModificationOfPicNumsIdcString(value));
}
std::string StdVideoH264MemMgmtControlOpString(StdVideoH264MemMgmtControlOp value) {
    switch (value) {
        case STD_VIDEO_H264_MEM_MGMT_CONTROL_OP_END: return "STD_VIDEO_H264_MEM_MGMT_CONTROL_OP_END";
        case STD_VIDEO_H264_MEM_MGMT_CONTROL_OP_UNMARK_SHORT_TERM: return "STD_VIDEO_H264_MEM_MGMT_CONTROL_OP_UNMARK_SHORT_TERM";
        case STD_VIDEO_H264_MEM_MGMT_CONTROL_OP_UNMARK_LONG_TERM: return "STD_VIDEO_H264_MEM_MGMT_CONTROL_OP_UNMARK_LONG_TERM";
        case STD_VIDEO_H264_MEM_MGMT_CONTROL_OP_MARK_LONG_TERM: return "STD_VIDEO_H264_MEM_MGMT_CONTROL_OP_MARK_LONG_TERM";
        case STD_VIDEO_H264_MEM_MGMT_CONTROL_OP_SET_MAX_LONG_TERM_INDEX: return "STD_VIDEO_H264_MEM_MGMT_CONTROL_OP_SET_MAX_LONG_TERM_INDEX";
        case STD_VIDEO_H264_MEM_MGMT_CONTROL_OP_UNMARK_ALL: return "STD_VIDEO_H264_MEM_MGMT_CONTROL_OP_UNMARK_ALL";
        case STD_VIDEO_H264_MEM_MGMT_CONTROL_OP_MARK_CURRENT_AS_LONG_TERM: return "STD_VIDEO_H264_MEM_MGMT_CONTROL_OP_MARK_CURRENT_AS_LONG_TERM";
        case STD_VIDEO_H264_MEM_MGMT_CONTROL_OP_INVALID: return "STD_VIDEO_H264_MEM_MGMT_CONTROL_OP_INVALID";
        default: return std::string("UNKNOWN_StdVideoH264MemMgmtControlOp_value") + std::to_string(value);
    }
}
void DumpStdVideoH264MemMgmtControlOp(Printer &p, std::string name, StdVideoH264MemMgmtControlOp value) {
    p.PrintKeyString(name, StdVideoH264MemMgmtControlOpString(value));
}
std::string StdVideoH264CabacInitIdcString(StdVideoH264CabacInitIdc value) {
    switch (value) {
        case STD_VIDEO_H264_CABAC_INIT_IDC_0: return "STD_VIDEO_H264_CABAC_INIT_IDC_0";
        case STD_VIDEO_H264_CABAC_INIT_IDC_1: return "STD_VIDEO_H264_CABAC_INIT_IDC_1";
        case STD_VIDEO_H264_CABAC_INIT_IDC_2: return "STD_VIDEO_H264_CABAC_INIT_IDC_2";
        case STD_VIDEO_H264_CABAC_INIT_IDC_INVALID: return "STD_VIDEO_H264_CABAC_INIT_IDC_INVALID";
        default: return std::string("UNKNOWN_StdVideoH264CabacInitIdc_value") + std::to_string(value);
    }
}
void DumpStdVideoH264CabacInitIdc(Printer &p, std::string name, StdVideoH264CabacInitIdc value) {
    p.PrintKeyString(name, StdVideoH264CabacInitIdcString(value));
}
std::string StdVideoH264DisableDeblockingFilterIdcString(StdVideoH264DisableDeblockingFilterIdc value) {
    switch (value) {
        case STD_VIDEO_H264_DISABLE_DEBLOCKING_FILTER_IDC_DISABLED: return "STD_VIDEO_H264_DISABLE_DEBLOCKING_FILTER_IDC_DISABLED";
        case STD_VIDEO_H264_DISABLE_DEBLOCKING_FILTER_IDC_ENABLED: return "STD_VIDEO_H264_DISABLE_DEBLOCKING_FILTER_IDC_ENABLED";
        case STD_VIDEO_H264_DISABLE_DEBLOCKING_FILTER_IDC_PARTIAL: return "STD_VIDEO_H264_DISABLE_DEBLOCKING_FILTER_IDC_PARTIAL";
        case STD_VIDEO_H264_DISABLE_DEBLOCKING_FILTER_IDC_INVALID: return "STD_VIDEO_H264_DISABLE_DEBLOCKING_FILTER_IDC_INVALID";
        default: return std::string("UNKNOWN_StdVideoH264DisableDeblockingFilterIdc_value") + std::to_string(value);
    }
}
void DumpStdVideoH264DisableDeblockingFilterIdc(Printer &p, std::string name, StdVideoH264DisableDeblockingFilterIdc value) {
    p.PrintKeyString(name, StdVideoH264DisableDeblockingFilterIdcString(value));
}
std::string StdVideoH264SliceTypeString(StdVideoH264SliceType value) {
    switch (value) {
        case STD_VIDEO_H264_SLICE_TYPE_P: return "STD_VIDEO_H264_SLICE_TYPE_P";
        case STD_VIDEO_H264_SLICE_TYPE_B: return "STD_VIDEO_H264_SLICE_TYPE_B";
        case STD_VIDEO_H264_SLICE_TYPE_I: return "STD_VIDEO_H264_SLICE_TYPE_I";
        case STD_VIDEO_H264_SLICE_TYPE_INVALID: return "STD_VIDEO_H264_SLICE_TYPE_INVALID";
        default: return std::string("UNKNOWN_StdVideoH264SliceType_value") + std::to_string(value);
    }
}
void DumpStdVideoH264SliceType(Printer &p, std::string name, StdVideoH264SliceType value) {
    p.PrintKeyString(name, StdVideoH264SliceTypeString(value));
}
std::string StdVideoH264PictureTypeString(StdVideoH264PictureType value) {
    switch (value) {
        case STD_VIDEO_H264_PICTURE_TYPE_P: return "STD_VIDEO_H264_PICTURE_TYPE_P";
        case STD_VIDEO_H264_PICTURE_TYPE_B: return "STD_VIDEO_H264_PICTURE_TYPE_B";
        case STD_VIDEO_H264_PICTURE_TYPE_I: return "STD_VIDEO_H264_PICTURE_TYPE_I";
        case STD_VIDEO_H264_PICTURE_TYPE_IDR: return "STD_VIDEO_H264_PICTURE_TYPE_IDR";
        case STD_VIDEO_H264_PICTURE_TYPE_INVALID: return "STD_VIDEO_H264_PICTURE_TYPE_INVALID";
        default: return std::string("UNKNOWN_StdVideoH264PictureType_value") + std::to_string(value);
    }
}
void DumpStdVideoH264PictureType(Printer &p, std::string name, StdVideoH264PictureType value) {
    p.PrintKeyString(name, StdVideoH264PictureTypeString(value));
}
std::string StdVideoH264NonVclNaluTypeString(StdVideoH264NonVclNaluType value) {
    switch (value) {
        case STD_VIDEO_H264_NON_VCL_NALU_TYPE_SPS: return "STD_VIDEO_H264_NON_VCL_NALU_TYPE_SPS";
        case STD_VIDEO_H264_NON_VCL_NALU_TYPE_PPS: return "STD_VIDEO_H264_NON_VCL_NALU_TYPE_PPS";
        case STD_VIDEO_H264_NON_VCL_NALU_TYPE_AUD: return "STD_VIDEO_H264_NON_VCL_NALU_TYPE_AUD";
        case STD_VIDEO_H264_NON_VCL_NALU_TYPE_PREFIX: return "STD_VIDEO_H264_NON_VCL_NALU_TYPE_PREFIX";
        case STD_VIDEO_H264_NON_VCL_NALU_TYPE_END_OF_SEQUENCE: return "STD_VIDEO_H264_NON_VCL_NALU_TYPE_END_OF_SEQUENCE";
        case STD_VIDEO_H264_NON_VCL_NALU_TYPE_END_OF_STREAM: return "STD_VIDEO_H264_NON_VCL_NALU_TYPE_END_OF_STREAM";
        case STD_VIDEO_H264_NON_VCL_NALU_TYPE_PRECODED: return "STD_VIDEO_H264_NON_VCL_NALU_TYPE_PRECODED";
        case STD_VIDEO_H264_NON_VCL_NALU_TYPE_INVALID: return "STD_VIDEO_H264_NON_VCL_NALU_TYPE_INVALID";
        default: return std::string("UNKNOWN_StdVideoH264NonVclNaluType_value") + std::to_string(value);
    }
}
void DumpStdVideoH264NonVclNaluType(Printer &p, std::string name, StdVideoH264NonVclNaluType value) {
    p.PrintKeyString(name, StdVideoH264NonVclNaluTypeString(value));
}
std::string StdVideoDecodeH264FieldOrderCountString(StdVideoDecodeH264FieldOrderCount value) {
    switch (value) {
        case STD_VIDEO_DECODE_H264_FIELD_ORDER_COUNT_TOP: return "STD_VIDEO_DECODE_H264_FIELD_ORDER_COUNT_TOP";
        case STD_VIDEO_DECODE_H264_FIELD_ORDER_COUNT_BOTTOM: return "STD_VIDEO_DECODE_H264_FIELD_ORDER_COUNT_BOTTOM";
        case STD_VIDEO_DECODE_H264_FIELD_ORDER_COUNT_INVALID: return "STD_VIDEO_DECODE_H264_FIELD_ORDER_COUNT_INVALID";
        default: return std::string("UNKNOWN_StdVideoDecodeH264FieldOrderCount_value") + std::to_string(value);
    }
}
void DumpStdVideoDecodeH264FieldOrderCount(Printer &p, std::string name, StdVideoDecodeH264FieldOrderCount value) {
    p.PrintKeyString(name, StdVideoDecodeH264FieldOrderCountString(value));
}
std::string StdVideoH265ChromaFormatIdcString(StdVideoH265ChromaFormatIdc value) {
    switch (value) {
        case STD_VIDEO_H265_CHROMA_FORMAT_IDC_MONOCHROME: return "STD_VIDEO_H265_CHROMA_FORMAT_IDC_MONOCHROME";
        case STD_VIDEO_H265_CHROMA_FORMAT_IDC_420: return "STD_VIDEO_H265_CHROMA_FORMAT_IDC_420";
        case STD_VIDEO_H265_CHROMA_FORMAT_IDC_422: return "STD_VIDEO_H265_CHROMA_FORMAT_IDC_422";
        case STD_VIDEO_H265_CHROMA_FORMAT_IDC_444: return "STD_VIDEO_H265_CHROMA_FORMAT_IDC_444";
        case STD_VIDEO_H265_CHROMA_FORMAT_IDC_INVALID: return "STD_VIDEO_H265_CHROMA_FORMAT_IDC_INVALID";
        default: return std::string("UNKNOWN_StdVideoH265ChromaFormatIdc_value") + std::to_string(value);
    }
}
void DumpStdVideoH265ChromaFormatIdc(Printer &p, std::string name, StdVideoH265ChromaFormatIdc value) {
    p.PrintKeyString(name, StdVideoH265ChromaFormatIdcString(value));
}
std::string StdVideoH265ProfileIdcString(StdVideoH265ProfileIdc value) {
    switch (value) {
        case STD_VIDEO_H265_PROFILE_IDC_MAIN: return "STD_VIDEO_H265_PROFILE_IDC_MAIN";
        case STD_VIDEO_H265_PROFILE_IDC_MAIN_10: return "STD_VIDEO_H265_PROFILE_IDC_MAIN_10";
        case STD_VIDEO_H265_PROFILE_IDC_MAIN_STILL_PICTURE: return "STD_VIDEO_H265_PROFILE_IDC_MAIN_STILL_PICTURE";
        case STD_VIDEO_H265_PROFILE_IDC_FORMAT_RANGE_EXTENSIONS: return "STD_VIDEO_H265_PROFILE_IDC_FORMAT_RANGE_EXTENSIONS";
        case STD_VIDEO_H265_PROFILE_IDC_SCC_EXTENSIONS: return "STD_VIDEO_H265_PROFILE_IDC_SCC_EXTENSIONS";
        case STD_VIDEO_H265_PROFILE_IDC_INVALID: return "STD_VIDEO_H265_PROFILE_IDC_INVALID";
        default: return std::string("UNKNOWN_StdVideoH265ProfileIdc_value") + std::to_string(value);
    }
}
void DumpStdVideoH265ProfileIdc(Printer &p, std::string name, StdVideoH265ProfileIdc value) {
    p.PrintKeyString(name, StdVideoH265ProfileIdcString(value));
}
std::string StdVideoH265LevelIdcString(StdVideoH265LevelIdc value) {
    switch (value) {
        case STD_VIDEO_H265_LEVEL_IDC_1_0: return "STD_VIDEO_H265_LEVEL_IDC_1_0";
        case STD_VIDEO_H265_LEVEL_IDC_2_0: return "STD_VIDEO_H265_LEVEL_IDC_2_0";
        case STD_VIDEO_H265_LEVEL_IDC_2_1: return "STD_VIDEO_H265_LEVEL_IDC_2_1";
        case STD_VIDEO_H265_LEVEL_IDC_3_0: return "STD_VIDEO_H265_LEVEL_IDC_3_0";
        case STD_VIDEO_H265_LEVEL_IDC_3_1: return "STD_VIDEO_H265_LEVEL_IDC_3_1";
        case STD_VIDEO_H265_LEVEL_IDC_4_0: return "STD_VIDEO_H265_LEVEL_IDC_4_0";
        case STD_VIDEO_H265_LEVEL_IDC_4_1: return "STD_VIDEO_H265_LEVEL_IDC_4_1";
        case STD_VIDEO_H265_LEVEL_IDC_5_0: return "STD_VIDEO_H265_LEVEL_IDC_5_0";
        case STD_VIDEO_H265_LEVEL_IDC_5_1: return "STD_VIDEO_H265_LEVEL_IDC_5_1";
        case STD_VIDEO_H265_LEVEL_IDC_5_2: return "STD_VIDEO_H265_LEVEL_IDC_5_2";
        case STD_VIDEO_H265_LEVEL_IDC_6_0: return "STD_VIDEO_H265_LEVEL_IDC_6_0";
        case STD_VIDEO_H265_LEVEL_IDC_6_1: return "STD_VIDEO_H265_LEVEL_IDC_6_1";
        case STD_VIDEO_H265_LEVEL_IDC_6_2: return "STD_VIDEO_H265_LEVEL_IDC_6_2";
        case STD_VIDEO_H265_LEVEL_IDC_INVALID: return "STD_VIDEO_H265_LEVEL_IDC_INVALID";
        default: return std::string("UNKNOWN_StdVideoH265LevelIdc_value") + std::to_string(value);
    }
}
void DumpStdVideoH265LevelIdc(Printer &p, std::string name, StdVideoH265LevelIdc value) {
    p.PrintKeyString(name, StdVideoH265LevelIdcString(value));
}
std::string StdVideoH265SliceTypeString(StdVideoH265SliceType value) {
    switch (value) {
        case STD_VIDEO_H265_SLICE_TYPE_B: return "STD_VIDEO_H265_SLICE_TYPE_B";
        case STD_VIDEO_H265_SLICE_TYPE_P: return "STD_VIDEO_H265_SLICE_TYPE_P";
        case STD_VIDEO_H265_SLICE_TYPE_I: return "STD_VIDEO_H265_SLICE_TYPE_I";
        case STD_VIDEO_H265_SLICE_TYPE_INVALID: return "STD_VIDEO_H265_SLICE_TYPE_INVALID";
        default: return std::string("UNKNOWN_StdVideoH265SliceType_value") + std::to_string(value);
    }
}
void DumpStdVideoH265SliceType(Printer &p, std::string name, StdVideoH265SliceType value) {
    p.PrintKeyString(name, StdVideoH265SliceTypeString(value));
}
std::string StdVideoH265PictureTypeString(StdVideoH265PictureType value) {
    switch (value) {
        case STD_VIDEO_H265_PICTURE_TYPE_P: return "STD_VIDEO_H265_PICTURE_TYPE_P";
        case STD_VIDEO_H265_PICTURE_TYPE_B: return "STD_VIDEO_H265_PICTURE_TYPE_B";
        case STD_VIDEO_H265_PICTURE_TYPE_I: return "STD_VIDEO_H265_PICTURE_TYPE_I";
        case STD_VIDEO_H265_PICTURE_TYPE_IDR: return "STD_VIDEO_H265_PICTURE_TYPE_IDR";
        case STD_VIDEO_H265_PICTURE_TYPE_INVALID: return "STD_VIDEO_H265_PICTURE_TYPE_INVALID";
        default: return std::string("UNKNOWN_StdVideoH265PictureType_value") + std::to_string(value);
    }
}
void DumpStdVideoH265PictureType(Printer &p, std::string name, StdVideoH265PictureType value) {
    p.PrintKeyString(name, StdVideoH265PictureTypeString(value));
}
std::string StdVideoH265AspectRatioIdcString(StdVideoH265AspectRatioIdc value) {
    switch (value) {
        case STD_VIDEO_H265_ASPECT_RATIO_IDC_UNSPECIFIED: return "STD_VIDEO_H265_ASPECT_RATIO_IDC_UNSPECIFIED";
        case STD_VIDEO_H265_ASPECT_RATIO_IDC_SQUARE: return "STD_VIDEO_H265_ASPECT_RATIO_IDC_SQUARE";
        case STD_VIDEO_H265_ASPECT_RATIO_IDC_12_11: return "STD_VIDEO_H265_ASPECT_RATIO_IDC_12_11";
        case STD_VIDEO_H265_ASPECT_RATIO_IDC_10_11: return "STD_VIDEO_H265_ASPECT_RATIO_IDC_10_11";
        case STD_VIDEO_H265_ASPECT_RATIO_IDC_16_11: return "STD_VIDEO_H265_ASPECT_RATIO_IDC_16_11";
        case STD_VIDEO_H265_ASPECT_RATIO_IDC_40_33: return "STD_VIDEO_H265_ASPECT_RATIO_IDC_40_33";
        case STD_VIDEO_H265_ASPECT_RATIO_IDC_24_11: return "STD_VIDEO_H265_ASPECT_RATIO_IDC_24_11";
        case STD_VIDEO_H265_ASPECT_RATIO_IDC_20_11: return "STD_VIDEO_H265_ASPECT_RATIO_IDC_20_11";
        case STD_VIDEO_H265_ASPECT_RATIO_IDC_32_11: return "STD_VIDEO_H265_ASPECT_RATIO_IDC_32_11";
        case STD_VIDEO_H265_ASPECT_RATIO_IDC_80_33: return "STD_VIDEO_H265_ASPECT_RATIO_IDC_80_33";
        case STD_VIDEO_H265_ASPECT_RATIO_IDC_18_11: return "STD_VIDEO_H265_ASPECT_RATIO_IDC_18_11";
        case STD_VIDEO_H265_ASPECT_RATIO_IDC_15_11: return "STD_VIDEO_H265_ASPECT_RATIO_IDC_15_11";
        case STD_VIDEO_H265_ASPECT_RATIO_IDC_64_33: return "STD_VIDEO_H265_ASPECT_RATIO_IDC_64_33";
        case STD_VIDEO_H265_ASPECT_RATIO_IDC_160_99: return "STD_VIDEO_H265_ASPECT_RATIO_IDC_160_99";
        case STD_VIDEO_H265_ASPECT_RATIO_IDC_4_3: return "STD_VIDEO_H265_ASPECT_RATIO_IDC_4_3";
        case STD_VIDEO_H265_ASPECT_RATIO_IDC_3_2: return "STD_VIDEO_H265_ASPECT_RATIO_IDC_3_2";
        case STD_VIDEO_H265_ASPECT_RATIO_IDC_2_1: return "STD_VIDEO_H265_ASPECT_RATIO_IDC_2_1";
        case STD_VIDEO_H265_ASPECT_RATIO_IDC_EXTENDED_SAR: return "STD_VIDEO_H265_ASPECT_RATIO_IDC_EXTENDED_SAR";
        case STD_VIDEO_H265_ASPECT_RATIO_IDC_INVALID: return "STD_VIDEO_H265_ASPECT_RATIO_IDC_INVALID";
        default: return std::string("UNKNOWN_StdVideoH265AspectRatioIdc_value") + std::to_string(value);
    }
}
void DumpStdVideoH265AspectRatioIdc(Printer &p, std::string name, StdVideoH265AspectRatioIdc value) {
    p.PrintKeyString(name, StdVideoH265AspectRatioIdcString(value));
}
std::string StdVideoVP9ProfileString(StdVideoVP9Profile value) {
    switch (value) {
        case STD_VIDEO_VP9_PROFILE_0: return "STD_VIDEO_VP9_PROFILE_0";
        case STD_VIDEO_VP9_PROFILE_1: return "STD_VIDEO_VP9_PROFILE_1";
        case STD_VIDEO_VP9_PROFILE_2: return "STD_VIDEO_VP9_PROFILE_2";
        case STD_VIDEO_VP9_PROFILE_3: return "STD_VIDEO_VP9_PROFILE_3";
        case STD_VIDEO_VP9_PROFILE_INVALID: return "STD_VIDEO_VP9_PROFILE_INVALID";
        default: return std::string("UNKNOWN_StdVideoVP9Profile_value") + std::to_string(value);
    }
}
void DumpStdVideoVP9Profile(Printer &p, std::string name, StdVideoVP9Profile value) {
    p.PrintKeyString(name, StdVideoVP9ProfileString(value));
}
std::string StdVideoVP9LevelString(StdVideoVP9Level value) {
    switch (value) {
        case STD_VIDEO_VP9_LEVEL_1_0: return "STD_VIDEO_VP9_LEVEL_1_0";
        case STD_VIDEO_VP9_LEVEL_1_1: return "STD_VIDEO_VP9_LEVEL_1_1";
        case STD_VIDEO_VP9_LEVEL_2_0: return "STD_VIDEO_VP9_LEVEL_2_0";
        case STD_VIDEO_VP9_LEVEL_2_1: return "STD_VIDEO_VP9_LEVEL_2_1";
        case STD_VIDEO_VP9_LEVEL_3_0: return "STD_VIDEO_VP9_LEVEL_3_0";
        case STD_VIDEO_VP9_LEVEL_3_1: return "STD_VIDEO_VP9_LEVEL_3_1";
        case STD_VIDEO_VP9_LEVEL_4_0: return "STD_VIDEO_VP9_LEVEL_4_0";
        case STD_VIDEO_VP9_LEVEL_4_1: return "STD_VIDEO_VP9_LEVEL_4_1";
        case STD_VIDEO_VP9_LEVEL_5_0: return "STD_VIDEO_VP9_LEVEL_5_0";
        case STD_VIDEO_VP9_LEVEL_5_1: return "STD_VIDEO_VP9_LEVEL_5_1";
        case STD_VIDEO_VP9_LEVEL_5_2: return "STD_VIDEO_VP9_LEVEL_5_2";
        case STD_VIDEO_VP9_LEVEL_6_0: return "STD_VIDEO_VP9_LEVEL_6_0";
        case STD_VIDEO_VP9_LEVEL_6_1: return "STD_VIDEO_VP9_LEVEL_6_1";
        case STD_VIDEO_VP9_LEVEL_6_2: return "STD_VIDEO_VP9_LEVEL_6_2";
        case STD_VIDEO_VP9_LEVEL_INVALID: return "STD_VIDEO_VP9_LEVEL_INVALID";
        default: return std::string("UNKNOWN_StdVideoVP9Level_value") + std::to_string(value);
    }
}
void DumpStdVideoVP9Level(Printer &p, std::string name, StdVideoVP9Level value) {
    p.PrintKeyString(name, StdVideoVP9LevelString(value));
}
std::string StdVideoVP9FrameTypeString(StdVideoVP9FrameType value) {
    switch (value) {
        case STD_VIDEO_VP9_FRAME_TYPE_KEY: return "STD_VIDEO_VP9_FRAME_TYPE_KEY";
        case STD_VIDEO_VP9_FRAME_TYPE_NON_KEY: return "STD_VIDEO_VP9_FRAME_TYPE_NON_KEY";
        case STD_VIDEO_VP9_FRAME_TYPE_INVALID: return "STD_VIDEO_VP9_FRAME_TYPE_INVALID";
        default: return std::string("UNKNOWN_StdVideoVP9FrameType_value") + std::to_string(value);
    }
}
void DumpStdVideoVP9FrameType(Printer &p, std::string name, StdVideoVP9FrameType value) {
    p.PrintKeyString(name, StdVideoVP9FrameTypeString(value));
}
std::string StdVideoVP9ReferenceNameString(StdVideoVP9ReferenceName value) {
    switch (value) {
        case STD_VIDEO_VP9_REFERENCE_NAME_INTRA_FRAME: return "STD_VIDEO_VP9_REFERENCE_NAME_INTRA_FRAME";
        case STD_VIDEO_VP9_REFERENCE_NAME_LAST_FRAME: return "STD_VIDEO_VP9_REFERENCE_NAME_LAST_FRAME";
        case STD_VIDEO_VP9_REFERENCE_NAME_GOLDEN_FRAME: return "STD_VIDEO_VP9_REFERENCE_NAME_GOLDEN_FRAME";
        case STD_VIDEO_VP9_REFERENCE_NAME_ALTREF_FRAME: return "STD_VIDEO_VP9_REFERENCE_NAME_ALTREF_FRAME";
        case STD_VIDEO_VP9_REFERENCE_NAME_INVALID: return "STD_VIDEO_VP9_REFERENCE_NAME_INVALID";
        default: return std::string("UNKNOWN_StdVideoVP9ReferenceName_value") + std::to_string(value);
    }
}
void DumpStdVideoVP9ReferenceName(Printer &p, std::string name, StdVideoVP9ReferenceName value) {
    p.PrintKeyString(name, StdVideoVP9ReferenceNameString(value));
}
std::string StdVideoVP9InterpolationFilterString(StdVideoVP9InterpolationFilter value) {
    switch (value) {
        case STD_VIDEO_VP9_INTERPOLATION_FILTER_EIGHTTAP: return "STD_VIDEO_VP9_INTERPOLATION_FILTER_EIGHTTAP";
        case STD_VIDEO_VP9_INTERPOLATION_FILTER_EIGHTTAP_SMOOTH: return "STD_VIDEO_VP9_INTERPOLATION_FILTER_EIGHTTAP_SMOOTH";
        case STD_VIDEO_VP9_INTERPOLATION_FILTER_EIGHTTAP_SHARP: return "STD_VIDEO_VP9_INTERPOLATION_FILTER_EIGHTTAP_SHARP";
        case STD_VIDEO_VP9_INTERPOLATION_FILTER_BILINEAR: return "STD_VIDEO_VP9_INTERPOLATION_FILTER_BILINEAR";
        case STD_VIDEO_VP9_INTERPOLATION_FILTER_SWITCHABLE: return "STD_VIDEO_VP9_INTERPOLATION_FILTER_SWITCHABLE";
        case STD_VIDEO_VP9_INTERPOLATION_FILTER_INVALID: return "STD_VIDEO_VP9_INTERPOLATION_FILTER_INVALID";
        default: return std::string("UNKNOWN_StdVideoVP9InterpolationFilter_value") + std::to_string(value);
    }
}
void DumpStdVideoVP9InterpolationFilter(Printer &p, std::string name, StdVideoVP9InterpolationFilter value) {
    p.PrintKeyString(name, StdVideoVP9InterpolationFilterString(value));
}
std::string StdVideoVP9ColorSpaceString(StdVideoVP9ColorSpace value) {
    switch (value) {
        case STD_VIDEO_VP9_COLOR_SPACE_UNKNOWN: return "STD_VIDEO_VP9_COLOR_SPACE_UNKNOWN";
        case STD_VIDEO_VP9_COLOR_SPACE_BT_601: return "STD_VIDEO_VP9_COLOR_SPACE_BT_601";
        case STD_VIDEO_VP9_COLOR_SPACE_BT_709: return "STD_VIDEO_VP9_COLOR_SPACE_BT_709";
        case STD_VIDEO_VP9_COLOR_SPACE_SMPTE_170: return "STD_VIDEO_VP9_COLOR_SPACE_SMPTE_170";
        case STD_VIDEO_VP9_COLOR_SPACE_SMPTE_240: return "STD_VIDEO_VP9_COLOR_SPACE_SMPTE_240";
        case STD_VIDEO_VP9_COLOR_SPACE_BT_2020: return "STD_VIDEO_VP9_COLOR_SPACE_BT_2020";
        case STD_VIDEO_VP9_COLOR_SPACE_RESERVED: return "STD_VIDEO_VP9_COLOR_SPACE_RESERVED";
        case STD_VIDEO_VP9_COLOR_SPACE_RGB: return "STD_VIDEO_VP9_COLOR_SPACE_RGB";
        case STD_VIDEO_VP9_COLOR_SPACE_INVALID: return "STD_VIDEO_VP9_COLOR_SPACE_INVALID";
        default: return std::string("UNKNOWN_StdVideoVP9ColorSpace_value") + std::to_string(value);
    }
}
void DumpStdVideoVP9ColorSpace(Printer &p, std::string name, StdVideoVP9ColorSpace value) {
    p.PrintKeyString(name, StdVideoVP9ColorSpaceString(value));
}
std::string StdVideoAV1ProfileString(StdVideoAV1Profile value) {
    switch (value) {
        case STD_VIDEO_AV1_PROFILE_MAIN: return "STD_VIDEO_AV1_PROFILE_MAIN";
        case STD_VIDEO_AV1_PROFILE_HIGH: return "STD_VIDEO_AV1_PROFILE_HIGH";
        case STD_VIDEO_AV1_PROFILE_PROFESSIONAL: return "STD_VIDEO_AV1_PROFILE_PROFESSIONAL";
        case STD_VIDEO_AV1_PROFILE_INVALID: return "STD_VIDEO_AV1_PROFILE_INVALID";
        default: return std::string("UNKNOWN_StdVideoAV1Profile_value") + std::to_string(value);
    }
}
void DumpStdVideoAV1Profile(Printer &p, std::string name, StdVideoAV1Profile value) {
    p.PrintKeyString(name, StdVideoAV1ProfileString(value));
}
std::string StdVideoAV1LevelString(StdVideoAV1Level value) {
    switch (value) {
        case STD_VIDEO_AV1_LEVEL_2_0: return "STD_VIDEO_AV1_LEVEL_2_0";
        case STD_VIDEO_AV1_LEVEL_2_1: return "STD_VIDEO_AV1_LEVEL_2_1";
        case STD_VIDEO_AV1_LEVEL_2_2: return "STD_VIDEO_AV1_LEVEL_2_2";
        case STD_VIDEO_AV1_LEVEL_2_3: return "STD_VIDEO_AV1_LEVEL_2_3";
        case STD_VIDEO_AV1_LEVEL_3_0: return "STD_VIDEO_AV1_LEVEL_3_0";
        case STD_VIDEO_AV1_LEVEL_3_1: return "STD_VIDEO_AV1_LEVEL_3_1";
        case STD_VIDEO_AV1_LEVEL_3_2: return "STD_VIDEO_AV1_LEVEL_3_2";
        case STD_VIDEO_AV1_LEVEL_3_3: return "STD_VIDEO_AV1_LEVEL_3_3";
        case STD_VIDEO_AV1_LEVEL_4_0: return "STD_VIDEO_AV1_LEVEL_4_0";
        case STD_VIDEO_AV1_LEVEL_4_1: return "STD_VIDEO_AV1_LEVEL_4_1";
        case STD_VIDEO_AV1_LEVEL_4_2: return "STD_VIDEO_AV1_LEVEL_4_2";
        case STD_VIDEO_AV1_LEVEL_4_3: return "STD_VIDEO_AV1_LEVEL_4_3";
        case STD_VIDEO_AV1_LEVEL_5_0: return "STD_VIDEO_AV1_LEVEL_5_0";
        case STD_VIDEO_AV1_LEVEL_5_1: return "STD_VIDEO_AV1_LEVEL_5_1";
        case STD_VIDEO_AV1_LEVEL_5_2: return "STD_VIDEO_AV1_LEVEL_5_2";
        case STD_VIDEO_AV1_LEVEL_5_3: return "STD_VIDEO_AV1_LEVEL_5_3";
        case STD_VIDEO_AV1_LEVEL_6_0: return "STD_VIDEO_AV1_LEVEL_6_0";
        case STD_VIDEO_AV1_LEVEL_6_1: return "STD_VIDEO_AV1_LEVEL_6_1";
        case STD_VIDEO_AV1_LEVEL_6_2: return "STD_VIDEO_AV1_LEVEL_6_2";
        case STD_VIDEO_AV1_LEVEL_6_3: return "STD_VIDEO_AV1_LEVEL_6_3";
        case STD_VIDEO_AV1_LEVEL_7_0: return "STD_VIDEO_AV1_LEVEL_7_0";
        case STD_VIDEO_AV1_LEVEL_7_1: return "STD_VIDEO_AV1_LEVEL_7_1";
        case STD_VIDEO_AV1_LEVEL_7_2: return "STD_VIDEO_AV1_LEVEL_7_2";
        case STD_VIDEO_AV1_LEVEL_7_3: return "STD_VIDEO_AV1_LEVEL_7_3";
        case STD_VIDEO_AV1_LEVEL_INVALID: return "STD_VIDEO_AV1_LEVEL_INVALID";
        default: return std::string("UNKNOWN_StdVideoAV1Level_value") + std::to_string(value);
    }
}
void DumpStdVideoAV1Level(Printer &p, std::string name, StdVideoAV1Level value) {
    p.PrintKeyString(name, StdVideoAV1LevelString(value));
}
std::string StdVideoAV1FrameTypeString(StdVideoAV1FrameType value) {
    switch (value) {
        case STD_VIDEO_AV1_FRAME_TYPE_KEY: return "STD_VIDEO_AV1_FRAME_TYPE_KEY";
        case STD_VIDEO_AV1_FRAME_TYPE_INTER: return "STD_VIDEO_AV1_FRAME_TYPE_INTER";
        case STD_VIDEO_AV1_FRAME_TYPE_INTRA_ONLY: return "STD_VIDEO_AV1_FRAME_TYPE_INTRA_ONLY";
        case STD_VIDEO_AV1_FRAME_TYPE_SWITCH: return "STD_VIDEO_AV1_FRAME_TYPE_SWITCH";
        case STD_VIDEO_AV1_FRAME_TYPE_INVALID: return "STD_VIDEO_AV1_FRAME_TYPE_INVALID";
        default: return std::string("UNKNOWN_StdVideoAV1FrameType_value") + std::to_string(value);
    }
}
void DumpStdVideoAV1FrameType(Printer &p, std::string name, StdVideoAV1FrameType value) {
    p.PrintKeyString(name, StdVideoAV1FrameTypeString(value));
}
std::string StdVideoAV1ReferenceNameString(StdVideoAV1ReferenceName value) {
    switch (value) {
        case STD_VIDEO_AV1_REFERENCE_NAME_INTRA_FRAME: return "STD_VIDEO_AV1_REFERENCE_NAME_INTRA_FRAME";
        case STD_VIDEO_AV1_REFERENCE_NAME_LAST_FRAME: return "STD_VIDEO_AV1_REFERENCE_NAME_LAST_FRAME";
        case STD_VIDEO_AV1_REFERENCE_NAME_LAST2_FRAME: return "STD_VIDEO_AV1_REFERENCE_NAME_LAST2_FRAME";
        case STD_VIDEO_AV1_REFERENCE_NAME_LAST3_FRAME: return "STD_VIDEO_AV1_REFERENCE_NAME_LAST3_FRAME";
        case STD_VIDEO_AV1_REFERENCE_NAME_GOLDEN_FRAME: return "STD_VIDEO_AV1_REFERENCE_NAME_GOLDEN_FRAME";
        case STD_VIDEO_AV1_REFERENCE_NAME_BWDREF_FRAME: return "STD_VIDEO_AV1_REFERENCE_NAME_BWDREF_FRAME";
        case STD_VIDEO_AV1_REFERENCE_NAME_ALTREF2_FRAME: return "STD_VIDEO_AV1_REFERENCE_NAME_ALTREF2_FRAME";
        case STD_VIDEO_AV1_REFERENCE_NAME_ALTREF_FRAME: return "STD_VIDEO_AV1_REFERENCE_NAME_ALTREF_FRAME";
        case STD_VIDEO_AV1_REFERENCE_NAME_INVALID: return "STD_VIDEO_AV1_REFERENCE_NAME_INVALID";
        default: return std::string("UNKNOWN_StdVideoAV1ReferenceName_value") + std::to_string(value);
    }
}
void DumpStdVideoAV1ReferenceName(Printer &p, std::string name, StdVideoAV1ReferenceName value) {
    p.PrintKeyString(name, StdVideoAV1ReferenceNameString(value));
}
std::string StdVideoAV1InterpolationFilterString(StdVideoAV1InterpolationFilter value) {
    switch (value) {
        case STD_VIDEO_AV1_INTERPOLATION_FILTER_EIGHTTAP: return "STD_VIDEO_AV1_INTERPOLATION_FILTER_EIGHTTAP";
        case STD_VIDEO_AV1_INTERPOLATION_FILTER_EIGHTTAP_SMOOTH: return "STD_VIDEO_AV1_INTERPOLATION_FILTER_EIGHTTAP_SMOOTH";
        case STD_VIDEO_AV1_INTERPOLATION_FILTER_EIGHTTAP_SHARP: return "STD_VIDEO_AV1_INTERPOLATION_FILTER_EIGHTTAP_SHARP";
        case STD_VIDEO_AV1_INTERPOLATION_FILTER_BILINEAR: return "STD_VIDEO_AV1_INTERPOLATION_FILTER_BILINEAR";
        case STD_VIDEO_AV1_INTERPOLATION_FILTER_SWITCHABLE: return "STD_VIDEO_AV1_INTERPOLATION_FILTER_SWITCHABLE";
        case STD_VIDEO_AV1_INTERPOLATION_FILTER_INVALID: return "STD_VIDEO_AV1_INTERPOLATION_FILTER_INVALID";
        default: return std::string("UNKNOWN_StdVideoAV1InterpolationFilter_value") + std::to_string(value);
    }
}
void DumpStdVideoAV1InterpolationFilter(Printer &p, std::string name, StdVideoAV1InterpolationFilter value) {
    p.PrintKeyString(name, StdVideoAV1InterpolationFilterString(value));
}
std::string StdVideoAV1TxModeString(StdVideoAV1TxMode value) {
    switch (value) {
        case STD_VIDEO_AV1_TX_MODE_ONLY_4X4: return "STD_VIDEO_AV1_TX_MODE_ONLY_4X4";
        case STD_VIDEO_AV1_TX_MODE_LARGEST: return "STD_VIDEO_AV1_TX_MODE_LARGEST";
        case STD_VIDEO_AV1_TX_MODE_SELECT: return "STD_VIDEO_AV1_TX_MODE_SELECT";
        case STD_VIDEO_AV1_TX_MODE_INVALID: return "STD_VIDEO_AV1_TX_MODE_INVALID";
        default: return std::string("UNKNOWN_StdVideoAV1TxMode_value") + std::to_string(value);
    }
}
void DumpStdVideoAV1TxMode(Printer &p, std::string name, StdVideoAV1TxMode value) {
    p.PrintKeyString(name, StdVideoAV1TxModeString(value));
}
std::string StdVideoAV1FrameRestorationTypeString(StdVideoAV1FrameRestorationType value) {
    switch (value) {
        case STD_VIDEO_AV1_FRAME_RESTORATION_TYPE_NONE: return "STD_VIDEO_AV1_FRAME_RESTORATION_TYPE_NONE";
        case STD_VIDEO_AV1_FRAME_RESTORATION_TYPE_WIENER: return "STD_VIDEO_AV1_FRAME_RESTORATION_TYPE_WIENER";
        case STD_VIDEO_AV1_FRAME_RESTORATION_TYPE_SGRPROJ: return "STD_VIDEO_AV1_FRAME_RESTORATION_TYPE_SGRPROJ";
        case STD_VIDEO_AV1_FRAME_RESTORATION_TYPE_SWITCHABLE: return "STD_VIDEO_AV1_FRAME_RESTORATION_TYPE_SWITCHABLE";
        case STD_VIDEO_AV1_FRAME_RESTORATION_TYPE_INVALID: return "STD_VIDEO_AV1_FRAME_RESTORATION_TYPE_INVALID";
        default: return std::string("UNKNOWN_StdVideoAV1FrameRestorationType_value") + std::to_string(value);
    }
}
void DumpStdVideoAV1FrameRestorationType(Printer &p, std::string name, StdVideoAV1FrameRestorationType value) {
    p.PrintKeyString(name, StdVideoAV1FrameRestorationTypeString(value));
}
std::string StdVideoAV1ColorPrimariesString(StdVideoAV1ColorPrimaries value) {
    switch (value) {
        case STD_VIDEO_AV1_COLOR_PRIMARIES_BT_709: return "STD_VIDEO_AV1_COLOR_PRIMARIES_BT_709";
        case STD_VIDEO_AV1_COLOR_PRIMARIES_UNSPECIFIED: return "STD_VIDEO_AV1_COLOR_PRIMARIES_UNSPECIFIED";
        case STD_VIDEO_AV1_COLOR_PRIMARIES_BT_470_M: return "STD_VIDEO_AV1_COLOR_PRIMARIES_BT_470_M";
        case STD_VIDEO_AV1_COLOR_PRIMARIES_BT_470_B_G: return "STD_VIDEO_AV1_COLOR_PRIMARIES_BT_470_B_G";
        case STD_VIDEO_AV1_COLOR_PRIMARIES_BT_601: return "STD_VIDEO_AV1_COLOR_PRIMARIES_BT_601";
        case STD_VIDEO_AV1_COLOR_PRIMARIES_SMPTE_240: return "STD_VIDEO_AV1_COLOR_PRIMARIES_SMPTE_240";
        case STD_VIDEO_AV1_COLOR_PRIMARIES_GENERIC_FILM: return "STD_VIDEO_AV1_COLOR_PRIMARIES_GENERIC_FILM";
        case STD_VIDEO_AV1_COLOR_PRIMARIES_BT_2020: return "STD_VIDEO_AV1_COLOR_PRIMARIES_BT_2020";
        case STD_VIDEO_AV1_COLOR_PRIMARIES_XYZ: return "STD_VIDEO_AV1_COLOR_PRIMARIES_XYZ";
        case STD_VIDEO_AV1_COLOR_PRIMARIES_SMPTE_431: return "STD_VIDEO_AV1_COLOR_PRIMARIES_SMPTE_431";
        case STD_VIDEO_AV1_COLOR_PRIMARIES_SMPTE_432: return "STD_VIDEO_AV1_COLOR_PRIMARIES_SMPTE_432";
        case STD_VIDEO_AV1_COLOR_PRIMARIES_EBU_3213: return "STD_VIDEO_AV1_COLOR_PRIMARIES_EBU_3213";
        case STD_VIDEO_AV1_COLOR_PRIMARIES_INVALID: return "STD_VIDEO_AV1_COLOR_PRIMARIES_INVALID";
        default: return std::string("UNKNOWN_StdVideoAV1ColorPrimaries_value") + std::to_string(value);
    }
}
void DumpStdVideoAV1ColorPrimaries(Printer &p, std::string name, StdVideoAV1ColorPrimaries value) {
    p.PrintKeyString(name, StdVideoAV1ColorPrimariesString(value));
}
std::string StdVideoAV1TransferCharacteristicsString(StdVideoAV1TransferCharacteristics value) {
    switch (value) {
        case STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_RESERVED_0: return "STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_RESERVED_0";
        case STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_BT_709: return "STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_BT_709";
        case STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_UNSPECIFIED: return "STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_UNSPECIFIED";
        case STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_RESERVED_3: return "STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_RESERVED_3";
        case STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_BT_470_M: return "STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_BT_470_M";
        case STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_BT_470_B_G: return "STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_BT_470_B_G";
        case STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_BT_601: return "STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_BT_601";
        case STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_SMPTE_240: return "STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_SMPTE_240";
        case STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_LINEAR: return "STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_LINEAR";
        case STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_LOG_100: return "STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_LOG_100";
        case STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_LOG_100_SQRT10: return "STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_LOG_100_SQRT10";
        case STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_IEC_61966: return "STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_IEC_61966";
        case STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_BT_1361: return "STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_BT_1361";
        case STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_SRGB: return "STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_SRGB";
        case STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_BT_2020_10_BIT: return "STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_BT_2020_10_BIT";
        case STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_BT_2020_12_BIT: return "STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_BT_2020_12_BIT";
        case STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_SMPTE_2084: return "STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_SMPTE_2084";
        case STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_SMPTE_428: return "STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_SMPTE_428";
        case STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_HLG: return "STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_HLG";
        case STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_INVALID: return "STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_INVALID";
        default: return std::string("UNKNOWN_StdVideoAV1TransferCharacteristics_value") + std::to_string(value);
    }
}
void DumpStdVideoAV1TransferCharacteristics(Printer &p, std::string name, StdVideoAV1TransferCharacteristics value) {
    p.PrintKeyString(name, StdVideoAV1TransferCharacteristicsString(value));
}
std::string StdVideoAV1MatrixCoefficientsString(StdVideoAV1MatrixCoefficients value) {
    switch (value) {
        case STD_VIDEO_AV1_MATRIX_COEFFICIENTS_IDENTITY: return "STD_VIDEO_AV1_MATRIX_COEFFICIENTS_IDENTITY";
        case STD_VIDEO_AV1_MATRIX_COEFFICIENTS_BT_709: return "STD_VIDEO_AV1_MATRIX_COEFFICIENTS_BT_709";
        case STD_VIDEO_AV1_MATRIX_COEFFICIENTS_UNSPECIFIED: return "STD_VIDEO_AV1_MATRIX_COEFFICIENTS_UNSPECIFIED";
        case STD_VIDEO_AV1_MATRIX_COEFFICIENTS_RESERVED_3: return "STD_VIDEO_AV1_MATRIX_COEFFICIENTS_RESERVED_3";
        case STD_VIDEO_AV1_MATRIX_COEFFICIENTS_FCC: return "STD_VIDEO_AV1_MATRIX_COEFFICIENTS_FCC";
        case STD_VIDEO_AV1_MATRIX_COEFFICIENTS_BT_470_B_G: return "STD_VIDEO_AV1_MATRIX_COEFFICIENTS_BT_470_B_G";
        case STD_VIDEO_AV1_MATRIX_COEFFICIENTS_BT_601: return "STD_VIDEO_AV1_MATRIX_COEFFICIENTS_BT_601";
        case STD_VIDEO_AV1_MATRIX_COEFFICIENTS_SMPTE_240: return "STD_VIDEO_AV1_MATRIX_COEFFICIENTS_SMPTE_240";
        case STD_VIDEO_AV1_MATRIX_COEFFICIENTS_SMPTE_YCGCO: return "STD_VIDEO_AV1_MATRIX_COEFFICIENTS_SMPTE_YCGCO";
        case STD_VIDEO_AV1_MATRIX_COEFFICIENTS_BT_2020_NCL: return "STD_VIDEO_AV1_MATRIX_COEFFICIENTS_BT_2020_NCL";
        case STD_VIDEO_AV1_MATRIX_COEFFICIENTS_BT_2020_CL: return "STD_VIDEO_AV1_MATRIX_COEFFICIENTS_BT_2020_CL";
        case STD_VIDEO_AV1_MATRIX_COEFFICIENTS_SMPTE_2085: return "STD_VIDEO_AV1_MATRIX_COEFFICIENTS_SMPTE_2085";
        case STD_VIDEO_AV1_MATRIX_COEFFICIENTS_CHROMAT_NCL: return "STD_VIDEO_AV1_MATRIX_COEFFICIENTS_CHROMAT_NCL";
        case STD_VIDEO_AV1_MATRIX_COEFFICIENTS_CHROMAT_CL: return "STD_VIDEO_AV1_MATRIX_COEFFICIENTS_CHROMAT_CL";
        case STD_VIDEO_AV1_MATRIX_COEFFICIENTS_ICTCP: return "STD_VIDEO_AV1_MATRIX_COEFFICIENTS_ICTCP";
        case STD_VIDEO_AV1_MATRIX_COEFFICIENTS_INVALID: return "STD_VIDEO_AV1_MATRIX_COEFFICIENTS_INVALID";
        default: return std::string("UNKNOWN_StdVideoAV1MatrixCoefficients_value") + std::to_string(value);
    }
}
void DumpStdVideoAV1MatrixCoefficients(Printer &p, std::string name, StdVideoAV1MatrixCoefficients value) {
    p.PrintKeyString(name, StdVideoAV1MatrixCoefficientsString(value));
}
std::string StdVideoAV1ChromaSamplePositionString(StdVideoAV1ChromaSamplePosition value) {
    switch (value) {
        case STD_VIDEO_AV1_CHROMA_SAMPLE_POSITION_UNKNOWN: return "STD_VIDEO_AV1_CHROMA_SAMPLE_POSITION_UNKNOWN";
        case STD_VIDEO_AV1_CHROMA_SAMPLE_POSITION_VERTICAL: return "STD_VIDEO_AV1_CHROMA_SAMPLE_POSITION_VERTICAL";
        case STD_VIDEO_AV1_CHROMA_SAMPLE_POSITION_COLOCATED: return "STD_VIDEO_AV1_CHROMA_SAMPLE_POSITION_COLOCATED";
        case STD_VIDEO_AV1_CHROMA_SAMPLE_POSITION_RESERVED: return "STD_VIDEO_AV1_CHROMA_SAMPLE_POSITION_RESERVED";
        case STD_VIDEO_AV1_CHROMA_SAMPLE_POSITION_INVALID: return "STD_VIDEO_AV1_CHROMA_SAMPLE_POSITION_INVALID";
        default: return std::string("UNKNOWN_StdVideoAV1ChromaSamplePosition_value") + std::to_string(value);
    }
}
void DumpStdVideoAV1ChromaSamplePosition(Printer &p, std::string name, StdVideoAV1ChromaSamplePosition value) {
    p.PrintKeyString(name, StdVideoAV1ChromaSamplePositionString(value));
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
        case (VK_DRIVER_ID_MESA_HONEYKRISP): return "DRIVER_ID_MESA_HONEYKRISP";
        case (VK_DRIVER_ID_VULKAN_SC_EMULATION_ON_VULKAN): return "DRIVER_ID_VULKAN_SC_EMULATION_ON_VULKAN";
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
        case (VK_FORMAT_A1B5G5R5_UNORM_PACK16): return "FORMAT_A1B5G5R5_UNORM_PACK16";
        case (VK_FORMAT_A8_UNORM): return "FORMAT_A8_UNORM";
        case (VK_FORMAT_PVRTC1_2BPP_UNORM_BLOCK_IMG): return "FORMAT_PVRTC1_2BPP_UNORM_BLOCK_IMG";
        case (VK_FORMAT_PVRTC1_4BPP_UNORM_BLOCK_IMG): return "FORMAT_PVRTC1_4BPP_UNORM_BLOCK_IMG";
        case (VK_FORMAT_PVRTC2_2BPP_UNORM_BLOCK_IMG): return "FORMAT_PVRTC2_2BPP_UNORM_BLOCK_IMG";
        case (VK_FORMAT_PVRTC2_4BPP_UNORM_BLOCK_IMG): return "FORMAT_PVRTC2_4BPP_UNORM_BLOCK_IMG";
        case (VK_FORMAT_PVRTC1_2BPP_SRGB_BLOCK_IMG): return "FORMAT_PVRTC1_2BPP_SRGB_BLOCK_IMG";
        case (VK_FORMAT_PVRTC1_4BPP_SRGB_BLOCK_IMG): return "FORMAT_PVRTC1_4BPP_SRGB_BLOCK_IMG";
        case (VK_FORMAT_PVRTC2_2BPP_SRGB_BLOCK_IMG): return "FORMAT_PVRTC2_2BPP_SRGB_BLOCK_IMG";
        case (VK_FORMAT_PVRTC2_4BPP_SRGB_BLOCK_IMG): return "FORMAT_PVRTC2_4BPP_SRGB_BLOCK_IMG";
        case (VK_FORMAT_R8_BOOL_ARM): return "FORMAT_R8_BOOL_ARM";
        case (VK_FORMAT_R16G16_SFIXED5_NV): return "FORMAT_R16G16_SFIXED5_NV";
        case (VK_FORMAT_R10X6_UINT_PACK16_ARM): return "FORMAT_R10X6_UINT_PACK16_ARM";
        case (VK_FORMAT_R10X6G10X6_UINT_2PACK16_ARM): return "FORMAT_R10X6G10X6_UINT_2PACK16_ARM";
        case (VK_FORMAT_R10X6G10X6B10X6A10X6_UINT_4PACK16_ARM): return "FORMAT_R10X6G10X6B10X6A10X6_UINT_4PACK16_ARM";
        case (VK_FORMAT_R12X4_UINT_PACK16_ARM): return "FORMAT_R12X4_UINT_PACK16_ARM";
        case (VK_FORMAT_R12X4G12X4_UINT_2PACK16_ARM): return "FORMAT_R12X4G12X4_UINT_2PACK16_ARM";
        case (VK_FORMAT_R12X4G12X4B12X4A12X4_UINT_4PACK16_ARM): return "FORMAT_R12X4G12X4B12X4A12X4_UINT_4PACK16_ARM";
        case (VK_FORMAT_R14X2_UINT_PACK16_ARM): return "FORMAT_R14X2_UINT_PACK16_ARM";
        case (VK_FORMAT_R14X2G14X2_UINT_2PACK16_ARM): return "FORMAT_R14X2G14X2_UINT_2PACK16_ARM";
        case (VK_FORMAT_R14X2G14X2B14X2A14X2_UINT_4PACK16_ARM): return "FORMAT_R14X2G14X2B14X2A14X2_UINT_4PACK16_ARM";
        case (VK_FORMAT_R14X2_UNORM_PACK16_ARM): return "FORMAT_R14X2_UNORM_PACK16_ARM";
        case (VK_FORMAT_R14X2G14X2_UNORM_2PACK16_ARM): return "FORMAT_R14X2G14X2_UNORM_2PACK16_ARM";
        case (VK_FORMAT_R14X2G14X2B14X2A14X2_UNORM_4PACK16_ARM): return "FORMAT_R14X2G14X2B14X2A14X2_UNORM_4PACK16_ARM";
        case (VK_FORMAT_G14X2_B14X2R14X2_2PLANE_420_UNORM_3PACK16_ARM): return "FORMAT_G14X2_B14X2R14X2_2PLANE_420_UNORM_3PACK16_ARM";
        case (VK_FORMAT_G14X2_B14X2R14X2_2PLANE_422_UNORM_3PACK16_ARM): return "FORMAT_G14X2_B14X2R14X2_2PLANE_422_UNORM_3PACK16_ARM";
        default: return std::string("UNKNOWN_VkFormat_value") + std::to_string(value);
    }
}
void DumpVkFormat(Printer &p, std::string name, VkFormat value) {
    if (p.Type() == OutputType::json)
        p.PrintKeyString(name, std::string("VK_") + VkFormatString(value));
    else
        p.PrintKeyString(name, VkFormatString(value));
}
std::string VkImageLayoutString(VkImageLayout value) {
    switch (value) {
        case (VK_IMAGE_LAYOUT_UNDEFINED): return "IMAGE_LAYOUT_UNDEFINED";
        case (VK_IMAGE_LAYOUT_GENERAL): return "IMAGE_LAYOUT_GENERAL";
        case (VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL): return "IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL";
        case (VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL): return "IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL";
        case (VK_IMAGE_LAYOUT_DEPTH_STENCIL_READ_ONLY_OPTIMAL): return "IMAGE_LAYOUT_DEPTH_STENCIL_READ_ONLY_OPTIMAL";
        case (VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL): return "IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL";
        case (VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL): return "IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL";
        case (VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL): return "IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL";
        case (VK_IMAGE_LAYOUT_PREINITIALIZED): return "IMAGE_LAYOUT_PREINITIALIZED";
        case (VK_IMAGE_LAYOUT_DEPTH_READ_ONLY_STENCIL_ATTACHMENT_OPTIMAL): return "IMAGE_LAYOUT_DEPTH_READ_ONLY_STENCIL_ATTACHMENT_OPTIMAL";
        case (VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_STENCIL_READ_ONLY_OPTIMAL): return "IMAGE_LAYOUT_DEPTH_ATTACHMENT_STENCIL_READ_ONLY_OPTIMAL";
        case (VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_OPTIMAL): return "IMAGE_LAYOUT_DEPTH_ATTACHMENT_OPTIMAL";
        case (VK_IMAGE_LAYOUT_DEPTH_READ_ONLY_OPTIMAL): return "IMAGE_LAYOUT_DEPTH_READ_ONLY_OPTIMAL";
        case (VK_IMAGE_LAYOUT_STENCIL_ATTACHMENT_OPTIMAL): return "IMAGE_LAYOUT_STENCIL_ATTACHMENT_OPTIMAL";
        case (VK_IMAGE_LAYOUT_STENCIL_READ_ONLY_OPTIMAL): return "IMAGE_LAYOUT_STENCIL_READ_ONLY_OPTIMAL";
        case (VK_IMAGE_LAYOUT_READ_ONLY_OPTIMAL): return "IMAGE_LAYOUT_READ_ONLY_OPTIMAL";
        case (VK_IMAGE_LAYOUT_ATTACHMENT_OPTIMAL): return "IMAGE_LAYOUT_ATTACHMENT_OPTIMAL";
        case (VK_IMAGE_LAYOUT_RENDERING_LOCAL_READ): return "IMAGE_LAYOUT_RENDERING_LOCAL_READ";
        case (VK_IMAGE_LAYOUT_PRESENT_SRC_KHR): return "IMAGE_LAYOUT_PRESENT_SRC_KHR";
        case (VK_IMAGE_LAYOUT_VIDEO_DECODE_DST_KHR): return "IMAGE_LAYOUT_VIDEO_DECODE_DST_KHR";
        case (VK_IMAGE_LAYOUT_VIDEO_DECODE_SRC_KHR): return "IMAGE_LAYOUT_VIDEO_DECODE_SRC_KHR";
        case (VK_IMAGE_LAYOUT_VIDEO_DECODE_DPB_KHR): return "IMAGE_LAYOUT_VIDEO_DECODE_DPB_KHR";
        case (VK_IMAGE_LAYOUT_SHARED_PRESENT_KHR): return "IMAGE_LAYOUT_SHARED_PRESENT_KHR";
        case (VK_IMAGE_LAYOUT_FRAGMENT_DENSITY_MAP_OPTIMAL_EXT): return "IMAGE_LAYOUT_FRAGMENT_DENSITY_MAP_OPTIMAL_EXT";
        case (VK_IMAGE_LAYOUT_FRAGMENT_SHADING_RATE_ATTACHMENT_OPTIMAL_KHR): return "IMAGE_LAYOUT_FRAGMENT_SHADING_RATE_ATTACHMENT_OPTIMAL_KHR";
        case (VK_IMAGE_LAYOUT_VIDEO_ENCODE_DST_KHR): return "IMAGE_LAYOUT_VIDEO_ENCODE_DST_KHR";
        case (VK_IMAGE_LAYOUT_VIDEO_ENCODE_SRC_KHR): return "IMAGE_LAYOUT_VIDEO_ENCODE_SRC_KHR";
        case (VK_IMAGE_LAYOUT_VIDEO_ENCODE_DPB_KHR): return "IMAGE_LAYOUT_VIDEO_ENCODE_DPB_KHR";
        case (VK_IMAGE_LAYOUT_ATTACHMENT_FEEDBACK_LOOP_OPTIMAL_EXT): return "IMAGE_LAYOUT_ATTACHMENT_FEEDBACK_LOOP_OPTIMAL_EXT";
        case (VK_IMAGE_LAYOUT_TENSOR_ALIASING_ARM): return "IMAGE_LAYOUT_TENSOR_ALIASING_ARM";
        case (VK_IMAGE_LAYOUT_VIDEO_ENCODE_QUANTIZATION_MAP_KHR): return "IMAGE_LAYOUT_VIDEO_ENCODE_QUANTIZATION_MAP_KHR";
        case (VK_IMAGE_LAYOUT_ZERO_INITIALIZED_EXT): return "IMAGE_LAYOUT_ZERO_INITIALIZED_EXT";
        default: return std::string("UNKNOWN_VkImageLayout_value") + std::to_string(value);
    }
}
void DumpVkImageLayout(Printer &p, std::string name, VkImageLayout value) {
    if (p.Type() == OutputType::json)
        p.PrintKeyString(name, std::string("VK_") + VkImageLayoutString(value));
    else
        p.PrintKeyString(name, VkImageLayoutString(value));
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
std::string VkPipelineRobustnessBufferBehaviorString(VkPipelineRobustnessBufferBehavior value) {
    switch (value) {
        case (VK_PIPELINE_ROBUSTNESS_BUFFER_BEHAVIOR_DEVICE_DEFAULT): return "PIPELINE_ROBUSTNESS_BUFFER_BEHAVIOR_DEVICE_DEFAULT";
        case (VK_PIPELINE_ROBUSTNESS_BUFFER_BEHAVIOR_DISABLED): return "PIPELINE_ROBUSTNESS_BUFFER_BEHAVIOR_DISABLED";
        case (VK_PIPELINE_ROBUSTNESS_BUFFER_BEHAVIOR_ROBUST_BUFFER_ACCESS): return "PIPELINE_ROBUSTNESS_BUFFER_BEHAVIOR_ROBUST_BUFFER_ACCESS";
        case (VK_PIPELINE_ROBUSTNESS_BUFFER_BEHAVIOR_ROBUST_BUFFER_ACCESS_2): return "PIPELINE_ROBUSTNESS_BUFFER_BEHAVIOR_ROBUST_BUFFER_ACCESS_2";
        default: return std::string("UNKNOWN_VkPipelineRobustnessBufferBehavior_value") + std::to_string(value);
    }
}
void DumpVkPipelineRobustnessBufferBehavior(Printer &p, std::string name, VkPipelineRobustnessBufferBehavior value) {
    if (p.Type() == OutputType::json)
        p.PrintKeyString(name, std::string("VK_") + VkPipelineRobustnessBufferBehaviorString(value));
    else
        p.PrintKeyString(name, VkPipelineRobustnessBufferBehaviorString(value));
}
std::string VkPipelineRobustnessImageBehaviorString(VkPipelineRobustnessImageBehavior value) {
    switch (value) {
        case (VK_PIPELINE_ROBUSTNESS_IMAGE_BEHAVIOR_DEVICE_DEFAULT): return "PIPELINE_ROBUSTNESS_IMAGE_BEHAVIOR_DEVICE_DEFAULT";
        case (VK_PIPELINE_ROBUSTNESS_IMAGE_BEHAVIOR_DISABLED): return "PIPELINE_ROBUSTNESS_IMAGE_BEHAVIOR_DISABLED";
        case (VK_PIPELINE_ROBUSTNESS_IMAGE_BEHAVIOR_ROBUST_IMAGE_ACCESS): return "PIPELINE_ROBUSTNESS_IMAGE_BEHAVIOR_ROBUST_IMAGE_ACCESS";
        case (VK_PIPELINE_ROBUSTNESS_IMAGE_BEHAVIOR_ROBUST_IMAGE_ACCESS_2): return "PIPELINE_ROBUSTNESS_IMAGE_BEHAVIOR_ROBUST_IMAGE_ACCESS_2";
        default: return std::string("UNKNOWN_VkPipelineRobustnessImageBehavior_value") + std::to_string(value);
    }
}
void DumpVkPipelineRobustnessImageBehavior(Printer &p, std::string name, VkPipelineRobustnessImageBehavior value) {
    if (p.Type() == OutputType::json)
        p.PrintKeyString(name, std::string("VK_") + VkPipelineRobustnessImageBehaviorString(value));
    else
        p.PrintKeyString(name, VkPipelineRobustnessImageBehaviorString(value));
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
        case (VK_PRESENT_MODE_FIFO_LATEST_READY_EXT): return "PRESENT_MODE_FIFO_LATEST_READY_EXT";
        default: return std::string("UNKNOWN_VkPresentModeKHR_value") + std::to_string(value);
    }
}
void DumpVkPresentModeKHR(Printer &p, std::string name, VkPresentModeKHR value) {
    if (p.Type() == OutputType::json)
        p.PrintKeyString(name, std::string("VK_") + VkPresentModeKHRString(value));
    else
        p.PrintKeyString(name, VkPresentModeKHRString(value));
}
std::string VkQueueGlobalPriorityString(VkQueueGlobalPriority value) {
    switch (value) {
        case (VK_QUEUE_GLOBAL_PRIORITY_LOW): return "QUEUE_GLOBAL_PRIORITY_LOW";
        case (VK_QUEUE_GLOBAL_PRIORITY_MEDIUM): return "QUEUE_GLOBAL_PRIORITY_MEDIUM";
        case (VK_QUEUE_GLOBAL_PRIORITY_HIGH): return "QUEUE_GLOBAL_PRIORITY_HIGH";
        case (VK_QUEUE_GLOBAL_PRIORITY_REALTIME): return "QUEUE_GLOBAL_PRIORITY_REALTIME";
        default: return std::string("UNKNOWN_VkQueueGlobalPriority_value") + std::to_string(value);
    }
}
void DumpVkQueueGlobalPriority(Printer &p, std::string name, VkQueueGlobalPriority value) {
    if (p.Type() == OutputType::json)
        p.PrintKeyString(name, std::string("VK_") + VkQueueGlobalPriorityString(value));
    else
        p.PrintKeyString(name, VkQueueGlobalPriorityString(value));
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
        case (VK_ERROR_NOT_PERMITTED): return "ERROR_NOT_PERMITTED";
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
        case (VK_ERROR_FULL_SCREEN_EXCLUSIVE_MODE_LOST_EXT): return "ERROR_FULL_SCREEN_EXCLUSIVE_MODE_LOST_EXT";
        case (VK_THREAD_IDLE_KHR): return "THREAD_IDLE_KHR";
        case (VK_THREAD_DONE_KHR): return "THREAD_DONE_KHR";
        case (VK_OPERATION_DEFERRED_KHR): return "OPERATION_DEFERRED_KHR";
        case (VK_OPERATION_NOT_DEFERRED_KHR): return "OPERATION_NOT_DEFERRED_KHR";
        case (VK_ERROR_INVALID_VIDEO_STD_PARAMETERS_KHR): return "ERROR_INVALID_VIDEO_STD_PARAMETERS_KHR";
        case (VK_ERROR_COMPRESSION_EXHAUSTED_EXT): return "ERROR_COMPRESSION_EXHAUSTED_EXT";
        case (VK_INCOMPATIBLE_SHADER_BINARY_EXT): return "INCOMPATIBLE_SHADER_BINARY_EXT";
        case (VK_PIPELINE_BINARY_MISSING_KHR): return "PIPELINE_BINARY_MISSING_KHR";
        case (VK_ERROR_NOT_ENOUGH_SPACE_KHR): return "ERROR_NOT_ENOUGH_SPACE_KHR";
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
    if (VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_CUBIC_BIT & value) strings.push_back("FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_CUBIC_BIT");
    if (VK_FORMAT_FEATURE_2_HOST_IMAGE_TRANSFER_BIT & value) strings.push_back("FORMAT_FEATURE_2_HOST_IMAGE_TRANSFER_BIT");
    if (VK_FORMAT_FEATURE_2_VIDEO_DECODE_OUTPUT_BIT_KHR & value) strings.push_back("FORMAT_FEATURE_2_VIDEO_DECODE_OUTPUT_BIT_KHR");
    if (VK_FORMAT_FEATURE_2_VIDEO_DECODE_DPB_BIT_KHR & value) strings.push_back("FORMAT_FEATURE_2_VIDEO_DECODE_DPB_BIT_KHR");
    if (VK_FORMAT_FEATURE_2_ACCELERATION_STRUCTURE_VERTEX_BUFFER_BIT_KHR & value) strings.push_back("FORMAT_FEATURE_2_ACCELERATION_STRUCTURE_VERTEX_BUFFER_BIT_KHR");
    if (VK_FORMAT_FEATURE_2_FRAGMENT_DENSITY_MAP_BIT_EXT & value) strings.push_back("FORMAT_FEATURE_2_FRAGMENT_DENSITY_MAP_BIT_EXT");
    if (VK_FORMAT_FEATURE_2_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR & value) strings.push_back("FORMAT_FEATURE_2_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR");
    if (VK_FORMAT_FEATURE_2_VIDEO_ENCODE_INPUT_BIT_KHR & value) strings.push_back("FORMAT_FEATURE_2_VIDEO_ENCODE_INPUT_BIT_KHR");
    if (VK_FORMAT_FEATURE_2_VIDEO_ENCODE_DPB_BIT_KHR & value) strings.push_back("FORMAT_FEATURE_2_VIDEO_ENCODE_DPB_BIT_KHR");
    if (VK_FORMAT_FEATURE_2_ACCELERATION_STRUCTURE_RADIUS_BUFFER_BIT_NV & value) strings.push_back("FORMAT_FEATURE_2_ACCELERATION_STRUCTURE_RADIUS_BUFFER_BIT_NV");
    if (VK_FORMAT_FEATURE_2_LINEAR_COLOR_ATTACHMENT_BIT_NV & value) strings.push_back("FORMAT_FEATURE_2_LINEAR_COLOR_ATTACHMENT_BIT_NV");
    if (VK_FORMAT_FEATURE_2_WEIGHT_IMAGE_BIT_QCOM & value) strings.push_back("FORMAT_FEATURE_2_WEIGHT_IMAGE_BIT_QCOM");
    if (VK_FORMAT_FEATURE_2_WEIGHT_SAMPLED_IMAGE_BIT_QCOM & value) strings.push_back("FORMAT_FEATURE_2_WEIGHT_SAMPLED_IMAGE_BIT_QCOM");
    if (VK_FORMAT_FEATURE_2_BLOCK_MATCHING_BIT_QCOM & value) strings.push_back("FORMAT_FEATURE_2_BLOCK_MATCHING_BIT_QCOM");
    if (VK_FORMAT_FEATURE_2_BOX_FILTER_SAMPLED_BIT_QCOM & value) strings.push_back("FORMAT_FEATURE_2_BOX_FILTER_SAMPLED_BIT_QCOM");
    if (VK_FORMAT_FEATURE_2_TENSOR_SHADER_BIT_ARM & value) strings.push_back("FORMAT_FEATURE_2_TENSOR_SHADER_BIT_ARM");
    if (VK_FORMAT_FEATURE_2_TENSOR_IMAGE_ALIASING_BIT_ARM & value) strings.push_back("FORMAT_FEATURE_2_TENSOR_IMAGE_ALIASING_BIT_ARM");
    if (VK_FORMAT_FEATURE_2_OPTICAL_FLOW_IMAGE_BIT_NV & value) strings.push_back("FORMAT_FEATURE_2_OPTICAL_FLOW_IMAGE_BIT_NV");
    if (VK_FORMAT_FEATURE_2_OPTICAL_FLOW_VECTOR_BIT_NV & value) strings.push_back("FORMAT_FEATURE_2_OPTICAL_FLOW_VECTOR_BIT_NV");
    if (VK_FORMAT_FEATURE_2_OPTICAL_FLOW_COST_BIT_NV & value) strings.push_back("FORMAT_FEATURE_2_OPTICAL_FLOW_COST_BIT_NV");
    if (VK_FORMAT_FEATURE_2_TENSOR_DATA_GRAPH_BIT_ARM & value) strings.push_back("FORMAT_FEATURE_2_TENSOR_DATA_GRAPH_BIT_ARM");
    if (VK_FORMAT_FEATURE_2_VIDEO_ENCODE_QUANTIZATION_DELTA_MAP_BIT_KHR & value) strings.push_back("FORMAT_FEATURE_2_VIDEO_ENCODE_QUANTIZATION_DELTA_MAP_BIT_KHR");
    if (VK_FORMAT_FEATURE_2_VIDEO_ENCODE_EMPHASIS_MAP_BIT_KHR & value) strings.push_back("FORMAT_FEATURE_2_VIDEO_ENCODE_EMPHASIS_MAP_BIT_KHR");
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
    if (VK_IMAGE_USAGE_HOST_TRANSFER_BIT & value) strings.push_back("IMAGE_USAGE_HOST_TRANSFER_BIT");
    if (VK_IMAGE_USAGE_VIDEO_DECODE_DST_BIT_KHR & value) strings.push_back("IMAGE_USAGE_VIDEO_DECODE_DST_BIT_KHR");
    if (VK_IMAGE_USAGE_VIDEO_DECODE_SRC_BIT_KHR & value) strings.push_back("IMAGE_USAGE_VIDEO_DECODE_SRC_BIT_KHR");
    if (VK_IMAGE_USAGE_VIDEO_DECODE_DPB_BIT_KHR & value) strings.push_back("IMAGE_USAGE_VIDEO_DECODE_DPB_BIT_KHR");
    if (VK_IMAGE_USAGE_FRAGMENT_DENSITY_MAP_BIT_EXT & value) strings.push_back("IMAGE_USAGE_FRAGMENT_DENSITY_MAP_BIT_EXT");
    if (VK_IMAGE_USAGE_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR & value) strings.push_back("IMAGE_USAGE_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR");
    if (VK_IMAGE_USAGE_VIDEO_ENCODE_DST_BIT_KHR & value) strings.push_back("IMAGE_USAGE_VIDEO_ENCODE_DST_BIT_KHR");
    if (VK_IMAGE_USAGE_VIDEO_ENCODE_SRC_BIT_KHR & value) strings.push_back("IMAGE_USAGE_VIDEO_ENCODE_SRC_BIT_KHR");
    if (VK_IMAGE_USAGE_VIDEO_ENCODE_DPB_BIT_KHR & value) strings.push_back("IMAGE_USAGE_VIDEO_ENCODE_DPB_BIT_KHR");
    if (VK_IMAGE_USAGE_ATTACHMENT_FEEDBACK_LOOP_BIT_EXT & value) strings.push_back("IMAGE_USAGE_ATTACHMENT_FEEDBACK_LOOP_BIT_EXT");
    if (VK_IMAGE_USAGE_INVOCATION_MASK_BIT_HUAWEI & value) strings.push_back("IMAGE_USAGE_INVOCATION_MASK_BIT_HUAWEI");
    if (VK_IMAGE_USAGE_SAMPLE_WEIGHT_BIT_QCOM & value) strings.push_back("IMAGE_USAGE_SAMPLE_WEIGHT_BIT_QCOM");
    if (VK_IMAGE_USAGE_SAMPLE_BLOCK_MATCH_BIT_QCOM & value) strings.push_back("IMAGE_USAGE_SAMPLE_BLOCK_MATCH_BIT_QCOM");
    if (VK_IMAGE_USAGE_TENSOR_ALIASING_BIT_ARM & value) strings.push_back("IMAGE_USAGE_TENSOR_ALIASING_BIT_ARM");
    if (VK_IMAGE_USAGE_TILE_MEMORY_BIT_QCOM & value) strings.push_back("IMAGE_USAGE_TILE_MEMORY_BIT_QCOM");
    if (VK_IMAGE_USAGE_VIDEO_ENCODE_QUANTIZATION_DELTA_MAP_BIT_KHR & value) strings.push_back("IMAGE_USAGE_VIDEO_ENCODE_QUANTIZATION_DELTA_MAP_BIT_KHR");
    if (VK_IMAGE_USAGE_VIDEO_ENCODE_EMPHASIS_MAP_BIT_KHR & value) strings.push_back("IMAGE_USAGE_VIDEO_ENCODE_EMPHASIS_MAP_BIT_KHR");
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
    if (VK_MEMORY_HEAP_TILE_MEMORY_BIT_QCOM & value) strings.push_back("MEMORY_HEAP_TILE_MEMORY_BIT_QCOM");
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
    if (VK_QUEUE_DATA_GRAPH_BIT_ARM & value) strings.push_back("QUEUE_DATA_GRAPH_BIT_ARM");
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
    if (VK_QUEUE_DATA_GRAPH_BIT_ARM & value) {
        if (is_first) { is_first = false; } else { out += " | "; }
        out += "QUEUE_DATA_GRAPH_BIT_ARM";
    }
    return out;
}
std::vector<const char *> VkResolveModeFlagBitsGetStrings(VkResolveModeFlagBits value) {
    std::vector<const char *> strings;
    if (value == 0) { strings.push_back("RESOLVE_MODE_NONE"); return strings; }
    if (VK_RESOLVE_MODE_SAMPLE_ZERO_BIT & value) strings.push_back("RESOLVE_MODE_SAMPLE_ZERO_BIT");
    if (VK_RESOLVE_MODE_AVERAGE_BIT & value) strings.push_back("RESOLVE_MODE_AVERAGE_BIT");
    if (VK_RESOLVE_MODE_MIN_BIT & value) strings.push_back("RESOLVE_MODE_MIN_BIT");
    if (VK_RESOLVE_MODE_MAX_BIT & value) strings.push_back("RESOLVE_MODE_MAX_BIT");
    if (VK_RESOLVE_MODE_EXTERNAL_FORMAT_DOWNSAMPLE_BIT_ANDROID & value) strings.push_back("RESOLVE_MODE_EXTERNAL_FORMAT_DOWNSAMPLE_BIT_ANDROID");
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
    if (VK_SUBGROUP_FEATURE_ROTATE_BIT & value) strings.push_back("SUBGROUP_FEATURE_ROTATE_BIT");
    if (VK_SUBGROUP_FEATURE_ROTATE_CLUSTERED_BIT & value) strings.push_back("SUBGROUP_FEATURE_ROTATE_CLUSTERED_BIT");
    if (VK_SUBGROUP_FEATURE_PARTITIONED_BIT_NV & value) strings.push_back("SUBGROUP_FEATURE_PARTITIONED_BIT_NV");
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
void DumpVkPhysicalDeviceDynamicRenderingLocalReadFeatures(Printer &p, std::string name, const VkPhysicalDeviceDynamicRenderingLocalReadFeatures &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(25);
    p.PrintKeyBool("dynamicRenderingLocalRead", static_cast<bool>(obj.dynamicRenderingLocalRead));
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
void DumpVkPhysicalDeviceGlobalPriorityQueryFeatures(Printer &p, std::string name, const VkPhysicalDeviceGlobalPriorityQueryFeatures &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(19);
    p.PrintKeyBool("globalPriorityQuery", static_cast<bool>(obj.globalPriorityQuery));
}
void DumpVkPhysicalDeviceHostImageCopyFeatures(Printer &p, std::string name, const VkPhysicalDeviceHostImageCopyFeatures &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(13);
    p.PrintKeyBool("hostImageCopy", static_cast<bool>(obj.hostImageCopy));
}
void DumpVkPhysicalDeviceHostImageCopyProperties(Printer &p, std::string name, const VkPhysicalDeviceHostImageCopyProperties &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(35);
    p.PrintKeyValue("copySrcLayoutCount", obj.copySrcLayoutCount);
    if (obj.copySrcLayoutCount == 0 || obj.pCopySrcLayouts == nullptr) {
        p.PrintKeyString("pCopySrcLayouts", "NULL");
    } else {
        ArrayWrapper arr(p,"pCopySrcLayouts", obj.copySrcLayoutCount);
        for (uint32_t i = 0; i < obj.copySrcLayoutCount; i++) {
            DumpVkImageLayout(p, std::to_string(i), obj.pCopySrcLayouts[i]);
        }
    }
    p.PrintKeyValue("copyDstLayoutCount", obj.copyDstLayoutCount);
    if (obj.copyDstLayoutCount == 0 || obj.pCopyDstLayouts == nullptr) {
        p.PrintKeyString("pCopyDstLayouts", "NULL");
    } else {
        ArrayWrapper arr(p,"pCopyDstLayouts", obj.copyDstLayoutCount);
        for (uint32_t i = 0; i < obj.copyDstLayoutCount; i++) {
            DumpVkImageLayout(p, std::to_string(i), obj.pCopyDstLayouts[i]);
        }
    }
    p.PrintKeyValue("optimalTilingLayoutUUID", obj.optimalTilingLayoutUUID);
    p.PrintKeyBool("identicalMemoryTypeRequirements", static_cast<bool>(obj.identicalMemoryTypeRequirements));
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
void DumpVkPhysicalDeviceIndexTypeUint8Features(Printer &p, std::string name, const VkPhysicalDeviceIndexTypeUint8Features &obj) {
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
void DumpVkPhysicalDeviceLineRasterizationFeatures(Printer &p, std::string name, const VkPhysicalDeviceLineRasterizationFeatures &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(24);
    p.PrintKeyBool("rectangularLines", static_cast<bool>(obj.rectangularLines));
    p.PrintKeyBool("bresenhamLines", static_cast<bool>(obj.bresenhamLines));
    p.PrintKeyBool("smoothLines", static_cast<bool>(obj.smoothLines));
    p.PrintKeyBool("stippledRectangularLines", static_cast<bool>(obj.stippledRectangularLines));
    p.PrintKeyBool("stippledBresenhamLines", static_cast<bool>(obj.stippledBresenhamLines));
    p.PrintKeyBool("stippledSmoothLines", static_cast<bool>(obj.stippledSmoothLines));
}
void DumpVkPhysicalDeviceLineRasterizationProperties(Printer &p, std::string name, const VkPhysicalDeviceLineRasterizationProperties &obj) {
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
void DumpVkPhysicalDeviceMaintenance5Features(Printer &p, std::string name, const VkPhysicalDeviceMaintenance5Features &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(12);
    p.PrintKeyBool("maintenance5", static_cast<bool>(obj.maintenance5));
}
void DumpVkPhysicalDeviceMaintenance5Properties(Printer &p, std::string name, const VkPhysicalDeviceMaintenance5Properties &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(51);
    p.PrintKeyBool("earlyFragmentMultisampleCoverageAfterSampleCounting", static_cast<bool>(obj.earlyFragmentMultisampleCoverageAfterSampleCounting));
    p.PrintKeyBool("earlyFragmentSampleMaskTestBeforeSampleCounting", static_cast<bool>(obj.earlyFragmentSampleMaskTestBeforeSampleCounting));
    p.PrintKeyBool("depthStencilSwizzleOneSupport", static_cast<bool>(obj.depthStencilSwizzleOneSupport));
    p.PrintKeyBool("polygonModePointSize", static_cast<bool>(obj.polygonModePointSize));
    p.PrintKeyBool("nonStrictSinglePixelWideLinesUseParallelogram", static_cast<bool>(obj.nonStrictSinglePixelWideLinesUseParallelogram));
    p.PrintKeyBool("nonStrictWideLinesUseParallelogram", static_cast<bool>(obj.nonStrictWideLinesUseParallelogram));
}
void DumpVkPhysicalDeviceMaintenance6Features(Printer &p, std::string name, const VkPhysicalDeviceMaintenance6Features &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(12);
    p.PrintKeyBool("maintenance6", static_cast<bool>(obj.maintenance6));
}
void DumpVkPhysicalDeviceMaintenance6Properties(Printer &p, std::string name, const VkPhysicalDeviceMaintenance6Properties &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(38);
    p.PrintKeyBool("blockTexelViewCompatibleMultipleLayers", static_cast<bool>(obj.blockTexelViewCompatibleMultipleLayers));
    p.PrintKeyValue("maxCombinedImageSamplerDescriptorCount", obj.maxCombinedImageSamplerDescriptorCount);
    p.PrintKeyBool("fragmentShadingRateClampCombinerInputs", static_cast<bool>(obj.fragmentShadingRateClampCombinerInputs));
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
void DumpVkPhysicalDevicePipelineProtectedAccessFeatures(Printer &p, std::string name, const VkPhysicalDevicePipelineProtectedAccessFeatures &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(23);
    p.PrintKeyBool("pipelineProtectedAccess", static_cast<bool>(obj.pipelineProtectedAccess));
}
void DumpVkPhysicalDevicePipelineRobustnessFeatures(Printer &p, std::string name, const VkPhysicalDevicePipelineRobustnessFeatures &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(18);
    p.PrintKeyBool("pipelineRobustness", static_cast<bool>(obj.pipelineRobustness));
}
void DumpVkPhysicalDevicePipelineRobustnessProperties(Printer &p, std::string name, const VkPhysicalDevicePipelineRobustnessProperties &obj) {
    ObjectWrapper object{p, name};
    DumpVkPipelineRobustnessBufferBehavior(p, "defaultRobustnessStorageBuffers", obj.defaultRobustnessStorageBuffers);
    DumpVkPipelineRobustnessBufferBehavior(p, "defaultRobustnessUniformBuffers", obj.defaultRobustnessUniformBuffers);
    DumpVkPipelineRobustnessBufferBehavior(p, "defaultRobustnessVertexInputs", obj.defaultRobustnessVertexInputs);
    DumpVkPipelineRobustnessImageBehavior(p, "defaultRobustnessImages", obj.defaultRobustnessImages);
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
void DumpVkPhysicalDevicePushDescriptorProperties(Printer &p, std::string name, const VkPhysicalDevicePushDescriptorProperties &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(18);
    p.PrintKeyValue("maxPushDescriptors", obj.maxPushDescriptors);
}
void DumpVkPhysicalDeviceRobustness2FeaturesKHR(Printer &p, std::string name, const VkPhysicalDeviceRobustness2FeaturesKHR &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(19);
    p.PrintKeyBool("robustBufferAccess2", static_cast<bool>(obj.robustBufferAccess2));
    p.PrintKeyBool("robustImageAccess2", static_cast<bool>(obj.robustImageAccess2));
    p.PrintKeyBool("nullDescriptor", static_cast<bool>(obj.nullDescriptor));
}
void DumpVkPhysicalDeviceRobustness2PropertiesKHR(Printer &p, std::string name, const VkPhysicalDeviceRobustness2PropertiesKHR &obj) {
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
void DumpVkPhysicalDeviceShaderExpectAssumeFeatures(Printer &p, std::string name, const VkPhysicalDeviceShaderExpectAssumeFeatures &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(18);
    p.PrintKeyBool("shaderExpectAssume", static_cast<bool>(obj.shaderExpectAssume));
}
void DumpVkPhysicalDeviceShaderFloat16Int8Features(Printer &p, std::string name, const VkPhysicalDeviceShaderFloat16Int8Features &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(13);
    p.PrintKeyBool("shaderFloat16", static_cast<bool>(obj.shaderFloat16));
    p.PrintKeyBool("shaderInt8", static_cast<bool>(obj.shaderInt8));
}
void DumpVkPhysicalDeviceShaderFloatControls2Features(Printer &p, std::string name, const VkPhysicalDeviceShaderFloatControls2Features &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(20);
    p.PrintKeyBool("shaderFloatControls2", static_cast<bool>(obj.shaderFloatControls2));
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
void DumpVkPhysicalDeviceShaderSubgroupRotateFeatures(Printer &p, std::string name, const VkPhysicalDeviceShaderSubgroupRotateFeatures &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(29);
    p.PrintKeyBool("shaderSubgroupRotate", static_cast<bool>(obj.shaderSubgroupRotate));
    p.PrintKeyBool("shaderSubgroupRotateClustered", static_cast<bool>(obj.shaderSubgroupRotateClustered));
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
void DumpVkPhysicalDeviceVertexAttributeDivisorFeatures(Printer &p, std::string name, const VkPhysicalDeviceVertexAttributeDivisorFeatures &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(38);
    p.PrintKeyBool("vertexAttributeInstanceRateDivisor", static_cast<bool>(obj.vertexAttributeInstanceRateDivisor));
    p.PrintKeyBool("vertexAttributeInstanceRateZeroDivisor", static_cast<bool>(obj.vertexAttributeInstanceRateZeroDivisor));
}
void DumpVkPhysicalDeviceVertexAttributeDivisorProperties(Printer &p, std::string name, const VkPhysicalDeviceVertexAttributeDivisorProperties &obj) {
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
void DumpVkPhysicalDeviceVulkan14Features(Printer &p, std::string name, const VkPhysicalDeviceVulkan14Features &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(38);
    p.PrintKeyBool("globalPriorityQuery", static_cast<bool>(obj.globalPriorityQuery));
    p.PrintKeyBool("shaderSubgroupRotate", static_cast<bool>(obj.shaderSubgroupRotate));
    p.PrintKeyBool("shaderSubgroupRotateClustered", static_cast<bool>(obj.shaderSubgroupRotateClustered));
    p.PrintKeyBool("shaderFloatControls2", static_cast<bool>(obj.shaderFloatControls2));
    p.PrintKeyBool("shaderExpectAssume", static_cast<bool>(obj.shaderExpectAssume));
    p.PrintKeyBool("rectangularLines", static_cast<bool>(obj.rectangularLines));
    p.PrintKeyBool("bresenhamLines", static_cast<bool>(obj.bresenhamLines));
    p.PrintKeyBool("smoothLines", static_cast<bool>(obj.smoothLines));
    p.PrintKeyBool("stippledRectangularLines", static_cast<bool>(obj.stippledRectangularLines));
    p.PrintKeyBool("stippledBresenhamLines", static_cast<bool>(obj.stippledBresenhamLines));
    p.PrintKeyBool("stippledSmoothLines", static_cast<bool>(obj.stippledSmoothLines));
    p.PrintKeyBool("vertexAttributeInstanceRateDivisor", static_cast<bool>(obj.vertexAttributeInstanceRateDivisor));
    p.PrintKeyBool("vertexAttributeInstanceRateZeroDivisor", static_cast<bool>(obj.vertexAttributeInstanceRateZeroDivisor));
    p.PrintKeyBool("indexTypeUint8", static_cast<bool>(obj.indexTypeUint8));
    p.PrintKeyBool("dynamicRenderingLocalRead", static_cast<bool>(obj.dynamicRenderingLocalRead));
    p.PrintKeyBool("maintenance5", static_cast<bool>(obj.maintenance5));
    p.PrintKeyBool("maintenance6", static_cast<bool>(obj.maintenance6));
    p.PrintKeyBool("pipelineProtectedAccess", static_cast<bool>(obj.pipelineProtectedAccess));
    p.PrintKeyBool("pipelineRobustness", static_cast<bool>(obj.pipelineRobustness));
    p.PrintKeyBool("hostImageCopy", static_cast<bool>(obj.hostImageCopy));
    p.PrintKeyBool("pushDescriptor", static_cast<bool>(obj.pushDescriptor));
}
void DumpVkPhysicalDeviceVulkan14Properties(Printer &p, std::string name, const VkPhysicalDeviceVulkan14Properties &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(51);
    p.PrintKeyValue("lineSubPixelPrecisionBits", obj.lineSubPixelPrecisionBits);
    p.PrintKeyValue("maxVertexAttribDivisor", obj.maxVertexAttribDivisor);
    p.PrintKeyBool("supportsNonZeroFirstInstance", static_cast<bool>(obj.supportsNonZeroFirstInstance));
    p.PrintKeyValue("maxPushDescriptors", obj.maxPushDescriptors);
    p.PrintKeyBool("dynamicRenderingLocalReadDepthStencilAttachments", static_cast<bool>(obj.dynamicRenderingLocalReadDepthStencilAttachments));
    p.PrintKeyBool("dynamicRenderingLocalReadMultisampledAttachments", static_cast<bool>(obj.dynamicRenderingLocalReadMultisampledAttachments));
    p.PrintKeyBool("earlyFragmentMultisampleCoverageAfterSampleCounting", static_cast<bool>(obj.earlyFragmentMultisampleCoverageAfterSampleCounting));
    p.PrintKeyBool("earlyFragmentSampleMaskTestBeforeSampleCounting", static_cast<bool>(obj.earlyFragmentSampleMaskTestBeforeSampleCounting));
    p.PrintKeyBool("depthStencilSwizzleOneSupport", static_cast<bool>(obj.depthStencilSwizzleOneSupport));
    p.PrintKeyBool("polygonModePointSize", static_cast<bool>(obj.polygonModePointSize));
    p.PrintKeyBool("nonStrictSinglePixelWideLinesUseParallelogram", static_cast<bool>(obj.nonStrictSinglePixelWideLinesUseParallelogram));
    p.PrintKeyBool("nonStrictWideLinesUseParallelogram", static_cast<bool>(obj.nonStrictWideLinesUseParallelogram));
    p.PrintKeyBool("blockTexelViewCompatibleMultipleLayers", static_cast<bool>(obj.blockTexelViewCompatibleMultipleLayers));
    p.PrintKeyValue("maxCombinedImageSamplerDescriptorCount", obj.maxCombinedImageSamplerDescriptorCount);
    p.PrintKeyBool("fragmentShadingRateClampCombinerInputs", static_cast<bool>(obj.fragmentShadingRateClampCombinerInputs));
    DumpVkPipelineRobustnessBufferBehavior(p, "defaultRobustnessStorageBuffers", obj.defaultRobustnessStorageBuffers);
    DumpVkPipelineRobustnessBufferBehavior(p, "defaultRobustnessUniformBuffers", obj.defaultRobustnessUniformBuffers);
    DumpVkPipelineRobustnessBufferBehavior(p, "defaultRobustnessVertexInputs", obj.defaultRobustnessVertexInputs);
    DumpVkPipelineRobustnessImageBehavior(p, "defaultRobustnessImages", obj.defaultRobustnessImages);
    p.PrintKeyValue("copySrcLayoutCount", obj.copySrcLayoutCount);
    if (obj.copySrcLayoutCount == 0 || obj.pCopySrcLayouts == nullptr) {
        p.PrintKeyString("pCopySrcLayouts", "NULL");
    } else {
        ArrayWrapper arr(p,"pCopySrcLayouts", obj.copySrcLayoutCount);
        for (uint32_t i = 0; i < obj.copySrcLayoutCount; i++) {
            DumpVkImageLayout(p, std::to_string(i), obj.pCopySrcLayouts[i]);
        }
    }
    p.PrintKeyValue("copyDstLayoutCount", obj.copyDstLayoutCount);
    if (obj.copyDstLayoutCount == 0 || obj.pCopyDstLayouts == nullptr) {
        p.PrintKeyString("pCopyDstLayouts", "NULL");
    } else {
        ArrayWrapper arr(p,"pCopyDstLayouts", obj.copyDstLayoutCount);
        for (uint32_t i = 0; i < obj.copyDstLayoutCount; i++) {
            DumpVkImageLayout(p, std::to_string(i), obj.pCopyDstLayouts[i]);
        }
    }
    p.PrintKeyValue("optimalTilingLayoutUUID", obj.optimalTilingLayoutUUID);
    p.PrintKeyBool("identicalMemoryTypeRequirements", static_cast<bool>(obj.identicalMemoryTypeRequirements));
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
void DumpVkQueueFamilyGlobalPriorityProperties(Printer &p, std::string name, const VkQueueFamilyGlobalPriorityProperties &obj) {
    ObjectWrapper object{p, name};
    p.SetMinKeyWidth(14);
    p.PrintKeyValue("priorityCount", obj.priorityCount);
    ArrayWrapper arr(p,"priorities", obj.priorityCount);
    for (uint32_t i = 0; i < obj.priorityCount; i++) {
       if (p.Type() == OutputType::json)
           p.PrintString(std::string("VK_") + VkQueueGlobalPriorityString(obj.priorities[i]));
       else
           p.PrintString(VkQueueGlobalPriorityString(obj.priorities[i]));
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
    VkPhysicalDeviceHostImageCopyProperties PhysicalDeviceHostImageCopyProperties{};
    std::vector<VkImageLayout> VkPhysicalDeviceHostImageCopyProperties_pCopySrcLayouts;
    std::vector<VkImageLayout> VkPhysicalDeviceHostImageCopyProperties_pCopyDstLayouts;
    VkPhysicalDeviceIDProperties PhysicalDeviceIDProperties{};
    VkPhysicalDeviceInlineUniformBlockProperties PhysicalDeviceInlineUniformBlockProperties{};
    VkPhysicalDeviceLineRasterizationProperties PhysicalDeviceLineRasterizationProperties{};
    VkPhysicalDeviceMaintenance3Properties PhysicalDeviceMaintenance3Properties{};
    VkPhysicalDeviceMaintenance4Properties PhysicalDeviceMaintenance4Properties{};
    VkPhysicalDeviceMaintenance5Properties PhysicalDeviceMaintenance5Properties{};
    VkPhysicalDeviceMaintenance6Properties PhysicalDeviceMaintenance6Properties{};
    VkPhysicalDeviceMultiviewProperties PhysicalDeviceMultiviewProperties{};
    VkPhysicalDevicePCIBusInfoPropertiesEXT PhysicalDevicePCIBusInfoPropertiesEXT{};
    VkPhysicalDevicePerformanceQueryPropertiesKHR PhysicalDevicePerformanceQueryPropertiesKHR{};
    VkPhysicalDevicePipelineRobustnessProperties PhysicalDevicePipelineRobustnessProperties{};
    VkPhysicalDevicePointClippingProperties PhysicalDevicePointClippingProperties{};
    VkPhysicalDeviceProtectedMemoryProperties PhysicalDeviceProtectedMemoryProperties{};
    VkPhysicalDevicePushDescriptorProperties PhysicalDevicePushDescriptorProperties{};
    VkPhysicalDeviceRobustness2PropertiesKHR PhysicalDeviceRobustness2PropertiesKHR{};
    VkPhysicalDeviceSampleLocationsPropertiesEXT PhysicalDeviceSampleLocationsPropertiesEXT{};
    VkPhysicalDeviceSamplerFilterMinmaxProperties PhysicalDeviceSamplerFilterMinmaxProperties{};
    VkPhysicalDeviceShaderIntegerDotProductProperties PhysicalDeviceShaderIntegerDotProductProperties{};
    VkPhysicalDeviceSubgroupProperties PhysicalDeviceSubgroupProperties{};
    VkPhysicalDeviceSubgroupSizeControlProperties PhysicalDeviceSubgroupSizeControlProperties{};
    VkPhysicalDeviceTexelBufferAlignmentProperties PhysicalDeviceTexelBufferAlignmentProperties{};
    VkPhysicalDeviceTimelineSemaphoreProperties PhysicalDeviceTimelineSemaphoreProperties{};
    VkPhysicalDeviceVertexAttributeDivisorProperties PhysicalDeviceVertexAttributeDivisorProperties{};
    VkPhysicalDeviceVulkan11Properties PhysicalDeviceVulkan11Properties{};
    VkPhysicalDeviceVulkan12Properties PhysicalDeviceVulkan12Properties{};
    VkPhysicalDeviceVulkan13Properties PhysicalDeviceVulkan13Properties{};
    VkPhysicalDeviceVulkan14Properties PhysicalDeviceVulkan14Properties{};
    std::vector<VkImageLayout> VkPhysicalDeviceVulkan14Properties_pCopySrcLayouts;
    std::vector<VkImageLayout> VkPhysicalDeviceVulkan14Properties_pCopyDstLayouts;
    VkPhysicalDeviceVulkanSC10Properties PhysicalDeviceVulkanSC10Properties{};
    void initialize_chain(AppInstance &inst, AppGpu &gpu , bool show_promoted_structs) noexcept {
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
        PhysicalDeviceHostImageCopyProperties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_IMAGE_COPY_PROPERTIES;
        PhysicalDeviceIDProperties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES;
        PhysicalDeviceInlineUniformBlockProperties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES;
        PhysicalDeviceLineRasterizationProperties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_PROPERTIES;
        PhysicalDeviceMaintenance3Properties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES;
        PhysicalDeviceMaintenance4Properties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_PROPERTIES;
        PhysicalDeviceMaintenance5Properties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_PROPERTIES;
        PhysicalDeviceMaintenance6Properties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_6_PROPERTIES;
        PhysicalDeviceMultiviewProperties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES;
        PhysicalDevicePCIBusInfoPropertiesEXT.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT;
        PhysicalDevicePerformanceQueryPropertiesKHR.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_PROPERTIES_KHR;
        PhysicalDevicePipelineRobustnessProperties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_PROPERTIES;
        PhysicalDevicePointClippingProperties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES;
        PhysicalDeviceProtectedMemoryProperties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES;
        PhysicalDevicePushDescriptorProperties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES;
        PhysicalDeviceRobustness2PropertiesKHR.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_PROPERTIES_KHR;
        PhysicalDeviceSampleLocationsPropertiesEXT.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT;
        PhysicalDeviceSamplerFilterMinmaxProperties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES;
        PhysicalDeviceShaderIntegerDotProductProperties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_PROPERTIES;
        PhysicalDeviceSubgroupProperties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES;
        PhysicalDeviceSubgroupSizeControlProperties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_PROPERTIES;
        PhysicalDeviceTexelBufferAlignmentProperties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES;
        PhysicalDeviceTimelineSemaphoreProperties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES;
        PhysicalDeviceVertexAttributeDivisorProperties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES;
        PhysicalDeviceVulkan11Properties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES;
        PhysicalDeviceVulkan12Properties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES;
        PhysicalDeviceVulkan13Properties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES;
        PhysicalDeviceVulkan14Properties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_4_PROPERTIES;
        PhysicalDeviceVulkanSC10Properties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_SC_1_0_PROPERTIES;
        std::vector<VkBaseOutStructure*> chain_members{};
        if (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_BLEND_OPERATION_ADVANCED_EXTENSION_NAME))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceBlendOperationAdvancedPropertiesEXT));
        if (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_CONSERVATIVE_RASTERIZATION_EXTENSION_NAME))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceConservativeRasterizationPropertiesEXT));
        if (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_CUSTOM_BORDER_COLOR_EXTENSION_NAME))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceCustomBorderColorPropertiesEXT));
        if ((gpu.api_version >= VK_API_VERSION_1_2))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceDepthStencilResolveProperties));
        if ((gpu.api_version >= VK_API_VERSION_1_2))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceDescriptorIndexingProperties));
        if (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_DISCARD_RECTANGLES_EXTENSION_NAME))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceDiscardRectanglePropertiesEXT));
        if ((gpu.api_version >= VK_API_VERSION_1_2))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceDriverProperties));
        if (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_EXTERNAL_MEMORY_HOST_EXTENSION_NAME))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceExternalMemoryHostPropertiesEXT));
        if ((gpu.api_version >= VK_API_VERSION_1_2))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceFloatControlsProperties));
        if (gpu.CheckPhysicalDeviceExtensionIncluded(VK_KHR_FRAGMENT_SHADING_RATE_EXTENSION_NAME))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceFragmentShadingRatePropertiesKHR));
        if ((gpu.api_version >= VK_API_VERSION_1_4))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceHostImageCopyProperties));
        if ((gpu.api_version >= VK_API_VERSION_1_1))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceIDProperties));
        if ((gpu.api_version >= VK_API_VERSION_1_3))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceInlineUniformBlockProperties));
        if ((gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_LINE_RASTERIZATION_EXTENSION_NAME)
         || gpu.CheckPhysicalDeviceExtensionIncluded(VK_KHR_LINE_RASTERIZATION_EXTENSION_NAME))
            && (gpu.api_version < VK_API_VERSION_1_4 || show_promoted_structs))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceLineRasterizationProperties));
        if ((gpu.api_version >= VK_API_VERSION_1_1))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceMaintenance3Properties));
        if ((gpu.api_version >= VK_API_VERSION_1_3))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceMaintenance4Properties));
        if ((gpu.api_version >= VK_API_VERSION_1_4))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceMaintenance5Properties));
        if ((gpu.api_version >= VK_API_VERSION_1_4))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceMaintenance6Properties));
        if ((gpu.api_version >= VK_API_VERSION_1_1))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceMultiviewProperties));
        if (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_PCI_BUS_INFO_EXTENSION_NAME))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDevicePCIBusInfoPropertiesEXT));
        if (gpu.CheckPhysicalDeviceExtensionIncluded(VK_KHR_PERFORMANCE_QUERY_EXTENSION_NAME))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDevicePerformanceQueryPropertiesKHR));
        if ((gpu.api_version >= VK_API_VERSION_1_4))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDevicePipelineRobustnessProperties));
        if ((gpu.api_version >= VK_API_VERSION_1_1))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDevicePointClippingProperties));
        if (gpu.api_version == VK_API_VERSION_1_1 || show_promoted_structs)
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceProtectedMemoryProperties));
        if ((gpu.api_version >= VK_API_VERSION_1_4))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDevicePushDescriptorProperties));
        if (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_ROBUSTNESS_2_EXTENSION_NAME)
         || gpu.CheckPhysicalDeviceExtensionIncluded(VK_KHR_ROBUSTNESS_2_EXTENSION_NAME))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceRobustness2PropertiesKHR));
        if (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_SAMPLE_LOCATIONS_EXTENSION_NAME))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceSampleLocationsPropertiesEXT));
        if ((gpu.api_version >= VK_API_VERSION_1_2))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceSamplerFilterMinmaxProperties));
        if ((gpu.api_version >= VK_API_VERSION_1_3))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceShaderIntegerDotProductProperties));
        if (gpu.api_version == VK_API_VERSION_1_1 || show_promoted_structs)
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceSubgroupProperties));
        if ((gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_SUBGROUP_SIZE_CONTROL_EXTENSION_NAME))
            && (gpu.api_version < VK_API_VERSION_1_3 || show_promoted_structs))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceSubgroupSizeControlProperties));
        if ((gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_TEXEL_BUFFER_ALIGNMENT_EXTENSION_NAME))
            && (gpu.api_version < VK_API_VERSION_1_3 || show_promoted_structs))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceTexelBufferAlignmentProperties));
        if ((gpu.api_version >= VK_API_VERSION_1_2))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceTimelineSemaphoreProperties));
        if ((gpu.CheckPhysicalDeviceExtensionIncluded(VK_KHR_VERTEX_ATTRIBUTE_DIVISOR_EXTENSION_NAME))
            && (gpu.api_version < VK_API_VERSION_1_4 || show_promoted_structs))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceVertexAttributeDivisorProperties));
        if ((gpu.api_version >= VK_API_VERSION_1_2))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceVulkan11Properties));
        if ((gpu.api_version >= VK_API_VERSION_1_2))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceVulkan12Properties));
        if ((gpu.api_version >= VK_API_VERSION_1_3))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceVulkan13Properties));
        if ((gpu.api_version >= VK_API_VERSION_1_4))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceVulkan14Properties));
        if ((gpu.api_version >= VKSC_API_VERSION_1_0))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceVulkanSC10Properties));

        if (!chain_members.empty()) {
            for(size_t i = 0; i < chain_members.size() - 1; i++){
                chain_members[i]->pNext = chain_members[i + 1];
            }
            start_of_chain = chain_members[0];
        }
    }
};
void setup_phys_device_props2_chain(VkPhysicalDeviceProperties2& start, std::unique_ptr<phys_device_props2_chain>& chain, AppInstance &inst,AppGpu &gpu,bool show_promoted_structs){
    chain = std::unique_ptr<phys_device_props2_chain>(new phys_device_props2_chain());
    chain->initialize_chain(inst,gpu,show_promoted_structs);
    start.pNext = chain->start_of_chain;
};

void chain_iterator_phys_device_props2(Printer &p, AppInstance &inst, AppGpu &gpu, bool show_promoted_structs, const void * place) {
    while (place) {
        const VkBaseOutStructure *structure = (const VkBaseOutStructure *)place;
        p.SetSubHeader();
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT) {
            const VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT* props = (const VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT*)structure;
            DumpVkPhysicalDeviceBlendOperationAdvancedPropertiesEXT(p, "VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT) {
            const VkPhysicalDeviceConservativeRasterizationPropertiesEXT* props = (const VkPhysicalDeviceConservativeRasterizationPropertiesEXT*)structure;
            DumpVkPhysicalDeviceConservativeRasterizationPropertiesEXT(p, "VkPhysicalDeviceConservativeRasterizationPropertiesEXT", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_PROPERTIES_EXT) {
            const VkPhysicalDeviceCustomBorderColorPropertiesEXT* props = (const VkPhysicalDeviceCustomBorderColorPropertiesEXT*)structure;
            DumpVkPhysicalDeviceCustomBorderColorPropertiesEXT(p, "VkPhysicalDeviceCustomBorderColorPropertiesEXT", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES) {
            const VkPhysicalDeviceDepthStencilResolveProperties* props = (const VkPhysicalDeviceDepthStencilResolveProperties*)structure;
            DumpVkPhysicalDeviceDepthStencilResolveProperties(p, "VkPhysicalDeviceDepthStencilResolveProperties", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES) {
            const VkPhysicalDeviceDescriptorIndexingProperties* props = (const VkPhysicalDeviceDescriptorIndexingProperties*)structure;
            DumpVkPhysicalDeviceDescriptorIndexingProperties(p, "VkPhysicalDeviceDescriptorIndexingProperties", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT) {
            const VkPhysicalDeviceDiscardRectanglePropertiesEXT* props = (const VkPhysicalDeviceDiscardRectanglePropertiesEXT*)structure;
            DumpVkPhysicalDeviceDiscardRectanglePropertiesEXT(p, "VkPhysicalDeviceDiscardRectanglePropertiesEXT", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES) {
            const VkPhysicalDeviceDriverProperties* props = (const VkPhysicalDeviceDriverProperties*)structure;
            DumpVkPhysicalDeviceDriverProperties(p, "VkPhysicalDeviceDriverProperties", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT) {
            const VkPhysicalDeviceExternalMemoryHostPropertiesEXT* props = (const VkPhysicalDeviceExternalMemoryHostPropertiesEXT*)structure;
            DumpVkPhysicalDeviceExternalMemoryHostPropertiesEXT(p, "VkPhysicalDeviceExternalMemoryHostPropertiesEXT", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES) {
            const VkPhysicalDeviceFloatControlsProperties* props = (const VkPhysicalDeviceFloatControlsProperties*)structure;
            DumpVkPhysicalDeviceFloatControlsProperties(p, "VkPhysicalDeviceFloatControlsProperties", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_PROPERTIES_KHR) {
            const VkPhysicalDeviceFragmentShadingRatePropertiesKHR* props = (const VkPhysicalDeviceFragmentShadingRatePropertiesKHR*)structure;
            DumpVkPhysicalDeviceFragmentShadingRatePropertiesKHR(p, "VkPhysicalDeviceFragmentShadingRatePropertiesKHR", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_IMAGE_COPY_PROPERTIES) {
            const VkPhysicalDeviceHostImageCopyProperties* props = (const VkPhysicalDeviceHostImageCopyProperties*)structure;
            DumpVkPhysicalDeviceHostImageCopyProperties(p, "VkPhysicalDeviceHostImageCopyProperties", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES) {
            const VkPhysicalDeviceIDProperties* props = (const VkPhysicalDeviceIDProperties*)structure;
            DumpVkPhysicalDeviceIDProperties(p, "VkPhysicalDeviceIDProperties", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES) {
            const VkPhysicalDeviceInlineUniformBlockProperties* props = (const VkPhysicalDeviceInlineUniformBlockProperties*)structure;
            DumpVkPhysicalDeviceInlineUniformBlockProperties(p, "VkPhysicalDeviceInlineUniformBlockProperties", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_PROPERTIES) {
            const VkPhysicalDeviceLineRasterizationProperties* props = (const VkPhysicalDeviceLineRasterizationProperties*)structure;
            DumpVkPhysicalDeviceLineRasterizationProperties(p, gpu.api_version >= VK_API_VERSION_1_4 ?"VkPhysicalDeviceLineRasterizationProperties":"VkPhysicalDeviceLineRasterizationPropertiesKHR", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES) {
            const VkPhysicalDeviceMaintenance3Properties* props = (const VkPhysicalDeviceMaintenance3Properties*)structure;
            DumpVkPhysicalDeviceMaintenance3Properties(p, "VkPhysicalDeviceMaintenance3Properties", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_PROPERTIES) {
            const VkPhysicalDeviceMaintenance4Properties* props = (const VkPhysicalDeviceMaintenance4Properties*)structure;
            DumpVkPhysicalDeviceMaintenance4Properties(p, "VkPhysicalDeviceMaintenance4Properties", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_PROPERTIES) {
            const VkPhysicalDeviceMaintenance5Properties* props = (const VkPhysicalDeviceMaintenance5Properties*)structure;
            DumpVkPhysicalDeviceMaintenance5Properties(p, "VkPhysicalDeviceMaintenance5Properties", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_6_PROPERTIES) {
            const VkPhysicalDeviceMaintenance6Properties* props = (const VkPhysicalDeviceMaintenance6Properties*)structure;
            DumpVkPhysicalDeviceMaintenance6Properties(p, "VkPhysicalDeviceMaintenance6Properties", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES) {
            const VkPhysicalDeviceMultiviewProperties* props = (const VkPhysicalDeviceMultiviewProperties*)structure;
            DumpVkPhysicalDeviceMultiviewProperties(p, "VkPhysicalDeviceMultiviewProperties", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT) {
            const VkPhysicalDevicePCIBusInfoPropertiesEXT* props = (const VkPhysicalDevicePCIBusInfoPropertiesEXT*)structure;
            DumpVkPhysicalDevicePCIBusInfoPropertiesEXT(p, "VkPhysicalDevicePCIBusInfoPropertiesEXT", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_PROPERTIES_KHR) {
            const VkPhysicalDevicePerformanceQueryPropertiesKHR* props = (const VkPhysicalDevicePerformanceQueryPropertiesKHR*)structure;
            DumpVkPhysicalDevicePerformanceQueryPropertiesKHR(p, "VkPhysicalDevicePerformanceQueryPropertiesKHR", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_PROPERTIES) {
            const VkPhysicalDevicePipelineRobustnessProperties* props = (const VkPhysicalDevicePipelineRobustnessProperties*)structure;
            DumpVkPhysicalDevicePipelineRobustnessProperties(p, "VkPhysicalDevicePipelineRobustnessProperties", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES) {
            const VkPhysicalDevicePointClippingProperties* props = (const VkPhysicalDevicePointClippingProperties*)structure;
            DumpVkPhysicalDevicePointClippingProperties(p, "VkPhysicalDevicePointClippingProperties", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES) {
            const VkPhysicalDeviceProtectedMemoryProperties* props = (const VkPhysicalDeviceProtectedMemoryProperties*)structure;
            DumpVkPhysicalDeviceProtectedMemoryProperties(p, "VkPhysicalDeviceProtectedMemoryProperties", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES) {
            const VkPhysicalDevicePushDescriptorProperties* props = (const VkPhysicalDevicePushDescriptorProperties*)structure;
            DumpVkPhysicalDevicePushDescriptorProperties(p, "VkPhysicalDevicePushDescriptorProperties", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_PROPERTIES_KHR) {
            const VkPhysicalDeviceRobustness2PropertiesKHR* props = (const VkPhysicalDeviceRobustness2PropertiesKHR*)structure;
            DumpVkPhysicalDeviceRobustness2PropertiesKHR(p, "VkPhysicalDeviceRobustness2PropertiesKHR", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT) {
            const VkPhysicalDeviceSampleLocationsPropertiesEXT* props = (const VkPhysicalDeviceSampleLocationsPropertiesEXT*)structure;
            DumpVkPhysicalDeviceSampleLocationsPropertiesEXT(p, "VkPhysicalDeviceSampleLocationsPropertiesEXT", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES) {
            const VkPhysicalDeviceSamplerFilterMinmaxProperties* props = (const VkPhysicalDeviceSamplerFilterMinmaxProperties*)structure;
            DumpVkPhysicalDeviceSamplerFilterMinmaxProperties(p, "VkPhysicalDeviceSamplerFilterMinmaxProperties", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_PROPERTIES) {
            const VkPhysicalDeviceShaderIntegerDotProductProperties* props = (const VkPhysicalDeviceShaderIntegerDotProductProperties*)structure;
            DumpVkPhysicalDeviceShaderIntegerDotProductProperties(p, "VkPhysicalDeviceShaderIntegerDotProductProperties", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES) {
            const VkPhysicalDeviceSubgroupProperties* props = (const VkPhysicalDeviceSubgroupProperties*)structure;
            DumpVkPhysicalDeviceSubgroupProperties(p, "VkPhysicalDeviceSubgroupProperties", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_PROPERTIES) {
            const VkPhysicalDeviceSubgroupSizeControlProperties* props = (const VkPhysicalDeviceSubgroupSizeControlProperties*)structure;
            DumpVkPhysicalDeviceSubgroupSizeControlProperties(p, gpu.api_version >= VK_API_VERSION_1_3 ?"VkPhysicalDeviceSubgroupSizeControlProperties":"VkPhysicalDeviceSubgroupSizeControlPropertiesEXT", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES) {
            const VkPhysicalDeviceTexelBufferAlignmentProperties* props = (const VkPhysicalDeviceTexelBufferAlignmentProperties*)structure;
            DumpVkPhysicalDeviceTexelBufferAlignmentProperties(p, gpu.api_version >= VK_API_VERSION_1_3 ?"VkPhysicalDeviceTexelBufferAlignmentProperties":"VkPhysicalDeviceTexelBufferAlignmentPropertiesEXT", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES) {
            const VkPhysicalDeviceTimelineSemaphoreProperties* props = (const VkPhysicalDeviceTimelineSemaphoreProperties*)structure;
            DumpVkPhysicalDeviceTimelineSemaphoreProperties(p, "VkPhysicalDeviceTimelineSemaphoreProperties", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES) {
            const VkPhysicalDeviceVertexAttributeDivisorProperties* props = (const VkPhysicalDeviceVertexAttributeDivisorProperties*)structure;
            DumpVkPhysicalDeviceVertexAttributeDivisorProperties(p, gpu.api_version >= VK_API_VERSION_1_4 ?"VkPhysicalDeviceVertexAttributeDivisorProperties":"VkPhysicalDeviceVertexAttributeDivisorPropertiesKHR", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES) {
            const VkPhysicalDeviceVulkan11Properties* props = (const VkPhysicalDeviceVulkan11Properties*)structure;
            DumpVkPhysicalDeviceVulkan11Properties(p, "VkPhysicalDeviceVulkan11Properties", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES) {
            const VkPhysicalDeviceVulkan12Properties* props = (const VkPhysicalDeviceVulkan12Properties*)structure;
            DumpVkPhysicalDeviceVulkan12Properties(p, "VkPhysicalDeviceVulkan12Properties", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES) {
            const VkPhysicalDeviceVulkan13Properties* props = (const VkPhysicalDeviceVulkan13Properties*)structure;
            DumpVkPhysicalDeviceVulkan13Properties(p, "VkPhysicalDeviceVulkan13Properties", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_4_PROPERTIES) {
            const VkPhysicalDeviceVulkan14Properties* props = (const VkPhysicalDeviceVulkan14Properties*)structure;
            DumpVkPhysicalDeviceVulkan14Properties(p, "VkPhysicalDeviceVulkan14Properties", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_SC_1_0_PROPERTIES) {
            const VkPhysicalDeviceVulkanSC10Properties* props = (const VkPhysicalDeviceVulkanSC10Properties*)structure;
            DumpVkPhysicalDeviceVulkanSC10Properties(p, "VkPhysicalDeviceVulkanSC10Properties", *props);
            p.AddNewline();
        }
        place = structure->pNext;
    }
}

bool prepare_phys_device_props2_twocall_chain_vectors(std::unique_ptr<phys_device_props2_chain>& chain) {
    (void)chain;
    chain->VkPhysicalDeviceHostImageCopyProperties_pCopySrcLayouts.resize(chain->PhysicalDeviceHostImageCopyProperties.copySrcLayoutCount);
    chain->PhysicalDeviceHostImageCopyProperties.pCopySrcLayouts = chain->VkPhysicalDeviceHostImageCopyProperties_pCopySrcLayouts.data();
    chain->VkPhysicalDeviceHostImageCopyProperties_pCopyDstLayouts.resize(chain->PhysicalDeviceHostImageCopyProperties.copyDstLayoutCount);
    chain->PhysicalDeviceHostImageCopyProperties.pCopyDstLayouts = chain->VkPhysicalDeviceHostImageCopyProperties_pCopyDstLayouts.data();
    chain->VkPhysicalDeviceVulkan14Properties_pCopySrcLayouts.resize(chain->PhysicalDeviceVulkan14Properties.copySrcLayoutCount);
    chain->PhysicalDeviceVulkan14Properties.pCopySrcLayouts = chain->VkPhysicalDeviceVulkan14Properties_pCopySrcLayouts.data();
    chain->VkPhysicalDeviceVulkan14Properties_pCopyDstLayouts.resize(chain->PhysicalDeviceVulkan14Properties.copyDstLayoutCount);
    chain->PhysicalDeviceVulkan14Properties.pCopyDstLayouts = chain->VkPhysicalDeviceVulkan14Properties_pCopyDstLayouts.data();
    return true;
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

bool prepare_phys_device_mem_props2_twocall_chain_vectors(std::unique_ptr<phys_device_mem_props2_chain>& chain) {
    (void)chain;
    return false;
}
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
    VkPhysicalDeviceDynamicRenderingLocalReadFeatures PhysicalDeviceDynamicRenderingLocalReadFeatures{};
    VkPhysicalDeviceExtendedDynamicState2FeaturesEXT PhysicalDeviceExtendedDynamicState2FeaturesEXT{};
    VkPhysicalDeviceExtendedDynamicStateFeaturesEXT PhysicalDeviceExtendedDynamicStateFeaturesEXT{};
    VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT PhysicalDeviceFragmentShaderInterlockFeaturesEXT{};
    VkPhysicalDeviceFragmentShadingRateFeaturesKHR PhysicalDeviceFragmentShadingRateFeaturesKHR{};
    VkPhysicalDeviceGlobalPriorityQueryFeatures PhysicalDeviceGlobalPriorityQueryFeatures{};
    VkPhysicalDeviceHostImageCopyFeatures PhysicalDeviceHostImageCopyFeatures{};
    VkPhysicalDeviceHostQueryResetFeatures PhysicalDeviceHostQueryResetFeatures{};
    VkPhysicalDeviceImageRobustnessFeatures PhysicalDeviceImageRobustnessFeatures{};
    VkPhysicalDeviceImagelessFramebufferFeatures PhysicalDeviceImagelessFramebufferFeatures{};
    VkPhysicalDeviceIndexTypeUint8Features PhysicalDeviceIndexTypeUint8Features{};
    VkPhysicalDeviceInlineUniformBlockFeatures PhysicalDeviceInlineUniformBlockFeatures{};
    VkPhysicalDeviceLineRasterizationFeatures PhysicalDeviceLineRasterizationFeatures{};
    VkPhysicalDeviceMaintenance4Features PhysicalDeviceMaintenance4Features{};
    VkPhysicalDeviceMaintenance5Features PhysicalDeviceMaintenance5Features{};
    VkPhysicalDeviceMaintenance6Features PhysicalDeviceMaintenance6Features{};
    VkPhysicalDeviceMultiviewFeatures PhysicalDeviceMultiviewFeatures{};
    VkPhysicalDevicePerformanceQueryFeaturesKHR PhysicalDevicePerformanceQueryFeaturesKHR{};
    VkPhysicalDevicePipelineCreationCacheControlFeatures PhysicalDevicePipelineCreationCacheControlFeatures{};
    VkPhysicalDevicePipelineProtectedAccessFeatures PhysicalDevicePipelineProtectedAccessFeatures{};
    VkPhysicalDevicePipelineRobustnessFeatures PhysicalDevicePipelineRobustnessFeatures{};
    VkPhysicalDevicePrivateDataFeatures PhysicalDevicePrivateDataFeatures{};
    VkPhysicalDeviceProtectedMemoryFeatures PhysicalDeviceProtectedMemoryFeatures{};
    VkPhysicalDeviceRobustness2FeaturesKHR PhysicalDeviceRobustness2FeaturesKHR{};
    VkPhysicalDeviceSamplerYcbcrConversionFeatures PhysicalDeviceSamplerYcbcrConversionFeatures{};
    VkPhysicalDeviceScalarBlockLayoutFeatures PhysicalDeviceScalarBlockLayoutFeatures{};
    VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures PhysicalDeviceSeparateDepthStencilLayoutsFeatures{};
    VkPhysicalDeviceShaderAtomicFloatFeaturesEXT PhysicalDeviceShaderAtomicFloatFeaturesEXT{};
    VkPhysicalDeviceShaderAtomicInt64Features PhysicalDeviceShaderAtomicInt64Features{};
    VkPhysicalDeviceShaderClockFeaturesKHR PhysicalDeviceShaderClockFeaturesKHR{};
    VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures PhysicalDeviceShaderDemoteToHelperInvocationFeatures{};
    VkPhysicalDeviceShaderDrawParametersFeatures PhysicalDeviceShaderDrawParametersFeatures{};
    VkPhysicalDeviceShaderExpectAssumeFeatures PhysicalDeviceShaderExpectAssumeFeatures{};
    VkPhysicalDeviceShaderFloat16Int8Features PhysicalDeviceShaderFloat16Int8Features{};
    VkPhysicalDeviceShaderFloatControls2Features PhysicalDeviceShaderFloatControls2Features{};
    VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT PhysicalDeviceShaderImageAtomicInt64FeaturesEXT{};
    VkPhysicalDeviceShaderIntegerDotProductFeatures PhysicalDeviceShaderIntegerDotProductFeatures{};
    char VkPhysicalDeviceShaderIntegerDotProductFeatures_padding[64];
    VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures PhysicalDeviceShaderSubgroupExtendedTypesFeatures{};
    VkPhysicalDeviceShaderSubgroupRotateFeatures PhysicalDeviceShaderSubgroupRotateFeatures{};
    VkPhysicalDeviceShaderTerminateInvocationFeatures PhysicalDeviceShaderTerminateInvocationFeatures{};
    VkPhysicalDeviceSubgroupSizeControlFeatures PhysicalDeviceSubgroupSizeControlFeatures{};
    VkPhysicalDeviceSynchronization2Features PhysicalDeviceSynchronization2Features{};
    VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT PhysicalDeviceTexelBufferAlignmentFeaturesEXT{};
    VkPhysicalDeviceTextureCompressionASTCHDRFeatures PhysicalDeviceTextureCompressionASTCHDRFeatures{};
    VkPhysicalDeviceTimelineSemaphoreFeatures PhysicalDeviceTimelineSemaphoreFeatures{};
    VkPhysicalDeviceUniformBufferStandardLayoutFeatures PhysicalDeviceUniformBufferStandardLayoutFeatures{};
    VkPhysicalDeviceVariablePointersFeatures PhysicalDeviceVariablePointersFeatures{};
    VkPhysicalDeviceVertexAttributeDivisorFeatures PhysicalDeviceVertexAttributeDivisorFeatures{};
    VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT PhysicalDeviceVertexInputDynamicStateFeaturesEXT{};
    VkPhysicalDeviceVulkan11Features PhysicalDeviceVulkan11Features{};
    VkPhysicalDeviceVulkan12Features PhysicalDeviceVulkan12Features{};
    VkPhysicalDeviceVulkan13Features PhysicalDeviceVulkan13Features{};
    VkPhysicalDeviceVulkan14Features PhysicalDeviceVulkan14Features{};
    VkPhysicalDeviceVulkanMemoryModelFeatures PhysicalDeviceVulkanMemoryModelFeatures{};
    VkPhysicalDeviceVulkanSC10Features PhysicalDeviceVulkanSC10Features{};
    VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT PhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT{};
    VkPhysicalDeviceYcbcrImageArraysFeaturesEXT PhysicalDeviceYcbcrImageArraysFeaturesEXT{};
    VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures PhysicalDeviceZeroInitializeWorkgroupMemoryFeatures{};
    void initialize_chain(AppGpu &gpu , bool show_promoted_structs) noexcept {
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
        PhysicalDeviceDynamicRenderingLocalReadFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_LOCAL_READ_FEATURES;
        PhysicalDeviceExtendedDynamicState2FeaturesEXT.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_2_FEATURES_EXT;
        PhysicalDeviceExtendedDynamicStateFeaturesEXT.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_FEATURES_EXT;
        PhysicalDeviceFragmentShaderInterlockFeaturesEXT.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT;
        PhysicalDeviceFragmentShadingRateFeaturesKHR.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_FEATURES_KHR;
        PhysicalDeviceGlobalPriorityQueryFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES;
        PhysicalDeviceHostImageCopyFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_IMAGE_COPY_FEATURES;
        PhysicalDeviceHostQueryResetFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES;
        PhysicalDeviceImageRobustnessFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES;
        PhysicalDeviceImagelessFramebufferFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES;
        PhysicalDeviceIndexTypeUint8Features.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES;
        PhysicalDeviceInlineUniformBlockFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES;
        PhysicalDeviceLineRasterizationFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES;
        PhysicalDeviceMaintenance4Features.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_FEATURES;
        PhysicalDeviceMaintenance5Features.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_FEATURES;
        PhysicalDeviceMaintenance6Features.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_6_FEATURES;
        PhysicalDeviceMultiviewFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES;
        PhysicalDevicePerformanceQueryFeaturesKHR.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_FEATURES_KHR;
        PhysicalDevicePipelineCreationCacheControlFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES;
        PhysicalDevicePipelineProtectedAccessFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_PROTECTED_ACCESS_FEATURES;
        PhysicalDevicePipelineRobustnessFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_FEATURES;
        PhysicalDevicePrivateDataFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIVATE_DATA_FEATURES;
        PhysicalDeviceProtectedMemoryFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES;
        PhysicalDeviceRobustness2FeaturesKHR.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_KHR;
        PhysicalDeviceSamplerYcbcrConversionFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES;
        PhysicalDeviceScalarBlockLayoutFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES;
        PhysicalDeviceSeparateDepthStencilLayoutsFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES;
        PhysicalDeviceShaderAtomicFloatFeaturesEXT.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_FEATURES_EXT;
        PhysicalDeviceShaderAtomicInt64Features.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES;
        PhysicalDeviceShaderClockFeaturesKHR.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR;
        PhysicalDeviceShaderDemoteToHelperInvocationFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES;
        PhysicalDeviceShaderDrawParametersFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES;
        PhysicalDeviceShaderExpectAssumeFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EXPECT_ASSUME_FEATURES;
        PhysicalDeviceShaderFloat16Int8Features.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES;
        PhysicalDeviceShaderFloatControls2Features.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT_CONTROLS_2_FEATURES;
        PhysicalDeviceShaderImageAtomicInt64FeaturesEXT.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_ATOMIC_INT64_FEATURES_EXT;
        PhysicalDeviceShaderIntegerDotProductFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_FEATURES;
        PhysicalDeviceShaderSubgroupExtendedTypesFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES;
        PhysicalDeviceShaderSubgroupRotateFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_ROTATE_FEATURES;
        PhysicalDeviceShaderTerminateInvocationFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TERMINATE_INVOCATION_FEATURES;
        PhysicalDeviceSubgroupSizeControlFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES;
        PhysicalDeviceSynchronization2Features.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SYNCHRONIZATION_2_FEATURES;
        PhysicalDeviceTexelBufferAlignmentFeaturesEXT.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT;
        PhysicalDeviceTextureCompressionASTCHDRFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES;
        PhysicalDeviceTimelineSemaphoreFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES;
        PhysicalDeviceUniformBufferStandardLayoutFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES;
        PhysicalDeviceVariablePointersFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES;
        PhysicalDeviceVertexAttributeDivisorFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES;
        PhysicalDeviceVertexInputDynamicStateFeaturesEXT.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_INPUT_DYNAMIC_STATE_FEATURES_EXT;
        PhysicalDeviceVulkan11Features.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES;
        PhysicalDeviceVulkan12Features.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES;
        PhysicalDeviceVulkan13Features.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES;
        PhysicalDeviceVulkan14Features.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_4_FEATURES;
        PhysicalDeviceVulkanMemoryModelFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES;
        PhysicalDeviceVulkanSC10Features.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_SC_1_0_FEATURES;
        PhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_2_PLANE_444_FORMATS_FEATURES_EXT;
        PhysicalDeviceYcbcrImageArraysFeaturesEXT.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT;
        PhysicalDeviceZeroInitializeWorkgroupMemoryFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_WORKGROUP_MEMORY_FEATURES;
        std::vector<VkBaseOutStructure*> chain_members{};
        if ((gpu.api_version >= VK_API_VERSION_1_1))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDevice16BitStorageFeatures));
        if (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_4444_FORMATS_EXTENSION_NAME))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDevice4444FormatsFeaturesEXT));
        if ((gpu.api_version >= VK_API_VERSION_1_2))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDevice8BitStorageFeatures));
        if (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_ASTC_DECODE_MODE_EXTENSION_NAME))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceASTCDecodeFeaturesEXT));
        if (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_BLEND_OPERATION_ADVANCED_EXTENSION_NAME))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceBlendOperationAdvancedFeaturesEXT));
        if ((gpu.api_version >= VK_API_VERSION_1_2))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceBufferDeviceAddressFeatures));
        if (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_COLOR_WRITE_ENABLE_EXTENSION_NAME))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceColorWriteEnableFeaturesEXT));
        if (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_CUSTOM_BORDER_COLOR_EXTENSION_NAME))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceCustomBorderColorFeaturesEXT));
        if (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_DEPTH_CLIP_ENABLE_EXTENSION_NAME))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceDepthClipEnableFeaturesEXT));
        if ((gpu.api_version >= VK_API_VERSION_1_2))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceDescriptorIndexingFeatures));
        if ((gpu.api_version >= VK_API_VERSION_1_3))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceDynamicRenderingFeatures));
        if ((gpu.api_version >= VK_API_VERSION_1_4))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceDynamicRenderingLocalReadFeatures));
        if (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_EXTENDED_DYNAMIC_STATE_2_EXTENSION_NAME))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceExtendedDynamicState2FeaturesEXT));
        if (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_EXTENDED_DYNAMIC_STATE_EXTENSION_NAME))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceExtendedDynamicStateFeaturesEXT));
        if (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_FRAGMENT_SHADER_INTERLOCK_EXTENSION_NAME))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceFragmentShaderInterlockFeaturesEXT));
        if (gpu.CheckPhysicalDeviceExtensionIncluded(VK_KHR_FRAGMENT_SHADING_RATE_EXTENSION_NAME))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceFragmentShadingRateFeaturesKHR));
        if ((gpu.CheckPhysicalDeviceExtensionIncluded(VK_KHR_GLOBAL_PRIORITY_EXTENSION_NAME))
            && (gpu.api_version < VK_API_VERSION_1_4 || show_promoted_structs))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceGlobalPriorityQueryFeatures));
        if ((gpu.api_version >= VK_API_VERSION_1_4))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceHostImageCopyFeatures));
        if ((gpu.api_version >= VK_API_VERSION_1_2))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceHostQueryResetFeatures));
        if ((gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_IMAGE_ROBUSTNESS_EXTENSION_NAME))
            && (gpu.api_version < VK_API_VERSION_1_3 || show_promoted_structs))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceImageRobustnessFeatures));
        if ((gpu.api_version >= VK_API_VERSION_1_2))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceImagelessFramebufferFeatures));
        if ((gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_INDEX_TYPE_UINT8_EXTENSION_NAME)
         || gpu.CheckPhysicalDeviceExtensionIncluded(VK_KHR_INDEX_TYPE_UINT8_EXTENSION_NAME))
            && (gpu.api_version < VK_API_VERSION_1_4 || show_promoted_structs))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceIndexTypeUint8Features));
        if ((gpu.api_version >= VK_API_VERSION_1_3))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceInlineUniformBlockFeatures));
        if ((gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_LINE_RASTERIZATION_EXTENSION_NAME)
         || gpu.CheckPhysicalDeviceExtensionIncluded(VK_KHR_LINE_RASTERIZATION_EXTENSION_NAME))
            && (gpu.api_version < VK_API_VERSION_1_4 || show_promoted_structs))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceLineRasterizationFeatures));
        if ((gpu.api_version >= VK_API_VERSION_1_3))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceMaintenance4Features));
        if ((gpu.api_version >= VK_API_VERSION_1_4))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceMaintenance5Features));
        if ((gpu.api_version >= VK_API_VERSION_1_4))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceMaintenance6Features));
        if ((gpu.api_version >= VK_API_VERSION_1_1))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceMultiviewFeatures));
        if (gpu.CheckPhysicalDeviceExtensionIncluded(VK_KHR_PERFORMANCE_QUERY_EXTENSION_NAME))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDevicePerformanceQueryFeaturesKHR));
        if ((gpu.api_version >= VK_API_VERSION_1_3))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDevicePipelineCreationCacheControlFeatures));
        if ((gpu.api_version >= VK_API_VERSION_1_4))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDevicePipelineProtectedAccessFeatures));
        if ((gpu.api_version >= VK_API_VERSION_1_4))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDevicePipelineRobustnessFeatures));
        if ((gpu.api_version >= VK_API_VERSION_1_3))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDevicePrivateDataFeatures));
        if (gpu.api_version == VK_API_VERSION_1_1 || show_promoted_structs)
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceProtectedMemoryFeatures));
        if (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_ROBUSTNESS_2_EXTENSION_NAME)
         || gpu.CheckPhysicalDeviceExtensionIncluded(VK_KHR_ROBUSTNESS_2_EXTENSION_NAME))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceRobustness2FeaturesKHR));
        if ((gpu.api_version >= VK_API_VERSION_1_1))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceSamplerYcbcrConversionFeatures));
        if ((gpu.api_version >= VK_API_VERSION_1_2))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceScalarBlockLayoutFeatures));
        if ((gpu.api_version >= VK_API_VERSION_1_2))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceSeparateDepthStencilLayoutsFeatures));
        if (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_SHADER_ATOMIC_FLOAT_EXTENSION_NAME))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceShaderAtomicFloatFeaturesEXT));
        if ((gpu.api_version >= VK_API_VERSION_1_2))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceShaderAtomicInt64Features));
        if (gpu.CheckPhysicalDeviceExtensionIncluded(VK_KHR_SHADER_CLOCK_EXTENSION_NAME))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceShaderClockFeaturesKHR));
        if ((gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_SHADER_DEMOTE_TO_HELPER_INVOCATION_EXTENSION_NAME))
            && (gpu.api_version < VK_API_VERSION_1_3 || show_promoted_structs))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceShaderDemoteToHelperInvocationFeatures));
        if (gpu.api_version == VK_API_VERSION_1_1 || show_promoted_structs)
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceShaderDrawParametersFeatures));
        if ((gpu.api_version >= VK_API_VERSION_1_4))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceShaderExpectAssumeFeatures));
        if ((gpu.api_version >= VK_API_VERSION_1_2))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceShaderFloat16Int8Features));
        if ((gpu.api_version >= VK_API_VERSION_1_4))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceShaderFloatControls2Features));
        if (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_SHADER_IMAGE_ATOMIC_INT64_EXTENSION_NAME))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceShaderImageAtomicInt64FeaturesEXT));
        if ((gpu.api_version >= VK_API_VERSION_1_3))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceShaderIntegerDotProductFeatures));
        if ((gpu.api_version >= VK_API_VERSION_1_2))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceShaderSubgroupExtendedTypesFeatures));
        if ((gpu.api_version >= VK_API_VERSION_1_4))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceShaderSubgroupRotateFeatures));
        if ((gpu.CheckPhysicalDeviceExtensionIncluded(VK_KHR_SHADER_TERMINATE_INVOCATION_EXTENSION_NAME))
            && (gpu.api_version < VK_API_VERSION_1_3 || show_promoted_structs))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceShaderTerminateInvocationFeatures));
        if ((gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_SUBGROUP_SIZE_CONTROL_EXTENSION_NAME))
            && (gpu.api_version < VK_API_VERSION_1_3 || show_promoted_structs))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceSubgroupSizeControlFeatures));
        if ((gpu.CheckPhysicalDeviceExtensionIncluded(VK_KHR_SYNCHRONIZATION_2_EXTENSION_NAME))
            && (gpu.api_version < VK_API_VERSION_1_3 || show_promoted_structs))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceSynchronization2Features));
        if (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_TEXEL_BUFFER_ALIGNMENT_EXTENSION_NAME))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceTexelBufferAlignmentFeaturesEXT));
        if ((gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_TEXTURE_COMPRESSION_ASTC_HDR_EXTENSION_NAME))
            && (gpu.api_version < VK_API_VERSION_1_3 || show_promoted_structs))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceTextureCompressionASTCHDRFeatures));
        if ((gpu.api_version >= VK_API_VERSION_1_2))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceTimelineSemaphoreFeatures));
        if ((gpu.api_version >= VK_API_VERSION_1_2))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceUniformBufferStandardLayoutFeatures));
        if ((gpu.api_version >= VK_API_VERSION_1_1))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceVariablePointersFeatures));
        if ((gpu.CheckPhysicalDeviceExtensionIncluded(VK_KHR_VERTEX_ATTRIBUTE_DIVISOR_EXTENSION_NAME))
            && (gpu.api_version < VK_API_VERSION_1_4 || show_promoted_structs))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceVertexAttributeDivisorFeatures));
        if (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_VERTEX_INPUT_DYNAMIC_STATE_EXTENSION_NAME))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceVertexInputDynamicStateFeaturesEXT));
        if ((gpu.api_version >= VK_API_VERSION_1_2))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceVulkan11Features));
        if ((gpu.api_version >= VK_API_VERSION_1_2))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceVulkan12Features));
        if ((gpu.api_version >= VK_API_VERSION_1_3))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceVulkan13Features));
        if ((gpu.api_version >= VK_API_VERSION_1_4))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceVulkan14Features));
        if ((gpu.api_version >= VK_API_VERSION_1_2))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceVulkanMemoryModelFeatures));
        if ((gpu.api_version >= VKSC_API_VERSION_1_0))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceVulkanSC10Features));
        if (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_YCBCR_2PLANE_444_FORMATS_EXTENSION_NAME))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT));
        if (gpu.CheckPhysicalDeviceExtensionIncluded(VK_EXT_YCBCR_IMAGE_ARRAYS_EXTENSION_NAME))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceYcbcrImageArraysFeaturesEXT));
        if ((gpu.api_version >= VK_API_VERSION_1_3))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&PhysicalDeviceZeroInitializeWorkgroupMemoryFeatures));

        if (!chain_members.empty()) {
            for(size_t i = 0; i < chain_members.size() - 1; i++){
                chain_members[i]->pNext = chain_members[i + 1];
            }
            start_of_chain = chain_members[0];
        }
    }
};
void setup_phys_device_features2_chain(VkPhysicalDeviceFeatures2& start, std::unique_ptr<phys_device_features2_chain>& chain, AppGpu &gpu,bool show_promoted_structs){
    chain = std::unique_ptr<phys_device_features2_chain>(new phys_device_features2_chain());
    chain->initialize_chain(gpu,show_promoted_structs);
    start.pNext = chain->start_of_chain;
};

void chain_iterator_phys_device_features2(Printer &p, AppGpu &gpu, bool show_promoted_structs, const void * place) {
    while (place) {
        const VkBaseOutStructure *structure = (const VkBaseOutStructure *)place;
        p.SetSubHeader();
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES) {
            const VkPhysicalDevice16BitStorageFeatures* props = (const VkPhysicalDevice16BitStorageFeatures*)structure;
            DumpVkPhysicalDevice16BitStorageFeatures(p, "VkPhysicalDevice16BitStorageFeatures", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_4444_FORMATS_FEATURES_EXT) {
            const VkPhysicalDevice4444FormatsFeaturesEXT* props = (const VkPhysicalDevice4444FormatsFeaturesEXT*)structure;
            DumpVkPhysicalDevice4444FormatsFeaturesEXT(p, "VkPhysicalDevice4444FormatsFeaturesEXT", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES) {
            const VkPhysicalDevice8BitStorageFeatures* props = (const VkPhysicalDevice8BitStorageFeatures*)structure;
            DumpVkPhysicalDevice8BitStorageFeatures(p, "VkPhysicalDevice8BitStorageFeatures", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT) {
            const VkPhysicalDeviceASTCDecodeFeaturesEXT* props = (const VkPhysicalDeviceASTCDecodeFeaturesEXT*)structure;
            DumpVkPhysicalDeviceASTCDecodeFeaturesEXT(p, "VkPhysicalDeviceASTCDecodeFeaturesEXT", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT) {
            const VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT* props = (const VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT*)structure;
            DumpVkPhysicalDeviceBlendOperationAdvancedFeaturesEXT(p, "VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES) {
            const VkPhysicalDeviceBufferDeviceAddressFeatures* props = (const VkPhysicalDeviceBufferDeviceAddressFeatures*)structure;
            DumpVkPhysicalDeviceBufferDeviceAddressFeatures(p, "VkPhysicalDeviceBufferDeviceAddressFeatures", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COLOR_WRITE_ENABLE_FEATURES_EXT) {
            const VkPhysicalDeviceColorWriteEnableFeaturesEXT* props = (const VkPhysicalDeviceColorWriteEnableFeaturesEXT*)structure;
            DumpVkPhysicalDeviceColorWriteEnableFeaturesEXT(p, "VkPhysicalDeviceColorWriteEnableFeaturesEXT", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_FEATURES_EXT) {
            const VkPhysicalDeviceCustomBorderColorFeaturesEXT* props = (const VkPhysicalDeviceCustomBorderColorFeaturesEXT*)structure;
            DumpVkPhysicalDeviceCustomBorderColorFeaturesEXT(p, "VkPhysicalDeviceCustomBorderColorFeaturesEXT", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT) {
            const VkPhysicalDeviceDepthClipEnableFeaturesEXT* props = (const VkPhysicalDeviceDepthClipEnableFeaturesEXT*)structure;
            DumpVkPhysicalDeviceDepthClipEnableFeaturesEXT(p, "VkPhysicalDeviceDepthClipEnableFeaturesEXT", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES) {
            const VkPhysicalDeviceDescriptorIndexingFeatures* props = (const VkPhysicalDeviceDescriptorIndexingFeatures*)structure;
            DumpVkPhysicalDeviceDescriptorIndexingFeatures(p, "VkPhysicalDeviceDescriptorIndexingFeatures", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_FEATURES) {
            const VkPhysicalDeviceDynamicRenderingFeatures* props = (const VkPhysicalDeviceDynamicRenderingFeatures*)structure;
            DumpVkPhysicalDeviceDynamicRenderingFeatures(p, "VkPhysicalDeviceDynamicRenderingFeatures", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_LOCAL_READ_FEATURES) {
            const VkPhysicalDeviceDynamicRenderingLocalReadFeatures* props = (const VkPhysicalDeviceDynamicRenderingLocalReadFeatures*)structure;
            DumpVkPhysicalDeviceDynamicRenderingLocalReadFeatures(p, "VkPhysicalDeviceDynamicRenderingLocalReadFeatures", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_2_FEATURES_EXT) {
            const VkPhysicalDeviceExtendedDynamicState2FeaturesEXT* props = (const VkPhysicalDeviceExtendedDynamicState2FeaturesEXT*)structure;
            DumpVkPhysicalDeviceExtendedDynamicState2FeaturesEXT(p, "VkPhysicalDeviceExtendedDynamicState2FeaturesEXT", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_FEATURES_EXT) {
            const VkPhysicalDeviceExtendedDynamicStateFeaturesEXT* props = (const VkPhysicalDeviceExtendedDynamicStateFeaturesEXT*)structure;
            DumpVkPhysicalDeviceExtendedDynamicStateFeaturesEXT(p, "VkPhysicalDeviceExtendedDynamicStateFeaturesEXT", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT) {
            const VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT* props = (const VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT*)structure;
            DumpVkPhysicalDeviceFragmentShaderInterlockFeaturesEXT(p, "VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_FEATURES_KHR) {
            const VkPhysicalDeviceFragmentShadingRateFeaturesKHR* props = (const VkPhysicalDeviceFragmentShadingRateFeaturesKHR*)structure;
            DumpVkPhysicalDeviceFragmentShadingRateFeaturesKHR(p, "VkPhysicalDeviceFragmentShadingRateFeaturesKHR", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES) {
            const VkPhysicalDeviceGlobalPriorityQueryFeatures* props = (const VkPhysicalDeviceGlobalPriorityQueryFeatures*)structure;
            DumpVkPhysicalDeviceGlobalPriorityQueryFeatures(p, gpu.api_version >= VK_API_VERSION_1_4 ?"VkPhysicalDeviceGlobalPriorityQueryFeatures":"VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_IMAGE_COPY_FEATURES) {
            const VkPhysicalDeviceHostImageCopyFeatures* props = (const VkPhysicalDeviceHostImageCopyFeatures*)structure;
            DumpVkPhysicalDeviceHostImageCopyFeatures(p, "VkPhysicalDeviceHostImageCopyFeatures", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES) {
            const VkPhysicalDeviceHostQueryResetFeatures* props = (const VkPhysicalDeviceHostQueryResetFeatures*)structure;
            DumpVkPhysicalDeviceHostQueryResetFeatures(p, "VkPhysicalDeviceHostQueryResetFeatures", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES) {
            const VkPhysicalDeviceImageRobustnessFeatures* props = (const VkPhysicalDeviceImageRobustnessFeatures*)structure;
            DumpVkPhysicalDeviceImageRobustnessFeatures(p, gpu.api_version >= VK_API_VERSION_1_3 ?"VkPhysicalDeviceImageRobustnessFeatures":"VkPhysicalDeviceImageRobustnessFeaturesEXT", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES) {
            const VkPhysicalDeviceImagelessFramebufferFeatures* props = (const VkPhysicalDeviceImagelessFramebufferFeatures*)structure;
            DumpVkPhysicalDeviceImagelessFramebufferFeatures(p, "VkPhysicalDeviceImagelessFramebufferFeatures", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES) {
            const VkPhysicalDeviceIndexTypeUint8Features* props = (const VkPhysicalDeviceIndexTypeUint8Features*)structure;
            DumpVkPhysicalDeviceIndexTypeUint8Features(p, gpu.api_version >= VK_API_VERSION_1_4 ?"VkPhysicalDeviceIndexTypeUint8Features":"VkPhysicalDeviceIndexTypeUint8FeaturesKHR", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES) {
            const VkPhysicalDeviceInlineUniformBlockFeatures* props = (const VkPhysicalDeviceInlineUniformBlockFeatures*)structure;
            DumpVkPhysicalDeviceInlineUniformBlockFeatures(p, "VkPhysicalDeviceInlineUniformBlockFeatures", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES) {
            const VkPhysicalDeviceLineRasterizationFeatures* props = (const VkPhysicalDeviceLineRasterizationFeatures*)structure;
            DumpVkPhysicalDeviceLineRasterizationFeatures(p, gpu.api_version >= VK_API_VERSION_1_4 ?"VkPhysicalDeviceLineRasterizationFeatures":"VkPhysicalDeviceLineRasterizationFeaturesKHR", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_FEATURES) {
            const VkPhysicalDeviceMaintenance4Features* props = (const VkPhysicalDeviceMaintenance4Features*)structure;
            DumpVkPhysicalDeviceMaintenance4Features(p, "VkPhysicalDeviceMaintenance4Features", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_FEATURES) {
            const VkPhysicalDeviceMaintenance5Features* props = (const VkPhysicalDeviceMaintenance5Features*)structure;
            DumpVkPhysicalDeviceMaintenance5Features(p, "VkPhysicalDeviceMaintenance5Features", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_6_FEATURES) {
            const VkPhysicalDeviceMaintenance6Features* props = (const VkPhysicalDeviceMaintenance6Features*)structure;
            DumpVkPhysicalDeviceMaintenance6Features(p, "VkPhysicalDeviceMaintenance6Features", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES) {
            const VkPhysicalDeviceMultiviewFeatures* props = (const VkPhysicalDeviceMultiviewFeatures*)structure;
            DumpVkPhysicalDeviceMultiviewFeatures(p, "VkPhysicalDeviceMultiviewFeatures", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_FEATURES_KHR) {
            const VkPhysicalDevicePerformanceQueryFeaturesKHR* props = (const VkPhysicalDevicePerformanceQueryFeaturesKHR*)structure;
            DumpVkPhysicalDevicePerformanceQueryFeaturesKHR(p, "VkPhysicalDevicePerformanceQueryFeaturesKHR", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES) {
            const VkPhysicalDevicePipelineCreationCacheControlFeatures* props = (const VkPhysicalDevicePipelineCreationCacheControlFeatures*)structure;
            DumpVkPhysicalDevicePipelineCreationCacheControlFeatures(p, "VkPhysicalDevicePipelineCreationCacheControlFeatures", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_PROTECTED_ACCESS_FEATURES) {
            const VkPhysicalDevicePipelineProtectedAccessFeatures* props = (const VkPhysicalDevicePipelineProtectedAccessFeatures*)structure;
            DumpVkPhysicalDevicePipelineProtectedAccessFeatures(p, "VkPhysicalDevicePipelineProtectedAccessFeatures", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_FEATURES) {
            const VkPhysicalDevicePipelineRobustnessFeatures* props = (const VkPhysicalDevicePipelineRobustnessFeatures*)structure;
            DumpVkPhysicalDevicePipelineRobustnessFeatures(p, "VkPhysicalDevicePipelineRobustnessFeatures", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIVATE_DATA_FEATURES) {
            const VkPhysicalDevicePrivateDataFeatures* props = (const VkPhysicalDevicePrivateDataFeatures*)structure;
            DumpVkPhysicalDevicePrivateDataFeatures(p, "VkPhysicalDevicePrivateDataFeatures", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES) {
            const VkPhysicalDeviceProtectedMemoryFeatures* props = (const VkPhysicalDeviceProtectedMemoryFeatures*)structure;
            DumpVkPhysicalDeviceProtectedMemoryFeatures(p, "VkPhysicalDeviceProtectedMemoryFeatures", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_KHR) {
            const VkPhysicalDeviceRobustness2FeaturesKHR* props = (const VkPhysicalDeviceRobustness2FeaturesKHR*)structure;
            DumpVkPhysicalDeviceRobustness2FeaturesKHR(p, "VkPhysicalDeviceRobustness2FeaturesKHR", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES) {
            const VkPhysicalDeviceSamplerYcbcrConversionFeatures* props = (const VkPhysicalDeviceSamplerYcbcrConversionFeatures*)structure;
            DumpVkPhysicalDeviceSamplerYcbcrConversionFeatures(p, "VkPhysicalDeviceSamplerYcbcrConversionFeatures", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES) {
            const VkPhysicalDeviceScalarBlockLayoutFeatures* props = (const VkPhysicalDeviceScalarBlockLayoutFeatures*)structure;
            DumpVkPhysicalDeviceScalarBlockLayoutFeatures(p, "VkPhysicalDeviceScalarBlockLayoutFeatures", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES) {
            const VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures* props = (const VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures*)structure;
            DumpVkPhysicalDeviceSeparateDepthStencilLayoutsFeatures(p, "VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_FEATURES_EXT) {
            const VkPhysicalDeviceShaderAtomicFloatFeaturesEXT* props = (const VkPhysicalDeviceShaderAtomicFloatFeaturesEXT*)structure;
            DumpVkPhysicalDeviceShaderAtomicFloatFeaturesEXT(p, "VkPhysicalDeviceShaderAtomicFloatFeaturesEXT", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES) {
            const VkPhysicalDeviceShaderAtomicInt64Features* props = (const VkPhysicalDeviceShaderAtomicInt64Features*)structure;
            DumpVkPhysicalDeviceShaderAtomicInt64Features(p, "VkPhysicalDeviceShaderAtomicInt64Features", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR) {
            const VkPhysicalDeviceShaderClockFeaturesKHR* props = (const VkPhysicalDeviceShaderClockFeaturesKHR*)structure;
            DumpVkPhysicalDeviceShaderClockFeaturesKHR(p, "VkPhysicalDeviceShaderClockFeaturesKHR", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES) {
            const VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures* props = (const VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures*)structure;
            DumpVkPhysicalDeviceShaderDemoteToHelperInvocationFeatures(p, gpu.api_version >= VK_API_VERSION_1_3 ?"VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures":"VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES) {
            const VkPhysicalDeviceShaderDrawParametersFeatures* props = (const VkPhysicalDeviceShaderDrawParametersFeatures*)structure;
            DumpVkPhysicalDeviceShaderDrawParametersFeatures(p, gpu.api_version >= VK_API_VERSION_1_1 ?"VkPhysicalDeviceShaderDrawParametersFeatures":"VkPhysicalDeviceShaderDrawParameterFeatures", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EXPECT_ASSUME_FEATURES) {
            const VkPhysicalDeviceShaderExpectAssumeFeatures* props = (const VkPhysicalDeviceShaderExpectAssumeFeatures*)structure;
            DumpVkPhysicalDeviceShaderExpectAssumeFeatures(p, "VkPhysicalDeviceShaderExpectAssumeFeatures", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES) {
            const VkPhysicalDeviceShaderFloat16Int8Features* props = (const VkPhysicalDeviceShaderFloat16Int8Features*)structure;
            DumpVkPhysicalDeviceShaderFloat16Int8Features(p, "VkPhysicalDeviceShaderFloat16Int8Features", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT_CONTROLS_2_FEATURES) {
            const VkPhysicalDeviceShaderFloatControls2Features* props = (const VkPhysicalDeviceShaderFloatControls2Features*)structure;
            DumpVkPhysicalDeviceShaderFloatControls2Features(p, "VkPhysicalDeviceShaderFloatControls2Features", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_ATOMIC_INT64_FEATURES_EXT) {
            const VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT* props = (const VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT*)structure;
            DumpVkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT(p, "VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_FEATURES) {
            const VkPhysicalDeviceShaderIntegerDotProductFeatures* props = (const VkPhysicalDeviceShaderIntegerDotProductFeatures*)structure;
            DumpVkPhysicalDeviceShaderIntegerDotProductFeatures(p, "VkPhysicalDeviceShaderIntegerDotProductFeatures", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES) {
            const VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures* props = (const VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures*)structure;
            DumpVkPhysicalDeviceShaderSubgroupExtendedTypesFeatures(p, "VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_ROTATE_FEATURES) {
            const VkPhysicalDeviceShaderSubgroupRotateFeatures* props = (const VkPhysicalDeviceShaderSubgroupRotateFeatures*)structure;
            DumpVkPhysicalDeviceShaderSubgroupRotateFeatures(p, "VkPhysicalDeviceShaderSubgroupRotateFeatures", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TERMINATE_INVOCATION_FEATURES) {
            const VkPhysicalDeviceShaderTerminateInvocationFeatures* props = (const VkPhysicalDeviceShaderTerminateInvocationFeatures*)structure;
            DumpVkPhysicalDeviceShaderTerminateInvocationFeatures(p, gpu.api_version >= VK_API_VERSION_1_3 ?"VkPhysicalDeviceShaderTerminateInvocationFeatures":"VkPhysicalDeviceShaderTerminateInvocationFeaturesKHR", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES) {
            const VkPhysicalDeviceSubgroupSizeControlFeatures* props = (const VkPhysicalDeviceSubgroupSizeControlFeatures*)structure;
            DumpVkPhysicalDeviceSubgroupSizeControlFeatures(p, gpu.api_version >= VK_API_VERSION_1_3 ?"VkPhysicalDeviceSubgroupSizeControlFeatures":"VkPhysicalDeviceSubgroupSizeControlFeaturesEXT", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SYNCHRONIZATION_2_FEATURES) {
            const VkPhysicalDeviceSynchronization2Features* props = (const VkPhysicalDeviceSynchronization2Features*)structure;
            DumpVkPhysicalDeviceSynchronization2Features(p, gpu.api_version >= VK_API_VERSION_1_3 ?"VkPhysicalDeviceSynchronization2Features":"VkPhysicalDeviceSynchronization2FeaturesKHR", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT) {
            const VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT* props = (const VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT*)structure;
            DumpVkPhysicalDeviceTexelBufferAlignmentFeaturesEXT(p, "VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES) {
            const VkPhysicalDeviceTextureCompressionASTCHDRFeatures* props = (const VkPhysicalDeviceTextureCompressionASTCHDRFeatures*)structure;
            DumpVkPhysicalDeviceTextureCompressionASTCHDRFeatures(p, gpu.api_version >= VK_API_VERSION_1_3 ?"VkPhysicalDeviceTextureCompressionASTCHDRFeatures":"VkPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES) {
            const VkPhysicalDeviceTimelineSemaphoreFeatures* props = (const VkPhysicalDeviceTimelineSemaphoreFeatures*)structure;
            DumpVkPhysicalDeviceTimelineSemaphoreFeatures(p, "VkPhysicalDeviceTimelineSemaphoreFeatures", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES) {
            const VkPhysicalDeviceUniformBufferStandardLayoutFeatures* props = (const VkPhysicalDeviceUniformBufferStandardLayoutFeatures*)structure;
            DumpVkPhysicalDeviceUniformBufferStandardLayoutFeatures(p, "VkPhysicalDeviceUniformBufferStandardLayoutFeatures", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES) {
            const VkPhysicalDeviceVariablePointersFeatures* props = (const VkPhysicalDeviceVariablePointersFeatures*)structure;
            DumpVkPhysicalDeviceVariablePointersFeatures(p, gpu.api_version >= VK_API_VERSION_1_1 ?"VkPhysicalDeviceVariablePointersFeatures":"VkPhysicalDeviceVariablePointerFeatures", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES) {
            const VkPhysicalDeviceVertexAttributeDivisorFeatures* props = (const VkPhysicalDeviceVertexAttributeDivisorFeatures*)structure;
            DumpVkPhysicalDeviceVertexAttributeDivisorFeatures(p, gpu.api_version >= VK_API_VERSION_1_4 ?"VkPhysicalDeviceVertexAttributeDivisorFeatures":"VkPhysicalDeviceVertexAttributeDivisorFeaturesKHR", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_INPUT_DYNAMIC_STATE_FEATURES_EXT) {
            const VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT* props = (const VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT*)structure;
            DumpVkPhysicalDeviceVertexInputDynamicStateFeaturesEXT(p, "VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES) {
            const VkPhysicalDeviceVulkan11Features* props = (const VkPhysicalDeviceVulkan11Features*)structure;
            DumpVkPhysicalDeviceVulkan11Features(p, "VkPhysicalDeviceVulkan11Features", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES) {
            const VkPhysicalDeviceVulkan12Features* props = (const VkPhysicalDeviceVulkan12Features*)structure;
            DumpVkPhysicalDeviceVulkan12Features(p, "VkPhysicalDeviceVulkan12Features", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES) {
            const VkPhysicalDeviceVulkan13Features* props = (const VkPhysicalDeviceVulkan13Features*)structure;
            DumpVkPhysicalDeviceVulkan13Features(p, "VkPhysicalDeviceVulkan13Features", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_4_FEATURES) {
            const VkPhysicalDeviceVulkan14Features* props = (const VkPhysicalDeviceVulkan14Features*)structure;
            DumpVkPhysicalDeviceVulkan14Features(p, "VkPhysicalDeviceVulkan14Features", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES) {
            const VkPhysicalDeviceVulkanMemoryModelFeatures* props = (const VkPhysicalDeviceVulkanMemoryModelFeatures*)structure;
            DumpVkPhysicalDeviceVulkanMemoryModelFeatures(p, "VkPhysicalDeviceVulkanMemoryModelFeatures", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_SC_1_0_FEATURES) {
            const VkPhysicalDeviceVulkanSC10Features* props = (const VkPhysicalDeviceVulkanSC10Features*)structure;
            DumpVkPhysicalDeviceVulkanSC10Features(p, "VkPhysicalDeviceVulkanSC10Features", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_2_PLANE_444_FORMATS_FEATURES_EXT) {
            const VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT* props = (const VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT*)structure;
            DumpVkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT(p, "VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT) {
            const VkPhysicalDeviceYcbcrImageArraysFeaturesEXT* props = (const VkPhysicalDeviceYcbcrImageArraysFeaturesEXT*)structure;
            DumpVkPhysicalDeviceYcbcrImageArraysFeaturesEXT(p, "VkPhysicalDeviceYcbcrImageArraysFeaturesEXT", *props);
            p.AddNewline();
        }
        if (structure->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_WORKGROUP_MEMORY_FEATURES) {
            const VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures* props = (const VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures*)structure;
            DumpVkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures(p, "VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures", *props);
            p.AddNewline();
        }
        place = structure->pNext;
    }
}

bool prepare_phys_device_features2_twocall_chain_vectors(std::unique_ptr<phys_device_features2_chain>& chain) {
    (void)chain;
    return false;
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

void chain_iterator_surface_capabilities2(Printer &p, AppInstance &inst, AppGpu &gpu, const void * place) {
    while (place) {
        const VkBaseOutStructure *structure = (const VkBaseOutStructure *)place;
        p.SetSubHeader();
        if (structure->sType == VK_STRUCTURE_TYPE_SHARED_PRESENT_SURFACE_CAPABILITIES_KHR) {
            const VkSharedPresentSurfaceCapabilitiesKHR* props = (const VkSharedPresentSurfaceCapabilitiesKHR*)structure;
            DumpVkSharedPresentSurfaceCapabilitiesKHR(p, "VkSharedPresentSurfaceCapabilitiesKHR", *props);
            p.AddNewline();
        }
        place = structure->pNext;
    }
}

bool prepare_surface_capabilities2_twocall_chain_vectors(std::unique_ptr<surface_capabilities2_chain>& chain) {
    (void)chain;
    return false;
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
        if ((gpu.api_version >= VK_API_VERSION_1_3))
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

void chain_iterator_format_properties2(Printer &p, AppGpu &gpu, const void * place) {
    while (place) {
        const VkBaseOutStructure *structure = (const VkBaseOutStructure *)place;
        p.SetSubHeader();
        if (structure->sType == VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_3) {
            const VkFormatProperties3* props = (const VkFormatProperties3*)structure;
            DumpVkFormatProperties3(p, "VkFormatProperties3", *props);
            p.AddNewline();
        }
        place = structure->pNext;
    }
}

bool prepare_format_properties2_twocall_chain_vectors(std::unique_ptr<format_properties2_chain>& chain) {
    (void)chain;
    return false;
}
struct queue_properties2_chain {
    queue_properties2_chain() = default;
    queue_properties2_chain(const queue_properties2_chain &) = delete;
    queue_properties2_chain& operator=(const queue_properties2_chain &) = delete;
    queue_properties2_chain(queue_properties2_chain &&) = delete;
    queue_properties2_chain& operator=(queue_properties2_chain &&) = delete;
    void* start_of_chain = nullptr;
    VkQueueFamilyGlobalPriorityProperties QueueFamilyGlobalPriorityProperties{};
    void initialize_chain(AppGpu &gpu ) noexcept {
        QueueFamilyGlobalPriorityProperties.sType = VK_STRUCTURE_TYPE_QUEUE_FAMILY_GLOBAL_PRIORITY_PROPERTIES;
        std::vector<VkBaseOutStructure*> chain_members{};
        if ((gpu.CheckPhysicalDeviceExtensionIncluded(VK_KHR_GLOBAL_PRIORITY_EXTENSION_NAME))
            && (gpu.api_version < VK_API_VERSION_1_4 ))
            chain_members.push_back(reinterpret_cast<VkBaseOutStructure*>(&QueueFamilyGlobalPriorityProperties));

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

void chain_iterator_queue_properties2(Printer &p, AppGpu &gpu, const void * place) {
    while (place) {
        const VkBaseOutStructure *structure = (const VkBaseOutStructure *)place;
        p.SetSubHeader();
        if (structure->sType == VK_STRUCTURE_TYPE_QUEUE_FAMILY_GLOBAL_PRIORITY_PROPERTIES) {
            const VkQueueFamilyGlobalPriorityProperties* props = (const VkQueueFamilyGlobalPriorityProperties*)structure;
            DumpVkQueueFamilyGlobalPriorityProperties(p, gpu.api_version >= VK_API_VERSION_1_4 ?"VkQueueFamilyGlobalPriorityProperties":"VkQueueFamilyGlobalPriorityPropertiesKHR", *props);
            p.AddNewline();
        }
        place = structure->pNext;
    }
}

bool prepare_queue_properties2_twocall_chain_vectors(std::unique_ptr<queue_properties2_chain>& chain) {
    (void)chain;
    return false;
}
struct video_profile_info_chain {
    video_profile_info_chain() = default;
    video_profile_info_chain(const video_profile_info_chain &) = delete;
    video_profile_info_chain& operator=(const video_profile_info_chain &) = delete;
    video_profile_info_chain(video_profile_info_chain &&) = delete;
    video_profile_info_chain& operator=(video_profile_info_chain &&) = delete;
    void* start_of_chain = nullptr;
    void initialize_chain(AppGpu &gpu ) noexcept {
        std::vector<VkBaseOutStructure*> chain_members{};

        if (!chain_members.empty()) {
            for(size_t i = 0; i < chain_members.size() - 1; i++){
                chain_members[i]->pNext = chain_members[i + 1];
            }
            start_of_chain = chain_members[0];
        }
    }
};
void setup_video_profile_info_chain(VkVideoProfileInfoKHR& start, std::unique_ptr<video_profile_info_chain>& chain, AppGpu &gpu){
    chain = std::unique_ptr<video_profile_info_chain>(new video_profile_info_chain());
    chain->initialize_chain(gpu);
    start.pNext = chain->start_of_chain;
};

void chain_iterator_video_profile_info(Printer &p, AppGpu &gpu, const void * place) {
    while (place) {
        const VkBaseOutStructure *structure = (const VkBaseOutStructure *)place;
        p.SetSubHeader();
        place = structure->pNext;
    }
}

bool prepare_video_profile_info_twocall_chain_vectors(std::unique_ptr<video_profile_info_chain>& chain) {
    (void)chain;
    return false;
}
struct video_capabilities_chain {
    video_capabilities_chain() = default;
    video_capabilities_chain(const video_capabilities_chain &) = delete;
    video_capabilities_chain& operator=(const video_capabilities_chain &) = delete;
    video_capabilities_chain(video_capabilities_chain &&) = delete;
    video_capabilities_chain& operator=(video_capabilities_chain &&) = delete;
    void* start_of_chain = nullptr;
    void initialize_chain(AppGpu &gpu ) noexcept {
        std::vector<VkBaseOutStructure*> chain_members{};

        if (!chain_members.empty()) {
            for(size_t i = 0; i < chain_members.size() - 1; i++){
                chain_members[i]->pNext = chain_members[i + 1];
            }
            start_of_chain = chain_members[0];
        }
    }
};
void setup_video_capabilities_chain(VkVideoCapabilitiesKHR& start, std::unique_ptr<video_capabilities_chain>& chain, AppGpu &gpu){
    chain = std::unique_ptr<video_capabilities_chain>(new video_capabilities_chain());
    chain->initialize_chain(gpu);
    start.pNext = chain->start_of_chain;
};

void chain_iterator_video_capabilities(Printer &p, AppGpu &gpu, const void * place) {
    while (place) {
        const VkBaseOutStructure *structure = (const VkBaseOutStructure *)place;
        p.SetSubHeader();
        place = structure->pNext;
    }
}

bool prepare_video_capabilities_twocall_chain_vectors(std::unique_ptr<video_capabilities_chain>& chain) {
    (void)chain;
    return false;
}
struct video_format_properties_chain {
    video_format_properties_chain() = default;
    video_format_properties_chain(const video_format_properties_chain &) = delete;
    video_format_properties_chain& operator=(const video_format_properties_chain &) = delete;
    video_format_properties_chain(video_format_properties_chain &&) = delete;
    video_format_properties_chain& operator=(video_format_properties_chain &&) = delete;
    void* start_of_chain = nullptr;
    void initialize_chain(AppGpu &gpu ) noexcept {
        std::vector<VkBaseOutStructure*> chain_members{};

        if (!chain_members.empty()) {
            for(size_t i = 0; i < chain_members.size() - 1; i++){
                chain_members[i]->pNext = chain_members[i + 1];
            }
            start_of_chain = chain_members[0];
        }
    }
};
void setup_video_format_properties_chain(VkVideoFormatPropertiesKHR& start, std::unique_ptr<video_format_properties_chain>& chain, AppGpu &gpu){
    chain = std::unique_ptr<video_format_properties_chain>(new video_format_properties_chain());
    chain->initialize_chain(gpu);
    start.pNext = chain->start_of_chain;
};

void chain_iterator_video_format_properties(Printer &p, AppGpu &gpu, const void * place) {
    while (place) {
        const VkBaseOutStructure *structure = (const VkBaseOutStructure *)place;
        p.SetSubHeader();
        place = structure->pNext;
    }
}

bool prepare_video_format_properties_twocall_chain_vectors(std::unique_ptr<video_format_properties_chain>& chain) {
    (void)chain;
    return false;
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
    FormatRange{VK_API_VERSION_1_4, nullptr, static_cast<VkFormat>(1000470000), static_cast<VkFormat>(1000470001)},
    FormatRange{0, VK_KHR_MAINTENANCE_5_EXTENSION_NAME, static_cast<VkFormat>(1000470000), static_cast<VkFormat>(1000470001)},
};

