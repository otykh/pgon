#include "creature.h"

const char* const Creature::creatureType[4] = { "Humanoid", "Animal", "Demon", "Angel" };

/*
Creature::Creature(int bodies, int arms, int legs, int heads, int eyes, int noses, int creatureType, Creature::Alignment alignment) : Object()
{
	this->dna.bodies = bodies;
	this->dna.arms = arms;
	this->dna.legs = legs;
	this->dna.heads = heads;
	this->dna.eyes = eyes;
	this->dna.noses = noses;
	this->dna.type = creatureType;
	this->alignment = alignment;
}
*/

Creature::Creature(const std::string name, const DNA& basedOn, const Creature::Alignment alignment) : dna(basedOn), Object(name)
{
	this->alignment = alignment;
	/*this->dna.bodies = basedOn.bodies;
	this->dna.arms = basedOn.arms;
	this->dna.legs = basedOn.legs;
	this->dna.heads = basedOn.heads;
	this->dna.eyes = basedOn.eyes;
	this->dna.noses = basedOn.noses;
	this->dna.type = basedOn.type;*/
}
DNA& Creature::GetDNA()
{
	return this->dna;
}
std::string Creature::toString() const
{
	return "Creature";
}
const char* Creature::AlignmentToString() const
{
	switch(this->alignment)
	{
		case LawfulGood:
			return "Lawful Good";
		case NeutralGood:
			return "Neutral Good";
		case ChaoticGood:
			return "Chaotic Good";
		case LawfulNeutral:
			return "Lawful Neutral";
		case TrueNeutral:
			return "True Neutral";
		case ChaoticNeutral:
			return "Chaotic Neutral";
		case LawfulEvil:
			return "Lawful Evil";
		case NeutralEvil:
			return "Neutral Evil";
		case ChaoticEvil:
			return "Chaotic Evil";
		default:
			return "Unknown";
	};
}
bool Creature::isType(Creature::CreatureType type)
{
	return (type & this->dna.type) > 0;
}
