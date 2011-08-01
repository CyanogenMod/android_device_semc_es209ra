#!/bin/sh

# Copyright (C) 2010 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

VENDOR=semc
DEVICE=es209ra

rm -r ../../../vendor/$VENDOR/$DEVICE
mkdir -p ../../../vendor/$VENDOR/$DEVICE/proprietary

# Prebuilt kl keymaps
adb pull /system/usr/keylayout/es209ra_keypad.kl ../../../vendor/$VENDOR/$DEVICE/proprietary
adb pull /system/usr/keylayout/es209ra_handset.kl ../../../vendor/$VENDOR/$DEVICE/proprietary
adb pull /system/usr/keychars/es209ra_keypad.kcm.bin ../../../vendor/$VENDOR/$DEVICE/proprietary

## RIL related stuff 
adb pull /system/lib/libril.so ../../../vendor/$VENDOR/$DEVICE/proprietary
adb pull /system/bin/port-bridge ../../../vendor/$VENDOR/$DEVICE/proprietary
adb pull /system/bin/qmuxd ../../../vendor/$VENDOR/$DEVICE/proprietary
adb pull /system/lib/libauth.so ../../../vendor/$VENDOR/$DEVICE/proprietary
adb pull /system/lib/libcm.so ../../../vendor/$VENDOR/$DEVICE/proprietary
adb pull /system/lib/libdiag.so ../../../vendor/$VENDOR/$DEVICE/proprietary
adb pull /system/lib/libdll.so ../../../vendor/$VENDOR/$DEVICE/proprietary
adb pull /system/lib/libdsm.so ../../../vendor/$VENDOR/$DEVICE/proprietary
adb pull /system/lib/libdss.so ../../../vendor/$VENDOR/$DEVICE/proprietary
adb pull /system/lib/libgsdi_exp.so ../../../vendor/$VENDOR/$DEVICE/proprietary
adb pull /system/lib/libgstk_exp.so ../../../vendor/$VENDOR/$DEVICE/proprietary
adb pull /system/lib/libmmgsdilib.so ../../../vendor/$VENDOR/$DEVICE/proprietary
adb pull /system/lib/libnv.so ../../../vendor/$VENDOR/$DEVICE/proprietary
adb pull /system/lib/liboem_rapi.so ../../../vendor/$VENDOR/$DEVICE/proprietary
adb pull /system/lib/liboncrpc.so ../../../vendor/$VENDOR/$DEVICE/proprietary
adb pull /system/lib/libpbmlib.so ../../../vendor/$VENDOR/$DEVICE/proprietary
adb pull /system/lib/libqmi.so ../../../vendor/$VENDOR/$DEVICE/proprietary
adb pull /system/lib/libqueue.so ../../../vendor/$VENDOR/$DEVICE/proprietary
adb pull /system/lib/libuim.so ../../../vendor/$VENDOR/$DEVICE/proprietary
adb pull /system/lib/libril-qc-1.so ../../../vendor/$VENDOR/$DEVICE/proprietary
adb pull /system/lib/libwms.so ../../../vendor/$VENDOR/$DEVICE/proprietary
adb pull /system/lib/libwmsts.so ../../../vendor/$VENDOR/$DEVICE/proprietary

## Camera proprietaries
adb pull /system/lib/liboemcamera.so ../../../vendor/$VENDOR/$DEVICE/proprietary
adb pull /system/lib/libmmjpeg.so ../../../vendor/$VENDOR/$DEVICE/proprietary
adb pull /system/lib/libmmipl.so ../../../vendor/$VENDOR/$DEVICE/proprietary 
adb pull /system/lib/libcamera.so ../../../vendor/$VENDOR/$DEVICE/proprietary
adb pull /system/lib/libopencore_common.so ../../../vendor/$VENDOR/$DEVICE/proprietary


## FIRMWARE
adb pull /system/etc/firmware/yamato_pfp.fw ../../../vendor/$VENDOR/$DEVICE/proprietary
adb pull /system/etc/firmware/yamato_pm4.fw ../../../vendor/$VENDOR/$DEVICE/proprietary
adb pull /system/etc/firmware/camfirm.bin ../../../vendor/$VENDOR/$DEVICE/proprietary

## ATHEROS WIFI 
adb pull /system/lib/modules/athwlan.bin.z77 ../../../vendor/$VENDOR/$DEVICE/proprietary
adb pull /system/lib/modules/data.patch.hw2_0.bin ../../../vendor/$VENDOR/$DEVICE/proprietary
adb pull /system/bin/wlan_mac ../../../vendor/$VENDOR/$DEVICE/proprietary
adb pull /system/bin/wlan_tool ../../../vendor/$VENDOR/$DEVICE/proprietary

## BT proprietary
adb pull /system/bin/hci_qcomm_init ../../../vendor/$VENDOR/$DEVICE/proprietary
adb pull /system/bin/hciattach ../../../vendor/$VENDOR/$DEVICE/proprietary

## Adreno 200 files
adb pull /system/lib/libgsl.so ../../../vendor/$VENDOR/$DEVICE/proprietary/libgsl.so
adb pull /system/lib/egl/libGLESv1_CM_adreno200.so ../../../vendor/$VENDOR/$DEVICE/proprietary
adb pull /system/lib/egl/libq3dtools_adreno200.so ../../../vendor/$VENDOR/$DEVICE/proprietary
adb pull /system/lib/egl/libEGL_adreno200.so ../../../vendor/$VENDOR/$DEVICE/proprietary
adb pull /system/lib/egl/libGLESv2_adreno200.so ../../../vendor/$VENDOR/$DEVICE/proprietary

## Other libraries and proprietary binaries
adb pull /system/etc/vold.fstab ../../../vendor/$VENDOR/$DEVICE/proprietary
adb pull /system/etc/sensors.conf ../../../vendor/$VENDOR/$DEVICE/proprietary
adb pull /system/bin/akmd2 ../../../vendor/$VENDOR/$DEVICE/proprietary

#offline charger
adb pull /system/bin/chargemon ../../../vendor/$VENDOR/$DEVICE/proprietary
adb pull /system/bin/updatemiscta ../../../vendor/$VENDOR/$DEVICE/proprietary
adb pull /system/lib/libmiscta.so ../../../vendor/$VENDOR/$DEVICE/proprietary

#hw
adb pull /system/lib/hw/copybit.qsd8k.so ../../../vendor/$VENDOR/$DEVICE/proprietary
adb pull /system/lib/hw/sensors.default.so ../../../vendor/$VENDOR/$DEVICE/proprietary

./setup-makefiles.sh

