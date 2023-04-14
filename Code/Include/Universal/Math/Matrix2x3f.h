#pragma once

#include <Universal/Math/Vector2f.h>
#include <Universal/Math/Vector3f.h>
#include <array>

namespace Uni::Math
{
    //! A generic 2x3 matrix class with float components.
    class Matrix2x3f
    {
    public:
        static Matrix2x3f CreateIdentity();
        static Matrix2x3f CreateFromTranslation(const Vector2f& translation);
        static Matrix2x3f CreateFromRotationRadians(float angle);
        static Matrix2x3f CreateFromRotationDegrees(float angle);
        static Matrix2x3f CreateFromScale(const Vector2f& scale);
        static Matrix2x3f CreateFromRowMajorFloats(const float values[6]);

        Matrix2x3f() = default;
        Matrix2x3f(const Matrix2x3f& other) = default;
        Matrix2x3f(Matrix2x3f&& other) = default;
        ~Matrix2x3f() = default;

        Vector2f TransformVector2f(const Vector2f& vector) const;
        Vector3f TransformVector3f(const Vector3f& vector) const;

        Matrix2x3f& operator=(const Matrix2x3f& other) = default;
        Matrix2x3f operator*(const Matrix2x3f& other) const;
        Matrix2x3f& operator*=(const Matrix2x3f& other);
        Vector2f operator*(const Vector2f& vector) const;
        Vector3f operator*(const Vector3f& vector) const;

    private:
        std::array<float, 6> m_values; //!< Stored in row-major order.
    };
} // namespace Uni::Math
