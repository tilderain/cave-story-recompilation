//#include "types.h"
#include "SDL_stdinc.h"
#include "windows_wrapper.h"
#include "Tags.h"
#include "forNpc.h"
#include "windows_wrapper.h"

void ActNpc180(NPCHAR *npc);
void ActNpc181(NPCHAR *npc);
void ActNpc182(NPCHAR *npc);
void ActNpc183(NPCHAR *npc);
void ActNpc184(NPCHAR *npc);
void ActNpc185(NPCHAR *npc);
void ActNpc186(NPCHAR *npc);
void ActNpc187(NPCHAR *npc);
void ActNpc188(NPCHAR *npc);
void ActNpc189(NPCHAR *npc);
void ActNpc190(NPCHAR *npc);
void ActNpc191(NPCHAR *npc);
void ActNpc192(NPCHAR *npc);
void ActNpc193(NPCHAR *npc);
void ActNpc194(NPCHAR *npc);
void ActNpc195(NPCHAR *npc);
void ActNpc196(NPCHAR *npc);
void ActNpc197(NPCHAR *npc);
void ActNpc198(NPCHAR *npc);
void ActNpc199(NPCHAR *npc);

_UNKNOWN ActNpc199(NPCHAR *)::C.16;
_UNKNOWN ActNpc180(NPCHAR *)::C.0;
_UNKNOWN ActNpc180(NPCHAR *)::C.1;


void ActNpc180(NPCHAR *npc)
{
  int v1;
  unsigned __int16 v2;
  bool v3;
  int v4;
  int v5;
  NPCHAR *v6;
  RECT *v7;
  RECT rcRight[11];
  RECT rcLeft[11];
  int xx;
  int yy;
  RECT *v12;

  qmemcpy(rcLeft, &ActNpc180(NPCHAR *)::C.0, sizeof(rcLeft));
  qmemcpy(rcRight, &ActNpc180(NPCHAR *)::C.1, sizeof(rcRight));
  if ( npc->y >= y - 0x14000 )
  {
    if ( gCurlyShoot_wait )
    {
      npc->tgt_x = gCurlyShoot_x;
      npc->tgt_y = gCurlyShoot_y;
    }
    else
    {
      npc->tgt_x = x;
      npc->tgt_y = y;
    }
  }
  else
  {
    if ( npc->y > 0x1FFFF )
      npc->tgt_x = 0;
    else
      npc->tgt_x = 2621440;
    npc->tgt_y = npc->y;
  }
  if ( npc->xm < 0 && npc->flag & 1 )
    npc->xm = 0;
  if ( npc->xm > 0 && npc->flag & 4 )
    npc->xm = 0;
  v1 = npc->act_no;
  if ( v1 == 41 )
  {
LABEL_34:
    if ( ++npc->act_wait == 750 )
    {
      v2 = npc->bits;
      HIBYTE(v2) &= 0xDFu;                      // TODO: This is probably a compiler optimisation. Compare to unoptimised Windows build.
      npc->bits = v2;
      npc->ani_no = 0;
    }
    if ( npc->act_wait > 1000 )
    {
      npc->act_no = 100;
      npc->ani_no = 0;
      SetNpChar(183, 0, 0, 0, 0, 0, npc, 256);
      if ( (unsigned __int8)GetNPCFlag(563) )
        SetNpChar(182, 0, 0, 0, 0, 0, npc, 256);
      else
        SetNpChar(181, 0, 0, 0, 0, 0, npc, 256);
    }
    goto LABEL_54;
  }
  if ( v1 <= 41 )
  {
    if ( v1 == 11 || v1 <= 11 )
      goto LABEL_54;
    if ( v1 == 20 )
    {
      npc->x = x;
      npc->y = y;
      npc->act_no = 100;
      npc->ani_no = 0;
      SetNpChar(183, 0, 0, 0, 0, 0, npc, 256);
      if ( (unsigned __int8)GetNPCFlag(563) )
        SetNpChar(182, 0, 0, 0, 0, 0, npc, 256);
      else
        SetNpChar(181, 0, 0, 0, 0, 0, npc, 256);
      goto LABEL_54;
    }
    if ( v1 != 40 )
      goto LABEL_54;
    npc->act_no = 41;
    npc->act_wait = 0;
    npc->ani_no = 10;
    goto LABEL_34;
  }
  if ( v1 == 210 )
  {
    npc->xm -= 32;
    npc->direct = 0;
    if ( npc->flag & 8 )
      npc->act_no = 100;
  }
  else if ( v1 > 210 )
  {
    if ( v1 == 300 )
    {
      npc->xm += 32;
      npc->direct = 2;
      if ( npc->flag & 4 )
        ++npc->count1;
      else
        npc->count1 = 0;
    }
    else if ( v1 == 310 )
    {
      npc->xm += 32;
      npc->direct = 2;
      if ( npc->flag & 8 )
        npc->act_no = 100;
    }
  }
  else if ( v1 == 100 )
  {
    npc->ani_no = 0;
    npc->xm = 7 * npc->xm / 8;
    npc->count1 = 0;
    if ( npc->x <= npc->tgt_x + 0x2000 )
    {
      if ( npc->x < npc->tgt_x - 0x2000 )
      {
        npc->act_no = 300;
        npc->ani_no = 1;
        npc->direct = 2;
        npc->act_wait = Random(20, 60);
      }
    }
    else
    {
      npc->act_no = 200;
      npc->ani_no = 1;
      npc->direct = 0;
      npc->act_wait = Random(20, 60);
    }
  }
  else if ( v1 == 200 )
  {
    npc->xm -= 32;
    npc->direct = 0;
    if ( npc->flag & 1 )
      ++npc->count1;
    else
      npc->count1 = 0;
  }
LABEL_54:
  if ( gCurlyShoot_wait )
    --gCurlyShoot_wait;
  if ( gCurlyShoot_wait == 70 )
    npc->count2 = 10;
  v3 = gCurlyShoot_wait == 60 && npc->flag & 8 && Random(0, 2);
  if ( v3 )
  {
    npc->count1 = 0;
    npc->ym = -1536;
    npc->ani_no = 1;
    PlaySoundObject(15, 1);
    if ( npc->x <= npc->tgt_x )
      npc->act_no = 310;
    else
      npc->act_no = 210;
  }
  xx = npc->x - npc->tgt_x;
  yy = npc->y - npc->tgt_y;
  if ( xx < 0 )
    xx = -xx;
  if ( npc->act_no == 100 )
  {
    if ( xx + 1024 >= yy )
      npc->ani_no = 0;
    else
      npc->ani_no = 5;
  }
  if ( npc->act_no == 210 || npc->act_no == 310 )
  {
    if ( xx + 1024 >= yy )
      npc->ani_no = 1;
    else
      npc->ani_no = 6;
  }
  if ( npc->act_no == 200 || npc->act_no == 300 )
  {
    ++npc->ani_wait;
    if ( xx + 1024 >= yy )
      v4 = npc->ani_wait / 4 % 4 + 1;
    else
      v4 = npc->ani_wait / 4 % 4 + 6;
    npc->ani_no = v4;
    if ( npc->act_wait )
    {
      --npc->act_wait;
      if ( npc->flag && npc->count1 > 10 )
      {
        npc->count1 = 0;
        npc->ym = -1536;
        npc->act_no += 10;
        npc->ani_no = 1;
        PlaySoundObject(15, 1);
      }
    }
    else
    {
      npc->act_no = 100;
      npc->ani_no = 0;
    }
  }
  if ( npc->act_no > 99 && npc->act_no <= 499 )
  {
    if ( npc->x >= x - 40960 && npc->x <= x + 40960 )
    {
      npc->ym += 51;
    }
    else
    {
      if ( npc->flag )
        v5 = npc->ym + 16;
      else
        v5 = npc->ym + 51;
      npc->ym = v5;
    }
  }
  if ( npc->xm > 768 )
    npc->xm = 768;
  if ( npc->xm < -768 )
    npc->xm = -768;
  if ( npc->ym > 1535 )
    npc->ym = 1535;
  npc->x += npc->xm;
  npc->y += npc->ym;
  if ( npc->act_no > 99 && !(npc->flag & 8) && npc->ani_no != 1000 )
  {
    if ( xx + 1024 >= yy )
      npc->ani_no = 1;
    else
      npc->ani_no = 6;
  }
  if ( npc->direct )
  {
    v6 = npc;
    v7 = (RECT *)(&v12 + 4 * npc->ani_no - 90);
  }
  else
  {
    v6 = npc;
    v7 = (RECT *)(&v12 + 4 * npc->ani_no - 46);
  }
  npc->rect.left = v7->left;
  v6->rect.top = v7->top;
  v6->rect.right = v7->right;
  v6->rect.bottom = v7->bottom;
}
/* Orphan comments:
TODO: More WTF
TODO: Actually points at end of RECT array
*/

void ActNpc181(NPCHAR *npc)
{
  int v1;
  int v2;
  NPCHAR *v3;
  RECT *v4;
  RECT rcRight[2];
  RECT rcLeft[2];
  RECT *v7;

  rcLeft[0].left = 216;
  rcLeft[0].top = 152;
  rcLeft[0].right = 232;
  rcLeft[0].bottom = 168;
  rcLeft[1].left = 232;
  rcLeft[1].top = 152;
  rcLeft[1].right = 248;
  rcLeft[1].bottom = 168;
  rcRight[0].left = 216;
  rcRight[0].top = 168;
  rcRight[0].right = 232;
  rcRight[0].bottom = 184;
  rcRight[1].left = 232;
  rcRight[1].top = 168;
  rcRight[1].right = 248;
  rcRight[1].bottom = 184;
  if ( npc->pNpc )
  {
    if ( npc->pNpc->ani_no > 4 )
    {
      if ( npc->pNpc->direct )
        npc->direct = 2;
      else
        npc->direct = 0;
      npc->x = npc->pNpc->x;
      npc->y = npc->pNpc->y - 5120;
      npc->ani_no = 1;
    }
    else
    {
      if ( npc->pNpc->direct )
      {
        npc->direct = 2;
        v1 = npc->pNpc->x + 4096;
      }
      else
      {
        npc->direct = 0;
        v1 = npc->pNpc->x - 4096;
      }
      npc->x = v1;
      npc->y = npc->pNpc->y;
      npc->ani_no = 0;
    }
    if ( npc->pNpc->ani_no == 1 || npc->pNpc->ani_no == 3 || npc->pNpc->ani_no == 6 || npc->pNpc->ani_no == 8 )
      npc->y -= 512;
    v2 = npc->act_no;
    if ( v2 )
    {
      if ( v2 == 10 )
      {
        if ( ++npc->act_wait % 6 == 1 )
        {
          if ( npc->ani_no )
          {
            if ( npc->direct )
            {
              SetBullet(12, npc->x + 1024, npc->y - 2048, 1);
              SetCaret(npc->x + 1024, npc->y - 2048, 3, 0);
            }
            else
            {
              SetBullet(12, npc->x - 1024, npc->y - 2048, 1);
              SetCaret(npc->x - 1024, npc->y - 2048, 3, 0);
            }
          }
          else if ( npc->direct )
          {
            SetBullet(12, npc->x + 2048, npc->y + 1536, 2);
            SetCaret(npc->x + 2048, npc->y + 1536, 3, 0);
          }
          else
          {
            SetBullet(12, npc->x - 2048, npc->y + 1536, 0);
            SetCaret(npc->x - 2048, npc->y + 1536, 3, 0);
          }
        }
        if ( npc->act_wait == 60 )
          npc->act_no = 0;
      }
    }
    else if ( npc->pNpc->count2 == 10 )
    {
      npc->pNpc->count2 = 0;
      npc->act_no = 10;
      npc->act_wait = 0;
    }
    if ( npc->direct )
    {
      v3 = npc;
      v4 = (RECT *)&(&v7)[4 * npc->ani_no - 1]; // rcRight
    }
    else
    {
      v3 = npc;
      v4 = (RECT *)(&v7 + 4 * npc->ani_no - 8); // rcLeft
    }
    npc->rect.left = v4->left;
    v3->rect.top = v4->top;
    v3->rect.right = v4->right;
    v3->rect.bottom = v4->bottom;
  }
}

void ActNpc182(NPCHAR *npc)
{
  int v1;
  int v2;
  NPCHAR *v3;
  RECT *v4;
  RECT rcRight[2];
  RECT rcLeft[2];
  RECT *v7;

  rcLeft[0].left = 184;
  rcLeft[0].top = 152;
  rcLeft[0].right = 200;
  rcLeft[0].bottom = 168;
  rcLeft[1].left = 200;
  rcLeft[1].top = 152;
  rcLeft[1].right = 216;
  rcLeft[1].bottom = 168;
  rcRight[0].left = 184;
  rcRight[0].top = 168;
  rcRight[0].right = 200;
  rcRight[0].bottom = 184;
  rcRight[1].left = 200;
  rcRight[1].top = 168;
  rcRight[1].right = 216;
  rcRight[1].bottom = 184;
  if ( npc->pNpc )
  {
    if ( npc->pNpc->ani_no > 4 )
    {
      if ( npc->pNpc->direct )
        npc->direct = 2;
      else
        npc->direct = 0;
      npc->x = npc->pNpc->x;
      npc->y = npc->pNpc->y - 5120;
      npc->ani_no = 1;
    }
    else
    {
      if ( npc->pNpc->direct )
      {
        npc->direct = 2;
        v1 = npc->pNpc->x + 4096;
      }
      else
      {
        npc->direct = 0;
        v1 = npc->pNpc->x - 4096;
      }
      npc->x = v1;
      npc->y = npc->pNpc->y;
      npc->ani_no = 0;
    }
    if ( npc->pNpc->ani_no == 1 || npc->pNpc->ani_no == 3 || npc->pNpc->ani_no == 6 || npc->pNpc->ani_no == 8 )
      npc->y -= 512;
    v2 = npc->act_no;
    if ( v2 )
    {
      if ( v2 == 10 )
      {
        if ( ++npc->act_wait % 12 == 1 )
        {
          if ( npc->ani_no )
          {
            if ( npc->direct )
            {
              SetBullet(6, npc->x + 1024, npc->y - 2048, 1);
              SetCaret(npc->x + 1024, npc->y - 2048, 3, 0);
            }
            else
            {
              SetBullet(6, npc->x - 1024, npc->y - 2048, 1);
              SetCaret(npc->x - 1024, npc->y - 2048, 3, 0);
            }
          }
          else if ( npc->direct )
          {
            SetBullet(6, npc->x + 2048, npc->y + 1536, 2);
            SetCaret(npc->x + 2048, npc->y + 1536, 3, 0);
          }
          else
          {
            SetBullet(6, npc->x - 2048, npc->y + 1536, 0);
            SetCaret(npc->x - 2048, npc->y + 1536, 3, 0);
          }
        }
        if ( npc->act_wait == 60 )
          npc->act_no = 0;
      }
    }
    else if ( npc->pNpc->count2 == 10 )
    {
      npc->pNpc->count2 = 0;
      npc->act_no = 10;
      npc->act_wait = 0;
    }
    if ( npc->direct )
    {
      v3 = npc;
      v4 = (RECT *)&(&v7)[4 * npc->ani_no - 1];
    }
    else
    {
      v3 = npc;
      v4 = (RECT *)(&v7 + 4 * npc->ani_no - 8);
    }
    npc->rect.left = v4->left;
    v3->rect.top = v4->top;
    v3->rect.right = v4->right;
    v3->rect.bottom = v4->bottom;
  }
}

void ActNpc183(NPCHAR *npc)
{
  RECT rect[2];
  RECT *v2;

  rect[0].left = 56;
  rect[0].top = 96;
  rect[0].right = 80;
  rect[0].bottom = 120;
  rect[1].left = 80;
  rect[1].top = 96;
  rect[1].right = 104;
  rect[1].bottom = 120;
  if ( npc->pNpc )
  {
    if ( !npc->act_no )
    {
      npc->x = npc->pNpc->x;
      npc->y = npc->pNpc->y;
      npc->act_no = 1;
    }
    npc->x += (npc->pNpc->x - npc->x) / 2;
    npc->y += (npc->pNpc->y - npc->y) / 2;
    if ( ++npc->ani_wait > 1 )
    {
      npc->ani_wait = 0;
      ++npc->ani_no;
    }
    if ( npc->ani_no > 1 )
      npc->ani_no = 0;
    if ( npc->pNpc->flag & 0x100 )
      npc->rect = (RECT)*((_OWORD *)&v2 + npc->ani_no - 2);
    else
      npc->rect.right = 0;
  }
}

void ActNpc184(NPCHAR *npc)
{
  int v1;
  int v2;
  int v3;
  int v4;
  int v5;
  int v6;
  RECT rc[4];
  int i;
  RECT *v9;

  rc[0].left = 0;
  rc[0].top = 64;
  rc[0].right = 32;
  rc[0].bottom = 96;
  rc[1].left = 32;
  rc[1].top = 64;
  rc[1].right = 64;
  rc[1].bottom = 96;
  rc[2].left = 64;
  rc[2].top = 64;
  rc[2].right = 96;
  rc[2].bottom = 96;
  rc[3].left = 32;
  rc[3].top = 64;
  rc[3].right = 64;
  rc[3].bottom = 96;
  switch ( npc->act_no )
  {
    case 0:
      npc->act_no = 1;
      npc->x += 4096;
      npc->y += 4096;
      break;
    case 0xA:
      npc->act_no = 11;
      npc->ani_no = 1;
      npc->act_wait = 0;
      npc->bits |= 8u;
      goto LABEL_4;
    case 0xB:
LABEL_4:
      v1 = npc->direct;
      if ( v1 == 1 )
      {
        npc->y -= 128;
      }
      else if ( v1 > 1 )
      {
        if ( v1 == 2 )
        {
          npc->x += 128;
        }
        else if ( v1 == 3 )
        {
          npc->y += 128;
        }
      }
      else if ( !v1 )
      {
        npc->x -= 128;
      }
      if ( !(++npc->act_wait & 7) )
        PlaySoundObject(26, 1);
      SetQuake(20);
      break;
    case 0x14:
      for ( i = 0; i <= 3; ++i )
      {
        v2 = Random(-1536, 0);
        v3 = Random(-341, 341);
        v4 = npc->y + 0x2000;
        v5 = npc->x;
        v6 = Random(-12, 12);
        SetNpChar(4, v5 + (v6 << 9), v4, v3, v2, 0, 0, 256);
      }
      npc->act_no = 1;
      break;
    default:
      break;
  }
  if ( ++npc->ani_wait > 10 )
  {
    npc->ani_wait = 0;
    ++npc->ani_no;
  }
  if ( npc->ani_no > 3 )
    npc->ani_no = 0;
  npc->rect = *(RECT *)(&(&v9)[4 * npc->ani_no - 1] - 1);
}

void ActNpc185(NPCHAR *npc)
{
  int v1;

  switch ( npc->act_no )
  {
    case 0:
      npc->act_no = 1;
      npc->y += 4096;
      break;
    case 0xA:
      npc->act_no = 11;
      npc->ani_no = 1;
      npc->act_wait = 0;
      npc->bits |= 8u;
      goto LABEL_4;
    case 0xB:
LABEL_4:
      v1 = npc->direct;
      if ( v1 == 1 )
      {
        npc->y -= 128;
      }
      else if ( v1 > 1 )
      {
        if ( v1 == 2 )
        {
          npc->x += 128;
        }
        else if ( v1 == 3 )
        {
          npc->y += 128;
        }
      }
      else if ( !v1 )
      {
        npc->x -= 128;
      }
      ++npc->act_wait;
      break;
    case 0x14:
      npc->y -= 12288;
      npc->act_no = 1;
      break;
    default:
      break;
  }
  npc->rect.left = 96;
  npc->rect.top = 64;
  npc->rect.right = 112;
  npc->rect.bottom = 96;
}

void ActNpc186(NPCHAR *npc)
{
  int v1;
  int v2;
  RECT *v3;
  RECT rc[4];

  rc[0].left = 48;
  rc[0].top = 48;
  rc[0].right = 64;
  rc[0].bottom = 64;
  rc[1].left = 64;
  rc[1].top = 48;
  rc[1].right = 80;
  rc[1].bottom = 64;
  rc[2].left = 80;
  rc[2].top = 48;
  rc[2].right = 96;
  rc[2].bottom = 64;
  rc[3].left = 64;
  rc[3].top = 48;
  rc[3].right = 80;
  rc[3].bottom = 64;
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
        goto LABEL_22;
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
      ++npc->act_wait;
    }
    else if ( !v1 )
    {
      npc->act_no = 1;
    }
  }
LABEL_22:
  if ( ++npc->ani_wait > 10 )
  {
    npc->ani_wait = 0;
    ++npc->ani_no;
  }
  if ( npc->ani_no > 3 )
    npc->ani_no = 0;
  v3 = &rc[npc->ani_no];
  npc->rect.left = v3->left;
  npc->rect.top = v3->top;
  npc->rect.right = v3->right;
  npc->rect.bottom = v3->bottom;
}

void ActNpc187(NPCHAR *npc)
{
  int v1;
  NPCHAR *v2;
  Sint32 *v3;
  RECT rect_right[2];
  RECT rect_left[2];
  int i;
  RECT *v7;

  v1 = npc->act_no;
  if ( v1 == 1 )
  {
LABEL_7:
    if ( ++npc->act_wait > 49 )
    {
      npc->act_wait = 0;
      npc->act_no = 2;
      npc->ym = 768;
    }
    goto LABEL_20;
  }
  if ( v1 != 2 )
  {
    if ( v1 )
      goto LABEL_20;
    npc->act_no = 1;
    npc->tgt_x = npc->x;
    npc->tgt_y = npc->y;
    npc->count1 = 120;
    npc->act_wait = Random(0, 50);
    for ( i = 0; i <= 4; ++i )
      SetNpChar(188, 0, 0, 0, 0, 51 * i, npc, 256);
    goto LABEL_7;
  }
  npc->count1 += 4;
  if ( x >= npc->x )
    npc->direct = 2;
  else
    npc->direct = 0;
  if ( npc->tgt_y < npc->y )
    npc->ym -= 16;
  if ( npc->tgt_y > npc->y )
    npc->ym += 16;
  if ( npc->ym > 853 )
    npc->ym = 853;
  if ( npc->ym < -853 )
    npc->ym = -853;
LABEL_20:
  npc->x += npc->xm;
  npc->y += npc->ym;
  rect_left[0].left = 224;
  rect_left[0].top = 104;
  rect_left[0].right = 256;
  rect_left[0].bottom = 136;
  rect_left[1].left = 256;
  rect_left[1].top = 104;
  rect_left[1].right = 288;
  rect_left[1].bottom = 136;
  rect_right[0].left = 224;
  rect_right[0].top = 136;
  rect_right[0].right = 256;
  rect_right[0].bottom = 168;
  rect_right[1].left = 256;
  rect_right[1].top = 136;
  rect_right[1].right = 288;
  rect_right[1].bottom = 168;
  if ( ++npc->ani_wait > 2 )
  {
    npc->ani_wait = 0;
    ++npc->ani_no;
  }
  if ( npc->ani_no > 1 )
    npc->ani_no = 0;
  if ( npc->direct )
  {
    v2 = npc;
    v3 = (Sint32 *)(&(&v7)[4 * npc->ani_no - 1] - 1);
  }
  else
  {
    v2 = npc;
    v3 = (Sint32 *)(&v7 + 4 * npc->ani_no - 9);
  }
  npc->rect.left = *v3;
  v2->rect.top = v3[1];
  v2->rect.right = v3[2];
  v2->rect.bottom = v3[3];
}

void ActNpc188(NPCHAR *npc)
{
  int v1;
  int v2;
  int v3;
  int v4;
  int v5;
  NPCHAR *v6;
  RECT *v7;
  RECT rect_right[2];
  RECT rect_left[2];
  unsigned __int8 deg;
  RECT *v11;

  v1 = npc->act_no;
  if ( v1 == 1 )
  {
LABEL_5:
    if ( npc->pNpc->code_char != 187 || (npc->pNpc->cond & 0x80u) == 0 )
    {
      npc->xm = Random(-512, 512);
      npc->ym = Random(-512, 512);
      npc->act_no = 10;
    }
    else
    {
      deg = LOBYTE(npc->count1) + LOBYTE(npc->pNpc->count1);
      v2 = npc->pNpc->x;
      npc->x = v2 + 20 * GetSin(deg);
      v3 = npc->pNpc->y;
      npc->y = v3 + 32 * GetCos(deg);
    }
    goto LABEL_24;
  }
  if ( v1 != 10 )
  {
    if ( v1 )
      goto LABEL_24;
    npc->act_no = 1;
    npc->count1 = npc->direct;
    goto LABEL_5;
  }
  if ( x >= npc->x )
    v4 = npc->xm + 32;
  else
    v4 = npc->xm - 32;
  npc->xm = v4;
  if ( y >= npc->y )
    v5 = npc->ym + 32;
  else
    v5 = npc->ym - 32;
  npc->ym = v5;
  if ( npc->xm > 2048 )
    npc->xm = 2048;
  if ( npc->xm < -2048 )
    npc->xm = -2048;
  if ( npc->ym > 512 )
    npc->ym = 512;
  if ( npc->ym < -512 )
    npc->ym = -512;
  npc->x += npc->xm;
  npc->y += npc->ym;
LABEL_24:
  if ( x >= npc->x )
    npc->direct = 2;
  else
    npc->direct = 0;
  if ( ++npc->ani_wait > 2 )
  {
    npc->ani_wait = 0;
    ++npc->ani_no;
  }
  if ( npc->ani_no > 1 )
    npc->ani_no = 0;
  rect_left[0].left = 288;
  rect_left[0].top = 104;
  rect_left[0].right = 304;
  rect_left[0].bottom = 120;
  rect_left[1].left = 304;
  rect_left[1].top = 104;
  rect_left[1].right = 320;
  rect_left[1].bottom = 120;
  rect_right[0].left = 288;
  rect_right[0].top = 120;
  rect_right[0].right = 304;
  rect_right[0].bottom = 136;
  rect_right[1].left = 304;
  rect_right[1].top = 120;
  rect_right[1].right = 320;
  rect_right[1].bottom = 136;
  if ( npc->direct )
  {
    v6 = npc;
    v7 = (RECT *)(&(&v11)[4 * npc->ani_no - 1] - 1);
  }
  else
  {
    v6 = npc;
    v7 = (RECT *)(&v11 + 4 * npc->ani_no - 9);
  }
  npc->rect.left = v7->left;
  v6->rect.top = v7->top;
  v6->rect.right = v7->right;
  v6->rect.bottom = v7->bottom;
}

void ActNpc189(NPCHAR *npc)
{
  int v1;
  int v2;
  int v3;
  RECT *v4;
  RECT rect[3];

  v1 = npc->act_no;
  if ( v1 == 1 )
  {
LABEL_5:
    npc->y += npc->ym;
    if ( ++npc->act_wait > 256 )
      npc->act_no = 10;
    goto LABEL_22;
  }
  if ( v1 != 10 )
  {
    if ( v1 )
      goto LABEL_22;
    npc->act_no = 1;
    npc->xm = -64;
    goto LABEL_5;
  }
  if ( x >= npc->x )
    v2 = npc->xm + 8;
  else
    v2 = npc->xm - 8;
  npc->xm = v2;
  if ( y >= npc->y )
    v3 = npc->ym + 8;
  else
    v3 = npc->ym - 8;
  npc->ym = v3;
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
LABEL_22:
  if ( x >= npc->x )
    npc->direct = 2;
  else
    npc->direct = 0;
  if ( ++npc->ani_wait > 2 )
  {
    npc->ani_wait = 0;
    ++npc->ani_no;
  }
  if ( npc->ani_no > 2 )
    npc->ani_no = 0;
  rect[0].left = 224;
  rect[0].top = 184;
  rect[0].right = 232;
  rect[0].bottom = 200;
  rect[1].left = 232;
  rect[1].top = 184;
  rect[1].right = 240;
  rect[1].bottom = 200;
  rect[2].left = 240;
  rect[2].top = 184;
  rect[2].right = 248;
  rect[2].bottom = 200;
  v4 = &rect[npc->ani_no];
  npc->rect.left = v4->left;
  npc->rect.top = v4->top;
  npc->rect.right = v4->right;
  npc->rect.bottom = v4->bottom;
}

void ActNpc190(NPCHAR *npc)
{
  int v1;
  int v2;
  int v3;
  int v4;
  int v5;
  RECT rect[2];
  int i;
  RECT *v8;

  rect[0].left = 192;
  rect[0].top = 32;
  rect[0].right = 208;
  rect[0].bottom = 48;
  rect[1].left = 208;
  rect[1].top = 32;
  rect[1].right = 224;
  rect[1].bottom = 48;
  v1 = npc->act_no;
  switch ( v1 )
  {
    case 10:
      PlaySoundObject(72, 1);
      for ( i = 0; i <= 7; ++i )
      {
        v2 = Random(-3, 3) << 9;
        v3 = Random(-8, -2) << 9;
        v4 = npc->y;
        v5 = Random(-8, 8);
        SetNpChar(4, npc->x, v4 + (v5 << 9), v3, v2, 0, 0, 256);
      }
      npc->cond = 0;
      break;
    case 20:
      if ( ++npc->ani_wait > 10 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 1 )
        npc->ani_no = 0;
      break;
    case 0:
      npc->ani_no = 0;
      break;
  }
  npc->rect = *(RECT *)(&v8 + 4 * npc->ani_no - 9);
}

void ActNpc191(NPCHAR *npc)
{
  int v1;
  int v2;
  int v3;
  int v4;

  switch ( npc->act_no )
  {
    case 0:
      npc->act_no = 10;
      npc->tgt_y = npc->y;
      npc->ym = 512;
      goto LABEL_3;
    case 0xA:
LABEL_3:
      if ( npc->y >= npc->tgt_y )
        v1 = npc->ym - 4;
      else
        v1 = npc->ym + 4;
      npc->ym = v1;
      if ( npc->ym < -256 )
        npc->ym = -256;
      if ( npc->ym > 256 )
        npc->ym = 256;
      npc->y += npc->ym;
      break;
    case 0x14:
      npc->act_no = 21;
      npc->act_wait = 0;
      goto LABEL_12;
    case 0x15:
LABEL_12:
      if ( npc->y >= npc->tgt_y )
        v2 = npc->ym - 4;
      else
        v2 = npc->ym + 4;
      npc->ym = v2;
      if ( npc->ym < -512 )
        npc->ym = -512;
      if ( npc->ym > 512 )
        npc->ym = 512;
      npc->y += npc->ym;
      if ( ++npc->act_wait > 1000 )
        npc->act_no = 22;
      break;
    case 0x16:
      if ( npc->y >= 0 )
        v3 = npc->ym - 4;
      else
        v3 = npc->ym + 4;
      npc->ym = v3;
      if ( npc->ym < -512 )
        npc->ym = -512;
      if ( npc->ym > 512 )
        npc->ym = 512;
      npc->y += npc->ym;
      if ( npc->y <= 0x7FFF || gSuperYpos )
      {
        npc->act_no = 21;
        npc->act_wait = 0;
      }
      break;
    case 0x1E:
      if ( npc->y >= 0 )
        v4 = npc->ym - 4;
      else
        v4 = npc->ym + 4;
      npc->ym = v4;
      if ( npc->ym < -512 )
        npc->ym = -512;
      if ( npc->ym > 256 )
        npc->ym = 256;
      npc->y += npc->ym;
      break;
    default:
      break;
  }
  gWaterY = npc->y;
  npc->rect.right = 0;
  npc->rect.bottom = 0;
}

void ActNpc192(NPCHAR *npc)
{
  int v1;
  int v2;
  int v3;
  NPCHAR *v4;
  RECT *v5;
  RECT rcRight[2];
  RECT rcLeft[2];
  RECT *v8;

  switch ( npc->act_no )
  {
    case 0:
      npc->act_no = 1;
      npc->view.back = 0x2000;
      npc->view.front = 0x2000;
      npc->view.top = 4096;
      npc->view.bottom = 4096;
      break;
    case 0xA:
      npc->act_no = 11;
      npc->ani_no = 1;
      npc->view.top = 0x2000;
      npc->view.bottom = 0x2000;
      npc->y -= 2560;
      break;
    case 0x14:
      npc->act_no = 21;
      npc->act_wait = 1;
      npc->tgt_x = npc->x;
      npc->tgt_y = npc->y;
      goto LABEL_5;
    case 0x15:
LABEL_5:
      v1 = npc->tgt_x;
      npc->x = v1 + (Random(-1, 1) << 9);
      v2 = npc->tgt_y;
      npc->y = v2 + (Random(-1, 1) << 9);
      if ( ++npc->act_wait > 30 )
        npc->act_no = 30;
      break;
    case 0x1E:
      npc->act_no = 31;
      npc->act_wait = 1;
      npc->xm = -2048;
      npc->x = npc->tgt_x;
      npc->y = npc->tgt_y;
      PlaySoundObject(44, 1);
      goto LABEL_8;
    case 0x1F:
LABEL_8:
      npc->xm += 32;
      npc->x += npc->xm;
      ++npc->act_wait;
      v3 = npc->tgt_y;
      npc->y = v3 + (Random(-1, 1) << 9);
      if ( npc->act_wait > 10 )
        npc->direct = 2;
      if ( npc->act_wait > 200 )
        npc->act_no = 40;
      break;
    case 0x28:
      npc->act_no = 41;
      npc->act_wait = 2;
      npc->direct = 0;
      npc->y -= 24576;
      npc->xm = -4096;
      goto LABEL_13;
    case 0x29:
LABEL_13:
      npc->x += npc->xm;
      npc->y += npc->ym;
      npc->act_wait += 2;
      if ( npc->act_wait > 1200 )
        npc->cond = 0;
      break;
    default:
      break;
  }
  if ( !(npc->act_wait & 3) && npc->act_no > 19 )
  {
    PlaySoundObject(34, 1);
    if ( npc->direct )
      SetCaret(npc->x - 5120, npc->y + 5120, 7, 0);
    else
      SetCaret(npc->x + 5120, npc->y + 5120, 7, 2);
  }
  rcLeft[0].left = 224;
  rcLeft[0].top = 64;
  rcLeft[0].right = 256;
  rcLeft[0].bottom = 80;
  rcLeft[1].left = 256;
  rcLeft[1].top = 64;
  rcLeft[1].right = 288;
  rcLeft[1].bottom = 96;
  rcRight[0].left = 224;
  rcRight[0].top = 80;
  rcRight[0].right = 256;
  rcRight[0].bottom = 96;
  rcRight[1].left = 288;
  rcRight[1].top = 64;
  rcRight[1].right = 320;
  rcRight[1].bottom = 96;
  if ( npc->direct )
  {
    v4 = npc;
    v5 = (RECT *)&(&v8)[4 * npc->ani_no - 1];
  }
  else
  {
    v4 = npc;
    v5 = (RECT *)(&v8 + 4 * npc->ani_no - 8);
  }
  npc->rect.left = v5->left;
  v4->rect.top = v5->top;
  v4->rect.right = v5->right;
  v4->rect.bottom = v5->bottom;
}

void ActNpc193(NPCHAR *npc)
{
  if ( !npc->act_no )
  {
    npc->act_no = 1;
    npc->y = npc->y;
    npc->x += 12288;
  }
  npc->rect.left = 256;
  npc->rect.top = 96;
  npc->rect.right = 320;
  npc->rect.bottom = 112;
}

void ActNpc194(NPCHAR *npc)
{
  if ( !npc->act_no )
  {
    npc->act_no = 1;
    npc->y += 2048;
  }
  npc->rect.left = 192;
  npc->rect.top = 120;
  npc->rect.right = 224;
  npc->rect.bottom = 128;
}

void ActNpc195(NPCHAR *npc)
{
  npc->rect.left = 112;
  npc->rect.top = 64;
  npc->rect.right = 128;
  npc->rect.bottom = 80;
}

void ActNpc196(NPCHAR *npc)
{
  npc->x -= 3072;
  if ( npc->x <= 155648 )
    npc->x += 180224;
  if ( npc->direct )
  {
    npc->rect.left = 112;
    npc->rect.top = 80;
    npc->rect.right = 144;
    npc->rect.bottom = 96;
  }
  else
  {
    npc->rect.left = 112;
    npc->rect.top = 64;
    npc->rect.right = 144;
    npc->rect.bottom = 80;
  }
}

void ActNpc197(NPCHAR *npc)
{
  int v1;
  RECT rc[4];
  RECT *v3;

  rc[0].left = 0;
  rc[0].top = 0;
  rc[0].right = 16;
  rc[0].bottom = 16;
  rc[1].left = 16;
  rc[1].top = 0;
  rc[1].right = 32;
  rc[1].bottom = 16;
  rc[2].left = 32;
  rc[2].top = 0;
  rc[2].right = 48;
  rc[2].bottom = 16;
  rc[3].left = 48;
  rc[3].top = 0;
  rc[3].right = 64;
  rc[3].bottom = 16;
  v1 = npc->act_no;
  if ( v1 == 10 )
  {
LABEL_5:
    if ( ++npc->ani_wait > 2 )
    {
      npc->ani_wait = 0;
      ++npc->ani_no;
    }
    if ( npc->ani_no > 1 )
      npc->ani_no = 0;
    if ( npc->xm < 0 )
    {
      npc->damage = 3;
      npc->act_no = 20;
    }
    goto LABEL_17;
  }
  if ( v1 != 20 )
  {
    if ( v1 )
      goto LABEL_17;
    npc->act_no = 10;
    npc->ani_wait = 0;
    npc->ym = Random(-512, 512);
    npc->xm = 2048;
    goto LABEL_5;
  }
  npc->damage = 3;
  if ( ++npc->ani_wait > 0 )
  {
    npc->ani_wait = 0;
    ++npc->ani_no;
  }
  if ( npc->ani_no > 3 )
    npc->ani_no = 2;
  if ( npc->x <= 24575 )
  {
    npc->destroy_voice = 0;
    LoseNpChar(npc, 1);
  }
LABEL_17:
  if ( npc->flag & 2 )
    npc->ym = 512;
  if ( npc->flag & 8 )
    npc->ym = -512;
  npc->xm -= 12;
  npc->x += npc->xm;
  npc->y += npc->ym;
  npc->rect = *(RECT *)&(&v3)[4 * npc->ani_no - 1];
}

void ActNpc198(NPCHAR *npc)
{
  int v1;
  RECT rcRight[3];
  RECT *v3;

  rcRight[0].left = 208;
  rcRight[0].top = 48;
  rcRight[0].right = 224;
  rcRight[0].bottom = 72;
  rcRight[1].left = 224;
  rcRight[1].top = 48;
  rcRight[1].right = 240;
  rcRight[1].bottom = 72;
  rcRight[2].left = 240;
  rcRight[2].top = 48;
  rcRight[2].right = 256;
  rcRight[2].bottom = 72;
  v1 = npc->act_no;
  if ( v1 )
  {
    if ( v1 == 1 )
      npc->xm += 32;
  }
  else if ( ++npc->act_wait > 20 )
  {
    npc->act_no = 1;
    npc->xm = 0;
    npc->ym = 0;
    npc->count1 = 0;
  }
  if ( ++npc->ani_wait > 0 )
  {
    npc->ani_wait = 0;
    ++npc->ani_no;
  }
  if ( npc->ani_no > 2 )
    npc->ani_no = 0;
  npc->x += npc->xm;
  npc->y += npc->ym;
  npc->rect = (RECT)*((_OWORD *)&v3 + npc->ani_no - 3);
  if ( ++npc->count1 > 100 )
    npc->cond = 0;
  if ( npc->count1 % 4 == 1 )
    PlaySoundObject(46, 1);
}
/* Orphan comments:
TODO: More WTF
*/

void ActNpc199(NPCHAR *npc)
{
  int v1;
  int v2;
  int v3;
  RECT rect[5];
  RECT *v5;

  qmemcpy(rect, &ActNpc199(NPCHAR *)::C.16, sizeof(rect));
  if ( !npc->act_no )
  {
    npc->act_no = 1;
    npc->ani_no = Random(0, 2);
    v1 = npc->direct;
    if ( v1 == 1 )
    {
      npc->ym = -1;
    }
    else if ( v1 > 1 )
    {
      if ( v1 == 2 )
      {
        npc->xm = 1;
      }
      else if ( v1 == 3 )
      {
        npc->ym = 1;
      }
    }
    else if ( !v1 )
    {
      npc->xm = -1;
    }
    v2 = npc->xm;
    npc->xm = (Random(4, 8) << 9) / 2 * v2;
    v3 = npc->ym;
    npc->ym = (Random(4, 8) << 9) / 2 * v3;
  }
  if ( ++npc->ani_wait > 6 )
  {
    npc->ani_wait = 0;
    ++npc->ani_no;
  }
  if ( npc->ani_no > 4 )
    npc->cond = 0;
  npc->x += npc->xm;
  npc->y += npc->ym;
  npc->rect = (RECT)*((_OWORD *)&v5 + npc->ani_no - 5);
}
