#include "DrawGameBoard.h"
#include "GameBoard.h"

void DrawGameBoard::DrawBoard() {
	DrawGameBoard dgb;
	GameBoard gb;
	
	//êFê›íË
	dgb.SetColor(COL_BLUE, COL_BLUE);
    SetCursorPos(BD_ORG_X, BD_ORG_Y);
	for (int x = { 0 }; x < gb.GetcGbWidth() + 2; ++x) {
        std::cout << "  "; 
    }

    SetCursorPos(BD_ORG_X, BD_ORG_Y + gb.GetcGbHeight() + 1);
	for (int x = { 0 }; x < gb.GetcGbWidth() + 2; ++x) {
        std::cout << "  ";
    }
    for (int y = BD_ORG_Y + 1; y < BD_ORG_Y + gb.GetcGbHeight() + 1; ++y) {
        SetCursorPos(BD_ORG_X, y);
        std::cout << "  ";  
        SetCursorPos(BD_ORG_X + (gb.GetcGbWidth() + 1) * 2, y);
        std::cout << "  ";    
    }
}

//
//	fg 
//  bg îwåiêF
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

//DrawGameBoard(){}