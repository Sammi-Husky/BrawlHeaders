#pragma once

#include <StaticAssert.h>
#include <so/so_null.h>
#include <types.h>

class soTeam : public soNullable {
public:
    virtual ~soTeam();
    virtual s32 getTeam();
    virtual void setTeam(s32 team);
    virtual s32 getEffectiveTeam();
    virtual void setEffectiveTeam(s32 team);
    virtual s32 getTeamOwner();
    virtual void setTeamOwner(s32 teamOwner);
    virtual void update();
};
static_assert(sizeof(soTeam) == 0x8, "soTeam size is wrong!");

class soTeamImpl : public soTeam {
public:
    explicit soTeamImpl(s32 team);
    virtual ~soTeamImpl();
    virtual s32 getTeam();
    virtual void setTeam(s32 team);
    virtual s32 getEffectiveTeam();
    virtual void setEffectiveTeam(s32 team);
    virtual s32 getTeamOwner();
    virtual void setTeamOwner(s32 teamOwner);
    virtual void update();

    s32 m_team;
    s32 m_teamOwner;
};
static_assert(sizeof(soTeamImpl) == 0x10, "soTeamImpl size is wrong!");

class ftTeam : public soTeam {
public:
    ftTeam(void* fighter);
    virtual ~ftTeam();
    virtual s32 getTeam();
    virtual void setTeam(s32 team);
    virtual s32 getEffectiveTeam();
    virtual void setEffectiveTeam(s32 team);
    virtual s32 getTeamOwner();
    virtual void setTeamOwner(s32 teamOwner);
    virtual void update();

    void* m_fighter;
    s32 m_team;
    s32 m_teamOwner;
};
static_assert(sizeof(ftTeam) == 0x14, "ftTeam size is wrong!");

class ftTeamIndirect : public ftTeam {
public:
    s32 m_indirectTeam;

    ftTeamIndirect(void* fighter) :
        ftTeam(fighter), m_indirectTeam(-1) { }

    virtual ~ftTeamIndirect();
    virtual s32 getTeam();
    virtual s32 getEffectiveTeam();
    virtual void setEffectiveTeam(s32 team);
};
static_assert(sizeof(ftTeamIndirect) == 0x18,
    "ftTeamIndirect size is wrong!");
