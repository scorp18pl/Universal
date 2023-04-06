#include <Universal/Graphics/Buffer.h>
#include <gtest/gtest.h>

namespace Uni::Grpx
{
    TEST(BufferTest, Constructor)
    {
        Buffer buffer(10);
        EXPECT_EQ(buffer.GetSize(), 10);
    }

    TEST(BufferTest, MoveConstructor)
    {
        Buffer buffer1(10);
        Buffer buffer2(std::move(buffer1));
        EXPECT_EQ(buffer2.GetSize(), 10);
    }
} // namespace Uni::Grpx
