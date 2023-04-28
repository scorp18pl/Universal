#include <Universal/Graphics/Bitmap.h>
#include <Universal/Graphics/GraphicsUtils.h>
#include <cstring>
#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>
#include <stdexcept>

namespace Uni::Grpx
{
    Bitmap Bitmap::CreateFromFile(
        const std::string& path, bool flipVertically, Channel::Flags pixelFlags)
    {
        int width, height;
        int desiredChannels = 0;
        if (pixelFlags != Channel::Flags::Invalid)
        {
            desiredChannels =
                static_cast<int>(Utils::GetChannelCount(pixelFlags));
        }

        int channels = 0;
        stbi_set_flip_vertically_on_load(flipVertically);
        unsigned char* data = stbi_load(
            path.c_str(), &width, &height, &channels, desiredChannels);

        if (data == nullptr)
        {
            throw std::runtime_error("Failed to load image: " + path);
        }

        return {
            data,
            static_cast<size_t>(width),
            static_cast<size_t>(height),
            Utils::GetChannelFlags(static_cast<size_t>(channels))
        };
    }

    Bitmap::Bitmap(size_t width, size_t height, Channel::Flags pixelFlags)
        : Buffer{ Utils::CalculatePixelSize(pixelFlags) * width * height }
        , m_width{ width }
        , m_height{ height }
        , m_pixelFlags{ pixelFlags }
        , m_pixelSize{ Utils::CalculatePixelSize(pixelFlags) }
    {
    }

    Bitmap::Bitmap(
        uint8_t* data, size_t width, size_t height, Channel::Flags pixelFlags)
        : Buffer{ data, Utils::CalculatePixelSize(pixelFlags) * width * height }
        , m_width{ width }
        , m_height{ height }
        , m_pixelFlags{ pixelFlags }
        , m_pixelSize{ Utils::CalculatePixelSize(pixelFlags) }
    {
    }

    Bitmap::Bitmap(const Bitmap& other)
        : Buffer(other.GetSize())
        , m_width{ other.m_width }
        , m_height{ other.m_height }
        , m_pixelFlags{ other.m_pixelFlags }
        , m_pixelSize{ other.m_pixelSize }
    {
        std::memcpy(m_data, other.m_data, other.m_size);
    }

    Bitmap::Bitmap(Bitmap&& other) noexcept
        : Buffer{ other.m_size }
        , m_width{ other.m_width }
        , m_height{ other.m_height }
        , m_pixelFlags{ other.m_pixelFlags }
        , m_pixelSize{ other.m_pixelSize }
    {
        other.m_width = 0LU;
        other.m_height = 0LU;
    }

    size_t Bitmap::GetWidth() const
    {
        return m_width;
    }

    size_t Bitmap::GetHeight() const
    {
        return m_height;
    }

    size_t Bitmap::GetPixelSize() const
    {
        return m_pixelSize;
    }

    size_t Bitmap::GetStride() const
    {
        return GetPixelSize() * GetWidth();
    }

    Channel::Flags Bitmap::GetPixelFlags() const
    {
        return m_pixelFlags;
    }

    size_t Bitmap::GetPixelIndex(size_t x, size_t y) const
    {
        return GetStride() * y + x * GetPixelSize();
    }
} // namespace Uni::Grpx