#include <Universal/Math/Math.h>
#include <Universal/Math/Random/Generator.h>
#include <Universal/Math/Vector/Vector2f.h>
#include <cmath>

namespace Uni::Math
{
    Vector2f::Vector2f()
    {
        (*this) = Vector2f::CreateZero();
    }

    Vector2f::Vector2f(float x, float y)
        : m_x{ x }
        , m_y{ y }
    {
    }

    Vector2f Vector2f::CreateZero()
    {
        return CreateFromFloat(0.0f);
    }

    Vector2f Vector2f::CreateFromFloat(float value)
    {
        return { value, value };
    }

    Vector2f Vector2f::CreateRandomUnitVector(Rand::Generator& generator)
    {
        const float theta =
            generator.GenerateInRange(0.0f, Math::Constants::TwoPI);

        return { std::cos(theta), std::sin(theta) };
    }

    float Vector2f::GetLengthSquared() const
    {
        return m_x * m_x + m_y * m_y;
    }

    float Vector2f::GetLength() const
    {
        return std::sqrt(GetLengthSquared());
    }

    Vector2f Vector2f::GetNormalized() const
    {
        return (*this) * Q_rsqrt(GetLengthSquared());
    }

    Vector2f Vector2f::GetMod(const Vector2f& other) const
    {
        return { FMod(m_x, other.m_x), FMod(m_y, other.m_y) };
    }

    float Vector2f::Dot(const Vector2f& vector) const
    {
        return m_x * vector.m_x + m_y * vector.m_y;
    }

    bool Vector2f::operator==(const Vector2f& other) const
    {
        return m_x == other.m_x && m_y == other.m_y;
    }

    bool Vector2f::operator!=(const Vector2f& other) const
    {
        return !((*this) == other);
    }

    Vector2f& Vector2f::operator+=(const Vector2f& other)
    {
        m_x += other.m_x;
        m_y += other.m_y;

        return (*this);
    }

    Vector2f Vector2f::operator+(const Vector2f& other) const
    {
        return Vector2f(*this) += other;
    }

    Vector2f& Vector2f::operator-=(const Vector2f& other)
    {
        m_x -= other.m_x;
        m_y -= other.m_y;

        return (*this);
    }

    Vector2f Vector2f::operator-(const Vector2f& other) const
    {
        return Vector2f(*this) -= other;
    }

    Vector2f& Vector2f::operator*=(float value)
    {
        m_x *= value;
        m_y *= value;

        return (*this);
    }

    Vector2f& Vector2f::operator*=(const Vector2f& other)
    {
        m_x *= other.m_x;
        m_y *= other.m_y;

        return (*this);
    }

    Vector2f Vector2f::operator*(float value) const
    {
        return Vector2f(*this) *= value;
    }

    Vector2f Vector2f::operator*(const Vector2f& other) const
    {
        return Vector2f(*this) *= other;
    }

    Vector2f& Vector2f::operator/=(float value)
    {
        m_x /= value;
        m_y /= value;

        return (*this);
    }

    Vector2f& Vector2f::operator/=(const Vector2f& other)
    {
        m_x /= other.m_x;
        m_y /= other.m_y;

        return (*this);
    }

    Vector2f Vector2f::operator/(float value) const
    {
        Vector2f vector = (*this);
        vector /= value;
        return vector;
    }

    Vector2f Vector2f::operator/(const Vector2f& other) const
    {
        return Vector2f(*this) /= other;
    }

    Vector2f operator*(float lhs, const Vector2f& rhs)
    {
        return rhs * lhs;
    }

    Vector2f operator-(const Vector2f& vector)
    {
        return { -vector.m_x, -vector.m_y };
    }
} // namespace Uni::Math