#pragma once

namespace Uni::Sys
{
    template<typename Tag>
    class TypeSafeId
    {
    public:
        TypeSafeId() = default;
        explicit constexpr TypeSafeId(size_t value)
            : m_value(value)
        {
        }

        constexpr static TypeSafeId CreateInvalid()
        {
            return TypeSafeId(InvalidId);
        }

        constexpr bool IsValid() const
        {
            return m_value != InvalidId;
        }

        constexpr size_t GetValue() const
        {
            return m_value;
        }

        constexpr bool operator==(const TypeSafeId& rhs) const
        {
            return m_value == rhs.m_value;
        }

        constexpr bool operator!=(const TypeSafeId& rhs) const
        {
            return m_value != rhs.m_value;
        }

        constexpr bool operator<(const TypeSafeId& rhs) const
        {
            return m_value < rhs.m_value;
        }

        constexpr bool operator>(const TypeSafeId& rhs) const
        {
            return m_value > rhs.m_value;
        }

        constexpr bool operator<=(const TypeSafeId& rhs) const
        {
            return m_value <= rhs.m_value;
        }

        constexpr bool operator>=(const TypeSafeId& rhs) const
        {
            return m_value >= rhs.m_value;
        }

        constexpr TypeSafeId& operator++()
        {
            ++m_value;
            return *this;
        }

    private:
        static constexpr size_t InvalidId = -1;
        size_t m_value;
    };
}