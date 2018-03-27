//#include "types.h"
#include "SDL_stdinc.h"
#include "windows_wrapper.h"
#include "Tags.h"

void JadgeHitNpCharBlock(NPCHAR *npc, int x, int y);
void JudgeHitNpCharTriangleA(NPCHAR *npc, int x, int y);
void JudgeHitNpCharTriangleB(NPCHAR *npc, int x, int y);
void JudgeHitNpCharTriangleC(NPCHAR *npc, int x, int y);
void JudgeHitNpCharTriangleD(NPCHAR *npc, int x, int y);
void JudgeHitNpCharTriangleE(NPCHAR *npc, int x, int y);
void JudgeHitNpCharTriangleF(NPCHAR *npc, int x, int y);
void JudgeHitNpCharTriangleG(NPCHAR *npc, int x, int y);
void JudgeHitNpCharTriangleH(NPCHAR *npc, int x, int y);
void JudgeHitNpCharWater(NPCHAR *npc, int x, int y);
void HitNpCharMap();
void LoseNpChar(NPCHAR *npc, bool bVanish);
void HitNpCharBullet();


void JadgeHitNpCharBlock(NPCHAR *npc, int x, int y)
{
  int hit;

  hit = 0;
  if ( npc->y - npc->hit.top < ((2 * y + 1) << 12) - 1536
    && npc->hit.bottom + npc->y > ((2 * y - 1) << 12) + 1536
    && npc->x - npc->hit.back < (2 * x + 1) << 12
    && npc->x - npc->hit.back > x << 13 )
  {
    npc->x = npc->hit.back + ((2 * x + 1) << 12);
    hit = 1;
  }
  if ( npc->y - npc->hit.top < ((2 * y + 1) << 12) - 1536
    && npc->hit.bottom + npc->y > ((2 * y - 1) << 12) + 1536
    && npc->hit.back + npc->x > (2 * x - 1) << 12
    && npc->hit.back + npc->x < x << 13 )
  {
    npc->x = ((2 * x - 1) << 12) - npc->hit.back;
    hit |= 4u;
  }
  if ( npc->x - npc->hit.back < ((2 * x + 1) << 12) - 1536
    && npc->hit.back + npc->x > ((2 * x - 1) << 12) + 1536
    && npc->y - npc->hit.top < (2 * y + 1) << 12
    && npc->y - npc->hit.top > y << 13 )
  {
    npc->y = npc->hit.top + ((2 * y + 1) << 12);
    npc->ym = 0;
    hit |= 2u;
  }
  if ( npc->x - npc->hit.back < ((2 * x + 1) << 12) - 1536
    && npc->hit.back + npc->x > ((2 * x - 1) << 12) + 1536
    && npc->hit.bottom + npc->y > (2 * y - 1) << 12
    && npc->hit.bottom + npc->y < y << 13 )
  {
    npc->y = ((2 * y - 1) << 12) - npc->hit.bottom;
    npc->ym = 0;
    hit |= 8u;
  }
  npc->flag |= hit;
}

void JudgeHitNpCharTriangleA(NPCHAR *npc, int x, int y)
{
  int hit;

  hit = 0;
  if ( npc->x < (2 * x + 1) << 12
    && npc->x > (2 * x - 1) << 12
    && npc->y - npc->hit.top < (y << 13) - (-8192 * x + npc->x) / 2 + 2048
    && npc->hit.bottom + npc->y > (2 * y - 1) << 12 )
  {
    npc->y = npc->hit.top + (y << 13) - (-8192 * x + npc->x) / 2 + 2048;
    if ( npc->ym < 0 )
      npc->ym = 0;
    hit = 2;
  }
  npc->flag |= hit;
}

void JudgeHitNpCharTriangleB(NPCHAR *npc, int x, int y)
{
  int hit;

  hit = 0;
  if ( npc->x < (2 * x + 1) << 12
    && npc->x > (2 * x - 1) << 12
    && npc->y - npc->hit.top < (y << 13) - (-8192 * x + npc->x) / 2 - 2048
    && npc->hit.bottom + npc->y > (2 * y - 1) << 12 )
  {
    npc->y = npc->hit.top + (y << 13) - (-8192 * x + npc->x) / 2 - 2048;
    if ( npc->ym < 0 )
      npc->ym = 0;
    hit = 2;
  }
  npc->flag |= hit;
}

void JudgeHitNpCharTriangleC(NPCHAR *npc, int x, int y)
{
  int hit;

  hit = 0;
  if ( npc->x < (2 * x + 1) << 12
    && npc->x > (2 * x - 1) << 12
    && npc->y - npc->hit.top < (y << 13) + (-8192 * x + npc->x) / 2 - 2048
    && npc->hit.bottom + npc->y > (2 * y - 1) << 12 )
  {
    npc->y = npc->hit.top + (y << 13) + (-8192 * x + npc->x) / 2 - 2048;
    if ( npc->ym < 0 )
      npc->ym = 0;
    hit = 2;
  }
  npc->flag |= hit;
}

void JudgeHitNpCharTriangleD(NPCHAR *npc, int x, int y)
{
  int hit;

  hit = 0;
  if ( npc->x < (2 * x + 1) << 12
    && npc->x > (2 * x - 1) << 12
    && npc->y - npc->hit.top < (y << 13) + (-8192 * x + npc->x) / 2 + 2048
    && npc->hit.bottom + npc->y > (2 * y - 1) << 12 )
  {
    npc->y = npc->hit.top + (y << 13) + (-8192 * x + npc->x) / 2 + 2048;
    if ( npc->ym < 0 )
      npc->ym = 0;
    hit = 2;
  }
  npc->flag |= hit;
}

void JudgeHitNpCharTriangleE(NPCHAR *npc, int x, int y)
{
  int hit;

  hit = 0x10000;
  if ( npc->x < (2 * x + 1) << 12
    && npc->x > (2 * x - 1) << 12
    && npc->y + npc->hit.bottom > (y << 13) + (-8192 * x + npc->x) / 2 - 2048
    && npc->y - npc->hit.top < (2 * y + 1) << 12 )
  {
    npc->y = (y << 13) + (-8192 * x + npc->x) / 2 - 2048 - npc->hit.bottom;
    if ( npc->ym > 0 )
      npc->ym = 0;
    hit = 65576;
  }
  npc->flag |= hit;
}

void JudgeHitNpCharTriangleF(NPCHAR *npc, int x, int y)
{
  int hit;

  hit = 0x20000;
  if ( npc->x < (2 * x + 1) << 12
    && npc->x >= (2 * x - 1) << 12
    && npc->y + npc->hit.bottom > (y << 13) + (-8192 * x + npc->x) / 2 + 2048
    && npc->y - npc->hit.top < (2 * y + 1) << 12 )
  {
    npc->y = (y << 13) + (-8192 * x + npc->x) / 2 + 2048 - npc->hit.bottom;
    if ( npc->ym > 0 )
      npc->ym = 0;
    hit = 131112;
  }
  npc->flag |= hit;
}

void JudgeHitNpCharTriangleG(NPCHAR *npc, int x, int y)
{
  int hit;

  hit = 0x40000;
  if ( npc->x < (2 * x + 1) << 12
    && npc->x > (2 * x - 1) << 12
    && npc->y + npc->hit.bottom > (y << 13) - (-8192 * x + npc->x) / 2 + 2048
    && npc->y - npc->hit.top < (2 * y + 1) << 12 )
  {
    npc->y = (y << 13) - (-8192 * x + npc->x) / 2 + 2048 - npc->hit.bottom;
    if ( npc->ym > 0 )
      npc->ym = 0;
    hit = 262168;
  }
  npc->flag |= hit;
}

void JudgeHitNpCharTriangleH(NPCHAR *npc, int x, int y)
{
  int hit;

  hit = 0x80000;
  if ( npc->x < (2 * x + 1) << 12
    && npc->x > (2 * x - 1) << 12
    && npc->y + npc->hit.bottom > (y << 13) - (-8192 * x + npc->x) / 2 - 2048
    && npc->y - npc->hit.top < (2 * y + 1) << 12 )
  {
    npc->y = (y << 13) - (-8192 * x + npc->x) / 2 - 2048 - npc->hit.bottom;
    if ( npc->ym > 0 )
      npc->ym = 0;
    hit = 524312;
  }
  npc->flag |= hit;
}

void JudgeHitNpCharWater(NPCHAR *npc, int x, int y)
{
  int hit;

  hit = 0;
  if ( npc->x - npc->hit.back < (4 * (2 * x + 1) - 1) << 10
    && npc->hit.back + npc->x > (4 * (2 * x - 1) + 1) << 10
    && npc->y - npc->hit.top < (4 * (2 * y + 1) - 1) << 10
    && npc->hit.bottom + npc->y > (4 * (2 * y - 1) + 1) << 10 )
  {
    hit = 256;
  }
  npc->flag |= hit;
}

void HitNpCharMap()
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
  int offy[9];
  int offx[9];
  int x;
  int y;
  int judg;
  int i;
  int j;

  offx[0] = 0;
  offx[1] = 1;
  offx[2] = 0;
  offx[3] = 1;
  offx[4] = 2;
  offx[5] = 2;
  offx[6] = 2;
  offx[7] = 0;
  offx[8] = 1;
  offy[0] = 0;
  offy[1] = 0;
  offy[2] = 1;
  offy[3] = 1;
  offy[4] = 0;
  offy[5] = 1;
  offy[6] = 2;
  offy[7] = 2;
  offy[8] = 2;
  for ( i = 0; i <= 511; ++i )
  {
    if ( (gNPC[i].cond & 0x80u) != 0 && !(gNPC[i].bits & 8) )
    {
      if ( gNPC[i].size <= 2 )
      {
        judg = 4;
        x = gNPC[i].x / 0x2000;
        v1 = gNPC[i].y;
      }
      else
      {
        judg = 9;
        v0 = gNPC[i].x - 4096;
        x = (signed int)((HIDWORD(v0) >> 19) + v0) >> 13;
        v1 = gNPC[i].y - 4096;
      }
      y = (signed int)((HIDWORD(v1) >> 19) + v1) >> 13;
      gNPC[i].flag = 0;
      for ( j = 0; j < judg; ++j )
      {
        switch ( (unsigned __int8)GetAttribute(x + offx[j], y + offy[j]) )
        {
          case 2u:
          case 0x60u:
          case 0x62u:
            JudgeHitNpCharWater((NPCHAR *)(172 * i + 136142176), x + offx[j], y + offy[j]);
            break;
          case 3u:
          case 5u:
          case 0x41u:
          case 0x43u:
            goto LABEL_10;
          case 4u:
          case 0x61u:
          case 0x64u:
            JadgeHitNpCharBlock((NPCHAR *)(172 * i + 136142176), x + offx[j], y + offy[j]);
            JudgeHitNpCharWater((NPCHAR *)(172 * i + 136142176), x + offx[j], y + offy[j]);
            break;
          case 0x44u:
            if ( !(gNPC[i].bits & 2) )
LABEL_10:
              JadgeHitNpCharBlock((NPCHAR *)(172 * i + 136142176), x + offx[j], y + offy[j]);
            break;
          case 0x50u:
            JudgeHitNpCharTriangleA((NPCHAR *)(172 * i + 136142176), x + offx[j], y + offy[j]);
            break;
          case 0x51u:
            JudgeHitNpCharTriangleB((NPCHAR *)(172 * i + 136142176), x + offx[j], y + offy[j]);
            break;
          case 0x52u:
            JudgeHitNpCharTriangleC((NPCHAR *)(172 * i + 136142176), x + offx[j], y + offy[j]);
            break;
          case 0x53u:
            JudgeHitNpCharTriangleD((NPCHAR *)(172 * i + 136142176), x + offx[j], y + offy[j]);
            break;
          case 0x54u:
            JudgeHitNpCharTriangleE((NPCHAR *)(172 * i + 136142176), x + offx[j], y + offy[j]);
            break;
          case 0x55u:
            JudgeHitNpCharTriangleF((NPCHAR *)(172 * i + 136142176), x + offx[j], y + offy[j]);
            break;
          case 0x56u:
            JudgeHitNpCharTriangleG((NPCHAR *)(172 * i + 136142176), x + offx[j], y + offy[j]);
            break;
          case 0x57u:
            JudgeHitNpCharTriangleH((NPCHAR *)(172 * i + 136142176), x + offx[j], y + offy[j]);
            break;
          case 0x70u:
            JudgeHitNpCharTriangleA((NPCHAR *)(172 * i + 136142176), x + offx[j], y + offy[j]);
            JudgeHitNpCharWater((NPCHAR *)(172 * i + 136142176), x + offx[j], y + offy[j]);
            break;
          case 0x71u:
            JudgeHitNpCharTriangleB((NPCHAR *)(172 * i + 136142176), x + offx[j], y + offy[j]);
            JudgeHitNpCharWater((NPCHAR *)(172 * i + 136142176), x + offx[j], y + offy[j]);
            break;
          case 0x72u:
            JudgeHitNpCharTriangleC((NPCHAR *)(172 * i + 136142176), x + offx[j], y + offy[j]);
            JudgeHitNpCharWater((NPCHAR *)(172 * i + 136142176), x + offx[j], y + offy[j]);
            break;
          case 0x73u:
            JudgeHitNpCharTriangleD((NPCHAR *)(172 * i + 136142176), x + offx[j], y + offy[j]);
            JudgeHitNpCharWater((NPCHAR *)(172 * i + 136142176), x + offx[j], y + offy[j]);
            break;
          case 0x74u:
            JudgeHitNpCharTriangleE((NPCHAR *)(172 * i + 136142176), x + offx[j], y + offy[j]);
            JudgeHitNpCharWater((NPCHAR *)(172 * i + 136142176), x + offx[j], y + offy[j]);
            break;
          case 0x75u:
            JudgeHitNpCharTriangleF((NPCHAR *)(172 * i + 136142176), x + offx[j], y + offy[j]);
            JudgeHitNpCharWater((NPCHAR *)(172 * i + 136142176), x + offx[j], y + offy[j]);
            break;
          case 0x76u:
            JudgeHitNpCharTriangleG((NPCHAR *)(172 * i + 136142176), x + offx[j], y + offy[j]);
            JudgeHitNpCharWater((NPCHAR *)(172 * i + 136142176), x + offx[j], y + offy[j]);
            break;
          case 0x77u:
            JudgeHitNpCharTriangleH((NPCHAR *)(172 * i + 136142176), x + offx[j], y + offy[j]);
            JudgeHitNpCharWater((NPCHAR *)(172 * i + 136142176), x + offx[j], y + offy[j]);
            break;
          case 0x80u:
            goto LABEL_30;
          case 0x81u:
            goto LABEL_32;
          case 0x82u:
            goto LABEL_34;
          case 0x83u:
            goto LABEL_36;
          case 0xA0u:
            v2 = gNPC[i].flag;
            BYTE1(v2) |= 1u;
            gNPC[i].flag = v2;
LABEL_30:
            v3 = gNPC[i].flag;
            BYTE1(v3) |= 0x10u;
            gNPC[i].flag = v3;
            break;
          case 0xA1u:
            v4 = gNPC[i].flag;
            BYTE1(v4) |= 1u;
            gNPC[i].flag = v4;
LABEL_32:
            v5 = gNPC[i].flag;
            BYTE1(v5) |= 0x20u;
            gNPC[i].flag = v5;
            break;
          case 0xA2u:
            v6 = gNPC[i].flag;
            BYTE1(v6) |= 1u;
            gNPC[i].flag = v6;
LABEL_34:
            v7 = gNPC[i].flag;
            BYTE1(v7) |= 0x40u;
            gNPC[i].flag = v7;
            break;
          case 0xA3u:
            v8 = gNPC[i].flag;
            BYTE1(v8) |= 1u;
            gNPC[i].flag = v8;
LABEL_36:
            v9 = gNPC[i].flag;
            BYTE1(v9) |= 0x80u;
            gNPC[i].flag = v9;
            break;
          default:
            break;
        }
        if ( gNPC[i].y > gWaterY + 2048 )
        {
          v10 = gNPC[i].flag;
          BYTE1(v10) |= 1u;
          gNPC[i].flag = v10;
        }
      }
    }
  }
}

void LoseNpChar(NPCHAR *npc, bool bVanish)
{
  int v2;
  int v3;
  char v4;

  PlaySoundObject(npc->destroy_voice, 1);
  v2 = npc->size;
  switch ( v2 )
  {
    case 2:
      SetDestroyNpChar(npc->x, npc->y, npc->view.back, 7);
      break;
    case 3:
      SetDestroyNpChar(npc->x, npc->y, npc->view.back, 12);
      break;
    case 1:
      SetDestroyNpChar(npc->x, npc->y, npc->view.back, 3);
      break;
  }
  if ( npc->exp )
  {
    v3 = Random(1, 5);
    if ( v3 == 1 )
    {
      if ( npc->exp <= 6 )
        SetLifeObject(npc->x, npc->y, 2);
      else
        SetLifeObject(npc->x, npc->y, 6);
    }
    else if ( v3 != 2
           || (npc->exp <= 6 ? (v4 = SetBulletObject(npc->x, npc->y, 1)) : (v4 = SetBulletObject(npc->x, npc->y, 3)), !v4) )
    {
      SetExpObjects(npc->x, npc->y, npc->exp);
    }
  }
  SetNPCFlag(npc->code_flag);
  if ( (npc->bits & 0x8000u) == 0 )
  {
    npc->cond = 0;
  }
  else
  {
    if ( (npc->bits & 0x8000u) != 0 && npc->damage_view )
      SetValueView(&npc->x, &npc->y, npc->damage_view);
    if ( bVanish )
      VanishNpChar(npc);
  }
}

void HitNpCharBullet()
{
  int n;
  int b;
  bool bHit;

  for ( n = 0; n <= 511; ++n )
  {
    if ( (gNPC[n].cond & 0x80u) != 0 && (!(gNPC[n].bits & 0x20) || !(gNPC[n].bits & 0x2000)) )
    {
      for ( b = 0; ; ++b )
      {
        if ( b > 63 )
        {
          if ( gNPC[n].cond & 8 )
            LoseNpChar((NPCHAR *)(172 * n + 136142176), 1);
          break;
        }
        if ( gBul[b].cond & 0x80 && gBul[b].damage != -1 )
        {
          bHit = 0;
          if ( gNPC[n].bits & 0x20
            && gNPC[n].x - gNPC[n].hit.back < *(&gBul[0].flag + 4 * (8 * b + 1)) + gBul[b].enemyXL
            && gNPC[n].x + gNPC[n].hit.back > *(&gBul[0].flag + 4 * (8 * b + 1)) - gBul[b].enemyXL
            && gNPC[n].y - gNPC[n].hit.top < *(&gBul[0].code_bullet + 4 * (8 * b + 1)) + gBul[b].enemyYL
            && gNPC[n].y + gNPC[n].hit.bottom > *(&gBul[0].code_bullet + 4 * (8 * b + 1)) - gBul[b].enemyYL )
          {
            bHit = 1;
          }
          else if ( gNPC[n].bits & 4
                 && gNPC[n].x - gNPC[n].hit.back < *(&gBul[0].flag + 4 * (8 * b + 1)) + gBul[b].blockXL
                 && gNPC[n].x + gNPC[n].hit.back > *(&gBul[0].flag + 4 * (8 * b + 1)) - gBul[b].blockXL
                 && gNPC[n].y - gNPC[n].hit.top < *(&gBul[0].code_bullet + 4 * (8 * b + 1)) + gBul[b].blockYL
                 && gNPC[n].y + gNPC[n].hit.bottom > *(&gBul[0].code_bullet + 4 * (8 * b + 1)) - gBul[b].blockYL )
          {
            bHit = 1;
          }
          if ( bHit )
          {
            if ( gNPC[n].bits & 0x20 )
            {
              gNPC[n].life -= gBul[b].damage;
              if ( gNPC[n].life > 0 )
              {
                if ( gNPC[n].shock <= 0xDu )
                {
                  SetCaret(
                    (*(&gBul[0].flag + 4 * (8 * b + 1)) + gNPC[n].x) / 2,
                    (*(&gBul[0].code_bullet + 4 * (8 * b + 1)) + gNPC[n].y) / 2,
                    11,
                    0);
                  SetCaret(
                    (*(&gBul[0].flag + 4 * (8 * b + 1)) + gNPC[n].x) / 2,
                    (*(&gBul[0].code_bullet + 4 * (8 * b + 1)) + gNPC[n].y) / 2,
                    11,
                    0);
                  SetCaret(
                    (*(&gBul[0].flag + 4 * (8 * b + 1)) + gNPC[n].x) / 2,
                    (*(&gBul[0].code_bullet + 4 * (8 * b + 1)) + gNPC[n].y) / 2,
                    11,
                    0);
                  PlaySoundObject(gNPC[n].hit_voice, 1);
                  gNPC[n].shock = 16;
                }
                if ( (gNPC[n].bits & 0x8000u) != 0 )
                  gNPC[n].damage_view -= gBul[b].damage;
              }
              else
              {
                gNPC[n].life = 0;
                if ( (gNPC[n].bits & 0x8000u) != 0 )
                  gNPC[n].damage_view -= gBul[b].damage;
                if ( (gMC.cond & 0x80u) != 0 && gNPC[n].bits & 0x200 )
                  StartTextScript(gNPC[n].code_event);
                else
                  gNPC[n].cond |= 8u;
              }
            }
            else if ( gBul[b].code_bullet != 13
                   && gBul[b].code_bullet != 14
                   && gBul[b].code_bullet != 15
                   && gBul[b].code_bullet != 28
                   && gBul[b].code_bullet != 29
                   && gBul[b].code_bullet != 30
                   && !(gBul[b].bbits & 0x10) )
            {
              SetCaret(
                (*(&gBul[0].flag + 4 * (8 * b + 1)) + gNPC[n].x) / 2,
                (*(&gBul[0].code_bullet + 4 * (8 * b + 1)) + gNPC[n].y) / 2,
                2,
                2);
              PlaySoundObject(31, 1);
              gBul[b].life = 0;
              continue;
            }
            --gBul[b].life;
          }
        }
      }
    }
  }
}

