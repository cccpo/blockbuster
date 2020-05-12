#pragma once
#include <Windows.h>

class DrawGameBoard
{


	

public:


	void DrawBoard();

	//void DrawStage();
	void DrawScore();

	void DrawRotType();

	void SetColor(int fg, int bg );
	void SetCursorPos(int x, int y);

	//DrawGameBoard(){}
	//~DrawGameBoard(){}
};

