#include "stddef.h"
#include "types.h"
#include "stdio.h"
#include "libio.h"
#include "stdint.h"
#include "SDL_stdinc.h"
#include "SDL_rwops.h"
void __cdecl GetCompileDate(int *year, int *month, int *day)
{
  char *table[13];
  char strMonth[16];
  int i;

  table[0] = (char *)&unk_814B854;
  table[1] = (char *)&unk_814B858;
  table[2] = (char *)&unk_814B85C;
  table[3] = (char *)&unk_814B860;
  table[4] = (char *)&unk_814B864;
  table[5] = (char *)&unk_814B868;
  table[6] = (char *)&unk_814B86C;
  table[7] = (char *)&unk_814B870;
  table[8] = (char *)&unk_814B874;
  table[9] = (char *)&unk_814B878;
  table[10] = (char *)&unk_814B87C;
  table[11] = (char *)&unk_814B880;
  table[12] = (char *)&unk_814B884;
  sscanf("Mar 15 2010", "%s %ld %ld", strMonth, day, year);
  for ( i = 0; i <= 11 && memcmp(strMonth, table[i], 3u); ++i )
    ;
  *month = i;
}

signed int __cdecl GetCompileVersion(int *v1, int *v2, int *v3, int *v4)
{
  *v1 = 1;
  *v2 = 0;
  *v3 = 0;
  *v4 = 4;
  return 1;
}

signed int __cdecl ErrorLog(const char *str, int value)
{
  fprintf(stderr, "%s,%ld\n", str, value);
  return 1;
}

int __cdecl GetFileSizeLong(char *path)
{
  int len;
  SDL_RWops_0 *fp;

  fp = SDL_RWFromFile(path, "rb");
  if ( !fp )
    return -1;
  len = fp->seek(fp, 0, 2);
  fp->close(fp);
  return len;
}

bool __cdecl IsShiftJIS(unsigned __int8 c)
{
  if ( c > 0x80u && c <= 0x9Fu )
    return 1;
  if ( c <= 0xDFu || c > 0xEFu )
    return 0;
  return 1;
}

bool __cdecl IsEnableBitmap(char *path)
{
  char str[16];
  SDL_RWops_0 *fp;
  int len;

  len = strlen(_extra_text);
  fp = SDL_RWFromFile(path, "rb");
  if ( !fp )
    return 0;
  fp->seek(fp, -len, 2);
  fp->read(fp, str, 1, len);
  fp->close(fp);
  return memcmp(str, _extra_text, len) == 0;
}

