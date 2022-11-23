unsigned long long KEY_POWER = 0x800f740c;
unsigned long long KEY_EJECTCD = 0x800f7428;
unsigned long long XboxFancyButton = 0x800ff464; 
unsigned long long KEY_STOP = 0x800ff419;
unsigned long long KEY_PAUSE = 0x800f7418; 
unsigned long long KEY_REWIND = 0x800ff415;
unsigned long long KEY_FASTFORWARD = 0x800f7414; 
unsigned long long KEY_PREVIOUS = 0x800ff41b;
unsigned long long KEY_NEXT = 0x800f741a;
unsigned long long KEY_PLAY = 0x800ff416;
unsigned long long KEY_ZOOM = 0x800f744f; 
unsigned long long KEY_TITLE = 0x800ff451;
unsigned long long KEY_MENU = 0x800f7424;
unsigned long long KEY_BACK = 0x800ff423;
unsigned long long KEY_INFO = 0x800f740f;
unsigned long long KEY_UP = 0x800ff41e; 
unsigned long long KEY_LEFT = 0x800f7420; 
unsigned long long KEY_RIGHT = 0x800ff421;
unsigned long long KEY_DOWN = 0x800f741f;
unsigned long long KEY_OK = 0x800ff422;
unsigned long long KEY_YELLOW = 0x800f7426;
unsigned long long KEY_BLUE = 0x800ff468;
unsigned long long KEY_GREEN = 0x800f7466;
unsigned long long KEY_RED = 0x800ff425;
unsigned long long KEY_CHANNELUP = 0x800f7412; 
unsigned long long KEY_CHANNELDOWN = 0x800ff413; 
unsigned long long KEY_VOLUMEDOWN = 0x800ff411;
unsigned long long KEY_VOLUMEUP = 0x800ff410;
unsigned long long KEY_MUTE = 0x800ff40e;
unsigned long long KEY_HOME = 0x800ff40d;
unsigned long long KEY_ENTER = 0x800ff40b; 
unsigned long long KEY_RECORD = 0x800f7417;
unsigned long long KEY_DELETE = 0x800ff40a;
unsigned long long KEY_NUMERIC_0 = 0x800f7400;
unsigned long long KEY_NUMERIC_1 = 0x800f7401;
unsigned long long KEY_NUMERIC_2 = 0x800ff402;
unsigned long long KEY_NUMERIC_3 = 0x800f7403;
unsigned long long KEY_NUMERIC_4 = 0x800ff404;
unsigned long long KEY_NUMERIC_5 = 0x800f7405;
unsigned long long KEY_NUMERIC_6 = 0x800ff406;
unsigned long long KEY_NUMERIC_7 = 0x800f7407;
unsigned long long KEY_NUMERIC_8 = 0x800ff408;
unsigned long long KEY_NUMERIC_9 = 0x800f7409;
unsigned long long KEY_NUMERIC_STAR = 0x800ff41d;
unsigned long long KEY_NUMERIC_POUND = 0x800f741c;


/*
          KEY_EJECTCD              0x0BD7
#         XBOXGUIDE                0x0B9B
          KEY_POWER                0x0BF3
          KEY_STOP                 0x0BE6
          KEY_PAUSE                0x0BE7
          KEY_REWIND               0x0BEA
          KEY_FASTFORWARD          0x0BEB
          KEY_PREVIOUS             0x0BE4
          KEY_NEXT                 0x0BE5
          KEY_PLAY                 0x0BE9
          KEY_ZOOM                 0x0BB0
          KEY_TITLE                0x0BAE
          KEY_MENU                 0x0BDB
          KEY_BACK                 0x0BDC
          KEY_INFO                 0x0BF0
          KEY_UP                   0x0BE1
          KEY_DOWN                 0x0BE0
          KEY_LEFT                 0x0BDF
          KEY_RIGHT                0x0BDE
          KEY_OK                   0x0BDD
          KEY_YEOW               0x0BD9
          KEY_BLUE                 0x0B97
          KEY_GREEN                0x0B99
          KEY_RED                  0x0BDA
          KEY_VOLUMEUP             0x0BEF
          KEY_VOLUMEDOWN           0x0BEE
          KEY_CHANNELUP            0x0B93
          KEY_CHANNELDOWN          0x0B92
          KEY_MUTE                 0x0BF1
          KEY_HOME                 0x0BF2
          KEY_ENTER                0x0BF4
          KEY_DELETE               0x0BF5
          KEY_RECORD               0x0BE8
          KEY_NUMERIC_1            0x0BFE
          KEY_NUMERIC_2            0x0BFD
          KEY_NUMERIC_3            0x0BFC
          KEY_NUMERIC_4            0x0BFB
          KEY_NUMERIC_5            0x0BFA
          KEY_NUMERIC_6            0x0BF9
          KEY_NUMERIC_7            0x0BF8
          KEY_NUMERIC_8            0x0BF7
          KEY_NUMERIC_9            0x0BF6
          KEY_NUMERIC_STAR         0x0BE2
          KEY_NUMERIC_0            0x0BFF
          KEY_NUMERIC_POUND        0x0BE3
*/
typedef struct{
  char* keyString;
  unsigned long long keyCode;
} keyType;
keyType keys[]= {
{"KEY_POWER",0x800f740c},
{"KEY_EJECTCD",0x800f7428},
{"XboxFancyButton",0x800ff464}, 
{"KEY_STOP",0x800ff419},
{"KEY_PAUSE",0x800f7418},
{"KEY_REWIND",0x800ff415},
{"KEY_FASTFORWARD",0x800f7414}, 
{"KEY_PREVIOUS",0x800ff41b},
{"KEY_NEXT",0x800f741a},
{"KEY_PLAY",0x800ff416},
{"KEY_ZOOM",0x800f744f},
{"KEY_TITLE",0x800ff451},
{"KEY_MENU",0x800f7424},
{"KEY_BACK",0x800ff423},
{"KEY_INFO",0x800f740f},
{"KEY_UP",0x800ff41e},
{"KEY_LEFT",0x800f7420},
{"KEY_RIGHT",0x800ff421},
{"KEY_DOWN",0x800f741f},
{"KEY_OK",0x800ff422},
{"KEY_YEOW",0x800f7426},
{"KEY_BLUE",0x800ff468},
{"KEY_GREEN",0x800f7466},
{"KEY_RED",0x800ff425},
{"KEY_CHANNELUP",0x800f7412},
{"KEY_CHANNELDOWN",0x800ff413}, 
{"KEY_VOLUMEDOWN",0x800ff411},
{"KEY_VOLUMEUP",0x800ff410},
{"KEY_MUTE",0x800ff40e},
{"KEY_HOME",0x800ff40d},
{"KEY_ENTER",0x800ff40b},
{"KEY_RECORD",0x800f7417},
{"KEY_DELETE",0x800ff40a},
{"KEY_NUMERIC_0",0x800f7400},
{"KEY_NUMERIC_1",0x800f7401},
{"KEY_NUMERIC_2",0x800ff402},
{"KEY_NUMERIC_3",0x800f7403},
{"KEY_NUMERIC_4",0x800ff404},
{"KEY_NUMERIC_5",0x800f7405},
{"KEY_NUMERIC_6",0x800ff406},
{"KEY_NUMERIC_7",0x800f7407},
{"KEY_NUMERIC_8",0x800ff408},
{"KEY_NUMERIC_9",0x800f7409},
{"KEY_NUMERIC_STAR",0x800ff41d},
{"KEY_NUMERIC_POUND",0x800f741c},
};
