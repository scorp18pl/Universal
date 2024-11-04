#include <Universal/Math/Math.h>
#include <Universal/Math/Matrix/Matrix3x3f.h>
#include <cmath>
#include <gtest/gtest.h>

using Uni::Math::Matrix3x3f;
using Uni::Math::Vector3f;
using Uni::Math::Vector4f;

static constexpr float epsilon = 1.0e-5f;

TEST(Matrix3x3fTest, CreateIdentity)
{
    Matrix3x3f identity = Matrix3x3f::CreateIdentity();
    for (size_t row = 0; row < 3; ++row)
    {
        for (size_t col = 0; col < 3; ++col)
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

TEST(Matrix3x3fTest, CreateFromRowMajorFloats)
{
    float values[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    Matrix3x3f matrix = Matrix3x3f::CreateFromRowMajorFloats(values);

    // Check that the matrix was created correctly
    for (size_t row = 0; row < 3; ++row)
    {
        for (size_t col = 0; col < 3; ++col)
        {
            EXPECT_FLOAT_EQ(
                matrix.GetRow(row).m_data[col], values[row * 3 + col]);
        }
    }
}

TEST(Matrix3x3fTest, MatrixMultiplication)
{
    float valuesA[9] = {
        1, 2, 3, 4, 5, 6, 7, 8, 9,
    };
    Matrix3x3f matrixA = Matrix3x3f::CreateFromRowMajorFloats(valuesA);

    float valuesB[9] = {
        -1, 0, 1, 2, -2, 1, 0, -1, 1,
    };
    Matrix3x3f matrixB = Matrix3x3f::CreateFromRowMajorFloats(valuesB);

    Matrix3x3f resultMatrix = matrixA * matrixB;

    // Check that the matrices were multiplied correctly
    float expectedValues[9] = { 3.0f,  -7.0f, 6.0f,   6.0f, -16.0f,
                                15.0f, 9.0f,  -25.0f, 24.0f };

    for (size_t row = 0; row < 3; ++row)
    {
        for (size_t col = 0; col < 3; ++col)
        {
            EXPECT_NEAR(
                resultMatrix.GetRow(row).m_data[col],
                expectedValues[row * 3 + col],
                epsilon);
        }
    }
}

TEST(Matrix3x3fTest, OperatorParentheses)
{
    float values[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    Matrix3x3f matrix = Matrix3x3f::CreateFromRowMajorFloats(values);

    // Check that the values are accessed correctly using operator()
    for (size_t row = 0; row < 3; ++row)
    {
        for (size_t col = 0; col < 3; ++col)
        {
            EXPECT_FLOAT_EQ(
                matrix.GetRow(row).m_data[col], values[row * 3 + col]);
        }
    }
}

TEST(Matrix3x3fTest, Determinant)
{
    float values[9] = { 2.0f, -3.0f,  1.0f,
                        2.0f, 0.0f, -1.0f,
                        1.0f, 4.0f, 5.0f };
    Matrix3x3f matrix = Matrix3x3f::CreateFromRowMajorFloats(values);

    const float determinant = matrix.GetDeterminant();

    EXPECT_NEAR(determinant, 49.0f, epsilon);
}

TEST(Matrix3x3fTest, Inverse)
{
    Vector3f v = { 1.0f, 2.0f, 3.0f };

    float values[9] = { 6.0f, 2.0f,  40.0f,
                        0.0f, 2.0f, 0.0f,
                        0.0f, 35.0f, -4.0f };
    Matrix3x3f matrix = Matrix3x3f::CreateFromRowMajorFloats(values);

    Vector3f v1 = matrix * v;
    Vector3f v2 = matrix.GetInverse() * v1;

    EXPECT_NEAR(v.m_x, v2.m_x, epsilon);
    EXPECT_NEAR(v.m_y, v2.m_y, epsilon);
    EXPECT_NEAR(v.m_z, v2.m_z, epsilon);
}
