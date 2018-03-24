#include "types.h"
#include "SDL_stdinc.h"
#include "windows_wrapper.h"
#include "Tags.h"
#include "forNpc.h"
#include "KeyControl.h"
void __cdecl ActNpc320(NPCHAR_0 *npc)
{
  NPCHAR_0 *v1;
  Sint32 *v2;
  RECT rcRight[3];
  RECT rcLeft[3];
  char v5[8];

  rcLeft[0].left = 16;
  rcLeft[0].top = 96;
  rcLeft[0].right = 32;
  rcLeft[0].bottom = 112;
  rcLeft[1].left = 48;
  rcLeft[1].top = 96;
  rcLeft[1].right = 64;
  rcLeft[1].bottom = 112;
  rcLeft[2].left = 96;
  rcLeft[2].top = 96;
  rcLeft[2].right = 112;
  rcLeft[2].bottom = 112;
  rcRight[0].left = 16;
  rcRight[0].top = 112;
  rcRight[0].right = 32;
  rcRight[0].bottom = 128;
  rcRight[1].left = 48;
  rcRight[1].top = 112;
  rcRight[1].right = 64;
  rcRight[1].bottom = 128;
  rcRight[2].left = 96;
  rcRight[2].top = 112;
  rcRight[2].right = 112;
  rcRight[2].bottom = 128;
  if ( !npc->act_no )
  {
    npc->act_no = 1;
    npc->x = x;
    npc->y = y;
    SetNpChar(321, 0, 0, 0, 0, 0, npc, 256);
  }
  if ( dword_81C8584 & 8 )
  {
    if ( unk_81C858C )
    {
      npc->tgt_x = x;
      npc->tgt_y = y - 5120;
      npc->ani_no = 1;
    }
    else
    {
      npc->ani_no = 0;
      if ( dir )
        npc->tgt_x = x - 3584;
      else
        npc->tgt_x = x + 3584;
      npc->tgt_y = y - 1536;
    }
  }
  else if ( unk_81C858C )
  {
    npc->tgt_x = x;
    npc->tgt_y = y + 4096;
    npc->ani_no = 2;
  }
  else if ( unk_81C8590 )
  {
    npc->tgt_x = x;
    npc->tgt_y = y - 4096;
    npc->ani_no = 1;
  }
  else
  {
    npc->ani_no = 0;
    if ( dir )
      npc->tgt_x = x - 3584;
    else
      npc->tgt_x = x + 3584;
    npc->tgt_y = y - 1536;
  }
  npc->x += (npc->tgt_x - npc->x) / 2;
  npc->y += (npc->tgt_y - npc->y) / 2;
  if ( unk_81C85C0 & 1 )
    npc->y -= 512;
  if ( dir )
  {
    v1 = npc;
    v2 = (Sint32 *)&v5[16 * npc->ani_no - 48];
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


void __cdecl ActNpc321(NPCHAR_0 *npc)
{
  int v1;
  bool v2;
  NPCHAR_0 *v3;
  Sint32 *v4;
  RECT rcRight[3];
  RECT rcLeft[3];
  int direct;
  char v8[8];

  rcLeft[0].left = 136;
  rcLeft[0].top = 152;
  rcLeft[0].right = 152;
  rcLeft[0].bottom = 168;
  rcLeft[1].left = 152;
  rcLeft[1].top = 152;
  rcLeft[1].right = 168;
  rcLeft[1].bottom = 168;
  rcLeft[2].left = 168;
  rcLeft[2].top = 152;
  rcLeft[2].right = 184;
  rcLeft[2].bottom = 168;
  rcRight[0].left = 136;
  rcRight[0].top = 168;
  rcRight[0].right = 152;
  rcRight[0].bottom = 184;
  rcRight[1].left = 152;
  rcRight[1].top = 168;
  rcRight[1].right = 168;
  rcRight[1].bottom = 184;
  rcRight[2].left = 168;
  rcRight[2].top = 168;
  rcRight[2].right = 184;
  rcRight[2].bottom = 184;
  if ( npc->pNpc )
  {
    v1 = npc->pNpc->ani_no;
    switch ( v1 )
    {
      case 1:
        npc->x = npc->pNpc->x;
        direct = 1;
        npc->y = npc->pNpc->y - 5120;
        break;
      case 2:
        npc->x = npc->pNpc->x;
        direct = 3;
        npc->y = npc->pNpc->y + 5120;
        break;
      case 0:
        if ( dir )
        {
          npc->x = npc->pNpc->x - 4096;
          direct = 0;
        }
        else
        {
          npc->x = npc->pNpc->x + 4096;
          direct = 2;
        }
        npc->y = npc->pNpc->y;
        break;
    }
    npc->ani_no = npc->pNpc->ani_no;
    v2 = g_GameFlags & 2 && CountBulletNum(43) <= 1 && gKeyTrg & gKeyShot;
    if ( v2 )
    {
      SetBullet(43, npc->pNpc->x, npc->pNpc->y, direct);
      SetCaret(npc->pNpc->x, npc->pNpc->y, 3, 0);
      PlaySoundObject(117, 1);
    }
    if ( dir )
    {
      v3 = npc;
      v4 = (Sint32 *)&v8[16 * npc->ani_no - 52];
    }
    else
    {
      v3 = npc;
      v4 = (Sint32 *)&v8[16 * npc->ani_no - 100];
    }
    npc->rect.left = *v4;
    v3->rect.top = v4[1];
    v3->rect.right = v4[2];
    v3->rect.bottom = v4[3];
  }
}


void __cdecl ActNpc322(NPCHAR_0 *npc)
{
  int v1;
  Sint32 *v2;
  int v3;
  RECT rc[3];
  char v5[8];

  rc[0].left = 272;
  rc[0].top = 216;
  rc[0].right = 296;
  rc[0].bottom = 240;
  rc[1].left = 296;
  rc[1].top = 216;
  rc[1].right = 320;
  rc[1].bottom = 240;
  rc[2].left = 160;
  rc[2].top = 216;
  rc[2].right = 184;
  rc[2].bottom = 240;
  if ( npc->act_no <= 1 && npc->life <= 968 )
  {
    npc->act_no = 2;
    npc->act_wait = 0;
    npc->bits &= 0xFFDFu;
    npc->bits |= 4u;
    PlaySoundObject(22, 1);
  }
  v1 = npc->act_no;
  if ( v1 == 1 )
  {
LABEL_10:
    if ( npc->shock )
      ++npc->count1;
    else
      npc->count1 = 0;
    v2 = (Sint32 *)&v5[16 * (npc->count1 / 2 % 2) - 48];
    npc->rect.left = *v2;
    npc->rect.top = v2[1];
    npc->rect.right = v2[2];
    npc->rect.bottom = v2[3];
    return;
  }
  if ( v1 != 2 )
  {
    if ( v1 )
      return;
    npc->act_no = 1;
    if ( npc->direct )
      npc->x += 4096;
    else
      npc->y += 4096;
    goto LABEL_10;
  }
  npc->ani_no = 2;
  v3 = npc->act_wait;
  if ( v3 == 100 )
  {
    SetNpChar(207, npc->x + 2048, npc->y, 0, 0, 2, 0, 384);
  }
  else if ( v3 > 100 )
  {
    switch ( v3 )
    {
      case 200:
        SetNpChar(207, npc->x + 2048, npc->y, 0, 0, 4, 0, 384);
        break;
      case 250:
        npc->hit.back = 24576;
        npc->hit.front = 24576;
        npc->hit.top = 24576;
        npc->hit.bottom = 24576;
        npc->damage = 12;
        PlaySoundObject(26, 1);
        SetDestroyNpChar(npc->x, npc->y, 24576, 40);
        SetQuake(10);
        if ( npc->direct )
        {
          DeleteMapParts((npc->x - 4096) / 0x2000, npc->y / 0x2000);
          DeleteMapParts((npc->x + 4096) / 0x2000, npc->y / 0x2000);
        }
        else
        {
          DeleteMapParts(npc->x / 0x2000, (npc->y - 4096) / 0x2000);
          DeleteMapParts(npc->x / 0x2000, (npc->y + 4096) / 0x2000);
        }
        npc->cond |= 8u;
        break;
      case 150:
        SetNpChar(207, npc->x + 2048, npc->y, 0, 0, 3, 0, 384);
        break;
    }
  }
  else if ( v3 )
  {
    if ( v3 == 50 )
      SetNpChar(207, npc->x + 2048, npc->y, 0, 0, 1, 0, 384);
  }
  else
  {
    SetNpChar(207, npc->x + 2048, npc->y, 0, 0, 0, 0, 384);
  }
  ++npc->act_wait;
  npc->rect.left = rc[2].left;
  npc->rect.top = rc[2].top;
  npc->rect.right = rc[2].right;
  npc->rect.bottom = rc[2].bottom;
}


void __cdecl ActNpc323(NPCHAR_0 *npc)
{
  int v1;
  int v2;
  int v3;
  RECT *v4;
  RECT rc[4];

  rc[0].left = 216;
  rc[0].top = 32;
  rc[0].right = 232;
  rc[0].bottom = 56;
  rc[1].left = 232;
  rc[1].top = 32;
  rc[1].right = 248;
  rc[1].bottom = 56;
  rc[2].left = 216;
  rc[2].top = 56;
  rc[2].right = 232;
  rc[2].bottom = 80;
  rc[3].left = 232;
  rc[3].top = 56;
  rc[3].right = 248;
  rc[3].bottom = 80;
  if ( ++npc->ani_wait > 3 )
  {
    npc->ani_wait = 0;
    if ( ++npc->ani_no > 3 )
      npc->ani_no = 0;
  }
  v1 = npc->act_no;
  if ( v1 )
  {
    if ( v1 != 1 )
      goto LABEL_38;
  }
  else
  {
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
  }
  if ( ++npc->act_wait == 16 )
    npc->bits &= 0xFFF7u;
  npc->x += npc->xm;
  npc->y += npc->ym;
  if ( npc->flag & 0xFF )
    npc->act_no = 10;
  if ( npc->act_wait > 20 )
  {
    v3 = npc->direct;
    if ( v3 == 1 )
    {
      if ( npc->y <= y + 0x4000 )
        npc->act_no = 10;
    }
    else if ( v3 > 1 )
    {
      if ( v3 == 2 )
      {
        if ( npc->x >= x - 0x4000 )
          npc->act_no = 10;
      }
      else if ( v3 == 3 && npc->y >= y - 0x4000 )
      {
        npc->act_no = 10;
      }
    }
    else if ( !v3 && npc->x <= x + 0x4000 )
    {
      npc->act_no = 10;
    }
  }
LABEL_38:
  if ( npc->act_no == 10 )
  {
    npc->code_char = 309;
    npc->ani_no = 0;
    npc->act_no = 11;
    npc->bits |= 0x20u;
    npc->bits &= 0xFFF7u;
    npc->damage = 5;
    npc->view.top = 4096;
  }
  v4 = &rc[npc->ani_no];
  npc->rect.left = v4->left;
  npc->rect.top = v4->top;
  npc->rect.right = v4->right;
  npc->rect.bottom = v4->bottom;
}

void __cdecl ActNpc324(NPCHAR_0 *npc)
{
  int v1;

  v1 = npc->act_no;
  if ( v1 && v1 >= 0 )
  {
    if ( v1 == 10 )
    {
      npc->act_no = 11;
      npc->act_wait = 0;
    }
    else if ( v1 != 11 )
    {
      return;
    }
    if ( ++npc->act_wait % 50 == 1 )
      SetNpChar(323, npc->x, npc->y, 0, 0, npc->direct, 0, 256);
    if ( npc->act_wait > 351 )
      npc->act_no = 0;
  }
}

void __cdecl ActNpc325(NPCHAR_0 *npc)
{
  int v1;
  Sint32 *v2;
  RECT rc[7];
  char v4[24];

  qmemcpy(rc, &ActNpc325(NPCHAR *)::C.5, sizeof(rc));
  v1 = npc->act_no;
  switch ( v1 )
  {
    case 1:
      goto LABEL_5;
    case 10:
      if ( ++npc->ani_wait > 2 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 6 )
      {
        npc->cond = 0;
        return;
      }
      break;
    case 0:
      npc->act_no = 1;
      PlaySoundObject(29, 1);
LABEL_5:
      if ( ++npc->ani_wait > 0 )
      {
        npc->ani_wait = 0;
        ++npc->ani_no;
      }
      if ( npc->ani_no > 2 )
        npc->ani_no = 0;
      if ( ++npc->act_wait > 50 )
      {
        npc->act_no = 10;
        npc->ani_wait = 0;
        npc->ani_no = 3;
        npc->damage = 10;
        npc->view.front = 4096;
        npc->view.top = 6144;
        PlaySoundObject(101, 1);
        SetDestroyNpChar(npc->x, npc->y + 43008, 0, 3);
      }
      break;
  }
  v2 = (Sint32 *)&v4[16 * npc->ani_no - 112];
  npc->rect.left = *v2;
  npc->rect.top = v2[1];
  npc->rect.right = v2[2];
  npc->rect.bottom = v2[3];
}


void __cdecl ActNpc326(NPCHAR_0 *npc)
{
  NPCHAR_0 *v1;
  Sint32 *v2;
  RECT rcSu[8];
  RECT rcItoh[8];
  char v5[24];

  switch ( npc->act_no )
  {
    case 0:
      npc->act_no = 1;
      npc->y -= 4096;
      npc->x += 0x2000;
      npc->ani_no = 0;
      goto LABEL_3;
    case 1:
LABEL_3:
      if ( ++npc->act_wait > 80 )
      {
        npc->act_no = 10;
        npc->act_wait = 0;
      }
      else if ( npc->direct )
      {
        if ( npc->act_wait == 50 )
          npc->ani_no = 1;
        if ( npc->act_wait == 60 )
          npc->ani_no = 0;
      }
      else
      {
        if ( npc->act_wait == 30 )
          npc->ani_no = 1;
        if ( npc->act_wait == 40 )
          npc->ani_no = 0;
      }
      break;
    case 0xA:
      if ( ++npc->act_wait > 50 )
      {
        npc->act_no = 15;
        npc->ani_no = 4;
        if ( npc->direct )
          npc->act_wait = -20;
        else
          npc->act_wait = 0;
      }
      else if ( npc->act_wait / 2 & 1 )
      {
        npc->ani_no = 2;
      }
      else
      {
        npc->ani_no = 3;
      }
      break;
    case 0xF:
      if ( ++npc->act_wait > 40 )
      {
        npc->act_wait = 0;
        npc->act_no = 20;
      }
      break;
    case 0x14:
      npc->ym += 64;
      if ( npc->ym > 1535 )
        npc->ym = 1535;
      npc->y += npc->ym;
      if ( ++npc->act_wait > 50 )
      {
        npc->act_no = 30;
        npc->act_wait = 0;
        npc->ani_no = 6;
        if ( npc->direct )
          SetNpChar(327, npc->x, npc->y - 4096, 0, 0, 0, npc, 256);
        else
          SetNpChar(327, npc->x, npc->y - 0x2000, 0, 0, 0, npc, 256);
      }
      break;
    case 0x1E:
      if ( ++npc->act_wait == 30 )
        npc->ani_no = 7;
      if ( npc->act_wait == 40 )
        npc->act_no = 40;
      break;
    case 0x28:
      npc->act_no = 41;
      npc->act_wait = 0;
      npc->ani_no = 0;
      goto LABEL_34;
    case 0x29:
LABEL_34:
      if ( ++npc->act_wait == 30 )
        npc->ani_no = 1;
      if ( npc->act_wait == 40 )
        npc->ani_no = 0;
      break;
    default:
      break;
  }
  qmemcpy(rcItoh, &ActNpc326(NPCHAR *)::C.10, sizeof(rcItoh));
  qmemcpy(rcSu, &ActNpc326(NPCHAR *)::C.11, sizeof(rcSu));
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


void __cdecl ActNpc327(NPCHAR_0 *npc)
{
  int v1;
  int v2;
  int v3;
  Sint32 *v4;
  RECT rc[2];
  char v6[8];

  rc[0].left = 240;
  rc[0].top = 80;
  rc[0].right = 256;
  rc[0].bottom = 96;
  rc[1].left = 256;
  rc[1].top = 80;
  rc[1].right = 272;
  rc[1].bottom = 96;
  ++npc->act_wait;
  v1 = npc->act_no;
  if ( v1 )
  {
    if ( v1 == 1 )
    {
      if ( npc->act_wait > 47 )
      {
        npc->x = npc->tgt_x;
        npc->y = npc->tgt_y;
      }
      else
      {
        v2 = npc->tgt_x;
        npc->x = v2 + (Random(-1, 1) << 9);
        v3 = npc->tgt_y;
        npc->y = v3 + (Random(-1, 1) << 9);
      }
    }
  }
  else
  {
    if ( npc->act_wait <= 3 )
      npc->y -= 1024;
    if ( npc->pNpc->ani_no == 7 )
    {
      npc->ani_no = 1;
      npc->act_no = 1;
      npc->tgt_x = npc->x;
      npc->tgt_y = npc->y;
    }
  }
  if ( npc->act_wait > 70 )
    npc->cond = 0;
  v4 = (Sint32 *)&v6[16 * npc->ani_no - 32];
  npc->rect.left = *v4;
  npc->rect.top = v4[1];
  npc->rect.right = v4[2];
  npc->rect.bottom = v4[3];
}


void __cdecl ActNpc328(NPCHAR_0 *npc)
{
  npc->rect.left = 96;
  npc->rect.top = 0;
  npc->rect.right = 128;
  npc->rect.bottom = 48;
}

void __cdecl ActNpc329(NPCHAR_0 *npc)
{
  if ( ++npc->ani_wait / 2 & 1 )
  {
    npc->rect.left = 48;
    npc->rect.top = 0;
    npc->rect.right = 64;
  }
  else
  {
    npc->rect.left = 64;
    npc->rect.top = 0;
    npc->rect.right = 80;
  }
  npc->rect.bottom = 16;
}

void __cdecl ActNpc330(NPCHAR_0 *npc)
{
  Sint32 *v1;
  RECT rc[3];
  char v3[8];

  rc[0].left = 144;
  rc[0].top = 136;
  rc[0].right = 160;
  rc[0].bottom = 152;
  rc[1].left = 160;
  rc[1].top = 136;
  rc[1].right = 176;
  rc[1].bottom = 152;
  rc[2].left = 176;
  rc[2].top = 136;
  rc[2].right = 192;
  rc[2].bottom = 152;
  switch ( npc->act_no )
  {
    case 0:
      ChangeMapParts(npc->x / 0x2000, npc->y / 0x2000, 0);
      if ( npc->direct )
        npc->act_no = 30;
      else
        npc->act_no = 10;
      break;
    case 0xA:
      npc->xm -= 64;
      npc->ym = 0;
      if ( npc->flag & 1 )
        npc->act_no = 20;
      break;
    case 0x14:
      npc->xm = 0;
      npc->ym -= 64;
      if ( npc->flag & 2 )
        npc->act_no = 30;
      break;
    case 0x1E:
      npc->xm += 64;
      npc->ym = 0;
      if ( npc->flag & 4 )
        npc->act_no = 40;
      break;
    case 0x28:
      npc->xm = 0;
      npc->ym += 64;
      if ( npc->flag & 8 )
        npc->act_no = 10;
      break;
    default:
      break;
  }
  if ( npc->xm < -1024 )
    npc->xm = -1024;
  if ( npc->xm > 1024 )
    npc->xm = 1024;
  if ( npc->ym < -1024 )
    npc->ym = -1024;
  if ( npc->ym > 1024 )
    npc->ym = 1024;
  npc->x += npc->xm;
  npc->y += npc->ym;
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
}


void __cdecl ActNpc331(NPCHAR_0 *npc)
{
  int v1;
  int v2;
  Sint32 *v3;
  RECT rc[4];
  char v5[8];

  rc[0].left = 288;
  rc[0].top = 80;
  rc[0].right = 304;
  rc[0].bottom = 96;
  rc[1].left = 304;
  rc[1].top = 80;
  rc[1].right = 320;
  rc[1].bottom = 96;
  rc[2].left = 288;
  rc[2].top = 96;
  rc[2].right = 304;
  rc[2].bottom = 112;
  rc[3].left = 304;
  rc[3].top = 96;
  rc[3].right = 320;
  rc[3].bottom = 112;
  v1 = npc->act_no;
  if ( v1 == 1 )
  {
LABEL_5:
    if ( npc->flag & 8 )
    {
      npc->ym = -512;
      npc->act_no = 10;
    }
    goto LABEL_9;
  }
  if ( v1 != 10 )
  {
    if ( v1 )
      goto LABEL_9;
    npc->act_no = 1;
    goto LABEL_5;
  }
  if ( npc->flag & 8 )
  {
    npc->cond = 0;
    SetCaret(npc->x, npc->y, 2, 0);
  }
LABEL_9:
  npc->ym += 64;
  if ( npc->ym > 1535 )
    npc->ym = 1535;
  npc->y += npc->ym;
  npc->x += npc->xm;
  if ( ++npc->ani_wait > 3 )
  {
    npc->ani_wait = 0;
    if ( npc->direct )
      v2 = npc->ani_no - 1;
    else
      v2 = npc->ani_no + 1;
    npc->ani_no = v2;
    if ( npc->ani_no < 0 )
      npc->ani_no += 4;
    if ( npc->ani_no > 3 )
      npc->ani_no -= 4;
  }
  v3 = (Sint32 *)&v5[16 * npc->ani_no - 64];
  npc->rect.left = *v3;
  npc->rect.top = v3[1];
  npc->rect.right = v3[2];
  npc->rect.bottom = v3[3];
}


void __cdecl ActNpc332(NPCHAR_0 *npc)
{
  int v1;
  Sint32 *v2;
  RECT rc[3];
  int xm;
  char v5[8];

  rc[0].left = 144;
  rc[0].top = 96;
  rc[0].right = 168;
  rc[0].bottom = 120;
  rc[1].left = 168;
  rc[1].top = 96;
  rc[1].right = 192;
  rc[1].bottom = 120;
  rc[2].left = 192;
  rc[2].top = 96;
  rc[2].right = 216;
  rc[2].bottom = 120;
  v1 = npc->act_no;
  if ( v1 )
  {
    if ( v1 != 1 )
      goto LABEL_15;
  }
  else
  {
    PlaySoundObject(44, 1);
    npc->act_no = 1;
    if ( npc->direct )
      npc->xm = 1024;
    else
      npc->xm = -1024;
  }
  if ( ++npc->ani_wait > 1 )
  {
    npc->ani_wait = 0;
    if ( ++npc->ani_no > 2 )
      npc->ani_no = 0;
  }
  if ( ++npc->act_wait % 6 == 1 )
  {
    if ( npc->direct )
      xm = (Random(4, 16) << 9) / 8;
    else
      xm = (Random(-16, -4) << 9) / 8;
    SetNpChar(331, npc->x, npc->y, xm, -1024, 0, 0, 256);
    PlaySoundObject(12, 1);
  }
LABEL_15:
  if ( npc->flag & 1 )
    npc->cond = 0;
  if ( npc->flag & 4 )
    npc->cond = 0;
  npc->x += npc->xm;
  v2 = (Sint32 *)&v5[16 * npc->ani_no - 52];
  npc->rect.left = *v2;
  npc->rect.top = v2[1];
  npc->rect.right = v2[2];
  npc->rect.bottom = v2[3];
}


void __cdecl ActNpc333(NPCHAR_0 *npc)
{
  int v1;
  Sint32 *v2;
  RECT rc[2];
  char v4[8];

  rc[0].left = 80;
  rc[0].top = 120;
  rc[0].right = 104;
  rc[0].bottom = 144;
  rc[1].left = 104;
  rc[1].top = 120;
  rc[1].right = 128;
  rc[1].bottom = 144;
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
    PlaySoundObject(103, 1);
    npc->y = y;
  }
  if ( ++npc->act_wait / 2 & 1 )
    npc->ani_no = 0;
  else
    npc->ani_no = 1;
  if ( !npc->direct && npc->act_wait == 20 )
    SetNpChar(146, npc->tgt_x, npc->tgt_y, 0, 0, 0, 0, 256);
  if ( npc->act_wait > 40 )
    npc->cond = 0;
LABEL_13:
  v2 = (Sint32 *)&v4[16 * npc->ani_no - 32];
  npc->rect.left = *v2;
  npc->rect.top = v2[1];
  npc->rect.right = v2[2];
  npc->rect.bottom = v2[3];
}


void __cdecl ActNpc334(NPCHAR_0 *npc)
{
  int v1;
  NPCHAR_0 *v2;
  RECT *v3;
  RECT rcRight[2];
  RECT rcLeft[2];

  rcLeft[0].left = 160;
  rcLeft[0].top = 184;
  rcLeft[0].right = 168;
  rcLeft[0].bottom = 200;
  rcLeft[1].left = 168;
  rcLeft[1].top = 184;
  rcLeft[1].right = 176;
  rcLeft[1].bottom = 200;
  rcRight[0].left = 176;
  rcRight[0].top = 184;
  rcRight[0].right = 184;
  rcRight[0].bottom = 200;
  rcRight[1].left = 184;
  rcRight[1].top = 184;
  rcRight[1].right = 192;
  rcRight[1].bottom = 200;
  v1 = npc->act_no;
  if ( v1 )
  {
    if ( v1 != 10 )
      goto LABEL_12;
  }
  else
  {
    npc->act_no = 10;
    if ( npc->direct )
    {
      npc->x = x - 5120;
      npc->y = y - 1024;
    }
    else
    {
      npc->x += 5120;
      npc->y -= 9216;
    }
  }
  if ( ++npc->act_wait / 8 & 1 )
    npc->ani_no = 0;
  else
    npc->ani_no = 1;
  if ( npc->act_wait > 63 )
    npc->cond = 0;
LABEL_12:
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

void __cdecl ActNpc335(NPCHAR_0 *npc)
{
  int v1;
  Sint32 *v2;
  RECT rc[3];
  char v4[8];

  rc[0].left = 0;
  rc[0].top = 16;
  rc[0].right = 16;
  rc[0].bottom = 32;
  rc[1].left = 16;
  rc[1].top = 16;
  rc[1].right = 32;
  rc[1].bottom = 32;
  rc[2].left = 32;
  rc[2].top = 16;
  rc[2].right = 48;
  rc[2].bottom = 32;
  v1 = npc->act_no;
  if ( v1 == 1 )
  {
LABEL_9:
    if ( --npc->act_wait <= 0 )
    {
      npc->act_no = 2;
      npc->act_wait = Random(10, 50);
      npc->ani_no = 1;
      npc->xm = 1536;
    }
    goto LABEL_15;
  }
  if ( v1 <= 1 )
  {
    if ( v1 )
      goto LABEL_15;
    npc->act_no = 1;
    npc->act_wait = Random(3, 20);
    goto LABEL_9;
  }
  if ( v1 == 2 )
  {
    if ( --npc->act_wait <= 0 )
    {
      npc->act_no = 3;
      npc->act_wait = Random(40, 50);
      npc->ani_no = 2;
      npc->ym = Random(-256, 256);
    }
  }
  else if ( v1 == 3 && --npc->act_wait <= 0 )
  {
    npc->act_no = 1;
    npc->act_wait = 0;
    npc->ani_no = 0;
  }
LABEL_15:
  npc->xm -= 16;
  npc->x += npc->xm;
  npc->y += npc->ym;
  v2 = (Sint32 *)&v4[16 * npc->ani_no - 48];
  npc->rect.left = *v2;
  npc->rect.top = v2[1];
  npc->rect.right = v2[2];
  npc->rect.bottom = v2[3];
}


void __cdecl ActNpc336(NPCHAR_0 *npc)
{
  int v1;
  int v2;
  int v3;

  v1 = npc->act_no;
  if ( v1 )
  {
    if ( v1 == 10 && ++npc->act_wait % 4 == 1 )
    {
      v2 = npc->y;
      v3 = Random(0, 13);
      SetNpChar(335, npc->x, v2 + (v3 << 13), 0, 0, 0, 0, 0);
    }
  }
  else if ( unk_81C8610 )
  {
    npc->cond = 0;
  }
}

void __cdecl ActNpc337(NPCHAR_0 *npc)
{
  int v1;
  RECT *v2;
  RECT rcLeft[2];

  rcLeft[0].left = 256;
  rcLeft[0].top = 112;
  rcLeft[0].right = 288;
  rcLeft[0].bottom = 152;
  rcLeft[1].left = 288;
  rcLeft[1].top = 112;
  rcLeft[1].right = 320;
  rcLeft[1].bottom = 152;
  v1 = npc->act_no;
  if ( v1 == 1 )
  {
LABEL_5:
    npc->xm = 0;
    npc->act_no = 2;
    npc->ani_no = 0;
    goto LABEL_6;
  }
  if ( v1 != 2 )
  {
    if ( v1 )
      goto LABEL_10;
    npc->act_no = 1;
    npc->y -= 4096;
    goto LABEL_5;
  }
LABEL_6:
  if ( ++npc->ani_wait > 50 )
  {
    npc->ani_wait = 0;
    ++npc->ani_no;
  }
  if ( npc->ani_no > 1 )
    npc->ani_no = 0;
LABEL_10:
  npc->ym += 64;
  if ( npc->ym > 1535 )
    npc->ym = 1535;
  npc->x += npc->xm;
  npc->y += npc->ym;
  v2 = &rcLeft[npc->ani_no];
  npc->rect.left = v2->left;
  npc->rect.top = v2->top;
  npc->rect.right = v2->right;
  npc->rect.bottom = v2->bottom;
}

void __cdecl ActNpc338(NPCHAR_0 *npc)
{
  int v1;
  int v2;
  int v3;
  NPCHAR_0 *v4;
  Sint32 *v5;
  RECT rcRight[2];
  RECT rcLeft[2];
  char v8[8];

  rcLeft[0].left = 288;
  rcLeft[0].top = 0;
  rcLeft[0].right = 304;
  rcLeft[0].bottom = 16;
  rcLeft[1].left = 304;
  rcLeft[1].top = 0;
  rcLeft[1].right = 320;
  rcLeft[1].bottom = 16;
  rcRight[0].left = 288;
  rcRight[0].top = 16;
  rcRight[0].right = 304;
  rcRight[0].bottom = 32;
  rcRight[1].left = 304;
  rcRight[1].top = 16;
  rcRight[1].right = 320;
  rcRight[1].bottom = 32;
  v1 = npc->act_no;
  if ( v1 )
  {
    if ( v1 != 1 )
      goto LABEL_24;
  }
  else
  {
    npc->act_no = 1;
    npc->view.top = 4096;
    npc->view.bottom = 4096;
    npc->damage = 3;
    npc->bits |= 0x20u;
    npc->tgt_y = npc->y;
    npc->ym = (Random(-10, 10) << 9) / 2;
  }
  if ( ++npc->ani_wait > 2 )
  {
    npc->ani_wait = 0;
    ++npc->ani_no;
  }
  if ( npc->ani_no > 1 )
    npc->ani_no = 0;
  if ( npc->y >= npc->tgt_y )
    v2 = npc->ym - 128;
  else
    v2 = npc->ym + 128;
  npc->ym = v2;
  if ( npc->direct )
    v3 = npc->xm + 32;
  else
    v3 = npc->xm - 32;
  npc->xm = v3;
  if ( npc->xm > 1024 )
    npc->xm = 1024;
  if ( npc->xm < -1024 )
    npc->xm = -1024;
  if ( npc->x < 0 || npc->y < 0 || npc->x > gMap.width << 13 || npc->y > gMap.length << 13 )
  {
    VanishNpChar(npc);
    return;
  }
LABEL_24:
  npc->x += npc->xm;
  npc->y += npc->ym;
  if ( npc->direct )
  {
    v4 = npc;
    v5 = (Sint32 *)&v8[16 * npc->ani_no - 64];
  }
  else
  {
    v4 = npc;
    v5 = (Sint32 *)&v8[16 * npc->ani_no - 32];
  }
  npc->rect.left = *v5;
  v4->rect.top = v5[1];
  v4->rect.right = v5[2];
  v4->rect.bottom = v5[3];
}


void __cdecl ActNpc339(NPCHAR_0 *npc)
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
    npc->act_wait = Random(0, 40);
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
    v4 = Random(-16, 16);
    SetNpChar(338, npc->x, v3 + (v4 << 9), 0, 0, v2, 0, 256);
  }
}

