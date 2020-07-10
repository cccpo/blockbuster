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



	bool IsMoveDown(GameBoard ioGameBoard);//接触判定

	bool IsMoveLeft(GameBoard inGaneBoard);//左に移動する
	bool IsMoveRight(GameBoard inGaneBoard);//右に移動する

	bool IsOverLaped(GameBoard inGaneBoard);
	
	void ChangeBlock(GameBoard inGaneBoard);//テトリミノを固定化
	
	void DeleteLine(GameBoard inGaneBoard);// 揃ったラインを消去

	int GetRot(GameBoard inGaneBoard);//現在のテトリミノの回転タイプをゲット

	void SetTertimino(const GameBoard& ioGameBoard, int type, int inTetriminoType);//テトリミノをゲームボードに配置
	void AddTertimino(const GameBoard& ioGameBoard); // テトリミノの追加


	int GetgTetriminoPosX(GameBoard inGameBoard);
	void SetTeriminoPosX(int tpx);

	

	int GetTetriminoPosY(GameBoard inGaneBoard);
	void SetTeriminoPosY(int tpy);

	

	void SetRot(int r);
	
	int GetgTeriminoType();
	void SetTeriminoType(int ttype);

	int GetTeriminoValue(int x, int y);
	

	
	BlockPiece();
	//~BlockPiece();

protected:
	GameBoard inGaneBoard;

};

