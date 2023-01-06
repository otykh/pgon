#pragma once

#include <iostream>

class ColoredText
{
public:
	enum COLORS
	{
		BLACK = 0,
		RED = 1,
		GREEN = 2,
		YELLOW = 3,
		BLUE = 4,
		MAGENTA = 5,
		CYAN = 6,
		WHITE = 7,
		NONE = 0
	};
	enum STYLE
	{
		NORMAL = 0,
		BOLD = 1,
		UNDERLINE = 2,
		BLINK = 3
	};

	static const char* end;
	static const char* start;
	static const char* c[8];
	static const char* bc[8];
	static const char* st[4];

	std::string text;
	COLORS color;
	COLORS background;
	STYLE style;

	ColoredText(const char* text, COLORS col = COLORS::WHITE, COLORS back = COLORS::NONE, STYLE style = STYLE::NORMAL);
	ColoredText(const std::string str, COLORS col = COLORS::WHITE, COLORS back = COLORS::NONE, STYLE style = STYLE::NORMAL);
	ColoredText& operator=(const char* str);

	friend std::ostream& operator<<(std::ostream& os, const ColoredText& ct);
};

std::ostream& operator<<(std::ostream& os, const ColoredText& ct);

typedef ColoredText cstring;
