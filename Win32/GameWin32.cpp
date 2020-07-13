#include "GameWin32.h"

#include <iostream>


GameWin32::GameWin32(DrawEngineWin32& ioDrawEngineWin32):
    draw_engine_win32(draw_engine_win32),game_board(game_board),
    block_piece(block_piece),score(score),data(data),
    mIsPaused(false)
{
    GameBoard GameBoard(1, 2);
}

GameWin32::~GameWin32()
{

}

void GameWin32::UpdateTime() 
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


const void GameWin32::Draw() {
    draw_engine_win32.DrawUI();

}


//ゲームオーバー判定
const bool GameWin32::IsGameOver() 
{
    return block_piece.IsOverLaped(game_board);
}

