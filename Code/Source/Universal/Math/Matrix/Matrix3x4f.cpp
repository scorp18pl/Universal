#include <Universal/Math/Math.h>
#include <Universal/Math/Matrix/Matrix3x4f.h>
#include <cmath>

namespace Uni::Math
{
    Matrix3x4f Matrix3x4f::CreateIdentity()
    {
        static constexpr float values[ElementCount] = {
            1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
            0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,
        };

        return CreateFromRowMajorFloats(values);
    }

    Matrix3x4f Matrix3x4f::CreateFromTranslation(const Vector3f& translation)
    {
        const float values[ElementCount] = {
            1.0f, 0.0f, 0.0f, translation.m_x,
            0.0f, 1.0f, 0.0f, translation.m_y,
            0.0f, 0.0f, 1.0f, translation.m_z,
        };

        return CreateFromRowMajorFloats(values);
    }

    Matrix3x4f Matrix3x4f::CreateFromRotationRadians(
        float angle, Axis rotationAxis)
    {
        float values[ElementCount] = { 0.0f };

        switch (rotationAxis)
        {
        case Axis::X:
            values[0] = 1.0f;
            values[5] = std::cos(angle);
            values[6] = -std::sin(angle);
            values[9] = std::sin(angle);
            values[10] = std::cos(angle);
            break;
        case Axis::Y:
            values[0] = std::cos(angle);
            values[2] = std::sin(angle);
            values[5] = 1.0f;
            values[8] = -std::sin(angle);
            values[10] = std::cos(angle);
            break;
        case Axis::Z:
            values[0] = std::cos(angle);
            values[1] = -std::sin(angle);
            values[4] = std::sin(angle);
            values[5] = std::cos(angle);
            values[10] = 1.0f;
            break;
        }

        return CreateFromRowMajorFloats(values);
    }

    Matrix3x4f Matrix3x4f::CreateFromRotationDegrees(
        float angle, Axis rotationAxis)
    {
        return CreateFromRotationRadians(
            angle * (Constants::PI / 180.0f), rotationAxis);
    }

    Matrix3x4f Matrix3x4f::CreateFromScale(const Vector3f& scale)
    {
        const float values[ElementCount] = {
            scale.m_x, 0.0f, 0.0f, 0.0f, 0.0f,      scale.m_y,
            0.0f,      0.0f, 0.0f, 0.0f, scale.m_z, 0.0f,
        };

        return CreateFromRowMajorFloats(values);
    }

    Matrix3x4f Matrix3x4f::CreateFromRowMajorFloats(const float* values)
    {
        Matrix3x4f matrix;
        for (size_t i = 0; i < ElementCount; ++i)
        {
            matrix.m_values[i] = values[i];
        }
        return matrix;
    }

    float Matrix3x4f::operator()(size_t row, size_t column) const
    {
        return m_values[row * ColumnCount + column];
    }

    float& Matrix3x4f::operator()(size_t row, size_t column)
    {
        return m_values[row * ColumnCount + column];
    }

    Vector3f Matrix3x4f::TransformVector3f(const Vector3f& vector) const
    {
        return {
            (vector.m_x * m_values[0]) + (vector.m_y * m_values[1]) +
                (vector.m_z * m_values[2]) + m_values[3],
            (vector.m_x * m_values[4]) + (vector.m_y * m_values[5]) +
                (vector.m_z * m_values[6]) + m_values[7],
            (vector.m_x * m_values[8]) + (vector.m_y * m_values[9]) +
                (vector.m_z * m_values[10]) + m_values[11],
        };
    }

    Vector4f Matrix3x4f::TransformVector4f(const Vector4f& vector) const
    {
        return {
            (vector.m_x * m_values[0]) + (vector.m_y * m_values[1]) +
                (vector.m_z * m_values[2]) + (vector.m_w * m_values[3]),
            (vector.m_x * m_values[4]) + (vector.m_y * m_values[5]) +
                (vector.m_z * m_values[6]) + (vector.m_w * m_values[7]),
            (vector.m_x * m_values[8]) + (vector.m_y * m_values[9]) +
                (vector.m_z * m_values[10]) + (vector.m_w * m_values[11]),
            vector.m_w,
        };
    }

    Matrix3x4f& Matrix3x4f::operator*=(const Matrix3x4f& other)
    {
        Matrix3x4f copy{ *this };

        copy.m_values[0] = (m_values[0] * other.m_values[0]) +
            (m_values[1] * other.m_values[4]) +
            (m_values[2] * other.m_values[8]);
        copy.m_values[1] = (m_values[0] * other.m_values[1]) +
            (m_values[1] * other.m_values[5]) +
            (m_values[2] * other.m_values[9]);
        copy.m_values[2] = (m_values[0] * other.m_values[2]) +
            (m_values[1] * other.m_values[6]) +
            (m_values[2] * other.m_values[10]);
        copy.m_values[3] = (m_values[0] * other.m_values[3]) +
            (m_values[1] * other.m_values[7]) +
            (m_values[2] * other.m_values[11]) + m_values[3];
        copy.m_values[4] = (m_values[4] * other.m_values[0]) +
            (m_values[5] * other.m_values[4]) +
            (m_values[6] * other.m_values[8]);
        copy.m_values[5] = (m_values[4] * other.m_values[1]) +
            (m_values[5] * other.m_values[5]) +
            (m_values[6] * other.m_values[9]);
        copy.m_values[6] = (m_values[4] * other.m_values[2]) +
            (m_values[5] * other.m_values[6]) +
            (m_values[6] * other.m_values[10]);
        copy.m_values[7] = (m_values[4] * other.m_values[3]) +
            (m_values[5] * other.m_values[7]) +
            (m_values[6] * other.m_values[11]) + m_values[7];
        copy.m_values[8] = (m_values[8] * other.m_values[0]) +
            (m_values[9] * other.m_values[4]) +
            (m_values[10] * other.m_values[8]);
        copy.m_values[9] = (m_values[8] * other.m_values[1]) +
            (m_values[9] * other.m_values[5]) +
            (m_values[10] * other.m_values[9]);
        copy.m_values[10] = (m_values[8] * other.m_values[2]) +
            (m_values[9] * other.m_values[6]) +
            (m_values[10] * other.m_values[10]);
        copy.m_values[11] = (m_values[8] * other.m_values[3]) +
            (m_values[9] * other.m_values[7]) +
            (m_values[10] * other.m_values[11]) + m_values[11];

        (*this) = copy;
        return *this;
    }

    Matrix3x4f Matrix3x4f::operator*(const Matrix3x4f& other) const
    {
        Matrix3x4f matrix{ *this };
        matrix *= other;

        return matrix;
    }

    Vector3f Matrix3x4f::operator*(const Vector3f& vector) const
    {
        return TransformVector3f(vector);
    }

    Vector4f Matrix3x4f::operator*(const Vector4f& vector) const
    {
        return TransformVector4f(vector);
    }
} // namespace Uni::Math