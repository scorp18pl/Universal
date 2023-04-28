#pragma once

#include <Universal/Graphics/Channel.h>
#include <cstddef>

namespace Uni::Grpx::Utils
{
    size_t CalculatePixelSize(Channel::Flags flags);
    size_t GetChannelSize(Channel::Flags flags, Channel::Type type);
    size_t GetChannelCount(Channel::Flags flags);
    Channel::Flags GetChannelFlags(size_t channelCount);
} // namespace Uni::Grpx::Utils