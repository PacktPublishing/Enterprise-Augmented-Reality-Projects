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

@interface easyar_SparseSpatialMapResult : easyar_FrameFilterResult

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

- (easyar_MapTrackingStatus)getMapTrackingStatus;
- (easyar_Matrix44F *)getVioPose;
- (easyar_Matrix44F *)getMapPose;
- (bool)getLocalizedStatus;
- (NSString *)getCurrentLocalizedMapID;

@end

@interface easyar_PlaneData : easyar_RefBase

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

+ (easyar_PlaneData *) create;
- (easyar_PlaneType)getType;
- (easyar_Matrix44F *)getPose;
- (float)getExtentX;
- (float)getExtentZ;

@end

@interface easyar_SparseSpatialMapConfig : easyar_RefBase

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

+ (easyar_SparseSpatialMapConfig *) create;
- (void)setLocalizeConfig:(easyar_LocalizeConfig)_value;
- (easyar_LocalizeConfig)getLocalizeConfig;
- (void)setMapConfig:(easyar_MapConfig)_value;
- (easyar_MapConfig)getMapConfig;

@end

@interface easyar_SparseSpatialMap : easyar_RefBase

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

+ (bool)isAvailable;
- (easyar_InputFrameSink *)inputFrameSink;
- (easyar_OutputFrameSource *)outputFrameSource;
+ (easyar_SparseSpatialMap *)create;
- (bool)start;
- (void)stop;
- (void)close;
- (easyar_Buffer *)getPointCloudBuffer;
- (NSArray<easyar_PlaneData *> *)getMapPlanes;
- (NSArray<easyar_Vec3F *> *)hitTestAgainstPointCloud:(easyar_Vec2F *)cameraImagePoint;
- (NSArray<easyar_Vec3F *> *)hitTestAgainstPlanes:(easyar_Vec2F *)cameraImagePoint;
- (bool)saveMap:(easyar_CallbackScheduler *)callbackScheduler resultCallBack:(void (^)(easyar_Buffer * pMapData))resultCallBack;
- (bool)loadMap:(easyar_Buffer *)pMapData mapID:(NSString *)mapID callbackScheduler:(easyar_CallbackScheduler *)callbackScheduler resultCallBack:(void (^)(bool))resultCallBack;
- (bool)unloadMap:(NSString *)mapID callbackScheduler:(easyar_CallbackScheduler *)callbackScheduler resultCallBack:(void (^)(bool))resultCallBack;
- (void)setConfig:(easyar_SparseSpatialMapConfig *)config;
- (easyar_SparseSpatialMapConfig *)getConfig;
- (bool)startLocalize;
- (bool)stopLocalize;

@end
