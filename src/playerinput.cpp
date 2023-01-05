#include "playerinput.h"

std::string pi::GetLookAtObjectName(std::string command)
{
	if(command.length() <= 5)
	{
		return "";
	}

	command = command.substr(5, command.length() - 5); // remove the "look" from the command
	if(command.rfind("around", 0) == 0)
	{
		return "around";
	}
	else
	{
		// if the next word is "at" ex. look AT tree
		// also removes the "the" and "a" from the sentence
		// ex. look at THE tree
		if(command.rfind("at ", 0) == 0) { command = command.substr(3, command.length() - 3); }
		if(command.rfind("the ", 0) == 0) { command = command.substr(4, command.length() - 4); }
		else if(command.rfind("a ", 0) == 0) { command = command.substr(2, command.length() - 2); }

		return command;
	}
}
