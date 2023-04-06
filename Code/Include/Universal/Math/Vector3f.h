#pragma once

namespace Uni::Math::Rand
{
    class Generator;
}

namespace Uni::Math
{
    //! A generic 3D vector class with float components.
    struct Vector3f
    {
        float m_x, m_y, m_z;

        static Vector3f CreateZero();
        static Vector3f CreateFromFloat(float value);
        static Vector3f CreateRandomUnitVector(Rand::Generator& generator);

        Vector3f();
        Vector3f(const Vector3f& vector) = default;
        Vector3f(Vector3f&& vector) = default;
        ~Vector3f() = default;

        Vector3f(float x, float y, float z);

        [[nodiscard]] float GetLength() const;
        [[nodiscard]] float GetLengthSquared() const;
        [[nodiscard]] Vector3f GetNormalized() const;

        float DotProduct(const Vector3f& vector) const;
        Vector3f CrossProduct(const Vector3f& vector) const;

        bool operator==(const Vector3f& other) const;
        bool operator!=(const Vector3f& other) const;
        Vector3f& operator=(const Vector3f& other) = default;
        Vector3f& operator+=(const Vector3f& other);
        Vector3f operator+(const Vector3f& other) const;
        Vector3f& operator-=(const Vector3f& other);
        Vector3f operator-(const Vector3f& other) const;
        Vector3f& operator*=(float value);
        Vector3f& operator*=(const Vector3f& other);
        Vector3f operator*(float value) const;
        Vector3f operator*(const Vector3f& other) const;
        Vector3f& operator/=(float value);
        Vector3f operator/(float value) const;
    };
} // namespace Uni::Math
