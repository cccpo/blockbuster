#include "GameWin32.h"

#include <iostream>


GameWin32::GameWin32(DrawEngineWin32& draw_engine_win32):
    draw_engine_win32(draw_engine_win32),mIsPaused(false)
{
    game_board_win32 = new GameBoardWin32(draw_engine_win32,10,20);

}

GameWin32::~GameWin32()
{
    delete game_board_win32;
}

void GameWin32::UpdateTime() 
{
    if (mIsPaused)
        return;

    if (game_board_win32->IsGameOver()) {
        mIsPaused = true;
      
        return;
    }

   
    game_board_win32->UpdateTime();


    //描画
    game_board_win32->DrawGameBoard();
}

void GameWin32::Pause(bool paused) {
   
    if (IsGameOver())
        return;

    mIsPaused = paused;
}

// Key入力管理クラス
bool GameWin32::IsKeyPress(int inKeyPress)
{
    if (inKeyPress != VK_PAUSE && inKeyPress != VK_RETURN && mIsPaused)
        return false;

    switch (inKeyPress)
    {
    case VK_UP:
        game_board_win32->Rotate();
        break;
    case VK_DOWN:
        game_board_win32->Move(0, -1);
        break;
    case VK_LEFT:
        game_board_win32->Move(-1, 0);
        break;
    case VK_RIGHT:
        game_board_win32->Move(1, 0);
        break;
    case VK_SPACE:
        game_board_win32->Rotate();
        break;
    case VK_PAUSE:
        Pause(!mIsPaused);
        break;
    case VK_RETURN:
        if (game_board_win32->IsGameOver())
            /*      restart();*/
    default:
        return false;
        return true;
    }
}


void GameWin32::Draw() const
{
    draw_engine_win32.DrawUI();

    game_board_win32->DrawGameBoard();

}


//ゲームオーバー判定
bool GameWin32::IsGameOver() const
{
    return game_board_win32->IsGameOver();
}

