#include "types.h"
#include "SDL_stdinc.h"
#include "windows_wrapper.h"
#include "Tags.h"
#include "forNpc.h"
void __cdecl ActNpc040(NPCHAR_0 *npc)
{
  int v1;
  NPCHAR_0 *v2;
  Sint32 *v3;
  RECT rcRight[7];
  RECT rcLeft[7];
  char v6[24];

  qmemcpy(rcLeft, &ActNpc040(NPCHAR *)::C.0, sizeof(rcLeft));
  qmemcpy(rcRight, &ActNpc040(NPCHAR *)::C.1, sizeof(rcRight));
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
      if ( npc->x - 0x4000 < x && npc->x + 0x4000 > x && npc->y - 0x4000 < y && npc->y + 0x2000 > y )
      {
        if ( npc->x <= x )
          npc->direct = 2;
        else
          npc->direct = 0;
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
      goto LABEL_15;
    case 4:
LABEL_15:
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
    default:
      break;
  }
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
}


void __cdecl ActNpc041(NPCHAR_0 *npc)
{
  if ( !npc->act_no )
  {
    ++npc->act_no;
    npc->y -= 0x2000;
  }
  npc->rect.left = 0;
  npc->rect.top = 80;
  npc->rect.right = 48;
  npc->rect.bottom = 112;
}

void __cdecl ActNpc042(NPCHAR_0 *npc)
{
  int v1;
  NPCHAR_0 *v2;
  Sint32 *v3;
  RECT rcRight[13];
  RECT rcLeft[13];
  int n;
  char v7[24];

  qmemcpy(rcLeft, &ActNpc042(NPCHAR *)::C.3, sizeof(rcLeft));
  qmemcpy(rcRight, &ActNpc042(NPCHAR *)::C.4, sizeof(rcRight));
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
        npc->xm = 512;
      else
        npc->xm = -512;
      break;
    case 5:
      npc->ani_no = 6;
      npc->xm = 0;
      break;
    case 6:
      PlaySoundObject(50, 1);
      npc->act_wait = 0;
      npc->act_no = 7;
      npc->ani_no = 7;
      goto LABEL_17;
    case 7:
LABEL_17:
      if ( ++npc->act_wait > 10 )
        npc->act_no = 0;
      break;
    case 8:
      PlaySoundObject(50, 1);
      npc->act_wait = 0;
      npc->act_no = 9;
      npc->ani_no = 7;
      npc->ym = -512;
      if ( npc->direct )
        npc->xm = -1024;
      else
        npc->xm = 1024;
      goto LABEL_22;
    case 9:
LABEL_22:
      if ( ++npc->act_wait > 3 && npc->flag & 8 )
      {
        npc->act_no = 10;
        if ( npc->direct )
          npc->direct = 0;
        else
          npc->direct = 2;
      }
      break;
    case 0xA:
      npc->xm = 0;
      npc->ani_no = 8;
      break;
    case 0xB:
      npc->act_no = 12;
      npc->act_wait = 0;
      npc->ani_no = 9;
      npc->ani_wait = 0;
      npc->xm = 0;
      goto LABEL_29;
    case 0xC:
LABEL_29:
      if ( ++npc->ani_wait > 8 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 10 )
        npc->ani_no = 9;
      break;
    case 0xD:
      npc->ani_no = 11;
      npc->xm = 0;
      npc->ym = 0;
      npc->act_no = 14;
      for ( n = 0; n <= 511 && gNPC[n].code_event != 501; ++n )
        ;
      if ( n == 512 )
      {
        npc->act_no = 0;
      }
      else
      {
        npc->pNpc = &gNPC[n];
LABEL_40:
        if ( npc->pNpc->direct )
          npc->direct = 0;
        else
          npc->direct = 2;
        if ( npc->pNpc->direct )
          v1 = npc->pNpc->x + 3072;
        else
          v1 = npc->pNpc->x - 3072;
        npc->x = v1;
        npc->y = npc->pNpc->y + 2048;
        if ( npc->pNpc->ani_no == 2 || npc->pNpc->ani_no == 4 )
          npc->y -= 512;
      }
      break;
    case 0xE:
      goto LABEL_40;
    case 0xF:
      npc->act_no = 16;
      SetNpChar(257, npc->x + 0x10000, npc->y, 0, 0, 0, 0, 0);
      SetNpChar(257, npc->x + 0x10000, npc->y, 0, 0, 2, 0, 128);
      npc->xm = 0;
      npc->ani_no = 0;
      goto LABEL_50;
    case 0x10:
LABEL_50:
      gSuperXpos = npc->x - 12288;
      gSuperYpos = npc->y - 4096;
      break;
    case 0x11:
      npc->xm = 0;
      npc->ani_no = 12;
      gSuperXpos = npc->x;
      gSuperYpos = npc->y - 4096;
      break;
    case 0x14:
      npc->act_no = 21;
      npc->ani_no = 2;
      npc->ani_wait = 0;
      goto LABEL_53;
    case 0x15:
LABEL_53:
      if ( ++npc->ani_wait > 2 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 5 )
        npc->ani_no = 2;
      if ( npc->direct )
        npc->xm = 1024;
      else
        npc->xm = -1024;
      if ( npc->x < x - 4096 )
      {
        npc->direct = 2;
        npc->act_no = 0;
      }
      break;
    case 0x1E:
      npc->act_no = 31;
      npc->ani_no = 2;
      npc->ani_wait = 0;
      goto LABEL_63;
    case 0x1F:
LABEL_63:
      if ( ++npc->ani_wait > 2 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 5 )
        npc->ani_no = 2;
      if ( npc->direct )
        npc->xm = 1024;
      else
        npc->xm = -1024;
      break;
    case 0x28:
      npc->act_no = 41;
      npc->ani_no = 9;
      npc->ym = -1024;
      break;
    default:
      break;
  }
  if ( npc->act_no != 14 )
  {
    npc->ym += 64;
    if ( npc->xm > 1024 )
      npc->xm = 1024;
    if ( npc->xm < -1024 )
      npc->xm = -1024;
    if ( npc->ym > 1535 )
      npc->ym = 1535;
    npc->x += npc->xm;
    npc->y += npc->ym;
  }
  if ( npc->direct )
  {
    v2 = npc;
    v3 = (Sint32 *)&v7[16 * npc->ani_no - 420];
  }
  else
  {
    v2 = npc;
    v3 = (Sint32 *)&v7[16 * npc->ani_no - 212];
  }
  npc->rect.left = *v3;
  v2->rect.top = v3[1];
  v2->rect.right = v3[2];
  v2->rect.bottom = v3[3];
}


void __cdecl ActNpc043(NPCHAR_0 *npc)
{
  if ( !npc->act_no )
  {
    npc->act_no = 1;
    npc->y -= 0x2000;
  }
  if ( npc->direct )
  {
    npc->rect.left = 168;
    npc->rect.top = 80;
    npc->rect.right = 208;
  }
  else
  {
    npc->rect.left = 128;
    npc->rect.top = 80;
    npc->rect.right = 168;
  }
  npc->rect.bottom = 112;
}

void __cdecl ActNpc044(NPCHAR_0 *npc)
{
  int v1;
  int v2;
  NPCHAR_0 *v3;
  Sint32 *v4;
  RECT rcLeft[3];
  RECT rcRight[3];
  int i;
  char v8[8];

  rcRight[0].left = 0;
  rcRight[0].top = 0;
  rcRight[0].right = 32;
  rcRight[0].bottom = 32;
  rcRight[1].left = 32;
  rcRight[1].top = 0;
  rcRight[1].right = 64;
  rcRight[1].bottom = 32;
  rcRight[2].left = 64;
  rcRight[2].top = 0;
  rcRight[2].right = 96;
  rcRight[2].bottom = 32;
  rcLeft[0].left = 0;
  rcLeft[0].top = 0;
  rcLeft[0].right = 32;
  rcLeft[0].bottom = 32;
  rcLeft[1].left = 96;
  rcLeft[1].top = 0;
  rcLeft[1].right = 128;
  rcLeft[1].bottom = 32;
  rcLeft[2].left = 128;
  rcLeft[2].top = 0;
  rcLeft[2].right = 160;
  rcLeft[2].bottom = 32;
  switch ( npc->act_no )
  {
    case 0:
      npc->act_no = 1;
      goto LABEL_3;
    case 1:
LABEL_3:
      npc->ani_no = 0;
      if ( npc->direct )
        npc->act_no = 2;
      else
        npc->act_no = 8;
      goto LABEL_6;
    case 2:
LABEL_6:
      npc->ym += 32;
      if ( npc->ym > 0 && npc->flag & 8 )
      {
        npc->ym = -256;
        npc->xm += 256;
      }
      if ( npc->flag & 4 )
        npc->act_no = 3;
      break;
    case 3:
      npc->xm += 32;
      if ( npc->xm > 0 && npc->flag & 4 )
      {
        npc->xm = -256;
        npc->ym -= 256;
      }
      if ( npc->flag & 2 )
        npc->act_no = 4;
      break;
    case 4:
      npc->ym -= 32;
      if ( npc->ym < 0 && npc->flag & 2 )
      {
        npc->ym = 256;
        npc->xm -= 256;
      }
      if ( npc->flag & 1 )
        npc->act_no = 5;
      break;
    case 5:
      npc->xm -= 32;
      if ( npc->xm < 0 && npc->flag & 1 )
      {
        npc->xm = 256;
        npc->ym += 256;
      }
      if ( npc->flag & 8 )
        npc->act_no = 2;
      break;
    case 6:
      npc->ym += 32;
      if ( npc->ym > 0 && npc->flag & 8 )
      {
        npc->ym = -256;
        npc->xm -= 256;
      }
      if ( npc->flag & 1 )
        npc->act_no = 7;
      break;
    case 7:
      npc->xm -= 32;
      if ( npc->xm < 0 && npc->flag & 1 )
      {
        npc->xm = 256;
        npc->ym -= 256;
      }
      if ( npc->flag & 2 )
        npc->act_no = 8;
      break;
    case 8:
      npc->ym -= 32;
      if ( npc->ym < 0 && npc->flag & 2 )
      {
        npc->ym = 256;
        npc->xm += 256;
      }
      if ( npc->flag & 4 )
        npc->act_no = 9;
      break;
    case 9:
      npc->xm += 32;
      if ( npc->xm > 0 && npc->flag & 4 )
      {
        npc->xm = -256;
        npc->ym += 256;
      }
      if ( npc->flag & 8 )
        npc->act_no = 6;
      break;
    default:
      break;
  }
  if ( npc->life <= 100 )
  {
    for ( i = 0; i <= 9; ++i )
      SetNpChar(45, npc->x, npc->y, 0, 0, 0, 0, 256);
    SetDestroyNpChar(npc->x, npc->y, npc->view.back, 8);
    PlaySoundObject(25, 1);
    npc->cond = 0;
  }
  if ( npc->xm > 512 )
    npc->xm = 512;
  if ( npc->xm < -512 )
    npc->xm = -512;
  if ( npc->ym > 512 )
    npc->ym = 512;
  if ( npc->ym < -512 )
    npc->ym = -512;
  if ( npc->shock )
  {
    npc->x += npc->xm / 2;
    v1 = npc->y;
    v2 = npc->ym / 2;
  }
  else
  {
    npc->x += npc->xm;
    v1 = npc->y;
    v2 = npc->ym;
  }
  npc->y = v2 + v1;
  if ( npc->act_no > 1 && npc->act_no <= 9 && ++npc->ani_no > 2 )
    npc->ani_no = 1;
  if ( npc->direct )
  {
    v3 = npc;
    v4 = (Sint32 *)&v8[16 * npc->ani_no - 52];
  }
  else
  {
    v3 = npc;
    v4 = (Sint32 *)&v8[16 * npc->ani_no - 100];
  }
  npc->rect.left = *v4;
  v3->rect.top = v4[1];
  v3->rect.right = v4[2];
  v3->rect.bottom = v4[3];
}


void __cdecl ActNpc045(NPCHAR_0 *npc)
{
  int v1;
  int v2;
  int v3;
  int v4;
  int v5;
  Sint32 *v6;
  RECT rect[3];
  char v8[8];

  rect[0].left = 0;
  rect[0].top = 32;
  rect[0].right = 16;
  rect[0].bottom = 48;
  rect[1].left = 16;
  rect[1].top = 32;
  rect[1].right = 32;
  rect[1].bottom = 48;
  rect[2].left = 32;
  rect[2].top = 32;
  rect[2].right = 48;
  rect[2].bottom = 48;
  v1 = npc->act_no;
  if ( v1 )
  {
    if ( v1 < 0 || v1 > 2 )
      goto LABEL_14;
  }
  else
  {
    npc->act_no = 2;
    if ( Random(0, 1) != 0 )
      v2 = Random(-512, -256);
    else
      v2 = Random(256, 512);
    npc->xm = v2;
    if ( Random(0, 1) != 0 )
      v3 = Random(-512, -256);
    else
      v3 = Random(256, 512);
    npc->ym = v3;
    npc->xm2 = npc->xm;
    npc->ym2 = npc->ym;
  }
  if ( ++npc->ani_no > 2 )
    npc->ani_no = 1;
LABEL_14:
  if ( npc->xm2 < 0 && npc->flag & 1 )
    npc->xm2 = -npc->xm2;
  if ( npc->xm2 > 0 && npc->flag & 4 )
    npc->xm2 = -npc->xm2;
  if ( npc->ym2 < 0 && npc->flag & 2 )
    npc->ym2 = -npc->ym2;
  if ( npc->ym2 > 0 && npc->flag & 8 )
    npc->ym2 = -npc->ym2;
  if ( npc->xm2 > 512 )
    npc->xm2 = 512;
  if ( npc->xm2 < -512 )
    npc->xm2 = -512;
  if ( npc->ym2 > 512 )
    npc->ym2 = 512;
  if ( npc->ym2 < -512 )
    npc->ym2 = -512;
  if ( npc->shock )
  {
    npc->x += npc->xm2 / 2;
    v4 = npc->y;
    v5 = npc->ym2 / 2;
  }
  else
  {
    npc->x += npc->xm2;
    v4 = npc->y;
    v5 = npc->ym2;
  }
  npc->y = v5 + v4;
  v6 = (Sint32 *)&v8[16 * npc->ani_no - 48];
  npc->rect.left = *v6;
  npc->rect.top = v6[1];
  npc->rect.right = v6[2];
  npc->rect.bottom = v6[3];
}


void __cdecl ActNpc046(NPCHAR_0 *npc)
{
  unsigned __int16 v1;
  int v2;
  int v3;

  v1 = npc->bits;
  HIBYTE(v1) |= 1u;
  npc->bits = v1;
  if ( npc->direct )
  {
    if ( npc->y >= y )
      v3 = npc->y - 1535;
    else
      v3 = npc->y + 1535;
    npc->y = v3;
  }
  else
  {
    if ( npc->x >= x )
      v2 = npc->x - 1535;
    else
      v2 = npc->x + 1535;
    npc->x = v2;
  }
  npc->rect.left = 0;
  npc->rect.top = 0;
  npc->rect.right = 16;
  npc->rect.bottom = 16;
}

void __cdecl ActNpc047(NPCHAR_0 *npc)
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
      if ( x > npc->x - 4096 && x < npc->x + 4096 && y > npc->y && y < npc->y + 4096 )
      {
        npc->act_no = 2;
        npc->act_wait = 0;
        PlaySoundObject(102, 1);
      }
      if ( npc->x < x )
        npc->x += 1024;
      if ( npc->x > x )
        npc->x -= 1024;
      break;
    case 2:
      if ( ++npc->ani_wait > 3 )
      {
        ++npc->ani_no;
        npc->ani_wait = 0;
      }
      if ( npc->ani_no == 3 )
        npc->damage = 10;
      if ( npc->ani_no == 4 )
      {
        npc->bits |= 0x20u;
        npc->act_no = 3;
        npc->act_wait = 0;
      }
      break;
    case 3:
      npc->bits |= 1u;
      npc->damage = 0;
      ++npc->act_wait;
      if ( npc->shock )
      {
        npc->act_no = 4;
        npc->act_wait = 0;
      }
      break;
    case 4:
      npc->bits |= 8u;
      npc->y += 512;
      if ( ++npc->act_wait == 32 )
      {
        npc->bits &= 0xFFFEu;
        npc->bits &= 0xFFDFu;
        npc->act_no = 5;
        npc->act_wait = 0;
      }
      break;
    case 5:
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
  qmemcpy(rect, &ActNpc047(NPCHAR *)::C.14, sizeof(rect));
  v1 = (Sint32 *)&v3[16 * npc->ani_no - 80];
  npc->rect.left = *v1;
  npc->rect.top = v1[1];
  npc->rect.right = v1[2];
  npc->rect.bottom = v1[3];
}


void __cdecl ActNpc048(NPCHAR_0 *npc)
{
  NPCHAR_0 *v1;
  Sint32 *v2;
  RECT rcRight[2];
  RECT rcLeft[2];
  char v5[8];

  if ( npc->flag & 1 && npc->xm < 0 )
  {
    npc->xm = -npc->xm;
  }
  else if ( npc->flag & 4 && npc->xm > 0 )
  {
    npc->xm = -npc->xm;
  }
  else if ( npc->flag & 8 )
  {
    if ( ++npc->count1 <= 2 && npc->direct != 2 )
    {
      npc->ym = -256;
    }
    else
    {
      VanishNpChar(npc);
      SetCaret(npc->x, npc->y, 2, 0);
    }
  }
  if ( npc->direct == 2 )
  {
    npc->bits &= 0xFFDFu;
    npc->bits |= 4u;
  }
  npc->ym += 5;
  npc->y += npc->ym;
  npc->x += npc->xm;
  rcLeft[0].left = 288;
  rcLeft[0].top = 88;
  rcLeft[0].right = 304;
  rcLeft[0].bottom = 104;
  rcLeft[1].left = 304;
  rcLeft[1].top = 88;
  rcLeft[1].right = 320;
  rcLeft[1].bottom = 104;
  rcRight[0].left = 288;
  rcRight[0].top = 104;
  rcRight[0].right = 304;
  rcRight[0].bottom = 120;
  rcRight[1].left = 304;
  rcRight[1].top = 104;
  rcRight[1].right = 320;
  rcRight[1].bottom = 120;
  if ( ++npc->ani_wait > 2 )
  {
    npc->ani_wait = 0;
    if ( ++npc->ani_no > 1 )
      npc->ani_no = 0;
  }
  if ( ++npc->act_wait > 750 )
  {
    SetCaret(npc->x, npc->y, 2, 0);
    npc->cond = 0;
  }
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
}


void __cdecl ActNpc049(NPCHAR_0 *npc)
{
  NPCHAR_0 *v1;
  Sint32 *v2;
  RECT rcRight[3];
  RECT rcLeft[3];
  unsigned __int8 deg;
  int xm;
  int ym;
  char v8[8];

  if ( npc->act_no > 9 && npc->pNpc->code_char == 3 )
  {
    npc->act_no = 3;
    npc->xm = 0;
    npc->ym = 0;
    npc->count2 = 1;
  }
  if ( npc->flag & 1 )
  {
    npc->direct = 2;
    npc->xm = 256;
  }
  if ( npc->flag & 4 )
  {
    npc->direct = 0;
    npc->xm = -256;
  }
  switch ( npc->act_no )
  {
    case 0:
      if ( npc->pNpc )
        npc->act_no = 10;
      else
        npc->act_no = 1;
      goto LABEL_12;
    case 1:
LABEL_12:
      if ( ++npc->act_wait > 3 )
      {
        npc->ym = -1024;
        npc->act_no = 3;
        npc->ani_no = 2;
        if ( npc->count2 )
        {
          if ( npc->direct )
            npc->xm = 512;
          else
            npc->xm = -512;
        }
        else if ( npc->direct )
        {
          npc->xm = 256;
        }
        else
        {
          npc->xm = -256;
        }
      }
      npc->ani_no = 1;
      break;
    case 3:
      if ( npc->flag & 8 )
      {
        npc->act_no = 1;
        npc->act_wait = 0;
        npc->xm = 0;
      }
      if ( npc->flag & 8 || npc->ym > 0 )
        npc->ani_no = 1;
      else
        npc->ani_no = 2;
      break;
    case 0xA:
      if ( npc->count1 > 49 )
      {
        if ( npc->x - 0x10000 < x && npc->x + 0x10000 > x && npc->y - 49152 < y && npc->y + 49152 > y )
        {
          npc->act_no = 11;
          npc->act_wait = 0;
          npc->ani_no = 2;
        }
      }
      else
      {
        ++npc->count1;
      }
      break;
    case 0xB:
      if ( ++npc->act_wait == 30 || npc->act_wait == 35 )
      {
        deg = GetArktan(npc->x - x, npc->y + 2048 - y);
        ym = 2 * GetSin(deg);
        xm = 2 * GetCos(deg);
        SetNpChar(50, npc->x, npc->y, xm, ym, 0, 0, 256);
        PlaySoundObject(39, 1);
      }
      if ( npc->act_wait > 50 )
      {
        npc->count1 = 0;
        npc->act_no = 10;
        npc->ani_no = 1;
      }
      break;
    default:
      break;
  }
  if ( npc->act_no > 9 )
  {
    npc->x = npc->pNpc->x;
    npc->y = npc->pNpc->y + 0x2000;
    npc->direct = npc->pNpc->direct;
    --npc->pNpc->count1;
  }
  npc->ym += 64;
  if ( npc->ym > 1535 )
    npc->ym = 1535;
  npc->x += npc->xm;
  npc->y += npc->ym;
  rcLeft[0].left = 0;
  rcLeft[0].top = 80;
  rcLeft[0].right = 32;
  rcLeft[0].bottom = 104;
  rcLeft[1].left = 32;
  rcLeft[1].top = 80;
  rcLeft[1].right = 64;
  rcLeft[1].bottom = 104;
  rcLeft[2].left = 64;
  rcLeft[2].top = 80;
  rcLeft[2].right = 96;
  rcLeft[2].bottom = 104;
  rcRight[0].left = 0;
  rcRight[0].top = 104;
  rcRight[0].right = 32;
  rcRight[0].bottom = 128;
  rcRight[1].left = 32;
  rcRight[1].top = 104;
  rcRight[1].right = 64;
  rcRight[1].bottom = 128;
  rcRight[2].left = 64;
  rcRight[2].top = 104;
  rcRight[2].right = 96;
  rcRight[2].bottom = 128;
  if ( npc->direct )
  {
    v1 = npc;
    v2 = (Sint32 *)&v8[16 * npc->ani_no - 108];
  }
  else
  {
    v1 = npc;
    v2 = (Sint32 *)&v8[16 * npc->ani_no - 60];
  }
  npc->rect.left = *v2;
  v1->rect.top = v2[1];
  v1->rect.right = v2[2];
  v1->rect.bottom = v2[3];
}


void __cdecl ActNpc050(NPCHAR_0 *npc)
{
  int v1;
  Sint32 *v2;
  RECT rect[4];
  char v4[8];

  v1 = npc->act_no;
  if ( v1 == 1 )
  {
LABEL_6:
    npc->x += npc->xm;
    npc->y += npc->ym;
    if ( npc->flag & 1 )
    {
      npc->act_no = 2;
      npc->xm = 512;
      ++npc->count1;
    }
    if ( npc->flag & 4 )
    {
      npc->act_no = 2;
      npc->xm = -512;
      ++npc->count1;
    }
    if ( npc->flag & 2 )
    {
      npc->act_no = 2;
      npc->ym = 512;
      ++npc->count1;
    }
    if ( npc->flag & 8 )
    {
      npc->act_no = 2;
      npc->ym = -512;
      ++npc->count1;
    }
    goto LABEL_17;
  }
  if ( v1 != 2 )
  {
    if ( v1 )
      goto LABEL_17;
    if ( npc->direct == 2 )
      npc->act_no = 2;
    goto LABEL_6;
  }
  npc->ym += 64;
  npc->x += npc->xm;
  npc->y += npc->ym;
  if ( npc->flag & 8 )
  {
    if ( ++npc->count1 > 1 )
    {
      SetCaret(npc->x, npc->y, 2, 0);
      npc->cond = 0;
    }
  }
LABEL_17:
  if ( npc->ym > 1535 )
    npc->ym = 1535;
  if ( npc->ym < -1535 )
    npc->ym = -1535;
  rect[0].left = 48;
  rect[0].top = 32;
  rect[0].right = 64;
  rect[0].bottom = 48;
  rect[1].left = 64;
  rect[1].top = 32;
  rect[1].right = 80;
  rect[1].bottom = 48;
  rect[2].left = 80;
  rect[2].top = 32;
  rect[2].right = 96;
  rect[2].bottom = 48;
  rect[3].left = 96;
  rect[3].top = 32;
  rect[3].right = 112;
  rect[3].bottom = 48;
  if ( npc->direct )
  {
    if ( ++npc->ani_wait > 1 )
    {
      npc->ani_wait = 0;
      --npc->ani_no;
    }
    if ( npc->ani_no < 0 )
      npc->ani_no = 3;
  }
  else
  {
    if ( ++npc->ani_wait > 1 )
    {
      npc->ani_wait = 0;
      ++npc->ani_no;
    }
    if ( npc->ani_no > 3 )
      npc->ani_no = 0;
  }
  v2 = (Sint32 *)&v4[16 * npc->ani_no - 64];
  npc->rect.left = *v2;
  npc->rect.top = v2[1];
  npc->rect.right = v2[2];
  npc->rect.bottom = v2[3];
}


void __cdecl ActNpc051(NPCHAR_0 *npc)
{
  int v1;
  int v2;
  NPCHAR_0 *v3;
  Sint32 *v4;
  RECT rect_right[5];
  RECT rect_left[5];
  char v7[24];

  v1 = npc->act_no;
  if ( v1 == 1 )
  {
LABEL_9:
    if ( x >= npc->x )
      npc->direct = 2;
    else
      npc->direct = 0;
    if ( npc->tgt_y < npc->y )
      npc->ym -= 10;
    if ( npc->tgt_y > npc->y )
      npc->ym += 10;
    if ( npc->ym > 512 )
      npc->ym = 512;
    if ( npc->ym < -512 )
      npc->ym = -512;
    if ( npc->count1 > 9 )
      npc->act_no = 2;
    else
      ++npc->count1;
    goto LABEL_41;
  }
  if ( v1 != 2 )
  {
    if ( v1 || npc->x - 163840 >= x || npc->x + 163840 <= x || npc->y - 163840 >= y || npc->y + 163840 <= y )
      goto LABEL_41;
    npc->tgt_x = npc->x;
    npc->tgt_y = npc->y;
    v2 = npc->direct;
    npc->ym = 1024;
    npc->act_no = 1;
    SetNpChar(49, 0, 0, 0, 0, 0, npc, 0);
    goto LABEL_9;
  }
  if ( x >= npc->x )
    npc->direct = 2;
  else
    npc->direct = 0;
  if ( npc->y <= y + 0x4000 )
  {
    if ( x < npc->x )
      npc->xm -= 16;
    if ( x > npc->x )
      npc->xm += 16;
  }
  else
  {
    if ( x < npc->x )
      npc->xm += 16;
    if ( x > npc->x )
      npc->xm -= 16;
  }
  if ( y < npc->y )
    npc->ym -= 16;
  if ( y > npc->y )
    npc->ym += 16;
  if ( npc->shock )
  {
    npc->ym += 32;
    npc->xm = 0;
  }
LABEL_41:
  if ( npc->xm < 0 && npc->flag & 1 )
    npc->xm = 256;
  if ( npc->xm > 0 && npc->flag & 4 )
    npc->xm = -256;
  if ( npc->ym < 0 && npc->flag & 2 )
    npc->ym = 256;
  if ( npc->ym > 0 && npc->flag & 8 )
    npc->ym = -256;
  if ( npc->xm > 1024 )
    npc->xm = 1024;
  if ( npc->xm < -1024 )
    npc->xm = -1024;
  if ( npc->ym > 512 )
    npc->ym = 512;
  if ( npc->ym < -512 )
    npc->ym = -512;
  npc->x += npc->xm;
  npc->y += npc->ym;
  qmemcpy(rect_left, &ActNpc051(NPCHAR *)::C.16, sizeof(rect_left));
  qmemcpy(rect_right, &ActNpc051(NPCHAR *)::C.17, sizeof(rect_right));
  if ( npc->shock )
  {
    npc->ani_no = 4;
  }
  else if ( npc->act_no != 2 || npc->y >= y - 0x4000 )
  {
    if ( npc->act_no )
    {
      if ( ++npc->ani_wait > 1 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 1 )
        npc->ani_no = 0;
    }
  }
  else
  {
    npc->ani_no = 0;
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


void __cdecl ActNpc052(NPCHAR_0 *npc)
{
  npc->rect.left = 240;
  npc->rect.top = 96;
  npc->rect.right = 256;
  npc->rect.bottom = 112;
}

void __cdecl ActNpc053(NPCHAR_0 *npc)
{
  int v1;
  NPCHAR *v2;
  int v3;
  int v4;
  int v5;
  NPCHAR_0 *v6;
  Sint32 *v7;
  RECT rcRight[2];
  RECT rcLeft[2];
  unsigned __int8 deg;
  char v11[8];

  rcLeft[0].left = 0;
  rcLeft[0].top = 128;
  rcLeft[0].right = 24;
  rcLeft[0].bottom = 144;
  rcLeft[1].left = 24;
  rcLeft[1].top = 128;
  rcLeft[1].right = 48;
  rcLeft[1].bottom = 144;
  rcRight[0].left = 48;
  rcRight[0].top = 128;
  rcRight[0].right = 72;
  rcRight[0].bottom = 144;
  rcRight[1].left = 72;
  rcRight[1].top = 128;
  rcRight[1].right = 96;
  rcRight[1].bottom = 144;
  if ( npc->pNpc->code_char == 3 )
  {
    VanishNpChar(npc);
    SetDestroyNpChar(npc->x, npc->y, npc->view.back, 4);
    return;
  }
  v1 = npc->act_no;
  if ( !v1 )
  {
    npc->act_no = 1;
    npc->count1 = 10;
LABEL_7:
    if ( !npc->direct && npc->flag & 0x20 )
    {
      npc->pNpc->y -= 1024;
      npc->pNpc->ym -= 256;
    }
    if ( npc->direct == 2 && npc->flag & 0x10 )
    {
      npc->pNpc->y -= 1024;
      npc->pNpc->ym -= 256;
    }
    if ( npc->flag & 8 )
    {
      npc->pNpc->y -= 1024;
      npc->pNpc->ym -= 256;
      if ( npc->pNpc->direct )
      {
        v2 = npc->pNpc;
        v3 = npc->pNpc->xm + 128;
      }
      else
      {
        v2 = npc->pNpc;
        v3 = npc->pNpc->xm - 128;
      }
      v2->xm = v3;
    }
    deg = npc->xm + npc->pNpc->count2;
    v4 = npc->pNpc->x;
    npc->x = v4 + npc->count1 * GetCos(deg);
    v5 = npc->pNpc->y;
    npc->y = v5 + npc->count1 * GetSin(deg);
    npc->direct = npc->pNpc->direct;
    goto LABEL_19;
  }
  if ( v1 == 1 )
    goto LABEL_7;
LABEL_19:
  npc->direct = npc->pNpc->direct;
  npc->ani_no = deg <= 0x13u || deg > 0x6Cu;
  if ( npc->direct )
  {
    v6 = npc;
    v7 = (Sint32 *)&v11[16 * npc->ani_no - 68];
  }
  else
  {
    v6 = npc;
    v7 = (Sint32 *)&v11[16 * npc->ani_no - 36];
  }
  npc->rect.left = *v7;
  v6->rect.top = v7[1];
  v6->rect.right = v7[2];
  v6->rect.bottom = v7[3];
}


void __cdecl ActNpc054(NPCHAR_0 *npc)
{
  int v1;
  NPCHAR_0 *v2;
  Sint32 *v3;
  RECT rcRight[3];
  RECT rcLeft[3];
  unsigned __int8 deg;
  char v7[8];

  rcLeft[0].left = 0;
  rcLeft[0].top = 80;
  rcLeft[0].right = 32;
  rcLeft[0].bottom = 104;
  rcLeft[1].left = 32;
  rcLeft[1].top = 80;
  rcLeft[1].right = 64;
  rcLeft[1].bottom = 104;
  rcLeft[2].left = 64;
  rcLeft[2].top = 80;
  rcLeft[2].right = 96;
  rcLeft[2].bottom = 104;
  rcRight[0].left = 0;
  rcRight[0].top = 104;
  rcRight[0].right = 32;
  rcRight[0].bottom = 128;
  rcRight[1].left = 32;
  rcRight[1].top = 104;
  rcRight[1].right = 64;
  rcRight[1].bottom = 128;
  rcRight[2].left = 64;
  rcRight[2].top = 104;
  rcRight[2].right = 96;
  rcRight[2].bottom = 128;
  v1 = npc->act_no;
  if ( v1 == 1 )
  {
LABEL_5:
    deg = npc->count2;
    if ( npc->direct )
      deg += 6;
    else
      deg -= 6;
    npc->count2 = deg;
    if ( npc->flag & 8 )
    {
      npc->xm = 3 * npc->xm / 4;
      if ( ++npc->act_wait > 60 )
      {
        npc->act_no = 2;
        npc->act_wait = 0;
      }
    }
    else
    {
      npc->act_wait = 0;
    }
    if ( npc->direct || !(npc->flag & 1) )
    {
      if ( npc->direct == 2 && npc->flag & 4 )
      {
        if ( ++npc->count1 > 8 )
        {
          npc->direct = 0;
          npc->xm = -npc->xm;
        }
      }
      else
      {
        npc->count1 = 0;
      }
    }
    else if ( ++npc->count1 > 8 )
    {
      npc->direct = 2;
      npc->xm = -npc->xm;
    }
    goto LABEL_26;
  }
  if ( v1 != 2 )
  {
    if ( v1 )
      goto LABEL_26;
    SetNpChar(53, 0, 0, 0, 0, npc->direct, npc, 256);
    SetNpChar(53, 0, 0, 128, 0, npc->direct, npc, 0);
    npc->act_no = 1;
    npc->ani_no = 1;
    goto LABEL_5;
  }
  ++npc->act_wait;
  npc->shock += LOBYTE(npc->act_wait);
  if ( npc->act_wait > 50 )
  {
    VanishNpChar(npc);
    SetDestroyNpChar(npc->x, npc->y, npc->view.back, 8);
    PlaySoundObject(25, 1);
  }
LABEL_26:
  npc->ym += 128;
  if ( npc->xm > 767 )
    npc->xm = 767;
  if ( npc->xm < -767 )
    npc->xm = -767;
  if ( npc->ym > 767 )
    npc->ym = 767;
  if ( npc->ym < -767 )
    npc->ym = -767;
  npc->x += npc->xm;
  npc->y += npc->ym;
  if ( npc->direct )
  {
    v2 = npc;
    v3 = (Sint32 *)&v7[16 * npc->ani_no - 100];
  }
  else
  {
    v2 = npc;
    v3 = (Sint32 *)&v7[16 * npc->ani_no - 52];
  }
  npc->rect.left = *v3;
  v2->rect.top = v3[1];
  v2->rect.right = v3[2];
  v2->rect.bottom = v3[3];
}


void __cdecl ActNpc055(NPCHAR_0 *npc)
{
  int v1;
  NPCHAR_0 *v2;
  Sint32 *v3;
  RECT rcRight[6];
  RECT rcLeft[6];
  char v6[12];

  qmemcpy(rcLeft, &ActNpc055(NPCHAR *)::C.18, sizeof(rcLeft));
  qmemcpy(rcRight, &ActNpc055(NPCHAR *)::C.19, sizeof(rcRight));
  switch ( npc->act_no )
  {
    case 0:
      npc->act_no = 1;
      npc->ani_no = 0;
      npc->ani_wait = 0;
      break;
    case 3:
      npc->act_no = 4;
      npc->ani_no = 1;
      npc->ani_wait = 0;
      goto LABEL_4;
    case 4:
LABEL_4:
      if ( ++npc->ani_wait > 4 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 4 )
        npc->ani_no = 1;
      if ( npc->direct )
        v1 = npc->x + 512;
      else
        v1 = npc->x - 512;
      npc->x = v1;
      break;
    case 5:
      npc->ani_no = 5;
      break;
    default:
      break;
  }
  npc->ym += 32;
  if ( npc->ym > 1535 )
    npc->ym = 1535;
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


void __cdecl ActNpc056(NPCHAR_0 *npc)
{
  int v1;
  int v2;
  int v3;
  int v4;
  NPCHAR_0 *v5;
  RECT *v6;
  RECT rcRight[3];
  RECT rcLeft[3];

  rcLeft[0].left = 0;
  rcLeft[0].top = 144;
  rcLeft[0].right = 16;
  rcLeft[0].bottom = 160;
  rcLeft[1].left = 16;
  rcLeft[1].top = 144;
  rcLeft[1].right = 32;
  rcLeft[1].bottom = 160;
  rcLeft[2].left = 32;
  rcLeft[2].top = 144;
  rcLeft[2].right = 48;
  rcLeft[2].bottom = 160;
  rcRight[0].left = 0;
  rcRight[0].top = 160;
  rcRight[0].right = 16;
  rcRight[0].bottom = 176;
  rcRight[1].left = 16;
  rcRight[1].top = 160;
  rcRight[1].right = 32;
  rcRight[1].bottom = 176;
  rcRight[2].left = 32;
  rcRight[2].top = 160;
  rcRight[2].right = 48;
  rcRight[2].bottom = 176;
  switch ( npc->act_no )
  {
    case 0:
      npc->act_no = 1;
      if ( npc->direct )
        npc->act_no = 3;
      else
        npc->act_no = 1;
      break;
    case 1:
      npc->xm -= 16;
      if ( npc->xm < -1024 )
        npc->xm = -1024;
      if ( npc->shock )
      {
        v1 = npc->x;
        v2 = npc->xm / 2;
      }
      else
      {
        v1 = npc->x;
        v2 = npc->xm;
      }
      npc->x = v2 + v1;
      if ( ++npc->ani_wait > 1 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 2 )
        npc->ani_no = 1;
      if ( npc->flag & 1 )
      {
        npc->act_no = 2;
        npc->act_wait = 0;
        npc->ani_no = 0;
        npc->xm = 0;
        npc->direct = 2;
      }
      break;
    case 2:
      if ( npc->x < x && npc->x > x - 0x20000 && npc->y < y + 4096 && npc->y > y - 4096 )
      {
        npc->act_no = 3;
        npc->ani_wait = 0;
        npc->ani_no = 1;
      }
      break;
    case 3:
      npc->xm += 16;
      if ( npc->xm > 1024 )
        npc->xm = 1024;
      if ( npc->shock )
      {
        v3 = npc->x;
        v4 = npc->xm / 2;
      }
      else
      {
        v3 = npc->x;
        v4 = npc->xm;
      }
      npc->x = v4 + v3;
      if ( ++npc->ani_wait > 1 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 2 )
        npc->ani_no = 1;
      if ( npc->flag & 4 )
      {
        npc->act_no = 4;
        npc->act_wait = 0;
        npc->ani_no = 0;
        npc->xm = 0;
        npc->direct = 0;
      }
      break;
    case 4:
      if ( npc->x < x + 0x20000 && npc->x > x && npc->y < y + 4096 && npc->y > y - 4096 )
      {
        npc->act_no = 1;
        npc->ani_wait = 0;
        npc->ani_no = 1;
      }
      break;
    default:
      break;
  }
  if ( npc->direct )
  {
    v5 = npc;
    v6 = &rcRight[npc->ani_no];
  }
  else
  {
    v5 = npc;
    v6 = &rcLeft[npc->ani_no];
  }
  npc->rect.left = v6->left;
  v5->rect.top = v6->top;
  v5->rect.right = v6->right;
  v5->rect.bottom = v6->bottom;
}

void __cdecl ActNpc057(NPCHAR_0 *npc)
{
  int v1;
  int v2;
  int v3;
  NPCHAR_0 *v4;
  Sint32 *v5;
  RECT rect_right[5];
  RECT rect_left[5];
  unsigned __int8 deg;
  char v9[24];

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
    if ( npc->shock )
    {
      npc->act_no = 2;
      npc->act_wait = 0;
      if ( npc->direct == 2 )
        npc->xm = -512;
      else
        npc->xm = 512;
      npc->ym = 0;
    }
    goto LABEL_67;
  }
  if ( v1 != 2 )
  {
    if ( v1 )
      goto LABEL_67;
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
    npc->ani_no = Random(0, 1);
    npc->ani_wait = Random(0, 4);
    goto LABEL_5;
  }
  if ( x >= npc->x )
    npc->direct = 2;
  else
    npc->direct = 0;
  if ( npc->y <= y + 24576 )
  {
    if ( x < npc->x )
      npc->xm -= 16;
    if ( x > npc->x )
      npc->xm += 16;
  }
  else
  {
    if ( x < npc->x )
      npc->xm += 16;
    if ( x > npc->x )
      npc->xm -= 16;
  }
  if ( y < npc->y )
    npc->ym -= 16;
  if ( y > npc->y )
    npc->ym += 16;
  if ( npc->shock )
  {
    npc->ym += 32;
    npc->xm = 0;
  }
  if ( npc->xm < 0 && npc->flag & 1 )
    npc->xm = 512;
  if ( npc->xm > 0 && npc->flag & 4 )
    npc->xm = -512;
  if ( npc->ym < 0 && npc->flag & 2 )
    npc->ym = 512;
  if ( npc->ym > 0 && npc->flag & 8 )
    npc->ym = -512;
  if ( npc->xm > 1535 )
    npc->xm = 1535;
  if ( npc->xm < -1535 )
    npc->xm = -1535;
  if ( npc->ym > 1535 )
    npc->ym = 1535;
  if ( npc->ym < -1535 )
    npc->ym = -1535;
LABEL_67:
  npc->x += npc->xm;
  npc->y += npc->ym;
  qmemcpy(rect_left, &ActNpc057(NPCHAR *)::C.20, sizeof(rect_left));
  qmemcpy(rect_right, &ActNpc057(NPCHAR *)::C.21, sizeof(rect_right));
  if ( npc->shock )
  {
    npc->ani_no = 4;
  }
  else
  {
    if ( ++npc->ani_wait > 1 )
    {
      npc->ani_wait = 0;
      ++npc->ani_no;
    }
    if ( npc->ani_no > 1 )
      npc->ani_no = 0;
  }
  if ( npc->direct )
  {
    v4 = npc;
    v5 = (Sint32 *)&v9[16 * npc->ani_no - 164];
  }
  else
  {
    v4 = npc;
    v5 = (Sint32 *)&v9[16 * npc->ani_no - 84];
  }
  npc->rect.left = *v5;
  v4->rect.top = v5[1];
  v4->rect.right = v5[2];
  v4->rect.bottom = v5[3];
}


void __cdecl ActNpc058(NPCHAR_0 *npc)
{
  int v1;
  int v2;
  int v3;
  int v4;
  int v5;
  NPCHAR_0 *v6;
  Sint32 *v7;
  RECT rcRight[3];
  RECT rcLeft[3];
  unsigned __int8 deg;
  int xm;
  int ym;
  char v13[8];

  rcLeft[0].left = 192;
  rcLeft[0].top = 0;
  rcLeft[0].right = 216;
  rcLeft[0].bottom = 24;
  rcLeft[1].left = 216;
  rcLeft[1].top = 0;
  rcLeft[1].right = 240;
  rcLeft[1].bottom = 24;
  rcLeft[2].left = 240;
  rcLeft[2].top = 0;
  rcLeft[2].right = 264;
  rcLeft[2].bottom = 24;
  rcRight[0].left = 192;
  rcRight[0].top = 24;
  rcRight[0].right = 216;
  rcRight[0].bottom = 48;
  rcRight[1].left = 216;
  rcRight[1].top = 24;
  rcRight[1].right = 240;
  rcRight[1].bottom = 48;
  rcRight[2].left = 240;
  rcRight[2].top = 24;
  rcRight[2].right = 264;
  rcRight[2].bottom = 48;
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
    if ( npc->ym > 256 )
      npc->ym = 256;
    if ( npc->ym < -256 )
      npc->ym = -256;
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
            ym = 2 * GetSin(deg);
            xm = 2 * GetCos(deg);
            SetNpChar(84, npc->x, npc->y, xm, ym, 0, 0, 256);
            PlaySoundObject(39, 1);
          }
          if ( npc->count2 > 8 )
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
    npc->ym = -256;
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


void __cdecl ActNpc059(NPCHAR_0 *npc)
{
  RECT *v1;
  RECT rcLeft[4];

  rcLeft[0].left = 224;
  rcLeft[0].top = 16;
  rcLeft[0].right = 240;
  rcLeft[0].bottom = 40;
  rcLeft[1].left = 208;
  rcLeft[1].top = 80;
  rcLeft[1].right = 224;
  rcLeft[1].bottom = 104;
  rcLeft[2].left = 224;
  rcLeft[2].top = 80;
  rcLeft[2].right = 240;
  rcLeft[2].bottom = 104;
  rcLeft[3].left = 240;
  rcLeft[3].top = 80;
  rcLeft[3].right = 256;
  rcLeft[3].bottom = 104;
  switch ( npc->act_no )
  {
    case 0:
      npc->act_no = 1;
      goto LABEL_3;
    case 1:
LABEL_3:
      if ( npc->x - 0x8000 < x && npc->x + 0x8000 > x && npc->y - 0x8000 < y && npc->y + 0x8000 > y )
      {
        npc->act_no = 2;
        npc->ani_wait = 0;
      }
      break;
    case 2:
      if ( ++npc->ani_wait > 2 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no == 2 )
        npc->act_no = 3;
      break;
    case 3:
      if ( npc->x - 0x8000 >= x || npc->x + 0x8000 <= x || npc->y - 0x8000 >= y || npc->y + 0x8000 <= y )
      {
        npc->act_no = 4;
        npc->ani_wait = 0;
      }
      break;
    case 4:
      if ( ++npc->ani_wait > 2 )
      {
        npc->ani_wait = 0;
        --npc->ani_no;
      }
      if ( !npc->ani_no )
        npc->act_no = 1;
      break;
    default:
      break;
  }
  if ( npc->shock )
  {
    npc->rect.left = rcLeft[3].left;
    npc->rect.top = rcLeft[3].top;
    npc->rect.right = rcLeft[3].right;
    npc->rect.bottom = rcLeft[3].bottom;
  }
  else
  {
    v1 = &rcLeft[npc->ani_no];
    npc->rect.left = v1->left;
    npc->rect.top = v1->top;
    npc->rect.right = v1->right;
    npc->rect.bottom = v1->bottom;
  }
}

