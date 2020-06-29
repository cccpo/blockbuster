#include "DrawEngineWin32.h"

DrawEngineWin32::DrawEngineWin32(HDC mHdc, HWND mHwnd, int pxPerBlock = 15, int mWidth = 10, int mHeight = 20) :
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
	SetBkColor(mHdc, RGB(70, 70, 70));
	SetBkMode(mHdc, TRANSPARENT);
}

DrawEngineWin32::~DrawEngineWin32()
{
	RestoreDC(mHdc, -1);
}