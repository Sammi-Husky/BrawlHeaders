#pragma once

#include <stdarg.h>
#include <types.h>

extern "C" {
int sprintf(char* str, const char* format, ...);
int vprintf(const char* format, va_list ap);
int vsnprintf(char* s, size_t n, const char* format, va_list ap);
}