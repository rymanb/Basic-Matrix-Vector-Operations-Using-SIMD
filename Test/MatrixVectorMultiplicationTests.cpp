#include "gtest/gtest.h"

#include "Vector.h"
#include "Matrix.h"
#include "MatrixMath.h"

TEST(Matrix_Vector_Multiplication, IdentityMatrixTimesVector0_Expects_Vector0) {
	const Matrix4 m = Matrix4::Identity();
	const Vector4 v(0);;

	auto r = Multiply(m, v);

	EXPECT_EQ(r.x, 0);
	EXPECT_EQ(r.y, 0);
	EXPECT_EQ(r.z, 0);
	EXPECT_EQ(r.w, 0);
}

TEST(Matrix_Vector_Multiplication, IdentityMatrixTimesVector1_Expects_Vector1) {
	const Matrix4 m = Matrix4::Identity();
	const Vector4 v(1);

	auto r = Multiply(m, v);

	EXPECT_EQ(r.x, 1);
	EXPECT_EQ(r.y, 1);
	EXPECT_EQ(r.z, 1);
	EXPECT_EQ(r.w, 1);
}

TEST(Matrix_Vector_Multiplication, IdentityMatrixTimesVector_Expects_Vector) {
	const Matrix4 m = Matrix4::Identity();
	const Vector4 v(1, 2, 3, 4);

	auto r = Multiply(m, v);

	EXPECT_EQ(r.x, v.x);
	EXPECT_EQ(r.y, v.y);
	EXPECT_EQ(r.z, v.z);
	EXPECT_EQ(r.w, v.w);
}

TEST(Matrix_Vector_Multiplication, Matrix0TimesV0_Expects_Vector0) {
	const Matrix4 m(0);
	const Vector4 v(0);

	auto r = Multiply(m, v);

	EXPECT_EQ(r.x, 0);
	EXPECT_EQ(r.y, 0);
	EXPECT_EQ(r.z, 0);
	EXPECT_EQ(r.w, 0);
}

TEST(Matrix_Vector_Multiplication, Matrix0TimesVector1_Expects_Vector0) {
	const Matrix4 m(0);
	const Vector4 v(1);

	auto r = Multiply(m, v);

	EXPECT_EQ(r.x, 0);
	EXPECT_EQ(r.y, 0);
	EXPECT_EQ(r.z, 0);
	EXPECT_EQ(r.w, 0);
}

TEST(Matrix_Vector_Multiplication, Matrix1TimesVector0_Expects_Vector0) {
	const Matrix4 m(1);
	const Vector4 v(0);

	auto r = Multiply(m, v);

	EXPECT_EQ(r.x, 0);
	EXPECT_EQ(r.y, 0);
	EXPECT_EQ(r.z, 0);
	EXPECT_EQ(r.w, 0);
}

TEST(Matrix_Vector_Multiplication, Matrix1TimesVector1_Expects_Vector4) {
	const Matrix4 m(1);
	const Vector4 v(1);

	auto r = Multiply(m, v);

	EXPECT_EQ(r.x, 4);
	EXPECT_EQ(r.y, 4);
	EXPECT_EQ(r.z, 4);
	EXPECT_EQ(r.w, 4);
}

TEST(Matrix_Vector_Multiplication, Matrix1TimesVector_Expects_Vector10) {
	const Matrix4 m(1);
	const Vector4 v(1, 2, 3, 4);

	auto r = Multiply(m, v);

	EXPECT_EQ(r.x, 10);
	EXPECT_EQ(r.y, 10);
	EXPECT_EQ(r.z, 10);
	EXPECT_EQ(r.w, 10);
}

TEST(Matrix_Vector_Multiplication, MatrixTimesVector_Expects_CorrectValue1) {
	const Matrix4 m(1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4);
	const Vector4 v(1, 2, 3, 4);

	auto r = Multiply(m, v);

	EXPECT_EQ(r.x, 30);
	EXPECT_EQ(r.y, 30);
	EXPECT_EQ(r.z, 30);
	EXPECT_EQ(r.w, 30);
}

TEST(Matrix_Vector_Multiplication, MatrixTimesVector_Expects_CorrectValue2) {
	const Matrix4 m(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	const Vector4 v(1, 2, 3, 4);

	auto r = Multiply(m, v);

	EXPECT_EQ(r.x, 30);
	EXPECT_EQ(r.y, 70);
	EXPECT_EQ(r.z, 110);
	EXPECT_EQ(r.w, 150);
}
