#include <common.h>
#include <screen.h>
#include <keyboard.h>
#include <lowlevel_io.h>
#include <utils.h>
#include <timer.h>
#include <sp.h>
#include <mem.h>
#include <idt.h>
#include <ash.h>

s32		kmain()
{	
	clear_screen();
	syscall("Starting kernel\n", 0);
	start_services();
	// -= ENTRY POINT IN KERNEL =- //
    syscall("Running ASH as a main script\n", 0);
	kprint("ash version 0.1\n");
	kprint("\nAsterOS > ");
    init_keyboard();


    // -=========================- //
	return 0;
}
