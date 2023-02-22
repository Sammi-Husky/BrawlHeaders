#pragma once

#include <gm/gm_lib.h>

struct StageModuleId {
    StageKind kind;
    const char name[0x20];
};

void moUnResolvedMessage(char const* name);
char const* moGetStageModuleName(StageKind kind);
