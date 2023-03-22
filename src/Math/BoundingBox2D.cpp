#include <Math/BoundingBox2D.h>
#include <algorithm>

namespace Uni::Math
{
    BoundingBox2D BoundingBox2D::CreateFromDimensions(
        const Vector2f& minPoint, const Vector2f& dimensions)
    {
        return { minPoint, dimensions };
    }

    BoundingBox2D BoundingBox2D::CreateFromPoints(
        const Vector2f& startPoint, const Vector2f& endPoint)
    {
        const Vector2f minPoint{
            startPoint.m_x < endPoint.m_x ? startPoint.m_x : endPoint.m_x,
            startPoint.m_y < endPoint.m_y ? startPoint.m_y : endPoint.m_y,
        };

        const Vector2f maxPoint{
            startPoint.m_x > endPoint.m_x ? startPoint.m_x : endPoint.m_x,
            startPoint.m_y > endPoint.m_y ? startPoint.m_y : endPoint.m_y,
        };

        return BoundingBox2D{ minPoint, maxPoint - minPoint };
    }

    BoundingBox2D::BoundingBox2D()
        : m_minPoint{ Vector2f::CreateZero() }
        , m_maxPoint{ Vector2f::CreateZero() }
        , m_dimensions{ Vector2f::CreateZero() }
    {
    }

    BoundingBox2D::BoundingBox2D(
        const Vector2f& minPoint, const Vector2f& dimensions)
        : m_minPoint{ minPoint }
        , m_maxPoint{ minPoint + dimensions }
        , m_dimensions{ dimensions }
    {
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