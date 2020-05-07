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
//#include "state/Score.h"
#include "board/GameBoard.h"
#include "board/DrawGameBoard.h"
#include "agent/BlockPiece.h"
#include "Input/KeyInput.h"

using std::cout;
using std::endl;

//game
void StartGame() {

	GameBoard gb;
	DrawGameBoard dgb;
	BlockPiece bp;
	KeyInput ki;
	//Score sc;

	

	gb.InitGameBoard();//ゲームボード初期化
	gb.DrawBoard();//ゲームボード外枠の描画
	gb.DrawStage();//ゲームボード内部の描画
	dgb.DrawScore();//スコア表示
	bp.AddTertimino();//テトリミノの追加
	bp.DrawTetrimino();//テトリミノの描画

	int bpx = bp.GetgTetriminoPosX();//テトリミノx座標設定
	int bpy = bp.GetTetriminoPosY();//テトリミノy座標設定

	
	
	int cnt = 1;
	int ts = 0;

	int key = 0;
	int keyDown = 0;

	
	//テトリミノ生成時点で固定ブロックと接触するとループを抜ける
	 while (!bp.IsOverLaped()) {
	//for(int cnt =1;;++cnt){
			bool update = false;

			if (cnt % FallInterval == 0 || key == VK_DOWN){
				//テトリミノが動かくなったら以下の処理
				if (!bp.IsMoveDown()) {
					key = 0;
					int FinalPosX = bp.GetgTetriminoPosX();
					int FinalPosY = bp.GetTetriminoPosY();
					bp.ChangeBlock();//ブロックの固定化
					bp.DeleteLine();//揃ったlineの消去
					dgb.DrawScore();
					bp.AddTertimino();
					gb.DrawStage();//ゲームボード内部の描画(ToDo)
					bp.DrawTetrimino();
					bpx = bp.GetgTetriminoPosX();//テトリミノx座標設定
					bpy = bp.GetTetriminoPosY();//テトリミノy座標設定
					if (bp.IsOverLaped()) 
						return;
					continue;
				}
				++bpy;     // 落下中テトリスをひとつ下に移動
				bp.SetgTeriminoPosY(bpy);
				update = true;
			}

			if (cnt % MoveInterval == 0) {   
				if (key == VK_LEFT) {
					if (bp.IsMoveLeft()) {
						--bpx;  
						bp.SetTeriminoPosX(bpx);
						update = true;
					}
					key = 0;
				}
				else if (key == VK_RIGHT) {
					if (bp.IsMoveRight()) {
						++bpx;  
						bp.SetTeriminoPosX(bpx);
						update = true;
					}
					key = 0;
				}
			}

			if (cnt % RotateInterval == 0) {       
				if (key == VK_UP) {
					int tx = bp.GetRot();

					if (++tx >= 4) {
						bp.SetRot(0);
					}
					bp.SetTertimino(bp.GetgTeriminoType(), tx);
					if (bp.IsOverLaped()) {    
						bp.SetTertimino(bp.GetgTeriminoType(), bp.GetRot());
					}
					else {
						bp.SetRot(tx);
						update = true;
					}
					key = 0;
				}
			}
			if (update) {
				gb.DrawStage();//ゲームボード内部の描画(ToDo)
				bp.DrawTetrimino();
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
	//StartGame();
	GameBoard gb;
	KeyInput ki;
	//cout << st.GetScore() << endl;

	for (;;) {
		start = chrono::system_clock::now();
		
		StartGame();


		end = chrono::system_clock::now();

		double time = static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0);
		gb.SetCursorPos(0, cGbHeight+5);
		gb.SetColor(static_cast<int>(GameBoard::Color::Gray), static_cast<int>(GameBoard::Color::Black));
		std::cout << "GAME OVER. Replay? [Y/N] ";
		
		for (;;) {
			if (ki.IsKeyPressed('N'))
				return 0;
			if (ki.IsKeyPressed('Y'))
				break;
			Sleep(LoopInterval);     // 10ミリ秒ウェイト
		}

		gb.SetCursorPos(0, 25 - 1);//リプレイ時にゲームボードの位置が初期化される
		
		for (int i = 0; i < 80 - 1; ++i) {
			std::cout << ' ';
		}

	}
}




