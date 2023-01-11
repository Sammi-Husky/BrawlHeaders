#pragma once

#include <types.h>

namespace nw4r {
    namespace g3d {

        struct SCN0 {
            char _spacer2[0x30];
            unsigned short m_animLength;
        };

        class AnmScnRes {
        public:
            virtual u32 IsDerivedFrom(int *unk1);

            virtual void G3dProc(int unk1, int unk2, int unk3);

            virtual ~AnmScnRes();

            virtual int *GetTypeObj();

            virtual int GetTypeName();

            virtual void SetFrame(float frame);

            virtual float GetFrame();

            virtual void UpdateFrame();

            virtual void SetUpdateRate(float updateRate);

            virtual float GetUpdateRate();

            virtual int Bind(int *unk1);

            virtual void Release();

            virtual int *GetResult(int *unk1, int unk2);

            virtual int Attach(int unk1, int *unk2); // TODO
            virtual int *Detach(int unk1);           // TODO
            virtual void DetachAll();

            AnmScnRes *Construct(int *unk1, int *unk2, int *unk3, int *unk4);

            char _spacer[52];

        };
    }
}

// Size: 56