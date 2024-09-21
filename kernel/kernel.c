#include <common.h>
#include <screen.h>
#include <keyboard.h>
#include <lowlevel_io.h>
#include <utils.h>
#include <timer.h>
#include <idt.h>

s32		kmain()
{	
	//set_vga_mode_640x480x8();
	//clear_vga_screen(0x00);
	clear_screen();//                                                                                \n"
	set_cursor(0);
	syscall("Loading kernel...\n", 0);
	sleep(5);
	int i = 1 / 0;
	init_idt();
	init_timer();
	init_keyboard();
	return 0;
}
