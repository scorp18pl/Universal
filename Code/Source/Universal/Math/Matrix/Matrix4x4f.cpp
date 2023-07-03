#include <Universal/Math/Math.h>
#include <Universal/Math/Matrix/Matrix3x4f.h>
#include <Universal/Math/Matrix/Matrix4x4f.h>
#include <cmath>

namespace Uni::Math
{
    Matrix4x4f Matrix4x4f::CreateIdentity()
    {
        static Matrix4x4f Identity = CreateFromRows(
            { 1.0f, 0.0f, 0.0f, 0.0f },
            { 0.0f, 1.0f, 0.0f, 0.0f },
            { 0.0f, 0.0f, 1.0f, 0.0f },
            { 0.0f, 0.0f, 0.0f, 1.0f });

        return Identity;
    }

    Matrix4x4f Matrix4x4f::CreateTranslation(const Vector3f& translation)
    {
        // clang-format off
        return CreateFromRows(
            { 1.0f, 0.0f, 0.0f, translation.m_x },
            { 0.0f, 1.0f, 0.0f, translation.m_y },
            { 0.0f, 0.0f, 1.0f, translation.m_z },
            { 0.0f, 0.0f, 0.0f, 1.0f            });
        // clang-format on
    }

    Matrix4x4f Matrix4x4f::CreateRotationEulerRadians(
        float angle, Axis rotationAxis)
    {
        switch (rotationAxis)
        {
        case Axis::X:
            // clang-format off
            return CreateFromRows(
                { 1.0f, 0.0f,             0.0f,            0.0f },
                { 0.0f, std::cos(angle), -std::sin(angle), 0.0f },
                { 0.0f, std::sin(angle),  std::cos(angle), 0.0f },
                { 0.0f, 0.0f,             0.0f,            1.0f });
        case Axis::Y:
            return CreateFromRows(
                {  std::cos(angle), 0.0f, std::sin(angle), 0.0f },
                {  0.0f,            1.0f, 0.0f,            0.0f },
                { -std::sin(angle), 0.0f, std::cos(angle), 0.0f },
                {  0.0f,            0.0f, 0.0f,            1.0f });
        case Axis::Z:
            return CreateFromRows(
                { std::cos(angle), -std::sin(angle), 0.0f, 0.0f },
                { std::sin(angle),  std::cos(angle), 0.0f, 0.0f },
                { 0.0f,             0.0f,            1.0f, 0.0f },
                { 0.0f,             0.0f,            0.0f, 1.0f });
            // clang-format on
        }

        return CreateIdentity();
    }

    Matrix4x4f Matrix4x4f::CreateRotationEulerDegrees(
        float angle, Axis rotationAxis)
    {
        return CreateRotationEulerRadians(
            angle * (Constants::PI / 180.0f), rotationAxis);
    }

    Matrix4x4f Matrix4x4f::CreateScale(const Vector3f& scale)
    {
        // clang-format off
        return CreateFromRows(
            { scale.m_x, 0.0f,      0.0f,      0.0f },
            { 0.0f,      scale.m_y, 0.0f,      0.0f },
            { 0.0f,      0.0f,      scale.m_z, 0.0f },
            { 0.0f,      0.0f,      0.0f,      1.0f });
        // clang-format on
    }

    Matrix4x4f Matrix4x4f::CreateFromRowMajorFloats(const float* values)
    {
        // clang-format off
        return CreateFromRows(
            { values[0],  values[1],  values[2],  values[3]  },
            { values[4],  values[5],  values[6],  values[7]  },
            { values[8],  values[9],  values[10], values[11] },
            { values[12], values[13], values[14], values[15] });
        // clang-format on
    }

    Matrix4x4f Matrix4x4f::CreateFromColumnMajorFloats(const float* values)
    {
        // clang-format off
        return CreateFromColumns(
            { values[0],  values[1],  values[2],  values[3]  },
            { values[4],  values[5],  values[6],  values[7]  },
            { values[8],  values[9],  values[10], values[11] },
            { values[12], values[13], values[14], values[15] });
        // clang-format on
    }

    Matrix4x4f Matrix4x4f::CreateFromRows(
        const Vector4f& row0,
        const Vector4f& row1,
        const Vector4f& row2,
        const Vector4f& row3)
    {
        Matrix4x4f matrix;

        matrix.m_rows[0] = row0;
        matrix.m_rows[1] = row1;
        matrix.m_rows[2] = row2;
        matrix.m_rows[3] = row3;

        return matrix;
    }

    Matrix4x4f Matrix4x4f::CreateFromColumns(
        const Vector4f& column0,
        const Vector4f& column1,
        const Vector4f& column2,
        const Vector4f& column3)
    {
        Matrix4x4f matrix;

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

        matrix.m_rows[3].m_data[0] = column0.m_w;
        matrix.m_rows[3].m_data[1] = column1.m_w;
        matrix.m_rows[3].m_data[2] = column2.m_w;
        matrix.m_rows[3].m_data[3] = column3.m_w;

        return matrix;
    }

    const Uni::Math::Vector4f& Matrix4x4f::GetRow(unsigned int index) const
    {
        return m_rows[index];
    }

    Uni::Math::Vector4f& Matrix4x4f::GetRow(unsigned int index)
    {
        return m_rows[index];
    }

    Matrix3x4f Matrix4x4f::ToMatrix3x4f() const
    {
        return Matrix3x4f::CreateFromRows(m_rows[0], m_rows[1], m_rows[2]);
    }

    Vector3f Matrix4x4f::TransformVector3f(const Vector3f& vector) const
    {
        const Vector4f homogeneousVector = vector.GetHomogeneous();
        return {
            m_rows[0].DotProduct(homogeneousVector),
            m_rows[1].DotProduct(homogeneousVector),
            m_rows[2].DotProduct(homogeneousVector),
        };
    }

    Vector4f Matrix4x4f::TransformVector4f(const Vector4f& vector) const
    {
        return {
            m_rows[0].DotProduct(vector),
            m_rows[1].DotProduct(vector),
            m_rows[2].DotProduct(vector),
            m_rows[3].DotProduct(vector),
        };
    }

    Matrix4x4f Matrix4x4f::operator*(const Matrix4x4f& other) const
    {
        Matrix4x4f result;

        for (size_t row = 0; row < RowCount; ++row)
        {
            for (size_t column = 0; column < ColumnCount; ++column)
            {
                result.m_rows[row].m_data[column] =
                    m_rows[row].m_data[0] * other.m_rows[0].m_data[column] +
                    m_rows[row].m_data[1] * other.m_rows[1].m_data[column] +
                    m_rows[row].m_data[2] * other.m_rows[2].m_data[column] +
                    m_rows[row].m_data[3] * other.m_rows[3].m_data[column];
            }
        }

        return result;
    }

    Vector3f Matrix4x4f::operator*(const Vector3f& vector) const
    {
        return TransformVector3f(vector);
    }

    Vector4f Matrix4x4f::operator*(const Vector4f& vector) const
    {
        return TransformVector4f(vector);
    }

    Matrix4x4f& Matrix4x4f::operator*=(const Matrix4x4f& other)
    {
        return *this = *this * other;
    }
} // namespace Uni::Math