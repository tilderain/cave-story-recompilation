
#include "sdl.h"

bool is_RECT_valid(const RECT *const r, const SDL_Surface *s);
void RECT_to_SDL_Rect(SDL_Rect *retstr, const RECT *const src, const SDL_Surface *s);
bool Flip_SystemTask(SDL_Surface *screen);
bool StartDirectDraw(SDL_Surface *screen, int magnification);
void EndDirectDraw();
void ReleaseSurface(int s);
bool MakeSurface(SDL_RWops *rw, int surf_no);
bool MakeSurface_Resource(char *name, int surf_no);
bool MakeSurface_File(char *name, int surf_no);
bool ReloadBitmap_Resource(char *name, int surf_no);
bool ReloadBitmap_File(char *name, int surf_no);
bool MakeSurface_Generic(int bxsize, int bysize, int surf_no);
void Blit(SDL_Surface *src, const RECT *const srcrect, SDL_Surface *dst, const RECT *const dstrect);
void BackupSurface(int surf_no, RECT *rect);
void PutBitmap3(RECT *rcView, int x, int y, RECT *rect, int surf_no);
void PutBitmap4(RECT *rcView, int x, int y, RECT *rect, int surf_no);
void Surface2Surface(int x, int y, RECT *rect, int to, int from);
Uint32 GetCortBoxColor(const SDL_Color *const rgb);
void Fill(const RECT *const rect, SDL_Surface *surface, Uint32 col);
void CortBox(RECT *rect, Uint32 col);
void CortBox2(RECT *rect, Uint32 col, int surf);
void InitTextObject();
void PutTextImpl(int x, int y, const char *text, const SDL_Color *const color, SDL_Surface *surface);
void PutText(int x, int y, const char *text, const SDL_Color *const color);
void PutText2(int x, int y, const char *text, const SDL_Color *const color, int surf);
void EndTextObject();

void PutFramePerSecound()
{
  ;
}

RECT grcGame = { 0, 0, 320, 240 };
RECT grcFull = { 0, 0, 320, 240 };
