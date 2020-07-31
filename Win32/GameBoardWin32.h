#pragma once

#include <Windows.h>

#include "../Data/Data.h"
#include "../board/ScoreManager.h"

#include "DrawEngineWin32.h"
#include "TetriminoSet.h"


class GameBoardWin32
{

public:
	GameBoardWin32(DrawEngineWin32& draw_engine_win32,
				   int game_board_width = 10, int game_board_height = 20);
	~GameBoardWin32();

	inline int GetScore() const{ return mScore;};
	inline int GetHiScore() const { return HiScore; };

	bool IsHiScore();

	/*void CheckHiScore();*/
	const void DrawGameBoard();//GameBoard�̕`���`��G���W���ɍs�킹��

	bool Rotate();//��]

	bool Move(int move_to_x, int move_to_y);// �e�g���~�m���ړ�

	void UpdateTime();

	bool IsGameOver();//�Q�[���I�[�o�[�ł��邩���m�F����
	const void DrawScore();//�X�R�A��`��
	const void DrawHiScore();//�n�C�X�R�A��`��
	const void DrawSpeed();//�������x���x����`��
	const void DrawLines();//���������C���̐���\��
	const void DrawNextTetrimino();//���̃e�g���~�m��`��

protected:
		bool Place(int inPosX, int inPosY, const TetriminoWin32& ioTetrimino);

		
		void ClearTetrimino(const TetriminoWin32& piece);

		
		void MakeRandomPiece();

		const bool IsHitBottom();
		const bool IsHitLeft();
		const bool IsHitRight();

		const bool IsCovered(const TetriminoWin32& piece, int inPosX, int inPosY);

		// �������s���폜����
		int ClearRows();


		COLORREF** game_board_win32;
		DrawEngineWin32& draw_engine_win32;

		TetriminoSet tetrimino_set; 
		TetriminoWin32* current_tetrimino;    
		TetriminoWin32* next_tetrimino;

		ScoreManager score_manager;
		Data data;


		int game_board_width;
		int game_board_height;

		int mPosX;
		int mPosY; 
		int mSpeed; 
		double mLastTime;   
		double mCurrentTime;  
		int mScore;
		int mHiScore;
		int mLines;
};

