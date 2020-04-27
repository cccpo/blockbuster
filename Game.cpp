#include <iostream>
#include <Windows.h>
#include <thread>
#include <chrono>
#include <memory>
#include <conio.h>


#include "message/Message.h"
#include "window/window.h"
#include "state/Score.h"
#include "board/GameBoard.h"
#include "board/DrawGameBoard.h"

using std::cout;
using std::endl;



//game
void StartGame() {
		
	//cout << "Game Start!" << endl;
}


//main
int main() {
	Message me;
	//window wi;
	Score st;
	GameBoard gb;
	DrawGameBoard dgb;

	//ゲーム開始
	
	StartGame();
	gb.InitGameBoard();//ゲームボード初期化
	gb.DrawBoard();//ゲームボード外枠の描画(ToDo)
	gb.DrawStage();//ゲームボード内部の描画(ToDo)
	dgb.DrawScore();//スコア表示(ToDO)
	getchar();

	//一時停止
	_getch();
	//cout << st.GetScore() << endl;

	return 0;
}
