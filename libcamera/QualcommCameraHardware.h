/*
** Copyright 2008, Google Inc.
** Copyright (c) 2009-2011, Code Aurora Forum. All rights reserved.
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

#ifndef ANDROID_HARDWARE_QUALCOMM_CAMERA_HARDWARE_H
#define ANDROID_HARDWARE_QUALCOMM_CAMERA_HARDWARE_H

#define ICS

#include <utils/threads.h>
#include <binder/MemoryBase.h>
#include <binder/MemoryHeapBase.h>
#include <stdint.h>
#include <ui/egl/android_natives.h>
#include <hardware/camera.h>
#include <camera/Camera.h>
#include <camera/CameraParameters.h>
#include <system/window.h>
#include <system/camera.h>
#include <hardware/camera.h>
#include <gralloc_priv.h>

extern "C" {
#include <linux/android_pmem.h>
}

struct str_map {
    const char *const desc;
    int val;
};

struct buffer_map {
    struct msm_frame *frame;
    buffer_handle_t * buffer;
    int size;
};

typedef enum {
    TARGET_MSM7625,
    TARGET_MSM7627,
    TARGET_QSD8250,
    TARGET_MSM7630,
    TARGET_MAX
}targetType;

typedef enum {
    LIVESHOT_DONE,
    LIVESHOT_IN_PROGRESS,
    LIVESHOT_STOPPED
}liveshotState;

#define MIN_UNDEQUEUD_BUFFER_COUNT 2
#define MAX_SNAPSHOT_BUFFERS 4

struct target_map {
    const char *targetStr;
    targetType targetEnum;
};

struct board_property{
    targetType target;
    unsigned int previewSizeMask;
    bool hasSceneDetect;
    bool hasSelectableZoneAf;
    bool hasFaceDetect;
};

typedef struct {
	unsigned int in1_w;
	unsigned int out1_w;
	unsigned int in1_h;
	unsigned int out1_h;
	unsigned int in2_w;
	unsigned int out2_w;
	unsigned int in2_h;
	unsigned int out2_h;
	uint8_t update_flag;
} common_crop_t;

typedef uint8_t cam_ctrl_type;

typedef struct {
	unsigned short video_width;
	unsigned short video_height;
	unsigned short picture_width;
	unsigned short picture_height;
	unsigned short display_width;
	unsigned short display_height;
	unsigned short orig_picture_dx;
	unsigned short orig_picture_dy;
	unsigned short ui_thumbnail_height;
	unsigned short ui_thumbnail_width;
	unsigned short thumbnail_height;
	unsigned short thumbnail_width;
	unsigned short raw_picture_height;
	unsigned short raw_picture_width;
	unsigned short filler7;
	unsigned short filler8;
	unsigned short postview_height;
	unsigned short postview_width;
} cam_ctrl_dimension_t;

typedef struct {
    uint8_t* ptr;
    uint32_t filled_size;
    uint32_t size;
    int32_t fd;
    uint32_t offset;
}mm_camera_buffer_t;

/* Add enumenrations at the bottom but before MM_CAMERA_PARM_MAX */
typedef enum {
    MM_CAMERA_PARM_PICT_SIZE,
    MM_CAMERA_PARM_ZOOM_RATIO,
    MM_CAMERA_PARM_HISTOGRAM,
    MM_CAMERA_PARM_DIMENSION,
    MM_CAMERA_PARM_FPS,
    MM_CAMERA_PARM_FPS_MODE, /*5*/
    MM_CAMERA_PARM_EFFECT,
    MM_CAMERA_PARM_EXPOSURE_COMPENSATION,
    MM_CAMERA_PARM_EXPOSURE,
    MM_CAMERA_PARM_SHARPNESS,
    MM_CAMERA_PARM_CONTRAST, /*10*/
    MM_CAMERA_PARM_SATURATION,
    MM_CAMERA_PARM_BRIGHTNESS,
    MM_CAMERA_PARM_WHITE_BALANCE,
    MM_CAMERA_PARM_LED_MODE,
    MM_CAMERA_PARM_ANTIBANDING, /*15*/
    MM_CAMERA_PARM_ROLLOFF,
    MM_CAMERA_PARM_CONTINUOUS_AF,
    MM_CAMERA_PARM_FOCUS_RECT,
    MM_CAMERA_PARM_AEC_ROI,
    MM_CAMERA_PARM_AF_ROI, /*20*/
    MM_CAMERA_PARM_HJR,
    MM_CAMERA_PARM_ISO,
    MM_CAMERA_PARM_BL_DETECTION,
    MM_CAMERA_PARM_SNOW_DETECTION,
    MM_CAMERA_PARM_BESTSHOT_MODE, /*25*/
    MM_CAMERA_PARM_ZOOM,
    MM_CAMERA_PARM_VIDEO_DIS,
    MM_CAMERA_PARM_VIDEO_ROT,
    MM_CAMERA_PARM_SCE_FACTOR,
    MM_CAMERA_PARM_FD, /*30*/
    MM_CAMERA_PARM_MODE,
    /* 2nd 32 bits */
    MM_CAMERA_PARM_3D_FRAME_FORMAT,
    MM_CAMERA_PARM_CAMERA_ID,
    MM_CAMERA_PARM_CAMERA_INFO,
    MM_CAMERA_PARM_PREVIEW_SIZE, /*35*/
    MM_CAMERA_PARM_QUERY_FALSH4SNAP,
    MM_CAMERA_PARM_FOCUS_DISTANCES,
    MM_CAMERA_PARM_BUFFER_INFO,
    MM_CAMERA_PARM_JPEG_ROTATION,
    MM_CAMERA_PARM_JPEG_MAINIMG_QUALITY, /* 40 */
    MM_CAMERA_PARM_JPEG_THUMB_QUALITY,
    MM_CAMERA_PARM_ZSL_ENABLE,
    MM_CAMERA_PARM_FOCAL_LENGTH,
    MM_CAMERA_PARM_HORIZONTAL_VIEW_ANGLE,
    MM_CAMERA_PARM_VERTICAL_VIEW_ANGLE, /* 45 */
    MM_CAMERA_PARM_MCE,
    MM_CAMERA_PARM_RESET_LENS_TO_INFINITY,
    MM_CAMERA_PARM_SNAPSHOTDATA,
    MM_CAMERA_PARM_HFR,
    MM_CAMERA_PARM_REDEYE_REDUCTION, /* 50 */
    MM_CAMERA_PARM_WAVELET_DENOISE,
    MM_CAMERA_PARM_3D_DISPLAY_DISTANCE,
    MM_CAMERA_PARM_3D_VIEW_ANGLE,
    MM_CAMERA_PARM_PREVIEW_FORMAT,
    MM_CAMERA_PARM_HFR_SIZE, /* 55 */
    MM_CAMERA_PARM_3D_EFFECT,
    MM_CAMERA_PARM_3D_MANUAL_CONV_RANGE,
    MM_CAMERA_PARM_3D_MANUAL_CONV_VALUE,
    MM_CAMERA_PARM_ENABLE_3D_MANUAL_CONVERGENCE, /* 59 */
    /* These are new parameters defined here */
    MM_CAMERA_PARM_CH_IMAGE_FMT,        // mm_camera_ch_image_fmt_parm_t
    MM_CAMERA_PARM_OP_MODE,             // camera state, sub state also
    MM_CAMERA_PARM_SHARPNESS_CAP,       //
    MM_CAMERA_PARM_SNAPSHOT_BURST_NUM,  // num shots per snapshot action
    MM_CAMERA_PARM_LIVESHOT_MAIN,       // enable/disable full size live shot
    MM_CAMERA_PARM_MAXZOOM,
    MM_CAMERA_PARM_LUMA_ADAPTATION,     // enable/disable
    MM_CAMERA_PARM_HDR,
    MM_CAMERA_PARM_CROP,
    MM_CAMERA_PARM_MAX_PICTURE_SIZE,
    MM_CAMERA_PARM_MAX_PREVIEW_SIZE,
    MM_CAMERA_PARM_ASD_ENABLE,
    MM_CAMERA_PARM_RECORDING_HINT,
    MM_CAMERA_PARM_CAF_ENABLE,
    MM_CAMERA_PARM_MAX
} mm_camera_parm_type_t;

enum {
	CAMERA_AEC_FRAME_AVERAGE,
	CAMERA_AEC_CENTER_WEIGHTED,
	CAMERA_AEC_SPOT_METERING,
};

typedef enum {
	AF_MODE_NORMAL,
	AF_MODE_MACRO,
	AF_MODE_AUTO,
} isp3a_af_mode_t;

enum {
	LED_MODE_OFF,
	LED_MODE_AUTO,
	LED_MODE_TORCH,
	LED_MODE_ON,
};

typedef enum {
    CAMERA_ANTIBANDING_OFF,
    CAMERA_ANTIBANDING_60HZ,
    CAMERA_ANTIBANDING_50HZ,
    CAMERA_ANTIBANDING_AUTO,
    CAMERA_MAX_ANTIBANDING,
} camera_antibanding_type;

typedef enum {
	CAMERA_WB_MIN_MINUS_1,
	CAMERA_WB_AUTO = 1,  /* This list must match aeecamera.h */
	CAMERA_WB_CUSTOM,
	CAMERA_WB_INCANDESCENT,
	CAMERA_WB_FLUORESCENT,
	CAMERA_WB_DAYLIGHT,
	CAMERA_WB_CLOUDY_DAYLIGHT,
	CAMERA_WB_TWILIGHT,
	CAMERA_WB_SHADE,
	CAMERA_WB_MAX_PLUS_1
} camera_wb_type;

typedef struct {
	uint32_t timestamp;  /* seconds since 1/6/1980          */
	double   latitude;   /* degrees, WGS ellipsoid */
	double   longitude;  /* degrees                */
	int16_t  altitude;   /* meters                          */
} camera_position_type;

struct cam_frame_start_parms {
	unsigned int unknown;
	struct msm_frame frame;
	struct msm_frame video_frame;
};

typedef unsigned int exif_tag_id_t;

#define EXIF_RATIONAL 5
#define EXIF_ASCII 2
#define EXIF_BYTE 1

typedef struct {
	int val;
	int otherval;
} rat_t;

typedef union {
        char * _ascii; /* At byte 16 relative to exif_tag_entry_t */
        rat_t * _rats;
        rat_t  _rat;
        uint8_t _byte;
} exif_tag_data_t;

/* The entire exif_tag_entry_t struct must be 24 bytes in length */
typedef unsigned int exif_tag_type_t;
typedef struct {
	exif_tag_type_t type;
	uint32_t copy;
	uint32_t count;
	exif_tag_data_t data;
} exif_tag_entry_t;

typedef struct {
	exif_tag_id_t tag_id;
	exif_tag_entry_t tag_entry;
} exif_tags_info_t;

/* EXIF tag IDs */
#define EXIFTAGID_GPS_LATITUDE 0x20002
#define EXIFTAGID_GPS_LATITUDE_REF 0x10001
#define EXIFTAGID_GPS_LONGITUDE 0x40004
#define EXIFTAGID_GPS_LONGITUDE_REF 0x30003
#define EXIFTAGID_GPS_ALTITUDE 0x60006
#define EXIFTAGID_GPS_ALTITUDE_REF 0x50005
#define EXIFTAGID_EXIF_CAMERA_MAKER 0x21010F
#define EXIFTAGID_EXIF_CAMERA_MODEL 0x220110
#define EXIFTAGID_EXIF_DATE_TIME_ORIGINAL 0x3A9003
#define EXIFTAGID_EXIF_DATE_TIME 0x3B9004
/* End of values originally in proprietary headers */

namespace android {

class QualcommCameraHardware : public RefBase{
public:

    //virtual sp<IMemoryHeap> getPreviewHeap() const;
    //virtual sp<IMemoryHeap> getRawHeap() const;

    void setCallbacks(camera_notify_callback notify_cb,
                            camera_data_callback data_cb,
                            camera_data_timestamp_callback data_cb_timestamp,
                            camera_request_memory get_memory,
                            void *user);

    virtual void enableMsgType(int32_t msgType);
    virtual void disableMsgType(int32_t msgType);
    virtual bool msgTypeEnabled(int32_t msgType);

    virtual status_t dump(int fd, const Vector<String16>& args) const;
    virtual status_t startPreview();
    virtual void stopPreview();
    virtual bool previewEnabled();
    virtual status_t startRecording();
    virtual void stopRecording();
    virtual bool recordingEnabled();
    virtual void releaseRecordingFrame(const void *opaque);
    virtual status_t autoFocus();
    virtual status_t cancelAutoFocus();
    virtual status_t takePicture();
    virtual status_t takeLiveSnapshot();
    void set_liveshot_exifinfo();
    virtual status_t cancelPicture();
    virtual status_t setParameters(const CameraParameters& params);
    virtual CameraParameters getParameters() const;
    virtual status_t sendCommand(int32_t command, int32_t arg1, int32_t arg2);
    virtual int32_t getNumberOfVideoBuffers();
    virtual sp<IMemory> getVideoBuffer(int32_t index);
    virtual status_t getBufferInfo( sp<IMemory>& Frame, size_t *alignedSize);
    virtual void encodeData( );
    virtual status_t set_PreviewWindow(void* param);
    virtual status_t setPreviewWindow(preview_stream_ops_t* window);
    virtual status_t setPreviewWindow(const sp<ANativeWindow>& buf) {return NO_ERROR;};
    virtual void release();

    static QualcommCameraHardware* createInstance();
    static QualcommCameraHardware* getInstance();

    void receivePreviewFrame(struct msm_frame *frame);
    void receiveLiveSnapshot(uint32_t jpeg_size);
//    void receiveCameraStats(camstats_type stype, camera_preview_histogram_info* histinfo);
    void receiveRecordingFrame(struct msm_frame *frame);
    void receiveJpegPicture(status_t status, mm_camera_buffer_t *encoded_buffer);
    void jpeg_set_location();
    void receiveJpegPictureFragment(uint8_t *buf, uint32_t size);
    void notifyShutter(bool mPlayShutterSoundOnly);
    void receive_camframe_error_timeout();
    static void getCameraInfo();
    void receiveRawPicture(status_t status,struct msm_frame *postviewframe, struct msm_frame *mainframe);
    virtual ~QualcommCameraHardware();
    int storeMetaDataInBuffers(int enable);

private:
    QualcommCameraHardware();
    status_t startPreviewInternal();
    status_t startRecordingInternal();
//    status_t setHistogramOn();
//    status_t setHistogramOff();
//    status_t runFaceDetection();
//    status_t setFaceDetection(const char *str);

    void stopPreviewInternal();
    friend void *auto_focus_thread(void *user);
    void runAutoFocus();
    status_t cancelAutoFocusInternal();
    bool native_set_dimension (int camfd);
    bool native_jpeg_encode (void);
    bool updatePictureDimension(const CameraParameters& params, int& width, int& height);
    bool native_set_parms(mm_camera_parm_type_t type, uint16_t length, void *value);
    bool native_set_parms( mm_camera_parm_type_t type, uint16_t length, void *value, int *result);
    bool native_zoom_image(int fd, int srcOffset, int dstOffset, common_crop_t *crop);

    status_t startInitialPreview();
    void stopInitialPreview();
    status_t getBuffersAndStartPreview();
    void relinquishBuffers();

    QualcommCameraHardware * singleton;

    /* These constants reflect the number of buffers that libmmcamera requires
       for preview and raw, and need to be updated when libmmcamera
       changes.
    */
    static const int kPreviewBufferCount = NUM_PREVIEW_BUFFERS;
    static const int kRawBufferCount = 1;
    static const int kJpegBufferCount = 1;
    static const int kTotalPreviewBufferCount = kPreviewBufferCount + MIN_UNDEQUEUD_BUFFER_COUNT;
    int numCapture;
    int numJpegReceived;
    int jpegPadding;

    CameraParameters mParameters;
    unsigned int frame_size;
    bool mCameraRunning;
    Mutex mCameraRunningLock;
    bool mPreviewInitialized;


    class MMCameraDL : public RefBase{
    private:
        static wp<MMCameraDL> instance;
        MMCameraDL();
        virtual ~MMCameraDL();
        void *libmmcamera;
        static Mutex singletonLock;
    public:
        static sp<MMCameraDL> getInstance();
        void * pointer();
    };

    // This class represents a heap which maintains several contiguous
    // buffers.  The heap may be backed by pmem (when pmem_pool contains
    // the name of a /dev/pmem* file), or by ashmem (when pmem_pool == NULL).
    struct MemPool : public RefBase {
        MemPool(int buffer_size, int num_buffers,
                int frame_size,
                const char *name);

        virtual ~MemPool()  ;// = 0;

        void completeInitialization();
        bool initialized() const {
            return mHeap != NULL && mHeap->base() != MAP_FAILED;
        }

        virtual status_t dump(int fd, const Vector<String16>& args) const;

        int mBufferSize;
        int mAlignedBufferSize;
        int mNumBuffers;
        int mFrameSize;
        sp<MemoryHeapBase> mHeap;
        sp<MemoryBase> *mBuffers;

        const char *mName;
    };
      struct DispMemPool : public MemPool {
          DispMemPool(int fd, int buffer_size,
          int num_buffers, int frame_size,
          const char *name);
          virtual ~DispMemPool();
          int mFD;
      };
      sp<DispMemPool> mPreviewHeap[kPreviewBufferCount + MIN_UNDEQUEUD_BUFFER_COUNT];

    struct AshmemPool : public MemPool {
        AshmemPool(int buffer_size, int num_buffers,
                   int frame_size,
                   const char *name);
    };

    struct PmemPool : public MemPool {
        PmemPool(const char *pmem_pool,
                 int flags, int pmem_type,
                 int buffer_size, int num_buffers,
                 int frame_size, int cbcr_offset,
                 int yoffset, const char *name);
        virtual ~PmemPool();
        int mFd;
        int mPmemType;
        int mCbCrOffset;
        int myOffset;
        int mCameraControlFd;
        uint32_t mAlignedSize;
        struct pmem_region mSize;
        sp<QualcommCameraHardware::MMCameraDL> mMMCameraDLRef;
    };

//    sp<PmemPool> mPreviewHeap;
    sp<PmemPool> mYV12Heap;
    sp<PmemPool> mRecordHeap;
    sp<PmemPool> mThumbnailHeap;
    sp<PmemPool> mRawHeap;
    sp<PmemPool> mDisplayHeap;
    sp<AshmemPool> mJpegHeap;
    sp<AshmemPool> mStatHeap;
    sp<AshmemPool> mMetaDataHeap;
    sp<PmemPool> mRawSnapShotPmemHeap;
    sp<PmemPool> mLastPreviewFrameHeap;
    sp<PmemPool> mPostviewHeap;
	sp<PmemPool> mPostViewHeap;
    sp<PmemPool> mInitialPreviewHeap;

    sp<MMCameraDL> mMMCameraDLRef;

    bool startCamera();
    bool initPreview();
    bool initRecord();
    void deinitPreview();
    bool initRaw(bool initJpegHeap);
    bool initZslBuffers(bool initJpegHeap);
    bool deinitZslBuffers();
    bool initLiveSnapshot(int videowidth, int videoheight);
    bool initRawSnapshot();
    void deinitRaw();
    void deinitRawSnapshot();
    bool mPreviewThreadRunning;
    bool createSnapshotMemory (int numberOfRawBuffers, int numberOfJpegBuffers,
                                   bool initJpegHeap, int snapshotFormat = 1 /*PICTURE_FORMAT_JPEG*/);
    Mutex mPreviewThreadWaitLock;
    Condition mPreviewThreadWait;
    friend void *preview_thread(void *user);
    friend void *openCamera(void *data);
    void runPreviewThread(void *data);
    friend void *hfr_thread(void *user);
    void runHFRThread(void *data);
    bool mHFRThreadRunning;
	int mapBuffer(msm_frame *frame);
	int mapRawBuffer(msm_frame *frame);
	int mapThumbnailBuffer(msm_frame *frame);
	int mapJpegBuffer(mm_camera_buffer_t* buffer);
        int mapvideoBuffer( msm_frame *frame);
	int mapFrame(buffer_handle_t *buffer);
    Mutex mHFRThreadWaitLock;

    class FrameQueue : public RefBase{
    private:
        Mutex mQueueLock;
        Condition mQueueWait;
        bool mInitialized;

        Vector<struct msm_frame *> mContainer;
    public:
        FrameQueue();
        virtual ~FrameQueue();
        bool add(struct msm_frame *element);
        void flush();
        struct msm_frame* get();
        void init();
        void deinit();
        bool isInitialized();
    };

    FrameQueue mPreviewBusyQueue;

    bool mFrameThreadRunning;
    Mutex mFrameThreadWaitLock;
    Condition mFrameThreadWait;
    friend void *frame_thread(void *user);
    void runFrameThread(void *data);

    //720p recording video thread
    bool mVideoThreadExit;
    bool mVideoThreadRunning;
    Mutex mVideoThreadWaitLock;
    Condition mVideoThreadWait;
    friend void *video_thread(void *user);
    void runVideoThread(void *data);

    // smooth zoom
    int mTargetSmoothZoom;
    bool mSmoothzoomThreadExit;
    bool mSmoothzoomThreadRunning;
    Mutex mSmoothzoomThreadWaitLock;
    Mutex mSmoothzoomThreadLock;
    Condition mSmoothzoomThreadWait;
    friend void *smoothzoom_thread(void *user);
    void runSmoothzoomThread(void* data);

    // For Histogram
//    int mStatsOn;
//    int mCurrent;
//    bool mSendData;
//    Mutex mStatsWaitLock;
//    Condition mStatsWait;

    //For Face Detection
//    int mFaceDetectOn;
//    bool mSendMetaData;
//    Mutex mMetaDataWaitLock;

    bool mShutterPending;
    Mutex mShutterLock;

    bool mSnapshotThreadRunning;
    Mutex mSnapshotThreadWaitLock;
    Condition mSnapshotThreadWait;
    friend void *snapshot_thread(void *user);
    void runSnapshotThread(void *data);
    Mutex mRawPictureHeapLock;
    bool mJpegThreadRunning;
    Mutex mJpegThreadWaitLock;
    Condition mJpegThreadWait;
    bool mInSnapshotMode;
    Mutex mInSnapshotModeWaitLock;
    Condition mInSnapshotModeWait;
    bool mEncodePending;
    Mutex mEncodePendingWaitLock;
    Condition mEncodePendingWait;
	bool mBuffersInitialized;

    void debugShowPreviewFPS() const;
    void debugShowVideoFPS() const;

    int mSnapshotFormat;
    bool mFirstFrame;
    void hasAutoFocusSupport();
    void filterPictureSizes();
    void filterPreviewSizes();
    static void storeTargetType();
    bool supportsSceneDetection();
    bool supportsSelectableZoneAf();
    bool supportsFaceDetection();

    void initDefaultParameters();
    bool initImageEncodeParameters(int size);
    bool initZslParameter(void);
    status_t setCameraMode(const CameraParameters& params);
    status_t setPreviewSize(const CameraParameters& params);
    status_t setJpegThumbnailSize(const CameraParameters& params);
    status_t setPreviewFpsRange(const CameraParameters& params);
    status_t setPreviewFrameRate(const CameraParameters& params);
    status_t setPreviewFrameRateMode(const CameraParameters& params);
    status_t setRecordSize(const CameraParameters& params);
    status_t setPictureSize(const CameraParameters& params);
    status_t setJpegQuality(const CameraParameters& params);
    status_t setAntibanding(const CameraParameters& params);
    status_t setEffect(const CameraParameters& params);
    status_t setRecordingHint(const CameraParameters& params);
    status_t setExposureCompensation(const CameraParameters &params);
    status_t setAutoExposure(const CameraParameters& params);
    status_t setWhiteBalance(const CameraParameters& params);
    status_t setFlash(const CameraParameters& params);
    status_t setGpsLocation(const CameraParameters& params);
    status_t setRotation(const CameraParameters& params);
    status_t setZoom(const CameraParameters& params);
    status_t setFocusMode(const CameraParameters& params);
    status_t setBrightness(const CameraParameters& params);
    status_t setSkinToneEnhancement(const CameraParameters& params);
    status_t setOrientation(const CameraParameters& params);
    status_t setLensshadeValue(const CameraParameters& params);
    status_t setMCEValue(const CameraParameters& params);
    status_t setHDRImaging(const CameraParameters& params);
    status_t setExpBracketing(const CameraParameters& params);
    status_t setISOValue(const CameraParameters& params);
    status_t setPictureFormat(const CameraParameters& params);
    status_t setSharpness(const CameraParameters& params);
    status_t setContrast(const CameraParameters& params);
    status_t setSaturation(const CameraParameters& params);
    status_t setSceneMode(const CameraParameters& params);
    status_t setContinuousAf(const CameraParameters& params);
    status_t setTouchAfAec(const CameraParameters& params);
    status_t setSceneDetect(const CameraParameters& params);
    status_t setStrTextures(const CameraParameters& params);
    status_t setPreviewFormat(const CameraParameters& params);
    status_t setSelectableZoneAf(const CameraParameters& params);
    status_t setHighFrameRate(const CameraParameters& params);
    bool register_record_buffers(bool register_buffer);
    status_t setRedeyeReduction(const CameraParameters& params);
    status_t setDenoise(const CameraParameters& params);
    status_t setZslParam(const CameraParameters& params);
    status_t setSnapshotCount(const CameraParameters& params);
    void setGpsParameters();
    bool storePreviewFrameForPostview();
    bool isValidDimension(int w, int h);
    status_t updateFocusDistances(const char *focusmode);
    int mStoreMetaDataInFrame;

    Mutex mLock;
	Mutex mDisplayLock;
    Mutex mCamframeTimeoutLock;
    bool camframe_timeout_flag;
    bool mReleasedRecordingFrame;

    Mutex mParametersLock;


    Mutex mCallbackLock;
    Mutex mOverlayLock;
	Mutex mRecordLock;
	Mutex mRecordFrameLock;
	Condition mRecordWait;
    Condition mStateWait;

    /* mJpegSize keeps track of the size of the accumulated JPEG.  We clear it
       when we are about to take a picture, so at any time it contains either
       zero, or the size of the last JPEG picture taken.
    */
    uint32_t mJpegSize;
    unsigned int        mPreviewFrameSize;
    unsigned int        mRecordFrameSize;
    int                 mRawSize;
    int                 mCbCrOffsetRaw;
    int                 mJpegMaxSize;
    int32_t                 mStatSize;


    cam_ctrl_dimension_t mDimension;
    bool mAutoFocusThreadRunning;
    Mutex mAutoFocusThreadLock;

    Mutex mAfLock;

    pthread_t mFrameThread;
    pthread_t mVideoThread;
    pthread_t mPreviewThread;
    pthread_t mSnapshotThread;
    pthread_t mDeviceOpenThread;
    pthread_t mSmoothzoomThread;
    pthread_t mHFRThread;

    common_crop_t mCrop;

    bool mInitialized;

    int mBrightness;
    int mSkinToneEnhancement;
    int mHJR;
    unsigned int mThumbnailMapped[MAX_SNAPSHOT_BUFFERS];
    int mRawfd[MAX_SNAPSHOT_BUFFERS];
    int mRawSnapshotfd;
    int mJpegfd[MAX_SNAPSHOT_BUFFERS];
    int mRecordfd[9];
    camera_memory_t *mPreviewMapped[kPreviewBufferCount + MIN_UNDEQUEUD_BUFFER_COUNT];
    camera_memory_t *mRawMapped[MAX_SNAPSHOT_BUFFERS];
    camera_memory_t *mJpegMapped[MAX_SNAPSHOT_BUFFERS];
    camera_memory_t *mRawSnapshotMapped;
    camera_memory_t *mStatsMapped[3];
    camera_memory_t *mRecordMapped[9];
    camera_memory_t* metadata_memory[9];

    struct msm_frame *frames[kPreviewBufferCount + MIN_UNDEQUEUD_BUFFER_COUNT];
    struct buffer_map frame_buffer[kPreviewBufferCount + MIN_UNDEQUEUD_BUFFER_COUNT];
    struct msm_frame *recordframes;
    struct msm_frame *rawframes;
    bool *record_buffers_tracking_flag;
    bool mInPreviewCallback;
    preview_stream_ops_t* mPreviewWindow;
    android_native_buffer_t *mPostViewBuffer;
    buffer_handle_t *mThumbnailBuffer[MAX_SNAPSHOT_BUFFERS];

    int32_t mMsgEnabled;    // camera msg to be handled
    camera_notify_callback mNotifyCallback;
    camera_data_callback mDataCallback;
    camera_data_timestamp_callback mDataCallbackTimestamp;
    camera_request_memory mGetMemory;
    void *mCallbackCookie;  // same for all callbacks
    int mDebugFps;
    int kPreviewBufferCountActual;
    int previewWidth, previewHeight;
    int yv12framesize;
    bool mSnapshotDone;
    int maxSnapshotWidth;
    int maxSnapshotHeight;
    bool mHasAutoFocusSupport;
    int videoWidth, videoHeight;

    bool mDisEnabled;
    int mRotation;
    bool mResetWindowCrop;
    int mThumbnailWidth, mThumbnailHeight;
    status_t setVpeParameters();
    status_t setDIS();
    bool strTexturesOn;
    int mPictureWidth;
    int mPictureHeight;
    int mPostviewWidth;
    int mPostviewHeight;
    int mTotalPreviewBufferCount;
    int mDenoiseValue;
    int mZslEnable;
    int mZslPanorama;
    bool mZslFlashEnable;
    bool mSnapshotCancel;
    bool mHFRMode;
    Mutex mSnapshotCancelLock;
    int mActualPictWidth;
    int mActualPictHeight;
    bool mUseJpegDownScaling;
    bool mPreviewStopping;
    bool mInHFRThread;
    Mutex mPmemWaitLock;
    Condition mPmemWait;
    bool mPrevHeapDeallocRunning;
    bool mHdrMode;
    bool mExpBracketMode;

    bool mMultiTouch;
};

extern "C" int HAL_getNumberOfCameras();
extern "C" void HAL_getCameraInfo(int cameraId, struct CameraInfo* cameraInfo);
extern "C" QualcommCameraHardware* HAL_openCameraHardware(int cameraId);
}; // namespace android

#endif
