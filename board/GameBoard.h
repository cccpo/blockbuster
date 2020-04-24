#pragma once
#include <iostream>

typedef unsigned char byte;



class GameBoard
{	
	const int cEmpty = { 0 };


	public:
	const int cGbWidth = { 10 };
	const int cGbHeight = { 20 };
	const static int WALL = 0xff;

	byte g_board[10 + 2][20 + 2];	//	ŠO˜g‚ðŠÜ‚ß‚½”Õ–Ê
	

	GameBoard() {}
	~GameBoard() {}

	void init_board();

	int GetcGbWidth();
	void SetcGbWidth(int w);

	int GetcGbHeight();
	void SetcGbHeight(int h);
};



