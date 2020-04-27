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

	//�Q�[���J�n
	
	StartGame();
	gb.InitGameBoard();//�Q�[���{�[�h������
	gb.DrawBoard();//�Q�[���{�[�h�O�g�̕`��(ToDo)
	gb.DrawStage();//�Q�[���{�[�h�����̕`��(ToDo)
	dgb.DrawScore();//�X�R�A�\��(ToDO)
	getchar();

	//�ꎞ��~
	_getch();
	//cout << st.GetScore() << endl;

	return 0;
}
