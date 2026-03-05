#ifndef NW4R_SND_DVD_SOUND_ARCHIVE_H
#define NW4R_SND_DVD_SOUND_ARCHIVE_H

#include <nw4r/snd/data_reference.h>

namespace nw4r
{
    namespace snd
    {
        template <typename T, u32 C>
        struct dataReferenceArr
        {
            const u32 m_count;
            nw4r::snd::detail::dataReferenceImpl<T> m_arr[C];
        };
        template <typename T>
        struct dataReferenceArrFlex
        {
            const u32 m_count;
            nw4r::snd::detail::dataReferenceImpl<T> m_arr[];
        };

        struct SoundArchiveInfo3DSoundInfo
        {
            u32 m_flags;
            u8 m_decayCurve;
            u8 m_decayRatio;
            u8 m_dopplerFactor;
            u8 _padding[0x5];
        };
        static_assert(sizeof(SoundArchiveInfo3DSoundInfo) == 0xC, "Class is wrong size!");

        struct SoundArchiveInfoSequenceSoundInfo
        {
            u32 m_dataID;
            u32 m_bankID;
            u32 m_allocTrack;
            u8 m_channelPriority;
            u8 m_releasePriorityFix;
        private:
            u8 _padding[0x6];
        };
        static_assert(sizeof(SoundArchiveInfoSequenceSoundInfo) == 0x14, "Class is wrong size!");

        struct SoundArchiveInfoStreamSoundInfo
        {
            u32 m_startPosition;
            u16 m_allocChannelCount;
            u16 m_allocTrackFlag;
        private:
            u8 _padding[0x4];
        };
        static_assert(sizeof(SoundArchiveInfoStreamSoundInfo) == 0xC, "Class is wrong size!");

        struct SoundArchiveInfoWaveSoundInfo
        {
            u32 m_soundIndex;
            u32 m_allocTrack;
            u8 m_channelPriority;
            u8 m_releasePriorityFix;
        private:
            u8 _padding[0x6];
        };
        static_assert(sizeof(SoundArchiveInfoWaveSoundInfo) == 0x10, "Class is wrong size!");

        struct SoundArchiveInfoSoundEntry
        {
            u32 stringID;
            u32 fileID;
            u32 playerID;
            nw4r::snd::detail::dataReferenceImpl<SoundArchiveInfo3DSoundInfo> param3DRefOffset;
            u8 volume;
            u8 playerPriority;
            u8 soundType;
            u8 remoteFilter;
            nw4r::snd::detail::dataReferenceImpl<void> soundInfoRef;
            u32 m_userParam1;
            u32 m_userParam2;
            u8 m_panMode;
            u8 m_panCurve;
            u8 m_actorPlayerID;
            u8 _padding;

            SoundArchiveInfo3DSoundInfo m_sound3DInfo;
            union
            {
                SoundArchiveInfoSequenceSoundInfo m_seqSoundInfo;
                SoundArchiveInfoWaveSoundInfo m_waveSoundInfo;
                SoundArchiveInfoStreamSoundInfo m_streamSoundInfo;
            };
        };

        struct SoundArchiveInfoBankEntry
        {
            u32 m_stringID;
            u32 m_fileID;
        private:
            u8 _padding[0x4];
        };
        static_assert(sizeof(SoundArchiveInfoBankEntry) == 0xC, "Class is wrong size!");

        struct SoundArchiveInfoPlayerEntry
        {
            u32 m_stringID;
            u8 m_playableSoundCount;
            u8 _padding1;
            u16 _padding2;
            u32 m_heapSize;
        private:
            u8 _padding[0x4];
        };
        static_assert(sizeof(SoundArchiveInfoPlayerEntry) == 0x10, "Class is wrong size!");

        struct SoundArchiveInfoFileEntry
        {
            u32 m_groupID;
            u32 m_index;
        };
        static_assert(sizeof(SoundArchiveInfoFileEntry) == 0x8, "Class is wrong size!");

        struct SoundArchiveInfoFileHeader
        {
            u32 m_headerLength;
            u32 m_dataLength;
            u32 m_entryNumber;
            nw4r::snd::detail::dataReferenceImpl<const char> stringOffset;
            nw4r::snd::detail::dataReferenceImpl<dataReferenceArrFlex<SoundArchiveInfoFileEntry> > m_entryArr;
        };
        static_assert(sizeof(SoundArchiveInfoFileHeader) == 0x1C, "Class is wrong size!");

        struct SoundArchiveInfoGroupEntry
        {
            u32 m_fileID;
            u32 m_headerOffset;
            u32 m_headerLength;
            u32 m_dataOffset;
            u32 m_dataLength;
        private:
            u8 _padding[0x4];
        };
        static_assert(sizeof(SoundArchiveInfoGroupEntry) == 0x18, "Class is wrong size!");

        struct SoundArchiveInfoGroupHeader
        {
            u32 m_groupID;
            u32 m_entryNum;
            nw4r::snd::detail::dataReferenceImpl<const char> m_extFilePath;
            u32 m_headerAddress;
            u32 m_headerLength;
            u32 m_dataAddress;
            u32 m_dataLength;
            nw4r::snd::detail::dataReferenceImpl<dataReferenceArrFlex<SoundArchiveInfoGroupEntry> > m_entryArr;
        };
        static_assert(sizeof(SoundArchiveInfoGroupHeader) == 0x28, "Class is wrong size!");

        struct SoundArchiveInfoSectionFooter
        {
            u16 m_sequenceMax;
            u16 m_sequenceTrackMax;
            u16 m_streamMax;
            u16 m_streamTrackMax;
            u16 m_streamChannelsMax;
            u16 m_waveMax;
            u16 m_waveTrackMax;
        private:
            u8 _padding[0x6];
        };
        static_assert(sizeof(SoundArchiveInfoSectionFooter) == 0x14, "Class is wrong size!");

        typedef dataReferenceArr<SoundArchiveInfoSoundEntry, 0x286C> soundRefArr_t;
        typedef dataReferenceArr<SoundArchiveInfoBankEntry, 0x0049> bankRefArr_t;
        typedef dataReferenceArr<SoundArchiveInfoPlayerEntry, 0x0007> playerRefArr_t;
        typedef dataReferenceArr<SoundArchiveInfoFileHeader, 0x032E> fileRefArr_t;
        typedef dataReferenceArr<SoundArchiveInfoGroupHeader, 0x0145> groupRefArr_t;
        struct SoundArchiveInfoSectionHeader
        {
            nw4r::snd::detail::dataReferenceImpl<soundRefArr_t> m_soundsSectionReference;
            nw4r::snd::detail::dataReferenceImpl<bankRefArr_t> m_banksSectionReference;
            nw4r::snd::detail::dataReferenceImpl<playerRefArr_t> m_playerSectionReference;
            nw4r::snd::detail::dataReferenceImpl<fileRefArr_t> m_filesSectionReference;
            nw4r::snd::detail::dataReferenceImpl<groupRefArr_t> m_groupsSectionReference;
            nw4r::snd::detail::dataReferenceImpl<SoundArchiveInfoSectionFooter> m_footerReference;
        };
        static_assert(sizeof(SoundArchiveInfoSectionHeader) == 0x30, "Class is wrong size!");

        struct SoundArchiveFileReader
        {
            u32 m_magic; // RSAR
            u16 m_byteOrderMarker;
            u16 m_version;
            u32 m_archiveSize;
            u16 m_headerLength; // 0x40
            u16 m_sectionCount; // 0x3
            u32 m_symbSectionOffset;
            u32 m_symbSectionSize;
            u32 m_infoSectionOffset;
            u32 m_infoSectionSize;
            u32 m_dataSectionOffset;
            u32 m_dataSectionSize;
            SoundArchiveInfoSectionHeader* m_infoSection;
            u8 _unk2C[0x54];
        };
        static_assert(sizeof(SoundArchiveFileReader) == 0x80, "Class is wrong size!");

        struct DvdSoundArchive
        {
            u8 _unk00[0x108];
            SoundArchiveFileReader m_RSAR;
            u32 _unk188;
        };
        static_assert(sizeof(DvdSoundArchive) == 0x18C, "Class is wrong size!");
    }
}

#endif
