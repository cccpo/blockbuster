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
void PlayGame() {
	static GameBoard *gb,*gb1;

	DrawEngine de;
	static BlockPiece *bp;
	KeyInput ki;
	Score sc;
	Data d;

	int HiScore = d.HiScoreLoad();//�n�C�X�R�A���擾
	sc.SetHighScore(HiScore);//�n�C�X�R�A���Z�b�g����

	gb = new GameBoard(1,2);//�Q�[���{�[�h�ʒu�ݒ�
	//gb1 = new GameBoard(90, 2);
	gb->InitGameBoard();//�Q�[���{�[�h������
	//gb1->InitGameBoard();
	
	de.DrawBoard(*gb);//�Q�[���{�[�h�O�g�̕`��
	//de.DrawBoard(*gb1,GameBoard::Color::Red);
	de.DrawStage(*gb);//�Q�[���{�[�h�����̕`��

	sc.SetScore(0);//�X�R�A�̏�����
	de.DrawScore(sc);//�X�R�A�\��
	de.DrawHighScore();//�n�C�X�R�A�\��
	
	bp = new BlockPiece();

	bp->AddTertimino(*gb);//�e�g���~�m�̒ǉ�
	de.DrawTetrimino(*bp);//�e�g���~�m�̕`��

	int bpx = bp->GetgTetriminoPosX(*gb);//�e�g���~�mx���W�ݒ�
	int bpy = bp->GetTetriminoPosY(*gb);//�e�g���~�my���W�ݒ�

	
	// Todo 
	int cnt = 1;
	int ts = 0;

	int key = 0;
	int keyDown = 0;

	
	//�e�g���~�m�������_�ŌŒ�u���b�N�ƐڐG����ƃ��[�v�𔲂���
	 while (!bp->IsOverLaped(*gb)) {
	//for(int cnt =1;;++cnt){
			bool update = false;

			if (cnt % FallInterval == 0 || key == VK_DOWN){
				//�e�g���~�m���������������ꍇ�Ɉȉ��̏���
				if (!bp->IsMoveDown(*gb)) {
					key = 0;
					int FinalPosX = bp->GetgTetriminoPosX(*gb);
					int FinalPosY = bp->GetTetriminoPosY(*gb);
					bp->ChangeBlock(*gb);//�u���b�N�̌Œ艻
					bp->DeleteLine(*gb);//������line�̏���
					de.DrawScore(sc);
					
					bp->AddTertimino(*gb);
					de.DrawStage(*gb);//�Q�[���{�[�h�����̕`��(ToDo)
					de.DrawTetrimino(*bp);//�e�g���~�m�̕`��
					bpx = bp->GetgTetriminoPosX(*gb);//�e�g���~�mx���W�ݒ�
					bpy = bp->GetTetriminoPosY(*gb);//�e�g���~�my���W�ݒ�
					
					//�g�O�ɏo�Ă��܂����ꍇ�I��
					if (bp->IsOverLaped(*gb))
						return;
					
					continue;
				}
				++bpy;     // �������e�g���X���ЂƂ��Ɉړ�
				bp->SetTeriminoPosY(bpy);
				update = true;
			}

			if (cnt % MoveInterval == 0) {   
				//Move Left
				if (key == VK_LEFT) {
					if (bp->IsMoveLeft(*gb)) {
						--bpx;  
						bp->SetTeriminoPosX(bpx);
						update = true;
					}
					key = 0;
				}
				//Move Right
				else if (key == VK_RIGHT) {
					if (bp->IsMoveRight(*gb)) {
						++bpx;  
						bp->SetTeriminoPosX(bpx);
						update = true;
					}
					key = 0;
				}
			}

			//Rotate
			if (cnt % RotateInterval == 0) {       
				if (key == VK_UP) {
					int tx = bp->GetRot(*gb);

					if (++tx >= 4) {
						bp->SetRot(0);
						tx = 0;
					}
					bp->SetTertimino(*gb,bp->mTetriminoType, tx);
					if (bp->IsOverLaped(*gb)) {    
						bp->SetTertimino(*gb,bp->mTetriminoType, bp->GetRot(*gb));
					}
					else {
						bp->SetRot(tx);
						update = true;
					}
					key = 0;
				}
			}
			if (update) {
				de.DrawStage(*gb);//�Q�[���{�[�h�����̕`��(ToDo)
				de.DrawTetrimino(*bp);
				
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
//int main() {
//	using namespace std;
//	chrono::system_clock::time_point start, end;
//
//	//�Q�[���J�n
//	DrawEngine de;
//	KeyInput ki;
//	Score sc;
//	Data d;
//
//	for (;;) {
//		start = chrono::system_clock::now();
//		
//		PlayGame();
//
//
//		end = chrono::system_clock::now();
//
//		double time = static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0);
//		
//		//������ύX����K�v������B
//		de.SetCursorPos(0, GameBoard::mGbHeight+5);
//		de.SetColor((int)DrawEngine::Color::Gray, (int)DrawEngine::Color::Black);
//		
//		//�n�C�X�R�A�X�V���̏���
//		if (sc.GetScore()>sc.GetHighScore()) {
//			std::cout << "HiScore!!" << sc.GetScore() <<endl;
//			d.HiScoreSave(sc.GetScore());
//		}
//		
//		std::cout << "GAME OVER. Replay? [Y/N] "<< endl;
//		
//		for (;;) {
//			if (ki.IsKeyPressed('N'))
//				return 0;
//			if (ki.IsKeyPressed('Y'))
//				break;
//			Sleep(LoopInterval);     // 10�~���b�E�F�C�g
//		}
//
//		
//		de.SetCursorPos(0, GameBoard::mGbHeight + 5);//���v���C���ɃQ�[���{�[�h�̈ʒu��������
//		
//		for (int i = 0; i < 79; ++i) {
//			std::cout << ' ';
//		}
//
//	}
//}




