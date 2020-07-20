#pragma once

#include <windows.h>

class TetriminoWin32
{
public:
	TetriminoWin32(int inTetriminoId,int inTetriminoRotate, COLORREF inTetriminoColor,
			       const POINT* inPoint,int inNumOfPoints=4);
	~TetriminoWin32();


    const inline int GetTetriminoWidth(){return mTetriminoWidth;}
    const inline int GetTetriminoHeight(){return mTetriminoHeight;}
    const inline int GetTetriminoNPoints() {return mTetriminoPoints;}
    const inline int GetTetriminoId() {return mTetriminoId;}
    const inline int GetTetriminoRotation() {return mTetriminoRotation;}
    const inline COLORREF GetTetriminoColor() {return color;}

    const void GetTetriminoBody(POINT* inTetriminoPoints);

protected:
    
    POINT* mTetriminoBody;

    int mTetriminoPoints;

    int mTetriminoWidth;
    int mTetriminoHeight;

    int mTetriminoId;
    int mTetriminoRotation;

    COLORREF color;
};

