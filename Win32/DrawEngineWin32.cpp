#include "DrawEngineWin32.h"

DrawEngineWin32::DrawEngineWin32(HDC mHdc, HWND mHwnd, int pxPerBlock = 15, int mWidth = 10, int mHeight = 20) :
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
	SetBkColor(mHdc, RGB(70, 70, 70));
	SetBkMode(mHdc, TRANSPARENT);
}

DrawEngineWin32::~DrawEngineWin32()
{
	RestoreDC(mHdc, -1);
}