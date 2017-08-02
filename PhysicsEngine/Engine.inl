#pragma once
#include "Actor.inl"
#include "Object.inl"
#include "Vec3.inl"
#include <set>
namespace HG_PHYSICS_ENGINE
{
	template<typename T> class Engine
	{
		std::set<Actor<T>*> actors;
		std::set<Object<T>*> objects;
		T current_engine_time;
	public:
		Engine() : current_engine_time(0) {}
		Engine(const std::set<Actor<T>*>& iactors, const std::set<Object<T>*>& iobjects) : current_engine_time(0), actors(iactors), objects(iobjects) {}
		Engine(const Engine& engine) : current_engine_time(engine.current_engine_time), actors(engine.actors), objects(engine.objects) {}
		Engine(Engine&& engine) : current_engine_time(std::move(engine.current_engine_time)), actors(std::move(engine.actors)), objects(std::move(engine.objects)) {}
		
		Engine& operator = (const Engine& engine)
		{
			actors = engine.actors;
			objects = engine.objects;
			current_engine_time = engine.current_engine_time;
		}
		Engine& operator = (Engine&& engine)
		{
			actors = std::move(engine.actors);
			objects = std::move(engine.objects);
			current_engine_time = std::move(engine.current_engine_time);
		}

		T get_current_engine_time() const
		{
			return current_engine_time;
		}

		void update(const T& delta_time)
		{
			current_engine_time = current_engine_time + delta_time;
			for (auto itr = actors.begin(); itr != actors.end(); itr++)
				(**itr).apply(delta_time);
			for (auto itr = objects.begin(); itr != objects.end(); itr++)
				(**itr).update(delta_time);
		}

		void add_object(Object<T>* object)
		{
			objects.emplace(object);
		}
		void add_actor(Actor<T>* actor)
		{
			actors.emplace(actor);
		}

		bool remove_object(Object<T>* object)
		{
			return objects.erase(object) > 0;

		}
		bool remove_actor(Actor<T>* actor)
		{
			return actors.erase(actor) > 0;
		}
	};
}