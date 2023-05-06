#pragma once

#include <types.h>
#include <ms/ms_text_writer_base.h>

class Message : public ms::TextWriterBase<char> {
    virtual ~Message();

    char _164[316];
};
static_assert(sizeof(Message) == 480, "Class is wrong size!");