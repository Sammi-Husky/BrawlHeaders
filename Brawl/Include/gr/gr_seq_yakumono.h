#pragma once

class grSeqYakumono : public grYakumono {
protected:
    char spacer_[12];
public:
    grSeqYakumono(char* taskName);
    void createSeSeqWork(int unk1);
    void playSeSeq(float unk1, int unk2);
    void playSeSeq(float unk1, float unk2, float unk3);
    void registSeSeq(unsigned int unk1, int unk2, int unk3);

    virtual ~grSeqYakumono();
};