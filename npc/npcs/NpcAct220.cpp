#include "types.h"
#include "SDL_stdinc.h"
#include "windows_wrapper.h"
#include "Tags.h"
#include "forNpc.h"

void __cdecl ActNpc220(NPCHAR_0 *npc);
void __cdecl ActNpc221(NPCHAR_0 *npc);
void __cdecl ActNpc222(NPCHAR_0 *npc);
void __cdecl ActNpc223(NPCHAR_0 *npc);
void __cdecl ActNpc224(NPCHAR_0 *npc);
void __cdecl ActNpc225(NPCHAR_0 *npc);
void __cdecl ActNpc226(NPCHAR_0 *npc);
void __cdecl ActNpc227(NPCHAR_0 *npc);
void __cdecl ActNpc228(NPCHAR_0 *npc);
void __cdecl ActNpc229(NPCHAR_0 *npc);
void __cdecl ActNpc230(NPCHAR_0 *npc);
void __cdecl ActNpc231(NPCHAR_0 *npc);
void __cdecl ActNpc232(NPCHAR_0 *npc);
void __cdecl ActNpc233(NPCHAR_0 *npc);
void __cdecl ActNpc234(NPCHAR_0 *npc);
void __cdecl ActNpc235(NPCHAR_0 *npc);
void __cdecl ActNpc236(NPCHAR_0 *npc);
void __cdecl ActNpc237(NPCHAR_0 *npc);
void __cdecl ActNpc238(NPCHAR_0 *npc);
void __cdecl ActNpc239(NPCHAR_0 *npc);

_UNKNOWN ActNpc236(NPCHAR *)::C.14;
_UNKNOWN ActNpc236(NPCHAR *)::C.15;
_UNKNOWN ActNpc226(NPCHAR *)::C.9;
_UNKNOWN ActNpc221(NPCHAR *)::C.1;
_UNKNOWN ActNpc221(NPCHAR *)::C.2;

void __cdecl ActNpc220(NPCHAR_0 *npc)
{
  int v1;
  NPCHAR_0 *v2;
  Sint32 *v3;
  RECT rcRight[2];
  RECT rcLeft[2];
  char v6[8];

  rcLeft[0].left = 0;
  rcLeft[0].top = 64;
  rcLeft[0].right = 16;
  rcLeft[0].bottom = 80;
  rcLeft[1].left = 16;
  rcLeft[1].top = 64;
  rcLeft[1].right = 32;
  rcLeft[1].bottom = 80;
  rcRight[0].left = 0;
  rcRight[0].top = 80;
  rcRight[0].right = 16;
  rcRight[0].bottom = 96;
  rcRight[1].left = 16;
  rcRight[1].top = 80;
  rcRight[1].right = 32;
  rcRight[1].bottom = 96;
  v1 = npc->act_no;
  if ( v1 == 1 )
  {
LABEL_5:
    if ( Random(0, 120) == 10 )
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
  if ( ++npc->act_wait > 8 )
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


void __cdecl ActNpc221(NPCHAR_0 *npc)
{
  NPCHAR_0 *v1;
  Sint32 *v2;
  RECT rcRight[6];
  RECT rcLeft[6];
  char v5[24];

  qmemcpy(rcLeft, &ActNpc221(NPCHAR *)::C.1, sizeof(rcLeft));
  qmemcpy(rcRight, &ActNpc221(NPCHAR *)::C.2, sizeof(rcRight));
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


void __cdecl ActNpc222(NPCHAR_0 *npc)
{
  if ( !npc->act_no )
  {
    ++npc->act_no;
    npc->y -= 4096;
  }
  npc->rect.left = 96;
  npc->rect.top = 168;
  npc->rect.right = 112;
  npc->rect.bottom = 200;
}

void __cdecl ActNpc223(NPCHAR_0 *npc)
{
  int v1;
  NPCHAR_0 *v2;
  Sint32 *v3;
  RECT rcRight[3];
  RECT rcLeft[3];
  char v6[8];

  rcLeft[0].left = 80;
  rcLeft[0].top = 192;
  rcLeft[0].right = 96;
  rcLeft[0].bottom = 216;
  rcLeft[1].left = 96;
  rcLeft[1].top = 192;
  rcLeft[1].right = 112;
  rcLeft[1].bottom = 216;
  rcLeft[2].left = 112;
  rcLeft[2].top = 192;
  rcLeft[2].right = 128;
  rcLeft[2].bottom = 216;
  rcRight[0].left = 80;
  rcRight[0].top = 216;
  rcRight[0].right = 96;
  rcRight[0].bottom = 240;
  rcRight[1].left = 96;
  rcRight[1].top = 216;
  rcRight[1].right = 112;
  rcRight[1].bottom = 240;
  rcRight[2].left = 112;
  rcRight[2].top = 216;
  rcRight[2].right = 128;
  rcRight[2].bottom = 240;
  v1 = npc->act_no;
  if ( v1 == 1 )
  {
LABEL_9:
    if ( Random(0, 160) == 1 )
    {
      npc->act_no = 2;
      npc->act_wait = 0;
      npc->ani_no = 1;
    }
    goto LABEL_14;
  }
  if ( v1 <= 1 )
  {
    if ( v1 )
      goto LABEL_14;
    npc->act_no = 1;
    npc->ani_no = 0;
    npc->ani_wait = 0;
    goto LABEL_9;
  }
  if ( v1 == 2 )
  {
    if ( ++npc->act_wait > 12 )
    {
      npc->act_no = 1;
      npc->ani_no = 0;
    }
  }
  else if ( v1 == 3 )
  {
    npc->ani_no = 2;
  }
LABEL_14:
  if ( npc->act_no <= 1 && y < npc->y + 0x2000 && y > npc->y - 0x2000 )
  {
    if ( x >= npc->x )
      npc->direct = 2;
    else
      npc->direct = 0;
  }
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


void __cdecl ActNpc224(NPCHAR_0 *npc)
{
  int v1;
  NPCHAR_0 *v2;
  Sint32 *v3;
  RECT rcRight[2];
  RECT rcLeft[2];
  char v6[8];

  rcLeft[0].left = 112;
  rcLeft[0].top = 32;
  rcLeft[0].right = 128;
  rcLeft[0].bottom = 48;
  rcLeft[1].left = 128;
  rcLeft[1].top = 32;
  rcLeft[1].right = 144;
  rcLeft[1].bottom = 48;
  rcRight[0].left = 112;
  rcRight[0].top = 48;
  rcRight[0].right = 128;
  rcRight[0].bottom = 64;
  rcRight[1].left = 128;
  rcRight[1].top = 48;
  rcRight[1].right = 144;
  rcRight[1].bottom = 64;
  v1 = npc->act_no;
  if ( v1 == 1 )
  {
LABEL_5:
    if ( Random(0, 160) == 1 )
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
  if ( ++npc->act_wait > 12 )
  {
    npc->act_no = 1;
    npc->ani_no = 0;
  }
LABEL_9:
  if ( npc->act_no <= 1 && y < npc->y + 0x2000 && y > npc->y - 0x2000 )
  {
    if ( x >= npc->x )
      npc->direct = 2;
    else
      npc->direct = 0;
  }
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


void __cdecl ActNpc225(NPCHAR_0 *npc)
{
  int v1;
  NPCHAR_0 *v2;
  Sint32 *v3;
  RECT rcRight[2];
  RECT rcLeft[2];
  char v6[8];

  rcLeft[0].left = 64;
  rcLeft[0].top = 64;
  rcLeft[0].right = 80;
  rcLeft[0].bottom = 80;
  rcLeft[1].left = 80;
  rcLeft[1].top = 64;
  rcLeft[1].right = 96;
  rcLeft[1].bottom = 80;
  rcRight[0].left = 64;
  rcRight[0].top = 80;
  rcRight[0].right = 80;
  rcRight[0].bottom = 96;
  rcRight[1].left = 80;
  rcRight[1].top = 80;
  rcRight[1].right = 96;
  rcRight[1].bottom = 96;
  v1 = npc->act_no;
  if ( v1 == 1 )
  {
LABEL_5:
    if ( Random(0, 160) == 1 )
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
  if ( ++npc->act_wait > 12 )
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


void __cdecl ActNpc226(NPCHAR_0 *npc)
{
  Sint32 *v1;
  RECT rcRight[7];
  char v3[24];

  qmemcpy(rcRight, &ActNpc226(NPCHAR *)::C.9, sizeof(rcRight));
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
      npc->ani_no = 2;
      npc->ani_wait = 0;
      goto LABEL_8;
    case 0xB:
LABEL_8:
      npc->xm = 512;
      if ( ++npc->ani_wait > 4 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 5 )
        npc->ani_no = 2;
      ++npc->act_wait;
      break;
    case 0x14:
      npc->xm = 0;
      npc->ani_no = 6;
      break;
    default:
      break;
  }
  npc->ym += 32;
  if ( npc->ym > 1535 )
    npc->ym = 1535;
  npc->x += npc->xm;
  npc->y += npc->ym;
  v1 = (Sint32 *)&v3[16 * npc->ani_no - 112];
  npc->rect.left = *v1;
  npc->rect.top = v1[1];
  npc->rect.right = v1[2];
  npc->rect.bottom = v1[3];
}


void __cdecl ActNpc227(NPCHAR_0 *npc)
{
  npc->rect.left = 208;
  npc->rect.top = 32;
  npc->rect.right = 224;
  npc->rect.bottom = 48;
}

void __cdecl ActNpc228(NPCHAR_0 *npc)
{
  NPCHAR_0 *v1;
  RECT *v2;
  RECT rcRight[4];
  RECT rcLeft[4];

  rcLeft[0].left = 0;
  rcLeft[0].top = 0;
  rcLeft[0].right = 32;
  rcLeft[0].bottom = 40;
  rcLeft[1].left = 32;
  rcLeft[1].top = 0;
  rcLeft[1].right = 64;
  rcLeft[1].bottom = 40;
  rcLeft[2].left = 64;
  rcLeft[2].top = 0;
  rcLeft[2].right = 96;
  rcLeft[2].bottom = 40;
  rcLeft[3].left = 96;
  rcLeft[3].top = 0;
  rcLeft[3].right = 128;
  rcLeft[3].bottom = 40;
  rcRight[0].left = 0;
  rcRight[0].top = 40;
  rcRight[0].right = 32;
  rcRight[0].bottom = 80;
  rcRight[1].left = 32;
  rcRight[1].top = 40;
  rcRight[1].right = 64;
  rcRight[1].bottom = 80;
  rcRight[2].left = 64;
  rcRight[2].top = 40;
  rcRight[2].right = 96;
  rcRight[2].bottom = 80;
  rcRight[3].left = 96;
  rcRight[3].top = 40;
  rcRight[3].right = 128;
  rcRight[3].bottom = 80;
  switch ( npc->act_no )
  {
    case 0:
      npc->act_no = 1;
      npc->y -= 4096;
      goto LABEL_3;
    case 1:
LABEL_3:
      npc->xm = 0;
      npc->act_no = 2;
      npc->ani_no = 0;
      goto LABEL_4;
    case 2:
LABEL_4:
      if ( npc->x <= x )
        npc->direct = 2;
      else
        npc->direct = 0;
      if ( ++npc->ani_wait > 50 )
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
      npc->act_wait = 0;
      goto LABEL_12;
    case 0xB:
LABEL_12:
      if ( ++npc->act_wait > 10 )
      {
        npc->act_no = 12;
        npc->ani_no = 3;
        npc->ym = -1536;
        if ( npc->direct )
          npc->xm = 512;
        else
          npc->xm = -512;
      }
      break;
    case 0xC:
      if ( npc->flag & 8 )
      {
        npc->ani_no = 2;
        npc->act_no = 13;
        npc->act_wait = 0;
      }
      break;
    case 0xD:
      npc->xm /= 2;
      if ( ++npc->act_wait > 10 )
        npc->act_no = 1;
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

void __cdecl ActNpc229(NPCHAR_0 *npc)
{
  if ( !npc->act_no )
  {
    npc->act_no = 1;
    npc->y -= 0x2000;
  }
  if ( npc->direct )
  {
    npc->rect.left = 0;
    npc->rect.top = 112;
    npc->rect.right = 48;
    npc->rect.bottom = 128;
  }
  else
  {
    npc->rect.left = 0;
    npc->rect.top = 96;
    npc->rect.right = 48;
    npc->rect.bottom = 112;
  }
}

void __cdecl ActNpc230(NPCHAR_0 *npc)
{
  if ( !npc->act_no )
  {
    npc->act_no = 1;
    npc->x -= 0x2000;
    npc->y -= 0x2000;
  }
  if ( npc->direct )
  {
    npc->rect.left = 96;
    npc->rect.top = 96;
    npc->rect.right = 144;
  }
  else
  {
    npc->rect.left = 48;
    npc->rect.top = 96;
    npc->rect.right = 96;
  }
  npc->rect.bottom = 128;
}

void __cdecl ActNpc231(NPCHAR_0 *npc)
{
  unsigned __int16 v1;
  int v2;
  int v3;
  int v4;
  int v5;
  int v6;
  int v7;
  int v8;
  int v9;
  unsigned __int16 v10;
  Sint32 *v11;
  RECT rc[2];
  int i;
  char v14[8];

  rc[0].left = 176;
  rc[0].top = 32;
  rc[0].right = 208;
  rc[0].bottom = 48;
  rc[1].left = 176;
  rc[1].top = 48;
  rc[1].right = 208;
  rc[1].bottom = 64;
  switch ( npc->act_no )
  {
    case 0:
      npc->act_no = 1;
      goto LABEL_3;
    case 1:
LABEL_3:
      npc->ani_no = 0;
      break;
    case 0xA:
      npc->act_no = 11;
      npc->act_wait = 0;
      goto LABEL_5;
    case 0xB:
LABEL_5:
      ++npc->act_wait;
      npc->ym += 8;
      if ( npc->flag & 8 )
      {
        if ( npc->act_wait > 9 )
          npc->act_no = 1;
        else
          npc->act_no = 12;
      }
      break;
    case 0xC:
      v1 = npc->bits;
      HIBYTE(v1) &= 0xDFu;
      npc->bits = v1;
      npc->act_no = 13;
      npc->act_wait = 0;
      npc->ani_no = 1;
      for ( i = 0; i <= 9; ++i )
      {
        v2 = npc->y;
        v3 = (Random(-8, 8) << 9) + v2;
        v4 = npc->x;
        v5 = Random(-16, 16);
        SetNpChar(4, v4 + (v5 << 9), v3, 0, 0, 0, 0, 256);
        PlaySoundObject(12, 1);
      }
      goto LABEL_12;
    case 0xD:
LABEL_12:
      npc->ym -= 8;
      if ( !(++npc->act_wait & 1) )
        SetCaret(npc->x - 5120, npc->y + 4096, 7, 3);
      if ( npc->act_wait % 2 == 1 )
        SetCaret(npc->x + 5120, npc->y + 4096, 7, 3);
      if ( npc->act_wait % 4 == 1 )
        PlaySoundObject(34, 1);
      if ( npc->flag & 2 || dword_81C8584 & 2 || npc->act_wait > 450 )
      {
        if ( npc->flag & 2 || dword_81C8584 & 2 )
          npc->ym = 0;
        npc->act_no = 15;
        for ( i = 0; i <= 5; ++i )
        {
          v6 = npc->y;
          v7 = (Random(-8, 8) << 9) + v6;
          v8 = npc->x;
          v9 = Random(-16, 16);
          SetNpChar(4, v8 + (v9 << 9), v7, 0, 0, 0, 0, 256);
          PlaySoundObject(12, 1);
        }
      }
      break;
    case 0xF:
      npc->ym += 8;
      ++npc->act_wait;
      if ( npc->ym < 0 )
      {
        if ( !(npc->act_wait & 7) )
          SetCaret(npc->x - 5120, npc->y + 4096, 7, 3);
        if ( npc->act_wait % 8 == 4 )
          SetCaret(npc->x + 5120, npc->y + 4096, 7, 3);
        if ( npc->act_wait % 16 == 1 )
          PlaySoundObject(34, 1);
      }
      if ( npc->flag & 8 )
      {
        v10 = npc->bits;
        HIBYTE(v10) |= 0x20u;
        npc->bits = v10;
        npc->act_no = 1;
        npc->ani_no = 0;
      }
      break;
    default:
      break;
  }
  if ( npc->ym < -1535 )
    npc->ym = -1535;
  if ( npc->ym > 1535 )
    npc->ym = 1535;
  npc->y += npc->ym;
  v11 = (Sint32 *)&v14[16 * npc->ani_no - 36];
  npc->rect.left = *v11;
  npc->rect.top = v11[1];
  npc->rect.right = v11[2];
  npc->rect.bottom = v11[3];
}


void __cdecl ActNpc232(NPCHAR_0 *npc)
{
  int v1;
  int v2;
  NPCHAR_0 *v3;
  Sint32 *v4;
  RECT rcRight[3];
  RECT rcLeft[3];
  int i;
  char v8[8];

  v1 = npc->act_no;
  if ( v1 )
  {
    if ( v1 != 1 )
      goto LABEL_27;
  }
  else
  {
    npc->act_no = 1;
    npc->tgt_x = npc->x;
    npc->tgt_y = npc->y;
    npc->ym = 512;
    for ( i = 0; i <= 7; ++i )
      SetNpChar(233, npc->x, npc->y, 0, 0, npc->direct, npc, 256);
  }
  if ( npc->xm < 0 && npc->flag & 1 )
    npc->direct = 2;
  if ( npc->xm > 0 && npc->flag & 4 )
    npc->direct = 0;
  if ( npc->direct )
    npc->xm = 256;
  else
    npc->xm = -256;
  if ( npc->y >= npc->tgt_y )
    v2 = npc->ym - 8;
  else
    v2 = npc->ym + 8;
  npc->ym = v2;
  if ( npc->ym > 512 )
    npc->ym = 512;
  if ( npc->ym < -512 )
    npc->ym = -512;
  if ( ++npc->ani_wait > 5 )
  {
    npc->ani_wait = 0;
    ++npc->ani_no;
  }
  if ( npc->ani_no > 2 )
    npc->ani_no = 0;
LABEL_27:
  npc->y += npc->ym;
  npc->x += npc->xm;
  rcLeft[0].left = 128;
  rcLeft[0].top = 0;
  rcLeft[0].right = 160;
  rcLeft[0].bottom = 32;
  rcLeft[1].left = 160;
  rcLeft[1].top = 0;
  rcLeft[1].right = 192;
  rcLeft[1].bottom = 32;
  rcLeft[2].left = 192;
  rcLeft[2].top = 0;
  rcLeft[2].right = 224;
  rcLeft[2].bottom = 32;
  rcRight[0].left = 128;
  rcRight[0].top = 32;
  rcRight[0].right = 160;
  rcRight[0].bottom = 64;
  rcRight[1].left = 160;
  rcRight[1].top = 32;
  rcRight[1].right = 192;
  rcRight[1].bottom = 64;
  rcRight[2].left = 192;
  rcRight[2].top = 32;
  rcRight[2].right = 224;
  rcRight[2].bottom = 64;
  if ( npc->direct )
  {
    v3 = npc;
    v4 = (Sint32 *)&v8[16 * npc->ani_no - 100];
  }
  else
  {
    v3 = npc;
    v4 = (Sint32 *)&v8[16 * npc->ani_no - 52];
  }
  npc->rect.left = *v4;
  v3->rect.top = v4[1];
  v3->rect.right = v4[2];
  v3->rect.bottom = v4[3];
}


void __cdecl ActNpc233(NPCHAR_0 *npc)
{
  int v1;
  unsigned __int8 v2;
  NPCHAR_0 *v3;
  Sint32 *v4;
  RECT rect_right[4];
  RECT rect_left[4];
  unsigned __int8 deg;
  char v8[8];

  v1 = npc->act_no;
  if ( v1 == 1 )
  {
LABEL_5:
    if ( npc->pNpc->code_char == 232 )
    {
      npc->tgt_x = npc->pNpc->x;
      npc->tgt_y = npc->pNpc->y;
      npc->direct = npc->pNpc->direct;
    }
    if ( npc->tgt_x < npc->x )
      npc->xm -= 8;
    if ( npc->tgt_x > npc->x )
      npc->xm += 8;
    if ( npc->count2 + npc->tgt_y < npc->y )
      npc->ym -= 32;
    if ( npc->count2 + npc->tgt_y > npc->y )
      npc->ym += 32;
    if ( npc->xm > 1024 )
      npc->xm = 1024;
    if ( npc->xm < -1024 )
      npc->xm = -1024;
    if ( npc->ym > 1024 )
      npc->ym = 1024;
    if ( npc->ym < -1024 )
      npc->ym = -1024;
    if ( npc->count1 > 119 )
    {
      if ( npc->x - 4096 < x && npc->x + 4096 > x && npc->y < y && npc->y + 90112 > y )
      {
        npc->xm /= 4;
        npc->ym = 0;
        npc->act_no = 3;
        npc->bits &= 0xFFF7u;
      }
    }
    else
    {
      ++npc->count1;
    }
    goto LABEL_34;
  }
  if ( v1 != 3 )
  {
    if ( v1 )
      goto LABEL_34;
    npc->act_no = 1;
    v2 = Random(0, 255);
    npc->xm = GetCos(v2);
    deg = Random(0, 255);
    npc->ym = GetSin(deg);
    npc->count1 = 120;
    npc->count2 = Random(-32, 32) << 9;
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
LABEL_34:
  npc->x += npc->xm;
  npc->y += npc->ym;
  rect_left[0].left = 256;
  rect_left[0].top = 0;
  rect_left[0].right = 272;
  rect_left[0].bottom = 16;
  rect_left[1].left = 272;
  rect_left[1].top = 0;
  rect_left[1].right = 288;
  rect_left[1].bottom = 16;
  rect_left[2].left = 288;
  rect_left[2].top = 0;
  rect_left[2].right = 304;
  rect_left[2].bottom = 16;
  rect_left[3].left = 304;
  rect_left[3].top = 0;
  rect_left[3].right = 320;
  rect_left[3].bottom = 16;
  rect_right[0].left = 256;
  rect_right[0].top = 16;
  rect_right[0].right = 272;
  rect_right[0].bottom = 32;
  rect_right[1].left = 272;
  rect_right[1].top = 16;
  rect_right[1].right = 288;
  rect_right[1].bottom = 32;
  rect_right[2].left = 288;
  rect_right[2].top = 16;
  rect_right[2].right = 304;
  rect_right[2].bottom = 32;
  rect_right[3].left = 304;
  rect_right[3].top = 16;
  rect_right[3].right = 320;
  rect_right[3].bottom = 32;
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
    v3 = npc;
    v4 = (Sint32 *)&v8[16 * npc->ani_no - 132];
  }
  else
  {
    v3 = npc;
    v4 = (Sint32 *)&v8[16 * npc->ani_no - 68];
  }
  npc->rect.left = *v4;
  v3->rect.top = v4[1];
  v3->rect.right = v4[2];
  v3->rect.bottom = v4[3];
}


void __cdecl ActNpc234(NPCHAR_0 *npc)
{
  if ( !npc->act_no )
  {
    npc->act_no = 1;
    npc->y += 0x2000;
  }
  if ( npc->direct )
  {
    npc->rect.left = 144;
    npc->rect.top = 112;
    npc->rect.right = 192;
    npc->rect.bottom = 128;
  }
  else
  {
    npc->rect.left = 144;
    npc->rect.top = 96;
    npc->rect.right = 192;
    npc->rect.bottom = 112;
  }
}

void __cdecl ActNpc235(NPCHAR_0 *npc)
{
  NPCHAR_0 *v1;
  Sint32 *v2;
  RECT rcRight[4];
  RECT rcLeft[4];
  char v5[8];

  rcLeft[0].left = 192;
  rcLeft[0].top = 96;
  rcLeft[0].right = 208;
  rcLeft[0].bottom = 112;
  rcLeft[1].left = 208;
  rcLeft[1].top = 96;
  rcLeft[1].right = 224;
  rcLeft[1].bottom = 112;
  rcLeft[2].left = 224;
  rcLeft[2].top = 96;
  rcLeft[2].right = 240;
  rcLeft[2].bottom = 112;
  rcLeft[3].left = 192;
  rcLeft[3].top = 96;
  rcLeft[3].right = 208;
  rcLeft[3].bottom = 112;
  rcRight[0].left = 192;
  rcRight[0].top = 112;
  rcRight[0].right = 208;
  rcRight[0].bottom = 128;
  rcRight[1].left = 208;
  rcRight[1].top = 112;
  rcRight[1].right = 224;
  rcRight[1].bottom = 128;
  rcRight[2].left = 224;
  rcRight[2].top = 112;
  rcRight[2].right = 240;
  rcRight[2].bottom = 128;
  rcRight[3].left = 192;
  rcRight[3].top = 112;
  rcRight[3].right = 208;
  rcRight[3].bottom = 128;
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
      if ( Random(0, 30) == 1 )
      {
        npc->act_no = 2;
        npc->act_wait = 0;
        npc->ani_no = 1;
      }
      if ( Random(0, 30) == 1 )
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
        npc->xm = 1024;
      else
        npc->xm = -1024;
      if ( ++npc->ani_wait > 1 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 3 )
        npc->ani_no = 2;
      if ( ++npc->act_wait > 64 )
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
  if ( npc->ani_no == 2 )
    npc->hit.top = 2560;
  else
    npc->hit.top = 2048;
  if ( npc->direct )
  {
    v1 = npc;
    v2 = (Sint32 *)&v5[16 * npc->ani_no - 128];
  }
  else
  {
    v1 = npc;
    v2 = (Sint32 *)&v5[16 * npc->ani_no - 64];
  }
  npc->rect.left = *v2;
  v1->rect.top = v2[1];
  v1->rect.right = v2[2];
  v1->rect.bottom = v2[3];
}


void __cdecl ActNpc236(NPCHAR_0 *npc)
{
  int v1;
  NPCHAR_0 *v2;
  Sint32 *v3;
  RECT rcRight[6];
  RECT rcLeft[6];
  char v6[24];

  qmemcpy(rcLeft, &ActNpc236(NPCHAR *)::C.14, sizeof(rcLeft));
  qmemcpy(rcRight, &ActNpc236(NPCHAR *)::C.15, sizeof(rcRight));
  switch ( npc->act_no )
  {
    case 0:
      npc->act_no = 1;
      npc->act_wait = Random(0, 50);
      npc->tgt_x = npc->x;
      npc->tgt_y = npc->y;
      npc->ym = 0;
      goto LABEL_3;
    case 1:
LABEL_3:
      if ( npc->act_wait )
      {
        --npc->act_wait;
      }
      else
      {
        npc->ym = 512;
        npc->act_no = 2;
      }
      break;
    case 2:
      if ( npc->x >= x )
        npc->direct = 0;
      else
        npc->direct = 2;
      if ( x < npc->x + 0x10000 && x > npc->x - 0x10000 && y < npc->y + 0x4000 && y > npc->y - 81920 )
        ++npc->act_wait;
      if ( npc->act_wait > 80 )
      {
        npc->act_no = 10;
        npc->act_wait = 0;
      }
      if ( ++npc->ani_wait > 1 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 1 )
        npc->ani_no = 0;
      break;
    case 0xA:
      if ( ++npc->act_wait > 20 )
      {
        npc->act_wait = 0;
        npc->act_no = 20;
      }
      if ( ++npc->ani_wait > 1 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 3 )
        npc->ani_no = 2;
      break;
    case 0x14:
      if ( ++npc->act_wait > 60 )
      {
        npc->act_wait = 0;
        npc->act_no = 2;
      }
      if ( npc->act_wait % 10 == 3 )
      {
        PlaySoundObject(39, 1);
        if ( npc->direct )
          SetNpChar(237, npc->x + 4096, npc->y - 4096, 1024, -1024, 0, 0, 256);
        else
          SetNpChar(237, npc->x - 4096, npc->y - 4096, -1024, -1024, 0, 0, 256);
      }
      if ( ++npc->ani_wait > 1 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 5 )
        npc->ani_no = 4;
      break;
    default:
      break;
  }
  if ( npc->y >= npc->tgt_y )
    v1 = npc->ym - 16;
  else
    v1 = npc->ym + 16;
  npc->ym = v1;
  if ( npc->ym > 256 )
    npc->ym = 256;
  if ( npc->ym < -256 )
    npc->ym = -256;
  npc->y += npc->ym;
  if ( npc->direct )
  {
    v2 = npc;
    v3 = (Sint32 *)&v6[16 * npc->ani_no - 192];
  }
  else
  {
    v2 = npc;
    v3 = (Sint32 *)&v6[16 * npc->ani_no - 96];
  }
  npc->rect.left = *v3;
  v2->rect.top = v3[1];
  v2->rect.right = v3[2];
  v2->rect.bottom = v3[3];
}


void __cdecl ActNpc237(NPCHAR_0 *npc)
{
  int v1;
  int i;
  bool bHit;

  v1 = npc->act_no;
  if ( v1 )
  {
    if ( v1 != 1 )
      goto LABEL_15;
  }
  else
  {
    npc->act_no = 1;
  }
  bHit = 0;
  ++npc->act_wait;
  if ( npc->flag & 0xFF )
    bHit = 1;
  if ( npc->act_wait > 10 && npc->flag & 0x100 )
    bHit = 1;
  if ( bHit )
  {
    for ( i = 0; i <= 4; ++i )
      SetCaret(npc->x, npc->y, 1, 0);
    PlaySoundObject(21, 1);
    npc->cond = 0;
    return;
  }
LABEL_15:
  npc->ym += 32;
  if ( npc->ym > 1535 )
    npc->ym = 1535;
  npc->x += npc->xm;
  npc->y += npc->ym;
  npc->rect.left = 312;
  npc->rect.top = 32;
  npc->rect.right = 320;
  npc->rect.bottom = 40;
}

void __cdecl ActNpc238(NPCHAR_0 *npc)
{
  int v1;
  int v2;
  int v3;
  int v4;
  int v5;
  int v6;
  Sint32 *v7;
  RECT rc[3];
  int i;
  char v10[8];

  rc[0].left = 184;
  rc[0].top = 200;
  rc[0].right = 208;
  rc[0].bottom = 216;
  rc[1].left = 208;
  rc[1].top = 200;
  rc[1].right = 232;
  rc[1].bottom = 216;
  rc[2].left = 232;
  rc[2].top = 200;
  rc[2].right = 256;
  rc[2].bottom = 216;
  switch ( npc->act_no )
  {
    case 0:
      npc->act_no = 1;
      npc->tgt_x = npc->x;
      npc->tgt_y = npc->y;
      npc->view.front = 0x2000;
      npc->view.back = 4096;
      goto LABEL_3;
    case 1:
LABEL_3:
      if ( !npc->direct && x < npc->x && x > npc->x - 98304 && y > npc->y - 2048 && y < npc->y + 4096 )
      {
        npc->act_no = 10;
        npc->act_wait = 0;
        npc->ani_no = 2;
      }
      if ( npc->direct == 2 && x > npc->x && x < npc->x + 98304 && y > npc->y - 2048 && y < npc->y + 4096 )
      {
        npc->act_no = 10;
        npc->act_wait = 0;
        npc->ani_no = 2;
      }
      break;
    case 0xA:
      npc->damage = 127;
      if ( npc->direct )
        v1 = npc->x + 3072;
      else
        v1 = npc->x - 3072;
      npc->x = v1;
      if ( ++npc->act_wait == 8 )
      {
        npc->act_no = 20;
        npc->act_wait = 0;
        for ( i = 0; i <= 3; ++i )
        {
          v2 = npc->y;
          v3 = (Random(-8, 8) << 9) + v2;
          v4 = npc->x;
          v5 = Random(-16, 16);
          SetNpChar(4, v4 + (v5 << 9), v3, 0, 0, 0, 0, 256);
          PlaySoundObject(12, 1);
        }
      }
      break;
    case 0x14:
      npc->damage = 0;
      if ( ++npc->act_wait > 50 )
      {
        npc->act_wait = 0;
        npc->act_no = 30;
      }
      break;
    case 0x1E:
      npc->damage = 0;
      npc->ani_no = 1;
      if ( ++npc->act_wait == 12 )
      {
        npc->act_no = 1;
        npc->act_wait = 0;
        npc->ani_no = 0;
      }
      if ( npc->direct )
        v6 = npc->x - 2048;
      else
        v6 = npc->x + 2048;
      npc->x = v6;
      break;
    default:
      break;
  }
  if ( npc->direct || x >= npc->x )
  {
    if ( npc->direct != 2 || x <= npc->x )
      npc->hit.back = 4096;
    else
      npc->hit.back = 0x2000;
  }
  else
  {
    npc->hit.back = 0x2000;
  }
  v7 = (Sint32 *)&v10[16 * npc->ani_no - 52];
  npc->rect.left = *v7;
  npc->rect.top = v7[1];
  npc->rect.right = v7[2];
  npc->rect.bottom = v7[3];
}


void __cdecl ActNpc239(NPCHAR_0 *npc)
{
  if ( !npc->act_no )
  {
    npc->act_no = 1;
    if ( npc->direct )
    {
      npc->view.front = 12288;
      npc->view.back = 12288;
      npc->view.top = 4096;
      npc->view.back = 12288;
    }
    else
    {
      npc->x += 4096;
      npc->y += 0x2000;
    }
  }
  if ( npc->direct )
  {
    npc->rect.left = 96;
    npc->rect.top = 112;
    npc->rect.right = 144;
    npc->rect.bottom = 144;
  }
  else
  {
    npc->rect.left = 192;
    npc->rect.top = 48;
    npc->rect.right = 256;
    npc->rect.bottom = 80;
  }
}

