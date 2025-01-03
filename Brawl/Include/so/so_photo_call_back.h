#pragma once

#include <ut/ut_list.h>

class cmPhotoCallBack : public utListNode {
public:
    virtual ~cmPhotoCallBack() { }
};

class soPhotoCallBack : public cmPhotoCallBack {
public:
    virtual ~soPhotoCallBack() { }
    void addCallback();
    void removeCallBack();
};
