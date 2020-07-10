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



	bool IsMoveDown(GameBoard ioGameBoard);//�ڐG����

	bool IsMoveLeft(GameBoard inGaneBoard);//���Ɉړ�����
	bool IsMoveRight(GameBoard inGaneBoard);//�E�Ɉړ�����

	bool IsOverLaped(GameBoard inGaneBoard);
	
	void ChangeBlock(GameBoard inGaneBoard);//�e�g���~�m���Œ艻
	
	void DeleteLine(GameBoard inGaneBoard);// ���������C��������

	int GetRot(GameBoard inGaneBoard);//���݂̃e�g���~�m�̉�]�^�C�v���Q�b�g

	void SetTertimino(const GameBoard& ioGameBoard, int type, int inTetriminoType);//�e�g���~�m���Q�[���{�[�h�ɔz�u
	void AddTertimino(const GameBoard& ioGameBoard); // �e�g���~�m�̒ǉ�


	int GetgTetriminoPosX(GameBoard inGameBoard);
	void SetTeriminoPosX(int tpx);

	

	int GetTetriminoPosY(GameBoard inGaneBoard);
	void SetTeriminoPosY(int tpy);

	

	void SetRot(int r);
	
	int GetgTeriminoType();
	void SetTeriminoType(int ttype);

	int GetTeriminoValue(int x, int y);
	

	
	BlockPiece();
	//~BlockPiece();

protected:
	GameBoard inGaneBoard;

};

