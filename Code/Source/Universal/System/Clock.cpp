#include <Universal/System/Clock.h>

namespace Uni::Sys
{
    Clock::Clock()
        : m_startTimePoint{ std::chrono::high_resolution_clock::now() }
    {
    }

    float Clock::GetElapsedTime() const
    {
        const auto endTimePoint = std::chrono::high_resolution_clock::now();
        const auto start =
            std::chrono::time_point_cast<std::chrono::microseconds>(
                m_startTimePoint)
                .time_since_epoch()
                .count();
        const auto end =
            std::chrono::time_point_cast<std::chrono::microseconds>(
                endTimePoint)
                .time_since_epoch()
                .count();

        return static_cast<float>(end - start) * 0.001f;
    }

    void Clock::Reset()
    {
        m_startTimePoint = std::chrono::high_resolution_clock::now();
    }
} // namespace Uni::Sys