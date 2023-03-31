#pragma once

namespace Uni::Math
{
    struct Vector2f
    {
        float m_x, m_y;

        static Vector2f CreateZero();
        static Vector2f CreateFromFloat(float value);
        static Vector2f CreateRandomUnitVector();

        Vector2f();
        Vector2f(const Vector2f& vector) = default;
        Vector2f(Vector2f&& vector) = default;
        ~Vector2f() = default;

        Vector2f(float x, float y);

        [[nodiscard]] float GetLength() const;
        [[nodiscard]] float GetLengthSquared() const;
        [[nodiscard]] Vector2f GetNormalized() const;
        [[nodiscard]] Vector2f GetMod(const Vector2f& other) const;

        Vector2f DotProduct(const Vector2f& vector) const;

        bool operator==(const Vector2f& other) const;
        bool operator!=(const Vector2f& other) const;
        Vector2f& operator=(const Vector2f& other) = default;
        Vector2f& operator+=(const Vector2f& other);
        Vector2f operator+(const Vector2f& other) const;
        Vector2f& operator-=(const Vector2f& other);
        Vector2f operator-(const Vector2f& other) const;
        Vector2f& operator*=(float value);
        Vector2f operator*(float value) const;
        Vector2f& operator/=(float value);
        Vector2f operator/(float value) const;
    };
} // namespace Uni::Math
