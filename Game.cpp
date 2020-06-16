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
#include "state/Score.h"
#include "board/GameBoard.h"
#include "board/DrawEngine.h"
#include "agent/BlockPiece.h"
#include "Input/KeyInput.h"
#include "Data/Data.h"

using std::cout;
using std::endl;


//game
void StartGame() {
	static GameBoard *gb,*gb1;

	DrawEngine dgb;
	static BlockPiece *bp;
	KeyInput ki;
	Score sc;
	Data d;

	int HiScore = d.HiScoreLoad();//�n�C�X�R�A���擾
	sc.SetHighScore(HiScore);//�n�C�X�R�A���Z�b�g����

	gb = new GameBoard(1,2);//
	//gb1 = new GameBoard(90, 2);
	gb->InitGameBoard();//�Q�[���{�[�h������
	//gb1->InitGameBoard();
	
	dgb.DrawBoard(*gb);//�Q�[���{�[�h�O�g�̕`��
	//dgb.DrawBoard(*gb1,GameBoard::Color::Red);
	dgb.DrawStage(*gb);//�Q�[���{�[�h�����̕`��

	sc.SetScore(0);//�X�R�A�̏�����
	dgb.DrawScore();//�X�R�A�\��
	
	bp = new BlockPiece();

	bp->AddTertimino();//�e�g���~�m�̒ǉ�
	dgb.DrawTetrimino(*bp);//�e�g���~�m�̕`��

	int bpx = bp->GetgTetriminoPosX();//�e�g���~�mx���W�ݒ�
	int bpy = bp->GetTetriminoPosY();//�e�g���~�my���W�ݒ�

	
	
	int cnt = 1;
	int ts = 0;

	int key = 0;
	int keyDown = 0;

	
	//�e�g���~�m�������_�ŌŒ�u���b�N�ƐڐG����ƃ��[�v�𔲂���
	 while (!bp->IsOverLaped()) {
	//for(int cnt =1;;++cnt){
			bool update = false;

			if (cnt % FallInterval == 0 || key == VK_DOWN){
				//�e�g���~�m���������Ȃ�����ȉ��̏���
				if (!bp->IsMoveDown()) {
					key = 0;
					int FinalPosX = bp->GetgTetriminoPosX();
					int FinalPosY = bp->GetTetriminoPosY();
					bp->ChangeBlock();//�u���b�N�̌Œ艻
					bp->DeleteLine();//������line�̏���
					dgb.DrawScore();
					bp->AddTertimino();
					dgb.DrawStage(*gb);//�Q�[���{�[�h�����̕`��(ToDo)
					dgb.DrawTetrimino(*bp);
					bpx = bp->GetgTetriminoPosX();//�e�g���~�mx���W�ݒ�
					bpy = bp->GetTetriminoPosY();//�e�g���~�my���W�ݒ�
					if (bp->IsOverLaped())
						return;
					continue;
				}
				++bpy;     // �������e�g���X���ЂƂ��Ɉړ�
				bp->SetTeriminoPosY(bpy);
				update = true;
			}

			if (cnt % MoveInterval == 0) {   
				if (key == VK_LEFT) {
					if (bp->IsMoveLeft()) {
						--bpx;  
						bp->SetTeriminoPosX(bpx);
						update = true;
					}
					key = 0;
				}
				else if (key == VK_RIGHT) {
					if (bp->IsMoveRight()) {
						++bpx;  
						bp->SetTeriminoPosX(bpx);
						update = true;
					}
					key = 0;
				}
			}

			if (cnt % RotateInterval == 0) {       
				if (key == VK_UP) {
					int tx = bp->GetRot();

					if (++tx >= 4) {
						bp->SetRot(0);
						tx = 0;
					}
					bp->SetTertimino(bp->mTetriminoType, tx);
					if (bp->IsOverLaped()) {    
						bp->SetTertimino(bp->mTetriminoType, bp->GetRot());
					}
					else {
						bp->SetRot(tx);
						update = true;
					}
					key = 0;
				}
			}
			if (update) {
				dgb.DrawStage(*gb);//�Q�[���{�[�h�����̕`��(ToDo)
				dgb.DrawTetrimino(*bp);
				
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
	using namespace std;
	chrono::system_clock::time_point start, end;

	//�Q�[���J�n
	GameBoard gb;
	DrawEngine dgb;
	KeyInput ki;
	//cout << st.GetScore() << endl;
	Score sc;
	Data d;

	for (;;) {
		start = chrono::system_clock::now();
		
		StartGame();


		end = chrono::system_clock::now();

	

		double time = static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0);
		
		//������ύX����K�v������B
		dgb.SetCursorPos(0, GameBoard::mGbHeight+5);
		dgb.SetColor(static_cast<int>(GameBoard::Color::Gray), static_cast<int>(GameBoard::Color::Black));
		
		if (sc.GetScore()>sc.GetHighScore()) {
			std::cout << "HiScore!!" << sc.GetScore() <<endl;
			d.HiScoreSave(sc.GetScore());
		}
		
		//dgb.SetCursorPos(0, GameBoard::mGbHeight + 15);
		std::cout << "GAME OVER. Replay? [Y/N] "<< endl;
		
		for (;;) {
			if (ki.IsKeyPressed('N'))
				return 0;
			if (ki.IsKeyPressed('Y'))
				break;
			Sleep(LoopInterval);     // 10�~���b�E�F�C�g
		}

		dgb,SetCursorPos(0, 25 - 1);//���v���C���ɃQ�[���{�[�h�̈ʒu�������������
		
		for (int i = 0; i < 80 - 1; ++i) {
			std::cout << ' ';
		}

	}
}




