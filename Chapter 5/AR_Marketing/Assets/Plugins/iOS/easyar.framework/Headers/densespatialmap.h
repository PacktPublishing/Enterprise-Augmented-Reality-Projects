//=============================================================================================================================
//
// EasyAR 3.0.1-final-r238a6316e
// Copyright (c) 2015-2019 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#ifndef __EASYAR_DENSESPATIALMAP_H__
#define __EASYAR_DENSESPATIALMAP_H__

#include "easyar/types.h"

#ifdef __cplusplus
extern "C" {
#endif

bool easyar_DenseSpatialMap_isAvailable();
void easyar_DenseSpatialMap_inputFrameSink(easyar_DenseSpatialMap * This, /* OUT */ easyar_InputFrameSink * * Return);
void easyar_DenseSpatialMap_create(/* OUT */ easyar_DenseSpatialMap * * Return);
bool easyar_DenseSpatialMap_start(easyar_DenseSpatialMap * This);
void easyar_DenseSpatialMap_stop(easyar_DenseSpatialMap * This);
void easyar_DenseSpatialMap_close(easyar_DenseSpatialMap * This);
void easyar_DenseSpatialMap_saveMap(easyar_DenseSpatialMap * This, /* OUT */ easyar_String * * Return);
void easyar_DenseSpatialMap_getMesh(easyar_DenseSpatialMap * This, /* OUT */ easyar_SceneMesh * * Return);
bool easyar_DenseSpatialMap_updateSceneMesh(easyar_DenseSpatialMap * This, bool updateMeshAll);
void easyar_DenseSpatialMap__dtor(easyar_DenseSpatialMap * This);
void easyar_DenseSpatialMap__retain(const easyar_DenseSpatialMap * This, /* OUT */ easyar_DenseSpatialMap * * Return);
const char * easyar_DenseSpatialMap__typeName(const easyar_DenseSpatialMap * This);

#ifdef __cplusplus
}
#endif

#endif
