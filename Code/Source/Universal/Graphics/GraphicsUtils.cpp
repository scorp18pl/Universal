#include <Universal/Graphics/Channel.h>
#include <Universal/Graphics/GraphicsUtils.h>

namespace Uni::Grpx::Utils
{
    size_t CalculatePixelSize(Channel::Flags flags)
    {
        size_t elementSize = flags & Channel::Flags::RGB16
            ? sizeof(Channel::Type16bit)
            : sizeof(Channel::Type8bit);

        if (!(flags & Channel::Flags::GreyScale))
        {
            elementSize *= 3LU;
        }

        if (flags & Channel::Flags::Alpha)
        {
            elementSize += sizeof(Channel::Type8bit);
        }

        return elementSize;
    }

    size_t GetChannelSize(Channel::Flags flags, Channel::Type type)
    {
        if (type == Channel::Type::Alpha)
        {
            return sizeof(Channel::Type8bit);
        }

        return flags & Channel::Flags::RGB16 ? sizeof(Channel::Type16bit)
                                             : sizeof(Channel::Type8bit);
    }

    size_t GetChannelCount(Channel::Flags flags)
    {
        size_t count = 1LU;
        if (!(flags & Channel::Flags::GreyScale))
        {
            count += 2LU;
        }

        if (flags & Channel::Flags::Alpha)
        {
            count += 1LU;
        }

        return count;
    }

    Channel::Flags GetChannelFlags(size_t channelCount)
    {
        Channel::Flags flags = Channel::Flags::Invalid;
        switch (channelCount)
        {
        case 1LU:
            flags = Channel::Flags::GreyScale;
            break;
        case 2LU:
            flags = static_cast<Channel::Flags>(
                Channel::Flags::GreyScale | Channel::Flags::Alpha);
            break;
        case 3LU:
            flags = Channel::Flags::None;
            break;
        case 4LU:
            flags = Channel::Flags::Alpha;
            break;
        default:
            break;
        }

        return flags;
    }
} // namespace Uni::Grpx::Utils