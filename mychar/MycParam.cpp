//#include "types.h"
#include "stddef.h"
//#include "types.h"
#include "stdio.h"
//#include "libio.h"
#include "stdint.h"
#include "SDL_stdinc.h"
#include "SDL_rwops.h"
#include "windows_wrapper.h"
#include "Tags.h"
#include "MycParam.h"

unsigned __int8 PutArmsEnergy(bool)::add_flash;

int _time_count;

$74F7120D52ED14132C5D5934E9BCA40C gArmsLevelTable[14] =
{
  { { 0, 0, 100 } },
  { { 30, 40, 16 } },
  { { 10, 20, 10 } },
  { { 10, 20, 20 } },
  { { 30, 40, 10 } },
  { { 10, 20, 10 } },
  { { 10, 20, 30 } },
  { { 10, 20, 5 } },
  { { 10, 20, 100 } },
  { { 30, 60, 0 } },
  { { 30, 60, 10 } },
  { { 10, 20, 100 } },
  { { 1, 1, 1 } },
  { { 40, 60, 200 } }
};

void AddExpMyChar(int x)
{
  int lv;
  int arms_code;

  lv = gArmsData[gSelectedArms].level - 1;
  arms_code = gArmsData[gSelectedArms].code;
  gArmsData[gSelectedArms].exp += x;
  if ( lv == 2 )
  {
    if ( gArmsData[gSelectedArms].exp >= gArmsLevelTable[0].exp[3 * arms_code + 2] )
    {
      gArmsData[gSelectedArms].exp = gArmsLevelTable[0].exp[3 * arms_code + 2];
      if ( star_flag & 0x80 )
      {
        if ( star_count <= 2 )
          ++star_count;
      }
    }
  }
  else
  {
    while ( lv <= 1 )
    {
      if ( gArmsData[gSelectedArms].exp >= gArmsLevelTable[0].exp[lv + 3 * arms_code] )
      {
        ++gArmsData[gSelectedArms].level;
        gArmsData[gSelectedArms].exp = 0;
        if ( gArmsData[gSelectedArms].code != 13 )
        {
          PlaySoundObject(27, 1);
          SetCaret(::x, y, 10, 0);
        }
      }
      ++lv;
    }
  }
  if ( gArmsData[gSelectedArms].code == 13 )
  {
    unk_81C8608 = 10;
  }
  else
  {
    value += x;
    unk_81C8608 = 30;
  }
}

void ZeroExpMyChar()
{
  gArmsData[gSelectedArms].level = 1;
  gArmsData[gSelectedArms].exp = 0;
}

bool IsMaxExpMyChar()
{
  return gArmsData[gSelectedArms].level == 3
      && gArmsData[gSelectedArms].exp >= gArmsLevelTable[gArmsData[gSelectedArms].code].exp[2];
}

void DamageMyChar(int damage)
{
  int v1;

  if ( !unk_81C8610 )
  {
    PlaySoundObject(16, 1);
    gMC.cond &= 0xFEu;
    unk_81C8610 = -128;
    if ( unk_81C8594 != 1 )
      unk_81C85B8 = -1024;
    word_81C8614 -= damage;
    if ( star_flag & 0x80 && star_count > 0 )
      --star_count;
    if ( star_flag & 4 )
      v1 = gArmsData[gSelectedArms].exp - damage;
    else
      v1 = gArmsData[gSelectedArms].exp - 2 * damage;
    gArmsData[gSelectedArms].exp = v1;
    while ( gArmsData[gSelectedArms].exp < 0 )
    {
      if ( gArmsData[gSelectedArms].level <= 1 )
      {
        gArmsData[gSelectedArms].exp = 0;
      }
      else
      {
        gArmsData[gSelectedArms].exp += gArmsLevelTable[0].exp[--gArmsData[gSelectedArms].level
                                                             - 1
                                                             + 3 * gArmsData[gSelectedArms].code];
        if ( word_81C8614 > 0 && gArmsData[gSelectedArms].code != 13 )
          SetCaret(x, y, 10, 2);
      }
    }
    SetValueView(&x, &y, -damage);
    if ( word_81C8614 <= 0 )
    {
      PlaySoundObject(17, 1);
      gMC.cond = 0;
      SetDestroyNpChar(x, y, 5120, 64);
      StartTextScript(40);
    }
  }
}

void ZeroArmsEnergy_All()
{
  int a;

  for ( a = 0; a <= 7; ++a )
  {
    gArmsData[a].level = 1;
    gArmsData[a].exp = 0;
  }
}

void AddBulletMyChar(int no, int val)
{
  char v2;
  char v3;
  int a;

  for ( a = 0; ; ++a )
  {
    v2 = a > 7 || gArmsData[a].code == 5 ? 0 : 1;
    if ( !v2 )
      break;
  }
  if ( a != 8 )
    goto LABEL_21;
  for ( a = 0; ; ++a )
  {
    v3 = a > 7 || gArmsData[a].code == 10 ? 0 : 1;
    if ( !v3 )
      break;
  }
  if ( a != 8 )
  {
LABEL_21:
    gArmsData[a].num += val;
    if ( gArmsData[a].num > gArmsData[a].max_num )
      gArmsData[a].num = gArmsData[a].max_num;
  }
}

void AddLifeMyChar(int x)
{
  word_81C8614 += x;
  if ( word_81C8614 > unk_81C8618 )
    word_81C8614 = unk_81C8618;
  dword_81C861C = word_81C8614;
}

void AddMaxLifeMyChar(int val)
{
  unk_81C8618 += val;
  if ( unk_81C8618 > 232 )
    unk_81C8618 = 232;
  word_81C8614 += val;
  dword_81C861C = word_81C8614;
}

void PutArmsEnergy(bool flash)
{
  char v1;
  bool v2;
  RECT rcExpFlash;
  RECT rcExpMax;
  RECT rcExpVal;
  RECT rcExpBox;
  RECT rcNone;
  RECT rcView;
  RECT rcLv;
  RECT rcPer;
  int lv;
  int arms_code;
  int exp_now;
  int exp_next;

  rcPer.left = 72;
  rcPer.top = 48;
  rcPer.right = 80;
  rcPer.bottom = 56;
  rcLv.left = 80;
  rcLv.top = 80;
  rcLv.right = 96;
  rcLv.bottom = 88;
  rcView.left = 0;
  rcView.top = 0;
  rcView.right = 320;
  rcView.bottom = 240;
  rcNone.left = 80;
  rcNone.top = 48;
  rcNone.right = 96;
  rcNone.bottom = 56;
  if ( gArmsEnergyX > 16 )
    gArmsEnergyX -= 2;
  if ( gArmsEnergyX <= 15 )
    gArmsEnergyX += 2;
  if ( gArmsData[gSelectedArms].max_num )
  {
    PutNumber4(gArmsEnergyX + 32, 16, gArmsData[gSelectedArms].num, 0);
    PutNumber4(gArmsEnergyX + 32, 24, gArmsData[gSelectedArms].max_num, 0);
  }
  else
  {
    PutBitmap3(&rcView, gArmsEnergyX + 48, 16, &rcNone, 26);
    PutBitmap3(&rcView, gArmsEnergyX + 48, 24, &rcNone, 26);
  }
  if ( !flash || !((unk_81C8610 >> 1) & 1) )
  {
    PutBitmap3(&rcView, gArmsEnergyX + 32, 24, &rcPer, 26);
    PutBitmap3(&rcView, gArmsEnergyX, 32, &rcLv, 26);
    PutNumber4(gArmsEnergyX - 8, 32, gArmsData[gSelectedArms].level, 0);
    rcExpBox.left = 0;
    rcExpBox.top = 72;
    rcExpBox.right = 40;
    rcExpBox.bottom = 80;
    rcExpVal.left = 0;
    rcExpVal.top = 80;
    rcExpVal.right = 0;
    rcExpVal.bottom = 88;
    rcExpMax.left = 40;
    rcExpMax.top = 72;
    rcExpMax.right = 80;
    rcExpMax.bottom = 80;
    rcExpFlash.left = 40;
    rcExpFlash.top = 80;
    rcExpFlash.right = 80;
    rcExpFlash.bottom = 88;
    lv = gArmsData[gSelectedArms].level - 1;
    arms_code = gArmsData[gSelectedArms].code;
    exp_now = gArmsData[gSelectedArms].exp;
    exp_next = gArmsLevelTable[0].exp[lv + 3 * arms_code];
    PutBitmap3(&rcView, gArmsEnergyX + 24, 32, &rcExpBox, 26);
    if ( lv != 2 || gArmsData[gSelectedArms].exp != gArmsLevelTable[0].exp[3 * arms_code + 2] )
    {
      if ( exp_next )
        rcExpVal.right += 40 * exp_now / exp_next;
      else
        rcExpVal.right = 0;
      PutBitmap3(&rcView, gArmsEnergyX + 24, 32, &rcExpVal, 26);
    }
    else
    {
      PutBitmap3(&rcView, gArmsEnergyX + 24, 32, &rcExpMax, 26);
    }
    v2 = 0;
    if ( unk_81C8608 )
    {
      v1 = (PutArmsEnergy(bool)::add_flash++ >> 1) & 1;
      if ( v1 )
        v2 = 1;
    }
    if ( v2 )
      PutBitmap3(&rcView, gArmsEnergyX + 24, 32, &rcExpFlash, 26);
  }
}

void PutActiveArmsList()
{
  RECT rect;
  int x;
  int a;
  int arms_num;

  rect.left = 0;
  rect.top = 0;
  rect.right = 0;
  rect.bottom = 16;
  for ( arms_num = 0; gArmsData[arms_num].code != 0; ++arms_num )
    ;
  if ( arms_num )
  {
    for ( a = 0; a < arms_num; ++a )
    {
      x = 16 * (a - gSelectedArms) + gArmsEnergyX;
      if ( x > 7 )
      {
        if ( x > 23 )
          x += 48;
      }
      else
      {
        x += 16 * (arms_num + 3);
      }
      if ( 8 * (2 * (arms_num + 3) + 1) <= x )
        x += 16 * (-3 - arms_num);
      if ( x <= 71 && x > 23 )
        x -= 48;
      rect.left = 16 * gArmsData[a].code;
      rect.right = rect.left + 16;
      PutBitmap3(&grcGame, x, 16, &rect, 12);
    }
  }
}

void PutMyLife(bool flash)
{
  RECT rcBr;
  RECT rcLife;
  RECT rcCase;

  rcCase.left = 0;
  rcCase.top = 40;
  rcCase.right = 232;
  rcCase.bottom = 48;
  rcLife.left = 0;
  rcLife.top = 24;
  rcLife.right = 232;
  rcLife.bottom = 32;
  rcBr.left = 0;
  rcBr.top = 32;
  rcBr.right = 232;
  rcBr.bottom = 40;
  if ( !flash || !((unk_81C8610 >> 1) & 1) )
  {
    if ( dword_81C861C < word_81C8614 )
      dword_81C861C = word_81C8614;
    if ( dword_81C861C <= word_81C8614 )
    {
      unk_81C8620 = 0;
    }
    else if ( ++unk_81C8620 > 30 )
    {
      --dword_81C861C;
    }
    rcCase.right = 64;
    rcLife.right = 40 * word_81C8614 / unk_81C8618 - 1;
    rcBr.right = 40 * dword_81C861C / unk_81C8618 - 1;
    PutBitmap3(&grcGame, 16, 40, &rcCase, 26);
    PutBitmap3(&grcGame, 40, 40, &rcBr, 26);
    PutBitmap3(&grcGame, 40, 40, &rcLife, 26);
    PutNumber4(8, 40, dword_81C861C, 0);
  }
}

void PutMyAir(int x, int y)
{
  RECT rcAir[2];

  rcAir[0].left = 112;
  rcAir[0].top = 72;
  rcAir[0].right = 144;
  rcAir[0].bottom = 80;
  rcAir[1].left = 112;
  rcAir[1].top = 80;
  rcAir[1].right = 144;
  rcAir[1].bottom = 88;
  if ( !(star_flag & 0x10) && unk_81C8628 )
  {
    if ( unk_81C8628 % 6 <= 3 )
      PutNumber4(x + 32, y, unk_81C8624 / 10, 0);
    if ( unk_81C8624 % 30 <= 10 )
      PutBitmap3(&grcGame, x, y, &rcAir[1], 26);
    else
      PutBitmap3(&grcGame, x, y, rcAir, 26);
  }
}

void PutTimeCounter(int x, int y)
{
  RECT rcTime[3];

  rcTime[0].left = 112;
  rcTime[0].top = 104;
  rcTime[0].right = 120;
  rcTime[0].bottom = 112;
  rcTime[1].left = 120;
  rcTime[1].top = 104;
  rcTime[1].right = 128;
  rcTime[1].bottom = 112;
  rcTime[2].left = 128;
  rcTime[2].top = 104;
  rcTime[2].right = 160;
  rcTime[2].bottom = 112;
  if ( star_flag & 0x100 )
  {
    if ( g_GameFlags & 2 )
    {
      if ( _time_count <= 299999 )
        ++_time_count;
      if ( _time_count % 30 <= 10 )
        PutBitmap3(&grcGame, x, y, &rcTime[1], 26);
      else
        PutBitmap3(&grcGame, x, y, rcTime, 26);
    }
    else
    {
      PutBitmap3(&grcGame, x, y, rcTime, 26);
    }
    PutNumber4(x, y, _time_count / 3000, 0);
    PutNumber4(x + 20, y, _time_count / 50 % 60, 1);
    PutNumber4(x + 32, y, _time_count / 5 % 10, 0);
    PutBitmap3(&grcGame, x + 30, y, &rcTime[2], 26);
  }
  else
  {
    _time_count = 0;
  }
}

signed int SaveTimeCounter()
{
  int v1;
  char path[260];
  $B3FC422DA37A539D80A9413BC091BB99 rec;
  int i;
  unsigned __int8 *p;
  SDL_RWops *fp;

  if ( !(star_flag & 0x100) )
    return 1;
  sprintf(path, "%s/290.rec", gModulePath);
  fp = SDL_RWFromFile(path, "rb");
  if ( fp )
  {
    fp->read(fp, &rec, 20, 1);
    fp->close(fp);
    p = (unsigned __int8 *)&rec;
    LOBYTE(rec.counter[0]) -= rec.random[0];
    BYTE1(rec.counter[0]) -= rec.random[0];
    BYTE2(rec.counter[0]) -= rec.random[0];
    HIBYTE(rec.counter[0]) -= rec.random[0] >> 1;
    if ( rec.counter[0] < _time_count )
      return 1;
  }
  for ( i = 0; i <= 3; ++i )
  {
    rec.counter[i] = _time_count;
    v1 = i;
    rec.random[v1] = Random(0, 250) + i;
    p = (unsigned __int8 *)&rec.counter[i];
    *p += rec.random[i];
    p[1] += rec.random[i];
    p[2] += rec.random[i];
    p[3] += rec.random[i] >> 1;
  }
  fp = SDL_RWFromFile(path, "wb");
  if ( !fp )
    return 0;
  fp->write(fp, &rec, 20, 1);
  fp->close(fp);
  return 1;
}

int LoadTimeCounter()
{
  int result;
  char path[260];
  $B3FC422DA37A539D80A9413BC091BB99 rec;
  int i;
  unsigned __int8 *p;
  SDL_RWops *fp;

  sprintf(path, "%s/290.rec", gModulePath);
  fp = SDL_RWFromFile(path, "rb");
  if ( !fp )
    return 0;
  fp->read(fp, &rec, 20, 1);
  fp->close(fp);
  for ( i = 0; i <= 3; ++i )
  {
    p = (unsigned __int8 *)&rec.counter[i];
    *p -= rec.random[i];
    p[1] -= rec.random[i];
    p[2] -= rec.random[i];
    p[3] -= rec.random[i] >> 1;
  }
  if ( rec.counter[0] == rec.counter[1] && rec.counter[0] == rec.counter[2] )
  {
    _time_count = rec.counter[0];
    result = rec.counter[0];
  }
  else
  {
    _time_count = 0;
    result = 0;
  }
  return result;
}

