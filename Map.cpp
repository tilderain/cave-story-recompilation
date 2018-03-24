#include "stddef.h"
#include "types.h"
#include "types.h"
#include "stdio.h"
#include "libio.h"
#include "stdint.h"
#include "SDL_stdinc.h"
#include "SDL_rwops.h"
#include "windows_wrapper.h"
#include "Tags.h"
signed int InitMapData2()
{
  gMap.data = (unsigned __int8 *)malloc(0x4B000u);
  return 1;
}

signed int __cdecl LoadMapData2(char *path_map)
{
  signed int result;
  char path[260];
  unsigned __int8 dum;
  char check[3];
  SDL_RWops_0 *fp;

  sprintf(path, "%s/%s", gDataPath, path_map);
  fp = SDL_RWFromFile(path, "rb");
  if ( !fp )
    return 0;
  fp->read(fp, check, 1, 3);
  if ( !memcmp(check, "PXM", 3u) )
  {
    fp->read(fp, &dum, 1, 1);
    gMap.width = SDL_ReadLE16(fp);
    gMap.length = SDL_ReadLE16(fp);
    if ( gMap.data )
    {
      fp->read(fp, gMap.data, 1, gMap.length * gMap.width);
      fp->close(fp);
      result = 1;
    }
    else
    {
      fp->close(fp);
      result = 0;
    }
  }
  else
  {
    fp->close(fp);
    result = 0;
  }
  return result;
}


signed int __cdecl LoadAttributeData(char *path_atrb)
{
  char path[260];
  SDL_RWops_0 *fp;

  sprintf(path, "%s/%s", gDataPath, path_atrb);
  fp = SDL_RWFromFile(path, "rb");
  if ( !fp )
    return 0;
  fp->read(fp, &gMap + 4, 1, 256);
  fp->close(fp);
  return 1;
}

void EndMapData()
{
  free(gMap.data);
}

void ReleasePartsImage()
{
  ReleaseSurface(2);
}

void __cdecl GetMapData(unsigned __int8 **data, __int16 *mw, __int16 *ml)
{
  if ( data )
    *data = gMap.data;
  if ( mw )
    *mw = gMap.width;
  if ( ml )
    *ml = gMap.length;
}

int __cdecl GetAttribute(int x, int y)
{
  int result;

  if ( x >= 0 && y >= 0 && gMap.width > x && gMap.length > y )
    result = gMap.atrb[gMap.data[y * gMap.width + x]];
  else
    result = 0;
  return result;
}

void __cdecl DeleteMapParts(int x, int y)
{
  gMap.data[y * gMap.width + x] = 0;
}

void __cdecl ShiftMapParts(int x, int y)
{
  --gMap.data[y * gMap.width + x];
}

signed int __cdecl ChangeMapParts(int x, int y, unsigned __int8 no)
{
  int i;

  if ( gMap.data[y * gMap.width + x] == no )
    return 0;
  gMap.data[y * gMap.width + x] = no;
  for ( i = 0; i <= 2; ++i )
    SetNpChar(4, x << 13, y << 13, 0, 0, 0, 0, 0);
  return 1;
}

void __cdecl PutStage_Back(int fx, int fy)
{
  RECT rect;
  int i;
  int j;
  int offset;
  int num_x;
  int num_y;
  int put_x;
  int put_y;
  int atrb;

  num_x = 21;
  num_y = 16;
  put_x = (fx / 512 + 8) / 16;
  put_y = (fy / 512 + 8) / 16;
  for ( j = (fy / 512 + 8) / 16; put_y + num_y > j; ++j )
  {
    for ( i = put_x; put_x + num_x > i; ++i )
    {
      offset = i + j * gMap.width;
      atrb = (unsigned __int8)GetAttribute(i, j);
      if ( atrb <= 31 )
      {
        rect.left = 16 * (gMap.data[offset] & 0xF);
        rect.top = 16 * (gMap.data[offset] >> 4);
        rect.right = rect.left + 16;
        rect.bottom = rect.top + 16;
        PutBitmap3(&grcGame, 8 * (2 * i - 1) - fx / 512, 8 * (2 * j - 1) - fy / 512, &rect, 2);
      }
    }
  }
}

void __cdecl PutStage_Front(int fx, int fy)
{
  RECT rect;
  RECT rcSnack;
  int i;
  int j;
  int offset;
  int num_x;
  int num_y;
  int put_x;
  int put_y;
  int atrb;

  rcSnack.left = 256;
  rcSnack.top = 48;
  rcSnack.right = 272;
  rcSnack.bottom = 64;
  num_x = 21;
  num_y = 16;
  put_x = (fx / 512 + 8) / 16;
  put_y = (fy / 512 + 8) / 16;
  for ( j = (fy / 512 + 8) / 16; put_y + num_y > j; ++j )
  {
    for ( i = put_x; put_x + num_x > i; ++i )
    {
      offset = i + j * gMap.width;
      atrb = (unsigned __int8)GetAttribute(i, j);
      if ( atrb > 63 && atrb <= 127 )
      {
        rect.left = 16 * (gMap.data[offset] & 0xF);
        rect.top = 16 * (gMap.data[offset] >> 4);
        rect.right = rect.left + 16;
        rect.bottom = rect.top + 16;
        PutBitmap3(&grcGame, 8 * (2 * i - 1) - fx / 512, 8 * (2 * j - 1) - fy / 512, &rect, 2);
        if ( atrb == 67 )
          PutBitmap3(&grcGame, 8 * (2 * i - 1) - fx / 512, 8 * (2 * j - 1) - fy / 512, &rcSnack, 20);
      }
    }
  }
}

void __cdecl PutMapDataVector(int fx, int fy)
{
  RECT rect;
  int i;
  int j;
  int offset;
  int num_x;
  int num_y;
  int put_x;
  int put_y;
  int atrb;

  PutMapDataVector(long,long)::count += 2;
  num_x = 21;
  num_y = 16;
  put_x = (fx / 512 + 8) / 16;
  put_y = (fy / 512 + 8) / 16;
  for ( j = (fy / 512 + 8) / 16; put_y + num_y > j; ++j )
  {
    for ( i = put_x; put_x + num_x > i; ++i )
    {
      offset = i + j * gMap.width;
      atrb = (unsigned __int8)GetAttribute(i, j);
      if ( atrb == 128
        || atrb == 129
        || atrb == 130
        || atrb == 131
        || atrb == 160
        || atrb == 161
        || atrb == 162
        || atrb == 163 )
      {
        switch ( atrb )
        {
          case 128:
          case 160:
            rect.left = (PutMapDataVector(long,long)::count & 0xF) + 224;
            rect.right = (PutMapDataVector(long,long)::count & 0xF) + 240;
            rect.top = 48;
            rect.bottom = 64;
            break;
          case 129:
          case 161:
            rect.left = 224;
            rect.right = 240;
            rect.top = (PutMapDataVector(long,long)::count & 0xF) + 48;
            rect.bottom = (PutMapDataVector(long,long)::count & 0xF) + 64;
            break;
          case 130:
          case 162:
            rect.left = 240 - (PutMapDataVector(long,long)::count & 0xF);
            rect.right = rect.left + 16;
            rect.top = 48;
            rect.bottom = 64;
            break;
          case 131:
          case 163:
            rect.left = 224;
            rect.right = 240;
            rect.top = 64 - (PutMapDataVector(long,long)::count & 0xF);
            rect.bottom = rect.top + 16;
            break;
          default:
            break;
        }
        PutBitmap3(&grcGame, 8 * (2 * i - 1) - fx / 512, 8 * (2 * j - 1) - fy / 512, &rect, 19);
      }
    }
  }
}

