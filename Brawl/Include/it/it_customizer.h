#pragma once

#include <types.h>
#include <StaticAssert.h>
#include <it/item.h>

class itBadgeCustomizer : public itCustomizer<itBadgeCustomizer> {
    virtual ~itBadgeCustomizer();
    virtual void onAction(BaseItem* item, int, float rate);

    STATIC_CHECK(sizeof(itBadgeCustomizer) == 12)
};

class itBananaCustomizer : public itCustomizer<itBananaCustomizer> {
    virtual ~itBananaCustomizer();
    virtual bool notifyEventCollisionAttackCheck(u32 flags);

    STATIC_CHECK(sizeof(itBananaCustomizer) == 12)
};

class itBeamSwordCustomizer : public itCustomizer<itBeamSwordCustomizer> {
    virtual ~itBeamSwordCustomizer();
    virtual void onAction(BaseItem* item, int, float rate);

    STATIC_CHECK(sizeof(itBeamSwordCustomizer) == 12)
};

class itMoneyCustomizer : public itCustomizer<itMoneyCustomizer> {
    virtual ~itMoneyCustomizer();
    virtual void onReset(BaseItem* item);
    virtual void onNotifyEventCollisionSearch(BaseItem* item, void*);
    virtual void onNotifyEventCollisionSearchCheck(BaseItem* item, int, u8, Vec3f*);
    virtual void onAction(BaseItem* item, int, float rate);
    virtual bool isSafe(BaseItem* item);

    STATIC_CHECK(sizeof(itMoneyCustomizer) == 12)
};

class itBombheiCustomizer : public itCustomizer<itBombheiCustomizer> {
    virtual ~itBombheiCustomizer();
    virtual void onProcessFixPosition(BaseItem* item);

    STATIC_CHECK(sizeof(itBombheiCustomizer) == 12)
};

class itChewingCustomizer : public itCustomizer<itChewingCustomizer> {
    virtual ~itChewingCustomizer();
    virtual void onNotifyEventChangeStatus(BaseItem* item, int unk1, int unk2, void* unk3, soModuleAccesser* moduleAccesser);
    virtual void onNotifyEventCollisionSearch(BaseItem* item, void*);
    virtual void onNotifyEventCollisionSearchCheck(BaseItem* item, int, u8, Vec3f*);
    virtual bool onHave(BaseItem* item, int);
    virtual bool onReflect(BaseItem* item);
    virtual bool isReferenceControlerHave(BaseItem* item);

    STATIC_CHECK(sizeof(itChewingCustomizer) == 12)
};

class itClackerCustomizer : public itCustomizer<itClackerCustomizer> {
    virtual ~itClackerCustomizer();
    virtual int onShoot(BaseItem* item, float lr, float, int);
    virtual int onShootBlanks(BaseItem* item, int);
    virtual int onGetBullet(BaseItem* item);

    STATIC_CHECK(sizeof(itClackerCustomizer) == 12)
};

class itCurryShotCustomizer : public itCustomizer<itCurryShotCustomizer> {
    virtual ~itCurryShotCustomizer();
    virtual void onReset(BaseItem* item);
    virtual void onUpdateKinetic(BaseItem* item);
    virtual void onThrowAttack(BaseItem* item, float, float* lr, Vec3f*, Vec3f*, float* powerMulStatus, bool*);

    STATIC_CHECK(sizeof(itCurryShotCustomizer) == 12)
};

class itDoseisanCustomizer : public itCustomizer<itDoseisanCustomizer> {
    virtual ~itDoseisanCustomizer();
    virtual void onNotifyEventCollisionAttackCheck(BaseItem* item, int);
    virtual bool isUseSpeedDamage(BaseItem* item);

    STATIC_CHECK(sizeof(itDoseisanCustomizer) == 12)
};

class itDragoonSetCustomizer : public itCustomizer<itDragoonSetCustomizer> {
    virtual ~itDragoonSetCustomizer();
    virtual void onDestruct(BaseItem* item);
    virtual void onReset(BaseItem* item);
    virtual void onProcessFixPosition(BaseItem* item);
    virtual void onProcessHit(BaseItem* item);
    virtual void onRenderDebug(BaseItem* item);
    virtual bool isUseScaleZ(BaseItem* item);
    virtual bool isConstraintHave(BaseItem* item);
    virtual bool isReferenceControlerHave(BaseItem* item);
    virtual u32 getKineticFlags(BaseItem* item);

    STATIC_CHECK(sizeof(itDragoonSetCustomizer) == 12)
};

class itDragoonSightCustomizer : public itCustomizer<itDragoonSightCustomizer> {
    virtual ~itDragoonSightCustomizer();
    virtual void onConstruct(BaseItem* item);
    virtual void onDestruct(BaseItem* item);
    virtual void onReset(BaseItem* item);
    virtual void onProcessFixPosition(BaseItem* item);
    virtual void onNotifyEventLink(BaseItem* item, void* unk1, soModuleAccesser* moduleAccesser, gfTask* task, int unk4);
    virtual int onGetLayerType(BaseItem* item);

    STATIC_CHECK(sizeof(itDragoonSightCustomizer) == 12)
};

class itFigureCustomizer : public itCustomizer<itFigureCustomizer> {
    virtual ~itFigureCustomizer();
    virtual void onConstruct(BaseItem* item);
    virtual void onDestruct(BaseItem* item);
    virtual void onReset(BaseItem* item);
    virtual void onProcessFixPosition(BaseItem* item);
    virtual void onRenderPre(BaseItem* item);
    virtual void onNotifyEventCollisionSearchCheck(BaseItem* item, int, u8, Vec3f*);
    virtual void onAction(BaseItem* item, int, float rate);

    STATIC_CHECK(sizeof(itFigureCustomizer) == 12)
};

class itFireFlowerCustomizer : public itCustomizer<itFireFlowerCustomizer> {
    virtual ~itFireFlowerCustomizer();
    virtual int onShoot(BaseItem* item, float lr, float, int);
    virtual int onShootBlanks(BaseItem* item, int);
    virtual int onGetBullet(BaseItem* item);
    virtual void onAction(BaseItem* item, int, float rate);

    STATIC_CHECK(sizeof(itFireFlowerCustomizer) == 12)
};

class itGoldenHammerCustomizer : public itCustomizer<itGoldenHammerCustomizer> {
    virtual ~itGoldenHammerCustomizer();
    virtual void onNotifyEventCollisionAttackCheck(BaseItem* item, int);
    virtual void onAction(BaseItem* item, int, float rate);
    virtual bool onHave(BaseItem* item, int);

    STATIC_CHECK(sizeof(itGoldenHammerCustomizer) == 12)
};

class itGreenShellCustomizer : public itCustomizer<itGreenShellCustomizer> {
    virtual ~itGreenShellCustomizer();
    virtual void onProcessFixPosition(BaseItem* item);
    virtual void onNotifyEventLink(BaseItem* item, void* unk1, soModuleAccesser* moduleAccesser, gfTask* task, int unk4);
    virtual bool onReflect(BaseItem* item);
    virtual bool isTreadPassive(BaseItem* item);
    virtual bool isUseShake(BaseItem* item);

    STATIC_CHECK(sizeof(itGreenShellCustomizer) == 12)
};

class itHammerCustomizer : public itCustomizer<itHammerCustomizer> {
    virtual ~itHammerCustomizer();
    virtual void onAction(BaseItem* item, int, float rate);

    STATIC_CHECK(sizeof(itHammerCustomizer) == 12)
};

class itHarisenCustomizer : public itCustomizer<itHarisenCustomizer> {
    virtual ~itHarisenCustomizer();
    virtual void onAction(BaseItem* item, int, float rate);

    STATIC_CHECK(sizeof(itHarisenCustomizer) == 12)
};

class itKusudamaCustomizer : public itCustomizer<itKusudamaCustomizer> {
    virtual ~itKusudamaCustomizer();
    virtual bool isUsePhysics(BaseItem* item);

    STATIC_CHECK(sizeof(itKusudamaCustomizer) == 12)
};

class itTuchCustomizer : public itCustomizer<itTuchCustomizer> {
    virtual ~itTuchCustomizer();
    virtual void onNotifyEventCollisionSearchCheck(BaseItem* item, int, u8, Vec3f*);

    STATIC_CHECK(sizeof(itTuchCustomizer) == 12)
};

class itMetalBlockCustomizer : public itCustomizer<itMetalBlockCustomizer> {
    virtual ~itMetalBlockCustomizer();
    virtual bool onDamage(BaseItem* item, int, void*);

    STATIC_CHECK(sizeof(itMetalBlockCustomizer) == 12)
};

class itPasaranCustomizer : public itCustomizer<itPasaranCustomizer> {
    virtual ~itPasaranCustomizer();
    virtual void onReset(BaseItem* item);
    virtual bool onReflect(BaseItem* item);
    virtual u32 getKineticFlags(BaseItem* item);

    STATIC_CHECK(sizeof(itPasaranCustomizer) == 12)
};

class itRayGunCustomizer : public itCustomizer<itRayGunCustomizer> {
    virtual ~itRayGunCustomizer();
    virtual int onShoot(BaseItem* item, float lr, float, int);
    virtual int onShootBlanks(BaseItem* item, int);
    virtual int onGetBullet(BaseItem* item);

    STATIC_CHECK(sizeof(itRayGunCustomizer) == 12)
};

class itRayGunShotCustomizer : public itCustomizer<itRayGunShotCustomizer> {
    virtual ~itRayGunShotCustomizer();
    virtual void onProcessFixPosition(BaseItem* item);

    STATIC_CHECK(sizeof(itRayGunShotCustomizer) == 12)
};

class itRipStickCustomizer : public itCustomizer<itRipStickCustomizer> {
    virtual ~itRipStickCustomizer();
    virtual int onShoot(BaseItem* item, float lr, float, int);
    virtual int onShootBlanks(BaseItem* item, int);
    virtual int onGetBullet(BaseItem* item);

    STATIC_CHECK(sizeof(itRipStickCustomizer) == 12)
};

class itRipStickFlowerCustomizer : public itCustomizer<itRipStickFlowerCustomizer> {
    virtual ~itRipStickFlowerCustomizer();
    virtual bool isUsePhysics(BaseItem* item);

    STATIC_CHECK(sizeof(itRipStickFlowerCustomizer) == 12)
};

class itSandbagCustomizer : public itCustomizer<itSandbagCustomizer> {
    virtual ~itSandbagCustomizer();
    virtual void onReset(BaseItem* item);
    virtual void onProcessFixPosition(BaseItem* item);
    virtual void onNotifyEventLink(BaseItem* item, void* unk1, soModuleAccesser* moduleAccesser, gfTask* task, int unk4);
    virtual bool onNotifyEventCaptureStatus(BaseItem* item); // TODO
    virtual bool onDamage(BaseItem* item, int, void*);
    virtual void onPreBound(BaseItem* item, float*, u32);
    virtual bool isUseTurnDamage(BaseItem* item);
    virtual bool isUseSpeedDamage(BaseItem* item);
    virtual u32 getKineticFlags(BaseItem* item);

    STATIC_CHECK(sizeof(itSandbagCustomizer) == 12)
};

class itSlowCustomizer : public itCustomizer<itSlowCustomizer> {
    virtual ~itSlowCustomizer();
    virtual int onResult(BaseItem* item);

    STATIC_CHECK(sizeof(itSlowCustomizer) == 12)
};

class itSmartBombCustomizer : public itCustomizer<itSmartBombCustomizer> {
    virtual ~itSmartBombCustomizer();
    virtual void onReset(BaseItem* item);

    STATIC_CHECK(sizeof(itSmartBombCustomizer) == 12)
};

class itSmashBallCustomizer : public itCustomizer<itSmashBallCustomizer> {
    virtual ~itSmashBallCustomizer();
    virtual void onNotifyEventAnimCmd(BaseItem* item, acAnimCmd* acmd, soModuleAccesser* moduleAccesser, int unk3);
    virtual void onUpdateAiDir(BaseItem* item, Vec2f*, Vec2f*, Vec2f*, Vec2f*);
    virtual void onUpdateAiMove(BaseItem* item, Vec2f*, Vec2f*, Vec2f*);
    virtual bool onPreDamageCheck(BaseItem* item, int, void*);
    virtual bool isUseSpeedDamage(BaseItem* item);
    virtual u32 getKineticFlags(BaseItem* item);

    STATIC_CHECK(sizeof(itSmashBallCustomizer) == 12)
};

class itSmokeScreenCustomizer : public itCustomizer<itSmokeScreenCustomizer> {
    virtual ~itSmokeScreenCustomizer();
    virtual void onReset(BaseItem* item);
    virtual void onNotifyEventChangeStatus(BaseItem* item, int unk1, int unk2, void* unk3, soModuleAccesser* moduleAccesser); // TODO: Verify observer parameters
    virtual void onNotifyEventCollisionSearch(BaseItem* item, void*);
    virtual void onNotifyEventCollisionSearchCheck(BaseItem* item, int, u8, Vec3f*);
    virtual bool onReflect(BaseItem* item);
    virtual bool isReferenceControlerHave(BaseItem* item);

    STATIC_CHECK(sizeof(itSmokeScreenCustomizer) == 12)
};

class itSpringCustomizer : public itCustomizer<itSpringCustomizer> {
    virtual ~itSpringCustomizer();
    virtual void onDestruct(BaseItem* item);
    virtual void onProcessFixPosition(BaseItem* item);
    virtual void onNotifyEventChangeStatus(BaseItem* item, int unk1, int unk2, void* unk3, soModuleAccesser* moduleAccesser); // TODO: Verify observer parameters
    virtual void onNotifyEventCollisionSearchCheck(BaseItem* item, int, u8, Vec3f*);
    virtual void onNotifyEventGimmick(BaseItem* item, soGimmickEventInfo *eventInfo,int *taskId);
    virtual bool onHave(BaseItem* item, int);

    STATIC_CHECK(sizeof(itSpringCustomizer) == 12)
};

class itStarRodCustomizer : public itCustomizer<itStarRodCustomizer> {
    virtual ~itStarRodCustomizer();
    virtual int onShoot(BaseItem* item, float lr, float, int);
    virtual int onShootBlanks(BaseItem* item, int);
    virtual int onGetBullet(BaseItem* item);
    virtual void onAction(BaseItem* item, int, float rate);

    STATIC_CHECK(sizeof(itStarRodCustomizer) == 12)
};

class itStarRodShotCustomizer : public itCustomizer<itStarRodShotCustomizer> {
    virtual ~itStarRodShotCustomizer();
    virtual u32 getKineticFlags(BaseItem* item);

    STATIC_CHECK(sizeof(itStarRodShotCustomizer) == 12)
};

class itSuperScopeCustomizer : public itCustomizer<itSuperScopeCustomizer> {
    virtual ~itSuperScopeCustomizer();
    virtual int onShoot(BaseItem* item, float lr, float, int);
    virtual int onShootBlanks(BaseItem* item, int);
    virtual int onGetBullet(BaseItem* item);

    STATIC_CHECK(sizeof(itSuperScopeCustomizer) == 12)
};

class itTeamHealingCustomizer : public itCustomizer<itTeamHealingCustomizer> {
    virtual ~itTeamHealingCustomizer();
    virtual void onNotifyEventCollisionSearchCheck(BaseItem* item, int, u8, Vec3f*);

    STATIC_CHECK(sizeof(itTeamHealingCustomizer) == 12)
};

class itThunderCustomizer : public itCustomizer<itThunderCustomizer> {
    virtual ~itThunderCustomizer();
    virtual void onNotifyEventCollisionSearchCheck(BaseItem* item, int, u8, Vec3f*);
    virtual int onResult(BaseItem* item);

    STATIC_CHECK(sizeof(itThunderCustomizer) == 12)
};

class itUsagiHatCustomizer : public itCustomizer<itUsagiHatCustomizer> {
    virtual ~itUsagiHatCustomizer();
    virtual void onAction(BaseItem* item, int, float rate);
    virtual bool isUsePhysics(BaseItem* item);

    STATIC_CHECK(sizeof(itUsagiHatCustomizer) == 12)
};

class itWarpstarCustomizer : public itCustomizer<itWarpstarCustomizer> {
    virtual ~itWarpstarCustomizer();
    virtual void onProcessFixPosition(BaseItem* item);
    virtual bool isConstraintHave(BaseItem* item);
    virtual bool isReferenceControlerHave(BaseItem* item);
    virtual u32 getKineticFlags(BaseItem* item);

    STATIC_CHECK(sizeof(itWarpstarCustomizer) == 12)
};

class itAroarosCustomizer : public itCustomizer<itAroarosCustomizer> {
    virtual ~itAroarosCustomizer();
    virtual u32 getKineticFlags(BaseItem* item);

    STATIC_CHECK(sizeof(itAroarosCustomizer) == 12)
};

class itCBoxCustomizer : public itCustomizer<itCBoxCustomizer> {
    virtual ~itCBoxCustomizer();
    virtual void onAction(BaseItem* item, int, float rate);
    virtual bool onHave(BaseItem* item, int);
    virtual bool onRemoveModelConstraint(BaseItem* item, int);
    virtual bool isUseScaleZ(BaseItem* item);
    virtual bool isUseThrowRotParam(BaseItem* item);
    virtual u32 getKineticFlags(BaseItem* item);

    STATIC_CHECK(sizeof(itCBoxCustomizer) == 12)
};

class itDiddyPeanutsCustomizer : public itCustomizer<itDiddyPeanutsCustomizer> {
    virtual ~itDiddyPeanutsCustomizer();
    virtual void onAction(BaseItem* item, int, float rate);
    virtual bool isUseSpeedDamage(BaseItem* item);

    STATIC_CHECK(sizeof(itDiddyPeanutsCustomizer) == 12)
};

class itLinkBombCustomizer : public itCustomizer<itLinkBombCustomizer> {
    virtual ~itLinkBombCustomizer();
    virtual void onProcessFixPosition(BaseItem* item);
    virtual void onNotifyEventCollisionSearch(BaseItem* item, void*);
    virtual void onNotifyEventCollisionSearchCheck(BaseItem* item, int, u8, Vec3f*);

    STATIC_CHECK(sizeof(itLinkBombCustomizer) == 12)
};

class itRobotGyroCustomizer : public itCustomizer<itRobotGyroCustomizer> {
    virtual ~itRobotGyroCustomizer();
    virtual void onProcessFixPosition(BaseItem* item);
    virtual void onAction(BaseItem* item, int, float rate);
    virtual u32 getKineticFlags(BaseItem* item);

    STATIC_CHECK(sizeof(itRobotGyroCustomizer) == 12)
};

class itWarioBikeCustomizer : public itCustomizer<itWarioBikeCustomizer> {
    virtual ~itWarioBikeCustomizer();
    virtual void onNotifyEventChangeStatus(BaseItem* item, int unk1, int unk2, void* unk3, soModuleAccesser* moduleAccesser); // TODO: Verify observer parameters
    virtual void onNotifyEventLink(BaseItem* item, void* unk1, soModuleAccesser* moduleAccesser, gfTask* task, int unk4);
    virtual bool onRemoveModelConstraint(BaseItem* item, int);
    virtual u32 getKineticFlags(BaseItem* item);

    STATIC_CHECK(sizeof(itWarioBikeCustomizer) == 12)
};

class itGokulinCustomizer : public itCustomizer<itGokulinCustomizer> {
    virtual ~itGokulinCustomizer();
    virtual void onDestruct(BaseItem* item);
    virtual void onProcessFixPosition(BaseItem* item);
    virtual void onNotifyEventChangeStatus(BaseItem* item, int unk1, int unk2, void* unk3, soModuleAccesser* moduleAccesser); // TODO: Verify observer parameters
    virtual void onNotifyEventLink(BaseItem* item, void* unk1, soModuleAccesser* moduleAccesser, gfTask* task, int unk4);
    virtual bool onEnumFighter(BaseItem* item, Fighter* fighter);

    STATIC_CHECK(sizeof(itGokulinCustomizer) == 12)
};

class itManaphyCustomizer : public itCustomizer<itManaphyCustomizer> {
    virtual ~itManaphyCustomizer();
    virtual void onDestruct(BaseItem* item);
    virtual void onProcessFixPosition(BaseItem* item);

    STATIC_CHECK(sizeof(itManaphyCustomizer) == 12)
};

class itSonansCustomizer : public itCustomizer<itSonansCustomizer> {
    virtual ~itSonansCustomizer();
    virtual void onProcessFixPosition(BaseItem* item);
    virtual void onNotifyEventCollisionAttackCheck(BaseItem* item, int);
    virtual bool onDamage(BaseItem* item, int, void*);
    virtual bool isUseSpeedDamage(BaseItem* item);
    virtual u32 getKineticFlags(BaseItem* item);

    STATIC_CHECK(sizeof(itSonansCustomizer) == 12)
};

class itDevilCustomizer : public itCustomizer<itDevilCustomizer> {
    virtual ~itDevilCustomizer();
    virtual void onConstruct(BaseItem* item);
    virtual void onDestruct(BaseItem* item);
    virtual void onProcessGameProc(BaseItem* item);
    virtual void onNotifyEventAnimCmd(BaseItem* item, acAnimCmd* acmd, soModuleAccesser* moduleAccesser, int unk3);

    STATIC_CHECK(sizeof(itDevilCustomizer) == 12)
};

class itJeffCustomizer : public itCustomizer<itJeffCustomizer> {
    virtual ~itJeffCustomizer();
    virtual void onProcessFixPosition(BaseItem* item);

    STATIC_CHECK(sizeof(itJeffCustomizer) == 12)
};

class itJeffPencilCustomizer : public itCustomizer<itJeffPencilCustomizer> {
    virtual ~itJeffPencilCustomizer();
    virtual bool onReflect(BaseItem* item);

    STATIC_CHECK(sizeof(itJeffPencilCustomizer) == 12)
};

class itHeririnCustomizer : public itCustomizer<itHeririnCustomizer> {
    virtual ~itHeririnCustomizer();
    virtual void onProcessUpdate(BaseItem* item);

    STATIC_CHECK(sizeof(itHeririnCustomizer) == 12)
};

class itKatanaAnaCustomizer : public itCustomizer<itKatanaAnaCustomizer> {
    virtual ~itKatanaAnaCustomizer();
    virtual bool onSearchTarget(BaseItem* item, int* taskId, Vec3f pos, int);

    STATIC_CHECK(sizeof(itKatanaAnaCustomizer) == 12)
};

class itLittlemacCustomizer : public itCustomizer<itLittlemacCustomizer> {
    virtual ~itLittlemacCustomizer();
    virtual bool notifyEventCollisionAttackCheck(u32 flags);

    STATIC_CHECK(sizeof(itLittlemacCustomizer) == 12)
};

class itMetroidCustomizer : public itCustomizer<itMetroidCustomizer> {
    virtual ~itMetroidCustomizer();
    virtual void onProcessFixPosition(BaseItem* item);

    STATIC_CHECK(sizeof(itMetroidCustomizer) == 12)
};

class itNintendogsHiCustomizer : public itCustomizer<itNintendogsHiCustomizer> {
    virtual ~itNintendogsHiCustomizer();
    virtual void onProcessFixPosition(BaseItem* item);
    virtual void onNotifyEventChangeStatus(BaseItem* item, int unk1, int unk2, void* unk3, soModuleAccesser* moduleAccesser); // TODO: Verify observer parameters
    virtual void onNotifyEventCollisionSearch(BaseItem* item, void*);
    virtual void onNotifyEventCollisionSearchCheck(BaseItem* item, int, u8, Vec3f*);
    virtual bool onHave(BaseItem* item, int);
    virtual bool isReferenceControlerHave(BaseItem* item);

    STATIC_CHECK(sizeof(itNintendogsHiCustomizer) == 12)
};

class itResetsanCustomizer : public itCustomizer<itResetsanCustomizer> {
    virtual ~itResetsanCustomizer();
    virtual void onConstruct(BaseItem* item);
    virtual void onReset(BaseItem* item);
    virtual void onNotifyEventAnimCmd(BaseItem* item, acAnimCmd* acmd, soModuleAccesser* moduleAccesser, int unk3);
    virtual u32 getKineticFlags(BaseItem* item);
    virtual void getFighterKind(int* fighterKind, char** fighterName, int*, int* fighterKind2, char** fighterName2, int*); // TODO: make and replace with ftKind

    STATIC_CHECK(sizeof(itResetsanCustomizer) == 12)
};

class itShadowCustomizer : public itCustomizer<itShadowCustomizer> {
    virtual ~itShadowCustomizer();
    virtual void onNotifyEventChangeStatus(BaseItem* item, int unk1, int unk2, void* unk3, soModuleAccesser* moduleAccesser); // TODO: Verify observer parameters
    virtual void onNotifyEventAnimCmd(BaseItem* item, acAnimCmd* acmd, soModuleAccesser* moduleAccesser, int unk3);

    STATIC_CHECK(sizeof(itShadowCustomizer) == 12)
};

class itTingleCustomizer : public itCustomizer<itTingleCustomizer> {
    virtual ~itTingleCustomizer();
    virtual void onDestruct(BaseItem* item);
    virtual void onProcessFixPosition(BaseItem* item);
    virtual bool onEnumFighter(BaseItem* item, Fighter* fighter);

    STATIC_CHECK(sizeof(itTingleCustomizer) == 12)
};



