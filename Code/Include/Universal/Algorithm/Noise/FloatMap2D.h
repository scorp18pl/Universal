#pragma once

#include <Universal/Graphics/Bitmap.h>

namespace Uni::Alg::Noise
{

    //! A 2D map of floating point values.
    //! Used to store the results of noise generation.
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
        [[nodiscard]] std::pair<float, float> GetMinMax() const;

        void SetValue(size_t x, size_t y, float value);

        //! Converts the map to a bitmap with grayscale values.
        [[nodiscard]] Grpx::Bitmap ToBitMap() const;

    private:
        [[nodiscard]] size_t GetIndex(size_t x, size_t y) const;

        size_t m_width, m_height;
        float* m_values;
    };

} // namespace Uni::Alg::Noise
