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
void InitNpChar()
{
  memset(gNPC, 0, 0x15800u);
}

void __cdecl _SetUniqueParameter(NPCHAR_0 *npc)
{
  int code;

  code = npc->code_char;
  npc->surf = gNpcTable[code].surf;
  npc->hit_voice = gNpcTable[code].hit_voice;
  npc->destroy_voice = gNpcTable[code].destroy_voice;
  npc->damage = gNpcTable[code].damage;
  npc->size = gNpcTable[code].size;
  npc->life = gNpcTable[code].life;
  npc->hit.front = gNpcTable[code].hit.front << 9;
  npc->hit.back = gNpcTable[code].hit.back << 9;
  npc->hit.top = gNpcTable[code].hit.top << 9;
  npc->hit.bottom = gNpcTable[code].hit.bottom << 9;
  npc->view.front = gNpcTable[code].view.front << 9;
  npc->view.back = gNpcTable[code].view.back << 9;
  npc->view.top = gNpcTable[code].view.top << 9;
  npc->view.bottom = gNpcTable[code].view.bottom << 9;
}

signed int __cdecl LoadEvent(char *path_event)
{
  int v2;
  char path[260];
  $27E69A81C4D44FA41891AD1A77DE92B3 eve;
  char code[4];
  int i;
  int n;
  SDL_RWops_0 *fp;
  int count;

  sprintf(path, "%s/%s", gDataPath, path_event);
  fp = SDL_RWFromFile(path, "rb");
  if ( !fp )
    return 0;
  fp->read(fp, code, 1, 4);
  if ( memcmp(code, gPassPixEve, 3u) )
    return 0;
  count = SDL_ReadLE32(fp);
  memset(gNPC, 0, 0x15800u);
  n = 170;
  for ( i = 0; i < count; ++i )
  {
    eve.x = SDL_ReadLE16(fp);
    eve.y = SDL_ReadLE16(fp);
    eve.code_flag = SDL_ReadLE16(fp);
    eve.code_event = SDL_ReadLE16(fp);
    eve.code_char = SDL_ReadLE16(fp);
    eve.bits = SDL_ReadLE16(fp);
    if ( eve.bits & 0x1000 )
      v2 = 2;
    else
      v2 = 0;
    gNPC[n].direct = v2;
    gNPC[n].code_char = eve.code_char;
    gNPC[n].code_event = eve.code_event;
    gNPC[n].code_flag = eve.code_flag;
    gNPC[n].x = eve.x << 13;
    gNPC[n].y = eve.y << 13;
    gNPC[n].bits = eve.bits;
    gNPC[n].bits |= gNpcTable[gNPC[n].code_char].bits;
    gNPC[n].exp = gNpcTable[gNPC[n].code_char].exp;
    _SetUniqueParameter((NPCHAR_0 *)(172 * n + 136142176));
    if ( gNPC[n].bits & 0x800 )
    {
      if ( (unsigned __int8)GetNPCFlag(gNPC[n].code_flag) )
        gNPC[n].cond |= 0x80u;
    }
    else if ( gNPC[n].bits & 0x4000 )
    {
      if ( (unsigned __int8)GetNPCFlag(gNPC[n].code_flag) ^ 1 )
        gNPC[n].cond |= 0x80u;
    }
    else
    {
      gNPC[n].cond = -128;
    }
    ++n;
  }
  fp->close(fp);
  return 1;
}



void __cdecl SetNpChar(int code_char, int x, int y, int xm, int ym, int dir, NPCHAR_0 *npc, int start_index)
{
  char v8;
  signed int n;

  for ( n = start_index; ; ++n )
  {
    v8 = n <= 511 && gNPC[n].cond ? 1 : 0;
    if ( !v8 )
      break;
  }
  if ( n != 512 )
  {
    memset((void *)(172 * n + 136142176), 0, 0xACu);
    gNPC[n].cond |= 0x80u;
    gNPC[n].direct = dir;
    gNPC[n].code_char = code_char;
    gNPC[n].x = x;
    gNPC[n].y = y;
    gNPC[n].xm = xm;
    gNPC[n].ym = ym;
    gNPC[n].pNpc = npc;
    gNPC[n].bits = gNpcTable[gNPC[n].code_char].bits;
    gNPC[n].exp = gNpcTable[gNPC[n].code_char].exp;
    _SetUniqueParameter((NPCHAR_0 *)(172 * n + 136142176));
  }
}

void __cdecl SetDestroyNpChar(int x, int y, int w, int num)
{
  int offset_x;
  int offset_y;
  int i;
  int wa;

  wa = w / 512;
  for ( i = 0; i < num; ++i )
  {
    offset_x = Random(-wa, wa) << 9;
    offset_y = Random(-wa, wa) << 9;
    SetNpChar(4, x + offset_x, offset_y + y, 0, 0, 0, 0, 256);
  }
  SetCaret(x, y, 12, 0);
}

void __cdecl SetDestroyNpCharUp(int x, int y, int w, int num)
{
  int offset_x;
  int offset_y;
  int i;
  int wa;

  wa = w / 512;
  for ( i = 0; i < num; ++i )
  {
    offset_x = Random(-wa, wa) << 9;
    offset_y = Random(-wa, wa) << 9;
    SetNpChar(4, x + offset_x, offset_y + y, 0, 0, 1, 0, 256);
  }
  SetCaret(x, y, 12, 0);
}

void __cdecl SetExpObjects(int x, int y, int exp)
{
  char v3;
  int n;
  signed int sub_exp;

  for ( n = 256; exp; _SetUniqueParameter((NPCHAR_0 *)(172 * n + 136142176)) )
  {
    while ( 1 )
    {
      v3 = n <= 511 && gNPC[n].cond ? 1 : 0;
      if ( !v3 )
        break;
      ++n;
    }
    if ( n == 512 )
      break;
    memset((void *)(172 * n + 136142176), 0, 0xACu);
    if ( exp <= 19 )
    {
      if ( exp <= 4 )
      {
        if ( exp > 0 )
        {
          --exp;
          sub_exp = 1;
        }
      }
      else
      {
        exp -= 5;
        sub_exp = 5;
      }
    }
    else
    {
      exp -= 20;
      sub_exp = 20;
    }
    gNPC[n].cond |= 0x80u;
    gNPC[n].direct = 0;
    gNPC[n].code_char = 1;
    gNPC[n].x = x;
    gNPC[n].y = y;
    gNPC[n].bits = gNpcTable[gNPC[n].code_char].bits;
    gNPC[n].exp = sub_exp;
  }
}

signed int __cdecl SetBulletObject(int x, int y, int val)
{
  int v3;
  char v5;
  int tamakazu_ari[10];
  int n;
  int bullet_no;
  int t;

  t = 0;
  memset(tamakazu_ari, 0, 0x28u);
  for ( n = 0; n <= 7; ++n )
  {
    v3 = gArmsData[n].code;
    if ( v3 == 5 )
    {
      tamakazu_ari[t++] = 0;
    }
    else if ( v3 == 10 )
    {
      tamakazu_ari[t++] = 1;
    }
    else
    {
      tamakazu_ari[t] = 0;
    }
  }
  if ( !t )
    return 0;
  n = Random(1, 10 * t);
  bullet_no = tamakazu_ari[n % t];
  for ( n = 256; ; ++n )
  {
    v5 = n <= 511 && gNPC[n].cond ? 1 : 0;
    if ( !v5 )
      break;
  }
  if ( n == 512 )
    return 0;
  memset((void *)(172 * n + 136142176), 0, 0xACu);
  gNPC[n].cond |= 0x80u;
  gNPC[n].direct = 0;
  gNPC[n].code_event = bullet_no;
  gNPC[n].code_char = 86;
  gNPC[n].x = x;
  gNPC[n].y = y;
  gNPC[n].bits = gNpcTable[gNPC[n].code_char].bits;
  gNPC[n].exp = val;
  _SetUniqueParameter((NPCHAR_0 *)(172 * n + 136142176));
  return 1;
}

signed int __cdecl SetLifeObject(int x, int y, int val)
{
  char v3;
  int n;

  for ( n = 256; ; ++n )
  {
    v3 = n <= 511 && gNPC[n].cond ? 1 : 0;
    if ( !v3 )
      break;
  }
  if ( n == 512 )
    return 0;
  memset((void *)(172 * n + 136142176), 0, 0xACu);
  gNPC[n].cond |= 0x80u;
  gNPC[n].direct = 0;
  gNPC[n].code_char = 87;
  gNPC[n].x = x;
  gNPC[n].y = y;
  gNPC[n].bits = gNpcTable[gNPC[n].code_char].bits;
  gNPC[n].exp = val;
  _SetUniqueParameter((NPCHAR_0 *)(172 * n + 136142176));
  return 1;
}

void __cdecl VanishNpChar(NPCHAR_0 *npc)
{
  int x;
  int y;

  x = npc->x;
  y = npc->y;
  memset(npc, 0, 0xACu);
  npc->count1 = 0;
  npc->x = x;
  npc->y = y;
  npc->cond |= 0x80u;
  npc->direct = 0;
  npc->code_char = 3;
  npc->bits = gNpcTable[npc->code_char].bits;
  npc->exp = gNpcTable[npc->code_char].exp;
  _SetUniqueParameter(npc);
}

void __cdecl PutNpChar(int fx, int fy)
{
  int n;
  Sint8 a;
  int side;

  for ( n = 0; n <= 511; ++n )
  {
    if ( (gNPC[n].cond & 0x80u) != 0 )
    {
      if ( gNPC[n].shock )
      {
        a = 2 * ((gNPC[n].shock >> 1) & 1) - 1;
      }
      else
      {
        a = 0;
        if ( (gNPC[n].bits & 0x8000u) != 0 && gNPC[n].damage_view )
        {
          SetValueView((int *)(172 * n + 136142184), (int *)(172 * n + 136142188), gNPC[n].damage_view);
          gNPC[n].damage_view = 0;
        }
      }
      if ( gNPC[n].direct )
        side = gNPC[n].view.back;
      else
        side = gNPC[n].view.front;
      PutBitmap3(
        &grcGame,
        (gNPC[n].x - side) / 512 - fx / 512 + a,
        (gNPC[n].y - gNPC[n].view.top) / 512 - fy / 512,
        (RECT *)(172 * n + 136142260),
        gNPC[n].surf);
    }
  }
}

void ActNpChar()
{
  int i;

  for ( i = 0; i <= 511; ++i )
  {
    if ( (gNPC[i].cond & 0x80u) != 0 )
    {
      gpNpcFuncTbl[gNPC[i].code_char]((NPCHAR_0 *)(172 * i + 136142176));
      if ( gNPC[i].shock )
        --gNPC[i].shock;
    }
  }
}

void __cdecl ChangeNpCharByEvent(int code_event, int code_char, int dir)
{
  int n;

  for ( n = 0; n <= 511; ++n )
  {
    if ( (gNPC[n].cond & 0x80u) != 0 && gNPC[n].code_event == code_event )
    {
      gNPC[n].bits &= 0x7F00u;
      gNPC[n].code_char = code_char;
      gNPC[n].bits |= gNpcTable[gNPC[n].code_char].bits;
      gNPC[n].exp = gNpcTable[gNPC[n].code_char].exp;
      _SetUniqueParameter((NPCHAR_0 *)(172 * n + 136142176));
      gNPC[n].cond |= 0x80u;
      gNPC[n].act_no = 0;
      gNPC[n].act_wait = 0;
      gNPC[n].count1 = 0;
      gNPC[n].count2 = 0;
      gNPC[n].ani_no = 0;
      gNPC[n].ani_wait = 0;
      gNPC[n].xm = 0;
      gNPC[n].ym = 0;
      if ( dir != 5 )
      {
        if ( dir == 4 )
        {
          if ( gNPC[n].x >= x )
            gNPC[n].direct = 0;
          else
            gNPC[n].direct = 2;
        }
        else
        {
          gNPC[n].direct = dir;
        }
      }
      gpNpcFuncTbl[code_char]((NPCHAR_0 *)(172 * n + 136142176));
    }
  }
}

void __cdecl ChangeCheckableNpCharByEvent(int code_event, int code_char, int dir)
{
  unsigned __int16 v3;
  int n;

  for ( n = 0; n <= 511; ++n )
  {
    if ( (gNPC[n].cond & 0x80u) != 0 && gNPC[n].code_event == code_event )
    {
      gNPC[n].bits &= 0x7F00u;
      v3 = gNPC[n].bits;
      HIBYTE(v3) |= 0x20u;
      gNPC[n].bits = v3;
      gNPC[n].code_char = code_char;
      gNPC[n].bits |= gNpcTable[gNPC[n].code_char].bits;
      gNPC[n].exp = gNpcTable[gNPC[n].code_char].exp;
      _SetUniqueParameter((NPCHAR_0 *)(172 * n + 136142176));
      gNPC[n].cond |= 0x80u;
      gNPC[n].act_no = 0;
      gNPC[n].act_wait = 0;
      gNPC[n].count1 = 0;
      gNPC[n].count2 = 0;
      gNPC[n].ani_no = 0;
      gNPC[n].ani_wait = 0;
      gNPC[n].xm = 0;
      gNPC[n].ym = 0;
      if ( dir != 5 )
      {
        if ( dir == 4 )
        {
          if ( gNPC[n].x >= x )
            gNPC[n].direct = 0;
          else
            gNPC[n].direct = 2;
        }
        else
        {
          gNPC[n].direct = (char)dir;
        }
      }
      gpNpcFuncTbl[code_char]((NPCHAR_0 *)(172 * n + 136142176));
    }
  }
}

void __cdecl SetNpCharActionNo(int code_event, int act_no, int dir)
{
  int n;

  for ( n = 0; n <= 511 && ((gNPC[n].cond & 0x80u) == 0 || gNPC[n].code_event != code_event); ++n )
    ;
  if ( n != 512 )
  {
    gNPC[n].act_no = act_no;
    if ( dir != 5 )
    {
      if ( dir == 4 )
      {
        if ( gNPC[n].x >= x )
          gNPC[n].direct = 0;
        else
          gNPC[n].direct = 2;
      }
      else
      {
        gNPC[n].direct = dir;
      }
    }
  }
}

void __cdecl MoveNpChar(int code_event, int x, int y, int dir)
{
  int n;

  for ( n = 0; n <= 511 && ((gNPC[n].cond & 0x80u) == 0 || gNPC[n].code_event != code_event); ++n )
    ;
  if ( n != 512 )
  {
    gNPC[n].x = x;
    gNPC[n].y = y;
    if ( dir != 5 )
    {
      if ( dir == 4 )
      {
        if ( gNPC[n].x >= ::x )
          gNPC[n].direct = 0;
        else
          gNPC[n].direct = 2;
      }
      else
      {
        gNPC[n].direct = (char)dir;
      }
    }
  }
}

void __cdecl BackStepMyChar(int code_event)
{
  int n;

  n = 0;
  gMC.cond &= 0xFEu;
  unk_81C85B8 = -512;
  if ( code_event )
  {
    if ( code_event == 2 )
    {
      dir = 2;
      unk_81C85B4 = -512;
    }
    else
    {
      while ( n <= 511 && ((gNPC[n].cond & 0x80u) == 0 || gNPC[n].code_event != code_event) )
        ++n;
      if ( n != 512 )
      {
        if ( gNPC[n].x >= x )
        {
          dir = 2;
          unk_81C85B4 = -512;
        }
        else
        {
          dir = 0;
          unk_81C85B4 = 512;
        }
      }
    }
  }
  else
  {
    dir = 0;
    unk_81C85B4 = 512;
  }
}

void __cdecl DeleteNpCharEvent(int code)
{
  int i;

  for ( i = 0; i <= 511; ++i )
  {
    if ( (gNPC[i].cond & 0x80u) != 0 && gNPC[i].code_event == code )
    {
      gNPC[i].cond = 0;
      SetNPCFlag(gNPC[i].code_flag);
    }
  }
}

void __cdecl DeleteNpCharCode(int code, bool bSmoke)
{
  int v2;
  int n;

  for ( n = 0; n <= 511; ++n )
  {
    if ( (gNPC[n].cond & 0x80u) != 0 && gNPC[n].code_char == code )
    {
      gNPC[n].cond = 0;
      SetNPCFlag(gNPC[n].code_flag);
      if ( bSmoke )
      {
        PlaySoundObject(gNPC[n].destroy_voice, 1);
        v2 = gNPC[n].size;
        switch ( v2 )
        {
          case 2:
            SetDestroyNpChar(gNPC[n].x, gNPC[n].y, gNPC[n].view.back, 8);
            break;
          case 3:
            SetDestroyNpChar(gNPC[n].x, gNPC[n].y, gNPC[n].view.back, 16);
            break;
          case 1:
            SetDestroyNpChar(gNPC[n].x, gNPC[n].y, gNPC[n].view.back, 4);
            break;
        }
      }
    }
  }
}

void __cdecl GetNpCharPosition(int *x, int *y, int i)
{
  *x = gNPC[i].x;
  *y = gNPC[i].y;
}

signed int __cdecl IsNpCharCode(int code)
{
  int i;

  for ( i = 0; i <= 511; ++i )
  {
    if ( (gNPC[i].cond & 0x80u) != 0 && gNPC[i].code_char == code )
      return 1;
  }
  return 0;
}

_BOOL4 __cdecl GetNpCharAlive(int code_event)
{
  int i;

  for ( i = 0; i <= 511 && ((gNPC[i].cond & 0x80u) == 0 || gNPC[i].code_event != code_event); ++i )
    ;
  return i <= 511;
}

int CountAliveNpChar()
{
  int n;
  int count;

  count = 0;
  for ( n = 0; n <= 511; ++n )
  {
    if ( (gNPC[n].cond & 0x80u) != 0 )
      ++count;
  }
  return count;
}

void __cdecl ActNpc000(NPCHAR_0 *npc)
{
  if ( !npc->act_no )
  {
    npc->act_no = 1;
    if ( npc->direct == 2 )
      npc->y += 0x2000;
  }
  npc->rect.left = 0;
  npc->rect.top = 0;
  npc->rect.right = 16;
  npc->rect.bottom = 16;
}

