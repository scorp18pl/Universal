#include <Universal/Profiling/TimeRegistry.h>
#include <fstream>
#include <nlohmann/json.hpp>

namespace Uni::Prof
{
    TimeRegistry& TimeRegistry::GetTimeRegistry()
    {
        static TimeRegistry timerRegistry;
        return timerRegistry;
    }

    const RegisteredTimesType& TimeRegistry::GetRegisteredTimes() const
    {
        return m_registeredTimeMap;
    }

    void TimeRegistry::WriteToJsonFile(
        const char* filePath,
        const char* filenameNoExtension,
        bool append) const
    {
        const std::string filename =
            std::string(filePath) + filenameNoExtension + ".json";
        nlohmann::json jsonFile;

        if (append)
        {
            std::ifstream logFile;
            logFile.open(filename);
            jsonFile = nlohmann::json::parse(logFile);
            logFile.close();
        }

        for (auto& entry : m_registeredTimeMap)
        {
            for (auto& time : entry.second)
            {
                jsonFile[entry.first].push_back(time);
            }
        }

        std::ofstream logFile;
        logFile.open(filename);
        logFile << jsonFile;
        logFile.close();
    }

    void TimeRegistry::ClearTimes()
    {
        m_registeredTimeMap.clear();
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