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

	int cityIndex = World::MakeNewCity(); // this will create a random city

	// since this is an init, the fist block at (0, 0) will be generated
	World::city_list[cityIndex]->GenerateBlock(0, 0);

	// then the player should be generated
	// NOTE: this will also mean that the default generation of the player is humanoid, but because it can be anything that has inteligence it should be used (in short: player cna start as any creature);

	World::player = std::shared_ptr<Object>(new Humanoid());
	World::AddNewObject(player); // assign the player to the world

	World::city_list[cityIndex]->Enter(World::player.get(), 0, 0); // enter where the shrine of death is located
}
void World::NameEverythingInTheRoom(const Room* room, const Object* caller)
{
	for(int i = 0; i < room->objects.size(); i++)
	{
		Object* lookedAt = room->objects[i];
		if(lookedAt->get_id() == caller->get_id())
		{
			Logger::ls << lookedAt->get_colored_name() << " (YOU)" << std::endl;
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

	std::string comm;

	std::cout << "$: ";
	std::getline(std::cin, comm);

	if(comm.rfind("help", 0) == 0)
	{
		Logger::l << "Use these commands to interact with the world: " << std::endl;
		Logger::ls << "* look\n* touch\n* use\n* pick up\n* open\n* close\n* unlock\n* talk to\n" << std::endl;
	}
	else if(comm.rfind("look", 0) == 0)
	{
		std::string objName = pi::GetLookAtObjectName(comm);
		if(objName.empty())
		{
			Logger::lerr << "Bad usage. Use LOOK [object of interest/around]" << std::endl;
		}
		else if(objName == "around")
		{
			World::NameEverythingInTheRoom(World::player->housingRoom, World::player.get());
		}
		else
		{
			Object* obj = World::ReturnObjectNamedInRoom(objName, World::player->housingRoom);
			if(obj == nullptr) {
				Logger::lerr << "Cannot find the \"" << objName << "\" object to look at" << std::endl; }
			else {
				World::player->LookAt(obj);
				//obj->Look(World::player.get());
			}
		}
	}
	else
	{
		Logger::lerr << "Cannot find the \"" << comm << "\" command" << std::endl;
	}
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

World::~World()
{
	World::seed = 0;
}
