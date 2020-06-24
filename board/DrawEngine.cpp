#include <iostream>


#include "DrawEngine.h"




using std::cout;
using std::endl;

//ゲームボード外枠の描画
void DrawEngine::DrawBoard(GameBoard const& gb) {
	//色設定
	SetColor((int)Color::Gray, (int)Color::Gray);

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

//ゲームボード外枠の描画(外枠色指定)
void DrawEngine::DrawBoard(GameBoard gb, Color cl) 
{
	//色設定
	SetColor((int)cl, (int)cl);

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

//ゲームボード内部の描画
void DrawEngine::DrawStage(GameBoard gb) {
	for (int y = 1; y <= GameBoard::mGbHeight; ++y) {
		SetCursorPos(gb.GetmGameBoardPosX() + 2, y + gb.GetmGameBoardPosY());
		for (int x = 1; x <= GameBoard::mGbWidth; ++x) {
			int Value = gb.GetGameBoardValue(x, y);
			//空ではないブロックは固定化→
			if(Value !=GameBoard::Value::empty){
				int Color = TetriminoTypeToColor(Value);

				//テトリミノの色を設定
				SetColor(Color, Color);
			}
			else
				SetColor((int)Color::Gray, (int)Color::Black);
			cout << "  ";
		}
	}
}

//DrawGameBoardに移植
void DrawEngine::DrawTetrimino(BlockPiece& bp)
{
	//GUIアプリとして移植する際にテトリミノを形状と色を持った構造体として定義することで描画を行う関数側から指定する必要をなくす
	int Color = TetriminoTypeToColor(bp.mTetriminoType + 1);//Typeの範囲を0~6ではなく、1~7に、

	//テトリミノの色を設定
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

//テトリミノの形状から色を設定する
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

//コンソール上の描画位置を設定
void DrawEngine::SetCursorPos(int x, int y) {
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hCons, pos);
}


//スコア表示
void DrawEngine::DrawScore(Score sc) {
	//スコア表示位置の設定
	int ScorePosX = (gb.GetmGameBoardPosX() + GameBoard::mGbWidth + 2) * 3 + 4;
	int ScorePosY = gb.GetmGameBoardPosY()+2;
	
	int score = sc.GetScore();//スコア取得

	SetCursorPos(ScorePosX,ScorePosY);
	//スコアの色を設定
	SetColor(static_cast<int>(Color::Gray), static_cast<int>(Color::Black));
	
	cout << "Score:";
	cout.width(8);     
	cout << score;
}
//
////ルール表示
void DrawEngine::DrawHighScore() {
	//スコア表示位置の設定
	int RulePosX = (gb.GetmGameBoardPosX() + GameBoard::mGbWidth + 2) * 3 + 4;
	int RulePosY = gb.GetmGameBoardPosY();

	int hiscore = sc.GetHighScore();//スコア取得

	SetCursorPos(RulePosX, RulePosY);
	//スコアの色を設定
	SetColor(static_cast<int>(Color::Gray), static_cast<int>(Color::Black));

	cout << "HiScore:";
	cout.width(6);
	cout << hiscore;
}

//デバック用テスト関数
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