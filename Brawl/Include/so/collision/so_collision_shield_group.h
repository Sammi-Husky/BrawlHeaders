#pragma once

#include <StaticAssert.h>
#include <types.h>

class soCollisionShieldGroup {
public:
	u8 _00[0x90];
	float m_posX;
	u32 _94;
	float m_Lr;
	float m_hopAngle;
	float m_attackMul;
	float m_speedMul;
	float m_attackLimit;
	float m_lifeMul;
	u8 m_isFront;
	u8 m_isHop;
	u8 m_isTurn;
	u8 m_isNoMBall;
	u8 m_isNoHop;
	u8 _b5[0x3];
};
static_assert(sizeof(soCollisionShieldGroup) == 0xB8, "Class is wrong size!");
