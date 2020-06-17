#pragma once
#include <Windows.h>
#include <vector>
#include <random>
#include <stdlib.h>

#include "GameBoard.h"

typedef unsigned char byte;

const int gTetriminoHeight = { 4 };
const int gTetriminoWidth = { 4 };



class BlockPiece
{
private:
	
	

	
public:
	int mTetriminoPosX;//ゲームボード左上からの相対的な位置
	int mTetriminoPosY;
	int mTetriminoType;//テトリミノのタイプ

	//テトリミノのタイプを列挙　#ToDO 名前は仮
	enum class TetrimnoType:int
	{
		TypeA=1,TypeB,TypeC,TypeD,TypeE,TypeF,TypeG
	};
	

	int mTetrimino[gTetriminoWidth][gTetriminoHeight];



	bool IsMoveDown(GameBoard gb);//接触判定

	bool IsMoveLeft(GameBoard gb);
	bool IsMoveRight(GameBoard gb);

	bool IsOverLaped();
		
	
	int GetRot();

	void SetTertimino(int type, int rx);//テトリミノをゲームボードに配置
	void AddTertimino(); // テトリミノの追加


	int GetgTetriminoPosX();
	void SetTeriminoPosX(int tpx);

	void ChangeBlock();

	int GetTetriminoPosY();
	void SetTeriminoPosY(int tpy);

	void DeleteLine();

	void SetRot(int r);
	
	int GetgTeriminoType();
	void SetTeriminoType(int ttype);

	int GetTeriminoValue(int x, int y);
	

	
	BlockPiece();
	//~BlockPiece();


};

