#pragma once

#include <types.h>
#include <StaticAssert.h>
#include <mt/mt_vector.h>
#include <gr/gr_gimmick_motion_path.h>

enum EnemyID {
    Enemy_Invalid = -0x1,
    Enemy_Kuribo = 0x0,
    Enemy_Popperam = 0x1,
    Enemy_Pochi = 0x2,
    Enemy_Jyakeel = 0x3,
    Enemy_Aroaros = 0x4,
    Enemy_Cymal = 0x5,
    Enemy_Deathpod = 0x6,
    Enemy_Boobas = 0x7,
    Enemy_Dekakuribo = 0x8,
    Enemy_Botron = 0x9,
    Enemy_Bucyulus = 0xA,
    Enemy_Gyraan = 0xB,
    Enemy_Siralamos = 0xC,
    Enemy_Killer = 0xD,
    Enemy_Roada = 0xE,
    Enemy_Spar = 0xF,
    Enemy_Mite = 0x10,
    Enemy_Teckin = 0x11,
    Enemy_Tautau = 0x12,
    Enemy_Hammerbros = 0x13,
    Enemy_Bitan = 0x14,
    Enemy_Flows = 0x15,
    Enemy_Kokkon = 0x16,
    Enemy_Prim = 0x17,
    Enemy_Shelly = 0x18,
    Enemy_Patapata = 0x19,
    Enemy_Jdus = 0x1A,
    Enemy_Bombhead = 0x1B,
    Enemy_Ngagog = 0x1D,
    Enemy_Faulong = 0x1E,
    Enemy_Ghamgha = 0x24,
    Enemy_Robobeam = 0x25,
    Enemy_Robodistance = 0x26,
    Enemy_Robohoming = 0x27,
    Enemy_Robopunch = 0x28,
    Enemy_Cataguard = 0x29,
    Enemy_Arman = 0x2A,
    Enemy_Galfire = 0x2B,
    Enemy_Bosspackun = 0x2E,
    Enemy_Ghamghabase = 0x2F,
    Enemy_Galleom = 0x33,
    Enemy_Ridley = 0x34,
    Enemy_Rayquaza = 0x35,
    Enemy_Duon = 0x36,
    Enemy_Porky = 0x37,
    Enemy_Metaridley = 0x38,
    Enemy_Falconflyer = 0x39,
    Enemy_Taboo = 0x3A,
    Enemy_Masterhand = 0x3B,
    Enemy_Crazyhand = 0x3C
};

class emCreate {
public:
    u8 m_difficultyLevel;
    char _1[3];
    EnemyID m_enemyID;
    int m_8;
    float m_facingDirection;
    Vec3f m_spawnPos;
    u32 m_startingAction;
    u8 m_32;
    char _33[3];
    float m_36;
    float m_posX1;
    float m_posX2;
    float m_posY1;
    float m_posY2;
    EnemyID m_connectedEnemyID;
    void* m_epbm;
    void* m_epsp;
    grGimmickMotionPath* m_motionPath;
    int m_72;
    virtual ~emCreate() {

    };

    STATIC_CHECK(sizeof(emCreate) == 80)
};