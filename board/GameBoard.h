#pragma once
#include <iostream>
#include <Windows.h>

typedef unsigned char byte;




enum class Mask {
	
};

class GameBoard
{

private:
	
	
	int mOuterFrame = 0xff;

	int mEmpty = { 0 };
	
	int mGameBoardPosX = 1;//�Q�[���{�[�h�ʒu��x���W
	int mGameBoardPosY = 2;//�Q�[���{�[�h�ʒu��y���W

	enum Mask {
		Intensity = 8, RedMask = 4, GreenMask = 2, BlueMask = 1
	};


public:
	const static int mGbWidth = 10;
	const static int mGbHeight = 20;

	//
	//
	//
	//
	enum class Color
	{
		Black = 0x00, DarkBlue, DarkGreen, DarkCyan, DarkRed, DarkViolet, DarkYellow, Gray, LightGray, Blue,
		Green, Cyan, Red, Violet, Yellow, White

	};





	void InitGameBoard();// �Q�[���{�[�h������

	void SetColor(int fg, int bg);
	void SetCursorPos(int x, int y);

	int GetmEmpty() const;

	int GetmGameBoardPosX() const;

	int GetmGameBoardPosY() const;

	int GetGameBoardValue(int x, int y);
	void SetTerimonoValue(int x, int y, int val);

	void Down(int y);

	//GameBoard();
	//~GameBoard();
};



