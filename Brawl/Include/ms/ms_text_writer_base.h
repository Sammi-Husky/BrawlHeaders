#pragma once

#include <StaticAssert.h>
#include <types.h>
#include <ms/ms_char_writer.h>

namespace ms {
    template <class T>
    class TextWriterBase : public CharWriter {
        char _112[48];
    };
}