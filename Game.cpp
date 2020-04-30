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
//                    return false;              //  �������ɕ� or �Œ�u���b�N������
//                break;
//            }
//        }
//}

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
	int bpy = gTeriminoPosY;
	
	//while (bpy < gb.GetcGbHeight()) {       // �����e�g���X���Ֆʉ��[�ɗ���܂Ń��[�v
	//	Sleep(1000);       // 1�b�E�F�C�g
	//	++bpy;             // �����e�g���X��1�s����
	//	bp.SetgTeriminoPosY(bpy);
	//	gb.DrawStage();//�Q�[���{�[�h�����̕`��(ToDo)
	//	bp.DrawTetrimino();
	//}

	for (int cnt = 1; ; ++cnt) {
		bool update = false;        // ��ʍX�V�t���O
		if (cnt % FallInterval == 0)
		{      // ��������
			if (!bp.MoveDown()) {
				gb.DrawStage();//�Q�[���{�[�h�����̕`��(ToDo)
				bp.DrawTetrimino();
				return;
			}
			++bpy;     // �������e�g���X���ЂƂ��Ɉړ�
			bp.SetgTeriminoPosY(bpy);
			update = true;
		}
		if (update) {
				gb.DrawStage();//�Q�[���{�[�h�����̕`��(ToDo)
				bp.DrawTetrimino();
		}
		Sleep(10);
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




