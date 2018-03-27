
void InitTriangleTable();
int GetSin(unsigned __int8 deg);
int GetCos(unsigned __int8 deg);
int GetArktan(int x, int y);

void InitTriangleTable();
int GetSin(unsigned __int8 deg);
int GetCos(unsigned __int8 deg);
int GetArktan(int x, int y);

void InitTriangleTable()
{
  float v0;
  float a;
  float v2;
  float b;
  int i;
  int ia;

  for ( i = 0; i <= 255; ++i )
  {
    v0 = (long double)i * 6.2831998 / 256.0;
    gSin[i] = (signed int)(sinf(v0) * 512.0);
  }
  for ( ia = 0; ia <= 32; ++ia )
  {
    a = (long double)ia * 6.2831855 / 256.0;
    v2 = sinf(a);
    b = v2 / cosf(a);
    gTan[ia] = (signed __int16)(b * 8192.0);
  }
}

int GetSin(unsigned __int8 deg)
{
  return gSin[deg];
}

int GetCos(unsigned __int8 deg)
{
  return gSin[(unsigned __int8)(deg + 64)];
}

int GetArktan(int x, int y)
{
  unsigned __int8 a;
  int xa;
  int ya;

  xa = -x;
  ya = -y;
  a = 0;
  if ( xa <= 0 )
  {
    if ( ya <= 0 )
    {
      if ( -xa <= -ya )
      {
        while ( gTan[a] < (signed __int16)(-8192 * xa / -ya) )
          ++a;
        a = -64 - a;
      }
      else
      {
        while ( gTan[a] < (signed __int16)(-8192 * ya / -xa) )
          ++a;
        a += -128;
      }
    }
    else if ( -xa <= ya )
    {
      while ( gTan[a] < (signed __int16)(-8192 * xa / ya) )
        ++a;
      a += 64;
    }
    else
    {
      while ( gTan[a] < (signed __int16)((ya << 13) / -xa) )
        ++a;
      a = -128 - a;
    }
  }
  else if ( ya <= 0 )
  {
    if ( -ya >= xa )
    {
      while ( gTan[a] < (signed __int16)((xa << 13) / -ya) )
        ++a;
      a -= 64;
    }
    else
    {
      while ( gTan[a] < (signed __int16)(-8192 * ya / xa) )
        ++a;
      a = -a;
    }
  }
  else if ( xa <= ya )
  {
    while ( gTan[a] < (signed __int16)((xa << 13) / ya) )
      ++a;
    a = 64 - a;
  }
  else
  {
    while ( gTan[a] < (signed __int16)((ya << 13) / xa) )
      ++a;
  }
  return a;
}

