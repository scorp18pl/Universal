#include <Universal/Math/Math.h>
#include <Universal/Math/Matrix/Matrix2x3f.h>
#include <cmath>

Uni::Math::Matrix2x3f Uni::Math::Matrix2x3f::CreateIdentity()
{
    static const Matrix2x3f Identity =
        CreateFromRows({ 1.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f });

    return Identity;
}

Uni::Math::Matrix2x3f Uni::Math::Matrix2x3f::CreateTranslation(
    const Uni::Math::Vector2f& translation)
{
    return CreateFromRows(
        { 1.0f, 0.0f, translation.m_x }, { 0.0f, 1.0f, translation.m_y });
}

Uni::Math::Matrix2x3f Uni::Math::Matrix2x3f::CreateRotationRadians(float angle)
{
    return CreateFromRows(
        { std::cos(angle), -std::sin(angle), 0.0f },
        { std::sin(angle), std::cos(angle), 0.0f });
}

Uni::Math::Matrix2x3f Uni::Math::Matrix2x3f::CreateRotationDegrees(float angle)
{
    return CreateRotationRadians(angle * (Math::Constants::PI / 180.0f));
}

Uni::Math::Matrix2x3f Uni::Math::Matrix2x3f::CreateScale(
    const Uni::Math::Vector2f& scale)
{
    return CreateFromRows({ scale.m_x, 0.0f, 0.0f }, { 0.0f, scale.m_y, 0.0f });
}

Uni::Math::Matrix2x3f Uni::Math::Matrix2x3f::CreateFromRowMajorFloats(
    const float* values)
{
    Matrix2x3f matrix;

    matrix.m_rows[0].m_data[0] = values[0];
    matrix.m_rows[0].m_data[1] = values[1];
    matrix.m_rows[0].m_data[2] = values[2];
    matrix.m_rows[1].m_data[0] = values[3];
    matrix.m_rows[1].m_data[1] = values[4];
    matrix.m_rows[1].m_data[2] = values[5];

    return matrix;
}

Uni::Math::Matrix2x3f Uni::Math::Matrix2x3f::CreateFromColumnMajorFloats(
    const float* values)
{
    Matrix2x3f matrix;

    matrix.m_rows[0].m_data[0] = values[0];
    matrix.m_rows[0].m_data[1] = values[2];
    matrix.m_rows[0].m_data[2] = values[4];
    matrix.m_rows[1].m_data[0] = values[1];
    matrix.m_rows[1].m_data[1] = values[3];
    matrix.m_rows[1].m_data[2] = values[5];

    return matrix;
}

Uni::Math::Matrix2x3f Uni::Math::Matrix2x3f::CreateFromRows(
    const Uni::Math::Vector3f& row0, const Uni::Math::Vector3f& row1)
{
    Matrix2x3f matrix;

    matrix.m_rows[0] = row0;
    matrix.m_rows[1] = row1;

    return matrix;
}

Uni::Math::Matrix2x3f Uni::Math::Matrix2x3f::CreateFromColumns(
    const Uni::Math::Vector2f& column0,
    const Uni::Math::Vector2f& column1,
    const Uni::Math::Vector2f& column2)
{
    Matrix2x3f matrix;

    matrix.m_rows[0].m_data[0] = column0.m_x;
    matrix.m_rows[0].m_data[1] = column1.m_x;
    matrix.m_rows[0].m_data[2] = column2.m_x;
    matrix.m_rows[1].m_data[0] = column0.m_y;
    matrix.m_rows[1].m_data[1] = column1.m_y;
    matrix.m_rows[1].m_data[2] = column2.m_y;

    return matrix;
}

const Uni::Math::Vector3f& Uni::Math::Matrix2x3f::GetRow(
    unsigned int index) const
{
    return m_rows[index];
}

Uni::Math::Vector3f& Uni::Math::Matrix2x3f::GetRow(unsigned int index)
{
    return m_rows[index];
}

Uni::Math::Vector2f Uni::Math::Matrix2x3f::TransformVector2f(
    const Uni::Math::Vector2f& vector) const
{
    return {
        m_rows[0].m_data[0] * vector.m_x + m_rows[0].m_data[1] * vector.m_y +
            m_rows[0].m_data[2],
        m_rows[1].m_data[0] * vector.m_x + m_rows[1].m_data[1] * vector.m_y +
            m_rows[1].m_data[2],
    };
}

Uni::Math::Vector3f Uni::Math::Matrix2x3f::TransformVector3f(
    const Uni::Math::Vector3f& vector) const
{
    return {
        m_rows[0].m_data[0] * vector.m_x + m_rows[0].m_data[1] * vector.m_y +
            m_rows[0].m_data[2] * vector.m_z,
        m_rows[1].m_data[0] * vector.m_x + m_rows[1].m_data[1] * vector.m_y +
            m_rows[1].m_data[2] * vector.m_z,
        vector.m_z,
    };
}

Uni::Math::Vector2f Uni::Math::Matrix2x3f::operator*(
    const Uni::Math::Vector2f& vector) const
{
    return TransformVector2f(vector);
}

Uni::Math::Vector3f Uni::Math::Matrix2x3f::operator*(
    const Uni::Math::Vector3f& vector) const
{
    return TransformVector3f(vector);
}


Uni::Math::Matrix2x3f Uni::Math::Matrix2x3f::operator*(
    const Uni::Math::Matrix2x3f& other) const
{
    return CreateFromRows(
        {
            m_rows[0].m_data[0] * other.m_rows[0].m_data[0] +
                m_rows[0].m_data[1] * other.m_rows[1].m_data[0],
            m_rows[0].m_data[0] * other.m_rows[0].m_data[1] +
                m_rows[0].m_data[1] * other.m_rows[1].m_data[1],
            m_rows[0].m_data[0] * other.m_rows[0].m_data[2] +
                m_rows[0].m_data[1] * other.m_rows[1].m_data[2] +
                m_rows[0].m_data[2],
        },
        {
            m_rows[1].m_data[0] * other.m_rows[0].m_data[0] +
                m_rows[1].m_data[1] * other.m_rows[1].m_data[0],
            m_rows[1].m_data[0] * other.m_rows[0].m_data[1] +
                m_rows[1].m_data[1] * other.m_rows[1].m_data[1],
            m_rows[1].m_data[0] * other.m_rows[0].m_data[2] +
                m_rows[1].m_data[1] * other.m_rows[1].m_data[2] +
                m_rows[1].m_data[2],
        });
}

Uni::Math::Matrix2x3f& Uni::Math::Matrix2x3f::operator*=(
    const Uni::Math::Matrix2x3f& other)
{
    *this = *this * other;
    return *this;
}
