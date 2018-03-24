#include "stddef.h"
#include "types.h"
#include "types.h"
#include "stdio.h"
#include "libio.h"
#include "stdint.h"
#include "SDL_stdinc.h"
#include "SDL_rwops.h"
#include "windows_wrapper.h"
#include "Tags.h"
#include "windows_wrapper.h"

signed int __cdecl LoadNpcTable(char *path);
void ReleaseNpcTable();

_UNKNOWN unk_814C220;

signed int __cdecl LoadNpcTable(char *path)
{
  signed int result;
  $3999A2E3BC6E7A1D19AF6FBFAF274F94 *v2;
  $3999A2E3BC6E7A1D19AF6FBFAF274F94 *v3;
  $3999A2E3BC6E7A1D19AF6FBFAF274F94 *v4;
  $3999A2E3BC6E7A1D19AF6FBFAF274F94 *v5;
  SDL_RWops_0 *fp;
  int n;
  int na;
  int nb;
  int nc;
  int nd;
  int ne;
  int nf;
  int ng;
  int nh;
  int ni;
  unsigned int size;
  int num;

  size = GetFileSizeLong(path);
  if ( size == -1 )
    return 0;
  num = size / 0x18;
  gNpcTable = ($3999A2E3BC6E7A1D19AF6FBFAF274F94 *)malloc(24 * (size / 0x18));
  if ( !gNpcTable )
    return 0;
  fp = SDL_RWFromFile(path, &unk_814C220);
  if ( fp )
  {
    for ( n = 0; n < num; ++n )
    {
      v2 = &gNpcTable[n];
      v2->bits = SDL_ReadLE16(fp);
    }
    for ( na = 0; na < num; ++na )
    {
      v3 = &gNpcTable[na];
      v3->life = SDL_ReadLE16(fp);
    }
    for ( nb = 0; nb < num; ++nb )
      fp->read(fp, &gNpcTable[nb].surf, 1, 1);
    for ( nc = 0; nc < num; ++nc )
      fp->read(fp, &gNpcTable[nc].destroy_voice, 1, 1);
    for ( nd = 0; nd < num; ++nd )
      fp->read(fp, &gNpcTable[nd].hit_voice, 1, 1);
    for ( ne = 0; ne < num; ++ne )
      fp->read(fp, &gNpcTable[ne].size, 1, 1);
    for ( nf = 0; nf < num; ++nf )
    {
      v4 = &gNpcTable[nf];
      v4->exp = SDL_ReadLE32(fp);
    }
    for ( ng = 0; ng < num; ++ng )
    {
      v5 = &gNpcTable[ng];
      v5->damage = SDL_ReadLE32(fp);
    }
    for ( nh = 0; nh < num; ++nh )
      fp->read(fp, &gNpcTable[nh].hit, 4, 1);
    for ( ni = 0; ni < num; ++ni )
      fp->read(fp, &gNpcTable[ni].view, 4, 1);
    fp->close(fp);
    result = 1;
  }
  else
  {
    free(gNpcTable);
    gNpcTable = 0;
    result = 0;
  }
  return result;
}



void ReleaseNpcTable()
{
  if ( gNpcTable )
  {
    free(gNpcTable);
    gNpcTable = 0;
  }
}

int __userpurge RGB@<eax>(int r, Uint8 g, Uint8 b, char a4)
{
  int result;

  result = r;
  *(_DWORD *)r = 0;
  *(_BYTE *)(r + 3) = -1;
  *(_BYTE *)r = g;
  *(_BYTE *)(r + 1) = b;
  *(_BYTE *)(r + 2) = a4;
  return result;
}

