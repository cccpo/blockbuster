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
	
	const int cScorePosX = (gb.GetcGameBoardPosX() + (gb.GetcGbWidth() + 2) * 3 + 4);
	const int cScorePosY = gb.GetcGameBoardPosY();
	
	int score = sc.GetScore();

	gb.SetCursorPos(cScorePosX,cScorePosY);
	gb.SetColor(static_cast<int>(GameBoard::Color::Gray), static_cast<int>(GameBoard::Color::Black));
	cout << "score:";
	cout.width(8);     
	cout << score;
}
