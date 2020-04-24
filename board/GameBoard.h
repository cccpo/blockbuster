#pragma once
#include <iostream>

typedef unsigned char byte;

const int cGbWidth = { 10 };
const int cGbHeight = { 20 };




class GameBoard
{	
	const int cEmpty = { 0 };


	public:
	byte gBoard[cGbWidth + 2][cGbHeight + 2];	//	�O�g���܂߂��Ֆ�
	const static int OuterFrame = 0xff;


	const static int cGameBoardPosX = 45; //
	const static int cGameBoardPosY = 5;

	void InitGameBoard();
	void DrawStage();

	int GetcEmpty();

	int GetcGbWidth();
	//void SetcGbWidth(int w);

	int GetcGbHeight();
	//void SetcGbHeight(int h);

	/*byte GetgBoard(int );*/

	GameBoard() {};
	~GameBoard() {};
};



