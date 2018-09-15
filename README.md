# Huawei Ascend P6 kernel source

## FEATURES

- Version: `3.0.8`
- Ready-to-use configuration for P6 - `cm_k3v2oem1_defconfig`
- Implement new SELinux features from version `4.17`
- Enable SELinux by default
- Just be prepared for Android 8.1 Oreo!

## HOW TO USE

Generally, this source is used for Android building. Clone this repository first, then move it into `<ANDROID_SOURCE>/kernel/huawei/hwp6_u06`. 

If you want to build Android or TWRP recovery, please also clone my given configuration file from `https://github.com/AnClark/twrp_device_huawei_hwp6_u06`.

## BUILD KERNEL ALONE

Also, you can build this kernel alone if you want to test the new kernel, or change your current kernel, even more. Every possibility is able to achieve by you.

### Preparations

- An x86_64 Linux system. Mine is Ubuntu 18.04.
- Build essentials. You can install via `sudo apt install build-essential` (On Ubuntu 16.04. For other distributions (like RedHat, OpenSUSE), please follow their instructions).
- ARM cross-compile kits. **FriendlyARM GCC is necessary, notice that other newer kits CAN BUILD, BUT CANNOT RUN!** 
  - **[FriendlyARM GCC is here](https://github.com/AnClark/twrp_device_huawei_hwp6_u06/tree/omni-6.0/toolchain)**
  - Assume that you installed it in `/opt/FriendlyARM/toolschain/4.4.3`, and added `/opt/FriendlyARM/toolschain/4.4.3/bin` to `$PATH`.

### Gotta go!

```shell
# Set cross-compile variables
export ARCH=arm
export SUBARCH=arm
export CROSS_COMPILE=arm-none-linux-gnueabi-

# Clean old files
make mrproper

# Load config
make cm_k3v2oem1_defconfig

# Build kernel
make

# Built kernel is here â†“
file arch/arm/boot/zImage
```

## CREDITS

- @[**surdupetru**](https://github.com/surdupetru) - Gathered the [original code](https://github.com/surdupetru/huawei-p6)
- @**anclark** - Get it ready for Android 8.1
