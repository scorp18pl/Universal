#include <Universal/Math/BoundingBox2D.h>
#include <gtest/gtest.h>

namespace Uni::Math
{
    TEST(BoundingBox2DTest, CreateFromPoints)
    {
        BoundingBox2D boundingBox = BoundingBox2D::CreateFromPoints({
            { 0.0f, 0.0f },
            { 1.0f, 1.0f },
            { 2.0f, 2.0f },
            { 3.0f, 3.0f },
            { 4.0f, 4.0f },
        });

        EXPECT_EQ(boundingBox.GetMinPoint(), Uni::Math::Vector2f(0.0f, 0.0f));
        EXPECT_EQ(boundingBox.GetMaxPoint(), Uni::Math::Vector2f(4.0f, 4.0f));
    }

    TEST(BoundingBox2DTest, CreateFromDimensions)
    {
        BoundingBox2D boundingBox =
            BoundingBox2D::CreateFromDimensions({ 1.0f, 1.0f }, { 4.0f, 4.0f });

        EXPECT_EQ(boundingBox.GetMinPoint(), Uni::Math::Vector2f(1.0f, 1.0f));
        EXPECT_EQ(boundingBox.GetMaxPoint(), Uni::Math::Vector2f(5.0f, 5.0f));
    }

    TEST(BoundingBox2DTest, IsPointWithinBounds)
    {
        BoundingBox2D boundingBox =
            BoundingBox2D::CreateFromDimensions({ 1.0f, 1.0f }, { 4.0f, 4.0f });

        EXPECT_TRUE(boundingBox.IsPointWithinBounds({ 2.0f, 2.0f }));
        EXPECT_FALSE(boundingBox.IsPointWithinBounds({ 0.0f, 0.0f }));
    }

    TEST(BoundingBox2DTest, GetDimensions)
    {
        BoundingBox2D boundingBox =
            BoundingBox2D::CreateFromDimensions({ 1.0f, 1.0f }, { 4.0f, 4.0f });

        EXPECT_EQ(boundingBox.GetDimensions(), Uni::Math::Vector2f(4.0f, 4.0f));
    }

    TEST(BoundingBox2DTest, GetMinPoint)
    {
        BoundingBox2D boundingBox =
            BoundingBox2D::CreateFromDimensions({ 1.0f, 1.0f }, { 4.0f, 4.0f });

        EXPECT_EQ(boundingBox.GetMinPoint(), Uni::Math::Vector2f(1.0f, 1.0f));
    }

    TEST(BoundingBox2DTest, GetMaxPoint)
    {
        BoundingBox2D boundingBox =
            BoundingBox2D::CreateFromDimensions({ 1.0f, 1.0f }, { 4.0f, 4.0f });

        EXPECT_EQ(boundingBox.GetMaxPoint(), Uni::Math::Vector2f(5.0f, 5.0f));
    }

    TEST(BoundingBox2DTest, IsValid)
    {
        BoundingBox2D boundingBox =
            BoundingBox2D::CreateFromDimensions({ 1.0f, 1.0f }, { 4.0f, 4.0f });

        EXPECT_TRUE(boundingBox.IsValid());
        EXPECT_FALSE(BoundingBox2D::CreateInvalid().IsValid());
        EXPECT_FALSE(BoundingBox2D().IsValid());
        EXPECT_FALSE(BoundingBox2D({ 1.0f, 1.0f }, { 0.0f, 0.0f }).IsValid());
    }
} // namespace Uni::Math
