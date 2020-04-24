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

	//ƒQ[ƒ€ŠJŽn
	
	StartGame();
	gb.InitGameBoard();
	dgb.DrawBoard();
	//gb.DrawStage();
	dgb.DrawScore();

	//ˆêŽž’âŽ~
	_getch();
	//cout << st.GetScore() << endl;

	return 0;
}
