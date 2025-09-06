#include <Universal/Math/Math.h>
#include <cmath>

namespace Uni::Math
{
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
} // namespace Uni::Math