#include <string>
#include <unordered_map>
#include <vector>

namespace Uni::Prof
{

    using RegisteredTimesType =
        std::unordered_map<std::string, std::vector<double>>;

    //! A singleton class that stores times with labels.
    class TimeRegistry
    {
    public:
        static TimeRegistry& GetTimeRegistry();

        const RegisteredTimesType& GetRegisteredTimes() const;

        //! Writes all registered times into a json file.
        //! @param filePath The path to the file directory.
        //! @param filenameNoExtension The name of the file without the extension.
        //! @param append If true, the times are appended to the existing file.
        void WriteToJsonFile(
            const char* filePath,
            const char* filenameNoExtension,
            bool append = false) const;

        //! Clears all registered times.
        void ClearTimes();

        //! Registers a time (in milliseconds) with a label.
        void RegisterTime(const std::string& name, double measuredTime);

    private:
        TimeRegistry() = default;
        TimeRegistry(const TimeRegistry& other) = default;
        TimeRegistry(TimeRegistry&& other) = default;
        ~TimeRegistry() = default;

        RegisteredTimesType m_registeredTimeMap;
    };

} // namespace Uni::Prof
