#include <Windows.h>

const int SCREEN_WIDTH = 10;    // Level width in cells
const int SCREEN_HEIGHT = 20;   // Level height in cells 

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow){

	static TCHAR szAppName[] = TEXT("BlockPiece");
	WNDCLASS wc; //WNDCLASS構造体:ウィンドウクラスの属性を表す
	HWND hwnd; //ウィンドウハンドル

	//ウィンドウクラスの属性を設定
	//wc.style
	//CS_HREDRAW:水平方向のサイズが変更された時再描画 
	//CS_VREDRAW:垂直方向のサイズが変更されたとき再描画
	wc.style = CS_HREDRAW | CS_VREDRAW;

	//メッセージボックス生成
	MessageBox(NULL,
		TEXT("HEllo,WOrd;"),
		TEXT("TEst"),
		MB_OK);

	return 0;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {

}