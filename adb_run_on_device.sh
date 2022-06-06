#!/bin/bash

set -e

DEVICE_PATH=/data/local/tmp/
adb shell mkdir -p ${DEVICE_PATH}

EXE=test

adb push build_android/bin/${EXE} ${DEVICE_PATH}
adb shell chmod +x ${DEVICE_PATH}/${EXE}
adb shell ${DEVICE_PATH}/${EXE}