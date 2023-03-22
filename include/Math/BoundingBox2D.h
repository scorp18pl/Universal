#pragma once

#include <Universal/Math/Vector2.h>

namespace Uni::Math
{
    class BoundingBox2D
    {
    public:
        static BoundingBox2D CreateFromDimensions(
            const Vector2f& minPoint, const Vector2f& dimensions);
        static BoundingBox2D CreateFromPoints(
            const Vector2f& startPoint, const Vector2f& endPoint);

        BoundingBox2D();
        BoundingBox2D(const Vector2f& minPoint, const Vector2f& dimensions);
        BoundingBox2D(const BoundingBox2D& other) = default;
        BoundingBox2D(BoundingBox2D&& other) = default;
        ~BoundingBox2D() = default;

        [[nodiscard]] bool IsPointWithinBounds(const Vector2f& point) const;

        [[nodiscard]] Vector2f GetDimensions() const;
        [[nodiscard]] Vector2f GetMinPoint() const;
        [[nodiscard]] Vector2f GetMaxPoint() const;

        BoundingBox2D& operator=(const BoundingBox2D& other) = default;
    private:
        Vector2f m_minPoint, m_maxPoint, m_dimensions;
    };

} // namespace Uni::Math
