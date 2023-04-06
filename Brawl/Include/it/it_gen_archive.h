#pragma once

#include <types.h>
#include <StaticAssert.h>
#include <it/it_archive.h>
#include <gm/gm_lib.h>

struct itSheet {
    Stages::srStageKind m_stageKind;
    int m_levelId;
};

class itGenArchive {
public:
    itArchive::Type m_itArchiveType;
    itSheet m_sheet;
    int m_archiveId;
    u8 m_16;
    u8 m_17;
    u8 m_18;
    char m_19[1];

    virtual ~itGenArchive();
};
