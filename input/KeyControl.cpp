


int GetTrg(void)::_key_old;

void GetTrg()
{
  gKeyTrg = gKey & (gKey ^ GetTrg(void)::_key_old);
  GetTrg(void)::_key_old = gKey;
}

