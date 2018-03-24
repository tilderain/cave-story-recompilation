#include "types.h"
#include "SDL_stdinc.h"
#include "windows_wrapper.h"
#include "Tags.h"
#include "KeyControl.h"
#include "windows_wrapper.h"

void InitBullet();
int __cdecl CountArmsBullet(int arms_code);
int __cdecl CountBulletNum(int bullet_code);
void __cdecl DeleteBullet(int code);
void ClearBullet();
void __cdecl PutBullet(int fx, int fy);
void __cdecl SetBullet(int no, int x, int y, int dir);
void __cdecl ActBullet_Frontia1($96A7816609F59F56E43A9A5E8F547E1B *bul);
void __cdecl ActBullet_Frontia2($96A7816609F59F56E43A9A5E8F547E1B *bul, int level);
void __cdecl ActBullet_PoleStar($96A7816609F59F56E43A9A5E8F547E1B *bul, int level);
void __cdecl ActBullet_FireBall($96A7816609F59F56E43A9A5E8F547E1B *bul, int level);
void __cdecl ActBullet_MachineGun($96A7816609F59F56E43A9A5E8F547E1B *bul, int level);
void __cdecl ActBullet_Missile($96A7816609F59F56E43A9A5E8F547E1B *bul, int level);
void __cdecl ActBullet_Bom($96A7816609F59F56E43A9A5E8F547E1B *bul, int level);
void __cdecl ActBullet_Bubblin1($96A7816609F59F56E43A9A5E8F547E1B *bul);
void __cdecl ActBullet_Bubblin2($96A7816609F59F56E43A9A5E8F547E1B *bul);
void __cdecl ActBullet_Bubblin3($96A7816609F59F56E43A9A5E8F547E1B *bul);
void __cdecl ActBullet_Spine($96A7816609F59F56E43A9A5E8F547E1B *bul);
void __cdecl ActBullet_Sword1($96A7816609F59F56E43A9A5E8F547E1B *bul);
void __cdecl ActBullet_Sword2($96A7816609F59F56E43A9A5E8F547E1B *bul);
void __cdecl ActBullet_Sword3($96A7816609F59F56E43A9A5E8F547E1B *bul);
void __cdecl ActBullet_Edge($96A7816609F59F56E43A9A5E8F547E1B *bul);
void __cdecl ActBullet_Drop($96A7816609F59F56E43A9A5E8F547E1B *bul);
void __cdecl ActBullet_SuperMissile($96A7816609F59F56E43A9A5E8F547E1B *bul, int level);
void __cdecl ActBullet_SuperBom($96A7816609F59F56E43A9A5E8F547E1B *bul, int level);
void __cdecl ActBullet_Nemesis($96A7816609F59F56E43A9A5E8F547E1B *bul, int level);
void __cdecl ActBullet_Spur($96A7816609F59F56E43A9A5E8F547E1B *bul, int level);
void __cdecl ActBullet_SpurTail($96A7816609F59F56E43A9A5E8F547E1B *bul, int level);
void __cdecl ActBullet_EnemyClear($96A7816609F59F56E43A9A5E8F547E1B *bul);
void __cdecl ActBullet_Star($96A7816609F59F56E43A9A5E8F547E1B *bul);
void ActBullet();
signed int IsActiveSomeBullet();

unsigned int ActBullet_SuperMissile(BULLET *,long)::inc;
unsigned int ActBullet_Missile(BULLET *,long)::inc;
unsigned int ActBullet_Frontia2(BULLET *,long)::inc;

$105B29886D5D4880B7955C7D7F8771E6 gBulTbl[46] =
{
  { '\0', '\0', 0, 0, 0, 0, 0, 0, { 0, 0, 0, 0 } },
  { '\x04', '\x01', 20, 36, 4, 4, 2, 2, { 8, 8, 8, 8 } },
  { '\x06', '\x01', 23, 36, 4, 4, 2, 2, { 8, 8, 8, 8 } },
  { '\b', '\x01', 30, 36, 4, 4, 2, 2, { 8, 8, 8, 8 } },
  { '\x01', '\x01', 8, 32, 6, 6, 2, 2, { 8, 8, 8, 8 } },
  { '\x02', '\x01', 12, 32, 6, 6, 2, 2, { 8, 8, 8, 8 } },
  { '\x04', '\x01', 16, 32, 6, 6, 2, 2, { 8, 8, 8, 8 } },
  { '\x02', '\x02', 100, 8, 8, 16, 4, 2, { 8, 8, 8, 8 } },
  { '\x03', '\x02', 100, 8, 4, 4, 4, 2, { 8, 8, 8, 8 } },
  { '\x03', '\x02', 100, 8, 4, 4, 4, 2, { 8, 8, 8, 8 } },
  { '\x02', '\x01', 20, 32, 2, 2, 2, 2, { 8, 8, 8, 8 } },
  { '\x04', '\x01', 20, 32, 2, 2, 2, 2, { 8, 8, 8, 8 } },
  { '\x06', '\x01', 20, 32, 2, 2, 2, 2, { 8, 8, 8, 8 } },
  { '\0', '\n', 50, 40, 2, 2, 2, 2, { 8, 8, 8, 8 } },
  { '\0', '\n', 70, 40, 4, 4, 4, 4, { 8, 8, 8, 8 } },
  { '\0', '\n', 90, 40, 4, 4, 0, 0, { 8, 8, 8, 8 } },
  { '\x01', 'd', 100, 20, 16, 16, 0, 0, { 0, 0, 0, 0 } },
  { '\x01', 'd', 100, 20, 16, 16, 0, 0, { 0, 0, 0, 0 } },
  { '\x01', 'd', 100, 20, 16, 16, 0, 0, { 0, 0, 0, 0 } },
  { '\x01', '\x01', 20, 8, 2, 2, 2, 2, { 4, 4, 4, 4 } },
  { '\x02', '\x01', 20, 8, 2, 2, 2, 2, { 4, 4, 4, 4 } },
  { '\x02', '\x01', 20, 8, 4, 4, 4, 4, { 4, 4, 4, 4 } },
  { '\x03', '\x01', 32, 32, 2, 2, 2, 2, { 4, 4, 4, 4 } },
  { '\0', 'd', 0, 36, 8, 8, 8, 8, { 12, 12, 12, 12 } },
  { '\x7F', '\x01', 2, 4, 8, 4, 8, 4, { 0, 0, 0, 0 } },
  { '\x0F', '\x01', 30, 36, 8, 8, 4, 2, { 8, 8, 8, 8 } },
  { '\x06', '\x03', 18, 36, 10, 10, 4, 2, { 12, 12, 12, 12 } },
  { '\x01', 'd', 30, 36, 6, 6, 4, 4, { 12, 12, 12, 12 } },
  { '\0', '\n', 30, 40, 2, 2, 2, 2, { 8, 8, 8, 8 } },
  { '\0', '\n', 40, 40, 4, 4, 4, 4, { 8, 8, 8, 8 } },
  { '\0', '\n', 40, 40, 4, 4, 0, 0, { 8, 8, 8, 8 } },
  { '\x02', 'd', 100, 20, 12, 12, 0, 0, { 0, 0, 0, 0 } },
  { '\x02', 'd', 100, 20, 12, 12, 0, 0, { 0, 0, 0, 0 } },
  { '\x02', 'd', 100, 20, 12, 12, 0, 0, { 0, 0, 0, 0 } },
  { '\x04', '\x04', 20, 32, 4, 4, 3, 3, { 8, 8, 24, 8 } },
  { '\x04', '\x02', 20, 32, 2, 2, 2, 2, { 8, 8, 24, 8 } },
  { '\x01', '\x01', 20, 32, 2, 2, 2, 2, { 8, 8, 24, 8 } },
  { '\x04', '\x04', 30, 64, 6, 6, 3, 3, { 8, 8, 8, 8 } },
  { '\b', '\b', 30, 64, 6, 6, 3, 3, { 8, 8, 8, 8 } },
  { '\f', '\f', 30, 64, 6, 6, 3, 3, { 8, 8, 8, 8 } },
  { '\x03', 'd', 30, 32, 6, 6, 3, 3, { 4, 4, 4, 4 } },
  { '\x06', 'd', 30, 32, 6, 6, 3, 3, { 4, 4, 4, 4 } },
  { '\v', 'd', 30, 32, 6, 6, 3, 3, { 4, 4, 4, 4 } },
  { '\x04', '\x04', 20, 32, 4, 4, 3, 3, { 8, 8, 24, 8 } },
  { '\0', '\x04', 4, 4, 0, 0, 0, 0, { 0, 0, 0, 0 } },
  { '\x01', '\x01', 1, 36, 1, 1, 1, 1, { 1, 1, 1, 1 } }
};

_UNKNOWN ActBullet_Edge(BULLET *)::C.71;
_UNKNOWN ActBullet_Edge(BULLET *)::C.72;

void InitBullet()
{
  int i;

  for ( i = 0; i <= 63; ++i )
    gBul[i].cond = 0;
}

int __cdecl CountArmsBullet(int arms_code)
{
  int i;
  int count;

  count = 0;
  for ( i = 0; i <= 63; ++i )
  {
    if ( gBul[i].cond & 0x80 && (gBul[i].code_bullet + 2) / 3 == arms_code )
      ++count;
  }
  return count;
}

int __cdecl CountBulletNum(int bullet_code)
{
  int i;
  int count;

  count = 0;
  for ( i = 0; i <= 63; ++i )
  {
    if ( gBul[i].cond & 0x80 && gBul[i].code_bullet == bullet_code )
      ++count;
  }
  return count;
}

void __cdecl DeleteBullet(int code)
{
  int i;

  for ( i = 0; i <= 63; ++i )
  {
    if ( gBul[i].cond & 0x80 )
    {
      if ( (gBul[i].code_bullet + 2) / 3 == code )
        gBul[i].cond = 0;
    }
  }
}

void ClearBullet()
{
  int i;

  for ( i = 0; i <= 63; ++i )
    gBul[i].cond = 0;
}

void __cdecl PutBullet(int fx, int fy)
{
  signed int v2;
  int i;
  int x;
  int y;

  for ( i = 0; i <= 63; ++i )
  {
    if ( gBul[i].cond & 0x80 )
    {
      v2 = gBul[i].direct;
      if ( v2 == 1 )
      {
        x = *(&gBul[0].flag + 4 * (8 * i + 1)) - gBul[i].view.top;
        y = *(&gBul[0].code_bullet + 4 * (8 * i + 1)) - gBul[i].view.front;
      }
      else if ( v2 > 1 )
      {
        if ( v2 == 2 )
        {
          x = *(&gBul[0].flag + 4 * (8 * i + 1)) - gBul[i].view.back;
          y = *(&gBul[0].code_bullet + 4 * (8 * i + 1)) - gBul[i].view.top;
        }
        else if ( v2 == 3 )
        {
          x = *(&gBul[0].flag + 4 * (8 * i + 1)) - gBul[i].view.top;
          y = *(&gBul[0].code_bullet + 4 * (8 * i + 1)) - gBul[i].view.back;
        }
      }
      else if ( !gBul[i].direct )
      {
        x = *(&gBul[0].flag + 4 * (8 * i + 1)) - gBul[i].view.front;
        y = *(&gBul[0].code_bullet + 4 * (8 * i + 1)) - gBul[i].view.top;
      }
      PutBitmap3(&grcGame, x / 512 - fx / 512, y / 512 - fy / 512, (RECT *)((i << 7) + 136090076), 17);
    }
  }
}

void __cdecl SetBullet(int no, int x, int y, int dir)
{
  char v4;
  int i;

  for ( i = 0; ; ++i )
  {
    v4 = i <= 63 && gBul[i].cond & 0x80 ? 1 : 0;
    if ( !v4 )
      break;
  }
  if ( i <= 63 )
  {
    memset((void *)((i << 7) + 136090016), 0, 0x80u);
    gBul[i].code_bullet = no;
    gBul[i].cond = 128;
    gBul[i].direct = dir;
    gBul[i].damage = gBulTbl[no].damage;
    gBul[i].life = gBulTbl[no].life;
    gBul[i].life_count = gBulTbl[no].life_count;
    gBul[i].bbits = gBulTbl[no].bbits;
    gBul[i].enemyXL = gBulTbl[no].enemyXL << 9;
    gBul[i].enemyYL = gBulTbl[no].enemyYL << 9;
    gBul[i].blockXL = gBulTbl[no].blockXL << 9;
    gBul[i].blockYL = gBulTbl[no].blockYL << 9;
    gBul[i].view.back = gBulTbl[no].view.back << 9;
    gBul[i].view.front = gBulTbl[no].view.front << 9;
    gBul[i].view.top = gBulTbl[no].view.top << 9;
    gBul[i].view.bottom = gBulTbl[no].view.bottom << 9;
    *(&gBul[0].flag + 4 * (8 * i + 1)) = x;
    *(&gBul[0].code_bullet + 4 * (8 * i + 1)) = y;
  }
}

void __cdecl ActBullet_Frontia1($96A7816609F59F56E43A9A5E8F547E1B *bul)
{
  signed int v1;
  $96A7816609F59F56E43A9A5E8F547E1B *v2;
  Sint32 *v3;
  RECT rcRight[4];
  RECT rcLeft[4];
  char v6[8];

  if ( ++bul->count1 <= bul->life_count )
  {
    if ( bul->act_no )
    {
      bul->x += bul->xm;
      bul->y += bul->ym;
    }
    else
    {
      bul->ani_no = Random(0, 2);
      bul->act_no = 1;
      v1 = bul->direct;
      if ( v1 == 1 )
      {
        bul->ym = -1536;
      }
      else if ( v1 > 1 )
      {
        if ( v1 == 2 )
        {
          bul->xm = 1536;
        }
        else if ( v1 == 3 )
        {
          bul->ym = 1536;
        }
      }
      else if ( !bul->direct )
      {
        bul->xm = -1536;
      }
    }
    if ( ++bul->ani_wait > 0 )
    {
      bul->ani_wait = 0;
      ++bul->ani_no;
    }
    if ( bul->ani_no > 3 )
      bul->ani_no = 0;
    rcLeft[0].left = 136;
    rcLeft[0].top = 80;
    rcLeft[0].right = 152;
    rcLeft[0].bottom = 80;
    rcLeft[1].left = 120;
    rcLeft[1].top = 80;
    rcLeft[1].right = 136;
    rcLeft[1].bottom = 96;
    rcLeft[2].left = 136;
    rcLeft[2].top = 64;
    rcLeft[2].right = 152;
    rcLeft[2].bottom = 80;
    rcLeft[3].left = 120;
    rcLeft[3].top = 64;
    rcLeft[3].right = 136;
    rcLeft[3].bottom = 80;
    rcRight[0].left = 120;
    rcRight[0].top = 64;
    rcRight[0].right = 136;
    rcRight[0].bottom = 80;
    rcRight[1].left = 136;
    rcRight[1].top = 64;
    rcRight[1].right = 152;
    rcRight[1].bottom = 80;
    rcRight[2].left = 120;
    rcRight[2].top = 80;
    rcRight[2].right = 136;
    rcRight[2].bottom = 96;
    rcRight[3].left = 136;
    rcRight[3].top = 80;
    rcRight[3].right = 152;
    rcRight[3].bottom = 80;
    if ( bul->direct )
    {
      v2 = bul;
      v3 = (Sint32 *)&v6[16 * bul->ani_no - 128];
    }
    else
    {
      v2 = bul;
      v3 = (Sint32 *)&v6[16 * bul->ani_no - 64];
    }
    bul->rect.left = *v3;
    v2->rect.top = v3[1];
    v2->rect.right = v3[2];
    v2->rect.bottom = v3[3];
  }
  else
  {
    bul->cond = 0;
    SetCaret(bul->x, bul->y, 3, 0);
  }
}


void __cdecl ActBullet_Frontia2($96A7816609F59F56E43A9A5E8F547E1B *bul, int level)
{
  signed int v2;
  signed int v3;
  signed int v4;
  signed int v5;
  Sint32 *v6;
  RECT rect[3];
  char v8[8];

  if ( ++bul->count1 > bul->life_count )
  {
    bul->cond = 0;
    SetCaret(bul->x, bul->y, 3, 0);
    return;
  }
  if ( !bul->act_no )
  {
    bul->ani_no = Random(0, 2);
    bul->act_no = 1;
    v2 = bul->direct;
    if ( v2 == 1 )
    {
      bul->ym = -512;
    }
    else if ( v2 > 1 )
    {
      if ( v2 == 2 )
      {
        bul->xm = 512;
      }
      else if ( v2 == 3 )
      {
        bul->ym = 512;
      }
    }
    else if ( !bul->direct )
    {
      bul->xm = -512;
    }
    ++ActBullet_Frontia2(BULLET *,long)::inc;
    v3 = bul->direct;
    if ( v3 != 1 )
    {
      if ( v3 <= 1 )
      {
        if ( bul->direct )
          goto LABEL_55;
LABEL_22:
        if ( ActBullet_Frontia2(BULLET *,long)::inc & 1 )
          bul->ym = 1024;
        else
          bul->ym = -1024;
        goto LABEL_55;
      }
      if ( v3 == 2 )
        goto LABEL_22;
      if ( v3 != 3 )
        goto LABEL_55;
    }
    if ( ActBullet_Frontia2(BULLET *,long)::inc & 1 )
      bul->xm = 1024;
    else
      bul->xm = -1024;
    goto LABEL_55;
  }
  v4 = bul->direct;
  if ( v4 == 1 )
  {
    bul->ym -= 128;
  }
  else if ( v4 > 1 )
  {
    if ( v4 == 2 )
    {
      bul->xm += 128;
    }
    else if ( v4 == 3 )
    {
      bul->ym += 128;
    }
  }
  else if ( !bul->direct )
  {
    bul->xm -= 128;
  }
  v5 = bul->direct;
  if ( v5 == 1 )
    goto LABEL_50;
  if ( v5 > 1 )
  {
    if ( v5 == 2 )
    {
LABEL_46:
      if ( bul->count1 % 5 == 2 )
      {
        if ( bul->ym >= 0 )
          bul->ym = -1024;
        else
          bul->ym = 1024;
      }
      goto LABEL_54;
    }
    if ( v5 != 3 )
      goto LABEL_54;
LABEL_50:
    if ( bul->count1 % 5 == 2 )
    {
      if ( bul->xm >= 0 )
        bul->xm = -1024;
      else
        bul->xm = 1024;
    }
    goto LABEL_54;
  }
  if ( !bul->direct )
    goto LABEL_46;
LABEL_54:
  bul->x += bul->xm;
  bul->y += bul->ym;
LABEL_55:
  if ( ++bul->ani_wait > 0 )
  {
    bul->ani_wait = 0;
    ++bul->ani_no;
  }
  if ( bul->ani_no > 2 )
    bul->ani_no = 0;
  rect[0].left = 192;
  rect[0].top = 16;
  rect[0].right = 208;
  rect[0].bottom = 32;
  rect[1].left = 208;
  rect[1].top = 16;
  rect[1].right = 224;
  rect[1].bottom = 32;
  rect[2].left = 224;
  rect[2].top = 16;
  rect[2].right = 240;
  rect[2].bottom = 32;
  v6 = (Sint32 *)&v8[16 * bul->ani_no - 48];
  bul->rect.left = *v6;
  bul->rect.top = v6[1];
  bul->rect.right = v6[2];
  bul->rect.bottom = v6[3];
  if ( level == 2 )
    SetNpChar(129, bul->x, bul->y, 0, -512, bul->ani_no, 0, 256);
  else
    SetNpChar(129, bul->x, bul->y, 0, -512, bul->ani_no + 3, 0, 256);
}


void __cdecl ActBullet_PoleStar($96A7816609F59F56E43A9A5E8F547E1B *bul, int level)
{
  signed int v2;
  signed int v3;
  signed int v4;

  if ( ++bul->count1 <= bul->life_count )
  {
    if ( bul->act_no )
    {
      bul->x += bul->xm;
      bul->y += bul->ym;
    }
    else
    {
      bul->act_no = 1;
      v2 = bul->direct;
      if ( v2 == 1 )
      {
        bul->ym = -4096;
      }
      else if ( v2 > 1 )
      {
        if ( v2 == 2 )
        {
          bul->xm = 4096;
        }
        else if ( v2 == 3 )
        {
          bul->ym = 4096;
        }
      }
      else if ( !bul->direct )
      {
        bul->xm = -4096;
      }
      if ( level == 1 )
      {
        v3 = bul->direct;
        if ( v3 == 1 )
        {
          bul->enemyXL = 1024;
        }
        else if ( v3 > 1 )
        {
          if ( v3 == 2 )
          {
            bul->enemyYL = 1024;
          }
          else if ( v3 == 3 )
          {
            bul->enemyXL = 1024;
          }
        }
        else if ( !bul->direct )
        {
          bul->enemyYL = 1024;
        }
      }
      else if ( level == 2 )
      {
        v4 = bul->direct;
        if ( v4 == 1 )
        {
          bul->enemyXL = 2048;
        }
        else if ( v4 > 1 )
        {
          if ( v4 == 2 )
          {
            bul->enemyYL = 2048;
          }
          else if ( v4 == 3 )
          {
            bul->enemyXL = 2048;
          }
        }
        else if ( !bul->direct )
        {
          bul->enemyYL = 2048;
        }
      }
    }
    switch ( level )
    {
      case 2:
        if ( bul->direct != 1 && bul->direct != 3 )
        {
          bul->rect.left = 160;
          bul->rect.top = 32;
          bul->rect.right = 176;
          bul->rect.bottom = 48;
        }
        else
        {
          bul->rect.left = 176;
          bul->rect.top = 32;
          bul->rect.right = 192;
          bul->rect.bottom = 48;
        }
        break;
      case 3:
        if ( bul->direct != 1 && bul->direct != 3 )
        {
          bul->rect.left = 128;
          bul->rect.top = 48;
          bul->rect.right = 144;
          bul->rect.bottom = 64;
        }
        else
        {
          bul->rect.left = 144;
          bul->rect.top = 48;
          bul->rect.right = 160;
          bul->rect.bottom = 64;
        }
        break;
      case 1:
        if ( bul->direct != 1 && bul->direct != 3 )
        {
          bul->rect.left = 128;
          bul->rect.top = 32;
          bul->rect.right = 144;
          bul->rect.bottom = 48;
        }
        else
        {
          bul->rect.left = 144;
          bul->rect.top = 32;
          bul->rect.right = 160;
          bul->rect.bottom = 48;
        }
        break;
    }
  }
  else
  {
    bul->cond = 0;
    SetCaret(bul->x, bul->y, 3, 0);
  }
}

void __cdecl ActBullet_FireBall($96A7816609F59F56E43A9A5E8F547E1B *bul, int level)
{
  signed int v2;
  int v3;
  $96A7816609F59F56E43A9A5E8F547E1B *v4;
  Sint32 *v5;
  $96A7816609F59F56E43A9A5E8F547E1B *v6;
  Sint32 *v7;
  RECT rect_right1[4];
  RECT rect_left1[4];
  RECT rect_right2[3];
  RECT rect_left2[3];
  bool bBreak;
  char v13[8];

  if ( ++bul->count1 <= bul->life_count )
  {
    bBreak = 0;
    if ( bul->flag & 2 && bul->flag & 8 )
      bBreak = 1;
    if ( bul->flag & 1 && bul->flag & 4 )
      bBreak = 1;
    if ( !bul->direct && bul->flag & 1 )
      bul->direct = 2;
    if ( bul->direct == 2 && bul->flag & 4 )
      bul->direct = 0;
    if ( bBreak )
    {
      bul->cond = 0;
      SetCaret(bul->x, bul->y, 2, 0);
      PlaySoundObject(28, 1);
    }
    else
    {
      if ( bul->act_no )
      {
        if ( bul->flag & 8 )
        {
          bul->ym = -1024;
        }
        else if ( bul->flag & 1 )
        {
          bul->xm = 1024;
        }
        else if ( bul->flag & 4 )
        {
          bul->xm = -1024;
        }
        bul->ym += 85;
        if ( bul->ym > 1023 )
          bul->ym = 1023;
        bul->x += bul->xm;
        bul->y += bul->ym;
        if ( bul->flag & 0xD )
          PlaySoundObject(34, 1);
      }
      else
      {
        bul->act_no = 1;
        v2 = bul->direct;
        if ( v2 == 1 )
        {
          bul->xm = unk_81C85B4;
          if ( unk_81C85B4 >= 0 )
            bul->direct = 2;
          else
            bul->direct = 0;
          if ( dir )
            v3 = bul->xm + 128;
          else
            v3 = bul->xm - 128;
          bul->xm = v3;
          bul->ym = -1535;
        }
        else if ( v2 > 1 )
        {
          if ( v2 == 2 )
          {
            bul->xm = 1024;
          }
          else if ( v2 == 3 )
          {
            bul->xm = unk_81C85B4;
            if ( unk_81C85B4 >= 0 )
              bul->direct = 2;
            else
              bul->direct = 0;
            bul->ym = 1535;
          }
        }
        else if ( !bul->direct )
        {
          bul->xm = -1024;
        }
      }
      rect_left1[0].left = 128;
      rect_left1[0].top = 0;
      rect_left1[0].right = 144;
      rect_left1[0].bottom = 16;
      rect_left1[1].left = 144;
      rect_left1[1].top = 0;
      rect_left1[1].right = 160;
      rect_left1[1].bottom = 16;
      rect_left1[2].left = 160;
      rect_left1[2].top = 0;
      rect_left1[2].right = 176;
      rect_left1[2].bottom = 16;
      rect_left1[3].left = 176;
      rect_left1[3].top = 0;
      rect_left1[3].right = 192;
      rect_left1[3].bottom = 16;
      rect_right1[0].left = 128;
      rect_right1[0].top = 16;
      rect_right1[0].right = 144;
      rect_right1[0].bottom = 32;
      rect_right1[1].left = 144;
      rect_right1[1].top = 16;
      rect_right1[1].right = 160;
      rect_right1[1].bottom = 32;
      rect_right1[2].left = 160;
      rect_right1[2].top = 16;
      rect_right1[2].right = 176;
      rect_right1[2].bottom = 32;
      rect_right1[3].left = 176;
      rect_right1[3].top = 16;
      rect_right1[3].right = 192;
      rect_right1[3].bottom = 32;
      rect_left2[0].left = 192;
      rect_left2[0].top = 16;
      rect_left2[0].right = 208;
      rect_left2[0].bottom = 32;
      rect_left2[1].left = 208;
      rect_left2[1].top = 16;
      rect_left2[1].right = 224;
      rect_left2[1].bottom = 32;
      rect_left2[2].left = 224;
      rect_left2[2].top = 16;
      rect_left2[2].right = 240;
      rect_left2[2].bottom = 32;
      rect_right2[0].left = 224;
      rect_right2[0].top = 16;
      rect_right2[0].right = 240;
      rect_right2[0].bottom = 32;
      rect_right2[1].left = 208;
      rect_right2[1].top = 16;
      rect_right2[1].right = 224;
      rect_right2[1].bottom = 32;
      rect_right2[2].left = 192;
      rect_right2[2].top = 16;
      rect_right2[2].right = 208;
      rect_right2[2].bottom = 32;
      ++bul->ani_no;
      if ( level == 1 )
      {
        if ( bul->ani_no > 3 )
          bul->ani_no = 0;
        if ( bul->direct )
        {
          v4 = bul;
          v5 = (Sint32 *)&v13[16 * bul->ani_no - 228];
        }
        else
        {
          v4 = bul;
          v5 = (Sint32 *)&v13[16 * bul->ani_no - 164];
        }
        bul->rect.left = *v5;
        v4->rect.top = v5[1];
        v4->rect.right = v5[2];
        v4->rect.bottom = v5[3];
      }
      else
      {
        if ( bul->ani_no > 2 )
          bul->ani_no = 0;
        if ( bul->direct )
        {
          v6 = bul;
          v7 = (Sint32 *)&v13[16 * bul->ani_no - 100];
        }
        else
        {
          v6 = bul;
          v7 = (Sint32 *)&v13[16 * bul->ani_no - 52];
        }
        bul->rect.left = *v7;
        v6->rect.top = v7[1];
        v6->rect.right = v7[2];
        v6->rect.bottom = v7[3];
        if ( level == 2 )
          SetNpChar(129, bul->x, bul->y, 0, -512, bul->ani_no, 0, 256);
        else
          SetNpChar(129, bul->x, bul->y, 0, -512, bul->ani_no + 3, 0, 256);
      }
    }
  }
  else
  {
    bul->cond = 0;
    SetCaret(bul->x, bul->y, 3, 0);
  }
}


void __cdecl ActBullet_MachineGun($96A7816609F59F56E43A9A5E8F547E1B *bul, int level)
{
  signed int v2;
  Sint32 *v3;
  Sint32 *v4;
  Sint32 *v5;
  RECT rect3[4];
  RECT rect2[4];
  RECT rect1[4];
  int move;
  char v10[8];

  rect1[0].left = 64;
  rect1[0].top = 0;
  rect1[0].right = 80;
  rect1[0].bottom = 16;
  rect1[1].left = 80;
  rect1[1].top = 0;
  rect1[1].right = 96;
  rect1[1].bottom = 16;
  rect1[2].left = 96;
  rect1[2].top = 0;
  rect1[2].right = 112;
  rect1[2].bottom = 16;
  rect1[3].left = 112;
  rect1[3].top = 0;
  rect1[3].right = 128;
  rect1[3].bottom = 16;
  rect2[0].left = 64;
  rect2[0].top = 16;
  rect2[0].right = 80;
  rect2[0].bottom = 32;
  rect2[1].left = 80;
  rect2[1].top = 16;
  rect2[1].right = 96;
  rect2[1].bottom = 32;
  rect2[2].left = 96;
  rect2[2].top = 16;
  rect2[2].right = 112;
  rect2[2].bottom = 32;
  rect2[3].left = 112;
  rect2[3].top = 16;
  rect2[3].right = 128;
  rect2[3].bottom = 32;
  rect3[0].left = 64;
  rect3[0].top = 32;
  rect3[0].right = 80;
  rect3[0].bottom = 48;
  rect3[1].left = 80;
  rect3[1].top = 32;
  rect3[1].right = 96;
  rect3[1].bottom = 48;
  rect3[2].left = 96;
  rect3[2].top = 32;
  rect3[2].right = 112;
  rect3[2].bottom = 48;
  rect3[3].left = 112;
  rect3[3].top = 32;
  rect3[3].right = 128;
  rect3[3].bottom = 48;
  if ( ++bul->count1 <= bul->life_count )
  {
    if ( bul->act_no )
    {
      bul->x += bul->xm;
      bul->y += bul->ym;
      switch ( level )
      {
        case 2:
          v4 = (Sint32 *)&v10[16 * bul->direct - 132];
          bul->rect.left = *v4;
          bul->rect.top = v4[1];
          bul->rect.right = v4[2];
          bul->rect.bottom = v4[3];
          if ( bul->direct != 1 && bul->direct != 3 )
            SetNpChar(127, bul->x, bul->y, 0, 0, 0, 0, 256);
          else
            SetNpChar(127, bul->x, bul->y, 0, 0, 1, 0, 256);
          break;
        case 3:
          v5 = (Sint32 *)&v10[16 * bul->direct - 196];
          bul->rect.left = *v5;
          bul->rect.top = v5[1];
          bul->rect.right = v5[2];
          bul->rect.bottom = v5[3];
          SetNpChar(128, bul->x, bul->y, 0, 0, bul->direct, 0, 256);
          break;
        case 1:
          v3 = (Sint32 *)&v10[16 * bul->direct - 68];
          bul->rect.left = *v3;
          bul->rect.top = v3[1];
          bul->rect.right = v3[2];
          bul->rect.bottom = v3[3];
          break;
      }
    }
    else
    {
      switch ( level )
      {
        case 2:
          move = 4096;
          break;
        case 3:
          move = 4096;
          break;
        case 1:
          move = 4096;
          break;
      }
      bul->act_no = 1;
      v2 = bul->direct;
      if ( v2 == 1 )
      {
        bul->ym = -move;
        bul->xm = Random(-170, 170);
      }
      else if ( v2 > 1 )
      {
        if ( v2 == 2 )
        {
          bul->xm = move;
          bul->ym = Random(-170, 170);
        }
        else if ( v2 == 3 )
        {
          bul->ym = move;
          bul->xm = Random(-170, 170);
        }
      }
      else if ( !bul->direct )
      {
        bul->xm = -move;
        bul->ym = Random(-170, 170);
      }
    }
  }
  else
  {
    bul->cond = 0;
    SetCaret(bul->x, bul->y, 3, 0);
  }
}


void __cdecl ActBullet_Missile($96A7816609F59F56E43A9A5E8F547E1B *bul, int level)
{
  int v2;
  signed int v3;
  signed int v4;
  unsigned int v5;
  signed int v6;
  signed int v7;
  int v8;
  int v9;
  signed int v10;
  Sint32 *v11;
  Sint32 *v12;
  Sint32 *v13;
  RECT rect3[4];
  RECT rect2[4];
  RECT rect1[4];
  bool bHit;
  char v18[8];

  if ( ++bul->count1 > bul->life_count )
  {
    bul->cond = 0;
    SetCaret(bul->x, bul->y, 3, 0);
    return;
  }
  bHit = 0;
  if ( bul->life != 10 )
    bHit = 1;
  if ( !bul->direct && bul->flag & 1 )
    bHit = 1;
  if ( bul->direct == 2 && bul->flag & 4 )
    bHit = 1;
  if ( bul->direct == 1 && bul->flag & 2 )
    bHit = 1;
  if ( bul->direct == 3 && bul->flag & 8 )
    bHit = 1;
  if ( !bul->direct && bul->flag & 0x80 )
    bHit = 1;
  if ( !bul->direct && bul->flag & 0x20 )
    bHit = 1;
  if ( bul->direct == 2 && bul->flag & 0x40 )
    bHit = 1;
  if ( bul->direct == 2 && bul->flag & 0x10 )
    bHit = 1;
  if ( bHit )
  {
    SetBullet(level + 15, bul->x, bul->y, 0);
    bul->cond = 0;
  }
  v2 = bul->act_no;
  if ( !v2 )
  {
    bul->act_no = 1;
    v3 = bul->direct;
    if ( v3 != 1 )
    {
      if ( v3 <= 1 )
      {
        if ( bul->direct )
          goto LABEL_43;
LABEL_41:
        bul->tgt_y = bul->y;
        goto LABEL_43;
      }
      if ( v3 == 2 )
        goto LABEL_41;
      if ( v3 != 3 )
      {
LABEL_43:
        if ( level != 3 )
        {
          bul->ani_no = 128;
          goto LABEL_67;
        }
        v4 = bul->direct;
        if ( v4 != 1 )
        {
          if ( v4 <= 1 )
          {
            if ( bul->direct )
              goto LABEL_59;
            goto LABEL_51;
          }
          if ( v4 == 2 )
          {
LABEL_51:
            if ( bul->y <= y )
              bul->ym = -256;
            else
              bul->ym = 256;
            bul->xm = Random(-512, 512);
            goto LABEL_59;
          }
          if ( v4 != 3 )
            goto LABEL_59;
        }
        if ( bul->x <= x )
          bul->xm = -256;
        else
          bul->xm = 256;
        bul->ym = Random(-512, 512);
LABEL_59:
        v5 = ++ActBullet_Missile(BULLET *,long)::inc % 3;
        if ( ActBullet_Missile(BULLET *,long)::inc % 3 == 1 )
        {
          bul->ani_no = 64;
        }
        else if ( v5 < 1 )
        {
          bul->ani_no = 128;
        }
        else if ( v5 == 2 )
        {
          bul->ani_no = 51;
        }
LABEL_67:
        v6 = bul->direct;
        if ( v6 == 1 )
        {
          bul->ym -= bul->ani_no;
        }
        else if ( v6 > 1 )
        {
          if ( v6 == 2 )
          {
            bul->xm += bul->ani_no;
          }
          else if ( v6 == 3 )
          {
            bul->ym += bul->ani_no;
          }
        }
        else if ( !bul->direct )
        {
          bul->xm -= bul->ani_no;
        }
        if ( level != 3 )
          goto LABEL_94;
        v7 = bul->direct;
        if ( v7 != 1 )
        {
          if ( v7 <= 1 )
          {
            if ( bul->direct )
            {
LABEL_94:
              if ( bul->xm < -2560 )
                bul->xm = -2560;
              if ( bul->xm > 2560 )
                bul->xm = 2560;
              if ( bul->ym < -2560 )
                bul->ym = -2560;
              if ( bul->ym > 2560 )
                bul->ym = 2560;
              bul->x += bul->xm;
              bul->y += bul->ym;
              goto LABEL_103;
            }
LABEL_86:
            if ( bul->y >= bul->tgt_y )
              v8 = bul->ym - 32;
            else
              v8 = bul->ym + 32;
            bul->ym = v8;
            goto LABEL_94;
          }
          if ( v7 == 2 )
            goto LABEL_86;
          if ( v7 != 3 )
            goto LABEL_94;
        }
        if ( bul->x >= bul->tgt_x )
          v9 = bul->xm - 32;
        else
          v9 = bul->xm + 32;
        bul->xm = v9;
        goto LABEL_94;
      }
    }
    bul->tgt_x = bul->x;
    goto LABEL_43;
  }
  if ( v2 == 1 )
    goto LABEL_67;
LABEL_103:
  if ( ++bul->count2 > 2 )
  {
    bul->count2 = 0;
    v10 = bul->direct;
    if ( v10 == 1 )
    {
      SetCaret(bul->x, bul->y + 4096, 7, 3);
    }
    else if ( v10 > 1 )
    {
      if ( v10 == 2 )
      {
        SetCaret(bul->x - 4096, bul->y, 7, 0);
      }
      else if ( v10 == 3 )
      {
        SetCaret(bul->x, bul->y - 4096, 7, 1);
      }
    }
    else if ( !bul->direct )
    {
      SetCaret(bul->x + 4096, bul->y, 7, 2);
    }
  }
  rect1[0].left = 0;
  rect1[0].top = 0;
  rect1[0].right = 16;
  rect1[0].bottom = 16;
  rect1[1].left = 16;
  rect1[1].top = 0;
  rect1[1].right = 32;
  rect1[1].bottom = 16;
  rect1[2].left = 32;
  rect1[2].top = 0;
  rect1[2].right = 48;
  rect1[2].bottom = 16;
  rect1[3].left = 48;
  rect1[3].top = 0;
  rect1[3].right = 64;
  rect1[3].bottom = 16;
  rect2[0].left = 0;
  rect2[0].top = 16;
  rect2[0].right = 16;
  rect2[0].bottom = 32;
  rect2[1].left = 16;
  rect2[1].top = 16;
  rect2[1].right = 32;
  rect2[1].bottom = 32;
  rect2[2].left = 32;
  rect2[2].top = 16;
  rect2[2].right = 48;
  rect2[2].bottom = 32;
  rect2[3].left = 48;
  rect2[3].top = 16;
  rect2[3].right = 64;
  rect2[3].bottom = 32;
  rect3[0].left = 0;
  rect3[0].top = 32;
  rect3[0].right = 16;
  rect3[0].bottom = 48;
  rect3[1].left = 16;
  rect3[1].top = 32;
  rect3[1].right = 32;
  rect3[1].bottom = 48;
  rect3[2].left = 32;
  rect3[2].top = 32;
  rect3[2].right = 48;
  rect3[2].bottom = 48;
  rect3[3].left = 48;
  rect3[3].top = 32;
  rect3[3].right = 64;
  rect3[3].bottom = 48;
  switch ( level )
  {
    case 2:
      v12 = (Sint32 *)&v18[16 * bul->direct - 132];
      bul->rect.left = *v12;
      bul->rect.top = v12[1];
      bul->rect.right = v12[2];
      bul->rect.bottom = v12[3];
      break;
    case 3:
      v13 = (Sint32 *)&v18[16 * bul->direct - 196];
      bul->rect.left = *v13;
      bul->rect.top = v13[1];
      bul->rect.right = v13[2];
      bul->rect.bottom = v13[3];
      break;
    case 1:
      v11 = (Sint32 *)&v18[16 * bul->direct - 68];
      bul->rect.left = *v11;
      bul->rect.top = v11[1];
      bul->rect.right = v11[2];
      bul->rect.bottom = v11[3];
      break;
  }
}


void __cdecl ActBullet_Bom($96A7816609F59F56E43A9A5E8F547E1B *bul, int level)
{
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

  v2 = bul->act_no;
  if ( v2 )
  {
    if ( v2 != 1 )
      return;
  }
  else
  {
    bul->act_no = 1;
    switch ( level )
    {
      case 2:
        bul->act_wait = 15;
        break;
      case 3:
        bul->act_wait = 5;
        break;
      case 1:
        bul->act_wait = 10;
        break;
    }
    PlaySoundObject(44, 1);
  }
  if ( level == 2 )
  {
    if ( !(bul->act_wait % 3) )
    {
      v8 = bul->enemyXL;
      v9 = bul->y;
      v10 = (Random(-32, 32) << 9) + v9;
      v11 = bul->x;
      v12 = Random(-32, 32);
      SetDestroyNpCharUp(v11 + (v12 << 9), v10, v8, 2);
    }
  }
  else if ( level == 3 )
  {
    if ( !(bul->act_wait % 3) )
    {
      v13 = bul->enemyXL;
      v14 = bul->y;
      v15 = (Random(-40, 40) << 9) + v14;
      v16 = bul->x;
      v17 = Random(-40, 40);
      SetDestroyNpCharUp(v16 + (v17 << 9), v15, v13, 2);
    }
  }
  else if ( level == 1 && !(bul->act_wait % 3) )
  {
    v3 = bul->enemyXL;
    v4 = bul->y;
    v5 = (Random(-16, 16) << 9) + v4;
    v6 = bul->x;
    v7 = Random(-16, 16);
    SetDestroyNpCharUp(v6 + (v7 << 9), v5, v3, 2);
  }
  if ( --bul->act_wait < 0 )
    bul->cond = 0;
}

void __cdecl ActBullet_Bubblin1($96A7816609F59F56E43A9A5E8F547E1B *bul)
{
  signed int v1;
  signed int v2;
  Sint32 *v3;
  RECT rect[4];
  char v5[8];

  if ( bul->flag & 0x2FF )
  {
    bul->cond = 0;
    SetCaret(bul->x, bul->y, 2, 0);
  }
  else
  {
    if ( !bul->act_no )
    {
      bul->act_no = 1;
      v1 = bul->direct;
      if ( v1 == 1 )
      {
        bul->ym = -1536;
      }
      else if ( v1 > 1 )
      {
        if ( v1 == 2 )
        {
          bul->xm = 1536;
        }
        else if ( v1 == 3 )
        {
          bul->ym = 1536;
        }
      }
      else if ( !bul->direct )
      {
        bul->xm = -1536;
      }
    }
    v2 = bul->direct;
    if ( v2 == 1 )
    {
      bul->ym += 42;
    }
    else if ( v2 > 1 )
    {
      if ( v2 == 2 )
      {
        bul->xm -= 42;
      }
      else if ( v2 == 3 )
      {
        bul->ym -= 42;
      }
    }
    else if ( !bul->direct )
    {
      bul->xm += 42;
    }
    bul->x += bul->xm;
    bul->y += bul->ym;
    if ( ++bul->act_wait > 40 )
    {
      bul->cond = 0;
      SetCaret(bul->x, bul->y, 15, 0);
    }
    rect[0].left = 192;
    rect[0].top = 0;
    rect[0].right = 200;
    rect[0].bottom = 8;
    rect[1].left = 200;
    rect[1].top = 0;
    rect[1].right = 208;
    rect[1].bottom = 8;
    rect[2].left = 208;
    rect[2].top = 0;
    rect[2].right = 216;
    rect[2].bottom = 8;
    rect[3].left = 216;
    rect[3].top = 0;
    rect[3].right = 224;
    rect[3].bottom = 8;
    if ( ++bul->ani_wait > 3 )
    {
      bul->ani_wait = 0;
      ++bul->ani_no;
    }
    if ( bul->ani_no > 3 )
      bul->ani_no = 3;
    v3 = (Sint32 *)&v5[16 * bul->ani_no - 64];
    bul->rect.left = *v3;
    bul->rect.top = v3[1];
    bul->rect.right = v3[2];
    bul->rect.bottom = v3[3];
  }
}


void __cdecl ActBullet_Bubblin2($96A7816609F59F56E43A9A5E8F547E1B *bul)
{
  signed int v1;
  signed int v2;
  Sint32 *v3;
  RECT rect[4];
  bool bDelete;
  char v6[8];

  bDelete = 0;
  if ( !bul->direct && bul->flag & 1 )
    bDelete = 1;
  if ( bul->direct == 2 && bul->flag & 4 )
    bDelete = 1;
  if ( bul->direct == 1 && bul->flag & 2 )
    bDelete = 1;
  if ( bul->direct == 3 && bul->flag & 8 )
    bDelete = 1;
  if ( bDelete )
  {
    bul->cond = 0;
    SetCaret(bul->x, bul->y, 2, 0);
  }
  else
  {
    if ( !bul->act_no )
    {
      bul->act_no = 1;
      v1 = bul->direct;
      if ( v1 == 1 )
      {
        bul->ym = -1536;
        bul->xm = Random(-256, 256);
      }
      else if ( v1 > 1 )
      {
        if ( v1 == 2 )
        {
          bul->xm = 1536;
          bul->ym = Random(-256, 256);
        }
        else if ( v1 == 3 )
        {
          bul->ym = 1536;
          bul->xm = Random(-256, 256);
        }
      }
      else if ( !bul->direct )
      {
        bul->xm = -1536;
        bul->ym = Random(-256, 256);
      }
    }
    v2 = bul->direct;
    if ( v2 == 1 )
    {
      bul->ym += 16;
    }
    else if ( v2 > 1 )
    {
      if ( v2 == 2 )
      {
        bul->xm -= 16;
      }
      else if ( v2 == 3 )
      {
        bul->ym -= 16;
      }
    }
    else if ( !bul->direct )
    {
      bul->xm += 16;
    }
    bul->x += bul->xm;
    bul->y += bul->ym;
    if ( ++bul->act_wait > 60 )
    {
      bul->cond = 0;
      SetCaret(bul->x, bul->y, 15, 0);
    }
    rect[0].left = 192;
    rect[0].top = 8;
    rect[0].right = 200;
    rect[0].bottom = 16;
    rect[1].left = 200;
    rect[1].top = 8;
    rect[1].right = 208;
    rect[1].bottom = 16;
    rect[2].left = 208;
    rect[2].top = 8;
    rect[2].right = 216;
    rect[2].bottom = 16;
    rect[3].left = 216;
    rect[3].top = 8;
    rect[3].right = 224;
    rect[3].bottom = 16;
    if ( ++bul->ani_wait > 3 )
    {
      bul->ani_wait = 0;
      ++bul->ani_no;
    }
    if ( bul->ani_no > 3 )
      bul->ani_no = 3;
    v3 = (Sint32 *)&v6[16 * bul->ani_no - 68];
    bul->rect.left = *v3;
    bul->rect.top = v3[1];
    bul->rect.right = v3[2];
    bul->rect.bottom = v3[3];
  }
}


void __cdecl ActBullet_Bubblin3($96A7816609F59F56E43A9A5E8F547E1B *bul)
{
  signed int v1;
  Sint32 *v2;
  RECT rect[4];
  char v4[8];

  if ( ++bul->act_wait <= 100 && gKey & gKeyShot )
  {
    if ( !bul->act_no )
    {
      bul->act_no = 1;
      v1 = bul->direct;
      if ( v1 == 1 )
      {
        bul->ym = Random(-1024, -512);
        bul->xm = (Random(-4, 4) << 9) / 2;
      }
      else if ( v1 > 1 )
      {
        if ( v1 == 2 )
        {
          bul->xm = Random(512, 1024);
          bul->ym = (Random(-4, 4) << 9) / 2;
        }
        else if ( v1 == 3 )
        {
          bul->ym = Random(128, 256);
          bul->xm = (Random(-4, 4) << 9) / 2;
        }
      }
      else if ( !bul->direct )
      {
        bul->xm = Random(-1024, -512);
        bul->ym = (Random(-4, 4) << 9) / 2;
      }
    }
    if ( bul->x < x )
      bul->xm += 32;
    if ( bul->x > x )
      bul->xm -= 32;
    if ( bul->y < y )
      bul->ym += 32;
    if ( bul->y > y )
      bul->ym -= 32;
    if ( bul->xm < 0 && bul->flag & 1 )
      bul->xm = 1024;
    if ( bul->xm > 0 && bul->flag & 4 )
      bul->xm = -1024;
    if ( bul->ym < 0 && bul->flag & 2 )
      bul->ym = 1024;
    if ( bul->ym > 0 && bul->flag & 8 )
      bul->ym = -1024;
    bul->x += bul->xm;
    bul->y += bul->ym;
    rect[0].left = 240;
    rect[0].top = 16;
    rect[0].right = 248;
    rect[0].bottom = 24;
    rect[1].left = 248;
    rect[1].top = 16;
    rect[1].right = 256;
    rect[1].bottom = 24;
    rect[2].left = 240;
    rect[2].top = 24;
    rect[2].right = 248;
    rect[2].bottom = 32;
    rect[3].left = 248;
    rect[3].top = 24;
    rect[3].right = 256;
    rect[3].bottom = 32;
    if ( ++bul->ani_wait > 3 )
    {
      bul->ani_wait = 0;
      ++bul->ani_no;
    }
    if ( bul->ani_no > 3 )
      bul->ani_no = 3;
    v2 = (Sint32 *)&v4[16 * bul->ani_no - 64];
    bul->rect.left = *v2;
    bul->rect.top = v2[1];
    bul->rect.right = v2[2];
    bul->rect.bottom = v2[3];
  }
  else
  {
    bul->cond = 0;
    SetCaret(bul->x, bul->y, 2, 0);
    PlaySoundObject(100, 1);
    if ( unk_81C858C )
    {
      SetBullet(22, bul->x, bul->y, 1);
    }
    else if ( unk_81C8590 )
    {
      SetBullet(22, bul->x, bul->y, 3);
    }
    else
    {
      SetBullet(22, bul->x, bul->y, dir);
    }
  }
}


void __cdecl ActBullet_Spine($96A7816609F59F56E43A9A5E8F547E1B *bul)
{
  signed int v1;
  int v2;
  int v3;
  signed int v4;
  Sint32 *v5;
  Sint32 *v6;
  Sint32 *v7;
  Sint32 *v8;
  RECT rcDown[2];
  RECT rcRight[2];
  RECT rcLeft[2];
  char v12[8];

  if ( ++bul->count1 > bul->life_count || bul->flag & 8 )
  {
    bul->cond = 0;
    SetCaret(bul->x, bul->y, 3, 0);
  }
  else
  {
    if ( bul->act_no )
    {
      bul->x += bul->xm;
      bul->y += bul->ym;
    }
    else
    {
      bul->act_no = 1;
      v1 = bul->direct;
      if ( v1 == 1 )
      {
        v3 = Random(10, 16);
        bul->ym = (signed int)(((unsigned int)(-512 * v3) >> 31) - (v3 << 9)) >> 1;
      }
      else if ( v1 > 1 )
      {
        if ( v1 == 2 )
        {
          bul->xm = (Random(10, 16) << 9) / 2;
        }
        else if ( v1 == 3 )
        {
          bul->ym = (Random(10, 16) << 9) / 2;
        }
      }
      else if ( !bul->direct )
      {
        v2 = Random(10, 16);
        bul->xm = (signed int)(((unsigned int)(-512 * v2) >> 31) - (v2 << 9)) >> 1;
      }
    }
    if ( ++bul->ani_wait > 1 )
    {
      bul->ani_wait = 0;
      ++bul->ani_no;
    }
    if ( bul->ani_no > 1 )
      bul->ani_no = 0;
    rcLeft[0].left = 224;
    rcLeft[0].top = 0;
    rcLeft[0].right = 232;
    rcLeft[0].bottom = 8;
    rcLeft[1].left = 232;
    rcLeft[1].top = 0;
    rcLeft[1].right = 240;
    rcLeft[1].bottom = 8;
    rcRight[0].left = 224;
    rcRight[0].top = 0;
    rcRight[0].right = 232;
    rcRight[0].bottom = 8;
    rcRight[1].left = 232;
    rcRight[1].top = 0;
    rcRight[1].right = 240;
    rcRight[1].bottom = 8;
    rcDown[0].left = 224;
    rcDown[0].top = 8;
    rcDown[0].right = 232;
    rcDown[0].bottom = 16;
    rcDown[1].left = 232;
    rcDown[1].top = 8;
    rcDown[1].right = 240;
    rcDown[1].bottom = 16;
    v4 = bul->direct;
    if ( v4 == 1 )
    {
      v6 = (Sint32 *)&v12[16 * bul->ani_no - 96];
      bul->rect.left = *v6;
      bul->rect.top = v6[1];
      bul->rect.right = v6[2];
      bul->rect.bottom = v6[3];
    }
    else if ( v4 > 1 )
    {
      if ( v4 == 2 )
      {
        v7 = (Sint32 *)&v12[16 * bul->ani_no - 64];
        bul->rect.left = *v7;
        bul->rect.top = v7[1];
        bul->rect.right = v7[2];
        bul->rect.bottom = v7[3];
      }
      else if ( v4 == 3 )
      {
        v8 = (Sint32 *)&v12[16 * bul->ani_no - 96];
        bul->rect.left = *v8;
        bul->rect.top = v8[1];
        bul->rect.right = v8[2];
        bul->rect.bottom = v8[3];
      }
    }
    else if ( !bul->direct )
    {
      v5 = (Sint32 *)&v12[16 * bul->ani_no - 32];
      bul->rect.left = *v5;
      bul->rect.top = v5[1];
      bul->rect.right = v5[2];
      bul->rect.bottom = v5[3];
    }
  }
}


void __cdecl ActBullet_Sword1($96A7816609F59F56E43A9A5E8F547E1B *bul)
{
  signed int v1;
  $96A7816609F59F56E43A9A5E8F547E1B *v2;
  Sint32 *v3;
  RECT rcRight[4];
  RECT rcLeft[4];
  char v6[8];

  if ( ++bul->count1 <= bul->life_count )
  {
    if ( bul->count1 == 3 )
      bul->bbits &= 0xFFFFFFFB;
    if ( bul->count1 % 5 == 1 )
      PlaySoundObject(34, 1);
    if ( bul->act_no )
    {
      bul->x += bul->xm;
      bul->y += bul->ym;
    }
    else
    {
      bul->act_no = 1;
      v1 = bul->direct;
      if ( v1 == 1 )
      {
        bul->ym = -2048;
      }
      else if ( v1 > 1 )
      {
        if ( v1 == 2 )
        {
          bul->xm = 2048;
        }
        else if ( v1 == 3 )
        {
          bul->ym = 2048;
        }
      }
      else if ( !bul->direct )
      {
        bul->xm = -2048;
      }
    }
    rcLeft[0].left = 0;
    rcLeft[0].top = 48;
    rcLeft[0].right = 16;
    rcLeft[0].bottom = 64;
    rcLeft[1].left = 16;
    rcLeft[1].top = 48;
    rcLeft[1].right = 32;
    rcLeft[1].bottom = 64;
    rcLeft[2].left = 32;
    rcLeft[2].top = 48;
    rcLeft[2].right = 48;
    rcLeft[2].bottom = 64;
    rcLeft[3].left = 48;
    rcLeft[3].top = 48;
    rcLeft[3].right = 64;
    rcLeft[3].bottom = 64;
    rcRight[0].left = 64;
    rcRight[0].top = 48;
    rcRight[0].right = 80;
    rcRight[0].bottom = 64;
    rcRight[1].left = 80;
    rcRight[1].top = 48;
    rcRight[1].right = 96;
    rcRight[1].bottom = 64;
    rcRight[2].left = 96;
    rcRight[2].top = 48;
    rcRight[2].right = 112;
    rcRight[2].bottom = 64;
    rcRight[3].left = 112;
    rcRight[3].top = 48;
    rcRight[3].right = 128;
    rcRight[3].bottom = 64;
    if ( ++bul->ani_wait > 1 )
    {
      bul->ani_wait = 0;
      ++bul->ani_no;
    }
    if ( bul->ani_no > 3 )
      bul->ani_no = 0;
    if ( bul->direct )
    {
      v2 = bul;
      v3 = (Sint32 *)&v6[16 * bul->ani_no - 128];
    }
    else
    {
      v2 = bul;
      v3 = (Sint32 *)&v6[16 * bul->ani_no - 64];
    }
    bul->rect.left = *v3;
    v2->rect.top = v3[1];
    v2->rect.right = v3[2];
    v2->rect.bottom = v3[3];
  }
  else
  {
    bul->cond = 0;
    SetCaret(bul->x, bul->y, 3, 0);
  }
}


void __cdecl ActBullet_Sword2($96A7816609F59F56E43A9A5E8F547E1B *bul)
{
  signed int v1;
  $96A7816609F59F56E43A9A5E8F547E1B *v2;
  Sint32 *v3;
  RECT rcRight[4];
  RECT rcLeft[4];
  char v6[8];

  if ( ++bul->count1 <= bul->life_count )
  {
    if ( bul->count1 == 3 )
      bul->bbits &= 0xFFFFFFFB;
    if ( bul->count1 % 7 == 1 )
      PlaySoundObject(106, 1);
    if ( bul->act_no )
    {
      bul->x += bul->xm;
      bul->y += bul->ym;
    }
    else
    {
      bul->act_no = 1;
      v1 = bul->direct;
      if ( v1 == 1 )
      {
        bul->ym = -2048;
      }
      else if ( v1 > 1 )
      {
        if ( v1 == 2 )
        {
          bul->xm = 2048;
        }
        else if ( v1 == 3 )
        {
          bul->ym = 2048;
        }
      }
      else if ( !bul->direct )
      {
        bul->xm = -2048;
      }
    }
    rcLeft[0].left = 160;
    rcLeft[0].top = 48;
    rcLeft[0].right = 184;
    rcLeft[0].bottom = 72;
    rcLeft[1].left = 184;
    rcLeft[1].top = 48;
    rcLeft[1].right = 208;
    rcLeft[1].bottom = 72;
    rcLeft[2].left = 208;
    rcLeft[2].top = 48;
    rcLeft[2].right = 232;
    rcLeft[2].bottom = 72;
    rcLeft[3].left = 232;
    rcLeft[3].top = 48;
    rcLeft[3].right = 256;
    rcLeft[3].bottom = 72;
    rcRight[0].left = 160;
    rcRight[0].top = 72;
    rcRight[0].right = 184;
    rcRight[0].bottom = 96;
    rcRight[1].left = 184;
    rcRight[1].top = 72;
    rcRight[1].right = 208;
    rcRight[1].bottom = 96;
    rcRight[2].left = 208;
    rcRight[2].top = 72;
    rcRight[2].right = 232;
    rcRight[2].bottom = 96;
    rcRight[3].left = 232;
    rcRight[3].top = 72;
    rcRight[3].right = 256;
    rcRight[3].bottom = 96;
    if ( ++bul->ani_wait > 1 )
    {
      bul->ani_wait = 0;
      ++bul->ani_no;
    }
    if ( bul->ani_no > 3 )
      bul->ani_no = 0;
    if ( bul->direct )
    {
      v2 = bul;
      v3 = (Sint32 *)&v6[16 * bul->ani_no - 128];
    }
    else
    {
      v2 = bul;
      v3 = (Sint32 *)&v6[16 * bul->ani_no - 64];
    }
    bul->rect.left = *v3;
    v2->rect.top = v3[1];
    v2->rect.right = v3[2];
    v2->rect.bottom = v3[3];
  }
  else
  {
    bul->cond = 0;
    SetCaret(bul->x, bul->y, 3, 0);
  }
}


void __cdecl ActBullet_Sword3($96A7816609F59F56E43A9A5E8F547E1B *bul)
{
  int v1;
  signed int v2;
  int v3;
  int v4;
  int v5;
  int v6;
  int v7;
  int v8;
  int v9;
  int v10;
  signed int v11;
  Sint32 *v12;
  Sint32 *v13;
  Sint32 *v14;
  Sint32 *v15;
  RECT rcDown[2];
  RECT rcRight[2];
  RECT rcUp[2];
  RECT rcLeft[2];
  char v20[8];

  rcLeft[0].left = 272;
  rcLeft[0].top = 0;
  rcLeft[0].right = 296;
  rcLeft[0].bottom = 24;
  rcLeft[1].left = 296;
  rcLeft[1].top = 0;
  rcLeft[1].right = 320;
  rcLeft[1].bottom = 24;
  rcUp[0].left = 272;
  rcUp[0].top = 48;
  rcUp[0].right = 296;
  rcUp[0].bottom = 72;
  rcUp[1].left = 296;
  rcUp[1].top = 0;
  rcUp[1].right = 320;
  rcUp[1].bottom = 24;
  rcRight[0].left = 272;
  rcRight[0].top = 24;
  rcRight[0].right = 296;
  rcRight[0].bottom = 48;
  rcRight[1].left = 296;
  rcRight[1].top = 24;
  rcRight[1].right = 320;
  rcRight[1].bottom = 48;
  rcDown[0].left = 296;
  rcDown[0].top = 48;
  rcDown[0].right = 320;
  rcDown[0].bottom = 72;
  rcDown[1].left = 296;
  rcDown[1].top = 24;
  rcDown[1].right = 320;
  rcDown[1].bottom = 48;
  v1 = bul->act_no;
  switch ( v1 )
  {
    case 1:
LABEL_5:
      v2 = bul->direct;
      if ( v2 == 1 )
      {
        bul->ym = -2048;
      }
      else if ( v2 > 1 )
      {
        if ( v2 == 2 )
        {
          bul->xm = 2048;
        }
        else if ( v2 == 3 )
        {
          bul->ym = 2048;
        }
      }
      else if ( !bul->direct )
      {
        bul->xm = -2048;
      }
      if ( bul->life != 100 )
      {
        bul->act_no = 2;
        bul->ani_no = 1;
        bul->damage = -1;
        bul->act_wait = 0;
      }
      if ( ++bul->act_wait % 4 == 1 )
      {
        PlaySoundObject(106, 1);
        ++bul->count1;
        if ( bul->count1 & 1 )
          SetBullet(23, bul->x, bul->y, 0);
        else
          SetBullet(23, bul->x, bul->y, 2);
      }
      if ( ++bul->count1 == 5 )
        bul->bbits &= 0xFFFFFFFB;
      if ( bul->count1 > bul->life_count )
      {
        bul->cond = 0;
        SetCaret(bul->x, bul->y, 3, 0);
        return;
      }
      break;
    case 2:
      bul->xm = 0;
      bul->ym = 0;
      ++bul->act_wait;
      if ( Random(-1, 1) == 0 )
      {
        PlaySoundObject(106, 1);
        if ( Random(0, 1) & 1 )
        {
          v3 = bul->y;
          v4 = (Random(-64, 64) << 9) + v3;
          v5 = bul->x;
          v6 = Random(-64, 64);
          SetBullet(23, v5 + (v6 << 9), v4, 0);
        }
        else
        {
          v7 = bul->y;
          v8 = (Random(-64, 64) << 9) + v7;
          v9 = bul->x;
          v10 = Random(-64, 64);
          SetBullet(23, v9 + (v10 << 9), v8, 2);
        }
      }
      if ( bul->act_wait > 50 )
        bul->cond = 0;
      break;
    case 0:
      bul->act_no = 1;
      bul->xm = 0;
      bul->ym = 0;
      goto LABEL_5;
  }
  bul->x += bul->xm;
  bul->y += bul->ym;
  v11 = bul->direct;
  if ( v11 == 1 )
  {
    v13 = (Sint32 *)&v20[16 * bul->ani_no - 64];
    bul->rect.left = *v13;
    bul->rect.top = v13[1];
    bul->rect.right = v13[2];
    bul->rect.bottom = v13[3];
  }
  else if ( v11 > 1 )
  {
    if ( v11 == 2 )
    {
      v14 = (Sint32 *)&v20[16 * bul->ani_no - 96];
      bul->rect.left = *v14;
      bul->rect.top = v14[1];
      bul->rect.right = v14[2];
      bul->rect.bottom = v14[3];
    }
    else if ( v11 == 3 )
    {
      v15 = (Sint32 *)&v20[16 * bul->ani_no - 128];
      bul->rect.left = *v15;
      bul->rect.top = v15[1];
      bul->rect.right = v15[2];
      bul->rect.bottom = v15[3];
    }
  }
  else if ( !bul->direct )
  {
    v12 = (Sint32 *)&v20[16 * bul->ani_no - 32];
    bul->rect.left = *v12;
    bul->rect.top = v12[1];
    bul->rect.right = v12[2];
    bul->rect.bottom = v12[3];
  }
  if ( bul->act_wait & 1 )
    bul->rect.right = 0;
}


void __cdecl ActBullet_Edge($96A7816609F59F56E43A9A5E8F547E1B *bul)
{
  int v1;
  int v2;
  int v3;
  $96A7816609F59F56E43A9A5E8F547E1B *v4;
  Sint32 *v5;
  RECT rcRight[5];
  RECT rcLeft[5];
  char v8[12];

  v1 = bul->act_no;
  if ( v1 )
  {
    if ( v1 != 1 )
      goto LABEL_18;
  }
  else
  {
    bul->act_no = 1;
    bul->y -= 6144;
    if ( bul->direct )
      v2 = bul->x - 0x2000;
    else
      v2 = bul->x + 0x2000;
    bul->x = v2;
  }
  if ( ++bul->ani_wait > 2 )
  {
    bul->ani_wait = 0;
    ++bul->ani_no;
  }
  if ( bul->direct )
    v3 = bul->x + 1024;
  else
    v3 = bul->x - 1024;
  bul->x = v3;
  bul->y += 1024;
  if ( bul->ani_no == 1 )
    bul->damage = 2;
  else
    bul->damage = 1;
  if ( bul->ani_no > 4 )
    bul->cond = 0;
LABEL_18:
  qmemcpy(rcLeft, &ActBullet_Edge(BULLET *)::C.71, sizeof(rcLeft));
  qmemcpy(rcRight, &ActBullet_Edge(BULLET *)::C.72, sizeof(rcRight));
  if ( bul->direct )
  {
    v4 = bul;
    v5 = (Sint32 *)&v8[16 * bul->ani_no - 160];
  }
  else
  {
    v4 = bul;
    v5 = (Sint32 *)&v8[16 * bul->ani_no - 80];
  }
  bul->rect.left = *v5;
  v4->rect.top = v5[1];
  v4->rect.right = v5[2];
  v4->rect.bottom = v5[3];
}


void __cdecl ActBullet_Drop($96A7816609F59F56E43A9A5E8F547E1B *bul)
{
  if ( ++bul->act_wait > 2 )
    bul->cond = 0;
  bul->rect.left = 0;
  bul->rect.top = 0;
  bul->rect.right = 0;
  bul->rect.bottom = 0;
}

void __cdecl ActBullet_SuperMissile($96A7816609F59F56E43A9A5E8F547E1B *bul, int level)
{
  int v2;
  signed int v3;
  signed int v4;
  unsigned int v5;
  signed int v6;
  signed int v7;
  int v8;
  int v9;
  signed int v10;
  Sint32 *v11;
  Sint32 *v12;
  Sint32 *v13;
  RECT rect2[4];
  RECT rect1[4];
  bool bHit;
  char v17[8];

  if ( ++bul->count1 > bul->life_count )
  {
    bul->cond = 0;
    SetCaret(bul->x, bul->y, 3, 0);
    return;
  }
  bHit = 0;
  if ( bul->life != 10 )
    bHit = 1;
  if ( !bul->direct && bul->flag & 1 )
    bHit = 1;
  if ( bul->direct == 2 && bul->flag & 4 )
    bHit = 1;
  if ( bul->direct == 1 && bul->flag & 2 )
    bHit = 1;
  if ( bul->direct == 3 && bul->flag & 8 )
    bHit = 1;
  if ( !bul->direct && bul->flag & 0x80 )
    bHit = 1;
  if ( !bul->direct && bul->flag & 0x20 )
    bHit = 1;
  if ( bul->direct == 2 && bul->flag & 0x40 )
    bHit = 1;
  if ( bul->direct == 2 && bul->flag & 0x10 )
    bHit = 1;
  if ( bHit )
  {
    SetBullet(level + 30, bul->x, bul->y, 0);
    bul->cond = 0;
  }
  v2 = bul->act_no;
  if ( !v2 )
  {
    bul->act_no = 1;
    v3 = bul->direct;
    if ( v3 != 1 )
    {
      if ( v3 <= 1 )
      {
        if ( bul->direct )
          goto LABEL_43;
LABEL_41:
        bul->tgt_y = bul->y;
        bul->enemyXL = 4096;
        bul->blockXL = 4096;
        goto LABEL_43;
      }
      if ( v3 == 2 )
        goto LABEL_41;
      if ( v3 != 3 )
      {
LABEL_43:
        if ( level != 3 )
        {
          bul->ani_no = 512;
          goto LABEL_67;
        }
        v4 = bul->direct;
        if ( v4 != 1 )
        {
          if ( v4 <= 1 )
          {
            if ( bul->direct )
              goto LABEL_59;
            goto LABEL_51;
          }
          if ( v4 == 2 )
          {
LABEL_51:
            if ( bul->y <= y )
              bul->ym = -256;
            else
              bul->ym = 256;
            bul->xm = Random(-512, 512);
            goto LABEL_59;
          }
          if ( v4 != 3 )
            goto LABEL_59;
        }
        if ( bul->x <= x )
          bul->xm = -256;
        else
          bul->xm = 256;
        bul->ym = Random(-512, 512);
LABEL_59:
        v5 = ++ActBullet_SuperMissile(BULLET *,long)::inc % 3;
        if ( ActBullet_SuperMissile(BULLET *,long)::inc % 3 == 1 )
        {
          bul->ani_no = 256;
        }
        else if ( v5 < 1 )
        {
          bul->ani_no = 512;
        }
        else if ( v5 == 2 )
        {
          bul->ani_no = 170;
        }
LABEL_67:
        v6 = bul->direct;
        if ( v6 == 1 )
        {
          bul->ym -= bul->ani_no;
        }
        else if ( v6 > 1 )
        {
          if ( v6 == 2 )
          {
            bul->xm += bul->ani_no;
          }
          else if ( v6 == 3 )
          {
            bul->ym += bul->ani_no;
          }
        }
        else if ( !bul->direct )
        {
          bul->xm -= bul->ani_no;
        }
        if ( level != 3 )
          goto LABEL_94;
        v7 = bul->direct;
        if ( v7 != 1 )
        {
          if ( v7 <= 1 )
          {
            if ( bul->direct )
            {
LABEL_94:
              if ( bul->xm < -5120 )
                bul->xm = -5120;
              if ( bul->xm > 5120 )
                bul->xm = 5120;
              if ( bul->ym < -5120 )
                bul->ym = -5120;
              if ( bul->ym > 5120 )
                bul->ym = 5120;
              bul->x += bul->xm;
              bul->y += bul->ym;
              goto LABEL_103;
            }
LABEL_86:
            if ( bul->y >= bul->tgt_y )
              v8 = bul->ym - 64;
            else
              v8 = bul->ym + 64;
            bul->ym = v8;
            goto LABEL_94;
          }
          if ( v7 == 2 )
            goto LABEL_86;
          if ( v7 != 3 )
            goto LABEL_94;
        }
        if ( bul->x >= bul->tgt_x )
          v9 = bul->xm - 64;
        else
          v9 = bul->xm + 64;
        bul->xm = v9;
        goto LABEL_94;
      }
    }
    bul->tgt_x = bul->x;
    bul->enemyYL = 4096;
    bul->blockYL = 4096;
    goto LABEL_43;
  }
  if ( v2 == 1 )
    goto LABEL_67;
LABEL_103:
  if ( ++bul->count2 > 2 )
  {
    bul->count2 = 0;
    v10 = bul->direct;
    if ( v10 == 1 )
    {
      SetCaret(bul->x, bul->y + 4096, 7, 3);
    }
    else if ( v10 > 1 )
    {
      if ( v10 == 2 )
      {
        SetCaret(bul->x - 4096, bul->y, 7, 0);
      }
      else if ( v10 == 3 )
      {
        SetCaret(bul->x, bul->y - 4096, 7, 1);
      }
    }
    else if ( !bul->direct )
    {
      SetCaret(bul->x + 4096, bul->y, 7, 2);
    }
  }
  rect1[0].left = 120;
  rect1[0].top = 96;
  rect1[0].right = 136;
  rect1[0].bottom = 112;
  rect1[1].left = 136;
  rect1[1].top = 96;
  rect1[1].right = 152;
  rect1[1].bottom = 112;
  rect1[2].left = 152;
  rect1[2].top = 96;
  rect1[2].right = 168;
  rect1[2].bottom = 112;
  rect1[3].left = 168;
  rect1[3].top = 96;
  rect1[3].right = 184;
  rect1[3].bottom = 112;
  rect2[0].left = 184;
  rect2[0].top = 96;
  rect2[0].right = 200;
  rect2[0].bottom = 112;
  rect2[1].left = 200;
  rect2[1].top = 96;
  rect2[1].right = 216;
  rect2[1].bottom = 112;
  rect2[2].left = 216;
  rect2[2].top = 96;
  rect2[2].right = 232;
  rect2[2].bottom = 112;
  rect2[3].left = 232;
  rect2[3].top = 96;
  rect2[3].right = 248;
  rect2[3].bottom = 112;
  switch ( level )
  {
    case 2:
      v12 = (Sint32 *)&v17[16 * bul->direct - 132];
      bul->rect.left = *v12;
      bul->rect.top = v12[1];
      bul->rect.right = v12[2];
      bul->rect.bottom = v12[3];
      break;
    case 3:
      v13 = (Sint32 *)&v17[16 * bul->direct - 68];
      bul->rect.left = *v13;
      bul->rect.top = v13[1];
      bul->rect.right = v13[2];
      bul->rect.bottom = v13[3];
      break;
    case 1:
      v11 = (Sint32 *)&v17[16 * bul->direct - 68];
      bul->rect.left = *v11;
      bul->rect.top = v11[1];
      bul->rect.right = v11[2];
      bul->rect.bottom = v11[3];
      break;
  }
}


void __cdecl ActBullet_SuperBom($96A7816609F59F56E43A9A5E8F547E1B *bul, int level)
{
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

  v2 = bul->act_no;
  if ( v2 )
  {
    if ( v2 != 1 )
      return;
  }
  else
  {
    bul->act_no = 1;
    switch ( level )
    {
      case 2:
        bul->act_wait = 14;
        break;
      case 3:
        bul->act_wait = 6;
        break;
      case 1:
        bul->act_wait = 10;
        break;
    }
    PlaySoundObject(44, 1);
  }
  if ( level == 2 )
  {
    if ( !(bul->act_wait % 3) )
    {
      v8 = bul->enemyXL;
      v9 = bul->y;
      v10 = (Random(-32, 32) << 9) + v9;
      v11 = bul->x;
      v12 = Random(-32, 32);
      SetDestroyNpCharUp(v11 + (v12 << 9), v10, v8, 2);
    }
  }
  else if ( level == 3 )
  {
    if ( !(bul->act_wait % 3) )
    {
      v13 = bul->enemyXL;
      v14 = bul->y;
      v15 = (Random(-40, 40) << 9) + v14;
      v16 = bul->x;
      v17 = Random(-40, 40);
      SetDestroyNpCharUp(v16 + (v17 << 9), v15, v13, 2);
    }
  }
  else if ( level == 1 && !(bul->act_wait % 3) )
  {
    v3 = bul->enemyXL;
    v4 = bul->y;
    v5 = (Random(-16, 16) << 9) + v4;
    v6 = bul->x;
    v7 = Random(-16, 16);
    SetDestroyNpCharUp(v6 + (v7 << 9), v5, v3, 2);
  }
  if ( --bul->act_wait < 0 )
    bul->cond = 0;
}

void __cdecl ActBullet_Nemesis($96A7816609F59F56E43A9A5E8F547E1B *bul, int level)
{
  signed int v2;
  signed int v3;
  int v4;
  int v5;
  int v6;
  int v7;
  signed int v8;
  Sint32 *v9;
  Sint32 *v10;
  Sint32 *v11;
  Sint32 *v12;
  RECT rcD[2];
  RECT rcR[2];
  RECT rcU[2];
  RECT rcL[2];
  char v17[8];

  if ( ++bul->count1 <= bul->life_count )
  {
    if ( bul->act_no )
    {
      if ( level == 1 && bul->count1 % 4 == 1 )
      {
        v3 = bul->direct;
        if ( v3 == 1 )
        {
          v5 = Random(-512, 512);
          SetNpChar(4, bul->x, bul->y, v5, -512, 2, 0, 256);
        }
        else if ( v3 > 1 )
        {
          if ( v3 == 2 )
          {
            v6 = Random(-512, 512);
            SetNpChar(4, bul->x, bul->y, 512, v6, 2, 0, 256);
          }
          else if ( v3 == 3 )
          {
            v7 = Random(-512, 512);
            SetNpChar(4, bul->x, bul->y, v7, 512, 2, 0, 256);
          }
        }
        else if ( !bul->direct )
        {
          v4 = Random(-512, 512);
          SetNpChar(4, bul->x, bul->y, -512, v4, 2, 0, 256);
        }
      }
      bul->x += bul->xm;
      bul->y += bul->ym;
    }
    else
    {
      bul->act_no = 1;
      bul->count1 = 0;
      v2 = bul->direct;
      if ( v2 == 1 )
      {
        bul->ym = -4096;
      }
      else if ( v2 > 1 )
      {
        if ( v2 == 2 )
        {
          bul->xm = 4096;
        }
        else if ( v2 == 3 )
        {
          bul->ym = 4096;
        }
      }
      else if ( !bul->direct )
      {
        bul->xm = -4096;
      }
      if ( level != 2 && level == 3 )
      {
        bul->xm /= 3;
        bul->ym /= 3;
      }
    }
    if ( ++bul->ani_no > 1 )
      bul->ani_no = 0;
    rcL[0].left = 0;
    rcL[0].top = 112;
    rcL[0].right = 32;
    rcL[0].bottom = 128;
    rcL[1].left = 0;
    rcL[1].top = 128;
    rcL[1].right = 32;
    rcL[1].bottom = 144;
    rcU[0].left = 32;
    rcU[0].top = 112;
    rcU[0].right = 48;
    rcU[0].bottom = 144;
    rcU[1].left = 48;
    rcU[1].top = 112;
    rcU[1].right = 64;
    rcU[1].bottom = 144;
    rcR[0].left = 64;
    rcR[0].top = 112;
    rcR[0].right = 96;
    rcR[0].bottom = 128;
    rcR[1].left = 64;
    rcR[1].top = 128;
    rcR[1].right = 96;
    rcR[1].bottom = 144;
    rcD[0].left = 96;
    rcD[0].top = 112;
    rcD[0].right = 112;
    rcD[0].bottom = 144;
    rcD[1].left = 112;
    rcD[1].top = 112;
    rcD[1].right = 128;
    rcD[1].bottom = 144;
    v8 = bul->direct;
    if ( v8 == 1 )
    {
      v10 = (Sint32 *)&v17[16 * bul->ani_no - 64];
      bul->rect.left = *v10;
      bul->rect.top = v10[1];
      bul->rect.right = v10[2];
      bul->rect.bottom = v10[3];
    }
    else if ( v8 > 1 )
    {
      if ( v8 == 2 )
      {
        v11 = (Sint32 *)&v17[16 * bul->ani_no - 96];
        bul->rect.left = *v11;
        bul->rect.top = v11[1];
        bul->rect.right = v11[2];
        bul->rect.bottom = v11[3];
      }
      else if ( v8 == 3 )
      {
        v12 = (Sint32 *)&v17[16 * bul->ani_no - 128];
        bul->rect.left = *v12;
        bul->rect.top = v12[1];
        bul->rect.right = v12[2];
        bul->rect.bottom = v12[3];
      }
    }
    else if ( !bul->direct )
    {
      v9 = (Sint32 *)&v17[16 * bul->ani_no - 32];
      bul->rect.left = *v9;
      bul->rect.top = v9[1];
      bul->rect.right = v9[2];
      bul->rect.bottom = v9[3];
    }
    bul->rect.top += 32 * ((level - 1) / 2);
    bul->rect.bottom += 32 * ((level - 1) / 2);
    bul->rect.left += (level - 1) % 2 << 7;
    bul->rect.right += (level - 1) % 2 << 7;
  }
  else
  {
    bul->cond = 0;
    SetCaret(bul->x, bul->y, 3, 0);
  }
}


void __cdecl ActBullet_Spur($96A7816609F59F56E43A9A5E8F547E1B *bul, int level)
{
  signed int v2;
  signed int v3;
  signed int v4;

  if ( ++bul->count1 <= bul->life_count )
  {
    if ( bul->damage && bul->life != 100 )
      bul->damage = 0;
    if ( bul->act_no )
    {
      bul->x += bul->xm;
      bul->y += bul->ym;
    }
    else
    {
      bul->act_no = 1;
      v2 = bul->direct;
      if ( v2 == 1 )
      {
        bul->ym = -4096;
      }
      else if ( v2 > 1 )
      {
        if ( v2 == 2 )
        {
          bul->xm = 4096;
        }
        else if ( v2 == 3 )
        {
          bul->ym = 4096;
        }
      }
      else if ( !bul->direct )
      {
        bul->xm = -4096;
      }
      if ( level == 1 )
      {
        v3 = bul->direct;
        if ( v3 == 1 )
        {
          bul->enemyXL = 1024;
        }
        else if ( v3 > 1 )
        {
          if ( v3 == 2 )
          {
            bul->enemyYL = 1024;
          }
          else if ( v3 == 3 )
          {
            bul->enemyXL = 1024;
          }
        }
        else if ( !bul->direct )
        {
          bul->enemyYL = 1024;
        }
      }
      else if ( level == 2 )
      {
        v4 = bul->direct;
        if ( v4 == 1 )
        {
          bul->enemyXL = 2048;
        }
        else if ( v4 > 1 )
        {
          if ( v4 == 2 )
          {
            bul->enemyYL = 2048;
          }
          else if ( v4 == 3 )
          {
            bul->enemyXL = 2048;
          }
        }
        else if ( !bul->direct )
        {
          bul->enemyYL = 2048;
        }
      }
    }
    bul->damage = bul->life;
    switch ( level )
    {
      case 2:
        if ( bul->direct != 1 && bul->direct != 3 )
        {
          bul->rect.left = 160;
          bul->rect.top = 32;
          bul->rect.right = 176;
          bul->rect.bottom = 48;
        }
        else
        {
          bul->rect.left = 176;
          bul->rect.top = 32;
          bul->rect.right = 192;
          bul->rect.bottom = 48;
        }
        break;
      case 3:
        if ( bul->direct != 1 && bul->direct != 3 )
        {
          bul->rect.left = 128;
          bul->rect.top = 48;
          bul->rect.right = 144;
          bul->rect.bottom = 64;
        }
        else
        {
          bul->rect.left = 144;
          bul->rect.top = 48;
          bul->rect.right = 160;
          bul->rect.bottom = 64;
        }
        break;
      case 1:
        if ( bul->direct != 1 && bul->direct != 3 )
        {
          bul->rect.left = 128;
          bul->rect.top = 32;
          bul->rect.right = 144;
          bul->rect.bottom = 48;
        }
        else
        {
          bul->rect.left = 144;
          bul->rect.top = 32;
          bul->rect.right = 160;
          bul->rect.bottom = 48;
        }
        break;
    }
    SetBullet(level + 39, bul->x, bul->y, bul->direct);
  }
  else
  {
    bul->cond = 0;
    SetCaret(bul->x, bul->y, 3, 0);
  }
}

void __cdecl ActBullet_SpurTail($96A7816609F59F56E43A9A5E8F547E1B *bul, int level)
{
  RECT *v2;
  RECT *v3;
  RECT *v4;
  RECT *v5;
  RECT *v6;
  RECT *v7;
  RECT rc_v_lv3[3];
  RECT rc_h_lv3[3];
  RECT rc_v_lv2[3];
  RECT rc_h_lv2[3];
  RECT rc_v_lv1[3];
  RECT rc_h_lv1[3];

  if ( ++bul->count1 > 20 )
    bul->ani_no = bul->count1 - 20;
  if ( bul->ani_no > 2 )
    bul->cond = 0;
  if ( bul->damage && bul->life != 100 )
    bul->damage = 0;
  rc_h_lv1[0].left = 192;
  rc_h_lv1[0].top = 32;
  rc_h_lv1[0].right = 200;
  rc_h_lv1[0].bottom = 40;
  rc_h_lv1[1].left = 200;
  rc_h_lv1[1].top = 32;
  rc_h_lv1[1].right = 208;
  rc_h_lv1[1].bottom = 40;
  rc_h_lv1[2].left = 208;
  rc_h_lv1[2].top = 32;
  rc_h_lv1[2].right = 216;
  rc_h_lv1[2].bottom = 40;
  rc_v_lv1[0].left = 192;
  rc_v_lv1[0].top = 40;
  rc_v_lv1[0].right = 200;
  rc_v_lv1[0].bottom = 48;
  rc_v_lv1[1].left = 200;
  rc_v_lv1[1].top = 40;
  rc_v_lv1[1].right = 208;
  rc_v_lv1[1].bottom = 48;
  rc_v_lv1[2].left = 208;
  rc_v_lv1[2].top = 40;
  rc_v_lv1[2].right = 216;
  rc_v_lv1[2].bottom = 48;
  rc_h_lv2[0].left = 216;
  rc_h_lv2[0].top = 32;
  rc_h_lv2[0].right = 224;
  rc_h_lv2[0].bottom = 40;
  rc_h_lv2[1].left = 224;
  rc_h_lv2[1].top = 32;
  rc_h_lv2[1].right = 232;
  rc_h_lv2[1].bottom = 40;
  rc_h_lv2[2].left = 232;
  rc_h_lv2[2].top = 32;
  rc_h_lv2[2].right = 240;
  rc_h_lv2[2].bottom = 40;
  rc_v_lv2[0].left = 216;
  rc_v_lv2[0].top = 40;
  rc_v_lv2[0].right = 224;
  rc_v_lv2[0].bottom = 48;
  rc_v_lv2[1].left = 224;
  rc_v_lv2[1].top = 40;
  rc_v_lv2[1].right = 232;
  rc_v_lv2[1].bottom = 48;
  rc_v_lv2[2].left = 232;
  rc_v_lv2[2].top = 40;
  rc_v_lv2[2].right = 240;
  rc_v_lv2[2].bottom = 48;
  rc_h_lv3[0].left = 240;
  rc_h_lv3[0].top = 32;
  rc_h_lv3[0].right = 248;
  rc_h_lv3[0].bottom = 40;
  rc_h_lv3[1].left = 248;
  rc_h_lv3[1].top = 32;
  rc_h_lv3[1].right = 256;
  rc_h_lv3[1].bottom = 40;
  rc_h_lv3[2].left = 256;
  rc_h_lv3[2].top = 32;
  rc_h_lv3[2].right = 264;
  rc_h_lv3[2].bottom = 40;
  rc_v_lv3[0].left = 240;
  rc_v_lv3[0].top = 32;
  rc_v_lv3[0].right = 248;
  rc_v_lv3[0].bottom = 40;
  rc_v_lv3[1].left = 248;
  rc_v_lv3[1].top = 32;
  rc_v_lv3[1].right = 256;
  rc_v_lv3[1].bottom = 40;
  rc_v_lv3[2].left = 256;
  rc_v_lv3[2].top = 32;
  rc_v_lv3[2].right = 264;
  rc_v_lv3[2].bottom = 40;
  switch ( level )
  {
    case 2:
      if ( bul->direct && bul->direct != 2 )
      {
        v5 = &rc_v_lv2[bul->ani_no];
        bul->rect.left = v5->left;
        bul->rect.top = v5->top;
        bul->rect.right = v5->right;
        bul->rect.bottom = v5->bottom;
      }
      else
      {
        v4 = &rc_h_lv2[bul->ani_no];
        bul->rect.left = v4->left;
        bul->rect.top = v4->top;
        bul->rect.right = v4->right;
        bul->rect.bottom = v4->bottom;
      }
      break;
    case 3:
      if ( bul->direct && bul->direct != 2 )
      {
        v7 = &rc_v_lv3[bul->ani_no];
        bul->rect.left = v7->left;
        bul->rect.top = v7->top;
        bul->rect.right = v7->right;
        bul->rect.bottom = v7->bottom;
      }
      else
      {
        v6 = &rc_h_lv3[bul->ani_no];
        bul->rect.left = v6->left;
        bul->rect.top = v6->top;
        bul->rect.right = v6->right;
        bul->rect.bottom = v6->bottom;
      }
      break;
    case 1:
      if ( bul->direct && bul->direct != 2 )
      {
        v3 = &rc_v_lv1[bul->ani_no];
        bul->rect.left = v3->left;
        bul->rect.top = v3->top;
        bul->rect.right = v3->right;
        bul->rect.bottom = v3->bottom;
      }
      else
      {
        v2 = &rc_h_lv1[bul->ani_no];
        bul->rect.left = v2->left;
        bul->rect.top = v2->top;
        bul->rect.right = v2->right;
        bul->rect.bottom = v2->bottom;
      }
      break;
  }
}

void __cdecl ActBullet_EnemyClear($96A7816609F59F56E43A9A5E8F547E1B *bul)
{
  if ( ++bul->count1 <= bul->life_count )
  {
    bul->damage = 10000;
    bul->enemyXL = 819200;
    bul->enemyYL = 819200;
  }
  else
  {
    bul->cond = 0;
  }
}

void __cdecl ActBullet_Star($96A7816609F59F56E43A9A5E8F547E1B *bul)
{
  if ( ++bul->count1 > bul->life_count )
    bul->cond = 0;
}

void ActBullet()
{
  int i;

  for ( i = 0; i <= 63; ++i )
  {
    if ( gBul[i].cond & 0x80 )
    {
      if ( gBul[i].life > 0 )
      {
        switch ( gBul[i].code_bullet )
        {
          case 1:
            ActBullet_Frontia1(($96A7816609F59F56E43A9A5E8F547E1B *)((i << 7) + 136090016));
            break;
          case 2:
            ActBullet_Frontia2(($96A7816609F59F56E43A9A5E8F547E1B *)((i << 7) + 136090016), 2);
            break;
          case 3:
            ActBullet_Frontia2(($96A7816609F59F56E43A9A5E8F547E1B *)((i << 7) + 136090016), 3);
            break;
          case 4:
            ActBullet_PoleStar(($96A7816609F59F56E43A9A5E8F547E1B *)((i << 7) + 136090016), 1);
            break;
          case 5:
            ActBullet_PoleStar(($96A7816609F59F56E43A9A5E8F547E1B *)((i << 7) + 136090016), 2);
            break;
          case 6:
            ActBullet_PoleStar(($96A7816609F59F56E43A9A5E8F547E1B *)((i << 7) + 136090016), 3);
            break;
          case 7:
            ActBullet_FireBall(($96A7816609F59F56E43A9A5E8F547E1B *)((i << 7) + 136090016), 1);
            break;
          case 8:
            ActBullet_FireBall(($96A7816609F59F56E43A9A5E8F547E1B *)((i << 7) + 136090016), 2);
            break;
          case 9:
            ActBullet_FireBall(($96A7816609F59F56E43A9A5E8F547E1B *)((i << 7) + 136090016), 3);
            break;
          case 0xA:
            ActBullet_MachineGun(($96A7816609F59F56E43A9A5E8F547E1B *)((i << 7) + 136090016), 1);
            break;
          case 0xB:
            ActBullet_MachineGun(($96A7816609F59F56E43A9A5E8F547E1B *)((i << 7) + 136090016), 2);
            break;
          case 0xC:
            ActBullet_MachineGun(($96A7816609F59F56E43A9A5E8F547E1B *)((i << 7) + 136090016), 3);
            break;
          case 0xD:
            ActBullet_Missile(($96A7816609F59F56E43A9A5E8F547E1B *)((i << 7) + 136090016), 1);
            break;
          case 0xE:
            ActBullet_Missile(($96A7816609F59F56E43A9A5E8F547E1B *)((i << 7) + 136090016), 2);
            break;
          case 0xF:
            ActBullet_Missile(($96A7816609F59F56E43A9A5E8F547E1B *)((i << 7) + 136090016), 3);
            break;
          case 0x10:
            ActBullet_Bom(($96A7816609F59F56E43A9A5E8F547E1B *)((i << 7) + 136090016), 1);
            break;
          case 0x11:
            ActBullet_Bom(($96A7816609F59F56E43A9A5E8F547E1B *)((i << 7) + 136090016), 2);
            break;
          case 0x12:
            ActBullet_Bom(($96A7816609F59F56E43A9A5E8F547E1B *)((i << 7) + 136090016), 3);
            break;
          case 0x13:
            ActBullet_Bubblin1(($96A7816609F59F56E43A9A5E8F547E1B *)((i << 7) + 136090016));
            break;
          case 0x14:
            ActBullet_Bubblin2(($96A7816609F59F56E43A9A5E8F547E1B *)((i << 7) + 136090016));
            break;
          case 0x15:
            ActBullet_Bubblin3(($96A7816609F59F56E43A9A5E8F547E1B *)((i << 7) + 136090016));
            break;
          case 0x16:
            ActBullet_Spine(($96A7816609F59F56E43A9A5E8F547E1B *)((i << 7) + 136090016));
            break;
          case 0x17:
            ActBullet_Edge(($96A7816609F59F56E43A9A5E8F547E1B *)((i << 7) + 136090016));
            break;
          case 0x18:
            ActBullet_Drop(($96A7816609F59F56E43A9A5E8F547E1B *)((i << 7) + 136090016));
            break;
          case 0x19:
            ActBullet_Sword1(($96A7816609F59F56E43A9A5E8F547E1B *)((i << 7) + 136090016));
            break;
          case 0x1A:
            ActBullet_Sword2(($96A7816609F59F56E43A9A5E8F547E1B *)((i << 7) + 136090016));
            break;
          case 0x1B:
            ActBullet_Sword3(($96A7816609F59F56E43A9A5E8F547E1B *)((i << 7) + 136090016));
            break;
          case 0x1C:
            ActBullet_SuperMissile(($96A7816609F59F56E43A9A5E8F547E1B *)((i << 7) + 136090016), 1);
            break;
          case 0x1D:
            ActBullet_SuperMissile(($96A7816609F59F56E43A9A5E8F547E1B *)((i << 7) + 136090016), 2);
            break;
          case 0x1E:
            ActBullet_SuperMissile(($96A7816609F59F56E43A9A5E8F547E1B *)((i << 7) + 136090016), 3);
            break;
          case 0x1F:
            ActBullet_SuperBom(($96A7816609F59F56E43A9A5E8F547E1B *)((i << 7) + 136090016), 1);
            break;
          case 0x20:
            ActBullet_SuperBom(($96A7816609F59F56E43A9A5E8F547E1B *)((i << 7) + 136090016), 2);
            break;
          case 0x21:
            ActBullet_SuperBom(($96A7816609F59F56E43A9A5E8F547E1B *)((i << 7) + 136090016), 3);
            break;
          case 0x22:
            ActBullet_Nemesis(($96A7816609F59F56E43A9A5E8F547E1B *)((i << 7) + 136090016), 1);
            break;
          case 0x23:
            ActBullet_Nemesis(($96A7816609F59F56E43A9A5E8F547E1B *)((i << 7) + 136090016), 2);
            break;
          case 0x24:
            ActBullet_Nemesis(($96A7816609F59F56E43A9A5E8F547E1B *)((i << 7) + 136090016), 3);
            break;
          case 0x25:
            ActBullet_Spur(($96A7816609F59F56E43A9A5E8F547E1B *)((i << 7) + 136090016), 1);
            break;
          case 0x26:
            ActBullet_Spur(($96A7816609F59F56E43A9A5E8F547E1B *)((i << 7) + 136090016), 2);
            break;
          case 0x27:
            ActBullet_Spur(($96A7816609F59F56E43A9A5E8F547E1B *)((i << 7) + 136090016), 3);
            break;
          case 0x28:
            ActBullet_SpurTail(($96A7816609F59F56E43A9A5E8F547E1B *)((i << 7) + 136090016), 1);
            break;
          case 0x29:
            ActBullet_SpurTail(($96A7816609F59F56E43A9A5E8F547E1B *)((i << 7) + 136090016), 2);
            break;
          case 0x2A:
            ActBullet_SpurTail(($96A7816609F59F56E43A9A5E8F547E1B *)((i << 7) + 136090016), 3);
            break;
          case 0x2B:
            ActBullet_Nemesis(($96A7816609F59F56E43A9A5E8F547E1B *)((i << 7) + 136090016), 1);
            break;
          case 0x2C:
            ActBullet_EnemyClear(($96A7816609F59F56E43A9A5E8F547E1B *)((i << 7) + 136090016));
            break;
          case 0x2D:
            ActBullet_Star(($96A7816609F59F56E43A9A5E8F547E1B *)((i << 7) + 136090016));
            break;
          default:
            continue;
        }
      }
      else
      {
        gBul[i].cond = 0;
      }
    }
  }
}

signed int IsActiveSomeBullet()
{
  unsigned int v0;
  int i;

  for ( i = 0; i <= 63; ++i )
  {
    if ( gBul[i].cond & 0x80 )
    {
      v0 = gBul[i].code_bullet - 13;
      if ( v0 <= 0x14 )
      {
        if ( (1 << v0) & 0x1FF43F )
          return 1;
      }
    }
  }
  return 0;
}

