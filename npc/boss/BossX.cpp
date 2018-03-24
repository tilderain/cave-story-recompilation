#include "types.h"
#include "SDL_stdinc.h"
#include "windows_wrapper.h"
#include "Tags.h"
void __cdecl ActBossChar03_01(NPCHAR_0 *npc)
{
  int v1;
  unsigned __int16 v2;
  unsigned __int16 v3;
  unsigned __int16 v4;
  NPCHAR_0 *v5;
  Sint32 *v6;
  RECT rcDown[6];
  RECT rcUp[6];
  char v9[24];

  qmemcpy(rcUp, &ActBossChar03_01(NPCHAR *)::C.0, sizeof(rcUp));
  qmemcpy(rcDown, &ActBossChar03_01(NPCHAR *)::C.1, sizeof(rcDown));
  v1 = npc->act_no;
  if ( v1 == 201 )
  {
LABEL_37:
    if ( ++npc->act_wait > 30 )
      npc->act_no = 202;
    if ( ++npc->ani_wait > 0 )
    {
      npc->ani_wait = 0;
      ++npc->ani_no;
    }
    if ( npc->ani_no > 5 )
      npc->ani_no = 4;
    npc->xm += 32;
    goto LABEL_64;
  }
  if ( v1 <= 201 )
  {
    if ( v1 == 101 )
      goto LABEL_23;
    if ( v1 <= 101 )
    {
      if ( v1 == 10 )
      {
        npc->ani_no = 0;
        npc->bits &= 0xFFEFu;
        goto LABEL_64;
      }
      if ( v1 != 100 )
        goto LABEL_64;
      npc->bits |= 0x10u;
      npc->act_no = 101;
      npc->act_wait = 0;
      npc->ani_no = 2;
      npc->ani_wait = 0;
LABEL_23:
      if ( ++npc->act_wait > 30 )
        npc->act_no = 102;
      if ( ++npc->ani_wait > 0 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 3 )
        npc->ani_no = 2;
      npc->xm -= 32;
      goto LABEL_64;
    }
    if ( v1 != 103 )
    {
      if ( v1 >= 103 )
      {
        if ( v1 != 200 )
          goto LABEL_64;
        npc->bits |= 0x10u;
        v2 = npc->bits;
        LOBYTE(v2) = v2 | 0x80;
        npc->bits = v2;
        npc->act_no = 201;
        npc->act_wait = 0;
        npc->ani_no = 4;
        npc->ani_wait = 0;
        goto LABEL_37;
      }
      npc->bits &= 0xFFEFu;
      npc->act_no = 103;
      npc->ani_no = 0;
      npc->ani_wait = 0;
    }
    ++npc->act_wait;
    if ( ++npc->ani_wait > 1 )
    {
      npc->ani_wait = 0;
      ++npc->ani_no;
    }
    if ( npc->ani_no > 1 )
      npc->ani_no = 0;
    npc->xm -= 32;
    goto LABEL_64;
  }
  if ( v1 == 300 )
  {
    npc->act_no = 301;
    npc->ani_no = 4;
    npc->ani_wait = 0;
    npc->bits |= 0x10u;
LABEL_51:
    if ( ++npc->ani_wait > 0 )
    {
      npc->ani_wait = 0;
      ++npc->ani_no;
    }
    if ( npc->ani_no > 5 )
      npc->ani_no = 4;
    npc->xm += 32;
    if ( npc->xm > 0 )
    {
      npc->xm = 0;
      npc->act_no = 10;
    }
    goto LABEL_64;
  }
  if ( v1 > 300 )
  {
    switch ( v1 )
    {
      case 400:
        npc->act_no = 401;
        npc->ani_no = 2;
        npc->ani_wait = 0;
        npc->bits |= 0x10u;
        break;
      case 401:
        break;
      case 301:
        goto LABEL_51;
      default:
        goto LABEL_64;
    }
    if ( ++npc->ani_wait > 0 )
    {
      npc->ani_wait = 0;
      ++npc->ani_no;
    }
    if ( npc->ani_no > 3 )
      npc->ani_no = 2;
    npc->xm -= 32;
    if ( npc->xm < 0 )
    {
      npc->xm = 0;
      npc->act_no = 10;
    }
    goto LABEL_64;
  }
  if ( v1 == 202 )
  {
    npc->bits &= 0xFFEFu;
    npc->act_no = 203;
    npc->ani_no = 0;
    npc->ani_wait = 0;
  }
  else if ( v1 != 203 )
  {
    goto LABEL_64;
  }
  ++npc->act_wait;
  if ( ++npc->ani_wait > 1 )
  {
    npc->ani_wait = 0;
    ++npc->ani_no;
  }
  if ( npc->ani_no > 1 )
    npc->ani_no = 0;
  npc->xm += 32;
LABEL_64:
  if ( (npc->act_no == 101 || npc->act_no == 201 || npc->act_no == 301 || npc->act_no == 401) && npc->act_wait % 2 == 1 )
    PlaySoundObject(112, 1);
  if ( (npc->act_no == 103 || npc->act_no == 203) && npc->act_wait % 4 == 1 )
    PlaySoundObject(111, 1);
  if ( npc->act_no <= 99 || y >= npc->y + 2048 || y <= npc->y - 2048 )
  {
    npc->damage = 0;
    v4 = npc->bits;
    LOBYTE(v4) = v4 & 0x7F;
    npc->bits = v4;
  }
  else
  {
    npc->damage = 10;
    v3 = npc->bits;
    LOBYTE(v3) = v3 | 0x80;
    npc->bits = v3;
  }
  if ( npc->xm > 1024 )
    npc->xm = 1024;
  if ( npc->xm < -1024 )
    npc->xm = -1024;
  npc->x += npc->xm;
  if ( npc->direct == 1 )
  {
    v5 = npc;
    v6 = (Sint32 *)&v9[16 * npc->ani_no - 96];
  }
  else
  {
    v5 = npc;
    v6 = (Sint32 *)&v9[16 * npc->ani_no - 192];
  }
  npc->rect.left = *v6;
  v5->rect.top = v6[1];
  v5->rect.right = v6[2];
  v5->rect.bottom = v6[3];
}


void __cdecl ActBossChar03_02(NPCHAR_0 *npc)
{
  int v1;
  int v2;
  Sint32 *v3;
  RECT rect[4];
  int direct;
  int x;
  int y;
  char v8[8];

  rect[0].left = 0;
  rect[0].top = 128;
  rect[0].right = 72;
  rect[0].bottom = 160;
  rect[1].left = 72;
  rect[1].top = 128;
  rect[1].right = 144;
  rect[1].bottom = 160;
  rect[2].left = 0;
  rect[2].top = 160;
  rect[2].right = 72;
  rect[2].bottom = 192;
  rect[3].left = 72;
  rect[3].top = 160;
  rect[3].right = 144;
  rect[3].bottom = 192;
  v1 = npc->act_no;
  if ( v1 && v1 >= 0 )
  {
    if ( v1 == 10 )
    {
      npc->act_no = 11;
      npc->act_wait = 30 * (npc->ani_no + 1);
    }
    else if ( v1 != 11 )
    {
      goto LABEL_21;
    }
    if ( npc->act_wait )
    {
      --npc->act_wait;
    }
    else
    {
      v2 = npc->ani_no;
      if ( v2 == 1 )
      {
        direct = 2;
        x = 15360;
        y = 3072;
      }
      else if ( v2 > 1 )
      {
        if ( v2 == 2 )
        {
          direct = 0;
          x = -15360;
          y = -3072;
        }
        else if ( v2 == 3 )
        {
          direct = 1;
          x = 15360;
          y = -3072;
        }
      }
      else if ( !v2 )
      {
        direct = 3;
        x = -15360;
        y = 3072;
      }
      SetNpChar(158, x + npc->x, y + npc->y, 0, 0, direct, 0, 256);
      PlaySoundObject(39, 1);
      npc->act_wait = 120;
    }
  }
LABEL_21:
  npc->x = (unk_81CCFC8 + *(&unk_81CCFC8 + 43 * npc->count1)) / 2;
  npc->y = (unk_81CCFCC + *(&unk_81CCFCC + 43 * npc->count1)) / 2;
  v3 = (Sint32 *)&v8[16 * npc->ani_no - 76];
  npc->rect.left = *v3;
  npc->rect.top = v3[1];
  npc->rect.right = v3[2];
  npc->rect.bottom = v3[3];
}


void __cdecl ActBossChar03_03(NPCHAR_0 *npc)
{
  switch ( npc->act_no )
  {
    case 0xA:
      npc->tgt_x += 512;
      if ( npc->tgt_x > 0x4000 )
      {
        npc->tgt_x = 0x4000;
        npc->act_no = 0;
        stru_81CD1C4.act_no = 10;
        stru_81CD270.act_no = 10;
        stru_81CD31C.act_no = 10;
        stru_81CD3C8.act_no = 10;
      }
      break;
    case 0x14:
      npc->tgt_x -= 512;
      if ( npc->tgt_x < 0 )
      {
        npc->tgt_x = 0;
        npc->act_no = 0;
        stru_81CD1C4.act_no = 0;
        stru_81CD270.act_no = 0;
        stru_81CD31C.act_no = 0;
        stru_81CD3C8.act_no = 0;
      }
      break;
    case 0x1E:
      npc->tgt_x += 512;
      if ( npc->tgt_x > 10240 )
      {
        npc->tgt_x = 10240;
        npc->act_no = 0;
        stru_81CD474.act_no = 10;
        stru_81CD87C.act_no = 10;
        stru_81CD928.act_no = 10;
        stru_81CD9D4.act_no = 10;
        stru_81CDA80.act_no = 10;
      }
      break;
    case 0x28:
      npc->tgt_x -= 512;
      if ( npc->tgt_x < 0 )
      {
        npc->tgt_x = 0;
        npc->act_no = 0;
        stru_81CD474.act_no = 0;
        stru_81CD87C.act_no = 0;
        stru_81CD928.act_no = 0;
        stru_81CD9D4.act_no = 0;
        stru_81CDA80.act_no = 0;
      }
      break;
    default:
      break;
  }
  if ( npc->direct )
  {
    npc->rect.left = 264;
    npc->rect.top = 96;
    npc->rect.right = 312;
    npc->rect.bottom = 144;
    npc->x = npc->tgt_x + unk_81CCFC8 + 12288;
  }
  else
  {
    npc->rect.left = 216;
    npc->rect.top = 96;
    npc->rect.right = 264;
    npc->rect.bottom = 144;
    npc->x = unk_81CCFC8 - 12288 - npc->tgt_x;
  }
  npc->y = unk_81CCFCC;
}

void __cdecl ActBossChar03_04(NPCHAR_0 *npc)
{
  int v1;
  char v2;
  int v3;
  Sint32 *v4;
  RECT rect[8];
  int xm;
  int ym;
  unsigned __int8 deg;
  char v9[24];

  qmemcpy(rect, &ActBossChar03_04(NPCHAR *)::C.2, sizeof(rect));
  v1 = npc->act_no;
  if ( !v1 )
  {
    npc->bits &= 0xFFDFu;
    npc->ani_no = 0;
    goto LABEL_15;
  }
  if ( v1 < 0 )
    goto LABEL_15;
  if ( v1 == 10 )
  {
    npc->act_no = 11;
    npc->act_wait = 10 * npc->tgt_x + 40;
    npc->bits |= 0x20u;
LABEL_8:
    npc->ani_no = npc->act_wait <= 15 && npc->act_wait / 2 & 1;
    if ( npc->act_wait )
    {
      --npc->act_wait;
    }
    else
    {
      deg = GetArktan(npc->x - x, npc->y - y);
      v2 = Random(-2, 2);
      deg += v2;
      ym = 3 * GetSin(deg);
      xm = 3 * GetCos(deg);
      SetNpChar(156, npc->x, npc->y, xm, ym, 0, 0, 256);
      PlaySoundObject(39, 1);
      npc->act_wait = 40;
    }
    goto LABEL_15;
  }
  if ( v1 == 11 )
    goto LABEL_8;
LABEL_15:
  v3 = npc->tgt_x;
  if ( v3 == 1 )
  {
    npc->x = unk_81CCFC8 + 14336;
    npc->y = unk_81CCFCC - 0x2000;
  }
  else if ( v3 > 1 )
  {
    if ( v3 == 2 )
    {
      npc->x = unk_81CCFC8 - 7680;
      npc->y = unk_81CCFCC + 7168;
    }
    else if ( v3 == 3 )
    {
      npc->x = unk_81CCFC8 + 8704;
      npc->y = unk_81CCFCC + 7168;
    }
  }
  else if ( !v3 )
  {
    npc->x = unk_81CCFC8 - 11264;
    npc->y = unk_81CCFCC - 0x2000;
  }
  v4 = (Sint32 *)&v9[16 * (4 * npc->ani_no + npc->tgt_x) - 140];
  npc->rect.left = *v4;
  npc->rect.top = v4[1];
  npc->rect.right = v4[2];
  npc->rect.bottom = v4[3];
}


void __cdecl ActBossChar03_face(NPCHAR_0 *npc)
{
  int v1;
  char v2;
  RECT *v3;
  RECT rect[3];

  rect[0].left = 216;
  rect[0].top = 0;
  rect[0].right = 320;
  rect[0].bottom = 48;
  rect[1].left = 216;
  rect[1].top = 48;
  rect[1].right = 320;
  rect[1].bottom = 96;
  rect[2].left = 216;
  rect[2].top = 144;
  rect[2].right = 320;
  rect[2].bottom = 192;
  v1 = npc->act_no;
  if ( !v1 )
  {
    unk_81CD010 &= 0xFFDFu;
    npc->ani_no = 0;
    goto LABEL_13;
  }
  if ( v1 < 0 )
    goto LABEL_13;
  if ( v1 == 10 )
  {
    npc->act_no = 11;
    npc->act_wait = 10 * npc->tgt_x + 40;
    unk_81CD010 |= 0x20u;
  }
  else if ( v1 != 11 )
  {
    goto LABEL_13;
  }
  if ( unk_81CD05C )
  {
    v2 = (ActBossChar03_face(NPCHAR *)::flash++ >> 1) & 1;
    if ( v2 )
      npc->ani_no = 1;
    else
      npc->ani_no = 0;
  }
  else
  {
    npc->ani_no = 0;
  }
LABEL_13:
  stru_81CD474.x = unk_81CCFC8;
  stru_81CD474.y = unk_81CCFCC;
  if ( unk_81CD034 <= 10 )
    npc->ani_no = 2;
  v3 = &rect[npc->ani_no];
  npc->rect.left = v3->left;
  npc->rect.top = v3->top;
  npc->rect.right = v3->right;
  npc->rect.bottom = v3->bottom;
}

void ActBossChar_MonstX()
{
  int v0;
  int v1;
  int v2;
  int v3;
  int v4;
  int i;

  v0 = gBoss[0].act_no;
  if ( v0 == 400 )
  {
    gBoss[0].act_wait = 0;
    gBoss[0].act_no = 401;
    goto LABEL_93;
  }
  if ( v0 > 400 )
  {
    if ( v0 == 600 )
    {
      gBoss[0].act_no = 601;
      gBoss[0].act_wait = 0;
      gBoss[0].count2 = gBoss[0].life;
      npc.act_no = 30;
      stru_81CD118.act_no = 30;
    }
    else
    {
      if ( v0 <= 600 )
      {
        if ( v0 == 501 )
        {
LABEL_109:
          if ( ++gBoss[0].act_wait > 300 )
          {
            gBoss[0].act_no = 502;
            gBoss[0].act_wait = 0;
          }
          if ( !stru_81CD1C4.cond && !stru_81CD270.cond && !stru_81CD31C.cond && !stru_81CD3C8.cond )
          {
            gBoss[0].act_no = 502;
            gBoss[0].act_wait = 0;
          }
          goto LABEL_139;
        }
        if ( v0 > 501 )
        {
          if ( v0 == 502 )
          {
            gBoss[0].act_no = 503;
            gBoss[0].act_wait = 0;
            gBoss[0].count1 = 0;
            npc.act_no = 20;
            stru_81CD118.act_no = 20;
          }
          else if ( v0 != 503 )
          {
            goto LABEL_139;
          }
          if ( ++gBoss[0].act_wait > 50 )
          {
            if ( gBoss[0].x <= x )
              gBoss[0].act_no = 200;
            else
              gBoss[0].act_no = 100;
          }
          goto LABEL_139;
        }
        if ( v0 != 401 )
        {
          if ( v0 != 500 )
            goto LABEL_139;
          gBoss[0].act_no = 501;
          gBoss[0].act_wait = 0;
          npc.act_no = 10;
          stru_81CD118.act_no = 10;
          goto LABEL_109;
        }
LABEL_93:
        if ( ++gBoss[0].act_wait == 4 )
          stru_81CD5CC.act_no = 400;
        if ( gBoss[0].act_wait == 8 )
          stru_81CD678.act_no = 400;
        if ( gBoss[0].act_wait == 10 )
          stru_81CD724.act_no = 400;
        if ( gBoss[0].act_wait == 12 )
          stru_81CD7D0.act_no = 400;
        if ( gBoss[0].act_wait > 50 )
        {
          if ( stru_81CD1C4.cond || stru_81CD270.cond || stru_81CD31C.cond || stru_81CD3C8.cond )
            gBoss[0].act_no = 500;
          else
            gBoss[0].act_no = 600;
        }
        goto LABEL_139;
      }
      if ( v0 == 603 )
      {
LABEL_126:
        if ( ++gBoss[0].act_wait > 50 )
        {
          if ( gBoss[0].x <= x )
            gBoss[0].act_no = 200;
          else
            gBoss[0].act_no = 100;
        }
        goto LABEL_139;
      }
      if ( v0 > 603 )
      {
        if ( v0 == 1000 )
        {
          SetQuake(2);
          if ( !(++gBoss[0].act_wait & 7) )
            PlaySoundObject(52, 1);
          v1 = gBoss[0].y;
          v2 = (Random(-64, 64) << 9) + v1;
          v3 = gBoss[0].x;
          v4 = Random(-72, 72);
          SetDestroyNpChar(v3 + (v4 << 9), v2, 1, 1);
          if ( gBoss[0].act_wait > 100 )
          {
            gBoss[0].act_wait = 0;
            gBoss[0].act_no = 1001;
            SetFlash(gBoss[0].x, gBoss[0].y, 1);
            PlaySoundObject(35, 1);
          }
        }
        else if ( v0 == 1001 )
        {
          SetQuake(40);
          if ( ++gBoss[0].act_wait > 50 )
          {
            for ( i = 0; i <= 19; ++i )
              gBoss[i].cond = 0;
            DeleteNpCharCode(158, 1);
            SetNpChar(159, gBoss[0].x, gBoss[0].y - 12288, 0, 0, 0, 0, 0);
          }
        }
        goto LABEL_139;
      }
      if ( v0 != 601 )
      {
        if ( v0 != 602 )
          goto LABEL_139;
        gBoss[0].act_no = 603;
        gBoss[0].act_wait = 0;
        gBoss[0].count1 = 0;
        npc.act_no = 40;
        stru_81CD118.act_no = 40;
        goto LABEL_126;
      }
    }
    ++gBoss[0].act_wait;
    if ( gBoss[0].life < gBoss[0].count2 - 200 || gBoss[0].act_wait > 300 )
    {
      gBoss[0].act_no = 602;
      gBoss[0].act_wait = 0;
    }
    goto LABEL_139;
  }
  if ( v0 == 100 )
  {
    gBoss[0].act_wait = 0;
    gBoss[0].act_no = 101;
    ++gBoss[0].count1;
    goto LABEL_47;
  }
  if ( v0 <= 100 )
  {
    if ( v0 == 2 )
      goto LABEL_139;
    if ( v0 > 2 )
    {
      if ( v0 == 10 )
      {
        gBoss[0].act_no = 11;
        gBoss[0].act_wait = 0;
        gBoss[0].count1 = 0;
      }
      else if ( v0 != 11 )
      {
        goto LABEL_139;
      }
      if ( ++gBoss[0].act_wait > 100 )
      {
        gBoss[0].act_wait = 0;
        if ( gBoss[0].x <= x )
          gBoss[0].act_no = 200;
        else
          gBoss[0].act_no = 100;
      }
    }
    else if ( v0 )
    {
      if ( v0 == 1 )
      {
        gBoss[0].life = 700;
        gBoss[0].exp = 1;
        gBoss[0].act_no = 1;
        gBoss[0].x = 0x100000;
        gBoss[0].y = 102400;
        gBoss[0].hit_voice = 54;
        gBoss[0].hit.front = 12288;
        gBoss[0].hit.top = 12288;
        gBoss[0].hit.back = 12288;
        gBoss[0].hit.bottom = 12288;
        gBoss[0].bits = -32248;
        gBoss[0].size = 3;
        gBoss[0].code_event = 1000;
        gBoss[0].ani_no = 0;
        npc.cond = -128;
        npc.size = 3;
        npc.direct = 0;
        npc.view.front = 12288;
        npc.view.top = 12288;
        npc.view.back = 12288;
        npc.view.bottom = 12288;
        npc.bits = 8;
        qmemcpy(&stru_81CD118, &npc, sizeof(stru_81CD118));
        stru_81CD118.direct = 2;
        stru_81CD1C4.cond = -128;
        stru_81CD1C4.life = 60;
        stru_81CD1C4.hit_voice = 54;
        stru_81CD1C4.destroy_voice = 71;
        stru_81CD1C4.size = 2;
        stru_81CD1C4.view.front = 4096;
        stru_81CD1C4.view.top = 4096;
        stru_81CD1C4.view.back = 4096;
        stru_81CD1C4.view.bottom = 4096;
        stru_81CD1C4.hit.front = 2560;
        stru_81CD1C4.hit.back = 2560;
        stru_81CD1C4.hit.top = 2560;
        stru_81CD1C4.hit.bottom = 2560;
        stru_81CD1C4.bits = 8;
        stru_81CD1C4.tgt_x = 0;
        qmemcpy(&stru_81CD270, &stru_81CD1C4, sizeof(stru_81CD270));
        stru_81CD270.tgt_x = 1;
        qmemcpy(&stru_81CD31C, &stru_81CD1C4, sizeof(stru_81CD31C));
        stru_81CD31C.tgt_x = 2;
        stru_81CD31C.life = 100;
        qmemcpy(&stru_81CD3C8, &stru_81CD1C4, sizeof(stru_81CD3C8));
        stru_81CD3C8.tgt_x = 3;
        stru_81CD3C8.life = 100;
        stru_81CD474.cond = -128;
        stru_81CD474.x = 0x100000;
        stru_81CD474.y = 102400;
        stru_81CD474.view.front = 26624;
        stru_81CD474.view.top = 12288;
        stru_81CD474.view.back = 26624;
        stru_81CD474.view.bottom = 12288;
        stru_81CD474.hit_voice = 52;
        stru_81CD474.hit.front = 4096;
        stru_81CD474.hit.top = 12288;
        stru_81CD474.hit.back = 4096;
        stru_81CD474.hit.bottom = 0x2000;
        stru_81CD474.bits = 8;
        stru_81CD474.size = 3;
        stru_81CD474.ani_no = 0;
        stru_81CD5CC.cond = -128;
        stru_81CD5CC.act_no = 0;
        stru_81CD5CC.direct = 1;
        stru_81CD5CC.x = 1015808;
        stru_81CD5CC.y = 73728;
        stru_81CD5CC.view.front = 18432;
        stru_81CD5CC.view.top = 4096;
        stru_81CD5CC.view.back = 18432;
        stru_81CD5CC.view.bottom = 12288;
        stru_81CD5CC.hit_voice = 52;
        stru_81CD5CC.hit.front = 14336;
        stru_81CD5CC.hit.top = 4096;
        stru_81CD5CC.hit.back = 14336;
        stru_81CD5CC.hit.bottom = 0x2000;
        stru_81CD5CC.bits = 141;
        stru_81CD5CC.size = 3;
        qmemcpy(&stru_81CD678, &stru_81CD5CC, sizeof(stru_81CD678));
        stru_81CD678.x = 1081344;
        qmemcpy(&stru_81CD724, &stru_81CD5CC, sizeof(stru_81CD724));
        stru_81CD724.direct = 3;
        stru_81CD724.x = 1015808;
        stru_81CD724.y = 0x20000;
        stru_81CD724.view.top = 12288;
        stru_81CD724.view.bottom = 4096;
        stru_81CD724.hit.top = 0x2000;
        stru_81CD724.hit.bottom = 4096;
        qmemcpy(&stru_81CD7D0, &stru_81CD724, sizeof(stru_81CD7D0));
        stru_81CD7D0.x = 1081344;
        qmemcpy(&stru_81CD87C, &stru_81CD5CC, sizeof(stru_81CD87C));
        stru_81CD87C.cond = -128;
        stru_81CD87C.view.top = 0x2000;
        stru_81CD87C.view.bottom = 0x2000;
        stru_81CD87C.view.front = 15360;
        stru_81CD87C.view.back = 21504;
        stru_81CD87C.count1 = 9;
        stru_81CD87C.ani_no = 0;
        stru_81CD87C.bits = 8;
        qmemcpy(&stru_81CD928, &stru_81CD87C, sizeof(stru_81CD928));
        stru_81CD928.view.front = 21504;
        stru_81CD928.view.back = 15360;
        stru_81CD928.count1 = 10;
        stru_81CD928.ani_no = 1;
        stru_81CD928.bits = 8;
        qmemcpy(&stru_81CD9D4, &stru_81CD87C, sizeof(stru_81CD9D4));
        stru_81CD9D4.view.top = 0x2000;
        stru_81CD9D4.view.bottom = 0x2000;
        stru_81CD9D4.count1 = 11;
        stru_81CD9D4.ani_no = 2;
        stru_81CD9D4.bits = 8;
        qmemcpy(&stru_81CDA80, &stru_81CD9D4, sizeof(stru_81CDA80));
        stru_81CDA80.view.front = 21504;
        stru_81CDA80.view.back = 15360;
        stru_81CDA80.count1 = 12;
        stru_81CDA80.ani_no = 3;
        stru_81CDA80.bits = 8;
        gBoss[0].act_no = 2;
      }
    }
    else
    {
      gBoss[0].life = 1;
      gBoss[0].x = -163840;
    }
    goto LABEL_139;
  }
  if ( v0 == 201 )
  {
LABEL_62:
    if ( ++gBoss[0].act_wait == 4 )
      stru_81CD5CC.act_no = 200;
    if ( gBoss[0].act_wait == 8 )
      stru_81CD678.act_no = 200;
    if ( gBoss[0].act_wait == 10 )
      stru_81CD724.act_no = 200;
    if ( gBoss[0].act_wait == 12 )
      stru_81CD7D0.act_no = 200;
    if ( gBoss[0].act_wait > 120 && gBoss[0].count1 > 2 )
      gBoss[0].act_no = 400;
    if ( gBoss[0].act_wait > 121 && x < gBoss[0].x )
      gBoss[0].act_no = 100;
    goto LABEL_139;
  }
  if ( v0 <= 201 )
  {
    if ( v0 != 101 )
    {
      if ( v0 != 200 )
        goto LABEL_139;
      gBoss[0].act_wait = 0;
      gBoss[0].act_no = 201;
      ++gBoss[0].count1;
      goto LABEL_62;
    }
LABEL_47:
    if ( ++gBoss[0].act_wait == 4 )
      stru_81CD5CC.act_no = 100;
    if ( gBoss[0].act_wait == 8 )
      stru_81CD678.act_no = 100;
    if ( gBoss[0].act_wait == 10 )
      stru_81CD724.act_no = 100;
    if ( gBoss[0].act_wait == 12 )
      stru_81CD7D0.act_no = 100;
    if ( gBoss[0].act_wait > 120 && gBoss[0].count1 > 2 )
      gBoss[0].act_no = 300;
    if ( gBoss[0].act_wait > 121 && x > gBoss[0].x )
      gBoss[0].act_no = 200;
    goto LABEL_139;
  }
  if ( v0 == 300 )
  {
    gBoss[0].act_wait = 0;
    gBoss[0].act_no = 301;
  }
  else if ( v0 != 301 )
  {
    goto LABEL_139;
  }
  if ( ++gBoss[0].act_wait == 4 )
    stru_81CD5CC.act_no = 300;
  if ( gBoss[0].act_wait == 8 )
    stru_81CD678.act_no = 300;
  if ( gBoss[0].act_wait == 10 )
    stru_81CD724.act_no = 300;
  if ( gBoss[0].act_wait == 12 )
    stru_81CD7D0.act_no = 300;
  if ( gBoss[0].act_wait > 50 )
  {
    if ( stru_81CD1C4.cond || stru_81CD270.cond || stru_81CD31C.cond || stru_81CD3C8.cond )
      gBoss[0].act_no = 500;
    else
      gBoss[0].act_no = 600;
  }
LABEL_139:
  ActBossChar03_01(&stru_81CD5CC);
  ActBossChar03_01(&stru_81CD678);
  ActBossChar03_01(&stru_81CD724);
  ActBossChar03_01(&stru_81CD7D0);
  gBoss[0].x += ((stru_81CD724.x + stru_81CD678.x + stru_81CD5CC.x + stru_81CD7D0.x) / 4 - gBoss[0].x) / 16;
  ActBossChar03_face(&stru_81CD474);
  ActBossChar03_02(&stru_81CD87C);
  ActBossChar03_02(&stru_81CD928);
  ActBossChar03_02(&stru_81CD9D4);
  ActBossChar03_02(&stru_81CDA80);
  ActBossChar03_03(&npc);
  ActBossChar03_03(&stru_81CD118);
  if ( stru_81CD1C4.cond )
    ActBossChar03_04(&stru_81CD1C4);
  if ( stru_81CD270.cond )
    ActBossChar03_04(&stru_81CD270);
  if ( stru_81CD31C.cond )
    ActBossChar03_04(&stru_81CD31C);
  if ( stru_81CD3C8.cond )
    ActBossChar03_04(&stru_81CD3C8);
  if ( !gBoss[0].life && gBoss[0].act_no <= 999 )
  {
    gBoss[0].act_no = 1000;
    gBoss[0].act_wait = 0;
    gBoss[0].shock = -106;
    stru_81CD5CC.act_no = 300;
    stru_81CD678.act_no = 300;
    stru_81CD724.act_no = 300;
    stru_81CD7D0.act_no = 300;
  }
}

