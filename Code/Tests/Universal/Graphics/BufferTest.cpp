#include <Universal/Graphics/Buffer.h>
#include <gtest/gtest.h>

namespace Uni::Grpx
{
    TEST(BufferTest, Constructor)
    {
        Buffer<uint8_t> buffer(10);
        EXPECT_EQ(buffer.GetSize(), 10);
    }

    TEST(BufferTest, MoveConstructor)
    {
        Buffer<uint8_t> buffer1(10);
        Buffer<uint8_t> buffer2(std::move(buffer1));
        EXPECT_EQ(buffer2.GetSize(), 10);
    }
} // namespace Uni::Grpx
