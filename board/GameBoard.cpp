#include <iostream>

#include "GameBoard.h"
#include "DrawGameBoard.h"
typedef unsigned char byte;

using std::cout;
using std::endl;

// ゲームボード初期化
void GameBoard::InitGameBoard() {

    //ゲームボード内部の初期化
    for (int x = { 1 }; x < cGbWidth + 1; ++x) {
        for (int y = { 1 }; y < cGbHeight + 1; ++y) {
            gBoard[x][y] = cEmpty;    
        }
    }
  
    //ゲームボード外枠の初期化
    for (int x = { 0 }; x <= cGbWidth + 1; ++x) {
        gBoard[x][0] = gBoard[x][cGbHeight + 1] = OuterFrame;
    }
    for (int y = { 0 }; y <= cGbHeight + 1; ++y) {
        gBoard[0][y] = gBoard[cGbWidth + 1][y] = OuterFrame;
    }

};

//ゲームボード外枠の描画(ToDo)
void GameBoard::DrawBoard() {
    GameBoard gb;

    //色設定
    SetColor(COL_GRAY, COL_GRAY);

    SetCursorPos(cGameBoardPosX, cGameBoardPosY);
    for (int x = { 0 }; x < GameBoard::GetcGbWidth() + 2; ++x) {
        cout << "  ";
    }

    SetCursorPos(cGameBoardPosX, cGameBoardPosY + GameBoard::GetcGbHeight() + 1);
    for (int x = { 0 }; x < GameBoard::GetcGbWidth() + 2; ++x) {
        cout << "  ";
    }
    for (int y = cGameBoardPosY + 1; y < cGameBoardPosY + GameBoard::GetcGbHeight() + 1; ++y) {
        SetCursorPos(cGameBoardPosX, y);
        cout << "  ";
        SetCursorPos(cGameBoardPosX + (GameBoard::GetcGbWidth() + 1) * 2, y);
        cout << "  ";
    }
}


void GameBoard::DrawStage() {
    GameBoard gb;
  

    int cGbWidth = GameBoard::GetcGbWidth();
    int cGbHeight = GameBoard::GetcGbHeight();

     //gBoard[5][6] = 1;

    for (int y = 1; y <= cGbHeight; ++y) {
        SetCursorPos(cGameBoardPosX + 2, y + cGameBoardPosY);
        for (int x = 1; x <= GameBoard::GetcGbWidth(); ++x) {
            if (gBoard[x][y] != GameBoard::GetcEmpty())
                GameBoard::SetColor(COL_GRAY, COL_GREEN);
            else
                GameBoard::SetColor(COL_GRAY, COL_BLACK);
            cout << "  ";
        }
    }
}

void GameBoard::SetColor(int fg, int bg) {
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

void GameBoard::SetCursorPos(int x, int y) {
    HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(hCons, pos);
}

int GameBoard::GetcEmpty() {
    return cEmpty;
}

int GameBoard::GetcGbWidth() {
    return cGbWidth;
};

//void GameBoard::SetcGbWidth(int w) {
//    this->cGbWidth;
//};

int GameBoard::GetcGbHeight() {
    return cGbHeight;
};

//void GameBoard::SetcGbHeight(int h) {
//    this->cGbHeight;
//};

//byte GameBoard::GetgBoard() {
//    return gBoard[][];
//}




