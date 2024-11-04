#include <Universal/Math/Math.h>
#include <cmath>

namespace Uni::Math
{
    float Q_rsqrt(float number)
    {
        long i;
        float x2, y;
        const float threehalfs = 1.5F;

        x2 = number * 0.5F;
        y = number;
        i = *(long*)&y; // evil floating point bit level hacking
        i = 0x5f3759df - (i >> 1); // what the fuck?
        y = *(float*)&i;
        y = y * (threehalfs - (x2 * y * y)); // 1st iteration
        y = y * (threehalfs - (x2 * y * y)); // 2nd iteration,
        // this can be removed

        return y;
    }

    float FMod(float x, float y)
    {
        float mod = std::fmod((x < 0.0f) ? x + y : x, y);
        return mod;
    }

    float SmoothStepSimple(float value)
    {
        value = std::max(value, 0.0f);
        value = std::min(value, 1.0f);
        return value * value * (-2.0f * value + 3.0f);
    }

    float SmoothStep(float value)
    {
        value = std::max(value, 0.0f);
        value = std::min(value, 1.0f);
        return value * value * value * (value * (value * 6.0f - 15.0f) + 10.0f);
    }

    float Lerp(float value1, float value2, float t)
    {
        return value1 * (1.0f - t) + value2 * t;
    }

    float Attenuation(float t)
    {
        return std::pow<float, int>(0.5f - t * t, 4);
    }
} // namespace Uni::Math