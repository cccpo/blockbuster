#include <iostream>


#include "DrawEngine.h"
#include "../state/Score.h"
#include "../agent/BlockPiece.h"


using std::cout;
using std::endl;

//�Q�[���{�[�h�O�g�̕`��
void DrawEngine::DrawBoard(GameBoard const& gb) {
	//�F�ݒ�
	SetColor((int)GameBoard::Color::Gray, (int)(GameBoard::Color::Gray));

	SetCursorPos(gb.mGameBoardPosX, gb.mGameBoardPosY);
	for (int x = 0; x < GameBoard::mGbWidth + 2; ++x) {
		cout << "  ";
	}

	SetCursorPos(gb.mGameBoardPosX, gb.mGameBoardPosY + GameBoard::mGbHeight + 1);
	for (int x = 0; x < GameBoard::mGbWidth + 2; ++x) {
		cout << "  ";
	}
	for (int y = gb.mGameBoardPosY + 1; y < gb.mGameBoardPosY + GameBoard::mGbHeight + 1; ++y) {
		SetCursorPos(gb.mGameBoardPosX, y);
		cout << "  ";
		SetCursorPos(gb.mGameBoardPosX + (GameBoard::mGbWidth + 1) * 2, y);
		cout << "  ";
	}
}

//�Q�[���{�[�h�O�g�̕`��(�O�g�F�w��)
void DrawEngine::DrawBoard(GameBoard gb, GameBoard::Color cl) 
{
	//�F�ݒ�
	SetColor(static_cast<int>(cl), static_cast<int>(cl));

	SetCursorPos(gb.mGameBoardPosX, gb.mGameBoardPosY);
	for (int x = 0; x < GameBoard::mGbWidth + 2; ++x) {
		cout << "  ";
	}

	SetCursorPos(gb.mGameBoardPosX, gb.mGameBoardPosY + GameBoard::mGbHeight + 1);
	for (int x = 0; x < GameBoard::mGbWidth + 2; ++x) {
		cout << "  ";
	}
	for (int y = gb.mGameBoardPosY + 1; y < gbpy + GameBoard::mGbHeight + 1; ++y) {
		SetCursorPos(gb.mGameBoardPosX, y);
		cout << "  ";
		SetCursorPos(gb.mGameBoardPosX + (GameBoard::mGbWidth + 1) * 2, y);
		cout << "  ";
	}
}

//�Q�[���{�[�h�����̕`��
void DrawEngine::DrawStage(GameBoard gb) {
	BlockPiece bp;

	for (int y = 1; y <= GameBoard::mGbHeight; ++y) {
		SetCursorPos(gb.GetmGameBoardPosX() + 2, y + gb.GetmGameBoardPosY());
		for (int x = 1; x <= GameBoard::mGbWidth; ++x) {
			//��ł͂Ȃ��u���b�N�͌Œ艻��
			if (gb.GetGameBoardValue(x,y) != gb.GetmEmpty()) {
				int Color = bp.TetriminoTypeToColor(gb.GetGameBoardValue(x, y));

				//�e�g���~�m�̐F��ݒ�
				SetColor(static_cast<int>(Color), static_cast<int>(Color));
			}
			else
				SetColor(static_cast<int>(GameBoard::Color::Gray), static_cast<int>(GameBoard::Color::Black));
			cout << "  ";
		}
	}
}

//DrawGameBoard�ɈڐA
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

int DrawEngine::TetriminoTypeToColor(int ttc) {
	static int tkl;


	switch (ttc)
	{
		case static_cast<int>(BlockPiece::TetrimnoType::TypeA) :
			tkl = static_cast<int>(GameBoard::Color::Cyan);
			break;
		case static_cast<int>(BlockPiece::TetrimnoType::TypeB) :
			tkl = static_cast<int>(GameBoard::Color::Yellow);
			break;
		case static_cast<int>(BlockPiece::TetrimnoType::TypeC) :
			tkl = static_cast<int>(GameBoard::Color::Red);
			break;
		case static_cast<int>(BlockPiece::TetrimnoType::TypeD) :
			tkl = static_cast<int>(GameBoard::Color::Green);
			break;
		case static_cast<int>(BlockPiece::TetrimnoType::TypeE) :
			tkl = static_cast<int>(GameBoard::Color::Blue);
			break;
		case static_cast<int>(BlockPiece::TetrimnoType::TypeF) :
			tkl = static_cast<int>(GameBoard::Color::DarkRed);
			break;
		case static_cast<int>(BlockPiece::TetrimnoType::TypeG) :
			tkl = static_cast<int>(GameBoard::Color::Violet);
			break;
		default:
			break;
	}

	return tkl;
}

void DrawEngine::SetCursorPos(int x, int y) {
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hCons, pos);
}


//�X�R�A�\��
void DrawEngine::DrawScore() {
	GameBoard gb;
	Score sc;
	
	//�X�R�A�\���ʒu�̐ݒ�
	int ScorePosX = (gb.GetmGameBoardPosX() + GameBoard::mGbWidth + 2) * 3 + 4;
	int ScorePosY = gb.GetmGameBoardPosY();
	
	int score = sc.GetScore();//�X�R�A�擾

	SetCursorPos(ScorePosX,ScorePosY);
	//�X�R�A�̐F��ݒ�
	SetColor(static_cast<int>(GameBoard::Color::Gray), static_cast<int>(GameBoard::Color::Black));
	
	cout << "score:";
	cout.width(8);     
	cout << score;
}

//�f�o�b�N�p�e�X�g�֐�
void DrawEngine::DrawRotType() {
	GameBoard gb;
	Score sc;
	BlockPiece bp;

	int RotPosX = (gb.GetmGameBoardPosX() + (GameBoard::mGbWidth + 2) * 3 + 4);
	int RotePosY = gb.GetmGameBoardPosY() + 2;

	int RotType = bp.GetRot();
	SetCursorPos(RotPosX, RotePosY);
	SetColor(static_cast<int>(GameBoard::Color::Gray), static_cast<int>(GameBoard::Color::Black));
	cout << "RotType:";
	cout.width(8);
	cout << RotType;
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