#pragma once
#include "Actor.inl"
#include "Object.inl"
#include "Vec3.inl"
namespace HG_PHYSICS_ENGINE
{
	template<typename T> class Spring : public Actor<T>
	{
		T k;
		T l;
		Object<T>* objects[2];
	public:
		Spring() = delete;
		Spring(T k_constant, T idle_length, Object<T>* a, Object<T>* b) : k(k_constant), l(idle_length)
		{
			objects[0] = a;
			objects[1] = b;
		}
		Spring(const Spring<T>& spring) : k(spring.k), l(spring.l)
		{
			objects[0] = a;
			objects[1] = b;
		}
		Spring<T> operator = (const Spring<T>& spring)
		{
			k = spring.k;
			l = spring.l;
			objects[0] = spring.objects[0];
			objects[1] = spring.objects[1];
		}
		void apply(const T& delta_time)
		{
			const HG_MATH::Vec3<T> force_dir = objects[0]->get_postion() - objects[1]->get_postion();
			const T length = force_dir.length();
			const T x = l - length;
			const HG_MATH::Vec3<T> force = force_dir*(x*k/length);
			objects[0]->add_force(force);
			objects[1]->add_force(force*T(-1));
		}
	};
}