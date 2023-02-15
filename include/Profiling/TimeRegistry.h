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
        static TimeRegistry& GetTimerRegistry();

        const RegisteredTimesType& GetRegisteredTimes() const;

        void RegisterTime(const std::string& name, double measuredTime);

    private:
        TimeRegistry() = default;
        TimeRegistry(const TimeRegistry& other) = default;
        TimeRegistry(TimeRegistry&& other) = default;
        ~TimeRegistry() = default;

        RegisteredTimesType m_registeredTimeMap;
    };

} // namespace Uni::Prof
