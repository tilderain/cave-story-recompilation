#include "types.h"
#include "SDL_stdinc.h"
#include "windows_wrapper.h"
#include "Tags.h"
#include "forNpc.h"

void __cdecl ActNpc140(NPCHAR_0 *npc);
void __cdecl ActNpc141(NPCHAR_0 *npc);
void __cdecl ActNpc142(NPCHAR_0 *npc);
void __cdecl ActNpc143(NPCHAR_0 *npc);
void __cdecl ActNpc144(NPCHAR_0 *npc);
void __cdecl ActNpc145(NPCHAR_0 *npc);
void __cdecl ActNpc146(NPCHAR_0 *npc);
void __cdecl ActNpc147(NPCHAR_0 *npc);
void __cdecl ActNpc148(NPCHAR_0 *npc);
void __cdecl ActNpc149(NPCHAR_0 *npc);
void __cdecl ActNpc150(NPCHAR_0 *npc);
void __cdecl ActNpc151(NPCHAR_0 *npc);
void __cdecl ActNpc152(NPCHAR_0 *npc);
void __cdecl ActNpc153(NPCHAR_0 *npc);
void __cdecl ActNpc154(NPCHAR_0 *npc);
void __cdecl ActNpc155(NPCHAR_0 *npc);
void __cdecl ActNpc156(NPCHAR_0 *npc);
void __cdecl ActNpc157(NPCHAR_0 *npc);
void __cdecl ActNpc158(NPCHAR_0 *npc);
void __cdecl ActNpc159(NPCHAR_0 *npc);

_UNKNOWN ActNpc158(NPCHAR *)::C.21;
_UNKNOWN ActNpc150(NPCHAR *)::C.14;
_UNKNOWN ActNpc150(NPCHAR *)::C.15;
_UNKNOWN ActNpc147(NPCHAR *)::C.11;
_UNKNOWN ActNpc147(NPCHAR *)::C.12;
_UNKNOWN ActNpc146(NPCHAR *)::C.10;
_UNKNOWN ActNpc144(NPCHAR *)::C.7;
_UNKNOWN ActNpc144(NPCHAR *)::C.8;
_UNKNOWN ActNpc142(NPCHAR *)::C.6;
_UNKNOWN ActNpc140(NPCHAR *)::C.0;
_UNKNOWN ActNpc140(NPCHAR *)::C.1;

RECT grcKitL[21] =
{
  { 0, 0, 24, 24 },
  { 24, 0, 48, 24 },
  { 48, 0, 72, 24 },
  { 0, 0, 24, 24 },
  { 72, 0, 96, 24 },
  { 0, 0, 24, 24 },
  { 96, 0, 120, 24 },
  { 120, 0, 144, 24 },
  { 144, 0, 168, 24 },
  { 168, 0, 192, 24 },
  { 192, 0, 216, 24 },
  { 216, 0, 240, 24 },
  { 240, 0, 264, 24 },
  { 264, 0, 288, 24 },
  { 0, 48, 24, 72 },
  { 24, 48, 48, 72 },
  { 48, 48, 72, 72 },
  { 72, 48, 96, 72 },
  { 288, 0, 312, 24 },
  { 24, 48, 48, 72 },
  { 96, 48, 120, 72 }
};
RECT grcKitR[21] =
{
  { 0, 24, 24, 48 },
  { 24, 24, 48, 48 },
  { 48, 24, 72, 48 },
  { 0, 24, 24, 48 },
  { 72, 24, 96, 48 },
  { 0, 24, 24, 48 },
  { 96, 24, 120, 48 },
  { 120, 24, 144, 48 },
  { 144, 24, 168, 48 },
  { 168, 24, 192, 48 },
  { 192, 24, 216, 48 },
  { 216, 24, 240, 48 },
  { 240, 24, 264, 48 },
  { 264, 24, 288, 48 },
  { 0, 72, 24, 96 },
  { 24, 72, 48, 96 },
  { 48, 72, 72, 96 },
  { 72, 72, 96, 96 },
  { 288, 24, 312, 48 },
  { 24, 72, 48, 96 },
  { 96, 72, 120, 96 }
};

void __cdecl ActNpc140(NPCHAR_0 *npc)
{
  unsigned __int16 v1;
  bool v2;
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
  NPCHAR_0 *v21;
  Sint32 *v22;
  RECT rcRight[14];
  RECT rcLeft[14];
  int i;
  char v26[24];

  qmemcpy(rcLeft, &ActNpc140(NPCHAR *)::C.0, sizeof(rcLeft));
  qmemcpy(rcRight, &ActNpc140(NPCHAR *)::C.1, sizeof(rcRight));
  switch ( npc->act_no )
  {
    case 0:
      npc->act_no = 1;
      npc->ani_no = 9;
      npc->act_wait = 0;
      v1 = npc->bits;
      HIBYTE(v1) &= 0xDFu;
      npc->bits = v1;
      goto LABEL_3;
    case 1:
LABEL_3:
      if ( ++npc->act_wait > 50 )
      {
        npc->act_no = 2;
        npc->act_wait = 0;
        npc->ani_no = 8;
      }
      break;
    case 2:
      if ( ++npc->ani_no > 10 )
        npc->ani_no = 9;
      if ( ++npc->act_wait > 50 )
      {
        npc->act_no = 3;
        npc->act_wait = 0;
        npc->ani_no = 0;
      }
      break;
    case 3:
      if ( ++npc->act_wait > 50 )
      {
        npc->act_no = 10;
        npc->bits |= 0x20u;
      }
      break;
    case 0xA:
      npc->bits = npc->bits;
      npc->act_no = 11;
      npc->ani_no = 0;
      npc->ani_wait = 0;
      npc->act_wait = Random(20, 130);
      npc->xm = 0;
      goto LABEL_12;
    case 0xB:
LABEL_12:
      if ( npc->x <= x )
        npc->direct = 2;
      else
        npc->direct = 0;
      if ( ++npc->ani_wait > 4 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 1 )
        npc->ani_no = 0;
      v2 = CountArmsBullet(6) || CountArmsBullet(3) > 3;
      if ( v2 )
        npc->act_no = 20;
      if ( npc->act_wait )
      {
        --npc->act_wait;
      }
      else if ( Random(0, 99) & 1 )
      {
        npc->act_no = 20;
      }
      else
      {
        npc->act_no = 50;
      }
      break;
    case 0x14:
      npc->act_no = 21;
      npc->ani_no = 2;
      npc->act_wait = 0;
      goto LABEL_31;
    case 0x15:
LABEL_31:
      if ( ++npc->act_wait > 10 )
      {
        npc->act_no = 22;
        npc->act_wait = 0;
        npc->ani_no = 3;
        npc->ym = -1535;
        if ( npc->direct )
          npc->xm = 512;
        else
          npc->xm = -512;
      }
      break;
    case 0x16:
      if ( ++npc->act_wait > 10 )
      {
        npc->act_no = 23;
        npc->act_wait = 0;
        npc->ani_no = 6;
        SetNpChar(141, 0, 0, 0, 0, 0, npc, 0);
      }
      break;
    case 0x17:
      if ( ++npc->act_wait > 30 )
      {
        npc->act_no = 24;
        npc->act_wait = 0;
        npc->ani_no = 7;
      }
      if ( npc->x <= x )
        npc->direct = 2;
      else
        npc->direct = 0;
      break;
    case 0x18:
      if ( ++npc->act_wait > 3 )
      {
        npc->act_no = 25;
        npc->ani_no = 3;
      }
      break;
    case 0x19:
      if ( npc->flag & 8 )
      {
        npc->act_no = 26;
        npc->act_wait = 0;
        npc->ani_no = 2;
        PlaySoundObject(26, 1);
        SetQuake(20);
      }
      break;
    case 0x1A:
      npc->xm = 8 * npc->xm / 9;
      if ( ++npc->act_wait > 20 )
      {
        npc->act_no = 10;
        npc->ani_no = 0;
      }
      break;
    case 0x32:
      npc->act_no = 51;
      npc->act_wait = 0;
      npc->ani_no = 4;
      SetNpChar(141, 0, 0, 0, 0, 0, npc, 0);
      goto LABEL_49;
    case 0x33:
LABEL_49:
      if ( ++npc->act_wait > 30 )
      {
        npc->act_no = 52;
        npc->act_wait = 0;
        npc->ani_no = 5;
      }
      if ( npc->x <= x )
        npc->direct = 2;
      else
        npc->direct = 0;
      break;
    case 0x34:
      if ( ++npc->act_wait > 3 )
      {
        npc->act_no = 10;
        npc->ani_no = 0;
      }
      break;
    case 0x64:
      npc->ani_no = 3;
      npc->act_no = 101;
      npc->bits &= 0xFFDFu;
      npc->damage = 0;
      for ( i = 0; i <= 7; ++i )
      {
        v3 = Random(-1536, 0);
        v4 = Random(-341, 341);
        v5 = npc->y;
        v6 = (Random(-12, 12) << 9) + v5;
        v7 = npc->x;
        v8 = Random(-12, 12);
        SetNpChar(4, v7 + (v8 << 9), v6, v4, v3, 0, 0, 256);
      }
      break;
    case 0x65:
      if ( npc->flag & 8 )
      {
        npc->act_no = 102;
        npc->act_wait = 0;
        npc->ani_no = 2;
        PlaySoundObject(26, 1);
        SetQuake(20);
      }
      break;
    case 0x66:
      npc->xm = 8 * npc->xm / 9;
      if ( ++npc->act_wait > 50 )
      {
        npc->act_no = 103;
        npc->act_wait = 0;
        npc->ani_no = 10;
      }
      break;
    case 0x67:
      if ( ++npc->act_wait > 50 )
      {
        npc->ani_no = 9;
        npc->act_no = 104;
        npc->act_wait = 0;
      }
      break;
    case 0x68:
      if ( ++npc->ani_no > 10 )
        npc->ani_no = 9;
      if ( ++npc->act_wait > 100 )
      {
        npc->act_wait = 0;
        npc->ani_no = 9;
        npc->act_no = 105;
      }
      break;
    case 0x69:
      if ( ++npc->act_wait > 50 )
      {
        npc->ani_wait = 0;
        npc->act_no = 106;
        npc->ani_no = 11;
      }
      break;
    case 0x6A:
      if ( ++npc->ani_wait > 50 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 12 )
        npc->ani_no = 12;
      break;
    case 0x8C:
      npc->act_no = 141;
      npc->act_wait = 0;
      npc->ani_no = 12;
      PlaySoundObject(29, 1);
      goto LABEL_77;
    case 0x8D:
LABEL_77:
      if ( ++npc->ani_no > 13 )
        npc->ani_no = 12;
      if ( ++npc->act_wait > 100 )
      {
        for ( i = 0; i <= 3; ++i )
        {
          v9 = Random(-1536, 0);
          v10 = Random(-341, 341);
          v11 = npc->y;
          v12 = (Random(-12, 12) << 9) + v11;
          v13 = npc->x;
          v14 = Random(-12, 12);
          SetNpChar(4, v13 + (v14 << 9), v12, v10, v9, 0, 0, 256);
        }
        npc->cond = 0;
      }
      break;
    default:
      break;
  }
  if ( npc->act_no > 100 && npc->act_no <= 104 && !(npc->act_wait % 9) )
  {
    v15 = Random(-1536, 0);
    v16 = Random(-341, 341);
    v17 = npc->y;
    v18 = (Random(-12, 12) << 9) + v17;
    v19 = npc->x;
    v20 = Random(-12, 12);
    SetNpChar(4, v19 + (v20 << 9), v18, v16, v15, 0, 0, 256);
  }
  npc->ym += 32;
  if ( npc->ym > 1535 )
    npc->ym = 1535;
  if ( npc->ym < -1535 )
    npc->ym = -1535;
  npc->x += npc->xm;
  npc->y += npc->ym;
  if ( npc->direct )
  {
    v21 = npc;
    v22 = (Sint32 *)&v26[16 * npc->ani_no - 452];
  }
  else
  {
    v21 = npc;
    v22 = (Sint32 *)&v26[16 * npc->ani_no - 228];
  }
  npc->rect.left = *v22;
  v21->rect.top = v22[1];
  v21->rect.right = v22[2];
  v21->rect.bottom = v22[3];
}


void __cdecl ActNpc141(NPCHAR_0 *npc)
{
  int v1;
  int v2;
  int v3;
  int v4;
  int v5;
  int v6;
  int v7;
  Sint32 *v8;
  RECT rect[2];
  int i;
  unsigned __int8 deg;
  char v12[8];

  rect[0].left = 288;
  rect[0].top = 32;
  rect[0].right = 304;
  rect[0].bottom = 48;
  rect[1].left = 304;
  rect[1].top = 32;
  rect[1].right = 320;
  rect[1].bottom = 48;
  v1 = npc->act_no;
  if ( v1 == 1 )
  {
LABEL_9:
    if ( npc->pNpc->direct )
      v2 = npc->pNpc->x - 5120;
    else
      v2 = npc->pNpc->x + 5120;
    npc->x = v2;
    npc->y = npc->pNpc->y - 4096;
    if ( npc->pNpc->act_no == 24 || npc->pNpc->act_no == 52 )
    {
      npc->act_no = 10;
      if ( npc->pNpc->direct )
        v3 = npc->pNpc->x + 0x2000;
      else
        v3 = npc->pNpc->x - 0x2000;
      npc->x = v3;
      npc->y = npc->pNpc->y;
      deg = GetArktan(npc->x - x, npc->y - y);
      npc->ym = 4 * GetSin(deg);
      npc->xm = 4 * GetCos(deg);
      PlaySoundObject(39, 1);
    }
    goto LABEL_29;
  }
  if ( v1 <= 1 )
  {
    if ( v1 )
      goto LABEL_29;
    npc->act_no = 1;
    npc->act_wait = 0;
    goto LABEL_9;
  }
  if ( v1 == 10 )
  {
    if ( npc->flag & 0xF )
    {
      npc->act_no = 20;
      npc->act_wait = 0;
      SetCaret(npc->x, npc->y, 2, 0);
      PlaySoundObject(12, 1);
      for ( i = 0; i <= 3; ++i )
      {
        v4 = Random(-512, 512);
        v5 = Random(-512, 512);
        SetNpChar(4, npc->x, npc->y, v5, v4, 0, 0, 256);
      }
    }
    else
    {
      npc->x += npc->xm;
      npc->y += npc->ym;
    }
  }
  else if ( v1 == 20 )
  {
    npc->x += npc->xm;
    npc->y += npc->ym;
    if ( ++npc->act_wait > 4 )
    {
      for ( i = 0; i <= 3; ++i )
      {
        v6 = Random(-512, 512);
        v7 = Random(-512, 512);
        SetNpChar(4, npc->x, npc->y, v7, v6, 0, 0, 256);
      }
      npc->code_char = 142;
      npc->ani_no = 0;
      npc->act_no = 20;
      npc->xm = 0;
      npc->bits &= 0xFFFBu;
      npc->bits |= 0x20u;
      npc->damage = 1;
    }
  }
LABEL_29:
  if ( ++npc->ani_no > 1 )
    npc->ani_no = 0;
  v8 = (Sint32 *)&v12[16 * npc->ani_no - 40];
  npc->rect.left = *v8;
  npc->rect.top = v8[1];
  npc->rect.right = v8[2];
  npc->rect.bottom = v8[3];
}


void __cdecl ActNpc142(NPCHAR_0 *npc)
{
  Sint32 *v1;
  RECT rect[5];
  char v3[24];

  qmemcpy(rect, &ActNpc142(NPCHAR *)::C.6, sizeof(rect));
  switch ( npc->act_no )
  {
    case 0xA:
      npc->act_no = 11;
      npc->ani_no = 0;
      npc->act_wait = 0;
      goto LABEL_3;
    case 0xB:
LABEL_3:
      if ( ++npc->act_wait > 30 )
      {
        npc->act_no = 12;
        npc->ani_no = 1;
        npc->ani_wait = 0;
      }
      break;
    case 0xC:
      if ( ++npc->ani_wait > 8 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no == 3 )
      {
        npc->act_no = 20;
        npc->ym = -512;
        if ( x >= npc->x )
          npc->xm = 512;
        else
          npc->xm = -512;
      }
      break;
    case 0x14:
      if ( npc->ym < -127 )
        npc->ani_no = 3;
      else
        npc->ani_no = 4;
      if ( npc->flag & 8 )
      {
        npc->ani_no = 2;
        npc->act_no = 21;
        npc->act_wait = 0;
        npc->xm = 0;
        PlaySoundObject(23, 1);
      }
      break;
    case 0x15:
      if ( ++npc->act_wait > 10 )
      {
        npc->act_no = 10;
        npc->ani_no = 0;
      }
      break;
    default:
      break;
  }
  npc->ym += 64;
  if ( npc->ym > 1535 )
    npc->ym = 1535;
  if ( npc->ym < -1535 )
    npc->ym = -1535;
  npc->x += npc->xm;
  npc->y += npc->ym;
  v1 = (Sint32 *)&v3[16 * npc->ani_no - 80];
  npc->rect.left = *v1;
  npc->rect.top = v1[1];
  npc->rect.right = v1[2];
  npc->rect.bottom = v1[3];
}


void __cdecl ActNpc143(NPCHAR_0 *npc)
{
  NPCHAR_0 *v1;
  RECT *v2;
  RECT rcRight[1];
  RECT rcLeft[1];

  rcLeft[0].left = 208;
  rcLeft[0].top = 32;
  rcLeft[0].right = 224;
  rcLeft[0].bottom = 48;
  rcRight[0].left = 208;
  rcRight[0].top = 48;
  rcRight[0].right = 224;
  rcRight[0].bottom = 64;
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

void __cdecl ActNpc144(NPCHAR_0 *npc)
{
  NPCHAR_0 *v1;
  Sint32 *v2;
  int v3;
  RECT rcRight[5];
  RECT rcLeft[5];
  char v6[24];

  qmemcpy(rcLeft, &ActNpc144(NPCHAR *)::C.7, sizeof(rcLeft));
  qmemcpy(rcRight, &ActNpc144(NPCHAR *)::C.8, sizeof(rcRight));
  switch ( npc->act_no )
  {
    case 0:
      npc->act_no = 1;
      npc->ani_no = 0;
      npc->ani_wait = 0;
      npc->tgt_x = npc->x;
      PlaySoundObject(29, 1);
      goto LABEL_3;
    case 1:
LABEL_3:
      if ( ++npc->act_wait == 64 )
      {
        npc->act_no = 2;
        npc->act_wait = 0;
      }
      break;
    case 2:
      if ( ++npc->ani_wait > 2 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 3 )
        npc->ani_no = 2;
      if ( npc->flag & 8 )
      {
        npc->act_no = 4;
        npc->act_wait = 0;
        npc->ani_no = 4;
        PlaySoundObject(23, 1);
      }
      break;
    case 0xA:
      npc->act_no = 11;
      npc->ani_no = 0;
      npc->ani_wait = 0;
      goto LABEL_12;
    case 0xB:
LABEL_12:
      if ( Random(0, 120) == 10 )
      {
        npc->act_no = 12;
        npc->act_wait = 0;
        npc->ani_no = 1;
      }
      break;
    case 0xC:
      if ( ++npc->act_wait > 8 )
      {
        npc->act_no = 11;
        npc->ani_no = 0;
      }
      break;
    default:
      break;
  }
  if ( npc->act_no > 1 )
  {
    npc->ym += 32;
    if ( npc->ym > 1535 )
      npc->ym = 1535;
    npc->y += npc->ym;
  }
  if ( npc->direct )
  {
    v1 = npc;
    v2 = (Sint32 *)&v6[16 * npc->ani_no - 160];
  }
  else
  {
    v1 = npc;
    v2 = (Sint32 *)&v6[16 * npc->ani_no - 80];
  }
  npc->rect.left = *v2;
  v1->rect.top = v2[1];
  v1->rect.right = v2[2];
  v1->rect.bottom = v2[3];
  if ( npc->act_no == 1 )
  {
    npc->rect.bottom = npc->act_wait / 4 + npc->rect.top;
    if ( npc->act_wait / 2 & 1 )
      v3 = npc->tgt_x;
    else
      v3 = npc->tgt_x + 512;
    npc->x = v3;
  }
}


void __cdecl ActNpc145(NPCHAR_0 *npc)
{
  int v1;
  NPCHAR_0 *v2;
  RECT *v3;
  RECT rcRight[1];
  RECT rcLeft[1];

  rcLeft[0].left = 96;
  rcLeft[0].top = 32;
  rcLeft[0].right = 112;
  rcLeft[0].bottom = 48;
  rcRight[0].left = 112;
  rcRight[0].top = 32;
  rcRight[0].right = 128;
  rcRight[0].bottom = 48;
  if ( !npc->act_no )
  {
    if ( npc->pNpc->count2 )
    {
      if ( npc->pNpc->direct )
        npc->direct = 0;
      else
        npc->direct = 2;
    }
    else if ( npc->pNpc->direct )
    {
      npc->direct = 2;
    }
    else
    {
      npc->direct = 0;
    }
    if ( npc->direct )
      v1 = npc->pNpc->x + 5120;
    else
      v1 = npc->pNpc->x - 5120;
    npc->x = v1;
    npc->y = npc->pNpc->y;
  }
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

void __cdecl ActNpc146(NPCHAR_0 *npc)
{
  int v1;
  Sint32 *v2;
  RECT rect[5];
  char v4[24];

  qmemcpy(rect, &ActNpc146(NPCHAR *)::C.10, sizeof(rect));
  v1 = npc->act_no;
  if ( v1 == 1 )
  {
LABEL_6:
    if ( ++npc->act_wait > 10 )
    {
      npc->act_no = 2;
      PlaySoundObject(101, 1);
    }
    goto LABEL_14;
  }
  if ( v1 != 2 )
  {
    if ( v1 )
      goto LABEL_14;
    npc->act_no = 1;
    if ( npc->direct == 2 )
      SetFlash(0, 0, 2);
    goto LABEL_6;
  }
  if ( ++npc->ani_wait > 2 )
  {
    npc->ani_wait = 0;
    ++npc->ani_no;
  }
  if ( npc->ani_no == 2 )
    npc->damage = 10;
  if ( npc->ani_no > 4 )
  {
    SetDestroyNpChar(npc->x, npc->y, 4096, 8);
    npc->cond = 0;
  }
LABEL_14:
  v2 = (Sint32 *)&v4[16 * npc->ani_no - 80];
  npc->rect.left = *v2;
  npc->rect.top = v2[1];
  npc->rect.right = v2[2];
  npc->rect.bottom = v2[3];
}


void __cdecl ActNpc147(NPCHAR_0 *npc)
{
  char v1;
  int v2;
  NPCHAR_0 *v3;
  Sint32 *v4;
  RECT rcRight[6];
  RECT rcLeft[6];
  int xm;
  int ym;
  unsigned __int8 deg;
  char v10[24];

  qmemcpy(rcLeft, &ActNpc147(NPCHAR *)::C.11, sizeof(rcLeft));
  qmemcpy(rcRight, &ActNpc147(NPCHAR *)::C.12, sizeof(rcRight));
  switch ( npc->act_no )
  {
    case 0:
      npc->y += 1536;
      npc->act_no = 1;
      goto LABEL_3;
    case 1:
LABEL_3:
      if ( npc->act_wait <= 7
        || npc->x - 49152 >= x
        || npc->x + 49152 <= x
        || npc->y - 49152 >= y
        || npc->y + 0x4000 <= y )
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
      if ( npc->act_wait > 7 && npc->x - 24576 < x && npc->x + 24576 > x && npc->y - 49152 < y && npc->y + 0x4000 > y )
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
        PlaySoundObject(30, 1);
        if ( npc->x <= x )
          npc->direct = 2;
        else
          npc->direct = 0;
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
      if ( npc->flag & 7 || npc->act_wait > 60 )
      {
        npc->damage = 3;
        npc->act_no = 5;
        npc->ani_no = 2;
      }
      else
      {
        if ( npc->act_wait % 4 == 1 )
          PlaySoundObject(109, 1);
        if ( npc->flag & 8 )
          npc->ym = -512;
        if ( npc->act_wait % 30 == 6 )
        {
          deg = GetArktan(npc->x - x, npc->y - y);
          v1 = Random(-6, 6);
          deg += v1;
          ym = 3 * GetSin(deg);
          xm = 3 * GetCos(deg);
          SetNpChar(148, npc->x, npc->y, xm, ym, 0, 0, 256);
          PlaySoundObject(39, 1);
        }
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


void __cdecl ActNpc148(NPCHAR_0 *npc)
{
  Sint32 *v1;
  RECT rect_left[2];
  char v3[8];

  if ( npc->flag & 0xFF )
  {
    SetCaret(npc->x, npc->y, 2, 0);
    npc->cond = 0;
  }
  npc->y += npc->ym;
  npc->x += npc->xm;
  rect_left[0].left = 96;
  rect_left[0].top = 96;
  rect_left[0].right = 104;
  rect_left[0].bottom = 104;
  rect_left[1].left = 104;
  rect_left[1].top = 96;
  rect_left[1].right = 112;
  rect_left[1].bottom = 104;
  if ( ++npc->ani_no > 1 )
    npc->ani_no = 0;
  v1 = (Sint32 *)&v3[16 * npc->ani_no - 32];
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


void __cdecl ActNpc149(NPCHAR_0 *npc)
{
  unsigned __int16 v1;
  int v2;
  int v3;
  int v4;
  int v5;
  unsigned __int16 v6;
  unsigned __int16 v7;
  unsigned __int16 v8;
  int v9;
  int v10;
  int v11;
  int v12;
  unsigned __int16 v13;
  unsigned __int16 v14;
  int i;
  int ia;

  switch ( npc->act_no )
  {
    case 0:
      npc->x += 4096;
      npc->y += 4096;
      if ( npc->direct )
        npc->act_no = 20;
      else
        npc->act_no = 10;
      npc->xm = 0;
      npc->ym = 0;
      npc->bits |= 0x40u;
      break;
    case 0xA:
      v1 = npc->bits;
      LOBYTE(v1) = v1 & 0x7F;
      npc->bits = v1;
      npc->damage = 0;
      if ( x < npc->x + 12800 && x > npc->x - 204800 && y < npc->y + 12800 && y > npc->y - 12800 )
      {
        npc->act_no = 11;
        npc->act_wait = 0;
      }
      break;
    case 0xB:
      if ( ++npc->act_wait % 10 == 6 )
        PlaySoundObject(107, 1);
      if ( npc->flag & 1 )
      {
        npc->xm = 0;
        npc->direct = 2;
        npc->act_no = 20;
        SetQuake(10);
        PlaySoundObject(26, 1);
        for ( i = 0; i <= 3; ++i )
        {
          v2 = Random(-1536, 0);
          v3 = Random(-341, 341);
          v4 = npc->y;
          v5 = Random(-12, 12);
          SetNpChar(4, npc->x - 0x2000, v4 + (v5 << 9), v3, v2, 0, 0, 256);
        }
      }
      else
      {
        if ( dword_81C8584 & 1 )
        {
          v6 = npc->bits;
          LOBYTE(v6) = v6 | 0x80;
          npc->bits = v6;
          npc->damage = 100;
        }
        else
        {
          v7 = npc->bits;
          LOBYTE(v7) = v7 & 0x7F;
          npc->bits = v7;
          npc->damage = 0;
        }
        npc->xm -= 32;
      }
      break;
    case 0x14:
      v8 = npc->bits;
      LOBYTE(v8) = v8 & 0x7F;
      npc->bits = v8;
      npc->damage = 0;
      if ( x > npc->x - 12800 && x < npc->x + 204800 && y < npc->y + 12800 && y > npc->y - 12800 )
      {
        npc->act_no = 21;
        npc->act_wait = 0;
      }
      break;
    case 0x15:
      if ( ++npc->act_wait % 10 == 6 )
        PlaySoundObject(107, 1);
      if ( npc->flag & 4 )
      {
        npc->xm = 0;
        npc->direct = 0;
        npc->act_no = 10;
        SetQuake(10);
        PlaySoundObject(26, 1);
        for ( ia = 0; ia <= 3; ++ia )
        {
          v9 = Random(-1536, 0);
          v10 = Random(-341, 341);
          v11 = npc->y;
          v12 = Random(-12, 12);
          SetNpChar(4, npc->x + 0x2000, v11 + (v12 << 9), v10, v9, 0, 0, 256);
        }
      }
      else
      {
        if ( dword_81C8584 & 4 )
        {
          v13 = npc->bits;
          LOBYTE(v13) = v13 | 0x80;
          npc->bits = v13;
          npc->damage = 100;
        }
        else
        {
          v14 = npc->bits;
          LOBYTE(v14) = v14 & 0x7F;
          npc->bits = v14;
          npc->damage = 0;
        }
        npc->xm += 32;
      }
      break;
    default:
      break;
  }
  if ( npc->xm > 512 )
    npc->xm = 512;
  if ( npc->xm < -512 )
    npc->xm = -512;
  npc->x += npc->xm;
  npc->rect.left = 16;
  npc->rect.top = 0;
  npc->rect.right = 48;
  npc->rect.bottom = 32;
}

void __cdecl ActNpc150(NPCHAR_0 *npc)
{
  int v1;
  int v2;
  int v3;
  int v4;
  int v5;
  int v6;
  NPCHAR_0 *v7;
  Sint32 *v8;
  RECT rcRight[9];
  RECT rcLeft[9];
  int i;
  char v12[24];

  qmemcpy(rcLeft, &ActNpc150(NPCHAR *)::C.14, sizeof(rcLeft));
  qmemcpy(rcRight, &ActNpc150(NPCHAR *)::C.15, sizeof(rcRight));
  switch ( npc->act_no )
  {
    case 0:
      npc->act_no = 1;
      npc->ani_no = 0;
      if ( npc->direct > 10 )
      {
        npc->x = x;
        npc->y = y;
        npc->direct -= 10;
      }
      break;
    case 2:
      npc->ani_no = 1;
      break;
    case 0xA:
      npc->act_no = 11;
      for ( i = 0; i <= 3; ++i )
      {
        v1 = Random(-1536, 0);
        v2 = Random(-341, 341);
        SetNpChar(4, npc->x, npc->y, v2, v1, 0, 0, 256);
      }
      PlaySoundObject(71, 1);
      goto LABEL_9;
    case 0xB:
LABEL_9:
      npc->ani_no = 2;
      break;
    case 0x14:
      npc->act_no = 21;
      npc->act_wait = 64;
      PlaySoundObject(29, 1);
      goto LABEL_11;
    case 0x15:
LABEL_11:
      if ( !--npc->act_wait )
        npc->cond = 0;
      break;
    case 0x32:
      npc->act_no = 51;
      npc->ani_no = 3;
      npc->ani_wait = 0;
      goto LABEL_14;
    case 0x33:
LABEL_14:
      if ( ++npc->ani_wait > 4 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 6 )
        npc->ani_no = 3;
      if ( npc->direct )
        v3 = npc->x + 512;
      else
        v3 = npc->x - 512;
      npc->x = v3;
      break;
    case 0x3C:
      npc->act_no = 61;
      npc->ani_no = 7;
      npc->tgt_x = npc->x;
      npc->tgt_y = npc->y;
      goto LABEL_23;
    case 0x3D:
LABEL_23:
      npc->tgt_y += 256;
      v4 = npc->tgt_x;
      npc->x = v4 + (Random(-1, 1) << 9);
      v5 = npc->tgt_y;
      npc->y = v5 + (Random(-1, 1) << 9);
      break;
    case 0x46:
      npc->act_no = 71;
      npc->act_wait = 0;
      npc->ani_no = 3;
      npc->ani_wait = 0;
      goto LABEL_25;
    case 0x47:
LABEL_25:
      if ( npc->direct )
        v6 = npc->x - 256;
      else
        v6 = npc->x + 256;
      npc->x = v6;
      if ( ++npc->ani_wait > 8 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 6 )
        npc->ani_no = 3;
      break;
    case 0x50:
      npc->ani_no = 8;
      break;
    case 0x63:
    case 0x64:
      npc->act_no = 101;
      npc->ani_no = 3;
      npc->ani_wait = 0;
      goto LABEL_34;
    case 0x65:
LABEL_34:
      npc->ym += 64;
      if ( npc->ym > 1535 )
        npc->ym = 1535;
      if ( npc->flag & 8 )
      {
        npc->ym = 0;
        npc->act_no = 102;
      }
      npc->y += npc->ym;
      break;
    case 0x66:
      if ( ++npc->ani_wait > 8 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 6 )
        npc->ani_no = 3;
      break;
    default:
      break;
  }
  if ( npc->direct )
  {
    v7 = npc;
    v8 = (Sint32 *)&v12[16 * npc->ani_no - 292];
  }
  else
  {
    v7 = npc;
    v8 = (Sint32 *)&v12[16 * npc->ani_no - 148];
  }
  npc->rect.left = *v8;
  v7->rect.top = v8[1];
  v7->rect.right = v8[2];
  v7->rect.bottom = v8[3];
  if ( npc->act_no == 21 )
  {
    npc->rect.bottom = npc->act_wait / 4 + npc->rect.top;
    if ( npc->act_wait / 2 & 1 )
      ++npc->rect.left;
  }
  if ( unk_81C8598 & 0x40 )
  {
    npc->rect.top += 32;
    npc->rect.bottom += 32;
  }
}


void __cdecl ActNpc151(NPCHAR_0 *npc)
{
  int v1;
  NPCHAR_0 *v2;
  Sint32 *v3;
  RECT rcRight[2];
  RECT rcLeft[2];
  char v6[8];

  rcLeft[0].left = 192;
  rcLeft[0].top = 0;
  rcLeft[0].right = 208;
  rcLeft[0].bottom = 16;
  rcLeft[1].left = 208;
  rcLeft[1].top = 0;
  rcLeft[1].right = 224;
  rcLeft[1].bottom = 16;
  rcRight[0].left = 192;
  rcRight[0].top = 16;
  rcRight[0].right = 208;
  rcRight[0].bottom = 32;
  rcRight[1].left = 208;
  rcRight[1].top = 16;
  rcRight[1].right = 224;
  rcRight[1].bottom = 32;
  v1 = npc->act_no;
  if ( v1 == 1 )
  {
LABEL_5:
    if ( Random(0, 100) == 0 )
    {
      npc->act_no = 2;
      npc->act_wait = 0;
      npc->ani_no = 1;
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
    goto LABEL_5;
  }
  if ( ++npc->act_wait > 16 )
  {
    npc->act_no = 1;
    npc->ani_no = 0;
  }
LABEL_9:
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
}


void __cdecl ActNpc152(NPCHAR_0 *npc)
{
  if ( !npc->act_no )
  {
    if ( npc->direct == 2 )
      npc->y += 0x2000;
    npc->act_no = 1;
  }
  npc->rect.left = 0;
  npc->rect.top = 0;
  npc->rect.right = 0;
  npc->rect.bottom = 0;
}

void __cdecl ActNpc153(NPCHAR_0 *npc)
{
  NPCHAR_0 *v1;
  Sint32 *v2;
  Sint32 v3;
  Sint32 *v4;

  if ( npc->x <= x + 163840 && npc->x >= x - 163840 && npc->y <= y + 122880 && npc->y >= y - 122880 )
  {
    switch ( npc->act_no )
    {
      case 0:
        npc->act_no = 1;
        npc->xm = 0;
        npc->ani_no = 0;
        npc->y += 1536;
        goto LABEL_7;
      case 1:
LABEL_7:
        if ( Random(0, 100) == 1 )
        {
          npc->act_no = 2;
          npc->ani_no = 1;
          npc->act_wait = 0;
        }
        if ( Random(0, 100) == 1 )
        {
          if ( npc->direct )
            npc->direct = 0;
          else
            npc->direct = 2;
        }
        if ( Random(0, 100) == 1 )
          npc->act_no = 10;
        break;
      case 2:
        if ( ++npc->act_wait > 20 )
        {
          npc->act_no = 1;
          npc->ani_no = 0;
        }
        break;
      case 0xA:
        npc->act_no = 11;
        npc->act_wait = Random(25, 100);
        npc->ani_no = 2;
        npc->ani_wait = 0;
        goto LABEL_18;
      case 0xB:
LABEL_18:
        if ( ++npc->ani_wait > 3 )
        {
          npc->ani_wait = 0;
          ++npc->ani_no;
        }
        if ( npc->ani_no > 5 )
          npc->ani_no = 2;
        if ( npc->direct )
          npc->xm = 512;
        else
          npc->xm = -512;
        if ( npc->act_wait )
        {
          --npc->act_wait;
        }
        else
        {
          npc->act_no = 1;
          npc->ani_no = 0;
          npc->xm = 0;
        }
        if ( npc->direct || !(npc->flag & 1) )
        {
          if ( npc->direct == 2 )
          {
            if ( npc->flag & 4 )
            {
              npc->ani_no = 2;
              npc->ym = -1535;
              npc->act_no = 20;
              if ( !(gMC.cond & 2) )
                PlaySoundObject(30, 1);
            }
          }
        }
        else
        {
          npc->ani_no = 2;
          npc->ym = -1535;
          npc->act_no = 20;
          if ( !(gMC.cond & 2) )
            PlaySoundObject(30, 1);
        }
        break;
      case 0x14:
        if ( npc->direct || !(npc->flag & 1) )
        {
          if ( npc->direct == 2 && npc->flag & 4 )
            ++npc->count1;
          else
            npc->count1 = 0;
        }
        else
        {
          ++npc->count1;
        }
        if ( npc->count1 > 10 )
        {
          if ( npc->direct )
            npc->direct = 0;
          else
            npc->direct = 2;
        }
        if ( npc->direct )
          npc->xm = 256;
        else
          npc->xm = -256;
        if ( npc->flag & 8 )
        {
          npc->act_no = 21;
          npc->ani_no = 20;
          npc->act_wait = 0;
          npc->xm = 0;
          if ( !(gMC.cond & 2) )
            PlaySoundObject(23, 1);
        }
        break;
      case 0x15:
        if ( ++npc->act_wait > 10 )
        {
          npc->act_no = 1;
          npc->ani_no = 0;
        }
        break;
      default:
        break;
    }
    npc->ym += 64;
    if ( npc->ym > 1535 )
      npc->ym = 1535;
    npc->x += npc->xm;
    npc->y += npc->ym;
    if ( npc->direct )
    {
      v1 = npc;
      v4 = (Sint32 *)(16 * npc->ani_no);
      npc->rect.left = *(Sint32 *)((char *)&grcKitR[0].left + (_DWORD)v4);
      npc->rect.top = v4[34020881];
      npc->rect.right = v4[34020882];
      v3 = v4[34020883];
    }
    else
    {
      v1 = npc;
      v2 = (Sint32 *)(16 * npc->ani_no);
      npc->rect.left = *(Sint32 *)((char *)&grcKitL[0].left + (_DWORD)v2);
      npc->rect.top = v2[34020793];
      npc->rect.right = v2[34020794];
      v3 = v2[34020795];
    }
    v1->rect.bottom = v3;
    if ( npc->life <= 985 )
    {
      npc->code_char = 154;
      npc->act_no = 0;
    }
  }
}

void __cdecl ActNpc154(NPCHAR_0 *npc)
{
  int v1;
  NPCHAR_0 *v2;
  Sint32 *v3;
  Sint32 v4;
  Sint32 *v5;

  v1 = npc->act_no;
  switch ( v1 )
  {
    case 1:
      if ( npc->flag & 8 )
      {
        npc->ani_no = 10;
        npc->ani_wait = 0;
        npc->act_no = 2;
        npc->act_wait = 0;
      }
      break;
    case 2:
      npc->xm = 8 * npc->xm / 9;
      if ( ++npc->ani_wait > 3 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 11 )
        npc->ani_no = 10;
      if ( ++npc->act_wait > 50 )
        npc->cond |= 8u;
      break;
    case 0:
      npc->bits &= 0xFFDFu;
      npc->bits &= 0xFFF7u;
      npc->damage = 0;
      npc->act_no = 1;
      npc->ani_no = 9;
      npc->ym = -512;
      if ( npc->direct )
        npc->xm = -256;
      else
        npc->xm = 256;
      PlaySoundObject(53, 1);
      break;
  }
  npc->ym += 32;
  if ( npc->ym > 1535 )
    npc->ym = 1535;
  npc->x += npc->xm;
  npc->y += npc->ym;
  if ( npc->direct )
  {
    v2 = npc;
    v5 = (Sint32 *)(16 * npc->ani_no);
    npc->rect.left = *(Sint32 *)((char *)&grcKitR[0].left + (_DWORD)v5);
    npc->rect.top = v5[34020881];
    npc->rect.right = v5[34020882];
    v4 = v5[34020883];
  }
  else
  {
    v2 = npc;
    v3 = (Sint32 *)(16 * npc->ani_no);
    npc->rect.left = *(Sint32 *)((char *)&grcKitL[0].left + (_DWORD)v3);
    npc->rect.top = v3[34020793];
    npc->rect.right = v3[34020794];
    v4 = v3[34020795];
  }
  v2->rect.bottom = v4;
}

void __cdecl ActNpc155(NPCHAR_0 *npc)
{
  int v1;
  unsigned __int8 deg;
  int v3;
  unsigned __int8 v4;
  int v5;
  unsigned __int8 v6;
  unsigned __int8 v7;
  int ym;
  int v9;
  NPCHAR_0 *v10;
  Sint32 *v11;
  Sint32 v12;
  Sint32 *v13;

  if ( npc->x > x + 163840 || npc->x < x - 163840 || npc->y > y + 122880 || npc->y < y - 122880 )
    return;
  v1 = npc->act_no;
  switch ( v1 )
  {
    case 1:
      goto LABEL_9;
    case 2:
      if ( ++npc->ani_no > 19 )
        npc->ani_no = 18;
      if ( ++npc->act_wait > 30 )
      {
        v6 = GetArktan(npc->x - x, npc->y - y);
        v7 = Random(-6, 6) + v6;
        ym = 3 * GetSin(v7);
        v9 = GetCos(v7);
        SetNpChar(156, npc->x, npc->y, 3 * v9, ym, 0, 0, 256);
        if ( !(gMC.cond & 2) )
          PlaySoundObject(39, 1);
        npc->act_no = 1;
        npc->act_wait = Random(70, 150);
        npc->ani_no = 14;
        npc->ani_wait = 0;
      }
      break;
    case 0:
      deg = Random(0, 255);
      npc->xm = GetCos(deg);
      v3 = npc->x;
      npc->tgt_x = v3 + 8 * GetCos(deg + 64);
      v4 = Random(0, 255);
      npc->ym = GetSin(v4);
      v5 = npc->y;
      npc->tgt_y = v5 + 8 * GetSin(v4 + 64);
      npc->act_no = 1;
      npc->count1 = 120;
      npc->act_wait = Random(70, 150);
      npc->ani_no = 14;
LABEL_9:
      if ( ++npc->ani_no > 15 )
        npc->ani_no = 14;
      if ( npc->act_wait )
      {
        --npc->act_wait;
      }
      else
      {
        npc->act_no = 2;
        npc->ani_no = 18;
      }
      break;
  }
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
  npc->x += npc->xm;
  npc->y += npc->ym;
  if ( npc->direct )
  {
    v10 = npc;
    v13 = (Sint32 *)(16 * npc->ani_no);
    npc->rect.left = *(Sint32 *)((char *)&grcKitR[0].left + (_DWORD)v13);
    npc->rect.top = v13[34020881];
    npc->rect.right = v13[34020882];
    v12 = v13[34020883];
  }
  else
  {
    v10 = npc;
    v11 = (Sint32 *)(16 * npc->ani_no);
    npc->rect.left = *(Sint32 *)((char *)&grcKitL[0].left + (_DWORD)v11);
    npc->rect.top = v11[34020793];
    npc->rect.right = v11[34020794];
    v12 = v11[34020795];
  }
  v10->rect.bottom = v12;
  if ( npc->life <= 985 )
  {
    npc->code_char = 154;
    npc->act_no = 0;
  }
}

void __cdecl ActNpc156(NPCHAR_0 *npc)
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
  rect_left[0].top = 112;
  rect_left[0].right = 112;
  rect_left[0].bottom = 128;
  rect_left[1].left = 112;
  rect_left[1].top = 112;
  rect_left[1].right = 128;
  rect_left[1].bottom = 128;
  rect_left[2].left = 128;
  rect_left[2].top = 112;
  rect_left[2].right = 144;
  rect_left[2].bottom = 128;
  if ( ++npc->ani_no > 2 )
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


void __cdecl ActNpc157(NPCHAR_0 *npc)
{
  unsigned __int16 v1;
  int v2;
  int v3;
  int v4;
  int v5;
  int v6;
  unsigned __int16 v7;
  unsigned __int16 v8;
  unsigned __int16 v9;
  int v10;
  int v11;
  int v12;
  int v13;
  int v14;
  unsigned __int16 v15;
  unsigned __int16 v16;
  int i;
  int ia;

  switch ( npc->act_no )
  {
    case 0:
      npc->x += 4096;
      npc->y += 4096;
      if ( npc->direct )
        npc->act_no = 20;
      else
        npc->act_no = 10;
      npc->xm = 0;
      npc->ym = 0;
      npc->bits |= 0x40u;
      break;
    case 0xA:
      v1 = npc->bits;
      LOBYTE(v1) = v1 & 0x7F;
      npc->bits = v1;
      npc->damage = 0;
      if ( y < npc->y + 12800 && y > npc->y - 204800 && x < npc->x + 12800 && x > npc->x - 12800 )
      {
        npc->act_no = 11;
        npc->act_wait = 0;
      }
      break;
    case 0xB:
      if ( ++npc->act_wait % 10 == 6 )
        PlaySoundObject(107, 1);
      if ( npc->flag & 2 )
      {
        npc->ym = 0;
        npc->direct = 2;
        npc->act_no = 20;
        SetQuake(10);
        PlaySoundObject(26, 1);
        for ( i = 0; i <= 3; ++i )
        {
          v2 = Random(-1536, 0);
          v3 = Random(-341, 341);
          v4 = npc->y - 0x2000;
          v5 = npc->x;
          v6 = Random(-12, 12);
          SetNpChar(4, v5 + (v6 << 9), v4, v3, v2, 0, 0, 256);
        }
      }
      else
      {
        if ( dword_81C8584 & 2 )
        {
          v7 = npc->bits;
          LOBYTE(v7) = v7 | 0x80;
          npc->bits = v7;
          npc->damage = 100;
        }
        else
        {
          v8 = npc->bits;
          LOBYTE(v8) = v8 & 0x7F;
          npc->bits = v8;
          npc->damage = 0;
        }
        npc->ym -= 32;
      }
      break;
    case 0x14:
      v9 = npc->bits;
      LOBYTE(v9) = v9 & 0x7F;
      npc->bits = v9;
      npc->damage = 0;
      if ( y > npc->y - 12800 && y < npc->y + 204800 && x < npc->x + 12800 && x > npc->x - 12800 )
      {
        npc->act_no = 21;
        npc->act_wait = 0;
      }
      break;
    case 0x15:
      if ( ++npc->act_wait % 10 == 6 )
        PlaySoundObject(107, 1);
      if ( npc->flag & 8 )
      {
        npc->ym = 0;
        npc->direct = 0;
        npc->act_no = 10;
        SetQuake(10);
        PlaySoundObject(26, 1);
        for ( ia = 0; ia <= 3; ++ia )
        {
          v10 = Random(-1536, 0);
          v11 = Random(-341, 341);
          v12 = npc->y + 0x2000;
          v13 = npc->x;
          v14 = Random(-12, 12);
          SetNpChar(4, v13 + (v14 << 9), v12, v11, v10, 0, 0, 256);
        }
      }
      else
      {
        if ( dword_81C8584 & 8 )
        {
          v15 = npc->bits;
          LOBYTE(v15) = v15 | 0x80;
          npc->bits = v15;
          npc->damage = 100;
        }
        else
        {
          v16 = npc->bits;
          LOBYTE(v16) = v16 & 0x7F;
          npc->bits = v16;
          npc->damage = 0;
        }
        npc->ym += 32;
      }
      break;
    default:
      break;
  }
  if ( npc->ym > 512 )
    npc->ym = 512;
  if ( npc->ym < -512 )
    npc->ym = -512;
  npc->y += npc->ym;
  npc->rect.left = 16;
  npc->rect.top = 0;
  npc->rect.right = 48;
  npc->rect.bottom = 32;
}

void __cdecl ActNpc158(NPCHAR_0 *npc)
{
  int v1;
  int v2;
  int v3;
  int v4;
  Sint32 *v5;
  RECT rect[8];
  int dir;
  char v8[24];

  qmemcpy(rect, &ActNpc158(NPCHAR *)::C.21, sizeof(rect));
  v1 = npc->act_no;
  if ( v1 )
  {
    if ( v1 != 1 )
      goto LABEL_28;
  }
  else
  {
    npc->act_no = 1;
    v2 = npc->direct;
    if ( v2 == 1 )
    {
      npc->count1 = 224;
    }
    else if ( v2 > 1 )
    {
      if ( v2 == 2 )
      {
        npc->count1 = 32;
      }
      else if ( v2 == 3 )
      {
        npc->count1 = 96;
      }
    }
    else if ( !v2 )
    {
      npc->count1 = 160;
    }
  }
  npc->xm = 2 * GetCos(npc->count1);
  npc->ym = 2 * GetSin(npc->count1);
  npc->y += npc->ym;
  npc->x += npc->xm;
  dir = (unsigned __int8)GetArktan(npc->x - x, npc->y - y);
  if ( npc->count1 <= dir )
  {
    if ( dir - npc->count1 > 127 )
      v4 = npc->count1 - 1;
    else
      v4 = npc->count1 + 1;
    npc->count1 = v4;
  }
  else
  {
    if ( npc->count1 - dir > 127 )
      v3 = npc->count1 + 1;
    else
      v3 = npc->count1 - 1;
    npc->count1 = v3;
  }
  if ( npc->count1 > 255 )
    npc->count1 -= 256;
  if ( npc->count1 < 0 )
    npc->count1 += 256;
LABEL_28:
  if ( ++npc->ani_wait > 2 )
  {
    npc->ani_wait = 0;
    SetCaret(npc->x, npc->y, 7, 4);
  }
  npc->ani_no = (npc->count1 + 16) / 32;
  if ( npc->ani_no > 7 )
    npc->ani_no = 7;
  v5 = (Sint32 *)&v8[16 * npc->ani_no - 132];
  npc->rect.left = *v5;
  npc->rect.top = v5[1];
  npc->rect.right = v5[2];
  npc->rect.bottom = v5[3];
}


void __cdecl ActNpc159(NPCHAR_0 *npc)
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
  int v14;
  int i;

  v1 = npc->act_no;
  if ( v1 == 1 )
  {
LABEL_7:
    if ( ++npc->act_wait > 50 )
    {
      npc->act_no = 2;
      npc->xm = -256;
    }
    if ( npc->act_wait / 2 & 1 )
      v8 = npc->x + 512;
    else
      v8 = npc->x - 512;
    npc->x = v8;
    goto LABEL_15;
  }
  if ( v1 != 2 )
  {
    if ( v1 )
      goto LABEL_15;
    npc->act_no = 1;
    for ( i = 0; i <= 7; ++i )
    {
      v2 = Random(-341, 341);
      v3 = Random(-341, 341);
      v4 = npc->y;
      v5 = (Random(-16, 16) << 9) + v4;
      v6 = npc->x;
      v7 = Random(-16, 16);
      SetNpChar(4, v6 + (v7 << 9), v5, v3, v2, 0, 0, 256);
    }
    goto LABEL_7;
  }
  ++npc->act_wait;
  npc->ym += 64;
  if ( npc->y > 327680 )
    npc->cond = 0;
LABEL_15:
  npc->y += npc->ym;
  npc->x += npc->xm;
  npc->rect.left = 144;
  npc->rect.top = 128;
  npc->rect.right = 192;
  npc->rect.bottom = 200;
  if ( npc->act_wait % 8 == 1 )
  {
    v9 = Random(-341, 341);
    v10 = Random(-341, 341);
    v11 = npc->y;
    v12 = (Random(-16, 16) << 9) + v11;
    v13 = npc->x;
    v14 = Random(-16, 16);
    SetNpChar(4, v13 + (v14 << 9), v12, v10, v9, 0, 0, 256);
  }
}

