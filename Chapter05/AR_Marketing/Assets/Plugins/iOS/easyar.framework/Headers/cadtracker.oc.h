//=============================================================================================================================
//
// EasyAR 3.0.1-final-r238a6316e
// Copyright (c) 2015-2019 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#import "easyar/types.oc.h"
#import "easyar/target.oc.h"

@interface easyar_CADTrackerResult : easyar_TargetTrackerResult

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

- (NSArray<easyar_TargetInstance *> *)targetInstances;
- (void)setTargetInstances:(NSArray<easyar_TargetInstance *> *)instances;

@end

@interface easyar_CADTracker : easyar_RefBase

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

+ (bool)isAvailable;
- (easyar_FeedbackFrameSink *)feedbackFrameSink;
- (easyar_OutputFrameSource *)outputFrameSource;
+ (easyar_CADTracker *)create;
- (bool)start;
- (void)stop;
- (void)close;
- (void)loadTarget:(easyar_Target *)target callbackScheduler:(easyar_CallbackScheduler *)callbackScheduler callback:(void (^)(easyar_Target * target, bool status))callback;
- (void)unloadTarget:(easyar_Target *)target callbackScheduler:(easyar_CallbackScheduler *)callbackScheduler callback:(void (^)(easyar_Target * target, bool status))callback;
- (NSArray<easyar_Target *> *)targets;

@end
