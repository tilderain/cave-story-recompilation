#include "../forNpc.h"
#include "../npcList.h"

void ActNpc080(NPCHAR *npc)
{
  NPCHAR *v1;
  Sint32 *v2;
  RECT rcRight[7];
  RECT rcLeft[7];
  char v5[12];

  qmemcpy(rcLeft, &ActNpc080(NPCHAR *)::C.0, sizeof(rcLeft));
  qmemcpy(rcRight, &ActNpc080(NPCHAR *)::C.1, sizeof(rcRight));
  switch ( npc->act_no )
  {
    case 0:
      npc->bits &= 0xFFDFu;
      npc->act_no = 1;
      npc->damage = 0;
      npc->hit.front = 2048;
      goto LABEL_3;
    case 1:
LABEL_3:
      npc->ani_no = 0;
      if ( npc->x - 0x10000 < x && npc->x + 0x10000 > x && npc->y - 24576 < y && npc->y + 0x4000 > y )
      {
        npc->ani_wait = 0;
        npc->act_no = 2;
      }
      if ( npc->shock )
      {
        npc->ani_no = 1;
        npc->ani_wait = 0;
        npc->act_no = 2;
        npc->bits &= 0xFFDFu;
      }
      if ( x >= npc->x )
        npc->direct = 2;
      else
        npc->direct = 0;
      break;
    case 2:
      if ( ++npc->ani_wait > 6 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 3 )
        npc->ani_no = 0;
      if ( npc->x - 0x2000 < x && npc->x + 0x2000 > x )
      {
        npc->hit.front = 9216;
        npc->act_wait = 0;
        npc->act_no = 3;
        npc->bits |= 0x20u;
        if ( npc->direct )
          npc->xm = 1024;
        else
          npc->xm = -1024;
      }
      if ( x >= npc->x )
      {
        npc->direct = 2;
        npc->xm = 256;
      }
      else
      {
        npc->direct = 0;
        npc->xm = -256;
      }
      break;
    case 3:
      npc->xm = 0;
      if ( ++npc->act_wait > 40 )
      {
        npc->act_wait = 0;
        npc->act_no = 4;
      }
      npc->ani_no = 4;
      break;
    case 4:
      npc->damage = 10;
      if ( ++npc->act_wait > 2 )
      {
        npc->act_wait = 0;
        npc->act_no = 5;
      }
      npc->ani_no = 5;
      break;
    case 5:
      npc->ani_no = 6;
      if ( ++npc->act_wait > 60 )
        npc->act_no = 0;
      break;
    default:
      break;
  }
  if ( npc->xm < 0 && npc->flag & 1 )
    npc->xm = 0;
  if ( npc->xm > 0 && npc->flag & 4 )
    npc->xm = 0;
  npc->ym += 32;
  if ( npc->xm > 1024 )
    npc->xm = 1024;
  if ( npc->xm < -1024 )
    npc->xm = -1024;
  if ( npc->ym > 1535 )
    npc->xm = 1535;
  if ( npc->ym < -1535 )
    npc->xm = -1535;
  npc->x += npc->xm;
  npc->y += npc->ym;
  if ( npc->direct )
  {
    v1 = npc;
    v2 = (Sint32 *)&v5[16 * npc->ani_no - 224];
  }
  else
  {
    v1 = npc;
    v2 = (Sint32 *)&v5[16 * npc->ani_no - 112];
  }
  npc->rect.left = *v2;
  v1->rect.top = v2[1];
  v1->rect.right = v2[2];
  v1->rect.bottom = v2[3];
}


void ActNpc081(NPCHAR *npc)
{
  unsigned int v1;
  NPCHAR *v2;
  Sint32 *v3;
  RECT rcRight[6];
  RECT rcLeft[6];
  char v6[24];

  qmemcpy(rcLeft, &ActNpc081(NPCHAR *)::C.2, sizeof(rcLeft));
  qmemcpy(rcRight, &ActNpc081(NPCHAR *)::C.3, sizeof(rcRight));
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
      if ( Random(0, 100) == 1 )
      {
        npc->act_no = 2;
        npc->act_wait = 0;
        npc->ani_no = 1;
      }
      else
      {
        if ( Random(0, 150) == 1 )
        {
          if ( npc->direct )
            npc->direct = 0;
          else
            npc->direct = 2;
        }
        if ( Random(0, 150) == 1 )
        {
          npc->act_no = 3;
          npc->act_wait = 50;
          npc->ani_no = 0;
        }
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
      goto LABEL_14;
    case 4:
LABEL_14:
      if ( !--npc->act_wait )
        npc->act_no = 0;
      if ( ++npc->ani_wait > 2 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 4 )
        npc->ani_no = 2;
      if ( npc->flag & 1 )
      {
        npc->direct = 2;
        npc->xm = 512;
      }
      if ( npc->flag & 4 )
      {
        npc->direct = 0;
        npc->xm = -512;
      }
      if ( npc->direct )
        npc->xm = 256;
      else
        npc->xm = -256;
      break;
    case 5:
      if ( npc->flag & 8 )
        npc->act_no = 0;
      break;
    default:
      break;
  }
  v1 = npc->act_no;
  if ( v1 <= 4 && (1 << v1) & 0x16 && npc->shock )
  {
    npc->ym = -512;
    npc->ani_no = 5;
    npc->act_no = 5;
    if ( npc->x >= x )
      npc->xm = -256;
    else
      npc->xm = 256;
  }
  npc->ym += 64;
  if ( npc->ym > 1535 )
    npc->ym = 1535;
  npc->x += npc->xm;
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


void ActNpc082(NPCHAR *npc)
{
  unsigned int v1;
  int v2;
  NPCHAR *v3;
  Sint32 *v4;
  RECT rcRight[9];
  RECT rcLeft[9];
  char v7[24];

  switch ( npc->act_no )
  {
    case 0:
      npc->act_no = 1;
      npc->ani_no = 2;
      goto LABEL_3;
    case 1:
LABEL_3:
      if ( Random(0, 120) == 10 )
      {
        npc->act_no = 2;
        npc->act_wait = 0;
        npc->ani_no = 3;
      }
      break;
    case 2:
      if ( ++npc->act_wait > 8 )
      {
        npc->act_no = 1;
        npc->ani_no = 2;
      }
      break;
    case 0xF:
      npc->act_no = 16;
      npc->act_wait = 0;
      npc->ani_no = 4;
      goto LABEL_8;
    case 0x10:
LABEL_8:
      if ( ++npc->act_wait == 30 )
      {
        PlaySoundObject(21, 1);
        SetNpChar(66, npc->x, npc->y - 0x2000, 0, 0, 0, npc, 0);
      }
      if ( npc->act_wait == 50 )
        npc->act_no = 14;
      break;
    case 0x14:
      npc->act_no = 21;
      npc->ani_no = 0;
      npc->ym = 0;
      npc->bits |= 8u;
      goto LABEL_13;
    case 0x15:
LABEL_13:
      npc->ym -= 32;
      if ( npc->y < -4096 )
        npc->cond = 0;
      break;
    case 0x19:
      npc->act_no = 26;
      npc->act_wait = 0;
      npc->ani_no = 5;
      npc->ani_wait = 0;
      goto LABEL_16;
    case 0x1A:
LABEL_16:
      if ( ++npc->ani_no > 7 )
        npc->ani_no = 5;
      if ( ++npc->act_wait == 30 )
      {
        PlaySoundObject(101, 1);
        SetFlash(0, 0, 2);
        npc->act_no = 27;
        npc->ani_no = 7;
      }
      break;
    case 0x1B:
      if ( ++npc->act_wait == 50 )
      {
        npc->act_no = 0;
        npc->ani_no = 0;
      }
      break;
    case 0x1E:
      npc->act_no = 31;
      npc->ani_no = 3;
      npc->ani_wait = 0;
      goto LABEL_23;
    case 0x1F:
LABEL_23:
      if ( ++npc->ani_wait > 10 )
      {
        npc->act_no = 32;
        npc->ani_no = 4;
        npc->ani_wait = 0;
      }
      break;
    case 0x20:
      if ( ++npc->ani_wait > 100 )
      {
        npc->act_no = 1;
        npc->ani_no = 2;
      }
      break;
    case 0x28:
      npc->act_no = 41;
      npc->act_wait = 0;
      goto LABEL_28;
    case 0x29:
LABEL_28:
      npc->ani_no = 4;
      v1 = ++npc->act_wait - 30;
      if ( v1 <= 0x14 && (1 << v1) & 0x100401 )
      {
        v2 = Random(-512, 0);
        SetNpChar(11, npc->x + 4096, npc->y - 4096, 1536, v2, 0, 0, 256);
        PlaySoundObject(33, 1);
      }
      if ( npc->act_wait > 50 )
        npc->act_no = 0;
      break;
    case 0x32:
      npc->ani_no = 8;
      break;
    default:
      break;
  }
  npc->x += npc->xm;
  npc->y += npc->ym;
  qmemcpy(rcLeft, &ActNpc082(NPCHAR *)::C.8, sizeof(rcLeft));
  qmemcpy(rcRight, &ActNpc082(NPCHAR *)::C.9, sizeof(rcRight));
  if ( npc->act_no == 11 )
  {
    if ( npc->ani_wait )
    {
      --npc->ani_wait;
      npc->ani_no = 1;
    }
    else
    {
      if ( Random(0, 100) == 1 )
        npc->ani_wait = 30;
      npc->ani_no = 0;
    }
  }
  if ( npc->act_no == 14 )
  {
    if ( npc->ani_wait )
    {
      --npc->ani_wait;
      npc->ani_no = 3;
    }
    else
    {
      if ( Random(0, 100) == 1 )
        npc->ani_wait = 30;
      npc->ani_no = 2;
    }
  }
  if ( npc->direct )
  {
    v3 = npc;
    v4 = (Sint32 *)&v7[16 * npc->ani_no - 288];
  }
  else
  {
    v3 = npc;
    v4 = (Sint32 *)&v7[16 * npc->ani_no - 144];
  }
  npc->rect.left = *v4;
  v3->rect.top = v4[1];
  v3->rect.right = v4[2];
  v3->rect.bottom = v4[3];
}


void ActNpc083(NPCHAR *npc)
{
  NPCHAR *v1;
  Sint32 *v2;
  RECT rcRight[8];
  RECT rcLeft[8];
  char v5[24];

  qmemcpy(rcLeft, &ActNpc083(NPCHAR *)::C.12, sizeof(rcLeft));
  qmemcpy(rcRight, &ActNpc083(NPCHAR *)::C.13, sizeof(rcRight));
  switch ( npc->act_no )
  {
    case 0:
      npc->xm = 0;
      npc->act_no = 1;
      npc->ani_no = 0;
      npc->ani_wait = 0;
      goto LABEL_3;
    case 1:
LABEL_3:
      if ( ++npc->ani_wait > 5 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 1 )
        npc->ani_no = 0;
      break;
    case 2:
      npc->act_no = 3;
      npc->ani_no = 2;
      npc->ani_wait = 0;
      goto LABEL_8;
    case 3:
LABEL_8:
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
      break;
    case 4:
      npc->xm = 0;
      npc->act_no = 5;
      npc->act_wait = 0;
      npc->ani_no = 6;
      goto LABEL_16;
    case 5:
LABEL_16:
      if ( ++npc->act_wait > 10 )
      {
        npc->act_wait = 0;
        npc->act_no = 6;
        npc->ani_no = 7;
        PlaySoundObject(70, 1);
      }
      break;
    case 6:
      if ( ++npc->act_wait > 8 )
      {
        npc->act_no = 0;
        npc->ani_no = 0;
      }
      break;
    case 7:
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
    v2 = (Sint32 *)&v5[16 * npc->ani_no - 256];
  }
  else
  {
    v1 = npc;
    v2 = (Sint32 *)&v5[16 * npc->ani_no - 128];
  }
  npc->rect.left = *v2;
  v1->rect.top = v2[1];
  v1->rect.right = v2[2];
  v1->rect.bottom = v2[3];
}


void ActNpc084(NPCHAR *npc)
{
  Sint32 *v1;
  RECT rect_left[4];
  char v3[8];

  if ( npc->flag & 0xFF )
  {
    SetCaret(npc->x, npc->y, 2, 0);
    npc->cond = 0;
  }
  npc->y += npc->ym;
  npc->x += npc->xm;
  rect_left[0].left = 48;
  rect_left[0].top = 48;
  rect_left[0].right = 64;
  rect_left[0].bottom = 64;
  rect_left[1].left = 64;
  rect_left[1].top = 48;
  rect_left[1].right = 80;
  rect_left[1].bottom = 64;
  rect_left[2].left = 48;
  rect_left[2].top = 64;
  rect_left[2].right = 64;
  rect_left[2].bottom = 80;
  rect_left[3].left = 64;
  rect_left[3].top = 64;
  rect_left[3].right = 80;
  rect_left[3].bottom = 80;
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
    SetCaret(npc->x, npc->y, 2, 0);
    npc->cond = 0;
  }
}


void ActNpc085(NPCHAR *npc)
{
  int v1;
  NPCHAR *v2;
  Sint32 *v3;
  RECT rcRight[3];
  RECT rcLeft[3];
  char v6[8];

  rcLeft[0].left = 256;
  rcLeft[0].top = 96;
  rcLeft[0].right = 272;
  rcLeft[0].bottom = 120;
  rcLeft[1].left = 256;
  rcLeft[1].top = 96;
  rcLeft[1].right = 272;
  rcLeft[1].bottom = 120;
  rcLeft[2].left = 272;
  rcLeft[2].top = 96;
  rcLeft[2].right = 288;
  rcLeft[2].bottom = 120;
  rcRight[0].left = 256;
  rcRight[0].top = 96;
  rcRight[0].right = 272;
  rcRight[0].bottom = 120;
  rcRight[1].left = 288;
  rcRight[1].top = 96;
  rcRight[1].right = 304;
  rcRight[1].bottom = 120;
  rcRight[2].left = 304;
  rcRight[2].top = 96;
  rcRight[2].right = 320;
  rcRight[2].bottom = 120;
  v1 = npc->act_no;
  if ( v1 )
  {
    if ( v1 == 1 && ++npc->ani_no > 2 )
      npc->ani_no = 1;
  }
  else
  {
    npc->ani_no = 0;
    if ( npc->x - 4096 < x && npc->x + 4096 > x && npc->y - 0x2000 < y && npc->y + 4096 > y )
    {
      PlaySoundObject(43, 1);
      npc->act_no = 1;
    }
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


void ActNpc086(NPCHAR *npc)
{
  int v1;
  Sint32 *v2;
  Sint32 *v3;
  RECT rect3[2];
  RECT rect1[2];
  RECT rcLast;
  char v7[8];

  rect1[0].left = 0;
  rect1[0].top = 80;
  rect1[0].right = 16;
  rect1[0].bottom = 96;
  rect1[1].left = 16;
  rect1[1].top = 80;
  rect1[1].right = 32;
  rect1[1].bottom = 96;
  rect3[0].left = 0;
  rect3[0].top = 112;
  rect3[0].right = 16;
  rect3[0].bottom = 128;
  rect3[1].left = 16;
  rect3[1].top = 112;
  rect3[1].right = 32;
  rect3[1].bottom = 128;
  rcLast.left = 16;
  rcLast.top = 0;
  rcLast.right = 32;
  rcLast.bottom = 16;
  if ( !npc->direct )
  {
    if ( ++npc->ani_wait > 2 )
    {
      npc->ani_wait = 0;
      ++npc->ani_no;
    }
    if ( npc->ani_no > 1 )
      npc->ani_no = 0;
  }
  if ( gBack.type == 5 || gBack.type == 6 )
  {
    if ( !npc->act_no )
    {
      npc->act_no = 1;
      npc->ym = Random(-32, 32);
      npc->xm = Random(127, 256);
    }
    npc->xm -= 8;
    if ( npc->x <= 40959 )
      npc->cond = 0;
    if ( npc->x < -1536 )
      npc->x = -1536;
    if ( npc->flag & 1 )
      npc->xm = 256;
    if ( npc->flag & 2 )
      npc->ym = 64;
    if ( npc->flag & 8 )
      npc->ym = -64;
    npc->x += npc->xm;
    npc->y += npc->ym;
  }
  v1 = npc->exp;
  if ( v1 == 1 )
  {
    v2 = (Sint32 *)&v7[16 * npc->ani_no - 48];
    npc->rect.left = *v2;
    npc->rect.top = v2[1];
    npc->rect.right = v2[2];
    npc->rect.bottom = v2[3];
  }
  else if ( v1 == 3 )
  {
    v3 = (Sint32 *)&v7[16 * npc->ani_no - 80];
    npc->rect.left = *v3;
    npc->rect.top = v3[1];
    npc->rect.right = v3[2];
    npc->rect.bottom = v3[3];
  }
  if ( !npc->direct )
    ++npc->count1;
  if ( npc->count1 > 550 )
    npc->cond = 0;
  if ( npc->count1 > 500 && npc->count1 / 2 & 1 )
    npc->rect.right = 0;
  if ( npc->count1 > 547 )
    npc->rect = rcLast;
}


void ActNpc087(NPCHAR *npc)
{
  int v1;
  Sint32 *v2;
  Sint32 *v3;
  RECT rect6[2];
  RECT rect2[2];
  RECT rcLast;
  char v7[8];

  rect2[0].left = 32;
  rect2[0].top = 80;
  rect2[0].right = 48;
  rect2[0].bottom = 96;
  rect2[1].left = 48;
  rect2[1].top = 80;
  rect2[1].right = 64;
  rect2[1].bottom = 96;
  rect6[0].left = 64;
  rect6[0].top = 80;
  rect6[0].right = 80;
  rect6[0].bottom = 96;
  rect6[1].left = 80;
  rect6[1].top = 80;
  rect6[1].right = 96;
  rect6[1].bottom = 96;
  rcLast.left = 16;
  rcLast.top = 0;
  rcLast.right = 32;
  rcLast.bottom = 16;
  if ( !npc->direct )
  {
    if ( ++npc->ani_wait > 2 )
    {
      npc->ani_wait = 0;
      ++npc->ani_no;
    }
    if ( npc->ani_no > 1 )
      npc->ani_no = 0;
  }
  if ( gBack.type == 5 || gBack.type == 6 )
  {
    if ( !npc->act_no )
    {
      npc->act_no = 1;
      npc->ym = Random(-32, 32);
      npc->xm = Random(127, 256);
    }
    npc->xm -= 8;
    if ( npc->x <= 40959 )
      npc->cond = 0;
    if ( npc->x < -1536 )
      npc->x = -1536;
    if ( npc->flag & 1 )
      npc->xm = 256;
    if ( npc->flag & 2 )
      npc->ym = 64;
    if ( npc->flag & 8 )
      npc->ym = -64;
    npc->x += npc->xm;
    npc->y += npc->ym;
  }
  v1 = npc->exp;
  if ( v1 == 2 )
  {
    v2 = (Sint32 *)&v7[16 * npc->ani_no - 48];
    npc->rect.left = *v2;
    npc->rect.top = v2[1];
    npc->rect.right = v2[2];
    npc->rect.bottom = v2[3];
  }
  else if ( v1 == 6 )
  {
    v3 = (Sint32 *)&v7[16 * npc->ani_no - 80];
    npc->rect.left = *v3;
    npc->rect.top = v3[1];
    npc->rect.right = v3[2];
    npc->rect.bottom = v3[3];
  }
  if ( !npc->direct )
    ++npc->count1;
  if ( npc->count1 > 550 )
    npc->cond = 0;
  if ( npc->count1 > 500 && npc->count1 / 2 & 1 )
    npc->rect.right = 0;
  if ( npc->count1 > 547 )
    npc->rect = rcLast;
}


void ActNpc088(NPCHAR *npc)
{
  int v1;
  int v2;
  int v3;
  int v4;
  int v5;
  int v6;
  char v7;
  NPCHAR *v8;
  Sint32 *v9;
  RECT rcRight[12];
  RECT rcLeft[12];
  int i;
  unsigned __int8 deg;
  int xm;
  int ym;
  char v16[24];

  qmemcpy(rcLeft, &ActNpc088(NPCHAR *)::C.14, sizeof(rcLeft));
  qmemcpy(rcRight, &ActNpc088(NPCHAR *)::C.15, sizeof(rcRight));
  switch ( npc->act_no )
  {
    case 0:
      npc->xm = 0;
      npc->act_no = 1;
      npc->ani_no = 0;
      npc->ani_wait = 0;
      goto LABEL_3;
    case 1:
LABEL_3:
      if ( ++npc->ani_wait > 5 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 1 )
        npc->ani_no = 0;
      if ( ++npc->act_wait > 50 )
        npc->act_no = 2;
      break;
    case 2:
      npc->act_no = 3;
      npc->act_wait = 0;
      npc->ani_no = 2;
      npc->ani_wait = 0;
      if ( ++npc->count1 > 2 && npc->life <= 150 )
      {
        npc->count2 = 1;
        if ( x >= npc->x )
          npc->direct = 0;
        else
          npc->direct = 2;
      }
      else
      {
        npc->count2 = 0;
        if ( x >= npc->x )
          npc->direct = 2;
        else
          npc->direct = 0;
      }
      goto LABEL_17;
    case 3:
LABEL_17:
      ++npc->act_wait;
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
      if ( npc->count2 )
      {
        if ( npc->act_wait > 16 )
        {
          npc->act_no = 9;
          npc->xm = 0;
          npc->ani_no = 10;
        }
      }
      else if ( npc->act_wait <= 50 )
      {
        if ( npc->direct )
        {
          if ( npc->x + 12288 > x )
            npc->act_no = 4;
        }
        else if ( npc->x - 12288 < x )
        {
          npc->act_no = 4;
        }
      }
      else
      {
        npc->ani_no = 8;
        npc->ym = -1024;
        npc->act_no = 7;
        npc->act_wait = 0;
        npc->xm = 3 * npc->xm / 2;
        npc->damage = 2;
      }
      break;
    case 4:
      npc->xm = 0;
      npc->act_no = 5;
      npc->act_wait = 0;
      npc->ani_no = 6;
      goto LABEL_35;
    case 5:
LABEL_35:
      if ( ++npc->act_wait > 12 )
      {
        npc->act_wait = 0;
        npc->act_no = 6;
        npc->ani_no = 7;
        PlaySoundObject(70, 1);
        npc->damage = 5;
        npc->hit.front = 12288;
        npc->hit.top = 1;
      }
      break;
    case 6:
      if ( ++npc->act_wait > 10 )
      {
        npc->act_no = 0;
        npc->ani_no = 0;
        npc->damage = 0;
        npc->hit.front = 4096;
        npc->hit.top = 0x2000;
      }
      break;
    case 7:
      if ( npc->flag & 8 )
      {
        npc->act_no = 8;
        npc->ani_no = 9;
        PlaySoundObject(26, 1);
        SetQuake(30);
        npc->damage = 0;
        for ( i = 0; i <= 3; ++i )
        {
          v1 = Random(-1536, 0);
          v2 = Random(-341, 341);
          v3 = npc->y;
          v4 = (Random(-12, 12) << 9) + v3;
          v5 = npc->x;
          v6 = Random(-12, 12);
          SetNpChar(4, v5 + (v6 << 9), v4, v2, v1, 0, 0, 256);
        }
      }
      break;
    case 8:
      npc->xm = 0;
      if ( ++npc->act_wait > 10 )
      {
        npc->act_no = 0;
        npc->ani_no = 0;
        npc->damage = 0;
      }
      break;
    case 9:
      npc->act_no = 10;
      npc->act_wait = 0;
      if ( x >= npc->x )
        npc->direct = 2;
      else
        npc->direct = 0;
      goto LABEL_49;
    case 0xA:
LABEL_49:
      if ( ++npc->act_wait > 100 && npc->act_wait % 6 == 1 )
      {
        if ( npc->direct )
          deg = -8;
        else
          deg = -120;
        v7 = Random(-16, 16);
        deg += v7;
        ym = 3 * GetSin(deg);
        xm = 3 * GetCos(deg);
        SetNpChar(11, npc->x, npc->y + 2048, xm, ym, 0, 0, 256);
        PlaySoundObject(12, 1);
      }
      if ( npc->act_wait > 50 && npc->act_wait / 2 & 1 )
        npc->ani_no = 11;
      else
        npc->ani_no = 10;
      if ( npc->act_wait > 132 )
      {
        npc->act_no = 0;
        npc->ani_no = 0;
        npc->count1 = 0;
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
    v8 = npc;
    v9 = (Sint32 *)&v16[16 * npc->ani_no - 400];
  }
  else
  {
    v8 = npc;
    v9 = (Sint32 *)&v16[16 * npc->ani_no - 208];
  }
  npc->rect.left = *v9;
  v8->rect.top = v9[1];
  v8->rect.right = v9[2];
  v8->rect.bottom = v9[3];
}


void ActNpc089(NPCHAR *npc)
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
  int v15;
  int v16;
  int v17;
  int v18;
  int v19;
  NPCHAR *v20;
  Sint32 *v21;
  NPCHAR *v22;
  Sint32 *v23;
  RECT rcRight[4];
  RECT rcLeft[4];
  int i;
  char v27[24];

  rcLeft[0].left = 80;
  rcLeft[0].top = 80;
  rcLeft[0].right = 120;
  rcLeft[0].bottom = 120;
  rcLeft[1].left = 240;
  rcLeft[1].top = 80;
  rcLeft[1].right = 264;
  rcLeft[1].bottom = 104;
  rcLeft[2].left = 264;
  rcLeft[2].top = 80;
  rcLeft[2].right = 288;
  rcLeft[2].bottom = 104;
  rcLeft[3].left = 288;
  rcLeft[3].top = 80;
  rcLeft[3].right = 312;
  rcLeft[3].bottom = 104;
  rcRight[0].left = 200;
  rcRight[0].top = 80;
  rcRight[0].right = 240;
  rcRight[0].bottom = 120;
  rcRight[1].left = 240;
  rcRight[1].top = 104;
  rcRight[1].right = 264;
  rcRight[1].bottom = 128;
  rcRight[2].left = 264;
  rcRight[2].top = 104;
  rcRight[2].right = 288;
  rcRight[2].bottom = 128;
  rcRight[3].left = 288;
  rcRight[3].top = 104;
  rcRight[3].right = 312;
  rcRight[3].bottom = 128;
  v1 = npc->act_no;
  if ( v1 == 1 )
  {
LABEL_15:
    if ( ++npc->act_wait > 100 )
    {
      npc->act_wait = 0;
      npc->act_no = 2;
    }
    if ( !(npc->act_wait % 5) )
    {
      v8 = Random(-1536, 0);
      v9 = Random(-341, 341);
      v10 = npc->y;
      v11 = (Random(-12, 12) << 9) + v10;
      v12 = npc->x;
      v13 = Random(-12, 12);
      SetNpChar(4, v12 + (v13 << 9), v11, v9, v8, 0, 0, 256);
    }
    if ( npc->direct )
    {
      npc->rect.left = rcRight[0].left;
      npc->rect.top = rcRight[0].top;
      npc->rect.right = rcRight[0].right;
      npc->rect.bottom = rcRight[0].bottom;
    }
    else
    {
      npc->rect.left = rcLeft[0].left;
      npc->rect.top = rcLeft[0].top;
      npc->rect.right = rcLeft[0].right;
      npc->rect.bottom = rcLeft[0].bottom;
    }
    if ( npc->act_wait / 2 & 1 )
      --npc->rect.left;
    goto LABEL_44;
  }
  if ( v1 <= 1 )
  {
    if ( v1 )
      goto LABEL_44;
    PlaySoundObject(72, 1);
    if ( npc->x <= x )
      npc->direct = 2;
    else
      npc->direct = 0;
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
    npc->act_no = 1;
    goto LABEL_15;
  }
  if ( v1 == 2 )
  {
    if ( ++npc->act_wait / 2 & 1 && npc->act_wait <= 99 )
    {
      npc->ani_no = 0;
      npc->view.back = 10240;
      npc->view.front = 10240;
      npc->view.top = 10240;
    }
    else
    {
      npc->ani_no = 1;
      npc->view.back = 6144;
      npc->view.front = 6144;
      npc->view.top = 4096;
    }
    if ( npc->act_wait > 150 )
    {
      npc->act_wait = 0;
      npc->act_no = 3;
      npc->ani_no = 1;
    }
    if ( !(npc->act_wait % 9) )
    {
      v14 = Random(-1536, 0);
      v15 = Random(-341, 341);
      v16 = npc->y;
      v17 = (Random(-12, 12) << 9) + v16;
      v18 = npc->x;
      v19 = Random(-12, 12);
      SetNpChar(4, v18 + (v19 << 9), v17, v15, v14, 0, 0, 256);
    }
    if ( npc->direct )
    {
      v20 = npc;
      v21 = (Sint32 *)&v27[16 * npc->ani_no - 132];
    }
    else
    {
      v20 = npc;
      v21 = (Sint32 *)&v27[16 * npc->ani_no - 68];
    }
    npc->rect.left = *v21;
    v20->rect.top = v21[1];
    v20->rect.right = v21[2];
    v20->rect.bottom = v21[3];
  }
  else if ( v1 == 3 )
  {
    if ( ++npc->ani_wait > 50 )
    {
      npc->ani_wait = 0;
      ++npc->ani_no;
    }
    if ( npc->ani_no == 3 )
      npc->act_no = 4;
    if ( npc->direct )
    {
      v22 = npc;
      v23 = (Sint32 *)&v27[16 * npc->ani_no - 132];
    }
    else
    {
      v22 = npc;
      v23 = (Sint32 *)&v27[16 * npc->ani_no - 68];
    }
    npc->rect.left = *v23;
    v22->rect.top = v23[1];
    v22->rect.right = v23[2];
    v22->rect.bottom = v23[3];
  }
LABEL_44:
  npc->ym += 64;
  if ( npc->ym > 1535 )
    npc->ym = 1535;
  npc->x += npc->xm;
  npc->y += npc->ym;
}


void ActNpc090(NPCHAR *npc)
{
  npc->rect.left = 280;
  npc->rect.top = 80;
  npc->rect.right = 296;
  npc->rect.bottom = 104;
}

void ActNpc091(NPCHAR *npc)
{
  if ( !npc->act_no )
  {
    ++npc->act_no;
    npc->y += 0x2000;
  }
  npc->rect.left = 96;
  npc->rect.top = 88;
  npc->rect.right = 128;
  npc->rect.bottom = 112;
}

void ActNpc092(NPCHAR *npc)
{
  int v1;
  Sint32 *v2;
  RECT rcLeft[3];
  char v4[8];

  rcLeft[0].left = 272;
  rcLeft[0].top = 216;
  rcLeft[0].right = 288;
  rcLeft[0].bottom = 240;
  rcLeft[1].left = 288;
  rcLeft[1].top = 216;
  rcLeft[1].right = 304;
  rcLeft[1].bottom = 240;
  rcLeft[2].left = 304;
  rcLeft[2].top = 216;
  rcLeft[2].right = 320;
  rcLeft[2].bottom = 240;
  v1 = npc->act_no;
  if ( v1 == 1 )
  {
LABEL_9:
    if ( ++npc->ani_wait > 2 )
    {
      npc->ani_wait = 0;
      ++npc->ani_no;
    }
    if ( npc->ani_no > 1 )
      npc->ani_no = 0;
    if ( Random(0, 80) == 1 )
    {
      npc->act_no = 2;
      npc->act_wait = 0;
      npc->ani_no = 1;
    }
    if ( Random(0, 120) == 10 )
    {
      npc->act_no = 3;
      npc->act_wait = 0;
      npc->ani_no = 2;
    }
    goto LABEL_21;
  }
  if ( v1 <= 1 )
  {
    if ( v1 )
      goto LABEL_21;
    npc->x -= 2048;
    npc->y += 0x2000;
    npc->act_no = 1;
    npc->ani_no = 0;
    npc->ani_wait = 0;
    goto LABEL_9;
  }
  if ( v1 == 2 )
  {
    if ( ++npc->act_wait > 40 )
    {
      npc->act_no = 3;
      npc->act_wait = 0;
      npc->ani_no = 2;
    }
  }
  else if ( v1 == 3 && ++npc->act_wait > 80 )
  {
    npc->act_no = 1;
    npc->ani_no = 0;
  }
LABEL_21:
  v2 = (Sint32 *)&v4[16 * npc->ani_no - 48];
  npc->rect.left = *v2;
  npc->rect.top = v2[1];
  npc->rect.right = v2[2];
  npc->rect.bottom = v2[3];
}


void ActNpc093(NPCHAR *npc)
{
  int v1;
  NPCHAR *v2;
  Sint32 *v3;
  RECT rcRight[7];
  RECT rcLeft[7];
  char v6[24];

  qmemcpy(rcLeft, &ActNpc093(NPCHAR *)::C.18, sizeof(rcLeft));
  qmemcpy(rcRight, &ActNpc093(NPCHAR *)::C.19, sizeof(rcRight));
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
    case 0xA:
      npc->ani_no = 6;
      if ( ++npc->act_wait > 200 )
      {
        npc->act_wait = 0;
        SetCaret(npc->x, npc->y, 5, 0);
      }
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


void ActNpc094(NPCHAR *npc)
{
  int v1;
  Sint32 *v2;
  RECT rect[5];
  char v4[12];

  qmemcpy(rect, &ActNpc094(NPCHAR *)::C.21, sizeof(rect));
  switch ( npc->act_no )
  {
    case 0:
      npc->ani_no = 4;
      if ( npc->shock )
      {
        npc->ani_no = 0;
        npc->act_no = 10;
        npc->act_wait = 0;
      }
      break;
    case 0xA:
      npc->bits |= 0x20u;
      npc->bits &= 0xFFFBu;
      if ( ++npc->act_wait > 40 )
      {
        npc->act_wait = 0;
        npc->ani_wait = 0;
        npc->act_no = 11;
      }
      break;
    case 0xB:
      if ( ++npc->ani_wait > 5 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 2 )
      {
        npc->act_no = 12;
        npc->ani_no = 3;
      }
      break;
    case 0xC:
      npc->ym = -341;
      if ( ++npc->act_wait > 20 )
      {
        npc->act_wait = 0;
        npc->act_no = 10;
        npc->ani_no = 0;
      }
      break;
    case 0x14:
      npc->xm /= 2;
      npc->ym += 32;
      if ( !npc->shock )
      {
        npc->act_wait = 30;
        npc->act_no = 10;
        npc->ani_no = 0;
      }
      break;
    default:
      break;
  }
  if ( npc->shock )
  {
    if ( ++npc->count2 > 12 )
    {
      npc->act_no = 20;
      npc->ani_no = 4;
      npc->bits &= 0xFFDFu;
      npc->bits |= 4u;
    }
  }
  else
  {
    npc->count2 = 0;
  }
  if ( npc->act_no > 9 )
  {
    if ( npc->flag & 1 )
    {
      npc->count1 = 50;
      npc->direct = 2;
    }
    if ( npc->flag & 4 )
    {
      npc->count1 = 50;
      npc->direct = 0;
    }
    if ( npc->count1 )
    {
      --npc->count1;
      if ( npc->direct )
        v1 = npc->xm + 128;
      else
        v1 = npc->xm - 128;
      npc->xm = v1;
    }
    else
    {
      npc->count1 = 50;
      if ( npc->x <= x )
        npc->direct = 2;
      else
        npc->direct = 0;
    }
    npc->ym += 16;
    if ( npc->flag & 8 )
      npc->ym = -1024;
  }
  if ( npc->xm > 256 )
    npc->xm = 256;
  if ( npc->xm < -256 )
    npc->xm = -256;
  if ( npc->ym > 768 )
    npc->ym = 768;
  if ( npc->ym < -768 )
    npc->ym = -768;
  npc->x += npc->xm;
  npc->y += npc->ym;
  v2 = (Sint32 *)&v4[16 * npc->ani_no - 80];
  npc->rect.left = *v2;
  npc->rect.top = v2[1];
  npc->rect.right = v2[2];
  npc->rect.bottom = v2[3];
}


void ActNpc095(NPCHAR *npc)
{
  int v1;
  int v2;
  int v3;
  NPCHAR *v4;
  Sint32 *v5;
  RECT rcRight[4];
  RECT rcLeft[4];
  char v8[8];

  rcLeft[0].left = 208;
  rcLeft[0].top = 64;
  rcLeft[0].right = 224;
  rcLeft[0].bottom = 80;
  rcLeft[1].left = 224;
  rcLeft[1].top = 64;
  rcLeft[1].right = 240;
  rcLeft[1].bottom = 80;
  rcLeft[2].left = 240;
  rcLeft[2].top = 64;
  rcLeft[2].right = 256;
  rcLeft[2].bottom = 80;
  rcLeft[3].left = 256;
  rcLeft[3].top = 64;
  rcLeft[3].right = 272;
  rcLeft[3].bottom = 80;
  rcRight[0].left = 208;
  rcRight[0].top = 80;
  rcRight[0].right = 224;
  rcRight[0].bottom = 96;
  rcRight[1].left = 224;
  rcRight[1].top = 80;
  rcRight[1].right = 240;
  rcRight[1].bottom = 96;
  rcRight[2].left = 240;
  rcRight[2].top = 80;
  rcRight[2].right = 256;
  rcRight[2].bottom = 96;
  rcRight[3].left = 256;
  rcRight[3].top = 80;
  rcRight[3].right = 272;
  rcRight[3].bottom = 96;
  switch ( npc->act_no )
  {
    case 0:
      npc->act_no = 1;
      npc->act_wait = Random(0, 50);
      npc->tgt_y = npc->y;
      npc->tgt_x = npc->x;
      if ( npc->direct )
        npc->xm = -512;
      else
        npc->xm = 512;
      goto LABEL_5;
    case 1:
LABEL_5:
      if ( --npc->act_wait > 0 )
        break;
      npc->act_no = 10;
      goto LABEL_7;
    case 0xA:
LABEL_7:
      if ( ++npc->act_wait > 10 )
      {
        npc->act_wait = 0;
        npc->ani_wait = 0;
        npc->act_no = 11;
      }
      break;
    case 0xB:
      if ( ++npc->ani_wait > 5 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no == 2 )
      {
        if ( npc->direct )
          v1 = npc->xm + 256;
        else
          v1 = npc->xm - 256;
        npc->xm = v1;
        npc->ym -= 512;
      }
      if ( npc->ani_no > 2 )
      {
        npc->act_no = 12;
        npc->ani_no = 3;
      }
      break;
    case 0xC:
      ++npc->act_wait;
      if ( npc->y > npc->tgt_y && npc->act_wait > 10 )
      {
        npc->act_wait = 0;
        npc->act_no = 10;
        npc->ani_no = 0;
      }
      break;
    default:
      break;
  }
  if ( npc->x <= npc->tgt_x )
    npc->direct = 2;
  else
    npc->direct = 0;
  if ( npc->flag & 1 )
  {
    npc->count1 = 50;
    npc->direct = 2;
  }
  if ( npc->flag & 4 )
  {
    npc->count1 = 50;
    npc->direct = 0;
  }
  npc->ym += 32;
  if ( npc->flag & 8 )
    npc->ym = -1024;
  if ( npc->xm > 256 )
    npc->xm = 256;
  if ( npc->xm < -256 )
    npc->xm = -256;
  if ( npc->ym > 512 )
    npc->ym = 512;
  if ( npc->ym < -512 )
    npc->ym = -512;
  if ( npc->shock )
  {
    npc->x += npc->xm / 2;
    v2 = npc->y;
    v3 = npc->ym / 2;
  }
  else
  {
    npc->x += npc->xm;
    v2 = npc->y;
    v3 = npc->ym;
  }
  npc->y = v3 + v2;
  if ( npc->direct )
  {
    v4 = npc;
    v5 = (Sint32 *)&v8[16 * npc->ani_no - 128];
  }
  else
  {
    v4 = npc;
    v5 = (Sint32 *)&v8[16 * npc->ani_no - 64];
  }
  npc->rect.left = *v5;
  v4->rect.top = v5[1];
  v4->rect.right = v5[2];
  v4->rect.bottom = v5[3];
}


void ActNpc096(NPCHAR *npc)
{
  int v1;
  bool v2;
  int v3;
  int v4;
  Sint32 *v5;
  RECT rc[3];
  char v7[8];

  rc[0].left = 272;
  rc[0].top = 120;
  rc[0].right = 288;
  rc[0].bottom = 136;
  rc[1].left = 288;
  rc[1].top = 120;
  rc[1].right = 304;
  rc[1].bottom = 136;
  rc[2].left = 304;
  rc[2].top = 120;
  rc[2].right = 320;
  rc[2].bottom = 136;
  v1 = npc->act_no;
  switch ( v1 )
  {
    case 1:
      goto LABEL_7;
    case 2:
      if ( ++npc->ani_wait > 0 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 2 )
        npc->ani_no = 0;
      v2 = x > npc->x - 163840 && x < npc->x + 163840 && y > npc->y - 122880 && y < npc->y + 122880 && Random(0, 5) == 1;
      if ( v2 )
      {
        v3 = npc->y;
        v4 = Random(-8, 8);
        SetNpChar(199, npc->x, v3 + (v4 << 9), 0, 0, 0, 0, 256);
      }
      if ( y < npc->y + 4096 && y > npc->y - 4096 && x < npc->x && x > npc->x - 49152 )
      {
        unk_81C85B4 -= 136;
        gMC.cond |= 0x20u;
      }
      break;
    case 0:
      if ( npc->direct == 2 )
        npc->act_no = 2;
      else
        npc->ani_no = 1;
LABEL_7:
      npc->ani_no = 0;
      break;
  }
  v5 = (Sint32 *)&v7[16 * npc->ani_no - 48];
  npc->rect.left = *v5;
  npc->rect.top = v5[1];
  npc->rect.right = v5[2];
  npc->rect.bottom = v5[3];
}


void ActNpc097(NPCHAR *npc)
{
  int v1;
  bool v2;
  int v3;
  int v4;
  int v5;
  Sint32 *v6;
  RECT rc[3];
  char v8[8];

  rc[0].left = 272;
  rc[0].top = 136;
  rc[0].right = 288;
  rc[0].bottom = 152;
  rc[1].left = 288;
  rc[1].top = 136;
  rc[1].right = 304;
  rc[1].bottom = 152;
  rc[2].left = 304;
  rc[2].top = 136;
  rc[2].right = 320;
  rc[2].bottom = 152;
  v1 = npc->act_no;
  switch ( v1 )
  {
    case 1:
      goto LABEL_7;
    case 2:
      if ( ++npc->ani_wait > 0 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 2 )
        npc->ani_no = 0;
      v2 = x > npc->x - 163840 && x < npc->x + 163840 && y > npc->y - 122880 && y < npc->y + 122880 && Random(0, 5) == 1;
      if ( v2 )
      {
        v3 = npc->y;
        v4 = npc->x;
        v5 = Random(-8, 8);
        SetNpChar(199, v4 + (v5 << 9), v3, 0, 0, 1, 0, 256);
      }
      if ( x < npc->x + 4096 && x > npc->x - 4096 && y < npc->y && y > npc->y - 49152 )
        unk_81C85B8 -= 136;
      break;
    case 0:
      if ( npc->direct == 2 )
        npc->act_no = 2;
      else
        npc->ani_no = 1;
LABEL_7:
      npc->ani_no = 0;
      break;
  }
  v6 = (Sint32 *)&v8[16 * npc->ani_no - 48];
  npc->rect.left = *v6;
  npc->rect.top = v6[1];
  npc->rect.right = v6[2];
  npc->rect.bottom = v6[3];
}


void ActNpc098(NPCHAR *npc)
{
  int v1;
  bool v2;
  int v3;
  int v4;
  Sint32 *v5;
  RECT rc[3];
  char v7[8];

  rc[0].left = 272;
  rc[0].top = 152;
  rc[0].right = 288;
  rc[0].bottom = 168;
  rc[1].left = 288;
  rc[1].top = 152;
  rc[1].right = 304;
  rc[1].bottom = 168;
  rc[2].left = 304;
  rc[2].top = 152;
  rc[2].right = 320;
  rc[2].bottom = 168;
  v1 = npc->act_no;
  switch ( v1 )
  {
    case 1:
      goto LABEL_7;
    case 2:
      if ( ++npc->ani_wait > 0 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 2 )
        npc->ani_no = 0;
      v2 = x > npc->x - 163840 && x < npc->x + 163840 && y > npc->y - 122880 && y < npc->y + 122880 && Random(0, 5) == 1;
      if ( v2 )
      {
        v3 = npc->y;
        v4 = Random(-8, 8);
        SetNpChar(199, npc->x, v3 + (v4 << 9), 0, 0, 2, 0, 256);
      }
      if ( y < npc->y + 4096 && y > npc->y - 4096 && x < npc->x + 49152 && x > npc->x )
      {
        unk_81C85B4 += 136;
        gMC.cond |= 0x20u;
      }
      break;
    case 0:
      if ( npc->direct == 2 )
        npc->act_no = 2;
      else
        npc->ani_no = 1;
LABEL_7:
      npc->ani_no = 0;
      break;
  }
  v5 = (Sint32 *)&v7[16 * npc->ani_no - 48];
  npc->rect.left = *v5;
  npc->rect.top = v5[1];
  npc->rect.right = v5[2];
  npc->rect.bottom = v5[3];
}


void ActNpc099(NPCHAR *npc)
{
  int v1;
  bool v2;
  int v3;
  int v4;
  int v5;
  Sint32 *v6;
  RECT rc[3];
  char v8[8];

  rc[0].left = 272;
  rc[0].top = 168;
  rc[0].right = 288;
  rc[0].bottom = 184;
  rc[1].left = 288;
  rc[1].top = 168;
  rc[1].right = 304;
  rc[1].bottom = 184;
  rc[2].left = 304;
  rc[2].top = 168;
  rc[2].right = 320;
  rc[2].bottom = 184;
  v1 = npc->act_no;
  switch ( v1 )
  {
    case 1:
      goto LABEL_7;
    case 2:
      if ( ++npc->ani_wait > 0 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 2 )
        npc->ani_no = 0;
      v2 = x > npc->x - 163840 && x < npc->x + 163840 && y > npc->y - 122880 && y < npc->y + 122880 && Random(0, 5) == 1;
      if ( v2 )
      {
        v3 = npc->y;
        v4 = npc->x;
        v5 = Random(-8, 8);
        SetNpChar(199, v4 + (v5 << 9), v3, 0, 0, 3, 0, 256);
      }
      if ( x < npc->x + 4096 && x > npc->x - 4096 && y < npc->y + 49152 && y > npc->y )
        unk_81C85B8 += 136;
      break;
    case 0:
      if ( npc->direct == 2 )
        npc->act_no = 2;
      else
        npc->ani_no = 1;
LABEL_7:
      npc->ani_no = 0;
      break;
  }
  v6 = (Sint32 *)&v8[16 * npc->ani_no - 48];
  npc->rect.left = *v6;
  npc->rect.top = v6[1];
  npc->rect.right = v6[2];
  npc->rect.bottom = v6[3];
}


