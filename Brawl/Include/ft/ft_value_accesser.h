#pragma once

#include <types.h>
#include <so/so_value_accesser.h>

class ftValueAccesser : public soValueAccesser {
public:
    enum ParamFloat {
        Common_Param_Float_Walk_Stick_X = 0xC2D,

        Common_Param_Float_Walk_Motion_Rate_Max = 0xC320,
        Common_Param_Float_Turn_Stick_X = 0xC31,
        Common_Param_Float_Dash_Stick_X = 0xC32,
        Common_Param_Float_Dash_Escape_Frame = 0xC33, // TODO: Verify
        Common_Param_Float_Turn_Dash_Frame = 0xC34, // TODO: Verify
        Common_Param_Float_Dash_End_Speed_Mul = 0xC35,
        Common_Param_Float_Run_Stick_X = 0xC36,

        Common_Param_Float_Run_Brake_Brake_Mul = 0xC38,

        Common_Param_Float_Turn_Run_Stick_X = 0xC3A,

        Common_Param_Float_Squat_Stick_Y = 0xC3D,
        Common_Param_Float_Squat_F_Stick_X_Min = 0xC3E,
        Common_Param_Float_Squat_F_Stick_X_Max = 0xC3F,
        Common_Param_Float_Squat_B_Stick_X_Min = 0xC40,
        Common_Param_Float_Squat_B_Stick_X_Max = 0xC41,
        Common_Param_Float_Jump_Stick_Y = 0xC42,
        Common_Param_Float_Jump_Neutral_X = 0xC43,
        Common_Param_Float_Jump_Neutral_Y = 0xC44, // TODO: Verify
        Common_Param_Float_Jump_Run_Stick_Y = 0xC45,
        Common_Param_Float_Jump_Speed_Y_Mul = 0xC46, // TODO: Verify

        Common_Param_Float_Escape_Stick_Y = 0xC4C,
        Common_Param_Float_Escape_Fb_Stick_X = 0xC4D,

        Common_Param_Float_Attack_S3_Stick_X = 0xC4F,
        Common_Param_Float_Attack_S3_Stick_Dir_Hi = 0xC50,
        Common_Param_Float_Attack_S3_Stick_Dir_Lw = 0xC51,
        Common_Param_Float_Attack_Hi3_Stick_Y = 0xC52,
        Common_Param_Float_Attack_Lw3_Stick_Y = 0xC53,
        Common_Param_Float_Attack_S4_Stick_Dir_Hi = 0xC54,
        Common_Param_Float_Attack_S4_Stick_Dir_Lw = 0xC55,
        Common_Param_Float_Attack_Hi4_Stick_Y = 0xC56,
        Common_Param_Float_Attack_Hi4_Flick_Y = 0xC57,
        Common_Param_Float_Attack_Lw4_Stick_Y = 0xC58,
        Common_Param_Float_Attack_Lw4_Flick_Y = 0xC59,

        Common_Param_Float_Attack_Air_Neutral_X = 0xC5C,
        Common_Param_Float_Attack_Air_Neutral_Y = 0xC5D,

        Common_Param_Float_Dive_Cont_Value = 0xC5F,

        Common_Param_Float_Hit_Stop_Squat_Mul = 0xC63,
        Common_Param_Float_Hit_Stop_Guard_Mul = 0xC64, // TODO: Verify

        Common_Param_Float_Down_Frame = 0xC6B,
        Common_Param_Float_Stand_Stick_Y = 0xC6C,
        Common_Param_Float_Stand_Fb_Stick_X = 0xC6D,

        Common_Param_Float_Special_Stick_X = 0xC71,
        Common_Param_Float_Special_Stick_Y = 0xC72,
        Common_Param_Float_Pass_Stick_Y = 0xC73,
        Common_Param_Float_Pass_Speed_Y = 0xC74,

        Common_Param_Float_Cliff_Catch_Cancel_Stick_Y = 0xC78,

        Common_Param_Float_Passive_Fb_Cont_Value = 0xC73,

        Common_Param_Float_FuraFura_Frame = 0xC80,

        Common_Param_Float_FuraFura_Recovery = 0xC82,
        Common_Param_Float_FuraFura_Recovery_Clatter = 0xC83,

        Common_Param_Float_Wall_Jump_Stick_X = 0xC97,
        Common_Param_Float_Wall_Jump_Speed_Dec = 0xC98,
        Common_Param_Float_Wall_Jump_X_Speed_Dec = 0xC99,
        Common_Param_Float_Tread_Jump_Speed_Dec = 0xC9A,
        Common_Param_Float_Tread_Jump_Speed_Limit = 0xC9B,
        Common_Param_Float_Attach_Wall_Slant_Max = 0xC9C,
        Common_Param_Float_Attack_Wall_Slant_Min = 0xC9D,
        Common_Param_Float_Attach_Wall_Frame_Mul = 0xC9E,
        Common_Param_Float_Detach_Wall_Jump_X_Mul = 0xC9F,

        Common_Param_Float_Shield_Max = 0xCA1,
        Common_Param_Float_Shield_Scale_Min = 0xCA2,

        Common_Param_Float_Shield_Dec = 0xCA5,
        Common_Param_Float_Shield_Recovery = 0xCA6,
        Common_Param_Float_Shield_Reset = 0xCA7,
        Common_Param_Float_Shield_Damage_Mul = 0xCA8,
        Common_Param_Float_Shield_Damage_Add = 0xCA9,
        Common_Param_Float_Shield_SetOff_Mul = 0xCAA,
        Common_Param_Float_Shield_SetOff_Add = 0xCAB,
        Common_Param_Float_Shield_SetOff_Speed_Mul = 0xCAC,
        Common_Param_Float_Shield_SetOff_Speed_Max = 0xCAD,

        Common_Param_Float_Shield_Stiff_Mul_Attack_Air = 0xCB0,
        Common_Param_Float_Shield_Stiff_Mul_Attack_4 = 0xCB1,
        Common_Param_Float_Shield_Comp_Mul = 0xCB2,
        Common_Param_Float_Just_Shield_Rebound_Speed_Mul = 0xCB3,
        Common_Param_Float_Shield_Rebound_Speed_Mul = 0xCB4,
        Common_Param_Float_Shield_Rebound_Speed_Add = 0xCB5,
        Common_Param_Float_Shield_Rebound_Air_Brake = 0xCB6,
        Common_Param_Float_Shield_Rebound_Ground_Brake = 0xCB7,

        Common_Param_Float_Capture_Recovery = 0xCBB,
        Common_Param_Float_Capture_Recovery_Clatter = 0xCBC,

        Common_Param_Float_Capture_Cut_Dist_X = 0xCC0, // TODO: Verify
        Common_Param_Float_Capture_Cut_Dist_Y = 0xCC1, // TODO: Verify
        Common_Param_Float_Capture_Cut_Frame_Damage_Mul = 0xCC2,

        Common_Param_Float_Capture_Cut_Brake_Mul = 0xCC4, // TODO: Verify
        Common_Param_Float_Capture_Cut_Ground_Speed = 0xCC5,
        Common_Param_Float_Capture_Cut_Speed_X = 0xCC6,
        Common_Param_Float_Capture_Cut_Speed_Y = 0xCC7,

        Common_Param_Float_Damage_Fly_Speed_Y_Mul_Base_Accel = 0xCD8,
        Common_Param_Float_Damage_Fly_Speed_Y_Mul = 0xCD9,

        Common_Param_Float_Damage_Fly_Cloud_Through_Speed = 0xCDB,
        Common_Param_Float_Damage_Fly_Cloud_Through_Out_Speed_Mul = 0xCDC,
        Common_Param_Float_Damage_Ground_Mul = 0xCDD,
        Common_Param_Float_Damage_Air_Brake = 0xCDE,
        Common_Param_Float_Damage_Speed_Composition_Speed = 0xCDF,

        Common_Param_Float_Dead_Up_Damage_Speed = 0xCE6,

        Common_Param_Float_Damage_Fly_Ind_Speed_Max = 0xCEC,
        Common_Param_Float_Damage_Fly_Ind_Speed_Min = 0xCED,
        Common_Param_Float_Damage_Fly_Ind_Speed_Succeed_Mul = 0xCEE,
        Common_Param_Float_Damage_Fly_Ind_Weight_Mul = 0xCEF,
        Common_Param_Float_Damage_Song_Frame = 0xCF0,
        Common_Param_Float_Damage_Song_Frame_Bonus_Rank = 0xCF1,
        Common_Param_Float_Damage_Song_Frame_Bonus_Handi = 0xCF2,
        Common_Param_Float_Damage_Song_Frame_Bonus_Reaction = 0xCF3,
        Common_Param_Float_Damage_Song_Frame_Bonus_Damage = 0xCF4,
        Common_Param_Float_Damage_Song_Recovery = 0xCF5,
        Common_Param_Float_Damage_Song_Recovery_Clatter = 0xCF6,
        Common_Param_Float_Damage_Song_Fall_Speed_Limit = 0xCF7,
        Common_Param_Float_Damage_Bind_Frame = 0xCF8,
        Common_Param_Float_Damage_Bind_Frame_Bonus_Rank = 0xCF9,
        Common_Param_Float_Damage_Bind_Frame_Bonus_Handi = 0xCFA,
        Common_Param_Float_Damage_Bind_Frame_Bonus_Reaction = 0xCFB,
        Common_Param_Float_Damage_Bind_Frame_Bonus_Damage = 0xCFC,
        Common_Param_Float_Damage_Bind_Recovery = 0xCFD,
        Common_Param_Float_Damage_Bind_Recovery_Clatter = 0xCFE,
        Common_Param_Float_Damage_Bury_Frame = 0xCFF,
        Common_Param_Float_Damage_Bury_Frame_Bonus_Rank = 0xD00,
        Common_Param_Float_Damage_Bury_Frame_Bonus_Handi = 0xD01,
        Common_Param_Float_Damage_Bury_Frame_Bonus_Reaction = 0xD02,
        Common_Param_Float_Damage_Bury_Frame_Bonus_Damage = 0xD03,
        Common_Param_Float_Damage_Bury_Recovery = 0xD04,
        Common_Param_Float_Damage_Bury_Recovery_Clatter = 0xD05,
        Common_Param_Float_Damage_Bury_Jump_Y_Speed_Mul = 0xD06,
        Common_Param_Float_Damage_Bury_Jump_No_Attack_Frame_Value = 0xD07,
        Common_Param_Float_Damage_Bury_Damage_Reaction_Sub = 0xD08,
        Common_Param_Float_Damage_Ice_Fall_Y_Mul = 0xD09,
        Common_Param_Float_Damage_Ice_Reflect_Break_Speed = 0xD0A,
        Common_Param_Float_Damage_Ice_Reflect_Speed_Mul = 0xD0B,
        Common_Param_Float_Damage_Ice_Damage_Dec_Mul = 0xD0C,
        Common_Param_Float_Damage_Ice_Damage_Reaction_Dec_Mul = 0xD0D,
        Common_Param_Float_Damage_Ice_Damage_Air_Brake = 0xD0E,
        Common_Param_Float_Damage_Ice_Rot_Speed_Min = 0xD0F,
        Common_Param_Float_Damage_Ice_Rot_Speed_Max = 0xD10,
        Common_Param_Float_Damage_Ice_Frame_Damage_Mul = 0xD13,
        Common_Param_Float_Damage_Ice_Recovery = 0xD12,
        Common_Param_Float_Damage_Ice_Recovery_Clatter = 0xD13,
        Common_Param_Float_Damage_Ice_Recovery_Damage = 0xD14,
        Common_Param_Float_Damage_Ice_Effect_Radius = 0xD15,
        Common_Param_Float_Ladder_Stick_Y = 0xD16,
        Common_Param_Float_Ladder_Cancel_Frame = 0xD17,

        Common_Param_Float_Swim_Drown_Frame_Dec_Damage_Rate = 0xD1E,
        Common_Param_Float_Swim_Drown_Speed_X_Mul = 0xD1F,

        Common_Param_Float_Bitten_Frame_Add = 0xD2F,
        Common_Param_Float_Bitten_Frame_Damage_Mul = 0xD30,
        Common_Param_Float_Bitten_Recovery_Clatter = 0xD31,
        Common_Param_Float_Bitten_Motion_Rate = 0xD32,
        Common_Param_Float_Bitten_Motion_Rate_Frame = 0xD33,
        Common_Param_Float_Bitten_Flick_Frame = 0xD34, // TODO: Verify
        Common_Param_Float_Kirby_Swallowed_Offset_X = 0xD35,
        Common_Param_Float_Kirby_Swallowed_Offset_Y = 0xD36,
        Common_Param_Float_Kirby_Swallowed_Speed_X = 0xD37,
        Common_Param_Float_Kirby_Swallowed_Speed_Y = 0xD38,
        Common_Param_Float_Kirby_Swallowed_Comp_Dist = 0xD39,
        Common_Param_Float_Kirby_SwallowedCatch_Recovery_Clatter = 0xD3A,
        Common_Param_Float_Kirby_SwallowedCatch_Recovery = 0xD3B,
        Common_Param_Float_Kirby_SwallowedCatch_Frame = 0xD3C,
        Common_Param_Float_Kirby_SwallowedThrown_Recovery_Clatter = 0xD3D,
        Common_Param_Float_Kirby_SwallowedThrown_Recovery = 0xD3E,
        Common_Param_Float_Kirby_SwallowedThrown_Frame = 0xD3F,

        Common_Param_FLoat_Kirby_SwallowedThrown_Exit_Frame = 0xD41,
        Common_Param_Float_Kirby_SwallowedThrown_Exit_Speed_X = 0xD42,
        Common_Param_Float_Kirby_SwallowedThrown_Exit_Speed_Y = 0xD43,

        Common_Param_Float_Shouldered_Frame_Add = 0xD48,
        Common_Param_Float_Shouldered_Frame_Damage_Mul = 0xD49,
        Common_Param_Float_Shouldered_Recovery_Clatter = 0xD4A,
        Common_Param_Float_Shouldered_Recovery_Clatter_Air = 0xD4B,
        Common_Param_Float_Dedede_Swallowed_Offset_X = 0xD4C,
        Common_Param_Float_Dedede_Swallowed_Offset_Y = 0xD4D,
        Common_Param_Float_Dedede_Swallowed_Speed_X = 0xD4E,
        Common_Param_Float_Dedede_Swallowed_Speed_Y = 0xD4F,
        Common_Param_Float_Dedede_Swallowed_Comp_Dist = 0xD50,
        Common_Param_Float_Dedede_SwallowedCatch_Recovery_Clatter = 0xD51,
        Common_Param_Float_Dedede_SwallowedCatch_Recovery = 0xD52,
        Common_Param_Float_Dedede_SwallowedCatch_Frame = 0xD53,
        Common_Param_Float_Dedede_SwallowedThrown_Recovery_Clatter = 0xD54,
        Common_Param_Float_Dedede_SwallowedThrown_Recovery = 0xD55,
        Common_Param_Float_Dedede_SwallowedThrown_Frame = 0xD56,
        Common_Param_Float_Dedede_SwallowedThrown_Exit_Frame = 0xD57,
        Common_Param_Float_Dedede_SwallowedThrown_Exit_Speed_X = 0xD58,
        Common_Param_Float_Dedede_SwallowedThrown_Exit_Speed_Y = 0xD59,
        Common_Param_Float_Dedede_SwallowedEscape_Offset_X = 0xD5A,
        Common_Param_Float_Dedede_SwallowedEscape_Offset_Y = 0xD5B,
//        Common_Param_Float_Dedede_SwallowedEscape_1 = 0xD5C, // TODO: Check what these are
//        Common_Param_Float_Dedede_SwallowedEscape_2 = 0xD5D,
//        Common_Param_Float_Dedede_SwallowedEscape_3 = 0xD5E,
        Common_Param_Float_Diddy_Clung_Frame_Add = 0xD5F,
        Common_Param_Float_Diddy_Clung_Frame_Damage_Mul = 0xD60,
        Common_Param_Float_Diddy_Clung_Frame_Handicap_Mul = 0xD61,
        Common_Param_Float_Diddy_Clung_Frame_Air_Mul = 0xD62,
        Common_Param_Float_Diddy_Clung_Recovery_Clatter = 0xD63,
        Common_Param_Float_Diddy_Clung_Stop_Speed_X = 0xD64,

    };

    enum ParamInt {


    };

    virtual soParamAccesser* getExtendParamAccesser();
    virtual ~ftValueAccesser();
    virtual float getConstantFloatCore(soModuleAccesser* moduleAccesser, u32);
    virtual int getConstantIntCore(soModuleAccesser* moduleAccesser, u32);
    virtual void* getConstantIndefiniteCore(soModuleAccesser* moduleAccesser, u32);

    virtual float getVariableFloatCore(soModuleAccesser* moduleAccesser, u32);
    virtual int getVariableIntCore(soModuleAccesser* moduleAccesser, u32);

    virtual bool isControllerValueCore(soModuleAccesser* moduleAccesser, u32, u32);
    virtual bool isEnableSpeedOperationCore(soModuleAccesser* moduleAccesser);


};

