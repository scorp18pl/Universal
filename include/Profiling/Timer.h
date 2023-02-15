#include <chrono>
#include <string>

namespace Uni::Prof
{
    class Timer
    {
    public:
        Timer(const char* name);
        ~Timer();

    private:
        std::chrono::time_point<std::chrono::high_resolution_clock>
            m_startTimePoint;
        std::string m_name;
    };

} // namespace Uni::Prof
