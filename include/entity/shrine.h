#pragma once

#include "object.h"
#include "logger.h"

struct Shrine : public Object
{
	Shrine() : Object(cstring("The Shrine Of Death", cstring::MAGENTA)) {}
	inline void LookedBy(Object* const o) override
	{
		Logger::l << this->get_colored_name() << std::endl;
		Logger::ls << "You look at the big metal statue in front of you, it size is huge and it is resembeling a person comming from the ground, like they are being reborn. On the closer look you see a sign position right at the statue itself, it reads\n" << cstring("\"Whoever might fall, must be reborn\"\n", cstring::MAGENTA) << "Clearly this is a reference to the phenomenon that, in this universe anyone that dies will be resurected in a new form with a new body. You take a minute to appreciate the craftsmenship that went into creating such a monument and step away." << std::endl;
	}
	inline void TouchedBy(Object* const o) override
	{
		Logger::l << "You approach the metal structure, putting your hand closer and close to the metal facade that it has, feeling the coldness of the material. But for all that this Shrine resembles, " << cstring("nothing happens", cstring::YELLOW) << std::endl;
	}
	inline void TalkedToBy(Object* const o) override
	{
		Logger::l << "You try to talk to the " << this->get_colored_name() << " but it did not respond to your questions, probably because it is just a statue" << std::endl;
	}
	inline void PickedUpBy(Object* const o) override
	{
		Logger::lerr << "It is too heavy to pick up" << std::endl;
	}
};
