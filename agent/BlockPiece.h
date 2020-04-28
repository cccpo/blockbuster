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
	int gTetriminoType;//テトリミノのタイプ


	

	const int cTetrimino = 7;
	int sRotIX;

	byte gTetrimino[cTetriminoWidth][cTetriminoHeight];
	byte* top;

	//BlockPiece(byte* p, int tw, int th);


	
	bool MoveDown();
		

	void SetTertimino(int type, int rx);
	void SetTertimino();

	void DrawTetrimino();

	//int GetTetorimonoType();

	int GetgTetriminoPosX();
	void SetgTeriminoPosX(int tpx);

	int GetgTetriminoPosY();
	void SetgTeriminoPosY(int tpy);

	void SetgTeriminoType(int ttype);

	byte*  GetTetrimino();
	
	/*BlockPiece() {}
	~BlockPiece() {}*/
};

