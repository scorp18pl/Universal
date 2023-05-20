#pragma once

#include <Universal/Math/Quaternion.h>
#include <Universal/Math/Vector/Vector3f.h>

namespace Uni::Math
{
    struct Matrix3x4f;

    //!< Class for storing and manipulating 3D transformations.
    //!< First scale, then rotate, then translate.
    class Transform
    {
    public:
        Transform() = default;
        explicit Transform(
            Quaternion rotation,
            Vector3f scale = Vector3f{ 1.0f },
            Vector3f translation = Vector3f{ 0.0f });
        Transform(const Transform& transform) = default;
        Transform(Transform&& transform) = default;
        ~Transform() = default;

        [[nodiscard]] Matrix3x4f GetMatrix() const;

        [[nodiscard]] const Vector3f& GetTranslation() const;
        [[nodiscard]] const Quaternion& GetRotation() const;
        [[nodiscard]] const Vector3f& GetScale() const;
        [[nodiscard]] Transform* GetParent() const;
        [[nodiscard]] Transform GetWorldTransform() const;

        void SetTranslation(const Vector3f& translation);
        void SetRotation(const Quaternion& rotation);
        void SetScale(const Vector3f& scale);
        // Do not create circular dependencies!
        // They are not checked for to avoid performance hit.
        void SetParent(Transform* parent);

        void Translate(const Vector3f& translation);
        void Rotate(const Quaternion& rotation);
        void Scale(const Vector3f& scale);

        Transform& operator=(const Transform& transform) = default;

    private:
        // Root transform determines the world space
        Transform* m_parent{ nullptr };

        Vector3f m_scale{ 1.0f, 1.0f, 1.0f };
        Quaternion m_rotation = Quaternion::CreateIdentity();
        Vector3f m_translation{ 0.0f, 0.0f, 0.0f };
    };
} // namespace Uni::Math
