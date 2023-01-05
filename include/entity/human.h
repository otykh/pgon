#pragma once

#include "creature.h"

struct Humanoid : public Creature
{
	inline static const DNA humanDNA = {1, 2, 2, 1, 2, 1, 0b00001}; // c++17

	Humanoid() : Creature("RANDOM NAME", humanDNA, Creature::Unknown) { } // TODO make this a really a random name rather then "RANDOM NAME"
	void Look(const Object* o) override
	{
		Logger::l << "Human" << std::endl;
	}
 	void Touch(const Object* o) override
	{
		Logger::lerr << "Cannot touch this object" << std::endl;
	}
 	void Use(const Object* o) override
	{
		Logger::lerr << "Cannot use this object" << std::endl;
	}
 	void Open(const Object* o) override
	{
		Logger::lerr << "Cannot open this object" << std::endl;
	}
	void Close(const Object* o) override
	{
		Logger::lerr << "Cannot close this object" << std::endl;
	}
	void Unlock(const Object* o) override
	{
		Logger::lerr << "Cannot unlock this object" << std::endl;
	}
	void TalkTo(const Object* o) override
	{
		Logger::lerr << "Cannot talking to this object" << std::endl;
	}
	void PickUp(const Object* o) override
	{
		Logger::lerr << "Cannot pick up this object" << std::endl;
	}
};
