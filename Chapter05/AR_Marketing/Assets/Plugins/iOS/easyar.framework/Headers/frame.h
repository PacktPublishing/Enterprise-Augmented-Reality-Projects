//=============================================================================================================================
//
// EasyAR 3.0.1-final-r238a6316e
// Copyright (c) 2015-2019 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#ifndef __EASYAR_FRAME_H__
#define __EASYAR_FRAME_H__

#include "easyar/types.h"

#ifdef __cplusplus
extern "C" {
#endif

int easyar_InputFrame_index(const easyar_InputFrame * This);
void easyar_InputFrame_image(const easyar_InputFrame * This, /* OUT */ easyar_Image * * Return);
bool easyar_InputFrame_hasCameraParameters(const easyar_InputFrame * This);
void easyar_InputFrame_cameraParameters(const easyar_InputFrame * This, /* OUT */ easyar_CameraParameters * * Return);
bool easyar_InputFrame_hasTemporalInformation(const easyar_InputFrame * This);
double easyar_InputFrame_timestamp(const easyar_InputFrame * This);
bool easyar_InputFrame_hasSpatialInformation(const easyar_InputFrame * This);
easyar_Matrix44F easyar_InputFrame_cameraTransform(const easyar_InputFrame * This);
easyar_InputFrameTrackingStatus easyar_InputFrame_trackingStatus(const easyar_InputFrame * This);
void easyar_InputFrame_create(easyar_Image * image, easyar_CameraParameters * cameraParameters, double timestamp, easyar_Matrix44F cameraTransform, easyar_InputFrameTrackingStatus trackingStatus, /* OUT */ easyar_InputFrame * * Return);
void easyar_InputFrame_createWithImageAndCameraParametersAndTemporal(easyar_Image * image, easyar_CameraParameters * cameraParameters, double timestamp, /* OUT */ easyar_InputFrame * * Return);
void easyar_InputFrame_createWithImageAndCameraParameters(easyar_Image * image, easyar_CameraParameters * cameraParameters, /* OUT */ easyar_InputFrame * * Return);
void easyar_InputFrame_createWithImage(easyar_Image * image, /* OUT */ easyar_InputFrame * * Return);
void easyar_InputFrame__dtor(easyar_InputFrame * This);
void easyar_InputFrame__retain(const easyar_InputFrame * This, /* OUT */ easyar_InputFrame * * Return);
const char * easyar_InputFrame__typeName(const easyar_InputFrame * This);

void easyar_FrameFilterResult__dtor(easyar_FrameFilterResult * This);
void easyar_FrameFilterResult__retain(const easyar_FrameFilterResult * This, /* OUT */ easyar_FrameFilterResult * * Return);
const char * easyar_FrameFilterResult__typeName(const easyar_FrameFilterResult * This);

void easyar_OutputFrame__ctor(easyar_InputFrame * inputFrame, easyar_ListOfOptionalOfFrameFilterResult * results, /* OUT */ easyar_OutputFrame * * Return);
int easyar_OutputFrame_index(const easyar_OutputFrame * This);
void easyar_OutputFrame_inputFrame(const easyar_OutputFrame * This, /* OUT */ easyar_InputFrame * * Return);
void easyar_OutputFrame_results(const easyar_OutputFrame * This, /* OUT */ easyar_ListOfOptionalOfFrameFilterResult * * Return);
void easyar_OutputFrame__dtor(easyar_OutputFrame * This);
void easyar_OutputFrame__retain(const easyar_OutputFrame * This, /* OUT */ easyar_OutputFrame * * Return);
const char * easyar_OutputFrame__typeName(const easyar_OutputFrame * This);

void easyar_FeedbackFrame__ctor(easyar_InputFrame * inputFrame, easyar_OptionalOfOutputFrame previousOutputFrame, /* OUT */ easyar_FeedbackFrame * * Return);
void easyar_FeedbackFrame_inputFrame(const easyar_FeedbackFrame * This, /* OUT */ easyar_InputFrame * * Return);
void easyar_FeedbackFrame_previousOutputFrame(const easyar_FeedbackFrame * This, /* OUT */ easyar_OptionalOfOutputFrame * Return);
void easyar_FeedbackFrame__dtor(easyar_FeedbackFrame * This);
void easyar_FeedbackFrame__retain(const easyar_FeedbackFrame * This, /* OUT */ easyar_FeedbackFrame * * Return);
const char * easyar_FeedbackFrame__typeName(const easyar_FeedbackFrame * This);

void easyar_ListOfOptionalOfFrameFilterResult__ctor(easyar_OptionalOfFrameFilterResult const * begin, easyar_OptionalOfFrameFilterResult const * end, /* OUT */ easyar_ListOfOptionalOfFrameFilterResult * * Return);
void easyar_ListOfOptionalOfFrameFilterResult__dtor(easyar_ListOfOptionalOfFrameFilterResult * This);
void easyar_ListOfOptionalOfFrameFilterResult_copy(const easyar_ListOfOptionalOfFrameFilterResult * This, /* OUT */ easyar_ListOfOptionalOfFrameFilterResult * * Return);
int easyar_ListOfOptionalOfFrameFilterResult_size(const easyar_ListOfOptionalOfFrameFilterResult * This);
easyar_OptionalOfFrameFilterResult easyar_ListOfOptionalOfFrameFilterResult_at(const easyar_ListOfOptionalOfFrameFilterResult * This, int index);

#ifdef __cplusplus
}
#endif

#endif
