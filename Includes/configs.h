#ifndef WRITEU8
#	define WRITEU8(addr, data) 		*(vu8*)(addr) = data
#endif
#ifndef WRITEU16
#	define WRITEU16(addr, data) 	*(vu16*)(addr) = data
#endif
#ifndef WRITEU32
#	define WRITEU32(addr, data) 	*(vu32*)(addr) = data
#endif
#ifndef READU8
#	define READU8(addr) 			*(volatile unsigned char*)(addr)
#endif
#ifndef READU16
#	define READU16(addr) 			*(volatile unsigned short*)(addr)
#endif
#ifndef READU32
#	define READU32(addr) 			*(volatile unsigned int*)(addr)
#endif

#ifndef IO_BASE_PAD
#	define IO_BASE_PAD				1
#endif
#ifndef IO_BASE_LCD
#	define IO_BASE_LCD				2
#endif
#ifndef IO_BASE_PDC
#	define IO_BASE_PDC				3
#endif
#ifndef IO_BASE_GSPHEAP
#	define IO_BASE_GSPHEAP			4
#endif
#ifndef BUTTON_A
#	define BUTTON_A 				0x00000001
#endif
#ifndef BUTTON_B
#	define BUTTON_B 				0x00000002
#endif
#ifndef BUTTON_SE
#	define BUTTON_SE 				0x00000004
#endif
#ifndef BUTTON_ST
#	define BUTTON_ST 				0x00000008
#endif
#ifndef BUTTON_DR
#	define BUTTON_DR 				0x00000010
#endif
#ifndef BUTTON_DL
#	define BUTTON_DL 				0x00000020
#endif
#ifndef BUTTON_DU
#	define BUTTON_DU 				0x00000040
#endif
#ifndef BUTTON_DD
#	define BUTTON_DD 				0x00000080
#endif
#ifndef BUTTON_R
#	define BUTTON_R 				0x00000100
#endif
#ifndef BUTTON_L
#	define BUTTON_L 				0x00000200
#endif
#ifndef BUTTON_ZR
#	define BUTTON_ZR 				0x00008000
#endif
#ifndef BUTTON_ZL
#	define BUTTON_ZL 				0x00004000
#endif
#ifndef BUTTON_X
#	define BUTTON_X 				0x00000400
#endif
#ifndef BUTTON_Y
#	define BUTTON_Y 				0x00000800
#endif

#ifndef A
#	define A						BUTTON_A
#endif
#ifndef B
#	define B						BUTTON_B
#endif
#ifndef X
#	define X						BUTTON_X
#endif
#ifndef Y
#	define Y						BUTTON_Y
#endif
#ifndef L
#	define L						BUTTON_L
#endif
#ifndef R
#	define R						BUTTON_R
#endif
#ifndef ZL
#	define ZL						BUTTON_ZL
#endif
#ifndef ZR
#	define ZR						BUTTON_ZR
#endif
#ifndef ST
#	define ST						BUTTON_ST
#endif
#ifndef SE
#	define SE						BUTTON_SE
#endif
#ifndef DU
#	define DU						BUTTON_DU
#endif
#ifndef DD
#	define DD						BUTTON_DD
#endif
#ifndef DL
#	define DL						BUTTON_DL
#endif
#ifndef DR
#	define DR						BUTTON_DR
#endif