#include "../Game.h"
#include "../state/Score.h"

#include "../board/GameBoard.h"

#include "BlockPiece.h"
#include <string>
using namespace std;

using std::cout;
using std::endl;

int mRotIX = 0;

//ToDO�@���s��7��ނ̃e�g���~�m��90�x�����炵��4�p�^�[��������
int trData[][4][4][4] = {
	{	
		//Type A
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
	{	//TypeB
		{
			{2, 2, 0, 0},
			{2, 2, 0, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0},
		},
		{
			{2, 2, 0, 0},
			{2, 2, 0, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0},
		},
		{
			{2, 2, 0, 0},
			{2, 2, 0, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0},
		},
		{
			{2, 2, 0, 0},
			{2, 2, 0, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0},
		},
	},
	{	//TypeC
		{
			{3, 3, 0, 0},
			{0, 3, 3, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0},
		},
		{
			{0, 3, 0, 0},
			{3, 3, 0, 0},
			{3, 0, 0, 0},
			{0, 0, 0, 0},
		},
		{
			{3, 3, 0, 0},
			{0, 3, 3, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0},
		},
		{
			{0, 3, 0, 0},
			{3, 3, 0, 0},
			{3, 0, 0, 0},
			{0, 0, 0, 0},
		},
	},
	{//TypeD
		{
			{0, 4, 4, 0},
			{4, 4, 0, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0},
		},
		{
			{4, 0, 0, 0},
			{4, 4, 0, 0},
			{0, 4, 0, 0},
			{0, 0, 0, 0},
		},
		{
			{0, 4, 4, 0},
			{4, 4, 0, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0},
		},
		{
			{4, 0, 0, 0},
			{4, 4, 0, 0},
			{0, 4, 0, 0},
			{0, 0, 0, 0},
		},
	},
	{	//TypeE
		{
			{0, 5, 0, 0},
			{0, 5, 0, 0},
			{0, 5, 5, 0},
			{0, 0, 0, 0},
		},
		{
			{0, 0, 5, 0},
			{5, 5, 5, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0},
		},
		{
			{5, 5, 0, 0},
			{0, 5, 0, 0},
			{0, 5, 0, 0},
			{0, 0, 0, 0},
		},
		{
			{0, 0, 0, 0},
			{5, 5, 5, 0},
			{5, 0, 0, 0},
			{0, 0, 0, 0},
		},
	},
	//TypeF
			{	
		{
			{0, 6, 0, 0},
			{0, 6, 0, 0},
			{6, 6, 0, 0},
			{0, 0, 0, 0},
		},
		{
			{0, 0, 0, 0},
			{6, 6, 6, 0},
			{0, 0, 6, 0},
			{0, 0, 0, 0},
		},
		{
			{0, 6, 6, 0},
			{0, 6, 0, 0},
			{0, 6, 0, 0},
			{0, 0, 0, 0},
		},
		{
			{6, 0, 0, 0},
			{6, 6, 6, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0},
		},
	},
	{//TypeG	
		{
			{0, 7, 0, 0},
			{7, 7, 7, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0},
		},
		{
			{0, 7, 0, 0},
			{7, 7, 0, 0},
			{0, 7, 0, 0},
			{0, 0, 0, 0},
		},
		{
			{0, 0, 0, 0},
			{7, 7, 7, 0},
			{0, 7, 0, 0},
			{0, 0, 0, 0},
		},
		{
			{0, 7, 0, 0},
			{0, 7, 7, 0},
			{0, 7, 0, 0},
			{0, 0, 0, 0},
		},
	},
};

//�e�g���~�m���Q�[���{�[�h�ɔz�u
void BlockPiece::SetTertimino(GameBoard gb, int type, int rx) {
        for (int y = 0; y < gTetriminoHeight; ++y) {
            for (int x = 0; x < gTetriminoWidth; ++x) {
                mTetrimino[x][y] = trData[type][rx][y][x];
            }
        }
    }

//�e�g���~�m�̒ǉ�
void BlockPiece::AddTertimino(GameBoard gb) {
	std::random_device rnd;
	std::mt19937 mt(rnd());
	std::uniform_int_distribution<int> type(0,6);//0�`6�͈̔͂ŗ�������

	int gbw = GameBoard::mGbWidth;
	
	SetTeriminoPosX(((gbw - gTetriminoWidth) / 2));
	SetTeriminoPosY(0);

	SetTeriminoType(type(mt));


    SetTertimino(gb,mTetriminoType, mRotIX = 0);
    }


//�ڐG����
bool BlockPiece::IsMoveDown(GameBoard gb) {
	for (int x = 0; x < gTetriminoWidth; ++x) {
		for (int y = gTetriminoHeight; --y >= 0;) {
			if (mTetrimino[x][y] != 0) {
				if (gb.GetGameBoardValue(x + mTetriminoPosX + 1, y + mTetriminoPosY + 2) != 0)
					return false; 
				break;
			}
		}
	}
	return true;
}

//���Ɉړ�����
bool BlockPiece::IsMoveLeft(GameBoard gb) {
	for (int y = 0; y < gTetriminoHeight; ++y) {
		for (int x = 0; x < gTetriminoWidth; ++x) {
			if (mTetrimino[x][y] != 0) {     
				if(gb.GetGameBoardValue(x + mTetriminoPosX + 1 - 1, y + mTetriminoPosY + 1) != 0)
					return false; 
				break;  
			}
		}
	}
	return true;
}

//�E�Ɉړ�����
bool BlockPiece::IsMoveRight(GameBoard gb) {
	for (int y = 0; y < gTetriminoHeight; ++y) {
		for (int x = gTetriminoWidth; --x >= 0; ) {
			if (mTetrimino[x][y] != 0) {     
				if (gb.GetGameBoardValue(x + mTetriminoPosX + 1 + 1,y + mTetriminoPosY + 1) != 0)
					return false;           
				break;    
			}
		}
	}
	return true;
}

//�g�O�ɂ��邩�𔻒�
bool BlockPiece::IsOverLaped(GameBoard gb) {
	for (int y = 0; y < gTetriminoHeight; ++y) {
		for (int x = 0; x < gTetriminoWidth; ++x) {
			if (mTetrimino[x][y] != 0 && gb.GetGameBoardValue(x + mTetriminoPosX + 1, y + mTetriminoPosY + 1) != 0)
				return true;
		}
	}
	return false;
}

//�e�g���~�m���Œ艻
void BlockPiece::ChangeBlock(GameBoard gb) {
	for (int y = 0; y < gTetriminoHeight; ++y) {
		for (int x = 0; x < gTetriminoWidth; ++x) {
			if (mTetrimino[x][y] != 0)
				gb.SetTerimonoValue(x + mTetriminoPosX + 1, y + mTetriminoPosY + 1,BlockPiece::mTetriminoType + 1);
		}
	}

	
}

// ���������C��������
void BlockPiece::DeleteLine(GameBoard gb)
{
	Score sc;

	int nClear = 0;       // �����������C����(����ɉ����ă|�C���g�����㏸)
	for (int ty = 0; ty < gTetriminoHeight; ++ty) {
		int y = ty + GetTetriminoPosY(gb) + 1;
		if (y > GameBoard::mGbHeight) break;
		int cnt = 0;
		for (int x = 1; x <= GameBoard::mGbWidth; ++x) {
			if (gb.GetGameBoardValue(x,y) != 0)
				++cnt;
		}

		if (cnt == GameBoard::mGbWidth) {
			gb.Down(y);
			++nClear;
		}
	}


	sc.AddScore(nClear);

}

//���݂̃e�g���~�m�̉�]�^�C�v���Q�b�g
int BlockPiece::GetRot(GameBoard gb) {
	return mRotIX;
}

int BlockPiece::GetgTetriminoPosX(GameBoard gb) {
	return mTetriminoPosX;
}

void BlockPiece::SetTeriminoPosX(int tpx) {
	mTetriminoPosX = tpx;
}

int BlockPiece::GetTetriminoPosY(GameBoard gb) {
	return mTetriminoPosY;
}

void BlockPiece::SetTeriminoPosY(int tpy) {
	mTetriminoPosY = tpy;
}

int BlockPiece::GetgTeriminoType(){
	return mTetriminoType;
}

void BlockPiece::SetTeriminoType(int ttype) {
	mTetriminoType = ttype;
}

int BlockPiece::GetTeriminoValue(int x,int y) {
	int s = mTetrimino[x][y];
	return s;
}

void BlockPiece::SetRot(int r) {
	mRotIX = r;
}

BlockPiece::BlockPiece() {

}