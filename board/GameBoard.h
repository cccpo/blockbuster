#pragma once
#include <iostream>
#include <Windows.h>



typedef unsigned char byte;




enum class Mask {
	
};

class GameBoard
{

private:
	
	
	int mOuterFrame = 0xff;

	int mEmpty = { 0 };
	


	enum Mask {
		Intensity = 8, RedMask = 4, GreenMask = 2, BlueMask = 1
	};


public:
	enum Value {
		empty=0
	};

	const static int mGbWidth = 10;
	const static int mGbHeight = 20;

	int mGameBoardPosX;//ゲームボード位置のx座標
	int mGameBoardPosY;//ゲームボード位置のy座標

	void InitGameBoard();// ゲームボード初期化

	int GetGameBoardValue(int x, int y);// ゲームボードの値をゲット
	void SetTerimonoValue(int x, int y, int val);// ゲームボードの値をセット

	void Down(int y);// 一段落とす(揃ったときに使用)

	int GetmEmpty() const;// 初期化関数

	int GetmGameBoardPosX() const;// ゲームボードのx座標を返す
	int GetmGameBoardPosY() const;// ゲームボードのy座標を返す

	GameBoard();

	GameBoard(int x, int y);

	//~GameBoard();
};



