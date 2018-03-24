#include "stddef.h"
#include "types.h"
#include "types.h"
#include "stdio.h"
#include "libio.h"
#include "stdint.h"
#include "SDL_stdinc.h"
#include "SDL_rwops.h"
#include "Config.h"
#include "windows_wrapper.h"

bool __cdecl LoadConfigData($88CD5C1514A19B01CE178CB8EAE44D15 *conf);
void __cdecl map_button($88CD5C1514A19B01CE178CB8EAE44D15 *conf, size_t index, Sint32 action);
void __cdecl DefaultConfigData($88CD5C1514A19B01CE178CB8EAE44D15 *conf);


bool __cdecl LoadConfigData($88CD5C1514A19B01CE178CB8EAE44D15 *conf)
{
  int v2;
  char path[260];
  SDL_RWops_0 *fp;
  int button;

  memset(conf, 0, 0x94u);
  sprintf(path, "%s/%s", gModulePath, "Config.dat");
  fp = SDL_RWFromFile(path, "rb");
  if ( !fp )
    return 0;
  fp->read(fp, conf, 32, 1);
  fp->read(fp, conf->font_name, 64, 1);
  conf->move_button_mode = SDL_ReadLE32(fp);
  conf->attack_button_mode = SDL_ReadLE32(fp);
  conf->ok_button_mode = SDL_ReadLE32(fp);
  conf->display_mode = SDL_ReadLE32(fp);
  conf->bJoystick = SDL_ReadLE32(fp);
  for ( button = 0; button <= 7; ++button )
  {
    v2 = button;
    *(_DWORD *)&conf->proof[4 * (v2 + 28) + 4] = SDL_ReadLE32(fp);
  }
  fp->close(fp);
  if ( !strcmp(conf->proof, "DOUKUTSU20041206") )
    return 1;
  memset(conf, 0, 0x94u);
  return 0;
}


void __cdecl map_button($88CD5C1514A19B01CE178CB8EAE44D15 *conf, size_t index, Sint32 action)
{
  *(_DWORD *)&conf->proof[4 * (index + 28) + 4] = action;
}

void __cdecl DefaultConfigData($88CD5C1514A19B01CE178CB8EAE44D15 *conf)
{
  memset(conf, 0, 0x94u);
  conf->display_mode = 1;
  conf->bJoystick = 1;
  map_button(conf, 0, 2);
  map_button(conf, 1u, 1);
  map_button(conf, 2u, 5);
  map_button(conf, 3u, 6);
  map_button(conf, 4u, 3);
  map_button(conf, 5u, 4);
  map_button(conf, 6u, 6);
  map_button(conf, 7u, 3);
}

