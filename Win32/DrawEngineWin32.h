#pragma once
#include "TetriminoWin32.h"
#include <Windows.h>

class DrawEngineWin32
{
public:
	DrawEngineWin32(HDC mHdc, HWND mHwnd, 
					int mBlockSize = 25, int mWidth = 10, int mHeight = 20);

	~DrawEngineWin32();

	void DrawTetrimino(int pos_x, int pos_y, COLORREF color);
	void DrawNextTetrimino(TetriminoWin32& ioTetrimino, int pos_x, int pos_y);

	void DrawUIRightArea();
	void DrawUILeftArea();

	void DrawTextOn(TCHAR *text, int pos_x, int pos_y) const;
	
	const void DrawScore(int mScore, int pos_x, int pos_y);

protected:
	HDC mHdc;
	HWND mHwnd;
	RECT mRect;
	int mWidth;
	int mHeight;


};

