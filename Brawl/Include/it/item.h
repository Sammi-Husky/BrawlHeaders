#pragma once

#include <types.h>
#include <StaticAssert.h>
#include <so/stageobject.h>
#include <so/so_article.h>

enum itKind {
    Item_AssistTrophy = 0x00,
    Item_FranklinBadge = 0x01,
    Item_BananaPeel = 0x02,
    Item_Barrel = 0x03,
    Item_BeamSword = 0x04,
    Item_Bill = 0x05,
    Item_BobOmb = 0x06,
    Item_Crate = 0x07,
    Item_Bumper = 0x08,
    Item_Capsule = 0x09,
    Item_RollingCrate = 0x0A,
    Item_CD = 0x0B,
    Item_GooeyBomb = 0x0C,
    Item_CrackerLauncher = 0x0D,
    Item_CrackerLauncher_Shot = 0x0E,
    Item_Coin = 0x0F,
    Item_SuperspicyCurry = 0x10,
    Item_SuperspicyCurry_Shot = 0x11,
    Item_DekuNut = 0x12,
    Item_MrSaturn = 0x13,
    Item_Dragoon_Part = 0x14,
    Item_Dragoon_Set = 0x15,
    Item_Dragoon_Sight = 0x16,
    Item_Trophy = 0x17,
    Item_FireFlower = 0x18,
    Item_FireFlower_Shot = 0x19,
    Item_Freezie = 0x1A,
    Item_GoldenHammer = 0x1B,
    Item_GreenShell = 0x1C,
    Item_Hammer = 0x1D,
    Item_Hammer_Head = 0x1E,
    Item_Fan = 0x1F,
    Item_HeartContainer = 0x20,
    Item_HomerunBat = 0x21,
    Item_PartyBall = 0x22,
    Item_Manaphy_Heart = 0x23,
    Item_MaximTomato = 0x24,
    Item_PoisonMushroom = 0x25,
    Item_SuperMushroom = 0x26,
    Item_MetalBox = 0x27,
    Item_Hothead = 0x28,
    Item_Pitfall = 0x29,
    Item_Pokeball = 0x2A,
    Item_BlastBox = 0x2B,
    Item_RayGun = 0x2C,
    Item_RayGun_Shot = 0x2D,
    Item_Lipstick = 0x2E,
    Item_Lipstick_Flower = 0x2F,
    Item_Lipstick_ShotDustPowder = 0x30,
    Item_Sandbag = 0x31,
    Item_ScrewAttack = 0x32,
    Item_Sticker = 0x33,
    Item_MotionSensorBomb = 0x34,
    Item_Timer = 0x35,
    Item_SmartBomb = 0x36,
    Item_SmashBall = 0x37,
    Item_SmokeScreen = 0x38,
    Item_Spring = 0x39,
    Item_StarRod = 0x3A,
    Item_StarRod_Shot = 0x3B,
    Item_SoccerBall = 0x3C,
    Item_SuperScope = 0x3D,
    Item_SuperScope_Shot = 0x3E,
    Item_Star = 0x3F,
    Item_Food = 0x40,
    Item_TeamHealer = 0x41,
    Item_Lightning = 0x42,
    Item_Unira = 0x43,
    Item_BunnyHood = 0x44,
    Item_WarpStar = 0x45,
    Item_SSE_Trophy = 0x46,
    Item_SSE_Key = 0x47,
    Item_SSE_TrophyStand = 0x48,
    Item_SSE_StockBall = 0x49,
    Item_GreenGreens_Apple = 0x4A,
    Item_MarioBros_Sidestepper = 0x4B,
    Item_MarioBros_Shellcreeper = 0x4C,
    Item_DistantPlanet_Pellet = 0x4D,
    Item_Summit_Vegetable = 0x4E,
    Item_Homerun_Sandbag = 0x4F,
    Item_Enemy_Auroros = 0x50,
    Item_Enemy_Koopa1 = 0x51,
    Item_Enemy_Koopa2 = 0x52,
    Item_Snake_Box = 0x53,
    Item_Diddy_Peanut = 0x54,
    Item_Link_Bomb = 0x55,
    Item_Peach_Turnip = 0x56,
    Item_ROB_Gyro = 0x57,
    Item_Diddy_Peanut_Seed = 0x58,
    Item_Snake_Grenade = 0x59,
    Item_Samus_ArmorPiece = 0x5A,
    Item_ToonLink_Bomb = 0x5B,
    Item_Wario_Bike = 0x5C,
    Item_Wario_Bike_A = 0x5D,
    Item_Wario_Bike_B = 0x5E,
    Item_Wario_Bike_C = 0x5F,
    Item_Wario_Bike_D = 0x60,
    Item_Wario_Bike_E = 0x61,
    Item_Pokemon_Torchic = 0x62,
    Item_Pokemon_Cerebi = 0x63,
    Item_Pokemon_Chickorita = 0x64,
    Item_Pokemon_Chickorita_Shot = 0x65,
    Item_Pokemon_Entei = 0x66,
    Item_Pokemon_Moltres = 0x67,
    Item_Pokemon_Munchlax = 0x68,
    Item_Pokemon_Deoxys = 0x69,
    Item_Pokemon_Groudon = 0x6A,
    Item_Pokemon_Gulpin = 0x6B,
    Item_Pokemon_Staryu = 0x6C,
    Item_Pokemon_Staryu_Shot = 0x6D,
    Item_Pokemon_HoOh = 0x6E,
    Item_Pokemon_HoOh_Shot = 0x6F,
    Item_Pokemon_Jirachi = 0x70,
    Item_Pokemon_Snorlax = 0x71,
    Item_Pokemon_Bellossom = 0x72,
    Item_Pokemon_Kyogre = 0x73,
    Item_Pokemon_Kyogre_Shot = 0x74,
    Item_Pokemon_LatiasLatios = 0x75,
    Item_Pokemon_Lugia = 0x76,
    Item_Pokemon_Lugia_Shot = 0x77,
    Item_Pokemon_Manaphy = 0x78,
    Item_Pokemon_Weavile = 0x79,
    Item_Pokemon_Electrode = 0x7A,
    Item_Pokemon_Metagross = 0x7B,
    Item_Pokemon_Mew = 0x7C,
    Item_Pokemon_Meowth = 0x7D,
    Item_Pokemon_Meowth_Shot = 0x7E,
    Item_Pokemon_Piplup = 0x7F,
    Item_Pokemon_Togepi = 0x80,
    Item_Pokemon_Goldeen = 0x81,
    Item_Pokemon_Gardevoir = 0x82,
    Item_Pokemon_Wobuffet = 0x83,
    Item_Pokemon_Suicune = 0x84,
    Item_Pokemon_Bonsly = 0x85,
    Item_Assist_Andross = 0x86,
    Item_Assist_Andross_Shot = 0x87,
    Item_Assist_Barbara = 0x88,
    Item_Assist_GrayFox = 0x89,
    Item_Assist_RayMKII = 0x8A,
    Item_Assist_RayMKII_Bomb = 0x8B,
    Item_Assist_RayMKII_GunShot = 0x8C,
    Item_Assist_SamuraiGoroh = 0x8D,
    Item_Assist_Devil = 0x8E,
    Item_Assist_Excitebike = 0x8F,
    Item_Assist_Jeff = 0x90,
    Item_Assist_Jeff_PencilBullet = 0x91,
    Item_Assist_Jeff_PencilRocket = 0x92,
    Item_Assist_Lakitu = 0x93,
    Item_Assist_KnuckleJoe = 0x94,
    Item_Assist_KnuckleJoe_Shot = 0x95,
    Item_Assist_HammerBro = 0x96,
    Item_Assist_HammerBro_Hammer = 0x97,
    Item_Assist_Helirin = 0x98,
    Item_Assist_KatAna = 0x99,
    Item_Assist_KatAna_Ana = 0x9A,
    Item_Assist_JillDozer = 0x9B,
    Item_Assist_Lyn = 0x9C,
    Item_Assist_LittleMac = 0x9D,
    Item_Assist_Metroid = 0x9E,
    Item_Assist_Nintendog = 0x9F,
    Item_Assist_Nintendog_Full = 0xA0,
    Item_Assist_MrResetti = 0xA1,
    Item_Assist_Isaac = 0xA2,
    Item_Assist_Isaac_Shot = 0xA3,
    Item_Assist_Saki = 0xA4,
    Item_Assist_Saki_Shot1 = 0xA5,
    Item_Assist_Saki_Shot2 = 0xA6,
    Item_Assist_Shadow = 0xA7,
    Item_Assist_War_Infantry = 0xA8,
    Item_Assist_War_Infantry_Shot = 0xA9,
    Item_Assist_Stafy = 0xAA,
    Item_Assist_War_Tank = 0xAB,
    Item_Assist_War_Tank_Shot = 0xAC,
    Item_Assist_Tingle = 0xAD,
    Item_Assist_Lakitu_Spiny = 0xAE,
    Item_Assist_Waluigi = 0xAF,
    Item_Assist_DrWright = 0xB0,
    Item_Assist_DrWright_Building = 0xB1,
    Item_Unknown1 = 0x7D1,
    Item_Unknown2 = 0x7D2,
    Item_Unknown3 = 0x7D3,
    Item_Unknown4 = 0x7D4,
    Item_Unknown5 = 0x7D5
};

class BaseItem : public StageObject, public soStatusEventObserver, public soSituationEventObserver,
        public soCollisionAttackEventObserver, public soCollisionShieldEventObserver, public soCollisionReflectorEventObserver,
        public soCollisionSearchEventObserver, public soGimmickEventObserver, public soArticle {
    soModuleAccesser moduleAccesser;
    char _spacer[15284];

public:
    virtual void processUpdate();
    virtual void processMapCorrection();
    virtual void processFixPosition();
    virtual void processHit();
    virtual void processFixCamera();
    virtual void processGameProc();
    virtual void renderPre();
    virtual void renderDebug();
    virtual ~BaseItem();

    // TODO: Verify parameters
    virtual void reset(float, float*);
    virtual void remove();
    virtual int getArticleId();
    virtual int getArticleEventManageId();
    virtual int getTaskId();
    virtual void linkOwner(int,int);
    virtual void unlinkOwner(int);
    virtual bool isActiveArticle();
    virtual void deactivateArticle();
    virtual void changeMotion(int,int);
    virtual void changeStatus(int actionID);
    virtual void setVisibilityWhole(u8);
    virtual void setVisibilityWholeForce(u8);
    virtual u8 getVisibilityWhole();
    virtual void setSituationKind(int);
    virtual bool isConstraint();
    virtual void setConstraintTargetNode(int);
    virtual bool isSyncOwnerStatus();
    virtual void setSyncOwnerStatus(int);
    virtual void setAttackPowerMulPattern(float);
    virtual void setArticleId(int articleId);
    virtual void setLogAttackInfo(soLogAttackInfo* logAttackInfo);
    virtual soLogAttackInfo getLogAttackInfo();
    virtual void updateLogAttackInfo();
    virtual void deactivate();
    virtual void have(int, int, int);
    virtual void action(int);
    virtual void setGlowAttack(int glowAttack);
    virtual int getGlowAttack();
    virtual void notifyEventChangeStatus(int unk1, int unk2, void* unk3, soModuleAccesser* moduleAccesser);
    virtual void notifyEventChangeSituation(int unk1, int unk2, soModuleAccesser* moduleAccesser);
    virtual void notifyEventCollisionAttack(void* unk1, void* unk2, soModuleAccesser* moduleAccesser);
    virtual bool notifyEventCollisionAttackCheck(u32 flags);
    virtual void notifyEventCollisionShield(float, float, float, void*, void*, int, soModuleAccesser* moduleAccesser);
    virtual void notifyEventCollisionShieldSearch(void*, void*);
    virtual bool notifyEventCollisionShieldCheck();
    virtual void notifyEventCollisionReflector(float, float, float, void*, void*, int, soModuleAccesser* moduleAccesser); // TODO: This is a guess based on above
    virtual void notifyEventCollisionReflectorSearch(int,int,int);
    virtual bool notifyEventCollisionReflectorCheck();
    virtual void notifyEventCollisionSearch(void*, soModuleAccesser* moduleAccesser);
    virtual bool notifyEventCollisionSearchCheck();
    virtual void notifyEventInfoWindow(int);
    virtual void notifyEventGimmick(soGimmickEventInfo *eventInfo,int *taskId);
    virtual void presentEventGimmick(soGimmickEventInfo* eventInfo, int sendID);
    virtual void onDamage(int, void*);
    virtual bool isUseTurnDamage();
    virtual bool isUseSpeedDamage();
    virtual bool isUseShake();

    int getParam(unsigned int param);
    float getParam(int param);
    float getParamFloat(unsigned int param);

    void warp(Vec3f* pos);
    void setVanishMode(bool);


    STATIC_CHECK(sizeof(BaseItem) == 0x3d60)
};