#include "city.h"
#include "world.h"
#include "e/shrine.h"

City::City()
{
	this->scale = rand() % 11; // 10 - 0
	this->danger = rand() % 5; // 4 - 0
}
void City::GenerateBlock(int x, int y)
{
	Room r = Room(nullptr); // TODO this is a room but this is also a block which means that this should be owned by the major of the town, [TODO Global Creature Update]

	if(x == 0 && y == 0)
	{
		// put the Shrine of Death here
		Shrine* shrinePtr = new Shrine();
		World::AddNewObject(std::shared_ptr<Object>(shrinePtr));
		r.Enter(shrinePtr);
	}
	else
	{
		// randomly generate with context [TODO will be made later]
	}

	room_list.push_back(std::make_shared<Room>(r));
	// the x and y to the index in the list
	map_room.insert(std::make_pair(std::make_pair(x, y), room_list.size() - 1));
}
Room* City::GetBlockAt(int x, int y)
{
	return City::room_list[City::map_room.at(std::make_pair(x, y))].get();
}
void City::Enter(Object* object, int x, int y)
{
	Logger::l << object->get_id() << " is now entering the city" << std::endl;
	if(object->housingRoom != nullptr)
	{
		object->housingRoom->Exit(object);
	}

	Room* desiredRoom = this->GetBlockAt(x, y);
	desiredRoom->Enter(object);
	object->housingRoom = desiredRoom;

	Logger::l << object->get_name() << " is now in the city in the block. " << std::endl;
	Logger::l << "With them there is a: " << std::endl;
	for(int i = 0; i < object->housingRoom->objects.size(); i++)
	{
		std::cout << object->housingRoom->objects[i]->get_name() << std::endl;
	}
}
void City::Move(Object* object, int x, int y)
{

}
