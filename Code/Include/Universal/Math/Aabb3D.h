#pragma once

#include <Universal/Math/Vector/Vector3f.h>
#include <vector>

namespace Uni::Math
{
    //! A 3D bounding box class.
    //! The box is defined by a minimum point and a maximum point.
    class Aabb3D
    {
    public:
        static Aabb3D CreateInvalid();
        static Aabb3D CreateFromDimensions(
            const Vector3f& origin, const Vector3f& dimensions);
        static Aabb3D CreateFromPoints(
            const std::vector<Vector3f>& points);

        Aabb3D();
        Aabb3D(const Vector3f& origin, const Vector3f& dimensions);
        Aabb3D(const Aabb3D& other) = default;
        Aabb3D(Aabb3D&& other) = default;
        ~Aabb3D() = default;

        //! The Bounding box is valid if the minimum point is less than the
        //! maximum point.
        [[nodiscard]] bool IsValid() const;
        [[nodiscard]] bool IsPointWithinBounds(const Vector3f& point) const;

        [[nodiscard]] Vector3f GetDimensions() const;
        [[nodiscard]] Vector3f GetMinPoint() const;
        [[nodiscard]] Vector3f GetMaxPoint() const;

        Aabb3D& operator=(const Aabb3D& other) = default;

    private:
        Vector3f m_origin, m_dimensions;
    };

} // namespace Uni::Math
