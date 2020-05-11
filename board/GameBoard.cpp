#include <iostream>

#include "GameBoard.h"
#include "../agent/BlockPiece.h"
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

//ゲームボード外枠の描画(ToDO DrawGameBoardに移植予定)
void GameBoard::DrawBoard() {
    int gbpx = GetmGameBoardPosX();
    int gbpy = GetmGameBoardPosY();

    //色設定
    SetColor(static_cast<int>(GameBoard::Color::Gray), static_cast<int>(GameBoard::Color::Gray));

    SetCursorPos(gbpx, gbpy);
    for (int x = 0; x < mGbWidth + 2; ++x) {
        cout << "  ";
    }

    SetCursorPos(gbpx, gbpy + mGbHeight + 1);
    for (int x = 0; x < mGbWidth + 2; ++x) {
        cout << "  ";
    }
    for (int y = gbpy + 1; y < gbpy + mGbHeight + 1; ++y) {
        SetCursorPos(gbpx, y);
        cout << "  ";
        SetCursorPos(gbpx + ( mGbWidth + 1) * 2, y);
        cout << "  ";
    }
}

//ゲームボード内部の描画(ToDO DrawGameBoardに移植予定)
void GameBoard::DrawStage() {

    for (int y = 1; y <= mGbHeight; ++y) {
        SetCursorPos(GetmGameBoardPosX() + 2, y + GetmGameBoardPosY());
        for (int x = 1; x <= mGbWidth; ++x) {
            //空ではないブロックは緑で固定化→
            if (gBoard[x][y] != GetmEmpty()){
                int BlockColor = GetGameBoardValue(x, y);
                switch (BlockColor)
                {
                case 1:
                    SetColor(static_cast<int>(GameBoard::Color::Cyan), static_cast<int>(GameBoard::Color::Cyan));
                    break;
                case 2:
                    SetColor(static_cast<int>(GameBoard::Color::Yellow), static_cast<int>(GameBoard::Color::Yellow));
                    break;
                case 3:
                    SetColor(static_cast<int>(GameBoard::Color::Red), static_cast<int>(GameBoard::Color::Red));
                    break;
                case 4:
                    SetColor(static_cast<int>(GameBoard::Color::Green), static_cast<int>(GameBoard::Color::Green));
                    break;
                case 5:
                    SetColor(static_cast<int>(GameBoard::Color::Blue), static_cast<int>(GameBoard::Color::Blue));
                    break;
                case 6:
                    SetColor(static_cast<int>(GameBoard::Color::DarkRed), static_cast<int>(GameBoard::Color::DarkRed));
                    break;
                case 7:
                    SetColor(static_cast<int>(GameBoard::Color::Violet), static_cast<int>(GameBoard::Color::Violet));
                    break;
                default:
                    break;
                }
                //SetColor(static_cast<int>(GameBoard::Color::Gray), static_cast<int>(GameBoard::Color::Green));
            }else
                SetColor(static_cast<int>(GameBoard::Color::Gray), static_cast<int>(GameBoard::Color::Black));
            cout << "  ";
        }
    }
}

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



