#pragma once

#include <gr/gr_yakumono.h>
#include <StaticAssert.h>

class grSeqYakumono : public grYakumono {

protected:
    class SeSeqBank {
        char _0[8];

        STATIC_CHECK(sizeof(SeSeqBank) == 8)
    };

    SeSeqBank* m_seSeqBanks;
    u32 m_numSeSeqBanks;

    char _spacer[4];

public:
    grSeqYakumono(char* taskName);
    void createSeSeqWork(int unk1);
    void playSeSeq(float unk1, int unk2);
    void playSeSeq(float unk1, float unk2, float unk3);
    void registSeSeq(unsigned int unk1, int unk2, int unk3);

    virtual ~grSeqYakumono();

    STATIC_CHECK(sizeof(grSeqYakumono) == 348)
};