#pragma once

#include <random>

namespace Uni::Math::Rand
{
    using SeedType = unsigned long long;

    class Generator
    {
    public:
        Generator() = default;
        explicit Generator(SeedType seed);
        Generator(const Generator& other) = default;
        Generator(Generator&& other) noexcept = default;
        ~Generator() = default;

        [[nodiscard]] SeedType GetSeed() const;

        void SetSeed(SeedType seed);
        void SetRandomSeed();

        float GenerateInRange(float min = 0.0f, float max = 1.0f);
        int GenerateInRange(int min, int max);
        float GenerateGaussian(float mean, float stddev);

        Generator& operator=(const Generator& other) = default;

    private:
        bool m_isSeedUsed{ false };
        SeedType m_seed{ 0UL };
        std::mt19937 m_generator;
    };
} // namespace Uni::Math::Rand
