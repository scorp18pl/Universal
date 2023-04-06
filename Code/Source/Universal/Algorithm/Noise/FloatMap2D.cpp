#include <Universal/Algorithm/Noise/FloatMap2D.h>
#include <Universal/Configuration/GlobalSettings.h>
#include <array>
#include <thread>

namespace Uni::Alg::Noise
{
    static constexpr size_t workerCount = Global::Settings::ThreadCount;

    FloatMap2D::FloatMap2D::FloatMap2D(size_t width, size_t height)
        : m_width{ width }
        , m_height{ height }
    {
        m_values = new float[width * height];
        for (size_t i = 0; i < width * height; ++i)
        {
            m_values[i] = 0.0f;
        }
    }

    FloatMap2D::FloatMap2D(FloatMap2D&& other) noexcept
        : m_width{ other.m_width }
        , m_height{ other.m_height }
        , m_values{ other.m_values }
    {
        other.m_values = nullptr;
        other.m_width = 0LU;
        other.m_height = 0LU;
    }

    FloatMap2D::~FloatMap2D()
    {
        delete[] m_values;
    }

    size_t FloatMap2D::GetWidth() const
    {
        return m_width;
    }

    size_t FloatMap2D::GetHeight() const
    {
        return m_height;
    }

    float FloatMap2D::GetValue(size_t x, size_t y) const
    {
        if (!m_values)
        {
            return 0.0f;
        }

        return m_values[m_width * y + x];
    }

    std::pair<float, float> FloatMap2D::GetMinMax() const
    {
        std::pair<float, float> minMax{ std::numeric_limits<float>::max(),
                                        std::numeric_limits<float>::min() };

        for (size_t i = 0; i < m_width * m_height; ++i)
        {
            if (m_values[i] < minMax.first)
            {
                minMax.first = m_values[i];
            }
            if (m_values[i] > minMax.second)
            {
                minMax.second = m_values[i];
            }
        }

        return minMax;
    }

    void FloatMap2D::SetValue(size_t x, size_t y, float value)
    {
        m_values[GetIndex(x, y)] = value;
    }

    Grpx::Bitmap FloatMap2D::ToBitMap() const
    {
        Grpx::Bitmap bitmap{
            m_width,
            m_height,
            Grpx::Channel::Flags::GreyScale,
        };

        std::pair<float, float> minMax = GetMinMax();

        std::array<std::thread, workerCount> threads;
        for (size_t id = 0; id < threads.size(); ++id)
        {
            threads[id] = std::thread{
                [this, &bitmap, &minMax](
                    size_t workerCount, size_t id, size_t length)
                {
                    for (size_t index = id; index < length;
                         index += workerCount)
                    {
                        const size_t y = index / m_width;
                        const size_t x = index - (y * m_width);

                        bitmap.GetData()[bitmap.GetPixelIndex(x, y)] =
                            static_cast<uint8_t>(
                                (GetValue(x, y) - minMax.first) /
                                (minMax.second - minMax.first) * 255.0f);
                    }
                },
                workerCount,
                id,
                m_width * m_height,
            };
        }

        for (std::thread& thread : threads)
        {
            thread.join();
        }

        return bitmap;
    }

    size_t FloatMap2D::GetIndex(size_t x, size_t y) const
    {
        return m_width * y + x;
    }
} // namespace Uni::Alg::Noise