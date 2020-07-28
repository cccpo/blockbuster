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

//�Q�[�������X�^�[�g����
void GameWin32::RestartGame()
{
    delete game_board_win32;
    game_board_win32 = new GameBoardWin32(draw_engine_win32, 10, 20);
    mIsPaused = false;
    PriorityDraw();
}

void GameWin32::UpdateTime() 
{
    if (mIsPaused)
        return;

    if (game_board_win32->IsGameOver()) {
        mIsPaused = true;
        DrawGameOver();
        return;
    }

   
    game_board_win32->UpdateTime();


    //�`��
    game_board_win32->DrawGameBoard();
}

void GameWin32::Pause(bool inPaused) {
   
    if (IsGameOver())
        return;

    mIsPaused = inPaused;
    if(inPaused)
    DrawPause();
}

// Key���͊Ǘ��N���X
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
        RestartGame();
    default:
        return false;
    }
}


const void GameWin32::PriorityDraw()
{
    draw_engine_win32.DrawUIRightArea();
    draw_engine_win32.DrawUILeftArea();

    game_board_win32->DrawGameBoard();
    game_board_win32->DrawNextTetrimino();

}

void GameWin32::DrawGameOver() const
{
    //if(eng)
    TCHAR buffer[] = TEXT("GAME OVER");
    TCHAR buffer_2[] = TEXT("Press the ENTER button to restart");

    draw_engine_win32.DrawTextOnRed(buffer, 11, 10);
    draw_engine_win32.DrawTextOnRed(buffer_2, 9, 9);
}

void GameWin32::DrawPause() const
{
    //if(eng)
    TCHAR buffer[] = TEXT("PAUSE");
    TCHAR buffer_2[] = TEXT("Press the PAUSE button again to continue");

    draw_engine_win32.DrawTextOn(buffer, 12, 10);
    draw_engine_win32.DrawTextOn(buffer_2, 8, 9);
}


//�Q�[���I�[�o�[����
bool GameWin32::IsGameOver() const
{
    return game_board_win32->IsGameOver();
}

