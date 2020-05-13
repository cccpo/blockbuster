#include <iostream>

#include "GameBoard.h"

#include "../state/Score.h"

//#include "DrawGameBoard.h"
typedef unsigned char byte;

using std::cout;
using std::endl;

int gBoard[GameBoard::mGbWidth + 2][GameBoard::mGbHeight + 2];

// ゲームボード初期化
void GameBoard::InitGameBoard() {

    //ゲームボード内部の初期化
    for (int x = 1; x < mGbWidth + 1; ++x) {
        for (int y = 1; y < mGbHeight + 1; ++y) {
            gBoard[x][y] = GetmEmpty();    
        }
    }
  
    //ゲームボード外枠の初期化
    for (int x = 0; x <= mGbWidth + 1; ++x) {
        gBoard[x][0] = gBoard[x][mGbHeight + 1] = mOuterFrame;
    }
    for (int y = 0; y <= mGbHeight + 1; ++y) {
        gBoard[0][y] = gBoard[mGbWidth + 1][y] = mOuterFrame;
    }

};

int GameBoard::GetGameBoardValue(int x, int y) {
    int s = gBoard[x][y];
    return s;
}

void GameBoard::SetTerimonoValue(int x,int y,int val) {
    gBoard[x][y] = val;
}

void GameBoard::SetColor(int fg, int bg) {
    HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
    WORD attr = 0;
    if (fg & static_cast<int>(GameBoard::Mask::Intensity))
        attr |= FOREGROUND_INTENSITY;
    if (fg & static_cast<int>(GameBoard::Mask::RedMask))
        attr |= FOREGROUND_RED;
    if (fg & static_cast<int>(GameBoard::Mask::GreenMask))
        attr |= FOREGROUND_GREEN;
    if (fg & static_cast<int>(GameBoard::Mask::BlueMask))
        attr |= FOREGROUND_BLUE;

    if (bg & static_cast<int>(GameBoard::Mask::Intensity))
        attr |= BACKGROUND_INTENSITY;
    if (bg & static_cast<int>(GameBoard::Mask::RedMask))
        attr |= BACKGROUND_RED;
    if (bg & static_cast<int>(GameBoard::Mask::GreenMask))
        attr |= BACKGROUND_GREEN;
    if (bg & static_cast<int>(GameBoard::Mask::BlueMask))
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

void GameBoard::Down(int y) {

    while (y > 1) {
        for (int x = 1; x <= mGbWidth; ++x)
            gBoard[x][y] = gBoard[x][y - 1];     // １行下に移動
        --y;      //  上の行に
    }
    for (int x = 1; x <= mGbWidth; ++x)
        gBoard[x][1] = 0;     // 最上行は空に
}



int GameBoard::GetmEmpty() const{
    return mEmpty;
}



int GameBoard::GetmGameBoardPosX() const{
    return mGameBoardPosX;
}

int GameBoard::GetmGameBoardPosY() const{
    return mGameBoardPosY;
}

GameBoard::GameBoard() :mGameBoardPosX(1),mGameBoardPosY(2){

}

//　ゲームボードを生成する座標及びを与える
GameBoard::GameBoard(int x,int y) :mGameBoardPosX(x),mGameBoardPosY(y){
}




