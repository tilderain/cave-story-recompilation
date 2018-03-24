#include "types.h"
#include "SDL_stdinc.h"
#include "windows_wrapper.h"
#include "Tags.h"
void __cdecl _Vanish($96A7816609F59F56E43A9A5E8F547E1B *bul)
{
  if ( bul->code_bullet != 37 && bul->code_bullet != 38 && bul->code_bullet != 39 )
    PlaySoundObject(28, 1);
  else
    SetCaret(bul->x, bul->y, 2, 1);
  bul->cond = 0;
  SetCaret(bul->x, bul->y, 2, 2);
}

int __cdecl JudgeHitBulletBlock(int x, int y, $96A7816609F59F56E43A9A5E8F547E1B *bul)
{
  bool v3;
  int v4;
  int v5;
  int i;
  int hit;

  hit = 0;
  if ( bul->x - bul->blockXL < (2 * x + 1) << 12
    && bul->blockXL + bul->x > (2 * x - 1) << 12
    && bul->y - bul->blockYL < (2 * y + 1) << 12
    && bul->blockYL + bul->y > (2 * y - 1) << 12 )
  {
    hit = 512;
  }
  v3 = hit && bul->bbits & 0x60 && (unsigned __int8)GetAttribute(x, y) == 67;
  if ( v3 )
  {
    if ( !(bul->bbits & 0x40) )
      bul->cond = 0;
    SetCaret(bul->x, bul->y, 2, 0);
    PlaySoundObject(12, 1);
    for ( i = 0; i <= 3; ++i )
    {
      v4 = Random(-512, 512);
      v5 = Random(-512, 512);
      SetNpChar(4, x << 13, y << 13, v5, v4, 0, 0, 256);
    }
    ShiftMapParts(x, y);
  }
  return hit;
}

int __cdecl JudgeHitBulletBlock2(int x, int y, unsigned __int8 *atrb, $96A7816609F59F56E43A9A5E8F547E1B *bul)
{
  int block[4];
  int workX;
  int workY;
  int hit;
  int i;

  hit = 0;
  if ( bul->bbits & 0x40 )
  {
    for ( i = 0; i <= 3; ++i )
    {
      block[i] = *atrb == 65 || *atrb == 97;
      ++atrb;
    }
  }
  else
  {
    for ( i = 0; i <= 3; ++i )
    {
      block[i] = *atrb == 65 || *atrb == 67 || *atrb == 97;
      ++atrb;
    }
  }
  workX = (2 * x + 1) << 12;
  workY = (2 * y + 1) << 12;
  if ( block[0] && block[2] )
  {
    if ( bul->x - bul->blockXL < workX )
      hit |= 1u;
  }
  else if ( !block[0] || block[2] )
  {
    if ( !block[0] && block[2] && bul->x - bul->blockXL < workX && bul->blockYL + bul->y > workY + 1536 )
      hit |= 1u;
  }
  else if ( bul->x - bul->blockXL < workX && bul->y - bul->blockYL < workY - 1536 )
  {
    hit |= 1u;
  }
  if ( block[1] && block[3] )
  {
    if ( bul->x + bul->blockXL > workX )
      hit |= 4u;
  }
  else if ( !block[1] || block[3] )
  {
    if ( !block[1] && block[3] && bul->x + bul->blockXL > workX && bul->blockYL + bul->y > workY + 1536 )
      hit |= 4u;
  }
  else if ( bul->x + bul->blockXL > workX && bul->y - bul->blockYL < workY - 1536 )
  {
    hit |= 4u;
  }
  if ( block[0] && block[1] )
  {
    if ( bul->y - bul->blockYL < workY )
      hit |= 2u;
  }
  else if ( !block[0] || block[1] )
  {
    if ( !block[0] && block[1] && bul->y - bul->blockYL < workY && bul->blockXL + bul->x > workX + 1536 )
      hit |= 2u;
  }
  else if ( bul->y - bul->blockYL < workY && bul->x - bul->blockXL < workX - 1536 )
  {
    hit |= 2u;
  }
  if ( block[2] && block[3] )
  {
    if ( bul->y + bul->blockYL > workY )
      hit |= 8u;
  }
  else if ( !block[2] || block[3] )
  {
    if ( !block[2] && block[3] && bul->y + bul->blockYL > workY && bul->blockXL + bul->x > workX + 1536 )
      hit |= 8u;
  }
  else if ( bul->y + bul->blockYL > workY && bul->x - bul->blockXL < workX - 1536 )
  {
    hit |= 8u;
  }
  if ( bul->bbits & 8 )
  {
    if ( hit & 1 )
    {
      bul->x = workX + bul->blockXL;
    }
    else if ( hit & 4 )
    {
      bul->x = workX - bul->blockXL;
    }
    else if ( hit & 2 )
    {
      bul->y = workY + bul->blockYL;
    }
    else if ( hit & 8 )
    {
      bul->y = workY - bul->blockYL;
    }
  }
  else if ( hit & 0xF )
  {
    _Vanish(bul);
  }
  return hit;
}

int __cdecl JudgeHitBulletTriangleA(int x, int y, $96A7816609F59F56E43A9A5E8F547E1B *bul)
{
  int hit;

  hit = 0;
  if ( bul->x < (2 * x + 1) << 12
    && bul->x > (2 * x - 1) << 12
    && bul->y - 1024 < (y << 13) - (-8192 * x + bul->x) / 2 + 2048
    && bul->y + 1024 > (2 * y - 1) << 12 )
  {
    if ( bul->bbits & 8 )
      bul->y = (y << 13) - (-8192 * x + bul->x) / 2 + 3072;
    else
      _Vanish(bul);
    hit = 130;
  }
  return hit;
}

int __cdecl JudgeHitBulletTriangleB(int x, int y, $96A7816609F59F56E43A9A5E8F547E1B *bul)
{
  int hit;

  hit = 0;
  if ( bul->x < (2 * x + 1) << 12
    && bul->x > (2 * x - 1) << 12
    && bul->y - 1024 < (y << 13) - (-8192 * x + bul->x) / 2 - 2048
    && bul->y + 1024 > (2 * y - 1) << 12 )
  {
    if ( bul->bbits & 8 )
      bul->y = (y << 13) - (-8192 * x + bul->x) / 2 - 1024;
    else
      _Vanish(bul);
    hit = 130;
  }
  return hit;
}

int __cdecl JudgeHitBulletTriangleC(int x, int y, $96A7816609F59F56E43A9A5E8F547E1B *bul)
{
  int hit;

  hit = 0;
  if ( bul->x < (2 * x + 1) << 12
    && bul->x > (2 * x - 1) << 12
    && bul->y - 1024 < (y << 13) + (-8192 * x + bul->x) / 2 - 2048
    && bul->y + 1024 > (2 * y - 1) << 12 )
  {
    if ( bul->bbits & 8 )
      bul->y = (y << 13) + (-8192 * x + bul->x) / 2 - 1024;
    else
      _Vanish(bul);
    hit = 66;
  }
  return hit;
}

int __cdecl JudgeHitBulletTriangleD(int x, int y, $96A7816609F59F56E43A9A5E8F547E1B *bul)
{
  int hit;

  hit = 0;
  if ( bul->x < (2 * x + 1) << 12
    && bul->x > (2 * x - 1) << 12
    && bul->y - 1024 < (y << 13) + (-8192 * x + bul->x) / 2 + 2048
    && bul->y + 1024 > (2 * y - 1) << 12 )
  {
    if ( bul->bbits & 8 )
      bul->y = (y << 13) + (-8192 * x + bul->x) / 2 + 3072;
    else
      _Vanish(bul);
    hit = 66;
  }
  return hit;
}

int __cdecl JudgeHitBulletTriangleE(int x, int y, $96A7816609F59F56E43A9A5E8F547E1B *bul)
{
  int hit;

  hit = 0;
  if ( bul->x < (2 * x + 1) << 12
    && bul->x - 512 > (2 * x - 1) << 12
    && bul->y + 1024 > (y << 13) + (-8192 * x + bul->x) / 2 - 2048
    && bul->y - 1024 < (2 * y + 1) << 12 )
  {
    if ( bul->bbits & 8 )
      bul->y = (y << 13) + (-8192 * x + bul->x) / 2 - 3072;
    else
      _Vanish(bul);
    hit = 40;
  }
  return hit;
}

int __cdecl JudgeHitBulletTriangleF(int x, int y, $96A7816609F59F56E43A9A5E8F547E1B *bul)
{
  int hit;

  hit = 0;
  if ( bul->x < (2 * x + 1) << 12
    && bul->x > (2 * x - 1) << 12
    && bul->y + 1024 > (y << 13) + (-8192 * x + bul->x) / 2 + 2048
    && bul->y - 1024 < (2 * y + 1) << 12 )
  {
    if ( bul->bbits & 8 )
      bul->y = (y << 13) + (-8192 * x + bul->x) / 2 + 1024;
    else
      _Vanish(bul);
    hit = 40;
  }
  return hit;
}

int __cdecl JudgeHitBulletTriangleG(int x, int y, $96A7816609F59F56E43A9A5E8F547E1B *bul)
{
  int hit;

  hit = 0;
  if ( bul->x < (2 * x + 1) << 12
    && bul->x > (2 * x - 1) << 12
    && bul->y + 1024 > (y << 13) - (-8192 * x + bul->x) / 2 + 2048
    && bul->y - 1024 < (2 * y + 1) << 12 )
  {
    if ( bul->bbits & 8 )
      bul->y = (y << 13) - (-8192 * x + bul->x) / 2 + 1024;
    else
      _Vanish(bul);
    hit = 24;
  }
  return hit;
}

int __cdecl JudgeHitBulletTriangleH(int x, int y, $96A7816609F59F56E43A9A5E8F547E1B *bul)
{
  int hit;

  hit = 0;
  if ( bul->x < (2 * x + 1) << 12
    && bul->x > (2 * x - 1) << 12
    && bul->y + 1024 > (y << 13) - (-8192 * x + bul->x) / 2 - 2048
    && bul->y - 1024 < (2 * y + 1) << 12 )
  {
    if ( bul->bbits & 8 )
      bul->y = (y << 13) - (-8192 * x + bul->x) / 2 - 3072;
    else
      _Vanish(bul);
    hit = 24;
  }
  return hit;
}

void HitBulletMap()
{
  __int64 v0;
  __int64 v1;
  int v2;
  int v3;
  int v4;
  int v5;
  int v6;
  int v7;
  int v8;
  int v9;
  int v10;
  int v11;
  int v12;
  int v13;
  int v14;
  int v15;
  int v16;
  int v17;
  int v18;
  int v19;
  int v20;
  int v21;
  int offy[4];
  int offx[4];
  unsigned __int8 atrb[4];
  int x;
  int y;
  int i;
  int j;

  for ( i = 0; i <= 63; ++i )
  {
    if ( gBul[i].cond & 0x80 )
    {
      v0 = *(&gBul[0].flag + 4 * (8 * i + 1));
      x = (signed int)((HIDWORD(v0) >> 19) + v0) >> 13;
      v1 = *(&gBul[0].code_bullet + 4 * (8 * i + 1));
      y = (signed int)((HIDWORD(v1) >> 19) + v1) >> 13;
      offx[0] = 0;
      offx[1] = 1;
      offx[2] = 0;
      offx[3] = 1;
      offy[0] = 0;
      offy[1] = 0;
      offy[2] = 1;
      offy[3] = 1;
      atrb[0] = GetAttribute(x, y);
      atrb[1] = GetAttribute(x + 1, y);
      atrb[2] = GetAttribute(x, y + 1);
      atrb[3] = GetAttribute(x + 1, y + 1);
      gBul[i].flag = 0;
      if ( !(gBul[i].bbits & 4) )
      {
        for ( j = 0; j <= 3; ++j )
        {
          if ( gBul[i].cond & 0x80 )
          {
            switch ( atrb[j] )
            {
              case 0x41u:
              case 0x43u:
              case 0x44u:
              case 0x61u:
              case 0x64u:
                v2 = i;
                v3 = gBul[i].flag;
                gBul[v2].flag = JudgeHitBulletBlock(x + offx[j], y + offy[j], &gBul[i]) | v3;
                break;
              case 0x50u:
              case 0x70u:
                v4 = i;
                v5 = gBul[i].flag;
                gBul[v4].flag = JudgeHitBulletTriangleA(x + offx[j], y + offy[j], &gBul[i]) | v5;
                break;
              case 0x51u:
              case 0x71u:
                v6 = i;
                v7 = gBul[i].flag;
                gBul[v6].flag = JudgeHitBulletTriangleB(x + offx[j], y + offy[j], &gBul[i]) | v7;
                break;
              case 0x52u:
              case 0x72u:
                v8 = i;
                v9 = gBul[i].flag;
                gBul[v8].flag = JudgeHitBulletTriangleC(x + offx[j], y + offy[j], &gBul[i]) | v9;
                break;
              case 0x53u:
              case 0x73u:
                v10 = i;
                v11 = gBul[i].flag;
                gBul[v10].flag = JudgeHitBulletTriangleD(x + offx[j], y + offy[j], &gBul[i]) | v11;
                break;
              case 0x54u:
              case 0x74u:
                v12 = i;
                v13 = gBul[i].flag;
                gBul[v12].flag = JudgeHitBulletTriangleE(x + offx[j], y + offy[j], &gBul[i]) | v13;
                break;
              case 0x55u:
              case 0x75u:
                v14 = i;
                v15 = gBul[i].flag;
                gBul[v14].flag = JudgeHitBulletTriangleF(x + offx[j], y + offy[j], &gBul[i]) | v15;
                break;
              case 0x56u:
              case 0x76u:
                v16 = i;
                v17 = gBul[i].flag;
                gBul[v16].flag = JudgeHitBulletTriangleG(x + offx[j], y + offy[j], &gBul[i]) | v17;
                break;
              case 0x57u:
              case 0x77u:
                v18 = i;
                v19 = gBul[i].flag;
                gBul[v18].flag = JudgeHitBulletTriangleH(x + offx[j], y + offy[j], &gBul[i]) | v19;
                break;
              default:
                continue;
            }
          }
        }
        v20 = i;
        v21 = gBul[i].flag;
        gBul[v20].flag = JudgeHitBulletBlock2(x, y, atrb, ($96A7816609F59F56E43A9A5E8F547E1B *)((i << 7) + 136090016)) | v21;
      }
    }
  }
}

signed int get_language()
{
  return 1;
}

