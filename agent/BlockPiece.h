#pragma once
#include <Windows.h>
#include <vector>
#include <random>
#include <stdlib.h>

#include "../board/GameBoard.h"

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



	bool IsMoveDown();

	bool IsMoveLeft();
	bool IsMoveRight();

	bool IsOverLaped();
		
	
	int GetRot();

	void SetTertimino(int type, int rx);
	void AddTertimino();


	int GetgTetriminoPosX();
	void SetTeriminoPosX(int tpx);

	void ChangeBlock();

	int GetTetriminoPosY();
	void SetgTeriminoPosY(int tpy);

	void DeleteLine();

	//int GetRot();
	void SetRot(int r);
	
	int GetgTeriminoType();
	void SetgTeriminoType(int ttype);

	int GetTeriminoValue(int x, int y);
	
	int TetriminoTypeToColor(int ttc);

	
	BlockPiece();
	//~BlockPiece();


};

