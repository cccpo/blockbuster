#pragma once

#include <windows.h>

class TetriminoWin32
{
public:
	TetriminoWin32(int inTetriminoId,int inTetriminoRotate, COLORREF inTetriminoColor,
			  POINT* inPoint,int inNumOfPoints);
	~TetriminoWin32();
protected:
    
    POINT* mTetriminoBody;

    int mTetriminoPoints;

    int mTetriminoWidth;
    int mTetriminoHeight;

    int mTetriminoId;
    int mTetriminoRotation;

    COLORREF color;
};

