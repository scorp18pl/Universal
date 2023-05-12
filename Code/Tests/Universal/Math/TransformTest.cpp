#include <Universal/Math/Transform.h>
#include <gtest/gtest.h>

using Uni::Math::Matrix3x4f;
using Uni::Math::Transform;
using Uni::Math::Vector3f;

namespace
{
    const float kTolerance = 1e-6f;

    bool CompareFloat(float a, float b)
    {
        return std::abs(a - b) <= kTolerance;
    }

    bool CompareVector3f(const Vector3f& a, const Vector3f& b)
    {
        return a == b;
    }

    bool CompareMatrix3x4f(const Matrix3x4f& a, const Matrix3x4f& b)
    {
        for (size_t row = 0; row < 3; ++row)
        {
            for (size_t col = 0; col < 4; ++col)
            {
                if (!CompareFloat(a(row, col), b(row, col)))
                {
                    return false;
                }
            }
        }
        return true;
    }

    TEST(TransformTest, DefaultConstructor)
    {
        Transform transform;
        Matrix3x4f identity = Matrix3x4f::CreateIdentity();
        Vector3f one = Vector3f::CreateFromFloat(1.0f);
        Vector3f zero = Vector3f::CreateFromFloat(0.0f);

        EXPECT_TRUE(CompareMatrix3x4f(transform.GetMatrix(), identity));
        EXPECT_TRUE(CompareVector3f(transform.GetScale(), one));
        EXPECT_TRUE(CompareMatrix3x4f(transform.GetRotation(), identity));
        EXPECT_TRUE(CompareVector3f(transform.GetTranslation(), zero));
    }

    TEST(TransformTest, SetTranslation)
    {
        Transform transform;
        Vector3f newPosition(2.0f, 3.0f, 4.0f);
        transform.SetTranslation(newPosition);

        EXPECT_TRUE(CompareVector3f(transform.GetTranslation(), newPosition));
    }

    TEST(TransformTest, SetRotation)
    {
        const float values[12] = { 1.0f,  0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
                                   -1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f };

        Transform transform;
        Matrix3x4f newRotation = Matrix3x4f::CreateFromRowMajorFloats(values);
        transform.SetRotation(newRotation);

        EXPECT_TRUE(CompareMatrix3x4f(transform.GetRotation(), newRotation));
    }

    TEST(TransformTest, SetScale)
    {
        Transform transform;
        Vector3f newScale(2.0f, 3.0f, 4.0f);
        transform.SetScale(newScale);

        EXPECT_TRUE(CompareVector3f(transform.GetScale(), newScale));
    }

    TEST(TransformTest, Translate)
    {
        Transform transform;
        Vector3f translation(2.0f, 3.0f, 4.0f);
        Vector3f initialPosition = transform.GetTranslation();
        transform.Translate(translation);
        Vector3f expectedPosition = initialPosition + translation;

        EXPECT_TRUE(
            CompareVector3f(transform.GetTranslation(), expectedPosition));
    }

    TEST(TransformTest, Rotate)
    {
        const float values[12] = { 1.0f,  0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
                                   -1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f };

        Transform transform;
        Matrix3x4f rotation = Matrix3x4f::CreateFromRowMajorFloats(values);
        Matrix3x4f initialRotation = transform.GetRotation();
        transform.Rotate(rotation);
        Matrix3x4f expectedRotation = rotation * initialRotation;

        EXPECT_TRUE(
            CompareMatrix3x4f(transform.GetRotation(), expectedRotation));
    }

    TEST(TransformTest, Scale)
    {
        Transform transform;
        Vector3f scale(2.0f, 3.0f, 4.0f);
        Vector3f initialScale = transform.GetScale();
        transform.Scale(scale);
        Vector3f expectedScale = Vector3f(
            initialScale.m_x * scale.m_x,
            initialScale.m_y * scale.m_y,
            initialScale.m_z * scale.m_z);

        EXPECT_TRUE(CompareVector3f(transform.GetScale(), expectedScale));
    }
} // namespace