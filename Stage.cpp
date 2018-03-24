#include "stddef.h"
#include "types.h"
#include "libio.h"
#include "windows_wrapper.h"
#include "language.h"
#include "stdio.h"
signed int __cdecl TransferStage(int no, int w, int x, int y)
{
  signed int result;
  char path[260];
  char path_dir[20];
  bool bError;
  char *map_name;

  SetMyCharPosition(x << 13, y << 13);
  bError = 0;
  memcpy(path_dir, "Stage", 6u);
  sprintf(path, "%s/Prt%s", path_dir, 232 * no + 136058976);
  if ( !ReloadBitmap_File(path, 2) )
    bError = 1;
  sprintf(path, "%s/%s.pxa", path_dir, 232 * no + 136058976);
  if ( (unsigned __int8)LoadAttributeData(path) ^ 1 )
    bError = 1;
  sprintf(path, "%s/%s.pxm", path_dir, 232 * no + 136059008);
  if ( (unsigned __int8)LoadMapData2(path) ^ 1 )
    bError = 1;
  sprintf(path, "%s/%s.pxe", path_dir, 232 * no + 136059008);
  if ( (unsigned __int8)LoadEvent(path) ^ 1 )
    bError = 1;
  sprintf(path, "%s/%s.tsc", path_dir, 232 * no + 136059008);
  if ( (unsigned __int8)LoadTextScript_Stage(path) ^ 1 )
    bError = 1;
  strcpy(path, (const char *)(232 * no + 136059044));
  if ( (unsigned __int8)InitBack(path, gTMT[no].bkType) ^ 1 )
    bError = 1;
  memcpy(path_dir, "Npc", 4u);
  sprintf(path, "%s/Npc%s", path_dir, 232 * no + 136059076);
  if ( !ReloadBitmap_File(path, 21) )
    bError = 1;
  sprintf(path, "%s/Npc%s", path_dir, 232 * no + 136059108);
  if ( !ReloadBitmap_File(path, 22) )
    bError = 1;
  if ( bError )
  {
    fprintf(stderr, "There was an ERROR loading Stage %ld!", no);
    result = 0;
  }
  else
  {
    map_name = 0;
    if ( get_language() == 0 )
      map_name = (char *)(232 * no + 136059141);
    else
      map_name = (char *)(232 * no + 136059173);
    ReadyMapName((unsigned __int8 *)map_name);
    StartTextScript(w);
    SetFrameMyChar();
    ClearBullet();
    InitCaret();
    ClearValueView();
    ResetQuake();
    InitBossChar(gTMT[no].boss_no);
    ResetFlash();
    gStageNo = no;
    result = 1;
  }
  return result;
}

void __cdecl ChangeMusic(int no)
{
  if ( !no || no != gMusicNo )
  {
    gOldPos = GetOrganyaPosition();
    gOldNo = gMusicNo;
    StopOrganyaMusic();
    LoadOrganya(gMusicTable[no]);
    ChangeOrganyaVolume(100);
    SetOrganyaPosition(0);
    PlayOrganyaMusic();
    gMusicNo = no;
  }
}

void ReCallMusic()
{
  StopOrganyaMusic();
  LoadOrganya(gMusicTable[gOldNo]);
  SetOrganyaPosition(gOldPos);
  ChangeOrganyaVolume(100);
  PlayOrganyaMusic();
  gMusicNo = gOldNo;
}

