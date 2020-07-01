#include <iostream>
#include <Windows.h>
#include <thread>
#include <chrono>
#include <memory>
#include <conio.h>
#include <chrono>

#include "Game.h"

#include "state/Score.h"
#include "board/GameBoard.h"
#include "board/DrawEngine.h"
#include "board/BlockPiece.h"
#include "Input/KeyInput.h"
#include "Data/Data.h"

using std::cout;
using std::endl;


//game
void gPlayGame(DrawEngine& ioDrawEngine) {
	
	GameBoard gb(1,2);

	BlockPiece blockpiece;
	KeyInput key_input;
	Score score;
	Data data;

	int HiScore = data.HiScoreLoad();//ハイスコアを取得
	score.SetHighScore(HiScore);//ハイスコアをセットする

	//gb = new GameBoard(1,2);//ゲームボード位置設定
	gb.InitGameBoard();//ゲームボード初期化
	//gb1->InitGameBoard();
	

	score.SetScore(0);//スコアの初期化

	blockpiece.AddTertimino(gb);//テトリミノの追加

	int bpx = blockpiece.GetgTetriminoPosX(gb);//テトリミノx座標設定
	int bpy = blockpiece.GetTetriminoPosY(gb);//テトリミノy座標設定

	ioDrawEngine.DrawBoard(gb);//ゲームボード外枠の描画
	ioDrawEngine.DrawStage(gb);//ゲームボード内部の描画

	ioDrawEngine.DrawScore(score);//スコア表示
	ioDrawEngine.DrawHighScore();//ハイスコア表示

	ioDrawEngine.DrawTetrimino(blockpiece);//テトリミノの描画

	// Todo 
	int cnt = 1;
	int ts = 0;

	int key = 0;
	int keyDown = 0;

	
	//テトリミノ生成時点で固定ブロックと接触するとループを抜ける
	 while (!blockpiece.IsOverLaped(gb)) {
	//for(int cnt =1;;++cnt){
			bool update = false;

			if (cnt % FallInterval == 0 || key == VK_DOWN){
				//テトリミノが落下完了した場合に以下の処理
				if (!blockpiece.IsMoveDown(gb)) {
					key = 0;
					int FinalPosX = blockpiece.GetgTetriminoPosX(gb);
					int FinalPosY = blockpiece.GetTetriminoPosY(gb);
					blockpiece.ChangeBlock(gb);//ブロックの固定化
					blockpiece.DeleteLine(gb);//揃ったlineの消去
					ioDrawEngine.DrawScore(score);
					
					blockpiece.AddTertimino(gb);
					ioDrawEngine.DrawStage(gb);//ゲームボード内部の描画(ToDo)
					ioDrawEngine.DrawTetrimino(blockpiece);//テトリミノの描画
					bpx = blockpiece.GetgTetriminoPosX(gb);//テトリミノx座標設定
					bpy = blockpiece.GetTetriminoPosY(gb);//テトリミノy座標設定
					
					//枠外に出てしまった場合終了
					if (blockpiece.IsOverLaped(gb))
						return;
					
					continue;
				}
				++bpy;     // 落下中テトリスをひとつ下に移動
				blockpiece.SetTeriminoPosY(bpy);
				update = true;
			}

			if (cnt % MoveInterval == 0) {   
				//Move Left
				if (key == VK_LEFT) {
					if (blockpiece.IsMoveLeft(gb)) {
						--bpx;  
						blockpiece.SetTeriminoPosX(bpx);
						update = true;
					}
					key = 0;
				}
				//Move Right
				else if (key == VK_RIGHT) {
					if (blockpiece.IsMoveRight(gb)) {
						++bpx;  
						blockpiece.SetTeriminoPosX(bpx);
						update = true;
					}
					key = 0;
				}
			}

			//Rotate
			if (cnt % RotateInterval == 0) {       
				if (key == VK_UP) {
					int tx = blockpiece.GetRot(gb);

					if (++tx >= 4) {
						blockpiece.SetRot(0);
						tx = 0;
					}
					blockpiece.SetTertimino(gb,blockpiece.mTetriminoType, tx);
					if (blockpiece.IsOverLaped(gb)) {    
						blockpiece.SetTertimino(gb,blockpiece.mTetriminoType, blockpiece.GetRot(gb));
					}
					else {
						blockpiece.SetRot(tx);
						update = true;
					}
					key = 0;
				}
			}
			if (update) {
				ioDrawEngine.DrawStage(gb);//ゲームボード内部の描画(ToDo)
				ioDrawEngine.DrawTetrimino(blockpiece);
				
			}
			if (!keyDown) {     // キー押下を受け付けていない場合
				if (key_input.IsKeyPressed(VK_LEFT)) {
					key = keyDown = VK_LEFT;
				}
				else if (key_input.IsKeyPressed(VK_RIGHT)) {
					key = keyDown = VK_RIGHT;
				}
				else if (key_input.IsKeyPressed(VK_UP)) {
					key = keyDown = VK_UP;
				}
				else if (key_input.IsKeyPressed(VK_DOWN)) {
					key = keyDown = VK_DOWN;
				}
			}
			else {
				if (!key_input.IsKeyPressed(keyDown))// 押されたキーが離された
					keyDown = 0;
			}


			Sleep(10);
			//std::this_thread::sleep_for(std::chrono::seconds(1));
			++cnt;
		}


}

void draw(DrawEngine& de) {

}

//main
int main() {
	using namespace std;
	chrono::system_clock::time_point start, end;

	//ゲーム開始
	DrawEngine de;
	KeyInput ki;
	Score sc;
	Data d;

	for (;;) {
		start = chrono::system_clock::now();
		
		gPlayGame(de);


		end = chrono::system_clock::now();

		double time = static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0);
		
		//処理を変更する必要がある。
		de.SetCursorPos(0, GameBoard::mGbHeight+5);
		de.SetColor((int)DrawEngine::Color::Gray, (int)DrawEngine::Color::Black);
		
		//ハイスコア更新時の処理
		if (sc.GetScore()>sc.GetHighScore()) {
			std::cout << "HiScore!!" << sc.GetScore() <<endl;
			d.HiScoreSave(sc.GetScore());
		}
		
		std::cout << "GAME OVER. Replay? [Y/N] "<< endl;
		
		for (;;) {
			if (ki.IsKeyPressed('N'))
				return 0;
			if (ki.IsKeyPressed('Y'))
				break;
			Sleep(LoopInterval);     // 10ミリ秒ウェイト
		}

		
		de.SetCursorPos(0, GameBoard::mGbHeight + 5);//リプレイ時にゲームボードの位置を初期化
		
		for (int i = 0; i < 79; ++i) {
			std::cout << ' ';
		}

	}
}


// Key入力管理クラス
bool Game::KeyPress(int k) {
	// When pausing, ignore keys other than PAUSE and ENTER
	if (k != VK_PAUSE)
		//&& k != VK_RETURN && isPaused)
		return false;

	switch (k)
	{
	case VK_UP:
		
		break;
	case VK_DOWN:
		
		break;
	case VK_LEFT:
		
		break;
	case VK_RIGHT:
		
		break;
	case VK_SPACE:
	
		break;
	case VK_PAUSE:
	
		break;
	case VK_RETURN:
		//restart();
	default:
		return false;
	}
	return true;
}
