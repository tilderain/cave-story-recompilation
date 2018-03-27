struct NOTE
{
	Uint32 start;
	Uint8 note;
	Uint8 length;
	Uint8 volume;
	Uint8 pan;
};

struct TRACK
{
	Uint16 freq;
	Uint8 wave;
	Uint8 pi;
	Uint16 num_notes;
	NOTE cur_note;
	NOTE *note;
	Uint32 pos;
	Sint16 playing;
	Uint32 samples;
	Uint16 pos_comma;
};

struct ORG
{
	char header[6];
	Uint16 tempo;
	Uint8 spb;
	Uint8 bps;
	Uint32 loopStart;
	Uint32 loopEnd;
	TRACK track[16];
	Uint32 pos;
	Uint32 samples;
};

struct NOTELIST
{
	NOTELIST *from;
	NOTELIST *to;
	Sint32 x;
	Uint8 length;
	Uint8 y;
	Uint8 volume;
	Uint8 pan;
};

struct OCTAVE_WAVE//(i think)
{
	__int16 wave_size;
	__int16 oct_par;
	__int16 oct_size;
};

ORG *loadORG(const char *path);
void freeORG(ORG *org);
void playORG(ORG *org);
void setPlayerFadeout(Uint8 fadeout);
void setPlayerVolume(Uint16 volume);
Uint32 getORGPosition(ORG *org);
void setORGPosition(ORG *org, Uint32 position);
void stopORG();
int _interpolate(Sint16 v1, Sint16 v2, Uint16 f);
void _renderDrumWave(Sint32 *buffer, int no, TRACK *instrument, int len);
void _renderOrgWave(Sint32 *buffer, TRACK *instrument, int len);
void org_mixer(void *param, Uint8 *stream, int len);
void initORG();
void quitORG();