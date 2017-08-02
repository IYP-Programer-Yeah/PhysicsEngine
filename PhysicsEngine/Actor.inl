#pragma once
namespace HG_PHYSICS_ENGINE
{
	template<typename T> class Actor
	{
	public:
		virtual void apply(const T& delta_time) = 0;
	};
}