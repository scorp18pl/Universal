#include <string>
#include <unordered_map>
#include <vector>

namespace Uni::Prof
{

    using RegisteredTimesType =
        std::unordered_map<std::string, std::vector<double>>;

    class TimeRegistry
    {
    public:
        static TimeRegistry& GetTimeRegistry();

        const RegisteredTimesType& GetRegisteredTimes() const;
        void WriteToJsonFile(
            const char* filePath, const char* filenameNoExtension = "time_registry_log_file") const;

        void ClearTimes();
        void RegisterTime(const std::string& name, double measuredTime);

    private:
        TimeRegistry() = default;
        TimeRegistry(const TimeRegistry& other) = default;
        TimeRegistry(TimeRegistry&& other) = default;
        ~TimeRegistry() = default;

        RegisteredTimesType m_registeredTimeMap;
    };

} // namespace Uni::Prof
