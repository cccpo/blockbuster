#pragma once
#include "TetriminoWin32.h"
#include <Windows.h>

class DrawEngineWin32
{
public:
	DrawEngineWin32(HDC mHdc, HWND mHwnd, 
					int mBlockSize = 25, int mWidth = 10, int mHeight = 20);

	~DrawEngineWin32();

	void DrawTetrimino(int pos_x, int pos_y, COLORREF color);//�e�g���~�m�`��
	void DrawNextTetrimino(TetriminoWin32& ioTetrimino, int pos_x, int pos_y);//���̃e�g���~�m��`��

	void DrawUIRightArea();//�EUI�G���A�`��
	void DrawUILeftArea();//��UI�G���A�`��

	void DrawTextOn(TCHAR *text, int pos_x, int pos_y) const;//�e�L�X�g�`��
	void DrawTextOnRed(TCHAR* text, int pos_x, int pos_y) const;//�ԕ����e�L�X�g�`��
	
	const void DrawScore(int inScore, int pos_x, int pos_y);//�X�R�A�\��
	const void DrawHiScore(int inHiScore, int pos_x, int pos_y);//�@�n�C�X�R�A�\��
	const void DrawLines(int inLines, int pos_x, int pos_y);//�폜�������C������\��

	const void DrawSpeed(int inSpeed, int x, int y) ;


protected:
	HDC mHdc;
	HWND mHwnd;
	RECT mRect;
	int mWidth;
	int mHeight;


};

