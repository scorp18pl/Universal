#include <Universal/Graphics/Bitmap.h>
#include <gtest/gtest.h>

namespace Uni::Grpx
{
    TEST(BitmapTest, Constructor)
    {
        Channel::Flags pixelFlags = Channel::Flags::GreyScale;
        size_t width = 10;
        size_t height = 10;
        Bitmap bitmap(width, height, pixelFlags);

        EXPECT_EQ(bitmap.GetWidth(), width);
        EXPECT_EQ(bitmap.GetHeight(), height);
        EXPECT_EQ(bitmap.GetPixelFlags(), pixelFlags);
    }

    TEST(BitmapTest, CopyConstructor)
    {
        Channel::Flags pixelFlags = Channel::Flags::GreyScale;
        size_t width = 10;
        size_t height = 10;
        Bitmap bitmap(width, height, pixelFlags);

        Bitmap bitmapCopy(bitmap);

        EXPECT_EQ(bitmapCopy.GetWidth(), width);
        EXPECT_EQ(bitmapCopy.GetHeight(), height);
        EXPECT_EQ(bitmapCopy.GetPixelFlags(), pixelFlags);
    }

    TEST(BitmapTest, MoveConstructor)
    {
        Channel::Flags pixelFlags = Channel::Flags::GreyScale;
        size_t width = 10;
        size_t height = 10;
        Bitmap bitmap(width, height, pixelFlags);

        Bitmap bitmapCopy(std::move(bitmap));

        EXPECT_EQ(bitmapCopy.GetWidth(), width);
        EXPECT_EQ(bitmapCopy.GetHeight(), height);
        EXPECT_EQ(bitmapCopy.GetPixelFlags(), pixelFlags);
    }

    TEST(BitmapTest, GetPixelIndex)
    {
        Channel::Flags pixelFlags = Channel::Flags::GreyScale;
        size_t width = 10;
        size_t height = 10;
        Bitmap bitmap(width, height, pixelFlags);

        size_t x = 5;
        size_t y = 5;
        size_t expectedIndex =
            y * bitmap.GetStride() + x * bitmap.GetPixelSize();

        EXPECT_EQ(bitmap.GetPixelIndex(x, y), expectedIndex);

        pixelFlags = static_cast<Channel::Flags>(
            Channel::Flags::GreyScale | Channel::Flags::Alpha);
        width = 20;
        height = 20;
        Bitmap bitmap2(width, height, pixelFlags);

        x = 10;
        y = 10;
        expectedIndex = y * bitmap2.GetStride() + x * bitmap2.GetPixelSize();

        EXPECT_EQ(bitmap2.GetPixelIndex(x, y), expectedIndex);
    }
} // namespace Uni::Grpx