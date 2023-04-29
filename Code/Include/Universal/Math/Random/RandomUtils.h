#pragma once

#include <Universal/Math/Random/Generator.h>
#include <Universal/Math/Vector/Vector2f.h>

namespace Uni::Math::Rand::Utils
{
    SeedType CreateSeedFromPosition(const Uni::Math::Vector2f& position);
} // namespace Uni::Math::Rand::Utils
