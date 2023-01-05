#include "creature.h"
#include "city.h"
#include "room.h"

#include <stdlib.h>
#include <time.h>
#include <vector>
#include <memory>

// entities:
#include "e/shrine.h"

#pragma once

class World
{
public:
	static int seed;

private:
	static std::shared_ptr<Object> player;

	static std::vector<std::shared_ptr<Object>> object_list;
	static std::vector<std::shared_ptr<City>> city_list;
	static std::vector<std::shared_ptr<Room>> room_list;

public:
	// initialise the world
	static void init();
	static void NameEverythingInTheRoom(const Room* room, const Object* caller);
	static Object* ReturnObjectNamedInRoom(const std::string name, const Room* room);
	static int MakeNewCity();
	static int AddNewCity(std::shared_ptr<City> cityPointer);
	static int AddNewObject(std::shared_ptr<Object> object);

	static void GetPlayerInput();

	~World();
};
