#include <Universal/Algorithm/Noise/VectorGrid2D.h>
#include <Universal/Math/Random/Generator.h>
#include <gtest/gtest.h>

namespace Uni::Alg::Noise
{

    class VectorGrid2DTest : public testing::Test
    {
    protected:
        void SetUp() override
        {
            generator = Math::Rand::Generator(
                12345); // Fixed seed for deterministic tests
        }

        Math::Rand::Generator generator;
    };

    TEST_F(VectorGrid2DTest, Initialization)
    {
        VectorGrid2D grid(5, 5);

        EXPECT_EQ(grid.GetCellCountX(), 5);
        EXPECT_EQ(grid.GetCellCountY(), 5);
    }

    TEST_F(VectorGrid2DTest, Resize)
    {
        VectorGrid2D grid(5, 5);

        grid.Resize(10, 10);

        EXPECT_EQ(grid.GetCellCountX(), 10);
        EXPECT_EQ(grid.GetCellCountY(), 10);
    }

    TEST_F(VectorGrid2DTest, GenerateVectorsAndSample)
    {
        VectorGrid2D grid(5, 5);

        grid.GenerateVectors(generator);

        const size_t sampleCountX = 1000;
        const size_t sampleCountY = sampleCountX;
        for (size_t x = 0; x < sampleCountX; ++x)
        {
            for (size_t y = 0; y < sampleCountY; ++y)
            {
                Math::Vector2f gridPosition{
                    static_cast<float>(x) / static_cast<float>(sampleCountX) *
                        static_cast<float>(grid.GetCellCountX()),
                    static_cast<float>(y) / static_cast<float>(sampleCountY) *
                        static_cast<float>(grid.GetCellCountY())
                };

                float sampleValue = grid.Sample(gridPosition);

                float epsilon = 1e-4f;
                EXPECT_GE(sampleValue, -1.0f - epsilon);
                EXPECT_LE(sampleValue, 1.0f + epsilon);
            }
        }
    }

} // namespace Uni::Alg::Noise