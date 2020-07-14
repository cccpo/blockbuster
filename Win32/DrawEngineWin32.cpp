#include "DrawEngineWin32.h"

DrawEngineWin32::DrawEngineWin32(HDC mHdc, HWND mHwnd, 
								 int pxPerBlock, int mWidth, int mHeight) :
	mHdc(mHdc), mHwnd(mHwnd), mWidth(mWidth), mHeight(mHeight)
{
	//クライアントエリアのサイズを取得
	GetClientRect(mHwnd, &mRect);

	//デバイスコンテキストの状態を保存
	SaveDC(mHdc);

	SetMapMode(mHdc, MM_ISOTROPIC);	//マッピングモードの変更
	SetViewportExtEx(mHdc, pxPerBlock, pxPerBlock, 0);
	SetWindowExtEx(mHdc, 1, -1, 0);
	SetViewportOrgEx(mHdc, 0, mRect.bottom, 0);

	SetTextColor(mHdc, RGB(255, 255, 255));
	SetBkColor(mHdc, RGB(70, 70, 70));//背景色の指定
	SetBkMode(mHdc, TRANSPARENT);//背景モードを変更
}

DrawEngineWin32::~DrawEngineWin32()
{
	RestoreDC(mHdc, -1);
}

//UI描画
void DrawEngineWin32::DrawUI() 
{
	// Draw a gray area at the right
	HBRUSH hBrush = CreateSolidBrush(RGB(70, 70, 70));
	
	mRect.top = mHeight;
	mRect.left = mWidth;
	mRect.bottom = 0;
	mRect.right = mWidth + 8;

	FillRect(mHdc, &mRect, hBrush);
	DeleteObject(hBrush);
}

//テキスト描画
void DrawEngineWin32::DrawText(TCHAR* szText, int x, int y) const
{
	TextOut(mHdc, x, y, szText, lstrlen(szText));
}

//スコア描画
void DrawEngineWin32::DrawScore(int score, int x, int y) const
{
	TCHAR szBuffer[20];
	int score_board = wsprintf(szBuffer, TEXT("Score: %6d"), score);

	SetBkMode(mHdc, OPAQUE);
	TextOut(mHdc, x, y, szBuffer, score_board);
	SetBkMode(mHdc, TRANSPARENT);
}

//テトリミノ描画
void DrawEngineWin32::DrawTetrimino(int x, int y, COLORREF color) 
{
	HBRUSH hBrush = CreateSolidBrush(color);
	mRect.left = x;
	mRect.right = x + 1;
	mRect.top = y;
	mRect.bottom = y + 1;

	FillRect(mHdc, &mRect, hBrush);
}