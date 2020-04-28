#include <iostream>
#include <Windows.h>
#include <thread>
#include <chrono>
#include <memory>
#include <conio.h>

#include "Game.h"
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


	gb.InitGameBoard();//�Q�[���{�[�h������
	gb.DrawBoard();//�Q�[���{�[�h�O�g�̕`��(ToDo)
	gb.DrawStage();//�Q�[���{�[�h�����̕`��(ToDo)
	dgb.DrawScore();//�X�R�A�\��(ToDO)
	bp.SetTertimino();
	bp.DrawTetrimino();
	int bpy = bp.GetgTetriminoPosY();

	while (bpy < gb.GetcGbHeight()) {       // �����e�g���X���Ֆʉ��[�ɗ���܂Ń��[�v
		Sleep(100);       // 0.1�b�E�F�C�g
		++bpy;             // �����e�g���X��1�s����
		bp.SetgTeriminoPosY(bpy);
		gb.DrawStage();//�Q�[���{�[�h�����̕`��(ToDo)
		bp.DrawTetrimino();
	}


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




