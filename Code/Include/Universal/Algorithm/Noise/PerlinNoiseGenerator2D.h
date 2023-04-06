#pragma once

#include <Universal/Algorithm/Noise/FloatMap2D.h>
#include <Universal/Algorithm/Noise/VectorGrid2D.h>
#include <Universal/Graphics/Bitmap.h>
#include <Universal/Math/Random/Generator.h>

namespace Uni::Alg::Noise
{
    class PerlinNoiseGenerator2D
    {
    public:
        explicit PerlinNoiseGenerator2D(
            const Math::Rand::Generator& generator = Math::Rand::Generator{0LU});
        PerlinNoiseGenerator2D(const PerlinNoiseGenerator2D& other) = default;
        PerlinNoiseGenerator2D(PerlinNoiseGenerator2D&& other) noexcept;
        ~PerlinNoiseGenerator2D() = default;

        FloatMap2D Generate(
            size_t width,
            size_t height,
            float initialFrequency = 1.0f,
            size_t octaveCount = 1LU);

    private:
        Math::Rand::Generator m_generator;
        VectorGrid2D m_grid;
    };
} // namespace Uni::Alg::Noise