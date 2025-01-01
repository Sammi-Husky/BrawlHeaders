#pragma once

#include <so/so_null.h>
#include <types.h>

// TODO: size
class soResourceIdAccesser : public soNullable {
public:
    virtual ~soResourceIdAccesser();
    virtual void setResIdPacked(u32 id);
    virtual void setAnmResId(u32 id);
    virtual void setMdlResId(u32 id);
    virtual void setTexResId(u32 id);
    virtual void setMdlResIndex(u16 id);
    virtual void setTexResIndex(u16 id);
    virtual u32 getTexResId() = 0;
    virtual u16 getTexResIndex();
    virtual u32 getMdlResId() = 0;
    virtual u16 getMdlResIndex() = 0;
    virtual u32 getAnmResId() = 0;
    virtual u32 getBinResId() = 0;
    virtual u32 getArchiveId() = 0;
    virtual u32 getEtcResId() = 0;
    virtual u32 getMdlArchiveId() = 0;
    virtual u32 getTexArchiveId() = 0;
    virtual u32 getAnmArchiveId() = 0;
    virtual u32 getEtcArchiveId() = 0;
    virtual u32 getBinArchiveId() = 0;
};

// TODO: size
class soResourceIdAccesserImpl : public soResourceIdAccesser {
public:
    virtual ~soResourceIdAccesserImpl();
    virtual void setResIdPacked(u32 id);
    virtual void setAnmResId(u32 id);
    virtual void setMdlResId(u32 id);
    virtual void setTexResId(u32 id);
    virtual void setMdlResIndex(u16 id);
    virtual void setTexResIndex(u16 id);
    virtual u32 getTexResId();
    virtual u16 getTexResIndex();
    virtual u32 getMdlResId();
    virtual u16 getMdlResIndex();
    virtual u32 getAnmResId();
    virtual u32 getBinResId();
    virtual u32 getArchiveId();
    virtual u32 getEtcResId();
    virtual u32 getMdlArchiveId();
    virtual u32 getTexArchiveId();
    virtual u32 getAnmArchiveId();
    virtual u32 getEtcArchiveId();
    virtual u32 getBinArchiveId();
};
