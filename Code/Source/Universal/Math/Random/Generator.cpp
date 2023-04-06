#include <Universal/Math/Random/Generator.h>

namespace Uni::Math::Rand
{
    Generator::Generator(SeedType seed)
    {
        SetSeed(seed);
    }

    SeedType Generator::GetSeed() const
    {
        return m_seed;
    }

    void Generator::SetRandomSeed()
    {
        std::random_device randomDevice;
        m_generator.seed(randomDevice());
    }

    void Generator::SetSeed(SeedType seed)
    {
        m_seed = seed;
        m_generator.seed(seed);
        m_isSeedUsed = false;
    }

    float Generator::GenerateInRange(float min, float max)
    {
        static std::uniform_real_distribution<float> distribution;
        distribution = std::uniform_real_distribution<float>{ min, max };

        return distribution(m_generator);
    }

    int Generator::GenerateInRange(int min, int max)
    {
        static std::uniform_int_distribution<int> distribution;
        distribution = std::uniform_int_distribution<int>{ min, max };
        return distribution(m_generator);
    }

    float Generator::GenerateGaussian(float mean, float stddev)
    {
        static std::normal_distribution<float> distribution;
        distribution = std::normal_distribution<float>{ mean, stddev };
        return distribution(m_generator);
    }
} // namespace Uni::Math::Rand
