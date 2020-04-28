#pragma once
#include <iostream>

typedef unsigned char byte;


//int	gRotIX;			//	‰ñ“]”Ô†


const int cTetriminoHeight = { 4 };
const int cTetriminoWidth = { 4 };



class BlockPiece
{
private:



public:

	int gTetriminoPosX;
	int gTetriminoPosY;
	int gTetriminoType;


	

	const int cTetrimino = 7;
	int sRotIX;

	byte g_tetris[cTetriminoWidth][cTetriminoHeight];			//	—‰ºƒeƒgƒŠƒX

	void SetTertimino(int type, int rx);
	void SetTertimino();

	void DrawTetrimino();

	//int GetTetorimonoType();

	
	/*BlockPiece() {}
	~BlockPiece() {}*/
};

