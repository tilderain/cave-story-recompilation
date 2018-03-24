#include "types.h"
#include "SDL_stdinc.h"
#include "windows_wrapper.h"

_UNKNOWN SetValueView(long *,long *,long)::C.21;

void ClearValueView();
void __cdecl SetValueView(int *px, int *py, int value);
void ActValueView();
void __cdecl PutValueView(int flx, int fly);

int gVVIndex;
$BB6E7CC5619195A5A6517E054D903FD5 gVV[16];


void ClearValueView()
{
  memset(gVV, 0, 0x280u);
  gVVIndex = 0;
}

void __cdecl SetValueView(int *px, int *py, int value)
{
  RECT rect[20];
  RECT rcMinus;
  RECT rcPlus;
  int fig[4];
  int dig[4];
  int minus;
  int v;
  int index;
  int i;
  int width;
  int sw;

  for ( i = 0;
        i <= 15
     && (!gVV[i].flag || gVV[i].px != px || (gVV[i].value >= 0 || value >= 0) && (gVV[i].value <= 0 || value <= 0));
        ++i )
  {
    ;
  }
  if ( i == 16 )
  {
    index = gVVIndex++;
    if ( gVVIndex == 16 )
      gVVIndex = 0;
    gVV[index].count = 0;
    gVV[index].offset_y = 0;
    gVV[index].value = value;
  }
  else
  {
    index = i;
    gVV[i].count = 32;
    gVV[index].value += value;
    value = gVV[index].value;
  }
  if ( value >= 0 )
  {
    minus = 0;
  }
  else
  {
    value = -value;
    minus = 1;
  }
  v = value;
  if ( value <= 999 )
  {
    if ( value <= 99 )
    {
      if ( value <= 9 )
        width = 16;
      else
        width = 24;
    }
    else
    {
      width = 32;
    }
  }
  else
  {
    width = 40;
  }
  gVV[index].flag = 1;
  gVV[index].px = px;
  gVV[index].py = py;
  gVV[index].rect.left = 40 - width;
  gVV[index].rect.top = 8 * index;
  gVV[index].rect.right = 40;
  gVV[index].rect.bottom = 8 * (index + 1);
  qmemcpy(rect, &SetValueView(long *,long *,long)::C.21, sizeof(rect));// TODO: This shit's weird, yo
  dig[0] = 1;
  dig[1] = 10;
  dig[2] = 100;
  dig[3] = 1000;
  for ( i = 3; i >= 0; --i )                    // TODO: Split these 'i's
  {
    fig[i] = 0;
    while ( dig[i] <= v )
    {
      v -= dig[i];
      ++fig[i];
    }
  }
  sw = 0;
  rcPlus.left = 32;
  rcPlus.top = 48;
  rcPlus.right = 40;
  rcPlus.bottom = 56;
  rcMinus.left = 40;
  rcMinus.top = 48;
  rcMinus.right = 48;
  rcMinus.bottom = 56;
  CortBox2(&gVV[index].rect, 0, 29);
  if ( minus )
    Surface2Surface(gVV[index].rect.left, gVV[index].rect.top, &rcMinus, 29, 26);
  else
    Surface2Surface(gVV[index].rect.left, gVV[index].rect.top, &rcPlus, 29, 26);
  for ( i = 3; i >= 0; --i )
  {
    if ( sw || !i || fig[i] )
    {
      sw = 1;
      if ( minus )
        fig[i] += 10;
      Surface2Surface(8 * (4 - i), gVV[index].rect.top, &rect[fig[i]], 29, 26);
    }
  }
}

void ActValueView()
{
  int v;

  for ( v = 0; v <= 15; ++v )
  {
    if ( gVV[v].flag )
    {
      if ( ++gVV[v].count <= 31 )
        gVV[v].offset_y -= 256;
      if ( gVV[v].count > 72 )
        ++gVV[v].rect.top;
      if ( gVV[v].count > 80 )
        gVV[v].flag = 0;
    }
  }
}

void __cdecl PutValueView(int flx, int fly)
{
  __int64 v2;
  int v3;
  __int64 v4;
  int v;

  for ( v = 0; v <= 15; ++v )
  {
    if ( gVV[v].flag )
    {
      v2 = *gVV[v].py;
      v3 = ((signed int)((HIDWORD(v2) >> 23) + v2) >> 9) + gVV[v].offset_y / 512 - 4 - fly / 512;// TODO: Probably broken divisions
      v4 = *gVV[v].px;
      PutBitmap3(
        &grcGame,
        ((signed int)((HIDWORD(v4) >> 23) + v4) >> 9) - (gVV[v].rect.right - gVV[v].rect.left) / 2 - flx / 512,
        v3,
        &gVV[v].rect,
        29);
    }
  }
}

