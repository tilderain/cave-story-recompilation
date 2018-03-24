#include "stddef.h"
#include "types.h"
#include "stdint.h"
#include "SDL_stdinc.h"
#include "SDL_video.h"
#include "windows_wrapper.h"
#include "SDL_keysym.h"
#include "SDL_keyboard.h"
#include "SDL_events.h"
#include "Input.h"
#include "Config.h"
#include "language.h"
#include "KeyControl.h"

void PutFramePerSecound();
int __cdecl main(int argc, const char **argv, const char **envp);
void InactiveWindow();
void ActiveWindow();
void JoystickProc();
bool __cdecl SystemTask();

char aUMaxim[9] = "\x93\xB4\x8CA\x95\xA8\x8C";

int gJoystickButtonTable[8];

bool _bActive;

char gModulePath[260];
char gDataPath[260];
bool gbUseJoystick;

const SystemTask::key_mapping_t SystemTask(void)::mapping[15] =
{
  { SDLK_LEFT, 1 },
  { SDLK_RIGHT, 2 },
  { SDLK_UP, 4 },
  { SDLK_DOWN, 8 },
  { SDLK_w, 16 },
  { SDLK_x, 32 },
  { SDLK_z, 64 },
  { SDLK_s, 128 },
  { SDLK_a, 256 },
  { SDLK_LSHIFT, 512 },
  { SDLK_RSHIFT, 512 },
  { SDLK_F1, 1024 },
  { SDLK_F2, 2048 },
  { SDLK_ESCAPE, 32768 },
  { SDLK_q, 4096 }
};

void PutFramePerSecound()
{
  ;
}

int __cdecl main(int argc, const char **argv, const char **envp)
{
  size_t v3;
  int result;
  int v5;
  int v6;
  bool v7;
  SDL_Surface_0 *v8;
  $88CD5C1514A19B01CE178CB8EAE44D15 v9;
  RECT v16;
  int v20;
  int v20_4;
  signed int v20_8;
  int v20_12;
  int v15;
  const char *anonymous1;
  int i;
  int v18;
  int v19;
  int anonymous6;
  _BOOL4 v21;

  memcpy(gModulePath, ".", 2u);
  strcpy(gDataPath, gModulePath);
  v3 = strlen(gDataPath);
  memcpy(&gDataPath[v3], "/data", 6u);
  v15 = 0x100231;
  if ( SDL_Init(0x100231) >= 0 )
  {
    if ( get_language() == 0 )
      anonymous1 = aUMaxim;
    else
      anonymous1 = "Cave Story";
    SDL_WM_SetCaption(anonymous1, anonymous1);
    if ( !LoadConfigData(&v9) )
      DefaultConfigData(&v9);
    if ( v9.attack_button_mode )
    {
      if ( v9.attack_button_mode == 1 )
      {
        gKeyJump = 32;
        gKeyShot = 64;
      }
    }
    else
    {
      gKeyJump = 64;
      gKeyShot = 32;
    }
    if ( v9.ok_button_mode )
    {
      if ( v9.ok_button_mode == 1 )
      {
        gKeyOk = gKeyShot;
        gKeyCancel = gKeyJump;
      }
    }
    else
    {
      gKeyOk = gKeyJump;
      gKeyCancel = gKeyShot;
    }
    if ( v9.move_button_mode )
    {
      if ( v9.move_button_mode == 1 )
      {
        gKeyLeft = 0x10000;
        gKeyUp = 1572864;
        gKeyRight = 0x40000;
        gKeyDown = 0x20000;
      }
    }
    else
    {
      gKeyLeft = 1;
      gKeyUp = 4;
      gKeyRight = 2;
      gKeyDown = 8;
    }
    for ( i = 0; i <= 7; ++i )
    {
      switch ( *(_DWORD *)&v9.proof[4 * (i + 28) + 4] )
      {
        case 1:
          gJoystickButtonTable[i] = gKeyJump;
          break;
        case 2:
          gJoystickButtonTable[i] = gKeyShot;
          break;
        case 3:
          gJoystickButtonTable[i] = gKeyArms;
          break;
        case 4:
          gJoystickButtonTable[i] = gKeyItem;
          break;
        case 5:
          gJoystickButtonTable[i] = gKeyMap;
          break;
        case 6:
          gJoystickButtonTable[i] = gKeyArmsRev;
          break;
        default:
          continue;
      }
    }
    v18 = 2;
    v19 = 0x10000000;
    anonymous6 = 16;
    switch ( v9.display_mode )
    {
      case 0:
        v19 |= 0x80000000;
        break;
      case 1:
        v18 = 1;
        break;
      case 3:
        v19 |= 0x80000000;
        anonymous6 = 24;
        break;
      case 4:
        v19 |= 0x80000000;
        anonymous6 = 32;
        break;
      default:
        break;
    }
    gscreen = (SDL_Surface_0 *)SDL_SetVideoMode(320 * v18, 240 * v18, anonymous6, v19);
    if ( gscreen )
    {
      if ( v19 < 0 )
        SDL_ShowCursor(0);
      StartDirectDraw(gscreen, v18);
      v20 = 0;
      v20_4 = 0;
      v20_8 = 64;
      v20_12 = 8;
      v16.left = 0;
      v16.top = 0;
      v16.right = 320;
      v16.bottom = 240;
      v21 = MakeSurface_File("Loading", 15);
      CortBox(&v16, 0);
      PutBitmap3(&v16, 128, 116, (RECT *)&v20, 15);
      if ( !Flip_SystemTask(gscreen) )
      {
        ErrorLog("Flip_SystemTask exit while loading", 0);
        SDL_Quit(v6);
        result = 1;
      }
      else
      {
        InitDirectSound();
        v7 = v9.bJoystick && InitDirectInput();
        if ( v7 )
        {
          ResetJoystickStatus();
          gbUseJoystick = 1;
        }
        InitTextObject();
        InitTriangleTable();
        Game();
        EndTextObject();
        EndDirectSound();
        v8 = gscreen;
        EndDirectDraw();
        SDL_Quit(v8);
        result = 1;
      }
    }
    else
    {
      ErrorLog("SDL_SetVideoMode failed", anonymous6);
      SDL_Quit(v5);
      result = 0;
    }
  }
  else
  {
    ErrorLog("SDL_Init failed", 0);
    result = -1;
  }
  return result;
}

void InactiveWindow()
{
  if ( _bActive )
  {
    _bActive = 0;
    StopOrganyaMusic();
    SleepNoise();
  }
  PlaySoundObject(7, 0);
}

void ActiveWindow()
{
  if ( _bActive != 1 )
  {
    _bActive = 1;
    StopOrganyaMusic();
    PlayOrganyaMusic();
    ResetNoise();
  }
  PlaySoundObject(7, -1);
}

void JoystickProc()
{
  $CC5B0FEB395DC4593A946B3182F5E0FD status;
  int i;

  if ( !((unsigned __int8)GetJoystickStatus(&status) ^ 1) )
  {
    if ( status.bLeft )
      gKey |= gKeyLeft;
    if ( status.bRight )
      gKey |= gKeyRight;
    if ( status.bUp )
      gKey |= gKeyUp;
    if ( status.bDown )
      gKey |= gKeyDown;
    for ( i = 0; i <= 7; ++i )
    {
      if ( status.bButton[i] )
        gKey |= gJoystickButtonTable[i];
    }
  }
}

bool __cdecl SystemTask()
{
  int key_count;
  SDL_Event_0 event;
  const Uint8 *const keys;
  size_t i;
  const SystemTask::key_mapping_t *const m;

  while ( SDL_PollEvent(&event) != 0 )
  {
    if ( event.type == 12 )
      return 0;
  }
  key_count = 0;
  keys = SDL_GetKeyState(&key_count);
  gKey = 0;
  for ( i = 0; i <= 0xE; ++i )
  {
    m = (const SystemTask::key_mapping_t *const )(8 * i + 0x814C0C0);// TODO: Decode this
    if ( keys[SystemTask(void)::mapping[i].src] )
      gKey |= m->dst;
  }
  if ( gbUseJoystick )
    JoystickProc();
  return 1;
}
