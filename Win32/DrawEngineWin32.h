#pragma once

#include <Windows.h>

class DrawEngineWin32
{
public:
	DrawEngineWin32(HDC mHdc, HWND mHwnd, 
		int pxPerBlock = 15, int mWidth = 10, int mHeight = 20);

	~DrawEngineWin32();

	const void DrawTetrimino(int x, int y, COLORREF color);

	const void DrawUI();
	const void DrawText(TCHAR* szText, int x, int y);
	const void DrawScore(int score, int x, int y);

	//const void DrawNextTetrimino(int x, int y, COLORREF color);

	

protected:
	HDC mHdc;
	HWND mHwnd;
	RECT mRect;
	int mWidth;
	int mHeight;


};

