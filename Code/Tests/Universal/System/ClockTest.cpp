#include <gtest/gtest.h>
#include <Universal/System/Clock.h>
#include <thread>

namespace Uni::Sys
{
    constexpr float epsilon = 1e-2f;

    TEST(ClockTest, DefaultConstructor) {
        Clock clock;
        ASSERT_GE(clock.GetElapsedTime(), 0.0f);
    }

    TEST(ClockTest, ElapsedTimeIncreases) {
        Clock clock;
        float startTime = clock.GetElapsedTime();

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        float elapsedTime = clock.GetElapsedTime();
        ASSERT_GT(elapsedTime, startTime);
    }

    TEST(ClockTest, Reset) {
        Clock clock;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        clock.Reset();

        float elapsedTime = clock.GetElapsedTime();
        ASSERT_GE(elapsedTime, 0.0f);
        ASSERT_LT(elapsedTime, 0.1f);
    }

    TEST(ClockTest, CopyConstructor) {
        Clock clock1;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        Clock clock2(clock1);

        float elapsedTime1 = clock1.GetElapsedTime();
        float elapsedTime2 = clock2.GetElapsedTime();

        ASSERT_NEAR(elapsedTime1, elapsedTime2, epsilon);
    }

    TEST(ClockTest, MoveConstructor) {
        Clock clock1;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        Clock clock2(std::move(clock1));

        float elapsedTime2 = clock2.GetElapsedTime();
        ASSERT_GE(elapsedTime2, 0.1f);
    }
} // namespace Uni::Sys
