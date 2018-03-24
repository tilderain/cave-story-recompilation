#include "types.h"
#include "stdint.h"
#include "SDL_stdinc.h"
#include "pt.h"
void initWaveTables()
{
  float v0;
  int i;
  int ia;
  int ib;
  int ic;
  int id;
  int ie;
  int ig;
  int ih;

  for ( i = 0; i <= 255; ++i )
  {
    v0 = (long double)i * 6.283185307179586 / 256.0;
    waveModelTable[i] = (signed __int16)(sinf(v0) * 64.0);
  }
  for ( ia = 0; ia <= 63; ++ia )
    *(_BYTE *)(ia + 136088736) = (ia << 8) / 256;
  for ( ib = 0; ib <= 127; ++ib )
    *(_BYTE *)(ib + 136088800) = 64 - (ib << 8) / 256;
  for ( ic = 0; ic <= 63; ++ic )
    *(_BYTE *)(ic + 136088928) = (ic << 8) / 256 - 64;
  for ( id = 0; id <= 255; ++id )
    *(_BYTE *)(id + 136088992) = (id << 7) / 256 - 64;
  for ( ie = 0; ie <= 255; ++ie )
    *(_BYTE *)(ie + 136089248) = 64 - (ie << 7) / 256;
  for ( ig = 0; ig <= 127; ++ig )
    *(_BYTE *)(ig + 136089504) = 64;
  while ( ig <= 255 )
    *(_BYTE *)(ig++ + 136089504) = -64;
  srand(0);
  for ( ih = 0; ih <= 255; ++ih )
    *(_BYTE *)(ih + 136089760) = (char)rand() / 2;
}

void __cdecl makePTWave(Uint8 **buf, $296577AB1FDEBC0CA4D43AF2DF231431 *param)
{
  long double v2;
  Sint8 envelopeTable[256];
  int i;
  float e;
  int iMain;
  int iPitch;
  int iVolume;
  int iEnvelope;
  float fPitch;
  float fMain;
  float fVolume;
  float fPitchPlus;
  float fMainPlus;
  float fVolumePlus;

  memset(envelopeTable, 0, 0x100u);
  i = 0;
  e = (long double)param->initial;
  while ( param->pointAx > i )
  {
    envelopeTable[i] = (signed __int16)e;
    e = ((long double)param->pointAy - (long double)param->initial) / (long double)param->pointAx + e;
    ++i;
  }
  e = (long double)param->pointAy;
  while ( param->pointBx > i )
  {
    envelopeTable[i] = (signed __int16)e;
    e = ((long double)param->pointBy - (long double)param->pointAy) / (long double)(param->pointBx - param->pointAx) + e;
    ++i;
  }
  e = (long double)param->pointBy;
  while ( param->pointCx > i )
  {
    envelopeTable[i] = (signed __int16)e;
    e = ((long double)param->pointCy - (long double)param->pointBy) / (long double)(param->pointCx - param->pointBx) + e;
    ++i;
  }
  e = (long double)param->pointCy;
  while ( i <= 255 )
  {
    envelopeTable[i] = (signed __int16)e;
    e = e - (long double)param->pointCy / (long double)(256 - param->pointCx);
    ++i;
  }
  fPitch = (long double)param->oPitch.offset;
  fVolume = (long double)param->oVolume.offset;
  fMain = (long double)param->oVolume.offset;
  if ( param->oMain.num == 0.0 )
    fMainPlus = 0.0;
  else
    fMainPlus = 256.0 / ((long double)param->size / param->oMain.num);
  if ( param->oVolume.num == 0.0 )
    fVolumePlus = 0.0;
  else
    fVolumePlus = 256.0 / ((long double)param->size / param->oVolume.num);
  if ( param->oPitch.num == 0.0 )
    fPitchPlus = 0.0;
  else
    fPitchPlus = 256.0 / ((long double)param->size / param->oPitch.num);
  *buf = (Uint8 *)malloc(param->size);
  for ( i = 0; param->size > i; ++i )
  {
    iMain = (unsigned __int8)(((unsigned __int64)(signed int)fMain >> 56) + (signed int)fMain)
          - ((unsigned int)((signed int)fMain >> 31) >> 24);
    iVolume = (unsigned __int8)(((unsigned __int64)(signed int)fVolume >> 56) + (signed int)fVolume)
            - ((unsigned int)((signed int)fVolume >> 31) >> 24);
    iPitch = (unsigned __int8)(((unsigned __int64)(signed int)fPitch >> 56) + (signed int)fPitch)
           - ((unsigned int)((signed int)fPitch >> 31) >> 24);
    iEnvelope = (signed int)((long double)(i << 8) / (long double)param->size);
    (*buf)[i] = waveModelTable[256 * param->oMain.model + iMain]
              * param->oMain.top
              / 64
              * (waveModelTable[256 * param->oVolume.model + iVolume] * param->oVolume.top / 64 + 64)
              / 64
              * envelopeTable[iEnvelope]
              / 64
              + -128;
    if ( *(_BYTE *)((param->oPitch.model << 8) + iPitch + 136088480) >= 0 )
      v2 = (fMainPlus + fMainPlus)
         * (long double)*(char *)((param->oPitch.model << 8) + iPitch + 136088480)
         * (long double)param->oPitch.top
         / 64.0
         / 64.0
         + fMainPlus
         + fMain;
    else
      v2 = fMainPlus
         * 0.5
         * (long double)-*(char *)((param->oPitch.model << 8) + iPitch + 136088480)
         * (long double)param->oPitch.top
         / 64.0
         / -64.0
         + fMainPlus
         + fMain;
    fMain = v2;
    fPitch = fPitch + fPitchPlus;
    fVolume = fVolume + fVolumePlus;
  }
}

void __cdecl mixPTWaves(Uint8 **buf, $296577AB1FDEBC0CA4D43AF2DF231431 *param, int count)
{
  Uint8 *waveptr;
  Sint16 *mixbuf;
  int i;
  int j;
  int max_size;

  max_size = 0;
  for ( i = 0; i < count; ++i )
  {
    if ( param[i].size > max_size )
      max_size = param[i].size;
  }
  mixbuf = (Sint16 *)malloc(2 * max_size);
  *buf = (Uint8 *)malloc(max_size);
  for ( j = 0; j < max_size; ++j )
    mixbuf[j] = 128;
  for ( i = 0; i < count; ++i )
  {
    makePTWave(&waveptr, &param[i]);
    for ( j = 0; param[i].size > j; ++j )
      mixbuf[j] = mixbuf[j] + waveptr[j] - 128;
    free(waveptr);
  }
  for ( j = 0; j < max_size; ++j )
  {
    if ( mixbuf[j] <= 255 )
    {
      if ( mixbuf[j] >= 0 )
        (*buf)[j] = mixbuf[j];
      else
        (*buf)[j] = 0;
    }
    else
    {
      (*buf)[j] = -1;
    }
  }
  free(mixbuf);
}

