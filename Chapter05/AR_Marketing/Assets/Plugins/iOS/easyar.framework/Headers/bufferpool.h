//=============================================================================================================================
//
// EasyAR 3.0.1-final-r238a6316e
// Copyright (c) 2015-2019 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#ifndef __EASYAR_BUFFERPOOL_H__
#define __EASYAR_BUFFERPOOL_H__

#include "easyar/types.h"

#ifdef __cplusplus
extern "C" {
#endif

void easyar_BufferPool__ctor(int block_size, int capacity, /* OUT */ easyar_BufferPool * * Return);
int easyar_BufferPool_block_size(const easyar_BufferPool * This);
int easyar_BufferPool_capacity(const easyar_BufferPool * This);
int easyar_BufferPool_size(const easyar_BufferPool * This);
void easyar_BufferPool_tryAcquire(easyar_BufferPool * This, /* OUT */ easyar_OptionalOfBuffer * Return);
void easyar_BufferPool__dtor(easyar_BufferPool * This);
void easyar_BufferPool__retain(const easyar_BufferPool * This, /* OUT */ easyar_BufferPool * * Return);
const char * easyar_BufferPool__typeName(const easyar_BufferPool * This);

#ifdef __cplusplus
}
#endif

#endif
