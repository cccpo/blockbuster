#pragma once
#include <Windows.h>

#include "GameBoard.h"
#include "BlockPiece.h"
#include "Value.h"
#include "../Data/Data.h"
#include "../state/Score.h"

//�@GameBoard�̕`����s���N���X
class DrawEngine
{
private:
	int gbpx;
	int gbpy;

	enum Mask {
		Intensity = 8, RedMask = 4, GreenMask = 2, BlueMask = 1
	};

public:
	enum class Color : int
	{
		Black = 0x00, DarkBlue, DarkGreen, DarkCyan, DarkRed, DarkViolet, DarkYellow, Gray, LightGray, Blue,
		Green, Cyan, Red, Violet, Yellow, White

	};

	void DefaultDrawBoard(const GameBoard& ioGameBoard);//�Q�[���{�[�h�O�g�̕`��
	void DrawBoard(const GameBoard& ioGameBoard,const Color& cl);//�Q�[���{�[�h�O�g�̕`��
	void DrawStage(GameBoard ioGameBoard);//�Q�[���{�[�h�����̕`��
	
	void DrawTetrimino(BlockPiece& bp);

	int TetriminoTypeToColor(int ttc);//�e�g���~�m�̌`�󂩂�F��ݒ肷��

	void DrawScore(Score sc);//�X�R�A�\��

	void DrawHighScore();

	void DrawRotType();

	void SetColor(int fg, int bg );
	void SetCursorPos(int x, int y);

	//DrawGameBoard(){}
	//~DrawGameBoard(){}

protected:
	GameBoard gb;
	BlockPiece bp;
	Score sc;
	Data d;


};

