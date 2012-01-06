-include vendor/semc/es209ra/BoardConfigVendor.mk

TARGET_NO_BOOTLOADER := true

TARGET_BOOTLOADER_BOARD_NAME := es209ra
TARGET_SPECIFIC_HEADER_PATH := device/semc/es209ra/include

TARGET_BOARD_PLATFORM := qsd8k
TARGET_BOARD_PLATFORM_GPU := qcom-adreno200

TARGET_CPU_ABI := armeabi-v7a
TARGET_CPU_ABI2 := armeabi
TARGET_ARCH_VARIANT := armv7-a-neon
ARCH_ARM_HAVE_TLS_REGISTER := true
ARCH_ARM_HAVE_ARMV7A_BUG := true

BOARD_USES_GENERIC_AUDIO := false

# Wifi related defines
BOARD_WPA_SUPPLICANT_DRIVER := AWEXT
WIFI_DRIVER_MODULE_NAME     := ar6000

BOARD_HAVE_BLUETOOTH := true
BOARD_HAVE_BLUETOOTH_CUSTOM_HCIATTACH := true

BOARD_USES_QCOM_HARDWARE := true
BOARD_USES_QCOM_LIBS := true
BOARD_USES_QCOM_LIBRPC := true
#USE_OPENGL_RENDERER := false
#TARGET_USES_C2D_COMPOSITION := false
#TARGET_USES_SF_BYPASS := false
#TARGET_HAVE_BYPASS := false
#TARGET_USES_OVERLAY := false
#TARGET_QCOM_HDMI_OUT := false
#TARGET_GRALLOC_USES_ASHMEM := true
TARGET_USES_GENLOCK := true
TARGET_USES_CPU_UPLOAD := true
COMMON_GLOBAL_CFLAGS += -DREFRESH_RATE=60 -DMISSING_GRALLOC_BUFFERS -DMISSING_EGL_PIXEL_FORMAT_YV12 -DMISSING_EGL_EXTERNAL_IMAGE
BOARD_EGL_CFG := device/semc/msm7x30-common/prebuilt/egl.cfg

BOARD_USES_QCOM_GPS := true
BOARD_VENDOR_QCOM_AMSS_VERSION := 1240
BOARD_VENDOR_QCOM_GPS_LOC_API_HARDWARE := es209ra
BOARD_VENDOR_QCOM_GPS_LOC_API_AMSS_VERSION := 1240

BOARD_EGL_CFG := device/semc/es209ra/prebuilt/egl.cfg

BOARD_CUSTOM_BOOTIMG_MK := device/semc/es209ra/custombootimg.mk
TARGET_RECOVERY_PRE_COMMAND := "touch /cache/recovery/boot;sync;"

BOARD_HAS_NO_MISC_PARTITION := true
BOARD_USES_RECOVERY_CHARGEMODE := false
BOARD_CUSTOM_RECOVERY_KEYMAPPING := ../../device/semc/es209ra/recovery/recovery_keys.c

BOARD_KERNEL_CMDLINE := console=null
BOARD_KERNEL_BASE := 0x20000000

BOARD_SDCARD_INTERNAL_DEVICE := /dev/block/mmcblk0p1

# A custom ota package maker for a device without a boot partition
TARGET_RELEASETOOL_OTA_FROM_TARGET_SCRIPT := device/semc/es209ra/releasetools/semc_ota_from_target_files

TARGET_OTA_ASSERT_DEVICE := X10i,X10a,es209ra

BOARD_CAMERA_USE_GETBUFFERINFO := true

TARGET_USE_CUSTOM_LUN_FILE_PATH := /sys/devices/platform/usb_mass_storage/lun0/file
BOARD_UMS_LUNFILE := /sys/devices/platform/usb_mass_storage/lun0

