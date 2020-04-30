#include <iostream>
#include <Windows.h>
#include <thread>
#include <chrono>
#include <memory>
#include <conio.h>
#include <chrono>

#include "Game.h"
//#include "message/Message.h"
//#include "window/window.h"
//#include "state/Score.h"
#include "board/GameBoard.h"
#include "board/DrawGameBoard.h"
#include "agent/BlockPiece.h"

using std::cout;
using std::endl;



//bool MoveDown() {
//    BlockPiece bp;
//
//    int tpx = bp.GetgTetriminoPosX();
//    int tpy = bp.GetgTetriminoPosY();
//
//    byte* ter = bp.GetTetrimino();
//
//    for (int x = 0; x < cTetriminoWidth; ++x)
//        for (int y = cTetriminoHeight; --y >= 0;) {
//            if (ter[x][y] != 0) {
//                if (gBoard[x + tpx + 1][y + tpy + 1 + 1] != 0)
//                    return false;              //  すぐ下に壁 or 固定ブロックがある
//                break;
//            }
//        }
//}

//game
void StartGame() {

	GameBoard gb;
	DrawGameBoard dgb;
	BlockPiece bp;


	gb.InitGameBoard();//ゲームボード初期化
	gb.DrawBoard();//ゲームボード外枠の描画(ToDo)
	gb.DrawStage();//ゲームボード内部の描画(ToDo)
	dgb.DrawScore();//スコア表示(ToDO)
	bp.SetTertimino();
	bp.DrawTetrimino();
	int bpy = gTeriminoPosY;
	
	//while (bpy < gb.GetcGbHeight()) {       // 落下テトリスが盤面下端に来るまでループ
	//	Sleep(1000);       // 1秒ウェイト
	//	++bpy;             // 落下テトリスを1行落下
	//	bp.SetgTeriminoPosY(bpy);
	//	gb.DrawStage();//ゲームボード内部の描画(ToDo)
	//	bp.DrawTetrimino();
	//}

	for (int cnt = 1; ; ++cnt) {
		bool update = false;        // 画面更新フラグ
		if (cnt % FallInterval == 0)
		{      // 落下処理
			if (!bp.MoveDown()) {
				gb.DrawStage();//ゲームボード内部の描画(ToDo)
				bp.DrawTetrimino();
				return;
			}
			++bpy;     // 落下中テトリスをひとつ下に移動
			bp.SetgTeriminoPosY(bpy);
			update = true;
		}
		if (update) {
				gb.DrawStage();//ゲームボード内部の描画(ToDo)
				bp.DrawTetrimino();
		}
		Sleep(10);
	}

}


//main
int main() {
	//ゲーム開始
	StartGame();

	getchar();

	//一時停止
	_getch();
	//cout << st.GetScore() << endl;

	return 0;
}




