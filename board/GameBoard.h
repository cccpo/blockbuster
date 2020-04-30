#pragma once
#include <iostream>
#include <Windows.h>

typedef unsigned char byte;

const int cGbWidth = 10;
const int cGbHeight = 20;

static int gBoard[cGbWidth + 2][cGbHeight + 2];

enum class Mask {
	
};

class GameBoard
{

private:
	const static int mOuterFrame = 0xff;


	

	enum Mask {
		Intensity = 8, RedMask = 4, GreenMask = 2, BlueMask = 1
	};


public:
	const int cEmpty = { 0 };

	

	/*byte gBoard[cGbWidth + 2][cGbHeight + 2];*/

	enum class Color
	{
		Black = 0x00, DarkBlue, DarkGreen, DarkCyan, DarlRed, DarkViolet, DarkYellow, Gray, LightGray, Blue,
		Green, Cyan, Red, Violet, Yellow, White

	};

	const static int cGameBoardPosX = 1; //
	const static int cGameBoardPosY = 2;



	void InitGameBoard();
	void DrawBoard();//�Q�[���{�[�h�O�g�̕`��(ToDO DrawGameBoard�ɈڐA�\��)
	void DrawStage();//�Q�[���{�[�h�����̕`��(ToDO DrawGameBoard�ɈڐA�\��)

	bool MoveDown();

	void SetColor(int fg, int bg);
	void SetCursorPos(int x, int y);

	int GetcEmpty();

	int GetcGbWidth();

	int GetcGbHeight();

	int GetcGameBoardPosX();

	int GetcGameBoardPosY();

	int SetTeriminoValue(int x, int y);

	//byte(*getAry())[cGbHeight + 2];
	//int* GetbBoard();

	//GameBoard();
	//~GameBoard();
};



