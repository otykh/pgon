#include<iostream>
#include<logger.h>

Logger Logger::ls = Logger(Logger::SILENT);
Logger Logger::l = Logger(Logger::INFO);
Logger Logger::lwarn = Logger(Logger::WARN);
Logger Logger::lerr = Logger(Logger::ERR);
Logger Logger::lcrit = Logger(Logger::CRIT);

//const cstring Logger::signs[5] = {cstring("[i] "), "\033[1;33m[!]\033[0m ", "\033[1;31m[e]\033[0m ", "\033[41;30m[CRITICAL]\033[0m ", "\0"};

const cstring Logger::signs[5] = {
	cstring("[i]"),
	cstring("[!]", cstring::YELLOW),
	cstring("[e]", cstring::RED),
	cstring("[CRITICAL]", cstring::BLACK, cstring::RED),
	"\0"};
	//"\033[41;30m[CRITICAL]\033[0m ", "\0"};

Logger::Logger(msgtype type)
{
	Logger::messageType = type;
}
