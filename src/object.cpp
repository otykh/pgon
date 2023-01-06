#include "object.h"

int Object::id_counter;
Object::Object(const cstring& name) : name(name)
{
	this->id = id_counter;
	id_counter++;
}
Object::Object(const std::string& name) : Object(cstring(name)) {}
Object::Object(const char* name) : Object(cstring(name)) {}

const int Object::get_id() const
{
	return this->id;
}
const std::string Object::get_name() const
{
	return this->name.text;
}
const cstring& Object::get_colored_name() const
{
	return this->name;
}
void Object::LookAt(Object* const o)
{
	Logger::lerr << "Cannot look" << std::endl;
}
void Object::Touch(Object* const o)
{
	Logger::lerr << "Cannot touch" << std::endl;
}
void Object::Use(Object* const o)
{
	Logger::lerr << "Cannot use" << std::endl;
}
void Object::Open(Object* const o)
{
	Logger::lerr << "Cannot open" << std::endl;
}
void Object::Close(Object* const o)
{
	Logger::lerr << "Cannot close" << std::endl;
}
void Object::Unlock(Object* const o)
{
	Logger::lerr << "Cannot unlock" << std::endl;
}
void Object::TalkTo(Object* const o)
{
	Logger::lerr << "Cannot talking" << std::endl;
}
void Object::PickUp(Object* const o)
{
	Logger::lerr << "Cannot pick" << std::endl;
}

void Object::TouchedBy(Object* const o)
{
	Logger::lerr << "Nothing happend" << std::endl;
}
void Object::UsedBy(Object* const o)
{
	Logger::lerr << "Cannot use this object" << std::endl;
}
void Object::OpenedBy(Object* const o)
{
	Logger::lerr << "Cannot open" << std::endl;
}
void Object::ClosedBy(Object* const o)
{
	Logger::lerr << "Cannot close" << std::endl;
}
void Object::UnlockedBy(Object* const o)
{
	Logger::lerr << "Cannot unlock" << std::endl;
}
void Object::TalkedToBy(Object* const o)
{
	Logger::lerr << "Cannot talk to" << std::endl;
}
void Object::PickedUpBy(Object* const o)
{
	Logger::lerr << "Cannot be picked up" << std::endl;
}

