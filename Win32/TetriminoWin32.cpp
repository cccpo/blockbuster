#include "TetriminoWin32.h"

//
//inTetriminoId::テトリミノのID
TetriminoWin32::TetriminoWin32(int inTetriminoId,int inTetriminoRotate, COLORREF inTetriminoColor,
	                 const POINT* inPoint, int inNumOfPoints) :
	mTetriminoId(inTetriminoId), mTetriminoRotation(inTetriminoRotate), mTetriminoPoints(inNumOfPoints),
	color(inTetriminoColor), mTetriminoWidth(0), mTetriminoHeight(0)
{
    POINT bottomLeft = inPoint[0];

    for (int i = 1; i < mTetriminoPoints; i++)
    {
        bottomLeft.x = min(inPoint[i].x, bottomLeft.x);
        bottomLeft.y = min(inPoint[i].y, bottomLeft.y);
    }

    mTetriminoBody = new POINT[mTetriminoPoints];

    for (int i = 0; i < mTetriminoPoints; i++)
    {
        mTetriminoBody[i].x = inPoint[i].x - bottomLeft.x;
        mTetriminoBody[i].y = inPoint[i].y - bottomLeft.y;

        mTetriminoWidth = max((int)mTetriminoBody[i].x + 1, mTetriminoWidth);
        mTetriminoHeight = max((int)mTetriminoBody[i].y + 1, mTetriminoHeight);
    }
}

//破棄
TetriminoWin32::~TetriminoWin32()
{
    if (mTetriminoBody)
        delete[] mTetriminoBody;
}


//Point構造体として構成されたテトリミノを取得する関数
void TetriminoWin32::GetTetriminoBody(POINT* inTetriminoPoints) const
{
    for (int i = 0; i < mTetriminoPoints; i++)
        inTetriminoPoints[i] = mTetriminoBody[i];
}

const int TetriminoWin32::GetMoveDown(POINT* inPoint)
{
    int i = 0;
    for (int x = 0; x < mTetriminoWidth; x++)
    {
        for (int y = 0; y < mTetriminoHeight; y++)
        {
            if (IsPointExists(x, y))
            {
                inPoint[i].x = x;
                inPoint[i].y = y;
                i++;
                break;
            }
        }
    }
    return i;
}

const int TetriminoWin32::GetLeftSide(POINT* inPoint)
{
    int i = 0;
    for (int y = 0; y < mTetriminoHeight; y++)
    {
        for (int x = 0; x < mTetriminoHeight; x++)
        {
            if (IsPointExists(x, y))
            {
                inPoint[i].x = x;
                inPoint[i].y = y;
                i++;
                break;
            }
        }
    }
    return i;
}

const int TetriminoWin32::GetRightSide(POINT* inPoint)
{
    int i = 0;
    for (int y = 0; y < mTetriminoHeight; y++)
    {
        for (int x = mTetriminoWidth - 1; x >= 0; x--)
        {
            if (IsPointExists(x, y))
            {
                inPoint[i].x = x;
                inPoint[i].y = y;
                i++;
                break;
            }
        }
    }
    return i;
}

const bool TetriminoWin32::IsPointExists(int inPosX, int inPosY)
{
    for (int i = 0; i < 4; i++)
    {
        if (mTetriminoBody[i].x == inPosX && mTetriminoBody[i].y == inPosY)
            return true;
    }
    return false;
}