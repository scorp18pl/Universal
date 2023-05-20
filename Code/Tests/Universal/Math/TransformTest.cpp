#include <Universal/Math/Math.h>
#include <Universal/Math/Transform.h>
#include <gtest/gtest.h>

using namespace Uni::Math;

namespace
{
    Quaternion defaultRotation = Quaternion::CreateIdentity();
    Vector3f defaultScale = { 1.0f, 1.0f, 1.0f };
    Vector3f defaultTranslation = { 0.0f, 0.0f, 0.0f };
} // namespace

class TransformTest : public ::testing::Test
{
protected:
    Transform* transform;

    void SetUp() override
    {
        transform =
            new Transform(defaultRotation, defaultScale, defaultTranslation);
    }

    void TearDown() override
    {
        delete transform;
        transform = nullptr;
    }
};

TEST_F(TransformTest, DefaultConstructorTest)
{
    EXPECT_EQ(transform->GetRotation(), defaultRotation);
    EXPECT_EQ(transform->GetScale(), defaultScale);
    EXPECT_EQ(transform->GetTranslation(), defaultTranslation);
}

TEST_F(TransformTest, ParentNullByDefault)
{
    EXPECT_EQ(transform->GetParent(), nullptr);
}

TEST_F(TransformTest, SetParentTest)
{
    Transform parentTransform;
    transform->SetParent(&parentTransform);
    EXPECT_EQ(transform->GetParent(), &parentTransform);
}

TEST_F(TransformTest, TranslationTest)
{
    Vector3f newTranslation{ 1.0f, 2.0f, 3.0f };
    transform->Translate(newTranslation);
    EXPECT_EQ(transform->GetTranslation(), newTranslation);
}

TEST_F(TransformTest, RotationTest)
{
    Quaternion newRotation =
        Quaternion::CreateFromEulerRadZYX({ 0.0f, 0.0f, Constants::PI / 2.0f });
    transform->Rotate(newRotation);
    EXPECT_EQ(transform->GetRotation(), newRotation);
}

TEST_F(TransformTest, ScaleTest)
{
    Vector3f newScale{ 2.0f, 2.0f, 2.0f };
    transform->Scale(newScale);
    EXPECT_EQ(transform->GetScale(), newScale);
}

TEST_F(TransformTest, GetWorldTransformTest)
{
    // Setup parent transform
    Vector3f parentScale{ 2.0f, 2.0f, 2.0f };
    Quaternion parentRotation =
        Quaternion::CreateFromEulerRadZYX({ 0.0f, 0.0f, Constants::PI });
    Vector3f parentTranslation{ 1.0f, 2.0f, 3.0f };
    Transform parentTransform(parentRotation, parentScale, parentTranslation);
    transform->SetParent(&parentTransform);

    Transform worldTransform = transform->GetWorldTransform();

    // Assert world transform values
    EXPECT_EQ(worldTransform.GetScale(), transform->GetScale() * parentScale);
    EXPECT_EQ(
        worldTransform.GetRotation(),
        transform->GetRotation() * parentRotation);
    EXPECT_EQ(
        worldTransform.GetTranslation(),
        parentTransform.GetTranslation() + transform->GetTranslation());
}