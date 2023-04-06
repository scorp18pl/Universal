#include <Universal/Math/Random/Generator.h>
#include <gtest/gtest.h>

namespace Uni::Math::Rand
{
    TEST(GeneratorTest, Seed)
    {
        Generator generator1;
        generator1.SetSeed(0);
        Generator generator2;
        generator2.SetSeed(0);

        for (int i = 0; i < 100; ++i)
        {
            EXPECT_EQ(generator1.GenerateInRange(), generator2.GenerateInRange());
        }
    }
} // namespace Uni::Math::Rand
