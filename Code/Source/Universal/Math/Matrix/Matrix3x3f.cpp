#include <Universal/Math/Math.h>
#include <Universal/Math/Matrix/Matrix3x3f.h>
#include <cmath>

namespace Uni::Math
{
    Matrix3x3f Matrix3x3f::CreateIdentity()
    {
        static const Matrix3x3f Identity = CreateFromRows(
            { 1.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f }, { 0.0f, 0.0f, 1.0f });

        return Identity;
    }

    Matrix3x3f Matrix3x3f::CreateFromRowMajorFloats(const float* values)
    {
        return CreateFromRows(
            { values[0], values[1], values[2] },
            { values[3], values[4], values[5] },
            { values[6], values[7], values[8] });
    }

    Matrix3x3f Matrix3x3f::CreateFromColumnMajorFloats(const float* values)
    {
        return CreateFromColumns(
            { values[0], values[1], values[2] },
            { values[3], values[4], values[5] },
            { values[6], values[7], values[8] });
    }

    Matrix3x3f Matrix3x3f::CreateFromRows(
        const Vector3f& row0, const Vector3f& row1, const Vector3f& row2)
    {
        Matrix3x3f matrix;

        matrix.m_rows[0] = row0;
        matrix.m_rows[1] = row1;
        matrix.m_rows[2] = row2;

        return matrix;
    }

    Matrix3x3f Matrix3x3f::CreateFromColumns(
        const Vector3f& column0,
        const Vector3f& column1,
        const Vector3f& column2)
    {
        Matrix3x3f matrix;

        matrix.m_rows[0].m_data[0] = column0.m_x;
        matrix.m_rows[0].m_data[1] = column1.m_x;
        matrix.m_rows[0].m_data[2] = column2.m_x;
        matrix.m_rows[1].m_data[0] = column0.m_y;
        matrix.m_rows[1].m_data[1] = column1.m_y;
        matrix.m_rows[1].m_data[2] = column2.m_y;
        matrix.m_rows[2].m_data[0] = column0.m_z;
        matrix.m_rows[2].m_data[1] = column1.m_z;
        matrix.m_rows[2].m_data[2] = column1.m_z;

        return matrix;
    }

    Matrix3x3f Matrix3x3f::GetTransposed() const
    {
        return CreateFromColumns(m_rows[0], m_rows[1], m_rows[2]);
    }

    float Matrix3x3f::GetDeterminant() const
    {
        return m_rows[0].m_data[0] *
            (m_rows[1].m_data[1] * m_rows[2].m_data[2] -
             m_rows[1].m_data[2] * m_rows[2].m_data[1]) -
            m_rows[0].m_data[1] *
            (m_rows[1].m_data[0] * m_rows[2].m_data[2] -
             m_rows[1].m_data[2] * m_rows[2].m_data[0]) +
            m_rows[0].m_data[2] *
            (m_rows[1].m_data[0] * m_rows[2].m_data[1] -
             m_rows[1].m_data[1] * m_rows[2].m_data[0]);
    }

    Matrix3x3f Matrix3x3f::GetInverse() const
    {
        return CreateFromRows(
                   {
                       m_rows[1].m_data[1] * m_rows[2].m_data[2] -
                           m_rows[1].m_data[2] * m_rows[2].m_data[1],
                       m_rows[0].m_data[2] * m_rows[2].m_data[1] -
                           m_rows[0].m_data[1] * m_rows[2].m_data[2],
                       m_rows[0].m_data[1] * m_rows[1].m_data[2] -
                           m_rows[0].m_data[2] * m_rows[1].m_data[1],
                   },
                   {
                       m_rows[1].m_data[2] * m_rows[2].m_data[0] -
                           m_rows[1].m_data[0] * m_rows[2].m_data[2],
                       m_rows[0].m_data[0] * m_rows[2].m_data[2] -
                           m_rows[0].m_data[2] * m_rows[2].m_data[0],
                       m_rows[0].m_data[2] * m_rows[1].m_data[0] -
                           m_rows[0].m_data[0] * m_rows[1].m_data[2],
                   },
                   {
                       m_rows[1].m_data[0] * m_rows[2].m_data[1] -
                           m_rows[1].m_data[1] * m_rows[2].m_data[0],
                       m_rows[0].m_data[1] * m_rows[2].m_data[0] -
                           m_rows[0].m_data[0] * m_rows[2].m_data[1],
                       m_rows[0].m_data[0] * m_rows[1].m_data[1] -
                           m_rows[0].m_data[1] * m_rows[1].m_data[0],
                   }) /
            GetDeterminant();
    }

    const Vector3f& Matrix3x3f::GetRow(unsigned int index) const
    {
        return m_rows[index];
    }

    Vector3f& Matrix3x3f::GetRow(unsigned int index) { return m_rows[index]; }

    Vector3f Matrix3x3f::TransformVector3f(const Vector3f& vector) const
    {
        return {
            m_rows[0].m_data[0] * vector.m_x +
                m_rows[0].m_data[1] * vector.m_y +
                m_rows[0].m_data[2] * vector.m_z,
            m_rows[1].m_data[0] * vector.m_x +
                m_rows[1].m_data[1] * vector.m_y +
                m_rows[1].m_data[2] * vector.m_z,
            m_rows[2].m_data[0] * vector.m_x +
                m_rows[2].m_data[1] * vector.m_y +
                m_rows[2].m_data[2] * vector.m_z,
        };
    }

    Vector3f Matrix3x3f::operator*(const Vector3f& vector) const
    {
        return TransformVector3f(vector);
    }

    Matrix3x3f Matrix3x3f::operator*(float value) const
    {
        return CreateFromRows(
            m_rows[0] * value, m_rows[1] * value, m_rows[2] * value);
    }

    Matrix3x3f Matrix3x3f::operator/(float value) const
    {
        return CreateFromRows(
            m_rows[0] / value, m_rows[1] / value, m_rows[2] / value);
    }

    Matrix3x3f Matrix3x3f::operator*(const Matrix3x3f& other) const
    {
        Matrix3x3f result;

        for (size_t row = 0; row < RowCount; ++row)
        {
            for (size_t column = 0; column < ColumnCount; ++column)
            {
                result.m_rows[row].m_data[column] =
                    m_rows[row].m_data[0] * other.m_rows[0].m_data[column] +
                    m_rows[row].m_data[1] * other.m_rows[1].m_data[column] +
                    m_rows[row].m_data[2] * other.m_rows[2].m_data[column];
            }
        }

        return result;
    }

    Matrix3x3f& Matrix3x3f::operator*=(const Matrix3x3f& other)
    {
        *this = *this * other;
        return *this;
    }

    Matrix3x3f operator-(const Matrix3x3f& matrix) { return matrix * -1.0f; }

    Matrix3x3f operator*(float lhs, const Matrix3x3f& rhs) { return rhs * lhs; }
} // namespace Uni::Math
