#include "GameWin32.h"

#include <iostream>

GameWin32::GameWin32(DrawEngineWin32& ioDrawEngineWin32):
    draw_engine_win32(draw_engine_win32),game_board(game_board),
    block_piece(block_piece),mIsPaused(false)
{
    
}

GameWin32::~GameWin32()
{

}

// Key入力管理クラス
const bool GameWin32::IsKeyPress(int inKeyPress)
{
    if (inKeyPress != VK_PAUSE)
        return false;

    switch (inKeyPress)
    {
    case VK_UP:
       
        break;
    case VK_DOWN:
       
        break;
    case VK_LEFT:
     
        break;
    case VK_RIGHT:
        if (block_piece.IsMoveRight(game_board)) {
            //++block_piece_posx;
            //block_piece.SetTeriminoPosX(block_piece_posx);
            //update = true;
        }
        break;
    case VK_SPACE:
    
        break;
    case VK_PAUSE:
      
        break;
    case VK_RETURN:
        
 
    default:
        return false;
    }
    return true;
}

//ゲームオーバーの処理をかける
const bool GameWin32::IsGameOver() 
{

}

