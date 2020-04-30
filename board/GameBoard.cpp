#include <iostream>

#include "GameBoard.h"
#include "../agent/BlockPiece.h"

//#include "DrawGameBoard.h"
typedef unsigned char byte;

using std::cout;
using std::endl;

// ゲームボード初期化
void GameBoard::InitGameBoard() {

    //ゲームボード内部の初期化
    for (int x = 1; x < cGbWidth + 1; ++x) {
        for (int y = 1; y < cGbHeight + 1; ++y) {
            gBoard[x][y] = cEmpty;    
        }
    }
  
    //ゲームボード外枠の初期化
    for (int x = 0; x <= cGbWidth + 1; ++x) {
        gBoard[x][0] = gBoard[x][cGbHeight + 1] = mOuterFrame;
    }
    for (int y = 0; y <= cGbHeight + 1; ++y) {
        gBoard[0][y] = gBoard[cGbWidth + 1][y] = mOuterFrame;
    }

};

//ゲームボード外枠の描画(ToDO DrawGameBoardに移植予定)
void GameBoard::DrawBoard() {
    GameBoard gb;

    //色設定
    SetColor(static_cast<int>(GameBoard::Color::Gray), static_cast<int>(GameBoard::Color::Blue));

    SetCursorPos(cGameBoardPosX, cGameBoardPosY);
    for (int x = 0; x < gb.GetcGbWidth() + 2; ++x) {
        cout << "  ";
    }

    SetCursorPos(cGameBoardPosX, cGameBoardPosY + gb.GetcGbHeight() + 1);
    for (int x = 0; x < gb.GetcGbWidth() + 2; ++x) {
        cout << "  ";
    }
    for (int y = cGameBoardPosY + 1; y < cGameBoardPosY + gb.GetcGbHeight() + 1; ++y) {
        SetCursorPos(cGameBoardPosX, y);
        cout << "  ";
        SetCursorPos(cGameBoardPosX + (gb.GetcGbWidth() + 1) * 2, y);
        cout << "  ";
    }
}

//ゲームボード内部の描画(ToDO DrawGameBoardに移植予定)
void GameBoard::DrawStage() {
    GameBoard gb;
  

    int cGbWidth = gb.GetcGbWidth();
    int cGbHeight = gb.GetcGbHeight();

    for (int y = 1; y <= cGbHeight; ++y) {
        SetCursorPos(cGameBoardPosX + 2, y + cGameBoardPosY);
        for (int x = 1; x <= gb.GetcGbWidth(); ++x) {
            if (gBoard[x][y] != gb.GetcEmpty())
                gb.SetColor(static_cast<int>(GameBoard::Color::Gray), static_cast<int>(GameBoard::Color::Green));
            else
                gb.SetColor(static_cast<int>(GameBoard::Color::Gray), static_cast<int>(GameBoard::Color::Black));
            cout << "  ";
        }
    }
}
//
//bool GameBoard::MoveDown() {
//    BlockPiece bp;
//
//    int tpx = gTeriminoPosX;
//    int tpy = bp.GetgTetriminoPosY();
//
//    for (int x = 0; x < gTetriminoWidth; ++x)
//        for (int y = gTetriminoHeight; --y >= 0;) {
//            if (bp.SetTeriminoValue(x,y) != 0) {
//                if (gBoard[x + tpx + 1][y + tpy + 1 + 1] != 0)
//                    return false;              //  すぐ下に壁 or 固定ブロックがある
//                break;
//            }
//        }
//    return false;
//}

int GameBoard::SetTeriminoValue(int x, int y) {
    int s = gBoard[x][y];
    return s;
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

//int* GameBoard::GetbBoard() {
//    return *gBoard[][cGbHeight + 2];
//}

int GameBoard::GetcEmpty() {
    return cEmpty;
}

int GameBoard::GetcGbWidth() {
    return cGbWidth;
};


int GameBoard::GetcGbHeight() {
    return cGbHeight;
};

int GameBoard::GetcGameBoardPosX() {
    return cGameBoardPosX;
}

int GameBoard::GetcGameBoardPosY() {
    return cGameBoardPosY;
}

//byte(GameBoard::* getAry())[cGbHeight + 2]{
//    return GameBoard::gBoard;
//}

/*te GameBoard::(&f())[100]{
    return &gBoard;
}*/

//byte GameBoard::GetgBoard() {
//    return gBoard[][];
//}

//GameBoard::GameBoard() {
//    for (int i = 0; i < cGbWidth + 2; ++i)
//    {
//        for (int jj = 0; jj < cGbHeight + 2; ++jj)
//        {
//            gBoard[i][jj] = (i + 1) * jj;
//        }
//    }
//}



