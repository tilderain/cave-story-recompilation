//#include "types.h"
#include "SDL_stdinc.h"
#include "windows_wrapper.h"
#include "Tags.h"
#include "forNpc.h"

void ActNpc200(NPCHAR *npc);
void ActNpc201(NPCHAR *npc);
void ActNpc202(NPCHAR *npc);
void ActNpc203(NPCHAR *npc);
void ActNpc204(NPCHAR *npc);
void ActNpc205(NPCHAR *npc);
void ActNpc206(NPCHAR *npc);
void ActNpc207(NPCHAR *npc);
void ActNpc208(NPCHAR *npc);
void ActNpc209(NPCHAR *npc);
void ActNpc210(NPCHAR *npc);
void ActNpc211(NPCHAR *npc);
void ActNpc212(NPCHAR *npc);
void ActNpc213(NPCHAR *npc);
void ActNpc214(NPCHAR *npc);
void ActNpc215(NPCHAR *npc);
void ActNpc216(NPCHAR *npc);
void ActNpc217(NPCHAR *npc);
void ActNpc218(NPCHAR *npc);
void ActNpc219(NPCHAR *npc);

_UNKNOWN ActNpc217(NPCHAR *)::C.8;
_UNKNOWN ActNpc215(NPCHAR *)::C.7;
_UNKNOWN ActNpc213(NPCHAR *)::C.6;
_UNKNOWN ActNpc207(NPCHAR *)::C.4;
_UNKNOWN ActNpc200(NPCHAR *)::C.0;
_UNKNOWN ActNpc200(NPCHAR *)::C.1;

{
  int v1;
  char v2;
  NPCHAR *v3;
  Sint32 *v4;
  RECT rcRight[6];
  RECT rcLeft[6];
  unsigned __int8 deg;
  int xm;
  int ym;
  char v10[24];

  qmemcpy(rcLeft, &ActNpc200(NPCHAR *)::C.0, sizeof(rcLeft));
  qmemcpy(rcRight, &ActNpc200(NPCHAR *)::C.1, sizeof(rcRight));
  if ( npc->act_no <= 99 && npc->life <= 949 )
  {
    PlaySoundObject(72, 1);
    SetDestroyNpChar(npc->x, npc->y, npc->view.back, 8);
    SetExpObjects(npc->x, npc->y, npc->exp);
    npc->act_no = 100;
    npc->bits &= 0xFFDFu;
    npc->damage = 0;
  }
  v1 = npc->act_no;
  if ( v1 == 21 )
  {
LABEL_26:
    if ( ++npc->act_wait / 2 & 1 )
      npc->ani_no = 2;
    else
      npc->ani_no = 3;
    if ( npc->act_wait > 30 )
      npc->act_no = 30;
    if ( x >= npc->x )
      npc->direct = 2;
    else
      npc->direct = 0;
    goto LABEL_48;
  }
  if ( v1 <= 21 )
  {
    if ( v1 == 10 )
    {
LABEL_15:
      if ( ++npc->ani_wait > 30 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 1 )
        npc->ani_no = 0;
      if ( npc->count1 )
        --npc->count1;
      if ( !npc->count1 && x > npc->x - 57344 && x < npc->x + 57344 )
        npc->act_no = 20;
      goto LABEL_48;
    }
    if ( v1 != 20 )
    {
      if ( v1 )
        goto LABEL_48;
      npc->act_no = 10;
      npc->count1 = 0;
      goto LABEL_15;
    }
    npc->act_no = 21;
    npc->act_wait = 0;
    goto LABEL_26;
  }
  switch ( v1 )
  {
    case 31:
      goto LABEL_35;
    case 100:
      npc->ani_no = 5;
      break;
    case 30:
      npc->act_no = 31;
      npc->act_wait = 0;
      npc->ani_no = 4;
      npc->tgt_x = x;
      npc->tgt_y = y;
LABEL_35:
      if ( ++npc->act_wait <= 39 && npc->act_wait % 8 == 1 )
      {
        deg = npc->direct ? (unsigned __int8)GetArktan(npc->x + 7168 - npc->tgt_x, npc->y - npc->tgt_y) : (unsigned __int8)GetArktan(npc->x - 7168 - npc->tgt_x, npc->y - npc->tgt_y);
        v2 = Random(-6, 6);
        deg += v2;
        ym = 3 * GetSin(deg);
        xm = 3 * GetCos(deg);
        if ( npc->direct )
          SetNpChar(202, npc->x + 7168, npc->y, xm, ym, 0, 0, 256);
        else
          SetNpChar(202, npc->x - 7168, npc->y, xm, ym, 0, 0, 256);
        if ( !(gMC.cond & 2) )
          PlaySoundObject(33, 1);
      }
      if ( npc->act_wait > 60 )
      {
        npc->act_no = 10;
        npc->count1 = Random(100, 200);
        npc->ani_wait = 0;
      }
      break;
  }
LABEL_48:
  if ( npc->direct )
  {
    v3 = npc;
    v4 = (Sint32 *)&v10[16 * npc->ani_no - 204];
  }
  else
  {
    v3 = npc;
    v4 = (Sint32 *)&v10[16 * npc->ani_no - 108];
  }
  npc->rect.left = *v4;
  v3->rect.top = v4[1];
  v3->rect.right = v4[2];
  v3->rect.bottom = v4[3];
}


void ActNpc201(NPCHAR *npc)
{
  NPCHAR *v1;
  RECT *v2;
  RECT rcRight[1];
  RECT rcLeft[1];

  rcLeft[0].left = 200;
  rcLeft[0].top = 0;
  rcLeft[0].right = 240;
  rcLeft[0].bottom = 40;
  rcRight[0].left = 200;
  rcRight[0].top = 40;
  rcRight[0].right = 240;
  rcRight[0].bottom = 80;
  if ( npc->direct )
  {
    v1 = npc;
    v2 = &rcRight[npc->ani_no];
  }
  else
  {
    v1 = npc;
    v2 = &rcLeft[npc->ani_no];
  }
  npc->rect.left = v2->left;
  v1->rect.top = v2->top;
  v1->rect.right = v2->right;
  v1->rect.bottom = v2->bottom;
}

void ActNpc202(NPCHAR *npc)
{
  Sint32 *v1;
  RECT rect_left[3];
  char v3[8];

  if ( npc->flag & 0xFF )
  {
    npc->cond = 0;
    SetCaret(npc->x, npc->y, 2, 0);
  }
  npc->y += npc->ym;
  npc->x += npc->xm;
  rect_left[0].left = 184;
  rect_left[0].top = 216;
  rect_left[0].right = 200;
  rect_left[0].bottom = 240;
  rect_left[1].left = 200;
  rect_left[1].top = 216;
  rect_left[1].right = 216;
  rect_left[1].bottom = 240;
  rect_left[2].left = 216;
  rect_left[2].top = 216;
  rect_left[2].right = 232;
  rect_left[2].bottom = 240;
  if ( ++npc->ani_wait > 1 )
  {
    npc->ani_wait = 0;
    ++npc->ani_no;
  }
  if ( npc->ani_no > 2 )
    npc->ani_no = 0;
  v1 = (Sint32 *)&v3[16 * npc->ani_no - 48];
  npc->rect.left = *v1;
  npc->rect.top = v1[1];
  npc->rect.right = v1[2];
  npc->rect.bottom = v1[3];
  if ( ++npc->count1 > 300 )
  {
    npc->cond = 0;
    SetCaret(npc->x, npc->y, 2, 0);
  }
}


void ActNpc203(NPCHAR *npc)
{
  int v1;
  NPCHAR *v2;
  Sint32 *v3;
  RECT rcRight[3];
  RECT rcLeft[3];
  char v6[8];

  rcLeft[0].left = 0;
  rcLeft[0].top = 80;
  rcLeft[0].right = 16;
  rcLeft[0].bottom = 96;
  rcLeft[1].left = 16;
  rcLeft[1].top = 80;
  rcLeft[1].right = 32;
  rcLeft[1].bottom = 96;
  rcLeft[2].left = 32;
  rcLeft[2].top = 80;
  rcLeft[2].right = 48;
  rcLeft[2].bottom = 96;
  rcRight[0].left = 0;
  rcRight[0].top = 96;
  rcRight[0].right = 16;
  rcRight[0].bottom = 112;
  rcRight[1].left = 16;
  rcRight[1].top = 96;
  rcRight[1].right = 32;
  rcRight[1].bottom = 112;
  rcRight[2].left = 32;
  rcRight[2].top = 96;
  rcRight[2].right = 48;
  rcRight[2].bottom = 112;
  v1 = npc->act_no;
  if ( v1 == 1 )
  {
LABEL_9:
    if ( npc->x <= x )
      npc->direct = 2;
    else
      npc->direct = 0;
    if ( npc->act_wait <= 7 || npc->x - 57344 >= x || npc->x + 57344 <= x || npc->y - 40960 >= y || npc->y + 40960 <= y )
    {
      if ( npc->act_wait <= 7 )
        ++npc->act_wait;
      npc->ani_no = 0;
    }
    else
    {
      npc->ani_no = 1;
    }
    if ( npc->shock )
    {
      npc->act_no = 2;
      npc->ani_no = 0;
      npc->act_wait = 0;
    }
    if ( npc->act_wait > 7 && npc->x - 24576 < x && npc->x + 24576 > x && npc->y - 40960 < y && npc->y + 24576 > y )
    {
      npc->act_no = 2;
      npc->ani_no = 0;
      npc->act_wait = 0;
    }
    goto LABEL_38;
  }
  if ( v1 <= 1 )
  {
    if ( v1 )
      goto LABEL_38;
    npc->y += 1536;
    npc->act_no = 1;
    goto LABEL_9;
  }
  if ( v1 == 2 )
  {
    if ( ++npc->act_wait > 8 )
    {
      npc->act_no = 3;
      npc->ani_no = 2;
      npc->ym = -1535;
      if ( !(gMC.cond & 2) )
        PlaySoundObject(30, 1);
      if ( npc->direct )
        npc->xm = 256;
      else
        npc->xm = -256;
    }
  }
  else if ( v1 == 3 )
  {
    if ( npc->flag & 8 )
    {
      npc->xm = 0;
      npc->act_wait = 0;
      npc->ani_no = 0;
      npc->act_no = 1;
      if ( !(gMC.cond & 2) )
        PlaySoundObject(23, 1);
    }
  }
LABEL_38:
  npc->ym += 64;
  if ( npc->ym > 1535 )
    npc->ym = 1535;
  npc->x += npc->xm;
  npc->y += npc->ym;
  if ( npc->direct )
  {
    v2 = npc;
    v3 = (Sint32 *)&v6[16 * npc->ani_no - 96];
  }
  else
  {
    v2 = npc;
    v3 = (Sint32 *)&v6[16 * npc->ani_no - 48];
  }
  npc->rect.left = *v3;
  v2->rect.top = v3[1];
  v2->rect.right = v3[2];
  v2->rect.bottom = v3[3];
}


void ActNpc204(NPCHAR *npc)
{
  int v1;
  int v2;
  Sint32 *v3;
  RECT rc[2];
  char v5[8];

  rc[0].left = 240;
  rc[0].top = 80;
  rc[0].right = 256;
  rc[0].bottom = 96;
  rc[1].left = 240;
  rc[1].top = 144;
  rc[1].right = 256;
  rc[1].bottom = 160;
  v1 = npc->act_no;
  if ( v1 == 1 )
    goto LABEL_9;
  if ( v1 <= 1 )
  {
    if ( v1 )
      goto LABEL_22;
    npc->act_no = 1;
    npc->tgt_x = npc->x;
LABEL_9:
    if ( x > npc->x - 6144 && x < npc->x + 6144 && y > npc->y )
      npc->act_no = 2;
    goto LABEL_22;
  }
  if ( v1 == 2 )
  {
    if ( ++npc->act_wait / 6 & 1 )
      v2 = npc->tgt_x - 512;
    else
      v2 = npc->tgt_x;
    npc->x = v2;
    if ( npc->act_wait > 30 )
    {
      npc->act_no = 3;
      npc->ani_no = 1;
    }
    goto LABEL_22;
  }
  if ( v1 != 3 || (npc->ym += 32, !(npc->flag & 0xFF)) )
  {
LABEL_22:
    if ( npc->ym > 3072 )
      npc->ym = 3072;
    npc->y += npc->ym;
    v3 = (Sint32 *)&v5[16 * npc->ani_no - 32];
    npc->rect.left = *v3;
    npc->rect.top = v3[1];
    npc->rect.right = v3[2];
    npc->rect.bottom = v3[3];
    return;
  }
  if ( !(gMC.cond & 2) )
    PlaySoundObject(12, 1);
  SetDestroyNpChar(npc->x, npc->y, npc->view.back, 4);
  npc->cond = 0;
}


void ActNpc205(NPCHAR *npc)
{
  int v1;
  Sint32 *v2;
  RECT rc[2];
  char v4[8];

  rc[0].left = 112;
  rc[0].top = 80;
  rc[0].right = 128;
  rc[0].bottom = 112;
  rc[1].left = 128;
  rc[1].top = 80;
  rc[1].right = 144;
  rc[1].bottom = 112;
  switch ( npc->act_no )
  {
    case 0:
      npc->act_no = 1;
      npc->tgt_x = npc->x;
      npc->y += 2048;
      goto LABEL_3;
    case 1:
LABEL_3:
      if ( x > npc->x - 6144 && x < npc->x + 6144 && y > npc->y )
        npc->act_no = 2;
      break;
    case 2:
      if ( ++npc->act_wait / 6 & 1 )
        v1 = npc->tgt_x - 512;
      else
        v1 = npc->tgt_x;
      npc->x = v1;
      if ( npc->act_wait > 30 )
      {
        npc->act_no = 3;
        npc->ani_no = 1;
        npc->act_wait = 0;
      }
      break;
    case 3:
      npc->ym += 32;
      if ( y <= npc->y )
      {
        npc->bits |= 0x40u;
        npc->damage = 0;
      }
      else
      {
        npc->bits &= 0xFFBFu;
        npc->damage = 127;
      }
      if ( ++npc->act_wait <= 8 || !(npc->flag & 0xFF) )
        break;
      npc->bits |= 0x40u;
      npc->act_no = 4;
      npc->act_wait = 0;
      npc->ym = 0;
      npc->damage = 0;
      PlaySoundObject(12, 1);
      SetDestroyNpChar(npc->x, npc->y, npc->view.back, 4);
      SetBullet(24, npc->x, npc->y, 0);
      return;
    case 4:
      if ( ++npc->act_wait > 4 )
      {
        npc->act_no = 5;
        npc->bits |= 0x20u;
      }
      break;
    default:
      break;
  }
  if ( npc->ym > 3072 )
    npc->ym = 3072;
  npc->y += npc->ym;
  v2 = (Sint32 *)&v4[16 * npc->ani_no - 32];
  npc->rect.left = *v2;
  npc->rect.top = v2[1];
  npc->rect.right = v2[2];
  npc->rect.bottom = v2[3];
}


void ActNpc206(NPCHAR *npc)
{
  int v1;
  int v2;
  Sint32 *v3;
  RECT rect_left[3];
  char v5[8];

  v1 = npc->act_no;
  if ( v1 == 1 )
  {
LABEL_9:
    if ( ++npc->act_wait > 49 )
    {
      npc->act_wait = 0;
      npc->act_no = 2;
      npc->ym = 768;
    }
    goto LABEL_32;
  }
  if ( v1 <= 1 )
  {
    if ( v1 )
      goto LABEL_32;
    npc->act_no = 1;
    npc->tgt_x = npc->x;
    npc->tgt_y = npc->y;
    npc->count1 = 120;
    npc->act_wait = Random(0, 50);
    goto LABEL_9;
  }
  if ( v1 == 2 )
  {
    if ( x > npc->x - 40960 && x < npc->x + 40960 )
    {
      npc->act_wait = 0;
      npc->act_no = 3;
    }
    if ( npc->shock )
    {
      npc->act_wait = 0;
      npc->act_no = 3;
    }
  }
  else if ( v1 == 3 )
  {
    v2 = npc->act_wait;
    if ( v2 == 120 )
    {
      SetNpChar(207, npc->x + 0x2000, npc->y + 2048, 0, 0, 2, 0, 256);
    }
    else if ( v2 > 120 )
    {
      switch ( v2 )
      {
        case 240:
          SetNpChar(207, npc->x + 0x2000, npc->y + 2048, 0, 0, 4, 0, 256);
          break;
        case 300:
          npc->hit.back = 0x10000;
          npc->hit.front = 0x10000;
          npc->hit.top = 51200;
          npc->hit.bottom = 51200;
          npc->damage = 30;
          PlaySoundObject(35, 1);
          SetDestroyNpChar(npc->x, npc->y, 0x10000, 100);
          SetQuake(20);
          npc->cond |= 8u;
          break;
        case 180:
          SetNpChar(207, npc->x + 0x2000, npc->y + 2048, 0, 0, 3, 0, 256);
          break;
      }
    }
    else if ( v2 )
    {
      if ( v2 == 60 )
        SetNpChar(207, npc->x + 0x2000, npc->y + 2048, 0, 0, 1, 0, 256);
    }
    else
    {
      SetNpChar(207, npc->x + 0x2000, npc->y + 2048, 0, 0, 0, 0, 256);
    }
    ++npc->act_wait;
  }
LABEL_32:
  if ( npc->act_no > 1 )
  {
    if ( npc->tgt_y < npc->y )
      npc->ym -= 16;
    if ( npc->tgt_y > npc->y )
      npc->ym += 16;
    if ( npc->ym > 256 )
      npc->ym = 256;
    if ( npc->ym < -256 )
      npc->ym = -256;
  }
  npc->x += npc->xm;
  npc->y += npc->ym;
  rect_left[0].left = 80;
  rect_left[0].top = 80;
  rect_left[0].right = 120;
  rect_left[0].bottom = 120;
  rect_left[1].left = 120;
  rect_left[1].top = 80;
  rect_left[1].right = 160;
  rect_left[1].bottom = 120;
  rect_left[2].left = 160;
  rect_left[2].top = 80;
  rect_left[2].right = 200;
  rect_left[2].bottom = 120;
  if ( ++npc->ani_wait > 4 )
  {
    npc->ani_wait = 0;
    ++npc->ani_no;
  }
  if ( npc->ani_no > 2 )
    npc->ani_no = 0;
  v3 = (Sint32 *)&v5[16 * npc->ani_no - 48];
  npc->rect.left = *v3;
  npc->rect.top = v3[1];
  npc->rect.right = v3[2];
  npc->rect.bottom = v3[3];
}


void ActNpc207(NPCHAR *npc)
{
  int v1;
  Sint32 *v2;
  RECT rc[5];
  char v4[24];

  qmemcpy(rc, &ActNpc207(NPCHAR *)::C.4, sizeof(rc));
  v1 = npc->act_no;
  switch ( v1 )
  {
    case 1:
      goto LABEL_5;
    case 2:
      if ( ++npc->act_wait > 30 )
      {
        npc->cond = 0;
        return;
      }
      break;
    case 0:
      npc->act_no = 1;
      npc->ani_no = npc->direct;
      PlaySoundObject(43, 1);
LABEL_5:
      npc->x += 512;
      if ( ++npc->act_wait > 8 )
      {
        npc->act_wait = 0;
        npc->act_no = 2;
      }
      break;
  }
  v2 = (Sint32 *)&v4[16 * npc->ani_no - 80];
  npc->rect.left = *v2;
  npc->rect.top = v2[1];
  npc->rect.right = v2[2];
  npc->rect.bottom = v2[3];
}


void ActNpc208(NPCHAR *npc)
{
  int v1;
  int v2;
  int v3;
  int v4;
  int v5;
  NPCHAR *v6;
  Sint32 *v7;
  RECT rcRight[3];
  RECT rcLeft[3];
  unsigned __int8 deg;
  int xm;
  int ym;
  char v13[8];

  rcLeft[0].left = 248;
  rcLeft[0].top = 80;
  rcLeft[0].right = 272;
  rcLeft[0].bottom = 104;
  rcLeft[1].left = 272;
  rcLeft[1].top = 80;
  rcLeft[1].right = 296;
  rcLeft[1].bottom = 104;
  rcLeft[2].left = 296;
  rcLeft[2].top = 80;
  rcLeft[2].right = 320;
  rcLeft[2].bottom = 104;
  rcRight[0].left = 248;
  rcRight[0].top = 104;
  rcRight[0].right = 272;
  rcRight[0].bottom = 128;
  rcRight[1].left = 272;
  rcRight[1].top = 104;
  rcRight[1].right = 296;
  rcRight[1].bottom = 128;
  rcRight[2].left = 296;
  rcRight[2].top = 104;
  rcRight[2].right = 320;
  rcRight[2].bottom = 128;
  v1 = npc->act_no;
  if ( v1 )
  {
    if ( v1 != 1 )
      goto LABEL_58;
    if ( npc->x <= x )
    {
      npc->direct = 2;
      v2 = npc->xm + 16;
    }
    else
    {
      npc->direct = 0;
      v2 = npc->xm - 16;
    }
    npc->xm = v2;
    if ( npc->flag & 1 )
      npc->xm = 512;
    if ( npc->flag & 4 )
      npc->xm = -512;
    if ( npc->y >= npc->tgt_y )
      v3 = npc->ym - 8;
    else
      v3 = npc->ym + 8;
    npc->ym = v3;
    if ( npc->xm > 767 )
      npc->xm = 767;
    if ( npc->xm < -767 )
      npc->xm = -767;
    if ( npc->ym > 512 )
      npc->ym = 512;
    if ( npc->ym < -512 )
      npc->ym = -512;
    if ( npc->shock )
    {
      npc->x += npc->xm / 2;
      v4 = npc->y;
      v5 = npc->ym / 2;
    }
    else
    {
      npc->x += npc->xm;
      v4 = npc->y;
      v5 = npc->ym;
    }
    npc->y = v5 + v4;
    if ( x <= npc->x + 204800 && x >= npc->x - 204800 )
    {
LABEL_58:
      if ( npc->act_no )
      {
        if ( npc->act_wait <= 149 )
          ++npc->act_wait;
        if ( npc->act_wait == 150 )
        {
          if ( !(++npc->count2 & 7) && npc->x < x + 81920 && npc->x > x - 81920 )
          {
            deg = GetArktan(npc->x - x, npc->y - y);
            deg += Random(-6, 6);
            ym = 3 * GetSin(deg);
            xm = 3 * GetCos(deg);
            SetNpChar(209, npc->x, npc->y, xm, ym, 0, 0, 256);
            PlaySoundObject(39, 1);
          }
          if ( npc->count2 > 16 )
          {
            npc->act_wait = 0;
            npc->count2 = 0;
          }
        }
      }
      if ( ++npc->ani_wait > 1 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 1 )
        npc->ani_no = 0;
      if ( npc->act_wait > 120 && npc->act_wait / 2 % 2 == 1 && npc->ani_no == 1 )
        npc->ani_no = 2;
      if ( npc->direct )
      {
        v6 = npc;
        v7 = (Sint32 *)&v13[16 * npc->ani_no - 108];
      }
      else
      {
        v6 = npc;
        v7 = (Sint32 *)&v13[16 * npc->ani_no - 60];
      }
      npc->rect.left = *v7;
      v6->rect.top = v7[1];
      v6->rect.right = v7[2];
      v6->rect.bottom = v7[3];
    }
    else
    {
      npc->act_no = 0;
      npc->xm = 0;
      npc->direct = npc->count1;
      npc->x = npc->tgt_x;
      npc->rect.right = 0;
      npc->damage = 0;
    }
  }
  else if ( x >= npc->x + 0x2000 || x <= npc->x - 0x2000 )
  {
    npc->rect.right = 0;
    npc->damage = 0;
    npc->xm = 0;
    npc->ym = 0;
    npc->bits &= 0xFFDFu;
  }
  else
  {
    npc->bits |= 0x20u;
    npc->ym = -512;
    npc->tgt_x = npc->x;
    npc->tgt_y = npc->y;
    npc->act_no = 1;
    npc->act_wait = 0;
    npc->count1 = npc->direct;
    npc->count2 = 0;
    npc->damage = 6;
    if ( npc->direct )
    {
      npc->x = x - 0x20000;
      npc->xm = 767;
    }
    else
    {
      npc->x = x + 0x20000;
      npc->xm = -767;
    }
  }
}


void ActNpc209(NPCHAR *npc)
{
  Sint32 *v1;
  RECT rect_left[4];
  char v3[8];

  if ( npc->flag & 0xFF )
  {
    npc->cond = 0;
    SetCaret(npc->x, npc->y, 2, 0);
  }
  npc->y += npc->ym;
  npc->x += npc->xm;
  rect_left[0].left = 232;
  rect_left[0].top = 96;
  rect_left[0].right = 248;
  rect_left[0].bottom = 112;
  rect_left[1].left = 200;
  rect_left[1].top = 112;
  rect_left[1].right = 216;
  rect_left[1].bottom = 128;
  rect_left[2].left = 216;
  rect_left[2].top = 112;
  rect_left[2].right = 232;
  rect_left[2].bottom = 128;
  rect_left[3].left = 232;
  rect_left[3].top = 112;
  rect_left[3].right = 248;
  rect_left[3].bottom = 128;
  if ( ++npc->ani_wait > 2 )
  {
    npc->ani_wait = 0;
    ++npc->ani_no;
  }
  if ( npc->ani_no > 3 )
    npc->ani_no = 0;
  v1 = (Sint32 *)&v3[16 * npc->ani_no - 64];
  npc->rect.left = *v1;
  npc->rect.top = v1[1];
  npc->rect.right = v1[2];
  npc->rect.bottom = v1[3];
  if ( ++npc->count1 > 300 )
  {
    npc->cond = 0;
    SetCaret(npc->x, npc->y, 2, 0);
  }
}


void ActNpc210(NPCHAR *npc)
{
  int v1;
  int v2;
  int v3;
  int v4;
  int v5;
  NPCHAR *v6;
  RECT *v7;
  RECT rcRight[2];
  RECT rcLeft[2];

  rcLeft[0].left = 0;
  rcLeft[0].top = 112;
  rcLeft[0].right = 16;
  rcLeft[0].bottom = 128;
  rcLeft[1].left = 16;
  rcLeft[1].top = 112;
  rcLeft[1].right = 32;
  rcLeft[1].bottom = 128;
  rcRight[0].left = 32;
  rcRight[0].top = 112;
  rcRight[0].right = 48;
  rcRight[0].bottom = 128;
  rcRight[1].left = 48;
  rcRight[1].top = 112;
  rcRight[1].right = 64;
  rcRight[1].bottom = 128;
  v1 = npc->act_no;
  if ( v1 )
  {
    if ( v1 == 1 )
    {
      if ( npc->x <= x )
      {
        npc->direct = 2;
        v2 = npc->xm + 16;
      }
      else
      {
        npc->direct = 0;
        v2 = npc->xm - 16;
      }
      npc->xm = v2;
      if ( npc->xm > 767 )
        npc->xm = 767;
      if ( npc->xm < -767 )
        npc->xm = -767;
      if ( npc->y >= npc->tgt_y )
        v3 = npc->ym - 8;
      else
        v3 = npc->ym + 8;
      npc->ym = v3;
      if ( npc->ym > 512 )
        npc->ym = 512;
      if ( npc->ym < -512 )
        npc->ym = -512;
      if ( npc->shock )
      {
        npc->x += npc->xm / 2;
        v4 = npc->y;
        v5 = npc->ym / 2;
      }
      else
      {
        npc->x += npc->xm;
        v4 = npc->y;
        v5 = npc->ym;
      }
      npc->y = v5 + v4;
    }
  }
  else
  {
    if ( x >= npc->x + 0x2000 || x <= npc->x - 0x2000 )
    {
      npc->bits &= 0xFFDFu;
      npc->rect.right = 0;
      npc->damage = 0;
      npc->xm = 0;
      npc->ym = 0;
      return;
    }
    npc->bits |= 0x20u;
    npc->ym = -512;
    npc->tgt_y = npc->y;
    npc->act_no = 1;
    npc->damage = 2;
    if ( npc->direct )
    {
      npc->x = x - 0x20000;
      npc->xm = 767;
    }
    else
    {
      npc->x = x + 0x20000;
      npc->xm = -767;
    }
  }
  if ( ++npc->ani_wait > 1 )
  {
    npc->ani_wait = 0;
    ++npc->ani_no;
  }
  if ( npc->ani_no > 1 )
    npc->ani_no = 0;
  if ( npc->direct )
  {
    v6 = npc;
    v7 = &rcRight[npc->ani_no];
  }
  else
  {
    v6 = npc;
    v7 = &rcLeft[npc->ani_no];
  }
  npc->rect.left = v7->left;
  v6->rect.top = v7->top;
  v6->rect.right = v7->right;
  v6->rect.bottom = v7->bottom;
}

void ActNpc211(NPCHAR *npc)
{
  RECT *v1;
  RECT rect[4];

  rect[0].left = 256;
  rect[0].top = 200;
  rect[0].right = 272;
  rect[0].bottom = 216;
  rect[1].left = 272;
  rect[1].top = 200;
  rect[1].right = 288;
  rect[1].bottom = 216;
  rect[2].left = 288;
  rect[2].top = 200;
  rect[2].right = 304;
  rect[2].bottom = 216;
  rect[3].left = 304;
  rect[3].top = 200;
  rect[3].right = 320;
  rect[3].bottom = 216;
  v1 = &rect[npc->code_event];
  npc->rect.left = v1->left;
  npc->rect.top = v1->top;
  npc->rect.right = v1->right;
  npc->rect.bottom = v1->bottom;
}

void ActNpc212(NPCHAR *npc)
{
  int v1;
  int v2;
  int v3;
  Sint32 *v4;
  RECT rcRight[4];
  char v6[8];

  rcRight[0].left = 160;
  rcRight[0].top = 152;
  rcRight[0].right = 200;
  rcRight[0].bottom = 192;
  rcRight[1].left = 200;
  rcRight[1].top = 152;
  rcRight[1].right = 240;
  rcRight[1].bottom = 192;
  rcRight[2].left = 240;
  rcRight[2].top = 112;
  rcRight[2].right = 280;
  rcRight[2].bottom = 152;
  rcRight[3].left = 280;
  rcRight[3].top = 112;
  rcRight[3].right = 320;
  rcRight[3].bottom = 152;
  switch ( npc->act_no )
  {
    case 0:
      npc->act_no = 1;
      npc->y -= 2048;
      goto LABEL_3;
    case 1:
LABEL_3:
      if ( ++npc->ani_wait > 30 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 1 )
        npc->ani_no = 0;
      break;
    case 0xA:
      npc->act_no = 11;
      npc->ani_no = 2;
      npc->ani_wait = 0;
      npc->tgt_y = npc->y - 0x2000;
      npc->tgt_x = npc->x - 3072;
      npc->ym = 0;
      npc->bits |= 8u;
      goto LABEL_8;
    case 0xB:
LABEL_8:
      if ( npc->x >= npc->tgt_x )
        v1 = npc->xm - 8;
      else
        v1 = npc->xm + 8;
      npc->xm = v1;
      if ( npc->y >= npc->tgt_y )
        v2 = npc->ym - 8;
      else
        v2 = npc->ym + 8;
      npc->ym = v2;
      npc->x += npc->xm;
      npc->y += npc->ym;
      if ( ++npc->ani_wait > 5 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 3 )
        npc->ani_no = 2;
      break;
    case 0x14:
      npc->act_no = 21;
      npc->bits |= 8u;
      goto LABEL_19;
    case 0x15:
LABEL_19:
      if ( npc->y >= npc->tgt_y )
        v3 = npc->ym - 16;
      else
        v3 = npc->ym + 16;
      npc->ym = v3;
      npc->xm += 32;
      if ( npc->xm > 1536 )
        npc->xm = 1536;
      if ( npc->xm < -1536 )
        npc->xm = -1536;
      npc->x += npc->xm;
      npc->y += npc->ym;
      if ( ++npc->ani_wait > 2 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 3 )
        npc->ani_no = 2;
      break;
    case 0x1E:
      npc->act_no = 31;
      SetNpChar(297, 0, 0, 0, 0, 0, npc, 256);
      break;
    default:
      break;
  }
  v4 = (Sint32 *)&v6[16 * npc->ani_no - 64];
  npc->rect.left = *v4;
  npc->rect.top = v4[1];
  npc->rect.right = v4[2];
  npc->rect.bottom = v4[3];
  if ( star_flag & 0x40 )
  {
    if ( npc->ani_no > 1 )
    {
      npc->rect.top += 40;
      npc->rect.bottom += 40;
    }
  }
}


void ActNpc213(NPCHAR *npc)
{
  int v1;
  int v2;
  int v3;
  int v4;
  int v5;
  int v6;
  int v7;
  int v8;
  int v9;
  Sint32 *v10;
  RECT rect[10];
  char v12[24];

  qmemcpy(rect, &ActNpc213(NPCHAR *)::C.6, sizeof(rect));
  switch ( npc->act_no )
  {
    case 0:
      npc->ani_no = 0;
      npc->tgt_x = npc->x;
      npc->tgt_y = npc->y;
      goto LABEL_3;
    case 1:
LABEL_3:
      if ( y > npc->y - 4096 && y < npc->y + 4096 )
      {
        if ( npc->direct )
          v1 = npc->y + 122880;
        else
          v1 = npc->y - 122880;
        npc->y = v1;
        npc->act_no = 10;
        npc->act_wait = 0;
        npc->ani_no = 1;
        npc->ym = 0;
        npc->bits |= 0x20u;
      }
      break;
    case 0xA:
      if ( ++npc->ani_wait > 2 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 3 )
        npc->ani_no = 1;
      if ( ++npc->act_wait > 200 )
      {
        npc->act_no = 20;
        npc->act_wait = 0;
        npc->ani_no = 4;
      }
      break;
    case 0x14:
      if ( ++npc->ani_wait > 2 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 6 )
        npc->ani_no = 4;
      if ( ++npc->act_wait > 50 )
      {
        npc->act_no = 30;
        npc->act_wait = 0;
        npc->ani_no = 7;
      }
      break;
    case 0x1E:
      if ( ++npc->ani_wait > 2 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 9 )
        npc->ani_no = 7;
      if ( ++npc->act_wait % 5 == 1 )
      {
        v2 = Random(-512, 512);
        v3 = Random(2, 12);
        SetNpChar(214, npc->x, npc->y, (v3 << 9) / 4, v2, 0, 0, 256);
        PlaySoundObject(21, 1);
      }
      if ( npc->act_wait > 50 )
      {
        npc->act_no = 10;
        npc->act_wait = 0;
        npc->ani_no = 1;
      }
      break;
    case 0x28:
      if ( npc->y >= npc->tgt_y )
        v4 = npc->ym - 64;
      else
        v4 = npc->ym + 64;
      npc->ym = v4;
      if ( npc->ym < -1024 )
        npc->ym = -1024;
      if ( npc->ym > 1024 )
        npc->ym = 1024;
      if ( npc->shock )
      {
        v5 = npc->y;
        v6 = npc->ym / 2;
      }
      else
      {
        v5 = npc->y;
        v6 = npc->ym;
      }
      npc->y = v6 + v5;
      if ( ++npc->ani_wait > 2 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 6 )
        npc->ani_no = 4;
      if ( y < npc->tgt_y + 122880 && y > npc->tgt_y - 122880 )
      {
        npc->act_no = 20;
        npc->act_wait = 0;
        npc->ani_no = 4;
      }
      break;
    default:
      break;
  }
  if ( npc->act_no > 9 && npc->act_no <= 30 )
  {
    if ( npc->y >= y )
      v7 = npc->ym - 25;
    else
      v7 = npc->ym + 25;
    npc->ym = v7;
    if ( npc->ym < -1024 )
      npc->ym = -1024;
    if ( npc->ym > 1024 )
      npc->ym = 1024;
    if ( npc->flag & 2 )
      npc->ym = 512;
    if ( npc->flag & 8 )
      npc->ym = -512;
    if ( npc->shock )
    {
      v8 = npc->y;
      v9 = npc->ym / 2;
    }
    else
    {
      v8 = npc->y;
      v9 = npc->ym;
    }
    npc->y = v9 + v8;
    if ( y > npc->tgt_y + 122880 || y < npc->tgt_y - 122880 )
      npc->act_no = 40;
  }
  v10 = (Sint32 *)&v12[16 * npc->ani_no - 160];
  npc->rect.left = *v10;
  npc->rect.top = v10[1];
  npc->rect.right = v10[2];
  npc->rect.bottom = v10[3];
}


void ActNpc214(NPCHAR *npc)
{
  int v1;
  Sint32 *v2;
  RECT rect[3];
  char v4[8];

  rect[0].left = 144;
  rect[0].top = 48;
  rect[0].right = 176;
  rect[0].bottom = 64;
  rect[1].left = 176;
  rect[1].top = 48;
  rect[1].right = 208;
  rect[1].bottom = 64;
  rect[2].left = 208;
  rect[2].top = 48;
  rect[2].right = 240;
  rect[2].bottom = 64;
  v1 = npc->act_no;
  if ( v1 )
  {
    if ( v1 != 1 )
      goto LABEL_13;
  }
  else
  {
    npc->act_no = 1;
    npc->bits |= 8u;
  }
  if ( ++npc->ani_wait > 2 )
  {
    npc->ani_wait = 0;
    ++npc->ani_no;
  }
  if ( npc->ani_no > 2 )
    npc->ani_no = 0;
  npc->xm -= 25;
  npc->x += npc->xm;
  npc->y += npc->ym;
  if ( npc->xm < 0 )
    npc->bits &= 0xFFF7u;
  if ( npc->flag & 0xFF )
  {
    SetDestroyNpChar(npc->x, npc->y, npc->view.back, 4);
    PlaySoundObject(28, 1);
    npc->cond = 0;
  }
LABEL_13:
  v2 = (Sint32 *)&v4[16 * npc->ani_no - 48];
  npc->rect.left = *v2;
  npc->rect.top = v2[1];
  npc->rect.right = v2[2];
  npc->rect.bottom = v2[3];
}


void ActNpc215(NPCHAR *npc)
{
  Sint32 *v1;
  RECT rect[5];
  char v3[24];

  switch ( npc->act_no )
  {
    case 0:
      npc->ani_no = 0;
      npc->act_no = 1;
      npc->act_wait = 0;
      npc->tgt_y = npc->y;
      npc->bits &= 0xFFDFu;
      npc->bits &= 0xFFFBu;
      npc->bits &= 0xFFFEu;
      npc->bits &= 0xFFF7u;
      goto LABEL_3;
    case 1:
LABEL_3:
      if ( x > npc->x - 6144 && x < npc->x + 6144 && y > npc->y && y < npc->y + 4096 )
      {
        npc->act_no = 15;
        npc->act_wait = 0;
      }
      break;
    case 0xF:
      if ( ++npc->act_wait > 10 )
      {
        PlaySoundObject(102, 1);
        npc->act_no = 20;
      }
      break;
    case 0x14:
      if ( ++npc->ani_wait > 3 )
      {
        ++npc->ani_no;
        npc->ani_wait = 0;
      }
      if ( npc->ani_no == 3 )
        npc->damage = 15;
      if ( npc->ani_no == 4 )
      {
        npc->bits |= 0x20u;
        npc->act_no = 30;
        npc->act_wait = 0;
      }
      break;
    case 0x1E:
      npc->bits |= 1u;
      npc->damage = 0;
      ++npc->act_wait;
      if ( npc->shock )
      {
        npc->act_no = 40;
        npc->act_wait = 0;
      }
      break;
    case 0x28:
      npc->bits |= 8u;
      npc->y += 512;
      if ( ++npc->act_wait == 32 )
      {
        npc->bits &= 0xFFFEu;
        npc->bits &= 0xFFDFu;
        npc->act_no = 50;
        npc->act_wait = 0;
      }
      break;
    case 0x32:
      if ( npc->act_wait > 99 )
      {
        npc->y = npc->tgt_y;
        npc->ani_no = 0;
        npc->act_no = 0;
      }
      else
      {
        ++npc->act_wait;
      }
      break;
    default:
      break;
  }
  qmemcpy(rect, &ActNpc215(NPCHAR *)::C.7, sizeof(rect));
  v1 = (Sint32 *)&v3[16 * npc->ani_no - 80];
  npc->rect.left = *v1;
  npc->rect.top = v1[1];
  npc->rect.right = v1[2];
  npc->rect.bottom = v1[3];
}


void ActNpc216(NPCHAR *npc)
{
  npc->rect.left = 256;
  npc->rect.top = 192;
  npc->rect.right = 272;
  npc->rect.bottom = 216;
}

void ActNpc217(NPCHAR *npc)
{
  int v1;
  Sint32 *v2;
  RECT rect[8];
  char v4[24];

  qmemcpy(rect, &ActNpc217(NPCHAR *)::C.8, sizeof(rect));
  switch ( npc->act_no )
  {
    case 0:
      npc->act_no = 1;
      npc->ani_no = 0;
      npc->ani_wait = 0;
      npc->xm = 0;
      goto LABEL_3;
    case 1:
LABEL_3:
      if ( Random(0, 120) == 10 )
      {
        npc->act_no = 2;
        npc->act_wait = 0;
        npc->ani_no = 1;
      }
      break;
    case 2:
      if ( ++npc->act_wait > 8 )
      {
        npc->act_no = 1;
        npc->ani_no = 0;
      }
      break;
    case 0xA:
      npc->ani_no = 2;
      npc->xm = 0;
      break;
    case 0x14:
      npc->act_no = 21;
      npc->ani_no = 2;
      npc->xm += 512;
      npc->ym -= 1024;
      break;
    case 0x15:
      if ( npc->flag & 8 )
      {
        npc->ani_no = 3;
        npc->act_no = 30;
        npc->act_wait = 0;
        npc->xm = 0;
        npc->tgt_x = npc->x;
      }
      break;
    case 0x1E:
      npc->ani_no = 3;
      if ( ++npc->act_wait / 2 & 1 )
        v1 = npc->tgt_x + 512;
      else
        v1 = npc->tgt_x;
      npc->x = v1;
      break;
    case 0x28:
      npc->act_no = 41;
      npc->ym = -512;
      npc->ani_no = 2;
      goto LABEL_16;
    case 0x29:
LABEL_16:
      if ( npc->flag & 8 )
      {
        npc->act_no = 42;
        npc->ani_no = 4;
      }
      break;
    case 0x2A:
      npc->xm = 0;
      npc->ani_no = 4;
      break;
    case 0x32:
      npc->act_no = 51;
      npc->act_wait = 0;
      goto LABEL_20;
    case 0x33:
LABEL_20:
      if ( ++npc->act_wait > 32 )
        npc->act_no = 42;
      npc->xm = 512;
      if ( ++npc->ani_wait > 3 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 7 )
        npc->ani_no = 4;
      break;
    default:
      break;
  }
  npc->ym += 64;
  if ( npc->ym > 1535 )
    npc->ym = 1535;
  npc->x += npc->xm;
  npc->y += npc->ym;
  v2 = (Sint32 *)&v4[16 * npc->ani_no - 128];
  npc->rect.left = *v2;
  npc->rect.top = v2[1];
  npc->rect.right = v2[2];
  npc->rect.bottom = v2[3];
}


void ActNpc218(NPCHAR *npc)
{
  RECT *v1;
  RECT rc[2];

  rc[0].left = 256;
  rc[0].top = 120;
  rc[0].right = 288;
  rc[0].bottom = 152;
  rc[1].left = 288;
  rc[1].top = 120;
  rc[1].right = 320;
  rc[1].bottom = 152;
  npc->x += npc->xm;
  npc->y += npc->ym;
  if ( ++npc->act_wait > 200 )
    npc->cond = 0;
  if ( ++npc->ani_wait > 2 )
  {
    npc->ani_wait = 0;
    ++npc->ani_no;
  }
  if ( npc->ani_no > 1 )
    npc->ani_no = 0;
  v1 = &rc[npc->ani_no];
  npc->rect.left = v1->left;
  npc->rect.top = v1->top;
  npc->rect.right = v1->right;
  npc->rect.bottom = v1->bottom;
}

void ActNpc219(NPCHAR *npc)
{
  int v1;
  int v2;
  int v3;
  int v4;
  int v5;
  int v6;

  if ( npc->direct )
  {
    v3 = npc->y;
    v4 = (Random(-128, 128) << 9) + v3;
    v5 = npc->x;
    v6 = Random(-160, 160);
    SetNpChar(199, v5 + (v6 << 9), v4, 0, 0, 2, 0, 256);
  }
  else if ( Random(0, 40) == 1 )
  {
    v1 = npc->y;
    v2 = Random(-20, 20);
    SetNpChar(4, (v2 << 9) + npc->x, v1, 0, -512, 0, 0, 256);
  }
  npc->rect.left = 0;
  npc->rect.top = 0;
  npc->rect.right = 0;
  npc->rect.bottom = 0;
}

