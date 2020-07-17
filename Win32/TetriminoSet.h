#pragma once
#include <random>

#include "TetriminoWin32.h"


class TetriminoSet
{

public:
	enum {
		Rotate_Pattern = 4, Num_Tetriminos = 7
	};

	TetriminoSet();
	~TetriminoSet();

	const TetriminoWin32* GetTetrimino(int id, int rotation = 0);
	const TetriminoWin32* GetRandomTetrimino();


protected:

	TetriminoWin32* tetriminos[Num_Tetriminos][Rotate_Pattern];

	void MakeTetriminoRotateAllPattern();
	void RotateTetrimino(POINT* apt, int inNumPoints = 4);
};