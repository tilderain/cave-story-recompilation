void ChangeOrganFrequency(Uint8 key, Sint8 track, Uint32 a);
void ChangeOrganPan(Uint8 key, Uint8 pan, Sint8 track);
void ChangeOrganVolume(int no, int volume, Sint8 track);
void PlayOrganObject(Uint8 key, int mode, Sint8 track, Uint32 freq);
void ReleaseOrganyaObject(Sint8 track);
signed int InitWaveData100();
signed int MakeOrganyaWave(char track, char wave_no);
void ChangeDramFrequency(unsigned __int8 key, char track);
void ChangeDramPan(unsigned __int8 pan, char track);
void ChangeDramVolume(int volume, char track);
void PlayDramObject(unsigned __int8 key, int mode, char track);
signed int StartOrganya();
signed int LoadOrganya(char *path);
void SetOrganyaPosition(Sint32 x);
Uint32 GetOrganyaPosition();
void PlayOrganyaMusic();
signed int ChangeOrganyaVolume(int vol);
void StopOrganyaMusic();
void SetOrganyaFadeout();
void EndOrganya();
void ChangeMusic(int no);
void ReCallMusic();

