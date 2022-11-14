#pragma once

#include <types.h>
#include <StaticAssert.h>
#include <so/so_null.h>
#include <so/so_event_presenter.h>

class soArticleEventObserver : public soEventObserver<soArticleEventObserver> {
    char _spacer1[2];
    STATIC_CHECK(sizeof(soArticleEventObserver) == 12)
};

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
    virtual void changeMotion(int,int);
    virtual void setFrame(float frame);
    virtual void setRate(float rate);
    virtual void changeStatus(int actionID);
    virtual void setVisibilityWhole(u8);
    virtual void setVisibility(int, u8);
    virtual void set2nd(u8);
    virtual void action(int);
    virtual void setSituationKind(int);
    virtual bool isConstraint();
    virtual void deactivateDescendantForce();
    virtual bool isActiveArticle();
    virtual void deactivateArticle();
    virtual int getOwnerDeactiveTreatType();
    virtual int getFounderTaskId();
    virtual void have(int, int, int);
    virtual void linkOwner(int,int);
    virtual void unlinkOwner(int);
    virtual bool isSyncOwnerStatus();
    virtual void setSyncOwnerStatus(int);
    virtual void setLogAttackInfo(soLogAttackInfo* logAttackInfo);
    virtual soLogAttackInfo getLogAttackInfo();
    virtual void updateLogAttackInfo();
    virtual void intrudeLogAttackInfo();
    virtual float getActiveGlobalFrame();
    virtual void setAttackPowerMulPattern(float);

    STATIC_CHECK(sizeof(soArticle) == 20)
};
