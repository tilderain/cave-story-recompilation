#include "stdint.h"
#include "SDL_stdinc.h"
#include "profiling.h"
void __cdecl scoped_profile::scoped_profile(scoped_profile *const this, const char *id)
{
  this->_vptr.scoped_profile = (int (**)(...))off_81454D8;
  this->id = id;
  this->start = SDL_GetTicks();
}



void __cdecl scoped_profile::~scoped_profile(scoped_profile *const this)
{
  int v1;

  this->_vptr.scoped_profile = (int (**)(...))off_81454D8;
  v1 = SDL_GetTicks();
  ErrorLog(this->id, v1 - this->start);
}



void __cdecl scoped_profile::~scoped_profile(scoped_profile *const this)
{
  int v1;

  this->_vptr.scoped_profile = (int (**)(...))off_81454D8;
  v1 = SDL_GetTicks();
  ErrorLog(this->id, v1 - this->start);
}



void __cdecl scoped_profile::~scoped_profile(scoped_profile *const this)
{
  int v1;

  this->_vptr.scoped_profile = (int (**)(...))off_81454D8;
  v1 = SDL_GetTicks();
  ErrorLog(this->id, v1 - this->start);
  operator delete(this);
}



