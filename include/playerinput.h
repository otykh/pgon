#pragma once

#include <string>
#include <iostream>
#include "logger.h"
#include "world.h"

class pi
{
public:
	static void GetPlayerInput();
	static std::string GetLookAtObjectName(const std::string& comm);
};
