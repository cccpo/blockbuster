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
#include "Input/KeyInput.h"

using std::cout;
using std::endl;

//game
void StartGame() {

	GameBoard gb;
	DrawGameBoard dgb;
	BlockPiece bp;
	KeyInput ki;

	gb.InitGameBoard();//�Q�[���{�[�h������
	gb.DrawBoard();//�Q�[���{�[�h�O�g�̕`��
	gb.DrawStage();//�Q�[���{�[�h�����̕`��
	dgb.DrawScore();//�X�R�A�\��
	bp.SetTertimino();
	bp.DrawTetrimino();//�e�g���~�m�̕`��

	int bpx = bp.GetgTetriminoPosX();//�e�g���~�mx���W�ݒ�
	int bpy = bp.GetgTetriminoPosY();//�e�g���~�my���W�ݒ�
	
	int cnt = 1;
	int ts = 0;

	int key = 0;
	int keyDown = 0;

	//�e�g���~�m�������_�ŌŒ�u���b�N�ƐڐG����ƃ��[�v�𔲂���
	while (!bp.IsOverLaped()) {
		
			bool update = false;
			if (cnt % FallInterval == 0 || key == VK_DOWN)
			{
				if (!bp.MoveDown()) {
					key = 0;
					int FinalPosX = bp.GetgTetriminoPosX();
					int FinalPosY = bp.GetgTetriminoPosY();
					bp.ChangeBlock();//�ŉ����܂ł��ǂ蒅�����u���b�N�̌Œ艻
					bp.DeleteLine();
					dgb.DrawScore();
					bp.SetTertimino();
					gb.DrawStage();//�Q�[���{�[�h�����̕`��(ToDo)
					bp.DrawTetrimino();
				}
				++bpy;     // �������e�g���X���ЂƂ��Ɉړ�
				bp.SetgTeriminoPosY(bpy);
				update = true;
			}
			if (cnt % MoveInterval == 0) {   
				if (key == VK_LEFT) {
					if (bp.MoveLeft()) {
						--bpx;  
						bp.SetgTeriminoPosX(bpx);
						update = true;
					}
					key = 0;
				}
				else if (key == VK_RIGHT) {
					if (bp.MoveRight()) {
						++bpx;  
						bp.SetgTeriminoPosX(bpx);
						update = true;
					}
					key = 0;
				}
			}

			if (cnt % RotateInterval == 0) {       
				if (key == VK_UP) {
					int tx = bp.GetRot();

					if (++tx >= 4) {
						bp.SetRot(0);
						bp.SetTertimino(bp.GetgTeriminoType(), tx);
					}

					if (bp.IsOverLaped()) {    
						bp.SetTertimino(bp.GetgTeriminoType(), tx);      
					}
					else {
						bp.SetRot(tx);
						update = true;
					}
					key = 0;
				}
			}
			if (update) {
				gb.DrawStage();//�Q�[���{�[�h�����̕`��(ToDo)
				bp.DrawTetrimino();
			}
			if (!keyDown) {     // �L�[�������󂯕t���Ă��Ȃ��ꍇ
				if (ki.IsKeyPressed(VK_LEFT)) {
					key = keyDown = VK_LEFT;
				}
				else if (ki.IsKeyPressed(VK_RIGHT)) {
					key = keyDown = VK_RIGHT;
				}
				else if (ki.IsKeyPressed(VK_UP)) {
					key = keyDown = VK_UP;
				}
				else if (ki.IsKeyPressed(VK_DOWN)) {
					key = keyDown = VK_DOWN;
				}
			}
			else {
				if (!ki.IsKeyPressed(keyDown))// �����ꂽ�L�[�������ꂽ
					keyDown = 0;
			}


			Sleep(10);
			//std::this_thread::sleep_for(std::chrono::seconds(1));
			++cnt;
		}
}





//main
int main() {
	//�Q�[���J�n
	//StartGame();
	GameBoard gb;
	KeyInput ki;
	//cout << st.GetScore() << endl;

	for (;;) {
		StartGame();

		gb.SetCursorPos(0, 25);
		gb.SetColor(static_cast<int>(GameBoard::Color::Gray), static_cast<int>(GameBoard::Color::Black));
		std::cout << "GAME OVER. Replay? [y/n] ";
		for (;;) {
			if (ki.IsKeyPressed('N'))
				return 0;
			if (ki.IsKeyPressed('Y'))
				break;
			Sleep(LoopInterval);     // 10�~���b�E�F�C�g
		}
		gb.SetCursorPos(0, 80 - 1);
		
		for (int i = 0; i < 80 - 1; ++i) {
			std::cout << ' ';
		}

	}
}




