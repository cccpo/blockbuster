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
//#include "board/GameBoard.h"
//#include "board/DrawGameBoard.h"
//#include "agent/BlockPiece.h"

using std::cout;
using std::endl;



//game
void StartGame() {
	cout << "�O" << endl;
	
	/*Message me;*/
	//window wi;
	//Score st;
	//GameBoard gb;

	//DrawGameBoard dgb;
	//BlockPiece bp;

	//gScore = { 0 };

	//gb.InitGameBoard();//�Q�[���{�[�h������
	//gb.DrawBoard();//�Q�[���{�[�h�O�g�̕`��(ToDo)
	//gb.DrawStage();//�Q�[���{�[�h�����̕`��(ToDo)
	//dgb.DrawScore();//�X�R�A�\��(ToDO)
	//bp.SetTertimino();
	//bp.DrawTetrimino();
	//int tpy = 0;
	//while (gTetriminoPosY < gb.GetcGbHeight()) {
	//	Sleep(100);
	//	++tpy;
	//	gb.DrawStage();//�Q�[���{�[�h�O�g�̕`��(ToDo)
	//	bp.DrawTetrimino();
	//}

}


//main
int main() {
	//�Q�[���J�n
	StartGame();

	getchar();

	//�ꎞ��~
	_getch();
	//cout << st.GetScore() << endl;

	return 0;
}




