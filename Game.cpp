#include <iostream>
#include <Windows.h>
#include <thread>
#include <chrono>
#include <memory>
#include <conio.h>
#include <chrono>

#include "Game.h"

#include "state/Score.h"
#include "board/GameBoard.h"
#include "board/DrawEngine.h"
#include "board/BlockPiece.h"
#include "Input/KeyInput.h"
#include "Data/Data.h"

using std::cout;
using std::endl;


//game
void gPlayGame(DrawEngine& ioDrawEngine) {
	
	GameBoard gb(1,2);

	BlockPiece blockpiece;
	KeyInput key_input;
	Score score;
	Data data;

	int HiScore = data.HiScoreLoad();//�n�C�X�R�A���擾
	score.SetHighScore(HiScore);//�n�C�X�R�A���Z�b�g����

	gb.InitGameBoard();//�Q�[���{�[�h������

	score.SetScore(0);//�X�R�A�̏�����

	blockpiece.AddTertimino(gb);//�e�g���~�m�̒ǉ�

	int bpx = blockpiece.GetgTetriminoPosX(gb);//�e�g���~�mx���W�ݒ�
	int bpy = blockpiece.GetTetriminoPosY(gb);//�e�g���~�my���W�ݒ�

	ioDrawEngine.DrawBoard(gb);//�Q�[���{�[�h�O�g�̕`��
	ioDrawEngine.DrawStage(gb);//�Q�[���{�[�h�����̕`��

	ioDrawEngine.DrawScore(score);//�X�R�A�\��
	ioDrawEngine.DrawHighScore();//�n�C�X�R�A�\��

	ioDrawEngine.DrawTetrimino(blockpiece);//�e�g���~�m�̕`��

	// Todo fix
	int cnt = 1;
	int ts = 0;

	int key = 0;
	int keyDown = 0;
	
	
	//�e�g���~�m�������_�ŌŒ�u���b�N�ƐڐG����ƃ��[�v�𔲂���
	 while (!blockpiece.IsOverLaped(gb)) {
	//for(int cnt =1;;++cnt){
			bool update = false;

			if (cnt % FallInterval == 0 || key == VK_DOWN){
				//�e�g���~�m���������������ꍇ�Ɉȉ��̏���
				if (!blockpiece.IsMoveDown(gb)) {
					key = 0;
					int FinalPosX = blockpiece.GetgTetriminoPosX(gb);
					int FinalPosY = blockpiece.GetTetriminoPosY(gb);
					blockpiece.ChangeBlock(gb);//�u���b�N�̌Œ艻
					blockpiece.DeleteLine(gb);//������line�̏���
					ioDrawEngine.DrawScore(score);
					
					blockpiece.AddTertimino(gb);
					ioDrawEngine.DrawStage(gb);//�Q�[���{�[�h�����̕`��(ToDo)
					ioDrawEngine.DrawTetrimino(blockpiece);//�e�g���~�m�̕`��
					bpx = blockpiece.GetgTetriminoPosX(gb);//�e�g���~�mx���W�ݒ�
					bpy = blockpiece.GetTetriminoPosY(gb);//�e�g���~�my���W�ݒ�
					
					//�g�O�ɏo�Ă��܂����ꍇ�I��
					if (blockpiece.IsOverLaped(gb))
						return;
					
					continue;
				}
				++bpy;     // �������e�g���X���ЂƂ��Ɉړ�
				blockpiece.SetTeriminoPosY(bpy);
				update = true;
			}

			if (cnt % MoveInterval == 0) {   
				//Move Left
				if (key == VK_LEFT) {
					if (blockpiece.IsMoveLeft(gb)) {
						--bpx;  
						blockpiece.SetTeriminoPosX(bpx);
						update = true;
					}
					key = 0;
				}
				//Move Right
				else if (key == VK_RIGHT) {
					if (blockpiece.IsMoveRight(gb)) {
						++bpx;  
						blockpiece.SetTeriminoPosX(bpx);
						update = true;
					}
					key = 0;
				}
			}

			//Rotate
			if (cnt % RotateInterval == 0) {       
				if (key == VK_UP) {
					int tx = blockpiece.GetRot(gb);

					if (++tx >= 4) {
						blockpiece.SetRot(0);
						tx = 0;
					}
					blockpiece.SetTertimino(gb,blockpiece.mTetriminoType, tx);
					if (blockpiece.IsOverLaped(gb)) {    
						blockpiece.SetTertimino(gb,blockpiece.mTetriminoType, blockpiece.GetRot(gb));
					}
					else {
						blockpiece.SetRot(tx);
						update = true;
					}
					key = 0;
				}
			}
			if (update) {
				ioDrawEngine.DrawStage(gb);//�Q�[���{�[�h�����̕`��(ToDo)
				ioDrawEngine.DrawTetrimino(blockpiece);
				
			}
			if (!keyDown) {     // �L�[�������󂯕t���Ă��Ȃ��ꍇ
				if (key_input.IsKeyPressed(VK_LEFT)) {
					key = keyDown = VK_LEFT;
				}
				else if (key_input.IsKeyPressed(VK_RIGHT)) {
					key = keyDown = VK_RIGHT;
				}
				else if (key_input.IsKeyPressed(VK_UP)) {
					key = keyDown = VK_UP;
				}
				else if (key_input.IsKeyPressed(VK_DOWN)) {
					key = keyDown = VK_DOWN;
				}
			}
			else {
				if (!key_input.IsKeyPressed(keyDown))// �����ꂽ�L�[�������ꂽ
					keyDown = 0;
			}


			Sleep(10);
			//std::this_thread::sleep_for(std::chrono::seconds(1));
			++cnt;
		}


}

void draw(DrawEngine& de) {

}

//main
int main() {
	using namespace std;
	chrono::system_clock::time_point start, end;

	//�Q�[���J�n
	DrawEngine de;
	KeyInput ki;
	Score sc;
	Data d;

	for (;;) {
		start = chrono::system_clock::now();
		
		gPlayGame(de);


		end = chrono::system_clock::now();

		double time = static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0);
		
		//������ύX����K�v������B
		de.SetCursorPos(0, GameBoard::mGbHeight+5);
		de.SetColor((int)DrawEngine::Color::Gray, (int)DrawEngine::Color::Black);
		
		//�n�C�X�R�A�X�V���̏���
		if (sc.GetScore()>sc.GetHighScore()) {
			std::cout << "HiScore!!" << sc.GetScore() <<endl;
			d.HiScoreSave(sc.GetScore());
		}
		
		std::cout << "GAME OVER. Replay? [Y/N] "<< endl;
		
		for (;;) {
			if (ki.IsKeyPressed('N'))
				return 0;
			if (ki.IsKeyPressed('Y'))
				break;
			Sleep(LoopInterval);     // 10�~���b�E�F�C�g
		}

		
		de.SetCursorPos(0, GameBoard::mGbHeight + 5);//���v���C���ɃQ�[���{�[�h�̈ʒu��������
		
		for (int i = 0; i < 79; ++i) {
			std::cout << ' ';
		}

	}
}


// Key���͊Ǘ��N���X
bool Game::KeyPress(int input_key) {
	if (input_key != VK_PAUSE)
	
		return false;

	switch (input_key)
	{
	case VK_UP:
		
		break;
	case VK_DOWN:
		
		break;
	case VK_LEFT:
		
		break;
	case VK_RIGHT:
		
		break;
	case VK_SPACE:
	
		break;
	case VK_PAUSE:
	
		break;
	case VK_RETURN:
		//restart();
	default:
		return false;
	}
	return true;
}
