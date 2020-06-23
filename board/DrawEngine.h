#pragma once
#include <Windows.h>

#include "GameBoard.h"
#include "BlockPiece.h"
#include "../Data/Data.h"
#include "../state/Score.h"

//　GameBoardの描画を行うクラス
class DrawEngine
{
private:
	int gbpx;
	int gbpy;

	enum Mask {
		Intensity = 8, RedMask = 4, GreenMask = 2, BlueMask = 1
	};

public:
	enum class Color : int
	{
		Black = 0x00, DarkBlue, DarkGreen, DarkCyan, DarkRed, DarkViolet, DarkYellow, Gray, LightGray, Blue,
		Green, Cyan, Red, Violet, Yellow, White

	};

	void DrawBoard(GameBoard const& gb);//ゲームボード外枠の描画
	void DrawBoard(GameBoard gb,Color cl);//ゲームボード外枠の描画
	void DrawStage(GameBoard gb);//ゲームボード内部の描画
	
	void DrawTetrimino(BlockPiece& bp);

	int TetriminoTypeToColor(int ttc);//テトリミノの形状から色を設定する

	void DrawScore(Score sc);//スコア表示

	void DrawHighScore();

	void DrawRotType();

	void SetColor(int fg, int bg );
	void SetCursorPos(int x, int y);

	//DrawGameBoard(){}
	//~DrawGameBoard(){}

protected:
	GameBoard gb;
	BlockPiece bp;
	Score sc;
	Data d;


};

