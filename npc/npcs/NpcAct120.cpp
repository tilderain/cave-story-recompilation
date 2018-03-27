#include "../forNpc.h"
#include "../npcList.h"

void ActNpc120(NPCHAR *npc)
{
  if ( npc->direct )
  {
    npc->rect.left = 64;
    npc->rect.top = 16;
    npc->rect.right = 80;
    npc->rect.bottom = 32;
  }
  else
  {
    npc->rect.left = 64;
    npc->rect.top = 0;
    npc->rect.right = 80;
    npc->rect.bottom = 16;
  }
}

void ActNpc121(NPCHAR *npc)
{
  int v1;
  Sint32 *v2;
  RECT rect[3];
  char v4[8];

  rect[0].left = 0;
  rect[0].top = 0;
  rect[0].right = 16;
  rect[0].bottom = 16;
  rect[1].left = 16;
  rect[1].top = 0;
  rect[1].right = 32;
  rect[1].bottom = 16;
  rect[2].left = 112;
  rect[2].top = 0;
  rect[2].right = 128;
  rect[2].bottom = 16;
  if ( !npc->direct )
  {
    v1 = npc->act_no;
    if ( v1 != 1 )
    {
      if ( v1 == 2 )
      {
        if ( ++npc->act_wait > 8 )
        {
          npc->act_no = 1;
          npc->ani_no = 0;
        }
        goto LABEL_10;
      }
      if ( v1 )
      {
LABEL_10:
        v2 = (Sint32 *)&v4[16 * npc->ani_no - 48];
        npc->rect.left = *v2;
        npc->rect.top = v2[1];
        npc->rect.right = v2[2];
        npc->rect.bottom = v2[3];
        return;
      }
      npc->act_no = 1;
      npc->ani_no = 0;
      npc->ani_wait = 0;
    }
    if ( Random(0, 120) == 10 )
    {
      npc->act_no = 2;
      npc->act_wait = 0;
      npc->ani_no = 1;
    }
    goto LABEL_10;
  }
  npc->rect.left = rect[2].left;
  npc->rect.top = rect[2].top;
  npc->rect.right = rect[2].right;
  npc->rect.bottom = rect[2].bottom;
  if ( ++npc->act_wait > 100 )
  {
    npc->act_wait = 0;
    SetCaret(npc->x, npc->y, 5, 0);
  }
}


void ActNpc122(NPCHAR *npc)
{
  int v1;
  NPCHAR *v2;
  Sint32 *v3;
  RECT rcRight[10];
  RECT rcLeft[10];
  char v6[24];

  qmemcpy(rcLeft, &ActNpc122(NPCHAR *)::C.1, sizeof(rcLeft));
  qmemcpy(rcRight, &ActNpc122(NPCHAR *)::C.2, sizeof(rcRight));
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
    case 0xA:
      npc->life = 1000;
      npc->act_no = 11;
      npc->act_wait = Random(0, 50);
      npc->ani_no = 0;
      npc->damage = 0;
      goto LABEL_15;
    case 0xB:
LABEL_15:
      if ( npc->act_wait )
        --npc->act_wait;
      else
        npc->act_no = 13;
      break;
    case 0xD:
      npc->act_no = 14;
      npc->act_wait = Random(0, 50);
      if ( npc->x <= x )
        npc->direct = 2;
      else
        npc->direct = 0;
      goto LABEL_21;
    case 0xE:
LABEL_21:
      if ( ++npc->ani_wait > 2 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 5 )
        npc->ani_no = 2;
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
        npc->act_no = 15;
        npc->ani_no = 2;
        npc->ym = -512;
        npc->damage = 2;
      }
      break;
    case 0xF:
      if ( npc->flag & 8 )
      {
        npc->bits |= 0x20u;
        npc->xm = 0;
        npc->act_no = 10;
        npc->damage = 0;
      }
      break;
    case 0x14:
      if ( npc->flag & 8 )
      {
        npc->xm = 0;
        npc->act_no = 21;
        npc->damage = 0;
        if ( npc->ani_no == 6 )
          npc->ani_no = 8;
        else
          npc->ani_no = 9;
        npc->act_wait = Random(300, 400);
      }
      break;
    case 0x15:
      if ( npc->act_wait )
      {
        --npc->act_wait;
      }
      else
      {
        npc->bits |= 0x20u;
        npc->life = 1000;
        npc->act_no = 11;
        npc->act_wait = Random(0, 50);
        npc->ani_no = 0;
      }
      break;
    default:
      break;
  }
  if ( npc->act_no > 10 && npc->act_no <= 19 && npc->life != 1000 )
  {
    npc->act_no = 20;
    npc->ym = -512;
    npc->ani_no = Random(6, 7);
    npc->bits &= 0xFFDFu;
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
    v2 = npc;
    v3 = (Sint32 *)&v6[16 * npc->ani_no - 320];
  }
  else
  {
    v2 = npc;
    v3 = (Sint32 *)&v6[16 * npc->ani_no - 160];
  }
  npc->rect.left = *v3;
  v2->rect.top = v3[1];
  v2->rect.right = v3[2];
  v2->rect.bottom = v3[3];
}


void ActNpc123(NPCHAR *npc)
{
  int v1;
  int v2;
  int v3;
  Sint32 *v4;
  RECT rect[4];
  bool bBreak;
  char v7[8];

  rect[0].left = 192;
  rect[0].top = 0;
  rect[0].right = 208;
  rect[0].bottom = 16;
  rect[1].left = 208;
  rect[1].top = 0;
  rect[1].right = 224;
  rect[1].bottom = 16;
  rect[2].left = 224;
  rect[2].top = 0;
  rect[2].right = 240;
  rect[2].bottom = 16;
  rect[3].left = 240;
  rect[3].top = 0;
  rect[3].right = 256;
  rect[3].bottom = 16;
  bBreak = 0;
  v1 = npc->act_no;
  if ( v1 )
  {
    if ( v1 == 1 )
    {
      v3 = npc->direct;
      if ( v3 == 1 )
      {
        if ( npc->flag & 2 )
          bBreak = 1;
      }
      else if ( v3 > 1 )
      {
        if ( v3 == 2 )
        {
          if ( npc->flag & 4 )
            bBreak = 1;
        }
        else if ( v3 == 3 && npc->flag & 8 )
        {
          bBreak = 1;
        }
      }
      else if ( !v3 && npc->flag & 1 )
      {
        bBreak = 1;
      }
      npc->x += npc->xm;
      npc->y += npc->ym;
    }
  }
  else
  {
    npc->act_no = 1;
    SetCaret(npc->x, npc->y, 3, 0);
    PlaySoundObject(32, 1);
    v2 = npc->direct;
    if ( v2 == 1 )
    {
      npc->ym = -4096;
      npc->xm = Random(-128, 128);
    }
    else if ( v2 > 1 )
    {
      if ( v2 == 2 )
      {
        npc->xm = 4096;
        npc->ym = Random(-128, 128);
      }
      else if ( v2 == 3 )
      {
        npc->ym = 4096;
        npc->xm = Random(-128, 128);
      }
    }
    else if ( !v2 )
    {
      npc->xm = -4096;
      npc->ym = Random(-128, 128);
    }
  }
  if ( bBreak )
  {
    SetCaret(npc->x, npc->y, 2, 2);
    PlaySoundObject(28, 1);
    npc->cond = 0;
  }
  v4 = (Sint32 *)&v7[16 * npc->direct - 68];
  npc->rect.left = *v4;
  npc->rect.top = v4[1];
  npc->rect.right = v4[2];
  npc->rect.bottom = v4[3];
}


void ActNpc124(NPCHAR *npc)
{
  int v1;
  int v2;
  Sint32 *v3;
  RECT rect[2];
  char v5[8];

  rect[0].left = 160;
  rect[0].top = 0;
  rect[0].right = 192;
  rect[0].bottom = 32;
  rect[1].left = 192;
  rect[1].top = 0;
  rect[1].right = 224;
  rect[1].bottom = 32;
  v1 = npc->act_no;
  if ( v1 == 1 )
  {
LABEL_9:
    npc->bits &= 0xFFF7u;
    npc->ani_no = 0;
    goto LABEL_25;
  }
  if ( v1 <= 1 )
  {
    if ( v1 )
      goto LABEL_25;
    npc->act_no = 1;
    npc->x += 4096;
    npc->y += 4096;
    goto LABEL_9;
  }
  if ( v1 == 10 )
  {
    npc->act_no = 11;
    npc->ani_no = 1;
    npc->act_wait = 0;
    npc->bits |= 8u;
  }
  else if ( v1 != 11 )
  {
    goto LABEL_25;
  }
  v2 = npc->direct;
  if ( v2 == 1 )
  {
    npc->y -= 128;
  }
  else if ( v2 > 1 )
  {
    if ( v2 == 2 )
    {
      npc->x += 128;
    }
    else if ( v2 == 3 )
    {
      npc->y += 128;
    }
  }
  else if ( !v2 )
  {
    npc->x -= 128;
  }
  if ( !(++npc->act_wait & 7) )
    PlaySoundObject(26, 1);
  SetQuake(20);
LABEL_25:
  v3 = (Sint32 *)&v5[16 * npc->ani_no - 32];
  npc->rect.left = *v3;
  npc->rect.top = v3[1];
  npc->rect.right = v3[2];
  npc->rect.bottom = v3[3];
}


void ActNpc125(NPCHAR *npc)
{
  if ( npc->life <= 989 )
  {
    SetDestroyNpChar(npc->x, npc->y, npc->view.back, 8);
    PlaySoundObject(70, 1);
    if ( npc->direct )
      SetNpChar(86, npc->x, npc->y, 0, 0, 2, 0, 0);
    else
      SetNpChar(87, npc->x, npc->y, 0, 0, 2, 0, 0);
    npc->cond = 0;
  }
  if ( npc->direct )
  {
    npc->rect.left = 16;
    npc->rect.top = 96;
    npc->rect.right = 32;
  }
  else
  {
    npc->rect.left = 0;
    npc->rect.top = 96;
    npc->rect.right = 16;
  }
  npc->rect.bottom = 112;
}

void ActNpc126(NPCHAR *npc)
{
  int v1;
  unsigned __int16 v2;
  NPCHAR *v3;
  Sint32 *v4;
  RECT rcRight[6];
  RECT rcLeft[6];
  char v7[24];

  qmemcpy(rcLeft, &ActNpc126(NPCHAR *)::C.4, sizeof(rcLeft));
  qmemcpy(rcRight, &ActNpc126(NPCHAR *)::C.5, sizeof(rcRight));
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
      if ( npc->x - 49152 < x && npc->x + 49152 > x && npc->y - 0x4000 < y && npc->y + 0x2000 > y )
      {
        if ( npc->x <= x )
          npc->direct = 2;
        else
          npc->direct = 0;
      }
      if ( npc->x - 0x4000 < x && npc->x + 0x4000 > x && npc->y - 0x4000 < y && npc->y + 0x2000 > y )
      {
        if ( npc->x <= x )
          npc->direct = 0;
        else
          npc->direct = 2;
        npc->act_no = 10;
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
      npc->ani_no = 4;
      npc->ani_wait = 0;
      goto LABEL_23;
    case 0xB:
LABEL_23:
      if ( npc->flag & 8 )
      {
        if ( ++npc->ani_wait > 2 )
        {
          npc->ani_wait = 0;
          ++npc->ani_no;
        }
        if ( npc->ani_no > 5 )
          npc->ani_no = 4;
      }
      else
      {
        npc->ani_no = 5;
        npc->ani_wait = 0;
      }
      if ( npc->xm < 0 && npc->flag & 1 )
      {
        npc->xm /= -2;
        npc->direct = 2;
      }
      if ( npc->xm > 0 && npc->flag & 4 )
      {
        npc->xm /= -2;
        npc->direct = 0;
      }
      if ( npc->direct )
        v1 = npc->xm + 64;
      else
        v1 = npc->xm - 64;
      npc->xm = v1;
      if ( npc->xm > 1535 )
        npc->xm = 1024;
      if ( npc->xm < -1535 )
        npc->xm = -1024;
      break;
    default:
      break;
  }
  if ( gKeyTrg & gKeyDown )
  {
    v2 = npc->bits;
    HIBYTE(v2) |= 0x20u;
  }
  else
  {
    v2 = npc->bits;
    HIBYTE(v2) &= 0xDFu;
  }
  npc->bits = v2;
  npc->ym += 64;
  if ( npc->ym > 1535 )
    npc->ym = 1535;
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


void ActNpc127(NPCHAR *npc)
{
  NPCHAR *v1;
  RECT *v2;
  RECT rcH[3];
  RECT rcV[3];

  rcV[0].left = 112;
  rcV[0].top = 48;
  rcV[0].right = 128;
  rcV[0].bottom = 64;
  rcV[1].left = 112;
  rcV[1].top = 64;
  rcV[1].right = 128;
  rcV[1].bottom = 80;
  rcV[2].left = 112;
  rcV[2].top = 80;
  rcV[2].right = 128;
  rcV[2].bottom = 96;
  rcH[0].left = 64;
  rcH[0].top = 80;
  rcH[0].right = 80;
  rcH[0].bottom = 96;
  rcH[1].left = 80;
  rcH[1].top = 80;
  rcH[1].right = 96;
  rcH[1].bottom = 96;
  rcH[2].left = 96;
  rcH[2].top = 80;
  rcH[2].right = 112;
  rcH[2].bottom = 96;
  if ( ++npc->ani_wait > 0 )
  {
    npc->ani_wait = 0;
    if ( ++npc->ani_no > 2 )
      npc->cond = 0;
  }
  if ( npc->direct )
  {
    v1 = npc;
    v2 = &rcV[npc->ani_no];
  }
  else
  {
    v1 = npc;
    v2 = &rcH[npc->ani_no];
  }
  npc->rect.left = v2->left;
  v1->rect.top = v2->top;
  v1->rect.right = v2->right;
  v1->rect.bottom = v2->bottom;
}

void ActNpc128(NPCHAR *npc)
{
  int v1;
  Sint32 *v2;
  Sint32 *v3;
  Sint32 *v4;
  Sint32 *v5;
  RECT rcDown[5];
  RECT rcUp[5];
  RECT rcRight[5];
  RECT rcLeft[5];
  char v10[12];

  qmemcpy(rcLeft, &ActNpc128(NPCHAR *)::C.9, sizeof(rcLeft));
  qmemcpy(rcRight, &ActNpc128(NPCHAR *)::C.10, sizeof(rcRight));
  qmemcpy(rcUp, &ActNpc128(NPCHAR *)::C.11, sizeof(rcUp));
  qmemcpy(rcDown, &ActNpc128(NPCHAR *)::C.12, sizeof(rcDown));
  if ( !npc->act_no )
  {
    npc->act_no = 1;
    if ( npc->direct && npc->direct != 2 )
    {
      npc->view.front = 4096;
      npc->view.top = 2048;
    }
    else
    {
      npc->view.front = 2048;
      npc->view.top = 4096;
    }
  }
  if ( ++npc->ani_no > 4 )
    npc->cond = 0;
  v1 = npc->direct;
  if ( v1 == 1 )
  {
    v3 = (Sint32 *)&v10[16 * npc->ani_no - 240];
    npc->rect.left = *v3;
    npc->rect.top = v3[1];
    npc->rect.right = v3[2];
    npc->rect.bottom = v3[3];
  }
  else if ( v1 > 1 )
  {
    if ( v1 == 2 )
    {
      v4 = (Sint32 *)&v10[16 * npc->ani_no - 160];
      npc->rect.left = *v4;
      npc->rect.top = v4[1];
      npc->rect.right = v4[2];
      npc->rect.bottom = v4[3];
    }
    else if ( v1 == 3 )
    {
      v5 = (Sint32 *)&v10[16 * npc->ani_no - 320];
      npc->rect.left = *v5;
      npc->rect.top = v5[1];
      npc->rect.right = v5[2];
      npc->rect.bottom = v5[3];
    }
  }
  else if ( !v1 )
  {
    v2 = (Sint32 *)&v10[16 * npc->ani_no - 80];
    npc->rect.left = *v2;
    npc->rect.top = v2[1];
    npc->rect.right = v2[2];
    npc->rect.bottom = v2[3];
  }
}


void ActNpc129(NPCHAR *npc)
{
  Sint32 *v1;
  RECT rect[18];
  char v3[12];

  qmemcpy(rect, &ActNpc129(NPCHAR *)::C.13, sizeof(rect));
  if ( ++npc->ani_wait > 1 )
  {
    npc->ani_wait = 0;
    if ( ++npc->ani_no > 2 )
      npc->cond = 0;
  }
  npc->y += npc->ym;
  v1 = (Sint32 *)&v3[16 * (npc->ani_no + 3 * npc->direct) - 288];
  npc->rect.left = *v1;
  npc->rect.top = v1[1];
  npc->rect.right = v1[2];
  npc->rect.bottom = v1[3];
}


void ActNpc130(NPCHAR *npc)
{
  int v1;
  unsigned __int16 v2;
  NPCHAR *v3;
  Sint32 *v4;
  RECT rcRight[4];
  RECT rcLeft[4];
  char v7[8];

  rcLeft[0].left = 48;
  rcLeft[0].top = 144;
  rcLeft[0].right = 64;
  rcLeft[0].bottom = 160;
  rcLeft[1].left = 64;
  rcLeft[1].top = 144;
  rcLeft[1].right = 80;
  rcLeft[1].bottom = 160;
  rcLeft[2].left = 48;
  rcLeft[2].top = 144;
  rcLeft[2].right = 64;
  rcLeft[2].bottom = 160;
  rcLeft[3].left = 80;
  rcLeft[3].top = 144;
  rcLeft[3].right = 96;
  rcLeft[3].bottom = 160;
  rcRight[0].left = 48;
  rcRight[0].top = 160;
  rcRight[0].right = 64;
  rcRight[0].bottom = 176;
  rcRight[1].left = 64;
  rcRight[1].top = 160;
  rcRight[1].right = 80;
  rcRight[1].bottom = 176;
  rcRight[2].left = 48;
  rcRight[2].top = 160;
  rcRight[2].right = 64;
  rcRight[2].bottom = 176;
  rcRight[3].left = 80;
  rcRight[3].top = 160;
  rcRight[3].right = 96;
  rcRight[3].bottom = 176;
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
    if ( npc->x - 0x8000 < x && npc->x + 0x8000 > x && npc->y - 0x4000 < y && npc->y + 0x2000 > y )
    {
      if ( ++npc->ani_wait > 3 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 3 )
        npc->ani_no = 2;
    }
    if ( npc->x - 49152 < x && npc->x + 49152 > x && npc->y - 0x4000 < y && npc->y + 0x2000 > y )
    {
      if ( npc->x <= x )
        npc->direct = 2;
      else
        npc->direct = 0;
    }
    goto LABEL_24;
  }
  if ( v1 != 2 )
  {
    if ( v1 )
      goto LABEL_24;
    npc->act_no = 1;
    npc->ani_no = 0;
    npc->ani_wait = 0;
    v2 = npc->bits;
    HIBYTE(v2) |= 0x20u;
    npc->bits = v2;
    goto LABEL_5;
  }
  if ( ++npc->act_wait > 8 )
  {
    npc->act_no = 1;
    npc->ani_no = 0;
  }
LABEL_24:
  npc->ym += 64;
  if ( npc->ym > 1535 )
    npc->ym = 1535;
  npc->x += npc->xm;
  npc->y += npc->ym;
  if ( npc->direct )
  {
    v3 = npc;
    v4 = (Sint32 *)&v7[16 * npc->ani_no - 128];
  }
  else
  {
    v3 = npc;
    v4 = (Sint32 *)&v7[16 * npc->ani_no - 64];
  }
  npc->rect.left = *v4;
  v3->rect.top = v4[1];
  v3->rect.right = v4[2];
  v3->rect.bottom = v4[3];
}


void ActNpc131(NPCHAR *npc)
{
  NPCHAR *v1;
  Sint32 *v2;
  RECT rcRight[1];
  RECT rcLeft[1];
  char v5[8];

  rcLeft[0].left = 144;
  rcLeft[0].top = 144;
  rcLeft[0].right = 160;
  rcLeft[0].bottom = 160;
  rcRight[0].left = 144;
  rcRight[0].top = 160;
  rcRight[0].right = 160;
  rcRight[0].bottom = 176;
  if ( ++npc->act_wait > 100 )
  {
    npc->act_wait = 0;
    SetCaret(npc->x, npc->y, 5, 0);
  }
  if ( npc->direct )
  {
    v1 = npc;
    v2 = (Sint32 *)&v5[16 * npc->ani_no - 32];
  }
  else
  {
    v1 = npc;
    v2 = (Sint32 *)&v5[16 * npc->ani_no - 16];
  }
  npc->rect.left = *v2;
  v1->rect.top = v2[1];
  v1->rect.right = v2[2];
  v1->rect.bottom = v2[3];
}


void ActNpc132(NPCHAR *npc)
{
  int v1;
  NPCHAR *v2;
  Sint32 *v3;
  RECT rcRight[5];
  RECT rcLeft[5];
  char v6[24];

  qmemcpy(rcLeft, &ActNpc132(NPCHAR *)::C.15, sizeof(rcLeft));
  qmemcpy(rcRight, &ActNpc132(NPCHAR *)::C.16, sizeof(rcRight));
  if ( npc->act_no <= 99 )
  {
    if ( x >= npc->x )
      npc->direct = 2;
    else
      npc->direct = 0;
  }
  v1 = npc->act_no;
  if ( v1 == 11 )
  {
LABEL_41:
    if ( Random(0, 120) == 10 )
    {
      npc->act_no = 12;
      npc->act_wait = 0;
      npc->ani_no = 1;
    }
    goto LABEL_56;
  }
  if ( v1 > 11 )
  {
    if ( v1 == 100 )
    {
      npc->act_no = 101;
      npc->count1 = 0;
    }
    else
    {
      if ( v1 <= 100 )
      {
        if ( v1 == 12 && ++npc->act_wait > 8 )
        {
          npc->act_no = 11;
          npc->ani_no = 0;
        }
        goto LABEL_56;
      }
      if ( v1 != 101 )
      {
        if ( v1 == 120 )
          npc->ani_no = 0;
        goto LABEL_56;
      }
    }
    if ( ++npc->ani_wait > 4 )
    {
      npc->ani_wait = 0;
      ++npc->ani_no;
    }
    if ( npc->ani_no > 4 )
    {
      if ( npc->count1 > 2 )
      {
        npc->ani_no = 0;
        npc->count1 = 0;
      }
      else
      {
        npc->ani_no = 2;
        ++npc->count1;
      }
    }
    if ( npc->ani_no == 4 && !npc->ani_wait )
      PlaySoundObject(105, 1);
  }
  else
  {
    if ( v1 == 1 )
    {
LABEL_22:
      if ( Random(0, 120) == 10 )
      {
        npc->act_no = 2;
        npc->act_wait = 0;
        npc->ani_no = 1;
      }
      if ( npc->x - 0x8000 >= x || npc->x + 0x8000 <= x || npc->y - 0x2000 >= y || npc->y + 0x2000 <= y )
      {
        if ( npc->ani_no == 4 )
          npc->ani_no = 2;
      }
      else
      {
        if ( ++npc->ani_wait > 4 )
        {
          npc->ani_wait = 0;
          ++npc->ani_no;
        }
        if ( npc->ani_no > 4 )
          npc->ani_no = 2;
        if ( npc->ani_no == 4 && !npc->ani_wait )
          PlaySoundObject(105, 1);
      }
      goto LABEL_56;
    }
    if ( v1 <= 1 )
    {
      if ( v1 )
        goto LABEL_56;
      npc->act_no = 1;
      npc->ani_no = 0;
      npc->ani_wait = 0;
      goto LABEL_22;
    }
    if ( v1 != 2 )
    {
      if ( v1 != 10 )
        goto LABEL_56;
      npc->act_no = 11;
      npc->ani_no = 0;
      npc->ani_wait = 0;
      goto LABEL_41;
    }
    if ( ++npc->act_wait > 8 )
    {
      npc->act_no = 1;
      npc->ani_no = 0;
    }
  }
LABEL_56:
  npc->ym += 64;
  if ( npc->ym > 1535 )
    npc->ym = 1535;
  npc->x += npc->xm;
  npc->y += npc->ym;
  if ( npc->direct )
  {
    v2 = npc;
    v3 = (Sint32 *)&v6[16 * npc->ani_no - 160];
  }
  else
  {
    v2 = npc;
    v3 = (Sint32 *)&v6[16 * npc->ani_no - 80];
  }
  npc->rect.left = *v3;
  v2->rect.top = v3[1];
  v2->rect.right = v3[2];
  v2->rect.bottom = v3[3];
}


void ActNpc133(NPCHAR *npc)
{
  int v1;
  NPCHAR *v2;
  Sint32 *v3;
  RECT rcRight[2];
  RECT rcLeft[2];
  char v6[8];

  rcLeft[0].left = 176;
  rcLeft[0].top = 32;
  rcLeft[0].right = 192;
  rcLeft[0].bottom = 48;
  rcLeft[1].left = 192;
  rcLeft[1].top = 32;
  rcLeft[1].right = 208;
  rcLeft[1].bottom = 48;
  rcRight[0].left = 176;
  rcRight[0].top = 48;
  rcRight[0].right = 192;
  rcRight[0].bottom = 64;
  rcRight[1].left = 192;
  rcRight[1].top = 48;
  rcRight[1].right = 208;
  rcRight[1].bottom = 64;
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


void ActNpc134(NPCHAR *npc)
{
  int v1;
  int v2;
  NPCHAR *v3;
  Sint32 *v4;
  RECT rcRight[3];
  RECT rcLeft[3];
  char v7[8];

  rcLeft[0].left = 224;
  rcLeft[0].top = 0;
  rcLeft[0].right = 256;
  rcLeft[0].bottom = 16;
  rcLeft[1].left = 256;
  rcLeft[1].top = 0;
  rcLeft[1].right = 288;
  rcLeft[1].bottom = 16;
  rcLeft[2].left = 288;
  rcLeft[2].top = 0;
  rcLeft[2].right = 320;
  rcLeft[2].bottom = 16;
  rcRight[0].left = 224;
  rcRight[0].top = 16;
  rcRight[0].right = 256;
  rcRight[0].bottom = 32;
  rcRight[1].left = 256;
  rcRight[1].top = 16;
  rcRight[1].right = 288;
  rcRight[1].bottom = 32;
  rcRight[2].left = 288;
  rcRight[2].top = 16;
  rcRight[2].right = 320;
  rcRight[2].bottom = 32;
  v1 = npc->act_no;
  if ( v1 == 1 )
  {
LABEL_9:
    if ( x > npc->x - 163840 && x < npc->x + 163840 && y > npc->y - 81920 && y < npc->y + 0x8000 )
    {
      npc->act_no = 10;
      npc->bits |= 0x20u;
      npc->bits &= 0xFFFBu;
    }
    goto LABEL_31;
  }
  if ( v1 <= 1 )
  {
    if ( v1 )
      goto LABEL_31;
    npc->act_no = 1;
    npc->ani_no = 2;
    npc->bits &= 0xFFDFu;
    npc->bits |= 4u;
    goto LABEL_9;
  }
  if ( v1 == 10 )
  {
    if ( ++npc->ani_wait > 4 )
    {
      npc->ani_wait = 0;
      ++npc->ani_no;
    }
    if ( npc->ani_no > 1 )
      npc->ani_no = 0;
    if ( !npc->direct && npc->flag & 1 )
      npc->direct = 2;
    if ( npc->direct == 2 && npc->flag & 4 )
      npc->direct = 0;
    if ( npc->direct )
      v2 = npc->x + 256;
    else
      v2 = npc->x - 256;
    npc->x = v2;
    if ( CountArmsBullet(6) != 0 )
    {
      npc->act_no = 20;
      npc->act_wait = 0;
      npc->ani_no = 2;
      npc->bits &= 0xFFDFu;
      npc->bits |= 4u;
    }
  }
  else if ( v1 == 20 && ++npc->act_wait > 100 )
  {
    npc->act_no = 10;
    npc->ani_no = 0;
    npc->ani_wait = 0;
    npc->bits |= 0x20u;
    npc->bits &= 0xFFFBu;
  }
LABEL_31:
  npc->ym += 64;
  if ( npc->ym > 1535 )
    npc->ym = 1535;
  npc->y += npc->ym;
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
}


void ActNpc135(NPCHAR *npc)
{
  int v1;
  int v2;
  NPCHAR *v3;
  Sint32 *v4;
  RECT rcRight[2];
  RECT rcLeft[2];
  unsigned __int8 deg;
  int xm;
  int ym;
  char v10[8];

  rcLeft[0].left = 256;
  rcLeft[0].top = 32;
  rcLeft[0].right = 288;
  rcLeft[0].bottom = 64;
  rcLeft[1].left = 288;
  rcLeft[1].top = 32;
  rcLeft[1].right = 320;
  rcLeft[1].bottom = 64;
  rcRight[0].left = 256;
  rcRight[0].top = 64;
  rcRight[0].right = 288;
  rcRight[0].bottom = 96;
  rcRight[1].left = 288;
  rcRight[1].top = 64;
  rcRight[1].right = 320;
  rcRight[1].bottom = 96;
  if ( x < npc->x - 180224 || x > npc->x + 180224 || y < npc->y - 81920 || y > npc->y + 0x8000 )
    npc->act_no = 0;
  switch ( npc->act_no )
  {
    case 0:
      npc->act_no = 1;
      npc->xm = 0;
      goto LABEL_8;
    case 1:
LABEL_8:
      if ( x > npc->x - 163840 && x < npc->x + 163840 && y > npc->y - 81920 && y < npc->y + 0x8000 )
        npc->act_no = 10;
      if ( npc->flag & 8 )
        npc->ani_no = 0;
      break;
    case 0xA:
      npc->xm = 0;
      npc->act_no = 11;
      npc->act_wait = 0;
      npc->ani_no = 0;
      goto LABEL_16;
    case 0xB:
LABEL_16:
      if ( ++npc->act_wait > 4 && npc->flag & 8 )
      {
        npc->act_no = 20;
        npc->ani_no = 1;
        npc->count1 = 0;
        npc->ym = -512 * Random(1, 3);
        if ( npc->shock )
        {
          if ( npc->x >= x )
            v1 = npc->xm + 256;
          else
            v1 = npc->xm - 256;
          npc->xm = v1;
        }
        else
        {
          if ( npc->x >= x )
            v2 = npc->xm - 256;
          else
            v2 = npc->xm + 256;
          npc->xm = v2;
        }
      }
      break;
    case 0x14:
      if ( npc->ym > 0 && !npc->count1 )
      {
        ++npc->count1;
        deg = GetArktan(npc->x - x, npc->y + 2048 - y);
        ym = 2 * GetSin(deg);
        xm = 2 * GetCos(deg);
        SetNpChar(50, npc->x, npc->y, xm, ym, 0, 0, 384);
        PlaySoundObject(39, 1);
      }
      if ( npc->flag & 8 )
      {
        npc->act_no = 10;
        npc->ani_no = 0;
      }
      break;
    default:
      break;
  }
  if ( npc->act_no > 9 )
  {
    if ( npc->x <= x )
      npc->direct = 2;
    else
      npc->direct = 0;
  }
  npc->ym += 51;
  if ( npc->ym > 1535 )
    npc->ym = 1535;
  if ( npc->xm > 1535 )
    npc->xm = 1535;
  if ( npc->xm < -1535 )
    npc->xm = -1535;
  npc->y += npc->ym;
  npc->x += npc->xm;
  if ( npc->direct )
  {
    v3 = npc;
    v4 = (Sint32 *)&v10[16 * npc->ani_no - 76];
  }
  else
  {
    v3 = npc;
    v4 = (Sint32 *)&v10[16 * npc->ani_no - 44];
  }
  npc->rect.left = *v4;
  v3->rect.top = v4[1];
  v3->rect.right = v4[2];
  v3->rect.bottom = v4[3];
}


void ActNpc136(NPCHAR *npc)
{
  int v1;
  unsigned __int16 v2;
  NPCHAR *v3;
  Sint32 *v4;
  RECT rcRight[2];
  RECT rcLeft[2];
  char v7[8];

  rcLeft[0].left = 48;
  rcLeft[0].top = 144;
  rcLeft[0].right = 64;
  rcLeft[0].bottom = 160;
  rcLeft[1].left = 64;
  rcLeft[1].top = 144;
  rcLeft[1].right = 80;
  rcLeft[1].bottom = 160;
  rcRight[0].left = 48;
  rcRight[0].top = 160;
  rcRight[0].right = 64;
  rcRight[0].bottom = 176;
  rcRight[1].left = 64;
  rcRight[1].top = 160;
  rcRight[1].right = 80;
  rcRight[1].bottom = 176;
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
    v2 = npc->bits;
    HIBYTE(v2) &= 0xDFu;
    npc->bits = v2;
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
  if ( dir )
    npc->direct = 2;
  else
    npc->direct = 0;
  npc->y = y - 5120;
  if ( npc->direct )
  {
    npc->x = x - 2048;
    v3 = npc;
    v4 = (Sint32 *)&v7[16 * npc->ani_no - 64];
  }
  else
  {
    npc->x = x + 2048;
    v3 = npc;
    v4 = (Sint32 *)&v7[16 * npc->ani_no - 32];
  }
  npc->rect.left = *v4;
  v3->rect.top = v4[1];
  v3->rect.right = v4[2];
  v3->rect.bottom = v4[3];
  if ( unk_81C85C0 & 1 )
    ++npc->rect.top;
}


void ActNpc137(NPCHAR *npc)
{
  npc->rect.left = 96;
  npc->rect.top = 136;
  npc->rect.right = 128;
  npc->rect.bottom = 188;
}

void ActNpc138(NPCHAR *npc)
{
  int v1;
  int v2;

  v1 = npc->act_no;
  if ( v1 != 1 )
  {
    if ( v1 > 1 )
    {
      if ( v1 == 10 )
      {
        npc->act_no = 11;
        npc->ani_no = 1;
        npc->act_wait = 0;
        npc->bits |= 8u;
      }
      else if ( v1 != 11 )
      {
        return;
      }
      if ( !(++npc->act_wait & 7) )
        PlaySoundObject(26, 1);
      if ( npc->direct )
      {
        npc->x = (npc->act_wait / 8 << 9) + npc->tgt_x;
        npc->rect.left = 112;
        npc->rect.top = 112;
        npc->rect.right = 128;
        npc->rect.bottom = 136;
        npc->rect.right -= npc->act_wait / 8;
      }
      else
      {
        npc->rect.left = 96;
        npc->rect.top = 112;
        npc->rect.right = 112;
        npc->rect.bottom = 136;
        npc->rect.left += npc->act_wait / 8;
      }
      if ( npc->act_wait == 104 )
        npc->cond = 0;
    }
    else if ( !v1 )
    {
      npc->act_no = 1;
      if ( npc->direct )
      {
        npc->rect.left = 112;
        npc->rect.top = 112;
        npc->rect.right = 128;
        npc->rect.bottom = 136;
        v2 = npc->x - 4096;
      }
      else
      {
        npc->rect.left = 96;
        npc->rect.top = 112;
        npc->rect.right = 112;
        npc->rect.bottom = 136;
        v2 = npc->x + 4096;
      }
      npc->x = v2;
      npc->tgt_x = npc->x;
    }
  }
}

void ActNpc139(NPCHAR *npc)
{
  int v1;
  NPCHAR *v2;
  Sint32 *v3;
  RECT rcRight[3];
  RECT rcLeft[3];
  char v6[8];

  rcLeft[0].left = 0;
  rcLeft[0].top = 128;
  rcLeft[0].right = 24;
  rcLeft[0].bottom = 160;
  rcLeft[1].left = 24;
  rcLeft[1].top = 128;
  rcLeft[1].right = 48;
  rcLeft[1].bottom = 160;
  rcLeft[2].left = 48;
  rcLeft[2].top = 128;
  rcLeft[2].right = 72;
  rcLeft[2].bottom = 160;
  rcRight[0].left = 0;
  rcRight[0].top = 160;
  rcRight[0].right = 24;
  rcRight[0].bottom = 192;
  rcRight[1].left = 24;
  rcRight[1].top = 160;
  rcRight[1].right = 48;
  rcRight[1].bottom = 192;
  rcRight[2].left = 48;
  rcRight[2].top = 160;
  rcRight[2].right = 72;
  rcRight[2].bottom = 192;
  switch ( npc->act_no )
  {
    case 0:
      npc->act_no = 1;
      npc->xm = 0;
      npc->ym = 0;
      npc->y -= 4096;
      goto LABEL_3;
    case 1:
LABEL_3:
      if ( npc->flag & 8 )
        npc->ani_no = 0;
      else
        npc->ani_no = 2;
      npc->ym += 64;
      break;
    case 0xA:
      npc->act_no = 11;
      npc->ani_no = 1;
      npc->ani_wait = 0;
      npc->count1 = 0;
      goto LABEL_8;
    case 0xB:
LABEL_8:
      if ( ++npc->ani_wait > 6 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 1 )
      {
        npc->ani_no = 0;
        ++npc->count1;
      }
      if ( npc->count1 > 8 )
      {
        npc->ani_no = 0;
        npc->act_no = 1;
      }
      break;
    case 0x14:
      npc->act_no = 21;
      npc->act_wait = 0;
      npc->ani_no = 2;
      npc->tgt_y = npc->y - 0x4000;
      goto LABEL_15;
    case 0x15:
LABEL_15:
      if ( npc->y >= npc->tgt_y )
        v1 = npc->ym - 32;
      else
        v1 = npc->ym + 32;
      npc->ym = v1;
      if ( npc->ym > 512 )
        npc->ym = 512;
      if ( npc->ym < -512 )
        npc->ym = -512;
      break;
    case 0x1E:
      npc->act_no = 31;
      npc->xm = 0;
      npc->ym = 0;
      npc->act_wait = 2 * (npc->rect.bottom - npc->rect.top);
      PlaySoundObject(29, 1);
      goto LABEL_23;
    case 0x1F:
LABEL_23:
      --npc->act_wait;
      npc->ani_no = 0;
      if ( !npc->act_wait )
        npc->cond = 0;
      break;
    case 0x28:
      npc->act_no = 41;
      npc->act_wait = 0;
      npc->xm = 0;
      npc->ym = 0;
      PlaySoundObject(29, 1);
      goto LABEL_26;
    case 0x29:
LABEL_26:
      npc->ani_no = 2;
      if ( ++npc->act_wait > 63 )
        npc->act_no = 20;
      break;
    default:
      break;
  }
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
  if ( npc->act_no == 31 || npc->act_no == 41 )
  {
    npc->rect.bottom = npc->act_wait / 2 + npc->rect.top;
    if ( npc->act_wait / 2 & 1 )
      ++npc->rect.left;
  }
}


