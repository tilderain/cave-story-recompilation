#include "types.h"
#include "SDL_stdinc.h"
#include "windows_wrapper.h"
#include "Tags.h"
void __cdecl ActBossCharT_DragonBody(NPCHAR_0 *npc)
{
  int v1;
  __int64 v2;
  int v3;
  int v4;
  int v5;
  int v6;
  __int64 v7;
  int v8;
  int v9;
  __int64 v10;
  int v11;
  int v12;
  NPCHAR_0 *v13;
  Sint32 *v14;
  RECT rcRight[3];
  RECT rcLeft[3];
  unsigned __int8 deg;
  char v18[8];

  rcLeft[0].left = 0;
  rcLeft[0].top = 0;
  rcLeft[0].right = 40;
  rcLeft[0].bottom = 40;
  rcLeft[1].left = 40;
  rcLeft[1].top = 0;
  rcLeft[1].right = 80;
  rcLeft[1].bottom = 40;
  rcLeft[2].left = 80;
  rcLeft[2].top = 0;
  rcLeft[2].right = 120;
  rcLeft[2].bottom = 40;
  rcRight[0].left = 0;
  rcRight[0].top = 40;
  rcRight[0].right = 40;
  rcRight[0].bottom = 80;
  rcRight[1].left = 40;
  rcRight[1].top = 40;
  rcRight[1].right = 80;
  rcRight[1].bottom = 80;
  rcRight[2].left = 80;
  rcRight[2].top = 40;
  rcRight[2].right = 120;
  rcRight[2].bottom = 80;
  v1 = npc->act_no;
  if ( v1 == 100 )
  {
    v7 = npc->pNpc->count1;
    deg = LOBYTE(npc->count1) + ((signed int)((HIDWORD(v7) >> 30) + v7) >> 2);
    v8 = npc->pNpc->x;
    npc->tgt_x = v8 + npc->pNpc->tgt_x * GetCos(deg);
    v9 = npc->pNpc->y;
    npc->tgt_y = v9 + npc->pNpc->tgt_y * GetSin(deg);
    npc->x += (npc->tgt_x - npc->x) / 8;
    npc->y += (npc->tgt_y - npc->y) / 8;
    if ( npc->x <= x )
      npc->direct = 2;
    else
      npc->direct = 0;
  }
  else if ( v1 > 100 )
  {
    if ( v1 == 1000 )
    {
      npc->act_no = 1001;
      npc->bits &= 0xFFDFu;
    }
    else if ( v1 != 1001 )
    {
      goto LABEL_20;
    }
    v10 = npc->pNpc->count1;
    deg = LOBYTE(npc->count1) + ((signed int)((HIDWORD(v10) >> 30) + v10) >> 2);
    v11 = npc->pNpc->x;
    npc->tgt_x = v11 + npc->pNpc->tgt_x * GetCos(deg);
    v12 = npc->pNpc->y;
    npc->tgt_y = v12 + npc->pNpc->tgt_y * GetSin(deg);
    npc->x += (npc->tgt_x - npc->x) / 8;
    npc->y += (npc->tgt_y - npc->y) / 8;
    if ( npc->x <= npc->pNpc->x )
      npc->direct = 2;
    else
      npc->direct = 0;
  }
  else
  {
    if ( v1 )
    {
      if ( v1 != 10 )
        goto LABEL_20;
    }
    else
    {
      v2 = npc->pNpc->count1;
      deg = LOBYTE(npc->count1) + ((signed int)((HIDWORD(v2) >> 30) + v2) >> 2);
      npc->act_no = 10;
      v3 = npc->x;
      v4 = npc->pNpc->x;
      npc->x = v3 + v4 + npc->pNpc->tgt_x * GetCos(deg);
      v5 = npc->y;
      v6 = npc->pNpc->y;
      npc->y = v5 + v6 + npc->pNpc->tgt_y * GetSin(deg);
    }
    if ( npc->x <= x )
      npc->direct = 2;
    else
      npc->direct = 0;
  }
LABEL_20:
  if ( ++npc->ani_wait > 2 )
  {
    npc->ani_wait = 0;
    ++npc->ani_no;
  }
  if ( npc->ani_no > 2 )
    npc->ani_no = 0;
  if ( npc->direct )
  {
    v13 = npc;
    v14 = (Sint32 *)&v18[16 * npc->ani_no - 100];
  }
  else
  {
    v13 = npc;
    v14 = (Sint32 *)&v18[16 * npc->ani_no - 52];
  }
  npc->rect.left = *v14;
  v13->rect.top = v14[1];
  v13->rect.right = v14[2];
  v13->rect.bottom = v14[3];
}


void __cdecl ActBossCharT_DragonHead(NPCHAR_0 *npc)
{
  int v1;
  int v2;
  NPCHAR_0 *v3;
  Sint32 *v4;
  RECT rcRight[4];
  RECT rcLeft[4];
  unsigned __int8 deg;
  int xm;
  int ym;
  char v10[8];

  rcLeft[0].left = 0;
  rcLeft[0].top = 80;
  rcLeft[0].right = 40;
  rcLeft[0].bottom = 112;
  rcLeft[1].left = 40;
  rcLeft[1].top = 80;
  rcLeft[1].right = 80;
  rcLeft[1].bottom = 112;
  rcLeft[2].left = 80;
  rcLeft[2].top = 80;
  rcLeft[2].right = 120;
  rcLeft[2].bottom = 112;
  rcLeft[3].left = 120;
  rcLeft[3].top = 80;
  rcLeft[3].right = 160;
  rcLeft[3].bottom = 112;
  rcRight[0].left = 0;
  rcRight[0].top = 112;
  rcRight[0].right = 40;
  rcRight[0].bottom = 144;
  rcRight[1].left = 40;
  rcRight[1].top = 112;
  rcRight[1].right = 80;
  rcRight[1].bottom = 144;
  rcRight[2].left = 80;
  rcRight[2].top = 112;
  rcRight[2].right = 120;
  rcRight[2].bottom = 144;
  rcRight[3].left = 120;
  rcRight[3].top = 112;
  rcRight[3].right = 160;
  rcRight[3].bottom = 144;
  v1 = npc->act_no;
  if ( v1 == 210 )
  {
    if ( ++npc->act_wait == 3 )
      npc->ani_no = 1;
    if ( npc->act_wait == 6 )
    {
      npc->ani_no = 2;
      npc->hit.front = 4096;
      npc->bits |= 0x20u;
      npc->count2 = 0;
    }
    if ( npc->act_wait > 150 )
    {
      npc->act_no = 220;
      npc->act_wait = 0;
    }
    if ( npc->shock )
      ++npc->count2;
    if ( npc->count2 > 10 )
    {
      PlaySoundObject(51, 1);
      SetDestroyNpChar(npc->x, npc->y, npc->view.back, 4);
      npc->act_no = 300;
      npc->act_wait = 0;
      npc->ani_no = 3;
      npc->hit.front = 0x2000;
    }
  }
  else
  {
    if ( v1 <= 210 )
    {
      if ( v1 == 100 )
      {
        npc->act_no = 200;
      }
      else
      {
        if ( v1 <= 100 )
        {
          if ( !v1 )
            npc->act_no = 1;
          goto LABEL_55;
        }
        if ( v1 != 200 )
        {
          if ( v1 != 201 )
            goto LABEL_55;
LABEL_21:
          if ( npc->count1 )
          {
            --npc->count1;
          }
          else
          {
            npc->act_no = 210;
            npc->act_wait = 0;
            npc->count2 = 0;
          }
          goto LABEL_55;
        }
      }
      npc->bits &= 0xFFDFu;
      npc->ani_no = 0;
      npc->hit.front = 0x2000;
      npc->act_no = 201;
      npc->count1 = Random(100, 200);
      goto LABEL_21;
    }
    if ( v1 == 400 )
    {
      npc->act_no = 401;
      npc->act_wait = 0;
      npc->ani_no = 0;
      npc->hit.front = 0x2000;
      npc->bits &= 0xFFDFu;
    }
    else
    {
      if ( v1 <= 400 )
      {
        if ( v1 == 220 )
        {
          if ( ++npc->act_wait % 8 == 1 )
          {
            deg = GetArktan(npc->x - x, npc->y - y);
            deg += Random(-6, 6);
            ym = GetSin(deg);
            xm = GetCos(deg);
            if ( npc->direct )
              SetNpChar(202, npc->x + 4096, npc->y, xm, ym, 0, 0, 256);
            else
              SetNpChar(202, npc->x - 4096, npc->y, xm, ym, 0, 0, 256);
            PlaySoundObject(33, 1);
          }
          if ( npc->act_wait > 50 )
            npc->act_no = 200;
        }
        else if ( v1 == 300 && ++npc->act_wait > 100 )
        {
          npc->act_no = 200;
        }
        goto LABEL_55;
      }
      if ( v1 != 401 )
      {
        if ( v1 == 1000 )
        {
          npc->bits &= 0xFFDFu;
          npc->ani_no = 3;
        }
        goto LABEL_55;
      }
    }
    if ( ++npc->act_wait == 3 )
      npc->ani_no = 1;
    if ( npc->act_wait == 6 )
    {
      npc->ani_no = 2;
      npc->hit.front = 4096;
      npc->bits |= 0x20u;
      npc->count2 = 0;
    }
    if ( npc->act_wait > 20 && npc->act_wait % 32 == 1 )
    {
      deg = GetArktan(npc->x - x, npc->y - y);
      deg += Random(-6, 6);
      ym = GetSin(deg);
      xm = GetCos(deg);
      if ( npc->direct )
        SetNpChar(202, npc->x + 4096, npc->y, xm, ym, 0, 0, 256);
      else
        SetNpChar(202, npc->x - 4096, npc->y, xm, ym, 0, 0, 256);
      PlaySoundObject(33, 1);
    }
  }
LABEL_55:
  npc->direct = npc->pNpc->direct;
  if ( npc->direct )
    v2 = npc->pNpc->x + 2048;
  else
    v2 = npc->pNpc->x - 2048;
  npc->x = v2;
  npc->y = npc->pNpc->y - 4096;
  if ( npc->direct )
  {
    v3 = npc;
    v4 = (Sint32 *)&v10[16 * npc->ani_no - 140];
  }
  else
  {
    v3 = npc;
    v4 = (Sint32 *)&v10[16 * npc->ani_no - 76];
  }
  npc->rect.left = *v4;
  v3->rect.top = v4[1];
  v3->rect.right = v4[2];
  v3->rect.bottom = v4[3];
}


void ActBossChar_Twin()
{
  int v0;
  unsigned __int16 v1;
  int v2;
  int v3;
  int v4;
  int v5;

  v0 = gBoss[0].act_no;
  if ( v0 == 400 )
  {
    if ( ++gBoss[0].act_wait > 100 )
    {
      gBoss[0].act_wait = 0;
      gBoss[0].act_no = 401;
    }
    goto LABEL_82;
  }
  if ( v0 > 400 )
  {
    if ( v0 != 1001 )
    {
      if ( v0 > 1001 )
      {
        if ( v0 == 1010 )
        {
          gBoss[0].count1 += 4;
          if ( gBoss[0].count1 > 1023 )
            gBoss[0].count1 -= 1024;
          if ( gBoss[0].tgt_x > 8 )
            --gBoss[0].tgt_x;
          if ( gBoss[0].tgt_y > 0 )
            --gBoss[0].tgt_y;
          if ( gBoss[0].tgt_x < -8 )
            ++gBoss[0].tgt_x;
          if ( gBoss[0].tgt_y < 0 )
            ++gBoss[0].tgt_y;
          if ( !gBoss[0].tgt_y )
          {
            gBoss[0].act_no = 1020;
            gBoss[0].act_wait = 0;
            SetFlash(unk_81CCFC8, unk_81CCFCC, 1);
            PlaySoundObject(35, 1);
          }
        }
        else if ( v0 == 1020 && ++dword_81CD038 > 50 )
        {
          DeleteNpCharCode(211, 1);
          gBoss[0].cond = 0;
          npc.cond = 0;
          stru_81CD118.cond = 0;
          stru_81CD1C4.cond = 0;
          stru_81CD270.cond = 0;
          stru_81CD31C.cond = 0;
          unk_81CD034 = 0;
        }
        goto LABEL_82;
      }
      if ( v0 == 401 )
      {
        if ( ++gBoss[0].act_wait > 99 )
        {
          if ( gBoss[0].act_wait > 119 )
          {
            if ( gBoss[0].act_wait > 499 )
            {
              if ( gBoss[0].act_wait > 539 )
              {
                if ( gBoss[0].act_wait > 559 )
                {
                  gBoss[0].act_no = 100;
                  gBoss[0].act_wait = 0;
                  stru_81CD118.act_no = 100;
                  stru_81CD270.act_no = 100;
                  goto LABEL_82;
                }
                ++gBoss[0].count1;
              }
              else
              {
                gBoss[0].count1 += 2;
              }
            }
            else
            {
              gBoss[0].count1 += 4;
            }
          }
          else
          {
            gBoss[0].count1 += 2;
          }
        }
        else
        {
          ++gBoss[0].count1;
        }
        if ( gBoss[0].count1 > 1023 )
          gBoss[0].count1 -= 1024;
        goto LABEL_82;
      }
      if ( v0 != 1000 )
        goto LABEL_82;
      gBoss[0].act_no = 1001;
      gBoss[0].act_wait = 0;
      stru_81CD118.act_no = 1000;
      stru_81CD1C4.act_no = 1000;
      stru_81CD270.act_no = 1000;
      stru_81CD31C.act_no = 1000;
      SetDestroyNpChar(gBoss[0].x, gBoss[0].y, gBoss[0].view.back, 40);
    }
    if ( ++gBoss[0].act_wait > 100 )
      gBoss[0].act_no = 1010;
    v2 = gBoss[0].y;
    v3 = (Random(-70, 70) << 9) + v2;
    v4 = gBoss[0].x;
    v5 = Random(-128, 128);
    SetNpChar(4, v4 + (v5 << 9), v3, 0, 0, 0, 0, 256);
    goto LABEL_82;
  }
  if ( v0 == 20 )
  {
    if ( --gBoss[0].tgt_x <= 112 )
    {
      gBoss[0].act_no = 100;
      gBoss[0].act_wait = 0;
      stru_81CD118.act_no = 100;
      stru_81CD270.act_no = 100;
      stru_81CD1C4.act_no = 100;
      stru_81CD31C.act_no = 100;
    }
  }
  else if ( v0 > 20 )
  {
    if ( v0 == 100 )
    {
      if ( ++gBoss[0].act_wait > 99 )
      {
        if ( gBoss[0].act_wait > 119 )
        {
          if ( gBoss[0].act_wait >= gBoss[0].count2 )
          {
            if ( gBoss[0].act_wait >= gBoss[0].count2 + 40 )
            {
              if ( gBoss[0].act_wait >= gBoss[0].count2 + 60 )
              {
                gBoss[0].act_wait = 0;
                gBoss[0].act_no = 110;
                gBoss[0].count2 = Random(400, 700);
                goto LABEL_82;
              }
              ++gBoss[0].count1;
            }
            else
            {
              gBoss[0].count1 += 2;
            }
          }
          else
          {
            gBoss[0].count1 += 4;
          }
        }
        else
        {
          gBoss[0].count1 += 2;
        }
      }
      else
      {
        ++gBoss[0].count1;
      }
      if ( gBoss[0].count1 > 1023 )
        gBoss[0].count1 -= 1024;
    }
    else
    {
      if ( v0 != 110 )
        goto LABEL_82;
      if ( ++gBoss[0].act_wait > 19 )
      {
        if ( gBoss[0].act_wait > 59 )
        {
          if ( gBoss[0].act_wait >= gBoss[0].count2 )
          {
            if ( gBoss[0].act_wait >= gBoss[0].count2 + 40 )
            {
              if ( gBoss[0].act_wait >= gBoss[0].count2 + 60 )
              {
                if ( gBoss[0].life > 299 )
                {
                  gBoss[0].act_wait = 0;
                  gBoss[0].act_no = 100;
                  gBoss[0].count2 = Random(400, 700);
                }
                else
                {
                  gBoss[0].act_wait = 0;
                  gBoss[0].act_no = 400;
                  stru_81CD118.act_no = 400;
                  stru_81CD270.act_no = 400;
                }
                goto LABEL_82;
              }
              --gBoss[0].count1;
            }
            else
            {
              gBoss[0].count1 -= 2;
            }
          }
          else
          {
            gBoss[0].count1 -= 4;
          }
        }
        else
        {
          gBoss[0].count1 -= 2;
        }
      }
      else
      {
        --gBoss[0].count1;
      }
      if ( gBoss[0].count1 <= 0 )
        gBoss[0].count1 += 1024;
    }
  }
  else if ( !v0 )
  {
    gBoss[0].cond = -128;
    gBoss[0].direct = 0;
    gBoss[0].act_no = 10;
    gBoss[0].exp = 0;
    gBoss[0].x = 81920;
    gBoss[0].y = 0x10000;
    gBoss[0].view.front = 4096;
    gBoss[0].view.top = 4096;
    gBoss[0].view.back = 0x10000;
    gBoss[0].view.bottom = 4096;
    gBoss[0].hit_voice = 54;
    gBoss[0].hit.front = 4096;
    gBoss[0].hit.top = 4096;
    gBoss[0].hit.back = 4096;
    gBoss[0].hit.bottom = 4096;
    gBoss[0].bits = 8;
    v1 = gBoss[0].bits;
    HIBYTE(v1) |= 2u;
    gBoss[0].bits = v1;
    gBoss[0].size = 3;
    gBoss[0].damage = 0;
    gBoss[0].code_event = 1000;
    gBoss[0].life = 500;
    gBoss[0].count2 = Random(700, 1200);
    gBoss[0].tgt_x = 180;
    gBoss[0].tgt_y = 61;
    stru_81CD118.view.back = 10240;
    stru_81CD118.view.front = 10240;
    stru_81CD118.view.top = 0x2000;
    stru_81CD118.view.bottom = 0x2000;
    stru_81CD118.hit.back = 6144;
    stru_81CD118.hit.front = 6144;
    stru_81CD118.hit.top = 5120;
    stru_81CD118.hit.bottom = 5120;
    stru_81CD118.bits = 12;
    stru_81CD118.pNpc = &stru_81CD1C4;
    stru_81CD118.cond = -112;
    stru_81CD118.damage = 10;
    stru_81CD1C4.cond = -128;
    stru_81CD1C4.view.back = 10240;
    stru_81CD1C4.view.front = 10240;
    stru_81CD1C4.view.top = 10240;
    stru_81CD1C4.view.bottom = 10240;
    stru_81CD1C4.hit.back = 6144;
    stru_81CD1C4.hit.front = 6144;
    stru_81CD1C4.hit.top = 1024;
    stru_81CD1C4.hit.bottom = 0x2000;
    stru_81CD1C4.bits = 8;
    stru_81CD1C4.pNpc = gBoss;
    stru_81CD1C4.damage = 10;
    qmemcpy(&stru_81CD270, &stru_81CD118, sizeof(stru_81CD270));
    stru_81CD270.pNpc = &stru_81CD31C;
    qmemcpy(&stru_81CD31C, &stru_81CD1C4, sizeof(stru_81CD31C));
    stru_81CD31C.count1 = 128;
  }
LABEL_82:
  ActBossCharT_DragonHead(&stru_81CD118);
  ActBossCharT_DragonBody(&stru_81CD1C4);
  ActBossCharT_DragonHead(&stru_81CD270);
  ActBossCharT_DragonBody(&stru_81CD31C);
  gBoss[0].rect.left = 0;
  gBoss[0].rect.top = 0;
  gBoss[0].rect.right = 0;
  gBoss[0].rect.bottom = 0;
}

