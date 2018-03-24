#include "types.h"
#include "SDL_stdinc.h"
#include "windows_wrapper.h"
#include "Tags.h"
#include "forNpc.h"
void __cdecl ActNpc260(NPCHAR_0 *npc)
{
  int v1;
  NPCHAR_0 *v2;
  Sint32 *v3;
  RECT rcRight[3];
  RECT rcLeft[3];
  char v6[8];

  rcLeft[0].left = 128;
  rcLeft[0].top = 64;
  rcLeft[0].right = 144;
  rcLeft[0].bottom = 80;
  rcLeft[1].left = 144;
  rcLeft[1].top = 64;
  rcLeft[1].right = 160;
  rcLeft[1].bottom = 80;
  rcLeft[2].left = 224;
  rcLeft[2].top = 64;
  rcLeft[2].right = 240;
  rcLeft[2].bottom = 80;
  rcRight[0].left = 128;
  rcRight[0].top = 80;
  rcRight[0].right = 144;
  rcRight[0].bottom = 96;
  rcRight[1].left = 144;
  rcRight[1].top = 80;
  rcRight[1].right = 160;
  rcRight[1].bottom = 96;
  rcRight[2].left = 224;
  rcRight[2].top = 80;
  rcRight[2].right = 240;
  rcRight[2].bottom = 96;
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
    npc->x += 512;
    npc->y -= 1024;
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
  else if ( v1 == 10 )
  {
    npc->act_no = 11;
    npc->ani_no = 2;
    SetNpChar(87, npc->x, npc->y - 0x2000, 0, 0, 0, 0, 256);
  }
LABEL_14:
  if ( x >= npc->x )
    npc->direct = 2;
  else
    npc->direct = 0;
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


void __cdecl ActNpc261(NPCHAR_0 *npc)
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
    npc->x -= 512;
    npc->y -= 1024;
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
  if ( x >= npc->x )
    npc->direct = 2;
  else
    npc->direct = 0;
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


void __cdecl ActNpc262(NPCHAR_0 *npc)
{
  int v1;
  NPCHAR_0 *v2;
  Sint32 *v3;
  RECT rcRight[2];
  RECT rcLeft[2];
  char v6[8];

  rcLeft[0].left = 128;
  rcLeft[0].top = 0;
  rcLeft[0].right = 144;
  rcLeft[0].bottom = 16;
  rcLeft[1].left = 144;
  rcLeft[1].top = 0;
  rcLeft[1].right = 160;
  rcLeft[1].bottom = 16;
  rcRight[0].left = 128;
  rcRight[0].top = 16;
  rcRight[0].right = 144;
  rcRight[0].bottom = 32;
  rcRight[1].left = 144;
  rcRight[1].top = 16;
  rcRight[1].right = 160;
  rcRight[1].bottom = 32;
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
    npc->x -= 512;
    npc->y -= 1024;
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
  if ( x >= npc->x )
    npc->direct = 2;
  else
    npc->direct = 0;
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


void __cdecl ActNpc263(NPCHAR_0 *npc)
{
  int v1;
  int v2;
  int v3;
  NPCHAR_0 *v4;
  Sint32 *v5;
  RECT rcRight[9];
  RECT rcLeft[9];
  int deg;
  int xm;
  int ym;
  char v11[24];

  qmemcpy(rcLeft, &ActNpc263(NPCHAR *)::C.3, sizeof(rcLeft));
  qmemcpy(rcRight, &ActNpc263(NPCHAR *)::C.4, sizeof(rcRight));
  v1 = npc->act_no;
  if ( v1 == 31 )
  {
LABEL_51:
    if ( ++npc->act_wait / 2 & 1 )
      v2 = npc->tgt_x;
    else
      v2 = npc->tgt_x + 512;
    npc->x = v2;
    if ( npc->act_wait > 50 )
    {
      npc->act_no = 32;
      npc->act_wait = 0;
      npc->ani_no = 7;
      PlaySoundObject(101, 1);
      for ( deg = 8; deg <= 255; deg += 16 )
      {
        xm = 2 * GetCos(deg);
        ym = 2 * GetSin(deg);
        SetNpChar(266, npc->x, npc->y, xm, ym, 0, 0, 256);
      }
    }
    goto LABEL_83;
  }
  if ( v1 > 31 )
  {
    if ( v1 == 102 )
    {
      if ( ++npc->act_wait > 40 )
      {
        npc->act_no = 103;
        npc->act_wait = 16;
        npc->ani_no = 2;
        npc->ym = 0;
        npc->x = npc->tgt_x;
        npc->y = npc->tgt_y;
        if ( npc->x <= x )
          npc->direct = 2;
        else
          npc->direct = 0;
      }
    }
    else if ( v1 > 102 )
    {
      switch ( v1 )
      {
        case 500:
          npc->bits &= 0xFFDFu;
          npc->ani_no = 6;
          npc->ym += 16;
          if ( npc->flag & 8 )
          {
            npc->act_no = 501;
            npc->act_wait = 0;
            npc->tgt_x = npc->x;
            if ( npc->x <= x )
              npc->direct = 2;
            else
              npc->direct = 0;
          }
          break;
        case 501:
          if ( npc->x <= x )
            npc->direct = 2;
          else
            npc->direct = 0;
          npc->ani_no = 8;
          if ( ++npc->act_wait / 2 & 1 )
            v3 = npc->tgt_x;
          else
            v3 = npc->tgt_x + 512;
          npc->x = v3;
          break;
        case 103:
          npc->act_wait -= 2;
          if ( npc->act_wait <= 0 )
          {
            npc->bits |= 0x20u;
            npc->damage = 3;
            if ( npc->count1 > 2 )
            {
              npc->count1 = 0;
              npc->act_no = 30;
            }
            else
            {
              ++npc->count1;
              npc->act_no = 10;
            }
          }
          break;
      }
    }
    else
    {
      if ( v1 == 100 )
      {
        npc->act_no = 101;
        npc->bits &= 0xFFDFu;
        npc->damage = 0;
        npc->act_wait = 0;
        PlaySoundObject(29, 1);
      }
      else if ( v1 <= 100 )
      {
        if ( v1 == 32 && ++npc->act_wait > 50 )
          npc->act_no = 100;
        goto LABEL_83;
      }
      npc->act_wait += 2;
      if ( npc->act_wait > 16 )
      {
        npc->act_no = 102;
        npc->act_wait = 0;
        npc->ani_no = 3;
        npc->tgt_x = Random(5, 35) << 13;
        npc->tgt_y = Random(5, 7) << 13;
      }
    }
  }
  else if ( v1 == 2 )
  {
    if ( ++npc->act_wait / 2 & 1 )
      npc->ani_no = 0;
    else
      npc->ani_no = 3;
    if ( npc->act_wait > 50 )
      npc->act_no = 10;
  }
  else
  {
    if ( v1 <= 2 )
    {
      if ( !v1 )
      {
        npc->act_no = 1;
        npc->y += 4096;
        npc->ani_no = 3;
      }
      goto LABEL_83;
    }
    if ( v1 != 20 )
    {
      if ( v1 != 30 )
      {
        if ( v1 == 10 )
        {
          npc->ym += 128;
          npc->bits |= 0x20u;
          npc->damage = 3;
          if ( npc->flag & 8 )
          {
            npc->act_no = 20;
            npc->act_wait = 0;
            npc->ani_no = 0;
            npc->count2 = npc->life;
            if ( npc->x <= x )
              npc->direct = 2;
            else
              npc->direct = 0;
          }
        }
        goto LABEL_83;
      }
      npc->act_no = 31;
      npc->act_wait = 0;
      npc->ani_no = 6;
      npc->tgt_x = npc->x;
      npc->bits |= 0x20u;
      goto LABEL_51;
    }
    if ( ++npc->act_wait <= 49 && npc->life < npc->count2 - 20 )
      npc->act_wait = 50;
    if ( npc->act_wait == 50 )
    {
      if ( npc->x <= x )
        npc->direct = 2;
      else
        npc->direct = 0;
      npc->ani_no = 4;
    }
    if ( npc->act_wait == 80 )
    {
      npc->ani_no = 5;
      PlaySoundObject(25, 1);
      if ( npc->direct )
      {
        SetNpChar(264, npc->x + 0x2000, npc->y, 0, 0, 2, 0, 256);
        SetNpChar(264, npc->x + 0x2000, npc->y, 0, 0, 1026, 0, 256);
      }
      else
      {
        SetNpChar(264, npc->x - 0x2000, npc->y, 0, 0, 0, 0, 256);
        SetNpChar(264, npc->x - 0x2000, npc->y, 0, 0, 1024, 0, 256);
      }
    }
    if ( npc->act_wait == 120 )
      npc->ani_no = 0;
    if ( npc->act_wait > 130 && npc->life < npc->count2 - 50 )
      npc->act_wait = 161;
    if ( npc->act_wait > 160 )
    {
      npc->act_no = 100;
      npc->ani_no = 0;
    }
  }
LABEL_83:
  if ( npc->act_no > 9 )
  {
    if ( npc->act_no == 102 )
    {
      gSuperXpos = npc->tgt_x;
      gSuperYpos = npc->tgt_y;
    }
    else
    {
      gSuperXpos = npc->x;
      gSuperYpos = npc->y;
    }
  }
  if ( npc->ym > 1535 )
    npc->ym = 1535;
  npc->x += npc->xm;
  npc->y += npc->ym;
  if ( npc->direct )
  {
    v4 = npc;
    v5 = (Sint32 *)&v11[16 * npc->ani_no - 300];
  }
  else
  {
    v4 = npc;
    v5 = (Sint32 *)&v11[16 * npc->ani_no - 156];
  }
  npc->rect.left = *v5;
  v4->rect.top = v5[1];
  v4->rect.right = v5[2];
  v4->rect.bottom = v5[3];
  if ( npc->act_no != 101 && npc->act_no != 103 )
  {
    npc->view.top = 0x2000;
  }
  else
  {
    npc->rect.top += npc->act_wait;
    npc->rect.bottom -= npc->act_wait;
    npc->view.top = (16 - npc->act_wait) << 9;
  }
}


void __cdecl ActNpc264(NPCHAR_0 *npc)
{
  int v1;
  int v2;
  int v3;
  int v4;
  unsigned __int8 deg;

  if ( npc->x < 0 || npc->x > gMap.width << 13 )
  {
    VanishNpChar(npc);
    return;
  }
  v1 = npc->act_no;
  if ( !v1 )
  {
    npc->act_no = 1;
    npc->tgt_x = npc->x;
    npc->tgt_y = npc->y;
    npc->count1 = npc->direct / 8;
    npc->direct %= 8;
    goto LABEL_8;
  }
  if ( v1 == 1 )
  {
LABEL_8:
    npc->count1 += 6;
    npc->count1 = (unsigned __int8)(((unsigned __int64)npc->count1 >> 56) + npc->count1)
                - ((unsigned int)(npc->count1 >> 31) >> 24);
    deg = npc->count1;
    if ( npc->act_wait <= 127 )
      ++npc->act_wait;
    if ( npc->direct )
      v2 = npc->xm + 21;
    else
      v2 = npc->xm - 21;
    npc->xm = v2;
    npc->tgt_x += npc->xm;
    v3 = npc->tgt_x;
    npc->x = v3 + npc->act_wait * GetCos(deg) / 8;
    v4 = npc->tgt_y;
    npc->y = v4 + npc->act_wait * GetSin(deg) / 2;
    SetNpChar(265, npc->x, npc->y, 0, 0, 0, 0, 256);
  }
  npc->rect.left = 288;
  npc->rect.top = 0;
  npc->rect.right = 304;
  npc->rect.bottom = 16;
}

void __cdecl ActNpc265(NPCHAR_0 *npc)
{
  RECT *v1;
  RECT rc[3];

  rc[0].left = 288;
  rc[0].top = 16;
  rc[0].right = 304;
  rc[0].bottom = 32;
  rc[1].left = 288;
  rc[1].top = 32;
  rc[1].right = 304;
  rc[1].bottom = 48;
  rc[2].left = 288;
  rc[2].top = 48;
  rc[2].right = 304;
  rc[2].bottom = 64;
  if ( ++npc->ani_wait > 3 )
  {
    npc->ani_wait = 0;
    ++npc->ani_no;
  }
  if ( npc->ani_no <= 2 )
  {
    v1 = &rc[npc->ani_no];
    npc->rect.left = v1->left;
    npc->rect.top = v1->top;
    npc->rect.right = v1->right;
    npc->rect.bottom = v1->bottom;
  }
  else
  {
    npc->cond = 0;
  }
}

void __cdecl ActNpc266(NPCHAR_0 *npc)
{
  Sint32 *v1;
  RECT rc[2];
  char v3[8];

  rc[0].left = 304;
  rc[0].top = 16;
  rc[0].right = 320;
  rc[0].bottom = 32;
  rc[1].left = 304;
  rc[1].top = 32;
  rc[1].right = 320;
  rc[1].bottom = 48;
  if ( npc->flag & 1 )
    npc->xm = -npc->xm;
  if ( npc->flag & 4 )
    npc->xm = -npc->xm;
  if ( npc->flag & 2 )
    npc->ym = 512;
  if ( npc->flag & 8 )
    npc->ym = -512;
  npc->x += npc->xm;
  npc->y += npc->ym;
  if ( ++npc->ani_no > 1 )
    npc->ani_no = 0;
  v1 = (Sint32 *)&v3[16 * npc->ani_no - 32];
  npc->rect.left = *v1;
  npc->rect.top = v1[1];
  npc->rect.right = v1[2];
  npc->rect.bottom = v1[3];
  if ( ++npc->act_wait % 4 == 1 )
    SetNpChar(265, npc->x, npc->y, 0, 0, 0, 0, 256);
  if ( npc->act_wait > 250 )
    VanishNpChar(npc);
}


void __cdecl ActNpc267(NPCHAR_0 *npc)
{
  int v1;
  int v2;
  int v3;
  int v4;
  int v5;
  int v6;
  int v7;
  unsigned __int16 v8;
  unsigned __int16 v9;
  unsigned __int16 v10;
  int v11;
  int v12;
  bool v13;
  int v14;
  int v15;
  int v16;
  int v17;
  int v18;
  int v19;
  int v20;
  int v21;
  int v22;
  int v23;
  int v24;
  int v25;
  int v26;
  int v27;
  int v28;
  int v29;
  int v30;
  int v31;
  int v32;
  int v33;
  int v34;
  int v35;
  int v36;
  NPCHAR_0 *v37;
  Sint32 *v38;
  RECT rcRight[10];
  RECT rcLeft[10];
  int xm;
  int ym;
  int i;
  char v44[24];

  qmemcpy(rcLeft, &ActNpc267(NPCHAR *)::C.9, sizeof(rcLeft));
  qmemcpy(rcRight, &ActNpc267(NPCHAR *)::C.10, sizeof(rcRight));
  v1 = npc->act_no;
  if ( v1 == 21 )
  {
LABEL_118:
    ++npc->act_wait;
    npc->ani_no = 6;
    if ( npc->act_wait > 20 && npc->act_wait % 3 == 1 )
    {
      ym = Random(-512, 512);
      xm = 4 * Random(256, 512);
      if ( npc->direct )
        SetNpChar(269, npc->x + 4096, npc->y - 2048, xm, ym, 2, 0, 256);
      else
        SetNpChar(269, npc->x - 4096, npc->y - 2048, -xm, ym, 0, 0, 256);
      PlaySoundObject(39, 1);
    }
    if ( npc->act_wait > 90 )
      npc->act_no = 10;
    goto LABEL_188;
  }
  if ( v1 <= 21 )
  {
    if ( v1 == 8 )
    {
LABEL_63:
      npc->ym += 64;
      if ( ++npc->act_wait > 40 )
        npc->act_no = 10;
      goto LABEL_188;
    }
    if ( v1 <= 8 )
    {
      if ( v1 == 2 )
      {
LABEL_54:
        npc->ym += 128;
        if ( ++npc->act_wait / 2 & 1 )
          npc->ani_no = 0;
        else
          npc->ani_no = 3;
        goto LABEL_188;
      }
      if ( v1 <= 2 )
      {
        if ( v1 )
        {
          if ( v1 != 1 )
            goto LABEL_188;
        }
        else
        {
          if ( x >= gSuperXpos )
            npc->direct = 2;
          else
            npc->direct = 0;
          if ( npc->direct )
            npc->x = gSuperXpos + 3072;
          else
            npc->x = gSuperXpos - 3072;
          npc->y = gSuperYpos;
        }
        npc->act_no = 2;
        goto LABEL_54;
      }
      if ( v1 == 6 )
        goto LABEL_58;
      if ( v1 <= 6 )
      {
        if ( v1 != 5 )
          goto LABEL_188;
        npc->act_no = 6;
        npc->ani_no = 1;
        npc->ani_wait = 0;
LABEL_58:
        npc->ym += 128;
        if ( ++npc->ani_wait > 40 )
        {
          npc->ani_wait = 0;
          ++npc->ani_no;
        }
        if ( npc->ani_no > 2 )
          npc->ani_no = 1;
        goto LABEL_188;
      }
      npc->act_no = 8;
      npc->act_wait = 0;
      npc->ani_no = 3;
      goto LABEL_63;
    }
    if ( v1 == 16 )
    {
      npc->ym += 64;
      if ( ++npc->ani_wait > 1 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 5 )
        npc->ani_no = 4;
      if ( npc->x <= x )
        npc->direct = 2;
      else
        npc->direct = 0;
      if ( npc->ym > 0 && npc->flag & 8 )
        npc->act_no = 17;
      goto LABEL_188;
    }
    if ( v1 <= 16 )
    {
      if ( v1 == 11 )
      {
LABEL_66:
        npc->ym += 128;
        if ( npc->x <= x )
          npc->direct = 2;
        else
          npc->direct = 0;
        if ( npc->flag & 8 )
        {
          if ( npc->life >= npc->count2 - 20 )
          {
            if ( ++npc->ani_wait > 10 )
            {
              npc->ani_wait = 0;
              if ( ++npc->ani_no > 2 )
                npc->ani_no = 1;
            }
          }
          else if ( dword_81C8584 & 8 && x > npc->x - 24576 && x < npc->x + 24576 && npc->ani_no != 6 )
          {
            npc->ani_no = 6;
            DamageMyChar(5);
            SetQuake(10);
            PlaySoundObject(26, 1);
            unk_81C85B8 = -1024;
            if ( npc->x <= x )
              unk_81C85B4 = 1535;
            else
              unk_81C85B4 = -1535;
            for ( i = 0; i <= 99; ++i )
            {
              v2 = 3 * Random(-512, 512);
              v3 = 3 * Random(-512, 512);
              v4 = npc->y;
              v5 = (Random(-16, 16) << 9) + v4;
              v6 = npc->x;
              v7 = Random(-16, 16);
              SetNpChar(270, v6 + (v7 << 9), v5, v3, v2, 3, 0, 170);
            }
          }
        }
        else
        {
          npc->ani_no = 4;
        }
        if ( ++npc->act_wait > 30 || npc->life < npc->count2 - 20 )
        {
          if ( ++npc->count1 > 10 )
            npc->count1 = 0;
          switch ( npc->count1 )
          {
            case 1:
            case 9:
              npc->act_no = 40;
              break;
            case 2:
            case 7:
              npc->act_no = 100;
              break;
            case 3:
            case 6:
              npc->act_no = 30;
              break;
            case 8:
              npc->act_no = 20;
              break;
            default:
              npc->act_no = 15;
              npc->act_wait = 0;
              break;
          }
        }
        goto LABEL_188;
      }
      if ( v1 != 15 )
      {
        if ( v1 != 10 )
          goto LABEL_188;
        npc->bits |= 4u;
        npc->xm = 0;
        npc->act_no = 11;
        npc->act_wait = 0;
        npc->ani_no = 1;
        npc->ani_wait = 0;
        npc->count2 = npc->life;
        goto LABEL_66;
      }
      npc->ani_no = 3;
      ++npc->act_wait;
      if ( npc->x <= x )
        npc->direct = 2;
      else
        npc->direct = 0;
      if ( npc->act_wait > 20 )
      {
        npc->act_no = 16;
        npc->ani_no = 4;
        npc->ani_wait = 0;
        npc->ym = -1536;
        if ( npc->direct )
          npc->xm = 1024;
        else
          npc->xm = -1024;
      }
      goto LABEL_188;
    }
    if ( v1 != 18 )
    {
      if ( v1 >= 18 )
      {
        if ( v1 != 20 )
          goto LABEL_188;
        npc->act_no = 21;
        npc->act_wait = 0;
        goto LABEL_118;
      }
      npc->act_no = 18;
      npc->act_wait = 0;
      SetQuake(10);
      PlaySoundObject(26, 1);
    }
    npc->ani_no = 3;
    ++npc->act_wait;
    npc->xm = 7 * npc->xm / 8;
    npc->ym += 128;
    if ( npc->act_wait > 10 )
      npc->act_no = 10;
    goto LABEL_188;
  }
  if ( v1 == 102 )
  {
    if ( ++npc->act_wait > 40 )
    {
      npc->act_no = 103;
      npc->act_wait = 28;
      npc->ani_no = 4;
      npc->ym = 0;
      npc->x = npc->tgt_x;
      npc->y = npc->tgt_y;
      if ( npc->x <= x )
        npc->direct = 2;
      else
        npc->direct = 0;
    }
  }
  else if ( v1 > 102 )
  {
    if ( v1 == 510 )
    {
      npc->act_no = 511;
      npc->act_wait = 0;
      npc->ani_no = 9;
      npc->tgt_x = npc->x;
      npc->y += 0x2000;
      npc->bits |= 8u;
    }
    else
    {
      if ( v1 <= 510 )
      {
        switch ( v1 )
        {
          case 500:
            DeleteNpCharCode(269, 1);
            npc->bits &= 0xFFDFu;
            npc->ani_no = 4;
            npc->ym += 32;
            npc->xm = 0;
            if ( npc->flag & 8 )
            {
              npc->act_no = 501;
              npc->act_wait = 0;
              npc->tgt_x = npc->x;
              if ( npc->x <= x )
                npc->direct = 2;
              else
                npc->direct = 0;
            }
            break;
          case 501:
            npc->ani_no = 9;
            if ( ++npc->act_wait / 2 & 1 )
              v11 = npc->tgt_x;
            else
              v11 = npc->tgt_x + 512;
            npc->x = v11;
            break;
          case 103:
            npc->act_wait -= 2;
            if ( npc->act_wait <= 0 )
            {
              npc->bits |= 0x24u;
              npc->damage = 5;
              npc->act_no = 16;
              npc->ym = -512;
              npc->xm = 0;
            }
            break;
        }
        goto LABEL_188;
      }
      if ( v1 == 512 )
        goto LABEL_188;
      if ( v1 >= 512 )
      {
        if ( v1 == 520 )
        {
          npc->damage = 0;
          gSuperYpos = -16384;
        }
        goto LABEL_188;
      }
    }
    SetQuake(2);
    if ( ++npc->act_wait % 6 == 3 )
      PlaySoundObject(25, 1);
    if ( npc->act_wait / 2 & 1 )
      v12 = npc->tgt_x;
    else
      v12 = npc->tgt_x + 512;
    npc->x = v12;
    if ( npc->act_wait > 352 )
    {
      npc->ani_no = 0;
      npc->act_no = 512;
    }
  }
  else if ( v1 == 40 )
  {
    npc->ani_no = 3;
    ++npc->act_wait;
    if ( npc->x <= x )
      npc->direct = 2;
    else
      npc->direct = 0;
    if ( npc->act_wait > 20 )
    {
      npc->act_no = 41;
      npc->ani_no = 4;
      npc->ani_wait = 0;
      npc->ym = -2048;
      if ( npc->direct )
        npc->xm = 1024;
      else
        npc->xm = -1024;
    }
  }
  else
  {
    if ( v1 <= 40 )
    {
      if ( v1 != 31 )
      {
        if ( v1 == 32 )
        {
          ++npc->act_wait;
          npc->ym = 0;
          if ( npc->act_wait / 2 & 1 )
            npc->ani_no = 7;
          else
            npc->ani_no = 8;
          if ( npc->act_wait > 30 )
          {
            npc->act_wait = 0;
            npc->act_no = 18;
            npc->damage = 5;
            v9 = npc->bits;
            LOBYTE(v9) = v9 & 0x7E;
            npc->bits = v9;
            npc->bits |= 0x20u;
          }
          if ( npc->flag & 1 || npc->flag & 4 )
          {
            npc->act_no = 15;
            npc->act_wait = 0;
            npc->damage = 5;
            v10 = npc->bits;
            LOBYTE(v10) = v10 & 0x7E;
            npc->bits = v10;
            npc->bits |= 0x20u;
          }
          goto LABEL_188;
        }
        if ( v1 != 30 )
          goto LABEL_188;
        npc->act_no = 31;
        npc->act_wait = 0;
        npc->bits |= 1u;
        npc->bits &= 0xFFDFu;
      }
      npc->ani_no = 3;
      if ( ++npc->act_wait > 20 )
      {
        npc->act_no = 32;
        npc->act_wait = 0;
        npc->ani_no = 7;
        v8 = npc->bits;
        LOBYTE(v8) = v8 | 0x80;
        npc->bits = v8;
        npc->damage = 10;
        PlaySoundObject(25, 1);
        if ( npc->direct )
          npc->xm = 1535;
        else
          npc->xm = -1535;
      }
      goto LABEL_188;
    }
    if ( v1 == 100 )
    {
      npc->act_no = 101;
      npc->act_wait = 0;
      npc->bits &= 0xFFDBu;
      npc->damage = 0;
      PlaySoundObject(29, 1);
    }
    else if ( v1 <= 100 )
    {
      if ( v1 == 41 )
      {
        npc->ym += 64;
        if ( ++npc->ani_wait > 1 )
        {
          npc->ani_wait = 0;
          ++npc->ani_no;
        }
        if ( npc->ani_no > 5 )
          npc->ani_no = 4;
        if ( y > npc->y && x > npc->x - 4096 && x < npc->x + 4096 )
        {
          npc->act_no = 16;
          npc->ym = 1535;
          npc->xm = 0;
        }
        if ( npc->ym > 0 && npc->flag & 8 )
          npc->act_no = 17;
      }
      goto LABEL_188;
    }
    npc->act_wait += 2;
    if ( npc->act_wait > 28 )
    {
      npc->act_no = 102;
      npc->act_wait = 0;
      npc->ani_no = 0;
      npc->tgt_x = x;
      npc->tgt_y = y - 0x4000;
      if ( npc->tgt_y <= 0x7FFF )
        npc->tgt_y = 0x8000;
      if ( npc->tgt_x <= 0x7FFF )
        npc->tgt_x = 0x8000;
      if ( npc->tgt_x > 294912 )
        npc->tgt_x = 294912;
    }
  }
LABEL_188:
  if ( npc->act_no > 10 && npc->act_no <= 500 )
  {
    if ( npc->act_no == 102 )
    {
      gSuperXpos = npc->tgt_x;
      gSuperYpos = npc->tgt_y;
    }
    else
    {
      gSuperXpos = npc->x;
      gSuperYpos = npc->y;
    }
  }
  if ( npc->ym > 1535 )
    npc->ym = 1535;
  npc->x += npc->xm;
  npc->y += npc->ym;
  if ( npc->act_no <= 511 )
  {
    if ( npc->act_no > 509 )
    {
      v19 = 2 * Random(-512, 0);
      v20 = Random(-512, 512);
      v21 = npc->y - ((336 - npc->act_wait) / 8 << 9);
      v22 = npc->x;
      v23 = Random(-16, 16);
      SetNpChar(270, v22 + (v23 << 9), v21, v20, v19, 3, 0, 170);
      v24 = 2 * Random(-512, 0);
      v25 = Random(-512, 512);
      v26 = npc->y - ((336 - npc->act_wait) / 8 << 9);
      v27 = npc->x;
      v28 = Random(-16, 16);
      SetNpChar(270, v27 + (v28 << 9), v26, v25, v24, 3, 0, 170);
      v29 = 2 * Random(-512, 0);
      v30 = npc->y - ((336 - npc->act_wait) / 8 << 9);
      v31 = npc->x;
      v32 = Random(-16, 16);
      SetNpChar(270, v31 + (v32 << 9), v30, 0, v29, 3, 0, 170);
      v33 = 2 * Random(-512, 0);
      v34 = npc->y - ((336 - npc->act_wait) / 8 << 9);
      v35 = npc->x;
      v36 = Random(-16, 16);
      SetNpChar(270, v35 + (v36 << 9), v34, 0, v33, 3, 0, 170);
    }
    else
    {
      v13 = npc->act_no != 102 && npc->act_no != 103 && Random(0, 3) == 2;
      if ( v13 )
      {
        v14 = npc->xm;
        v15 = npc->y;
        v16 = (Random(-8, 4) << 9) + v15;
        v17 = npc->x;
        v18 = Random(-16, 16);
        SetNpChar(270, v17 + (v18 << 9), v16, v14, 0, 3, 0, 256);
      }
    }
  }
  if ( npc->direct )
  {
    v37 = npc;
    v38 = (Sint32 *)&v44[16 * npc->ani_no - 332];
  }
  else
  {
    v37 = npc;
    v38 = (Sint32 *)&v44[16 * npc->ani_no - 172];
  }
  npc->rect.left = *v38;
  v37->rect.top = v38[1];
  v37->rect.right = v38[2];
  v37->rect.bottom = v38[3];
  if ( npc->act_no == 511 )
  {
    npc->rect.top += npc->act_wait / 8;
    npc->view.top = (44 - npc->act_wait / 8) << 9;
    npc->view.bottom = 2048;
  }
  else if ( npc->act_no != 101 && npc->act_no != 103 )
  {
    npc->view.top = 14336;
  }
  else
  {
    npc->rect.top += npc->act_wait;
    npc->rect.bottom -= npc->act_wait;
    npc->view.top = (28 - npc->act_wait) << 9;
  }
}


void __cdecl ActNpc268(NPCHAR_0 *npc)
{
  char v1;
  NPCHAR_0 *v2;
  Sint32 *v3;
  RECT rcRight[10];
  RECT rcLeft[10];
  unsigned __int8 deg;
  int xm;
  int ym;
  char v9[24];

  qmemcpy(rcLeft, &ActNpc268(NPCHAR *)::C.22, sizeof(rcLeft));
  qmemcpy(rcRight, &ActNpc268(NPCHAR *)::C.23, sizeof(rcRight));
  if ( npc->x < x - 163840 || npc->x > x + 163840 || npc->y < y - 122880 || npc->y > y + 122880 )
    npc->act_no = 1;
  switch ( npc->act_no )
  {
    case 0:
      npc->act_no = 1;
      npc->y += 4096;
      goto LABEL_8;
    case 1:
LABEL_8:
      if ( ++npc->ani_wait > 20 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 1 )
        npc->ani_no = 0;
      if ( npc->x < x + 57344 && npc->x > x - 57344 && npc->x < x + 24576 && npc->x > x - 57344 )
        npc->act_no = 10;
      if ( npc->shock )
        npc->act_no = 10;
      break;
    case 0xA:
      npc->act_no = 11;
      npc->act_wait = 0;
      npc->ani_no = 0;
      npc->ani_wait = 0;
      if ( x >= npc->x )
        npc->direct = 2;
      else
        npc->direct = 0;
      goto LABEL_22;
    case 0xB:
LABEL_22:
      if ( npc->direct )
        npc->xm = 512;
      else
        npc->xm = -512;
      if ( npc->x < x + 0x8000 && npc->x > x - 0x8000 )
      {
        npc->act_no = 20;
        npc->act_wait = 0;
      }
      if ( npc->xm < 0 && npc->flag & 1 )
      {
        npc->act_no = 20;
        npc->act_wait = 0;
      }
      if ( npc->xm > 0 && npc->flag & 4 )
      {
        npc->act_no = 20;
        npc->act_wait = 0;
      }
      if ( ++npc->ani_wait > 4 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 5 )
        npc->ani_no = 2;
      break;
    case 0x14:
      npc->xm = 0;
      npc->ani_no = 6;
      if ( ++npc->act_wait > 10 )
      {
        npc->act_no = 30;
        npc->ym = -1535;
        if ( npc->direct )
          npc->xm = 512;
        else
          npc->xm = -512;
        PlaySoundObject(108, 1);
      }
      break;
    case 0x1E:
      npc->ani_no = 7;
      if ( npc->flag & 8 )
      {
        npc->act_no = 40;
        npc->act_wait = 0;
        SetQuake(20);
        PlaySoundObject(26, 1);
      }
      break;
    case 0x28:
      npc->xm = 0;
      npc->ani_no = 6;
      if ( ++npc->act_wait > 30 )
        npc->act_no = 50;
      break;
    case 0x32:
      npc->act_no = 51;
      npc->act_wait = 0;
      if ( x >= npc->x )
        npc->direct = 2;
      else
        npc->direct = 0;
      goto LABEL_50;
    case 0x33:
LABEL_50:
      if ( ++npc->act_wait > 30 && npc->act_wait % 4 == 1 )
      {
        if ( npc->direct )
          deg = -8;
        else
          deg = -120;
        v1 = Random(-16, 16);
        deg += v1;
        ym = 5 * GetSin(deg);
        xm = 5 * GetCos(deg);
        SetNpChar(11, npc->x, npc->y + 2048, xm, ym, 0, 0, 256);
        PlaySoundObject(12, 1);
      }
      if ( npc->act_wait <= 49 && npc->act_wait / 2 & 1 )
        npc->ani_no = 9;
      else
        npc->ani_no = 8;
      if ( npc->act_wait > 82 )
      {
        npc->act_no = 10;
        if ( x >= npc->x )
          npc->direct = 2;
        else
          npc->direct = 0;
      }
      break;
    default:
      break;
  }
  npc->ym += 51;
  if ( npc->ym > 1535 )
    npc->ym = 1535;
  npc->x += npc->xm;
  npc->y += npc->ym;
  if ( npc->direct )
  {
    v2 = npc;
    v3 = (Sint32 *)&v9[16 * npc->ani_no - 332];
  }
  else
  {
    v2 = npc;
    v3 = (Sint32 *)&v9[16 * npc->ani_no - 172];
  }
  npc->rect.left = *v3;
  v2->rect.top = v3[1];
  v2->rect.right = v3[2];
  v2->rect.bottom = v3[3];
}


void __cdecl ActNpc269(NPCHAR_0 *npc)
{
  int v1;
  NPCHAR_0 *v2;
  RECT *v3;
  RECT rcRight[3];
  RECT rcLeft[3];

  rcLeft[0].left = 232;
  rcLeft[0].top = 0;
  rcLeft[0].right = 248;
  rcLeft[0].bottom = 16;
  rcLeft[1].left = 248;
  rcLeft[1].top = 0;
  rcLeft[1].right = 264;
  rcLeft[1].bottom = 16;
  rcLeft[2].left = 248;
  rcLeft[2].top = 16;
  rcLeft[2].right = 264;
  rcLeft[2].bottom = 32;
  rcRight[0].left = 232;
  rcRight[0].top = 32;
  rcRight[0].right = 248;
  rcRight[0].bottom = 48;
  rcRight[1].left = 248;
  rcRight[1].top = 32;
  rcRight[1].right = 264;
  rcRight[1].bottom = 48;
  rcRight[2].left = 248;
  rcRight[2].top = 48;
  rcRight[2].right = 264;
  rcRight[2].bottom = 64;
  v1 = npc->act_no;
  if ( v1 )
  {
    if ( v1 != 1 )
      goto LABEL_21;
  }
  else
  {
    npc->act_no = 1;
    npc->xm2 = npc->xm;
    npc->ym2 = npc->ym;
  }
  if ( npc->xm2 < 0 && npc->flag & 1 )
  {
    npc->direct = 2;
    npc->xm2 = -npc->xm2;
  }
  else if ( npc->xm2 > 0 && npc->flag & 4 )
  {
    npc->direct = 0;
    npc->xm2 = -npc->xm2;
  }
  else if ( npc->ym2 < 0 && npc->flag & 2 )
  {
    npc->ym2 = -npc->ym2;
  }
  else if ( npc->ym2 > 0 && npc->flag & 8 )
  {
    npc->ym2 = -npc->ym2;
  }
  npc->x += npc->xm2;
  npc->y += npc->ym2;
  if ( ++npc->ani_wait > 2 )
  {
    npc->ani_wait = 0;
    ++npc->ani_no;
  }
  if ( npc->ani_no > 2 )
    npc->ani_no = 0;
LABEL_21:
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

void __cdecl ActNpc270(NPCHAR_0 *npc)
{
  Sint32 *v1;
  RECT rc[2];
  char v3[8];

  rc[0].left = 170;
  rc[0].top = 34;
  rc[0].right = 174;
  rc[0].bottom = 38;
  rc[1].left = 170;
  rc[1].top = 42;
  rc[1].right = 174;
  rc[1].bottom = 46;
  if ( npc->direct != 3 && npc->direct != 1 )
  {
    if ( npc->direct == 2 )
    {
      if ( !npc->act_no )
      {
        npc->act_no = 1;
        npc->bits |= 8u;
        npc->xm = 3 * Random(-512, 512);
        npc->ym = 3 * Random(-512, 512);
        npc->count1 = Random(16, 51);
        npc->count2 = Random(128, 256);
      }
      if ( npc->x < npc->pNpc->x )
        npc->xm += 512 / npc->count1;
      if ( npc->x > npc->pNpc->x )
        npc->xm -= 512 / npc->count1;
      if ( npc->y < npc->pNpc->y )
        npc->ym += 512 / npc->count1;
      if ( npc->y > npc->pNpc->y )
        npc->ym -= 512 / npc->count1;
      if ( npc->xm > 2 * npc->count2 )
        npc->xm = 2 * npc->count2;
      if ( npc->xm < -2 * npc->count2 )
        npc->xm = -2 * npc->count2;
      if ( npc->ym > 3 * npc->count2 )
        npc->ym = 3 * npc->count2;
      if ( npc->ym < -3 * npc->count2 )
        npc->ym = -3 * npc->count2;
      npc->x += npc->xm;
      npc->y += npc->ym;
    }
  }
  else
  {
    if ( npc->direct == 3 )
      npc->ym += 64;
    if ( npc->direct == 1 )
      npc->ym -= 64;
    ++npc->act_wait;
    if ( npc->ym > 1535 )
      npc->ym = 1535;
    npc->x += npc->xm;
    npc->y += npc->ym;
    if ( npc->act_wait > 50 )
      npc->cond = 0;
    if ( npc->flag & 0xFF )
      npc->cond = 0;
  }
  v1 = (Sint32 *)&v3[16 * Random(0, 1) - 32];
  npc->rect.left = *v1;
  npc->rect.top = v1[1];
  npc->rect.right = v1[2];
  npc->rect.bottom = v1[3];
}


void __cdecl ActNpc271(NPCHAR_0 *npc)
{
  int v1;
  int a;

  if ( npc->xm >= 0 || npc->x >= -8192 )
  {
    if ( npc->xm <= 0 || npc->x <= (gMap.width + 1) << 13 )
    {
      if ( !npc->act_no )
      {
        npc->act_no = 1;
        a = Random(0, 9);
        if ( a == 9 )
        {
          npc->rect.left = 0;
          npc->rect.right = 32;
          npc->rect.top = 64;
          npc->rect.bottom = 96;
          npc->view.front = 0x2000;
          npc->view.back = 0x2000;
          npc->view.top = 0x2000;
          npc->view.bottom = 0x2000;
          npc->hit.front = 6144;
          npc->hit.back = 6144;
          npc->hit.top = 6144;
          npc->hit.bottom = 6144;
        }
        else
        {
          npc->rect.left = 16 * (a % 3 + 7);
          npc->rect.top = 16 * (a / 3);
          npc->rect.right = npc->rect.left + 16;
          npc->rect.bottom = npc->rect.top + 16;
        }
        if ( npc->direct )
          v1 = 2 * Random(256, 512);
        else
          v1 = -2 * Random(256, 512);
        npc->xm = v1;
        npc->ym = Random(-512, 512);
      }
      if ( npc->ym < 0 && npc->y - npc->hit.top <= 4095 )
      {
        npc->ym = -npc->ym;
        SetCaret(npc->x, npc->y - 4096, 13, 0);
        SetCaret(npc->x, npc->y - 4096, 13, 0);
      }
      if ( npc->ym > 0 && npc->y + npc->hit.bottom > 118784 )
      {
        npc->ym = -npc->ym;
        SetCaret(npc->x, npc->y + 4096, 13, 0);
        SetCaret(npc->x, npc->y + 4096, 13, 0);
      }
      npc->x += npc->xm;
      npc->y += npc->ym;
    }
    else
    {
      VanishNpChar(npc);
    }
  }
  else
  {
    VanishNpChar(npc);
  }
}

void __cdecl ActNpc272(NPCHAR_0 *npc)
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
    npc->act_wait = Random(0, 200);
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
    SetNpChar(271, npc->x, v3 + (v4 << 9), 0, 0, v2, 0, 256);
  }
}

void __cdecl ActNpc273(NPCHAR_0 *npc)
{
  int v1;
  Sint32 *v2;
  RECT rc[3];
  char v4[8];

  rc[0].left = 248;
  rc[0].top = 40;
  rc[0].right = 272;
  rc[0].bottom = 64;
  rc[1].left = 272;
  rc[1].top = 40;
  rc[1].right = 296;
  rc[1].bottom = 64;
  rc[2].left = 296;
  rc[2].top = 40;
  rc[2].right = 320;
  rc[2].bottom = 64;
  v1 = npc->act_no;
  if ( v1 )
  {
    if ( v1 != 1 )
      goto LABEL_11;
  }
  else
  {
    npc->act_no = 1;
  }
  npc->x += npc->xm;
  npc->y += npc->ym;
  if ( npc->flag & 0xFF )
  {
    SetNpChar(4, npc->x, npc->y, 0, 0, 0, 0, 256);
    SetNpChar(4, npc->x, npc->y, 0, 0, 0, 0, 256);
    SetNpChar(4, npc->x, npc->y, 0, 0, 0, 0, 256);
    VanishNpChar(npc);
    return;
  }
  if ( !(++npc->act_wait % 5) )
    PlaySoundObject(110, 1);
  if ( ++npc->ani_no > 2 )
    npc->ani_no = 0;
LABEL_11:
  v2 = (Sint32 *)&v4[16 * npc->ani_no - 48];
  npc->rect.left = *v2;
  npc->rect.top = v2[1];
  npc->rect.right = v2[2];
  npc->rect.bottom = v2[3];
}


void __cdecl ActNpc274(NPCHAR_0 *npc)
{
  NPCHAR_0 *v1;
  Sint32 *v2;
  RECT rcRight[6];
  RECT rcLeft[6];
  unsigned __int8 deg;
  int xm;
  int ym;
  char v8[24];

  qmemcpy(rcLeft, &ActNpc274(NPCHAR *)::C.25, sizeof(rcLeft));
  qmemcpy(rcRight, &ActNpc274(NPCHAR *)::C.26, sizeof(rcRight));
  switch ( npc->act_no )
  {
    case 0:
      npc->act_no = 1;
      npc->y -= 4096;
      npc->tgt_x = npc->x;
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
      if ( ++npc->ani_wait > 40 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 1 )
        npc->ani_no = 0;
      if ( npc->shock )
        npc->act_no = 10;
      break;
    case 0xA:
      npc->act_no = 11;
      npc->ani_no = 2;
      npc->act_wait = 0;
      goto LABEL_14;
    case 0xB:
LABEL_14:
      if ( ++npc->act_wait > 10 )
      {
        npc->act_no = 12;
        npc->ani_no = 3;
        npc->ym = -1536;
        npc->count1 = 0;
        if ( npc->tgt_x <= npc->x )
          npc->xm = -512;
        else
          npc->xm = 512;
      }
      break;
    case 0xC:
      if ( npc->ym > 0 )
      {
        npc->ani_no = 4;
        if ( !npc->count1 )
        {
          ++npc->count1;
          deg = GetArktan(npc->x - x, npc->y - 5120 - y);
          ym = 4 * GetSin(deg);
          xm = 4 * GetCos(deg);
          SetNpChar(273, npc->x, npc->y - 5120, xm, ym, 0, 0, 256);
          PlaySoundObject(39, 1);
        }
      }
      if ( npc->ym > 512 )
        npc->ani_no = 5;
      if ( npc->flag & 8 )
      {
        npc->ani_no = 2;
        npc->act_no = 13;
        npc->act_wait = 0;
        npc->xm = 0;
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
  npc->ym += 85;
  if ( npc->ym > 1535 )
    npc->ym = 1535;
  npc->x += npc->xm;
  npc->y += npc->ym;
  if ( npc->direct )
  {
    v1 = npc;
    v2 = (Sint32 *)&v8[16 * npc->ani_no - 204];
  }
  else
  {
    v1 = npc;
    v2 = (Sint32 *)&v8[16 * npc->ani_no - 108];
  }
  npc->rect.left = *v2;
  v1->rect.top = v2[1];
  v1->rect.right = v2[2];
  v1->rect.bottom = v2[3];
}


void __cdecl ActNpc275(NPCHAR_0 *npc)
{
  int v1;
  Sint32 *v2;
  RECT rcRight[4];
  char v4[8];

  rcRight[0].left = 272;
  rcRight[0].top = 80;
  rcRight[0].right = 288;
  rcRight[0].bottom = 96;
  rcRight[1].left = 288;
  rcRight[1].top = 80;
  rcRight[1].right = 304;
  rcRight[1].bottom = 96;
  rcRight[2].left = 272;
  rcRight[2].top = 80;
  rcRight[2].right = 288;
  rcRight[2].bottom = 96;
  rcRight[3].left = 304;
  rcRight[3].top = 80;
  rcRight[3].right = 320;
  rcRight[3].bottom = 96;
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
    goto LABEL_17;
  }
  if ( v1 != 2 )
  {
    if ( v1 )
      goto LABEL_17;
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
LABEL_17:
  npc->ym += 64;
  if ( npc->ym > 1535 )
    npc->ym = 1535;
  npc->x += npc->xm;
  npc->y += npc->ym;
  v2 = (Sint32 *)&v4[16 * npc->ani_no - 64];
  npc->rect.left = *v2;
  npc->rect.top = v2[1];
  npc->rect.right = v2[2];
  npc->rect.bottom = v2[3];
}


void __cdecl ActNpc276(NPCHAR_0 *npc)
{
  unsigned int v1;
  signed int v2;
  unsigned int v3;
  signed int v4;
  NPCHAR_0 *v5;
  Sint32 *v6;
  RECT rcRight[9];
  RECT rcLeft[9];
  unsigned __int8 deg;
  int xm;
  int ym;
  char v12[24];

  qmemcpy(rcLeft, &ActNpc276(NPCHAR *)::C.29, sizeof(rcLeft));
  qmemcpy(rcRight, &ActNpc276(NPCHAR *)::C.30, sizeof(rcRight));
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
      if ( ++npc->ani_wait > 20 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 1 )
        npc->ani_no = 0;
      if ( npc->shock )
        npc->act_no = 10;
      break;
    case 0xA:
      npc->act_no = 11;
      npc->act_wait = 0;
      npc->ani_no = 3;
      npc->bits |= 0x20u;
      goto LABEL_14;
    case 0xB:
LABEL_14:
      v1 = ++npc->act_wait - 30;
      if ( v1 <= 0x18 )
      {
        v2 = 1 << v1;
        if ( v2 & 0x1004010 )
        {
          npc->ani_no = 3;
        }
        else if ( v2 & 0x100401 )
        {
          npc->ani_no = 4;
          deg = GetArktan(npc->x - x, npc->y - y);
          ym = 4 * GetSin(deg);
          xm = 4 * GetCos(deg);
          SetNpChar(277, npc->x, npc->y, xm, ym, 0, 0, 256);
          PlaySoundObject(39, 1);
        }
      }
      if ( npc->act_wait > 60 )
      {
        npc->act_no = 20;
        npc->act_wait = 0;
        npc->ani_no = 2;
      }
      break;
    case 0x14:
      if ( ++npc->act_wait > 20 )
      {
        npc->act_no = 21;
        npc->act_wait = 0;
        npc->ani_no = 5;
        npc->ym = -1535;
        if ( npc->x >= x )
          npc->xm = -256;
        else
          npc->xm = 256;
      }
      break;
    case 0x15:
      v3 = ++npc->act_wait - 30;
      if ( v3 <= 0x14 )
      {
        v4 = 1 << v3;
        if ( v4 & 0x100401 )
        {
          npc->ani_no = 6;
          deg = GetArktan(npc->x - x, npc->y - 5120 - y);
          ym = 4 * GetSin(deg);
          xm = 4 * GetCos(deg);
          SetNpChar(277, npc->x, npc->y - 5120, xm, ym, 0, 0, 256);
          PlaySoundObject(39, 1);
        }
        else if ( v4 & 0x4010 )
        {
          npc->ani_no = 5;
        }
      }
      if ( npc->act_wait > 53 )
        npc->ani_no = 7;
      if ( npc->flag & 8 )
      {
        npc->act_no = 22;
        npc->act_wait = 0;
        npc->ani_no = 2;
        SetQuake(10);
        PlaySoundObject(26, 1);
      }
      break;
    case 0x16:
      npc->xm /= 2;
      if ( ++npc->act_wait > 22 )
        npc->act_no = 10;
      break;
    case 0x32:
      npc->bits &= 0xFFDFu;
      npc->damage = 0;
      if ( npc->flag & 8 )
      {
        npc->act_no = 51;
        npc->ani_no = 2;
        SetQuake(10);
        SetExpObjects(npc->x, npc->y, 19);
        SetDestroyNpChar(npc->x, npc->y, npc->view.back, 8);
        PlaySoundObject(72, 1);
      }
      break;
    case 0x33:
      npc->xm = 7 * npc->xm / 8;
      npc->ani_no = 8;
      break;
    default:
      break;
  }
  npc->ym += 32;
  if ( npc->ym > 1535 )
    npc->ym = 1535;
  npc->x += npc->xm;
  npc->y += npc->ym;
  if ( npc->act_no <= 49 )
  {
    if ( npc->x >= x )
      npc->direct = 0;
    else
      npc->direct = 2;
  }
  if ( npc->direct )
  {
    v5 = npc;
    v6 = (Sint32 *)&v12[16 * npc->ani_no - 300];
  }
  else
  {
    v5 = npc;
    v6 = (Sint32 *)&v12[16 * npc->ani_no - 156];
  }
  npc->rect.left = *v6;
  v5->rect.top = v6[1];
  v5->rect.right = v6[2];
  v5->rect.bottom = v6[3];
}


void __cdecl ActNpc277(NPCHAR_0 *npc)
{
  int v1;
  Sint32 *v2;
  RECT rc[3];
  char v4[8];

  rc[0].left = 128;
  rc[0].top = 0;
  rc[0].right = 152;
  rc[0].bottom = 24;
  rc[1].left = 152;
  rc[1].top = 0;
  rc[1].right = 176;
  rc[1].bottom = 24;
  rc[2].left = 176;
  rc[2].top = 0;
  rc[2].right = 200;
  rc[2].bottom = 24;
  v1 = npc->act_no;
  if ( v1 )
  {
    if ( v1 != 1 )
      goto LABEL_11;
  }
  else
  {
    npc->act_no = 1;
  }
  npc->x += npc->xm;
  npc->y += npc->ym;
  if ( npc->flag & 0xFF )
  {
    SetNpChar(4, npc->x, npc->y, 0, 0, 0, 0, 256);
    SetNpChar(4, npc->x, npc->y, 0, 0, 0, 0, 256);
    SetNpChar(4, npc->x, npc->y, 0, 0, 0, 0, 256);
    VanishNpChar(npc);
    return;
  }
  if ( !(++npc->act_wait % 5) )
    PlaySoundObject(110, 1);
  if ( ++npc->ani_no > 2 )
    npc->ani_no = 0;
LABEL_11:
  v2 = (Sint32 *)&v4[16 * npc->ani_no - 48];
  npc->rect.left = *v2;
  npc->rect.top = v2[1];
  npc->rect.right = v2[2];
  npc->rect.bottom = v2[3];
}


void __cdecl ActNpc278(NPCHAR_0 *npc)
{
  int v1;
  Sint32 *v2;
  Sint32 *v3;
  RECT rcKodomo[2];
  RECT rcMama[2];
  RECT rcPapa[2];
  char v7[8];

  rcPapa[0].left = 0;
  rcPapa[0].top = 120;
  rcPapa[0].right = 8;
  rcPapa[0].bottom = 128;
  rcPapa[1].left = 8;
  rcPapa[1].top = 120;
  rcPapa[1].right = 16;
  rcPapa[1].bottom = 128;
  rcMama[0].left = 16;
  rcMama[0].top = 120;
  rcMama[0].right = 24;
  rcMama[0].bottom = 128;
  rcMama[1].left = 24;
  rcMama[1].top = 120;
  rcMama[1].right = 32;
  rcMama[1].bottom = 128;
  rcKodomo[0].left = 32;
  rcKodomo[0].top = 120;
  rcKodomo[0].right = 40;
  rcKodomo[0].bottom = 128;
  rcKodomo[1].left = 40;
  rcKodomo[1].top = 120;
  rcKodomo[1].right = 48;
  rcKodomo[1].bottom = 128;
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
      npc->ani_no = 0;
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
        npc->xm = 256;
      else
        npc->xm = -256;
      if ( ++npc->ani_wait > 4 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 1 )
        npc->ani_no = 0;
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
  v1 = npc->code_event;
  if ( v1 == 200 )
  {
    v2 = (Sint32 *)&v7[16 * npc->ani_no - 32];
    npc->rect.left = *v2;
    npc->rect.top = v2[1];
    npc->rect.right = v2[2];
    npc->rect.bottom = v2[3];
  }
  else
  {
    if ( v1 == 210 )
      v3 = (Sint32 *)&v7[16 * npc->ani_no - 64];
    else
      v3 = (Sint32 *)&v7[16 * npc->ani_no - 96];
    npc->rect.left = *v3;
    npc->rect.top = v3[1];
    npc->rect.right = v3[2];
    npc->rect.bottom = v3[3];
  }
}


void __cdecl ActNpc279(NPCHAR_0 *npc)
{
  int v1;
  int v2;
  int v3;
  int v4;
  int v5;
  int v6;
  int v7;
  Sint32 *v8;
  RECT rc[2];
  int i;
  char v11[24];

  rc[0].left = 0;
  rc[0].top = 16;
  rc[0].right = 32;
  rc[0].bottom = 48;
  rc[1].left = 16;
  rc[1].top = 0;
  rc[1].right = 32;
  rc[1].bottom = 16;
  v1 = npc->act_no;
  if ( v1 == 100 )
  {
    npc->ym += 64;
    if ( npc->ym > 1792 )
      npc->ym = 1792;
    if ( npc->y > 0x10000 )
      npc->bits &= 0xFFF7u;
    if ( npc->flag & 8 )
    {
      npc->ym = -512;
      npc->act_no = 110;
      npc->bits |= 8u;
      PlaySoundObject(26, 1);
      SetQuake(10);
      for ( i = 0; i <= 3; ++i )
      {
        v3 = Random(-1536, 0);
        v4 = Random(-341, 341);
        v5 = npc->y + 0x2000;
        v6 = npc->x;
        v7 = Random(-12, 12);
        SetNpChar(4, v6 + (v7 << 9), v5, v4, v3, 0, 0, 256);
      }
    }
    goto LABEL_31;
  }
  if ( v1 > 100 )
  {
    if ( v1 == 110 )
    {
      npc->ym += 64;
      if ( npc->y > (gMap.length + 2) << 13 )
      {
        npc->cond = 0;
        return;
      }
    }
  }
  else
  {
    if ( !v1 )
    {
      v2 = npc->direct;
      switch ( v2 )
      {
        case 1:
          npc->ani_no = 0;
          npc->act_no = 10;
          break;
        case 2:
          npc->act_no = 100;
          npc->bits |= 4u;
          npc->ani_no = 1;
          npc->view.back = 4096;
          npc->view.front = 4096;
          npc->view.top = 4096;
          npc->view.bottom = 4096;
          npc->hit.back = 4096;
          npc->hit.front = 4096;
          npc->hit.top = 4096;
          npc->hit.bottom = 4096;
          break;
        case 0:
          npc->act_no = 100;
          npc->bits |= 4u;
          npc->ani_no = 0;
          break;
      }
      if ( npc->direct != 1 )
        goto LABEL_31;
      goto LABEL_17;
    }
    if ( v1 >= 0 )
    {
      if ( v1 != 10 )
      {
        if ( v1 != 11 )
          goto LABEL_31;
LABEL_18:
        npc->act_wait -= 2;
        if ( npc->act_wait <= 0 )
        {
          npc->act_no = 100;
          npc->bits |= 4u;
        }
        goto LABEL_31;
      }
LABEL_17:
      npc->act_no = 11;
      npc->act_wait = 16;
      goto LABEL_18;
    }
  }
LABEL_31:
  if ( y <= npc->y )
    npc->damage = 0;
  else
    npc->damage = 10;
  npc->y += npc->ym;
  v8 = (Sint32 *)&v11[16 * npc->ani_no - 36];
  npc->rect.left = *v8;
  npc->rect.top = v8[1];
  npc->rect.right = v8[2];
  npc->rect.bottom = v8[3];
  if ( npc->act_no == 11 )
  {
    npc->rect.top += npc->act_wait;
    npc->rect.bottom -= npc->act_wait;
    npc->view.top = (16 - npc->act_wait) << 9;
  }
}


