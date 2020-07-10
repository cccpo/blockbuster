#include "GameWin32.h"

#include <iostream>

GameWin32::GameWin32(DrawEngineWin32& ioDrawEngineWin32):
    draw_engine_win32(draw_engine_win32), mIsPaused(false)
{
  
}

GameWin32::~GameWin32()
{

}

// Key“ü—ÍŠÇ—ƒNƒ‰ƒX
bool GameWin32::KeyPress(int inKeyPress)
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