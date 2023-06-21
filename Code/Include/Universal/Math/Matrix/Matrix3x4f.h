#pragma once

#include <Universal/Math/Vector/Vector3f.h>
#include <Universal/Math/Vector/Vector4f.h>

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
    private:
        static constexpr unsigned int RowCount = 3;
        static constexpr unsigned int ColumnCount = 4;
        static constexpr unsigned int ElementCount = RowCount * ColumnCount;

    public:
        static Matrix3x4f CreateIdentity();

        static Matrix3x4f CreateTranslation(const Vector3f& translation);
        static Matrix3x4f CreateRotationEulerRadians(
            float angle, Axis rotationAxis);
        static Matrix3x4f CreateRotationEulerDegrees(
            float angle, Axis rotationAxis);
        static Matrix3x4f CreateScale(const Vector3f& scale);

        static Matrix3x4f CreateFromRowMajorFloats(
            const float values[ElementCount]);
        static Matrix3x4f CreateFromColumnMajorFloats(
            const float values[ElementCount]);

        static Matrix3x4f CreateFromRows(
            const Vector4f& row0, const Vector4f& row1, const Vector4f& row2);
        static Matrix3x4f CreateFromColumns(
            const Vector3f& column0,
            const Vector3f& column1,
            const Vector3f& column2,
            const Vector3f& column3);

        Matrix3x4f();
        Matrix3x4f(const Matrix3x4f& other) = default;
        Matrix3x4f(Matrix3x4f&& other) = default;
        ~Matrix3x4f() = default;

        [[nodiscard]] const Uni::Math::Vector4f& GetRow(unsigned int index) const;
        Uni::Math::Vector4f& GetRow(unsigned int index);

        [[nodiscard]] Vector3f TransformVector3f(const Vector3f& vector) const;
        [[nodiscard]] Vector4f TransformVector4f(const Vector4f& vector) const;

        Matrix3x4f& operator=(const Matrix3x4f& other) = default;

        Vector3f operator*(const Vector3f& vector) const;
        Vector4f operator*(const Vector4f& vector) const;
        Matrix3x4f operator*(const Matrix3x4f& other) const;

        Matrix3x4f& operator*=(const Matrix3x4f& other);

    private:
        Uni::Math::Vector4f m_rows[RowCount];
    };
} // namespace Uni::Math
