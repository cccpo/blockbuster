#pragma once

#include "DrawEngineWin32.h"


class GameWin32
{

public:
	GameWin32(DrawEngineWin32& ioDrawEngineWin32);
	~GameWin32();

protected:
	DrawEngineWin32 draw_engine_win32;

	bool mIsPaused;
};

