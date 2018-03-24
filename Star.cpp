#include "types.h"
#include "SDL_stdinc.h"
#include "windows_wrapper.h"
#include "Tags.h"
void InitStar()
{
  memset(_star, 0, 0xCCu);
  _star[0].x = x;
  _star[0].y = y;
  _star[1].x = x;
  _star[1].y = y;
  _star[2].x = x;
  _star[2].y = y;
  _star[0].xm = 1024;
  _star[0].ym = -512;
  _star[1].xm = -512;
  _star[1].ym = 1024;
  _star[2].xm = 512;
  _star[2].ym = 512;
}

void ActStar()
{
  int v0;
  int v1;
  int v2;
  int v3;
  int i;

  ++ActStar(void)::_a;
  ActStar(void)::_a %= 3;
  for ( i = 0; i <= 2; ++i )
  {
    if ( i )
    {
      if ( _star[i - 1].x >= _star[i].x )
        v0 = _star[i].xm + 128;
      else
        v0 = _star[i].xm - 128;
      _star[i].xm = v0;
      if ( _star[i - 1].y >= _star[i].y )
        v1 = _star[i].ym + 170;
      else
        v1 = _star[i].ym - 170;
      _star[i].ym = v1;
    }
    else
    {
      if ( x >= _star[0].x )
        v2 = _star[0].xm + 128;
      else
        v2 = _star[0].xm - 128;
      _star[0].xm = v2;
      if ( y >= _star[0].y )
        v3 = _star[0].ym + 170;
      else
        v3 = _star[0].ym - 170;
      _star[0].ym = v3;
    }
    if ( _star[i].xm > 2560 )
      _star[i].xm = 2560;
    if ( _star[i].xm < -2560 )
      _star[i].xm = -2560;
    if ( _star[i].ym > 2560 )
      _star[i].ym = 2560;
    if ( _star[i].ym < -2560 )
      _star[i].ym = -2560;
    if ( _star[i].xm > 2560 )
      _star[i].xm = 2560;
    if ( _star[i].xm < -2560 )
      _star[i].xm = -2560;
    if ( _star[i].ym > 2560 )
      _star[i].ym = 2560;
    if ( _star[i].ym < -2560 )
      _star[i].ym = -2560;
    _star[i].x += _star[i].xm;
    _star[i].y += _star[i].ym;
    if ( unk_81C8616 > i && unk_81C8598 & 0x80 && g_GameFlags & 2 && ActStar(void)::_a == i )
      SetBullet(45, _star[ActStar(void)::_a].x, _star[ActStar(void)::_a].y, 0);
  }
}

void __cdecl PutStar(int fx, int fy)
{
  RECT rc[3];
  int i;

  rc[0].left = 192;
  rc[0].top = 0;
  rc[0].right = 200;
  rc[0].bottom = 8;
  rc[1].left = 192;
  rc[1].top = 8;
  rc[1].right = 200;
  rc[1].bottom = 16;
  rc[2].left = 192;
  rc[2].top = 16;
  rc[2].right = 200;
  rc[2].bottom = 24;
  if ( !(gMC.cond & 2) && unk_81C8598 & 0x80 )
  {
    for ( i = 0; i <= 2; ++i )
    {
      if ( unk_81C8616 > i )
        PutBitmap3(&grcGame, _star[i].x / 512 - fx / 512 - 4, _star[i].y / 512 - fy / 512 - 4, &rc[i], 16);
    }
  }
}

