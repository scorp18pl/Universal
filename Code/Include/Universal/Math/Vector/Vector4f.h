#pragma once

namespace Uni::Math
{
    struct Vector2f;
    struct Vector3f;

    //! A generic 4D vector class with float components.
    struct Vector4f
    {
        union
        {
            float m_data[4];
            struct{
                float m_x, m_y, m_z, m_w;
            };
        };

        static Vector4f CreateZero();

        Vector4f();
        Vector4f(const Vector4f& vector) = default;
        Vector4f(Vector4f&& vector) = default;
        ~Vector4f() = default;

        explicit Vector4f(float value);
        Vector4f(float x, float y, float z, float w);

        Vector4f(const Vector2f& vector, float z, float w);
        Vector4f(float x, const Vector2f& vector, float w);
        Vector4f(float x, float y, const Vector2f& vector);
        Vector4f(const Vector2f& vector1, const Vector2f& vector2);

        Vector4f(const Vector3f& vector, float w);
        Vector4f(float x, const Vector3f& vector);

        [[nodiscard]] float GetLength() const;
        [[nodiscard]] float GetLengthSquared() const;
        [[nodiscard]] Vector4f GetNormalized() const;

        [[nodiscard]] float DotProduct(const Vector4f& vector) const;

        Vector4f& operator=(const Vector4f& other) = default;

        bool operator==(const Vector4f& other) const;
        bool operator!=(const Vector4f& other) const;

        Vector4f operator*(float value) const;
        Vector4f operator/(float value) const;

        Vector4f& operator*=(float value);
        Vector4f& operator/=(float value);

        Vector4f operator+(const Vector4f& other) const;
        Vector4f operator-(const Vector4f& other) const;
        Vector4f operator*(const Vector4f& other) const;
        Vector4f operator/(const Vector4f& other) const;

        Vector4f& operator+=(const Vector4f& other);
        Vector4f& operator-=(const Vector4f& other);
        Vector4f& operator*=(const Vector4f& other);
        Vector4f& operator/=(const Vector4f& other);

        friend Vector4f operator-(const Vector4f &vector);
        friend Vector4f operator*(float lhs, const Vector4f &rhs);
    };
} // namespace Uni::Math
