#pragma once

struct Vector4;
struct Matrix4;

int DotProduct(const Vector4& v1, const Vector4& v2);
Vector4 Multiply(const Matrix4& m, const Vector4& v);
Matrix4 Multiply(const Matrix4& m1, const Matrix4& m2);
