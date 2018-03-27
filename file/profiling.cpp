#include "stdint.h"
#include "SDL_stdinc.h"
#include "profiling.h"

void scoped_profile::scoped_profile(scoped_profile *const this, const char *id);
void scoped_profile::scoped_profile(scoped_profile *const this, const char *id);
void scoped_profile::~scoped_profile(scoped_profile *const this);
void scoped_profile::~scoped_profile(scoped_profile *const this);
void scoped_profile::~scoped_profile(scoped_profile *const this);

_DWORD (__cdecl *off_81454D8[2])(scoped_profile *this) = { &scoped_profile::~scoped_profile, &scoped_profile::~scoped_profile };


void scoped_profile::scoped_profile(scoped_profile *const this, const char *id)
{
  this->_vptr.scoped_profile = (int (**)(...))off_81454D8;
  this->id = id;
  this->start = SDL_GetTicks();
}



void scoped_profile::~scoped_profile(scoped_profile *const this)
{
  int v1;

  this->_vptr.scoped_profile = (int (**)(...))off_81454D8;
  v1 = SDL_GetTicks();
  ErrorLog(this->id, v1 - this->start);
}



void scoped_profile::~scoped_profile(scoped_profile *const this)
{
  int v1;

  this->_vptr.scoped_profile = (int (**)(...))off_81454D8;
  v1 = SDL_GetTicks();
  ErrorLog(this->id, v1 - this->start);
}



void scoped_profile::~scoped_profile(scoped_profile *const this)
{
  int v1;

  this->_vptr.scoped_profile = (int (**)(...))off_81454D8;
  v1 = SDL_GetTicks();
  ErrorLog(this->id, v1 - this->start);
  operator delete(this);
}

// No idea what this crap is
void scoped_profile::scoped_profile(scoped_profile *const this, const char *id)
{
  this->_vptr.scoped_profile = (int (**)(...))off_81454D8;
  this->id = id;
  this->start = SDL_GetTicks();
}
