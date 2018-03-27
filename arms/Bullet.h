
struct $B5FAF0D5A59B9E9B7FBA104BDE3D14AE
{
  int front;
  int top;
  int back;
  int bottom;
};

struct Bullet
{
  int flag;
  int code_bullet;
  int bbits;
  int cond;
  int x;
  int y;
  int xm;
  int ym;
  int tgt_x;
  int tgt_y;
  int act_no;
  int act_wait;
  int ani_wait;
  int ani_no;
  unsigned __int8 direct;
  RECT rect;
  int count1;
  int count2;
  int life_count;
  int damage;
  int life;
  int enemyXL;
  int enemyYL;
  int blockXL;
  int blockYL;
  $B5FAF0D5A59B9E9B7FBA104BDE3D14AE view;
};

void InitBullet();
int CountArmsBullet(int arms_code);
int CountBulletNum(int bullet_code);
void DeleteBullet(int code);
void ClearBullet();
void PutBullet(int fx, int fy);
void SetBullet(int no, int x, int y, int dir);