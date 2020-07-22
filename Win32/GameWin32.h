#pragma once

#include "DrawEngineWin32.h"
#include "GameBoardWin32.h"


class GameWin32
{

public:
	GameWin32(DrawEngineWin32& draw_engine_win32);
	~GameWin32();

	void UpdateTime();

	void Draw() const;
	
	bool IsKeyPress(int inInputKey);

	void Pause(bool paused);

	 bool IsGameOver() const;

protected:
	DrawEngineWin32& draw_engine_win32;
	GameBoardWin32* game_board_win32;

	bool mIsPaused;
};

