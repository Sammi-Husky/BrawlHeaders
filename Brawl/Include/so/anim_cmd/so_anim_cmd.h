#pragma once

#include <StaticAssert.h>

class soAnimCmdArgument;
class soAnimCmd;

// Variable Data Type
#define ANIM_CMD_INT 0
#define ANIM_CMD_FLOAT 1
#define ANIM_CMD_BOOL 2 

// Variable Memory Type
#define ANIM_CMD_VAR_TYPE_IC 0
#define ANIM_CMD_VAR_TYPE_LA 1
#define ANIM_CMD_VAR_TYPE_RA 2

enum soAnimCmdArgumentType {
    AnimCmd_Arg_Type_Int = 0,
    AnimCmd_Arg_Type_Scalar = 1,
    AnimCmd_Arg_Type_Ptr = 2,
    AnimCmd_Arg_Type_Bool = 3,
    AnimCmd_Arg_Type_File = 4,
    AnimCmd_Arg_Type_Variable = 5,
    AnimCmd_Arg_Type_Requirement = 6
};

class soAnimCmdArgument {
public:
    soAnimCmdArgumentType m_varType;
    u32 m_rawValue;
};
static_assert(sizeof(soAnimCmdArgument) == 0x8, "Class is the wrong size!");

class soAnimCmd {
public:
    char m_module;
    char m_code;
    char m_argCount;
    char m_option;
    soAnimCmdArgument *m_args; // ptr to array
};
static_assert(sizeof(soAnimCmd) == 0x8, "Class is the wrong size!");
