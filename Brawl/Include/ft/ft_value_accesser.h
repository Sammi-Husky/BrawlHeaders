#pragma once

#include <types.h>
#include <so/so_value_accesser.h>
#include <ft/ft_common_data_accesser.h>
#include <ft/ft_info.h>

class ftValueAccesser : public soValueAccesser {
public:
    enum ParamFloat {
        Customize_Param_Float_Walk_Accel_Mul = 0xBB9,
        Customize_Param_Float_Walk_Accel_Add = 0xBBA,
        Customize_Param_Float_Walk_Speed_Max = 0xBBB,
        Customize_Param_Float_Ground_Brake = 0xBBC,
        Customize_Param_Float_Dash_Speed = 0xBBD,
        Customize_Param_Float_Run_Accel_Mul = 0xBBE,
        Customize_Param_Float_Run_Accel_Add = 0xBBF,
        Customize_Param_Float_Run_Speed_Max = 0xBC0,

        Customize_Param_Float_Ground_Speed_X_Limit = 0xBC2,
        Customize_Param_Float_Guard_Speed_Limit = 0xBC3,
        Customize_Param_Float_Jump_Speed_X = 0xBC4,
        Customize_Param_Float_Jump_Speed_Y = 0xBC5,
        Customize_Param_Float_Jump_Speed_X_Mul = 0xBC6,
        Customize_Param_Float_Jump_Speed_X_Max = 0xBC7,
        Customize_Param_Float_Mini_Jump_Speed_Y = 0xBC8,
        Customize_Param_Float_Jump_Aerial_Speed_Y = 0xBC9,
        Customize_Param_Float_Jump_Aerial_Speed_X_Mul = 0xBCA,
        Customize_Param_Float_Tread_Jump_Speed_Y_Mul = 0xBCB,
        Customize_Param_Float_Tread_Mini_Jump_Speed_Y_Mul = 0xBCC,
        Customize_Param_Float_Tread_Fall_Recovery_Frame = 0xBCD,
        Customize_Param_Float_Meteor_Recovery_Frame = 0xBCE,
        Customize_Param_Float_Air_Accel_Y = 0xBCF,
        Customize_Param_Float_Air_Speed_Y_Stable = 0xBD0,
        Customize_Param_Float_Air_Brake_Y = 0xBD1,

        Customize_Param_Float_Air_Accel_X_Mul = 0xBD3,
        Customize_Param_Float_Air_Accel_X_Add = 0xBD4,
        Customize_Param_Float_Air_Speed_X_Stable = 0xBD5,
        Customize_Param_Float_Air_Brake_X = 0xBD6,
        Customize_Param_Float_Dive_Speed_Y = 0xBD7,

        Customize_Param_Float_Combo_Attack_12_End = 0xBDA,
        Customize_Param_Float_Combo_Attack_13_End = 0xBDB,
        Customize_Param_Float_Combo_Attack_32_End = 0xBDC,
        Customize_Param_Float_Combo_Attack_33_End = 0xBDD,
        Customize_Param_Float_Combo_Attack_42_End = 0xBDE,
        Customize_Param_Float_Flip_Dir_Frame = 0xBDF,

        Customize_Param_Float_Weight = 0xBE1,
        Customize_Param_Float_Scale = 0xBE2,
        Customize_Param_Float_Result_Scale_Mul = 0xBE3,
        Customize_Param_Float_Height = 0xBE4,
        Customize_Param_Float_Expand_Height = 0xBE5,
        Customize_Param_Float_Shield_Radius = 0xBE6,
        Customize_Param_Float_Shield_Break_Y = 0xBE7,
        Customize_Param_Float_Jostle_Weight = 0xBE8,
        Customize_Param_Float_Effect_Scale = 0xBE9,
        Customize_Param_Float_Entry_Stand_Scale = 0xBEA,

        Customize_Param_Float_Cliff_Jump_Speed_X = 0xBF1,
        Customize_Param_Float_Cliff_Jump_Speed_Y = 0xBF2,
        Customize_Param_Float_Item_Lift_Accel_Mul = 0xBF3,
        Customize_Param_Float_Item_Lift_Accel_Add = 0xBF4,
        Customize_Param_Float_Item_Lift_Speed_Max = 0xBF5,
        Customize_Param_Float_Item_Grip_Offset_X = 0xBF6,
        Customize_Param_Float_Item_Grip_Offset_Y = 0xBF7,
        Customize_Param_Float_Item_Grip_Offset_Z = 0xBF8,
        Customize_Param_Float_Throw_Item_Speed_Mul = 0xBF9,
        Customize_Param_Float_Throw_Item_Power_Mul = 0xBFA,
        Customize_Param_Float_Shoot_Walk_Accel_Mul = 0xBFB,
        Customize_Param_Float_Shoot_Walk_Accel_Add = 0xBFC,
        Customize_Param_Float_Shoot_Walk_Speed_Max = 0xBFD,
        Customize_Param_Float_Shoot_Dash_Speed_F = 0xBFE,
        Customize_Param_Float_Shoot_Dash_Speed_B = 0xBFF,

        Customize_Param_Float_Landing_Frame_Light = 0xC01,
        Customize_Param_Float_Landing_Frame = 0xC02,
        Customize_Param_Float_Landing_Attack_Air_Frame_N = 0xC03,
        Customize_Param_Float_Landing_Attack_Air_Frame_F = 0xC04,
        Customize_Param_Float_Landing_Attack_Air_Frame_B = 0xC05,
        Customize_Param_Float_Landing_Attack_Air_Frame_Hi = 0xC06,
        Customize_Param_Float_Landing_Attack_Air_Frame_Lw = 0xC07,
        Customize_Param_Float_Cursor_Offset_Y = 0xC08,
        Customize_Param_Float_Passive_Wall_Speed_X = 0xC09,
        Customize_Param_Float_Passive_Wall_Jump_Speed_X = 0xC0A,
        Customize_Param_Float_Passive_Wall_Jump_Speed_Y = 0xC0B,
        Customize_Param_Float_Passive_Ceil_Speed_X = 0xC0C,
        Customize_Param_Float_Wall_Jump_Enable_Speed_X = 0xC0D,
        Customize_Param_Float_Ladder_Speed_U_Max = 0xC0E,
        Customize_Param_Float_Ladder_Speed_D_Max = 0xC0F,
        Customize_Param_Float_Swim_Dive_Speed_Mul = 0xC10,
        Customize_Param_Float_Swim_Rise_Accel_Y = 0xC11,
        Customize_Param_Float_Swim_Rise_Stable_Speed_Y = 0xC12,
        Customize_Param_Float_Swim_Accel_Mul = 0xC13,
        Customize_Param_Float_Swim_Speed_Mul = 0xC14,
        Customize_Param_Float_Swim_Brake = 0xC15,
        Customize_Param_Float_Swim_Drown_Out_Accel_Y_Frame = 0xC16,
        Customize_Param_Float_Star_Scale = 0xC17,
        Customize_Param_Float_Egg_Scale = 0xC18,
        Customize_Param_Float_Egg_Collision_Offset_1_X = 0xC19,
        Customize_Param_Float_Egg_Collision_Offset_1_Y = 0xC1A,
        Customize_Param_Float_Egg_Collision_Offset_1_Z = 0xC1B,
        Customize_Param_Float_Egg_Collision_Offset_2_X = 0xC1C,
        Customize_Param_Float_Egg_Collision_Offset_2_Y = 0xC1D,
        Customize_Param_Float_Egg_Collision_Offset_2_Z = 0xC1E,
        Customize_Param_Float_Egg_Collision_Size = 0xC1F,

        Customize_Param_Float_Ice_Offset_Y = 0xC24,
        Customize_Param_Float_Ice_Offset_Z = 0xC25,
        Customize_Param_Float_Ice_Radius = 0xC26,
        Customize_Param_Float_Ice_Jump_Speed_Y_Mul = 0xC27,
        Customize_Param_Float_Ice_Jump_Speed_X = 0xC28,

        Customize_Param_Float_Slope_Top_Angle_Max = 0xC2A,


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
        Common_Param_Float_Jump_Speed_Y_Mul = 0xC46,

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

        Common_Param_Float_Spring_Jump_Mul = 0xC7D,
        Common_Param_Float_Passive_Fb_Cont_Value = 0xC7E,
        Common_Param_Float_Passive_Ground_Damage_Speed_Mul = 0xC7F,
        Common_Param_Float_FuraFura_Frame = 0xC80,

        Common_Param_Float_FuraFura_Recovery = 0xC82,
        Common_Param_Float_FuraFura_Recovery_Clatter = 0xC83,

        Common_Param_Float_Slip_Damage_Rate_Max = 0xC86,
        Common_Param_Float_Slip_Damage_Rate_Min = 0xC87,
        Common_Param_Float_Slip_Mul = 0xC88,
        Common_Param_Float_Slip_Dash_Rate_Max = 0xC89,
        Common_Param_Float_Slip_Dash_Rate_Min = 0xC8A,
        Common_Param_Float_Slip_Turn_Rate_Max = 0xC8B,
        Common_Param_Float_Slip_Turn_Rate_Min = 0xC8C,
        Common_Param_Float_Loupe_Damage_Limit = 0xC8D,
        Common_Param_Float_Loupe_Damage = 0xC8E,
        Common_Param_Float_Cursor_Fly_Speed = 0xC8F,
        Common_Param_Float_Cursor_Disp_Camera_Distance = 0xC90,

        Common_Param_Float_Stop_Ceil_Speed_X_Mul = 0xC94,
        Common_Param_Float_Stop_Ceil_Speed_Y_Mul = 0xC95,
        Common_Param_Float_Stop_Ceil_Speed_X_Stable_Mul = 0xC96,
        Common_Param_Float_Wall_Jump_Stick_X = 0xC97,
        Common_Param_Float_Wall_Jump_Speed_Dec = 0xC98,
        Common_Param_Float_Wall_Jump_Speed_X_Dec = 0xC99,
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

        Common_Param_Float_Damage_Fly_Reflect_Speed = 0xCD4,
        Common_Param_Float_Damage_Fly_Reflect_Speed_Mul = 0xCD5,

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
        Common_Param_Float_Damage_Bury_Jump_Speed_Y_Mul = 0xD06,
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
        Common_Param_Float_Ladder_Jump_Y_Mul = 0xD18,

        Common_Param_Float_Swim_Dive_Speed_X_Mul = 0xD1B,
        Common_Param_Float_Swim_Jump_Charge_Accel_Y = 0xD1C,
        Common_Param_Float_Swim_Jump_Speed_Y_Mul = 0xD1D,
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

        Common_Param_Float_Item_Lift_Walk_Stick_X = 0xD77,
        Common_Param_Float_Item_Turn_Stick_X = 0xD78,

        Common_Param_Float_Shoot_Jump_Speed_Y_Mul = 0xD7E,
        Common_Param_Float_Item_Pickup_Light_Walk_Mul = 0xD7F,
        Common_Param_Float_Damage_Drop_Dragoon_Angle = 0xD80,
        Common_Param_Float_Damage_Drop_Dragoon_Speed = 0xD81,
        Common_Param_Float_Flower_Recovery = 0xD82,
        Common_Param_Float_Flower_Recovery_Clatter = 0xD83,
        Common_Param_Float_Flower_Frame_Max = 0xD84,
        Common_Param_Float_Flower_Damage_Add_Frame_Rate = 0xD85,
        Common_Param_Float_Flower_Scale_Min = 0xD86,
        Common_Param_Float_Flower_Scale_Max = 0xD87,
        Common_Param_Float_Flower_Damage_Add_Scale_Rate = 0xD88,

        Common_Param_Float_Gekikara_Motion_Rate = 0xD8A,
        Common_Param_Float_Gekikara_Fire_Shoot_Angle = 0xD8B,
        Common_Param_Float_Gekikara_Fire_Shoot_Angle_Speed = 0xD8C,
        Common_Param_Float_Gekikara_Fire_Shoot_Angle_Min = 0xD8D,
        Common_Param_Float_Gekikara_Fire_Shoot_Angle_Max = 0xD8E,
        Common_Param_Float_Screw_Jump_Speed_Y_Mul = 0xD8F,

        Common_Param_Float_Kinoko_Giant_Scale = 0xD91,

        Common_Param_Float_Kinoko_Small_Scale = 0xD93,
        Common_Param_Float_Kinoko_Pitch_Big = 0xD94,
        Common_Param_Float_Kinoko_Pitch_Small = 0xD95,
        Common_Param_Float_Kinoko_Bonus_Damage = 0xD96,

        Common_Param_Float_Thunder_Giant_Scale = 0xD98,

        Common_Param_Float_Thunder_Small_Scale = 0xD9A,
        Common_Param_Float_Thunder_Pitch_Big = 0xD9B,
        Common_Param_Float_Thunder_Pitch_Small = 0xD9C,
        Common_Param_Float_Metal_Cancel_Damage = 0xD9D,
        Common_Param_Float_Metal_Damage_Reaction_Sub = 0xD9E,
        Common_Param_Float_Team_Healing_Heal_Team_Mul = 0xD9F,
        Common_Param_Float_Team_Healing_Heal_Opponent_Rate = 0xDA0,
        Common_Param_Float_Team_Healing_Heal_Opponent_Mul = 0xDA1,
        Common_Param_Float_Pit_Fall_Speed = 0xDA2,
        Common_Param_Float_Pit_Fall_Accel = 0xDA3,
        Common_Param_Float_Pit_Fall_Speed_Max = 0xDA4,


        Owner_Param_Float_Damage_Ratio = 0xDAE,
        Owner_Param_Float_Attack_Reaction_Mul = 0xDAF,
        Owner_Param_Float_Damage_Reaction_Mul = 0xDB0,
        Owner_Param_Float_Special_Glow_Attack = 0xDB1,
        Owner_Param_Float_Auto_Handi = 0xDB2,
        Owner_Param_Float_Slip_Mul = 0xDB3,
        Owner_Param_Float_Result_Win_Rot_Y = 0xDB4,
    };

    enum ParamInt {
        Customize_Param_Int_Run_Brake_Attack_Dash_Frame = 0x59D9,
        Customize_Param_Int_Jump_Squat_Frame = 0x59DA,
        Customize_Param_Int_Jump_Count_Max = 0x59DB,
        Customize_Param_Int_Jump_Glide_Frame = 0x59DC,

        Customize_Param_Int_Landing_Heavy_Frame = 0x59DF,

        Customize_Param_Int_No_Ladder_Frame = 0x59E1,
        Customize_Param_Int_Ladder_Hand_Node_Index_1 = 0x59E2,
        Customize_Param_Int_Ladder_Hand_Node_Index_2 = 0x59E3,
        Customize_Param_Int_Star_Attack_Power = 0x59E4,

        Customize_Param_Int_Ice_Node_Index = 0x59E6,

        Customize_Param_Int_Dead_Rare_SE_Rate = 0x59E9,

        // 0x59F3


        Common_Param_Int_Dash_Flick_X = 0x59F7,
        Common_Param_Int_Dash_Speed_Keep_Frame = 0x59F8,
        Common_Param_Int_Re_Dash_Frame = 0x59F9,
        Common_Param_Int_Turn_Dash_Frame = 0x59FA, // TODO: verify
        Common_Param_Int_Jump_Initial_Frame = 0x59FB,
        Common_Param_Int_Jump_Flick_Y = 0x59FC,
        Common_Param_Int_Escape_Flick_Y = 0x59FD,
        Common_Param_Int_Escape_Fb_Flick_X = 0x59FE,
        Common_Param_Int_Dive_Flick_Frame = 0x59FF,

        Common_Param_Int_Hit_Stop_Delay_Flick_Frame = 0x5A01,
        Common_Param_Int_Damage_Turn_Reverse_Cont_Frame = 0x5A02,
        Common_Param_Int_Status_Start_Turn_Frame = 0x5A03,
        Common_Param_Int_Special_Smash_Flick_X = 0x5A04,  // TODO: Verify
        Common_Param_Int_Special_Air_N_Turn_Frame = 0x5A05,
        Common_Param_Int_Pass_Flick_Y = 0x5A06,
        Common_Param_Int_Cliff_Catch_Move_Frame = 0x5A07,
        Common_Param_Int_Cliff_Catch_Time_Quick = 0x5A08,
        Common_Param_Int_Cliff_Wait_Air_Xlu_Max_Air_Frame = 0x5A09,
        Common_Param_Int_Cliff_No_Catch_Frame = 0x5A0A,
        Common_Param_Int_Cliff_Wait_Xlu_Frame = 0x5A0B,
        Common_Param_Int_Passive_Trigger_Frame = 0x5A0C,
        Common_Param_Int_No_Rapid_Frame_Value = 0x5A0D,
        Common_Param_Int_Passive_Wall_Stop_Frame = 0x5A0E,

        Common_Param_Int_Air_Escape_Passive_Trigger_Frame = 0x5A10,

        Common_Param_Int_Slip_Damage_Disable_Frame = 0x5A11,
        Common_Param_Int_Slip_Wait_Frame = 0x5A12,
        Common_Param_Int_Slip_Disable_Frame = 0x5A13,

        Common_Param_Int_Damage_Drop_Smash_Ball = 0x5A17,
        Common_Param_Int_Damage_Drop_Smash_Ball_Handicap = 0x5A18,

        Common_Param_Int_Discretion_Final_Point_Diff = 0x5A1B,
        Common_Param_Int_No_Discretion_Final_Beat_Count = 0x5A1C,
        Common_Param_Int_Wall_Jump_Interval_Frame = 0x5A1D,
        Common_Param_Int_Wall_Jump_Flick_X = 0x5A1E,
        Common_Param_Int_Wall_Jump_Stop_Frame = 0x5A1F,
        Common_Param_Int_Wall_Jump_Disable_Cont_Frame = 0x5A20,
        Common_Param_Int_Tread_Attack_Frame = 0x5A21, // TODO: Verify
        Common_Param_Int_Attach_Wall_Frame = 0x5A22,
        Common_Param_Int_Attach_Wall_Disable_Frame = 0x5A23,
        Common_Param_Int_Shield_Min_Frame = 0x5A24,

        Common_Param_Int_Shield_Just_Frame = 0x5A26,
        Common_Param_Int_Continue_Just_Shield_Count = 0x5A27,
        Common_Param_Int_Guard_Off_Cancel_Frame = 0x5A28,
        Common_Param_Int_Catch_Dash_Frame = 0x5A29,
        Common_Param_Int_Catch_Turn_Frame = 0x5A2A,

        Common_Param_Int_Capture_Cut_Jump_Button_Count = 0x5A2C,
        Common_Param_Int_Capture_Cut_Frame = 0x5A2D,
        Common_Param_Int_Throw_Invincible_Frame = 0x5A2E,

        Common_Param_Int_Damage_Fly_Attack_Frame = 0x5A30,
        Common_Param_Int_Damage_Fly_Escape_Frame = 0x5A31,

        Common_Param_Int_Rebirth_Wait_Frame = 0x5A3D,
        Common_Param_Int_Rebirth_Invincible_Frame = 0x5A3E,

        Common_Param_Int_Bury_Down_Frame = 0x5A40,
        Common_Param_Int_Bury_Physics_Invalid_Frame = 0x5A41,
        Common_Param_Int_Ice_Jump_Stiff_Frame = 0x5A42,

        Common_Param_Int_Swim_Jump_Charge_Frame = 0x5A45,
        Common_Param_Int_Swim_Jump_Speed_Y_Dec_Count = 0x5A46,
        Common_Param_Int_Swim_Effect_Interval_Frame = 0x5A47,
        Common_Param_Int_Swim_Drown_Frame = 0x5A48,
        Common_Param_Int_Swim_Drown_Out_Frame = 0x5A49,
        Common_Param_Int_Swim_Drown_Effect_Interval_Frame = 0x5A4A,

        Common_Param_Int_Item_Throw_4_Flick = 0x5A54,
        Common_Param_Int_Item_Air_Throw_4_Flick = 0x5A55,
        Common_Param_Int_Item_Catch_Frame_Attack_Dash = 0x5A56,
        Common_Param_Int_Item_Air_Catch_Frame = 0x5A57,
        Common_Param_Int_Item_Air_Catch_Frame_Escape = 0x5A58,
        Common_Param_Int_Item_No_Air_Catch_Frame = 0x5A59,
        Common_Param_Int_Damage_Drop_Item = 0x5A5A,
        Common_Param_Int_Damage_Drop_Item_Empty = 0x5A5B,

        Common_Param_Int_Damage_Drop_Dragoon = 0x5A66,
        Common_Param_Int_Damage_Drop_Dragoon_Handicap = 0x5A67,
        Common_Param_Int_Dragoon_Invincible_Frame = 0x5A68,

        Common_Param_Int_Gekikara_Frame = 0x5A6C,
        Common_Param_Int_Gekikara_Fire_Shoot_Interval = 0x5A6D,
        Common_Param_Int_Hammer_Frame = 0x5A6E,
        Common_Param_Int_Hammer_Landing_Frame = 0x5A6F,
        Common_Param_Int_Hammer_Throw_Frame = 0x5A70,
        Common_Param_Int_Golden_Hammer_Frame = 0x5A71,
        Common_Param_Int_Golden_Hammer_Hande_Frame = 0x5A72,
        Common_Param_Int_Golden_Hammer_Beat_Dec_Frame = 0x5A73,
        Common_Param_Int_Golden_Hammer_End_Flash_Frame = 0x5A74,
        Common_Param_Int_Golden_Hammer_Drift_Frame = 0x5A75,
        //Common_Param_Int_Golden_Hammer_ = 0x5A76,
        Common_Param_Int_Super_Star_Frame = 0x5A77,
        Common_Param_Int_Super_Star_SE_Frame = 0x5A78,
        Common_Param_Int_Kinoko_Frame = 0x5A79,
        Common_Param_Int_Kinoko_Bonus_Max = 0x5A7A,
        Common_Param_Int_Thunder_Frame = 0x5A7B,

        Common_Param_Int_Metal_Frame = 0x5A7D,
        Common_Param_Int_Timer_Slow_Mag = 0x5A7E,
        Common_Param_Int_Timer_Frame = 0x5A7F,

        Common_Param_Int_Timer_Beat_Dec_Frame = 0x5A81,


        Owner_Param_Int_Shield_Break_Frame_Add = 0x5A86,
        Owner_Param_Int_Swim_Drown_Frame_Add = 0x5A87,
        Entry_Param_Int_Rank = 0x5A88,
        Owner_Param_Int_Stock_Count = 0x5A89,


        Info_Param_Int_Attack_Combo_Type = 0x5A8C,
        Info_Param_Int_Attack_Combo_Max = 0x5A8D,
        Info_Param_Int_Attack_100_Type = 0x5A8E,
        Info_Param_Int_S3_Combo_Max = 0x5A8F,
        Info_Param_Int_S4_Combo_Max = 0x5A90,
        Info_Param_Int_Jump_Aerial_Type = 0x5A91,
        Info_Param_Int_Glide_Type = 0x5A92,
        Info_Param_Int_Squat_Walk_Type = 0x5A93,
        Info_Param_Int_Attack_Dash_Type = 0x5A94,
        Info_Param_Int_Wall_Jump_Type = 0x5A95,
        Info_Param_Int_Attach_Wall_Type = 0x5A96,
        Info_Param_Int_Air_Lasso_Type = 0x5A97,
        Info_Param_Int_Motion_Share_Type = 0x5A98,
        Info_Param_Int_Capture_Motion_Height = 0x5A99,
    };

    enum ParamIndefinite {

    };

    enum VariableFloat {
        Variable_Float_Kinetic_Sum_Speed = 0x3E8,
        Variable_Float_Kinetic_Sum_Speed_X = 0x3E9,
        Variable_Float_Kinetic_Sum_Speed_Y = 0x3EA,
        Variable_Float_Motion_Trans_Move_Speed_X = 0x3EB,
        Variable_Float_Motion_Trans_Move_Speed_Y = 0x3EC,
        Variable_Float_Kinetic_Energy_Damage_Speed = 0x3ED,
        Variable_Float_Kinetic_Energy_Damage_Speed_X = 0x3EE,
        Variable_Float_Kinetic_Energy_Damage_Speed_X_Rv = 0x3EF,
        Variable_Float_Kinetic_Energy_Damage_Speed_Y = 0x3F0,
        Variable_Float_Kinetic_Energy_Damage_Speed_Y_Rv = 0x3F1,
        Variable_Float_Controller_Stick_X = 0x3F2,
        Variable_Float_Controller_Stick_X_Lr = 0x3F3,
        Variable_Float_Controller_Stick_X_Lr_Rv = 0x3F4,
        Variable_Float_Controller_Stick_X_Abs = 0x3F5,
        Variable_Float_Controller_Stick_X_Rv = 0x3F6,

        Variable_Float_Controller_Stick_X_Kinetic_Sum_Speed_Lr = 0x3F9,
        Variable_Float_Controller_Stick_Y = 0x3FA,
        Variable_Float_Controller_Stick_Y_Abs = 0x3FB,
        Variable_Float_Controller_Stick_Y_Rv = 0x3FC,
        Variable_Float_Controller_Stick_Dir = 0x3FD,
        Variable_Float_Controller_Stick_Prev_X = 0x3FE,
        Variable_Float_Controller_Stick_Prev_X_Lr = 0x3FF,
        Variable_Float_Controller_Stick_Prev_X_Lr_Rv = 0x400,
        Variable_Float_Controller_Stick_Prev_X_Abs = 0x401,
        Variable_Float_Controller_Stick_Prev_Y = 0x402,
        Variable_Float_Controller_Stick_Prev_Y_Abs = 0x403,
        Variable_Float_Controller_Stick_Prev_Y_Rv = 0x404,
        Variable_Float_Throw_Item_Speed = 0x405,
        Variable_Float_Throw_Item_Angle = 0x406,
        Variable_Float_Throw_Item_Power = 0x407,
        Variable_Float_Item_Pickup_Light_Range = 0x408,
        Variable_Float_Item_Swing_Motion_Rate = 0x409,
        Variable_Float_Tread_Jump_Speed_Y = 0x40A,
        Variable_Float_Motion_Frame = 0x40B,
        Variable_Float_Motion_Rate = 0x40C,
    };

    enum VariableInt {
        Variable_Int_Combo_Count = 0x5208,
        Variable_Int_Controller_Flick_X = 0x5209,
        Variable_Int_Controller_Flick_Y = 0x520A,
        Variable_Int_Controller_Flick_No_Reset_X = 0x520B,
        Variable_Int_Controller_Flick_No_Reset_Y = 0x520C,
        Variable_Int_Controller_Flick_After_X = 0x520D,
        Variable_Int_Controller_Flick_After_Y = 0x520E,
        Variable_Int_Controller_Flick_X_Dir = 0x520F,
        Variable_Int_Controller_Flick_Y_Dir = 0x5210,
        Variable_Int_Controller_Trigger_1_Count = 0x5211,
        Variable_Int_Controller_Trigger_1_Count_Prev = 0x5212,
        Variable_Int_Controller_Trigger_2_Count = 0x5213,
        Variable_Int_Controller_Trigger_2_Count_Prev = 0x5214,
        Variable_Int_Controller_Trigger_3_Count = 0x5215,
        Variable_Int_Controller_Trigger_3_Count_Prev = 0x5216,
        Variable_Int_Controller_Trigger_4_Count = 0x5217,
        Variable_Int_Controller_Trigger_4_Count_Prev = 0x5218,
        Variable_Int_Controller_Trigger_5_Count = 0x5219,
        Variable_Int_Controller_Trigger_5_Count_Prev = 0x521A,
        Variable_Int_Controller_Flick_X_Lr = 0x521B,
        Variable_Int_Controller_Flick_X_Lr_Rv = 0x521C,
        Variable_Int_Controller_Flick_After_X_Lr_Rv = 0x521D,
        Variable_Int_Item_Swing_1_Motion_Kind = 0x521E,
        Variable_Int_Item_Swing_3_Motion_Kind = 0x521F,
        Variable_Int_Item_Swing_4_Motion_Kind = 0x5220,
        Variable_Int_Item_Swing_Dash_Motion_Kind = 0x5221,
        Variable_Int_Item_Wait_Motion_Kind = 0x5222,
        Variable_Int_Item_Squat_Wait_Motion_Kind = 0x5223,
        Variable_Int_Win_Pose_Kind = 0x5224,
        Variable_Int_Player_Color_Kind = 0x5225,
    };

    virtual soParamAccesser* getExtendParamAccesser();
    virtual ~ftValueAccesser();
    virtual float getConstantFloatCore(soModuleAccesser* moduleAccesser, u32, u32);
    virtual int getConstantIntCore(soModuleAccesser* moduleAccesser, u32, u32);
    virtual void* getConstantIndefiniteCore(soModuleAccesser* moduleAccesser, u32, u32);

    virtual float getVariableFloatCore(soModuleAccesser* moduleAccesser, u32, u32);
    virtual int getVariableIntCore(soModuleAccesser* moduleAccesser, u32, u32);

    virtual bool isControllerValueCore(soModuleAccesser* moduleAccesser, u32, u32);
    virtual bool isEnableSpeedOperationCore(soModuleAccesser* moduleAccesser);


};

