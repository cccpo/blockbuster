#pragma once

#include <Windows.h>

#include "DrawEngineWin32.h"

#include "TetriminoSet.h"


class GameBoardWin32
{

public:
	GameBoardWin32(DrawEngineWin32& draw_engine_win32,
				   int game_board_width = 10, int game_board_height = 20);
	~GameBoardWin32();

	const void DrawGameBoard();

	bool Rotate();

	bool Move(int cxDistance, int cyDistance);

	void UpdateTime();

	bool IsGameOver();
	const void DrawScore();

protected:
		bool Place(int x, int y, const TetriminoWin32& ioTetrimino);

		
		void Clear(const TetriminoWin32& piece);

		
		void MakeRandomPiece();

		bool IsHitBottom() const;
		bool IsHitLeft() const;
		bool IsHitRight() const;

		const bool IsCovered(const TetriminoWin32& piece, int x, int y);

		// ëµÇ¡ÇΩçsÇçÌèúÇ∑ÇÈ
		int ClearRows();


		COLORREF** game_board_win32;
		DrawEngineWin32& draw_engine_win32;

		TetriminoSet tetrimino_set; 
		TetriminoWin32* current_tetrimino;    
		TetriminoWin32* next_tetrimino;


		int game_board_width;
		int game_board_height;

		int mPosX;
		int mPosY; 
		int mSpeed; 
		double mLastTime;   
		double mCurrentTime;  
		int mScore; 
};

