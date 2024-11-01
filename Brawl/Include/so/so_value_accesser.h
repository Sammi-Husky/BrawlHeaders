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

    enum VariableFloat {
        Variable_Float_Motion_Frame = 0x0,
        Variable_Float_Motion_End_Frame = 0x1,
        Variable_Float_Damage = 0x2,
        Variable_Float_Posture_Pos_X = 0x3,
        Variable_Float_Posture_Pos_Y = 0x4,
        Variable_Float_Posture_Rot_X = 0x5,
        Variable_Float_Posture_Rot_Y = 0x6,
        Variable_Float_Posture_Rot_Z = 0x7,
        Variable_Float_Posture_Lr = 0x8,
        Variable_Float_Posture_Lr_Rv = 0x9,
        Variable_Float_Motion_Other_1_Frame = 0xA,
        Variable_Float_Motion_Other_2_Frame = 0xB,
        Variable_Float_Motion_Other_3_Frame = 0xC,
        Variable_Float_Motion_Other_4_Frame = 0xD,
        Variable_Float_Motion_Other_5_Frame = 0xE,
        Variable_Float_Motion_Other_1_End_Frame = 0xF,
        Variable_Float_Motion_Other_2_End_Frame = 0x10,
        Variable_Float_Motion_Other_3_End_Frame = 0x11,
        Variable_Float_Motion_Other_4_End_Frame = 0x12,
        Variable_Float_Motion_Other_5_End_Frame = 0x13,
        Variable_Float_Posture_Scale = 0x14,
        Variable_Float_Posture_Pos_Z = 0x15,
        Variable_Float_Kinetic_Sum_Speed_X = 0x16,
        Variable_Float_Kinetic_Sum_Speed_Y = 0x17,
        Variable_Float_Motion_Rate = 0x18,
        Variable_Float_Controller_Stick_X = 0x19,
        Variable_Float_Controller_Stick_X_Rv = 0x1A,
        Variable_Float_Kinetic_Sum_Speed_X_Abs = 0x1B,
        Variable_Float_Kinetic_Sum_Speed_X_Lr = 0x1C,
        Variable_Float_Kinetic_Sum_Speed_X_Lr_Rv = 0x1D,
        Variable_Float_Camera_Range_Up = 0x1E,
        Variable_Float_Camera_Range_Down = 0x1F,
        Variable_Float_Camera_Range_Right = 0x20,
        Variable_Float_Camera_Range_Left = 0x21,
        Variable_Float_Dead_Range_Up = 0x22,
        Variable_Float_Dead_Range_Down = 0x23,
        Variable_Float_Dead_Range_Right = 0x24,
        Variable_Float_Dead_Range_Left = 0x25,
        Variable_Float_Damage_Reaction = 0x26,
        Variable_Float_Ground_Down_Friction = 0x27,
        Variable_Float_Ground_Down_Movement_Speed = 0x28
    };

    enum VariableInt {
        Variable_Int_Motion_Kind = 0x4E20,
        Variable_Int_Status_Kind = 0x4E21,
        Variable_Int_Status_Ground_Correct = 0x4E22,
        Variable_Int_Status_Prev_Kind = 0x4E23,
        Variable_Int_Status_Last_Transition_Group_Id = 0x4E24,
        Variable_Int_Status_Last_Transition_Unit_Id = 0x4E25,
        Variable_Int_Pickable_Item_Size = 0x4E26,
        Variable_Int_Pickable_Item_Kind = 0x4E27,
        Variable_Int_Have_Item_Size = 0x4E28,
        Variable_Int_Have_Item_Kind = 0x4E29,
        Variable_Int_Motion_Partial_1_Kind = 0x4E2A,
        Variable_Int_Motion_Partial_2_Kind = 0x4E2B,
        Variable_Int_Motion_Other_1_Kind = 0x4E2C,
        Variable_Int_Motion_Other_2_Kind = 0x4E2D,
        Variable_Int_Motion_Other_3_Kind = 0x4E2E,
        Variable_Int_Motion_Other_4_Kind = 0x4E2F,
        Variable_Int_Motion_Other_5_Kind = 0x4E30,
        Variable_Int_Controller_Flick_X = 0x4E31,
        Variable_Int_Shoot_Item_Bullet = 0x4E32,
        Variable_Int_Have_Item_Hold_Kind = 0x4E33,
        Variable_Int_Camera_Quake_Kind = 0x4E34,
        Variable_Int_Team_No = 0x4E35,
        Variable_Int_Task_Id = 0x4E36,
        Variable_Int_Ground_Correct = 0x4E37,
        Variable_Int_Kinetic_Type = 0x4E38,
        Variable_Int_Situation_Kind = 0x4E39,
        Variable_Int_Stage_Default_Light_Set_Index = 0x4E3A,
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
