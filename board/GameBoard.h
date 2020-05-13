#pragma once
#include <iostream>
#include <Windows.h>

#include "../agent/BlockPiece.h"

typedef unsigned char byte;




enum class Mask {
	
};

class GameBoard
{

private:
	
	
	int mOuterFrame = 0xff;

	int mEmpty = { 0 };
	


	enum Mask {
		Intensity = 8, RedMask = 4, GreenMask = 2, BlueMask = 1
	};


public:
	const static int mGbWidth = 10;
	const static int mGbHeight = 20;

	int mGameBoardPosX;//�Q�[���{�[�h�ʒu��x���W
	int mGameBoardPosY;//�Q�[���{�[�h�ʒu��y���W
	//
	//
	//
	//
	enum class Color: int
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

	GameBoard();

	GameBoard(int x, int y);

	//~GameBoard();
};



