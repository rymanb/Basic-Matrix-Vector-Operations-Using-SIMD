#include <cassert>
#include "Vector.h"
#include "Matrix.h"

Matrix4::Matrix4(int i)
	: a { i, i, i, i, i, i, i, i, i, i, i, i, i, i, i, i } { }

Matrix4::Matrix4(int i0, int i1, int i2, int i3, int i4, int i5, int i6, int i7, int i8, int i9, int i10, int i11, int i12, int i13, int i14, int i15)
	: a { i0, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15 } { }

int& Matrix4::operator[](unsigned int i)
{
	assert(i < 16);
	return a[i];
}

const int& Matrix4::operator[](unsigned int i) const
{
	assert(i < 16);
	return a[i];
}

bool Matrix4::operator==(const Matrix4& rhs) const
{
	for (int i = 0; i < 16; ++i)
	{
		if (a[i] != rhs.a[i])
		{
			return false;
		}
	}

	return true;
}

Matrix4 Matrix4::Identity()
{
	return Matrix4(
		1, 0, 0, 0, 
		0, 1, 0, 0, 
		0, 0, 1, 0, 
		0, 0, 0, 1);
}
