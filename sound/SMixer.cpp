#include "stddef.h"
//#include "types.h"
//#include "libio.h"
//#include "types.h"
#include "stdint.h"
#include "SDL_stdinc.h"
#include "SDL_audio.h"
#include "SMixer.h"
#include "stdio.h"

int _interpolate($8D9359E30B30BEB685C90F8A0F30C069 *chan, bool left);
void _advance($8D9359E30B30BEB685C90F8A0F30C069 *chan);
signed int _checkRepeat($8D9359E30B30BEB685C90F8A0F30C069 *chan);
void _mix_callback(void *userdata, Uint8 *stream, int len);
void SMixer_StopChunk($FE85C58A60403E3389C96E96D80030A8 *c);
void SMixer_Reset($FE85C58A60403E3389C96E96D80030A8 *c);
void SMixer_SetVolume($FE85C58A60403E3389C96E96D80030A8 *c, Uint16 volume);
void SMixer_SetPan($FE85C58A60403E3389C96E96D80030A8 *c, Uint16 pan);
void SMixer_SetFrequency($FE85C58A60403E3389C96E96D80030A8 *c, Uint32 freq);
void SMixer_InitChunk($FE85C58A60403E3389C96E96D80030A8 *c);
void SMixer_PlayChunk($FE85C58A60403E3389C96E96D80030A8 *c, Sint32 repeat);
void SMixer_FreeChunks();
void SMixer_Init();
void SMixer_Start();
void SMixer_Quit();

int device_frequency;
Uint16 device_format;
int device_channels;
$8D9359E30B30BEB685C90F8A0F30C069 mix_chans[255];
unsigned int mix_nextfree;

int _interpolate($8D9359E30B30BEB685C90F8A0F30C069 *chan, bool left)
{
  int v2;

  if ( left )
    v2 = chan->data->lvol;
  else
    v2 = chan->data->rvol;
  return (unsigned __int16)((signed __int16)((signed __int16)(((unsigned __int16)(1024 - chan->pos_comma)
                                                             * (signed __int16)((chan->data->buf[chan->pos] - 128) << 7)
                                                             + (signed __int16)((chan->data->buf[(chan->pos + 2)
                                                                                               % chan->data->len]
                                                                               - 128) << 7)
                                                             * chan->pos_comma) >> 10)
                                           * chan->data->vol >> 10)
                          * v2 >> 8);
}

void _advance($8D9359E30B30BEB685C90F8A0F30C069 *chan)
{
  Uint16 freq;

  freq = chan->data->freq;
  chan->pos += (unsigned __int8)((signed int)freq >> 10);
  chan->pos_comma += freq & 0x3FF;
  chan->pos += (signed int)chan->pos_comma >> 10;
  chan->pos_comma &= 0x3FFu;
}

signed int _checkRepeat($8D9359E30B30BEB685C90F8A0F30C069 *chan)
{
  if ( chan->pos >= chan->data->len )
  {
    if ( chan->repeat <= 0 )
    {
      if ( chan->repeat >= 0 )
      {
        chan->pos = 0;
        return 1;
      }
      chan->pos = 0;
    }
    else
    {
      --chan->repeat;
      chan->pos = 0;
    }
  }
  return 0;
}

void _mix_callback(void *userdata, Uint8 *stream, int len)
{
  unsigned int v3;
  _DWORD *v4;
  Sint32 accum;
  char left;
  int i;
  unsigned int c;
  $8D9359E30B30BEB685C90F8A0F30C069 *cur_chan;

  left = 1;
  for ( i = 0; len / 2 > i; ++i )
  {
    accum = 0;
    for ( c = 0; c < mix_nextfree; ++c )
    {
      cur_chan = ($8D9359E30B30BEB685C90F8A0F30C069 *)(16 * c + 136110560);
      if ( mix_chans[c].data )
      {
        accum += (signed __int16)_interpolate(cur_chan, left);
        _advance(cur_chan);
        if ( (unsigned __int8)_checkRepeat(cur_chan) )
        {
          --mix_nextfree;
          v3 = 16 * c;
          v4 = (_DWORD *)(16 * mix_nextfree);
          mix_chans[v3 / 0x10].pos = mix_chans[mix_nextfree].pos;
          *(_DWORD *)(v3 + 136110564) = v4[34027641];
          *(_DWORD *)(v3 + 136110568) = v4[34027642];
          *(_DWORD *)(v3 + 136110572) = v4[34027643];
        }
      }
    }
    if ( accum <= 0x7FFF )
    {
      if ( accum < -32768 )
        LOWORD(accum) = -32768;
    }
    else
    {
      LOWORD(accum) = 0x7FFF;
    }
    *(_WORD *)&stream[2 * i] += accum;
    left ^= 1u;
  }
  org_mixer(userdata, stream, len);
}

void SMixer_StopChunk($FE85C58A60403E3389C96E96D80030A8 *c)
{
  unsigned int v1;
  _DWORD *v2;
  unsigned int i;

  SDL_LockAudio();
  for ( i = 0; i < mix_nextfree; ++i )
  {
    if ( mix_chans[i].data == c )
    {
      --mix_nextfree;
      v1 = 16 * i;
      v2 = (_DWORD *)(16 * mix_nextfree);
      mix_chans[v1 / 0x10].pos = mix_chans[mix_nextfree].pos;
      *(_DWORD *)(v1 + 136110564) = v2[34027641];
      *(_DWORD *)(v1 + 136110568) = v2[34027642];
      *(_DWORD *)(v1 + 136110572) = v2[34027643];
    }
  }
  SDL_UnlockAudio();
}



void SMixer_Reset($FE85C58A60403E3389C96E96D80030A8 *c)
{
  unsigned int i;

  SDL_LockAudio();
  for ( i = 0; i < mix_nextfree; ++i )
  {
    if ( mix_chans[i].data == c )
    {
      mix_chans[i].pos = 0;
      mix_chans[i].pos_comma = 0;
      break;
    }
  }
  SDL_UnlockAudio();
}



void SMixer_SetVolume($FE85C58A60403E3389C96E96D80030A8 *c, Uint16 volume)
{
  SDL_LockAudio();
  c->vol = (volume << 10) / 300;
  SDL_UnlockAudio();
}



void SMixer_SetPan($FE85C58A60403E3389C96E96D80030A8 *c, Uint16 pan)
{
  Sint16 lpan;
  Sint16 rpan;

  SDL_LockAudio();
  lpan = 256 - pan;
  rpan = pan - 256;
  c->lvol = 256;
  c->rvol = 256;
  if ( (signed __int16)(256 - pan) > 0 && lpan <= 255 )
    c->lvol = lpan;
  if ( rpan > 0 && rpan <= 255 )
    c->rvol = rpan;
  SDL_UnlockAudio();
}



void SMixer_SetFrequency($FE85C58A60403E3389C96E96D80030A8 *c, Uint32 freq)
{
  SDL_LockAudio();
  c->freq = (freq << 10) / 0x15888;
  SDL_UnlockAudio();
}



void SMixer_InitChunk($FE85C58A60403E3389C96E96D80030A8 *c)
{
  c->vol = 1024;
  c->lvol = 256;
  c->rvol = 256;
  c->freq = 256;
}

void SMixer_PlayChunk($FE85C58A60403E3389C96E96D80030A8 *c, Sint32 repeat)
{
  unsigned int v2;
  unsigned int v3;
  int ch_0_4;
  unsigned int i;

  SDL_LockAudio();
  for ( i = 0; i < mix_nextfree; ++i )
  {
    if ( mix_chans[i].data == c )
    {
      mix_chans[i].repeat = repeat;
      mix_chans[i].pos = 0;
      break;
    }
  }
  if ( i == mix_nextfree )
  {
    if ( mix_nextfree > 0xFE )
      return;
    LOWORD(ch_0_4) = 0;
    v2 = mix_nextfree;
    v3 = 16 * mix_nextfree;
    mix_chans[v3 / 0x10].pos = 0;
    *(_DWORD *)(v3 + 136110564) = ch_0_4;
    *(_DWORD *)(v3 + 136110568) = repeat;
    *(_DWORD *)(v3 + 136110572) = c;
    mix_nextfree = v2 + 1;
  }
  SDL_UnlockAudio();
}



void SMixer_FreeChunks()
{
  size_t i;

  mix_nextfree = 0;
  SDL_LockAudio();
  for ( i = 0; i <= 0x9F; ++i )
  {
    if ( chunks[i] )
    {
      free(chunks[i]->buf);
      free(chunks[i]);
      chunks[i] = 0;
    }
  }
  SDL_UnlockAudio();
}



void SMixer_Init()
{
  SDL_AudioSpec real;
  SDL_AudioSpec desiredFormat;

  desiredFormat.freq = 44100;
  desiredFormat.samples = 1024;
  desiredFormat.format = -32752;
  desiredFormat.channels = 2;
  desiredFormat.callback = _mix_callback;
  if ( SDL_OpenAudio(&desiredFormat, &real) != 0 )
    fwrite("Couldn't open audio device!\n", 1u, 0x1Cu, stderr);
  device_frequency = real.freq;
  device_format = real.format;
  device_channels = real.channels;
  if ( real.format != -32752 || device_channels != 2 )
    fwrite("Wrong device format. Mixer is broken!\n", 1u, 0x26u, stderr);
}


void SMixer_Start()
{
  SDL_PauseAudio(0);
}


void SMixer_Quit()
{
  SDL_CloseAudio();
}


