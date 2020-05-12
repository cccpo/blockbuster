#pragma once


class ColorManagement
{

public:
	enum class Color
	{
		Black = 0x00, DarkBlue, DarkGreen, DarkCyan, DarkRed, DarkViolet, DarkYellow, Gray, LightGray, Blue,
		Green, Cyan, Red, Violet, Yellow, White
	};

	void SetColor(int fg, int bg);
};

