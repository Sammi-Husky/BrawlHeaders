#pragma once

#include <types.h>
#include <mt/mt_vector.h>
#include <ft/fighter.h>
#include <so/damage/so_damage_attacker_info.h>

class ftManager {
    char _spacer[352];

    public:
        int getEntryCount();
        int getEntryIdFromIndex(int index);
        int getEntryIdFromTaskId(int taskId, int* unk);
        Fighter* getFighter(int entryId, int unk);
        int getTeam(int entryId, bool unk2, bool unk3);
        Fighter* searchNearFighter(float unk1, float radius, Vec3f* pos, int team, bool unk4);
        void setHeal(int entryId, float heal);
        void setCurry(int entryId);
        void setSuperStar(int entryId);
        void setSlow(int inflictingTeam, bool setStatus, int slowStrength, int slowDuration);
        void setTimerSlow(int inflictingEntryId, bool setStatus, int slowStrength, int slowDuration);
        void setScaling(int entryId, int unk1, int unk2);
        void setInfiniteScaling(int entryId, int unk1, int unk2);
        void setThunder(int inflictingEntryId, int unk2);
        void setDead(int entryId, int unk1, int unk2);

        bool isProcessHeartSwap(int entryId);
        void toKnockOutHeartSwapOpposite(int entryId, soDamageAttackerInfo* attackerInfo);
};

extern ftManager* g_ftManager;