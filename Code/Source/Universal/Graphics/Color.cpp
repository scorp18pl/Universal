#pragma once

#include <Universal/Graphics/Color.h>

const Uni::Grpx::Color Uni::Grpx::Color::White = CreateFromFloats(1.0f, 1.0f, 1.0f);
const Uni::Grpx::Color Uni::Grpx::Color::Black = CreateFromFloats(0.0f, 0.0f, 0.0f);
const Uni::Grpx::Color Uni::Grpx::Color::Red =   CreateFromFloats(1.0f, 0.0f, 0.0f);
const Uni::Grpx::Color Uni::Grpx::Color::Green = CreateFromFloats(0.0f, 1.0f, 0.0f);
const Uni::Grpx::Color Uni::Grpx::Color::Blue =  CreateFromFloats(0.0f, 0.0f, 1.0f);

Uni::Grpx::Color Uni::Grpx::Color::CreateFromVector3f(
    const Uni::Math::Vector3f& vector, float alpha)
{
    Color color;
    color.m_color = vector;
    color.m_alpha = alpha;
    return color;
}

Uni::Grpx::Color Uni::Grpx::Color::CreateFromFloats(
    float red, float green, float blue, float alpha)
{
    return CreateFromVector3f({red, green, blue}, alpha);
}

float Uni::Grpx::Color::GetRed() const
{
    return m_color.m_x;
}

float Uni::Grpx::Color::GetGreed() const
{
    return m_color.m_y;
}

float Uni::Grpx::Color::GetBlue() const
{
    return m_color.m_z;
}

Uni::Math::Vector3f Uni::Grpx::Color::GetColor() const
{
    return m_color;
}

float Uni::Grpx::Color::GetAlpha() const
{
    return m_alpha;
}
