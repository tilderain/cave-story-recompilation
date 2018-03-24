#include "types.h"
#include "stdint.h"
#include "SDL_stdinc.h"
#include "SDL_video.h"
#include "windows_wrapper.h"
#include "Tags.h"
#include "Escape.h"
#include "KeyControl.h"
void ClearPermitStage()
{
  memset(gPermitStage, 0, 0x40u);
}

signed int __cdecl AddPermitStage(int index, int event)
{
  int i;

  for ( i = 0; i <= 7 && gPermitStage[i].index != index && gPermitStage[i].index; ++i )
    ;
  if ( i == 8 )
    return 0;
  gPermitStage[i].index = index;
  gPermitStage[i].event = event;
  return 1;
}

signed int __cdecl SubPermitStage(int index)
{
  int v2;
  int v3;
  int i;
  int ia;

  for ( i = 0; i <= 7 && gPermitStage[i].index != index; ++i )
    ;
  if ( i == 32 )
    return 0;
  for ( ia = i + 1; ia <= 7; ++ia )
  {
    v2 = ia - 1;
    v3 = gPermitStage[ia].event;
    gPermitStage[v2].index = gPermitStage[ia].index;
    gPermitStage[v2].event = v3;
  }
  gPermitStage[ia - 1].index = 0;
  gPermitStage[ia - 1].event = 0;
  return 1;
}

void MoveStageSelectCursor()
{
  int stage_num;

  for ( stage_num = 0; gPermitStage[stage_num].index != 0; ++stage_num )
    ;
  if ( stage_num )
  {
    if ( gKeyTrg & gKeyLeft )
      --gSelectedStage;
    if ( gKeyTrg & gKeyRight )
      ++gSelectedStage;
    if ( gSelectedStage < 0 )
      gSelectedStage = stage_num - 1;
    if ( stage_num - 1 < gSelectedStage )
      gSelectedStage = 0;
    if ( (gKeyRight | gKeyLeft) & gKeyTrg )
      StartTextScript(gPermitStage[gSelectedStage].index + 1000);
    if ( (gKeyRight | gKeyLeft) & gKeyTrg )
      PlaySoundObject(1, 1);
  }
}

void PutStageSelectObject()
{
  RECT rcCur[2];
  RECT rcTitle1;
  RECT rcView;
  RECT rcStage;
  int i;
  int stage_num;
  int stage_x;

  rcView.left = 0;
  rcView.top = 0;
  rcView.right = 320;
  rcView.bottom = 240;
  rcCur[0].left = 80;
  rcCur[0].top = 88;
  rcCur[0].right = 112;
  rcCur[0].bottom = 104;
  rcCur[1].left = 80;
  rcCur[1].top = 104;
  rcCur[1].right = 112;
  rcCur[1].bottom = 120;
  rcTitle1.left = 80;
  rcTitle1.top = 64;
  rcTitle1.right = 144;
  rcTitle1.bottom = 72;
  if ( gStageSelectTitleY > 46 )
    --gStageSelectTitleY;
  PutBitmap3(&rcView, 128, gStageSelectTitleY, &rcTitle1, 26);
  for ( stage_num = 0; gPermitStage[stage_num].index != 0; ++stage_num )
    ;
  ++PutStageSelectObject(void)::flash;
  if ( stage_num )
  {
    stage_x = (-40 * stage_num + 320) / 2;
    PutBitmap3(&rcView, stage_x + 40 * gSelectedStage, 64, &rcCur[(PutStageSelectObject(void)::flash >> 1) & 1], 26);
    for ( i = 0; i <= 7 && gPermitStage[i].index; ++i )
    {
      rcStage.left = 32 * (gPermitStage[i].index % 8);
      rcStage.right = rcStage.left + 32;
      rcStage.top = 16 * (gPermitStage[i].index / 8);
      rcStage.bottom = rcStage.top + 16;
      PutBitmap3(&rcView, stage_x + 40 * i, 64, &rcStage, 14);
    }
  }
}

signed int __cdecl StageSelectLoop(int *p_event)
{
  signed int v1;
  signed int v3;
  char old_script_path[260];
  RECT rcView;

  rcView.left = 0;
  rcView.top = 0;
  rcView.right = 320;
  rcView.bottom = 240;
  gSelectedStage = 0;
  BackupSurface(10, &grcFull);
  GetTextScriptPath(old_script_path);
  LoadTextScript2("StageSelect.tsc");
  gStageSelectTitleY = 54;
  StartTextScript(gPermitStage[gSelectedStage].index + 1000);
  do
  {
    GetTrg();
    if ( gKey & 0x8000 )
    {
      v1 = Call_Escape(gscreen);
      if ( !v1 )
        return 0;
      if ( v1 == 2 )
        return 2;
    }
    MoveStageSelectCursor();
    v3 = TextScriptProc();
    if ( !v3 )
      return 0;
    if ( v3 == 2 )
      return 2;
    PutBitmap3(&rcView, 0, 0, &rcView, 10);
    PutStageSelectObject();
    PutTextScript();
    if ( gKeyTrg & gKeyOk )
    {
      StopTextScript();
      LoadTextScript_Stage(old_script_path);
      *p_event = gPermitStage[gSelectedStage].event;
      return 1;
    }
    if ( gKeyTrg & gKeyCancel )
    {
      StopTextScript();
      LoadTextScript_Stage(old_script_path);
      *p_event = 0;
      return 1;
    }
    PutFramePerSecound();
  }
  while ( Flip_SystemTask(gscreen) );
  return 0;
}

