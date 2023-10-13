#pragma once

#include <cstddef>
#include <cstdint>
#include <cstring>

namespace Uni::Grpx
{
    //! A simple buffer of bytes.
    template<typename StoredType>
    class Buffer
    {
    public:
        Buffer() = default;
        explicit Buffer(size_t size);
        Buffer(StoredType* data, size_t size);
        Buffer(const Buffer& other);
        Buffer(Buffer&& other) noexcept;
        ~Buffer();

        StoredType* GetData();
        [[nodiscard]] const StoredType* GetData() const;
        [[nodiscard]] size_t GetSize() const;

        Buffer& operator=(const Buffer& other);

    protected:
        StoredType* m_data{ nullptr }; //! Pointer to the start of the buffer.
        size_t m_size{ 0LU }; //! Size in bytes.
    };

    template<typename StoredType>
    Buffer<StoredType>::Buffer(size_t size)
        : m_data(new StoredType[size])
        , m_size(size)
    {
    }

    template<typename StoredType>
    Buffer<StoredType>::Buffer(StoredType* data, size_t size)
        : m_data(data)
        , m_size(size)
    {
    }

    template<typename StoredType>
    Buffer<StoredType>::Buffer(const Buffer<StoredType>& other)
        : m_data(new uint8_t[other.m_size])
        , m_size(other.m_size)
    {
        std::memcpy(m_data, other.m_data, m_size);
    }

    template<typename StoredType>
    Buffer<StoredType>::Buffer(Buffer<StoredType>&& other) noexcept
        : m_data(other.m_data)
        , m_size(other.m_size)
    {
        other.m_data = nullptr;
        other.m_size = 0LU;
    }

    template<typename StoredType>
    Buffer<StoredType>::~Buffer()
    {
        delete[] m_data;
    }

    template<typename StoredType>
    const StoredType* Buffer<StoredType>::GetData() const
    {
        return m_data;
    }

    template<typename StoredType>
    StoredType* Buffer<StoredType>::GetData()
    {
        return m_data;
    }

    template<typename StoredType>
    size_t Buffer<StoredType>::GetSize() const
    {
        return m_size;
    }

    template<typename StoredType>
    Buffer<StoredType>& Buffer<StoredType>::operator=(
        const Buffer<StoredType>& other)
    {
        if (this != &other)
        {
            m_size = other.m_size;
            delete[] m_data;

            m_data = new uint8_t[m_size];

            std::memcpy(m_data, other.m_data, m_size);
        }
        return *this;
    }
} // namespace Uni::Grpx
