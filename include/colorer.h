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
		WHITE = 7
	};

	static const char* end;
	static const char c[8][8];

	std::string text;
	COLORS color;

	ColoredText(const char* text, COLORS col = COLORS::WHITE);
	ColoredText& operator=(const char* str);

	friend std::ostream& operator<<(std::ostream& os, const ColoredText& ct);
};

std::ostream& operator<<(std::ostream& os, const ColoredText& ct);

typedef ColoredText cstring;
