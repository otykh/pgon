#pragma once
#include <iostream>
#include "dna.h"
#include "object.h"

class Creature : public Object
{
public:
	enum Alignment
	{
		LawfulGood, 	NeutralGood, 	ChaoticGood,
		LawfulNeutral, 	TrueNeutral,	ChaoticNeutral,
		LawfulEvil, 	NeutralEvil, 	ChaoticEvil,
		Unknown
	};

	enum CreatureType
	{
		Humanoid = 	0b00001,
		Animal = 	0b00010,
		Demon = 	0b00100,
		Angel = 	0b01000
	};

	// number of parts
	// describes how many parts a creature has
	// the connection is based like this:
	// body -> head -> eyes -> nose -> leg/arm
	// thus the creature without a body is described as:
	// 1 head with 2 eyes and 1 nose positioned on 2 legs with 2 arms derived from it's body
protected:
	DNA dna;
	Alignment alignment;

public:
	static const int MAX_CreatureTag = 0b01111;
	static const int MIN_CreatureTag = 0b00001;
	static const char* const creatureType[4];

	/*Creature(int bodies, int arms, int legs, int heads, int eyes, int noses, int creatureType, Alignment alignment);*/
	Creature(const std::string name, const DNA& basedOn, const Creature::Alignment alignment);

	DNA& GetDNA();
	std::string toString() const;
	const char* AlignmentToString() const;
	bool isType(CreatureType type);

	friend std::ostream & operator<<(std::ostream & str, Creature const & c);
};

inline std::ostream & operator<<(std::ostream & str, Creature const & c)
{
	const DNA& d = c.dna;
	int count = 0;
	for(unsigned int mask = Creature::MIN_CreatureTag;
		mask <= Creature::MAX_CreatureTag;
		mask = mask << 1)
	{
		//std::cout << mask << " : " << ((c.type & mask) > 0) << std::endl;
		if((d.type & mask) > 0)
		{
			std::cout << Creature::creatureType[count] << " ";
		}
		count++;
	}
	std::cout << "with " << d.arms << " arms, " << d.legs << " legs ";
	std::cout << "all connected to ";
	if(d.bodies > 0)
	{
		std::cout << "the torso ";
	}
	else if(d.heads == 1)
	{
		std::cout << "the single head with no torso";
	}
	else if(d.heads > 1)
	{
		std::cout << "multiple (" << d.heads << ") heads with no torso";
	}
	else if(d.eyes > 0)
	{
		std::cout << d.eyes << " eyes, mashed together";
	}
	else if(d.noses > 0)
	{
		std::cout << d.noses << "noses, mashed together";
	}
	else
	{
		std::cout << "each other creating a horifying mess";
	}

	std::cout << ". It is aligned as " << c.AlignmentToString();

	return str;
}
