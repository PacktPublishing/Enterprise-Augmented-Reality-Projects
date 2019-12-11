//=============================================================================================================================
//
// EasyAR 3.0.1-final-r238a6316e
// Copyright (c) 2015-2019 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#ifndef __EASYAR_SCENEMESH_HXX__
#define __EASYAR_SCENEMESH_HXX__

#include "easyar/types.hxx"

namespace easyar {

/// <summary>
/// record
/// </summary>
struct BlockInfo
{
    int x_;
    int y_;
    int z_;
    int numOfVertex_;
    int startPointOfVertex_;
    int numOfIndex_;
    int startPointOfIndex_;
    int age_;

    BlockInfo();
    BlockInfo(int x_, int y_, int z_, int numOfVertex_, int startPointOfVertex_, int numOfIndex_, int startPointOfIndex_, int age_);
    easyar_BlockInfo get_cdata();
};

class SceneMesh
{
protected:
    easyar_SceneMesh * cdata_ ;
    void init_cdata(easyar_SceneMesh * cdata);
    virtual SceneMesh & operator=(const SceneMesh & data) { return *this; } //deleted
public:
    SceneMesh(easyar_SceneMesh * cdata);
    virtual ~SceneMesh();

    SceneMesh(const SceneMesh & data);
    const easyar_SceneMesh * get_cdata() const;
    easyar_SceneMesh * get_cdata();

    SceneMesh();
    int getNumOfVertexAll();
    int getNumOfIndexAll();
    void getVerticesAll(/* OUT */ Buffer * * Return);
    void getNormalsAll(/* OUT */ Buffer * * Return);
    void getIndicesAll(/* OUT */ Buffer * * Return);
    int getNumOfVertexIncremental();
    int getNumOfIndexIncremental();
    void getVerticesIncremental(/* OUT */ Buffer * * Return);
    void getNormalsIncremental(/* OUT */ Buffer * * Return);
    void getIndicesIncremental(/* OUT */ Buffer * * Return);
    void getBlocksInfoIncremental(/* OUT */ ListOfBlockInfo * * Return);
    float getBlockDimentionInMeters();
};

#ifndef __EASYAR_LISTOFBLOCKINFO__
#define __EASYAR_LISTOFBLOCKINFO__
class ListOfBlockInfo
{
private:
    easyar_ListOfBlockInfo * cdata_;
    virtual ListOfBlockInfo & operator=(const ListOfBlockInfo & data) { return *this; } //deleted
public:
    ListOfBlockInfo(easyar_ListOfBlockInfo * cdata);
    virtual ~ListOfBlockInfo();

    ListOfBlockInfo(const ListOfBlockInfo & data);
    const easyar_ListOfBlockInfo * get_cdata() const;
    easyar_ListOfBlockInfo * get_cdata();

    ListOfBlockInfo(easyar_BlockInfo * begin, easyar_BlockInfo * end);
    int size() const;
    BlockInfo at(int index) const;
};
#endif

}

#endif

#ifndef __IMPLEMENTATION_EASYAR_SCENEMESH_HXX__
#define __IMPLEMENTATION_EASYAR_SCENEMESH_HXX__

#include "easyar/scenemesh.h"
#include "easyar/buffer.hxx"

namespace easyar {

inline BlockInfo::BlockInfo()
{
    this->x_ = int();
    this->y_ = int();
    this->z_ = int();
    this->numOfVertex_ = int();
    this->startPointOfVertex_ = int();
    this->numOfIndex_ = int();
    this->startPointOfIndex_ = int();
    this->age_ = int();
}
inline BlockInfo::BlockInfo(int x_, int y_, int z_, int numOfVertex_, int startPointOfVertex_, int numOfIndex_, int startPointOfIndex_, int age_)
{
    this->x_ = x_;
    this->y_ = y_;
    this->z_ = z_;
    this->numOfVertex_ = numOfVertex_;
    this->startPointOfVertex_ = startPointOfVertex_;
    this->numOfIndex_ = numOfIndex_;
    this->startPointOfIndex_ = startPointOfIndex_;
    this->age_ = age_;
}
inline easyar_BlockInfo BlockInfo::get_cdata()
{
    easyar_BlockInfo _return_value_ = {x_, y_, z_, numOfVertex_, startPointOfVertex_, numOfIndex_, startPointOfIndex_, age_};
    return _return_value_;
}
inline SceneMesh::SceneMesh(easyar_SceneMesh * cdata)
    :
    cdata_(NULL)
{
    init_cdata(cdata);
}
inline SceneMesh::~SceneMesh()
{
    if (cdata_) {
        easyar_SceneMesh__dtor(cdata_);
        cdata_ = NULL;
    }
}

inline SceneMesh::SceneMesh(const SceneMesh & data)
    :
    cdata_(NULL)
{
    easyar_SceneMesh * cdata = NULL;
    easyar_SceneMesh__retain(data.cdata_, &cdata);
    init_cdata(cdata);
}
inline const easyar_SceneMesh * SceneMesh::get_cdata() const
{
    return cdata_;
}
inline easyar_SceneMesh * SceneMesh::get_cdata()
{
    return cdata_;
}
inline void SceneMesh::init_cdata(easyar_SceneMesh * cdata)
{
    cdata_ = cdata;
}
inline SceneMesh::SceneMesh()
    :
    cdata_(NULL)
{
    easyar_SceneMesh * _return_value_ = NULL;
    easyar_SceneMesh__ctor(&_return_value_);
    init_cdata(_return_value_);
}
inline int SceneMesh::getNumOfVertexAll()
{
    if (cdata_ == NULL) {
        return int();
    }
    int _return_value_ = easyar_SceneMesh_getNumOfVertexAll(cdata_);
    return _return_value_;
}
inline int SceneMesh::getNumOfIndexAll()
{
    if (cdata_ == NULL) {
        return int();
    }
    int _return_value_ = easyar_SceneMesh_getNumOfIndexAll(cdata_);
    return _return_value_;
}
inline void SceneMesh::getVerticesAll(/* OUT */ Buffer * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_Buffer * _return_value_ = NULL;
    easyar_SceneMesh_getVerticesAll(cdata_, &_return_value_);
    *Return = new Buffer(_return_value_);
}
inline void SceneMesh::getNormalsAll(/* OUT */ Buffer * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_Buffer * _return_value_ = NULL;
    easyar_SceneMesh_getNormalsAll(cdata_, &_return_value_);
    *Return = new Buffer(_return_value_);
}
inline void SceneMesh::getIndicesAll(/* OUT */ Buffer * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_Buffer * _return_value_ = NULL;
    easyar_SceneMesh_getIndicesAll(cdata_, &_return_value_);
    *Return = new Buffer(_return_value_);
}
inline int SceneMesh::getNumOfVertexIncremental()
{
    if (cdata_ == NULL) {
        return int();
    }
    int _return_value_ = easyar_SceneMesh_getNumOfVertexIncremental(cdata_);
    return _return_value_;
}
inline int SceneMesh::getNumOfIndexIncremental()
{
    if (cdata_ == NULL) {
        return int();
    }
    int _return_value_ = easyar_SceneMesh_getNumOfIndexIncremental(cdata_);
    return _return_value_;
}
inline void SceneMesh::getVerticesIncremental(/* OUT */ Buffer * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_Buffer * _return_value_ = NULL;
    easyar_SceneMesh_getVerticesIncremental(cdata_, &_return_value_);
    *Return = new Buffer(_return_value_);
}
inline void SceneMesh::getNormalsIncremental(/* OUT */ Buffer * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_Buffer * _return_value_ = NULL;
    easyar_SceneMesh_getNormalsIncremental(cdata_, &_return_value_);
    *Return = new Buffer(_return_value_);
}
inline void SceneMesh::getIndicesIncremental(/* OUT */ Buffer * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_Buffer * _return_value_ = NULL;
    easyar_SceneMesh_getIndicesIncremental(cdata_, &_return_value_);
    *Return = new Buffer(_return_value_);
}
inline void SceneMesh::getBlocksInfoIncremental(/* OUT */ ListOfBlockInfo * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_ListOfBlockInfo * _return_value_ = NULL;
    easyar_SceneMesh_getBlocksInfoIncremental(cdata_, &_return_value_);
    *Return = new ListOfBlockInfo(_return_value_);
}
inline float SceneMesh::getBlockDimentionInMeters()
{
    if (cdata_ == NULL) {
        return float();
    }
    float _return_value_ = easyar_SceneMesh_getBlockDimentionInMeters(cdata_);
    return _return_value_;
}

#ifndef __IMPLEMENTATION_EASYAR_LISTOFBLOCKINFO__
#define __IMPLEMENTATION_EASYAR_LISTOFBLOCKINFO__
inline ListOfBlockInfo::ListOfBlockInfo(easyar_ListOfBlockInfo * cdata)
    : cdata_(cdata)
{
}
inline ListOfBlockInfo::~ListOfBlockInfo()
{
    if (cdata_) {
        easyar_ListOfBlockInfo__dtor(cdata_);
        cdata_ = NULL;
    }
}

inline ListOfBlockInfo::ListOfBlockInfo(const ListOfBlockInfo & data)
    : cdata_(static_cast<easyar_ListOfBlockInfo *>(NULL))
{
    easyar_ListOfBlockInfo_copy(data.cdata_, &cdata_);
}
inline const easyar_ListOfBlockInfo * ListOfBlockInfo::get_cdata() const
{
    return cdata_;
}
inline easyar_ListOfBlockInfo * ListOfBlockInfo::get_cdata()
{
    return cdata_;
}

inline ListOfBlockInfo::ListOfBlockInfo(easyar_BlockInfo * begin, easyar_BlockInfo * end)
    : cdata_(static_cast<easyar_ListOfBlockInfo *>(NULL))
{
    easyar_ListOfBlockInfo__ctor(begin, end, &cdata_);
}
inline int ListOfBlockInfo::size() const
{
    return easyar_ListOfBlockInfo_size(cdata_);
}
inline BlockInfo ListOfBlockInfo::at(int index) const
{
    easyar_BlockInfo _return_value_ = easyar_ListOfBlockInfo_at(cdata_, index);
    return BlockInfo(_return_value_.x_, _return_value_.y_, _return_value_.z_, _return_value_.numOfVertex_, _return_value_.startPointOfVertex_, _return_value_.numOfIndex_, _return_value_.startPointOfIndex_, _return_value_.age_);
}
#endif

}

#endif
