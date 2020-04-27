#pragma once
#include <iostream>

typedef unsigned char byte;

extern const int cGbWidth = { 10 };
extern const int cGbHeight = { 20 };

class GameBoard
{	

private:
#define		COL_BLACK  0x00
#define		COL_DARK_BLUE		0x01
#define		COL_DARK_GREEN	0x02
#define		COL_DARK_CYAN		0x03
#define		COL_DARK_RED		0x04
#define		COL_DARK_VIOLET	0x05
#define		COL_DARK_YELLOW	0x06
#define		COL_GRAY	0x07
#define		COL_LIGHT_GRAY		0x08
#define		COL_BLUE		0x09
#define		COL_GREEN	0x0a
#define		COL_CYAN		0x0b
#define		COL_RED		0x0c
#define		COL_VIOLET	0x0d
#define		COL_YELLOW	0x0e
#define		COL_WHITE	0x0f
#define		COL_INTENSITY		0x08		//	���P�x�}�X�N
#define		COL_RED_MASK		0x04
#define		COL_GREEN_MASK	0x02
#define		COL_BLUE_MASK	0x01

	public:
	const int cEmpty = { 0 };

	byte gBoard[cGbWidth + 2][cGbHeight + 2]; 


	
	const static int OuterFrame = 0xff;


	const static int cGameBoardPosX = 1; //
	const static int cGameBoardPosY = 2;



	void InitGameBoard();
	void DrawStage();
	void DrawBoard();

	void SetColor(int fg, int bg);
	void SetCursorPos(int x, int y);

	int GetcEmpty();

	int GetcGbWidth();

	int GetcGbHeight();



	/*byte GetgBoard(int );*/


	//GameBoard() {}
	//~GameBoard() {}
};



