#pragma once

#include <StaticAssert.h>
#include <types.h>

class emArchive {
    int enmCommonArchiveId;
    int brresArchiveId;
    int paramArchiveId;
    int brresArchiveId2;
    int brresArchiveId3;
    int primFaceBrresArchiveId;
};
static_assert(sizeof(emArchive) == 24, "Class is wrong size!");