#include <Universal/Math/Math.h>
#include <Universal/Math/Matrix/Matrix3x4f.h>
#include <Universal/Math/Quaternion.h>
#include <Universal/Math/Vector/Vector3f.h>
#include <valarray>

namespace Uni::Math
{
    Quaternion Quaternion::CreateIdentity()
    {
        return Quaternion{ 1.0f, 0.0f, 0.0f, 0.0f };
    }

    Quaternion Quaternion::CreateFromAxisRad(float angle, const Vector3f& axis)
    {
        const float Sin = std::sin(angle / 2.0f);
        const Vector3f NormalizedAxis = axis.GetNormalized();

        return Quaternion{
            std::cos(angle / 2.0f),
            NormalizedAxis.m_x * Sin,
            NormalizedAxis.m_y * Sin,
            NormalizedAxis.m_z * Sin,
        };
    }

    Quaternion Quaternion::CreateFromEulerRadZYX(const Vector3f& angles)
    {
        const float HalfX = angles.m_x / 2.0f;
        const float HalfY = angles.m_y / 2.0f;
        const float HalfZ = angles.m_z / 2.0f;

        const float SinX = std::sin(HalfX);
        const float SinY = std::sin(HalfY);
        const float SinZ = std::sin(HalfZ);

        const float CosX = std::cos(HalfX);
        const float CosY = std::cos(HalfY);
        const float CosZ = std::cos(HalfZ);

        return {
            CosX * CosY * CosZ + SinX * SinY * SinZ,
            SinX * CosY * CosZ - CosX * SinY * SinZ,
            CosX * SinY * CosZ + SinX * CosY * SinZ,
            CosX * CosY * SinZ - SinX * SinY * CosZ,
        };
    }

    Quaternion Quaternion::CreateFromEulerDegZYX(const Vector3f& angles)
    {
        return CreateFromEulerRadZYX(angles * Constants::DegToRad);
    }

    Quaternion::Quaternion()
    {
        (*this) = CreateIdentity();
    }

    Quaternion::Quaternion(float x, float y, float z, float w)
        : m_r(x)
        , m_i(y)
        , m_j(z)
        , m_k(w)
    {
    }

    Vector3f Quaternion::GetEulerRadZYX() const
    {
        static constexpr float epsilon = 1.0e-6f;
        Vector3f result;
        result.m_y =
            std::asin(std::clamp(2.0f * (m_r * m_j - m_i * m_k), -1.0f, 1.0f));

        if (std::abs(std::abs(result.m_y) - Constants::HalfPI) < epsilon)
        {
            result.m_x = 0.0f;
            result.m_z =
                (result.m_y / std::abs(result.m_y)) * -2.0f * std::atan2(m_i, m_r);
        }
        else
        {
            result.m_x = std::atan2(
                2.0f * (m_r * m_i + m_j * m_k),
                m_r * m_r - m_i * m_i - m_j * m_j + m_k * m_k);
            result.m_z = std::atan2(
                2.0f * (m_r * m_k + m_i * m_j),
                m_r * m_r + m_i * m_i - m_j * m_j - m_k * m_k);
        }

        return result;
    }

    Vector3f Quaternion::GetEulerDegZYX() const
    {
        return GetEulerRadZYX() * Constants::RadToDeg;
    }

    Vector3f Quaternion::Rotate(const Vector3f& vector) const
    {
        const Quaternion VectorQuaternion{
            0.0f, vector.m_x, vector.m_y, vector.m_z
        };
        const Quaternion Result = (*this) * VectorQuaternion * GetConjugate();

        return Vector3f{ Result.m_i, Result.m_j, Result.m_k };
    }

    Quaternion Quaternion::GetConjugate() const
    {
        return Quaternion{ m_r, -m_i, -m_j, -m_k };
    }

    Matrix3x4f Quaternion::GetMatrix() const
    {
        return Matrix3x4f::CreateFromRows(
            {
                1 - 2.0f * (m_j * m_j + m_k * m_k),
                2.0f * (m_i * m_j - m_r * m_k),
                2.0f * (m_i * m_k + m_r * m_j),
                0.0f,
            },
            {
                2.0f * (m_i * m_j + m_r * m_k),
                1.0f - 2.0f * (m_i * m_i + m_k * m_k),
                2.0f * (m_j * m_k - m_r * m_i),
                0.0f,
            },
            {
                2.0f * (m_i * m_k - m_r * m_j),
                2.0f * (m_j * m_k + m_r * m_i),
                1.0f - 2.0f * (m_i * m_i + m_j * m_j),
                0.0f,
            });
    }

    bool Quaternion::operator==(const Quaternion& other) const
    {
        return (m_r == other.m_r) && (m_i == other.m_i) && (m_j == other.m_j) &&
            (m_k == other.m_k);
    }

    bool Quaternion::operator!=(const Quaternion& other) const
    {
        return !(*this == other);
    }

    Vector3f Quaternion::operator*(const Vector3f& vector) const
    {
        return Rotate(vector);
    }

    Quaternion Quaternion::operator+(const Quaternion& other) const
    {
        return Quaternion{
            m_r + other.m_r, m_i + other.m_i, m_j + other.m_j, m_k + other.m_k
        };
    }

    Quaternion Quaternion::operator-(const Quaternion& other) const
    {
        return Quaternion{
            m_r - other.m_r, m_i - other.m_i, m_j - other.m_j, m_k - other.m_k
        };
    }

    Quaternion Quaternion::operator*(const Quaternion& other) const
    {
        Quaternion result = *this;
        result.m_r = m_r * other.m_r - m_i * other.m_i - m_j * other.m_j -
            m_k * other.m_k;
        result.m_i = m_r * other.m_i + m_i * other.m_r + m_j * other.m_k -
            m_k * other.m_j;
        result.m_j = m_r * other.m_j - m_i * other.m_k + m_j * other.m_r +
            m_k * other.m_i;
        result.m_k = m_r * other.m_k + m_i * other.m_j - m_j * other.m_i +
            m_k * other.m_r;

        return result;
    }

    Quaternion& Quaternion::operator+=(const Quaternion& other)
    {
        return *this = *this + other;
    }

    Quaternion& Quaternion::operator-=(const Quaternion& other)
    {
        return *this = *this - other;
    }

    Quaternion& Quaternion::operator*=(const Quaternion& other)
    {
        return *this = *this * other;
    }
} // namespace Uni::Math