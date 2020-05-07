#include <iostream>

#include "GameBoard.h"
#include "../agent/BlockPiece.h"
#include "../state/Score.h"

//#include "DrawGameBoard.h"
typedef unsigned char byte;

using std::cout;
using std::endl;

int gBoard[cGbWidth + 2][cGbHeight + 2];

// �Q�[���{�[�h������
void GameBoard::InitGameBoard() {

    //�Q�[���{�[�h�����̏�����
    for (int x = 1; x < cGbWidth + 1; ++x) {
        for (int y = 1; y < cGbHeight + 1; ++y) {
            gBoard[x][y] = GetmEmpty();    
        }
    }
  
    //�Q�[���{�[�h�O�g�̏�����
    for (int x = 0; x <= cGbWidth + 1; ++x) {
        gBoard[x][0] = gBoard[x][cGbHeight + 1] = mOuterFrame;
    }
    for (int y = 0; y <= cGbHeight + 1; ++y) {
        gBoard[0][y] = gBoard[cGbWidth + 1][y] = mOuterFrame;
    }

};

//�Q�[���{�[�h�O�g�̕`��(ToDO DrawGameBoard�ɈڐA�\��)
void GameBoard::DrawBoard() {
    int gbpx = GetmGameBoardPosX();
    int gbpy = GetmGameBoardPosY();

    //�F�ݒ�
    SetColor(static_cast<int>(GameBoard::Color::Gray), static_cast<int>(GameBoard::Color::Blue));

    SetCursorPos(gbpx, gbpy);
    for (int x = 0; x < GetcGbWidth() + 2; ++x) {
        cout << "  ";
    }

    SetCursorPos(gbpx, gbpy + GetcGbHeight() + 1);
    for (int x = 0; x < GetcGbWidth() + 2; ++x) {
        cout << "  ";
    }
    for (int y = gbpy + 1; y < gbpy + GetcGbHeight() + 1; ++y) {
        SetCursorPos(gbpx, y);
        cout << "  ";
        SetCursorPos(gbpx + (GetcGbWidth() + 1) * 2, y);
        cout << "  ";
    }
}

//�Q�[���{�[�h�����̕`��(ToDO DrawGameBoard�ɈڐA�\��)
void GameBoard::DrawStage() {

    for (int y = 1; y <= cGbHeight; ++y) {
        SetCursorPos(GetmGameBoardPosX() + 2, y + GetmGameBoardPosY());
        for (int x = 1; x <= GetcGbWidth(); ++x) {
            if (gBoard[x][y] != GetmEmpty())
                SetColor(static_cast<int>(GameBoard::Color::Gray), static_cast<int>(GameBoard::Color::Green));
            else
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
        for (int x = 1; x <= cGbWidth; ++x)
            gBoard[x][y] = gBoard[x][y - 1];     // �P�s���Ɉړ�
        --y;      //  ��̍s��
    }
    for (int x = 1; x <= cGbWidth; ++x)
        gBoard[x][1] = 0;     // �ŏ�s�͋��
}



int GameBoard::GetmEmpty() const{
    return mEmpty;
}

int GameBoard::GetcGbWidth() const{
    return cGbWidth;
};


int GameBoard::GetcGbHeight() const{
    return cGbHeight;
};

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



