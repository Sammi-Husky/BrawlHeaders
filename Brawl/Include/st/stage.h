#pragma once

#include <GX.h>
#include <StaticAssert.h>
#include <cm/cm_camera_controller.h>
#include <em/em_create.h>
#include <gf/gf_archive.h>
#include <gf/gf_task.h>
#include <gm/gm_lib.h>
#include <gr/gr_yakumono.h>
#include <if/if_smash_appear.h>
#include <it/item.h>
#include <memory.h>
#include <mt/mt_matrix.h>
#include <mt/mt_vector.h>
#include <snd/snd_3d_generator.h>
#include <st/st_collision_attr_param.h>
#include <st/st_positions.h>
#include <st/st_trigger.h>
#include <types.h>

class StageParam { // STPM
public:
    u8 m_echo;
    u8 m_id1;
    u8 m_id2;
    char _3;
    float _4;
    float _8;
    float _12;
    float _16;
    u8 m_bgmVolume;
    u8 m_sfxVolume;
    char _22;
    char _23;
    float m_shadowPitch;
    float m_shadowYaw;
    char _26[8];
    float m_camFOV;
    float m_camMinZ;
    float m_camMaxZ;
    float m_camMinTilt;
    float m_camMaxTilt;
    float m_camHorizontalRotationFactor;
    float m_camVerticalRotationFactor;
    float m_fighterBubbleBufferMultiplier;
    float _72;
    float m_cameraSpeed;
    float m_starKOCamTilt;
    float m_finalSmashCamTilt;
    float m_camRight;
    float m_camLeft;
    Vec3f m_pauseCamCenterPos;
    float m_pauseCamAngle;
    float m_pauseCamZoomIn;
    float m_pauseCamZoomDefault;
    float m_pauseCamZoomOut;
    float m_pauseCamRotYMin;
    float m_pauseCamRotYMax;
    float m_pauseCamRotXMin;
    float m_pauseCamRotXMax;
    Vec3f m_fixedCamCenterPos;
    float m_fixedCamFOV;
    float m_fixedHorizontalAngle;
    float m_fixedVerticalAngle;
    char _164[4];
    float m_olimarFinalCamAngle;
    Vec3f m_iceClimbersFinalPos;
    Vec2f m_iceClimbersFinalScale;
    Vec2f m_pitFinalPalutenaScale;
    u8 m_kirifudaModelType;
    bool m_characterWindEnabled;
    char _202[2];
    float m_windStrength;
    float m_horizontalWindRotation;
    float m_verticalWindRotation;
    float _216;
    GXColor _220;
    char _224[4];
    bool _228;
    bool _229;
    u8 m_effectVol;
    u8 m_reverbLPF;
    u8 m_reverbType;
    u8 m_reverbColoration;
    u8 m_reverbDamping;
    u8 m_reverbPreDelay;
    u8 m_reverbBalance;
    u8 m_delayFeedback;
    u8 m_delayOutput;
    char _239;
    s16 m_reverbTime;
    u16 m_delayTime;
    char _244[16];
};
static_assert(sizeof(StageParam) == 260, "Class is wrong size!");

class Stage : public gfTask {
public:
    // 0
    char _spacer[0x04];
    // 4
    srStageKind m_stageKind;
    // 8
    char _spacer1[0x10];
    // 18
    Rect2D m_deadRange;
    // 28
    Rect2D m_aiRange;
    // 38
    cmStageParam* m_cameraParam1;
    // 3c
    char _3c[0x4];
    // 40
    cmStageParam* m_cameraParam2;
    // 44
    char _spacer2[4];
    // 48
    Ground* m_headGround;
    // 4c
    void* m_collConv;
    // 50
    stPositions* m_stagePositions;
    // 54
    char _spacer3[4];
    // 58
    StageParam* m_stageParam;
    // 5C
    void* m_stageData;
    // 60
    stTriggerMng* m_triggerMng;
    // 64
    char _spacer4[0x18];
    // 7C
    u32 m_unk;
    // 80
    char _spacer5[0x38];
    // B8
    char collisionAttrs[0xC];
    // C4
    gfArchive m_archive;
    // 144
    bool m_unk2;
    // 145
    char _spacer6[3];
    // 148
    u32 m_unk3;
    // 14C
    float m_unk4;
    // 150
    float m_frameRuleTime;
    // 154
    char _spacer7[0xC];
    // TOTAL_SIZE == 0x160

    void testStageParamInit(gfArchive* archive, int fileIndex);
    void testStageDataInit(gfArchive* archive, int fileIndex, int unk2);
    void addGround(Ground* Ground);
    Ground* getGround(int index);
    u32 getGroundNum();
    grCollision* createCollision(gfArchive* archive, int index, Ground* ground);
    void createStagePositions();
    void createStagePositions(nw4r::g3d::ResFile* resFile);
    void loadStageAttrParam(gfArchive* filedata, int fileIndex);
    void registScnAnim(nw4r::g3d::ResFileData* scnData, u32 index);
    void initPosPokeTrainer(int unk1, int unk2);
    void setStageAttackData(grGimmickDamageFloor* attackData, u32 index);
    void removeGround(Ground*);

    Stage(const char* name, srStageKind stageKind);
    virtual void processBegin();
    virtual void processAnim();
    virtual void processUpdate();
    virtual void processMapCorrection();
    virtual void processFixCamera();
    virtual void processEnd();
    virtual void renderPre();
    virtual void renderDebug();
    virtual ~Stage();

    virtual void createObj();
    virtual void createObjPokeTrainer(gfArchive* filedata, int fileindex, const char* name, int unk1, int unk2);
    virtual int getPokeTrainerPointNum() { return 0; }
    virtual void getPokeTrainerPointData(int* unk1, int unk2) {}
    virtual float getPokeTrainerPositionZ() { return 0.0f; }
    virtual int getPokeTrainerDrawLayer() { return 0; }
    virtual bool isAdventureStage() { return false; }
#ifdef MATCHING
    virtual void getItemPac(gfArchive** brres, gfArchive** param, itKind itemID, int variantID);
#else
    virtual void getItemPac(gfArchive** brres, gfArchive** param, itKind itemID, int variantID, gfArchive** commonParam = NULL, itCustomizerInterface** customizer = NULL); // Note: Optional parameters for modding purposes to use custom itmParams and customizers
#endif
    virtual void getItemGenPac(gfArchive** archive);
    virtual void getItemPacEnemyFigure(gfArchive** archive);
    virtual void getEnemyPac(gfArchive** brres, gfArchive** param, gfArchive** enmCommon, gfArchive** primFaceBrres, EnemyKind enemyKind);
    virtual void getAdvRadarData(gfArchive**, gfArchive**);
    virtual void initializeStage();
    virtual void closeStage();
    virtual void renderDebugPositions();
    virtual bool loading();
    virtual void process();
    virtual void updateStagePositions();
    virtual void debugCollision();
    virtual Rect2D* getAIRange() { return &m_aiRange; }
    virtual int getDefaultLightSetIndex() { return 0x14; }
    virtual int getZoneLightSetIndex();
    virtual int getScrollDir(Vec3f* unk1)
    {
        unk1->m_x = 0.0f;
        unk1->m_y = 0.0f;
        unk1->m_z = 0.0f;
        return 0;
    }
    virtual void clearCameraParam();
    virtual void initCameraParam();
    virtual void startLoadLocalData();
    virtual bool isLoadLocalData();
    virtual int entryLocalData();
    virtual void removeLocalData();
    virtual void appearanceFighterLocal() {}
    virtual void getFighterStartPos(Vec3f* startPos, int fighterIndex);
    virtual void getFighterReStartPos(Vec3f* startPos, int fighterIndex);
    virtual bool isReStartSamePoint();
    virtual void getPokeTrainerStartPos(Vec3f* pos, u32);
    virtual u8 getItemPosCount();
    virtual void getItemPos(Vec3f*, Vec3f*, u32 index);
    virtual void getRandItemPos(Vec3f* pos);
    virtual void getKirifudaPos(Vec3f* pos, u32);
    virtual float getKirifudaAngle(u32);
    virtual void getKirifudaScale(Vec3f* scale, u32);
    virtual u8 getKirifudaModelType(u32);
    virtual u8 getPokeTrainerPosCount();
    virtual void getPokeTrainerPos(Vec3f*, Vec3f*, u32 index);
    virtual float getFighterDeadEffectSizeRate();
    virtual float getEnemyDeadEffectSizeRate();
    virtual float getEnableZ();
    virtual int getBgmID() { return 0; }
    virtual int getBgmID() const { return 0; }
    virtual int getNowStepBgmID() { return 0; }
    virtual int getBgmOptionID() { return 0; }
    virtual bool isBgmChange() { return m_unk2; }
    virtual void getBgmChangeID(u32* unk1, float* unk2)
    {
        *unk1 = m_unk3;
        *unk2 = m_unk4;
    }
    virtual void setBgmChange(float unk1, bool unk2, u32 unk3)
    {
        m_unk2 = unk2;
        m_unk3 = unk3;
        m_unk4 = unk1;
    }
    virtual float getBgmVolume() { return 1.0f; }
    virtual float getBgmPlayOffsetFrame() { return 0.0f; }
    virtual bool isNextStepBgmEqualNowStepBgmFromFlag() { return false; }
    virtual void setFrameRuleTime(float unk1) { m_frameRuleTime = unk1; }
    virtual float getFrameRuleTime() { return m_frameRuleTime; }
    virtual void notifyTimmingGameStart() {}
    virtual bool isEnd();
    virtual bool isEventEnd();
    virtual void enableDevil();
    virtual void disableDevil();
    virtual bool isDevil();
    virtual void setDevilScrool(float unk1, float unk2);     // TODO
    virtual void getLucarioFinalTechniquePosition(int unk1); // TODO
    virtual bool startAppear();                              // TODO
    virtual void setAppearKind(u8 kind);                     // TODO
    virtual void endAppear();                                // TODO
    virtual IfSmashAppearTask* getAppearTask();              // TODO
    virtual void forceStopAppear();                          // TODO
    virtual int getFinalTechniqColor();                      // TODO
    virtual void setMotionRatio(float unk1, float unk2);     // TODO
    virtual void saveMotionRatio(int unk1);                  // TODO
    virtual void restoreMotionRatio(int unk1);               // TODO
    virtual void setMotionSubRatio(float unk1, float unk2);  // TODO
    virtual void saveMotionSubRatio(int unk1);               // TODO
    virtual void restoreMotionSubRatio(int unk1);            // TODO
    virtual bool isCameraLocked() { return true; }
    virtual bool isBossBattleMode() { return false; }
    virtual bool isSimpleBossBattleMode() { return false; }
    virtual bool isAppear();             // TODO
    virtual s32 isStartAppearTimming();  // TODO
    virtual void getMadeinAiData();      // TODO
    virtual bool isBamperVector();       // TODO
    virtual void getBamperVector(int unk1);
    virtual void notifyEventInfoReady();                           // TODO
    virtual void notifyEventInfoGo();                              // TODO
    virtual void getDestroyBossParamCommon();                      // TODO
    virtual void stAdventureEventGetItem(int entryId, itKind kind, int itVariation, int genParamId, int instanceId);
    virtual void setStageOutEffectInit();                          // TODO
    virtual void setStageInEffectInit();                           // TODO
    virtual int helperStarWarp() { return 0; }
    virtual int initializeFighterAttackRatio() { return 0; }
    virtual void startFighterEvent() {}
    virtual int getZoneState(); // TODO
    virtual void getZonePos(Vec3f* pos);
    virtual float getMagmaHeight();   // TODO
    virtual float getAcidHeight();    // TODO
    virtual u8 getIteamDropStatus();
    virtual bool createWind2ndOnly();
    virtual grGimmickWindData2nd* getWind2ndOnlyData(); // TODO
    virtual void updateWind2ndOnly();                   // TODO
    virtual void setVision(u8);
};

enum ItemOverrideSetting {
    ItemOverride_None = 0x0,
    ItemOverride_Brres = 0x1,
    ItemOverride_Param = 0x2,
    ItemOverride_Both = 0x3,
};

struct ItemOverride { // Custom Misc Data node
    char _header[4];
    char m_itmOverrideName[12];
    char m_pkmOverrideName[12];
    s8 m_pokemonOverload;
    ItemOverrideSetting m_overrideCommon : 8;
    ItemOverrideSetting m_overrideTorchic : 8;
    ItemOverrideSetting m_overrideCelebi : 8;
    ItemOverrideSetting m_overrideChikorita : 8;
    ItemOverrideSetting m_overrideChikoritaShot : 8;
    ItemOverrideSetting m_overrideEntei : 8;
    ItemOverrideSetting m_overrideMoltres : 8;
    ItemOverrideSetting m_overrideMunchlax : 8;
    ItemOverrideSetting m_overrideDeoxys : 8;
    ItemOverrideSetting m_overrideGroudon : 8;
    ItemOverrideSetting m_overrideGulpin : 8;
    ItemOverrideSetting m_overrideStaryu: 8;
    ItemOverrideSetting m_overrideStaryuShot : 8;
    ItemOverrideSetting m_overrideHoOh : 8;
    ItemOverrideSetting m_overrideHoOhShot : 8;
    ItemOverrideSetting m_overrideJirachi : 8;
    ItemOverrideSetting m_overrideSnorlax : 8;
    ItemOverrideSetting m_overrideBellosom : 8;
    ItemOverrideSetting m_overrideKyogre : 8;
    ItemOverrideSetting m_overrideKyogreShot : 8;
    ItemOverrideSetting m_overrideLatiasLatios : 8;
    ItemOverrideSetting m_overrideLugia : 8;
    ItemOverrideSetting m_overrideLugiaShot : 8;
    ItemOverrideSetting m_overrideManaphy : 8;
    ItemOverrideSetting m_overrideWeavile : 8;
    ItemOverrideSetting m_overrideElectrode : 8;
    ItemOverrideSetting m_overrideMetagross : 8;
    ItemOverrideSetting m_overrideMew : 8;
    ItemOverrideSetting m_overrideMeowth : 8;
    ItemOverrideSetting m_overrideMeowthShot : 8;
    ItemOverrideSetting m_overridePiplup : 8;
    ItemOverrideSetting m_overrideTogepi : 8;
    ItemOverrideSetting m_overrideGoldeen : 8;
    ItemOverrideSetting m_overrideGardevoir : 8;
    ItemOverrideSetting m_overrideWobbuffet : 8;
    ItemOverrideSetting m_overrideSuicune : 8;
    ItemOverrideSetting m_overrideBonsly : 8;
    ItemOverrideSetting m_overrideAndross : 8;
    ItemOverrideSetting m_overrideAndrossShot : 8;
    ItemOverrideSetting m_overrideBarbara : 8;
    ItemOverrideSetting m_overrideGrayFox : 8;
    ItemOverrideSetting m_overrideRayMKII : 8;
    ItemOverrideSetting m_overrideRayMKIIBomb : 8;
    ItemOverrideSetting m_overrideRayMKIIGun : 8;
    ItemOverrideSetting m_overrideSamuraiGoroh : 8;
    ItemOverrideSetting m_overrideDevil : 8;
    ItemOverrideSetting m_overrideExcitebike : 8;
    ItemOverrideSetting m_overrideJeff : 8;
    ItemOverrideSetting m_overrideJeffPencilBullet : 8;
    ItemOverrideSetting m_overrideJeffPencilRocket : 8;
    ItemOverrideSetting m_overrideLakitu : 8;
    ItemOverrideSetting m_overrideKnuckleJoe : 8;
    ItemOverrideSetting m_overrideKnuckleJoeShot : 8;
    ItemOverrideSetting m_overrideHammerBro : 8;
    ItemOverrideSetting m_overrideHammerBroHammer : 8;
    ItemOverrideSetting m_overrideHelirin : 8;
    ItemOverrideSetting m_overrideKat : 8;
    ItemOverrideSetting m_overrideAna : 8;
    ItemOverrideSetting m_overrideJillDozer : 8;
    ItemOverrideSetting m_overrideLyn : 8;
    ItemOverrideSetting m_overrideLittleMac : 8;
    ItemOverrideSetting m_overrideMetroid : 8;
    ItemOverrideSetting m_overrideNintendog : 8;
    ItemOverrideSetting m_overrideNintendogFull : 8;
    ItemOverrideSetting m_overrideMrResetti : 8;
    ItemOverrideSetting m_overrideIsaac : 8;
    ItemOverrideSetting m_overrideIsaacShot : 8;
    ItemOverrideSetting m_overrideSaki : 8;
    ItemOverrideSetting m_overrideSakiShot1 : 8;
    ItemOverrideSetting m_overrideSakiShot2 : 8;
    ItemOverrideSetting m_overrideShadow : 8;
    ItemOverrideSetting m_overrideWarInfantry : 8;
    ItemOverrideSetting m_overrideWarInfantryShot : 8;
    ItemOverrideSetting m_overrideStarfy : 8;
    ItemOverrideSetting m_overrideWarTank : 8;
    ItemOverrideSetting m_overrideWarTankShot : 8;
    ItemOverrideSetting m_overrideTingle : 8;
    ItemOverrideSetting m_overrideLakituSpiny : 8;
    ItemOverrideSetting m_overrideWaluigi : 8;
    ItemOverrideSetting m_overrideDrWright : 8;
    ItemOverrideSetting m_overrideDrWrightBuilding : 8;
    char m_stageItemFolder[12];
};