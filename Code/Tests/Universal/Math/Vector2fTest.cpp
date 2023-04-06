#include <Universal/Math/Random/Generator.h>
#include <Universal/Math/Vector2f.h>
#include <gtest/gtest.h>

namespace Uni::Math
{
    TEST(Vector2fTest, CreateZero)
    {
        Vector2f zero = Vector2f::CreateZero();
        EXPECT_FLOAT_EQ(zero.m_x, 0.0f);
        EXPECT_FLOAT_EQ(zero.m_y, 0.0f);
    }

    TEST(Vector2fTest, CreateFromFloat)
    {
        Vector2f vector = Vector2f::CreateFromFloat(3.0f);
        EXPECT_FLOAT_EQ(vector.m_x, 3.0f);
        EXPECT_FLOAT_EQ(vector.m_y, 3.0f);
    }

    TEST(Vector2fTest, CreateRandomUnitVector)
    {
        Rand::Generator generator;
        Vector2f randomVec = Vector2f::CreateRandomUnitVector(generator);

        float length = randomVec.GetLength();
        EXPECT_FLOAT_EQ(length, 1.0f);
    }

    TEST(Vector2fTest, GetLength)
    {
        Vector2f vector(3.0f, 4.0f);
        EXPECT_FLOAT_EQ(vector.GetLength(), 5.0f);
    }

    TEST(Vector2fTest, GetLengthSquared)
    {
        Vector2f vector(3.0f, 4.0f);
        EXPECT_FLOAT_EQ(vector.GetLengthSquared(), 25.0f);
    }

    TEST(Vector2fTest, GetNormalized)
    {
        Vector2f vector(3.0f, 4.0f);
        Vector2f normalizedVector = vector.GetNormalized();

        float length = normalizedVector.GetLength();
        float epsilon = 1e-4f;
        EXPECT_NEAR(length, 1.0f, epsilon);
    }

    TEST(Vector2fTest, GetMod)
    {
        Vector2f vector1(6.0f, 9.0f);
        Vector2f vector2(4.0f, 5.0f);
        Vector2f modVec = vector1.GetMod(vector2);

        EXPECT_FLOAT_EQ(modVec.m_x, 2.0f);
        EXPECT_FLOAT_EQ(modVec.m_y, 4.0f);
    }

    TEST(Vector2fTest, Dot)
    {
        Vector2f vector1(3.0f, 4.0f);
        Vector2f vector2(2.0f, 3.0f);

        float dotProduct = vector1.Dot(vector2);
        EXPECT_FLOAT_EQ(dotProduct, 18.0f);
    }

    TEST(Vector2fTest, OperatorPlus)
    {
        Vector2f vector1(3.0f, 4.0f);
        Vector2f vector2(2.0f, 3.0f);

        Vector2f sumVec = vector1 + vector2;
        EXPECT_FLOAT_EQ(sumVec.m_x, 5.0f);
        EXPECT_FLOAT_EQ(sumVec.m_y, 7.0f);
    }

    TEST(Vector2fTest, OperatorMinus)
    {
        Vector2f vector1(3.0f, 4.0f);
        Vector2f vector2(2.0f, 3.0f);

        Vector2f diffVec = vector1 - vector2;
        EXPECT_FLOAT_EQ(diffVec.m_x, 1.0f);
        EXPECT_FLOAT_EQ(diffVec.m_y, 1.0f);
    }

    TEST(Vector2fTest, OperatorMultiplyByVector)
    {
        Vector2f vector1(3.0f, 4.0f);
        Vector2f vector2(2.0f, 3.0f);

        Vector2f productVec = vector1 * vector2;
        EXPECT_FLOAT_EQ(productVec.m_x, 6.0f);
        EXPECT_FLOAT_EQ(productVec.m_y, 12.0f);
    }

    TEST(Vector2fTest, OperatorMultiplyByFloat)
    {
        Vector2f vector(3.0f, 4.0f);
        Vector2f productVec = vector * 2.0f;

        EXPECT_FLOAT_EQ(productVec.m_x, 6.0f);
        EXPECT_FLOAT_EQ(productVec.m_y, 8.0f);
    }

    TEST(Vector2fTest, OperatorDivideByVector)
    {
        Vector2f vector1(6.0f, 9.0f);
        Vector2f vector2(2.0f, 3.0f);

        Vector2f quotientVec = vector1 / vector2;
        EXPECT_FLOAT_EQ(quotientVec.m_x, 3.0f);
        EXPECT_FLOAT_EQ(quotientVec.m_y, 3.0f);
    }
} // namespace Uni::Math