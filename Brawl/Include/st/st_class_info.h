#pragma once

class stClassInfo {
private:
public:
    void setClassInfo(int, stClassInfo*);
    stClassInfo();
    virtual ~stClassInfo();
};

template <int I, class T>
class stClassInfoImpl : public stClassInfo {
private:
public:
    stClassInfoImpl() : stClassInfo() { setClassInfo(I, this); };
    virtual T* create();
    virtual void preload();
    virtual ~stClassInfoImpl();
};

#define ST_CLASS_INFO                              \
    template <int I, typename T>                   \
    T* stClassInfoImpl<I, T>::create()             \
    {                                              \
        T* stage = new (Heaps::StageInstance) T(); \
        return stage;                              \
    };                                             \
    template <int I, typename T>                   \
    stClassInfoImpl<I, T>::~stClassInfoImpl()      \
    {                                              \
        setClassInfo(I, 0);                        \
    }                                              \
    template <int I, typename T>                   \
    void stClassInfoImpl<I, T>::preload()          \
    {                                              \
        return;                                    \
    }