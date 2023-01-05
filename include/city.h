#pragma once

#include "dna.h"
#include "room.h"
#include <stdlib.h>
#include <vector>
#include <memory>
#include <unordered_map>
#include <tuple>

struct hash_pair
{
	template <class T1, class T2>
    size_t operator()(const std::pair<T1, T2>& p) const
    {
        auto hash1 = std::hash<T1>{}(p.first);
        auto hash2 = std::hash<T2>{}(p.second);

        if (hash1 != hash2) {
            return hash1 ^ hash2;
        }

        // If hash1 == hash2, their XOR is zero.
    	return hash1;
    }
};

class City
{
	int scale; // how big the city is, the larger the number the more houses will be generated
	int danger; // how dangereous the city is, in other words how much the citizens will squew to the "evil" rather then "good"

	std::vector<std::shared_ptr<Object>> object_list;
	std::vector<std::shared_ptr<Room>> room_list;

	// this is a pair<x, y> (north, west of the town) to the index in room_list (see above)
	std::unordered_map<std::pair<int,int>, int, hash_pair> map_room;

public:
	City();
	void GenerateBlock(int x, int y);
	Room* GetBlockAt(int x, int y); // the position relative from the Srhine Of Death (the center of the city)
	void Enter(Object*, int x, int y);
	void Move(Object*, int x, int y); // moves the object up down left right. (1, 0) -> will be right
};
