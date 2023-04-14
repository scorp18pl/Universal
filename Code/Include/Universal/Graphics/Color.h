#pragma once

#include <Universal/Math/Vector3f.h>

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

        static Color CreateFromVector3f(
            const Math::Vector3f& vector, float alpha = 1.0f);
        static Color CreateFromFloats(
            float red, float green, float blue, float alpha = 1.0f);

        Color() = default;

        [[nodiscard]] float GetRed() const;
        [[nodiscard]] float GetGreed() const;
        [[nodiscard]] float GetBlue() const;
        [[nodiscard]] Math::Vector3f GetColor() const;
        [[nodiscard]] float GetAlpha() const;

    private:
        Math::Vector3f m_color;
        float m_alpha;
    };
} // namespace Uni::Grpx