#pragma once

#include <Universal/Graphics/Color.h>
#include <string>
#include <vector>

namespace Uni::Grpx
{
    class ColorPalette
    {
    public:
        static ColorPalette LoadFromFile(const std::string& fileName);

        ColorPalette() = default;
        ColorPalette(const ColorPalette& other) = default;
        ~ColorPalette() = default;

        [[nodiscard]] const std::string& GetName() const;
        [[nodiscard]] const std::vector<Color>& GetColors() const;

        ColorPalette& operator=(const ColorPalette& other) = default;

    private:
        static Color CreateColorFromHex(const std::string& hexString);
        static Color CreateColorFromRgb(const std::string& rgbString);

        static ColorPalette LoadFromHexFile(const std::string& fileName);
        static ColorPalette LoadFromGplFile(const std::string& fileName);
        static ColorPalette LoadFromPalFile(const std::string& fileName);

        std::vector<Color> m_colors;
        std::string m_name;
    };
} // namespace Uni::Grpx
