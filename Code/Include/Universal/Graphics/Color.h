#pragma once

#include <Universal/Math/Vector/Vector3f.h>
#include <Universal/Math/Vector/Vector4f.h>
#include <cstdint>

namespace Uni::Grpx
{
    class Color : public Math::Vector4f
    {
    public:
        static const Color Black;
        static const Color White;
        static const Color Red;
        static const Color Green;
        static const Color Blue;

        static Color CreateFromVector3f(
            const Math::Vector3f& vector, float alpha = 1.0f);
        static Color CreateFromVector4f(const Math::Vector4f& vector);
        static Color CreateFromFloats(
            float red, float green, float blue, float alpha = 1.0f);
        static Color CreateFromUint8(
            uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 255);

        static Color CreateGray(float value, float alpha = 1.0f);

        Color() = default;
        Color(float red, float green, float blue, float alpha = 1.0f);
        Color(const Color& other) = default;
        Color(Color&& other) = default;
        ~Color() = default;

        [[nodiscard]] float GetRed() const;
        [[nodiscard]] float GetGreen() const;
        [[nodiscard]] float GetBlue() const;
        [[nodiscard]] float GetAlpha() const;

        Color& operator=(const Color& other) = default;
    };
} // namespace Uni::Grpx