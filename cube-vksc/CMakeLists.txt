# ~~~
# Copyright (c) 2025 The Khronos Group Inc.
# Copyright (c) 2018 Valve Corporation
# Copyright (c) 2018 LunarG, Inc.
# Copyright (c) 2025 RasterGrid Kft.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
# ~~~

option(BUILD_WSI_DISPLAY_SUPPORT "Build DISPLAY WSI support" ON)
set(VKSC_PIPELINE_CACHE_COMPILER "" CACHE FILEPATH "Path to the Vulkan SC pipeline cache compiler")
set(VKSC_PIPELINE_CACHE_FLAGS "" CACHE STRING "Additional flags to pass to the pipeline cache compiler")

if(NOT VKSC_PIPELINE_CACHE_COMPILER)
    message(STATUS "Using self-hosted Vulkan SC Emulation ICD pipeline cache. Provide a pipeline cache compile via VKSC_PIPELINE_CACHE_COMPILER should a different one be needed.")
endif()

if(BUILD_WSI_DISPLAY_SUPPORT)
    list(APPEND ENABLED_CUBE_PLATFORMS VK_USE_PLATFORM_DISPLAY_KHR)
endif()

if(WIN32)
    add_definitions(-DWIN32_LEAN_AND_MEAN -DNOMINMAX)
    list(APPEND ENABLED_CUBE_PLATFORMS VK_USE_PLATFORM_WIN32_KHR)
elseif(CMAKE_SYSTEM_NAME MATCHES "Linux|BSD|GNU")
    link_libraries(${API_LOWERCASE} m)
else()
    message(FATAL_ERROR "Unsupported Platform!")
endif()

if(NOT DEFINED ENABLED_CUBE_PLATFORMS)
        message(FATAL_ERROR "There are no supported WSI platforms on this system, vkcube requires a WSI platform be available to be able to render its output")
endif()

if (COMPILE_CUBE_SHADERS)
    # Try to find glslang in system paths or in an SDK if the VULKAN_SDK env-var is set
    find_program(GLSLANG_VALIDATOR names glslang glslangValidator HINTS $ENV{GLSLANG_INSTALL_DIR} $ENV{VULKAN_SDK}/bin $ENV{VULKAN_SDK}/Bin)

    add_custom_command(COMMENT "Compiling cube vertex shader"
                    OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/cube.vert.spv
                    COMMAND ${GLSLANG_VALIDATOR} --target-env vulkan1.2 -o ${CMAKE_CURRENT_SOURCE_DIR}/cube.vert.spv
                        ${CMAKE_CURRENT_SOURCE_DIR}/cube.vert
                    MAIN_DEPENDENCY cube.vert
                    DEPENDS cube.vert ${GLSLANG_VALIDATOR})
    add_custom_command(COMMENT "Compiling cube fragment shader"
                    OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/cube.frag.spv
                    COMMAND ${GLSLANG_VALIDATOR} --target-env vulkan1.2 -o ${CMAKE_CURRENT_SOURCE_DIR}/cube.frag.spv
                        ${CMAKE_CURRENT_SOURCE_DIR}/cube.frag
                    MAIN_DEPENDENCY cube.frag
                    DEPENDS cube.frag ${GLSLANG_VALIDATOR})
endif()

if(VKSC_PIPELINE_CACHE_COMPILER)
    separate_arguments(VKSC_PIPELINE_CACHE_FLAGS NATIVE_COMMAND "${VKSC_PIPELINE_CACHE_FLAGS}")
    add_custom_command(COMMENT "Compiling pipeline cache binary header"
                    OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/pipeline_cache.h
                    BYPRODUCTS
                        cube.pc.json.log
                        ${CMAKE_CURRENT_BINARY_DIR}/pipeline_cache.h.bin
                    COMMAND ${VKSC_PIPELINE_CACHE_COMPILER} --path ${CMAKE_CURRENT_SOURCE_DIR}
                        --out ${CMAKE_CURRENT_BINARY_DIR}/pipeline_cache.h.bin
                        --log ${CMAKE_CURRENT_BINARY_DIR}/cube.pc.json.log
                        ${VKSC_PIPELINE_CACHE_FLAGS}
                    COMMAND ${CMAKE_COMMAND} -D INPUT:FILEPATH=${CMAKE_CURRENT_BINARY_DIR}/pipeline_cache.h.bin
                        -D OUTPUT:FILEPATH=${CMAKE_CURRENT_SOURCE_DIR}/pipeline_cache.h
                        -P ${CMAKE_CURRENT_SOURCE_DIR}/bin_to_c_hex_array.cmake
                    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                    MAIN_DEPENDENCY cube.pc.json
                    DEPENDS
                        cube.pc.json
                        ${CMAKE_CURRENT_SOURCE_DIR}/cube.vert.spv
                        ${CMAKE_CURRENT_SOURCE_DIR}/cube.frag.spv
                        ${VKSC_PIPELINE_CACHE_COMPILER}
                        ${CMAKE_CURRENT_SOURCE_DIR}/bin_to_c_hex_array.cmake)
endif()
add_custom_command(COMMENT "Compiling pipeline cache UUID header"
                OUTPUT pipeline_offline_info.h
                COMMAND ${CMAKE_COMMAND} -D INPUT:FILEPATH=${CMAKE_CURRENT_SOURCE_DIR}/cube.pc.json
                    -D OUTPUT:FILEPATH=${CMAKE_CURRENT_BINARY_DIR}/pipeline_offline_info.h
                    -P ${CMAKE_CURRENT_SOURCE_DIR}/uuid_from_json.cmake
                WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                MAIN_DEPENDENCY cube.pc.json
                DEPENDS
                    cube.pc.json
                    ${CMAKE_CURRENT_SOURCE_DIR}/uuid_from_json.cmake)

if(WIN32)
    add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
    # vksccube make use of M_PI and various other math defines.
    add_compile_definitions(_USE_MATH_DEFINES)
endif()


# On Ubuntu 20.04, it was found that the validation layers fail to launch in vksccube due to
# a missing dependency on libpthread. While newer Ubuntu versions use a glibc version where libpthread
# is integrated into libc, older ubuntu's do not so we need to link threads directly in order for
# validation layers to be loadable.
if (CMAKE_SYSTEM_NAME MATCHES "Linux|BSD|GNU")
    find_package(Threads REQUIRED)
endif()

# ----------------------------------------------------------------------------
# vkcube

add_executable(vkcube)
target_sources(vkcube PRIVATE
    cube.c
    cube.vert
    cube.frag
    cube.pc.json
    pipeline_cache.h
    ${CMAKE_CURRENT_BINARY_DIR}/pipeline_offline_info.h
)

if(CMAKE_SYSTEM_NAME MATCHES "Linux|BSD|GNU")
    target_link_libraries(vkcube PRIVATE Threads::Threads)
    include(CheckLibraryExists)
    CHECK_LIBRARY_EXISTS("rt" clock_gettime "" NEED_RT)
    if (NEED_RT)
        target_link_libraries(vkcube PRIVATE rt)
    endif()
elseif(WIN32)
else()
    message(FATAL_ERROR "Unsupported Platform!")
endif()

# We have to manually search for VulkanSC library, due to currently lacking a `Vulkan::Vulkan` equivalent target in Vulkan SC.
if(WIN32)
  set(_VulkanSC_library_name vulkansc-1)
else()
  set(_VulkanSC_library_name vulkansc)
endif()
find_library(VulkanSC_LIBRARY
  NAMES ${_VulkanSC_library_name}
)
mark_as_advanced(VulkanSC_LIBRARY)

target_compile_definitions(vkcube PRIVATE ${ENABLED_CUBE_PLATFORMS})
target_include_directories(vkcube PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR} # xyz_loader.h, linmath.h, etc.
    ${CMAKE_CURRENT_BINARY_DIR} # pipeline_offline_info.h
)
target_link_libraries(vkcube PRIVATE Vulkan::Headers "${VulkanSC_LIBRARY}")
set_target_properties(vkcube PROPERTIES OUTPUT_NAME vksccube)

install(TARGETS vkcube)