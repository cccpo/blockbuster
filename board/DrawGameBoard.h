#pragma once
#include <Windows.h>

#include "GameBoard.h"

//�@GameBoard�̕`����s���N���X
class DrawGameBoard
{
private:
	int gbpx;
	int gbpy;

	enum Mask {
		Intensity = 8, RedMask = 4, GreenMask = 2, BlueMask = 1
	};

public:

	void DrawBoard(GameBoard const& gb);//�Q�[���{�[�h�O�g�̕`��
	void DrawBoard(GameBoard gb,GameBoard::Color cl);//�Q�[���{�[�h�O�g�̕`��
	void DrawStage(GameBoard gb);//�Q�[���{�[�h�����̕`��
	
	void DrawTetrimino(BlockPiece& bp);

	int TetriminoTypeToColor(int ttc);

	void DrawScore();//�X�R�A�\��

	void DrawRotType();

	void SetColor(int fg, int bg );
	void SetCursorPos(int x, int y);

	//DrawGameBoard(){}
	//~DrawGameBoard(){}

protected:
	GameBoard gb;


};

