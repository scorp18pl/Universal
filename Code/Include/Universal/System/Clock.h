#pragma once

#include <chrono>

namespace Uni::Sys
{
    class Clock
    {
    public:
        Clock();
        Clock(const Clock& other) = default;
        Clock(Clock&& other) = default;
        ~Clock() = default;

        [[nodiscard]] float GetElapsedTime() const;

        void Reset();

    private:
        std::chrono::time_point<std::chrono::high_resolution_clock>
            m_startTimePoint;
    };
} // namespace Uni::Sys
