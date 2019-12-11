//=============================================================================================================================
//
// EasyAR 3.0.1-final-r238a6316e
// Copyright (c) 2015-2019 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#ifndef __EASYAR_SPARSESPATIALMAP_H__
#define __EASYAR_SPARSESPATIALMAP_H__

#include "easyar/types.h"

#ifdef __cplusplus
extern "C" {
#endif

easyar_MapTrackingStatus easyar_SparseSpatialMapResult_getMapTrackingStatus(const easyar_SparseSpatialMapResult * This);
easyar_Matrix44F easyar_SparseSpatialMapResult_getVioPose(const easyar_SparseSpatialMapResult * This);
easyar_Matrix44F easyar_SparseSpatialMapResult_getMapPose(const easyar_SparseSpatialMapResult * This);
bool easyar_SparseSpatialMapResult_getLocalizedStatus(const easyar_SparseSpatialMapResult * This);
void easyar_SparseSpatialMapResult_getCurrentLocalizedMapID(const easyar_SparseSpatialMapResult * This, /* OUT */ easyar_String * * Return);
void easyar_SparseSpatialMapResult__dtor(easyar_SparseSpatialMapResult * This);
void easyar_SparseSpatialMapResult__retain(const easyar_SparseSpatialMapResult * This, /* OUT */ easyar_SparseSpatialMapResult * * Return);
const char * easyar_SparseSpatialMapResult__typeName(const easyar_SparseSpatialMapResult * This);
void easyar_castSparseSpatialMapResultToFrameFilterResult(const easyar_SparseSpatialMapResult * This, /* OUT */ easyar_FrameFilterResult * * Return);
void easyar_tryCastFrameFilterResultToSparseSpatialMapResult(const easyar_FrameFilterResult * This, /* OUT */ easyar_SparseSpatialMapResult * * Return);

void easyar_PlaneData__ctor(/* OUT */ easyar_PlaneData * * Return);
easyar_PlaneType easyar_PlaneData_getType(const easyar_PlaneData * This);
easyar_Matrix44F easyar_PlaneData_getPose(const easyar_PlaneData * This);
float easyar_PlaneData_getExtentX(const easyar_PlaneData * This);
float easyar_PlaneData_getExtentZ(const easyar_PlaneData * This);
void easyar_PlaneData__dtor(easyar_PlaneData * This);
void easyar_PlaneData__retain(const easyar_PlaneData * This, /* OUT */ easyar_PlaneData * * Return);
const char * easyar_PlaneData__typeName(const easyar_PlaneData * This);

void easyar_SparseSpatialMapConfig__ctor(/* OUT */ easyar_SparseSpatialMapConfig * * Return);
void easyar_SparseSpatialMapConfig_setLocalizeConfig(easyar_SparseSpatialMapConfig * This, easyar_LocalizeConfig _value);
easyar_LocalizeConfig easyar_SparseSpatialMapConfig_getLocalizeConfig(const easyar_SparseSpatialMapConfig * This);
void easyar_SparseSpatialMapConfig_setMapConfig(easyar_SparseSpatialMapConfig * This, easyar_MapConfig _value);
easyar_MapConfig easyar_SparseSpatialMapConfig_getMapConfig(const easyar_SparseSpatialMapConfig * This);
void easyar_SparseSpatialMapConfig__dtor(easyar_SparseSpatialMapConfig * This);
void easyar_SparseSpatialMapConfig__retain(const easyar_SparseSpatialMapConfig * This, /* OUT */ easyar_SparseSpatialMapConfig * * Return);
const char * easyar_SparseSpatialMapConfig__typeName(const easyar_SparseSpatialMapConfig * This);

bool easyar_SparseSpatialMap_isAvailable();
void easyar_SparseSpatialMap_inputFrameSink(easyar_SparseSpatialMap * This, /* OUT */ easyar_InputFrameSink * * Return);
void easyar_SparseSpatialMap_outputFrameSource(easyar_SparseSpatialMap * This, /* OUT */ easyar_OutputFrameSource * * Return);
void easyar_SparseSpatialMap_create(/* OUT */ easyar_SparseSpatialMap * * Return);
bool easyar_SparseSpatialMap_start(easyar_SparseSpatialMap * This);
void easyar_SparseSpatialMap_stop(easyar_SparseSpatialMap * This);
void easyar_SparseSpatialMap_close(easyar_SparseSpatialMap * This);
void easyar_SparseSpatialMap_getPointCloudBuffer(easyar_SparseSpatialMap * This, /* OUT */ easyar_Buffer * * Return);
void easyar_SparseSpatialMap_getMapPlanes(easyar_SparseSpatialMap * This, /* OUT */ easyar_ListOfPlaneData * * Return);
void easyar_SparseSpatialMap_hitTestAgainstPointCloud(easyar_SparseSpatialMap * This, easyar_Vec2F cameraImagePoint, /* OUT */ easyar_ListOfVec3F * * Return);
void easyar_SparseSpatialMap_hitTestAgainstPlanes(easyar_SparseSpatialMap * This, easyar_Vec2F cameraImagePoint, /* OUT */ easyar_ListOfVec3F * * Return);
bool easyar_SparseSpatialMap_saveMap(easyar_SparseSpatialMap * This, easyar_CallbackScheduler * callbackScheduler, easyar_FunctorOfVoidFromOptionalOfBuffer resultCallBack);
bool easyar_SparseSpatialMap_loadMap(easyar_SparseSpatialMap * This, easyar_Buffer * pMapData, easyar_String * mapID, easyar_CallbackScheduler * callbackScheduler, easyar_OptionalOfFunctorOfVoidFromBool resultCallBack);
bool easyar_SparseSpatialMap_unloadMap(easyar_SparseSpatialMap * This, easyar_String * mapID, easyar_CallbackScheduler * callbackScheduler, easyar_OptionalOfFunctorOfVoidFromBool resultCallBack);
void easyar_SparseSpatialMap_setConfig(easyar_SparseSpatialMap * This, easyar_SparseSpatialMapConfig * config);
void easyar_SparseSpatialMap_getConfig(easyar_SparseSpatialMap * This, /* OUT */ easyar_SparseSpatialMapConfig * * Return);
bool easyar_SparseSpatialMap_startLocalize(easyar_SparseSpatialMap * This);
bool easyar_SparseSpatialMap_stopLocalize(easyar_SparseSpatialMap * This);
void easyar_SparseSpatialMap__dtor(easyar_SparseSpatialMap * This);
void easyar_SparseSpatialMap__retain(const easyar_SparseSpatialMap * This, /* OUT */ easyar_SparseSpatialMap * * Return);
const char * easyar_SparseSpatialMap__typeName(const easyar_SparseSpatialMap * This);

void easyar_ListOfPlaneData__ctor(easyar_PlaneData * const * begin, easyar_PlaneData * const * end, /* OUT */ easyar_ListOfPlaneData * * Return);
void easyar_ListOfPlaneData__dtor(easyar_ListOfPlaneData * This);
void easyar_ListOfPlaneData_copy(const easyar_ListOfPlaneData * This, /* OUT */ easyar_ListOfPlaneData * * Return);
int easyar_ListOfPlaneData_size(const easyar_ListOfPlaneData * This);
easyar_PlaneData * easyar_ListOfPlaneData_at(const easyar_ListOfPlaneData * This, int index);

void easyar_ListOfVec3F__ctor(easyar_Vec3F const * begin, easyar_Vec3F const * end, /* OUT */ easyar_ListOfVec3F * * Return);
void easyar_ListOfVec3F__dtor(easyar_ListOfVec3F * This);
void easyar_ListOfVec3F_copy(const easyar_ListOfVec3F * This, /* OUT */ easyar_ListOfVec3F * * Return);
int easyar_ListOfVec3F_size(const easyar_ListOfVec3F * This);
easyar_Vec3F easyar_ListOfVec3F_at(const easyar_ListOfVec3F * This, int index);

#ifdef __cplusplus
}
#endif

#endif
