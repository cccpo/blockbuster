#pragma once
#include <Windows.h>

//�@GameBoard�̕`����s���N���X
class DrawGameBoard
{


	

public:


	void DrawBoard();//�Q�[���{�[�h�O�g�̕`��
	void DrawStage();//�Q�[���{�[�h�����̕`��
	
	void DrawScore();//�X�R�A�\��

	void DrawRotType();

	void SetColor(int fg, int bg );
	void SetCursorPos(int x, int y);

	//DrawGameBoard(){}
	//~DrawGameBoard(){}
};

