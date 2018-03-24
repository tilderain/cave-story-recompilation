#include "types.h"
#include "stdint.h"
#include "SDL_stdinc.h"
#include "SDL_video.h"
#include "language.h"
#include "huuuu"
void __cdecl ReadyMapName(unsigned __int8 *str)
{
  unsigned __int8 name_en[22];
  unsigned __int8 name_jp[24];
  Uint8 r;
  Uint8 v4;
  int a;

  gMapName.flag = 0;
  gMapName.wait = 0;
  if ( !strcmp((const char *)str, "u") )
  {
    if ( get_language() == 0 )
    {
      name_jp[0] = -119;
      name_jp[1] = 73;
      name_jp[2] = -109;
      name_jp[3] = -84;
      name_jp[4] = -115;
      name_jp[5] = -71;
      name_jp[6] = 79;
      name_jp[7] = 104;
      name_jp[8] = 119;
      name_jp[9] = 100;
      name_jp[10] = 107;
      name_jp[11] = 31;
      name_jp[12] = 111;
      name_jp[13] = 113;
      name_jp[14] = 100;
      name_jp[15] = 114;
      name_jp[16] = 100;
      name_jp[17] = 109;
      name_jp[18] = 115;
      name_jp[19] = 114;
      name_jp[20] = -1;
      name_jp[21] = 0;
      name_jp[22] = 0;
      name_jp[23] = 0;
      for ( a = 0; a <= 23; ++a )
        ++name_jp[a];
      str = name_jp;
    }
    else
    {
      strcpy((char *)name_en, "Studio Pixel presents");
      str = name_en;
    }
  }
  strcpy(gMapName.name, (const char *)str);
  a = strlen(gMapName.name);
  CortBox2(&_rc, 0, 13);
  RGB((int)&r, 0x11u, 0, 34);
  PutText2((-6 * a + 160) / 2 + 6, 1, gMapName.name, (const SDL_Color_0 *const )&r, 13);
  RGB((int)&v4, 0xFFu, 0xFFu, 254);
  PutText2((-6 * a + 160) / 2 + 6, 0, gMapName.name, (const SDL_Color_0 *const )&v4, 13);
}

void __cdecl PutMapName(bool bMini)
{
  RECT rcBack;

  if ( bMini )
  {
    rcBack.left = 0;
    rcBack.right = 320;
    rcBack.top = 7;
    rcBack.bottom = 24;
    CortBox(&rcBack, 0);
    PutBitmap3(&grcGame, 74, 10, &_rc, 13);
  }
  else if ( gMapName.flag )
  {
    PutBitmap3(&grcGame, 74, 80, &_rc, 13);
    if ( ++gMapName.wait > 160 )
      gMapName.flag = 0;
  }
}

void StartMapName()
{
  gMapName.flag = 1;
  gMapName.wait = 0;
}

void RestoreMapName()
{
  Uint8 r;
  Uint8 v1;
  int a;

  a = strlen(gMapName.name);
  CortBox2(&_rc, 0, 13);
  RGB((int)&r, 0x11u, 0, 34);
  PutText2((-6 * a + 160) / 2 + 6, 1, gMapName.name, (const SDL_Color_0 *const )&r, 13);
  RGB((int)&v1, 0xFFu, 0xFFu, 254);
  PutText2((-6 * a + 160) / 2 + 6, 0, gMapName.name, (const SDL_Color_0 *const )&v1, 13);
}

