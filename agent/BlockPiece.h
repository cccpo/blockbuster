#pragma once
#include <iostream>
#include <Windows.h>

typedef unsigned char byte;

const int cTetriminoHeight = { 4 };
const int cTetriminoWidth = { 4 };



class BlockPiece
{
private:



public:

	int gTetriminoPosX;//ゲームボード左上からの相対的な位置
	int gTetriminoPosY;
	int gTetriminoType;


	

	const int cTetrimino = 7;
	int sRotIX;

	byte g_tetris[cTetriminoWidth][cTetriminoHeight];
	
	bool MoveDown();
		

	void SetTertimino(int type, int rx);
	void SetTertimino();

	void DrawTetrimino();

	//int GetTetorimonoType();

	void SetgTeriminoPosX(int tpx);
	int GetgTetriminoPosY();
	void SetgTeriminoPosY(int tpy);

	void SetgTeriminoType(int ttype);
	
	/*BlockPiece() {}
	~BlockPiece() {}*/
};

