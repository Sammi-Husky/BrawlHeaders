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
    ANIM_CMD_ARG_INT = 0,
    ANIM_CMD_ARG_SCALAR = 1,
    ANIM_CMD_ARG_PTR = 2,
    ANIM_CMD_ARG_BOOL = 3,
    ANIM_CMD_ARG_FILE = 4,
    ANIM_CMD_ARG_VARIABLE = 5,
    ANIM_CMD_ARG_REQUIREMENT = 6
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
