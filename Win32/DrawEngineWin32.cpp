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
	
	HBRUSH h_brush = CreateSolidBrush(RGB(225, 200, 150));
	
	mRect.top = mHeight;
	mRect.left = mWidth;
	mRect.bottom = 0;
	mRect.right = mWidth + 8;

	FillRect(mHdc, &mRect, h_brush);
	DeleteObject(h_brush);
}

//テキスト描画
 void DrawEngineWin32::DrawText(TCHAR* szText, int x, int y) const
{
	TextOut(mHdc, x, y, szText, lstrlen(szText));
}

//スコア描画
const void DrawEngineWin32::DrawScore(int mScore, int inPosX, int inPosY)
{
	TCHAR sz_buffer[20];
	int score_board = wsprintf(sz_buffer, TEXT("Score: %6d"), mScore);

	SetBkMode(mHdc, OPAQUE);
	TextOut(mHdc, inPosX, inPosY, sz_buffer, score_board);
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

	MoveToEx(mHdc, x, y + 1, NULL);
	LineTo(mHdc, x, y);
	LineTo(mHdc, x + 1, y);
	DeleteObject(hBrush);
}

void DrawEngineWin32::DrawNextPiece(TetriminoWin32& ioTetrimino, int pos_x, int pos_y)
{
	TCHAR szBuffer[] = TEXT("Next:");
	TextOut(mHdc, pos_x, pos_y + 5, szBuffer, lstrlen(szBuffer));
	COLORREF color = ioTetrimino.GetTetriminoColor();

	
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (ioTetrimino.IsPointExists(i,j))
				DrawTetrimino(i + pos_x, j + pos_y, color);
			else
				DrawTetrimino(i + pos_x, j + pos_y, RGB(0, 0, 0));
		}
	}
}
