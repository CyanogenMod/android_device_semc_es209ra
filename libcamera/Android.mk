BUILD_LIBCAMERA:=false
ifeq ($(BUILD_LIBCAMERA),true)

# When zero we link against libmmcamera; when 1, we dlopen libmmcamera.
DLOPEN_LIBMMCAMERA:=1

ifneq ($(BUILD_TINY_ANDROID),true)

LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_CFLAGS:= -DDLOPEN_LIBMMCAMERA=$(DLOPEN_LIBMMCAMERA)

LOCAL_CFLAGS+= -DHW_ENCODE

LOCAL_HAL_FILES := QualcommCamera.cpp 
#QualcommCameraHardware.cpp
MM_CAM_FILES:=

LOCAL_SRC_FILES := $(MM_CAM_FILES) $(LOCAL_HAL_FILES)

LOCAL_CFLAGS+= -DNUM_PREVIEW_BUFFERS=4 -D_ANDROID_ -DUSE_NEON_CONVERSION

LOCAL_C_INCLUDES+= \
    $(TARGET_OUT_HEADERS)/mm-camera \
    $(TARGET_OUT_HEADERS)/mm-camera/common \
    $(TARGET_OUT_HEADERS)/mm-still/jpeg \

LOCAL_C_INCLUDES += hardware/qcom/display/libgralloc \
                    hardware/qcom/display/libgenlock \
                    hardware/qcom/media/libstagefrighthw


LOCAL_SHARED_LIBRARIES:= libutils libui libcamera_client liblog libcutils libmmjpeg
LOCAL_SHARED_LIBRARIES+= libgenlock libbinder

ifneq ($(DLOPEN_LIBMMCAMERA),1)
LOCAL_SHARED_LIBRARIES+= liboemcamera
else
LOCAL_SHARED_LIBRARIES+= libdl
endif

LOCAL_MODULE_PATH := $(TARGET_OUT_SHARED_LIBRARIES)/hw
LOCAL_MODULE:= camera.$(TARGET_BOARD_PLATFORM)
LOCAL_MODULE_TAGS := optional
include $(BUILD_SHARED_LIBRARY)

endif # BUILD_TINY_ANDROID
endif # BUILD_LIBCAMERA
