#pragma once

#include <Universal/Math/Matrix/Matrix3x4f.h>

namespace Uni::Math
{
    //!< Class for storing and manipulating 3D transformations.
    //!< First scale, then rotate, then translate.
    class Transform
    {
    public:
        Transform() = default;
        explicit Transform(
            Uni::Math::Matrix3x4f rotation,
            Uni::Math::Vector3f scale =
                Uni::Math::Vector3f::CreateFromFloat(1.0f),
            Uni::Math::Vector3f translation =
                Uni::Math::Vector3f::CreateFromFloat(0.0f));
        Transform(const Transform& transform) = default;
        Transform(Transform&& transform) = default;
        ~Transform() = default;

        [[nodiscard]] const Matrix3x4f& GetMatrix() const;

        [[nodiscard]] const Vector3f& GetTranslation() const;
        [[nodiscard]] const Matrix3x4f& GetRotation() const;
        [[nodiscard]] const Vector3f& GetScale() const;
        [[nodiscard]] Transform* GetParent() const;
        [[nodiscard]] Transform GetWorldTransform() const;

        void SetTranslation(const Vector3f& translation);
        void SetRotation(const Matrix3x4f& rotation);
        void SetScale(const Vector3f& scale);
        // Do not create circular dependencies!
        // They are not checked for to avoid performance hit.
        void SetParent(Transform* parent);

        void Translate(const Vector3f& translation);
        void Rotate(const Matrix3x4f& rotation);
        void Scale(const Vector3f& scale);

        Transform& operator=(const Transform& transform) = default;

    private:
        // Root transform determines the world space
        Transform* m_parent{ nullptr };

        // Cached transform for faster access
        Matrix3x4f m_transform = Matrix3x4f::CreateIdentity();

        Uni::Math::Vector3f m_scale{ 1.0f, 1.0f, 1.0f };
        Uni::Math::Matrix3x4f m_rotation =
            Uni::Math::Matrix3x4f::CreateIdentity();
        Uni::Math::Vector3f m_translation{ 0.0f, 0.0f, 0.0f };

        void UpdateTransform();
    };
} // namespace Uni::Math
