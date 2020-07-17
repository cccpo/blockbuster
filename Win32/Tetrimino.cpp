#include "Tetrimino.h"

Tetrimino::Tetrimino(int inTetriminoId,int inTetriminoRotate, COLORREF inTetriminoColor,
	                 POINT* inPoint, int inNumOfPoints) :
	id(inTetriminoId), rotation(inTetriminoRotate), nPoints(inNumOfPoints),
	color(inTetriminoColor), width(0), height(0)
{
    POINT bottomLeft = inPoint[0];

    for (int i = 1; i < nPoints; i++)
    {
        bottomLeft.x = min(inPoint[i].x, bottomLeft.x);
        bottomLeft.y = min(inPoint[i].y, bottomLeft.y);
    }

    body = new POINT[nPoints];

    for (int i = 0; i < nPoints; i++)
    {
        body[i].x = inPoint[i].x - bottomLeft.x;
        body[i].y = inPoint[i].y - bottomLeft.y;

        width = max((int)body[i].x + 1, width);
        height = max((int)body[i].y + 1, height);
    }
}