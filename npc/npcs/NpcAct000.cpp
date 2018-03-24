#include "types.h"
#include "SDL_stdinc.h"
#include "windows_wrapper.h"
#include "Tags.h"
#include "forNpc.h"

void __cdecl ActNpc000(NPCHAR_0 *npc);
void __cdecl ActNpc001(NPCHAR_0 *npc);
void __cdecl ActNpc002(NPCHAR_0 *npc);
void __cdecl ActNpc003(NPCHAR_0 *npc);
void __cdecl ActNpc004(NPCHAR_0 *npc);
void __cdecl ActNpc005(NPCHAR_0 *npc);
void __cdecl ActNpc006(NPCHAR_0 *npc);
void __cdecl ActNpc007(NPCHAR_0 *npc);
void __cdecl ActNpc008(NPCHAR_0 *npc);
void __cdecl ActNpc009(NPCHAR_0 *npc);
void __cdecl ActNpc010(NPCHAR_0 *npc);
void __cdecl ActNpc011(NPCHAR_0 *npc);
void __cdecl ActNpc012(NPCHAR_0 *npc);
void __cdecl ActNpc013(NPCHAR_0 *npc);
void __cdecl ActNpc014(NPCHAR_0 *npc);
void __cdecl ActNpc015(NPCHAR_0 *npc);
void __cdecl ActNpc016(NPCHAR_0 *npc);
void __cdecl ActNpc017(NPCHAR_0 *npc);
void __cdecl ActNpc018(NPCHAR_0 *npc);
void __cdecl ActNpc019(NPCHAR_0 *npc);

_UNKNOWN ActNpc016(NPCHAR *)::C.18;
_UNKNOWN ActNpc012(NPCHAR *)::C.15;
_UNKNOWN ActNpc012(NPCHAR *)::C.16;
_UNKNOWN ActNpc006(NPCHAR *)::C.6;
_UNKNOWN ActNpc006(NPCHAR *)::C.7;
_UNKNOWN ActNpc004(NPCHAR *)::C.4;
_UNKNOWN ActNpc004(NPCHAR *)::C.5;
_UNKNOWN ActNpc002(NPCHAR *)::C.2;
_UNKNOWN ActNpc002(NPCHAR *)::C.3;
_UNKNOWN ActNpc001(NPCHAR *)::C.1;

void __cdecl ActNpc000(NPCHAR_0 *npc)
{
  if ( !npc->act_no )
  {
    npc->act_no = 1;
    if ( npc->direct == 2 )
      npc->y += 0x2000;
  }
  npc->rect.left = 0;
  npc->rect.top = 0;
  npc->rect.right = 16;
  npc->rect.bottom = 16;
}


void __cdecl ActNpc001(NPCHAR_0 *npc)
{
  int v1;
  Sint32 *v2;
  int v3;
  RECT rect[6];
  RECT rcNo;
  char v6[24];

  if ( gBack.type != 5 && gBack.type != 6 )
  {
    if ( !npc->act_no )
    {
      npc->act_no = 1;
      npc->ani_no = Random(0, 4);
      npc->xm = Random(-512, 512);
      npc->ym = Random(-1024, 0);
      if ( Random(0, 1) != 0 )
        npc->direct = 0;
      else
        npc->direct = 2;
    }
    if ( npc->flag & 0x100 )
      v1 = npc->ym + 21;
    else
      v1 = npc->ym + 42;
    npc->ym = v1;
    if ( npc->flag & 1 && npc->xm < 0 )
      npc->xm = -npc->xm;
    if ( npc->flag & 4 && npc->xm > 0 )
      npc->xm = -npc->xm;
    if ( npc->flag & 2 && npc->ym < 0 )
      npc->ym = -npc->ym;
    if ( npc->flag & 8 )
    {
      PlaySoundObject(45, 1);
      npc->ym = -640;
      npc->xm = 2 * npc->xm / 3;
    }
    if ( npc->flag & 0xD )
    {
      PlaySoundObject(45, 1);
      if ( ++npc->count2 > 2 )
        npc->y -= 512;
    }
    else
    {
      npc->count2 = 0;
    }
    if ( npc->xm < -1535 )
      npc->xm = -1535;
    if ( npc->xm > 1535 )
      npc->xm = 1535;
    if ( npc->ym < -1535 )
      npc->ym = -1535;
    if ( npc->ym > 1535 )
      npc->ym = 1535;
  }
  else
  {
    if ( !npc->act_no )
    {
      npc->act_no = 1;
      npc->ym = Random(-128, 128);
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
  }
  npc->y += npc->ym;
  npc->x += npc->xm;
  qmemcpy(rect, &ActNpc001(NPCHAR *)::C.1, sizeof(rect));
  rcNo.left = 0;
  rcNo.top = 0;
  rcNo.right = 0;
  rcNo.bottom = 0;
  ++npc->ani_wait;
  if ( npc->direct )
  {
    if ( npc->ani_wait > 2 )
    {
      npc->ani_wait = 0;
      if ( --npc->ani_no < 0 )
        npc->ani_no = 5;
    }
  }
  else if ( npc->ani_wait > 2 )
  {
    npc->ani_wait = 0;
    if ( ++npc->ani_no > 5 )
      npc->ani_no = 0;
  }
  v2 = (Sint32 *)&v6[16 * npc->ani_no - 112];
  npc->rect.left = *v2;
  npc->rect.top = v2[1];
  npc->rect.right = v2[2];
  npc->rect.bottom = v2[3];
  if ( npc->act_no )
  {
    v3 = npc->exp;
    if ( v3 == 5 )
    {
      npc->rect.top += 16;
      npc->rect.bottom += 16;
    }
    else if ( v3 == 20 )
    {
      npc->rect.top += 32;
      npc->rect.bottom += 32;
    }
    npc->act_no = 1;
  }
  if ( ++npc->count1 > 500 && npc->ani_no == 5 && npc->ani_wait == 2 )
    npc->cond = 0;
  if ( npc->count1 > 400 )
  {
    if ( npc->count1 / 2 & 1 )
      npc->rect = rcNo;
  }
}


void __cdecl ActNpc002(NPCHAR_0 *npc)
{
  int v1;
  NPCHAR_0 *v2;
  Sint32 *v3;
  RECT rcRight[7];
  RECT rcLeft[7];
  char v6[12];

  qmemcpy(rcLeft, &ActNpc002(NPCHAR *)::C.2, sizeof(rcLeft));
  qmemcpy(rcRight, &ActNpc002(NPCHAR *)::C.3, sizeof(rcRight));
  if ( npc->flag & 1 )
  {
    npc->direct = 2;
  }
  else if ( npc->flag & 4 )
  {
    npc->direct = 0;
  }
  v1 = npc->act_no;
  switch ( v1 )
  {
    case 1:
      npc->xm = 7 * npc->xm / 8;
      if ( ++npc->count1 > 40 )
      {
        if ( npc->shock )
        {
          npc->count1 = 0;
          npc->act_no = 2;
          npc->ani_no = 6;
          npc->ani_wait = 0;
          npc->damage = 5;
        }
        else
        {
          npc->act_no = 0;
          npc->ani_wait = 0;
        }
      }
      break;
    case 2:
      if ( npc->direct )
        npc->xm = 1024;
      else
        npc->xm = -1024;
      if ( ++npc->count1 > 200 )
      {
        npc->act_no = 0;
        npc->damage = 1;
      }
      if ( ++npc->ani_wait > 5 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 6 )
        npc->ani_no = 5;
      break;
    case 0:
      if ( npc->direct )
        npc->xm = 256;
      else
        npc->xm = -256;
      if ( ++npc->ani_wait > 8 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 3 )
        npc->ani_no = 0;
      if ( npc->shock )
      {
        npc->count1 = 0;
        npc->act_no = 1;
        npc->ani_no = 4;
      }
      break;
  }
  npc->ym += 64;
  if ( npc->ym > 1535 )
    npc->ym = 1535;
  npc->x += npc->xm;
  npc->y += npc->ym;
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


void __cdecl ActNpc003(NPCHAR_0 *npc)
{
  if ( ++npc->count1 > 100 )
    npc->cond = 0;
  npc->rect.left = 0;
  npc->rect.top = 0;
  npc->rect.right = 0;
  npc->rect.bottom = 0;
}

void __cdecl ActNpc004(NPCHAR_0 *npc)
{
  int v1;
  int v2;
  Sint32 *v3;
  Sint32 *v4;
  Sint32 *v5;
  RECT rcUp[8];
  RECT rcLeft[8];
  unsigned __int8 deg;
  char v9[24];

  qmemcpy(rcLeft, &ActNpc004(NPCHAR *)::C.4, sizeof(rcLeft));
  qmemcpy(rcUp, &ActNpc004(NPCHAR *)::C.5, sizeof(rcUp));
  if ( npc->act_no )
  {
    npc->xm = 20 * npc->xm / 21;
    npc->ym = 20 * npc->ym / 21;
    npc->x += npc->xm;
    npc->y += npc->ym;
  }
  else
  {
    if ( !npc->direct || npc->direct == 1 )
    {
      deg = Random(0, 255);
      v1 = GetCos(deg);
      npc->xm = v1 * Random(512, 1535) / 512;
      v2 = GetSin(deg);
      npc->ym = v2 * Random(512, 1535) / 512;
    }
    npc->ani_no = Random(0, 4);
    npc->ani_wait = Random(0, 3);
    npc->act_no = 1;
  }
  if ( ++npc->ani_wait > 4 )
  {
    npc->ani_wait = 0;
    ++npc->ani_no;
  }
  if ( npc->ani_no <= 7 )
  {
    if ( npc->direct == 1 )
    {
      v3 = (Sint32 *)&v9[16 * npc->ani_no - 260];
      npc->rect.left = *v3;
      npc->rect.top = v3[1];
      npc->rect.right = v3[2];
      npc->rect.bottom = v3[3];
    }
    if ( !npc->direct )
    {
      v4 = (Sint32 *)&v9[16 * npc->ani_no - 132];
      npc->rect.left = *v4;
      npc->rect.top = v4[1];
      npc->rect.right = v4[2];
      npc->rect.bottom = v4[3];
    }
    if ( npc->direct == 2 )
    {
      v5 = (Sint32 *)&v9[16 * npc->ani_no - 132];
      npc->rect.left = *v5;
      npc->rect.top = v5[1];
      npc->rect.right = v5[2];
      npc->rect.bottom = v5[3];
    }
  }
  else
  {
    npc->cond = 0;
  }
}


void __cdecl ActNpc005(NPCHAR_0 *npc)
{
  int v1;
  NPCHAR_0 *v2;
  Sint32 *v3;
  RECT rcRight[3];
  RECT rcLeft[3];
  char v6[8];

  rcLeft[0].left = 0;
  rcLeft[0].top = 48;
  rcLeft[0].right = 16;
  rcLeft[0].bottom = 64;
  rcLeft[1].left = 16;
  rcLeft[1].top = 48;
  rcLeft[1].right = 32;
  rcLeft[1].bottom = 64;
  rcLeft[2].left = 32;
  rcLeft[2].top = 48;
  rcLeft[2].right = 48;
  rcLeft[2].bottom = 64;
  rcRight[0].left = 0;
  rcRight[0].top = 64;
  rcRight[0].right = 16;
  rcRight[0].bottom = 80;
  rcRight[1].left = 16;
  rcRight[1].top = 64;
  rcRight[1].right = 32;
  rcRight[1].bottom = 80;
  rcRight[2].left = 32;
  rcRight[2].top = 64;
  rcRight[2].right = 48;
  rcRight[2].bottom = 80;
  v1 = npc->act_no;
  if ( v1 == 1 )
  {
LABEL_9:
    if ( npc->x <= x )
      npc->direct = 2;
    else
      npc->direct = 0;
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
    if ( npc->act_wait > 7 && npc->x - 24576 < x && npc->x + 24576 > x && npc->y - 40960 < y && npc->y + 24576 > y )
    {
      npc->act_no = 2;
      npc->ani_no = 0;
      npc->act_wait = 0;
    }
    goto LABEL_35;
  }
  if ( v1 <= 1 )
  {
    if ( v1 )
      goto LABEL_35;
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
LABEL_35:
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


void __cdecl ActNpc006(NPCHAR_0 *npc)
{
  int v1;
  int v2;
  int v3;
  int v4;
  NPCHAR_0 *v5;
  Sint32 *v6;
  RECT rcRight[5];
  RECT rcLeft[5];
  char v9[12];

  qmemcpy(rcLeft, &ActNpc006(NPCHAR *)::C.6, sizeof(rcLeft));
  qmemcpy(rcRight, &ActNpc006(NPCHAR *)::C.7, sizeof(rcRight));
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
      if ( ++npc->act_wait > 60 )
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
      if ( ++npc->act_wait > 60 )
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
    v6 = (Sint32 *)&v9[16 * npc->ani_no - 160];
  }
  else
  {
    v5 = npc;
    v6 = (Sint32 *)&v9[16 * npc->ani_no - 80];
  }
  npc->rect.left = *v6;
  v5->rect.top = v6[1];
  v5->rect.right = v6[2];
  v5->rect.bottom = v6[3];
}


void __cdecl ActNpc007(NPCHAR_0 *npc)
{
  int v1;
  NPCHAR_0 *v2;
  RECT *v3;
  RECT rcRight[3];
  RECT rcLeft[3];

  rcLeft[0].left = 256;
  rcLeft[0].top = 64;
  rcLeft[0].right = 288;
  rcLeft[0].bottom = 80;
  rcLeft[1].left = 256;
  rcLeft[1].top = 80;
  rcLeft[1].right = 288;
  rcLeft[1].bottom = 96;
  rcLeft[2].left = 256;
  rcLeft[2].top = 96;
  rcLeft[2].right = 288;
  rcLeft[2].bottom = 112;
  rcRight[0].left = 288;
  rcRight[0].top = 64;
  rcRight[0].right = 320;
  rcRight[0].bottom = 80;
  rcRight[1].left = 288;
  rcRight[1].top = 80;
  rcRight[1].right = 320;
  rcRight[1].bottom = 96;
  rcRight[2].left = 288;
  rcRight[2].top = 96;
  rcRight[2].right = 320;
  rcRight[2].bottom = 112;
  v1 = npc->act_no;
  switch ( v1 )
  {
    case 1:
      npc->xm -= 64;
      if ( npc->x < x - 98304 )
        npc->act_no = 2;
      if ( npc->flag & 1 )
      {
        npc->xm = 0;
        npc->act_no = 2;
      }
      break;
    case 2:
      npc->xm += 64;
      if ( npc->x > x + 98304 )
        npc->act_no = 1;
      if ( npc->flag & 4 )
      {
        npc->xm = 0;
        npc->act_no = 1;
      }
      break;
    case 0:
      npc->x = x;
      if ( npc->direct )
        npc->act_no = 2;
      else
        npc->act_no = 1;
      break;
  }
  if ( npc->xm >= 0 )
    npc->direct = 2;
  else
    npc->direct = 0;
  if ( npc->xm > 1535 )
    npc->xm = 1535;
  if ( npc->xm < -1535 )
    npc->xm = -1535;
  npc->x += npc->xm;
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

void __cdecl ActNpc008(NPCHAR_0 *npc)
{
  int v1;
  int v2;
  int v3;
  int v4;
  int v5;
  NPCHAR_0 *v6;
  RECT *v7;
  RECT rcRight[2];
  RECT rcLeft[2];

  rcLeft[0].left = 80;
  rcLeft[0].top = 80;
  rcLeft[0].right = 96;
  rcLeft[0].bottom = 96;
  rcLeft[1].left = 96;
  rcLeft[1].top = 80;
  rcLeft[1].right = 112;
  rcLeft[1].bottom = 96;
  rcRight[0].left = 80;
  rcRight[0].top = 96;
  rcRight[0].right = 96;
  rcRight[0].bottom = 112;
  rcRight[1].left = 96;
  rcRight[1].top = 96;
  rcRight[1].right = 112;
  rcRight[1].bottom = 112;
  v1 = npc->act_no;
  if ( v1 )
  {
    if ( v1 == 1 )
    {
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
      if ( npc->xm > 767 )
        npc->xm = 767;
      if ( npc->xm < -767 )
        npc->xm = -767;
      if ( npc->y >= npc->tgt_y )
        v3 = npc->ym - 8;
      else
        v3 = npc->ym + 8;
      npc->ym = v3;
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
    }
  }
  else
  {
    if ( x >= npc->x + 0x2000 || x <= npc->x - 0x2000 )
    {
      npc->bits &= 0xFFDFu;
      npc->rect.right = 0;
      npc->damage = 0;
      npc->xm = 0;
      npc->ym = 0;
      return;
    }
    npc->bits |= 0x20u;
    npc->ym = -256;
    npc->tgt_y = npc->y;
    npc->act_no = 1;
    npc->damage = 2;
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
  if ( ++npc->ani_wait > 1 )
  {
    npc->ani_wait = 0;
    ++npc->ani_no;
  }
  if ( npc->ani_no > 1 )
    npc->ani_no = 0;
  if ( npc->direct )
  {
    v6 = npc;
    v7 = &rcRight[npc->ani_no];
  }
  else
  {
    v6 = npc;
    v7 = &rcLeft[npc->ani_no];
  }
  npc->rect.left = v7->left;
  v6->rect.top = v7->top;
  v6->rect.right = v7->right;
  v6->rect.bottom = v7->bottom;
}

void __cdecl ActNpc009(NPCHAR_0 *npc)
{
  int v1;
  int v2;
  int v3;
  int v4;
  int v5;
  int v6;
  int v7;
  NPCHAR_0 *v8;
  Sint32 *v9;
  RECT rect_right[3];
  RECT rect_left[3];
  int i;
  char v13[24];

  v1 = npc->act_no;
  if ( v1 == 1 )
  {
LABEL_5:
    npc->ym += 32;
    if ( npc->count1 > 39 )
    {
      npc->bits &= 0xFFF7u;
      npc->bits |= 1u;
    }
    else
    {
      ++npc->count1;
    }
    if ( npc->flag & 8 )
    {
      for ( i = 0; i <= 3; ++i )
      {
        v2 = Random(-1536, 0);
        v3 = Random(-341, 341);
        v4 = npc->y;
        v5 = (Random(-12, 12) << 9) + v4;
        v6 = npc->x;
        v7 = Random(-12, 12);
        SetNpChar(4, v6 + (v7 << 9), v5, v3, v2, 0, 0, 256);
      }
      npc->act_no = 2;
      npc->ani_no = 1;
      npc->act_wait = 0;
      PlaySoundObject(26, 1);
      SetQuake(30);
    }
    goto LABEL_15;
  }
  if ( v1 != 2 )
  {
    if ( v1 )
      goto LABEL_15;
    npc->act_no = 1;
    npc->ani_no = 2;
    goto LABEL_5;
  }
  if ( ++npc->act_wait > 16 )
  {
    npc->act_no = 3;
    npc->ani_no = 0;
    npc->ani_wait = 0;
  }
LABEL_15:
  if ( npc->ym > 1535 )
    npc->ym = 1535;
  if ( npc->ym < -1535 )
    npc->ym = -1535;
  npc->x += npc->xm;
  npc->y += npc->ym;
  rect_left[0].left = 0;
  rect_left[0].top = 0;
  rect_left[0].right = 40;
  rect_left[0].bottom = 24;
  rect_left[1].left = 80;
  rect_left[1].top = 0;
  rect_left[1].right = 120;
  rect_left[1].bottom = 24;
  rect_left[2].left = 120;
  rect_left[2].top = 0;
  rect_left[2].right = 160;
  rect_left[2].bottom = 24;
  rect_right[0].left = 0;
  rect_right[0].top = 24;
  rect_right[0].right = 40;
  rect_right[0].bottom = 48;
  rect_right[1].left = 80;
  rect_right[1].top = 24;
  rect_right[1].right = 120;
  rect_right[1].bottom = 48;
  rect_right[2].left = 120;
  rect_right[2].top = 24;
  rect_right[2].right = 160;
  rect_right[2].bottom = 48;
  if ( npc->direct )
  {
    v8 = npc;
    v9 = (Sint32 *)&v13[16 * npc->ani_no - 100];
  }
  else
  {
    v8 = npc;
    v9 = (Sint32 *)&v13[16 * npc->ani_no - 52];
  }
  npc->rect.left = *v9;
  v8->rect.top = v9[1];
  v8->rect.right = v9[2];
  v8->rect.bottom = v9[3];
}


void __cdecl ActNpc010(NPCHAR_0 *npc)
{
  NPCHAR_0 *v1;
  Sint32 *v2;
  RECT rect_right[4];
  RECT rect_left[4];
  unsigned __int8 deg;
  int xm;
  int ym;
  char v8[8];

  switch ( npc->act_no )
  {
    case 0:
      npc->act_no = 1;
      goto LABEL_3;
    case 1:
LABEL_3:
      if ( ++npc->act_wait > 12 )
      {
        npc->act_no = 2;
        npc->act_wait = 0;
        npc->count1 = 3;
        npc->ani_no = 1;
      }
      break;
    case 2:
      if ( ++npc->act_wait > 16 )
      {
        --npc->count1;
        npc->act_wait = 0;
        deg = GetArktan(npc->x - x, npc->y + 2048 - y);
        deg += Random(-16, 16);
        ym = GetSin(deg);
        xm = GetCos(deg);
        SetNpChar(11, npc->x, npc->y + 2048, xm, ym, 0, 0, 256);
        PlaySoundObject(39, 1);
        if ( !npc->count1 )
        {
          npc->act_no = 3;
          npc->act_wait = 0;
        }
      }
      break;
    case 3:
      if ( ++npc->act_wait > 3 )
      {
        npc->act_no = 4;
        npc->act_wait = 0;
        npc->xm = (x - npc->x) / 100;
        npc->ym = -1536;
        npc->ani_no = 3;
      }
      break;
    case 4:
      if ( npc->flag & 5 )
        npc->xm = 0;
      if ( npc->y + 0x2000 >= y )
        npc->damage = 0;
      else
        npc->damage = 5;
      if ( npc->flag & 8 )
      {
        npc->act_no = 5;
        npc->act_wait = 0;
        npc->ani_no = 2;
        PlaySoundObject(26, 1);
        SetQuake(30);
        npc->damage = 0;
      }
      break;
    case 5:
      npc->xm = 0;
      if ( ++npc->act_wait > 3 )
      {
        npc->act_no = 1;
        npc->act_wait = 0;
      }
      break;
    default:
      break;
  }
  npc->ym += 32;
  if ( npc->ym > 1535 )
    npc->ym = 1535;
  npc->x += npc->xm;
  npc->y += npc->ym;
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
  if ( npc->x >= x )
    npc->direct = 0;
  else
    npc->direct = 2;
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
}


void __cdecl ActNpc011(NPCHAR_0 *npc)
{
  Sint32 *v1;
  RECT rect_left[3];
  char v3[8];

  if ( npc->flag & 0xFF )
  {
    npc->cond = 0;
    SetCaret(npc->x, npc->y, 2, 0);
  }
  npc->y += npc->ym;
  npc->x += npc->xm;
  rect_left[0].left = 208;
  rect_left[0].top = 104;
  rect_left[0].right = 224;
  rect_left[0].bottom = 120;
  rect_left[1].left = 224;
  rect_left[1].top = 104;
  rect_left[1].right = 240;
  rect_left[1].bottom = 120;
  rect_left[2].left = 240;
  rect_left[2].top = 104;
  rect_left[2].right = 256;
  rect_left[2].bottom = 120;
  if ( ++npc->ani_wait > 1 )
  {
    npc->ani_wait = 0;
    if ( ++npc->ani_no > 2 )
      npc->ani_no = 0;
  }
  v1 = (Sint32 *)&v3[16 * npc->ani_no - 48];
  npc->rect.left = *v1;
  npc->rect.top = v1[1];
  npc->rect.right = v1[2];
  npc->rect.bottom = v1[3];
  if ( ++npc->count1 > 150 )
  {
    SetCaret(npc->x, npc->y, 2, 0);
    npc->cond = 0;
  }
}


void __cdecl ActNpc012(NPCHAR_0 *npc)
{
  int v1;
  int v2;
  int v3;
  int v4;
  int v5;
  int v6;
  int v7;
  int v8;
  bool v9;
  int v10;
  int v11;
  int v12;
  int v13;
  int v14;
  int v15;
  NPCHAR_0 *v16;
  Sint32 *v17;
  RECT rect_right[14];
  RECT rect_left[14];
  int i;
  int x;
  int y;
  char v23[24];

  switch ( npc->act_no )
  {
    case 0:
      if ( npc->direct == 4 )
      {
        if ( npc->x <= ::x )
          npc->direct = 2;
        else
          npc->direct = 0;
      }
      npc->act_no = 1;
      npc->ani_no = 0;
      goto LABEL_7;
    case 1:
LABEL_7:
      if ( Random(0, 100) == 0 )
      {
        npc->act_no = 2;
        npc->act_wait = 0;
        npc->ani_no = 1;
      }
      break;
    case 2:
      if ( ++npc->act_wait > 16 )
      {
        npc->act_no = 1;
        npc->ani_no = 0;
      }
      break;
    case 0xA:
      if ( npc->direct == 4 )
      {
        if ( npc->x <= ::x )
          npc->direct = 2;
        else
          npc->direct = 0;
      }
      npc->act_no = 11;
      npc->ani_no = 2;
      npc->act_wait = 0;
      npc->tgt_x = 0;
      goto LABEL_16;
    case 0xB:
LABEL_16:
      if ( ++npc->act_wait > 30 )
      {
        npc->act_no = 12;
        npc->act_wait = 0;
        npc->ani_no = 3;
        npc->ym = -2048;
        npc->bits |= 8u;
      }
      break;
    case 0xC:
      if ( npc->flag & 5 )
        npc->xm = 0;
      if ( npc->y < 0 )
      {
        npc->code_char = 0;
        PlaySoundObject(26, 1);
        SetQuake(30);
      }
      break;
    case 0x14:
      if ( npc->direct == 4 )
      {
        if ( npc->x <= ::x )
          npc->direct = 2;
        else
          npc->direct = 0;
      }
      npc->act_no = 21;
      npc->ani_no = 5;
      npc->act_wait = 0;
      npc->count1 = 0;
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
      PlaySoundObject(72, 1);
      goto LABEL_30;
    case 0x15:
LABEL_30:
      npc->tgt_x = 1;
      if ( npc->flag & 8 )
        ++npc->act_wait;
      if ( ++npc->count1 / 2 & 1 )
        v7 = npc->x + 512;
      else
        v7 = npc->x - 512;
      npc->x = v7;
      if ( npc->act_wait > 100 )
      {
        npc->act_no = 11;
        npc->act_wait = 0;
        npc->ani_no = 2;
      }
      npc->ym += 32;
      if ( npc->ym > 1535 )
        npc->ym = 1535;
      break;
    case 0x1E:
      npc->ani_no = 4;
      if ( ++npc->act_wait > 100 )
      {
        npc->act_no = 0;
        npc->ani_no = 0;
      }
      break;
    case 0x28:
      if ( npc->direct == 4 )
      {
        if ( npc->x <= ::x )
          npc->direct = 2;
        else
          npc->direct = 0;
      }
      npc->act_no = 41;
      npc->act_wait = 0;
      npc->ani_no = 5;
      goto LABEL_46;
    case 0x29:
LABEL_46:
      if ( ++npc->ani_wait / 2 & 1 )
        npc->ani_no = 5;
      else
        npc->ani_no = 6;
      break;
    case 0x2A:
      if ( npc->direct == 4 )
      {
        if ( npc->x <= ::x )
          npc->direct = 2;
        else
          npc->direct = 0;
      }
      npc->act_no = 43;
      npc->act_wait = 0;
      npc->ani_no = 6;
      goto LABEL_54;
    case 0x2B:
LABEL_54:
      if ( ++npc->ani_wait / 2 & 1 )
        npc->ani_no = 7;
      else
        npc->ani_no = 6;
      break;
    case 0x32:
      npc->ani_no = 8;
      npc->xm = 0;
      break;
    case 0x3C:
      npc->act_no = 61;
      npc->ani_no = 9;
      npc->ani_wait = 0;
      goto LABEL_59;
    case 0x3D:
LABEL_59:
      if ( ++npc->ani_wait > 3 )
      {
        npc->ani_wait = 0;
        if ( ++npc->ani_no == 10 || npc->ani_no == 11 )
          PlaySoundObject(23, 1);
      }
      if ( npc->ani_no > 12 )
        npc->ani_no = 9;
      if ( npc->direct )
        npc->xm = 512;
      else
        npc->xm = -512;
      break;
    case 0x46:
      npc->act_no = 71;
      npc->act_wait = 64;
      PlaySoundObject(29, 1);
      npc->ani_no = 13;
      goto LABEL_69;
    case 0x47:
LABEL_69:
      if ( !--npc->act_wait )
        npc->cond = 0;
      break;
    case 0x50:
      npc->count1 = 0;
      npc->act_no = 81;
      goto LABEL_72;
    case 0x51:
LABEL_72:
      if ( ++npc->count1 / 2 & 1 )
        v8 = npc->x + 512;
      else
        v8 = npc->x - 512;
      npc->x = v8;
      npc->ani_no = 5;
      npc->xm = 0;
      npc->ym += 32;
      break;
    case 0x64:
      npc->act_no = 101;
      npc->act_wait = 0;
      npc->ani_no = 2;
      goto LABEL_77;
    case 0x65:
LABEL_77:
      if ( ++npc->act_wait > 20 )
      {
        npc->act_no = 102;
        npc->act_wait = 0;
        npc->ani_no = 3;
        npc->ym = -2048;
        npc->bits |= 8u;
        DeleteNpCharCode(150, 0);
        DeleteNpCharCode(117, 0);
        SetNpChar(355, 0, 0, 0, 0, 0, npc, 256);
        SetNpChar(355, 0, 0, 0, 0, 1, npc, 256);
      }
      break;
    case 0x66:
      x = npc->x / 0x2000;
      y = npc->y / 0x2000;
      if ( y >= 0 && y <= 34 && (unsigned __int8)ChangeMapParts(x, y, 0) )
      {
        ChangeMapParts(x - 1, y, 0);
        ChangeMapParts(x + 1, y, 0);
        PlaySoundObject(44, 1);
        SetQuake2(10);
      }
      if ( npc->y < -16384 )
      {
        npc->code_char = 0;
        SetQuake(30);
      }
      break;
    default:
      break;
  }
  v9 = npc->tgt_x && !Random(0, 10);
  if ( v9 )
  {
    v10 = Random(-1536, 0);
    v11 = Random(-341, 341);
    v12 = npc->y;
    v13 = (Random(-12, 12) << 9) + v12;
    v14 = npc->x;
    v15 = Random(-12, 12);
    SetNpChar(4, v14 + (v15 << 9), v13, v11, v10, 0, 0, 256);
  }
  if ( npc->ym > 1535 )
    npc->ym = 1535;
  npc->x += npc->xm;
  npc->y += npc->ym;
  qmemcpy(rect_left, &ActNpc012(NPCHAR *)::C.15, sizeof(rect_left));
  qmemcpy(rect_right, &ActNpc012(NPCHAR *)::C.16, sizeof(rect_right));
  if ( npc->direct )
  {
    v16 = npc;
    v17 = (Sint32 *)&v23[16 * npc->ani_no - 460];
  }
  else
  {
    v16 = npc;
    v17 = (Sint32 *)&v23[16 * npc->ani_no - 236];
  }
  npc->rect.left = *v17;
  v16->rect.top = v17[1];
  v16->rect.right = v17[2];
  v16->rect.bottom = v17[3];
  if ( npc->act_no == 71 )
  {
    npc->rect.bottom = npc->act_wait / 2 + npc->rect.top;
    if ( npc->act_wait & 1 )
      ++npc->rect.left;
  }
}


void __cdecl ActNpc013(NPCHAR_0 *npc)
{
  RECT *v1;
  RECT rect[4];

  rect[0].left = 128;
  rect[0].top = 0;
  rect[0].right = 144;
  rect[0].bottom = 16;
  rect[1].left = 144;
  rect[1].top = 0;
  rect[1].right = 160;
  rect[1].bottom = 16;
  rect[2].left = 160;
  rect[2].top = 0;
  rect[2].right = 176;
  rect[2].bottom = 16;
  rect[3].left = 176;
  rect[3].top = 0;
  rect[3].right = 192;
  rect[3].bottom = 16;
  if ( ++npc->ani_wait > 0 )
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

void __cdecl ActNpc014(NPCHAR_0 *npc)
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
  if ( !npc->act_no )
  {
    npc->act_no = 1;
    if ( npc->direct == 2 )
    {
      npc->ym = -512;
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
  }
  if ( ++npc->ani_wait > 1 )
  {
    npc->ani_wait = 0;
    ++npc->ani_no;
  }
  if ( npc->ani_no > 2 )
    npc->ani_no = 0;
  npc->ym += 64;
  if ( npc->ym > 1535 )
    npc->ym = 1535;
  npc->y += npc->ym;
  v7 = (Sint32 *)&v10[16 * npc->ani_no - 52];
  npc->rect.left = *v7;
  npc->rect.top = v7[1];
  npc->rect.right = v7[2];
  npc->rect.bottom = v7[3];
}


void __cdecl ActNpc015(NPCHAR_0 *npc)
{
  int v1;
  unsigned __int16 v2;
  int v3;
  int v4;
  int v5;
  int v6;
  int v7;
  int v8;
  Sint32 *v9;
  RECT rcLeft[3];
  int i;
  char v12[24];

  rcLeft[0].left = 240;
  rcLeft[0].top = 0;
  rcLeft[0].right = 256;
  rcLeft[0].bottom = 16;
  rcLeft[1].left = 256;
  rcLeft[1].top = 0;
  rcLeft[1].right = 272;
  rcLeft[1].bottom = 16;
  rcLeft[2].left = 272;
  rcLeft[2].top = 0;
  rcLeft[2].right = 288;
  rcLeft[2].bottom = 16;
  v1 = npc->act_no;
  if ( v1 == 1 )
  {
LABEL_8:
    npc->ani_no = 0;
    if ( Random(0, 30) == 0 )
      npc->act_no = 2;
    goto LABEL_14;
  }
  if ( v1 != 2 )
  {
    if ( v1 )
      goto LABEL_14;
    npc->act_no = 1;
    v2 = npc->bits;
    HIBYTE(v2) |= 0x20u;
    npc->bits = v2;
    if ( npc->direct == 2 )
    {
      npc->ym = -512;
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
    }
    goto LABEL_8;
  }
  if ( ++npc->ani_wait > 1 )
  {
    npc->ani_wait = 0;
    ++npc->ani_no;
  }
  if ( npc->ani_no > 2 )
  {
    npc->act_no = 1;
    npc->ani_no = 0;
  }
LABEL_14:
  npc->ym += 64;
  if ( npc->ym > 1535 )
    npc->ym = 1535;
  npc->y += npc->ym;
  v9 = (Sint32 *)&v12[16 * npc->ani_no - 52];
  npc->rect.left = *v9;
  npc->rect.top = v9[1];
  npc->rect.right = v9[2];
  npc->rect.bottom = v9[3];
}


void __cdecl ActNpc016(NPCHAR_0 *npc)
{
  int v1;
  unsigned __int16 v2;
  unsigned __int16 v3;
  int v4;
  int v5;
  int v6;
  int v7;
  int v8;
  int v9;
  unsigned __int16 v10;
  Sint32 *v11;
  RECT rect[8];
  int i;
  char v14[24];

  qmemcpy(rect, &ActNpc016(NPCHAR *)::C.18, sizeof(rect));
  v1 = npc->act_no;
  if ( v1 )
  {
    if ( v1 != 1 )
      goto LABEL_10;
  }
  else
  {
    v2 = npc->bits;
    HIBYTE(v2) |= 0x20u;
    npc->bits = v2;
    npc->act_no = 1;
    if ( npc->direct == 2 )
    {
      v3 = npc->bits;
      HIBYTE(v3) &= 0xDFu;
      npc->bits = v3;
      npc->ym = -512;
      for ( i = 0; i <= 3; ++i )
      {
        v4 = Random(-1536, 0);
        v5 = Random(-341, 341);
        v6 = npc->y;
        v7 = (Random(-12, 12) << 9) + v6;
        v8 = npc->x;
        v9 = Random(-12, 12);
        SetNpChar(4, v8 + (v9 << 9), v7, v5, v4, 0, 0, 256);
      }
    }
  }
  if ( npc->flag & 8 )
  {
    v10 = npc->bits;
    HIBYTE(v10) |= 0x20u;
    npc->bits = v10;
  }
LABEL_10:
  if ( ++npc->ani_wait > 2 )
  {
    npc->ani_wait = 0;
    ++npc->ani_no;
  }
  if ( npc->ani_no > 7 )
    npc->ani_no = 0;
  npc->ym += 64;
  if ( npc->ym > 1535 )
    npc->ym = 1535;
  npc->y += npc->ym;
  v11 = (Sint32 *)&v14[16 * npc->ani_no - 132];
  npc->rect.left = *v11;
  npc->rect.top = v11[1];
  npc->rect.right = v11[2];
  npc->rect.bottom = v11[3];
}


void __cdecl ActNpc017(NPCHAR_0 *npc)
{
  int v1;
  int v2;
  int v3;
  int v4;
  int v5;
  int v6;
  int a;
  int aa;

  switch ( npc->act_no )
  {
    case 0:
      npc->act_no = 1;
      if ( npc->direct == 2 )
      {
        npc->ym = -512;
        for ( a = 0; a <= 3; ++a )
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
      goto LABEL_6;
    case 1:
LABEL_6:
      aa = Random(0, 30);
      if ( aa > 9 )
      {
        if ( aa > 24 )
          npc->act_no = 4;
        else
          npc->act_no = 3;
      }
      else
      {
        npc->act_no = 2;
      }
      npc->act_wait = Random(16, 64);
      npc->ani_wait = 0;
      break;
    case 2:
      npc->rect.left = 288;
      npc->rect.top = 0;
      npc->rect.right = 304;
      npc->rect.bottom = 16;
      if ( !--npc->act_wait )
        npc->act_no = 1;
      break;
    case 3:
      ++npc->ani_wait;
      if ( npc->ani_wait & 1 )
      {
        npc->rect.left = 288;
        npc->rect.top = 0;
        npc->rect.right = 304;
      }
      else
      {
        npc->rect.left = 304;
        npc->rect.top = 0;
        npc->rect.right = 320;
      }
      npc->rect.bottom = 16;
      if ( !--npc->act_wait )
        npc->act_no = 1;
      break;
    case 4:
      npc->rect.left = 304;
      npc->rect.top = 0;
      npc->rect.right = 320;
      npc->rect.bottom = 16;
      if ( !--npc->act_wait )
        npc->act_no = 1;
      break;
    default:
      break;
  }
  npc->ym += 64;
  if ( npc->ym > 1535 )
    npc->ym = 1535;
  npc->y += npc->ym;
}

void __cdecl ActNpc018(NPCHAR_0 *npc)
{
  int v1;
  int v2;
  int v3;
  int i;

  v1 = npc->act_no;
  if ( v1 )
  {
    if ( v1 == 1 )
    {
      for ( i = 0; i <= 3; ++i )
      {
        v2 = Random(-1536, 0);
        v3 = Random(-341, 341);
        SetNpChar(4, npc->x, npc->y, v3, v2, 0, 0, 256);
      }
      npc->act_no = 0;
      npc->rect.left = 224;
      npc->rect.top = 16;
      npc->rect.right = 240;
      npc->rect.bottom = 40;
    }
  }
  else if ( npc->direct )
  {
    npc->rect.left = 192;
    npc->rect.top = 112;
    npc->rect.right = 208;
    npc->rect.bottom = 136;
  }
  else
  {
    npc->rect.left = 224;
    npc->rect.top = 16;
    npc->rect.right = 240;
    npc->rect.bottom = 40;
  }
}

void __cdecl ActNpc019(NPCHAR_0 *npc)
{
  int v1;
  int v2;
  int v3;
  int v4;
  int v5;
  int v6;
  NPCHAR_0 *v7;
  Sint32 *v8;
  RECT rect_right[4];
  RECT rect_left[4];
  int i;
  char v12[24];

  switch ( npc->act_no )
  {
    case 0:
      for ( i = 0; i <= 15; ++i )
      {
        v1 = Random(-1536, 0);
        v2 = Random(-341, 341);
        v3 = npc->y;
        v4 = (Random(-12, 12) << 9) + v3;
        v5 = npc->x;
        v6 = Random(-12, 12);
        SetNpChar(4, v5 + (v6 << 9), v4, v2, v1, 0, 0, 256);
      }
      npc->y += 5120;
      npc->act_no = 1;
      npc->ani_no = 3;
      npc->ym = -256;
      PlaySoundObject(12, 1);
      PlaySoundObject(26, 1);
      SetQuake(30);
      goto LABEL_6;
    case 1:
LABEL_6:
      npc->ym += 16;
      if ( npc->ym > 0 && npc->flag & 8 )
      {
        npc->act_no = 2;
        npc->ani_no = 2;
        npc->act_wait = 0;
        PlaySoundObject(26, 1);
        SetQuake(30);
      }
      break;
    case 2:
      if ( ++npc->act_wait > 16 )
      {
        npc->act_no = 3;
        npc->ani_no = 0;
        npc->ani_wait = 0;
      }
      break;
    case 3:
      if ( Random(0, 100) == 0 )
      {
        npc->act_no = 4;
        npc->act_wait = 0;
        npc->ani_no = 1;
      }
      break;
    case 4:
      if ( ++npc->act_wait > 16 )
      {
        npc->act_no = 3;
        npc->ani_no = 0;
      }
      break;
    default:
      break;
  }
  if ( npc->ym > 1535 )
    npc->ym = 1535;
  if ( npc->ym < -1535 )
    npc->ym = -1535;
  npc->x += npc->xm;
  npc->y += npc->ym;
  rect_left[0].left = 0;
  rect_left[0].top = 0;
  rect_left[0].right = 40;
  rect_left[0].bottom = 24;
  rect_left[1].left = 160;
  rect_left[1].top = 0;
  rect_left[1].right = 200;
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
  rect_right[1].left = 160;
  rect_right[1].top = 24;
  rect_right[1].right = 200;
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
    v7 = npc;
    v8 = (Sint32 *)&v12[16 * npc->ani_no - 132];
  }
  else
  {
    v7 = npc;
    v8 = (Sint32 *)&v12[16 * npc->ani_no - 68];
  }
  npc->rect.left = *v8;
  v7->rect.top = v8[1];
  v7->rect.right = v8[2];
  v7->rect.bottom = v8[3];
}


