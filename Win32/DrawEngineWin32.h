#pragma once
#include "TetriminoWin32.h"
#include <Windows.h>

class DrawEngineWin32
{
public:
	DrawEngineWin32(HDC mHdc, HWND mHwnd, 
		int pxPerBlock = 25, int mWidth = 10, int mHeight = 20);

	~DrawEngineWin32();

	void DrawTetrimino(int x, int y, COLORREF color);

	void DrawUI();
	void DrawText(TCHAR* szText, int x, int y) const;
	const void DrawScore(int mScore, int x, int y);

	//const void DrawNextTetrimino(int x, int y, COLORREF color);

	

protected:
	HDC mHdc;
	HWND mHwnd;
	RECT mRect;
	int mWidth;
	int mHeight;


};

