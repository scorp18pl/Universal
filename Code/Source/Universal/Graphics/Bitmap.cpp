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
            Utils::GetChannelFlags(static_cast<size_t>(channels)),
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

    Color Bitmap::GetPixelColor(size_t x, size_t y) const
    {
        float r, g, b, a;
        r = g = b = a = 1.0f;
        const uint8_t* pixelData = &GetData()[GetPixelIndex(x, y)];

        if (m_pixelFlags & Channel::Flags::Rgb16)
        {
            throw std::runtime_error("16-bit color not supported yet.");
            return Color::White;
        }

        r = static_cast<float>(pixelData[0]) / 255.0f;
        if (m_pixelFlags & Channel::Flags::GreyScale)
        {
            g = b = r;
        }
        else
        {
            g = static_cast<float>(pixelData[1]) / 255.0f;
            b = static_cast<float>(pixelData[2]) / 255.0f;
        }

        if (m_pixelFlags & Channel::Flags::Alpha)
        {
            a = static_cast<float>(pixelData[3]) / 255.0f;
        }

        return Color::CreateFromFloats(r, g, b, a);
    }

    void Bitmap::SetPixelColor(size_t x, size_t y, const Color& color)
    {
        uint8_t* pixelData = &GetData()[GetPixelIndex(x, y)];

        if (m_pixelFlags & Channel::Flags::Rgb16)
        {
            throw std::runtime_error("16-bit color not supported yet.");
        }

        unsigned int alphaIndex = -1U;
        if (m_pixelFlags & Channel::Flags::GreyScale)
        {
            const float Average =
                (color.GetRed() + color.GetGreen() + color.GetBlue()) / 3.0f;
            pixelData[0] = static_cast<uint8_t>(Average * 255.0f);
            alphaIndex = 1U;
        }
        else
        {
            pixelData[0] = static_cast<uint8_t>(color.GetRed() * 255.0f);
            pixelData[1] = static_cast<uint8_t>(color.GetGreen() * 255.0f);
            pixelData[2] = static_cast<uint8_t>(color.GetBlue() * 255.0f);
            alphaIndex = 3U;
        }

        if (m_pixelFlags & Channel::Flags::Alpha)
        {
            pixelData[alphaIndex] =
                static_cast<uint8_t>(color.GetAlpha() * 255.0f);
        }
    }

    Bitmap& Bitmap::operator=(const Bitmap& other)
    {
        if (this != &other)
        {
            m_width = other.m_width;
            m_height = other.m_height;
            m_pixelFlags = other.m_pixelFlags;
            m_pixelSize = other.m_pixelSize;
            Buffer::operator=(other);
        }

        return *this;
    }
} // namespace Uni::Grpx