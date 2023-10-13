#pragma once

namespace Uni::Math::Rand
{
    class Generator;
}

namespace Uni::Math
{
    //! A generic 2D vector class with float components.
    struct Vector2f
    {
        union {
            float m_data[2];
            struct
            {
                float m_x, m_y;
            };
        };

        static Vector2f CreateZero();
        static Vector2f CreateRandomUnitVector(Rand::Generator& generator);

        Vector2f();
        Vector2f(const Vector2f& vector) = default;
        Vector2f(Vector2f&& vector) = default;
        ~Vector2f() = default;

        explicit Vector2f(float value);
        Vector2f(float x, float y);

        [[nodiscard]] float GetLength() const;
        [[nodiscard]] float GetLengthSquared() const;
        [[nodiscard]] Vector2f GetNormalized() const;
        [[nodiscard]] Vector2f GetMod(const Vector2f& other) const;

        [[nodiscard]] float Dot(const Vector2f& vector) const;

        Vector2f& operator=(const Vector2f& other) = default;

        bool operator==(const Vector2f& other) const;
        bool operator!=(const Vector2f& other) const;

        Vector2f operator*(float value) const;
        Vector2f operator/(float value) const;

        Vector2f& operator*=(float value);
        Vector2f& operator/=(float value);

        Vector2f operator+(const Vector2f& other) const;
        Vector2f operator-(const Vector2f& other) const;
        Vector2f operator*(const Vector2f& other) const;
        Vector2f operator/(const Vector2f& other) const;

        Vector2f& operator+=(const Vector2f& other);
        Vector2f& operator-=(const Vector2f& other);
        Vector2f& operator*=(const Vector2f& other);
        Vector2f& operator/=(const Vector2f& other);

        friend Vector2f operator-(const Vector2f& vector);
        friend Vector2f operator*(float lhs, const Vector2f& rhs);
    };
} // namespace Uni::Math
