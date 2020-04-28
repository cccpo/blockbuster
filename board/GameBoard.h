#pragma once
#include <iostream>
#include <Windows.h>

typedef unsigned char byte;

const int cGbWidth = 10;
const int cGbHeight = 20;



enum class Mask {
	
};

class GameBoard
{	

private:
	const static int cOuterFrame = 0xff;



	enum Mask {
		Intensity=8,RedMask=4,GreenMask=2,BlueMask=1
	};


	public:
	const int cEmpty = { 0 };

	byte gBoard[cGbWidth + 2][cGbHeight + 2]; 

	enum class Color
	{
		Black, DarkBlue, DarkGreen, DarkCyan, DarlRed, DarkViolet, DarkYellow, Gray, LightGray, Blue,
		Green, Cyan, Red, Violet, Yellow, White

	};

	const static int cGameBoardPosX = 1; //
	const static int cGameBoardPosY = 2;



	void InitGameBoard();	
	void DrawBoard();//ƒQ[ƒ€ƒ{[ƒhŠO˜g‚Ì•`‰æ(ToDO DrawGameBoard‚ÉˆÚA—\’è)
	void DrawStage();//ƒQ[ƒ€ƒ{[ƒh“à•”‚Ì•`‰æ(ToDO DrawGameBoard‚ÉˆÚA—\’è)

	void SetColor(int fg, int bg);
	void SetCursorPos(int x, int y);

	int GetcEmpty();

	int GetcGbWidth();

	int GetcGbHeight();

	int GetcGameBoardPosX();

	int GetcGameBoardPosY();
	

	/*byte GetgBoard(int );*/


	//GameBoard() {}
	//~GameBoard() {}
};



