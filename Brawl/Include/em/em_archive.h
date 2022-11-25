#pragma once

#include <types.h>
#include <StaticAssert.h>

class emArchive {
    int enmCommonArchiveId;
    int brresArchiveId;
    int paramArchiveId;
    int brresArchiveId2;
    int brresArchiveId3;
    int primFaceBrresArchiveId;

    STATIC_CHECK(sizeof(emArchive) == 24)
};