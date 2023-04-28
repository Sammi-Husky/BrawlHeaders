#pragma once

#include "types.h"

struct FAHandle;
extern "C" int FAFread(void* dest, size_t size, size_t num, FAHandle* handle);