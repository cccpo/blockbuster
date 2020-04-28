#include <iostream>
#include <Windows.h>
#include <thread>
#include <chrono>
#include <memory>
#include <conio.h>

//#include "Game.h"
//#include "message/Message.h"
//#include "window/window.h"
//#include "state/Score.h"
#include "board/GameBoard.h"
#include "board/DrawGameBoard.h"
#include "agent/BlockPiece.h"

using std::cout;
using std::endl;



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
	int bpy = bp.GetgTetriminoPosY();
	while (bpy < gb.GetcGbHeight()) {       // 落下テトリスが盤面下端に来るまでループ
		Sleep(100);       // 0.1秒ウェイト
		++bpy;             // 落下テトリスを1行落下
		bp.SetgTeriminoPosY(bpy);
		gb.DrawStage();//ゲームボード内部の描画(ToDo)
		bp.DrawTetrimino();
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




