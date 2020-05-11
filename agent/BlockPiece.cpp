#include "../Game.h"
#include "../state/Score.h"
#include "../board/DrawGameBoard.h"
#include "../board/GameBoard.h"
#include "BlockPiece.h"
#include <string>
using namespace std;

using std::cout;
using std::endl;

//ToDO　現行は7種類のテトリミノに90度ずつずらした4パターンを準備
int trData[][4][4][4] = {
	{	
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
	{	
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
	{	
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
	{
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
	{	
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
	{	
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

int mRotIX = 0;

//テトリミノのゲームボードへの配置
void BlockPiece::SetTertimino(int type, int rx) {
        for (int y = 0; y < gTetriminoHeight; ++y) {
            for (int x = 0; x < gTetriminoWidth; ++x) {
                mTetrimino[x][y] = trData[type][rx][y][x];
            }
        }
    }

//テトリミノの追加　ToDo 関数名の変更
void BlockPiece::AddTertimino() {
	string debug;

	std::random_device rnd;
	std::mt19937 mt(rnd());
	std::uniform_int_distribution<int> type(0,6);

	int gbw = GameBoard::mGbWidth;
	
	SetTeriminoPosX(((gbw - gTetriminoWidth) / 2));
	SetgTeriminoPosY(0);

	SetgTeriminoType(type(mt));
	//ここで色も指定するか?

    SetTertimino(mTetriminoType, mRotIX = 0);
    }

void BlockPiece::DrawTetrimino()
{
    GameBoard gb;

	//GUIアプリとして移植する際にテトリミノを形状と色を持った構造体として定義することで描画を行う関数側から指定する必要をなくす
	int BlockColor = BlockPiece::GetgTeriminoType();
	switch (BlockColor)
	{
	case 0:
		gb.SetColor(static_cast<int>(GameBoard::Color::Cyan), static_cast<int>(GameBoard::Color::Cyan));
		break;
	case 1:
		gb.SetColor(static_cast<int>(GameBoard::Color::Yellow), static_cast<int>(GameBoard::Color::Yellow));
		break;
	case 2:
		gb.SetColor(static_cast<int>(GameBoard::Color::Red), static_cast<int>(GameBoard::Color::Red));
		break;
	case 3:
		gb.SetColor(static_cast<int>(GameBoard::Color::Green), static_cast<int>(GameBoard::Color::Green));
		break;
	case 4:
		gb.SetColor(static_cast<int>(GameBoard::Color::Blue), static_cast<int>(GameBoard::Color::Blue));
		break;
	case 5:
		gb.SetColor(static_cast<int>(GameBoard::Color::DarkRed), static_cast<int>(GameBoard::Color::DarkRed));
		break;
	case 6:
		gb.SetColor(static_cast<int>(GameBoard::Color::Violet), static_cast<int>(GameBoard::Color::Violet));
		break;
	default:
		break;
	}

	//テトリミノの色を設定
	//gb.SetColor(static_cast<int>(BlockColor), static_cast<int>(BlockColor));
   

	for (int i = 0; i < gTetriminoWidth; ++i) {
        int y = mTetriminoPosY + i;
        if (y < 0 || y >= GameBoard::mGbHeight) continue;
			for (int k = 0; k < gTetriminoWidth; ++k) {
				int x = mTetriminoPosX + k;
            if (x < 0 || x >= GameBoard::mGbWidth) continue;
				if (mTetrimino[k][i]) {
					gb.SetCursorPos(gb.GetmGameBoardPosX() + (x + 1) * 2, gb.GetmGameBoardPosY() + y + 1);
					cout << "  ";
				}
			}
    }
}

//接触判定
bool BlockPiece::IsMoveDown() {
	GameBoard gb;

	
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

//左に移動する
bool BlockPiece::IsMoveLeft() {
	GameBoard gb;

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

//右に移動する
bool BlockPiece::IsMoveRight() {
	GameBoard gb;


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

//テトリミノが固定
bool BlockPiece::IsOverLaped() {
	GameBoard gb;


	for (int y = 0; y < gTetriminoHeight; ++y) {
		for (int x = 0; x < gTetriminoWidth; ++x) {
			if (mTetrimino[x][y] != 0 && gb.GetGameBoardValue(x + mTetriminoPosX + 1, y + mTetriminoPosY + 1) != 0)
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
				gb.SetTerimonoValue(x + mTetriminoPosX + 1, y + mTetriminoPosY + 1,BlockPiece::mTetriminoType + 1);
		}
	}

	
}

// 揃ったラインを消去
void BlockPiece::DeleteLine()
{
	Score sc;
	GameBoard gb;


	int nClear = 0;       // 消去したライン数(これに応じてポイント数が上昇)
	for (int ty = 0; ty < gTetriminoHeight; ++ty) {
		int y = ty + GetTetriminoPosY() + 1;
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

int BlockPiece::GetRot() {
	return mRotIX;
}

int BlockPiece::GetgTetriminoPosX() {

	return mTetriminoPosX;
}

void BlockPiece::SetTeriminoPosX(int tpx) {
	mTetriminoPosX = tpx;
}

int BlockPiece::GetTetriminoPosY() {
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

int BlockPiece::GetTeriminoValue(int x,int y) {
	int s = mTetrimino[x][y];
	return s;
}

//int BlockPiece::GetRot() {
//	return mRotIX;
//}

void BlockPiece::SetRot(int r) {
	mRotIX = r;
}

//BlockPiece::BlockPiece(byte* p, int tw, int th) {
//	top = p;
//	= tw;
//
//}




