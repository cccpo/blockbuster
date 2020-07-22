#pragma once

#include <windows.h>

class TetriminoWin32
{
public:
	TetriminoWin32(int inTetriminoId,int inTetriminoRotate, COLORREF inTetriminoColor,
			       const POINT* inPoint,int inNumOfPoints=4);
	~TetriminoWin32();

    //Getter
    inline int GetTetriminoWidth() const{return mTetriminoWidth;}
    inline int GetTetriminoHeight() const{return mTetriminoHeight;}
    inline int GetTetriminoNPoints() const {return mTetriminoPoints;}
    inline int GetTetriminoId() const{return mTetriminoId;}
    inline int GetTetriminoRotation() const{return mTetriminoRotation;}
    inline COLORREF GetTetriminoColor() const{return color;}

    void GetTetriminoBody(POINT* inTetriminoPoints) const;

   
    const int GetMoveDown(POINT* inPoint);
    const int GetLeftSide(POINT* inPoint);
    const int GetRightSide(POINT* inPoint);

    const bool IsPointExists(int inPosX, int InPosY);
protected:
    
    POINT* mTetriminoBody;

    int mTetriminoPoints;

    int mTetriminoWidth;
    int mTetriminoHeight;

    int mTetriminoId;
    int mTetriminoRotation;

    COLORREF color;
};

