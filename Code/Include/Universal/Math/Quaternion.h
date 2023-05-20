#pragma once

namespace Uni::Math
{
    struct Vector3f;
    struct Matrix3x4f;

    class Quaternion
    {
    public:
        static Quaternion CreateIdentity();
        static Quaternion CreateFromAxisRad(
            float angle, const Vector3f& axis);
        static Quaternion CreateFromEulerRadZYX(const Vector3f& angles);
        static Quaternion CreateFromEulerDegZYX(const Vector3f& angles);

        Quaternion();
        Quaternion(float x, float y, float z, float w);
        Quaternion(const Quaternion& quaternion) = default;
        Quaternion(Quaternion&& quaternion) = default;
        ~Quaternion() = default;

        [[nodiscard]] Vector3f GetEulerRadZYX() const;
        [[nodiscard]] Vector3f GetEulerDegZYX() const;
        [[nodiscard]] Vector3f Rotate(const Vector3f& vector) const;
        [[nodiscard]] Quaternion GetConjugate() const;
        [[nodiscard]] Matrix3x4f GetMatrix() const;

        Quaternion& operator=(const Quaternion& other) = default;

        bool operator==(const Quaternion& other) const;
        bool operator!=(const Quaternion& other) const;

        Vector3f operator*(const Vector3f& vector) const;

        Quaternion operator+(const Quaternion& other) const;
        Quaternion operator-(const Quaternion& other) const;
        Quaternion operator*(const Quaternion& other) const;

        Quaternion& operator+=(const Quaternion& other);
        Quaternion& operator-=(const Quaternion& other);
        Quaternion& operator*=(const Quaternion& other);

    private:
        float m_r, m_i, m_j, m_k;
    };
} // namespace Uni::Math
