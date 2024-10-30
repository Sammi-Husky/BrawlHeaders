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
        Motion_Variable_Float_Frame = 0x0,
        Motion_Variable_Float_End_Frame = 0x1,
        Damage_Variable_Float_Damage = 0x2,
        Posture_Variable_Float_Pos_X = 0x3,
        Posture_Variable_Float_Pos_Y = 0x4,
        Posture_Variable_Float_Rot_X = 0x5,
        Posture_Variable_Float_Rot_Y = 0x6,
        Posture_Variable_Float_Rot_Z = 0x7,
        Posture_Variable_Float_Lr = 0x8,
        Posture_Variable_Float_Lr_Rv = 0x9,
        Motion_Variable_Float_Other_1_Frame = 0xA,
        Motion_Variable_Float_Other_2_Frame = 0xB,
        Motion_Variable_Float_Other_3_Frame = 0xC,
        Motion_Variable_Float_Other_4_Frame = 0xD,
        Motion_Variable_Float_Other_5_Frame = 0xE,
        Motion_Variable_Float_Other_1_End_Frame = 0xF,
        Motion_Variable_Float_Other_2_End_Frame = 0x10,
        Motion_Variable_Float_Other_3_End_Frame = 0x11,
        Motion_Variable_Float_Other_4_End_Frame = 0x12,
        Motion_Variable_Float_Other_5_End_Frame = 0x13,
        Posture_Variable_Float_Scale = 0x14,
        Posture_Variable_Float_Pos_Z = 0x15,
        Kinetic_Variable_Float_Sum_Speed_X = 0x16,
        Kinetic_Variable_Float_Sum_Speed_Y = 0x17,
        Motion_Variable_Float_Rate = 0x18,
        Controller_Variable_Float_Stick_X = 0x19,
        Controller_Variable_Float_Stick_X_Rv = 0x1A,
        Kinetic_Variable_Float_Sum_Speed_X_Abs = 0x1B,
        Kinetic_Variable_Float_Sum_Speed_X_Lr = 0x1C,
        Kinetic_Variable_Float_Sum_Speed_X_Lr_Rv = 0x1D,
        Camera_Variable_Float_Camera_Range_Up = 0x1E,
        Camera_Variable_Float_Camera_Range_Down = 0x1F,
        Camera_Variable_Float_Camera_Range_Right = 0x20,
        Camera_Variable_Float_Camera_Range_Left = 0x21,
        Camera_Variable_Float_Dead_Range_Up = 0x22,
        Camera_Variable_Float_Dead_Range_Down = 0x23,
        Camera_Variable_Float_Dead_Range_Right = 0x24,
        Camera_Variable_Float_Dead_Range_Left = 0x25,
        Damage_Variable_Float_Reaction = 0x26,
        Ground_Variable_Down_Friction = 0x27,
        Ground_Variable_Down_Movement_Speed = 0x28
    };

    enum VariableInt {
        Motion_Variable_Int_Kind = 0x4E20,
        Status_Variable_Int_Kind = 0x4E21,
        Status_Variable_Int_Ground_Correct = 0x4E22,
        Status_Variable_Int_Prev_Kind = 0x4E23,
        Status_Variable_Int_Last_Transition_Group_Id = 0x4324,
        Status_Variable_Int_Last_Transition_Unit_Id = 0x4325,
        ItemManage_Variable_Int_Pickable_Item_Size = 0x4326,
        ItemManage_Variable_Int_Pickable_Item_Kind = 0x4327,
        ItemManage_Variable_Int_Have_Item_Size = 0x4328,
        ItemManage_Variable_Int_Have_Item_Kind = 0x4329,
        Motion_Variable_Int_Partial_1_Kind = 0x432A,
        Motion_Variable_Int_Partial_2_Kind = 0x432B,
        Motion_Variable_Int_Other_1_Kind = 0x432C,
        Motion_Variable_Int_Other_2_Kind = 0x432D,
        Motion_Variable_Int_Other_3_Kind = 0x432E,
        Motion_Variable_Int_Other_4_Kind = 0x432F,
        Motion_Variable_Int_Other_5_Kind = 0x4330,
        Controller_Variable_Int_Flick_X = 0x4E31,
        ItemManage_Variable_Int_Shoot_Item_Bullet = 0x4E32,
        ItemManage_Variable_Int_Have_Item_Hold_Kind = 0x4E33,
        Camera_Variable_Int_Quake_Kind = 0x4E34,
        Team_Variable_Int_No = 0x4E35,
        Instance_Variable_Int_Task_Id = 0x4E36,
        Ground_Variable_Int_Correct = 0x4E37,
        Kinetic_Variable_Int_Type = 0x4E38,
        Situation_Variable_Int_Kind = 0x4E39,
        Stage_Variable_Int_Default_Light_Set_Index = 0x4E3A
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
