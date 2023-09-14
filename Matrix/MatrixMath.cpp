#include <climits>
#include "Vector.h"
#include "Matrix.h"
#include "MatrixMath.h"
#include <cstdint>

// sse2
#include <emmintrin.h>

int DotProduct(const Vector4& v1, const Vector4& v2)
{
	// convert the vectors to float
	float v1Ptr[4];
	for (int i = 0; i < 4; i++)
	{
		v1Ptr[i] = (float)v1[i];
	}
	float v2Ptr[4];
	for (int i = 0; i < 4; i++)
	{
		v2Ptr[i] = (float)v2[i];
	}
	
	// load the vectors into SIMD registers
	__m128 v1Reg = _mm_loadu_ps(v1Ptr);
	__m128 v2Reg = _mm_loadu_ps(v2Ptr);
	
	// multiply the vectors
	__m128 result = _mm_mul_ps(v1Reg, v2Reg);
	
	// add the results
	__m128 temp = _mm_shuffle_ps(result, result, _MM_SHUFFLE(2, 3, 0, 1));
	result = _mm_add_ps(result, temp);
	temp = _mm_shuffle_ps(result, result, _MM_SHUFFLE(1, 0, 3, 2));
	result = _mm_add_ps(result, temp);
	
	// store the result
	float resultPtr[4];
	_mm_storeu_ps(resultPtr, result);
	
	// return the result
	return (int)resultPtr[0];
	

}

Vector4 Multiply(const Matrix4& m, const Vector4& v)
{
	Vector4 result(0);

	// calculate the dot product of each row of the matrix with the vector
	result.x = DotProduct(m.v[0], v);
	result.y = DotProduct(m.v[1], v);
	result.z = DotProduct(m.v[2], v);
	result.w = DotProduct(m.v[3], v);

	return result;
}

Matrix4 Multiply(const Matrix4& m1, const Matrix4& m2)
{
	Matrix4 result(0);

	// go through each row of m1
	for (int i = 0; i < 4; ++i)
	{
		// go through each column of m2
		for (int j = 0; j < 4; ++j)
		{

			// create vectors from the row and column
			Vector4 v1(m1.v[i][0], m1.v[i][1], m1.v[i][2], m1.v[i][3]);
			Vector4 v2(m2.v[0][j], m2.v[1][j], m2.v[2][j], m2.v[3][j]);
			
			// calculate the dot product of the row and column
			result.v[i][j] = (int)DotProduct(v1, v2);
			
	
		}
	}

	return result;
}
