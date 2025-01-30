# Vulkan SC Cube Demo

This directory contains the Vulkan SC Cube Demo sources and data files.

## System requirements

The default build of `vksccube` contains embedded pipeline cache binaries built for the
[Vulkan SC Emulation driver stack](https://github.com/KhronosGroup/VulkanSC-Emulation/).
If you intend to run it with another Vulkan SC implementation, please refer to the Vulkan SC documentation of your
vendor toolchain and the [next section](#custom-pipeline-cache-compiler) describing the use of custom pipeline cache
compilers.

In order to test with the Vulkan SC Emulation driver stack, please refer to its
[build instructions](https://github.com/KhronosGroup/VulkanSC-Emulation/blob/main/BUILD.md) and
[documentation](https://github.com/KhronosGroup/VulkanSC-Emulation/blob/main/icd/README.md).

The `vksccube` requires support for the `VK_KHR_display` extension for window-system interaction. The Vulkan SC
Emulation ICD supports this through display emulation on top of Win32/X11 windows, hence the sample should with the
Vulkan SC Emulation ICD on top of any Vulkan implementation supporting these window-systems on Windows and on Linux
running X11 or Wayland (through XWayland).

## Custom pipeline cache compiler

The Vulkan SC version of the cube sample (`vksccube`) much like all Vulkan SC applications requires an extra toolchain
component to execute properly: a pipeline cache compiler (PCC). As a convenience, the sample embeds a pre-compiled
pipeline cache binary using the Khronos Vulkan SC Emulation ICD PCC (`pcconvk`). This pipeline cache can be used with
the Vulkan SC Emulation ICD on top of any compatible Vulkan implementation.

If you want to run the application using any other Vulkan SC ICD, you'll need to compile the pipline cache JSON
(`cube-vksc/cube.pc.json`) offline and specify the built pipeline cache binary at run-time, e.g.:

```
<path-to-pcc> --path <VulkanSC-Tools-path>/cube-vksc --prefix cube.pc --out pipeline_cache.bin <additional-args>
vksccube --pipeline-cache pipeline_cache.bin
```

Alternatively, you can embed a custom pipeline cache binary into `vksccube` built using the pipeline cache compiler
of your choice instead of the Vulkan SC EMulation ICD's PCC by adding the `VKSC_PIPELINE_CACHE_COMPILER` (and if any
additional compiler specific flags are needed, the `VKSC_PIPELINE_CACHE_FLAGS`) configuration-time option(s):

```
cmake ... -D VKSC_PIPELINE_CACHE_COMPILER:FILEPATH=<path-to-pcc> -D VKSC_PIPELINE_CACHE_FLAGS=<additional-args>
```

For example, NVIDIA's Vulkan SC PCC requires an additional argument to specify the target GPU instruction set:

```
cmake ... -D VKSC_PIPELINE_CACHE_COMPILER:FILEPATH=<path-to-nvidia-pcc> -D VKSC_PIPELINE_CACHE_FLAGS="-chip <target>"
```
