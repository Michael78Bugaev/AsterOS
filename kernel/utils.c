#include <utils.h>
#include <screen.h>
#include <timer.h>
#include <common.h>

void	kprint_colored(u8 *str, u8 attr)
{
	while (*str)
	{
		if (*str == '_')
			putchar(*str, 0x00);	
		else
			putchar(*str, attr);
		str++;
	}
}	

void syscall(u8 *msg, int type)
{
	if (type == 0)
	{
		kprint_colored("[", 0x07);
		kprint_timetick();
		kprint_colored("]", 0x07);
		kprint(": ");
		kprint("info: ");
		kprint(msg);
	}
	else if (type == 1)
	{
		kprint_colored("[", 0x07);
		kprint_timetick();
		kprint_colored("]", 0x07);
		kprint(": ");
		kprint("warning: ");
		kprint(msg);
	}
	else if (type == 2)
	{
		kprint_colored("[", 0x07);
		kprint_timetick();
		kprint_colored("]", 0x07);
		kprint(": ");
		kprint("error: ");
		kprint(msg);
	}
	else if (type == 3)
	{
		kprint_colored("[", 0x07);
		kprint_timetick();
		kprint_colored("]", 0x07);
		kprint_colored(": ", 0x07);
		kprint("fatal error: ");
		kprint_colored(msg, 0x07);
	}
}

void print_hex(uint32_t num)
{
	char hex[9]; // 8 characters for the hex representation + 1 for the null terminator
    int i;

    for (i = 7; i >= 0; i--) {
        uint32_t temp = num & 0xF;
        if (temp < 10)
            hex[i] = temp + '0';
        else
            hex[i] = temp + 'A' - 10;
        num >>= 4;
    }
    //hex[8] = '\0'; // null terminate the string

    kprint("0x");
	kprint(hex);
}