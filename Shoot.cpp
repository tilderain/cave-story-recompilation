#include "types.h"
#include "SDL_stdinc.h"
#include "windows_wrapper.h"
#include "Tags.h"
#include "KeyControl.h"
void __cdecl ShootBullet_Frontia1(int level)
{
  signed int bul_no;

  switch ( level )
  {
    case 2:
      bul_no = 2;
      break;
    case 3:
      bul_no = 3;
      break;
    case 1:
      bul_no = 1;
      break;
  }
  if ( CountArmsBullet(1) <= 3 && gKeyTrg & gKeyShot )
  {
    if ( (unsigned __int8)UseArmsEnergy(1) ^ 1 )
    {
      ChangeToFirstArms();
    }
    else
    {
      if ( unk_81C858C )
      {
        if ( dir )
        {
          SetBullet(bul_no, x + 1536, y - 5120, 1);
          SetCaret(x + 1536, y - 5120, 3, 0);
        }
        else
        {
          SetBullet(bul_no, x - 1536, y - 5120, 1);
          SetCaret(x - 1536, y - 5120, 3, 0);
        }
      }
      else if ( unk_81C8590 )
      {
        if ( dir )
        {
          SetBullet(bul_no, x + 1536, y + 5120, 3);
          SetCaret(x + 1536, y + 5120, 3, 0);
        }
        else
        {
          SetBullet(bul_no, x - 1536, y + 5120, 3);
          SetCaret(x - 1536, y + 5120, 3, 0);
        }
      }
      else if ( dir )
      {
        SetBullet(bul_no, x + 3072, y + 1024, 2);
        SetCaret(x + 6144, y + 1024, 3, 0);
      }
      else
      {
        SetBullet(bul_no, x - 3072, y + 1024, 0);
        SetCaret(x - 6144, y + 1024, 3, 0);
      }
      PlaySoundObject(33, 1);
    }
  }
}

void __cdecl ShootBullet_PoleStar(int level)
{
  signed int bul_no;

  switch ( level )
  {
    case 2:
      bul_no = 5;
      break;
    case 3:
      bul_no = 6;
      break;
    case 1:
      bul_no = 4;
      break;
  }
  if ( CountArmsBullet(2) <= 1 && gKeyTrg & gKeyShot )
  {
    if ( (unsigned __int8)UseArmsEnergy(1) ^ 1 )
    {
      PlaySoundObject(37, 1);
    }
    else
    {
      if ( unk_81C858C )
      {
        if ( dir )
        {
          SetBullet(bul_no, x + 512, y - 4096, 1);
          SetCaret(x + 512, y - 4096, 3, 0);
        }
        else
        {
          SetBullet(bul_no, x - 512, y - 4096, 1);
          SetCaret(x - 512, y - 4096, 3, 0);
        }
      }
      else if ( unk_81C8590 )
      {
        if ( dir )
        {
          SetBullet(bul_no, x + 512, y + 4096, 3);
          SetCaret(x + 512, y + 4096, 3, 0);
        }
        else
        {
          SetBullet(bul_no, x - 512, y + 4096, 3);
          SetCaret(x - 512, y + 4096, 3, 0);
        }
      }
      else if ( dir )
      {
        SetBullet(bul_no, x + 3072, y + 1536, 2);
        SetCaret(x + 6144, y + 1536, 3, 0);
      }
      else
      {
        SetBullet(bul_no, x - 3072, y + 1536, 0);
        SetCaret(x - 6144, y + 1536, 3, 0);
      }
      if ( level == 3 )
        PlaySoundObject(49, 1);
      else
        PlaySoundObject(32, 1);
    }
  }
}

void __cdecl ShootBullet_FireBall(int level)
{
  signed int bul_no;

  switch ( level )
  {
    case 2:
      if ( CountArmsBullet(3) > 2 )
        return;
      bul_no = 8;
      break;
    case 3:
      if ( CountArmsBullet(3) > 3 )
        return;
      bul_no = 9;
      break;
    case 1:
      if ( CountArmsBullet(3) > 1 )
        return;
      bul_no = 7;
      break;
  }
  if ( gKeyTrg & gKeyShot )
  {
    if ( (unsigned __int8)UseArmsEnergy(1) ^ 1 )
    {
      ChangeToFirstArms();
    }
    else
    {
      if ( unk_81C858C )
      {
        if ( dir )
        {
          SetBullet(bul_no, x + 2048, y - 4096, 1);
          SetCaret(x + 2048, y - 4096, 3, 0);
        }
        else
        {
          SetBullet(bul_no, x - 2048, y - 4096, 1);
          SetCaret(x - 2048, y - 4096, 3, 0);
        }
      }
      else if ( unk_81C8590 )
      {
        if ( dir )
        {
          SetBullet(bul_no, x + 2048, y + 4096, 3);
          SetCaret(x + 2048, y + 4096, 3, 0);
        }
        else
        {
          SetBullet(bul_no, x - 2048, y + 4096, 3);
          SetCaret(x - 2048, y + 4096, 3, 0);
        }
      }
      else if ( dir )
      {
        SetBullet(bul_no, x + 3072, y + 1024, 2);
        SetCaret(x + 6144, y + 1024, 3, 0);
      }
      else
      {
        SetBullet(bul_no, x - 3072, y + 1024, 0);
        SetCaret(x - 6144, y + 1024, 3, 0);
      }
      PlaySoundObject(34, 1);
    }
  }
}

void __cdecl ShootBullet_Machinegun1(int level)
{
  signed int bul_no;

  if ( CountArmsBullet(4) <= 4 )
  {
    switch ( level )
    {
      case 2:
        bul_no = 11;
        break;
      case 3:
        bul_no = 12;
        break;
      case 1:
        bul_no = 10;
        break;
    }
    if ( !(gKey & gKeyShot) )
      unk_81C8612 = 6;
    if ( gKey & gKeyShot )
    {
      if ( ++unk_81C8612 > 5u )
      {
        unk_81C8612 = 0;
        if ( (unsigned __int8)UseArmsEnergy(1) ^ 1 )
        {
          PlaySoundObject(37, 1);
          if ( !_empty )
          {
            SetCaret(x, y, 16, 0);
            _empty = 50;
          }
        }
        else
        {
          if ( unk_81C858C )
          {
            if ( level == 3 )
              unk_81C85B8 += 256;
            if ( dir )
            {
              SetBullet(bul_no, x + 1536, y - 4096, 1);
              SetCaret(x + 1536, y - 4096, 3, 0);
            }
            else
            {
              SetBullet(bul_no, x - 1536, y - 4096, 1);
              SetCaret(x - 1536, y - 4096, 3, 0);
            }
          }
          else if ( unk_81C8590 )
          {
            if ( level == 3 )
            {
              if ( unk_81C85B8 > 0 )
                unk_81C85B8 /= 2;
              if ( unk_81C85B8 >= -1023 )
              {
                unk_81C85B8 -= 512;
                if ( unk_81C85B8 < -1024 )
                  unk_81C85B8 = -1024;
              }
            }
            if ( dir )
            {
              SetBullet(bul_no, x + 1536, y + 4096, 3);
              SetCaret(x + 1536, y + 4096, 3, 0);
            }
            else
            {
              SetBullet(bul_no, x - 1536, y + 4096, 3);
              SetCaret(x - 1536, y + 4096, 3, 0);
            }
          }
          else if ( dir )
          {
            SetBullet(bul_no, x + 6144, y + 1536, 2);
            SetCaret(x + 6144, y + 1536, 3, 0);
          }
          else
          {
            SetBullet(bul_no, x - 6144, y + 1536, 0);
            SetCaret(x - 6144, y + 1536, 3, 0);
          }
          if ( level == 3 )
            PlaySoundObject(49, 1);
          else
            PlaySoundObject(32, 1);
        }
      }
    }
    else
    {
      ++ShootBullet_Machinegun1(long)::wait;
      if ( unk_81C8598 & 8 )
      {
        if ( ShootBullet_Machinegun1(long)::wait > 1 )
        {
          ShootBullet_Machinegun1(long)::wait = 0;
          ChargeArmsEnergy(1);
        }
      }
      else if ( ShootBullet_Machinegun1(long)::wait > 4 )
      {
        ShootBullet_Machinegun1(long)::wait = 0;
        ChargeArmsEnergy(1);
      }
    }
  }
}

void __cdecl ShootBullet_Missile(int level, bool bSuper)
{
  signed int bul_no;

  if ( bSuper )
  {
    switch ( level )
    {
      case 2:
        bul_no = 29;
        break;
      case 3:
        bul_no = 30;
        break;
      case 1:
        bul_no = 28;
        break;
    }
    if ( level == 2 )
    {
      if ( CountArmsBullet(10) > 1 || CountArmsBullet(11) > 1 )
        return;
    }
    else if ( level == 3 )
    {
      if ( CountArmsBullet(10) > 3 || CountArmsBullet(11) > 3 )
        return;
    }
    else if ( level == 1 && (CountArmsBullet(10) > 0 || CountArmsBullet(11) > 0) )
    {
      return;
    }
  }
  else
  {
    switch ( level )
    {
      case 2:
        bul_no = 14;
        break;
      case 3:
        bul_no = 15;
        break;
      case 1:
        bul_no = 13;
        break;
    }
    if ( level == 2 )
    {
      if ( CountArmsBullet(5) > 1 || CountArmsBullet(6) > 1 )
        return;
    }
    else if ( level == 3 )
    {
      if ( CountArmsBullet(5) > 3 || CountArmsBullet(6) > 3 )
        return;
    }
    else if ( level == 1 && (CountArmsBullet(5) > 0 || CountArmsBullet(6) > 0) )
    {
      return;
    }
  }
  if ( !(gKeyTrg & gKeyShot) )
    return;
  if ( level <= 2 )
  {
    if ( (unsigned __int8)UseArmsEnergy(1) ^ 1 )
    {
      PlaySoundObject(37, 1);
      if ( !_empty )
      {
        SetCaret(x, y, 16, 0);
        _empty = 50;
      }
      return;
    }
    if ( unk_81C858C )
    {
      if ( dir )
      {
        SetBullet(bul_no, x + 512, y - 4096, 1);
        SetCaret(x + 512, y - 4096, 3, 0);
      }
      else
      {
        SetBullet(bul_no, x - 512, y - 4096, 1);
        SetCaret(x - 512, y - 4096, 3, 0);
      }
    }
    else if ( unk_81C8590 )
    {
      if ( dir )
      {
        SetBullet(bul_no, x + 512, y + 4096, 3);
        SetCaret(x + 512, y + 4096, 3, 0);
      }
      else
      {
        SetBullet(bul_no, x - 512, y + 4096, 3);
        SetCaret(x - 512, y + 4096, 3, 0);
      }
    }
    else if ( dir )
    {
      SetBullet(bul_no, x + 3072, y, 2);
      SetCaret(x + 6144, y, 3, 0);
    }
    else
    {
      SetBullet(bul_no, x - 3072, y, 0);
      SetCaret(x - 6144, y, 3, 0);
    }
LABEL_68:
    PlaySoundObject(32, 1);
    return;
  }
  if ( !((unsigned __int8)UseArmsEnergy(1) ^ 1) )
  {
    if ( unk_81C858C )
    {
      if ( dir )
      {
        SetBullet(bul_no, x + 512, y - 4096, 1);
        SetCaret(x + 512, y - 4096, 3, 0);
      }
      else
      {
        SetBullet(bul_no, x - 512, y - 4096, 1);
        SetCaret(x - 512, y - 4096, 3, 0);
      }
      SetBullet(bul_no, x + 1536, y, 1);
      SetBullet(bul_no, x - 1536, y, 1);
    }
    else if ( unk_81C8590 )
    {
      if ( dir )
      {
        SetBullet(bul_no, x + 512, y + 4096, 3);
        SetCaret(x + 512, y + 4096, 3, 0);
        SetBullet(bul_no, x - 1536, y, 3);
        SetBullet(bul_no, x + 1536, y, 3);
      }
      else
      {
        SetBullet(bul_no, x - 512, y + 4096, 3);
        SetCaret(x - 512, y + 4096, 3, 0);
        SetBullet(bul_no, x + 1536, y, 3);
        SetBullet(bul_no, x - 1536, y, 3);
      }
    }
    else if ( dir )
    {
      SetBullet(bul_no, x + 3072, y + 512, 2);
      SetCaret(x + 6144, y + 512, 3, 0);
      SetBullet(bul_no, x, y - 4096, 2);
      SetBullet(bul_no, x - 2048, y - 512, 2);
    }
    else
    {
      SetBullet(bul_no, x - 3072, y + 512, 0);
      SetCaret(x - 6144, y + 512, 3, 0);
      SetBullet(bul_no, x, y - 4096, 0);
      SetBullet(bul_no, x + 2048, y - 512, 0);
    }
    goto LABEL_68;
  }
  PlaySoundObject(37, 1);
  if ( !_empty )
  {
    SetCaret(x, y, 16, 0);
    _empty = 50;
  }
}

void ShootBullet_Bubblin1()
{
  if ( CountArmsBullet(7) <= 3 )
  {
    if ( gKeyTrg & gKeyShot )
    {
      if ( (unsigned __int8)UseArmsEnergy(1) ^ 1 )
      {
        PlaySoundObject(37, 1);
        if ( !_empty )
        {
          SetCaret(x, y, 16, 0);
          _empty = 50;
        }
      }
      else
      {
        if ( unk_81C858C )
        {
          if ( dir )
          {
            SetBullet(19, x + 512, y - 1024, 1);
            SetCaret(x + 512, y - 1024, 3, 0);
          }
          else
          {
            SetBullet(19, x - 512, y - 1024, 1);
            SetCaret(x - 512, y - 1024, 3, 0);
          }
        }
        else if ( unk_81C8590 )
        {
          if ( dir )
          {
            SetBullet(19, x + 512, y + 1024, 3);
            SetCaret(x + 512, y + 1024, 3, 0);
          }
          else
          {
            SetBullet(19, x - 512, y + 1024, 3);
            SetCaret(x - 512, y + 1024, 3, 0);
          }
        }
        else if ( dir )
        {
          SetBullet(19, x + 3072, y + 1536, 2);
          SetCaret(x + 6144, y + 1536, 3, 0);
        }
        else
        {
          SetBullet(19, x - 3072, y + 1536, 0);
          SetCaret(x - 6144, y + 1536, 3, 0);
        }
        PlaySoundObject(48, 1);
      }
    }
    else if ( ++ShootBullet_Bubblin1(void)::wait > 20 )
    {
      ShootBullet_Bubblin1(void)::wait = 0;
      ChargeArmsEnergy(1);
    }
  }
}

void __cdecl ShootBullet_Bubblin2(int level)
{
  int levela;

  if ( CountArmsBullet(7) <= 15 )
  {
    levela = level + 18;
    if ( !(gKey & gKeyShot) )
      unk_81C8612 = 6;
    if ( gKey & gKeyShot )
    {
      if ( ++unk_81C8612 > 6u )
      {
        unk_81C8612 = 0;
        if ( (unsigned __int8)UseArmsEnergy(1) ^ 1 )
        {
          PlaySoundObject(37, 1);
          if ( !_empty )
          {
            SetCaret(x, y, 16, 0);
            _empty = 50;
          }
        }
        else
        {
          if ( unk_81C858C )
          {
            if ( dir )
            {
              SetBullet(levela, x + 1536, y - 4096, 1);
              SetCaret(x + 1536, y - 0x2000, 3, 0);
            }
            else
            {
              SetBullet(levela, x - 1536, y - 4096, 1);
              SetCaret(x - 1536, y - 0x2000, 3, 0);
            }
          }
          else if ( unk_81C8590 )
          {
            if ( dir )
            {
              SetBullet(levela, x + 1536, y + 4096, 3);
              SetCaret(x + 1536, y + 0x2000, 3, 0);
            }
            else
            {
              SetBullet(levela, x - 1536, y + 4096, 3);
              SetCaret(x - 1536, y + 0x2000, 3, 0);
            }
          }
          else if ( dir )
          {
            SetBullet(levela, x + 3072, y + 1536, 2);
            SetCaret(x + 6144, y + 1536, 3, 0);
          }
          else
          {
            SetBullet(levela, x - 3072, y + 1536, 0);
            SetCaret(x - 6144, y + 1536, 3, 0);
          }
          PlaySoundObject(48, 1);
        }
      }
    }
    else if ( ++ShootBullet_Bubblin2(long)::wait > 1 )
    {
      ShootBullet_Bubblin2(long)::wait = 0;
      ChargeArmsEnergy(1);
    }
  }
}

void __cdecl ShootBullet_Sword(int level)
{
  signed int bul_no;

  if ( CountArmsBullet(9) <= 0 )
  {
    switch ( level )
    {
      case 2:
        bul_no = 26;
        break;
      case 3:
        bul_no = 27;
        break;
      case 1:
        bul_no = 25;
        break;
    }
    if ( gKeyTrg & gKeyShot )
    {
      if ( unk_81C858C )
      {
        if ( dir )
          SetBullet(bul_no, x + 512, y + 2048, 1);
        else
          SetBullet(bul_no, x - 512, y + 2048, 1);
      }
      else if ( unk_81C8590 )
      {
        if ( dir )
          SetBullet(bul_no, x + 512, y - 3072, 3);
        else
          SetBullet(bul_no, x - 512, y - 3072, 3);
      }
      else if ( dir )
      {
        SetBullet(bul_no, x - 3072, y - 1536, 2);
      }
      else
      {
        SetBullet(bul_no, x + 3072, y - 1536, 0);
      }
      PlaySoundObject(34, 1);
    }
  }
}

void __cdecl ShootBullet_Nemesis(int level)
{
  signed int bul_no;

  switch ( level )
  {
    case 2:
      bul_no = 35;
      break;
    case 3:
      bul_no = 36;
      break;
    case 1:
      bul_no = 34;
      break;
  }
  if ( CountArmsBullet(12) <= 1 && gKeyTrg & gKeyShot )
  {
    if ( (unsigned __int8)UseArmsEnergy(1) ^ 1 )
    {
      PlaySoundObject(37, 1);
    }
    else
    {
      if ( unk_81C858C )
      {
        if ( dir )
        {
          SetBullet(bul_no, x + 512, y - 6144, 1);
          SetCaret(x + 512, y - 6144, 3, 0);
        }
        else
        {
          SetBullet(bul_no, x - 512, y - 6144, 1);
          SetCaret(x - 512, y - 6144, 3, 0);
        }
      }
      else if ( unk_81C8590 )
      {
        if ( dir )
        {
          SetBullet(bul_no, x + 512, y + 6144, 3);
          SetCaret(x + 512, y + 6144, 3, 0);
        }
        else
        {
          SetBullet(bul_no, x - 512, y + 6144, 3);
          SetCaret(x - 512, y + 6144, 3, 0);
        }
      }
      else if ( dir )
      {
        SetBullet(bul_no, x + 11264, y + 1536, 2);
        SetCaret(x + 0x2000, y + 1536, 3, 0);
      }
      else
      {
        SetBullet(bul_no, x - 11264, y + 1536, 0);
        SetCaret(x - 0x2000, y + 1536, 3, 0);
      }
      switch ( level )
      {
        case 2:
          PlaySoundObject(49, 1);
          break;
        case 3:
          PlaySoundObject(60, 1);
          break;
        case 1:
          PlaySoundObject(117, 1);
          break;
      }
    }
  }
}

void ResetSpurCharge()
{
  _spur_charge = 0;
  if ( gArmsData[gSelectedArms].code == 13 )
    ZeroExpMyChar();
}

void __cdecl ShootBullet_Spur(int level)
{
  bool v1;
  signed int bul_no;
  bool bShot;

  bShot = 0;
  if ( gKey & gKeyShot )
  {
    if ( unk_81C8598 & 8 )
      AddExpMyChar(3);
    else
      AddExpMyChar(2);
    if ( ++_spur_charge / 2 & 1 )
    {
      switch ( level )
      {
        case 2:
          PlaySoundObject(60, 1);
          break;
        case 3:
          if ( (unsigned __int8)IsMaxExpMyChar() ^ 1 )
            PlaySoundObject(61, 1);
          break;
        case 1:
          PlaySoundObject(59, 1);
          break;
      }
    }
  }
  else
  {
    if ( _spur_charge )
      bShot = 1;
    _spur_charge = 0;
  }
  if ( (unsigned __int8)IsMaxExpMyChar() )
  {
    if ( ShootBullet_Spur(long)::_bMax != 1 )
    {
      ShootBullet_Spur(long)::_bMax = 1;
      PlaySoundObject(65, 1);
    }
  }
  else
  {
    ShootBullet_Spur(long)::_bMax = 0;
  }
  if ( !(gKey & gKeyShot) )
    ZeroExpMyChar();
  switch ( level )
  {
    case 2:
      bul_no = 37;
      break;
    case 3:
      if ( ShootBullet_Spur(long)::_bMax )
        bul_no = 39;
      else
        bul_no = 38;
      break;
    case 1:
      bul_no = 6;
      bShot = 0;
      break;
  }
  v1 = CountArmsBullet(13) > 0 || CountArmsBullet(14) > 0;
  if ( !v1 && (gKeyTrg & gKeyShot || bShot) )
  {
    if ( (unsigned __int8)UseArmsEnergy(1) ^ 1 )
    {
      PlaySoundObject(37, 1);
    }
    else
    {
      if ( unk_81C858C )
      {
        if ( dir )
        {
          SetBullet(bul_no, x + 512, y - 4096, 1);
          SetCaret(x + 512, y - 4096, 3, 0);
        }
        else
        {
          SetBullet(bul_no, x - 512, y - 4096, 1);
          SetCaret(x - 512, y - 4096, 3, 0);
        }
      }
      else if ( unk_81C8590 )
      {
        if ( dir )
        {
          SetBullet(bul_no, x + 512, y + 4096, 3);
          SetCaret(x + 512, y + 4096, 3, 0);
        }
        else
        {
          SetBullet(bul_no, x - 512, y + 4096, 3);
          SetCaret(x - 512, y + 4096, 3, 0);
        }
      }
      else if ( dir )
      {
        SetBullet(bul_no, x + 3072, y + 1536, 2);
        SetCaret(x + 6144, y + 1536, 3, 0);
      }
      else
      {
        SetBullet(bul_no, x - 3072, y + 1536, 0);
        SetCaret(x - 6144, y + 1536, 3, 0);
      }
      if ( bul_no == 37 )
      {
        PlaySoundObject(62, 1);
      }
      else if ( bul_no > 37 )
      {
        if ( bul_no == 38 )
        {
          PlaySoundObject(63, 1);
        }
        else if ( bul_no == 39 )
        {
          PlaySoundObject(64, 1);
        }
      }
      else if ( bul_no == 6 )
      {
        PlaySoundObject(49, 1);
      }
    }
  }
}

void ShootBullet()
{
  int v0;
  int v1;

  if ( _empty )
    --_empty;
  if ( ShootBullet(void)::soft_rensha )
    --ShootBullet(void)::soft_rensha;
  if ( gKeyTrg & gKeyShot )
  {
    if ( ShootBullet(void)::soft_rensha )
      return;
    ShootBullet(void)::soft_rensha = 4;
  }
  if ( !(gMC.cond & 2) )
  {
    switch ( gArmsData[gSelectedArms].code )
    {
      case 1:
        ShootBullet_Frontia1(gArmsData[gSelectedArms].level);
        break;
      case 2:
        ShootBullet_PoleStar(gArmsData[gSelectedArms].level);
        break;
      case 3:
        ShootBullet_FireBall(gArmsData[gSelectedArms].level);
        break;
      case 4:
        ShootBullet_Machinegun1(gArmsData[gSelectedArms].level);
        break;
      case 5:
        ShootBullet_Missile(gArmsData[gSelectedArms].level, 0);
        break;
      case 7:
        v0 = gArmsData[gSelectedArms].level;
        switch ( v0 )
        {
          case 2:
            ShootBullet_Bubblin2(2);
            break;
          case 3:
            ShootBullet_Bubblin2(3);
            break;
          case 1:
            ShootBullet_Bubblin1();
            break;
        }
        break;
      case 9:
        v1 = gArmsData[gSelectedArms].level;
        switch ( v1 )
        {
          case 2:
            ShootBullet_Sword(2);
            break;
          case 3:
            ShootBullet_Sword(3);
            break;
          case 1:
            ShootBullet_Sword(1);
            break;
        }
        break;
      case 0xA:
        ShootBullet_Missile(gArmsData[gSelectedArms].level, 1);
        break;
      case 0xC:
        ShootBullet_Nemesis(gArmsData[gSelectedArms].level);
        break;
      case 0xD:
        ShootBullet_Spur(gArmsData[gSelectedArms].level);
        break;
      default:
        return;
    }
  }
}

