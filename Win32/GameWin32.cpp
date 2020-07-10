#include "GameWin32.h"

#include <iostream>

GameWin32::GameWin32(DrawEngineWin32& ioDrawEngineWin32):
    draw_engine_win32(draw_engine_win32), mIsPaused(false)
{
  
}

GameWin32::~GameWin32()
{

}