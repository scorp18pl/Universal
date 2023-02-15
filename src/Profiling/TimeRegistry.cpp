#include <Profiling/TimeRegistry.h>

namespace Uni::Prof
{
    TimeRegistry& TimeRegistry::GetTimerRegistry()
    {
        static TimeRegistry timerRegistry;
        return timerRegistry;
    }

    const RegisteredTimesType& TimeRegistry::GetRegisteredTimes() const
    {
        return m_registeredTimeMap;
    }

    void TimeRegistry::RegisterTime(
        const std::string& name, double measuredTime)
    {
        auto nameTimesPair = m_registeredTimeMap.find(name);
        if (nameTimesPair == m_registeredTimeMap.end())
        {
            m_registeredTimeMap.emplace(name, std::vector{ measuredTime });
            return;
        }

        nameTimesPair->second.push_back(measuredTime);
    }
} // namespace Uni::Prof