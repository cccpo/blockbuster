#pragma once

#include <Windows.h>

class DrawEngineWin32
{
public:
	DrawEngineWin32(HDC mHdc, HWND mHwnd, 
		int pxPerBlock = 15, int mWidth = 10, int mHeight = 20);

	~DrawEngineWin32();

	void DrawTetrimino(int x, int y, COLORREF color);

	void DrawUI();
	void DrawText(TCHAR* szText, int x, int y) const;
	void DrawScore(int score, int x, int y) const;

	void DrawTetrimino();

	

protected:
	HDC mHdc;
	HWND mHwnd;
	RECT mRect;
	int mWidth;
	int mHeight;


};

