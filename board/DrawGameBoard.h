#pragma once
#include <Windows.h>

#include "GameBoard.h"

//　GameBoardの描画を行うクラス
class DrawGameBoard
{
private:
	int gbpx;
	int gbpy;

	

public:

	void DrawBoard(GameBoard& gb);//ゲームボード外枠の描画
	void DrawBoard(GameBoard gb,GameBoard::Color cl);//ゲームボード外枠の描画
	void DrawStage(GameBoard gb);//ゲームボード内部の描画
	
	void DrawTetrimino(BlockPiece& bp);

	int TetriminoTypeToColor(int ttc);

	void DrawScore();//スコア表示

	void DrawRotType();

	void SetColor(int fg, int bg );
	void SetCursorPos(int x, int y);

	//DrawGameBoard(){}
	//~DrawGameBoard(){}

protected:
	GameBoard gb;


};

