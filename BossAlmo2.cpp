#include "types.h"
#include "SDL_stdinc.h"
#include "windows_wrapper.h"
#include "Tags.h"
void __cdecl _ActBossCharA_Head(NPCHAR_0 *npc)
{
  int v1;
  RECT *v2;
  RECT rect[4];

  rect[0].left = 0;
  rect[0].top = 0;
  rect[0].right = 72;
  rect[0].bottom = 112;
  rect[1].left = 0;
  rect[1].top = 112;
  rect[1].right = 72;
  rect[1].bottom = 224;
  rect[2].left = 160;
  rect[2].top = 0;
  rect[2].right = 232;
  rect[2].bottom = 112;
  rect[3].left = 0;
  rect[3].top = 0;
  rect[3].right = 0;
  rect[3].bottom = 0;
  v1 = npc->act_no;
  if ( v1 == 51 )
  {
LABEL_12:
    if ( !--npc->act_wait )
    {
      npc->act_no = 100;
      npc->ani_no = 3;
    }
    goto LABEL_15;
  }
  if ( v1 <= 51 )
  {
    if ( v1 != 50 )
    {
      if ( v1 == 10 )
      {
        npc->act_no = 11;
        npc->ani_no = 2;
        npc->bits = 8;
        npc->view.front = 18432;
        npc->view.top = 28672;
      }
      else if ( v1 != 11 )
      {
        goto LABEL_15;
      }
      npc->x = unk_81CCFC8 - 18432;
      npc->y = unk_81CCFCC;
      goto LABEL_15;
    }
    npc->act_no = 51;
    npc->act_wait = 112;
    goto LABEL_12;
  }
  if ( v1 == 100 )
    npc->ani_no = 3;
LABEL_15:
  v2 = &rect[npc->ani_no];
  npc->rect.left = v2->left;
  npc->rect.top = v2->top;
  npc->rect.right = v2->right;
  npc->rect.bottom = v2->bottom;
  if ( npc->act_no == 51 )
    npc->rect.bottom = npc->act_wait + npc->rect.top;
}

void __cdecl _ActBossCharA_Tail(NPCHAR_0 *npc)
{
  int v1;
  RECT *v2;
  RECT rect[3];

  rect[0].left = 72;
  rect[0].top = 0;
  rect[0].right = 160;
  rect[0].bottom = 112;
  rect[1].left = 72;
  rect[1].top = 112;
  rect[1].right = 160;
  rect[1].bottom = 224;
  rect[2].left = 0;
  rect[2].top = 0;
  rect[2].right = 0;
  rect[2].bottom = 0;
  v1 = npc->act_no;
  if ( v1 == 51 )
  {
LABEL_12:
    if ( !--npc->act_wait )
    {
      npc->act_no = 100;
      npc->ani_no = 2;
    }
    goto LABEL_15;
  }
  if ( v1 <= 51 )
  {
    if ( v1 != 50 )
    {
      if ( v1 == 10 )
      {
        npc->act_no = 11;
        npc->ani_no = 0;
        npc->bits = 8;
        npc->view.front = 22528;
        npc->view.top = 28672;
      }
      else if ( v1 != 11 )
      {
        goto LABEL_15;
      }
      npc->x = unk_81CCFC8 + 22528;
      npc->y = unk_81CCFCC;
      goto LABEL_15;
    }
    npc->act_no = 51;
    npc->act_wait = 112;
    goto LABEL_12;
  }
  if ( v1 == 100 )
    npc->ani_no = 2;
LABEL_15:
  v2 = &rect[npc->ani_no];
  npc->rect.left = v2->left;
  npc->rect.top = v2->top;
  npc->rect.right = v2->right;
  npc->rect.bottom = v2->bottom;
  if ( npc->act_no == 51 )
    npc->rect.bottom = npc->act_wait + npc->rect.top;
}

void __cdecl _ActBossCharA_Face(NPCHAR_0 *npc)
{
  Sint32 *v1;
  RECT rect[5];
  char v3[24];

  qmemcpy(rect, &_ActBossCharA_Face(NPCHAR *)::C.0, sizeof(rect));
  switch ( npc->act_no )
  {
    case 0:
      npc->ani_no = 0;
      break;
    case 0xA:
      npc->ani_no = 1;
      break;
    case 0x14:
      npc->ani_no = 2;
      break;
    case 0x1E:
      npc->act_no = 31;
      npc->ani_no = 3;
      npc->act_wait = 100;
      goto LABEL_6;
    case 0x1F:
LABEL_6:
      if ( ++npc->act_wait > 300 )
        npc->act_wait = 0;
      if ( npc->act_wait > 250 && npc->act_wait % 16 == 1 )
        PlaySoundObject(26, 1);
      if ( npc->act_wait > 250 && npc->act_wait % 16 == 7 )
      {
        SetNpChar(293, npc->x, npc->y, 0, 0, 0, 0, 128);
        PlaySoundObject(101, 1);
      }
      if ( npc->act_wait == 200 )
        PlaySoundObject(116, 1);
      if ( npc->act_wait > 200 && npc->act_wait & 1 )
        npc->ani_no = 4;
      else
        npc->ani_no = 3;
      break;
    default:
      break;
  }
  npc->view.back = 18432;
  npc->view.front = 18432;
  npc->view.top = 10240;
  npc->x = unk_81CCFC8 - 18432;
  npc->y = unk_81CCFCC + 2048;
  npc->bits = 8;
  v1 = (Sint32 *)&v3[16 * npc->ani_no - 80];
  npc->rect.left = *v1;
  npc->rect.top = v1[1];
  npc->rect.right = v1[2];
  npc->rect.bottom = v1[3];
}


void __cdecl _ActBossCharA_Mini(NPCHAR_0 *npc)
{
  int v1;
  int v2;
  int v3;
  int v4;
  Sint32 *v5;
  RECT rect[3];
  int deg;
  char v8[8];

  rect[0].left = 256;
  rect[0].top = 0;
  rect[0].right = 320;
  rect[0].bottom = 40;
  rect[1].left = 256;
  rect[1].top = 40;
  rect[1].right = 320;
  rect[1].bottom = 80;
  rect[2].left = 256;
  rect[2].top = 80;
  rect[2].right = 320;
  rect[2].bottom = 120;
  if ( !npc->cond )
    return;
  npc->life = 1000;
  v1 = npc->act_no;
  if ( v1 == 20 )
  {
    npc->ani_no = 1;
    npc->bits &= 0xFFDFu;
    npc->count2 += 2;
    npc->count2 = (unsigned __int8)(((unsigned __int64)npc->count2 >> 56) + npc->count2)
                - ((unsigned int)(npc->count2 >> 31) >> 24);
  }
  else
  {
    if ( v1 > 20 )
    {
      if ( v1 == 200 )
      {
        npc->act_no = 201;
        npc->ani_no = 2;
        npc->xm = 0;
        npc->ym = 0;
      }
      else if ( v1 != 201 )
      {
        if ( v1 == 30 )
        {
          npc->ani_no = 0;
          npc->bits &= 0xFFDFu;
          npc->count2 += 4;
          npc->count2 = (unsigned __int8)(((unsigned __int64)npc->count2 >> 56) + npc->count2)
                      - ((unsigned int)(npc->count2 >> 31) >> 24);
        }
        goto LABEL_20;
      }
      npc->xm += 32;
      npc->x += npc->xm;
      if ( npc->x > (gMap.width + 2) << 13 )
        npc->cond = 0;
      goto LABEL_20;
    }
    switch ( v1 )
    {
      case 5:
        npc->ani_no = 0;
        npc->bits &= 0xFFDFu;
        ++npc->count2;
        npc->count2 = (unsigned __int8)(((unsigned __int64)npc->count2 >> 56) + npc->count2)
                    - ((unsigned int)(npc->count2 >> 31) >> 24);
        break;
      case 10:
        npc->ani_no = 0;
        npc->bits &= 0xFFDFu;
        npc->count2 += 2;
        npc->count2 = (unsigned __int8)(((unsigned __int64)npc->count2 >> 56) + npc->count2)
                    - ((unsigned int)(npc->count2 >> 31) >> 24);
        break;
      case 0:
        npc->bits &= 0xFFDFu;
        break;
    }
  }
LABEL_20:
  if ( npc->act_no <= 49 )
  {
    if ( npc->count1 )
      v2 = npc->count2 + 128;
    else
      v2 = npc->count2 + 384;
    deg = v2;
    v3 = npc->pNpc->x - 4096;
    npc->x = v3 + 48 * GetCos(v2 / 2);
    v4 = npc->pNpc->y;
    npc->y = v4 + 80 * GetSin(deg / 2);
  }
  v5 = (Sint32 *)&v8[16 * npc->ani_no - 52];
  npc->rect.left = *v5;
  npc->rect.top = v5[1];
  npc->rect.right = v5[2];
  npc->rect.bottom = v5[3];
}


void __cdecl _ActBossCharA_Hit(NPCHAR_0 *npc)
{
  int v1;

  v1 = npc->count1;
  if ( v1 == 1 )
  {
    npc->x = unk_81CCFC8 + 14336;
    npc->y = unk_81CCFCC;
  }
  else if ( v1 > 1 )
  {
    if ( v1 == 2 )
    {
      npc->x = unk_81CCFC8 + 2048;
      npc->y = unk_81CCFCC + 0x4000;
    }
    else if ( v1 == 3 )
    {
      npc->x = unk_81CCFC8 - 14336;
      npc->y = unk_81CCFCC + 2048;
    }
  }
  else if ( !v1 )
  {
    npc->x = unk_81CCFC8;
    npc->y = unk_81CCFCC - 0x4000;
  }
}

void ActBossChar_Undead()
{
  int v0;
  unsigned __int16 v1;
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
  int v22;
  int v23;
  int v24;
  int v25;
  int v26;
  bool bShock;
  int i;
  int ia;
  int ib;
  int ic;
  int x;
  int y;

  bShock = 0;
  v0 = gBoss[0].act_no;
  if ( v0 == 210 )
  {
    gBoss[0].act_no = 211;
    gBoss[0].act_wait = 0;
    stru_81CD1C4.act_no = 10;
    stru_81CD520.bits |= 4u;
    stru_81CD5CC.bits |= 4u;
    stru_81CD678.bits |= 4u;
    stru_81CD724.bits |= 0x20u;
    ActBossChar_Undead(void)::_life = gBoss[0].life;
    bShock = 1;
LABEL_42:
    ++ActBossChar_Undead(void)::_flash;
    if ( gBoss[0].shock && (ActBossChar_Undead(void)::_flash >> 1) & 1 )
    {
      stru_81CD270.ani_no = 1;
      stru_81CD31C.ani_no = 1;
    }
    else
    {
      stru_81CD270.ani_no = 0;
      stru_81CD31C.ani_no = 0;
    }
    if ( ++gBoss[0].act_wait % 100 == 1 )
    {
      gCurlyShoot_wait = Random(80, 100);
      gCurlyShoot_x = stru_81CD724.x;
      gCurlyShoot_y = stru_81CD724.y;
    }
    if ( gBoss[0].act_wait <= 299 )
    {
      if ( gBoss[0].act_wait % 120 == 1 )
        SetNpChar(288, gBoss[0].x - 0x4000, gBoss[0].y - 0x2000, 0, 0, 1, 0, 32);
      if ( gBoss[0].act_wait % 120 == 61 )
        SetNpChar(288, gBoss[0].x - 0x4000, gBoss[0].y + 0x2000, 0, 0, 3, 0, 32);
    }
    if ( gBoss[0].life < ActBossChar_Undead(void)::_life - 50 || gBoss[0].act_wait > 400 )
      gBoss[0].act_no = 200;
    goto LABEL_108;
  }
  if ( v0 > 210 )
  {
    if ( v0 != 231 )
    {
      if ( v0 > 231 )
      {
        if ( v0 != 501 )
        {
          if ( v0 > 501 )
          {
            if ( v0 == 1000 )
            {
              SetQuake(100);
              if ( !(++dword_81CD038 & 7) )
                PlaySoundObject(44, 1);
              v15 = unk_81CCFCC;
              v16 = (Random(-64, 64) << 9) + v15;
              v17 = unk_81CCFC8;
              v18 = Random(-72, 72);
              SetDestroyNpChar(v17 + (v18 << 9), v16, 1, 1);
              if ( dword_81CD038 > 100 )
              {
                dword_81CD038 = 0;
                unk_81CD034 = 1001;
                SetFlash(unk_81CCFC8, unk_81CCFCC, 1);
                PlaySoundObject(35, 1);
              }
            }
            else if ( v0 == 1001 )
            {
              SetQuake(40);
              if ( ++dword_81CD038 > 50 )
              {
                for ( ib = 0; ib <= 19; ++ib )
                  gBoss[ib].cond = 0;
                DeleteNpCharCode(158, 1);
                DeleteNpCharCode(301, 1);
              }
            }
            goto LABEL_108;
          }
          if ( v0 != 500 )
            goto LABEL_108;
          CutNoise();
          gBoss[0].act_no = 501;
          gBoss[0].act_wait = 0;
          gBoss[0].xm = 0;
          gBoss[0].ym = 0;
          stru_81CD1C4.act_no = 0;
          stru_81CD270.ani_no = 2;
          stru_81CD31C.ani_no = 0;
          npc.act_no = 5;
          stru_81CD118.act_no = 5;
          stru_81CD3C8.act_no = 5;
          stru_81CD474.act_no = 5;
          SetQuake(20);
          for ( i = 0; i <= 99; ++i )
          {
            v3 = Random(-128, 128) << 9;
            v4 = Random(-128, 128) << 9;
            v5 = gBoss[0].y;
            v6 = (Random(-64, 64) << 9) + v5;
            v7 = gBoss[0].x;
            v8 = Random(-128, 128);
            SetNpChar(4, v7 + (v8 << 9), v6, v4, v3, 0, 0, 0);
          }
          DeleteNpCharCode(282, 1);
          stru_81CD724.bits &= 0xFFDFu;
          for ( ia = 0; ia <= 11; ++ia )
            *((_WORD *)&unk_81CD010 + 86 * ia) &= 0xFFFBu;
        }
        if ( ++gBoss[0].act_wait & 0xF )
        {
          v9 = Random(-128, 128) << 9;
          v10 = Random(-128, 128) << 9;
          v11 = gBoss[0].y;
          v12 = (Random(-32, 32) << 9) + v11;
          v13 = gBoss[0].x;
          v14 = Random(-64, 64);
          SetNpChar(4, v13 + (v14 << 9), v12, v10, v9, 0, 0, 256);
        }
        gBoss[0].x += 64;
        gBoss[0].y += 128;
        if ( gBoss[0].act_wait > 200 )
        {
          gBoss[0].act_wait = 0;
          gBoss[0].act_no = 1000;
        }
        goto LABEL_108;
      }
      if ( v0 == 220 )
      {
        gBoss[0].act_no = 221;
        gBoss[0].act_wait = 0;
        gBoss[0].count1 = 0;
        gSuperYpos = 1;
        stru_81CD1C4.act_no = 20;
        stru_81CD520.bits |= 4u;
        stru_81CD5CC.bits |= 4u;
        stru_81CD678.bits |= 4u;
        stru_81CD724.bits |= 0x20u;
        SetQuake(100);
        ActBossChar_Undead(void)::_life = gBoss[0].life;
        bShock = 1;
      }
      else
      {
        if ( v0 <= 220 )
        {
          if ( v0 != 211 )
            goto LABEL_108;
          goto LABEL_42;
        }
        if ( v0 != 221 )
        {
          if ( v0 != 230 )
            goto LABEL_108;
          gBoss[0].act_no = 231;
          gBoss[0].act_wait = 0;
          stru_81CD1C4.act_no = 30;
          stru_81CD520.bits |= 4u;
          stru_81CD5CC.bits |= 4u;
          stru_81CD678.bits |= 4u;
          stru_81CD724.bits |= 0x20u;
          PlaySoundObject(25, 1);
          SetNpChar(285, stru_81CD1C4.x - 0x2000, stru_81CD1C4.y, 0, 0, 0, 0, 256);
          SetNpChar(285, stru_81CD1C4.x - 0x2000, stru_81CD1C4.y, 0, 0, 1024, 0, 256);
          SetNpChar(285, stru_81CD1C4.x, stru_81CD1C4.y - 0x2000, 0, 0, 0, 0, 256);
          SetNpChar(285, stru_81CD1C4.x, stru_81CD1C4.y - 0x2000, 0, 0, 1024, 0, 256);
          SetNpChar(285, stru_81CD1C4.x, stru_81CD1C4.y + 0x2000, 0, 0, 0, 0, 256);
          SetNpChar(285, stru_81CD1C4.x, stru_81CD1C4.y + 0x2000, 0, 0, 1024, 0, 256);
          ActBossChar_Undead(void)::_life = gBoss[0].life;
          bShock = 1;
          goto LABEL_79;
        }
      }
      if ( ++gBoss[0].act_wait % 40 == 1 )
      {
        v2 = Random(0, 3);
        if ( v2 == 1 )
        {
          x = stru_81CD118.x;
          y = stru_81CD118.y;
        }
        else if ( v2 > 1 )
        {
          if ( v2 == 2 )
          {
            x = stru_81CD3C8.x;
            y = stru_81CD3C8.y;
          }
          else if ( v2 == 3 )
          {
            x = stru_81CD474.x;
            y = stru_81CD474.y;
          }
        }
        else if ( !v2 )
        {
          x = npc.x;
          y = npc.y;
        }
        PlaySoundObject(25, 1);
        SetNpChar(285, x - 0x2000, y, 0, 0, 0, 0, 256);
        SetNpChar(285, x - 0x2000, y, 0, 0, 1024, 0, 256);
      }
      ++ActBossChar_Undead(void)::_flash;
      if ( gBoss[0].shock && (ActBossChar_Undead(void)::_flash >> 1) & 1 )
      {
        stru_81CD270.ani_no = 1;
        stru_81CD31C.ani_no = 1;
      }
      else
      {
        stru_81CD270.ani_no = 0;
        stru_81CD31C.ani_no = 0;
      }
      if ( gBoss[0].life < ActBossChar_Undead(void)::_life - 150 || gBoss[0].act_wait > 400 || gBoss[0].life <= 199 )
        gBoss[0].act_no = 200;
      goto LABEL_108;
    }
LABEL_79:
    ++ActBossChar_Undead(void)::_flash;
    if ( gBoss[0].shock && (ActBossChar_Undead(void)::_flash >> 1) & 1 )
    {
      stru_81CD270.ani_no = 1;
      stru_81CD31C.ani_no = 1;
    }
    else
    {
      stru_81CD270.ani_no = 0;
      stru_81CD31C.ani_no = 0;
    }
    if ( ++gBoss[0].act_wait % 100 == 1 )
    {
      gCurlyShoot_wait = Random(80, 100);
      gCurlyShoot_x = stru_81CD724.x;
      gCurlyShoot_y = stru_81CD724.y;
    }
    if ( gBoss[0].act_wait % 120 == 1 )
      SetNpChar(288, gBoss[0].x - 0x4000, gBoss[0].y - 0x2000, 0, 0, 1, 0, 32);
    if ( gBoss[0].act_wait % 120 == 61 )
      SetNpChar(288, gBoss[0].x - 0x4000, gBoss[0].y + 0x2000, 0, 0, 3, 0, 32);
    goto LABEL_108;
  }
  if ( v0 == 15 )
  {
    gBoss[0].act_no = 16;
    bShock = 1;
    gBoss[0].direct = 0;
    stru_81CD1C4.act_no = 10;
    stru_81CD270.ani_no = 0;
    goto LABEL_108;
  }
  if ( v0 > 15 )
  {
    if ( v0 == 20 )
    {
      gBoss[0].act_no = 210;
      bShock = 1;
      gBoss[0].direct = 0;
      npc.act_no = 5;
      stru_81CD118.act_no = 5;
      stru_81CD3C8.act_no = 5;
      stru_81CD474.act_no = 5;
      goto LABEL_108;
    }
    if ( v0 <= 20 )
      goto LABEL_108;
    if ( v0 == 200 )
    {
      gBoss[0].act_no = 201;
      gBoss[0].act_wait = 0;
      stru_81CD1C4.act_no = 0;
      stru_81CD270.ani_no = 2;
      stru_81CD31C.ani_no = 0;
      stru_81CD520.bits &= 0xFFFBu;
      stru_81CD5CC.bits &= 0xFFFBu;
      stru_81CD678.bits &= 0xFFFBu;
      stru_81CD724.bits &= 0xFFDFu;
      gSuperYpos = 0;
      CutNoise();
      bShock = 1;
    }
    else if ( v0 != 201 )
    {
      goto LABEL_108;
    }
    ++gBoss[0].act_wait;
    if ( (gBoss[0].direct == 2 || gBoss[0].ani_no > 0 || gBoss[0].life <= 199) && gBoss[0].act_wait > 200 )
    {
      ++gBoss[0].count1;
      PlaySoundObject(115, 1);
      if ( gBoss[0].life > 199 )
      {
        if ( gBoss[0].count1 <= 2 )
          gBoss[0].act_no = 210;
        else
          gBoss[0].act_no = 220;
      }
      else
      {
        gBoss[0].act_no = 230;
      }
    }
  }
  else if ( v0 == 1 )
  {
    gBoss[0].act_no = 10;
    gBoss[0].exp = 1;
    gBoss[0].cond = -128;
    gBoss[0].bits = -32756;
    gBoss[0].life = 700;
    gBoss[0].hit_voice = 114;
    gBoss[0].x = 303104;
    gBoss[0].y = 61440;
    gBoss[0].xm = 0;
    gBoss[0].ym = 0;
    gBoss[0].code_event = 1000;
    v1 = gBoss[0].bits;
    HIBYTE(v1) |= 2u;
    gBoss[0].bits = v1;
    stru_81CD1C4.cond = -128;
    stru_81CD1C4.act_no = 0;
    stru_81CD270.cond = -128;
    stru_81CD270.act_no = 10;
    stru_81CD31C.cond = -128;
    stru_81CD31C.act_no = 10;
    stru_81CD520.cond = -128;
    stru_81CD520.bits = 8;
    stru_81CD520.view.front = 0;
    stru_81CD520.view.top = 0;
    stru_81CD520.hit.back = 20480;
    stru_81CD520.hit.top = 0x2000;
    stru_81CD520.hit.bottom = 0x2000;
    stru_81CD520.count1 = 0;
    qmemcpy(&stru_81CD5CC, &stru_81CD520, sizeof(stru_81CD5CC));
    stru_81CD5CC.hit.back = 18432;
    stru_81CD5CC.hit.top = 12288;
    stru_81CD5CC.hit.bottom = 12288;
    stru_81CD5CC.count1 = 1;
    qmemcpy(&stru_81CD678, &stru_81CD520, sizeof(stru_81CD678));
    stru_81CD678.hit.back = 22528;
    stru_81CD678.hit.top = 4096;
    stru_81CD678.hit.bottom = 4096;
    stru_81CD678.count1 = 2;
    qmemcpy(&stru_81CD724, &stru_81CD520, sizeof(stru_81CD724));
    stru_81CD724.cond |= 0x10u;
    stru_81CD724.hit.back = 10240;
    stru_81CD724.hit.top = 10240;
    stru_81CD724.hit.bottom = 10240;
    stru_81CD724.count1 = 3;
    npc.cond = -128;
    npc.act_no = 0;
    npc.bits = 40;
    npc.life = 1000;
    npc.hit_voice = 54;
    npc.hit.back = 12288;
    npc.hit.top = 0x2000;
    npc.hit.bottom = 0x2000;
    npc.view.front = 0x4000;
    npc.view.top = 10240;
    npc.pNpc = gBoss;
    qmemcpy(&stru_81CD118, &npc, sizeof(stru_81CD118));
    stru_81CD118.count2 = 128;
    qmemcpy(&stru_81CD3C8, &npc, sizeof(stru_81CD3C8));
    stru_81CD3C8.count1 = 1;
    qmemcpy(&stru_81CD474, &npc, sizeof(stru_81CD474));
    stru_81CD474.count1 = 1;
    stru_81CD474.count2 = 128;
    ActBossChar_Undead(void)::_life = gBoss[0].life;
  }
LABEL_108:
  if ( bShock )
  {
    SetQuake(20);
    if ( gBoss[0].act_no == 201 )
    {
      stru_81CD474.act_no = 10;
      stru_81CD3C8.act_no = 10;
      stru_81CD118.act_no = 10;
      npc.act_no = 10;
    }
    if ( gBoss[0].act_no == 221 )
    {
      stru_81CD474.act_no = 20;
      stru_81CD3C8.act_no = 20;
      stru_81CD118.act_no = 20;
      npc.act_no = 20;
    }
    if ( gBoss[0].act_no == 231 )
    {
      stru_81CD474.act_no = 30;
      stru_81CD3C8.act_no = 30;
      stru_81CD118.act_no = 30;
      npc.act_no = 30;
    }
    PlaySoundObject(26, 1);
    for ( ic = 0; ic <= 7; ++ic )
    {
      v19 = Random(-256, 256);
      v20 = Random(-512, 512);
      v21 = stru_81CD270.y;
      v22 = stru_81CD270.x;
      v23 = Random(-32, 16);
      SetNpChar(4, v22 + (v23 << 9), v21, v20, v19, 0, 0, 256);
    }
  }
  if ( gBoss[0].act_no > 199 && gBoss[0].act_no <= 299 )
  {
    if ( gBoss[0].x <= 98303 )
      gBoss[0].direct = 2;
    if ( gBoss[0].x > (gMap.width - 4) << 13 )
      gBoss[0].direct = 0;
    if ( gBoss[0].direct )
      v24 = gBoss[0].xm + 4;
    else
      v24 = gBoss[0].xm - 4;
    gBoss[0].xm = v24;
  }
  if ( (unsigned int)(gBoss[0].act_no - 201) <= 0x1E && (1 << (LOBYTE(gBoss[0].act_no) + 55)) & 0x40100401 )
  {
    if ( ++gBoss[0].count2 == 150 )
    {
      gBoss[0].count2 = 0;
      v25 = Random(-1, 3);
      SetNpChar(282, ((gMap.width << 7) + 1) << 6, (v25 + 10) << 13, 0, 0, 0, 0, 48);
    }
    else if ( gBoss[0].count2 == 75 )
    {
      v26 = Random(-3, 0);
      SetNpChar(282, ((gMap.width << 7) + 1) << 6, (v26 + 3) << 13, 0, 0, 0, 0, 48);
    }
  }
  if ( gBoss[0].xm > 128 )
    gBoss[0].xm = 128;
  if ( gBoss[0].xm < -128 )
    gBoss[0].xm = -128;
  if ( gBoss[0].ym > 128 )
    gBoss[0].ym = 128;
  if ( gBoss[0].ym < -128 )
    gBoss[0].ym = -128;
  gBoss[0].x += gBoss[0].xm;
  gBoss[0].y += gBoss[0].ym;
  _ActBossCharA_Face(&stru_81CD1C4);
  _ActBossCharA_Head(&stru_81CD270);
  _ActBossCharA_Tail(&stru_81CD31C);
  _ActBossCharA_Mini(&npc);
  _ActBossCharA_Mini(&stru_81CD118);
  _ActBossCharA_Mini(&stru_81CD3C8);
  _ActBossCharA_Mini(&stru_81CD474);
  _ActBossCharA_Hit(&stru_81CD520);
  _ActBossCharA_Hit(&stru_81CD5CC);
  _ActBossCharA_Hit(&stru_81CD678);
  _ActBossCharA_Hit(&stru_81CD724);
}

