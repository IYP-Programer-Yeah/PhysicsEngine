#pragma once
#include <cmath>
namespace HG_MATH
{
	template<typename T> class Vec3
	{
	public:
		union
		{
			struct
			{
				T x, y, z;
			};
		};
		Vec3() = default;
		Vec3(const Vec3<T>& vector) : x(vector.x), y(vector.y), z(vector.z) {}
		Vec3(const T& ix, const T& iy, const T& iz) : x(ix), y(iy), z(iz) {}
		Vec3(const T& i) : x(i), y(i), z(i) {}
		Vec3<T>& operator = (const Vec3<T>& vector)
		{
			x = vector.x;
			y = vector.y;
			z = vector.z;
			return *this;
		}
		Vec3<T> operator + (const Vec3<T>& b) const
		{
			return Vec3<T>(x + b.x, y + b.y, z + b.y);
		}
		Vec3<T> operator - (const Vec3<T>& b) const
		{
			return Vec3<T>(x - b.x, y - b.y, z - b.z);
		}
		Vec3<T> operator * (const T& b) const
		{
			return Vec3<T>(x*b, y*b, z*b);
		}
		Vec3<T> operator / (const T& b) const
		{
			return Vec3<T>(x / b, y / b, z / b);
		}
		T squared_length() const
		{
			return x*x + y*y + z*z;
		}
		T length() const
		{
			return std::sqrt(x*x + y*y + z*z);
		}
		void normalize()
		{
			T l = length();
			x = x / l;
			y = y / l;
			z = z / l;
		}
	};
}