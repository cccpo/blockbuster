#pragma once

#include "GameBoard.h"
class Value
{
private:

public:
	Value();
	~Value();


	bool IsEmpty(int i);//��ł��邩�𔻒肷��֐�
protected:
	GameBoard game_board;
};

