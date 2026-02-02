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
option(REBUILD_PIPELINE_CACHE "Rebuild pipeline cache" OFF)
set(VKSC_PIPELINE_CACHE_FLAGS "" CACHE STRING "Additional flags to pass to the pipeline cache compiler")

if(NOT REBUILD_PIPELINE_CACHE)
    message(STATUS "Using self-hosted Vulkan SC Emulation ICD pipeline cache. "
                   "Use REBUILD_PIPELINE_CACHE to rebuild pipeline cache with the Pipeline Cache Compiler discovered by the VulkanSC SDK.")
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

    function(add_glsl_shader INPUT OUTPUT)
        file(RELATIVE_PATH SPV_PATH "${CMAKE_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}/${OUTPUT}")
        file(TO_NATIVE_PATH "${SPV_PATH}" SPV_PATH)
        add_custom_command(COMMENT "Compiling GLSL shader ${SPV_PATH}"
                        OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/${OUTPUT}
                        COMMAND ${GLSLANG_VALIDATOR} --target-env vulkan1.2 -o ${CMAKE_CURRENT_SOURCE_DIR}/${OUTPUT} --quiet
                            ${CMAKE_CURRENT_SOURCE_DIR}/${INPUT}
                        MAIN_DEPENDENCY ${INPUT}
                        DEPENDS ${INPUT} ${GLSLANG_VALIDATOR})
    endfunction()

    add_glsl_shader(cube.vert cube.vert.spv)
    add_glsl_shader(cube.frag cube.frag.spv)
endif()

if(REBUILD_PIPELINE_CACHE)
    find_package(VulkanSC CONFIG REQUIRED)
    include(VulkanSCPccUtilities)

    set(PIPELINE_CACHE_BIN "${CMAKE_CURRENT_BINARY_DIR}/pipeline_cache.$<CONFIG>.bin")
    set(PIPELINE_CACHE_HEADER "${CMAKE_CURRENT_SOURCE_DIR}/pipeline_cache.h")

    if(COMPILE_CUBE_SHADERS)
        # NOTE: Intra-target custom_command inter-dependencies for invocation ordering via dyndep files isn't resolved.
        #       If pipeline cache compilation has inputs which are outputs of custom commands and have no target of their
        #       for pipeline_cache to DEPEND on, these generated inputs need to be explicit.
        set(DEPENDS_ARG DEPENDS
            "${CMAKE_CURRENT_SOURCE_DIR}/cube.vert.spv"
            "${CMAKE_CURRENT_SOURCE_DIR}/cube.frag.spv"
        )
    endif()

    add_vksc_pipeline_cache(pipeline_cache
        PATH "${CMAKE_CURRENT_SOURCE_DIR}"
        OUT "${PIPELINE_CACHE_BIN}"
        $<$<CONFIG:Debug,RelWithDebInfo>:DEBUG>
        FLAGS "${VKSC_PIPELINE_CACHE_FLAGS}"
        ${DEPENDS_ARG}
    )

    file(RELATIVE_PATH HDR_PATH "${CMAKE_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}/pipeline_cache.h")
    if(WIN32)
        string(REPLACE "/" "\\" HDR_PATH "${HDR_PATH}")
    endif()
    add_custom_command(COMMENT "Generating PC header ${HDR_PATH}"
                    OUTPUT "${PIPELINE_CACHE_HEADER}"
                    COMMAND "${CMAKE_COMMAND}"
                        -D "INPUT:FILEPATH=${PIPELINE_CACHE_BIN}"
                        -D "OUTPUT:FILEPATH=${PIPELINE_CACHE_HEADER}"
                        -P "${CMAKE_CURRENT_SOURCE_DIR}/bin_to_c_hex_array.cmake"
                    MAIN_DEPENDENCY cube.pc.json
                    DEPENDS
                        "${PIPELINE_CACHE_BIN}"
                        "${CMAKE_CURRENT_SOURCE_DIR}/bin_to_c_hex_array.cmake")
endif()

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
    pipeline_cache.h
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
target_compile_definitions(vkcube PRIVATE ${ENABLED_CUBE_PLATFORMS})
target_include_directories(vkcube PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}") # xyz_loader.h, linmath.h, etc.
set_target_properties(vkcube PROPERTIES OUTPUT_NAME vksccube)

if(NOT REBUILD_PIPELINE_CACHE)
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

    target_link_libraries(vkcube PRIVATE Vulkan::Headers "${VulkanSC_LIBRARY}")
else()
    target_link_libraries(vkcube PRIVATE VulkanSC::VulkanSC)
endif()

install(TARGETS vkcube)