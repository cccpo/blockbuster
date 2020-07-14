#pragma once

#include "DrawEngineWin32.h"

#include "../board/GameBoard.h"
#include "../board/BlockPiece.h"

class GameBoardWin32
{

	public:
	GameBoardWin32(GameBoard& game_board,DrawEngineWin32& draw_engine_win32,
				   int game_board_width = 10, int game_board_height = 20);
	~GameBoardWin32();

	protected:
		COLORREF** game_board_win32;
		DrawEngineWin32& draw_engine_win32;
		BlockPiece* current_block_piece;
		BlockPiece* next_block_piece;
		GameBoard& game_board;


		int game_board_width;
		int game_board_height;
};

