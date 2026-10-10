#pragma once

#include <StaticAssert.h>
#include <nw4r/ef/ef_resource.h>
#include <nw4r/g3d/g3d_restex.h>
#include <revolution/GX/GXTexture.h>
#include <types.h>

struct gfDrawEfResource {
    char m_name[32];
    u8* m_breff;
    u8* m_breft;
    nw4r::ef::EffectProject* m_effProject;
    nw4r::ef::TextureProject* m_texProject;
};
static_assert(sizeof(gfDrawEfResource) == 0x30, "Class is wrong size!");

struct gfDrawEfResourceList {
    u16 m_numEntries;
    u16 m_numUsed;
    gfDrawEfResource* m_entries;
    gfDrawEfResource* m_common;
};
static_assert(sizeof(gfDrawEfResourceList) == 0xC, "Class is wrong size!");

void gfDrawResetLight();
void gfDrawSetupCoord2D();
void gfDrawSetVtxPosColorPrimEnvironment();
void gfDrawSetVtxPosColorTexPrimEnvironment();
void gfDrawSetupTexObj(GXTexObj* texObj, nw4r::g3d::ResTex resTex);
gfDrawEfResourceList* gfDrawCreateEfResourceList(u16 numEntries);
void gfDrawDestroyEfResourceList();
void gfDrawAddEfResource(gfDrawEfResourceList* list, const char* name, u8* breff, u8* breft,
                         bool isCommon);
void gfDrawRemoveEfResource(gfDrawEfResourceList* list, const char* name);

extern gfDrawEfResourceList* g_gfDrawEfResourceList;
