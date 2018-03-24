#include "types.h"
#include "SDL_stdinc.h"
#include "windows_wrapper.h"
#include "Tags.h"

void ActBossChar_Ironhead()
{
	int v0;
	int v1;
	int v2;
	int v3;
	int v4;
	int v5;
	int v6;
	int v7;
	int v8;
	int v9;
	int v10;
	int v11;
	int v12;
	int v13;
	int v14;
	int v15;
	int v16;
	int v17;
	int v18;
	int v19;
	int v20;
	int v21;
	NPCHAR_0 *v22;
	Sint32 *v23;
	NPCHAR_0 *v24;
	Sint32 *v25;
	RECT rcDamage[9];
	RECT rc[9];
	int i;
	NPCHAR_0 *npc;
	char v30[24];

	npc = gBoss;
	v0 = gBoss[0].act_no;
	if (v0 == 101)
	{
	LABEL_16:
		if (++npc->act_wait > 50)
		{
			npc->act_no = 250;
			npc->act_wait = 0;
		}
		if (!(npc->act_wait & 3))
		{
			v1 = Random(2, 13) << 13;
			v2 = Random(15, 18);
			SetNpChar(197, v2 << 13, v1, 0, 0, 0, 0, 256);
		}
		goto LABEL_60;
	}
	if (v0 <= 101)
	{
		if (v0 == 1)
			goto LABEL_60;
		if (v0 != 100)
		{
			if (!v0)
			{
				npc->cond = -128;
				npc->exp = 1;
				npc->direct = 2;
				npc->act_no = 100;
				npc->x = 81920;
				npc->y = 0x10000;
				npc->view.front = 20480;
				npc->view.top = 6144;
				npc->view.back = 12288;
				npc->view.bottom = 6144;
				npc->hit_voice = 54;
				npc->hit.front = 0x2000;
				npc->hit.top = 5120;
				npc->hit.back = 0x2000;
				npc->hit.bottom = 5120;
				npc->bits = -32216;
				npc->size = 3;
				npc->damage = 10;
				npc->code_event = 1000;
				npc->life = 400;
			}
			goto LABEL_60;
		}
		npc->act_no = 101;
		npc->bits &= 0xFFDFu;
		npc->act_wait = 0;
		goto LABEL_16;
	}
	if (v0 == 251)
		goto LABEL_24;
	if (v0 <= 251)
	{
		if (v0 != 250)
			goto LABEL_60;
		npc->act_no = 251;
		if (npc->direct == 2)
		{
			npc->x = 122880;
			npc->y = y;
		}
		else
		{
			npc->x = 368640;
			npc->y = Random(2, 13) << 13;
		}
		npc->tgt_x = npc->x;
		npc->tgt_y = npc->y;
		npc->ym = Random(-512, 512);
		npc->xm = Random(-512, 512);
		npc->bits |= 0x20u;
	LABEL_24:
		if (npc->direct == 2)
		{
			npc->tgt_x += 1024;
		}
		else
		{
			npc->tgt_x -= 512;
			if (npc->tgt_y >= y)
				v3 = npc->tgt_y - 512;
			else
				v3 = npc->tgt_y + 512;
			npc->tgt_y = v3;
		}
		if (npc->x >= npc->tgt_x)
			v4 = npc->xm - 8;
		else
			v4 = npc->xm + 8;
		npc->xm = v4;
		if (npc->y >= npc->tgt_y)
			v5 = npc->ym - 8;
		else
			v5 = npc->ym + 8;
		npc->ym = v5;
		if (npc->ym > 512)
			npc->ym = 512;
		if (npc->ym < -512)
			npc->ym = -512;
		npc->x += npc->xm;
		npc->y += npc->ym;
		if (npc->direct == 2)
		{
			if (npc->x > 368640)
			{
				npc->direct = 0;
				npc->act_no = 100;
			}
		}
		else if (npc->x <= 139263)
		{
			npc->direct = 2;
			npc->act_no = 100;
		}
		if (!npc->direct && (++npc->act_wait == 300 || npc->act_wait == 310 || npc->act_wait == 320))
		{
			PlaySoundObject(39, 1);
			v6 = Random(-3, 3) << 9;
			v7 = Random(-3, 0);
			SetNpChar(198, npc->x + 5120, npc->y + 512, v7 << 9, v6, 2, 0, 256);
		}
		if (++npc->ani_wait > 2)
		{
			npc->ani_wait = 0;
			++npc->ani_no;
		}
		if (npc->ani_no > 7)
			npc->ani_no = 0;
		goto LABEL_60;
	}
	if (v0 == 1000)
	{
		npc->bits &= 0xFFDFu;
		npc->ani_no = 8;
		npc->damage = 0;
		npc->act_no = 1001;
		npc->tgt_x = npc->x;
		npc->tgt_y = npc->y;
		SetQuake(20);
		for (i = 0; i <= 31; ++i)
		{
			v8 = Random(-128, 128) << 9;
			v9 = Random(-128, 128) << 9;
			v10 = npc->y;
			v11 = (Random(-64, 64) << 9) + v10;
			v12 = npc->x;
			v13 = Random(-128, 128);
			SetNpChar(4, v12 + (v13 << 9), v11, v9, v8, 0, 0, 256);
		}
		DeleteNpCharCode(197, 1);
		DeleteNpCharCode(271, 1);
		DeleteNpCharCode(272, 1);
	}
	else if (v0 != 1001)
	{
		goto LABEL_60;
	}
	npc->tgt_x -= 512;
	v14 = npc->tgt_x;
	npc->x = v14 + (Random(-1, 1) << 9);
	v15 = npc->tgt_y;
	npc->y = v15 + (Random(-1, 1) << 9);
	if (!(++npc->act_wait & 3))
	{
		v16 = Random(-128, 128) << 9;
		v17 = Random(-128, 128) << 9;
		v18 = npc->y;
		v19 = (Random(-64, 64) << 9) + v18;
		v20 = npc->x;
		v21 = Random(-128, 128);
		SetNpChar(4, v20 + (v21 << 9), v19, v17, v16, 0, 0, 256);
	}
LABEL_60:
	qmemcpy(rc, &ActBossChar_Ironhead(void)::C.0, sizeof(rc));
	qmemcpy(rcDamage, &ActBossChar_Ironhead(void)::C.1, sizeof(rcDamage));
	if (npc->shock)
	{
		if ((++ActBossChar_Ironhead(void)::_flash >> 1) & 1)
		{
			v22 = npc;
			v23 = (Sint32 *)&v30[16 * npc->ani_no - 152];
		}
		else
		{
			v22 = npc;
			v23 = (Sint32 *)&v30[16 * npc->ani_no - 296];
		}
		npc->rect.left = *v23;
		v22->rect.top = v23[1];
		v22->rect.right = v23[2];
		v22->rect.bottom = v23[3];
	}
	else
	{
		v24 = npc;
		v25 = (Sint32 *)&v30[16 * npc->ani_no - 152];
		npc->rect.left = *v25;
		v24->rect.top = v25[1];
		v24->rect.right = v25[2];
		v24->rect.bottom = v25[3];
	}
}