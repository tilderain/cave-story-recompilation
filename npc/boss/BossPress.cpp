//#include "types.h"
#include "SDL_stdinc.h"
#include "windows_wrapper.h"
#include "Tags.h"
#include "windows_wrapper.h"

void ActBossChar_Press();
unsigned __int8 ActBossChar_Press(void)::_flash;

void ActBossChar_Press()
{
  int v0;
  int v1;
  int v2;
  int v3;
  int v4;
  int v5;
  int v6;
  int v7;
  int v8;
  int v9;
  NPCHAR *v10;
  Sint32 *v11;
  NPCHAR *v12;
  Sint32 *v13;
  RECT rcDamage[3];
  RECT rc[3];
  NPCHAR *npc;
  int i;
  int x;
  char v19[24];

  npc = gBoss;
  v0 = gBoss[0].act_no;
  if ( v0 == 21 )
  {
LABEL_27:
    if ( !(++npc->act_wait & 0xF) )
    {
      v1 = npc->y;
      v2 = (Random(-60, 60) << 9) + v1;
      v3 = npc->x;
      v4 = Random(-40, 40);
      SetDestroyNpChar(v3 + (v4 << 9), v2, 1, 1);
    }
    goto LABEL_65;
  }
  if ( v0 <= 21 )
  {
    if ( v0 == 6 )
      goto LABEL_65;
    if ( v0 <= 6 )
    {
      if ( v0 != 1 )
      {
        if ( v0 == 5 )
        {
          npc->act_no = 6;
          npc->x = 0;
          npc->y = 0;
          ::npc.cond = 0;
          stru_81CD118.cond = 0;
        }
        else if ( !v0 )
        {
          npc->act_no = 10;
          npc->cond = -128;
          npc->exp = 1;
          npc->direct = 2;
          npc->x = 0;
          npc->y = 0;
          npc->view.front = 20480;
          npc->view.top = 30720;
          npc->view.back = 20480;
          npc->view.bottom = 30720;
          npc->hit_voice = 54;
          npc->hit.front = 25088;
          npc->hit.top = 30720;
          npc->hit.back = 20480;
          npc->hit.bottom = 24576;
          npc->bits = -32184;
          npc->size = 3;
          npc->damage = 10;
          npc->code_event = 1000;
          npc->life = 700;
        }
      }
      goto LABEL_65;
    }
    if ( v0 == 11 )
      goto LABEL_65;
    if ( v0 != 20 )
    {
      if ( v0 == 10 )
      {
        npc->act_no = 11;
        npc->x = 81920;
        npc->y = 37888;
      }
      goto LABEL_65;
    }
    npc->damage = 0;
    npc->act_no = 21;
    npc->x = 81920;
    npc->y = 211456;
    npc->bits &= 0xFFBFu;
    ::npc.cond = 0;
    stru_81CD118.cond = 0;
    goto LABEL_27;
  }
  if ( v0 == 101 )
  {
LABEL_36:
    if ( npc->count2 > 1 && npc->life < 70 * npc->count2 )
    {
      --npc->count2;
      for ( i = 0; i <= 4; ++i )
      {
        ChangeMapParts(i + 8, npc->count2, 0);
        SetDestroyNpChar((i + 8) << 13, npc->count2 << 13, 0, 4);
        PlaySoundObject(12, 1);
      }
    }
    if ( ++npc->act_wait == 81 || npc->act_wait == 241 )
      SetNpChar(323, 24576, 122880, 0, 0, 1, 0, 256);
    if ( npc->act_wait == 1 || npc->act_wait == 161 )
      SetNpChar(323, 139264, 122880, 0, 0, 1, 0, 256);
    if ( npc->act_wait > 299 )
    {
      npc->act_wait = 0;
      SetNpChar(325, npc->x, npc->y + 30720, 0, 0, 0, 0, 256);
    }
    goto LABEL_65;
  }
  if ( v0 <= 101 )
  {
    if ( v0 == 31 )
    {
LABEL_30:
      npc->y += 2048;
      if ( npc->y > 211455 )
      {
        npc->y = 211456;
        npc->ani_no = 0;
        npc->act_no = 20;
        PlaySoundObject(44, 1);
        for ( i = 0; i <= 4; ++i )
        {
          v5 = npc->x;
          x = v5 + (Random(-40, 40) << 9);
          SetNpChar(4, x, npc->y + 30720, 0, 0, 0, 0, 256);
        }
      }
      goto LABEL_65;
    }
    if ( v0 != 100 )
    {
      if ( v0 != 30 )
        goto LABEL_65;
      npc->act_no = 31;
      npc->ani_no = 2;
      npc->x = 81920;
      npc->y = 0x8000;
      goto LABEL_30;
    }
    npc->act_no = 101;
    npc->count2 = 9;
    npc->act_wait = -100;
    ::npc.cond = -128;
    ::npc.hit.front = 7168;
    ::npc.hit.back = 7168;
    ::npc.hit.top = 4096;
    ::npc.hit.bottom = 4096;
    ::npc.bits = 12;
    qmemcpy(&stru_81CD118, &::npc, sizeof(stru_81CD118));
    stru_81CD1C4.cond = -112;
    stru_81CD1C4.bits |= 0x20u;
    stru_81CD1C4.hit.front = 3072;
    stru_81CD1C4.hit.back = 3072;
    stru_81CD1C4.hit.top = 4096;
    stru_81CD1C4.hit.bottom = 4096;
    SetNpChar(325, npc->x, npc->y + 30720, 0, 0, 0, 0, 256);
    goto LABEL_36;
  }
  if ( v0 == 501 )
    goto LABEL_50;
  if ( v0 != 510 )
  {
    if ( v0 != 500 )
      goto LABEL_65;
    stru_81CD1C4.bits &= 0xFFDFu;
    npc->act_no = 501;
    npc->act_wait = 0;
    npc->count1 = 0;
    DeleteNpCharCode(325, 1);
    DeleteNpCharCode(330, 1);
LABEL_50:
    if ( !(++npc->act_wait & 0xF) )
    {
      PlaySoundObject(12, 1);
      v6 = npc->y;
      v7 = (Random(-60, 60) << 9) + v6;
      v8 = npc->x;
      v9 = Random(-40, 40);
      SetDestroyNpChar(v8 + (v9 << 9), v7, 1, 1);
    }
    if ( npc->act_wait == 95 )
      npc->ani_no = 1;
    if ( npc->act_wait == 98 )
      npc->ani_no = 2;
    if ( npc->act_wait > 100 )
      npc->act_no = 510;
    goto LABEL_65;
  }
  npc->ym += 64;
  npc->damage = 127;
  npc->y += npc->ym;
  if ( !npc->count1 && npc->y > 81920 )
  {
    npc->count1 = 1;
    npc->ym = -512;
    npc->damage = 0;
    for ( i = 0; i <= 6; ++i )
    {
      ChangeMapParts(i + 7, 14, 0);
      SetDestroyNpChar((i + 7) << 13, 114688, 0, 0);
      PlaySoundObject(12, 1);
    }
  }
  if ( npc->y > 245760 )
    npc->act_no = 520;
LABEL_65:
  ::npc.x = npc->x - 12288;
  ::npc.y = npc->y + 26624;
  stru_81CD118.x = npc->x + 12288;
  stru_81CD118.y = npc->y + 26624;
  stru_81CD1C4.x = npc->x;
  stru_81CD1C4.y = npc->y + 20480;
  rc[0].left = 0;
  rc[0].top = 0;
  rc[0].right = 80;
  rc[0].bottom = 120;
  rc[1].left = 80;
  rc[1].top = 0;
  rc[1].right = 160;
  rc[1].bottom = 120;
  rc[2].left = 160;
  rc[2].top = 0;
  rc[2].right = 240;
  rc[2].bottom = 120;
  rcDamage[0].left = 0;
  rcDamage[0].top = 120;
  rcDamage[0].right = 80;
  rcDamage[0].bottom = 240;
  rcDamage[1].left = 80;
  rcDamage[1].top = 120;
  rcDamage[1].right = 160;
  rcDamage[1].bottom = 240;
  rcDamage[2].left = 160;
  rcDamage[2].top = 120;
  rcDamage[2].right = 240;
  rcDamage[2].bottom = 240;
  if ( npc->shock )
  {
    if ( (++ActBossChar_Press(void)::_flash >> 1) & 1 )
    {
      v10 = npc;
      v11 = (Sint32 *)&v19[16 * npc->ani_no - 60];
    }
    else
    {
      v10 = npc;
      v11 = (Sint32 *)&v19[16 * npc->ani_no - 108];
    }
    npc->rect.left = *v11;
    v10->rect.top = v11[1];
    v10->rect.right = v11[2];
    v10->rect.bottom = v11[3];
  }
  else
  {
    v12 = npc;
    v13 = (Sint32 *)&v19[16 * npc->ani_no - 60];
    npc->rect.left = *v13;
    v12->rect.top = v13[1];
    v12->rect.right = v13[2];
    v12->rect.bottom = v13[3];
  }
}
