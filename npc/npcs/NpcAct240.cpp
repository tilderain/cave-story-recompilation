//#include "types.h"
#include "SDL_stdinc.h"
#include "windows_wrapper.h"
#include "Tags.h"
#include "forNpc.h"

void ActNpc240(NPCHAR *npc);
void ActNpc241(NPCHAR *npc);
void ActNpc242(NPCHAR *npc);
void ActNpc243(NPCHAR *npc);
void ActNpc244(NPCHAR *npc);
void ActNpc245(NPCHAR *npc);
void ActNpc246(NPCHAR *npc);
void ActNpc247(NPCHAR *npc);
void ActNpc248(NPCHAR *npc);
void ActNpc249(NPCHAR *npc);
void ActNpc250(NPCHAR *npc);
void ActNpc251(NPCHAR *npc);
void ActNpc252(NPCHAR *npc);
void ActNpc253(NPCHAR *npc);
void ActNpc254(NPCHAR *npc);
void ActNpc255(NPCHAR *npc);
void ActNpc256(NPCHAR *npc);
void ActNpc257(NPCHAR *npc);
void ActNpc258(NPCHAR *npc);
void ActNpc259(NPCHAR *npc);

_UNKNOWN ActNpc256(NPCHAR *)::C.11;
_UNKNOWN ActNpc247(NPCHAR *)::C.5;
_UNKNOWN ActNpc247(NPCHAR *)::C.6;
_UNKNOWN ActNpc240(NPCHAR *)::C.0;
_UNKNOWN ActNpc240(NPCHAR *)::C.1;

void ActNpc240(NPCHAR *npc)
{
  NPCHAR *v1;
  Sint32 *v2;
  RECT rcRight[6];
  RECT rcLeft[6];
  char v5[24];

  qmemcpy(rcLeft, &ActNpc240(NPCHAR *)::C.0, sizeof(rcLeft));
  qmemcpy(rcRight, &ActNpc240(NPCHAR *)::C.1, sizeof(rcRight));
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
      if ( Random(0, 60) == 1 )
      {
        npc->act_no = 2;
        npc->act_wait = 0;
        npc->ani_no = 1;
      }
      if ( Random(0, 60) == 1 )
      {
        npc->act_no = 10;
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
      npc->act_no = 11;
      npc->act_wait = Random(0, 16);
      npc->ani_no = 2;
      npc->ani_wait = 0;
      if ( Random(0, 9) & 1 )
        npc->direct = 0;
      else
        npc->direct = 2;
      goto LABEL_12;
    case 0xB:
LABEL_12:
      if ( npc->direct || !(npc->flag & 1) )
      {
        if ( npc->direct == 2 && npc->flag & 4 )
          npc->direct = 0;
      }
      else
      {
        npc->direct = 2;
      }
      if ( npc->direct )
        npc->xm = 512;
      else
        npc->xm = -512;
      if ( ++npc->ani_wait > 4 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 5 )
        npc->ani_no = 2;
      if ( ++npc->act_wait > 32 )
        npc->act_no = 0;
      break;
    default:
      break;
  }
  npc->ym += 32;
  if ( npc->ym > 1535 )
    npc->ym = 1535;
  npc->x += npc->xm;
  npc->y += npc->ym;
  if ( npc->direct )
  {
    v1 = npc;
    v2 = (Sint32 *)&v5[16 * npc->ani_no - 192];
  }
  else
  {
    v1 = npc;
    v2 = (Sint32 *)&v5[16 * npc->ani_no - 96];
  }
  npc->rect.left = *v2;
  v1->rect.top = v2[1];
  v1->rect.right = v2[2];
  v1->rect.bottom = v2[3];
}


void ActNpc241(NPCHAR *npc)
{
  int v1;
  NPCHAR *v2;
  Sint32 *v3;
  RECT rcRight[3];
  RECT rcLeft[3];
  char v6[8];

  rcLeft[0].left = 0;
  rcLeft[0].top = 0;
  rcLeft[0].right = 16;
  rcLeft[0].bottom = 16;
  rcLeft[1].left = 16;
  rcLeft[1].top = 0;
  rcLeft[1].right = 32;
  rcLeft[1].bottom = 16;
  rcLeft[2].left = 32;
  rcLeft[2].top = 0;
  rcLeft[2].right = 48;
  rcLeft[2].bottom = 16;
  rcRight[0].left = 0;
  rcRight[0].top = 16;
  rcRight[0].right = 16;
  rcRight[0].bottom = 32;
  rcRight[1].left = 16;
  rcRight[1].top = 16;
  rcRight[1].right = 32;
  rcRight[1].bottom = 32;
  rcRight[2].left = 32;
  rcRight[2].top = 16;
  rcRight[2].right = 48;
  rcRight[2].bottom = 32;
  v1 = npc->act_no;
  if ( v1 == 1 )
  {
LABEL_9:
    if ( npc->x <= x )
      npc->direct = 2;
    else
      npc->direct = 0;
    if ( npc->act_wait <= 7 || npc->x - 73728 >= x || npc->x + 73728 <= x || npc->y - 40960 >= y || npc->y + 40960 <= y )
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
    if ( npc->act_wait > 7 && npc->x - 49152 < x && npc->x + 49152 > x && npc->y - 40960 < y && npc->y + 49152 > y )
    {
      npc->act_no = 2;
      npc->ani_no = 0;
      npc->act_wait = 0;
    }
    goto LABEL_35;
  }
  if ( v1 <= 1 )
  {
    if ( v1 )
      goto LABEL_35;
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
      PlaySoundObject(30, 1);
      if ( npc->direct )
        npc->xm = 512;
      else
        npc->xm = -512;
    }
  }
  else if ( v1 == 3 && npc->flag & 8 )
  {
    npc->xm = 0;
    npc->act_wait = 0;
    npc->ani_no = 0;
    npc->act_no = 1;
    PlaySoundObject(23, 1);
  }
LABEL_35:
  npc->ym += 85;
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


void ActNpc242(NPCHAR *npc)
{
  int v1;
  NPCHAR *v2;
  Sint32 *v3;
  RECT rect_right[4];
  RECT rect_left[4];
  char v6[8];

  if ( npc->x < 0 || npc->x > gMap.width << 13 )
  {
    VanishNpChar(npc);
    return;
  }
  v1 = npc->act_no;
  switch ( v1 )
  {
    case 1:
      goto LABEL_8;
    case 2:
      goto LABEL_11;
    case 0:
      npc->act_no = 1;
      npc->tgt_x = npc->x;
      npc->tgt_y = npc->y;
      npc->act_wait = Random(0, 50);
LABEL_8:
      if ( npc->act_wait )
      {
        --npc->act_wait;
        break;
      }
      npc->act_no = 2;
      npc->ym = 1024;
LABEL_11:
      if ( npc->direct )
        npc->xm = 256;
      else
        npc->xm = -256;
      if ( npc->tgt_y < npc->y )
        npc->ym -= 16;
      if ( npc->tgt_y > npc->y )
        npc->ym += 16;
      if ( npc->ym > 768 )
        npc->ym = 768;
      if ( npc->ym < -768 )
        npc->ym = -768;
      break;
  }
  npc->x += npc->xm;
  npc->y += npc->ym;
  rect_left[0].left = 32;
  rect_left[0].top = 32;
  rect_left[0].right = 48;
  rect_left[0].bottom = 48;
  rect_left[1].left = 48;
  rect_left[1].top = 32;
  rect_left[1].right = 64;
  rect_left[1].bottom = 48;
  rect_left[2].left = 64;
  rect_left[2].top = 32;
  rect_left[2].right = 80;
  rect_left[2].bottom = 48;
  rect_left[3].left = 80;
  rect_left[3].top = 32;
  rect_left[3].right = 96;
  rect_left[3].bottom = 48;
  rect_right[0].left = 32;
  rect_right[0].top = 48;
  rect_right[0].right = 48;
  rect_right[0].bottom = 64;
  rect_right[1].left = 48;
  rect_right[1].top = 48;
  rect_right[1].right = 64;
  rect_right[1].bottom = 64;
  rect_right[2].left = 64;
  rect_right[2].top = 48;
  rect_right[2].right = 80;
  rect_right[2].bottom = 64;
  rect_right[3].left = 80;
  rect_right[3].top = 48;
  rect_right[3].right = 96;
  rect_right[3].bottom = 64;
  if ( ++npc->ani_wait > 1 )
  {
    npc->ani_wait = 0;
    ++npc->ani_no;
  }
  if ( npc->ani_no > 2 )
    npc->ani_no = 0;
  if ( npc->direct )
  {
    v2 = npc;
    v3 = (Sint32 *)&v6[16 * npc->ani_no - 128];
  }
  else
  {
    v2 = npc;
    v3 = (Sint32 *)&v6[16 * npc->ani_no - 64];
  }
  npc->rect.left = *v3;
  v2->rect.top = v3[1];
  v2->rect.right = v3[2];
  v2->rect.bottom = v3[3];
}


void ActNpc243(NPCHAR *npc)
{
  int v1;
  int v2;
  int v3;
  int v4;

  v1 = npc->act_no;
  if ( v1 )
  {
    if ( v1 != 1 )
      return;
  }
  else
  {
    npc->act_no = 1;
    npc->act_wait = Random(0, 500);
  }
  if ( npc->act_wait )
  {
    --npc->act_wait;
  }
  else
  {
    npc->act_no = 0;
    v2 = npc->direct;
    v3 = npc->y;
    v4 = Random(-32, 32);
    SetNpChar(242, npc->x, v3 + (v4 << 9), 0, 0, v2, 0, 256);
  }
}

void ActNpc244(NPCHAR *npc)
{
  bool bHit;
  int i;

  npc->ym += 64;
  bHit = 0;
  if ( npc->flag & 0xFF )
    bHit = 1;
  if ( npc->act_wait > 10 && npc->flag & 0x100 )
    bHit = 1;
  if ( bHit )
  {
    for ( i = 0; i <= 2; ++i )
      SetCaret(npc->x, npc->y + 2048, 1, 2);
    if ( npc->x > x - 0x20000 && npc->x < x + 0x20000 && npc->y > y - 81920 && npc->y < y + 81920 )
      PlaySoundObject(21, 1);
    npc->cond = 0;
  }
  else
  {
    if ( npc->ym > 1535 )
      npc->ym = 1535;
    npc->y += npc->ym;
    npc->rect.left = 96;
    npc->rect.top = 0;
    npc->rect.right = 104;
    npc->rect.bottom = 16;
  }
}

void ActNpc245(NPCHAR *npc)
{
  int v1;
  int v2;
  Sint32 *v3;
  RECT rc[4];
  char v5[8];

  rc[0].left = 0;
  rc[0].top = 0;
  rc[0].right = 0;
  rc[0].bottom = 0;
  rc[1].left = 104;
  rc[1].top = 0;
  rc[1].right = 112;
  rc[1].bottom = 16;
  rc[2].left = 112;
  rc[2].top = 0;
  rc[2].right = 120;
  rc[2].bottom = 16;
  rc[3].left = 120;
  rc[3].top = 0;
  rc[3].right = 128;
  rc[3].bottom = 16;
  v1 = npc->act_no;
  switch ( v1 )
  {
    case 1:
      goto LABEL_5;
    case 10:
      if ( ++npc->ani_wait > 10 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 3 )
      {
        SetNpChar(244, npc->x, npc->y, 0, 0, 0, 0, 256);
        npc->act_no = 1;
        npc->act_wait = npc->code_flag;
      }
      break;
    case 0:
      npc->act_no = 1;
      npc->tgt_x = npc->x;
      npc->act_wait = npc->code_event;
LABEL_5:
      npc->ani_no = 0;
      if ( npc->act_wait )
      {
        --npc->act_wait;
        return;
      }
      npc->act_no = 10;
      npc->ani_wait = 0;
      break;
  }
  if ( npc->ani_wait / 2 & 1 )
    v2 = npc->tgt_x;
  else
    v2 = npc->tgt_x + 512;
  npc->x = v2;
  v3 = (Sint32 *)&v5[16 * npc->ani_no - 64];
  npc->rect.left = *v3;
  npc->rect.top = v3[1];
  npc->rect.right = v3[2];
  npc->rect.bottom = v3[3];
}


void ActNpc246(NPCHAR *npc)
{
  int v1;
  int v2;
  int v3;
  Sint32 *v4;
  RECT rcLeft[3];
  int i;
  char v7[8];

  rcLeft[0].left = 144;
  rcLeft[0].top = 112;
  rcLeft[0].right = 160;
  rcLeft[0].bottom = 136;
  rcLeft[1].left = 160;
  rcLeft[1].top = 112;
  rcLeft[1].right = 176;
  rcLeft[1].bottom = 136;
  rcLeft[2].left = 176;
  rcLeft[2].top = 112;
  rcLeft[2].right = 192;
  rcLeft[2].bottom = 136;
  v1 = npc->act_no;
  if ( v1 == 1 )
  {
LABEL_9:
    if ( x < npc->x + 4096 && x > npc->x - 4096 && y > npc->y + 4096 && y < npc->y + 0x10000 )
      npc->act_no = 5;
    goto LABEL_30;
  }
  if ( v1 <= 1 )
  {
    if ( v1 )
      goto LABEL_30;
    npc->act_no = 1;
    npc->y -= 2048;
    goto LABEL_9;
  }
  if ( v1 == 5 )
  {
    if ( !(npc->flag & 8) )
    {
      npc->act_no = 10;
      npc->ani_wait = 0;
      npc->ani_no = 1;
    }
  }
  else if ( v1 == 10 )
  {
    if ( ++npc->ani_wait > 2 )
    {
      npc->ani_wait = 0;
      ++npc->ani_no;
    }
    if ( npc->ani_no > 2 )
      npc->ani_no = 2;
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
    if ( npc->flag & 8 )
    {
      if ( npc->ani_no > 1 )
      {
        for ( i = 0; i <= 3; ++i )
        {
          v2 = Random(-1536, 0);
          v3 = Random(-341, 341);
          SetNpChar(4, npc->x, npc->y, v3, v2, 0, 0, 256);
        }
        PlaySoundObject(26, 1);
        SetQuake(10);
      }
      npc->act_no = 20;
      npc->ani_no = 0;
      npc->ani_wait = 0;
      npc->bits |= 0x40u;
      npc->damage = 0;
    }
  }
LABEL_30:
  if ( npc->act_no > 4 )
  {
    npc->ym += 128;
    if ( npc->ym > 1535 )
      npc->ym = 1535;
    npc->y += npc->ym;
  }
  v4 = (Sint32 *)&v7[16 * npc->ani_no - 52];
  npc->rect.left = *v4;
  npc->rect.top = v4[1];
  npc->rect.right = v4[2];
  npc->rect.bottom = v4[3];
}


void ActNpc247(NPCHAR *npc)
{
  int v1;
  int v2;
  char v3;
  int v4;
  int v5;
  NPCHAR *v6;
  Sint32 *v7;
  RECT rcRight[9];
  RECT rcLeft[9];
  unsigned __int8 deg;
  int xm;
  int ym;
  char v13[24];

  qmemcpy(rcLeft, &ActNpc247(NPCHAR *)::C.5, sizeof(rcLeft));
  qmemcpy(rcRight, &ActNpc247(NPCHAR *)::C.6, sizeof(rcRight));
  v1 = npc->act_no;
  if ( v1 == 111 )
  {
LABEL_60:
    ++npc->act_wait;
    if ( npc->act_wait & 1 )
      npc->ani_no = 5;
    else
      npc->ani_no = 6;
    if ( npc->act_wait > 30 )
    {
      npc->act_wait = 0;
      if ( ++npc->count1 % 3 )
        npc->act_no = 112;
      else
        npc->act_no = 113;
      npc->ani_no = 4;
    }
    goto LABEL_109;
  }
  if ( v1 > 111 )
  {
    if ( v1 != 151 )
    {
      if ( v1 > 151 )
      {
        if ( v1 == 1000 )
        {
          npc->bits &= 0xFFDFu;
          npc->act_no = 1001;
          npc->act_wait = 0;
          npc->ani_no = 4;
          npc->tgt_x = npc->x;
          npc->tgt_y = npc->y;
          npc->xm = 0;
          npc->ym = 0;
          DeleteNpCharCode(252, 1);
          SetNpChar(4, npc->x, npc->y, 0, 0, 0, 0, 256);
          SetNpChar(4, npc->x, npc->y, 0, 0, 0, 0, 256);
          SetNpChar(4, npc->x, npc->y, 0, 0, 0, 0, 256);
        }
        else
        {
          if ( v1 <= 1000 )
          {
            if ( v1 == 160 )
            {
              npc->act_no = 161;
              npc->act_wait = 0;
              npc->ani_no = 4;
              if ( x >= npc->x )
                npc->direct = 2;
              else
                npc->direct = 0;
            }
            else if ( v1 != 161 )
            {
              goto LABEL_109;
            }
            if ( npc->y >= npc->tgt_y )
              v4 = npc->ym - 32;
            else
              v4 = npc->ym + 32;
            npc->ym = v4;
            if ( npc->ym < -512 )
              npc->ym = -512;
            if ( npc->ym > 512 )
              npc->ym = 512;
            if ( !(++npc->act_wait % 24) )
            {
              SetNpChar(250, npc->x, npc->y + 2048, 0, 0, 0, 0, 256);
              PlaySoundObject(34, 1);
            }
            if ( npc->act_wait > 72 )
            {
              npc->act_wait = 0;
              npc->act_no = 100;
            }
            goto LABEL_109;
          }
          if ( v1 != 1001 )
          {
            if ( v1 == 1010 )
            {
              npc->ym += 16;
              if ( npc->flag & 8 )
              {
                npc->act_no = 1020;
                npc->ani_no = 8;
              }
            }
            goto LABEL_109;
          }
        }
        if ( ++npc->act_wait / 2 & 1 )
          v5 = npc->tgt_x + 512;
        else
          v5 = npc->tgt_x;
        npc->x = v5;
        goto LABEL_109;
      }
      if ( v1 == 113 )
      {
        if ( ++npc->act_wait == 10 )
        {
          ym = y - 0x8000;
          SetNpChar(279, x, y - 0x8000, 0, 0, 1, 0, 256);
        }
        if ( npc->act_wait > 30 )
        {
          npc->act_wait = 0;
          npc->act_no = 150;
        }
        goto LABEL_109;
      }
      if ( v1 < 113 )
      {
        if ( !(++npc->act_wait % 6) )
        {
          deg = GetArktan(npc->x - x, npc->y - y);
          v3 = Random(-4, 4);
          deg += v3;
          ym = 4 * GetSin(deg);
          xm = 4 * GetCos(deg);
          SetNpChar(248, npc->x, npc->y + 2048, xm, ym, 0, 0, 256);
          PlaySoundObject(34, 1);
        }
        if ( npc->act_wait > 30 )
        {
          npc->act_wait = 0;
          npc->act_no = 150;
        }
        goto LABEL_109;
      }
      if ( v1 == 120 || v1 != 150 )
        goto LABEL_109;
      npc->act_no = 151;
      npc->act_wait = 0;
      npc->ani_no = 7;
      SetNpChar(249, npc->x, npc->y, 0, 0, 0, 0, 256);
      SetNpChar(249, npc->x, npc->y, 0, 0, 2, 0, 256);
      npc->tgt_x = Random(9, 31) << 13;
      npc->tgt_y = Random(5, 7) << 13;
      PlaySoundObject(29, 1);
    }
    if ( ++npc->act_wait == 42 )
    {
      SetNpChar(249, npc->tgt_x + 0x2000, npc->tgt_y, 0, 0, 0, 0, 256);
      SetNpChar(249, npc->tgt_x - 0x2000, npc->tgt_y, 0, 0, 2, 0, 256);
    }
    if ( npc->act_wait > 50 )
    {
      npc->act_wait = 0;
      npc->ym = -512;
      npc->bits |= 0x20u;
      npc->x = npc->tgt_x;
      npc->y = npc->tgt_y;
      if ( npc->life <= 339 )
      {
        SetNpChar(252, 0, 0, 0, 0, 0, npc, 256);
        SetNpChar(252, 0, 0, 0, 0, 128, npc, 256);
      }
      if ( npc->life <= 179 )
      {
        SetNpChar(252, 0, 0, 0, 0, 64, npc, 256);
        SetNpChar(252, 0, 0, 0, 0, 192, npc, 256);
      }
      if ( x >= npc->x - 57344 && x <= npc->x + 57344 )
        npc->act_no = 100;
      else
        npc->act_no = 160;
    }
    goto LABEL_109;
  }
  if ( v1 == 21 )
  {
    if ( Random(0, 120) == 10 )
    {
      npc->act_no = 22;
      npc->act_wait = 0;
      npc->ani_no = 3;
    }
    goto LABEL_109;
  }
  if ( v1 > 21 )
  {
    if ( v1 == 100 )
    {
      npc->act_no = 101;
      npc->act_wait = 0;
      npc->ani_no = 0;
      npc->xm = 0;
      npc->bits |= 0x20u;
      npc->count2 = npc->life;
    }
    else
    {
      if ( v1 <= 100 )
      {
        if ( v1 == 22 && ++npc->act_wait > 8 )
        {
          npc->act_no = 21;
          npc->ani_no = 2;
        }
        goto LABEL_109;
      }
      if ( v1 != 101 )
      {
        if ( v1 != 110 )
          goto LABEL_109;
        npc->act_no = 111;
        npc->act_wait = 0;
        npc->xm = 0;
        npc->ym = 0;
        npc->bits &= 0xFFDFu;
        goto LABEL_60;
      }
    }
    if ( x >= npc->x )
      npc->direct = 2;
    else
      npc->direct = 0;
    if ( npc->y >= npc->tgt_y )
      v2 = npc->ym - 32;
    else
      v2 = npc->ym + 32;
    npc->ym = v2;
    if ( npc->ym < -512 )
      npc->ym = -512;
    if ( npc->ym > 512 )
      npc->ym = 512;
    if ( ++npc->act_wait > 200 || npc->life <= npc->count2 - 80 )
    {
      npc->act_wait = 0;
      npc->act_no = 110;
    }
    goto LABEL_109;
  }
  if ( v1 == 1 )
  {
LABEL_35:
    if ( Random(0, 120) == 10 )
    {
      npc->act_no = 2;
      npc->act_wait = 0;
      npc->ani_no = 1;
    }
    goto LABEL_109;
  }
  if ( v1 <= 1 )
  {
    if ( v1 )
      goto LABEL_109;
    npc->act_no = 1;
    npc->y += 3072;
    npc->tgt_y = 0x8000;
    goto LABEL_35;
  }
  if ( v1 == 2 )
  {
    if ( ++npc->act_wait > 8 )
    {
      npc->act_no = 1;
      npc->ani_no = 0;
    }
  }
  else if ( v1 == 20 )
  {
    npc->xm = 0;
    npc->ym += 64;
    if ( npc->flag & 8 )
    {
      npc->act_no = 21;
      npc->ani_no = 2;
    }
  }
LABEL_109:
  if ( npc->xm < -512 )
    npc->xm = -512;
  if ( npc->xm > 512 )
    npc->xm = 512;
  if ( npc->ym < -1024 )
    npc->ym = -1024;
  if ( npc->ym > 1024 )
    npc->ym = 1024;
  npc->x += npc->xm;
  npc->y += npc->ym;
  if ( npc->direct )
  {
    v6 = npc;
    v7 = (Sint32 *)&v13[16 * npc->ani_no - 300];
  }
  else
  {
    v6 = npc;
    v7 = (Sint32 *)&v13[16 * npc->ani_no - 156];
  }
  npc->rect.left = *v7;
  v6->rect.top = v7[1];
  v6->rect.right = v7[2];
  v6->rect.bottom = v7[3];
}


void ActNpc248(NPCHAR *npc)
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
  rect_left[0].left = 0;
  rect_left[0].top = 48;
  rect_left[0].right = 16;
  rect_left[0].bottom = 64;
  rect_left[1].left = 16;
  rect_left[1].top = 48;
  rect_left[1].right = 32;
  rect_left[1].bottom = 64;
  rect_left[2].left = 32;
  rect_left[2].top = 48;
  rect_left[2].right = 48;
  rect_left[2].bottom = 64;
  if ( ++npc->ani_wait > 1 )
  {
    npc->ani_wait = 0;
    if ( ++npc->ani_no > 2 )
      npc->ani_no = 0;
  }
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


void ActNpc249(NPCHAR *npc)
{
  int v1;

  if ( ++npc->act_wait > 8 )
    npc->cond = 0;
  if ( npc->direct )
  {
    npc->rect.left = 64;
    npc->rect.top = 48;
    npc->rect.right = 80;
    npc->rect.bottom = 64;
    v1 = npc->x + 1024;
  }
  else
  {
    npc->rect.left = 48;
    npc->rect.top = 48;
    npc->rect.right = 64;
    npc->rect.bottom = 64;
    v1 = npc->x - 1024;
  }
  npc->x = v1;
}

void ActNpc250(NPCHAR *npc)
{
  int v1;
  int v2;
  int v3;
  Sint32 *v4;
  RECT rc[3];
  char v6[8];

  rc[0].left = 0;
  rc[0].top = 32;
  rc[0].right = 16;
  rc[0].bottom = 48;
  rc[1].left = 16;
  rc[1].top = 32;
  rc[1].right = 32;
  rc[1].bottom = 48;
  rc[2].left = 32;
  rc[2].top = 32;
  rc[2].right = 48;
  rc[2].bottom = 48;
  v1 = npc->act_no;
  if ( v1 == 1 )
    goto LABEL_9;
  if ( v1 <= 1 )
  {
    if ( v1 )
      goto LABEL_37;
    npc->act_no = 1;
    npc->tgt_y = npc->y;
    npc->xm = 0;
    npc->ym = -512;
LABEL_9:
    if ( npc->x >= x )
      v2 = npc->xm - 16;
    else
      v2 = npc->xm + 16;
    npc->xm = v2;
    if ( npc->y >= npc->tgt_y )
      v3 = npc->ym - 32;
    else
      v3 = npc->ym + 32;
    npc->ym = v3;
    if ( npc->xm > 512 )
      npc->xm = 512;
    if ( npc->xm < -512 )
      npc->xm = -512;
    if ( npc->ym > 512 )
      npc->ym = 512;
    if ( npc->ym < -512 )
      npc->ym = -512;
    npc->x += npc->xm;
    npc->y += npc->ym;
    if ( ++npc->ani_wait > 2 )
    {
      npc->ani_wait = 0;
      ++npc->ani_no;
    }
    if ( npc->ani_no > 1 )
      npc->ani_no = 0;
    if ( x > npc->x - 4096 && x < npc->x + 4096 && y > npc->y )
      npc->act_no = 10;
    goto LABEL_37;
  }
  if ( v1 == 10 )
  {
    npc->act_no = 11;
    npc->act_wait = 0;
  }
  else if ( v1 != 11 )
  {
    goto LABEL_37;
  }
  if ( ++npc->act_wait > 10 )
  {
    SetNpChar(251, npc->x, npc->y, 0, 0, 0, 0, 256);
    PlaySoundObject(101, 1);
    npc->cond = 0;
    return;
  }
  if ( npc->act_wait / 2 & 1 )
    npc->ani_no = 2;
  else
    npc->ani_no = 1;
LABEL_37:
  v4 = (Sint32 *)&v6[16 * npc->ani_no - 48];
  npc->rect.left = *v4;
  npc->rect.top = v4[1];
  npc->rect.right = v4[2];
  npc->rect.bottom = v4[3];
}


void ActNpc251(NPCHAR *npc)
{
  int v1;
  Sint32 *v2;
  RECT rc[2];
  char v4[8];

  rc[0].left = 80;
  rc[0].top = 32;
  rc[0].right = 96;
  rc[0].bottom = 64;
  rc[1].left = 96;
  rc[1].top = 32;
  rc[1].right = 112;
  rc[1].bottom = 64;
  v1 = npc->act_no;
  if ( v1 )
  {
    if ( v1 != 1 )
      goto LABEL_9;
  }
  else
  {
    npc->act_no = 1;
  }
  if ( ++npc->ani_no > 1 )
    npc->ani_no = 0;
  npc->y += 4096;
  if ( npc->flag & 0xFF )
  {
    SetDestroyNpChar(npc->x, npc->y, npc->view.back, 3);
    npc->cond = 0;
  }
LABEL_9:
  v2 = (Sint32 *)&v4[16 * npc->ani_no - 32];
  npc->rect.left = *v2;
  npc->rect.top = v2[1];
  npc->rect.right = v2[2];
  npc->rect.bottom = v2[3];
}


void ActNpc252(NPCHAR *npc)
{
  int v1;
  int v2;
  int v3;
  NPCHAR *v4;
  Sint32 *v5;
  RECT rcRight[4];
  RECT rcLeft[4];
  unsigned __int8 deg;
  char v9[8];

  rcLeft[0].left = 48;
  rcLeft[0].top = 32;
  rcLeft[0].right = 64;
  rcLeft[0].bottom = 48;
  rcLeft[1].left = 112;
  rcLeft[1].top = 32;
  rcLeft[1].right = 128;
  rcLeft[1].bottom = 48;
  rcLeft[2].left = 128;
  rcLeft[2].top = 32;
  rcLeft[2].right = 144;
  rcLeft[2].bottom = 48;
  rcLeft[3].left = 144;
  rcLeft[3].top = 32;
  rcLeft[3].right = 160;
  rcLeft[3].bottom = 48;
  rcRight[0].left = 48;
  rcRight[0].top = 32;
  rcRight[0].right = 64;
  rcRight[0].bottom = 48;
  rcRight[1].left = 112;
  rcRight[1].top = 48;
  rcRight[1].right = 128;
  rcRight[1].bottom = 64;
  rcRight[2].left = 128;
  rcRight[2].top = 48;
  rcRight[2].right = 144;
  rcRight[2].bottom = 64;
  rcRight[3].left = 144;
  rcRight[3].top = 48;
  rcRight[3].right = 160;
  rcRight[3].bottom = 64;
  v1 = npc->act_no;
  if ( v1 == 1 )
  {
LABEL_9:
    npc->count1 += 2;
    npc->count1 = (unsigned __int8)(((unsigned __int64)npc->count1 >> 56) + npc->count1)
                - ((unsigned int)(npc->count1 >> 31) >> 24);
    deg = npc->count1;
    if ( npc->act_wait <= 191 )
      ++npc->act_wait;
    v2 = npc->pNpc->x;
    npc->x = v2 + npc->act_wait * GetCos(deg) / 4;
    v3 = npc->pNpc->y;
    npc->y = v3 + npc->act_wait * GetSin(deg) / 4;
    if ( npc->pNpc->act_no == 151 )
    {
      npc->act_no = 10;
      npc->ani_no = 0;
    }
    goto LABEL_22;
  }
  if ( v1 <= 1 )
  {
    if ( v1 )
      goto LABEL_22;
    npc->act_no = 1;
    npc->act_wait = 0;
    npc->count1 = npc->direct;
    goto LABEL_9;
  }
  if ( v1 == 10 )
  {
    npc->act_no = 11;
    npc->bits |= 0x20u;
    npc->bits &= 0xFFFBu;
    npc->bits &= 0xFFF7u;
    deg = GetArktan(npc->x - x, npc->y - y);
    deg += Random(-3, 3);
    npc->xm = GetCos(deg);
    npc->ym = GetSin(deg);
    npc->ani_no = 1;
    npc->ani_wait = 0;
    if ( npc->x <= x )
      npc->direct = 2;
    else
      npc->direct = 0;
  }
  else if ( v1 != 11 )
  {
    goto LABEL_22;
  }
  npc->x += npc->xm;
  npc->y += npc->ym;
  if ( npc->flag & 0xFF )
  {
    SetNpChar(4, npc->x, npc->y, 0, 0, 0, 0, 256);
    SetNpChar(4, npc->x, npc->y, 0, 0, 0, 0, 256);
    SetNpChar(4, npc->x, npc->y, 0, 0, 0, 0, 256);
    npc->cond = 0;
  }
  if ( ++npc->ani_wait > 4 )
  {
    npc->ani_wait = 0;
    ++npc->ani_no;
  }
  if ( npc->ani_no > 3 )
    npc->ani_no = 1;
LABEL_22:
  if ( npc->direct )
  {
    v4 = npc;
    v5 = (Sint32 *)&v9[16 * npc->ani_no - 132];
  }
  else
  {
    v4 = npc;
    v5 = (Sint32 *)&v9[16 * npc->ani_no - 68];
  }
  npc->rect.left = *v5;
  v4->rect.top = v5[1];
  v4->rect.right = v5[2];
  v4->rect.bottom = v5[3];
}


void ActNpc253(NPCHAR *npc)
{
  int v1;
  Sint32 *v2;
  RECT rc[2];
  char v4[8];

  v1 = npc->act_no;
  if ( v1 )
  {
    if ( v1 != 1 )
      goto LABEL_9;
  }
  else
  {
    npc->act_no = 1;
  }
  if ( ++npc->ani_wait > 4 )
  {
    npc->ani_wait = 0;
    ++npc->ani_no;
  }
  if ( npc->ani_no > 1 )
    npc->ani_no = 0;
LABEL_9:
  if ( npc->life <= 100 )
  {
    SetExpObjects(npc->x, npc->y, npc->code_flag);
    SetDestroyNpChar(npc->x, npc->y, npc->view.back, 8);
    PlaySoundObject(25, 1);
    npc->cond = 0;
  }
  rc[0].left = 0;
  rc[0].top = 64;
  rc[0].right = 16;
  rc[0].bottom = 80;
  rc[1].left = 16;
  rc[1].top = 64;
  rc[1].right = 32;
  rc[1].bottom = 80;
  v2 = (Sint32 *)&v4[16 * npc->ani_no - 32];
  npc->rect.left = *v2;
  npc->rect.top = v2[1];
  npc->rect.right = v2[2];
  npc->rect.bottom = v2[3];
}


void ActNpc254(NPCHAR *npc)
{
  switch ( npc->act_no )
  {
    case 0:
      npc->act_no = 1;
      SetNpChar(255, npc->x + 9216, npc->y - 29184, 0, 0, 0, npc, 256);
      SetNpChar(255, npc->x - 0x4000, npc->y - 26624, 0, 0, 2, npc, 256);
      break;
    case 0x14:
      npc->act_wait = 0;
      npc->count1 = 60;
      npc->act_no = 21;
      break;
    case 0x1E:
      npc->act_no = 21;
      SetNpChar(223, npc->x - 5632, npc->y - 7168, 0, 0, 0, 0, 256);
      break;
    case 0x28:
      npc->act_no = 21;
      SetNpChar(223, npc->x - 4608, npc->y - 7168, 0, 0, 0, 0, 256);
      SetNpChar(40, npc->x - 11264, npc->y - 7168, 0, 0, 0, 0, 256);
      SetNpChar(93, npc->x - 17920, npc->y - 7168, 0, 0, 0, 0, 256);
      break;
    default:
      break;
  }
  if ( npc->direct )
  {
    npc->rect.left = 0;
    npc->rect.top = 64;
    npc->rect.right = 128;
    npc->rect.bottom = 128;
  }
  else
  {
    npc->rect.left = 0;
    npc->rect.top = 0;
    npc->rect.right = 128;
    npc->rect.bottom = 64;
  }
}

void ActNpc255(NPCHAR *npc)
{
  int v1;
  int v2;
  NPCHAR *v3;
  RECT *v4;
  RECT rcRight[4];
  RECT rcLeft[4];

  rcLeft[0].left = 128;
  rcLeft[0].top = 0;
  rcLeft[0].right = 240;
  rcLeft[0].bottom = 16;
  rcLeft[1].left = 128;
  rcLeft[1].top = 16;
  rcLeft[1].right = 240;
  rcLeft[1].bottom = 32;
  rcLeft[2].left = 128;
  rcLeft[2].top = 32;
  rcLeft[2].right = 240;
  rcLeft[2].bottom = 48;
  rcLeft[3].left = 128;
  rcLeft[3].top = 16;
  rcLeft[3].right = 240;
  rcLeft[3].bottom = 32;
  rcRight[0].left = 240;
  rcRight[0].top = 0;
  rcRight[0].right = 320;
  rcRight[0].bottom = 16;
  rcRight[1].left = 240;
  rcRight[1].top = 16;
  rcRight[1].right = 320;
  rcRight[1].bottom = 32;
  rcRight[2].left = 240;
  rcRight[2].top = 32;
  rcRight[2].right = 320;
  rcRight[2].bottom = 48;
  rcRight[3].left = 240;
  rcRight[3].top = 16;
  rcRight[3].right = 320;
  rcRight[3].bottom = 32;
  v1 = npc->act_no;
  if ( v1 == 1 )
  {
LABEL_11:
    if ( npc->pNpc->act_no > 19 )
      npc->act_no = 10;
    goto LABEL_16;
  }
  if ( v1 <= 1 )
  {
    if ( v1 )
      goto LABEL_16;
    npc->act_no = 1;
    if ( npc->direct )
    {
      npc->view.front = 20480;
      npc->view.back = 20480;
    }
    else
    {
      npc->view.front = 28672;
      npc->view.back = 28672;
    }
    goto LABEL_11;
  }
  if ( v1 == 10 )
  {
    npc->act_no = 11;
  }
  else if ( v1 != 11 )
  {
    goto LABEL_16;
  }
  if ( ++npc->ani_no > 3 )
    npc->ani_no = 0;
LABEL_16:
  if ( npc->direct )
  {
    npc->x = npc->pNpc->x - 0x4000;
    v2 = npc->pNpc->y - 26624;
  }
  else
  {
    npc->x = npc->pNpc->x + 9216;
    v2 = npc->pNpc->y - 29184;
  }
  npc->y = v2;
  if ( npc->direct )
  {
    v3 = npc;
    v4 = &rcRight[npc->ani_no];
  }
  else
  {
    v3 = npc;
    v4 = &rcLeft[npc->ani_no];
  }
  npc->rect.left = v4->left;
  v3->rect.top = v4->top;
  v3->rect.right = v4->right;
  v3->rect.bottom = v4->bottom;
}

void ActNpc256(NPCHAR *npc)
{
  Sint32 *v1;
  RECT rcLeft[6];
  char v3[24];

  qmemcpy(rcLeft, &ActNpc256(NPCHAR *)::C.11, sizeof(rcLeft));
  switch ( npc->act_no )
  {
    case 0:
      gSuperXpos = 0;
      npc->act_no = 1;
      npc->y -= 4096;
      goto LABEL_3;
    case 1:
LABEL_3:
      npc->ani_no = 0;
      break;
    case 0xA:
      npc->act_no = 11;
      npc->ani_wait = 0;
      npc->ani_no = 0;
      npc->count1 = 0;
      goto LABEL_5;
    case 0xB:
LABEL_5:
      if ( ++npc->ani_wait > 5 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 1 )
      {
        npc->ani_no = 0;
        ++npc->count1;
      }
      if ( npc->count1 > 5 )
        npc->act_no = 1;
      break;
    case 0x14:
      npc->act_no = 21;
      goto LABEL_12;
    case 0x15:
LABEL_12:
      npc->ani_no = 2;
      break;
    case 0x28:
      npc->act_no = 41;
      SetNpChar(257, npc->x - 7168, npc->y - 0x2000, 0, 0, 0, 0, 256);
      SetNpChar(257, npc->x - 7168, npc->y - 0x2000, 0, 0, 2, 0, 170);
      goto LABEL_14;
    case 0x29:
LABEL_14:
      npc->ani_no = 4;
      break;
    case 0x32:
      npc->act_no = 51;
      npc->ani_wait = 0;
      npc->ani_no = 4;
      npc->count1 = 0;
      goto LABEL_16;
    case 0x33:
LABEL_16:
      if ( ++npc->ani_wait > 5 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 5 )
      {
        npc->ani_no = 4;
        ++npc->count1;
      }
      if ( npc->count1 > 5 )
        npc->act_no = 41;
      break;
    default:
      break;
  }
  v1 = (Sint32 *)&v3[16 * npc->ani_no - 96];
  npc->rect.left = *v1;
  npc->rect.top = v1[1];
  npc->rect.right = v1[2];
  npc->rect.bottom = v1[3];
}


void ActNpc257(NPCHAR *npc)
{
  int v1;
  RECT *v2;
  RECT rc[3];

  rc[0].left = 176;
  rc[0].top = 32;
  rc[0].right = 184;
  rc[0].bottom = 48;
  rc[1].left = 184;
  rc[1].top = 32;
  rc[1].right = 192;
  rc[1].bottom = 48;
  rc[2].left = 0;
  rc[2].top = 0;
  rc[2].right = 0;
  rc[2].bottom = 0;
  v1 = npc->act_no;
  if ( v1 == 1 )
  {
LABEL_5:
    if ( gSuperXpos )
      npc->act_no = 10;
    goto LABEL_24;
  }
  if ( v1 != 10 )
  {
    if ( v1 )
      goto LABEL_24;
    npc->act_no = 1;
    goto LABEL_5;
  }
  if ( npc->x < gSuperXpos )
    npc->xm += 85;
  if ( npc->x > gSuperXpos )
    npc->xm -= 85;
  if ( npc->y < gSuperYpos )
    npc->ym += 85;
  if ( npc->y > gSuperYpos )
    npc->ym -= 85;
  if ( npc->xm > 1024 )
    npc->xm = 1024;
  if ( npc->xm < -1024 )
    npc->xm = -1024;
  if ( npc->ym > 1024 )
    npc->ym = 1024;
  if ( npc->ym < -1024 )
    npc->ym = -1024;
  npc->x += npc->xm;
  npc->y += npc->ym;
LABEL_24:
  if ( ++npc->ani_wait > 3 )
  {
    npc->ani_wait = 0;
    ++npc->ani_no;
  }
  if ( npc->ani_no > 1 )
    npc->ani_no = 0;
  if ( !npc->direct && npc->xm > 0 )
    npc->ani_no = 2;
  if ( npc->direct == 2 && npc->xm < 0 )
    npc->ani_no = 2;
  v2 = &rc[npc->ani_no];
  npc->rect.left = v2->left;
  npc->rect.top = v2->top;
  npc->rect.right = v2->right;
  npc->rect.bottom = v2->bottom;
}

void ActNpc258(NPCHAR *npc)
{
  npc->rect.left = 48;
  npc->rect.top = 32;
  npc->rect.right = 64;
  npc->rect.bottom = 48;
}

void ActNpc259(NPCHAR *npc)
{
  unsigned __int16 v1;

  switch ( npc->act_no )
  {
    case 0:
      v1 = npc->bits;
      HIBYTE(v1) &= 0xDFu;
      npc->bits = v1;
      npc->act_no = 1;
      goto LABEL_3;
    case 1:
LABEL_3:
      if ( dir )
        npc->direct = 2;
      else
        npc->direct = 0;
      npc->y = y - 2048;
      if ( npc->direct )
      {
        npc->x = x - 1536;
        npc->rect.left = 224;
        npc->rect.top = 112;
        npc->rect.right = 240;
        npc->rect.bottom = 128;
      }
      else
      {
        npc->x = x + 1536;
        npc->rect.left = 224;
        npc->rect.top = 96;
        npc->rect.right = 240;
        npc->rect.bottom = 112;
      }
      if ( unk_81C85C0 & 1 )
        ++npc->rect.top;
      break;
    case 0xA:
      npc->act_no = 11;
      npc->xm = 64;
      npc->ym = -32;
      npc->rect.left = 224;
      npc->rect.top = 96;
      npc->rect.right = 240;
      npc->rect.bottom = 112;
      break;
    case 0xB:
      if ( npc->y <= 0x7FFF )
        npc->ym = 32;
      npc->x += npc->xm;
      npc->y += npc->ym;
      break;
    case 0x14:
      VanishNpChar(npc);
      SetDestroyNpCharUp(npc->x, npc->y, 0x2000, 64);
      break;
    default:
      return;
  }
}

