#include "types.h"
#include "stdint.h"
#include "SDL_stdinc.h"
#include "SDL_video.h"

void InitFade();
void SetFadeMask();
void ClearFade();
void __cdecl StartFadeOut(char dir);
void __cdecl StartFadeIn(char dir);
void ProcFade();
void PutFade();
_BOOL4 GetFadeActive();

Uint32 _mask_color;

$EEE7987CBFE674A81758BE97986F1045 gFade;

void InitFade()
{
  SDL_Color_0 r;

  memset(&gFade, 0, 0x268u);
  RGB(&r, 0, 0, 0x20u);
  _mask_color = GetCortBoxColor(&r);
}

void SetFadeMask()
{
  gFade.bMask = 1;
}

void ClearFade()
{
  gFade.bMask = 0;
  gFade.mode = 0;
}

void __cdecl StartFadeOut(char dir)
{
  int x;
  int y;

  gFade.mode = 2;
  gFade.count = 0;
  gFade.dir = dir;
  gFade.bMask = 0;
  for ( y = 0; y <= 14; ++y )
  {
    for ( x = 0; x <= 19; ++x )
    {
      *(_BYTE *)(x + 20 * y + 136086284) = 0;
      *(_BYTE *)(x + 20 * y + 136086584) = 0;
    }
  }
}

void __cdecl StartFadeIn(char dir)
{
  int x;
  int y;

  gFade.mode = 1;
  gFade.count = 0;
  gFade.dir = dir;
  gFade.bMask = 1;
  for ( y = 0; y <= 14; ++y )
  {
    for ( x = 0; x <= 19; ++x )
    {
      *(_BYTE *)(x + 20 * y + 136086284) = 15;
      *(_BYTE *)(x + 20 * y + 136086584) = 0;
    }
  }
}

void ProcFade()
{
  int x;
  int xa;
  int xb;
  int xc;
  int xd;
  int xe;
  int xf;
  int xg;
  int xh;
  int xi;
  int xj;
  int xk;
  int xl;
  int xm;
  int xn;
  int xo;
  int xp;
  int xq;
  int y;
  int ya;
  int yb;
  int yc;
  int yd;
  int ye;
  int yf;
  int yg;
  int yh;
  int yi;
  int yj;
  int yk;
  int yl;
  int ym;
  int yn;
  int yo;
  int yp;
  int yq;

  if ( gFade.mode == 1 )
  {
    gFade.bMask = 0;
    switch ( gFade.dir )
    {
      case 0:
        for ( yi = 0; yi <= 14; ++yi )
        {
          for ( xi = 0; xi <= 19; ++xi )
          {
            if ( 19 - gFade.count == xi )
              *(_BYTE *)(xi + 20 * yi + 136086584) = 1;
          }
        }
        break;
      case 1:
        for ( yk = 0; yk <= 14; ++yk )
        {
          for ( xk = 0; xk <= 19; ++xk )
          {
            if ( 14 - gFade.count == yk )
              *(_BYTE *)(xk + 20 * yk + 136086584) = 1;
          }
        }
        break;
      case 2:
        for ( yj = 0; yj <= 14; ++yj )
        {
          for ( xj = 0; xj <= 19; ++xj )
          {
            if ( gFade.count == xj )
              *(_BYTE *)(xj + 20 * yj + 136086584) = 1;
          }
        }
        break;
      case 3:
        for ( yl = 0; yl <= 14; ++yl )
        {
          for ( xl = 0; xl <= 19; ++xl )
          {
            if ( gFade.count == yl )
              *(_BYTE *)(xl + 20 * yl + 136086584) = 1;
          }
        }
        break;
      case 4:
        for ( ym = 0; ym <= 6; ++ym )
        {
          for ( xm = 0; xm <= 9; ++xm )
          {
            if ( 19 - gFade.count == xm + ym )
              *(_BYTE *)(xm + 20 * ym + 136086584) = 1;
          }
        }
        for ( yn = 0; yn <= 6; ++yn )
        {
          for ( xn = 10; xn <= 19; ++xn )
          {
            if ( 19 - gFade.count == yn + 19 - xn )
              *(_BYTE *)(xn + 20 * yn + 136086584) = 1;
          }
        }
        for ( yo = 7; yo <= 14; ++yo )
        {
          for ( xo = 0; xo <= 9; ++xo )
          {
            if ( 19 - gFade.count == xo + 14 - yo )
              *(_BYTE *)(xo + 20 * yo + 136086584) = 1;
          }
        }
        for ( yp = 7; yp <= 14; ++yp )
        {
          for ( xp = 10; xp <= 19; ++xp )
          {
            if ( 19 - gFade.count == 19 - xp + 14 - yp )
              *(_BYTE *)(xp + 20 * yp + 136086584) = 1;
          }
        }
        break;
      default:
        break;
    }
    for ( yq = 0; yq <= 14; ++yq )
    {
      for ( xq = 0; xq <= 19; ++xq )
      {
        if ( *(_BYTE *)(xq + 20 * yq + 136086284) > 0 && *(_BYTE *)(xq + 20 * yq + 136086584) )
          --*(_BYTE *)(xq + 20 * yq + 136086284);
      }
    }
    if ( ++gFade.count > 36 )
      gFade.mode = 0;
  }
  else if ( gFade.mode == 2 )
  {
    switch ( gFade.dir )
    {
      case 0:
        for ( y = 0; y <= 14; ++y )
        {
          for ( x = 0; x <= 19; ++x )
          {
            if ( 19 - gFade.count == x )
              *(_BYTE *)(x + 20 * y + 136086584) = 1;
          }
        }
        break;
      case 1:
        for ( yb = 0; yb <= 14; ++yb )
        {
          for ( xb = 0; xb <= 19; ++xb )
          {
            if ( 14 - gFade.count == yb )
              *(_BYTE *)(xb + 20 * yb + 136086584) = 1;
          }
        }
        break;
      case 2:
        for ( ya = 0; ya <= 14; ++ya )
        {
          for ( xa = 0; xa <= 19; ++xa )
          {
            if ( gFade.count == xa )
              *(_BYTE *)(xa + 20 * ya + 136086584) = 1;
          }
        }
        break;
      case 3:
        for ( yc = 0; yc <= 14; ++yc )
        {
          for ( xc = 0; xc <= 19; ++xc )
          {
            if ( gFade.count == yc )
              *(_BYTE *)(xc + 20 * yc + 136086584) = 1;
          }
        }
        break;
      case 4:
        for ( yd = 0; yd <= 6; ++yd )
        {
          for ( xd = 0; xd <= 9; ++xd )
          {
            if ( gFade.count == xd + yd )
              *(_BYTE *)(xd + 20 * yd + 136086584) = 1;
          }
        }
        for ( ye = 0; ye <= 6; ++ye )
        {
          for ( xe = 10; xe <= 19; ++xe )
          {
            if ( gFade.count == ye + 19 - xe )
              *(_BYTE *)(xe + 20 * ye + 136086584) = 1;
          }
        }
        for ( yf = 7; yf <= 14; ++yf )
        {
          for ( xf = 0; xf <= 9; ++xf )
          {
            if ( gFade.count == xf + 14 - yf )
              *(_BYTE *)(xf + 20 * yf + 136086584) = 1;
          }
        }
        for ( yg = 7; yg <= 14; ++yg )
        {
          for ( xg = 10; xg <= 19; ++xg )
          {
            if ( gFade.count == 19 - xg + 14 - yg )
              *(_BYTE *)(xg + 20 * yg + 136086584) = 1;
          }
        }
        break;
      default:
        break;
    }
    for ( yh = 0; yh <= 14; ++yh )
    {
      for ( xh = 0; xh <= 19; ++xh )
      {
        if ( *(_BYTE *)(xh + 20 * yh + 136086284) <= 14 && *(_BYTE *)(xh + 20 * yh + 136086584) )
          ++*(_BYTE *)(xh + 20 * yh + 136086284);
      }
    }
    if ( ++gFade.count > 36 )
    {
      gFade.bMask = 1;
      gFade.mode = 0;
    }
  }
}

void PutFade()
{
  RECT rect;
  int x;
  int y;

  rect.top = 0;
  rect.bottom = 16;
  if ( gFade.bMask )
  {
    CortBox(&grcGame, _mask_color);
  }
  else if ( gFade.mode )
  {
    for ( y = 0; y <= 14; ++y )
    {
      for ( x = 0; x <= 19; ++x )
      {
        rect.left = 16 * *(char *)(x + 20 * y + 136086284);
        rect.right = rect.left + 16;
        PutBitmap3(&grcGame, 16 * x, 16 * y, &rect, 6);
      }
    }
  }
}

_BOOL4 GetFadeActive()
{
  return gFade.mode != 0;
}

