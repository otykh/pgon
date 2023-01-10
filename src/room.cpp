#include "room.h"

Room::Room(Object* owner)
{
	this->owner = owner;
}
CityBlock::CityBlock(City* city, Object* owner, int x, int y) : x(x), y(y), Room(owner)
{
	this->cityOrigin = city;
}
Room::~Room()
{

}
void Room::Enter(Object* object)
{
	objects.push_back(object);
}
void Room::Exit(Object* creature)
{
	for(int i = 0; i < objects.size(); i++)
	{
		if(objects[i]->get_id() == creature->get_id())
		{
			objects.erase(objects.begin() + i);
			return;
		}
	}
}
