#include <iostream>


#include "DrawGameBoard.h"
#include "../state/Score.h"
#include "../agent/BlockPiece.h"


using std::cout;
using std::endl;

//ゲームボード外枠の描画
void DrawGameBoard::DrawBoard(GameBoard gb) {

	gbpy = gb.GetmGameBoardPosY();

	//色設定
	gb.SetColor((int)GameBoard::Color::Gray, (int)(GameBoard::Color::Gray));

	gb.SetCursorPos(gb.mGameBoardPosX, gbpy);
	for (int x = 0; x < GameBoard::mGbWidth + 2; ++x) {
		cout << "  ";
	}

	gb.SetCursorPos(gb.mGameBoardPosX, gbpy + GameBoard::mGbHeight + 1);
	for (int x = 0; x < GameBoard::mGbWidth + 2; ++x) {
		cout << "  ";
	}
	for (int y = gbpy + 1; y < gbpy + GameBoard::mGbHeight + 1; ++y) {
		gb.SetCursorPos(gb.mGameBoardPosX, y);
		cout << "  ";
		gb.SetCursorPos(gb.mGameBoardPosX + (GameBoard::mGbWidth + 1) * 2, y);
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

	gb.SetCursorPos(gbpx, gbpy);
	for (int x = 0; x < GameBoard::mGbWidth + 2; ++x) {
		cout << "  ";
	}

	gb.SetCursorPos(gbpx, gbpy + GameBoard::mGbHeight + 1);
	for (int x = 0; x < GameBoard::mGbWidth + 2; ++x) {
		cout << "  ";
	}
	for (int y = gbpy + 1; y < gbpy + GameBoard::mGbHeight + 1; ++y) {
		gb.SetCursorPos(gbpx, y);
		cout << "  ";
		gb.SetCursorPos(gbpx + (GameBoard::mGbWidth + 1) * 2, y);
		cout << "  ";
	}
}

//ゲームボード内部の描画
void DrawGameBoard::DrawStage(GameBoard gb) {
	BlockPiece bp;

	for (int y = 1; y <= GameBoard::mGbHeight; ++y) {
		gb.SetCursorPos(gb.GetmGameBoardPosX() + 2, y + gb.GetmGameBoardPosY());
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



//スコア表示
void DrawGameBoard::DrawScore() {
	GameBoard gb;
	Score sc;
	
	//スコア表示位置の設定
	int ScorePosX = (gb.GetmGameBoardPosX() + GameBoard::mGbWidth + 2) * 3 + 4;
	int ScorePosY = gb.GetmGameBoardPosY();
	
	int score = sc.GetScore();//スコア取得

	gb.SetCursorPos(ScorePosX,ScorePosY);
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
	gb.SetCursorPos(RotPosX, RotePosY);
	gb.SetColor(static_cast<int>(GameBoard::Color::Gray), static_cast<int>(GameBoard::Color::Black));
	cout << "RotType:";
	cout.width(8);
	cout << RotType;
}
