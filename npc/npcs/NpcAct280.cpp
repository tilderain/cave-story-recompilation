#include "types.h"
#include "SDL_stdinc.h"
#include "windows_wrapper.h"
#include "Tags.h"
#include "forNpc.h"

void __cdecl ActNpc280(NPCHAR_0 *npc);
void __cdecl ActNpc281(NPCHAR_0 *npc);
void __cdecl ActNpc282(NPCHAR_0 *npc);
void __cdecl ActNpc283(NPCHAR_0 *npc);
void __cdecl ActNpc284(NPCHAR_0 *npc);
void __cdecl ActNpc285(NPCHAR_0 *npc);
void __cdecl ActNpc286(NPCHAR_0 *npc);
void __cdecl ActNpc287(NPCHAR_0 *npc);
void __cdecl ActNpc288(NPCHAR_0 *npc);
void __cdecl ActNpc289(NPCHAR_0 *npc);
void __cdecl ActNpc290(NPCHAR_0 *npc);
void __cdecl ActNpc291(NPCHAR_0 *npc);
void __cdecl ActNpc292();
void __cdecl ActNpc293(NPCHAR_0 *npc);
void __cdecl ActNpc294(NPCHAR_0 *npc);
void __cdecl ActNpc295(NPCHAR_0 *npc);
void __cdecl ActNpc296(NPCHAR_0 *npc);
void __cdecl ActNpc297(NPCHAR_0 *npc);
void __cdecl ActNpc298(NPCHAR_0 *npc);
void __cdecl ActNpc299(NPCHAR_0 *npc);

_UNKNOWN ActNpc298(NPCHAR *)::C.11;
_UNKNOWN ActNpc288(NPCHAR *)::C.9;
_UNKNOWN ActNpc287(NPCHAR *)::C.8;
_UNKNOWN ActNpc284(NPCHAR *)::C.4;
_UNKNOWN ActNpc284(NPCHAR *)::C.5;
_UNKNOWN ActNpc283(NPCHAR *)::C.1;
_UNKNOWN ActNpc283(NPCHAR *)::C.2;

void __cdecl ActNpc281(NPCHAR_0 *npc)
{
  switch ( npc->act_no )
  {
    case 0:
      npc->act_no = 1;
      break;
    case 0xA:
      npc->act_no = 11;
      npc->act_wait = 0;
      goto LABEL_4;
    case 0xB:
LABEL_4:
      ++npc->act_wait;
      SetNpChar(270, npc->x, npc->y + 0x10000, 0, 0, 2, npc, 256);
      if ( npc->act_wait > 150 )
        npc->act_no = 12;
      break;
    case 0x14:
      npc->act_no = 21;
      npc->act_wait = 0;
      goto LABEL_7;
    case 0x15:
LABEL_7:
      if ( ++npc->act_wait > 250 )
      {
        DeleteNpCharCode(270, 0);
        npc->act_no = 22;
      }
      break;
    default:
      break;
  }
  npc->rect.left = 0;
  npc->rect.top = 0;
  npc->rect.right = 0;
  npc->rect.bottom = 0;
}

void __cdecl ActNpc282(NPCHAR_0 *npc)
{
  int v1;
  Sint32 *v2;
  RECT tc[3];
  char v4[8];

  tc[0].left = 256;
  tc[0].top = 80;
  tc[0].right = 320;
  tc[0].bottom = 120;
  tc[1].left = 256;
  tc[1].top = 0;
  tc[1].right = 320;
  tc[1].bottom = 40;
  tc[2].left = 256;
  tc[2].top = 120;
  tc[2].right = 320;
  tc[2].bottom = 160;
  v1 = npc->act_no;
  if ( v1 )
  {
    if ( v1 != 20 )
      goto LABEL_48;
  }
  else
  {
    npc->act_no = 20;
    npc->tgt_y = npc->y;
    if ( Random(0, 100) & 1 )
      npc->ym = -256;
    else
      npc->ym = 256;
  }
  npc->xm = -512;
  if ( npc->x < -32768 )
    npc->cond = 0;
  if ( npc->tgt_y < npc->y )
    npc->ym -= 16;
  if ( npc->tgt_y > npc->y )
    npc->ym += 16;
  if ( npc->ym > 256 )
    npc->ym = 256;
  if ( npc->ym < -256 )
    npc->ym = -256;
  if ( dword_81C8584 & 8 && y < npc->y - 2048 && x > npc->x - 12288 && x < npc->x + 12288 )
  {
    npc->tgt_y = 73728;
    npc->ani_no = 2;
  }
  else if ( npc->ani_no != 1 )
  {
    npc->ani_no = 0;
  }
  if ( dword_81C8584 & 1
    && x < npc->x - npc->hit.back
    && x > npc->x - npc->hit.back - 4096
    && y + unk_81C85D0 > npc->y - npc->hit.top
    && y - unk_81C85C8 < npc->y + npc->hit.bottom )
  {
    npc->bits &= 0xFFBFu;
    npc->ani_no = 1;
  }
  else if ( dword_81C8584 & 4
         && x > npc->x + npc->hit.back
         && x < npc->x + npc->hit.back + 4096
         && y + unk_81C85D0 > npc->y - npc->hit.top
         && y - unk_81C85C8 < npc->y + npc->hit.bottom )
  {
    npc->bits &= 0xFFBFu;
    npc->ani_no = 1;
  }
  else if ( dword_81C8584 & 2
         && y < npc->y - npc->hit.top
         && y > npc->y - npc->hit.top - 4096
         && x + unk_81C85C4 > npc->x - npc->hit.back
         && x - unk_81C85CC < npc->x + npc->hit.front )
  {
    npc->bits &= 0xFFBFu;
    npc->ani_no = 1;
  }
  else if ( dword_81C8584 & 8
         && y > npc->y + npc->hit.bottom - 2048
         && y < npc->y + npc->hit.bottom + 6144
         && x + unk_81C85C4 > npc->x - npc->hit.back - 2048
         && x - unk_81C85CC < npc->x + npc->hit.front + 2048 )
  {
    npc->bits &= 0xFFBFu;
    npc->ani_no = 1;
  }
LABEL_48:
  npc->x += npc->xm;
  npc->y += npc->ym;
  v2 = (Sint32 *)&v4[16 * npc->ani_no - 48];
  npc->rect.left = *v2;
  npc->rect.top = v2[1];
  npc->rect.right = v2[2];
  npc->rect.bottom = v2[3];
}


void __cdecl ActNpc283(NPCHAR_0 *npc)
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
  NPCHAR_0 *v13;
  Sint32 *v14;
  RECT rcRight[11];
  RECT rcLeft[11];
  int x;
  int y;
  int direct;
  char v20[24];

  qmemcpy(rcLeft, &ActNpc283(NPCHAR *)::C.1, sizeof(rcLeft));
  qmemcpy(rcRight, &ActNpc283(NPCHAR *)::C.2, sizeof(rcRight));
  if ( npc->act_no <= 99 && (!gBoss[0].cond || npc->life <= 399) )
    npc->act_no = 100;
  switch ( npc->act_no )
  {
    case 0:
      npc->act_no = 1;
      npc->y -= 4096;
      PlaySoundObject(29, 1);
      goto LABEL_7;
    case 1:
LABEL_7:
      if ( ++npc->act_wait / 2 & 1 )
        npc->ani_no = 9;
      else
        npc->ani_no = 0;
      break;
    case 0xA:
      npc->act_no = 11;
      npc->ani_no = 9;
      break;
    case 0x14:
      gSuperXpos = 0;
      npc->act_no = 21;
      npc->act_wait = 0;
      npc->ani_no = 0;
      npc->ani_wait = 0;
      goto LABEL_12;
    case 0x15:
LABEL_12:
      npc->xm = 7 * npc->xm / 8;
      npc->ym = 7 * npc->ym / 8;
      if ( ++npc->ani_wait > 20 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 1 )
        npc->ani_no = 0;
      if ( ++npc->act_wait > 100 )
        npc->act_no = 30;
      if ( npc->x >= ::x )
        npc->direct = 0;
      else
        npc->direct = 2;
      break;
    case 0x1E:
      npc->act_no = 31;
      npc->act_wait = 0;
      npc->ani_no = 2;
      npc->count2 = npc->life;
      goto LABEL_22;
    case 0x1F:
LABEL_22:
      if ( ++npc->ani_wait > 1 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 3 )
        npc->ani_no = 2;
      if ( npc->flag & 8 )
        npc->ym = -512;
      if ( npc->x <= unk_81CCFC8 )
        v1 = npc->xm + 32;
      else
        v1 = npc->xm - 32;
      npc->xm = v1;
      if ( npc->y <= ::y )
        v2 = npc->ym + 16;
      else
        v2 = npc->ym - 16;
      npc->ym = v2;
      if ( npc->xm > 512 )
        npc->xm = 512;
      if ( npc->xm < -512 )
        npc->xm = -512;
      if ( npc->ym > 512 )
        npc->ym = 512;
      if ( npc->ym < -512 )
        npc->ym = -512;
      if ( npc->x <= ::x )
        npc->direct = 2;
      else
        npc->direct = 0;
      if ( ++npc->act_wait > 150 && (npc->life < npc->count2 - 20 || gSuperXpos) )
      {
        gSuperXpos = 0;
        npc->act_no = 40;
      }
      if ( unk_81CD028 && npc->act_wait > 250 )
        npc->act_no = 50;
      break;
    case 0x28:
      npc->act_no = 41;
      npc->act_wait = 0;
      npc->xm = 0;
      npc->ym = 0;
      if ( npc->x <= ::x )
        npc->direct = 2;
      else
        npc->direct = 0;
      PlaySoundObject(103, 1);
      if ( ::y > 81919 )
        npc->count2 = 289;
      else
        npc->count2 = 290;
      goto LABEL_58;
    case 0x29:
LABEL_58:
      if ( ++npc->act_wait / 2 & 1 )
        npc->ani_no = 4;
      else
        npc->ani_no = 5;
      if ( npc->act_wait % 6 == 1 )
      {
        if ( npc->count2 == 289 )
        {
          v3 = npc->x;
          x = v3 + (Random(-64, 64) << 9);
          v4 = npc->y;
          y = v4 + (Random(-32, 32) << 9);
        }
        else
        {
          v5 = npc->x;
          x = v5 + (Random(-32, 32) << 9);
          v6 = npc->y;
          y = v6 + (Random(-64, 64) << 9);
        }
        if ( x <= 0x3FFF )
          x = 0x4000;
        if ( (gMap.width - 2) << 13 < x )
          x = (gMap.width - 2) << 13;
        if ( y <= 0x3FFF )
          y = 0x4000;
        if ( (gMap.length - 2) << 13 < y )
          y = (gMap.length - 2) << 13;
        PlaySoundObject(39, 1);
        SetNpChar(npc->count2, x, y, 0, 0, 0, 0, 256);
      }
      if ( npc->act_wait > 50 )
      {
        npc->act_no = 42;
        npc->act_wait = 0;
        if ( npc->x <= ::x )
          npc->direct = 2;
        else
          npc->direct = 0;
      }
      break;
    case 0x2A:
      ++npc->act_wait;
      npc->ani_no = 6;
      if ( npc->act_wait > 50 )
      {
        npc->ym = -512;
        if ( npc->direct )
          npc->xm = -512;
        else
          npc->xm = 512;
        npc->act_no = 30;
      }
      break;
    case 0x32:
      npc->act_no = 51;
      npc->act_wait = 0;
      npc->xm = 0;
      npc->ym = 0;
      if ( npc->x <= ::x )
        npc->direct = 2;
      else
        npc->direct = 0;
      PlaySoundObject(103, 1);
      goto LABEL_87;
    case 0x33:
LABEL_87:
      if ( ++npc->act_wait / 2 & 1 )
        npc->ani_no = 4;
      else
        npc->ani_no = 5;
      if ( unk_81C8598 & 0x20 )
      {
        if ( npc->act_wait % 10 == 1 )
        {
          if ( npc->direct )
          {
            x = npc->x - 5120;
            y = npc->y;
            v8 = npc->act_wait / 6 % 4;
            if ( v8 == 1 )
            {
              direct = 108;
            }
            else if ( v8 > 1 )
            {
              if ( v8 == 2 )
              {
                direct = 148;
              }
              else if ( v8 == 3 )
              {
                direct = 168;
              }
            }
            else if ( !v8 )
            {
              direct = 88;
            }
          }
          else
          {
            x = npc->x + 5120;
            y = npc->y;
            v7 = npc->act_wait / 6 % 4;
            if ( v7 == 1 )
            {
              direct = 236;
            }
            else if ( v7 > 1 )
            {
              if ( v7 == 2 )
              {
                direct = 20;
              }
              else if ( v7 == 3 )
              {
                direct = 40;
              }
            }
            else if ( !v7 )
            {
              direct = 216;
            }
          }
          PlaySoundObject(39, 1);
          SetNpChar(301, x, y, 0, 0, direct, 0, 256);
        }
      }
      else if ( npc->act_wait % 24 == 1 )
      {
        if ( npc->direct )
        {
          x = npc->x - 5120;
          y = npc->y;
          v10 = npc->act_wait / 6 % 4;
          if ( v10 == 1 )
          {
            direct = 108;
          }
          else if ( v10 > 1 )
          {
            if ( v10 == 2 )
            {
              direct = 148;
            }
            else if ( v10 == 3 )
            {
              direct = 168;
            }
          }
          else if ( !v10 )
          {
            direct = 88;
          }
        }
        else
        {
          x = npc->x + 5120;
          y = npc->y;
          v9 = npc->act_wait / 6 % 4;
          if ( v9 == 1 )
          {
            direct = 236;
          }
          else if ( v9 > 1 )
          {
            if ( v9 == 2 )
            {
              direct = 20;
            }
            else if ( v9 == 3 )
            {
              direct = 40;
            }
          }
          else if ( !v9 )
          {
            direct = 216;
          }
        }
        PlaySoundObject(39, 1);
        SetNpChar(301, x, y, 0, 0, direct, 0, 256);
      }
      if ( npc->act_wait > 50 )
      {
        npc->act_no = 42;
        npc->act_wait = 0;
        if ( npc->x <= ::x )
          npc->direct = 2;
        else
          npc->direct = 0;
      }
      break;
    case 0x63:
      npc->xm = 0;
      npc->ym = 0;
      npc->ani_no = 9;
      npc->bits &= 0xFFDFu;
      break;
    case 0x64:
      npc->act_no = 101;
      npc->ani_no = 9;
      npc->damage = 0;
      npc->bits &= 0xFFDFu;
      npc->bits |= 8u;
      npc->ym = -512;
      npc->shock += 50;
      npc->hit.bottom = 6144;
      ++unk_81CD028;
      goto LABEL_147;
    case 0x65:
LABEL_147:
      npc->ym += 32;
      if ( npc->y > 110592 - npc->hit.bottom )
      {
        npc->y = 110592 - npc->hit.bottom;
        npc->act_no = 102;
        npc->ani_no = 10;
        npc->xm = 0;
        npc->ym = 0;
      }
      break;
    default:
      break;
  }
  npc->y += npc->ym;
  if ( npc->shock )
  {
    v11 = npc->x;
    v12 = npc->xm / 2;
  }
  else
  {
    v11 = npc->x;
    v12 = npc->xm;
  }
  npc->x = v12 + v11;
  if ( npc->direct )
  {
    v13 = npc;
    v14 = (Sint32 *)&v20[16 * npc->ani_no - 364];
  }
  else
  {
    v13 = npc;
    v14 = (Sint32 *)&v20[16 * npc->ani_no - 188];
  }
  npc->rect.left = *v14;
  v13->rect.top = v14[1];
  v13->rect.right = v14[2];
  v13->rect.bottom = v14[3];
}


void __cdecl ActNpc284(NPCHAR_0 *npc)
{
  int v1;
  int v2;
  int v3;
  NPCHAR_0 *v4;
  Sint32 *v5;
  RECT rcRight[13];
  RECT rcLeft[13];
  unsigned __int8 deg;
  char v9[24];

  qmemcpy(rcLeft, &ActNpc284(NPCHAR *)::C.4, sizeof(rcLeft));
  qmemcpy(rcRight, &ActNpc284(NPCHAR *)::C.5, sizeof(rcRight));
  if ( npc->act_no <= 99 && (!gBoss[0].cond || npc->life <= 499) )
    npc->act_no = 100;
  switch ( npc->act_no )
  {
    case 0:
      npc->act_no = 1;
      npc->y -= 2048;
      PlaySoundObject(29, 1);
      npc->count2 = npc->life;
      goto LABEL_7;
    case 1:
LABEL_7:
      if ( ++npc->act_wait / 2 & 1 )
      {
        npc->view.top = 0x2000;
        npc->view.back = 0x2000;
        npc->view.front = 0x2000;
        npc->ani_no = 11;
      }
      else
      {
        npc->view.top = 1536;
        npc->view.back = 4096;
        npc->view.front = 4096;
        npc->ani_no = 12;
      }
      if ( npc->act_wait > 50 )
        npc->act_no = 10;
      break;
    case 0xA:
      npc->act_no = 11;
      npc->ani_no = 11;
      npc->view.top = 0x2000;
      npc->view.back = 0x2000;
      npc->view.front = 0x2000;
      DeleteNpCharCode(257, 1);
      break;
    case 0x14:
      npc->act_no = 21;
      npc->act_wait = 0;
      npc->ani_no = 0;
      npc->ani_wait = 0;
      npc->damage = 0;
      npc->bits |= 0x20u;
      npc->bits &= 0xFFF7u;
      goto LABEL_14;
    case 0x15:
LABEL_14:
      npc->xm = 7 * npc->xm / 8;
      npc->ym = 7 * npc->ym / 8;
      if ( ++npc->ani_wait > 20 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 1 )
        npc->ani_no = 0;
      if ( ++npc->act_wait > 80 )
        npc->act_no = 30;
      if ( npc->x >= x )
        npc->direct = 0;
      else
        npc->direct = 2;
      if ( npc->life < npc->count2 - 50 )
      {
        npc->count2 = npc->life;
        gSuperXpos = 10;
      }
      break;
    case 0x1E:
      npc->act_no = 31;
      npc->act_wait = 0;
      npc->ani_no = 2;
      npc->xm = 0;
      npc->ym = 0;
      goto LABEL_26;
    case 0x1F:
LABEL_26:
      if ( ++npc->act_wait <= 16 )
        break;
      ++npc->count1;
      npc->count1 %= 4;
      v1 = npc->count1;
      if ( v1 == 1 )
        goto LABEL_33;
      if ( v1 > 1 )
      {
        if ( v1 == 2 )
        {
          npc->act_no = 32;
        }
        else if ( v1 == 3 )
        {
LABEL_33:
          npc->act_no = 34;
        }
      }
      else if ( !v1 )
      {
        npc->act_no = 32;
      }
      break;
    case 0x20:
      npc->act_no = 33;
      npc->act_wait = 0;
      npc->bits &= 0xFFDFu;
      if ( x >= npc->x )
        npc->tgt_x = x + 81920;
      else
        npc->tgt_x = x - 81920;
      npc->tgt_y = y;
      deg = GetArktan(npc->x - npc->tgt_x, npc->y - npc->tgt_y);
      npc->xm = 3 * GetCos(deg);
      npc->ym = 3 * GetSin(deg);
      npc->bits &= 0xFFF7u;
      if ( npc->x < gMap.width / 0x80000 >> 1 && npc->xm > 0 )
      {
        if ( npc->y < gMap.length / 0x80000 >> 1 && npc->ym > 0 )
          npc->bits |= 8u;
        if ( npc->y > gMap.length / 0x80000 >> 1 && npc->ym < 0 )
          npc->bits |= 8u;
      }
      if ( npc->x > gMap.width / 0x80000 >> 1 && npc->xm < 0 )
      {
        if ( npc->y < gMap.length / 0x80000 >> 1 && npc->ym > 0 )
          npc->bits |= 8u;
        if ( npc->y > gMap.length / 0x80000 >> 1 && npc->ym < 0 )
          npc->bits |= 8u;
      }
      if ( npc->xm <= 0 )
        npc->direct = 0;
      else
        npc->direct = 2;
      goto LABEL_59;
    case 0x21:
LABEL_59:
      if ( ++npc->act_wait / 2 & 1 )
        npc->ani_no = 3;
      else
        npc->ani_no = 8;
      if ( npc->act_wait > 50 || npc->flag & 5 )
        npc->act_no = 20;
      break;
    case 0x22:
      npc->act_no = 35;
      npc->act_wait = 0;
      npc->damage = 4;
      npc->tgt_x = x;
      npc->tgt_y = y;
      deg = GetArktan(npc->x - npc->tgt_x, npc->y - npc->tgt_y);
      npc->ym = 3 * GetSin(deg);
      npc->xm = 3 * GetCos(deg);
      npc->bits &= 0xFFF7u;
      if ( npc->x < gMap.width / 0x80000 >> 1 && npc->xm > 0 )
      {
        if ( npc->y < gMap.length / 0x80000 >> 1 && npc->ym > 0 )
          npc->bits |= 8u;
        if ( npc->y > gMap.length / 0x80000 >> 1 && npc->ym < 0 )
          npc->bits |= 8u;
      }
      if ( npc->x > gMap.width / 0x80000 >> 1 && npc->xm < 0 )
      {
        if ( npc->y < gMap.length / 0x80000 >> 1 && npc->ym > 0 )
          npc->bits |= 8u;
        if ( npc->y > gMap.length / 0x80000 >> 1 && npc->ym < 0 )
          npc->bits |= 8u;
      }
      if ( npc->xm <= 0 )
        npc->direct = 0;
      else
        npc->direct = 2;
      goto LABEL_84;
    case 0x23:
LABEL_84:
      if ( ++npc->act_wait > 20 && npc->shock )
      {
        npc->act_no = 40;
      }
      else if ( npc->act_wait > 50 || npc->flag & 5 )
      {
        npc->act_no = 20;
      }
      if ( ++npc->ani_wait > 1 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 7 )
        npc->ani_no = 4;
      if ( npc->act_wait % 5 == 1 )
        PlaySoundObject(109, 1);
      break;
    case 0x28:
      npc->act_no = 41;
      npc->act_wait = 0;
      npc->ani_no = 2;
      npc->damage = 0;
      npc->bits &= 0xFFF7u;
      goto LABEL_97;
    case 0x29:
LABEL_97:
      npc->xm = 7 * npc->xm / 8;
      npc->ym = 7 * npc->ym / 8;
      if ( ++npc->act_wait > 6 )
      {
        npc->act_no = 42;
        npc->act_wait = 0;
        npc->ym = -512;
        if ( npc->direct )
          npc->xm = -512;
        else
          npc->xm = 512;
      }
      break;
    case 0x2A:
      npc->ani_no = 9;
      if ( npc->flag & 8 )
      {
        npc->act_no = 43;
        npc->act_wait = 0;
        npc->ani_no = 2;
        if ( npc->x >= x )
          npc->direct = 0;
        else
          npc->direct = 2;
      }
      npc->ym += 32;
      if ( npc->ym > 1535 )
        npc->ym = 1535;
      break;
    case 0x2B:
      if ( ++npc->act_wait > 16 )
        npc->act_no = 20;
      break;
    case 0x63:
      npc->xm = 0;
      npc->ym = 0;
      npc->ani_no = 9;
      npc->bits &= 0xFFDFu;
      break;
    case 0x64:
      npc->act_no = 101;
      npc->ani_no = 9;
      npc->damage = 0;
      npc->bits &= 0xFFDFu;
      npc->bits |= 8u;
      npc->ym = -512;
      npc->shock += 50;
      ++unk_81CD028;
      goto LABEL_111;
    case 0x65:
LABEL_111:
      npc->ym += 32;
      if ( npc->y > 110592 - npc->hit.bottom )
      {
        npc->y = 110592 - npc->hit.bottom;
        npc->act_no = 102;
        npc->ani_no = 10;
        npc->xm = 0;
        npc->ym = 0;
      }
      break;
    default:
      break;
  }
  npc->y += npc->ym;
  if ( npc->shock )
  {
    v2 = npc->x;
    v3 = npc->xm / 2;
  }
  else
  {
    v2 = npc->x;
    v3 = npc->xm;
  }
  npc->x = v3 + v2;
  if ( npc->direct )
  {
    v4 = npc;
    v5 = (Sint32 *)&v9[16 * npc->ani_no - 420];
  }
  else
  {
    v4 = npc;
    v5 = (Sint32 *)&v9[16 * npc->ani_no - 212];
  }
  npc->rect.left = *v5;
  v4->rect.top = v5[1];
  v4->rect.right = v5[2];
  v4->rect.bottom = v5[3];
}


void __cdecl ActNpc285(NPCHAR_0 *npc)
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
    npc->count1 += 24;
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
    npc->x = v3 + 4 * GetCos(deg);
    v4 = npc->tgt_y;
    npc->y = v4 + 6 * GetSin(deg);
    SetNpChar(286, npc->x, npc->y, 0, 0, 0, 0, 256);
  }
  npc->rect.left = 232;
  npc->rect.top = 104;
  npc->rect.right = 248;
  npc->rect.bottom = 120;
}

void __cdecl ActNpc286(NPCHAR_0 *npc)
{
  RECT *v1;
  RECT rc[3];

  rc[0].left = 232;
  rc[0].top = 120;
  rc[0].right = 248;
  rc[0].bottom = 136;
  rc[1].left = 232;
  rc[1].top = 136;
  rc[1].right = 248;
  rc[1].bottom = 152;
  rc[2].left = 232;
  rc[2].top = 152;
  rc[2].right = 248;
  rc[2].bottom = 168;
  if ( ++npc->ani_wait > 0 )
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

void __cdecl ActNpc287(NPCHAR_0 *npc)
{
  Sint32 *v1;
  RECT rcLeft[7];
  char v3[24];

  qmemcpy(rcLeft, &ActNpc287(NPCHAR *)::C.8, sizeof(rcLeft));
  if ( npc->act_no )
  {
    npc->xm = 20 * npc->xm / 21;
    npc->ym = 20 * npc->ym / 21;
    npc->x += npc->xm;
    npc->y += npc->ym;
  }
  else
  {
    npc->xm = Random(-4, 4) << 9;
    npc->act_no = 1;
  }
  if ( ++npc->ani_wait > 1 )
  {
    npc->ani_wait = 0;
    ++npc->ani_no;
  }
  if ( npc->ani_no <= 6 )
  {
    v1 = (Sint32 *)&v3[16 * npc->ani_no - 112];
    npc->rect.left = *v1;
    npc->rect.top = v1[1];
    npc->rect.right = v1[2];
    npc->rect.bottom = v1[3];
  }
  else
  {
    npc->cond = 0;
  }
}


void __cdecl ActNpc288(NPCHAR_0 *npc)
{
  int v1;
  Sint32 *v2;
  RECT rc[5];
  char v4[24];

  qmemcpy(rc, &ActNpc288(NPCHAR *)::C.9, sizeof(rc));
  v1 = npc->act_no;
  if ( v1 == 1 )
  {
LABEL_9:
    if ( npc->direct == 1 )
    {
      npc->ym -= 32;
      if ( npc->ym < -1535 )
        npc->ym = -1535;
      if ( npc->flag & 2 )
        npc->act_no = 2;
    }
    else if ( npc->direct == 3 )
    {
      npc->ym += 32;
      if ( npc->ym > 1535 )
        npc->ym = 1535;
      if ( npc->flag & 8 )
        npc->act_no = 2;
    }
    if ( ++npc->ani_wait > 3 )
    {
      npc->ani_wait = 0;
      ++npc->ani_no;
    }
    if ( npc->ani_no > 1 )
      npc->ani_no = 0;
    goto LABEL_36;
  }
  if ( v1 <= 1 )
  {
    if ( v1 )
      goto LABEL_36;
    npc->act_no = 1;
    npc->xm = -512;
    goto LABEL_9;
  }
  if ( v1 == 2 )
  {
    PlaySoundObject(44, 1);
    npc->act_no = 3;
    npc->act_wait = 0;
    npc->bits |= 8u;
    npc->ym = 0;
    if ( npc->x <= x )
      npc->xm = 1024;
    else
      npc->xm = -1024;
    npc->view.back = 6144;
    npc->view.front = 6144;
    npc->view.top = 6144;
    npc->view.bottom = 6144;
  }
  else if ( v1 != 3 )
  {
    goto LABEL_36;
  }
  if ( ++npc->ani_no > 4 )
    npc->ani_no = 2;
  if ( ++npc->act_wait % 4 == 1 )
  {
    if ( npc->direct == 1 )
      SetNpChar(287, npc->x, npc->y, 0, 1024, 0, 0, 256);
    else
      SetNpChar(287, npc->x, npc->y, 0, -1024, 0, 0, 256);
  }
  if ( npc->x <= 0x1FFF || npc->x > (gMap.width - 1) << 13 )
    npc->cond = 0;
LABEL_36:
  npc->x += npc->xm;
  npc->y += npc->ym;
  v2 = (Sint32 *)&v4[16 * npc->ani_no - 80];
  npc->rect.left = *v2;
  npc->rect.top = v2[1];
  npc->rect.right = v2[2];
  npc->rect.bottom = v2[3];
}


void __cdecl ActNpc289(NPCHAR_0 *npc)
{
  NPCHAR_0 *v1;
  Sint32 *v2;
  RECT rcRight[3];
  RECT rcLeft[3];
  char v5[8];

  rcLeft[0].left = 160;
  rcLeft[0].top = 32;
  rcLeft[0].right = 176;
  rcLeft[0].bottom = 48;
  rcLeft[1].left = 176;
  rcLeft[1].top = 32;
  rcLeft[1].right = 192;
  rcLeft[1].bottom = 48;
  rcLeft[2].left = 192;
  rcLeft[2].top = 32;
  rcLeft[2].right = 208;
  rcLeft[2].bottom = 48;
  rcRight[0].left = 160;
  rcRight[0].top = 48;
  rcRight[0].right = 176;
  rcRight[0].bottom = 64;
  rcRight[1].left = 176;
  rcRight[1].top = 48;
  rcRight[1].right = 192;
  rcRight[1].bottom = 64;
  rcRight[2].left = 192;
  rcRight[2].top = 48;
  rcRight[2].right = 208;
  rcRight[2].bottom = 64;
  switch ( npc->act_no )
  {
    case 0:
      npc->act_no = 1;
      npc->ani_no = 2;
      if ( npc->x <= x )
        npc->direct = 2;
      else
        npc->direct = 0;
      goto LABEL_5;
    case 1:
LABEL_5:
      if ( ++npc->act_wait > 16 )
      {
        npc->act_no = 10;
        npc->view.top = 4096;
        npc->view.bottom = 4096;
        npc->damage = 2;
        npc->bits |= 0x20u;
      }
      goto LABEL_21;
    case 0xA:
      if ( npc->flag & 8 )
      {
        npc->act_no = 11;
        npc->ani_no = 0;
        npc->act_wait = 0;
        npc->xm = 0;
        if ( npc->x <= x )
          npc->direct = 2;
        else
          npc->direct = 0;
      }
      goto LABEL_21;
    case 0xB:
      if ( ++npc->act_wait > 10 )
      {
        if ( ++npc->count1 <= 4 )
          npc->act_no = 10;
        else
          npc->act_no = 12;
        PlaySoundObject(30, 1);
        npc->ym = -1536;
        if ( npc->direct )
          npc->xm = 512;
        else
          npc->xm = -512;
        npc->ani_no = 2;
      }
      goto LABEL_21;
    case 0xC:
      npc->bits |= 8u;
      if ( npc->y <= gMap.length << 13 )
        goto LABEL_21;
      VanishNpChar(npc);
      break;
    default:
LABEL_21:
      if ( npc->act_no > 9 )
        npc->ym += 64;
      if ( npc->ym > 1535 )
        npc->ym = 1535;
      npc->x += npc->xm;
      npc->y += npc->ym;
      if ( npc->direct )
      {
        v1 = npc;
        v2 = (Sint32 *)&v5[16 * npc->ani_no - 96];
      }
      else
      {
        v1 = npc;
        v2 = (Sint32 *)&v5[16 * npc->ani_no - 48];
      }
      npc->rect.left = *v2;
      v1->rect.top = v2[1];
      v1->rect.right = v2[2];
      v1->rect.bottom = v2[3];
      if ( npc->act_no == 1 )
      {
        npc->rect.top += 8 - npc->act_wait / 2;
        npc->rect.bottom += -8 - npc->act_wait / 2;
        npc->view.top = (npc->act_wait << 9) / 2;
        npc->view.bottom = (npc->act_wait << 9) / 2;
      }
      break;
  }
}


void __cdecl ActNpc290(NPCHAR_0 *npc)
{
  int v1;
  int v2;
  int v3;
  NPCHAR_0 *v4;
  Sint32 *v5;
  RECT rcRight[3];
  RECT rcLeft[3];
  char v8[8];

  rcLeft[0].left = 112;
  rcLeft[0].top = 32;
  rcLeft[0].right = 128;
  rcLeft[0].bottom = 48;
  rcLeft[1].left = 128;
  rcLeft[1].top = 32;
  rcLeft[1].right = 144;
  rcLeft[1].bottom = 48;
  rcLeft[2].left = 144;
  rcLeft[2].top = 32;
  rcLeft[2].right = 160;
  rcLeft[2].bottom = 48;
  rcRight[0].left = 112;
  rcRight[0].top = 48;
  rcRight[0].right = 128;
  rcRight[0].bottom = 64;
  rcRight[1].left = 128;
  rcRight[1].top = 48;
  rcRight[1].right = 144;
  rcRight[1].bottom = 64;
  rcRight[2].left = 144;
  rcRight[2].top = 48;
  rcRight[2].right = 160;
  rcRight[2].bottom = 64;
  v1 = npc->act_no;
  switch ( v1 )
  {
    case 1:
LABEL_7:
      if ( ++npc->act_wait > 16 )
      {
        npc->act_no = 10;
        npc->view.top = 4096;
        npc->view.bottom = 4096;
        npc->damage = 2;
        npc->bits |= 0x20u;
        npc->tgt_y = npc->y;
        npc->ym = 1024;
      }
      break;
    case 10:
      if ( ++npc->ani_wait > 2 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 2 )
        npc->ani_no = 0;
      if ( npc->y >= npc->tgt_y )
        v2 = npc->ym - 64;
      else
        v2 = npc->ym + 64;
      npc->ym = v2;
      if ( npc->direct )
        v3 = npc->xm + 16;
      else
        v3 = npc->xm - 16;
      npc->xm = v3;
      if ( npc->x < 0 || npc->y < 0 || npc->x > gMap.width << 13 || npc->y > gMap.length << 13 )
      {
        VanishNpChar(npc);
        return;
      }
      break;
    case 0:
      npc->act_no = 1;
      npc->ani_no = 2;
      if ( npc->x <= x )
        npc->direct = 2;
      else
        npc->direct = 0;
      goto LABEL_7;
  }
  npc->x += npc->xm;
  npc->y += npc->ym;
  if ( npc->direct )
  {
    v4 = npc;
    v5 = (Sint32 *)&v8[16 * npc->ani_no - 96];
  }
  else
  {
    v4 = npc;
    v5 = (Sint32 *)&v8[16 * npc->ani_no - 48];
  }
  npc->rect.left = *v5;
  v4->rect.top = v5[1];
  v4->rect.right = v5[2];
  v4->rect.bottom = v5[3];
  if ( npc->act_no == 1 )
  {
    npc->rect.top += 8 - npc->act_wait / 2;
    npc->rect.bottom += -8 - npc->act_wait / 2;
    npc->view.top = (npc->act_wait << 9) / 2;
    npc->view.bottom = (npc->act_wait << 9) / 2;
  }
}


void __cdecl ActNpc291(NPCHAR_0 *npc)
{
  RECT *v1;
  RECT tc[2];

  tc[0].left = 256;
  tc[0].top = 80;
  tc[0].right = 320;
  tc[0].bottom = 120;
  tc[1].left = 256;
  tc[1].top = 0;
  tc[1].right = 320;
  tc[1].bottom = 40;
  if ( !npc->act_no )
  {
    npc->act_no = 20;
    if ( npc->direct == 2 )
    {
      npc->bits &= 0xFFBFu;
      npc->ani_no = 1;
    }
  }
  v1 = &tc[npc->ani_no];
  npc->rect.left = v1->left;
  npc->rect.top = v1->top;
  npc->rect.right = v1->right;
  npc->rect.bottom = v1->bottom;
}

void __cdecl ActNpc292()
{
  SetQuake(10);
}

void __cdecl ActNpc293(NPCHAR_0 *npc)
{
  int v1;
  int v2;
  int v3;
  int v4;
  int v5;
  Sint32 *v6;
  RECT rect[2];
  char v8[8];

  rect[0].left = 240;
  rect[0].top = 200;
  rect[0].right = 280;
  rect[0].bottom = 240;
  rect[1].left = 280;
  rect[1].top = 200;
  rect[1].right = 320;
  rect[1].bottom = 240;
  v1 = npc->act_no;
  if ( v1 )
  {
    if ( v1 != 1 )
      goto LABEL_9;
  }
  else
  {
    npc->act_no = 1;
  }
  if ( ++npc->ani_no > 1 )
    npc->ani_no = 0;
  v2 = npc->y;
  v3 = (Random(-16, 16) << 9) + v2;
  v4 = npc->x;
  v5 = Random(0, 16);
  SetNpChar(4, v4 + (v5 << 9), v3, 0, 0, 0, 0, 256);
  npc->x -= 4096;
  if ( npc->x < -16384 )
    npc->cond = 0;
LABEL_9:
  v6 = (Sint32 *)&v8[16 * npc->ani_no - 32];
  npc->rect.left = *v6;
  npc->rect.top = v6[1];
  npc->rect.right = v6[2];
  npc->rect.bottom = v6[3];
}


void __cdecl ActNpc294(NPCHAR_0 *npc)
{
  int v1;
  int v2;
  int v3;
  int x;
  int y;

  v1 = npc->act_no;
  if ( v1 )
  {
    if ( v1 == 1 )
    {
      ++npc->act_wait;
      if ( unk_81C8598 & 0x20 )
      {
        npc->x = ::x + 0x8000;
        if ( npc->x <= 212991 )
          npc->x = 212992;
      }
      else
      {
        npc->x = ::x + 49152;
        if ( npc->x <= 188415 )
          npc->x = 188416;
      }
      if ( npc->x > (gMap.width - 10) << 13 )
        npc->x = (gMap.width - 10) << 13;
      if ( npc->act_wait > 24 )
      {
        if ( unk_81C8598 & 0x20 )
        {
          v2 = npc->x;
          x = v2 + (Random(-14, 14) << 13);
        }
        else
        {
          v3 = npc->x;
          x = v3 + (Random(-11, 11) << 13);
        }
        y = ::y - 114688;
        if ( Random(0, 10) & 1 )
          SetNpChar(279, x, y, 0, 0, 0, 0, 256);
        else
          SetNpChar(279, x, y, 0, 0, 2, 0, 256);
        npc->act_wait = Random(0, 15);
      }
    }
  }
  else if ( ::x < (gMap.width - 6) << 13 )
  {
    npc->act_no = 1;
    npc->act_wait = 0;
  }
}

void __cdecl ActNpc295(NPCHAR_0 *npc)
{
  int v1;
  RECT *v2;
  RECT rc[4];

  rc[0].left = 0;
  rc[0].top = 0;
  rc[0].right = 208;
  rc[0].bottom = 64;
  rc[1].left = 32;
  rc[1].top = 64;
  rc[1].right = 144;
  rc[1].bottom = 96;
  rc[2].left = 32;
  rc[2].top = 96;
  rc[2].right = 104;
  rc[2].bottom = 128;
  rc[3].left = 104;
  rc[3].top = 96;
  rc[3].right = 144;
  rc[3].bottom = 128;
  v1 = npc->act_no;
  if ( v1 )
  {
    if ( v1 == 1 )
    {
      npc->x += npc->xm;
      npc->y += npc->ym;
      if ( npc->x < -32768 )
        npc->cond = 0;
      if ( npc->y < -16384 )
        npc->cond = 0;
    }
  }
  else
  {
    npc->act_no = 1;
    npc->ani_no = npc->direct % 4;
    switch ( npc->direct )
    {
      case 0:
        npc->ym = -4096;
        npc->view.back = 53248;
        npc->view.front = 53248;
        break;
      case 1:
        npc->ym = -2048;
        npc->view.back = 28672;
        npc->view.front = 28672;
        break;
      case 2:
        npc->ym = -1024;
        npc->view.back = 0x4000;
        npc->view.front = 0x4000;
        break;
      case 3:
        npc->ym = -512;
        npc->view.back = 10240;
        npc->view.front = 10240;
        break;
      case 4:
        npc->xm = -1024;
        npc->view.back = 53248;
        npc->view.front = 53248;
        break;
      case 5:
        npc->xm = -512;
        npc->view.back = 28672;
        npc->view.front = 28672;
        break;
      case 6:
        npc->xm = -256;
        npc->view.back = 0x4000;
        npc->view.front = 0x4000;
        break;
      case 7:
        npc->xm = -128;
        npc->view.back = 10240;
        npc->view.front = 10240;
        break;
      default:
        break;
    }
  }
  v2 = &rc[npc->ani_no];
  npc->rect.left = v2->left;
  npc->rect.top = v2->top;
  npc->rect.right = v2->right;
  npc->rect.bottom = v2->bottom;
}

void __cdecl ActNpc296(NPCHAR_0 *npc)
{
  int v1;
  int v2;
  int x;
  int v4;
  int v5;
  signed int dir;
  signed int pri;

  if ( ++npc->act_wait > 16 )
  {
    npc->act_wait = Random(0, 16);
    dir = Random(0, 100) % 4;
    if ( npc->direct )
    {
      if ( dir == 1 )
      {
        pri = 85;
      }
      else if ( dir > 1 )
      {
        if ( dir == 2 )
        {
          pri = 64;
        }
        else if ( dir == 3 )
        {
          pri = 0;
        }
      }
      else if ( !dir )
      {
        pri = 128;
      }
      x = npc->x;
      v4 = npc->y;
      v5 = Random(-7, 7);
      SetNpChar(295, x, v4 + (v5 << 13), 0, 0, dir + 4, 0, pri);
    }
    else
    {
      if ( dir == 1 )
      {
        pri = 128;
      }
      else if ( dir > 1 )
      {
        if ( dir == 2 )
        {
          pri = 64;
        }
        else if ( dir == 3 )
        {
          pri = 0;
        }
      }
      else if ( !dir )
      {
        pri = 384;
      }
      v1 = npc->x;
      v2 = Random(-10, 10);
      SetNpChar(295, v1 + (v2 << 13), npc->y, 0, 0, dir, 0, pri);
    }
  }
}

void __cdecl ActNpc297(NPCHAR_0 *npc)
{
  npc->x = npc->pNpc->x + 0x2000;
  npc->y = npc->pNpc->y + 4096;
  npc->rect.left = 112;
  npc->rect.top = 48;
  npc->rect.right = 128;
  npc->rect.bottom = 64;
}

void __cdecl ActNpc298(NPCHAR_0 *npc)
{
  Sint32 *v1;
  RECT rc[8];
  char v3[12];

  qmemcpy(rc, &ActNpc298(NPCHAR *)::C.11, sizeof(rc));
  switch ( npc->act_no )
  {
    case 0:
      npc->act_no = 1;
      npc->y -= 4096;
      goto LABEL_3;
    case 1:
LABEL_3:
      npc->ani_no = 0;
      break;
    case 0xA:
      npc->act_no = 11;
      npc->ani_no = 0;
      npc->ani_wait = 0;
      npc->count1 = 0;
      goto LABEL_5;
    case 0xB:
LABEL_5:
      if ( ++npc->ani_wait > 6 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 1 )
      {
        npc->ani_no = 0;
        if ( ++npc->count1 > 7 )
        {
          npc->ani_no = 0;
          npc->act_no = 1;
        }
      }
      break;
    case 0x14:
      npc->act_no = 21;
      npc->ani_no = 2;
      npc->ani_wait = 0;
      goto LABEL_11;
    case 0x15:
LABEL_11:
      if ( ++npc->ani_wait > 10 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 5 )
        npc->ani_no = 2;
      npc->x += 256;
      break;
    case 0x1E:
      npc->ani_no = 6;
      break;
    case 0x28:
      npc->act_no = 41;
      npc->ani_no = 6;
      npc->ani_wait = 0;
      npc->count1 = 0;
      goto LABEL_18;
    case 0x29:
LABEL_18:
      if ( ++npc->ani_wait > 6 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 7 )
      {
        npc->ani_no = 6;
        if ( ++npc->count1 > 7 )
        {
          npc->ani_no = 6;
          npc->act_no = 30;
        }
      }
      break;
    default:
      break;
  }
  v1 = (Sint32 *)&v3[16 * npc->ani_no - 128];
  npc->rect.left = *v1;
  npc->rect.top = v1[1];
  npc->rect.right = v1[2];
  npc->rect.bottom = v1[3];
}


void __cdecl ActNpc299(NPCHAR_0 *npc)
{
  int v1;
  RECT *v2;
  RECT rc[2];

  rc[0].left = 0;
  rc[0].top = 0;
  rc[0].right = 48;
  rc[0].bottom = 48;
  rc[1].left = 48;
  rc[1].top = 0;
  rc[1].right = 96;
  rc[1].bottom = 48;
  if ( !npc->act_no )
  {
    npc->act_no = 1;
    if ( npc->direct )
    {
      npc->ani_no = 0;
      npc->act_wait = 0;
    }
    else
    {
      npc->ani_no = 1;
      npc->act_wait = 25;
      npc->y -= 1600;
    }
  }
  if ( ++npc->act_wait / 50 & 1 )
    v1 = npc->y + 64;
  else
    v1 = npc->y - 64;
  npc->y = v1;
  v2 = &rc[npc->ani_no];
  npc->rect.left = v2->left;
  npc->rect.top = v2->top;
  npc->rect.right = v2->right;
  npc->rect.bottom = v2->bottom;
}

