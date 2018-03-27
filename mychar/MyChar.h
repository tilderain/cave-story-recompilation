
struct MyChar
{
  unsigned __int8 cond;
  unsigned int flag;
  int direct;
  int up;
  int down;
  int unit;
  int equip;
  int x;
  int y;
  int tgt_x;
  int tgt_y;
  int index_x;
  int index_y;
  int xm;
  int ym;
  int ani_wait;
  int ani_no;
  $B5FAF0D5A59B9E9B7FBA104BDE3D14AE hit;
  $B5FAF0D5A59B9E9B7FBA104BDE3D14AE view;
  RECT rect;
  RECT rect_arms;
  int level;
  int exp_wait;
  int exp_count;
  unsigned __int8 shock;
  unsigned __int8 no_life;
  unsigned __int8 rensha;
  unsigned __int8 bubble;
  __int16 life;
  __int16 star;
  __int16 max_life;
  __int16 a;
  int lifeBr;
  int lifeBr_count;
  int air;
  int air_get;
  char sprash;
  char ques;
  char boost_sw;
  int boost_cnt;
};


extern MyChar gMC;

void InitMyChar();
void AnimationMyChar(bool bKey);
void ShowMyChar(bool bShow);
void PutMyChar(int fx, int fy);
void ActMyChar_Normal(bool bKey);
void ActMyChar_Stream(bool bKey);
void AirProcess();
void ActMyChar(bool bKey);
void GetMyCharPosition(int *x, int *y);
void SetMyCharPosition(int x, int y);
void MoveMyChar(int x, int y);
void ZeroMyCharXMove();
int GetUnitMyChar();
void SetMyCharDirect(unsigned __int8 dir);
void ChangeMyUnit(unsigned __int8 a);
void PitMyChar();
void EquipItem(int flag, bool b);
void ResetCheck();
void SetNoise(int no, int freq);
void CutNoise();
void ResetNoise();
void SleepNoise();