#include <chrono>
#include <string>

namespace Uni::Prof
{
    //! A simple timer class that measures the time
    //! between its creation and its destruction.
    //! The time is measured in miliseconds and is registered
    //! in the TimeRegistry with the label given in the constructor.
    class Timer
    {
    public:
        Timer(const char* label);
        ~Timer();

    private:
        std::chrono::time_point<std::chrono::high_resolution_clock>
            m_startTimePoint;
        std::string m_label;
    };

} // namespace Uni::Prof
