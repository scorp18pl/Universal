#include <Universal/Math/BoundingBox2D.h>

namespace Uni::Math
{
    BoundingBox2D BoundingBox2D::CreateInvalid()
    {
        return { Vector2f::CreateFromFloat(1.0f),
                 Vector2f::CreateFromFloat(-1.0f) };
    }

    BoundingBox2D BoundingBox2D::CreateFromDimensions(
        const Vector2f& minPoint, const Vector2f& dimensions)
    {
        return { minPoint, dimensions };
    }

    BoundingBox2D BoundingBox2D::CreateFromPoints(
        const std::vector<Vector2f>& points)
    {
        if (points.empty())
        {
            return BoundingBox2D::CreateInvalid();
        }

        Vector2f minPoint, maxPoint;
        minPoint = maxPoint = points[0];
        for (auto& point : points)
        {
            minPoint.m_x = std::min(minPoint.m_x, point.m_x);
            minPoint.m_y = std::min(minPoint.m_y, point.m_y);
            maxPoint.m_x = std::max(maxPoint.m_x, point.m_x);
            maxPoint.m_y = std::max(maxPoint.m_y, point.m_y);
        }

        return BoundingBox2D{ minPoint, maxPoint - minPoint };
    }

    BoundingBox2D::BoundingBox2D()
    {
        (*this) = BoundingBox2D::CreateInvalid();
    }

    BoundingBox2D::BoundingBox2D(
        const Vector2f& minPoint, const Vector2f& dimensions)
        : m_minPoint{ minPoint }
        , m_maxPoint{ minPoint + dimensions }
        , m_dimensions{ dimensions }
    {
    }

    bool BoundingBox2D::IsValid() const
    {
        return m_minPoint.m_x < m_maxPoint.m_x &&
            m_minPoint.m_y < m_maxPoint.m_y;
    }

    bool BoundingBox2D::IsPointWithinBounds(const Vector2f& point) const
    {
        return point.m_x >= m_minPoint.m_x && point.m_y >= m_minPoint.m_y &&
            point.m_x < m_maxPoint.m_x && point.m_y < m_maxPoint.m_y;
    }

    Vector2f BoundingBox2D::GetDimensions() const
    {
        return m_dimensions;
    }

    Vector2f BoundingBox2D::GetMinPoint() const
    {
        return m_minPoint;
    }

    Vector2f BoundingBox2D::GetMaxPoint() const
    {
        return m_maxPoint;
    }
} // namespace Uni::Math