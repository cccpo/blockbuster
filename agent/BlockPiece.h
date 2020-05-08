#pragma once
#include <Windows.h>
#include <vector>
#include <random>
#include <stdlib.h>

typedef unsigned char byte;

const int gTetriminoHeight = { 4 };
const int gTetriminoWidth = { 4 };



class BlockPiece
{
private:
	int mTetriminoPosX;//ゲームボード左上からの相対的な位置
	int mTetriminoPosY;
	int mTetriminoType;//テトリミノのタイプ

	
public:



	

	int mTetrimino[gTetriminoWidth][gTetriminoHeight];



	bool IsMoveDown();

	bool IsMoveLeft();
	bool IsMoveRight();

	bool IsOverLaped();
		
	
	int GetRot();

	void SetTertimino(int type, int rx);
	void AddTertimino();

	void DrawTetrimino();


	int GetgTetriminoPosX();
	void SetTeriminoPosX(int tpx);

	void ChangeBlock();

	int GetTetriminoPosY();
	void SetgTeriminoPosY(int tpy);

	void DeleteLine();

	//int GetRot();
	void SetRot(int r);
	
	int GetgTeriminoType();
	void SetgTeriminoType(int ttype);

	int GetTeriminoValue(int x, int y);
	
	
	//BlockPiece();
	//~BlockPiece();
};

