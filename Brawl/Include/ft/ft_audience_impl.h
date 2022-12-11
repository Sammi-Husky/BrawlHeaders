#pragma once

#include <types.h>
#include <StaticAssert.h>
#include <gf/gf_task.h>

class ftAudience {
public:
    virtual ~ftAudience();
    virtual void activate();
    virtual void deactivate();
    virtual void reqHandclapDead(float, bool);
    virtual float correctCheerReaction(float, float);
    virtual void reqCallFgmStopCheer();
    virtual void checkCheer(float, int entryId1, int entryId2);
    virtual bool checkTumultRange(float);
    virtual bool checkTumultLanding(float, float, int entryId);
    virtual bool checkTumultFallSpecial(float, int entryId);
    virtual void checkCheerDefeat(int entryId);

    STATIC_CHECK(sizeof(ftAudience) == 4)
};

class ftAudienceImpl : public gfTask, public ftAudience {
    char _68[4];
    int m_entryId;
    char _76[4];
    float m_80;
    char _84[44];

public:
    virtual void processFixPosition();
    virtual ~ftAudienceImpl();

    virtual void activate();
    virtual void deactivate();
    virtual void reqHandclapDead(float, bool);
    virtual float correctCheerReaction(float, float);
    virtual void reqCallFgmStopCheer();
    virtual void checkCheer(float, int entryId1, int entryId2);
    virtual bool checkTumultRange(float);
    virtual bool checkTumultLanding(float, float, int entryId);
    virtual bool checkTumultFallSpecial(float, int entryId);
    virtual void checkCheerDefeat(int entryId);

    STATIC_CHECK(sizeof(ftAudienceImpl) == 128)
};