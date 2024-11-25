#pragma once

#include <gr/gr_yakumono.h>
#include <types.h>

class grGimmickAreaCommon : public grYakumono {
protected:
    stGimmickAreaData* m_gimmickAreaData;
    soAreaData m_areaData;
    soSet<soAreaData> m_areaDataSet;
    ykAreaData m_ykData;

public:
    grGimmickAreaCommon(const char* taskName);
    virtual void update(float deltaFrame);
    virtual void startup(gfArchive* archive, u32 unk1, u32 unk2);
    virtual void onGimmickEvent(soGimmickEventInfo* eventInfo, int* taskId);
    virtual ~grGimmickAreaCommon();

};
static_assert(sizeof(grGimmickAreaCommon) == 0x188, "Class is wrong size!");