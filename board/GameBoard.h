#pragma once
#include <iostream>
#include <Windows.h>

typedef unsigned char byte;

const int cGbWidth = 10;
const int cGbHeight = 20;

enum class Mask {
	
};

class GameBoard
{

private:
	int mOuterFrame = 0xff;

	int mEmpty = { 0 };
	
	int mGameBoardPosX = 1;//ゲームボード位置のx座標
	int mGameBoardPosY = 2;//ゲームボード位置のy座標

	enum Mask {
		Intensity = 8, RedMask = 4, GreenMask = 2, BlueMask = 1
	};


public:

	enum class Color
	{
		Black = 0x00, DarkBlue, DarkGreen, DarkCyan, DarlRed, DarkViolet, DarkYellow, Gray, LightGray, Blue,
		Green, Cyan, Red, Violet, Yellow, White

	};





	void InitGameBoard();// ゲームボード初期化
	void DrawBoard();//ゲームボード外枠の描画(ToDO DrawGameBoardに移植予定)
	void DrawStage();//ゲームボード内部の描画(ToDO DrawGameBoardに移植予定)


	void SetColor(int fg, int bg);
	void SetCursorPos(int x, int y);

	int GetmEmpty() const;

	int GetcGbWidth() const;

	int GetcGbHeight() const;

	int GetmGameBoardPosX() const;

	int GetmGameBoardPosY() const;

	int GetTeriminoValue(int x, int y);
	void SetTerimonoValue(int x, int y, int val);

	void Down(int y);

	//GameBoard();
	//~GameBoard();
};



