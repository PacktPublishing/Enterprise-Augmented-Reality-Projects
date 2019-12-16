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

@interface easyar_CADTarget : easyar_Target

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

+ (easyar_CADTarget *) create;
+ (easyar_CADTarget *)createFromUnity:(easyar_Buffer *)vertices faces:(easyar_Buffer *)faces transform:(easyar_Matrix44F *)transform localScale:(float)localScale;
- (void)updateTransform:(easyar_Matrix44F *)transform localScale:(float)localScale;
- (void)updateTrackConfig:(float)threshContrast threshConsist:(float)threshConsist threshQuality:(float)threshQuality;
+ (easyar_CADTarget *)createFromObjectFile:(NSString *)path storageType:(easyar_StorageType)storageType name:(NSString *)name uid:(NSString *)uid meta:(NSString *)meta scale:(float)scale;
+ (NSArray<easyar_CADTarget *> *)setupAll:(NSString *)path storageType:(easyar_StorageType)storageType;
- (float)scale;
- (NSArray<easyar_Vec3F *> *)boundingBox;
- (NSArray<easyar_Vec3F *> *)boundingBoxGL;
- (bool)setScale:(float)scale;
- (int)runtimeID;
- (NSString *)uid;
- (NSString *)name;
- (void)setName:(NSString *)name;
- (NSString *)meta;
- (void)setMeta:(NSString *)data;

@end
