#include <Universal/Math/Aabb3D.h>

namespace Uni::Math
{
    Aabb3D Aabb3D::CreateInvalid()
    {
        return { Vector3f{ 1.0f }, Vector3f{ -1.0f } };
    }

    Aabb3D Aabb3D::CreateFromDimensions(
        const Vector3f& minPoint, const Vector3f& dimensions)
    {
        return { minPoint, dimensions };
    }

    Aabb3D Aabb3D::CreateFromPoints(const std::vector<Vector3f>& points)
    {
        if (points.empty())
        {
            return Aabb3D::CreateInvalid();
        }

        Vector3f minPoint, maxPoint;
        minPoint = maxPoint = points[0];
        for (auto& point : points)
        {
            minPoint.m_x = std::min(minPoint.m_x, point.m_x);
            minPoint.m_y = std::min(minPoint.m_y, point.m_y);
            minPoint.m_z = std::min(minPoint.m_z, point.m_z);
            maxPoint.m_x = std::max(maxPoint.m_x, point.m_x);
            maxPoint.m_y = std::max(maxPoint.m_y, point.m_y);
            maxPoint.m_z = std::max(maxPoint.m_z, point.m_z);
        }

        return Aabb3D{ minPoint, maxPoint - minPoint };
    }

    Aabb3D::Aabb3D() { (*this) = CreateInvalid(); }

    Aabb3D::Aabb3D(const Vector3f& origin, const Vector3f& dimensions)
        : m_origin{ origin }
        , m_dimensions{ dimensions }
    {
    }

    bool Aabb3D::IsValid() const
    {
        return m_dimensions.m_x > 0.0f && m_dimensions.m_y > 0.0f &&
            m_dimensions.m_z > 0.0f;
    }

    bool Aabb3D::IsPointWithinBounds(const Vector3f& point) const
    {
        return point.m_x >= m_origin.m_x && point.m_y >= m_origin.m_y &&
            point.m_z >= m_origin.m_z &&
            point.m_x < m_origin.m_x + m_dimensions.m_x &&
            point.m_y < m_origin.m_y + m_dimensions.m_y &&
            point.m_z < m_origin.m_z + m_dimensions.m_z;
    }

    Vector3f Aabb3D::GetDimensions() const { return m_dimensions; }

    Vector3f Aabb3D::GetMinPoint() const { return m_origin; }

    Vector3f Aabb3D::GetMaxPoint() const { return m_origin + m_dimensions; }
} // namespace Uni::Math