#pragma once
#include "Vec3.inl"
namespace HG_PHYSICS_ENGINE
{
	template<typename T> class Object
	{
		T m;
		HG_MATH::Vec3<T> p;
		HG_MATH::Vec3<T> f;
		HG_MATH::Vec3<T> v;
		bool movable;
	public:
		Object() = delete;
		Object(const T& mass, bool imovable/* = true*/, const HG_MATH::Vec3<T>& position/* = HG_MATH::Vec3<T>(T(0))*/, const HG_MATH::Vec3<T>& force/* = HG_MATH::Vec3<T>&(T(0))*/, const HG_MATH::Vec3<T>& velocity/* = HG_MATH::Vec3<T>(T(0))*/) : m(mass), movable(imovable), v(velocity), f(force), p(position) {}
		Object(const Object& object) : m(object.m), v(object.v), f(object.f), p(object.p), movable(object.movable){}
		Object& operator = (const Object& object)
		{
			m = object.m;
			p = object.p;
			f = object.f;
			v = object.v;
			movable = object.movable;
		}
		void update(const T& delta_time)
		{
			if (movable)
			{
				const HG_MATH::Vec3<T> new_v(v + f*(m*delta_time));
				p = p + (v + new_v)*(delta_time / T(2));
				v = new_v;
				f = HG_MATH::Vec3<T>(T(0));
			}
		}
		T get_mass() const
		{
			return m;
		}
		void set_mass(const T& mass)
		{
			m = mass;
		}
		HG_MATH::Vec3<T> get_postion() const
		{
			return p;
		}
		void set_position(const HG_MATH::Vec3<T>& position)
		{
			p = position;
		}
		void add_force(const HG_MATH::Vec3<T>& force)
		{
			f = f + force;
		}
		void set_movable(bool imovable)
		{
			movable = imovable;
		}
		bool get_movable() const
		{
			return movable;
		}
	};
}