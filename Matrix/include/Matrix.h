#pragma once

struct Matrix4
{
	Matrix4(int i);
	Matrix4(int i0, int i1, int i2, int i3, int i4, int i5, int i6, int i7, int i8, int i9, int i10, int i11, int i12, int i13, int i14, int i15);
	
	int& operator[](unsigned int i);
	const int& operator[](unsigned int i) const;
	bool operator==(const Matrix4& rhs) const;
	static Matrix4 Identity();

	union
	{
		int a[16] = { 0 };
		Vector4 v[4];
		int m[4][4];
	};
};

