#pragma once

#include <gr/gr_stadium.h>
#include <ms/ms_message.h>

class grStadiumVision : public grStadium {
public:
    void* m_msgBinData;
    u8 m_352;
    char _353[3];
    int m_stadiumType;
    char _360[4];
    float _364;
    Message* message;
    float m_372;
    float m_376;
    float m_380;
    float m_384;
    float m_388;
    float m_392;
    float m_396;
    short m_400;
    short m_402;
    short m_404;
    short m_406;
    short m_408;
    short m_410;
    short m_412;
    u8 m_414;
    char _415;

    grStadiumVision(char* taskName);
    virtual void startup(gfArchive* data, u32 unk1, u32 unk2);
    virtual void update(float deltaFrame);
    virtual ~grStadiumVision();

    void setDisplay(bool);

    static grStadiumVision* create(int mdlIndex, char* tgtNodeName, char* taskName);
};
static_assert(sizeof(grStadiumVision) == 416, "Class is wrong size!");