#pragma once

#include <types.h>

namespace nw4r {
    namespace g3d {

        struct CLR0 {
            char _spacer2[0x1C];
            unsigned short m_animLength;
        };

        class AnmObjMatClrRes {
        public:
            virtual u32 IsDerivedFrom(int* unk1);

            virtual void G3dProc(int unk1, int unk2, int unk3);

            virtual ~AnmObjMatClrRes();

            virtual int* GetTypeObj();

            virtual int GetTypeName();

            virtual void SetFrame(float frame);

            virtual float GetFrame();

            virtual void UpdateFrame();

            virtual void SetUpdateRate(float updateRate);

            virtual float GetUpdateRate();

            virtual int Bind(int* unk1);

            virtual void Release();

            virtual int* GetResult(int* unk1, int unk2);

            virtual int Attach(int unk1, int* unk2); // TODO
            virtual int* Detach(int unk1);           // TODO
            virtual void DetachAll();

            AnmObjMatClrRes* Construct(int* unk1, int* unk2, int* unk3, int* unk4, u32 unk5);

            char _spacer[40];

            CLR0* m_anmMatClrFile;

            char _spacer2[4];
        };
    }
}

// Size: 52