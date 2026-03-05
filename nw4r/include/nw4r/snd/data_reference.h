#ifndef NW4R_SND_DATA_REFERENCE
#define NW4R_SND_DATA_REFERENCE

#include <StaticAssert.h>
#include <types.h>

namespace nw4r
{
    namespace snd
    {
        namespace detail
        {
            struct dataReference
            {
                // 0 if address is absolute, 1 if address is relative to a parent address.
                u8 m_isRelative;
                u8 _unk01[0x03];
                u32 m_address;

                u32 getAddress(u32 baseAddressIn)
                {
                    u32 result = 0x00;

                    if (m_isRelative == 0)
                    {
                        result = m_address;
                    }
                    else if (m_isRelative == 1)
                    {
                        result = baseAddressIn + m_address;
                    }

                    return result;
                }
            };
            static_assert(sizeof(dataReference) == 0x8, "Class is wrong size!");

            template <typename T>
            struct dataReferenceImpl : dataReference
            {
                T* getAddress(void* baseAddressIn)
                {
                    return reinterpret_cast<T*>(dataReference::getAddress(reinterpret_cast<u32>(baseAddressIn)));
                }
            };
            static_assert(sizeof(dataReferenceImpl<void>) == 0x8, "Class is wrong size!");
        }
    }
}

#endif

