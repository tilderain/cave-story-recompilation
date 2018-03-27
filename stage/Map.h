
signed int InitMapData2();
signed int LoadMapData2(char *path_map);
signed int LoadAttributeData(char *path_atrb);
void EndMapData();
void ReleasePartsImage();
void GetMapData(unsigned __int8 **data, __int16 *mw, __int16 *ml);
int GetAttribute(int x, int y);
void DeleteMapParts(int x, int y);
void ShiftMapParts(int x, int y);
signed int ChangeMapParts(int x, int y, unsigned __int8 no);
void PutStage_Back(int fx, int fy);
void PutStage_Front(int fx, int fy);
void PutMapDataVector(int fx, int fy);
