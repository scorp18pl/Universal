#pragma once

#include <Universal/Math/Vector/Vector2f.h>
#include <Universal/Math/Vector/Vector3f.h>

namespace Uni::Math
{
    //! A generic 3x3 matrix class with float components.
    class Matrix3x3f
    {
    private:
        static constexpr unsigned int RowCount = 3;
        static constexpr unsigned int ColumnCount = 3;
        static constexpr unsigned int ElementCount = RowCount * ColumnCount;

    public:
        static Matrix3x3f CreateIdentity();

        static Matrix3x3f CreateFromRowMajorFloats(
            const float values[ElementCount]);
        static Matrix3x3f CreateFromColumnMajorFloats(
            const float values[ElementCount]);

        static Matrix3x3f CreateFromRows(
            const Vector3f& row0, const Vector3f& row1, const Vector3f& row2);
        static Matrix3x3f CreateFromColumns(
            const Vector3f& column0,
            const Vector3f& column1,
            const Vector3f& column2);

        Matrix3x3f() = default;
        Matrix3x3f(const Matrix3x3f& other) = default;
        Matrix3x3f(Matrix3x3f&& other) = default;
        ~Matrix3x3f() = default;

        [[nodiscard]] Matrix3x3f GetTransposed() const;
        [[nodiscard]] float GetDeterminant() const;
        [[nodiscard]] Matrix3x3f GetInverse() const;

        [[nodiscard]] const Vector3f& GetRow(unsigned int index) const;
        Vector3f& GetRow(unsigned int index);

        [[nodiscard]] Vector3f TransformVector3f(const Vector3f& vector) const;

        Matrix3x3f& operator=(const Matrix3x3f& other) = default;

        Vector3f operator*(const Vector3f& vector) const;
        Matrix3x3f operator*(float value) const;
        Matrix3x3f operator/(float value) const;
        Matrix3x3f operator*(const Matrix3x3f& other) const;

        Matrix3x3f& operator*=(const Matrix3x3f& other);

        friend Matrix3x3f operator-(const Matrix3x3f &matrix);
        friend Matrix3x3f operator*(float lhs, const Matrix3x3f &rhs);
    private:
        Vector3f m_rows[RowCount];
    };
} // namespace Uni::Math
