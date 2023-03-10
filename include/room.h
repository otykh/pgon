#pragma once

#include <vector>
#include <memory>
#include "object.h"

class Object;

// exists as a container for objects and entities
// could be described as a scene
// objects could travel in and out and here where all the entities are kept
struct Room
{
	Object* owner; //sets the owner of this room, can be null
	std::vector<Object*> objects;

	Room(Object* owner);
	~Room();
	void Enter(Object*);
	void Exit(Object*);
};
