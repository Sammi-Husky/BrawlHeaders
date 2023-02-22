#pragma once

enum StageKind {
    ST_BATTLE = 0x01,
    ST_FINAL = 0x02,
    ST_DOLPIC = 0x03,
    ST_MANSION = 0x04,
    ST_MARIOPAST = 0x05,
    ST_KART = 0x06,
    ST_DONKEY = 0x07,
    ST_JUNGLE = 0x08,
    ST_PIRATES = 0x09,
    ST_NORFAIR = 0x0B,
    ST_ORPHEON = 0x0C,
    ST_CRAYON = 0x0D,
    ST_HALBERD = 0x0E,
    ST_STARFOX = 0x13,
    ST_STADIUM = 0x14,
    ST_TENGAN = 0x15,
    ST_FZERO = 0x16,
    ST_ICE = 0x17,
    ST_GW = 0x18,
    ST_EMBLEM = 0x19,
    ST_MADEIN = 0x1C,
    ST_EARTH = 0x1D,
    ST_PALUTENA = 0x1E,
    ST_FAMICOM = 0x1F,
    ST_NEWPORK = 0x20,
    ST_VILLAGE = 0x21,
    ST_METALGEAR = 0x22,
    ST_GREENHILL = 0x23,
    ST_PICTCHAT = 0x24,
    ST_PLANKTON = 0x25,
    ST_CONFIG = 0x26,
    ST_DXSHRINE = 0x29,
    ST_DXYORSTER = 0x2A,
    ST_DXGARDEN = 0x2B,
    ST_DXONETT = 0x2C,
    ST_DXGREENS = 0x2D,
    ST_DXPSTADIUM = 0x2E,
    ST_DXRCRUISE = 0x2F,
    ST_DXCORNERIA = 0x30,
    ST_DXBIGBLUE = 0x31,
    ST_DXZEBES = 0x32,
    ST_OLDIN = 0x33,
    ST_HOMERUN = 0x34,
    ST_STAGEEDIT = 0x35,
    ST_HEAL = 0x36,
    ST_OTRAIN = 0x37,
    ST_TBREAK = 0x38,
    ST_CROLL = 0x39,
    ST_BATTLES = 0x41,
};

struct StageModuleId {
    StageKind kind;
    const char name[0x20];
};

void moUnResolvedMessage(char const* name);
char const* moGetStageModuleName(StageKind kind);
