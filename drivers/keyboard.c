#include <keyboard.h>
#include <screen.h>
#include <idt.h>
#include <utils.h>
#include <sp.h>
#include <stdint.h>
#include <ash.h>
#include <uinfo.h>
#include <timer.h>
#include <stdbool.h>
#include <string.h>
#include <lowlevel_io.h>

bool capsOn = false;
bool capsLock = false;

char input[1024];

int backspace_func(char buffer[])
{
    int len = strlen(buffer);
    if (len > 0)
    {
        buffer[len - 1] = '\0';
        return 1;
    }
    else
    {
        return 0;
    }
}

void init_keyboard()
{

    irq_install_handler(1, &shell);

	//syscall("Keyboard handler is ready to get from you keys!\n", 0);
}

void shell(struct InterruptRegisters *regs)
{
    char scanCode = port_byte_in(0x60) & 0x7F;
	  char press = port_byte_in(0x60) & 0x80;
    //kprint(lowercase[0x22]);

    switch (scanCode)
    {
        case 1:
        case 29:
        case 56:
        case 59:
        case 60:
        case 61:
        case 62:
        case 63:
        case 64:
        case 65:
        case 66:
        case 67:
        case 68:
        case 87:
        case 88:
            break;
        case KEY_LEFT:
            if (get_cursor_x() > 0 && get_cursor_x() != 0)
            {
                set_cursor_xy(get_cursor_x() - 1, get_cursor_y());
            }
            break;
        case KEY_RIGHT:
            if (get_cursor_x() < 80 && get_cursor_x != 80)
            {
                set_cursor_xy(get_cursor_x(), get_cursor_y() + 1);
            }
            break;
        case 42:
            if (press == 0)
                capsOn = true;
            else
                capsOn = false;
            break;
        case 58:
            if (!capsLock && press == 0)
            {
                capsLock = true;
            }
            else if (capsLock && press == 0)
            {
                capsLock = false;
            }
            break;
        case 40:
            if (press)
                putchar('\'', 0x07);
                join(input, '\'');
            break;
        case 0x29:
            if (press)
                putchar('~', 0x07);
                join(input, '~');
            break;
        case 0x0E:
            if (press == 0)
                putchar('\b', 0x07);
                backspace_func(input);
            break;
        case 0x1C:
            if (press == 0)
            {
                kprint("\n");
                ash(input);
                input[0] = '\0';
                kprint("AsterOS > ");
            }
            else;    
                
            break;
        case 0x0F:
            if (press);
            break;
        default:
            if (press == 0)
            {
                if (capsOn || capsLock)
                {
                    putchar(get_acsii_high(scanCode), 0x07);
                    join(input, get_acsii_high(scanCode));
                }
                else
                {
                    putchar(get_acsii_low(scanCode), 0x07);
                    join(input, get_acsii_low(scanCode));
                }
            }
            break;
    }
}

void user_require(struct InterruptRegisters *regs)
{
    char scanCode = port_byte_in(0x60) & 0x7F;
	  char press = port_byte_in(0x60) & 0x80;
    //kprint(lowercase[0x22]);

    switch (scanCode)
    {
        case 1:
        case 29:
        case 56:
        case 59:
        case 60:
        case 61:
        case 62:
        case 63:
        case 64:
        case 65:
        case 66:
        case 67:
        case 68:
        case 87:
        case 88:
            break;
        case KEY_LEFT:
            if (get_cursor_x() > 0 && get_cursor_x() != 0)
            {
                set_cursor_xy(get_cursor_x() - 1, get_cursor_y());
            }
            break;
        case KEY_RIGHT:
            if (get_cursor_x() < 80 && get_cursor_x != 80)
            {
                set_cursor_xy(get_cursor_x(), get_cursor_y() + 1);
            }
            break;
        case 42:
            if (press == 0)
                capsOn = true;
            else
                capsOn = false;
            break;
        case 58:
            if (!capsLock && press == 0)
            {
                capsLock = true;
            }
            else if (capsLock && press == 0)
            {
                capsLock = false;
            }
            break;
        case 40:
            if (press)
                putchar('\'', 0x07);
                join(input, '\'');
            break;
        case 0x29:
            if (press)
                putchar('~', 0x07);
                join(input, '~');
            break;
        case 0x0E:
            if (press == 0)
                putchar('\b', 0x07);
                backspace_func(input);
            break;
        case 0x1C:
            if (press == 0)
            {
                kprint("\n");
                execute(input);
                input[0] = '\0';
            }
            else;    
                
            break;
        case 0x0F:
            if (press);
            break;
        default:
            if (press == 0)
            {
                if (capsOn || capsLock)
                {
                    putchar(get_acsii_high(scanCode), 0x07);
                    join(input, get_acsii_high(scanCode));
                }
                else
                {
                    putchar(get_acsii_low(scanCode), 0x07);
                    join(input, get_acsii_low(scanCode));
                }
            }
            break;
    }
}























void keyboard_handler(struct InterruptRegisters *regs)
{
	char scanCode = port_byte_in(0x60) & 0x7F;
	char press = port_byte_in(0x60) & 0x80;
    
    //kprint(lowercase[0x22]);

    switch (scanCode)
    {
        case 1:
        case 29:
        case 56:
        case 59:
        case 60:
        case 61:
        case 62:
        case 63:
        case 64:
        case 65:
        case 66:
        case 67:
        case 68:
        case 87:
        case 88:
            break;
        case KEY_LEFT:
            if (get_cursor_x() > 0 && get_cursor_x() != 0)
            {
                set_cursor_xy(get_cursor_x() - 1, get_cursor_y());
            }
            break;
        case KEY_RIGHT:
            if (get_cursor_x() < 80 && get_cursor_x != 80)
            {
                set_cursor_xy(get_cursor_x(), get_cursor_y() + 1);
            }
            break;
        case 42:
            if (press == 0)
                capsOn = true;
            else
                capsOn = false;
            break;
        case 58:
            if (!capsLock && press == 0)
            {
                capsLock = true;
            }
            else if (capsLock && press == 0)
            {
                capsLock = false;
            }
            break;
        case 40:
            if (press)
                putchar('\'', 0x07);
                join(input, '\'');
            break;
        case 0x29:
            if (press)
                putchar('~', 0x07);
            break;
        case 0x0E:
            if (press == 0)
                putchar('\b', 0x07);
            break;
        case 0x1C:
            if (press == 0)
                
            break;
        case 0x0F:
            if (press)
                    
            break;
        default:
            if (press == 0)
            {
                if (capsOn || capsLock)
                {
                    putchar(get_acsii_high(scanCode), 0x07);
                }
                else
                {
                    putchar(get_acsii_low(scanCode), 0x07);
                }
            }
            break;
    }

}
char get_acsii_low(char code)
{
     switch (code)
  {
  case KEY_A:
    return 'a';
  case KEY_B:
    return 'b';
  case KEY_C:
    return 'c';
  case KEY_D:
    return 'd';
  case KEY_E:
    return 'e';
  case KEY_F:
    return 'f';
  case KEY_G:
    return 'g';
  case KEY_H:
    return 'h';
  case KEY_I:
    return 'i';
  case KEY_J:
    return 'j';
  case KEY_K:
    return 'k';
  case KEY_L:
    return 'l';
  case KEY_M:
    return 'm';
  case KEY_N:
    return 'n';
  case KEY_O:
    return 'o';
  case KEY_P:
    return 'p';
  case KEY_Q:
    return 'q';
  case KEY_R:
    return 'r';
  case KEY_S:
    return 's';
  case KEY_T:
    return 't';
  case KEY_U:
    return 'u';
  case KEY_V:
    return 'v';
  case KEY_W:
    return 'w';
  case KEY_X:
    return 'x';
  case KEY_Y:
    return 'y';
  case KEY_Z:
    return 'z';
  case KEY_1:
    return '1';
  case KEY_2:
    return '2';
  case KEY_3:
    return '3';
  case KEY_4:
    return '4';
  case KEY_5:
    return '5';
  case KEY_6:
    return '6';
  case KEY_7:
    return '7';
  case KEY_8:
    return '8';
  case KEY_9:
    return '9';
  case KEY_0:
    return '0';
  case KEY_MINUS:
    return '-';
  case KEY_EQUAL:
    return '=';
  case KEY_SQUARE_OPEN_BRACKET:
    return '[';
  case KEY_SQUARE_CLOSE_BRACKET:
    return ']';
  case KEY_SEMICOLON:
    return ';';
  case KEY_BACKSLASH:
    return '\\';
  case KEY_COMMA:
    return ',';
  case KEY_DOT:
    return '.';
  case KEY_FORESLHASH:
    return '/';
  case KEY_SPACE:
    return ' ';
  default:
    return 0;
  }
}
char get_acsii_high(char code)
{
     switch (code)
  {
  case KEY_A:
    return 'A';
  case KEY_B:
    return 'B';
  case KEY_C:
    return 'C';
  case KEY_D:
    return 'D';
  case KEY_E:
    return 'E';
  case KEY_F:
    return 'F';
  case KEY_G:
    return 'G';
  case KEY_H:
    return 'H';
  case KEY_I:
    return 'I';
  case KEY_J:
    return 'J';
  case KEY_K:
    return 'K';
  case KEY_L:
    return 'L';
  case KEY_M:
    return 'M';
  case KEY_N:
    return 'N';
  case KEY_O:
    return 'O';
  case KEY_P:
    return 'P';
  case KEY_Q:
    return 'Q';
  case KEY_R:
    return 'R';
  case KEY_S:
    return 'S';
  case KEY_T:
    return 'T';
  case KEY_U:
    return 'U';
  case KEY_V:
    return 'V';
  case KEY_W:
    return 'W';
  case KEY_X:
    return 'X';
  case KEY_Y:
    return 'Y';
  case KEY_Z:
    return 'Z';
  case KEY_1:
    return '!';
  case KEY_2:
    return '@';
  case KEY_3:
    return '#';
  case KEY_4:
    return '$';
  case KEY_5:
    return '%';
  case KEY_6:
    return '^';
  case KEY_7:
    return '&';
  case KEY_8:
    return '*';
  case KEY_9:
    return '(';
  case KEY_0:
    return ')';
  case KEY_MINUS:
    return '_';
  case KEY_EQUAL:
    return '+';
  case KEY_SQUARE_OPEN_BRACKET:
    return '{';
  case KEY_SQUARE_CLOSE_BRACKET:
    return '}';
  case KEY_SEMICOLON:
    return ':';
  case KEY_BACKSLASH:
    return '|';
  case KEY_COMMA:
    return '<';
  case KEY_DOT:
    return '>';
  case KEY_FORESLHASH:
    return '?';
  case KEY_SPACE:
    return ' ';
  default:
    return 0;
  }
}