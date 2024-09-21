#include <keyboard.h>
#include <screen.h>
#include <idt.h>
#include <utils.h>
#include <stdint.h>
#include <timer.h>
#include <stdbool.h>
#include <lowlevel_io.h>

uint8_t lowercase[128] = {
0,0,'1','2','3','4','5','6','7','8',
'9','0','-','=','\b','\t','q','w','e','r',
't','y','u','i','o','p','[',']','\n',0,
'a','s','d','f','g','h','j','k','l',';',
'\'','`',0,'\\','z','x','c','v','b','n','m',',',
'.','/',0,'*',0,' ',0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,'-',0,0,0,
'+',0,0,0,0,0,0,0,0,01,02,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0
};

uint8_t uppercase[128] = {
    0,0,'!','@','#','$','%','^','&','*','(',')','_','+','\b','\t','Q','W','E','R',
'T','Y','U','I','O','P','{','}','\n',0,'A','S','D','F','G','H','J','K','L',':','"','~',0,'|','Z','X','C',
'V','B','N','M','<','>','?',0,'*',0,' ',0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,'-',
0,0,0,'+',0,0,0,0,0,0,0,0,01,02,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0
};


bool capsOn = false;
bool capsLock = false;

void init_keyboard()
{
    irq_install_handler(1, &keyboard_handler);

	//syscall("Keyboard handler is ready to get from you keys!\n", 0);
}
void keyboard_handler(struct InterruptRegisters *regs)
{
	char scanCode = port_byte_in(0x60) & 0x7F;
	char press = port_byte_in(0x60) & 0x80;
    
    kprint(lowercase[0x22]);

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
        case 0x1C:
            kprint("\n");
            break;
        default:
            if (press == 0)
            {
                if (capsOn || capsLock)
                {
                    if (scanCode == 0x1E)
                    {
                        kprint('A');
                    }
                    else if (scanCode == KEY_B)
                    {
                        kprint('B');
                    }
                }
                else
                {
                    kprint(lowercase[scanCode]);
                }
            }
            break;
    }

}