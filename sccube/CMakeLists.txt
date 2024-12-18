# ~~~
# Copyright (C) 2024 The Khronos Group Inc.
# Copyright (C) 2024 RasterGrid Kft.
#
# SPDX-License-Identifier: Apache-2.0
#
# Author: Máté Ferenc Nagy-Egri <mate@rastergrid.com>
# ~~~

if(CMAKE_SYSTEM_NAME MATCHES "Linux|BSD|GNU|QNX")
    set(VKSC_SYSTEM_LINUX_LIKE ON)
else()
    set(VKSC_SYSTEM_LINUX_LIKE OFF)
endif()

if(NOT (VKSC_SYSTEM_LINUX_LIKE OR WIN32))
    message(FATAL_ERROR "Unsupported Platform!")
endif()

include(CMakeDependentOption)

option(COMPILE_CUBE_SHADERS "Compile GLSL shaders to SPIR-V" OFF)
option(BUILD_IMAGE_DUMP_SUPPORT "Build Image dump support" ON)
option(BUILD_WSI_DISPLAY_SUPPORT "Build DISPLAY WSI support" ON)
cmake_dependent_option(BUILD_WSI_XCB_SUPPORT "Build XCB WSI support" ON "VKSC_SYSTEM_LINUX_LIKE" OFF)
cmake_dependent_option(BUILD_WSI_XLIB_SUPPORT "Build Xlib WSI support" ON "VKSC_SYSTEM_LINUX_LIKE" OFF)
cmake_dependent_option(BUILD_WSI_WAYLAND_SUPPORT "Build Wayland WSI support" ON "VKSC_SYSTEM_LINUX_LIKE" OFF)
cmake_dependent_option(BUILD_WSI_DIRECTFB_SUPPORT "Build DirectFB WSI support" OFF "VKSC_SYSTEM_LINUX_LIKE" OFF)
cmake_dependent_option(BUILD_WSI_WIN32_SUPPORT "Build Win32 WSI support" ON "WIN32" OFF)

# Collect enabled back-ends
if(BUILD_IMAGE_DUMP_SUPPORT)
    list(APPEND ENABLED_CUBE_PLATFORMS CUBE_USE_IMAGE_DUMP)
endif()
if(BUILD_WSI_DISPLAY_SUPPORT)
    list(APPEND ENABLED_CUBE_PLATFORMS VK_USE_PLATFORM_DISPLAY_KHR)
endif()
if(BUILD_WSI_WIN32_SUPPORT)
    list(APPEND ENABLED_CUBE_PLATFORMS VK_USE_PLATFORM_WIN32_KHR)
endif()
if(BUILD_WSI_XCB_SUPPORT)
    list(APPEND ENABLED_CUBE_PLATFORMS VK_USE_PLATFORM_XCB_KHR)
endif()
if(BUILD_WSI_XLIB_SUPPORT)
    list(APPEND ENABLED_CUBE_PLATFORMS VK_USE_PLATFORM_XLIB_KHR)
endif()
if(BUILD_WSI_WAYLAND_SUPPORT)
    list(APPEND ENABLED_CUBE_PLATFORMS VK_USE_PLATFORM_WAYLAND_KHR)
endif()
if(BUILD_WSI_DIRECTFB_SUPPORT)
    list(APPEND ENABLED_CUBE_PLATFORMS VK_USE_PLATFORM_DIRECTFB_EXT)
endif()

if(NOT DEFINED ENABLED_CUBE_PLATFORMS)
    message(FATAL_ERROR "No WSI platforms enabled. vksccube requires at least one WSI platform to render its output.")
endif()

# ----------------------------------------------------------------------------
# dependencies

find_program(PCC_PROGRAM NAMES pcc pcconvk REQUIRED)

# On Ubuntu 20.04, it was found that the validation layers fail to launch in vksccube due to
# a missing dependency on libpthread. While newer Ubuntu versions use a glibc version where libpthread
# is integrated into libc, older ubuntu's do not so we need to link threads directly in order for
# validation layers to be loadable.
find_package(Threads REQUIRED)

if(VKSC_SYSTEM_LINUX_LIKE)
    find_package(PkgConfig REQUIRED) # Use PkgConfig to find Linux system libraries
    include(CheckLibraryExists) # Use CheckLibraryExists to find Linux system libraries

    check_library_exists(rt clock_gettime "" NEED_RT)
    check_library_exists(m sin "" NEED_M)
endif()

if(COMPILE_CUBE_SHADERS)
    find_program(GLSLANG_VALIDATOR
        NAMES glslang glslangValidator
        HINTS $ENV{GLSLANG_INSTALL_DIR} $ENV{VULKAN_SDK}/bin $ENV{VULKAN_SDK}/Bin
    )
endif()

if(BUILD_IMAGE_DUMP_SUPPORT)
    find_path(STB_INCLUDE_DIR stb_image_write.h REQUIRED
        PATH_SUFFIXES include)
endif()
if(BUILD_WSI_XCB_SUPPORT)
    pkg_check_modules(XCB REQUIRED IMPORTED_TARGET xcb)
endif()
if(BUILD_WSI_XLIB_SUPPORT)
    pkg_check_modules(X11 REQUIRED IMPORTED_TARGET x11)
endif()
if(BUILD_WSI_WAYLAND_SUPPORT)
    pkg_check_modules(WAYLAND_CLIENT REQUIRED IMPORTED_TARGET wayland-client)
endif()
if(BUILD_WSI_DIRECTFB_SUPPORT)
    pkg_check_modules(DirectFB REQUIRED IMPORTED_TARGET directfb)
endif()

# ----------------------------------------------------------------------------
# vksccube

if(VKSC_SYSTEM_LINUX_LIKE)
    add_executable(vksccube)
elseif(WIN32)
    add_executable(vksccube WIN32)
endif()

# Source generation
if(BUILD_WSI_WAYLAND_SUPPORT)
    pkg_get_variable(WAYLAND_INCLUDE_DIRS wayland-client includedir)
    pkg_get_variable(WAYLAND_SCANNER_EXECUTABLE wayland-scanner wayland_scanner)
    pkg_get_variable(WAYLAND_CLIENT_PATH wayland-client pkgdatadir)
    pkg_get_variable(WAYLAND_PROTOCOLS_PATH wayland-protocols pkgdatadir)
    set(WAYLAND_CODE_PROTOCOL ${WAYLAND_CLIENT_PATH}/wayland.xml)
    set(XDG_SHELL_PROTOCOL ${WAYLAND_PROTOCOLS_PATH}/stable/xdg-shell/xdg-shell.xml)
    set(XDG_DECORATION_PROTOCOL ${WAYLAND_PROTOCOLS_PATH}/unstable/xdg-decoration/xdg-decoration-unstable-v1.xml)

    add_custom_command(COMMENT "Generating wayland client protocol dispatch data"
                      OUTPUT wayland-client.c
                      COMMAND ${WAYLAND_SCANNER_EXECUTABLE}
                              private-code
                              ${WAYLAND_CODE_PROTOCOL}
                              ${CMAKE_CURRENT_BINARY_DIR}/wayland-client.c
                      MAIN_DEPENDENCY ${WAYLAND_CODE_PROTOCOL}
                      DEPENDS ${WAYLAND_CODE_PROTOCOL} ${WAYLAND_SCANNER_EXECUTABLE})

    add_custom_command(COMMENT "Generating xdg-shell protocol dispatch data"
                       OUTPUT xdg-shell-code.c
                       COMMAND ${WAYLAND_SCANNER_EXECUTABLE}
                               private-code
                               ${XDG_SHELL_PROTOCOL}
                               ${CMAKE_CURRENT_BINARY_DIR}/xdg-shell-code.c
                       MAIN_DEPENDENCY ${XDG_SHELL_PROTOCOL}
                       DEPENDS ${XDG_SHELL_PROTOCOL} ${WAYLAND_SCANNER_EXECUTABLE})
    add_custom_command(COMMENT "Generating xdg-shell protocol header"
                       OUTPUT xdg-shell-client-header.h
                       COMMAND ${WAYLAND_SCANNER_EXECUTABLE}
                               client-header
                               ${XDG_SHELL_PROTOCOL}
                               ${CMAKE_CURRENT_BINARY_DIR}/xdg-shell-client-header.h
                       MAIN_DEPENDENCY ${XDG_SHELL_PROTOCOL}
                       DEPENDS ${XDG_SHELL_PROTOCOL} ${WAYLAND_SCANNER_EXECUTABLE})
    add_custom_command(COMMENT "Generating xdg-decoration protocol dispatch data"
                       OUTPUT xdg-decoration-code.c
                       COMMAND ${WAYLAND_SCANNER_EXECUTABLE}
                               private-code
                               ${XDG_DECORATION_PROTOCOL}
                               ${CMAKE_CURRENT_BINARY_DIR}/xdg-decoration-code.c
                       MAIN_DEPENDENCY ${XDG_DECORATION_PROTOCOL}
                       DEPENDS ${XDG_DECORATION_PROTOCOL} ${WAYLAND_SCANNER_EXECUTABLE})
    add_custom_command(COMMENT "Generating xdg-decoration protocol header"
                       OUTPUT xdg-decoration-client-header.h
                       COMMAND ${WAYLAND_SCANNER_EXECUTABLE}
                               client-header
                               ${XDG_DECORATION_PROTOCOL}
                               ${CMAKE_CURRENT_BINARY_DIR}/xdg-decoration-client-header.h
                       MAIN_DEPENDENCY ${XDG_DECORATION_PROTOCOL}
                       DEPENDS ${XDG_DECORATION_PROTOCOL} ${WAYLAND_SCANNER_EXECUTABLE})
    set(WAYLAND_GENERATED_SOURCES
        ${CMAKE_CURRENT_BINARY_DIR}/wayland-client.c
        ${CMAKE_CURRENT_BINARY_DIR}/xdg-shell-code.c
        ${CMAKE_CURRENT_BINARY_DIR}/xdg-shell-client-header.h
        ${CMAKE_CURRENT_BINARY_DIR}/xdg-decoration-code.c
        ${CMAKE_CURRENT_BINARY_DIR}/xdg-decoration-client-header.h
    )
endif()

if(COMPILE_CUBE_SHADERS)
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

add_custom_command(COMMENT "Compiling pipeline cache binary header"
                OUTPUT pipeline_cache.h
                BYPRODUCTS cube.pc.json.log
                COMMAND ${PCC_PROGRAM} --path ${CMAKE_CURRENT_SOURCE_DIR}
                    --out ${CMAKE_CURRENT_BINARY_DIR}/pipeline_cache.h --hex
                    --log ${CMAKE_CURRENT_BINARY_DIR}/cube.pc.json.log
                WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                MAIN_DEPENDENCY cube.pc.json
                DEPENDS
                    cube.pc.json
                    ${CMAKE_CURRENT_SOURCE_DIR}/cube.vert.spv
                    ${CMAKE_CURRENT_SOURCE_DIR}/cube.frag.spv
                    ${PCC_PROGRAM})
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

# Target properties
target_sources(vksccube PRIVATE
    cube.c
    cube.vert
    cube.frag
    cube.pc.json
    ${CMAKE_CURRENT_BINARY_DIR}/pipeline_cache.h
    ${CMAKE_CURRENT_BINARY_DIR}/pipeline_offline_info.h
    $<$<BOOL:${BUILD_WSI_XCB_SUPPORT}>:../cube/xcb_loader.h>
    $<$<BOOL:${BUILD_WSI_XLIB_SUPPORT}>:../cube/xlib_loader.h>
    $<$<BOOL:${BUILD_WSI_WAYLAND_SUPPORT}>:../cube/wayland_loader.h ${WAYLAND_GENERATED_SOURCES}>
)
target_compile_definitions(vksccube PRIVATE
    ${ENABLED_CUBE_PLATFORMS}
    $<$<PLATFORM_ID:Windows>:WIN32_LEAN_AND_MEAN NOMINMAX _CRT_SECURE_NO_WARNINGS _USE_MATH_DEFINES>
    $<$<BOOL:${BUILD_WSI_XCB_SUPPORT}>:XCB_LIBRARY=${XCB_LINK_LIBRARIES}>
    $<$<BOOL:${BUILD_WSI_XLIB_SUPPORT}>:XCB_LIBRARY=${X11_LINK_LIBRARIES}>
    $<$<BOOL:${BUILD_WSI_WAYLAND_SUPPORT}>:XCB_LIBRARY=${WAYLAND_CLIENT_LINK_LIBRARIES}>
)
target_include_directories(vksccube PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../cube # xyz_loader.h, linmath.h, etc.
    ${CMAKE_CURRENT_BINARY_DIR}         # pipeline_cache.h pipeline_offline_info.h
    $<$<BOOL:${BUILD_IMAGE_DUMP_SUPPORT}>:${STB_INCLUDE_DIR}>
    $<$<BOOL:${BUILD_WSI_WAYLAND_SUPPORT}>:${CMAKE_CURRENT_BINARY_DIR}>
)
target_link_libraries(vksccube PRIVATE
    Vulkan::Headers
    Vulkan::Loader
    Threads::Threads
    $<$<BOOL:${BUILD_WSI_XCB_SUPPORT}>:PkgConfig::xcb>
    $<$<BOOL:${BUILD_WSI_XLIB_SUPPORT}>:PkgConfig::x11>
    $<$<BOOL:${BUILD_WSI_WAYLAND_SUPPORT}>:PkgConfig::wayland-client>
    $<$<BOOL:${BUILD_WSI_DIRECTFB_SUPPORT}>:PkgConfig::DirectFB>
    $<$<BOOL:${NEED_RT}>:rt>
    $<$<BOOL:${NEED_M}>:m>
)

install(TARGETS vksccube)
