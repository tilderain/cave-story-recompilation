//#include "types.h"
#include "SDL_stdinc.h"
#include "windows_wrapper.h"
#include "Tags.h"

void InitBossChar(int code);
void PutBossChar(int fx, int fy);
void SetBossCharActNo(int a);
void HitBossBullet();
void ActBossChar_0();
void ActBossChar();
void HitBossMap();

BOSSFUNCTION gpBossFuncTbl[10] =
{
  &ActBossChar_0,
  &ActBossChar_Omega,
  &ActBossChar_Frog,
  &ActBossChar_MonstX,
  &ActBossChar_Core,
  &ActBossChar_Ironhead,
  &ActBossChar_Twin,
  &ActBossChar_Undead,
  &ActBossChar_Press,
  &ActBossChar_Ballos
};


void InitBossChar(int code)
{
  memset(gBoss, 0, 0xD70u);
  gBoss[0].cond = -128;
  unk_81CCFE8 = code;
}

void PutBossChar(int fx, int fy)
{
  __int64 v2;
  Sint8 a;
  int b;
  int side;

  for ( b = 19; b >= 0; --b )
  {
    if ( (gBoss[b].cond & 0x80u) != 0 )
    {
      if ( *((_BYTE *)&unk_81CD05C + 172 * b) )
      {
        a = 2 * ((*((_BYTE *)&unk_81CD05C + 172 * b) >> 1) & 1) - 1;
      }
      else
      {
        a = 0;
        if ( *((_WORD *)&unk_81CD010 + 86 * b) < 0 && *((_DWORD *)&unk_81CD060 + 43 * b) )
        {
          SetValueView((int *)(172 * b + 136105928), (int *)(172 * b + 136105932), *((_DWORD *)&unk_81CD060 + 43 * b));
          *((_DWORD *)&unk_81CD060 + 43 * b) = 0;
        }
      }
      if ( *((_DWORD *)&unk_81CD00C + 43 * b) )
        side = *((_DWORD *)&unk_81CD054 + 43 * b);
      else
        side = *((_DWORD *)&unk_81CD04C + 43 * b);
      v2 = *(&unk_81CCFCC + 43 * b) - *((_DWORD *)&unk_81CD050 + 43 * b);
      PutBitmap3(
        &grcGame,
        (*(&unk_81CCFC8 + 43 * b) - side) / 512 - fx / 512 + a,
        ((signed int)((HIDWORD(v2) >> 23) + v2) >> 9) - fy / 512,
        (RECT *)(172 * b + 136106004),
        22);
    }
  }
}

void SetBossCharActNo(int a)
{
  unk_81CD034 = a;
}

void HitBossBullet()
{
  int v0;
  bool bHit;
  int bul;
  int bos;
  int bos_;

  for ( bos = 0; bos <= 19; ++bos )
  {
    if ( (gBoss[bos].cond & 0x80u) != 0 )
    {
      for ( bul = 0; bul <= 63; ++bul )
      {
        if ( gBul[bul].cond & 0x80 && gBul[bul].damage != -1 )
        {
          bHit = 0;
          if ( *((_WORD *)&unk_81CD010 + 86 * bos) & 0x20
            && *(&unk_81CCFC8 + 43 * bos) - *((_DWORD *)&unk_81CD044 + 43 * bos) < *(&gBul[0].flag + 4 * (8 * bul + 1))
                                                                                 + gBul[bul].enemyXL
            && *(&unk_81CCFC8 + 43 * bos) + *((_DWORD *)&unk_81CD044 + 43 * bos) > *(&gBul[0].flag + 4 * (8 * bul + 1))
                                                                                 - gBul[bul].enemyXL
            && *(&unk_81CCFCC + 43 * bos) - *((_DWORD *)&unk_81CD040 + 43 * bos) < *(&gBul[0].code_bullet
                                                                                   + 4 * (8 * bul + 1))
                                                                                 + gBul[bul].enemyYL
            && *(&unk_81CCFCC + 43 * bos) + *((_DWORD *)&unk_81CD048 + 43 * bos) > *(&gBul[0].code_bullet
                                                                                   + 4 * (8 * bul + 1))
                                                                                 - gBul[bul].enemyYL )
          {
            bHit = 1;
          }
          else if ( *((_WORD *)&unk_81CD010 + 86 * bos) & 4
                 && *(&unk_81CCFC8 + 43 * bos) - *((_DWORD *)&unk_81CD044 + 43 * bos) < *(&gBul[0].flag
                                                                                        + 4 * (8 * bul + 1))
                                                                                      + gBul[bul].blockXL
                 && *(&unk_81CCFC8 + 43 * bos) + *((_DWORD *)&unk_81CD044 + 43 * bos) > *(&gBul[0].flag
                                                                                        + 4 * (8 * bul + 1))
                                                                                      - gBul[bul].blockXL
                 && *(&unk_81CCFCC + 43 * bos) - *((_DWORD *)&unk_81CD040 + 43 * bos) < *(&gBul[0].code_bullet
                                                                                        + 4 * (8 * bul + 1))
                                                                                      + gBul[bul].blockYL
                 && *(&unk_81CCFCC + 43 * bos) + *((_DWORD *)&unk_81CD048 + 43 * bos) > *(&gBul[0].code_bullet
                                                                                        + 4 * (8 * bul + 1))
                                                                                      - gBul[bul].blockYL )
          {
            bHit = 1;
          }
          if ( bHit )
          {
            if ( *((_WORD *)&unk_81CD010 + 86 * bos) & 0x20 )
            {
              if ( gBoss[bos].cond & 0x10 )
                bos_ = 0;
              else
                bos_ = bos;
              *((_DWORD *)&unk_81CD000 + 43 * bos_) -= gBul[bul].damage;
              if ( *((_DWORD *)&unk_81CD000 + 43 * bos_) > 0 )
              {
                if ( *((_BYTE *)&unk_81CD05C + 172 * bos) <= 0xDu )
                {
                  SetCaret(*(&gBul[0].flag + 4 * (8 * bul + 1)), *(&gBul[0].code_bullet + 4 * (8 * bul + 1)), 11, 0);
                  SetCaret(*(&gBul[0].flag + 4 * (8 * bul + 1)), *(&gBul[0].code_bullet + 4 * (8 * bul + 1)), 11, 0);
                  SetCaret(*(&gBul[0].flag + 4 * (8 * bul + 1)), *(&gBul[0].code_bullet + 4 * (8 * bul + 1)), 11, 0);
                  PlaySoundObject(*((_DWORD *)&unk_81CCFF8 + 43 * bos_), 1);
                }
                *((_BYTE *)&unk_81CD05C + 172 * bos) = 8;
                *((_BYTE *)&unk_81CD05C + 172 * bos_) = 8;
                *((_DWORD *)&unk_81CD060 + 43 * bos_) -= gBul[bul].damage;
              }
              else
              {
                *((_DWORD *)&unk_81CD000 + 43 * bos_) = bos_;
                if ( (gMC.cond & 0x80u) != 0 && *((_WORD *)&unk_81CD010 + 86 * bos_) & 0x200 )
                {
                  StartTextScript(*((_DWORD *)&unk_81CCFF0 + 43 * bos_));
                }
                else
                {
                  PlaySoundObject(*((_DWORD *)&unk_81CCFFC + 43 * bos_), 1);
                  v0 = *((_DWORD *)&unk_81CD008 + 43 * bos_);
                  switch ( v0 )
                  {
                    case 2:
                      SetDestroyNpChar(
                        *(&unk_81CCFC8 + 43 * bos_),
                        *(&unk_81CCFCC + 43 * bos_),
                        *((_DWORD *)&unk_81CD054 + 43 * bos_),
                        8);
                      break;
                    case 3:
                      SetDestroyNpChar(
                        *(&unk_81CCFC8 + 43 * bos_),
                        *(&unk_81CCFCC + 43 * bos_),
                        *((_DWORD *)&unk_81CD054 + 43 * bos_),
                        16);
                      break;
                    case 1:
                      SetDestroyNpChar(
                        *(&unk_81CCFC8 + 43 * bos_),
                        *(&unk_81CCFCC + 43 * bos_),
                        *((_DWORD *)&unk_81CD054 + 43 * bos_),
                        4);
                      break;
                  }
                  gBoss[bos_].cond = 0;
                }
              }
              if ( --gBul[bul].life <= 0 )
                gBul[bul].cond = 0;
            }
            else if ( gBul[bul].code_bullet != 13
                   && gBul[bul].code_bullet != 14
                   && gBul[bul].code_bullet != 15
                   && gBul[bul].code_bullet != 28
                   && gBul[bul].code_bullet != 29
                   && gBul[bul].code_bullet != 30 )
            {
              if ( !(gBul[bul].bbits & 0x10) )
              {
                SetCaret(*(&gBul[0].flag + 4 * (8 * bul + 1)), *(&gBul[0].code_bullet + 4 * (8 * bul + 1)), 2, 2);
                PlaySoundObject(31, 1);
                gBul[bul].cond = 0;
              }
            }
            else
            {
              --gBul[bul].life;
            }
          }
        }
      }
    }
  }
}

void ActBossChar_0()
{
  ;
}

void ActBossChar()
{
  int bos;

  if ( (gBoss[0].cond & 0x80u) != 0 )
  {
    gpBossFuncTbl[unk_81CCFE8]();
    for ( bos = 0; bos <= 19; ++bos )
    {
      if ( *((_BYTE *)&unk_81CD05C + 172 * bos) )
        --*((_BYTE *)&unk_81CD05C + 172 * bos);
    }
  }
}

void HitBossMap()
{
  int v0;
  int offy[16];
  int offx[16];
  unsigned __int8 atrb[16];
  int x;
  int y;
  int judg;
  int b;
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
  offx[9] = -1;
  offx[10] = -1;
  offx[11] = -1;
  offx[12] = -1;
  offx[13] = 0;
  offx[14] = 1;
  offx[15] = 2;
  offy[0] = 0;
  offy[1] = 0;
  offy[2] = 1;
  offy[3] = 1;
  offy[4] = 0;
  offy[5] = 1;
  offy[6] = 2;
  offy[7] = 2;
  offy[8] = 2;
  offy[9] = -1;
  offy[10] = 0;
  offy[11] = 1;
  offy[12] = 2;
  offy[13] = -1;
  offy[14] = -1;
  offy[15] = -1;
  for ( b = 0; b <= 19; ++b )
  {
    if ( (gBoss[b].cond & 0x80u) != 0 && !(*((_WORD *)&unk_81CD010 + 86 * b) & 8) )
    {
      if ( *((_DWORD *)&unk_81CD008 + 43 * b) <= 2 )
        judg = 4;
      else
        judg = 16;
      x = *(&unk_81CCFC8 + 43 * b) / 0x2000;
      y = *(&unk_81CCFCC + 43 * b) / 0x2000;
      *((_DWORD *)&unk_81CCFC4 + 43 * b) = 0;
      for ( j = 0; j < judg; ++j )
      {
        v0 = j;
        atrb[v0] = GetAttribute(x + offx[j], y + offy[j]);
        switch ( atrb[j] )
        {
          case 2u:
          case 0x60u:
          case 0x61u:
          case 0x64u:
            JadgeHitNpCharBlock((NPCHAR *)(172 * b + 136105920), x + offx[j], y + offy[j]);
            JudgeHitNpCharWater((NPCHAR *)(172 * b + 136105920), x + offx[j], y + offy[j]);
            break;
          case 5u:
          case 0x41u:
          case 0x43u:
            goto LABEL_10;
          case 0x44u:
            if ( !(*((_WORD *)&unk_81CD010 + 86 * b) & 2) )
LABEL_10:
              JadgeHitNpCharBlock((NPCHAR *)(172 * b + 136105920), x + offx[j], y + offy[j]);
            break;
          case 0x50u:
            JudgeHitNpCharTriangleA((NPCHAR *)(172 * b + 136105920), x + offx[j], y + offy[j]);
            break;
          case 0x51u:
            JudgeHitNpCharTriangleB((NPCHAR *)(172 * b + 136105920), x + offx[j], y + offy[j]);
            break;
          case 0x52u:
            JudgeHitNpCharTriangleC((NPCHAR *)(172 * b + 136105920), x + offx[j], y + offy[j]);
            break;
          case 0x53u:
            JudgeHitNpCharTriangleD((NPCHAR *)(172 * b + 136105920), x + offx[j], y + offy[j]);
            break;
          case 0x54u:
            JudgeHitNpCharTriangleE((NPCHAR *)(172 * b + 136105920), x + offx[j], y + offy[j]);
            break;
          case 0x55u:
            JudgeHitNpCharTriangleF((NPCHAR *)(172 * b + 136105920), x + offx[j], y + offy[j]);
            break;
          case 0x56u:
            JudgeHitNpCharTriangleG((NPCHAR *)(172 * b + 136105920), x + offx[j], y + offy[j]);
            break;
          case 0x57u:
            JudgeHitNpCharTriangleH((NPCHAR *)(172 * b + 136105920), x + offx[j], y + offy[j]);
            break;
          case 0x70u:
            JudgeHitNpCharTriangleA((NPCHAR *)(172 * b + 136105920), x + offx[j], y + offy[j]);
            JudgeHitNpCharWater((NPCHAR *)(172 * b + 136105920), x + offx[j], y + offy[j]);
            break;
          case 0x71u:
            JudgeHitNpCharTriangleB((NPCHAR *)(172 * b + 136105920), x + offx[j], y + offy[j]);
            JudgeHitNpCharWater((NPCHAR *)(172 * b + 136105920), x + offx[j], y + offy[j]);
            break;
          case 0x72u:
            JudgeHitNpCharTriangleC((NPCHAR *)(172 * b + 136105920), x + offx[j], y + offy[j]);
            JudgeHitNpCharWater((NPCHAR *)(172 * b + 136105920), x + offx[j], y + offy[j]);
            break;
          case 0x73u:
            JudgeHitNpCharTriangleD((NPCHAR *)(172 * b + 136105920), x + offx[j], y + offy[j]);
            JudgeHitNpCharWater((NPCHAR *)(172 * b + 136105920), x + offx[j], y + offy[j]);
            break;
          case 0x74u:
            JudgeHitNpCharTriangleE((NPCHAR *)(172 * b + 136105920), x + offx[j], y + offy[j]);
            JudgeHitNpCharWater((NPCHAR *)(172 * b + 136105920), x + offx[j], y + offy[j]);
            break;
          case 0x75u:
            JudgeHitNpCharTriangleF((NPCHAR *)(172 * b + 136105920), x + offx[j], y + offy[j]);
            JudgeHitNpCharWater((NPCHAR *)(172 * b + 136105920), x + offx[j], y + offy[j]);
            break;
          case 0x76u:
            JudgeHitNpCharTriangleG((NPCHAR *)(172 * b + 136105920), x + offx[j], y + offy[j]);
            JudgeHitNpCharWater((NPCHAR *)(172 * b + 136105920), x + offx[j], y + offy[j]);
            break;
          case 0x77u:
            JudgeHitNpCharTriangleH((NPCHAR *)(172 * b + 136105920), x + offx[j], y + offy[j]);
            JudgeHitNpCharWater((NPCHAR *)(172 * b + 136105920), x + offx[j], y + offy[j]);
            break;
          default:
            continue;
        }
      }
    }
  }
}

