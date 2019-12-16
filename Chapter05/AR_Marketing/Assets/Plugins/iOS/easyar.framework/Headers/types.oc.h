//=============================================================================================================================
//
// EasyAR 3.0.1-final-r238a6316e
// Copyright (c) 2015-2019 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#import <Foundation/Foundation.h>

@interface easyar_RefBase : NSObject

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

@end

@class easyar_ObjectTargetParameters;

@class easyar_ObjectTarget;

@class easyar_ObjectTrackerResult;

@class easyar_ObjectTracker;

@class easyar_CADTarget;

@class easyar_CADTrackerResult;

@class easyar_CADTracker;

typedef enum easyar_CloudStatus : NSInteger
{
    easyar_CloudStatus_FoundTargets = 0,
    easyar_CloudStatus_TargetsNotFound = 1,
    easyar_CloudStatus_Reconnecting = 2,
    easyar_CloudStatus_ProtocolError = 3,
} easyar_CloudStatus;

@class easyar_CloudRecognizer;

@class easyar_DenseSpatialMap;

@class easyar_BlockInfo;

@class easyar_SceneMesh;

typedef enum easyar_SurfaceTrackingStatus : NSInteger
{
    easyar_SurfaceTrackingStatus_NotTracking = 0,
    easyar_SurfaceTrackingStatus_BadTracking = 1,
    easyar_SurfaceTrackingStatus_GoodTracking = 2,
} easyar_SurfaceTrackingStatus;

@class easyar_SurfaceTrackerResult;

@class easyar_SurfaceTracker;

typedef enum easyar_MotionTrackingStatus : NSInteger
{
    easyar_MotionTrackingStatus_NotTracking = 0,
    easyar_MotionTrackingStatus_BadTracking = 1,
    easyar_MotionTrackingStatus_GoodTracking = 2,
} easyar_MotionTrackingStatus;

@class easyar_MotionTrackerResult;

@class easyar_MotionTracker;

@class easyar_MotionTrackerOutputFrameToInputFrameAdapter;

@class easyar_ImageTargetParameters;

@class easyar_ImageTarget;

typedef enum easyar_ImageTrackerMode : NSInteger
{
    easyar_ImageTrackerMode_PreferQuality = 0,
    easyar_ImageTrackerMode_PreferPerformance = 1,
} easyar_ImageTrackerMode;

@class easyar_ImageTrackerResult;

@class easyar_ImageTracker;

@class easyar_Recorder;

typedef enum easyar_RecordProfile : NSInteger
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

typedef enum easyar_RecordVideoSize : NSInteger
{
    easyar_RecordVideoSize_Vid1080p = 0x00000002,
    easyar_RecordVideoSize_Vid720p = 0x00000010,
    easyar_RecordVideoSize_Vid480p = 0x00000080,
} easyar_RecordVideoSize;

typedef enum easyar_RecordZoomMode : NSInteger
{
    easyar_RecordZoomMode_NoZoomAndClip = 0x00000000,
    easyar_RecordZoomMode_ZoomInWithAllContent = 0x00000001,
} easyar_RecordZoomMode;

typedef enum easyar_RecordVideoOrientation : NSInteger
{
    easyar_RecordVideoOrientation_Landscape = 0x00000000,
    easyar_RecordVideoOrientation_Portrait = 0x00000001,
} easyar_RecordVideoOrientation;

typedef enum easyar_RecordStatus : NSInteger
{
    easyar_RecordStatus_OnStarted = 0x00000002,
    easyar_RecordStatus_OnStopped = 0x00000004,
    easyar_RecordStatus_FailedToStart = 0x00000202,
    easyar_RecordStatus_FileSucceeded = 0x00000400,
    easyar_RecordStatus_FileFailed = 0x00000401,
    easyar_RecordStatus_LogInfo = 0x00000800,
    easyar_RecordStatus_LogError = 0x00001000,
} easyar_RecordStatus;

@class easyar_RecorderConfiguration;

typedef enum easyar_MapTrackingStatus : NSInteger
{
    easyar_MapTrackingStatus_NotTracking = 0,
    easyar_MapTrackingStatus_Tracking = 1,
} easyar_MapTrackingStatus;

@class easyar_SparseSpatialMapResult;

typedef enum easyar_PlaneType : NSInteger
{
    easyar_PlaneType_Horizontal = 0,
    easyar_PlaneType_Vertical = 1,
} easyar_PlaneType;

@class easyar_PlaneData;

typedef enum easyar_LocalizeConfig : NSInteger
{
    easyar_LocalizeConfig_UntilSuccess = 0,
    easyar_LocalizeConfig_Keep = 1,
    easyar_LocalizeConfig_Once = 2,
    easyar_LocalizeConfig_KeepUpdate = 3,
} easyar_LocalizeConfig;

typedef enum easyar_MapConfig : NSInteger
{
    easyar_MapConfig_NotExtend = 0,
    easyar_MapConfig_Extend = 1,
} easyar_MapConfig;

@class easyar_SparseSpatialMapConfig;

@class easyar_SparseSpatialMap;

@class easyar_ImageHelper;

@class easyar_CallbackScheduler;

@class easyar_DelayedCallbackScheduler;

@class easyar_ImmediateCallbackScheduler;

typedef enum easyar_CameraDeviceFocusMode : NSInteger
{
    easyar_CameraDeviceFocusMode_Normal = 0,
    easyar_CameraDeviceFocusMode_Continousauto = 2,
    easyar_CameraDeviceFocusMode_Infinity = 3,
    easyar_CameraDeviceFocusMode_Macro = 4,
    easyar_CameraDeviceFocusMode_Medium = 5,
} easyar_CameraDeviceFocusMode;

typedef enum easyar_AndroidCameraApiType : NSInteger
{
    easyar_AndroidCameraApiType_Camera1 = 0,
    easyar_AndroidCameraApiType_Camera2 = 1,
} easyar_AndroidCameraApiType;

typedef enum easyar_CameraDevicePresetProfile : NSInteger
{
    easyar_CameraDevicePresetProfile_Photo = 0,
    easyar_CameraDevicePresetProfile_High = 1,
    easyar_CameraDevicePresetProfile_Medium = 2,
    easyar_CameraDevicePresetProfile_Low = 3,
} easyar_CameraDevicePresetProfile;

typedef enum easyar_CameraState : NSInteger
{
    easyar_CameraState_Unknown = 0x00000000,
    easyar_CameraState_Disconnected = 0x00000001,
    easyar_CameraState_Preempted = 0x00000002,
} easyar_CameraState;

@class easyar_CameraDevice;

typedef enum easyar_CameraDevicePreference : NSInteger
{
    easyar_CameraDevicePreference_PreferObjectSensing = 0,
    easyar_CameraDevicePreference_PreferSurfaceTracking = 1,
    easyar_CameraDevicePreference_PreferMotionTracking = 2,
} easyar_CameraDevicePreference;

@class easyar_CameraDeviceSelector;

@class easyar_SignalSink;

@class easyar_SignalSource;

@class easyar_InputFrameSink;

@class easyar_InputFrameSource;

@class easyar_OutputFrameSink;

@class easyar_OutputFrameSource;

@class easyar_FeedbackFrameSink;

@class easyar_FeedbackFrameSource;

@class easyar_InputFrameFork;

@class easyar_OutputFrameFork;

@class easyar_OutputFrameJoin;

@class easyar_FeedbackFrameFork;

@class easyar_InputFrameThrottler;

@class easyar_OutputFrameBuffer;

@class easyar_InputFrameToOutputFrameAdapter;

@class easyar_InputFrameToFeedbackFrameAdapter;

@class easyar_Engine;

typedef enum easyar_InputFrameTrackingStatus : NSInteger
{
    easyar_InputFrameTrackingStatus_NotTracking = 0,
    easyar_InputFrameTrackingStatus_Tracking = 1,
} easyar_InputFrameTrackingStatus;

@class easyar_InputFrame;

@class easyar_FrameFilterResult;

@class easyar_OutputFrame;

@class easyar_FeedbackFrame;

typedef enum easyar_PermissionStatus : NSInteger
{
    easyar_PermissionStatus_Granted = 0x00000000,
    easyar_PermissionStatus_Denied = 0x00000001,
    easyar_PermissionStatus_Error = 0x00000002,
} easyar_PermissionStatus;

typedef enum easyar_StorageType : NSInteger
{
    easyar_StorageType_App = 0,
    easyar_StorageType_Assets = 1,
    easyar_StorageType_Absolute = 2,
} easyar_StorageType;

@class easyar_Target;

typedef enum easyar_TargetStatus : NSInteger
{
    easyar_TargetStatus_Unknown = 0,
    easyar_TargetStatus_Undefined = 1,
    easyar_TargetStatus_Detected = 2,
    easyar_TargetStatus_Tracked = 3,
} easyar_TargetStatus;

@class easyar_TargetInstance;

@class easyar_TargetTrackerResult;

@class easyar_TextureId;

typedef enum easyar_VideoStatus : NSInteger
{
    easyar_VideoStatus_Error = -1,
    easyar_VideoStatus_Ready = 0,
    easyar_VideoStatus_Completed = 1,
} easyar_VideoStatus;

typedef enum easyar_VideoType : NSInteger
{
    easyar_VideoType_Normal = 0,
    easyar_VideoType_TransparentSideBySide = 1,
    easyar_VideoType_TransparentTopAndBottom = 2,
} easyar_VideoType;

@class easyar_VideoPlayer;

@class easyar_Buffer;

@class easyar_BufferDictionary;

@class easyar_BufferPool;

typedef enum easyar_CameraDeviceType : NSInteger
{
    easyar_CameraDeviceType_Default = 0,
    easyar_CameraDeviceType_Back = 1,
    easyar_CameraDeviceType_Front = 2,
} easyar_CameraDeviceType;

@class easyar_CameraParameters;

typedef enum easyar_PixelFormat : NSInteger
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

@class easyar_Image;

@class easyar_JniUtility;

typedef enum easyar_LogLevel : NSInteger
{
    easyar_LogLevel_Error = 0,
    easyar_LogLevel_Warning = 1,
    easyar_LogLevel_Info = 2,
} easyar_LogLevel;

@class easyar_Log;

@class easyar_Matrix44F;

@class easyar_Matrix33F;

@class easyar_Vec4F;

@class easyar_Vec3F;

@class easyar_Vec2F;

@class easyar_Vec4I;

@class easyar_Vec2I;
