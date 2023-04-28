#pragma once

struct FAHandle;
extern "C" int FAFwrite(void* buffer, size_t size, size_t num, FAHandle* handle);