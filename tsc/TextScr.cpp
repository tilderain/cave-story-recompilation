#include "stddef.h"
#include "types.h"
#include "types.h"
#include "stdio.h"
#include "libio.h"
#include "stdint.h"
#include "SDL_stdinc.h"
#include "SDL_rwops.h"
#include "SDL_video.h"
#include "Tags.h"
#include "Escape.h"
#include "KeyControl.h"

_BOOL4 InitTextScript2();
void EndTextScript();
void __cdecl EncryptionBinaryData2(unsigned __int8 *pData, int size);
signed int __cdecl LoadTextScript2(char *name);
signed int __cdecl LoadTextScript_Stage(char *name);
void __cdecl GetTextScriptPath(char *path);
int __cdecl GetTextScriptNo(int a);
signed int __cdecl StartTextScript(int no);
signed int __cdecl JumpTextScript(int no);
void StopTextScript();
void CheckNewLine();
void __cdecl SetNumberTextScript(int index);
void ClearTextLine();
void PutTextScript();
signed int TextScriptProc();
void RestoreTextScript();

_UNKNOWN unk_81D5ACC;
_UNKNOWN unk_81D5ACD;
int unk_81D5AD0;
_UNKNOWN unk_81D5AD4;
_UNKNOWN unk_81D5AD8;
_UNKNOWN unk_81D5AEC;
_UNKNOWN unk_81D5AF0;
int no;
_UNKNOWN unk_81D5AF8;
_UNKNOWN unk_81D5AFC;
_UNKNOWN unk_81D5B00;
_DWORD dword_81D5B04;
int dword_81D5B08;

RECT gRect_line = { 0, 0, 216, 16 };

_BOOL4 InitTextScript2()
{
  int i;

  unk_81D5ACC = 0;
  g_GameFlags &= 0xFFFFFFFB;
  for ( i = 0; i <= 3; ++i )
    MakeSurface_Generic(gRect_line.right, gRect_line.bottom, i + 30);
  memset(_text, 0, 0x100u);
  unk_81D5AC8 = (unsigned __int8 *)malloc(0x5000u);
  return unk_81D5AC8 != 0;
}

void EndTextScript()
{
  int i;

  free(unk_81D5AC8);
  ReleaseSurface(26);
  for ( i = 0; i <= 3; ++i )
    ReleaseSurface(i + 30);
}

void __cdecl EncryptionBinaryData2(unsigned __int8 *pData, int size)
{
  int i;
  int half;
  int val1;

  half = size / 2;
  if ( pData[size / 2] )
    val1 = -pData[half];
  else
    LOBYTE(val1) = -7;
  for ( i = 0; i < size; ++i )
  {
    if ( i != half )
      pData[i] += val1;
  }
}

signed int __cdecl LoadTextScript2(char *name)
{
  char path[260];
  SDL_RWops_0 *fp;

  sprintf(path, "%s/%s", gDataPath, name);
  unk_81D5AC4 = GetFileSizeLong(path);
  if ( unk_81D5AC4 == -1 )
    return 0;
  fp = SDL_RWFromFile(path, "rb");
  if ( !fp )
    return 0;
  fp->read(fp, unk_81D5AC8, 1, unk_81D5AC4);
  unk_81D5AC8[unk_81D5AC4] = 0;
  fp->close(fp);
  strcpy(gTS.path, name);
  EncryptionBinaryData2(unk_81D5AC8, unk_81D5AC4);
  return 1;
}

signed int __cdecl LoadTextScript_Stage(char *name)
{
  char path[260];
  SDL_RWops_0 *fp;
  int head_size;
  int body_size;

  sprintf(path, "%s/%s", gDataPath, "Head.tsc");
  head_size = GetFileSizeLong(path);
  if ( head_size == -1 )
    return 0;
  fp = SDL_RWFromFile(path, "rb");
  if ( !fp )
    return 0;
  fp->read(fp, unk_81D5AC8, 1, head_size);
  EncryptionBinaryData2(unk_81D5AC8, head_size);
  unk_81D5AC8[head_size] = 0;
  fp->close(fp);
  sprintf(path, "%s/%s", gDataPath, name);
  body_size = GetFileSizeLong(path);
  if ( body_size == -1 )
    return 0;
  fp = SDL_RWFromFile(path, "rb");
  if ( !fp )
    return 0;
  fp->read(fp, &unk_81D5AC8[head_size], 1, body_size);
  EncryptionBinaryData2(&unk_81D5AC8[head_size], body_size);
  unk_81D5AC8[head_size + body_size] = 0;
  fp->close(fp);
  unk_81D5AC4 = head_size + body_size;
  strcpy(gTS.path, name);
  return 1;
}

void __cdecl GetTextScriptPath(char *path)
{
  strcpy(path, gTS.path);
}

int __cdecl GetTextScriptNo(int a)
{
  return (char)unk_81D5AC8[a + 3]
       - 48
       + 10 * (char)unk_81D5AC8[a + 2]
       - 480
       + 100 * (char)unk_81D5AC8[a + 1]
       - 4800
       + 1000 * (char)unk_81D5AC8[a]
       - 48000;
}

signed int __cdecl StartTextScript(int no)
{
  int i;
  int event_no;

  unk_81D5ACC = 1;
  g_GameFlags |= 5u;
  unk_81D5AD8 = 0;
  unk_81D5AD4 = 0;
  unk_81D5AEC = 4;
  unk_81D5ACD = 0;
  unk_81D5B20 = 0;
  unk_81D5AFC = 0;
  dword_81D5B04 = 0;
  unk_81D5B1C = 0;
  unk_81C8610 = 0;
  rcView.left = 52;
  rcView.top = 184;
  rcView.right = 268;
  rcView.bottom = 232;
  for ( i = 0; i <= 3; ++i )
  {
    dword_81D59CC[i + 68] = 16 * i;
    CortBox2(&gRect_line, 0, i + 30);
    memset((void *)((i << 6) + 136141632), 0, 0x40u);
  }
  for ( unk_81D5AD0 = 0; ; ++unk_81D5AD0 )
  {
    if ( !unk_81D5AC8[unk_81D5AD0] )
      return 0;
    if ( unk_81D5AC8[unk_81D5AD0] != 35 )
      continue;
    event_no = GetTextScriptNo(++unk_81D5AD0);
    if ( no == event_no )
      break;
    if ( no < event_no )
      return 0;
  }
  while ( unk_81D5AC8[unk_81D5AD0] != 10 )
    ++unk_81D5AD0;
  ++unk_81D5AD0;
  return 1;
}

signed int __cdecl JumpTextScript(int no)
{
  int i;
  int event_no;

  unk_81D5ACC = 1;
  g_GameFlags |= 4u;
  unk_81D5AD8 = 0;
  unk_81D5AD4 = 0;
  unk_81D5AEC = 4;
  unk_81D5B20 = 0;
  for ( i = 0; i <= 3; ++i )
  {
    dword_81D59CC[i + 68] = 16 * i;
    CortBox2(&gRect_line, 0, i + 30);
    memset((void *)((i << 6) + 136141632), 0, 0x40u);
  }
  for ( unk_81D5AD0 = 0; ; ++unk_81D5AD0 )
  {
    if ( !unk_81D5AC8[unk_81D5AD0] )
      return 0;
    if ( unk_81D5AC8[unk_81D5AD0] != 35 )
      continue;
    event_no = GetTextScriptNo(++unk_81D5AD0);
    if ( no == event_no )
      break;
    if ( no < event_no )
      return 0;
  }
  while ( unk_81D5AC8[unk_81D5AD0] != 10 )
    ++unk_81D5AD0;
  ++unk_81D5AD0;
  return 1;
}

void StopTextScript()
{
  unk_81D5ACC = 0;
  g_GameFlags &= 0xFFFFFFFB;
  g_GameFlags |= 3u;
  unk_81D5ACD = 0;
}

void CheckNewLine()
{
  if ( dword_81D59CC[unk_81D5AD8 % 4 + 68] == 48 )
  {
    unk_81D5ACC = 3;
    g_GameFlags |= 4u;
    CortBox2(&gRect_line, 0, unk_81D5AD8 % 4 + 30);
    memset((void *)((unk_81D5AD8 % 4 << 6) + 136141632), 0, 0x40u);
  }
}

void __cdecl SetNumberTextScript(int index)
{
  int v1;
  int v2;
  int table[3];
  char str[5];
  Uint8 r;
  int bZero;
  int a;
  int b;
  int offset;
  int i;

  table[0] = 1000;
  table[1] = 100;
  table[2] = 10;
  a = gNumberTextScript[index];
  bZero = 0;
  offset = 0;
  for ( i = 0; i <= 2; ++i )
  {
    if ( a / table[i] || bZero )
    {
      b = a / table[i];
      str[offset] = b + 48;
      bZero = 1;
      a -= b * table[i];
      ++offset;
    }
  }
  str[offset] = a + 48;
  str[offset + 1] = 0;
  v1 = unk_81D5AD8 % 4 + 30;
  RGB((int)&r, 0xFFu, 0xFFu, 254);
  PutText2(6 * unk_81D5AD4, 0, str, (const SDL_Color_0 *const )&r, v1);
  strcat((char *)((unk_81D5AD8 % 4 << 6) + 136141632), str);
  PlaySoundObject(2, 1);
  unk_81D5B20 = 0;
  v2 = unk_81D5AD4;
  unk_81D5AD4 = v2 + strlen(str);
  if ( unk_81D5AD4 > 34 )
  {
    unk_81D5AD4 = 0;
    ++unk_81D5AD8;
    CheckNewLine();
  }
}

void ClearTextLine()
{
  int i;

  unk_81D5AD8 = 0;
  unk_81D5AD4 = 0;
  unk_81D5B1C = 0;
  for ( i = 0; i <= 3; ++i )
  {
    dword_81D59CC[i + 68] = 16 * i;
    CortBox2(&gRect_line, 0, i + 30);
    memset((void *)((i << 6) + 136141632), 0, 0x40u);
  }
}

void PutTextScript()
{
  bool v0;
  bool v1;
  Uint32 v2;
  RECT rcFrame3;
  RECT rcFrame2;
  RECT rcFrame1;
  RECT rect_cur;
  RECT rect_yesno;
  RECT rcItemBox5;
  RECT rcItemBox4;
  RECT rcItemBox3;
  RECT rcItemBox2;
  RECT rcItemBox1;
  RECT rcFace;
  RECT rect;
  Uint8 r;
  int i;
  int text_offset;

  if ( unk_81D5ACC && (unk_81D5ACD & 1) == 1 )
  {
    if ( unk_81D5ACD & 0x20 )
    {
      rcView.top = 32;
      rcView.bottom = 80;
    }
    else
    {
      rcView.top = 184;
      rcView.bottom = 232;
    }
    if ( unk_81D5ACD & 2 )
    {
      rcFrame1.left = 0;
      rcFrame1.top = 0;
      rcFrame1.right = 244;
      rcFrame1.bottom = 8;
      rcFrame2.left = 0;
      rcFrame2.top = 8;
      rcFrame2.right = 244;
      rcFrame2.bottom = 16;
      rcFrame3.left = 0;
      rcFrame3.top = 16;
      rcFrame3.right = 244;
      rcFrame3.bottom = 24;
      PutBitmap3(&grcFull, 38, rcView.top - 10, &rcFrame1, 26);
      for ( i = 1; i <= 6; ++i )
        PutBitmap3(&grcFull, 38, 8 * i + rcView.top - 10, &rcFrame2, 26);
      PutBitmap3(&grcFull, 38, 8 * i + rcView.top - 10, &rcFrame3, 26);
    }
    rcFace.left = 48 * (unk_81D5AFC % 6);
    rcFace.top = 48 * (unk_81D5AFC / 6);
    rcFace.right = 48 * (unk_81D5AFC % 6) + 48;
    rcFace.bottom = 48 * (unk_81D5AFC / 6) + 48;
    if ( unk_81D5B00 <= 26623 )
      unk_81D5B00 += 4096;
    PutBitmap3(&rcView, unk_81D5B00 / 512, rcView.top - 3, &rcFace, 27);
    if ( unk_81D5AFC )
      text_offset = 56;
    else
      text_offset = 0;
    for ( i = 0; i <= 3; ++i )
      PutBitmap3(&rcView, text_offset + 52, unk_81D5B1C + dword_81D59CC[i + 68] + rcView.top, &gRect_line, i + 30);
    v0 = unk_81D5B20++ % 0x14u > 0xC;
    v1 = v0 && unk_81D5ACC == 2;
    if ( v1 )
    {
      rect.left = text_offset + 6 * unk_81D5AD4 + 52;
      rect.top = rcView.top + dword_81D59CC[unk_81D5AD8 % 4 + 68] + unk_81D5B1C;
      rect.right = text_offset + 6 * unk_81D5AD4 + 52 + 5;
      rect.bottom = rect.top + 11;
      RGB((int)&r, 0xFFu, 0xFFu, 254);
      v2 = GetCortBoxColor((const SDL_Color_0 *const )&r);
      CortBox(&rect, v2);
    }
    rcItemBox1.left = 0;
    rcItemBox1.top = 0;
    rcItemBox1.right = 72;
    rcItemBox1.bottom = 16;
    rcItemBox2.left = 0;
    rcItemBox2.top = 8;
    rcItemBox2.right = 72;
    rcItemBox2.bottom = 24;
    rcItemBox3.left = 240;
    rcItemBox3.top = 0;
    rcItemBox3.right = 244;
    rcItemBox3.bottom = 8;
    rcItemBox4.left = 240;
    rcItemBox4.top = 8;
    rcItemBox4.right = 244;
    rcItemBox4.bottom = 16;
    rcItemBox5.left = 240;
    rcItemBox5.top = 16;
    rcItemBox5.right = 244;
    rcItemBox5.bottom = 24;
    if ( dword_81D5B04 )
    {
      PutBitmap3(&grcFull, 120, 128, &rcItemBox1, 26);
      PutBitmap3(&grcFull, 120, 144, &rcItemBox2, 26);
      PutBitmap3(&grcFull, 192, 128, &rcItemBox3, 26);
      PutBitmap3(&grcFull, 192, 136, &rcItemBox4, 26);
      PutBitmap3(&grcFull, 192, 144, &rcItemBox4, 26);
      PutBitmap3(&grcFull, 192, 152, &rcItemBox5, 26);
      if ( dword_81D5B08 <= 135 )
        ++dword_81D5B08;
      if ( dword_81D5B04 > 999 )
      {
        rect.left = 32
                  * (((((unsigned int)((dword_81D5B04 - 1000) >> 31) >> 29) + (_BYTE)dword_81D5B04 + 24) & 7)
                   - ((unsigned int)((dword_81D5B04 - 1000) >> 31) >> 29));
        rect.right = 32
                   * (((((unsigned int)((dword_81D5B04 - 1000) >> 31) >> 29) + (_BYTE)dword_81D5B04 + 24) & 7)
                    - ((unsigned int)((dword_81D5B04 - 1000) >> 31) >> 29))
                   + 32;
        rect.top = 16 * ((dword_81D5B04 - 1000) / 8);
        rect.bottom = 16 * ((dword_81D5B04 - 1000) / 8) + 16;
        PutBitmap3(&grcFull, 140, dword_81D5B08, &rect, 8);
      }
      else
      {
        rect.left = 16 * (dword_81D5B04 % 16);
        rect.right = 16 * (dword_81D5B04 % 16) + 16;
        rect.top = 16 * (dword_81D5B04 / 16);
        rect.bottom = 16 * (dword_81D5B04 / 16) + 16;
        PutBitmap3(&grcFull, 148, dword_81D5B08, &rect, 12);
      }
    }
    rect_yesno.left = 152;
    rect_yesno.top = 48;
    rect_yesno.right = 244;
    rect_yesno.bottom = 80;
    rect_cur.left = 112;
    rect_cur.top = 88;
    rect_cur.right = 128;
    rect_cur.bottom = 104;
    if ( unk_81D5ACC == 6 )
    {
      if ( unk_81D5AEC > 1 )
        i = 144;
      else
        i = 4 * (38 - unk_81D5AEC);
      PutBitmap3(&grcFull, 216, i, &rect_yesno, 26);
      if ( unk_81D5AEC == 16 )
        PutBitmap3(&grcFull, 41 * unk_81D5AF8 + 211, 154, &rect_cur, 26);
    }
  }
}

signed int TextScriptProc()
{
  signed int v1;
  signed int v2;
  int v3;
  signed int v4;
  char v5;
  int v6;
  int v7;
  char str[72];
  char str_0[64];
  RECT rcSymbol;
  int z;
  char c[3];
  Uint8 r;
  Uint8 v14;
  int i;
  int w;
  int x;
  int y;
  bool bExit;

  rcSymbol.left = 64;
  rcSymbol.top = 48;
  rcSymbol.right = 72;
  rcSymbol.bottom = 56;
  switch ( unk_81D5ACC )
  {
    case 0:
      goto LABEL_479;
    case 1:
      ++unk_81D5AEC;
      if ( !(g_GameFlags & 2) && (gKeyCancel | gKeyOk) & gKey )
        unk_81D5AEC += 4;
      if ( unk_81D5AEC <= 3 )
        goto LABEL_479;
      unk_81D5AEC = 0;
      bExit = 0;
      break;
    case 2:
      if ( (gKeyCancel | gKeyOk) & gKeyTrg )
        unk_81D5ACC = 1;
      goto LABEL_479;
    case 3:
      for ( i = 0; i <= 3; ++i )
      {
        dword_81D59CC[i + 68] -= 4;
        if ( !dword_81D59CC[i + 68] )
          unk_81D5ACC = 1;
        if ( dword_81D59CC[i + 68] == -16 )
          dword_81D59CC[i + 68] = 48;
      }
      goto LABEL_479;
    case 4:
      if ( unk_81D5AF0 != 9999 )
      {
        if ( unk_81D5AEC != 9999 )
          ++unk_81D5AEC;
        if ( unk_81D5AEC >= unk_81D5AF0 )
        {
          unk_81D5ACC = 1;
          unk_81D5B20 = 0;
        }
      }
      goto LABEL_479;
    case 5:
      if ( !(unsigned __int8)GetFadeActive() )
      {
        unk_81D5ACC = 1;
        unk_81D5B20 = 0;
      }
      goto LABEL_479;
    case 6:
      if ( unk_81D5AEC > 15 )
      {
        if ( gKeyTrg & gKeyOk )
        {
          PlaySoundObject(18, 1);
          if ( unk_81D5AF8 == 1 )
          {
            JumpTextScript(no);
          }
          else
          {
            unk_81D5ACC = 1;
            unk_81D5B20 = 0;
          }
        }
        else if ( gKeyTrg & gKeyLeft )
        {
          unk_81D5AF8 = 0;
          PlaySoundObject(1, 1);
        }
        else if ( gKeyTrg & gKeyRight )
        {
          unk_81D5AF8 = 1;
          PlaySoundObject(1, 1);
        }
      }
      else
      {
        ++unk_81D5AEC;
      }
      goto LABEL_479;
    case 7:
      if ( dword_81C8584 & 8 )
      {
        unk_81D5ACC = 1;
        unk_81D5B20 = 0;
      }
      goto LABEL_479;
  }
  while ( 1 )
  {
    while ( 1 )
    {
      while ( 1 )
      {
        while ( 1 )
        {
          while ( 1 )
          {
            while ( 1 )
            {
              while ( 1 )
              {
                while ( 1 )
                {
                  while ( 1 )
                  {
                    while ( 1 )
                    {
                      while ( 1 )
                      {
                        while ( 1 )
                        {
                          while ( 1 )
                          {
                            while ( 1 )
                            {
                              while ( 1 )
                              {
                                while ( 1 )
                                {
                                  while ( 1 )
                                  {
                                    while ( 1 )
                                    {
                                      while ( 1 )
                                      {
                                        while ( 1 )
                                        {
                                          while ( 1 )
                                          {
                                            while ( 1 )
                                            {
                                              while ( 1 )
                                              {
                                                while ( 1 )
                                                {
                                                  while ( 1 )
                                                  {
                                                    while ( 1 )
                                                    {
                                                      while ( 1 )
                                                      {
                                                        while ( 1 )
                                                        {
                                                          while ( 1 )
                                                          {
                                                            while ( 1 )
                                                            {
                                                              while ( 1 )
                                                              {
                                                                while ( 1 )
                                                                {
                                                                  while ( 1 )
                                                                  {
                                                                    while ( 1 )
                                                                    {
                                                                      while ( 1 )
                                                                      {
                                                                        while ( 1 )
                                                                        {
                                                                          while ( 1 )
                                                                          {
                                                                            while ( 1 )
                                                                            {
                                                                              while ( 1 )
                                                                              {
                                                                                while ( 1 )
                                                                                {
                                                                                  while ( 1 )
                                                                                  {
                                                                                    while ( 1 )
                                                                                    {
                                                                                      while ( 1 )
                                                                                      {
                                                                                        while ( 1 )
                                                                                        {
                                                                                          while ( 1 )
                                                                                          {
                                                                                            while ( 1 )
                                                                                            {
                                                                                              while ( 1 )
                                                                                              {
                                                                                                while ( 1 )
                                                                                                {
                                                                                                  while ( 1 )
                                                                                                  {
                                                                                                    while ( 1 )
                                                                                                    {
                                                                                                      while ( 1 )
                                                                                                      {
                                                                                                        while ( 1 )
                                                                                                        {
                                                                                                          while ( 1 )
                                                                                                          {
                                                                                                            while ( 1 )
                                                                                                            {
                                                                                                              while ( 1 )
                                                                                                              {
                                                                                                                while ( 1 )
                                                                                                                {
                                                                                                                  while ( 1 )
                                                                                                                  {
                                                                                                                    while ( 1 )
                                                                                                                    {
                                                                                                                      while ( 1 )
                                                                                                                      {
                                                                                                                        while ( 1 )
                                                                                                                        {
                                                                                                                          while ( 1 )
                                                                                                                          {
                                                                                                                            while ( 1 )
                                                                                                                            {
                                                                                                                              while ( 1 )
                                                                                                                              {
                                                                                                                                while ( 1 )
                                                                                                                                {
                                                                                                                                  while ( 1 )
                                                                                                                                  {
                                                                                                                                    while ( 1 )
                                                                                                                                    {
                                                                                                                                      while ( 1 )
                                                                                                                                      {
                                                                                                                                        while ( 1 )
                                                                                                                                        {
                                                                                                                                          while ( 1 )
                                                                                                                                          {
                                                                                                                                            while ( 1 )
                                                                                                                                            {
                                                                                                                                              while ( 1 )
                                                                                                                                              {
                                                                                                                                                while ( 1 )
                                                                                                                                                {
                                                                                                                                                  while ( 1 )
                                                                                                                                                  {
                                                                                                                                                    while ( 1 )
                                                                                                                                                    {
                                                                                                                                                      while ( 1 )
                                                                                                                                                      {
                                                                                                                                                        while ( 1 )
                                                                                                                                                        {
                                                                                                                                                          while ( 1 )
                                                                                                                                                          {
                                                                                                                                                            while ( 1 )
                                                                                                                                                            {
                                                                                                                                                              while ( 1 )
                                                                                                                                                              {
                                                                                                                                                                while ( 1 )
                                                                                                                                                                {
                                                                                                                                                                  while ( 1 )
                                                                                                                                                                  {
                                                                                                                                                                    while ( 1 )
                                                                                                                                                                    {
                                                                                                                                                                      while ( 1 )
                                                                                                                                                                      {
                                                                                                                                                                        while ( 1 )
                                                                                                                                                                        {
                                                                                                                                                                          while ( 1 )
                                                                                                                                                                          {
                                                                                                                                                                            while ( 1 )
                                                                                                                                                                            {
                                                                                                                                                                              while ( 1 )
                                                                                                                                                                              {
                                                                                                                                                                                while ( 1 )
                                                                                                                                                                                {
                                                                                                                                                                                  while ( 1 )
                                                                                                                                                                                  {
                                                                                                                                                                                    while ( 1 )
                                                                                                                                                                                    {
                                                                                                                                                                                      while ( 1 )
                                                                                                                                                                                      {
                                                                                                                                                                                        while ( 1 )
                                                                                                                                                                                        {
                                                                                                                                                                                          if ( bExit == 1 )
                                                                                                                                                                                          {
LABEL_479:
                                                                                                                                                                                            if ( unk_81D5ACC )
                                                                                                                                                                                              g_GameFlags |= 4u;
                                                                                                                                                                                            else
                                                                                                                                                                                              g_GameFlags &= 0xFFFFFFFB;
                                                                                                                                                                                            return 1;
                                                                                                                                                                                          }
                                                                                                                                                                                          if ( unk_81D5AC8[unk_81D5AD0] == 60 )
                                                                                                                                                                                            break;
                                                                                                                                                                                          if ( unk_81D5AC8[unk_81D5AD0] == 13 )
                                                                                                                                                                                          {
                                                                                                                                                                                            unk_81D5AD0 += 2;
                                                                                                                                                                                            unk_81D5AD4 = 0;
                                                                                                                                                                                            if ( unk_81D5ACD & 1 )
                                                                                                                                                                                            {
                                                                                                                                                                                              ++unk_81D5AD8;
                                                                                                                                                                                              CheckNewLine();
                                                                                                                                                                                            }
                                                                                                                                                                                          }
                                                                                                                                                                                          else if ( unk_81D5ACD & 0x10 )
                                                                                                                                                                                          {
                                                                                                                                                                                            for ( x = unk_81D5AD0;
                                                                                                                                                                                                  ;
                                                                                                                                                                                                  ++x )
                                                                                                                                                                                            {
                                                                                                                                                                                              v5 = unk_81D5AC8[x] == 60 || unk_81D5AC8[x] == 13 ? 0 : 1;
                                                                                                                                                                                              if ( !v5 )
                                                                                                                                                                                                break;
                                                                                                                                                                                              if ( (unk_81D5AC8[x] & 0x80u) != 0 )
                                                                                                                                                                                                ++x;
                                                                                                                                                                                            }
                                                                                                                                                                                            y = x - unk_81D5AD0;
                                                                                                                                                                                            memcpy(str, &unk_81D5AC8[unk_81D5AD0], x - unk_81D5AD0);
                                                                                                                                                                                            str[y] = 0;
                                                                                                                                                                                            unk_81D5AD4 = x;
                                                                                                                                                                                            v6 = unk_81D5AD8 % 4 + 30;
                                                                                                                                                                                            RGB((int)&r, 0xFFu, 0xFFu, 254);
                                                                                                                                                                                            PutText2(0, 0, str, (const SDL_Color_0 *const )&r, v6);
                                                                                                                                                                                            sprintf((char *)((unk_81D5AD8 % 4 << 6) + 136141632), str);
                                                                                                                                                                                            unk_81D5AD0 += y;
                                                                                                                                                                                            if ( unk_81D5AD4 > 34 )
                                                                                                                                                                                              CheckNewLine();
                                                                                                                                                                                            bExit = 1;
                                                                                                                                                                                          }
                                                                                                                                                                                          else
                                                                                                                                                                                          {
                                                                                                                                                                                            c[0] = unk_81D5AC8[unk_81D5AD0];
                                                                                                                                                                                            if ( c[0] >= 0 )
                                                                                                                                                                                            {
                                                                                                                                                                                              c[1] = 0;
                                                                                                                                                                                            }
                                                                                                                                                                                            else
                                                                                                                                                                                            {
                                                                                                                                                                                              c[1] = unk_81D5AC8[unk_81D5AD0 + 1];
                                                                                                                                                                                              c[2] = 0;
                                                                                                                                                                                            }
                                                                                                                                                                                            if ( c[0] == 61 )
                                                                                                                                                                                            {
                                                                                                                                                                                              Surface2Surface(6 * unk_81D5AD4, 2, &rcSymbol, unk_81D5AD8 % 4 + 30, 26);
                                                                                                                                                                                            }
                                                                                                                                                                                            else
                                                                                                                                                                                            {
                                                                                                                                                                                              v7 = unk_81D5AD8 % 4 + 30;
                                                                                                                                                                                              RGB((int)&v14, 0xFFu, 0xFFu, 254);
                                                                                                                                                                                              PutText2(6 * unk_81D5AD4, 0, c, (const SDL_Color_0 *const )&v14, v7);
                                                                                                                                                                                            }
                                                                                                                                                                                            strcat((char *)((unk_81D5AD8 % 4 << 6) + 136141632), c);
                                                                                                                                                                                            PlaySoundObject(2, 1);
                                                                                                                                                                                            unk_81D5B20 = 0;
                                                                                                                                                                                            if ( c[0] >= 0 )
                                                                                                                                                                                            {
                                                                                                                                                                                              ++unk_81D5AD0;
                                                                                                                                                                                              ++unk_81D5AD4;
                                                                                                                                                                                            }
                                                                                                                                                                                            else
                                                                                                                                                                                            {
                                                                                                                                                                                              unk_81D5AD0 += 2;
                                                                                                                                                                                              unk_81D5AD4 += 2;
                                                                                                                                                                                            }
                                                                                                                                                                                            if ( unk_81D5AD4 > 34 )
                                                                                                                                                                                            {
                                                                                                                                                                                              CheckNewLine();
                                                                                                                                                                                              unk_81D5AD4 = 0;
                                                                                                                                                                                              ++unk_81D5AD8;
                                                                                                                                                                                              CheckNewLine();
                                                                                                                                                                                            }
                                                                                                                                                                                            bExit = 1;
                                                                                                                                                                                          }
                                                                                                                                                                                        }
                                                                                                                                                                                        if ( unk_81D5AC8[unk_81D5AD0 + 1] != 69 || unk_81D5AC8[unk_81D5AD0 + 2] != 78 || unk_81D5AC8[unk_81D5AD0 + 3] != 68 )
                                                                                                                                                                                          break;
                                                                                                                                                                                        unk_81D5ACC = 0;
                                                                                                                                                                                        gMC.cond &= 0xFEu;
                                                                                                                                                                                        g_GameFlags |= 3u;
                                                                                                                                                                                        unk_81D5AFC = 0;
                                                                                                                                                                                        bExit = 1;
                                                                                                                                                                                      }
                                                                                                                                                                                      if ( unk_81D5AC8[unk_81D5AD0 + 1] != 76 || unk_81D5AC8[unk_81D5AD0 + 2] != 73 || unk_81D5AC8[unk_81D5AD0 + 3] != 43 )
                                                                                                                                                                                        break;
                                                                                                                                                                                      x = GetTextScriptNo(unk_81D5AD0 + 4);
                                                                                                                                                                                      AddLifeMyChar(x);
                                                                                                                                                                                      unk_81D5AD0 += 8;
                                                                                                                                                                                    }
                                                                                                                                                                                    if ( unk_81D5AC8[unk_81D5AD0 + 1] != 77 || unk_81D5AC8[unk_81D5AD0 + 2] != 76 || unk_81D5AC8[unk_81D5AD0 + 3] != 43 )
                                                                                                                                                                                      break;
                                                                                                                                                                                    z = GetTextScriptNo(unk_81D5AD0 + 4);
                                                                                                                                                                                    AddMaxLifeMyChar(z);
                                                                                                                                                                                    unk_81D5AD0 += 8;
                                                                                                                                                                                  }
                                                                                                                                                                                  if ( unk_81D5AC8[unk_81D5AD0 + 1] != 65 || unk_81D5AC8[unk_81D5AD0 + 2] != 69 || unk_81D5AC8[unk_81D5AD0 + 3] != 43 )
                                                                                                                                                                                    break;
                                                                                                                                                                                  FullArmsEnergy();
                                                                                                                                                                                  unk_81D5AD0 += 4;
                                                                                                                                                                                }
                                                                                                                                                                                if ( unk_81D5AC8[unk_81D5AD0 + 1] != 73 || unk_81D5AC8[unk_81D5AD0 + 2] != 84 || unk_81D5AC8[unk_81D5AD0 + 3] != 43 )
                                                                                                                                                                                  break;
                                                                                                                                                                                x = GetTextScriptNo(unk_81D5AD0 + 4);
                                                                                                                                                                                PlaySoundObject(38, 1);
                                                                                                                                                                                AddItemData(x);
                                                                                                                                                                                unk_81D5AD0 += 8;
                                                                                                                                                                              }
                                                                                                                                                                              if ( unk_81D5AC8[unk_81D5AD0 + 1] != 73 || unk_81D5AC8[unk_81D5AD0 + 2] != 84 || unk_81D5AC8[unk_81D5AD0 + 3] != 45 )
                                                                                                                                                                                break;
                                                                                                                                                                              z = GetTextScriptNo(unk_81D5AD0 + 4);
                                                                                                                                                                              SubItemData(z);
                                                                                                                                                                              unk_81D5AD0 += 8;
                                                                                                                                                                            }
                                                                                                                                                                            if ( unk_81D5AC8[unk_81D5AD0 + 1] != 69 || unk_81D5AC8[unk_81D5AD0 + 2] != 81 || unk_81D5AC8[unk_81D5AD0 + 3] != 43 )
                                                                                                                                                                              break;
                                                                                                                                                                            z = GetTextScriptNo(unk_81D5AD0 + 4);
                                                                                                                                                                            EquipItem(z, 1);
                                                                                                                                                                            unk_81D5AD0 += 8;
                                                                                                                                                                          }
                                                                                                                                                                          if ( unk_81D5AC8[unk_81D5AD0 + 1] != 69 || unk_81D5AC8[unk_81D5AD0 + 2] != 81 || unk_81D5AC8[unk_81D5AD0 + 3] != 45 )
                                                                                                                                                                            break;
                                                                                                                                                                          z = GetTextScriptNo(unk_81D5AD0 + 4);
                                                                                                                                                                          EquipItem(z, 0);
                                                                                                                                                                          unk_81D5AD0 += 8;
                                                                                                                                                                        }
                                                                                                                                                                        if ( unk_81D5AC8[unk_81D5AD0 + 1] != 65 || unk_81D5AC8[unk_81D5AD0 + 2] != 77 || unk_81D5AC8[unk_81D5AD0 + 3] != 43 )
                                                                                                                                                                          break;
                                                                                                                                                                        w = GetTextScriptNo(unk_81D5AD0 + 4);
                                                                                                                                                                        x = GetTextScriptNo(unk_81D5AD0 + 9);
                                                                                                                                                                        gNumberTextScript[0] = x;
                                                                                                                                                                        gNumberTextScript[1] = z;
                                                                                                                                                                        PlaySoundObject(38, 1);
                                                                                                                                                                        AddArmsData(w, x);
                                                                                                                                                                        unk_81D5AD0 += 13;
                                                                                                                                                                      }
                                                                                                                                                                      if ( unk_81D5AC8[unk_81D5AD0 + 1] != 65 || unk_81D5AC8[unk_81D5AD0 + 2] != 77 || unk_81D5AC8[unk_81D5AD0 + 3] != 45 )
                                                                                                                                                                        break;
                                                                                                                                                                      z = GetTextScriptNo(unk_81D5AD0 + 4);
                                                                                                                                                                      SubArmsData(z);
                                                                                                                                                                      unk_81D5AD0 += 8;
                                                                                                                                                                    }
                                                                                                                                                                    if ( unk_81D5AC8[unk_81D5AD0 + 1] != 90 || unk_81D5AC8[unk_81D5AD0 + 2] != 65 || unk_81D5AC8[unk_81D5AD0 + 3] != 77 )
                                                                                                                                                                      break;
                                                                                                                                                                    ZeroArmsEnergy_All();
                                                                                                                                                                    unk_81D5AD0 += 4;
                                                                                                                                                                  }
                                                                                                                                                                  if ( unk_81D5AC8[unk_81D5AD0 + 1] != 84 || unk_81D5AC8[unk_81D5AD0 + 2] != 65 || unk_81D5AC8[unk_81D5AD0 + 3] != 77 )
                                                                                                                                                                    break;
                                                                                                                                                                  x = GetTextScriptNo(unk_81D5AD0 + 4);
                                                                                                                                                                  y = GetTextScriptNo(unk_81D5AD0 + 9);
                                                                                                                                                                  z = GetTextScriptNo(unk_81D5AD0 + 14);
                                                                                                                                                                  TradeArms(x, y, z);
                                                                                                                                                                  unk_81D5AD0 += 18;
                                                                                                                                                                }
                                                                                                                                                                if ( unk_81D5AC8[unk_81D5AD0 + 1] != 80 || unk_81D5AC8[unk_81D5AD0 + 2] != 83 || unk_81D5AC8[unk_81D5AD0 + 3] != 43 )
                                                                                                                                                                  break;
                                                                                                                                                                x = GetTextScriptNo(unk_81D5AD0 + 4);
                                                                                                                                                                y = GetTextScriptNo(unk_81D5AD0 + 9);
                                                                                                                                                                AddPermitStage(x, y);
                                                                                                                                                                unk_81D5AD0 += 13;
                                                                                                                                                              }
                                                                                                                                                              if ( unk_81D5AC8[unk_81D5AD0 + 1] != 77 || unk_81D5AC8[unk_81D5AD0 + 2] != 80 || unk_81D5AC8[unk_81D5AD0 + 3] != 43 )
                                                                                                                                                                break;
                                                                                                                                                              x = GetTextScriptNo(unk_81D5AD0 + 4);
                                                                                                                                                              SetMapping(x);
                                                                                                                                                              unk_81D5AD0 += 8;
                                                                                                                                                            }
                                                                                                                                                            if ( unk_81D5AC8[unk_81D5AD0 + 1] != 85 || unk_81D5AC8[unk_81D5AD0 + 2] != 78 || unk_81D5AC8[unk_81D5AD0 + 3] != 73 )
                                                                                                                                                              break;
                                                                                                                                                            z = GetTextScriptNo(unk_81D5AD0 + 4);
                                                                                                                                                            ChangeMyUnit(z);
                                                                                                                                                            unk_81D5AD0 += 8;
                                                                                                                                                          }
                                                                                                                                                          if ( unk_81D5AC8[unk_81D5AD0 + 1] != 83 || unk_81D5AC8[unk_81D5AD0 + 2] != 84 || unk_81D5AC8[unk_81D5AD0 + 3] != 67 )
                                                                                                                                                            break;
                                                                                                                                                          SaveTimeCounter();
                                                                                                                                                          unk_81D5AD0 += 4;
                                                                                                                                                        }
                                                                                                                                                        if ( unk_81D5AC8[unk_81D5AD0 + 1] != 84 || unk_81D5AC8[unk_81D5AD0 + 2] != 82 || unk_81D5AC8[unk_81D5AD0 + 3] != 65 )
                                                                                                                                                          break;
                                                                                                                                                        z = GetTextScriptNo(unk_81D5AD0 + 4);
                                                                                                                                                        w = GetTextScriptNo(unk_81D5AD0 + 9);
                                                                                                                                                        x = GetTextScriptNo(unk_81D5AD0 + 14);
                                                                                                                                                        y = GetTextScriptNo(unk_81D5AD0 + 19);
                                                                                                                                                        if ( (unsigned __int8)TransferStage(z, w, x, y) ^ 1 )
                                                                                                                                                          return 0;
                                                                                                                                                      }
                                                                                                                                                      if ( unk_81D5AC8[unk_81D5AD0 + 1] != 77 || unk_81D5AC8[unk_81D5AD0 + 2] != 79 || unk_81D5AC8[unk_81D5AD0 + 3] != 86 )
                                                                                                                                                        break;
                                                                                                                                                      x = GetTextScriptNo(unk_81D5AD0 + 4);
                                                                                                                                                      y = GetTextScriptNo(unk_81D5AD0 + 9);
                                                                                                                                                      SetMyCharPosition(x << 13, y << 13);
                                                                                                                                                      unk_81D5AD0 += 13;
                                                                                                                                                    }
                                                                                                                                                    if ( unk_81D5AC8[unk_81D5AD0 + 1] != 72 || unk_81D5AC8[unk_81D5AD0 + 2] != 77 || unk_81D5AC8[unk_81D5AD0 + 3] != 67 )
                                                                                                                                                      break;
                                                                                                                                                    ShowMyChar(0);
                                                                                                                                                    unk_81D5AD0 += 4;
                                                                                                                                                  }
                                                                                                                                                  if ( unk_81D5AC8[unk_81D5AD0 + 1] != 83 || unk_81D5AC8[unk_81D5AD0 + 2] != 77 || unk_81D5AC8[unk_81D5AD0 + 3] != 67 )
                                                                                                                                                    break;
                                                                                                                                                  ShowMyChar(1);
                                                                                                                                                  unk_81D5AD0 += 4;
                                                                                                                                                }
                                                                                                                                                if ( unk_81D5AC8[unk_81D5AD0 + 1] != 70 || unk_81D5AC8[unk_81D5AD0 + 2] != 76 || unk_81D5AC8[unk_81D5AD0 + 3] != 43 )
                                                                                                                                                  break;
                                                                                                                                                z = GetTextScriptNo(unk_81D5AD0 + 4);
                                                                                                                                                SetNPCFlag(z);
                                                                                                                                                unk_81D5AD0 += 8;
                                                                                                                                              }
                                                                                                                                              if ( unk_81D5AC8[unk_81D5AD0 + 1] != 70 || unk_81D5AC8[unk_81D5AD0 + 2] != 76 || unk_81D5AC8[unk_81D5AD0 + 3] != 45 )
                                                                                                                                                break;
                                                                                                                                              z = GetTextScriptNo(unk_81D5AD0 + 4);
                                                                                                                                              CutNPCFlag(z);
                                                                                                                                              unk_81D5AD0 += 8;
                                                                                                                                            }
                                                                                                                                            if ( unk_81D5AC8[unk_81D5AD0 + 1] != 83 || unk_81D5AC8[unk_81D5AD0 + 2] != 75 || unk_81D5AC8[unk_81D5AD0 + 3] != 43 )
                                                                                                                                              break;
                                                                                                                                            z = GetTextScriptNo(unk_81D5AD0 + 4);
                                                                                                                                            SetSkipFlag(z);
                                                                                                                                            unk_81D5AD0 += 8;
                                                                                                                                          }
                                                                                                                                          if ( unk_81D5AC8[unk_81D5AD0 + 1] != 83 || unk_81D5AC8[unk_81D5AD0 + 2] != 75 || unk_81D5AC8[unk_81D5AD0 + 3] != 45 )
                                                                                                                                            break;
                                                                                                                                          z = GetTextScriptNo(unk_81D5AD0 + 4);
                                                                                                                                          CutSkipFlag(z);
                                                                                                                                          unk_81D5AD0 += 8;
                                                                                                                                        }
                                                                                                                                        if ( unk_81D5AC8[unk_81D5AD0 + 1] != 75 || unk_81D5AC8[unk_81D5AD0 + 2] != 69 || unk_81D5AC8[unk_81D5AD0 + 3] != 89 )
                                                                                                                                          break;
                                                                                                                                        g_GameFlags &= 0xFFFFFFFD;
                                                                                                                                        g_GameFlags |= 1u;
                                                                                                                                        unk_81C858C = 0;
                                                                                                                                        unk_81C8610 = 0;
                                                                                                                                        unk_81D5AD0 += 4;
                                                                                                                                      }
                                                                                                                                      if ( unk_81D5AC8[unk_81D5AD0 + 1] != 80 || unk_81D5AC8[unk_81D5AD0 + 2] != 82 || unk_81D5AC8[unk_81D5AD0 + 3] != 73 )
                                                                                                                                        break;
                                                                                                                                      g_GameFlags &= 0xFFFFFFFC;
                                                                                                                                      unk_81C8610 = 0;
                                                                                                                                      unk_81D5AD0 += 4;
                                                                                                                                    }
                                                                                                                                    if ( unk_81D5AC8[unk_81D5AD0 + 1] != 70 || unk_81D5AC8[unk_81D5AD0 + 2] != 82 || unk_81D5AC8[unk_81D5AD0 + 3] != 69 )
                                                                                                                                      break;
                                                                                                                                    g_GameFlags |= 3u;
                                                                                                                                    unk_81D5AD0 += 4;
                                                                                                                                  }
                                                                                                                                  if ( unk_81D5AC8[unk_81D5AD0 + 1] != 78 || unk_81D5AC8[unk_81D5AD0 + 2] != 79 || unk_81D5AC8[unk_81D5AD0 + 3] != 68 )
                                                                                                                                    break;
                                                                                                                                  unk_81D5ACC = 2;
                                                                                                                                  unk_81D5AD0 += 4;
                                                                                                                                  bExit = 1;
                                                                                                                                }
                                                                                                                                if ( unk_81D5AC8[unk_81D5AD0 + 1] != 67 || unk_81D5AC8[unk_81D5AD0 + 2] != 76 || unk_81D5AC8[unk_81D5AD0 + 3] != 82 )
                                                                                                                                  break;
                                                                                                                                ClearTextLine();
                                                                                                                                unk_81D5AD0 += 4;
                                                                                                                              }
                                                                                                                              if ( unk_81D5AC8[unk_81D5AD0 + 1] != 77 || unk_81D5AC8[unk_81D5AD0 + 2] != 83 || unk_81D5AC8[unk_81D5AD0 + 3] != 71 )
                                                                                                                                break;
                                                                                                                              ClearTextLine();
                                                                                                                              unk_81D5ACD |= 3u;
                                                                                                                              unk_81D5ACD &= 0xCFu;
                                                                                                                              if ( unk_81D5ACD & 0x40 )
                                                                                                                                unk_81D5ACD |= 0x10u;
                                                                                                                              unk_81D5AD0 += 4;
                                                                                                                              bExit = 1;
                                                                                                                            }
                                                                                                                            if ( unk_81D5AC8[unk_81D5AD0 + 1] != 77 || unk_81D5AC8[unk_81D5AD0 + 2] != 83 || unk_81D5AC8[unk_81D5AD0 + 3] != 50 )
                                                                                                                              break;
                                                                                                                            ClearTextLine();
                                                                                                                            unk_81D5ACD &= 0xEDu;
                                                                                                                            unk_81D5ACD |= 0x21u;
                                                                                                                            if ( unk_81D5ACD & 0x40 )
                                                                                                                              unk_81D5ACD |= 0x10u;
                                                                                                                            unk_81D5AFC = 0;
                                                                                                                            unk_81D5AD0 += 4;
                                                                                                                            bExit = 1;
                                                                                                                          }
                                                                                                                          if ( unk_81D5AC8[unk_81D5AD0 + 1] != 77 || unk_81D5AC8[unk_81D5AD0 + 2] != 83 || unk_81D5AC8[unk_81D5AD0 + 3] != 51 )
                                                                                                                            break;
                                                                                                                          ClearTextLine();
                                                                                                                          unk_81D5ACD &= 0xEFu;
                                                                                                                          unk_81D5ACD |= 0x23u;
                                                                                                                          if ( unk_81D5ACD & 0x40 )
                                                                                                                            unk_81D5ACD |= 0x10u;
                                                                                                                          unk_81D5AD0 += 4;
                                                                                                                          bExit = 1;
                                                                                                                        }
                                                                                                                        if ( unk_81D5AC8[unk_81D5AD0 + 1] != 87 || unk_81D5AC8[unk_81D5AD0 + 2] != 65 || unk_81D5AC8[unk_81D5AD0 + 3] != 73 )
                                                                                                                          break;
                                                                                                                        unk_81D5ACC = 4;
                                                                                                                        unk_81D5AF0 = GetTextScriptNo(unk_81D5AD0 + 4);
                                                                                                                        unk_81D5AD0 += 8;
                                                                                                                        bExit = 1;
                                                                                                                      }
                                                                                                                      if ( unk_81D5AC8[unk_81D5AD0 + 1] != 87 || unk_81D5AC8[unk_81D5AD0 + 2] != 65 || unk_81D5AC8[unk_81D5AD0 + 3] != 83 )
                                                                                                                        break;
                                                                                                                      unk_81D5ACC = 7;
                                                                                                                      unk_81D5AD0 += 4;
                                                                                                                      bExit = 1;
                                                                                                                    }
                                                                                                                    if ( unk_81D5AC8[unk_81D5AD0 + 1] != 84 || unk_81D5AC8[unk_81D5AD0 + 2] != 85 || unk_81D5AC8[unk_81D5AD0 + 3] != 82 )
                                                                                                                      break;
                                                                                                                    unk_81D5AD0 += 4;
                                                                                                                    unk_81D5ACD |= 0x10u;
                                                                                                                  }
                                                                                                                  if ( unk_81D5AC8[unk_81D5AD0 + 1] != 83 || unk_81D5AC8[unk_81D5AD0 + 2] != 65 || unk_81D5AC8[unk_81D5AD0 + 3] != 84 )
                                                                                                                    break;
                                                                                                                  unk_81D5AD0 += 4;
                                                                                                                  unk_81D5ACD |= 0x40u;
                                                                                                                }
                                                                                                                if ( unk_81D5AC8[unk_81D5AD0 + 1] != 67 || unk_81D5AC8[unk_81D5AD0 + 2] != 65 || unk_81D5AC8[unk_81D5AD0 + 3] != 84 )
                                                                                                                  break;
                                                                                                                unk_81D5AD0 += 4;
                                                                                                                unk_81D5ACD |= 0x40u;
                                                                                                              }
                                                                                                              if ( unk_81D5AC8[unk_81D5AD0 + 1] != 67 || unk_81D5AC8[unk_81D5AD0 + 2] != 76 || unk_81D5AC8[unk_81D5AD0 + 3] != 79 )
                                                                                                                break;
                                                                                                              unk_81D5ACD &= 0xCCu;
                                                                                                              unk_81D5AD0 += 4;
                                                                                                            }
                                                                                                            if ( unk_81D5AC8[unk_81D5AD0 + 1] != 69 || unk_81D5AC8[unk_81D5AD0 + 2] != 86 || unk_81D5AC8[unk_81D5AD0 + 3] != 69 )
                                                                                                              break;
                                                                                                            z = GetTextScriptNo(unk_81D5AD0 + 4);
                                                                                                            JumpTextScript(z);
                                                                                                          }
                                                                                                          if ( unk_81D5AC8[unk_81D5AD0 + 1] != 89 || unk_81D5AC8[unk_81D5AD0 + 2] != 78 || unk_81D5AC8[unk_81D5AD0 + 3] != 74 )
                                                                                                            break;
                                                                                                          no = GetTextScriptNo(unk_81D5AD0 + 4);
                                                                                                          unk_81D5AD0 += 8;
                                                                                                          unk_81D5ACC = 6;
                                                                                                          PlaySoundObject(5, 1);
                                                                                                          unk_81D5AEC = 0;
                                                                                                          unk_81D5AF8 = 0;
                                                                                                          bExit = 1;
                                                                                                        }
                                                                                                        if ( unk_81D5AC8[unk_81D5AD0 + 1] != 70 || unk_81D5AC8[unk_81D5AD0 + 2] != 76 || unk_81D5AC8[unk_81D5AD0 + 3] != 74 )
                                                                                                          break;
                                                                                                        x = GetTextScriptNo(unk_81D5AD0 + 4);
                                                                                                        z = GetTextScriptNo(unk_81D5AD0 + 9);
                                                                                                        if ( (unsigned __int8)GetNPCFlag(x) )
                                                                                                          JumpTextScript(z);
                                                                                                        else
                                                                                                          unk_81D5AD0 += 13;
                                                                                                      }
                                                                                                      if ( unk_81D5AC8[unk_81D5AD0 + 1] != 83 || unk_81D5AC8[unk_81D5AD0 + 2] != 75 || unk_81D5AC8[unk_81D5AD0 + 3] != 74 )
                                                                                                        break;
                                                                                                      x = GetTextScriptNo(unk_81D5AD0 + 4);
                                                                                                      z = GetTextScriptNo(unk_81D5AD0 + 9);
                                                                                                      if ( (unsigned __int8)GetSkipFlag(x) )
                                                                                                        JumpTextScript(z);
                                                                                                      else
                                                                                                        unk_81D5AD0 += 13;
                                                                                                    }
                                                                                                    if ( unk_81D5AC8[unk_81D5AD0 + 1] != 73 || unk_81D5AC8[unk_81D5AD0 + 2] != 84 || unk_81D5AC8[unk_81D5AD0 + 3] != 74 )
                                                                                                      break;
                                                                                                    x = GetTextScriptNo(unk_81D5AD0 + 4);
                                                                                                    z = GetTextScriptNo(unk_81D5AD0 + 9);
                                                                                                    if ( (unsigned __int8)CheckItem(x) )
                                                                                                      JumpTextScript(z);
                                                                                                    else
                                                                                                      unk_81D5AD0 += 13;
                                                                                                  }
                                                                                                  if ( unk_81D5AC8[unk_81D5AD0 + 1] != 65 || unk_81D5AC8[unk_81D5AD0 + 2] != 77 || unk_81D5AC8[unk_81D5AD0 + 3] != 74 )
                                                                                                    break;
                                                                                                  x = GetTextScriptNo(unk_81D5AD0 + 4);
                                                                                                  z = GetTextScriptNo(unk_81D5AD0 + 9);
                                                                                                  if ( (unsigned __int8)CheckArms(x) )
                                                                                                    JumpTextScript(z);
                                                                                                  else
                                                                                                    unk_81D5AD0 += 13;
                                                                                                }
                                                                                                if ( unk_81D5AC8[unk_81D5AD0 + 1] != 85 || unk_81D5AC8[unk_81D5AD0 + 2] != 78 || unk_81D5AC8[unk_81D5AD0 + 3] != 74 )
                                                                                                  break;
                                                                                                x = GetTextScriptNo(unk_81D5AD0 + 4);
                                                                                                z = GetTextScriptNo(unk_81D5AD0 + 9);
                                                                                                if ( GetUnitMyChar() == x )
                                                                                                  JumpTextScript(z);
                                                                                                else
                                                                                                  unk_81D5AD0 += 13;
                                                                                              }
                                                                                              if ( unk_81D5AC8[unk_81D5AD0 + 1] != 69
                                                                                                || unk_81D5AC8[unk_81D5AD0 + 2] != 67
                                                                                                || unk_81D5AC8[unk_81D5AD0 + 3] != 74 )
                                                                                              {
                                                                                                break;
                                                                                              }
                                                                                              x = GetTextScriptNo(unk_81D5AD0 + 4);
                                                                                              z = GetTextScriptNo(unk_81D5AD0 + 9);
                                                                                              if ( (unsigned __int8)GetNpCharAlive(x) )
                                                                                                JumpTextScript(z);
                                                                                              else
                                                                                                unk_81D5AD0 += 13;
                                                                                            }
                                                                                            if ( unk_81D5AC8[unk_81D5AD0 + 1] != 78
                                                                                              || unk_81D5AC8[unk_81D5AD0 + 2] != 67
                                                                                              || unk_81D5AC8[unk_81D5AD0 + 3] != 74 )
                                                                                            {
                                                                                              break;
                                                                                            }
                                                                                            x = GetTextScriptNo(unk_81D5AD0 + 4);
                                                                                            z = GetTextScriptNo(unk_81D5AD0 + 9);
                                                                                            if ( (unsigned __int8)IsNpCharCode(x) )
                                                                                              JumpTextScript(z);
                                                                                            else
                                                                                              unk_81D5AD0 += 13;
                                                                                          }
                                                                                          if ( unk_81D5AC8[unk_81D5AD0 + 1] != 77
                                                                                            || unk_81D5AC8[unk_81D5AD0 + 2] != 80
                                                                                            || unk_81D5AC8[unk_81D5AD0 + 3] != 74 )
                                                                                          {
                                                                                            break;
                                                                                          }
                                                                                          x = GetTextScriptNo(unk_81D5AD0 + 4);
                                                                                          if ( (unsigned __int8)IsMapping() )
                                                                                            JumpTextScript(x);
                                                                                          else
                                                                                            unk_81D5AD0 += 8;
                                                                                        }
                                                                                        if ( unk_81D5AC8[unk_81D5AD0 + 1] != 83
                                                                                          || unk_81D5AC8[unk_81D5AD0 + 2] != 83
                                                                                          || unk_81D5AC8[unk_81D5AD0 + 3] != 83 )
                                                                                        {
                                                                                          break;
                                                                                        }
                                                                                        x = GetTextScriptNo(unk_81D5AD0 + 4);
                                                                                        SetNoise(1, x);
                                                                                        unk_81D5AD0 += 8;
                                                                                      }
                                                                                      if ( unk_81D5AC8[unk_81D5AD0 + 1] != 67
                                                                                        || unk_81D5AC8[unk_81D5AD0 + 2] != 83
                                                                                        || unk_81D5AC8[unk_81D5AD0 + 3] != 83 )
                                                                                      {
                                                                                        break;
                                                                                      }
                                                                                      CutNoise();
                                                                                      unk_81D5AD0 += 4;
                                                                                    }
                                                                                    if ( unk_81D5AC8[unk_81D5AD0 + 1] != 83
                                                                                      || unk_81D5AC8[unk_81D5AD0 + 2] != 80
                                                                                      || unk_81D5AC8[unk_81D5AD0 + 3] != 83 )
                                                                                    {
                                                                                      break;
                                                                                    }
                                                                                    SetNoise(2, x);
                                                                                    unk_81D5AD0 += 4;
                                                                                  }
                                                                                  if ( unk_81D5AC8[unk_81D5AD0 + 1] != 67
                                                                                    || unk_81D5AC8[unk_81D5AD0 + 2] != 80
                                                                                    || unk_81D5AC8[unk_81D5AD0 + 3] != 83 )
                                                                                  {
                                                                                    break;
                                                                                  }
                                                                                  CutNoise();
                                                                                  unk_81D5AD0 += 4;
                                                                                }
                                                                                if ( unk_81D5AC8[unk_81D5AD0 + 1] != 81
                                                                                  || unk_81D5AC8[unk_81D5AD0 + 2] != 85
                                                                                  || unk_81D5AC8[unk_81D5AD0 + 3] != 65 )
                                                                                {
                                                                                  break;
                                                                                }
                                                                                z = GetTextScriptNo(unk_81D5AD0 + 4);
                                                                                SetQuake(z);
                                                                                unk_81D5AD0 += 8;
                                                                              }
                                                                              if ( unk_81D5AC8[unk_81D5AD0 + 1] != 70
                                                                                || unk_81D5AC8[unk_81D5AD0 + 2] != 76
                                                                                || unk_81D5AC8[unk_81D5AD0 + 3] != 65 )
                                                                              {
                                                                                break;
                                                                              }
                                                                              SetFlash(0, 0, 2);
                                                                              unk_81D5AD0 += 4;
                                                                            }
                                                                            if ( unk_81D5AC8[unk_81D5AD0 + 1] != 70
                                                                              || unk_81D5AC8[unk_81D5AD0 + 2] != 65
                                                                              || unk_81D5AC8[unk_81D5AD0 + 3] != 73 )
                                                                            {
                                                                              break;
                                                                            }
                                                                            z = GetTextScriptNo(unk_81D5AD0 + 4);
                                                                            StartFadeIn(z);
                                                                            unk_81D5ACC = 5;
                                                                            unk_81D5AD0 += 8;
                                                                            bExit = 1;
                                                                          }
                                                                          if ( unk_81D5AC8[unk_81D5AD0 + 1] != 70
                                                                            || unk_81D5AC8[unk_81D5AD0 + 2] != 65
                                                                            || unk_81D5AC8[unk_81D5AD0 + 3] != 79 )
                                                                          {
                                                                            break;
                                                                          }
                                                                          z = GetTextScriptNo(unk_81D5AD0 + 4);
                                                                          StartFadeOut(z);
                                                                          unk_81D5ACC = 5;
                                                                          unk_81D5AD0 += 8;
                                                                          bExit = 1;
                                                                        }
                                                                        if ( unk_81D5AC8[unk_81D5AD0 + 1] != 77
                                                                          || unk_81D5AC8[unk_81D5AD0 + 2] != 78
                                                                          || unk_81D5AC8[unk_81D5AD0 + 3] != 65 )
                                                                        {
                                                                          break;
                                                                        }
                                                                        StartMapName();
                                                                        unk_81D5AD0 += 4;
                                                                      }
                                                                      if ( unk_81D5AC8[unk_81D5AD0 + 1] != 70
                                                                        || unk_81D5AC8[unk_81D5AD0 + 2] != 79
                                                                        || unk_81D5AC8[unk_81D5AD0 + 3] != 77 )
                                                                      {
                                                                        break;
                                                                      }
                                                                      z = GetTextScriptNo(unk_81D5AD0 + 4);
                                                                      SetFrameTargetMyChar(z);
                                                                      unk_81D5AD0 += 8;
                                                                    }
                                                                    if ( unk_81D5AC8[unk_81D5AD0 + 1] != 70
                                                                      || unk_81D5AC8[unk_81D5AD0 + 2] != 79
                                                                      || unk_81D5AC8[unk_81D5AD0 + 3] != 78 )
                                                                    {
                                                                      break;
                                                                    }
                                                                    x = GetTextScriptNo(unk_81D5AD0 + 4);
                                                                    y = GetTextScriptNo(unk_81D5AD0 + 9);
                                                                    SetFrameTargetNpChar(x, y);
                                                                    unk_81D5AD0 += 13;
                                                                  }
                                                                  if ( unk_81D5AC8[unk_81D5AD0 + 1] != 70
                                                                    || unk_81D5AC8[unk_81D5AD0 + 2] != 79
                                                                    || unk_81D5AC8[unk_81D5AD0 + 3] != 66 )
                                                                  {
                                                                    break;
                                                                  }
                                                                  x = GetTextScriptNo(unk_81D5AD0 + 4);
                                                                  y = GetTextScriptNo(unk_81D5AD0 + 9);
                                                                  SetFrameTargetBoss(x, y);
                                                                  unk_81D5AD0 += 13;
                                                                }
                                                                if ( unk_81D5AC8[unk_81D5AD0 + 1] != 83
                                                                  || unk_81D5AC8[unk_81D5AD0 + 2] != 79
                                                                  || unk_81D5AC8[unk_81D5AD0 + 3] != 85 )
                                                                {
                                                                  break;
                                                                }
                                                                z = GetTextScriptNo(unk_81D5AD0 + 4);
                                                                PlaySoundObject(z, 1);
                                                                unk_81D5AD0 += 8;
                                                              }
                                                              if ( unk_81D5AC8[unk_81D5AD0 + 1] != 67
                                                                || unk_81D5AC8[unk_81D5AD0 + 2] != 77
                                                                || unk_81D5AC8[unk_81D5AD0 + 3] != 85 )
                                                              {
                                                                break;
                                                              }
                                                              z = GetTextScriptNo(unk_81D5AD0 + 4);
                                                              ChangeMusic(z);
                                                              unk_81D5AD0 += 8;
                                                            }
                                                            if ( unk_81D5AC8[unk_81D5AD0 + 1] != 70
                                                              || unk_81D5AC8[unk_81D5AD0 + 2] != 77
                                                              || unk_81D5AC8[unk_81D5AD0 + 3] != 85 )
                                                            {
                                                              break;
                                                            }
                                                            SetOrganyaFadeout();
                                                            unk_81D5AD0 += 4;
                                                          }
                                                          if ( unk_81D5AC8[unk_81D5AD0 + 1] != 82
                                                            || unk_81D5AC8[unk_81D5AD0 + 2] != 77
                                                            || unk_81D5AC8[unk_81D5AD0 + 3] != 85 )
                                                          {
                                                            break;
                                                          }
                                                          ReCallMusic();
                                                          unk_81D5AD0 += 4;
                                                        }
                                                        if ( unk_81D5AC8[unk_81D5AD0 + 1] != 77
                                                          || unk_81D5AC8[unk_81D5AD0 + 2] != 76
                                                          || unk_81D5AC8[unk_81D5AD0 + 3] != 80 )
                                                        {
                                                          break;
                                                        }
                                                        unk_81D5AD0 += 4;
                                                        bExit = 1;
                                                        v1 = MiniMapLoop();
                                                        if ( !v1 )
                                                          return 0;
                                                        if ( v1 == 2 )
                                                          return 2;
                                                      }
                                                      if ( unk_81D5AC8[unk_81D5AD0 + 1] != 83
                                                        || unk_81D5AC8[unk_81D5AD0 + 2] != 76
                                                        || unk_81D5AC8[unk_81D5AD0 + 3] != 80 )
                                                      {
                                                        break;
                                                      }
                                                      bExit = 1;
                                                      v2 = StageSelectLoop(&z);
                                                      if ( !v2 )
                                                        return 0;
                                                      if ( v2 == 2 )
                                                        return 2;
                                                      JumpTextScript(z);
                                                      g_GameFlags &= 0xFFFFFFFC;
                                                    }
                                                    if ( unk_81D5AC8[unk_81D5AD0 + 1] != 68
                                                      || unk_81D5AC8[unk_81D5AD0 + 2] != 78
                                                      || unk_81D5AC8[unk_81D5AD0 + 3] != 80 )
                                                    {
                                                      break;
                                                    }
                                                    z = GetTextScriptNo(unk_81D5AD0 + 4);
                                                    DeleteNpCharEvent(z);
                                                    unk_81D5AD0 += 8;
                                                  }
                                                  if ( unk_81D5AC8[unk_81D5AD0 + 1] != 68
                                                    || unk_81D5AC8[unk_81D5AD0 + 2] != 78
                                                    || unk_81D5AC8[unk_81D5AD0 + 3] != 65 )
                                                  {
                                                    break;
                                                  }
                                                  z = GetTextScriptNo(unk_81D5AD0 + 4);
                                                  DeleteNpCharCode(z, 1);
                                                  unk_81D5AD0 += 8;
                                                }
                                                if ( unk_81D5AC8[unk_81D5AD0 + 1] != 66
                                                  || unk_81D5AC8[unk_81D5AD0 + 2] != 79
                                                  || unk_81D5AC8[unk_81D5AD0 + 3] != 65 )
                                                {
                                                  break;
                                                }
                                                z = GetTextScriptNo(unk_81D5AD0 + 4);
                                                SetBossCharActNo(z);
                                                unk_81D5AD0 += 8;
                                              }
                                              if ( unk_81D5AC8[unk_81D5AD0 + 1] != 67
                                                || unk_81D5AC8[unk_81D5AD0 + 2] != 78
                                                || unk_81D5AC8[unk_81D5AD0 + 3] != 80 )
                                              {
                                                break;
                                              }
                                              x = GetTextScriptNo(unk_81D5AD0 + 4);
                                              y = GetTextScriptNo(unk_81D5AD0 + 9);
                                              z = GetTextScriptNo(unk_81D5AD0 + 14);
                                              ChangeNpCharByEvent(x, y, z);
                                              unk_81D5AD0 += 18;
                                            }
                                            if ( unk_81D5AC8[unk_81D5AD0 + 1] != 65
                                              || unk_81D5AC8[unk_81D5AD0 + 2] != 78
                                              || unk_81D5AC8[unk_81D5AD0 + 3] != 80 )
                                            {
                                              break;
                                            }
                                            x = GetTextScriptNo(unk_81D5AD0 + 4);
                                            y = GetTextScriptNo(unk_81D5AD0 + 9);
                                            z = GetTextScriptNo(unk_81D5AD0 + 14);
                                            SetNpCharActionNo(x, y, z);
                                            unk_81D5AD0 += 18;
                                          }
                                          if ( unk_81D5AC8[unk_81D5AD0 + 1] != 73
                                            || unk_81D5AC8[unk_81D5AD0 + 2] != 78
                                            || unk_81D5AC8[unk_81D5AD0 + 3] != 80 )
                                          {
                                            break;
                                          }
                                          x = GetTextScriptNo(unk_81D5AD0 + 4);
                                          y = GetTextScriptNo(unk_81D5AD0 + 9);
                                          z = GetTextScriptNo(unk_81D5AD0 + 14);
                                          ChangeCheckableNpCharByEvent(x, y, z);
                                          unk_81D5AD0 += 18;
                                        }
                                        if ( unk_81D5AC8[unk_81D5AD0 + 1] != 83
                                          || unk_81D5AC8[unk_81D5AD0 + 2] != 78
                                          || unk_81D5AC8[unk_81D5AD0 + 3] != 80 )
                                        {
                                          break;
                                        }
                                        w = GetTextScriptNo(unk_81D5AD0 + 4);
                                        x = GetTextScriptNo(unk_81D5AD0 + 9);
                                        y = GetTextScriptNo(unk_81D5AD0 + 14);
                                        z = GetTextScriptNo(unk_81D5AD0 + 19);
                                        SetNpChar(w, x << 13, y << 13, 0, 0, z, 0, 256);
                                        unk_81D5AD0 += 23;
                                      }
                                      if ( unk_81D5AC8[unk_81D5AD0 + 1] != 77
                                        || unk_81D5AC8[unk_81D5AD0 + 2] != 78
                                        || unk_81D5AC8[unk_81D5AD0 + 3] != 80 )
                                      {
                                        break;
                                      }
                                      w = GetTextScriptNo(unk_81D5AD0 + 4);
                                      x = GetTextScriptNo(unk_81D5AD0 + 9);
                                      y = GetTextScriptNo(unk_81D5AD0 + 14);
                                      z = GetTextScriptNo(unk_81D5AD0 + 19);
                                      MoveNpChar(w, x << 13, y << 13, z);
                                      unk_81D5AD0 += 23;
                                    }
                                    if ( unk_81D5AC8[unk_81D5AD0 + 1] != 83
                                      || unk_81D5AC8[unk_81D5AD0 + 2] != 77
                                      || unk_81D5AC8[unk_81D5AD0 + 3] != 80 )
                                    {
                                      break;
                                    }
                                    x = GetTextScriptNo(unk_81D5AD0 + 4);
                                    y = GetTextScriptNo(unk_81D5AD0 + 9);
                                    ShiftMapParts(x, y);
                                    unk_81D5AD0 += 13;
                                  }
                                  if ( unk_81D5AC8[unk_81D5AD0 + 1] != 67
                                    || unk_81D5AC8[unk_81D5AD0 + 2] != 77
                                    || unk_81D5AC8[unk_81D5AD0 + 3] != 80 )
                                  {
                                    break;
                                  }
                                  x = GetTextScriptNo(unk_81D5AD0 + 4);
                                  y = GetTextScriptNo(unk_81D5AD0 + 9);
                                  z = GetTextScriptNo(unk_81D5AD0 + 14);
                                  ChangeMapParts(x, y, z);
                                  unk_81D5AD0 += 18;
                                }
                                if ( unk_81D5AC8[unk_81D5AD0 + 1] != 66
                                  || unk_81D5AC8[unk_81D5AD0 + 2] != 83
                                  || unk_81D5AC8[unk_81D5AD0 + 3] != 76 )
                                {
                                  break;
                                }
                                z = GetTextScriptNo(unk_81D5AD0 + 4);
                                if ( z )
                                  StartBossLife(z);
                                else
                                  StartBossLife2();
                                unk_81D5AD0 += 8;
                              }
                              if ( unk_81D5AC8[unk_81D5AD0 + 1] != 77
                                || unk_81D5AC8[unk_81D5AD0 + 2] != 89
                                || unk_81D5AC8[unk_81D5AD0 + 3] != 68 )
                              {
                                break;
                              }
                              z = GetTextScriptNo(unk_81D5AD0 + 4);
                              SetMyCharDirect(z);
                              unk_81D5AD0 += 8;
                            }
                            if ( unk_81D5AC8[unk_81D5AD0 + 1] != 77
                              || unk_81D5AC8[unk_81D5AD0 + 2] != 89
                              || unk_81D5AC8[unk_81D5AD0 + 3] != 66 )
                            {
                              break;
                            }
                            z = GetTextScriptNo(unk_81D5AD0 + 4);
                            BackStepMyChar(z);
                            unk_81D5AD0 += 8;
                          }
                          if ( unk_81D5AC8[unk_81D5AD0 + 1] != 77
                            || unk_81D5AC8[unk_81D5AD0 + 2] != 77
                            || unk_81D5AC8[unk_81D5AD0 + 3] != 48 )
                          {
                            break;
                          }
                          ZeroMyCharXMove();
                          unk_81D5AD0 += 4;
                        }
                        if ( unk_81D5AC8[unk_81D5AD0 + 1] != 73
                          || unk_81D5AC8[unk_81D5AD0 + 2] != 78
                          || unk_81D5AC8[unk_81D5AD0 + 3] != 73 )
                        {
                          break;
                        }
                        InitializeGame();
                        unk_81D5AD0 += 4;
                      }
                      if ( unk_81D5AC8[unk_81D5AD0 + 1] != 83
                        || unk_81D5AC8[unk_81D5AD0 + 2] != 86
                        || unk_81D5AC8[unk_81D5AD0 + 3] != 80 )
                      {
                        break;
                      }
                      SaveProfile(0);
                      unk_81D5AD0 += 4;
                    }
                    if ( unk_81D5AC8[unk_81D5AD0 + 1] != 76
                      || unk_81D5AC8[unk_81D5AD0 + 2] != 68
                      || unk_81D5AC8[unk_81D5AD0 + 3] != 80 )
                    {
                      break;
                    }
                    if ( (unsigned __int8)LoadProfile(0) ^ 1 )
                      InitializeGame();
                  }
                  if ( unk_81D5AC8[unk_81D5AD0 + 1] != 70
                    || unk_81D5AC8[unk_81D5AD0 + 2] != 65
                    || unk_81D5AC8[unk_81D5AD0 + 3] != 67 )
                  {
                    break;
                  }
                  z = GetTextScriptNo(unk_81D5AD0 + 4);
                  if ( unk_81D5AFC != (char)z )
                  {
                    unk_81D5AFC = (char)z;
                    unk_81D5B00 = 2048;
                  }
                  unk_81D5AD0 += 8;
                }
                if ( unk_81D5AC8[unk_81D5AD0 + 1] != 70
                  || unk_81D5AC8[unk_81D5AD0 + 2] != 65
                  || unk_81D5AC8[unk_81D5AD0 + 3] != 67 )
                {
                  break;
                }
                z = GetTextScriptNo(unk_81D5AD0 + 4);
                if ( unk_81D5AFC != (char)z )
                {
                  unk_81D5AFC = (char)z;
                  unk_81D5B00 = 2048;
                }
                unk_81D5AD0 += 8;
              }
              if ( unk_81D5AC8[unk_81D5AD0 + 1] != 71
                || unk_81D5AC8[unk_81D5AD0 + 2] != 73
                || unk_81D5AC8[unk_81D5AD0 + 3] != 84 )
              {
                break;
              }
              z = GetTextScriptNo(unk_81D5AD0 + 4);
              dword_81D5B04 = z;
              dword_81D5B08 = 128;
              unk_81D5AD0 += 8;
            }
            if ( unk_81D5AC8[unk_81D5AD0 + 1] != 78
              || unk_81D5AC8[unk_81D5AD0 + 2] != 85
              || unk_81D5AC8[unk_81D5AD0 + 3] != 77 )
            {
              break;
            }
            z = GetTextScriptNo(unk_81D5AD0 + 4);
            SetNumberTextScript(z);
            unk_81D5AD0 += 8;
          }
          if ( unk_81D5AC8[unk_81D5AD0 + 1] != 67
            || unk_81D5AC8[unk_81D5AD0 + 2] != 82
            || unk_81D5AC8[unk_81D5AD0 + 3] != 69 )
          {
            break;
          }
          g_GameFlags |= 8u;
          StartCreditScript();
          unk_81D5AD0 += 4;
        }
        if ( unk_81D5AC8[unk_81D5AD0 + 1] != 83
          || unk_81D5AC8[unk_81D5AD0 + 2] != 73
          || unk_81D5AC8[unk_81D5AD0 + 3] != 76 )
        {
          break;
        }
        z = GetTextScriptNo(unk_81D5AD0 + 4);
        SetCreditIllust(z);
        unk_81D5AD0 += 8;
      }
      if ( unk_81D5AC8[unk_81D5AD0 + 1] != 67
        || unk_81D5AC8[unk_81D5AD0 + 2] != 73
        || unk_81D5AC8[unk_81D5AD0 + 3] != 76 )
      {
        break;
      }
      CutCreditIllust();
      unk_81D5AD0 += 4;
    }
    if ( unk_81D5AC8[unk_81D5AD0 + 1] != 88 || unk_81D5AC8[unk_81D5AD0 + 2] != 88 || unk_81D5AC8[unk_81D5AD0 + 3] != 49 )
      break;
    bExit = 1;
    v3 = GetTextScriptNo(unk_81D5AD0 + 4);
    z = v3;
    v4 = Scene_DownIsland(gscreen, v3);
    if ( !v4 )
      return 0;
    if ( v4 == 2 )
      return 2;
    unk_81D5AD0 += 8;
  }
  if ( unk_81D5AC8[unk_81D5AD0 + 1] == 69 && unk_81D5AC8[unk_81D5AD0 + 2] == 83 && unk_81D5AC8[unk_81D5AD0 + 3] == 67 )
    return 2;
  sprintf(
    str_0,
    "\x95s\x96\xBE\x82̃R\x81[\x83h:<%c%c%c",
    (char)unk_81D5AC8[unk_81D5AD0 + 1],
    (char)unk_81D5AC8[unk_81D5AD0 + 2],
    (char)unk_81D5AC8[unk_81D5AD0 + 3]);
  return 0;
}

void RestoreTextScript()
{
  int v0;
  Uint8 r;
  int i;

  for ( i = 0; i <= 3; ++i )
  {
    CortBox2(&gRect_line, 0, i + 30);
    v0 = i + 30;
    RGB((int)&r, 0xFFu, 0xFFu, 254);
    PutText2(0, 0, (const char *)((i << 6) + 136141632), (const SDL_Color_0 *const )&r, v0);
  }
}

