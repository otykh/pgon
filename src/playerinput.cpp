#include "playerinput.h"

void pi::GetPlayerInput()
{
	std::string comm;
	std::cout << "$: ";
	std::getline(std::cin, comm);

	if(comm.rfind("help", 0) == 0)
	{
		Logger::l << "Use these commands to interact with the world: " << std::endl;
		Logger::ls << "* look\n* touch\n* use\n* pick up\n* open\n* close\n* unlock\n* talk to\n" << std::endl;
	}
	else if(comm.rfind("move", 0) == 0)
	{
		if(comm.length() <= 5)
		{
			Logger::lerr << "Bad usage. Use MOVE [north/east/south/west]" << std::endl;
		}
		else
		{
			char dir = comm.substr(5, 1).at(0); // get the first letter (n, e, s, w)
			if(dir == 's' || dir == 'e' || dir == 'n' || dir == 'w')
			{
				World::PlayerMove(dir);
			}
			else
			{
				Logger::lerr << "Bad usage. Use MOVE [north/east/south/west]" << std::endl;
			}
		}
	}
	else if(comm.rfind("enter", 0) == 0)
	{
		if(comm.length() <= 6)
		{
			Logger::lerr << "Bad usage. Use ENTER [object of interest]" << std::endl;
		}
		else
		{
			std::string objName = comm.substr(6, comm.length() - 6);
			World::PlayerEnterObject(objName);
		}
	}
	else if(comm.rfind("look", 0) == 0)
	{
		std::string objName = pi::GetLookAtObjectName(comm);
		if(objName.empty())
		{
			Logger::lerr << "Bad usage. Use LOOK [object of interest/around]" << std::endl;
		}
		else
		{
			World::PlayerLookAtObject(objName);
		}
	}
	else if(comm.rfind("touch", 0) == 0)
	{
		if(comm.length() <= 6)
		{
			Logger::lerr << "Bad usage. Use TOUCH [object of interest]" << std::endl;
		}
		else
		{
			std::string objName = comm.substr(6, comm.length() - 6);
			World::PlayerTouchObject(objName);
		}
	}
	else if(comm.rfind("use", 0) == 0)
	{
		if(comm.length() <= 4)
		{
			Logger::lerr << "Bad usage. Use USE [object of interest]" << std::endl;
		}
		else
		{
			std::string objName = comm.substr(4, comm.length() - 4);
			World::PlayerUseObject(objName);
		}
	}
	else if(comm.rfind("pick up", 0) == 0)
	{
		if(comm.length() <= 8)
		{
			Logger::lerr << "Bad usage. Use PICK UP [object of interest]" << std::endl;
		}
		else
		{
			std::string objName = comm.substr(8, comm.length() - 8);
			World::PlayerPickUpObject(objName);
		}
	}
	else if(comm.rfind("open", 0) == 0)
	{
		if(comm.length() <= 5)
		{
			Logger::lerr << "Bad usage. Use Open [object of interest]" << std::endl;
		}
		else
		{
			std::string objName = comm.substr(5, comm.length() - 5);
			World::PlayerOpenObject(objName);
		}
	}
	else if(comm.rfind("close", 0) == 0)
	{
		if(comm.length() <= 6)
		{
			Logger::lerr << "Bad usage. Use CLOSE [object of interest]" << std::endl;
		}
		else
		{
			std::string objName = comm.substr(6, comm.length() - 6);
			World::PlayerCloseObject(objName);
		}
	}
	else if(comm.rfind("unlock", 0) == 0)
	{
		if(comm.length() <= 7)
		{
			Logger::lerr << "Bad usage. Use UNLOCK [object of interest]" << std::endl;
		}
		else
		{
			std::string objName = comm.substr(7, comm.length() - 7);
			World::PlayerUnlockObject(objName);
		}
	}
	else if(comm.rfind("talk to", 0) == 0)
	{
		if(comm.length() <= 8)
		{
			Logger::lerr << "Bad usage. Use TALK TO [object of interest]" << std::endl;
		}
		else
		{
			std::string objName = comm.substr(8, comm.length() - 8);
			World::PlayerTalkToObject(objName);
		}
	}
	else
	{
		Logger::lerr << "Cannot find the \"" << comm << "\" command" << std::endl;
	}
}

std::string pi::GetLookAtObjectName(const std::string& command)
{
	if(command.length() <= 5)
	{
		return "";
	}

	std::string output;

	output = command.substr(5, command.length() - 5); // remove the "look" from the command
	if(output.rfind("around", 0) == 0)
	{
		return "around";
	}
	else
	{
		// if the next word is "at" ex. look AT tree
		// also removes the "the" and "a" from the sentence
		// ex. look at THE tree
		if(output.rfind("at ", 0) == 0) { output = output.substr(3, output.length() - 3); }
		if(output.rfind("the ", 0) == 0) { output = output.substr(4, output.length() - 4); }
		else if(output.rfind("a ", 0) == 0) { output = output.substr(2, output.length() - 2); }

		return output;
	}
}
