#include <Universal/Graphics/Buffer.h>
#include <cstdlib>

namespace Uni::Grpx
{
    Buffer::Buffer(size_t size)
    {
        m_data = new uint8_t[size];
        m_size = size;
    }

    Buffer::Buffer(Buffer&& other) noexcept
    {
        m_data = other.m_data;
        m_size = other.m_size;

        other.m_data = nullptr;
        other.m_size = 0LU;
    }

    Buffer::~Buffer()
    {
        delete[] m_data;
    }

    uint8_t* Buffer::GetData()
    {
        return m_data;
    }

    size_t Buffer::GetSize() const
    {
        return m_size;
    }
} // namespace Uni::Grpx