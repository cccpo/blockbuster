#include <iostream>


#include "DrawGameBoard.h"
#include "../state/Score.h"
#include "../agent/BlockPiece.h"


using std::cout;
using std::endl;

//ゲームボード外枠の描画
void DrawGameBoard::DrawBoard(GameBoard& gb) {

	gbpy = gb.GetmGameBoardPosY();

	//色設定
	gb.SetColor((int)GameBoard::Color::Gray, (int)(GameBoard::Color::Gray));

	SetCursorPos(gb.mGameBoardPosX, gbpy);
	for (int x = 0; x < GameBoard::mGbWidth + 2; ++x) {
		cout << "  ";
	}

	SetCursorPos(gb.mGameBoardPosX, gbpy + GameBoard::mGbHeight + 1);
	for (int x = 0; x < GameBoard::mGbWidth + 2; ++x) {
		cout << "  ";
	}
	for (int y = gbpy + 1; y < gbpy + GameBoard::mGbHeight + 1; ++y) {
		SetCursorPos(gb.mGameBoardPosX, y);
		cout << "  ";
		SetCursorPos(gb.mGameBoardPosX + (GameBoard::mGbWidth + 1) * 2, y);
		cout << "  ";
	}
}

//ゲームボード外枠の描画(外枠色指定)
void DrawGameBoard::DrawBoard(GameBoard gb, GameBoard::Color cl) 
{
	gbpx = gb.GetmGameBoardPosX();
	gbpy = gb.GetmGameBoardPosY();

	//色設定
	gb.SetColor(static_cast<int>(cl), static_cast<int>(cl));

	SetCursorPos(gbpx, gbpy);
	for (int x = 0; x < GameBoard::mGbWidth + 2; ++x) {
		cout << "  ";
	}

	SetCursorPos(gbpx, gbpy + GameBoard::mGbHeight + 1);
	for (int x = 0; x < GameBoard::mGbWidth + 2; ++x) {
		cout << "  ";
	}
	for (int y = gbpy + 1; y < gbpy + GameBoard::mGbHeight + 1; ++y) {
		SetCursorPos(gbpx, y);
		cout << "  ";
		SetCursorPos(gbpx + (GameBoard::mGbWidth + 1) * 2, y);
		cout << "  ";
	}
}

//ゲームボード内部の描画
void DrawGameBoard::DrawStage(GameBoard gb) {
	BlockPiece bp;

	for (int y = 1; y <= GameBoard::mGbHeight; ++y) {
		SetCursorPos(gb.GetmGameBoardPosX() + 2, y + gb.GetmGameBoardPosY());
		for (int x = 1; x <= GameBoard::mGbWidth; ++x) {
			//空ではないブロックは緑で固定化→
			if (gb.GetGameBoardValue(x,y) != gb.GetmEmpty()) {


				int Color = bp.TetriminoTypeToColor(gb.GetGameBoardValue(x, y) - 1);

				//テトリミノの色を設定
				gb.SetColor(static_cast<int>(Color), static_cast<int>(Color));
			}
			else
				gb.SetColor(static_cast<int>(GameBoard::Color::Gray), static_cast<int>(GameBoard::Color::Black));
			cout << "  ";
		}
	}
}

void DrawGameBoard::SetCursorPos(int x, int y) {
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hCons, pos);
}


//スコア表示
void DrawGameBoard::DrawScore() {
	GameBoard gb;
	Score sc;
	
	//スコア表示位置の設定
	int ScorePosX = (gb.GetmGameBoardPosX() + GameBoard::mGbWidth + 2) * 3 + 4;
	int ScorePosY = gb.GetmGameBoardPosY();
	
	int score = sc.GetScore();//スコア取得

	SetCursorPos(ScorePosX,ScorePosY);
	//スコアの色を設定
	gb.SetColor(static_cast<int>(GameBoard::Color::Gray), static_cast<int>(GameBoard::Color::Black));
	
	cout << "score:";
	cout.width(8);     
	cout << score;
}

//デバック用テスト関数
void DrawGameBoard::DrawRotType() {
	GameBoard gb;
	Score sc;
	BlockPiece bp;

	int RotPosX = (gb.GetmGameBoardPosX() + (GameBoard::mGbWidth + 2) * 3 + 4);
	int RotePosY = gb.GetmGameBoardPosY() + 2;

	int RotType = bp.GetRot();
	SetCursorPos(RotPosX, RotePosY);
	gb.SetColor(static_cast<int>(GameBoard::Color::Gray), static_cast<int>(GameBoard::Color::Black));
	cout << "RotType:";
	cout.width(8);
	cout << RotType;
}
