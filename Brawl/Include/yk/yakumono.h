#pragma once

#include <so/so_area_module_impl.h>
#include <so/so_gimmick_event_observer.h>


struct YakumonoAreaInfo {
    int field_0x0;
    int field_0x4;
    soAreaInit* init;
};

class Yakumono {
    public:
        void setSituationKind(int situationKind);
        void setColliisonHitOpponentCategory(int unk1, bool unk2);
        void setCollisionHitSelfCategory(int category);
        void setReactionFrame(int reactionFrame);
        void setTeamOwnerId(int teamOwnerId);
        void setTeam(int teamId);
        int getTeam();
    private:
        char _spacer[853];

};

