#include <iostream>


#include "DrawGameBoard.h"
#include "GameBoard.h"
#include "../state/Score.h"
#include "../agent/BlockPiece.h"

using std::cout;
using std::endl;




//スコア表示
void DrawGameBoard::DrawScore() {
	GameBoard gb;
	Score sc;
	
	int ScorePosX = (gb.GetmGameBoardPosX() + GameBoard::cGbWidth + 2) * 3 + 4;
	int ScorePosY = gb.GetmGameBoardPosY();
	
	int score = sc.GetScore();//スコア取得

	gb.SetCursorPos(ScorePosX,ScorePosY);
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

	int RotPosX = (gb.GetmGameBoardPosX() + (GameBoard::cGbWidth + 2) * 3 + 4);
	int RotePosY = gb.GetmGameBoardPosY() + 2;

	int RotType = bp.GetRot();
	gb.SetCursorPos(RotPosX, RotePosY);
	gb.SetColor(static_cast<int>(GameBoard::Color::Gray), static_cast<int>(GameBoard::Color::Black));
	cout << "RotType:";
	cout.width(8);
	cout << RotType;
}
