#include "types.h"
#include "SDL_stdinc.h"
#include "windows_wrapper.h"
#include "Tags.h"

void ActBoss01_12();
void ActBoss01_34();
void ActBoss01_5();
void ActBossChar_Omega();

void ActBoss01_12()
{
  int v0;
  RECT *v1;
  int v2;
  RECT *v3;
  RECT rcRight[1];
  RECT rcLeft[1];
  int i;

  rcLeft[0].left = 80;
  rcLeft[0].top = 56;
  rcLeft[0].right = 104;
  rcLeft[0].bottom = 72;
  rcRight[0].left = 104;
  rcRight[0].top = 56;
  rcRight[0].right = 128;
  rcRight[0].bottom = 72;
  for ( i = 1; i <= 2; ++i )
  {
    *(&unk_81CCFCC + 43 * i) = (unk_81CCFCC + *(&unk_81CCFCC + 43 * (i + 2)) - 4096) / 2;
    if ( *((_DWORD *)&unk_81CD00C + 43 * i) )
    {
      v2 = 172 * i;
      v3 = &rcRight[*((_DWORD *)&unk_81CD028 + 43 * i)];
      *(_DWORD *)(v2 + 136106004) = v3->left;
      *(_DWORD *)(v2 + 136106008) = v3->top;
      *(_DWORD *)(v2 + 136106012) = v3->right;
      *(_DWORD *)(v2 + 136106016) = v3->bottom;
      *(&unk_81CCFC8 + 43 * i) = unk_81CCFC8 + 0x2000;
    }
    else
    {
      *(&unk_81CCFC8 + 43 * i) = unk_81CCFC8 - 0x2000;
      v0 = 172 * i;
      v1 = &rcLeft[*((_DWORD *)&unk_81CD028 + 43 * i)];
      *(_DWORD *)(v0 + 136106004) = v1->left;
      *(_DWORD *)(v0 + 136106008) = v1->top;
      *(_DWORD *)(v0 + 136106012) = v1->right;
      *(_DWORD *)(v0 + 136106016) = v1->bottom;
    }
  }
}

void ActBoss01_34()
{
  signed int v0;
  int v1;
  char *v2;
  RECT rcRight[2];
  RECT rcLeft[2];
  int i;
  char v6[8];

  rcLeft[0].left = 0;
  rcLeft[0].top = 56;
  rcLeft[0].right = 40;
  rcLeft[0].bottom = 88;
  rcLeft[1].left = 40;
  rcLeft[1].top = 56;
  rcLeft[1].right = 80;
  rcLeft[1].bottom = 88;
  rcRight[0].left = 0;
  rcRight[0].top = 88;
  rcRight[0].right = 40;
  rcRight[0].bottom = 120;
  rcRight[1].left = 40;
  rcRight[1].top = 88;
  rcRight[1].right = 80;
  rcRight[1].bottom = 120;
  for ( i = 3; i <= 4; ++i )
  {
    v0 = *((_DWORD *)&unk_81CD034 + 43 * i);
    if ( v0 == 1 )
      goto LABEL_10;
    if ( v0 <= 1 )
    {
      if ( v0 )
        goto LABEL_19;
      *((_DWORD *)&unk_81CD034 + 43 * i) = 1;
LABEL_10:
      *(&unk_81CCFCC + 43 * i) = unk_81CCFCC;
      if ( i == 3 )
        *(&unk_81CCFC8 + 129) = unk_81CCFC8 - 0x2000;
      if ( i == 4 )
        *(&unk_81CCFC8 + 172) = unk_81CCFC8 + 0x2000;
      goto LABEL_19;
    }
    if ( v0 != 2 && v0 == 3 )
    {
      *((_DWORD *)&unk_81CCFE4 + 43 * i) = unk_81CCFCC + 12288;
      if ( i == 3 )
        *(&unk_81CCFC8 + 129) = unk_81CCFC8 - 0x2000;
      if ( i == 4 )
        *(&unk_81CCFC8 + 172) = unk_81CCFC8 + 0x2000;
      *(&unk_81CCFCC + 43 * i) += (*((_DWORD *)&unk_81CCFE4 + 43 * i) - *(&unk_81CCFCC + 43 * i)) / 2;
    }
LABEL_19:
    *((_DWORD *)&unk_81CD028 + 43 * i) = !(*((_DWORD *)&unk_81CCFC4 + 43 * i) & 8)
                                      && *(&unk_81CCFCC + 43 * i) > *((_DWORD *)&unk_81CCFE4 + 43 * i);
    if ( *((_DWORD *)&unk_81CD00C + 43 * i) )
    {
      v1 = 172 * i;
      v2 = &v6[16 * *((_DWORD *)&unk_81CD028 + 43 * i) - 68];
    }
    else
    {
      v1 = 172 * i;
      v2 = &v6[16 * *((_DWORD *)&unk_81CD028 + 43 * i) - 36];
    }
    *(_DWORD *)(v1 + 136106004) = *(_DWORD *)v2;
    *(_DWORD *)(v1 + 136106008) = *((_DWORD *)v2 + 1);
    *(_DWORD *)(v1 + 136106012) = *((_DWORD *)v2 + 2);
    *(_DWORD *)(v1 + 136106016) = *((_DWORD *)v2 + 3);
  }
}


void ActBoss01_5()
{
  if ( !stru_81CD31C.act_no )
  {
    stru_81CD31C.bits |= 9u;
    stru_81CD31C.hit.front = 10240;
    stru_81CD31C.hit.top = 18432;
    stru_81CD31C.hit.back = 10240;
    stru_81CD31C.hit.bottom = 0x2000;
    stru_81CD31C.act_no = 1;
    goto LABEL_5;
  }
  if ( stru_81CD31C.act_no == 1 )
  {
LABEL_5:
    stru_81CD31C.x = unk_81CCFC8;
    stru_81CD31C.y = unk_81CCFCC;
  }
}

void ActBossChar_Omega()
{
  int v0;
  int v1;
  bool v2;
  int v3;
  bool v4;
  int v5;
  int v6;
  int v7;
  int v8;
  int v9;
  char *v10;
  RECT rect[4];
  char v12[24];

  switch ( unk_81CD034 )
  {
    case 0:
      unk_81CCFC8 = 1794048;
      unk_81CCFCC = 0x20000;
      unk_81CD04C = 20480;
      unk_81CD050 = 20480;
      unk_81CD054 = 20480;
      unk_81CD058 = 0x2000;
      unk_81CCFE0 = 1794048;
      unk_81CCFE4 = 0x20000;
      unk_81CCFF8 = 52;
      unk_81CD03C = 4096;
      unk_81CD040 = 12288;
      unk_81CD044 = 4096;
      unk_81CD048 = 0x2000;
      unk_81CD010 = -32248;
      unk_81CD008 = 3;
      unk_81CD004 = 1;
      unk_81CCFF0 = 210;
      unk_81CD000 = 400;
      npc.cond = -128;
      npc.view.front = 6144;
      npc.view.top = 4096;
      npc.view.back = 6144;
      npc.view.bottom = 4096;
      npc.bits = 8;
      qmemcpy(&stru_81CD118, &npc, sizeof(stru_81CD118));
      npc.direct = 0;
      stru_81CD118.direct = 2;
      stru_81CD1C4.cond = -128;
      stru_81CD1C4.view.front = 12288;
      stru_81CD1C4.view.top = 0x2000;
      stru_81CD1C4.view.back = 0x2000;
      stru_81CD1C4.view.bottom = 0x2000;
      stru_81CD1C4.hit_voice = 52;
      stru_81CD1C4.hit.front = 4096;
      stru_81CD1C4.hit.top = 4096;
      stru_81CD1C4.hit.back = 4096;
      stru_81CD1C4.hit.bottom = 4096;
      stru_81CD1C4.bits = 8;
      stru_81CD1C4.y = unk_81CCFCC;
      stru_81CD1C4.direct = 0;
      qmemcpy(&stru_81CD270, &stru_81CD1C4, sizeof(stru_81CD270));
      stru_81CD270.direct = 2;
      stru_81CD1C4.x = unk_81CCFC8 + 0x2000;
      stru_81CD31C.cond = -128;
      break;
    case 0x14:
      unk_81CD034 = 30;
      dword_81CD038 = 0;
      unk_81CD028 = 0;
      goto LABEL_4;
    case 0x1E:
LABEL_4:
      SetQuake(2);
      unk_81CCFCC -= 512;
      if ( !(++dword_81CD038 & 3) )
        PlaySoundObject(26, 1);
      if ( dword_81CD038 == 48 )
      {
        dword_81CD038 = 0;
        unk_81CD034 = 40;
        if ( unk_81CD000 <= 280 )
        {
          unk_81CD034 = 110;
          unk_81CD010 |= 0x20u;
          unk_81CD010 &= 0xFFF7u;
          stru_81CD1C4.bits &= 0xFFF7u;
          stru_81CD270.bits &= 0xFFF7u;
          stru_81CD1C4.act_no = 3;
          stru_81CD270.act_no = 3;
          stru_81CD31C.hit.top = 0x2000;
        }
      }
      break;
    case 0x28:
      if ( ++dword_81CD038 == 48 )
      {
        dword_81CD038 = 0;
        unk_81CD034 = 50;
        unk_81CD024 = 0;
        stru_81CD31C.hit.top = 0x2000;
        PlaySoundObject(102, 1);
      }
      break;
    case 0x32:
      if ( ++unk_81CD024 > 2 )
      {
        unk_81CD024 = 0;
        ++unk_81CD028;
      }
      if ( unk_81CD028 == 3 )
      {
        unk_81CD034 = 60;
        dword_81CD038 = 0;
        unk_81CD010 |= 0x20u;
        unk_81CD03C = 0x2000;
        unk_81CD044 = 0x2000;
      }
      break;
    case 0x3C:
      if ( ++dword_81CD038 > 20 && dword_81CD038 <= 79 && !(dword_81CD038 % 3) )
      {
        if ( Random(0, 9) <= 7 )
        {
          v0 = Random(-256, 256);
          SetNpChar(48, unk_81CCFC8, unk_81CCFCC - 0x2000, v0, -819, 0, 0, 256);
        }
        else
        {
          v1 = Random(-256, 256);
          SetNpChar(48, unk_81CCFC8, unk_81CCFCC - 0x2000, v1, -819, 2, 0, 256);
        }
        PlaySoundObject(39, 1);
      }
      v2 = dword_81CD038 == 200 || CountArmsBullet(6);
      if ( v2 )
      {
        unk_81CD024 = 0;
        unk_81CD034 = 70;
        PlaySoundObject(102, 1);
      }
      break;
    case 0x46:
      if ( ++unk_81CD024 > 2 )
      {
        unk_81CD024 = 0;
        --unk_81CD028;
      }
      if ( unk_81CD028 == 1 )
        unk_81CD064 = 20;
      if ( !unk_81CD028 )
      {
        PlaySoundObject(102, 0);
        PlaySoundObject(12, 1);
        unk_81CD034 = 80;
        dword_81CD038 = 0;
        unk_81CD010 &= 0xFFDFu;
        unk_81CD03C = 12288;
        unk_81CD044 = 12288;
        stru_81CD31C.hit.top = 18432;
        unk_81CD064 = 0;
      }
      break;
    case 0x50:
      if ( ++dword_81CD038 == 48 )
      {
        dword_81CD038 = 0;
        unk_81CD034 = 90;
      }
      break;
    case 0x5A:
      SetQuake(2);
      unk_81CCFCC += 512;
      if ( !(++dword_81CD038 & 3) )
        PlaySoundObject(26, 1);
      if ( dword_81CD038 == 48 )
      {
        dword_81CD038 = 0;
        unk_81CD034 = 100;
      }
      break;
    case 0x64:
      if ( ++dword_81CD038 == 120 )
      {
        dword_81CD038 = 0;
        unk_81CD034 = 30;
        v3 = unk_81CCFE0;
        unk_81CCFC8 = v3 + (Random(-64, 64) << 9);
        unk_81CCFCC = unk_81CCFE4;
      }
      break;
    case 0x6E:
      if ( ++unk_81CD024 > 2 )
      {
        unk_81CD024 = 0;
        ++unk_81CD028;
      }
      if ( unk_81CD028 == 3 )
      {
        unk_81CD034 = 120;
        dword_81CD038 = 0;
        unk_81CD03C = 0x2000;
        unk_81CD044 = 0x2000;
      }
      break;
    case 0x78:
      v4 = ++dword_81CD038 == 50 || CountArmsBullet(6);
      if ( v4 )
      {
        unk_81CD034 = 130;
        PlaySoundObject(102, 1);
        dword_81CD038 = 0;
        unk_81CD024 = 0;
      }
      if ( dword_81CD038 <= 29 && !(dword_81CD038 % 5) )
      {
        v5 = Random(-341, 341);
        SetNpChar(48, unk_81CCFC8, unk_81CCFCC - 0x2000, v5, -819, 0, 0, 256);
        PlaySoundObject(39, 1);
      }
      break;
    case 0x82:
      if ( ++unk_81CD024 > 2 )
      {
        unk_81CD024 = 0;
        --unk_81CD028;
      }
      if ( unk_81CD028 == 1 )
        unk_81CD064 = 20;
      if ( !unk_81CD028 )
      {
        unk_81CD034 = 140;
        unk_81CD010 |= 0x20u;
        unk_81CD03C = 0x2000;
        unk_81CD044 = 0x2000;
        unk_81CCFD4 = -1535;
        PlaySoundObject(102, 0);
        PlaySoundObject(12, 1);
        PlaySoundObject(25, 1);
        if ( unk_81CCFC8 < x )
          unk_81CCFD0 = 256;
        if ( unk_81CCFC8 > x )
          unk_81CCFD0 = -256;
        unk_81CD064 = 0;
        stru_81CD31C.hit.top = 18432;
      }
      break;
    case 0x8C:
      if ( dword_81C8584 & 8 && unk_81CCFD4 > 0 )
        stru_81CD31C.damage = 20;
      else
        stru_81CD31C.damage = 0;
      unk_81CCFD4 += 36;
      if ( unk_81CCFD4 > 1535 )
        unk_81CCFD4 = 1535;
      unk_81CCFCC += unk_81CCFD4;
      unk_81CCFC8 += unk_81CCFD0;
      if ( unk_81CCFC4 & 8 )
      {
        unk_81CD034 = 110;
        dword_81CD038 = 0;
        unk_81CD024 = 0;
        stru_81CD31C.hit.top = 0x2000;
        stru_81CD31C.damage = 0;
        PlaySoundObject(26, 1);
        PlaySoundObject(12, 1);
        SetQuake(30);
      }
      break;
    case 0x96:
      SetQuake(2);
      if ( !(++dword_81CD038 % 12) )
        PlaySoundObject(52, 1);
      v6 = unk_81CCFCC;
      v7 = (Random(-48, 24) << 9) + v6;
      v8 = unk_81CCFC8;
      v9 = Random(-48, 48);
      SetDestroyNpChar(v8 + (v9 << 9), v7, 1, 1);
      if ( dword_81CD038 > 100 )
      {
        dword_81CD038 = 0;
        unk_81CD034 = 160;
        SetFlash(unk_81CCFC8, unk_81CCFCC, 1);
        PlaySoundObject(35, 1);
      }
      break;
    case 0xA0:
      SetQuake(40);
      if ( ++dword_81CD038 > 50 )
      {
        gBoss[0].cond = 0;
        npc.cond = 0;
        stru_81CD118.cond = 0;
        stru_81CD1C4.cond = 0;
        stru_81CD270.cond = 0;
        stru_81CD31C.cond = 0;
      }
      break;
    default:
      break;
  }
  rect[0].left = 0;
  rect[0].top = 0;
  rect[0].right = 80;
  rect[0].bottom = 56;
  rect[1].left = 80;
  rect[1].top = 0;
  rect[1].right = 160;
  rect[1].bottom = 56;
  rect[2].left = 160;
  rect[2].top = 0;
  rect[2].right = 240;
  rect[2].bottom = 56;
  rect[3].left = 80;
  rect[3].top = 0;
  rect[3].right = 160;
  rect[3].bottom = 56;
  v10 = &v12[16 * unk_81CD028 - 64];
  unk_81CD014 = *(_DWORD *)v10;
  unk_81CD018 = *((_DWORD *)v10 + 1);
  unk_81CD01C = *((_DWORD *)v10 + 2);
  unk_81CD020 = *((_DWORD *)v10 + 3);
  npc.shock = unk_81CD05C;
  stru_81CD118.shock = unk_81CD05C;
  stru_81CD1C4.shock = unk_81CD05C;
  stru_81CD270.shock = unk_81CD05C;
  ActBoss01_34();
  ActBoss01_12();
  ActBoss01_5();
  if ( !unk_81CD000 && unk_81CD034 <= 149 )
  {
    unk_81CD034 = 150;
    dword_81CD038 = 0;
    unk_81CD064 = 0;
    stru_81CD31C.damage = 0;
    DeleteNpCharCode(48, 1);
  }
}


