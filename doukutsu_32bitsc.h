
#define __int8 char
#define __int16 short
#define __int32 int
#define __int64 long long

struct _IO_FILE;
struct _IO_marker;
struct private_hwdata;

struct RECT
{
  Sint32 left;
  Sint32 top;
  Sint32 right;
  Sint32 bottom;
};

struct $A04024D9D3FA77925171298B9D10BD38
{
  int mode;
  int act_no;
  int flag;
  int cnt;
  int width;
  int x;
  int y;
  RECT rect1;
  RECT rect2;
};

struct NPCHAR
{
  unsigned __int8 cond;
  int flag;
  int x;
  int y;
  int xm;
  int ym;
  int xm2;
  int ym2;
  int tgt_x;
  int tgt_y;
  int code_char;
  int code_flag;
  int code_event;
  int surf;
  int hit_voice;
  int destroy_voice;
  int life;
  int exp;
  int size;
  int direct;
  unsigned __int16 bits;
  RECT rect;
  int ani_wait;
  int ani_no;
  int count1;
  int count2;
  int act_no;
  int act_wait;
  $B5FAF0D5A59B9E9B7FBA104BDE3D14AE hit;
  $B5FAF0D5A59B9E9B7FBA104BDE3D14AE view;
  unsigned __int8 shock;
  int damage_view;
  int damage;
  NPCHAR *pNpc;
};

enum enum_ESCRETURN : __int32
{
  enum_ESCRETURN_exit = 0x0,
  enum_ESCRETURN_continue = 0x1,
  enum_ESCRETURN_restart = 0x2,
};


struct $BB6E7CC5619195A5A6517E054D903FD5
{
  int flag;
  int *px;
  int *py;
  int offset_y;
  int value;
  int count;
  RECT rect;
};

struct __attribute__((aligned(4))) $F81DAB7A3C5C75230BC79406CA55D892
{
  unsigned __int8 *data;
  unsigned __int8 atrb[257];
  __int16 width;
  __int16 length;
};


struct scoped_profile
{
  int (**_vptr.scoped_profile)(...);
  const char *id;
  Uint32 start;
};


struct __attribute__((aligned(4))) $EEE7987CBFE674A81758BE97986F1045
{
  int mode;
  bool bMask;
  int count;
  char ani_no[15][20];
  char flag[15][20];
  char dir;
};

struct $D3B267130C558B6C8C7B7A80A5697BE6
{
  int code;
  int level;
  int exp;
  int max_num;
  int num;
};


struct $E6546247C29CB722C536082DCFE3A174
{
  int flag;
  int *pLife;
  int max;
  int br;
  int count;
};

struct $557AD80E8FB350125C3B3CCF0C10D895
{
  Uint32 start;
  Uint8 note;
  Uint8 length;
  Uint8 volume;
  Uint8 pan;
};


struct __attribute__((aligned(4))) $04553E4401276348CEA0C0E6398A028E
{
  Uint16 freq;
  Uint8 wave;
  Uint8 pi;
  Uint16 num_notes;
  $557AD80E8FB350125C3B3CCF0C10D895 cur_note;
  $557AD80E8FB350125C3B3CCF0C10D895 *note;
  Uint32 pos;
  Sint16 playing;
  Uint32 samples;
  Uint16 pos_comma;
};


struct $C1127D3748787668AAF0293B2D646CFD
{
  char header[6];
  Uint16 tempo;
  Uint8 spb;
  Uint8 bps;
  Uint32 loopStart;
  Uint32 loopEnd;
  $04553E4401276348CEA0C0E6398A028E track[16];
  Uint32 pos;
  Uint32 samples;
};


struct $FE85C58A60403E3389C96E96D80030A8
{
  Uint8 *buf;
  Uint32 len;
  Uint16 vol;
  Uint16 lvol;
  Uint16 rvol;
  Uint32 freq;
};


struct __attribute__((aligned(2))) $5F3F5665D4853494D3935C18994FCA41
{
  $C1127D3748787668AAF0293B2D646CFD *org;
  Sint16 volume;
  Sint8 fadeout;
};

struct $88CD5C1514A19B01CE178CB8EAE44D15
{
  char proof[32];
  char font_name[64];
  Sint32 move_button_mode;
  Sint32 attack_button_mode;
  Sint32 ok_button_mode;
  Sint32 display_mode;
  Sint32 bJoystick;
  Sint32 joystick_button[8];
};


struct $DC890D5E5AA9C328B36A6715ACB40917
{
  int index;
  int event;
};


struct $6DB5036734B46A680493E38A645FBEF0
{
  int model;
  float num;
  int top;
  int offset;
};

struct $296577AB1FDEBC0CA4D43AF2DF231431
{
  int use;
  int size;
  $6DB5036734B46A680493E38A645FBEF0 oMain;
  $6DB5036734B46A680493E38A645FBEF0 oPitch;
  $6DB5036734B46A680493E38A645FBEF0 oVolume;
  int initial;
  int pointAx;
  int pointAy;
  int pointBx;
  int pointBy;
  int pointCx;
  int pointCy;
};

struct $105B29886D5D4880B7955C7D7F8771E6
{
  char damage;
  char life;
  int life_count;
  int bbits;
  int enemyXL;
  int enemyYL;
  int blockXL;
  int blockYL;
  $B5FAF0D5A59B9E9B7FBA104BDE3D14AE view;
};


struct $223C71E5D7CCC0F84FEFCDD656B66DEC
{
  int flag;
  int partsW;
  int partsH;
  int numX;
  int numY;
  int type;
  int _fx;
};


struct $74F7120D52ED14132C5D5934E9BCA40C
{
  int exp[3];
};


struct $B3FC422DA37A539D80A9413BC091BB99
{
  int counter[4];
  unsigned __int8 random[4];
};


enum language : __int32
{
  language_japanese = 0x0,
  language_english = 0x1,
};


struct MapName
{
  int flag;
  int wait;
  char name[32];
};


typedef void (*BOSSFUNCTION)(void);


struct __attribute__((aligned(4))) $D0E8D2897BA5D40099F1B39E7818C056
{
  char parts[32];
  char map[32];
  int bkType;
  char back[32];
  char npc[32];
  char boss[32];
  char boss_no;
  char name_jp[32];
  char name_en[32];
};


typedef void (*CARETFUNCTION)($4AB8D1A8A7198C298836BEA20F02E4D8 *);


struct $B39ED6C1613C80801629116D648EBE12
{
  int view_left;
  int view_top;
};


typedef int wchar_t;


struct $CC5B0FEB395DC4593A946B3182F5E0FD
{
  bool bLeft;
  bool bRight;
  bool bUp;
  bool bDown;
  bool bButton[32];
};


struct $4010822F30180CACF39DC1B3C7E9022D
{
  int code;
};


struct $8D9359E30B30BEB685C90F8A0F30C069
{
  Uint32 pos;
  Uint16 pos_comma;
  Sint32 repeat;
  $FE85C58A60403E3389C96E96D80030A8 *data;
};


enum $CBDFFB15DCADFA44BD5D682B3D6971CA : __int32
{
  SDLK_UNKNOWN = 0x0,
  SDLK_FIRST = 0x0,
  SDLK_BACKSPACE = 0x8,
  SDLK_TAB = 0x9,
  SDLK_CLEAR = 0xC,
  SDLK_RETURN = 0xD,
  SDLK_PAUSE = 0x13,
  SDLK_ESCAPE = 0x1B,
  SDLK_SPACE = 0x20,
  SDLK_EXCLAIM = 0x21,
  SDLK_QUOTEDBL = 0x22,
  SDLK_HASH = 0x23,
  SDLK_DOLLAR = 0x24,
  SDLK_AMPERSAND = 0x26,
  SDLK_QUOTE = 0x27,
  SDLK_LEFTPAREN = 0x28,
  SDLK_RIGHTPAREN = 0x29,
  SDLK_ASTERISK = 0x2A,
  SDLK_PLUS = 0x2B,
  SDLK_COMMA = 0x2C,
  SDLK_MINUS = 0x2D,
  SDLK_PERIOD = 0x2E,
  SDLK_SLASH = 0x2F,
  SDLK_0 = 0x30,
  SDLK_1 = 0x31,
  SDLK_2 = 0x32,
  SDLK_3 = 0x33,
  SDLK_4 = 0x34,
  SDLK_5 = 0x35,
  SDLK_6 = 0x36,
  SDLK_7 = 0x37,
  SDLK_8 = 0x38,
  SDLK_9 = 0x39,
  SDLK_COLON = 0x3A,
  SDLK_SEMICOLON = 0x3B,
  SDLK_LESS = 0x3C,
  SDLK_EQUALS = 0x3D,
  SDLK_GREATER = 0x3E,
  SDLK_QUESTION = 0x3F,
  SDLK_AT = 0x40,
  SDLK_LEFTBRACKET = 0x5B,
  SDLK_BACKSLASH = 0x5C,
  SDLK_RIGHTBRACKET = 0x5D,
  SDLK_CARET = 0x5E,
  SDLK_UNDERSCORE = 0x5F,
  SDLK_BACKQUOTE = 0x60,
  SDLK_a = 0x61,
  SDLK_b = 0x62,
  SDLK_c = 0x63,
  SDLK_d = 0x64,
  SDLK_e = 0x65,
  SDLK_f = 0x66,
  SDLK_g = 0x67,
  SDLK_h = 0x68,
  SDLK_i = 0x69,
  SDLK_j = 0x6A,
  SDLK_k = 0x6B,
  SDLK_l = 0x6C,
  SDLK_m = 0x6D,
  SDLK_n = 0x6E,
  SDLK_o = 0x6F,
  SDLK_p = 0x70,
  SDLK_q = 0x71,
  SDLK_r = 0x72,
  SDLK_s = 0x73,
  SDLK_t = 0x74,
  SDLK_u = 0x75,
  SDLK_v = 0x76,
  SDLK_w = 0x77,
  SDLK_x = 0x78,
  SDLK_y = 0x79,
  SDLK_z = 0x7A,
  SDLK_DELETE = 0x7F,
  SDLK_WORLD_0 = 0xA0,
  SDLK_WORLD_1 = 0xA1,
  SDLK_WORLD_2 = 0xA2,
  SDLK_WORLD_3 = 0xA3,
  SDLK_WORLD_4 = 0xA4,
  SDLK_WORLD_5 = 0xA5,
  SDLK_WORLD_6 = 0xA6,
  SDLK_WORLD_7 = 0xA7,
  SDLK_WORLD_8 = 0xA8,
  SDLK_WORLD_9 = 0xA9,
  SDLK_WORLD_10 = 0xAA,
  SDLK_WORLD_11 = 0xAB,
  SDLK_WORLD_12 = 0xAC,
  SDLK_WORLD_13 = 0xAD,
  SDLK_WORLD_14 = 0xAE,
  SDLK_WORLD_15 = 0xAF,
  SDLK_WORLD_16 = 0xB0,
  SDLK_WORLD_17 = 0xB1,
  SDLK_WORLD_18 = 0xB2,
  SDLK_WORLD_19 = 0xB3,
  SDLK_WORLD_20 = 0xB4,
  SDLK_WORLD_21 = 0xB5,
  SDLK_WORLD_22 = 0xB6,
  SDLK_WORLD_23 = 0xB7,
  SDLK_WORLD_24 = 0xB8,
  SDLK_WORLD_25 = 0xB9,
  SDLK_WORLD_26 = 0xBA,
  SDLK_WORLD_27 = 0xBB,
  SDLK_WORLD_28 = 0xBC,
  SDLK_WORLD_29 = 0xBD,
  SDLK_WORLD_30 = 0xBE,
  SDLK_WORLD_31 = 0xBF,
  SDLK_WORLD_32 = 0xC0,
  SDLK_WORLD_33 = 0xC1,
  SDLK_WORLD_34 = 0xC2,
  SDLK_WORLD_35 = 0xC3,
  SDLK_WORLD_36 = 0xC4,
  SDLK_WORLD_37 = 0xC5,
  SDLK_WORLD_38 = 0xC6,
  SDLK_WORLD_39 = 0xC7,
  SDLK_WORLD_40 = 0xC8,
  SDLK_WORLD_41 = 0xC9,
  SDLK_WORLD_42 = 0xCA,
  SDLK_WORLD_43 = 0xCB,
  SDLK_WORLD_44 = 0xCC,
  SDLK_WORLD_45 = 0xCD,
  SDLK_WORLD_46 = 0xCE,
  SDLK_WORLD_47 = 0xCF,
  SDLK_WORLD_48 = 0xD0,
  SDLK_WORLD_49 = 0xD1,
  SDLK_WORLD_50 = 0xD2,
  SDLK_WORLD_51 = 0xD3,
  SDLK_WORLD_52 = 0xD4,
  SDLK_WORLD_53 = 0xD5,
  SDLK_WORLD_54 = 0xD6,
  SDLK_WORLD_55 = 0xD7,
  SDLK_WORLD_56 = 0xD8,
  SDLK_WORLD_57 = 0xD9,
  SDLK_WORLD_58 = 0xDA,
  SDLK_WORLD_59 = 0xDB,
  SDLK_WORLD_60 = 0xDC,
  SDLK_WORLD_61 = 0xDD,
  SDLK_WORLD_62 = 0xDE,
  SDLK_WORLD_63 = 0xDF,
  SDLK_WORLD_64 = 0xE0,
  SDLK_WORLD_65 = 0xE1,
  SDLK_WORLD_66 = 0xE2,
  SDLK_WORLD_67 = 0xE3,
  SDLK_WORLD_68 = 0xE4,
  SDLK_WORLD_69 = 0xE5,
  SDLK_WORLD_70 = 0xE6,
  SDLK_WORLD_71 = 0xE7,
  SDLK_WORLD_72 = 0xE8,
  SDLK_WORLD_73 = 0xE9,
  SDLK_WORLD_74 = 0xEA,
  SDLK_WORLD_75 = 0xEB,
  SDLK_WORLD_76 = 0xEC,
  SDLK_WORLD_77 = 0xED,
  SDLK_WORLD_78 = 0xEE,
  SDLK_WORLD_79 = 0xEF,
  SDLK_WORLD_80 = 0xF0,
  SDLK_WORLD_81 = 0xF1,
  SDLK_WORLD_82 = 0xF2,
  SDLK_WORLD_83 = 0xF3,
  SDLK_WORLD_84 = 0xF4,
  SDLK_WORLD_85 = 0xF5,
  SDLK_WORLD_86 = 0xF6,
  SDLK_WORLD_87 = 0xF7,
  SDLK_WORLD_88 = 0xF8,
  SDLK_WORLD_89 = 0xF9,
  SDLK_WORLD_90 = 0xFA,
  SDLK_WORLD_91 = 0xFB,
  SDLK_WORLD_92 = 0xFC,
  SDLK_WORLD_93 = 0xFD,
  SDLK_WORLD_94 = 0xFE,
  SDLK_WORLD_95 = 0xFF,
  SDLK_KP0 = 0x100,
  SDLK_KP1 = 0x101,
  SDLK_KP2 = 0x102,
  SDLK_KP3 = 0x103,
  SDLK_KP4 = 0x104,
  SDLK_KP5 = 0x105,
  SDLK_KP6 = 0x106,
  SDLK_KP7 = 0x107,
  SDLK_KP8 = 0x108,
  SDLK_KP9 = 0x109,
  SDLK_KP_PERIOD = 0x10A,
  SDLK_KP_DIVIDE = 0x10B,
  SDLK_KP_MULTIPLY = 0x10C,
  SDLK_KP_MINUS = 0x10D,
  SDLK_KP_PLUS = 0x10E,
  SDLK_KP_ENTER = 0x10F,
  SDLK_KP_EQUALS = 0x110,
  SDLK_UP = 0x111,
  SDLK_DOWN = 0x112,
  SDLK_RIGHT = 0x113,
  SDLK_LEFT = 0x114,
  SDLK_INSERT = 0x115,
  SDLK_HOME = 0x116,
  SDLK_END = 0x117,
  SDLK_PAGEUP = 0x118,
  SDLK_PAGEDOWN = 0x119,
  SDLK_F1 = 0x11A,
  SDLK_F2 = 0x11B,
  SDLK_F3 = 0x11C,
  SDLK_F4 = 0x11D,
  SDLK_F5 = 0x11E,
  SDLK_F6 = 0x11F,
  SDLK_F7 = 0x120,
  SDLK_F8 = 0x121,
  SDLK_F9 = 0x122,
  SDLK_F10 = 0x123,
  SDLK_F11 = 0x124,
  SDLK_F12 = 0x125,
  SDLK_F13 = 0x126,
  SDLK_F14 = 0x127,
  SDLK_F15 = 0x128,
  SDLK_NUMLOCK = 0x12C,
  SDLK_CAPSLOCK = 0x12D,
  SDLK_SCROLLOCK = 0x12E,
  SDLK_RSHIFT = 0x12F,
  SDLK_LSHIFT = 0x130,
  SDLK_RCTRL = 0x131,
  SDLK_LCTRL = 0x132,
  SDLK_RALT = 0x133,
  SDLK_LALT = 0x134,
  SDLK_RMETA = 0x135,
  SDLK_LMETA = 0x136,
  SDLK_LSUPER = 0x137,
  SDLK_RSUPER = 0x138,
  SDLK_MODE = 0x139,
  SDLK_COMPOSE = 0x13A,
  SDLK_HELP = 0x13B,
  SDLK_PRINT = 0x13C,
  SDLK_SYSREQ = 0x13D,
  SDLK_BREAK = 0x13E,
  SDLK_MENU = 0x13F,
  SDLK_POWER = 0x140,
  SDLK_EURO = 0x141,
  SDLK_UNDO = 0x142,
  SDLK_LAST = 0x143,
};


enum $1C079D1B6F18170A124E17435FCF607E : __int32
{
  KMOD_NONE = 0x0,
  KMOD_LSHIFT = 0x1,
  KMOD_RSHIFT = 0x2,
  KMOD_LCTRL = 0x40,
  KMOD_RCTRL = 0x80,
  KMOD_LALT = 0x100,
  KMOD_RALT = 0x200,
  KMOD_LMETA = 0x400,
  KMOD_RMETA = 0x800,
  KMOD_NUM = 0x1000,
  KMOD_CAPS = 0x2000,
  KMOD_MODE = 0x4000,
  KMOD_RESERVED = 0x8000,
};


struct __attribute__((aligned(4))) SDL_keysym
{
  Uint8 scancode;
  $CBDFFB15DCADFA44BD5D682B3D6971CA sym;
  $1C079D1B6F18170A124E17435FCF607E mod;
  Uint16 unicode;
};



enum $02EB03CA9A2314059A325BB1D549B4E8 : __int32
{
  SDL_NOEVENT = 0x0,
  SDL_ACTIVEEVENT = 0x1,
  SDL_KEYDOWN = 0x2,
  SDL_KEYUP = 0x3,
  SDL_MOUSEMOTION = 0x4,
  SDL_MOUSEBUTTONDOWN = 0x5,
  SDL_MOUSEBUTTONUP = 0x6,
  SDL_JOYAXISMOTION = 0x7,
  SDL_JOYBALLMOTION = 0x8,
  SDL_JOYHATMOTION = 0x9,
  SDL_JOYBUTTONDOWN = 0xA,
  SDL_JOYBUTTONUP = 0xB,
  SDL_QUIT = 0xC,
  SDL_SYSWMEVENT = 0xD,
  SDL_EVENT_RESERVEDA = 0xE,
  SDL_EVENT_RESERVEDB = 0xF,
  SDL_VIDEORESIZE = 0x10,
  SDL_VIDEOEXPOSE = 0x11,
  SDL_EVENT_RESERVED2 = 0x12,
  SDL_EVENT_RESERVED3 = 0x13,
  SDL_EVENT_RESERVED4 = 0x14,
  SDL_EVENT_RESERVED5 = 0x15,
  SDL_EVENT_RESERVED6 = 0x16,
  SDL_EVENT_RESERVED7 = 0x17,
  SDL_USEREVENT = 0x18,
  SDL_NUMEVENTS = 0x20,
};


struct SystemTask::key_mapping_t
{
  $CBDFFB15DCADFA44BD5D682B3D6971CA src;
  int dst;
};


struct $7E71A1045C51D94A65087D8D46AB5C4F
{
  __int16 wave_size;
  __int16 oct_par;
  __int16 oct_size;
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




struct $A339A23B941C4586D68835B5BC3A21B2
{
  Uint16 freq;
  Uint8 wave_no;
  char pipi;
  NOTELIST *note_p;
  NOTELIST *note_list;
};


struct MUSICINFO
{
  Uint16 wait;
  Uint8 line;
  Uint8 dot;
  Uint16 alloc_note;
  Sint32 repeat_x;
  Sint32 end_x;
  $A339A23B941C4586D68835B5BC3A21B2 tdata[16];
};


struct __attribute__((aligned(2))) OrgData
{
  MUSICINFO_0 info;
  Sint8 track;
  Sint8 mute[16];
  Uint8 def_pan;
  Uint8 def_volume;
};


struct $6415F74327D6332F8F6CD308B0CDA689
{
  Uint16 freq;
  Uint8 wave_no;
  Uint8 pipi;
  Uint16 note_num;
};


struct $11C3EE8C60DD49A6CA3BAE14ACF35155
{
  Uint16 wait;
  Uint8 line;
  Uint8 dot;
  Sint32 repeat_x;
  Sint32 end_x;
  $6415F74327D6332F8F6CD308B0CDA689 tdata[16];
};


struct $2E6CEF5F705D68E3CCB7FD89342DD377
{
  Uint8 front;
  Uint8 top;
  Uint8 back;
  Uint8 bottom;
};


struct $3999A2E3BC6E7A1D19AF6FBFAF274F94
{
  Uint16 bits;
  Uint16 life;
  Uint8 surf;
  Uint8 hit_voice;
  Uint8 destroy_voice;
  Uint8 size;
  Sint32 exp;
  Sint32 damage;
  $2E6CEF5F705D68E3CCB7FD89342DD377 hit;
  $2E6CEF5F705D68E3CCB7FD89342DD377 view;
};


typedef void (*NPCFUNCTION)(NPCHAR *);


struct __attribute__((aligned(4))) $ADBFBA5FD9F608539A549A0DE3CC3084
{
  char path[260];
  int size;
  char *data;
  char mode;
  char flags;
  int p_read;
  int p_write;
  int line;
  int ypos_line[4];
  int wait;
  int wait_next;
  int next_event;
  char select;
  int face;
  int face_x;
  int item;
  int item_y;
  RECT rcText;
  int offsetY;
  unsigned __int8 wait_beam;
};




struct $27E69A81C4D44FA41891AD1A77DE92B3
{
  __int16 x;
  __int16 y;
  __int16 code_flag;
  __int16 code_event;
  __int16 code_char;
  unsigned __int16 bits;
};


union __attribute__((aligned(8))) __m64
{
  unsigned __int64 m64_u64;
  float m64_f32[2];
  __int8 m64_i8[8];
  __int16 m64_i16[4];
  __int32 m64_i32[2];
  __int64 m64_i64;
  unsigned __int8 m64_u8[8];
  unsigned __int16 m64_u16[4];
  unsigned __int32 m64_u32[2];
};


union __attribute__((aligned(16))) __m128
{
  float m128_f32[4];
  unsigned __int64 m128_u64[2];
  __int8 m128_i8[16];
  __int16 m128_i16[8];
  __int32 m128_i32[4];
  __int64 m128_i64[2];
  unsigned __int8 m128_u8[16];
  unsigned __int16 m128_u16[8];
  unsigned __int32 m128_u32[4];
};


struct __m128d
{
  double m128d_f64[2];
};


union __attribute__((aligned(16))) __m128i
{
  __int8 m128i_i8[16];
  __int16 m128i_i16[8];
  __int32 m128i_i32[4];
  __int64 m128i_i64[2];
  unsigned __int8 m128i_u8[16];
  unsigned __int16 m128i_u16[8];
  unsigned __int32 m128i_u32[4];
  unsigned __int64 m128i_u64[2];
};

