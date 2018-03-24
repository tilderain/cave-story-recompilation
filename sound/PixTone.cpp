#include "types.h"
#include "SDL_stdinc.h"
#include "PixTone.h"

void MakeWaveTables();
signed int __cdecl MakePixelWaveData($296577AB1FDEBC0CA4D43AF2DF231431 *ptp, unsigned __int8 *pData);

bool wave_tables_made;
Sint8 gWaveModelTable[1536];

void MakeWaveTables()
{
  float v0;
  int v1;
  int i;
  int ia;
  int ib;
  int ic;
  int id;
  int ie;
  int a;
  int aa;
  int ab;

  for ( i = 0; i <= 255; ++i )
  {
    v0 = (long double)i * 6.2831841 / 256.0;
    gWaveModelTable[i] = (signed __int16)(sinf(v0) * 64.0);
    v1 = gWaveModelTable[i];
  }
  a = 0;
  for ( ia = 0; ia <= 63; ++ia )
    *(_BYTE *)(ia + 136098560) = (a++ << 6) / 64;
  aa = 0;
  while ( ia <= 191 )
    *(_BYTE *)(ia++ + 136098560) = 64 - (aa++ << 6) / 64;
  ab = 0;
  while ( ia <= 255 )
    *(_BYTE *)(ia++ + 136098560) = (ab++ << 6) / 64 - 64;
  for ( ib = 0; ib <= 255; ++ib )
    *(_BYTE *)(ib + 136098816) = ib / 2 - 64;
  for ( ic = 0; ic <= 255; ++ic )
    *(_BYTE *)(ic + 136099072) = 64 - ic / 2;
  for ( id = 0; id <= 127; ++id )
    *(_BYTE *)(id + 136099328) = 64;
  while ( id <= 255 )
    *(_BYTE *)(id++ + 136099328) = -64;
  srand(0);
  for ( ie = 0; ie <= 255; ++ie )
    *(_BYTE *)(ie + 136099584) = (char)rand() / 2;
}

signed int __cdecl MakePixelWaveData($296577AB1FDEBC0CA4D43AF2DF231431 *ptp, unsigned __int8 *pData)
{
  long double v2;
  char envelopeTable[256];
  int i;
  int a;
  int b;
  int c;
  int d;
  float dPitch;
  float dMain;
  float dVolume;
  float dEnvelope;
  float d1;
  float d2;
  float d3;

  if ( wave_tables_made != 1 )
  {
    MakeWaveTables();
    wave_tables_made = 1;
  }
  memset(envelopeTable, 0, 0x100u);
  i = 0;
  dEnvelope = (long double)ptp->initial;
  while ( ptp->pointAx > i )
  {
    envelopeTable[i] = (signed __int16)dEnvelope;
    dEnvelope = ((long double)ptp->pointAy - (long double)ptp->initial) / (long double)ptp->pointAx + dEnvelope;
    ++i;
  }
  dEnvelope = (long double)ptp->pointAy;
  while ( ptp->pointBx > i )
  {
    envelopeTable[i] = (signed __int16)dEnvelope;
    dEnvelope = ((long double)ptp->pointBy - (long double)ptp->pointAy) / (long double)(ptp->pointBx - ptp->pointAx)
              + dEnvelope;
    ++i;
  }
  dEnvelope = (long double)ptp->pointBy;
  while ( ptp->pointCx > i )
  {
    envelopeTable[i] = (signed __int16)dEnvelope;
    dEnvelope = ((long double)ptp->pointCy - (long double)ptp->pointBy) / (long double)(ptp->pointCx - ptp->pointBx)
              + dEnvelope;
    ++i;
  }
  dEnvelope = (long double)ptp->pointCy;
  while ( i <= 255 )
  {
    envelopeTable[i] = (signed __int16)dEnvelope;
    dEnvelope = dEnvelope - (long double)ptp->pointCy / (long double)(256 - ptp->pointCx);
    ++i;
  }
  dPitch = (long double)ptp->oPitch.offset;
  dMain = (long double)ptp->oMain.offset;
  dVolume = (long double)ptp->oVolume.offset;
  if ( ptp->oMain.num == 0.0 )
    d1 = 0.0;
  else
    d1 = 256.0 / ((long double)ptp->size / ptp->oMain.num);
  if ( ptp->oPitch.num == 0.0 )
    d2 = 0.0;
  else
    d2 = 256.0 / ((long double)ptp->size / ptp->oPitch.num);
  if ( ptp->oVolume.num == 0.0 )
    d3 = 0.0;
  else
    d3 = 256.0 / ((long double)ptp->size / ptp->oVolume.num);
  for ( i = 0; ptp->size > i; ++i )
  {
    a = (unsigned __int8)(((unsigned __int64)(signed int)dMain >> 56) + (signed int)dMain)
      - ((unsigned int)((signed int)dMain >> 31) >> 24);
    b = (unsigned __int8)(((unsigned __int64)(signed int)dPitch >> 56) + (signed int)dPitch)
      - ((unsigned int)((signed int)dPitch >> 31) >> 24);
    c = (unsigned __int8)(((unsigned __int64)(signed int)dVolume >> 56) + (signed int)dVolume)
      - ((unsigned int)((signed int)dVolume >> 31) >> 24);
    d = (signed int)((long double)(i << 8) / (long double)ptp->size);
    pData[i] = gWaveModelTable[256 * ptp->oMain.model + a]
             * ptp->oMain.top
             / 64
             * (gWaveModelTable[256 * ptp->oVolume.model + c] * ptp->oVolume.top / 64 + 64)
             / 64
             * envelopeTable[d]
             / 64
             + -128;
    if ( *(_BYTE *)((ptp->oPitch.model << 8) + b + 136098304) >= 0 )
      v2 = (d1 + d1)
         * (long double)*(char *)((ptp->oPitch.model << 8) + b + 136098304)
         * (long double)ptp->oPitch.top
         / 64.0
         / 64.0
         + d1
         + dMain;
    else
      v2 = d1
         * 0.5
         * (long double)-*(char *)((ptp->oPitch.model << 8) + b + 136098304)
         * (long double)ptp->oPitch.top
         / 64.0
         / -64.0
         + d1
         + dMain;
    dMain = v2;
    dPitch = dPitch + d2;
    dVolume = dVolume + d3;
  }
  return 1;
}

