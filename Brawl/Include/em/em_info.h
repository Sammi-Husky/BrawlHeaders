#pragma once

#include <StaticAssert.h>
#include <em/em_create.h>
#include <em/enemy.h>
#include <so/so_info.h>
#include <types.h>

class emInfo : public soInfo {
public:
    typedef Enemy* (*CreateEnemyFunc_t)(u32, emCreate*);
    typedef void (*ModifyExParamFunc_t)(emResourceModuleImpl* p1, emCreate const* p2);
    typedef void (*DeleteExParamFunc_t)();
    static const u32 NumEnemies = 61;
private:
    static const u32 NodeNumTable[NumEnemies];
    static const u32 MotionNumTable[NumEnemies];
    static const u32 StatusNumTable[NumEnemies];
    static const u32 KineticEnergyNumTable[NumEnemies];
    static const u32 KineticEnergyParamAryPtrGetIdTable[NumEnemies];
    static const u32 AreaNumTable[NumEnemies];
    static const u32 AreaParamAryPtrGetIdTable[NumEnemies];
    static const u32 TargetSearchNumTable[NumEnemies];
    static const u32 TargetSearchParamAryPtrGetIdTable[NumEnemies];
    static const u32 AINumTable[NumEnemies];
    static const u32 SEIdTable[NumEnemies];
    static const u32 StandByStatusKindTable[NumEnemies];
public:
    static CreateEnemyFunc_t CreateFuncPtrTable[NumEnemies];
    static ModifyExParamFunc_t ModifyExParamFuncPtrTable[NumEnemies];
    static DeleteExParamFunc_t DeleteExParamFuncPtrTable[NumEnemies];

    static emInfo* getInstance();

    emInfo();
    virtual ~emInfo();
    virtual u32 isInvalidKind(s32 index);
    virtual s32 getInvalidKind();
    virtual const char* getNamePtr();
    virtual u32 getMotionNum(u32 index);
    virtual u32 getStatusNum(u32 index);
    u32 isPrimKind(s32 index);
    u32 getNodeNum(u32 index);
    u32 getKineticEnergyNum(u32 index);
    u32 getKineticEnergyParamAryPtrGetId(u32 index);
    u32 getAreaNum(u32 index);
    u32 getAreaParamAryPtrGetId(u32 index);
    u32 getTargetSearchNum(u32 index);
    u32 getTargetSearchParamAryPtrGetId(u32 index);
    u32 getAINum(u32 index);
    CreateEnemyFunc_t getCreateFuncPtr(s32 index);
    ModifyExParamFunc_t getExParamModifyFuncPtr(s32 index);
    DeleteExParamFunc_t getExParamDeleteFuncPtr(s32 index);
    u32 getSEId(u32 index);
    u32 StandByStatusKind(u32 index);
};
static_assert(sizeof(emInfo) == 0x4, "Class has the wrong size!");

extern emInfo g_emInfo;
