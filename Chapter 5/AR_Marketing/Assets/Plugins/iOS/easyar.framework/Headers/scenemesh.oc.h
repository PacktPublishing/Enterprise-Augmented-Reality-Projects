//=============================================================================================================================
//
// EasyAR 3.0.1-final-r238a6316e
// Copyright (c) 2015-2019 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#import "easyar/types.oc.h"

/// <summary>
/// record
/// </summary>
@interface easyar_BlockInfo : NSObject

@property (nonatomic) int x_;
@property (nonatomic) int y_;
@property (nonatomic) int z_;
@property (nonatomic) int numOfVertex_;
@property (nonatomic) int startPointOfVertex_;
@property (nonatomic) int numOfIndex_;
@property (nonatomic) int startPointOfIndex_;
@property (nonatomic) int age_;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)create:(int)x_ y_:(int)y_ z_:(int)z_ numOfVertex_:(int)numOfVertex_ startPointOfVertex_:(int)startPointOfVertex_ numOfIndex_:(int)numOfIndex_ startPointOfIndex_:(int)startPointOfIndex_ age_:(int)age_;

@end

@interface easyar_SceneMesh : easyar_RefBase

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

+ (easyar_SceneMesh *) create;
- (int)getNumOfVertexAll;
- (int)getNumOfIndexAll;
- (easyar_Buffer *)getVerticesAll;
- (easyar_Buffer *)getNormalsAll;
- (easyar_Buffer *)getIndicesAll;
- (int)getNumOfVertexIncremental;
- (int)getNumOfIndexIncremental;
- (easyar_Buffer *)getVerticesIncremental;
- (easyar_Buffer *)getNormalsIncremental;
- (easyar_Buffer *)getIndicesIncremental;
- (NSArray<easyar_BlockInfo *> *)getBlocksInfoIncremental;
- (float)getBlockDimentionInMeters;

@end
