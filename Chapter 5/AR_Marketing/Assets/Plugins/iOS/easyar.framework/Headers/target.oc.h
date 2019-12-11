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

@interface easyar_Target : easyar_RefBase

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

- (int)runtimeID;
- (NSString *)uid;
- (NSString *)name;
- (void)setName:(NSString *)name;
- (NSString *)meta;
- (void)setMeta:(NSString *)data;

@end

@interface easyar_TargetInstance : easyar_RefBase

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

+ (easyar_TargetInstance *) create;
- (easyar_TargetStatus)status;
- (easyar_Target *)target;
- (easyar_Matrix44F *)pose;

@end

@interface easyar_TargetTrackerResult : easyar_FrameFilterResult

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

- (NSArray<easyar_TargetInstance *> *)targetInstances;
- (void)setTargetInstances:(NSArray<easyar_TargetInstance *> *)instances;

@end
