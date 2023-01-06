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
void Object::Touch(const Object* o)
{
	Logger::lerr << "Cannot touch this object" << std::endl;
}
void Object::Use(const Object* o)
{
	Logger::lerr << "Cannot use this object" << std::endl;
}
void Object::Open(const Object* o)
{
	Logger::lerr << "Cannot open this object" << std::endl;
}
void Object::Close(const Object* o)
{
	Logger::lerr << "Cannot close this object" << std::endl;
}
void Object::Unlock(const Object* o)
{
	Logger::lerr << "Cannot unlock this object" << std::endl;
}
void Object::TalkTo(const Object* o)
{
	Logger::lerr << "Cannot talking to this object" << std::endl;
}
void Object::PickUp(const Object* o)
{
	Logger::lerr << "Cannot pick up this object" << std::endl;
}
