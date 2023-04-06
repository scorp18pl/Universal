#include <Universal/Math/Math.h>
#include <gtest/gtest.h>

namespace Uni::Math
{
    TEST(MathTest, FMod)
    {
        EXPECT_FLOAT_EQ(Math::FMod(0.0f, 1.0f), 0.0f);
        EXPECT_FLOAT_EQ(Math::FMod(1.0f, 1.0f), 0.0f);
        EXPECT_FLOAT_EQ(Math::FMod(2.0f, 1.0f), 0.0f);
        EXPECT_FLOAT_EQ(Math::FMod(3.0f, 1.0f), 0.0f);
        EXPECT_FLOAT_EQ(Math::FMod(4.0f, 1.0f), 0.0f);
        EXPECT_FLOAT_EQ(Math::FMod(5.0f, 1.0f), 0.0f);

        EXPECT_FLOAT_EQ(Math::FMod(-0.0f, 1.0f), 0.0f);
        EXPECT_FLOAT_EQ(Math::FMod(-1.0f, 1.0f), 0.0f);
        EXPECT_FLOAT_EQ(Math::FMod(-2.0f, 1.0f), 0.0f);
        EXPECT_FLOAT_EQ(Math::FMod(-3.0f, 1.0f), 0.0f);
        EXPECT_FLOAT_EQ(Math::FMod(-4.0f, 1.0f), 0.0f);
        EXPECT_FLOAT_EQ(Math::FMod(-5.0f, 1.0f), 0.0f);

        EXPECT_FLOAT_EQ(Math::FMod(0.0f, -1.0f), 0.0f);
        EXPECT_FLOAT_EQ(Math::FMod(1.0f, -1.0f), 0.0f);
        EXPECT_FLOAT_EQ(Math::FMod(2.0f, -1.0f), 0.0f);
        EXPECT_FLOAT_EQ(Math::FMod(3.0f, -1.0f), 0.0f);
        EXPECT_FLOAT_EQ(Math::FMod(4.0f, -1.0f), 0.0f);
        EXPECT_FLOAT_EQ(Math::FMod(5.0f, -1.0f), 0.0f);

        EXPECT_FLOAT_EQ(Math::FMod(-0.0f, -1.0f), 0.0f);
        EXPECT_FLOAT_EQ(Math::FMod(-1.0f, -1.0f), 0.0f);
        EXPECT_FLOAT_EQ(Math::FMod(-2.0f, -1.0f), 0.0f);
        EXPECT_FLOAT_EQ(Math::FMod(-3.0f, -1.0f), 0.0f);
        EXPECT_FLOAT_EQ(Math::FMod(-4.0f, -1.0f), 0.0f);
        EXPECT_FLOAT_EQ(Math::FMod(-5.0f, -1.0f), 0.0f);

        EXPECT_FLOAT_EQ(Math::FMod(0.0f, 1.5f), 0.0f);
        EXPECT_FLOAT_EQ(Math::FMod(1.0f, 1.5f), 1.0f);
        EXPECT_FLOAT_EQ(Math::FMod(2.0f, 1.5f), 0.5f);
        EXPECT_FLOAT_EQ(Math::FMod(3.0f, 1.5f), 0.0f);
    }
} // namespace Uni::Math