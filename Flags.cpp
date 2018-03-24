void InitSkipFlags()
{
  memset(gSkipFlag, 0, 8u);
}

void __cdecl SetNPCFlag(int a)
{
  gFlagNPC[a / 8] |= 1 << a % 8;
}

void __cdecl CutNPCFlag(int a)
{
  gFlagNPC[a / 8] &= ~(1 << a % 8);
}

_BOOL4 __cdecl GetNPCFlag(int a)
{
  return (((signed int)gFlagNPC[a / 8] >> a % 8) & 1) != 0;
}

void __cdecl SetSkipFlag(int a)
{
  gSkipFlag[a / 8] |= 1 << a % 8;
}

void __cdecl CutSkipFlag(int a)
{
  gSkipFlag[a / 8] &= ~(1 << a % 8);
}

_BOOL4 __cdecl GetSkipFlag(int a)
{
  return (((signed int)gSkipFlag[a / 8] >> a % 8) & 1) != 0;
}

