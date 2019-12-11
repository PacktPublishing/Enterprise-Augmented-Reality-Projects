//=============================================================================================================================
//
// EasyAR 3.0.1-final-r238a6316e
// Copyright (c) 2015-2019 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#ifndef __EASYAR_TYPES_HXX__
#define __EASYAR_TYPES_HXX__

#include "easyar/types.h"
#include <cstddef>
#include <stdexcept>

namespace easyar {

class String
{
private:
    easyar_String * cdata_;
    virtual String & operator=(const String & data) { return *this; } //deleted
public:
    String(easyar_String * cdata)
        : cdata_(cdata)
    {
    }
    virtual ~String()
    {
        if (cdata_) {
            easyar_String__dtor(cdata_);
            cdata_ = NULL;
        }
    }

    String(const String & data)
        : cdata_(static_cast<easyar_String *>(NULL))
    {
        easyar_String_copy(data.cdata_, &cdata_);
    }
    const easyar_String * get_cdata() const
    {
        return cdata_;
    }
    easyar_String * get_cdata()
    {
        return cdata_;
    }

    static void from_utf8(const char * begin, const char * end, /* OUT */ String * * Return)
    {
        easyar_String * _return_value_ = NULL;
        easyar_String_from_utf8(begin, end, &_return_value_);
        *Return = _return_value_ == NULL ? NULL : new String(_return_value_);
    }
    static void from_utf8_begin(const char * begin, /* OUT */ String * * Return)
    {
        easyar_String * _return_value_ = NULL;
        easyar_String_from_utf8_begin(begin, &_return_value_);
        *Return = _return_value_ == NULL ? NULL : new String(_return_value_);
    }
    const char * begin()
    {
        return easyar_String_begin(cdata_);
    }
    const char * end()
    {
        return easyar_String_end(cdata_);
    }
};

class ObjectTargetParameters;

class ObjectTarget;

class ObjectTrackerResult;

class ObjectTracker;

class CADTarget;

class CADTrackerResult;

class CADTracker;

enum CloudStatus
{
    CloudStatus_FoundTargets = 0,
    CloudStatus_TargetsNotFound = 1,
    CloudStatus_Reconnecting = 2,
    CloudStatus_ProtocolError = 3,
};

class CloudRecognizer;

class DenseSpatialMap;

struct BlockInfo;

class SceneMesh;

enum SurfaceTrackingStatus
{
    SurfaceTrackingStatus_NotTracking = 0,
    SurfaceTrackingStatus_BadTracking = 1,
    SurfaceTrackingStatus_GoodTracking = 2,
};

class SurfaceTrackerResult;

class SurfaceTracker;

enum MotionTrackingStatus
{
    MotionTrackingStatus_NotTracking = 0,
    MotionTrackingStatus_BadTracking = 1,
    MotionTrackingStatus_GoodTracking = 2,
};

class MotionTrackerResult;

class MotionTracker;

class MotionTrackerOutputFrameToInputFrameAdapter;

class ImageTargetParameters;

class ImageTarget;

enum ImageTrackerMode
{
    ImageTrackerMode_PreferQuality = 0,
    ImageTrackerMode_PreferPerformance = 1,
};

class ImageTrackerResult;

class ImageTracker;

class Recorder;

enum RecordProfile
{
    RecordProfile_Quality_1080P_Low = 0x00000001,
    RecordProfile_Quality_1080P_Middle = 0x00000002,
    RecordProfile_Quality_1080P_High = 0x00000004,
    RecordProfile_Quality_720P_Low = 0x00000008,
    RecordProfile_Quality_720P_Middle = 0x00000010,
    RecordProfile_Quality_720P_High = 0x00000020,
    RecordProfile_Quality_480P_Low = 0x00000040,
    RecordProfile_Quality_480P_Middle = 0x00000080,
    RecordProfile_Quality_480P_High = 0x00000100,
    RecordProfile_Quality_Default = 0x00000010,
};

enum RecordVideoSize
{
    RecordVideoSize_Vid1080p = 0x00000002,
    RecordVideoSize_Vid720p = 0x00000010,
    RecordVideoSize_Vid480p = 0x00000080,
};

enum RecordZoomMode
{
    RecordZoomMode_NoZoomAndClip = 0x00000000,
    RecordZoomMode_ZoomInWithAllContent = 0x00000001,
};

enum RecordVideoOrientation
{
    RecordVideoOrientation_Landscape = 0x00000000,
    RecordVideoOrientation_Portrait = 0x00000001,
};

enum RecordStatus
{
    RecordStatus_OnStarted = 0x00000002,
    RecordStatus_OnStopped = 0x00000004,
    RecordStatus_FailedToStart = 0x00000202,
    RecordStatus_FileSucceeded = 0x00000400,
    RecordStatus_FileFailed = 0x00000401,
    RecordStatus_LogInfo = 0x00000800,
    RecordStatus_LogError = 0x00001000,
};

class RecorderConfiguration;

enum MapTrackingStatus
{
    MapTrackingStatus_NotTracking = 0,
    MapTrackingStatus_Tracking = 1,
};

class SparseSpatialMapResult;

enum PlaneType
{
    PlaneType_Horizontal = 0,
    PlaneType_Vertical = 1,
};

class PlaneData;

enum LocalizeConfig
{
    LocalizeConfig_UntilSuccess = 0,
    LocalizeConfig_Keep = 1,
    LocalizeConfig_Once = 2,
    LocalizeConfig_KeepUpdate = 3,
};

enum MapConfig
{
    MapConfig_NotExtend = 0,
    MapConfig_Extend = 1,
};

class SparseSpatialMapConfig;

class SparseSpatialMap;

class ImageHelper;

class CallbackScheduler;

class DelayedCallbackScheduler;

class ImmediateCallbackScheduler;

enum CameraDeviceFocusMode
{
    CameraDeviceFocusMode_Normal = 0,
    CameraDeviceFocusMode_Continousauto = 2,
    CameraDeviceFocusMode_Infinity = 3,
    CameraDeviceFocusMode_Macro = 4,
    CameraDeviceFocusMode_Medium = 5,
};

enum AndroidCameraApiType
{
    AndroidCameraApiType_Camera1 = 0,
    AndroidCameraApiType_Camera2 = 1,
};

enum CameraDevicePresetProfile
{
    CameraDevicePresetProfile_Photo = 0,
    CameraDevicePresetProfile_High = 1,
    CameraDevicePresetProfile_Medium = 2,
    CameraDevicePresetProfile_Low = 3,
};

enum CameraState
{
    CameraState_Unknown = 0x00000000,
    CameraState_Disconnected = 0x00000001,
    CameraState_Preempted = 0x00000002,
};

class CameraDevice;

enum CameraDevicePreference
{
    CameraDevicePreference_PreferObjectSensing = 0,
    CameraDevicePreference_PreferSurfaceTracking = 1,
    CameraDevicePreference_PreferMotionTracking = 2,
};

class CameraDeviceSelector;

class SignalSink;

class SignalSource;

class InputFrameSink;

class InputFrameSource;

class OutputFrameSink;

class OutputFrameSource;

class FeedbackFrameSink;

class FeedbackFrameSource;

class InputFrameFork;

class OutputFrameFork;

class OutputFrameJoin;

class FeedbackFrameFork;

class InputFrameThrottler;

class OutputFrameBuffer;

class InputFrameToOutputFrameAdapter;

class InputFrameToFeedbackFrameAdapter;

class Engine;

enum InputFrameTrackingStatus
{
    InputFrameTrackingStatus_NotTracking = 0,
    InputFrameTrackingStatus_Tracking = 1,
};

class InputFrame;

class FrameFilterResult;

class OutputFrame;

class FeedbackFrame;

enum PermissionStatus
{
    PermissionStatus_Granted = 0x00000000,
    PermissionStatus_Denied = 0x00000001,
    PermissionStatus_Error = 0x00000002,
};

enum StorageType
{
    StorageType_App = 0,
    StorageType_Assets = 1,
    StorageType_Absolute = 2,
};

class Target;

enum TargetStatus
{
    TargetStatus_Unknown = 0,
    TargetStatus_Undefined = 1,
    TargetStatus_Detected = 2,
    TargetStatus_Tracked = 3,
};

class TargetInstance;

class TargetTrackerResult;

class TextureId;

enum VideoStatus
{
    VideoStatus_Error = -1,
    VideoStatus_Ready = 0,
    VideoStatus_Completed = 1,
};

enum VideoType
{
    VideoType_Normal = 0,
    VideoType_TransparentSideBySide = 1,
    VideoType_TransparentTopAndBottom = 2,
};

class VideoPlayer;

class Buffer;

class BufferDictionary;

class BufferPool;

enum CameraDeviceType
{
    CameraDeviceType_Default = 0,
    CameraDeviceType_Back = 1,
    CameraDeviceType_Front = 2,
};

class CameraParameters;

enum PixelFormat
{
    PixelFormat_Unknown = 0,
    PixelFormat_Gray = 1,
    PixelFormat_YUV_NV21 = 2,
    PixelFormat_YUV_NV12 = 3,
    PixelFormat_YUV_I420 = 4,
    PixelFormat_YUV_YV12 = 5,
    PixelFormat_RGB888 = 6,
    PixelFormat_BGR888 = 7,
    PixelFormat_RGBA8888 = 8,
    PixelFormat_BGRA8888 = 9,
};

class Image;

class JniUtility;

enum LogLevel
{
    LogLevel_Error = 0,
    LogLevel_Warning = 1,
    LogLevel_Info = 2,
};

class Log;

struct Matrix44F;

struct Matrix33F;

struct Vec4F;

struct Vec3F;

struct Vec2F;

struct Vec4I;

struct Vec2I;

struct OptionalOfBuffer;

struct FunctorOfVoid;

struct OptionalOfObjectTarget;

class ListOfObjectTarget;

class ListOfVec3F;

class ListOfTargetInstance;

struct OptionalOfTarget;

struct OptionalOfOutputFrame;

class ListOfOptionalOfFrameFilterResult;

struct OptionalOfFrameFilterResult;

struct OptionalOfFunctorOfVoidFromOutputFrame;

struct FunctorOfVoidFromOutputFrame;

struct FunctorOfVoidFromTargetAndBool;

class ListOfTarget;

struct OptionalOfCADTarget;

class ListOfCADTarget;

struct OptionalOfFunctorOfVoidFromCloudStatusAndListOfTarget;

struct FunctorOfVoidFromCloudStatusAndListOfTarget;

class ListOfBlockInfo;

struct OptionalOfFunctorOfVoidFromInputFrame;

struct FunctorOfVoidFromInputFrame;

struct OptionalOfImageTarget;

class ListOfImageTarget;

class ListOfImage;

struct OptionalOfFunctorOfVoidFromPermissionStatusAndString;

struct FunctorOfVoidFromPermissionStatusAndString;

struct OptionalOfFunctorOfVoidFromRecordStatusAndString;

struct FunctorOfVoidFromRecordStatusAndString;

class ListOfPlaneData;

struct FunctorOfVoidFromOptionalOfBuffer;

struct OptionalOfFunctorOfVoidFromBool;

struct FunctorOfVoidFromBool;

struct OptionalOfImage;

struct OptionalOfFunctorOfVoidFromCameraState;

struct FunctorOfVoidFromCameraState;

struct OptionalOfFunctorOfVoid;

struct OptionalOfFunctorOfVoidFromFeedbackFrame;

struct FunctorOfVoidFromFeedbackFrame;

struct FunctorOfOutputFrameFromListOfOutputFrame;

class ListOfOutputFrame;

struct OptionalOfFunctorOfVoidFromVideoStatus;

struct FunctorOfVoidFromVideoStatus;

struct FunctorOfVoidFromLogLevelAndString;

}

#endif
