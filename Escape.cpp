#include "types.h"
#include "stdint.h"
#include "SDL_stdinc.h"
#include "SDL_video.h"
#include "windows_wrapper.h"
#include "KeyControl.h"
#include "Escape.h"

signed int __cdecl Call_Escape(SDL_Surface_0 *screen);
void MoveFrame3();

signed int __cdecl Call_Escape(SDL_Surface_0 *screen)
{
  RECT rc;

  rc.left = 0;
  rc.top = 128;
  rc.right = 208;
  rc.bottom = 144;
  do
  {
    GetTrg();
    if ( gKeyTrg & 0x8000 )
    {
      gKeyTrg = 0;
      return 0;
    }
    if ( gKeyTrg & 0x400 )
    {
      gKeyTrg = 0;
      return 1;
    }
    if ( gKeyTrg & 0x800 )
    {
      gKeyTrg = 0;
      return 2;
    }
    CortBox(&grcFull, 0);
    PutBitmap3(&grcFull, 56, 112, &rc, 26);
    PutFramePerSecound();
  }
  while ( Flip_SystemTask(screen) );
  gKeyTrg = 0;
  return 0;
}

void MoveFrame3()
{
  int v0;
  int v1;
  int v2;
  int v3;
  __int16 map_l;
  __int16 map_w;

  GetMapData(0, &map_w, &map_l);
  gFrame.x += (*gFrame.tgt_x - 81920 - gFrame.x) / gFrame.wait;
  gFrame.y += (*gFrame.tgt_y - 61440 - gFrame.y) / gFrame.wait;
  if ( gFrame.x < -511 )
    gFrame.x = 0;
  if ( gFrame.y < -511 )
    gFrame.y = 0;
  if ( gFrame.x > (map_w - 21) << 13 )
    gFrame.x = (map_w - 21) << 13;
  if ( gFrame.y > (map_l - 16) << 13 )
    gFrame.y = (map_l - 16) << 13;
  if ( gFrame.quake2 )
  {
    v0 = gFrame.x;
    gFrame.x = v0 + (Random(-5, 5) << 9);
    v1 = gFrame.y;
    gFrame.y = v1 + (Random(-3, 3) << 9);
    --gFrame.quake2;
  }
  else if ( gFrame.quake )
  {
    v2 = gFrame.x;
    gFrame.x = v2 + (Random(-1, 1) << 9);
    v3 = gFrame.y;
    gFrame.y = v3 + (Random(-1, 1) << 9);
    --gFrame.quake;
  }
  if ( gFrame.x < -511 )
    gFrame.x = 0;
  if ( gFrame.y < -511 )
    gFrame.y = 0;
}

