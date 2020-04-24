#include <iostream>

#include "GameBoard.h"
typedef unsigned char byte;

using std::cout;
using std::endl;

// 盤面初期化
void GameBoard::init_board() {
    // 盤面の中身を全て空に
    for (int x = 1; x < cGbWidth + 1; ++x) {
        for (int y = 1; y < cGbHeight + 1; ++y) {
            g_board[x][y] = cEmpty;     //  盤面を空に
        }
    }
    // 外枠部分に WALL を設定
    for (int x = 0; x < cGbWidth + 2; ++x) {
        g_board[x][0] = g_board[x][cGbHeight + 1] = WALL;
    }
    for (int y = 0; y < cGbHeight + 2; ++y) {
        g_board[0][y] = g_board[cGbWidth + 1][y] = WALL;
    }

    std:cout << "初期化完了" << endl;
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


