#include <iostream>


#include "DrawEngine.h"




using std::cout;
using std::endl;

//�Q�[���{�[�h�O�g�̕`��
void DrawEngine::DefaultDrawBoard(const GameBoard& ioGameBoard) {
	//�F�ݒ�
	SetColor((int)Color::Gray, (int)Color::Gray);

	SetCursorPos(ioGameBoard.mGameBoardPosX, ioGameBoard.mGameBoardPosY);
	for (int x = 0; x < GameBoard::mGbWidth + 2; ++x) {
		cout << "  ";
	}

	SetCursorPos(ioGameBoard.mGameBoardPosX, ioGameBoard.mGameBoardPosY + GameBoard::mGbHeight + 1);
	for (int x = 0; x < GameBoard::mGbWidth + 2; ++x) {
		cout << "  ";
	}
	for (int y = ioGameBoard.mGameBoardPosY + 1; y < ioGameBoard.mGameBoardPosY + GameBoard::mGbHeight + 1; ++y) {
		SetCursorPos(ioGameBoard.mGameBoardPosX, y);
		cout << "  ";
		SetCursorPos(ioGameBoard.mGameBoardPosX + (GameBoard::mGbWidth + 1) * 2, y);
		cout << "  ";
	}
}

//�Q�[���{�[�h�O�g�̕`��(�O�g�F�w��)
void DrawEngine::DrawBoard(const GameBoard& ioGameBoard, const Color& cl) 
{
	//�F�ݒ�
	SetColor((int)cl, (int)cl);

	SetCursorPos(ioGameBoard.mGameBoardPosX, ioGameBoard.mGameBoardPosY);
	for (int x = 0; x < GameBoard::mGbWidth + 2; ++x) {
		cout << "  ";
	}

	SetCursorPos(ioGameBoard.mGameBoardPosX, ioGameBoard.mGameBoardPosY + GameBoard::mGbHeight + 1);
	for (int x = 0; x < GameBoard::mGbWidth + 2; ++x) {
		cout << "  ";
	}
	for (int y = ioGameBoard.mGameBoardPosY + 1; y < gbpy + GameBoard::mGbHeight + 1; ++y) {
		SetCursorPos(ioGameBoard.mGameBoardPosX, y);
		cout << "  ";
		SetCursorPos(ioGameBoard.mGameBoardPosX + (GameBoard::mGbWidth + 1) * 2, y);
		cout << "  ";
	}
}

//�Q�[���{�[�h�����̕`��
void DrawEngine::DrawStage(GameBoard inGameBoard) {
	for (int y = 1; y <= GameBoard::mGbHeight; ++y) {
		SetCursorPos(inGameBoard.GetmGameBoardPosX() + 2, y + inGameBoard.GetmGameBoardPosY());
		for (int x = 1; x <= GameBoard::mGbWidth; ++x) {
			int Value = inGameBoard.GetGameBoardValue(x, y);
			//��ł͂Ȃ��u���b�N�͌Œ艻��
			if(Value !=GameBoard::Value::empty){
				int Color = TetriminoTypeToColor(Value);

				//�e�g���~�m�̐F��ݒ�
				SetColor(Color, Color);
			}
			else
				SetColor((int)Color::Gray, (int)Color::Black);
			cout << "  ";
		}
	}
}


void DrawEngine::DrawTetrimino(BlockPiece& bp)
{
	//GUI�A�v���Ƃ��ĈڐA����ۂɃe�g���~�m���`��ƐF���������\���̂Ƃ��Ē�`���邱�Ƃŕ`����s���֐�������w�肷��K�v���Ȃ���
	int Color = TetriminoTypeToColor(bp.mTetriminoType + 1);//Type�͈̔͂�0~6�ł͂Ȃ��A1~7�ɁA

	//�e�g���~�m�̐F��ݒ�
	SetColor(static_cast<int>(Color), static_cast<int>(Color));


	for (int i = 0; i < gTetriminoWidth; ++i) {
		int y = bp.mTetriminoPosY + i;
		if (y < 0 || y >= GameBoard::mGbHeight) continue;
		for (int k = 0; k < gTetriminoWidth; ++k) {
			int x = bp.mTetriminoPosX + k;
			if (x < 0 || x >= GameBoard::mGbWidth) continue;
			if (bp.mTetrimino[k][i]) {
				SetCursorPos(gb.GetmGameBoardPosX() + (x + 1) * 2, gb.GetmGameBoardPosY() + y + 1);
				cout << "  ";
			}
		}
	}
}

//�e�g���~�m�̌`�󂩂�F��ݒ肷��
int DrawEngine::TetriminoTypeToColor(int ttc) {
	static int tkl;


	switch (ttc)
	{
		case static_cast<int>(BlockPiece::TetrimnoType::TypeA) :
			tkl = static_cast<int>(Color::Cyan);
			break;
		case static_cast<int>(BlockPiece::TetrimnoType::TypeB) :
			tkl = static_cast<int>(Color::Yellow);
			break;
		case static_cast<int>(BlockPiece::TetrimnoType::TypeC) :
			tkl = static_cast<int>(Color::Red);
			break;
		case static_cast<int>(BlockPiece::TetrimnoType::TypeD) :
			tkl = static_cast<int>(Color::Green);
			break;
		case static_cast<int>(BlockPiece::TetrimnoType::TypeE) :
			tkl = static_cast<int>(Color::Blue);
			break;
		case static_cast<int>(BlockPiece::TetrimnoType::TypeF) :
			tkl = static_cast<int>(Color::DarkRed);
			break;
		case static_cast<int>(BlockPiece::TetrimnoType::TypeG) :
			tkl = static_cast<int>(Color::Violet);
			break;
		default:
			break;
	}

	return tkl;
}

//�R���\�[����̕`��ʒu��ݒ�
void DrawEngine::SetCursorPos(int x, int y) {
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hCons, pos);
}


//�X�R�A�\��
void DrawEngine::DrawScore(Score sc) {
	//�X�R�A�\���ʒu�̐ݒ�
	int ScorePosX = (gb.GetmGameBoardPosX() + GameBoard::mGbWidth + 2) * 3 + 4;
	int ScorePosY = gb.GetmGameBoardPosY()+2;
	
	int score = sc.GetScore();//�X�R�A�擾

	SetCursorPos(ScorePosX,ScorePosY);
	//�X�R�A�̐F��ݒ�
	SetColor(static_cast<int>(Color::Gray), static_cast<int>(Color::Black));
	
	cout << "Score:";
	cout.width(8);     
	cout << score;
}
//
////���[���\��
void DrawEngine::DrawHighScore() {
	//�X�R�A�\���ʒu�̐ݒ�
	int RulePosX = (gb.GetmGameBoardPosX() + GameBoard::mGbWidth + 2) * 3 + 4;
	int RulePosY = gb.GetmGameBoardPosY();

	int hiscore = sc.GetHighScore();//�X�R�A�擾

	SetCursorPos(RulePosX, RulePosY);
	//�X�R�A�̐F��ݒ�
	SetColor(static_cast<int>(Color::Gray), static_cast<int>(Color::Black));

	cout << "HiScore:";
	cout.width(6);
	cout << hiscore;
}

//�f�o�b�N�p�e�X�g�֐�
void DrawEngine::DrawRotType() {
	//int RotPosX = (gb.GetmGameBoardPosX() + (GameBoard::mGbWidth + 2) * 3 + 4);
	//int RotePosY = gb.GetmGameBoardPosY() + 2;

	//int RotType = bp.GetRot();
	//SetCursorPos(RotPosX, RotePosY);
	//SetColor(static_cast<int>(Color::Gray), static_cast<int>(Color::Black));
	//cout << "RotType:";
	//cout.width(8);
	//cout << RotType;
}



void DrawEngine::SetColor(int fg, int bg) {
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD attr = 0;
	if (fg & static_cast<int>(Mask::Intensity))
		attr |= FOREGROUND_INTENSITY;
	if (fg & static_cast<int>(Mask::RedMask))
		attr |= FOREGROUND_RED;
	if (fg & static_cast<int>(Mask::GreenMask))
		attr |= FOREGROUND_GREEN;
	if (fg & static_cast<int>(Mask::BlueMask))
		attr |= FOREGROUND_BLUE;

	if (bg & static_cast<int>(Mask::Intensity))
		attr |= BACKGROUND_INTENSITY;
	if (bg & static_cast<int>(Mask::RedMask))
		attr |= BACKGROUND_RED;
	if (bg & static_cast<int>(Mask::GreenMask))
		attr |= BACKGROUND_GREEN;
	if (bg & static_cast<int>(Mask::BlueMask))
		attr |= BACKGROUND_BLUE;
	SetConsoleTextAttribute(hCons, attr);
}