#pragma once
#include "../types.h"
#include <SDL.h>
#include "../windows_wrapper.h"
#include "../common.h"
#include "../Tags.h"

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

$3999A2E3BC6E7A1D19AF6FBFAF274F94 *gNpcTable;