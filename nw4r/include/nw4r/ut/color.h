#pragma once

#include <StaticAssert.h>
#include <types.h>

namespace nw4r {
    namespace ut {
        struct Color {
            u8 m_r;
            u8 m_g;
            u8 m_b;
            u8 m_a;
        };
        static_assert(sizeof(Color) == 0x4, "Class is the wrong size!");
    }
}
