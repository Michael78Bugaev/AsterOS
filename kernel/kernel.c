#include <common.h>
#include <screen.h>
#include <keyboard.h>
#include <lowlevel_io.h>
#include <utils.h>
#include <timer.h>
#include <sp.h>
#include <mem.h>
#include <idt.h>
#include <sysconfig.h>
#include <ash.h>

s32	kmain()
{	
	clear_screen();
	kprint("Welcome to Aster!\n");
	start_services();
	// -= ENTRY POINT IN KERNEL =- //
    kprint("kstart: Running ASH as a main script\n");
	kprint("ash version 0.1\n");
	//kprint(1/0);
	kprint("\n");
	kprint(get_cur_dir());
	kprint(">");
    init_keyboard();


    // -=========================- //
	return 0;
}
