#pragma once

#include <Universal/Math/Vector/Vector4f.h>
#include <cstdint>

namespace Uni::Grpx
{
    class Color
    {
    public:
        static const Color Black;
        static const Color White;
        static const Color Red;
        static const Color Green;
        static const Color Blue;

        static Color CreateFromVector4f(
            const Math::Vector4f& vector);
        static Color CreateFromFloats(
            float red, float green, float blue, float alpha = 1.0f);
        static Color CreateFromUint8(
                uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 255);

        Color() = default;

        [[nodiscard]] float GetRed() const;
        [[nodiscard]] float GetGreed() const;
        [[nodiscard]] float GetBlue() const;
        [[nodiscard]] float GetAlpha() const;
        [[nodiscard]] Math::Vector4f GetColor() const;

    private:
        Math::Vector4f m_color;
        float m_alpha;
    };
} // namespace Uni::Grpx