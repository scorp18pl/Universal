#include <Universal/Math/Math.h>
#include <Universal/Math/Matrix/Matrix3x4f.h>
#include <cmath>
#include <gtest/gtest.h>

using Uni::Math::Axis;
using Uni::Math::Matrix3x4f;
using Uni::Math::Vector3f;
using Uni::Math::Vector4f;

static constexpr float epsilon = 1.0e-6f;

TEST(Matrix3x4fTest, CreateIdentity)
{
    Matrix3x4f identity = Matrix3x4f::CreateIdentity();
    for (size_t row = 0; row < 3; ++row)
    {
        for (size_t col = 0; col < 4; ++col)
        {
            if (row == col)
            {
                EXPECT_NEAR(identity.GetRow(row).m_data[col], 1.0f, epsilon);
            }
            else
            {
                EXPECT_NEAR(identity.GetRow(row).m_data[col], 0.0f, epsilon);
            }
        }
    }
}

TEST(Matrix3x4fTest, CreateRotationEulerRadians)
{
    float angle = Uni::Math::Constants::PI / 2.0f; // 90 degrees in radians
    Matrix3x4f matrix = Matrix3x4f::CreateRotationEulerRadians(angle, Axis::Z);

    // Check that the matrix represents the correct rotation
    EXPECT_FLOAT_EQ(matrix.GetRow(0).m_data[0], std::cos(angle));
    EXPECT_FLOAT_EQ(matrix.GetRow(0).m_data[1], -std::sin(angle));
    EXPECT_FLOAT_EQ(matrix.GetRow(1).m_data[0], std::sin(angle));
    EXPECT_FLOAT_EQ(matrix.GetRow(1).m_data[1], std::cos(angle));
}

TEST(Matrix3x4fTest, CreateRotationEulerDegrees)
{
    float angle = 45.0f; // 45 degrees
    Matrix3x4f matrix = Matrix3x4f::CreateRotationEulerDegrees(angle, Axis::Z);

    float angleRadians = angle * Uni::Math::Constants::PI / 180.0f;

    // Check that the matrix represents the correct rotation
    EXPECT_FLOAT_EQ(matrix.GetRow(0).m_data[0], std::cos(angleRadians));
    EXPECT_FLOAT_EQ(matrix.GetRow(0).m_data[1], -std::sin(angleRadians));
    EXPECT_FLOAT_EQ(matrix.GetRow(1).m_data[0], std::sin(angleRadians));
    EXPECT_FLOAT_EQ(matrix.GetRow(1).m_data[1], std::cos(angleRadians));
}

TEST(Matrix3x4fTest, CreateScale)
{
    Vector3f scale(2.0f, 3.0f, 4.0f);
    Matrix3x4f matrix = Matrix3x4f::CreateScale(scale);

    const Vector3f scaledVector = matrix * Vector3f(1.0f, 1.0f, 1.0f);

    // Check that the matrix represents the correct scaling
    ASSERT_NEAR(scaledVector.m_x, scale.m_x, epsilon);
    ASSERT_NEAR(scaledVector.m_y, scale.m_y, epsilon);
    ASSERT_NEAR(scaledVector.m_z, scale.m_z, epsilon);
}

TEST(Matrix3x4fTest, CreateFromRowMajorFloats)
{
    float values[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
    Matrix3x4f matrix = Matrix3x4f::CreateFromRowMajorFloats(values);

    // Check that the matrix was created correctly
    for (size_t row = 0; row < 3; ++row)
    {
        for (size_t col = 0; col < 4; ++col)
        {
            EXPECT_FLOAT_EQ(
                matrix.GetRow(row).m_data[col], values[row * 4 + col]);
        }
    }
}

TEST(Matrix3x4fTest, TransformVector3f)
{
    Matrix3x4f scaleMatrix = Matrix3x4f::CreateScale({ 2.0f, 3.0f, 4.0f });
    Vector3f vector(1.0f, 2.0f, 3.0f);
    Vector3f transformedVector = scaleMatrix * vector;

    // Check that the vector was transformed correctly
    EXPECT_NEAR(transformedVector.m_x, vector.m_x * 2.0f, epsilon);
    EXPECT_NEAR(transformedVector.m_y, vector.m_y * 3.0f, epsilon);
    EXPECT_NEAR(transformedVector.m_z, vector.m_z * 4.0f, epsilon);
}

TEST(Matrix3x4fTest, TransformVector4f)
{
    Matrix3x4f translationMatrix =
        Matrix3x4f::CreateTranslation({ 1.0f, 2.0f, 3.0f });
    Vector4f vector(1.0f, 2.0f, 3.0f, 1.0f);
    Vector4f transformedVector = translationMatrix * vector;

    // Check that the vector was transformed correctly
    EXPECT_NEAR(transformedVector.m_x, vector.m_x + 1.0f, epsilon);
    EXPECT_NEAR(transformedVector.m_y, vector.m_y + 2.0f, epsilon);
    EXPECT_NEAR(transformedVector.m_z, vector.m_z + 3.0f, epsilon);
    EXPECT_NEAR(transformedVector.m_w, vector.m_w, epsilon);
}

TEST(Matrix3x4fTest, MatrixMultiplication)
{
    float valuesA[12] = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,
    };
    Matrix3x4f matrixA = Matrix3x4f::CreateFromRowMajorFloats(valuesA);

    float valuesB[12] = {
        -1, 0, 1, 2, -2, 1, 0, -1, 1, -1, 0, 1,
    };
    Matrix3x4f matrixB = Matrix3x4f::CreateFromRowMajorFloats(valuesB);

    Matrix3x4f resultMatrix = matrixA * matrixB;

    // Check that the matrices were multiplied correctly
    float expectedValues[12] = {
        -2, -1, 1, 7, -10, -1, 5, 19, -18, -1, 9, 31,
    };
    for (size_t row = 0; row < 3; ++row)
    {
        for (size_t col = 0; col < 4; ++col)
        {
            EXPECT_NEAR(
                resultMatrix.GetRow(row).m_data[col],
                expectedValues[row * 4 + col],
                epsilon);
        }
    }
}

TEST(Matrix3x4fTest, OperatorParentheses)
{
    float values[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };

    Matrix3x4f matrix = Matrix3x4f::CreateFromRowMajorFloats(values);

    // Check that the values are accessed correctly using operator()
    for (size_t row = 0; row < 3; ++row)
    {
        for (size_t col = 0; col < 4; ++col)
        {
            EXPECT_FLOAT_EQ(
                matrix.GetRow(row).m_data[col], values[row * 4 + col]);
        }
    }
}

TEST(Matrix3x4fTest, RotateAndTranslate)
{
    float angle = 90.0f; // 45 degrees
    Matrix3x4f rotationMatrix1 =
        Matrix3x4f::CreateRotationEulerDegrees(angle, Axis::Z);

    Matrix3x4f rotationMatrix2 =
        Matrix3x4f::CreateRotationEulerDegrees(angle, Axis::Y);

    Matrix3x4f rotationMatrix3 =
        Matrix3x4f::CreateRotationEulerDegrees(angle, Axis::X);

    Matrix3x4f translationMatrix =
        Matrix3x4f::CreateTranslation({ 1.0f, 2.0f, 3.0f });

    Matrix3x4f combinedMatrix =
        translationMatrix * rotationMatrix3 * rotationMatrix2 * rotationMatrix1;

    Vector3f vector(1.0f, 0.0f, 0.0f);
    Vector3f transformedVector = combinedMatrix * vector;

    // Check that the vector was rotated and translated correctly
    EXPECT_NEAR(transformedVector.m_x, 1.0f, epsilon);
    EXPECT_NEAR(transformedVector.m_y, 2.0f, epsilon);
    EXPECT_NEAR(transformedVector.m_z, 4.0f, epsilon);
}