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

//�e�g���~�m�̕`��
void DrawEngine::DrawTetrimino(const GameBoard& ioGameBoard, const BlockPiece& ioBlockPiece)
{
	//GUI�A�v���Ƃ��ĈڐA����ۂɃe�g���~�m���`��ƐF���������\���̂Ƃ��Ē�`���邱�Ƃŕ`����s���֐�������w�肷��K�v���Ȃ���
	int tetrimino_color = TetriminoTypeToColor(ioBlockPiece.mTetriminoType + 1);//Type�͈̔͂�0~6�ł͂Ȃ��A1~7�ɁA

	//�e�g���~�m�̐F��ݒ�
	SetColor(static_cast<int>(tetrimino_color), static_cast<int>(tetrimino_color));


	for (int i = 0; i < gTetriminoWidth; ++i) {
		int blockpiece_posy = ioBlockPiece.mTetriminoPosY + i;
		
		if (blockpiece_posy < 0 || blockpiece_posy >= GameBoard::mGbHeight) continue;
			for (int k = 0; k < gTetriminoWidth; ++k) {
				int blockpiece_posx = ioBlockPiece.mTetriminoPosX + k;

				if (blockpiece_posx < 0 || blockpiece_posx >= GameBoard::mGbWidth) continue;
					
				if (ioBlockPiece.mTetrimino[k][i]) {
					SetCursorPos(ioGameBoard.GetmGameBoardPosX() + (blockpiece_posx + 1) * 2, 
								ioGameBoard.GetmGameBoardPosY() + blockpiece_posy + 1);
					cout << "  ";
			}
		}
	}
}

//�e�g���~�m�̌`�󂩂�F��ݒ肷��
int DrawEngine::TetriminoTypeToColor(int inTetriminoType) {
	static int tetrimino_color;


	switch (inTetriminoType)
	{
		case static_cast<int>(BlockPiece::TetrimnoType::TypeA) :
			tetrimino_color = static_cast<int>(Color::Cyan);
			break;
		case static_cast<int>(BlockPiece::TetrimnoType::TypeB) :
			tetrimino_color = static_cast<int>(Color::Yellow);
			break;
		case static_cast<int>(BlockPiece::TetrimnoType::TypeC) :
			tetrimino_color = static_cast<int>(Color::Red);
			break;
		case static_cast<int>(BlockPiece::TetrimnoType::TypeD) :
			tetrimino_color = static_cast<int>(Color::Green);
			break;
		case static_cast<int>(BlockPiece::TetrimnoType::TypeE) :
			tetrimino_color = static_cast<int>(Color::Blue);
			break;
		case static_cast<int>(BlockPiece::TetrimnoType::TypeF) :
			tetrimino_color = static_cast<int>(Color::DarkRed);
			break;
		case static_cast<int>(BlockPiece::TetrimnoType::TypeG) :
			tetrimino_color = static_cast<int>(Color::Violet);
			break;
		default:
			break;
	}

	return tetrimino_color;
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
	int ScorePosX = (game_board.GetmGameBoardPosX() + GameBoard::mGbWidth + 2) * 3 + 4;
	int ScorePosY = game_board.GetmGameBoardPosY()+2;
	
	int score = sc.GetScore();//�X�R�A�擾

	SetCursorPos(ScorePosX,ScorePosY);
	//�X�R�A�̐F��ݒ�
	SetColor(static_cast<int>(Color::Gray), static_cast<int>(Color::Black));
	
	cout << "Score:";
	cout.width(8);     
	cout << score;
}

//���[���\��
void DrawEngine::DrawHighScore() {
	//�X�R�A�\���ʒu�̐ݒ�
	int RulePosX = (game_board.GetmGameBoardPosX() + GameBoard::mGbWidth + 2) * 3 + 4;
	int RulePosY = game_board.GetmGameBoardPosY();

	int hiscore = score.GetHighScore();//�X�R�A�擾

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

//�O�i�F�Ɣw�i�F��ݒ�
void DrawEngine::SetColor(int inForeGroundColor, int inBackGroundColor) {
	HANDLE h_cons = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD attr = 0;
	if (inForeGroundColor & static_cast<int>(Mask::Intensity))
		attr |= FOREGROUND_INTENSITY;
	if (inForeGroundColor & static_cast<int>(Mask::RedMask))
		attr |= FOREGROUND_RED;
	if (inForeGroundColor & static_cast<int>(Mask::GreenMask))
		attr |= FOREGROUND_GREEN;
	if (inForeGroundColor & static_cast<int>(Mask::BlueMask))
		attr |= FOREGROUND_BLUE;

	if (inBackGroundColor & static_cast<int>(Mask::Intensity))
		attr |= BACKGROUND_INTENSITY;
	if (inBackGroundColor & static_cast<int>(Mask::RedMask))
		attr |= BACKGROUND_RED;
	if (inBackGroundColor & static_cast<int>(Mask::GreenMask))
		attr |= BACKGROUND_GREEN;
	if (inBackGroundColor & static_cast<int>(Mask::BlueMask))
		attr |= BACKGROUND_BLUE;
	SetConsoleTextAttribute(h_cons, attr);
}