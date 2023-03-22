#include <Math/Vector2.h>

#include <Math/Math.h>
#include <Math/Random.h>
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

    Vector2f Vector2f::CreateRandomUnitVector()
    {
        const float theta =
            Rand::CreateRandomUniformFloat(0, Math::Constants::TwoPI);

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
        const float lengthInverse = Q_rsqrt(GetLengthSquared());
        return { m_x * lengthInverse, m_y * lengthInverse };
    }

    Vector2f Vector2f::DotProduct(const Vector2f& vector) const
    {
        return {
            m_x * vector.m_x,
            m_y * vector.m_y,
        };
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
        Vector2f vector = (*this);
        vector += other;
        return vector;
    }

    Vector2f& Vector2f::operator-=(const Vector2f& other)
    {
        m_x -= other.m_x;
        m_y -= other.m_y;

        return (*this);
    }

    Vector2f Vector2f::operator-(const Vector2f& other) const
    {
        Vector2f vector = (*this);
        vector -= other;
        return vector;
    }

    Vector2f& Vector2f::operator*=(float value)
    {
        m_x *= value;
        m_y *= value;

        return (*this);
    }

    Vector2f Vector2f::operator*(float value) const
    {
        Vector2f vector = (*this);
        vector *= value;
        return vector;
    }

    Vector2f& Vector2f::operator/=(float value)
    {
        m_x /= value;
        m_y /= value;

        return (*this);
    }

    Vector2f Vector2f::operator/(float value) const
    {
        Vector2f vector = (*this);
        vector /= value;
        return vector;
    }
} // namespace Uni::Math