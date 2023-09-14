#include "gtest/gtest.h"

#include "Vector.h"
#include "MatrixMath.h"

TEST(DotProduct, Vector0_dot_Vector0_Expects_0) {
	Vector4 v1(0);
	Vector4 v2(0);

	auto r1 = DotProduct(v1, v2);

	EXPECT_EQ(r1, 0);
}

TEST(DotProduct, Vector1_dot_Vector0_Expects_0) {
	Vector4 v1(1);
	Vector4 v2(0);

	auto r1 = DotProduct(v1, v2);

	EXPECT_EQ(r1, 0);
}

TEST(DotProduct, Vector1_dot_Vector1_Expects_4) {
	Vector4 v1(1);
	Vector4 v2(1);

	auto r1 = DotProduct(v1, v2);

	EXPECT_EQ(r1, 4);
}

TEST(DotProduct, VectorNegative1_dot_Vector1_Expects_Negative4) {
	Vector4 v1(-1);
	Vector4 v2(1);

	auto r1 = DotProduct(v1, v2);

	EXPECT_EQ(r1, -4);
}

TEST(DotProduct, V1_dot_V2_Expects_2) {
	Vector4 v1(-1, 1, 1, 1);
	Vector4 v2(1);

	auto r1 = DotProduct(v1, v2);

	EXPECT_EQ(r1, 2);
}

TEST(DotProduct, V1s_dot_V2_Expects_0) {
	Vector4 v1(-1, 1, -1, 1);
	Vector4 v2(1);

	auto r1 = DotProduct(v1, v2);

	EXPECT_EQ(r1, 0);
}

TEST(DotProduct, V1234_dot_V0_Expects_10) {
	Vector4 v1(1, 2, 3, 4);
	Vector4 v2(1);

	auto r1 = DotProduct(v1, v2);

	EXPECT_EQ(r1, 10);
}

TEST(DotProduct, V_123_4_dot_V2_Expects_0) {
	Vector4 v1(-1, 2, 3, -4);
	Vector4 v2(1);

	auto r1 = DotProduct(v1, v2);

	EXPECT_EQ(r1, 0);
}

TEST(DotProduct, V1_dot_V2_Expects_6) {
	Vector4 v1(1, -2, 3, 4);
	Vector4 v2(1);

	auto r1 = DotProduct(v1, v2);

	EXPECT_EQ(r1, 6);
}

TEST(DotProduct, V1_dot_V2_Expects_36) {
	Vector4 v1(1, -2, 3, 4);
	Vector4 v2(-5, 6, 7, 8);

	auto r1 = DotProduct(v1, v2);

	EXPECT_EQ(r1, 36);
}

TEST(DotProduct, V2_dot_V1_Expects_36) {
	Vector4 v1(1, -2, 3, 4);
	Vector4 v2(-5, 6, 7, 8);

	auto r1 = DotProduct(v2, v1);

	EXPECT_EQ(r1, 36);
}

TEST(DotProduct, TestCommutativity_Expects_IsCommutative) {
	Vector4 v1(1, -2, 3, 4);
	Vector4 v2(-5, 6, 7, 8);

	auto r1 = DotProduct(v1, v2);
	auto r2 = DotProduct(v2, v1);

	EXPECT_EQ(r1, r2);
}
