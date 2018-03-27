char completed_5829;
int _CTOR_LIST__ = 4294967295;
int _DTOR_LIST__[] = { 4294967295 };
_UNKNOWN _DTOR_END__;
int _JCR_LIST__ = 0;

int init_proc()
{
  int v1;

  if ( &_gmon_start__ )
    __gmon_start__();
  frame_dummy();
  _do_global_ctors_aux();
  return v1;
}


#error "8049473: positive sp value has been found (funcsize=2)"

void _do_global_dtors_aux()
{
  int v0;
  unsigned int i;

  if ( !completed_5829 )
  {
    v0 = dtor_idx_5831;
    for ( i = ((&_DTOR_END__ - (_UNKNOWN *)_DTOR_LIST__) >> 2) - 1; dtor_idx_5831 < i; v0 = dtor_idx_5831 )
    {
      dtor_idx_5831 = v0 + 1;
      ((void (*)(void))_DTOR_LIST__[v0 + 1])();
    }
    completed_5829 = 1;
  }
}




int frame_dummy()
{
  int result;

  result = _JCR_LIST__;
  if ( _JCR_LIST__ )
    result = 0;
  return result;
}


void _libc_csu_fini(void)
{
  ;
}

void _libc_csu_init(int a1, int a2, int a3)
{
  init_proc();
}

