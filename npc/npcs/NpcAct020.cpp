#include "types.h"
#include "SDL_stdinc.h"
#include "windows_wrapper.h"
#include "Tags.h"
#include "forNpc.h"

void __cdecl ActNpc020(NPCHAR_0 *npc);
void __cdecl ActNpc021(NPCHAR_0 *npc);
void __cdecl ActNpc022(NPCHAR_0 *npc);
void __cdecl ActNpc023(NPCHAR_0 *npc);
void __cdecl ActNpc024(NPCHAR_0 *npc);
void __cdecl ActNpc025(NPCHAR_0 *npc);
void __cdecl ActNpc026(NPCHAR_0 *npc);
void __cdecl ActNpc027(NPCHAR_0 *npc);
void __cdecl ActNpc028(NPCHAR_0 *npc);
void __cdecl ActNpc029(NPCHAR_0 *npc);
void __cdecl ActNpc030(NPCHAR_0 *npc);
void __cdecl ActNpc031(NPCHAR_0 *npc);
void __cdecl ActNpc032(NPCHAR_0 *npc);
void __cdecl ActNpc033(NPCHAR_0 *npc);
void __cdecl ActNpc034(NPCHAR_0 *npc);
void __cdecl ActNpc035(NPCHAR_0 *npc);
void __cdecl ActNpc036(NPCHAR_0 *npc);
void __cdecl ActNpc037(NPCHAR_0 *npc);
void __cdecl ActNpc038(NPCHAR_0 *npc);
void __cdecl ActNpc039(NPCHAR_0 *npc);

_UNKNOWN ActNpc036(NPCHAR *)::C.12;
_UNKNOWN ActNpc036(NPCHAR *)::C.13;
_UNKNOWN ActNpc031(NPCHAR *)::C.6;
_UNKNOWN ActNpc031(NPCHAR *)::C.7;
_UNKNOWN ActNpc028(NPCHAR *)::C.3;
_UNKNOWN ActNpc028(NPCHAR *)::C.4;
_UNKNOWN ActNpc024(NPCHAR *)::C.1;
_UNKNOWN ActNpc024(NPCHAR *)::C.2;
_UNKNOWN ActNpc023(NPCHAR *)::C.0;


void __cdecl ActNpc020(NPCHAR_0 *npc)
{
  RECT *v1;
  RECT rcRight[3];
  RECT rcLeft;

  rcLeft.left = 288;
  rcLeft.top = 16;
  rcLeft.right = 320;
  rcLeft.bottom = 40;
  rcRight[0].left = 288;
  rcRight[0].top = 40;
  rcRight[0].right = 320;
  rcRight[0].bottom = 64;
  rcRight[1].left = 288;
  rcRight[1].top = 40;
  rcRight[1].right = 320;
  rcRight[1].bottom = 64;
  rcRight[2].left = 288;
  rcRight[2].top = 64;
  rcRight[2].right = 320;
  rcRight[2].bottom = 88;
  if ( ++npc->ani_wait > 3 )
  {
    npc->ani_wait = 0;
    ++npc->ani_no;
  }
  if ( npc->ani_no > 2 )
    npc->ani_no = 0;
  if ( npc->direct )
  {
    v1 = &rcRight[npc->ani_no];
    npc->rect.left = v1->left;
    npc->rect.top = v1->top;
    npc->rect.right = v1->right;
    npc->rect.bottom = v1->bottom;
  }
  else
  {
    npc->rect = rcLeft;
  }
}

void __cdecl ActNpc021(NPCHAR_0 *npc)
{
  if ( !npc->act_no )
  {
    npc->act_no = 1;
    if ( npc->direct == 2 )
      npc->y += 0x2000;
  }
  npc->rect.left = 224;
  npc->rect.top = 40;
  npc->rect.right = 240;
  npc->rect.bottom = 48;
}

void __cdecl ActNpc022(NPCHAR_0 *npc)
{
  int v1;
  RECT *v2;
  RECT rect[2];

  rect[0].left = 240;
  rect[0].top = 16;
  rect[0].right = 264;
  rect[0].bottom = 48;
  rect[1].left = 248;
  rect[1].top = 152;
  rect[1].right = 272;
  rect[1].bottom = 184;
  v1 = npc->act_no;
  if ( v1 )
  {
    if ( v1 == 1 && ++npc->ani_no > 1 )
      npc->ani_no = 0;
  }
  else
  {
    npc->ani_no = 0;
  }
  v2 = &rect[npc->ani_no];
  npc->rect.left = v2->left;
  npc->rect.top = v2->top;
  npc->rect.right = v2->right;
  npc->rect.bottom = v2->bottom;
}

void __cdecl ActNpc023(NPCHAR_0 *npc)
{
  Sint32 *v1;
  RECT rect[8];
  char v3[12];

  qmemcpy(rect, &ActNpc023(NPCHAR *)::C.0, sizeof(rect));
  if ( ++npc->ani_wait > 1 )
  {
    npc->ani_wait = 0;
    ++npc->ani_no;
  }
  if ( npc->ani_no > 7 )
    npc->ani_no = 0;
  v1 = (Sint32 *)&v3[16 * npc->ani_no - 128];
  npc->rect.left = *v1;
  npc->rect.top = v1[1];
  npc->rect.right = v1[2];
  npc->rect.bottom = v1[3];
}


void __cdecl ActNpc024(NPCHAR_0 *npc)
{
  int v1;
  int v2;
  NPCHAR_0 *v3;
  Sint32 *v4;
  RECT rcRight[6];
  RECT rcLeft[6];
  char v7[24];

  qmemcpy(rcLeft, &ActNpc024(NPCHAR *)::C.1, sizeof(rcLeft));
  qmemcpy(rcRight, &ActNpc024(NPCHAR *)::C.2, sizeof(rcRight));
  switch ( npc->act_no )
  {
    case 0:
      npc->y += 1536;
      npc->act_no = 1;
      goto LABEL_3;
    case 1:
LABEL_3:
      if ( npc->act_wait <= 7
        || npc->x - 0x10000 >= x
        || npc->x + 0x10000 <= x
        || npc->y - 0x10000 >= y
        || npc->y + 24576 <= y )
      {
        if ( npc->act_wait <= 7 )
          ++npc->act_wait;
        npc->ani_no = 0;
      }
      else
      {
        if ( npc->x <= x )
          npc->direct = 2;
        else
          npc->direct = 0;
        npc->ani_no = 1;
      }
      if ( npc->shock )
      {
        npc->act_no = 2;
        npc->ani_no = 0;
        npc->act_wait = 0;
      }
      if ( npc->act_wait > 7 && npc->x - 49152 < x && npc->x + 49152 > x && npc->y - 49152 < y && npc->y + 24576 > y )
      {
        npc->act_no = 2;
        npc->ani_no = 0;
        npc->act_wait = 0;
      }
      break;
    case 2:
      if ( ++npc->act_wait > 8 )
      {
        npc->act_no = 3;
        npc->ani_no = 2;
        npc->ym = -1535;
        PlaySoundObject(108, 1);
        if ( npc->x <= x )
          npc->direct = 2;
        else
          npc->direct = 0;
        if ( npc->direct )
          npc->xm = 256;
        else
          npc->xm = -256;
      }
      break;
    case 3:
      if ( npc->ym > 512 )
      {
        npc->tgt_y = npc->y;
        npc->act_no = 4;
        npc->ani_no = 3;
        npc->act_wait = 0;
        npc->act_wait = 0;
      }
      break;
    case 4:
      if ( npc->x >= x )
        npc->direct = 0;
      else
        npc->direct = 2;
      ++npc->act_wait;
      if ( npc->flag & 7 || npc->act_wait > 100 )
      {
        npc->damage = 12;
        npc->act_no = 5;
        npc->ani_no = 2;
        npc->xm /= 2;
      }
      else
      {
        if ( npc->act_wait % 4 == 1 )
          PlaySoundObject(110, 1);
        if ( ++npc->ani_wait > 0 )
        {
          npc->ani_wait = 0;
          ++npc->ani_no;
        }
        if ( npc->ani_no > 5 )
          npc->ani_no = 3;
      }
      break;
    case 5:
      if ( npc->flag & 8 )
      {
        npc->damage = 2;
        npc->xm = 0;
        npc->act_wait = 0;
        npc->ani_no = 0;
        npc->act_no = 1;
        PlaySoundObject(26, 1);
        SetQuake(30);
      }
      break;
    default:
      break;
  }
  if ( npc->act_no == 4 )
  {
    if ( npc->x >= x )
      v1 = npc->xm - 32;
    else
      v1 = npc->xm + 32;
    npc->xm = v1;
    if ( npc->y <= npc->tgt_y )
      v2 = npc->ym + 16;
    else
      v2 = npc->ym - 16;
    npc->ym = v2;
    if ( npc->ym > 512 )
      npc->ym = 512;
    if ( npc->ym < -512 )
      npc->ym = -512;
    if ( npc->xm > 512 )
      npc->xm = 512;
    if ( npc->xm < -512 )
      npc->xm = -512;
  }
  else
  {
    npc->ym += 32;
    if ( npc->ym > 1535 )
      npc->ym = 1535;
  }
  npc->x += npc->xm;
  npc->y += npc->ym;
  if ( npc->direct )
  {
    v3 = npc;
    v4 = (Sint32 *)&v7[16 * npc->ani_no - 192];
  }
  else
  {
    v3 = npc;
    v4 = (Sint32 *)&v7[16 * npc->ani_no - 96];
  }
  npc->rect.left = *v4;
  v3->rect.top = v4[1];
  v3->rect.right = v4[2];
  v3->rect.bottom = v4[3];
}


void __cdecl ActNpc025(NPCHAR_0 *npc)
{
  unsigned int v1;
  Sint32 *v2;
  RECT rcLeft[2];
  char v4[4];

  rcLeft[0].left = 256;
  rcLeft[0].top = 64;
  rcLeft[0].right = 288;
  rcLeft[0].bottom = 80;
  rcLeft[1].left = 256;
  rcLeft[1].top = 80;
  rcLeft[1].right = 288;
  rcLeft[1].bottom = 96;
  switch ( npc->act_no )
  {
    case 0:
      npc->act_no = 1;
      npc->ani_no = 0;
      npc->ani_wait = 0;
      npc->x += 4096;
      goto LABEL_3;
    case 1:
LABEL_3:
      if ( ++npc->act_wait > 150 )
      {
        npc->act_wait = 0;
        ++npc->act_no;
      }
      break;
    case 2:
      if ( ++npc->act_wait > 64 )
      {
        npc->act_wait = 0;
        ++npc->act_no;
      }
      else
      {
        npc->y -= 512;
      }
      break;
    case 3:
      if ( ++npc->act_wait > 150 )
      {
        npc->act_wait = 0;
        ++npc->act_no;
      }
      break;
    case 4:
      if ( ++npc->act_wait > 64 )
      {
        npc->act_wait = 0;
        ++npc->act_no;
      }
      else
      {
        npc->y -= 512;
      }
      break;
    case 5:
      if ( ++npc->act_wait > 150 )
      {
        npc->act_wait = 0;
        ++npc->act_no;
      }
      break;
    case 6:
      if ( ++npc->act_wait > 64 )
      {
        npc->act_wait = 0;
        ++npc->act_no;
      }
      else
      {
        npc->y += 512;
      }
      break;
    case 7:
      if ( ++npc->act_wait > 150 )
      {
        npc->act_wait = 0;
        ++npc->act_no;
      }
      break;
    case 8:
      if ( ++npc->act_wait > 64 )
      {
        npc->act_wait = 0;
        npc->act_no = 1;
      }
      else
      {
        npc->y += 512;
      }
      break;
    default:
      break;
  }
  v1 = npc->act_no;
  if ( v1 <= 8 && (1 << v1) & 0x154 )
  {
    if ( ++npc->ani_wait > 1 )
    {
      npc->ani_wait = 0;
      ++npc->ani_no;
    }
    if ( npc->ani_no > 1 )
      npc->ani_no = 0;
  }
  v2 = (Sint32 *)&v4[16 * npc->ani_no - 32];
  npc->rect.left = *v2;
  npc->rect.top = v2[1];
  npc->rect.right = v2[2];
  npc->rect.bottom = v2[3];
}


void __cdecl ActNpc026(NPCHAR_0 *npc)
{
  int v1;
  int v2;
  int v3;
  NPCHAR_0 *v4;
  Sint32 *v5;
  RECT rect_right[4];
  RECT rect_left[4];
  unsigned __int8 deg;
  char v9[8];

  v1 = npc->act_no;
  if ( v1 == 1 )
  {
LABEL_5:
    if ( x >= npc->x )
      npc->direct = 2;
    else
      npc->direct = 0;
    if ( npc->tgt_x < npc->x )
      npc->xm -= 16;
    if ( npc->tgt_x > npc->x )
      npc->xm += 16;
    if ( npc->tgt_y < npc->y )
      npc->ym -= 16;
    if ( npc->tgt_y > npc->y )
      npc->ym += 16;
    if ( npc->xm > 512 )
      npc->xm = 512;
    if ( npc->xm < -512 )
      npc->xm = -512;
    if ( npc->ym > 512 )
      npc->ym = 512;
    if ( npc->ym < -512 )
      npc->ym = -512;
    if ( npc->count1 > 119 )
    {
      if ( npc->x - 4096 < x && npc->x + 4096 > x && npc->y < y && npc->y + 49152 > y )
      {
        npc->xm /= 2;
        npc->ym = 0;
        npc->act_no = 3;
        npc->bits &= 0xFFF7u;
      }
    }
    else
    {
      ++npc->count1;
    }
    goto LABEL_35;
  }
  if ( v1 != 3 )
  {
    if ( v1 )
      goto LABEL_35;
    deg = Random(0, 255);
    npc->xm = GetCos(deg);
    deg += 64;
    v2 = npc->x;
    npc->tgt_x = v2 + 8 * GetCos(deg);
    deg = Random(0, 255);
    npc->ym = GetSin(deg);
    deg += 64;
    v3 = npc->y;
    npc->tgt_y = v3 + 8 * GetSin(deg);
    npc->act_no = 1;
    npc->count1 = 120;
    goto LABEL_5;
  }
  npc->ym += 64;
  if ( npc->ym > 1535 )
    npc->ym = 1535;
  if ( npc->flag & 8 )
  {
    npc->ym = 0;
    npc->xm *= 2;
    npc->count1 = 0;
    npc->act_no = 1;
    npc->bits |= 8u;
  }
LABEL_35:
  npc->x += npc->xm;
  npc->y += npc->ym;
  rect_left[0].left = 32;
  rect_left[0].top = 80;
  rect_left[0].right = 48;
  rect_left[0].bottom = 96;
  rect_left[1].left = 48;
  rect_left[1].top = 80;
  rect_left[1].right = 64;
  rect_left[1].bottom = 96;
  rect_left[2].left = 64;
  rect_left[2].top = 80;
  rect_left[2].right = 80;
  rect_left[2].bottom = 96;
  rect_left[3].left = 80;
  rect_left[3].top = 80;
  rect_left[3].right = 96;
  rect_left[3].bottom = 96;
  rect_right[0].left = 32;
  rect_right[0].top = 96;
  rect_right[0].right = 48;
  rect_right[0].bottom = 112;
  rect_right[1].left = 48;
  rect_right[1].top = 96;
  rect_right[1].right = 64;
  rect_right[1].bottom = 112;
  rect_right[2].left = 64;
  rect_right[2].top = 96;
  rect_right[2].right = 80;
  rect_right[2].bottom = 112;
  rect_right[3].left = 80;
  rect_right[3].top = 96;
  rect_right[3].right = 96;
  rect_right[3].bottom = 112;
  if ( npc->act_no == 3 )
  {
    npc->ani_no = 3;
  }
  else
  {
    if ( ++npc->ani_wait > 1 )
    {
      npc->ani_wait = 0;
      ++npc->ani_no;
    }
    if ( npc->ani_no > 2 )
      npc->ani_no = 0;
  }
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


void __cdecl ActNpc027(NPCHAR_0 *npc)
{
  RECT *v1;
  RECT rcLeft[1];

  rcLeft[0].left = 96;
  rcLeft[0].top = 64;
  rcLeft[0].right = 128;
  rcLeft[0].bottom = 88;
  v1 = &rcLeft[npc->ani_no];
  npc->rect.left = v1->left;
  npc->rect.top = v1->top;
  npc->rect.right = v1->right;
  npc->rect.bottom = v1->bottom;
}

void __cdecl ActNpc028(NPCHAR_0 *npc)
{
  int v1;
  int v2;
  NPCHAR_0 *v3;
  Sint32 *v4;
  RECT rcRight[6];
  RECT rcLeft[6];
  char v7[24];

  qmemcpy(rcLeft, &ActNpc028(NPCHAR *)::C.3, sizeof(rcLeft));
  qmemcpy(rcRight, &ActNpc028(NPCHAR *)::C.4, sizeof(rcRight));
  switch ( npc->act_no )
  {
    case 0:
      npc->y += 1536;
      npc->act_no = 1;
      goto LABEL_3;
    case 1:
LABEL_3:
      if ( npc->act_wait <= 7
        || npc->x - 0x10000 >= x
        || npc->x + 0x10000 <= x
        || npc->y - 0x10000 >= y
        || npc->y + 24576 <= y )
      {
        if ( npc->act_wait <= 7 )
          ++npc->act_wait;
        npc->ani_no = 0;
      }
      else
      {
        if ( npc->x <= x )
          npc->direct = 2;
        else
          npc->direct = 0;
        npc->ani_no = 1;
      }
      if ( npc->shock )
      {
        npc->act_no = 2;
        npc->ani_no = 0;
        npc->act_wait = 0;
      }
      if ( npc->act_wait > 7 && npc->x - 49152 < x && npc->x + 49152 > x && npc->y - 49152 < y && npc->y + 24576 > y )
      {
        npc->act_no = 2;
        npc->ani_no = 0;
        npc->act_wait = 0;
      }
      break;
    case 2:
      if ( ++npc->act_wait > 8 )
      {
        npc->act_no = 3;
        npc->ani_no = 2;
        npc->ym = -1228;
        PlaySoundObject(30, 1);
        if ( npc->x <= x )
          npc->direct = 2;
        else
          npc->direct = 0;
        if ( npc->direct )
          npc->xm = 256;
        else
          npc->xm = -256;
      }
      break;
    case 3:
      if ( npc->ym > 256 )
      {
        npc->tgt_y = npc->y;
        npc->act_no = 4;
        npc->ani_no = 3;
        npc->act_wait = 0;
        npc->act_wait = 0;
      }
      break;
    case 4:
      if ( npc->x >= x )
        npc->direct = 0;
      else
        npc->direct = 2;
      ++npc->act_wait;
      if ( npc->flag & 7 || npc->act_wait > 100 )
      {
        npc->damage = 3;
        npc->act_no = 5;
        npc->ani_no = 2;
        npc->xm /= 2;
      }
      else
      {
        if ( npc->act_wait % 4 == 1 )
          PlaySoundObject(109, 1);
        if ( npc->flag & 8 )
          npc->ym = -512;
        if ( ++npc->ani_wait > 0 )
        {
          npc->ani_wait = 0;
          ++npc->ani_no;
        }
        if ( npc->ani_no > 5 )
          npc->ani_no = 3;
      }
      break;
    case 5:
      if ( npc->flag & 8 )
      {
        npc->damage = 2;
        npc->xm = 0;
        npc->act_wait = 0;
        npc->ani_no = 0;
        npc->act_no = 1;
        PlaySoundObject(23, 1);
      }
      break;
    default:
      break;
  }
  if ( npc->act_no == 4 )
  {
    if ( npc->x >= x )
      v1 = npc->xm - 32;
    else
      v1 = npc->xm + 32;
    npc->xm = v1;
    if ( npc->y <= npc->tgt_y )
      v2 = npc->ym + 16;
    else
      v2 = npc->ym - 16;
    npc->ym = v2;
    if ( npc->ym > 512 )
      npc->ym = 512;
    if ( npc->ym < -512 )
      npc->ym = -512;
    if ( npc->xm > 512 )
      npc->xm = 512;
    if ( npc->xm < -512 )
      npc->xm = -512;
  }
  else
  {
    npc->ym += 64;
    if ( npc->ym > 1535 )
      npc->ym = 1535;
  }
  npc->x += npc->xm;
  npc->y += npc->ym;
  if ( npc->direct )
  {
    v3 = npc;
    v4 = (Sint32 *)&v7[16 * npc->ani_no - 192];
  }
  else
  {
    v3 = npc;
    v4 = (Sint32 *)&v7[16 * npc->ani_no - 96];
  }
  npc->rect.left = *v4;
  v3->rect.top = v4[1];
  v3->rect.right = v4[2];
  v3->rect.bottom = v4[3];
}


void __cdecl ActNpc029(NPCHAR_0 *npc)
{
  int v1;
  NPCHAR_0 *v2;
  RECT *v3;
  RECT rcRight[2];
  RECT rcLeft[2];

  rcLeft[0].left = 0;
  rcLeft[0].top = 192;
  rcLeft[0].right = 16;
  rcLeft[0].bottom = 216;
  rcLeft[1].left = 16;
  rcLeft[1].top = 192;
  rcLeft[1].right = 32;
  rcLeft[1].bottom = 216;
  rcRight[0].left = 0;
  rcRight[0].top = 216;
  rcRight[0].right = 16;
  rcRight[0].bottom = 240;
  rcRight[1].left = 16;
  rcRight[1].top = 216;
  rcRight[1].right = 32;
  rcRight[1].bottom = 240;
  v1 = npc->act_no;
  if ( v1 )
  {
    if ( v1 != 1 )
      goto LABEL_11;
  }
  else
  {
    npc->act_no = 1;
    npc->ani_no = 0;
    npc->ani_wait = 0;
  }
  npc->ani_no = npc->x - 24576 < x && npc->x + 24576 > x && npc->y - 24576 < y && npc->y + 0x2000 > y;
LABEL_11:
  if ( npc->direct )
  {
    v2 = npc;
    v3 = &rcRight[npc->ani_no];
  }
  else
  {
    v2 = npc;
    v3 = &rcLeft[npc->ani_no];
  }
  npc->rect.left = v3->left;
  v2->rect.top = v3->top;
  v2->rect.right = v3->right;
  v2->rect.bottom = v3->bottom;
}

void __cdecl ActNpc030(NPCHAR_0 *npc)
{
  int v1;
  Sint32 *v2;
  RECT rc[3];
  char v4[8];

  rc[0].left = 48;
  rc[0].top = 0;
  rc[0].right = 64;
  rc[0].bottom = 16;
  rc[1].left = 48;
  rc[1].top = 16;
  rc[1].right = 64;
  rc[1].bottom = 32;
  rc[2].left = 0;
  rc[2].top = 32;
  rc[2].right = 16;
  rc[2].bottom = 48;
  if ( npc->direct )
  {
    if ( !npc->act_no )
    {
      npc->act_no = 1;
      npc->y += 0x2000;
      npc->ani_no = 2;
    }
    if ( ++npc->act_wait > 100 )
    {
      npc->act_wait = 0;
      SetCaret(npc->x, npc->y - 1024, 5, 0);
    }
  }
  else
  {
    v1 = npc->act_no;
    if ( v1 == 1 )
    {
LABEL_6:
      if ( Random(0, 120) == 10 )
      {
        npc->act_no = 2;
        npc->act_wait = 0;
        npc->ani_no = 1;
      }
      goto LABEL_14;
    }
    if ( v1 != 2 )
    {
      if ( v1 )
        goto LABEL_14;
      npc->act_no = 1;
      npc->ani_no = 0;
      npc->ani_wait = 0;
      goto LABEL_6;
    }
    if ( ++npc->act_wait > 8 )
    {
      npc->act_no = 1;
      npc->ani_no = 0;
    }
  }
LABEL_14:
  v2 = (Sint32 *)&v4[16 * npc->ani_no - 48];
  npc->rect.left = *v2;
  npc->rect.top = v2[1];
  npc->rect.right = v2[2];
  npc->rect.bottom = v2[3];
}


void __cdecl ActNpc031(NPCHAR_0 *npc)
{
  NPCHAR_0 *v1;
  Sint32 *v2;
  RECT rcRight[5];
  RECT rcLeft[5];
  char v5[24];

  qmemcpy(rcLeft, &ActNpc031(NPCHAR *)::C.6, sizeof(rcLeft));
  qmemcpy(rcRight, &ActNpc031(NPCHAR *)::C.7, sizeof(rcRight));
  switch ( npc->act_no )
  {
    case 0:
      npc->act_no = 1;
      goto LABEL_3;
    case 1:
LABEL_3:
      if ( Random(0, 120) == 10 )
      {
        npc->act_no = 2;
        npc->act_wait = 0;
        npc->ani_no = 1;
      }
      if ( npc->x - 4096 < x && npc->x + 4096 > x && npc->y - 4096 < y && npc->y + 49152 > y )
      {
        npc->ani_no = 0;
        npc->act_no = 3;
      }
      break;
    case 2:
      if ( ++npc->act_wait > 8 )
      {
        npc->act_no = 1;
        npc->ani_no = 0;
      }
      break;
    case 3:
      npc->ani_no = 0;
      if ( npc->shock || npc->x - 10240 > x || npc->x + 10240 < x )
      {
        npc->ani_no = 1;
        npc->ani_wait = 0;
        npc->act_no = 4;
        npc->act_wait = 0;
      }
      break;
    case 4:
      npc->ym += 32;
      if ( npc->ym > 1535 )
        npc->ym = 1535;
      if ( (++npc->act_wait > 19 || npc->flag & 8) && (npc->flag & 8 || npc->y > y - 0x2000) )
      {
        npc->ani_wait = 0;
        npc->ani_no = 2;
        npc->act_no = 5;
        npc->tgt_y = npc->y;
        if ( npc->flag & 8 )
          npc->ym = -512;
      }
      break;
    case 5:
      if ( ++npc->ani_wait > 1 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 4 )
        npc->ani_no = 2;
      if ( x >= npc->x )
        npc->direct = 2;
      else
        npc->direct = 0;
      if ( x < npc->x )
        npc->xm -= 16;
      if ( x > npc->x )
        npc->xm += 16;
      if ( npc->tgt_y < npc->y )
        npc->ym -= 16;
      if ( npc->tgt_y > npc->y )
        npc->ym += 16;
      if ( npc->xm > 512 )
        npc->xm = 512;
      if ( npc->xm < -512 )
        npc->xm = -512;
      if ( npc->ym > 512 )
        npc->ym = 512;
      if ( npc->ym < -512 )
        npc->ym = -512;
      if ( npc->flag & 8 )
        npc->ym = -512;
      if ( npc->flag & 2 )
        npc->ym = 512;
      break;
    default:
      break;
  }
  npc->x += npc->xm;
  npc->y += npc->ym;
  if ( npc->direct )
  {
    v1 = npc;
    v2 = (Sint32 *)&v5[16 * npc->ani_no - 160];
  }
  else
  {
    v1 = npc;
    v2 = (Sint32 *)&v5[16 * npc->ani_no - 80];
  }
  npc->rect.left = *v2;
  v1->rect.top = v2[1];
  v1->rect.right = v2[2];
  v1->rect.bottom = v2[3];
}


void __cdecl ActNpc032(NPCHAR_0 *npc)
{
  RECT *v1;
  RECT rect[2];

  rect[0].left = 32;
  rect[0].top = 96;
  rect[0].right = 48;
  rect[0].bottom = 112;
  rect[1].left = 48;
  rect[1].top = 96;
  rect[1].right = 64;
  rect[1].bottom = 112;
  if ( ++npc->ani_wait > 2 )
  {
    npc->ani_wait = 0;
    ++npc->ani_no;
  }
  if ( npc->ani_no > 1 )
    npc->ani_no = 0;
  v1 = &rect[npc->ani_no];
  npc->rect.left = v1->left;
  npc->rect.top = v1->top;
  npc->rect.right = v1->right;
  npc->rect.bottom = v1->bottom;
}

void __cdecl ActNpc033(NPCHAR_0 *npc)
{
  Sint32 *v1;
  RECT rect_left[2];
  char v3[8];

  if ( npc->flag & 5 )
  {
    SetCaret(npc->x, npc->y, 2, 0);
    npc->cond = 0;
  }
  else if ( npc->flag & 8 )
  {
    npc->ym = -1024;
  }
  npc->ym += 42;
  npc->y += npc->ym;
  npc->x += npc->xm;
  rect_left[0].left = 240;
  rect_left[0].top = 64;
  rect_left[0].right = 256;
  rect_left[0].bottom = 80;
  rect_left[1].left = 240;
  rect_left[1].top = 80;
  rect_left[1].right = 256;
  rect_left[1].bottom = 96;
  if ( ++npc->ani_wait > 2 )
  {
    npc->ani_wait = 0;
    if ( ++npc->ani_no > 1 )
      npc->ani_no = 0;
  }
  v1 = (Sint32 *)&v3[16 * npc->ani_no - 32];
  npc->rect.left = *v1;
  npc->rect.top = v1[1];
  npc->rect.right = v1[2];
  npc->rect.bottom = v1[3];
  if ( ++npc->act_wait > 250 )
  {
    SetCaret(npc->x, npc->y, 2, 0);
    npc->cond = 0;
  }
}


void __cdecl ActNpc034(NPCHAR_0 *npc)
{
  if ( npc->direct )
  {
    npc->rect.left = 192;
    npc->rect.top = 184;
    npc->rect.right = 224;
    npc->rect.bottom = 200;
  }
  else
  {
    npc->rect.left = 192;
    npc->rect.top = 48;
    npc->rect.right = 224;
    npc->rect.bottom = 64;
  }
}

void __cdecl ActNpc035(NPCHAR_0 *npc)
{
  int v1;
  NPCHAR_0 *v2;
  Sint32 *v3;
  RECT rcRight[4];
  RECT rcLeft[4];
  char v6[8];

  if ( npc->act_no <= 2 && npc->life <= 89 )
  {
    PlaySoundObject(71, 1);
    SetDestroyNpChar(npc->x, npc->y, npc->view.back, 8);
    SetExpObjects(npc->x, npc->y, npc->exp);
    npc->act_no = 3;
    npc->act_wait = 0;
    npc->ani_no = 2;
    npc->bits &= 0xFFDFu;
    npc->damage = 0;
  }
  v1 = npc->act_no;
  if ( v1 == 2 )
  {
    if ( ++npc->act_wait > 20 )
    {
      npc->act_wait = 0;
      npc->act_no = 1;
      npc->ani_no = 0;
    }
  }
  else if ( v1 > 2 )
  {
    if ( v1 == 3 )
    {
      if ( ++npc->act_wait == 50 || npc->act_wait == 60 )
        npc->ani_no = 3;
      if ( npc->act_wait == 53 || npc->act_wait == 63 )
        npc->ani_no = 2;
      if ( npc->act_wait > 100 )
        npc->act_no = 4;
    }
  }
  else if ( v1 >= 0 && npc->shock )
  {
    if ( npc->direct )
      SetNpChar(103, npc->x + 4096, npc->y + 4096, 0, 0, npc->direct, 0, 256);
    else
      SetNpChar(103, npc->x - 4096, npc->y + 4096, 0, 0, npc->direct, 0, 256);
    npc->ani_no = 1;
    npc->act_no = 2;
    npc->act_wait = 0;
  }
  rcLeft[0].left = 96;
  rcLeft[0].top = 64;
  rcLeft[0].right = 120;
  rcLeft[0].bottom = 96;
  rcLeft[1].left = 120;
  rcLeft[1].top = 64;
  rcLeft[1].right = 144;
  rcLeft[1].bottom = 96;
  rcLeft[2].left = 144;
  rcLeft[2].top = 64;
  rcLeft[2].right = 168;
  rcLeft[2].bottom = 96;
  rcLeft[3].left = 168;
  rcLeft[3].top = 64;
  rcLeft[3].right = 192;
  rcLeft[3].bottom = 96;
  rcRight[0].left = 96;
  rcRight[0].top = 96;
  rcRight[0].right = 120;
  rcRight[0].bottom = 128;
  rcRight[1].left = 120;
  rcRight[1].top = 96;
  rcRight[1].right = 144;
  rcRight[1].bottom = 128;
  rcRight[2].left = 144;
  rcRight[2].top = 96;
  rcRight[2].right = 168;
  rcRight[2].bottom = 128;
  rcRight[3].left = 168;
  rcRight[3].top = 96;
  rcRight[3].right = 192;
  rcRight[3].bottom = 128;
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


void __cdecl ActNpc036(NPCHAR_0 *npc)
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
  int v10;
  int v11;
  int v12;
  int v13;
  NPCHAR_0 *v14;
  Sint32 *v15;
  RECT rect_right[6];
  RECT rect_left[6];
  int i;
  unsigned __int8 deg;
  int xm;
  int ym;
  char v22[24];

  switch ( npc->act_no )
  {
    case 0:
      npc->act_no = 1;
      goto LABEL_3;
    case 1:
LABEL_3:
      if ( ++npc->act_wait > 12 )
      {
        npc->act_no = 2;
        npc->act_wait = 0;
        npc->count1 = 3;
        npc->ani_no = 1;
      }
      break;
    case 2:
      if ( ++npc->act_wait > 16 )
      {
        --npc->count1;
        npc->act_wait = 0;
        deg = GetArktan(npc->x - x, npc->y + 2048 - y);
        deg += Random(-16, 16);
        ym = GetSin(deg);
        xm = GetCos(deg);
        SetNpChar(11, npc->x, npc->y + 2048, xm, ym, 0, 0, 256);
        PlaySoundObject(39, 1);
        if ( !npc->count1 )
        {
          npc->act_no = 3;
          npc->act_wait = 0;
        }
      }
      break;
    case 3:
      if ( ++npc->act_wait > 3 )
      {
        npc->act_no = 4;
        npc->act_wait = 0;
        npc->xm = (x - npc->x) / 100;
        npc->ym = -1536;
        npc->ani_no = 3;
      }
      break;
    case 4:
      if ( npc->ym >= -511 )
      {
        if ( npc->life <= 60 )
        {
          npc->act_no = 6;
        }
        else
        {
          npc->act_no = 5;
          npc->ani_no = 4;
          npc->ani_wait = 0;
          npc->act_wait = 0;
          npc->tgt_y = npc->y;
        }
      }
      break;
    case 5:
      if ( ++npc->ani_wait > 1 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 5 )
      {
        npc->ani_no = 4;
        PlaySoundObject(47, 1);
      }
      if ( ++npc->act_wait > 100 )
      {
        npc->act_no = 6;
        npc->ani_no = 3;
      }
      if ( npc->y >= npc->tgt_y )
        v1 = npc->ym - 64;
      else
        v1 = npc->ym + 64;
      npc->ym = v1;
      if ( npc->ym < -512 )
        npc->ym = -512;
      if ( npc->ym > 512 )
        npc->ym = 512;
      break;
    case 6:
      if ( npc->y + 0x2000 >= y )
        npc->damage = 0;
      else
        npc->damage = 10;
      if ( npc->flag & 8 )
      {
        npc->act_no = 7;
        npc->act_wait = 0;
        npc->ani_no = 2;
        PlaySoundObject(26, 1);
        PlaySoundObject(25, 1);
        SetQuake(30);
        npc->damage = 0;
        for ( i = 0; i <= 7; ++i )
        {
          v2 = Random(-1536, 0);
          v3 = Random(-341, 341);
          v4 = npc->y;
          v5 = (Random(-12, 12) << 9) + v4;
          v6 = npc->x;
          v7 = Random(-12, 12);
          SetNpChar(4, v6 + (v7 << 9), v5, v3, v2, 0, 0, 256);
        }
        for ( i = 0; i <= 7; ++i )
        {
          v8 = Random(-1024, 0);
          v9 = Random(-1024, 1024);
          v10 = npc->y;
          v11 = (Random(-12, 12) << 9) + v10;
          v12 = npc->x;
          v13 = Random(-12, 12);
          SetNpChar(33, v12 + (v13 << 9), v11, v9, v8, 0, 0, 256);
        }
      }
      break;
    case 7:
      npc->xm = 0;
      if ( ++npc->act_wait > 3 )
      {
        npc->act_no = 1;
        npc->act_wait = 0;
      }
      break;
    default:
      break;
  }
  if ( npc->act_no != 5 )
  {
    npc->ym += 51;
    if ( npc->x >= x )
      npc->direct = 0;
    else
      npc->direct = 2;
  }
  if ( npc->ym > 1535 )
    npc->ym = 1535;
  npc->x += npc->xm;
  npc->y += npc->ym;
  qmemcpy(rect_left, &ActNpc036(NPCHAR *)::C.12, sizeof(rect_left));
  qmemcpy(rect_right, &ActNpc036(NPCHAR *)::C.13, sizeof(rect_right));
  if ( npc->direct )
  {
    v14 = npc;
    v15 = (Sint32 *)&v22[16 * npc->ani_no - 208];
  }
  else
  {
    v14 = npc;
    v15 = (Sint32 *)&v22[16 * npc->ani_no - 112];
  }
  npc->rect.left = *v15;
  v14->rect.top = v15[1];
  v14->rect.right = v15[2];
  v14->rect.bottom = v15[3];
}


void __cdecl ActNpc037(NPCHAR_0 *npc)
{
  RECT *v1;
  RECT rect[2];

  rect[0].left = 192;
  rect[0].top = 64;
  rect[0].right = 208;
  rect[0].bottom = 80;
  rect[1].left = 208;
  rect[1].top = 64;
  rect[1].right = 224;
  rect[1].bottom = 80;
  if ( ++npc->ani_wait > 1 )
  {
    npc->ani_wait = 0;
    ++npc->ani_no;
  }
  if ( npc->ani_no > 1 )
    npc->ani_no = 0;
  v1 = &rect[npc->ani_no];
  npc->rect.left = v1->left;
  npc->rect.top = v1->top;
  npc->rect.right = v1->right;
  npc->rect.bottom = v1->bottom;
}

void __cdecl ActNpc038(NPCHAR_0 *npc)
{
  int v1;
  Sint32 *v2;
  RECT rect[4];
  char v4[8];

  rect[0].left = 128;
  rect[0].top = 64;
  rect[0].right = 144;
  rect[0].bottom = 80;
  rect[1].left = 144;
  rect[1].top = 64;
  rect[1].right = 160;
  rect[1].bottom = 80;
  rect[2].left = 160;
  rect[2].top = 64;
  rect[2].right = 176;
  rect[2].bottom = 80;
  rect[3].left = 176;
  rect[3].top = 64;
  rect[3].right = 192;
  rect[3].bottom = 80;
  v1 = npc->act_no;
  if ( v1 )
  {
    if ( v1 < 0 )
      return;
    if ( v1 == 10 )
    {
      npc->act_no = 11;
      SetDestroyNpChar(npc->x, npc->y, npc->view.back, 8);
    }
    else if ( v1 != 11 )
    {
      return;
    }
    npc->rect.left = 0;
    npc->rect.right = 0;
    return;
  }
  if ( ++npc->ani_wait > 3 )
  {
    npc->ani_wait = 0;
    ++npc->ani_no;
  }
  if ( npc->ani_no > 3 )
    npc->ani_no = 0;
  v2 = (Sint32 *)&v4[16 * npc->ani_no - 64];
  npc->rect.left = *v2;
  npc->rect.top = v2[1];
  npc->rect.right = v2[2];
  npc->rect.bottom = v2[3];
}


void __cdecl ActNpc039(NPCHAR_0 *npc)
{
  RECT *v1;
  RECT rect[2];

  rect[0].left = 224;
  rect[0].top = 64;
  rect[0].right = 240;
  rect[0].bottom = 80;
  rect[1].left = 240;
  rect[1].top = 64;
  rect[1].right = 256;
  rect[1].bottom = 80;
  if ( npc->direct )
    npc->ani_no = 1;
  else
    npc->ani_no = 0;
  v1 = &rect[npc->ani_no];
  npc->rect.left = v1->left;
  npc->rect.top = v1->top;
  npc->rect.right = v1->right;
  npc->rect.bottom = v1->bottom;
}

