#include "gtest/gtest.h"

#include "Vector.h"
#include "Matrix.h"
#include "MatrixMath.h"

TEST(Matrix_Mutliplication, IdentityMatrixTimesZeroMatrix_Expects_ZeroMatrix) {
	const Matrix4 m1 = Matrix4::Identity();
	const Matrix4 m2(0);

	Matrix4 r = Multiply(m1, m2);

	EXPECT_EQ(m2, r);
}

TEST(Matrix_Mutliplication, ZeroMatrixTimesIdentityMatrix_Expects_ZeroMatrix) {
	const Matrix4 m1(0);
	const Matrix4 m2 = Matrix4::Identity();

	Matrix4 r = Multiply(m1, m2);

	EXPECT_EQ(m1, r);
}

TEST(Matrix_Mutliplication, IdentityMatrixTimesIdentityMatrix_Expects_IdentityMatrix) {
	const Matrix4 m1 = Matrix4::Identity();
	const Matrix4 m2 = Matrix4::Identity();

	Matrix4 r = Multiply(m1, m2);

	EXPECT_EQ(Matrix4::Identity(), r);
}

TEST(Matrix_Mutliplication, IdentityMatrixTimesMatrix_Expects_Matrix) {
	const Matrix4 m1 = Matrix4::Identity();
	const Matrix4 m2(1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4);

	Matrix4 r = Multiply(m1, m2);

	EXPECT_EQ(m2, r);
}

TEST(Matrix_Mutliplication, MatrixTimesIdentityMatrix_Expects_Matrix) {
	const Matrix4 m1(1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4);
	const Matrix4 m2 = Matrix4::Identity();

	Matrix4 r = Multiply(m1, m2);

	EXPECT_EQ(m1, r);
}

TEST(Matrix_Mutliplication, MatrixSquared_Expects_MatrixSquared) {
	const Matrix4 m1(1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4);

	Matrix4 r = Multiply(m1, m1);

	const Matrix4 expected(10, 20, 30, 40, 10, 20, 30, 40, 10, 20, 30, 40, 10, 20, 30, 40);

	EXPECT_EQ(expected, r);
}

TEST(Matrix_Mutliplication, MatrixTimesMatrix_Expects_CorrectValues) {
	const Matrix4 m1(1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4);
	const Matrix4 m2(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

	Matrix4 r = Multiply(m1, m2);

	const Matrix4 expected(90, 100, 110, 120, 90, 100, 110, 120, 90, 100, 110, 120, 90, 100, 110, 120);

	EXPECT_EQ(expected, r);
}
