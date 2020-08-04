#include <iostream>
#include <Windows.h>
#include <thread>
#include <chrono>
#include <memory>
#include <conio.h>
#include <chrono>

#include "Game.h"

#include "board/ScoreManager.h"
#include "board/GameBoard.h"
#include "board/DrawEngine.h"
#include "board/BlockPiece.h"
#include "Data/Data.h"
#include "Input/KeyInput.h"

using std::cout;
using std::endl;


//game
void gPlayGame(DrawEngine& ioDrawEngine) {

	GameBoard game_board(1, 2);

	BlockPiece block_piece;
	KeyInput key_input;
	ScoreManager score;
	Data data;

	int hi_score = data.HiScoreLoad();//�n�C�X�R�A���擾
	score.SetHighScore(hi_score);//�n�C�X�R�A���Z�b�g����

	game_board.InitGameBoard();//�Q�[���{�[�h������

	score.SetScore(0);//�X�R�A�̏�����

	block_piece.AddTertimino(game_board);//�e�g���~�m�̒ǉ�

	int block_piece_posx = block_piece.GetTetriminoPosX(game_board);//�e�g���~�mx���W�ݒ�
	int block_piece_posy = block_piece.GetTetriminoPosY(game_board);//�e�g���~�my���W�ݒ�

	ioDrawEngine.DefaultDrawBoard(game_board);//�Q�[���{�[�h�O�g�̕`��
	ioDrawEngine.DrawStage(game_board);//�Q�[���{�[�h�����̕`��

	ioDrawEngine.DrawScore(score);//�X�R�A�\��
	ioDrawEngine.DrawHiScore();//�n�C�X�R�A�\��

	ioDrawEngine.DrawTetrimino(game_board, block_piece);//�e�g���~�m�̕`��

	// Todo fix
	int mCurrentTime = 1;
	int ts = 0;

	int key = 0;
	int keyDown = 0;


	//�e�g���~�m�������_�ŌŒ�u���b�N�ƐڐG����ƃ��[�v�𔲂���
	while (!block_piece.IsOverLaped(game_board)) {
		//for(int cnt =1;;++cnt){
		bool update = false;

		if (mCurrentTime % FallInterval == 0 || key == VK_DOWN) {
			//�e�g���~�m���������������ꍇ�Ɉȉ��̏���
			if (!block_piece.IsMoveDown(game_board)) {
				key = 0;
				int final_posx = block_piece.GetTetriminoPosX(game_board);
				int final_posy = block_piece.GetTetriminoPosY(game_board);
				block_piece.ChangeBlock(game_board);//�u���b�N�̌Œ艻
				block_piece.DeleteLine(game_board);//������line�̏���
				ioDrawEngine.DrawScore(score);

				block_piece.AddTertimino(game_board);
				ioDrawEngine.DrawStage(game_board);//�Q�[���{�[�h�����̕`��(ToDo)
				ioDrawEngine.DrawTetrimino(game_board, block_piece);//�e�g���~�m�̕`��
				block_piece_posx = block_piece.GetTetriminoPosX(game_board);//�e�g���~�mx���W�ݒ�
				block_piece_posy = block_piece.GetTetriminoPosY(game_board);//�e�g���~�my���W�ݒ�

				//�g�O�ɏo�Ă��܂����ꍇ�I��
				if (block_piece.IsOverLaped(game_board))
					return;

				continue;
			}
			++block_piece_posy;     // �������e�g���X���ЂƂ��Ɉړ�
			block_piece.SetTeriminoPosY(block_piece_posy);
			update = true;
		}

		if (mCurrentTime % MoveInterval == 0) {
			//Move Left
			if (key == VK_LEFT) {
				if (block_piece.IsMoveLeft(game_board)) {
					--block_piece_posx;
					block_piece.SetTeriminoPosX(block_piece_posx);
					update = true;
				}
				key = 0;
			}
			//Move Right
			else if (key == VK_RIGHT) {
				if (block_piece.IsMoveRight(game_board)) {
					++block_piece_posx;
					block_piece.SetTeriminoPosX(block_piece_posx);
					update = true;
				}
				key = 0;
			}
		}

		//Rotate
		if (mCurrentTime % RotateInterval == 0) {
			if (key == VK_UP) {
				int tx = block_piece.GetRot(game_board);

				if (++tx >= 4) {
					block_piece.SetRot(0);
					tx = 0;
				}
				block_piece.SetTertimino(game_board, block_piece.mTetriminoType, tx);
				if (block_piece.IsOverLaped(game_board)) {
					block_piece.SetTertimino(game_board, block_piece.mTetriminoType, block_piece.GetRot(game_board));
				}
				else {
					block_piece.SetRot(tx);
					update = true;
				}
				key = 0;
			}
		}
		if (update) {
			ioDrawEngine.DrawStage(game_board);//�Q�[���{�[�h�����̕`��(ToDo)
			ioDrawEngine.DrawTetrimino(game_board, block_piece);

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
		++mCurrentTime;
	}


}

//main
int main() {
	using namespace std;
	chrono::system_clock::time_point start, end;

	//�Q�[���J�n
	DrawEngine draw_engine;
	KeyInput key_input;
	ScoreManager score_manager;
	Data data;

	for (;;) {
		start = chrono::system_clock::now();//�^�C�}�[�X�^�[�g
		
		gPlayGame(draw_engine);


		end = chrono::system_clock::now();//�^�C�}�[�X�g�b�v

		double time = static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0);
		
		draw_engine.SetCursorPos(0, GameBoard::mGbHeight+5);
		draw_engine.SetColor((int)DrawEngine::Color::Gray, (int)DrawEngine::Color::Black);
		
		//�n�C�X�R�A�X�V���̏���
		if (score_manager.GetScore()>score_manager.GetHighScore()) {
			std::cout << "HiScore!!" << score_manager.GetScore() <<endl;
			data.HiScoreSave(score_manager.GetScore());
		}
		
		std::cout << "GAME OVER. Replay? [Y/N] "<< endl;
		
		for (;;) {
			if (key_input.IsKeyPressed('N'))
				return 0;
			if (key_input.IsKeyPressed('Y'))
				break;
			Sleep(LoopInterval);     // 10�~���b�E�F�C�g
		}

		
		draw_engine.SetCursorPos(0, GameBoard::mGbHeight + 5);//���v���C���ɃQ�[���{�[�h�̈ʒu��������
		
		for (int i = 0; i < 79; ++i) {
			std::cout << ' ';
		}

	}
}

