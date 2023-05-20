#pragma once

namespace Uni::Math
{
    namespace Constants
    {
        constexpr float BigG = 6.6743e-11f;
        constexpr float PI = 3.14159265359f;
        constexpr float HalfPI = 1.57079632679f;
        constexpr float TwoPI = 6.28318530718;
        constexpr float DegToRad = PI / 180.0f;
        constexpr float RadToDeg = 180.0f / PI;
    } // namespace Constants

    float Q_rsqrt(float number);
    float FMod(float x, float y);
    float SmoothStepSimple(float value);
    float SmoothStep(float value);
    float Lerp(float value1, float value2, float t);
} // namespace Uni::Math
