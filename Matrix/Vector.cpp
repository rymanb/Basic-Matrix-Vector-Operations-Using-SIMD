#include <cassert>
#include "Vector.h"

Vector4::Vector4(int i) : x(i), y(i), z(i), w(i) {}

Vector4::Vector4(int X, int Y, int Z, int W) : x(X), y(Y), z(Z), w(W) {}

int& Vector4::operator[](unsigned int i)
{
	assert(i < 4);
	return a[i];
}

int Vector4::operator[](unsigned int i) const
{
	assert(i < 4);
	return a[i];
}

bool Vector4::operator==(const Vector4& rhs) const
{
	for (int i = 0; i < 4; ++i)
	{
		if (a[i] != rhs.a[i])
		{
			return false;
		}
	}

	return true;
}
