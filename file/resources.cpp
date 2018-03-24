#include "types.h"
#include "stddef.h"
#include "stdio.h"
#include "libio.h"
#include "stdint.h"
#include "SDL_stdinc.h"
#include "SDL_rwops.h"
#include "Credit01.h"
#include "Credit02.h"
#include "Credit03.h"
#include "Credit04.h"
#include "Credit05.h"
#include "Credit06.h"
#include "Credit07.h"
#include "Credit08.h"
#include "Credit09.h"
#include "Credit10.h"
#include "Credit11.h"
#include "Credit12.h"
#include "Credit14.h"
#include "Credit15.h"
#include "Credit16.h"
#include "Credit17.h"
#include "Credit18.h"
#include "font_en_1.h"
#include "font_en_2.h"
#include "pixel.h"
#include "Access.h"
#include "Anzen.h"
#include "Balcony.h"
#include "Ballos.h"
#include "BreakDown.h"
#include "Cemetery.h"
#include "Curly.h"
#include "Dr.h"
#include "Ending.h"
#include "Escape.h"
#include "Fanfale1.h"
#include "Fanfale2.h"
#include "Fanfale3.h"
#include "FireEye.h"
#include "Gameover.h"
#include "Ginsuke.h"
#include "Grand.h"
#include "Gravity.h"
#include "Hell.h"
#include "ironH.h"
#include "Jenka2.h"
#include "Jenka.h"
#include "Kodou.h"
#include "LastBtl3.h"
#include "LastBtl.h"
#include "LastCave.h"
#include "Marine.h"
#include "Maze.h"
#include "MDown2.h"
#include "Mura.h"
#include "NewData.h"
#include "Oside.h"
#include "Plant.h"
#include "quiet.h"
#include "Requiem.h"
#include "Toroko.h"
#include "Vivi.h"
#include "Wanpak2.h"
#include "Wanpaku.h"
#include "Weed.h"
#include "White.h"
#include "XXXX.h"
#include "Zonbie.h"
#include "Wave.h"
char *__cdecl get_resource(const char *name, int *size)
{
  char *result;

  *size = 0;
  if ( !strcmp(name, "Credit01") )
  {
    *size = size_Credit01;
    result = (char *)Credit01;
  }
  else if ( !strcmp(name, "Credit02") )
  {
    *size = size_Credit02;
    result = (char *)Credit02;
  }
  else if ( !strcmp(name, "Credit03") )
  {
    *size = size_Credit03;
    result = (char *)Credit03;
  }
  else if ( !strcmp(name, "Credit04") )
  {
    *size = size_Credit04;
    result = (char *)Credit04;
  }
  else if ( !strcmp(name, "Credit05") )
  {
    *size = size_Credit05;
    result = (char *)Credit05;
  }
  else if ( !strcmp(name, "Credit06") )
  {
    *size = size_Credit06;
    result = (char *)Credit06;
  }
  else if ( !strcmp(name, "Credit07") )
  {
    *size = size_Credit07;
    result = (char *)Credit07;
  }
  else if ( !strcmp(name, "Credit08") )
  {
    *size = size_Credit08;
    result = (char *)Credit08;
  }
  else if ( !strcmp(name, "Credit09") )
  {
    *size = size_Credit09;
    result = (char *)Credit09;
  }
  else if ( !strcmp(name, "Credit10") )
  {
    *size = size_Credit10;
    result = (char *)Credit10;
  }
  else if ( !strcmp(name, "Credit11") )
  {
    *size = size_Credit11;
    result = (char *)Credit11;
  }
  else if ( !strcmp(name, "Credit12") )
  {
    *size = size_Credit12;
    result = (char *)Credit12;
  }
  else if ( !strcmp(name, "Credit14") )
  {
    *size = size_Credit14;
    result = (char *)Credit14;
  }
  else if ( !strcmp(name, "Credit15") )
  {
    *size = size_Credit15;
    result = (char *)Credit15;
  }
  else if ( !strcmp(name, "Credit16") )
  {
    *size = size_Credit16;
    result = (char *)Credit16;
  }
  else if ( !strcmp(name, "Credit17") )
  {
    *size = size_Credit17;
    result = (char *)Credit17;
  }
  else if ( !strcmp(name, "Credit18") )
  {
    *size = size_Credit18;
    result = (char *)Credit18;
  }
  else if ( !strcmp(name, "font_en_1") )
  {
    *size = size_font_en_1;
    result = (char *)font_en_1;
  }
  else if ( !strcmp(name, "font_en_2") )
  {
    *size = size_font_en_2;
    result = (char *)font_en_2;
  }
  else if ( !strcmp(name, "pixel") )
  {
    *size = size_pixel;
    result = (char *)pixel;
  }
  else if ( !strcmp(name, "Access") )
  {
    *size = 1138;
    result = Access;
  }
  else if ( !strcmp(name, "Anzen") )
  {
    *size = 9194;
    result = Anzen;
  }
  else if ( !strcmp(name, "Balcony") )
  {
    *size = 3082;
    result = Balcony;
  }
  else if ( !strcmp(name, "Ballos") )
  {
    *size = 3570;
    result = Ballos;
  }
  else if ( !strcmp(name, "BreakDown") )
  {
    *size = 2570;
    result = BreakDown;
  }
  else if ( !strcmp(name, "Cemetery") )
  {
    *size = 4578;
    result = Cemetery;
  }
  else if ( !strcmp(name, "Curly") )
  {
    *size = 25738;
    result = Curly;
  }
  else if ( !strcmp(name, "Dr") )
  {
    *size = 2162;
    result = Dr;
  }
  else if ( !strcmp(name, "Ending") )
  {
    *size = 17898;
    result = Ending;
  }
  else if ( !strcmp(name, "Escape") )
  {
    *size = 7618;
    result = Escape;
  }
  else if ( !strcmp(name, "Fanfale1") )
  {
    *size = 914;
    result = Fanfale1;
  }
  else if ( !strcmp(name, "Fanfale2") )
  {
    *size = 922;
    result = Fanfale2;
  }
  else if ( !strcmp(name, "Fanfale3") )
  {
    *size = 1074;
    result = Fanfale3;
  }
  else if ( !strcmp(name, "FireEye") )
  {
    *size = 21354;
    result = FireEye;
  }
  else if ( !strcmp(name, "Gameover") )
  {
    *size = 1138;
    result = Gameover;
  }
  else if ( !strcmp(name, "Ginsuke") )
  {
    *size = 5970;
    result = Ginsuke;
  }
  else if ( !strcmp(name, "Grand") )
  {
    *size = 13466;
    result = Grand;
  }
  else if ( !strcmp(name, "Gravity") )
  {
    *size = 20578;
    result = Gravity;
  }
  else if ( !strcmp(name, "Hell") )
  {
    *size = 18386;
    result = Hell;
  }
  else if ( !strcmp(name, "ironH") )
  {
    *size = 13450;
    result = ironH;
  }
  else if ( !strcmp(name, "Jenka2") )
  {
    *size = 11986;
    result = Jenka2;
  }
  else if ( !strcmp(name, "Jenka") )
  {
    *size = 8306;
    result = Jenka;
  }
  else if ( !strcmp(name, "Kodou") )
  {
    *size = 10418;
    result = Kodou;
  }
  else if ( !strcmp(name, "LastBtl3") )
  {
    *size = 21122;
    result = LastBtl3;
  }
  else if ( !strcmp(name, "LastBtl") )
  {
    *size = 2770;
    result = LastBtl;
  }
  else if ( !strcmp(name, "LastCave") )
  {
    *size = 18122;
    result = LastCave;
  }
  else if ( !strcmp(name, "Marine") )
  {
    *size = 16962;
    result = Marine;
  }
  else if ( !strcmp(name, "Maze") )
  {
    *size = 14786;
    result = Maze;
  }
  else if ( !strcmp(name, "MDown2") )
  {
    *size = 21074;
    result = MDown2;
  }
  else if ( !strcmp(name, "Mura") )
  {
    *size = 10634;
    result = Mura;
  }
  else if ( !strcmp(name, "NewData") )
  {
    *size = 3018;
    result = NewData;
  }
  else if ( !strcmp(name, "Oside") )
  {
    *size = 25634;
    result = Oside;
  }
  else if ( !strcmp(name, "Plant") )
  {
    *size = 11378;
    result = Plant;
  }
  else if ( !strcmp(name, "quiet") )
  {
    *size = 4770;
    result = quiet;
  }
  else if ( !strcmp(name, "Requiem") )
  {
    *size = 9722;
    result = Requiem;
  }
  else if ( !strcmp(name, "Toroko") )
  {
    *size = 18482;
    result = Toroko;
  }
  else if ( !strcmp(name, "Vivi") )
  {
    *size = 10458;
    result = Vivi;
  }
  else if ( !strcmp(name, "Wanpak2") )
  {
    *size = 15994;
    result = Wanpak2;
  }
  else if ( !strcmp(name, "Wanpaku") )
  {
    *size = 19626;
    result = Wanpaku;
  }
  else if ( !strcmp(name, "Weed") )
  {
    *size = 23706;
    result = Weed;
  }
  else if ( !strcmp(name, "White") )
  {
    *size = 23714;
    result = White;
  }
  else if ( !strcmp(name, "XXXX") )
  {
    *size = 114;
    result = XXXX;
  }
  else if ( !strcmp(name, "Zonbie") )
  {
    *size = 5346;
    result = Zonbie;
  }
  else if ( !strcmp(name, "Wave") )
  {
    *size = 25600;
    result = Wave;
  }
  else
  {
    fprintf(stderr, "Unmapped resource %s!\n", name);
    result = 0;
  }
  return result;
}

SDL_RWops_0 *__cdecl open_resource(const char *name)
{
  SDL_RWops_0 *result;
  int size;
  const void *const mem;

  size = 0;
  mem = get_resource(name, &size);
  if ( mem )
    result = SDL_RWFromConstMem(mem, size);
  else
    result = 0;
  return result;
}

