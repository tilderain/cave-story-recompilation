#include "PixTone.h"
signed int LoadGenericData()
{
  char str[64];
  int pt_size;
  bool bError;

  MakeSurface_Resource("pixel", 1);
  bError = 0;
  if ( !MakeSurface_File("MyChar", 16) )
    bError = 1;
  if ( !MakeSurface_File("Title", 0) )
    bError = 1;
  if ( !MakeSurface_File("ArmsImage", 12) )
    bError = 1;
  if ( !MakeSurface_File("Arms", 11) )
    bError = 1;
  if ( !MakeSurface_File("ItemImage", 8) )
    bError = 1;
  if ( !MakeSurface_File("StageImage", 14) )
    bError = 1;
  if ( !MakeSurface_File("Npc/NpcSym", 20) )
    bError = 1;
  if ( !MakeSurface_File("Npc/NpcRegu", 23) )
    bError = 1;
  if ( !MakeSurface_File("TextBox", 26) )
    bError = 1;
  if ( !MakeSurface_File("Caret", 19) )
    bError = 1;
  if ( !MakeSurface_File("Bullet", 17) )
    bError = 1;
  if ( !MakeSurface_File("Face", 27) )
    bError = 1;
  if ( !MakeSurface_File("Fade", 6) )
    bError = 1;
  MakeSurface_Resource("Credit01", 36);
  if ( bError )
    return 0;
  MakeSurface_Generic(320, 240, 10);
  MakeSurface_Generic(320, 240, 28);
  MakeSurface_Generic(320, 240, 9);
  MakeSurface_Generic(320, 240, 37);
  MakeSurface_Generic(256, 256, 2);
  MakeSurface_Generic(160, 16, 13);
  MakeSurface_Generic(40, 240, 29);
  MakeSurface_Generic(320, 240, 21);
  MakeSurface_Generic(320, 240, 22);
  MakeSurface_Generic(320, 240, 35);
  pt_size = MakePixToneObject(gPtpTable, 2, 32);
  pt_size += MakePixToneObject(&ptp, 2, 33);
  pt_size += MakePixToneObject(&stru_81BE310, 2, 34);
  pt_size += MakePixToneObject(&stru_81BE3B8, 1, 15);
  pt_size += MakePixToneObject(&stru_81BE40C, 1, 24);
  pt_size += MakePixToneObject(&stru_81BE460, 1, 23);
  pt_size += MakePixToneObject(&stru_81BE4B4, 2, 50);
  pt_size += MakePixToneObject(&stru_81BE55C, 2, 51);
  pt_size += MakePixToneObject(&stru_81BEC94, 1, 1);
  pt_size += MakePixToneObject(&stru_81BEE38, 1, 2);
  pt_size += MakePixToneObject(&stru_81BF420, 1, 29);
  pt_size += MakePixToneObject(&stru_81BF5C4, 1, 43);
  pt_size += MakePixToneObject(&stru_81BF618, 3, 44);
  pt_size += MakePixToneObject(&stru_81BF714, 1, 45);
  pt_size += MakePixToneObject(&stru_81BF768, 1, 46);
  pt_size += MakePixToneObject(&stru_81BF810, 1, 47);
  pt_size += MakePixToneObject(&stru_81BF1D4, 3, 35);
  pt_size += MakePixToneObject(&stru_81BF2D0, 3, 39);
  pt_size += MakePixToneObject(&stru_81BE604, 2, 52);
  pt_size += MakePixToneObject(&stru_81BEAF0, 2, 53);
  pt_size += MakePixToneObject(&stru_81BE6AC, 2, 70);
  pt_size += MakePixToneObject(&stru_81BE754, 2, 71);
  pt_size += MakePixToneObject(&stru_81BE7FC, 2, 72);
  pt_size += MakePixToneObject(&stru_81BEB98, 1, 5);
  pt_size += MakePixToneObject(&stru_81BEC40, 1, 11);
  pt_size += MakePixToneObject(&stru_81BED3C, 1, 4);
  pt_size += MakePixToneObject(&stru_81BF0D8, 2, 25);
  pt_size += MakePixToneObject(&stru_81BF180, 1, 27);
  pt_size += MakePixToneObject(&stru_81BF378, 2, 28);
  pt_size += MakePixToneObject(&stru_81BEE8C, 1, 14);
  pt_size += MakePixToneObject(&stru_81BE94C, 2, 16);
  pt_size += MakePixToneObject(&stru_81BE9F4, 3, 17);
  pt_size += MakePixToneObject(&stru_81BECE8, 1, 18);
  pt_size += MakePixToneObject(&stru_81BED90, 2, 20);
  pt_size += MakePixToneObject(&stru_81BEBEC, 1, 22);
  pt_size += MakePixToneObject(&stru_81BEF34, 2, 26);
  pt_size += MakePixToneObject(&stru_81BEFDC, 1, 21);
  pt_size += MakePixToneObject(&stru_81BF030, 2, 12);
  pt_size += MakePixToneObject(&stru_81BF474, 2, 38);
  pt_size += MakePixToneObject(&stru_81BF51C, 1, 31);
  pt_size += MakePixToneObject(&stru_81BF570, 1, 42);
  pt_size += MakePixToneObject(&stru_81BF864, 1, 48);
  pt_size += MakePixToneObject(&stru_81BF8B8, 2, 49);
  pt_size += MakePixToneObject(&stru_81BF960, 1, 100);
  pt_size += MakePixToneObject(&stru_81BF9B4, 3, 101);
  pt_size += MakePixToneObject(&stru_81BFAB0, 2, 54);
  pt_size += MakePixToneObject(&stru_81BFB58, 2, 102);
  pt_size += MakePixToneObject(&stru_81BFC00, 2, 103);
  pt_size += MakePixToneObject(&stru_81BFC54, 1, 104);
  pt_size += MakePixToneObject(&stru_81BFCA8, 1, 105);
  pt_size += MakePixToneObject(&stru_81BFCFC, 2, 106);
  pt_size += MakePixToneObject(&stru_81BFDA4, 1, 107);
  pt_size += MakePixToneObject(&stru_81BFDF8, 1, 30);
  pt_size += MakePixToneObject(&stru_81BFE4C, 1, 108);
  pt_size += MakePixToneObject(&stru_81BFEA0, 1, 109);
  pt_size += MakePixToneObject(&stru_81BFEF4, 1, 110);
  pt_size += MakePixToneObject(&stru_81BFF48, 1, 111);
  pt_size += MakePixToneObject(&stru_81BFF9C, 1, 112);
  pt_size += MakePixToneObject(&stru_81BFFF0, 1, 113);
  pt_size += MakePixToneObject(&stru_81C0044, 2, 114);
  pt_size += MakePixToneObject(&stru_81C00EC, 2, 150);
  pt_size += MakePixToneObject(&stru_81C0194, 2, 151);
  pt_size += MakePixToneObject(&stru_81C023C, 1, 152);
  pt_size += MakePixToneObject(&stru_81C0290, 1, 153);
  pt_size += MakePixToneObject(&stru_81C02E4, 2, 154);
  pt_size += MakePixToneObject(&stru_81C062C, 2, 155);
  pt_size += MakePixToneObject(&stru_81C038C, 2, 56);
  pt_size += MakePixToneObject(&stru_81C0434, 2, 40);
  pt_size += MakePixToneObject(&stru_81C0434, 2, 41);
  pt_size += MakePixToneObject(&stru_81C04DC, 2, 37);
  pt_size += MakePixToneObject(&stru_81C0584, 2, 57);
  pt_size += MakePixToneObject(&stru_81C06D4, 3, 115);
  pt_size += MakePixToneObject(&stru_81C07D0, 1, 104);
  pt_size += MakePixToneObject(&stru_81C0824, 3, 116);
  pt_size += MakePixToneObject(&stru_81C0920, 2, 58);
  pt_size += MakePixToneObject(&stru_81C09C8, 2, 55);
  pt_size += MakePixToneObject(&stru_81C0A70, 2, 117);
  pt_size += MakePixToneObject(&stru_81C0B18, 1, 59);
  pt_size += MakePixToneObject(&stru_81C0B6C, 1, 60);
  pt_size += MakePixToneObject(&stru_81C0BC0, 1, 61);
  pt_size += MakePixToneObject(&stru_81C0C14, 2, 62);
  pt_size += MakePixToneObject(&stru_81C0CBC, 2, 63);
  pt_size += MakePixToneObject(&stru_81C0D64, 2, 64);
  pt_size += MakePixToneObject(&stru_81C0E0C, 1, 65);
  pt_size += MakePixToneObject(&stru_81C0E60, 1, 3);
  pt_size += MakePixToneObject(&stru_81C0EB4, 1, 6);
  pt_size += MakePixToneObject(&stru_81C0F08, 1, 7);
  sprintf(str, "PixTone = %ld byte", pt_size, 0);
  return 1;
}

