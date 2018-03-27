//#include "types.h"
#include "stdint.h"
#include "SDL_stdinc.h"
#include "SDL_video.h"
#include "windows_wrapper.h"

void InitFlash();
void SetFlash(int x, int y, int mode);
void ActFlash_Explosion(int flx, int fly);
void ActFlash_Flash();
void ActFlash(int flx, int fly);
void PutFlash();
void ResetFlash();
void InitFlash()

RECT rect;
RECT stru_81C7A0C;
Uint32 gFlashColor;

$A04024D9D3FA77925171298B9D10BD38 flash;
_UNKNOWN unk_81C79E4;
_UNKNOWN unk_81C79E8;
_UNKNOWN unk_81C79EC;
_UNKNOWN unk_81C79F0;
_UNKNOWN unk_81C79F4;
_UNKNOWN unk_81C79F8;

{
  SDL_Color r;

  RGB(&r, 0xFFu, 0xFFu, 0xFEu);
  gFlashColor = GetCortBoxColor(&r);
}

void SetFlash(int x, int y, int mode)
{
  unk_81C79E4 = 0;
  unk_81C79E8 = 1;
  unk_81C79F4 = x;
  unk_81C79F8 = y;
  flash.mode = mode;
  unk_81C79EC = 0;
  unk_81C79F0 = 0;
}

void ActFlash_Explosion(int flx, int fly)
{
  Sint32 left;
  Sint32 top;
  Sint32 topa;
  Sint32 right;
  Sint32 bottom;
  Sint32 bottoma;

  if ( unk_81C79E4 )
  {
    if ( unk_81C79E4 == 1 )
    {
      unk_81C79F0 -= unk_81C79F0 / 8;
      if ( (unsigned int)(unk_81C79F0 + 255) <= 0x1FE )
        unk_81C79E8 = 0;
      topa = (unk_81C79F8 - fly - unk_81C79F0) / 512;
      if ( topa < 0 )
        topa = 0;
      bottoma = (unk_81C79F8 - fly + unk_81C79F0) / 512;
      if ( bottoma > 240 )
        bottoma = 240;
      rect.left = 0;
      rect.right = 0;
      rect.top = 0;
      rect.bottom = 0;
      stru_81C7A0C.top = topa;
      stru_81C7A0C.bottom = bottoma;
      stru_81C7A0C.left = 0;
      stru_81C7A0C.right = 320;
    }
  }
  else
  {
    unk_81C79EC += 512;
    unk_81C79F0 += unk_81C79EC;
    left = (unk_81C79F4 - flx - unk_81C79F0) / 512;
    top = (unk_81C79F8 - fly - unk_81C79F0) / 512;
    right = (unk_81C79F4 - flx + unk_81C79F0) / 512;
    bottom = (unk_81C79F8 - fly + unk_81C79F0) / 512;
    if ( left < 0 )
      left = 0;
    if ( top < 0 )
      top = 0;
    if ( right > 320 )
      right = 320;
    if ( bottom > 240 )
      bottom = 240;
    rect.left = left;
    rect.right = right;
    rect.top = 0;
    rect.bottom = 240;
    stru_81C7A0C.left = 0;
    stru_81C7A0C.right = 320;
    stru_81C7A0C.top = top;
    stru_81C7A0C.bottom = bottom;
    if ( unk_81C79F0 > 655360 )
    {
      unk_81C79E4 = 1;
      unk_81C79EC = 0;
      unk_81C79F0 = 122880;
    }
  }
}

void ActFlash_Flash()
{
  ++unk_81C79EC;
  rect.left = 0;
  rect.right = 0;
  rect.top = 0;
  rect.bottom = 0;
  if ( unk_81C79EC / 2 & 1 )
  {
    stru_81C7A0C.top = 0;
    stru_81C7A0C.bottom = 240;
    stru_81C7A0C.left = 0;
    stru_81C7A0C.right = 320;
  }
  else
  {
    stru_81C7A0C.left = 0;
    stru_81C7A0C.right = 0;
    stru_81C7A0C.top = 0;
    stru_81C7A0C.bottom = 0;
  }
  if ( unk_81C79EC > 20 )
    unk_81C79E8 = 0;
}

void ActFlash(int flx, int fly)
{
  if ( unk_81C79E8 )
  {
    if ( flash.mode == 1 )
    {
      ActFlash_Explosion(flx, fly);
    }
    else if ( flash.mode == 2 )
    {
      ActFlash_Flash();
    }
  }
}

void PutFlash()
{
  if ( unk_81C79E8 )
  {
    CortBox(&rect, gFlashColor);
    CortBox(&stru_81C7A0C, gFlashColor);
  }
}

void ResetFlash()
{
  unk_81C79E8 = 0;
}

