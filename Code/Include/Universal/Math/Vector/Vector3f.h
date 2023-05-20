#pragma once

namespace Uni::Math::Rand
{
    class Generator;
}

namespace Uni::Math
{
    struct Vector2f;
    struct Vector4f;

    //! A generic 3D vector class with float components.
    struct Vector3f
    {
        union
        {
            float m_data[3];
            struct{
                float m_x, m_y, m_z;
            };
        };

        static Vector3f CreateZero();
        static Vector3f CreateAxisX();
        static Vector3f CreateAxisY();
        static Vector3f CreateAxisZ();
        static Vector3f CreateRandomUnitVector(Rand::Generator& generator);

        Vector3f();
        Vector3f(const Vector3f& vector) = default;
        Vector3f(Vector3f&& vector) = default;
        ~Vector3f() = default;

        explicit Vector3f(float value);
        Vector3f(float x, float y, float z);
        Vector3f(const Vector2f& vector, float z);
        Vector3f(float x, const Vector2f& vector);


        [[nodiscard]] float GetLength() const;
        [[nodiscard]] float GetLengthSquared() const;
        [[nodiscard]] float GetDotProduct(const Vector3f& vector) const;
        [[nodiscard]] Vector3f GetCrossProduct(const Vector3f& vector) const;
        [[nodiscard]] Vector3f GetNormalized() const;
        [[nodiscard]] Vector4f GetHomogeneous() const;

        Vector3f& operator=(const Vector3f& other) = default;

        bool operator==(const Vector3f& other) const;
        bool operator!=(const Vector3f& other) const;

        Vector3f operator*(float value) const;
        Vector3f operator/(float value) const;

        Vector3f& operator*=(float value);
        Vector3f& operator/=(float value);

        Vector3f operator+(const Vector3f& other) const;
        Vector3f operator-(const Vector3f& other) const;
        Vector3f operator*(const Vector3f& other) const;
        Vector3f operator/(const Vector3f& other) const;

        Vector3f& operator+=(const Vector3f& other);
        Vector3f& operator-=(const Vector3f& other);
        Vector3f& operator*=(const Vector3f& other);
        Vector3f& operator/=(const Vector3f& other);

        friend Vector3f operator-(const Vector3f &vector);
        friend Vector3f operator*(float lhs, const Vector3f &rhs);
    };
} // namespace Uni::Math
