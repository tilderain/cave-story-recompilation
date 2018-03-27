//#include "types.h"
#include "SDL_stdinc.h"
#include "windows_wrapper.h"
#include "Tags.h"



void ActCaret00();
void ActCaret01($4AB8D1A8A7198C298836BEA20F02E4D8 *crt);
void ActCaret02($4AB8D1A8A7198C298836BEA20F02E4D8 *crt);
void ActCaret03($4AB8D1A8A7198C298836BEA20F02E4D8 *crt);
void ActCaret04($4AB8D1A8A7198C298836BEA20F02E4D8 *crt);
void ActCaret05($4AB8D1A8A7198C298836BEA20F02E4D8 *crt);
void ActCaret07($4AB8D1A8A7198C298836BEA20F02E4D8 *crt);
void ActCaret08($4AB8D1A8A7198C298836BEA20F02E4D8 *crt);
void ActCaret09($4AB8D1A8A7198C298836BEA20F02E4D8 *crt);
void ActCaret10($4AB8D1A8A7198C298836BEA20F02E4D8 *crt);
void ActCaret11($4AB8D1A8A7198C298836BEA20F02E4D8 *crt);
void ActCaret12($4AB8D1A8A7198C298836BEA20F02E4D8 *crt);
void ActCaret13($4AB8D1A8A7198C298836BEA20F02E4D8 *crt);
void ActCaret14($4AB8D1A8A7198C298836BEA20F02E4D8 *crt);
void ActCaret15($4AB8D1A8A7198C298836BEA20F02E4D8 *crt);
void ActCaret16($4AB8D1A8A7198C298836BEA20F02E4D8 *crt);
void ActCaret17($4AB8D1A8A7198C298836BEA20F02E4D8 *crt);
void ActCaret();
void PutCaret(int fx, int fy);
void SetCaret(int x, int y, int code, int dir);

_UNKNOWN ActCaret14(CARET *)::C.4;
_UNKNOWN ActCaret11(CARET *)::C.3;
_UNKNOWN ActCaret07(CARET *)::C.2;
_UNKNOWN ActCaret05(CARET *)::C.1;
_UNKNOWN ActCaret04(CARET *)::C.0;

CARETFUNCTION gpCaretFuncTbl[18] =
{
  &ActCaret00,
  &ActCaret01,
  &ActCaret02,
  &ActCaret03,
  &ActCaret04,
  &ActCaret05,
  &ActCaret04,
  &ActCaret07,
  &ActCaret08,
  &ActCaret09,
  &ActCaret10,
  &ActCaret11,
  &ActCaret12,
  &ActCaret13,
  &ActCaret14,
  &ActCaret15,
  &ActCaret16,
  &ActCaret17
};

$B39ED6C1613C80801629116D648EBE12 gCaretTable[18] =
{
  { 0, 0 },
  { 2048, 2048 },
  { 4096, 4096 },
  { 4096, 4096 },
  { 4096, 4096 },
  { 2048, 2048 },
  { 4096, 4096 },
  { 2048, 2048 },
  { 4096, 4096 },
  { 4096, 4096 },
  { 14336, 4096 },
  { 2048, 2048 },
  { 8192, 8192 },
  { 2048, 2048 },
  { 10240, 10240 },
  { 2048, 2048 },
  { 10240, 2048 },
  { 26624, 2048 }
};

void ActCaret00()
{
  ;
}

void ActCaret01($4AB8D1A8A7198C298836BEA20F02E4D8 *crt)
{
  $4AB8D1A8A7198C298836BEA20F02E4D8 *v1;
  Sint32 *v2;
  RECT rcRight[4];
  RECT rcLeft[4];
  char v5[8];

  rcLeft[0].left = 0;
  rcLeft[0].top = 64;
  rcLeft[0].right = 8;
  rcLeft[0].bottom = 72;
  rcLeft[1].left = 8;
  rcLeft[1].top = 64;
  rcLeft[1].right = 16;
  rcLeft[1].bottom = 72;
  rcLeft[2].left = 16;
  rcLeft[2].top = 64;
  rcLeft[2].right = 24;
  rcLeft[2].bottom = 72;
  rcLeft[3].left = 24;
  rcLeft[3].top = 64;
  rcLeft[3].right = 32;
  rcLeft[3].bottom = 72;
  rcRight[0].left = 64;
  rcRight[0].top = 24;
  rcRight[0].right = 72;
  rcRight[0].bottom = 32;
  rcRight[1].left = 72;
  rcRight[1].top = 24;
  rcRight[1].right = 80;
  rcRight[1].bottom = 32;
  rcRight[2].left = 80;
  rcRight[2].top = 24;
  rcRight[2].right = 88;
  rcRight[2].bottom = 32;
  rcRight[3].left = 88;
  rcRight[3].top = 24;
  rcRight[3].right = 96;
  rcRight[3].bottom = 32;
  if ( !crt->act_no )
  {
    crt->act_no = 1;
    crt->xm = Random(-1024, 1024);
    crt->ym = Random(-1024, 0);
  }
  crt->ym += 64;
  crt->x += crt->xm;
  crt->y += crt->ym;
  if ( ++crt->ani_wait > 5 )
  {
    crt->ani_wait = 0;
    if ( ++crt->ani_no > 3 )
      crt->cond = 0;
  }
  if ( crt->direct )
  {
    v1 = crt;
    v2 = (Sint32 *)&v5[16 * crt->ani_no - 128];
  }
  else
  {
    v1 = crt;
    v2 = (Sint32 *)&v5[16 * crt->ani_no - 64];
  }
  crt->rect.left = *v2;
  v1->rect.top = v2[1];
  v1->rect.right = v2[2];
  v1->rect.bottom = v2[3];
}


void ActCaret02($4AB8D1A8A7198C298836BEA20F02E4D8 *crt)
{
  int v1;
  RECT *v2;
  RECT *v3;
  RECT *v4;
  RECT rect_right[4];
  RECT rect_left[4];
  RECT rect_up[3];

  rect_left[0].left = 0;
  rect_left[0].top = 32;
  rect_left[0].right = 16;
  rect_left[0].bottom = 48;
  rect_left[1].left = 16;
  rect_left[1].top = 32;
  rect_left[1].right = 32;
  rect_left[1].bottom = 48;
  rect_left[2].left = 32;
  rect_left[2].top = 32;
  rect_left[2].right = 48;
  rect_left[2].bottom = 48;
  rect_left[3].left = 48;
  rect_left[3].top = 32;
  rect_left[3].right = 64;
  rect_left[3].bottom = 48;
  rect_right[0].left = 176;
  rect_right[0].top = 0;
  rect_right[0].right = 192;
  rect_right[0].bottom = 16;
  rect_right[1].left = 192;
  rect_right[1].top = 0;
  rect_right[1].right = 208;
  rect_right[1].bottom = 16;
  rect_right[2].left = 208;
  rect_right[2].top = 0;
  rect_right[2].right = 224;
  rect_right[2].bottom = 16;
  rect_right[3].left = 224;
  rect_right[3].top = 0;
  rect_right[3].right = 240;
  rect_right[3].bottom = 16;
  rect_up[0].left = 0;
  rect_up[0].top = 32;
  rect_up[0].right = 16;
  rect_up[0].bottom = 48;
  rect_up[1].left = 32;
  rect_up[1].top = 32;
  rect_up[1].right = 48;
  rect_up[1].bottom = 48;
  rect_up[2].left = 16;
  rect_up[2].top = 32;
  rect_up[2].right = 32;
  rect_up[2].bottom = 48;
  v1 = crt->direct;
  switch ( v1 )
  {
    case 1:
      v4 = &rect_up[++crt->ani_wait / 2 % 3];
      crt->rect.left = v4->left;
      crt->rect.top = v4->top;
      crt->rect.right = v4->right;
      crt->rect.bottom = v4->bottom;
      if ( crt->ani_wait > 24 )
        crt->cond = 0;
      break;
    case 2:
      if ( ++crt->ani_wait > 2 )
      {
        crt->ani_wait = 0;
        ++crt->ani_no;
      }
      if ( crt->ani_no > 3 )
        crt->cond = 0;
      v3 = &rect_right[crt->ani_no];
      crt->rect.left = v3->left;
      crt->rect.top = v3->top;
      crt->rect.right = v3->right;
      crt->rect.bottom = v3->bottom;
      break;
    case 0:
      crt->ym -= 16;
      crt->y += crt->ym;
      if ( ++crt->ani_wait > 5 )
      {
        crt->ani_wait = 0;
        ++crt->ani_no;
      }
      if ( crt->ani_no > 3 )
        crt->cond = 0;
      v2 = &rect_left[crt->ani_no];
      crt->rect.left = v2->left;
      crt->rect.top = v2->top;
      crt->rect.right = v2->right;
      crt->rect.bottom = v2->bottom;
      break;
  }
}

void ActCaret03($4AB8D1A8A7198C298836BEA20F02E4D8 *crt)
{
  RECT *v1;
  RECT rect[4];

  rect[0].left = 0;
  rect[0].top = 48;
  rect[0].right = 16;
  rect[0].bottom = 64;
  rect[1].left = 16;
  rect[1].top = 48;
  rect[1].right = 32;
  rect[1].bottom = 64;
  rect[2].left = 32;
  rect[2].top = 48;
  rect[2].right = 48;
  rect[2].bottom = 64;
  rect[3].left = 48;
  rect[3].top = 48;
  rect[3].right = 64;
  rect[3].bottom = 64;
  if ( ++crt->ani_wait > 2 )
  {
    crt->ani_wait = 0;
    if ( ++crt->ani_no > 3 )
      crt->cond = 0;
  }
  v1 = &rect[crt->ani_no];
  crt->rect.left = v1->left;
  crt->rect.top = v1->top;
  crt->rect.right = v1->right;
  crt->rect.bottom = v1->bottom;
}

void ActCaret04($4AB8D1A8A7198C298836BEA20F02E4D8 *crt)
{
  Sint32 *v1;
  RECT rect[9];
  char v3[12];

  qmemcpy(rect, &ActCaret04(CARET *)::C.0, sizeof(rect));
  if ( ++crt->ani_wait > 1 )
  {
    crt->ani_wait = 0;
    if ( ++crt->ani_no > 2 )
      crt->cond = 0;
  }
  v1 = (Sint32 *)&v3[16 * (crt->ani_no + 3 * crt->direct) - 144];
  crt->rect.left = *v1;
  crt->rect.top = v1[1];
  crt->rect.right = v1[2];
  crt->rect.bottom = v1[3];
}


void ActCaret05($4AB8D1A8A7198C298836BEA20F02E4D8 *crt)
{
  Sint32 *v1;
  RECT rect[7];
  char v3[12];

  qmemcpy(rect, &ActCaret05(CARET *)::C.1, sizeof(rect));
  if ( ++crt->ani_wait > 4 )
  {
    crt->ani_wait = 0;
    ++crt->ani_no;
  }
  if ( crt->ani_no > 6 )
    crt->cond = 0;
  crt->x += 128;
  crt->y -= 128;
  v1 = (Sint32 *)&v3[16 * crt->ani_no - 112];
  crt->rect.left = *v1;
  crt->rect.top = v1[1];
  crt->rect.right = v1[2];
  crt->rect.bottom = v1[3];
}


void ActCaret07($4AB8D1A8A7198C298836BEA20F02E4D8 *crt)
{
  Sint32 *v1;
  int v2;
  RECT rcLeft[7];
  char v4[12];

  qmemcpy(rcLeft, &ActCaret07(CARET *)::C.2, sizeof(rcLeft));
  if ( ++crt->ani_wait > 1 )
  {
    crt->ani_wait = 0;
    if ( ++crt->ani_no > 6 )
      crt->cond = 0;
  }
  v1 = (Sint32 *)&v4[16 * crt->ani_no - 112];
  crt->rect.left = *v1;
  crt->rect.top = v1[1];
  crt->rect.right = v1[2];
  crt->rect.bottom = v1[3];
  v2 = crt->direct;
  if ( v2 == 1 )
  {
    crt->y -= 1024;
  }
  else if ( v2 > 1 )
  {
    if ( v2 == 2 )
    {
      crt->x += 1024;
    }
    else if ( v2 == 3 )
    {
      crt->y += 1024;
    }
  }
  else if ( !v2 )
  {
    crt->x -= 1024;
  }
}


void ActCaret08($4AB8D1A8A7198C298836BEA20F02E4D8 *crt)
{
  if ( crt->direct )
  {
    crt->rect.left = 32;
    crt->rect.top = 80;
    crt->rect.right = 48;
  }
  else
  {
    crt->rect.left = 16;
    crt->rect.top = 80;
    crt->rect.right = 32;
  }
  crt->rect.bottom = 96;
}

void ActCaret09($4AB8D1A8A7198C298836BEA20F02E4D8 *crt)
{
  if ( ++crt->ani_wait <= 4 )
    crt->y -= 2048;
  if ( crt->ani_wait == 32 )
    crt->cond = 0;
  if ( crt->direct )
  {
    crt->rect.left = 48;
    crt->rect.top = 64;
    crt->rect.right = 64;
    crt->rect.bottom = 80;
  }
  else
  {
    crt->rect.left = 0;
    crt->rect.top = 80;
    crt->rect.right = 16;
    crt->rect.bottom = 96;
  }
}

void ActCaret10($4AB8D1A8A7198C298836BEA20F02E4D8 *crt)
{
  $4AB8D1A8A7198C298836BEA20F02E4D8 *v1;
  RECT *v2;
  RECT rcRight[2];
  RECT rcLeft[2];

  rcLeft[0].left = 0;
  rcLeft[0].top = 0;
  rcLeft[0].right = 56;
  rcLeft[0].bottom = 16;
  rcLeft[1].left = 0;
  rcLeft[1].top = 16;
  rcLeft[1].right = 56;
  rcLeft[1].bottom = 32;
  rcRight[0].left = 0;
  rcRight[0].top = 96;
  rcRight[0].right = 56;
  rcRight[0].bottom = 112;
  rcRight[1].left = 0;
  rcRight[1].top = 112;
  rcRight[1].right = 56;
  rcRight[1].bottom = 128;
  ++crt->ani_wait;
  if ( crt->direct )
  {
    if ( crt->ani_wait <= 19 )
      crt->y -= 512;
    if ( crt->ani_wait == 80 )
      crt->cond = 0;
  }
  else
  {
    if ( crt->ani_wait <= 19 )
      crt->y -= 1024;
    if ( crt->ani_wait == 80 )
      crt->cond = 0;
  }
  if ( crt->direct )
  {
    v1 = crt;
    v2 = &rcRight[crt->ani_wait / 2 % 2];
  }
  else
  {
    v1 = crt;
    v2 = &rcLeft[crt->ani_wait / 2 % 2];
  }
  crt->rect.left = v2->left;
  v1->rect.top = v2->top;
  v1->rect.right = v2->right;
  v1->rect.bottom = v2->bottom;
}

void ActCaret11($4AB8D1A8A7198C298836BEA20F02E4D8 *crt)
{
  Sint32 *v1;
  RECT rcRight[7];
  unsigned __int8 deg;
  char v4[24];

  if ( !crt->act_no )
  {
    crt->act_no = 1;
    deg = Random(0, 255);
    crt->xm = 2 * GetCos(deg);
    crt->ym = 2 * GetSin(deg);
  }
  crt->x += crt->xm;
  crt->y += crt->ym;
  qmemcpy(rcRight, &ActCaret11(CARET *)::C.3, sizeof(rcRight));
  if ( ++crt->ani_wait > 2 )
  {
    crt->ani_wait = 0;
    if ( ++crt->ani_no > 6 )
      crt->cond = 0;
  }
  v1 = (Sint32 *)&v4[16 * crt->ani_no - 116];
  crt->rect.left = *v1;
  crt->rect.top = v1[1];
  crt->rect.right = v1[2];
  crt->rect.bottom = v1[3];
}


void ActCaret12($4AB8D1A8A7198C298836BEA20F02E4D8 *crt)
{
  RECT *v1;
  RECT rcLeft[2];

  rcLeft[0].left = 112;
  rcLeft[0].top = 0;
  rcLeft[0].right = 144;
  rcLeft[0].bottom = 32;
  rcLeft[1].left = 144;
  rcLeft[1].top = 0;
  rcLeft[1].right = 176;
  rcLeft[1].bottom = 32;
  if ( ++crt->ani_wait > 2 )
  {
    crt->ani_wait = 0;
    if ( ++crt->ani_no > 1 )
      crt->cond = 0;
  }
  v1 = &rcLeft[crt->ani_no];
  crt->rect.left = v1->left;
  crt->rect.top = v1->top;
  crt->rect.right = v1->right;
  crt->rect.bottom = v1->bottom;
}

void ActCaret13($4AB8D1A8A7198C298836BEA20F02E4D8 *crt)
{
  int v1;
  Sint32 *v2;
  RECT rcLeft[2];
  char v4[8];

  rcLeft[0].left = 56;
  rcLeft[0].top = 24;
  rcLeft[0].right = 64;
  rcLeft[0].bottom = 32;
  rcLeft[1].left = 0;
  rcLeft[1].top = 0;
  rcLeft[1].right = 0;
  rcLeft[1].bottom = 0;
  if ( !crt->act_no )
  {
    crt->act_no = 1;
    v1 = crt->direct;
    if ( v1 )
    {
      if ( v1 == 1 )
        crt->ym = -512 * Random(1, 3);
    }
    else
    {
      crt->xm = Random(-1536, 1536);
      crt->ym = Random(-512, 512);
    }
  }
  if ( !crt->direct )
  {
    crt->xm = 4 * crt->xm / 5;
    crt->ym = 4 * crt->ym / 5;
  }
  crt->x += crt->xm;
  crt->y += crt->ym;
  if ( ++crt->ani_wait > 20 )
    crt->cond = 0;
  v2 = (Sint32 *)&v4[16 * (crt->ani_wait / 2 % 2) - 32];
  crt->rect.left = *v2;
  crt->rect.top = v2[1];
  crt->rect.right = v2[2];
  crt->rect.bottom = v2[3];
  if ( crt->direct == 5 )
    crt->x -= 2048;
}


void ActCaret14($4AB8D1A8A7198C298836BEA20F02E4D8 *crt)
{
  Sint32 *v1;
  RECT rect[5];
  char v3[12];

  qmemcpy(rect, &ActCaret14(CARET *)::C.4, sizeof(rect));
  if ( ++crt->ani_wait > 1 )
  {
    crt->ani_wait = 0;
    if ( ++crt->ani_no > 4 )
      crt->cond = 0;
  }
  v1 = (Sint32 *)&v3[16 * crt->ani_no - 80];
  crt->rect.left = *v1;
  crt->rect.top = v1[1];
  crt->rect.right = v1[2];
  crt->rect.bottom = v1[3];
}


void ActCaret15($4AB8D1A8A7198C298836BEA20F02E4D8 *crt)
{
  RECT *v1;
  RECT rcLeft[4];

  rcLeft[0].left = 0;
  rcLeft[0].top = 72;
  rcLeft[0].right = 8;
  rcLeft[0].bottom = 80;
  rcLeft[1].left = 8;
  rcLeft[1].top = 72;
  rcLeft[1].right = 16;
  rcLeft[1].bottom = 80;
  rcLeft[2].left = 16;
  rcLeft[2].top = 72;
  rcLeft[2].right = 24;
  rcLeft[2].bottom = 80;
  rcLeft[3].left = 24;
  rcLeft[3].top = 72;
  rcLeft[3].right = 32;
  rcLeft[3].bottom = 80;
  if ( ++crt->ani_wait > 2 )
  {
    crt->ani_wait = 0;
    if ( ++crt->ani_no > 3 )
      crt->cond = 0;
  }
  v1 = &rcLeft[crt->ani_no];
  crt->rect.left = v1->left;
  crt->rect.top = v1->top;
  crt->rect.right = v1->right;
  crt->rect.bottom = v1->bottom;
}

void ActCaret16($4AB8D1A8A7198C298836BEA20F02E4D8 *crt)
{
  RECT *v1;
  RECT rcLeft[2];

  rcLeft[0].left = 104;
  rcLeft[0].top = 96;
  rcLeft[0].right = 144;
  rcLeft[0].bottom = 104;
  rcLeft[1].left = 104;
  rcLeft[1].top = 104;
  rcLeft[1].right = 144;
  rcLeft[1].bottom = 112;
  if ( ++crt->ani_wait <= 9 )
    crt->y -= 1024;
  if ( crt->ani_wait == 40 )
    crt->cond = 0;
  v1 = &rcLeft[crt->ani_wait / 2 % 2];
  crt->rect.left = v1->left;
  crt->rect.top = v1->top;
  crt->rect.right = v1->right;
  crt->rect.bottom = v1->bottom;
}

void ActCaret17($4AB8D1A8A7198C298836BEA20F02E4D8 *crt)
{
  if ( ++crt->ani_wait > 39 )
    crt->ani_wait = 0;
  if ( crt->ani_wait > 29 )
  {
    crt->rect.left = 0;
    crt->rect.top = 0;
    crt->rect.right = 0;
    crt->rect.bottom = 0;
  }
  else
  {
    crt->rect.left = 0;
    crt->rect.top = 144;
    crt->rect.right = 144;
    crt->rect.bottom = 152;
  }
}

void ActCaret()
{
  int i;

  for ( i = 0; i <= 63; ++i )
  {
    if ( gCrt[i].cond & 0x80 )
      ((void (__cdecl *)())gpCaretFuncTbl[gCrt[i].code])();
  }
}

void PutCaret(int fx, int fy)
{
  __int64 v2;
  int i;

  for ( i = 0; i <= 63; ++i )
  {
    if ( gCrt[i].cond & 0x80 )
    {
      v2 = gCrt[i].y - gCrt[i].view_top;
      PutBitmap3(
        &grcGame,
        (gCrt[i].x - gCrt[i].view_left) / 512 - fx / 512,
        ((signed int)((HIDWORD(v2) >> 23) + v2) >> 9) - fy / 512,
        (RECT *)(68 * i + 136101268),
        19);
    }
  }
}

void SetCaret(int x, int y, int code, int dir)
{
  int c;

  for ( c = 0; c <= 63 && gCrt[c].cond; ++c )
    ;
  if ( c != 64 )
  {
    memset((void *)(68 * c + 136101216), 0, 0x44u);
    gCrt[c].cond = 128;
    gCrt[c].code = code;
    gCrt[c].x = x;
    gCrt[c].y = y;
    gCrt[c].view_left = gCaretTable[code].view_left;
    gCrt[c].view_top = gCaretTable[code].view_top;
    gCrt[c].direct = dir;
  }
}

