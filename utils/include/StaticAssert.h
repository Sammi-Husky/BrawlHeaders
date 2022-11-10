#pragma once

template <bool>
struct CompileTimeError;
template <>
struct CompileTimeError<true> {
};
#define CONCAT(a, b) CONCAT_INNER(a, b)
#define CONCAT_INNER(a, b) a##b

#define UNIQUE_NAME(base) CONCAT(base, __LINE__)

#define STATIC_CHECK(expr) \
    inline void UNIQUE_NAME(StaticCheck)() { ((void)CompileTimeError<(expr) != 0>()); }

#define PRINT_SIZEOF(typename) \
    inline void UNIQUE_NAME(PrintSizeOf)() { char(*__kaboom)[sizeof(typename)] = 1; }