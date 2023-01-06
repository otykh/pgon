#include "colorer.h"
#include "logger.h"
#include <cstring>

const char* cstring::end = { "\033[0m" };
const char* cstring::start = { "\033[" };

const char* cstring::c[8] =
{
	"30m",
	"31m",
	"32m",
	"33m",
	"34m",
	"35m",
	"36m",
	"37m"
};
const char* cstring::bc[8] =
{
	"40;",
	"41;",
	"42;",
	"43;",
	"44;",
	"45;",
	"46;",
	"47;"
};
const char* cstring::st[4] =
{
	"0;", // normal
	"1;", // bold
	"4;", // underline
	"5;"  // blink
};

ColoredText::ColoredText(const char* text, COLORS col, COLORS background, STYLE style)
{
	this->text = text;
	this->color = col;
	this->background = background;
	this->style = style;
}

ColoredText::ColoredText(const std::string text, COLORS col, COLORS background, STYLE style)
{
	this->text = text;
	this->color = col;
	this->background = background;
	this->style = style;
}

ColoredText& ColoredText::operator=(const char* text)
{
	this->text = text;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const ColoredText& ct)
{
	if(ct.background != ColoredText::COLORS::NONE)
	{
		os << ColoredText::start << ColoredText::st[ct.style] << ColoredText::bc[ct.background] << ColoredText::c[ct.color] << ct.text << ColoredText::end;
	}
	else
	{
		os << ColoredText::start << ColoredText::st[ct.style] << ColoredText::c[ct.color] << ct.text << ColoredText::end;
	}
	return os;
}
