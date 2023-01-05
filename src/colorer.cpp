#include "colorer.h"
#include "logger.h"
#include <cstring>

const char* cstring::end = { "\033[0m" };
const char cstring::c[8][8] =
{
	"\033[0;30m",
	"\033[0;31m",
	"\033[0;32m",
	"\033[0;33m",
	"\033[0;34m",
	"\033[0;35m",
	"\033[0;36m",
	"\033[0;37m"
};

ColoredText::ColoredText(const char* text, COLORS col)
{
	this->text = text;
	this->color = col;
}

ColoredText& ColoredText::operator=(const char* text)
{
	this->text = text;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const ColoredText& ct)
{
	os << ColoredText::c[ct.color] << ct.text << ColoredText::end;
	return os;
}
