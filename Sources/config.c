#include "config.h"

#define NULL	(void *)0

#define POS(x, y) (x | (y << 16))
#define DIM(w, h) (w | (h << 16))

typedef struct	s_img_infos
{
	int			pos;
	int			dimension;
	int			rgb;
}				t_img_infos;

extern unsigned int  ui_offset;
extern unsigned char *BACKGROUND;
//extern unsigned char *SPLASH;
extern unsigned char *NOTE_BACKGROUND;
extern unsigned char *CHEATS_LABEL;
extern unsigned char *SPEED_LABEL;
extern unsigned char *HOTKEY_LABEL;
extern unsigned char *CREDIT_LABEL;
unsigned char	*background_img = NULL;
unsigned char	*credit_label = NULL;
unsigned char	*splash_img = NULL;
unsigned char	*cheats_label = NULL;
unsigned char	*speed_label = NULL;
unsigned char	*hotkey_label = NULL;
unsigned char	*note_background = NULL;
t_img_infos		background_infos = { 0, 0, 0};
t_img_infos		cheats_label_infos = { 0, 0, 0 };
t_img_infos		speed_label_infos = { 0, 0, 0 };
t_img_infos		hotkey_label_infos = { 0, 0, 0 };
t_img_infos		credit_label_infos = { 0, 0, 0 };
t_img_infos		note_background_infos = { 0, 0, 0 };


void	init_img(void)
{
	ui_offset = UI_OFFSET;
	background_img = (unsigned char *)BACKGROUND;
	//splash_img = SPLASH;
	note_background = (unsigned char *)NOTE_BACKGROUND;
	cheats_label = CHEATS_LABEL;
	speed_label = SPEED_LABEL;
	hotkey_label = HOTKEY_LABEL;
	credit_label = CREDIT_LABEL;
	background_infos = (t_img_infos) { POS(BACKGROUND_POS_X, BACKGROUND_POS_Y), DIM(BACKGROUND_WIDTH, BACKGROUND_HEIGHT), BACKGROUND_RGB };
	cheats_label_infos = (t_img_infos) { POS(CHEATS_LABEL_POS_X, CHEATS_LABEL_POS_Y), DIM(CHEATS_LABEL_WIDTH, CHEATS_LABEL_HEIGHT), CHEATS_LABEL_RGB };
	speed_label_infos = (t_img_infos) { POS(SPEED_LABEL_POS_X, SPEED_LABEL_POS_Y), DIM(SPEED_LABEL_WIDTH, SPEED_LABEL_HEIGHT), SPEED_LABEL_RGB };
	hotkey_label_infos = (t_img_infos) { POS(HOTKEY_LABEL_POS_X, HOTKEY_LABEL_POS_Y), DIM(HOTKEY_LABEL_WIDTH, HOTKEY_LABEL_HEIGHT), HOTKEY_LABEL_RGB };
	credit_label_infos = (t_img_infos) { POS(CREDIT_LABEL_POS_X, CREDIT_LABEL_POS_Y), DIM(CREDIT_LABEL_WIDTH, CREDIT_LABEL_HEIGHT), CREDIT_LABEL_RGB };
	note_background_infos = (t_img_infos) { POS(NOTE_BACKGROUND_POS_X, NOTE_BACKGROUND_POS_Y), DIM(NOTE_BACKGROUND_WIDTH, NOTE_BACKGROUND_HEIGHT), NOTE_BACKGROUND_RGB };
}