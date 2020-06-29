#include "DrawEngineWin32.h"

DrawEngineWin32::DrawEngineWin32(HDC mHdc, HWND mHwnd, int pxPerBlock = 15, int mWidth = 10, int mHeight = 20) :
	mHdc(mHdc), mHwnd(mHwnd), mWidth(mWidth), mHeight(mHeight)
{

}