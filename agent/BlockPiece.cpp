#include <stdlib.h>
#include <random>

#include "../board/DrawGameBoard.h"
#include "../board/GameBoard.h"
#include "BlockPiece.h"

using std::cout;
using std::endl;



//void BlockPiece::SetTertimino(int type, int rx) {
//        for (int y = 0; y < cTetriminoHeight; ++y) {
//            for (int x = 0; x < cTetriminoWidth; ++x) {
//                g_tetris[x][y] = trData[type][rx][y][x];
//            }
//        }
//    }

//void BlockPiece::SetTertimino() {
//	GameBoard gb;
//
//	std::random_device rnd;
//	std::mt19937 mt(rnd());
//	std::uniform_int_distribution<int> type(0,5);
//	
//
//	gTetriminoPosX = { (gb.GetcGbWidth() - cTetriminoWidth) / 2 };
//	gTetriminoPosY = { 0 };
//	gTetriminoType = (type(mt));
//    SetTertimino(gTetriminoType, gRotIX = 0);
//    }

//void BlockPiece::DrawTetrimino()
//{
//    GameBoard gb;
//    DrawGameBoard dgb;
//
//    dgb.SetColor(COL_BLUE, COL_BLUE);
//    for (int i = 0; i < cTetriminoWidth; ++i) {
//        int y = gTetriminoPosY + i;
//        if (y < 0 || y >= cTetriminoHeight) continue;
//        for (int k = 0; k < cTetriminoWidth; ++k) {
//            int x = gTetriminoPosX + k;
//            if (x < 0 || x >= gb.GetcGbWidth()) continue;
//            if (g_tetris[k][i]) {
//                dgb.SetCursorPos(gb.GetcGbHeight()+ (x + 1) * 2, gTetriminoPosY + y + 1);
//                cout << "  ";
//            }
//        }
//    }
//}



