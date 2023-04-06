#pragma once

#include <Universal/Graphics/Buffer.h>
#include <Universal/Graphics/Channel.h>
#include <cstdint>
#include <vector>

namespace Uni::Grpx
{
    //! 2D pixel buffer with defined channel properties.
    class Bitmap : public Buffer
    {
    public:
        //! Creates a bitmap with the given width, height and pixel flags.
        Bitmap(size_t width, size_t height, Channel::Flags pixelFlags);
        Bitmap(const Bitmap& other);
        Bitmap(Bitmap&& other) noexcept;
        ~Bitmap() = default;

        [[nodiscard]] size_t GetWidth() const;
        [[nodiscard]] size_t GetHeight() const;

        [[nodiscard]] size_t GetPixelSize() const;
        //! Returns stride in bytes.
        //! Stride is the number of bytes between the start of one row and the start of the next.
        [[nodiscard]] size_t GetStride() const;
        [[nodiscard]] Channel::Flags GetPixelFlags() const;
        [[nodiscard]] size_t GetPixelIndex(size_t x, size_t y) const;
    private:

        size_t m_width, m_height;
        const Channel::Flags m_pixelFlags;
        const size_t m_pixelSize;
    };
} // namespace Uni::Grpx
