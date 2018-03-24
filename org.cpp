#include "types.h"
#include "stddef.h"
#include "types.h"
#include "stdio.h"
#include "libio.h"
#include "stdint.h"
#include "SDL_stdinc.h"
#include "org.h"
#include "SDL_rwops.h"
#include "SMixer.h"
$C1127D3748787668AAF0293B2D646CFD *__cdecl loadORG(const char *path)
{
  int v1;
  Sint16 v2;
  $557AD80E8FB350125C3B3CCF0C10D895 *v3;
  Uint32 *v4;
  Uint32 v5;
  int size;
  int i;
  int j;
  $C1127D3748787668AAF0293B2D646CFD *org;
  SDL_RWops_0 *orgfp;
  void *orgmem;

  orgfp = (SDL_RWops_0 *)SDL_AllocRW();
  orgmem = get_resource(path, &size);
  orgfp = SDL_RWFromConstMem(orgmem, size);
  org = ($C1127D3748787668AAF0293B2D646CFD *)malloc(0x25Cu);
  orgfp->read(orgfp, org, 1, 6);
  orgfp->read(orgfp, &org->tempo, 2, 1);
  orgfp->read(orgfp, &org->spb, 1, 1);
  orgfp->read(orgfp, &org->bps, 1, 1);
  orgfp->read(orgfp, &org->loopStart, 4, 1);
  orgfp->read(orgfp, &org->loopEnd, 4, 1);
  org->samples = 0;
  org->pos = 0;
  for ( i = 0; i <= 15; ++i )
  {
    orgfp->read(orgfp, &org->track[i], 2, 1);
    orgfp->read(orgfp, &org->track[i].wave, 1, 1);
    orgfp->read(orgfp, &org->track[i].pi, 1, 1);
    orgfp->read(orgfp, &org->track[i].num_notes, 2, 1);
    org->track[i].note = 0;
    org->track[i].pos = 0;
    org->track[i].playing = 0;
    org->track[i].samples = 0;
  }
  for ( i = 0; i <= 15; ++i )
  {
    if ( org->track[i].num_notes )
    {
      v1 = i;
      org->track[v1].note = ($557AD80E8FB350125C3B3CCF0C10D895 *)calloc(org->track[i].num_notes, 8u);
      for ( j = 0; org->track[i].num_notes > j; ++j )
        orgfp->read(orgfp, &org->track[i].note[j], 4, 1);
      for ( j = 0; org->track[i].num_notes > j; ++j )
        orgfp->read(orgfp, &org->track[i].note[j].note, 1, 1);
      for ( j = 0; org->track[i].num_notes > j; ++j )
        orgfp->read(orgfp, &org->track[i].note[j].length, 1, 1);
      for ( j = 0; org->track[i].num_notes > j; ++j )
        orgfp->read(orgfp, &org->track[i].note[j].volume, 1, 1);
      for ( j = 0; org->track[i].num_notes > j; ++j )
        orgfp->read(orgfp, &org->track[i].note[j].pan, 1, 1);
      if ( !org->track[i].note->start )
      {
        if ( org->track[i].note->note != -1 )
        {
          if ( org->track[i].pi )
            v2 = 1;
          else
            v2 = org->track[i].note->length;
          org->track[i].playing = v2;
        }
        org->track[i].pos = 1;
        v3 = org->track[i].note;
        v4 = &org->loopEnd + 9 * i;
        v5 = *(_DWORD *)&v3->note;
        v4[3] = v3->start;
        v4[4] = v5;
      }
    }
  }
  SDL_FreeRW(orgfp);
  return org;
}



void __cdecl freeORG($C1127D3748787668AAF0293B2D646CFD *org)
{
  int i;

  if ( org )
  {
    for ( i = 0; i <= 15; ++i )
    {
      if ( org->track[i].note )
        free(org->track[i].note);
    }
    free(org);
  }
}

void __cdecl playORG($C1127D3748787668AAF0293B2D646CFD *org)
{
  SDL_LockAudio();
  Player.org = org;
  Player.volume = 100;
  Player.fadeout = 0;
  SDL_UnlockAudio();
}



void __cdecl setPlayerFadeout(Uint8 fadeout)
{
  Player.fadeout = fadeout;
}

void __cdecl setPlayerVolume(Uint16 volume)
{
  Player.volume = volume;
}

Uint32 __cdecl getORGPosition($C1127D3748787668AAF0293B2D646CFD *org)
{
  Uint32 result;

  if ( org )
    result = org->pos;
  else
    result = 0;
  return result;
}

void __cdecl setORGPosition($C1127D3748787668AAF0293B2D646CFD *org, Uint32 position)
{
  char v2;
  Sint16 v3;
  $557AD80E8FB350125C3B3CCF0C10D895 *v4;
  Uint32 *v5;
  Uint32 v6;
  int i;

  org->pos = position;
  for ( i = 0; i <= 15; ++i )
  {
    for ( org->track[i].pos = 0; ; ++org->track[i].pos )
    {
      v2 = org->track[i].pos >= org->track[i].num_notes || org->track[i].note[org->track[i].pos].start >= org->pos ? 0 : 1;
      if ( !v2 )
        break;
    }
    org->track[i].playing = 0;
    org->track[i].samples = 0;
    if ( org->track[i].pos < org->track[i].num_notes && org->track[i].note[org->track[i].pos].start == org->pos )
    {
      if ( org->track[i].note[org->track[i].pos].note != -1 )
      {
        if ( org->track[i].pi )
          v3 = 1;
        else
          v3 = org->track[i].note[org->track[i].pos].length;
        org->track[i].playing = v3;
      }
      v4 = &org->track[i].note[org->track[i].pos];
      v5 = &org->loopEnd + 9 * i;
      v6 = *(_DWORD *)&v4->note;
      v5[3] = v4->start;
      v5[4] = v6;
      ++org->track[i].pos;
    }
  }
}

void stopORG()
{
  SDL_LockAudio();
  Player.org = 0;
  SDL_UnlockAudio();
}



int __cdecl _interpolate(Sint16 v1, Sint16 v2, Uint16 f)
{
  __int64 v4;

  if ( !f )
    return (unsigned __int16)v1;
  v4 = (v2 - v1) * f;
  return ((signed int)((HIDWORD(v4) >> 20) + v4) >> 12) + (unsigned __int16)v1;
}

void __cdecl _renderDrumWave(Sint32 *buffer, int no, $04553E4401276348CEA0C0E6398A028E *instrument, int len)
{
  int i;
  int s_offset_1;
  __int16 pan;
  Uint32 sample_sf;
  Sint32 val;
  float volume_f;
  float left_f;
  float right_f;
  int noa;
  int nob;

  switch ( instrument->wave )
  {
    case 0u:
      noa = 0;
      goto LABEL_9;
    case 2u:
      noa = 1;
      goto LABEL_9;
    case 4u:
      noa = 4;
      goto LABEL_9;
    case 5u:
      noa = 2;
      goto LABEL_9;
    case 6u:
      noa = 3;
LABEL_9:
      nob = noa + 150;
      sample_sf = (signed __int64)((long double)(800 * instrument->cur_note.note + 100) / 44100.0 * 4096.0);
      volume_f = (long double)instrument->cur_note.volume / 254.0;
      pan = instrument->cur_note.pan;
      left_f = volume_f;
      right_f = volume_f;
      if ( pan > 5 )
      {
        if ( pan > 6 )
          left_f = volume_f * ((long double)(12 - instrument->cur_note.pan) / 6.0);
      }
      else
      {
        right_f = volume_f * ((long double)(6 - instrument->cur_note.pan) / 6.0);
      }
      i = 0;
      break;
    case 9u:
      return;
    default:
      fprintf(stderr, "unknown drum wave: %d\n", instrument->wave);
      __assert_fail(
        "0",
        "/home/simon/Projekte/doukutsu_sdl/src/generic/org.cpp",
        0x12Cu,
        "void _renderDrumWave(Sint32*, int, ORG_Instrument*, int)");
      return;
  }
  while ( i < len )
  {
    instrument->samples += sample_sf;
    s_offset_1 = instrument->samples >> 12;
    if ( (signed int)chunks[nob]->len <= s_offset_1 + 1 )
    {
      if ( (signed int)chunks[nob]->len <= s_offset_1 )
        break;
      val = (chunks[nob]->buf[s_offset_1] - 128) << 7;
    }
    else
    {
      val = (signed __int16)_interpolate(
                              (chunks[nob]->buf[s_offset_1] - 128) << 7,
                              (chunks[nob]->buf[s_offset_1 + 1] - 128) << 7,
                              instrument->samples & 0xFFF);
    }
    buffer[2 * i] = (signed int)((long double)buffer[2 * i] + (long double)val * left_f);
    buffer[2 * i + 1] = (signed int)((long double)buffer[2 * i + 1] + (long double)val * right_f);
    ++i;
  }
  if ( instrument->samples >> 12 >= chunks[nob]->len )
  {
    instrument->samples = 0;
    instrument->playing = 0;
  }
}

void __cdecl _renderOrgWave(Sint32 *buffer, $04553E4401276348CEA0C0E6398A028E *instrument, int len)
{
  long double v3;
  int s_offset_1;
  Sint32 val;
  int i;
  __int16 pan;
  float volume_f;
  float left_f;
  float right_f;
  Sint8 *org_wave;

  volume_f = (long double)instrument->cur_note.volume / 254.0;
  pan = instrument->cur_note.pan;
  left_f = volume_f;
  right_f = volume_f;
  if ( pan > 5 )
  {
    if ( pan > 6 )
      left_f = volume_f * ((long double)(12 - instrument->cur_note.pan) / 6.0);
  }
  else
  {
    right_f = volume_f * ((long double)(6 - instrument->cur_note.pan) / 6.0);
  }
  org_wave = (Sint8 *)&org_waves[256 * instrument->wave];
  v3 = ((long double)(octfreq[instrument->cur_note.note / 0xCu] * (signed int)notefreq[instrument->cur_note.note % 0xCu])
      * 32.0
      + (long double)instrument->freq
      - 1000.0)
     / 44100.0
     * 4096.0;
  for ( i = 0; i < len; ++i )
  {
    instrument->samples = ((unsigned __int64)(signed __int64)v3 + instrument->samples) & 0xFFFFF;
    s_offset_1 = instrument->samples >> 12;
    val = (signed __int16)_interpolate(
                            org_wave[s_offset_1] << 7,
                            org_wave[(unsigned __int8)(((unsigned int)((s_offset_1 + 1) >> 31) >> 24) + s_offset_1 + 1)
                                   - ((unsigned int)((s_offset_1 + 1) >> 31) >> 24)] << 7,
                            instrument->samples & 0xFFF);
    buffer[2 * i] += (signed int)((long double)val * left_f);
    buffer[2 * i + 1] += (signed int)((long double)val * right_f);
  }
}

void __cdecl org_mixer(void *param, Uint8 *stream, int len)
{
  Sint16 v3;
  unsigned int samples_per_beat;
  int samples;
  int samples_left;
  signed int render_samples;
  int samples_rendered;
  int i;
  int ia;
  int j;
  int ja;
  int track_pos;
  Sint32 *buffer;
  Uint8 b_notestart;
  float f_volume;

  samples = len / 4;
  if ( Player.org )
  {
    samples_per_beat = 44100 * Player.org->tempo / 1000;
    buffer = (Sint32 *)malloc(8 * samples);
    memset(buffer, 0, 8 * samples);
    samples_left = len / 4;
    samples_rendered = 0;
    while ( samples_left > 0 )
    {
      render_samples = samples_per_beat - Player.org->samples % samples_per_beat;
      if ( render_samples > samples_left )
        render_samples = samples_left;
      for ( i = 0; i <= 15; ++i )
      {
        if ( Player.org->track[i].note && Player.org->track[i].playing > 0 )
        {
          if ( i > 7 )
            _renderDrumWave(&buffer[2 * samples_rendered], i - 8, &Player.org->track[i], render_samples);
          else
            _renderOrgWave(&buffer[2 * samples_rendered], &Player.org->track[i], render_samples);
        }
      }
      samples_left -= render_samples;
      samples_rendered += render_samples;
      Player.org->samples += render_samples;
      if ( !(Player.org->samples % samples_per_beat) )
      {
        if ( Player.fadeout )
          Player.volume -= 2;
        if ( Player.volume < 0 )
          Player.volume = 0;
        if ( ++Player.org->pos >= Player.org->loopEnd )
          setORGPosition(Player.org, Player.org->loopStart);
        for ( ia = 0; ia <= 15; ++ia )
        {
          track_pos = Player.org->track[ia].pos;
          if ( Player.org->track[ia].note )
          {
            b_notestart = 0;
            if ( Player.org->track[ia].num_notes > track_pos
              && Player.org->pos == Player.org->track[ia].note[track_pos].start )
            {
              ++Player.org->track[ia].pos;
              if ( Player.org->track[ia].note[track_pos].note != -1 )
              {
                Player.org->track[ia].samples = 0;
                if ( Player.org->track[ia].pi )
                  v3 = 1;
                else
                  v3 = Player.org->track[ia].note[track_pos].length;
                Player.org->track[ia].playing = v3;
                Player.org->track[ia].cur_note.note = Player.org->track[ia].note[track_pos].note;
                b_notestart = 1;
              }
              if ( Player.org->track[ia].note[track_pos].pan != -1 )
                Player.org->track[ia].cur_note.pan = Player.org->track[ia].note[track_pos].pan;
              if ( Player.org->track[ia].note[track_pos].volume != -1 )
                Player.org->track[ia].cur_note.volume = Player.org->track[ia].note[track_pos].volume;
            }
            if ( !b_notestart && Player.org->track[ia].playing > 0 && ia <= 7 )
              --Player.org->track[ia].playing;
          }
        }
      }
    }
    for ( j = 0; 2 * samples > j; ++j )
    {
      if ( buffer[j] <= 0x7FFF )
      {
        if ( buffer[j] >= -32768 )
        {
          buffer[j] = buffer[j];
        }
        else
        {
          fprintf(stderr, "%d! ", 0x8000 - buffer[j]);
          buffer[j] = -32768;
        }
      }
      else
      {
        fprintf(stderr, "%d! ", buffer[j] - 0x7FFF);
        buffer[j] = 0x7FFF;
      }
    }
    f_volume = (long double)Player.volume / 192.0;
    for ( ja = 0; ja < samples; ++ja )
    {
      *(_WORD *)&stream[4 * ja] = (signed __int16)((long double)*(signed __int16 *)&stream[4 * ja]
                                                 + (long double)buffer[2 * ja] * f_volume);
      *(_WORD *)&stream[2 * (2 * ja + 1)] = (signed __int16)((long double)*(signed __int16 *)&stream[2 * (2 * ja + 1)]
                                                           + (long double)buffer[2 * ja + 1] * f_volume);
    }
    free(buffer);
  }
}

void initORG()
{
  int dummy;

  Player.org = 0;
  org_waves = (Uint8 *)get_resource("Wave", &dummy);
}

void quitORG()
{
  Player.org = 0;
}

