//#include "types.h"
#include "SDL_stdinc.h"
#include "windows_wrapper.h"
#include "Tags.h"
#include "forNpc.h"

void ActNpc160(NPCHAR *npc);
void ActNpc161(NPCHAR *npc);
void ActNpc162(NPCHAR *npc);
void ActNpc163(NPCHAR *npc);
void ActNpc164(NPCHAR *npc);
void ActNpc165(NPCHAR *npc);
void ActNpc166(NPCHAR *npc);
void ActNpc167(NPCHAR *npc);
void ActNpc168(NPCHAR *npc);
void ActNpc169(NPCHAR *npc);
void ActNpc170(NPCHAR *npc);
void ActNpc171(NPCHAR *npc);
void ActNpc172(NPCHAR *npc);
void ActNpc173(NPCHAR *npc);
void ActNpc174(NPCHAR *npc);
void ActNpc175(NPCHAR *npc);
void ActNpc176(NPCHAR *npc);
void ActNpc177(NPCHAR *npc);
void ActNpc178(NPCHAR *npc);
void ActNpc179(NPCHAR *npc);

_UNKNOWN ActNpc169(NPCHAR *)::C.12;
_UNKNOWN ActNpc169(NPCHAR *)::C.13;

void ActNpc160(NPCHAR *npc)
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
  NPCHAR *v13;
  Sint32 *v14;
  RECT rect_right[4];
  RECT rect_left[4];
  int i;
  char v18[24];

  switch ( npc->act_no )
  {
    case 0:
      npc->bits &= 0xFFFEu;
      npc->act_no = 1;
      goto LABEL_3;
    case 1:
LABEL_3:
      if ( npc->x >= x )
        npc->direct = 0;
      else
        npc->direct = 2;
      npc->ym = 2560;
      if ( npc->y > 0xFFFF )
      {
        npc->bits &= 0xFFF7u;
        npc->act_no = 2;
      }
      else
      {
        ++npc->count1;
      }
      break;
    case 2:
      npc->ym = 2560;
      if ( npc->flag & 8 )
      {
        DeleteNpCharCode(161, 1);
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
        npc->act_no = 3;
        npc->act_wait = 0;
        SetQuake(30);
        PlaySoundObject(26, 1);
        PlaySoundObject(72, 1);
      }
      if ( npc->y < y && dword_81C8584 & 8 )
        npc->damage = 20;
      else
        npc->damage = 0;
      break;
    case 3:
      npc->damage = 20;
      npc->damage = 0;
      if ( ++npc->act_wait > 24 )
      {
        npc->act_no = 4;
        npc->count1 = 0;
        npc->count2 = 0;
      }
      break;
    case 4:
      gSuperXpos = npc->x;
      gSuperYpos = npc->y;
      if ( npc->shock & 1 )
      {
        v7 = Random(-1536, 1536);
        v8 = Random(-1536, 1536);
        v9 = npc->y;
        v10 = (Random(-12, 12) << 9) + v9;
        v11 = npc->x;
        v12 = Random(-12, 12);
        SetNpChar(161, v11 + (v12 << 9), v10, v8, v7, 0, 0, 256);
        if ( ++npc->count1 > 30 )
        {
          npc->count1 = 0;
          npc->act_no = 5;
          npc->ym = -3072;
          npc->bits |= 8u;
        }
      }
      break;
    case 5:
      gSuperXpos = npc->x;
      gSuperYpos = npc->y;
      if ( ++npc->count1 > 60 )
      {
        npc->count1 = 0;
        npc->act_no = 6;
      }
      break;
    case 6:
      gSuperXpos = x;
      gSuperYpos = 3276800;
      if ( ++npc->count1 > 110 )
      {
        npc->count1 = 10;
        npc->x = x;
        npc->y = 0;
        npc->ym = 1535;
        npc->act_no = 1;
      }
      break;
    default:
      break;
  }
  npc->y += npc->ym;
  switch ( npc->act_no )
  {
    case 0:
    case 1:
      npc->ani_no = 3;
      break;
    case 2:
      npc->ani_no = 3;
      break;
    case 3:
      npc->ani_no = 2;
      break;
    case 4:
      npc->ani_no = 0;
      break;
    case 5:
      npc->ani_no = 3;
      break;
    case 6:
      npc->ani_no = 3;
      break;
    default:
      break;
  }
  rect_left[0].left = 0;
  rect_left[0].top = 0;
  rect_left[0].right = 40;
  rect_left[0].bottom = 24;
  rect_left[1].left = 40;
  rect_left[1].top = 0;
  rect_left[1].right = 80;
  rect_left[1].bottom = 24;
  rect_left[2].left = 80;
  rect_left[2].top = 0;
  rect_left[2].right = 120;
  rect_left[2].bottom = 24;
  rect_left[3].left = 120;
  rect_left[3].top = 0;
  rect_left[3].right = 160;
  rect_left[3].bottom = 24;
  rect_right[0].left = 0;
  rect_right[0].top = 24;
  rect_right[0].right = 40;
  rect_right[0].bottom = 48;
  rect_right[1].left = 40;
  rect_right[1].top = 24;
  rect_right[1].right = 80;
  rect_right[1].bottom = 48;
  rect_right[2].left = 80;
  rect_right[2].top = 24;
  rect_right[2].right = 120;
  rect_right[2].bottom = 48;
  rect_right[3].left = 120;
  rect_right[3].top = 24;
  rect_right[3].right = 160;
  rect_right[3].bottom = 48;
  if ( npc->direct )
  {
    v13 = npc;
    v14 = (Sint32 *)&v18[16 * npc->ani_no - 132];
  }
  else
  {
    v13 = npc;
    v14 = (Sint32 *)&v18[16 * npc->ani_no - 68];
  }
  npc->rect.left = *v14;
  v13->rect.top = v14[1];
  v13->rect.right = v14[2];
  v13->rect.bottom = v14[3];
}


void ActNpc161(NPCHAR *npc)
{
  int v1;
  int v2;
  Sint32 *v3;
  RECT rect[3];
  char v5[8];

  npc->exp = 0;
  if ( npc->x >= gSuperXpos )
    v1 = npc->xm - 64;
  else
    v1 = npc->xm + 64;
  npc->xm = v1;
  if ( npc->y >= gSuperYpos )
    v2 = npc->ym - 64;
  else
    v2 = npc->ym + 64;
  npc->ym = v2;
  if ( npc->xm < -4605 )
    npc->xm = -4605;
  if ( npc->xm > 4605 )
    npc->xm = 4605;
  if ( npc->ym < -4605 )
    npc->ym = -4605;
  if ( npc->ym > 4605 )
    npc->ym = 4605;
  if ( npc->life <= 99 )
  {
    npc->bits &= 0xFFDFu;
    npc->bits &= 0xFFFBu;
    npc->damage = 0;
    npc->ani_no = 2;
  }
  npc->x += npc->xm;
  npc->y += npc->ym;
  if ( npc->ani_no <= 1 )
    npc->ani_no = Random(0, 10) != 2;
  rect[0].left = 0;
  rect[0].top = 48;
  rect[0].right = 16;
  rect[0].bottom = 64;
  rect[1].left = 16;
  rect[1].top = 48;
  rect[1].right = 32;
  rect[1].bottom = 64;
  rect[2].left = 32;
  rect[2].top = 48;
  rect[2].right = 48;
  rect[2].bottom = 64;
  v3 = (Sint32 *)&v5[16 * npc->ani_no - 48];
  npc->rect.left = *v3;
  npc->rect.top = v3[1];
  npc->rect.right = v3[2];
  npc->rect.bottom = v3[3];
}


void ActNpc162(NPCHAR *npc)
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
  int i;

  v1 = npc->act_no;
  if ( v1 == 1 )
  {
LABEL_18:
    if ( !(++npc->count1 & 3) )
    {
      v8 = npc->y;
      v9 = (Random(-12, 12) << 9) + v8;
      v10 = npc->x;
      v11 = Random(-12, 12);
      SetNpChar(161, v10 + (v11 << 9), v9, 0, 0, 0, 0, 256);
    }
    if ( npc->count1 > 160 )
    {
      npc->count1 = 0;
      npc->act_no = 2;
      npc->tgt_y = npc->y;
    }
    goto LABEL_34;
  }
  if ( v1 <= 1 )
  {
    if ( v1 )
      goto LABEL_34;
    DeleteNpCharCode(161, 1);
    PlaySoundObject(72, 1);
    for ( i = 0; i <= 9; ++i )
    {
      v2 = Random(-1536, 1536);
      v3 = Random(-1536, 1536);
      v4 = npc->y;
      v5 = (Random(-12, 12) << 9) + v4;
      v6 = npc->x;
      v7 = Random(-12, 12);
      SetNpChar(4, v6 + (v7 << 9), v5, v3, v2, 0, 0, 256);
    }
    if ( npc->x <= x )
      npc->direct = 2;
    else
      npc->direct = 0;
    if ( npc->direct )
    {
      npc->rect.left = 40;
      npc->rect.top = 24;
      npc->rect.right = 80;
      npc->rect.bottom = 48;
    }
    else
    {
      npc->rect.left = 40;
      npc->rect.top = 0;
      npc->rect.right = 80;
      npc->rect.bottom = 24;
    }
    npc->count1 = 0;
    npc->act_no = 1;
    goto LABEL_18;
  }
  if ( v1 == 2 )
  {
    SetQuake(2);
    if ( ++npc->count1 > 240 )
    {
      npc->rect.left = 0;
      npc->rect.top = 0;
      npc->rect.right = 0;
      npc->rect.bottom = 0;
      npc->count1 = 0;
      npc->act_no = 3;
    }
    else
    {
      if ( npc->direct )
      {
        npc->rect.left = 40;
        npc->rect.top = 24;
        npc->rect.right = 80;
        npc->rect.bottom = 48;
      }
      else
      {
        npc->rect.left = 40;
        npc->rect.top = 0;
        npc->rect.right = 80;
        npc->rect.bottom = 24;
      }
      npc->rect.top += npc->count1 / 8;
      npc->y = (npc->count1 / 8 << 9) + npc->tgt_y;
      npc->rect.left -= npc->count1 / 2 % 2;
    }
    if ( npc->count1 % 3 == 2 )
    {
      v12 = Random(-512, 512);
      v13 = npc->y - 6144;
      v14 = npc->x;
      v15 = Random(-12, 12);
      SetNpChar(161, v14 + (v15 << 9), v13, v12, 256, 0, 0, 256);
    }
    if ( npc->count1 % 4 == 2 )
      PlaySoundObject(21, 1);
  }
  else if ( v1 == 3 && ++npc->count1 > 59 )
  {
    DeleteNpCharCode(161, 1);
    npc->cond = 0;
  }
LABEL_34:
  gSuperXpos = npc->x;
  gSuperYpos = -512000;
}

void ActNpc163(NPCHAR *npc)
{
  int v1;
  NPCHAR *v2;
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


void ActNpc164(NPCHAR *npc)
{
  int v1;
  NPCHAR *v2;
  Sint32 *v3;
  RECT rcRight[2];
  RECT rcLeft[2];
  char v6[8];

  rcLeft[0].left = 224;
  rcLeft[0].top = 0;
  rcLeft[0].right = 240;
  rcLeft[0].bottom = 16;
  rcLeft[1].left = 240;
  rcLeft[1].top = 0;
  rcLeft[1].right = 256;
  rcLeft[1].bottom = 16;
  rcRight[0].left = 224;
  rcRight[0].top = 16;
  rcRight[0].right = 240;
  rcRight[0].bottom = 32;
  rcRight[1].left = 240;
  rcRight[1].top = 16;
  rcRight[1].right = 256;
  rcRight[1].bottom = 32;
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


void ActNpc165(NPCHAR *npc)
{
  int v1;
  RECT *v2;
  RECT rcRight[2];
  RECT rcLeft;

  rcRight[0].left = 192;
  rcRight[0].top = 96;
  rcRight[0].right = 208;
  rcRight[0].bottom = 112;
  rcRight[1].left = 208;
  rcRight[1].top = 96;
  rcRight[1].right = 224;
  rcRight[1].bottom = 112;
  rcLeft.left = 144;
  rcLeft.top = 96;
  rcLeft.right = 160;
  rcLeft.bottom = 112;
  v1 = npc->act_no;
  if ( v1 )
  {
    if ( v1 != 1 )
      goto LABEL_12;
  }
  else
  {
    npc->act_no = 1;
    npc->y += 5120;
  }
  npc->ani_no = npc->direct == 2
             && x > npc->x - 0x4000
             && x < npc->x + 0x4000
             && y > npc->y - 0x2000
             && y < npc->y + 0x2000;
LABEL_12:
  if ( npc->direct )
  {
    v2 = &rcRight[npc->ani_no];
    npc->rect.left = v2->left;
    npc->rect.top = v2->top;
    npc->rect.right = v2->right;
    npc->rect.bottom = v2->bottom;
  }
  else
  {
    npc->rect = rcLeft;
  }
}

void ActNpc166(NPCHAR *npc)
{
  int v1;
  Sint32 *v2;
  RECT rcLeft[2];
  char v4[8];

  rcLeft[0].left = 144;
  rcLeft[0].top = 104;
  rcLeft[0].right = 184;
  rcLeft[0].bottom = 128;
  rcLeft[1].left = 184;
  rcLeft[1].top = 104;
  rcLeft[1].right = 224;
  rcLeft[1].bottom = 128;
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
  v2 = (Sint32 *)&v4[16 * npc->ani_no - 32];
  npc->rect.left = *v2;
  npc->rect.top = v2[1];
  npc->rect.right = v2[2];
  npc->rect.bottom = v2[3];
}


void ActNpc167(NPCHAR *npc)
{
  int v1;
  int v2;
  int v3;
  int v4;
  int v5;
  int v6;
  Sint32 *v7;
  RECT rect[3];
  int i;
  char v10[24];

  rect[0].left = 304;
  rect[0].top = 0;
  rect[0].right = 320;
  rect[0].bottom = 16;
  rect[1].left = 304;
  rect[1].top = 16;
  rect[1].right = 320;
  rect[1].bottom = 32;
  rect[2].left = 0;
  rect[2].top = 0;
  rect[2].right = 0;
  rect[2].bottom = 0;
  switch ( npc->act_no )
  {
    case 0:
      npc->act_no = 1;
      npc->ani_no = 1;
      break;
    case 0xA:
      npc->ani_no = 0;
      npc->ym += 64;
      if ( npc->ym > 1535 )
        npc->ym = 1535;
      npc->y += npc->ym;
      break;
    case 0x14:
      npc->act_no = 21;
      npc->act_wait = 0;
      npc->ani_no = 0;
      PlaySoundObject(29, 1);
      goto LABEL_7;
    case 0x15:
LABEL_7:
      if ( ++npc->ani_no > 2 )
        npc->ani_no = 1;
      if ( ++npc->act_wait > 100 )
      {
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
        npc->cond = 0;
      }
      break;
    default:
      break;
  }
  v7 = (Sint32 *)&v10[16 * npc->ani_no - 52];
  npc->rect.left = *v7;
  npc->rect.top = v7[1];
  npc->rect.right = v7[2];
  npc->rect.bottom = v7[3];
}


void ActNpc168(NPCHAR *npc)
{
  switch ( npc->act_no )
  {
    case 0:
      npc->act_no = 1;
      break;
    case 0xA:
      npc->act_no = 11;
      npc->act_wait = 0;
      npc->tgt_x = npc->x;
      goto LABEL_4;
    case 0xB:
LABEL_4:
      ++npc->act_wait;
      npc->x = npc->tgt_x;
      if ( npc->act_wait / 3 & 1 )
        npc->x += 512;
      break;
    case 0x14:
      npc->act_no = 21;
      npc->act_wait = 0;
      npc->ym = -1024;
      npc->xm = 256;
      PlaySoundObject(25, 1);
      goto LABEL_7;
    case 0x15:
LABEL_7:
      npc->ym += 16;
      npc->x += npc->xm;
      npc->y += npc->ym;
      if ( npc->act_wait && npc->flag & 8 )
      {
        PlaySoundObject(35, 1);
        SetQuake(40);
        npc->act_no = 0;
      }
      if ( !npc->act_wait )
        ++npc->act_wait;
      break;
    default:
      break;
  }
  npc->rect.left = 264;
  npc->rect.top = 56;
  npc->rect.right = 320;
  npc->rect.bottom = 96;
}

void ActNpc169(NPCHAR *npc)
{
  int v1;
  NPCHAR *v2;
  Sint32 *v3;
  RECT rect_right[9];
  RECT rect_left[9];
  char v6[24];

  switch ( npc->act_no )
  {
    case 0:
      npc->act_no = 1;
      npc->ani_no = 0;
      npc->act_wait = 30;
      if ( npc->x <= x )
        npc->direct = 2;
      else
        npc->direct = 0;
      goto LABEL_5;
    case 1:
LABEL_5:
      if ( !--npc->act_wait )
      {
        npc->act_no = 2;
        ++npc->count1;
      }
      break;
    case 2:
      npc->act_no = 3;
      npc->act_wait = 0;
      npc->ani_no = 1;
      npc->ani_wait = 0;
      goto LABEL_8;
    case 3:
LABEL_8:
      if ( ++npc->ani_wait > 3 )
      {
        npc->ani_wait = 0;
        if ( ++npc->ani_no == 2 || npc->ani_no == 4 )
          PlaySoundObject(23, 1);
      }
      if ( npc->ani_no > 4 )
        npc->ani_no = 1;
      if ( npc->direct )
        v1 = npc->xm + 32;
      else
        v1 = npc->xm - 32;
      npc->xm = v1;
      if ( npc->act_wait <= 7 || npc->x - 6144 >= x || npc->x + 6144 <= x || npc->y - 6144 >= y || npc->y + 4096 <= y )
      {
        if ( ++npc->act_wait <= 75 )
        {
          if ( npc->flag & 5 )
          {
            if ( npc->count2 > 4 )
            {
              npc->act_no = 4;
              npc->act_wait = 0;
              npc->ani_no = 7;
              npc->ym = -1535;
            }
            else
            {
              ++npc->count2;
            }
          }
          else
          {
            npc->count2 = 0;
          }
          if ( (npc->count1 & 1) != 1 && npc->act_wait > 25 )
          {
            npc->act_no = 4;
            npc->act_wait = 0;
            npc->ani_no = 7;
            npc->ym = -1535;
          }
        }
        else
        {
          npc->act_no = 9;
          npc->ani_no = 0;
        }
      }
      else
      {
        npc->act_no = 10;
        npc->ani_no = 5;
        gMC.cond |= 2u;
        DamageMyChar(5);
      }
      break;
    case 4:
      if ( npc->x <= x )
        npc->direct = 2;
      else
        npc->direct = 0;
      if ( ++npc->act_wait <= 29 && npc->act_wait % 6 == 1 )
      {
        PlaySoundObject(39, 1);
        SetNpChar(170, npc->x, npc->y, 0, 0, npc->direct, 0, 256);
      }
      if ( npc->flag & 8 )
      {
        npc->act_no = 9;
        npc->ani_no = 8;
        SetQuake(30);
        PlaySoundObject(26, 1);
      }
      if ( npc->act_wait > 7 && npc->x - 6144 < x && npc->x + 6144 > x && npc->y - 6144 < y && npc->y + 4096 > y )
      {
        npc->act_no = 10;
        npc->ani_no = 5;
        gMC.cond |= 2u;
        DamageMyChar(10);
      }
      break;
    case 9:
      npc->xm = 4 * npc->xm / 5;
      if ( !npc->xm )
        npc->act_no = 0;
      break;
    case 0xA:
      x = npc->x;
      y = npc->y;
      npc->xm = 4 * npc->xm / 5;
      if ( !npc->xm )
      {
        npc->act_no = 11;
        npc->act_wait = 0;
        npc->ani_no = 5;
        npc->ani_wait = 0;
      }
      break;
    case 0xB:
      x = npc->x;
      y = npc->y;
      if ( ++npc->ani_wait > 2 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 6 )
        npc->ani_no = 5;
      if ( ++npc->act_wait > 100 )
        npc->act_no = 20;
      break;
    case 0x14:
      PlaySoundObject(25, 1);
      gMC.cond &= 0xFDu;
      if ( npc->direct )
      {
        x -= 2048;
        y -= 4096;
        unk_81C85B4 = -1535;
        unk_81C85B8 = -512;
        dir = 0;
        npc->direct = 0;
      }
      else
      {
        x += 2048;
        y -= 4096;
        unk_81C85B4 = 1535;
        unk_81C85B8 = -512;
        dir = 2;
        npc->direct = 2;
      }
      npc->act_no = 21;
      npc->act_wait = 0;
      npc->ani_no = 7;
      goto LABEL_61;
    case 0x15:
LABEL_61:
      if ( ++npc->act_wait > 49 )
        npc->act_no = 0;
      break;
    default:
      break;
  }
  npc->ym += 32;
  if ( npc->xm < -768 )
    npc->xm = -768;
  if ( npc->xm > 768 )
    npc->xm = 768;
  if ( npc->ym > 1535 )
    npc->ym = 1535;
  npc->x += npc->xm;
  npc->y += npc->ym;
  qmemcpy(rect_left, &ActNpc169(NPCHAR *)::C.12, sizeof(rect_left));
  qmemcpy(rect_right, &ActNpc169(NPCHAR *)::C.13, sizeof(rect_right));
  if ( npc->direct )
  {
    v2 = npc;
    v3 = (Sint32 *)&v6[16 * npc->ani_no - 288];
  }
  else
  {
    v2 = npc;
    v3 = (Sint32 *)&v6[16 * npc->ani_no - 144];
  }
  npc->rect.left = *v3;
  v2->rect.top = v3[1];
  v2->rect.right = v3[2];
  v2->rect.bottom = v3[3];
}


void ActNpc170(NPCHAR *npc)
{
  int v1;
  int v2;
  int v3;
  NPCHAR *v4;
  Sint32 *v5;
  RECT rcRight[2];
  RECT rcLeft[2];
  bool bHit;
  char v9[8];

  rcLeft[0].left = 112;
  rcLeft[0].top = 96;
  rcLeft[0].right = 128;
  rcLeft[0].bottom = 104;
  rcLeft[1].left = 128;
  rcLeft[1].top = 96;
  rcLeft[1].right = 144;
  rcLeft[1].bottom = 104;
  rcRight[0].left = 112;
  rcRight[0].top = 104;
  rcRight[0].right = 128;
  rcRight[0].bottom = 112;
  rcRight[1].left = 128;
  rcRight[1].top = 104;
  rcRight[1].right = 144;
  rcRight[1].bottom = 112;
  bHit = 0;
  if ( !npc->direct && npc->flag & 1 )
    bHit = 1;
  if ( npc->direct == 2 && npc->flag & 4 )
    bHit = 1;
  if ( bHit )
  {
    PlaySoundObject(44, 1);
    SetDestroyNpChar(npc->x, npc->y, 0, 3);
    VanishNpChar(npc);
    return;
  }
  v1 = npc->act_no;
  if ( !v1 )
  {
    npc->act_no = 1;
    if ( npc->direct )
      v2 = Random(-2, -1) << 9;
    else
      v2 = Random(1, 2) << 9;
    npc->xm = v2;
    npc->ym = Random(-2, 0) << 9;
    goto LABEL_16;
  }
  if ( v1 == 1 )
  {
LABEL_16:
    ++npc->count1;
    if ( npc->direct )
    {
      npc->xm += 32;
      if ( npc->count1 % 3 == 1 )
        SetCaret(npc->x - 4096, npc->y, 7, 0);
    }
    else
    {
      npc->xm -= 32;
      if ( npc->count1 % 3 == 1 )
        SetCaret(npc->x + 4096, npc->y, 7, 2);
    }
    if ( npc->count1 > 49 )
    {
      npc->ym = 0;
    }
    else
    {
      if ( npc->y >= y )
        v3 = npc->ym - 32;
      else
        v3 = npc->ym + 32;
      npc->ym = v3;
    }
    if ( ++npc->ani_no > 1 )
      npc->ani_no = 0;
  }
  if ( npc->xm < -1024 )
    npc->xm = -1536;
  if ( npc->xm > 1024 )
    npc->xm = 1536;
  npc->x += npc->xm;
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


void ActNpc171(NPCHAR *npc)
{
  int v1;
  int v2;
  NPCHAR *v3;
  Sint32 *v4;
  RECT rcRight[2];
  RECT rcLeft[2];
  char v7[8];

  rcLeft[0].left = 120;
  rcLeft[0].top = 48;
  rcLeft[0].right = 152;
  rcLeft[0].bottom = 80;
  rcLeft[1].left = 152;
  rcLeft[1].top = 48;
  rcLeft[1].right = 184;
  rcLeft[1].bottom = 80;
  rcRight[0].left = 184;
  rcRight[0].top = 48;
  rcRight[0].right = 216;
  rcRight[0].bottom = 80;
  rcRight[1].left = 216;
  rcRight[1].top = 48;
  rcRight[1].right = 248;
  rcRight[1].bottom = 80;
  if ( npc->x <= x )
    npc->direct = 2;
  else
    npc->direct = 0;
  v1 = npc->act_no;
  if ( v1 == 1 )
  {
LABEL_8:
    if ( npc->act_wait )
    {
      --npc->act_wait;
    }
    else
    {
      npc->act_no = 10;
      npc->ym = 512;
    }
    goto LABEL_11;
  }
  if ( v1 != 10 )
  {
    if ( v1 )
      goto LABEL_35;
    npc->act_no = 1;
    npc->act_wait = Random(0, 50);
    npc->tgt_y = npc->y;
    goto LABEL_8;
  }
LABEL_11:
  if ( ++npc->ani_wait > 0 )
  {
    npc->ani_wait = 0;
    ++npc->ani_no;
  }
  if ( npc->ani_no > 1 )
    npc->ani_no = 0;
  if ( npc->y >= npc->tgt_y )
    v2 = npc->ym - 16;
  else
    v2 = npc->ym + 16;
  npc->ym = v2;
  if ( npc->ym > 512 )
    npc->ym = 512;
  if ( npc->ym < -512 )
    npc->ym = -512;
  npc->y += npc->ym;
  if ( npc->direct )
  {
    if ( y < npc->y + 40960 && y > npc->y - 40960 && x < npc->x + 81920 && x > npc->x )
      ++npc->count1;
  }
  else if ( y < npc->y + 40960 && y > npc->y - 40960 && x < npc->x && x > npc->x - 81920 )
  {
    ++npc->count1;
  }
  if ( npc->count1 > 20 )
  {
    SetNpChar(172, npc->x, npc->y, 0, 0, npc->direct, 0, 256);
    npc->count1 = -100;
    gCurlyShoot_wait = Random(80, 100);
    gCurlyShoot_x = npc->x;
    gCurlyShoot_y = npc->y;
  }
LABEL_35:
  if ( npc->direct )
  {
    v3 = npc;
    v4 = (Sint32 *)&v7[16 * npc->ani_no - 64];
  }
  else
  {
    v3 = npc;
    v4 = (Sint32 *)&v7[16 * npc->ani_no - 32];
  }
  npc->rect.left = *v4;
  v3->rect.top = v4[1];
  v3->rect.right = v4[2];
  v3->rect.bottom = v4[3];
}


void ActNpc172(NPCHAR *npc)
{
  int v1;
  int v2;
  Sint32 *v3;
  RECT rect[3];
  char v5[8];

  rect[0].left = 248;
  rect[0].top = 48;
  rect[0].right = 264;
  rect[0].bottom = 80;
  rect[1].left = 264;
  rect[1].top = 48;
  rect[1].right = 280;
  rect[1].bottom = 80;
  rect[2].left = 280;
  rect[2].top = 48;
  rect[2].right = 296;
  rect[2].bottom = 80;
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
  if ( ++npc->ani_wait > 1 )
  {
    npc->ani_wait = 0;
    ++npc->ani_no;
  }
  if ( npc->ani_no > 2 )
    npc->ani_no = 0;
  if ( npc->direct )
    v2 = npc->x + 512;
  else
    v2 = npc->x - 512;
  npc->x = v2;
  if ( npc->flag & 1 || npc->flag & 4 )
  {
    SetCaret(npc->x, npc->y, 2, 0);
    VanishNpChar(npc);
    return;
  }
LABEL_15:
  v3 = (Sint32 *)&v5[16 * npc->ani_no - 48];
  npc->rect.left = *v3;
  npc->rect.top = v3[1];
  npc->rect.right = v3[2];
  npc->rect.bottom = v3[3];
}


void ActNpc173(NPCHAR *npc)
{
  NPCHAR *v1;
  Sint32 *v2;
  RECT rcRight[4];
  RECT rcLeft[4];
  unsigned __int8 deg;
  int xm;
  int ym;
  char v8[8];

  rcLeft[0].left = 0;
  rcLeft[0].top = 128;
  rcLeft[0].right = 24;
  rcLeft[0].bottom = 152;
  rcLeft[1].left = 24;
  rcLeft[1].top = 128;
  rcLeft[1].right = 48;
  rcLeft[1].bottom = 152;
  rcLeft[2].left = 48;
  rcLeft[2].top = 128;
  rcLeft[2].right = 72;
  rcLeft[2].bottom = 152;
  rcLeft[3].left = 72;
  rcLeft[3].top = 128;
  rcLeft[3].right = 96;
  rcLeft[3].bottom = 152;
  rcRight[0].left = 0;
  rcRight[0].top = 152;
  rcRight[0].right = 24;
  rcRight[0].bottom = 176;
  rcRight[1].left = 24;
  rcRight[1].top = 152;
  rcRight[1].right = 48;
  rcRight[1].bottom = 176;
  rcRight[2].left = 48;
  rcRight[2].top = 152;
  rcRight[2].right = 72;
  rcRight[2].bottom = 176;
  rcRight[3].left = 72;
  rcRight[3].top = 152;
  rcRight[3].right = 96;
  rcRight[3].bottom = 176;
  if ( npc->x <= x + 163840 && npc->x >= x - 163840 && npc->y <= y + 122880 && npc->y >= y - 122880 )
  {
    switch ( npc->act_no )
    {
      case 0:
        npc->tgt_x = npc->x;
        npc->act_no = 1;
        goto LABEL_7;
      case 1:
LABEL_7:
        npc->ani_no = 0;
        npc->xm = 0;
        if ( npc->act_wait > 4 )
        {
          if ( npc->x - 98304 < x && npc->x + 98304 > x && npc->y - 81920 < y && npc->y + 81920 > y )
          {
            npc->act_no = 10;
            npc->act_wait = 0;
            npc->ani_no = 1;
          }
        }
        else
        {
          ++npc->act_wait;
        }
        break;
      case 0xA:
        if ( ++npc->act_wait > 3 )
        {
          if ( ++npc->count1 == 3 )
          {
            PlaySoundObject(30, 1);
            npc->count1 = 0;
            npc->act_no = 25;
            npc->act_wait = 0;
            npc->ani_no = 2;
            npc->ym = -1536;
            if ( npc->x >= npc->tgt_x )
              npc->xm = -128;
            else
              npc->xm = 128;
          }
          else
          {
            PlaySoundObject(30, 1);
            npc->act_no = 20;
            npc->ani_no = 2;
            npc->ym = -512;
            if ( npc->x >= npc->tgt_x )
              npc->xm = -512;
            else
              npc->xm = 512;
          }
        }
        break;
      case 0x14:
        ++npc->act_wait;
        if ( npc->flag & 8 )
        {
          PlaySoundObject(23, 1);
          npc->ani_no = 1;
          npc->act_no = 30;
          npc->act_wait = 0;
        }
        break;
      case 0x19:
        if ( ++npc->act_wait == 30 || npc->act_wait == 40 )
        {
          deg = GetArktan(npc->x - x, npc->y - y);
          deg += Random(-6, 6);
          ym = 3 * GetSin(deg);
          xm = 3 * GetCos(deg);
          SetNpChar(174, npc->x, npc->y, xm, ym, 0, 0, 256);
          PlaySoundObject(39, 1);
          npc->ani_no = 3;
          gCurlyShoot_wait = Random(80, 100);
          gCurlyShoot_x = npc->x;
          gCurlyShoot_y = npc->y;
        }
        if ( npc->act_wait == 35 || npc->act_wait == 45 )
          npc->ani_no = 2;
        if ( npc->flag & 8 )
        {
          PlaySoundObject(23, 1);
          npc->ani_no = 1;
          npc->act_no = 30;
          npc->act_wait = 0;
        }
        break;
      case 0x1E:
        npc->xm = 7 * npc->xm / 8;
        if ( ++npc->act_wait > 3 )
        {
          npc->ani_no = 0;
          npc->act_no = 1;
          npc->act_wait = 0;
        }
        break;
      default:
        break;
    }
    npc->ym += 51;
    if ( x >= npc->x )
      npc->direct = 2;
    else
      npc->direct = 0;
    if ( npc->ym > 1535 )
      npc->ym = 1535;
    if ( npc->ym < -1535 )
      npc->ym = 1535;
    npc->x += npc->xm;
    npc->y += npc->ym;
    if ( npc->direct )
    {
      v1 = npc;
      v2 = (Sint32 *)&v8[16 * npc->ani_no - 140];
    }
    else
    {
      v1 = npc;
      v2 = (Sint32 *)&v8[16 * npc->ani_no - 76];
    }
    npc->rect.left = *v2;
    v1->rect.top = v2[1];
    v1->rect.right = v2[2];
    v1->rect.bottom = v2[3];
    if ( npc->life <= 985 )
    {
      SetDestroyNpChar(npc->x, npc->y, 0, 2);
      npc->code_char = 154;
      npc->act_no = 0;
    }
  }
}


void ActNpc174(NPCHAR *npc)
{
  int v1;
  Sint32 *v2;
  RECT rect_left[3];
  bool bHit;
  char v5[8];

  v1 = npc->act_no;
  if ( v1 == 1 )
  {
LABEL_6:
    npc->x += npc->xm;
    npc->y += npc->ym;
    bHit = 0;
    if ( npc->flag & 1 )
    {
      bHit = 1;
      npc->xm = 512;
    }
    if ( npc->flag & 4 )
    {
      bHit = 1;
      npc->xm = -512;
    }
    if ( npc->flag & 2 )
    {
      bHit = 1;
      npc->ym = 512;
    }
    if ( npc->flag & 8 )
    {
      bHit = 1;
      npc->ym = -512;
    }
    if ( bHit )
    {
      npc->act_no = 2;
      ++npc->count1;
      PlaySoundObject(31, 1);
    }
    goto LABEL_19;
  }
  if ( v1 != 2 )
  {
    if ( v1 )
      goto LABEL_19;
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
LABEL_19:
  if ( npc->ym > 1535 )
    npc->ym = 1535;
  if ( npc->ym < -1535 )
    npc->ym = -1535;
  rect_left[0].left = 120;
  rect_left[0].top = 80;
  rect_left[0].right = 136;
  rect_left[0].bottom = 96;
  rect_left[1].left = 136;
  rect_left[1].top = 80;
  rect_left[1].right = 152;
  rect_left[1].bottom = 96;
  rect_left[2].left = 152;
  rect_left[2].top = 80;
  rect_left[2].right = 168;
  rect_left[2].bottom = 96;
  if ( ++npc->ani_no > 2 )
    npc->ani_no = 0;
  v2 = (Sint32 *)&v5[16 * npc->ani_no - 52];
  npc->rect.left = *v2;
  npc->rect.top = v2[1];
  npc->rect.right = v2[2];
  npc->rect.bottom = v2[3];
}


void ActNpc175(NPCHAR *npc)
{
  int v1;
  NPCHAR *v2;
  Sint32 *v3;
  RECT rcRight[2];
  RECT rcLeft[2];
  char v6[8];

  rcLeft[0].left = 168;
  rcLeft[0].top = 80;
  rcLeft[0].right = 192;
  rcLeft[0].bottom = 104;
  rcLeft[1].left = 192;
  rcLeft[1].top = 80;
  rcLeft[1].right = 216;
  rcLeft[1].bottom = 104;
  rcRight[0].left = 216;
  rcRight[0].top = 80;
  rcRight[0].right = 240;
  rcRight[0].bottom = 104;
  rcRight[1].left = 240;
  rcRight[1].top = 80;
  rcRight[1].right = 264;
  rcRight[1].bottom = 104;
  if ( npc->act_no <= 2 && npc->life <= 89 )
  {
    LoseNpChar(npc, 0);
    npc->act_no = 10;
    npc->ani_no = 1;
    npc->bits &= 0xFFDFu;
    npc->damage = 0;
  }
  if ( !npc->act_no )
  {
    npc->ani_no = 0;
    npc->act_no = 1;
  }
  if ( npc->direct )
    v1 = npc->ym - 32;
  else
    v1 = npc->ym + 32;
  npc->ym = v1;
  if ( npc->ym < -1535 )
    npc->ym = -1535;
  if ( npc->ym > 1535 )
    npc->ym = 1535;
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
}


void ActNpc176(NPCHAR *npc)
{
  int v1;
  NPCHAR *v2;
  Sint32 *v3;
  RECT rcRight[3];
  RECT rcLeft[3];
  char v6[8];

  rcLeft[0].left = 96;
  rcLeft[0].top = 128;
  rcLeft[0].right = 128;
  rcLeft[0].bottom = 144;
  rcLeft[1].left = 128;
  rcLeft[1].top = 128;
  rcLeft[1].right = 160;
  rcLeft[1].bottom = 144;
  rcLeft[2].left = 160;
  rcLeft[2].top = 128;
  rcLeft[2].right = 192;
  rcLeft[2].bottom = 144;
  rcRight[0].left = 96;
  rcRight[0].top = 144;
  rcRight[0].right = 128;
  rcRight[0].bottom = 160;
  rcRight[1].left = 128;
  rcRight[1].top = 144;
  rcRight[1].right = 160;
  rcRight[1].bottom = 160;
  rcRight[2].left = 160;
  rcRight[2].top = 144;
  rcRight[2].right = 192;
  rcRight[2].bottom = 160;
  if ( npc->act_no <= 2 && npc->life <= 939 )
  {
    LoseNpChar(npc, 0);
    npc->act_no = 10;
    npc->ani_no = 2;
    npc->bits &= 0xFFDFu;
    npc->damage = 0;
  }
  v1 = npc->act_no;
  if ( v1 == 1 )
  {
LABEL_8:
    if ( npc->direct )
    {
      if ( npc->x < x + 81920 && npc->x > x - 81920 && npc->y < y + 0x2000 && npc->y > y - 81920 )
        ++npc->count1;
    }
    else if ( npc->x < x + 81920 && npc->x > x - 81920 && npc->y < y + 81920 && npc->y > y - 0x2000 )
    {
      ++npc->count1;
    }
    if ( npc->count1 > 10 )
    {
      npc->act_no = 2;
      npc->act_wait = 0;
    }
    goto LABEL_33;
  }
  if ( v1 != 2 )
  {
    if ( v1 )
      goto LABEL_33;
    npc->act_no = 1;
    npc->ani_no = 0;
    npc->ani_wait = 0;
    goto LABEL_8;
  }
  if ( ++npc->ani_wait > 3 )
  {
    npc->ani_wait = 0;
    ++npc->ani_no;
  }
  if ( npc->ani_no > 1 )
    npc->ani_no = 0;
  if ( ++npc->act_wait > 10 )
  {
    if ( ++npc->count2 <= 2 )
    {
      npc->count1 = -10;
    }
    else
    {
      npc->count2 = 0;
      npc->count1 = -90;
    }
    if ( npc->direct )
      SetNpChar(177, npc->x, npc->y + 4096, 0, 0, 2, 0, 256);
    else
      SetNpChar(177, npc->x, npc->y - 4096, 0, 0, 0, 0, 256);
    PlaySoundObject(39, 1);
    npc->act_no = 0;
    npc->ani_no = 0;
    gCurlyShoot_wait = Random(80, 100);
    gCurlyShoot_x = npc->x;
    gCurlyShoot_y = npc->y;
  }
LABEL_33:
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


void ActNpc177(NPCHAR *npc)
{
  int v1;
  int v2;
  int v3;
  int v4;
  Sint32 *v5;
  RECT rc[2];
  char v7[8];

  rc[0].left = 192;
  rc[0].top = 128;
  rc[0].right = 208;
  rc[0].bottom = 144;
  rc[1].left = 208;
  rc[1].top = 128;
  rc[1].right = 224;
  rc[1].bottom = 144;
  if ( npc->flag & 0xFF )
  {
    SetCaret(npc->x, npc->y, 3, 0);
    npc->cond = 0;
    return;
  }
  v1 = npc->act_no;
  switch ( v1 )
  {
    case 1:
      goto LABEL_9;
    case 10:
      if ( npc->x >= npc->tgt_x )
        v2 = npc->xm - 32;
      else
        v2 = npc->xm + 32;
      npc->xm = v2;
      if ( npc->y >= npc->tgt_y )
        v3 = npc->ym - 32;
      else
        v3 = npc->ym + 32;
      npc->ym = v3;
      if ( ++npc->act_wait > 300 )
      {
        SetCaret(npc->x, npc->y, 3, 0);
        npc->cond = 0;
        return;
      }
      if ( npc->direct )
        v4 = npc->tgt_x + 512;
      else
        v4 = npc->tgt_x - 512;
      npc->tgt_x = v4;
      break;
    case 0:
      npc->act_no = 1;
      if ( npc->direct )
        npc->ym = 1536;
      else
        npc->ym = -1536;
LABEL_9:
      if ( npc->y < y + 0x2000 && npc->y > y - 0x2000 )
      {
        npc->act_no = 10;
        npc->tgt_x = npc->x;
        npc->tgt_y = npc->y;
        if ( npc->x <= x )
          npc->direct = 2;
        else
          npc->direct = 0;
        npc->xm = (2 * Random(0, 1) - 1) << 9;
        npc->ym = (2 * Random(0, 1) - 1) << 9;
      }
      break;
  }
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
  if ( ++npc->ani_wait > 6 )
  {
    npc->ani_wait = 0;
    ++npc->ani_no;
  }
  if ( npc->ani_no > 1 )
    npc->ani_no = 0;
  v5 = (Sint32 *)&v7[16 * npc->ani_no - 32];
  npc->rect.left = *v5;
  npc->rect.top = v5[1];
  npc->rect.right = v5[2];
  npc->rect.bottom = v5[3];
}


void ActNpc178(NPCHAR *npc)
{
  int v1;
  int v2;
  Sint32 *v3;
  RECT rect_left[3];
  char v5[8];

  if ( npc->flag & 0xFF )
  {
    SetCaret(npc->x, npc->y, 2, 0);
    npc->cond = 0;
  }
  if ( npc->flag & 0x100 )
  {
    npc->y += npc->ym / 2;
    v1 = npc->x;
    v2 = npc->xm / 2;
  }
  else
  {
    npc->y += npc->ym;
    v1 = npc->x;
    v2 = npc->xm;
  }
  npc->x = v2 + v1;
  rect_left[0].left = 0;
  rect_left[0].top = 224;
  rect_left[0].right = 16;
  rect_left[0].bottom = 240;
  rect_left[1].left = 16;
  rect_left[1].top = 224;
  rect_left[1].right = 32;
  rect_left[1].bottom = 240;
  rect_left[2].left = 32;
  rect_left[2].top = 224;
  rect_left[2].right = 48;
  rect_left[2].bottom = 240;
  if ( ++npc->ani_wait > 1 )
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
  if ( ++npc->count1 > 150 )
  {
    VanishNpChar(npc);
    SetCaret(npc->x, npc->y, 2, 0);
  }
}


void ActNpc179(NPCHAR *npc)
{
  Sint32 *v1;
  RECT rect_left[3];
  char v3[8];

  if ( npc->flag & 0xFF )
  {
    npc->cond = 0;
    SetCaret(npc->x, npc->y, 2, 0);
  }
  npc->xm -= 32;
  npc->ym = 0;
  if ( npc->xm < -1024 )
    npc->xm = -1024;
  npc->y += npc->ym;
  npc->x += npc->xm;
  rect_left[0].left = 48;
  rect_left[0].top = 224;
  rect_left[0].right = 72;
  rect_left[0].bottom = 240;
  rect_left[1].left = 72;
  rect_left[1].top = 224;
  rect_left[1].right = 96;
  rect_left[1].bottom = 240;
  rect_left[2].left = 96;
  rect_left[2].top = 224;
  rect_left[2].right = 120;
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
    VanishNpChar(npc);
    SetCaret(npc->x, npc->y, 2, 0);
  }
}


