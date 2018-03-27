#include "stddef.h"
//#include "types.h"
#include "stdint.h"
#include "SDL_stdinc.h"
#include "SMixer.h"
#include "../windows_wrapper.h"
#include "org.h"
#include "Organya.h"

void OrgData::OrgData(OrgData *const this);
void OrgData::OrgData(OrgData *const this);
void OrgData::InitOrgData(OrgData *const this);
signed int OrgData::SetMusicInfo(OrgData *const this, MUSICINFO_0 *mi, Uint32 flag);
signed int OrgData::NoteAlloc(OrgData *const this, unsigned __int16 alloc);
void OrgData::ReleaseNote(OrgData *const this);
signed int OrgData::InitMusicData(OrgData *const this, char *path);
void OrgData::GetMusicInfo(OrgData *const this, MUSICINFO_0 *mi);
void __thiscall OrgData::PlayData(OrgData *const this);
void OrgData::SetPlayPointer(OrgData *const this, Sint32 x);

int g_mute[16];
Uint8 _key_on[16];
Uint8 _key_twin[16];
char wave_data[25600];
ORG *org_data;
Sint32 _PlayPos;
NOTELIST *np[16];
int _now_leng[8];
int _TrackVol[16];
bool _bFadeout;

OCTAVE_WAVE oct_wave[8] =
{
  { 256, 1, 4 },
  { 256, 2, 8 },
  { 128, 4, 12 },
  { 128, 8, 16 },
  { 64, 16, 20 },
  { 32, 32, 24 },
  { 16, 64, 28 },
  { 8, 128, 32 }
};
__int16 freq_tbl[12] = { 262, 277, 294, 311, 330, 349, 370, 392, 415, 440, 466, 494 };
__int16 _pan_tbl[13] = { 0, 43, 86, 129, 172, 215, 256, 297, 340, 383, 426, 469, 512 };
Uint8 _old_key[16] =
{
  255u,
  255u,
  255u,
  255u,
  255u,
  255u,
  255u,
  255u,
  0u,
  0u,
  0u,
  0u,
  0u,
  0u,
  0u,
  0u
};
char pass[7] = "Org-01";
char pass2[7] = "Org-02";
int _Volume = 100;

void ChangeOrganFrequency(Uint8 key, Sint8 track, Uint32 a)
{
  __int64 v3;
  int j;
  int i;

  for ( j = 0; j <= 7; ++j )
  {
    for ( i = 0; i <= 1; ++i )
    {
      v3 = freq_tbl[key] * (signed int)oct_wave[j].wave_size * oct_wave[j].oct_par;
      SMixer_SetFrequency(orgs[0][0][2 * (8 * track + j) + i], a + ((signed int)((HIDWORD(v3) >> 29) + v3) >> 3) - 1000);
    }
  }
}


void ChangeOrganPan(Uint8 key, Uint8 pan, Sint8 track)
{
  if ( _old_key[track] != -1 )
    SMixer_SetPan(orgs[0][0][2 * (8 * track + _old_key[track] / 0xCu) + _key_twin[track]], _pan_tbl[pan]);
}

void ChangeOrganVolume(int no, int volume, Sint8 track)
{
  if ( _old_key[track] != -1 )
    SMixer_SetVolume(orgs[0][0][2 * (8 * track + _old_key[track] / 0xCu) + _key_twin[track]], volume);
}

void PlayOrganObject(Uint8 key, int mode, Sint8 track, Uint32 freq)
{
  if ( orgs[0][0][2 * (8 * track + key / 0xCu) + _key_twin[track]] )
  {
    if ( mode )
    {
      if ( mode > 0 )
      {
        if ( mode != 1 && mode == 2 && _old_key[track] != -1 )
        {
          SMixer_PlayChunk(orgs[0][0][2 * (8 * track + _old_key[track] / 0xCu) + _key_twin[track]], 0);
          _old_key[track] = -1;
        }
      }
      else if ( mode == -1 )
      {
        if ( _old_key[track] == -1 )
        {
          ChangeOrganFrequency(key % 0xCu, track, freq);
          SMixer_PlayChunk(orgs[0][0][2 * (8 * track + key / 0xCu) + _key_twin[track]], -1);
          _old_key[track] = key;
          _key_on[track] = 1;
        }
        else if ( _key_on[track] != 1 || _old_key[track] != key )
        {
          SMixer_PlayChunk(orgs[0][0][2 * (8 * track + _old_key[track] / 0xCu) + _key_twin[track]], 0);
          if ( ++_key_twin[track] > 1u )
            _key_twin[track] = 0;
          ChangeOrganFrequency(key % 0xCu, track, freq);
          SMixer_PlayChunk(orgs[0][0][2 * (8 * track + key / 0xCu) + _key_twin[track]], -1);
          _old_key[track] = key;
        }
        else
        {
          SMixer_PlayChunk(orgs[0][0][2 * (8 * track + _old_key[track] / 0xCu) + _key_twin[track]], 0);
          if ( ++_key_twin[track] > 1u )
            _key_twin[track] = 0;
          SMixer_PlayChunk(orgs[0][0][2 * (8 * track + key / 0xCu) + _key_twin[track]], -1);
        }
      }
    }
    else if ( _old_key[track] != -1 )
    {
      SMixer_StopChunk(orgs[0][0][2 * (8 * track + _old_key[track] / 0xCu) + _key_twin[track]]);
    }
  }
}

void ReleaseOrganyaObject(Sint8 track)
{
  int i;

  for ( i = 0; i <= 7; ++i )
  {
    SMixer_StopChunk(orgs[0][8 * track + i][0]);
    SMixer_StopChunk(orgs[0][0][2 * (8 * track + i) + 1]);
    if ( orgs[0][8 * track + i][0] )
    {
      if ( orgs[0][8 * track + i][0]->buf )
        free(orgs[0][8 * track + i][0]->buf);
      free(orgs[0][8 * track + i][0]);
      orgs[0][8 * track + i][0] = 0;
    }
    if ( orgs[0][0][2 * (8 * track + i) + 1] )
    {
      if ( orgs[0][0][2 * (8 * track + i) + 1]->buf )
        free(orgs[0][0][2 * (8 * track + i) + 1]->buf);
      free(orgs[0][0][2 * (8 * track + i) + 1]);
      orgs[0][0][2 * (8 * track + i) + 1] = 0;
    }
  }
}

signed int InitWaveData100()
{
  char *v0;
  int size;

  size = 0;
  v0 = get_resource("Wave", &size);
  memcpy(wave_data, v0, 0x6400u);
  return 1;
}

signed int MakeOrganyaWave(char track, char wave_no)
{
  if ( wave_no > 99 )
    return 0;
  SDL_LockAudio();
  ReleaseOrganyaObject(track);
  SDL_UnlockAudio();
  return 1;
}



void ChangeDramFrequency(unsigned __int8 key, char track)
{
  SMixer_SetFrequency(chunks[track + 150], 800 * key + 100);
}

void ChangeDramPan(unsigned __int8 pan, char track)
{
  SMixer_SetPan(chunks[track + 150], _pan_tbl[pan]);
}

void ChangeDramVolume(int volume, char track)
{
  SMixer_SetVolume(chunks[track + 150], volume);
}

void PlayDramObject(unsigned __int8 key, int mode, char track)
{
  if ( chunks[track + 150] )
  {
    if ( mode )
    {
      if ( mode == 1 )
      {
        SMixer_StopChunk(chunks[track + 150]);
        ChangeDramFrequency(key, track);
        SMixer_PlayChunk(chunks[track + 150], 0);
      }
    }
    else
    {
      SMixer_StopChunk(chunks[track + 150]);
    }
  }
}

void OrgData::OrgData(OrgData *const this)
{
  int i;

  for ( i = 0; i <= 15; ++i )
  {
    this->info.tdata[i].note_list = 0;
    this->info.tdata[i].note_p = 0;
  }
}

void OrgData::OrgData(OrgData *const this)
{
  int i;

  for ( i = 0; i <= 15; ++i )
  {
    this->info.tdata[i].note_list = 0;
    this->info.tdata[i].note_p = 0;
  }
}

void OrgData::InitOrgData(OrgData *const this)
{
  int i;

  this->track = 0;
  this->info.alloc_note = 4096;
  this->info.dot = 4;
  this->info.line = 4;
  this->info.wait = 128;
  this->info.repeat_x = 0;
  this->info.end_x = 255 * this->info.dot * this->info.line;
  for ( i = 0; i <= 15; ++i )
  {
    this->info.tdata[i].freq = 1000;
    this->info.tdata[i].wave_no = 0;
    this->info.tdata[i].pipi = 0;
  }
  OrgData::NoteAlloc(this, this->info.alloc_note);
  OrgData::SetMusicInfo(this, &this->info, 0xFFFFFFFF);
  this->def_pan = 6;
  this->def_volume = -56;
}

signed int OrgData::SetMusicInfo(OrgData *const this, MUSICINFO_0 *mi, Uint32 flag)
{
  char str[32];
  int i;

  if ( flag & 2 )
  {
    this->info.dot = mi->dot;
    this->info.line = mi->line;
  }
  if ( flag & 1 )
  {
    this->info.wait = mi->wait;
    sprintf(str, "%usd", mi->wait);
  }
  if ( flag & 8 )
  {
    this->info.repeat_x = mi->repeat_x;
    this->info.end_x = mi->end_x;
  }
  if ( flag & 0x10 )
  {
    for ( i = 0; i <= 7; ++i )
    {
      this->info.tdata[i].freq = mi->tdata[i].freq;
      this->info.tdata[i].pipi = this->info.tdata[i].pipi;
    }
  }
  if ( flag & 0x20 )
  {
    for ( i = 0; i <= 15; ++i )
      this->info.tdata[i].wave_no = mi->tdata[i].wave_no;
  }
  if ( flag & 0x40 )
  {
    for ( i = 0; i <= 15; ++i )
      this->info.tdata[i].pipi = mi->tdata[i].pipi;
  }
  return 1;
}

signed int OrgData::NoteAlloc(OrgData *const this, unsigned __int16 alloc)
{
  int v3;
  int i;
  int ia;
  int j;
  int ja;

  for ( j = 0; ; ++j )
  {
    if ( j > 15 )
    {
      for ( ja = 0; ja <= 7; ++ja )
      {
        v3 = this->info.tdata[ja].pipi;
        MakeOrganyaWave(ja, this->info.tdata[ja].wave_no);
      }
      this->track = 0;
      return 1;
    }
    this->info.tdata[j].wave_no = 0;
    this->info.tdata[j].note_list = 0;
    this->info.tdata[j].note_p = (NOTELIST *)malloc(16 * alloc);
    if ( !this->info.tdata[j].note_p )
      break;
    for ( ia = 0; alloc > ia; ++ia )
    {
      this->info.tdata[j].note_p[ia].from = 0;
      this->info.tdata[j].note_p[ia].to = 0;
      this->info.tdata[j].note_p[ia].length = 0;
      this->info.tdata[j].note_p[ia].pan = -1;
      this->info.tdata[j].note_p[ia].volume = -1;
      this->info.tdata[j].note_p[ia].y = -1;
    }
  }
  for ( i = 0; i <= 15; ++i )
  {
    if ( this->info.tdata[i].note_p )
    {
      free(this->info.tdata[i].note_p);
      this->info.tdata[j].note_p = 0;
    }
  }
  return 0;
}

void OrgData::ReleaseNote(OrgData *const this)
{
  int i;

  for ( i = 0; i <= 15; ++i )
  {
    if ( this->info.tdata[i].note_p )
    {
      free(this->info.tdata[i].note_p);
      this->info.tdata[i].note_p = 0;
    }
  }
}

signed int OrgData::InitMusicData(OrgData *const this, char *path)
{
  int v3;
  $11C3EE8C60DD49A6CA3BAE14ACF35155 org_data;
  int size;
  char pass_check[6];
  NOTELIST *np;
  int i;
  int j;
  char ver;
  Uint8 *p;
  char v12[8];

  ver = 0;
  size = 0;
  p = (Uint8 *)get_resource(path, &size);
  memcpy(pass_check, p, 6u);
  p += 6;
  if ( !memcmp(pass_check, pass, 6u) )
    ver = 1;
  if ( !memcmp(pass_check, pass2, 6u) )
    ver = 2;
  if ( !ver )
    return 0;
  org_data.wait = *(_WORD *)p;
  p += 2;
  org_data.line = *p++;
  org_data.dot = *p++;
  org_data.repeat_x = (p[1] << 8) | (p[2] << 16) | (p[3] << 24) | *p;
  p += 4;
  org_data.end_x = (p[1] << 8) | (p[2] << 16) | (p[3] << 24) | *p;
  p += 4;
  for ( i = 0; i <= 15; ++i )
  {
    *(_WORD *)&v12[6 * i - 128] = *(_WORD *)p;
    p += 2;
    v12[6 * i - 126] = *p++;
    v12[6 * i - 125] = *p++;
    *(_WORD *)&v12[6 * i - 124] = *(_WORD *)p;
    p += 2;
  }
  this->info.wait = org_data.wait;
  this->info.line = org_data.line;
  this->info.dot = org_data.dot;
  this->info.repeat_x = org_data.repeat_x;
  this->info.end_x = org_data.end_x;
  for ( i = 0; i <= 15; ++i )
  {
    this->info.tdata[i].freq = *(_WORD *)&v12[6 * i - 128];
    if ( ver == 1 )
      this->info.tdata[i].pipi = 0;
    else
      this->info.tdata[i].pipi = v12[6 * i - 125];
    this->info.tdata[i].wave_no = v12[6 * i - 126];
  }
  for ( j = 0; j <= 15; ++j )
  {
    if ( *(_WORD *)&v12[6 * j - 124] )
    {
      np = this->info.tdata[j].note_p;
      this->info.tdata[j].note_list = this->info.tdata[j].note_p;
      np->from = 0;
      np->to = np + 1;
      ++np;
      for ( i = 1; *(unsigned __int16 *)&v12[6 * j - 124] > i; ++i )
      {
        np->from = np - 1;
        np->to = np + 1;
        ++np;
      }
      --np;
      np->to = 0;
      np = this->info.tdata[j].note_p;
      for ( i = 0; *(unsigned __int16 *)&v12[6 * j - 124] > i; ++i )
      {
        np->x = *p | (p[1] << 8) | (p[2] << 16) | (p[3] << 24);
        p += 4;
        ++np;
      }
      np = this->info.tdata[j].note_p;
      for ( i = 0; *(unsigned __int16 *)&v12[6 * j - 124] > i; ++i )
      {
        np->y = *p++;
        ++np;
      }
      np = this->info.tdata[j].note_p;
      for ( i = 0; *(unsigned __int16 *)&v12[6 * j - 124] > i; ++i )
      {
        np->length = *p++;
        ++np;
      }
      np = this->info.tdata[j].note_p;
      for ( i = 0; *(unsigned __int16 *)&v12[6 * j - 124] > i; ++i )
      {
        np->volume = *p++;
        ++np;
      }
      np = this->info.tdata[j].note_p;
      for ( i = 0; *(unsigned __int16 *)&v12[6 * j - 124] > i; ++i )
      {
        np->pan = *p++;
        ++np;
      }
    }
    else
    {
      this->info.tdata[j].note_list = 0;
    }
  }
  for ( j = 0; j <= 7; ++j )
  {
    v3 = this->info.tdata[j].pipi;
    MakeOrganyaWave(j, this->info.tdata[j].wave_no);
  }
  for ( j = 8; j <= 15; ++j )
    i = this->info.tdata[j].wave_no;
  OrgData::SetPlayPointer(this, 0);
  return 1;
}


void OrgData::GetMusicInfo(OrgData *const this, MUSICINFO_0 *mi)
{
  int i;

  mi->dot = this->info.dot;
  mi->line = this->info.line;
  mi->alloc_note = this->info.alloc_note;
  mi->wait = this->info.wait;
  mi->repeat_x = this->info.repeat_x;
  mi->end_x = this->info.end_x;
  for ( i = 0; i <= 15; ++i )
  {
    mi->tdata[i].freq = this->info.tdata[i].freq;
    mi->tdata[i].wave_no = this->info.tdata[i].wave_no;
    mi->tdata[i].pipi = this->info.tdata[i].pipi;
  }
}

void __thiscall OrgData::PlayData(OrgData *const this)
{
  int i;
  int ia;
  OrgData *thisa;

  if ( _bFadeout && _Volume )
    _Volume -= 2;
  if ( _Volume < 0 )
    _Volume = 0;
  for ( i = 0; i <= 7; ++i )
  {
    if ( np[i] && np[i]->x == _PlayPos )
    {
      if ( !g_mute[i] && np[i]->y != -1 )
      {
        PlayOrganObject(np[i]->y, -1, i, thisa->info.tdata[i].freq);
        _now_leng[i] = np[i]->length;
      }
      if ( np[i]->pan != -1 )
        ChangeOrganPan(np[i]->y, np[i]->pan, i);
      if ( np[i]->volume != -1 )
        _TrackVol[i] = np[i]->volume;
      np[i] = np[i]->to;
    }
    if ( !_now_leng[i] )
      PlayOrganObject(0, 2, i, thisa->info.tdata[i].freq);
    if ( _now_leng[i] > 0 )
      --_now_leng[i];
    if ( np[i] )
      ChangeOrganVolume(np[i]->y, _Volume * _TrackVol[i] / 127, i);
  }
  for ( ia = 8; ia <= 15; ++ia )
  {
    if ( np[ia] && np[ia]->x == _PlayPos )
    {
      if ( np[ia]->y != -1 && !g_mute[ia] )
        PlayDramObject(np[ia]->y, 1, ia - 8);
      if ( np[ia]->pan != -1 )
        ChangeDramPan(np[ia]->pan, ia - 8);
      if ( np[ia]->volume != -1 )
        _TrackVol[ia] = np[ia]->volume;
      np[ia] = np[ia]->to;
    }
    if ( np[ia] )
      ChangeDramVolume(_Volume * _TrackVol[ia] / 127, ia - 8);
  }
  if ( thisa->info.end_x <= ++_PlayPos )
  {
    _PlayPos = thisa->info.repeat_x;
    OrgData::SetPlayPointer(thisa, _PlayPos);
  }
}

void OrgData::SetPlayPointer(OrgData *const this, Sint32 x)
{
  char v2;
  int i;

  for ( i = 0; i <= 15; ++i )
  {
    for ( np[i] = this->info.tdata[i].note_list; ; np[i] = np[i]->to )
    {
      v2 = np[i] && np[i]->x < x ? 1 : 0;
      if ( !v2 )
        break;
    }
  }
  _PlayPos = x;
}

signed int StartOrganya()
{
  initORG();
  return 1;
}

signed int LoadOrganya(char *path)
{
  org_data = loadORG(path);
  return 1;
}

void SetOrganyaPosition(Sint32 x)
{
  setORGPosition(org_data, x);
  setPlayerVolume(0x64u);
  setPlayerFadeout(0);
}

Uint32 GetOrganyaPosition()
{
  return getORGPosition(org_data);
}

void PlayOrganyaMusic()
{
  playORG(org_data);
}

signed int ChangeOrganyaVolume(int vol)
{
  setPlayerVolume(vol);
  return 1;
}

void StopOrganyaMusic()
{
  stopORG();
}

void SetOrganyaFadeout()
{
  setPlayerFadeout(1u);
}

void EndOrganya()
{
  quitORG();
}


void ChangeMusic(int no)
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
