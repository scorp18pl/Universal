#include <Universal/Math/Math.h>
#include <Universal/Math/Quaternion.h>
#include <Universal/Math/Vector/Vector3f.h>
#include <Universal/Math/Matrix/Matrix3x4f.h>
#include <gtest/gtest.h>

using namespace Uni::Math;

namespace
{
    const float kTolerance = 1e-6f;

    bool CompareFloat(float a, float b)
    {
        return std::abs(a - b) <= kTolerance;
    }

    TEST(QuaternionTest, CompositionTest)
    {
        Quaternion quaternion = Quaternion::CreateFromAxisRad(
            Uni::Math::Constants::PI / 2.0f, Vector3f::CreateAxisX());
        Quaternion quaternion2 = Quaternion::CreateFromAxisRad(
            Uni::Math::Constants::PI, Vector3f::CreateAxisY());

        Quaternion result = quaternion * quaternion2;
        Vector3f vector = Vector3f::CreateAxisZ();

        Vector3f rotatedVector = result.Rotate(vector);

        EXPECT_TRUE(CompareFloat(rotatedVector.m_x, 0.0f));
        EXPECT_TRUE(CompareFloat(rotatedVector.m_y, 1.0f));
        EXPECT_TRUE(CompareFloat(rotatedVector.m_z, 0.0f));
    }

    TEST(QuaternionTest, FromEulerTest)
    {
        Vector3f euler = {Uni::Math::Constants::PI / 4.0f,
                           Uni::Math::Constants::PI / 3.0f,
                           Uni::Math::Constants::PI / 2.0f};

        Quaternion quaternion = Quaternion::CreateFromEulerRadZYX(euler);

        Vector3f returnedEuler = quaternion.GetEulerRadZYX();

        EXPECT_TRUE(CompareFloat(returnedEuler.m_x, euler.m_x));
        EXPECT_TRUE(CompareFloat(returnedEuler.m_y, euler.m_y));
        EXPECT_TRUE(CompareFloat(returnedEuler.m_z, euler.m_z));
    }

    TEST(QuaternionTest, ComparisonTest)
    {
        Quaternion q1 = Quaternion(1.0f, 2.0f, 3.0f, 4.0f);
        Quaternion q2 = Quaternion(1.0f, 2.0f, 3.0f, 4.0f);
        Quaternion q3 = Quaternion(1.0f, 2.0f, 3.0f, 5.0f);

        EXPECT_TRUE(q1 == q2);
        EXPECT_FALSE(q1 != q2);
        EXPECT_FALSE(q1 == q3);
        EXPECT_TRUE(q1 != q3);
    }

    TEST(QuaternionTest, MatrixTest)
    {
        Quaternion quaternion = Quaternion::CreateFromAxisRad(
            Uni::Math::Constants::PI / 2.0f, Vector3f::CreateAxisX());

        Matrix3x4f matrix = quaternion.GetMatrix();

        Vector3f vector = Vector3f::CreateAxisZ();

        Vector3f rotatedVector = matrix * vector;

        EXPECT_TRUE(CompareFloat(rotatedVector.m_x, 0.0f));
        EXPECT_TRUE(CompareFloat(rotatedVector.m_y, -1.0f));
        EXPECT_TRUE(CompareFloat(rotatedVector.m_z, 0.0f));
    }
} // namespace