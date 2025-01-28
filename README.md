# KhronosGroup/VulkanSC-Tools

This project provides Vulkan SC tools and utilities that can assist development by enabling developers to verify their applications correct use of the Vulkan SC API.

> **IMPORTANT NOTE:** This repository is to be used with the [Vulkan SC](https://www.khronos.org/vulkansc/) API and should not be confused with the similar repository that exists for the Vulkan API (see https://github.com/KhronosGroup/Vulkan-Tools). While it is possible to build the Vulkan version from this repository, this repository contains a forked version of the upstream code and may not be up-to-date with the latest changes in the upstream repository.

## Intro

The following components are available in this repository:

- [*Mock ICD*](icd/)
- [*Vulkan SC Cube Demo*](cube-vksc/)
- [*Vulkan SC Info*](vulkaninfo/)

In addition, the following Vulkan SC specific components are available in this repository:

- [*Vulkan SC Device Simulation Layer*](devsim/)

## Information for Developing or Contributing:

Please see the [CONTRIBUTING.md](CONTRIBUTING.md) file in this repository for more details.
Please see the [GOVERNANCE.md](GOVERNANCE.md) file in this repository for repository management details.

## How to Build and Run

[BUILD.md](BUILD.md) includes directions for building all components as well as running the vkcube demo applications.

## Version Tagging Scheme

Updates to this repository which correspond to a new Vulkan specification release are tagged using the following format: `v<`_`version`_`>` (e.g., `v1.3.266`).

**Note**: Marked version releases have undergone thorough testing but do not imply the same quality level as SDK tags. SDK tags follow the `vulkan-sdk-<`_`version`_`>.<`_`patch`_`>` format (e.g., `vulkan-sdk-1.3.266.0`).

This scheme was adopted following the `1.3.266` Vulkan specification release.


For Vulkan SC, updates to a new API version will be tagged using the following format `vksc<`_`version`_`>.<`_`patch`_`>` (e.g., `vksc1.0.12`).

## License
This work is released as open source under a Apache-style license from Khronos including a Khronos copyright.

See LICENSE.txt for a full list of licenses used in this repository.

## Acknowledgements
While this project has been developed primarily by LunarG, Inc., there are many other
companies and individuals making this possible: Valve Corporation, funding
project development; Google providing significant contributions to the validation layers;
Khronos providing oversight and hosting of the project.
