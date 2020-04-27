#pragma once
#include <Windows.h>

class DrawGameBoard
{


	

public:
	const int cGameBoardPosX = 1;			//	ゲームボード描画位置
	const int cGameBoardPosY = 2;

	void DrawBoard();
	//void DrawStage();
	void DrawScore();

	void SetColor(int fg, int bg );
	void SetCursorPos(int x, int y);

	DrawGameBoard(){}
	~DrawGameBoard(){}
};

