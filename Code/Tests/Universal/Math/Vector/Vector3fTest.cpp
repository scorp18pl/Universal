#include <Universal/Math/Random/Generator.h>
#include <Universal/Math/Vector/Vector3f.h>
#include <gtest/gtest.h>

TEST(Vector3fTest, CreateZero)
{
    Uni::Math::Vector3f vector = Uni::Math::Vector3f::CreateZero();

    EXPECT_EQ(vector.m_x, 0.0f);
    EXPECT_EQ(vector.m_y, 0.0f);
    EXPECT_EQ(vector.m_z, 0.0f);
}

TEST(Vector3fTest, CreateFromFloat)
{
    Uni::Math::Vector3f vector = Uni::Math::Vector3f::CreateFromFloat(1.0f);

    EXPECT_EQ(vector.m_x, 1.0f);
    EXPECT_EQ(vector.m_y, 1.0f);
    EXPECT_EQ(vector.m_z, 1.0f);
}

TEST(Vector3fTest, CreateRandomUnitVector)
{
    Uni::Math::Rand::Generator generator;
    Uni::Math::Vector3f vector =
        Uni::Math::Vector3f::CreateRandomUnitVector(generator);

    EXPECT_GE(vector.GetLength(), 0.0f);
    EXPECT_LE(vector.GetLength(), 1.0f);
}

TEST(Vector3fTest, GetLengthSquared)
{
    Uni::Math::Vector3f vector = { 1.0f, 2.0f, 3.0f };

    EXPECT_EQ(vector.GetLengthSquared(), 14.0f);
}

TEST(Vector3fTest, GetLength)
{
    Uni::Math::Vector3f vector = { 1.0f, 2.0f, 3.0f };

    EXPECT_EQ(vector.GetLength(), std::sqrt(14.0f));
}

TEST(Vector3fTest, GetNormalized)
{
    Uni::Math::Vector3f vector = { 1.0f, 2.0f, 3.0f };
    Uni::Math::Vector3f normalizedVector = vector.GetNormalized();

    float length = normalizedVector.GetLength();
    float epsilon = 1e-4f;
    EXPECT_NEAR(length, 1.0f, epsilon);
}

TEST(Vector3fTest, DotProduct)
{
    Uni::Math::Vector3f vector1 = { 1.0f, 2.0f, 3.0f };
    Uni::Math::Vector3f vector2 = { 4.0f, 5.0f, 6.0f };

    EXPECT_EQ(vector1.DotProduct(vector2), 32.0f);
}

TEST(Vector3fTest, CrossProduct)
{
    Uni::Math::Vector3f vector1 = { 1.0f, 2.0f, 3.0f };
    Uni::Math::Vector3f vector2 = { 4.0f, 5.0f, 6.0f };
    Uni::Math::Vector3f crossProduct = vector1.CrossProduct(vector2);

    EXPECT_EQ(crossProduct.m_x, -3.0f);
    EXPECT_EQ(crossProduct.m_y, 6.0f);
    EXPECT_EQ(crossProduct.m_z, -3.0f);
}

TEST(Vector3fTest, OperatorPlus)
{
    Uni::Math::Vector3f vector1 = { 1.0f, 2.0f, 3.0f };
    Uni::Math::Vector3f vector2 = { 4.0f, 5.0f, 6.0f };
    Uni::Math::Vector3f sum = vector1 + vector2;

    EXPECT_EQ(sum.m_x, 5.0f);
    EXPECT_EQ(sum.m_y, 7.0f);
    EXPECT_EQ(sum.m_z, 9.0f);
}

TEST(Vector3fTest, OperatorMinus)
{
    Uni::Math::Vector3f vector1 = { 1.0f, 2.0f, 3.0f };
    Uni::Math::Vector3f vector2 = { 4.0f, 5.0f, 6.0f };
    Uni::Math::Vector3f difference = vector1 - vector2;

    EXPECT_EQ(difference.m_x, -3.0f);
    EXPECT_EQ(difference.m_y, -3.0f);
    EXPECT_EQ(difference.m_z, -3.0f);
}

TEST(Vector3fTest, OperatorMultiplyByFloat)
{
    Uni::Math::Vector3f vector = { 1.0f, 2.0f, 3.0f };
    Uni::Math::Vector3f product = vector * 2.0f;

    EXPECT_EQ(product.m_x, 2.0f);
    EXPECT_EQ(product.m_y, 4.0f);
    EXPECT_EQ(product.m_z, 6.0f);
}

TEST(Vector3fTest, OperatorMultiplyByVector)
{
    Uni::Math::Vector3f vector1 = { 1.0f, 2.0f, 3.0f };
    Uni::Math::Vector3f vector2 = { 4.0f, 5.0f, 6.0f };
    Uni::Math::Vector3f product = vector1 * vector2;

    EXPECT_EQ(product.m_x, 4.0f);
    EXPECT_EQ(product.m_y, 10.0f);
    EXPECT_EQ(product.m_z, 18.0f);
}

TEST(Vector3fTest, OperatorDivide)
{
    Uni::Math::Vector3f vector = { 1.0f, 2.0f, 3.0f };
    Uni::Math::Vector3f quotient = vector / 2.0f;

    EXPECT_EQ(quotient.m_x, 0.5f);
    EXPECT_EQ(quotient.m_y, 1.0f);
    EXPECT_EQ(quotient.m_z, 1.5f);
}

TEST(Vector3fTest, OperatorPlusEqual)
{
    Uni::Math::Vector3f vector1 = { 1.0f, 2.0f, 3.0f };
    Uni::Math::Vector3f vector2 = { 4.0f, 5.0f, 6.0f };
    vector1 += vector2;

    EXPECT_EQ(vector1.m_x, 5.0f);
    EXPECT_EQ(vector1.m_y, 7.0f);
    EXPECT_EQ(vector1.m_z, 9.0f);
}

TEST(Vector3fTest, OperatorMinusEqual)
{
    Uni::Math::Vector3f vector1 = { 1.0f, 2.0f, 3.0f };
    Uni::Math::Vector3f vector2 = { 4.0f, 5.0f, 6.0f };
    vector1 -= vector2;

    EXPECT_EQ(vector1.m_x, -3.0f);
    EXPECT_EQ(vector1.m_y, -3.0f);
    EXPECT_EQ(vector1.m_z, -3.0f);
}

TEST(Vector3fTest, OperatorMultiplyEqual)
{
    Uni::Math::Vector3f vector = { 1.0f, 2.0f, 3.0f };
    vector *= 2.0f;

    EXPECT_EQ(vector.m_x, 2.0f);
    EXPECT_EQ(vector.m_y, 4.0f);
    EXPECT_EQ(vector.m_z, 6.0f);
}

TEST(Vector3fTest, OperatorDivideEqual)
{
    Uni::Math::Vector3f vector = { 1.0f, 2.0f, 3.0f };
    vector /= 2.0f;

    EXPECT_EQ(vector.m_x, 0.5f);
    EXPECT_EQ(vector.m_y, 1.0f);
    EXPECT_EQ(vector.m_z, 1.5f);
}

TEST(Vector3fTest, OperatorEqual)
{
    Uni::Math::Vector3f vector1 = { 1.0f, 2.0f, 3.0f };
    Uni::Math::Vector3f vector2 = { 1.0f, 2.0f, 3.0f };

    EXPECT_TRUE(vector1 == vector2);
}

TEST(Vector3fTest, OperatorNotEqual)
{
    Uni::Math::Vector3f vector1 = { 1.0f, 2.0f, 3.0f };
    Uni::Math::Vector3f vector2 = { 4.0f, 5.0f, 6.0f };

    EXPECT_TRUE(vector1 != vector2);
}
