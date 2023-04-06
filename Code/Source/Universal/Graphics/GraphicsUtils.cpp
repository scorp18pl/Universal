#include <Universal/Graphics/GraphicsUtils.h>
#include <Universal/Graphics/Channel.h>

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
        if(!(flags & Channel::Flags::GreyScale))
        {
            count += 3LU;
        }

        if (flags & Channel::Flags::Alpha)
        {
            count += 1LU;
        }

        return count;
    }
} // namespace Uni::Grpx::Utils