#include <Universal/Math/Transform.h>
#include <Universal/Math/Matrix/Matrix3x4f.h>

namespace Uni::Math
{
    Transform::Transform(
        Quaternion rotation,
        Uni::Math::Vector3f scale,
        Uni::Math::Vector3f translation)
        : m_scale(scale)
        , m_rotation(rotation)
        , m_translation(translation)
    {
    }

    Matrix3x4f Transform::GetMatrix() const
    {
        return Matrix3x4f::CreateTranslation(m_translation) *
            m_rotation.GetMatrix() * Matrix3x4f::CreateScale(m_scale);
    }

    const Vector3f& Transform::GetTranslation() const
    {
        return m_translation;
    }

    const Quaternion& Transform::GetRotation() const
    {
        return m_rotation;
    }

    const Vector3f& Transform::GetScale() const
    {
        return m_scale;
    }

    Transform* Transform::GetParent() const
    {
        return m_parent;
    }

    Transform Transform::GetWorldTransform() const
    {
        Transform transform = (*this);
        for (Transform* current = m_parent; current != nullptr;
             current = current->m_parent)
        {
            transform.m_translation = current->m_translation +
                current->m_rotation * transform.m_translation;

            transform.m_rotation = current->m_rotation * transform.m_rotation;
            transform.m_scale *= current->m_scale;
        }

        return transform;
    }

    void Transform::SetTranslation(const Vector3f& translation)
    {
        m_translation = translation;
    }

    void Transform::SetRotation(const Quaternion& rotation)
    {
        m_rotation = rotation;
    }

    void Transform::SetScale(const Vector3f& scale)
    {
        m_scale = scale;
    }

    void Transform::SetParent(Transform* parent)
    {
        m_parent = parent;
    }

    void Transform::Translate(const Vector3f& translation)
    {
        m_translation += translation;
    }

    void Transform::Rotate(const Quaternion& rotation)
    {
        m_rotation = rotation * m_rotation;
    }

    void Transform::Scale(const Vector3f& scale)
    {
        m_scale *= scale;
    }
} // namespace Uni::Math