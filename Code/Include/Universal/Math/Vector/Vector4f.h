#pragma once

namespace Uni::Math
{
    //! A generic 4D vector class with float components.
    struct Vector4f
    {
        float m_x, m_y, m_z, m_w;

        static Vector4f CreateZero();
        static Vector4f CreateFromFloat(float value);

        Vector4f();
        Vector4f(const Vector4f& vector) = default;
        Vector4f(Vector4f&& vector) = default;
        ~Vector4f() = default;

        Vector4f(float x, float y, float z, float w);

        [[nodiscard]] float GetLength() const;
        [[nodiscard]] float GetLengthSquared() const;
        [[nodiscard]] Vector4f GetNormalized() const;

        [[nodiscard]] float DotProduct(const Vector4f& vector) const;

        bool operator==(const Vector4f& other) const;
        bool operator!=(const Vector4f& other) const;
        Vector4f& operator=(const Vector4f& other) = default;
        Vector4f& operator+=(const Vector4f& other);
        Vector4f operator+(const Vector4f& other) const;
        Vector4f& operator-=(const Vector4f& other);
        Vector4f operator-(const Vector4f& other) const;
        Vector4f& operator*=(float value);
        Vector4f& operator*=(const Vector4f& other);
        Vector4f operator*(float value) const;
        Vector4f operator*(const Vector4f& other) const;
        Vector4f& operator/=(float value);
        Vector4f operator/(float value) const;

        friend Vector4f operator*(float lhs, const Vector4f &rhs);
        friend Vector4f operator-(const Vector4f &vector);
    };
} // namespace Uni::Math
