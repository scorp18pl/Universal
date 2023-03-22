#include <Math/Vector3.h>

#include <Math/Math.h>
#include <Math/Random.h>
#include <cmath>

namespace Uni::Math
{
    Vector3f::Vector3f()
    {
        (*this) = Vector3f::CreateZero();
    }

    Vector3f::Vector3f(float x, float y, float z)
        : m_x{ x }
        , m_y{ y }
        , m_z{ z }
    {
    }

    Vector3f Vector3f::CreateZero()
    {
        return CreateFromFloat(0.0f);
    }

    Vector3f Vector3f::CreateFromFloat(float value)
    {
        return { value, value, value };
    }

    Vector3f Vector3f::CreateRandomUnitVector()
    {
        Vector3f randomUnitVector = {
            Rand::CreateRandomGaussianFloat(0.0f, 1.0f),
            Rand::CreateRandomGaussianFloat(0.0f, 1.0f),
            Rand::CreateRandomGaussianFloat(0.0f, 1.0f),
        };

        return randomUnitVector.GetNormalized();
    }

    float Vector3f::GetLengthSquared() const
    {
        return m_x * m_x + m_y * m_y + m_z * m_z;
    }

    float Vector3f::GetLength() const
    {
        return std::sqrt(GetLengthSquared());
    }

    Vector3f Vector3f::GetNormalized() const
    {
        const float lengthInverse = Q_rsqrt(GetLengthSquared());
        return { m_x * lengthInverse,
                 m_y * lengthInverse,
                 m_z * lengthInverse };
    }

    Vector3f Vector3f::DotProduct(const Vector3f& vector) const
    {
        return {
            m_x * vector.m_x,
            m_y * vector.m_y,
            m_z * vector.m_z,
        };
    }

    Vector3f Vector3f::CrossProduct(const Vector3f& vector) const
    {
        return {
            m_y * vector.m_z - m_z * vector.m_y,
            m_z * vector.m_x - m_x * vector.m_z,
            m_x * vector.m_y - m_y * vector.m_x,
        };
    }

    Vector3f& Vector3f::operator+=(const Vector3f& other)
    {
        m_x += other.m_x;
        m_y += other.m_y;
        m_z += other.m_z;

        return (*this);
    }

    Vector3f Vector3f::operator+(const Vector3f& other) const
    {
        Vector3f vector = (*this);
        vector += other;
        return vector;
    }

    Vector3f& Vector3f::operator-=(const Vector3f& other)
    {
        m_x -= other.m_x;
        m_y -= other.m_y;
        m_z -= other.m_z;

        return (*this);
    }

    Vector3f Vector3f::operator-(const Vector3f& other) const
    {
        Vector3f vector = (*this);
        vector -= other;
        return vector;
    }

    Vector3f& Vector3f::operator*=(float value)
    {
        m_x *= value;
        m_y *= value;
        m_z *= value;

        return (*this);
    }

    Vector3f Vector3f::operator*(float value) const
    {
        Vector3f vector = (*this);
        vector *= value;
        return vector;
    }

    Vector3f& Vector3f::operator/=(float value)
    {
        m_x /= value;
        m_y /= value;
        m_z /= value;

        return (*this);
    }

    Vector3f Vector3f::operator/(float value) const
    {
        Vector3f vector = (*this);
        vector /= value;
        return vector;
    }
} // namespace Uni::Math