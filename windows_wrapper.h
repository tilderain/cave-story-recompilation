void __cdecl RGB(SDL_Color_0 *retstr, Uint8 r, Uint8 g, Uint8 b)
{
  *retstr = 0;                                  // TODO: More of a memset 0 of the SDL_Color struct
  retstr->unused = -1;
  retstr->r = r;
  retstr->g = g;
  retstr->b = b;
}

void __cdecl RGB(SDL_Color_0 *retstr, Uint8 r, Uint8 g, Uint8 b)
{
  *retstr = 0;                                  // TODO: Kill
  retstr->unused = -1;
  retstr->r = r;
  retstr->g = g;
  retstr->b = b;
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

