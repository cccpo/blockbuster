#include "DrawEngineWin32.h"
#include "GameBoardWin32.h"
#include "TetriminoSet.h"
#include "TetriminoWin32.h"


class GameWin32
{

public:
	GameWin32(DrawEngineWin32& draw_engine_win32);
	~GameWin32();

	void RestartGame();

	void UpdateTime();

	const void PriorityDraw();
	
	bool IsKeyPress(int inInputKey);

	void Pause(bool inPaused);

	 bool IsGameOver() const;
	 void DrawGameOver() const;
	 void DrawPause() const;

protected:
	DrawEngineWin32& draw_engine_win32;
	GameBoardWin32* game_board_win32;

	bool mIsPaused;
};