#include <Universal/Profiling/Timer.h>
#include <Universal/Profiling/TimeRegistry.h>

namespace Uni::Prof
{
    Timer::Timer(const char* label)
        : m_label(label)
    {
        m_startTimePoint = std::chrono::high_resolution_clock::now();
    }

    Timer::~Timer()
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

        const double miliseconds = (end - start) * 0.001;

        auto& timerRegistry = TimeRegistry::GetTimeRegistry();
        timerRegistry.RegisterTime(m_label, miliseconds);
    }
} // namespace Uni::Prof