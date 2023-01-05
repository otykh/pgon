#pragma once

// this defines the description of the creature
struct DNA
{
	int bodies;
	int arms;
	int legs;
	int heads;
	int eyes;
	int noses;

	int type;

	DNA(int bodies, int arms, int legs, int heads, int eyes, int noses, int creatureType)
	{
		this->bodies = bodies;
		this->arms = arms;
		this->legs = legs;
		this->heads = heads;
		this->eyes = eyes;
		this->noses = noses;
		this->type = creatureType;
	}
};
