#include "types.h"
#include "stdint.h"
#include "SDL_stdinc.h"
#include "SDL_video.h"
#include "windows_wrapper.h"
#include "Tags.h"
#include "KeyControl.h"
#include "Escape.h"
void __cdecl WriteMiniMapLine(int line)
{
  RECT rcLevel[4];
  int x;
  unsigned __int8 a;

  rcLevel[0].left = 240;
  rcLevel[0].top = 24;
  rcLevel[0].right = 241;
  rcLevel[0].bottom = 25;
  rcLevel[1].left = 241;
  rcLevel[1].top = 24;
  rcLevel[1].right = 242;
  rcLevel[1].bottom = 25;
  rcLevel[2].left = 242;
  rcLevel[2].top = 24;
  rcLevel[2].right = 243;
  rcLevel[2].bottom = 25;
  rcLevel[3].left = 243;
  rcLevel[3].top = 24;
  rcLevel[3].right = 244;
  rcLevel[3].bottom = 25;
  for ( x = 0; gMap.width > x; ++x )
  {
    a = GetAttribute(x, line);
    if ( a )
    {
      if ( a != 68
        && a != 1
        && a != 64
        && a != -128
        && a != -127
        && a != -126
        && a != -125
        && a != 81
        && a != 82
        && a != 85
        && a != 86
        && a != 2
        && a != 96
        && a != 113
        && a != 114
        && a != 117
        && a != 118
        && a != -96
        && a != -95
        && a != -94
        && a != -93 )
      {
        if ( a != 67
          && a != 99
          && a != 80
          && a != 83
          && a != 84
          && a != 87
          && a != 96
          && a != 112
          && a != 115
          && a != 116
          && a != 119 )
        {
          Surface2Surface(x, line, &rcLevel[3], 9, 26);
        }
        else
        {
          Surface2Surface(x, line, &rcLevel[2], 9, 26);
        }
      }
      else
      {
        Surface2Surface(x, line, &rcLevel[1], 9, 26);
      }
    }
    else
    {
      Surface2Surface(x, line, rcLevel, 9, 26);
    }
  }
}

signed int MiniMapLoop()
{
  signed int v0;
  signed int v2;
  signed int v3;
  RECT my_rect;
  RECT rcMiniMap;
  RECT rcView;
  int f;
  int line;
  int my_x;
  int my_y;
  unsigned __int8 my_wait;

  my_rect.left = 0;
  my_rect.top = 57;
  my_rect.right = 1;
  my_rect.bottom = 58;
  my_x = (x / 512 + 8) / 16;
  my_y = (y / 512 + 8) / 16;
  for ( f = 0; f <= 8; ++f )
  {
    GetTrg();
    if ( gKey & 0x8000 )
    {
      v0 = Call_Escape(gscreen);
      if ( !v0 )
        return 0;
      if ( v0 == 2 )
        return 2;
    }
    PutBitmap4(&grcGame, 0, 0, &grcGame, 10);
    rcView.left = 160 - f * gMap.width / 16;
    rcView.right = f * gMap.width / 16 + 160;
    rcView.top = 120 - f * gMap.length / 16;
    rcView.bottom = f * gMap.length / 16 + 120;
    PutMapName(1);
    CortBox(&rcView, 0);
    PutFramePerSecound();
    if ( !Flip_SystemTask(gscreen) )
      return 0;
  }
  rcMiniMap.left = 0;
  rcMiniMap.right = gMap.width;
  rcMiniMap.top = 0;
  rcMiniMap.bottom = gMap.length;
  rcView.right = --rcView.left + gMap.width + 2;
  rcView.bottom = --rcView.top + gMap.length + 2;
  CortBox2(&rcMiniMap, 0, 9);
  line = 0;
  my_wait = 0;
  while ( 1 )
  {
    GetTrg();
    if ( (gKeyCancel | gKeyOk) & gKeyTrg )
      break;
    if ( gKey & 0x8000 )
    {
      v2 = Call_Escape(gscreen);
      if ( !v2 )
        return 0;
      if ( v2 == 2 )
        return 2;
    }
    PutBitmap4(&grcGame, 0, 0, &grcGame, 10);
    CortBox(&rcView, 0);
    if ( gMap.length > line )
      WriteMiniMapLine(line++);
    if ( gMap.length > line )
      WriteMiniMapLine(line++);
    PutBitmap3(&grcGame, rcView.left + 1, rcView.top + 1, &rcMiniMap, 9);
    PutMapName(1);
    if ( (++my_wait >> 3) & 1 )
      PutBitmap3(&grcGame, my_x + rcView.left + 1, my_y + rcView.top + 1, &my_rect, 26);
    PutFramePerSecound();
    if ( !Flip_SystemTask(gscreen) )
      return 0;
  }
  for ( f = 8; f >= -1; --f )
  {
    GetTrg();
    if ( gKey & 0x8000 )
    {
      v3 = Call_Escape(gscreen);
      if ( !v3 )
        return 0;
      if ( v3 == 2 )
        return 2;
    }
    PutBitmap4(&grcGame, 0, 0, &grcGame, 10);
    rcView.left = 160 - f * gMap.width / 16;
    rcView.right = f * gMap.width / 16 + 160;
    rcView.top = 120 - f * gMap.length / 16;
    rcView.bottom = f * gMap.length / 16 + 120;
    PutMapName(1);
    CortBox(&rcView, 0);
    PutFramePerSecound();
    if ( !Flip_SystemTask(gscreen) )
      return 0;
  }
  return 1;
}

_BOOL4 IsMapping()
{
  return gMapping[gStageNo] != 0;
}

void StartMapping()
{
  memset(gMapping, 0, 0x80u);
}

void __cdecl SetMapping(int a)
{
  gMapping[a] = 1;
}

