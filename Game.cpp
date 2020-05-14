#include <iostream>
#include <Windows.h>
#include <thread>
#include <chrono>
#include <memory>
#include <conio.h>
#include <chrono>

#include "Game.h"
//#include "message/Message.h"
//#include "window/window.h"
#include "state/Score.h"
#include "board/GameBoard.h"
#include "board/DrawEngine.h"
#include "agent/BlockPiece.h"
#include "Input/KeyInput.h"
#include "Data/Data.h"

using std::cout;
using std::endl;


//game
void StartGame() {
	static GameBoard *gb,*gb1;

	DrawEngine dgb;
	static BlockPiece *bp;
	KeyInput ki;
	Score sc;
	Data d;

	int HiScore = d.HiScoreLoad();//ハイスコアを取得
	sc.SetHighScore(HiScore);//ハイスコアをセットする

	gb = new GameBoard(1,2);//
	//gb1 = new GameBoard(90, 2);
	gb->InitGameBoard();//ゲームボード初期化
	//gb1->InitGameBoard();
	
	dgb.DrawBoard(*gb);//ゲームボード外枠の描画
	//dgb.DrawBoard(*gb1,GameBoard::Color::Red);
	dgb.DrawStage(*gb);//ゲームボード内部の描画

	sc.SetScore(0);//スコアの初期化
	dgb.DrawScore();//スコア表示
	
	bp = new BlockPiece();

	bp->AddTertimino();//テトリミノの追加
	dgb.DrawTetrimino(*bp);//テトリミノの描画

	int bpx = bp->GetgTetriminoPosX();//テトリミノx座標設定
	int bpy = bp->GetTetriminoPosY();//テトリミノy座標設定

	
	
	int cnt = 1;
	int ts = 0;

	int key = 0;
	int keyDown = 0;

	
	//テトリミノ生成時点で固定ブロックと接触するとループを抜ける
	 while (!bp->IsOverLaped()) {
	//for(int cnt =1;;++cnt){
			bool update = false;

			if (cnt % FallInterval == 0 || key == VK_DOWN){
				//テトリミノが動かくなったら以下の処理
				if (!bp->IsMoveDown()) {
					key = 0;
					int FinalPosX = bp->GetgTetriminoPosX();
					int FinalPosY = bp->GetTetriminoPosY();
					bp->ChangeBlock();//ブロックの固定化
					bp->DeleteLine();//揃ったlineの消去
					dgb.DrawScore();
					bp->AddTertimino();
					dgb.DrawStage(*gb);//ゲームボード内部の描画(ToDo)
					dgb.DrawTetrimino(*bp);
					bpx = bp->GetgTetriminoPosX();//テトリミノx座標設定
					bpy = bp->GetTetriminoPosY();//テトリミノy座標設定
					if (bp->IsOverLaped())
						return;
					continue;
				}
				++bpy;     // 落下中テトリスをひとつ下に移動
				bp->SetgTeriminoPosY(bpy);
				update = true;
			}

			if (cnt % MoveInterval == 0) {   
				if (key == VK_LEFT) {
					if (bp->IsMoveLeft()) {
						--bpx;  
						bp->SetTeriminoPosX(bpx);
						update = true;
					}
					key = 0;
				}
				else if (key == VK_RIGHT) {
					if (bp->IsMoveRight()) {
						++bpx;  
						bp->SetTeriminoPosX(bpx);
						update = true;
					}
					key = 0;
				}
			}

			if (cnt % RotateInterval == 0) {       
				if (key == VK_UP) {
					int tx = bp->GetRot();

					if (++tx >= 4) {
						bp->SetRot(0);
						tx = 0;
					}
					bp->SetTertimino(bp->mTetriminoType, tx);
					if (bp->IsOverLaped()) {    
						bp->SetTertimino(bp->mTetriminoType, bp->GetRot());
					}
					else {
						bp->SetRot(tx);
						update = true;
					}
					key = 0;
				}
			}
			if (update) {
				dgb.DrawStage(*gb);//ゲームボード内部の描画(ToDo)
				dgb.DrawTetrimino(*bp);
				
			}
			if (!keyDown) {     // キー押下を受け付けていない場合
				if (ki.IsKeyPressed(VK_LEFT)) {
					key = keyDown = VK_LEFT;
				}
				else if (ki.IsKeyPressed(VK_RIGHT)) {
					key = keyDown = VK_RIGHT;
				}
				else if (ki.IsKeyPressed(VK_UP)) {
					key = keyDown = VK_UP;
				}
				else if (ki.IsKeyPressed(VK_DOWN)) {
					key = keyDown = VK_DOWN;
				}
			}
			else {
				if (!ki.IsKeyPressed(keyDown))// 押されたキーが離された
					keyDown = 0;
			}


			Sleep(10);
			//std::this_thread::sleep_for(std::chrono::seconds(1));
			++cnt;
		}


}





//main
int main() {
	using namespace std;
	chrono::system_clock::time_point start, end;

	//ゲーム開始
	GameBoard gb;
	DrawEngine dgb;
	KeyInput ki;
	//cout << st.GetScore() << endl;
	Score sc;
	Data d;

	for (;;) {
		start = chrono::system_clock::now();
		
		StartGame();


		end = chrono::system_clock::now();

	

		double time = static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0);
		
		//処理を変更する必要がある。
		dgb.SetCursorPos(0, GameBoard::mGbHeight+5);
		dgb.SetColor(static_cast<int>(GameBoard::Color::Gray), static_cast<int>(GameBoard::Color::Black));
		
		if (sc.GetScore()>sc.GetHighScore()) {
			std::cout << "HiScore!!" << sc.GetScore() <<endl;
			d.HiScoreSave(sc.GetScore());
		}
		
		//dgb.SetCursorPos(0, GameBoard::mGbHeight + 15);
		std::cout << "GAME OVER. Replay? [Y/N] "<< endl;
		
		for (;;) {
			if (ki.IsKeyPressed('N'))
				return 0;
			if (ki.IsKeyPressed('Y'))
				break;
			Sleep(LoopInterval);     // 10ミリ秒ウェイト
		}

		dgb,SetCursorPos(0, 25 - 1);//リプレイ時にゲームボードの位置が初期化される
		
		for (int i = 0; i < 80 - 1; ++i) {
			std::cout << ' ';
		}

	}
}




