#pragma once

#include <cstddef>
#include <cstdint>

namespace Uni::Grpx
{
    //! A simple buffer of bytes.
    class Buffer
    {
    public:
        explicit Buffer(size_t size);
        Buffer(const Buffer& other) = delete;
        Buffer(Buffer&& other) noexcept;
        ~Buffer();

        uint8_t* GetData();
        [[nodiscard]] size_t GetSize() const;

    protected:
        uint8_t* m_data{ nullptr }; //! Pointer to the start of the buffer.
        size_t m_size{ 0LU }; //! Size in bytes.
    };
} // namespace Uni::Grpx
