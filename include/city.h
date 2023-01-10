#pragma once

#include "dna.h"
#include "room.h"
#include <stdlib.h>
#include <vector>
#include <memory>
#include <unordered_map>
#include <unordered_set>
#include "hash_pair.h"

#define BLOCK_UNINITIALIZED -1

class City
{
	static const int citySizeArray[];

	int scale; // how big the city is, the larger the number the more houses will be generated
	int danger; // how dangereous the city is, in other words how much the citizens will squew to the "evil" rather then "good"

	std::vector<std::shared_ptr<Object>> object_list;
	std::vector<std::shared_ptr<CityBlock>> room_list;

	// @NOTE the array should just be generated, with the indexes pointing to the room list
	int* cityBlocksId;

	std::unordered_set<int> buildingNumberSet;

	int GetRoomIndexAt(int x, int y);

public:

	// building properties
	int chaos; // determins how random the city is
	int buildingSize; // determines how (on average) big the building are in the city

	City();
	void GenerateBlock(int x, int y);
	int GenerateBuildingNumber();
	Room* GetBlockAt(int x, int y); // the position relative from the Srhine Of Death (the center of the city)
	void Enter(Object*, int x, int y);
	void Move(Object*, int x, int y); // moves the object up down left right. (1, 0) -> will be right
	~City();
};

