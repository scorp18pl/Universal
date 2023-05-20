#pragma once

#include <Universal/Math/Vector/Vector2f.h>
#include <Universal/Math/Vector/Vector3f.h>

namespace Uni::Math
{
    //! A generic 2x3 matrix class with float components.
    class Matrix2x3f
    {
    private:
        static constexpr unsigned int RowCount = 2;
        static constexpr unsigned int ColumnCount = 3;
        static constexpr unsigned int ElementCount = RowCount * ColumnCount;

    public:
        static Matrix2x3f CreateIdentity();

        static Matrix2x3f CreateTranslation(const Vector2f& translation);
        static Matrix2x3f CreateRotationRadians(float angle);
        static Matrix2x3f CreateRotationDegrees(float angle);
        static Matrix2x3f CreateScale(const Vector2f& scale);

        static Matrix2x3f CreateFromRowMajorFloats(
            const float values[ElementCount]);
        static Matrix2x3f CreateFromColumnMajorFloats(
            const float values[ElementCount]);

        static Matrix2x3f CreateFromRows(
            const Vector3f& row0, const Vector3f& row1);
        static Matrix2x3f CreateFromColumns(
            const Vector2f& column0,
            const Vector2f& column1,
            const Vector2f& column2);

        Matrix2x3f() = default;
        Matrix2x3f(const Matrix2x3f& other) = default;
        Matrix2x3f(Matrix2x3f&& other) = default;
        ~Matrix2x3f() = default;

        [[nodiscard]] const Uni::Math::Vector3f& GetRow(unsigned int index) const;
        Uni::Math::Vector3f& GetRow(unsigned int index);

        Vector2f TransformVector2f(const Vector2f& vector) const;
        Vector3f TransformVector3f(const Vector3f& vector) const;

        Matrix2x3f& operator=(const Matrix2x3f& other) = default;

        Vector2f operator*(const Vector2f& vector) const;
        Vector3f operator*(const Vector3f& vector) const;
        Matrix2x3f operator*(const Matrix2x3f& other) const;

        Matrix2x3f& operator*=(const Matrix2x3f& other);

    private:
        Uni::Math::Vector3f m_rows[RowCount];
    };
} // namespace Uni::Math
