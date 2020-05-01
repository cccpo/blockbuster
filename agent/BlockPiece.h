#pragma once
#include <iostream>
#include <Windows.h>
#include <vector>

typedef unsigned char byte;

const int gTetriminoHeight = { 4 };
const int gTetriminoWidth = { 4 };

static int gTeriminoPosY;


class BlockPiece
{
private:
	const int cTetrimino = 7;


public:

	int sRotIX;


	int mTetriminoPosX;//ゲームボード左上からの相対的な位置
	int mTetriminoPosY;
	int mTetriminoType;//テトリミノのタイプ

	int mTetrimino[gTetriminoWidth][gTetriminoHeight];



	bool MoveDown();

	bool MoveLeft();
	bool MoveRight();

	bool IsOverLaped();
		
	

	void SetTertimino(int type, int rx);
	void SetTertimino();

	void DrawTetrimino();


	int GetgTetriminoPosX();
	void SetgTeriminoPosX(int tpx);

	void ChangeBlock();

	int GetgTetriminoPosY();
	void SetgTeriminoPosY(int tpy);

	void DeleteLine();

	int GetRot();
	void SetRot(int r);
	
	int GetgTeriminoType();
	void SetgTeriminoType(int ttype);

	int SetTeriminoValue(int x, int y);
	
	
	BlockPiece();
	~BlockPiece();
};

