#include <stdlib.h>
#include <random>

#include "../board/DrawGameBoard.h"
#include "../board/GameBoard.h"
#include "BlockPiece.h"
#include <string>
using namespace std;

using std::cout;
using std::endl;

byte trData[][4][4][4] = {
	{	//	I
		{
			{0, 1, 0, 0},
			{0, 1, 0, 0},
			{0, 1, 0, 0},
			{0, 1, 0, 0},
		},
		{
			{0, 0, 0, 0},
			{1, 1, 1, 1},
			{0, 0, 0, 0},
			{0, 0, 0, 0},
		},
		{
			{0, 1, 0, 0},
			{0, 1, 0, 0},
			{0, 1, 0, 0},
			{0, 1, 0, 0},
		},
		{
			{0, 0, 0, 0},
			{1, 1, 1, 1},
			{0, 0, 0, 0},
			{0, 0, 0, 0},
		},
	},
	{	//	o
		{
			{1, 1, 0, 0},
			{1, 1, 0, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0},
		},
		{
			{1, 1, 0, 0},
			{1, 1, 0, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0},
		},
		{
			{1, 1, 0, 0},
			{1, 1, 0, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0},
		},
		{
			{1, 1, 0, 0},
			{1, 1, 0, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0},
		},
	},
	{	//	Z
		{
			{1, 1, 0, 0},
			{0, 1, 1, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0},
		},
		{
			{0, 1, 0, 0},
			{1, 1, 0, 0},
			{1, 0, 0, 0},
			{0, 0, 0, 0},
		},
		{
			{1, 1, 0, 0},
			{0, 1, 1, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0},
		},
		{
			{0, 1, 0, 0},
			{1, 1, 0, 0},
			{1, 0, 0, 0},
			{0, 0, 0, 0},
		},
	},
	{	//	S
		{
			{0, 1, 1, 0},
			{1, 1, 0, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0},
		},
		{
			{1, 0, 0, 0},
			{1, 1, 0, 0},
			{0, 1, 0, 0},
			{0, 0, 0, 0},
		},
		{
			{0, 1, 1, 0},
			{1, 1, 0, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0},
		},
		{
			{1, 0, 0, 0},
			{1, 1, 0, 0},
			{0, 1, 0, 0},
			{0, 0, 0, 0},
		},
	},
	{	//	L
		{
			{0, 1, 0, 0},
			{0, 1, 0, 0},
			{0, 1, 1, 0},
			{0, 0, 0, 0},
		},
		{
			{0, 0, 1, 0},
			{1, 1, 1, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0},
		},
		{
			{1, 1, 0, 0},
			{0, 1, 0, 0},
			{0, 1, 0, 0},
			{0, 0, 0, 0},
		},
		{
			{0, 0, 0, 0},
			{1, 1, 1, 0},
			{1, 0, 0, 0},
			{0, 0, 0, 0},
		},
	},

			{	//	J
		{
			{0, 1, 0, 0},
			{0, 1, 0, 0},
			{1, 1, 0, 0},
			{0, 0, 0, 0},
		},
		{
			{0, 0, 0, 0},
			{1, 1, 1, 0},
			{0, 0, 1, 0},
			{0, 0, 0, 0},
		},
		{
			{0, 1, 1, 0},
			{0, 1, 0, 0},
			{0, 1, 0, 0},
			{0, 0, 0, 0},
		},
		{
			{1, 0, 0, 0},
			{1, 1, 1, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0},
		},
	},
	{	//	T
		{
			{0, 1, 0, 0},
			{1, 1, 1, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0},
		},
		{
			{0, 1, 0, 0},
			{1, 1, 0, 0},
			{0, 1, 0, 0},
			{0, 0, 0, 0},
		},
		{
			{0, 0, 0, 0},
			{1, 1, 1, 0},
			{0, 1, 0, 0},
			{0, 0, 0, 0},
		},
		{
			{0, 1, 0, 0},
			{0, 1, 1, 0},
			{0, 1, 0, 0},
			{0, 0, 0, 0},
		},
	},
};

void BlockPiece::SetTertimino(int type, int rx) {
        for (int y = 0; y < cTetriminoHeight; ++y) {
            for (int x = 0; x < cTetriminoWidth; ++x) {
                g_tetris[x][y] = trData[type][rx][y][x];
            }
        }
    }

void BlockPiece::SetTertimino() {
	GameBoard gb;
	string debug;

	std::random_device rnd;
	std::mt19937 mt(rnd());
	std::uniform_int_distribution<int> type(0,6);

	int gbw = gb.GetcGbWidth();
	
	gTetriminoPosX = ((gbw - cTetriminoWidth) / 2);
	
	//OutputDebugString(debug);
	//gTetriminoPosX = { (gb.GetcGbWidth() - cTetriminoWidth) / 2 };
	gTetriminoPosY = 0;
	gTetriminoType = (type(mt));
    SetTertimino(gTetriminoType, sRotIX = 0);
    }

void BlockPiece::DrawTetrimino()
{
    GameBoard gb;
    //DrawGameBoard dgb;

	gb.SetColor(static_cast<int>(GameBoard::Color::Red), static_cast<int>(GameBoard::Color::Red));
   
	for (int i = 0; i < cTetriminoWidth; ++i) {
        int y = gTetriminoPosY + i;
        if (y < 0 || y >= gb.GetcGbHeight()) continue;
        for (int k = 0; k < cTetriminoWidth; ++k) {
            int x = gTetriminoPosX + k;
            if (x < 0 || x >= gb.GetcGbWidth()) continue;
            if (g_tetris[k][i]) {
                gb.SetCursorPos(gb.GetcGameBoardPosX() + (x + 1) * 2, gb.GetcGameBoardPosY() + y + 1);
                cout << "  ";
            }
        }
    }
}

//bool BlockPiece::MoveDown() {
//	for(int x = 0;x<cTetriminoWidth;++x)
//		for (int y = cTetriminoHeight; --y >= 0;) {
//			if (g_board[x +  + 1][y +  + 1 + 1] != 0)
//				return false;              //  ‚·‚®‰º‚É•Ç or ŒÅ’èƒuƒƒbƒN‚ª‚ ‚é
//			break;
//		}
//}

void BlockPiece::SetgTeriminoPosX(int tpx) {
	this->gTetriminoPosX = tpx;
}

int BlockPiece::GetgTetriminoPosY() {
	return gTetriminoPosY;
}

void BlockPiece::SetgTeriminoPosY(int tpy) {
	this->gTetriminoPosY = tpy;
}


void BlockPiece::SetgTeriminoType(int ttype) {
	this->gTetriminoType = ttype;
}



