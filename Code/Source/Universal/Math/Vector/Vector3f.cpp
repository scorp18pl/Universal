#include <Universal/Math/Random/Generator.h>
#include <Universal/Math/Vector/Vector2f.h>
#include <Universal/Math/Vector/Vector3f.h>
#include <Universal/Math/Vector/Vector4f.h>
#include <cmath>

namespace Uni::Math
{
    Vector3f Vector3f::CreateZero()
    {
        return Vector3f{ 0.0f };
    }

    Vector3f Vector3f::CreateAxisX()
    {
        return { 1.0f, 0.0f, 0.0f };
    }

    Vector3f Vector3f::CreateAxisY()
    {
        return { 0.0f, 1.0f, 0.0f };
    }

    Vector3f Vector3f::CreateAxisZ()
    {
        return { 0.0f, 0.0f, 1.0f };
    }

    Vector3f Vector3f::CreateRandomUnitVector(Rand::Generator& generator)
    {
        Vector3f randomUnitVector = {
            generator.GenerateGaussian(0.0f, 1.0f),
            generator.GenerateGaussian(0.0f, 1.0f),
            generator.GenerateGaussian(0.0f, 1.0f),
        };

        return randomUnitVector.GetNormalized();
    }

    Vector3f::Vector3f()
    {
        (*this) = Vector3f::CreateZero();
    }

    Vector3f::Vector3f(float value)
        : m_x{ value }
        , m_y{ value }
        , m_z{ value }
    {
    }

    Vector3f::Vector3f(float x, float y, float z)
        : m_x{ x }
        , m_y{ y }
        , m_z{ z }
    {
    }

    Vector3f::Vector3f(const Vector2f& vector, float z)
        : m_x{ vector.m_x }
        , m_y{ vector.m_y }
        , m_z{ z }
    {
    }

    Vector3f::Vector3f(float x, const Vector2f& vector)
        : m_x{ x }
        , m_y{ vector.m_x }
        , m_z{ vector.m_y }
    {
    }

    float Vector3f::GetLengthSquared() const
    {
        return m_x * m_x + m_y * m_y + m_z * m_z;
    }

    float Vector3f::GetLength() const
    {
        return std::sqrt(GetLengthSquared());
    }

    float Vector3f::GetDotProduct(const Vector3f& vector) const
    {
        return m_x * vector.m_x + m_y * vector.m_y + m_z * vector.m_z;
    }

    Vector3f Vector3f::GetNormalized() const
    {
        return (*this) / GetLength();
    }

    Vector3f Vector3f::GetCrossProduct(const Vector3f& vector) const
    {
        return {
            m_y * vector.m_z - m_z * vector.m_y,
            m_z * vector.m_x - m_x * vector.m_z,
            m_x * vector.m_y - m_y * vector.m_x,
        };
    }

    Vector4f Vector3f::GetHomogeneous() const
    {
        return { (*this), 1.0f };
    }

    bool Vector3f::operator==(const Vector3f& other) const
    {
        return m_x == other.m_x && m_y == other.m_y && m_z == other.m_z;
    }

    bool Vector3f::operator!=(const Vector3f& other) const
    {
        return !(*this == other);
    }

    Vector3f Vector3f::operator*(float value) const
    {
        return { m_x * value, m_y * value, m_z * value };
    }

    Vector3f Vector3f::operator/(float value) const
    {
        return { m_x / value, m_y / value, m_z / value };
    }

    Vector3f& Vector3f::operator*=(float value)
    {
        return (*this) = (*this) * value;
    }

    Vector3f& Vector3f::operator/=(float value)
    {
        return (*this) = (*this) / value;
    }

    Vector3f Vector3f::operator+(const Vector3f& other) const
    {
        return { m_x + other.m_x, m_y + other.m_y, m_z + other.m_z };
    }

    Vector3f Vector3f::operator-(const Vector3f& other) const
    {
        return { m_x - other.m_x, m_y - other.m_y, m_z - other.m_z };
    }

    Vector3f Vector3f::operator*(const Vector3f& other) const
    {
        return { m_x * other.m_x, m_y * other.m_y, m_z * other.m_z };
    }

    Vector3f Vector3f::operator/(const Vector3f& other) const
    {
        return { m_x / other.m_x, m_y / other.m_y, m_z / other.m_z };
    }

    Vector3f& Vector3f::operator+=(const Vector3f& other)
    {
        return (*this) = (*this) + other;
    }

    Vector3f& Vector3f::operator-=(const Vector3f& other)
    {
        return (*this) = (*this) - other;
    }

    Vector3f& Vector3f::operator*=(const Vector3f& other)
    {
        return (*this) = (*this) * other;
    }

    Vector3f& Vector3f::operator/=(const Vector3f& other)
    {
        return (*this) = (*this) / other;
    }

    Vector3f operator-(const Vector3f& vector)
    {
        return { -vector.m_x, -vector.m_y, -vector.m_z };
    }

    Vector3f operator*(float lhs, const Vector3f& rhs)
    {
        return rhs * lhs;
    }
} // namespace Uni::Math