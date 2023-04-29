#include <Universal/Math/Math.h>
#include <Universal/Math/Vector/Vector4f.h>
#include <cmath>

namespace Uni::Math
{
    Vector4f Uni::Math::Vector4f::CreateZero()
    {
        return CreateFromFloat(0.0f);
    }

    Vector4f Vector4f::CreateFromFloat(float value)
    {
        return { value, value, value, value };
    }

    Vector4f::Vector4f()
    {
        (*this) = Vector4f::CreateZero();
    }

    Vector4f::Vector4f(float x, float y, float z, float w)
        : m_x{ x }
        , m_y{ y }
        , m_z{ z }
        , m_w{ w }
    {
    }

    float Vector4f::GetLength() const
    {
        return std::sqrt(GetLengthSquared());
    }

    float Vector4f::GetLengthSquared() const
    {
        return m_x * m_x + m_y * m_y + m_z * m_z + m_w * m_w;
    }

    Vector4f Vector4f::GetNormalized() const
    {
        return (*this) * Q_rsqrt(GetLengthSquared());
    }

    float Vector4f::DotProduct(const Vector4f& vector) const
    {
        return m_x * vector.m_x + m_y * vector.m_y + m_z * vector.m_z +
            m_w * vector.m_w;
    }

    bool Vector4f::operator==(const Vector4f& other) const
    {
        return m_x == other.m_x && m_y == other.m_y && m_z == other.m_z &&
            m_w == other.m_w;
    }

    bool Vector4f::operator!=(const Vector4f& other) const
    {
        return !(*this == other);
    }

    Vector4f& Vector4f::operator+=(const Vector4f& other)
    {
        m_x += other.m_x;
        m_y += other.m_y;
        m_z += other.m_z;
        m_w += other.m_w;

        return (*this);
    }

    Vector4f Vector4f::operator+(const Vector4f& other) const
    {
        return Vector4f(*this) += other;
    }

    Vector4f& Vector4f::operator-=(const Vector4f& other)
    {
        m_x -= other.m_x;
        m_y -= other.m_y;
        m_z -= other.m_z;
        m_w -= other.m_w;

        return (*this);
    }

    Vector4f Vector4f::operator-(const Vector4f& other) const
    {
        return Vector4f(*this) -= other;
    }

    Vector4f& Vector4f::operator*=(float value)
    {
        m_x *= value;
        m_y *= value;
        m_z *= value;
        m_w *= value;

        return (*this);
    }

    Vector4f& Vector4f::operator*=(const Vector4f& other)
    {
        m_x *= other.m_x;
        m_y *= other.m_y;
        m_z *= other.m_z;
        m_w *= other.m_w;

        return (*this);
    }

    Vector4f Vector4f::operator*(float value) const
    {
        return Vector4f(*this) *= value;
    }

    Vector4f Vector4f::operator*(const Vector4f& other) const
    {
        return Vector4f(*this) *= other;
    }

    Vector4f& Vector4f::operator/=(float value)
    {
        m_x /= value;
        m_y /= value;
        m_z /= value;
        m_w /= value;

        return (*this);
    }

    Vector4f Vector4f::operator/(float value) const
    {
        return Vector4f(*this) /= value;
    }

    Vector4f operator*(float lhs, const Vector4f& rhs)
    {
        return rhs * lhs;
    }

    Vector4f operator-(const Vector4f& vector)
    {
        return { -vector.m_x, -vector.m_y, -vector.m_z, -vector.m_w };
    }

} // namespace Uni::Math
