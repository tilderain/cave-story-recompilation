#include "types.h"
#include "SDL_stdinc.h"
#include "windows_wrapper.h"
#include "Tags.h"

void ResetMyCharFlag();
void _PutlittleStar();
int __cdecl JudgeHitMyCharBlock(int x, int y);
int __cdecl JudgeHitMyCharTriangleA(int x, int y);
int __cdecl JudgeHitMyCharTriangleB(int x, int y);
int __cdecl JudgeHitMyCharTriangleC(int x, int y);
int __cdecl JudgeHitMyCharTriangleD(int x, int y);
int __cdecl JudgeHitMyCharTriangleE(int x, int y);
int __cdecl JudgeHitMyCharTriangleF(int x, int y);
int __cdecl JudgeHitMyCharTriangleG(int x, int y);
int __cdecl JudgeHitMyCharTriangleH(int x, int y);
int __cdecl JudgeHitMyCharWater(int x, int y);
int __cdecl JudgeHitMyCharDamage(int x, int y);
int __cdecl JudgeHitMyCharDamageW(int x, int y);
int __cdecl JudgeHitMyCharVectLeft(int x, int y);
int __cdecl JudgeHitMyCharVectUp(int x, int y);
int __cdecl JudgeHitMyCharVectRight(int x, int y);
int __cdecl JudgeHitMyCharVectDown(int x, int y);
void HitMyCharMap();
int __cdecl JudgeHitMyCharNPC(NPCHAR_0 *npc);
signed int __cdecl JudgeHitMyCharNPC3(NPCHAR_0 *npc);
int __cdecl JudgeHitMyCharNPC4(NPCHAR_0 *npc);
void HitMyCharNpChar();
void HitMyCharBoss();

void ResetMyCharFlag()
{
  dword_81C8584 = 0;
}

void _PutlittleStar()
{
  if ( !(gMC.cond & 2) && unk_81C85B8 < -512 )
  {
    PlaySoundObject(3, 1);
    SetCaret(x, y - unk_81C85C8, 13, 0);
    SetCaret(x, y - unk_81C85C8, 13, 0);
  }
}

int __cdecl JudgeHitMyCharBlock(int x, int y)
{
  int hit;

  hit = 0;
  if ( ::y - unk_81C85C8 < (2 * (2 * y + 1) - 1) << 11
    && unk_81C85D0 + ::y > (2 * (2 * y - 1) + 1) << 11
    && ::x - unk_81C85CC < (2 * x + 1) << 12
    && ::x - unk_81C85CC > x << 13 )
  {
    ::x = ((2 * x + 1) << 12) + unk_81C85CC;
    if ( unk_81C85B4 < -384 )
      unk_81C85B4 = -384;
    if ( !(gKey & gKeyLeft) && unk_81C85B4 < 0 )
      unk_81C85B4 = 0;
    hit = 1;
  }
  if ( ::y - unk_81C85C8 < (2 * (2 * y + 1) - 1) << 11
    && unk_81C85D0 + ::y > (2 * (2 * y - 1) + 1) << 11
    && unk_81C85CC + ::x > (2 * x - 1) << 12
    && unk_81C85CC + ::x < x << 13 )
  {
    ::x = ((2 * x - 1) << 12) - unk_81C85CC;
    if ( unk_81C85B4 > 384 )
      unk_81C85B4 = 384;
    if ( !(gKey & gKeyRight) && unk_81C85B4 > 0 )
      unk_81C85B4 = 0;
    hit |= 4u;
  }
  if ( ::x - unk_81C85CC < ((2 * x + 1) << 12) - 1536
    && unk_81C85CC + ::x > ((2 * x - 1) << 12) + 1536
    && ::y - unk_81C85C8 < (2 * y + 1) << 12
    && ::y - unk_81C85C8 > y << 13 )
  {
    ::y = ((2 * y + 1) << 12) + unk_81C85C8;
    if ( !(gMC.cond & 2) && unk_81C85B8 < -512 )
      _PutlittleStar();
    if ( unk_81C85B8 < 0 )
      unk_81C85B8 = 0;
    hit |= 2u;
  }
  if ( ::x - unk_81C85CC < ((2 * x + 1) << 12) - 1536
    && unk_81C85CC + ::x > ((2 * x - 1) << 12) + 1536
    && unk_81C85D0 + ::y > (2 * y - 1) << 12
    && unk_81C85D0 + ::y < y << 13 )
  {
    ::y = ((2 * y - 1) << 12) - unk_81C85D0;
    if ( unk_81C85B8 > 1024 )
      PlaySoundObject(23, 1);
    if ( unk_81C85B8 > 0 )
      unk_81C85B8 = 0;
    hit |= 8u;
  }
  return hit;
}

int __cdecl JudgeHitMyCharTriangleA(int x, int y)
{
  int hit;

  hit = 0;
  if ( ::x < (2 * x + 1) << 12
    && ::x > (2 * x - 1) << 12
    && ::y - unk_81C85C8 < (y << 13) - (-8192 * x + ::x) / 2 + 2048
    && unk_81C85D0 + ::y > (2 * y - 1) << 12 )
  {
    ::y = (y << 13) - (-8192 * x + ::x) / 2 + 2048 + unk_81C85C8;
    if ( !(gMC.cond & 2) && unk_81C85B8 < -512 )
      _PutlittleStar();
    if ( unk_81C85B8 < 0 )
      unk_81C85B8 = 0;
    hit = 2;
  }
  return hit;
}

int __cdecl JudgeHitMyCharTriangleB(int x, int y)
{
  int hit;

  hit = 0;
  if ( ::x < (2 * x + 1) << 12
    && ::x > (2 * x - 1) << 12
    && ::y - unk_81C85C8 < (y << 13) - (-8192 * x + ::x) / 2 - 2048
    && unk_81C85D0 + ::y > (2 * y - 1) << 12 )
  {
    ::y = (y << 13) - (-8192 * x + ::x) / 2 - 2048 + unk_81C85C8;
    if ( !(gMC.cond & 2) && unk_81C85B8 < -512 )
      _PutlittleStar();
    if ( unk_81C85B8 < 0 )
      unk_81C85B8 = 0;
    hit = 2;
  }
  return hit;
}

int __cdecl JudgeHitMyCharTriangleC(int x, int y)
{
  int hit;

  hit = 0;
  if ( ::x < (2 * x + 1) << 12
    && ::x > (2 * x - 1) << 12
    && ::y - unk_81C85C8 < (y << 13) + (-8192 * x + ::x) / 2 - 2048
    && unk_81C85D0 + ::y > (2 * y - 1) << 12 )
  {
    ::y = (y << 13) + (-8192 * x + ::x) / 2 - 2048 + unk_81C85C8;
    if ( !(gMC.cond & 2) && unk_81C85B8 < -512 )
      _PutlittleStar();
    if ( unk_81C85B8 < 0 )
      unk_81C85B8 = 0;
    hit = 2;
  }
  return hit;
}

int __cdecl JudgeHitMyCharTriangleD(int x, int y)
{
  int hit;

  hit = 0;
  if ( ::x < (2 * x + 1) << 12
    && ::x > (2 * x - 1) << 12
    && ::y - unk_81C85C8 < (y << 13) + (-8192 * x + ::x) / 2 + 2048
    && unk_81C85D0 + ::y > (2 * y - 1) << 12 )
  {
    ::y = (y << 13) + (-8192 * x + ::x) / 2 + 2048 + unk_81C85C8;
    if ( !(gMC.cond & 2) && unk_81C85B8 < -512 )
      _PutlittleStar();
    if ( unk_81C85B8 < 0 )
      unk_81C85B8 = 0;
    hit = 2;
  }
  return hit;
}

int __cdecl JudgeHitMyCharTriangleE(int x, int y)
{
  int hit;

  hit = 0x10000;
  if ( ::x < (2 * x + 1) << 12
    && ::x > (2 * x - 1) << 12
    && ::y + unk_81C85D0 > (y << 13) + (-8192 * x + ::x) / 2 - 2048
    && ::y - unk_81C85C8 < (2 * y + 1) << 12 )
  {
    ::y = (y << 13) + (-8192 * x + ::x) / 2 - 2048 - unk_81C85D0;
    if ( unk_81C85B8 > 1024 )
      PlaySoundObject(23, 1);
    if ( unk_81C85B8 > 0 )
      unk_81C85B8 = 0;
    hit = 65576;
  }
  return hit;
}

int __cdecl JudgeHitMyCharTriangleF(int x, int y)
{
  int hit;

  hit = 0x20000;
  if ( ::x < (2 * x + 1) << 12
    && ::x > (2 * x - 1) << 12
    && ::y + unk_81C85D0 > (y << 13) + (-8192 * x + ::x) / 2 + 2048
    && ::y - unk_81C85C8 < (2 * y + 1) << 12 )
  {
    ::y = (y << 13) + (-8192 * x + ::x) / 2 + 2048 - unk_81C85D0;
    if ( unk_81C85B8 > 1024 )
      PlaySoundObject(23, 1);
    if ( unk_81C85B8 > 0 )
      unk_81C85B8 = 0;
    hit = 131112;
  }
  return hit;
}

int __cdecl JudgeHitMyCharTriangleG(int x, int y)
{
  int hit;

  hit = 0x40000;
  if ( ::x < (2 * x + 1) << 12
    && ::x > (2 * x - 1) << 12
    && ::y + unk_81C85D0 > (y << 13) - (-8192 * x + ::x) / 2 + 2048
    && ::y - unk_81C85C8 < (2 * y + 1) << 12 )
  {
    ::y = (y << 13) - (-8192 * x + ::x) / 2 + 2048 - unk_81C85D0;
    if ( unk_81C85B8 > 1024 )
      PlaySoundObject(23, 1);
    if ( unk_81C85B8 > 0 )
      unk_81C85B8 = 0;
    hit = 262168;
  }
  return hit;
}

int __cdecl JudgeHitMyCharTriangleH(int x, int y)
{
  int hit;

  hit = 0x80000;
  if ( ::x < (2 * x + 1) << 12
    && ::x > (2 * x - 1) << 12
    && ::y + unk_81C85D0 > (y << 13) - (-8192 * x + ::x) / 2 - 2048
    && ::y - unk_81C85C8 < (2 * y + 1) << 12 )
  {
    ::y = (y << 13) - (-8192 * x + ::x) / 2 - 2048 - unk_81C85D0;
    if ( unk_81C85B8 > 1024 )
      PlaySoundObject(23, 1);
    if ( unk_81C85B8 > 0 )
      unk_81C85B8 = 0;
    hit = 524312;
  }
  return hit;
}

int __cdecl JudgeHitMyCharWater(int x, int y)
{
  int hit;

  hit = 0;
  if ( ::x - unk_81C85CC < ((2 * x + 1) << 12) - 1536
    && unk_81C85CC + ::x > ((2 * x - 1) << 12) + 1536
    && ::y - unk_81C85C8 < ((2 * y + 1) << 12) - 1536
    && unk_81C85D0 + ::y > y << 13 )
  {
    hit = 256;
  }
  return hit;
}

int __cdecl JudgeHitMyCharDamage(int x, int y)
{
  int hit;

  hit = 0;
  if ( ::x - 2048 < (4 * x + 1) << 11
    && ::x + 2048 > (4 * x - 1) << 11
    && ::y - 2048 < (y << 13) + 1536
    && ::y + 2048 > (y << 13) - 1536 )
  {
    hit = 1024;
  }
  return hit;
}

int __cdecl JudgeHitMyCharDamageW(int x, int y)
{
  int hit;

  hit = 0;
  if ( ::x - 2048 < (4 * x + 1) << 11
    && ::x + 2048 > (4 * x - 1) << 11
    && ::y - 2048 < (y << 13) + 1536
    && ::y + 2048 > (y << 13) - 1536 )
  {
    hit = 3328;
  }
  return hit;
}

int __cdecl JudgeHitMyCharVectLeft(int x, int y)
{
  int hit;

  hit = 0;
  if ( ::x - unk_81C85CC < (4 * (2 * x + 1) - 1) << 10
    && unk_81C85CC + ::x > (4 * (2 * x - 1) + 1) << 10
    && ::y - unk_81C85C8 < (4 * (2 * y + 1) - 1) << 10
    && unk_81C85D0 + ::y > (4 * (2 * y - 1) + 1) << 10 )
  {
    hit = 4096;
  }
  return hit;
}

int __cdecl JudgeHitMyCharVectUp(int x, int y)
{
  int hit;

  hit = 0;
  if ( ::x - unk_81C85CC < (4 * (2 * x + 1) - 1) << 10
    && unk_81C85CC + ::x > (4 * (2 * x - 1) + 1) << 10
    && ::y - unk_81C85C8 < (4 * (2 * y + 1) - 1) << 10
    && unk_81C85D0 + ::y > (4 * (2 * y - 1) + 1) << 10 )
  {
    hit = 0x2000;
  }
  return hit;
}

int __cdecl JudgeHitMyCharVectRight(int x, int y)
{
  int hit;

  hit = 0;
  if ( ::x - unk_81C85CC < (4 * (2 * x + 1) - 1) << 10
    && unk_81C85CC + ::x > (4 * (2 * x - 1) + 1) << 10
    && ::y - unk_81C85C8 < (4 * (2 * y + 1) - 1) << 10
    && unk_81C85D0 + ::y > (4 * (2 * y - 1) + 1) << 10 )
  {
    hit = 0x4000;
  }
  return hit;
}

int __cdecl JudgeHitMyCharVectDown(int x, int y)
{
  int hit;

  hit = 0;
  if ( ::x - unk_81C85CC < (4 * (2 * x + 1) - 1) << 10
    && unk_81C85CC + ::x > (4 * (2 * x - 1) + 1) << 10
    && ::y - unk_81C85C8 < (4 * (2 * y + 1) - 1) << 10
    && unk_81C85D0 + ::y > (4 * (2 * y - 1) + 1) << 10 )
  {
    hit = 0x8000;
  }
  return hit;
}

void HitMyCharMap()
{
  int v0;
  int v1;
  int v2;
  int v3;
  int v4;
  int v5;
  int v6;
  int v7;
  int v8;
  int v9;
  int v10;
  int v11;
  int v12;
  int v13;
  int v14;
  int v15;
  int v16;
  int v17;
  int v18;
  int v19;
  int v20;
  int v21;
  int v22;
  int v23;
  int v24;
  int v25;
  int v26;
  int v27;
  int v28;
  int v29;
  int v30;
  int v31;
  int offy[4];
  int offx[4];
  unsigned __int8 atrb[4];
  int x;
  int y;
  int i;

  x = ::x / 0x2000;
  y = ::y / 0x2000;
  offx[0] = 0;
  offx[1] = 1;
  offx[2] = 0;
  offx[3] = 1;
  offy[0] = 0;
  offy[1] = 0;
  offy[2] = 1;
  offy[3] = 1;
  for ( i = 0; i <= 3; ++i )
  {
    v0 = i;
    atrb[v0] = GetAttribute(x + offx[i], y + offy[i]);
    switch ( atrb[i] )
    {
      case 2u:
        v16 = dword_81C8584;
        dword_81C8584 = v16 | JudgeHitMyCharWater(x + offx[i], y + offy[i]);
        break;
      case 5u:
      case 0x41u:
      case 0x43u:
      case 0x46u:
        v1 = dword_81C8584;
        dword_81C8584 = v1 | JudgeHitMyCharBlock(x + offx[i], y + offy[i]);
        break;
      case 0x42u:
        v10 = dword_81C8584;
        dword_81C8584 = v10 | JudgeHitMyCharDamage(x + offx[i], y + offy[i]);
        break;
      case 0x50u:
        v2 = dword_81C8584;
        dword_81C8584 = v2 | JudgeHitMyCharTriangleA(x + offx[i], y + offy[i]);
        break;
      case 0x51u:
        v3 = dword_81C8584;
        dword_81C8584 = v3 | JudgeHitMyCharTriangleB(x + offx[i], y + offy[i]);
        break;
      case 0x52u:
        v4 = dword_81C8584;
        dword_81C8584 = v4 | JudgeHitMyCharTriangleC(x + offx[i], y + offy[i]);
        break;
      case 0x53u:
        v5 = dword_81C8584;
        dword_81C8584 = v5 | JudgeHitMyCharTriangleD(x + offx[i], y + offy[i]);
        break;
      case 0x54u:
        v6 = dword_81C8584;
        dword_81C8584 = v6 | JudgeHitMyCharTriangleE(x + offx[i], y + offy[i]);
        break;
      case 0x55u:
        v7 = dword_81C8584;
        dword_81C8584 = v7 | JudgeHitMyCharTriangleF(x + offx[i], y + offy[i]);
        break;
      case 0x56u:
        v8 = dword_81C8584;
        dword_81C8584 = v8 | JudgeHitMyCharTriangleG(x + offx[i], y + offy[i]);
        break;
      case 0x57u:
        v9 = dword_81C8584;
        dword_81C8584 = v9 | JudgeHitMyCharTriangleH(x + offx[i], y + offy[i]);
        break;
      case 0x60u:
        v17 = dword_81C8584;
        dword_81C8584 = v17 | JudgeHitMyCharWater(x + offx[i], y + offy[i]);
        break;
      case 0x61u:
        v18 = dword_81C8584;
        dword_81C8584 = v18 | JudgeHitMyCharBlock(x + offx[i], y + offy[i]);
        dword_81C8584 |= JudgeHitMyCharWater(x + offx[i], y + offy[i]);
        break;
      case 0x62u:
        v11 = dword_81C8584;
        dword_81C8584 = v11 | JudgeHitMyCharDamageW(x + offx[i], y + offy[i]);
        break;
      case 0x70u:
        v19 = dword_81C8584;
        dword_81C8584 = v19 | JudgeHitMyCharTriangleA(x + offx[i], y + offy[i]);
        dword_81C8584 |= JudgeHitMyCharWater(x + offx[i], y + offy[i]);
        break;
      case 0x71u:
        v20 = dword_81C8584;
        dword_81C8584 = v20 | JudgeHitMyCharTriangleB(x + offx[i], y + offy[i]);
        dword_81C8584 |= JudgeHitMyCharWater(x + offx[i], y + offy[i]);
        break;
      case 0x72u:
        v21 = dword_81C8584;
        dword_81C8584 = v21 | JudgeHitMyCharTriangleC(x + offx[i], y + offy[i]);
        dword_81C8584 |= JudgeHitMyCharWater(x + offx[i], y + offy[i]);
        break;
      case 0x73u:
        v22 = dword_81C8584;
        dword_81C8584 = v22 | JudgeHitMyCharTriangleD(x + offx[i], y + offy[i]);
        dword_81C8584 |= JudgeHitMyCharWater(x + offx[i], y + offy[i]);
        break;
      case 0x74u:
        v23 = dword_81C8584;
        dword_81C8584 = v23 | JudgeHitMyCharTriangleE(x + offx[i], y + offy[i]);
        dword_81C8584 |= JudgeHitMyCharWater(x + offx[i], y + offy[i]);
        break;
      case 0x75u:
        v24 = dword_81C8584;
        dword_81C8584 = v24 | JudgeHitMyCharTriangleF(x + offx[i], y + offy[i]);
        dword_81C8584 |= JudgeHitMyCharWater(x + offx[i], y + offy[i]);
        break;
      case 0x76u:
        v25 = dword_81C8584;
        dword_81C8584 = v25 | JudgeHitMyCharTriangleG(x + offx[i], y + offy[i]);
        dword_81C8584 |= JudgeHitMyCharWater(x + offx[i], y + offy[i]);
        break;
      case 0x77u:
        v26 = dword_81C8584;
        dword_81C8584 = v26 | JudgeHitMyCharTriangleH(x + offx[i], y + offy[i]);
        dword_81C8584 |= JudgeHitMyCharWater(x + offx[i], y + offy[i]);
        break;
      case 0x80u:
        v12 = dword_81C8584;
        dword_81C8584 = v12 | JudgeHitMyCharVectLeft(x + offx[i], y + offy[i]);
        break;
      case 0x81u:
        v13 = dword_81C8584;
        dword_81C8584 = v13 | JudgeHitMyCharVectUp(x + offx[i], y + offy[i]);
        break;
      case 0x82u:
        v14 = dword_81C8584;
        dword_81C8584 = v14 | JudgeHitMyCharVectRight(x + offx[i], y + offy[i]);
        break;
      case 0x83u:
        v15 = dword_81C8584;
        dword_81C8584 = v15 | JudgeHitMyCharVectDown(x + offx[i], y + offy[i]);
        break;
      case 0xA0u:
        v27 = dword_81C8584;
        dword_81C8584 = v27 | JudgeHitMyCharVectLeft(x + offx[i], y + offy[i]);
        dword_81C8584 |= JudgeHitMyCharWater(x + offx[i], y + offy[i]);
        break;
      case 0xA1u:
        v28 = dword_81C8584;
        dword_81C8584 = v28 | JudgeHitMyCharVectUp(x + offx[i], y + offy[i]);
        dword_81C8584 |= JudgeHitMyCharWater(x + offx[i], y + offy[i]);
        break;
      case 0xA2u:
        v29 = dword_81C8584;
        dword_81C8584 = v29 | JudgeHitMyCharVectRight(x + offx[i], y + offy[i]);
        dword_81C8584 |= JudgeHitMyCharWater(x + offx[i], y + offy[i]);
        break;
      case 0xA3u:
        v30 = dword_81C8584;
        dword_81C8584 = v30 | JudgeHitMyCharVectDown(x + offx[i], y + offy[i]);
        dword_81C8584 |= JudgeHitMyCharWater(x + offx[i], y + offy[i]);
        break;
      default:
        continue;
    }
  }
  if ( ::y > gWaterY + 2048 )
  {
    v31 = dword_81C8584;
    BYTE1(v31) |= 1u;
    dword_81C8584 = v31;
  }
}

int __cdecl JudgeHitMyCharNPC(NPCHAR_0 *npc)
{
  int hit;

  hit = 0;
  if ( y - unk_81C85C8 < npc->y + npc->hit.bottom - 1536
    && y + unk_81C85D0 > npc->y - npc->hit.top + 1536
    && x - unk_81C85CC < npc->x + npc->hit.back
    && x - unk_81C85CC > npc->x )
  {
    if ( unk_81C85B4 <= 511 )
      unk_81C85B4 += 512;
    hit = 1;
  }
  if ( y - unk_81C85C8 < npc->y + npc->hit.bottom - 1536
    && y + unk_81C85D0 > npc->y - npc->hit.top + 1536
    && x + unk_81C85CC - 512 > npc->x - npc->hit.back
    && x + unk_81C85CC - 512 < npc->x )
  {
    if ( unk_81C85B4 >= -511 )
      unk_81C85B4 -= 512;
    hit |= 4u;
  }
  if ( x - unk_81C85CC < npc->x + npc->hit.back - 1536
    && x + unk_81C85CC > npc->x - npc->hit.back + 1536
    && y - unk_81C85C8 < npc->y + npc->hit.bottom
    && y - unk_81C85C8 > npc->y )
  {
    if ( unk_81C85B8 < 0 )
      unk_81C85B8 = 0;
    hit |= 2u;
  }
  if ( x - unk_81C85CC < npc->x + npc->hit.back - 1536
    && x + unk_81C85CC > npc->x - npc->hit.back + 1536
    && y + unk_81C85D0 > npc->y - npc->hit.top
    && unk_81C85D0 + y < npc->y + 1536 )
  {
    if ( npc->bits & 0x10 )
    {
      unk_81C85B8 = npc->ym - 512;
      hit |= 8u;
    }
    else if ( !(dword_81C8584 & 8) && unk_81C85B8 > npc->ym )
    {
      y = npc->y - npc->hit.top - unk_81C85D0 + 512;
      unk_81C85B8 = npc->ym;
      x += npc->xm;
      hit |= 8u;
    }
  }
  return hit;
}

signed int __cdecl JudgeHitMyCharNPC3(NPCHAR_0 *npc)
{
  if ( npc->direct )
  {
    if ( x + 1024 > npc->x - npc->hit.back
      && x - 1024 < npc->x + npc->hit.front
      && y + 1024 > npc->y - npc->hit.top
      && y - 1024 < npc->y + npc->hit.bottom )
    {
      return 1;
    }
  }
  else if ( x + 1024 > npc->x - npc->hit.front
         && x - 1024 < npc->x + npc->hit.back
         && y + 1024 > npc->y - npc->hit.top
         && y - 1024 < npc->y + npc->hit.bottom )
  {
    return 1;
  }
  return 0;
}

int __cdecl JudgeHitMyCharNPC4(NPCHAR_0 *npc)
{
  long double v1;
  long double v2;
  float fy1;
  float fy2;
  int hit;
  float fx1;
  float fx2;

  hit = 0;
  if ( npc->x <= x )
    v1 = (long double)(x - npc->x);
  else
    v1 = (long double)(npc->x - x);
  fx1 = v1;
  if ( npc->y <= y )
    v2 = (long double)(y - npc->y);
  else
    v2 = (long double)(npc->y - y);
  fx2 = (long double)npc->hit.back;
  if ( 0.0 == fx1 )
    fx1 = 1.0;
  if ( 0.0 == fx2 )
    fx2 = 1.0;
  fy1 = v2;
  fy2 = (long double)npc->hit.top;
  if ( fy1 / fx1 <= fy2 / fx2 )
  {
    if ( y - unk_81C85C8 < npc->y + npc->hit.bottom && y + unk_81C85D0 > npc->y - npc->hit.top )
    {
      if ( x - unk_81C85CC < npc->x + npc->hit.back && x - unk_81C85CC > npc->x )
      {
        if ( unk_81C85B4 < npc->xm )
          unk_81C85B4 = npc->xm;
        x = npc->hit.back + npc->x + unk_81C85CC;
        hit = 1;
      }
      if ( x + unk_81C85CC > npc->x - npc->hit.back && unk_81C85CC + x < npc->x )
      {
        if ( unk_81C85B4 > npc->xm )
          unk_81C85B4 = npc->xm;
        x = npc->x - npc->hit.back - unk_81C85CC;
        hit |= 4u;
      }
    }
  }
  else if ( x - unk_81C85CC < npc->x + npc->hit.back && x + unk_81C85CC > npc->x - npc->hit.back )
  {
    if ( y - unk_81C85C8 < npc->y + npc->hit.bottom && y - unk_81C85C8 > npc->y )
    {
      if ( unk_81C85B8 >= npc->ym )
      {
        if ( unk_81C85B8 < 0 )
          unk_81C85B8 = 0;
      }
      else
      {
        y = npc->hit.bottom + npc->y + unk_81C85C8 + 512;
        unk_81C85B8 = npc->ym;
      }
      hit = 2;
    }
    if ( y + unk_81C85D0 > npc->y - npc->hit.top && unk_81C85D0 + y < npc->y + 1536 )
    {
      if ( unk_81C85B8 - npc->ym > 1024 )
        PlaySoundObject(23, 1);
      if ( unk_81C8594 == 1 )
      {
        y = npc->y - npc->hit.top - unk_81C85D0 + 512;
        hit |= 8u;
      }
      else if ( npc->bits & 0x10 )
      {
        unk_81C85B8 = npc->ym - 512;
        hit |= 8u;
      }
      else if ( !(dword_81C8584 & 8) && unk_81C85B8 > npc->ym )
      {
        y = npc->y - npc->hit.top - unk_81C85D0 + 512;
        unk_81C85B8 = npc->ym;
        x += npc->xm;
        hit |= 8u;
      }
    }
  }
  return hit;
}

void HitMyCharNpChar()
{
  int i;
  int hit;

  if ( (gMC.cond & 0x80u) != 0 && !(gMC.cond & 2) )
  {
    for ( i = 0; i <= 511; ++i )
    {
      if ( (gNPC[i].cond & 0x80u) != 0 )
      {
        if ( gNPC[i].bits & 1 )
        {
          hit = JudgeHitMyCharNPC((NPCHAR_0 *)(172 * i + 136142176));
          dword_81C8584 |= hit;
        }
        else if ( gNPC[i].bits & 0x40 )
        {
          hit = JudgeHitMyCharNPC4((NPCHAR_0 *)(172 * i + 136142176));
          dword_81C8584 |= hit;
        }
        else
        {
          hit = (unsigned __int8)JudgeHitMyCharNPC3((NPCHAR_0 *)(172 * i + 136142176));
        }
        if ( hit && gNPC[i].code_char == 1 )
        {
          PlaySoundObject(14, 1);
          AddExpMyChar(gNPC[i].exp);
          gNPC[i].cond = 0;
        }
        if ( hit && gNPC[i].code_char == 86 )
        {
          PlaySoundObject(42, 1);
          AddBulletMyChar(gNPC[i].code_event, gNPC[i].exp);
          gNPC[i].cond = 0;
        }
        if ( hit && gNPC[i].code_char == 87 )
        {
          PlaySoundObject(20, 1);
          AddLifeMyChar(gNPC[i].exp);
          gNPC[i].cond = 0;
        }
        if ( !(g_GameFlags & 4) && hit && gNPC[i].bits & 0x100 )
          StartTextScript(gNPC[i].code_event);
        if ( g_GameFlags & 2 && !(gNPC[i].bits & 0x2000) )
        {
          if ( gNPC[i].bits & 0x80 )
          {
            if ( hit & 4 && gNPC[i].xm < 0 )
              DamageMyChar(gNPC[i].damage);
            if ( hit & 1 && gNPC[i].xm > 0 )
              DamageMyChar(gNPC[i].damage);
            if ( hit & 8 && gNPC[i].ym < 0 )
              DamageMyChar(gNPC[i].damage);
            if ( hit & 2 && gNPC[i].ym > 0 )
              DamageMyChar(gNPC[i].damage);
          }
          else if ( hit && gNPC[i].damage && !(g_GameFlags & 4) )
          {
            DamageMyChar(gNPC[i].damage);
          }
        }
        if ( !(g_GameFlags & 4) && hit && gMC.cond & 1 && gNPC[i].bits & 0x2000 )
        {
          StartTextScript(gNPC[i].code_event);
          unk_81C85B4 = 0;
          unk_81C862D = 0;
        }
      }
    }
    if ( unk_81C862D )
      SetCaret(x, y, 9, 0);
  }
}

void HitMyCharBoss()
{
  int b;
  int hit;

  if ( (gMC.cond & 0x80u) != 0 && !(gMC.cond & 2) )
  {
    for ( b = 0; b <= 19; ++b )
    {
      if ( (gBoss[b].cond & 0x80u) != 0 )
      {
        if ( *((_BYTE *)&unk_81CD010 + 172 * b) & 1 )
        {
          hit = JudgeHitMyCharNPC((NPCHAR_0 *)(172 * b + 136105920));
          dword_81C8584 |= hit;
        }
        else if ( *((_WORD *)&unk_81CD010 + 86 * b) & 0x40 )
        {
          hit = JudgeHitMyCharNPC4((NPCHAR_0 *)(172 * b + 136105920));
          dword_81C8584 |= hit;
        }
        else
        {
          hit = (unsigned __int8)JudgeHitMyCharNPC3((NPCHAR_0 *)(172 * b + 136105920));
        }
        if ( !(g_GameFlags & 4) && hit && *((_WORD *)&unk_81CD010 + 86 * b) & 0x100 )
        {
          StartTextScript(*((_DWORD *)&unk_81CCFF0 + 43 * b));
          unk_81C862D = 0;
        }
        if ( *((_WORD *)&unk_81CD010 + 86 * b) & 0x80 )
        {
          if ( hit & 4 && *((_DWORD *)&unk_81CCFD0 + 43 * b) < 0 )
            DamageMyChar(*((_DWORD *)&unk_81CD064 + 43 * b));
          if ( hit & 1 && *((_DWORD *)&unk_81CCFD0 + 43 * b) > 0 )
            DamageMyChar(*((_DWORD *)&unk_81CD064 + 43 * b));
        }
        else if ( hit && *((_DWORD *)&unk_81CD064 + 43 * b) && !(g_GameFlags & 4) )
        {
          DamageMyChar(*((_DWORD *)&unk_81CD064 + 43 * b));
        }
        if ( !(g_GameFlags & 4) && hit && gMC.cond & 1 && *((_WORD *)&unk_81CD010 + 86 * b) & 0x2000 )
        {
          StartTextScript(*((_DWORD *)&unk_81CCFF0 + 43 * b));
          unk_81C85B4 = 0;
          unk_81C862D = 0;
        }
      }
    }
    if ( unk_81C862D )
      SetCaret(x, y, 9, 0);
  }
}

