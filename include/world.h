#pragma once

#include "creature.h"
#include "city.h"
#include "room.h"

#include <stdlib.h>
#include <time.h>
#include <vector>
#include <memory>

// entities:
#include "e/shrine.h"

class World
{
public:
	static int seed;

private:
	static std::shared_ptr<Object> player;

	static std::vector<std::shared_ptr<Object>> object_list;
	static std::vector<std::shared_ptr<City>> city_list;
	static std::vector<std::shared_ptr<Room>> room_list;

	static void NameEverythingInTheRoom(const Room* room, const Object* caller);
	static Object* ReturnObjectNamedInRoom(const std::string name, const Room* room);
public:
	// initialise the world
	static void init();
	static int MakeNewCity();
	static int AddNewCity(std::shared_ptr<City> cityPointer);
	static int AddNewObject(std::shared_ptr<Object> object);
	template<typename lambda>
	static void CallObjectFunctionFromPlayer(const std::string& objName, const lambda& func);

	static void PlayerMove(const char& dir);
	static void PlayerLookAtObject(const std::string& objName);
	static void PlayerEnterObject(const std::string& objName);
	static void PlayerTouchObject(const std::string& objName);
	static void PlayerUseObject(const std::string& objName);
	static void PlayerPickUpObject(const std::string& objName);
	static void PlayerOpenObject(const std::string& objName);
	static void PlayerCloseObject(const std::string& objName);
	static void PlayerUnlockObject(const std::string& objName);
	static void PlayerTalkToObject(const std::string& objName);

	static void GetPlayerInput();

	~World();
};
