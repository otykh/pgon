#pragma once

#include "object.h"
#include "logger.h"
#include <algorithm>

// the most complicated yet
struct Building : public Object
{
	City* housingCity;
	bool numbered; //@NOTE if the building has a number in the city, the un-numbered building should note have special characters inside and are just more dangereous
	int number;
	int size;

	Building(City* housingCity) : Object("Building")
	{
		int chaos = housingCity->chaos;
		int buildingSize = housingCity->buildingSize;

		this->size = std::max(buildingSize + (rand() % 6 + 1) * chaos, 40); // max size is 40!
		this->numbered = (rand() % 2) == 0; // 0 - 1
		this->housingCity = housingCity;
		this->number = -1;
	}
	void LookedBy(Object* const o) override
	{
		Logger::l << "You look at a building, it is a";
		if(size >= 30) {
			Logger::ls << "HUGE building";
		}
		else if(size >= 15) {
			Logger::ls << "Big building";
		}
		else if(size >= 7) {
			Logger::ls << "Medium building";
		}
		else {
			Logger::ls << "Small building";
		}

		if(numbered)
		{
			// generate the number from the city
			if(number < 0)
			{
				number = housingCity->GenerateBuildingNumber();
				this->name = this->get_name() + " " + std::to_string(number);
			}

			Logger::ls << "that has a plate that says: \"Building number " << number << "\"";
		}
		else
		{
			Logger::ls << "the street and building number is unknown";
		}
		Logger::ls << std::endl;
	}
};
