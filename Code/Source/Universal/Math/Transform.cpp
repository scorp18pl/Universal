#include <Universal/Math/Transform.h>

namespace Uni::Math
{
    Transform::Transform(
        Uni::Math::Matrix3x4f rotation,
        Uni::Math::Vector3f scale,
        Uni::Math::Vector3f translation)
        : m_scale(scale)
        , m_transform(rotation)
        , m_translation(translation)
    {
        UpdateTransform();
    }

    const Matrix3x4f& Transform::GetMatrix() const
    {
        return m_transform;
    }

    const Vector3f& Transform::GetTranslation() const
    {
        return m_translation;
    }

    const Matrix3x4f& Transform::GetRotation() const
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
        transform.UpdateTransform();

        return transform;
    }

    void Transform::SetTranslation(const Vector3f& translation)
    {
        m_translation = translation;
        UpdateTransform();
    }

    void Transform::SetRotation(const Matrix3x4f& rotation)
    {
        m_rotation = rotation;
        UpdateTransform();
    }

    void Transform::SetScale(const Vector3f& scale)
    {
        m_scale = scale;
        UpdateTransform();
    }

    void Transform::SetParent(Transform* parent)
    {
        m_parent = parent;
    }

    void Transform::Translate(const Vector3f& translation)
    {
        m_translation += translation;
        UpdateTransform();
    }

    void Transform::Rotate(const Matrix3x4f& rotation)
    {
        m_rotation = rotation * m_rotation;
        UpdateTransform();
    }

    void Transform::Scale(const Vector3f& scale)
    {
        m_scale *= scale;
        UpdateTransform();
    }

    void Transform::UpdateTransform()
    {
        m_transform = Matrix3x4f::CreateFromTranslation(m_translation) *
            m_rotation * Matrix3x4f::CreateFromScale(m_scale);
    }
} // namespace Uni::Math