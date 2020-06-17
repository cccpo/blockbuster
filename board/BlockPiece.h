#pragma once
#include <Windows.h>
#include <vector>
#include <random>
#include <stdlib.h>

#include "GameBoard.h"

typedef unsigned char byte;

const int gTetriminoHeight = { 4 };
const int gTetriminoWidth = { 4 };



class BlockPiece
{
private:
	
	

	
public:
	int mTetriminoPosX;//�Q�[���{�[�h���ォ��̑��ΓI�Ȉʒu
	int mTetriminoPosY;
	int mTetriminoType;//�e�g���~�m�̃^�C�v

	//�e�g���~�m�̃^�C�v��񋓁@#ToDO ���O�͉�
	enum class TetrimnoType:int
	{
		TypeA=1,TypeB,TypeC,TypeD,TypeE,TypeF,TypeG
	};
	

	int mTetrimino[gTetriminoWidth][gTetriminoHeight];



	bool IsMoveDown(GameBoard gb);//�ڐG����

	bool IsMoveLeft(GameBoard gb);
	bool IsMoveRight(GameBoard gb);

	bool IsOverLaped();
		
	
	int GetRot();

	void SetTertimino(int type, int rx);//�e�g���~�m���Q�[���{�[�h�ɔz�u
	void AddTertimino(); // �e�g���~�m�̒ǉ�


	int GetgTetriminoPosX();
	void SetTeriminoPosX(int tpx);

	void ChangeBlock();

	int GetTetriminoPosY();
	void SetTeriminoPosY(int tpy);

	void DeleteLine();

	void SetRot(int r);
	
	int GetgTeriminoType();
	void SetTeriminoType(int ttype);

	int GetTeriminoValue(int x, int y);
	

	
	BlockPiece();
	//~BlockPiece();


};

