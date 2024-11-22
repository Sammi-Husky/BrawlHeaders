#pragma once

#include <StaticAssert.h>
#include <so/event/so_event_presenter.h>
#include <so/so_null.h>
#include <so/so_module_accesser.h>
#include <types.h>

class soArticleEventObserver : public soEventObserver<soArticleEventObserver> {
public:
    virtual void addObserver(short param1, s8 param2);
    char _spacer1[2];
};
static_assert(sizeof(soArticleEventObserver) == 12, "Class is wrong size!");

struct soLogAttackInfo {
    int _0;
    int _4;
    int _8;
};

class soArticle : public soNullable, public soEventPresenter<soArticleEventObserver> {
    // TODO
    virtual ~soArticle();
    virtual void remove();
    virtual int getArticleId();
    virtual int getArticleEventManageId();
    virtual int getTaskId();
    virtual void changeMotion(int, int);
    virtual void setFrame(float frame);
    virtual void setRate(float rate);
    virtual void changeStatus(int statusKind);
    virtual void setVisibilityWhole(u8);
    virtual void setVisibility(int, u8);
    virtual void set2nd(u8);
    virtual void action(int);
    virtual void setSituationKind(SituationKind);
    virtual bool isConstraint();
    virtual void deactivateDescendantForce();
    virtual bool isActiveArticle();
    virtual void deactivateArticle();
    virtual int getOwnerDeactiveTreatType();
    virtual int getFounderTaskId();
    virtual void have(int, int, int);
    virtual void linkOwner(int, int);
    virtual void unlinkOwner(int);
    virtual bool isSyncOwnerStatus();
    virtual void setSyncOwnerStatus(int);
    virtual void setLogAttackInfo(soLogAttackInfo* logAttackInfo);
    virtual soLogAttackInfo getLogAttackInfo();
    virtual void updateLogAttackInfo();
    virtual void intrudeLogAttackInfo();
    virtual float getActiveGlobalFrame();
    virtual void setAttackPowerMulPattern(float);
};
static_assert(sizeof(soArticle) == 20, "Class is wrong size!");
