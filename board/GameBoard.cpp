#include <iostream>

#include "GameBoard.h"
typedef unsigned char byte;

using std::cout;
using std::endl;

// ”Õ–Ê‰Šú‰»
void GameBoard::init_board() {
    // ”Õ–Ê‚Ì’†g‚ğ‘S‚Ä‹ó‚É
    for (int x = 1; x < cGbWidth + 1; ++x) {
        for (int y = 1; y < cGbHeight + 1; ++y) {
            g_board[x][y] = cEmpty;     //  ”Õ–Ê‚ğ‹ó‚É
        }
    }
    // ŠO˜g•”•ª‚É WALL ‚ğİ’è
    for (int x = 0; x < cGbWidth + 2; ++x) {
        g_board[x][0] = g_board[x][cGbHeight + 1] = WALL;
    }
    for (int y = 0; y < cGbHeight + 2; ++y) {
        g_board[0][y] = g_board[cGbWidth + 1][y] = WALL;
    }

    std:cout << "‰Šú‰»Š®—¹" << endl;
};

int GameBoard::GetcGbWidth() {
    return cGbWidth;
};

void GameBoard::SetcGbWidth(int w) {
    this->cGbWidth;
};

int GameBoard::GetcGbHeight() {
    return cGbHeight;
};

void GameBoard::SetcGbHeight(int h) {
    this->cGbHeight;
};


