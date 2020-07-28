#include "GameBoardWin32.h"
#include <ctime>


GameBoardWin32::GameBoardWin32(DrawEngineWin32& draw_engine_win32, int game_board_width, int game_board_height):
    draw_engine_win32(draw_engine_win32), game_board_width(game_board_width), game_board_height(game_board_height),
    mCurrentTime(0.0),mLastTime(0.0),mSpeed(500),mScore(0),mPosX(0),mPosY(0)
{
    srand(time(0));//乱数初期化
    
    game_board_win32 = new COLORREF * [game_board_width];

    for (int i = 0; i < game_board_width; i++)
    {
        game_board_win32[i] = new COLORREF[game_board_height];
        for (int j = 0; j < game_board_height; j++)
            game_board_win32[i][j] = RGB(0, 0, 0);
    }
    
    // 初期化
    current_tetrimino = 0;
    next_tetrimino = tetrimino_set.GetRandomTetrimino();

    mHiScore = data.HiScoreLoad();
    
}

//
GameBoardWin32::~GameBoardWin32()
{
    for (int i = 0; i < game_board_width; i++)
        delete[] game_board_win32[i];
    delete[] game_board_win32;
}

//GameBoardの描画を描画エンジンに行わせる
const void GameBoardWin32::DrawGameBoard()
{
    for (int i = 0; i < game_board_width; i++)
        for (int j = 0; j < game_board_height; j++)
            draw_engine_win32.DrawTetrimino(i+8, j, game_board_win32[i][j]);
}

void GameBoardWin32::UpdateTime()
{
    mCurrentTime = timeGetTime();
    if (mCurrentTime - mLastTime < mSpeed)
        return;

    if (current_tetrimino == NULL || !Move(0, -1))
    {
        int lines = ClearRows();

        mScore += score_manager.AddScoreWin32(lines);
        mSpeed = max(mSpeed - 2 * lines, 100);
        MakeRandomPiece();
        DrawNextTetrimino();
        DrawScore();
        DrawHiScore();
        
    }

    mLastTime = timeGetTime();
}

bool GameBoardWin32::Place(int inPosX, int inPosY, const TetriminoWin32& ioTetrimino)
{
    if (inPosX + ioTetrimino.GetTetriminoWidth()> game_board_width || 
        IsCovered(ioTetrimino, inPosX, inPosY))
        return false;

    mPosX = inPosX;
    mPosY = inPosY;

    POINT point[4];
    ioTetrimino.GetTetriminoBody(point);

    COLORREF color = ioTetrimino.GetTetriminoColor();

    for (int i = 0; i < 4; i++)
    {
        if (inPosY + point[i].y > game_board_height - 1)
            continue;
        game_board_win32[inPosX + point[i].x][inPosY + point[i].y] = color;
    }
    return true;
}

//回転
bool GameBoardWin32::Rotate()
{
    TetriminoWin32* tetrimino = current_tetrimino;

    int disX = max(mPosX + current_tetrimino->GetTetriminoHeight() 
                   - game_board_width, 0);

    int rotation = (current_tetrimino->GetTetriminoRotation() + 1) 
                    % TetriminoSet::Rotate_Pattern;

    Clear(*current_tetrimino);
    current_tetrimino = tetrimino_set.GetTetrimino(current_tetrimino->GetTetriminoId(), rotation);

    if (Place(mPosX - disX, mPosY, *current_tetrimino))
        return true;

    current_tetrimino = tetrimino;
    Place(mPosX, mPosY, *current_tetrimino);
    return false;
}

bool GameBoardWin32::Move(int cxDistance, int cyDistance)
{
    if (mPosX + cxDistance < 0 || mPosY + cyDistance < 0 ||
        mPosX + current_tetrimino->GetTetriminoWidth() + cxDistance > game_board_width)
        return false;
    if (cxDistance < 0 && IsHitLeft())
        return false;
    if (cxDistance > 0 && IsHitRight())
        return false;
    if (cyDistance < 0 && IsHitBottom())
        return false;
    Clear(*current_tetrimino);
    return Place(mPosX + cxDistance, mPosY + cyDistance, *current_tetrimino);
}

void GameBoardWin32::Clear(const TetriminoWin32& ioTetrimino)
{
    POINT point[4];
    ioTetrimino.GetTetriminoBody(point);
    int x, y;
    for (int i = 0; i < 4; i++) {
        x = mPosX + point[i].x;
        y = mPosY + point[i].y;
        if (x > game_board_width - 1 || y > game_board_height - 1)
            continue;
        game_board_win32[mPosX + point[i].x][mPosY + point[i].y] = RGB(0, 0, 0);
    }
}

//ランダムに
void GameBoardWin32::MakeRandomPiece()
{
    current_tetrimino = next_tetrimino;//次のテトリミノを追加
    next_tetrimino = tetrimino_set.GetRandomTetrimino();//ランダムにテトリミノを生成
    Place(3, game_board_height - 1, *current_tetrimino);
}

const bool GameBoardWin32::IsHitBottom()
{
    POINT point[4];
    int n = current_tetrimino->GetMoveDown(point);
    int x, y;
    for (int i = 0; i < n; i++)
    {
        x = mPosX + point[i].x;
        y = mPosY + point[i].y;
        if (y < game_board_height && (y == 0 || game_board_win32[x][y - 1] != RGB(0, 0, 0)))
            return true;
    }
    return false;
}


const bool GameBoardWin32::IsHitLeft()
{
    POINT point[4];
    int n = current_tetrimino->GetLeftSide(point);
    int x, y;
    for (int i = 0; i < n; i++)
    {
        x = mPosX + point[i].x;
        y = mPosY + point[i].y;
        if (y > game_board_height - 1)
            continue;
        if (x == 0 || game_board_win32[x - 1][y] != RGB(0, 0, 0))
            return true;
    }
    return false;
}

const bool GameBoardWin32::IsHitRight()
{
    POINT point[4];
    int n = current_tetrimino->GetRightSide(point);
    int x, y;
    for (int i = 0; i < n; i++)
    {
        x = mPosX + point[i].x;
        y = mPosY + point[i].y;
        if (y > game_board_height - 1)
            continue;
        if (x == game_board_width - 1 || game_board_win32[x + 1][y] != RGB(0, 0, 0))
            return true;
    }
    return false;
}

const bool GameBoardWin32::IsCovered(const TetriminoWin32& ioTetrimino, int x, int y)
{
    POINT point[4];
    ioTetrimino.GetTetriminoBody(point);
    int tmpX, tmpY;
    for (int i = 0; i < 4; i++)
    {
        tmpX = point[i].x + x;
        tmpY = point[i].y + y;
        if (tmpX > game_board_width - 1 || tmpY > game_board_height - 1)
            continue;
        if (game_board_win32[tmpX][tmpY] != RGB(0, 0, 0))
            return true;
    }
    return false;
}

// 揃った行を削除する
int GameBoardWin32::ClearRows()
{
    bool is_complete;
    int rows = 0;

    for (int i = 0; i < game_board_height; i++)
    {
        for (int j = 0; j < game_board_width; j++)
        {
            if (game_board_win32[j][i] == RGB(0, 0, 0))
            {
                is_complete = false;
                break;
            }
            if (j == game_board_width - 1)
                is_complete = true;
        }
        if (is_complete)
        {
            for (int j = 0; j < game_board_width; j++)
                game_board_win32[j][i] = RGB(0, 0, 0);

            for (int k = i; k < game_board_height - 1; k++)
            {
                for (int m = 0; m < game_board_width; m++)
                    game_board_win32[m][k] = game_board_win32[m][k + 1];
            }
            i = -1;
            rows++;
        }
    }
    return rows;
}

//ゲームオーバーであるかを確認する
bool GameBoardWin32::IsGameOver()
{
   
    if (current_tetrimino)
        Clear(*current_tetrimino);

    for (int i = 0; i < game_board_width; i++) {
        if (game_board_win32[i][game_board_height - 1]) {
            if (current_tetrimino)
                Place(mPosX, mPosY, *current_tetrimino);
            return true;
        }
    }

    if (current_tetrimino != 0)
        Place(mPosX, mPosY, *current_tetrimino);
    //if (mScore > HiScore) {
    //    data.HiScoreSave(mScore);//HiScoreを更新
    //    }
    return false;
}

//ハイスコアであるかを確認する
bool GameBoardWin32::IsHiScore() {
    if (mScore > HiScore)
        HiScore = mScore;
        data.HiScoreSave(mScore);
        return true;
 
        return false;
}


//ハイスコアを更新させる
//void GameBoardWin32::CheckHiScore() {
//    if (mScore > HiScore)
//       
//}

//スコアを描画
const void GameBoardWin32::DrawScore()
{
    draw_engine_win32.DrawScore(mScore, game_board_width + 9, 13);
}

//ハイスコアを描画
const void GameBoardWin32::DrawHiScore()
{
    draw_engine_win32.DrawHiScore(mHiScore, game_board_width-8, 18);
}


//次のテトリミノを描画
const void GameBoardWin32::DrawNextTetrimino()
{
    draw_engine_win32.DrawNextTetrimino(*next_tetrimino, game_board_width + 9, 14);
}
