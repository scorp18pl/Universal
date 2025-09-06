#pragma once

#include <Universal/Graphics/Channel.h>
#include <Universal/Graphics/Color.h>
#include <cstdint>
#include <string>
#include <vector>

namespace Uni::Grpx
{
    //! 2D pixel buffer with defined channel properties.
    class Bitmap
    {
    public:
        static Bitmap CreateFromFile(
            const std::string& path,
            bool flipVertically = false,
            Channel::Flags pixelFlags = Channel::Flags::Invalid);

        Bitmap() = default;
        //! Creates a bitmap with the given width, height and pixel flags.
        Bitmap(size_t width, size_t height, Channel::Flags pixelFlags);
        Bitmap(
            const uint8_t* data,
            size_t width,
            size_t height,
            Channel::Flags pixelFlags);
        Bitmap(const Bitmap& other) = default;
        Bitmap(Bitmap&& other) noexcept = default;
        ~Bitmap() = default;

        [[nodiscard]] size_t GetWidth() const;
        [[nodiscard]] size_t GetHeight() const;

        //! Returns stride in bytes.
        //! Stride is the number of bytes between the start of one row and the
        //! start of the next.
        [[nodiscard]] const uint8_t* GetData() const;
        [[nodiscard]] size_t GetStride() const;
        [[nodiscard]] Channel::Flags GetPixelFlags() const;
        [[nodiscard]] size_t GetPixelIndex(size_t x, size_t y) const;
        [[nodiscard]] Color GetPixelColor(size_t x, size_t y) const;

        [[nodiscard]] uint8_t* GetData();
        void SetPixelColor(size_t x, size_t y, const Color& color);

        //! WritePixelData from other bitmap to this bitmap.
        //! The other bitmap must have the same pixel flags.
        //! @param x The x coordinate of the top left corner of the area to
        //! overwrite.
        //! @param y The y coordinate of the top left corner of the area to
        //! overwrite.
        //! @param other The bitmap to copy data from.
        //! @param bitmapX The x coordinate of the top left corner of the area
        //! to copy from.
        //! @param bitmapY The y coordinate of the top left corner of the area
        //! to copy from.
        //! @param width The width of the area to copy.
        //! @param height The height of the area to copy.
        //! If width or height is 0, the function will copy the entire bitmap.
        //! If the selected area is not contained within the bitmap, the
        //! function will fail.
        void WriteData(
            size_t x,
            size_t y,
            const Bitmap& other,
            size_t bitmapX = 0,
            size_t bitmapY = 0,
            size_t width = 0,
            size_t height = 0);

        Bitmap& operator=(const Bitmap& other);

    private:
        Channel::Flags m_pixelFlags{ Channel::Flags::Invalid };

        size_t m_width{ 0LU };
        size_t m_height{ 0LU };

        std::vector<uint8_t> m_data;
    };
} // namespace Uni::Grpx
