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



	bool IsMoveDown(GameBoard inGameBoard);//�ڐG����
	bool IsMoveLeft(GameBoard inGaneBoard);//���Ɉړ�����
	bool IsMoveRight(GameBoard inGaneBoard);//�E�Ɉړ�����
	bool IsOverLaped(GameBoard inGaneBoard);//�g�O�ɂ��邩�𔻒�
	
	void ChangeBlock(GameBoard inGaneBoard);//�e�g���~�m���Œ艻
	
	void DeleteLine(GameBoard inGaneBoard);// ���������C��������

	int GetRot(const GameBoard& ioGaneBoard);//���݂̃e�g���~�m�̉�]�^�C�v���Q�b�g

	void SetTertimino(const GameBoard& ioGameBoard, int type, int inTetriminoType);//�e�g���~�m���Q�[���{�[�h�ɔz�u
	void AddTertimino(const GameBoard& ioGameBoard); // �e�g���~�m�̒ǉ�
	
	//inline
	inline int GetTetriminoPosX(const GameBoard& inGameBoard) { return mTetriminoPosX;};
	inline void SetTeriminoPosX(int inTetriminoPosX) {mTetriminoPosX = inTetriminoPosX;};

	inline int GetTetriminoPosY(const GameBoard& inGaneBoard) { return mTetriminoPosY;};
	inline void SetTeriminoPosY(int inTetriminoPosY) { mTetriminoPosY = inTetriminoPosY; };

	inline int GetTeriminoType(const GameBoard& inGaneBoard) { return mTetriminoType; };

	

	void SetRot(int r);
	
	//int GetTeriminoType();
	void SetTeriminoType(int ttype);

	int GetTeriminoValue(int x, int y);
	

	
	BlockPiece();
	//~BlockPiece();

protected:
	GameBoard inGaneBoard;

};

