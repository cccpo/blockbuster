#pragma once
#include <iostream>
#include <Windows.h>
#include <vector>

typedef unsigned char byte;

const int gTetriminoHeight = { 4 };
const int gTetriminoWidth = { 4 };



class BlockPiece
{
private:
	int mTetriminoPosX;//�Q�[���{�[�h���ォ��̑��ΓI�Ȉʒu
	int mTetriminoPosY;
	int mTetriminoType;//�e�g���~�m�̃^�C�v

	int sRotIX;
public:



	

	int mTetrimino[gTetriminoWidth][gTetriminoHeight];



	bool IsMoveDown();

	bool IsMoveLeft();
	bool IsMoveRight();

	bool IsOverLaped();
		
	

	void SetTertimino(int type, int rx);
	void AddTertimino();

	void DrawTetrimino();


	int GetgTetriminoPosX();
	void SetTeriminoPosX(int tpx);

	void ChangeBlock();

	int GetTetriminoPosY();
	void SetgTeriminoPosY(int tpy);

	void DeleteLine();

	int GetRot();
	void SetRot(int r);
	
	int GetgTeriminoType();
	void SetgTeriminoType(int ttype);

	int GetTeriminoValue(int x, int y);
	
	
	//BlockPiece();
	//~BlockPiece();
};

