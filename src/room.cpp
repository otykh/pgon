#include "room.h"

Room::Room(Object* owner)
{

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
