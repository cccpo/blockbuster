#pragma once

#include "GameBoard.h"
class Value
{
private:

public:
	Value();
	~Value();


	bool IsEmpty(int i);//空であるかを判定する関数
protected:
	GameBoard game_board;
};

