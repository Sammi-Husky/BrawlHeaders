#pragma once

#include "fa/FAClosedir.h"
#include "fa/FAFclose.h"
#include "fa/FAFopen.h"
#include "fa/FAFread.h"
#include "fa/FAFseek.h"
#include "fa/FAFsfirst.h"
#include "fa/FAFsnext.h"
#include "fa/FAFstat.h"
#include "fa/FAFwrite.h"
#include "fa/FAOpendir.h"
#include "fa/FAremove.h"

struct FAEntryInfo {
    char _0x0[0x224];
    s16 modifiedTime;
    s16 modifiedDate;
    int size;
    char _flag;
    char shortname[0xd];
    char name[0x38];
    char unk[0x1e2];
};
