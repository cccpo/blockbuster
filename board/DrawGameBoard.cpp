#include <iostream>


#include "DrawGameBoard.h"
#include "GameBoard.h"
#include "../state/Score.h"

using std::cout;
using std::endl;




//スコア表示
void DrawGameBoard::DrawScore() {
	GameBoard gb;
	Score sc;
	
	int ScorePosX = (gb.GetmGameBoardPosX() + (gb.GetcGbWidth() + 2) * 3 + 4);
	int ScorePosY = gb.GetmGameBoardPosY();
	
	int score = sc.GetScore();//スコア取得

	gb.SetCursorPos(ScorePosX,ScorePosY);
	gb.SetColor(static_cast<int>(GameBoard::Color::Gray), static_cast<int>(GameBoard::Color::Black));
	cout << "score:";
	cout.width(8);     
	cout << score;
}
