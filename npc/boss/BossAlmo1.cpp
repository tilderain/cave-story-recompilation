//#include "types.h"
#include "SDL_stdinc.h"
#include "windows_wrapper.h"
#include "Tags.h"

void ActBossChar_Core_Face(NPCHAR *npc);
void ActBossChar_Core_Tail(NPCHAR *npc);
void ActBossChar_Core_Mini(NPCHAR *npc);
void ActBossChar_Core_Hit(NPCHAR *npc);
void ActBossChar_Core();
void InitCaret();

unsigned __int8 ActBossChar_Core(void)::_flash;

void ActBossChar_Core_Face(NPCHAR *npc)
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
    npc->x = unk_81CCFC8 - 18432;
    npc->y = unk_81CCFCC;
    goto LABEL_16;
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
        goto LABEL_16;
      }
      npc->x = unk_81CCFC8 - 18432;
      npc->y = unk_81CCFCC;
      goto LABEL_16;
    }
    npc->act_no = 51;
    npc->act_wait = 112;
    goto LABEL_12;
  }
  if ( v1 == 100 )
    npc->ani_no = 3;
LABEL_16:
  v2 = &rect[npc->ani_no];
  npc->rect.left = v2->left;
  npc->rect.top = v2->top;
  npc->rect.right = v2->right;
  npc->rect.bottom = v2->bottom;
  if ( npc->act_no == 51 )
    npc->rect.bottom = npc->act_wait + npc->rect.top;
}

void ActBossChar_Core_Tail(NPCHAR *npc)
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
    npc->x = unk_81CCFC8 + 22528;
    npc->y = unk_81CCFCC;
    goto LABEL_16;
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
        goto LABEL_16;
      }
      npc->x = unk_81CCFC8 + 22528;
      npc->y = unk_81CCFCC;
      goto LABEL_16;
    }
    npc->act_no = 51;
    npc->act_wait = 112;
    goto LABEL_12;
  }
  if ( v1 == 100 )
    npc->ani_no = 2;
LABEL_16:
  v2 = &rect[npc->ani_no];
  npc->rect.left = v2->left;
  npc->rect.top = v2->top;
  npc->rect.right = v2->right;
  npc->rect.bottom = v2->bottom;
  if ( npc->act_no == 51 )
    npc->rect.bottom = npc->act_wait + npc->rect.top;
}

void ActBossChar_Core_Mini(NPCHAR *npc)
{
  int v1;
  int v2;
  int v3;
  int v4;
  int v5;
  Sint32 *v6;
  RECT rect[3];
  int xm;
  int ym;
  unsigned __int8 deg;
  char v11[8];

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
  npc->life = 1000;
  v1 = npc->act_no;
  if ( v1 == 121 )
  {
LABEL_24:
    if ( ++npc->act_wait / 2 & 1 )
      npc->ani_no = 0;
    else
      npc->ani_no = 1;
    if ( npc->act_wait > 20 )
      npc->act_no = 130;
    goto LABEL_39;
  }
  if ( v1 > 121 )
  {
    if ( v1 == 140 )
    {
      npc->x += (npc->tgt_x - npc->x) / 16;
      npc->y += (npc->tgt_y - npc->y) / 16;
      goto LABEL_39;
    }
    if ( v1 > 140 )
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
        goto LABEL_39;
      }
      npc->xm += 32;
      npc->x += npc->xm;
      if ( npc->x > (gMap.width + 2) << 13 )
        npc->cond = 0;
    }
    else
    {
      if ( v1 == 130 )
      {
        npc->act_no = 131;
        npc->ani_no = 2;
        npc->act_wait = 0;
        v4 = npc->x;
        npc->tgt_x = v4 + (Random(24, 48) << 9);
        v5 = npc->y;
        npc->tgt_y = v5 + (Random(-4, 4) << 9);
      }
      else if ( v1 != 131 )
      {
        goto LABEL_39;
      }
      npc->x += (npc->tgt_x - npc->x) / 16;
      npc->y += (npc->tgt_y - npc->y) / 16;
      if ( ++npc->act_wait > 50 )
      {
        npc->act_no = 140;
        npc->ani_no = 0;
      }
      if ( npc->act_wait == 1 || npc->act_wait == 3 )
      {
        deg = GetArktan(npc->x - x, npc->y - y);
        deg += Random(-2, 2);
        ym = 2 * GetSin(deg);
        xm = 2 * GetCos(deg);
        SetNpChar(178, npc->x, npc->y, xm, ym, 0, 0, 256);
        PlaySoundObject(39, 1);
      }
    }
  }
  else
  {
    if ( v1 == 100 )
    {
      npc->act_no = 101;
      npc->ani_no = 2;
      npc->act_wait = 0;
      v2 = unk_81CCFC8;
      npc->tgt_x = v2 + (Random(-128, 32) << 9);
      v3 = unk_81CCFCC;
      npc->tgt_y = v3 + (Random(-64, 64) << 9);
      npc->bits |= 0x20u;
    }
    else
    {
      if ( v1 <= 100 )
      {
        if ( v1 && v1 == 10 )
        {
          npc->ani_no = 2;
          npc->bits &= 0xFFDFu;
        }
        goto LABEL_39;
      }
      if ( v1 != 101 )
      {
        if ( v1 != 120 )
          goto LABEL_39;
        npc->act_no = 121;
        npc->act_wait = 0;
        goto LABEL_24;
      }
    }
    npc->x += (npc->tgt_x - npc->x) / 16;
    npc->y += (npc->tgt_y - npc->y) / 16;
    if ( ++npc->act_wait > 50 )
      npc->ani_no = 0;
  }
LABEL_39:
  if ( npc->shock )
    npc->tgt_x += 1024;
  v6 = (Sint32 *)&v11[16 * npc->ani_no - 60];
  npc->rect.left = *v6;
  npc->rect.top = v6[1];
  npc->rect.right = v6[2];
  npc->rect.bottom = v6[3];
}


void ActBossChar_Core_Hit(NPCHAR *npc)
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

void ActBossChar_Core()
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
  unsigned __int8 deg;
  int ym;
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
  int v27;
  int v28;
  int v29;
  int v30;
  int v31;
  int v32;
  int v33;
  int v34;
  bool bShock;
  int i;
  int ia;
  int ib;

  bShock = 0;
  v0 = gBoss[0].act_no;
  if ( v0 == 211 )
  {
LABEL_27:
    gBoss[0].tgt_x = x;
    gBoss[0].tgt_y = y;
    if ( gBoss[0].shock )
    {
      if ( (++ActBossChar_Core(void)::_flash >> 1) & 1 )
      {
        stru_81CD270.ani_no = 0;
        stru_81CD31C.ani_no = 0;
      }
      else
      {
        stru_81CD270.ani_no = 1;
        stru_81CD31C.ani_no = 1;
      }
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
    if ( gBoss[0].act_wait <= 199 && gBoss[0].act_wait % 20 == 1 )
    {
      v2 = gBoss[0].y;
      v3 = (Random(-64, 64) << 9) + v2;
      v4 = gBoss[0].x;
      v5 = Random(-48, -16);
      SetNpChar(179, v4 + (v5 << 9), v3, 0, 0, 0, 0, 256);
    }
    if ( gBoss[0].act_wait > 400 || gBoss[0].life < gBoss[0].count2 - 200 )
    {
      gBoss[0].act_no = 200;
      stru_81CD270.ani_no = 2;
      stru_81CD31C.ani_no = 0;
      bShock = 1;
    }
    goto LABEL_75;
  }
  if ( v0 > 211 )
  {
    if ( v0 != 500 )
    {
      if ( v0 <= 500 )
      {
        if ( v0 == 220 )
        {
          gBoss[0].act_no = 221;
          gBoss[0].act_wait = 0;
          gSuperYpos = 1;
          stru_81CD724.bits |= 0x20u;
          SetQuake(100);
          SetNoise(1, 1000);
        }
        else if ( v0 != 221 )
        {
          goto LABEL_75;
        }
        ++gBoss[0].act_wait;
        v6 = y;
        v7 = (Random(-160, 160) << 9) + v6;
        v8 = x;
        v9 = Random(-50, 150);
        SetNpChar(199, v8 + (v9 << 10), v7, 0, 0, 0, 0, 256);
        unk_81C85B4 -= 32;
        gMC.cond |= 0x20u;
        if ( gBoss[0].shock )
        {
          if ( (++ActBossChar_Core(void)::_flash >> 1) & 1 )
          {
            stru_81CD270.ani_no = 0;
            stru_81CD31C.ani_no = 0;
          }
          else
          {
            stru_81CD270.ani_no = 1;
            stru_81CD31C.ani_no = 1;
          }
        }
        else
        {
          stru_81CD270.ani_no = 0;
          stru_81CD31C.ani_no = 0;
        }
        if ( gBoss[0].act_wait == 300 || gBoss[0].act_wait == 350 || gBoss[0].act_wait == 400 )
        {
          deg = GetArktan(gBoss[0].x - x, gBoss[0].y - y);
          ym = 3 * GetSin(deg);
          v12 = GetCos(deg);
          SetNpChar(218, gBoss[0].x - 20480, gBoss[0].y, 3 * v12, ym, 0, 0, 256);
          PlaySoundObject(101, 1);
        }
        if ( gBoss[0].act_wait > 400 )
        {
          gBoss[0].act_no = 200;
          stru_81CD270.ani_no = 2;
          stru_81CD31C.ani_no = 0;
          bShock = 1;
        }
        goto LABEL_75;
      }
      switch ( v0 )
      {
        case 600:
          gBoss[0].act_no = 601;
          stru_81CD270.act_no = 50;
          stru_81CD31C.act_no = 50;
          stru_81CD520.bits &= 0xFFFBu;
          stru_81CD5CC.bits &= 0xFFFBu;
          stru_81CD678.bits &= 0xFFFBu;
          stru_81CD724.bits &= 0xFFFBu;
          break;
        case 601:
          break;
        case 501:
          goto LABEL_58;
        default:
          goto LABEL_75;
      }
      if ( ++gBoss[0].act_wait / 2 & 1 )
        v28 = gBoss[0].x - 2048;
      else
        v28 = gBoss[0].x + 2048;
      gBoss[0].x = v28;
      goto LABEL_75;
    }
    CutNoise();
    gBoss[0].act_no = 501;
    gBoss[0].act_wait = 0;
    gBoss[0].xm = 0;
    gBoss[0].ym = 0;
    stru_81CD270.ani_no = 2;
    stru_81CD31C.ani_no = 0;
    npc.act_no = 200;
    stru_81CD118.act_no = 200;
    stru_81CD1C4.act_no = 200;
    stru_81CD3C8.act_no = 200;
    stru_81CD474.act_no = 200;
    SetQuake(20);
    for ( i = 0; i <= 31; ++i )
    {
      v13 = Random(-128, 128) << 9;
      v14 = Random(-128, 128) << 9;
      v15 = gBoss[0].y;
      v16 = (Random(-64, 64) << 9) + v15;
      v17 = gBoss[0].x;
      v18 = Random(-128, 128);
      SetNpChar(4, v17 + (v18 << 9), v16, v14, v13, 0, 0, 256);
    }
    for ( ia = 0; ia <= 11; ++ia )
      *((_WORD *)&unk_81CD010 + 86 * ia) &= 0xFFDBu;
LABEL_58:
    if ( ++gBoss[0].act_wait & 0xF )
    {
      v19 = Random(-128, 128) << 9;
      v20 = Random(-128, 128) << 9;
      v21 = gBoss[0].y;
      v22 = (Random(-32, 32) << 9) + v21;
      v23 = gBoss[0].x;
      v24 = Random(-64, 64);
      SetNpChar(4, v23 + (v24 << 9), v22, v20, v19, 0, 0, 256);
    }
    if ( gBoss[0].act_wait / 2 & 1 )
      v25 = gBoss[0].x - 512;
    else
      v25 = gBoss[0].x + 512;
    gBoss[0].x = v25;
    if ( gBoss[0].x > 516095 )
      v26 = gBoss[0].x - 128;
    else
      v26 = gBoss[0].x + 128;
    gBoss[0].x = v26;
    if ( gBoss[0].y > 90111 )
      v27 = gBoss[0].y - 128;
    else
      v27 = gBoss[0].y + 128;
    gBoss[0].y = v27;
    goto LABEL_75;
  }
  if ( v0 == 200 )
  {
    gBoss[0].act_no = 201;
    gBoss[0].act_wait = 0;
    stru_81CD724.bits &= 0xFFDFu;
    gSuperYpos = 0;
    CutNoise();
  }
  else
  {
    if ( v0 <= 200 )
    {
      if ( !v0 )
      {
        gBoss[0].act_no = 10;
        gBoss[0].exp = 1;
        gBoss[0].cond = -128;
        gBoss[0].bits = -32756;
        gBoss[0].life = 650;
        gBoss[0].hit_voice = 114;
        gBoss[0].x = 630784;
        gBoss[0].y = 114688;
        gBoss[0].xm = 0;
        gBoss[0].ym = 0;
        gBoss[0].code_event = 1000;
        v1 = gBoss[0].bits;
        HIBYTE(v1) |= 2u;
        gBoss[0].bits = v1;
        stru_81CD270.cond = -128;
        stru_81CD270.act_no = 10;
        stru_81CD31C.cond = -128;
        stru_81CD31C.act_no = 10;
        stru_81CD520.cond = -128;
        stru_81CD520.bits = 12;
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
        npc.act_no = 10;
        npc.bits = 44;
        npc.life = 1000;
        npc.hit_voice = 54;
        npc.hit.back = 12288;
        npc.hit.top = 0x2000;
        npc.hit.bottom = 0x2000;
        npc.view.front = 0x4000;
        npc.view.top = 10240;
        npc.x = gBoss[0].x - 4096;
        npc.y = gBoss[0].y - 0x8000;
        qmemcpy(&stru_81CD118, &npc, sizeof(stru_81CD118));
        stru_81CD118.x = gBoss[0].x + 0x2000;
        stru_81CD118.y = gBoss[0].y;
        qmemcpy(&stru_81CD1C4, &npc, sizeof(stru_81CD1C4));
        stru_81CD1C4.x = gBoss[0].x - 4096;
        stru_81CD1C4.y = gBoss[0].y + 0x8000;
        qmemcpy(&stru_81CD3C8, &npc, sizeof(stru_81CD3C8));
        stru_81CD3C8.x = gBoss[0].x - 24576;
        stru_81CD3C8.y = gBoss[0].y - 0x4000;
        qmemcpy(&stru_81CD474, &npc, sizeof(stru_81CD474));
        stru_81CD474.x = gBoss[0].x - 24576;
        stru_81CD474.y = gBoss[0].y + 0x4000;
      }
      goto LABEL_75;
    }
    if ( v0 != 201 )
    {
      if ( v0 != 210 )
        goto LABEL_75;
      gBoss[0].act_no = 211;
      gBoss[0].act_wait = 0;
      gBoss[0].count2 = gBoss[0].life;
      stru_81CD724.bits |= 0x20u;
      goto LABEL_27;
    }
  }
  gBoss[0].tgt_x = x;
  gBoss[0].tgt_y = y;
  if ( ++gBoss[0].act_wait > 400 )
  {
    ++gBoss[0].count1;
    PlaySoundObject(115, 1);
    if ( gBoss[0].count1 <= 3 )
    {
      gBoss[0].act_no = 210;
    }
    else
    {
      gBoss[0].count1 = 0;
      gBoss[0].act_no = 220;
    }
    stru_81CD270.ani_no = 0;
    stru_81CD31C.ani_no = 0;
    bShock = 1;
  }
LABEL_75:
  if ( bShock )
  {
    SetQuake(20);
    npc.act_no = 100;
    stru_81CD118.act_no = 100;
    stru_81CD1C4.act_no = 100;
    stru_81CD3C8.act_no = 100;
    stru_81CD474.act_no = 100;
    PlaySoundObject(26, 1);
    for ( ib = 0; ib <= 7; ++ib )
    {
      v29 = Random(-256, 256);
      v30 = Random(-512, 512);
      v31 = stru_81CD270.y;
      v32 = stru_81CD270.x;
      v33 = Random(-32, 16);
      SetNpChar(4, v32 + (v33 << 9), v31, v30, v29, 0, 0, 256);
    }
  }
  if ( gBoss[0].act_no > 199 && gBoss[0].act_no <= 299 )
  {
    v34 = gBoss[0].act_wait;
    if ( v34 == 140 )
    {
      stru_81CD1C4.act_no = 120;
    }
    else if ( v34 > 140 )
    {
      if ( v34 == 170 )
      {
        stru_81CD3C8.act_no = 120;
      }
      else if ( v34 == 200 )
      {
        stru_81CD474.act_no = 120;
      }
    }
    else if ( v34 == 80 )
    {
      npc.act_no = 120;
    }
    else if ( v34 == 110 )
    {
      stru_81CD118.act_no = 120;
    }
    if ( gBoss[0].x < gBoss[0].tgt_x + 81920 )
      gBoss[0].xm += 4;
    if ( gBoss[0].x > gBoss[0].tgt_x + 81920 )
      gBoss[0].xm -= 4;
    if ( gBoss[0].y < gBoss[0].tgt_y )
      gBoss[0].ym += 4;
    if ( gBoss[0].y > gBoss[0].tgt_y )
      gBoss[0].ym -= 4;
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
  ActBossChar_Core_Face(&stru_81CD270);
  ActBossChar_Core_Tail(&stru_81CD31C);
  ActBossChar_Core_Mini(&npc);
  ActBossChar_Core_Mini(&stru_81CD118);
  ActBossChar_Core_Mini(&stru_81CD1C4);
  ActBossChar_Core_Mini(&stru_81CD3C8);
  ActBossChar_Core_Mini(&stru_81CD474);
  ActBossChar_Core_Hit(&stru_81CD520);
  ActBossChar_Core_Hit(&stru_81CD5CC);
  ActBossChar_Core_Hit(&stru_81CD678);
  ActBossChar_Core_Hit(&stru_81CD724);
}

void InitCaret()
{
  memset(gCrt, 0, 0x1100u);
}

