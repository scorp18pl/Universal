#include <Universal/Math/Math.h>
#include <Universal/Math/Matrix/Matrix2x3f.h>
#include <gtest/gtest.h>
#include <valarray>

namespace Uni::Math
{
    constexpr float kTolerance = 1e-6f;

    TEST(Matrix2x3fTest, CreateIdentity)
    {
        Matrix2x3f identity = Matrix2x3f::CreateIdentity();
        EXPECT_NEAR(identity(0, 0), 1.0f, kTolerance);
        EXPECT_NEAR(identity(0, 1), 0.0f, kTolerance);
        EXPECT_NEAR(identity(0, 2), 0.0f, kTolerance);
        EXPECT_NEAR(identity(1, 0), 0.0f, kTolerance);
        EXPECT_NEAR(identity(1, 1), 1.0f, kTolerance);
        EXPECT_NEAR(identity(1, 2), 0.0f, kTolerance);
    }

    TEST(Matrix2x3fTest, CreateFromTranslation)
    {
        Vector2f translation(2.0f, 3.0f);
        Matrix2x3f matrix = Matrix2x3f::CreateFromTranslation(translation);
        // Test matrix elements
        Vector2f result = matrix * Vector2f(1.0f, 1.0f);
        EXPECT_NEAR(result.m_x, 3.0f, kTolerance);
        EXPECT_NEAR(result.m_y, 4.0f, kTolerance);
    }

    TEST(Matrix2x3fTest, CreateFromRotationRadians)
    {
        float angle = Constants::PI / 4.0f;
        Matrix2x3f matrix = Matrix2x3f::CreateFromRotationRadians(angle);
        // Test matrix elements
        Vector2f result = matrix * Vector2f(1.0f, 1.0f);
        EXPECT_NEAR(result.m_x, 0.0f, kTolerance);
        EXPECT_NEAR(result.m_y, std::sqrt(2.0f), kTolerance);
    }

    TEST(Matrix2x3fTest, CreateFromRotationDegrees)
    {
        float angle = 45.0f;
        Matrix2x3f matrix = Matrix2x3f::CreateFromRotationDegrees(angle);
        // Test matrix elements
        Vector2f result = matrix * Vector2f(1.0f, 1.0f);
        EXPECT_NEAR(result.m_x, 0.0f, kTolerance);
        EXPECT_NEAR(result.m_y, std::sqrt(2.0f), kTolerance);
    }

    TEST(Matrix2x3fTest, CreateFromScale)
    {
        Vector2f scale(2.0f, 3.0f);
        Matrix2x3f matrix = Matrix2x3f::CreateFromScale(scale);
        // Test matrix elements
        Vector2f result = matrix * Vector2f(1.0f, 1.0f);
        EXPECT_NEAR(result.m_x, 2.0f, kTolerance);
        EXPECT_NEAR(result.m_y, 3.0f, kTolerance);
    }

    TEST(Matrix2x3fTest, CreateFromRowMajorFloats)
    {
        float values[6] = { 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f };
        Matrix2x3f matrix = Matrix2x3f::CreateFromRowMajorFloats(values);
        // Test matrix elements
        EXPECT_EQ(matrix(0, 0), 1.0f);
        EXPECT_EQ(matrix(0, 1), 2.0f);
        EXPECT_EQ(matrix(0, 2), 3.0f);
        EXPECT_EQ(matrix(1, 0), 4.0f);
        EXPECT_EQ(matrix(1, 1), 5.0f);
        EXPECT_EQ(matrix(1, 2), 6.0f);
    }

    TEST(Matrix2x3fTest, OperatorMultiplyMatrix)
    {
        Matrix2x3f matrix1 =
            Matrix2x3f::CreateFromTranslation(Vector2f(1.0f, 2.0f));
        Matrix2x3f matrix2 = Matrix2x3f::CreateFromRotationDegrees(90.0f);
        Matrix2x3f result = matrix1 * matrix2;
        // Test result matrix
        Vector2f vector = result * Vector2f(1.0f, 1.0f);
        EXPECT_NEAR(vector.m_x, 0.0f, kTolerance);
        EXPECT_NEAR(vector.m_y, 3.0f, kTolerance);
    }

    TEST(Matrix2x3fTest, OperatorMultiplyAssignMatrix)
    {
        Matrix2x3f matrix1 =
            Matrix2x3f::CreateFromTranslation(Vector2f(1.0f, 2.0f));
        Matrix2x3f matrix2 = Matrix2x3f::CreateFromRotationDegrees(90.0f);
        matrix1 *= matrix2;
        // Test matrix1
        Vector2f vector = matrix1 * Vector2f(1.0f, 1.0f);
        EXPECT_NEAR(vector.m_x, 0.0f, kTolerance);
        EXPECT_NEAR(vector.m_y, 3.0f, kTolerance);
    }
} // namespace Uni::Math