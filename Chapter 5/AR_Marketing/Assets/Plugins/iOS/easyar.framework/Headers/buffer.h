//=============================================================================================================================
//
// EasyAR 3.0.1-final-r238a6316e
// Copyright (c) 2015-2019 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#ifndef __EASYAR_BUFFER_H__
#define __EASYAR_BUFFER_H__

#include "easyar/types.h"

#ifdef __cplusplus
extern "C" {
#endif

void easyar_Buffer_wrap(void * ptr, int size, easyar_FunctorOfVoid deleter, /* OUT */ easyar_Buffer * * Return);
void easyar_Buffer_create(int size, /* OUT */ easyar_Buffer * * Return);
void * easyar_Buffer_data(const easyar_Buffer * This);
int easyar_Buffer_size(const easyar_Buffer * This);
void easyar_Buffer_memoryCopy(void * src, void * dest, int length);
bool easyar_Buffer_tryCopyFrom(easyar_Buffer * This, void * src, int srcIndex, int index, int length);
bool easyar_Buffer_tryCopyTo(easyar_Buffer * This, int index, void * dest, int destIndex, int length);
void easyar_Buffer_partition(easyar_Buffer * This, int index, int length, /* OUT */ easyar_Buffer * * Return);
void easyar_Buffer__dtor(easyar_Buffer * This);
void easyar_Buffer__retain(const easyar_Buffer * This, /* OUT */ easyar_Buffer * * Return);
const char * easyar_Buffer__typeName(const easyar_Buffer * This);

void easyar_BufferDictionary__ctor(/* OUT */ easyar_BufferDictionary * * Return);
int easyar_BufferDictionary_count(const easyar_BufferDictionary * This);
bool easyar_BufferDictionary_contains(const easyar_BufferDictionary * This, easyar_String * path);
void easyar_BufferDictionary_tryGet(const easyar_BufferDictionary * This, easyar_String * path, /* OUT */ easyar_OptionalOfBuffer * Return);
void easyar_BufferDictionary_set(easyar_BufferDictionary * This, easyar_String * path, easyar_Buffer * buffer);
bool easyar_BufferDictionary_remove(easyar_BufferDictionary * This, easyar_String * path);
void easyar_BufferDictionary_clear(easyar_BufferDictionary * This);
void easyar_BufferDictionary__dtor(easyar_BufferDictionary * This);
void easyar_BufferDictionary__retain(const easyar_BufferDictionary * This, /* OUT */ easyar_BufferDictionary * * Return);
const char * easyar_BufferDictionary__typeName(const easyar_BufferDictionary * This);

#ifdef __cplusplus
}
#endif

#endif
