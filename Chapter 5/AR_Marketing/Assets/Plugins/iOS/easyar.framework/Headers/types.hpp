//=============================================================================================================================
//
// EasyAR 3.0.1-final-r238a6316e
// Copyright (c) 2015-2019 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#pragma once

#include "easyar/types.h"
#include <cstddef>
#include <optional>
#include <memory>
#include <string>
#include <array>
#include <vector>
#include <functional>
#include <stdexcept>
#include <type_traits>

#if defined(_DECLARATION_ONLY_) || defined(_IMPLEMENTATION_ONLY_)
#   define _INLINE_SPECIFIER_
#else
#   define _INLINE_SPECIFIER_ inline
#endif

#ifndef _IMPLEMENTATION_ONLY_

namespace easyar {

class ObjectTargetParameters;

class ObjectTarget;

class ObjectTrackerResult;

class ObjectTracker;

class CADTarget;

class CADTrackerResult;

class CADTracker;

enum class CloudStatus
{
    FoundTargets = 0,
    TargetsNotFound = 1,
    Reconnecting = 2,
    ProtocolError = 3,
};

class CloudRecognizer;

class DenseSpatialMap;

struct BlockInfo;

class SceneMesh;

enum class SurfaceTrackingStatus
{
    NotTracking = 0,
    BadTracking = 1,
    GoodTracking = 2,
};

class SurfaceTrackerResult;

class SurfaceTracker;

enum class MotionTrackingStatus
{
    NotTracking = 0,
    BadTracking = 1,
    GoodTracking = 2,
};

class MotionTrackerResult;

class MotionTracker;

class MotionTrackerOutputFrameToInputFrameAdapter;

class ImageTargetParameters;

class ImageTarget;

enum class ImageTrackerMode
{
    PreferQuality = 0,
    PreferPerformance = 1,
};

class ImageTrackerResult;

class ImageTracker;

class Recorder;

enum class RecordProfile
{
    Quality_1080P_Low = 0x00000001,
    Quality_1080P_Middle = 0x00000002,
    Quality_1080P_High = 0x00000004,
    Quality_720P_Low = 0x00000008,
    Quality_720P_Middle = 0x00000010,
    Quality_720P_High = 0x00000020,
    Quality_480P_Low = 0x00000040,
    Quality_480P_Middle = 0x00000080,
    Quality_480P_High = 0x00000100,
    Quality_Default = 0x00000010,
};

enum class RecordVideoSize
{
    Vid1080p = 0x00000002,
    Vid720p = 0x00000010,
    Vid480p = 0x00000080,
};

enum class RecordZoomMode
{
    NoZoomAndClip = 0x00000000,
    ZoomInWithAllContent = 0x00000001,
};

enum class RecordVideoOrientation
{
    Landscape = 0x00000000,
    Portrait = 0x00000001,
};

enum class RecordStatus
{
    OnStarted = 0x00000002,
    OnStopped = 0x00000004,
    FailedToStart = 0x00000202,
    FileSucceeded = 0x00000400,
    FileFailed = 0x00000401,
    LogInfo = 0x00000800,
    LogError = 0x00001000,
};

class RecorderConfiguration;

enum class MapTrackingStatus
{
    NotTracking = 0,
    Tracking = 1,
};

class SparseSpatialMapResult;

enum class PlaneType
{
    Horizontal = 0,
    Vertical = 1,
};

class PlaneData;

enum class LocalizeConfig
{
    UntilSuccess = 0,
    Keep = 1,
    Once = 2,
    KeepUpdate = 3,
};

enum class MapConfig
{
    NotExtend = 0,
    Extend = 1,
};

class SparseSpatialMapConfig;

class SparseSpatialMap;

class ImageHelper;

class CallbackScheduler;

class DelayedCallbackScheduler;

class ImmediateCallbackScheduler;

enum class CameraDeviceFocusMode
{
    Normal = 0,
    Continousauto = 2,
    Infinity = 3,
    Macro = 4,
    Medium = 5,
};

enum class AndroidCameraApiType
{
    Camera1 = 0,
    Camera2 = 1,
};

enum class CameraDevicePresetProfile
{
    Photo = 0,
    High = 1,
    Medium = 2,
    Low = 3,
};

enum class CameraState
{
    Unknown = 0x00000000,
    Disconnected = 0x00000001,
    Preempted = 0x00000002,
};

class CameraDevice;

enum class CameraDevicePreference
{
    PreferObjectSensing = 0,
    PreferSurfaceTracking = 1,
    PreferMotionTracking = 2,
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

enum class InputFrameTrackingStatus
{
    NotTracking = 0,
    Tracking = 1,
};

class InputFrame;

class FrameFilterResult;

class OutputFrame;

class FeedbackFrame;

enum class PermissionStatus
{
    Granted = 0x00000000,
    Denied = 0x00000001,
    Error = 0x00000002,
};

enum class StorageType
{
    App = 0,
    Assets = 1,
    Absolute = 2,
};

class Target;

enum class TargetStatus
{
    Unknown = 0,
    Undefined = 1,
    Detected = 2,
    Tracked = 3,
};

class TargetInstance;

class TargetTrackerResult;

class TextureId;

enum class VideoStatus
{
    Error = -1,
    Ready = 0,
    Completed = 1,
};

enum class VideoType
{
    Normal = 0,
    TransparentSideBySide = 1,
    TransparentTopAndBottom = 2,
};

class VideoPlayer;

class Buffer;

class BufferDictionary;

class BufferPool;

enum class CameraDeviceType
{
    Default = 0,
    Back = 1,
    Front = 2,
};

class CameraParameters;

enum class PixelFormat
{
    Unknown = 0,
    Gray = 1,
    YUV_NV21 = 2,
    YUV_NV12 = 3,
    YUV_I420 = 4,
    YUV_YV12 = 5,
    RGB888 = 6,
    BGR888 = 7,
    RGBA8888 = 8,
    BGRA8888 = 9,
};

class Image;

class JniUtility;

enum class LogLevel
{
    Error = 0,
    Warning = 1,
    Info = 2,
};

class Log;

struct Matrix44F;

struct Matrix33F;

struct Vec4F;

struct Vec3F;

struct Vec2F;

struct Vec4I;

struct Vec2I;

class ObjectTargetParameters
{
protected:
    std::shared_ptr<easyar_ObjectTargetParameters> cdata_;
    void init_cdata(std::shared_ptr<easyar_ObjectTargetParameters> cdata);
    ObjectTargetParameters & operator=(const ObjectTargetParameters & data) = delete;
public:
    ObjectTargetParameters(std::shared_ptr<easyar_ObjectTargetParameters> cdata);
    virtual ~ObjectTargetParameters();

    std::shared_ptr<easyar_ObjectTargetParameters> get_cdata();
    static std::shared_ptr<ObjectTargetParameters> from_cdata(std::shared_ptr<easyar_ObjectTargetParameters> cdata);

    ObjectTargetParameters();
    std::shared_ptr<BufferDictionary> bufferDictionary();
    void setBufferDictionary(std::shared_ptr<BufferDictionary> bufferDictionary);
    std::string objPath();
    void setObjPath(std::string objPath);
    std::string name();
    void setName(std::string name);
    std::string uid();
    void setUid(std::string uid);
    std::string meta();
    void setMeta(std::string meta);
    float scale();
    void setScale(float size);
};

class Target
{
protected:
    std::shared_ptr<easyar_Target> cdata_;
    void init_cdata(std::shared_ptr<easyar_Target> cdata);
    Target & operator=(const Target & data) = delete;
public:
    Target(std::shared_ptr<easyar_Target> cdata);
    virtual ~Target();

    std::shared_ptr<easyar_Target> get_cdata();
    static std::shared_ptr<Target> from_cdata(std::shared_ptr<easyar_Target> cdata);

    int runtimeID();
    std::string uid();
    std::string name();
    void setName(std::string name);
    std::string meta();
    void setMeta(std::string data);
};

class ObjectTarget : public Target
{
protected:
    std::shared_ptr<easyar_ObjectTarget> cdata_;
    void init_cdata(std::shared_ptr<easyar_ObjectTarget> cdata);
    ObjectTarget & operator=(const ObjectTarget & data) = delete;
public:
    ObjectTarget(std::shared_ptr<easyar_ObjectTarget> cdata);
    virtual ~ObjectTarget();

    std::shared_ptr<easyar_ObjectTarget> get_cdata();
    static std::shared_ptr<ObjectTarget> from_cdata(std::shared_ptr<easyar_ObjectTarget> cdata);

    ObjectTarget();
    static std::optional<std::shared_ptr<ObjectTarget>> createFromParameters(std::shared_ptr<ObjectTargetParameters> parameters);
    static std::optional<std::shared_ptr<ObjectTarget>> createFromObjectFile(std::string path, StorageType storageType, std::string name, std::string uid, std::string meta, float scale);
    static std::vector<std::shared_ptr<ObjectTarget>> setupAll(std::string path, StorageType storageType);
    float scale();
    std::vector<Vec3F> boundingBox();
    bool setScale(float scale);
    int runtimeID();
    std::string uid();
    std::string name();
    void setName(std::string name);
    std::string meta();
    void setMeta(std::string data);
};

class FrameFilterResult
{
protected:
    std::shared_ptr<easyar_FrameFilterResult> cdata_;
    void init_cdata(std::shared_ptr<easyar_FrameFilterResult> cdata);
    FrameFilterResult & operator=(const FrameFilterResult & data) = delete;
public:
    FrameFilterResult(std::shared_ptr<easyar_FrameFilterResult> cdata);
    virtual ~FrameFilterResult();

    std::shared_ptr<easyar_FrameFilterResult> get_cdata();
    static std::shared_ptr<FrameFilterResult> from_cdata(std::shared_ptr<easyar_FrameFilterResult> cdata);

};

class TargetTrackerResult : public FrameFilterResult
{
protected:
    std::shared_ptr<easyar_TargetTrackerResult> cdata_;
    void init_cdata(std::shared_ptr<easyar_TargetTrackerResult> cdata);
    TargetTrackerResult & operator=(const TargetTrackerResult & data) = delete;
public:
    TargetTrackerResult(std::shared_ptr<easyar_TargetTrackerResult> cdata);
    virtual ~TargetTrackerResult();

    std::shared_ptr<easyar_TargetTrackerResult> get_cdata();
    static std::shared_ptr<TargetTrackerResult> from_cdata(std::shared_ptr<easyar_TargetTrackerResult> cdata);

    std::vector<std::shared_ptr<TargetInstance>> targetInstances();
    void setTargetInstances(std::vector<std::shared_ptr<TargetInstance>> instances);
};

class ObjectTrackerResult : public TargetTrackerResult
{
protected:
    std::shared_ptr<easyar_ObjectTrackerResult> cdata_;
    void init_cdata(std::shared_ptr<easyar_ObjectTrackerResult> cdata);
    ObjectTrackerResult & operator=(const ObjectTrackerResult & data) = delete;
public:
    ObjectTrackerResult(std::shared_ptr<easyar_ObjectTrackerResult> cdata);
    virtual ~ObjectTrackerResult();

    std::shared_ptr<easyar_ObjectTrackerResult> get_cdata();
    static std::shared_ptr<ObjectTrackerResult> from_cdata(std::shared_ptr<easyar_ObjectTrackerResult> cdata);

    std::vector<std::shared_ptr<TargetInstance>> targetInstances();
    void setTargetInstances(std::vector<std::shared_ptr<TargetInstance>> instances);
};

class ObjectTracker
{
protected:
    std::shared_ptr<easyar_ObjectTracker> cdata_;
    void init_cdata(std::shared_ptr<easyar_ObjectTracker> cdata);
    ObjectTracker & operator=(const ObjectTracker & data) = delete;
public:
    ObjectTracker(std::shared_ptr<easyar_ObjectTracker> cdata);
    virtual ~ObjectTracker();

    std::shared_ptr<easyar_ObjectTracker> get_cdata();
    static std::shared_ptr<ObjectTracker> from_cdata(std::shared_ptr<easyar_ObjectTracker> cdata);

    static bool isAvailable();
    std::shared_ptr<FeedbackFrameSink> feedbackFrameSink();
    std::shared_ptr<OutputFrameSource> outputFrameSource();
    static std::shared_ptr<ObjectTracker> create();
    bool start();
    void stop();
    void close();
    void loadTarget(std::shared_ptr<Target> target, std::shared_ptr<CallbackScheduler> callbackScheduler, std::function<void(std::shared_ptr<Target>, bool)> callback);
    void unloadTarget(std::shared_ptr<Target> target, std::shared_ptr<CallbackScheduler> callbackScheduler, std::function<void(std::shared_ptr<Target>, bool)> callback);
    std::vector<std::shared_ptr<Target>> targets();
    bool setSimultaneousNum(int num);
    int simultaneousNum();
};

class CADTarget : public Target
{
protected:
    std::shared_ptr<easyar_CADTarget> cdata_;
    void init_cdata(std::shared_ptr<easyar_CADTarget> cdata);
    CADTarget & operator=(const CADTarget & data) = delete;
public:
    CADTarget(std::shared_ptr<easyar_CADTarget> cdata);
    virtual ~CADTarget();

    std::shared_ptr<easyar_CADTarget> get_cdata();
    static std::shared_ptr<CADTarget> from_cdata(std::shared_ptr<easyar_CADTarget> cdata);

    CADTarget();
    static std::optional<std::shared_ptr<CADTarget>> createFromUnity(std::shared_ptr<Buffer> vertices, std::shared_ptr<Buffer> faces, Matrix44F transform, float localScale);
    void updateTransform(Matrix44F transform, float localScale);
    void updateTrackConfig(float threshContrast, float threshConsist, float threshQuality);
    static std::optional<std::shared_ptr<CADTarget>> createFromObjectFile(std::string path, StorageType storageType, std::string name, std::string uid, std::string meta, float scale);
    static std::vector<std::shared_ptr<CADTarget>> setupAll(std::string path, StorageType storageType);
    float scale();
    std::vector<Vec3F> boundingBox();
    std::vector<Vec3F> boundingBoxGL();
    bool setScale(float scale);
    int runtimeID();
    std::string uid();
    std::string name();
    void setName(std::string name);
    std::string meta();
    void setMeta(std::string data);
};

class CADTrackerResult : public TargetTrackerResult
{
protected:
    std::shared_ptr<easyar_CADTrackerResult> cdata_;
    void init_cdata(std::shared_ptr<easyar_CADTrackerResult> cdata);
    CADTrackerResult & operator=(const CADTrackerResult & data) = delete;
public:
    CADTrackerResult(std::shared_ptr<easyar_CADTrackerResult> cdata);
    virtual ~CADTrackerResult();

    std::shared_ptr<easyar_CADTrackerResult> get_cdata();
    static std::shared_ptr<CADTrackerResult> from_cdata(std::shared_ptr<easyar_CADTrackerResult> cdata);

    std::vector<std::shared_ptr<TargetInstance>> targetInstances();
    void setTargetInstances(std::vector<std::shared_ptr<TargetInstance>> instances);
};

class CADTracker
{
protected:
    std::shared_ptr<easyar_CADTracker> cdata_;
    void init_cdata(std::shared_ptr<easyar_CADTracker> cdata);
    CADTracker & operator=(const CADTracker & data) = delete;
public:
    CADTracker(std::shared_ptr<easyar_CADTracker> cdata);
    virtual ~CADTracker();

    std::shared_ptr<easyar_CADTracker> get_cdata();
    static std::shared_ptr<CADTracker> from_cdata(std::shared_ptr<easyar_CADTracker> cdata);

    static bool isAvailable();
    std::shared_ptr<FeedbackFrameSink> feedbackFrameSink();
    std::shared_ptr<OutputFrameSource> outputFrameSource();
    static std::shared_ptr<CADTracker> create();
    bool start();
    void stop();
    void close();
    void loadTarget(std::shared_ptr<Target> target, std::shared_ptr<CallbackScheduler> callbackScheduler, std::function<void(std::shared_ptr<Target>, bool)> callback);
    void unloadTarget(std::shared_ptr<Target> target, std::shared_ptr<CallbackScheduler> callbackScheduler, std::function<void(std::shared_ptr<Target>, bool)> callback);
    std::vector<std::shared_ptr<Target>> targets();
};

class CloudRecognizer
{
protected:
    std::shared_ptr<easyar_CloudRecognizer> cdata_;
    void init_cdata(std::shared_ptr<easyar_CloudRecognizer> cdata);
    CloudRecognizer & operator=(const CloudRecognizer & data) = delete;
public:
    CloudRecognizer(std::shared_ptr<easyar_CloudRecognizer> cdata);
    virtual ~CloudRecognizer();

    std::shared_ptr<easyar_CloudRecognizer> get_cdata();
    static std::shared_ptr<CloudRecognizer> from_cdata(std::shared_ptr<easyar_CloudRecognizer> cdata);

    static bool isAvailable();
    std::shared_ptr<InputFrameSink> inputFrameSink();
    static std::shared_ptr<CloudRecognizer> create(std::string server, std::string appKey, std::string appSecret, std::shared_ptr<CallbackScheduler> callbackScheduler, std::optional<std::function<void(CloudStatus, std::vector<std::shared_ptr<Target>>)>> callback);
    bool start();
    void stop();
    void close();
};

class DenseSpatialMap
{
protected:
    std::shared_ptr<easyar_DenseSpatialMap> cdata_;
    void init_cdata(std::shared_ptr<easyar_DenseSpatialMap> cdata);
    DenseSpatialMap & operator=(const DenseSpatialMap & data) = delete;
public:
    DenseSpatialMap(std::shared_ptr<easyar_DenseSpatialMap> cdata);
    virtual ~DenseSpatialMap();

    std::shared_ptr<easyar_DenseSpatialMap> get_cdata();
    static std::shared_ptr<DenseSpatialMap> from_cdata(std::shared_ptr<easyar_DenseSpatialMap> cdata);

    static bool isAvailable();
    std::shared_ptr<InputFrameSink> inputFrameSink();
    static std::shared_ptr<DenseSpatialMap> create();
    bool start();
    void stop();
    void close();
    std::string saveMap();
    std::shared_ptr<SceneMesh> getMesh();
    bool updateSceneMesh(bool updateMeshAll);
};

/// <summary>
/// record
/// </summary>
struct BlockInfo
{
    int x_;
    int y_;
    int z_;
    int numOfVertex_;
    int startPointOfVertex_;
    int numOfIndex_;
    int startPointOfIndex_;
    int age_;
};

class SceneMesh
{
protected:
    std::shared_ptr<easyar_SceneMesh> cdata_;
    void init_cdata(std::shared_ptr<easyar_SceneMesh> cdata);
    SceneMesh & operator=(const SceneMesh & data) = delete;
public:
    SceneMesh(std::shared_ptr<easyar_SceneMesh> cdata);
    virtual ~SceneMesh();

    std::shared_ptr<easyar_SceneMesh> get_cdata();
    static std::shared_ptr<SceneMesh> from_cdata(std::shared_ptr<easyar_SceneMesh> cdata);

    SceneMesh();
    int getNumOfVertexAll();
    int getNumOfIndexAll();
    std::shared_ptr<Buffer> getVerticesAll();
    std::shared_ptr<Buffer> getNormalsAll();
    std::shared_ptr<Buffer> getIndicesAll();
    int getNumOfVertexIncremental();
    int getNumOfIndexIncremental();
    std::shared_ptr<Buffer> getVerticesIncremental();
    std::shared_ptr<Buffer> getNormalsIncremental();
    std::shared_ptr<Buffer> getIndicesIncremental();
    std::vector<BlockInfo> getBlocksInfoIncremental();
    float getBlockDimentionInMeters();
};

class SurfaceTrackerResult : public FrameFilterResult
{
protected:
    std::shared_ptr<easyar_SurfaceTrackerResult> cdata_;
    void init_cdata(std::shared_ptr<easyar_SurfaceTrackerResult> cdata);
    SurfaceTrackerResult & operator=(const SurfaceTrackerResult & data) = delete;
public:
    SurfaceTrackerResult(std::shared_ptr<easyar_SurfaceTrackerResult> cdata);
    virtual ~SurfaceTrackerResult();

    std::shared_ptr<easyar_SurfaceTrackerResult> get_cdata();
    static std::shared_ptr<SurfaceTrackerResult> from_cdata(std::shared_ptr<easyar_SurfaceTrackerResult> cdata);

    Matrix44F transform();
    SurfaceTrackingStatus status();
};

class SurfaceTracker
{
protected:
    std::shared_ptr<easyar_SurfaceTracker> cdata_;
    void init_cdata(std::shared_ptr<easyar_SurfaceTracker> cdata);
    SurfaceTracker & operator=(const SurfaceTracker & data) = delete;
public:
    SurfaceTracker(std::shared_ptr<easyar_SurfaceTracker> cdata);
    virtual ~SurfaceTracker();

    std::shared_ptr<easyar_SurfaceTracker> get_cdata();
    static std::shared_ptr<SurfaceTracker> from_cdata(std::shared_ptr<easyar_SurfaceTracker> cdata);

    static bool isAvailable();
    std::shared_ptr<InputFrameSink> inputFrameSink();
    std::shared_ptr<OutputFrameSource> outputFrameSource();
    static std::shared_ptr<SurfaceTracker> create();
    bool start();
    void stop();
    void close();
    void alignTargetToCameraImagePoint(Vec2F cameraImagePoint);
};

class MotionTrackerResult : public FrameFilterResult
{
protected:
    std::shared_ptr<easyar_MotionTrackerResult> cdata_;
    void init_cdata(std::shared_ptr<easyar_MotionTrackerResult> cdata);
    MotionTrackerResult & operator=(const MotionTrackerResult & data) = delete;
public:
    MotionTrackerResult(std::shared_ptr<easyar_MotionTrackerResult> cdata);
    virtual ~MotionTrackerResult();

    std::shared_ptr<easyar_MotionTrackerResult> get_cdata();
    static std::shared_ptr<MotionTrackerResult> from_cdata(std::shared_ptr<easyar_MotionTrackerResult> cdata);

    Matrix44F transform();
    MotionTrackingStatus status();
};

class MotionTracker
{
protected:
    std::shared_ptr<easyar_MotionTracker> cdata_;
    void init_cdata(std::shared_ptr<easyar_MotionTracker> cdata);
    MotionTracker & operator=(const MotionTracker & data) = delete;
public:
    MotionTracker(std::shared_ptr<easyar_MotionTracker> cdata);
    virtual ~MotionTracker();

    std::shared_ptr<easyar_MotionTracker> get_cdata();
    static std::shared_ptr<MotionTracker> from_cdata(std::shared_ptr<easyar_MotionTracker> cdata);

    static bool isAvailable();
    std::shared_ptr<InputFrameSink> inputFrameSink();
    std::shared_ptr<OutputFrameSource> outputFrameSource();
    static std::shared_ptr<MotionTracker> create();
    bool start();
    void stop();
    void close();
};

class MotionTrackerOutputFrameToInputFrameAdapter
{
protected:
    std::shared_ptr<easyar_MotionTrackerOutputFrameToInputFrameAdapter> cdata_;
    void init_cdata(std::shared_ptr<easyar_MotionTrackerOutputFrameToInputFrameAdapter> cdata);
    MotionTrackerOutputFrameToInputFrameAdapter & operator=(const MotionTrackerOutputFrameToInputFrameAdapter & data) = delete;
public:
    MotionTrackerOutputFrameToInputFrameAdapter(std::shared_ptr<easyar_MotionTrackerOutputFrameToInputFrameAdapter> cdata);
    virtual ~MotionTrackerOutputFrameToInputFrameAdapter();

    std::shared_ptr<easyar_MotionTrackerOutputFrameToInputFrameAdapter> get_cdata();
    static std::shared_ptr<MotionTrackerOutputFrameToInputFrameAdapter> from_cdata(std::shared_ptr<easyar_MotionTrackerOutputFrameToInputFrameAdapter> cdata);

    std::shared_ptr<OutputFrameSink> input();
    std::shared_ptr<InputFrameSource> output();
    static std::shared_ptr<MotionTrackerOutputFrameToInputFrameAdapter> create();
};

class ImageTargetParameters
{
protected:
    std::shared_ptr<easyar_ImageTargetParameters> cdata_;
    void init_cdata(std::shared_ptr<easyar_ImageTargetParameters> cdata);
    ImageTargetParameters & operator=(const ImageTargetParameters & data) = delete;
public:
    ImageTargetParameters(std::shared_ptr<easyar_ImageTargetParameters> cdata);
    virtual ~ImageTargetParameters();

    std::shared_ptr<easyar_ImageTargetParameters> get_cdata();
    static std::shared_ptr<ImageTargetParameters> from_cdata(std::shared_ptr<easyar_ImageTargetParameters> cdata);

    ImageTargetParameters();
    std::shared_ptr<Image> image();
    void setImage(std::shared_ptr<Image> image);
    std::string name();
    void setName(std::string name);
    std::string uid();
    void setUid(std::string uid);
    std::string meta();
    void setMeta(std::string meta);
    float scale();
    void setScale(float scale);
};

class ImageTarget : public Target
{
protected:
    std::shared_ptr<easyar_ImageTarget> cdata_;
    void init_cdata(std::shared_ptr<easyar_ImageTarget> cdata);
    ImageTarget & operator=(const ImageTarget & data) = delete;
public:
    ImageTarget(std::shared_ptr<easyar_ImageTarget> cdata);
    virtual ~ImageTarget();

    std::shared_ptr<easyar_ImageTarget> get_cdata();
    static std::shared_ptr<ImageTarget> from_cdata(std::shared_ptr<easyar_ImageTarget> cdata);

    ImageTarget();
    static std::optional<std::shared_ptr<ImageTarget>> createFromParameters(std::shared_ptr<ImageTargetParameters> parameters);
    static std::optional<std::shared_ptr<ImageTarget>> createFromTargetFile(std::string path, StorageType storageType);
    static std::optional<std::shared_ptr<ImageTarget>> createFromTargetData(std::shared_ptr<Buffer> buffer);
    bool save(std::string path);
    static std::optional<std::shared_ptr<ImageTarget>> createFromImageFile(std::string path, StorageType storageType, std::string name, std::string uid, std::string meta, float scale);
    static std::vector<std::shared_ptr<ImageTarget>> setupAll(std::string path, StorageType storageType);
    float scale();
    float aspectRatio();
    bool setScale(float scale);
    std::vector<std::shared_ptr<Image>> images();
    int runtimeID();
    std::string uid();
    std::string name();
    void setName(std::string name);
    std::string meta();
    void setMeta(std::string data);
};

class ImageTrackerResult : public TargetTrackerResult
{
protected:
    std::shared_ptr<easyar_ImageTrackerResult> cdata_;
    void init_cdata(std::shared_ptr<easyar_ImageTrackerResult> cdata);
    ImageTrackerResult & operator=(const ImageTrackerResult & data) = delete;
public:
    ImageTrackerResult(std::shared_ptr<easyar_ImageTrackerResult> cdata);
    virtual ~ImageTrackerResult();

    std::shared_ptr<easyar_ImageTrackerResult> get_cdata();
    static std::shared_ptr<ImageTrackerResult> from_cdata(std::shared_ptr<easyar_ImageTrackerResult> cdata);

    std::vector<std::shared_ptr<TargetInstance>> targetInstances();
    void setTargetInstances(std::vector<std::shared_ptr<TargetInstance>> instances);
};

class ImageTracker
{
protected:
    std::shared_ptr<easyar_ImageTracker> cdata_;
    void init_cdata(std::shared_ptr<easyar_ImageTracker> cdata);
    ImageTracker & operator=(const ImageTracker & data) = delete;
public:
    ImageTracker(std::shared_ptr<easyar_ImageTracker> cdata);
    virtual ~ImageTracker();

    std::shared_ptr<easyar_ImageTracker> get_cdata();
    static std::shared_ptr<ImageTracker> from_cdata(std::shared_ptr<easyar_ImageTracker> cdata);

    static bool isAvailable();
    std::shared_ptr<FeedbackFrameSink> feedbackFrameSink();
    std::shared_ptr<OutputFrameSource> outputFrameSource();
    static std::shared_ptr<ImageTracker> create();
    static std::shared_ptr<ImageTracker> createWithMode(ImageTrackerMode trackMode);
    bool start();
    void stop();
    void close();
    void loadTarget(std::shared_ptr<Target> target, std::shared_ptr<CallbackScheduler> callbackScheduler, std::function<void(std::shared_ptr<Target>, bool)> callback);
    void unloadTarget(std::shared_ptr<Target> target, std::shared_ptr<CallbackScheduler> callbackScheduler, std::function<void(std::shared_ptr<Target>, bool)> callback);
    std::vector<std::shared_ptr<Target>> targets();
    bool setSimultaneousNum(int num);
    int simultaneousNum();
};

class Recorder
{
protected:
    std::shared_ptr<easyar_Recorder> cdata_;
    void init_cdata(std::shared_ptr<easyar_Recorder> cdata);
    Recorder & operator=(const Recorder & data) = delete;
public:
    Recorder(std::shared_ptr<easyar_Recorder> cdata);
    virtual ~Recorder();

    std::shared_ptr<easyar_Recorder> get_cdata();
    static std::shared_ptr<Recorder> from_cdata(std::shared_ptr<easyar_Recorder> cdata);

    static bool isAvailable();
    static void requestPermissions(std::shared_ptr<CallbackScheduler> callbackScheduler, std::optional<std::function<void(PermissionStatus, std::string)>> permissionCallback);
    static std::shared_ptr<Recorder> create(std::shared_ptr<RecorderConfiguration> config, std::shared_ptr<CallbackScheduler> callbackScheduler, std::optional<std::function<void(RecordStatus, std::string)>> statusCallback);
    void start();
    void updateFrame(std::shared_ptr<TextureId> texture, int width, int height);
    bool stop();
};

class RecorderConfiguration
{
protected:
    std::shared_ptr<easyar_RecorderConfiguration> cdata_;
    void init_cdata(std::shared_ptr<easyar_RecorderConfiguration> cdata);
    RecorderConfiguration & operator=(const RecorderConfiguration & data) = delete;
public:
    RecorderConfiguration(std::shared_ptr<easyar_RecorderConfiguration> cdata);
    virtual ~RecorderConfiguration();

    std::shared_ptr<easyar_RecorderConfiguration> get_cdata();
    static std::shared_ptr<RecorderConfiguration> from_cdata(std::shared_ptr<easyar_RecorderConfiguration> cdata);

    RecorderConfiguration();
    void setOutputFile(std::string path);
    bool setProfile(RecordProfile profile);
    void setVideoSize(RecordVideoSize framesize);
    void setVideoBitrate(int bitrate);
    void setChannelCount(int count);
    void setAudioSampleRate(int samplerate);
    void setAudioBitrate(int bitrate);
    void setVideoOrientation(RecordVideoOrientation mode);
    void setZoomMode(RecordZoomMode mode);
};

class SparseSpatialMapResult : public FrameFilterResult
{
protected:
    std::shared_ptr<easyar_SparseSpatialMapResult> cdata_;
    void init_cdata(std::shared_ptr<easyar_SparseSpatialMapResult> cdata);
    SparseSpatialMapResult & operator=(const SparseSpatialMapResult & data) = delete;
public:
    SparseSpatialMapResult(std::shared_ptr<easyar_SparseSpatialMapResult> cdata);
    virtual ~SparseSpatialMapResult();

    std::shared_ptr<easyar_SparseSpatialMapResult> get_cdata();
    static std::shared_ptr<SparseSpatialMapResult> from_cdata(std::shared_ptr<easyar_SparseSpatialMapResult> cdata);

    MapTrackingStatus getMapTrackingStatus();
    Matrix44F getVioPose();
    Matrix44F getMapPose();
    bool getLocalizedStatus();
    std::string getCurrentLocalizedMapID();
};

class PlaneData
{
protected:
    std::shared_ptr<easyar_PlaneData> cdata_;
    void init_cdata(std::shared_ptr<easyar_PlaneData> cdata);
    PlaneData & operator=(const PlaneData & data) = delete;
public:
    PlaneData(std::shared_ptr<easyar_PlaneData> cdata);
    virtual ~PlaneData();

    std::shared_ptr<easyar_PlaneData> get_cdata();
    static std::shared_ptr<PlaneData> from_cdata(std::shared_ptr<easyar_PlaneData> cdata);

    PlaneData();
    PlaneType getType();
    Matrix44F getPose();
    float getExtentX();
    float getExtentZ();
};

class SparseSpatialMapConfig
{
protected:
    std::shared_ptr<easyar_SparseSpatialMapConfig> cdata_;
    void init_cdata(std::shared_ptr<easyar_SparseSpatialMapConfig> cdata);
    SparseSpatialMapConfig & operator=(const SparseSpatialMapConfig & data) = delete;
public:
    SparseSpatialMapConfig(std::shared_ptr<easyar_SparseSpatialMapConfig> cdata);
    virtual ~SparseSpatialMapConfig();

    std::shared_ptr<easyar_SparseSpatialMapConfig> get_cdata();
    static std::shared_ptr<SparseSpatialMapConfig> from_cdata(std::shared_ptr<easyar_SparseSpatialMapConfig> cdata);

    SparseSpatialMapConfig();
    void setLocalizeConfig(LocalizeConfig _value);
    LocalizeConfig getLocalizeConfig();
    void setMapConfig(MapConfig _value);
    MapConfig getMapConfig();
};

class SparseSpatialMap
{
protected:
    std::shared_ptr<easyar_SparseSpatialMap> cdata_;
    void init_cdata(std::shared_ptr<easyar_SparseSpatialMap> cdata);
    SparseSpatialMap & operator=(const SparseSpatialMap & data) = delete;
public:
    SparseSpatialMap(std::shared_ptr<easyar_SparseSpatialMap> cdata);
    virtual ~SparseSpatialMap();

    std::shared_ptr<easyar_SparseSpatialMap> get_cdata();
    static std::shared_ptr<SparseSpatialMap> from_cdata(std::shared_ptr<easyar_SparseSpatialMap> cdata);

    static bool isAvailable();
    std::shared_ptr<InputFrameSink> inputFrameSink();
    std::shared_ptr<OutputFrameSource> outputFrameSource();
    static std::shared_ptr<SparseSpatialMap> create();
    bool start();
    void stop();
    void close();
    std::shared_ptr<Buffer> getPointCloudBuffer();
    std::vector<std::shared_ptr<PlaneData>> getMapPlanes();
    std::vector<Vec3F> hitTestAgainstPointCloud(Vec2F cameraImagePoint);
    std::vector<Vec3F> hitTestAgainstPlanes(Vec2F cameraImagePoint);
    bool saveMap(std::shared_ptr<CallbackScheduler> callbackScheduler, std::function<void(std::optional<std::shared_ptr<Buffer>>)> resultCallBack);
    bool loadMap(std::shared_ptr<Buffer> pMapData, std::string mapID, std::shared_ptr<CallbackScheduler> callbackScheduler, std::optional<std::function<void(bool)>> resultCallBack);
    bool unloadMap(std::string mapID, std::shared_ptr<CallbackScheduler> callbackScheduler, std::optional<std::function<void(bool)>> resultCallBack);
    void setConfig(std::shared_ptr<SparseSpatialMapConfig> config);
    std::shared_ptr<SparseSpatialMapConfig> getConfig();
    bool startLocalize();
    bool stopLocalize();
};

class ImageHelper
{
public:
    static std::optional<std::shared_ptr<Image>> decode(std::shared_ptr<Buffer> buffer);
};

class CallbackScheduler
{
protected:
    std::shared_ptr<easyar_CallbackScheduler> cdata_;
    void init_cdata(std::shared_ptr<easyar_CallbackScheduler> cdata);
    CallbackScheduler & operator=(const CallbackScheduler & data) = delete;
public:
    CallbackScheduler(std::shared_ptr<easyar_CallbackScheduler> cdata);
    virtual ~CallbackScheduler();

    std::shared_ptr<easyar_CallbackScheduler> get_cdata();
    static std::shared_ptr<CallbackScheduler> from_cdata(std::shared_ptr<easyar_CallbackScheduler> cdata);

};

class DelayedCallbackScheduler : public CallbackScheduler
{
protected:
    std::shared_ptr<easyar_DelayedCallbackScheduler> cdata_;
    void init_cdata(std::shared_ptr<easyar_DelayedCallbackScheduler> cdata);
    DelayedCallbackScheduler & operator=(const DelayedCallbackScheduler & data) = delete;
public:
    DelayedCallbackScheduler(std::shared_ptr<easyar_DelayedCallbackScheduler> cdata);
    virtual ~DelayedCallbackScheduler();

    std::shared_ptr<easyar_DelayedCallbackScheduler> get_cdata();
    static std::shared_ptr<DelayedCallbackScheduler> from_cdata(std::shared_ptr<easyar_DelayedCallbackScheduler> cdata);

    DelayedCallbackScheduler();
    bool runOne();
};

class ImmediateCallbackScheduler : public CallbackScheduler
{
protected:
    std::shared_ptr<easyar_ImmediateCallbackScheduler> cdata_;
    void init_cdata(std::shared_ptr<easyar_ImmediateCallbackScheduler> cdata);
    ImmediateCallbackScheduler & operator=(const ImmediateCallbackScheduler & data) = delete;
public:
    ImmediateCallbackScheduler(std::shared_ptr<easyar_ImmediateCallbackScheduler> cdata);
    virtual ~ImmediateCallbackScheduler();

    std::shared_ptr<easyar_ImmediateCallbackScheduler> get_cdata();
    static std::shared_ptr<ImmediateCallbackScheduler> from_cdata(std::shared_ptr<easyar_ImmediateCallbackScheduler> cdata);

    static std::shared_ptr<ImmediateCallbackScheduler> getDefault();
};

class CameraDevice
{
protected:
    std::shared_ptr<easyar_CameraDevice> cdata_;
    void init_cdata(std::shared_ptr<easyar_CameraDevice> cdata);
    CameraDevice & operator=(const CameraDevice & data) = delete;
public:
    CameraDevice(std::shared_ptr<easyar_CameraDevice> cdata);
    virtual ~CameraDevice();

    std::shared_ptr<easyar_CameraDevice> get_cdata();
    static std::shared_ptr<CameraDevice> from_cdata(std::shared_ptr<easyar_CameraDevice> cdata);

    CameraDevice();
    static bool isAvailable();
    AndroidCameraApiType androidCameraApiType();
    void setAndroidCameraApiType(AndroidCameraApiType type);
    int bufferCapacity();
    void setBufferCapacity(int capacity);
    std::shared_ptr<InputFrameSource> inputFrameSource();
    void setStateChangedCallback(std::shared_ptr<CallbackScheduler> callbackScheduler, std::optional<std::function<void(CameraState)>> stateChangedCallback);
    static void requestPermissions(std::shared_ptr<CallbackScheduler> callbackScheduler, std::optional<std::function<void(PermissionStatus, std::string)>> permissionCallback);
    bool openWithIndex(int cameraIndex);
    bool openWithType(CameraDeviceType type);
    bool start();
    void stop();
    void close();
    CameraDeviceType type();
    std::shared_ptr<CameraParameters> cameraParameters();
    void setCameraParameters(std::shared_ptr<CameraParameters> cameraParameters);
    Vec2I size();
    int supportedSizeCount();
    Vec2I supportedSize(int index);
    bool setSize(Vec2I size);
    int supportedFrameRateRangeCount();
    float supportedFrameRateRangeLower(int index);
    float supportedFrameRateRangeUpper(int index);
    int frameRateRange();
    bool setFrameRateRange(int index);
    bool setFlashTorchMode(bool on);
    bool setFocusMode(CameraDeviceFocusMode focusMode);
    bool autoFocus();
    bool setPresentProfile(CameraDevicePresetProfile profile);
};

class CameraDeviceSelector
{
public:
    static std::shared_ptr<CameraDevice> createCameraDevice(CameraDevicePreference preference);
};

class SignalSink
{
protected:
    std::shared_ptr<easyar_SignalSink> cdata_;
    void init_cdata(std::shared_ptr<easyar_SignalSink> cdata);
    SignalSink & operator=(const SignalSink & data) = delete;
public:
    SignalSink(std::shared_ptr<easyar_SignalSink> cdata);
    virtual ~SignalSink();

    std::shared_ptr<easyar_SignalSink> get_cdata();
    static std::shared_ptr<SignalSink> from_cdata(std::shared_ptr<easyar_SignalSink> cdata);

    void handle();
};

class SignalSource
{
protected:
    std::shared_ptr<easyar_SignalSource> cdata_;
    void init_cdata(std::shared_ptr<easyar_SignalSource> cdata);
    SignalSource & operator=(const SignalSource & data) = delete;
public:
    SignalSource(std::shared_ptr<easyar_SignalSource> cdata);
    virtual ~SignalSource();

    std::shared_ptr<easyar_SignalSource> get_cdata();
    static std::shared_ptr<SignalSource> from_cdata(std::shared_ptr<easyar_SignalSource> cdata);

    void setHandler(std::optional<std::function<void()>> handler);
    void connect(std::shared_ptr<SignalSink> sink);
    void disconnect();
};

class InputFrameSink
{
protected:
    std::shared_ptr<easyar_InputFrameSink> cdata_;
    void init_cdata(std::shared_ptr<easyar_InputFrameSink> cdata);
    InputFrameSink & operator=(const InputFrameSink & data) = delete;
public:
    InputFrameSink(std::shared_ptr<easyar_InputFrameSink> cdata);
    virtual ~InputFrameSink();

    std::shared_ptr<easyar_InputFrameSink> get_cdata();
    static std::shared_ptr<InputFrameSink> from_cdata(std::shared_ptr<easyar_InputFrameSink> cdata);

    void handle(std::shared_ptr<InputFrame> inputData);
};

class InputFrameSource
{
protected:
    std::shared_ptr<easyar_InputFrameSource> cdata_;
    void init_cdata(std::shared_ptr<easyar_InputFrameSource> cdata);
    InputFrameSource & operator=(const InputFrameSource & data) = delete;
public:
    InputFrameSource(std::shared_ptr<easyar_InputFrameSource> cdata);
    virtual ~InputFrameSource();

    std::shared_ptr<easyar_InputFrameSource> get_cdata();
    static std::shared_ptr<InputFrameSource> from_cdata(std::shared_ptr<easyar_InputFrameSource> cdata);

    void setHandler(std::optional<std::function<void(std::shared_ptr<InputFrame>)>> handler);
    void connect(std::shared_ptr<InputFrameSink> sink);
    void disconnect();
};

class OutputFrameSink
{
protected:
    std::shared_ptr<easyar_OutputFrameSink> cdata_;
    void init_cdata(std::shared_ptr<easyar_OutputFrameSink> cdata);
    OutputFrameSink & operator=(const OutputFrameSink & data) = delete;
public:
    OutputFrameSink(std::shared_ptr<easyar_OutputFrameSink> cdata);
    virtual ~OutputFrameSink();

    std::shared_ptr<easyar_OutputFrameSink> get_cdata();
    static std::shared_ptr<OutputFrameSink> from_cdata(std::shared_ptr<easyar_OutputFrameSink> cdata);

    void handle(std::shared_ptr<OutputFrame> inputData);
};

class OutputFrameSource
{
protected:
    std::shared_ptr<easyar_OutputFrameSource> cdata_;
    void init_cdata(std::shared_ptr<easyar_OutputFrameSource> cdata);
    OutputFrameSource & operator=(const OutputFrameSource & data) = delete;
public:
    OutputFrameSource(std::shared_ptr<easyar_OutputFrameSource> cdata);
    virtual ~OutputFrameSource();

    std::shared_ptr<easyar_OutputFrameSource> get_cdata();
    static std::shared_ptr<OutputFrameSource> from_cdata(std::shared_ptr<easyar_OutputFrameSource> cdata);

    void setHandler(std::optional<std::function<void(std::shared_ptr<OutputFrame>)>> handler);
    void connect(std::shared_ptr<OutputFrameSink> sink);
    void disconnect();
};

class FeedbackFrameSink
{
protected:
    std::shared_ptr<easyar_FeedbackFrameSink> cdata_;
    void init_cdata(std::shared_ptr<easyar_FeedbackFrameSink> cdata);
    FeedbackFrameSink & operator=(const FeedbackFrameSink & data) = delete;
public:
    FeedbackFrameSink(std::shared_ptr<easyar_FeedbackFrameSink> cdata);
    virtual ~FeedbackFrameSink();

    std::shared_ptr<easyar_FeedbackFrameSink> get_cdata();
    static std::shared_ptr<FeedbackFrameSink> from_cdata(std::shared_ptr<easyar_FeedbackFrameSink> cdata);

    void handle(std::shared_ptr<FeedbackFrame> inputData);
};

class FeedbackFrameSource
{
protected:
    std::shared_ptr<easyar_FeedbackFrameSource> cdata_;
    void init_cdata(std::shared_ptr<easyar_FeedbackFrameSource> cdata);
    FeedbackFrameSource & operator=(const FeedbackFrameSource & data) = delete;
public:
    FeedbackFrameSource(std::shared_ptr<easyar_FeedbackFrameSource> cdata);
    virtual ~FeedbackFrameSource();

    std::shared_ptr<easyar_FeedbackFrameSource> get_cdata();
    static std::shared_ptr<FeedbackFrameSource> from_cdata(std::shared_ptr<easyar_FeedbackFrameSource> cdata);

    void setHandler(std::optional<std::function<void(std::shared_ptr<FeedbackFrame>)>> handler);
    void connect(std::shared_ptr<FeedbackFrameSink> sink);
    void disconnect();
};

class InputFrameFork
{
protected:
    std::shared_ptr<easyar_InputFrameFork> cdata_;
    void init_cdata(std::shared_ptr<easyar_InputFrameFork> cdata);
    InputFrameFork & operator=(const InputFrameFork & data) = delete;
public:
    InputFrameFork(std::shared_ptr<easyar_InputFrameFork> cdata);
    virtual ~InputFrameFork();

    std::shared_ptr<easyar_InputFrameFork> get_cdata();
    static std::shared_ptr<InputFrameFork> from_cdata(std::shared_ptr<easyar_InputFrameFork> cdata);

    std::shared_ptr<InputFrameSink> input();
    std::shared_ptr<InputFrameSource> output(int index);
    int outputCount();
    static std::shared_ptr<InputFrameFork> create(int outputCount);
};

class OutputFrameFork
{
protected:
    std::shared_ptr<easyar_OutputFrameFork> cdata_;
    void init_cdata(std::shared_ptr<easyar_OutputFrameFork> cdata);
    OutputFrameFork & operator=(const OutputFrameFork & data) = delete;
public:
    OutputFrameFork(std::shared_ptr<easyar_OutputFrameFork> cdata);
    virtual ~OutputFrameFork();

    std::shared_ptr<easyar_OutputFrameFork> get_cdata();
    static std::shared_ptr<OutputFrameFork> from_cdata(std::shared_ptr<easyar_OutputFrameFork> cdata);

    std::shared_ptr<OutputFrameSink> input();
    std::shared_ptr<OutputFrameSource> output(int index);
    int outputCount();
    static std::shared_ptr<OutputFrameFork> create(int outputCount);
};

class OutputFrameJoin
{
protected:
    std::shared_ptr<easyar_OutputFrameJoin> cdata_;
    void init_cdata(std::shared_ptr<easyar_OutputFrameJoin> cdata);
    OutputFrameJoin & operator=(const OutputFrameJoin & data) = delete;
public:
    OutputFrameJoin(std::shared_ptr<easyar_OutputFrameJoin> cdata);
    virtual ~OutputFrameJoin();

    std::shared_ptr<easyar_OutputFrameJoin> get_cdata();
    static std::shared_ptr<OutputFrameJoin> from_cdata(std::shared_ptr<easyar_OutputFrameJoin> cdata);

    std::shared_ptr<OutputFrameSink> input(int index);
    std::shared_ptr<OutputFrameSource> output();
    int inputCount();
    static std::shared_ptr<OutputFrameJoin> create(int inputCount);
    static std::shared_ptr<OutputFrameJoin> createWithJoiner(int inputCount, std::function<std::shared_ptr<OutputFrame>(std::vector<std::shared_ptr<OutputFrame>>)> joiner);
};

class FeedbackFrameFork
{
protected:
    std::shared_ptr<easyar_FeedbackFrameFork> cdata_;
    void init_cdata(std::shared_ptr<easyar_FeedbackFrameFork> cdata);
    FeedbackFrameFork & operator=(const FeedbackFrameFork & data) = delete;
public:
    FeedbackFrameFork(std::shared_ptr<easyar_FeedbackFrameFork> cdata);
    virtual ~FeedbackFrameFork();

    std::shared_ptr<easyar_FeedbackFrameFork> get_cdata();
    static std::shared_ptr<FeedbackFrameFork> from_cdata(std::shared_ptr<easyar_FeedbackFrameFork> cdata);

    std::shared_ptr<FeedbackFrameSink> input();
    std::shared_ptr<FeedbackFrameSource> output(int index);
    int outputCount();
    static std::shared_ptr<FeedbackFrameFork> create(int outputCount);
};

class InputFrameThrottler
{
protected:
    std::shared_ptr<easyar_InputFrameThrottler> cdata_;
    void init_cdata(std::shared_ptr<easyar_InputFrameThrottler> cdata);
    InputFrameThrottler & operator=(const InputFrameThrottler & data) = delete;
public:
    InputFrameThrottler(std::shared_ptr<easyar_InputFrameThrottler> cdata);
    virtual ~InputFrameThrottler();

    std::shared_ptr<easyar_InputFrameThrottler> get_cdata();
    static std::shared_ptr<InputFrameThrottler> from_cdata(std::shared_ptr<easyar_InputFrameThrottler> cdata);

    std::shared_ptr<InputFrameSink> input();
    std::shared_ptr<InputFrameSource> output();
    std::shared_ptr<SignalSink> signalInput();
    static std::shared_ptr<InputFrameThrottler> create();
};

class OutputFrameBuffer
{
protected:
    std::shared_ptr<easyar_OutputFrameBuffer> cdata_;
    void init_cdata(std::shared_ptr<easyar_OutputFrameBuffer> cdata);
    OutputFrameBuffer & operator=(const OutputFrameBuffer & data) = delete;
public:
    OutputFrameBuffer(std::shared_ptr<easyar_OutputFrameBuffer> cdata);
    virtual ~OutputFrameBuffer();

    std::shared_ptr<easyar_OutputFrameBuffer> get_cdata();
    static std::shared_ptr<OutputFrameBuffer> from_cdata(std::shared_ptr<easyar_OutputFrameBuffer> cdata);

    std::shared_ptr<OutputFrameSink> input();
    std::shared_ptr<SignalSource> signalOutput();
    std::optional<std::shared_ptr<OutputFrame>> peek();
    static std::shared_ptr<OutputFrameBuffer> create();
};

class InputFrameToOutputFrameAdapter
{
protected:
    std::shared_ptr<easyar_InputFrameToOutputFrameAdapter> cdata_;
    void init_cdata(std::shared_ptr<easyar_InputFrameToOutputFrameAdapter> cdata);
    InputFrameToOutputFrameAdapter & operator=(const InputFrameToOutputFrameAdapter & data) = delete;
public:
    InputFrameToOutputFrameAdapter(std::shared_ptr<easyar_InputFrameToOutputFrameAdapter> cdata);
    virtual ~InputFrameToOutputFrameAdapter();

    std::shared_ptr<easyar_InputFrameToOutputFrameAdapter> get_cdata();
    static std::shared_ptr<InputFrameToOutputFrameAdapter> from_cdata(std::shared_ptr<easyar_InputFrameToOutputFrameAdapter> cdata);

    std::shared_ptr<InputFrameSink> input();
    std::shared_ptr<OutputFrameSource> output();
    static std::shared_ptr<InputFrameToOutputFrameAdapter> create();
};

class InputFrameToFeedbackFrameAdapter
{
protected:
    std::shared_ptr<easyar_InputFrameToFeedbackFrameAdapter> cdata_;
    void init_cdata(std::shared_ptr<easyar_InputFrameToFeedbackFrameAdapter> cdata);
    InputFrameToFeedbackFrameAdapter & operator=(const InputFrameToFeedbackFrameAdapter & data) = delete;
public:
    InputFrameToFeedbackFrameAdapter(std::shared_ptr<easyar_InputFrameToFeedbackFrameAdapter> cdata);
    virtual ~InputFrameToFeedbackFrameAdapter();

    std::shared_ptr<easyar_InputFrameToFeedbackFrameAdapter> get_cdata();
    static std::shared_ptr<InputFrameToFeedbackFrameAdapter> from_cdata(std::shared_ptr<easyar_InputFrameToFeedbackFrameAdapter> cdata);

    std::shared_ptr<InputFrameSink> input();
    std::shared_ptr<OutputFrameSink> sideInput();
    std::shared_ptr<FeedbackFrameSource> output();
    static std::shared_ptr<InputFrameToFeedbackFrameAdapter> create();
};

class Engine
{
public:
    static int schemaHash();
    static bool initialize(std::string key);
    static void onPause();
    static void onResume();
    static std::string errorMessage();
    static std::string versionString();
    static std::string name();
};

class InputFrame
{
protected:
    std::shared_ptr<easyar_InputFrame> cdata_;
    void init_cdata(std::shared_ptr<easyar_InputFrame> cdata);
    InputFrame & operator=(const InputFrame & data) = delete;
public:
    InputFrame(std::shared_ptr<easyar_InputFrame> cdata);
    virtual ~InputFrame();

    std::shared_ptr<easyar_InputFrame> get_cdata();
    static std::shared_ptr<InputFrame> from_cdata(std::shared_ptr<easyar_InputFrame> cdata);

    int index();
    std::shared_ptr<Image> image();
    bool hasCameraParameters();
    std::shared_ptr<CameraParameters> cameraParameters();
    bool hasTemporalInformation();
    double timestamp();
    bool hasSpatialInformation();
    Matrix44F cameraTransform();
    InputFrameTrackingStatus trackingStatus();
    static std::shared_ptr<InputFrame> create(std::shared_ptr<Image> image, std::shared_ptr<CameraParameters> cameraParameters, double timestamp, Matrix44F cameraTransform, InputFrameTrackingStatus trackingStatus);
    static std::shared_ptr<InputFrame> createWithImageAndCameraParametersAndTemporal(std::shared_ptr<Image> image, std::shared_ptr<CameraParameters> cameraParameters, double timestamp);
    static std::shared_ptr<InputFrame> createWithImageAndCameraParameters(std::shared_ptr<Image> image, std::shared_ptr<CameraParameters> cameraParameters);
    static std::shared_ptr<InputFrame> createWithImage(std::shared_ptr<Image> image);
};

class OutputFrame
{
protected:
    std::shared_ptr<easyar_OutputFrame> cdata_;
    void init_cdata(std::shared_ptr<easyar_OutputFrame> cdata);
    OutputFrame & operator=(const OutputFrame & data) = delete;
public:
    OutputFrame(std::shared_ptr<easyar_OutputFrame> cdata);
    virtual ~OutputFrame();

    std::shared_ptr<easyar_OutputFrame> get_cdata();
    static std::shared_ptr<OutputFrame> from_cdata(std::shared_ptr<easyar_OutputFrame> cdata);

    OutputFrame(std::shared_ptr<InputFrame> inputFrame, std::vector<std::optional<std::shared_ptr<FrameFilterResult>>> results);
    int index();
    std::shared_ptr<InputFrame> inputFrame();
    std::vector<std::optional<std::shared_ptr<FrameFilterResult>>> results();
};

class FeedbackFrame
{
protected:
    std::shared_ptr<easyar_FeedbackFrame> cdata_;
    void init_cdata(std::shared_ptr<easyar_FeedbackFrame> cdata);
    FeedbackFrame & operator=(const FeedbackFrame & data) = delete;
public:
    FeedbackFrame(std::shared_ptr<easyar_FeedbackFrame> cdata);
    virtual ~FeedbackFrame();

    std::shared_ptr<easyar_FeedbackFrame> get_cdata();
    static std::shared_ptr<FeedbackFrame> from_cdata(std::shared_ptr<easyar_FeedbackFrame> cdata);

    FeedbackFrame(std::shared_ptr<InputFrame> inputFrame, std::optional<std::shared_ptr<OutputFrame>> previousOutputFrame);
    std::shared_ptr<InputFrame> inputFrame();
    std::optional<std::shared_ptr<OutputFrame>> previousOutputFrame();
};

class TargetInstance
{
protected:
    std::shared_ptr<easyar_TargetInstance> cdata_;
    void init_cdata(std::shared_ptr<easyar_TargetInstance> cdata);
    TargetInstance & operator=(const TargetInstance & data) = delete;
public:
    TargetInstance(std::shared_ptr<easyar_TargetInstance> cdata);
    virtual ~TargetInstance();

    std::shared_ptr<easyar_TargetInstance> get_cdata();
    static std::shared_ptr<TargetInstance> from_cdata(std::shared_ptr<easyar_TargetInstance> cdata);

    TargetInstance();
    TargetStatus status();
    std::optional<std::shared_ptr<Target>> target();
    Matrix44F pose();
};

class TextureId
{
protected:
    std::shared_ptr<easyar_TextureId> cdata_;
    void init_cdata(std::shared_ptr<easyar_TextureId> cdata);
    TextureId & operator=(const TextureId & data) = delete;
public:
    TextureId(std::shared_ptr<easyar_TextureId> cdata);
    virtual ~TextureId();

    std::shared_ptr<easyar_TextureId> get_cdata();
    static std::shared_ptr<TextureId> from_cdata(std::shared_ptr<easyar_TextureId> cdata);

    int getInt();
    void * getPointer();
    static std::shared_ptr<TextureId> fromInt(int _value);
    static std::shared_ptr<TextureId> fromPointer(void * ptr);
};

class VideoPlayer
{
protected:
    std::shared_ptr<easyar_VideoPlayer> cdata_;
    void init_cdata(std::shared_ptr<easyar_VideoPlayer> cdata);
    VideoPlayer & operator=(const VideoPlayer & data) = delete;
public:
    VideoPlayer(std::shared_ptr<easyar_VideoPlayer> cdata);
    virtual ~VideoPlayer();

    std::shared_ptr<easyar_VideoPlayer> get_cdata();
    static std::shared_ptr<VideoPlayer> from_cdata(std::shared_ptr<easyar_VideoPlayer> cdata);

    VideoPlayer();
    void setVideoType(VideoType videoType);
    void setRenderTexture(std::shared_ptr<TextureId> texture);
    void open(std::string path, StorageType storageType, std::shared_ptr<CallbackScheduler> callbackScheduler, std::optional<std::function<void(VideoStatus)>> callback);
    void close();
    bool play();
    void stop();
    void pause();
    bool isRenderTextureAvailable();
    void updateFrame();
    int duration();
    int currentPosition();
    bool seek(int position);
    Vec2I size();
    float volume();
    bool setVolume(float volume);
};

class Buffer
{
protected:
    std::shared_ptr<easyar_Buffer> cdata_;
    void init_cdata(std::shared_ptr<easyar_Buffer> cdata);
    Buffer & operator=(const Buffer & data) = delete;
public:
    Buffer(std::shared_ptr<easyar_Buffer> cdata);
    virtual ~Buffer();

    std::shared_ptr<easyar_Buffer> get_cdata();
    static std::shared_ptr<Buffer> from_cdata(std::shared_ptr<easyar_Buffer> cdata);

    static std::shared_ptr<Buffer> wrap(void * ptr, int size, std::function<void()> deleter);
    static std::shared_ptr<Buffer> create(int size);
    void * data();
    int size();
    static void memoryCopy(void * src, void * dest, int length);
    bool tryCopyFrom(void * src, int srcIndex, int index, int length);
    bool tryCopyTo(int index, void * dest, int destIndex, int length);
    std::shared_ptr<Buffer> partition(int index, int length);
};

class BufferDictionary
{
protected:
    std::shared_ptr<easyar_BufferDictionary> cdata_;
    void init_cdata(std::shared_ptr<easyar_BufferDictionary> cdata);
    BufferDictionary & operator=(const BufferDictionary & data) = delete;
public:
    BufferDictionary(std::shared_ptr<easyar_BufferDictionary> cdata);
    virtual ~BufferDictionary();

    std::shared_ptr<easyar_BufferDictionary> get_cdata();
    static std::shared_ptr<BufferDictionary> from_cdata(std::shared_ptr<easyar_BufferDictionary> cdata);

    BufferDictionary();
    int count();
    bool contains(std::string path);
    std::optional<std::shared_ptr<Buffer>> tryGet(std::string path);
    void set(std::string path, std::shared_ptr<Buffer> buffer);
    bool remove(std::string path);
    void clear();
};

class BufferPool
{
protected:
    std::shared_ptr<easyar_BufferPool> cdata_;
    void init_cdata(std::shared_ptr<easyar_BufferPool> cdata);
    BufferPool & operator=(const BufferPool & data) = delete;
public:
    BufferPool(std::shared_ptr<easyar_BufferPool> cdata);
    virtual ~BufferPool();

    std::shared_ptr<easyar_BufferPool> get_cdata();
    static std::shared_ptr<BufferPool> from_cdata(std::shared_ptr<easyar_BufferPool> cdata);

    BufferPool(int block_size, int capacity);
    int block_size();
    int capacity();
    int size();
    std::optional<std::shared_ptr<Buffer>> tryAcquire();
};

class CameraParameters
{
protected:
    std::shared_ptr<easyar_CameraParameters> cdata_;
    void init_cdata(std::shared_ptr<easyar_CameraParameters> cdata);
    CameraParameters & operator=(const CameraParameters & data) = delete;
public:
    CameraParameters(std::shared_ptr<easyar_CameraParameters> cdata);
    virtual ~CameraParameters();

    std::shared_ptr<easyar_CameraParameters> get_cdata();
    static std::shared_ptr<CameraParameters> from_cdata(std::shared_ptr<easyar_CameraParameters> cdata);

    CameraParameters(Vec2I size, Vec2F focalLength, Vec2F principalPoint, CameraDeviceType cameraDeviceType, int cameraOrientation);
    Vec2I size();
    Vec2F focalLength();
    Vec2F principalPoint();
    CameraDeviceType cameraDeviceType();
    int cameraOrientation();
    static std::shared_ptr<CameraParameters> createWithDefaultIntrinsics(Vec2I size, CameraDeviceType cameraDeviceType, int cameraOrientation);
    int imageOrientation(int screenRotation);
    bool imageHorizontalFlip(bool manualHorizontalFlip);
    Matrix44F projection(float nearPlane, float farPlane, float viewportAspectRatio, int screenRotation, bool combiningFlip, bool manualHorizontalFlip);
    Matrix44F imageProjection(float viewportAspectRatio, int screenRotation, bool combiningFlip, bool manualHorizontalFlip);
    Vec2F screenCoordinatesFromImageCoordinates(float viewportAspectRatio, int screenRotation, bool combiningFlip, bool manualHorizontalFlip, Vec2F imageCoordinates);
    Vec2F imageCoordinatesFromScreenCoordinates(float viewportAspectRatio, int screenRotation, bool combiningFlip, bool manualHorizontalFlip, Vec2F screenCoordinates);
    bool equalsTo(std::shared_ptr<CameraParameters> other);
};

class Image
{
protected:
    std::shared_ptr<easyar_Image> cdata_;
    void init_cdata(std::shared_ptr<easyar_Image> cdata);
    Image & operator=(const Image & data) = delete;
public:
    Image(std::shared_ptr<easyar_Image> cdata);
    virtual ~Image();

    std::shared_ptr<easyar_Image> get_cdata();
    static std::shared_ptr<Image> from_cdata(std::shared_ptr<easyar_Image> cdata);

    Image(std::shared_ptr<Buffer> buffer, PixelFormat format, int width, int height);
    std::shared_ptr<Buffer> buffer();
    PixelFormat format();
    int width();
    int height();
    bool empty();
};

class JniUtility
{
public:
    static std::shared_ptr<Buffer> wrapByteArray(void * bytes, bool readOnly, std::function<void()> deleter);
    static std::shared_ptr<Buffer> wrapBuffer(void * directBuffer, std::function<void()> deleter);
};

class Log
{
public:
    static void setLogFunc(std::function<void(LogLevel, std::string)> func);
    static void resetLogFunc();
};

/// <summary>
/// record
/// </summary>
struct Matrix44F
{
    std::array<float, 16> data;
};

/// <summary>
/// record
/// </summary>
struct Matrix33F
{
    std::array<float, 9> data;
};

/// <summary>
/// record
/// </summary>
struct Vec4F
{
    std::array<float, 4> data;
};

/// <summary>
/// record
/// </summary>
struct Vec3F
{
    std::array<float, 3> data;
};

/// <summary>
/// record
/// </summary>
struct Vec2F
{
    std::array<float, 2> data;
};

/// <summary>
/// record
/// </summary>
struct Vec4I
{
    std::array<int, 4> data;
};

/// <summary>
/// record
/// </summary>
struct Vec2I
{
    std::array<int, 2> data;
};

}

#endif

#ifndef _DECLARATION_ONLY_

#include "easyar/objecttarget.h"
#include "easyar/objecttracker.h"
#include "easyar/cadtarget.h"
#include "easyar/cadtracker.h"
#include "easyar/cloud.h"
#include "easyar/densespatialmap.h"
#include "easyar/scenemesh.h"
#include "easyar/surfacetracker.h"
#include "easyar/motiontracker.h"
#include "easyar/imagetarget.h"
#include "easyar/imagetracker.h"
#include "easyar/recorder.h"
#include "easyar/recorder_configuration.h"
#include "easyar/sparsespatialmap.h"
#include "easyar/imagehelper.h"
#include "easyar/callbackscheduler.h"
#include "easyar/camera.h"
#include "easyar/dataflow.h"
#include "easyar/engine.h"
#include "easyar/frame.h"
#include "easyar/target.h"
#include "easyar/texture.h"
#include "easyar/videoplayer.h"
#include "easyar/buffer.h"
#include "easyar/bufferpool.h"
#include "easyar/cameraparameters.h"
#include "easyar/image.h"
#include "easyar/jniutility.h"
#include "easyar/log.h"

namespace easyar {

static inline std::shared_ptr<easyar_String> std_string_to_easyar_String(std::string s)
{
    easyar_String * ptr;
    easyar_String_from_utf8(s.data(), s.data() + s.size(), &ptr);
    return std::shared_ptr<easyar_String>(ptr, [](easyar_String * ptr) { easyar_String__dtor(ptr); });
}
static inline std::string std_string_from_easyar_String(std::shared_ptr<easyar_String> s)
{
    return std::string(easyar_String_begin(s.get()), easyar_String_end(s.get()));
}

static void FunctorOfVoid_func(void * _state, /* OUT */ easyar_String * * _exception);
static void FunctorOfVoid_destroy(void * _state);
static inline easyar_FunctorOfVoid FunctorOfVoid_to_c(std::function<void()> f);

static inline std::shared_ptr<easyar_ListOfObjectTarget> std_vector_to_easyar_ListOfObjectTarget(std::vector<std::shared_ptr<ObjectTarget>> l);
static inline std::vector<std::shared_ptr<ObjectTarget>> std_vector_from_easyar_ListOfObjectTarget(std::shared_ptr<easyar_ListOfObjectTarget> pl);
static inline bool easyar_ListOfObjectTarget_check_external_cpp(const std::vector<std::shared_ptr<ObjectTarget>> & l);

static inline std::shared_ptr<easyar_ListOfVec3F> std_vector_to_easyar_ListOfVec3F(std::vector<Vec3F> l);
static inline std::vector<Vec3F> std_vector_from_easyar_ListOfVec3F(std::shared_ptr<easyar_ListOfVec3F> pl);
static inline bool easyar_ListOfVec3F_check_external_cpp(const std::vector<Vec3F> & l);

static inline std::shared_ptr<easyar_ListOfTargetInstance> std_vector_to_easyar_ListOfTargetInstance(std::vector<std::shared_ptr<TargetInstance>> l);
static inline std::vector<std::shared_ptr<TargetInstance>> std_vector_from_easyar_ListOfTargetInstance(std::shared_ptr<easyar_ListOfTargetInstance> pl);
static inline bool easyar_ListOfTargetInstance_check_external_cpp(const std::vector<std::shared_ptr<TargetInstance>> & l);

static inline std::shared_ptr<easyar_ListOfOptionalOfFrameFilterResult> std_vector_to_easyar_ListOfOptionalOfFrameFilterResult(std::vector<std::optional<std::shared_ptr<FrameFilterResult>>> l);
static inline std::vector<std::optional<std::shared_ptr<FrameFilterResult>>> std_vector_from_easyar_ListOfOptionalOfFrameFilterResult(std::shared_ptr<easyar_ListOfOptionalOfFrameFilterResult> pl);
static inline bool easyar_ListOfOptionalOfFrameFilterResult_check_external_cpp(const std::vector<std::optional<std::shared_ptr<FrameFilterResult>>> & l);

static void FunctorOfVoidFromOutputFrame_func(void * _state, easyar_OutputFrame *, /* OUT */ easyar_String * * _exception);
static void FunctorOfVoidFromOutputFrame_destroy(void * _state);
static inline easyar_FunctorOfVoidFromOutputFrame FunctorOfVoidFromOutputFrame_to_c(std::function<void(std::shared_ptr<OutputFrame>)> f);

static void FunctorOfVoidFromTargetAndBool_func(void * _state, easyar_Target *, bool, /* OUT */ easyar_String * * _exception);
static void FunctorOfVoidFromTargetAndBool_destroy(void * _state);
static inline easyar_FunctorOfVoidFromTargetAndBool FunctorOfVoidFromTargetAndBool_to_c(std::function<void(std::shared_ptr<Target>, bool)> f);

static inline std::shared_ptr<easyar_ListOfTarget> std_vector_to_easyar_ListOfTarget(std::vector<std::shared_ptr<Target>> l);
static inline std::vector<std::shared_ptr<Target>> std_vector_from_easyar_ListOfTarget(std::shared_ptr<easyar_ListOfTarget> pl);
static inline bool easyar_ListOfTarget_check_external_cpp(const std::vector<std::shared_ptr<Target>> & l);

static inline std::shared_ptr<easyar_ListOfCADTarget> std_vector_to_easyar_ListOfCADTarget(std::vector<std::shared_ptr<CADTarget>> l);
static inline std::vector<std::shared_ptr<CADTarget>> std_vector_from_easyar_ListOfCADTarget(std::shared_ptr<easyar_ListOfCADTarget> pl);
static inline bool easyar_ListOfCADTarget_check_external_cpp(const std::vector<std::shared_ptr<CADTarget>> & l);

static void FunctorOfVoidFromCloudStatusAndListOfTarget_func(void * _state, easyar_CloudStatus, easyar_ListOfTarget *, /* OUT */ easyar_String * * _exception);
static void FunctorOfVoidFromCloudStatusAndListOfTarget_destroy(void * _state);
static inline easyar_FunctorOfVoidFromCloudStatusAndListOfTarget FunctorOfVoidFromCloudStatusAndListOfTarget_to_c(std::function<void(CloudStatus, std::vector<std::shared_ptr<Target>>)> f);

static inline std::shared_ptr<easyar_ListOfBlockInfo> std_vector_to_easyar_ListOfBlockInfo(std::vector<BlockInfo> l);
static inline std::vector<BlockInfo> std_vector_from_easyar_ListOfBlockInfo(std::shared_ptr<easyar_ListOfBlockInfo> pl);
static inline bool easyar_ListOfBlockInfo_check_external_cpp(const std::vector<BlockInfo> & l);

static void FunctorOfVoidFromInputFrame_func(void * _state, easyar_InputFrame *, /* OUT */ easyar_String * * _exception);
static void FunctorOfVoidFromInputFrame_destroy(void * _state);
static inline easyar_FunctorOfVoidFromInputFrame FunctorOfVoidFromInputFrame_to_c(std::function<void(std::shared_ptr<InputFrame>)> f);

static inline std::shared_ptr<easyar_ListOfImageTarget> std_vector_to_easyar_ListOfImageTarget(std::vector<std::shared_ptr<ImageTarget>> l);
static inline std::vector<std::shared_ptr<ImageTarget>> std_vector_from_easyar_ListOfImageTarget(std::shared_ptr<easyar_ListOfImageTarget> pl);
static inline bool easyar_ListOfImageTarget_check_external_cpp(const std::vector<std::shared_ptr<ImageTarget>> & l);

static inline std::shared_ptr<easyar_ListOfImage> std_vector_to_easyar_ListOfImage(std::vector<std::shared_ptr<Image>> l);
static inline std::vector<std::shared_ptr<Image>> std_vector_from_easyar_ListOfImage(std::shared_ptr<easyar_ListOfImage> pl);
static inline bool easyar_ListOfImage_check_external_cpp(const std::vector<std::shared_ptr<Image>> & l);

static void FunctorOfVoidFromPermissionStatusAndString_func(void * _state, easyar_PermissionStatus, easyar_String *, /* OUT */ easyar_String * * _exception);
static void FunctorOfVoidFromPermissionStatusAndString_destroy(void * _state);
static inline easyar_FunctorOfVoidFromPermissionStatusAndString FunctorOfVoidFromPermissionStatusAndString_to_c(std::function<void(PermissionStatus, std::string)> f);

static void FunctorOfVoidFromRecordStatusAndString_func(void * _state, easyar_RecordStatus, easyar_String *, /* OUT */ easyar_String * * _exception);
static void FunctorOfVoidFromRecordStatusAndString_destroy(void * _state);
static inline easyar_FunctorOfVoidFromRecordStatusAndString FunctorOfVoidFromRecordStatusAndString_to_c(std::function<void(RecordStatus, std::string)> f);

static inline std::shared_ptr<easyar_ListOfPlaneData> std_vector_to_easyar_ListOfPlaneData(std::vector<std::shared_ptr<PlaneData>> l);
static inline std::vector<std::shared_ptr<PlaneData>> std_vector_from_easyar_ListOfPlaneData(std::shared_ptr<easyar_ListOfPlaneData> pl);
static inline bool easyar_ListOfPlaneData_check_external_cpp(const std::vector<std::shared_ptr<PlaneData>> & l);

static void FunctorOfVoidFromOptionalOfBuffer_func(void * _state, easyar_OptionalOfBuffer, /* OUT */ easyar_String * * _exception);
static void FunctorOfVoidFromOptionalOfBuffer_destroy(void * _state);
static inline easyar_FunctorOfVoidFromOptionalOfBuffer FunctorOfVoidFromOptionalOfBuffer_to_c(std::function<void(std::optional<std::shared_ptr<Buffer>>)> f);

static void FunctorOfVoidFromBool_func(void * _state, bool, /* OUT */ easyar_String * * _exception);
static void FunctorOfVoidFromBool_destroy(void * _state);
static inline easyar_FunctorOfVoidFromBool FunctorOfVoidFromBool_to_c(std::function<void(bool)> f);

static void FunctorOfVoidFromCameraState_func(void * _state, easyar_CameraState, /* OUT */ easyar_String * * _exception);
static void FunctorOfVoidFromCameraState_destroy(void * _state);
static inline easyar_FunctorOfVoidFromCameraState FunctorOfVoidFromCameraState_to_c(std::function<void(CameraState)> f);

static void FunctorOfVoidFromFeedbackFrame_func(void * _state, easyar_FeedbackFrame *, /* OUT */ easyar_String * * _exception);
static void FunctorOfVoidFromFeedbackFrame_destroy(void * _state);
static inline easyar_FunctorOfVoidFromFeedbackFrame FunctorOfVoidFromFeedbackFrame_to_c(std::function<void(std::shared_ptr<FeedbackFrame>)> f);

static void FunctorOfOutputFrameFromListOfOutputFrame_func(void * _state, easyar_ListOfOutputFrame *, /* OUT */ easyar_OutputFrame * *, /* OUT */ easyar_String * * _exception);
static void FunctorOfOutputFrameFromListOfOutputFrame_destroy(void * _state);
static inline easyar_FunctorOfOutputFrameFromListOfOutputFrame FunctorOfOutputFrameFromListOfOutputFrame_to_c(std::function<std::shared_ptr<OutputFrame>(std::vector<std::shared_ptr<OutputFrame>>)> f);

static inline std::shared_ptr<easyar_ListOfOutputFrame> std_vector_to_easyar_ListOfOutputFrame(std::vector<std::shared_ptr<OutputFrame>> l);
static inline std::vector<std::shared_ptr<OutputFrame>> std_vector_from_easyar_ListOfOutputFrame(std::shared_ptr<easyar_ListOfOutputFrame> pl);
static inline bool easyar_ListOfOutputFrame_check_external_cpp(const std::vector<std::shared_ptr<OutputFrame>> & l);

static void FunctorOfVoidFromVideoStatus_func(void * _state, easyar_VideoStatus, /* OUT */ easyar_String * * _exception);
static void FunctorOfVoidFromVideoStatus_destroy(void * _state);
static inline easyar_FunctorOfVoidFromVideoStatus FunctorOfVoidFromVideoStatus_to_c(std::function<void(VideoStatus)> f);

static void FunctorOfVoidFromLogLevelAndString_func(void * _state, easyar_LogLevel, easyar_String *, /* OUT */ easyar_String * * _exception);
static void FunctorOfVoidFromLogLevelAndString_destroy(void * _state);
static inline easyar_FunctorOfVoidFromLogLevelAndString FunctorOfVoidFromLogLevelAndString_to_c(std::function<void(LogLevel, std::string)> f);

_INLINE_SPECIFIER_ ObjectTargetParameters::ObjectTargetParameters(std::shared_ptr<easyar_ObjectTargetParameters> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ ObjectTargetParameters::~ObjectTargetParameters()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_ObjectTargetParameters> ObjectTargetParameters::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void ObjectTargetParameters::init_cdata(std::shared_ptr<easyar_ObjectTargetParameters> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<ObjectTargetParameters> ObjectTargetParameters::from_cdata(std::shared_ptr<easyar_ObjectTargetParameters> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<ObjectTargetParameters>(cdata);
}
_INLINE_SPECIFIER_ ObjectTargetParameters::ObjectTargetParameters()
    :
    cdata_(nullptr)
{
    easyar_ObjectTargetParameters * _return_value_;
    easyar_ObjectTargetParameters__ctor(&_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); };
    init_cdata(std::shared_ptr<easyar_ObjectTargetParameters>(_return_value_, [](easyar_ObjectTargetParameters * ptr) { easyar_ObjectTargetParameters__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<BufferDictionary> ObjectTargetParameters::bufferDictionary()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_BufferDictionary * _return_value_;
    easyar_ObjectTargetParameters_bufferDictionary(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return BufferDictionary::from_cdata(std::shared_ptr<easyar_BufferDictionary>(_return_value_, [](easyar_BufferDictionary * ptr) { easyar_BufferDictionary__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void ObjectTargetParameters::setBufferDictionary(std::shared_ptr<BufferDictionary> arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    if (!(arg0 != nullptr)) { throw std::runtime_error("InvalidArgument: bufferDictionary"); }
    easyar_ObjectTargetParameters_setBufferDictionary(cdata_.get(), arg0->get_cdata().get());
}
_INLINE_SPECIFIER_ std::string ObjectTargetParameters::objPath()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_String * _return_value_;
    easyar_ObjectTargetParameters_objPath(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return std_string_from_easyar_String(std::shared_ptr<easyar_String>(_return_value_, [](easyar_String * ptr) { easyar_String__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void ObjectTargetParameters::setObjPath(std::string arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_ObjectTargetParameters_setObjPath(cdata_.get(), std_string_to_easyar_String(arg0).get());
}
_INLINE_SPECIFIER_ std::string ObjectTargetParameters::name()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_String * _return_value_;
    easyar_ObjectTargetParameters_name(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return std_string_from_easyar_String(std::shared_ptr<easyar_String>(_return_value_, [](easyar_String * ptr) { easyar_String__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void ObjectTargetParameters::setName(std::string arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_ObjectTargetParameters_setName(cdata_.get(), std_string_to_easyar_String(arg0).get());
}
_INLINE_SPECIFIER_ std::string ObjectTargetParameters::uid()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_String * _return_value_;
    easyar_ObjectTargetParameters_uid(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return std_string_from_easyar_String(std::shared_ptr<easyar_String>(_return_value_, [](easyar_String * ptr) { easyar_String__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void ObjectTargetParameters::setUid(std::string arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_ObjectTargetParameters_setUid(cdata_.get(), std_string_to_easyar_String(arg0).get());
}
_INLINE_SPECIFIER_ std::string ObjectTargetParameters::meta()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_String * _return_value_;
    easyar_ObjectTargetParameters_meta(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return std_string_from_easyar_String(std::shared_ptr<easyar_String>(_return_value_, [](easyar_String * ptr) { easyar_String__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void ObjectTargetParameters::setMeta(std::string arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_ObjectTargetParameters_setMeta(cdata_.get(), std_string_to_easyar_String(arg0).get());
}
_INLINE_SPECIFIER_ float ObjectTargetParameters::scale()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_ObjectTargetParameters_scale(cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ void ObjectTargetParameters::setScale(float arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_ObjectTargetParameters_setScale(cdata_.get(), arg0);
}

_INLINE_SPECIFIER_ ObjectTarget::ObjectTarget(std::shared_ptr<easyar_ObjectTarget> cdata)
    :
    Target(std::shared_ptr<easyar_Target>(nullptr)),
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ ObjectTarget::~ObjectTarget()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_ObjectTarget> ObjectTarget::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void ObjectTarget::init_cdata(std::shared_ptr<easyar_ObjectTarget> cdata)
{
    cdata_ = cdata;
    {
        easyar_Target * ptr = nullptr;
        easyar_castObjectTargetToTarget(cdata_.get(), &ptr);
        Target::init_cdata(std::shared_ptr<easyar_Target>(ptr, [](easyar_Target * ptr) { easyar_Target__dtor(ptr); }));
    }
}
_INLINE_SPECIFIER_ std::shared_ptr<ObjectTarget> ObjectTarget::from_cdata(std::shared_ptr<easyar_ObjectTarget> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<ObjectTarget>(cdata);
}
_INLINE_SPECIFIER_ ObjectTarget::ObjectTarget()
    :
    Target(std::shared_ptr<easyar_Target>(nullptr)),
    cdata_(nullptr)
{
    easyar_ObjectTarget * _return_value_;
    easyar_ObjectTarget__ctor(&_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); };
    init_cdata(std::shared_ptr<easyar_ObjectTarget>(_return_value_, [](easyar_ObjectTarget * ptr) { easyar_ObjectTarget__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::optional<std::shared_ptr<ObjectTarget>> ObjectTarget::createFromParameters(std::shared_ptr<ObjectTargetParameters> arg0)
{
    if (!(arg0 != nullptr)) { throw std::runtime_error("InvalidArgument: parameters"); }
    easyar_OptionalOfObjectTarget _return_value_;
    easyar_ObjectTarget_createFromParameters(arg0->get_cdata().get(), &_return_value_);
    if (!(!_return_value_.has_value || (_return_value_.value != nullptr))) { throw std::runtime_error("InvalidReturnValue"); }
    return (_return_value_.has_value ? ObjectTarget::from_cdata(std::shared_ptr<easyar_ObjectTarget>(_return_value_.value, [](easyar_ObjectTarget * ptr) { easyar_ObjectTarget__dtor(ptr); })) : std::optional<std::shared_ptr<ObjectTarget>>{});
}
_INLINE_SPECIFIER_ std::optional<std::shared_ptr<ObjectTarget>> ObjectTarget::createFromObjectFile(std::string arg0, StorageType arg1, std::string arg2, std::string arg3, std::string arg4, float arg5)
{
    easyar_OptionalOfObjectTarget _return_value_;
    easyar_ObjectTarget_createFromObjectFile(std_string_to_easyar_String(arg0).get(), static_cast<easyar_StorageType>(arg1), std_string_to_easyar_String(arg2).get(), std_string_to_easyar_String(arg3).get(), std_string_to_easyar_String(arg4).get(), arg5, &_return_value_);
    if (!(!_return_value_.has_value || (_return_value_.value != nullptr))) { throw std::runtime_error("InvalidReturnValue"); }
    return (_return_value_.has_value ? ObjectTarget::from_cdata(std::shared_ptr<easyar_ObjectTarget>(_return_value_.value, [](easyar_ObjectTarget * ptr) { easyar_ObjectTarget__dtor(ptr); })) : std::optional<std::shared_ptr<ObjectTarget>>{});
}
_INLINE_SPECIFIER_ std::vector<std::shared_ptr<ObjectTarget>> ObjectTarget::setupAll(std::string arg0, StorageType arg1)
{
    easyar_ListOfObjectTarget * _return_value_;
    easyar_ObjectTarget_setupAll(std_string_to_easyar_String(arg0).get(), static_cast<easyar_StorageType>(arg1), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return std_vector_from_easyar_ListOfObjectTarget(std::shared_ptr<easyar_ListOfObjectTarget>(_return_value_, [](easyar_ListOfObjectTarget * ptr) { easyar_ListOfObjectTarget__dtor(ptr); }));
}
_INLINE_SPECIFIER_ float ObjectTarget::scale()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_ObjectTarget_scale(cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ std::vector<Vec3F> ObjectTarget::boundingBox()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_ListOfVec3F * _return_value_;
    easyar_ObjectTarget_boundingBox(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return std_vector_from_easyar_ListOfVec3F(std::shared_ptr<easyar_ListOfVec3F>(_return_value_, [](easyar_ListOfVec3F * ptr) { easyar_ListOfVec3F__dtor(ptr); }));
}
_INLINE_SPECIFIER_ bool ObjectTarget::setScale(float arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_ObjectTarget_setScale(cdata_.get(), arg0);
    return _return_value_;
}
_INLINE_SPECIFIER_ int ObjectTarget::runtimeID()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_ObjectTarget_runtimeID(cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ std::string ObjectTarget::uid()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_String * _return_value_;
    easyar_ObjectTarget_uid(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return std_string_from_easyar_String(std::shared_ptr<easyar_String>(_return_value_, [](easyar_String * ptr) { easyar_String__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::string ObjectTarget::name()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_String * _return_value_;
    easyar_ObjectTarget_name(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return std_string_from_easyar_String(std::shared_ptr<easyar_String>(_return_value_, [](easyar_String * ptr) { easyar_String__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void ObjectTarget::setName(std::string arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_ObjectTarget_setName(cdata_.get(), std_string_to_easyar_String(arg0).get());
}
_INLINE_SPECIFIER_ std::string ObjectTarget::meta()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_String * _return_value_;
    easyar_ObjectTarget_meta(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return std_string_from_easyar_String(std::shared_ptr<easyar_String>(_return_value_, [](easyar_String * ptr) { easyar_String__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void ObjectTarget::setMeta(std::string arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_ObjectTarget_setMeta(cdata_.get(), std_string_to_easyar_String(arg0).get());
}

_INLINE_SPECIFIER_ ObjectTrackerResult::ObjectTrackerResult(std::shared_ptr<easyar_ObjectTrackerResult> cdata)
    :
    TargetTrackerResult(std::shared_ptr<easyar_TargetTrackerResult>(nullptr)),
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ ObjectTrackerResult::~ObjectTrackerResult()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_ObjectTrackerResult> ObjectTrackerResult::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void ObjectTrackerResult::init_cdata(std::shared_ptr<easyar_ObjectTrackerResult> cdata)
{
    cdata_ = cdata;
    {
        easyar_TargetTrackerResult * ptr = nullptr;
        easyar_castObjectTrackerResultToTargetTrackerResult(cdata_.get(), &ptr);
        TargetTrackerResult::init_cdata(std::shared_ptr<easyar_TargetTrackerResult>(ptr, [](easyar_TargetTrackerResult * ptr) { easyar_TargetTrackerResult__dtor(ptr); }));
    }
}
_INLINE_SPECIFIER_ std::shared_ptr<ObjectTrackerResult> ObjectTrackerResult::from_cdata(std::shared_ptr<easyar_ObjectTrackerResult> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<ObjectTrackerResult>(cdata);
}
_INLINE_SPECIFIER_ std::vector<std::shared_ptr<TargetInstance>> ObjectTrackerResult::targetInstances()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_ListOfTargetInstance * _return_value_;
    easyar_ObjectTrackerResult_targetInstances(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return std_vector_from_easyar_ListOfTargetInstance(std::shared_ptr<easyar_ListOfTargetInstance>(_return_value_, [](easyar_ListOfTargetInstance * ptr) { easyar_ListOfTargetInstance__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void ObjectTrackerResult::setTargetInstances(std::vector<std::shared_ptr<TargetInstance>> arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    if (!easyar_ListOfTargetInstance_check_external_cpp(arg0)) { throw std::runtime_error("InvalidArgument: instances"); }
    easyar_ObjectTrackerResult_setTargetInstances(cdata_.get(), std_vector_to_easyar_ListOfTargetInstance(arg0).get());
}

_INLINE_SPECIFIER_ ObjectTracker::ObjectTracker(std::shared_ptr<easyar_ObjectTracker> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ ObjectTracker::~ObjectTracker()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_ObjectTracker> ObjectTracker::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void ObjectTracker::init_cdata(std::shared_ptr<easyar_ObjectTracker> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<ObjectTracker> ObjectTracker::from_cdata(std::shared_ptr<easyar_ObjectTracker> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<ObjectTracker>(cdata);
}
_INLINE_SPECIFIER_ bool ObjectTracker::isAvailable()
{
    auto _return_value_ = easyar_ObjectTracker_isAvailable();
    return _return_value_;
}
_INLINE_SPECIFIER_ std::shared_ptr<FeedbackFrameSink> ObjectTracker::feedbackFrameSink()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_FeedbackFrameSink * _return_value_;
    easyar_ObjectTracker_feedbackFrameSink(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return FeedbackFrameSink::from_cdata(std::shared_ptr<easyar_FeedbackFrameSink>(_return_value_, [](easyar_FeedbackFrameSink * ptr) { easyar_FeedbackFrameSink__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<OutputFrameSource> ObjectTracker::outputFrameSource()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_OutputFrameSource * _return_value_;
    easyar_ObjectTracker_outputFrameSource(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return OutputFrameSource::from_cdata(std::shared_ptr<easyar_OutputFrameSource>(_return_value_, [](easyar_OutputFrameSource * ptr) { easyar_OutputFrameSource__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<ObjectTracker> ObjectTracker::create()
{
    easyar_ObjectTracker * _return_value_;
    easyar_ObjectTracker_create(&_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return ObjectTracker::from_cdata(std::shared_ptr<easyar_ObjectTracker>(_return_value_, [](easyar_ObjectTracker * ptr) { easyar_ObjectTracker__dtor(ptr); }));
}
_INLINE_SPECIFIER_ bool ObjectTracker::start()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_ObjectTracker_start(cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ void ObjectTracker::stop()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_ObjectTracker_stop(cdata_.get());
}
_INLINE_SPECIFIER_ void ObjectTracker::close()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_ObjectTracker_close(cdata_.get());
}
_INLINE_SPECIFIER_ void ObjectTracker::loadTarget(std::shared_ptr<Target> arg0, std::shared_ptr<CallbackScheduler> arg1, std::function<void(std::shared_ptr<Target>, bool)> arg2)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    if (!(arg0 != nullptr)) { throw std::runtime_error("InvalidArgument: target"); }
    if (!(arg1 != nullptr)) { throw std::runtime_error("InvalidArgument: callbackScheduler"); }
    if (!(arg2 != nullptr)) { throw std::runtime_error("InvalidArgument: callback"); }
    easyar_ObjectTracker_loadTarget(cdata_.get(), arg0->get_cdata().get(), arg1->get_cdata().get(), FunctorOfVoidFromTargetAndBool_to_c(arg2));
}
_INLINE_SPECIFIER_ void ObjectTracker::unloadTarget(std::shared_ptr<Target> arg0, std::shared_ptr<CallbackScheduler> arg1, std::function<void(std::shared_ptr<Target>, bool)> arg2)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    if (!(arg0 != nullptr)) { throw std::runtime_error("InvalidArgument: target"); }
    if (!(arg1 != nullptr)) { throw std::runtime_error("InvalidArgument: callbackScheduler"); }
    if (!(arg2 != nullptr)) { throw std::runtime_error("InvalidArgument: callback"); }
    easyar_ObjectTracker_unloadTarget(cdata_.get(), arg0->get_cdata().get(), arg1->get_cdata().get(), FunctorOfVoidFromTargetAndBool_to_c(arg2));
}
_INLINE_SPECIFIER_ std::vector<std::shared_ptr<Target>> ObjectTracker::targets()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_ListOfTarget * _return_value_;
    easyar_ObjectTracker_targets(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return std_vector_from_easyar_ListOfTarget(std::shared_ptr<easyar_ListOfTarget>(_return_value_, [](easyar_ListOfTarget * ptr) { easyar_ListOfTarget__dtor(ptr); }));
}
_INLINE_SPECIFIER_ bool ObjectTracker::setSimultaneousNum(int arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_ObjectTracker_setSimultaneousNum(cdata_.get(), arg0);
    return _return_value_;
}
_INLINE_SPECIFIER_ int ObjectTracker::simultaneousNum()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_ObjectTracker_simultaneousNum(cdata_.get());
    return _return_value_;
}

_INLINE_SPECIFIER_ CADTarget::CADTarget(std::shared_ptr<easyar_CADTarget> cdata)
    :
    Target(std::shared_ptr<easyar_Target>(nullptr)),
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ CADTarget::~CADTarget()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_CADTarget> CADTarget::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void CADTarget::init_cdata(std::shared_ptr<easyar_CADTarget> cdata)
{
    cdata_ = cdata;
    {
        easyar_Target * ptr = nullptr;
        easyar_castCADTargetToTarget(cdata_.get(), &ptr);
        Target::init_cdata(std::shared_ptr<easyar_Target>(ptr, [](easyar_Target * ptr) { easyar_Target__dtor(ptr); }));
    }
}
_INLINE_SPECIFIER_ std::shared_ptr<CADTarget> CADTarget::from_cdata(std::shared_ptr<easyar_CADTarget> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<CADTarget>(cdata);
}
_INLINE_SPECIFIER_ CADTarget::CADTarget()
    :
    Target(std::shared_ptr<easyar_Target>(nullptr)),
    cdata_(nullptr)
{
    easyar_CADTarget * _return_value_;
    easyar_CADTarget__ctor(&_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); };
    init_cdata(std::shared_ptr<easyar_CADTarget>(_return_value_, [](easyar_CADTarget * ptr) { easyar_CADTarget__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::optional<std::shared_ptr<CADTarget>> CADTarget::createFromUnity(std::shared_ptr<Buffer> arg0, std::shared_ptr<Buffer> arg1, Matrix44F arg2, float arg3)
{
    if (!(arg0 != nullptr)) { throw std::runtime_error("InvalidArgument: vertices"); }
    if (!(arg1 != nullptr)) { throw std::runtime_error("InvalidArgument: faces"); }
    easyar_OptionalOfCADTarget _return_value_;
    easyar_CADTarget_createFromUnity(arg0->get_cdata().get(), arg1->get_cdata().get(), easyar_Matrix44F{{arg2.data[0], arg2.data[1], arg2.data[2], arg2.data[3], arg2.data[4], arg2.data[5], arg2.data[6], arg2.data[7], arg2.data[8], arg2.data[9], arg2.data[10], arg2.data[11], arg2.data[12], arg2.data[13], arg2.data[14], arg2.data[15]}}, arg3, &_return_value_);
    if (!(!_return_value_.has_value || (_return_value_.value != nullptr))) { throw std::runtime_error("InvalidReturnValue"); }
    return (_return_value_.has_value ? CADTarget::from_cdata(std::shared_ptr<easyar_CADTarget>(_return_value_.value, [](easyar_CADTarget * ptr) { easyar_CADTarget__dtor(ptr); })) : std::optional<std::shared_ptr<CADTarget>>{});
}
_INLINE_SPECIFIER_ void CADTarget::updateTransform(Matrix44F arg0, float arg1)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_CADTarget_updateTransform(cdata_.get(), easyar_Matrix44F{{arg0.data[0], arg0.data[1], arg0.data[2], arg0.data[3], arg0.data[4], arg0.data[5], arg0.data[6], arg0.data[7], arg0.data[8], arg0.data[9], arg0.data[10], arg0.data[11], arg0.data[12], arg0.data[13], arg0.data[14], arg0.data[15]}}, arg1);
}
_INLINE_SPECIFIER_ void CADTarget::updateTrackConfig(float arg0, float arg1, float arg2)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_CADTarget_updateTrackConfig(cdata_.get(), arg0, arg1, arg2);
}
_INLINE_SPECIFIER_ std::optional<std::shared_ptr<CADTarget>> CADTarget::createFromObjectFile(std::string arg0, StorageType arg1, std::string arg2, std::string arg3, std::string arg4, float arg5)
{
    easyar_OptionalOfCADTarget _return_value_;
    easyar_CADTarget_createFromObjectFile(std_string_to_easyar_String(arg0).get(), static_cast<easyar_StorageType>(arg1), std_string_to_easyar_String(arg2).get(), std_string_to_easyar_String(arg3).get(), std_string_to_easyar_String(arg4).get(), arg5, &_return_value_);
    if (!(!_return_value_.has_value || (_return_value_.value != nullptr))) { throw std::runtime_error("InvalidReturnValue"); }
    return (_return_value_.has_value ? CADTarget::from_cdata(std::shared_ptr<easyar_CADTarget>(_return_value_.value, [](easyar_CADTarget * ptr) { easyar_CADTarget__dtor(ptr); })) : std::optional<std::shared_ptr<CADTarget>>{});
}
_INLINE_SPECIFIER_ std::vector<std::shared_ptr<CADTarget>> CADTarget::setupAll(std::string arg0, StorageType arg1)
{
    easyar_ListOfCADTarget * _return_value_;
    easyar_CADTarget_setupAll(std_string_to_easyar_String(arg0).get(), static_cast<easyar_StorageType>(arg1), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return std_vector_from_easyar_ListOfCADTarget(std::shared_ptr<easyar_ListOfCADTarget>(_return_value_, [](easyar_ListOfCADTarget * ptr) { easyar_ListOfCADTarget__dtor(ptr); }));
}
_INLINE_SPECIFIER_ float CADTarget::scale()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_CADTarget_scale(cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ std::vector<Vec3F> CADTarget::boundingBox()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_ListOfVec3F * _return_value_;
    easyar_CADTarget_boundingBox(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return std_vector_from_easyar_ListOfVec3F(std::shared_ptr<easyar_ListOfVec3F>(_return_value_, [](easyar_ListOfVec3F * ptr) { easyar_ListOfVec3F__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::vector<Vec3F> CADTarget::boundingBoxGL()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_ListOfVec3F * _return_value_;
    easyar_CADTarget_boundingBoxGL(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return std_vector_from_easyar_ListOfVec3F(std::shared_ptr<easyar_ListOfVec3F>(_return_value_, [](easyar_ListOfVec3F * ptr) { easyar_ListOfVec3F__dtor(ptr); }));
}
_INLINE_SPECIFIER_ bool CADTarget::setScale(float arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_CADTarget_setScale(cdata_.get(), arg0);
    return _return_value_;
}
_INLINE_SPECIFIER_ int CADTarget::runtimeID()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_CADTarget_runtimeID(cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ std::string CADTarget::uid()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_String * _return_value_;
    easyar_CADTarget_uid(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return std_string_from_easyar_String(std::shared_ptr<easyar_String>(_return_value_, [](easyar_String * ptr) { easyar_String__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::string CADTarget::name()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_String * _return_value_;
    easyar_CADTarget_name(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return std_string_from_easyar_String(std::shared_ptr<easyar_String>(_return_value_, [](easyar_String * ptr) { easyar_String__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void CADTarget::setName(std::string arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_CADTarget_setName(cdata_.get(), std_string_to_easyar_String(arg0).get());
}
_INLINE_SPECIFIER_ std::string CADTarget::meta()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_String * _return_value_;
    easyar_CADTarget_meta(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return std_string_from_easyar_String(std::shared_ptr<easyar_String>(_return_value_, [](easyar_String * ptr) { easyar_String__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void CADTarget::setMeta(std::string arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_CADTarget_setMeta(cdata_.get(), std_string_to_easyar_String(arg0).get());
}

_INLINE_SPECIFIER_ CADTrackerResult::CADTrackerResult(std::shared_ptr<easyar_CADTrackerResult> cdata)
    :
    TargetTrackerResult(std::shared_ptr<easyar_TargetTrackerResult>(nullptr)),
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ CADTrackerResult::~CADTrackerResult()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_CADTrackerResult> CADTrackerResult::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void CADTrackerResult::init_cdata(std::shared_ptr<easyar_CADTrackerResult> cdata)
{
    cdata_ = cdata;
    {
        easyar_TargetTrackerResult * ptr = nullptr;
        easyar_castCADTrackerResultToTargetTrackerResult(cdata_.get(), &ptr);
        TargetTrackerResult::init_cdata(std::shared_ptr<easyar_TargetTrackerResult>(ptr, [](easyar_TargetTrackerResult * ptr) { easyar_TargetTrackerResult__dtor(ptr); }));
    }
}
_INLINE_SPECIFIER_ std::shared_ptr<CADTrackerResult> CADTrackerResult::from_cdata(std::shared_ptr<easyar_CADTrackerResult> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<CADTrackerResult>(cdata);
}
_INLINE_SPECIFIER_ std::vector<std::shared_ptr<TargetInstance>> CADTrackerResult::targetInstances()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_ListOfTargetInstance * _return_value_;
    easyar_CADTrackerResult_targetInstances(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return std_vector_from_easyar_ListOfTargetInstance(std::shared_ptr<easyar_ListOfTargetInstance>(_return_value_, [](easyar_ListOfTargetInstance * ptr) { easyar_ListOfTargetInstance__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void CADTrackerResult::setTargetInstances(std::vector<std::shared_ptr<TargetInstance>> arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    if (!easyar_ListOfTargetInstance_check_external_cpp(arg0)) { throw std::runtime_error("InvalidArgument: instances"); }
    easyar_CADTrackerResult_setTargetInstances(cdata_.get(), std_vector_to_easyar_ListOfTargetInstance(arg0).get());
}

_INLINE_SPECIFIER_ CADTracker::CADTracker(std::shared_ptr<easyar_CADTracker> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ CADTracker::~CADTracker()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_CADTracker> CADTracker::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void CADTracker::init_cdata(std::shared_ptr<easyar_CADTracker> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<CADTracker> CADTracker::from_cdata(std::shared_ptr<easyar_CADTracker> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<CADTracker>(cdata);
}
_INLINE_SPECIFIER_ bool CADTracker::isAvailable()
{
    auto _return_value_ = easyar_CADTracker_isAvailable();
    return _return_value_;
}
_INLINE_SPECIFIER_ std::shared_ptr<FeedbackFrameSink> CADTracker::feedbackFrameSink()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_FeedbackFrameSink * _return_value_;
    easyar_CADTracker_feedbackFrameSink(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return FeedbackFrameSink::from_cdata(std::shared_ptr<easyar_FeedbackFrameSink>(_return_value_, [](easyar_FeedbackFrameSink * ptr) { easyar_FeedbackFrameSink__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<OutputFrameSource> CADTracker::outputFrameSource()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_OutputFrameSource * _return_value_;
    easyar_CADTracker_outputFrameSource(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return OutputFrameSource::from_cdata(std::shared_ptr<easyar_OutputFrameSource>(_return_value_, [](easyar_OutputFrameSource * ptr) { easyar_OutputFrameSource__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<CADTracker> CADTracker::create()
{
    easyar_CADTracker * _return_value_;
    easyar_CADTracker_create(&_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return CADTracker::from_cdata(std::shared_ptr<easyar_CADTracker>(_return_value_, [](easyar_CADTracker * ptr) { easyar_CADTracker__dtor(ptr); }));
}
_INLINE_SPECIFIER_ bool CADTracker::start()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_CADTracker_start(cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ void CADTracker::stop()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_CADTracker_stop(cdata_.get());
}
_INLINE_SPECIFIER_ void CADTracker::close()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_CADTracker_close(cdata_.get());
}
_INLINE_SPECIFIER_ void CADTracker::loadTarget(std::shared_ptr<Target> arg0, std::shared_ptr<CallbackScheduler> arg1, std::function<void(std::shared_ptr<Target>, bool)> arg2)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    if (!(arg0 != nullptr)) { throw std::runtime_error("InvalidArgument: target"); }
    if (!(arg1 != nullptr)) { throw std::runtime_error("InvalidArgument: callbackScheduler"); }
    if (!(arg2 != nullptr)) { throw std::runtime_error("InvalidArgument: callback"); }
    easyar_CADTracker_loadTarget(cdata_.get(), arg0->get_cdata().get(), arg1->get_cdata().get(), FunctorOfVoidFromTargetAndBool_to_c(arg2));
}
_INLINE_SPECIFIER_ void CADTracker::unloadTarget(std::shared_ptr<Target> arg0, std::shared_ptr<CallbackScheduler> arg1, std::function<void(std::shared_ptr<Target>, bool)> arg2)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    if (!(arg0 != nullptr)) { throw std::runtime_error("InvalidArgument: target"); }
    if (!(arg1 != nullptr)) { throw std::runtime_error("InvalidArgument: callbackScheduler"); }
    if (!(arg2 != nullptr)) { throw std::runtime_error("InvalidArgument: callback"); }
    easyar_CADTracker_unloadTarget(cdata_.get(), arg0->get_cdata().get(), arg1->get_cdata().get(), FunctorOfVoidFromTargetAndBool_to_c(arg2));
}
_INLINE_SPECIFIER_ std::vector<std::shared_ptr<Target>> CADTracker::targets()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_ListOfTarget * _return_value_;
    easyar_CADTracker_targets(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return std_vector_from_easyar_ListOfTarget(std::shared_ptr<easyar_ListOfTarget>(_return_value_, [](easyar_ListOfTarget * ptr) { easyar_ListOfTarget__dtor(ptr); }));
}

_INLINE_SPECIFIER_ CloudRecognizer::CloudRecognizer(std::shared_ptr<easyar_CloudRecognizer> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ CloudRecognizer::~CloudRecognizer()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_CloudRecognizer> CloudRecognizer::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void CloudRecognizer::init_cdata(std::shared_ptr<easyar_CloudRecognizer> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<CloudRecognizer> CloudRecognizer::from_cdata(std::shared_ptr<easyar_CloudRecognizer> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<CloudRecognizer>(cdata);
}
_INLINE_SPECIFIER_ bool CloudRecognizer::isAvailable()
{
    auto _return_value_ = easyar_CloudRecognizer_isAvailable();
    return _return_value_;
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrameSink> CloudRecognizer::inputFrameSink()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_InputFrameSink * _return_value_;
    easyar_CloudRecognizer_inputFrameSink(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return InputFrameSink::from_cdata(std::shared_ptr<easyar_InputFrameSink>(_return_value_, [](easyar_InputFrameSink * ptr) { easyar_InputFrameSink__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<CloudRecognizer> CloudRecognizer::create(std::string arg0, std::string arg1, std::string arg2, std::shared_ptr<CallbackScheduler> arg3, std::optional<std::function<void(CloudStatus, std::vector<std::shared_ptr<Target>>)>> arg4)
{
    if (!(arg3 != nullptr)) { throw std::runtime_error("InvalidArgument: callbackScheduler"); }
    if (!(!arg4.has_value() || (arg4.value() != nullptr))) { throw std::runtime_error("InvalidArgument: callback"); }
    easyar_CloudRecognizer * _return_value_;
    easyar_CloudRecognizer_create(std_string_to_easyar_String(arg0).get(), std_string_to_easyar_String(arg1).get(), std_string_to_easyar_String(arg2).get(), arg3->get_cdata().get(), (arg4.has_value() ? easyar_OptionalOfFunctorOfVoidFromCloudStatusAndListOfTarget{true, FunctorOfVoidFromCloudStatusAndListOfTarget_to_c(arg4.value())} : easyar_OptionalOfFunctorOfVoidFromCloudStatusAndListOfTarget{false, {}}), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return CloudRecognizer::from_cdata(std::shared_ptr<easyar_CloudRecognizer>(_return_value_, [](easyar_CloudRecognizer * ptr) { easyar_CloudRecognizer__dtor(ptr); }));
}
_INLINE_SPECIFIER_ bool CloudRecognizer::start()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_CloudRecognizer_start(cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ void CloudRecognizer::stop()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_CloudRecognizer_stop(cdata_.get());
}
_INLINE_SPECIFIER_ void CloudRecognizer::close()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_CloudRecognizer_close(cdata_.get());
}

_INLINE_SPECIFIER_ DenseSpatialMap::DenseSpatialMap(std::shared_ptr<easyar_DenseSpatialMap> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ DenseSpatialMap::~DenseSpatialMap()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_DenseSpatialMap> DenseSpatialMap::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void DenseSpatialMap::init_cdata(std::shared_ptr<easyar_DenseSpatialMap> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<DenseSpatialMap> DenseSpatialMap::from_cdata(std::shared_ptr<easyar_DenseSpatialMap> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<DenseSpatialMap>(cdata);
}
_INLINE_SPECIFIER_ bool DenseSpatialMap::isAvailable()
{
    auto _return_value_ = easyar_DenseSpatialMap_isAvailable();
    return _return_value_;
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrameSink> DenseSpatialMap::inputFrameSink()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_InputFrameSink * _return_value_;
    easyar_DenseSpatialMap_inputFrameSink(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return InputFrameSink::from_cdata(std::shared_ptr<easyar_InputFrameSink>(_return_value_, [](easyar_InputFrameSink * ptr) { easyar_InputFrameSink__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<DenseSpatialMap> DenseSpatialMap::create()
{
    easyar_DenseSpatialMap * _return_value_;
    easyar_DenseSpatialMap_create(&_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return DenseSpatialMap::from_cdata(std::shared_ptr<easyar_DenseSpatialMap>(_return_value_, [](easyar_DenseSpatialMap * ptr) { easyar_DenseSpatialMap__dtor(ptr); }));
}
_INLINE_SPECIFIER_ bool DenseSpatialMap::start()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_DenseSpatialMap_start(cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ void DenseSpatialMap::stop()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_DenseSpatialMap_stop(cdata_.get());
}
_INLINE_SPECIFIER_ void DenseSpatialMap::close()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_DenseSpatialMap_close(cdata_.get());
}
_INLINE_SPECIFIER_ std::string DenseSpatialMap::saveMap()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_String * _return_value_;
    easyar_DenseSpatialMap_saveMap(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return std_string_from_easyar_String(std::shared_ptr<easyar_String>(_return_value_, [](easyar_String * ptr) { easyar_String__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<SceneMesh> DenseSpatialMap::getMesh()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_SceneMesh * _return_value_;
    easyar_DenseSpatialMap_getMesh(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return SceneMesh::from_cdata(std::shared_ptr<easyar_SceneMesh>(_return_value_, [](easyar_SceneMesh * ptr) { easyar_SceneMesh__dtor(ptr); }));
}
_INLINE_SPECIFIER_ bool DenseSpatialMap::updateSceneMesh(bool arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_DenseSpatialMap_updateSceneMesh(cdata_.get(), arg0);
    return _return_value_;
}

_INLINE_SPECIFIER_ SceneMesh::SceneMesh(std::shared_ptr<easyar_SceneMesh> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ SceneMesh::~SceneMesh()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_SceneMesh> SceneMesh::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void SceneMesh::init_cdata(std::shared_ptr<easyar_SceneMesh> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<SceneMesh> SceneMesh::from_cdata(std::shared_ptr<easyar_SceneMesh> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<SceneMesh>(cdata);
}
_INLINE_SPECIFIER_ SceneMesh::SceneMesh()
    :
    cdata_(nullptr)
{
    easyar_SceneMesh * _return_value_;
    easyar_SceneMesh__ctor(&_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); };
    init_cdata(std::shared_ptr<easyar_SceneMesh>(_return_value_, [](easyar_SceneMesh * ptr) { easyar_SceneMesh__dtor(ptr); }));
}
_INLINE_SPECIFIER_ int SceneMesh::getNumOfVertexAll()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_SceneMesh_getNumOfVertexAll(cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ int SceneMesh::getNumOfIndexAll()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_SceneMesh_getNumOfIndexAll(cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ std::shared_ptr<Buffer> SceneMesh::getVerticesAll()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_Buffer * _return_value_;
    easyar_SceneMesh_getVerticesAll(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return Buffer::from_cdata(std::shared_ptr<easyar_Buffer>(_return_value_, [](easyar_Buffer * ptr) { easyar_Buffer__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<Buffer> SceneMesh::getNormalsAll()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_Buffer * _return_value_;
    easyar_SceneMesh_getNormalsAll(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return Buffer::from_cdata(std::shared_ptr<easyar_Buffer>(_return_value_, [](easyar_Buffer * ptr) { easyar_Buffer__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<Buffer> SceneMesh::getIndicesAll()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_Buffer * _return_value_;
    easyar_SceneMesh_getIndicesAll(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return Buffer::from_cdata(std::shared_ptr<easyar_Buffer>(_return_value_, [](easyar_Buffer * ptr) { easyar_Buffer__dtor(ptr); }));
}
_INLINE_SPECIFIER_ int SceneMesh::getNumOfVertexIncremental()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_SceneMesh_getNumOfVertexIncremental(cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ int SceneMesh::getNumOfIndexIncremental()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_SceneMesh_getNumOfIndexIncremental(cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ std::shared_ptr<Buffer> SceneMesh::getVerticesIncremental()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_Buffer * _return_value_;
    easyar_SceneMesh_getVerticesIncremental(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return Buffer::from_cdata(std::shared_ptr<easyar_Buffer>(_return_value_, [](easyar_Buffer * ptr) { easyar_Buffer__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<Buffer> SceneMesh::getNormalsIncremental()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_Buffer * _return_value_;
    easyar_SceneMesh_getNormalsIncremental(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return Buffer::from_cdata(std::shared_ptr<easyar_Buffer>(_return_value_, [](easyar_Buffer * ptr) { easyar_Buffer__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<Buffer> SceneMesh::getIndicesIncremental()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_Buffer * _return_value_;
    easyar_SceneMesh_getIndicesIncremental(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return Buffer::from_cdata(std::shared_ptr<easyar_Buffer>(_return_value_, [](easyar_Buffer * ptr) { easyar_Buffer__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::vector<BlockInfo> SceneMesh::getBlocksInfoIncremental()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_ListOfBlockInfo * _return_value_;
    easyar_SceneMesh_getBlocksInfoIncremental(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return std_vector_from_easyar_ListOfBlockInfo(std::shared_ptr<easyar_ListOfBlockInfo>(_return_value_, [](easyar_ListOfBlockInfo * ptr) { easyar_ListOfBlockInfo__dtor(ptr); }));
}
_INLINE_SPECIFIER_ float SceneMesh::getBlockDimentionInMeters()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_SceneMesh_getBlockDimentionInMeters(cdata_.get());
    return _return_value_;
}

_INLINE_SPECIFIER_ SurfaceTrackerResult::SurfaceTrackerResult(std::shared_ptr<easyar_SurfaceTrackerResult> cdata)
    :
    FrameFilterResult(std::shared_ptr<easyar_FrameFilterResult>(nullptr)),
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ SurfaceTrackerResult::~SurfaceTrackerResult()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_SurfaceTrackerResult> SurfaceTrackerResult::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void SurfaceTrackerResult::init_cdata(std::shared_ptr<easyar_SurfaceTrackerResult> cdata)
{
    cdata_ = cdata;
    {
        easyar_FrameFilterResult * ptr = nullptr;
        easyar_castSurfaceTrackerResultToFrameFilterResult(cdata_.get(), &ptr);
        FrameFilterResult::init_cdata(std::shared_ptr<easyar_FrameFilterResult>(ptr, [](easyar_FrameFilterResult * ptr) { easyar_FrameFilterResult__dtor(ptr); }));
    }
}
_INLINE_SPECIFIER_ std::shared_ptr<SurfaceTrackerResult> SurfaceTrackerResult::from_cdata(std::shared_ptr<easyar_SurfaceTrackerResult> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<SurfaceTrackerResult>(cdata);
}
_INLINE_SPECIFIER_ Matrix44F SurfaceTrackerResult::transform()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_SurfaceTrackerResult_transform(cdata_.get());
    return Matrix44F{{{_return_value_.data[0], _return_value_.data[1], _return_value_.data[2], _return_value_.data[3], _return_value_.data[4], _return_value_.data[5], _return_value_.data[6], _return_value_.data[7], _return_value_.data[8], _return_value_.data[9], _return_value_.data[10], _return_value_.data[11], _return_value_.data[12], _return_value_.data[13], _return_value_.data[14], _return_value_.data[15]}}};
}
_INLINE_SPECIFIER_ SurfaceTrackingStatus SurfaceTrackerResult::status()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_SurfaceTrackerResult_status(cdata_.get());
    return static_cast<SurfaceTrackingStatus>(_return_value_);
}

_INLINE_SPECIFIER_ SurfaceTracker::SurfaceTracker(std::shared_ptr<easyar_SurfaceTracker> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ SurfaceTracker::~SurfaceTracker()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_SurfaceTracker> SurfaceTracker::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void SurfaceTracker::init_cdata(std::shared_ptr<easyar_SurfaceTracker> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<SurfaceTracker> SurfaceTracker::from_cdata(std::shared_ptr<easyar_SurfaceTracker> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<SurfaceTracker>(cdata);
}
_INLINE_SPECIFIER_ bool SurfaceTracker::isAvailable()
{
    auto _return_value_ = easyar_SurfaceTracker_isAvailable();
    return _return_value_;
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrameSink> SurfaceTracker::inputFrameSink()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_InputFrameSink * _return_value_;
    easyar_SurfaceTracker_inputFrameSink(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return InputFrameSink::from_cdata(std::shared_ptr<easyar_InputFrameSink>(_return_value_, [](easyar_InputFrameSink * ptr) { easyar_InputFrameSink__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<OutputFrameSource> SurfaceTracker::outputFrameSource()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_OutputFrameSource * _return_value_;
    easyar_SurfaceTracker_outputFrameSource(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return OutputFrameSource::from_cdata(std::shared_ptr<easyar_OutputFrameSource>(_return_value_, [](easyar_OutputFrameSource * ptr) { easyar_OutputFrameSource__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<SurfaceTracker> SurfaceTracker::create()
{
    easyar_SurfaceTracker * _return_value_;
    easyar_SurfaceTracker_create(&_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return SurfaceTracker::from_cdata(std::shared_ptr<easyar_SurfaceTracker>(_return_value_, [](easyar_SurfaceTracker * ptr) { easyar_SurfaceTracker__dtor(ptr); }));
}
_INLINE_SPECIFIER_ bool SurfaceTracker::start()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_SurfaceTracker_start(cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ void SurfaceTracker::stop()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_SurfaceTracker_stop(cdata_.get());
}
_INLINE_SPECIFIER_ void SurfaceTracker::close()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_SurfaceTracker_close(cdata_.get());
}
_INLINE_SPECIFIER_ void SurfaceTracker::alignTargetToCameraImagePoint(Vec2F arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_SurfaceTracker_alignTargetToCameraImagePoint(cdata_.get(), easyar_Vec2F{{arg0.data[0], arg0.data[1]}});
}

_INLINE_SPECIFIER_ MotionTrackerResult::MotionTrackerResult(std::shared_ptr<easyar_MotionTrackerResult> cdata)
    :
    FrameFilterResult(std::shared_ptr<easyar_FrameFilterResult>(nullptr)),
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ MotionTrackerResult::~MotionTrackerResult()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_MotionTrackerResult> MotionTrackerResult::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void MotionTrackerResult::init_cdata(std::shared_ptr<easyar_MotionTrackerResult> cdata)
{
    cdata_ = cdata;
    {
        easyar_FrameFilterResult * ptr = nullptr;
        easyar_castMotionTrackerResultToFrameFilterResult(cdata_.get(), &ptr);
        FrameFilterResult::init_cdata(std::shared_ptr<easyar_FrameFilterResult>(ptr, [](easyar_FrameFilterResult * ptr) { easyar_FrameFilterResult__dtor(ptr); }));
    }
}
_INLINE_SPECIFIER_ std::shared_ptr<MotionTrackerResult> MotionTrackerResult::from_cdata(std::shared_ptr<easyar_MotionTrackerResult> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<MotionTrackerResult>(cdata);
}
_INLINE_SPECIFIER_ Matrix44F MotionTrackerResult::transform()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_MotionTrackerResult_transform(cdata_.get());
    return Matrix44F{{{_return_value_.data[0], _return_value_.data[1], _return_value_.data[2], _return_value_.data[3], _return_value_.data[4], _return_value_.data[5], _return_value_.data[6], _return_value_.data[7], _return_value_.data[8], _return_value_.data[9], _return_value_.data[10], _return_value_.data[11], _return_value_.data[12], _return_value_.data[13], _return_value_.data[14], _return_value_.data[15]}}};
}
_INLINE_SPECIFIER_ MotionTrackingStatus MotionTrackerResult::status()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_MotionTrackerResult_status(cdata_.get());
    return static_cast<MotionTrackingStatus>(_return_value_);
}

_INLINE_SPECIFIER_ MotionTracker::MotionTracker(std::shared_ptr<easyar_MotionTracker> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ MotionTracker::~MotionTracker()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_MotionTracker> MotionTracker::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void MotionTracker::init_cdata(std::shared_ptr<easyar_MotionTracker> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<MotionTracker> MotionTracker::from_cdata(std::shared_ptr<easyar_MotionTracker> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<MotionTracker>(cdata);
}
_INLINE_SPECIFIER_ bool MotionTracker::isAvailable()
{
    auto _return_value_ = easyar_MotionTracker_isAvailable();
    return _return_value_;
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrameSink> MotionTracker::inputFrameSink()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_InputFrameSink * _return_value_;
    easyar_MotionTracker_inputFrameSink(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return InputFrameSink::from_cdata(std::shared_ptr<easyar_InputFrameSink>(_return_value_, [](easyar_InputFrameSink * ptr) { easyar_InputFrameSink__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<OutputFrameSource> MotionTracker::outputFrameSource()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_OutputFrameSource * _return_value_;
    easyar_MotionTracker_outputFrameSource(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return OutputFrameSource::from_cdata(std::shared_ptr<easyar_OutputFrameSource>(_return_value_, [](easyar_OutputFrameSource * ptr) { easyar_OutputFrameSource__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<MotionTracker> MotionTracker::create()
{
    easyar_MotionTracker * _return_value_;
    easyar_MotionTracker_create(&_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return MotionTracker::from_cdata(std::shared_ptr<easyar_MotionTracker>(_return_value_, [](easyar_MotionTracker * ptr) { easyar_MotionTracker__dtor(ptr); }));
}
_INLINE_SPECIFIER_ bool MotionTracker::start()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_MotionTracker_start(cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ void MotionTracker::stop()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_MotionTracker_stop(cdata_.get());
}
_INLINE_SPECIFIER_ void MotionTracker::close()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_MotionTracker_close(cdata_.get());
}

_INLINE_SPECIFIER_ MotionTrackerOutputFrameToInputFrameAdapter::MotionTrackerOutputFrameToInputFrameAdapter(std::shared_ptr<easyar_MotionTrackerOutputFrameToInputFrameAdapter> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ MotionTrackerOutputFrameToInputFrameAdapter::~MotionTrackerOutputFrameToInputFrameAdapter()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_MotionTrackerOutputFrameToInputFrameAdapter> MotionTrackerOutputFrameToInputFrameAdapter::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void MotionTrackerOutputFrameToInputFrameAdapter::init_cdata(std::shared_ptr<easyar_MotionTrackerOutputFrameToInputFrameAdapter> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<MotionTrackerOutputFrameToInputFrameAdapter> MotionTrackerOutputFrameToInputFrameAdapter::from_cdata(std::shared_ptr<easyar_MotionTrackerOutputFrameToInputFrameAdapter> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<MotionTrackerOutputFrameToInputFrameAdapter>(cdata);
}
_INLINE_SPECIFIER_ std::shared_ptr<OutputFrameSink> MotionTrackerOutputFrameToInputFrameAdapter::input()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_OutputFrameSink * _return_value_;
    easyar_MotionTrackerOutputFrameToInputFrameAdapter_input(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return OutputFrameSink::from_cdata(std::shared_ptr<easyar_OutputFrameSink>(_return_value_, [](easyar_OutputFrameSink * ptr) { easyar_OutputFrameSink__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrameSource> MotionTrackerOutputFrameToInputFrameAdapter::output()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_InputFrameSource * _return_value_;
    easyar_MotionTrackerOutputFrameToInputFrameAdapter_output(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return InputFrameSource::from_cdata(std::shared_ptr<easyar_InputFrameSource>(_return_value_, [](easyar_InputFrameSource * ptr) { easyar_InputFrameSource__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<MotionTrackerOutputFrameToInputFrameAdapter> MotionTrackerOutputFrameToInputFrameAdapter::create()
{
    easyar_MotionTrackerOutputFrameToInputFrameAdapter * _return_value_;
    easyar_MotionTrackerOutputFrameToInputFrameAdapter_create(&_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return MotionTrackerOutputFrameToInputFrameAdapter::from_cdata(std::shared_ptr<easyar_MotionTrackerOutputFrameToInputFrameAdapter>(_return_value_, [](easyar_MotionTrackerOutputFrameToInputFrameAdapter * ptr) { easyar_MotionTrackerOutputFrameToInputFrameAdapter__dtor(ptr); }));
}

_INLINE_SPECIFIER_ ImageTargetParameters::ImageTargetParameters(std::shared_ptr<easyar_ImageTargetParameters> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ ImageTargetParameters::~ImageTargetParameters()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_ImageTargetParameters> ImageTargetParameters::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void ImageTargetParameters::init_cdata(std::shared_ptr<easyar_ImageTargetParameters> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<ImageTargetParameters> ImageTargetParameters::from_cdata(std::shared_ptr<easyar_ImageTargetParameters> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<ImageTargetParameters>(cdata);
}
_INLINE_SPECIFIER_ ImageTargetParameters::ImageTargetParameters()
    :
    cdata_(nullptr)
{
    easyar_ImageTargetParameters * _return_value_;
    easyar_ImageTargetParameters__ctor(&_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); };
    init_cdata(std::shared_ptr<easyar_ImageTargetParameters>(_return_value_, [](easyar_ImageTargetParameters * ptr) { easyar_ImageTargetParameters__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<Image> ImageTargetParameters::image()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_Image * _return_value_;
    easyar_ImageTargetParameters_image(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return Image::from_cdata(std::shared_ptr<easyar_Image>(_return_value_, [](easyar_Image * ptr) { easyar_Image__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void ImageTargetParameters::setImage(std::shared_ptr<Image> arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    if (!(arg0 != nullptr)) { throw std::runtime_error("InvalidArgument: image"); }
    easyar_ImageTargetParameters_setImage(cdata_.get(), arg0->get_cdata().get());
}
_INLINE_SPECIFIER_ std::string ImageTargetParameters::name()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_String * _return_value_;
    easyar_ImageTargetParameters_name(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return std_string_from_easyar_String(std::shared_ptr<easyar_String>(_return_value_, [](easyar_String * ptr) { easyar_String__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void ImageTargetParameters::setName(std::string arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_ImageTargetParameters_setName(cdata_.get(), std_string_to_easyar_String(arg0).get());
}
_INLINE_SPECIFIER_ std::string ImageTargetParameters::uid()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_String * _return_value_;
    easyar_ImageTargetParameters_uid(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return std_string_from_easyar_String(std::shared_ptr<easyar_String>(_return_value_, [](easyar_String * ptr) { easyar_String__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void ImageTargetParameters::setUid(std::string arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_ImageTargetParameters_setUid(cdata_.get(), std_string_to_easyar_String(arg0).get());
}
_INLINE_SPECIFIER_ std::string ImageTargetParameters::meta()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_String * _return_value_;
    easyar_ImageTargetParameters_meta(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return std_string_from_easyar_String(std::shared_ptr<easyar_String>(_return_value_, [](easyar_String * ptr) { easyar_String__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void ImageTargetParameters::setMeta(std::string arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_ImageTargetParameters_setMeta(cdata_.get(), std_string_to_easyar_String(arg0).get());
}
_INLINE_SPECIFIER_ float ImageTargetParameters::scale()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_ImageTargetParameters_scale(cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ void ImageTargetParameters::setScale(float arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_ImageTargetParameters_setScale(cdata_.get(), arg0);
}

_INLINE_SPECIFIER_ ImageTarget::ImageTarget(std::shared_ptr<easyar_ImageTarget> cdata)
    :
    Target(std::shared_ptr<easyar_Target>(nullptr)),
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ ImageTarget::~ImageTarget()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_ImageTarget> ImageTarget::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void ImageTarget::init_cdata(std::shared_ptr<easyar_ImageTarget> cdata)
{
    cdata_ = cdata;
    {
        easyar_Target * ptr = nullptr;
        easyar_castImageTargetToTarget(cdata_.get(), &ptr);
        Target::init_cdata(std::shared_ptr<easyar_Target>(ptr, [](easyar_Target * ptr) { easyar_Target__dtor(ptr); }));
    }
}
_INLINE_SPECIFIER_ std::shared_ptr<ImageTarget> ImageTarget::from_cdata(std::shared_ptr<easyar_ImageTarget> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<ImageTarget>(cdata);
}
_INLINE_SPECIFIER_ ImageTarget::ImageTarget()
    :
    Target(std::shared_ptr<easyar_Target>(nullptr)),
    cdata_(nullptr)
{
    easyar_ImageTarget * _return_value_;
    easyar_ImageTarget__ctor(&_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); };
    init_cdata(std::shared_ptr<easyar_ImageTarget>(_return_value_, [](easyar_ImageTarget * ptr) { easyar_ImageTarget__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::optional<std::shared_ptr<ImageTarget>> ImageTarget::createFromParameters(std::shared_ptr<ImageTargetParameters> arg0)
{
    if (!(arg0 != nullptr)) { throw std::runtime_error("InvalidArgument: parameters"); }
    easyar_OptionalOfImageTarget _return_value_;
    easyar_ImageTarget_createFromParameters(arg0->get_cdata().get(), &_return_value_);
    if (!(!_return_value_.has_value || (_return_value_.value != nullptr))) { throw std::runtime_error("InvalidReturnValue"); }
    return (_return_value_.has_value ? ImageTarget::from_cdata(std::shared_ptr<easyar_ImageTarget>(_return_value_.value, [](easyar_ImageTarget * ptr) { easyar_ImageTarget__dtor(ptr); })) : std::optional<std::shared_ptr<ImageTarget>>{});
}
_INLINE_SPECIFIER_ std::optional<std::shared_ptr<ImageTarget>> ImageTarget::createFromTargetFile(std::string arg0, StorageType arg1)
{
    easyar_OptionalOfImageTarget _return_value_;
    easyar_ImageTarget_createFromTargetFile(std_string_to_easyar_String(arg0).get(), static_cast<easyar_StorageType>(arg1), &_return_value_);
    if (!(!_return_value_.has_value || (_return_value_.value != nullptr))) { throw std::runtime_error("InvalidReturnValue"); }
    return (_return_value_.has_value ? ImageTarget::from_cdata(std::shared_ptr<easyar_ImageTarget>(_return_value_.value, [](easyar_ImageTarget * ptr) { easyar_ImageTarget__dtor(ptr); })) : std::optional<std::shared_ptr<ImageTarget>>{});
}
_INLINE_SPECIFIER_ std::optional<std::shared_ptr<ImageTarget>> ImageTarget::createFromTargetData(std::shared_ptr<Buffer> arg0)
{
    if (!(arg0 != nullptr)) { throw std::runtime_error("InvalidArgument: buffer"); }
    easyar_OptionalOfImageTarget _return_value_;
    easyar_ImageTarget_createFromTargetData(arg0->get_cdata().get(), &_return_value_);
    if (!(!_return_value_.has_value || (_return_value_.value != nullptr))) { throw std::runtime_error("InvalidReturnValue"); }
    return (_return_value_.has_value ? ImageTarget::from_cdata(std::shared_ptr<easyar_ImageTarget>(_return_value_.value, [](easyar_ImageTarget * ptr) { easyar_ImageTarget__dtor(ptr); })) : std::optional<std::shared_ptr<ImageTarget>>{});
}
_INLINE_SPECIFIER_ bool ImageTarget::save(std::string arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_ImageTarget_save(cdata_.get(), std_string_to_easyar_String(arg0).get());
    return _return_value_;
}
_INLINE_SPECIFIER_ std::optional<std::shared_ptr<ImageTarget>> ImageTarget::createFromImageFile(std::string arg0, StorageType arg1, std::string arg2, std::string arg3, std::string arg4, float arg5)
{
    easyar_OptionalOfImageTarget _return_value_;
    easyar_ImageTarget_createFromImageFile(std_string_to_easyar_String(arg0).get(), static_cast<easyar_StorageType>(arg1), std_string_to_easyar_String(arg2).get(), std_string_to_easyar_String(arg3).get(), std_string_to_easyar_String(arg4).get(), arg5, &_return_value_);
    if (!(!_return_value_.has_value || (_return_value_.value != nullptr))) { throw std::runtime_error("InvalidReturnValue"); }
    return (_return_value_.has_value ? ImageTarget::from_cdata(std::shared_ptr<easyar_ImageTarget>(_return_value_.value, [](easyar_ImageTarget * ptr) { easyar_ImageTarget__dtor(ptr); })) : std::optional<std::shared_ptr<ImageTarget>>{});
}
_INLINE_SPECIFIER_ std::vector<std::shared_ptr<ImageTarget>> ImageTarget::setupAll(std::string arg0, StorageType arg1)
{
    easyar_ListOfImageTarget * _return_value_;
    easyar_ImageTarget_setupAll(std_string_to_easyar_String(arg0).get(), static_cast<easyar_StorageType>(arg1), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return std_vector_from_easyar_ListOfImageTarget(std::shared_ptr<easyar_ListOfImageTarget>(_return_value_, [](easyar_ListOfImageTarget * ptr) { easyar_ListOfImageTarget__dtor(ptr); }));
}
_INLINE_SPECIFIER_ float ImageTarget::scale()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_ImageTarget_scale(cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ float ImageTarget::aspectRatio()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_ImageTarget_aspectRatio(cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ bool ImageTarget::setScale(float arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_ImageTarget_setScale(cdata_.get(), arg0);
    return _return_value_;
}
_INLINE_SPECIFIER_ std::vector<std::shared_ptr<Image>> ImageTarget::images()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_ListOfImage * _return_value_;
    easyar_ImageTarget_images(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return std_vector_from_easyar_ListOfImage(std::shared_ptr<easyar_ListOfImage>(_return_value_, [](easyar_ListOfImage * ptr) { easyar_ListOfImage__dtor(ptr); }));
}
_INLINE_SPECIFIER_ int ImageTarget::runtimeID()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_ImageTarget_runtimeID(cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ std::string ImageTarget::uid()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_String * _return_value_;
    easyar_ImageTarget_uid(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return std_string_from_easyar_String(std::shared_ptr<easyar_String>(_return_value_, [](easyar_String * ptr) { easyar_String__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::string ImageTarget::name()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_String * _return_value_;
    easyar_ImageTarget_name(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return std_string_from_easyar_String(std::shared_ptr<easyar_String>(_return_value_, [](easyar_String * ptr) { easyar_String__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void ImageTarget::setName(std::string arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_ImageTarget_setName(cdata_.get(), std_string_to_easyar_String(arg0).get());
}
_INLINE_SPECIFIER_ std::string ImageTarget::meta()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_String * _return_value_;
    easyar_ImageTarget_meta(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return std_string_from_easyar_String(std::shared_ptr<easyar_String>(_return_value_, [](easyar_String * ptr) { easyar_String__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void ImageTarget::setMeta(std::string arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_ImageTarget_setMeta(cdata_.get(), std_string_to_easyar_String(arg0).get());
}

_INLINE_SPECIFIER_ ImageTrackerResult::ImageTrackerResult(std::shared_ptr<easyar_ImageTrackerResult> cdata)
    :
    TargetTrackerResult(std::shared_ptr<easyar_TargetTrackerResult>(nullptr)),
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ ImageTrackerResult::~ImageTrackerResult()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_ImageTrackerResult> ImageTrackerResult::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void ImageTrackerResult::init_cdata(std::shared_ptr<easyar_ImageTrackerResult> cdata)
{
    cdata_ = cdata;
    {
        easyar_TargetTrackerResult * ptr = nullptr;
        easyar_castImageTrackerResultToTargetTrackerResult(cdata_.get(), &ptr);
        TargetTrackerResult::init_cdata(std::shared_ptr<easyar_TargetTrackerResult>(ptr, [](easyar_TargetTrackerResult * ptr) { easyar_TargetTrackerResult__dtor(ptr); }));
    }
}
_INLINE_SPECIFIER_ std::shared_ptr<ImageTrackerResult> ImageTrackerResult::from_cdata(std::shared_ptr<easyar_ImageTrackerResult> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<ImageTrackerResult>(cdata);
}
_INLINE_SPECIFIER_ std::vector<std::shared_ptr<TargetInstance>> ImageTrackerResult::targetInstances()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_ListOfTargetInstance * _return_value_;
    easyar_ImageTrackerResult_targetInstances(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return std_vector_from_easyar_ListOfTargetInstance(std::shared_ptr<easyar_ListOfTargetInstance>(_return_value_, [](easyar_ListOfTargetInstance * ptr) { easyar_ListOfTargetInstance__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void ImageTrackerResult::setTargetInstances(std::vector<std::shared_ptr<TargetInstance>> arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    if (!easyar_ListOfTargetInstance_check_external_cpp(arg0)) { throw std::runtime_error("InvalidArgument: instances"); }
    easyar_ImageTrackerResult_setTargetInstances(cdata_.get(), std_vector_to_easyar_ListOfTargetInstance(arg0).get());
}

_INLINE_SPECIFIER_ ImageTracker::ImageTracker(std::shared_ptr<easyar_ImageTracker> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ ImageTracker::~ImageTracker()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_ImageTracker> ImageTracker::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void ImageTracker::init_cdata(std::shared_ptr<easyar_ImageTracker> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<ImageTracker> ImageTracker::from_cdata(std::shared_ptr<easyar_ImageTracker> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<ImageTracker>(cdata);
}
_INLINE_SPECIFIER_ bool ImageTracker::isAvailable()
{
    auto _return_value_ = easyar_ImageTracker_isAvailable();
    return _return_value_;
}
_INLINE_SPECIFIER_ std::shared_ptr<FeedbackFrameSink> ImageTracker::feedbackFrameSink()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_FeedbackFrameSink * _return_value_;
    easyar_ImageTracker_feedbackFrameSink(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return FeedbackFrameSink::from_cdata(std::shared_ptr<easyar_FeedbackFrameSink>(_return_value_, [](easyar_FeedbackFrameSink * ptr) { easyar_FeedbackFrameSink__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<OutputFrameSource> ImageTracker::outputFrameSource()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_OutputFrameSource * _return_value_;
    easyar_ImageTracker_outputFrameSource(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return OutputFrameSource::from_cdata(std::shared_ptr<easyar_OutputFrameSource>(_return_value_, [](easyar_OutputFrameSource * ptr) { easyar_OutputFrameSource__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<ImageTracker> ImageTracker::create()
{
    easyar_ImageTracker * _return_value_;
    easyar_ImageTracker_create(&_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return ImageTracker::from_cdata(std::shared_ptr<easyar_ImageTracker>(_return_value_, [](easyar_ImageTracker * ptr) { easyar_ImageTracker__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<ImageTracker> ImageTracker::createWithMode(ImageTrackerMode arg0)
{
    easyar_ImageTracker * _return_value_;
    easyar_ImageTracker_createWithMode(static_cast<easyar_ImageTrackerMode>(arg0), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return ImageTracker::from_cdata(std::shared_ptr<easyar_ImageTracker>(_return_value_, [](easyar_ImageTracker * ptr) { easyar_ImageTracker__dtor(ptr); }));
}
_INLINE_SPECIFIER_ bool ImageTracker::start()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_ImageTracker_start(cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ void ImageTracker::stop()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_ImageTracker_stop(cdata_.get());
}
_INLINE_SPECIFIER_ void ImageTracker::close()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_ImageTracker_close(cdata_.get());
}
_INLINE_SPECIFIER_ void ImageTracker::loadTarget(std::shared_ptr<Target> arg0, std::shared_ptr<CallbackScheduler> arg1, std::function<void(std::shared_ptr<Target>, bool)> arg2)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    if (!(arg0 != nullptr)) { throw std::runtime_error("InvalidArgument: target"); }
    if (!(arg1 != nullptr)) { throw std::runtime_error("InvalidArgument: callbackScheduler"); }
    if (!(arg2 != nullptr)) { throw std::runtime_error("InvalidArgument: callback"); }
    easyar_ImageTracker_loadTarget(cdata_.get(), arg0->get_cdata().get(), arg1->get_cdata().get(), FunctorOfVoidFromTargetAndBool_to_c(arg2));
}
_INLINE_SPECIFIER_ void ImageTracker::unloadTarget(std::shared_ptr<Target> arg0, std::shared_ptr<CallbackScheduler> arg1, std::function<void(std::shared_ptr<Target>, bool)> arg2)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    if (!(arg0 != nullptr)) { throw std::runtime_error("InvalidArgument: target"); }
    if (!(arg1 != nullptr)) { throw std::runtime_error("InvalidArgument: callbackScheduler"); }
    if (!(arg2 != nullptr)) { throw std::runtime_error("InvalidArgument: callback"); }
    easyar_ImageTracker_unloadTarget(cdata_.get(), arg0->get_cdata().get(), arg1->get_cdata().get(), FunctorOfVoidFromTargetAndBool_to_c(arg2));
}
_INLINE_SPECIFIER_ std::vector<std::shared_ptr<Target>> ImageTracker::targets()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_ListOfTarget * _return_value_;
    easyar_ImageTracker_targets(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return std_vector_from_easyar_ListOfTarget(std::shared_ptr<easyar_ListOfTarget>(_return_value_, [](easyar_ListOfTarget * ptr) { easyar_ListOfTarget__dtor(ptr); }));
}
_INLINE_SPECIFIER_ bool ImageTracker::setSimultaneousNum(int arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_ImageTracker_setSimultaneousNum(cdata_.get(), arg0);
    return _return_value_;
}
_INLINE_SPECIFIER_ int ImageTracker::simultaneousNum()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_ImageTracker_simultaneousNum(cdata_.get());
    return _return_value_;
}

_INLINE_SPECIFIER_ Recorder::Recorder(std::shared_ptr<easyar_Recorder> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ Recorder::~Recorder()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_Recorder> Recorder::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void Recorder::init_cdata(std::shared_ptr<easyar_Recorder> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<Recorder> Recorder::from_cdata(std::shared_ptr<easyar_Recorder> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<Recorder>(cdata);
}
_INLINE_SPECIFIER_ bool Recorder::isAvailable()
{
    auto _return_value_ = easyar_Recorder_isAvailable();
    return _return_value_;
}
_INLINE_SPECIFIER_ void Recorder::requestPermissions(std::shared_ptr<CallbackScheduler> arg0, std::optional<std::function<void(PermissionStatus, std::string)>> arg1)
{
    if (!(arg0 != nullptr)) { throw std::runtime_error("InvalidArgument: callbackScheduler"); }
    if (!(!arg1.has_value() || (arg1.value() != nullptr))) { throw std::runtime_error("InvalidArgument: permissionCallback"); }
    easyar_Recorder_requestPermissions(arg0->get_cdata().get(), (arg1.has_value() ? easyar_OptionalOfFunctorOfVoidFromPermissionStatusAndString{true, FunctorOfVoidFromPermissionStatusAndString_to_c(arg1.value())} : easyar_OptionalOfFunctorOfVoidFromPermissionStatusAndString{false, {}}));
}
_INLINE_SPECIFIER_ std::shared_ptr<Recorder> Recorder::create(std::shared_ptr<RecorderConfiguration> arg0, std::shared_ptr<CallbackScheduler> arg1, std::optional<std::function<void(RecordStatus, std::string)>> arg2)
{
    if (!(arg0 != nullptr)) { throw std::runtime_error("InvalidArgument: config"); }
    if (!(arg1 != nullptr)) { throw std::runtime_error("InvalidArgument: callbackScheduler"); }
    if (!(!arg2.has_value() || (arg2.value() != nullptr))) { throw std::runtime_error("InvalidArgument: statusCallback"); }
    easyar_Recorder * _return_value_;
    easyar_Recorder_create(arg0->get_cdata().get(), arg1->get_cdata().get(), (arg2.has_value() ? easyar_OptionalOfFunctorOfVoidFromRecordStatusAndString{true, FunctorOfVoidFromRecordStatusAndString_to_c(arg2.value())} : easyar_OptionalOfFunctorOfVoidFromRecordStatusAndString{false, {}}), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return Recorder::from_cdata(std::shared_ptr<easyar_Recorder>(_return_value_, [](easyar_Recorder * ptr) { easyar_Recorder__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void Recorder::start()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_Recorder_start(cdata_.get());
}
_INLINE_SPECIFIER_ void Recorder::updateFrame(std::shared_ptr<TextureId> arg0, int arg1, int arg2)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    if (!(arg0 != nullptr)) { throw std::runtime_error("InvalidArgument: texture"); }
    easyar_Recorder_updateFrame(cdata_.get(), arg0->get_cdata().get(), arg1, arg2);
}
_INLINE_SPECIFIER_ bool Recorder::stop()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_Recorder_stop(cdata_.get());
    return _return_value_;
}

_INLINE_SPECIFIER_ RecorderConfiguration::RecorderConfiguration(std::shared_ptr<easyar_RecorderConfiguration> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ RecorderConfiguration::~RecorderConfiguration()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_RecorderConfiguration> RecorderConfiguration::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void RecorderConfiguration::init_cdata(std::shared_ptr<easyar_RecorderConfiguration> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<RecorderConfiguration> RecorderConfiguration::from_cdata(std::shared_ptr<easyar_RecorderConfiguration> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<RecorderConfiguration>(cdata);
}
_INLINE_SPECIFIER_ RecorderConfiguration::RecorderConfiguration()
    :
    cdata_(nullptr)
{
    easyar_RecorderConfiguration * _return_value_;
    easyar_RecorderConfiguration__ctor(&_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); };
    init_cdata(std::shared_ptr<easyar_RecorderConfiguration>(_return_value_, [](easyar_RecorderConfiguration * ptr) { easyar_RecorderConfiguration__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void RecorderConfiguration::setOutputFile(std::string arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_RecorderConfiguration_setOutputFile(cdata_.get(), std_string_to_easyar_String(arg0).get());
}
_INLINE_SPECIFIER_ bool RecorderConfiguration::setProfile(RecordProfile arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_RecorderConfiguration_setProfile(cdata_.get(), static_cast<easyar_RecordProfile>(arg0));
    return _return_value_;
}
_INLINE_SPECIFIER_ void RecorderConfiguration::setVideoSize(RecordVideoSize arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_RecorderConfiguration_setVideoSize(cdata_.get(), static_cast<easyar_RecordVideoSize>(arg0));
}
_INLINE_SPECIFIER_ void RecorderConfiguration::setVideoBitrate(int arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_RecorderConfiguration_setVideoBitrate(cdata_.get(), arg0);
}
_INLINE_SPECIFIER_ void RecorderConfiguration::setChannelCount(int arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_RecorderConfiguration_setChannelCount(cdata_.get(), arg0);
}
_INLINE_SPECIFIER_ void RecorderConfiguration::setAudioSampleRate(int arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_RecorderConfiguration_setAudioSampleRate(cdata_.get(), arg0);
}
_INLINE_SPECIFIER_ void RecorderConfiguration::setAudioBitrate(int arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_RecorderConfiguration_setAudioBitrate(cdata_.get(), arg0);
}
_INLINE_SPECIFIER_ void RecorderConfiguration::setVideoOrientation(RecordVideoOrientation arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_RecorderConfiguration_setVideoOrientation(cdata_.get(), static_cast<easyar_RecordVideoOrientation>(arg0));
}
_INLINE_SPECIFIER_ void RecorderConfiguration::setZoomMode(RecordZoomMode arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_RecorderConfiguration_setZoomMode(cdata_.get(), static_cast<easyar_RecordZoomMode>(arg0));
}

_INLINE_SPECIFIER_ SparseSpatialMapResult::SparseSpatialMapResult(std::shared_ptr<easyar_SparseSpatialMapResult> cdata)
    :
    FrameFilterResult(std::shared_ptr<easyar_FrameFilterResult>(nullptr)),
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ SparseSpatialMapResult::~SparseSpatialMapResult()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_SparseSpatialMapResult> SparseSpatialMapResult::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void SparseSpatialMapResult::init_cdata(std::shared_ptr<easyar_SparseSpatialMapResult> cdata)
{
    cdata_ = cdata;
    {
        easyar_FrameFilterResult * ptr = nullptr;
        easyar_castSparseSpatialMapResultToFrameFilterResult(cdata_.get(), &ptr);
        FrameFilterResult::init_cdata(std::shared_ptr<easyar_FrameFilterResult>(ptr, [](easyar_FrameFilterResult * ptr) { easyar_FrameFilterResult__dtor(ptr); }));
    }
}
_INLINE_SPECIFIER_ std::shared_ptr<SparseSpatialMapResult> SparseSpatialMapResult::from_cdata(std::shared_ptr<easyar_SparseSpatialMapResult> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<SparseSpatialMapResult>(cdata);
}
_INLINE_SPECIFIER_ MapTrackingStatus SparseSpatialMapResult::getMapTrackingStatus()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_SparseSpatialMapResult_getMapTrackingStatus(cdata_.get());
    return static_cast<MapTrackingStatus>(_return_value_);
}
_INLINE_SPECIFIER_ Matrix44F SparseSpatialMapResult::getVioPose()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_SparseSpatialMapResult_getVioPose(cdata_.get());
    return Matrix44F{{{_return_value_.data[0], _return_value_.data[1], _return_value_.data[2], _return_value_.data[3], _return_value_.data[4], _return_value_.data[5], _return_value_.data[6], _return_value_.data[7], _return_value_.data[8], _return_value_.data[9], _return_value_.data[10], _return_value_.data[11], _return_value_.data[12], _return_value_.data[13], _return_value_.data[14], _return_value_.data[15]}}};
}
_INLINE_SPECIFIER_ Matrix44F SparseSpatialMapResult::getMapPose()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_SparseSpatialMapResult_getMapPose(cdata_.get());
    return Matrix44F{{{_return_value_.data[0], _return_value_.data[1], _return_value_.data[2], _return_value_.data[3], _return_value_.data[4], _return_value_.data[5], _return_value_.data[6], _return_value_.data[7], _return_value_.data[8], _return_value_.data[9], _return_value_.data[10], _return_value_.data[11], _return_value_.data[12], _return_value_.data[13], _return_value_.data[14], _return_value_.data[15]}}};
}
_INLINE_SPECIFIER_ bool SparseSpatialMapResult::getLocalizedStatus()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_SparseSpatialMapResult_getLocalizedStatus(cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ std::string SparseSpatialMapResult::getCurrentLocalizedMapID()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_String * _return_value_;
    easyar_SparseSpatialMapResult_getCurrentLocalizedMapID(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return std_string_from_easyar_String(std::shared_ptr<easyar_String>(_return_value_, [](easyar_String * ptr) { easyar_String__dtor(ptr); }));
}

_INLINE_SPECIFIER_ PlaneData::PlaneData(std::shared_ptr<easyar_PlaneData> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ PlaneData::~PlaneData()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_PlaneData> PlaneData::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void PlaneData::init_cdata(std::shared_ptr<easyar_PlaneData> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<PlaneData> PlaneData::from_cdata(std::shared_ptr<easyar_PlaneData> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<PlaneData>(cdata);
}
_INLINE_SPECIFIER_ PlaneData::PlaneData()
    :
    cdata_(nullptr)
{
    easyar_PlaneData * _return_value_;
    easyar_PlaneData__ctor(&_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); };
    init_cdata(std::shared_ptr<easyar_PlaneData>(_return_value_, [](easyar_PlaneData * ptr) { easyar_PlaneData__dtor(ptr); }));
}
_INLINE_SPECIFIER_ PlaneType PlaneData::getType()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_PlaneData_getType(cdata_.get());
    return static_cast<PlaneType>(_return_value_);
}
_INLINE_SPECIFIER_ Matrix44F PlaneData::getPose()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_PlaneData_getPose(cdata_.get());
    return Matrix44F{{{_return_value_.data[0], _return_value_.data[1], _return_value_.data[2], _return_value_.data[3], _return_value_.data[4], _return_value_.data[5], _return_value_.data[6], _return_value_.data[7], _return_value_.data[8], _return_value_.data[9], _return_value_.data[10], _return_value_.data[11], _return_value_.data[12], _return_value_.data[13], _return_value_.data[14], _return_value_.data[15]}}};
}
_INLINE_SPECIFIER_ float PlaneData::getExtentX()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_PlaneData_getExtentX(cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ float PlaneData::getExtentZ()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_PlaneData_getExtentZ(cdata_.get());
    return _return_value_;
}

_INLINE_SPECIFIER_ SparseSpatialMapConfig::SparseSpatialMapConfig(std::shared_ptr<easyar_SparseSpatialMapConfig> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ SparseSpatialMapConfig::~SparseSpatialMapConfig()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_SparseSpatialMapConfig> SparseSpatialMapConfig::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void SparseSpatialMapConfig::init_cdata(std::shared_ptr<easyar_SparseSpatialMapConfig> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<SparseSpatialMapConfig> SparseSpatialMapConfig::from_cdata(std::shared_ptr<easyar_SparseSpatialMapConfig> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<SparseSpatialMapConfig>(cdata);
}
_INLINE_SPECIFIER_ SparseSpatialMapConfig::SparseSpatialMapConfig()
    :
    cdata_(nullptr)
{
    easyar_SparseSpatialMapConfig * _return_value_;
    easyar_SparseSpatialMapConfig__ctor(&_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); };
    init_cdata(std::shared_ptr<easyar_SparseSpatialMapConfig>(_return_value_, [](easyar_SparseSpatialMapConfig * ptr) { easyar_SparseSpatialMapConfig__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void SparseSpatialMapConfig::setLocalizeConfig(LocalizeConfig arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_SparseSpatialMapConfig_setLocalizeConfig(cdata_.get(), static_cast<easyar_LocalizeConfig>(arg0));
}
_INLINE_SPECIFIER_ LocalizeConfig SparseSpatialMapConfig::getLocalizeConfig()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_SparseSpatialMapConfig_getLocalizeConfig(cdata_.get());
    return static_cast<LocalizeConfig>(_return_value_);
}
_INLINE_SPECIFIER_ void SparseSpatialMapConfig::setMapConfig(MapConfig arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_SparseSpatialMapConfig_setMapConfig(cdata_.get(), static_cast<easyar_MapConfig>(arg0));
}
_INLINE_SPECIFIER_ MapConfig SparseSpatialMapConfig::getMapConfig()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_SparseSpatialMapConfig_getMapConfig(cdata_.get());
    return static_cast<MapConfig>(_return_value_);
}

_INLINE_SPECIFIER_ SparseSpatialMap::SparseSpatialMap(std::shared_ptr<easyar_SparseSpatialMap> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ SparseSpatialMap::~SparseSpatialMap()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_SparseSpatialMap> SparseSpatialMap::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void SparseSpatialMap::init_cdata(std::shared_ptr<easyar_SparseSpatialMap> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<SparseSpatialMap> SparseSpatialMap::from_cdata(std::shared_ptr<easyar_SparseSpatialMap> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<SparseSpatialMap>(cdata);
}
_INLINE_SPECIFIER_ bool SparseSpatialMap::isAvailable()
{
    auto _return_value_ = easyar_SparseSpatialMap_isAvailable();
    return _return_value_;
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrameSink> SparseSpatialMap::inputFrameSink()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_InputFrameSink * _return_value_;
    easyar_SparseSpatialMap_inputFrameSink(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return InputFrameSink::from_cdata(std::shared_ptr<easyar_InputFrameSink>(_return_value_, [](easyar_InputFrameSink * ptr) { easyar_InputFrameSink__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<OutputFrameSource> SparseSpatialMap::outputFrameSource()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_OutputFrameSource * _return_value_;
    easyar_SparseSpatialMap_outputFrameSource(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return OutputFrameSource::from_cdata(std::shared_ptr<easyar_OutputFrameSource>(_return_value_, [](easyar_OutputFrameSource * ptr) { easyar_OutputFrameSource__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<SparseSpatialMap> SparseSpatialMap::create()
{
    easyar_SparseSpatialMap * _return_value_;
    easyar_SparseSpatialMap_create(&_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return SparseSpatialMap::from_cdata(std::shared_ptr<easyar_SparseSpatialMap>(_return_value_, [](easyar_SparseSpatialMap * ptr) { easyar_SparseSpatialMap__dtor(ptr); }));
}
_INLINE_SPECIFIER_ bool SparseSpatialMap::start()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_SparseSpatialMap_start(cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ void SparseSpatialMap::stop()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_SparseSpatialMap_stop(cdata_.get());
}
_INLINE_SPECIFIER_ void SparseSpatialMap::close()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_SparseSpatialMap_close(cdata_.get());
}
_INLINE_SPECIFIER_ std::shared_ptr<Buffer> SparseSpatialMap::getPointCloudBuffer()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_Buffer * _return_value_;
    easyar_SparseSpatialMap_getPointCloudBuffer(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return Buffer::from_cdata(std::shared_ptr<easyar_Buffer>(_return_value_, [](easyar_Buffer * ptr) { easyar_Buffer__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::vector<std::shared_ptr<PlaneData>> SparseSpatialMap::getMapPlanes()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_ListOfPlaneData * _return_value_;
    easyar_SparseSpatialMap_getMapPlanes(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return std_vector_from_easyar_ListOfPlaneData(std::shared_ptr<easyar_ListOfPlaneData>(_return_value_, [](easyar_ListOfPlaneData * ptr) { easyar_ListOfPlaneData__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::vector<Vec3F> SparseSpatialMap::hitTestAgainstPointCloud(Vec2F arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_ListOfVec3F * _return_value_;
    easyar_SparseSpatialMap_hitTestAgainstPointCloud(cdata_.get(), easyar_Vec2F{{arg0.data[0], arg0.data[1]}}, &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return std_vector_from_easyar_ListOfVec3F(std::shared_ptr<easyar_ListOfVec3F>(_return_value_, [](easyar_ListOfVec3F * ptr) { easyar_ListOfVec3F__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::vector<Vec3F> SparseSpatialMap::hitTestAgainstPlanes(Vec2F arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_ListOfVec3F * _return_value_;
    easyar_SparseSpatialMap_hitTestAgainstPlanes(cdata_.get(), easyar_Vec2F{{arg0.data[0], arg0.data[1]}}, &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return std_vector_from_easyar_ListOfVec3F(std::shared_ptr<easyar_ListOfVec3F>(_return_value_, [](easyar_ListOfVec3F * ptr) { easyar_ListOfVec3F__dtor(ptr); }));
}
_INLINE_SPECIFIER_ bool SparseSpatialMap::saveMap(std::shared_ptr<CallbackScheduler> arg0, std::function<void(std::optional<std::shared_ptr<Buffer>>)> arg1)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    if (!(arg0 != nullptr)) { throw std::runtime_error("InvalidArgument: callbackScheduler"); }
    if (!(arg1 != nullptr)) { throw std::runtime_error("InvalidArgument: resultCallBack"); }
    auto _return_value_ = easyar_SparseSpatialMap_saveMap(cdata_.get(), arg0->get_cdata().get(), FunctorOfVoidFromOptionalOfBuffer_to_c(arg1));
    return _return_value_;
}
_INLINE_SPECIFIER_ bool SparseSpatialMap::loadMap(std::shared_ptr<Buffer> arg0, std::string arg1, std::shared_ptr<CallbackScheduler> arg2, std::optional<std::function<void(bool)>> arg3)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    if (!(arg0 != nullptr)) { throw std::runtime_error("InvalidArgument: pMapData"); }
    if (!(arg2 != nullptr)) { throw std::runtime_error("InvalidArgument: callbackScheduler"); }
    if (!(!arg3.has_value() || (arg3.value() != nullptr))) { throw std::runtime_error("InvalidArgument: resultCallBack"); }
    auto _return_value_ = easyar_SparseSpatialMap_loadMap(cdata_.get(), arg0->get_cdata().get(), std_string_to_easyar_String(arg1).get(), arg2->get_cdata().get(), (arg3.has_value() ? easyar_OptionalOfFunctorOfVoidFromBool{true, FunctorOfVoidFromBool_to_c(arg3.value())} : easyar_OptionalOfFunctorOfVoidFromBool{false, {}}));
    return _return_value_;
}
_INLINE_SPECIFIER_ bool SparseSpatialMap::unloadMap(std::string arg0, std::shared_ptr<CallbackScheduler> arg1, std::optional<std::function<void(bool)>> arg2)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    if (!(arg1 != nullptr)) { throw std::runtime_error("InvalidArgument: callbackScheduler"); }
    if (!(!arg2.has_value() || (arg2.value() != nullptr))) { throw std::runtime_error("InvalidArgument: resultCallBack"); }
    auto _return_value_ = easyar_SparseSpatialMap_unloadMap(cdata_.get(), std_string_to_easyar_String(arg0).get(), arg1->get_cdata().get(), (arg2.has_value() ? easyar_OptionalOfFunctorOfVoidFromBool{true, FunctorOfVoidFromBool_to_c(arg2.value())} : easyar_OptionalOfFunctorOfVoidFromBool{false, {}}));
    return _return_value_;
}
_INLINE_SPECIFIER_ void SparseSpatialMap::setConfig(std::shared_ptr<SparseSpatialMapConfig> arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    if (!(arg0 != nullptr)) { throw std::runtime_error("InvalidArgument: config"); }
    easyar_SparseSpatialMap_setConfig(cdata_.get(), arg0->get_cdata().get());
}
_INLINE_SPECIFIER_ std::shared_ptr<SparseSpatialMapConfig> SparseSpatialMap::getConfig()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_SparseSpatialMapConfig * _return_value_;
    easyar_SparseSpatialMap_getConfig(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return SparseSpatialMapConfig::from_cdata(std::shared_ptr<easyar_SparseSpatialMapConfig>(_return_value_, [](easyar_SparseSpatialMapConfig * ptr) { easyar_SparseSpatialMapConfig__dtor(ptr); }));
}
_INLINE_SPECIFIER_ bool SparseSpatialMap::startLocalize()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_SparseSpatialMap_startLocalize(cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ bool SparseSpatialMap::stopLocalize()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_SparseSpatialMap_stopLocalize(cdata_.get());
    return _return_value_;
}

_INLINE_SPECIFIER_ std::optional<std::shared_ptr<Image>> ImageHelper::decode(std::shared_ptr<Buffer> arg0)
{
    if (!(arg0 != nullptr)) { throw std::runtime_error("InvalidArgument: buffer"); }
    easyar_OptionalOfImage _return_value_;
    easyar_ImageHelper_decode(arg0->get_cdata().get(), &_return_value_);
    if (!(!_return_value_.has_value || (_return_value_.value != nullptr))) { throw std::runtime_error("InvalidReturnValue"); }
    return (_return_value_.has_value ? Image::from_cdata(std::shared_ptr<easyar_Image>(_return_value_.value, [](easyar_Image * ptr) { easyar_Image__dtor(ptr); })) : std::optional<std::shared_ptr<Image>>{});
}

_INLINE_SPECIFIER_ CallbackScheduler::CallbackScheduler(std::shared_ptr<easyar_CallbackScheduler> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ CallbackScheduler::~CallbackScheduler()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_CallbackScheduler> CallbackScheduler::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void CallbackScheduler::init_cdata(std::shared_ptr<easyar_CallbackScheduler> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<CallbackScheduler> CallbackScheduler::from_cdata(std::shared_ptr<easyar_CallbackScheduler> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    std::string typeName = easyar_CallbackScheduler__typeName(cdata.get());
    if (typeName == "DelayedCallbackScheduler") {
        easyar_DelayedCallbackScheduler * st_cdata;
        easyar_tryCastCallbackSchedulerToDelayedCallbackScheduler(cdata.get(), &st_cdata);
        return std::static_pointer_cast<CallbackScheduler>(std::make_shared<DelayedCallbackScheduler>(std::shared_ptr<easyar_DelayedCallbackScheduler>(st_cdata, [](easyar_DelayedCallbackScheduler * ptr) { easyar_DelayedCallbackScheduler__dtor(ptr); })));
    }
    if (typeName == "ImmediateCallbackScheduler") {
        easyar_ImmediateCallbackScheduler * st_cdata;
        easyar_tryCastCallbackSchedulerToImmediateCallbackScheduler(cdata.get(), &st_cdata);
        return std::static_pointer_cast<CallbackScheduler>(std::make_shared<ImmediateCallbackScheduler>(std::shared_ptr<easyar_ImmediateCallbackScheduler>(st_cdata, [](easyar_ImmediateCallbackScheduler * ptr) { easyar_ImmediateCallbackScheduler__dtor(ptr); })));
    }
    return std::make_shared<CallbackScheduler>(cdata);
}

_INLINE_SPECIFIER_ DelayedCallbackScheduler::DelayedCallbackScheduler(std::shared_ptr<easyar_DelayedCallbackScheduler> cdata)
    :
    CallbackScheduler(std::shared_ptr<easyar_CallbackScheduler>(nullptr)),
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ DelayedCallbackScheduler::~DelayedCallbackScheduler()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_DelayedCallbackScheduler> DelayedCallbackScheduler::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void DelayedCallbackScheduler::init_cdata(std::shared_ptr<easyar_DelayedCallbackScheduler> cdata)
{
    cdata_ = cdata;
    {
        easyar_CallbackScheduler * ptr = nullptr;
        easyar_castDelayedCallbackSchedulerToCallbackScheduler(cdata_.get(), &ptr);
        CallbackScheduler::init_cdata(std::shared_ptr<easyar_CallbackScheduler>(ptr, [](easyar_CallbackScheduler * ptr) { easyar_CallbackScheduler__dtor(ptr); }));
    }
}
_INLINE_SPECIFIER_ std::shared_ptr<DelayedCallbackScheduler> DelayedCallbackScheduler::from_cdata(std::shared_ptr<easyar_DelayedCallbackScheduler> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<DelayedCallbackScheduler>(cdata);
}
_INLINE_SPECIFIER_ DelayedCallbackScheduler::DelayedCallbackScheduler()
    :
    CallbackScheduler(std::shared_ptr<easyar_CallbackScheduler>(nullptr)),
    cdata_(nullptr)
{
    easyar_DelayedCallbackScheduler * _return_value_;
    easyar_DelayedCallbackScheduler__ctor(&_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); };
    init_cdata(std::shared_ptr<easyar_DelayedCallbackScheduler>(_return_value_, [](easyar_DelayedCallbackScheduler * ptr) { easyar_DelayedCallbackScheduler__dtor(ptr); }));
}
_INLINE_SPECIFIER_ bool DelayedCallbackScheduler::runOne()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_DelayedCallbackScheduler_runOne(cdata_.get());
    return _return_value_;
}

_INLINE_SPECIFIER_ ImmediateCallbackScheduler::ImmediateCallbackScheduler(std::shared_ptr<easyar_ImmediateCallbackScheduler> cdata)
    :
    CallbackScheduler(std::shared_ptr<easyar_CallbackScheduler>(nullptr)),
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ ImmediateCallbackScheduler::~ImmediateCallbackScheduler()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_ImmediateCallbackScheduler> ImmediateCallbackScheduler::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void ImmediateCallbackScheduler::init_cdata(std::shared_ptr<easyar_ImmediateCallbackScheduler> cdata)
{
    cdata_ = cdata;
    {
        easyar_CallbackScheduler * ptr = nullptr;
        easyar_castImmediateCallbackSchedulerToCallbackScheduler(cdata_.get(), &ptr);
        CallbackScheduler::init_cdata(std::shared_ptr<easyar_CallbackScheduler>(ptr, [](easyar_CallbackScheduler * ptr) { easyar_CallbackScheduler__dtor(ptr); }));
    }
}
_INLINE_SPECIFIER_ std::shared_ptr<ImmediateCallbackScheduler> ImmediateCallbackScheduler::from_cdata(std::shared_ptr<easyar_ImmediateCallbackScheduler> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<ImmediateCallbackScheduler>(cdata);
}
_INLINE_SPECIFIER_ std::shared_ptr<ImmediateCallbackScheduler> ImmediateCallbackScheduler::getDefault()
{
    easyar_ImmediateCallbackScheduler * _return_value_;
    easyar_ImmediateCallbackScheduler_getDefault(&_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return ImmediateCallbackScheduler::from_cdata(std::shared_ptr<easyar_ImmediateCallbackScheduler>(_return_value_, [](easyar_ImmediateCallbackScheduler * ptr) { easyar_ImmediateCallbackScheduler__dtor(ptr); }));
}

_INLINE_SPECIFIER_ CameraDevice::CameraDevice(std::shared_ptr<easyar_CameraDevice> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ CameraDevice::~CameraDevice()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_CameraDevice> CameraDevice::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void CameraDevice::init_cdata(std::shared_ptr<easyar_CameraDevice> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<CameraDevice> CameraDevice::from_cdata(std::shared_ptr<easyar_CameraDevice> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<CameraDevice>(cdata);
}
_INLINE_SPECIFIER_ CameraDevice::CameraDevice()
    :
    cdata_(nullptr)
{
    easyar_CameraDevice * _return_value_;
    easyar_CameraDevice__ctor(&_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); };
    init_cdata(std::shared_ptr<easyar_CameraDevice>(_return_value_, [](easyar_CameraDevice * ptr) { easyar_CameraDevice__dtor(ptr); }));
}
_INLINE_SPECIFIER_ bool CameraDevice::isAvailable()
{
    auto _return_value_ = easyar_CameraDevice_isAvailable();
    return _return_value_;
}
_INLINE_SPECIFIER_ AndroidCameraApiType CameraDevice::androidCameraApiType()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_CameraDevice_androidCameraApiType(cdata_.get());
    return static_cast<AndroidCameraApiType>(_return_value_);
}
_INLINE_SPECIFIER_ void CameraDevice::setAndroidCameraApiType(AndroidCameraApiType arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_CameraDevice_setAndroidCameraApiType(cdata_.get(), static_cast<easyar_AndroidCameraApiType>(arg0));
}
_INLINE_SPECIFIER_ int CameraDevice::bufferCapacity()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_CameraDevice_bufferCapacity(cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ void CameraDevice::setBufferCapacity(int arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_CameraDevice_setBufferCapacity(cdata_.get(), arg0);
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrameSource> CameraDevice::inputFrameSource()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_InputFrameSource * _return_value_;
    easyar_CameraDevice_inputFrameSource(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return InputFrameSource::from_cdata(std::shared_ptr<easyar_InputFrameSource>(_return_value_, [](easyar_InputFrameSource * ptr) { easyar_InputFrameSource__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void CameraDevice::setStateChangedCallback(std::shared_ptr<CallbackScheduler> arg0, std::optional<std::function<void(CameraState)>> arg1)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    if (!(arg0 != nullptr)) { throw std::runtime_error("InvalidArgument: callbackScheduler"); }
    if (!(!arg1.has_value() || (arg1.value() != nullptr))) { throw std::runtime_error("InvalidArgument: stateChangedCallback"); }
    easyar_CameraDevice_setStateChangedCallback(cdata_.get(), arg0->get_cdata().get(), (arg1.has_value() ? easyar_OptionalOfFunctorOfVoidFromCameraState{true, FunctorOfVoidFromCameraState_to_c(arg1.value())} : easyar_OptionalOfFunctorOfVoidFromCameraState{false, {}}));
}
_INLINE_SPECIFIER_ void CameraDevice::requestPermissions(std::shared_ptr<CallbackScheduler> arg0, std::optional<std::function<void(PermissionStatus, std::string)>> arg1)
{
    if (!(arg0 != nullptr)) { throw std::runtime_error("InvalidArgument: callbackScheduler"); }
    if (!(!arg1.has_value() || (arg1.value() != nullptr))) { throw std::runtime_error("InvalidArgument: permissionCallback"); }
    easyar_CameraDevice_requestPermissions(arg0->get_cdata().get(), (arg1.has_value() ? easyar_OptionalOfFunctorOfVoidFromPermissionStatusAndString{true, FunctorOfVoidFromPermissionStatusAndString_to_c(arg1.value())} : easyar_OptionalOfFunctorOfVoidFromPermissionStatusAndString{false, {}}));
}
_INLINE_SPECIFIER_ bool CameraDevice::openWithIndex(int arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_CameraDevice_openWithIndex(cdata_.get(), arg0);
    return _return_value_;
}
_INLINE_SPECIFIER_ bool CameraDevice::openWithType(CameraDeviceType arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_CameraDevice_openWithType(cdata_.get(), static_cast<easyar_CameraDeviceType>(arg0));
    return _return_value_;
}
_INLINE_SPECIFIER_ bool CameraDevice::start()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_CameraDevice_start(cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ void CameraDevice::stop()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_CameraDevice_stop(cdata_.get());
}
_INLINE_SPECIFIER_ void CameraDevice::close()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_CameraDevice_close(cdata_.get());
}
_INLINE_SPECIFIER_ CameraDeviceType CameraDevice::type()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_CameraDevice_type(cdata_.get());
    return static_cast<CameraDeviceType>(_return_value_);
}
_INLINE_SPECIFIER_ std::shared_ptr<CameraParameters> CameraDevice::cameraParameters()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_CameraParameters * _return_value_;
    easyar_CameraDevice_cameraParameters(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return CameraParameters::from_cdata(std::shared_ptr<easyar_CameraParameters>(_return_value_, [](easyar_CameraParameters * ptr) { easyar_CameraParameters__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void CameraDevice::setCameraParameters(std::shared_ptr<CameraParameters> arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    if (!(arg0 != nullptr)) { throw std::runtime_error("InvalidArgument: cameraParameters"); }
    easyar_CameraDevice_setCameraParameters(cdata_.get(), arg0->get_cdata().get());
}
_INLINE_SPECIFIER_ Vec2I CameraDevice::size()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_CameraDevice_size(cdata_.get());
    return Vec2I{{{_return_value_.data[0], _return_value_.data[1]}}};
}
_INLINE_SPECIFIER_ int CameraDevice::supportedSizeCount()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_CameraDevice_supportedSizeCount(cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ Vec2I CameraDevice::supportedSize(int arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_CameraDevice_supportedSize(cdata_.get(), arg0);
    return Vec2I{{{_return_value_.data[0], _return_value_.data[1]}}};
}
_INLINE_SPECIFIER_ bool CameraDevice::setSize(Vec2I arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_CameraDevice_setSize(cdata_.get(), easyar_Vec2I{{arg0.data[0], arg0.data[1]}});
    return _return_value_;
}
_INLINE_SPECIFIER_ int CameraDevice::supportedFrameRateRangeCount()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_CameraDevice_supportedFrameRateRangeCount(cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ float CameraDevice::supportedFrameRateRangeLower(int arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_CameraDevice_supportedFrameRateRangeLower(cdata_.get(), arg0);
    return _return_value_;
}
_INLINE_SPECIFIER_ float CameraDevice::supportedFrameRateRangeUpper(int arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_CameraDevice_supportedFrameRateRangeUpper(cdata_.get(), arg0);
    return _return_value_;
}
_INLINE_SPECIFIER_ int CameraDevice::frameRateRange()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_CameraDevice_frameRateRange(cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ bool CameraDevice::setFrameRateRange(int arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_CameraDevice_setFrameRateRange(cdata_.get(), arg0);
    return _return_value_;
}
_INLINE_SPECIFIER_ bool CameraDevice::setFlashTorchMode(bool arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_CameraDevice_setFlashTorchMode(cdata_.get(), arg0);
    return _return_value_;
}
_INLINE_SPECIFIER_ bool CameraDevice::setFocusMode(CameraDeviceFocusMode arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_CameraDevice_setFocusMode(cdata_.get(), static_cast<easyar_CameraDeviceFocusMode>(arg0));
    return _return_value_;
}
_INLINE_SPECIFIER_ bool CameraDevice::autoFocus()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_CameraDevice_autoFocus(cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ bool CameraDevice::setPresentProfile(CameraDevicePresetProfile arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_CameraDevice_setPresentProfile(cdata_.get(), static_cast<easyar_CameraDevicePresetProfile>(arg0));
    return _return_value_;
}

_INLINE_SPECIFIER_ std::shared_ptr<CameraDevice> CameraDeviceSelector::createCameraDevice(CameraDevicePreference arg0)
{
    easyar_CameraDevice * _return_value_;
    easyar_CameraDeviceSelector_createCameraDevice(static_cast<easyar_CameraDevicePreference>(arg0), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return CameraDevice::from_cdata(std::shared_ptr<easyar_CameraDevice>(_return_value_, [](easyar_CameraDevice * ptr) { easyar_CameraDevice__dtor(ptr); }));
}

_INLINE_SPECIFIER_ SignalSink::SignalSink(std::shared_ptr<easyar_SignalSink> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ SignalSink::~SignalSink()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_SignalSink> SignalSink::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void SignalSink::init_cdata(std::shared_ptr<easyar_SignalSink> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<SignalSink> SignalSink::from_cdata(std::shared_ptr<easyar_SignalSink> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<SignalSink>(cdata);
}
_INLINE_SPECIFIER_ void SignalSink::handle()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_SignalSink_handle(cdata_.get());
}

_INLINE_SPECIFIER_ SignalSource::SignalSource(std::shared_ptr<easyar_SignalSource> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ SignalSource::~SignalSource()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_SignalSource> SignalSource::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void SignalSource::init_cdata(std::shared_ptr<easyar_SignalSource> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<SignalSource> SignalSource::from_cdata(std::shared_ptr<easyar_SignalSource> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<SignalSource>(cdata);
}
_INLINE_SPECIFIER_ void SignalSource::setHandler(std::optional<std::function<void()>> arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    if (!(!arg0.has_value() || (arg0.value() != nullptr))) { throw std::runtime_error("InvalidArgument: handler"); }
    easyar_SignalSource_setHandler(cdata_.get(), (arg0.has_value() ? easyar_OptionalOfFunctorOfVoid{true, FunctorOfVoid_to_c(arg0.value())} : easyar_OptionalOfFunctorOfVoid{false, {}}));
}
_INLINE_SPECIFIER_ void SignalSource::connect(std::shared_ptr<SignalSink> arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    if (!(arg0 != nullptr)) { throw std::runtime_error("InvalidArgument: sink"); }
    easyar_SignalSource_connect(cdata_.get(), arg0->get_cdata().get());
}
_INLINE_SPECIFIER_ void SignalSource::disconnect()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_SignalSource_disconnect(cdata_.get());
}

_INLINE_SPECIFIER_ InputFrameSink::InputFrameSink(std::shared_ptr<easyar_InputFrameSink> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ InputFrameSink::~InputFrameSink()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_InputFrameSink> InputFrameSink::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void InputFrameSink::init_cdata(std::shared_ptr<easyar_InputFrameSink> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrameSink> InputFrameSink::from_cdata(std::shared_ptr<easyar_InputFrameSink> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<InputFrameSink>(cdata);
}
_INLINE_SPECIFIER_ void InputFrameSink::handle(std::shared_ptr<InputFrame> arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    if (!(arg0 != nullptr)) { throw std::runtime_error("InvalidArgument: inputData"); }
    easyar_InputFrameSink_handle(cdata_.get(), arg0->get_cdata().get());
}

_INLINE_SPECIFIER_ InputFrameSource::InputFrameSource(std::shared_ptr<easyar_InputFrameSource> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ InputFrameSource::~InputFrameSource()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_InputFrameSource> InputFrameSource::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void InputFrameSource::init_cdata(std::shared_ptr<easyar_InputFrameSource> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrameSource> InputFrameSource::from_cdata(std::shared_ptr<easyar_InputFrameSource> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<InputFrameSource>(cdata);
}
_INLINE_SPECIFIER_ void InputFrameSource::setHandler(std::optional<std::function<void(std::shared_ptr<InputFrame>)>> arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    if (!(!arg0.has_value() || (arg0.value() != nullptr))) { throw std::runtime_error("InvalidArgument: handler"); }
    easyar_InputFrameSource_setHandler(cdata_.get(), (arg0.has_value() ? easyar_OptionalOfFunctorOfVoidFromInputFrame{true, FunctorOfVoidFromInputFrame_to_c(arg0.value())} : easyar_OptionalOfFunctorOfVoidFromInputFrame{false, {}}));
}
_INLINE_SPECIFIER_ void InputFrameSource::connect(std::shared_ptr<InputFrameSink> arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    if (!(arg0 != nullptr)) { throw std::runtime_error("InvalidArgument: sink"); }
    easyar_InputFrameSource_connect(cdata_.get(), arg0->get_cdata().get());
}
_INLINE_SPECIFIER_ void InputFrameSource::disconnect()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_InputFrameSource_disconnect(cdata_.get());
}

_INLINE_SPECIFIER_ OutputFrameSink::OutputFrameSink(std::shared_ptr<easyar_OutputFrameSink> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ OutputFrameSink::~OutputFrameSink()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_OutputFrameSink> OutputFrameSink::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void OutputFrameSink::init_cdata(std::shared_ptr<easyar_OutputFrameSink> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<OutputFrameSink> OutputFrameSink::from_cdata(std::shared_ptr<easyar_OutputFrameSink> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<OutputFrameSink>(cdata);
}
_INLINE_SPECIFIER_ void OutputFrameSink::handle(std::shared_ptr<OutputFrame> arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    if (!(arg0 != nullptr)) { throw std::runtime_error("InvalidArgument: inputData"); }
    easyar_OutputFrameSink_handle(cdata_.get(), arg0->get_cdata().get());
}

_INLINE_SPECIFIER_ OutputFrameSource::OutputFrameSource(std::shared_ptr<easyar_OutputFrameSource> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ OutputFrameSource::~OutputFrameSource()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_OutputFrameSource> OutputFrameSource::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void OutputFrameSource::init_cdata(std::shared_ptr<easyar_OutputFrameSource> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<OutputFrameSource> OutputFrameSource::from_cdata(std::shared_ptr<easyar_OutputFrameSource> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<OutputFrameSource>(cdata);
}
_INLINE_SPECIFIER_ void OutputFrameSource::setHandler(std::optional<std::function<void(std::shared_ptr<OutputFrame>)>> arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    if (!(!arg0.has_value() || (arg0.value() != nullptr))) { throw std::runtime_error("InvalidArgument: handler"); }
    easyar_OutputFrameSource_setHandler(cdata_.get(), (arg0.has_value() ? easyar_OptionalOfFunctorOfVoidFromOutputFrame{true, FunctorOfVoidFromOutputFrame_to_c(arg0.value())} : easyar_OptionalOfFunctorOfVoidFromOutputFrame{false, {}}));
}
_INLINE_SPECIFIER_ void OutputFrameSource::connect(std::shared_ptr<OutputFrameSink> arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    if (!(arg0 != nullptr)) { throw std::runtime_error("InvalidArgument: sink"); }
    easyar_OutputFrameSource_connect(cdata_.get(), arg0->get_cdata().get());
}
_INLINE_SPECIFIER_ void OutputFrameSource::disconnect()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_OutputFrameSource_disconnect(cdata_.get());
}

_INLINE_SPECIFIER_ FeedbackFrameSink::FeedbackFrameSink(std::shared_ptr<easyar_FeedbackFrameSink> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ FeedbackFrameSink::~FeedbackFrameSink()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_FeedbackFrameSink> FeedbackFrameSink::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void FeedbackFrameSink::init_cdata(std::shared_ptr<easyar_FeedbackFrameSink> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<FeedbackFrameSink> FeedbackFrameSink::from_cdata(std::shared_ptr<easyar_FeedbackFrameSink> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<FeedbackFrameSink>(cdata);
}
_INLINE_SPECIFIER_ void FeedbackFrameSink::handle(std::shared_ptr<FeedbackFrame> arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    if (!(arg0 != nullptr)) { throw std::runtime_error("InvalidArgument: inputData"); }
    easyar_FeedbackFrameSink_handle(cdata_.get(), arg0->get_cdata().get());
}

_INLINE_SPECIFIER_ FeedbackFrameSource::FeedbackFrameSource(std::shared_ptr<easyar_FeedbackFrameSource> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ FeedbackFrameSource::~FeedbackFrameSource()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_FeedbackFrameSource> FeedbackFrameSource::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void FeedbackFrameSource::init_cdata(std::shared_ptr<easyar_FeedbackFrameSource> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<FeedbackFrameSource> FeedbackFrameSource::from_cdata(std::shared_ptr<easyar_FeedbackFrameSource> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<FeedbackFrameSource>(cdata);
}
_INLINE_SPECIFIER_ void FeedbackFrameSource::setHandler(std::optional<std::function<void(std::shared_ptr<FeedbackFrame>)>> arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    if (!(!arg0.has_value() || (arg0.value() != nullptr))) { throw std::runtime_error("InvalidArgument: handler"); }
    easyar_FeedbackFrameSource_setHandler(cdata_.get(), (arg0.has_value() ? easyar_OptionalOfFunctorOfVoidFromFeedbackFrame{true, FunctorOfVoidFromFeedbackFrame_to_c(arg0.value())} : easyar_OptionalOfFunctorOfVoidFromFeedbackFrame{false, {}}));
}
_INLINE_SPECIFIER_ void FeedbackFrameSource::connect(std::shared_ptr<FeedbackFrameSink> arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    if (!(arg0 != nullptr)) { throw std::runtime_error("InvalidArgument: sink"); }
    easyar_FeedbackFrameSource_connect(cdata_.get(), arg0->get_cdata().get());
}
_INLINE_SPECIFIER_ void FeedbackFrameSource::disconnect()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_FeedbackFrameSource_disconnect(cdata_.get());
}

_INLINE_SPECIFIER_ InputFrameFork::InputFrameFork(std::shared_ptr<easyar_InputFrameFork> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ InputFrameFork::~InputFrameFork()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_InputFrameFork> InputFrameFork::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void InputFrameFork::init_cdata(std::shared_ptr<easyar_InputFrameFork> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrameFork> InputFrameFork::from_cdata(std::shared_ptr<easyar_InputFrameFork> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<InputFrameFork>(cdata);
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrameSink> InputFrameFork::input()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_InputFrameSink * _return_value_;
    easyar_InputFrameFork_input(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return InputFrameSink::from_cdata(std::shared_ptr<easyar_InputFrameSink>(_return_value_, [](easyar_InputFrameSink * ptr) { easyar_InputFrameSink__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrameSource> InputFrameFork::output(int arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_InputFrameSource * _return_value_;
    easyar_InputFrameFork_output(cdata_.get(), arg0, &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return InputFrameSource::from_cdata(std::shared_ptr<easyar_InputFrameSource>(_return_value_, [](easyar_InputFrameSource * ptr) { easyar_InputFrameSource__dtor(ptr); }));
}
_INLINE_SPECIFIER_ int InputFrameFork::outputCount()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_InputFrameFork_outputCount(cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrameFork> InputFrameFork::create(int arg0)
{
    easyar_InputFrameFork * _return_value_;
    easyar_InputFrameFork_create(arg0, &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return InputFrameFork::from_cdata(std::shared_ptr<easyar_InputFrameFork>(_return_value_, [](easyar_InputFrameFork * ptr) { easyar_InputFrameFork__dtor(ptr); }));
}

_INLINE_SPECIFIER_ OutputFrameFork::OutputFrameFork(std::shared_ptr<easyar_OutputFrameFork> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ OutputFrameFork::~OutputFrameFork()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_OutputFrameFork> OutputFrameFork::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void OutputFrameFork::init_cdata(std::shared_ptr<easyar_OutputFrameFork> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<OutputFrameFork> OutputFrameFork::from_cdata(std::shared_ptr<easyar_OutputFrameFork> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<OutputFrameFork>(cdata);
}
_INLINE_SPECIFIER_ std::shared_ptr<OutputFrameSink> OutputFrameFork::input()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_OutputFrameSink * _return_value_;
    easyar_OutputFrameFork_input(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return OutputFrameSink::from_cdata(std::shared_ptr<easyar_OutputFrameSink>(_return_value_, [](easyar_OutputFrameSink * ptr) { easyar_OutputFrameSink__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<OutputFrameSource> OutputFrameFork::output(int arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_OutputFrameSource * _return_value_;
    easyar_OutputFrameFork_output(cdata_.get(), arg0, &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return OutputFrameSource::from_cdata(std::shared_ptr<easyar_OutputFrameSource>(_return_value_, [](easyar_OutputFrameSource * ptr) { easyar_OutputFrameSource__dtor(ptr); }));
}
_INLINE_SPECIFIER_ int OutputFrameFork::outputCount()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_OutputFrameFork_outputCount(cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ std::shared_ptr<OutputFrameFork> OutputFrameFork::create(int arg0)
{
    easyar_OutputFrameFork * _return_value_;
    easyar_OutputFrameFork_create(arg0, &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return OutputFrameFork::from_cdata(std::shared_ptr<easyar_OutputFrameFork>(_return_value_, [](easyar_OutputFrameFork * ptr) { easyar_OutputFrameFork__dtor(ptr); }));
}

_INLINE_SPECIFIER_ OutputFrameJoin::OutputFrameJoin(std::shared_ptr<easyar_OutputFrameJoin> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ OutputFrameJoin::~OutputFrameJoin()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_OutputFrameJoin> OutputFrameJoin::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void OutputFrameJoin::init_cdata(std::shared_ptr<easyar_OutputFrameJoin> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<OutputFrameJoin> OutputFrameJoin::from_cdata(std::shared_ptr<easyar_OutputFrameJoin> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<OutputFrameJoin>(cdata);
}
_INLINE_SPECIFIER_ std::shared_ptr<OutputFrameSink> OutputFrameJoin::input(int arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_OutputFrameSink * _return_value_;
    easyar_OutputFrameJoin_input(cdata_.get(), arg0, &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return OutputFrameSink::from_cdata(std::shared_ptr<easyar_OutputFrameSink>(_return_value_, [](easyar_OutputFrameSink * ptr) { easyar_OutputFrameSink__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<OutputFrameSource> OutputFrameJoin::output()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_OutputFrameSource * _return_value_;
    easyar_OutputFrameJoin_output(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return OutputFrameSource::from_cdata(std::shared_ptr<easyar_OutputFrameSource>(_return_value_, [](easyar_OutputFrameSource * ptr) { easyar_OutputFrameSource__dtor(ptr); }));
}
_INLINE_SPECIFIER_ int OutputFrameJoin::inputCount()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_OutputFrameJoin_inputCount(cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ std::shared_ptr<OutputFrameJoin> OutputFrameJoin::create(int arg0)
{
    easyar_OutputFrameJoin * _return_value_;
    easyar_OutputFrameJoin_create(arg0, &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return OutputFrameJoin::from_cdata(std::shared_ptr<easyar_OutputFrameJoin>(_return_value_, [](easyar_OutputFrameJoin * ptr) { easyar_OutputFrameJoin__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<OutputFrameJoin> OutputFrameJoin::createWithJoiner(int arg0, std::function<std::shared_ptr<OutputFrame>(std::vector<std::shared_ptr<OutputFrame>>)> arg1)
{
    if (!(arg1 != nullptr)) { throw std::runtime_error("InvalidArgument: joiner"); }
    easyar_OutputFrameJoin * _return_value_;
    easyar_OutputFrameJoin_createWithJoiner(arg0, FunctorOfOutputFrameFromListOfOutputFrame_to_c(arg1), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return OutputFrameJoin::from_cdata(std::shared_ptr<easyar_OutputFrameJoin>(_return_value_, [](easyar_OutputFrameJoin * ptr) { easyar_OutputFrameJoin__dtor(ptr); }));
}

_INLINE_SPECIFIER_ FeedbackFrameFork::FeedbackFrameFork(std::shared_ptr<easyar_FeedbackFrameFork> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ FeedbackFrameFork::~FeedbackFrameFork()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_FeedbackFrameFork> FeedbackFrameFork::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void FeedbackFrameFork::init_cdata(std::shared_ptr<easyar_FeedbackFrameFork> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<FeedbackFrameFork> FeedbackFrameFork::from_cdata(std::shared_ptr<easyar_FeedbackFrameFork> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<FeedbackFrameFork>(cdata);
}
_INLINE_SPECIFIER_ std::shared_ptr<FeedbackFrameSink> FeedbackFrameFork::input()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_FeedbackFrameSink * _return_value_;
    easyar_FeedbackFrameFork_input(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return FeedbackFrameSink::from_cdata(std::shared_ptr<easyar_FeedbackFrameSink>(_return_value_, [](easyar_FeedbackFrameSink * ptr) { easyar_FeedbackFrameSink__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<FeedbackFrameSource> FeedbackFrameFork::output(int arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_FeedbackFrameSource * _return_value_;
    easyar_FeedbackFrameFork_output(cdata_.get(), arg0, &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return FeedbackFrameSource::from_cdata(std::shared_ptr<easyar_FeedbackFrameSource>(_return_value_, [](easyar_FeedbackFrameSource * ptr) { easyar_FeedbackFrameSource__dtor(ptr); }));
}
_INLINE_SPECIFIER_ int FeedbackFrameFork::outputCount()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_FeedbackFrameFork_outputCount(cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ std::shared_ptr<FeedbackFrameFork> FeedbackFrameFork::create(int arg0)
{
    easyar_FeedbackFrameFork * _return_value_;
    easyar_FeedbackFrameFork_create(arg0, &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return FeedbackFrameFork::from_cdata(std::shared_ptr<easyar_FeedbackFrameFork>(_return_value_, [](easyar_FeedbackFrameFork * ptr) { easyar_FeedbackFrameFork__dtor(ptr); }));
}

_INLINE_SPECIFIER_ InputFrameThrottler::InputFrameThrottler(std::shared_ptr<easyar_InputFrameThrottler> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ InputFrameThrottler::~InputFrameThrottler()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_InputFrameThrottler> InputFrameThrottler::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void InputFrameThrottler::init_cdata(std::shared_ptr<easyar_InputFrameThrottler> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrameThrottler> InputFrameThrottler::from_cdata(std::shared_ptr<easyar_InputFrameThrottler> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<InputFrameThrottler>(cdata);
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrameSink> InputFrameThrottler::input()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_InputFrameSink * _return_value_;
    easyar_InputFrameThrottler_input(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return InputFrameSink::from_cdata(std::shared_ptr<easyar_InputFrameSink>(_return_value_, [](easyar_InputFrameSink * ptr) { easyar_InputFrameSink__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrameSource> InputFrameThrottler::output()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_InputFrameSource * _return_value_;
    easyar_InputFrameThrottler_output(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return InputFrameSource::from_cdata(std::shared_ptr<easyar_InputFrameSource>(_return_value_, [](easyar_InputFrameSource * ptr) { easyar_InputFrameSource__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<SignalSink> InputFrameThrottler::signalInput()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_SignalSink * _return_value_;
    easyar_InputFrameThrottler_signalInput(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return SignalSink::from_cdata(std::shared_ptr<easyar_SignalSink>(_return_value_, [](easyar_SignalSink * ptr) { easyar_SignalSink__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrameThrottler> InputFrameThrottler::create()
{
    easyar_InputFrameThrottler * _return_value_;
    easyar_InputFrameThrottler_create(&_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return InputFrameThrottler::from_cdata(std::shared_ptr<easyar_InputFrameThrottler>(_return_value_, [](easyar_InputFrameThrottler * ptr) { easyar_InputFrameThrottler__dtor(ptr); }));
}

_INLINE_SPECIFIER_ OutputFrameBuffer::OutputFrameBuffer(std::shared_ptr<easyar_OutputFrameBuffer> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ OutputFrameBuffer::~OutputFrameBuffer()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_OutputFrameBuffer> OutputFrameBuffer::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void OutputFrameBuffer::init_cdata(std::shared_ptr<easyar_OutputFrameBuffer> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<OutputFrameBuffer> OutputFrameBuffer::from_cdata(std::shared_ptr<easyar_OutputFrameBuffer> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<OutputFrameBuffer>(cdata);
}
_INLINE_SPECIFIER_ std::shared_ptr<OutputFrameSink> OutputFrameBuffer::input()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_OutputFrameSink * _return_value_;
    easyar_OutputFrameBuffer_input(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return OutputFrameSink::from_cdata(std::shared_ptr<easyar_OutputFrameSink>(_return_value_, [](easyar_OutputFrameSink * ptr) { easyar_OutputFrameSink__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<SignalSource> OutputFrameBuffer::signalOutput()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_SignalSource * _return_value_;
    easyar_OutputFrameBuffer_signalOutput(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return SignalSource::from_cdata(std::shared_ptr<easyar_SignalSource>(_return_value_, [](easyar_SignalSource * ptr) { easyar_SignalSource__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::optional<std::shared_ptr<OutputFrame>> OutputFrameBuffer::peek()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_OptionalOfOutputFrame _return_value_;
    easyar_OutputFrameBuffer_peek(cdata_.get(), &_return_value_);
    if (!(!_return_value_.has_value || (_return_value_.value != nullptr))) { throw std::runtime_error("InvalidReturnValue"); }
    return (_return_value_.has_value ? OutputFrame::from_cdata(std::shared_ptr<easyar_OutputFrame>(_return_value_.value, [](easyar_OutputFrame * ptr) { easyar_OutputFrame__dtor(ptr); })) : std::optional<std::shared_ptr<OutputFrame>>{});
}
_INLINE_SPECIFIER_ std::shared_ptr<OutputFrameBuffer> OutputFrameBuffer::create()
{
    easyar_OutputFrameBuffer * _return_value_;
    easyar_OutputFrameBuffer_create(&_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return OutputFrameBuffer::from_cdata(std::shared_ptr<easyar_OutputFrameBuffer>(_return_value_, [](easyar_OutputFrameBuffer * ptr) { easyar_OutputFrameBuffer__dtor(ptr); }));
}

_INLINE_SPECIFIER_ InputFrameToOutputFrameAdapter::InputFrameToOutputFrameAdapter(std::shared_ptr<easyar_InputFrameToOutputFrameAdapter> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ InputFrameToOutputFrameAdapter::~InputFrameToOutputFrameAdapter()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_InputFrameToOutputFrameAdapter> InputFrameToOutputFrameAdapter::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void InputFrameToOutputFrameAdapter::init_cdata(std::shared_ptr<easyar_InputFrameToOutputFrameAdapter> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrameToOutputFrameAdapter> InputFrameToOutputFrameAdapter::from_cdata(std::shared_ptr<easyar_InputFrameToOutputFrameAdapter> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<InputFrameToOutputFrameAdapter>(cdata);
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrameSink> InputFrameToOutputFrameAdapter::input()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_InputFrameSink * _return_value_;
    easyar_InputFrameToOutputFrameAdapter_input(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return InputFrameSink::from_cdata(std::shared_ptr<easyar_InputFrameSink>(_return_value_, [](easyar_InputFrameSink * ptr) { easyar_InputFrameSink__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<OutputFrameSource> InputFrameToOutputFrameAdapter::output()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_OutputFrameSource * _return_value_;
    easyar_InputFrameToOutputFrameAdapter_output(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return OutputFrameSource::from_cdata(std::shared_ptr<easyar_OutputFrameSource>(_return_value_, [](easyar_OutputFrameSource * ptr) { easyar_OutputFrameSource__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrameToOutputFrameAdapter> InputFrameToOutputFrameAdapter::create()
{
    easyar_InputFrameToOutputFrameAdapter * _return_value_;
    easyar_InputFrameToOutputFrameAdapter_create(&_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return InputFrameToOutputFrameAdapter::from_cdata(std::shared_ptr<easyar_InputFrameToOutputFrameAdapter>(_return_value_, [](easyar_InputFrameToOutputFrameAdapter * ptr) { easyar_InputFrameToOutputFrameAdapter__dtor(ptr); }));
}

_INLINE_SPECIFIER_ InputFrameToFeedbackFrameAdapter::InputFrameToFeedbackFrameAdapter(std::shared_ptr<easyar_InputFrameToFeedbackFrameAdapter> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ InputFrameToFeedbackFrameAdapter::~InputFrameToFeedbackFrameAdapter()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_InputFrameToFeedbackFrameAdapter> InputFrameToFeedbackFrameAdapter::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void InputFrameToFeedbackFrameAdapter::init_cdata(std::shared_ptr<easyar_InputFrameToFeedbackFrameAdapter> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrameToFeedbackFrameAdapter> InputFrameToFeedbackFrameAdapter::from_cdata(std::shared_ptr<easyar_InputFrameToFeedbackFrameAdapter> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<InputFrameToFeedbackFrameAdapter>(cdata);
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrameSink> InputFrameToFeedbackFrameAdapter::input()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_InputFrameSink * _return_value_;
    easyar_InputFrameToFeedbackFrameAdapter_input(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return InputFrameSink::from_cdata(std::shared_ptr<easyar_InputFrameSink>(_return_value_, [](easyar_InputFrameSink * ptr) { easyar_InputFrameSink__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<OutputFrameSink> InputFrameToFeedbackFrameAdapter::sideInput()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_OutputFrameSink * _return_value_;
    easyar_InputFrameToFeedbackFrameAdapter_sideInput(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return OutputFrameSink::from_cdata(std::shared_ptr<easyar_OutputFrameSink>(_return_value_, [](easyar_OutputFrameSink * ptr) { easyar_OutputFrameSink__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<FeedbackFrameSource> InputFrameToFeedbackFrameAdapter::output()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_FeedbackFrameSource * _return_value_;
    easyar_InputFrameToFeedbackFrameAdapter_output(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return FeedbackFrameSource::from_cdata(std::shared_ptr<easyar_FeedbackFrameSource>(_return_value_, [](easyar_FeedbackFrameSource * ptr) { easyar_FeedbackFrameSource__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrameToFeedbackFrameAdapter> InputFrameToFeedbackFrameAdapter::create()
{
    easyar_InputFrameToFeedbackFrameAdapter * _return_value_;
    easyar_InputFrameToFeedbackFrameAdapter_create(&_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return InputFrameToFeedbackFrameAdapter::from_cdata(std::shared_ptr<easyar_InputFrameToFeedbackFrameAdapter>(_return_value_, [](easyar_InputFrameToFeedbackFrameAdapter * ptr) { easyar_InputFrameToFeedbackFrameAdapter__dtor(ptr); }));
}

_INLINE_SPECIFIER_ int Engine::schemaHash()
{
    auto _return_value_ = easyar_Engine_schemaHash();
    return _return_value_;
}
_INLINE_SPECIFIER_ bool Engine::initialize(std::string arg0)
{
    if (easyar_Engine_schemaHash() != -1339788856) {
        throw std::runtime_error("SchemaHashNotMatched");
    }
    auto _return_value_ = easyar_Engine_initialize(std_string_to_easyar_String(arg0).get());
    return _return_value_;
}
_INLINE_SPECIFIER_ void Engine::onPause()
{
    easyar_Engine_onPause();
}
_INLINE_SPECIFIER_ void Engine::onResume()
{
    easyar_Engine_onResume();
}
_INLINE_SPECIFIER_ std::string Engine::errorMessage()
{
    easyar_String * _return_value_;
    easyar_Engine_errorMessage(&_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return std_string_from_easyar_String(std::shared_ptr<easyar_String>(_return_value_, [](easyar_String * ptr) { easyar_String__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::string Engine::versionString()
{
    easyar_String * _return_value_;
    easyar_Engine_versionString(&_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return std_string_from_easyar_String(std::shared_ptr<easyar_String>(_return_value_, [](easyar_String * ptr) { easyar_String__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::string Engine::name()
{
    easyar_String * _return_value_;
    easyar_Engine_name(&_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return std_string_from_easyar_String(std::shared_ptr<easyar_String>(_return_value_, [](easyar_String * ptr) { easyar_String__dtor(ptr); }));
}

_INLINE_SPECIFIER_ InputFrame::InputFrame(std::shared_ptr<easyar_InputFrame> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ InputFrame::~InputFrame()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_InputFrame> InputFrame::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void InputFrame::init_cdata(std::shared_ptr<easyar_InputFrame> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrame> InputFrame::from_cdata(std::shared_ptr<easyar_InputFrame> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<InputFrame>(cdata);
}
_INLINE_SPECIFIER_ int InputFrame::index()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_InputFrame_index(cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ std::shared_ptr<Image> InputFrame::image()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_Image * _return_value_;
    easyar_InputFrame_image(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return Image::from_cdata(std::shared_ptr<easyar_Image>(_return_value_, [](easyar_Image * ptr) { easyar_Image__dtor(ptr); }));
}
_INLINE_SPECIFIER_ bool InputFrame::hasCameraParameters()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_InputFrame_hasCameraParameters(cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ std::shared_ptr<CameraParameters> InputFrame::cameraParameters()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_CameraParameters * _return_value_;
    easyar_InputFrame_cameraParameters(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return CameraParameters::from_cdata(std::shared_ptr<easyar_CameraParameters>(_return_value_, [](easyar_CameraParameters * ptr) { easyar_CameraParameters__dtor(ptr); }));
}
_INLINE_SPECIFIER_ bool InputFrame::hasTemporalInformation()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_InputFrame_hasTemporalInformation(cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ double InputFrame::timestamp()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_InputFrame_timestamp(cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ bool InputFrame::hasSpatialInformation()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_InputFrame_hasSpatialInformation(cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ Matrix44F InputFrame::cameraTransform()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_InputFrame_cameraTransform(cdata_.get());
    return Matrix44F{{{_return_value_.data[0], _return_value_.data[1], _return_value_.data[2], _return_value_.data[3], _return_value_.data[4], _return_value_.data[5], _return_value_.data[6], _return_value_.data[7], _return_value_.data[8], _return_value_.data[9], _return_value_.data[10], _return_value_.data[11], _return_value_.data[12], _return_value_.data[13], _return_value_.data[14], _return_value_.data[15]}}};
}
_INLINE_SPECIFIER_ InputFrameTrackingStatus InputFrame::trackingStatus()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_InputFrame_trackingStatus(cdata_.get());
    return static_cast<InputFrameTrackingStatus>(_return_value_);
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrame> InputFrame::create(std::shared_ptr<Image> arg0, std::shared_ptr<CameraParameters> arg1, double arg2, Matrix44F arg3, InputFrameTrackingStatus arg4)
{
    if (!(arg0 != nullptr)) { throw std::runtime_error("InvalidArgument: image"); }
    if (!(arg1 != nullptr)) { throw std::runtime_error("InvalidArgument: cameraParameters"); }
    easyar_InputFrame * _return_value_;
    easyar_InputFrame_create(arg0->get_cdata().get(), arg1->get_cdata().get(), arg2, easyar_Matrix44F{{arg3.data[0], arg3.data[1], arg3.data[2], arg3.data[3], arg3.data[4], arg3.data[5], arg3.data[6], arg3.data[7], arg3.data[8], arg3.data[9], arg3.data[10], arg3.data[11], arg3.data[12], arg3.data[13], arg3.data[14], arg3.data[15]}}, static_cast<easyar_InputFrameTrackingStatus>(arg4), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return InputFrame::from_cdata(std::shared_ptr<easyar_InputFrame>(_return_value_, [](easyar_InputFrame * ptr) { easyar_InputFrame__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrame> InputFrame::createWithImageAndCameraParametersAndTemporal(std::shared_ptr<Image> arg0, std::shared_ptr<CameraParameters> arg1, double arg2)
{
    if (!(arg0 != nullptr)) { throw std::runtime_error("InvalidArgument: image"); }
    if (!(arg1 != nullptr)) { throw std::runtime_error("InvalidArgument: cameraParameters"); }
    easyar_InputFrame * _return_value_;
    easyar_InputFrame_createWithImageAndCameraParametersAndTemporal(arg0->get_cdata().get(), arg1->get_cdata().get(), arg2, &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return InputFrame::from_cdata(std::shared_ptr<easyar_InputFrame>(_return_value_, [](easyar_InputFrame * ptr) { easyar_InputFrame__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrame> InputFrame::createWithImageAndCameraParameters(std::shared_ptr<Image> arg0, std::shared_ptr<CameraParameters> arg1)
{
    if (!(arg0 != nullptr)) { throw std::runtime_error("InvalidArgument: image"); }
    if (!(arg1 != nullptr)) { throw std::runtime_error("InvalidArgument: cameraParameters"); }
    easyar_InputFrame * _return_value_;
    easyar_InputFrame_createWithImageAndCameraParameters(arg0->get_cdata().get(), arg1->get_cdata().get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return InputFrame::from_cdata(std::shared_ptr<easyar_InputFrame>(_return_value_, [](easyar_InputFrame * ptr) { easyar_InputFrame__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrame> InputFrame::createWithImage(std::shared_ptr<Image> arg0)
{
    if (!(arg0 != nullptr)) { throw std::runtime_error("InvalidArgument: image"); }
    easyar_InputFrame * _return_value_;
    easyar_InputFrame_createWithImage(arg0->get_cdata().get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return InputFrame::from_cdata(std::shared_ptr<easyar_InputFrame>(_return_value_, [](easyar_InputFrame * ptr) { easyar_InputFrame__dtor(ptr); }));
}

_INLINE_SPECIFIER_ FrameFilterResult::FrameFilterResult(std::shared_ptr<easyar_FrameFilterResult> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ FrameFilterResult::~FrameFilterResult()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_FrameFilterResult> FrameFilterResult::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void FrameFilterResult::init_cdata(std::shared_ptr<easyar_FrameFilterResult> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<FrameFilterResult> FrameFilterResult::from_cdata(std::shared_ptr<easyar_FrameFilterResult> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    std::string typeName = easyar_FrameFilterResult__typeName(cdata.get());
    if (typeName == "ObjectTrackerResult") {
        easyar_ObjectTrackerResult * st_cdata;
        easyar_tryCastFrameFilterResultToObjectTrackerResult(cdata.get(), &st_cdata);
        return std::static_pointer_cast<FrameFilterResult>(std::make_shared<ObjectTrackerResult>(std::shared_ptr<easyar_ObjectTrackerResult>(st_cdata, [](easyar_ObjectTrackerResult * ptr) { easyar_ObjectTrackerResult__dtor(ptr); })));
    }
    if (typeName == "CADTrackerResult") {
        easyar_CADTrackerResult * st_cdata;
        easyar_tryCastFrameFilterResultToCADTrackerResult(cdata.get(), &st_cdata);
        return std::static_pointer_cast<FrameFilterResult>(std::make_shared<CADTrackerResult>(std::shared_ptr<easyar_CADTrackerResult>(st_cdata, [](easyar_CADTrackerResult * ptr) { easyar_CADTrackerResult__dtor(ptr); })));
    }
    if (typeName == "SurfaceTrackerResult") {
        easyar_SurfaceTrackerResult * st_cdata;
        easyar_tryCastFrameFilterResultToSurfaceTrackerResult(cdata.get(), &st_cdata);
        return std::static_pointer_cast<FrameFilterResult>(std::make_shared<SurfaceTrackerResult>(std::shared_ptr<easyar_SurfaceTrackerResult>(st_cdata, [](easyar_SurfaceTrackerResult * ptr) { easyar_SurfaceTrackerResult__dtor(ptr); })));
    }
    if (typeName == "MotionTrackerResult") {
        easyar_MotionTrackerResult * st_cdata;
        easyar_tryCastFrameFilterResultToMotionTrackerResult(cdata.get(), &st_cdata);
        return std::static_pointer_cast<FrameFilterResult>(std::make_shared<MotionTrackerResult>(std::shared_ptr<easyar_MotionTrackerResult>(st_cdata, [](easyar_MotionTrackerResult * ptr) { easyar_MotionTrackerResult__dtor(ptr); })));
    }
    if (typeName == "ImageTrackerResult") {
        easyar_ImageTrackerResult * st_cdata;
        easyar_tryCastFrameFilterResultToImageTrackerResult(cdata.get(), &st_cdata);
        return std::static_pointer_cast<FrameFilterResult>(std::make_shared<ImageTrackerResult>(std::shared_ptr<easyar_ImageTrackerResult>(st_cdata, [](easyar_ImageTrackerResult * ptr) { easyar_ImageTrackerResult__dtor(ptr); })));
    }
    if (typeName == "SparseSpatialMapResult") {
        easyar_SparseSpatialMapResult * st_cdata;
        easyar_tryCastFrameFilterResultToSparseSpatialMapResult(cdata.get(), &st_cdata);
        return std::static_pointer_cast<FrameFilterResult>(std::make_shared<SparseSpatialMapResult>(std::shared_ptr<easyar_SparseSpatialMapResult>(st_cdata, [](easyar_SparseSpatialMapResult * ptr) { easyar_SparseSpatialMapResult__dtor(ptr); })));
    }
    if (typeName == "TargetTrackerResult") {
        easyar_TargetTrackerResult * st_cdata;
        easyar_tryCastFrameFilterResultToTargetTrackerResult(cdata.get(), &st_cdata);
        return std::static_pointer_cast<FrameFilterResult>(std::make_shared<TargetTrackerResult>(std::shared_ptr<easyar_TargetTrackerResult>(st_cdata, [](easyar_TargetTrackerResult * ptr) { easyar_TargetTrackerResult__dtor(ptr); })));
    }
    return std::make_shared<FrameFilterResult>(cdata);
}

_INLINE_SPECIFIER_ OutputFrame::OutputFrame(std::shared_ptr<easyar_OutputFrame> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ OutputFrame::~OutputFrame()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_OutputFrame> OutputFrame::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void OutputFrame::init_cdata(std::shared_ptr<easyar_OutputFrame> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<OutputFrame> OutputFrame::from_cdata(std::shared_ptr<easyar_OutputFrame> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<OutputFrame>(cdata);
}
_INLINE_SPECIFIER_ OutputFrame::OutputFrame(std::shared_ptr<InputFrame> arg0, std::vector<std::optional<std::shared_ptr<FrameFilterResult>>> arg1)
    :
    cdata_(nullptr)
{
    if (!(arg0 != nullptr)) { throw std::runtime_error("InvalidArgument: inputFrame"); }
    if (!easyar_ListOfOptionalOfFrameFilterResult_check_external_cpp(arg1)) { throw std::runtime_error("InvalidArgument: results"); }
    easyar_OutputFrame * _return_value_;
    easyar_OutputFrame__ctor(arg0->get_cdata().get(), std_vector_to_easyar_ListOfOptionalOfFrameFilterResult(arg1).get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); };
    init_cdata(std::shared_ptr<easyar_OutputFrame>(_return_value_, [](easyar_OutputFrame * ptr) { easyar_OutputFrame__dtor(ptr); }));
}
_INLINE_SPECIFIER_ int OutputFrame::index()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_OutputFrame_index(cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrame> OutputFrame::inputFrame()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_InputFrame * _return_value_;
    easyar_OutputFrame_inputFrame(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return InputFrame::from_cdata(std::shared_ptr<easyar_InputFrame>(_return_value_, [](easyar_InputFrame * ptr) { easyar_InputFrame__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::vector<std::optional<std::shared_ptr<FrameFilterResult>>> OutputFrame::results()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_ListOfOptionalOfFrameFilterResult * _return_value_;
    easyar_OutputFrame_results(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return std_vector_from_easyar_ListOfOptionalOfFrameFilterResult(std::shared_ptr<easyar_ListOfOptionalOfFrameFilterResult>(_return_value_, [](easyar_ListOfOptionalOfFrameFilterResult * ptr) { easyar_ListOfOptionalOfFrameFilterResult__dtor(ptr); }));
}

_INLINE_SPECIFIER_ FeedbackFrame::FeedbackFrame(std::shared_ptr<easyar_FeedbackFrame> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ FeedbackFrame::~FeedbackFrame()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_FeedbackFrame> FeedbackFrame::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void FeedbackFrame::init_cdata(std::shared_ptr<easyar_FeedbackFrame> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<FeedbackFrame> FeedbackFrame::from_cdata(std::shared_ptr<easyar_FeedbackFrame> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<FeedbackFrame>(cdata);
}
_INLINE_SPECIFIER_ FeedbackFrame::FeedbackFrame(std::shared_ptr<InputFrame> arg0, std::optional<std::shared_ptr<OutputFrame>> arg1)
    :
    cdata_(nullptr)
{
    if (!(arg0 != nullptr)) { throw std::runtime_error("InvalidArgument: inputFrame"); }
    if (!(!arg1.has_value() || (arg1.value() != nullptr))) { throw std::runtime_error("InvalidArgument: previousOutputFrame"); }
    easyar_FeedbackFrame * _return_value_;
    easyar_FeedbackFrame__ctor(arg0->get_cdata().get(), (arg1.has_value() ? easyar_OptionalOfOutputFrame{true, arg1.value()->get_cdata().get()} : easyar_OptionalOfOutputFrame{false, {}}), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); };
    init_cdata(std::shared_ptr<easyar_FeedbackFrame>(_return_value_, [](easyar_FeedbackFrame * ptr) { easyar_FeedbackFrame__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrame> FeedbackFrame::inputFrame()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_InputFrame * _return_value_;
    easyar_FeedbackFrame_inputFrame(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return InputFrame::from_cdata(std::shared_ptr<easyar_InputFrame>(_return_value_, [](easyar_InputFrame * ptr) { easyar_InputFrame__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::optional<std::shared_ptr<OutputFrame>> FeedbackFrame::previousOutputFrame()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_OptionalOfOutputFrame _return_value_;
    easyar_FeedbackFrame_previousOutputFrame(cdata_.get(), &_return_value_);
    if (!(!_return_value_.has_value || (_return_value_.value != nullptr))) { throw std::runtime_error("InvalidReturnValue"); }
    return (_return_value_.has_value ? OutputFrame::from_cdata(std::shared_ptr<easyar_OutputFrame>(_return_value_.value, [](easyar_OutputFrame * ptr) { easyar_OutputFrame__dtor(ptr); })) : std::optional<std::shared_ptr<OutputFrame>>{});
}

_INLINE_SPECIFIER_ Target::Target(std::shared_ptr<easyar_Target> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ Target::~Target()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_Target> Target::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void Target::init_cdata(std::shared_ptr<easyar_Target> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<Target> Target::from_cdata(std::shared_ptr<easyar_Target> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    std::string typeName = easyar_Target__typeName(cdata.get());
    if (typeName == "ObjectTarget") {
        easyar_ObjectTarget * st_cdata;
        easyar_tryCastTargetToObjectTarget(cdata.get(), &st_cdata);
        return std::static_pointer_cast<Target>(std::make_shared<ObjectTarget>(std::shared_ptr<easyar_ObjectTarget>(st_cdata, [](easyar_ObjectTarget * ptr) { easyar_ObjectTarget__dtor(ptr); })));
    }
    if (typeName == "CADTarget") {
        easyar_CADTarget * st_cdata;
        easyar_tryCastTargetToCADTarget(cdata.get(), &st_cdata);
        return std::static_pointer_cast<Target>(std::make_shared<CADTarget>(std::shared_ptr<easyar_CADTarget>(st_cdata, [](easyar_CADTarget * ptr) { easyar_CADTarget__dtor(ptr); })));
    }
    if (typeName == "ImageTarget") {
        easyar_ImageTarget * st_cdata;
        easyar_tryCastTargetToImageTarget(cdata.get(), &st_cdata);
        return std::static_pointer_cast<Target>(std::make_shared<ImageTarget>(std::shared_ptr<easyar_ImageTarget>(st_cdata, [](easyar_ImageTarget * ptr) { easyar_ImageTarget__dtor(ptr); })));
    }
    return std::make_shared<Target>(cdata);
}
_INLINE_SPECIFIER_ int Target::runtimeID()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_Target_runtimeID(cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ std::string Target::uid()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_String * _return_value_;
    easyar_Target_uid(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return std_string_from_easyar_String(std::shared_ptr<easyar_String>(_return_value_, [](easyar_String * ptr) { easyar_String__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::string Target::name()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_String * _return_value_;
    easyar_Target_name(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return std_string_from_easyar_String(std::shared_ptr<easyar_String>(_return_value_, [](easyar_String * ptr) { easyar_String__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void Target::setName(std::string arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_Target_setName(cdata_.get(), std_string_to_easyar_String(arg0).get());
}
_INLINE_SPECIFIER_ std::string Target::meta()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_String * _return_value_;
    easyar_Target_meta(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return std_string_from_easyar_String(std::shared_ptr<easyar_String>(_return_value_, [](easyar_String * ptr) { easyar_String__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void Target::setMeta(std::string arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_Target_setMeta(cdata_.get(), std_string_to_easyar_String(arg0).get());
}

_INLINE_SPECIFIER_ TargetInstance::TargetInstance(std::shared_ptr<easyar_TargetInstance> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ TargetInstance::~TargetInstance()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_TargetInstance> TargetInstance::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void TargetInstance::init_cdata(std::shared_ptr<easyar_TargetInstance> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<TargetInstance> TargetInstance::from_cdata(std::shared_ptr<easyar_TargetInstance> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<TargetInstance>(cdata);
}
_INLINE_SPECIFIER_ TargetInstance::TargetInstance()
    :
    cdata_(nullptr)
{
    easyar_TargetInstance * _return_value_;
    easyar_TargetInstance__ctor(&_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); };
    init_cdata(std::shared_ptr<easyar_TargetInstance>(_return_value_, [](easyar_TargetInstance * ptr) { easyar_TargetInstance__dtor(ptr); }));
}
_INLINE_SPECIFIER_ TargetStatus TargetInstance::status()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_TargetInstance_status(cdata_.get());
    return static_cast<TargetStatus>(_return_value_);
}
_INLINE_SPECIFIER_ std::optional<std::shared_ptr<Target>> TargetInstance::target()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_OptionalOfTarget _return_value_;
    easyar_TargetInstance_target(cdata_.get(), &_return_value_);
    if (!(!_return_value_.has_value || (_return_value_.value != nullptr))) { throw std::runtime_error("InvalidReturnValue"); }
    return (_return_value_.has_value ? Target::from_cdata(std::shared_ptr<easyar_Target>(_return_value_.value, [](easyar_Target * ptr) { easyar_Target__dtor(ptr); })) : std::optional<std::shared_ptr<Target>>{});
}
_INLINE_SPECIFIER_ Matrix44F TargetInstance::pose()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_TargetInstance_pose(cdata_.get());
    return Matrix44F{{{_return_value_.data[0], _return_value_.data[1], _return_value_.data[2], _return_value_.data[3], _return_value_.data[4], _return_value_.data[5], _return_value_.data[6], _return_value_.data[7], _return_value_.data[8], _return_value_.data[9], _return_value_.data[10], _return_value_.data[11], _return_value_.data[12], _return_value_.data[13], _return_value_.data[14], _return_value_.data[15]}}};
}

_INLINE_SPECIFIER_ TargetTrackerResult::TargetTrackerResult(std::shared_ptr<easyar_TargetTrackerResult> cdata)
    :
    FrameFilterResult(std::shared_ptr<easyar_FrameFilterResult>(nullptr)),
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ TargetTrackerResult::~TargetTrackerResult()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_TargetTrackerResult> TargetTrackerResult::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void TargetTrackerResult::init_cdata(std::shared_ptr<easyar_TargetTrackerResult> cdata)
{
    cdata_ = cdata;
    {
        easyar_FrameFilterResult * ptr = nullptr;
        easyar_castTargetTrackerResultToFrameFilterResult(cdata_.get(), &ptr);
        FrameFilterResult::init_cdata(std::shared_ptr<easyar_FrameFilterResult>(ptr, [](easyar_FrameFilterResult * ptr) { easyar_FrameFilterResult__dtor(ptr); }));
    }
}
_INLINE_SPECIFIER_ std::shared_ptr<TargetTrackerResult> TargetTrackerResult::from_cdata(std::shared_ptr<easyar_TargetTrackerResult> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    std::string typeName = easyar_TargetTrackerResult__typeName(cdata.get());
    if (typeName == "ObjectTrackerResult") {
        easyar_ObjectTrackerResult * st_cdata;
        easyar_tryCastTargetTrackerResultToObjectTrackerResult(cdata.get(), &st_cdata);
        return std::static_pointer_cast<TargetTrackerResult>(std::make_shared<ObjectTrackerResult>(std::shared_ptr<easyar_ObjectTrackerResult>(st_cdata, [](easyar_ObjectTrackerResult * ptr) { easyar_ObjectTrackerResult__dtor(ptr); })));
    }
    if (typeName == "CADTrackerResult") {
        easyar_CADTrackerResult * st_cdata;
        easyar_tryCastTargetTrackerResultToCADTrackerResult(cdata.get(), &st_cdata);
        return std::static_pointer_cast<TargetTrackerResult>(std::make_shared<CADTrackerResult>(std::shared_ptr<easyar_CADTrackerResult>(st_cdata, [](easyar_CADTrackerResult * ptr) { easyar_CADTrackerResult__dtor(ptr); })));
    }
    if (typeName == "ImageTrackerResult") {
        easyar_ImageTrackerResult * st_cdata;
        easyar_tryCastTargetTrackerResultToImageTrackerResult(cdata.get(), &st_cdata);
        return std::static_pointer_cast<TargetTrackerResult>(std::make_shared<ImageTrackerResult>(std::shared_ptr<easyar_ImageTrackerResult>(st_cdata, [](easyar_ImageTrackerResult * ptr) { easyar_ImageTrackerResult__dtor(ptr); })));
    }
    return std::make_shared<TargetTrackerResult>(cdata);
}
_INLINE_SPECIFIER_ std::vector<std::shared_ptr<TargetInstance>> TargetTrackerResult::targetInstances()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_ListOfTargetInstance * _return_value_;
    easyar_TargetTrackerResult_targetInstances(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return std_vector_from_easyar_ListOfTargetInstance(std::shared_ptr<easyar_ListOfTargetInstance>(_return_value_, [](easyar_ListOfTargetInstance * ptr) { easyar_ListOfTargetInstance__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void TargetTrackerResult::setTargetInstances(std::vector<std::shared_ptr<TargetInstance>> arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    if (!easyar_ListOfTargetInstance_check_external_cpp(arg0)) { throw std::runtime_error("InvalidArgument: instances"); }
    easyar_TargetTrackerResult_setTargetInstances(cdata_.get(), std_vector_to_easyar_ListOfTargetInstance(arg0).get());
}

_INLINE_SPECIFIER_ TextureId::TextureId(std::shared_ptr<easyar_TextureId> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ TextureId::~TextureId()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_TextureId> TextureId::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void TextureId::init_cdata(std::shared_ptr<easyar_TextureId> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<TextureId> TextureId::from_cdata(std::shared_ptr<easyar_TextureId> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<TextureId>(cdata);
}
_INLINE_SPECIFIER_ int TextureId::getInt()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_TextureId_getInt(cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ void * TextureId::getPointer()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_TextureId_getPointer(cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ std::shared_ptr<TextureId> TextureId::fromInt(int arg0)
{
    easyar_TextureId * _return_value_;
    easyar_TextureId_fromInt(arg0, &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return TextureId::from_cdata(std::shared_ptr<easyar_TextureId>(_return_value_, [](easyar_TextureId * ptr) { easyar_TextureId__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<TextureId> TextureId::fromPointer(void * arg0)
{
    easyar_TextureId * _return_value_;
    easyar_TextureId_fromPointer(arg0, &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return TextureId::from_cdata(std::shared_ptr<easyar_TextureId>(_return_value_, [](easyar_TextureId * ptr) { easyar_TextureId__dtor(ptr); }));
}

_INLINE_SPECIFIER_ VideoPlayer::VideoPlayer(std::shared_ptr<easyar_VideoPlayer> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ VideoPlayer::~VideoPlayer()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_VideoPlayer> VideoPlayer::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void VideoPlayer::init_cdata(std::shared_ptr<easyar_VideoPlayer> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<VideoPlayer> VideoPlayer::from_cdata(std::shared_ptr<easyar_VideoPlayer> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<VideoPlayer>(cdata);
}
_INLINE_SPECIFIER_ VideoPlayer::VideoPlayer()
    :
    cdata_(nullptr)
{
    easyar_VideoPlayer * _return_value_;
    easyar_VideoPlayer__ctor(&_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); };
    init_cdata(std::shared_ptr<easyar_VideoPlayer>(_return_value_, [](easyar_VideoPlayer * ptr) { easyar_VideoPlayer__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void VideoPlayer::setVideoType(VideoType arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_VideoPlayer_setVideoType(cdata_.get(), static_cast<easyar_VideoType>(arg0));
}
_INLINE_SPECIFIER_ void VideoPlayer::setRenderTexture(std::shared_ptr<TextureId> arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    if (!(arg0 != nullptr)) { throw std::runtime_error("InvalidArgument: texture"); }
    easyar_VideoPlayer_setRenderTexture(cdata_.get(), arg0->get_cdata().get());
}
_INLINE_SPECIFIER_ void VideoPlayer::open(std::string arg0, StorageType arg1, std::shared_ptr<CallbackScheduler> arg2, std::optional<std::function<void(VideoStatus)>> arg3)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    if (!(arg2 != nullptr)) { throw std::runtime_error("InvalidArgument: callbackScheduler"); }
    if (!(!arg3.has_value() || (arg3.value() != nullptr))) { throw std::runtime_error("InvalidArgument: callback"); }
    easyar_VideoPlayer_open(cdata_.get(), std_string_to_easyar_String(arg0).get(), static_cast<easyar_StorageType>(arg1), arg2->get_cdata().get(), (arg3.has_value() ? easyar_OptionalOfFunctorOfVoidFromVideoStatus{true, FunctorOfVoidFromVideoStatus_to_c(arg3.value())} : easyar_OptionalOfFunctorOfVoidFromVideoStatus{false, {}}));
}
_INLINE_SPECIFIER_ void VideoPlayer::close()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_VideoPlayer_close(cdata_.get());
}
_INLINE_SPECIFIER_ bool VideoPlayer::play()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_VideoPlayer_play(cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ void VideoPlayer::stop()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_VideoPlayer_stop(cdata_.get());
}
_INLINE_SPECIFIER_ void VideoPlayer::pause()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_VideoPlayer_pause(cdata_.get());
}
_INLINE_SPECIFIER_ bool VideoPlayer::isRenderTextureAvailable()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_VideoPlayer_isRenderTextureAvailable(cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ void VideoPlayer::updateFrame()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_VideoPlayer_updateFrame(cdata_.get());
}
_INLINE_SPECIFIER_ int VideoPlayer::duration()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_VideoPlayer_duration(cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ int VideoPlayer::currentPosition()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_VideoPlayer_currentPosition(cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ bool VideoPlayer::seek(int arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_VideoPlayer_seek(cdata_.get(), arg0);
    return _return_value_;
}
_INLINE_SPECIFIER_ Vec2I VideoPlayer::size()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_VideoPlayer_size(cdata_.get());
    return Vec2I{{{_return_value_.data[0], _return_value_.data[1]}}};
}
_INLINE_SPECIFIER_ float VideoPlayer::volume()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_VideoPlayer_volume(cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ bool VideoPlayer::setVolume(float arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_VideoPlayer_setVolume(cdata_.get(), arg0);
    return _return_value_;
}

_INLINE_SPECIFIER_ Buffer::Buffer(std::shared_ptr<easyar_Buffer> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ Buffer::~Buffer()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_Buffer> Buffer::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void Buffer::init_cdata(std::shared_ptr<easyar_Buffer> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<Buffer> Buffer::from_cdata(std::shared_ptr<easyar_Buffer> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<Buffer>(cdata);
}
_INLINE_SPECIFIER_ std::shared_ptr<Buffer> Buffer::wrap(void * arg0, int arg1, std::function<void()> arg2)
{
    if (!(arg2 != nullptr)) { throw std::runtime_error("InvalidArgument: deleter"); }
    easyar_Buffer * _return_value_;
    easyar_Buffer_wrap(arg0, arg1, FunctorOfVoid_to_c(arg2), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return Buffer::from_cdata(std::shared_ptr<easyar_Buffer>(_return_value_, [](easyar_Buffer * ptr) { easyar_Buffer__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<Buffer> Buffer::create(int arg0)
{
    easyar_Buffer * _return_value_;
    easyar_Buffer_create(arg0, &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return Buffer::from_cdata(std::shared_ptr<easyar_Buffer>(_return_value_, [](easyar_Buffer * ptr) { easyar_Buffer__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void * Buffer::data()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_Buffer_data(cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ int Buffer::size()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_Buffer_size(cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ void Buffer::memoryCopy(void * arg0, void * arg1, int arg2)
{
    easyar_Buffer_memoryCopy(arg0, arg1, arg2);
}
_INLINE_SPECIFIER_ bool Buffer::tryCopyFrom(void * arg0, int arg1, int arg2, int arg3)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_Buffer_tryCopyFrom(cdata_.get(), arg0, arg1, arg2, arg3);
    return _return_value_;
}
_INLINE_SPECIFIER_ bool Buffer::tryCopyTo(int arg0, void * arg1, int arg2, int arg3)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_Buffer_tryCopyTo(cdata_.get(), arg0, arg1, arg2, arg3);
    return _return_value_;
}
_INLINE_SPECIFIER_ std::shared_ptr<Buffer> Buffer::partition(int arg0, int arg1)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_Buffer * _return_value_;
    easyar_Buffer_partition(cdata_.get(), arg0, arg1, &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return Buffer::from_cdata(std::shared_ptr<easyar_Buffer>(_return_value_, [](easyar_Buffer * ptr) { easyar_Buffer__dtor(ptr); }));
}

_INLINE_SPECIFIER_ BufferDictionary::BufferDictionary(std::shared_ptr<easyar_BufferDictionary> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ BufferDictionary::~BufferDictionary()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_BufferDictionary> BufferDictionary::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void BufferDictionary::init_cdata(std::shared_ptr<easyar_BufferDictionary> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<BufferDictionary> BufferDictionary::from_cdata(std::shared_ptr<easyar_BufferDictionary> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<BufferDictionary>(cdata);
}
_INLINE_SPECIFIER_ BufferDictionary::BufferDictionary()
    :
    cdata_(nullptr)
{
    easyar_BufferDictionary * _return_value_;
    easyar_BufferDictionary__ctor(&_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); };
    init_cdata(std::shared_ptr<easyar_BufferDictionary>(_return_value_, [](easyar_BufferDictionary * ptr) { easyar_BufferDictionary__dtor(ptr); }));
}
_INLINE_SPECIFIER_ int BufferDictionary::count()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_BufferDictionary_count(cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ bool BufferDictionary::contains(std::string arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_BufferDictionary_contains(cdata_.get(), std_string_to_easyar_String(arg0).get());
    return _return_value_;
}
_INLINE_SPECIFIER_ std::optional<std::shared_ptr<Buffer>> BufferDictionary::tryGet(std::string arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_OptionalOfBuffer _return_value_;
    easyar_BufferDictionary_tryGet(cdata_.get(), std_string_to_easyar_String(arg0).get(), &_return_value_);
    if (!(!_return_value_.has_value || (_return_value_.value != nullptr))) { throw std::runtime_error("InvalidReturnValue"); }
    return (_return_value_.has_value ? Buffer::from_cdata(std::shared_ptr<easyar_Buffer>(_return_value_.value, [](easyar_Buffer * ptr) { easyar_Buffer__dtor(ptr); })) : std::optional<std::shared_ptr<Buffer>>{});
}
_INLINE_SPECIFIER_ void BufferDictionary::set(std::string arg0, std::shared_ptr<Buffer> arg1)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    if (!(arg1 != nullptr)) { throw std::runtime_error("InvalidArgument: buffer"); }
    easyar_BufferDictionary_set(cdata_.get(), std_string_to_easyar_String(arg0).get(), arg1->get_cdata().get());
}
_INLINE_SPECIFIER_ bool BufferDictionary::remove(std::string arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_BufferDictionary_remove(cdata_.get(), std_string_to_easyar_String(arg0).get());
    return _return_value_;
}
_INLINE_SPECIFIER_ void BufferDictionary::clear()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_BufferDictionary_clear(cdata_.get());
}

_INLINE_SPECIFIER_ BufferPool::BufferPool(std::shared_ptr<easyar_BufferPool> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ BufferPool::~BufferPool()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_BufferPool> BufferPool::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void BufferPool::init_cdata(std::shared_ptr<easyar_BufferPool> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<BufferPool> BufferPool::from_cdata(std::shared_ptr<easyar_BufferPool> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<BufferPool>(cdata);
}
_INLINE_SPECIFIER_ BufferPool::BufferPool(int arg0, int arg1)
    :
    cdata_(nullptr)
{
    easyar_BufferPool * _return_value_;
    easyar_BufferPool__ctor(arg0, arg1, &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); };
    init_cdata(std::shared_ptr<easyar_BufferPool>(_return_value_, [](easyar_BufferPool * ptr) { easyar_BufferPool__dtor(ptr); }));
}
_INLINE_SPECIFIER_ int BufferPool::block_size()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_BufferPool_block_size(cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ int BufferPool::capacity()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_BufferPool_capacity(cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ int BufferPool::size()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_BufferPool_size(cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ std::optional<std::shared_ptr<Buffer>> BufferPool::tryAcquire()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_OptionalOfBuffer _return_value_;
    easyar_BufferPool_tryAcquire(cdata_.get(), &_return_value_);
    if (!(!_return_value_.has_value || (_return_value_.value != nullptr))) { throw std::runtime_error("InvalidReturnValue"); }
    return (_return_value_.has_value ? Buffer::from_cdata(std::shared_ptr<easyar_Buffer>(_return_value_.value, [](easyar_Buffer * ptr) { easyar_Buffer__dtor(ptr); })) : std::optional<std::shared_ptr<Buffer>>{});
}

_INLINE_SPECIFIER_ CameraParameters::CameraParameters(std::shared_ptr<easyar_CameraParameters> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ CameraParameters::~CameraParameters()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_CameraParameters> CameraParameters::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void CameraParameters::init_cdata(std::shared_ptr<easyar_CameraParameters> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<CameraParameters> CameraParameters::from_cdata(std::shared_ptr<easyar_CameraParameters> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<CameraParameters>(cdata);
}
_INLINE_SPECIFIER_ CameraParameters::CameraParameters(Vec2I arg0, Vec2F arg1, Vec2F arg2, CameraDeviceType arg3, int arg4)
    :
    cdata_(nullptr)
{
    easyar_CameraParameters * _return_value_;
    easyar_CameraParameters__ctor(easyar_Vec2I{{arg0.data[0], arg0.data[1]}}, easyar_Vec2F{{arg1.data[0], arg1.data[1]}}, easyar_Vec2F{{arg2.data[0], arg2.data[1]}}, static_cast<easyar_CameraDeviceType>(arg3), arg4, &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); };
    init_cdata(std::shared_ptr<easyar_CameraParameters>(_return_value_, [](easyar_CameraParameters * ptr) { easyar_CameraParameters__dtor(ptr); }));
}
_INLINE_SPECIFIER_ Vec2I CameraParameters::size()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_CameraParameters_size(cdata_.get());
    return Vec2I{{{_return_value_.data[0], _return_value_.data[1]}}};
}
_INLINE_SPECIFIER_ Vec2F CameraParameters::focalLength()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_CameraParameters_focalLength(cdata_.get());
    return Vec2F{{{_return_value_.data[0], _return_value_.data[1]}}};
}
_INLINE_SPECIFIER_ Vec2F CameraParameters::principalPoint()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_CameraParameters_principalPoint(cdata_.get());
    return Vec2F{{{_return_value_.data[0], _return_value_.data[1]}}};
}
_INLINE_SPECIFIER_ CameraDeviceType CameraParameters::cameraDeviceType()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_CameraParameters_cameraDeviceType(cdata_.get());
    return static_cast<CameraDeviceType>(_return_value_);
}
_INLINE_SPECIFIER_ int CameraParameters::cameraOrientation()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_CameraParameters_cameraOrientation(cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ std::shared_ptr<CameraParameters> CameraParameters::createWithDefaultIntrinsics(Vec2I arg0, CameraDeviceType arg1, int arg2)
{
    easyar_CameraParameters * _return_value_;
    easyar_CameraParameters_createWithDefaultIntrinsics(easyar_Vec2I{{arg0.data[0], arg0.data[1]}}, static_cast<easyar_CameraDeviceType>(arg1), arg2, &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return CameraParameters::from_cdata(std::shared_ptr<easyar_CameraParameters>(_return_value_, [](easyar_CameraParameters * ptr) { easyar_CameraParameters__dtor(ptr); }));
}
_INLINE_SPECIFIER_ int CameraParameters::imageOrientation(int arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_CameraParameters_imageOrientation(cdata_.get(), arg0);
    return _return_value_;
}
_INLINE_SPECIFIER_ bool CameraParameters::imageHorizontalFlip(bool arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_CameraParameters_imageHorizontalFlip(cdata_.get(), arg0);
    return _return_value_;
}
_INLINE_SPECIFIER_ Matrix44F CameraParameters::projection(float arg0, float arg1, float arg2, int arg3, bool arg4, bool arg5)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_CameraParameters_projection(cdata_.get(), arg0, arg1, arg2, arg3, arg4, arg5);
    return Matrix44F{{{_return_value_.data[0], _return_value_.data[1], _return_value_.data[2], _return_value_.data[3], _return_value_.data[4], _return_value_.data[5], _return_value_.data[6], _return_value_.data[7], _return_value_.data[8], _return_value_.data[9], _return_value_.data[10], _return_value_.data[11], _return_value_.data[12], _return_value_.data[13], _return_value_.data[14], _return_value_.data[15]}}};
}
_INLINE_SPECIFIER_ Matrix44F CameraParameters::imageProjection(float arg0, int arg1, bool arg2, bool arg3)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_CameraParameters_imageProjection(cdata_.get(), arg0, arg1, arg2, arg3);
    return Matrix44F{{{_return_value_.data[0], _return_value_.data[1], _return_value_.data[2], _return_value_.data[3], _return_value_.data[4], _return_value_.data[5], _return_value_.data[6], _return_value_.data[7], _return_value_.data[8], _return_value_.data[9], _return_value_.data[10], _return_value_.data[11], _return_value_.data[12], _return_value_.data[13], _return_value_.data[14], _return_value_.data[15]}}};
}
_INLINE_SPECIFIER_ Vec2F CameraParameters::screenCoordinatesFromImageCoordinates(float arg0, int arg1, bool arg2, bool arg3, Vec2F arg4)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_CameraParameters_screenCoordinatesFromImageCoordinates(cdata_.get(), arg0, arg1, arg2, arg3, easyar_Vec2F{{arg4.data[0], arg4.data[1]}});
    return Vec2F{{{_return_value_.data[0], _return_value_.data[1]}}};
}
_INLINE_SPECIFIER_ Vec2F CameraParameters::imageCoordinatesFromScreenCoordinates(float arg0, int arg1, bool arg2, bool arg3, Vec2F arg4)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_CameraParameters_imageCoordinatesFromScreenCoordinates(cdata_.get(), arg0, arg1, arg2, arg3, easyar_Vec2F{{arg4.data[0], arg4.data[1]}});
    return Vec2F{{{_return_value_.data[0], _return_value_.data[1]}}};
}
_INLINE_SPECIFIER_ bool CameraParameters::equalsTo(std::shared_ptr<CameraParameters> arg0)
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    if (!(arg0 != nullptr)) { throw std::runtime_error("InvalidArgument: other"); }
    auto _return_value_ = easyar_CameraParameters_equalsTo(cdata_.get(), arg0->get_cdata().get());
    return _return_value_;
}

_INLINE_SPECIFIER_ Image::Image(std::shared_ptr<easyar_Image> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ Image::~Image()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_Image> Image::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void Image::init_cdata(std::shared_ptr<easyar_Image> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<Image> Image::from_cdata(std::shared_ptr<easyar_Image> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<Image>(cdata);
}
_INLINE_SPECIFIER_ Image::Image(std::shared_ptr<Buffer> arg0, PixelFormat arg1, int arg2, int arg3)
    :
    cdata_(nullptr)
{
    if (!(arg0 != nullptr)) { throw std::runtime_error("InvalidArgument: buffer"); }
    easyar_Image * _return_value_;
    easyar_Image__ctor(arg0->get_cdata().get(), static_cast<easyar_PixelFormat>(arg1), arg2, arg3, &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); };
    init_cdata(std::shared_ptr<easyar_Image>(_return_value_, [](easyar_Image * ptr) { easyar_Image__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<Buffer> Image::buffer()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    easyar_Buffer * _return_value_;
    easyar_Image_buffer(cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return Buffer::from_cdata(std::shared_ptr<easyar_Buffer>(_return_value_, [](easyar_Buffer * ptr) { easyar_Buffer__dtor(ptr); }));
}
_INLINE_SPECIFIER_ PixelFormat Image::format()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_Image_format(cdata_.get());
    return static_cast<PixelFormat>(_return_value_);
}
_INLINE_SPECIFIER_ int Image::width()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_Image_width(cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ int Image::height()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_Image_height(cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ bool Image::empty()
{
    if (cdata_ == nullptr) { throw std::runtime_error("InvalidArgument: this"); }
    auto _return_value_ = easyar_Image_empty(cdata_.get());
    return _return_value_;
}

_INLINE_SPECIFIER_ std::shared_ptr<Buffer> JniUtility::wrapByteArray(void * arg0, bool arg1, std::function<void()> arg2)
{
    if (!(arg2 != nullptr)) { throw std::runtime_error("InvalidArgument: deleter"); }
    easyar_Buffer * _return_value_;
    easyar_JniUtility_wrapByteArray(arg0, arg1, FunctorOfVoid_to_c(arg2), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return Buffer::from_cdata(std::shared_ptr<easyar_Buffer>(_return_value_, [](easyar_Buffer * ptr) { easyar_Buffer__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<Buffer> JniUtility::wrapBuffer(void * arg0, std::function<void()> arg1)
{
    if (!(arg1 != nullptr)) { throw std::runtime_error("InvalidArgument: deleter"); }
    easyar_Buffer * _return_value_;
    easyar_JniUtility_wrapBuffer(arg0, FunctorOfVoid_to_c(arg1), &_return_value_);
    if (!(_return_value_ != nullptr)) { throw std::runtime_error("InvalidReturnValue"); }
    return Buffer::from_cdata(std::shared_ptr<easyar_Buffer>(_return_value_, [](easyar_Buffer * ptr) { easyar_Buffer__dtor(ptr); }));
}

_INLINE_SPECIFIER_ void Log::setLogFunc(std::function<void(LogLevel, std::string)> arg0)
{
    if (!(arg0 != nullptr)) { throw std::runtime_error("InvalidArgument: func"); }
    easyar_Log_setLogFunc(FunctorOfVoidFromLogLevelAndString_to_c(arg0));
}
_INLINE_SPECIFIER_ void Log::resetLogFunc()
{
    easyar_Log_resetLogFunc();
}

static void FunctorOfVoid_func(void * _state, /* OUT */ easyar_String * * _exception)
{
    *_exception = nullptr;
    try {
        auto f = reinterpret_cast<std::function<void()> *>(_state);
        (*f)();
    } catch (std::exception & ex) {
        auto message = std::string() + typeid(*(&ex)).name() + u8"\n" + ex.what();
        easyar_String_from_utf8_begin(message.c_str(), _exception);
    }
}
static void FunctorOfVoid_destroy(void * _state)
{
    auto f = reinterpret_cast<std::function<void()> *>(_state);
    delete f;
}
static inline easyar_FunctorOfVoid FunctorOfVoid_to_c(std::function<void()> f)
{
    return easyar_FunctorOfVoid{new std::function<void()>(f), FunctorOfVoid_func, FunctorOfVoid_destroy};
}

static inline std::shared_ptr<easyar_ListOfObjectTarget> std_vector_to_easyar_ListOfObjectTarget(std::vector<std::shared_ptr<ObjectTarget>> l)
{
    std::vector<easyar_ObjectTarget *> values;
    values.reserve(l.size());
    for (auto v : l) {
        auto cv = v->get_cdata().get();
        easyar_ObjectTarget__retain(cv, &cv);
        values.push_back(cv);
    }
    easyar_ListOfObjectTarget * ptr;
    easyar_ListOfObjectTarget__ctor(values.data(), values.data() + values.size(), &ptr);
    return std::shared_ptr<easyar_ListOfObjectTarget>(ptr, [](easyar_ListOfObjectTarget * ptr) { easyar_ListOfObjectTarget__dtor(ptr); });
}
static inline std::vector<std::shared_ptr<ObjectTarget>> std_vector_from_easyar_ListOfObjectTarget(std::shared_ptr<easyar_ListOfObjectTarget> pl)
{
    auto size = easyar_ListOfObjectTarget_size(pl.get());
    std::vector<std::shared_ptr<ObjectTarget>> values;
    values.reserve(size);
    for (int k = 0; k < size; k += 1) {
        auto v = easyar_ListOfObjectTarget_at(pl.get(), k);
        easyar_ObjectTarget__retain(v, &v);
        values.push_back(ObjectTarget::from_cdata(std::shared_ptr<easyar_ObjectTarget>(v, [](easyar_ObjectTarget * ptr) { easyar_ObjectTarget__dtor(ptr); })));
    }
    return values;
}
static inline bool easyar_ListOfObjectTarget_check_external_cpp(const std::vector<std::shared_ptr<ObjectTarget>> & l)
{
    for (auto e : l) {
        if (!(e != nullptr)) { return false; }
    }
    return true;
}

static inline std::shared_ptr<easyar_ListOfVec3F> std_vector_to_easyar_ListOfVec3F(std::vector<Vec3F> l)
{
    std::vector<easyar_Vec3F> values;
    values.reserve(l.size());
    for (auto v : l) {
        auto cv = easyar_Vec3F{{v.data[0], v.data[1], v.data[2]}};
        values.push_back(cv);
    }
    easyar_ListOfVec3F * ptr;
    easyar_ListOfVec3F__ctor(values.data(), values.data() + values.size(), &ptr);
    return std::shared_ptr<easyar_ListOfVec3F>(ptr, [](easyar_ListOfVec3F * ptr) { easyar_ListOfVec3F__dtor(ptr); });
}
static inline std::vector<Vec3F> std_vector_from_easyar_ListOfVec3F(std::shared_ptr<easyar_ListOfVec3F> pl)
{
    auto size = easyar_ListOfVec3F_size(pl.get());
    std::vector<Vec3F> values;
    values.reserve(size);
    for (int k = 0; k < size; k += 1) {
        auto v = easyar_ListOfVec3F_at(pl.get(), k);
        values.push_back(Vec3F{{{v.data[0], v.data[1], v.data[2]}}});
    }
    return values;
}
static inline bool easyar_ListOfVec3F_check_external_cpp(const std::vector<Vec3F> & l)
{
    return true;
}

static inline std::shared_ptr<easyar_ListOfTargetInstance> std_vector_to_easyar_ListOfTargetInstance(std::vector<std::shared_ptr<TargetInstance>> l)
{
    std::vector<easyar_TargetInstance *> values;
    values.reserve(l.size());
    for (auto v : l) {
        auto cv = v->get_cdata().get();
        easyar_TargetInstance__retain(cv, &cv);
        values.push_back(cv);
    }
    easyar_ListOfTargetInstance * ptr;
    easyar_ListOfTargetInstance__ctor(values.data(), values.data() + values.size(), &ptr);
    return std::shared_ptr<easyar_ListOfTargetInstance>(ptr, [](easyar_ListOfTargetInstance * ptr) { easyar_ListOfTargetInstance__dtor(ptr); });
}
static inline std::vector<std::shared_ptr<TargetInstance>> std_vector_from_easyar_ListOfTargetInstance(std::shared_ptr<easyar_ListOfTargetInstance> pl)
{
    auto size = easyar_ListOfTargetInstance_size(pl.get());
    std::vector<std::shared_ptr<TargetInstance>> values;
    values.reserve(size);
    for (int k = 0; k < size; k += 1) {
        auto v = easyar_ListOfTargetInstance_at(pl.get(), k);
        easyar_TargetInstance__retain(v, &v);
        values.push_back(TargetInstance::from_cdata(std::shared_ptr<easyar_TargetInstance>(v, [](easyar_TargetInstance * ptr) { easyar_TargetInstance__dtor(ptr); })));
    }
    return values;
}
static inline bool easyar_ListOfTargetInstance_check_external_cpp(const std::vector<std::shared_ptr<TargetInstance>> & l)
{
    for (auto e : l) {
        if (!(e != nullptr)) { return false; }
    }
    return true;
}

static inline std::shared_ptr<easyar_ListOfOptionalOfFrameFilterResult> std_vector_to_easyar_ListOfOptionalOfFrameFilterResult(std::vector<std::optional<std::shared_ptr<FrameFilterResult>>> l)
{
    std::vector<easyar_OptionalOfFrameFilterResult> values;
    values.reserve(l.size());
    for (auto v : l) {
        auto cv = (v.has_value() ? easyar_OptionalOfFrameFilterResult{true, v.value()->get_cdata().get()} : easyar_OptionalOfFrameFilterResult{false, {}});
        if (cv.has_value) { easyar_FrameFilterResult__retain(cv.value, &cv.value); }
        values.push_back(cv);
    }
    easyar_ListOfOptionalOfFrameFilterResult * ptr;
    easyar_ListOfOptionalOfFrameFilterResult__ctor(values.data(), values.data() + values.size(), &ptr);
    return std::shared_ptr<easyar_ListOfOptionalOfFrameFilterResult>(ptr, [](easyar_ListOfOptionalOfFrameFilterResult * ptr) { easyar_ListOfOptionalOfFrameFilterResult__dtor(ptr); });
}
static inline std::vector<std::optional<std::shared_ptr<FrameFilterResult>>> std_vector_from_easyar_ListOfOptionalOfFrameFilterResult(std::shared_ptr<easyar_ListOfOptionalOfFrameFilterResult> pl)
{
    auto size = easyar_ListOfOptionalOfFrameFilterResult_size(pl.get());
    std::vector<std::optional<std::shared_ptr<FrameFilterResult>>> values;
    values.reserve(size);
    for (int k = 0; k < size; k += 1) {
        auto v = easyar_ListOfOptionalOfFrameFilterResult_at(pl.get(), k);
        if (v.has_value) { easyar_FrameFilterResult__retain(v.value, &v.value); }
        values.push_back((v.has_value ? FrameFilterResult::from_cdata(std::shared_ptr<easyar_FrameFilterResult>(v.value, [](easyar_FrameFilterResult * ptr) { easyar_FrameFilterResult__dtor(ptr); })) : std::optional<std::shared_ptr<FrameFilterResult>>{}));
    }
    return values;
}
static inline bool easyar_ListOfOptionalOfFrameFilterResult_check_external_cpp(const std::vector<std::optional<std::shared_ptr<FrameFilterResult>>> & l)
{
    for (auto e : l) {
        if (!(!e.has_value() || (e.value() != nullptr))) { return false; }
    }
    return true;
}

static void FunctorOfVoidFromOutputFrame_func(void * _state, easyar_OutputFrame * arg0, /* OUT */ easyar_String * * _exception)
{
    *_exception = nullptr;
    try {
        easyar_OutputFrame__retain(arg0, &arg0);
        std::shared_ptr<OutputFrame> cpparg0 = OutputFrame::from_cdata(std::shared_ptr<easyar_OutputFrame>(arg0, [](easyar_OutputFrame * ptr) { easyar_OutputFrame__dtor(ptr); }));
        auto f = reinterpret_cast<std::function<void(std::shared_ptr<OutputFrame>)> *>(_state);
        (*f)(cpparg0);
    } catch (std::exception & ex) {
        auto message = std::string() + typeid(*(&ex)).name() + u8"\n" + ex.what();
        easyar_String_from_utf8_begin(message.c_str(), _exception);
    }
}
static void FunctorOfVoidFromOutputFrame_destroy(void * _state)
{
    auto f = reinterpret_cast<std::function<void(std::shared_ptr<OutputFrame>)> *>(_state);
    delete f;
}
static inline easyar_FunctorOfVoidFromOutputFrame FunctorOfVoidFromOutputFrame_to_c(std::function<void(std::shared_ptr<OutputFrame>)> f)
{
    return easyar_FunctorOfVoidFromOutputFrame{new std::function<void(std::shared_ptr<OutputFrame>)>(f), FunctorOfVoidFromOutputFrame_func, FunctorOfVoidFromOutputFrame_destroy};
}

static void FunctorOfVoidFromTargetAndBool_func(void * _state, easyar_Target * arg0, bool arg1, /* OUT */ easyar_String * * _exception)
{
    *_exception = nullptr;
    try {
        easyar_Target__retain(arg0, &arg0);
        std::shared_ptr<Target> cpparg0 = Target::from_cdata(std::shared_ptr<easyar_Target>(arg0, [](easyar_Target * ptr) { easyar_Target__dtor(ptr); }));
        bool cpparg1 = arg1;
        auto f = reinterpret_cast<std::function<void(std::shared_ptr<Target>, bool)> *>(_state);
        (*f)(cpparg0, cpparg1);
    } catch (std::exception & ex) {
        auto message = std::string() + typeid(*(&ex)).name() + u8"\n" + ex.what();
        easyar_String_from_utf8_begin(message.c_str(), _exception);
    }
}
static void FunctorOfVoidFromTargetAndBool_destroy(void * _state)
{
    auto f = reinterpret_cast<std::function<void(std::shared_ptr<Target>, bool)> *>(_state);
    delete f;
}
static inline easyar_FunctorOfVoidFromTargetAndBool FunctorOfVoidFromTargetAndBool_to_c(std::function<void(std::shared_ptr<Target>, bool)> f)
{
    return easyar_FunctorOfVoidFromTargetAndBool{new std::function<void(std::shared_ptr<Target>, bool)>(f), FunctorOfVoidFromTargetAndBool_func, FunctorOfVoidFromTargetAndBool_destroy};
}

static inline std::shared_ptr<easyar_ListOfTarget> std_vector_to_easyar_ListOfTarget(std::vector<std::shared_ptr<Target>> l)
{
    std::vector<easyar_Target *> values;
    values.reserve(l.size());
    for (auto v : l) {
        auto cv = v->get_cdata().get();
        easyar_Target__retain(cv, &cv);
        values.push_back(cv);
    }
    easyar_ListOfTarget * ptr;
    easyar_ListOfTarget__ctor(values.data(), values.data() + values.size(), &ptr);
    return std::shared_ptr<easyar_ListOfTarget>(ptr, [](easyar_ListOfTarget * ptr) { easyar_ListOfTarget__dtor(ptr); });
}
static inline std::vector<std::shared_ptr<Target>> std_vector_from_easyar_ListOfTarget(std::shared_ptr<easyar_ListOfTarget> pl)
{
    auto size = easyar_ListOfTarget_size(pl.get());
    std::vector<std::shared_ptr<Target>> values;
    values.reserve(size);
    for (int k = 0; k < size; k += 1) {
        auto v = easyar_ListOfTarget_at(pl.get(), k);
        easyar_Target__retain(v, &v);
        values.push_back(Target::from_cdata(std::shared_ptr<easyar_Target>(v, [](easyar_Target * ptr) { easyar_Target__dtor(ptr); })));
    }
    return values;
}
static inline bool easyar_ListOfTarget_check_external_cpp(const std::vector<std::shared_ptr<Target>> & l)
{
    for (auto e : l) {
        if (!(e != nullptr)) { return false; }
    }
    return true;
}

static inline std::shared_ptr<easyar_ListOfCADTarget> std_vector_to_easyar_ListOfCADTarget(std::vector<std::shared_ptr<CADTarget>> l)
{
    std::vector<easyar_CADTarget *> values;
    values.reserve(l.size());
    for (auto v : l) {
        auto cv = v->get_cdata().get();
        easyar_CADTarget__retain(cv, &cv);
        values.push_back(cv);
    }
    easyar_ListOfCADTarget * ptr;
    easyar_ListOfCADTarget__ctor(values.data(), values.data() + values.size(), &ptr);
    return std::shared_ptr<easyar_ListOfCADTarget>(ptr, [](easyar_ListOfCADTarget * ptr) { easyar_ListOfCADTarget__dtor(ptr); });
}
static inline std::vector<std::shared_ptr<CADTarget>> std_vector_from_easyar_ListOfCADTarget(std::shared_ptr<easyar_ListOfCADTarget> pl)
{
    auto size = easyar_ListOfCADTarget_size(pl.get());
    std::vector<std::shared_ptr<CADTarget>> values;
    values.reserve(size);
    for (int k = 0; k < size; k += 1) {
        auto v = easyar_ListOfCADTarget_at(pl.get(), k);
        easyar_CADTarget__retain(v, &v);
        values.push_back(CADTarget::from_cdata(std::shared_ptr<easyar_CADTarget>(v, [](easyar_CADTarget * ptr) { easyar_CADTarget__dtor(ptr); })));
    }
    return values;
}
static inline bool easyar_ListOfCADTarget_check_external_cpp(const std::vector<std::shared_ptr<CADTarget>> & l)
{
    for (auto e : l) {
        if (!(e != nullptr)) { return false; }
    }
    return true;
}

static void FunctorOfVoidFromCloudStatusAndListOfTarget_func(void * _state, easyar_CloudStatus arg0, easyar_ListOfTarget * arg1, /* OUT */ easyar_String * * _exception)
{
    *_exception = nullptr;
    try {
        CloudStatus cpparg0 = static_cast<CloudStatus>(arg0);
        easyar_ListOfTarget_copy(arg1, &arg1);
        std::vector<std::shared_ptr<Target>> cpparg1 = std_vector_from_easyar_ListOfTarget(std::shared_ptr<easyar_ListOfTarget>(arg1, [](easyar_ListOfTarget * ptr) { easyar_ListOfTarget__dtor(ptr); }));
        auto f = reinterpret_cast<std::function<void(CloudStatus, std::vector<std::shared_ptr<Target>>)> *>(_state);
        (*f)(cpparg0, cpparg1);
    } catch (std::exception & ex) {
        auto message = std::string() + typeid(*(&ex)).name() + u8"\n" + ex.what();
        easyar_String_from_utf8_begin(message.c_str(), _exception);
    }
}
static void FunctorOfVoidFromCloudStatusAndListOfTarget_destroy(void * _state)
{
    auto f = reinterpret_cast<std::function<void(CloudStatus, std::vector<std::shared_ptr<Target>>)> *>(_state);
    delete f;
}
static inline easyar_FunctorOfVoidFromCloudStatusAndListOfTarget FunctorOfVoidFromCloudStatusAndListOfTarget_to_c(std::function<void(CloudStatus, std::vector<std::shared_ptr<Target>>)> f)
{
    return easyar_FunctorOfVoidFromCloudStatusAndListOfTarget{new std::function<void(CloudStatus, std::vector<std::shared_ptr<Target>>)>(f), FunctorOfVoidFromCloudStatusAndListOfTarget_func, FunctorOfVoidFromCloudStatusAndListOfTarget_destroy};
}

static inline std::shared_ptr<easyar_ListOfBlockInfo> std_vector_to_easyar_ListOfBlockInfo(std::vector<BlockInfo> l)
{
    std::vector<easyar_BlockInfo> values;
    values.reserve(l.size());
    for (auto v : l) {
        auto cv = easyar_BlockInfo{v.x_, v.y_, v.z_, v.numOfVertex_, v.startPointOfVertex_, v.numOfIndex_, v.startPointOfIndex_, v.age_};
        values.push_back(cv);
    }
    easyar_ListOfBlockInfo * ptr;
    easyar_ListOfBlockInfo__ctor(values.data(), values.data() + values.size(), &ptr);
    return std::shared_ptr<easyar_ListOfBlockInfo>(ptr, [](easyar_ListOfBlockInfo * ptr) { easyar_ListOfBlockInfo__dtor(ptr); });
}
static inline std::vector<BlockInfo> std_vector_from_easyar_ListOfBlockInfo(std::shared_ptr<easyar_ListOfBlockInfo> pl)
{
    auto size = easyar_ListOfBlockInfo_size(pl.get());
    std::vector<BlockInfo> values;
    values.reserve(size);
    for (int k = 0; k < size; k += 1) {
        auto v = easyar_ListOfBlockInfo_at(pl.get(), k);
        values.push_back(BlockInfo{v.x_, v.y_, v.z_, v.numOfVertex_, v.startPointOfVertex_, v.numOfIndex_, v.startPointOfIndex_, v.age_});
    }
    return values;
}
static inline bool easyar_ListOfBlockInfo_check_external_cpp(const std::vector<BlockInfo> & l)
{
    return true;
}

static void FunctorOfVoidFromInputFrame_func(void * _state, easyar_InputFrame * arg0, /* OUT */ easyar_String * * _exception)
{
    *_exception = nullptr;
    try {
        easyar_InputFrame__retain(arg0, &arg0);
        std::shared_ptr<InputFrame> cpparg0 = InputFrame::from_cdata(std::shared_ptr<easyar_InputFrame>(arg0, [](easyar_InputFrame * ptr) { easyar_InputFrame__dtor(ptr); }));
        auto f = reinterpret_cast<std::function<void(std::shared_ptr<InputFrame>)> *>(_state);
        (*f)(cpparg0);
    } catch (std::exception & ex) {
        auto message = std::string() + typeid(*(&ex)).name() + u8"\n" + ex.what();
        easyar_String_from_utf8_begin(message.c_str(), _exception);
    }
}
static void FunctorOfVoidFromInputFrame_destroy(void * _state)
{
    auto f = reinterpret_cast<std::function<void(std::shared_ptr<InputFrame>)> *>(_state);
    delete f;
}
static inline easyar_FunctorOfVoidFromInputFrame FunctorOfVoidFromInputFrame_to_c(std::function<void(std::shared_ptr<InputFrame>)> f)
{
    return easyar_FunctorOfVoidFromInputFrame{new std::function<void(std::shared_ptr<InputFrame>)>(f), FunctorOfVoidFromInputFrame_func, FunctorOfVoidFromInputFrame_destroy};
}

static inline std::shared_ptr<easyar_ListOfImageTarget> std_vector_to_easyar_ListOfImageTarget(std::vector<std::shared_ptr<ImageTarget>> l)
{
    std::vector<easyar_ImageTarget *> values;
    values.reserve(l.size());
    for (auto v : l) {
        auto cv = v->get_cdata().get();
        easyar_ImageTarget__retain(cv, &cv);
        values.push_back(cv);
    }
    easyar_ListOfImageTarget * ptr;
    easyar_ListOfImageTarget__ctor(values.data(), values.data() + values.size(), &ptr);
    return std::shared_ptr<easyar_ListOfImageTarget>(ptr, [](easyar_ListOfImageTarget * ptr) { easyar_ListOfImageTarget__dtor(ptr); });
}
static inline std::vector<std::shared_ptr<ImageTarget>> std_vector_from_easyar_ListOfImageTarget(std::shared_ptr<easyar_ListOfImageTarget> pl)
{
    auto size = easyar_ListOfImageTarget_size(pl.get());
    std::vector<std::shared_ptr<ImageTarget>> values;
    values.reserve(size);
    for (int k = 0; k < size; k += 1) {
        auto v = easyar_ListOfImageTarget_at(pl.get(), k);
        easyar_ImageTarget__retain(v, &v);
        values.push_back(ImageTarget::from_cdata(std::shared_ptr<easyar_ImageTarget>(v, [](easyar_ImageTarget * ptr) { easyar_ImageTarget__dtor(ptr); })));
    }
    return values;
}
static inline bool easyar_ListOfImageTarget_check_external_cpp(const std::vector<std::shared_ptr<ImageTarget>> & l)
{
    for (auto e : l) {
        if (!(e != nullptr)) { return false; }
    }
    return true;
}

static inline std::shared_ptr<easyar_ListOfImage> std_vector_to_easyar_ListOfImage(std::vector<std::shared_ptr<Image>> l)
{
    std::vector<easyar_Image *> values;
    values.reserve(l.size());
    for (auto v : l) {
        auto cv = v->get_cdata().get();
        easyar_Image__retain(cv, &cv);
        values.push_back(cv);
    }
    easyar_ListOfImage * ptr;
    easyar_ListOfImage__ctor(values.data(), values.data() + values.size(), &ptr);
    return std::shared_ptr<easyar_ListOfImage>(ptr, [](easyar_ListOfImage * ptr) { easyar_ListOfImage__dtor(ptr); });
}
static inline std::vector<std::shared_ptr<Image>> std_vector_from_easyar_ListOfImage(std::shared_ptr<easyar_ListOfImage> pl)
{
    auto size = easyar_ListOfImage_size(pl.get());
    std::vector<std::shared_ptr<Image>> values;
    values.reserve(size);
    for (int k = 0; k < size; k += 1) {
        auto v = easyar_ListOfImage_at(pl.get(), k);
        easyar_Image__retain(v, &v);
        values.push_back(Image::from_cdata(std::shared_ptr<easyar_Image>(v, [](easyar_Image * ptr) { easyar_Image__dtor(ptr); })));
    }
    return values;
}
static inline bool easyar_ListOfImage_check_external_cpp(const std::vector<std::shared_ptr<Image>> & l)
{
    for (auto e : l) {
        if (!(e != nullptr)) { return false; }
    }
    return true;
}

static void FunctorOfVoidFromPermissionStatusAndString_func(void * _state, easyar_PermissionStatus arg0, easyar_String * arg1, /* OUT */ easyar_String * * _exception)
{
    *_exception = nullptr;
    try {
        PermissionStatus cpparg0 = static_cast<PermissionStatus>(arg0);
        easyar_String_copy(arg1, &arg1);
        std::string cpparg1 = std_string_from_easyar_String(std::shared_ptr<easyar_String>(arg1, [](easyar_String * ptr) { easyar_String__dtor(ptr); }));
        auto f = reinterpret_cast<std::function<void(PermissionStatus, std::string)> *>(_state);
        (*f)(cpparg0, cpparg1);
    } catch (std::exception & ex) {
        auto message = std::string() + typeid(*(&ex)).name() + u8"\n" + ex.what();
        easyar_String_from_utf8_begin(message.c_str(), _exception);
    }
}
static void FunctorOfVoidFromPermissionStatusAndString_destroy(void * _state)
{
    auto f = reinterpret_cast<std::function<void(PermissionStatus, std::string)> *>(_state);
    delete f;
}
static inline easyar_FunctorOfVoidFromPermissionStatusAndString FunctorOfVoidFromPermissionStatusAndString_to_c(std::function<void(PermissionStatus, std::string)> f)
{
    return easyar_FunctorOfVoidFromPermissionStatusAndString{new std::function<void(PermissionStatus, std::string)>(f), FunctorOfVoidFromPermissionStatusAndString_func, FunctorOfVoidFromPermissionStatusAndString_destroy};
}

static void FunctorOfVoidFromRecordStatusAndString_func(void * _state, easyar_RecordStatus arg0, easyar_String * arg1, /* OUT */ easyar_String * * _exception)
{
    *_exception = nullptr;
    try {
        RecordStatus cpparg0 = static_cast<RecordStatus>(arg0);
        easyar_String_copy(arg1, &arg1);
        std::string cpparg1 = std_string_from_easyar_String(std::shared_ptr<easyar_String>(arg1, [](easyar_String * ptr) { easyar_String__dtor(ptr); }));
        auto f = reinterpret_cast<std::function<void(RecordStatus, std::string)> *>(_state);
        (*f)(cpparg0, cpparg1);
    } catch (std::exception & ex) {
        auto message = std::string() + typeid(*(&ex)).name() + u8"\n" + ex.what();
        easyar_String_from_utf8_begin(message.c_str(), _exception);
    }
}
static void FunctorOfVoidFromRecordStatusAndString_destroy(void * _state)
{
    auto f = reinterpret_cast<std::function<void(RecordStatus, std::string)> *>(_state);
    delete f;
}
static inline easyar_FunctorOfVoidFromRecordStatusAndString FunctorOfVoidFromRecordStatusAndString_to_c(std::function<void(RecordStatus, std::string)> f)
{
    return easyar_FunctorOfVoidFromRecordStatusAndString{new std::function<void(RecordStatus, std::string)>(f), FunctorOfVoidFromRecordStatusAndString_func, FunctorOfVoidFromRecordStatusAndString_destroy};
}

static inline std::shared_ptr<easyar_ListOfPlaneData> std_vector_to_easyar_ListOfPlaneData(std::vector<std::shared_ptr<PlaneData>> l)
{
    std::vector<easyar_PlaneData *> values;
    values.reserve(l.size());
    for (auto v : l) {
        auto cv = v->get_cdata().get();
        easyar_PlaneData__retain(cv, &cv);
        values.push_back(cv);
    }
    easyar_ListOfPlaneData * ptr;
    easyar_ListOfPlaneData__ctor(values.data(), values.data() + values.size(), &ptr);
    return std::shared_ptr<easyar_ListOfPlaneData>(ptr, [](easyar_ListOfPlaneData * ptr) { easyar_ListOfPlaneData__dtor(ptr); });
}
static inline std::vector<std::shared_ptr<PlaneData>> std_vector_from_easyar_ListOfPlaneData(std::shared_ptr<easyar_ListOfPlaneData> pl)
{
    auto size = easyar_ListOfPlaneData_size(pl.get());
    std::vector<std::shared_ptr<PlaneData>> values;
    values.reserve(size);
    for (int k = 0; k < size; k += 1) {
        auto v = easyar_ListOfPlaneData_at(pl.get(), k);
        easyar_PlaneData__retain(v, &v);
        values.push_back(PlaneData::from_cdata(std::shared_ptr<easyar_PlaneData>(v, [](easyar_PlaneData * ptr) { easyar_PlaneData__dtor(ptr); })));
    }
    return values;
}
static inline bool easyar_ListOfPlaneData_check_external_cpp(const std::vector<std::shared_ptr<PlaneData>> & l)
{
    for (auto e : l) {
        if (!(e != nullptr)) { return false; }
    }
    return true;
}

static void FunctorOfVoidFromOptionalOfBuffer_func(void * _state, easyar_OptionalOfBuffer arg0, /* OUT */ easyar_String * * _exception)
{
    *_exception = nullptr;
    try {
        if (arg0.has_value) { easyar_Buffer__retain(arg0.value, &arg0.value); }
        std::optional<std::shared_ptr<Buffer>> cpparg0 = (arg0.has_value ? Buffer::from_cdata(std::shared_ptr<easyar_Buffer>(arg0.value, [](easyar_Buffer * ptr) { easyar_Buffer__dtor(ptr); })) : std::optional<std::shared_ptr<Buffer>>{});
        auto f = reinterpret_cast<std::function<void(std::optional<std::shared_ptr<Buffer>>)> *>(_state);
        (*f)(cpparg0);
    } catch (std::exception & ex) {
        auto message = std::string() + typeid(*(&ex)).name() + u8"\n" + ex.what();
        easyar_String_from_utf8_begin(message.c_str(), _exception);
    }
}
static void FunctorOfVoidFromOptionalOfBuffer_destroy(void * _state)
{
    auto f = reinterpret_cast<std::function<void(std::optional<std::shared_ptr<Buffer>>)> *>(_state);
    delete f;
}
static inline easyar_FunctorOfVoidFromOptionalOfBuffer FunctorOfVoidFromOptionalOfBuffer_to_c(std::function<void(std::optional<std::shared_ptr<Buffer>>)> f)
{
    return easyar_FunctorOfVoidFromOptionalOfBuffer{new std::function<void(std::optional<std::shared_ptr<Buffer>>)>(f), FunctorOfVoidFromOptionalOfBuffer_func, FunctorOfVoidFromOptionalOfBuffer_destroy};
}

static void FunctorOfVoidFromBool_func(void * _state, bool arg0, /* OUT */ easyar_String * * _exception)
{
    *_exception = nullptr;
    try {
        bool cpparg0 = arg0;
        auto f = reinterpret_cast<std::function<void(bool)> *>(_state);
        (*f)(cpparg0);
    } catch (std::exception & ex) {
        auto message = std::string() + typeid(*(&ex)).name() + u8"\n" + ex.what();
        easyar_String_from_utf8_begin(message.c_str(), _exception);
    }
}
static void FunctorOfVoidFromBool_destroy(void * _state)
{
    auto f = reinterpret_cast<std::function<void(bool)> *>(_state);
    delete f;
}
static inline easyar_FunctorOfVoidFromBool FunctorOfVoidFromBool_to_c(std::function<void(bool)> f)
{
    return easyar_FunctorOfVoidFromBool{new std::function<void(bool)>(f), FunctorOfVoidFromBool_func, FunctorOfVoidFromBool_destroy};
}

static void FunctorOfVoidFromCameraState_func(void * _state, easyar_CameraState arg0, /* OUT */ easyar_String * * _exception)
{
    *_exception = nullptr;
    try {
        CameraState cpparg0 = static_cast<CameraState>(arg0);
        auto f = reinterpret_cast<std::function<void(CameraState)> *>(_state);
        (*f)(cpparg0);
    } catch (std::exception & ex) {
        auto message = std::string() + typeid(*(&ex)).name() + u8"\n" + ex.what();
        easyar_String_from_utf8_begin(message.c_str(), _exception);
    }
}
static void FunctorOfVoidFromCameraState_destroy(void * _state)
{
    auto f = reinterpret_cast<std::function<void(CameraState)> *>(_state);
    delete f;
}
static inline easyar_FunctorOfVoidFromCameraState FunctorOfVoidFromCameraState_to_c(std::function<void(CameraState)> f)
{
    return easyar_FunctorOfVoidFromCameraState{new std::function<void(CameraState)>(f), FunctorOfVoidFromCameraState_func, FunctorOfVoidFromCameraState_destroy};
}

static void FunctorOfVoidFromFeedbackFrame_func(void * _state, easyar_FeedbackFrame * arg0, /* OUT */ easyar_String * * _exception)
{
    *_exception = nullptr;
    try {
        easyar_FeedbackFrame__retain(arg0, &arg0);
        std::shared_ptr<FeedbackFrame> cpparg0 = FeedbackFrame::from_cdata(std::shared_ptr<easyar_FeedbackFrame>(arg0, [](easyar_FeedbackFrame * ptr) { easyar_FeedbackFrame__dtor(ptr); }));
        auto f = reinterpret_cast<std::function<void(std::shared_ptr<FeedbackFrame>)> *>(_state);
        (*f)(cpparg0);
    } catch (std::exception & ex) {
        auto message = std::string() + typeid(*(&ex)).name() + u8"\n" + ex.what();
        easyar_String_from_utf8_begin(message.c_str(), _exception);
    }
}
static void FunctorOfVoidFromFeedbackFrame_destroy(void * _state)
{
    auto f = reinterpret_cast<std::function<void(std::shared_ptr<FeedbackFrame>)> *>(_state);
    delete f;
}
static inline easyar_FunctorOfVoidFromFeedbackFrame FunctorOfVoidFromFeedbackFrame_to_c(std::function<void(std::shared_ptr<FeedbackFrame>)> f)
{
    return easyar_FunctorOfVoidFromFeedbackFrame{new std::function<void(std::shared_ptr<FeedbackFrame>)>(f), FunctorOfVoidFromFeedbackFrame_func, FunctorOfVoidFromFeedbackFrame_destroy};
}

static void FunctorOfOutputFrameFromListOfOutputFrame_func(void * _state, easyar_ListOfOutputFrame * arg0, /* OUT */ easyar_OutputFrame * * Return, /* OUT */ easyar_String * * _exception)
{
    *_exception = nullptr;
    try {
        easyar_ListOfOutputFrame_copy(arg0, &arg0);
        std::vector<std::shared_ptr<OutputFrame>> cpparg0 = std_vector_from_easyar_ListOfOutputFrame(std::shared_ptr<easyar_ListOfOutputFrame>(arg0, [](easyar_ListOfOutputFrame * ptr) { easyar_ListOfOutputFrame__dtor(ptr); }));
        auto f = reinterpret_cast<std::function<std::shared_ptr<OutputFrame>(std::vector<std::shared_ptr<OutputFrame>>)> *>(_state);
        std::shared_ptr<OutputFrame> _return_value_ = (*f)(cpparg0);
        if (!(_return_value_ != nullptr)) {
            easyar_String_from_utf8_begin("InvalidReturnValue", _exception);
            return;
        }
        easyar_OutputFrame * _return_value_c_ = _return_value_->get_cdata().get();
        easyar_OutputFrame__retain(_return_value_c_, &_return_value_c_);
        *Return = _return_value_c_;
    } catch (std::exception & ex) {
        auto message = std::string() + typeid(*(&ex)).name() + u8"\n" + ex.what();
        easyar_String_from_utf8_begin(message.c_str(), _exception);
    }
}
static void FunctorOfOutputFrameFromListOfOutputFrame_destroy(void * _state)
{
    auto f = reinterpret_cast<std::function<std::shared_ptr<OutputFrame>(std::vector<std::shared_ptr<OutputFrame>>)> *>(_state);
    delete f;
}
static inline easyar_FunctorOfOutputFrameFromListOfOutputFrame FunctorOfOutputFrameFromListOfOutputFrame_to_c(std::function<std::shared_ptr<OutputFrame>(std::vector<std::shared_ptr<OutputFrame>>)> f)
{
    return easyar_FunctorOfOutputFrameFromListOfOutputFrame{new std::function<std::shared_ptr<OutputFrame>(std::vector<std::shared_ptr<OutputFrame>>)>(f), FunctorOfOutputFrameFromListOfOutputFrame_func, FunctorOfOutputFrameFromListOfOutputFrame_destroy};
}

static inline std::shared_ptr<easyar_ListOfOutputFrame> std_vector_to_easyar_ListOfOutputFrame(std::vector<std::shared_ptr<OutputFrame>> l)
{
    std::vector<easyar_OutputFrame *> values;
    values.reserve(l.size());
    for (auto v : l) {
        auto cv = v->get_cdata().get();
        easyar_OutputFrame__retain(cv, &cv);
        values.push_back(cv);
    }
    easyar_ListOfOutputFrame * ptr;
    easyar_ListOfOutputFrame__ctor(values.data(), values.data() + values.size(), &ptr);
    return std::shared_ptr<easyar_ListOfOutputFrame>(ptr, [](easyar_ListOfOutputFrame * ptr) { easyar_ListOfOutputFrame__dtor(ptr); });
}
static inline std::vector<std::shared_ptr<OutputFrame>> std_vector_from_easyar_ListOfOutputFrame(std::shared_ptr<easyar_ListOfOutputFrame> pl)
{
    auto size = easyar_ListOfOutputFrame_size(pl.get());
    std::vector<std::shared_ptr<OutputFrame>> values;
    values.reserve(size);
    for (int k = 0; k < size; k += 1) {
        auto v = easyar_ListOfOutputFrame_at(pl.get(), k);
        easyar_OutputFrame__retain(v, &v);
        values.push_back(OutputFrame::from_cdata(std::shared_ptr<easyar_OutputFrame>(v, [](easyar_OutputFrame * ptr) { easyar_OutputFrame__dtor(ptr); })));
    }
    return values;
}
static inline bool easyar_ListOfOutputFrame_check_external_cpp(const std::vector<std::shared_ptr<OutputFrame>> & l)
{
    for (auto e : l) {
        if (!(e != nullptr)) { return false; }
    }
    return true;
}

static void FunctorOfVoidFromVideoStatus_func(void * _state, easyar_VideoStatus arg0, /* OUT */ easyar_String * * _exception)
{
    *_exception = nullptr;
    try {
        VideoStatus cpparg0 = static_cast<VideoStatus>(arg0);
        auto f = reinterpret_cast<std::function<void(VideoStatus)> *>(_state);
        (*f)(cpparg0);
    } catch (std::exception & ex) {
        auto message = std::string() + typeid(*(&ex)).name() + u8"\n" + ex.what();
        easyar_String_from_utf8_begin(message.c_str(), _exception);
    }
}
static void FunctorOfVoidFromVideoStatus_destroy(void * _state)
{
    auto f = reinterpret_cast<std::function<void(VideoStatus)> *>(_state);
    delete f;
}
static inline easyar_FunctorOfVoidFromVideoStatus FunctorOfVoidFromVideoStatus_to_c(std::function<void(VideoStatus)> f)
{
    return easyar_FunctorOfVoidFromVideoStatus{new std::function<void(VideoStatus)>(f), FunctorOfVoidFromVideoStatus_func, FunctorOfVoidFromVideoStatus_destroy};
}

static void FunctorOfVoidFromLogLevelAndString_func(void * _state, easyar_LogLevel arg0, easyar_String * arg1, /* OUT */ easyar_String * * _exception)
{
    *_exception = nullptr;
    try {
        LogLevel cpparg0 = static_cast<LogLevel>(arg0);
        easyar_String_copy(arg1, &arg1);
        std::string cpparg1 = std_string_from_easyar_String(std::shared_ptr<easyar_String>(arg1, [](easyar_String * ptr) { easyar_String__dtor(ptr); }));
        auto f = reinterpret_cast<std::function<void(LogLevel, std::string)> *>(_state);
        (*f)(cpparg0, cpparg1);
    } catch (std::exception & ex) {
        auto message = std::string() + typeid(*(&ex)).name() + u8"\n" + ex.what();
        easyar_String_from_utf8_begin(message.c_str(), _exception);
    }
}
static void FunctorOfVoidFromLogLevelAndString_destroy(void * _state)
{
    auto f = reinterpret_cast<std::function<void(LogLevel, std::string)> *>(_state);
    delete f;
}
static inline easyar_FunctorOfVoidFromLogLevelAndString FunctorOfVoidFromLogLevelAndString_to_c(std::function<void(LogLevel, std::string)> f)
{
    return easyar_FunctorOfVoidFromLogLevelAndString{new std::function<void(LogLevel, std::string)>(f), FunctorOfVoidFromLogLevelAndString_func, FunctorOfVoidFromLogLevelAndString_destroy};
}

}

#endif

#undef _INLINE_SPECIFIER_
