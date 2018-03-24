#include "stddef.h"
#include "types.h"
#include "types.h"
#include "stdio.h"
#include "libio.h"
#include "stdint.h"
#include "SDL_stdinc.h"
#include "SDL_rwops.h"
#include "SDL_video.h"
#include "windows_wrapper.h"
#include "Tags.h"

signed int IsProfile();
void __cdecl Swap(__int16 *variable);
void __cdecl Swap(int *variable);
void __cdecl ByteSwapProfile($B183609F1A8F1989C6F45ED51C9AAA7D *profile);
signed int __cdecl SaveProfile(char *name);
signed int __cdecl LoadProfile(char *name);
signed int __cdecl InitializeGame();

char *gDefaultName = "Profile.dat";
char *gProfileCode = "Do041220";

signed int IsProfile()
{
  char path[260];
  SDL_RWops_0 *fp;

  sprintf(path, "%s/%s", gModulePath, gDefaultName);
  fp = SDL_RWFromFile(path, "rb");
  if ( !fp )
    return 0;
  fp->close(fp);
  return 1;
}

void __cdecl Swap(__int16 *variable)
{
  *variable = *variable;
}

void __cdecl Swap(int *variable)
{
  *variable = *variable;
}

void __cdecl ByteSwapProfile($B183609F1A8F1989C6F45ED51C9AAA7D *profile)
{
  int arm;
  int item;
  int permit_stage;

  Swap(&profile->stage);
  Swap(&profile->music);
  Swap(&profile->x);
  Swap(&profile->y);
  Swap(&profile->direct);
  Swap(&profile->max_life);
  Swap(&profile->star);
  Swap(&profile->life);
  Swap(&profile->a);
  Swap(&profile->select_arms);
  Swap(&profile->select_item);
  Swap(&profile->equip);
  Swap(&profile->unit);
  Swap(&profile->counter);
  for ( arm = 0; arm <= 7; ++arm )
  {
    Swap(&profile->arms[arm].code);
    Swap(&profile->arms[arm].level);
    Swap(&profile->arms[arm].exp);
    Swap(&profile->arms[arm].max_num);
    Swap(&profile->arms[arm].num);
  }
  for ( item = 0; item <= 31; ++item )
    Swap(&profile->stage + item + 52);
  for ( permit_stage = 0; permit_stage <= 7; ++permit_stage )
  {
    Swap(&profile->stage + 2 * (permit_stage + 42));
    Swap(&profile->music + 2 * (permit_stage + 42));
  }
}

signed int __cdecl SaveProfile(char *name)
{
  $B183609F1A8F1989C6F45ED51C9AAA7D profile;
  char path[260];
  SDL_RWops_0 *fp;
  char *FLAG;

  FLAG = "FLAG";
  if ( name )
    sprintf(path, "%s/%s", gModulePath, name);
  else
    sprintf(path, "%s/%s", gModulePath, gDefaultName);
  fp = SDL_RWFromFile(path, "wb");
  if ( !fp )
    return 0;
  memset(&profile, 0, 0x604u);
  memcpy(&profile, gProfileCode, 8u);
  memcpy(profile.FLAG, FLAG, 4u);
  profile.stage = gStageNo;
  profile.music = gMusicNo;
  profile.x = x;
  profile.y = y;
  profile.direct = dir;
  profile.max_life = unk_81C8618;
  profile.life = word_81C8614;
  profile.star = unk_81C8616;
  profile.select_arms = gSelectedArms;
  profile.select_item = gSelectedItem;
  profile.equip = unk_81C8598;
  profile.unit = unk_81C8594;
  profile.counter = gCounter;
  memcpy(profile.arms, gArmsData, 0xA0u);
  memcpy(profile.items, gItemData, 0x80u);
  memcpy(profile.permitstage, gPermitStage, 0x40u);
  memcpy(profile.permit_mapping, gMapping, 0x80u);
  memcpy(profile.flags, gFlagNPC, 0x3E8u);
  ByteSwapProfile(&profile);
  fp->write(fp, &profile, 1540, 1);
  fp->close(fp);
  return 1;
}

signed int __cdecl LoadProfile(char *name)
{
  $B183609F1A8F1989C6F45ED51C9AAA7D profile;
  char path[260];
  SDL_RWops_0 *fp;

  if ( name )
    strcpy(path, name);
  else
    sprintf(path, "%s/%s", gModulePath, gDefaultName);
  fp = SDL_RWFromFile(path, "rb");
  if ( !fp )
    return 0;
  fp->read(fp, &profile, 8, 1);
  if ( memcmp(&profile, gProfileCode, 8u) )
    return 0;
  fp->seek(fp, 0, 0);
  memset(&profile, 0, 0x604u);
  fp->read(fp, &profile, 1540, 1);
  ByteSwapProfile(&profile);
  fp->close(fp);
  gSelectedArms = profile.select_arms;
  gSelectedItem = profile.select_item;
  gCounter = profile.counter;
  memcpy(gArmsData, profile.arms, 0xA0u);
  memcpy(gItemData, profile.items, 0x80u);
  memcpy(gPermitStage, profile.permitstage, 0x40u);
  memcpy(gMapping, profile.permit_mapping, 0x80u);
  memcpy(gFlagNPC, profile.flags, 0x3E8u);
  ChangeMusic(profile.music);
  InitMyChar();
  if ( (unsigned __int8)TransferStage(profile.stage, 0, 0, 1) ^ 1 )
    return 0;
  unk_81C8598 = profile.equip;
  unk_81C8594 = profile.unit;
  dir = profile.direct;
  unk_81C8618 = profile.max_life;
  word_81C8614 = profile.life;
  unk_81C8616 = profile.star;
  gMC.cond = -128;
  unk_81C8624 = 1000;
  dword_81C861C = profile.life;
  x = profile.x;
  y = profile.y;
  stru_81C85F4.left = 24 * (gArmsData[gSelectedArms].code % 10);
  stru_81C85F4.right = stru_81C85F4.left + 24;
  stru_81C85F4.top = 32 * (gArmsData[gSelectedArms].code / 10);
  stru_81C85F4.bottom = stru_81C85F4.top + 16;
  ClearFade();
  SetFrameMyChar();
  SetFrameTargetMyChar(16);
  InitBossLife();
  CutNoise();
  InitStar();
  ClearValueView();
  gCurlyShoot_wait = 0;
  return 1;
}

signed int __cdecl InitializeGame()
{
  InitMyChar();
  gSelectedArms = 0;
  gSelectedItem = 0;
  gCounter = 0;
  ClearArmsData();
  ClearItemData();
  ClearPermitStage();
  StartMapping();
  InitFlags();
  if ( (unsigned __int8)TransferStage(13, 200, 10, 8) ^ 1 )
    return 0;
  ClearFade();
  SetFrameMyChar();
  SetFrameTargetMyChar(16);
  InitBossLife();
  CutNoise();
  ClearValueView();
  gCurlyShoot_wait = 0;
  SetFadeMask();
  SetFrameTargetMyChar(16);
  return 1;
}

