//#include "types.h"
#include "SDL_stdinc.h"
#include "windows_wrapper.h"
#include "Tags.h"

void ActBossChar02_01();
void ActBossChar02_02();
void ActBossChar_Frog();

_UNKNOWN ActBossChar_Frog(void)::C.0;
_UNKNOWN ActBossChar_Frog(void)::C.1;

void ActBossChar02_01()
{
  int minus;

  if ( unk_81CD00C )
    minus = -1;
  else
    minus = 1;
  switch ( unk_81CD028 )
  {
    case 0:
      npc.hit_voice = 52;
      npc.hit.front = 0x2000;
      npc.hit.top = 0x2000;
      npc.hit.back = 0x2000;
      npc.hit.bottom = 0x2000;
      npc.size = 3;
      npc.bits = 4;
      break;
    case 1:
      npc.x = unk_81CCFC8 - 12288 * minus;
      npc.y = unk_81CCFCC - 12288;
      break;
    case 2:
      npc.x = unk_81CCFC8 - 12288 * minus;
      npc.y = unk_81CCFCC - 10240;
      break;
    case 3:
    case 4:
      npc.x = unk_81CCFC8 - 12288 * minus;
      npc.y = unk_81CCFCC - 0x2000;
      break;
    case 5:
      npc.x = unk_81CCFC8 - 12288 * minus;
      npc.y = unk_81CCFCC - 22016;
      break;
    default:
      return;
  }
}

void ActBossChar02_02()
{
  if ( unk_81CD028 )
  {
    if ( unk_81CD028 >= 0 && unk_81CD028 <= 5 )
    {
      stru_81CD118.x = unk_81CCFC8;
      stru_81CD118.y = unk_81CCFCC;
    }
  }
  else
  {
    stru_81CD118.hit_voice = 52;
    stru_81CD118.hit.front = 12288;
    stru_81CD118.hit.top = 0x2000;
    stru_81CD118.hit.back = 12288;
    stru_81CD118.hit.bottom = 0x2000;
    stru_81CD118.size = 3;
    stru_81CD118.bits = 4;
  }
}

void ActBossChar_Frog()
{
  NPCHAR *v0;
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
  int v13;
  int v14;
  char v15;
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
  int v37;
  int v38;
  int v39;
  int v40;
  int v41;
  int v42;
  int v43;
  NPCHAR *v44;
  Sint32 *v45;
  RECT rcRight[9];
  RECT rcLeft[9];
  unsigned __int8 deg;
  int xm;
  int ym;
  int i;
  NPCHAR *boss;
  char v53[24];

  qmemcpy(rcLeft, &ActBossChar_Frog(void)::C.0, sizeof(rcLeft));
  qmemcpy(rcRight, &ActBossChar_Frog(void)::C.1, sizeof(rcRight));
  boss = gBoss;
  switch ( gBoss[0].act_no )
  {
    case 0:
      boss->x = 49152;
      boss->y = 102400;
      boss->direct = 2;
      boss->view.front = 24576;
      boss->view.top = 24576;
      boss->view.back = 0x4000;
      boss->view.bottom = 0x2000;
      boss->hit_voice = 52;
      boss->hit.front = 12288;
      boss->hit.top = 0x2000;
      boss->hit.back = 12288;
      boss->hit.bottom = 0x2000;
      boss->size = 3;
      boss->exp = 1;
      boss->code_event = 1000;
      boss->bits |= 0x8200u;
      boss->life = 300;
      break;
    case 0xA:
      boss->act_no = 11;
      boss->ani_no = 3;
      boss->cond = -128;
      v0 = boss;
      boss->rect.left = rcRight[0].left;
      v0->rect.top = rcRight[0].top;
      v0->rect.right = rcRight[0].right;
      v0->rect.bottom = rcRight[0].bottom;
      npc.cond = -112;
      npc.code_event = 1000;
      stru_81CD118.cond = -128;
      npc.damage = 5;
      stru_81CD118.damage = 5;
      for ( i = 0; i <= 7; ++i )
      {
        v1 = Random(-1536, 0);
        v2 = Random(-341, 341);
        v3 = boss->y;
        v4 = (Random(-12, 12) << 9) + v3;
        v5 = boss->x;
        v6 = Random(-12, 12);
        SetNpChar(4, v5 + (v6 << 9), v4, v2, v1, 0, 0, 256);
      }
      break;
    case 0x14:
      boss->act_no = 21;
      boss->act_wait = 0;
      goto LABEL_8;
    case 0x15:
LABEL_8:
      if ( ++boss->act_wait / 2 & 1 )
        boss->ani_no = 3;
      else
        boss->ani_no = 0;
      break;
    case 0x64:
      boss->act_no = 101;
      boss->act_wait = 0;
      boss->ani_no = 1;
      boss->xm = 0;
      goto LABEL_12;
    case 0x65:
LABEL_12:
      if ( ++boss->act_wait > 50 )
      {
        boss->act_no = 102;
        boss->ani_wait = 0;
        boss->ani_no = 2;
      }
      break;
    case 0x66:
      if ( ++boss->ani_wait > 10 )
      {
        boss->act_no = 103;
        boss->ani_wait = 0;
        boss->ani_no = 1;
      }
      break;
    case 0x67:
      if ( ++boss->ani_wait > 4 )
      {
        boss->act_no = 104;
        boss->ani_no = 5;
        boss->ym = -1024;
        PlaySoundObject(25, 1);
        if ( boss->direct )
          boss->xm = 512;
        else
          boss->xm = -512;
        boss->view.top = 0x8000;
        boss->view.bottom = 12288;
      }
      break;
    case 0x68:
      if ( !boss->direct && boss->flag & 1 )
      {
        boss->direct = 2;
        boss->xm = 512;
      }
      if ( boss->direct == 2 && boss->flag & 4 )
      {
        boss->direct = 0;
        boss->xm = -512;
      }
      if ( boss->flag & 8 )
      {
        PlaySoundObject(26, 1);
        SetQuake(30);
        boss->act_no = 100;
        boss->ani_no = 1;
        boss->view.top = 24576;
        boss->view.bottom = 0x2000;
        if ( !boss->direct && boss->x < x )
        {
          boss->direct = 2;
          boss->act_no = 110;
        }
        if ( boss->direct == 2 && boss->x > x )
        {
          boss->direct = 0;
          boss->act_no = 110;
        }
        v7 = Random(0, 4) << 13;
        v8 = Random(4, 16);
        SetNpChar(110, v8 << 13, v7, 0, 0, 4, 0, 128);
        for ( i = 0; i <= 3; ++i )
        {
          v9 = Random(-1536, 0);
          v10 = Random(-341, 341);
          v11 = boss->y + boss->hit.bottom;
          v12 = boss->x;
          v13 = Random(-12, 12);
          SetNpChar(4, v12 + (v13 << 9), v11, v10, v9, 0, 0, 256);
        }
      }
      break;
    case 0x6E:
      boss->ani_no = 1;
      boss->act_wait = 0;
      boss->act_no = 111;
      goto LABEL_39;
    case 0x6F:
LABEL_39:
      ++boss->act_wait;
      boss->xm = 8 * boss->xm / 9;
      if ( boss->act_wait > 50 )
      {
        boss->ani_no = 2;
        boss->ani_wait = 0;
        boss->act_no = 112;
      }
      break;
    case 0x70:
      if ( ++boss->ani_wait > 4 )
      {
        boss->act_no = 113;
        boss->act_wait = 0;
        boss->ani_no = 3;
        boss->count1 = 16;
        npc.bits |= 0x20u;
        boss->tgt_x = boss->life;
      }
      break;
    case 0x71:
      if ( boss->shock )
      {
        v14 = boss->count2;
        boss->count2 = v14 + 1;
        if ( v14 / 2 & 1 )
          boss->ani_no = 4;
        else
          boss->ani_no = 3;
      }
      else
      {
        boss->count2 = 0;
        boss->ani_no = 3;
      }
      boss->xm = 10 * boss->xm / 11;
      if ( ++boss->act_wait > 16 )
      {
        boss->act_wait = 0;
        --boss->count1;
        deg = boss->direct ? (unsigned __int8)GetArktan(boss->x + 0x4000 - x, boss->y - 4096 - y) : (unsigned __int8)GetArktan(boss->x - 0x4000 - x, boss->y - 4096 - y);
        v15 = Random(-16, 16);
        deg += v15;
        ym = GetSin(deg);
        xm = GetCos(deg);
        if ( boss->direct )
          SetNpChar(108, boss->x + 0x4000, boss->y - 4096, xm, ym, 0, 0, 256);
        else
          SetNpChar(108, boss->x - 0x4000, boss->y - 4096, xm, ym, 0, 0, 256);
        PlaySoundObject(39, 1);
        if ( !boss->count1 || boss->life < boss->tgt_x - 90 )
        {
          boss->act_no = 114;
          boss->act_wait = 0;
          boss->ani_no = 2;
          boss->ani_wait = 0;
          npc.bits &= 0xFFDFu;
        }
      }
      break;
    case 0x72:
      if ( ++boss->ani_wait > 10 )
      {
        if ( ++npc.count1 <= 2 )
        {
          boss->act_no = 100;
        }
        else
        {
          npc.count1 = 0;
          boss->act_no = 120;
        }
        boss->ani_wait = 0;
        boss->ani_no = 1;
      }
      break;
    case 0x78:
      boss->act_no = 121;
      boss->act_wait = 0;
      boss->ani_no = 1;
      boss->xm = 0;
      goto LABEL_64;
    case 0x79:
LABEL_64:
      if ( ++boss->act_wait > 50 )
      {
        boss->act_no = 122;
        boss->ani_wait = 0;
        boss->ani_no = 2;
      }
      break;
    case 0x7A:
      if ( ++boss->ani_wait > 20 )
      {
        boss->act_no = 123;
        boss->ani_wait = 0;
        boss->ani_no = 1;
      }
      break;
    case 0x7B:
      if ( ++boss->ani_wait > 4 )
      {
        boss->act_no = 124;
        boss->ani_no = 5;
        boss->ym = -2560;
        boss->view.top = 0x8000;
        boss->view.bottom = 12288;
        PlaySoundObject(25, 1);
      }
      break;
    case 0x7C:
      if ( boss->flag & 8 )
      {
        PlaySoundObject(26, 1);
        SetQuake(60);
        boss->act_no = 100;
        boss->ani_no = 1;
        boss->view.top = 24576;
        boss->view.bottom = 0x2000;
        for ( i = 0; i <= 1; ++i )
        {
          v16 = Random(0, 4) << 13;
          v17 = Random(4, 16);
          SetNpChar(104, v17 << 13, v16, 0, 0, 4, 0, 128);
        }
        for ( i = 0; i <= 5; ++i )
        {
          v18 = Random(0, 4) << 13;
          v19 = Random(4, 16);
          SetNpChar(110, v19 << 13, v18, 0, 0, 4, 0, 128);
        }
        for ( i = 0; i <= 7; ++i )
        {
          v20 = Random(-1536, 0);
          v21 = Random(-341, 341);
          v22 = boss->y + boss->hit.bottom;
          v23 = boss->x;
          v24 = Random(-12, 12);
          SetNpChar(4, v23 + (v24 << 9), v22, v21, v20, 0, 0, 256);
        }
        if ( !boss->direct && boss->x < x )
        {
          boss->direct = 2;
          boss->act_no = 110;
        }
        if ( boss->direct == 2 && boss->x > x )
        {
          boss->direct = 0;
          boss->act_no = 110;
        }
      }
      break;
    case 0x82:
      boss->act_no = 131;
      boss->ani_no = 3;
      boss->act_wait = 0;
      boss->xm = 0;
      PlaySoundObject(72, 1);
      for ( i = 0; i <= 7; ++i )
      {
        v25 = Random(-1536, 0);
        v26 = Random(-341, 341);
        v27 = boss->y;
        v28 = (Random(-12, 12) << 9) + v27;
        v29 = boss->x;
        v30 = Random(-12, 12);
        SetNpChar(4, v29 + (v30 << 9), v28, v26, v25, 0, 0, 256);
      }
      npc.cond = 0;
      stru_81CD118.cond = 0;
      goto LABEL_90;
    case 0x83:
LABEL_90:
      if ( !(++boss->act_wait % 5) )
      {
        v31 = Random(-1536, 0);
        v32 = Random(-341, 341);
        v33 = boss->y;
        v34 = (Random(-12, 12) << 9) + v33;
        v35 = boss->x;
        v36 = Random(-12, 12);
        SetNpChar(4, v35 + (v36 << 9), v34, v32, v31, 0, 0, 256);
      }
      if ( boss->act_wait / 2 & 1 )
        v37 = boss->x - 512;
      else
        v37 = boss->x + 512;
      boss->x = v37;
      if ( boss->act_wait > 100 )
      {
        boss->act_wait = 0;
        boss->act_no = 132;
      }
      break;
    case 0x84:
      if ( ++boss->act_wait / 2 & 1 )
      {
        boss->view.front = 10240;
        boss->view.top = 6144;
        boss->view.back = 10240;
        boss->view.bottom = 6144;
        boss->ani_no = 6;
      }
      else
      {
        boss->view.front = 24576;
        boss->view.top = 24576;
        boss->view.back = 0x4000;
        boss->view.bottom = 0x2000;
        boss->ani_no = 3;
      }
      if ( !(boss->act_wait % 9) )
      {
        v38 = Random(-1536, 0);
        v39 = Random(-341, 341);
        v40 = boss->y;
        v41 = (Random(-12, 12) << 9) + v40;
        v42 = boss->x;
        v43 = Random(-12, 12);
        SetNpChar(4, v42 + (v43 << 9), v41, v39, v38, 0, 0, 256);
      }
      if ( boss->act_wait > 150 )
      {
        boss->act_no = 140;
        boss->hit.bottom = 6144;
      }
      break;
    case 0x8C:
      boss->act_no = 141;
      goto LABEL_105;
    case 0x8D:
LABEL_105:
      if ( boss->flag & 8 )
      {
        boss->act_no = 142;
        boss->act_wait = 0;
        boss->ani_no = 7;
      }
      break;
    case 0x8E:
      if ( ++boss->act_wait > 30 )
      {
        boss->ani_no = 8;
        boss->ym = -2560;
        boss->bits |= 8u;
        boss->act_no = 143;
      }
      break;
    case 0x8F:
      boss->ym = -2560;
      if ( boss->y < 0 )
      {
        boss->cond = 0;
        PlaySoundObject(26, 1);
        SetQuake(30);
      }
      break;
    default:
      break;
  }
  boss->ym += 64;
  if ( boss->ym > 1535 )
    boss->ym = 1535;
  boss->x += boss->xm;
  boss->y += boss->ym;
  if ( boss->direct )
  {
    v44 = boss;
    v45 = (Sint32 *)&v53[16 * boss->ani_no - 308];
  }
  else
  {
    v44 = boss;
    v45 = (Sint32 *)&v53[16 * boss->ani_no - 164];
  }
  boss->rect.left = *v45;
  v44->rect.top = v45[1];
  v44->rect.right = v45[2];
  v44->rect.bottom = v45[3];
  ActBossChar02_01();
  ActBossChar02_02();
}


