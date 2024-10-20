#pragma once

#include <types.h>
#include <so/so_value_accesser.h>

class itValueAccesser : public soValueAccesser {
public:
    enum ParamFloat {
        Common_Param_Float_HitSize = 0xD49,
        Common_Param_Float_Throw_Speed_Mul = 0xD4A,
        Common_Param_Float_2 = 0xD4B,
        Common_Param_Float_Rot_Coef_X = 0xD4C,
        Common_Param_Float_Rot_Coef_Y = 0xD4D,
        Common_Param_Float_Rot_Coef_Z = 0xD4E,
        Common_Param_Float_Rot_Appear_Mul = 0xD4F,
        Common_Param_Float_Gravity_Accel = 0xD50,
        Common_Param_Float_Gravity_Accel_Max = 0xD51,
        Common_Param_Float_9 = 0xD52,
        Common_Param_Float_Nururi_Size_Up = 0xD53,
        Common_Param_Float_Nururi_Size_Down = 0xD54,
        Common_Param_Float_Nururi_Size_Left = 0xD55,
        Common_Param_Float_Nururi_Size_Right = 0xD56,
        Common_Param_Float_Pickup_Range_OffX = 0xD57,
        Common_Param_Float_Pickup_Range_OffY = 0xD58,
        Common_Param_Float_Pickup_Range_SizeW = 0xD59,
        Common_Param_Float_Pickup_Range_SizeH = 0xD5A,
        Common_Param_Float_MapColl_Size_Up = 0xD5B,
        Common_Param_Float_MapColl_Size_Down = 0xD5C,
        Common_Param_Float_MapColl_Size_HalfWidth = 0xD5D,
        Common_Param_Float_Clip_Sphere_R = 0xD5E,
        Common_Param_Float_Clip_Sphere_OffY = 0xD5F,
        Common_Param_Float_Rot_Accel = 0xD60,
        Common_Param_Float_Rot_Brake = 0xD61,
        Common_Param_Float_Bound_RefSpeed_Mul_X = 0xD62,
        Common_Param_Float_Bound_RefSpeed_Mul_Y = 0xD63,
        Common_Param_Float_Bound_MinSpeed = 0xD64,
        Common_Param_Float_Bound_RefSpeed_Wall_Mul_X = 0xD65,
        Common_Param_Float_Bound_RefSpeed_Wall_Mul_Y = 0xD66,
        Common_Param_Float_Bound_RefSpeed_Ceiling_Mul_X = 0xD67,
        Common_Param_Float_Bound_RefSpeed_Ceiling_Mul_Y = 0xD68,
        Common_Param_Float_Bound_RefSpeed_Character_Mul = 0xD69,
        Common_Param_Float_Bound_RefSpeed_Character_Add_Y = 0xD6A,
        Common_Param_Float_Air_Brake_X = 0xD6B,
        Common_Param_Float_Ground_Brake_X = 0xD6C,
        Common_Param_Float_Rot_Limit_Speed_X = 0xD6D,
        Common_Param_Float_Rot_Limit_Speed_Y = 0xD6E,
        Common_Param_Float_Throw_Power_Speed_Add = 0xD6F,
        Common_Param_Float_Throw_Power_Speed_Mul = 0xD70,
        Common_Param_Float_Scale = 0xD71,
        Common_Param_Float_HP = 0xD72
    };

    enum ParamInt {
        Game_Param_Int_Remove_Flash_Frame = 0x59d9,

        Common_Param_Int_AI_Pri = 0x5b68,
        Common_Param_Int_Size_Kind = 0x5b69,
        Common_Param_Int_Have_Kind = 0x5b6A,
        Common_Param_Int_3 = 0x5b6B,
        Common_Param_Int_4 = 0x5b6C,
        Common_Param_Int_Scale_Type = 0x5b6D,
        Common_Param_Int_Slope_Type = 0x5b6E,
        Common_Param_Int_Flash_Kind = 0x5b6F,
        Common_Param_Int_Camera_Kind = 0x5b70,
        Common_Param_Int_Hit_Kind = 0x5b71,
        Common_Param_Int_Reflect_Kind = 0x5b72,
        Common_Param_Int_Shield_Kind = 0x5b73,
        Common_Param_Int_DeadArea_Kind = 0x5b74,
        Common_Param_Int_Attack_HitStop_Kind = 0x5b75,
    };

    enum SizeKind {
        Size_Small = 0x0,
        Size_Large = 0x1
    };

    enum HaveKind {
        Have_None = 0x0,
        Have_Get = 0x1,
        Have_Motion = 0x2,
        Have_Normal = 0x3,
        Have_Pickup = 0x4,
        Have_Grip = 0x5,
        Have_Plate = 0x6
    };

    enum ScaleType {
        Scale_Normal = 0x0,
        Scale_Fighter = 0x1
    };

    enum SlopeType {
        Slope_None = 0x0,
        Slope_Slant = 0x1,
        Slope_Slant_Keep_Y_Rot = 0x2,
        Slope_KeepAngle = 0x3,
        Slope_Up = 0x4,
        Slope_Slant_Smooth = 0x5,
    };

    enum FlashKind {
        Flash_None = 0x0,
        Flash_Normal = 0x1,
    };

    enum CameraKind {
        Camera_None = 0x0,
        Camera_Normal = 0x1,
        Camera_Center = 0x2,
    };

    enum HitKind {
        Hit_None = 0x0,
        Hit_Stop = 0x1,
        Hit_Fly = 0x2,
        Hit_Lr = 0x3
    };

    enum ReflectKind {
        Reflect_None = 0x0,
        Reflect_Normal = 0x1
    };

    enum ShieldKind {
        Shield_None = 0x0,
        Shield_Lost = 0x1,
        Shield_Born = 0x2,
        Shield_Hop = 0x3
    };

    enum DeadAreaKind {
        DeadArea_None = 0x0,
        DeadArea_Remove = 0x1,
        DeadArea_Remove_Not_Xlu = 0x2,
        DeadArea_All = 0x3
    };

    enum AttackHitStopKind {
        Attack_HitStop_None = 0x0,
        Attack_HitStop_Normal = 0x1,
        Attack_HitStop_Parent = 0x2
    };

    virtual soParamAccesser* getExtendParamAccesser();
    virtual ~itValueAccesser();
    virtual float getConstantFloatCore(soModuleAccesser* moduleAccesser, u32);
    virtual int getConstantIntCore(soModuleAccesser* moduleAccesser, u32);
    virtual void* getConstantIndefiniteCore(soModuleAccesser* moduleAccesser, u32);

    virtual float getVariableFloatCore(soModuleAccesser* moduleAccesser, u32);
    virtual int getVariableIntCore(soModuleAccesser* moduleAccesser, u32);

};

