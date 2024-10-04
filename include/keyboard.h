#include <stdint.h>
#include <common.h>

#define KEY_A 0x1E
#define KEY_B 0x30
#define KEY_C 0x2E
#define KEY_D 0x20
#define KEY_E 0x12
#define KEY_F 0x21
#define KEY_G 0x22
#define KEY_H 0x23
#define KEY_I 0x17
#define KEY_J 0x24
#define KEY_K 0x25
#define KEY_L 0x26
#define KEY_M 0x32
#define KEY_N 0x31
#define KEY_O 0x18
#define KEY_P 0x19
#define KEY_Q 0x10
#define KEY_R 0x13
#define KEY_S 0x1F
#define KEY_T 0x14
#define KEY_U 0x16
#define KEY_V 0x2F
#define KEY_W 0x11
#define KEY_X 0x2D
#define KEY_Y 0x15
#define KEY_Z 0x2C
#define KEY_1 0x02
#define KEY_2 0x03
#define KEY_3 0x04
#define KEY_4 0x05
#define KEY_5 0x06
#define KEY_6 0x07
#define KEY_7 0x08
#define KEY_8 0x09
#define KEY_9 0x0A
#define KEY_0 0x0B
#define KEY_MINUS 0x0C
#define KEY_EQUAL 0x0D
#define KEY_SQUARE_OPEN_BRACKET 0x1A
#define KEY_SQUARE_CLOSE_BRACKET 0x1B
#define KEY_SEMICOLON 0x27
#define KEY_BACKSLASH 0x2B
#define KEY_COMMA 0x33
#define KEY_DOT 0x34
#define KEY_FORESLHASH 0x35
#define KEY_F1 0x3B
#define KEY_F2 0x3C
#define KEY_F3 0x3D
#define KEY_F4 0x3E
#define KEY_F5 0x3F
#define KEY_F6 0x40
#define KEY_F7 0x41
#define KEY_F8 0x42
#define KEY_F9 0x43
#define KEY_F10 0x44
#define KEY_F11 0x85
#define KEY_F12 0x86
#define KEY_BACKSPACE 0x0E
#define KEY_DELETE 0x53
#define KEY_DOWN 0x50
#define KEY_END 0x4F
#define KEY_ENTER 0x1C
#define KEY_ESC 0x01
#define KEY_HOME 0x47
#define KEY_INSERT 0x52
#define KEY_KEYPAD_5 0x4C
#define KEY_KEYPAD_MUL 0x37
#define KEY_KEYPAD_Minus 0x4A
#define KEY_KEYPAD_PLUS 0x4E
#define KEY_KEYPAD_DIV 0x35
#define KEY_LEFT 0x4B
#define KEY_PAGE_DOWN 0x51
#define KEY_PAGE_UP 0x49
#define KEY_PRINT_SCREEN 0x37
#define KEY_RIGHT 0x4D
#define KEY_SPACE 0x39
#define KEY_TAB 0x0F
#define KEY_UP 0x48

#define UNKNOWN 0xFFFFFFFF
#define ESC 0xFFFFFFFF - 1
#define CTRL 0xFFFFFFFF - 2
#define LSHFT 0xFFFFFFFF - 3
#define RSHFT 0xFFFFFFFF - 4
#define ALT 0xFFFFFFFF - 5
#define F1 0xFFFFFFFF - 6
#define F2 0xFFFFFFFF - 7
#define F3 0xFFFFFFFF - 8
#define F4 0xFFFFFFFF - 9
#define F5 0xFFFFFFFF - 10
#define F6 0xFFFFFFFF - 11
#define F7 0xFFFFFFFF - 12
#define F8 0xFFFFFFFF - 13
#define F9 0xFFFFFFFF - 14
#define F10 0xFFFFFFFF - 15
#define F11 0xFFFFFFFF - 16
#define F12 0xFFFFFFFF - 17
#define SCRLCK 0xFFFFFFFF - 18
#define HOME 0xFFFFFFFF - 19
#define UP 0xFFFFFFFF - 20
#define LEFT 0xFFFFFFFF - 21
#define RIGHT 0xFFFFFFFF - 22
#define DOWN 0xFFFFFFFF - 23
#define PGUP 0xFFFFFFFF - 24
#define PGDOWN 0xFFFFFFFF - 25
#define END 0xFFFFFFFF - 26
#define INS 0xFFFFFFFF - 27
#define DEL 0xFFFFFFFF - 28
#define CAPS 0xFFFFFFFF - 29
#define NONE 0xFFFFFFFF - 30
#define ALTGR 0xFFFFFFFF - 31
#define NUMLCK 0xFFFFFFFF - 32

int backspace_func(char buffer[]);
void init_keyboard();
void shell(struct InterruptRegisters *regs);
void user_require(struct InterruptRegisters *regs);
void keyboard_handler(struct InterruptRegisters *regs);
char get_acsii_low(char code);
char get_acsii_high(char code);