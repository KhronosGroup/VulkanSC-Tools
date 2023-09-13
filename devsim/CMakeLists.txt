# ~~~
# Copyright (c) 2023 RasterGrid Kft.
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

set(LAYER_NAME "VkSCLayer_khronos_device_simulation")
add_definitions(-DVULKANSC)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_CXX_VISIBILITY_PRESET "hidden")
set(CMAKE_C_VISIBILITY_PRESET "hidden")
set(CMAKE_VISIBILITY_INLINES_HIDDEN "YES")

# Platform-specific compiler switches
if(${CMAKE_C_COMPILER_ID} STREQUAL "Clang")
    add_compile_options(-Werror -Wno-unused-function -Wno-unused-but-set-variable -Wno-type-limits)
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

    add_compile_options(/W4 /WX)
    add_link_options(/WX)
    # Ignore some warnings that we know we'll generate.  In the future the
    # code that generates these warnings should be fixed properly.
    # vk_layer_logging.h provokes:
    #    warning C4100: 'default_flag_is_spec': unreferenced formal parameter
    # vk_loader_platform.h provokes:
    #    warning C4505: unreferenced local function has been removed
    # jsoncpp.cpp provokes:
    #    warning C4702: unreachable code
    # gtest.h provokes:
    #    warning C4389: '==': signed/unsigned mismatch
    #    warning C4018: '>=': signed/unsigned mismatch
    # vulkan_profiles.hpp provokes:
    #    warning C4245: '=': conversion from 'int' to 'uint64_t', signed/unsigned mismatch
    #    warning C4305: '=': truncation from 'double' to 'float'
    add_compile_options(/wd4100 /wd4505 /wd4702 /wd4389 /wd4245 /wd4305 /wd4018)
endif()


find_package(VulkanHeaders REQUIRED CONFIG QUIET)
find_package(valijson REQUIRED CONFIG)
find_package(jsoncpp REQUIRED CONFIG)

target_include_directories(Vulkan::Headers INTERFACE ${VULKAN_VALIDATIONLAYERS_INSTALL_DIR}/include/vulkan)

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    add_definitions(-DVK_USE_PLATFORM_WIN32_KHR -DVK_USE_PLATFORM_WIN32_KHX -DWIN32_LEAN_AND_MEAN -DNOMINMAX)
    set(DisplayServer Win32)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Android")
    add_definitions(-DVK_USE_PLATFORM_ANDROID_KHR)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Linux" OR CMAKE_SYSTEM_NAME MATCHES "BSD")
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
elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    if (BUILD_MOLTENVK_SUPPORT)
        add_definitions(-DVK_USE_PLATFORM_MACOS_MVK)
    endif()

    if (BUILD_METAL_SUPPORT)
       # TODO Add Metal Support
       add_definitions(-DVK_USE_PLATFORM_METAL_EXT)
    endif()
else()
    message(FATAL_ERROR "Unsupported Platform!")
endif()

if (BUILD_WSI_SCI_SUPPORT)
    target_compile_definitions(Vulkan::Headers INTERFACE VK_USE_PLATFORM_SCI)
endif()

add_definitions(-DVK_ENABLE_BETA_EXTENSIONS)

if (WIN32)
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_CRT_SECURE_NO_WARNINGS /bigobj")
    set (CMAKE_C_FLAGS   "${CMAKE_C_FLAGS} -D_CRT_SECURE_NO_WARNINGS /bigobj")
else()
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wpointer-arith")
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wpointer-arith")
endif()

source_group("JSON Manifest" FILES ${LAYER_NAME}.json.in)
source_group("Export Files" FILES ${LAYER_NAME}.def ${LAYER_NAME}.map)

add_library(DevSimLayer MODULE)
set_target_properties(DevSimLayer PROPERTIES FOLDER "Vulkan SC device simulation layer")
set_target_properties(DevSimLayer PROPERTIES OUTPUT_NAME ${LAYER_NAME})

if (MSVC)
    target_link_options(DevSimLayer PRIVATE /DEF:${CMAKE_CURRENT_SOURCE_DIR}/${LAYER_NAME}.def)
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
    profiles_generated.cpp
    profiles.h
    vk_layer_table.cpp
    ${LAYER_NAME}.json.in
    ${LAYER_NAME}.def
    ${LAYER_NAME}.map
)

target_link_libraries(DevSimLayer PRIVATE
    Vulkan::Headers
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
