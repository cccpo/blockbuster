#include <stdlib.h>
#include <random>

#include "../Game.h"
#include "../state/Score.h"
#include "../board/DrawGameBoard.h"
#include "../board/GameBoard.h"
#include "BlockPiece.h"
#include <string>
using namespace std;

using std::cout;
using std::endl;

//ToDO�@���s��7��ނ̃e�g���~�m��90�x�����炵��4�p�^�[��������
//��X��]�̓|�C���^��p���Ď�������
int trData[][4][4][4] = {
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
        for (int y = 0; y < gTetriminoHeight; ++y) {
            for (int x = 0; x < gTetriminoWidth; ++x) {
                mTetrimino[x][y] = trData[type][rx][y][x];
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
	
	//gTeriminoPosX = (gbw - gTetriminoWidth) / 2;
	SetgTeriminoPosX(((gbw - gTetriminoWidth) / 2));
	 //gTeriminoPosX = GetgTetriminoPosX();
	SetgTeriminoPosY(0);
	gTeriminoPosY = 0;
	SetgTeriminoType(type(mt));
    SetTertimino(mTetriminoType, sRotIX = 0);
    }

void BlockPiece::DrawTetrimino()
{
    GameBoard gb;
    //DrawGameBoard dgb;

	gb.SetColor(static_cast<int>(GameBoard::Color::Red), static_cast<int>(GameBoard::Color::Red));
   
	for (int i = 0; i < gTetriminoWidth; ++i) {
        int y = mTetriminoPosY + i;
        if (y < 0 || y >= gb.GetcGbHeight()) continue;
        for (int k = 0; k < gTetriminoWidth; ++k) {
            int x = mTetriminoPosX + k;
            if (x < 0 || x >= gb.GetcGbWidth()) continue;
            if (mTetrimino[k][i]) {
                gb.SetCursorPos(gb.GetcGameBoardPosX() + (x + 1) * 2, gb.GetcGameBoardPosY() + y + 1);
                cout << "  ";
            }
        }
    }
}

//�ڐG����
bool BlockPiece::MoveDown() {
	GameBoard gb;

	
	for (int x = 0; x < gTetriminoWidth; ++x) {
		for (int y = gTetriminoHeight; --y >= 0;) {
			if (mTetrimino[x][y] != 0) {
				if (gb.GetTeriminoValue(x + mTetriminoPosX + 1, y + mTetriminoPosY + 2) != 0)
					return false; 
				break;
			}
		}
	}
	return true;
}

//���Ɉړ�����
bool BlockPiece::MoveLeft() {
	GameBoard gb;

	for (int y = 0; y < gTetriminoHeight; ++y) {
		for (int x = 0; x < gTetriminoWidth; ++x) {
			if (mTetrimino[x][y] != 0) {     
				if(gb.GetTeriminoValue(x + mTetriminoPosX + 1 - 1, y + mTetriminoPosY + 1) != 0)
					return false; 
				break;  
			}
		}
	}
	return true;
}

//�E�Ɉړ�����
bool BlockPiece::MoveRight() {
	GameBoard gb;


	for (int y = 0; y < gTetriminoHeight; ++y) {
		for (int x = gTetriminoWidth; --x >= 0; ) {
			if (mTetrimino[x][y] != 0) {     
				if (gb.GetTeriminoValue(x + mTetriminoPosX + 1 + 1,y + mTetriminoPosY + 1) != 0)
					return false;           
				break;    
			}
		}
	}
	return true;
}

//
bool BlockPiece::IsOverLaped() {
	GameBoard gb;


	for (int y = 0; y < gTetriminoHeight; ++y) {
		for (int x = 0; x < gTetriminoWidth; ++x) {
			if (mTetrimino[x][y] != 0 && gb.GetTeriminoValue(x + mTetriminoPosX + 1, y + mTetriminoPosY + 1) != 0)
				return true;
		}
	}
	return false;
}




void BlockPiece::ChangeBlock() {
	GameBoard gb;

	for (int y = 0; y < gTetriminoHeight; ++y) {
		for (int x = 0; x < gTetriminoWidth; ++x) {
			if (mTetrimino[x][y] != 0)
				gb.SetTerimonoValue(x + mTetriminoPosX + 1, y + mTetriminoPosY + 1, 1);
		}
	}

	
}

// ���������C��������
void BlockPiece::DeleteLine()
{
	Score sc;
	GameBoard gb;


	int nClear = 0;       // �����������C����(����ɉ����ă|�C���g�����㏸)
	for (int ty = 0; ty < gTetriminoHeight; ++ty) {
		int y = ty + GetgTetriminoPosY() + 1;
		if (y > cGbHeight) break;
		int cnt = 0;
		for (int x = 1; x <= cGbWidth; ++x) {
			if (SetTeriminoValue(x,y) != 0)
				++cnt;
		}

		if (cnt == cGbWidth) {
			gb.Down(y);
			++nClear;
		}
	}
	sc.AddScore(nClear);

}

int BlockPiece::GetgTetriminoPosX() {

	return mTetriminoPosX;
}

void BlockPiece::SetgTeriminoPosX(int tpx) {
	mTetriminoPosX = tpx;
}

int BlockPiece::GetgTetriminoPosY() {
	return mTetriminoPosY;
}

void BlockPiece::SetgTeriminoPosY(int tpy) {
	mTetriminoPosY = tpy;
}

int BlockPiece::GetgTeriminoType(){
	return mTetriminoType;
}

void BlockPiece::SetgTeriminoType(int ttype) {
	mTetriminoType = ttype;
}

//auto BlockPiece::GetTetrimino() {
//	return gTetrimino;
//}

int BlockPiece::SetTeriminoValue(int x,int y) {
	int s = mTetrimino[x][y];
	return s;
}

int BlockPiece::GetRot() {
	return sRotIX;
}

void BlockPiece::SetRot(int r) {
	sRotIX = r;
}

//BlockPiece::BlockPiece(byte* p, int tw, int th) {
//	top = p;
//	= tw;
//
//}




