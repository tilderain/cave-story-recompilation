
#include "windows.h"

//lazy includes
#include "sound/org.h"
#include "sound/Organya.h"
#include "graphics/Draw.h"
#include "mychar/MycParam.h"
#include "file/Config.h"
#include "generic.h"
#include "tsc/flags.h"
#include "tsc/TextScr.h"
#include "stage/Map.h"
#include "Game.h"
#include "stage/Frame.h"
#include "arms/bullet.h"
#include "mychar/MyChar.h"
#include "Main.h"

/*void RGB(SDL_Color *retstr, Uint8 r, Uint8 g, Uint8 b);

void RGB(SDL_Color *retstr, Uint8 r, Uint8 g, Uint8 b)
{
  *retstr = 0;                          // TODO: Kill        // TODO: More of a memset 0 of the SDL_Color struct // TODO: Dumb memset
  retstr->unused = -1;
  retstr->r = r;
  retstr->g = g;
  retstr->b = b;
}*/
/*
int __userpurge RGB@<eax>(int r, Uint8 g, Uint8 b, char a4)
{
  int result;

  result = r;
  *(_DWORD *)r = 0;
  *(_BYTE *)(r + 3) = -1;
  *(_BYTE *)r = g;
  *(_BYTE *)(r + 1) = b;
  *(_BYTE *)(r + 2) = a4;
  return result;
}

int __userpurge RGB@<eax>(int r, Uint8 g, Uint8 b, char a4)
{
  int result;

  result = r;
  *(_DWORD *)r = 0;
  *(_BYTE *)(r + 3) = -1;
  *(_BYTE *)r = g;
  *(_BYTE *)(r + 1) = b;
  *(_BYTE *)(r + 2) = a4;
  return result;
}
*/
