#include "city.h"
#include "world.h"
#include "e/shrine.h"
#include "e/building.h"

const int City::citySizeArray[] { 2, 4, 10, 20};
City::City()
{
	this->scale = rand() % 4;
	this->danger = rand() % 5; // 4 - 0
	this->chaos = rand() % 4 + 1; // 4 - 1
	this->buildingSize = rand() % 30 + 1; // 1 - 30

	int cityLinearSize = City::citySizeArray[this->scale] * City::citySizeArray[this->scale];
	this->cityBlocksId = new int[cityLinearSize];
	for(int i = 0; i < cityLinearSize; i++)
	{
		this->cityBlocksId[i] = BLOCK_UNINITIALIZED;
	}
}
City::~City()
{
	delete[] this->cityBlocksId;
}
void City::GenerateBlock(int x, int y)
{
	CityBlock r = CityBlock(this, nullptr, x, y); // TODO this is a room but this is also a block which means that this should be owned by the major of the town, [TODO Global Creature Update]

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
		for(int i = 0; i < 7; i++)
		{
			if(rand() % 2 == 0) { break; } // 50/50 chance that generation will stop
			Building* buildingPtr = new Building(this);
			World::AddNewObject(std::shared_ptr<Object>(buildingPtr));
			r.Enter(buildingPtr);
		}
	}

	room_list.push_back(std::make_shared<CityBlock>(r));
	int index = City::GetRoomIndexAt(x, y);
	cityBlocksId[index] = room_list.size() - 1;
}
int City::GenerateBuildingNumber()
{
	for(;;) // this will repeat till the number that does not exist will be generated
	{
		int numberGenerated = rand() % 1000000;
		if(buildingNumberSet.find(numberGenerated) == buildingNumberSet.end())
		{
			buildingNumberSet.insert(numberGenerated);
			return numberGenerated;
		}
	}
}
int City::GetRoomIndexAt(int x, int y)
{
	x = x + City::citySizeArray[this->scale] / 2;
	y = y + City::citySizeArray[this->scale] / 2;
	return (y * City::citySizeArray[this->scale]) + x;
}
Room* City::GetBlockAt(int x, int y)
{
	int index = cityBlocksId[City::GetRoomIndexAt(x, y)];
	if(index == BLOCK_UNINITIALIZED)
	{
		City::GenerateBlock(x, y); // this will generate a block at position
		return City::GetBlockAt(x, y); // NOTE: May cause lock up if some indexing gone wrong
	}
	else
	{
		return room_list[index].get();
	}
}
void City::Enter(Object* object, int x, int y)
{
	Logger::l << object->get_name() << " is now entering the city" << std::endl;
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
void City::Move(Object* object, int movex, int movey)
{
	if(object->housingRoom->isCityMember())
	{
		CityBlock* block = ((CityBlock*)object->housingRoom);
		int newX = block->x + movex;
		int newY = block->y + movey;

		block->Exit(object);
		Room* newBlock = City::GetBlockAt(newX, newY);
		for(int i = 0; i < newBlock->objects.size(); i++)
		{
			Logger::l << newBlock->objects[i]->get_colored_name() << std::endl;
		}
		newBlock->Enter(object);
		object->housingRoom = newBlock;
	}
	else
	{
		Logger::lcrit << "Cannot move around in a non-city member room" << std::endl;
	}
}
