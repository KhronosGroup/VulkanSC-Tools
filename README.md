# Vulkan and Vulkan SC Ecosystem Components

This project provides Khronos official Vulkan SC Tools and Utilities for Windows, Linux, Android, and MacOS.

> **IMPORTANT NOTE:** This repository is to be used with the [Vulkan SC](https://www.khronos.org/vulkansc/) API and should not be confused with the similar repository that exists for the Vulkan API (see https://github.com/KhronosGroup/Vulkan-Tools). While it is possible to build the Vulkan version from this repository, this repository contains a forked version of the upstream code and may not be up-to-date with the latest changes in the upstream repository.

## CI Build Status
[![Build Status](https://github.com/KhronosGroup/VulkanSC-Tools/workflows/CI%20Build/badge.svg?branch=sc_main)](https://github.com/KhronosGroup/VulkanSC-Tools/actions)

## Introduction

This project provides Vulkan SC tools and utilities that can assist development by enabling developers to
verify their applications correct use of the Vulkan SC API.

The following components are available in this repository:
- [*Mock ICD*](icd/)
- [*Vkcube and Vkcube++ Demo*](cube/)
- [*VulkanInfo*](vulkaninfo/)
- [*Windows Runtime*](windows-runtime-installer/)

## Contact Information
* [Tobin Ehlis](mailto:tobine@google.com)
* [Mark Lobodzinski](mailto:mark@lunarg.com)

## Information for Developing or Contributing:

Please see the [CONTRIBUTING.md](CONTRIBUTING.md) file in this repository for more details.
Please see the [GOVERNANCE.md](GOVERNANCE.md) file in this repository for repository management details.

## How to Build and Run

[BUILD.md](BUILD.md)
Includes directions for building all components as well as running the vkcube demo applications.

## Version Tagging Scheme

Updates to the `VulkanSC-Tools` repository which correspond to a new Vulkan specification release are tagged using the following format: `v<`_`version`_`>` (e.g., `v1.1.96`).

**Note**: Marked version releases have undergone thorough testing but do not imply the same quality level as SDK tags. SDK tags follow the `sdk-<`_`version`_`>.<`_`patch`_`>` format (e.g., `sdk-1.1.92.0`).

This scheme was adopted following the 1.1.96 Vulkan specification release.


For Vulkan SC, updates to a new API version will be tagged using the following format `vksc<`_`version`_`>.<`_`patch`_`>` (e.g., `vksc1.0.12`).

## License
This work is released as open source under a Apache-style license from Khronos including a Khronos copyright.

See LICENSE.txt for a full list of licenses used in this repository.

## Acknowledgements
While this project has been developed primarily by LunarG, Inc., there are many other
companies and individuals making this possible: Valve Corporation, funding
project development; Google providing significant contributions to the validation layers;
Khronos providing oversight and hosting of the project.
