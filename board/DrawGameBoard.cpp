#include <iostream>


#include "DrawGameBoard.h"
#include "GameBoard.h"
#include "../state/Score.h"

using std::cout;
using std::endl;




//�X�R�A�\��
void DrawGameBoard::DrawScore() {
	GameBoard gb;
	Score sc;
	
	int ScorePosX = (gb.GetmGameBoardPosX() + (gb.GetcGbWidth() + 2) * 3 + 4);
	int ScorePosY = gb.GetmGameBoardPosY();
	
	int score = sc.GetScore();//�X�R�A�擾

	gb.SetCursorPos(ScorePosX,ScorePosY);
	gb.SetColor(static_cast<int>(GameBoard::Color::Gray), static_cast<int>(GameBoard::Color::Black));
	cout << "score:";
	cout.width(8);     
	cout << score;
}
