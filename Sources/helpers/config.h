unsigned char *fill_img = "Don't edit this.";
unsigned char *null_img = (void *)0x0;
//unsigned char *gateshark_label = "Don't edit this.";

#ifdef OLD
    #define BACKGROUND			fill_img
#else
    #define BACKGROUND			sumo_bg
#endif
#define BACKGROUND_POS_X		0
#define BACKGROUND_POS_Y		42
#define BACKGROUND_WIDTH		320
#define BACKGROUND_HEIGHT		198
#define BACKGROUND_RGB			1

#define SPLASH				BACKGROUND

#define UI_OFFSET			13

#ifdef OLD
    #define	CREDIT_LABEL			fill_img
#else
    #define	CREDIT_LABEL			credit_logo
#endif
#define CREDIT_LABEL_POS_X		0
#define CREDIT_LABEL_POS_Y		0
#define CREDIT_LABEL_WIDTH		320
#define CREDIT_LABEL_HEIGHT		42
#define CREDIT_LABEL_RGB		1

#ifdef OLD
    #define	CHEATS_LABEL			fill_img
#else
    #define	CHEATS_LABEL			cheats_logo
#endif
#define CHEATS_LABEL_POS_X		0
#define CHEATS_LABEL_POS_Y		0
#define CHEATS_LABEL_WIDTH		320
#define CHEATS_LABEL_HEIGHT		42
#define CHEATS_LABEL_RGB		1

#ifdef OLD
    #define	SPEED_LABEL			fill_img
#else
    #define SPEED_LABEL			speed_logo
#endif
#define SPEED_LABEL_POS_X		0
#define SPEED_LABEL_POS_Y		0
#define SPEED_LABEL_WIDTH		320
#define SPEED_LABEL_HEIGHT		42
#define SPEED_LABEL_RGB			1

#ifdef OLD
    #define	HOTKEY_LABEL			fill_img
#else
    #define HOTKEY_LABEL			hotkeys_logo
#endif
#define HOTKEY_LABEL_POS_X		0
#define HOTKEY_LABEL_POS_Y		0
#define HOTKEY_LABEL_WIDTH		320
#define HOTKEY_LABEL_HEIGHT		42
#define HOTKEY_LABEL_RGB		1

#ifdef OLD
    #define	NOTE_BACKGROUND			fill_img
#else
    #define NOTE_BACKGROUND			note_back2
#endif
#define NOTE_BACKGROUND_POS_X		30
#define NOTE_BACKGROUND_POS_Y		47
#define NOTE_BACKGROUND_WIDTH		260
#define NOTE_BACKGROUND_HEIGHT		145
#define NOTE_BACKGROUND_RGB		0
