#pragma once

#include <StaticAssert.h>
#include <gr/gr_gimmick_motion_path.h>
#include <mt/mt_vector.h>
#include <types.h>

enum emKind {
    Enemy_Invalid = -0x1,
    Enemy_Goomba = 0x0,
    Enemy_Kuribo = 0x0,
    Enemy_Poppant = 0x1,
    Enemy_Popperam = 0x1,
    Enemy_Feyesh = 0x2,
    Enemy_Pochi = 0x2,
    Enemy_Jyk = 0x3,
    Enemy_Jyakeel = 0x3,
    Enemy_Auroros = 0x4,
    Enemy_Aroaros = 0x4,
    Enemy_Cymal = 0x5,
    Enemy_Roturret = 0x6,
    Enemy_Deathpod = 0x6,
    Enemy_Borboras = 0x7,
    Enemy_Boobas = 0x7,
    Enemy_GiantGoomba = 0x8,
    Enemy_DekaKuribo = 0x8,
    Enemy_Buckot = 0x9,
    Enemy_Botron = 0x9,
    Enemy_Bucculus = 0xA,
    Enemy_Bucyulus = 0xA,
    Enemy_Greap = 0xB,
    Enemy_Gyraan = 0xB,
    Enemy_Armight = 0xC,
    Enemy_SirAlamos = 0xC,
    Enemy_BulletBill = 0xD,
    Enemy_Killer = 0xD,
    Enemy_Roader = 0xE,
    Enemy_Roada = 0xE,
    Enemy_Spaak = 0xF,
    Enemy_Spar = 0xF,
    Enemy_Mite = 0x10,
    Enemy_Ticken = 0x11,
    Enemy_Teckin = 0x11,
    Enemy_Towtow = 0x12,
    Enemy_Tautau = 0x12,
    Enemy_HammerBro = 0x13,
    Enemy_HammerBros = 0x13,
    Enemy_Bytan = 0x14,
    Enemy_Bitan = 0x14,
    Enemy_Floow = 0x15,
    Enemy_Flows = 0x15,
    Enemy_Puppit = 0x16,
    Enemy_Kokkon = 0x16,
    Enemy_Primid = 0x17,
    Enemy_Prim = 0x17,
    Enemy_Shellpod = 0x18,
    Enemy_Shelly = 0x18,
    Enemy_Koopa = 0x19,
    Enemy_Patapata = 0x19,
    Enemy_Shaydas = 0x1A,
    Enemy_Jdus = 0x1A,
    Enemy_Bombed = 0x1B,
    Enemy_Bombhead = 0x1B,
    Enemy_Primid_Metal = 0x1C,
    Enemy_Prim_Metal = 0x1C,
    Enemy_Nagagog = 0x1D,
    Enemy_Ngagog = 0x1D,
    Enemy_Trowlon = 0x1E,
    Enemy_Faulong = 0x1E,
    Enemy_Primid_Big = 0x1F,
    Enemy_Prim_Big = 0x1F,
    Enemy_Primid_Boom = 0x20,
    Enemy_Prim_Boomerang = 0x20,
    Enemy_Primid_Fire = 0x21,
    Enemy_Prim_Fire = 0x21,
    Enemy_Primid_Scope = 0x22,
    Enemy_Prim_SuperScope = 0x22,
    Enemy_Primid_Sword = 0x23,
    Enemy_Prim_Sword = 0x23,
    Enemy_Gamyga = 0x24,
    Enemy_Ghamgha = 0x24,
    Enemy_ROB_Blaster = 0x25,
    Enemy_Robo_Beam = 0x25,
    Enemy_ROB_Distance = 0x26,
    Enemy_Robo_Distance = 0x26,
    Enemy_ROB_Launcher = 0x27,
    Enemy_Robo_Homing = 0x27,
    Enemy_ROB_Sentry = 0x28,
    Enemy_Robo_Punch = 0x28,
    Enemy_Autolance = 0x29,
    Enemy_Cataguard = 0x29,
    Enemy_Armank = 0x2A,
    Enemy_Arman = 0x2A,
    Enemy_Glire = 0x2B,
    Enemy_Gal_Fire = 0x2B,
    Enemy_Glice = 0x2C,
    Enemy_Gal_Ice = 0x2C,
    Enemy_Glunder = 0x2D,
    Enemy_Gal_Thunder = 0x2D,
    Enemy_Boss_PeteyPiranha = 0x2E,
    Enemy_Boss_BossPackun = 0x2E,
    Enemy_GamygaBase = 0x2F,
    Enemy_Ghamghabase = 0x2F,
    Enemy_Boss_Galleom = 0x33,
    Enemy_Boss_Ridley = 0x34,
    Enemy_Boss_Rayquaza = 0x35,
    Enemy_Boss_Duon = 0x36,
    Enemy_Boss_Porky = 0x37,
    Enemy_Boss_MetaRidley = 0x38,
    Enemy_Boss_Metaridley = 0x38,
    Enemy_Boss_FalconFlyer = 0x39,
    Enemy_Boss_Falconflyer = 0x39,
    Enemy_Boss_Tabuu = 0x3A,
    Enemy_Boss_Taboo = 0x3A,
    Enemy_Boss_MasterHand = 0x3B,
    Enemy_Boss_Masterhand = 0x3B,
    Enemy_Boss_CrazyHand = 0x3C,
    Enemy_Boss_Crazyhand = 0x3C
};
typedef emKind EnemyKind;

// TODO: is this emValueAccesser?
struct UnkParamAccesser {
    u8 unk0[0xC0];
    u32 unkC0; // TODO type
    u8 unkC4[0x20];
    u32 unkE4; // TODO type
    u8 unkE8[0x1C];
    float unk104;
    float unk108;
    float unk10C;
    u32 unk110; // TODO type
    u8 unk114[0xC];
    u32 unk120; // TODO type
    u8 unk124[0xC];
    u32 unk130; // TODO type
    u8 unk134[0xC];
    u32 unk140; // TODO type
    u8 unk144[0x3C];
    u32 unk180; // TODO type
    u8 unk184[0x4];
    u32 unk188; // TODO type
    u8 unk18C[0x18];
    u32 unk1A4; // TODO type
    u32 unk1A8; // TODO type
    u32 unk1AC; // TODO type
    s32 unk1B0;
    s32 unk1B4;
    u32 unk1B8; // TODO type
    u8 unk1BC[0x4];
    u32 unk1C0; // TODO type
    float unk1C4;
    float unk1C8;
    u32 unk1CC; // TODO type
    u8 unk1D0[0x38];
    u32 unk208; // TODO type
    u8 unk20C[0x28];
    u32 unk234; // TODO type
    u8 unk238[0x8];
    u32 unk240; // TODO type
    u8 unk244[0x4];
    u32 unk248; // TODO type
    u8 unk24C[0xC];
    u32 unk258; // TODO type
    u8 unk25C[0x8];
    u32 unk264; // TODO type
    u32 unk268; // TODO type
    u8 unk26C[0xC];
    float unk278;
    s32 unk27C;
    u32 unk280; // TODO type
    u32 unk284; // TODO type
    u8 unk288[0x4];
    float unk28C;
    float unk290;
    u8 unk294;
    u8 unk295;
    u8 unk296[0x2];
    float unk298;
    u8 unk29C[0x10];
    s32 unk2AC;
    u32 unk2B0; // TODO type
    u8 unk2B4[0x38];
    u8 unk2EC; // TODO type
    s32 unk2F0;
    float unk2F4;
    float unk2F8;
    u8 unk2FC[0x4];
    u32 unk300; // TODO type
    u8 unk304[0x20];
    u32 unk324; // TODO type
    u8 unk328[0x4];
    s32 unk32C;
    float unk330;
    u8 unk334[0x10];
    s32 unk344;
    u32 unk348; // TODO type
    u8 unk34C[0x34];
    u32 unk380; // TODO type
    u8 unk384[0xB0];
    u32 unk434; // TODO type
    u8 unk438[0x44];
    u32 unk47C; // TODO type
    u8 unk480[0x34];
    u32 unk4B4; // TODO type
    u8 unk4B8[0x4];
    u32 unk4BC; // TODO type
    u8 unk4C0[0x20];
    u32 unk4E0; // TODO type
    u8 unk4E4[0xC];
    u32 unk4F0; // TODO type
    u8 unk4F4[0x8];
    u8 unk4FC;
    s32 unk500;
    s32 unk504;
    u32 unk508; // TODO type
    u8 unk50C[0x74];
    u32 unk580; // TODO type
    u8 unk584[0x68];
    u32 unk5EC; // TODO type
    u8 unk5F0[0x5C];
    s32 unk64C;
    u8 unk650;
    u32 unk654; // TODO type
    u8 unk658[0x4];
    s32 unk65C;
    s32 unk660;
    u32 unk664; // TODO type
    u8 unk668[0x4];
    u32 unk66C; // TODO type
    u8 unk670[0x4];
    u32 unk674; // TODO type
};

class emCreate {
public:
    u8 m_difficulty;
    char _1[3];
    EnemyKind m_enemyKind;
    int m_teamNo;
    float m_startLr;
    Vec3f m_startPos;
    u32 m_startStatusKind;
    u8 m_level;
    char _33[3];
    float m_36;
    Rect2D m_territoryRange;
    int m_connectedTriggerId;
    void* m_epbm;
    UnkParamAccesser* m_epsp;
    grGimmickMotionPath* m_motionPath;
    int m_parentCreateId;
    virtual ~emCreate(){

    };
};
static_assert(sizeof(emCreate) == 80, "Class is wrong size!");
