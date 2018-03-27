//#include "types.h"
#include "stdint.h"
#include "SDL_stdinc.h"
#include "SDL_video.h"
#include "Tags.h"

signed int InitBack(char *fName, int type);
void ActBack();
void PutBack(int fx, int fy);
void PutFront(int fx, int fy);

unsigned int _color_black;

signed int InitBack(char *fName, int type)
{
  SDL_RWops *v2;
  char path[260];
  Uint8 r;
  SDL_Surface *temp;

  RGB((int)&r, 0, 0, 16);
  _color_black = GetCortBoxColor((const SDL_Color *const )&r);
  sprintf(path, "%s/%s.pbm", gDataPath, fName);
  v2 = SDL_RWFromFile(path, "rb");
  temp = SDL_LoadBMP_RW(v2, 1);
  if ( !temp )
    return 0;
  gBack.partsW = temp->w;
  gBack.partsH = temp->h;
  SDL_FreeSurface(temp);
  temp = 0;
  gBack.flag = 1;
  if ( !ReloadBitmap_File(fName, 28) )
    return 0;
  gBack.type = type;
  gWaterY = 1966080;
  return 1;
}


void ActBack()
{
  if ( gBack.type == 5 )
  {
    gBack._fx += 3072;
  }
  else if ( gBack.type >= 5 && gBack.type <= 7 )
  {
    ++gBack._fx;
    gBack._fx %= 640;
  }
}

void PutBack(int fx, int fy)
{
  RECT rect;
  int x;
  int y;

  rect.left = 0;
  rect.top = 0;
  rect.right = gBack.partsW;
  rect.bottom = gBack.partsH;
  switch ( gBack.type )
  {
    case 0:
      for ( y = 0; y <= 239; y += gBack.partsH )
      {
        for ( x = 0; x <= 319; x += gBack.partsW )
          PutBitmap4(&grcGame, x, y, &rect, 28);
      }
      break;
    case 1:
      for ( y = -(fy / 1024 % gBack.partsH); y <= 239; y += gBack.partsH )
      {
        for ( x = -(fx / 1024 % gBack.partsW); x <= 319; x += gBack.partsW )
          PutBitmap4(&grcGame, x, y, &rect, 28);
      }
      break;
    case 2:
      for ( y = -(fy / 512 % gBack.partsH); y <= 239; y += gBack.partsH )
      {
        for ( x = -(fx / 512 % gBack.partsW); x <= 319; x += gBack.partsW )
          PutBitmap4(&grcGame, x, y, &rect, 28);
      }
      break;
    case 5:
      for ( y = -gBack.partsH; y <= 239; y += gBack.partsH )
      {
        for ( x = -(gBack._fx / 512 % gBack.partsW); x <= 319; x += gBack.partsW )
          PutBitmap4(&grcGame, x, y, &rect, 28);
      }
      break;
    case 6:
    case 7:
      rect.top = 0;
      rect.bottom = 88;
      rect.left = 0;
      rect.right = 320;
      PutBitmap4(&grcGame, 0, 0, &rect, 28);
      rect.top = 88;
      rect.bottom = 123;
      rect.left = gBack._fx / 2;
      rect.right = 320;
      PutBitmap4(&grcGame, 0, 88, &rect, 28);
      rect.left = 0;
      PutBitmap4(&grcGame, 320 - gBack._fx / 2 % 320, 88, &rect, 28);
      rect.top = 123;
      rect.bottom = 146;
      rect.left = gBack._fx % 320;
      rect.right = 320;
      PutBitmap4(&grcGame, 0, 123, &rect, 28);
      rect.left = 0;
      PutBitmap4(&grcGame, 320 - gBack._fx % 320, 123, &rect, 28);
      rect.top = 146;
      rect.bottom = 176;
      rect.left = 2 * gBack._fx % 320;
      rect.right = 320;
      PutBitmap4(&grcGame, 0, 146, &rect, 28);
      rect.left = 0;
      PutBitmap4(&grcGame, 320 - 2 * gBack._fx % 320, 146, &rect, 28);
      rect.top = 176;
      rect.bottom = 240;
      rect.left = 4 * gBack._fx % 320;
      rect.right = 320;
      PutBitmap4(&grcGame, 0, 176, &rect, 28);
      rect.left = 0;
      PutBitmap4(&grcGame, 320 - 4 * gBack._fx % 320, 176, &rect, 28);
      break;
    default:
      return;
  }
}

void PutFront(int fx, int fy)
{
  RECT rcWater[2];
  int xpos;
  int ypos;
  int x;
  int y;
  int x_1;
  int x_2;
  int y_1;
  int y_2;

  rcWater[0].left = 0;
  rcWater[0].top = 0;
  rcWater[0].right = 32;
  rcWater[0].bottom = 16;
  rcWater[1].left = 0;
  rcWater[1].top = 16;
  rcWater[1].right = 32;
  rcWater[1].bottom = 48;
  if ( gBack.type == 3 )
  {
    x_1 = fx / 0x4000;
    x_2 = fx / 0x4000 + 11;
    y_1 = 0;
    y_2 = 32;
    for ( y = 0; y < y_2; ++y )
    {
      ypos = (y << 14) / 512 - fy / 512 + gWaterY / 512;
      if ( ypos >= -32 )
      {
        if ( ypos > 240 )
          return;
        for ( x = x_1; x < x_2; ++x )
        {
          xpos = (x << 14) / 512 - fx / 512;
          PutBitmap3(&grcGame, xpos, ypos, &rcWater[1], 28);
          if ( !y )
            PutBitmap3(&grcGame, xpos, ypos, rcWater, 28);
        }
      }
    }
  }
}

