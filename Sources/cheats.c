#include "cheats.h"
#include "hid.h"


char	*builder_name = "itsRyan";

void	exceptSharpness(void)
{
	WRITEU32(0xC1EDC4, 0xE3510053);
	WRITEU32(0xC1EDC8, 0x3A00001);
	WRITEU32(0xC1EDCC, 0xE12FFF1E);
	WRITEU32(0xAF334C, 0xEA04AE9C);
	WRITEU32(0x4F79A8, 0xE1A00000);
	WRITEU32(0x4F79B4, 0xE3A00001);
}

void	code2(void)
{
	do_something
}

