#include <gtest/gtest.h>
#include <Universal/Algorithm/Noise/PerlinNoiseGenerator2D.h>

TEST(PerlinNoiseGenerator2DTest, WidthAndHeight)
{
    Uni::Alg::Noise::PerlinNoiseGenerator2D generator;
    Uni::Alg::Noise::FloatMap2D map = generator.Generate(100LU, 100LU, 1.0f, 1LU);

    EXPECT_EQ(map.GetWidth(), 100LU);
    EXPECT_EQ(map.GetHeight(), 100LU);
}

TEST(PerlinNoiseGenerator2DTest, Generate)
{
    Uni::Alg::Noise::PerlinNoiseGenerator2D generator;
    Uni::Alg::Noise::FloatMap2D map = generator.Generate(100LU, 100LU, 1.0f, 1);

    for (size_t y = 0; y < map.GetHeight(); ++y)
    {
        for (size_t x = 0; x < map.GetWidth(); ++x)
        {
            EXPECT_GE(map.GetValue(x, y), -1.0f);
            EXPECT_LE(map.GetValue(x, y), 1.0f);
        }
    }
}
