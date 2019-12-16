//=============================================================================================================================
//
// EasyAR 3.0.1-final-r238a6316e
// Copyright (c) 2015-2019 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#ifndef __EASYAR_TYPES_H__
#define __EASYAR_TYPES_H__

#ifndef __cplusplus
#include <stdbool.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef struct { char _placeHolder_; } easyar_String;
void easyar_String_from_utf8(const char * begin, const char * end, /* OUT */ easyar_String * * Return);
void easyar_String_from_utf8_begin(const char * begin, /* OUT */ easyar_String * * Return);
const char * easyar_String_begin(const easyar_String * This);
const char * easyar_String_end(const easyar_String * This);
void easyar_String_copy(const easyar_String * This, /* OUT */ easyar_String * * Return);
void easyar_String__dtor(easyar_String * This);

/// <summary>
/// class
/// </summary>
typedef struct { char _placeHolder_; } easyar_ObjectTargetParameters;

/// <summary>
/// class
/// extends Target
/// </summary>
typedef struct { char _placeHolder_; } easyar_ObjectTarget;

/// <summary>
/// class
/// extends TargetTrackerResult
/// </summary>
typedef struct { char _placeHolder_; } easyar_ObjectTrackerResult;

/// <summary>
/// class
/// </summary>
typedef struct { char _placeHolder_; } easyar_ObjectTracker;

/// <summary>
/// class
/// extends Target
/// </summary>
typedef struct { char _placeHolder_; } easyar_CADTarget;

/// <summary>
/// class
/// extends TargetTrackerResult
/// </summary>
typedef struct { char _placeHolder_; } easyar_CADTrackerResult;

/// <summary>
/// class
/// </summary>
typedef struct { char _placeHolder_; } easyar_CADTracker;

typedef enum
{
    easyar_CloudStatus_FoundTargets = 0,
    easyar_CloudStatus_TargetsNotFound = 1,
    easyar_CloudStatus_Reconnecting = 2,
    easyar_CloudStatus_ProtocolError = 3,
} easyar_CloudStatus;

/// <summary>
/// class
/// </summary>
typedef struct { char _placeHolder_; } easyar_CloudRecognizer;

/// <summary>
/// class
/// </summary>
typedef struct { char _placeHolder_; } easyar_DenseSpatialMap;

/// <summary>
/// record
/// </summary>
typedef struct
{
    int x_;
    int y_;
    int z_;
    int numOfVertex_;
    int startPointOfVertex_;
    int numOfIndex_;
    int startPointOfIndex_;
    int age_;
} easyar_BlockInfo;

/// <summary>
/// class
/// </summary>
typedef struct { char _placeHolder_; } easyar_SceneMesh;

typedef enum
{
    easyar_SurfaceTrackingStatus_NotTracking = 0,
    easyar_SurfaceTrackingStatus_BadTracking = 1,
    easyar_SurfaceTrackingStatus_GoodTracking = 2,
} easyar_SurfaceTrackingStatus;

/// <summary>
/// class
/// extends FrameFilterResult
/// </summary>
typedef struct { char _placeHolder_; } easyar_SurfaceTrackerResult;

/// <summary>
/// class
/// </summary>
typedef struct { char _placeHolder_; } easyar_SurfaceTracker;

typedef enum
{
    easyar_MotionTrackingStatus_NotTracking = 0,
    easyar_MotionTrackingStatus_BadTracking = 1,
    easyar_MotionTrackingStatus_GoodTracking = 2,
} easyar_MotionTrackingStatus;

/// <summary>
/// class
/// extends FrameFilterResult
/// </summary>
typedef struct { char _placeHolder_; } easyar_MotionTrackerResult;

/// <summary>
/// class
/// </summary>
typedef struct { char _placeHolder_; } easyar_MotionTracker;

/// <summary>
/// class
/// </summary>
typedef struct { char _placeHolder_; } easyar_MotionTrackerOutputFrameToInputFrameAdapter;

/// <summary>
/// class
/// </summary>
typedef struct { char _placeHolder_; } easyar_ImageTargetParameters;

/// <summary>
/// class
/// extends Target
/// </summary>
typedef struct { char _placeHolder_; } easyar_ImageTarget;

typedef enum
{
    easyar_ImageTrackerMode_PreferQuality = 0,
    easyar_ImageTrackerMode_PreferPerformance = 1,
} easyar_ImageTrackerMode;

/// <summary>
/// class
/// extends TargetTrackerResult
/// </summary>
typedef struct { char _placeHolder_; } easyar_ImageTrackerResult;

/// <summary>
/// class
/// </summary>
typedef struct { char _placeHolder_; } easyar_ImageTracker;

/// <summary>
/// class
/// </summary>
typedef struct { char _placeHolder_; } easyar_Recorder;

typedef enum
{
    easyar_RecordProfile_Quality_1080P_Low = 0x00000001,
    easyar_RecordProfile_Quality_1080P_Middle = 0x00000002,
    easyar_RecordProfile_Quality_1080P_High = 0x00000004,
    easyar_RecordProfile_Quality_720P_Low = 0x00000008,
    easyar_RecordProfile_Quality_720P_Middle = 0x00000010,
    easyar_RecordProfile_Quality_720P_High = 0x00000020,
    easyar_RecordProfile_Quality_480P_Low = 0x00000040,
    easyar_RecordProfile_Quality_480P_Middle = 0x00000080,
    easyar_RecordProfile_Quality_480P_High = 0x00000100,
    easyar_RecordProfile_Quality_Default = 0x00000010,
} easyar_RecordProfile;

typedef enum
{
    easyar_RecordVideoSize_Vid1080p = 0x00000002,
    easyar_RecordVideoSize_Vid720p = 0x00000010,
    easyar_RecordVideoSize_Vid480p = 0x00000080,
} easyar_RecordVideoSize;

typedef enum
{
    easyar_RecordZoomMode_NoZoomAndClip = 0x00000000,
    easyar_RecordZoomMode_ZoomInWithAllContent = 0x00000001,
} easyar_RecordZoomMode;

typedef enum
{
    easyar_RecordVideoOrientation_Landscape = 0x00000000,
    easyar_RecordVideoOrientation_Portrait = 0x00000001,
} easyar_RecordVideoOrientation;

typedef enum
{
    easyar_RecordStatus_OnStarted = 0x00000002,
    easyar_RecordStatus_OnStopped = 0x00000004,
    easyar_RecordStatus_FailedToStart = 0x00000202,
    easyar_RecordStatus_FileSucceeded = 0x00000400,
    easyar_RecordStatus_FileFailed = 0x00000401,
    easyar_RecordStatus_LogInfo = 0x00000800,
    easyar_RecordStatus_LogError = 0x00001000,
} easyar_RecordStatus;

/// <summary>
/// class
/// </summary>
typedef struct { char _placeHolder_; } easyar_RecorderConfiguration;

typedef enum
{
    easyar_MapTrackingStatus_NotTracking = 0,
    easyar_MapTrackingStatus_Tracking = 1,
} easyar_MapTrackingStatus;

/// <summary>
/// class
/// extends FrameFilterResult
/// </summary>
typedef struct { char _placeHolder_; } easyar_SparseSpatialMapResult;

typedef enum
{
    easyar_PlaneType_Horizontal = 0,
    easyar_PlaneType_Vertical = 1,
} easyar_PlaneType;

/// <summary>
/// class
/// </summary>
typedef struct { char _placeHolder_; } easyar_PlaneData;

typedef enum
{
    easyar_LocalizeConfig_UntilSuccess = 0,
    easyar_LocalizeConfig_Keep = 1,
    easyar_LocalizeConfig_Once = 2,
    easyar_LocalizeConfig_KeepUpdate = 3,
} easyar_LocalizeConfig;

typedef enum
{
    easyar_MapConfig_NotExtend = 0,
    easyar_MapConfig_Extend = 1,
} easyar_MapConfig;

/// <summary>
/// class
/// </summary>
typedef struct { char _placeHolder_; } easyar_SparseSpatialMapConfig;

/// <summary>
/// class
/// </summary>
typedef struct { char _placeHolder_; } easyar_SparseSpatialMap;

/// <summary>
/// class
/// </summary>
typedef struct { char _placeHolder_; } easyar_ImageHelper;

/// <summary>
/// class
/// </summary>
typedef struct { char _placeHolder_; } easyar_CallbackScheduler;

/// <summary>
/// class
/// extends CallbackScheduler
/// </summary>
typedef struct { char _placeHolder_; } easyar_DelayedCallbackScheduler;

/// <summary>
/// class
/// extends CallbackScheduler
/// </summary>
typedef struct { char _placeHolder_; } easyar_ImmediateCallbackScheduler;

typedef enum
{
    easyar_CameraDeviceFocusMode_Normal = 0,
    easyar_CameraDeviceFocusMode_Continousauto = 2,
    easyar_CameraDeviceFocusMode_Infinity = 3,
    easyar_CameraDeviceFocusMode_Macro = 4,
    easyar_CameraDeviceFocusMode_Medium = 5,
} easyar_CameraDeviceFocusMode;

typedef enum
{
    easyar_AndroidCameraApiType_Camera1 = 0,
    easyar_AndroidCameraApiType_Camera2 = 1,
} easyar_AndroidCameraApiType;

typedef enum
{
    easyar_CameraDevicePresetProfile_Photo = 0,
    easyar_CameraDevicePresetProfile_High = 1,
    easyar_CameraDevicePresetProfile_Medium = 2,
    easyar_CameraDevicePresetProfile_Low = 3,
} easyar_CameraDevicePresetProfile;

typedef enum
{
    easyar_CameraState_Unknown = 0x00000000,
    easyar_CameraState_Disconnected = 0x00000001,
    easyar_CameraState_Preempted = 0x00000002,
} easyar_CameraState;

/// <summary>
/// class
/// </summary>
typedef struct { char _placeHolder_; } easyar_CameraDevice;

typedef enum
{
    easyar_CameraDevicePreference_PreferObjectSensing = 0,
    easyar_CameraDevicePreference_PreferSurfaceTracking = 1,
    easyar_CameraDevicePreference_PreferMotionTracking = 2,
} easyar_CameraDevicePreference;

/// <summary>
/// class
/// </summary>
typedef struct { char _placeHolder_; } easyar_CameraDeviceSelector;

/// <summary>
/// class
/// </summary>
typedef struct { char _placeHolder_; } easyar_SignalSink;

/// <summary>
/// class
/// </summary>
typedef struct { char _placeHolder_; } easyar_SignalSource;

/// <summary>
/// class
/// </summary>
typedef struct { char _placeHolder_; } easyar_InputFrameSink;

/// <summary>
/// class
/// </summary>
typedef struct { char _placeHolder_; } easyar_InputFrameSource;

/// <summary>
/// class
/// </summary>
typedef struct { char _placeHolder_; } easyar_OutputFrameSink;

/// <summary>
/// class
/// </summary>
typedef struct { char _placeHolder_; } easyar_OutputFrameSource;

/// <summary>
/// class
/// </summary>
typedef struct { char _placeHolder_; } easyar_FeedbackFrameSink;

/// <summary>
/// class
/// </summary>
typedef struct { char _placeHolder_; } easyar_FeedbackFrameSource;

/// <summary>
/// class
/// </summary>
typedef struct { char _placeHolder_; } easyar_InputFrameFork;

/// <summary>
/// class
/// </summary>
typedef struct { char _placeHolder_; } easyar_OutputFrameFork;

/// <summary>
/// class
/// </summary>
typedef struct { char _placeHolder_; } easyar_OutputFrameJoin;

/// <summary>
/// class
/// </summary>
typedef struct { char _placeHolder_; } easyar_FeedbackFrameFork;

/// <summary>
/// class
/// </summary>
typedef struct { char _placeHolder_; } easyar_InputFrameThrottler;

/// <summary>
/// class
/// </summary>
typedef struct { char _placeHolder_; } easyar_OutputFrameBuffer;

/// <summary>
/// class
/// </summary>
typedef struct { char _placeHolder_; } easyar_InputFrameToOutputFrameAdapter;

/// <summary>
/// class
/// </summary>
typedef struct { char _placeHolder_; } easyar_InputFrameToFeedbackFrameAdapter;

/// <summary>
/// class
/// </summary>
typedef struct { char _placeHolder_; } easyar_Engine;

typedef enum
{
    easyar_InputFrameTrackingStatus_NotTracking = 0,
    easyar_InputFrameTrackingStatus_Tracking = 1,
} easyar_InputFrameTrackingStatus;

/// <summary>
/// class
/// </summary>
typedef struct { char _placeHolder_; } easyar_InputFrame;

/// <summary>
/// class
/// </summary>
typedef struct { char _placeHolder_; } easyar_FrameFilterResult;

/// <summary>
/// class
/// </summary>
typedef struct { char _placeHolder_; } easyar_OutputFrame;

/// <summary>
/// class
/// </summary>
typedef struct { char _placeHolder_; } easyar_FeedbackFrame;

typedef enum
{
    easyar_PermissionStatus_Granted = 0x00000000,
    easyar_PermissionStatus_Denied = 0x00000001,
    easyar_PermissionStatus_Error = 0x00000002,
} easyar_PermissionStatus;

typedef enum
{
    easyar_StorageType_App = 0,
    easyar_StorageType_Assets = 1,
    easyar_StorageType_Absolute = 2,
} easyar_StorageType;

/// <summary>
/// class
/// </summary>
typedef struct { char _placeHolder_; } easyar_Target;

typedef enum
{
    easyar_TargetStatus_Unknown = 0,
    easyar_TargetStatus_Undefined = 1,
    easyar_TargetStatus_Detected = 2,
    easyar_TargetStatus_Tracked = 3,
} easyar_TargetStatus;

/// <summary>
/// class
/// </summary>
typedef struct { char _placeHolder_; } easyar_TargetInstance;

/// <summary>
/// class
/// extends FrameFilterResult
/// </summary>
typedef struct { char _placeHolder_; } easyar_TargetTrackerResult;

/// <summary>
/// class
/// </summary>
typedef struct { char _placeHolder_; } easyar_TextureId;

typedef enum
{
    easyar_VideoStatus_Error = -1,
    easyar_VideoStatus_Ready = 0,
    easyar_VideoStatus_Completed = 1,
} easyar_VideoStatus;

typedef enum
{
    easyar_VideoType_Normal = 0,
    easyar_VideoType_TransparentSideBySide = 1,
    easyar_VideoType_TransparentTopAndBottom = 2,
} easyar_VideoType;

/// <summary>
/// class
/// </summary>
typedef struct { char _placeHolder_; } easyar_VideoPlayer;

/// <summary>
/// class
/// </summary>
typedef struct { char _placeHolder_; } easyar_Buffer;

/// <summary>
/// class
/// </summary>
typedef struct { char _placeHolder_; } easyar_BufferDictionary;

/// <summary>
/// class
/// </summary>
typedef struct { char _placeHolder_; } easyar_BufferPool;

typedef enum
{
    easyar_CameraDeviceType_Default = 0,
    easyar_CameraDeviceType_Back = 1,
    easyar_CameraDeviceType_Front = 2,
} easyar_CameraDeviceType;

/// <summary>
/// class
/// </summary>
typedef struct { char _placeHolder_; } easyar_CameraParameters;

typedef enum
{
    easyar_PixelFormat_Unknown = 0,
    easyar_PixelFormat_Gray = 1,
    easyar_PixelFormat_YUV_NV21 = 2,
    easyar_PixelFormat_YUV_NV12 = 3,
    easyar_PixelFormat_YUV_I420 = 4,
    easyar_PixelFormat_YUV_YV12 = 5,
    easyar_PixelFormat_RGB888 = 6,
    easyar_PixelFormat_BGR888 = 7,
    easyar_PixelFormat_RGBA8888 = 8,
    easyar_PixelFormat_BGRA8888 = 9,
} easyar_PixelFormat;

/// <summary>
/// class
/// </summary>
typedef struct { char _placeHolder_; } easyar_Image;

/// <summary>
/// class
/// </summary>
typedef struct { char _placeHolder_; } easyar_JniUtility;

typedef enum
{
    easyar_LogLevel_Error = 0,
    easyar_LogLevel_Warning = 1,
    easyar_LogLevel_Info = 2,
} easyar_LogLevel;

/// <summary>
/// class
/// </summary>
typedef struct { char _placeHolder_; } easyar_Log;

/// <summary>
/// record
/// </summary>
typedef struct
{
    float data[16];
} easyar_Matrix44F;

/// <summary>
/// record
/// </summary>
typedef struct
{
    float data[9];
} easyar_Matrix33F;

/// <summary>
/// record
/// </summary>
typedef struct
{
    float data[4];
} easyar_Vec4F;

/// <summary>
/// record
/// </summary>
typedef struct
{
    float data[3];
} easyar_Vec3F;

/// <summary>
/// record
/// </summary>
typedef struct
{
    float data[2];
} easyar_Vec2F;

/// <summary>
/// record
/// </summary>
typedef struct
{
    int data[4];
} easyar_Vec4I;

/// <summary>
/// record
/// </summary>
typedef struct
{
    int data[2];
} easyar_Vec2I;

typedef struct { bool has_value; easyar_Buffer * value; } easyar_OptionalOfBuffer;

typedef struct
{
    void * _state;
    void (* func)(void * _state, /* OUT */ easyar_String * * _exception);
    void (* destroy)(void * _state);
} easyar_FunctorOfVoid;

typedef struct { bool has_value; easyar_ObjectTarget * value; } easyar_OptionalOfObjectTarget;

typedef struct { char _placeHolder_; } easyar_ListOfObjectTarget;

typedef struct { char _placeHolder_; } easyar_ListOfVec3F;

typedef struct { char _placeHolder_; } easyar_ListOfTargetInstance;

typedef struct { bool has_value; easyar_Target * value; } easyar_OptionalOfTarget;

typedef struct { bool has_value; easyar_OutputFrame * value; } easyar_OptionalOfOutputFrame;

typedef struct { bool has_value; easyar_FrameFilterResult * value; } easyar_OptionalOfFrameFilterResult;

typedef struct { char _placeHolder_; } easyar_ListOfOptionalOfFrameFilterResult;

typedef struct
{
    void * _state;
    void (* func)(void * _state, easyar_OutputFrame *, /* OUT */ easyar_String * * _exception);
    void (* destroy)(void * _state);
} easyar_FunctorOfVoidFromOutputFrame;

typedef struct { bool has_value; easyar_FunctorOfVoidFromOutputFrame value; } easyar_OptionalOfFunctorOfVoidFromOutputFrame;

typedef struct
{
    void * _state;
    void (* func)(void * _state, easyar_Target *, bool, /* OUT */ easyar_String * * _exception);
    void (* destroy)(void * _state);
} easyar_FunctorOfVoidFromTargetAndBool;

typedef struct { char _placeHolder_; } easyar_ListOfTarget;

typedef struct { bool has_value; easyar_CADTarget * value; } easyar_OptionalOfCADTarget;

typedef struct { char _placeHolder_; } easyar_ListOfCADTarget;

typedef struct
{
    void * _state;
    void (* func)(void * _state, easyar_CloudStatus, easyar_ListOfTarget *, /* OUT */ easyar_String * * _exception);
    void (* destroy)(void * _state);
} easyar_FunctorOfVoidFromCloudStatusAndListOfTarget;

typedef struct { bool has_value; easyar_FunctorOfVoidFromCloudStatusAndListOfTarget value; } easyar_OptionalOfFunctorOfVoidFromCloudStatusAndListOfTarget;

typedef struct { char _placeHolder_; } easyar_ListOfBlockInfo;

typedef struct
{
    void * _state;
    void (* func)(void * _state, easyar_InputFrame *, /* OUT */ easyar_String * * _exception);
    void (* destroy)(void * _state);
} easyar_FunctorOfVoidFromInputFrame;

typedef struct { bool has_value; easyar_FunctorOfVoidFromInputFrame value; } easyar_OptionalOfFunctorOfVoidFromInputFrame;

typedef struct { bool has_value; easyar_ImageTarget * value; } easyar_OptionalOfImageTarget;

typedef struct { char _placeHolder_; } easyar_ListOfImageTarget;

typedef struct { char _placeHolder_; } easyar_ListOfImage;

typedef struct
{
    void * _state;
    void (* func)(void * _state, easyar_PermissionStatus, easyar_String *, /* OUT */ easyar_String * * _exception);
    void (* destroy)(void * _state);
} easyar_FunctorOfVoidFromPermissionStatusAndString;

typedef struct { bool has_value; easyar_FunctorOfVoidFromPermissionStatusAndString value; } easyar_OptionalOfFunctorOfVoidFromPermissionStatusAndString;

typedef struct
{
    void * _state;
    void (* func)(void * _state, easyar_RecordStatus, easyar_String *, /* OUT */ easyar_String * * _exception);
    void (* destroy)(void * _state);
} easyar_FunctorOfVoidFromRecordStatusAndString;

typedef struct { bool has_value; easyar_FunctorOfVoidFromRecordStatusAndString value; } easyar_OptionalOfFunctorOfVoidFromRecordStatusAndString;

typedef struct { char _placeHolder_; } easyar_ListOfPlaneData;

typedef struct
{
    void * _state;
    void (* func)(void * _state, easyar_OptionalOfBuffer, /* OUT */ easyar_String * * _exception);
    void (* destroy)(void * _state);
} easyar_FunctorOfVoidFromOptionalOfBuffer;

typedef struct
{
    void * _state;
    void (* func)(void * _state, bool, /* OUT */ easyar_String * * _exception);
    void (* destroy)(void * _state);
} easyar_FunctorOfVoidFromBool;

typedef struct { bool has_value; easyar_FunctorOfVoidFromBool value; } easyar_OptionalOfFunctorOfVoidFromBool;

typedef struct { bool has_value; easyar_Image * value; } easyar_OptionalOfImage;

typedef struct
{
    void * _state;
    void (* func)(void * _state, easyar_CameraState, /* OUT */ easyar_String * * _exception);
    void (* destroy)(void * _state);
} easyar_FunctorOfVoidFromCameraState;

typedef struct { bool has_value; easyar_FunctorOfVoidFromCameraState value; } easyar_OptionalOfFunctorOfVoidFromCameraState;

typedef struct { bool has_value; easyar_FunctorOfVoid value; } easyar_OptionalOfFunctorOfVoid;

typedef struct
{
    void * _state;
    void (* func)(void * _state, easyar_FeedbackFrame *, /* OUT */ easyar_String * * _exception);
    void (* destroy)(void * _state);
} easyar_FunctorOfVoidFromFeedbackFrame;

typedef struct { bool has_value; easyar_FunctorOfVoidFromFeedbackFrame value; } easyar_OptionalOfFunctorOfVoidFromFeedbackFrame;

typedef struct { char _placeHolder_; } easyar_ListOfOutputFrame;

typedef struct
{
    void * _state;
    void (* func)(void * _state, easyar_ListOfOutputFrame *, /* OUT */ easyar_OutputFrame * *, /* OUT */ easyar_String * * _exception);
    void (* destroy)(void * _state);
} easyar_FunctorOfOutputFrameFromListOfOutputFrame;

typedef struct
{
    void * _state;
    void (* func)(void * _state, easyar_VideoStatus, /* OUT */ easyar_String * * _exception);
    void (* destroy)(void * _state);
} easyar_FunctorOfVoidFromVideoStatus;

typedef struct { bool has_value; easyar_FunctorOfVoidFromVideoStatus value; } easyar_OptionalOfFunctorOfVoidFromVideoStatus;

typedef struct
{
    void * _state;
    void (* func)(void * _state, easyar_LogLevel, easyar_String *, /* OUT */ easyar_String * * _exception);
    void (* destroy)(void * _state);
} easyar_FunctorOfVoidFromLogLevelAndString;

#ifdef __cplusplus
}
#endif

#endif
