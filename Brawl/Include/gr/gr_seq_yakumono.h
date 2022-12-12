#pragma once

#include <gr/gr_yakumono.h>
#include <StaticAssert.h>

class grSeqYakumono : public grYakumono {
protected:
    char _spacer[12];

public:
    grSeqYakumono(char* taskName);
    void createSeSeqWork(int unk1);
    void playSeSeq(float unk1, int unk2);
    void playSeSeq(float unk1, float unk2, float unk3);
    void registSeSeq(unsigned int unk1, int unk2, int unk3);

    virtual ~grSeqYakumono();

    STATIC_CHECK(sizeof(grSeqYakumono) == 348)
};