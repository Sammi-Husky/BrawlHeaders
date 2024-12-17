#pragma once

#include <StaticAssert.h>
#include <types.h>
#include <so/anim/so_anim_cmd_event_presenter.h>

class soModuleAccesser;

class soStopModule {
public:
	virtual void setSpecialStop(u32 duration);
	virtual ~soStopModule();
	virtual void activate();
	virtual void end(int);
	virtual void setHitStop();
	virtual void cancelHitStop();
	virtual void setOtherStop(u32 duration);
	virtual void cancelOtherStop();
	virtual void setLinkStop(u32 duration);
	virtual u32 isStop();
	virtual u32 isSpecialStop();
	virtual u32 isHit();
	virtual u32 isDamage();
	virtual void update();
	virtual int getHitStopFrame();
	virtual int getHitStopRealFrame();
	virtual void setHitStopFrame(u32 duration, bool allowSDI);
	virtual void setHitStopFrameFix(int);
};
static_assert(sizeof(soStopModule) == 0x4, "Class is wrong size!");

class soStopModuleImpl : public soStopModule, public soAnimCmdEventObserver {
private:
	char _spacer1[0x4];
public:
	char m_hitStopFrameFix;
private:
	char _spacer2[0xB];
public:
	soModuleAccesser* m_moduleAccesser;

	virtual void setSpecialStop(u32 duration);
	virtual ~soStopModuleImpl();
	virtual void activate();
	virtual void end(int);
	virtual void setHitStop();
	virtual void cancelHitStop();
	virtual void setOtherStop(u32 duration);
	virtual void cancelOtherStop();
	virtual void setLinkStop(u32 duration);
	virtual u32 isStop();
	virtual u32 isSpecialStop();
	virtual u32 isHit();
	virtual u32 isDamage();
	virtual void update();
	virtual int getHitStopFrame();
	virtual int getHitStopRealFrame();
	virtual void setHitStopFrame(u32 duration, bool allowSDI);
	virtual void setHitStopFrameFix(int);

	virtual bool isObserv(char unk1);
	virtual bool notifyEventAnimCmd(acAnimCmd* acmd, soModuleAccesser* moduleAccesser, int unk3);
}; 
static_assert(sizeof(soStopModuleImpl) == 0x24, "Class is wrong size!");
