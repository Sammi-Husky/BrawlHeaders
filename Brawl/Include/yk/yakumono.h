#pragma once

class Yakumono {
    public:
        void setSituationKind(int situationKind);
        void setColliisonHitOpponentCategory(int unk1, bool unk2);
        void setCollisionHitSelfCategory(int category);
        void setReactionFrame(int reactionFrame);

    private:
        char _spacer[853];

};

