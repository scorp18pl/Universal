#include <Universal/Math/Math.h>
#include <Universal/Math/Matrix/Matrix3x4f.h>
#include <cmath>

namespace Uni::Math
{
    Matrix3x4f Matrix3x4f::CreateIdentity()
    {
        return Matrix4x4f::CreateIdentity().ToMatrix3x4f();
    }

    Matrix3x4f Matrix3x4f::CreateTranslation(const Vector3f& translation)
    {
        return Matrix4x4f::CreateTranslation(translation).ToMatrix3x4f();
    }

    Matrix3x4f Matrix3x4f::CreateRotationEulerRadians(
        float angle, Axis rotationAxis)
    {
        return Matrix4x4f::CreateRotationEulerRadians(angle, rotationAxis)
            .ToMatrix3x4f();
    }

    Matrix3x4f Matrix3x4f::CreateRotationEulerDegrees(
        float angle, Axis rotationAxis)
    {
        return Matrix4x4f::CreateRotationEulerDegrees(angle, rotationAxis)
            .ToMatrix3x4f();
    }

    Matrix3x4f Matrix3x4f::CreateScale(const Vector3f& scale)
    {
        return Matrix4x4f::CreateScale(scale).ToMatrix3x4f();
    }

    Matrix3x4f Matrix3x4f::CreateFromRowMajorFloats(const float* values)
    {
        return CreateFromRows(
            { values[0], values[1], values[2], values[3] },
            { values[4], values[5], values[6], values[7] },
            { values[8], values[9], values[10], values[11] });
    }

    Matrix3x4f Matrix3x4f::CreateFromColumnMajorFloats(const float* values)
    {
        return CreateFromColumns(
            { values[0], values[1], values[2] },
            { values[3], values[4], values[5] },
            { values[6], values[7], values[8] },
            { values[9], values[10], values[11] });
    }

    Matrix3x4f Matrix3x4f::CreateFromRows(
        const Vector4f& row0, const Vector4f& row1, const Vector4f& row2)
    {
        Matrix3x4f matrix;

        matrix.m_rows[0] = row0;
        matrix.m_rows[1] = row1;
        matrix.m_rows[2] = row2;

        return matrix;
    }

    Matrix3x4f Matrix3x4f::CreateFromColumns(
        const Vector3f& column0,
        const Vector3f& column1,
        const Vector3f& column2,
        const Vector3f& column3)
    {
        Matrix3x4f matrix;

        matrix.m_rows[0].m_data[0] = column0.m_x;
        matrix.m_rows[0].m_data[1] = column1.m_x;
        matrix.m_rows[0].m_data[2] = column2.m_x;
        matrix.m_rows[0].m_data[3] = column3.m_x;

        matrix.m_rows[1].m_data[0] = column0.m_y;
        matrix.m_rows[1].m_data[1] = column1.m_y;
        matrix.m_rows[1].m_data[2] = column2.m_y;
        matrix.m_rows[1].m_data[3] = column3.m_y;

        matrix.m_rows[2].m_data[0] = column0.m_z;
        matrix.m_rows[2].m_data[1] = column1.m_z;
        matrix.m_rows[2].m_data[2] = column2.m_z;
        matrix.m_rows[2].m_data[3] = column3.m_z;

        return matrix;
    }

    const Uni::Math::Vector4f& Matrix3x4f::GetRow(unsigned int index) const
    {
        return m_rows[index];
    }

    Uni::Math::Vector4f& Matrix3x4f::GetRow(unsigned int index)
    {
        return m_rows[index];
    }

    Matrix4x4f Matrix3x4f::ToMatrix4x4f() const
    {
        return Matrix4x4f::CreateFromRows(
            m_rows[0], m_rows[1], m_rows[2], { 0.0f, 0.0f, 0.0f, 1.0f });
    }

    Vector3f Matrix3x4f::TransformVector3f(const Vector3f& vector) const
    {
        return {
            m_rows[0].m_data[0] * vector.m_x +
                m_rows[0].m_data[1] * vector.m_y +
                m_rows[0].m_data[2] * vector.m_z + m_rows[0].m_data[3],
            m_rows[1].m_data[0] * vector.m_x +
                m_rows[1].m_data[1] * vector.m_y +
                m_rows[1].m_data[2] * vector.m_z + m_rows[1].m_data[3],
            m_rows[2].m_data[0] * vector.m_x +
                m_rows[2].m_data[1] * vector.m_y +
                m_rows[2].m_data[2] * vector.m_z + m_rows[2].m_data[3],
        };
    }

    Vector4f Matrix3x4f::TransformVector4f(const Vector4f& vector) const
    {
        return {
            m_rows[0].m_data[0] * vector.m_x +
                m_rows[0].m_data[1] * vector.m_y +
                m_rows[0].m_data[2] * vector.m_z +
                m_rows[0].m_data[3] * vector.m_w,
            m_rows[1].m_data[0] * vector.m_x +
                m_rows[1].m_data[1] * vector.m_y +
                m_rows[1].m_data[2] * vector.m_z +
                m_rows[1].m_data[3] * vector.m_w,
            m_rows[2].m_data[0] * vector.m_x +
                m_rows[2].m_data[1] * vector.m_y +
                m_rows[2].m_data[2] * vector.m_z +
                m_rows[2].m_data[3] * vector.m_w,
            vector.m_w,
        };
    }

    Matrix3x4f Matrix3x4f::operator*(const Matrix3x4f& other) const
    {
        Matrix3x4f result;

        for (size_t row = 0; row < RowCount; ++row)
        {
            for (size_t column = 0; column < ColumnCount; ++column)
            {
                result.m_rows[row].m_data[column] =
                    m_rows[row].m_data[0] * other.m_rows[0].m_data[column] +
                    m_rows[row].m_data[1] * other.m_rows[1].m_data[column] +
                    m_rows[row].m_data[2] * other.m_rows[2].m_data[column] +
                    m_rows[row].m_data[3] * (column == 3 ? 1.0f : 0.0f);
            }
        }

        return result;
    }

    Vector3f Matrix3x4f::operator*(const Vector3f& vector) const
    {
        return TransformVector3f(vector);
    }

    Vector4f Matrix3x4f::operator*(const Vector4f& vector) const
    {
        return TransformVector4f(vector);
    }

    Matrix3x4f& Matrix3x4f::operator*=(const Matrix3x4f& other)
    {
        return *this = *this * other;
    }
} // namespace Uni::Math