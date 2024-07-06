#include <Universal/Math/Aabb2D.h>
#include <gtest/gtest.h>

namespace Uni::Math
{
    TEST(Aabb2DTest, CreateFromPoints)
    {
        Aabb2D boundingBox = Aabb2D::CreateFromPoints({
            { 0.0f, 0.0f },
            { 1.0f, 1.0f },
            { 2.0f, 2.0f },
            { 3.0f, 3.0f },
            { 4.0f, 4.0f },
        });

        EXPECT_EQ(boundingBox.GetMinPoint(), Uni::Math::Vector2f(0.0f, 0.0f));
        EXPECT_EQ(boundingBox.GetMaxPoint(), Uni::Math::Vector2f(4.0f, 4.0f));
    }

    TEST(Aabb2DTest, CreateFromDimensions)
    {
        Aabb2D boundingBox =
            Aabb2D::CreateFromDimensions({ 1.0f, 1.0f }, { 4.0f, 4.0f });

        EXPECT_EQ(boundingBox.GetMinPoint(), Uni::Math::Vector2f(1.0f, 1.0f));
        EXPECT_EQ(boundingBox.GetMaxPoint(), Uni::Math::Vector2f(5.0f, 5.0f));
    }

    TEST(Aabb2DTest, IsPointWithinBounds)
    {
        Aabb2D boundingBox =
            Aabb2D::CreateFromDimensions({ 1.0f, 1.0f }, { 4.0f, 4.0f });

        EXPECT_TRUE(boundingBox.IsPointWithinBounds({ 2.0f, 2.0f }));
        EXPECT_FALSE(boundingBox.IsPointWithinBounds({ 0.0f, 0.0f }));
    }

    TEST(Aabb2DTest, GetDimensions)
    {
        Aabb2D boundingBox =
            Aabb2D::CreateFromDimensions({ 1.0f, 1.0f }, { 4.0f, 4.0f });

        EXPECT_EQ(boundingBox.GetDimensions(), Uni::Math::Vector2f(4.0f, 4.0f));
    }

    TEST(Aabb2DTest, GetMinPoint)
    {
        Aabb2D boundingBox =
            Aabb2D::CreateFromDimensions({ 1.0f, 1.0f }, { 4.0f, 4.0f });

        EXPECT_EQ(boundingBox.GetMinPoint(), Uni::Math::Vector2f(1.0f, 1.0f));
    }

    TEST(Aabb2DTest, GetMaxPoint)
    {
        Aabb2D boundingBox =
            Aabb2D::CreateFromDimensions({ 1.0f, 1.0f }, { 4.0f, 4.0f });

        EXPECT_EQ(boundingBox.GetMaxPoint(), Uni::Math::Vector2f(5.0f, 5.0f));
    }

    TEST(Aabb2DTest, IsValid)
    {
        Aabb2D boundingBox =
            Aabb2D::CreateFromDimensions({ 1.0f, 1.0f }, { 4.0f, 4.0f });

        EXPECT_TRUE(boundingBox.IsValid());
        EXPECT_FALSE(Aabb2D::CreateInvalid().IsValid());
        EXPECT_FALSE(Aabb2D().IsValid());
        EXPECT_FALSE(Aabb2D({ 1.0f, 1.0f }, { 0.0f, 0.0f }).IsValid());
    }
} // namespace Uni::Math
