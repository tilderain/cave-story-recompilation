//#include "types.h"
#include "stdint.h"
#include "SDL_stdinc.h"
#include "SDL_video.h"
#include "Tags.h"
#include "Escape.h"
#include "KeyControl.h"
#include "Game.h"

int _ModeOpening();
int _ModeTitle();
int _ModeAction();
signed int Game();

_UNKNOWN PutNumber4(long,long,long,bool)::C.0;

int Random(int min, int max)
{
  return min + rand() % (max - min + 1);
}

void PutNumber4(int x, int y, int value, bool bZero)
{
  RECT rect[10];
  int tbl[4];
  RECT rcClient;
  int a;
  int sw;
  int offset;

  rcClient.left = 0;
  rcClient.top = 0;
  rcClient.right = 320;
  rcClient.bottom = 240;
  qmemcpy(rect, &PutNumber4(long,long,long,bool)::C.0, sizeof(rect));
  tbl[0] = 1000;
  tbl[1] = 100;
  tbl[2] = 10;
  tbl[3] = 1;
  if ( value > 9999 )
    value = 9999;
  offset = 0;
  sw = 0;
  while ( offset <= 3 )
  {
    a = 0;
    while ( tbl[offset] <= value )
    {
      value -= tbl[offset];
      ++a;
      ++sw;
    }
    if ( bZero && offset == 2 || sw || offset == 3 )
      PutBitmap3(&rcClient, x + 8 * offset, y, &rect[a], 26);
    ++offset;
  }
}

int _ModeOpening()
{
  signed int v0;
  signed int v2;
  int frame_y;
  int frame_x;
  Uint32 wait;

  InitNpChar();
  InitCaret();
  InitStar();
  InitFade();
  InitFlash();
  InitBossLife();
  ChangeMusic(0);
  TransferStage(72, 100, 3, 3);
  SetFrameTargetMyChar(16);
  SetFadeMask();
  grcGame.left = 0;
  g_GameFlags = 3;
  CutNoise();
  wait = 0;
  while ( wait <= 0x1F3 )
  {
    ++wait;
    GetTrg();
    if ( gKey & 0x8000 )
    {
      v0 = Call_Escape(gscreen);
      if ( !v0 )
        return 0;
      if ( v0 == 2 )
        return 1;
    }
    if ( gKey & gKeyOk )
      break;
    ActNpChar();
    ActBossChar();
    ActBack();
    ResetMyCharFlag();
    HitMyCharMap();
    HitMyCharNpChar();
    HitMyCharBoss();
    HitNpCharMap();
    HitBossMap();
    HitBossBullet();
    ActCaret();
    MoveFrame3();
    ProcFade();
    CortBox(&grcFull, 0);
    GetFramePosition(&frame_x, &frame_y);
    PutBack(frame_x, frame_y);
    PutStage_Back(frame_x, frame_y);
    PutBossChar(frame_x, frame_y);
    PutNpChar(frame_x, frame_y);
    PutMapDataVector(frame_x, frame_y);
    PutStage_Front(frame_x, frame_y);
    PutFront(frame_x, frame_y);
    PutCaret(frame_x, frame_y);
    PutFade();
    v2 = TextScriptProc();
    if ( !v2 )
      return 0;
    if ( v2 == 2 )
      return 1;
    PutMapName(0);
    PutTextScript();
    PutFramePerSecound();
    if ( !Flip_SystemTask(gscreen) )
      return 0;
    ++gCounter;
  }
  wait = SDL_GetTicks();
  while ( SDL_GetTicks() < wait + 500 )
  {
    CortBox(&grcGame, 0);
    PutFramePerSecound();
    if ( !Flip_SystemTask(gscreen) )
      return 0;
  }
  return 2;
}


int _ModeTitle()
{
  int v0;
  signed int eax29;
  Sint32 *eax39;
  Sint32 *eax40;
  Sint32 *v5;
  Sint32 *v6;
  Sint32 *v7;
  RECT rcSu[4];
  RECT rcKing[4];
  RECT rcToroko[4];
  RECT rcCurly[4];
  RECT rcMyChar[4];
  RECT char_rc;
  int v4;
  int v3;
  int v2;
  int v1;
  RECT rcPeriod;
  RECT rcVersion;
  RECT rcContinue;
  RECT rcNew;
  RECT rcPixel;
  RECT rcTitle;
  Uint8 r;
  Uint32 wait;
  int anime;
  int char_type;
  int time_counter;
  int char_y;
  int char_surf;
  int back_color;
  char v32[8];

  rcTitle.left = 0;
  rcTitle.top = 0;
  rcTitle.right = 144;
  rcTitle.bottom = 32;
  rcPixel.left = 0;
  rcPixel.top = 0;
  rcPixel.right = 160;
  rcPixel.bottom = 16;
  rcNew.left = 144;
  rcNew.top = 0;
  rcNew.right = 192;
  rcNew.bottom = 16;
  rcContinue.left = 144;
  rcContinue.top = 16;
  rcContinue.right = 192;
  rcContinue.bottom = 32;
  rcVersion.left = 152;
  rcVersion.top = 80;
  rcVersion.right = 208;
  rcVersion.bottom = 88;
  rcPeriod.left = 152;
  rcPeriod.top = 88;
  rcPeriod.right = 208;
  rcPeriod.bottom = 96;
  rcMyChar[0].left = 0;
  rcMyChar[0].top = 16;
  rcMyChar[0].right = 16;
  rcMyChar[0].bottom = 32;
  rcMyChar[1].left = 16;
  rcMyChar[1].top = 16;
  rcMyChar[1].right = 32;
  rcMyChar[1].bottom = 32;
  rcMyChar[2].left = 0;
  rcMyChar[2].top = 16;
  rcMyChar[2].right = 16;
  rcMyChar[2].bottom = 32;
  rcMyChar[3].left = 32;
  rcMyChar[3].top = 16;
  rcMyChar[3].right = 48;
  rcMyChar[3].bottom = 32;
  rcCurly[0].left = 0;
  rcCurly[0].top = 112;
  rcCurly[0].right = 16;
  rcCurly[0].bottom = 128;
  rcCurly[1].left = 16;
  rcCurly[1].top = 112;
  rcCurly[1].right = 32;
  rcCurly[1].bottom = 128;
  rcCurly[2].left = 0;
  rcCurly[2].top = 112;
  rcCurly[2].right = 16;
  rcCurly[2].bottom = 128;
  rcCurly[3].left = 32;
  rcCurly[3].top = 112;
  rcCurly[3].right = 48;
  rcCurly[3].bottom = 128;
  rcToroko[0].left = 64;
  rcToroko[0].top = 80;
  rcToroko[0].right = 80;
  rcToroko[0].bottom = 96;
  rcToroko[1].left = 80;
  rcToroko[1].top = 80;
  rcToroko[1].right = 96;
  rcToroko[1].bottom = 96;
  rcToroko[2].left = 64;
  rcToroko[2].top = 80;
  rcToroko[2].right = 80;
  rcToroko[2].bottom = 96;
  rcToroko[3].left = 96;
  rcToroko[3].top = 80;
  rcToroko[3].right = 112;
  rcToroko[3].bottom = 96;
  rcKing[0].left = 224;
  rcKing[0].top = 48;
  rcKing[0].right = 240;
  rcKing[0].bottom = 64;
  rcKing[1].left = 288;
  rcKing[1].top = 48;
  rcKing[1].right = 304;
  rcKing[1].bottom = 64;
  rcKing[2].left = 224;
  rcKing[2].top = 48;
  rcKing[2].right = 240;
  rcKing[2].bottom = 64;
  rcKing[3].left = 304;
  rcKing[3].top = 48;
  rcKing[3].right = 320;
  rcKing[3].bottom = 64;
  rcSu[0].left = 0;
  rcSu[0].top = 16;
  rcSu[0].right = 16;
  rcSu[0].bottom = 32;
  rcSu[1].left = 32;
  rcSu[1].top = 16;
  rcSu[1].right = 48;
  rcSu[1].bottom = 32;
  rcSu[2].left = 0;
  rcSu[2].top = 16;
  rcSu[2].right = 16;
  rcSu[2].bottom = 32;
  rcSu[3].left = 48;
  rcSu[3].top = 16;
  rcSu[3].right = 64;
  rcSu[3].bottom = 32;
  InitCaret();
  InitStar();
  CutNoise();
  anime = 0;
  char_type = 0;
  time_counter = 0;
  RGB((int)&r, 0x20u, 0x20u, 32);
  back_color = GetCortBoxColor((const SDL_Color *const )&r);
  _bContinue = (unsigned __int8)IsProfile() != 0;
  time_counter = LoadTimeCounter();
  if ( time_counter && time_counter <= 17999 )
    char_type = 1;
  if ( time_counter && time_counter <= 14999 )
    char_type = 2;
  if ( time_counter && time_counter <= 11999 )
    char_type = 3;
  if ( time_counter && time_counter <= 8999 )
    char_type = 4;
  switch ( char_type )
  {
    case 1:
      ChangeMusic(36);
      break;
    case 2:
      ChangeMusic(40);
      break;
    case 3:
      ChangeMusic(41);
      break;
    case 4:
      ChangeMusic(2);
      break;
    default:
      ChangeMusic(24);
      break;
  }
  grcGame.left = 0;
  g_GameFlags = 0;
  v0 = star_flag;
  BYTE1(v0) |= 1u;
  star_flag = v0;
  wait = 0;
  while ( 1 )
  {
    if ( wait <= 9 )
      ++wait;
    GetTrg();
    if ( wait > 9 )
    {
      if ( gKeyTrg & gKeyOk )
        break;
    }
    if ( gKey & 0x8000 )
    {
      eax29 = Call_Escape(gscreen);
      if ( !eax29 )
        return 0;
      if ( eax29 == 2 )
        return 1;
    }
    if ( (gKeyDown | gKeyUp) & gKeyTrg )
    {
      PlaySoundObject(1, 1);
      _bContinue = _bContinue == 0;
    }
    ActCaret();
    if ( ++anime > 39 )
      anime = 0;
    CortBox(&grcGame, back_color);
    PutBitmap3(&grcGame, 100, 216, &rcVersion, 26);
    PutBitmap3(&grcGame, 156, 216, &rcPeriod, 26);
    GetCompileVersion(&v1, &v2, &v3, &v4);
    PutNumber4(140, 216, v1, 0);
    PutNumber4(156, 216, v2, 0);
    PutNumber4(172, 216, v3, 0);
    PutNumber4(188, 216, v4, 0);
    PutBitmap3(&grcGame, 88, 40, &rcTitle, 0);
    PutBitmap3(&grcGame, 136, 128, &rcNew, 0);
    PutBitmap3(&grcGame, 136, 148, &rcContinue, 0);
    PutBitmap3(&grcGame, 80, 192, &rcPixel, 1);
    switch ( char_type )
    {
      case 0:
        eax39 = (Sint32 *)&v32[16 * (anime / 10 % 4) - 224];
        char_rc.left = *eax39;
        char_rc.top = eax39[1];
        char_rc.right = eax39[2];
        char_rc.bottom = eax39[3];
        char_surf = 16;
        break;
      case 1:
        eax40 = (Sint32 *)&v32[16 * (anime / 10 % 4) - 288];
        char_rc.left = *eax40;
        char_rc.top = eax40[1];
        char_rc.right = eax40[2];
        char_rc.bottom = eax40[3];
        char_surf = 23;
        break;
      case 2:
        v5 = (Sint32 *)&v32[16 * (anime / 10 % 4) - 352];
        char_rc.left = *v5;
        char_rc.top = v5[1];
        char_rc.right = v5[2];
        char_rc.bottom = v5[3];
        char_surf = 23;
        break;
      case 3:
        v6 = (Sint32 *)&v32[16 * (anime / 10 % 4) - 416];
        char_rc.left = *v6;
        char_rc.top = v6[1];
        char_rc.right = v6[2];
        char_rc.bottom = v6[3];
        char_surf = 23;
        break;
      case 4:
        v7 = (Sint32 *)&v32[16 * (anime / 10 % 4) - 480];
        char_rc.left = *v7;
        char_rc.top = v7[1];
        char_rc.right = v7[2];
        char_rc.bottom = v7[3];
        char_surf = 23;
        break;
    }
    if ( _bContinue == 1 )
      char_y = 147;
    else
      char_y = 127;
    PutBitmap3(&grcGame, 116, char_y, &char_rc, char_surf);
    PutCaret(0, 0);
    if ( time_counter )
      PutTimeCounter(16, 8);
    PutFramePerSecound();
    if ( !Flip_SystemTask(gscreen) )
      return 0;
  }
  PlaySoundObject(18, 1);
  ChangeMusic(0);
  wait = SDL_GetTicks();
  while ( SDL_GetTicks() < wait + 1000 )
  {
    CortBox(&grcGame, 0);
    PutFramePerSecound();
    if ( !Flip_SystemTask(gscreen) )
      return 0;
  }
  return 3;
}



int _ModeAction()
{
  int result;
  signed int v1;
  signed int v2;
  signed int v3;
  signed int v4;
  int frame_y;
  int frame_x;
  Uint8 r;
  unsigned int swPlay;
  unsigned int _color;

  frame_x = 0;
  frame_y = 0;
  RGB((int)&r, 0, 0, 32);
  _color = GetCortBoxColor((const SDL_Color *const )&r);
  swPlay = 1;
  gCounter = 0;
  grcGame.left = 0;
  g_GameFlags = 3;
  InitMyChar();
  InitNpChar();
  InitBullet();
  InitCaret();
  InitStar();
  InitFade();
  InitFlash();
  ClearArmsData();
  ClearItemData();
  ClearPermitStage();
  StartMapping();
  InitFlags();
  InitBossLife();
  if ( _bContinue )
  {
    if ( (unsigned __int8)LoadProfile(0) ^ 1 && (unsigned __int8)InitializeGame() ^ 1 )
    {
      result = 0;
    }
    else
    {
      while ( 1 )
      {
LABEL_7:
        GetTrg();
        if ( gKeyTrg & 0x8000 )
        {
          v1 = Call_Escape(gscreen);
          if ( !v1 )
            return 0;
          if ( v1 == 2 )
            return 1;
        }
        if ( swPlay & 1 && g_GameFlags & 1 )
        {
          if ( g_GameFlags & 2 )
            ActMyChar(1);
          else
            ActMyChar(0);
          ActStar();
          ActNpChar();
          ActBossChar();
          ActValueView();
          ActBack();
          ResetMyCharFlag();
          HitMyCharMap();
          HitMyCharNpChar();
          HitMyCharBoss();
          HitNpCharMap();
          HitBossMap();
          HitBulletMap();
          HitNpCharBullet();
          HitBossBullet();
          if ( g_GameFlags & 2 )
            ShootBullet();
          ActBullet();
          ActCaret();
          MoveFrame3();
          ActFlash(frame_x, frame_y);
          if ( g_GameFlags & 2 )
            AnimationMyChar(1);
          else
            AnimationMyChar(0);
        }
        if ( g_GameFlags & 8 )
        {
          ActionCredit();
          ActionIllust();
          ActionStripper();
        }
        ProcFade();
        CortBox(&grcFull, _color);
        GetFramePosition(&frame_x, &frame_y);
        PutBack(frame_x, frame_y);
        PutStage_Back(frame_x, frame_y);
        PutBossChar(frame_x, frame_y);
        PutNpChar(frame_x, frame_y);
        PutBullet(frame_x, frame_y);
        PutMyChar(frame_x, frame_y);
        PutStar(frame_x, frame_y);
        PutMapDataVector(frame_x, frame_y);
        PutStage_Front(frame_x, frame_y);
        PutFront(frame_x, frame_y);
        PutFlash();
        PutCaret(frame_x, frame_y);
        PutValueView(frame_x, frame_y);
        PutBossLife();
        PutFade();
        if ( !(g_GameFlags & 4) )
        {
          if ( gKeyTrg & gKeyItem )
          {
            BackupSurface(10, &grcGame);
            v2 = CampLoop();
            if ( !v2 )
              return 0;
            if ( v2 == 2 )
              return 1;
            gMC.cond &= 0xFEu;
          }
          else if ( star_flag & 2 && gKeyTrg & gKeyMap )
          {
            BackupSurface(10, &grcGame);
            v3 = MiniMapLoop();
            if ( !v3 )
              return 0;
            if ( v3 == 2 )
              return 1;
          }
        }
        if ( g_GameFlags & 2 )
        {
          if ( gKeyTrg & gKeyArms )
          {
            RotationArms();
          }
          else if ( gKeyTrg & gKeyArmsRev )
          {
            RotationArmsRev();
          }
        }
        if ( swPlay & 1 )
        {
          v4 = TextScriptProc();
          if ( !v4 )
            return 0;
          if ( v4 == 2 )
            return 1;
        }
        PutMapName(0);
        PutTimeCounter(16, 8);
        if ( g_GameFlags & 2 )
        {
          PutMyLife(1);
          PutArmsEnergy(1);
          PutMyAir(120, 104);
          PutActiveArmsList();
        }
        if ( g_GameFlags & 8 )
        {
          PutIllust();
          PutStripper();
        }
        PutTextScript();
        PutFramePerSecound();
        if ( !Flip_SystemTask(gscreen) )
          break;
        ++gCounter;
      }
      result = 0;
    }
  }
  else
  {
    if ( !((unsigned __int8)InitializeGame() ^ 1) )
      goto LABEL_7;
    result = 0;
  }
  return result;
}

signed int Game()
{
  char path[260];
  int mode;

  if ( (unsigned __int8)LoadGenericData() ^ 1 )
    return 0;
  PlaySoundObject(7, -1);
  sprintf(path, "%s/npc.tbl", gDataPath);
  if ( (unsigned __int8)LoadNpcTable(path) ^ 1 )
    return 0;
  InitTextScript2();
  InitSkipFlags();
  InitMapData2();
  InitCreditScript();
  mode = 1;
  while ( mode )
  {
    if ( mode == 1 )
      mode = _ModeOpening();
    if ( mode == 2 )
      mode = _ModeTitle();
    if ( mode == 3 )
      mode = _ModeAction();
  }
  PlaySoundObject(7, 0);
  EndMapData();
  EndTextScript();
  ReleaseNpcTable();
  ReleaseCreditScript();
  return 1;
}

