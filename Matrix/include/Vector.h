#pragma once

struct Vector4
{
	Vector4(int i);
	Vector4(int x, int y, int z, int w);

	int& operator[](unsigned int i);
	int operator[](unsigned int i) const;
	bool operator==(const Vector4&) const;

#if defined (_MSC_VER)
#pragma warning(push, 3)
#pragma warning(disable:4201)
#endif
	union
	{
		int a[4] = { 0 };
		struct
		{
			int x;
			int y;
			int z;
			int w;
		};
	};
#if defined (_MSC_VER)
#pragma warning(default:4201)
#pragma warning(pop)
#endif
};
