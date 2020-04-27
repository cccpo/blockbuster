#pragma once
#include <iostream>

typedef unsigned char byte;

const int cGbWidth = { 10 };
const int cGbHeight = { 20 };




class GameBoard
{	
	public:
	const int cEmpty = { 0 };

	byte gBoard[cGbWidth + 2][cGbHeight + 2];	//	ŠO˜g‚ðŠÜ‚ß‚½”Õ–Ê
	const static int OuterFrame = 0xff;


	const static int cGameBoardPosX = 45; //
	const static int cGameBoardPosY = 5;

	void InitGameBoard();
	void DrawStage();
	void DrawBoard();

	void SetColor(int fg, int bg);
	void SetCursorPos(int x, int y);

	int GetcEmpty();

	int GetcGbWidth();
	//void SetcGbWidth(int w);

	int GetcGbHeight();
	//void SetcGbHeight(int h);

	/*byte GetgBoard(int );*/

	GameBoard() {};
	~GameBoard() {};
};



