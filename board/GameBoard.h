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
	enum Value {
		empty=0
	};

	const static int mGbWidth = 10;
	const static int mGbHeight = 20;

	int mGameBoardPosX;//�Q�[���{�[�h�ʒu��x���W
	int mGameBoardPosY;//�Q�[���{�[�h�ʒu��y���W

	void InitGameBoard();// �Q�[���{�[�h������

	int GetGameBoardValue(int x, int y);// �Q�[���{�[�h�̒l���Q�b�g
	void SetTerimonoValue(int x, int y, int val);// �Q�[���{�[�h�̒l���Z�b�g

	void Down(int y);// ��i���Ƃ�(�������Ƃ��Ɏg�p)

	const int GetmEmpty();// �������֐�

	const int GetmGameBoardPosX();// �Q�[���{�[�h��x���W��Ԃ�
	const int GetmGameBoardPosY();// �Q�[���{�[�h��y���W��Ԃ�

	GameBoard();

	GameBoard(int posx, int posy);

	//~GameBoard();
};



