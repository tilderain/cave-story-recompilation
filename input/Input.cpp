//#include "types.h"
#include "stdint.h"
#include "SDL_stdinc.h"
#include "SDL_joystick.h"
#include "Input.h"

void ReleaseDirectInput();
bool InitDirectInput();
signed int GetJoystickStatus($CC5B0FEB395DC4593A946B3182F5E0FD *pStatus);
signed int ResetJoystickStatus();

void ReleaseDirectInput()
{
  if ( joystick )
  {
    SDL_JoystickClose(joystick);
    joystick = 0;
  }
}


bool InitDirectInput()
{
  if ( SDL_NumJoysticks() > 0 )
    joystick = (SDL_Joystick *)SDL_JoystickOpen(0);
  return 1;
}



signed int GetJoystickStatus($CC5B0FEB395DC4593A946B3182F5E0FD *pStatus)
{
  Sint16 x;
  __int16 v2;
  int v3;
  int button_count;
  int button;

  memset(pStatus, 0, 0x24u);
  if ( joystick )
  {
    x = SDL_JoystickGetAxis(joystick, 0);
    v2 = SDL_JoystickGetAxis(joystick, 1);
    pStatus->bLeft = x < -8191;
    pStatus->bRight = x > 0x1FFF;
    pStatus->bUp = v2 < -8191;
    pStatus->bDown = v2 > 0x1FFF;
    v3 = SDL_JoystickNumButtons(joystick);
    if ( v3 > 32 )
      v3 = 32;
    button_count = v3;
    for ( button = 0; button < button_count; ++button )
      pStatus->bButton[button] = (unsigned __int8)SDL_JoystickGetButton(joystick, button) != 0;
  }
  return 1;
}




signed int ResetJoystickStatus()
{
  return 1;
}

