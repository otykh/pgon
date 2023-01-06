#pragma once

#include "creature.h"

struct Humanoid : public Creature
{
	inline static const DNA humanDNA = {1, 2, 2, 1, 2, 1, 0b00001}; // c++17

	Humanoid() : Creature("RANDOM NAME", humanDNA, Creature::Unknown) { } // TODO make this a really a random name rather then "RANDOM NAME"
	void LookAt(Object* const o) override
	{
		o->LookedBy(this);
	}
	void LookedBy(Object* const o) override
	{
		if(o->get_id() == this->get_id())
		{
			Logger::l << "You look at yourself" << std::endl;
		}
	}
};
