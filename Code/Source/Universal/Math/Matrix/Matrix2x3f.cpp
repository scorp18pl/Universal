#include <Universal/Math/Math.h>
#include <Universal/Math/Matrix/Matrix2x3f.h>
#include <cmath>

Uni::Math::Matrix2x3f Uni::Math::Matrix2x3f::CreateIdentity()
{
    static const float IdentityValues[6] = {
        1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,
    };
    static const Matrix2x3f Identity = CreateFromRowMajorFloats(IdentityValues);

    return Identity;
}

Uni::Math::Matrix2x3f Uni::Math::Matrix2x3f::CreateFromTranslation(
    const Uni::Math::Vector2f& translation)
{
    const float RowMajorValues[6] = {
        1.0f, 0.0f, translation.m_x, 0.0f, 1.0f, translation.m_y,
    };
    return CreateFromRowMajorFloats(RowMajorValues);
}

Uni::Math::Matrix2x3f Uni::Math::Matrix2x3f::CreateFromRotationRadians(
    float angle)
{
    const float RowMajorValues[6] = {
        std::cos(angle), -std::sin(angle), 0.0f,
        std::sin(angle), std::cos(angle),  0.0f,
    };
    return CreateFromRowMajorFloats(RowMajorValues);
}

Uni::Math::Matrix2x3f Uni::Math::Matrix2x3f::CreateFromRotationDegrees(
    float angle)
{
    return CreateFromRotationRadians(angle * (Math::Constants::PI / 180.0f));
}

Uni::Math::Matrix2x3f Uni::Math::Matrix2x3f::CreateFromScale(
    const Uni::Math::Vector2f& scale)
{
    const float RowMajorValues[6] = {
        scale.m_x, 0.0f, 0.0f, 0.0f, scale.m_y, 0.0f,
    };
    return CreateFromRowMajorFloats(RowMajorValues);
}

Uni::Math::Matrix2x3f Uni::Math::Matrix2x3f::CreateFromRowMajorFloats(
    const float* values)
{
    Matrix2x3f matrix;

    matrix.m_values[0] = values[0];
    matrix.m_values[1] = values[1];
    matrix.m_values[2] = values[2];
    matrix.m_values[3] = values[3];
    matrix.m_values[4] = values[4];
    matrix.m_values[5] = values[5];

    return matrix;
}

float Uni::Math::Matrix2x3f::operator()(size_t row, size_t column) const
{
    return m_values[row * 3 + column];
}

float& Uni::Math::Matrix2x3f::operator()(size_t row, size_t column)
{
    return m_values[row * 3 + column];
}

Uni::Math::Vector2f Uni::Math::Matrix2x3f::TransformVector2f(
    const Uni::Math::Vector2f& vector) const
{
    return {
        m_values[0] * vector.m_x + m_values[1] * vector.m_y + m_values[2],
        m_values[3] * vector.m_x + m_values[4] * vector.m_y + m_values[5],
    };
}

Uni::Math::Vector3f Uni::Math::Matrix2x3f::TransformVector3f(
    const Uni::Math::Vector3f& vector) const
{
    return {
        m_values[0] * vector.m_x + m_values[1] * vector.m_y +
            m_values[2] * vector.m_z,
        m_values[3] * vector.m_x + m_values[4] * vector.m_y +
            m_values[5] * vector.m_z,
        vector.m_z,
    };
}

Uni::Math::Matrix2x3f Uni::Math::Matrix2x3f::operator*(
    const Uni::Math::Matrix2x3f& other) const
{
    const float RowMajorValues[6] = {
        m_values[0] * other.m_values[0] + m_values[1] * other.m_values[3],
        m_values[0] * other.m_values[1] + m_values[1] * other.m_values[4],
        m_values[0] * other.m_values[2] + m_values[1] * other.m_values[5] +
            m_values[2],
        m_values[3] * other.m_values[0] + m_values[4] * other.m_values[3],
        m_values[3] * other.m_values[1] + m_values[4] * other.m_values[4],
        m_values[3] * other.m_values[2] + m_values[4] * other.m_values[5] +
            m_values[5],
    };

    return CreateFromRowMajorFloats(RowMajorValues);
}

Uni::Math::Matrix2x3f& Uni::Math::Matrix2x3f::operator*=(
    const Uni::Math::Matrix2x3f& other)
{
    *this = *this * other;
    return *this;
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
