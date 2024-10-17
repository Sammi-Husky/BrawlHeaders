#pragma once

#include <types.h>

// These are stored in field 0x18 in bits 20-21.
#define GF_FILE_IO_READ_OPERATION 0x000000
#define GF_FILE_IO_WRITE_OPERATION (1 << 0x14)
#define GF_FILE_IO_DEL_OPERATION (2 << 0x14)
#define GF_FILE_IO_CREATE_DIR_OPERATION (3 << 0x14)
#define GF_FILE_IO_CREATE_VF_SYSTEM_FILE_OPERATION (5 << 0x14)
#define GF_FILE_IO_MOUNT_VF_OPERATION (6 << 0x14)
#define GF_FILE_IO_UNMOUNT_VF_OPERATION (7 << 0x14)
#define GF_FILE_IO_FORMAT_VF_OPERATION (8 << 0x14)
#define GF_FILE_IO_MOUNT_SD_OPERATION (9 << 0x14)
#define GF_FILE_IO_UNMOUNT_SD_OPERATION (0xA << 0x14)
#define GF_FILE_IO_READ_DIR_OPERATION (0xB << 0x14)
#define GF_FILE_IO_CHECK_FREE_SIZE_OPERATION (0xC << 0x14)
#define GF_FILE_IO_CHECK_FILE_OPERATION (0xD << 0x14)
#define GF_FILE_IO_CHECK_DIR_OPERATION (0xE << 0x14)
#define GF_FILE_IO_FIND_FIRST_OPERATION (0xF << 0x14)
#define GF_FILE_IO_FIND_FILE_COUNT_OPERATION (0x10 << 0x14)
#define GF_FILE_IO_COPY_TO_NAND_CACHE_OPERATION (0x12 << 0x14)
#define GF_FILE_IO_NAND_DELETE_OPERATION (0x13 << 0x14)
#define GF_FILE_IO_WRITE_NAND_OPERATION (0x14 << 0x14)


class gfFileIORequest {
public:
    // 0x0
    char* m_pFilepath;
    // 0x4
    int m_offset;
    // 0x8
    int m_readLen;
    // 0xC
    void* m_dest;
    // 0x10
    void* m_heap;
    // 0x14
    u8 m_returnStatus;
    // 0x15 -- seems to be either a format specifier or id used by the VF operations.
    u8 m_vfUnk;

    u8 _unk16;
    // Bits 3+4 are involved in whether or not handle->release() frees this request.
    u8 _unkFlags;
    // 0x18
    int m_operationFlags;
    // 0x1C
    u16 m_crc16;
    // 0x20
    u16 m_unk3;
    // 0x24
    void* m_notifyCallback;
    char m_filepath[128];

    void setParam(const char* filepath);
    void setReadParam(const char* filepath, void* addr, int length, int offset);
    void setWriteParam(const char* filepath, void* addr, int len, int offset);
};
