#include <Universal/Math/Vector/Vector4f.h>
#include <cmath>
#include <gtest/gtest.h>

using Uni::Math::Vector4f;

TEST(Vector4fTest, CreateZero) {
    Vector4f zero = Vector4f::CreateZero();
    EXPECT_FLOAT_EQ(zero.m_x, 0.0f);
    EXPECT_FLOAT_EQ(zero.m_y, 0.0f);
    EXPECT_FLOAT_EQ(zero.m_z, 0.0f);
    EXPECT_FLOAT_EQ(zero.m_w, 0.0f);
}

TEST(Vector4fTest, CreateFromFloat) {
    float value = 3.0f;
    Vector4f vector = Vector4f{value};
    EXPECT_FLOAT_EQ(vector.m_x, value);
    EXPECT_FLOAT_EQ(vector.m_y, value);
    EXPECT_FLOAT_EQ(vector.m_z, value);
    EXPECT_FLOAT_EQ(vector.m_w, value);
}

TEST(Vector4fTest, GetLength) {
    Vector4f vector(1.0f, 2.0f, 3.0f, 4.0f);
    float length = vector.GetLength();
    EXPECT_FLOAT_EQ(length, std::sqrt(30.0f));
}

TEST(Vector4fTest, GetNormalized) {
    Vector4f vector(1.0f, 2.0f, 3.0f, 4.0f);
    Vector4f normalized = vector.GetNormalized();

    float length = normalized.GetLength();
    float epsilon = 1e-4f;
    EXPECT_NEAR(length, 1.0f, epsilon);
}

TEST(Vector4fTest, DotProduct) {
    Vector4f v1(1.0f, 2.0f, 3.0f, 4.0f);
    Vector4f v2(5.0f, 6.0f, 7.0f, 8.0f);
    float dot = v1.DotProduct(v2);
    EXPECT_FLOAT_EQ(dot, 70.0f);
}

TEST(Vector4fTest, OperatorEquals) {
    Vector4f v1(1.0f, 2.0f, 3.0f, 4.0f);
    Vector4f v2(1.0f, 2.0f, 3.0f, 4.0f);
    EXPECT_TRUE(v1 == v2);
}

TEST(Vector4fTest, OperatorNotEquals) {
    Vector4f v1(1.0f, 2.0f, 3.0f, 4.0f);
    Vector4f v2(5.0f, 6.0f, 7.0f, 8.0f);
    EXPECT_TRUE(v1 != v2);
}
