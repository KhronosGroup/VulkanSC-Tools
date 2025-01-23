# Copyright (c) 2025 The Khronos Group Inc.
# Copyright (c) 2025 RasterGrid Kft.
#
# SPDX-License-Identifier: Apache-2.0

file(READ "${INPUT}" input_file HEX)
set(out_file)

string(LENGTH "${input_file}" input_hex_length)
math(EXPR input_hex_length_minus_two "${input_hex_length} - 2")
foreach(idx RANGE 0 ${input_hex_length_minus_two} 2)
    string(SUBSTRING "${input_file}" ${idx} 2 input_hex_byte)
    string(APPEND out_file "0x${input_hex_byte},")
endforeach()

string(REGEX REPLACE [[,$]] "" out_file "${out_file}")
file(WRITE "${OUTPUT}" "${out_file}") 