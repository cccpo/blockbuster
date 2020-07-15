#pragma once

#include "DrawEngineWin32.h"
#include "GameBoardWin32.h"
#include "../board/BlockPiece.h"
#include "../board/GameBoard.h"
#include "../board/ScoreManager.h"
#include "../Data/Data.h"


class GameWin32
{

public:
	GameWin32(DrawEngineWin32& draw_engine_win32);
	~GameWin32();

	void UpdateTime();

	const void Draw();
	
	const bool IsKeyPress(int inInputKey);

	

	//const bool IsGameOver();

protected:
	DrawEngineWin32 draw_engine_win32;
	GameBoardWin32* game_board_win32;

	bool mIsPaused;
};

