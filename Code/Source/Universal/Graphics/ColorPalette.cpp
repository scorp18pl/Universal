#include <Universal/Graphics/ColorPalette.h>
#include <filesystem>
#include <fstream>

namespace Uni::Grpx
{
    ColorPalette ColorPalette::LoadFromFile(const std::string& fileName)
    {
        std::filesystem::path filePath{ fileName };
        if (filePath.extension() == ".hex")
        {
            return LoadFromHexFile(fileName);
        }
        else
        {
            throw std::runtime_error{ "Invalid file extension." };
        }
    }

    const std::string& ColorPalette::GetName() const
    {
        return m_name;
    }

    const std::vector<Color>& ColorPalette::GetColors() const
    {
        return m_colors;
    }

    Color ColorPalette::CreateColorFromHex(const std::string& hexString)
    {
        if (hexString.size() != 7)
        {
            throw std::runtime_error{ "Invalid hex string." };
        }

        const uint8_t red = std::stoi(hexString.substr(0, 2), nullptr, 16);
        const uint8_t green = std::stoi(hexString.substr(2, 2), nullptr, 16);
        const uint8_t blue = std::stoi(hexString.substr(4, 2), nullptr, 16);

        return Color::CreateFromUint8(red, green, blue);
    }

    ColorPalette ColorPalette::LoadFromHexFile(const std::string& fileName)
    {
        std::ifstream file{ fileName };
        if (!file.is_open())
        {
            throw std::runtime_error{ "Failed to open file." };
        }

        ColorPalette palette;
        palette.m_name = std::filesystem::path{ fileName }.stem().string();
        std::string line;
        while (std::getline(file, line))
        {
            if (line.empty())
            {
                continue;
            }

            palette.m_colors.push_back(CreateColorFromHex(line));
        }

        return palette;
    }
} // namespace Uni::Grpx