#pragma once

#include <StaticAssert.h>
#include <revolution/CX/CXCompression.h>
#include <types.h>

namespace CompressionAlgo {
    enum Enum {
        LZ = 0x10,
        Huffman = 0x20,
        RL = 0x30
    };
}

class gfDecomp {
    bool m_ready;
    CompressionAlgo::Enum m_algo;
    void* unk8;
    u32 m_uncompSize;
    void* m_heapAddr;
    CXUncompContext m_ctx;
public:
    void decomp(const CXStream* src, void* dest);
};
// TODO size
