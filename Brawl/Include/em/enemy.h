#pragma once

#include <StaticAssert.h>
#include <em/em_create.h>
#include <gr/gr_gimmick_motion_path.h>
#include <memory.h>
#include <so/stageobject.h>
#include <types.h>

class Enemy : public StageObject, public soStatusEventObserver, public soCollisionAttackEventObserver, public soCollisionSearchEventObserver, public soCaptureEventObserver, public soCollisionAbsorberEventObserver, public soCollisionReflectorEventObserver {

    EnemyKind m_enemyKind;
    char _176[4];
    int m_connectedTriggerId;
    u32 m_difficulty;
    u32 m_level;
    char _192[8];
    grGimmickMotionPath* m_motionPath;
    char _204[16];
    soModuleAccesser moduleAccesser;
    char _444[20820];

    // TODO: virtual functions
public:
    template<typename T>
    static Enemy* createInstance(u32 p1, emCreate* create) {
        return new (Heaps::EnemyInstance) T(p1, create);
    }
};
static_assert(sizeof(Enemy) == 0x5310, "Class is wrong size!");

class emKuribo : public Enemy {
    u8 unk5310[0xa14];
public:
    emKuribo(u32 p1, emCreate* create);
    virtual ~emKuribo();
    // TODO: emKuribo virtual functions
};
static_assert(sizeof(emKuribo) == 0x5d24, "Class is wrong size!");

struct emKuriboParam {

};

class emPopperam : public Enemy {
    u8 unk5310[0x938];
public:
    emPopperam(u32 p1, emCreate* create);
    virtual ~emPopperam();
    // TODO: emPopperam virtual functions
};
static_assert(sizeof(emPopperam) == 0x5c48, "Class is wrong size!");

struct emPopperamParam {

};

class emPacci : public Enemy {
    u8 unk5310[0xda8];
public:
    emPacci(u32 p1, emCreate* create);
    virtual ~emPacci();
    // TODO: emPacci virtual functions
};
static_assert(sizeof(emPacci) == 0x60b8, "Class is wrong size!");

struct emPacciParam {

};

class emJyakeel : public Enemy {
    u8 unk5310[0x424];
public:
    emJyakeel(u32 p1, emCreate* create);
    virtual ~emJyakeel();
    // TODO: emJyakeel virtual functions
};
static_assert(sizeof(emJyakeel) == 0x5734, "Class is wrong size!");

struct emJyakeelParam {

};

class emAroaros : public Enemy {
    u8 unk5310[0xa6c];
public:
    emAroaros(u32 p1, emCreate* create);
    virtual ~emAroaros();
    // TODO: emAroaros virtual functions
};
static_assert(sizeof(emAroaros) == 0x5d7c, "Class is wrong size!");

struct emAroarosParam {

};

class emCymal : public Enemy {
    u8 unk5310[0x5a8];
public:
    emCymal(u32 p1, emCreate* create);
    virtual ~emCymal();
    // TODO: emCymal virtual functions
};
static_assert(sizeof(emCymal) == 0x58b8, "Class is wrong size!");

struct emCymalParam {

};

class emDeathpod : public Enemy {
    u8 unk5310[0x7ec];
public:
    emDeathpod(u32 p1, emCreate* create);
    virtual ~emDeathpod();
    // TODO: emDeathpod virtual functions
};
static_assert(sizeof(emDeathpod) == 0x5afc, "Class is wrong size!");

struct emDeathpodParam {

};

class emBoobas : public Enemy {
    u8 unk5310[0xa14];
public:
    emBoobas(u32 p1, emCreate* create);
    virtual ~emBoobas();
    // TODO: emBoobas virtual functions
};
static_assert(sizeof(emBoobas) == 0x5d24, "Class is wrong size!");

struct emBoobasParam {

};

class emDekakuribo : public Enemy {
    u8 unk5310[0x9a8];
public:
    emDekakuribo(u32 p1, emCreate* create);
    virtual ~emDekakuribo();
    // TODO: emDekakuribo virtual functions
};
static_assert(sizeof(emDekakuribo) == 0x5cb8, "Class is wrong size!");

struct emDekakuriboParam {

};

class emBotron : public Enemy {
    u8 unk5310[0x918];
public:
    emBotron(u32 p1, emCreate* create);
    virtual ~emBotron();
    // TODO: emBotron virtual functions
};
static_assert(sizeof(emBotron) == 0x5c28, "Class is wrong size!");

struct emBotronParam {

};

class emBucyulus : public Enemy {
    u8 unk5310[0x76c];
public:
    emBucyulus(u32 p1, emCreate* create);
    virtual ~emBucyulus();
    // TODO: emBucyulus virtual functions
};
static_assert(sizeof(emBucyulus) == 0x5a7c, "Class is wrong size!");

struct emBucyulusParam {

};

class emGyraan : public Enemy {
    u8 unk5310[0x4f3c];
public:
    emGyraan(u32 p1, emCreate* create);
    virtual ~emGyraan();
    // TODO: emGyraan virtual functions
};
static_assert(sizeof(emGyraan) == 0xa24c, "Class is wrong size!");

struct emGyraanParam {

};

class emSiralamos : public Enemy {
    u8 unk5310[0x5364];
public:
    emSiralamos(u32 p1, emCreate* create);
    virtual ~emSiralamos();
    // TODO: emSiralamos virtual functions
};
static_assert(sizeof(emSiralamos) == 0xa674, "Class is wrong size!");

struct emSiralamosParam {

};

class emKiller : public Enemy {
    u8 unk5310[0x734];
public:
    emKiller(u32 p1, emCreate* create);
    virtual ~emKiller();
    // TODO: emKiller virtual functions
};
static_assert(sizeof(emKiller) == 0x5a44, "Class is wrong size!");

struct emKillerParam {

};

class emRoada : public Enemy {
    u8 unk5310[0x77c];
public:
    emRoada(u32 p1, emCreate* create);
    virtual ~emRoada();
    // TODO: emRoada virtual functions
};
static_assert(sizeof(emRoada) == 0x5a8c, "Class is wrong size!");

struct emRoadaParam {

};

class emSpar : public Enemy {
    u8 unk5310[0xc0c];
public:
    emSpar(u32 p1, emCreate* create);
    virtual ~emSpar();
    // TODO: emSpar virtual functions
};
static_assert(sizeof(emSpar) == 0x5f1c, "Class is wrong size!");

struct emSparParam {

};

class emMite : public Enemy {
    u8 unk5310[0x7d4];
public:
    emMite(u32 p1, emCreate* create);
    virtual ~emMite();
    // TODO: emMite virtual functions
};
static_assert(sizeof(emMite) == 0x5ae4, "Class is wrong size!");

struct emMiteParam {

};

class emTeckin : public Enemy {
    u8 unk5310[0xa24];
public:
    emTeckin(u32 p1, emCreate* create);
    virtual ~emTeckin();
    // TODO: emTeckin virtual functions
};
static_assert(sizeof(emTeckin) == 0x5d34, "Class is wrong size!");

struct emTeckinParam {

};

class emTautau : public Enemy {
    u8 unk5310[0xb0c];
public:
    emTautau(u32 p1, emCreate* create);
    virtual ~emTautau();
    // TODO: emTautau virtual functions
};
static_assert(sizeof(emTautau) == 0x5e1c, "Class is wrong size!");

struct emTautauParam {

};

class emHammerbros : public Enemy {
    u8 unk5310[0xb94];
public:
    emHammerbros(u32 p1, emCreate* create);
    virtual ~emHammerbros();
    // TODO: emHammerbros virtual functions
};
static_assert(sizeof(emHammerbros) == 0x5ea4, "Class is wrong size!");

struct emHammerbrosParam {

};

class emBitan : public Enemy {
    u8 unk5310[0x620];
public:
    emBitan(u32 p1, emCreate* create);
    virtual ~emBitan();
    // TODO: emBitan virtual functions
};
static_assert(sizeof(emBitan) == 0x5930, "Class is wrong size!");

struct emBitanParam {

};

class emFlows : public Enemy {
    u8 unk5310[0xa74];
public:
    emFlows(u32 p1, emCreate* create);
    virtual ~emFlows();
    // TODO: emFlows virtual functions
};
static_assert(sizeof(emFlows) == 0x5d84, "Class is wrong size!");

struct emFlowsParam {

};

class emKokkon : public Enemy {
    u8 unk5310[0x9d0];
public:
    emKokkon(u32 p1, emCreate* create);
    virtual ~emKokkon();
    // TODO: emKokkon virtual functions
};
static_assert(sizeof(emKokkon) == 0x5ce0, "Class is wrong size!");

struct emKokkonParam {

};

class emPrim : public Enemy {
    u8 unk5310[0x595c];
public:
    emPrim(u32 p1, emCreate* create);
    virtual ~emPrim();
    // TODO: emPrim virtual functions
};
static_assert(sizeof(emPrim) == 0xac6c, "Class is wrong size!");

struct emPrimParam {

};

class emShelly : public Enemy {
    u8 unk5310[0xf90];
public:
    emShelly(u32 p1, emCreate* create);
    virtual ~emShelly();
    // TODO: emShelly virtual functions
};
static_assert(sizeof(emShelly) == 0x62a0, "Class is wrong size!");

struct emShellyParam {

};

class emPatapata : public Enemy {
    u8 unk5310[0xb04];
public:
    emPatapata(u32 p1, emCreate* create);
    virtual ~emPatapata();
    // TODO: emPatapata virtual functions
};
static_assert(sizeof(emPatapata) == 0x5e14, "Class is wrong size!");

struct emPatapataParam {

};

class emJdus : public Enemy {
    u8 unk5310[0xb14];
public:
    emJdus(u32 p1, emCreate* create);
    virtual ~emJdus();
    // TODO: emJdus virtual functions
};
static_assert(sizeof(emJdus) == 0x5e24, "Class is wrong size!");

struct emJdusParam {

};

class emBombhead : public Enemy {
    u8 unk5310[0x2d10];
public:
    emBombhead(u32 p1, emCreate* create);
    virtual ~emBombhead();
    // TODO: emBombhead virtual functions
};
static_assert(sizeof(emBombhead) == 0x8020, "Class is wrong size!");

struct emBombheadParam {

};

class emNgagog : public Enemy {
    u8 unk5310[0xaf4];
public:
    emNgagog(u32 p1, emCreate* create);
    virtual ~emNgagog();
    // TODO: emNgagog virtual functions
};
static_assert(sizeof(emNgagog) == 0x5e04, "Class is wrong size!");

struct emNgagogParam {

};

class emFaulong : public Enemy {
    u8 unk5310[0x8c4];
public:
    emFaulong(u32 p1, emCreate* create);
    virtual ~emFaulong();
    // TODO: emFaulong virtual functions
};
static_assert(sizeof(emFaulong) == 0x5bd4, "Class is wrong size!");

struct emFaulongParam {

};

class emGhamgha : public Enemy {
    u8 unk5310[0x858];
public:
    emGhamgha(u32 p1, emCreate* create);
    virtual ~emGhamgha();
    // TODO: emGhamgha virtual functions
};
static_assert(sizeof(emGhamgha) == 0x5b68, "Class is wrong size!");

struct emGhamghaParam {

};

class emRobobeam : public Enemy {
    u8 unk5310[0xe7c];
public:
    emRobobeam(u32 p1, emCreate* create);
    virtual ~emRobobeam();
    // TODO: emRobobeam virtual functions
};
static_assert(sizeof(emRobobeam) == 0x618c, "Class is wrong size!");

struct emRobobeamParam {

};

class emRobodistance : public Enemy {
    u8 unk5310[0xf3c];
public:
    emRobodistance(u32 p1, emCreate* create);
    virtual ~emRobodistance();
    // TODO: emRobodistance virtual functions
};
static_assert(sizeof(emRobodistance) == 0x624c, "Class is wrong size!");

struct emRobodistanceParam {

};

class emRobohoming : public Enemy {
    u8 unk5310[0xe54];
public:
    emRobohoming(u32 p1, emCreate* create);
    virtual ~emRobohoming();
    // TODO: emRobohoming virtual functions
};
static_assert(sizeof(emRobohoming) == 0x6164, "Class is wrong size!");

struct emRobohomingParam {

};

class emRobopunch : public Enemy {
    u8 unk5310[0xf1c];
public:
    emRobopunch(u32 p1, emCreate* create);
    virtual ~emRobopunch();
    // TODO: emRobopunch virtual functions
};
static_assert(sizeof(emRobopunch) == 0x622c, "Class is wrong size!");

struct emRobopunchParam {

};

class emCataguard : public Enemy {
    u8 unk5310[0xa6c];
public:
    emCataguard(u32 p1, emCreate* create);
    virtual ~emCataguard();
    // TODO: emCataguard virtual functions
};
static_assert(sizeof(emCataguard) == 0x5d7c, "Class is wrong size!");

struct emCataguardParam {

};

class emArman : public Enemy {
    u8 unk5310[0x3398];
public:
    emArman(u32 p1, emCreate* create);
    virtual ~emArman();
    // TODO: emArman virtual functions
};
static_assert(sizeof(emArman) == 0x86a8, "Class is wrong size!");

struct emArmanParam {

};

class emGalfire : public Enemy {
    u8 unk5310[0x784];
public:
    emGalfire(u32 p1, emCreate* create);
    virtual ~emGalfire();
    // TODO: emGalfire virtual functions
};
static_assert(sizeof(emGalfire) == 0x5a94, "Class is wrong size!");

struct emGalfireParam {

};

class emBosspackun : public Enemy {
    u8 unk5310[0x5030];
public:
    emBosspackun(u32 p1, emCreate* create);
    virtual ~emBosspackun();
    // TODO: emBosspackun virtual functions
};
static_assert(sizeof(emBosspackun) == 0xa340, "Class is wrong size!");

struct emBosspackunParam {

};

class emGhamghabase : public Enemy {
    u8 unk5310[0x65c];
public:
    emGhamghabase(u32 p1, emCreate* create);
    virtual ~emGhamghabase();
    // TODO: emGhamghabase virtual functions
};
static_assert(sizeof(emGhamghabase) == 0x596c, "Class is wrong size!");

struct emGhamghabaseParam {

};

class emGalleom : public Enemy {
    u8 unk5310[0x1560];
public:
    emGalleom(u32 p1, emCreate* create);
    virtual ~emGalleom();
    // TODO: emGalleom virtual functions
};
static_assert(sizeof(emGalleom) == 0x6870, "Class is wrong size!");

struct emGalleomParam {

};

class emRidley : public Enemy {
    u8 unk5310[0x19bc];
public:
    emRidley(u32 p1, emCreate* create);
    virtual ~emRidley();
    // TODO: emRidley virtual functions
};
static_assert(sizeof(emRidley) == 0x6ccc, "Class is wrong size!");

struct emRidleyParam {

};

class emRayquaza : public Enemy {
    u8 unk5310[0x1230];
public:
    emRayquaza(u32 p1, emCreate* create);
    virtual ~emRayquaza();
    // TODO: emRayquaza virtual functions
};
static_assert(sizeof(emRayquaza) == 0x6540, "Class is wrong size!");

struct emRayquazaParam {

};

class emDuon : public Enemy {
    u8 unk5310[0x12fc];
public:
    emDuon(u32 p1, emCreate* create);
    virtual ~emDuon();
    // TODO: emDuon virtual functions
};
static_assert(sizeof(emDuon) == 0x660c, "Class is wrong size!");

struct emDuonParam {

};

class emPorky : public Enemy {
    u8 unk5310[0x10f0];
public:
    emPorky(u32 p1, emCreate* create);
    virtual ~emPorky();
    // TODO: emPorky virtual functions
};
static_assert(sizeof(emPorky) == 0x6400, "Class is wrong size!");

struct emPorkyParam {

};

class emMetaridley : public Enemy {
    u8 unk5310[0x1b1c];
public:
    emMetaridley(u32 p1, emCreate* create);
    virtual ~emMetaridley();
    // TODO: emMetaridley virtual functions
};
static_assert(sizeof(emMetaridley) == 0x6e2c, "Class is wrong size!");

struct emMetaridleyParam {

};

class emFalconflyer : public Enemy {
    u8 unk5310[0x734];
public:
    emFalconflyer(u32 p1, emCreate* create);
    virtual ~emFalconflyer();
    // TODO: emFalconflyer virtual functions
};
static_assert(sizeof(emFalconflyer) == 0x5a44, "Class is wrong size!");

struct emFalconflyerParam {

};

class emTaboo : public Enemy {
    u8 unk5310[0x2248];
public:
    emTaboo(u32 p1, emCreate* create);
    virtual ~emTaboo();
    // TODO: emTaboo virtual functions
};
static_assert(sizeof(emTaboo) == 0x7558, "Class is wrong size!");

struct emTabooParam {

};

class emMasterhand : public Enemy {
    u8 unk5310[0xb6c];
public:
    emMasterhand(u32 p1, emCreate* create);
    virtual ~emMasterhand();
    // TODO: emMasterhand virtual functions
};
static_assert(sizeof(emMasterhand) == 0x5e7c, "Class is wrong size!");

struct emMasterhandParam {

};

class emCrazyhand : public Enemy {
    u8 unk5310[0xe10];
public:
    emCrazyhand(u32 p1, emCreate* create);
    virtual ~emCrazyhand();
    // TODO: emCrazyhand virtual functions
};
static_assert(sizeof(emCrazyhand) == 0x6120, "Class is wrong size!");

struct emCrazyhandParam {

};
