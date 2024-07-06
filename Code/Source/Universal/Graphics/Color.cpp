#include <Universal/Graphics/Color.h>

namespace Uni::Grpx
{
    const Color Color::White = CreateFromFloats(1.0f, 1.0f, 1.0f);
    const Color Color::Black = CreateFromFloats(0.0f, 0.0f, 0.0f);
    const Color Color::Red = CreateFromFloats(1.0f, 0.0f, 0.0f);
    const Color Color::Green = CreateFromFloats(0.0f, 1.0f, 0.0f);
    const Color Color::Blue = CreateFromFloats(0.0f, 0.0f, 1.0f);

    Color Color::CreateFromVector3f(
        const Uni::Math::Vector3f& vector, float alpha)
    {
        return CreateFromVector4f(
            { vector.m_x, vector.m_y, vector.m_z, alpha });
    }

    Color Color::CreateFromVector4f(const Uni::Math::Vector4f& vector)
    {
        return CreateFromFloats(vector.m_x, vector.m_y, vector.m_z, vector.m_w);
    }

    Color Color::CreateFromFloats(
        float red, float green, float blue, float alpha)
    {
        return { red, green, blue, alpha };
    }

    Color Color::CreateFromUint8(
        uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
    {
        return CreateFromFloats(
            static_cast<float>(red) / 255.0f,
            static_cast<float>(green) / 255.0f,
            static_cast<float>(blue) / 255.0f,
            static_cast<float>(alpha) / 255.0f);
    }

    Color Color::CreateGray(float value, float alpha)
    {
        return CreateFromVector3f(Math::Vector3f{ value }, alpha);
    }

    Color::Color(float red, float green, float blue, float alpha)
        : Vector4f(red, green, blue, alpha)
    {
    }

    float Color::GetRed() const { return m_x; }

    float Color::GetGreen() const { return m_y; }

    float Color::GetBlue() const { return m_z; }

    float Color::GetAlpha() const { return m_w; }
} // namespace Uni::Grpx
