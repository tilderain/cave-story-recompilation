//#include "types.h"
#include "SDL_stdinc.h"
#include "windows_wrapper.h"
#include "Tags.h"

void GetFramePosition(int *fx, int *fy)
{
  *fx = gFrame.x;
  *fy = gFrame.y;
}

void SetFramePosition(int fx, int fy)
{
  __int16 map_l;
  __int16 map_w;

  gFrame.quake = 0;
  gFrame.quake2 = 0;
  GetMapData(0, &map_w, &map_l);
  gFrame.x = fx;
  gFrame.y = fy;
  if ( fx < -511 )
    gFrame.x = 0;
  if ( gFrame.y < -511 )
    gFrame.y = 0;
  if ( gFrame.x > (map_w - 21) << 13 )
    gFrame.x = (map_w - 21) << 13;
  if ( gFrame.y > (map_l - 16) << 13 )
    gFrame.y = (map_l - 16) << 13;
}

void SetFrameMyChar()
{
  __int16 map_l;
  __int16 map_w;
  int mc_y;
  int mc_x;

  GetMyCharPosition(&mc_x, &mc_y);
  GetMapData(0, &map_w, &map_l);
  gFrame.x = mc_x - 81920;
  gFrame.y = mc_y - 61440;
  if ( mc_x - 81920 < -511 )
    gFrame.x = 0;
  if ( gFrame.y < -511 )
    gFrame.y = 0;
  if ( gFrame.x > (map_w - 21) << 13 )
    gFrame.x = (map_w - 21) << 13;
  if ( gFrame.y > (map_l - 16) << 13 )
    gFrame.y = (map_l - 16) << 13;
}

void SetFrameTargetMyChar(int wait)
{
  gFrame.tgt_x = (_DWORD *)&unk_81C85A4;        // TODO: Figure these out
  gFrame.tgt_y = (_DWORD *)&unk_81C85A8;
  gFrame.wait = wait;
}

void SetFrameTargetNpChar(int event, int wait)
{
  int i;

  for ( i = 0; i <= 511 && gNPC[i].code_event != event; ++i )
    ;                                           // TODO: Rework this
  if ( i != 512 )
  {
    gFrame.tgt_x = &gNPC[i].x;
    gFrame.tgt_y = &gNPC[i].y;
    gFrame.wait = wait;
  }
}

void SetFrameTargetBoss(int no, int wait)
{
  gFrame.tgt_x = &gBoss[no].x;
  gFrame.tgt_y = &gBoss[no].y;
  gFrame.wait = wait;
}

void SetQuake(int time)
{
  gFrame.quake = time;
}

void SetQuake2(int time)
{
  gFrame.quake2 = time;
}

void ResetQuake()
{
  gFrame.quake = 0;
  gFrame.quake2 = 0;
}

