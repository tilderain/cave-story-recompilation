#include "stddef.h"
//#include "types.h"
//#include "libio.h"
#include "windows_wrapper.h"
#include "language.h"
#include "stdio.h"

signed int TransferStage(int no, int w, int x, int y);

$D0E8D2897BA5D40099F1B39E7818C056 gTMT[95] =
{
  {
    {
      '0',
      '\0',
      '\0',
      '\0',
      '\0',
      '\0',
      '\0',
      '\0',
      '\0',
      '\0',
      '\0',
      '\0',
      '\0',
      '\0',
      '\0',
      '\0',
      '\0',
      '\0',
      '\0',
      '\0',
      '\0',
      '\0',
      '\0',
      '\0',
      '\0',
      '\0',
      '\0',
      '\0',
      '\0',
      '\0',
      '\0',
      '\0'
    },
    "0",
    4,
    "bk0",
    "Guest",
    "0",
    '\0',
    "\x96\xB3",
    "Credits"
  },
  {
    "Pens",
    "Pens1",
    1,
    "bkBlue",
    "Guest",
    "0",
    '\0',
    "\x83A\x81[\x83T\x81[\x82̉\xC6",
    "Arthur's house"
  },
  {
    "Eggs",
    "Eggs",
    1,
    "bkGreen",
    "Eggs1",
    "Ravil",
    '\0',
    "\x83^\x83}\x83S\x89\xF1\x98\x4C",
    "Egg Corridor"
  },
  {
    "EggX",
    "EggX",
    4,
    "bk0",
    "Eggs1",
    "0",
    '\0',
    "\x83^\x83}\x83S No.00",
    "Egg No. 00"
  },
  {
    "EggIn",
    "Egg6",
    4,
    "bk0",
    "Eggs1",
    "0",
    '\0',
    "\x83^\x83}\x83S No.06",
    "Egg No. 06"
  },
  {
    "Store",
    "EggR",
    4,
    "bk0",
    "Eggs1",
    "0",
    '\0',
    "\x83^\x83}\x83S\x8AĎ\x8B\x8E\xBA",
    "Egg Observation Room"
  },
  {
    "Weed",
    "Weed",
    1,
    "bkBlue",
    "Weed",
    "0",
    '\0',
    "\x83N\x83T\x83\x80\x83\x89",
    "Grasstown"
  },
  {
    "Barr",
    "Santa",
    4,
    "bk0",
    "Weed",
    "0",
    '\0',
    "\x83T\x83\x93\x83^\x82̉\xC6",
    "Santa's House"
  },
  {
    "Barr",
    "Chako",
    1,
    "bkBlue",
    "Guest",
    "0",
    '\0',
    "\x83`\x83\x83\x83R\x82̉\xC6",
    "Chaco's House"
  },
  {
    "Maze",
    "MazeI",
    4,
    "bk0",
    "Maze",
    "0",
    '\0',
    "\x96\xC0\x8B{\x82h",
    "Labyrinth I"
  },
  {
    "Sand",
    "Sand",
    1,
    "bkGreen",
    "Sand",
    "Omg",
    '\x01',
    "\x8D\xBB\x8B\xE6",
    "Sand Zone"
  },
  {
    "Mimi",
    "Mimi",
    1,
    "bkBlue",
    "Guest",
    "0",
    '\0',
    "\x83~\x83~\x83K\x81[\x82̑\xBA",
    "Mimiga Village"
  },
  {
    "Cave",
    "Cave",
    4,
    "bk0",
    "Cemet",
    "0",
    '\0',
    "\x8Dŏ\x89\x82̓\xB4\x8CA",
    "First Cave"
  },
  {
    "Cave",
    "Start",
    4,
    "bk0",
    "Cemet",
    "0",
    '\0',
    "\x83X\x83^\x81[\x83g\x92n\x93_",
    "Start Point"
  },
  {
    "Mimi",
    "Barr",
    4,
    "bk0",
    "Cemet",
    "Bllg",
    '\0',
    "\x83o\x83\x89\x83b\x83N\x8F\xAC\x89\xAE",
    "Shack"
  },
  {
    "Mimi",
    "Pool",
    1,
    "bkBlue",
    "Guest",
    "0",
    '\0',
    "\x92\x99\x90\x85\x92r",
    "Reservoir"
  },
  {
    "Mimi",
    "Cemet",
    4,
    "bk0",
    "Cemet",
    "0",
    '\0',
    "\x82͂\xA9\x82\xCE",
    "Graveyard"
  },
  {
    "Mimi",
    "Plant",
    1,
    "bkGreen",
    "Plant",
    "0",
    '\0',
    "\x8ER\x89\xBA\x94_\x89\x80",
    "Yamashita Farm"
  },
  {
    "Store",
    "Shelt",
    4,
    "bk0",
    "Eggs1",
    "0",
    '\0',
    "\x83V\x83F\x83\x8B\x83^\x81[",
    "Shelter"
  },
  {
    "Pens",
    "Comu",
    1,
    "bkBlue",
    "Guest",
    "0",
    '\0',
    "\x8FW\x89\xEF\x8F\xEA",
    "Assembly Hall"
  },
  {
    "Mimi",
    "MiBox",
    4,
    "bk0",
    "0",
    "0",
    '\0',
    "\x83Z\x81[\x83u\x83|\x83C\x83\x93\x83g",
    "Save Point"
  },
  {
    "Store",
    "EgEnd1",
    4,
    "bk0",
    "0",
    "0",
    '\0',
    "\x83^\x83}\x83S\x89\xF1\x98\x4C\x82̌\u008E\xBA",
    "Side Room"
  },
  {
    "Store",
    "Cthu",
    4,
    "bk0",
    "0",
    "0",
    '\0',
    "\x83N\x83g\x83D\x83\x8B\x81[\x82̏Z\x8F\x88",
    "Cthulhu's Abode"
  },
  {
    "EggIn",
    "Egg1",
    4,
    "bk0",
    "Eggs1",
    "0",
    '\0',
    "\x83^\x83}\x83S No.01",
    "Egg No. 01"
  },
  {
    "Pens",
    "Pens2",
    1,
    "bkBlue",
    "Guest",
    "0",
    '\0',
    "\x83A\x81[\x83T\x81[\x82̉\xC6",
    "Arthur's House"
  },
  {
    "Barr",
    "Malco",
    1,
    "bkBlue",
    "Weed",
    "Bllg",
    '\0',
    "\x93d\x8C\xB9\x8E\xBA",
    "Power Room"
  },
  {
    "Barr",
    "WeedS",
    1,
    "bkBlue",
    "0",
    "0",
    '\0',
    "\x83Z\x81[\x83u\x83|\x83C\x83\x93\x83g",
    "Save Point"
  },
  {
    "Store",
    "WeedD",
    1,
    "bkBlue",
    "0",
    "0",
    '\0',
    "\x8F\x88\x8CY\x8E\xBA",
    "Execution Chamber"
  },
  {
    "Weed",
    "Frog",
    2,
    "bkGreen",
    "Weed",
    "Frog",
    '\x02',
    "\x83K\x83\x80",
    "Gum"
  },
  {
    "Sand",
    "Curly",
    4,
    "bk0",
    "Sand",
    "Curly",
    '\0',
    "\x8D\xBB\x8B撓\x8Dݏ\x8A",
    "Sand Zone Residence"
  },
  {
    "Pens",
    "WeedB",
    1,
    "bkBlue",
    "Ravil",
    "0",
    '\0',
    "\x83N\x83T\x83\x80\x83\x89\x82̏\xAC\x89\xAE",
    "Grasstown Hut"
  },
  {
    "River",
    "Stream",
    5,
    "bkBlue",
    "Stream",
    "IronH",
    '\x05',
    "\x91哮\x96\xAC",
    "Main Artery"
  },
  {
    "Pens",
    "CurlyS",
    4,
    "bk0",
    "Sand",
    "Curly",
    '\0',
    "\x8F\xAC\x95\x94\x89\xAE",
    "Small Room"
  },
  {
    "Barr",
    "Jenka1",
    4,
    "bk0",
    "Sand",
    "Bllg",
    '\0',
    "\x83W\x83F\x83\x93\x83J\x82̉\xC6",
    "Jenka's House"
  },
  {
    "Sand",
    "Dark",
    1,
    "bkBlack",
    "Sand",
    "0",
    '\0',
    "\x94p\x89\xAE",
    "Deserted House"
  },
  {
    "Gard",
    "Gard",
    1,
    "bkGard",
    "Toro",
    "Bllg",
    '\0',
    "\x8D\xBB\x8B\xE6\x91\x71\x8C\xC9",
    "Storehouse"
  },
  {
    "Barr",
    "Jenka2",
    4,
    "bk0",
    "Sand",
    "Bllg",
    '\0',
    "\x83W\x83F\x83\x93\x83J\x82̉\xC6",
    "Jenka's House"
  },
  {
    "Sand",
    "SandE",
    1,
    "bkGreen",
    "Sand",
    "Bllg",
    '\0',
    "\x8D\xBB\x8B\xE6",
    "Sand Zone"
  },
  {
    "Maze",
    "MazeH",
    4,
    "bk0",
    "Maze",
    "0",
    '\0',
    "\x96\xC0\x8B{\x82g",
    "Labyrinth H"
  },
  {
    "Maze",
    "MazeW",
    1,
    "bkMaze",
    "Maze",
    "X",
    '\x03',
    "\x96\xC0\x8B{\x82v",
    "Labyrinth W"
  },
  {
    "Maze",
    "MazeO",
    4,
    "bk0",
    "Guest",
    "0",
    '\0',
    "\x83L\x83\x83\x83\x93\x83v",
    "Camp"
  },
  {
    "Maze",
    "MazeD",
    4,
    "bk0",
    "Guest",
    "Dark",
    '\0',
    "\x90f\x97Ï\x8A\x90\xD5",
    "Clinic Ruins"
  },
  {
    "Store",
    "MazeA",
    4,
    "bk0",
    "Maze",
    "0",
    '\0',
    "\x96\xC0\x8B{\x82̓X",
    "Labyrinth Shop"
  },
  {
    "Maze",
    "MazeB",
    1,
    "bkBlue",
    "Maze",
    "0",
    '\0',
    "\x96\xC0\x8B{\x82a",
    "Labyrinth B"
  },
  {
    "Maze",
    "MazeS",
    2,
    "bkGray",
    "Maze",
    "Bllg",
    '\0',
    "\x91\xE5\x90\xCE\x82̍ǂ\xAE\x8F\x8A",
    "Boulder Chamber"
  },
  {
    "Maze",
    "MazeM",
    1,
    "bkRed",
    "Maze",
    "0",
    '\0',
    "\x96\xC0\x8B{\x82l",
    "Labyrinth M"
  },
  {
    "Cave",
    "Drain",
    3,
    "bkWater",
    "Cemet",
    "0",
    '\0',
    "\x88Â\xA2\x8F\x8A",
    "Dark Place"
  },
  {
    "Almond",
    "Almond",
    3,
    "bkWater",
    "Cemet",
    "Almo1",
    '\x04',
    "\x83R\x83A",
    "Core"
  },
  {
    "River",
    "River",
    2,
    "bkGreen",
    "Weed",
    "0",
    '\0',
    "\x90\x85\x98H",
    "Waterway"
  },
  {
    "Eggs",
    "Eggs2",
    1,
    "bkGreen",
    "Eggs2",
    "0",
    '\0',
    "\x83^\x83}\x83S\x89\xF1\x98\x4C\x81H",
    "Egg Corridor"
  },
  {
    "Store",
    "Cthu2",
    4,
    "bk0",
    "Eggs1",
    "0",
    '\0',
    "\x83N\x83g\x83D\x83\x8B\x81[\x82̏Z\x8F\x88\x81H",
    "Cthulhu's Abode"
  },
  {
    "Store",
    "EggR2",
    4,
    "bk0",
    "Eggs1",
    "TwinD",
    '\x06',
    "\x83^\x83}\x83S\x8AĎ\x8B\x8E\xBA\x81H",
    "Egg Observation Room"
  },
  {
    "EggX",
    "EggX2",
    4,
    "bk0",
    "Eggs1",
    "0",
    '\0',
    "\x83^\x83}\x83S No.00",
    "Egg No. 00"
  },
  {
    "Oside",
    "Oside",
    6,
    "bkMoon",
    "Moon",
    "0",
    '\0',
    "\x8AO\x95\xC7",
    "Outer Wall"
  },
  {
    "Store",
    "EgEnd2",
    4,
    "bk0",
    "Eggs1",
    "0",
    '\0',
    "\x83^\x83}\x83S\x89\xF1\x98\x4C\x82̌\u008E\xBA",
    "Side Room"
  },
  {
    "Store",
    "Itoh",
    2,
    "bkBlue",
    "Guest",
    "0",
    '\0',
    "\x91q\x8C\xC9",
    "Storehouse"
  },
  {
    "Cent",
    "Cent",
    1,
    "bkGreen",
    "Guest",
    "Cent",
    '\0',
    "\x91\xE5\x94\x5F\x89\x80",
    "Plantation"
  },
  {
    "Jail",
    "Jail1",
    4,
    "bk0",
    "Guest",
    "Cent",
    '\0',
    "\x91\xE6\x82\x50\x98S",
    "Jail No. 1"
  },
  {
    "Jail",
    "Momo",
    4,
    "bk0",
    "Guest",
    "0",
    '\0',
    "\x83J\x83N\x83\x8C\x83K",
    "Hideout"
  },
  {
    "Jail",
    "Lounge",
    4,
    "bk0",
    "Guest",
    "0",
    '\0',
    "\x8Bx\x8Ce\x8F\x8A",
    "Rest Area"
  },
  {
    "Store",
    "CentW",
    4,
    "bk0",
    "Guest",
    "Cent",
    '\0',
    "\x93]\x91\x97\x8E\xBA",
    "Teleporter"
  },
  {
    "Store",
    "Jail2",
    4,
    "bk0",
    "Guest",
    "Cent",
    '\0',
    "\x91\xE6\x82\x51\x98S",
    "Jail No. 2"
  },
  {
    "White",
    "Blcny1",
    7,
    "bkFog",
    "Ravil",
    "Heri",
    '\0',
    "\x83o\x83\x8B\x83R\x83j\x81[",
    "Balcony"
  },
  {
    "Jail",
    "Priso1",
    4,
    "bkGray",
    "Red",
    "0",
    '\0',
    "\x8DŌ\xE3\x82\xCC\x93\xB4\x8CA",
    "Last Cave"
  },
  {
    "White",
    "Ring1",
    7,
    "bkFog",
    "Guest",
    "Miza",
    '\0',
    "\x89\xA4\x82̋ʍ\xC0",
    "Throne Room"
  },
  {
    "White",
    "Ring2",
    7,
    "bkFog",
    "Guest",
    "Dr",
    '\0',
    "\x89\xA4\x82̐H\x91\xEC",
    "The King's Table"
  },
  {
    "Pens",
    "Prefa1",
    4,
    "bk0",
    "0",
    "0",
    '\0',
    "\x83v\x83\x8C\x83n\x83u",
    "Prefab House"
  },
  {
    "Jail",
    "Priso2",
    4,
    "bkGray",
    "Red",
    "0",
    '\0',
    "\x8DŌ\xE3\x82\xCC\x93\xB4\x8CA\x81E\x97\xA0",
    "Last Cave Hidden"
  },
  {
    "White",
    "Ring3",
    4,
    "bk0",
    "Miza",
    "Almo2",
    '\a',
    "\x8D\x95\x82\xA2\x8DL\x8A\xD4",
    "Black Space"
  },
  {
    "Pens",
    "Little",
    2,
    "bkBlue",
    "Guest",
    "0",
    '\0',
    "\x83\x8A\x83g\x83\x8B\x89\xC6",
    "Little House"
  },
  {
    "White",
    "Blcny2",
    7,
    "bkFog",
    "Ravil",
    "Heri",
    '\0',
    "\x83o\x83\x8B\x83R\x83j\x81[",
    "Balcony"
  },
  {
    "Fall",
    "Fall",
    1,
    "bkFall",
    "Guest",
    "Heri",
    '\0',
    "\x97\x8E\x89\xBA",
    "Ending"
  },
  { "White", "Kings", 4, "bk0", "Kings", "0", '\0', "u", "u" },
  {
    "Pens",
    "Pixel",
    1,
    "bkBlue",
    "Guest",
    "0",
    '\0',
    "\x90\x85\x98H\x82̏\xAC\x95\x94\x89\xAE",
    "Waterway Cabin"
  },
  { "Maze", "e_Maze", 1, "bkMaze", "Guest", "Maze", '\x03', "", "" },
  { "Barr", "e_Jenk", 4, "bk0", "Sand", "Bllg", '\0', "", "" },
  { "Barr", "e_Malc", 1, "bkBlue", "Weed", "Bllg", '\0', "", "" },
  { "Mimi", "e_Ceme", 4, "bk0", "Plant", "0", '\0', "", "" },
  { "Fall", "e_Sky", 1, "bkFall", "Guest", "Heri", '\0', "", "" },
  {
    "Pens",
    "Prefa2",
    4,
    "bk0",
    "0",
    "0",
    '\0',
    "\x83v\x83\x8C\x83n\x83u",
    "Prefab House"
  },
  {
    "Hell",
    "Hell1",
    2,
    "bkRed",
    "Hell",
    "0",
    '\0',
    "\x90\xB9\x88\xE6\x92\x6E\x89\xBA\x82P\x8AK",
    "Sacred Ground B1"
  },
  {
    "Hell",
    "Hell2",
    2,
    "bkRed",
    "Hell",
    "0",
    '\0',
    "\x90\xB9\x88\xE6\x92\x6E\x89\xBA\x82Q\x8AK",
    "Sacred Ground B2"
  },
  {
    "Hell",
    "Hell3",
    1,
    "bkRed",
    "Hell",
    "Press",
    '\b',
    "\x90\xB9\x88\xE6\x92\x6E\x89\xBA\x82R\x8AK",
    "Sacred Ground B3"
  },
  { "Cave", "Mapi", 2, "bk0", "Cemet", "0", '\0', "\x95\xA8\x92u", "Storage" },
  { "Hell", "Hell4", 4, "bk0", "Hell", "0", '\0', "\x92ʘH\x81H", "Passage" },
  {
    "Hell",
    "Hell42",
    4,
    "bk0",
    "Hell",
    "Press",
    '\b',
    "\x92ʘH\x81H",
    "Passage"
  },
  {
    "Hell",
    "Statue",
    1,
    "bkBlue",
    "0",
    "Cent",
    '\0',
    "\x90Α\x9C\x82̊\xD4",
    "Statue Chamber"
  },
  {
    "Hell",
    "Ballo1",
    2,
    "bkBlue",
    "Priest",
    "Ballos",
    '\t',
    "\x95\x95\x88\xF3\x82\xCC\x8A\xD4",
    "Seal Chamber"
  },
  {
    "White",
    "Ostep",
    7,
    "bkFog",
    "0",
    "0",
    '\0',
    "\x82킽\x82\xE8\x98\x4C\x89\xBA",
    "Corridor"
  },
  { "Labo", "e_Labo", 4, "bk0", "Guest", "0", '\0', "", "" },
  {
    "Cave",
    "Pole",
    4,
    "bk0",
    "Guest",
    "0",
    '\0',
    "\x82͂\xAE\x82\xEA\x8F\x65\x92b\x96\xE8",
    "Hermit Gunsmith"
  },
  { "0", "Island", 4, "bk0", "Island", "0", '\0', "", "" },
  {
    "Hell",
    "Ballo2",
    2,
    "bkBlue",
    "Priest",
    "Bllg",
    '\t',
    "\x95\x95\x88\xF3\x82\xCC\x8A\xD4",
    "Seal Chamber"
  },
  { "White", "e_Blcn", 7, "bkFog", "Miza", "0", '\t', "", "" },
  {
    "Oside",
    "Clock",
    6,
    "bkMoon",
    "Moon",
    "0",
    '\0',
    "\x8E\x9E\x8Cv\x89\xAE",
    "Clock Room"
  }
};
char *gMusicTable[42] =
{
  "XXXX",
  "Wanpaku",
  "Anzen",
  "Gameover",
  "Gravity",
  "Weed",
  "MDown2",
  "FireEye",
  "Vivi",
  "Mura",
  "Fanfale1",
  "Ginsuke",
  "Cemetery",
  "Plant",
  "Kodou",
  "Fanfale3",
  "Fanfale2",
  "Dr",
  "Escape",
  "Jenka",
  "Maze",
  "Access",
  "ironH",
  "Grand",
  "Curly",
  "Oside",
  "Requiem",
  "Wanpak2",
  "quiet",
  "LastCave",
  "Balcony",
  "LastBtl",
  "LastBtl3",
  "Ending",
  "Zonbie",
  "BreakDown",
  "Hell",
  "Jenka2",
  "Marine",
  "Ballos",
  "Toroko",
  "White"
};

signed int TransferStage(int no, int w, int x, int y)
{
  signed int result;
  char path[260];
  char path_dir[20];
  bool bError;
  char *map_name;

  SetMyCharPosition(x << 13, y << 13);
  bError = 0;
  memcpy(path_dir, "Stage", 6u);
  sprintf(path, "%s/Prt%s", path_dir, 232 * no + 136058976);
  if ( !ReloadBitmap_File(path, 2) )
    bError = 1;
  sprintf(path, "%s/%s.pxa", path_dir, 232 * no + 136058976);
  if ( (unsigned __int8)LoadAttributeData(path) ^ 1 )
    bError = 1;
  sprintf(path, "%s/%s.pxm", path_dir, 232 * no + 136059008);
  if ( (unsigned __int8)LoadMapData2(path) ^ 1 )
    bError = 1;
  sprintf(path, "%s/%s.pxe", path_dir, 232 * no + 136059008);
  if ( (unsigned __int8)LoadEvent(path) ^ 1 )
    bError = 1;
  sprintf(path, "%s/%s.tsc", path_dir, 232 * no + 136059008);
  if ( (unsigned __int8)LoadTextScript_Stage(path) ^ 1 )
    bError = 1;
  strcpy(path, (const char *)(232 * no + 136059044));
  if ( (unsigned __int8)InitBack(path, gTMT[no].bkType) ^ 1 )
    bError = 1;
  memcpy(path_dir, "Npc", 4u);
  sprintf(path, "%s/Npc%s", path_dir, 232 * no + 136059076);
  if ( !ReloadBitmap_File(path, 21) )
    bError = 1;
  sprintf(path, "%s/Npc%s", path_dir, 232 * no + 136059108);
  if ( !ReloadBitmap_File(path, 22) )
    bError = 1;
  if ( bError )
  {
    fprintf(stderr, "There was an ERROR loading Stage %ld!", no);
    result = 0;
  }
  else
  {
    map_name = 0;
    if ( get_language() == 0 )
      map_name = (char *)(232 * no + 136059141);
    else
      map_name = (char *)(232 * no + 136059173);
    ReadyMapName((unsigned __int8 *)map_name);
    StartTextScript(w);
    SetFrameMyChar();
    ClearBullet();
    InitCaret();
    ClearValueView();
    ResetQuake();
    InitBossChar(gTMT[no].boss_no);
    ResetFlash();
    gStageNo = no;
    result = 1;
  }
  return result;
}
