#include "GameBoardWin32.h"

GameBoardWin32::GameBoardWin32(GameBoard& game_board,DrawEngineWin32& draw_engine_win32, int game_board_width, int game_board_height) :
    game_board(game_board),draw_engine_win32(draw_engine_win32), game_board_width(game_board_width), game_board_height(game_board_height)
{
	game_board_win32 = new COLORREF * [game_board_width];

    for (int i = 0; i < game_board_width; i++)
    {
        game_board_win32[i] = new COLORREF[game_board_height];
        for (int j = 0; j < game_board_height; j++)
            game_board_win32[i][j] = RGB(0, 0, 0);
    }

    // ‰Šú‰»
    current_block_piece->AddTertimino(game_board);
    next_block_piece->AddTertimino(game_board);
    
}