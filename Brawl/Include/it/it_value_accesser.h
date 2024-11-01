#pragma once

#include <types.h>
#include <so/so_value_accesser.h>
#include <it/it_archive.h>

class itValueAccesser : public soValueAccesser {
public:
    enum ParamFloat {
        Specialized_Param_Float_HitSize = 3401,
        Specialized_Param_Float_Throw_Speed_Mul = 3402,
        Specialized_Param_Float_2 = 3403,
        Specialized_Param_Float_Rot_Coef_X = 3404,
        Specialized_Param_Float_Rot_Coef_Y = 3405,
        Specialized_Param_Float_Rot_Coef_Z = 3406,
        Specialized_Param_Float_Rot_Appear_Mul = 3407,
        Specialized_Param_Float_Gravity_Accel = 3408,
        Specialized_Param_Float_Gravity_Accel_Max = 3409,
        Specialized_Param_Float_9 = 3410,
        Specialized_Param_Float_Nururi_Size_Up = 3411,
        Specialized_Param_Float_Nururi_Size_Down = 3412,
        Specialized_Param_Float_Nururi_Size_Left = 3413,
        Specialized_Param_Float_Nururi_Size_Right = 3414,
        Specialized_Param_Float_Pickup_Range_Offset_X = 3415,
        Specialized_Param_Float_Pickup_Range_Offset_Y = 3416,
        Specialized_Param_Float_Pickup_Range_Size_W = 3417,
        Specialized_Param_Float_Pickup_Range_Size_H = 3418,
        Specialized_Param_Float_MapColl_Size_Up = 3419,
        Specialized_Param_Float_MapColl_Size_Down = 3420,
        Specialized_Param_Float_MapColl_Size_HalfWidth = 3421,
        Specialized_Param_Float_Clip_Sphere_R = 3422,
        Specialized_Param_Float_Clip_Sphere_OffY = 3423,
        Specialized_Param_Float_Rot_Accel = 3424,
        Specialized_Param_Float_Rot_Brake = 3425,
        Specialized_Param_Float_Bound_RefSpeed_Mul_X = 3426,
        Specialized_Param_Float_Bound_RefSpeed_Mul_Y = 3427,
        Specialized_Param_Float_Bound_MinSpeed = 3428,
        Specialized_Param_Float_Bound_RefSpeed_Wall_Mul_X = 3429,
        Specialized_Param_Float_Bound_RefSpeed_Wall_Mul_Y = 3430,
        Specialized_Param_Float_Bound_RefSpeed_Ceiling_Mul_X = 3431,
        Specialized_Param_Float_Bound_RefSpeed_Ceiling_Mul_Y = 3432,
        Specialized_Param_Float_Bound_RefSpeed_Character_Mul = 3433,
        Specialized_Param_Float_Bound_RefSpeed_Character_Add_Y = 3434,
        Specialized_Param_Float_Air_Brake_X = 3435,
        Specialized_Param_Float_Ground_Brake_X = 3436,
        Specialized_Param_Float_Rot_Limit_Speed_X = 3437,
        Specialized_Param_Float_Rot_Limit_Speed_Y = 3438,
        Specialized_Param_Float_Throw_Power_Speed_Add = 3439,
        Specialized_Param_Float_Throw_Power_Speed_Mul = 3440,
        Specialized_Param_Float_Scale = 3441,
        Specialized_Param_Float_Hp = 3442,
    };

    enum ParamInt {
        Game_Param_Int_Remove_Flash_Frame = 23001,

        Specialized_Param_Int_AI_Pri = 23400,
        Specialized_Param_Int_Size_Kind = 23401,
        Specialized_Param_Int_Have_Kind = 23402,
        Specialized_Param_Int_3 = 23403,
        Specialized_Param_Int_4 = 23404,
        Specialized_Param_Int_Scale_Type = 23405,
        Specialized_Param_Int_Slope_Type = 23406,
        Specialized_Param_Int_Flash_Kind = 23407,
        Specialized_Param_Int_Camera_Kind = 23408,
        Specialized_Param_Int_Hit_Kind = 23409,
        Specialized_Param_Int_Reflect_Kind = 23410,
        Specialized_Param_Int_Shield_Kind = 23411,
        Specialized_Param_Int_DeadArea_Kind = 23412,
        Specialized_Param_Int_Attack_HitStop_Kind = 23413,
    };

    enum ParamIndefinite {

    };

    enum VariableFloat {
        Variable_Float_Damage_Log_Speed_Lr = 1000,
        Variable_Float_Damage_Log_Reaction = 1001,
        Variable_Float_Damage_Log_Angle = 1002,
        Variable_Float_Damage_Log_Frame = 1003,
        Variable_Float_Damage_Log_Speed_X = 1004,
        Variable_Float_Damage_Log_Speed_Y = 1005,
        Variable_Float_Kinetic_Sum_Speed = 1006,
        Variable_Float_Kinetic_Sum_Speed_X = 1007,
        Variable_Float_Kinetic_Sum_Speed_Y = 1008,
        Variable_Float_Kinetic_Energy_Control_Speed_X = 1009,
        Variable_Float_Kinetic_Energy_Control_Speed_Y = 1010,
        Variable_Float_Kinetic_Energy_Control_Rot_X = 1011,
        Variable_Float_Kinetic_Energy_Control_Rot_Y = 1012,
        Variable_Float_Kinetic_Energy_Control_Rot_Z = 1013,
        Variable_Float_Motion_Trans_Move_Speed_X = 1014,
        Variable_Float_Motion_Trans_Move_Speed_Y = 1015,
        Variable_Float_Target_Dist = 1016,
        Variable_Float_Target_Dist_X_Abs = 1017,
        Variable_Float_Target_Dist_Y_Abs = 1018,
        Variable_Float_Target_Dist_X = 1019,
        Variable_Float_Target_Dist_Y = 1020,
        Variable_Float_Target_Dist_X_Norm = 1021,
        Variable_Float_Target_Dist_Y_Norm = 1022,
        Variable_Float_Target_Dist_Z_Norm = 1023,
        Variable_Float_Kinetic_Slope_Angle = 1024,
        Variable_Float_Damage_Log_Damage_Add = 1025,
        Variable_Float_Damage_Log_Lr = 1026,
        Variable_Float_World_Scale_Pos_Z = 1027,
    };

    enum VariableInt {
        Variable_Int_Damage_Log_Level = 21000,
        Variable_Int_Damage_Log_Height = 21001,

        Variable_Int_Damage_Log_Hit_Stop_Frame = 21003,
        Variable_Int_Damage_Log_Attribute = 21004,
        Variable_Int_Damage_Log_Attacker_Task_Id = 21005,
        Variable_Int_Damage_Log_Attacker_Team_No = 21006,
        Variable_Int_Creator_Item_Kind = 21007,

        Variable_Int_Target_Situation_Kind = 21010,
        Variable_Int_Item_Variation = 21011,
        Variable_Int_Link_Owner_Task_Id = 21012,
        Variable_Int_Item_Kind = 21013,
        Variable_Int_Damage_Log_Attacker_Task_Category = 21014,
        Variable_Int_Damage_Log_Is_Attack_Direct = 21015,
        Variable_Int_Creator_Task_Id = 21016,
        Variable_Int_Link_Owner_Hit_Target_1_No = 21017,
        Variable_Int_Link_Owner_Hit_Target_2_No = 21018,
        Variable_Int_Link_Owner_Hit_Target_3_No = 21019,
        Variable_Int_Damage_Log_Attacker_Team_Owner_Id = 21020,
    };

    virtual soParamAccesser* getExtendParamAccesser();
    virtual ~itValueAccesser();
    virtual float getConstantFloatCore(soModuleAccesser* moduleAccesser, u32, u32);
    virtual int getConstantIntCore(soModuleAccesser* moduleAccesser, u32, u32);
    virtual void* getConstantIndefiniteCore(soModuleAccesser* moduleAccesser, u32, u32);

    virtual float getVariableFloatCore(soModuleAccesser* moduleAccesser, u32, u32);
    virtual int getVariableIntCore(soModuleAccesser* moduleAccesser, u32, u32);

};