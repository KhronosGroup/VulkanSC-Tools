# ~~~
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

# This variable enables downstream users to customize the CMake targets
# based on the target API variant (e.g. Vulkan SC)
set(LAYER_NAME "VkLayer_khronos_device_simulation")

if(VULKANSC)
    set(LAYER_NAME "VkSCLayer_khronos_device_simulation")
endif()
if(${CMAKE_C_COMPILER_ID} MATCHES "(GNU|Clang)")
    add_compile_options(-Werror -Wno-unused-function -Wno-unused-but-set-variable -Wno-type-limits)
elseif(MSVC)
    # PDBs aren't generated on Release builds by default.
    add_compile_options("$<$<CONFIG:Release>:/Zi>")
    add_link_options("$<$<CONFIG:Release>:/DEBUG:FULL>")
    # Remove unreferenced code/data.
    add_link_options("$<$<CONFIG:Release>:/OPT:REF>")
    # Merge duplicate data/functions
    add_link_options("$<$<CONFIG:Release>:/OPT:ICF>")

    # Ignore some warnings that trigger due to inheriting source files with less strict warning requirements
    #    warning C4305: 'initializing': truncation from 'unsigned __int64' to 'size_t'
    #    warning C4309: 'initializing': truncation of constant value
    set_source_files_properties(profiles_generated.cpp PROPERTIES COMPILE_OPTIONS "/wd4305;/wd4309")
endif()

find_package(valijson REQUIRED CONFIG)
find_package(jsoncpp REQUIRED CONFIG)

target_include_directories(Vulkan::Headers INTERFACE ${VULKAN_UTILITY_LIBRARIES_INSTALL_DIR}/include/vulkan)

if(WIN32)
    # We need -DNOMINMAX for valijson build
    add_definitions(-DVK_USE_PLATFORM_WIN32_KHR -DVK_USE_PLATFORM_WIN32_KHX -DNOMINMAX)
    set(DisplayServer Win32)
elseif(ANDROID)
    add_definitions(-DVK_USE_PLATFORM_ANDROID_KHR)
elseif(APPLE)
    add_compile_definitions(VK_USE_PLATFORM_METAL_EXT)
    if (IOS)
        add_compile_definitions(VK_USE_PLATFORM_IOS_MVK)
    endif()
    if (CMAKE_SYSTEM_NAME STREQUAL "Darwin")
        add_compile_definitions(VK_USE_PLATFORM_MACOS_MVK)
    endif()
elseif(CMAKE_SYSTEM_NAME MATCHES "Linux|BSD|QNX")
    if (BUILD_WSI_XCB_SUPPORT)
        add_definitions(-DVK_USE_PLATFORM_XCB_KHR -DVK_USE_PLATFORM_XCB_KHX)
        set(DisplayServer Xcb)
    endif()

    if (BUILD_WSI_XLIB_SUPPORT)
        if (NOT DisplayServer)
            set(DisplayServer Xlib)
        endif()
        add_definitions(-DVK_USE_PLATFORM_XLIB_KHR -DVK_USE_PLATFORM_XLIB_KHX)
    endif()

    if (BUILD_WSI_WAYLAND_SUPPORT)
       # TODO Add Wayland Support
       # add_definitions(-DVK_USE_PLATFORM_WAYLAND_KHR)
    endif()
else()
    message(FATAL_ERROR "Unsupported Platform!")
endif()

option(BUILD_WSI_SCI_SUPPORT "Build with SCI platform headers" OFF)
if (BUILD_WSI_SCI_SUPPORT)
    target_compile_definitions(Vulkan::Headers INTERFACE VK_USE_PLATFORM_SCI)
endif()

add_definitions(-DVK_ENABLE_BETA_EXTENSIONS)

if(MSVC)
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_CRT_SECURE_NO_WARNINGS /bigobj")
    set (CMAKE_C_FLAGS   "${CMAKE_C_FLAGS} -D_CRT_SECURE_NO_WARNINGS /bigobj")
else()
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wpointer-arith")
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wpointer-arith")
endif()

add_definitions(-DVK_ENABLE_BETA_EXTENSIONS)

source_group("JSON Manifest" FILES ${LAYER_NAME}.json.in)
source_group("Export Files" FILES ${LAYER_NAME}.def ${LAYER_NAME}.map)

add_library(DevSimLayer MODULE)
set_target_properties(DevSimLayer PROPERTIES FOLDER "Vulkan SC device simulation layer")
set_target_properties(DevSimLayer PROPERTIES OUTPUT_NAME ${LAYER_NAME})

if (MSVC)
    target_compile_options(DevSimLayer PRIVATE "$<$<CONFIG:Release>:/Zi>")
    target_link_options(DevSimLayer PRIVATE /DEF:${CMAKE_CURRENT_SOURCE_DIR}/${LAYER_NAME}.def)
    target_link_options(DevSimLayer PRIVATE "$<$<CONFIG:Release>:/DEBUG:FULL>")
    target_link_options(DevSimLayer PRIVATE "$<$<CONFIG:Release>:/OPT:REF>")
    target_link_options(DevSimLayer PRIVATE "$<$<CONFIG:Release>:/OPT:ICF>")
elseif(MINGW)
    target_sources(DevSimLayer PRIVATE ${LAYER_NAME}.def)
elseif(APPLE)
    message(DEBUG "Functions are exported via PROFILES_EXPORT")
    set_target_properties(DevSimLayer PROPERTIES SUFFIX ".dylib")
elseif(ANDROID)
    message(DEBUG "Functions are exported via PROFILES_EXPORT")
else()
    target_link_options(DevSimLayer PRIVATE LINKER:--version-script=${CMAKE_CURRENT_SOURCE_DIR}/${LAYER_NAME}.map,-Bsymbolic,--exclude-libs,ALL)
endif()

target_sources(DevSimLayer PRIVATE
    profiles_interface.cpp
    profiles_interface.h
    profiles_settings.cpp
    profiles_settings.h
    profiles_json.cpp
    profiles_json.h
    profiles_util.cpp
    profiles_util.h
    profiles_interface.cpp
    profiles_interface.h
    profiles_generated.cpp
    profiles.h
    vk_layer_table.cpp
    vk_layer_table.h
    ${LAYER_NAME}.json.in
    ${LAYER_NAME}.def
    ${LAYER_NAME}.map
)

target_link_libraries(DevSimLayer PRIVATE
    Vulkan::LayerSettings
    Vulkan::Headers
    Vulkan::UtilityHeaders
    jsoncpp_static
    valijson
)

if(ANDROID)
    # Android needs -llog for __android_print_log()
    target_link_Libraries(DevSimLayer PRIVATE log)
endif()

set(INPUT_FILE "${CMAKE_CURRENT_SOURCE_DIR}/${LAYER_NAME}.json.in")
set(INTERMEDIATE_FILE "${CMAKE_CURRENT_BINARY_DIR}/json/profile.json")
set(OUTPUT_FILE_FINAL_NAME "${LAYER_NAME}.json")
set(LAYER_INSTALL_DIR ${CMAKE_INSTALL_LIBDIR})
if (WIN32)
    set(LAYER_INSTALL_DIR ${CMAKE_INSTALL_BINDIR}) # WIN32/MINGW expect the dll in the `bin` dir, this matches our WIN32 SDK process
endif()

if (WIN32)
    set(JSON_LIBRARY_PATH ".\\\\${LAYER_NAME}.dll")
elseif(APPLE)
    set(JSON_LIBRARY_PATH "./lib${LAYER_NAME}.dylib")
else()
    set(JSON_LIBRARY_PATH "./lib${LAYER_NAME}.so")
endif()

set(JSON_API_VERSION ${VulkanHeaders_VERSION})

configure_file(${INPUT_FILE} ${INTERMEDIATE_FILE} @ONLY)

# To support both multi/single configuration generators just copy the json to the correct directory
add_custom_command(TARGET DevSimLayer POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${INTERMEDIATE_FILE} $<TARGET_FILE_DIR:DevSimLayer>/${OUTPUT_FILE_FINAL_NAME}
)

# For UNIX-based systems, `library_path` should not contain a relative path (indicated by "./") before installing to system directories
# This json isn't used for regular local development, it's used for installation
if (UNIX)
    set(UNIX_INTERMEDIATE_FILE "${CMAKE_CURRENT_BINARY_DIR}/json/unix_install_profile.json")

    if(APPLE)
        set(JSON_LIBRARY_PATH "lib${LAYER_NAME}.dylib")
    else()
        set(JSON_LIBRARY_PATH "lib${LAYER_NAME}.so")
    endif()

    configure_file(${INPUT_FILE} ${UNIX_INTERMEDIATE_FILE} @ONLY)

    install(FILES ${UNIX_INTERMEDIATE_FILE} DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/${API_TYPE}/explicit_layer.d RENAME ${OUTPUT_FILE_FINAL_NAME})
endif()

if (WIN32)
    install(FILES ${INTERMEDIATE_FILE} DESTINATION ${LAYER_INSTALL_DIR} RENAME ${OUTPUT_FILE_FINAL_NAME})
endif()
if (MSVC)
    install(FILES $<TARGET_PDB_FILE:DevSimLayer> DESTINATION ${LAYER_INSTALL_DIR})
endif()

install(TARGETS DevSimLayer DESTINATION ${LAYER_INSTALL_DIR})
