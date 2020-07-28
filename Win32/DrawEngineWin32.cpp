#include "DrawEngineWin32.h"

DrawEngineWin32::DrawEngineWin32(HDC mHdc, HWND mHwnd, 
								 int mBlockSize, int mWidth, int mHeight) :
	mHdc(mHdc), mHwnd(mHwnd), mWidth(mWidth), mHeight(mHeight)
{
	//�N���C�A���g�G���A�̃T�C�Y���擾
	GetClientRect(mHwnd, &mRect);

	//�f�o�C�X�R���e�L�X�g�̏�Ԃ�ۑ�
	SaveDC(mHdc);

	SetMapMode(mHdc, MM_ISOTROPIC);	//�}�b�s���O���[�h�̕ύX
	SetViewportExtEx(mHdc, mBlockSize, mBlockSize, 0);
	SetWindowExtEx(mHdc, 1, -1, 0);
	SetViewportOrgEx(mHdc, 0, mRect.bottom, 0);

	SetTextColor(mHdc, RGB(255, 255, 255));
	SetBkColor(mHdc, RGB(70, 70, 70));//�w�i�F�̎w��
	SetBkMode(mHdc, TRANSPARENT);//�w�i���[�h��ύX
}

DrawEngineWin32::~DrawEngineWin32()
{
	RestoreDC(mHdc, -1);
}

//�EUI�G���A�`��
void DrawEngineWin32::DrawUIRightArea() 
{
	HBRUSH h_brush = CreateSolidBrush(RGB(225, 200, 150));
	
	mRect.top = mHeight;
	mRect.left = mWidth+8;
	mRect.bottom = 0;
	mRect.right = mWidth + 18;

	FillRect(mHdc, &mRect, h_brush);
	DeleteObject(h_brush);
}

//��UI�G���A�`��
void DrawEngineWin32::DrawUILeftArea()
{
	HBRUSH h_brush = CreateSolidBrush(RGB(225, 200, 150));

	mRect.top = mHeight;
	mRect.left = mWidth-18;
	mRect.bottom = 0;
	mRect.right = mWidth;

	FillRect(mHdc, &mRect, h_brush);
	DeleteObject(h_brush);
}

//�e�L�X�g�`��
void DrawEngineWin32::DrawTextOn(TCHAR *text, int pos_x, int pos_y) const
{
	TextOut(mHdc, pos_x, pos_y, text, lstrlen(text));
}

void DrawEngineWin32::DrawTextOnRed(TCHAR* text, int pos_x, int pos_y) const
{
	SetTextColor(mHdc, RGB(255, 0, 0));
	TextOut(mHdc, pos_x, pos_y, text, lstrlen(text));
	SetTextColor(mHdc, RGB(255, 255, 255));
}

//�X�R�A�`��
const void DrawEngineWin32::DrawScore(int inScore, int inPosX, int inPosY)
{
	TCHAR sz_buffer[20];
	int score_board = wsprintf(sz_buffer, TEXT("Score: %6d"), inScore);

	SetBkMode(mHdc, OPAQUE);
	TextOut(mHdc, inPosX, inPosY, sz_buffer, score_board);
	SetBkMode(mHdc, TRANSPARENT);
}

//�X�R�A�`��
const void DrawEngineWin32::DrawLines(int inLines, int inPosX, int inPosY)
{
	TCHAR sz_buffer[20];
	int score_board = wsprintf(sz_buffer, TEXT("Line: %6d"), inLines);

	SetBkMode(mHdc, OPAQUE);
	TextOut(mHdc, inPosX, inPosY, sz_buffer, score_board);
	SetBkMode(mHdc, TRANSPARENT);
}

const void DrawEngineWin32::DrawHiScore(int inHiScore, int inPosX, int inPosY) {
	TCHAR sz_buffer[20];
	int hiscore_board = wsprintf(sz_buffer, TEXT("HiScore: %6d"), inHiScore);

	SetBkMode(mHdc, OPAQUE);
	TextOut(mHdc, inPosX, inPosY, sz_buffer, hiscore_board);
	SetBkMode(mHdc, TRANSPARENT);
}

const void DrawEngineWin32::DrawSpeed(int inSpeed, int x, int y)
{
	TCHAR szBuffer[20];
	int len = wsprintf(szBuffer, TEXT("Game Level: %6d"), inSpeed);
	SetBkMode(mHdc, OPAQUE);
	TextOut(mHdc, x, y + 5, szBuffer, len);
	SetBkMode(mHdc, TRANSPARENT);
}

//�e�g���~�m�`��
void DrawEngineWin32::DrawTetrimino(int pos_x, int pos_y, COLORREF color)
{
	HBRUSH hBrush = CreateSolidBrush(color);
	mRect.left = pos_x;
	mRect.right = pos_x + 1;
	mRect.top = pos_y;
	mRect.bottom = pos_y + 1;

	FillRect(mHdc, &mRect, hBrush);

	MoveToEx(mHdc, pos_x, pos_y + 1, NULL);
	LineTo(mHdc, pos_x, pos_y);
	LineTo(mHdc, pos_x + 1, pos_y);
	DeleteObject(hBrush);
}

//���̃e�g���~�m��`��
void DrawEngineWin32::DrawNextTetrimino(TetriminoWin32& ioTetrimino, int pos_x, int pos_y)
{
	TCHAR szBuffer[] = TEXT("Next:");
	SetTextColor(mHdc, RGB(0, 0, 0));
	TextOut(mHdc, pos_x, pos_y + 5, szBuffer, lstrlen(szBuffer));
	SetTextColor(mHdc, RGB(255, 255, 255));


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
