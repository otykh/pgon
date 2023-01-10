#pragma once

#include <string>
#include <memory>
#include "logger.h"
#include "room.h"
#include "colorer.h"

struct Room;

//@NOTE this is probably overkill but removes the need to make 100 if statements to check for something, the objects can override those functions and the default responce is "nothing happens"
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

	//@NOTE on the Talk To, this should not be a dialogue with questions, rather a broad description of what the talk was about. Not! Hey *NAME* do you know .... But rather: You talked to *NAME* and they had not idea/knew about this or that....

	// these function are for when object does something to another
	// like Player.LookAt(Something);
	// these also should have to check whether the object can or can't do the action
	// the object with no hands should not be able to touch
	// or the object with no eyes cannot look At someting
	virtual void LookAt(Object* const o);
 	virtual void Touch(Object* const o);
 	virtual void Use(Object* const o);
	virtual void Enter(Object* const o);
 	virtual void Open(Object* const o);
	virtual void Close(Object* const o);
	virtual void Unlock(Object* const o);
	virtual void TalkTo(Object* const o);
	virtual void PickUp(Object* const o);

	// these function are called when the object is being operated
	// like Player.LookAt(Something); calls -> Something.LookedBy(Player)
	// here are the calls that the object has been interacted with,
	// such a thing can be used to coat the body with liquids, get attention etc.
	// the coolest example that I can some up with is Medusa, when LookedBy with turn that object
	// into stone :)
	// Also, (this comment is too long) can be used for checking if object has a knowledle or skill to perform an action. Like saint creatures can talk to gods and if player attempts to talk the game will check for certain knowledge (like prayer) it can use and perform the action if needed
	virtual void LookedBy(Object* const o) = 0;
 	virtual void TouchedBy(Object* const o);
 	virtual void UsedBy(Object* const o);
	virtual void EnteredBy(Object* const o);
 	virtual void OpenedBy(Object* const o);
	virtual void ClosedBy(Object* const o);
	virtual void UnlockedBy(Object* const o);
	virtual void TalkedToBy(Object* const o);
	virtual void PickedUpBy(Object* const o);
};

