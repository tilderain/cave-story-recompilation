#include "types.h"
#include "SDL_stdinc.h"
#include "windows_wrapper.h"
#include "Tags.h"
#include "forNpc.h"
void __cdecl ActNpc340(NPCHAR_0 *npc)
{
  int v1;
  int v2;
  int v3;
  int v4;
  int v5;
  int v6;
  int v7;
  int v8;
  NPCHAR_0 *v9;
  RECT *v10;
  RECT rcRight[11];
  RECT rcLeft[11];
  int i;
  int x;
  RECT *v15;

  v1 = npc->act_no;
  if ( v1 == 221 )
  {
LABEL_108:
    npc->ym = -2048;
    if ( ++npc->act_wait / 2 & 1 )
      npc->ani_no = 8;
    else
      npc->ani_no = 9;
    if ( npc->y <= 24575 )
    {
      npc->y = 24576;
      npc->ym = 0;
      npc->act_no = 222;
      npc->act_wait = 0;
      npc->damage = 3;
      for ( i = 0; i <= 7; ++i )
      {
        v3 = npc->x;
        x = v3 + (Random(-16, 16) << 9);
        SetNpChar(4, x, npc->y - 5120, 0, 0, 0, 0, 256);
      }
      SetNpChar(332, npc->x - 6144, npc->y - 6144, 0, 0, 0, 0, 256);
      SetNpChar(332, npc->x + 6144, npc->y - 6144, 0, 0, 2, 0, 256);
      SetQuake2(10);
      PlaySoundObject(26, 1);
    }
    if ( npc->count1 <= 3 && y > npc->y - 0x2000 && y < npc->y + 0x2000 )
      npc->act_no = 201;
    goto LABEL_217;
  }
  if ( v1 <= 221 )
  {
    if ( v1 == 200 )
    {
      npc->act_no = 201;
      npc->count1 = 0;
      goto LABEL_70;
    }
    if ( v1 <= 200 )
    {
      if ( v1 == 11 )
      {
LABEL_49:
        if ( ++npc->act_wait > 100 )
          npc->act_no = 100;
        goto LABEL_217;
      }
      if ( v1 <= 11 )
      {
        if ( v1 == 1 )
          goto LABEL_217;
        if ( v1 != 10 )
        {
          if ( !v1 )
          {
            npc->act_no = 1;
            npc->cond = -128;
            npc->exp = 1;
            npc->direct = 0;
            npc->y -= 3072;
            npc->damage = 0;
            SetNpChar(341, npc->x, npc->y - 0x2000, 0, 0, 0, npc, 256);
          }
          goto LABEL_217;
        }
        npc->act_no = 11;
        npc->act_wait = 0;
        goto LABEL_49;
      }
      if ( v1 != 110 )
      {
        if ( v1 == 111 )
        {
LABEL_53:
          if ( ++npc->ani_wait > 10 )
          {
            npc->ani_wait = 0;
            ++npc->ani_no;
          }
          if ( npc->ani_no > 2 )
            npc->ani_no = 1;
          ++npc->act_wait;
          if ( npc->life < npc->tgt_x - 50 || npc->act_wait > 150 )
          {
            v2 = npc->count2 % 5;
            if ( v2 >= 0 )
            {
              if ( v2 <= 3 )
              {
                npc->act_no = 200;
              }
              else if ( v2 == 4 )
              {
                npc->act_no = 300;
              }
            }
            ++npc->count2;
          }
          if ( ::x >= npc->x )
            npc->direct = 2;
          else
            npc->direct = 0;
          goto LABEL_217;
        }
        if ( v1 != 100 )
          goto LABEL_217;
        npc->act_no = 110;
        npc->act_wait = 0;
        npc->ani_no = 1;
        npc->ani_wait = 0;
        npc->damage = 4;
        npc->bits |= 0x20u;
      }
      npc->act_no = 111;
      npc->damage = 3;
      npc->tgt_x = npc->life;
      goto LABEL_53;
    }
    if ( v1 == 210 )
    {
      npc->act_no = 211;
      npc->act_wait = 0;
      npc->ani_no = 6;
      npc->ani_wait = 0;
      npc->ym = 0;
      npc->damage = 10;
      if ( ::x >= npc->x )
        npc->direct = 2;
      else
        npc->direct = 0;
      PlaySoundObject(25, 1);
LABEL_87:
      if ( npc->direct )
        npc->xm = 2048;
      else
        npc->xm = -2048;
      if ( ++npc->act_wait / 2 & 1 )
        npc->ani_no = 6;
      else
        npc->ani_no = 7;
      if ( !npc->direct && npc->flag & 1 )
      {
        npc->act_no = 212;
        npc->act_wait = 0;
        npc->damage = 3;
        SetQuake2(10);
        PlaySoundObject(26, 1);
      }
      if ( npc->direct == 2 && npc->flag & 4 )
      {
        npc->act_no = 212;
        npc->act_wait = 0;
        npc->damage = 3;
        SetQuake2(10);
        PlaySoundObject(26, 1);
      }
      if ( npc->count1 <= 3 && ::x > npc->x - 0x2000 && ::x < npc->x + 0x2000 )
        npc->act_no = 201;
      goto LABEL_217;
    }
    if ( v1 <= 210 )
    {
      if ( v1 == 202 )
        goto LABEL_74;
      if ( v1 >= 202 )
      {
        if ( v1 == 203 )
        {
          npc->xm = 8 * npc->xm / 9;
          npc->ym = 8 * npc->ym / 9;
          if ( ++npc->act_wait > 20 )
          {
            if ( y >= npc->y + 6144 )
              npc->act_no = 230;
            else
              npc->act_no = 220;
          }
        }
        goto LABEL_217;
      }
LABEL_70:
      if ( npc->xm )
        npc->act_no = 203;
      else
        npc->act_no = 202;
      npc->act_wait = 0;
      npc->ani_no = 3;
      npc->damage = 3;
      ++npc->count1;
LABEL_74:
      if ( ::x >= npc->x )
        npc->direct = 2;
      else
        npc->direct = 0;
      npc->xm = 8 * npc->xm / 9;
      npc->ym = 8 * npc->ym / 9;
      if ( ++npc->act_wait > 20 )
        npc->act_no = 210;
      goto LABEL_217;
    }
    if ( v1 != 212 )
    {
      if ( v1 >= 212 )
      {
        if ( v1 != 220 )
          goto LABEL_217;
        npc->act_no = 221;
        npc->act_wait = 0;
        npc->ani_no = 8;
        npc->ani_wait = 0;
        npc->xm = 0;
        npc->damage = 10;
        npc->direct = 0;
        PlaySoundObject(25, 1);
        goto LABEL_108;
      }
      goto LABEL_87;
    }
    ++npc->act_wait;
    npc->xm = 0;
    npc->ani_no = 6;
    if ( npc->act_wait > 30 )
    {
      if ( npc->count1 <= 3 )
        npc->act_no = 201;
      else
        npc->act_no = 240;
    }
    goto LABEL_217;
  }
  if ( v1 == 300 )
  {
    npc->act_no = 310;
    npc->act_wait = 0;
    npc->ym = -1536;
    if ( npc->x <= 163840 )
      npc->direct = 0;
    else
      npc->direct = 2;
    npc->tgt_x = ::x;
    npc->tgt_y = 90112;
    npc->ani_wait = 0;
LABEL_160:
    ++npc->ani_wait;
    if ( ++npc->act_wait <= 200 || npc->ani_wait > 19 )
      npc->direct = 0;
    else
      npc->direct = 2;
    if ( npc->ani_wait / 2 & 1 )
      npc->ani_no = 4;
    else
      npc->ani_no = 5;
    if ( npc->x >= npc->tgt_x )
      v5 = npc->xm - 64;
    else
      v5 = npc->xm + 64;
    npc->xm = v5;
    if ( npc->y >= npc->tgt_y )
      v6 = npc->ym - 64;
    else
      v6 = npc->ym + 64;
    npc->ym = v6;
    if ( npc->xm > 1024 )
      npc->xm = 1024;
    if ( npc->xm < -1024 )
      npc->xm = -1024;
    if ( npc->ym > 1024 )
      npc->ym = 1024;
    if ( npc->ym < -1024 )
      npc->ym = -1024;
    if ( npc->act_wait > 200 && npc->act_wait % 40 == 1 )
    {
      npc->ani_wait = 0;
      SetNpChar(333, ::x, 155648, 0, 0, 0, 0, 256);
    }
    if ( npc->act_wait > 480 )
    {
      npc->act_no = 320;
      npc->act_wait = 0;
    }
    goto LABEL_217;
  }
  if ( v1 > 300 )
  {
    if ( v1 != 1001 )
    {
      if ( v1 > 1001 )
      {
        if ( v1 == 1003 )
        {
          if ( ++npc->act_wait > 30 )
          {
            npc->act_wait = 0;
            npc->act_no = 1004;
            npc->ani_no = 3;
            npc->ym -= 2560;
            npc->direct = 0;
            npc->bits |= 8u;
          }
        }
        else if ( v1 < 1003 )
        {
          if ( ++npc->act_wait > 150 )
          {
            npc->act_wait = 0;
            npc->act_no = 1003;
            npc->ani_no = 3;
          }
          if ( npc->act_wait / 2 & 1 )
            v8 = npc->tgt_x + 512;
          else
            v8 = npc->tgt_x - 512;
          npc->x = v8;
        }
        else if ( v1 == 1004 )
        {
          if ( npc->y < 0 )
          {
            npc->xm = 0;
            npc->ym = 0;
            npc->act_no = 1005;
            npc->act_wait = 0;
            SetFlash(0, 0, 2);
            PlaySoundObject(29, 1);
          }
          if ( ++npc->act_wait / 2 & 1 )
            npc->ani_no = 8;
          else
            npc->ani_no = 9;
        }
        goto LABEL_217;
      }
      if ( v1 == 320 )
      {
        npc->xm = 0;
        npc->ym = 0;
        npc->direct = 2;
        if ( ++npc->act_wait == 40 )
          SetFlash(0, 0, 2);
        if ( npc->act_wait > 50 && npc->act_wait % 10 == 1 )
        {
          x = (4 * (npc->act_wait - 50) / 10 + 2) << 13;
          SetNpChar(333, x, 155648, 0, 0, 0, 0, 256);
        }
        if ( npc->act_wait > 140 )
          npc->act_no = 240;
        if ( ++npc->ani_wait / 2 & 1 )
          npc->ani_no = 4;
        else
          npc->ani_no = 5;
        goto LABEL_217;
      }
      if ( v1 != 1000 )
      {
        if ( v1 != 310 )
          goto LABEL_217;
        goto LABEL_160;
      }
      npc->act_no = 1001;
      npc->act_wait = 0;
      npc->ani_no = 10;
      npc->tgt_x = npc->x;
      npc->xm = 0;
      npc->bits &= 0xFFDFu;
      SetDestroyNpChar(npc->x, npc->y, 16, 16);
      PlaySoundObject(72, 1);
    }
    npc->ym += 32;
    if ( npc->ym > 1535 )
      npc->ym = 1535;
    if ( ++npc->act_wait / 2 & 1 )
      v7 = npc->tgt_x + 512;
    else
      v7 = npc->tgt_x - 512;
    npc->x = v7;
    if ( npc->flag & 8 )
    {
      npc->act_no = 1002;
      npc->act_wait = 0;
    }
    goto LABEL_217;
  }
  if ( v1 == 232 )
  {
    ++npc->act_wait;
    npc->xm = 0;
    npc->ani_no = 3;
    if ( npc->act_wait > 30 )
    {
      if ( npc->count1 <= 3 )
        npc->act_no = 201;
      else
        npc->act_no = 242;
    }
  }
  else
  {
    if ( v1 > 232 )
    {
      if ( v1 != 241 )
      {
        if ( v1 == 242 )
        {
          npc->xm = 3 * npc->xm / 4;
          npc->ani_no = 3;
          if ( ++npc->act_wait > 10 )
            npc->act_no = 110;
          goto LABEL_217;
        }
        if ( v1 != 240 )
          goto LABEL_217;
        npc->act_no = 241;
        npc->direct = 0;
      }
      npc->ym += 128;
      if ( npc->ym > 1535 )
        npc->ym = 1535;
      if ( ++npc->ani_wait / 2 & 1 )
        npc->ani_no = 4;
      else
        npc->ani_no = 5;
      if ( npc->flag & 8 )
      {
        npc->act_no = 242;
        npc->act_wait = 0;
        npc->ani_no = 3;
        if ( ::x >= npc->x )
          npc->direct = 2;
        else
          npc->direct = 0;
      }
      goto LABEL_217;
    }
    if ( v1 == 230 )
    {
      npc->act_no = 231;
      npc->act_wait = 0;
      npc->ani_no = 8;
      npc->ani_wait = 0;
      npc->xm = 0;
      npc->damage = 10;
      npc->direct = 2;
      PlaySoundObject(25, 1);
    }
    else if ( v1 <= 230 )
    {
      if ( v1 == 222 )
      {
        ++npc->act_wait;
        npc->xm = 0;
        npc->ani_no = 8;
        if ( npc->act_wait > 30 )
        {
          if ( npc->count1 <= 3 )
            npc->act_no = 201;
          else
            npc->act_no = 240;
        }
      }
      goto LABEL_217;
    }
    npc->ym = 2048;
    if ( ++npc->act_wait / 2 & 1 )
      npc->ani_no = 8;
    else
      npc->ani_no = 9;
    if ( npc->flag & 8 )
    {
      npc->act_no = 232;
      npc->act_wait = 0;
      npc->damage = 3;
      if ( ::x >= npc->x )
        npc->direct = 2;
      else
        npc->direct = 0;
      for ( i = 0; i <= 7; ++i )
      {
        v4 = npc->x;
        x = v4 + (Random(-16, 16) << 9);
        SetNpChar(4, x, npc->y + 5120, 0, 0, 0, 0, 256);
      }
      SetNpChar(332, npc->x - 6144, npc->y + 6144, 0, 0, 0, 0, 256);
      SetNpChar(332, npc->x + 6144, npc->y + 6144, 0, 0, 2, 0, 256);
      SetQuake2(10);
      PlaySoundObject(26, 1);
    }
    if ( npc->count1 <= 3 && y > npc->y - 0x2000 && y < npc->y + 0x2000 )
      npc->act_no = 201;
  }
LABEL_217:
  npc->x += npc->xm;
  npc->y += npc->ym;
  qmemcpy(rcLeft, &ActNpc340(NPCHAR *)::C.0, sizeof(rcLeft));
  qmemcpy(rcRight, &ActNpc340(NPCHAR *)::C.1, sizeof(rcRight));
  if ( npc->direct )
  {
    v9 = npc;
    v10 = (RECT *)(&v15 + 4 * npc->ani_no - 90);
  }
  else
  {
    v9 = npc;
    v10 = (RECT *)(&v15 + 4 * npc->ani_no - 46);
  }
  npc->rect.left = v10->left;
  v9->rect.top = v10->top;
  v9->rect.right = v10->right;
  v9->rect.bottom = v10->bottom;
}

void __cdecl ActNpc341(NPCHAR_0 *npc)
{
  RECT *v1;
  RECT rc[3];

  rc[0].left = 288;
  rc[0].top = 32;
  rc[0].right = 320;
  rc[0].bottom = 48;
  rc[1].left = 288;
  rc[1].top = 48;
  rc[1].right = 320;
  rc[1].bottom = 64;
  rc[2].left = 288;
  rc[2].top = 64;
  rc[2].right = 320;
  rc[2].bottom = 80;
  if ( npc->pNpc->act_no == 11 && npc->pNpc->act_wait > 50 )
    ++npc->ani_wait;
  if ( npc->ani_wait > 4 )
  {
    npc->ani_wait = 0;
    if ( npc->ani_no <= 1 )
      ++npc->ani_no;
  }
  if ( npc->pNpc->ani_no )
    npc->cond = 0;
  v1 = &rc[npc->ani_no];
  npc->rect.left = v1->left;
  npc->rect.top = v1->top;
  npc->rect.right = v1->right;
  npc->rect.bottom = v1->bottom;
}

void __cdecl ActNpc342(NPCHAR_0 *npc)
{
  int v1;
  int v2;
  int v3;
  int v4;
  Sint32 *v5;
  RECT rc[3];
  unsigned __int8 deg;
  char v8[8];

  rc[0].left = 240;
  rc[0].top = 48;
  rc[0].right = 280;
  rc[0].bottom = 88;
  rc[1].left = 240;
  rc[1].top = 88;
  rc[1].right = 280;
  rc[1].bottom = 128;
  rc[2].left = 280;
  rc[2].top = 48;
  rc[2].right = 320;
  rc[2].bottom = 88;
  if ( npc->act_no <= 999 && npc->pNpc->act_no > 999 )
    npc->act_no = 1000;
  v1 = npc->act_no;
  if ( v1 == 22 )
  {
    npc->ani_no = 2;
    npc->count1 -= 2;
    if ( npc->count1 < 0 )
      npc->count1 += 512;
    if ( npc->pNpc->act_no == 401 )
      npc->act_no = 23;
    goto LABEL_87;
  }
  if ( v1 <= 22 )
  {
    if ( v1 == 11 )
    {
      if ( npc->count2 <= 304 )
        npc->act_no = 12;
      else
        npc->count2 -= 4;
      goto LABEL_87;
    }
    if ( v1 > 11 )
    {
      if ( v1 == 20 )
      {
        npc->act_no = 21;
        npc->bits |= 0x20u;
        npc->life = 1000;
      }
      else if ( v1 <= 20 )
      {
        if ( v1 == 12 && npc->pNpc->act_no == 311 )
          npc->act_no = 20;
        goto LABEL_87;
      }
      npc->count1 -= 2;
      if ( npc->count1 < 0 )
        npc->count1 += 512;
      if ( npc->shock )
      {
        if ( ++ActNpc342(NPCHAR *)::_flash / 2 & 1 )
          npc->ani_no = 1;
        else
          npc->ani_no = 0;
      }
      else
      {
        npc->ani_no = 0;
      }
      if ( npc->life <= 899 )
      {
        npc->act_no = 22;
        npc->bits &= 0xFFDFu;                   // TODO: Hey look, it really was a compiler optimisation
        SetDestroyNpChar(npc->x, npc->y, 0x2000, 32);
        PlaySoundObject(71, 1);
      }
      npc->pNpc->count1 = 4;
      if ( npc->pNpc->act_no == 401 )
        npc->act_no = 23;
      goto LABEL_87;
    }
    if ( v1 )
    {
      if ( v1 != 10 )
        goto LABEL_87;
    }
    else
    {
      npc->act_no = 10;
      npc->count1 = 2 * (npc->direct & 0xFF);
      npc->direct >>= 8;
      npc->count2 = 192;
      npc->damage = 14;
    }
    if ( npc->count2 > 319 )
      npc->act_no = 11;
    else
      npc->count2 += 8;
    goto LABEL_87;
  }
  if ( v1 == 40 )
  {
    npc->act_no = 41;
    npc->xm = 0;
    npc->ym = 0;
    npc->ani_no = 2;
    npc->damage = 5;
    npc->bits &= 0xFFD7u;
    SetDestroyNpChar(npc->x, npc->y, 0x2000, 32);
    PlaySoundObject(71, 1);
    goto LABEL_69;
  }
  if ( v1 <= 40 )
  {
    if ( v1 == 30 )
    {
      npc->act_no = 31;
      npc->life = 1000;
      npc->damage = 10;
      if ( !npc->direct )
        npc->bits |= 0x20u;
      npc->ym = 0;
    }
    else if ( v1 != 31 )
    {
      if ( v1 == 23 )
      {
        npc->ani_no = 2;
        npc->count1 -= 4;
        if ( npc->count1 < 0 )
          npc->count1 += 512;
        if ( npc->pNpc->act_no == 420 )
          npc->act_no = 30;
      }
      goto LABEL_87;
    }
    ++npc->count1;
    npc->count1 %= 512;                         // TODO: More WTF
    if ( npc->count2 > 256 )
      --npc->count2;
    if ( npc->bits & 0x20 )
    {
      if ( npc->shock )
      {
        if ( ++ActNpc342(NPCHAR *)::_flash / 2 & 1 )// Fix me
          npc->ani_no = 1;
        else
          npc->ani_no = 0;
      }
      else
      {
        npc->ani_no = 0;
      }
    }
    else
    {
      npc->ani_no = 2;
    }
    if ( npc->life <= 899 )
      npc->act_no = 40;
    goto LABEL_87;
  }
  switch ( v1 )
  {
    case 1000:
      npc->act_no = 1001;
      npc->xm = 0;
      npc->ym = 0;
      npc->ani_no = 2;
      npc->bits &= 0xFFD7u;
      npc->damage = 0;
      npc->count1 /= 4;
      npc->exp = 0;
      break;
    case 1001:
      break;
    case 41:
LABEL_69:
      if ( npc->flag & 1 )
        npc->xm = 256;
      if ( npc->flag & 4 )
        npc->xm = -256;
      if ( npc->flag & 8 )
      {
        if ( !npc->xm )
        {
          if ( x >= npc->x )
            npc->xm = -256;
          else
            npc->xm = 256;
        }
        npc->ym = -2048;
        PlaySoundObject(26, 1);
      }
      npc->ym += 32;
      if ( npc->ym > 1535 )
        npc->ym = 1535;
      goto LABEL_87;
    default:
      goto LABEL_87;
  }
  if ( npc->count1 <= 0 )
  {
    SetDestroyNpChar(npc->x, npc->y, 0x2000, 32);
    PlaySoundObject(71, 1);
    VanishNpChar(npc);
    return;
  }
  if ( --npc->count1 / 2 & 1 )
    npc->ani_no = 1;
  else
    npc->ani_no = 0;
LABEL_87:
  if ( npc->act_no == 21 || npc->act_no == 22 )
  {
    v2 = npc->pNpc->direct;
    if ( v2 == 1 )
    {
      if ( npc->count1 == 268 )
      {
        SetNpChar(4, npc->x - 6144, npc->y + 4096, 0, 0, 0, 0, 256);
        SetNpChar(4, npc->x - 6144, npc->y - 4096, 0, 0, 0, 0, 256);
        PlaySoundObject(26, 1);
      }
    }
    else if ( v2 > 1 )
    {
      if ( v2 == 2 )
      {
        if ( npc->count1 == 396 )
        {
          SetNpChar(4, npc->x + 4096, npc->y - 6144, 0, 0, 0, 0, 256);
          SetNpChar(4, npc->x - 4096, npc->y - 6144, 0, 0, 0, 0, 256);
          SetNpChar(345, npc->x - 4096, npc->y - 6144, 0, 0, 0, 0, 256);
          PlaySoundObject(26, 1);
        }
      }
      else if ( v2 == 3 && npc->count1 == 12 )
      {
        SetNpChar(4, npc->x + 6144, npc->y + 4096, 0, 0, 0, 0, 256);
        SetNpChar(4, npc->x + 6144, npc->y - 4096, 0, 0, 0, 0, 256);
        PlaySoundObject(26, 1);
      }
    }
    else if ( !v2 && npc->count1 == 140 )
    {
      SetNpChar(4, npc->x + 4096, npc->y + 6144, 0, 0, 0, 0, 256);
      SetNpChar(4, npc->x - 4096, npc->y + 6144, 0, 0, 0, 0, 256);
      PlaySoundObject(26, 1);
    }
  }
  if ( npc->act_no <= 39 )
  {
    deg = npc->count1 / 2;
    v3 = npc->pNpc->x;
    npc->tgt_x = v3 + npc->count2 * GetCos(deg) / 4;
    v4 = npc->pNpc->y;
    npc->tgt_y = v4 + npc->count2 * GetSin(deg) / 4;
    npc->xm = npc->tgt_x - npc->x;
    npc->ym = npc->tgt_y - npc->y;
  }
  npc->x += npc->xm;
  npc->y += npc->ym;
  v5 = (Sint32 *)&v8[16 * npc->ani_no - 52];
  npc->rect.left = *v5;
  npc->rect.top = v5[1];
  npc->rect.right = v5[2];
  npc->rect.bottom = v5[3];
}


void __cdecl ActNpc343(NPCHAR_0 *npc)
{
  npc->rect.left = 0;
  npc->rect.top = 0;
  npc->rect.right = 120;
  npc->rect.bottom = 120;
  if ( ++npc->act_wait > 100 )
    npc->cond = 0;
  npc->x = npc->pNpc->x;
  npc->y = npc->pNpc->y;
}

void __cdecl ActNpc344(NPCHAR_0 *npc)
{
  int v1;

  if ( npc->direct )
  {
    npc->rect.left = 296;
    npc->rect.top = 0;
    npc->rect.right = 320;
    npc->rect.bottom = 16;
    v1 = npc->pNpc->x + 12288;
  }
  else
  {
    npc->rect.left = 272;
    npc->rect.top = 0;
    npc->rect.right = 296;
    npc->rect.bottom = 16;
    v1 = npc->pNpc->x - 12288;
  }
  npc->x = v1;
  if ( ++npc->act_wait > 100 )
    npc->cond = 0;
  npc->y = npc->pNpc->y - 18432;
}

void __cdecl ActNpc345(NPCHAR_0 *npc)
{
  int v1;
  int v2;
  int v3;
  int v4;
  int v5;
  int v6;
  int v7;
  RECT rc[4];
  int i;
  RECT *v10;

  rc[0].left = 128;
  rc[0].top = 176;
  rc[0].right = 144;
  rc[0].bottom = 192;
  rc[1].left = 144;
  rc[1].top = 176;
  rc[1].right = 160;
  rc[1].bottom = 192;
  rc[2].left = 160;
  rc[2].top = 176;
  rc[2].right = 176;
  rc[2].bottom = 192;
  rc[3].left = 176;
  rc[3].top = 176;
  rc[3].right = 192;
  rc[3].bottom = 192;
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
      npc->act_no = 100;
      npc->ani_no = Random(0, 16) % 4;          // TODO: Extra WTF
LABEL_5:
      npc->ym += 64;
      if ( npc->ym > 1792 )
        npc->ym = 1792;
      if ( npc->y > 0x10000 )
        npc->bits &= 0xFFF7u;
      v2 = npc->act_wait;
      npc->act_wait = v2 + 1;
      if ( v2 / 2 & 1 )
        SetNpChar(4, npc->x, npc->y, 0, 0, 0, 0, 256);
      if ( npc->flag & 8 )
      {
        npc->ym = -512;
        npc->act_no = 110;
        npc->bits |= 8u;
        PlaySoundObject(12, 1);
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
      break;
  }
  if ( ++npc->ani_wait > 8 )
  {
    npc->ani_wait = 0;
    ++npc->ani_no;
  }
  if ( npc->ani_no > 3 )
    npc->ani_no = 0;
  npc->y += npc->ym;
  npc->rect = *(RECT *)(&(&v10)[4 * npc->ani_no - 1] - 1);
}

void __cdecl ActNpc346(NPCHAR_0 *npc)
{
  int v1;
  unsigned __int8 deg;
  int v3;
  int v4;
  __int64 v5;

  if ( npc->act_no <= 999 && npc->pNpc->act_no > 999 )
    npc->act_no = 1000;
  v1 = npc->act_no;
  if ( v1 == 30 )
  {
    ++npc->count1;
    npc->count1 %= 1024;
    if ( npc->pNpc->act_no == 425 )
      npc->act_no = 50;
    if ( npc->pNpc->act_no == 427 )
      npc->act_no = 100;
  }
  else if ( v1 > 30 )
  {
    if ( v1 == 100 )
    {
      npc->ani_no = 0;
      if ( npc->pNpc->act_no == 424 )
        npc->act_no = 30;
      if ( npc->pNpc->act_no == 428 )
        npc->act_no = 20;
    }
    else if ( v1 > 100 )
    {
      if ( v1 == 1000 )
      {
        npc->act_no = 1001;
        npc->xm = 0;
        npc->ym = 0;
        npc->bits &= 0xFFBFu;
      }
      else if ( v1 != 1001 )
      {
        goto LABEL_50;
      }
      npc->ym += 64;
      if ( npc->y > gMap.length << 13 )
        npc->cond = 0;
    }
    else if ( v1 == 40 )
    {
      npc->count1 -= 2;
      if ( npc->count1 < 0 )
        npc->count1 += 1024;
      if ( npc->pNpc->act_no == 422 )
        npc->act_no = 20;
    }
    else if ( v1 == 50 )
    {
      npc->count1 += 2;
      npc->count1 %= 1024;
      if ( npc->pNpc->act_no == 426 )
        npc->act_no = 30;
    }
  }
  else
  {
    if ( v1 == 10 )
    {
LABEL_22:
      if ( npc->count2 > 447 )
        npc->act_no = 11;
      else
        npc->count2 += 8;
      goto LABEL_50;
    }
    if ( v1 <= 10 )
    {
      if ( v1 )
        goto LABEL_50;
      npc->act_no = 10;
      npc->count1 = 4 * npc->direct;
      npc->count2 = 192;
      npc->ani_no = 0;
      goto LABEL_22;
    }
    if ( v1 == 11 )
    {
      if ( npc->pNpc->act_no == 411 )
        npc->act_no = 20;
    }
    else if ( v1 == 20 )
    {
      if ( --npc->count1 < 0 )
        npc->count1 += 1024;
      if ( npc->pNpc->act_no == 421 )
        npc->act_no = 40;
      if ( npc->pNpc->act_no == 423 )
        npc->act_no = 100;
    }
  }
LABEL_50:
  if ( npc->act_no <= 999 )
  {
    if ( y <= npc->y - 4096 || unk_81C85B8 >= 0 )
      npc->bits |= 0x40u;
    else
      npc->bits &= 0xFFBFu;
    deg = npc->count1 / 4;
    v3 = npc->pNpc->x;
    npc->tgt_x = v3 + npc->count2 * GetCos(deg) / 4;
    v4 = npc->pNpc->y + 0x2000;
    npc->tgt_y = v4 + npc->count2 * GetSin(deg) / 4;
    npc->xm = npc->tgt_x - npc->x;
    if ( npc->act_no != 20 && npc->act_no != 30 )
    {
      if ( npc->act_no != 40 && npc->act_no != 50 )
      {
        npc->ani_no = npc->tgt_y - npc->y;
      }
      else if ( (npc->count1 / 2 & 1) != 1 )
      {
        npc->ani_no = (npc->tgt_y - npc->y) / 2;
      }
    }
    else if ( !(npc->count1 & 3) )
    {
      v5 = npc->tgt_y - npc->y;
      npc->ani_no = (signed int)((HIDWORD(v5) >> 30) + v5) >> 2;// TODO
    }
    npc->ym = npc->ani_no;
  }
  npc->x += npc->xm;
  npc->y += npc->ym;
  npc->rect.left = 240;
  npc->rect.top = 0;
  npc->rect.right = 272;
  npc->rect.bottom = 16;
}
/* Orphan comments:
TODO: WTF
TODO
*/

void __cdecl ActNpc347(NPCHAR_0 *npc)
{
  RECT rc[4];
  RECT *v2;

  switch ( npc->act_no )
  {
    case 0:
      npc->act_no = 1;
      goto LABEL_3;
    case 1:
LABEL_3:
      npc->ani_no = 0;
      if ( y < npc->y + 0x10000 && y > npc->y - 0x10000 )
      {
        npc->act_no = 10;
        npc->act_wait = 0;
        npc->ani_no = 1;
      }
      break;
    case 0xA:
      if ( ++npc->act_wait == 4 )
        npc->ani_no = 2;
      if ( npc->act_wait > 12 )
      {
        npc->act_no = 12;
        npc->xm = 1792;
        PlaySoundObject(6, 1);
        npc->ani_no = 3;
      }
      break;
    case 0xC:
      if ( y >= npc->y )
        npc->ym = 170;
      else
        npc->ym = -170;
      if ( npc->flag & 1 )
      {
        npc->act_no = 13;
        npc->act_wait = 0;
        npc->ani_no = 2;
        npc->xm = 0;
        npc->ym = 0;
      }
      else
      {
        npc->xm -= 42;
        if ( npc->xm < -1535 )
          npc->xm = -1535;
        npc->x += npc->xm;
        npc->y += npc->ym;
      }
      break;
    case 0xD:
      if ( ++npc->act_wait == 2 )
        npc->ani_no = 1;
      if ( npc->act_wait == 6 )
        npc->ani_no = 0;
      if ( npc->act_wait > 16 )
        npc->act_no = 1;
      break;
    default:
      break;
  }
  rc[0].left = 256;
  rc[0].top = 48;
  rc[0].right = 272;
  rc[0].bottom = 64;
  rc[1].left = 272;
  rc[1].top = 48;
  rc[1].right = 288;
  rc[1].bottom = 64;
  rc[2].left = 288;
  rc[2].top = 48;
  rc[2].right = 304;
  rc[2].bottom = 64;
  rc[3].left = 304;
  rc[3].top = 48;
  rc[3].right = 320;
  rc[3].bottom = 64;
  npc->rect = *(RECT *)&(&v2)[4 * npc->ani_no - 1];
}

void __cdecl ActNpc348(NPCHAR_0 *npc)
{
  int v1;
  RECT *v2;
  RECT rc[2];

  rc[0].left = 128;
  rc[0].top = 152;
  rc[0].right = 160;
  rc[0].bottom = 176;
  rc[1].left = 160;
  rc[1].top = 152;
  rc[1].right = 192;
  rc[1].bottom = 176;
  v1 = npc->act_no;
  if ( v1 )
  {
    if ( v1 != 1 )
      goto LABEL_10;
  }
  else
  {
    npc->act_no = 1;
  }
  if ( ++npc->act_wait > 127 )
  {
    npc->act_no = 10;
    npc->ani_no = 0;
    npc->damage = 2;
  }
  else
  {
    npc->y -= 128;
    if ( npc->act_wait / 2 & 1 )
      npc->ani_no = 1;
    else
      npc->ani_no = 0;
  }
LABEL_10:
  v2 = &rc[npc->ani_no];
  npc->rect.left = v2->left;
  npc->rect.top = v2->top;
  npc->rect.right = v2->right;
  npc->rect.bottom = v2->bottom;
}

void __cdecl ActNpc349(NPCHAR_0 *npc)
{
  if ( !npc->act_no )
  {
    npc->act_no = 1;
    if ( !npc->direct )
      npc->x += 4096;
    if ( npc->direct == 2 )
      npc->y += 0x2000;
  }
  npc->rect.left = 0;
  npc->rect.top = 0;
  npc->rect.right = 16;
  npc->rect.bottom = 16;
}

void __cdecl ActNpc350(NPCHAR_0 *npc)
{
  int v1;
  int v2;
  NPCHAR_0 *v3;
  RECT *v4;
  RECT rcRight[7];
  RECT rcLeft[7];
  RECT *v7;

  qmemcpy(rcLeft, &ActNpc350(NPCHAR *)::C.11, sizeof(rcLeft));
  qmemcpy(rcRight, &ActNpc350(NPCHAR *)::C.12, sizeof(rcRight));
  switch ( npc->act_no )
  {
    case 0:
      npc->act_no = 1;
      if ( npc->direct )
        v1 = npc->x + 0x10000;
      else
        v1 = npc->x - 0x10000;
      npc->tgt_x = v1;
      npc->tgt_y = npc->y;
      npc->ym = 2 * Random(-512, 512);
      npc->xm = 2 * Random(-512, 512);
      goto LABEL_6;
    case 1:
LABEL_6:
      if ( ++npc->ani_wait > 1 )
      {
        npc->ani_wait = 0;
        if ( ++npc->ani_no > 1 )
          npc->ani_no = 0;
      }
      if ( npc->direct )
      {
        if ( npc->x > npc->tgt_x )
          npc->act_no = 20;
      }
      else if ( npc->x < npc->tgt_x )
      {
        npc->act_no = 20;
      }
      goto LABEL_48;
    case 0x14:
      npc->act_no = 21;
      npc->act_wait = Random(0, 150);
      npc->ani_no = 2;
      npc->ani_wait = 0;
      goto LABEL_15;
    case 0x15:
LABEL_15:
      if ( ++npc->ani_wait > 2 )
      {
        npc->ani_wait = 0;
        if ( ++npc->ani_no > 3 )
          npc->ani_no = 2;
      }
      if ( ++npc->act_wait > 300 )
        npc->act_no = 30;
      if ( x < npc->x + 57344 && x > npc->x - 57344 && y < npc->y + 0x2000 && y > npc->y - 0x2000 )
        npc->act_no = 30;
      goto LABEL_48;
    case 0x1E:
      npc->act_no = 31;
      npc->act_wait = 0;
      npc->ani_wait = 0;
      goto LABEL_26;
    case 0x1F:
LABEL_26:
      if ( ++npc->ani_wait / 2 & 1 )
        npc->ani_no = 3;
      else
        npc->ani_no = 4;
      if ( ++npc->act_wait > 30 )
      {
        npc->act_no = 40;
        npc->ani_no = 5;
        if ( npc->direct )
          SetNpChar(312, npc->x, npc->y, 2048, 0, 2, 0, 409);
        else
          SetNpChar(312, npc->x, npc->y, -2048, 0, 0, 0, 409);
      }
      goto LABEL_48;
    case 0x28:
      npc->act_no = 41;
      npc->act_wait = 0;
      npc->ani_wait = 0;
      goto LABEL_34;
    case 0x29:
LABEL_34:
      if ( ++npc->ani_wait > 2 )
      {
        npc->ani_wait = 0;
        if ( ++npc->ani_no > 6 )
          npc->ani_no = 5;
      }
      if ( ++npc->act_wait > 40 )
      {
        npc->act_no = 50;
        npc->ani_no = 0;
        npc->xm = 0;
        npc->ym = 0;
      }
      goto LABEL_48;
    case 0x32:
      if ( ++npc->ani_wait > 1 )
      {
        npc->ani_wait = 0;
        if ( ++npc->ani_no > 1 )
          npc->ani_no = 0;
      }
      if ( npc->direct )
        v2 = npc->xm + 32;
      else
        v2 = npc->xm - 32;
      npc->xm = v2;
      if ( npc->x >= 0 && npc->x <= gMap.width << 13 )
        goto LABEL_48;
      VanishNpChar(npc);
      break;
    default:
LABEL_48:
      if ( npc->act_no <= 49 )
      {
        if ( npc->x < npc->tgt_x )
          npc->xm += 42;
        if ( npc->x > npc->tgt_x )
          npc->xm -= 42;
        if ( npc->y < npc->tgt_y )
          npc->ym += 42;
        if ( npc->y > npc->tgt_y )
          npc->ym -= 42;
        if ( npc->xm > 1024 )
          npc->xm = 1024;
        if ( npc->xm < -1024 )
          npc->xm = -1024;
        if ( npc->ym > 1024 )
          npc->ym = 1024;
        if ( npc->ym < -1024 )
          npc->ym = -1024;
      }
      npc->x += npc->xm;
      npc->y += npc->ym;
      if ( npc->direct )
      {
        v3 = npc;
        v4 = (RECT *)(&v7 + 4 * npc->ani_no - 56);
      }
      else
      {
        v3 = npc;
        v4 = (RECT *)(&v7 + 4 * npc->ani_no - 28);
      }
      npc->rect.left = v4->left;
      v3->rect.top = v4->top;
      v3->rect.right = v4->right;
      v3->rect.bottom = v4->bottom;
      break;
  }
}

void __cdecl ActNpc351(NPCHAR_0 *npc)
{
  RECT rc[9];
  RECT *v2;

  qmemcpy(rc, ActNpc351(NPCHAR *)::C.13, sizeof(rc));
  switch ( npc->act_no )
  {
    case 0:
      npc->act_no = 1;
      npc->ani_no = npc->direct / 10;
      npc->x += 4096;
      npc->y += 6144;
      break;
    case 0xA:
      if ( (unsigned __int8)GetNPCFlag(npc->code_flag) )
      {
        npc->act_no = 20;
      }
      else
      {
        npc->act_no = 11;
        npc->bits |= 0x20u;
      }
      goto LABEL_6;
    case 0xB:
LABEL_6:
      if ( npc->life <= 900 )
      {
        SetNpChar(351, npc->x - 4096, npc->y - 6144, 0, 0, 10 * npc->ani_no + 40, 0, 0);
        npc->cond |= 8u;
      }
      break;
    case 0x14:
      npc->ani_no += 4;
      npc->act_no = 1;
      break;
    default:
      break;
  }
  npc->rect = (RECT)*((_OWORD *)&v2 + npc->ani_no - 9);
}

void __cdecl ActNpc352(NPCHAR_0 *npc)
{
  int v1;
  unsigned int v2;
  unsigned int v3;
  RECT rc[28];
  RECT *v5;

  v1 = npc->act_no;
  if ( v1 )
  {
    if ( v1 != 1 )
      goto LABEL_19;
  }
  else
  {
    npc->act_no = 1;
    npc->ani_no = 0;
    npc->count1 = npc->direct / 100;
    npc->direct %= 100;
    v2 = npc->count1;
    if ( v2 <= 0xD && (1 << v2) & 0x3380 )
      npc->surf = 21;
    v3 = npc->count1;
    if ( v3 <= 0xC && (1 << v3) & 0x1214 )
      npc->view.top = 0x2000;
    if ( npc->count1 == 9 )
    {
      npc->view.back = 10240;
      npc->view.front = 10240;
      npc->x -= 512;
    }
    if ( !npc->count1 )
      SetNpChar(145, 0, 0, 0, 0, 2, npc, 256);
  }
  npc->ym += 64;
  if ( npc->ym > 1535 )
    npc->ym = 1535;
  if ( npc->flag & 8 )
  {
    npc->ym = 0;
    npc->act_no = 2;
    npc->ani_no = 1;
  }
  npc->y += npc->ym;
LABEL_19:
  qmemcpy(rc, ActNpc352(NPCHAR *)::C.15, sizeof(rc));
  npc->rect = *(RECT *)&(&v5)[4 * (npc->ani_no + 2 * npc->count1) - 7];
}

void __cdecl ActNpc353(NPCHAR_0 *npc)
{
  int v1;
  int v2;
  RECT *v3;
  int v4;
  int v5;
  int v6;
  NPCHAR_0 *v7;
  RECT *v8;
  RECT rc[4];
  RECT rcRight[2];
  RECT rcLeft[2];

  rc[0].left = 168;
  rc[0].top = 160;
  rc[0].right = 184;
  rc[0].bottom = 184;
  rc[1].left = 184;
  rc[1].top = 160;
  rc[1].right = 200;
  rc[1].bottom = 184;
  rc[2].left = 168;
  rc[2].top = 184;
  rc[2].right = 184;
  rc[2].bottom = 208;
  rc[3].left = 184;
  rc[3].top = 184;
  rc[3].right = 200;
  rc[3].bottom = 208;
  rcLeft[0].left = 200;
  rcLeft[0].top = 160;
  rcLeft[0].right = 216;
  rcLeft[0].bottom = 176;
  rcLeft[1].left = 216;
  rcLeft[1].top = 160;
  rcLeft[1].right = 232;
  rcLeft[1].bottom = 176;
  rcRight[0].left = 200;
  rcRight[0].top = 176;
  rcRight[0].right = 216;
  rcRight[0].bottom = 192;
  rcRight[1].left = 216;
  rcRight[1].top = 176;
  rcRight[1].right = 232;
  rcRight[1].bottom = 192;
  v1 = npc->act_no;
  if ( v1 == 1 )
  {
LABEL_19:
    if ( ++npc->act_wait == 8 )
      npc->bits &= 0xFFF7u;
    npc->x += npc->xm;
    npc->y += npc->ym;
    if ( npc->act_wait == 16 )
      npc->act_no = 10;
    if ( ++npc->ani_wait > 2 )
    {
      npc->ani_wait = 0;
      if ( ++npc->ani_no > 3 )
        npc->ani_no = 0;
    }
    v3 = &rc[npc->ani_no];
    npc->rect.left = v3->left;
    npc->rect.top = v3->top;
    npc->rect.right = v3->right;
    npc->rect.bottom = v3->bottom;
    return;
  }
  if ( v1 <= 1 )
  {
    if ( v1 )
      return;
    npc->act_no = 1;
    v2 = npc->direct;
    if ( v2 == 1 )
    {
      npc->ym = -1536;
    }
    else if ( v2 > 1 )
    {
      if ( v2 == 2 )
      {
        npc->xm = 1536;
      }
      else if ( v2 == 3 )
      {
        npc->ym = 1536;
      }
    }
    else if ( !v2 )
    {
      npc->xm = -1536;
    }
    goto LABEL_19;
  }
  if ( v1 == 10 )
  {
    npc->act_no = 11;
    npc->ani_no = 0;
    npc->bits |= 0x20u;
    npc->bits &= 0xFFF7u;
    npc->damage = 5;
    npc->view.top = 4096;
  }
  else if ( v1 != 11 )
  {
    return;
  }
  if ( npc->x <= x )
    npc->direct = 2;
  else
    npc->direct = 0;
  if ( y - 12288 <= npc->y )
  {
    if ( npc->direct )
      v5 = npc->xm2 + 16;
    else
      v5 = npc->xm2 - 16;
    npc->xm2 = v5;
  }
  else
  {
    if ( npc->direct )
      v4 = npc->xm2 - 16;
    else
      v4 = npc->xm2 + 16;
    npc->xm2 = v4;
  }
  if ( npc->y <= y )
    v6 = npc->ym2 + 16;
  else
    v6 = npc->ym2 - 16;
  npc->ym2 = v6;
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
    if ( ++npc->ani_no > 1 )
      npc->ani_no = 0;
  }
  if ( npc->direct )
  {
    v7 = npc;
    v8 = &rcRight[npc->ani_no];
  }
  else
  {
    v7 = npc;
    v8 = &rcLeft[npc->ani_no];
  }
  npc->rect.left = v8->left;
  v7->rect.top = v8->top;
  v7->rect.right = v8->right;
  v7->rect.bottom = v8->bottom;
}

void __cdecl ActNpc354(NPCHAR_0 *npc)
{
  int v1;
  int v2;
  int v3;
  int i;

  v1 = npc->act_no;
  if ( v1 != 1 )
  {
    if ( v1 > 1 )
    {
      if ( v1 == 10 )
      {
        npc->act_no = 11;
        npc->act_wait = 0;
        if ( npc->direct )
          v2 = npc->x - 0x2000;
        else
          v2 = npc->x + 0x2000;
        npc->x = v2;
      }
      else if ( v1 != 11 )
      {
        return;
      }
      if ( ++npc->act_wait > 100 )
      {
        npc->act_wait = 0;
        SetQuake(20);
        PlaySoundObject(26, 1);
        PlaySoundObject(12, 1);
        if ( npc->direct )
          v3 = npc->x + 0x2000;
        else
          v3 = npc->x - 0x2000;
        npc->x = v3;
        for ( i = 0; i <= 19; ++i )
          ChangeMapParts(npc->x / 0x2000, i + npc->y / 0x2000, 0x6Du);
      }
    }
    else if ( !v1 )
    {
      npc->hit.bottom = 143360;
    }
  }
}

void __cdecl ActNpc355(NPCHAR_0 *npc)
{
  int v1;
  RECT *v2;
  RECT rc[4];

  rc[0].left = 80;
  rc[0].top = 16;
  rc[0].right = 96;
  rc[0].bottom = 32;
  rc[1].left = 80;
  rc[1].top = 96;
  rc[1].right = 96;
  rc[1].bottom = 112;
  rc[2].left = 128;
  rc[2].top = 16;
  rc[2].right = 144;
  rc[2].bottom = 32;
  rc[3].left = 208;
  rc[3].top = 96;
  rc[3].right = 224;
  rc[3].bottom = 112;
  if ( !npc->act_no )
  {
    v1 = npc->direct;
    if ( v1 == 1 )
    {
      npc->surf = 23;
      npc->ani_no = 1;
      npc->x = npc->pNpc->x + 7168;
      npc->y = npc->pNpc->y + 5120;
    }
    else if ( v1 > 1 )
    {
      if ( v1 == 2 )
      {
        npc->surf = 16;
        npc->ani_no = 2;
        npc->x = npc->pNpc->x - 3584;
        npc->y = npc->pNpc->y - 9728;
      }
      else if ( v1 == 3 )
      {
        npc->surf = 23;
        npc->ani_no = 3;
        npc->x = npc->pNpc->x + 2048;
        npc->y = npc->pNpc->y - 9728;
      }
    }
    else if ( !v1 )
    {
      npc->surf = 16;
      npc->ani_no = 0;
      npc->x = npc->pNpc->x - 7168;
      npc->y = npc->pNpc->y + 5120;
    }
  }
  v2 = &rc[npc->ani_no];
  npc->rect.left = v2->left;
  npc->rect.top = v2->top;
  npc->rect.right = v2->right;
  npc->rect.bottom = v2->bottom;
}

void __cdecl ActNpc356(NPCHAR_0 *npc)
{
  int v1;
  int v2;
  RECT rcRight[2];
  RECT *v4;

  rcRight[0].left = 240;
  rcRight[0].top = 128;
  rcRight[0].right = 280;
  rcRight[0].bottom = 152;
  rcRight[1].left = 240;
  rcRight[1].top = 152;
  rcRight[1].right = 280;
  rcRight[1].bottom = 176;
  switch ( npc->act_no )
  {
    case 0:
      npc->act_no = 11;
      npc->ani_wait = 0;
      npc->tgt_y = npc->y - 0x2000;
      npc->tgt_x = npc->x - 3072;
      npc->ym = 0;
      SetNpChar(355, 0, 0, 0, 0, 3, npc, 170);
      SetNpChar(355, 0, 0, 0, 0, 2, npc, 170);
      goto LABEL_3;
    case 0xB:
LABEL_3:
      if ( npc->x >= npc->tgt_x )
        v1 = npc->xm - 8;
      else
        v1 = npc->xm + 8;
      npc->xm = v1;
      if ( npc->y >= npc->tgt_y )
        v2 = npc->ym - 8;
      else
        v2 = npc->ym + 8;
      npc->ym = v2;
      npc->x += npc->xm;
      npc->y += npc->ym;
      break;
    case 0x14:
      npc->act_no = 21;
      npc->xm = -1024;
      npc->ym = 512;
      goto LABEL_11;
    case 0x15:
LABEL_11:
      ++npc->ani_wait;
      npc->xm += 16;
      npc->ym -= 8;
      npc->x += npc->xm;
      npc->y += npc->ym;
      if ( npc->x > 491520 )
        npc->act_no = 22;
      break;
    case 0x16:
      npc->xm = 0;
      npc->ym = 0;
      break;
    default:
      break;
  }
  if ( ++npc->ani_wait > 4 )
  {
    npc->ani_wait = 0;
    ++npc->ani_no;
  }
  if ( npc->ani_no > 1 )
    npc->ani_no = 0;
  npc->rect = (RECT)*((_OWORD *)&v4 + npc->ani_no - 2);
}

void __cdecl ActNpc357(NPCHAR_0 *npc)
{
  int v1;
  int v2;
  int v3;
  int v4;

  v1 = npc->act_no;
  if ( !v1 )
  {
    npc->rect.left = 224;
    npc->rect.top = 136;
    npc->rect.right = 240;
    npc->rect.bottom = 152;
    ++npc->act_wait;
    goto LABEL_12;
  }
  if ( v1 < 0 )
    goto LABEL_12;
  if ( v1 == 10 )
  {
    npc->act_wait = 0;
    npc->act_no = 11;
    PlaySoundObject(29, 1);
  }
  else if ( v1 != 11 )
  {
    goto LABEL_12;
  }
  ++npc->act_wait;
  npc->rect.left = 224;
  npc->rect.top = 136;
  npc->rect.right = 240;
  npc->rect.bottom = 152;
  if ( npc->act_wait / 2 & 1 )
    npc->rect.right = npc->rect.left;
  if ( npc->act_wait > 50 )
    npc->cond = 0;
LABEL_12:
  if ( npc->act_wait % 8 == 1 )
  {
    v2 = npc->y + 4096;
    v3 = npc->x;
    v4 = Random(-8, 8);
    SetCaret(v3 + (v4 << 9), v2, 13, 1);
  }
}
/* Orphan comments:
TODO
*/

void __cdecl ActNpc358(NPCHAR_0 *npc)
{
  int v1;
  RECT rc[5];
  RECT *v3;

  qmemcpy(rc, ActNpc358(NPCHAR *)::C.16, sizeof(rc));
  v1 = npc->act_no;
  if ( v1 )
  {
    if ( v1 == 10 )
    {
      if ( ++npc->ani_wait > 6 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 4 )
        npc->ani_no = 3;
    }
  }
  else
  {
    if ( ++npc->ani_wait > 6 )
    {
      npc->ani_wait = 0;
      ++npc->ani_no;
    }
    if ( npc->ani_no > 1 )
      npc->ani_no = 0;
  }
  npc->rect = (RECT)*((_OWORD *)&v3 + npc->ani_no - 5);
}

void __cdecl ActNpc359(NPCHAR_0 *npc)
{
  int v1;

  if ( x < npc->x + 163840 && x > npc->x - 163840 && y < npc->y + 163840 && y > npc->y - 81920 && Random(0, 100) == 2 )
  {
    v1 = Random(-6, 6);
    SetNpChar(73, (v1 << 9) + npc->x, npc->y - 3584, 0, 0, 0, 0, 0);
  }
}

void __cdecl ActNpc360(NPCHAR_0 *npc)
{
  if ( !npc->act_no )
  {
    ++npc->act_no;
    npc->x -= 4096;
    npc->y -= 4096;
  }
  npc->rect.left = 0;
  npc->rect.top = 176;
  npc->rect.right = 48;
  npc->rect.bottom = 184;
}

// No idea what this crap is
void __cdecl scoped_profile::scoped_profile(scoped_profile *const this, const char *id)
{
  this->_vptr.scoped_profile = (int (**)(...))off_81454D8;
  this->id = id;
  this->start = SDL_GetTicks();
}



