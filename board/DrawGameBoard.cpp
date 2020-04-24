#include "DrawGameBoard.h"
#include "GameBoard.h"
#include "../State/Score.h"

using std::cout;
using std::endl;

void DrawGameBoard::DrawBoard() {
	GameBoard gb;
	
	//色設定
	SetColor(COL_YELLOW, COL_YELLOW);

    SetCursorPos(cGameBoardPosX, cGameBoardPosY);
	for (int x = { 0 }; x < gb.GetcGbWidth() + 2; ++x) {
        cout << "  "; 
    }

    SetCursorPos(cGameBoardPosX, cGameBoardPosY + gb.GetcGbHeight() + 1);
	for (int x = { 0 }; x < gb.GetcGbWidth() + 2; ++x) {
        cout << "  ";
    }
    for (int y = cGameBoardPosY + 1; y < cGameBoardPosY + gb.GetcGbHeight() + 1; ++y) {
        SetCursorPos(cGameBoardPosX, y);
        cout << "  ";  
        SetCursorPos(cGameBoardPosX + (gb.GetcGbWidth() + 1) * 2, y);
        cout << "  ";    
    }
}


//スコア表示
void DrawGameBoard::DrawScore() {
	GameBoard gb;
	Score sc;

	const int cScorePosX = (cGameBoardPosX + (gb.GetcGbWidth() + 2) * 3 + 4);
	const int cScorePosY = cGameBoardPosY;
	
	SetCursorPos(cScorePosX,cScorePosY);
	SetColor(COL_GRAY, COL_BLACK);
	cout << "SCORE:";
	cout.width(8);     
	cout << sc.GetScore();
}
//
//	fg 
//  bg 背景色
//
void DrawGameBoard::SetColor(int fg, int bg) {
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD attr = 0;
	if (fg & COL_INTENSITY)
		attr |= FOREGROUND_INTENSITY;
	if (fg & COL_RED_MASK)
		attr |= FOREGROUND_RED;
	if (fg & COL_GREEN_MASK)
		attr |= FOREGROUND_GREEN;
	if (fg & COL_BLUE_MASK)
		attr |= FOREGROUND_BLUE;

	if (bg & COL_INTENSITY)
		attr |= BACKGROUND_INTENSITY;
	if (bg & COL_RED_MASK)
		attr |= BACKGROUND_RED;
	if (bg & COL_GREEN_MASK)
		attr |= BACKGROUND_GREEN;
	if (bg & COL_BLUE_MASK)
		attr |= BACKGROUND_BLUE;
	SetConsoleTextAttribute(hCons, attr);
}

void DrawGameBoard::SetCursorPos(int x, int y) {
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hCons, pos);
}

