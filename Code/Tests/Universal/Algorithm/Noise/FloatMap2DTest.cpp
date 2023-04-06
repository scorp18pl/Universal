#include <gtest/gtest.h>
#include <Universal/Algorithm/Noise/FloatMap2D.h>

namespace Uni::Alg::Noise
{
    TEST(FloatMap2DTest, Constructor)
    {
        FloatMap2D map{ 10LU, 20LU };

        EXPECT_EQ(map.GetWidth(), 10LU);
        EXPECT_EQ(map.GetHeight(), 20LU);
    }

    TEST(FloatMap2DTest, MoveConstructor)
    {
        FloatMap2D map{ 10LU, 20LU };

        FloatMap2D map2{ std::move(map) };

        EXPECT_EQ(map2.GetWidth(), 10LU);
        EXPECT_EQ(map2.GetHeight(), 20LU);
    }

    TEST(FloatMap2DTest, SetValueGetValue) {
        Uni::Alg::Noise::FloatMap2D map(3, 3);

        map.SetValue(1, 1, 0.5f);
        map.SetValue(2, 2, -0.5f);

        EXPECT_FLOAT_EQ(map.GetValue(1, 1), 0.5f);
        EXPECT_FLOAT_EQ(map.GetValue(2, 2), -0.5f);
    }

    TEST(FloatMap2DTest, ToBitMap) {
        Uni::Alg::Noise::FloatMap2D map(2, 2);

        map.SetValue(0, 0, -1.0f);
        map.SetValue(1, 0, 1.0f);
        map.SetValue(0, 1, 0.0f);
        map.SetValue(1, 1, 0.5f);

        Uni::Grpx::Bitmap bitmap = map.ToBitMap();

        ASSERT_EQ(bitmap.GetWidth(), 2);
        ASSERT_EQ(bitmap.GetHeight(), 2);

        EXPECT_EQ(bitmap.GetData()[0], 0);
        EXPECT_EQ(bitmap.GetData()[1], 255);
        EXPECT_EQ(bitmap.GetData()[2], 127);
        EXPECT_EQ(bitmap.GetData()[3], 191);
    }
} // namespace Uni::Alg::Noise