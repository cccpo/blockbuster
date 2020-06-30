#include "DrawEngineWin32.h"

DrawEngineWin32::DrawEngineWin32(HDC mHdc, HWND mHwnd, 
	int pxPerBlock = 15, int mWidth = 10, int mHeight = 20) :
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
	// Draw a gray area at the right
	HBRUSH hBrush = CreateSolidBrush(RGB(70, 70, 70));
	
	mRect.top = mHeight;
	mRect.left = mWidth;
	mRect.bottom = 0;
	mRect.right = mWidth + 8;

	FillRect(mHdc, &mRect, hBrush);
	DeleteObject(hBrush);
}

//�e�L�X�g�`��
void DrawEngineWin32::DrawText(TCHAR* szText, int x, int y) const
{
	TextOut(mHdc, x, y, szText, lstrlen(szText));
}

//�X�R�A�`��
void DrawEngineWin32::DrawScore(int score, int x, int y) const
{
	TCHAR szBuffer[20];
	int len = wsprintf(szBuffer, TEXT("Score: %6d"), score);

	SetBkMode(mHdc, OPAQUE);
	TextOut(mHdc, x, y, szBuffer, len);
	SetBkMode(mHdc, TRANSPARENT);
}
