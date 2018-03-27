#include "stddef.h"
//#include "types.h"
#include "stdio.h"
//#include "libio.h"
//#include "types.h"
#include "stdint.h"
#include "SDL_stdinc.h"
#include "SDL_rwops.h"
#include "SDL_video.h"
#include "windows_wrapper.h"
#include "Draw.h"

int magnification = 1;

bool is_RECT_valid(const RECT *const r, const SDL_Surface *s)
{
  return r->right >= 0
      && r->bottom >= 0
      && r->right >= r->left
      && r->bottom >= r->top
      && r->left < s->w * magnification
      && r->top < s->h * magnification;
}

void RECT_to_SDL_Rect(SDL_Rect *retstr, const RECT *const src, const SDL_Surface *s)
{
  int x;
  int y;
  unsigned int w;
  unsigned int h;

  x = src->left * magnification;
  y = src->top * magnification;
  w = (src->right - src->left) * magnification;
  h = (src->bottom - src->top) * magnification;
  *(_DWORD *)&retstr->x = 0;                    // TODO: More memsets
  *(_DWORD *)&retstr->w = 0;                    // These can just be removed since they get written to
  retstr->x = x;
  retstr->y = y;
  retstr->w = w;
  retstr->h = h;
}

bool Flip_SystemTask(SDL_Surface *screen)
{
  Uint32 current_time;
  Uint32 next_time;

  if ( !`guard variable for'Flip_SystemTask(SDL_Surface *)::previous_time// TODO: WTF
    && __cxa_guard_acquire(&`guard variable for'Flip_SystemTask(SDL_Surface *)::previous_time) != 0 )
  {
    Flip_SystemTask(SDL_Surface *)::previous_time = SDL_GetTicks();
    __cxa_guard_release(&`guard variable for'Flip_SystemTask(SDL_Surface *)::previous_time);
  }
  current_time = SDL_GetTicks();
  next_time = Flip_SystemTask(SDL_Surface *)::previous_time + 20;
  if ( current_time >= Flip_SystemTask(SDL_Surface *)::previous_time + 20 )
  {
    Flip_SystemTask(SDL_Surface *)::previous_time = current_time;
  }
  else
  {
    while ( current_time < next_time )
    {
      SDL_Delay(1);
      current_time = SDL_GetTicks();
    }
    Flip_SystemTask(SDL_Surface *)::previous_time = next_time;
  }
  SDL_Flip(screen);
  return SystemTask() == 1;                     // TODO: This is dumb
}






bool StartDirectDraw(SDL_Surface *screen, int magnification)
{
  const SDL_Rect clip;
  const int w;
  const int h;

  ::screen = screen;
  ::magnification = magnification;
  w = screen->w / magnification;
  h = screen->h / magnification;
  x_offset = (w - 320) / 2;
  y_offset = (h - 240) / 2;
  clip.x = (w - 320) / 2 * magnification;
  clip.y = (h - 240) / 2 * magnification;
  clip.w = 320 * magnification;
  clip.h = 240 * magnification;
  SDL_SetClipRect(screen, &clip);
  return 1;
}


void EndDirectDraw()
{
  int i;

  for ( i = 0; i <= 39; ++i )
  {
    if ( _surf_S[i] )
    {
      SDL_FreeSurface(_surf_S[i]);
      _surf_S[i] = 0;
    }
  }
}


void ReleaseSurface(int s)
{
  if ( _surf_S[s] )
  {
    SDL_FreeSurface(_surf_S[s]);
    _surf_S[s] = 0;
  }
}


bool MakeSurface(SDL_RWops *rw, int surf_no)
{
  int v3;
  int v4;
  Uint32 v5;
  SDL_Surface *v6;
  SDL_Rect dstrect;
  SDL_Rect srcrect;
  SDL_Surface *unscaled;
  SDL_Surface *scaled;
  SDL_Surface **const display_format;

  if ( surf_no > 40 )
  {
    ErrorLog("surface no", surf_no);
    return 0;
  }
  if ( _surf_S[surf_no] )
  {
    ErrorLog("existing", surf_no);
    return 0;
  }
  unscaled = SDL_LoadBMP_RW(rw, 1);
  if ( !unscaled )
  {
    ErrorLog("path", 1);
    return 0;
  }
  if ( magnification == 1 )
  {
    scaled = unscaled;
    ++unscaled->refcount;
  }
  else
  {
    scaled = SDL_CreateRGBSurface(
               4096,
               unscaled->w * magnification,
               magnification * unscaled->h,     // TODO: Lawl
               unscaled->format->BitsPerPixel,
               unscaled->format->Rmask,
               unscaled->format->Gmask,
               unscaled->format->Bmask,
               unscaled->format->Amask);
    if ( !scaled )
    {
      ErrorLog("scale", 0);
      return 0;
    }
    v3 = *(_DWORD *)&unscaled->clip_rect.w;     // TODO: Annoying optimisation. It's just a struct-to-struct copy
    *(_DWORD *)&srcrect.x = *(_DWORD *)&unscaled->clip_rect.x;
    *(_DWORD *)&srcrect.w = v3;
    v4 = *(_DWORD *)&scaled->clip_rect.w;
    *(_DWORD *)&dstrect.x = *(_DWORD *)&scaled->clip_rect.x;
    *(_DWORD *)&dstrect.w = v4;
    SDL_SoftStretch(unscaled, &srcrect, scaled, &dstrect);
    SDL_SetColors(scaled, unscaled->format->palette->colors, 0, unscaled->format->palette->ncolors);
  }
  SDL_FreeSurface(unscaled);
  unscaled = 0;
  v5 = SDL_MapRGB(scaled->format, 0, 0, 0);
  SDL_SetColorKey(scaled, 4096, v5);
  display_format = &_surf_S[surf_no];
  v6 = SDL_DisplayFormat(scaled);
  *display_format = v6;
  SDL_FreeSurface(scaled);
  return 1;
}





bool MakeSurface_Resource(char *name, int surf_no)
{
  SDL_RWops *v2;

  v2 = open_resource(name);
  return MakeSurface(v2, surf_no);
}

bool MakeSurface_File(char *name, int surf_no)
{
  bool result;
  SDL_RWops *v3;
  char path[260];

  sprintf(path, "%s/%s.pbm", gDataPath, name);
  if ( !IsEnableBitmap(path) )
  {
    ErrorLog(path, 0);
    result = 0;
  }
  else
  {
    v3 = SDL_RWFromFile(path, "rb");
    result = MakeSurface(v3, surf_no);
  }
  return result;
}

bool ReloadBitmap_Resource(char *name, int surf_no)
{
  ReleaseSurface(surf_no);
  return MakeSurface_Resource(name, surf_no);
}

bool ReloadBitmap_File(char *name, int surf_no)
{
  ReleaseSurface(surf_no);
  return MakeSurface_File(name, surf_no);
}

bool MakeSurface_Generic(int bxsize, int bysize, int surf_no)
{
  Uint32 v4;
  SDL_Surface *surface;

  surface = SDL_CreateRGBSurface(
              4096,
              bxsize * magnification,
              bysize * magnification,
              screen->format->BitsPerPixel,
              screen->format->Rmask,
              screen->format->Gmask,
              screen->format->Bmask,
              screen->format->Amask);
  if ( !surface )
    return 0;
  v4 = SDL_MapRGB(surface->format, 0, 0, 0);
  SDL_SetColorKey(surface, 4096, v4);
  _surf_S[surf_no] = SDL_DisplayFormat(surface);
  SDL_FreeSurface(surface);
  return 1;
}



void Blit(SDL_Surface *src, const RECT *const srcrect, SDL_Surface *dst, const RECT *const dstrect)
{
  bool v4;
  SDL_Rect dstrect2;
  SDL_Rect srcrect2;

  v4 = is_RECT_valid(srcrect, src) && is_RECT_valid(dstrect, dst);
  if ( v4 )
  {
    RECT_to_SDL_Rect(&srcrect2, srcrect, src);
    RECT_to_SDL_Rect(&dstrect2, dstrect, dst);
    SDL_UpperBlit(src, &srcrect2, dst, &dstrect2);
  }
}


void BackupSurface(int surf_no, RECT *rect)
{
  const RECT srcrect;

  srcrect.left = 0;
  srcrect.top = 0;
  srcrect.right = 0;
  srcrect.bottom = 0;
  srcrect.left = rect->left + x_offset;
  srcrect.top = rect->top + y_offset;
  srcrect.right = rect->right + x_offset;
  srcrect.bottom = rect->bottom + y_offset;
  Blit(screen, &srcrect, _surf_S[surf_no], rect);
}

void PutBitmap3(RECT *rcView, int x, int y, RECT *rect, int surf_no)
{
  RECT rcSet;
  RECT rcWork;
  SDL_Surface *surface;

  rcWork.left = rect->left;
  rcWork.top = rect->top;
  rcWork.right = rect->right;
  rcWork.bottom = rect->bottom;
  if ( x + rect->right - rect->left > rcView->right )
    rcWork.right += rcView->right + rect->left - (x + rect->right);
  if ( rcView->left > x )
  {
    rcWork.left += rcView->left - x;
    x = rcView->left;
  }
  if ( y + rect->bottom - rect->top > rcView->bottom )
    rcWork.bottom += rcView->bottom + rect->top - (y + rect->bottom);
  if ( rcView->top > y )
  {
    rcWork.top += rcView->top - y;
    y = rcView->top;
  }
  rcSet.left = x + x_offset;
  rcSet.top = y + y_offset;
  rcSet.right = rcWork.right + x + x_offset - rcWork.left;
  rcSet.bottom = rcWork.bottom + y + y_offset - rcWork.top;
  surface = _surf_S[surf_no];
  if ( surface )
    Blit(surface, &rcWork, screen, &rcSet);
}

void PutBitmap4(RECT *rcView, int x, int y, RECT *rect, int surf_no)
{
  PutBitmap3(rcView, x, y, rect, surf_no);
}

void Surface2Surface(int x, int y, RECT *rect, int to, int from)
{
  RECT rcSet;

  rcSet.left = x;
  rcSet.top = y;
  rcSet.right = x + rect->right - rect->left;
  rcSet.bottom = y + rect->bottom - rect->top;
  Blit(_surf_S[from], rect, _surf_S[to], &rcSet);
}

Uint32 GetCortBoxColor(const SDL_Color *const rgb)
{
  return SDL_MapRGB(screen->format, rgb->r, rgb->g, rgb->b);
}

void Fill(const RECT *const rect, SDL_Surface *surface, Uint32 col)
{
  SDL_Rect dstrect;

  if ( is_RECT_valid(rect, surface) )
  {
    RECT_to_SDL_Rect(&dstrect, rect, surface);
    SDL_FillRect(surface, &dstrect, col);
  }
}


void CortBox(RECT *rect, Uint32 col)
{
  const RECT dstrect;

  dstrect.left = 0;
  dstrect.top = 0;
  dstrect.right = 0;
  dstrect.bottom = 0;
  dstrect.left = rect->left + x_offset;
  dstrect.top = rect->top + y_offset;
  dstrect.right = rect->right + x_offset;
  dstrect.bottom = rect->bottom + y_offset;
  Fill(&dstrect, screen, col);
}

void CortBox2(RECT *rect, Uint32 col, int surf)
{
  Fill(rect, _surf_S[surf], col);
}

void InitTextObject()
{
  SDL_RWops *v0;
  SDL_Surface *v1;
  Uint32 v2;
  char font_name[128];

  memset(font_name, 0, sizeof(font_name));
  sprintf(font_name, "font_en_%d", magnification);
  v0 = open_resource(font_name);
  v1 = SDL_LoadBMP_RW(v0, 1);
  font = v1;
  v2 = SDL_MapRGB(v1->format, 0, 0, 0);
  SDL_SetColorKey(font, 4096, v2);
}


void PutTextImpl(int x, int y, const char *text, const SDL_Color *const color, SDL_Surface *surface)
{
  Sint16 v5;
  SDL_Color palette[256];
  SDL_Rect dstrect;
  SDL_Rect srcrect;
  const Uint16 src_char_size;
  const Sint16 dst_char_width;
  const Sint16 dst_char_height;
  const unsigned __int8 *c;
  Sint16 dst_x;
  const Sint16 dst_y;
  Sint16 space_width;
  size_t i;
  const Sint16 src_x;
  const Sint16 src_y;

  if ( font && surface )
  {
    for ( i = 0; i <= 0xFF; ++i )
    {
      palette[i].r = i * color->r / 0xFF;
      palette[i].g = i * color->g / 0xFF;
      palette[i].b = i * color->b / 0xFF;
      palette[i].unused = i;
    }
    SDL_SetColors(font, palette, 0, 256);
    src_char_size = 8 * magnification;
    dst_char_width = 6 * magnification;
    dst_char_height = 12 * magnification;
    c = (const unsigned __int8 *)text;
    dst_x = magnification * x                   // TODO: WTF
          - ((((unsigned __int16)(8 * magnification) < (signed int)(signed __int16)(6 * magnification))
            + (unsigned __int16)(8 * magnification)
            - (signed int)(signed __int16)(6 * magnification)) >> 1);
    dst_y = magnification * y
          - ((((unsigned __int16)(8 * magnification) < (signed int)(signed __int16)(12 * magnification))
            + (unsigned __int16)(8 * magnification)
            - (signed int)(signed __int16)(12 * magnification)) >> 1);
    space_width = 9 * magnification / 2;
    if ( magnification == 1 )
      space_width = 5;
    while ( *c )
    {
      src_x = src_char_size * (*c & 0xF);
      src_y = src_char_size * (*c >> 4);
      srcrect.x = src_x;
      srcrect.y = src_y;
      srcrect.w = src_char_size;
      srcrect.h = src_char_size;
      dstrect.x = dst_x;
      dstrect.y = dst_y;
      dstrect.w = src_char_size;
      dstrect.h = src_char_size;
      SDL_UpperBlit(font, &srcrect, surface, &dstrect);
      if ( *c == 32 )
      {
        dst_x += space_width;
        if ( magnification == 1 )
        {
          if ( space_width == 4 )
            v5 = 5;
          else
            v5 = 4;
          space_width = v5;
        }
      }
      else
      {
        dst_x += dst_char_width;
      }
      ++c;
    }
  }
}



void PutText(int x, int y, const char *text, const SDL_Color *const color)
{
  PutTextImpl(x + x_offset, y + y_offset, text, color, screen);
}

void PutText2(int x, int y, const char *text, const SDL_Color *const color, int surf)
{
  PutTextImpl(x, y, text, color, _surf_S[surf]);
}

void EndTextObject()
{
  if ( font )
  {
    SDL_FreeSurface(font);
    font = 0;
  }
}


