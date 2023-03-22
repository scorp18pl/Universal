#pragma once

namespace Uni::Math
{
    struct Vector3f
    {
        float m_x, m_y, m_z;

        static Vector3f CreateZero();
        static Vector3f CreateFromFloat(float value);
        static Vector3f CreateRandomUnitVector();

        Vector3f();
        Vector3f(const Vector3f& vector) = default;
        Vector3f(Vector3f&& vector) = default;
        ~Vector3f() = default;

        Vector3f(float x, float y, float z);

        [[nodiscard]] float GetLength() const;
        [[nodiscard]] float GetLengthSquared() const;
        [[nodiscard]] Vector3f GetNormalized() const;

        Vector3f DotProduct(const Vector3f& vector) const;
        Vector3f CrossProduct(const Vector3f& vector) const;

        Vector3f& operator=(const Vector3f& other) = default;
        Vector3f& operator+=(const Vector3f& other);
        Vector3f operator+(const Vector3f& other) const;
        Vector3f& operator-=(const Vector3f& other);
        Vector3f operator-(const Vector3f& other) const;
        Vector3f& operator*=(float value);
        Vector3f operator*(float value) const;
        Vector3f& operator/=(float value);
        Vector3f operator/(float value) const;
    };
} // namespace Uni::Math
