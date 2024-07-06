#pragma once

#include <Universal/Math/Aabb2D.h>
#include <Universal/Math/Vector/Vector2f.h>
#include <cstddef>
#include <vector>

namespace Uni::Alg::Noise
{
    //! A 2D grid of unit vectors.
    class VectorGrid2D
    {
    public:
        VectorGrid2D(size_t cellCountX = 1LU, size_t cellCountY = 1LU);
        VectorGrid2D(const VectorGrid2D& other) = default;
        VectorGrid2D(VectorGrid2D&& other) noexcept;
        ~VectorGrid2D() = default;

        [[nodiscard]] size_t GetCellCountX() const;
        [[nodiscard]] size_t GetCellCountY() const;

        //! Samples the grid at the given position.
        //! Sampled values create a single frequency Perlin noise pattern.
        //! @param gridPosition The position to sample the grid at.
        //! @return The sampled value.
        [[nodiscard]] float Sample(const Math::Vector2f& gridPosition) const;

        //! Resizes the grid.
        void Resize(size_t cellCountX, size_t cellCountY);

        //! Generates a new set of vectors for the grid using the provided
        //! generator.
        //! @param generator The generator to use to generate the vectors.
        void GenerateVectors(Math::Rand::Generator& generator);

    private:
        [[nodiscard]] size_t GetVectorCountX() const;
        [[nodiscard]] size_t GetVectorCountY() const;

        size_t GetVectorIndex(size_t x, size_t y) const;

        size_t m_cellCountX, m_cellCountY; //!< The number of cells in the grid.
        std::vector<Math::Vector2f>
            m_grid; //!< The grid of unit vectors. Each vector is positioned at
                    //!< the corner of a cell.
    };

} // namespace Uni::Alg::Noise
