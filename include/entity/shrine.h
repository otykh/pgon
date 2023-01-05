#pragma once

#include "object.h"
#include "logger.h"

struct Shrine : public Object
{
	Shrine() : Object("The Shrine Of Death") {}
	inline void Look(const Object* o) override
	{
		Logger::l << "You look at the statue resembeling a human that is being reborn from the depths below, signaling that life is a loop" << std::endl;
	}
	inline void Touch(const Object* o) override
	{
		Logger::l << "Nothing happens" << std::endl;
	}
	inline void TalkTo(const Object* o) override
	{
		Logger::l << "After trying to have a meaningful conversation you realised that the statue in front of you cannot talk" << std::endl;
	}
	inline void PickUp(const Object* o) override
	{
		Logger::lerr << "The statue is too heavy to pick up" << std::endl;
	}
};
