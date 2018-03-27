//#include "types.h"
#include "SDL_stdinc.h"
#include "windows_wrapper.h"
#include "Tags.h"

void InitBossLife();
signed int StartBossLife(int code_event);
signed int StartBossLife2();
void PutBossLife();
void InitFlags();

void InitBossLife()
{
  gBL.flag = 0;
}

signed int StartBossLife(int code_event)
{
  char v1;
  int i;

  for ( i = 0; ; ++i )
  {
    v1 = i > 511 || gNPC[i].code_event == code_event ? 0 : 1;
    if ( !v1 )
      break;
  }
  if ( i == 512 )
    return 0;
  gBL.flag = 1;
  gBL.max = gNPC[i].life;
  gBL.br = gNPC[i].life;
  gBL.pLife = (int *)(172 * i + 136142240);
  return 1;
}

signed int StartBossLife2()
{
  gBL.flag = 1;
  gBL.max = unk_81CD000;
  gBL.br = unk_81CD000;
  gBL.pLife = (_DWORD *)&unk_81CD000;
  return 1;
}

void PutBossLife()
{
  RECT rcBr;
  RECT rcLife;
  RECT rcBox2;
  RECT rcBox1;
  RECT rcText;

  rcText.left = 0;
  rcText.top = 48;
  rcText.right = 32;
  rcText.bottom = 56;
  rcBox1.left = 0;
  rcBox1.top = 0;
  rcBox1.right = 244;
  rcBox1.bottom = 8;
  rcBox2.left = 0;
  rcBox2.top = 16;
  rcBox2.right = 244;
  rcBox2.bottom = 24;
  rcLife.left = 0;
  rcLife.top = 24;
  rcLife.right = 0;
  rcLife.bottom = 32;
  rcBr.left = 0;
  rcBr.top = 32;
  rcBr.right = 232;
  rcBr.bottom = 40;
  if ( gBL.flag )
  {
    if ( *gBL.pLife > 0 )
    {
      rcLife.right = 198 * *gBL.pLife / gBL.max;
      if ( gBL.br <= *gBL.pLife )
      {
        gBL.count = 0;
      }
      else if ( ++gBL.count > 30 )
      {
        --gBL.br;
      }
      rcBr.right = 198 * gBL.br / gBL.max;
      PutBitmap3(&grcGame, 32, 220, &rcBox1, 26);
      PutBitmap3(&grcGame, 32, 228, &rcBox2, 26);
      PutBitmap3(&grcGame, 72, 224, &rcBr, 26);
      PutBitmap3(&grcGame, 72, 224, &rcLife, 26);
      PutBitmap3(&grcGame, 40, 224, &rcText, 26);
    }
    else
    {
      gBL.flag = 0;
    }
  }
}

void InitFlags()
{
  memset(gFlagNPC, 0, 0x3E8u);
}

