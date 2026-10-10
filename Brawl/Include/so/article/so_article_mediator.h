#pragma once

#include <StaticAssert.h>
#include <types.h>

class soArticle;
class soModuleAccesser;

class soArticleGenerator {
public:
    virtual ~soArticleGenerator();
    virtual soArticle* generateArticle(
        u32 kind, soModuleAccesser* moduleOwner) = 0;
};

class soArticleOperator {
public:
    virtual ~soArticleOperator();
    virtual void deactivate() = 0;
    virtual bool isGeneratable(void* context, u32 kind) = 0;
    virtual s32 getActiveNum(void* context, u32 kind) = 0;
    virtual s32 getGenerateMaxNum(u32 kind) = 0;
    virtual s32 getMediateNum() = 0;
    virtual void setAutoRecycle(bool enabled) = 0;
    virtual s32 shoot(void* context, soArticle* article) = 0;
};

class soArticleMediator :
    public soArticleGenerator, public soArticleOperator {
public:
    virtual ~soArticleMediator();
};

class soArticleMediatorNull : public soArticleMediator {
public:
    static soArticleMediatorNull& getInstance() {
        static soArticleMediatorNull instance;
        return instance;
    }
    virtual ~soArticleMediatorNull();
    virtual soArticle* generateArticle(
        u32 kind, soModuleAccesser* moduleOwner);
    virtual void deactivate();
    virtual bool isGeneratable(void*, u32);
    virtual s32 getActiveNum(void*, u32);
    virtual s32 getGenerateMaxNum(u32);
    virtual s32 getMediateNum();
    virtual void setAutoRecycle(bool);
    virtual s32 shoot(void*, soArticle*);
};

static_assert(sizeof(soArticleGenerator) == 0x4, "Class is wrong size!");
static_assert(sizeof(soArticleOperator) == 0x4, "Class is wrong size!");
static_assert(sizeof(soArticleMediator) == 0x8, "Class is wrong size!");
static_assert(sizeof(soArticleMediatorNull) == 0x8, "Class is wrong size!");
