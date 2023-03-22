#include <Math/Random.h>

#include <random>

namespace Uni::Math::Rand
{
    float CreateRandomUniformFloat(float min, float max)
    {
        std::random_device random_device;
        std::mt19937 gen(random_device());
        std::uniform_real_distribution<> distribution(min, max);
        return static_cast<float>(distribution(gen));
    }

    float CreateRandomGaussianFloat(float mean, float stddev)
    {
        std::random_device random_device;
        std::mt19937 gen(random_device());
        std::normal_distribution<> distribution(mean, stddev);
        return static_cast<float>(distribution(gen));
    }
} // namespace Uni::Math::Rand