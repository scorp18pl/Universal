#include <Universal/Algorithm/Noise/PerlinNoiseGenerator2D.h>
#include <array>

namespace Uni::Alg::Noise
{
    PerlinNoiseGenerator2D::PerlinNoiseGenerator2D(
        const Math::Rand::Generator& generator)
        : m_generator{ generator }
    {
    }

    PerlinNoiseGenerator2D::PerlinNoiseGenerator2D(
        PerlinNoiseGenerator2D&& other) noexcept
        : m_generator{ other.m_generator }
        , m_grid{ std::move(other.m_grid) }
    {
    }

    FloatMap2D PerlinNoiseGenerator2D::Generate(
        size_t width, size_t height, float initialFrequency, size_t octaveCount)
    {
        FloatMap2D floatMap{ width, height };

        float weight = 1.0f;
        float weightSum = 0.0f;
        auto cellCount = static_cast<size_t>(1.0f / initialFrequency);
        if (cellCount == 0)
        {
            cellCount = 1;
        }

        for (size_t octave = 0; octave < octaveCount; ++octave)
        {
            m_grid.Resize(cellCount, cellCount);
            m_grid.GenerateVectors(m_generator);

            for (size_t y = 0; y < height; ++y)
            {
                for (size_t x = 0; x < width; ++x)
                {
                    const Math::Vector2f gridPosition{
                        static_cast<float>(x) / static_cast<float>(width) *
                            static_cast<float>(cellCount),
                        static_cast<float>(y) / static_cast<float>(height) *
                            static_cast<float>(cellCount)
                    };

                    floatMap.SetValue(
                        x,
                        y,
                        floatMap.GetValue(x, y) +
                            m_grid.Sample(gridPosition) * weight);
                }
            }

            weightSum += weight;
            weight *= 0.5f;
            cellCount *= 2LU;
        }

        for (size_t y = 0; y < height; ++y)
        {
            for (size_t x = 0; x < width; ++x)
            {
                floatMap.SetValue(x, y, floatMap.GetValue(x, y) / weightSum);
            }
        }

        return floatMap;
    }
} // namespace Uni::Alg::Noise
