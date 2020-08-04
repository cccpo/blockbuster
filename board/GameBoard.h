#pragma once
#include <iostream>
#include <Windows.h>

typedef unsigned char byte;


class GameBoard
{

private:
	int mOuterFrame = 0xff;
	int mEmpty = { 0 };
	
	enum Mask {
		Intensity = 8, RedMask = 4, GreenMask = 2, BlueMask = 1
	};


public:
	const static int mGbWidth = 10;
	const static int mGbHeight = 20;

	int mGameBoardPosX;//�Q�[���{�[�h�ʒu��x���W
	int mGameBoardPosY;//�Q�[���{�[�h�ʒu��y���W

	enum Value {
		empty=0
	};

	void InitGameBoard();// �Q�[���{�[�h������

	int GetGameBoardValue(int inPosX, int inPosY);// �Q�[���{�[�h�̒l���Q�b�g
	void SetTerimonoValue(int inPosX, int inPosY, int inValue);// �Q�[���{�[�h�̒l���Z�b�g

	void Down(int y);// ��i���Ƃ�(�������Ƃ��Ɏg�p)

	const int GetmEmpty();// �������֐�

	int GetGameBoardPosX();// �Q�[���{�[�h��x���W��Ԃ�
	int GetGameBoardPosY();// �Q�[���{�[�h��y���W��Ԃ�

	GameBoard();

	GameBoard(int inPosX, int inPosY);
	~GameBoard();

protected:
	int mScore=0;
};



