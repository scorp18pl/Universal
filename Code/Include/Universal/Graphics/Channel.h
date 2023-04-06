#pragma once

#include <cstdint>

namespace Uni::Grpx::Channel
{
    enum class Type : uint8_t
    {
        Red,
        Green,
        Blue,
        Alpha,
    };

    enum Flags : uint8_t
    {
        None = 0b00000000,
        GreyScale =
            0b00000001, //!< If enabled, Green and Blue channels are not used.
        RGB16 = 0b00000010, //!< If enabled uses 16 bits for the Red Green
                            //!< and Blue channels, if not uses 8 bits.
        Alpha = 0b00000100, //!< Enables the alpha channel (8 bits).
    };

    using Type8bit = uint8_t;
    using Type16bit = uint16_t;
}
