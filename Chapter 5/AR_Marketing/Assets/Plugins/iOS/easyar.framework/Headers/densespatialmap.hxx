//=============================================================================================================================
//
// EasyAR 3.0.1-final-r238a6316e
// Copyright (c) 2015-2019 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#ifndef __EASYAR_DENSESPATIALMAP_HXX__
#define __EASYAR_DENSESPATIALMAP_HXX__

#include "easyar/types.hxx"

namespace easyar {

class DenseSpatialMap
{
protected:
    easyar_DenseSpatialMap * cdata_ ;
    void init_cdata(easyar_DenseSpatialMap * cdata);
    virtual DenseSpatialMap & operator=(const DenseSpatialMap & data) { return *this; } //deleted
public:
    DenseSpatialMap(easyar_DenseSpatialMap * cdata);
    virtual ~DenseSpatialMap();

    DenseSpatialMap(const DenseSpatialMap & data);
    const easyar_DenseSpatialMap * get_cdata() const;
    easyar_DenseSpatialMap * get_cdata();

    static bool isAvailable();
    void inputFrameSink(/* OUT */ InputFrameSink * * Return);
    static void create(/* OUT */ DenseSpatialMap * * Return);
    bool start();
    void stop();
    void close();
    void saveMap(/* OUT */ String * * Return);
    void getMesh(/* OUT */ SceneMesh * * Return);
    bool updateSceneMesh(bool updateMeshAll);
};

}

#endif

#ifndef __IMPLEMENTATION_EASYAR_DENSESPATIALMAP_HXX__
#define __IMPLEMENTATION_EASYAR_DENSESPATIALMAP_HXX__

#include "easyar/densespatialmap.h"
#include "easyar/dataflow.hxx"
#include "easyar/frame.hxx"
#include "easyar/image.hxx"
#include "easyar/buffer.hxx"
#include "easyar/cameraparameters.hxx"
#include "easyar/vector.hxx"
#include "easyar/matrix.hxx"
#include "easyar/scenemesh.hxx"

namespace easyar {

inline DenseSpatialMap::DenseSpatialMap(easyar_DenseSpatialMap * cdata)
    :
    cdata_(NULL)
{
    init_cdata(cdata);
}
inline DenseSpatialMap::~DenseSpatialMap()
{
    if (cdata_) {
        easyar_DenseSpatialMap__dtor(cdata_);
        cdata_ = NULL;
    }
}

inline DenseSpatialMap::DenseSpatialMap(const DenseSpatialMap & data)
    :
    cdata_(NULL)
{
    easyar_DenseSpatialMap * cdata = NULL;
    easyar_DenseSpatialMap__retain(data.cdata_, &cdata);
    init_cdata(cdata);
}
inline const easyar_DenseSpatialMap * DenseSpatialMap::get_cdata() const
{
    return cdata_;
}
inline easyar_DenseSpatialMap * DenseSpatialMap::get_cdata()
{
    return cdata_;
}
inline void DenseSpatialMap::init_cdata(easyar_DenseSpatialMap * cdata)
{
    cdata_ = cdata;
}
inline bool DenseSpatialMap::isAvailable()
{
    bool _return_value_ = easyar_DenseSpatialMap_isAvailable();
    return _return_value_;
}
inline void DenseSpatialMap::inputFrameSink(/* OUT */ InputFrameSink * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_InputFrameSink * _return_value_ = NULL;
    easyar_DenseSpatialMap_inputFrameSink(cdata_, &_return_value_);
    *Return = new InputFrameSink(_return_value_);
}
inline void DenseSpatialMap::create(/* OUT */ DenseSpatialMap * * Return)
{
    easyar_DenseSpatialMap * _return_value_ = NULL;
    easyar_DenseSpatialMap_create(&_return_value_);
    *Return = new DenseSpatialMap(_return_value_);
}
inline bool DenseSpatialMap::start()
{
    if (cdata_ == NULL) {
        return bool();
    }
    bool _return_value_ = easyar_DenseSpatialMap_start(cdata_);
    return _return_value_;
}
inline void DenseSpatialMap::stop()
{
    if (cdata_ == NULL) {
        return;
    }
    easyar_DenseSpatialMap_stop(cdata_);
}
inline void DenseSpatialMap::close()
{
    if (cdata_ == NULL) {
        return;
    }
    easyar_DenseSpatialMap_close(cdata_);
}
inline void DenseSpatialMap::saveMap(/* OUT */ String * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_String * _return_value_ = NULL;
    easyar_DenseSpatialMap_saveMap(cdata_, &_return_value_);
    *Return = new String(_return_value_);
}
inline void DenseSpatialMap::getMesh(/* OUT */ SceneMesh * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_SceneMesh * _return_value_ = NULL;
    easyar_DenseSpatialMap_getMesh(cdata_, &_return_value_);
    *Return = new SceneMesh(_return_value_);
}
inline bool DenseSpatialMap::updateSceneMesh(bool arg0)
{
    if (cdata_ == NULL) {
        return bool();
    }
    bool _return_value_ = easyar_DenseSpatialMap_updateSceneMesh(cdata_, arg0);
    return _return_value_;
}

}

#endif
