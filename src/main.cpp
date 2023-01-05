#include<iostream>
#include<world.h>
#include<cstdlib>
#include<logger.h>


#include "e/shrine.h"

int main()
{
#if TESTING
	Logger log;

	World world;

	Logger::l << "This if info" << std::endl;
	Logger::lwarn << "This is a warning" << std::endl;
	Logger::lerr << "This is an error" << std::endl;
	Logger::lcrit << "This is critital" << std::endl;

	world.init();

	Logger::l << "world: ok";
	Logger::l << "completed";

	return 0;
#else
	Logger::l << "Starting the game" << std::endl;
	World world;

	world.init();

	for(;;)
	{
		world.GetPlayerInput();
	}

	/*Shrine sh;
	sh.Touch(nullptr);
	sh.Look(nullptr);
	sh.Use(nullptr);
	sh.Open(nullptr);
	sh.Close(nullptr);
	sh.Unlock(nullptr);
	sh.TalkTo(nullptr);
	sh.PickUp(nullptr);*/

	//Creature* c = world.GenerateRandomCreature();
	//log.p("Creature created");
	//log.p(c);

	return 0;
#endif
}
