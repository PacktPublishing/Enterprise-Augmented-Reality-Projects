//=============================================================================================================================
//
// EasyAR 3.0.1-final-r238a6316e
// Copyright (c) 2015-2019 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#import "easyar/types.oc.h"

@interface easyar_CameraParameters : easyar_RefBase

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

+ (easyar_CameraParameters *) create:(easyar_Vec2I *)size focalLength:(easyar_Vec2F *)focalLength principalPoint:(easyar_Vec2F *)principalPoint cameraDeviceType:(easyar_CameraDeviceType)cameraDeviceType cameraOrientation:(int)cameraOrientation;
- (easyar_Vec2I *)size;
- (easyar_Vec2F *)focalLength;
- (easyar_Vec2F *)principalPoint;
- (easyar_CameraDeviceType)cameraDeviceType;
- (int)cameraOrientation;
+ (easyar_CameraParameters *)createWithDefaultIntrinsics:(easyar_Vec2I *)size cameraDeviceType:(easyar_CameraDeviceType)cameraDeviceType cameraOrientation:(int)cameraOrientation;
- (int)imageOrientation:(int)screenRotation;
- (bool)imageHorizontalFlip:(bool)manualHorizontalFlip;
- (easyar_Matrix44F *)projection:(float)nearPlane farPlane:(float)farPlane viewportAspectRatio:(float)viewportAspectRatio screenRotation:(int)screenRotation combiningFlip:(bool)combiningFlip manualHorizontalFlip:(bool)manualHorizontalFlip;
- (easyar_Matrix44F *)imageProjection:(float)viewportAspectRatio screenRotation:(int)screenRotation combiningFlip:(bool)combiningFlip manualHorizontalFlip:(bool)manualHorizontalFlip;
- (easyar_Vec2F *)screenCoordinatesFromImageCoordinates:(float)viewportAspectRatio screenRotation:(int)screenRotation combiningFlip:(bool)combiningFlip manualHorizontalFlip:(bool)manualHorizontalFlip imageCoordinates:(easyar_Vec2F *)imageCoordinates;
- (easyar_Vec2F *)imageCoordinatesFromScreenCoordinates:(float)viewportAspectRatio screenRotation:(int)screenRotation combiningFlip:(bool)combiningFlip manualHorizontalFlip:(bool)manualHorizontalFlip screenCoordinates:(easyar_Vec2F *)screenCoordinates;
- (bool)equalsTo:(easyar_CameraParameters *)other;

@end
