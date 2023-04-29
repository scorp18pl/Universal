#pragma once

#include <Universal/Math/Vector/Vector3f.h>
#include <Universal/Math/Vector/Vector4f.h>
#include <array>
#include <cstddef>

namespace Uni::Math
{
    enum class Axis
    {
        X,
        Y,
        Z,
    };

    class Matrix3x4f
    {
    public:
        static Matrix3x4f CreateIdentity();
        static Matrix3x4f CreateFromTranslation(const Vector3f& translation);
        static Matrix3x4f CreateFromRotationRadians(
            float angle, Axis rotationAxis);
        static Matrix3x4f CreateFromRotationDegrees(
            float angle, Axis rotationAxis);
        static Matrix3x4f CreateFromScale(const Vector3f& scale);
        static Matrix3x4f CreateFromRowMajorFloats(const float values[6]);

        Matrix3x4f() = default;
        Matrix3x4f(const Matrix3x4f& other) = default;
        Matrix3x4f(Matrix3x4f&& other) = default;
        ~Matrix3x4f() = default;

        float operator()(size_t row, size_t column) const;
        float& operator()(size_t row, size_t column);

        Vector3f TransformVector3f(const Vector3f& vector) const;
        Vector4f TransformVector4f(const Vector4f& vector) const;

        Matrix3x4f& operator=(const Matrix3x4f& other) = default;
        Matrix3x4f& operator*=(const Matrix3x4f& other);
        Matrix3x4f operator*(const Matrix3x4f& other) const;
        Vector3f operator*(const Vector3f& vector) const;
        Vector4f operator*(const Vector4f& vector) const;

    private:
        static constexpr size_t RowCount = 3;
        static constexpr size_t ColumnCount = 4;
        static constexpr size_t ElementCount = RowCount * ColumnCount;

        std::array<float, ElementCount>
            m_values; //!< Stored in row-major order.
    };
} // namespace Uni::Math
