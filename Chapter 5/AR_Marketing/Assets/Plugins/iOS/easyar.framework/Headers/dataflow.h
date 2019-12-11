//=============================================================================================================================
//
// EasyAR 3.0.1-final-r238a6316e
// Copyright (c) 2015-2019 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#ifndef __EASYAR_DATAFLOW_H__
#define __EASYAR_DATAFLOW_H__

#include "easyar/types.h"

#ifdef __cplusplus
extern "C" {
#endif

void easyar_SignalSink_handle(easyar_SignalSink * This);
void easyar_SignalSink__dtor(easyar_SignalSink * This);
void easyar_SignalSink__retain(const easyar_SignalSink * This, /* OUT */ easyar_SignalSink * * Return);
const char * easyar_SignalSink__typeName(const easyar_SignalSink * This);

void easyar_SignalSource_setHandler(easyar_SignalSource * This, easyar_OptionalOfFunctorOfVoid handler);
void easyar_SignalSource_connect(easyar_SignalSource * This, easyar_SignalSink * sink);
void easyar_SignalSource_disconnect(easyar_SignalSource * This);
void easyar_SignalSource__dtor(easyar_SignalSource * This);
void easyar_SignalSource__retain(const easyar_SignalSource * This, /* OUT */ easyar_SignalSource * * Return);
const char * easyar_SignalSource__typeName(const easyar_SignalSource * This);

void easyar_InputFrameSink_handle(easyar_InputFrameSink * This, easyar_InputFrame * inputData);
void easyar_InputFrameSink__dtor(easyar_InputFrameSink * This);
void easyar_InputFrameSink__retain(const easyar_InputFrameSink * This, /* OUT */ easyar_InputFrameSink * * Return);
const char * easyar_InputFrameSink__typeName(const easyar_InputFrameSink * This);

void easyar_InputFrameSource_setHandler(easyar_InputFrameSource * This, easyar_OptionalOfFunctorOfVoidFromInputFrame handler);
void easyar_InputFrameSource_connect(easyar_InputFrameSource * This, easyar_InputFrameSink * sink);
void easyar_InputFrameSource_disconnect(easyar_InputFrameSource * This);
void easyar_InputFrameSource__dtor(easyar_InputFrameSource * This);
void easyar_InputFrameSource__retain(const easyar_InputFrameSource * This, /* OUT */ easyar_InputFrameSource * * Return);
const char * easyar_InputFrameSource__typeName(const easyar_InputFrameSource * This);

void easyar_OutputFrameSink_handle(easyar_OutputFrameSink * This, easyar_OutputFrame * inputData);
void easyar_OutputFrameSink__dtor(easyar_OutputFrameSink * This);
void easyar_OutputFrameSink__retain(const easyar_OutputFrameSink * This, /* OUT */ easyar_OutputFrameSink * * Return);
const char * easyar_OutputFrameSink__typeName(const easyar_OutputFrameSink * This);

void easyar_OutputFrameSource_setHandler(easyar_OutputFrameSource * This, easyar_OptionalOfFunctorOfVoidFromOutputFrame handler);
void easyar_OutputFrameSource_connect(easyar_OutputFrameSource * This, easyar_OutputFrameSink * sink);
void easyar_OutputFrameSource_disconnect(easyar_OutputFrameSource * This);
void easyar_OutputFrameSource__dtor(easyar_OutputFrameSource * This);
void easyar_OutputFrameSource__retain(const easyar_OutputFrameSource * This, /* OUT */ easyar_OutputFrameSource * * Return);
const char * easyar_OutputFrameSource__typeName(const easyar_OutputFrameSource * This);

void easyar_FeedbackFrameSink_handle(easyar_FeedbackFrameSink * This, easyar_FeedbackFrame * inputData);
void easyar_FeedbackFrameSink__dtor(easyar_FeedbackFrameSink * This);
void easyar_FeedbackFrameSink__retain(const easyar_FeedbackFrameSink * This, /* OUT */ easyar_FeedbackFrameSink * * Return);
const char * easyar_FeedbackFrameSink__typeName(const easyar_FeedbackFrameSink * This);

void easyar_FeedbackFrameSource_setHandler(easyar_FeedbackFrameSource * This, easyar_OptionalOfFunctorOfVoidFromFeedbackFrame handler);
void easyar_FeedbackFrameSource_connect(easyar_FeedbackFrameSource * This, easyar_FeedbackFrameSink * sink);
void easyar_FeedbackFrameSource_disconnect(easyar_FeedbackFrameSource * This);
void easyar_FeedbackFrameSource__dtor(easyar_FeedbackFrameSource * This);
void easyar_FeedbackFrameSource__retain(const easyar_FeedbackFrameSource * This, /* OUT */ easyar_FeedbackFrameSource * * Return);
const char * easyar_FeedbackFrameSource__typeName(const easyar_FeedbackFrameSource * This);

void easyar_InputFrameFork_input(easyar_InputFrameFork * This, /* OUT */ easyar_InputFrameSink * * Return);
void easyar_InputFrameFork_output(easyar_InputFrameFork * This, int index, /* OUT */ easyar_InputFrameSource * * Return);
int easyar_InputFrameFork_outputCount(easyar_InputFrameFork * This);
void easyar_InputFrameFork_create(int outputCount, /* OUT */ easyar_InputFrameFork * * Return);
void easyar_InputFrameFork__dtor(easyar_InputFrameFork * This);
void easyar_InputFrameFork__retain(const easyar_InputFrameFork * This, /* OUT */ easyar_InputFrameFork * * Return);
const char * easyar_InputFrameFork__typeName(const easyar_InputFrameFork * This);

void easyar_OutputFrameFork_input(easyar_OutputFrameFork * This, /* OUT */ easyar_OutputFrameSink * * Return);
void easyar_OutputFrameFork_output(easyar_OutputFrameFork * This, int index, /* OUT */ easyar_OutputFrameSource * * Return);
int easyar_OutputFrameFork_outputCount(easyar_OutputFrameFork * This);
void easyar_OutputFrameFork_create(int outputCount, /* OUT */ easyar_OutputFrameFork * * Return);
void easyar_OutputFrameFork__dtor(easyar_OutputFrameFork * This);
void easyar_OutputFrameFork__retain(const easyar_OutputFrameFork * This, /* OUT */ easyar_OutputFrameFork * * Return);
const char * easyar_OutputFrameFork__typeName(const easyar_OutputFrameFork * This);

void easyar_OutputFrameJoin_input(easyar_OutputFrameJoin * This, int index, /* OUT */ easyar_OutputFrameSink * * Return);
void easyar_OutputFrameJoin_output(easyar_OutputFrameJoin * This, /* OUT */ easyar_OutputFrameSource * * Return);
int easyar_OutputFrameJoin_inputCount(easyar_OutputFrameJoin * This);
void easyar_OutputFrameJoin_create(int inputCount, /* OUT */ easyar_OutputFrameJoin * * Return);
void easyar_OutputFrameJoin_createWithJoiner(int inputCount, easyar_FunctorOfOutputFrameFromListOfOutputFrame joiner, /* OUT */ easyar_OutputFrameJoin * * Return);
void easyar_OutputFrameJoin__dtor(easyar_OutputFrameJoin * This);
void easyar_OutputFrameJoin__retain(const easyar_OutputFrameJoin * This, /* OUT */ easyar_OutputFrameJoin * * Return);
const char * easyar_OutputFrameJoin__typeName(const easyar_OutputFrameJoin * This);

void easyar_FeedbackFrameFork_input(easyar_FeedbackFrameFork * This, /* OUT */ easyar_FeedbackFrameSink * * Return);
void easyar_FeedbackFrameFork_output(easyar_FeedbackFrameFork * This, int index, /* OUT */ easyar_FeedbackFrameSource * * Return);
int easyar_FeedbackFrameFork_outputCount(easyar_FeedbackFrameFork * This);
void easyar_FeedbackFrameFork_create(int outputCount, /* OUT */ easyar_FeedbackFrameFork * * Return);
void easyar_FeedbackFrameFork__dtor(easyar_FeedbackFrameFork * This);
void easyar_FeedbackFrameFork__retain(const easyar_FeedbackFrameFork * This, /* OUT */ easyar_FeedbackFrameFork * * Return);
const char * easyar_FeedbackFrameFork__typeName(const easyar_FeedbackFrameFork * This);

void easyar_InputFrameThrottler_input(easyar_InputFrameThrottler * This, /* OUT */ easyar_InputFrameSink * * Return);
void easyar_InputFrameThrottler_output(easyar_InputFrameThrottler * This, /* OUT */ easyar_InputFrameSource * * Return);
void easyar_InputFrameThrottler_signalInput(easyar_InputFrameThrottler * This, /* OUT */ easyar_SignalSink * * Return);
void easyar_InputFrameThrottler_create(/* OUT */ easyar_InputFrameThrottler * * Return);
void easyar_InputFrameThrottler__dtor(easyar_InputFrameThrottler * This);
void easyar_InputFrameThrottler__retain(const easyar_InputFrameThrottler * This, /* OUT */ easyar_InputFrameThrottler * * Return);
const char * easyar_InputFrameThrottler__typeName(const easyar_InputFrameThrottler * This);

void easyar_OutputFrameBuffer_input(easyar_OutputFrameBuffer * This, /* OUT */ easyar_OutputFrameSink * * Return);
void easyar_OutputFrameBuffer_signalOutput(easyar_OutputFrameBuffer * This, /* OUT */ easyar_SignalSource * * Return);
void easyar_OutputFrameBuffer_peek(easyar_OutputFrameBuffer * This, /* OUT */ easyar_OptionalOfOutputFrame * Return);
void easyar_OutputFrameBuffer_create(/* OUT */ easyar_OutputFrameBuffer * * Return);
void easyar_OutputFrameBuffer__dtor(easyar_OutputFrameBuffer * This);
void easyar_OutputFrameBuffer__retain(const easyar_OutputFrameBuffer * This, /* OUT */ easyar_OutputFrameBuffer * * Return);
const char * easyar_OutputFrameBuffer__typeName(const easyar_OutputFrameBuffer * This);

void easyar_InputFrameToOutputFrameAdapter_input(easyar_InputFrameToOutputFrameAdapter * This, /* OUT */ easyar_InputFrameSink * * Return);
void easyar_InputFrameToOutputFrameAdapter_output(easyar_InputFrameToOutputFrameAdapter * This, /* OUT */ easyar_OutputFrameSource * * Return);
void easyar_InputFrameToOutputFrameAdapter_create(/* OUT */ easyar_InputFrameToOutputFrameAdapter * * Return);
void easyar_InputFrameToOutputFrameAdapter__dtor(easyar_InputFrameToOutputFrameAdapter * This);
void easyar_InputFrameToOutputFrameAdapter__retain(const easyar_InputFrameToOutputFrameAdapter * This, /* OUT */ easyar_InputFrameToOutputFrameAdapter * * Return);
const char * easyar_InputFrameToOutputFrameAdapter__typeName(const easyar_InputFrameToOutputFrameAdapter * This);

void easyar_InputFrameToFeedbackFrameAdapter_input(easyar_InputFrameToFeedbackFrameAdapter * This, /* OUT */ easyar_InputFrameSink * * Return);
void easyar_InputFrameToFeedbackFrameAdapter_sideInput(easyar_InputFrameToFeedbackFrameAdapter * This, /* OUT */ easyar_OutputFrameSink * * Return);
void easyar_InputFrameToFeedbackFrameAdapter_output(easyar_InputFrameToFeedbackFrameAdapter * This, /* OUT */ easyar_FeedbackFrameSource * * Return);
void easyar_InputFrameToFeedbackFrameAdapter_create(/* OUT */ easyar_InputFrameToFeedbackFrameAdapter * * Return);
void easyar_InputFrameToFeedbackFrameAdapter__dtor(easyar_InputFrameToFeedbackFrameAdapter * This);
void easyar_InputFrameToFeedbackFrameAdapter__retain(const easyar_InputFrameToFeedbackFrameAdapter * This, /* OUT */ easyar_InputFrameToFeedbackFrameAdapter * * Return);
const char * easyar_InputFrameToFeedbackFrameAdapter__typeName(const easyar_InputFrameToFeedbackFrameAdapter * This);

void easyar_ListOfOutputFrame__ctor(easyar_OutputFrame * const * begin, easyar_OutputFrame * const * end, /* OUT */ easyar_ListOfOutputFrame * * Return);
void easyar_ListOfOutputFrame__dtor(easyar_ListOfOutputFrame * This);
void easyar_ListOfOutputFrame_copy(const easyar_ListOfOutputFrame * This, /* OUT */ easyar_ListOfOutputFrame * * Return);
int easyar_ListOfOutputFrame_size(const easyar_ListOfOutputFrame * This);
easyar_OutputFrame * easyar_ListOfOutputFrame_at(const easyar_ListOfOutputFrame * This, int index);

#ifdef __cplusplus
}
#endif

#endif
