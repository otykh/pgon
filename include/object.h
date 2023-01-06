#pragma once

#include <string>
#include <memory>
#include "logger.h"
#include "room.h"
#include "colorer.h"

struct Room;

class Object
{
protected:
	cstring name;
	static int id_counter;
	int id;
public:
	Room* housingRoom;

	Object(const cstring& name);
	Object(const std::string& name);
	Object(const char* name);

	const std::string get_name() const;
	const cstring& get_colored_name() const;
	const int get_id() const;

	// these function are for when object does something to another
	// like Player.LookAt(Something);
	virtual void LookAt(Object* const o);
 	virtual void Touch(Object* const o);
 	virtual void Use(Object* const o);
 	virtual void Open(Object* const o);
	virtual void Close(Object* const o);
	virtual void Unlock(Object* const o);
	virtual void TalkTo(Object* const o);
	virtual void PickUp(Object* const o);

	// these function are called when the object is being operated
	// like Player.LookAt(Something); calls -> Something.LookedBy(Player)
	virtual void LookedBy(Object* const o) = 0;
 	virtual void TouchedBy(Object* const o);
 	virtual void UsedBy(Object* const o);
 	virtual void OpenedBy(Object* const o);
	virtual void ClosedBy(Object* const o);
	virtual void UnlockedBy(Object* const o);
	virtual void TalkedToBy(Object* const o);
	virtual void PickedUpBy(Object* const o);
};
