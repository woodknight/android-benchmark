#!/bin/bash
set -e

rm -rf build_android
mkdir build_android

# compile
cd build_android

ANDROID_NDK="$HOME/Android/Sdk/ndk-bundle"

# cmake -DCMAKE_TOOLCHAIN_FILE="$ANDROID_NDK/build/cmake/android.toolchain.cmake" \
#       -DCMAKE_EXPORT_COMPILE_COMMANDS=1 \
#       -DCMAKE_INSTALL_PREFIX="install" \
#       -DCMAKE_BUILD_TYPE="Release" \
#       -DANDROID_ABI="arm64-v8a" \
#       -DANDROID_PLATFORM="android-28" \
#       -DANDROID_ARM_NEON="True" \
#       ../

# Starting from CMake 3.21, CMake has built-in support for NDK.
cmake ../ \
      -DCMAKE_SYSTEM_NAME=Android \
      -DCMAKE_SYSTEM_VERSION=28 \
      -DCMAKE_ANDROID_NDK=$ANDROID_NDK \
      -DCMAKE_ANDROID_ARCH_ABI=arm64-v8a \
      # -DCMAKE_ANDROID_ARCH_ABI=armeabi-v7a \
      # -DCMAKE_ANDROID_ARM_NEON=OFF \

make