#pragma once

struct FAEntryInfo;

extern "C" int FAFsfirst(const char* pattern, int filter, FAEntryInfo* ret);