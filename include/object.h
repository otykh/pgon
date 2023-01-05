#pragma once

#include <string>
#include <memory>
#include "logger.h"
#include "room.h"

struct Room;

class Object
{
private:
	std::string name;
	static int id_counter;
	int id;
public:
	Room* housingRoom;

	Object(const std::string& name);

	const std::string get_name() const;
	const int get_id() const;
	virtual void Look(const Object* o) = 0;
 	virtual void Touch(const Object* o);
 	virtual void Use(const Object* o);
 	virtual void Open(const Object* o);
	virtual void Close(const Object* o);
	virtual void Unlock(const Object* o);
	virtual void TalkTo(const Object* o);
	virtual void PickUp(const Object* o);
};
