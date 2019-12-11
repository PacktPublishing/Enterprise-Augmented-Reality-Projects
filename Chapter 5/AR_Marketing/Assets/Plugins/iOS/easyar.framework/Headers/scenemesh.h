//=============================================================================================================================
//
// EasyAR 3.0.1-final-r238a6316e
// Copyright (c) 2015-2019 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#ifndef __EASYAR_SCENEMESH_H__
#define __EASYAR_SCENEMESH_H__

#include "easyar/types.h"

#ifdef __cplusplus
extern "C" {
#endif

void easyar_SceneMesh__ctor(/* OUT */ easyar_SceneMesh * * Return);
int easyar_SceneMesh_getNumOfVertexAll(easyar_SceneMesh * This);
int easyar_SceneMesh_getNumOfIndexAll(easyar_SceneMesh * This);
void easyar_SceneMesh_getVerticesAll(easyar_SceneMesh * This, /* OUT */ easyar_Buffer * * Return);
void easyar_SceneMesh_getNormalsAll(easyar_SceneMesh * This, /* OUT */ easyar_Buffer * * Return);
void easyar_SceneMesh_getIndicesAll(easyar_SceneMesh * This, /* OUT */ easyar_Buffer * * Return);
int easyar_SceneMesh_getNumOfVertexIncremental(easyar_SceneMesh * This);
int easyar_SceneMesh_getNumOfIndexIncremental(easyar_SceneMesh * This);
void easyar_SceneMesh_getVerticesIncremental(easyar_SceneMesh * This, /* OUT */ easyar_Buffer * * Return);
void easyar_SceneMesh_getNormalsIncremental(easyar_SceneMesh * This, /* OUT */ easyar_Buffer * * Return);
void easyar_SceneMesh_getIndicesIncremental(easyar_SceneMesh * This, /* OUT */ easyar_Buffer * * Return);
void easyar_SceneMesh_getBlocksInfoIncremental(easyar_SceneMesh * This, /* OUT */ easyar_ListOfBlockInfo * * Return);
float easyar_SceneMesh_getBlockDimentionInMeters(easyar_SceneMesh * This);
void easyar_SceneMesh__dtor(easyar_SceneMesh * This);
void easyar_SceneMesh__retain(const easyar_SceneMesh * This, /* OUT */ easyar_SceneMesh * * Return);
const char * easyar_SceneMesh__typeName(const easyar_SceneMesh * This);

void easyar_ListOfBlockInfo__ctor(easyar_BlockInfo const * begin, easyar_BlockInfo const * end, /* OUT */ easyar_ListOfBlockInfo * * Return);
void easyar_ListOfBlockInfo__dtor(easyar_ListOfBlockInfo * This);
void easyar_ListOfBlockInfo_copy(const easyar_ListOfBlockInfo * This, /* OUT */ easyar_ListOfBlockInfo * * Return);
int easyar_ListOfBlockInfo_size(const easyar_ListOfBlockInfo * This);
easyar_BlockInfo easyar_ListOfBlockInfo_at(const easyar_ListOfBlockInfo * This, int index);

#ifdef __cplusplus
}
#endif

#endif
