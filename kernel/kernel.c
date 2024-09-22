#include <common.h>
#include <screen.h>
#include <keyboard.h>
#include <lowlevel_io.h>
#include <utils.h>
#include <timer.h>
#include <sp.h>
#include <mem.h>
#include <idt.h>

s32		kmain()
{	
	clear_screen();
	syscall("Starting kernel\n", 0);
	start_services();
	// -= ENTRY POINT IN KERNEL =- //
    syscall("Running ASH as a main script\n", 0);
	kprint("\nWelcome to The "); kprint_colored("Aster Operating System", 0x06);
	kprint("!\n");
	kprint("(AsterOS v.0.01beta)\n"
           "Special beta (not release!) version.\n"
           "Type \"help\" to get some help\n\n");
	kprint_colored("ash", 0xA);
    kprint("-(asteros)-");
    kprint_colored("[0:\\]", 0x0D);
    kprint_colored("&", 0x0F);
    init_keyboard();
    // -=========================- //
	return 0;
}
