#pragma once
#include <Windows.h>

//　GameBoardの描画を行うクラス
class DrawGameBoard
{


	

public:


	void DrawBoard();//ゲームボード外枠の描画
	void DrawStage();//ゲームボード内部の描画
	
	void DrawScore();//スコア表示

	void DrawRotType();

	void SetColor(int fg, int bg );
	void SetCursorPos(int x, int y);

	//DrawGameBoard(){}
	//~DrawGameBoard(){}
};

