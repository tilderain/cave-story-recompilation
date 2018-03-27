#include "../npcList.h"
#include "../forNpc.h"

void ActNpc060(NPCHAR *npc)
{
  int v1;
  bool v2;
  int v3;
  bool v4;
  int v5;
  bool v6;
  unsigned __int16 v7;
  NPCHAR *v8;
  Sint32 *v9;
  RECT rcRight[8];
  RECT rcLeft[8];
  char v12[24];

  qmemcpy(rcLeft, &ActNpc060(NPCHAR *)::C.0, sizeof(rcLeft));
  qmemcpy(rcRight, &ActNpc060(NPCHAR *)::C.1, sizeof(rcRight));
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
      if ( npc->x - 0x2000 < x && npc->x + 0x2000 > x && npc->y - 0x2000 < y && npc->y + 0x2000 > y )
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
      npc->ani_no = 1;
      npc->ani_wait = 0;
      goto LABEL_15;
    case 4:
LABEL_15:
      if ( ++npc->ani_wait > 2 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 4 )
        npc->ani_no = 1;
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
        npc->xm = 1024;
      else
        npc->xm = -1024;
      break;
    case 6:
      npc->act_no = 7;
      npc->act_wait = 0;
      npc->ani_no = 1;
      npc->ani_wait = 0;
      npc->ym = -1024;
      goto LABEL_27;
    case 7:
LABEL_27:
      if ( ++npc->ani_wait > 2 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 4 )
        npc->ani_no = 1;
      if ( npc->direct )
        npc->xm = 256;
      else
        npc->xm = -256;
      v1 = npc->act_wait;
      npc->act_wait = v1 + 1;
      v2 = v1 != 0 && npc->flag & 8;
      if ( v2 )
        npc->act_no = 3;
      break;
    case 8:
      npc->ani_no = 1;
      npc->act_wait = 0;
      npc->act_no = 9;
      npc->ym = -512;
      goto LABEL_41;
    case 9:
LABEL_41:
      v3 = npc->act_wait;
      npc->act_wait = v3 + 1;
      v4 = v3 != 0 && npc->flag & 8;
      if ( v4 )
        npc->act_no = 0;
      break;
    case 0xA:
      npc->act_no = 11;
      npc->ani_no = 6;
      npc->ym = -1024;
      PlaySoundObject(50, 1);
      if ( npc->direct )
        npc->xm = 256;
      else
        npc->xm = -256;
      break;
    case 0xB:
      v5 = npc->act_wait;
      npc->act_wait = v5 + 1;
      v6 = v5 != 0 && npc->flag & 8;
      if ( v6 )
      {
        npc->act_no = 12;
        npc->ani_no = 7;
        v7 = npc->bits;
        HIBYTE(v7) |= 0x20u;
        npc->bits = v7;
      }
      break;
    case 0xC:
      npc->xm = 0;
      break;
    default:
      break;
  }
  npc->ym += 64;
  if ( npc->xm > 1024 )
    npc->xm = 1024;
  if ( npc->xm < -1024 )
    npc->xm = -1024;
  if ( npc->ym > 1535 )
    npc->ym = 1535;
  npc->x += npc->xm;
  npc->y += npc->ym;
  if ( npc->direct )
  {
    v8 = npc;
    v9 = (Sint32 *)&v12[16 * npc->ani_no - 256];
  }
  else
  {
    v8 = npc;
    v9 = (Sint32 *)&v12[16 * npc->ani_no - 128];
  }
  npc->rect.left = *v9;
  v8->rect.top = v9[1];
  v8->rect.right = v9[2];
  v8->rect.bottom = v9[3];
}


void ActNpc061(NPCHAR *npc)
{
  int v1;
  bool v2;
  int v3;
  int v4;
  int v5;
  int v6;
  int v7;
  int v8;
  NPCHAR *v9;
  Sint32 *v10;
  RECT rcRight[11];
  RECT rcLeft[11];
  int i;
  char v14[24];

  qmemcpy(rcLeft, &ActNpc061(NPCHAR *)::C.9, sizeof(rcLeft));
  qmemcpy(rcRight, &ActNpc061(NPCHAR *)::C.10, sizeof(rcRight));
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
    case 5:
      npc->ani_no = 3;
      npc->xm = 0;
      break;
    case 6:
      npc->act_no = 7;
      npc->act_wait = 0;
      npc->ani_wait = 0;
      npc->ym = -1024;
      goto LABEL_9;
    case 7:
LABEL_9:
      npc->ani_no = 2;
      if ( npc->direct )
        npc->xm = 512;
      else
        npc->xm = -512;
      v1 = npc->act_wait;
      npc->act_wait = v1 + 1;
      v2 = v1 != 0 && npc->flag & 8;
      if ( v2 )
        npc->act_no = 5;
      break;
    case 8:
      npc->act_no = 9;
      npc->ani_no = 4;
      npc->ani_wait = 0;
      goto LABEL_19;
    case 9:
LABEL_19:
      if ( ++npc->ani_wait > 4 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 7 )
        npc->ani_no = 4;
      if ( npc->direct )
        npc->xm = 512;
      else
        npc->xm = -512;
      break;
    case 0xA:
      npc->act_no = 11;
      npc->ani_no = 4;
      npc->ani_wait = 0;
      goto LABEL_27;
    case 0xB:
LABEL_27:
      if ( ++npc->ani_wait > 2 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 7 )
        npc->ani_no = 4;
      if ( npc->direct )
        npc->xm = 1024;
      else
        npc->xm = -1024;
      break;
    case 0x14:
      SetNpChar(145, 0, 0, 0, 0, 2, npc, 256);
      npc->ani_no = 0;
      npc->act_no = 0;
      break;
    case 0x1E:
      npc->act_no = 31;
      npc->act_wait = 0;
      npc->ani_wait = 0;
      npc->ym = 0;
      goto LABEL_36;
    case 0x1F:
LABEL_36:
      npc->ani_no = 2;
      if ( npc->direct )
        npc->xm = 1536;
      else
        npc->xm = -1536;
      if ( npc->flag & 1 )
      {
        npc->direct = 2;
        npc->act_no = 7;
        npc->act_wait = 0;
        npc->ani_wait = 0;
        npc->ym = -1024;
        npc->xm = 512;
        PlaySoundObject(71, 1);
        SetDestroyNpChar(npc->x, npc->y, 2048, 4);
      }
      break;
    case 0x28:
      npc->act_no = 42;
      npc->act_wait = 0;
      npc->ani_no = 8;
      PlaySoundObject(29, 1);
      goto LABEL_42;
    case 0x2A:
LABEL_42:
      if ( ++npc->ani_no > 9 )
        npc->ani_no = 8;
      if ( ++npc->act_wait > 100 )
      {
        for ( i = 0; i <= 3; ++i )
        {
          v3 = Random(-1536, 0);
          v4 = Random(-341, 341);
          v5 = npc->y;
          v6 = (Random(-12, 12) << 9) + v5;
          v7 = npc->x;
          v8 = Random(-12, 12);
          SetNpChar(4, v7 + (v8 << 9), v6, v4, v3, 0, 0, 256);
        }
        npc->act_no = 50;
        npc->surf = 20;
        npc->ani_no = 10;
      }
      break;
    case 0x3C:
      npc->ani_no = 6;
      npc->act_no = 61;
      npc->ym = -1535;
      npc->xm = 1024;
      npc->count2 = 1;
      break;
    case 0x3D:
      npc->ym += 64;
      if ( npc->flag & 8 )
      {
        npc->act_no = 0;
        npc->count2 = 0;
        npc->xm = 0;
      }
      break;
    default:
      break;
  }
  if ( npc->act_no <= 29 || npc->act_no > 39 )
  {
    npc->ym += 64;
    if ( npc->xm > 1024 )
      npc->xm = 1024;
    if ( npc->xm < -1024 )
      npc->xm = -1024;
    if ( npc->ym > 1535 )
      npc->ym = 1535;
  }
  npc->x += npc->xm;
  npc->y += npc->ym;
  if ( npc->direct )
  {
    v9 = npc;
    v10 = (Sint32 *)&v14[16 * npc->ani_no - 356];
  }
  else
  {
    v9 = npc;
    v10 = (Sint32 *)&v14[16 * npc->ani_no - 180];
  }
  npc->rect.left = *v10;
  v9->rect.top = v10[1];
  v9->rect.right = v10[2];
  v9->rect.bottom = v10[3];
}


void ActNpc062(NPCHAR *npc)
{
  int v1;
  Sint32 *v2;
  RECT rcLeft[3];
  char v4[8];

  rcLeft[0].left = 272;
  rcLeft[0].top = 192;
  rcLeft[0].right = 288;
  rcLeft[0].bottom = 216;
  rcLeft[1].left = 288;
  rcLeft[1].top = 192;
  rcLeft[1].right = 304;
  rcLeft[1].bottom = 216;
  rcLeft[2].left = 304;
  rcLeft[2].top = 192;
  rcLeft[2].right = 320;
  rcLeft[2].bottom = 216;
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


void ActNpc063(NPCHAR *npc)
{
  int v1;
  bool v2;
  int v3;
  int v4;
  bool v5;
  unsigned __int16 v6;
  NPCHAR *v7;
  Sint32 *v8;
  RECT rcRight[6];
  RECT rcLeft[6];
  char v11[12];

  qmemcpy(rcLeft, &ActNpc063(NPCHAR *)::C.16, sizeof(rcLeft));
  qmemcpy(rcRight, &ActNpc063(NPCHAR *)::C.17, sizeof(rcRight));
  switch ( npc->act_no )
  {
    case 0:
      npc->act_no = 1;
      npc->act_wait = 0;
      npc->ani_wait = 0;
      npc->ym = -1024;
      goto LABEL_3;
    case 1:
LABEL_3:
      if ( npc->ym > 0 )
        npc->bits &= 0xFFF7u;
      if ( ++npc->ani_wait > 2 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 3 )
        npc->ani_no = 0;
      if ( npc->direct )
        npc->xm = 256;
      else
        npc->xm = -256;
      v1 = npc->act_wait;
      npc->act_wait = v1 + 1;
      v2 = v1 != 0 && npc->flag & 8;
      if ( v2 )
        npc->act_no = 2;
      break;
    case 2:
      npc->act_no = 3;
      npc->act_wait = 0;
      npc->ani_no = 0;
      npc->ani_wait = 0;
      goto LABEL_19;
    case 3:
LABEL_19:
      if ( ++npc->ani_wait > 2 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 3 )
        npc->ani_no = 0;
      if ( ++npc->act_wait > 50 )
      {
        npc->act_wait = 40;
        npc->xm = -npc->xm;
        if ( npc->direct )
          npc->direct = 0;
        else
          npc->direct = 2;
      }
      if ( npc->act_wait > 35 )
        npc->bits |= 0x20u;
      if ( npc->direct )
        v3 = npc->xm + 64;
      else
        v3 = npc->xm - 64;
      npc->xm = v3;
      if ( npc->shock )
      {
        npc->act_no = 4;
        npc->ani_no = 4;
        npc->ym = -1024;
        npc->bits &= 0xFFDFu;
        npc->damage = 0;
      }
      break;
    case 4:
      if ( npc->direct )
        npc->xm = 256;
      else
        npc->xm = -256;
      v4 = npc->act_wait;
      npc->act_wait = v4 + 1;
      v5 = v4 != 0 && npc->flag & 8;
      if ( v5 )
      {
        npc->act_no = 5;
        v6 = npc->bits;
        HIBYTE(v6) |= 0x20u;
        npc->bits = v6;
      }
      break;
    case 5:
      npc->xm = 0;
      npc->ani_no = 5;
      break;
    default:
      break;
  }
  npc->ym += 64;
  if ( npc->xm > 1024 )
    npc->xm = 1024;
  if ( npc->xm < -1024 )
    npc->xm = -1024;
  if ( npc->ym > 1535 )
    npc->ym = 1535;
  npc->x += npc->xm;
  npc->y += npc->ym;
  if ( npc->direct )
  {
    v7 = npc;
    v8 = (Sint32 *)&v11[16 * npc->ani_no - 192];
  }
  else
  {
    v7 = npc;
    v8 = (Sint32 *)&v11[16 * npc->ani_no - 96];
  }
  npc->rect.left = *v8;
  v7->rect.top = v8[1];
  v7->rect.right = v8[2];
  v7->rect.bottom = v8[3];
}


void ActNpc064(NPCHAR *npc)
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
    if ( npc->tgt_x <= 99 )
      ++npc->tgt_x;
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
    if ( npc->act_wait > 7
      && npc->tgt_x > 99
      && npc->x - 0x8000 < x
      && npc->x + 0x8000 > x
      && npc->y - 40960 < y
      && npc->y + 24576 > y )
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
      PlaySoundObject(30, 1);
      if ( npc->direct )
        npc->xm = 256;
      else
        npc->xm = -256;
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


void ActNpc065(NPCHAR *npc)
{
  int v1;
  NPCHAR *v2;
  Sint32 *v3;
  RECT rect_right[4];
  RECT rect_left[4];
  char v6[8];

  v1 = npc->act_no;
  if ( v1 == 1 )
  {
LABEL_5:
    if ( ++npc->act_wait > 49 )
    {
      npc->act_wait = 0;
      npc->act_no = 2;
      npc->ym = 768;
    }
    goto LABEL_18;
  }
  if ( v1 != 2 )
  {
    if ( v1 )
      goto LABEL_18;
    npc->tgt_x = npc->x;
    npc->tgt_y = npc->y;
    npc->count1 = 120;
    npc->act_no = 1;
    npc->act_wait = Random(0, 50);
    goto LABEL_5;
  }
  if ( x >= npc->x )
    npc->direct = 2;
  else
    npc->direct = 0;
  if ( npc->tgt_y < npc->y )
    npc->ym -= 16;
  if ( npc->tgt_y > npc->y )
    npc->ym += 16;
  if ( npc->ym > 768 )
    npc->ym = 768;
  if ( npc->ym < -768 )
    npc->ym = -768;
LABEL_18:
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


void ActNpc066(NPCHAR *npc)
{
  int v1;
  Sint32 *v2;
  RECT rect[4];
  int a;
  unsigned __int8 deg;
  char v6[8];

  rect[0].left = 32;
  rect[0].top = 192;
  rect[0].right = 56;
  rect[0].bottom = 216;
  rect[1].left = 56;
  rect[1].top = 192;
  rect[1].right = 80;
  rect[1].bottom = 216;
  rect[2].left = 32;
  rect[2].top = 216;
  rect[2].right = 56;
  rect[2].bottom = 240;
  rect[3].left = 56;
  rect[3].top = 216;
  rect[3].right = 80;
  rect[3].bottom = 240;
  v1 = npc->act_no;
  if ( v1 == 1 )
  {
LABEL_10:
    if ( ++npc->ani_wait > 1 )
    {
      npc->ani_wait = 0;
      ++npc->ani_no;
    }
    if ( npc->ani_no > 1 )
      npc->ani_no = 0;
    if ( npc->x - 1536 < npc->tgt_x
      && npc->x + 1536 > npc->tgt_x
      && npc->y - 1536 < npc->tgt_y
      && npc->y + 1536 > npc->tgt_y )
    {
      npc->act_no = 2;
      npc->ani_no = 2;
      gNPC[npc->count1].cond = 0;
      PlaySoundObject(21, 1);
    }
    goto LABEL_29;
  }
  if ( v1 != 2 )
  {
    if ( v1 )
      goto LABEL_29;
    for ( a = 0; a <= 511 && gNPC[a].code_event != 1000; ++a )
      ;
    if ( a == 512 )
      goto LABEL_29;
    npc->tgt_x = gNPC[a].x;
    npc->tgt_y = gNPC[a].y;
    npc->count1 = a;
    deg = GetArktan(npc->x - npc->tgt_x, npc->y - npc->tgt_y);
    npc->xm = 2 * GetCos(deg);
    npc->ym = 2 * GetSin(deg);
    npc->act_no = 1;
    goto LABEL_10;
  }
  npc->xm -= 32;
  npc->ym -= 32;
  if ( npc->xm < -1535 )
    npc->xm = -1535;
  if ( npc->ym < -1535 )
    npc->ym = -1535;
  if ( npc->y < -4096 )
    npc->cond = 0;
  if ( ++npc->ani_wait > 3 )
  {
    npc->ani_wait = 0;
    ++npc->ani_no;
  }
  if ( npc->ani_no > 3 )
    npc->ani_no = 2;
LABEL_29:
  npc->x += npc->xm;
  npc->y += npc->ym;
  v2 = (Sint32 *)&v6[16 * npc->ani_no - 72];
  npc->rect.left = *v2;
  npc->rect.top = v2[1];
  npc->rect.right = v2[2];
  npc->rect.bottom = v2[3];
}


void ActNpc067(NPCHAR *npc)
{
  int v1;
  NPCHAR *v2;
  Sint32 *v3;
  RECT rcRight[8];
  RECT rcLeft[8];
  char v6[24];

  switch ( npc->act_no )
  {
    case 0:
      npc->act_no = 1;
      npc->tgt_x = npc->x;
      npc->tgt_y = npc->y;
      npc->ani_no = 0;
      PlaySoundObject(29, 1);
      goto LABEL_3;
    case 1:
LABEL_3:
      v1 = npc->tgt_x;
      npc->x = v1 + (Random(-1, 1) << 9);
      if ( ++npc->act_wait == 32 )
        npc->act_no = 10;
      break;
    case 0xA:
      npc->act_no = 11;
      npc->act_wait = 0;
      npc->ani_no = 0;
      npc->ym = 512;
      goto LABEL_6;
    case 0xB:
LABEL_6:
      if ( npc->tgt_y < npc->y )
        npc->ym -= 16;
      if ( npc->tgt_y > npc->y )
        npc->ym += 16;
      if ( npc->ym > 256 )
        npc->ym = 256;
      if ( npc->ym < -256 )
        npc->ym = -256;
      break;
    case 0xD:
      npc->ani_no = 1;
      npc->ym += 64;
      if ( npc->ym > 1535 )
        npc->ym = 1535;
      if ( npc->flag & 8 )
      {
        PlaySoundObject(23, 1);
        npc->ym = 0;
        npc->act_no = 14;
        npc->bits |= 8u;
        npc->ani_no = 2;
      }
      break;
    case 0xF:
      npc->act_no = 16;
      npc->act_wait = 0;
      npc->ani_no = 4;
      goto LABEL_19;
    case 0x10:
LABEL_19:
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
      goto LABEL_24;
    case 0x15:
LABEL_24:
      npc->ym -= 32;
      if ( npc->y < -4096 )
        npc->cond = 0;
      break;
    case 0x19:
      npc->act_no = 26;
      npc->act_wait = 0;
      npc->ani_no = 5;
      npc->ani_wait = 0;
      goto LABEL_27;
    case 0x1A:
LABEL_27:
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
        npc->act_no = 14;
      break;
    default:
      break;
  }
  npc->x += npc->xm;
  npc->y += npc->ym;
  qmemcpy(rcLeft, &ActNpc067(NPCHAR *)::C.26, sizeof(rcLeft));
  qmemcpy(rcRight, &ActNpc067(NPCHAR *)::C.27, sizeof(rcRight));
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
    v2 = npc;
    v3 = (Sint32 *)&v6[16 * npc->ani_no - 256];
  }
  else
  {
    v2 = npc;
    v3 = (Sint32 *)&v6[16 * npc->ani_no - 128];
  }
  npc->rect.left = *v3;
  v2->rect.top = v3[1];
  v2->rect.right = v3[2];
  v2->rect.bottom = v3[3];
  if ( npc->act_no == 1 && npc->ani_wait <= 31 )
    npc->rect.bottom += ++npc->ani_wait / 2 - 16;
}


void ActNpc068(NPCHAR *npc)
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
        v1 = npc->xm + 16;
      else
        v1 = npc->xm - 16;
      npc->xm = v1;
      if ( npc->act_wait <= 7 || npc->x - 6144 >= x || npc->x + 6144 <= x || npc->y - 6144 >= y || npc->y + 4096 <= y )
      {
        ++npc->act_wait;
        if ( npc->flag & 5 || npc->act_wait > 75 )
        {
          npc->act_no = 9;
          npc->ani_no = 0;
        }
        else if ( !(npc->count1 % 3) && npc->act_wait > 25 )
        {
          npc->act_no = 4;
          npc->ani_no = 7;
          npc->ym = -1024;
        }
      }
      else
      {
        npc->act_no = 10;
        npc->ani_no = 5;
        gMC.cond |= 2u;
        DamageMyChar(2);
      }
      break;
    case 4:
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
        DamageMyChar(2);
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
      goto LABEL_51;
    case 0x15:
LABEL_51:
      if ( ++npc->act_wait > 49 )
        npc->act_no = 0;
      break;
    default:
      break;
  }
  npc->ym += 32;
  if ( npc->xm < -1024 )
    npc->xm = -1024;
  if ( npc->xm > 1024 )
    npc->xm = 1024;
  if ( npc->ym > 1535 )
    npc->ym = 1535;
  npc->x += npc->xm;
  npc->y += npc->ym;
  qmemcpy(rect_left, &ActNpc068(NPCHAR *)::C.30, sizeof(rect_left));
  qmemcpy(rect_right, &ActNpc068(NPCHAR *)::C.31, sizeof(rect_right));
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


void ActNpc069(NPCHAR *npc)
{
  unsigned int v1;
  NPCHAR *v2;
  Sint32 *v3;
  RECT rcRight[6];
  RECT rcLeft[6];
  char v6[24];

  qmemcpy(rcLeft, &ActNpc069(NPCHAR *)::C.32, sizeof(rcLeft));
  qmemcpy(rcRight, &ActNpc069(NPCHAR *)::C.33, sizeof(rcRight));
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


void ActNpc070(NPCHAR *npc)
{
  RECT *v1;
  RECT rect[4];

  rect[0].left = 96;
  rect[0].top = 48;
  rect[0].right = 112;
  rect[0].bottom = 64;
  rect[1].left = 112;
  rect[1].top = 48;
  rect[1].right = 128;
  rect[1].bottom = 64;
  rect[2].left = 128;
  rect[2].top = 48;
  rect[2].right = 144;
  rect[2].bottom = 64;
  rect[3].left = 144;
  rect[3].top = 48;
  rect[3].right = 160;
  rect[3].bottom = 64;
  if ( ++npc->ani_wait > 3 )
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

void ActNpc071(NPCHAR *npc)
{
  int v1;
  NPCHAR *v2;
  RECT *v3;
  RECT rcRight[3];
  RECT rcLeft[3];

  v1 = npc->act_no;
  if ( v1 )
  {
    if ( v1 != 1 )
      goto LABEL_13;
  }
  else
  {
    npc->act_no = 1;
    npc->tgt_x = npc->x;
    npc->tgt_y = npc->y;
    npc->ym = 128;
  }
  if ( npc->tgt_y < npc->y )
    npc->ym -= 8;
  if ( npc->tgt_y > npc->y )
    npc->ym += 8;
  if ( npc->ym > 256 )
    npc->ym = 256;
  if ( npc->ym < -256 )
    npc->ym = -256;
LABEL_13:
  npc->x += npc->xm;
  npc->y += npc->ym;
  rcLeft[0].left = 64;
  rcLeft[0].top = 32;
  rcLeft[0].right = 80;
  rcLeft[0].bottom = 48;
  rcLeft[1].left = 80;
  rcLeft[1].top = 32;
  rcLeft[1].right = 96;
  rcLeft[1].bottom = 48;
  rcLeft[2].left = 96;
  rcLeft[2].top = 32;
  rcLeft[2].right = 112;
  rcLeft[2].bottom = 48;
  rcRight[0].left = 64;
  rcRight[0].top = 48;
  rcRight[0].right = 80;
  rcRight[0].bottom = 64;
  rcRight[1].left = 80;
  rcRight[1].top = 48;
  rcRight[1].right = 96;
  rcRight[1].bottom = 64;
  rcRight[2].left = 96;
  rcRight[2].top = 48;
  rcRight[2].right = 112;
  rcRight[2].bottom = 64;
  if ( ++npc->ani_wait > 4 )
  {
    npc->ani_wait = 0;
    ++npc->ani_no;
  }
  if ( npc->ani_no > 1 )
    npc->ani_no = 0;
  if ( npc->shock )
    npc->ani_no = 2;
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

void ActNpc072(NPCHAR *npc)
{
  int v1;
  int v2;
  int v3;
  int v4;
  Sint32 *v5;
  RECT rect[2];
  char v7[8];

  if ( !npc->direct )
  {
    if ( ++npc->ani_wait > 1 )
    {
      npc->ani_wait = 0;
      ++npc->ani_no;
    }
    if ( npc->ani_no > 1 )
    {
      npc->ani_no = 0;
      return;
    }
    if ( x < npc->x + 163840 && x > npc->x - 163840 && y < npc->y + 122880 && y > npc->y - 122880 )
    {
      ++npc->act_no;
      if ( npc->act_no & 1 )
      {
        v1 = 3 * Random(-512, 128);
        v2 = Random(-512, 512);
        SetNpChar(73, npc->x, npc->y, 2 * v2, v1, 0, 0, 256);
      }
      v3 = 3 * Random(-512, 128);
      v4 = Random(-512, 512);
      SetNpChar(73, npc->x, npc->y, 2 * v4, v3, 0, 0, 256);
    }
  }
  rect[0].left = 224;
  rect[0].top = 48;
  rect[0].right = 240;
  rect[0].bottom = 64;
  rect[1].left = 240;
  rect[1].top = 48;
  rect[1].right = 256;
  rect[1].bottom = 64;
  v5 = (Sint32 *)&v7[16 * npc->ani_no - 32];
  npc->rect.left = *v5;
  npc->rect.top = v5[1];
  npc->rect.right = v5[2];
  npc->rect.bottom = v5[3];
}


void ActNpc073(NPCHAR *npc)
{
  Sint32 *v1;
  RECT rect[5];
  char v3[24];

  qmemcpy(rect, &ActNpc073(NPCHAR *)::C.37, sizeof(rect));
  npc->ym += 32;
  npc->ani_no = Random(0, 4);
  if ( npc->ym > 1535 )
    npc->ym = 1535;
  npc->x += npc->xm;
  npc->y += npc->ym;
  v1 = (Sint32 *)&v3[16 * npc->ani_no - 80];
  npc->rect.left = *v1;
  npc->rect.top = v1[1];
  npc->rect.right = v1[2];
  npc->rect.bottom = v1[3];
  if ( npc->direct == 2 )
  {
    npc->rect.top += 2;
    npc->rect.bottom += 2;
  }
  if ( ++npc->act_wait > 10 )
  {
    if ( npc->flag & 1 )
      npc->cond = 0;
    if ( npc->flag & 4 )
      npc->cond = 0;
    if ( npc->flag & 8 )
      npc->cond = 0;
    if ( npc->flag & 0x100 )
      npc->cond = 0;
  }
  if ( npc->y > gMap.length << 13 )
    npc->cond = 0;
}


void ActNpc074(NPCHAR *npc)
{
  NPCHAR *v1;
  Sint32 *v2;
  RECT rcRight[6];
  RECT rcLeft[6];
  char v5[24];

  qmemcpy(rcLeft, &ActNpc074(NPCHAR *)::C.38, sizeof(rcLeft));
  qmemcpy(rcRight, &ActNpc074(NPCHAR *)::C.39, sizeof(rcRight));
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
    case 8:
      npc->act_no = 9;
      npc->ani_no = 2;
      npc->ani_wait = 0;
      goto LABEL_8;
    case 9:
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
    default:
      break;
  }
  npc->ym += 64;
  if ( npc->xm > 1024 )
    npc->xm = 1024;
  if ( npc->xm < -1024 )
    npc->xm = -1024;
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


void ActNpc075(NPCHAR *npc)
{
  int v1;
  RECT *v2;
  RECT rcLeft[2];

  rcLeft[0].left = 272;
  rcLeft[0].top = 32;
  rcLeft[0].right = 296;
  rcLeft[0].bottom = 56;
  rcLeft[1].left = 296;
  rcLeft[1].top = 32;
  rcLeft[1].right = 320;
  rcLeft[1].bottom = 56;
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
  v2 = &rcLeft[npc->ani_no];
  npc->rect.left = v2->left;
  npc->rect.top = v2->top;
  npc->rect.right = v2->right;
  npc->rect.bottom = v2->bottom;
}

void ActNpc076(NPCHAR *npc)
{
  npc->rect.left = 16 * npc->code_event;
  npc->rect.top = 0;
  npc->rect.right = npc->rect.left + 16;
  npc->rect.bottom = 16;
}

void ActNpc077(NPCHAR *npc)
{
  int v1;
  Sint32 *v2;
  RECT rc[3];
  char v4[8];

  rc[0].left = 0;
  rc[0].top = 16;
  rc[0].right = 48;
  rc[0].bottom = 48;
  rc[1].left = 48;
  rc[1].top = 16;
  rc[1].right = 96;
  rc[1].bottom = 48;
  rc[2].left = 96;
  rc[2].top = 16;
  rc[2].right = 144;
  rc[2].bottom = 48;
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
    npc->rect.left = rc[2].left;
    npc->rect.top = rc[2].top;
    npc->rect.right = rc[2].right;
    npc->rect.bottom = rc[2].bottom;
  }
  else
  {
    v2 = (Sint32 *)&v4[16 * npc->ani_no - 48];
    npc->rect.left = *v2;
    npc->rect.top = v2[1];
    npc->rect.right = v2[2];
    npc->rect.bottom = v2[3];
  }
}


void ActNpc078(NPCHAR *npc)
{
  if ( npc->direct )
  {
    npc->rect.left = 176;
    npc->rect.top = 48;
    npc->rect.right = 192;
  }
  else
  {
    npc->rect.left = 160;
    npc->rect.top = 48;
    npc->rect.right = 176;
  }
  npc->rect.bottom = 64;
}

void ActNpc079(NPCHAR *npc)
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
  if ( v1 != 1 )
  {
    if ( v1 > 1 )
    {
      if ( v1 == 2 )
      {
        npc->ani_no = 0;
        if ( Random(0, 120) == 10 )
        {
          npc->act_no = 3;
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
      }
      else if ( v1 == 3 && ++npc->act_wait > 8 )
      {
        npc->act_no = 2;
        npc->ani_no = 0;
      }
    }
    else if ( !v1 )
    {
      npc->act_no = 1;
      npc->ani_no = 2;
      npc->ani_wait = 0;
    }
  }
  npc->ym += 64;
  if ( npc->ym > 1535 )
    npc->ym = 1535;
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


