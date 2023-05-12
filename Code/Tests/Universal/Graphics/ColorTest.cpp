#include <Universal/Graphics/Color.h>
#include <gtest/gtest.h>

TEST(ColorTest, CreateFromFloats)
{
    Uni::Grpx::Color color =
        Uni::Grpx::Color::CreateFromFloats(0.5f, 0.5f, 0.5f, 0.5f);
    EXPECT_EQ(color.GetRed(), 0.5f);
    EXPECT_EQ(color.GetGreed(), 0.5f);
    EXPECT_EQ(color.GetBlue(), 0.5f);
    EXPECT_EQ(color.GetAlpha(), 0.5f);
}

TEST(ColorTest, CreateFromUint8)
{
    const float Epsilon = 1.0e-2f;

    Uni::Grpx::Color color =
        Uni::Grpx::Color::CreateFromUint8(128, 128, 128, 128);
    EXPECT_NEAR(color.GetRed(), 0.5f, Epsilon);
    EXPECT_NEAR(color.GetGreed(), 0.5f, Epsilon);
    EXPECT_NEAR(color.GetBlue(), 0.5f, Epsilon);
    EXPECT_NEAR(color.GetAlpha(), 0.5f, Epsilon);
}

TEST(ColorTest, CreateFromVector3f)
{
    Uni::Math::Vector3f vector(0.5f, 0.5f, 0.5f);
    Uni::Grpx::Color color = Uni::Grpx::Color::CreateFromVector3f(vector, 0.5f);
    EXPECT_EQ(color.GetRed(), 0.5f);
    EXPECT_EQ(color.GetGreed(), 0.5f);
    EXPECT_EQ(color.GetBlue(), 0.5f);
    EXPECT_EQ(color.GetAlpha(), 0.5f);
}

TEST(ColorTest, CreateFromVector4f)
{
    Uni::Math::Vector4f vector(0.5f, 0.5f, 0.5f, 0.5f);
    Uni::Grpx::Color color = Uni::Grpx::Color::CreateFromVector4f(vector);
    EXPECT_EQ(color.GetRed(), 0.5f);
    EXPECT_EQ(color.GetGreed(), 0.5f);
    EXPECT_EQ(color.GetBlue(), 0.5f);
    EXPECT_EQ(color.GetAlpha(), 0.5f);
}

TEST(ColorTest, Constructors)
{
    Uni::Grpx::Color color1(0.5f, 0.5f, 0.5f, 0.5f);
    EXPECT_EQ(color1.GetRed(), 0.5f);
    EXPECT_EQ(color1.GetGreed(), 0.5f);
    EXPECT_EQ(color1.GetBlue(), 0.5f);
    EXPECT_EQ(color1.GetAlpha(), 0.5f);

    Uni::Grpx::Color color2 =
        Uni::Grpx::Color::CreateFromFloats(0.5f, 0.5f, 0.5f, 0.5f);
    EXPECT_EQ(color2.GetRed(), 0.5f);
    EXPECT_EQ(color2.GetGreed(), 0.5f);
    EXPECT_EQ(color2.GetBlue(), 0.5f);
    EXPECT_EQ(color2.GetAlpha(), 0.5f);
}