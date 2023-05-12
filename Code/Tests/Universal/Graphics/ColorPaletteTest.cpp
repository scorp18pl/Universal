#include <Universal/Graphics/ColorPalette.h>
#include <gtest/gtest.h>

TEST(ColorPaletteTest, LoadFromFile)
{
    Uni::Grpx::ColorPalette palette = Uni::Grpx::ColorPalette::LoadFromFile(
        "../../../../assets/universalis-42.hex");
    EXPECT_EQ(palette.GetName(), "universalis-42");
    EXPECT_EQ(palette.GetColors().size(), 42);
}