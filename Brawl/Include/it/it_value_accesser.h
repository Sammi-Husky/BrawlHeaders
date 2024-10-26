#pragma once

#include <types.h>
#include <so/so_value_accesser.h>
#include <it/it_archive.h>

class itValueAccesser : public soValueAccesser {
public:
    enum ParamFloat {
        Specialized_Param_Float_HitSize = 0xD49,
        Specialized_Param_Float_Throw_Speed_Mul = 0xD4A,
        Specialized_Param_Float_2 = 0xD4B,
        Specialized_Param_Float_Rot_Coef_X = 0xD4C,
        Specialized_Param_Float_Rot_Coef_Y = 0xD4D,
        Specialized_Param_Float_Rot_Coef_Z = 0xD4E,
        Specialized_Param_Float_Rot_Appear_Mul = 0xD4F,
        Specialized_Param_Float_Gravity_Accel = 0xD50,
        Specialized_Param_Float_Gravity_Accel_Max = 0xD51,
        Specialized_Param_Float_9 = 0xD52,
        Specialized_Param_Float_Nururi_Size_Up = 0xD53,
        Specialized_Param_Float_Nururi_Size_Down = 0xD54,
        Specialized_Param_Float_Nururi_Size_Left = 0xD55,
        Specialized_Param_Float_Nururi_Size_Right = 0xD56,
        Specialized_Param_Float_Pickup_Range_Offset_X = 0xD57,
        Specialized_Param_Float_Pickup_Range_Offset_Y = 0xD58,
        Specialized_Param_Float_Pickup_Range_Size_W = 0xD59,
        Specialized_Param_Float_Pickup_Range_Size_H = 0xD5A,
        Specialized_Param_Float_MapColl_Size_Up = 0xD5B,
        Specialized_Param_Float_MapColl_Size_Down = 0xD5C,
        Specialized_Param_Float_MapColl_Size_HalfWidth = 0xD5D,
        Specialized_Param_Float_Clip_Sphere_R = 0xD5E,
        Specialized_Param_Float_Clip_Sphere_OffY = 0xD5F,
        Specialized_Param_Float_Rot_Accel = 0xD60,
        Specialized_Param_Float_Rot_Brake = 0xD61,
        Specialized_Param_Float_Bound_RefSpeed_Mul_X = 0xD62,
        Specialized_Param_Float_Bound_RefSpeed_Mul_Y = 0xD63,
        Specialized_Param_Float_Bound_MinSpeed = 0xD64,
        Specialized_Param_Float_Bound_RefSpeed_Wall_Mul_X = 0xD65,
        Specialized_Param_Float_Bound_RefSpeed_Wall_Mul_Y = 0xD66,
        Specialized_Param_Float_Bound_RefSpeed_Ceiling_Mul_X = 0xD67,
        Specialized_Param_Float_Bound_RefSpeed_Ceiling_Mul_Y = 0xD68,
        Specialized_Param_Float_Bound_RefSpeed_Character_Mul = 0xD69,
        Specialized_Param_Float_Bound_RefSpeed_Character_Add_Y = 0xD6A,
        Specialized_Param_Float_Air_Brake_X = 0xD6B,
        Specialized_Param_Float_Ground_Brake_X = 0xD6C,
        Specialized_Param_Float_Rot_Limit_Speed_X = 0xD6D,
        Specialized_Param_Float_Rot_Limit_Speed_Y = 0xD6E,
        Specialized_Param_Float_Throw_Power_Speed_Add = 0xD6F,
        Specialized_Param_Float_Throw_Power_Speed_Mul = 0xD70,
        Specialized_Param_Float_Scale = 0xD71,
        Specialized_Param_Float_HP = 0xD72
    };

    enum ParamInt {
        Game_Param_Int_Remove_Flash_Frame = 0x59d9,

        Specialized_Param_Int_AI_Pri = 0x5b68,
        Specialized_Param_Int_Size_Kind = 0x5b69,
        Specialized_Param_Int_Have_Kind = 0x5b6A,
        Specialized_Param_Int_3 = 0x5b6B,
        Specialized_Param_Int_4 = 0x5b6C,
        Specialized_Param_Int_Scale_Type = 0x5b6D,
        Specialized_Param_Int_Slope_Type = 0x5b6E,
        Specialized_Param_Int_Flash_Kind = 0x5b6F,
        Specialized_Param_Int_Camera_Kind = 0x5b70,
        Specialized_Param_Int_Hit_Kind = 0x5b71,
        Specialized_Param_Int_Reflect_Kind = 0x5b72,
        Specialized_Param_Int_Shield_Kind = 0x5b73,
        Specialized_Param_Int_DeadArea_Kind = 0x5b74,
        Specialized_Param_Int_Attack_Hit_Stop_Kind = 0x5b75,
    };

    enum ParamIndefinite {

    };

    virtual soParamAccesser* getExtendParamAccesser();
    virtual ~itValueAccesser();
    virtual float getConstantFloatCore(soModuleAccesser* moduleAccesser, u32, u32);
    virtual int getConstantIntCore(soModuleAccesser* moduleAccesser, u32, u32);
    virtual void* getConstantIndefiniteCore(soModuleAccesser* moduleAccesser, u32, u32);

    virtual float getVariableFloatCore(soModuleAccesser* moduleAccesser, u32, u32);
    virtual int getVariableIntCore(soModuleAccesser* moduleAccesser, u32, u32);

};

