#include "types.h"
#include "SDL_stdinc.h"
#include "windows_wrapper.h"
#include "Tags.h"
void __cdecl _ActBossChar_Eye(NPCHAR_0 *npc)
{
  int v1;
  unsigned __int16 v2;
  NPCHAR_0 *v3;
  Sint32 *v4;
  RECT rcRight[5];
  RECT rcLeft[5];
  char v7[24];

  qmemcpy(rcLeft, &_ActBossChar_Eye(NPCHAR *)::C.0, sizeof(rcLeft));
  qmemcpy(rcRight, &_ActBossChar_Eye(NPCHAR *)::C.1, sizeof(rcRight));
  v1 = npc->act_no;
  if ( v1 == 102 )
  {
    npc->ani_no = 3;
    goto LABEL_27;
  }
  if ( v1 > 102 )
  {
    if ( v1 != 201 )
    {
      if ( v1 > 201 )
      {
        if ( v1 != 202 && v1 == 300 )
        {
          npc->act_no = 301;
          npc->ani_no = 4;
          if ( npc->direct )
            SetDestroyNpChar(npc->x + 2048, npc->y, 2048, 10);
          else
            SetDestroyNpChar(npc->x - 2048, npc->y, 2048, 10);
        }
        goto LABEL_27;
      }
      if ( v1 != 200 )
        goto LABEL_27;
      npc->act_no = 201;
      npc->ani_no = 3;
      npc->ani_wait = 0;
    }
    if ( ++npc->ani_wait > 2 )
    {
      npc->ani_wait = 0;
      --npc->ani_no;
    }
    if ( npc->ani_no <= 0 )
      npc->act_no = 202;
    goto LABEL_27;
  }
  if ( v1 == 100 )
  {
    npc->act_no = 101;
    npc->ani_no = 0;
    npc->ani_wait = 0;
  }
  else if ( v1 <= 100 )
  {
    goto LABEL_27;
  }
  if ( ++npc->ani_wait > 2 )
  {
    npc->ani_wait = 0;
    ++npc->ani_no;
  }
  if ( npc->ani_no > 2 )
    npc->act_no = 102;
LABEL_27:
  if ( npc->direct )
    npc->x = unk_81CCFC8 + 12288;
  else
    npc->x = unk_81CCFC8 - 12288;
  npc->y = unk_81CCFCC - 18432;
  if ( npc->act_no >= 0 && npc->act_no <= 299 )
  {
    if ( npc->ani_no == 3 )
      v2 = npc->bits | 0x20;
    else
      v2 = npc->bits & 0xFFDF;
    npc->bits = v2;
  }
  if ( npc->direct )
  {
    v3 = npc;
    v4 = (Sint32 *)&v7[16 * npc->ani_no - 160];
  }
  else
  {
    v3 = npc;
    v4 = (Sint32 *)&v7[16 * npc->ani_no - 80];
  }
  npc->rect.left = *v4;
  v3->rect.top = v4[1];
  v3->rect.right = v4[2];
  v3->rect.bottom = v4[3];
}


void __cdecl _ActBossChar_Body(NPCHAR_0 *npc)
{
  RECT *v1;
  RECT rc[4];

  rc[0].left = 0;
  rc[0].top = 0;
  rc[0].right = 120;
  rc[0].bottom = 120;
  rc[1].left = 120;
  rc[1].top = 0;
  rc[1].right = 240;
  rc[1].bottom = 120;
  rc[2].left = 0;
  rc[2].top = 120;
  rc[2].right = 120;
  rc[2].bottom = 240;
  rc[3].left = 120;
  rc[3].top = 120;
  rc[3].right = 240;
  rc[3].bottom = 240;
  npc->x = unk_81CCFC8;
  npc->y = unk_81CCFCC;
  v1 = &rc[npc->ani_no];
  npc->rect.left = v1->left;
  npc->rect.top = v1->top;
  npc->rect.right = v1->right;
  npc->rect.bottom = v1->bottom;
}

void __cdecl _ActBossChar_HITAI(NPCHAR_0 *npc)
{
  npc->x = unk_81CCFC8;
  npc->y = unk_81CCFCC - 22528;
}

void __cdecl _ActBossChar_HARA(NPCHAR_0 *npc)
{
  npc->x = unk_81CCFC8;
  npc->y = unk_81CCFCC;
}

void ActBossChar_Ballos()
{
  int v0;
  int v1;
  int v2;
  int v3;
  int v4;
  int v5;
  int v6;
  int v7;
  int x;
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
  int i;
  int ia;
  int ib;
  signed int ic;
  signed int id;
  int ie;
  int ig;
  int ih;
  int ii;

  v0 = gBoss[0].act_no;
  if ( v0 == 312 )
  {
    gBoss[0].direct = 1;
    gBoss[0].ym = -938;
    gBoss[0].xm = 0;
    gBoss[0].y += gBoss[0].ym;
    if ( gBoss[0].y <= 56831 )
    {
      gBoss[0].y = 56832;
      gBoss[0].act_no = 313;
    }
    goto LABEL_171;
  }
  if ( v0 > 312 )
  {
    if ( v0 == 422 )
    {
      if ( ++gBoss[0].ani_wait > 200 )
      {
        gBoss[0].ani_wait = 0;
        gBoss[0].act_no = 423;
      }
      goto LABEL_171;
    }
    if ( v0 <= 422 )
    {
      if ( v0 != 401 )
      {
        if ( v0 > 401 )
        {
          if ( v0 == 411 )
          {
            if ( ++gBoss[0].act_wait % 30 == 1 )
              SetNpChar(348, (gBoss[0].act_wait / 30 + 1) << 14, 172032, 0, 0, 0, 0, 384);
            if ( gBoss[0].act_wait / 3 & 1 )
              PlaySoundObject(26, 1);
            if ( gBoss[0].act_wait > 540 )
              gBoss[0].act_no = 420;
          }
          else if ( v0 > 411 )
          {
            if ( v0 == 420 )
            {
              gBoss[0].act_no = 421;
              gBoss[0].act_wait = 0;
              gBoss[0].ani_wait = 0;
              SetQuake2(30);
              PlaySoundObject(35, 1);
              npc.act_no = 102;
              stru_81CD118.act_no = 102;
              for ( ie = 0; ie <= 255; ++ie )
              {
                v7 = gBoss[0].x;
                x = v7 + (Random(-60, 60) << 9);
                v9 = gBoss[0].y;
                v10 = Random(-60, 60);
                SetNpChar(4, x, v9 + (v10 << 9), 0, 0, 0, 0, 0);
              }
            }
            else if ( v0 != 421 )
            {
              goto LABEL_171;
            }
            if ( ++gBoss[0].ani_wait > 500 )
            {
              gBoss[0].ani_wait = 0;
              gBoss[0].act_no = 422;
            }
          }
          else if ( v0 == 410 && ++gBoss[0].act_wait > 50 )
          {
            gBoss[0].act_wait = 0;
            gBoss[0].act_no = 411;
          }
          goto LABEL_171;
        }
        if ( v0 == 314 )
        {
          gBoss[0].direct = 3;
          gBoss[0].ym = 938;
          gBoss[0].xm = 0;
          gBoss[0].y += gBoss[0].ym;
          if ( gBoss[0].y > 115200 )
          {
            gBoss[0].y = 115200;
            gBoss[0].act_no = 311;
          }
          goto LABEL_171;
        }
        if ( v0 < 314 )
        {
          gBoss[0].direct = 2;
          gBoss[0].xm = 938;
          gBoss[0].ym = 0;
          gBoss[0].x += gBoss[0].xm;
          if ( gBoss[0].x > 262656 )
          {
            gBoss[0].x = 262656;
            gBoss[0].act_no = 314;
          }
          if ( gBoss[0].count1 )
            --gBoss[0].count1;
          if ( !gBoss[0].count1 && gBoss[0].x > 155648 && gBoss[0].x <= 172031 )
            gBoss[0].act_no = 400;
          goto LABEL_171;
        }
        if ( v0 != 400 )
          goto LABEL_171;
        gBoss[0].act_no = 401;
        gBoss[0].act_wait = 0;
        gBoss[0].xm = 0;
        gBoss[0].ym = 0;
        DeleteNpCharCode(339, 0);
      }
      gBoss[0].y += (81408 - gBoss[0].y) / 8;
      if ( ++gBoss[0].act_wait > 50 )
      {
        gBoss[0].act_wait = 0;
        gBoss[0].act_no = 410;
        for ( id = 0; id <= 255; id += 32 )
          SetNpChar(346, gBoss[0].x, gBoss[0].y, 0, 0, id, gBoss, 80);
        SetNpChar(343, gBoss[0].x, gBoss[0].y, 0, 0, 0, gBoss, 24);
        SetNpChar(344, gBoss[0].x - 12288, gBoss[0].y - 18432, 0, 0, 0, gBoss, 32);
        SetNpChar(344, gBoss[0].x + 12288, gBoss[0].y - 18432, 0, 0, 2, gBoss, 32);
      }
      goto LABEL_171;
    }
    if ( v0 == 427 )
    {
      if ( ++gBoss[0].ani_wait > 20 )
      {
        gBoss[0].ani_wait = 0;
        gBoss[0].act_no = 428;
      }
    }
    else
    {
      if ( v0 <= 427 )
      {
        if ( v0 == 424 )
        {
          if ( ++gBoss[0].ani_wait > 200 )
          {
            gBoss[0].ani_wait = 0;
            gBoss[0].act_no = 425;
          }
        }
        else if ( v0 < 424 )
        {
          if ( ++gBoss[0].ani_wait > 20 )
          {
            gBoss[0].ani_wait = 0;
            gBoss[0].act_no = 424;
          }
        }
        else if ( v0 == 425 )
        {
          if ( ++gBoss[0].ani_wait > 500 )
          {
            gBoss[0].ani_wait = 0;
            gBoss[0].act_no = 426;
          }
        }
        else if ( v0 == 426 && ++gBoss[0].ani_wait > 200 )
        {
          gBoss[0].ani_wait = 0;
          gBoss[0].act_no = 427;
        }
        goto LABEL_171;
      }
      if ( v0 == 1000 )
      {
        gBoss[0].act_no = 1001;
        gBoss[0].act_wait = 0;
        npc.act_no = 300;
        stru_81CD118.act_no = 300;
        unk_81CD010 &= 0xFFBEu;
        stru_81CD1C4.bits &= 0xFFBEu;
        stru_81CD270.bits &= 0xFFBEu;
        stru_81CD31C.bits &= 0xFFBEu;
      }
      else
      {
        if ( v0 <= 1000 )
        {
          if ( v0 == 428 && ++gBoss[0].ani_wait > 200 )
          {
            gBoss[0].ani_wait = 0;
            gBoss[0].act_no = 421;
          }
          goto LABEL_171;
        }
        if ( v0 != 1001 )
        {
          if ( v0 == 1002 )
          {
            SetQuake2(40);
            if ( ++dword_81CD038 == 50 )
            {
              gBoss[0].cond = 0;
              npc.cond = 0;
              stru_81CD118.cond = 0;
              stru_81CD1C4.cond = 0;
              stru_81CD270.cond = 0;
              stru_81CD31C.cond = 0;
              DeleteNpCharCode(350, 1);
              DeleteNpCharCode(348, 1);
            }
          }
          goto LABEL_171;
        }
      }
      if ( !(++dword_81CD038 % 12) )
        PlaySoundObject(44, 1);
      v11 = unk_81CCFCC;
      v12 = (Random(-60, 60) << 9) + v11;
      v13 = unk_81CCFC8;
      v14 = Random(-60, 60);
      SetDestroyNpChar(v13 + (v14 << 9), v12, 1, 1);
      if ( dword_81CD038 > 150 )
      {
        dword_81CD038 = 0;
        unk_81CD034 = 1002;
        SetFlash(unk_81CCFC8, unk_81CCFCC, 1);
        PlaySoundObject(35, 1);
      }
    }
  }
  else
  {
    if ( v0 == 201 )
    {
LABEL_80:
      gBoss[0].act_no = 203;
      gBoss[0].xm = 0;
      ++gBoss[0].count1;
      gBoss[0].hit.bottom = 24576;
      gBoss[0].damage = 0;
      if ( gBoss[0].count1 % 3 )
        gBoss[0].act_wait = 50;
      else
        gBoss[0].act_wait = 150;
LABEL_83:
      if ( --gBoss[0].act_wait <= 0 )
      {
        gBoss[0].act_no = 204;
        gBoss[0].ym = -3072;
        if ( gBoss[0].x >= ::x )
          gBoss[0].xm = -512;
        else
          gBoss[0].xm = 512;
      }
      goto LABEL_171;
    }
    if ( v0 > 201 )
    {
      if ( v0 == 222 )
        goto LABEL_171;
      if ( v0 > 222 )
      {
        if ( v0 != 301 )
        {
          if ( v0 > 301 )
          {
            if ( v0 != 310 && v0 == 311 )
            {
              gBoss[0].direct = 0;
              gBoss[0].xm = -938;
              gBoss[0].ym = 0;
              gBoss[0].x += gBoss[0].xm;
              if ( gBoss[0].x <= 56831 )
              {
                gBoss[0].x = 56832;
                gBoss[0].act_no = 312;
              }
            }
            goto LABEL_171;
          }
          if ( v0 != 300 )
            goto LABEL_171;
          gBoss[0].act_no = 301;
          gBoss[0].act_wait = 0;
          for ( ic = 0; ic <= 255; ic += 64 )
          {
            SetNpChar(342, gBoss[0].x, gBoss[0].y, 0, 0, ic, gBoss, 90);
            SetNpChar(342, gBoss[0].x, gBoss[0].y, 0, 0, ic + 544, gBoss, 90);
          }
          SetNpChar(343, gBoss[0].x, gBoss[0].y, 0, 0, 0, gBoss, 24);
          SetNpChar(344, gBoss[0].x - 12288, gBoss[0].y - 18432, 0, 0, 0, gBoss, 32);
          SetNpChar(344, gBoss[0].x + 12288, gBoss[0].y - 18432, 0, 0, 2, gBoss, 32);
        }
        gBoss[0].y += (115200 - gBoss[0].y) / 8;
        if ( ++gBoss[0].act_wait > 50 )
        {
          gBoss[0].act_no = 310;
          gBoss[0].act_wait = 0;
        }
        goto LABEL_171;
      }
      if ( v0 == 204 )
      {
        if ( gBoss[0].x <= 40959 )
          gBoss[0].xm = 512;
        if ( gBoss[0].x > 278528 )
          gBoss[0].xm = -512;
        gBoss[0].ym += 85;
        if ( gBoss[0].ym > 3072 )
          gBoss[0].ym = 3072;
        gBoss[0].x += gBoss[0].xm;
        gBoss[0].y += gBoss[0].ym;
        if ( gBoss[0].y > 155648 - gBoss[0].hit.bottom )
        {
          gBoss[0].y = 155648 - gBoss[0].hit.bottom;
          gBoss[0].ym = 0;
          gBoss[0].act_no = 201;
          gBoss[0].act_wait = 0;
          if ( y > gBoss[0].y + 28672 )
            DamageMyChar(16);
          if ( dword_81C8584 & 8 )
            unk_81C85B8 = -512;
          SetQuake2(30);
          PlaySoundObject(26, 1);
          SetNpChar(332, gBoss[0].x - 6144, gBoss[0].y + 26624, 0, 0, 0, 0, 256);
          SetNpChar(332, gBoss[0].x + 6144, gBoss[0].y + 26624, 0, 0, 2, 0, 256);
          PlaySoundObject(44, 1);
          for ( ia = 0; ia <= 15; ++ia )
          {
            v3 = gBoss[0].x;
            v4 = Random(-40, 40);
            SetNpChar(4, v3 + (v4 << 9), gBoss[0].y + 20480, 0, 0, 0, 0, 256);
          }
        }
      }
      else
      {
        if ( v0 <= 204 )
        {
          if ( v0 != 203 )
            goto LABEL_171;
          goto LABEL_83;
        }
        if ( v0 == 220 )
        {
          gBoss[0].act_no = 221;
          gBoss[0].life = 1200;
          npc.act_no = 200;
          stru_81CD118.act_no = 200;
          gBoss[0].xm = 0;
          gBoss[0].ani_no = 0;
          gBoss[0].shock = 0;
          ActBossChar_Ballos(void)::_flash = 0;
        }
        else if ( v0 != 221 )
        {
          goto LABEL_171;
        }
        gBoss[0].ym += 64;
        if ( gBoss[0].ym > 3072 )
          gBoss[0].ym = 3072;
        gBoss[0].y += gBoss[0].ym;
        if ( gBoss[0].y > 155648 - gBoss[0].hit.bottom )
        {
          gBoss[0].y = 155648 - gBoss[0].hit.bottom;
          gBoss[0].ym = 0;
          gBoss[0].act_no = 222;
          gBoss[0].act_wait = 0;
          SetQuake2(30);
          PlaySoundObject(26, 1);
          for ( ib = 0; ib <= 15; ++ib )
          {
            v5 = gBoss[0].x;
            v6 = Random(-40, 40);
            SetNpChar(4, v5 + (v6 << 9), gBoss[0].y + 20480, 0, 0, 0, 0, 256);
          }
          if ( dword_81C8584 & 8 )
            unk_81C85B8 = -512;
        }
      }
    }
    else
    {
      if ( v0 == 101 )
      {
LABEL_63:
        if ( ++gBoss[0].act_wait > 30 )
          gBoss[0].act_no = 102;
        goto LABEL_171;
      }
      if ( v0 <= 101 )
      {
        if ( v0 == 1 )
          goto LABEL_171;
        if ( v0 != 100 )
        {
          if ( !v0 )
          {
            gBoss[0].act_no = 1;
            gBoss[0].cond = -128;
            gBoss[0].exp = 1;
            gBoss[0].direct = 0;
            gBoss[0].x = 163840;
            gBoss[0].y = -32768;
            gBoss[0].hit_voice = 54;
            gBoss[0].hit.front = 0x4000;
            gBoss[0].hit.top = 24576;
            gBoss[0].hit.back = 0x4000;
            gBoss[0].hit.bottom = 24576;
            gBoss[0].bits = -32184;
            gBoss[0].size = 3;
            gBoss[0].damage = 0;
            gBoss[0].code_event = 1000;
            gBoss[0].life = 800;
            npc.cond = -112;
            npc.direct = 0;
            npc.bits = 8;
            npc.life = 10000;
            npc.view.front = 6144;
            npc.view.top = 0;
            npc.view.back = 6144;
            npc.view.bottom = 0x2000;
            npc.hit.front = 6144;
            npc.hit.top = 0;
            npc.hit.back = 6144;
            npc.hit.bottom = 0x2000;
            qmemcpy(&stru_81CD118, &npc, sizeof(stru_81CD118));
            stru_81CD118.direct = 2;
            stru_81CD1C4.cond = -112;
            stru_81CD1C4.bits = 13;
            stru_81CD1C4.view.front = 30720;
            stru_81CD1C4.view.top = 30720;
            stru_81CD1C4.view.back = 30720;
            stru_81CD1C4.view.bottom = 30720;
            stru_81CD1C4.hit.front = 24576;
            stru_81CD1C4.hit.top = 12288;
            stru_81CD1C4.hit.back = 24576;
            stru_81CD1C4.hit.bottom = 0x4000;
            stru_81CD270.cond = -112;
            stru_81CD270.bits = 13;
            stru_81CD270.hit.front = 0x4000;
            stru_81CD270.hit.top = 4096;
            stru_81CD270.hit.back = 0x4000;
            stru_81CD270.hit.bottom = 4096;
            stru_81CD31C.cond = -112;
            stru_81CD31C.bits = 76;
            stru_81CD31C.hit.front = 0x4000;
            stru_81CD31C.hit.top = 0;
            stru_81CD31C.hit.back = 0x4000;
            stru_81CD31C.hit.bottom = 24576;
          }
          goto LABEL_171;
        }
        gBoss[0].act_no = 101;
        gBoss[0].ani_no = 0;
        gBoss[0].x = ::x;
        SetNpChar(333, ::x, 155648, 0, 0, 2, 0, 256);
        gBoss[0].act_wait = 0;
        goto LABEL_63;
      }
      if ( v0 == 103 )
      {
        if ( ++gBoss[0].act_wait == 50 )
        {
          gBoss[0].act_no = 104;
          npc.act_no = 100;
          stru_81CD118.act_no = 100;
        }
      }
      else
      {
        if ( v0 >= 103 )
        {
          if ( v0 == 104 || v0 != 200 )
            goto LABEL_171;
          gBoss[0].act_no = 201;
          gBoss[0].count1 = 0;
          goto LABEL_80;
        }
        gBoss[0].ym += 64;
        if ( gBoss[0].ym > 3072 )
          gBoss[0].ym = 3072;
        gBoss[0].y += gBoss[0].ym;
        if ( gBoss[0].y > 155648 - gBoss[0].hit.bottom )
        {
          gBoss[0].y = 155648 - gBoss[0].hit.bottom;
          gBoss[0].ym = 0;
          gBoss[0].act_no = 103;
          gBoss[0].act_wait = 0;
          SetQuake2(30);
          PlaySoundObject(44, 1);
          if ( y > gBoss[0].y + 24576 && ::x < gBoss[0].x + 12288 && ::x > gBoss[0].x - 12288 )
            DamageMyChar(16);
          for ( i = 0; i <= 15; ++i )
          {
            v1 = gBoss[0].x;
            v2 = Random(-40, 40);
            SetNpChar(4, v1 + (v2 << 9), gBoss[0].y + 20480, 0, 0, 0, 0, 256);
          }
          if ( dword_81C8584 & 8 )
            unk_81C85B8 = -512;
        }
      }
    }
  }
LABEL_171:
  if ( gBoss[0].act_no > 420 && gBoss[0].act_no <= 499 )
  {
    stru_81CD1C4.bits |= 0x20u;
    stru_81CD270.bits |= 0x20u;
    stru_81CD31C.bits |= 0x20u;
    if ( ++gBoss[0].act_wait > 300 )
    {
      gBoss[0].act_wait = 0;
      if ( ::x <= gBoss[0].x )
      {
        for ( ih = 0; ih <= 7; ++ih )
        {
          v17 = (Random(-4, 4) << 13) / 4;
          v18 = Random(8, 68);
          SetNpChar(350, v17, (v18 << 13) / 4, 0, 0, 2, 0, 256);
        }
      }
      else
      {
        for ( ig = 0; ig <= 7; ++ig )
        {
          v15 = ((Random(-4, 4) + 156) << 13) / 4;
          v16 = Random(8, 68);
          SetNpChar(350, v15, (v16 << 13) / 4, 0, 0, 0, 0, 256);
        }
      }
    }
    if ( gBoss[0].act_wait == 270 || gBoss[0].act_wait == 280 || gBoss[0].act_wait == 290 )
    {
      SetNpChar(353, gBoss[0].x, gBoss[0].y - 26624, 0, 0, 1, 0, 256);
      PlaySoundObject(39, 1);
      for ( ii = 0; ii <= 3; ++ii )
        SetNpChar(4, gBoss[0].x, gBoss[0].y - 26624, 0, 0, 0, 0, 256);
    }
    if ( gBoss[0].life <= 500 )
    {
      if ( Random(0, 4) == 2 )
      {
        v23 = gBoss[0].x;
        v24 = v23 + (Random(-40, 40) << 9);
        v25 = gBoss[0].y;
        v26 = Random(0, 40);
        SetNpChar(270, v24, v25 + (v26 << 9), 0, 0, 3, 0, 0);
      }
    }
    else if ( Random(0, 10) == 2 )
    {
      v19 = gBoss[0].x;
      v20 = v19 + (Random(-40, 40) << 9);
      v21 = gBoss[0].y;
      v22 = Random(0, 40);
      SetNpChar(270, v20, v21 + (v22 << 9), 0, 0, 3, 0, 0);
    }
  }
  if ( gBoss[0].shock )
    stru_81CD1C4.ani_no = ((++ActBossChar_Ballos(void)::_flash >> 1) & 1) != 0;
  else
    stru_81CD1C4.ani_no = 0;
  if ( gBoss[0].act_no > 420 )
    stru_81CD1C4.ani_no += 2;
  _ActBossChar_Eye(&npc);
  _ActBossChar_Eye(&stru_81CD118);
  _ActBossChar_Body(&stru_81CD1C4);
  _ActBossChar_HITAI(&stru_81CD270);
  _ActBossChar_HARA(&stru_81CD31C);
}

void __cdecl ActNpc280(NPCHAR_0 *npc)
{
  int v1;
  NPCHAR_0 *v2;
  Sint32 *v3;
  int v4;
  RECT rcRight[2];
  RECT rcLeft[2];
  char v7[8];

  rcLeft[0].left = 112;
  rcLeft[0].top = 32;
  rcLeft[0].right = 128;
  rcLeft[0].bottom = 48;
  rcLeft[1].left = 144;
  rcLeft[1].top = 32;
  rcLeft[1].right = 160;
  rcLeft[1].bottom = 48;
  rcRight[0].left = 112;
  rcRight[0].top = 48;
  rcRight[0].right = 128;
  rcRight[0].bottom = 64;
  rcRight[1].left = 144;
  rcRight[1].top = 48;
  rcRight[1].right = 160;
  rcRight[1].bottom = 64;
  v1 = npc->act_no;
  if ( v1 == 1 )
  {
LABEL_5:
    if ( ++npc->act_wait == 64 )
    {
      npc->act_no = 2;
      npc->act_wait = 0;
    }
    goto LABEL_9;
  }
  if ( v1 != 2 )
  {
    if ( v1 )
      goto LABEL_9;
    npc->act_no = 1;
    npc->ani_no = 0;
    npc->ani_wait = 0;
    npc->x += 3072;
    npc->tgt_x = npc->x;
    PlaySoundObject(29, 1);
    goto LABEL_5;
  }
  npc->ani_no = 0;
  if ( npc->flag & 8 )
  {
    npc->act_no = 4;
    npc->act_wait = 0;
    npc->ani_no = 1;
    PlaySoundObject(23, 1);
  }
LABEL_9:
  if ( npc->act_no > 1 )
  {
    npc->ym += 32;
    if ( npc->ym > 1535 )
      npc->ym = 1535;
    npc->y += npc->ym;
  }
  if ( npc->direct )
  {
    v2 = npc;
    v3 = (Sint32 *)&v7[16 * npc->ani_no - 64];
  }
  else
  {
    v2 = npc;
    v3 = (Sint32 *)&v7[16 * npc->ani_no - 32];
  }
  npc->rect.left = *v3;
  v2->rect.top = v3[1];
  v2->rect.right = v3[2];
  v2->rect.bottom = v3[3];
  if ( npc->act_no == 1 )
  {
    npc->rect.bottom = npc->act_wait / 4 + npc->rect.top;
    if ( npc->act_wait / 2 & 1 )
      v4 = npc->tgt_x;
    else
      v4 = npc->tgt_x + 512;
    npc->x = v4;
  }
}


