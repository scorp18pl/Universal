#pragma once

#include <Universal/Graphics/Bitmap.h>

namespace Uni::Alg::Noise
{

    class FloatMap2D
    {
    public:
        FloatMap2D(size_t width, size_t height);
        FloatMap2D(const FloatMap2D& other) = default;
        FloatMap2D(FloatMap2D&& other) noexcept;
        ~FloatMap2D();

        [[nodiscard]] size_t GetWidth() const;
        [[nodiscard]] size_t GetHeight() const;
        [[nodiscard]] float GetValue(size_t x, size_t y) const;
        std::pair<float, float> GetMinMax() const;

        void SetValue(size_t x, size_t y, float value);

        [[nodiscard]] Grpx::Bitmap ToBitMap() const;

    private:
        size_t GetIndex(size_t x, size_t y) const;

        size_t m_width, m_height;
        float* m_values;
    };

} // namespace Uni::Alg::Noise
