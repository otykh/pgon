#pragma once

#include <iostream>
#include "colorer.h"

#define LOG_FILE_LOC = "./log.l";

class Logger
{
public:
	static Logger ls; // silent
	static Logger l;
	static Logger lwarn;
	static Logger lerr;
	static Logger lcrit;

	enum msgtype
	{
		INFO = 0,
		WARN,
		ERR,
		CRIT,
		SILENT
	};

private:
	static const cstring signs[];

public:
	msgtype messageType;

	Logger(msgtype);

	template<class T>
	std::ostream& operator<<(const T& v)
	{
		return std::cout << signs[messageType] << " " << v;
	}
	std::ostream& operator<<(std::ostream&(*f)(std::ostream&))
	{
		return std::cout << signs[messageType] << " " << f;
	}
};

/*template<class T>
Logger& operator<<(const T& v)
{
	std::cout << signs[0] << v;
	return *this;
}
Logger& operator<<(std::ostream&(*f)(std::ostream&))
{
	std::cout << signs[0] << f;
	return *this;
}*/
