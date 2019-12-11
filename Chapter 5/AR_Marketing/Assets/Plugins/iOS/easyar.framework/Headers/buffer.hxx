//=============================================================================================================================
//
// EasyAR 3.0.1-final-r238a6316e
// Copyright (c) 2015-2019 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#ifndef __EASYAR_BUFFER_HXX__
#define __EASYAR_BUFFER_HXX__

#include "easyar/types.hxx"

namespace easyar {

class Buffer
{
protected:
    easyar_Buffer * cdata_ ;
    void init_cdata(easyar_Buffer * cdata);
    virtual Buffer & operator=(const Buffer & data) { return *this; } //deleted
public:
    Buffer(easyar_Buffer * cdata);
    virtual ~Buffer();

    Buffer(const Buffer & data);
    const easyar_Buffer * get_cdata() const;
    easyar_Buffer * get_cdata();

    static void wrap(void * ptr, int size, FunctorOfVoid deleter, /* OUT */ Buffer * * Return);
    static void create(int size, /* OUT */ Buffer * * Return);
    void * data();
    int size();
    static void memoryCopy(void * src, void * dest, int length);
    bool tryCopyFrom(void * src, int srcIndex, int index, int length);
    bool tryCopyTo(int index, void * dest, int destIndex, int length);
    void partition(int index, int length, /* OUT */ Buffer * * Return);
};

class BufferDictionary
{
protected:
    easyar_BufferDictionary * cdata_ ;
    void init_cdata(easyar_BufferDictionary * cdata);
    virtual BufferDictionary & operator=(const BufferDictionary & data) { return *this; } //deleted
public:
    BufferDictionary(easyar_BufferDictionary * cdata);
    virtual ~BufferDictionary();

    BufferDictionary(const BufferDictionary & data);
    const easyar_BufferDictionary * get_cdata() const;
    easyar_BufferDictionary * get_cdata();

    BufferDictionary();
    int count();
    bool contains(String * path);
    void tryGet(String * path, /* OUT */ Buffer * * Return);
    void set(String * path, Buffer * buffer);
    bool remove(String * path);
    void clear();
};

#ifndef __EASYAR_FUNCTOROFVOID__
#define __EASYAR_FUNCTOROFVOID__
struct FunctorOfVoid
{
    void * _state;
    void (* func)(void * _state);
    void (* destroy)(void * _state);
    FunctorOfVoid(void * _state, void (* func)(void * _state), void (* destroy)(void * _state));
};

static void FunctorOfVoid_func(void * _state, /* OUT */ easyar_String * * _exception);
static void FunctorOfVoid_destroy(void * _state);
static inline easyar_FunctorOfVoid FunctorOfVoid_to_c(FunctorOfVoid f);
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

}

#endif

#ifndef __IMPLEMENTATION_EASYAR_BUFFER_HXX__
#define __IMPLEMENTATION_EASYAR_BUFFER_HXX__

#include "easyar/buffer.h"

namespace easyar {

inline Buffer::Buffer(easyar_Buffer * cdata)
    :
    cdata_(NULL)
{
    init_cdata(cdata);
}
inline Buffer::~Buffer()
{
    if (cdata_) {
        easyar_Buffer__dtor(cdata_);
        cdata_ = NULL;
    }
}

inline Buffer::Buffer(const Buffer & data)
    :
    cdata_(NULL)
{
    easyar_Buffer * cdata = NULL;
    easyar_Buffer__retain(data.cdata_, &cdata);
    init_cdata(cdata);
}
inline const easyar_Buffer * Buffer::get_cdata() const
{
    return cdata_;
}
inline easyar_Buffer * Buffer::get_cdata()
{
    return cdata_;
}
inline void Buffer::init_cdata(easyar_Buffer * cdata)
{
    cdata_ = cdata;
}
inline void Buffer::wrap(void * arg0, int arg1, FunctorOfVoid arg2, /* OUT */ Buffer * * Return)
{
    easyar_Buffer * _return_value_ = NULL;
    easyar_Buffer_wrap(arg0, arg1, FunctorOfVoid_to_c(arg2), &_return_value_);
    *Return = new Buffer(_return_value_);
}
inline void Buffer::create(int arg0, /* OUT */ Buffer * * Return)
{
    easyar_Buffer * _return_value_ = NULL;
    easyar_Buffer_create(arg0, &_return_value_);
    *Return = new Buffer(_return_value_);
}
inline void * Buffer::data()
{
    if (cdata_ == NULL) {
        return NULL;
    }
    void * _return_value_ = easyar_Buffer_data(cdata_);
    return _return_value_;
}
inline int Buffer::size()
{
    if (cdata_ == NULL) {
        return int();
    }
    int _return_value_ = easyar_Buffer_size(cdata_);
    return _return_value_;
}
inline void Buffer::memoryCopy(void * arg0, void * arg1, int arg2)
{
    easyar_Buffer_memoryCopy(arg0, arg1, arg2);
}
inline bool Buffer::tryCopyFrom(void * arg0, int arg1, int arg2, int arg3)
{
    if (cdata_ == NULL) {
        return bool();
    }
    bool _return_value_ = easyar_Buffer_tryCopyFrom(cdata_, arg0, arg1, arg2, arg3);
    return _return_value_;
}
inline bool Buffer::tryCopyTo(int arg0, void * arg1, int arg2, int arg3)
{
    if (cdata_ == NULL) {
        return bool();
    }
    bool _return_value_ = easyar_Buffer_tryCopyTo(cdata_, arg0, arg1, arg2, arg3);
    return _return_value_;
}
inline void Buffer::partition(int arg0, int arg1, /* OUT */ Buffer * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_Buffer * _return_value_ = NULL;
    easyar_Buffer_partition(cdata_, arg0, arg1, &_return_value_);
    *Return = new Buffer(_return_value_);
}

inline BufferDictionary::BufferDictionary(easyar_BufferDictionary * cdata)
    :
    cdata_(NULL)
{
    init_cdata(cdata);
}
inline BufferDictionary::~BufferDictionary()
{
    if (cdata_) {
        easyar_BufferDictionary__dtor(cdata_);
        cdata_ = NULL;
    }
}

inline BufferDictionary::BufferDictionary(const BufferDictionary & data)
    :
    cdata_(NULL)
{
    easyar_BufferDictionary * cdata = NULL;
    easyar_BufferDictionary__retain(data.cdata_, &cdata);
    init_cdata(cdata);
}
inline const easyar_BufferDictionary * BufferDictionary::get_cdata() const
{
    return cdata_;
}
inline easyar_BufferDictionary * BufferDictionary::get_cdata()
{
    return cdata_;
}
inline void BufferDictionary::init_cdata(easyar_BufferDictionary * cdata)
{
    cdata_ = cdata;
}
inline BufferDictionary::BufferDictionary()
    :
    cdata_(NULL)
{
    easyar_BufferDictionary * _return_value_ = NULL;
    easyar_BufferDictionary__ctor(&_return_value_);
    init_cdata(_return_value_);
}
inline int BufferDictionary::count()
{
    if (cdata_ == NULL) {
        return int();
    }
    int _return_value_ = easyar_BufferDictionary_count(cdata_);
    return _return_value_;
}
inline bool BufferDictionary::contains(String * arg0)
{
    if (cdata_ == NULL) {
        return bool();
    }
    bool _return_value_ = easyar_BufferDictionary_contains(cdata_, arg0->get_cdata());
    return _return_value_;
}
inline void BufferDictionary::tryGet(String * arg0, /* OUT */ Buffer * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_OptionalOfBuffer _return_value_ = {false, NULL};
    easyar_BufferDictionary_tryGet(cdata_, arg0->get_cdata(), &_return_value_);
    *Return = (_return_value_.has_value ? new Buffer(_return_value_.value) : NULL);
}
inline void BufferDictionary::set(String * arg0, Buffer * arg1)
{
    if (cdata_ == NULL) {
        return;
    }
    easyar_BufferDictionary_set(cdata_, arg0->get_cdata(), arg1->get_cdata());
}
inline bool BufferDictionary::remove(String * arg0)
{
    if (cdata_ == NULL) {
        return bool();
    }
    bool _return_value_ = easyar_BufferDictionary_remove(cdata_, arg0->get_cdata());
    return _return_value_;
}
inline void BufferDictionary::clear()
{
    if (cdata_ == NULL) {
        return;
    }
    easyar_BufferDictionary_clear(cdata_);
}

#ifndef __IMPLEMENTATION_EASYAR_FUNCTOROFVOID__
#define __IMPLEMENTATION_EASYAR_FUNCTOROFVOID__
inline FunctorOfVoid::FunctorOfVoid(void * _state, void (* func)(void * _state), void (* destroy)(void * _state))
{
    this->_state = _state;
    this->func = func;
    this->destroy = destroy;
}
static void FunctorOfVoid_func(void * _state, /* OUT */ easyar_String * * _exception)
{
    *_exception = NULL;
    try {
        FunctorOfVoid * f = reinterpret_cast<FunctorOfVoid *>(_state);
        f->func(f->_state);
    } catch (std::exception & ex) {
        easyar_String_from_utf8_begin(ex.what(), _exception);
    }
}
static void FunctorOfVoid_destroy(void * _state)
{
    FunctorOfVoid * f = reinterpret_cast<FunctorOfVoid *>(_state);
    if (f->destroy) {
        f->destroy(f->_state);
    }
    delete f;
}
static inline easyar_FunctorOfVoid FunctorOfVoid_to_c(FunctorOfVoid f)
{
    easyar_FunctorOfVoid _return_value_ = {NULL, NULL, NULL};
    _return_value_._state = new FunctorOfVoid(f._state, f.func, f.destroy);
    _return_value_.func = FunctorOfVoid_func;
    _return_value_.destroy = FunctorOfVoid_destroy;
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

}

#endif
