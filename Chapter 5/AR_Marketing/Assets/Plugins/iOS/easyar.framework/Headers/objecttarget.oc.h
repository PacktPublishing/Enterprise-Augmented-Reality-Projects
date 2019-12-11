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

@interface easyar_ObjectTargetParameters : easyar_RefBase

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

+ (easyar_ObjectTargetParameters *) create;
- (easyar_BufferDictionary *)bufferDictionary;
- (void)setBufferDictionary:(easyar_BufferDictionary *)bufferDictionary;
- (NSString *)objPath;
- (void)setObjPath:(NSString *)objPath;
- (NSString *)name;
- (void)setName:(NSString *)name;
- (NSString *)uid;
- (void)setUid:(NSString *)uid;
- (NSString *)meta;
- (void)setMeta:(NSString *)meta;
- (float)scale;
- (void)setScale:(float)size;

@end

@interface easyar_ObjectTarget : easyar_Target

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

+ (easyar_ObjectTarget *) create;
+ (easyar_ObjectTarget *)createFromParameters:(easyar_ObjectTargetParameters *)parameters;
+ (easyar_ObjectTarget *)createFromObjectFile:(NSString *)path storageType:(easyar_StorageType)storageType name:(NSString *)name uid:(NSString *)uid meta:(NSString *)meta scale:(float)scale;
+ (NSArray<easyar_ObjectTarget *> *)setupAll:(NSString *)path storageType:(easyar_StorageType)storageType;
- (float)scale;
- (NSArray<easyar_Vec3F *> *)boundingBox;
- (bool)setScale:(float)scale;
- (int)runtimeID;
- (NSString *)uid;
- (NSString *)name;
- (void)setName:(NSString *)name;
- (NSString *)meta;
- (void)setMeta:(NSString *)data;

@end
