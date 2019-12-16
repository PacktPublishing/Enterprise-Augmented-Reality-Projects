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

@interface easyar_ImageTargetParameters : easyar_RefBase

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

+ (easyar_ImageTargetParameters *) create;
- (easyar_Image *)image;
- (void)setImage:(easyar_Image *)image;
- (NSString *)name;
- (void)setName:(NSString *)name;
- (NSString *)uid;
- (void)setUid:(NSString *)uid;
- (NSString *)meta;
- (void)setMeta:(NSString *)meta;
- (float)scale;
- (void)setScale:(float)scale;

@end

@interface easyar_ImageTarget : easyar_Target

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

+ (easyar_ImageTarget *) create;
+ (easyar_ImageTarget *)createFromParameters:(easyar_ImageTargetParameters *)parameters;
+ (easyar_ImageTarget *)createFromTargetFile:(NSString *)path storageType:(easyar_StorageType)storageType;
+ (easyar_ImageTarget *)createFromTargetData:(easyar_Buffer *)buffer;
- (bool)save:(NSString *)path;
+ (easyar_ImageTarget *)createFromImageFile:(NSString *)path storageType:(easyar_StorageType)storageType name:(NSString *)name uid:(NSString *)uid meta:(NSString *)meta scale:(float)scale;
+ (NSArray<easyar_ImageTarget *> *)setupAll:(NSString *)path storageType:(easyar_StorageType)storageType;
- (float)scale;
- (float)aspectRatio;
- (bool)setScale:(float)scale;
- (NSArray<easyar_Image *> *)images;
- (int)runtimeID;
- (NSString *)uid;
- (NSString *)name;
- (void)setName:(NSString *)name;
- (NSString *)meta;
- (void)setMeta:(NSString *)data;

@end
