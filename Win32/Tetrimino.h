#pragma once

#include <windows.h>

class Tetrimino
{
public:
	Tetrimino(int inTetriminoId,int inTetriminoRotate, COLORREF inTetriminoColor,
			  POINT* inPoint,int inNumOfPoints);
	~Tetrimino();
protected:
    
    POINT* mTetriminoBody;

    int mTetriminoPoints;

    int mTetriminoWidth;
    int mTetriminoHeight;

    int mTetriminoId;
    int mTetriminoRotation;

    COLORREF color;
};

