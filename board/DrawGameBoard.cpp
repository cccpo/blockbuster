#include <iostream>


#include "DrawGameBoard.h"
#include "GameBoard.h"
#include "../state/Score.h"
#include "../agent/BlockPiece.h"


using std::cout;
using std::endl;

//ゲームボード外枠の描画
void DrawGameBoard::DrawBoard() {
	GameBoard gb;
	
	int gbpx = gb.GetmGameBoardPosX();
	int gbpy = gb.GetmGameBoardPosY();

	//色設定
	gb.SetColor(static_cast<int>(GameBoard::Color::Gray), static_cast<int>(GameBoard::Color::Gray));

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
