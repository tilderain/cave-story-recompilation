#include "stddef.h"
#include "stdint.h"
#include "SDL_stdinc.h"
#include "cstddef"
#include "new_allocator.h"
#include "cpp_type_traits.h"
#include "debug.h"
#include "SDL_audio.h"
#include "SMixer.h"
#include "pt.h"
#include "numeric_traits.h"

signed int InitDirectSound();
void EndDirectSound();
void PlaySoundObject(int no, int mode);
void ChangeSoundFrequency(int no, Uint32 rate);
int MakePixToneObject($296577AB1FDEBC0CA4D43AF2DF231431 *ptp, int ptp_num, int no);

signed int InitDirectSound()
{
  SMixer_Init();
  initWaveTables();
  StartOrganya();
  SMixer_Start();
  return 1;
}

void EndDirectSound()
{
  EndOrganya();
  SMixer_FreeChunks();
  SMixer_Quit();
}

void PlaySoundObject(int no, int mode)
{
  if ( chunks[no] )
  {
    if ( mode )
    {
      if ( mode == 1 )
      {
        SMixer_PlayChunk(chunks[no], 0);
      }
      else if ( mode == -1 )
      {
        SMixer_StopChunk(chunks[no]);
        SMixer_PlayChunk(chunks[no], -1);
      }
    }
    else
    {
      SMixer_StopChunk(chunks[no]);
    }
  }
}

void ChangeSoundFrequency(int no, Uint32 rate)
{
  if ( chunks[no] )
    SMixer_SetFrequency(chunks[no], 10 * rate + 100);
}

int MakePixToneObject($296577AB1FDEBC0CA4D43AF2DF231431 *ptp, int ptp_num, int no)
{
  SDL_AudioCVT cvt;
  Uint8 *mixbuf;
  int sample_count;
  $FE85C58A60403E3389C96E96D80030A8 **const chunk;
  int i;

  sample_count = 0;
  for ( i = 0; i < ptp_num; ++i )
  {
    if ( ptp[i].size > sample_count )
      sample_count = ptp[i].size;
  }
  memset(&cvt, 0, 0x54u);
  mixPTWaves(&mixbuf, ptp, ptp_num);
  SDL_LockAudio();
  chunk = &chunks[no];
  if ( chunks[no] )
  {
    SMixer_StopChunk(*chunk);
    if ( (*chunk)->buf )
      free((*chunk)->buf);
    free(*chunk);
    *chunk = 0;
  }
  *chunk = ($FE85C58A60403E3389C96E96D80030A8 *)malloc(0x14u);
  (*chunk)->buf = mixbuf;
  (*chunk)->len = sample_count;
  SMixer_InitChunk(*chunk);
  SDL_UnlockAudio();
  return sample_count;
}



