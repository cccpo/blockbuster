#include "TetriminoSet.h"

TetriminoSet::TetriminoSet()
{
    for (int i = 0; i < Num_Tetriminos; i++)
        for (int j = 0; j < Rotate_Pattern; j++)
            tetriminos[i][j] = 0;

    POINT tetrimino_constituion[Rotate_Pattern];

    //
    tetrimino_constituion[0].x = 0;    tetrimino_constituion[0].y = 0;
    tetrimino_constituion[1].x = 0;    tetrimino_constituion[1].y = 1;
    tetrimino_constituion[2].x = 0;    tetrimino_constituion[2].y = 2;
    tetrimino_constituion[3].x = 0;    tetrimino_constituion[3].y = 3;
    tetriminos[0][0] = new TetriminoWin32(0, 0, RGB(255, 0, 0), tetrimino_constituion);

    //
    tetrimino_constituion[0].x = 0;    tetrimino_constituion[0].y = 0;
    tetrimino_constituion[1].x = 1;    tetrimino_constituion[1].y = 0;
    tetrimino_constituion[2].x = 0;    tetrimino_constituion[2].y = 1;
    tetrimino_constituion[3].x = 0;    tetrimino_constituion[3].y = 2;
    tetriminos[1][0] = new TetriminoWin32(1, 0, RGB(230, 130, 24), tetrimino_constituion);

    //
    tetrimino_constituion[0].x = 0;    tetrimino_constituion[0].y = 0;
    tetrimino_constituion[1].x = 1;    tetrimino_constituion[1].y = 0;
    tetrimino_constituion[2].x = 1;    tetrimino_constituion[2].y = 1;
    tetrimino_constituion[3].x = 1;    tetrimino_constituion[3].y = 2;
    tetriminos[2][0] = new TetriminoWin32(2, 0, RGB(255, 255, 0), tetrimino_constituion);

    // 
    tetrimino_constituion[0].x = 0;    tetrimino_constituion[0].y = 0;
    tetrimino_constituion[1].x = 1;    tetrimino_constituion[1].y = 0;
    tetrimino_constituion[2].x = 1;    tetrimino_constituion[2].y = 1;
    tetrimino_constituion[3].x = 2;    tetrimino_constituion[3].y = 1;
    tetriminos[3][0] = new TetriminoWin32(3, 0, RGB(120, 200, 80), tetrimino_constituion);

    // 
    tetrimino_constituion[0].x = 1;    tetrimino_constituion[0].y = 0;
    tetrimino_constituion[1].x = 2;    tetrimino_constituion[1].y = 0;
    tetrimino_constituion[2].x = 0;    tetrimino_constituion[2].y = 1;
    tetrimino_constituion[3].x = 1;    tetrimino_constituion[3].y = 1;
    tetriminos[4][0] = new TetriminoWin32(4, 0, RGB(100, 180, 255), tetrimino_constituion);

    //
    tetrimino_constituion[0].x = 0;    tetrimino_constituion[0].y = 0;
    tetrimino_constituion[1].x = 1;    tetrimino_constituion[1].y = 0;
    tetrimino_constituion[2].x = 0;    tetrimino_constituion[2].y = 1;
    tetrimino_constituion[3].x = 1;    tetrimino_constituion[3].y = 1;
    tetriminos[5][0] = new TetriminoWin32(5, 0, RGB(20, 100, 200), tetrimino_constituion);

    // 
    tetrimino_constituion[0].x = 0;    tetrimino_constituion[0].y = 0;
    tetrimino_constituion[1].x = 1;    tetrimino_constituion[1].y = 0;
    tetrimino_constituion[2].x = 2;    tetrimino_constituion[2].y = 0;
    tetrimino_constituion[3].x = 1;    tetrimino_constituion[3].y = 1;
    tetriminos[6][0] = new TetriminoWin32(6, 0, RGB(220, 180, 255), tetrimino_constituion);

    MakeTetriminoRotateAllPattern();
}

TetriminoSet::~TetriminoSet()
{
    for (int i = 0; i < Num_Tetriminos; i++)
        for (int j = 0; j < Rotate_Pattern; j++)
            if (tetriminos[i][j] != 0)
                delete tetriminos[i][j];
}

const TetriminoWin32* TetriminoSet::GetTetrimino(int inTetriminoId, int inRotation)
{
    if (inTetriminoId >= Num_Tetriminos || inTetriminoId < 0 ||
        inRotation >= Rotate_Pattern || inRotation < 0)
        return NULL;
    return tetriminos[inTetriminoId][inRotation];
}

void TetriminoSet::MakeTetriminoRotateAllPattern()
{
    POINT tetrimino_constituion[Rotate_Pattern];
    for (int i = 0; i < Num_Tetriminos; i++)
    {
        tetriminos[i][0]->GetTetriminoBody(tetrimino_constituion);
        for (int j = 1; j < Rotate_Pattern; j++)
        {
            RotateTetrimino(tetrimino_constituion);
            if (tetriminos[i][j] != 0)
                delete tetriminos[i][j];
            tetriminos[i][j] = new TetriminoWin32(i, j, 
                tetriminos[i][0]->GetTetriminoColor(), tetrimino_constituion);
        }
    }
}

//テトリミノの形状をランダムに取得する
const TetriminoWin32* TetriminoSet::GetRandomTetrimino(){
        return GetTetrimino(rand() % Num_Tetriminos, rand() % Rotate_Pattern);
}

//テトリミノを回転させる
void TetriminoSet::RotateTetrimino(POINT* inPoint, int inNumPoints)
{
    int tmp_pos;

    for (int i = 0; i < inNumPoints; i++)
    {
        tmp_pos = inPoint[i].x;
        inPoint[i].x = -inPoint[i].y;
        inPoint[i].y = tmp_pos;
    }
}