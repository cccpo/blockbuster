#include "DrawEngineWin32.h"
#include "GameBoardWin32.h"
#include "TetriminoSet.h"
#include "TetriminoWin32.h"


class GameWin32
{

public:
	GameWin32(DrawEngineWin32& draw_engine_win32);
	~GameWin32();

	void RestartGame();//�Q�[�������X�^�[�g
	void UpdateTime();//���Ԃ��X�V

	const void PriorityDraw();// �`��Ώۂ��Ăяo��
	
	void Pause(bool inPaused);// �ꎞ��~
	bool IsKeyPress(int inInputKey);// Key���͌��o
	
	void DrawHiScore() const;
	void DrawGameOver() const;
	void DrawPause() const;

	bool IsGameOver() const;//�Q�[���I�[�o�[����
protected:
	DrawEngineWin32& draw_engine_win32;
	GameBoardWin32* game_board_win32;

	bool mIsPaused;
	bool mIsUpdateHiScore;
};