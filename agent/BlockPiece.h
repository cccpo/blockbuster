#pragma once
#include <iostream>
#include <Windows.h>
#include <vector>

typedef unsigned char byte;

const int gTetriminoHeight = { 4 };
const int gTetriminoWidth = { 4 };

static int gTeriminoPosX;
static int gTeriminoPosY;


class BlockPiece
{
private:
	const int cTetrimino = 7;
	int sRotIX;


public:

	int mTetriminoPosX;//�Q�[���{�[�h���ォ��̑��ΓI�Ȉʒu
	int mTetriminoPosY;
	int mTetriminoType;//�e�g���~�m�̃^�C�v

	int mTetrimino[gTetriminoWidth][gTetriminoHeight];
	//byte(&r2)[gTetriminoWidth][gTetriminoHeight] = mTetrimino;

	//BlockPiece(byte* p, int tw, int th);


	bool MoveDown();


		

	void SetTertimino(int type, int rx);
	void SetTertimino();

	void DrawTetrimino();

	//int GetTetorimonoType();

	int GetgTetriminoPosX();
	void SetgTeriminoPosX(int tpx);

	//int GetgTetriminoPosY();
	void SetgTeriminoPosY(int tpy);

	void SetgTeriminoType(int ttype);

	int SetTeriminoValue(int x, int y);
	
	/*BlockPiece() {}
	~BlockPiece() {}*/
};

