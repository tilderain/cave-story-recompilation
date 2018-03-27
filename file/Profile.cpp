#include "stddef.h"
//#include "types.h"
//#include "types.h"
#include "stdio.h"
//#include "libio.h"
#include "stdint.h"
#include "SDL_stdinc.h"
#include "SDL_rwops.h"
#include "SDL_video.h"
#include "windows_wrapper.h"
#include "Tags.h"

signed int IsProfile();
void Swap(__int16 *variable);
void Swap(int *variable);
void ByteSwapProfile(ProfileData *profile);
signed int SaveProfile(char *name);
signed int LoadProfile(char *name);
signed int InitializeGame();

char *gDefaultName = "Profile.dat";
char *gProfileCode = "Do041220";

struct ProfileData
{
  char code[8];
  int stage;
  int music;
  int x;
  int y;
  int direct;
  __int16 max_life;
  __int16 star;
  __int16 life;
  __int16 a;
  int select_arms;
  int select_item;
  int equip;
  int unit;
  int counter;
  $D3B267130C558B6C8C7B7A80A5697BE6 arms[8];
  $4010822F30180CACF39DC1B3C7E9022D items[32];
  $DC890D5E5AA9C328B36A6715ACB40917 permitstage[8];
  char permit_mapping[128];
  char FLAG[4];
  unsigned __int8 flags[1000];
};


signed int IsProfile()
{
  char path[260];
  SDL_RWops *fp;

  sprintf(path, "%s/%s", gModulePath, gDefaultName);
  fp = SDL_RWFromFile(path, "rb");
  if ( !fp )
    return 0;
  fp->close(fp);
  return 1;
}

void Swap(__int16 *variable)
{
  *variable = *variable;
}

void Swap(int *variable)
{
  *variable = *variable;
}

void ByteSwapProfile(ProfileData *profile)
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

signed int SaveProfile(char *name)
{
  ProfileData profile;
  char path[260];
  SDL_RWops *fp;
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
  profile.star = star_count;
  profile.select_arms = gSelectedArms;
  profile.select_item = gSelectedItem;
  profile.equip = star_flag;
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

signed int LoadProfile(char *name)
{
  ProfileData profile;
  char path[260];
  SDL_RWops *fp;

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
  star_flag = profile.equip;
  unk_81C8594 = profile.unit;
  dir = profile.direct;
  unk_81C8618 = profile.max_life;
  word_81C8614 = profile.life;
  star_count = profile.star;
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

signed int InitializeGame()
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

