#include "types.h"
#include "SDL_stdinc.h"
#include "windows_wrapper.h"
#include "Tags.h"
#include "KeyControl.h"

void InitMyChar();
void __cdecl AnimationMyChar(bool bKey);
void __cdecl ShowMyChar(bool bShow);
void __cdecl PutMyChar(int fx, int fy);
void __cdecl ActMyChar_Normal(bool bKey);
void __cdecl ActMyChar_Stream(bool bKey);
void AirProcess();
void __cdecl ActMyChar(bool bKey);
void __cdecl GetMyCharPosition(int *x, int *y);
void __cdecl SetMyCharPosition(int x, int y);
void __cdecl MoveMyChar(int x, int y);
void ZeroMyCharXMove();
int GetUnitMyChar();
void __cdecl SetMyCharDirect(unsigned __int8 dir);
void __cdecl ChangeMyUnit(unsigned __int8 a);
void PitMyChar();
void __cdecl EquipItem(int flag, bool b);
void ResetCheck();
void __cdecl SetNoise(int no, int freq);
void CutNoise();
void ResetNoise();
void SleepNoise();

_UNKNOWN AnimationMyChar(bool)::C.0;
_UNKNOWN AnimationMyChar(bool)::C.1;

int _noise_no;
Uint32 _noise_freq;

void InitMyChar()
{
  memset(&gMC, 0, 0xB4u);
  gMC.cond = -128;
  dir = 2;
  unk_81C85DC = 4096;
  unk_81C85D8 = 4096;
  unk_81C85D4 = 4096;
  unk_81C85E0 = 4096;
  unk_81C85CC = 2560;
  unk_81C85C8 = 4096;
  unk_81C85C4 = 2560;
  unk_81C85D0 = 4096;
  word_81C8614 = 3;
  unk_81C8618 = 3;
  unk_81C8594 = 0;
}

void __cdecl AnimationMyChar(bool bKey)
{
  char *v1;
  RECT rcRight[12];
  RECT rcLeft[12];
  char v4[24];

  qmemcpy(rcLeft, &AnimationMyChar(bool)::C.0, sizeof(rcLeft));
  qmemcpy(rcRight, &AnimationMyChar(bool)::C.1, sizeof(rcRight));
  if ( !(gMC.cond & 2) )
  {
    if ( dword_81C8584 & 8 )
    {
      if ( gMC.cond & 1 )
      {
        unk_81C85C0 = 11;
      }
      else if ( gKey & gKeyUp && (gKeyRight | gKeyLeft) & gKey && bKey )
      {
        gMC.cond |= 4u;
        if ( ++unk_81C85BC > 4 )
        {
          unk_81C85BC = 0;
          if ( ++unk_81C85C0 == 7 || unk_81C85C0 == 9 )
            PlaySoundObject(24, 1);
        }
        if ( unk_81C85C0 > 9 || unk_81C85C0 <= 5 )
          unk_81C85C0 = 6;
      }
      else if ( (gKeyRight | gKeyLeft) & gKey && bKey )
      {
        gMC.cond |= 4u;
        if ( ++unk_81C85BC > 4 )
        {
          unk_81C85BC = 0;
          if ( ++unk_81C85C0 == 2 || unk_81C85C0 == 4 )
            PlaySoundObject(24, 1);
        }
        if ( unk_81C85C0 > 4 || unk_81C85C0 <= 0 )
          unk_81C85C0 = 1;
      }
      else if ( gKey & gKeyUp && bKey )
      {
        if ( gMC.cond & 4 )
          PlaySoundObject(24, 1);
        gMC.cond &= 0xFBu;
        unk_81C85C0 = 5;
      }
      else
      {
        if ( gMC.cond & 4 )
          PlaySoundObject(24, 1);
        gMC.cond &= 0xFBu;
        unk_81C85C0 = 0;
      }
    }
    else if ( unk_81C858C )
    {
      unk_81C85C0 = 6;
    }
    else if ( unk_81C8590 )
    {
      unk_81C85C0 = 10;
    }
    else if ( unk_81C85B8 <= 0 )
    {
      unk_81C85C0 = 3;
    }
    else
    {
      unk_81C85C0 = 1;
    }
    if ( dir )
      v1 = &v4[16 * unk_81C85C0 - 384];
    else
      v1 = &v4[16 * unk_81C85C0 - 192];
    *(_QWORD *)&xmmword_81C85E4 = *(_QWORD *)v1;
    *((_QWORD *)&xmmword_81C85E4 + 1) = *((_QWORD *)v1 + 1);
  }
}



void __cdecl ShowMyChar(bool bShow)
{
  if ( bShow )
    gMC.cond &= 0xFDu;
  else
    gMC.cond |= 2u;
}

void __cdecl PutMyChar(int fx, int fy)
{
  RECT rcBubble[2];
  RECT rect;
  int arms_offset_y;

  if ( (gMC.cond & 0x80u) != 0 && !(gMC.cond & 2) )
  {
    stru_81C85F4.left = 24 * (gArmsData[gSelectedArms].code % 13);
    stru_81C85F4.right = stru_81C85F4.left + 24;
    stru_81C85F4.top = 96 * (gArmsData[gSelectedArms].code / 13);
    stru_81C85F4.bottom = stru_81C85F4.top + 16;
    if ( dir == 2 )
    {
      stru_81C85F4.top += 16;
      stru_81C85F4.bottom += 16;
    }
    if ( unk_81C858C )
    {
      arms_offset_y = -4;
      stru_81C85F4.top += 32;
      stru_81C85F4.bottom += 32;
    }
    else if ( unk_81C8590 )
    {
      arms_offset_y = 4;
      stru_81C85F4.top += 64;
      stru_81C85F4.bottom += 64;
    }
    else
    {
      arms_offset_y = 0;
    }
    if ( unk_81C85C0 == 1 || unk_81C85C0 == 3 || unk_81C85C0 == 6 || unk_81C85C0 == 8 )
      ++stru_81C85F4.top;
    if ( dir )
      PutBitmap3(
        &grcGame,
        (x - unk_81C85D4) / 512 - fx / 512,
        arms_offset_y + (y - unk_81C85D8) / 512 - fy / 512,
        &stru_81C85F4,
        11);
    else
      PutBitmap3(
        &grcGame,
        (x - unk_81C85D4) / 512 - fx / 512 - 8,
        arms_offset_y + (y - unk_81C85D8) / 512 - fy / 512,
        &stru_81C85F4,
        11);
    if ( !((unk_81C8610 >> 1) & 1) )
    {
      rect = (RECT)xmmword_81C85E4;
      if ( unk_81C8598 & 0x40 )
      {
        rect.top += 32;
        rect.bottom += 32;
      }
      PutBitmap3(&grcGame, (x - unk_81C85D4) / 512 - fx / 512, (y - unk_81C85D8) / 512 - fy / 512, &rect, 16);
      rcBubble[0].left = 56;
      rcBubble[0].top = 96;
      rcBubble[0].right = 80;
      rcBubble[0].bottom = 120;
      rcBubble[1].left = 80;
      rcBubble[1].top = 96;
      rcBubble[1].right = 104;
      rcBubble[1].bottom = 120;
      ++unk_81C8613;
      if ( unk_81C8598 & 0x10 && dword_81C8584 & 0x100 )
      {
        PutBitmap3(&grcGame, x / 512 - 12 - fx / 512, y / 512 - 12 - fy / 512, &rcBubble[(unk_81C8613 >> 1) & 1], 19);
      }
      else if ( unk_81C8594 == 1 )
      {
        PutBitmap3(&grcGame, x / 512 - 12 - fx / 512, y / 512 - 12 - fy / 512, &rcBubble[(unk_81C8613 >> 1) & 1], 19);
      }
    }
  }
}


void __cdecl ActMyChar_Normal(bool bKey)
{
  int x;
  int v2;
  int v3;
  int v4;
  int v5;
  int v6;
  int max_dash;
  int gravity1;
  int gravity2;
  int jump;
  int dash1;
  int dash2;
  int resist;
  int a;
  int aa;
  signed int dir;

  if ( !(gMC.cond & 2) )
  {
    if ( dword_81C8584 & 0x100 )
    {
      max_dash = 406;
      gravity1 = 40;
      gravity2 = 16;
      jump = 640;
      dash1 = 42;
      dash2 = 16;
      resist = 25;
    }
    else
    {
      max_dash = 812;
      gravity1 = 80;
      gravity2 = 32;
      jump = 1280;
      dash1 = 85;
      dash2 = 32;
      resist = 51;
    }
    unk_81C862D = 0;
    if ( bKey != 1 )
      unk_81C862E = 0;
    if ( dword_81C8584 & 8 || dword_81C8584 & 0x10 || dword_81C8584 & 0x20 )
    {
      unk_81C862E = 0;
      if ( unk_81C8598 & 1 )
      {
        unk_81C8630 = 50;
      }
      else if ( unk_81C8598 & 0x20 )
      {
        unk_81C8630 = 50;
      }
      else
      {
        unk_81C8630 = 0;
      }
      if ( bKey )
      {
        if ( gKeyTrg != gKeyDown || gKey != gKeyDown || (gMC.cond & 1) == 1 || g_GameFlags & 4 )
        {
          if ( gKey != gKeyDown )
          {
            if ( gKey & gKeyLeft && unk_81C85B4 > -max_dash )
              unk_81C85B4 -= dash1;
            if ( gKey & gKeyRight && unk_81C85B4 < max_dash )
              unk_81C85B4 += dash1;
            if ( gKey & gKeyLeft )
              ::dir = 0;
            if ( gKey & gKeyRight )
              ::dir = 2;
          }
        }
        else
        {
          gMC.cond |= 1u;
          unk_81C862D = 1;
        }
      }
      if ( !(gMC.cond & 0x20) )
      {
        if ( unk_81C85B4 < 0 )
        {
          if ( unk_81C85B4 <= -resist )
            unk_81C85B4 += resist;
          else
            unk_81C85B4 = 0;
        }
        if ( unk_81C85B4 > 0 )
        {
          if ( unk_81C85B4 >= resist )
            unk_81C85B4 -= resist;
          else
            unk_81C85B4 = 0;
        }
      }
    }
    else
    {
      if ( bKey )
      {
        if ( unk_81C8598 & 0x21 && gKeyTrg & gKeyJump && unk_81C8630 )
        {
          if ( unk_81C8598 & 1 )
          {
            unk_81C862E = 1;
            if ( unk_81C85B8 > 256 )
              unk_81C85B8 /= 2;
          }
          if ( unk_81C8598 & 0x20 )
          {
            if ( gKey & gKeyUp )
            {
              unk_81C862E = 2;
              unk_81C85B4 = 0;
              unk_81C85B8 = -1535;
            }
            else if ( gKey & gKeyLeft )
            {
              unk_81C862E = 1;
              unk_81C85B8 = 0;
              unk_81C85B4 = -1535;
            }
            else if ( gKey & gKeyRight )
            {
              unk_81C862E = 1;
              unk_81C85B8 = 0;
              unk_81C85B4 = 1535;
            }
            else if ( gKey & gKeyDown )
            {
              unk_81C862E = 3;
              unk_81C85B4 = 0;
              unk_81C85B8 = 1535;
            }
            else
            {
              unk_81C862E = 2;
              unk_81C85B4 = 0;
              unk_81C85B8 = -1535;
            }
          }
        }
        if ( gKey & gKeyLeft && unk_81C85B4 > -max_dash )
          unk_81C85B4 -= dash2;
        if ( gKey & gKeyRight && unk_81C85B4 < max_dash )
          unk_81C85B4 += dash2;
        if ( gKey & gKeyLeft )
          ::dir = 0;
        if ( gKey & gKeyRight )
          ::dir = 2;
      }
      if ( unk_81C8598 & 0x20 && unk_81C862E && (!(gKey & gKeyJump) || !unk_81C8630) )
      {
        if ( unk_81C862E == 1 )
        {
          unk_81C85B4 /= 2;
        }
        else if ( unk_81C862E == 2 )
        {
          unk_81C85B8 /= 2;
        }
      }
      if ( !unk_81C8630 || !(gKey & gKeyJump) )
        unk_81C862E = 0;
    }
    if ( bKey )
    {
      unk_81C858C = (gKey & gKeyUp) != 0;
      unk_81C8590 = gKey & gKeyDown && !(dword_81C8584 & 8);
      if ( gKeyTrg & gKeyJump
        && (dword_81C8584 & 8 || dword_81C8584 & 0x10 || dword_81C8584 & 0x20)
        && !(dword_81C8584 & 0x2000) )
      {
        unk_81C85B8 = -jump;
        PlaySoundObject(15, 1);
      }
    }
    if ( bKey && (gKeyShot | gKeyJump | gKeyUp | gKeyRight | gKeyLeft) & gKey )
      gMC.cond &= 0xFEu;
    if ( unk_81C862E && unk_81C8630 )
      --unk_81C8630;
    if ( dword_81C8584 & 0x1000 )
      unk_81C85B4 -= 136;
    if ( dword_81C8584 & 0x2000 )
      unk_81C85B8 -= 128;
    if ( dword_81C8584 & 0x4000 )
      unk_81C85B4 += 136;
    if ( dword_81C8584 & 0x8000 )
      unk_81C85B8 += 85;
    if ( unk_81C8598 & 0x20 && unk_81C862E )
    {
      if ( unk_81C862E == 1 )
      {
        if ( dword_81C8584 & 5 )
          unk_81C85B8 = -256;
        if ( !::dir )
          unk_81C85B4 -= 32;
        if ( ::dir == 2 )
          unk_81C85B4 += 32;
        if ( gKeyTrg & gKeyJump || unk_81C8630 % 3 == 1 )
        {
          if ( !::dir )
            SetCaret(::x + 1024, y + 1024, 7, 2);
          if ( ::dir == 2 )
            SetCaret(::x - 1024, y + 1024, 7, 0);
          PlaySoundObject(113, 1);
        }
      }
      else if ( unk_81C862E == 2 )
      {
        unk_81C85B8 -= 32;
        if ( gKeyTrg & gKeyJump || unk_81C8630 % 3 == 1 )
        {
          SetCaret(::x, y + 3072, 7, 3);
          PlaySoundObject(113, 1);
        }
      }
      else if ( unk_81C862E == 3 && (gKeyTrg & gKeyJump || unk_81C8630 % 3 == 1) )
      {
        SetCaret(::x, y - 3072, 7, 1);
        PlaySoundObject(113, 1);
      }
    }
    else if ( dword_81C8584 & 0x2000 )
    {
      unk_81C85B8 += gravity1;
    }
    else if ( unk_81C8598 & 1 && unk_81C862E && unk_81C85B8 >= -1023 )
    {
      unk_81C85B8 -= 32;
      if ( !(unk_81C8630 % 3) )
      {
        SetCaret(::x, unk_81C85D0 / 2 + y, 7, 3);
        PlaySoundObject(113, 1);
      }
      if ( dword_81C8584 & 2 )
        unk_81C85B8 = 512;
    }
    else if ( unk_81C85B8 < 0 && bKey && gKey & gKeyJump )
    {
      unk_81C85B8 += gravity2;
    }
    else
    {
      unk_81C85B8 += gravity1;
    }
    if ( bKey != 1 || !(gKeyTrg & gKeyJump) )
    {
      if ( dword_81C8584 & 0x10 && unk_81C85B4 < 0 )
        unk_81C85B8 = -unk_81C85B4;
      if ( dword_81C8584 & 0x20 && unk_81C85B4 > 0 )
        unk_81C85B8 = unk_81C85B4;
      if ( dword_81C8584 & 8 && dword_81C8584 & 0x80000 && unk_81C85B4 < 0 )
        unk_81C85B8 = 1024;
      if ( dword_81C8584 & 8 && dword_81C8584 & 0x10000 && unk_81C85B4 > 0 )
        unk_81C85B8 = 1024;
      if ( dword_81C8584 & 8 && dword_81C8584 & 0x20000 && dword_81C8584 & 0x40000 )
        unk_81C85B8 = 1024;
    }
    if ( !(dword_81C8584 & 0x100) || dword_81C8584 & 0xF000 )
    {
      if ( unk_81C85B4 < -1535 )
        unk_81C85B4 = -1535;
      if ( unk_81C85B4 > 1535 )
        unk_81C85B4 = 1535;
      if ( unk_81C85B8 < -1535 )
        unk_81C85B8 = -1535;
      if ( unk_81C85B8 > 1535 )
        unk_81C85B8 = 1535;
    }
    else
    {
      if ( unk_81C85B4 < -767 )
        unk_81C85B4 = -767;
      if ( unk_81C85B4 > 767 )
        unk_81C85B4 = 767;
      if ( unk_81C85B8 < -767 )
        unk_81C85B8 = -767;
      if ( unk_81C85B8 > 767 )
        unk_81C85B8 = 767;
    }
    if ( !unk_81C862C && dword_81C8584 & 0x100 )
    {
      if ( dword_81C8584 & 0x800 )
        dir = 2;
      else
        dir = 0;
      if ( dword_81C8584 & 8 || unk_81C85B8 <= 512 )
      {
        if ( unk_81C85B4 > 512 || unk_81C85B4 < -512 )
        {
          for ( aa = 0; aa <= 7; ++aa )
          {
            v4 = (Random(-8, 8) << 9) + ::x;
            v5 = Random(-512, 128);
            v6 = Random(-512, 512);
            SetNpChar(73, v4, y, v6 + unk_81C85B4, v5, dir, 0, 0);
          }
          PlaySoundObject(56, 1);
        }
      }
      else
      {
        for ( a = 0; a <= 7; ++a )
        {
          x = (Random(-8, 8) << 9) + ::x;
          v2 = Random(-512, 128) - unk_81C85B8 / 2;
          v3 = Random(-512, 512);
          SetNpChar(73, x, y, v3 + unk_81C85B4, v2, dir, 0, 0);
        }
        PlaySoundObject(56, 1);
      }
      unk_81C862C = 1;
    }
    if ( !(dword_81C8584 & 0x100) )
      unk_81C862C = 0;
    if ( dword_81C8584 & 0x400 )
      DamageMyChar(10);
    if ( ::dir )
    {
      unk_81C85AC += 512;
      if ( unk_81C85AC > 0x8000 )
        unk_81C85AC = 0x8000;
    }
    else
    {
      unk_81C85AC -= 512;
      if ( unk_81C85AC < -32768 )
        unk_81C85AC = -32768;
    }
    if ( gKey & gKeyUp && bKey )
    {
      unk_81C85B0 -= 512;
      if ( unk_81C85B0 < -32768 )
        unk_81C85B0 = -32768;
    }
    else if ( gKey & gKeyDown && bKey )
    {
      unk_81C85B0 += 512;
      if ( unk_81C85B0 > 0x8000 )
        unk_81C85B0 = 0x8000;
    }
    else
    {
      if ( unk_81C85B0 > 512 )
        unk_81C85B0 -= 512;
      if ( unk_81C85B0 < -512 )
        unk_81C85B0 += 512;
    }
    unk_81C85A4 = ::x + unk_81C85AC;
    unk_81C85A8 = y + unk_81C85B0;
    if ( unk_81C85B4 > resist || unk_81C85B4 < -resist )
      ::x += unk_81C85B4;
    y += unk_81C85B8;
  }
}

void __cdecl ActMyChar_Stream(bool bKey)
{
  unk_81C858C = 0;
  unk_81C8590 = 0;
  if ( bKey )
  {
    if ( (gKeyRight | gKeyLeft) & gKey )
    {
      if ( gKey & gKeyLeft )
        unk_81C85B4 -= 256;
      if ( gKey & gKeyRight )
        unk_81C85B4 += 256;
    }
    else if ( unk_81C85B4 > 127 || unk_81C85B4 < -127 )
    {
      if ( unk_81C85B4 <= 0 )
        unk_81C85B4 += unk_81C85B4 < 0 ? 0x80 : 0;
      else
        unk_81C85B4 -= 128;
    }
    else
    {
      unk_81C85B4 = 0;
    }
    if ( (gKeyDown | gKeyUp) & gKey )
    {
      if ( gKey & gKeyUp )
        unk_81C85B8 -= 256;
      if ( gKey & gKeyDown )
        unk_81C85B8 += 256;
    }
    else if ( unk_81C85B8 > 127 || unk_81C85B8 < -127 )
    {
      if ( unk_81C85B8 <= 0 )
        unk_81C85B8 += unk_81C85B8 < 0 ? 0x80 : 0;
      else
        unk_81C85B8 -= 128;
    }
    else
    {
      unk_81C85B8 = 0;
    }
  }
  else
  {
    if ( unk_81C85B4 > 127 || unk_81C85B4 < -63 )
    {
      if ( unk_81C85B4 <= 0 )
        unk_81C85B4 += unk_81C85B4 < 0 ? 0x80 : 0;
      else
        unk_81C85B4 -= 128;
    }
    else
    {
      unk_81C85B4 = 0;
    }
    if ( unk_81C85B8 > 127 || unk_81C85B8 < -63 )
    {
      if ( unk_81C85B8 <= 0 )
        unk_81C85B8 += unk_81C85B8 < 0 ? 0x80 : 0;
      else
        unk_81C85B8 -= 128;
    }
    else
    {
      unk_81C85B8 = 0;
    }
  }
  if ( unk_81C85B8 < -512 && dword_81C8584 & 2 )
    SetCaret(x, y - unk_81C85C8, 13, 5);
  if ( unk_81C85B8 > 512 && dword_81C8584 & 8 )
    SetCaret(x, unk_81C85D0 + y, 13, 5);
  if ( unk_81C85B4 > 1024 )
    unk_81C85B4 = 1024;
  if ( unk_81C85B4 < -1024 )
    unk_81C85B4 = -1024;
  if ( unk_81C85B8 > 1024 )
    unk_81C85B8 = 1024;
  if ( unk_81C85B8 < -1024 )
    unk_81C85B8 = -1024;
  if ( (gKey & (gKeyUp | gKeyLeft)) == (gKeyLeft | gKeyUp) )
  {
    if ( unk_81C85B4 < -780 )
      unk_81C85B4 = -780;
    if ( unk_81C85B8 < -780 )
      unk_81C85B8 = -780;
  }
  if ( (gKey & (gKeyUp | gKeyRight)) == (gKeyRight | gKeyUp) )
  {
    if ( unk_81C85B4 > 780 )
      unk_81C85B4 = 780;
    if ( unk_81C85B8 < -780 )
      unk_81C85B8 = -780;
  }
  if ( (gKey & (gKeyDown | gKeyLeft)) == (gKeyLeft | gKeyDown) )
  {
    if ( unk_81C85B4 < -780 )
      unk_81C85B4 = -780;
    if ( unk_81C85B8 > 780 )
      unk_81C85B8 = 780;
  }
  if ( (gKey & (gKeyDown | gKeyRight)) == (gKeyRight | gKeyDown) )
  {
    if ( unk_81C85B4 > 780 )
      unk_81C85B4 = 780;
    if ( unk_81C85B8 > 780 )
      unk_81C85B8 = 780;
  }
  x += unk_81C85B4;
  y += unk_81C85B8;
}

void AirProcess()
{
  if ( unk_81C8598 & 0x10 )
  {
    unk_81C8624 = 1000;
    unk_81C8628 = 0;
  }
  else
  {
    if ( dword_81C8584 & 0x100 )
    {
      if ( --unk_81C8624 <= 0 )
      {
        if ( (unsigned __int8)GetNPCFlag(4000) )
        {
          StartTextScript(1100);
        }
        else
        {
          StartTextScript(41);
          if ( dir )
            SetCaret(x, y, 8, 2);
          else
            SetCaret(x, y, 8, 0);
          gMC.cond &= 0x7Fu;
        }
      }
    }
    else
    {
      unk_81C8624 = 1000;
    }
    if ( dword_81C8584 & 0x100 )
    {
      unk_81C8628 = 60;
    }
    else if ( unk_81C8628 )
    {
      --unk_81C8628;
    }
  }
}

void __cdecl ActMyChar(bool bKey)
{
  if ( (gMC.cond & 0x80u) != 0 )
  {
    if ( unk_81C8608 )
      --unk_81C8608;
    if ( unk_81C8610 )
    {
      --unk_81C8610;
    }
    else if ( value )
    {
      SetValueView(&x, &y, value);
      value = 0;
    }
    if ( unk_81C8594 )
    {
      if ( unk_81C8594 == 1 )
        ActMyChar_Stream(bKey);
    }
    else
    {
      if ( !(g_GameFlags & 4) && bKey )
        AirProcess();
      ActMyChar_Normal(bKey);
    }
    gMC.cond &= 0xDFu;
  }
}

void __cdecl GetMyCharPosition(int *x, int *y)
{
  *x = ::x;
  *y = ::y;
}

void __cdecl SetMyCharPosition(int x, int y)
{
  ::x = x;
  ::y = y;
  unk_81C85A4 = x;
  unk_81C85A8 = y;
  unk_81C85AC = 0;
  unk_81C85B0 = 0;
  unk_81C85B4 = 0;
  unk_81C85B8 = 0;
  gMC.cond &= 0xFEu;
  InitStar();
}

void __cdecl MoveMyChar(int x, int y)
{
  ::x = x;
  ::y = y;
}

void ZeroMyCharXMove()
{
  unk_81C85B4 = 0;
}

int GetUnitMyChar()
{
  return unk_81C8594;
}

void __cdecl SetMyCharDirect(unsigned __int8 dir)
{
  int i;

  if ( dir == 3 )
  {
    gMC.cond |= 1u;
LABEL_13:
    unk_81C85B4 = 0;
    AnimationMyChar(0);
    return;
  }
  gMC.cond &= 0xFEu;
  if ( dir <= 9u )
  {
    ::dir = dir;
    goto LABEL_13;
  }
  for ( i = 0; i <= 511 && gNPC[i].code_event != dir; ++i )
    ;
  if ( i != 512 )
  {
    if ( x <= gNPC[i].x )
      ::dir = 2;
    else
      ::dir = 0;
    goto LABEL_13;
  }
}

void __cdecl ChangeMyUnit(unsigned __int8 a)
{
  unk_81C8594 = a;
}

void PitMyChar()
{
  y += 0x4000;
}

void __cdecl EquipItem(int flag, bool b)
{
  if ( b )
    unk_81C8598 |= flag;
  else
    unk_81C8598 &= ~flag;
}

void ResetCheck()
{
  gMC.cond &= 0xFEu;
}

void __cdecl SetNoise(int no, int freq)
{
  _noise_freq = freq;
  _noise_no = no;
  if ( no == 1 )
  {
    ChangeSoundFrequency(40, _noise_freq);
    ChangeSoundFrequency(41, _noise_freq + 100);
    PlaySoundObject(40, -1);
    PlaySoundObject(41, -1);
  }
  else if ( no == 2 )
  {
    PlaySoundObject(58, -1);
  }
}

void CutNoise()
{
  _noise_no = 0;
  PlaySoundObject(40, 0);
  PlaySoundObject(41, 0);
  PlaySoundObject(58, 0);
}

void ResetNoise()
{
  if ( _noise_no == 1 )
  {
    ChangeSoundFrequency(40, _noise_freq);
    ChangeSoundFrequency(41, _noise_freq + 100);
    PlaySoundObject(40, -1);
    PlaySoundObject(41, -1);
  }
  else if ( _noise_no == 2 )
  {
    PlaySoundObject(58, -1);
  }
}

void SleepNoise()
{
  PlaySoundObject(40, 0);
  PlaySoundObject(41, 0);
  PlaySoundObject(58, 0);
}

