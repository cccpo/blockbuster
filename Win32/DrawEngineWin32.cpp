#include "DrawEngineWin32.h"

DrawEngineWin32::DrawEngineWin32(HDC mHdc, HWND mHwnd, 
								 int pxPerBlock, int mWidth, int mHeight) :
	mHdc(mHdc), mHwnd(mHwnd), mWidth(mWidth), mHeight(mHeight)
{
	//�N���C�A���g�G���A�̃T�C�Y���擾
	GetClientRect(mHwnd, &mRect);

	//�f�o�C�X�R���e�L�X�g�̏�Ԃ�ۑ�
	SaveDC(mHdc);

	SetMapMode(mHdc, MM_ISOTROPIC);	//�}�b�s���O���[�h�̕ύX
	SetViewportExtEx(mHdc, pxPerBlock, pxPerBlock, 0);
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

//UI�`��
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

//�e�L�X�g�`��
 void DrawEngineWin32::DrawText(TCHAR* szText, int x, int y) const
{
	TextOut(mHdc, x, y, szText, lstrlen(szText));
}

//�X�R�A�`��
const void DrawEngineWin32::DrawScore(int mScore, int inPosX, int inPosY)
{
	TCHAR sz_buffer[20];
	int score_board = wsprintf(sz_buffer, TEXT("Score: %6d"), mScore);

	SetBkMode(mHdc, OPAQUE);
	TextOut(mHdc, inPosX, inPosY, sz_buffer, score_board);
	SetBkMode(mHdc, TRANSPARENT);
}

//�e�g���~�m�`��
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