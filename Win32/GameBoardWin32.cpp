#include "GameBoardWin32.h"


GameBoardWin32::GameBoardWin32(DrawEngineWin32& draw_engine_win32, int game_board_width, int game_board_height) :
    draw_engine_win32(draw_engine_win32), game_board_width(game_board_width), game_board_height(game_board_height)
{
    
    game_board_win32 = new COLORREF * [game_board_width];

    for (int i = 0; i < game_board_width; i++)
    {
        game_board_win32[i] = new COLORREF[game_board_height];
        for (int j = 0; j < game_board_height; j++)
            game_board_win32[i][j] = RGB(0, 0, 0);
    }

    // ‰Šú‰»
    /*current_block_piece->AddTertimino(game_board);
    next_block_piece->AddTertimino(game_board);*/
    
}

GameBoardWin32::~GameBoardWin32()
{
    for (int i = 0; i < game_board_width; i++)
        delete[] game_board_win32[i];
    delete[] game_board_win32;
}

//GameBoard‚Ì•`‰æ–½—ß‚ð‚·‚é
const void GameBoardWin32::DrawGameBoard()
{
    for (int i = 0; i < game_board_width; i++)
        for (int j = 0; j < game_board_height; j++)
            draw_engine_win32.DrawTetrimino(i, j, game_board_win32[i][j]);
}