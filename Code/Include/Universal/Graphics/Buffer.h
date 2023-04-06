#pragma once

#include <cstddef>
#include <cstdint>

namespace Uni::Grpx
{
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
        uint8_t* m_data{ nullptr };
        size_t m_size{ 0LU };
    };
} // namespace Uni::Grpx
