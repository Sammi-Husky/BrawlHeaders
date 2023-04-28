#pragma once

struct FAHandle;
extern "C" int FAFseek(FAHandle* handle, int offset, int mode);