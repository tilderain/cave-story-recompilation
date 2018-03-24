#include "types.h"
#include "stdint.h"
#include "SDL_stdinc.h"
#include "SDL_video.h"
#include "windows_wrapper.h"
#include "Tags.h"
#include "Escape.h"
#include "KeyControl.h"
void ClearArmsData()
{
  gArmsEnergyX = 32;
  memset(gArmsData, 0, 0xA0u);
}

void ClearItemData()
{
  memset(gItemData, 0, 0x80u);
}

signed int __cdecl AddArmsData(int code, int max_num)
{
  int i;

  for ( i = 0; i <= 7 && gArmsData[i].code != code && gArmsData[i].code; ++i )
    ;
  if ( i == 8 )
    return 0;
  if ( !gArmsData[i].code )
  {
    memset((void *)(20 * i + 136105600), 0, 0x14u);
    gArmsData[i].level = 1;
  }
  gArmsData[i].code = code;
  gArmsData[i].max_num += max_num;
  gArmsData[i].num += max_num;
  if ( gArmsData[i].num > gArmsData[i].max_num )
    gArmsData[i].num = gArmsData[i].max_num;
  return 1;
}

signed int __cdecl SubArmsData(int code)
{
  unsigned int v2;
  int i;
  int ia;

  for ( i = 0; i <= 7 && gArmsData[i].code != code; ++i )
    ;
  if ( i == 32 )
    return 0;
  for ( ia = i + 1; ia <= 7; ++ia )
  {
    v2 = 20 * (ia - 1);
    gArmsData[v2 / 0x14].code = gArmsData[ia].code;
    *(_DWORD *)(v2 + 136105604) = gArmsData[ia].level;
    *(_DWORD *)(v2 + 136105608) = gArmsData[ia].exp;
    *(_DWORD *)(v2 + 136105612) = gArmsData[ia].max_num;
    *(_DWORD *)(v2 + 136105616) = gArmsData[ia].num;
  }
  gArmsData[ia - 1].code = 0;
  gSelectedArms = 0;
  return 1;
}

signed int __cdecl TradeArms(int code1, int code2, int max_num)
{
  int i;

  for ( i = 0; i <= 7 && gArmsData[i].code != code1; ++i )
    ;
  if ( i == 8 )
    return 0;
  gArmsData[i].level = 1;
  gArmsData[i].code = code2;
  gArmsData[i].max_num += max_num;
  gArmsData[i].num += max_num;
  gArmsData[i].exp = 0;
  return 1;
}

signed int __cdecl AddItemData(int code)
{
  int i;

  for ( i = 0; i <= 31 && gItemData[i].code != code && gItemData[i].code; ++i )
    ;
  if ( i == 32 )
    return 0;
  gItemData[i].code = code;
  return 1;
}

signed int __cdecl SubItemData(int code)
{
  int i;
  int ia;

  for ( i = 0; i <= 31 && gItemData[i].code != code; ++i )
    ;
  if ( i == 32 )
    return 0;
  for ( ia = i + 1; ia <= 31; ++ia )
    gItemData[ia - 1] = gItemData[ia];
  gItemData[ia - 1].code = 0;
  gSelectedItem = 0;
  return 1;
}

void MoveCampCursor()
{
  bool bChange;
  int arms_num;
  int item_num;

  arms_num = 0;
  item_num = 0;
  while ( gArmsData[arms_num].code != 0 )
    ++arms_num;
  while ( gItemData[item_num].code != 0 )
    ++item_num;
  if ( arms_num || item_num )
  {
    bChange = 0;
    if ( gCampActive )
    {
      if ( gKeyTrg & gKeyLeft )
      {
        if ( gSelectedItem % 6 )
          --gSelectedItem;
        else
          gSelectedItem += 5;
        bChange = 1;
      }
      if ( gKeyTrg & gKeyRight )
      {
        if ( item_num - 1 == gSelectedItem )
        {
          gSelectedItem = 6 * (gSelectedItem / 6);
        }
        else if ( gSelectedItem % 6 == 5 )
        {
          gSelectedItem -= 5;
        }
        else
        {
          ++gSelectedItem;
        }
        bChange = 1;
      }
      if ( gKeyTrg & gKeyUp )
      {
        if ( (unsigned int)(gSelectedItem + 5) > 0xA )
          gSelectedItem -= 6;
        else
          gCampActive = 0;
        bChange = 1;
      }
      if ( gKeyTrg & gKeyDown )
      {
        if ( gSelectedItem / 6 == (item_num - 1) / 6 )
          gCampActive = 0;
        else
          gSelectedItem += 6;
        bChange = 1;
      }
      if ( gSelectedItem >= item_num )
        gSelectedItem = item_num - 1;
      if ( gCampActive && gKeyTrg & gKeyOk )
        StartTextScript(gItemData[gSelectedItem].code + 6000);
    }
    else
    {
      if ( gKeyTrg & gKeyLeft )
      {
        --gSelectedArms;
        bChange = 1;
      }
      if ( gKeyTrg & gKeyRight )
      {
        ++gSelectedArms;
        bChange = 1;
      }
      if ( (gKeyDown | gKeyUp) & gKeyTrg )
      {
        if ( item_num )
          gCampActive = 1;
        bChange = 1;
      }
      if ( gSelectedArms < 0 )
        gSelectedArms = arms_num - 1;
      if ( arms_num - 1 < gSelectedArms )
        gSelectedArms = 0;
    }
    if ( bChange )
    {
      if ( gCampActive )
      {
        PlaySoundObject(1, 1);
        if ( item_num )
          StartTextScript(gItemData[gSelectedItem].code + 5000);
        else
          StartTextScript(5000);
      }
      else
      {
        PlaySoundObject(4, 1);
        if ( arms_num )
          StartTextScript(gArmsData[gSelectedArms].code + 1000);
        else
          StartTextScript(1000);
      }
    }
  }
}

void PutCampObject()
{
  RECT rcCur2[2];
  RECT rcCur1[2];
  RECT rcBoxBottom;
  RECT rcBoxBody;
  RECT rcBoxTop;
  RECT rcTitle2;
  RECT rcTitle1;
  RECT rcView;
  RECT rcLv;
  RECT rcNone;
  RECT rcPer;
  RECT rcItem;
  RECT rcArms;
  int i;

  rcPer.left = 72;
  rcPer.top = 48;
  rcPer.right = 80;
  rcPer.bottom = 56;
  rcNone.left = 80;
  rcNone.top = 48;
  rcNone.right = 96;
  rcNone.bottom = 56;
  rcLv.left = 80;
  rcLv.top = 80;
  rcLv.right = 96;
  rcLv.bottom = 88;
  rcView.left = 0;
  rcView.top = 0;
  rcView.right = 320;
  rcView.bottom = 240;
  rcCur1[0].left = 0;
  rcCur1[0].top = 88;
  rcCur1[0].right = 40;
  rcCur1[0].bottom = 128;
  rcCur1[1].left = 40;
  rcCur1[1].top = 88;
  rcCur1[1].right = 80;
  rcCur1[1].bottom = 128;
  rcCur2[0].left = 80;
  rcCur2[0].top = 88;
  rcCur2[0].right = 112;
  rcCur2[0].bottom = 104;
  rcCur2[1].left = 80;
  rcCur2[1].top = 104;
  rcCur2[1].right = 112;
  rcCur2[1].bottom = 120;
  rcTitle1.left = 80;
  rcTitle1.top = 48;
  rcTitle1.right = 144;
  rcTitle1.bottom = 56;
  rcTitle2.left = 80;
  rcTitle2.top = 56;
  rcTitle2.right = 144;
  rcTitle2.bottom = 64;
  rcBoxTop.left = 0;
  rcBoxTop.top = 0;
  rcBoxTop.right = 244;
  rcBoxTop.bottom = 8;
  rcBoxBody.left = 0;
  rcBoxBody.top = 8;
  rcBoxBody.right = 244;
  rcBoxBody.bottom = 16;
  rcBoxBottom.left = 0;
  rcBoxBottom.top = 16;
  rcBoxBottom.right = 244;
  rcBoxBottom.bottom = 24;
  PutBitmap3(&rcView, 38, 8, &rcBoxTop, 26);
  for ( i = 1; i <= 17; ++i )
    PutBitmap3(&rcView, 38, 8 * (i + 1), &rcBoxBody, 26);
  PutBitmap3(&rcView, 38, 8 * (i + 1), &rcBoxBottom, 26);
  if ( gCampTitleY > 16 )
    --gCampTitleY;
  PutBitmap3(&rcView, 48, gCampTitleY, &rcTitle1, 26);
  PutBitmap3(&rcView, 48, gCampTitleY + 52, &rcTitle2, 26);
  ++PutCampObject(void)::flash;
  if ( gCampActive )
    PutBitmap3(&rcView, 40 * gSelectedArms + 48, 24, &rcCur1[1], 26);
  else
    PutBitmap3(&rcView, 40 * gSelectedArms + 48, 24, &rcCur1[(PutCampObject(void)::flash >> 1) & 1], 26);
  for ( i = 0; i <= 7 && gArmsData[i].code; ++i )
  {
    rcArms.left = 16 * (gArmsData[i].code % 16);
    rcArms.right = rcArms.left + 16;
    rcArms.top = 16 * (gArmsData[i].code / 16);
    rcArms.bottom = rcArms.top + 16;
    PutBitmap3(&rcView, 40 * i + 48, 24, &rcArms, 12);
    PutBitmap3(&rcView, 40 * i + 48, 56, &rcPer, 26);
    PutBitmap3(&rcView, 40 * i + 48, 40, &rcLv, 26);
    PutNumber4(40 * i + 48, 40, gArmsData[i].level, 0);
    if ( gArmsData[i].max_num )
    {
      PutNumber4(40 * i + 48, 48, gArmsData[i].num, 0);
      PutNumber4(40 * i + 48, 56, gArmsData[i].max_num, 0);
    }
    else
    {
      PutBitmap3(&rcView, 40 * i + 64, 48, &rcNone, 26);
      PutBitmap3(&rcView, 40 * i + 64, 56, &rcNone, 26);
    }
  }
  if ( gCampActive == 1 )
    PutBitmap3(
      &rcView,
      32 * (gSelectedItem % 6) + 48,
      16 * (gSelectedItem / 6) + 76,
      &rcCur2[(PutCampObject(void)::flash >> 1) & 1],
      26);
  else
    PutBitmap3(&rcView, 32 * (gSelectedItem % 6) + 48, 16 * (gSelectedItem / 6) + 76, &rcCur2[1], 26);
  for ( i = 0; i <= 31 && gItemData[i].code; ++i )
  {
    rcItem.left = 32 * (gItemData[i].code % 8);
    rcItem.right = rcItem.left + 32;
    rcItem.top = 16 * (gItemData[i].code / 8);
    rcItem.bottom = rcItem.top + 16;
    PutBitmap3(&rcView, 32 * (i % 6) + 48, 16 * (i / 6) + 76, &rcItem, 8);
  }
}

signed int CampLoop()
{
  signed int v0;
  signed int v2;
  char old_script_path[260];
  RECT rcView;
  int arms_num;

  rcView.left = 0;
  rcView.top = 0;
  rcView.right = 320;
  rcView.bottom = 240;
  GetTextScriptPath(old_script_path);
  LoadTextScript2("ArmsItem.tsc");
  gCampTitleY = 24;
  gCampActive = 0;
  gSelectedItem = 0;
  for ( arms_num = 0; gArmsData[arms_num].code != 0; ++arms_num )
    ;
  if ( arms_num )
    StartTextScript(gArmsData[gSelectedArms].code + 1000);
  else
    StartTextScript(gItemData[gSelectedItem].code + 5000);
  while ( 1 )
  {
    GetTrg();
    if ( gKeyTrg & 0x8000 )
    {
      v0 = Call_Escape(gscreen);
      if ( !v0 )
        return 0;
      if ( v0 == 2 )
        return 2;
    }
    if ( g_GameFlags & 2 )
      MoveCampCursor();
    v2 = TextScriptProc();
    if ( !v2 )
      return 0;
    if ( v2 == 2 )
      return 2;
    PutBitmap4(&rcView, 0, 0, &rcView, 10);
    PutCampObject();
    PutTextScript();
    PutFramePerSecound();
    if ( !gCampActive )
      break;
    if ( g_GameFlags & 2 && (gKeyItem | gKeyCancel) & gKeyTrg )
    {
      StopTextScript();
      goto LABEL_28;
    }
LABEL_26:
    if ( !Flip_SystemTask(gscreen) )
      return 0;
  }
  if ( !((gKeyItem | gKeyCancel | gKeyOk) & gKeyTrg) )
    goto LABEL_26;
  StopTextScript();
LABEL_28:
  LoadTextScript_Stage(old_script_path);
  gArmsEnergyX = 32;
  return 1;
}

signed int __cdecl CheckItem(int a)
{
  int i;

  for ( i = 0; i <= 31; ++i )
  {
    if ( gItemData[i].code == a )
      return 1;
  }
  return 0;
}

signed int __cdecl CheckArms(int a)
{
  int i;

  for ( i = 0; i <= 7; ++i )
  {
    if ( gArmsData[i].code == a )
      return 1;
  }
  return 0;
}

signed int __cdecl UseArmsEnergy(int num)
{
  if ( !gArmsData[gSelectedArms].max_num )
    return 1;
  if ( !gArmsData[gSelectedArms].num )
    return 0;
  gArmsData[gSelectedArms].num -= num;
  if ( gArmsData[gSelectedArms].num < 0 )
    gArmsData[gSelectedArms].num = 0;
  return 1;
}

signed int __cdecl ChargeArmsEnergy(int num)
{
  gArmsData[gSelectedArms].num += num;
  if ( gArmsData[gSelectedArms].num > gArmsData[gSelectedArms].max_num )
    gArmsData[gSelectedArms].num = gArmsData[gSelectedArms].max_num;
  return 1;
}

void FullArmsEnergy()
{
  int a;

  for ( a = 0; a <= 7; ++a )
  {
    if ( gArmsData[a].code )
      gArmsData[a].num = gArmsData[a].max_num;
  }
}

int RotationArms()
{
  int arms_num;

  for ( arms_num = 0; gArmsData[arms_num].code != 0; ++arms_num )
    ;
  if ( !arms_num )
    return 0;
  ResetSpurCharge();
  ++gSelectedArms;
  while ( gSelectedArms < arms_num && !gArmsData[gSelectedArms].code )
    ++gSelectedArms;
  if ( gSelectedArms == arms_num )
    gSelectedArms = 0;
  gArmsEnergyX = 32;
  PlaySoundObject(4, 1);
  return gArmsData[gSelectedArms].code;
}

int RotationArmsRev()
{
  int arms_num;

  for ( arms_num = 0; gArmsData[arms_num].code != 0; ++arms_num )
    ;
  if ( !arms_num )
    return 0;
  ResetSpurCharge();
  if ( --gSelectedArms < 0 )
    gSelectedArms = arms_num - 1;
  while ( gSelectedArms < arms_num && !gArmsData[gSelectedArms].code )
    --gSelectedArms;
  gArmsEnergyX = 0;
  PlaySoundObject(4, 1);
  return gArmsData[gSelectedArms].code;
}

void ChangeToFirstArms()
{
  gSelectedArms = 0;
  gArmsEnergyX = 32;
  PlaySoundObject(4, 1);
}




