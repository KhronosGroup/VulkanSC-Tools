# Vulkan SC Device Simulation Layer

This directory contains the Vulkan SC Device Simulation Layer (`VK_LAYER_KHRONOS_device_simulation`) that is derived from the Vulkan Profiles Layer and is used for validation layer testing against different device capabilities.

## Building the Vulkan SC Device Simulation Layer

The Vulkan SC Device Simulation Layer is built when the `BUILD_VKSC_DEVSIM` build option is enabled (default for Vulkan SC builds) when building the VulkanSC-Tools.

## Using the Vulkan SC Device Simulation Layer

To enable the Vulkan SC Device Simulation Layer, enable the layer using any of the available options (environment variable, application opt-in, etc.) and set the `VKSC_DEVSIM_PROFILE_FILE` environment variable to point to your Vulkan SC device profile JSON file (see examples under the `tests/vulkansc/device_profiles` directory of the [VulkanSC-ValidationLayers](https://github.com/KhronosGroup/VulkanSC-ValidationLayers) repository).

## Beyond Validation Layer Testing

The focus of the Vulkan SC Device Simulation Layer is validation layer testing, but it is available to use for alternative testing purposes. However, being a testing tool, it is subject to backward-incompatible changes so it is not advised for users to rely on the layer in a production environment.
