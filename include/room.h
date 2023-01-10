#pragma once

#include <vector>
#include <memory>
#include "object.h"

class Object;
class City;

// exists as a container for objects and entities
// could be described as a scene
// objects could travel in and out and here where all the entities are kept
// default room, connected by doors
struct Room
{
	Object* owner; //sets the owner of this room, can be null
	std::vector<Object*> objects;

	Room(Object* owner);
	~Room();
	void Enter(Object*);
	void Exit(Object*);
	virtual bool isCityMember() { return false; };
};
// city room, has origin and position, I call this a city BLOCK
// still has an owner like mayor etc.
struct CityBlock : Room
{
	City* cityOrigin; // can be null
	const int x;
	const int y;
	CityBlock(City* city, Object* owner, int x, int y);
	bool isCityMember() override { return true; };
};
