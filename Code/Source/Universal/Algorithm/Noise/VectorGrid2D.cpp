#include <Universal/Algorithm/Noise/VectorGrid2D.h>
#include <Universal/Math/Math.h>
#include <Universal/Math/Random/Generator.h>
#include <Universal/Math/Random/RandomUtils.h>
#include <array>
#include <stdexcept>

namespace Uni::Alg::Noise
{
    VectorGrid2D::VectorGrid2D(size_t cellCountX, size_t cellCountY)
        : m_cellCountX{ cellCountX }
        , m_cellCountY{ cellCountY }
        , m_grid{ (cellCountX + 1LU) * (cellCountY + 1LU) }
    {
    }

    VectorGrid2D::VectorGrid2D(VectorGrid2D&& other) noexcept
        : m_cellCountX{ other.m_cellCountX }
        , m_cellCountY{ other.m_cellCountY }
        , m_grid{ std::move(other.m_grid) }
    {
    }

    size_t VectorGrid2D::GetCellCountX() const
    {
        return m_cellCountX;
    }

    size_t VectorGrid2D::GetCellCountY() const
    {
        return m_cellCountY;
    }

    float VectorGrid2D::Sample(const Math::Vector2f& gridPosition) const
    {
        static constexpr size_t CellCornerCount = 4LU;
        static const std::array<std::pair<size_t, size_t>, CellCornerCount>
            CellToCornerTranslations{
                {
                    { 0LU, 0LU }, // North West
                    { 1LU, 0LU }, // North East
                    { 0LU, 1LU }, // South West
                    { 1LU, 1LU }, // South East
                },
            };

        const auto xIndex = static_cast<size_t>(gridPosition.m_x);
        const auto yIndex = static_cast<size_t>(gridPosition.m_y);

        const Math::Vector2f sampleToCellTranslation = gridPosition -
            Math::Vector2f{
                static_cast<float>(xIndex),
                static_cast<float>(yIndex),
            };

        const std::array<Math::Vector2f, CellCornerCount>
            CornerToSampleTranslations{ {
                sampleToCellTranslation,
                sampleToCellTranslation - Math::Vector2f{ 1.0f, 0.0f },
                sampleToCellTranslation - Math::Vector2f{ 0.0f, 1.0f },
                sampleToCellTranslation - Math::Vector2f{ 1.0f, 1.0f },
            } };

        const std::array<float, CellCornerCount> DotProducts{ {
            m_grid[GetVectorIndex(xIndex, yIndex)].Dot(
                CornerToSampleTranslations[0]),
            m_grid[GetVectorIndex(xIndex + 1LU, yIndex)].Dot(
                CornerToSampleTranslations[1]),
            m_grid[GetVectorIndex(xIndex, yIndex + 1LU)].Dot(
                CornerToSampleTranslations[2]),
            m_grid[GetVectorIndex(xIndex + 1LU, yIndex + 1LU)].Dot(
                CornerToSampleTranslations[3]),
        } };

        const float InterpolatedValueX1 = Math::Lerp(
            DotProducts[0],
            DotProducts[1],
            Math::SmoothStep(sampleToCellTranslation.m_x));
        const float InterpolatedValueX2 = Math::Lerp(
            DotProducts[2],
            DotProducts[3],
            Math::SmoothStep(sampleToCellTranslation.m_x));

        return Math::Lerp(
            InterpolatedValueX1,
            InterpolatedValueX2,
            Math::SmoothStep(sampleToCellTranslation.m_y));
    }

    void VectorGrid2D::Resize(size_t cellCountX, size_t cellCountY)
    {
        m_cellCountX = cellCountX;
        m_cellCountY = cellCountY;
        m_grid.resize((cellCountX + 1LU) * (cellCountY + 1LU));
    }

    void VectorGrid2D::GenerateVectors(Math::Rand::Generator& generator)
    {
        const size_t vectorCountX = GetVectorCountX();
        const size_t vectorCountY = GetVectorCountY();

        for (size_t y = 0LU; y < vectorCountX; ++y)
        {
            for (size_t x = 0LU; x < vectorCountY; ++x)
            {
                m_grid[GetVectorIndex(x, y)] =
                    Math::Vector2f::CreateRandomUnitVector(generator);
            }
        }
    }

    size_t VectorGrid2D::GetVectorCountX() const
    {
        return m_cellCountX + 1LU;
    }

    size_t VectorGrid2D::GetVectorCountY() const
    {
        return m_cellCountY + 1LU;
    }

    size_t VectorGrid2D::GetVectorIndex(size_t x, size_t y) const
    {
        if (x >= GetVectorCountX() || y >= GetVectorCountY())
        {
            throw std::out_of_range(
                "Provided vector coordinates are invalid. x: " +
                std::to_string(x) + ", y: " + std::to_string(y) +
                ", vectorCountX: " + std::to_string(GetVectorCountX()) +
                ", vectorCountY: " + std::to_string(GetVectorCountY()));
        }

        return y * GetVectorCountX() + x;
    }
} // namespace Uni::Alg::Noise