//#include "types.h"
#include "SDL_stdinc.h"
#include "windows_wrapper.h"
#include "Tags.h"
#include "forNpc.h"
#include "windows_wrapper.h"

void ActNpc300(NPCHAR *npc);
void ActNpc301(NPCHAR *npc);
void ActNpc302(NPCHAR *npc);
void ActNpc303(NPCHAR *npc);
void ActNpc304(NPCHAR *npc);
void ActNpc305(NPCHAR *npc);
void ActNpc306(NPCHAR *npc);
void ActNpc307(NPCHAR *npc);
void ActNpc308(NPCHAR *npc);
void ActNpc309(NPCHAR *npc);
void ActNpc310(NPCHAR *npc);
void ActNpc311(NPCHAR *npc);
void ActNpc312(NPCHAR *npc);
void ActNpc313(NPCHAR *npc);
void ActNpc314(NPCHAR *npc);
void ActNpc315(NPCHAR *npc);
void ActNpc316(NPCHAR *npc);
void ActNpc317(NPCHAR *npc);
void ActNpc318(NPCHAR *npc);
void ActNpc319(NPCHAR *npc);

RECT ActNpc313(NPCHAR *)::C.13[14] =
{
  { 128, 0, 144, 16 },
  { 144, 0, 160, 16 },
  { 160, 0, 176, 16 },
  { 176, 0, 192, 16 },
  { 192, 0, 208, 16 },
  { 208, 0, 224, 16 },
  { 224, 0, 240, 16 },
  { 240, 0, 256, 16 },
  { 256, 0, 272, 16 },
  { 272, 0, 288, 16 },
  { 288, 0, 304, 16 },
  { 128, 0, 144, 16 },
  { 176, 0, 192, 16 },
  { 304, 0, 320, 16 }
};
RECT ActNpc313(NPCHAR *)::C.14[14] =
{
  { 128, 16, 144, 32 },
  { 144, 16, 160, 32 },
  { 160, 16, 176, 32 },
  { 176, 16, 192, 32 },
  { 192, 16, 208, 32 },
  { 208, 16, 224, 32 },
  { 224, 16, 240, 32 },
  { 240, 16, 256, 32 },
  { 256, 16, 272, 32 },
  { 272, 16, 288, 32 },
  { 288, 16, 304, 32 },
  { 128, 16, 144, 32 },
  { 176, 16, 192, 32 },
  { 304, 16, 320, 32 }
};
RECT ActNpc312(NPCHAR *)::C.11[5] =
{
  { 0, 160, 16, 176 },
  { 16, 160, 32, 176 },
  { 32, 160, 48, 176 },
  { 48, 160, 64, 176 },
  { 64, 160, 80, 176 }
};
RECT ActNpc312(NPCHAR *)::C.12[5] =
{
  { 0, 176, 16, 192 },
  { 16, 176, 32, 192 },
  { 32, 176, 48, 192 },
  { 48, 176, 64, 192 },
  { 64, 176, 80, 192 }
};
RECT ActNpc311(NPCHAR *)::C.9[7] =
{
  { 0, 32, 24, 56 },
  { 24, 32, 48, 56 },
  { 48, 32, 72, 56 },
  { 72, 32, 96, 56 },
  { 96, 32, 120, 56 },
  { 120, 32, 144, 56 },
  { 144, 32, 168, 56 }
};
RECT ActNpc311(NPCHAR *)::C.10[7] =
{
  { 0, 56, 24, 80 },
  { 24, 56, 48, 80 },
  { 48, 56, 72, 80 },
  { 72, 56, 96, 80 },
  { 96, 56, 120, 80 },
  { 120, 56, 144, 80 },
  { 144, 56, 168, 80 }
};
RECT ActNpc310(NPCHAR *)::C.7[5] =
{
  { 32, 0, 56, 16 },
  { 56, 0, 80, 16 },
  { 80, 0, 104, 16 },
  { 104, 0, 128, 16 },
  { 128, 0, 152, 16 }
};
RECT ActNpc310(NPCHAR *)::C.8[5] =
{
  { 32, 16, 56, 32 },
  { 56, 16, 80, 32 },
  { 80, 16, 104, 32 },
  { 104, 16, 128, 32 },
  { 128, 16, 152, 32 }
};
RECT ActNpc301(NPCHAR *)::C.0[8] =
{
  { 144, 0, 160, 16 },
  { 160, 0, 176, 16 },
  { 176, 0, 192, 16 },
  { 192, 0, 208, 16 },
  { 144, 16, 160, 32 },
  { 160, 16, 176, 32 },
  { 176, 16, 192, 32 },
  { 192, 16, 208, 32 }
};

void ActNpc300(NPCHAR *npc)
{
  int v1;
  int v2;
  int v3;

  if ( !npc->act_no )
  {
    npc->act_no = 1;
    npc->y += 3072;
  }
  if ( ++npc->ani_wait % 8 == 1 )
  {
    v1 = npc->y + 4096;
    v2 = npc->x;
    v3 = Random(-8, 8);
    SetCaret(v2 + (v3 << 9), v1, 13, 1);
  }
  npc->rect.left = 192;
  npc->rect.top = 80;
  npc->rect.right = 208;
  npc->rect.bottom = 96;
}
/* Orphan comments:
TODO
*/

void ActNpc301(NPCHAR *npc)
{
  int v1;
  int v2;
  int v3;
  RECT rect[8];
  int dir;
  RECT *v6;

  qmemcpy(rect, ActNpc301(NPCHAR *)::C.0, sizeof(rect));
  v1 = npc->act_no;
  if ( v1 )
  {
    if ( v1 != 1 )
      goto LABEL_18;
  }
  else
  {
    npc->act_no = 1;
    npc->count1 = npc->direct;
  }
  npc->xm = 2 * GetCos(npc->count1);
  npc->ym = 2 * GetSin(npc->count1);
  npc->y += npc->ym;
  npc->x += npc->xm;
  dir = (unsigned __int8)GetArktan(npc->x - x, npc->y - y);
  if ( npc->count1 <= dir )
  {
    if ( dir - npc->count1 > 127 )
      v3 = npc->count1 - 1;
    else
      v3 = npc->count1 + 1;
    npc->count1 = v3;
  }
  else
  {
    if ( npc->count1 - dir > 127 )
      v2 = npc->count1 + 1;
    else
      v2 = npc->count1 - 1;
    npc->count1 = v2;
  }
  if ( npc->count1 > 255 )
    npc->count1 -= 256;
  if ( npc->count1 < 0 )
    npc->count1 += 256;
LABEL_18:
  if ( ++npc->ani_wait > 2 )
  {
    npc->ani_wait = 0;
    SetCaret(npc->x, npc->y, 7, 4);
  }
  npc->ani_no = (npc->count1 + 16) / 32;
  if ( npc->ani_no > 7 )
    npc->ani_no = 7;
  npc->rect = *(RECT *)(&(&v6)[4 * npc->ani_no - 2] - 1);
}

void ActNpc302(NPCHAR *npc)
{
  int v1;
  int v2;
  int n;

  v1 = npc->act_no;
  if ( v1 != 20 )
  {
    if ( v1 <= 20 )
    {
      if ( v1 )
      {
        if ( v1 == 10 )
        {
          npc->x = x;
          npc->y = y - 0x4000;
        }
      }
      return;
    }
    if ( v1 == 100 )
    {
      npc->act_no = 101;
      if ( npc->direct )
      {
        for ( n = 170; n <= 511; ++n )
        {
          if ( (gNPC[n].cond & 0x80u) != 0 && gNPC[n].code_event == npc->direct )
          {
            npc->pNpc = &gNPC[n];
            break;
          }
        }
        if ( n == 512 )
        {
          npc->cond = 0;
          return;
        }
      }
      else
      {
        npc->pNpc = gBoss;
      }
    }
    else if ( v1 != 101 )
    {
      if ( v1 == 30 )
      {
        npc->x = x;
        npc->y = y + 40960;
      }
      return;
    }
    npc->x = (x + npc->pNpc->x) / 2;
    npc->y = (y + npc->pNpc->y) / 2;
    return;
  }
  v2 = npc->direct;
  if ( v2 == 1 )
  {
    npc->y -= 1024;
  }
  else if ( v2 > 1 )
  {
    if ( v2 == 2 )
    {
      npc->x += 1024;
    }
    else if ( v2 == 3 )
    {
      npc->y += 1024;
    }
  }
  else if ( !v2 )
  {
    npc->x -= 1024;
  }
  x = npc->x;
  y = npc->y;
}

void ActNpc303(NPCHAR *npc)
{
  int v1;
  NPCHAR *v2;
  RECT *v3;
  RECT rcRight[2];
  RECT rcLeft[2];

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
    if ( npc->pNpc->ani_no == 3 || npc->pNpc->ani_no == 5 )
      npc->y -= 512;
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
}

void ActNpc304(NPCHAR *npc)
{
  RECT *v1;
  RECT rc[4];

  rc[0].left = 0;
  rc[0].top = 176;
  rc[0].right = 24;
  rc[0].bottom = 192;
  rc[1].left = 24;
  rc[1].top = 176;
  rc[1].right = 48;
  rc[1].bottom = 192;
  rc[2].left = 48;
  rc[2].top = 176;
  rc[2].right = 72;
  rc[2].bottom = 192;
  rc[3].left = 72;
  rc[3].top = 176;
  rc[3].right = 96;
  rc[3].bottom = 192;
  switch ( npc->act_no )
  {
    case 0:
      npc->act_no = 1;
      npc->y += 5120;
      goto LABEL_3;
    case 1:
LABEL_3:
      npc->ani_no = 0;
      break;
    case 0xA:
      npc->ani_no = 1;
      break;
    case 0x14:
      npc->act_no = 21;
      npc->ani_no = 2;
      goto LABEL_6;
    case 0x15:
LABEL_6:
      if ( ++npc->ani_wait > 10 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 3 )
        npc->ani_no = 2;
      break;
    default:
      break;
  }
  v1 = &rc[npc->ani_no];
  npc->rect.left = v1->left;
  npc->rect.top = v1->top;
  npc->rect.right = v1->right;
  npc->rect.bottom = v1->bottom;
}

void ActNpc305(NPCHAR *npc)
{
  int v1;
  NPCHAR *v2;
  RECT *v3;
  RECT rcRight[2];
  RECT rcLeft[2];
  RECT *v6;

  rcLeft[0].left = 160;
  rcLeft[0].top = 144;
  rcLeft[0].right = 176;
  rcLeft[0].bottom = 160;
  rcLeft[1].left = 176;
  rcLeft[1].top = 144;
  rcLeft[1].right = 192;
  rcLeft[1].bottom = 160;
  rcRight[0].left = 160;
  rcRight[0].top = 160;
  rcRight[0].right = 176;
  rcRight[0].bottom = 176;
  rcRight[1].left = 176;
  rcRight[1].top = 160;
  rcRight[1].right = 192;
  rcRight[1].bottom = 176;
  v1 = npc->act_no;
  if ( v1 )
  {
    if ( v1 != 1 )
      goto LABEL_9;
  }
  else
  {
    npc->act_no = 1;
    npc->y -= 0x2000;
    npc->ani_wait = Random(0, 6);
  }
  if ( ++npc->ani_wait > 6 )
  {
    npc->ani_wait = 0;
    ++npc->ani_no;
  }
  if ( npc->ani_no > 1 )
    npc->ani_no = 0;
LABEL_9:
  if ( npc->direct )
  {
    v2 = npc;
    v3 = (RECT *)&(&v6)[4 * npc->ani_no - 1];
  }
  else
  {
    v2 = npc;
    v3 = (RECT *)(&v6 + 4 * npc->ani_no - 8);
  }
  npc->rect.left = v3->left;
  v2->rect.top = v3->top;
  v2->rect.right = v3->right;
  v2->rect.bottom = v3->bottom;
}

void ActNpc306(NPCHAR *npc)
{
  int v1;
  NPCHAR *v2;
  RECT *v3;
  RECT rcRight[2];
  RECT rcLeft[2];
  RECT *v6;

  rcLeft[0].left = 240;
  rcLeft[0].top = 96;
  rcLeft[0].right = 280;
  rcLeft[0].bottom = 128;
  rcLeft[1].left = 280;
  rcLeft[1].top = 96;
  rcLeft[1].right = 320;
  rcLeft[1].bottom = 128;
  rcRight[0].left = 160;
  rcRight[0].top = 152;
  rcRight[0].right = 200;
  rcRight[0].bottom = 184;
  rcRight[1].left = 200;
  rcRight[1].top = 152;
  rcRight[1].right = 240;
  rcRight[1].bottom = 184;
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
    npc->y += 2048;
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
    v3 = (RECT *)&(&v6)[4 * npc->ani_no - 1];
  }
  else
  {
    v2 = npc;
    v3 = (RECT *)(&v6 + 4 * npc->ani_no - 8);
  }
  npc->rect.left = v3->left;
  v2->rect.top = v3->top;
  v2->rect.right = v3->right;
  v2->rect.bottom = v3->bottom;
}

void ActNpc307(NPCHAR *npc)
{
  int v1;
  NPCHAR *v2;
  RECT *v3;
  RECT rcRight[2];
  RECT rcLeft[2];
  RECT *v6;

  rcLeft[0].left = 0;
  rcLeft[0].top = 32;
  rcLeft[0].right = 16;
  rcLeft[0].bottom = 48;
  rcLeft[1].left = 16;
  rcLeft[1].top = 32;
  rcLeft[1].right = 32;
  rcLeft[1].bottom = 48;
  rcRight[0].left = 0;
  rcRight[0].top = 48;
  rcRight[0].right = 16;
  rcRight[0].bottom = 64;
  rcRight[1].left = 16;
  rcRight[1].top = 48;
  rcRight[1].right = 32;
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
    npc->x += 512;
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
    v3 = (RECT *)&(&v6)[4 * npc->ani_no - 1];
  }
  else
  {
    v2 = npc;
    v3 = (RECT *)(&v6 + 4 * npc->ani_no - 8);
  }
  npc->rect.left = v3->left;
  v2->rect.top = v3->top;
  v2->rect.right = v3->right;
  v2->rect.bottom = v3->bottom;
}

void ActNpc308(NPCHAR *npc)
{
  NPCHAR *v1;
  RECT *v2;
  RECT rcRight[2];
  RECT rcLeft[2];
  unsigned __int8 deg;
  RECT *v6;

  rcLeft[0].left = 128;
  rcLeft[0].top = 112;
  rcLeft[0].right = 144;
  rcLeft[0].bottom = 128;
  rcLeft[1].left = 144;
  rcLeft[1].top = 112;
  rcLeft[1].right = 160;
  rcLeft[1].bottom = 128;
  rcRight[0].left = 128;
  rcRight[0].top = 128;
  rcRight[0].right = 144;
  rcRight[0].bottom = 144;
  rcRight[1].left = 144;
  rcRight[1].top = 128;
  rcRight[1].right = 160;
  rcRight[1].bottom = 144;
  switch ( npc->act_no )
  {
    case 0:
      npc->act_no = 1;
      goto LABEL_3;
    case 1:
LABEL_3:
      if ( x < npc->x + 0x1E000 && x > npc->x - 0x1E000 && y < npc->y + 0x18000 && y > npc->y - 0x18000 )
        npc->act_no = 10;
      break;
    case 0xA:
      npc->act_no = 11;
      npc->act_wait = 0;
      npc->xm2 = 0;
      npc->ym2 = 0;
      if ( npc->x <= x )
        npc->direct = 2;
      else
        npc->direct = 0;
      goto LABEL_11;
    case 0xB:
LABEL_11:
      if ( ++npc->act_wait > 50 )
        npc->act_no = 20;
      ++npc->ani_wait;
      if ( npc->act_wait > 1 )
      {
        npc->ani_wait = 0;
        if ( ++npc->ani_no > 1 )
          npc->ani_no = 0;
      }
      if ( x > npc->x + 0x28000 || x < npc->x - 0x28000 || y > npc->y + 0x1E000 || y < npc->y - 0x1E000 )
        npc->act_no = 0;
      break;
    case 0x14:
      npc->act_no = 21;
      npc->act_wait = 0;
      deg = GetArktan(npc->x - x, npc->y - y);
      deg += Random(-3, 3);
      npc->ym2 = 2 * GetSin(deg);
      npc->xm2 = 2 * GetCos(deg);
      if ( npc->xm2 >= 0 )
        npc->direct = 2;
      else
        npc->direct = 0;
      goto LABEL_24;
    case 0x15:
LABEL_24:
      if ( npc->xm2 < 0 && npc->flag & 1 )
      {
        npc->direct = 2;
        npc->xm2 = -npc->xm2;
      }
      if ( npc->xm2 > 0 && npc->flag & 4 )
      {
        npc->direct = 0;
        npc->xm2 = -npc->xm2;
      }
      if ( npc->ym2 < 0 && npc->flag & 2 )
        npc->ym2 = -npc->ym2;
      if ( npc->ym2 > 0 && npc->flag & 8 )
        npc->ym2 = -npc->ym2;
      if ( npc->flag & 0x100 )
        npc->ym2 = -512;
      npc->x += npc->xm2;
      npc->y += npc->ym2;
      if ( ++npc->act_wait > 50 )
        npc->act_no = 10;
      if ( ++npc->ani_no > 1 )
        npc->ani_no = 0;
      break;
    default:
      break;
  }
  if ( npc->direct )
  {
    v1 = npc;
    v2 = (RECT *)(&(&v6)[4 * npc->ani_no - 1] - 1);
  }
  else
  {
    v1 = npc;
    v2 = (RECT *)(&v6 + 4 * npc->ani_no - 9);
  }
  npc->rect.left = v2->left;
  v1->rect.top = v2->top;
  v1->rect.right = v2->right;
  v1->rect.bottom = v2->bottom;
}

void ActNpc309(NPCHAR *npc)
{
  int v1;
  int v2;
  int v3;
  NPCHAR *v4;
  RECT *v5;
  RECT rcRight[2];
  RECT rcLeft[2];

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
    if ( npc->direct )
    {
      if ( x >= npc->x + 0x24000 || x <= npc->x + 0x22000 )
        return;
      npc->act_no = 10;
    }
    else
    {
      if ( x <= npc->x - 0x24000 || x >= npc->x - 0x22000 )
        return;
      npc->act_no = 10;
    }
    goto LABEL_50;
  }
  if ( v1 > 1 )
  {
    if ( v1 == 10 )
    {
      npc->act_no = 11;
      npc->bits |= 0x20u;
      npc->damage = 5;
    }
    else if ( v1 != 11 )
    {
      goto LABEL_50;
    }
    if ( npc->x <= x )
      npc->direct = 2;
    else
      npc->direct = 0;
    if ( npc->direct )
      v2 = npc->xm2 + 16;
    else
      v2 = npc->xm2 - 16;
    npc->xm2 = v2;
    if ( npc->y <= y )
      v3 = npc->ym2 + 16;
    else
      v3 = npc->ym2 - 16;
    npc->ym2 = v3;
    if ( npc->xm2 < 0 && npc->flag & 1 )
      npc->xm2 = -npc->xm2;
    if ( npc->xm2 > 0 && npc->flag & 4 )
      npc->xm2 = -npc->xm2;
    if ( npc->ym2 < 0 && npc->flag & 2 )
      npc->ym2 = -npc->ym2;
    if ( npc->ym2 > 0 && npc->flag & 8 )
      npc->ym2 = -npc->ym2;
    if ( npc->xm2 < -1535 )
      npc->xm2 = -1535;
    if ( npc->xm2 > 1535 )
      npc->xm2 = 1535;
    if ( npc->ym2 < -1535 )
      npc->ym2 = -1535;
    if ( npc->ym2 > 1535 )
      npc->ym2 = 1535;
    npc->x += npc->xm2;
    npc->y += npc->ym2;
    if ( ++npc->ani_wait > 1 )
    {
      npc->ani_wait = 0;
      ++npc->ani_no;
    }
    if ( npc->ani_no > 1 )
      npc->ani_no = 0;
    goto LABEL_50;
  }
  if ( !v1 )
  {
    npc->act_no = 1;
    goto LABEL_9;
  }
LABEL_50:
  if ( npc->direct )
  {
    v4 = npc;
    v5 = &rcRight[npc->ani_no];
  }
  else
  {
    v4 = npc;
    v5 = &rcLeft[npc->ani_no];
  }
  npc->rect.left = v5->left;
  v4->rect.top = v5->top;
  v4->rect.right = v5->right;
  v4->rect.bottom = v5->bottom;
  if ( npc->life <= 996 )
  {
    npc->code_char = 316;
    npc->act_no = 0;
  }
}

void ActNpc310(NPCHAR *npc)
{
  NPCHAR *v1;
  RECT *v2;
  RECT rcRight[5];
  RECT rcLeft[5];
  RECT *v5;

  qmemcpy(rcLeft, ActNpc310(NPCHAR *)::C.7, sizeof(rcLeft));
  qmemcpy(rcRight, ActNpc310(NPCHAR *)::C.8, sizeof(rcRight));
  switch ( npc->act_no )
  {
    case 0:
      npc->act_no = 1;
      npc->bits &= 0xFFDFu;
      npc->bits |= 4u;
      npc->damage = 0;
      goto LABEL_3;
    case 1:
LABEL_3:
      if ( npc->x <= x )
        npc->direct = 2;
      else
        npc->direct = 0;
      npc->ani_no = 0;
      if ( x > npc->x - 0x10000 && x < npc->x + 0x10000 && y > npc->y - 0x10000 && y < npc->y + 0x2000 )
        npc->act_no = 10;
      break;
    case 0xA:
      npc->xm = 0;
      npc->act_no = 11;
      npc->act_wait = 0;
      npc->bits &= 0xFFDFu;
      npc->bits |= 4u;
      npc->damage = 0;
      npc->ani_no = 0;
      goto LABEL_12;
    case 0xB:
LABEL_12:
      if ( ++npc->act_wait > 30 )
        npc->act_no = 20;
      break;
    case 0x14:
      npc->act_no = 21;
      npc->act_wait = 0;
      npc->bits &= 0xFFFBu;
      npc->bits |= 0x20u;
      npc->damage = 0;
      if ( npc->x <= x )
        npc->direct = 2;
      else
        npc->direct = 0;
      goto LABEL_17;
    case 0x15:
LABEL_17:
      if ( npc->direct )
        npc->xm = 1024;
      else
        npc->xm = -1024;
      if ( ++npc->ani_wait > 3 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 1 )
        npc->ani_no = 0;
      if ( ++npc->act_wait > 50 )
        npc->act_no = 10;
      if ( npc->x < x + 20480 && npc->x > x - 20480 )
      {
        npc->ym = -768;
        npc->xm /= 2;
        npc->ani_no = 2;
        npc->act_no = 30;
        PlaySoundObject(30, 1);
      }
      break;
    case 0x1E:
      if ( npc->ym >= -127 )
      {
        npc->act_no = 31;
        npc->ani_wait = 0;
        npc->ani_no = 3;
        npc->damage = 9;
      }
      break;
    case 0x1F:
      if ( ++npc->ani_wait > 2 )
      {
        npc->ani_wait = 0;
        npc->ani_no = 4;
      }
      if ( npc->flag & 8 )
      {
        npc->act_no = 32;
        npc->act_wait = 0;
        npc->xm = 0;
        npc->damage = 3;
      }
      break;
    case 0x20:
      if ( ++npc->act_wait > 30 )
      {
        npc->act_no = 10;
        npc->damage = 0;
      }
      break;
    default:
      break;
  }
  npc->ym += 32;
  npc->x += npc->xm;
  npc->y += npc->ym;
  if ( npc->direct )
  {
    v1 = npc;
    v2 = (RECT *)(&v5 + 4 * npc->ani_no - 40);
  }
  else
  {
    v1 = npc;
    v2 = (RECT *)(&v5 + 4 * npc->ani_no - 20);
  }
  npc->rect.left = v2->left;
  v1->rect.top = v2->top;
  v1->rect.right = v2->right;
  v1->rect.bottom = v2->bottom;
  if ( npc->life <= 996 )
  {
    npc->code_char = 316;
    npc->act_no = 0;
  }
}

void ActNpc311(NPCHAR *npc)
{
  NPCHAR *v1;
  RECT *v2;
  RECT rcRight[7];
  RECT rcLeft[7];
  RECT *v5;

  qmemcpy(rcLeft, ActNpc311(NPCHAR *)::C.9, sizeof(rcLeft));
  qmemcpy(rcRight, ActNpc311(NPCHAR *)::C.10, sizeof(rcRight));
  switch ( npc->act_no )
  {
    case 0:
      npc->act_no = 1;
      goto LABEL_3;
    case 1:
LABEL_3:
      if ( npc->direct )
      {
        if ( x > npc->x && x < npc->x + 0x28000 && y > npc->y - 0x14000 && y < npc->y + 0x14000 )
          npc->act_no = 10;
      }
      else if ( x > npc->x - 0x28000 && x < npc->x && y > npc->y - 0x14000 && y < npc->y + 0x14000 )
      {
        npc->act_no = 10;
      }
      break;
    case 0xA:
      npc->act_no = 11;
      goto LABEL_15;
    case 0xB:
LABEL_15:
      if ( npc->x <= x )
        npc->direct = 2;
      else
        npc->direct = 0;
      if ( x <= npc->x - 0x1C000 || x >= npc->x + 0x1C000 || y <= npc->y - 0x1000 )
      {
        npc->ani_no = 4;
        npc->count1 = 1;
      }
      else
      {
        npc->ani_no = 1;
        npc->count1 = 0;
      }
      if ( ++npc->act_wait > 10 )
        npc->act_no = 20;
      break;
    case 0x14:
      npc->act_no = 21;
      npc->act_wait = 0;
      goto LABEL_26;
    case 0x15:
LABEL_26:
      if ( npc->count1 )
      {
        if ( ++npc->ani_no > 5 )
          npc->ani_no = 4;
      }
      else if ( ++npc->ani_no > 2 )
      {
        npc->ani_no = 1;
      }
      if ( ++npc->act_wait > 30 )
        npc->act_no = 30;
      break;
    case 0x1E:
      npc->act_no = 31;
      npc->act_wait = 0;
      if ( npc->count1 )
      {
        if ( npc->direct )
          SetNpChar(312, npc->x, npc->y, 1536, -1536, 2, 0, 256);
        else
          SetNpChar(312, npc->x, npc->y, -1536, -1536, 0, 0, 256);
        npc->ani_no = 6;
      }
      else
      {
        if ( npc->direct )
          SetNpChar(312, npc->x, npc->y, 1536, 0, 2, 0, 256);
        else
          SetNpChar(312, npc->x, npc->y, -1536, 0, 0, 0, 256);
        npc->ani_no = 3;
      }
      goto LABEL_42;
    case 0x1F:
LABEL_42:
      if ( ++npc->act_wait > 30 )
      {
        npc->act_no = 40;
        npc->act_wait = Random(0, 100);
      }
      break;
    case 0x28:
      npc->ani_no = 0;
      if ( ++npc->act_wait > 150 )
        npc->act_no = 10;
      if ( x < npc->x - 0x2C000 || x > npc->x + 0x2C000 || y < npc->y - 0x1E000 || y > npc->y + 0x1E000 )
      {
        npc->act_no = 40;
        npc->act_wait = 0;
      }
      break;
    default:
      break;
  }
  if ( npc->direct )
  {
    v1 = npc;
    v2 = (RECT *)(&v5 + 4 * npc->ani_no - 56);
  }
  else
  {
    v1 = npc;
    v2 = (RECT *)(&v5 + 4 * npc->ani_no - 28);
  }
  npc->rect.left = v2->left;
  v1->rect.top = v2->top;
  v1->rect.right = v2->right;
  v1->rect.bottom = v2->bottom;
  if ( npc->life <= 992 )
  {
    npc->code_char = 316;
    npc->act_no = 0;
  }
}

void ActNpc312(NPCHAR *npc)
{
  NPCHAR *v1;
  RECT *v2;
  RECT rcRight[5];
  RECT rcLeft[5];
  RECT *v5;

  qmemcpy(rcLeft, ActNpc312(NPCHAR *)::C.11, sizeof(rcLeft));
  qmemcpy(rcRight, ActNpc312(NPCHAR *)::C.12, sizeof(rcRight));
  if ( npc->act_no > 0 && npc->act_no <= 19 && npc->flag & 0xFF )
    npc->act_no = 20;
  switch ( npc->act_no )
  {
    case 0:
      npc->act_no = 1;
      npc->act_wait = 0;
      if ( npc->xm >= 0 )
        npc->direct = 2;
      else
        npc->direct = 0;
      if ( npc->ym >= 0 )
        npc->ani_no = 2;
      else
        npc->ani_no = 0;
      goto LABEL_12;
    case 1:
LABEL_12:
      if ( ++npc->act_wait == 4 )
        npc->bits &= 0xFFF7u;
      if ( npc->act_wait > 10 )
        npc->act_no = 10;
      goto LABEL_27;
    case 0xA:
      npc->act_no = 11;
      npc->ani_wait = 0;
      npc->xm = 3 * npc->xm / 4;
      npc->ym = 3 * npc->ym / 4;
      goto LABEL_17;
    case 0xB:
LABEL_17:
      npc->ym += 32;
      if ( ++npc->ani_wait > 10 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 4 )
        npc->ani_no = 4;
      goto LABEL_27;
    case 0x14:
      npc->act_no = 21;
      npc->act_wait = 0;
      npc->xm = 0;
      npc->ym = 0;
      npc->damage = 0;
      goto LABEL_22;
    case 0x15:
LABEL_22:
      if ( ++npc->act_wait > 30 )
        npc->act_no = 30;
      goto LABEL_27;
    case 0x1E:
      npc->act_no = 31;
      npc->act_wait = 0;
      goto LABEL_25;
    case 0x1F:
LABEL_25:
      if ( ++npc->act_wait <= 30 )
        goto LABEL_27;
      npc->cond = 0;
      break;
    default:
LABEL_27:
      if ( npc->ym > 1535 )
        npc->ym = 1535;
      npc->x += npc->xm;
      npc->y += npc->ym;
      if ( npc->direct )
      {
        v1 = npc;
        v2 = (RECT *)(&v5 + 4 * npc->ani_no - 40);
      }
      else
      {
        v1 = npc;
        v2 = (RECT *)(&v5 + 4 * npc->ani_no - 20);
      }
      npc->rect.left = v2->left;
      v1->rect.top = v2->top;
      v1->rect.right = v2->right;
      v1->rect.bottom = v2->bottom;
      if ( npc->act_no == 31 )
      {
        if ( npc->act_wait / 2 & 1 )
        {
          npc->rect.left = 0;
          npc->rect.right = 0;
        }
      }
      break;
  }
}

void ActNpc313(NPCHAR *npc)
{
  int v1;
  int v2;
  int v3;
  int v4;
  unsigned __int16 v5;
  NPCHAR *v6;
  RECT *v7;
  RECT rcRight[14];
  RECT rcLeft[14];
  RECT *v10;

  qmemcpy(rcLeft, ActNpc313(NPCHAR *)::C.13, sizeof(rcLeft));
  qmemcpy(rcRight, ActNpc313(NPCHAR *)::C.14, sizeof(rcRight));
  v1 = npc->act_no;
  if ( v1 == 210 )
  {
    if ( ++npc->ani_no > 7 )
      npc->ani_no = 6;
    if ( npc->xm < 0 && npc->flag & 1 )
      npc->act_no = 220;
    if ( npc->xm > 0 && npc->flag & 4 )
      npc->act_no = 220;
    goto LABEL_127;
  }
  if ( v1 > 210 )
  {
    if ( v1 == 310 )
    {
      npc->ani_no = 2;
      if ( ++npc->act_wait > 4 )
      {
        npc->act_no = 320;
        npc->ani_no = 12;
        npc->ym = -2048;
        PlaySoundObject(25, 1);
        npc->bits |= 8u;
        npc->bits &= 0xFFDFu;
        npc->bits |= 4u;
        npc->damage = 10;
      }
      goto LABEL_127;
    }
    if ( v1 > 310 )
    {
      if ( v1 != 331 )
      {
        if ( v1 > 331 )
        {
          if ( v1 == 500 )
          {
            npc->bits &= 0xFFDFu;
            npc->act_no = 501;
            npc->act_wait = 0;
            npc->ani_no = 8;
            npc->tgt_x = npc->x;
            npc->damage = 0;
            DeleteNpCharCode(315, 1);
          }
          else if ( v1 != 501 )
          {
            goto LABEL_127;
          }
          npc->ym += 32;
          ++npc->act_wait;
          if ( npc->act_wait & 1 )
            v4 = npc->tgt_x;
          else
            v4 = npc->tgt_x + 512;
          npc->x = v4;
          goto LABEL_127;
        }
        if ( v1 == 320 )
        {
          if ( ++npc->ani_no > 13 )
            npc->ani_no = 12;
          if ( npc->y <= 0x1FFF )
            npc->act_no = 330;
          goto LABEL_127;
        }
        if ( v1 != 330 )
          goto LABEL_127;
        npc->ym = 0;
        npc->act_no = 331;
        npc->act_wait = 0;
        SetQuake(16);
        PlaySoundObject(26, 1);
      }
      if ( ++npc->ani_no > 13 )
        npc->ani_no = 12;
      if ( !(++npc->act_wait % 6) )
      {
        v3 = Random(4, 16);
        SetNpChar(315, v3 << 13, 0, 0, 0, 0, 0, 256);
      }
      if ( npc->act_wait > 30 )
      {
        npc->count1 = 0;
        npc->act_no = 130;
        npc->bits |= 0x20u;
        npc->bits &= 0xFFFBu;
        npc->damage = 3;
      }
      goto LABEL_127;
    }
    if ( v1 != 221 )
    {
      if ( v1 > 221 )
      {
        if ( v1 == 300 )
        {
          npc->act_no = 301;
          npc->ani_no = 9;
          if ( npc->x <= x )
            npc->direct = 2;
          else
            npc->direct = 0;
        }
        else if ( v1 != 301 )
        {
          goto LABEL_127;
        }
        if ( ++npc->ani_no > 11 )
          npc->ani_no = 9;
        if ( npc->direct )
          npc->xm = 1024;
        else
          npc->xm = -1024;
        if ( x > npc->x - 2048 && x < npc->x + 2048 )
        {
          npc->act_no = 310;
          npc->act_wait = 0;
          npc->ani_no = 2;
          npc->xm = 0;
        }
        goto LABEL_127;
      }
      if ( v1 != 220 )
        goto LABEL_127;
      npc->act_no = 221;
      npc->act_wait = 0;
      SetQuake(16);
      PlaySoundObject(26, 1);
      npc->damage = 4;
    }
    if ( ++npc->ani_no > 7 )
      npc->ani_no = 6;
    if ( !(++npc->act_wait % 6) )
    {
      v2 = Random(4, 16);
      SetNpChar(314, v2 << 13, 0x2000, 0, 0, 0, 0, 256);
    }
    if ( npc->act_wait > 30 )
    {
      npc->count1 = 0;
      npc->act_no = 130;
      npc->bits |= 0x20u;
      npc->bits &= 0xFFFBu;
      npc->damage = 3;
    }
    goto LABEL_127;
  }
  if ( v1 == 110 )
  {
LABEL_47:
    npc->damage = 1;
    if ( npc->x <= x )
      npc->direct = 2;
    else
      npc->direct = 0;
    npc->ani_no = 0;
    if ( ++npc->act_wait > 4 )
    {
      npc->act_wait = 0;
      npc->act_no = 120;
      if ( ++npc->count2 > 12 )
      {
        npc->count2 = 0;
        npc->act_no = 300;
      }
    }
    goto LABEL_127;
  }
  if ( v1 > 110 )
  {
    if ( v1 == 130 )
    {
      npc->ym += 128;
      if ( npc->y > 0x10000 )
        npc->bits &= 0xFFF7u;
      if ( npc->xm < 0 && npc->flag & 1 )
        npc->xm = -npc->xm;
      if ( npc->xm > 0 && npc->flag & 4 )
        npc->xm = -npc->xm;
      if ( npc->x <= x )
        npc->direct = 2;
      else
        npc->direct = 0;
      if ( npc->ym >= -512 )
      {
        if ( npc->ym <= 512 )
          npc->ani_no = 0;
        else
          npc->ani_no = 4;
      }
      else
      {
        npc->ani_no = 3;
      }
      if ( npc->flag & 8 )
      {
        npc->act_no = 140;
        npc->act_wait = 0;
        npc->ani_no = 2;
        npc->xm = 0;
      }
      if ( npc->count1 > 4 && y < npc->y + 2048 )
      {
        npc->act_no = 200;
        npc->act_wait = 0;
        npc->xm = 0;
        npc->ym = 0;
      }
    }
    else if ( v1 > 130 )
    {
      if ( v1 == 140 )
      {
        npc->ani_no = 2;
        if ( ++npc->act_wait > 4 )
          npc->act_no = 110;
      }
      else if ( v1 == 200 )
      {
        npc->ani_no = 5;
        if ( ++npc->act_wait > 10 )
        {
          npc->act_no = 210;
          npc->ani_no = 6;
          if ( npc->direct )
            npc->xm = 1535;
          else
            npc->xm = -1535;
          PlaySoundObject(25, 1);
          npc->bits &= 0xFFDFu;
          npc->bits |= 4u;
          npc->damage = 10;
        }
      }
    }
    else if ( v1 == 120 )
    {
      npc->ani_no = 2;
      if ( ++npc->act_wait > 4 )
      {
        npc->act_no = 130;
        npc->ani_no = 3;
        npc->xm = 2 * Random(-512, 512);
        npc->ym = -2048;
        PlaySoundObject(30, 1);
        ++npc->count1;
      }
    }
  }
  else
  {
    if ( v1 == 1 )
    {
LABEL_37:
      npc->ym += 64;
      if ( Random(0, 120) == 10 )
      {
        npc->act_no = 2;
        npc->act_wait = 0;
        npc->ani_no = 1;
      }
      if ( npc->x - 0x4000 < x && npc->x + 0x4000 > x )
      {
        if ( npc->x <= x )
          npc->direct = 2;
        else
          npc->direct = 0;
      }
      goto LABEL_127;
    }
    if ( v1 <= 1 )
    {
      if ( v1 )
        goto LABEL_127;
      npc->act_no = 1;
      npc->ani_no = 0;
      npc->ani_wait = 0;
      npc->y += 2048;
      goto LABEL_37;
    }
    if ( v1 != 2 )
    {
      if ( v1 != 100 )
        goto LABEL_127;
      npc->act_no = 110;
      npc->act_wait = 0;
      npc->count1 = 0;
      npc->bits |= 0x20u;
      goto LABEL_47;
    }
    if ( ++npc->act_wait > 8 )
    {
      npc->act_no = 1;
      npc->ani_no = 0;
    }
  }
LABEL_127:
  if ( npc->act_no > 100 && npc->act_no <= 499 && npc->act_no != 210 && npc->act_no != 320 )
  {
    if ( (unsigned __int8)IsActiveSomeBullet() )
    {
      npc->bits &= 0xFFDFu;
      v5 = npc->bits | 4;
    }
    else
    {
      npc->bits |= 0x20u;
      v5 = npc->bits & 0xFFFB;
    }
    npc->bits = v5;
  }
  if ( npc->ym > 1535 )
    npc->ym = 1535;
  npc->x += npc->xm;
  npc->y += npc->ym;
  if ( npc->direct )
  {
    v6 = npc;
    v7 = (RECT *)&(&v10)[4 * npc->ani_no - 7];
  }
  else
  {
    v6 = npc;
    v7 = (RECT *)(&v10 + 4 * npc->ani_no - 56);
  }
  npc->rect.left = v7->left;
  v6->rect.top = v7->top;
  v6->rect.right = v7->right;
  v6->rect.bottom = v7->bottom;
}

void ActNpc314(NPCHAR *npc)
{
  int v1;
  int v2;
  int v3;
  int v4;
  int v5;
  int v6;
  RECT rc[3];
  int i;
  RECT *v9;

  rc[0].left = 64;
  rc[0].top = 64;
  rc[0].right = 80;
  rc[0].bottom = 80;
  rc[1].left = 80;
  rc[1].top = 64;
  rc[1].right = 96;
  rc[1].bottom = 80;
  rc[2].left = 96;
  rc[2].top = 64;
  rc[2].right = 112;
  rc[2].bottom = 80;
  v1 = npc->act_no;
  switch ( v1 )
  {
    case 100:
      goto LABEL_5;
    case 110:
      npc->ym += 64;
      if ( npc->y > (gMap.length + 2) << 13 )
      {
        npc->cond = 0;
        return;
      }
      break;
    case 0:
      npc->count2 = 0;
      npc->act_no = 100;
      npc->bits |= 4u;
      npc->ani_no = Random(0, 2);
LABEL_5:
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
        PlaySoundObject(12, 1);
        SetQuake(10);
        for ( i = 0; i <= 1; ++i )
        {
          v2 = Random(-1536, 0);
          v3 = Random(-341, 341);
          v4 = npc->y + 0x2000;
          v5 = npc->x;
          v6 = Random(-12, 12);
          SetNpChar(4, v5 + (v6 << 9), v4, v3, v2, 0, 0, 256);
        }
      }
      break;
  }
  if ( ++npc->ani_wait > 6 )
  {
    ++npc->ani_wait;
    ++npc->ani_no;
  }
  if ( npc->ani_no > 2 )
    npc->ani_no = 0;
  if ( y <= npc->y )
    npc->damage = 0;
  else
    npc->damage = 10;
  npc->y += npc->ym;
  npc->rect = *(RECT *)(&v9 + 4 * npc->ani_no - 13);
}

void ActNpc315(NPCHAR *npc)
{
  int v1;
  unsigned __int16 v2;
  NPCHAR *v3;
  RECT *v4;
  RECT rcRight[4];
  RECT rcLeft[4];
  RECT *v7;

  rcLeft[0].left = 128;
  rcLeft[0].top = 0;
  rcLeft[0].right = 144;
  rcLeft[0].bottom = 16;
  rcLeft[1].left = 160;
  rcLeft[1].top = 0;
  rcLeft[1].right = 176;
  rcLeft[1].bottom = 16;
  rcLeft[2].left = 176;
  rcLeft[2].top = 0;
  rcLeft[2].right = 192;
  rcLeft[2].bottom = 16;
  rcLeft[3].left = 192;
  rcLeft[3].top = 0;
  rcLeft[3].right = 208;
  rcLeft[3].bottom = 16;
  rcRight[0].left = 128;
  rcRight[0].top = 16;
  rcRight[0].right = 144;
  rcRight[0].bottom = 32;
  rcRight[1].left = 160;
  rcRight[1].top = 16;
  rcRight[1].right = 176;
  rcRight[1].bottom = 32;
  rcRight[2].left = 176;
  rcRight[2].top = 16;
  rcRight[2].right = 192;
  rcRight[2].bottom = 32;
  rcRight[3].left = 192;
  rcRight[3].top = 16;
  rcRight[3].right = 208;
  rcRight[3].bottom = 32;
  v1 = npc->act_no;
  if ( v1 == 110 )
  {
LABEL_13:
    if ( npc->x <= x )
      npc->direct = 2;
    else
      npc->direct = 0;
    npc->ani_no = 0;
    if ( ++npc->act_wait > 4 )
    {
      npc->act_wait = 0;
      npc->act_no = 120;
    }
    goto LABEL_38;
  }
  if ( v1 > 110 )
  {
    switch ( v1 )
    {
      case 130:
        npc->ym += 128;
        if ( npc->xm < 0 && npc->flag & 1 )
          npc->xm = -npc->xm;
        if ( npc->xm > 0 && npc->flag & 4 )
          npc->xm = -npc->xm;
        if ( npc->x <= x )
          npc->direct = 2;
        else
          npc->direct = 0;
        if ( npc->ym >= -512 )
        {
          if ( npc->ym <= 512 )
            npc->ani_no = 3;
          else
            npc->ani_no = 0;
        }
        else
        {
          npc->ani_no = 2;
        }
        if ( npc->flag & 8 )
        {
          npc->act_no = 140;
          npc->act_wait = 0;
          npc->ani_no = 1;
          npc->xm = 0;
        }
        break;
      case 140:
        npc->ani_no = 1;
        if ( ++npc->act_wait > 4 )
        {
          npc->act_no = 110;
          npc->bits |= 0x20u;
        }
        break;
      case 120:
        npc->ani_no = 1;
        if ( ++npc->act_wait > 4 )
        {
          npc->act_no = 130;
          npc->ani_no = 3;
          npc->xm = 2 * Random(-512, 512);
          npc->ym = -2048;
          PlaySoundObject(30, 1);
        }
        break;
    }
  }
  else
  {
    if ( v1 )
    {
      if ( v1 != 100 )
        goto LABEL_38;
      npc->act_no = 110;
      npc->act_wait = 0;
      npc->count1 = 0;
      npc->bits |= 0x20u;
      goto LABEL_13;
    }
    npc->ani_no = 3;
    npc->ym += 128;
    if ( npc->y > 0x10000 )
    {
      npc->act_no = 130;
      npc->bits &= 0xFFF7u;
    }
  }
LABEL_38:
  if ( npc->act_no > 100 )
  {
    if ( (unsigned __int8)IsActiveSomeBullet() )
    {
      npc->bits &= 0xFFDFu;
      v2 = npc->bits | 4;
    }
    else
    {
      npc->bits |= 0x20u;
      v2 = npc->bits & 0xFFFB;
    }
    npc->bits = v2;
  }
  if ( ++npc->count2 <= 300 )
  {
    if ( npc->ym > 1535 )
      npc->ym = 1535;
    npc->x += npc->xm;
    npc->y += npc->ym;
    if ( npc->direct )
    {
      v3 = npc;
      v4 = (RECT *)&(&v7)[4 * npc->ani_no - 2];
    }
    else
    {
      v3 = npc;
      v4 = (RECT *)&(&v7)[4 * npc->ani_no - 1];
    }
    npc->rect.left = v4->left;
    v3->rect.top = v4->top;
    v3->rect.right = v4->right;
    v3->rect.bottom = v4->bottom;
  }
  else
  {
    VanishNpChar(npc);
  }
}

void ActNpc316(NPCHAR *npc)
{
  int v1;
  NPCHAR *v2;
  RECT *v3;
  RECT rcRight[3];
  RECT rcLeft[3];
  RECT *v6;

  rcLeft[0].left = 248;
  rcLeft[0].top = 32;
  rcLeft[0].right = 272;
  rcLeft[0].bottom = 56;
  rcLeft[1].left = 272;
  rcLeft[1].top = 32;
  rcLeft[1].right = 296;
  rcLeft[1].bottom = 56;
  rcLeft[2].left = 296;
  rcLeft[2].top = 32;
  rcLeft[2].right = 320;
  rcLeft[2].bottom = 56;
  rcRight[0].left = 248;
  rcRight[0].top = 56;
  rcRight[0].right = 272;
  rcRight[0].bottom = 80;
  rcRight[1].left = 272;
  rcRight[1].top = 56;
  rcRight[1].right = 296;
  rcRight[1].bottom = 80;
  rcRight[2].left = 296;
  rcRight[2].top = 56;
  rcRight[2].right = 320;
  rcRight[2].bottom = 80;
  v1 = npc->act_no;
  switch ( v1 )
  {
    case 1:
      if ( npc->flag & 8 )
      {
        npc->ani_no = 1;
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
      if ( npc->ani_no > 2 )
        npc->ani_no = 1;
      if ( ++npc->act_wait > 50 )
        npc->cond |= 8u;
      break;
    case 0:
      npc->bits &= 0xFFDFu;
      npc->bits &= 0xFFF7u;
      npc->damage = 0;
      npc->act_no = 1;
      npc->ani_no = 0;
      npc->view.front = 6144;
      npc->view.back = 6144;
      npc->view.top = 6144;
      npc->ym = -512;
      if ( npc->direct )
        npc->xm = -256;
      else
        npc->xm = 256;
      PlaySoundObject(50, 1);
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
    v3 = (RECT *)(&v6 + 4 * npc->ani_no - 24);
  }
  else
  {
    v2 = npc;
    v3 = (RECT *)(&v6 + 4 * npc->ani_no - 12);
  }
  npc->rect.left = v3->left;
  v2->rect.top = v3->top;
  v2->rect.right = v3->right;
  v2->rect.bottom = v3->bottom;
}

void ActNpc317(NPCHAR *npc)
{
  NPCHAR *v1;
  RECT *v2;
  RECT rcRight[4];
  RECT rcLeft[4];
  RECT *v5;

  rcLeft[0].left = 0;
  rcLeft[0].top = 80;
  rcLeft[0].right = 32;
  rcLeft[0].bottom = 120;
  rcLeft[1].left = 32;
  rcLeft[1].top = 80;
  rcLeft[1].right = 64;
  rcLeft[1].bottom = 120;
  rcLeft[2].left = 64;
  rcLeft[2].top = 80;
  rcLeft[2].right = 96;
  rcLeft[2].bottom = 120;
  rcLeft[3].left = 96;
  rcLeft[3].top = 80;
  rcLeft[3].right = 128;
  rcLeft[3].bottom = 120;
  rcRight[0].left = 0;
  rcRight[0].top = 120;
  rcRight[0].right = 32;
  rcRight[0].bottom = 160;
  rcRight[1].left = 32;
  rcRight[1].top = 120;
  rcRight[1].right = 64;
  rcRight[1].bottom = 160;
  rcRight[2].left = 64;
  rcRight[2].top = 120;
  rcRight[2].right = 96;
  rcRight[2].bottom = 160;
  rcRight[3].left = 96;
  rcRight[3].top = 120;
  rcRight[3].right = 128;
  rcRight[3].bottom = 160;
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
      npc->count1 = 0;
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
      if ( x > npc->x - 163840 && x < npc->x + 163840 && y > npc->y - 81920 && y < npc->y + 81920 && ++npc->count1 > 50 )
        npc->act_no = 10;
      break;
    case 0xA:
      npc->act_no = 11;
      npc->act_wait = 0;
      npc->ani_no = 2;
      SetNpChar(319, npc->x, npc->y, 0, 0, 0, npc, 256);
      goto LABEL_18;
    case 0xB:
LABEL_18:
      if ( ++npc->act_wait > 50 )
      {
        npc->act_wait = 0;
        npc->act_no = 12;
        npc->ani_no = 3;
        PlaySoundObject(39, 1);
      }
      break;
    case 0xC:
      if ( ++npc->act_wait > 20 )
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
    v2 = (RECT *)&(&v5)[4 * npc->ani_no - 2];
  }
  else
  {
    v1 = npc;
    v2 = (RECT *)&(&v5)[4 * npc->ani_no - 1];
  }
  npc->rect.left = v2->left;
  v1->rect.top = v2->top;
  v1->rect.right = v2->right;
  v1->rect.bottom = v2->bottom;
  if ( npc->life <= 936 )
  {
    npc->code_char = 318;
    npc->act_no = 0;
  }
}

void ActNpc318(NPCHAR *npc)
{
  int v1;
  NPCHAR *v2;
  RECT *v3;
  RECT rcRight[3];
  RECT rcLeft[3];
  RECT *v6;

  rcLeft[0].left = 224;
  rcLeft[0].top = 80;
  rcLeft[0].right = 256;
  rcLeft[0].bottom = 120;
  rcLeft[1].left = 256;
  rcLeft[1].top = 80;
  rcLeft[1].right = 288;
  rcLeft[1].bottom = 120;
  rcLeft[2].left = 288;
  rcLeft[2].top = 80;
  rcLeft[2].right = 320;
  rcLeft[2].bottom = 120;
  rcRight[0].left = 224;
  rcRight[0].top = 120;
  rcRight[0].right = 256;
  rcRight[0].bottom = 160;
  rcRight[1].left = 256;
  rcRight[1].top = 120;
  rcRight[1].right = 288;
  rcRight[1].bottom = 160;
  rcRight[2].left = 288;
  rcRight[2].top = 120;
  rcRight[2].right = 320;
  rcRight[2].bottom = 160;
  v1 = npc->act_no;
  switch ( v1 )
  {
    case 1:
      if ( npc->flag & 8 )
      {
        npc->ani_no = 1;
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
      if ( npc->ani_no > 2 )
        npc->ani_no = 1;
      if ( ++npc->act_wait > 50 )
        npc->cond |= 8u;
      break;
    case 0:
      npc->bits &= 0xFFDFu;
      npc->bits &= 0xFFF7u;
      npc->bits &= 0xFFFEu;
      npc->damage = 0;
      npc->act_no = 1;
      npc->ani_no = 0;
      npc->ym = -512;
      if ( npc->direct )
        npc->xm = -64;
      else
        npc->xm = 64;
      PlaySoundObject(54, 1);
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
    v3 = (RECT *)(&v6 + 4 * npc->ani_no - 24);
  }
  else
  {
    v2 = npc;
    v3 = (RECT *)(&v6 + 4 * npc->ani_no - 12);
  }
  npc->rect.left = v3->left;
  v2->rect.top = v3->top;
  v2->rect.right = v3->right;
  v2->rect.bottom = v3->bottom;
}

void ActNpc319(NPCHAR *npc)
{
  int v1;
  int v2;
  RECT rc[3];
  RECT *v4;

  rc[0].left = 16;
  rc[0].top = 0;
  rc[0].right = 32;
  rc[0].bottom = 16;
  rc[1].left = 16;
  rc[1].top = 0;
  rc[1].right = 32;
  rc[1].bottom = 16;
  rc[2].left = 96;
  rc[2].top = 80;
  rc[2].right = 112;
  rc[2].bottom = 96;
  v1 = npc->act_no;
  if ( v1 != 1 )
  {
    if ( v1 == 2 )
    {
      if ( ++npc->act_wait == 4 )
        npc->bits &= 0xFFF7u;
      npc->ym += 42;
      if ( npc->ym > 1535 )
        npc->ym = 1535;
      npc->x += npc->xm;
      npc->y += npc->ym;
      if ( npc->flag & 8 )
      {
        PlaySoundObject(12, 1);
        SetDestroyNpChar(npc->x, npc->y, 0, 3);
        npc->cond = 0;
      }
    }
    else if ( !v1 )
    {
      npc->y = npc->pNpc->y + 5120;
      if ( npc->pNpc->direct )
        v2 = npc->pNpc->x - 3584;
      else
        v2 = npc->pNpc->x + 3584;
      npc->x = v2;
      if ( npc->pNpc->code_char == 318 )
      {
        SetDestroyNpChar(npc->x, npc->y, 0, 3);
        npc->cond = 0;
        return;
      }
      if ( npc->pNpc->ani_no != 2 )
      {
        npc->act_no = 2;
        npc->act_wait = 0;
        npc->ym = -1024;
        npc->y = npc->pNpc->y - 2048;
        if ( npc->pNpc->direct )
          npc->xm = 1024;
        else
          npc->xm = -1024;
      }
    }
  }
  if ( ++npc->ani_no > 2 )
    npc->ani_no = 0;
  npc->rect = (RECT)*((_OWORD *)&v4 + npc->ani_no - 3);
}

