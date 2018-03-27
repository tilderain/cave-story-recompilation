
void InitSkipFlags()
{
  memset(gSkipFlag, 0, 8u);
}

void SetNPCFlag(int a)
{
  gFlagNPC[a / 8] |= 1 << a % 8;
}

void CutNPCFlag(int a)
{
  gFlagNPC[a / 8] &= ~(1 << a % 8);
}

bool GetNPCFlag(int a)
{
  return (((signed int)gFlagNPC[a / 8] >> a % 8) & 1) != 0;
}

void SetSkipFlag(int a)
{
  gSkipFlag[a / 8] |= 1 << a % 8;
}

void CutSkipFlag(int a)
{
  gSkipFlag[a / 8] &= ~(1 << a % 8);
}

bool GetSkipFlag(int a)
{
  return (((signed int)gSkipFlag[a / 8] >> a % 8) & 1) != 0;
}

