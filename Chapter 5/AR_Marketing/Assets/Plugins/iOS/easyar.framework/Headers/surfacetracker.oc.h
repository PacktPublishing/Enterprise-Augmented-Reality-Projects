//=============================================================================================================================
//
// EasyAR 3.0.1-final-r238a6316e
// Copyright (c) 2015-2019 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#import "easyar/types.oc.h"
#import "easyar/frame.oc.h"

@interface easyar_SurfaceTrackerResult : easyar_FrameFilterResult

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

- (easyar_Matrix44F *)transform;
- (easyar_SurfaceTrackingStatus)status;

@end

@interface easyar_SurfaceTracker : easyar_RefBase

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

+ (bool)isAvailable;
- (easyar_InputFrameSink *)inputFrameSink;
- (easyar_OutputFrameSource *)outputFrameSource;
+ (easyar_SurfaceTracker *)create;
- (bool)start;
- (void)stop;
- (void)close;
- (void)alignTargetToCameraImagePoint:(easyar_Vec2F *)cameraImagePoint;

@end
