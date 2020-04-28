#include <iostream>

#include "GameBoard.h"
//#include "DrawGameBoard.h"
typedef unsigned char byte;

using std::cout;
using std::endl;

// ÉQÅ[ÉÄÉ{Å[Éhèâä˙âª
void GameBoard::InitGameBoard() {

    //ÉQÅ[ÉÄÉ{Å[Éhì‡ïîÇÃèâä˙âª
    for (int x = 1; x < cGbWidth + 1; ++x) {
        for (int y = 1; y < cGbHeight + 1; ++y) {
            gBoard[x][y] = cEmpty;    
        }
    }
  
    //ÉQÅ[ÉÄÉ{Å[ÉhäOògÇÃèâä˙âª
    for (int x = 0; x <= cGbWidth + 1; ++x) {
        gBoard[x][0] = gBoard[x][cGbHeight + 1] = cOuterFrame;
    }
    for (int y = 0; y <= cGbHeight + 1; ++y) {
        gBoard[0][y] = gBoard[cGbWidth + 1][y] = cOuterFrame;
    }

};

//ÉQÅ[ÉÄÉ{Å[ÉhäOògÇÃï`âÊ(ToDO DrawGameBoardÇ…à⁄êAó\íË)
void GameBoard::DrawBoard() {
    GameBoard gb;

    //êFê›íË
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

//ÉQÅ[ÉÄÉ{Å[Éhì‡ïîÇÃï`âÊ(ToDO DrawGameBoardÇ…à⁄êAó\íË)
void GameBoard::DrawStage() {
    GameBoard gb;
  

    int cGbWidth = gb.GetcGbWidth();
    int cGbHeight = gb.GetcGbHeight();

    //gBoard[4][5] = 1;
    for (int i = 0; i < cGbWidth; ++i) {
        gBoard[i][20] = 1;
    }

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


//byte GameBoard::GetgBoard() {
//    return gBoard[][];
//}




