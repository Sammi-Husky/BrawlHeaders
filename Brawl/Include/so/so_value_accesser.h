#pragma once

#include <so/so_null.h>
#include <so/so_module_accesser.h>
#include <types.h>

class soParamAccesser : public soNull, public soNullable {
public:
    virtual ~soParamAccesser();
    float getParamFloat(soModuleAccesser* moduleAccesser, u32, u32);
    int getParamInt(soModuleAccesser* moduleAccesser, u32, u32);
    void* getParamIndefinite(soModuleAccesser* moduleAccesser, u32, u32);
};

class soValueAccesser {
public:

    enum ParamFloat {
        Common_Param_Float_Damage_Frame_Mul = 0x7D2,
        Common_Param_Float_Damage_Level_1 = 0x7D3,
        Common_Param_Float_Damage_Level_2 = 0x7D4,
        Common_Param_Float_Damage_Level_3 = 0x7D5,
        Common_Param_Float_Damage_Angle_Ground_Zero_Speed_Mul = 0x7D6,
        Common_Param_Float_Damage_Angle_Ground_Max = 0x7D7,
        Common_Param_Float_Damage_Angle_Ground_Reaction_Min = 0x7D8,
        Common_Param_Float_Damage_Angle_Ground_Reaction_Max = 0x7D9,
        Common_Param_Float_Damage_Speed_Mul = 0x7DA,
        Common_Param_Float_Damage_Speed_Limit = 0x7DB,
        Common_Param_Float_Damage_Sync_Speed_Mul = 0x7DC,
        Common_Param_Float_Damage_Down_On_Ground_Angle = 0x7DD,
        Common_Param_Float_Damage_Down_On_Ground_Speed_Y_Mul = 0x7DE,
        Common_Param_Float_Fly_Top_Angle_Lw = 0x7DF,
        Common_Param_Float_Fly_Top_Angle_Hi = 0x7E0,
        Common_Param_Float_Fly_Roll_Rate = 0x7E1,
        Common_Param_Float_Hit_Stop_Frame_Max = 0x7E2,
        Common_Param_Float_Hit_Stop_Frame_Mul = 0x7E3,
        Common_Param_Float_Hit_Stop_Frame_Add = 0x7E4,
        Common_Param_Float_Damage_Shake_Mul_Value = 0x7E5,
        Common_Param_Float_Damage_Shake_Add_Value = 0x7E6,

        Common_Param_Float_Down_Damage_Reaction = 0x7E9,
        Common_Param_Float_Down_Damage_S_Reaction = 0x7EA,

        Common_Param_Float_Hit_Stop_Elec_Mul = 0x7EC,
        Common_Param_Float_Hit_Stop_Frame_Paralyze_Max = 0x7ED,
        Common_Param_Float_Hit_Stop_Frame_Paralyze_Mul = 0x7EE,
        Common_Param_Float_Hit_Stop_Frame_Paralyze_Add = 0x7EF,
        Common_Param_Float_Slip_Damage_Reaction = 0x7F0,
        Common_Param_Float_Capture_Cut_Attack_Power = 0x7F1,
        Common_Param_Float_Capture_Cut_Damage = 0x7F2,
        Common_Param_Float_Damage_Fly_Quake_M = 0x7F3,
        Common_Param_Float_Damage_Fly_Quake_L = 0x7F4,
        Common_Param_Float_Rebound_Power_Diff = 0x7F5,
        Common_Param_Float_Rebound_Reaction_Mul = 0x7F6,
        Common_Param_Float_Rebound_Reaction_Add = 0x7F7,
        Common_Param_Float_Rebound_Speed_Mul = 0x7F8,
        Common_Param_Float_Rebound_Speed_Add = 0x7F9,
    };

    enum ParamInt {
        Common_Param_Int_Meteor_Vector_Min = 0x55F1,
        Common_Param_Int_Meteor_Vector_Max = 0x55F2,
        Common_Param_Int_Fly_Roll_Damage = 0x55F3,

        Common_Param_Int_Reflect_Count_Max = 0x55F5,
    };

    enum ParamIndefinite {

    };

    virtual soParamAccesser* getExtendParamAccesser();
    virtual ~soValueAccesser();
    virtual float getVariableFloatCore(soModuleAccesser* moduleAccesser, u32, u32);
    virtual int getVariableIntCore(soModuleAccesser* moduleAccesser, u32, u32);
    virtual void* getVariableIndefiniteCore(soModuleAccesser* moduleAccesser, u32, u32);
    virtual float getConstantFloatCore(soModuleAccesser* moduleAccesser, u32, u32);
    virtual int getConstantIntCore(soModuleAccesser* moduleAccesser, u32, u32);
    virtual void* getConstantIndefiniteCore(soModuleAccesser* moduleAccesser, u32, u32);
    virtual bool isControllerValueCore(soModuleAccesser* moduleAccesser, u32, u32);
    virtual bool isEnableSpeedOperationCore(soModuleAccesser* moduleAccesser);

    static float getVariableFloat(soModuleAccesser* moduleAccesser, u32, u32);
    static int getVariableInt(soModuleAccesser* moduleAccesser, u32, u32);
    static void* getVariableIndefinite(soModuleAccesser* moduleAccesser, u32, u32);

    static float getConstantFloat(soModuleAccesser* moduleAccesser, u32, u32);
    static int getConstantInt(soModuleAccesser* moduleAccesser, u32, u32);
    static void* getConstantIndefinite(soModuleAccesser* moduleAccesser, u32, u32);

    static float getValueFloat(soModuleAccesser* moduleAccesser, u32, u32);
    static int getValueInt(soModuleAccesser* moduleAccesser, u32, u32);
};
