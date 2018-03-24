#include "stddef.h"
#include "types.h"
#include "types.h"
#include "stdio.h"
#include "libio.h"
#include "stdint.h"
#include "SDL_stdinc.h"
#include "SDL_rwops.h"
#include "SDL_video.h"
#include "Escape.h"
#include "KeyControl.h"
void ActionStripper()
{
  int s;

  for ( s = 0; s <= 15; ++s )
  {
    if ( Strip[s].flag & 0x80 && Credit.mode )
      Strip[s].y -= 256;
    if ( Strip[s].y < -8191 )
      Strip[s].flag = 0;
  }
}

void PutStripper()
{
  RECT rc;
  int s;

  for ( s = 0; s <= 15; ++s )
  {
    if ( Strip[s].flag & 0x80 )
    {
      rc.left = 0;
      rc.right = 320;
      rc.top = 16 * s;
      rc.bottom = 16 * s + 16;
      PutBitmap3(&grcFull, Strip[s].x / 512, Strip[s].y / 512, &rc, 35);
      rc.left = 24 * (Strip[s].cast % 13);
      rc.right = rc.left + 24;
      rc.top = 24 * (Strip[s].cast / 13);
      rc.bottom = rc.top + 24;
      PutBitmap3(&grcFull, Strip[s].x / 512 - 24, Strip[s].y / 512 - 8, &rc, 37);
    }
  }
}

void __cdecl SetStripper(int x, int y, char *text, int cast)
{
  RECT rc;
  SDL_Color_0 r;
  int s;

  for ( s = 0; s <= 15 && Strip[s].flag & 0x80; ++s )
    ;
  if ( s != 16 )
  {
    Strip[s].flag = 128;
    Strip[s].x = x;
    Strip[s].y = y;
    Strip[s].cast = cast;
    strcpy((char *)Strip + 16 * (5 * s + 1), text);
    rc.left = 0;
    rc.right = 320;
    rc.top = 16 * s;
    rc.bottom = 16 * s + 16;
    CortBox2(&rc, 0, 35);
    RGB(&r, 0xFFu, 0xFFu, 0xFEu);
    PutText2(0, rc.top, text, &r, 35);
  }
}

void RestoreStripper()
{
  RECT rc;
  SDL_Color_0 r;
  int s;

  for ( s = 0; s <= 15; ++s )
  {
    if ( Strip[s].flag & 0x80 )
    {
      rc.left = 0;
      rc.right = 320;
      rc.top = 16 * s;
      rc.bottom = 16 * s + 16;
      CortBox2(&rc, 0, 35);
      RGB(&r, 0xFFu, 0xFFu, 0xFEu);
      PutText2(0, rc.top, (const char *)Strip + 16 * (5 * s + 1), &r, 35);// TODO: Actually Strip[s].str
    }
  }
}

void ActionIllust()
{
  switch ( Illust.act_no )
  {
    case 1:
      Illust.x += 20480;
      if ( Illust.x > 0 )
        Illust.x = 0;
      break;
    case 2:
      Illust.x -= 20480;
      if ( Illust.x < -81920 )
        Illust.x = -81920;
      break;
    case 0:
      Illust.x = -81920;
      break;
  }
}

void PutIllust()
{
  RECT rcIllust;

  rcIllust.left = 0;
  rcIllust.top = 0;
  rcIllust.right = 160;
  rcIllust.bottom = 240;
  PutBitmap3(&grcFull, Illust.x / 512, 0, &rcIllust, 36);
}

void __cdecl ReloadIllust(int a)
{
  char name[16];

  sprintf(name, "Credit%02ld", a);
  ReloadBitmap_Resource(name, 36);
}

void InitCreditScript()
{
  memset(&Credit, 0, 0x18u);
  memset(Strip, 0, 0x500u);
}

void ReleaseCreditScript()
{
  if ( Credit.pData )
  {
    free(Credit.pData);
    Credit.pData = 0;
  }
}

signed int StartCreditScript()
{
  signed int result;
  char path[260];
  SDL_RWops_0 *fp;

  if ( Credit.pData )
  {
    free(Credit.pData);
    Credit.pData = 0;
  }
  sprintf(path, "%s/%s", gDataPath, _credit_script);
  Credit.size = GetFileSizeLong(path);
  if ( Credit.size == -1 )
    return 0;
  Credit.pData = (char *)malloc(Credit.size);
  if ( !Credit.pData )
    return 0;
  fp = SDL_RWFromFile(path, "rb");
  if ( fp )
  {
    fp->read(fp, Credit.pData, 1, Credit.size);
    EncryptionBinaryData2((unsigned __int8 *)Credit.pData, Credit.size);
    Credit.offset = 0;
    Credit.wait = 0;
    Credit.mode = 1;
    Illust.x = -81920;
    Illust.act_no = 0;
    grcGame.left = 160;
    if ( !ReloadBitmap_File("casts", 37) )
    {
      result = 0;
    }
    else
    {
      memset(Strip, 0, 0x500u);
      result = 1;
    }
  }
  else
  {
    free(Credit.pData);
    fprintf(stderr, "Couldn't load %s!", path);
    result = 0;
  }
  return result;
}

int __cdecl _GetScriptNumber(char *text)
{
  return 1000 * *text - 48000 + 100 * text[1] - 4800 + 10 * text[2] - 480 + text[3] - 48;
}

void _ActionCredit_Read()
{
  signed int v0;
  char text[40];
  int a;
  int b;
  int len;

  while ( Credit.offset < Credit.size )
  {
    v0 = Credit.pData[Credit.offset];
    if ( v0 == 91 )
    {
      a = ++Credit.offset;
      while ( Credit.pData[a] != 93 )
      {
        if ( IsShiftJIS(Credit.pData[a]) )
          a += 2;
        else
          ++a;
      }
      len = a - Credit.offset;
      memcpy(text, &Credit.pData[Credit.offset], a - Credit.offset);
      text[len] = 0;
      Credit.offset = a + 1;
      len = _GetScriptNumber(&Credit.pData[a + 1]);
      SetStripper(Credit.start_x, 126976, text, len);
      Credit.offset += 4;
      return;
    }
    if ( v0 > 91 )
    {
      switch ( v0 )
      {
        case 106:
          b = _GetScriptNumber(&Credit.pData[++Credit.offset]);
          Credit.offset += 4;
          while ( Credit.offset < Credit.size )
          {
            if ( Credit.pData[Credit.offset] == 108 )
            {
              a = _GetScriptNumber(&Credit.pData[++Credit.offset]);
              Credit.offset += 4;
              if ( b == a )
                return;
            }
            else if ( IsShiftJIS(Credit.pData[Credit.offset]) )
            {
              Credit.offset += 2;
            }
            else
            {
              ++Credit.offset;
            }
          }
          return;
        case 126:
          ++Credit.offset;
          SetOrganyaFadeout();
          return;
        case 102:
          a = _GetScriptNumber(&Credit.pData[++Credit.offset]);
          Credit.offset += 5;
          b = _GetScriptNumber(&Credit.pData[Credit.offset]);
          Credit.offset += 4;
          if ( (unsigned __int8)GetNPCFlag(a) )
          {
            while ( Credit.offset < Credit.size )
            {
              if ( Credit.pData[Credit.offset] == 108 )
              {
                a = _GetScriptNumber(&Credit.pData[++Credit.offset]);
                Credit.offset += 4;
                if ( b == a )
                  return;
              }
              else if ( IsShiftJIS(Credit.pData[Credit.offset]) )
              {
                Credit.offset += 2;
              }
              else
              {
                ++Credit.offset;
              }
            }
          }
          return;
      }
    }
    else
    {
      if ( v0 == 43 )
      {
        Credit.start_x = _GetScriptNumber(&Credit.pData[++Credit.offset]) << 9;
        Credit.offset += 4;
        return;
      }
      if ( v0 > 43 )
      {
        if ( v0 == 45 )
        {
          Credit.wait = _GetScriptNumber(&Credit.pData[++Credit.offset]);
          Credit.offset += 4;
          Credit.mode = 2;
          return;
        }
        if ( v0 == 47 )
        {
          Credit.mode = 0;
          return;
        }
      }
      else if ( v0 == 33 )
      {
        a = _GetScriptNumber(&Credit.pData[++Credit.offset]);
        Credit.offset += 4;
        ChangeMusic(a);
        return;
      }
    }
    ++Credit.offset;
  }
}

void ActionCredit()
{
  if ( Credit.offset < Credit.size )
  {
    if ( Credit.mode == 1 )
    {
      _ActionCredit_Read();
    }
    else if ( Credit.mode == 2 && --Credit.wait <= 0 )
    {
      Credit.mode = 1;
    }
  }
}

void __cdecl SetCreditIllust(int a)
{
  ReloadIllust(a);
  Illust.act_no = 1;
}

void CutCreditIllust()
{
  Illust.act_no = 2;
}

signed int __cdecl Scene_DownIsland(SDL_Surface_0 *screen, int mode)
{
  signed int v2;
  RECT rc_sprite;
  RECT rc_ground;
  RECT rc_sky;
  RECT rc_frame;
  $0FBB943D0F44CD4E1A64E57ECDAAF024 sprite;
  int wait;

  rc_frame.left = 80;
  rc_frame.top = 80;
  rc_frame.right = 240;
  rc_frame.bottom = 160;
  rc_sky.left = 0;
  rc_sky.top = 0;
  rc_sky.right = 160;
  rc_sky.bottom = 80;
  rc_ground.left = 160;
  rc_ground.top = 48;
  rc_ground.right = 320;
  rc_ground.bottom = 80;
  rc_sprite.left = 160;
  rc_sprite.top = 0;
  rc_sprite.right = 200;
  rc_sprite.bottom = 24;
  sprite.x = 86016;
  sprite.y = 0x8000;
  for ( wait = 0; wait <= 899; ++wait )
  {
    GetTrg();
    if ( gKey & 0x8000 )
    {
      v2 = Call_Escape(screen);
      if ( !v2 )
        return 0;
      if ( v2 == 2 )
        return 2;
    }
    if ( mode )
    {
      if ( mode == 1 )
      {
        if ( wait > 349 )
        {
          if ( wait > 499 )
          {
            if ( wait > 599 )
            {
              if ( wait == 750 )
                wait = 900;
            }
            else
            {
              sprite.y += 12;
            }
          }
          else
          {
            sprite.y += 25;
          }
        }
        else
        {
          sprite.y += 51;
        }
      }
    }
    else
    {
      sprite.y += 51;
    }
    CortBox(&grcFull, 0);
    PutBitmap3(&rc_frame, 80, 80, &rc_sky, 21);
    PutBitmap3(&rc_frame, sprite.x / 512 - 20, sprite.y / 512 - 12, &rc_sprite, 21);
    PutBitmap3(&rc_frame, 80, 128, &rc_ground, 21);
    PutTimeCounter(16, 8);
    PutFramePerSecound();
    if ( !Flip_SystemTask(screen) )
      return 0;
  }
  return 1;
}

