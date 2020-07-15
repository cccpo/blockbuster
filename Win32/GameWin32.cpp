#include "GameWin32.h"

#include <iostream>


GameWin32::GameWin32(DrawEngineWin32& draw_engine_win32):
    draw_engine_win32(draw_engine_win32),mIsPaused(false)
{
    game_board_win32 = new GameBoardWin32(draw_engine_win32,10,20);

}

GameWin32::~GameWin32()
{

}

void GameWin32::UpdateTime() 
{
    if (mIsPaused)
        return;



    //描画
    game_board_win32->DrawGameBoard();
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
        //if (block_piece.IsMoveRight(game_board)) {
        //    //++block_piece_posx;
        //    //block_piece.SetTeriminoPosX(block_piece_posx);
        //    //update = true;
        //}
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

    game_board_win32->DrawGameBoard();

}


//ゲームオーバー判定
//const bool GameWin32::IsGameOver() 
//{
//    //return block_piece.IsOverLaped(game_board);
//}

