#include <iostream>

#include "GameBoard.h"
#include "DrawGameBoard.h"
typedef unsigned char byte;

using std::cout;
using std::endl;

// ゲームボード初期化
void GameBoard::InitGameBoard() {

    //ゲームボード内部の初期化
    for (int x = { 0 }; x < cGbWidth; ++x) {
        for (int y = { 0 }; y < cGbHeight; ++y) {
            gBoard[x][y] = cEmpty;    
        }
    }
  
    //ゲームボード外枠の初期化
    for (int x = { 0 }; x < cGbWidth + 2; ++x) {
        gBoard[x][0] = gBoard[x][cGbHeight + 1] = OuterFrame;
    }
    for (int y = { 0 }; y < cGbHeight + 2; ++y) {
        gBoard[0][y] = gBoard[cGbWidth + 1][y] = OuterFrame;
    }

};

void GameBoard::DrawStage() {
    GameBoard gb;
    DrawGameBoard dgb;

    int cGbWidth = gb.GetcGbWidth();
    int cGbHeight = gb.GetcGbHeight();

    for (int y = 1; y <= cGbHeight; ++y) {
        SetCursorPos(cGameBoardPosX + 2, y + cGameBoardPosY);
        for (int x = 1; x <= gb.GetcGbWidth(); ++x) {
            if (gBoard[x][y] != gb.GetcEmpty())
                dgb.SetColor(COL_GRAY, COL_BLUE);
            else
                dgb.SetColor(COL_GRAY, COL_BLACK);
            cout << "  ";
        }
    }
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




