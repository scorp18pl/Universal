#pragma once

#include <Universal/Math/Vector/Vector2f.h>
#include <vector>

namespace Uni::Math
{
    //! A 2D bounding box class.
    //! The box is defined by a minimum point and a maximum point.
    class Aabb2D
    {
    public:
        static Aabb2D CreateInvalid();
        static Aabb2D CreateFromDimensions(
            const Vector2f& origin, const Vector2f& dimensions);
        static Aabb2D CreateFromPoints(
            const std::vector<Vector2f>& points);

        Aabb2D();
        Aabb2D(const Vector2f& origin, const Vector2f& dimensions);
        Aabb2D(const Aabb2D& other) = default;
        Aabb2D(Aabb2D&& other) = default;
        ~Aabb2D() = default;

        //! The Bounding box is valid if the minimum point is less than the
        //! maximum point.
        [[nodiscard]] bool IsValid() const;
        [[nodiscard]] bool IsPointWithinBounds(const Vector2f& point) const;

        [[nodiscard]] Vector2f GetDimensions() const;
        [[nodiscard]] Vector2f GetMinPoint() const;
        [[nodiscard]] Vector2f GetMaxPoint() const;

        Aabb2D& operator=(const Aabb2D& other) = default;

    private:
        Vector2f m_origin, m_dimensions;
    };

} // namespace Uni::Math
