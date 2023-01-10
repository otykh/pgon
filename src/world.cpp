#include "world.h"
#include "playerinput.h"

#include "e/human.h"

int World::seed;

std::shared_ptr<Object> World::player;

std::vector<std::shared_ptr<Object>> World::object_list;
std::vector<std::shared_ptr<City>> World::city_list;
std::vector<std::shared_ptr<Room>> World::room_list;

// initialise the world
void World::init()
{
	World::seed = time(NULL);
	srand(World::seed);

	Logger::l << "Making a new city" << std::endl;

	int cityIndex = World::MakeNewCity(); // this will create a random city

	Logger::l << "Generating a new block" << std::endl;

	/*int thing = City::citySizeArray[World::city_list[cityIndex]->scale];
	for(int y = (thing / 2) * -1; y < thing / 2; y++)
	{
		for(int x = (thing / 2) * -1; x < thing / 2; x++)
		{
			Logger::lwarn << World::city_list[cityIndex]->GetRoomIndexAt(x, y) << std::endl;
		}
	}*/

	// since this is an init, the fist block at (0, 0) will be generated
	World::city_list[cityIndex]->GenerateBlock(0, 0);

	// then the player should be generated
	// NOTE: this will also mean that the default generation of the player is humanoid, but because it can be anything that has inteligence it should be used (in short: player can start as any creature);

	Logger::l << "Make player" << std::endl;
	World::player = std::shared_ptr<Object>(new Humanoid());
	Logger::l << "Putting player in the world" << std::endl;
	World::AddNewObject(player); // assign the player to the world

	Logger::l << "Player entering the city..." << std::endl;
	World::city_list[cityIndex]->Enter(World::player.get(), 0, 0); // enter where the shrine of death is located
}

void World::PlayerMove(const char& dir)
{
	// this should only apply when the player is in the CITY BLOCK
	// NOT when the player is in the ROOM or APRATMENT
	int x = 0;
	int y = 0;
	switch(dir)
	{
		case 'n':
			y = 1;
			break;
		case 'e':
			x = 1;
			break;
		case 's':
			y = -1;
			break;
		case 'w':
			x = -1;
			break;
		default:
			Logger::lerr << "Cannot move the player in the direction of " << dir << " (unknown direction)" << std::endl;
			break;
	}

	if(World::player->housingRoom->isCityMember())
	{
		((CityBlock*)World::player->housingRoom)->cityOrigin->Move(World::player.get(), x, y);
	}
	else
	{
		Logger::lcrit << "Cannot move around in a non-city member room" << std::endl;
		Logger::lwarn << "Player will stay in a current room" << std::endl;
	}
}
template <typename lambda>
void World::CallObjectFunctionFromPlayer(const std::string& objName, const lambda& func)
{
	Object* obj = World::ReturnObjectNamedInRoom(objName, World::player->housingRoom);
	if(obj == nullptr) {
		Logger::lerr << "Cannot find the \"" << objName << "\" object to interact" << std::endl;
	}
	else {
		func(obj);
	}
}
void World::PlayerEnterObject(const std::string& objName)
{
	World::CallObjectFunctionFromPlayer(objName, [](Object* o){ World::player->Enter(o); });
}
// these functions are callbacks from pi (PlayerInput), they also can have checks like LookAt has "around"
void World::PlayerLookAtObject(const std::string& objName)
{
	if(objName == "around")
	{
		World::NameEverythingInTheRoom(World::player->housingRoom, World::player.get());
	}
	else
	{
		World::CallObjectFunctionFromPlayer(objName, [](Object* o){ World::player->LookAt(o); });
	}
}
void World::PlayerTouchObject(const std::string& objName)
{
	World::CallObjectFunctionFromPlayer(objName, [](Object* o) { World::player->Touch(o); });
}
void World::PlayerUseObject(const std::string& objName)
{
	World::CallObjectFunctionFromPlayer(objName, [](Object* o) { World::player->Use(o); });
}
void World::PlayerPickUpObject(const std::string& objName)
{
	World::CallObjectFunctionFromPlayer(objName, [](Object* o) { World::player->PickUp(o); });
}
void World::PlayerOpenObject(const std::string& objName)
{
	World::CallObjectFunctionFromPlayer(objName, [](Object* o) { World::player->Open(o); });
}
void World::PlayerCloseObject(const std::string& objName)
{
	World::CallObjectFunctionFromPlayer(objName, [](Object* o) { World::player->Close(o); });
}
void World::PlayerUnlockObject(const std::string& objName)
{
	World::CallObjectFunctionFromPlayer(objName, [](Object* o) { World::player->Unlock(o); });
}
void World::PlayerTalkToObject(const std::string& objName)
{
	World::CallObjectFunctionFromPlayer(objName, [](Object* o) { World::player->TalkTo(o); });
}

void World::GetPlayerInput()
{
	/*
	 * Categories:
	 *	1. Inspect
	 *		* Look
	 *	2. Interaction
	 *		* Touch
	 *		* Use
	 *		* Pick Up
	 *	3. Change
	 *		* Open
	 *		* Close
	 *		* Unlock
	 *	4. Social
	 *		* Talk To
	 */

	pi::GetPlayerInput();
}
int World::MakeNewCity()
{
	city_list.push_back(std::shared_ptr<City>(new City()));
	return city_list.size() - 1;
}
int World::AddNewCity(std::shared_ptr<City> cityPointer)
{
	city_list.push_back(cityPointer);
	return city_list.size() - 1;
}
int World::AddNewObject(std::shared_ptr<Object> objectPointer)
{
	object_list.push_back(objectPointer);
	return object_list.size() - 1;
}

void World::NameEverythingInTheRoom(const Room* room, const Object* caller)
{
	for(int i = 0; i < room->objects.size(); i++)
	{
		Object* lookedAt = room->objects[i];
		if(lookedAt->get_id() == caller->get_id())
		{
			Logger::ls << lookedAt->get_colored_name() << cstring(" (YOU)", cstring::BLUE, cstring::BLACK, cstring::BOLD) << std::endl;
		}
		else
		{
			Logger::ls << lookedAt->get_colored_name() << std::endl;
		}
	}
}
Object* World::ReturnObjectNamedInRoom(const std::string name, const Room* room)
{
	for(int i = 0; i < room->objects.size(); i++)
	{
		Object* lookedAt = room->objects[i];
		if(lookedAt->get_name() == name)
		{
			return lookedAt;
		}
	}
	return nullptr;
}

World::~World()
{
	World::seed = 0;
}

