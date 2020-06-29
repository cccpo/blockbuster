#include <Windows.h>
#include "../Game.h"
#include "../board/GameBoard.h"
#include "../board/DrawEngine.h"

#include "../resource.h"

//コールバック関数
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow){
//
//	static TCHAR szAppName[] = TEXT("BlockPiece");
//	WNDCLASS wc; //WNDCLASS構造体:ウィンドウクラスの属性を表す
//	HWND hwnd; //ウィンドウハンドル
//	MSG msg;
//
//
//
//	//ウィンドウクラスの属性を設定
//	
//	//style:スタイルを指定する
//	//CS_HREDRAW:水平方向のサイズが変更された時再描画 
//	//CS_VREDRAW:垂直方向のサイズが変更されたとき再描画
//	wc.style = CS_HREDRAW | CS_VREDRAW;
//	//lpfnWndProc:ウィンドウプロシージャ:まだウィンドウプロシージャが完成していないので
//	//規定のDefWindoProcを宣言
//	//wc.lpfnWndProc = DefWindowProc;
//	wc.lpfnWndProc = WndProc;
//	//ウィンドウクラス構造体の後に確保する領域のバイト数
//	wc.cbClsExtra = 0;
//	//ウィンドウインスタンスの後に確保する領域のバイト数
//	wc.cbWndExtra = 0;
//	//
//	//IpfnWndProcで指定した関数が含まれるインスタンスへのハンドルを指定
//	wc.hInstance = hInstance;
//	//
//	//アイコンへのハンドルを指定
//	//wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	wc.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
//	//マウスカーソルへのハンドルを指定
//	//IDC_ARROW:矢印
//	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
//	//
//	//ウィンドウの背景を描画するブラシへのハンドル
//	wc.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);
//	//メニューのリソース名
//	wc.lpszMenuName = NULL;
//	//ウィンドウクラスに割り当てる名前
//	wc.lpszClassName = szAppName;
//	
//	//ウィンドウクラスの登録 登録失敗時に0を返却　」
//	//#ToDO 登録失敗時のエラーメッセージの作成
//	if (!RegisterClass(&wc)) return 0;
//
//	hwnd = CreateWindow(szAppName,
//						TEXT("BlcokBuster"),
//						WS_OVERLAPPEDWINDOW,
//	                    CW_USEDEFAULT, 
//                        CW_USEDEFAULT,
//                        CW_USEDEFAULT, 
//                        CW_USEDEFAULT,
//			            NULL, 
//                        NULL,hInstance, 
//	                    NULL);
//	
//	if(!hwnd)return 0;
//
//	//ウィンドウを表示
//	ShowWindow(hwnd, nCmdShow);
//
//	//ウィンドウを再描画
//	UpdateWindow(hwnd);
//
//	//メッセージループ
//	//while (GetMessage(&msg, NULL, 0, 0)) {
//	//	TranslateMessage(&msg);//キー入力メッセージを文字メッセージに変換
//	//	DispatchMessage(&msg);//メッセージをウィンドウプロシージャへディスパッチする
//	//}
//
//	//メッセージボックス生成
//	MessageBox(NULL,
//		TEXT("Create Window"),
//		TEXT("Test"),
//		MB_OK);
//
//	
//
//	
//
//	return 0;
//}
//

//ウィンドウプロシージャ(メッセージに対するコールバック関数

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {

	PAINTSTRUCT ps;
	HDC hdc;
	

	switch (message) {
	
	//ウィンドウ破棄メッセージ
	case WM_CREATE:
		hdc = GetDC(hwnd);
		return 0;

	case WM_KEYDOWN:
		
		return 0;

	case WM_TIMER:
		
		return 0;

	case WM_KILLFOCUS:
	
		return 0;

	case WM_SETFOCUS:
		
		return 0;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);

		EndPaint(hwnd, &ps);
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hwnd, message, wParam, lParam);
}