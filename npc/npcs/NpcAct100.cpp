#include "types.h"
#include "SDL_stdinc.h"
#include "windows_wrapper.h"
#include "Tags.h"
#include "forNpc.h"

void __cdecl ActNpc100(NPCHAR_0 *npc);
void __cdecl ActNpc101(NPCHAR_0 *npc);
void __cdecl ActNpc102(NPCHAR_0 *npc);
void __cdecl ActNpc103(NPCHAR_0 *npc);
void __cdecl ActNpc104(NPCHAR_0 *npc);
void __cdecl ActNpc105(NPCHAR_0 *npc);
void __cdecl ActNpc106(NPCHAR_0 *npc);
void __cdecl ActNpc107(NPCHAR_0 *npc);
void __cdecl ActNpc108(NPCHAR_0 *npc);
void __cdecl ActNpc109(NPCHAR_0 *npc);
void __cdecl ActNpc110(NPCHAR_0 *npc);
void __cdecl ActNpc111(NPCHAR_0 *npc);
void __cdecl ActNpc112(NPCHAR_0 *npc);
void __cdecl ActNpc113(NPCHAR_0 *npc);
void __cdecl ActNpc114(NPCHAR_0 *npc);
void __cdecl ActNpc115(NPCHAR_0 *npc);
void __cdecl ActNpc116(NPCHAR_0 *npc);
void __cdecl ActNpc117(NPCHAR_0 *npc);
void __cdecl ActNpc118(NPCHAR_0 *npc);
void __cdecl ActNpc119(NPCHAR_0 *npc);

_UNKNOWN ActNpc118(NPCHAR *)::C.17;
_UNKNOWN ActNpc118(NPCHAR *)::C.18;
_UNKNOWN ActNpc117(NPCHAR *)::C.13;
_UNKNOWN ActNpc117(NPCHAR *)::C.14;
_UNKNOWN ActNpc115(NPCHAR *)::C.11;
_UNKNOWN ActNpc115(NPCHAR *)::C.12;
_UNKNOWN ActNpc113(NPCHAR *)::C.8;
_UNKNOWN ActNpc113(NPCHAR *)::C.9;
_UNKNOWN ActNpc107(NPCHAR *)::C.3;

void __cdecl ActNpc100(NPCHAR_0 *npc)
{
  if ( !npc->act_no )
  {
    npc->y += 0x2000;
    npc->act_no = 1;
  }
  npc->rect.left = 272;
  npc->rect.top = 48;
  npc->rect.right = 288;
  npc->rect.bottom = 64;
}

void __cdecl ActNpc101(NPCHAR_0 *npc)
{
  RECT *v1;
  RECT rect[3];

  rect[0].left = 240;
  rect[0].top = 136;
  rect[0].right = 256;
  rect[0].bottom = 152;
  rect[1].left = 240;
  rect[1].top = 136;
  rect[1].right = 256;
  rect[1].bottom = 152;
  rect[2].left = 256;
  rect[2].top = 136;
  rect[2].right = 272;
  rect[2].bottom = 152;
  if ( ++npc->ani_wait > 3 )
  {
    npc->ani_wait = 0;
    ++npc->ani_no;
  }
  if ( npc->ani_no > 2 )
    npc->ani_no = 0;
  v1 = &rect[npc->ani_no];
  npc->rect.left = v1->left;
  npc->rect.top = v1->top;
  npc->rect.right = v1->right;
  npc->rect.bottom = v1->bottom;
}

void __cdecl ActNpc102(NPCHAR_0 *npc)
{
  RECT *v1;
  RECT rect[4];

  rect[0].left = 208;
  rect[0].top = 120;
  rect[0].right = 224;
  rect[0].bottom = 136;
  rect[1].left = 224;
  rect[1].top = 120;
  rect[1].right = 240;
  rect[1].bottom = 136;
  rect[2].left = 240;
  rect[2].top = 120;
  rect[2].right = 256;
  rect[2].bottom = 136;
  rect[3].left = 256;
  rect[3].top = 120;
  rect[3].right = 272;
  rect[3].bottom = 136;
  if ( !npc->act_no )
  {
    npc->act_no = 1;
    npc->y += 4096;
  }
  if ( ++npc->ani_wait > 0 )
  {
    npc->ani_wait = 0;
    ++npc->ani_no;
  }
  if ( npc->ani_no > 3 )
    npc->ani_no = 0;
  v1 = &rect[npc->ani_no];
  npc->rect.left = v1->left;
  npc->rect.top = v1->top;
  npc->rect.right = v1->right;
  npc->rect.bottom = v1->bottom;
}

void __cdecl ActNpc103(NPCHAR_0 *npc)
{
  int v1;
  int v2;
  NPCHAR_0 *v3;
  Sint32 *v4;
  RECT rcRight[3];
  RECT rcLeft[3];
  char v7[8];

  rcLeft[0].left = 192;
  rcLeft[0].top = 96;
  rcLeft[0].right = 208;
  rcLeft[0].bottom = 120;
  rcLeft[1].left = 208;
  rcLeft[1].top = 96;
  rcLeft[1].right = 224;
  rcLeft[1].bottom = 120;
  rcLeft[2].left = 224;
  rcLeft[2].top = 96;
  rcLeft[2].right = 240;
  rcLeft[2].bottom = 120;
  rcRight[0].left = 192;
  rcRight[0].top = 120;
  rcRight[0].right = 208;
  rcRight[0].bottom = 144;
  rcRight[1].left = 208;
  rcRight[1].top = 120;
  rcRight[1].right = 224;
  rcRight[1].bottom = 144;
  rcRight[2].left = 224;
  rcRight[2].top = 120;
  rcRight[2].right = 240;
  rcRight[2].bottom = 144;
  v1 = npc->act_no;
  if ( v1 )
  {
    if ( v1 != 1 )
      goto LABEL_12;
  }
  else
  {
    npc->act_no = 1;
  }
  if ( npc->direct )
    v2 = npc->xm + 32;
  else
    v2 = npc->xm - 32;
  npc->xm = v2;
  if ( ++npc->ani_wait > 0 )
  {
    npc->ani_wait = 0;
    ++npc->ani_no;
  }
  if ( npc->ani_no > 2 )
    npc->ani_no = 0;
LABEL_12:
  npc->x += npc->xm;
  if ( npc->direct )
  {
    v3 = npc;
    v4 = (Sint32 *)&v7[16 * npc->ani_no - 96];
  }
  else
  {
    v3 = npc;
    v4 = (Sint32 *)&v7[16 * npc->ani_no - 48];
  }
  npc->rect.left = *v4;
  v3->rect.top = v4[1];
  v3->rect.right = v4[2];
  v3->rect.bottom = v4[3];
  if ( ++npc->count1 > 100 )
    npc->cond = 0;
  if ( npc->count1 % 4 == 1 )
    PlaySoundObject(46, 1);
}


void __cdecl ActNpc104(NPCHAR_0 *npc)
{
  NPCHAR_0 *v1;
  Sint32 *v2;
  RECT rcRight[3];
  RECT rcLeft[3];
  bool bJump;
  char v6[8];

  rcLeft[0].left = 0;
  rcLeft[0].top = 112;
  rcLeft[0].right = 32;
  rcLeft[0].bottom = 144;
  rcLeft[1].left = 32;
  rcLeft[1].top = 112;
  rcLeft[1].right = 64;
  rcLeft[1].bottom = 144;
  rcLeft[2].left = 64;
  rcLeft[2].top = 112;
  rcLeft[2].right = 96;
  rcLeft[2].bottom = 144;
  rcRight[0].left = 0;
  rcRight[0].top = 144;
  rcRight[0].right = 32;
  rcRight[0].bottom = 176;
  rcRight[1].left = 32;
  rcRight[1].top = 144;
  rcRight[1].right = 64;
  rcRight[1].bottom = 176;
  rcRight[2].left = 64;
  rcRight[2].top = 144;
  rcRight[2].right = 96;
  rcRight[2].bottom = 176;
  switch ( npc->act_no )
  {
    case 0:
      npc->act_no = 1;
      npc->act_wait = 0;
      npc->xm = 0;
      npc->ym = 0;
      if ( npc->direct != 4 )
      {
        npc->bits &= 0xFFF7u;
        goto LABEL_8;
      }
      if ( Random(0, 1) != 0 )
        npc->direct = 0;
      else
        npc->direct = 2;
      npc->bits |= 8u;
      npc->ani_no = 2;
      npc->act_no = 3;
      break;
    case 1:
LABEL_8:
      ++npc->act_wait;
      if ( Random(0, 50) == 1 )
      {
        npc->act_no = 2;
        npc->act_wait = 0;
        npc->ani_no = 0;
        npc->ani_wait = 0;
      }
      break;
    case 2:
      ++npc->act_wait;
      if ( ++npc->ani_wait > 2 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 1 )
        npc->ani_no = 0;
      if ( npc->act_wait > 18 )
      {
        npc->act_no = 1;
        npc->act_no = 1;
      }
      break;
    case 3:
      if ( ++npc->act_wait > 40 )
        npc->bits &= 0xFFF7u;
      if ( npc->flag & 8 )
      {
        npc->act_no = 0;
        npc->ani_no = 0;
        npc->act_wait = 0;
      }
      break;
    case 0xA:
      npc->act_no = 11;
      goto LABEL_21;
    case 0xB:
LABEL_21:
      if ( npc->flag & 1 && npc->xm < 0 )
      {
        npc->xm = -npc->xm;
        npc->direct = 2;
      }
      if ( npc->flag & 4 && npc->xm > 0 )
      {
        npc->xm = -npc->xm;
        npc->direct = 0;
      }
      if ( npc->flag & 8 )
      {
        npc->act_no = 0;
        npc->ani_no = 0;
        npc->act_wait = 0;
      }
      break;
    default:
      break;
  }
  bJump = 0;
  if ( npc->act_no <= 9 && npc->act_no != 3 && npc->act_wait > 10 )
  {
    if ( npc->shock )
      bJump = 1;
    if ( npc->x >= x - 81920
      && npc->x <= x + 81920
      && npc->y >= y - 0x8000
      && npc->y <= y + 0x8000
      && Random(0, 50) == 2 )
    {
      bJump = 1;
    }
  }
  if ( bJump )
  {
    if ( npc->x >= x )
      npc->direct = 0;
    else
      npc->direct = 2;
    npc->act_no = 10;
    npc->ani_no = 2;
    npc->ym = -1535;
    if ( !(gMC.cond & 2) )
      PlaySoundObject(30, 1);
    if ( npc->direct )
      npc->xm = 512;
    else
      npc->xm = -512;
  }
  npc->ym += 128;
  if ( npc->ym > 1535 )
    npc->ym = 1535;
  npc->x += npc->xm;
  npc->y += npc->ym;
  if ( npc->direct )
  {
    v1 = npc;
    v2 = (Sint32 *)&v6[16 * npc->ani_no - 100];
  }
  else
  {
    v1 = npc;
    v2 = (Sint32 *)&v6[16 * npc->ani_no - 52];
  }
  npc->rect.left = *v2;
  v1->rect.top = v2[1];
  v1->rect.right = v2[2];
  v1->rect.bottom = v2[3];
}


void __cdecl ActNpc105(NPCHAR_0 *npc)
{
  RECT *v1;
  RECT rect[2];

  rect[0].left = 128;
  rect[0].top = 32;
  rect[0].right = 144;
  rect[0].bottom = 48;
  rect[1].left = 128;
  rect[1].top = 32;
  rect[1].right = 128;
  rect[1].bottom = 32;
  if ( ++npc->act_wait > 30 )
    npc->cond = 0;
  if ( npc->act_wait <= 4 )
    npc->y -= 512;
  v1 = &rect[npc->ani_no];
  npc->rect.left = v1->left;
  npc->rect.top = v1->top;
  npc->rect.right = v1->right;
  npc->rect.bottom = v1->bottom;
}

void __cdecl ActNpc106(NPCHAR_0 *npc)
{
  if ( !npc->act_no )
  {
    SetNpChar(105, npc->x, npc->y - 4096, 0, 0, 0, 0, 384);
    npc->act_no = 1;
  }
}

void __cdecl ActNpc107(NPCHAR_0 *npc)
{
  int v1;
  int v2;
  int v3;
  int v4;
  int v5;
  int v6;
  Sint32 *v7;
  RECT rcPoweron[10];
  int i;
  char v10[24];

  switch ( npc->act_no )
  {
    case 0:
      npc->act_no = 1;
      if ( npc->direct == 2 )
        npc->ani_no = 5;
      break;
    case 0xA:
      npc->act_no = 11;
      npc->act_wait = 0;
      npc->ani_wait = 0;
      for ( i = 0; i <= 3; ++i )
      {
        v1 = Random(-1536, 0);
        v2 = Random(-341, 341);
        SetNpChar(4, npc->x, npc->y, v2, v1, 0, 0, 256);
      }
      goto LABEL_7;
    case 0xB:
LABEL_7:
      if ( ++npc->ani_wait > 1 )
      {
        PlaySoundObject(43, 1);
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 1 )
        npc->ani_no = 0;
      if ( ++npc->act_wait > 100 )
        npc->act_no = 12;
      break;
    case 0xC:
      npc->act_no = 13;
      npc->act_wait = 0;
      npc->ani_no = 1;
      goto LABEL_14;
    case 0xD:
LABEL_14:
      if ( ++npc->act_wait > 50 )
        npc->act_no = 14;
      break;
    case 0xE:
      npc->act_no = 15;
      npc->act_wait = 0;
      goto LABEL_17;
    case 0xF:
LABEL_17:
      if ( npc->act_wait / 2 & 1 )
      {
        npc->x += 512;
        PlaySoundObject(11, 1);
      }
      else
      {
        npc->x -= 512;
      }
      if ( ++npc->act_wait > 50 )
        npc->act_no = 16;
      break;
    case 0x10:
      npc->act_no = 17;
      npc->act_wait = 0;
      npc->ani_no = 2;
      PlaySoundObject(12, 1);
      for ( i = 0; i <= 7; ++i )
      {
        v3 = Random(-1536, 0);
        v4 = Random(-341, 341);
        SetNpChar(4, npc->x, npc->y, v4, v3, 0, 0, 256);
      }
      goto LABEL_25;
    case 0x11:
LABEL_25:
      if ( ++npc->act_wait > 150 )
        npc->act_no = 18;
      break;
    case 0x12:
      npc->act_no = 19;
      npc->act_wait = 0;
      npc->ani_no = 3;
      npc->ani_wait = 0;
      goto LABEL_28;
    case 0x13:
LABEL_28:
      if ( ++npc->ani_wait > 3 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 4 )
      {
        PlaySoundObject(11, 1);
        npc->ani_no = 3;
      }
      if ( ++npc->act_wait > 100 )
      {
        npc->act_no = 20;
        PlaySoundObject(12, 1);
        for ( i = 0; i <= 3; ++i )
        {
          v5 = Random(-1536, 0);
          v6 = Random(-341, 341);
          SetNpChar(4, npc->x, npc->y, v6, v5, 0, 0, 256);
        }
      }
      break;
    case 0x14:
      npc->ani_no = 4;
      break;
    case 0x15:
      npc->act_no = 22;
      npc->ani_no = 5;
      PlaySoundObject(51, 1);
      break;
    case 0x64:
      npc->act_no = 101;
      npc->ani_no = 6;
      npc->ani_wait = 0;
      goto LABEL_40;
    case 0x65:
LABEL_40:
      if ( ++npc->ani_wait > 4 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 9 )
        npc->ani_no = 6;
      break;
    case 0x6E:
      SetDestroyNpChar(npc->x, npc->y, 0x2000, 16);
      npc->cond = 0;
      break;
    default:
      break;
  }
  qmemcpy(rcPoweron, &ActNpc107(NPCHAR *)::C.3, sizeof(rcPoweron));
  v7 = (Sint32 *)&v10[16 * npc->ani_no - 164];
  npc->rect.left = *v7;
  npc->rect.top = v7[1];
  npc->rect.right = v7[2];
  npc->rect.bottom = v7[3];
}


void __cdecl ActNpc108(NPCHAR_0 *npc)
{
  Sint32 *v1;
  RECT rect_left[3];
  char v3[8];

  if ( npc->flag & 0xFF )
  {
    SetCaret(npc->x, npc->y, 2, 0);
    npc->cond = 0;
  }
  npc->y += npc->ym;
  npc->x += npc->xm;
  rect_left[0].left = 96;
  rect_left[0].top = 48;
  rect_left[0].right = 112;
  rect_left[0].bottom = 64;
  rect_left[1].left = 112;
  rect_left[1].top = 48;
  rect_left[1].right = 128;
  rect_left[1].bottom = 64;
  rect_left[2].left = 128;
  rect_left[2].top = 48;
  rect_left[2].right = 144;
  rect_left[2].bottom = 64;
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
    SetCaret(npc->x, npc->y, 2, 0);
    npc->cond = 0;
  }
}


void __cdecl ActNpc109(NPCHAR_0 *npc)
{
  int v1;
  int v2;
  int v3;
  NPCHAR_0 *v4;
  Sint32 *v5;
  RECT rcRight[2];
  RECT rcLeft[2];
  int i;
  char v9[8];

  rcLeft[0].left = 240;
  rcLeft[0].top = 0;
  rcLeft[0].right = 256;
  rcLeft[0].bottom = 24;
  rcLeft[1].left = 256;
  rcLeft[1].top = 0;
  rcLeft[1].right = 272;
  rcLeft[1].bottom = 24;
  rcRight[0].left = 240;
  rcRight[0].top = 24;
  rcRight[0].right = 256;
  rcRight[0].bottom = 48;
  rcRight[1].left = 256;
  rcRight[1].top = 24;
  rcRight[1].right = 272;
  rcRight[1].bottom = 48;
  v1 = npc->act_no;
  if ( v1 == 1 )
  {
LABEL_11:
    if ( Random(0, 120) == 10 )
    {
      npc->act_no = 2;
      npc->act_wait = 0;
      npc->ani_no = 1;
    }
    if ( npc->x - 0x4000 < x && npc->x + 0x4000 > x && npc->y - 0x4000 < y && npc->y + 0x2000 > y )
    {
      if ( npc->x <= x )
        npc->direct = 2;
      else
        npc->direct = 0;
    }
    goto LABEL_25;
  }
  if ( v1 <= 1 )
  {
    if ( v1 )
      goto LABEL_25;
    if ( --npc->act_wait )
      npc->act_no = 1;
    npc->ani_no = 0;
    npc->ani_wait = 0;
    goto LABEL_11;
  }
  if ( v1 == 2 )
  {
    if ( ++npc->act_wait > 8 )
    {
      npc->act_no = 1;
      npc->ani_no = 0;
    }
  }
  else if ( v1 == 10 )
  {
    npc->act_no = 0;
    PlaySoundObject(12, 1);
    for ( i = 0; i <= 7; ++i )
    {
      v2 = Random(-1536, 0);
      v3 = Random(-341, 341);
      SetNpChar(4, npc->x, npc->y, v3, v2, 0, 0, 256);
    }
  }
LABEL_25:
  npc->ym += 64;
  if ( npc->ym > 1535 )
    npc->ym = 1535;
  npc->y += npc->ym;
  if ( npc->direct )
  {
    v4 = npc;
    v5 = (Sint32 *)&v9[16 * npc->ani_no - 68];
  }
  else
  {
    v4 = npc;
    v5 = (Sint32 *)&v9[16 * npc->ani_no - 36];
  }
  npc->rect.left = *v5;
  v4->rect.top = v5[1];
  v4->rect.right = v5[2];
  v4->rect.bottom = v5[3];
}


void __cdecl ActNpc110(NPCHAR_0 *npc)
{
  NPCHAR_0 *v1;
  Sint32 *v2;
  RECT rcRight[3];
  RECT rcLeft[3];
  bool bJump;
  char v6[8];

  rcLeft[0].left = 96;
  rcLeft[0].top = 128;
  rcLeft[0].right = 112;
  rcLeft[0].bottom = 144;
  rcLeft[1].left = 112;
  rcLeft[1].top = 128;
  rcLeft[1].right = 128;
  rcLeft[1].bottom = 144;
  rcLeft[2].left = 128;
  rcLeft[2].top = 128;
  rcLeft[2].right = 144;
  rcLeft[2].bottom = 144;
  rcRight[0].left = 96;
  rcRight[0].top = 144;
  rcRight[0].right = 112;
  rcRight[0].bottom = 160;
  rcRight[1].left = 112;
  rcRight[1].top = 144;
  rcRight[1].right = 128;
  rcRight[1].bottom = 160;
  rcRight[2].left = 128;
  rcRight[2].top = 144;
  rcRight[2].right = 144;
  rcRight[2].bottom = 160;
  switch ( npc->act_no )
  {
    case 0:
      npc->act_no = 1;
      npc->act_wait = 0;
      npc->xm = 0;
      npc->ym = 0;
      if ( npc->direct != 4 )
      {
        npc->bits &= 0xFFF7u;
        goto LABEL_8;
      }
      if ( Random(0, 1) != 0 )
        npc->direct = 0;
      else
        npc->direct = 2;
      npc->bits |= 8u;
      npc->ani_no = 2;
      npc->act_no = 3;
      break;
    case 1:
LABEL_8:
      ++npc->act_wait;
      if ( Random(0, 50) == 1 )
      {
        npc->act_no = 2;
        npc->act_wait = 0;
        npc->ani_no = 0;
        npc->ani_wait = 0;
      }
      break;
    case 2:
      ++npc->act_wait;
      if ( ++npc->ani_wait > 2 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 1 )
        npc->ani_no = 0;
      if ( npc->act_wait > 18 )
      {
        npc->act_no = 1;
        npc->act_no = 1;
      }
      break;
    case 3:
      if ( ++npc->act_wait > 40 )
        npc->bits &= 0xFFF7u;
      if ( npc->flag & 8 )
      {
        npc->act_no = 0;
        npc->ani_no = 0;
        npc->act_wait = 0;
      }
      break;
    case 0xA:
      npc->act_no = 11;
      goto LABEL_21;
    case 0xB:
LABEL_21:
      if ( npc->flag & 1 && npc->xm < 0 )
      {
        npc->xm = -npc->xm;
        npc->direct = 2;
      }
      if ( npc->flag & 4 && npc->xm > 0 )
      {
        npc->xm = -npc->xm;
        npc->direct = 0;
      }
      if ( npc->flag & 8 )
      {
        npc->act_no = 0;
        npc->ani_no = 0;
        npc->act_wait = 0;
      }
      break;
    default:
      break;
  }
  bJump = 0;
  if ( npc->act_no <= 9 && npc->act_no != 3 && npc->act_wait > 10 )
  {
    if ( npc->shock )
      bJump = 1;
    if ( npc->x >= x - 81920
      && npc->x <= x + 81920
      && npc->y >= y - 0x8000
      && npc->y <= y + 0x8000
      && Random(0, 50) == 2 )
    {
      bJump = 1;
    }
  }
  if ( bJump )
  {
    if ( npc->x >= x )
      npc->direct = 0;
    else
      npc->direct = 2;
    npc->act_no = 10;
    npc->ani_no = 2;
    npc->ym = -767;
    PlaySoundObject(6, 1);
    if ( npc->direct )
      npc->xm = 256;
    else
      npc->xm = -256;
  }
  npc->ym += 128;
  if ( npc->ym > 1535 )
    npc->ym = 1535;
  npc->x += npc->xm;
  npc->y += npc->ym;
  if ( npc->direct )
  {
    v1 = npc;
    v2 = (Sint32 *)&v6[16 * npc->ani_no - 100];
  }
  else
  {
    v1 = npc;
    v2 = (Sint32 *)&v6[16 * npc->ani_no - 52];
  }
  npc->rect.left = *v2;
  v1->rect.top = v2[1];
  v1->rect.right = v2[2];
  v1->rect.bottom = v2[3];
}


void __cdecl ActNpc111(NPCHAR_0 *npc)
{
  NPCHAR_0 *v1;
  Sint32 *v2;
  RECT rcRight[2];
  RECT rcLeft[2];
  char v5[8];

  rcLeft[0].left = 0;
  rcLeft[0].top = 0;
  rcLeft[0].right = 16;
  rcLeft[0].bottom = 16;
  rcLeft[1].left = 16;
  rcLeft[1].top = 0;
  rcLeft[1].right = 32;
  rcLeft[1].bottom = 16;
  rcRight[0].left = 0;
  rcRight[0].top = 16;
  rcRight[0].right = 16;
  rcRight[0].bottom = 32;
  rcRight[1].left = 16;
  rcRight[1].top = 16;
  rcRight[1].right = 32;
  rcRight[1].bottom = 32;
  switch ( npc->act_no )
  {
    case 0:
      npc->act_no = 1;
      npc->ani_no = 0;
      npc->y -= 0x2000;
      break;
    case 1:
      if ( ++npc->act_wait > 20 )
      {
        npc->act_wait = 0;
        npc->act_no = 2;
        npc->ani_no = 1;
        npc->ym = -767;
      }
      break;
    case 2:
      if ( npc->ym > 0 )
        npc->hit.bottom = 0x2000;
      if ( npc->flag & 8 )
      {
        npc->act_no = 3;
        npc->act_wait = 0;
        npc->ani_no = 0;
      }
      break;
    case 3:
      if ( ++npc->act_wait > 40 )
      {
        npc->act_no = 4;
        npc->act_wait = 64;
        PlaySoundObject(29, 1);
      }
      break;
    case 4:
      --npc->act_wait;
      npc->ani_no = 0;
      if ( !npc->act_wait )
        npc->cond = 0;
      break;
    default:
      break;
  }
  npc->ym += 64;
  npc->y += npc->ym;
  if ( npc->direct )
  {
    v1 = npc;
    v2 = (Sint32 *)&v5[16 * npc->ani_no - 64];
  }
  else
  {
    v1 = npc;
    v2 = (Sint32 *)&v5[16 * npc->ani_no - 32];
  }
  npc->rect.left = *v2;
  v1->rect.top = v2[1];
  v1->rect.right = v2[2];
  v1->rect.bottom = v2[3];
  if ( unk_81C8598 & 0x40 )
  {
    npc->rect.top += 32;
    npc->rect.bottom += 32;
  }
  if ( npc->act_no == 4 )
  {
    npc->rect.bottom = npc->act_wait / 4 + npc->rect.top;
    if ( npc->act_wait / 2 & 1 )
      ++npc->rect.left;
  }
}


void __cdecl ActNpc112(NPCHAR_0 *npc)
{
  int v1;
  NPCHAR_0 *v2;
  Sint32 *v3;
  RECT rcRight[2];
  RECT rcLeft[2];
  char v6[8];

  rcLeft[0].left = 0;
  rcLeft[0].top = 0;
  rcLeft[0].right = 16;
  rcLeft[0].bottom = 16;
  rcLeft[1].left = 16;
  rcLeft[1].top = 0;
  rcLeft[1].right = 32;
  rcLeft[1].bottom = 16;
  rcRight[0].left = 0;
  rcRight[0].top = 16;
  rcRight[0].right = 16;
  rcRight[0].bottom = 32;
  rcRight[1].left = 16;
  rcRight[1].top = 16;
  rcRight[1].right = 32;
  rcRight[1].bottom = 32;
  v1 = npc->act_no;
  if ( v1 == 1 )
  {
LABEL_9:
    if ( ++npc->act_wait == 64 )
    {
      npc->act_no = 2;
      npc->act_wait = 0;
    }
    goto LABEL_15;
  }
  if ( v1 <= 1 )
  {
    if ( v1 )
      goto LABEL_15;
    npc->act_no = 1;
    npc->ani_no = 0;
    npc->ani_wait = 0;
    npc->x += 0x2000;
    npc->y += 4096;
    PlaySoundObject(29, 1);
    goto LABEL_9;
  }
  if ( v1 == 2 )
  {
    if ( ++npc->act_wait > 20 )
    {
      npc->act_no = 3;
      npc->ani_no = 1;
      npc->hit.bottom = 4096;
    }
  }
  else if ( v1 == 3 && npc->flag & 8 )
  {
    npc->act_no = 4;
    npc->act_wait = 0;
    npc->ani_no = 0;
  }
LABEL_15:
  npc->ym += 64;
  npc->y += npc->ym;
  if ( npc->direct )
  {
    v2 = npc;
    v3 = (Sint32 *)&v6[16 * npc->ani_no - 64];
  }
  else
  {
    v2 = npc;
    v3 = (Sint32 *)&v6[16 * npc->ani_no - 32];
  }
  npc->rect.left = *v3;
  v2->rect.top = v3[1];
  v2->rect.right = v3[2];
  v2->rect.bottom = v3[3];
  if ( unk_81C8598 & 0x40 )
  {
    npc->rect.top += 32;
    npc->rect.bottom += 32;
  }
  if ( npc->act_no == 1 )
  {
    npc->rect.bottom = npc->act_wait / 4 + npc->rect.top;
    if ( npc->act_wait / 2 & 1 )
      ++npc->rect.left;
  }
}


void __cdecl ActNpc113(NPCHAR_0 *npc)
{
  int v1;
  NPCHAR_0 *v2;
  Sint32 *v3;
  RECT rcRight[7];
  RECT rcLeft[7];
  char v6[24];

  qmemcpy(rcLeft, &ActNpc113(NPCHAR *)::C.8, sizeof(rcLeft));
  qmemcpy(rcRight, &ActNpc113(NPCHAR *)::C.9, sizeof(rcRight));
  switch ( npc->act_no )
  {
    case 0:
      npc->act_no = 1;
      npc->ani_no = 0;
      npc->ani_wait = 0;
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
    case 3:
      npc->act_no = 4;
      npc->ani_no = 2;
      npc->ani_wait = 0;
      goto LABEL_8;
    case 4:
LABEL_8:
      if ( ++npc->ani_wait > 4 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 5 )
        npc->ani_no = 2;
      if ( npc->direct )
        v1 = npc->x + 512;
      else
        v1 = npc->x - 512;
      npc->x = v1;
      break;
    case 5:
      npc->ani_no = 6;
      break;
    case 0x1E:
      npc->act_no = 31;
      npc->ani_no = 0;
      npc->ani_wait = 0;
      npc->hit.bottom = 0x2000;
      npc->x -= 0x2000;
      npc->y += 4096;
      PlaySoundObject(29, 1);
      goto LABEL_18;
    case 0x1F:
LABEL_18:
      if ( ++npc->act_wait == 64 )
      {
        npc->act_no = 32;
        npc->act_wait = 0;
      }
      break;
    case 0x20:
      if ( ++npc->act_wait > 20 )
      {
        npc->act_no = 33;
        npc->ani_no = 1;
        npc->hit.bottom = 4096;
      }
      break;
    case 0x21:
      if ( npc->flag & 8 )
      {
        npc->act_no = 34;
        npc->act_wait = 0;
        npc->ani_no = 0;
      }
      break;
    default:
      break;
  }
  npc->ym += 64;
  npc->y += npc->ym;
  if ( npc->direct )
  {
    v2 = npc;
    v3 = (Sint32 *)&v6[16 * npc->ani_no - 224];
  }
  else
  {
    v2 = npc;
    v3 = (Sint32 *)&v6[16 * npc->ani_no - 112];
  }
  npc->rect.left = *v3;
  v2->rect.top = v3[1];
  v2->rect.right = v3[2];
  v2->rect.bottom = v3[3];
  if ( npc->act_no == 31 )
  {
    npc->rect.bottom = npc->act_wait / 4 + npc->rect.top;
    if ( npc->act_wait / 2 & 1 )
      ++npc->rect.left;
  }
}


void __cdecl ActNpc114(NPCHAR_0 *npc)
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
LABEL_5:
    if ( !(npc->flag & 8) )
    {
      npc->act_no = 10;
      npc->ani_wait = 0;
      npc->ani_no = 1;
    }
    goto LABEL_21;
  }
  if ( v1 != 10 )
  {
    if ( v1 )
      goto LABEL_21;
    npc->act_no = 1;
    npc->y -= 2048;
    goto LABEL_5;
  }
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
    npc->act_no = 1;
    npc->ani_no = 0;
    npc->damage = 0;
    npc->bits |= 0x40u;
  }
LABEL_21:
  npc->ym += 32;
  if ( npc->ym > 1535 )
    npc->ym = 1535;
  npc->y += npc->ym;
  v4 = (Sint32 *)&v7[16 * npc->ani_no - 52];
  npc->rect.left = *v4;
  npc->rect.top = v4[1];
  npc->rect.right = v4[2];
  npc->rect.bottom = v4[3];
}


void __cdecl ActNpc115(NPCHAR_0 *npc)
{
  int v1;
  int v2;
  int v3;
  int v4;
  int v5;
  int v6;
  int v7;
  NPCHAR_0 *v8;
  Sint32 *v9;
  RECT rcRight[6];
  RECT rcLeft[6];
  int i;
  char v13[24];

  qmemcpy(rcLeft, &ActNpc115(NPCHAR *)::C.11, sizeof(rcLeft));
  qmemcpy(rcRight, &ActNpc115(NPCHAR *)::C.12, sizeof(rcRight));
  switch ( npc->act_no )
  {
    case 0:
      npc->xm = 0;
      npc->act_no = 1;
      npc->act_wait = 0;
      npc->count1 = 0;
      goto LABEL_3;
    case 1:
LABEL_3:
      if ( x < npc->x + 49152 && x > npc->x - 49152 && y < npc->y + 0x4000 && y > npc->y - 49152 )
        npc->act_no = 10;
      if ( npc->shock )
        npc->act_no = 10;
      break;
    case 0xA:
      if ( x >= npc->x )
        npc->direct = 2;
      else
        npc->direct = 0;
      npc->ani_no = 1;
      if ( ++npc->act_wait > 20 )
      {
        npc->act_wait = 0;
        npc->act_no = 20;
      }
      break;
    case 0x14:
      npc->damage = 0;
      npc->xm = 0;
      if ( ++npc->ani_wait > 2 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 2 )
      {
        if ( npc->x <= x )
          npc->direct = 2;
        else
          npc->direct = 0;
        if ( npc->direct )
          npc->xm = 512;
        else
          npc->xm = -512;
        if ( ++npc->count1 <= 2 )
        {
          npc->act_no = 21;
          npc->ym = -1024;
          PlaySoundObject(30, 1);
        }
        else
        {
          npc->count1 = 0;
          npc->ani_no = 4;
          npc->act_no = 21;
          npc->ym = -1024;
          npc->xm *= 2;
          npc->damage = 5;
          PlaySoundObject(102, 1);
        }
      }
      break;
    case 0x15:
      if ( npc->flag & 8 )
      {
        PlaySoundObject(23, 1);
        npc->act_no = 20;
        npc->ani_no = 1;
        npc->ani_wait = 0;
        npc->damage = 0;
        if ( x > npc->x + 73728 || x < npc->x - 73728 || y > npc->y + 24576 || y < npc->y - 73728 )
          npc->act_no = 0;
      }
      break;
    case 0x1E:
      for ( i = 0; i <= 7; ++i )
      {
        v1 = Random(-1536, 0);
        v2 = Random(-341, 341);
        v3 = npc->y;
        v4 = (Random(-12, 12) << 9) + v3;
        v5 = npc->x;
        v6 = Random(-12, 12);
        SetNpChar(4, v5 + (v6 << 9), v4, v2, v1, 0, 0, 256);
      }
      npc->ani_no = 0;
      npc->act_no = 0;
      break;
    case 0x32:
      npc->act_no = 51;
      npc->ani_no = 4;
      npc->damage = 0;
      npc->ym = -512;
      npc->bits &= 0xFFDEu;
      PlaySoundObject(51, 1);
      goto LABEL_38;
    case 0x33:
LABEL_38:
      if ( npc->flag & 8 )
      {
        PlaySoundObject(23, 1);
        npc->act_no = 52;
        npc->ani_no = 5;
        npc->xm = 0;
      }
      break;
    default:
      break;
  }
  if ( npc->act_no <= 50 )
    v7 = npc->ym + 64;
  else
    v7 = npc->ym + 32;
  npc->ym = v7;
  if ( npc->ym > 1535 )
    npc->ym = 1535;
  npc->x += npc->xm;
  npc->y += npc->ym;
  if ( npc->direct )
  {
    v8 = npc;
    v9 = (Sint32 *)&v13[16 * npc->ani_no - 196];
  }
  else
  {
    v8 = npc;
    v9 = (Sint32 *)&v13[16 * npc->ani_no - 100];
  }
  npc->rect.left = *v9;
  v8->rect.top = v9[1];
  v8->rect.right = v9[2];
  v8->rect.bottom = v9[3];
}


void __cdecl ActNpc116(NPCHAR_0 *npc)
{
  npc->rect.left = 272;
  npc->rect.top = 184;
  npc->rect.right = 320;
  npc->rect.bottom = 200;
}

void __cdecl ActNpc117(NPCHAR_0 *npc)
{
  int v1;
  int v2;
  int v3;
  bool v4;
  int v5;
  NPCHAR_0 *v6;
  Sint32 *v7;
  RECT rcRight[10];
  RECT rcLeft[10];
  char v10[24];

  qmemcpy(rcLeft, &ActNpc117(NPCHAR *)::C.13, sizeof(rcLeft));
  qmemcpy(rcRight, &ActNpc117(NPCHAR *)::C.14, sizeof(rcRight));
  switch ( npc->act_no )
  {
    case 0:
      if ( npc->direct == 4 )
      {
        if ( npc->x <= x )
          npc->direct = 2;
        else
          npc->direct = 0;
      }
      npc->act_no = 1;
      npc->ani_no = 0;
      npc->ani_wait = 0;
      goto LABEL_7;
    case 1:
LABEL_7:
      npc->xm = 0;
      npc->ym += 64;
      if ( npc->x - 0x4000 < x && npc->x + 0x4000 > x )
        v1 = npc->y - 0x4000;
      break;
    case 3:
      npc->act_no = 4;
      npc->ani_no = 1;
      npc->ani_wait = 0;
      goto LABEL_11;
    case 4:
LABEL_11:
      if ( ++npc->ani_wait > 4 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 4 )
        npc->ani_no = 1;
      npc->ym += 64;
      if ( npc->direct )
        npc->xm = 512;
      else
        npc->xm = -512;
      break;
    case 5:
      npc->act_no = 6;
      npc->ani_no = 5;
      SetDestroyNpChar(npc->x, npc->y, npc->view.back, 8);
      break;
    case 6:
      npc->ani_no = 5;
      break;
    case 0xA:
      npc->act_no = 11;
      npc->ani_no = 1;
      npc->ani_wait = 0;
      if ( npc->x <= x )
        npc->direct = 2;
      else
        npc->direct = 0;
      goto LABEL_23;
    case 0xB:
LABEL_23:
      if ( ++npc->ani_wait > 4 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 4 )
        npc->ani_no = 1;
      if ( npc->direct )
        v2 = npc->x + 512;
      else
        v2 = npc->x - 512;
      npc->x = v2;
      if ( x < npc->x + 10240 && x > npc->x - 10240 )
        npc->act_no = 0;
      break;
    case 0x14:
      npc->xm = 0;
      npc->ani_no = 6;
      break;
    case 0x15:
      npc->xm = 0;
      npc->ani_no = 9;
      break;
    case 0x1E:
      npc->act_no = 31;
      npc->act_wait = 0;
      npc->ym = -1024;
      goto LABEL_36;
    case 0x1F:
LABEL_36:
      npc->ani_no = 7;
      if ( npc->direct )
        npc->xm = -512;
      else
        npc->xm = 512;
      npc->ym += 64;
      v3 = npc->act_wait;
      npc->act_wait = v3 + 1;
      v4 = v3 != 0 && npc->flag & 8;
      if ( v4 )
        npc->act_no = 32;
      break;
    case 0x20:
      npc->ym += 64;
      npc->ani_no = 8;
      npc->xm = 0;
      break;
    case 0x46:
      npc->act_no = 71;
      npc->act_wait = 0;
      npc->ani_no = 1;
      npc->ani_wait = 0;
      goto LABEL_47;
    case 0x47:
LABEL_47:
      if ( npc->direct )
        v5 = npc->x - 256;
      else
        v5 = npc->x + 256;
      npc->x = v5;
      if ( ++npc->ani_wait > 8 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 4 )
        npc->ani_no = 1;
      break;
    default:
      break;
  }
  if ( npc->ym > 1535 )
    npc->ym = 1535;
  npc->x += npc->xm;
  npc->y += npc->ym;
  if ( npc->direct )
  {
    v6 = npc;
    v7 = (Sint32 *)&v10[16 * npc->ani_no - 320];
  }
  else
  {
    v6 = npc;
    v7 = (Sint32 *)&v10[16 * npc->ani_no - 160];
  }
  npc->rect.left = *v7;
  v6->rect.top = v7[1];
  v6->rect.right = v7[2];
  v6->rect.bottom = v7[3];
}


void __cdecl ActNpc118(NPCHAR_0 *npc)
{
  int v1;
  bool v2;
  NPCHAR_0 *v3;
  Sint32 *v4;
  RECT rcRight[9];
  RECT rcLeft[9];
  bool bUpper;
  char v8[24];

  qmemcpy(rcLeft, &ActNpc118(NPCHAR *)::C.17, sizeof(rcLeft));
  qmemcpy(rcRight, &ActNpc118(NPCHAR *)::C.18, sizeof(rcRight));
  bUpper = 0;
  if ( !npc->direct && npc->x < x )
    bUpper = 1;
  if ( npc->direct == 2 && npc->x > x )
    bUpper = 1;
  switch ( npc->act_no )
  {
    case 0:
      npc->act_no = 1;
      npc->ani_no = 0;
      npc->ani_wait = 0;
      break;
    case 0xA:
      npc->act_no = 11;
      npc->act_wait = Random(50, 100);
      npc->ani_no = 0;
      if ( npc->x <= x )
        npc->direct = 2;
      else
        npc->direct = 0;
      npc->bits |= 0x20u;
      npc->bits &= 0xFFFBu;
      goto LABEL_13;
    case 0xB:
LABEL_13:
      if ( npc->act_wait )
        --npc->act_wait;
      else
        npc->act_no = 13;
      break;
    case 0xD:
      npc->act_no = 14;
      npc->ani_no = 3;
      npc->act_wait = Random(50, 100);
      if ( npc->x <= x )
        npc->direct = 2;
      else
        npc->direct = 0;
      goto LABEL_19;
    case 0xE:
LABEL_19:
      if ( ++npc->ani_wait > 2 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 6 )
        npc->ani_no = 3;
      if ( npc->direct )
        v1 = npc->xm + 64;
      else
        v1 = npc->xm - 64;
      npc->xm = v1;
      if ( npc->act_wait )
      {
        --npc->act_wait;
      }
      else
      {
        npc->bits |= 0x20u;
        npc->act_no = 20;
        npc->act_wait = 0;
        PlaySoundObject(103, 1);
      }
      break;
    case 0x14:
      if ( npc->x <= x )
        npc->direct = 2;
      else
        npc->direct = 0;
      npc->xm = 8 * npc->xm / 9;
      if ( ++npc->ani_no > 1 )
        npc->ani_no = 0;
      if ( ++npc->act_wait > 50 )
      {
        npc->act_no = 21;
        npc->act_wait = 0;
      }
      break;
    case 0x15:
      if ( ++npc->act_wait % 4 == 1 )
      {
        if ( npc->direct )
        {
          if ( bUpper )
          {
            npc->ani_no = 2;
            SetNpChar(123, npc->x, npc->y - 4096, 0, 0, 1, 0, 256);
          }
          else
          {
            npc->ani_no = 0;
            SetNpChar(123, npc->x + 4096, npc->y + 2048, 0, 0, 2, 0, 256);
            npc->x -= 512;
          }
        }
        else if ( bUpper )
        {
          npc->ani_no = 2;
          SetNpChar(123, npc->x, npc->y - 4096, 0, 0, 1, 0, 256);
        }
        else
        {
          npc->ani_no = 0;
          SetNpChar(123, npc->x - 4096, npc->y + 2048, 0, 0, 0, 0, 256);
          npc->x += 512;
        }
      }
      if ( npc->act_wait > 30 )
        npc->act_no = 10;
      break;
    case 0x1E:
      if ( ++npc->ani_no > 8 )
        npc->ani_no = 7;
      if ( ++npc->act_wait > 30 )
      {
        npc->act_no = 10;
        npc->ani_no = 0;
      }
      break;
    default:
      break;
  }
  v2 = npc->act_no > 10 && npc->act_no <= 29 && CountArmsBullet(6);
  if ( v2 )
  {
    npc->act_wait = 0;
    npc->act_no = 30;
    npc->ani_no = 7;
    npc->bits &= 0xFFDFu;
    npc->bits |= 4u;
    npc->xm = 0;
  }
  npc->ym += 32;
  if ( npc->xm > 511 )
    npc->xm = 511;
  if ( npc->xm < -511 )
    npc->xm = -511;
  if ( npc->ym > 1535 )
    npc->ym = 1535;
  npc->y += npc->ym;
  npc->x += npc->xm;
  if ( npc->direct )
  {
    v3 = npc;
    v4 = (Sint32 *)&v8[16 * npc->ani_no - 292];
  }
  else
  {
    v3 = npc;
    v4 = (Sint32 *)&v8[16 * npc->ani_no - 148];
  }
  npc->rect.left = *v4;
  v3->rect.top = v4[1];
  v3->rect.right = v4[2];
  v3->rect.bottom = v4[3];
}


void __cdecl ActNpc119(NPCHAR_0 *npc)
{
  npc->rect.left = 248;
  npc->rect.top = 184;
  npc->rect.right = 272;
  npc->rect.bottom = 200;
}

