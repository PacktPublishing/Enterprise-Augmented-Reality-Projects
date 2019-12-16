//=============================================================================================================================
//
// EasyAR 3.0.1-final-r238a6316e
// Copyright (c) 2015-2019 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#ifndef __EASYAR_SPARSESPATIALMAP_HXX__
#define __EASYAR_SPARSESPATIALMAP_HXX__

#include "easyar/types.hxx"
#include "easyar/frame.hxx"

namespace easyar {

class SparseSpatialMapResult : public FrameFilterResult
{
protected:
    easyar_SparseSpatialMapResult * cdata_ ;
    void init_cdata(easyar_SparseSpatialMapResult * cdata);
    virtual SparseSpatialMapResult & operator=(const SparseSpatialMapResult & data) { return *this; } //deleted
public:
    SparseSpatialMapResult(easyar_SparseSpatialMapResult * cdata);
    virtual ~SparseSpatialMapResult();

    SparseSpatialMapResult(const SparseSpatialMapResult & data);
    const easyar_SparseSpatialMapResult * get_cdata() const;
    easyar_SparseSpatialMapResult * get_cdata();

    MapTrackingStatus getMapTrackingStatus();
    Matrix44F getVioPose();
    Matrix44F getMapPose();
    bool getLocalizedStatus();
    void getCurrentLocalizedMapID(/* OUT */ String * * Return);
    static void tryCastFromFrameFilterResult(FrameFilterResult * v, /* OUT */ SparseSpatialMapResult * * Return);
};

class PlaneData
{
protected:
    easyar_PlaneData * cdata_ ;
    void init_cdata(easyar_PlaneData * cdata);
    virtual PlaneData & operator=(const PlaneData & data) { return *this; } //deleted
public:
    PlaneData(easyar_PlaneData * cdata);
    virtual ~PlaneData();

    PlaneData(const PlaneData & data);
    const easyar_PlaneData * get_cdata() const;
    easyar_PlaneData * get_cdata();

    PlaneData();
    PlaneType getType();
    Matrix44F getPose();
    float getExtentX();
    float getExtentZ();
};

class SparseSpatialMapConfig
{
protected:
    easyar_SparseSpatialMapConfig * cdata_ ;
    void init_cdata(easyar_SparseSpatialMapConfig * cdata);
    virtual SparseSpatialMapConfig & operator=(const SparseSpatialMapConfig & data) { return *this; } //deleted
public:
    SparseSpatialMapConfig(easyar_SparseSpatialMapConfig * cdata);
    virtual ~SparseSpatialMapConfig();

    SparseSpatialMapConfig(const SparseSpatialMapConfig & data);
    const easyar_SparseSpatialMapConfig * get_cdata() const;
    easyar_SparseSpatialMapConfig * get_cdata();

    SparseSpatialMapConfig();
    void setLocalizeConfig(LocalizeConfig _value);
    LocalizeConfig getLocalizeConfig();
    void setMapConfig(MapConfig _value);
    MapConfig getMapConfig();
};

class SparseSpatialMap
{
protected:
    easyar_SparseSpatialMap * cdata_ ;
    void init_cdata(easyar_SparseSpatialMap * cdata);
    virtual SparseSpatialMap & operator=(const SparseSpatialMap & data) { return *this; } //deleted
public:
    SparseSpatialMap(easyar_SparseSpatialMap * cdata);
    virtual ~SparseSpatialMap();

    SparseSpatialMap(const SparseSpatialMap & data);
    const easyar_SparseSpatialMap * get_cdata() const;
    easyar_SparseSpatialMap * get_cdata();

    static bool isAvailable();
    void inputFrameSink(/* OUT */ InputFrameSink * * Return);
    void outputFrameSource(/* OUT */ OutputFrameSource * * Return);
    static void create(/* OUT */ SparseSpatialMap * * Return);
    bool start();
    void stop();
    void close();
    void getPointCloudBuffer(/* OUT */ Buffer * * Return);
    void getMapPlanes(/* OUT */ ListOfPlaneData * * Return);
    void hitTestAgainstPointCloud(Vec2F cameraImagePoint, /* OUT */ ListOfVec3F * * Return);
    void hitTestAgainstPlanes(Vec2F cameraImagePoint, /* OUT */ ListOfVec3F * * Return);
    bool saveMap(CallbackScheduler * callbackScheduler, FunctorOfVoidFromOptionalOfBuffer resultCallBack);
    bool loadMap(Buffer * pMapData, String * mapID, CallbackScheduler * callbackScheduler, OptionalOfFunctorOfVoidFromBool resultCallBack);
    bool unloadMap(String * mapID, CallbackScheduler * callbackScheduler, OptionalOfFunctorOfVoidFromBool resultCallBack);
    void setConfig(SparseSpatialMapConfig * config);
    void getConfig(/* OUT */ SparseSpatialMapConfig * * Return);
    bool startLocalize();
    bool stopLocalize();
};

#ifndef __EASYAR_LISTOFPLANEDATA__
#define __EASYAR_LISTOFPLANEDATA__
class ListOfPlaneData
{
private:
    easyar_ListOfPlaneData * cdata_;
    virtual ListOfPlaneData & operator=(const ListOfPlaneData & data) { return *this; } //deleted
public:
    ListOfPlaneData(easyar_ListOfPlaneData * cdata);
    virtual ~ListOfPlaneData();

    ListOfPlaneData(const ListOfPlaneData & data);
    const easyar_ListOfPlaneData * get_cdata() const;
    easyar_ListOfPlaneData * get_cdata();

    ListOfPlaneData(easyar_PlaneData * * begin, easyar_PlaneData * * end);
    int size() const;
    PlaneData * at(int index) const;
};
#endif

#ifndef __EASYAR_LISTOFVEC_F__
#define __EASYAR_LISTOFVEC_F__
class ListOfVec3F
{
private:
    easyar_ListOfVec3F * cdata_;
    virtual ListOfVec3F & operator=(const ListOfVec3F & data) { return *this; } //deleted
public:
    ListOfVec3F(easyar_ListOfVec3F * cdata);
    virtual ~ListOfVec3F();

    ListOfVec3F(const ListOfVec3F & data);
    const easyar_ListOfVec3F * get_cdata() const;
    easyar_ListOfVec3F * get_cdata();

    ListOfVec3F(easyar_Vec3F * begin, easyar_Vec3F * end);
    int size() const;
    Vec3F at(int index) const;
};
#endif

#ifndef __EASYAR_OPTIONALOFBUFFER__
#define __EASYAR_OPTIONALOFBUFFER__
struct OptionalOfBuffer
{
    bool has_value;
    Buffer * value;
};
static inline easyar_OptionalOfBuffer OptionalOfBuffer_to_c(Buffer * o);
#endif

#ifndef __EASYAR_FUNCTOROFVOIDFROMOPTIONALOFBUFFER__
#define __EASYAR_FUNCTOROFVOIDFROMOPTIONALOFBUFFER__
struct FunctorOfVoidFromOptionalOfBuffer
{
    void * _state;
    void (* func)(void * _state, Buffer *);
    void (* destroy)(void * _state);
    FunctorOfVoidFromOptionalOfBuffer(void * _state, void (* func)(void * _state, Buffer *), void (* destroy)(void * _state));
};

static void FunctorOfVoidFromOptionalOfBuffer_func(void * _state, easyar_OptionalOfBuffer, /* OUT */ easyar_String * * _exception);
static void FunctorOfVoidFromOptionalOfBuffer_destroy(void * _state);
static inline easyar_FunctorOfVoidFromOptionalOfBuffer FunctorOfVoidFromOptionalOfBuffer_to_c(FunctorOfVoidFromOptionalOfBuffer f);
#endif

#ifndef __EASYAR_FUNCTOROFVOIDFROMBOOL__
#define __EASYAR_FUNCTOROFVOIDFROMBOOL__
struct FunctorOfVoidFromBool
{
    void * _state;
    void (* func)(void * _state, bool);
    void (* destroy)(void * _state);
    FunctorOfVoidFromBool(void * _state, void (* func)(void * _state, bool), void (* destroy)(void * _state));
};

static void FunctorOfVoidFromBool_func(void * _state, bool, /* OUT */ easyar_String * * _exception);
static void FunctorOfVoidFromBool_destroy(void * _state);
static inline easyar_FunctorOfVoidFromBool FunctorOfVoidFromBool_to_c(FunctorOfVoidFromBool f);
#endif

#ifndef __EASYAR_OPTIONALOFFUNCTOROFVOIDFROMBOOL__
#define __EASYAR_OPTIONALOFFUNCTOROFVOIDFROMBOOL__
struct OptionalOfFunctorOfVoidFromBool
{
    bool has_value;
    FunctorOfVoidFromBool value;
};
static inline easyar_OptionalOfFunctorOfVoidFromBool OptionalOfFunctorOfVoidFromBool_to_c(OptionalOfFunctorOfVoidFromBool o);
#endif

}

#endif

#ifndef __IMPLEMENTATION_EASYAR_SPARSESPATIALMAP_HXX__
#define __IMPLEMENTATION_EASYAR_SPARSESPATIALMAP_HXX__

#include "easyar/sparsespatialmap.h"
#include "easyar/frame.hxx"
#include "easyar/matrix.hxx"
#include "easyar/dataflow.hxx"
#include "easyar/image.hxx"
#include "easyar/buffer.hxx"
#include "easyar/cameraparameters.hxx"
#include "easyar/vector.hxx"
#include "easyar/callbackscheduler.hxx"

namespace easyar {

inline SparseSpatialMapResult::SparseSpatialMapResult(easyar_SparseSpatialMapResult * cdata)
    :
    FrameFilterResult(static_cast<easyar_FrameFilterResult *>(NULL)),
    cdata_(NULL)
{
    init_cdata(cdata);
}
inline SparseSpatialMapResult::~SparseSpatialMapResult()
{
    if (cdata_) {
        easyar_SparseSpatialMapResult__dtor(cdata_);
        cdata_ = NULL;
    }
}

inline SparseSpatialMapResult::SparseSpatialMapResult(const SparseSpatialMapResult & data)
    :
    FrameFilterResult(static_cast<easyar_FrameFilterResult *>(NULL)),
    cdata_(NULL)
{
    easyar_SparseSpatialMapResult * cdata = NULL;
    easyar_SparseSpatialMapResult__retain(data.cdata_, &cdata);
    init_cdata(cdata);
}
inline const easyar_SparseSpatialMapResult * SparseSpatialMapResult::get_cdata() const
{
    return cdata_;
}
inline easyar_SparseSpatialMapResult * SparseSpatialMapResult::get_cdata()
{
    return cdata_;
}
inline void SparseSpatialMapResult::init_cdata(easyar_SparseSpatialMapResult * cdata)
{
    cdata_ = cdata;
    {
        easyar_FrameFilterResult * cdata_inner = NULL;
        easyar_castSparseSpatialMapResultToFrameFilterResult(cdata, &cdata_inner);
        FrameFilterResult::init_cdata(cdata_inner);
    }
}
inline MapTrackingStatus SparseSpatialMapResult::getMapTrackingStatus()
{
    if (cdata_ == NULL) {
        return MapTrackingStatus();
    }
    easyar_MapTrackingStatus _return_value_ = easyar_SparseSpatialMapResult_getMapTrackingStatus(cdata_);
    return static_cast<MapTrackingStatus>(_return_value_);
}
inline Matrix44F SparseSpatialMapResult::getVioPose()
{
    if (cdata_ == NULL) {
        return Matrix44F();
    }
    easyar_Matrix44F _return_value_ = easyar_SparseSpatialMapResult_getVioPose(cdata_);
    return Matrix44F(_return_value_.data[0], _return_value_.data[1], _return_value_.data[2], _return_value_.data[3], _return_value_.data[4], _return_value_.data[5], _return_value_.data[6], _return_value_.data[7], _return_value_.data[8], _return_value_.data[9], _return_value_.data[10], _return_value_.data[11], _return_value_.data[12], _return_value_.data[13], _return_value_.data[14], _return_value_.data[15]);
}
inline Matrix44F SparseSpatialMapResult::getMapPose()
{
    if (cdata_ == NULL) {
        return Matrix44F();
    }
    easyar_Matrix44F _return_value_ = easyar_SparseSpatialMapResult_getMapPose(cdata_);
    return Matrix44F(_return_value_.data[0], _return_value_.data[1], _return_value_.data[2], _return_value_.data[3], _return_value_.data[4], _return_value_.data[5], _return_value_.data[6], _return_value_.data[7], _return_value_.data[8], _return_value_.data[9], _return_value_.data[10], _return_value_.data[11], _return_value_.data[12], _return_value_.data[13], _return_value_.data[14], _return_value_.data[15]);
}
inline bool SparseSpatialMapResult::getLocalizedStatus()
{
    if (cdata_ == NULL) {
        return bool();
    }
    bool _return_value_ = easyar_SparseSpatialMapResult_getLocalizedStatus(cdata_);
    return _return_value_;
}
inline void SparseSpatialMapResult::getCurrentLocalizedMapID(/* OUT */ String * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_String * _return_value_ = NULL;
    easyar_SparseSpatialMapResult_getCurrentLocalizedMapID(cdata_, &_return_value_);
    *Return = new String(_return_value_);
}
inline void SparseSpatialMapResult::tryCastFromFrameFilterResult(FrameFilterResult * v, /* OUT */ SparseSpatialMapResult * * Return)
{
    if (v == NULL) {
        *Return = NULL;
        return;
    }
    easyar_SparseSpatialMapResult * cdata = NULL;
    easyar_tryCastFrameFilterResultToSparseSpatialMapResult(v->get_cdata(), &cdata);
    if (cdata == NULL) {
        *Return = NULL;
        return;
    }
    *Return = new SparseSpatialMapResult(cdata);
}

inline PlaneData::PlaneData(easyar_PlaneData * cdata)
    :
    cdata_(NULL)
{
    init_cdata(cdata);
}
inline PlaneData::~PlaneData()
{
    if (cdata_) {
        easyar_PlaneData__dtor(cdata_);
        cdata_ = NULL;
    }
}

inline PlaneData::PlaneData(const PlaneData & data)
    :
    cdata_(NULL)
{
    easyar_PlaneData * cdata = NULL;
    easyar_PlaneData__retain(data.cdata_, &cdata);
    init_cdata(cdata);
}
inline const easyar_PlaneData * PlaneData::get_cdata() const
{
    return cdata_;
}
inline easyar_PlaneData * PlaneData::get_cdata()
{
    return cdata_;
}
inline void PlaneData::init_cdata(easyar_PlaneData * cdata)
{
    cdata_ = cdata;
}
inline PlaneData::PlaneData()
    :
    cdata_(NULL)
{
    easyar_PlaneData * _return_value_ = NULL;
    easyar_PlaneData__ctor(&_return_value_);
    init_cdata(_return_value_);
}
inline PlaneType PlaneData::getType()
{
    if (cdata_ == NULL) {
        return PlaneType();
    }
    easyar_PlaneType _return_value_ = easyar_PlaneData_getType(cdata_);
    return static_cast<PlaneType>(_return_value_);
}
inline Matrix44F PlaneData::getPose()
{
    if (cdata_ == NULL) {
        return Matrix44F();
    }
    easyar_Matrix44F _return_value_ = easyar_PlaneData_getPose(cdata_);
    return Matrix44F(_return_value_.data[0], _return_value_.data[1], _return_value_.data[2], _return_value_.data[3], _return_value_.data[4], _return_value_.data[5], _return_value_.data[6], _return_value_.data[7], _return_value_.data[8], _return_value_.data[9], _return_value_.data[10], _return_value_.data[11], _return_value_.data[12], _return_value_.data[13], _return_value_.data[14], _return_value_.data[15]);
}
inline float PlaneData::getExtentX()
{
    if (cdata_ == NULL) {
        return float();
    }
    float _return_value_ = easyar_PlaneData_getExtentX(cdata_);
    return _return_value_;
}
inline float PlaneData::getExtentZ()
{
    if (cdata_ == NULL) {
        return float();
    }
    float _return_value_ = easyar_PlaneData_getExtentZ(cdata_);
    return _return_value_;
}

inline SparseSpatialMapConfig::SparseSpatialMapConfig(easyar_SparseSpatialMapConfig * cdata)
    :
    cdata_(NULL)
{
    init_cdata(cdata);
}
inline SparseSpatialMapConfig::~SparseSpatialMapConfig()
{
    if (cdata_) {
        easyar_SparseSpatialMapConfig__dtor(cdata_);
        cdata_ = NULL;
    }
}

inline SparseSpatialMapConfig::SparseSpatialMapConfig(const SparseSpatialMapConfig & data)
    :
    cdata_(NULL)
{
    easyar_SparseSpatialMapConfig * cdata = NULL;
    easyar_SparseSpatialMapConfig__retain(data.cdata_, &cdata);
    init_cdata(cdata);
}
inline const easyar_SparseSpatialMapConfig * SparseSpatialMapConfig::get_cdata() const
{
    return cdata_;
}
inline easyar_SparseSpatialMapConfig * SparseSpatialMapConfig::get_cdata()
{
    return cdata_;
}
inline void SparseSpatialMapConfig::init_cdata(easyar_SparseSpatialMapConfig * cdata)
{
    cdata_ = cdata;
}
inline SparseSpatialMapConfig::SparseSpatialMapConfig()
    :
    cdata_(NULL)
{
    easyar_SparseSpatialMapConfig * _return_value_ = NULL;
    easyar_SparseSpatialMapConfig__ctor(&_return_value_);
    init_cdata(_return_value_);
}
inline void SparseSpatialMapConfig::setLocalizeConfig(LocalizeConfig arg0)
{
    if (cdata_ == NULL) {
        return;
    }
    easyar_SparseSpatialMapConfig_setLocalizeConfig(cdata_, static_cast<easyar_LocalizeConfig>(arg0));
}
inline LocalizeConfig SparseSpatialMapConfig::getLocalizeConfig()
{
    if (cdata_ == NULL) {
        return LocalizeConfig();
    }
    easyar_LocalizeConfig _return_value_ = easyar_SparseSpatialMapConfig_getLocalizeConfig(cdata_);
    return static_cast<LocalizeConfig>(_return_value_);
}
inline void SparseSpatialMapConfig::setMapConfig(MapConfig arg0)
{
    if (cdata_ == NULL) {
        return;
    }
    easyar_SparseSpatialMapConfig_setMapConfig(cdata_, static_cast<easyar_MapConfig>(arg0));
}
inline MapConfig SparseSpatialMapConfig::getMapConfig()
{
    if (cdata_ == NULL) {
        return MapConfig();
    }
    easyar_MapConfig _return_value_ = easyar_SparseSpatialMapConfig_getMapConfig(cdata_);
    return static_cast<MapConfig>(_return_value_);
}

inline SparseSpatialMap::SparseSpatialMap(easyar_SparseSpatialMap * cdata)
    :
    cdata_(NULL)
{
    init_cdata(cdata);
}
inline SparseSpatialMap::~SparseSpatialMap()
{
    if (cdata_) {
        easyar_SparseSpatialMap__dtor(cdata_);
        cdata_ = NULL;
    }
}

inline SparseSpatialMap::SparseSpatialMap(const SparseSpatialMap & data)
    :
    cdata_(NULL)
{
    easyar_SparseSpatialMap * cdata = NULL;
    easyar_SparseSpatialMap__retain(data.cdata_, &cdata);
    init_cdata(cdata);
}
inline const easyar_SparseSpatialMap * SparseSpatialMap::get_cdata() const
{
    return cdata_;
}
inline easyar_SparseSpatialMap * SparseSpatialMap::get_cdata()
{
    return cdata_;
}
inline void SparseSpatialMap::init_cdata(easyar_SparseSpatialMap * cdata)
{
    cdata_ = cdata;
}
inline bool SparseSpatialMap::isAvailable()
{
    bool _return_value_ = easyar_SparseSpatialMap_isAvailable();
    return _return_value_;
}
inline void SparseSpatialMap::inputFrameSink(/* OUT */ InputFrameSink * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_InputFrameSink * _return_value_ = NULL;
    easyar_SparseSpatialMap_inputFrameSink(cdata_, &_return_value_);
    *Return = new InputFrameSink(_return_value_);
}
inline void SparseSpatialMap::outputFrameSource(/* OUT */ OutputFrameSource * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_OutputFrameSource * _return_value_ = NULL;
    easyar_SparseSpatialMap_outputFrameSource(cdata_, &_return_value_);
    *Return = new OutputFrameSource(_return_value_);
}
inline void SparseSpatialMap::create(/* OUT */ SparseSpatialMap * * Return)
{
    easyar_SparseSpatialMap * _return_value_ = NULL;
    easyar_SparseSpatialMap_create(&_return_value_);
    *Return = new SparseSpatialMap(_return_value_);
}
inline bool SparseSpatialMap::start()
{
    if (cdata_ == NULL) {
        return bool();
    }
    bool _return_value_ = easyar_SparseSpatialMap_start(cdata_);
    return _return_value_;
}
inline void SparseSpatialMap::stop()
{
    if (cdata_ == NULL) {
        return;
    }
    easyar_SparseSpatialMap_stop(cdata_);
}
inline void SparseSpatialMap::close()
{
    if (cdata_ == NULL) {
        return;
    }
    easyar_SparseSpatialMap_close(cdata_);
}
inline void SparseSpatialMap::getPointCloudBuffer(/* OUT */ Buffer * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_Buffer * _return_value_ = NULL;
    easyar_SparseSpatialMap_getPointCloudBuffer(cdata_, &_return_value_);
    *Return = new Buffer(_return_value_);
}
inline void SparseSpatialMap::getMapPlanes(/* OUT */ ListOfPlaneData * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_ListOfPlaneData * _return_value_ = NULL;
    easyar_SparseSpatialMap_getMapPlanes(cdata_, &_return_value_);
    *Return = new ListOfPlaneData(_return_value_);
}
inline void SparseSpatialMap::hitTestAgainstPointCloud(Vec2F arg0, /* OUT */ ListOfVec3F * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_ListOfVec3F * _return_value_ = NULL;
    easyar_SparseSpatialMap_hitTestAgainstPointCloud(cdata_, arg0.get_cdata(), &_return_value_);
    *Return = new ListOfVec3F(_return_value_);
}
inline void SparseSpatialMap::hitTestAgainstPlanes(Vec2F arg0, /* OUT */ ListOfVec3F * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_ListOfVec3F * _return_value_ = NULL;
    easyar_SparseSpatialMap_hitTestAgainstPlanes(cdata_, arg0.get_cdata(), &_return_value_);
    *Return = new ListOfVec3F(_return_value_);
}
inline bool SparseSpatialMap::saveMap(CallbackScheduler * arg0, FunctorOfVoidFromOptionalOfBuffer arg1)
{
    if (cdata_ == NULL) {
        return bool();
    }
    bool _return_value_ = easyar_SparseSpatialMap_saveMap(cdata_, arg0->get_cdata(), FunctorOfVoidFromOptionalOfBuffer_to_c(arg1));
    return _return_value_;
}
inline bool SparseSpatialMap::loadMap(Buffer * arg0, String * arg1, CallbackScheduler * arg2, OptionalOfFunctorOfVoidFromBool arg3)
{
    if (cdata_ == NULL) {
        return bool();
    }
    bool _return_value_ = easyar_SparseSpatialMap_loadMap(cdata_, arg0->get_cdata(), arg1->get_cdata(), arg2->get_cdata(), OptionalOfFunctorOfVoidFromBool_to_c(arg3));
    return _return_value_;
}
inline bool SparseSpatialMap::unloadMap(String * arg0, CallbackScheduler * arg1, OptionalOfFunctorOfVoidFromBool arg2)
{
    if (cdata_ == NULL) {
        return bool();
    }
    bool _return_value_ = easyar_SparseSpatialMap_unloadMap(cdata_, arg0->get_cdata(), arg1->get_cdata(), OptionalOfFunctorOfVoidFromBool_to_c(arg2));
    return _return_value_;
}
inline void SparseSpatialMap::setConfig(SparseSpatialMapConfig * arg0)
{
    if (cdata_ == NULL) {
        return;
    }
    easyar_SparseSpatialMap_setConfig(cdata_, arg0->get_cdata());
}
inline void SparseSpatialMap::getConfig(/* OUT */ SparseSpatialMapConfig * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_SparseSpatialMapConfig * _return_value_ = NULL;
    easyar_SparseSpatialMap_getConfig(cdata_, &_return_value_);
    *Return = new SparseSpatialMapConfig(_return_value_);
}
inline bool SparseSpatialMap::startLocalize()
{
    if (cdata_ == NULL) {
        return bool();
    }
    bool _return_value_ = easyar_SparseSpatialMap_startLocalize(cdata_);
    return _return_value_;
}
inline bool SparseSpatialMap::stopLocalize()
{
    if (cdata_ == NULL) {
        return bool();
    }
    bool _return_value_ = easyar_SparseSpatialMap_stopLocalize(cdata_);
    return _return_value_;
}

#ifndef __IMPLEMENTATION_EASYAR_LISTOFPLANEDATA__
#define __IMPLEMENTATION_EASYAR_LISTOFPLANEDATA__
inline ListOfPlaneData::ListOfPlaneData(easyar_ListOfPlaneData * cdata)
    : cdata_(cdata)
{
}
inline ListOfPlaneData::~ListOfPlaneData()
{
    if (cdata_) {
        easyar_ListOfPlaneData__dtor(cdata_);
        cdata_ = NULL;
    }
}

inline ListOfPlaneData::ListOfPlaneData(const ListOfPlaneData & data)
    : cdata_(static_cast<easyar_ListOfPlaneData *>(NULL))
{
    easyar_ListOfPlaneData_copy(data.cdata_, &cdata_);
}
inline const easyar_ListOfPlaneData * ListOfPlaneData::get_cdata() const
{
    return cdata_;
}
inline easyar_ListOfPlaneData * ListOfPlaneData::get_cdata()
{
    return cdata_;
}

inline ListOfPlaneData::ListOfPlaneData(easyar_PlaneData * * begin, easyar_PlaneData * * end)
    : cdata_(static_cast<easyar_ListOfPlaneData *>(NULL))
{
    easyar_ListOfPlaneData__ctor(begin, end, &cdata_);
}
inline int ListOfPlaneData::size() const
{
    return easyar_ListOfPlaneData_size(cdata_);
}
inline PlaneData * ListOfPlaneData::at(int index) const
{
    easyar_PlaneData * _return_value_ = easyar_ListOfPlaneData_at(cdata_, index);
    easyar_PlaneData__retain(_return_value_, &_return_value_);
    return new PlaneData(_return_value_);
}
#endif

#ifndef __IMPLEMENTATION_EASYAR_LISTOFVEC_F__
#define __IMPLEMENTATION_EASYAR_LISTOFVEC_F__
inline ListOfVec3F::ListOfVec3F(easyar_ListOfVec3F * cdata)
    : cdata_(cdata)
{
}
inline ListOfVec3F::~ListOfVec3F()
{
    if (cdata_) {
        easyar_ListOfVec3F__dtor(cdata_);
        cdata_ = NULL;
    }
}

inline ListOfVec3F::ListOfVec3F(const ListOfVec3F & data)
    : cdata_(static_cast<easyar_ListOfVec3F *>(NULL))
{
    easyar_ListOfVec3F_copy(data.cdata_, &cdata_);
}
inline const easyar_ListOfVec3F * ListOfVec3F::get_cdata() const
{
    return cdata_;
}
inline easyar_ListOfVec3F * ListOfVec3F::get_cdata()
{
    return cdata_;
}

inline ListOfVec3F::ListOfVec3F(easyar_Vec3F * begin, easyar_Vec3F * end)
    : cdata_(static_cast<easyar_ListOfVec3F *>(NULL))
{
    easyar_ListOfVec3F__ctor(begin, end, &cdata_);
}
inline int ListOfVec3F::size() const
{
    return easyar_ListOfVec3F_size(cdata_);
}
inline Vec3F ListOfVec3F::at(int index) const
{
    easyar_Vec3F _return_value_ = easyar_ListOfVec3F_at(cdata_, index);
    return Vec3F(_return_value_.data[0], _return_value_.data[1], _return_value_.data[2]);
}
#endif

#ifndef __IMPLEMENTATION_EASYAR_FUNCTOROFVOIDFROMOPTIONALOFBUFFER__
#define __IMPLEMENTATION_EASYAR_FUNCTOROFVOIDFROMOPTIONALOFBUFFER__
inline FunctorOfVoidFromOptionalOfBuffer::FunctorOfVoidFromOptionalOfBuffer(void * _state, void (* func)(void * _state, Buffer *), void (* destroy)(void * _state))
{
    this->_state = _state;
    this->func = func;
    this->destroy = destroy;
}
static void FunctorOfVoidFromOptionalOfBuffer_func(void * _state, easyar_OptionalOfBuffer arg0, /* OUT */ easyar_String * * _exception)
{
    *_exception = NULL;
    try {
        if (arg0.has_value) { easyar_Buffer__retain(arg0.value, &arg0.value); }
        Buffer * cpparg0 = (arg0.has_value ? new Buffer(arg0.value) : NULL);
        FunctorOfVoidFromOptionalOfBuffer * f = reinterpret_cast<FunctorOfVoidFromOptionalOfBuffer *>(_state);
        f->func(f->_state, cpparg0);
        delete cpparg0;
    } catch (std::exception & ex) {
        easyar_String_from_utf8_begin(ex.what(), _exception);
    }
}
static void FunctorOfVoidFromOptionalOfBuffer_destroy(void * _state)
{
    FunctorOfVoidFromOptionalOfBuffer * f = reinterpret_cast<FunctorOfVoidFromOptionalOfBuffer *>(_state);
    if (f->destroy) {
        f->destroy(f->_state);
    }
    delete f;
}
static inline easyar_FunctorOfVoidFromOptionalOfBuffer FunctorOfVoidFromOptionalOfBuffer_to_c(FunctorOfVoidFromOptionalOfBuffer f)
{
    easyar_FunctorOfVoidFromOptionalOfBuffer _return_value_ = {NULL, NULL, NULL};
    _return_value_._state = new FunctorOfVoidFromOptionalOfBuffer(f._state, f.func, f.destroy);
    _return_value_.func = FunctorOfVoidFromOptionalOfBuffer_func;
    _return_value_.destroy = FunctorOfVoidFromOptionalOfBuffer_destroy;
    return _return_value_;
}
#endif

#ifndef __IMPLEMENTATION_EASYAR_OPTIONALOFBUFFER__
#define __IMPLEMENTATION_EASYAR_OPTIONALOFBUFFER__
static inline easyar_OptionalOfBuffer OptionalOfBuffer_to_c(Buffer * o)
{
    if (o != NULL) {
        easyar_OptionalOfBuffer _return_value_ = {true, o->get_cdata()};
        return _return_value_;
    } else {
        easyar_OptionalOfBuffer _return_value_ = {false, NULL};
        return _return_value_;
    }
}
#endif

#ifndef __IMPLEMENTATION_EASYAR_OPTIONALOFFUNCTOROFVOIDFROMBOOL__
#define __IMPLEMENTATION_EASYAR_OPTIONALOFFUNCTOROFVOIDFROMBOOL__
static inline easyar_OptionalOfFunctorOfVoidFromBool OptionalOfFunctorOfVoidFromBool_to_c(OptionalOfFunctorOfVoidFromBool o)
{
    if (o.has_value) {
        easyar_OptionalOfFunctorOfVoidFromBool _return_value_ = {true, FunctorOfVoidFromBool_to_c(o.value)};
        return _return_value_;
    } else {
        easyar_OptionalOfFunctorOfVoidFromBool _return_value_ = {false, {NULL, NULL, NULL}};
        return _return_value_;
    }
}
#endif

#ifndef __IMPLEMENTATION_EASYAR_FUNCTOROFVOIDFROMBOOL__
#define __IMPLEMENTATION_EASYAR_FUNCTOROFVOIDFROMBOOL__
inline FunctorOfVoidFromBool::FunctorOfVoidFromBool(void * _state, void (* func)(void * _state, bool), void (* destroy)(void * _state))
{
    this->_state = _state;
    this->func = func;
    this->destroy = destroy;
}
static void FunctorOfVoidFromBool_func(void * _state, bool arg0, /* OUT */ easyar_String * * _exception)
{
    *_exception = NULL;
    try {
        bool cpparg0 = arg0;
        FunctorOfVoidFromBool * f = reinterpret_cast<FunctorOfVoidFromBool *>(_state);
        f->func(f->_state, cpparg0);
    } catch (std::exception & ex) {
        easyar_String_from_utf8_begin(ex.what(), _exception);
    }
}
static void FunctorOfVoidFromBool_destroy(void * _state)
{
    FunctorOfVoidFromBool * f = reinterpret_cast<FunctorOfVoidFromBool *>(_state);
    if (f->destroy) {
        f->destroy(f->_state);
    }
    delete f;
}
static inline easyar_FunctorOfVoidFromBool FunctorOfVoidFromBool_to_c(FunctorOfVoidFromBool f)
{
    easyar_FunctorOfVoidFromBool _return_value_ = {NULL, NULL, NULL};
    _return_value_._state = new FunctorOfVoidFromBool(f._state, f.func, f.destroy);
    _return_value_.func = FunctorOfVoidFromBool_func;
    _return_value_.destroy = FunctorOfVoidFromBool_destroy;
    return _return_value_;
}
#endif

}

#endif
