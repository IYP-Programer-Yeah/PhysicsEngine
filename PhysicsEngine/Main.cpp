#include "Engine.inl"
#include "Object.inl"
#include "Spring.inl"
#include <iostream>
int main()
{
	HG_PHYSICS_ENGINE::Engine<long double> engine;
	HG_PHYSICS_ENGINE::Object<long double> a(100.0l, true, HG_MATH::Vec3<long double>(0.0l), HG_MATH::Vec3<long double>(0.0l), HG_MATH::Vec3<long double>(0.0l));
	HG_PHYSICS_ENGINE::Object<long double> b(100.0l, true, HG_MATH::Vec3<long double>(1.0l, 0.0l, 0.0l), HG_MATH::Vec3<long double>(0.0l), HG_MATH::Vec3<long double>(0.0l));
	HG_PHYSICS_ENGINE::Object<long double> c(1.0l, true, HG_MATH::Vec3<long double>(0.2l, 0.0l, 0.0l), HG_MATH::Vec3<long double>(0.0l), HG_MATH::Vec3<long double>(0.0l));
	engine.add_object(&a);
	engine.add_object(&b);
	engine.add_object(&c);
	HG_PHYSICS_ENGINE::Spring<long double> spring_a(0.5l, 0.5l, &a, &c);
	HG_PHYSICS_ENGINE::Spring<long double> spring_b(0.5l, 0.5l, &b, &c);
	engine.add_actor(&spring_a);
	engine.add_actor(&spring_b);
	for (long double i = 0.0l; i < 60.0l; i += 0.001)
	{
		std::cout << "Time: " << i << "\n";
		auto p = c.get_postion();
		std::cout << "C position: x: " << p.x << " y: " << p.y << " z: " << p.z << "\n";
		engine.update(0.001l);
	}
	int wait;
	std::cin >> wait;
	return 0;
}