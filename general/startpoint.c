#include <sp.h>
#include <stdint.h>
#include <mem.h>
#include <screen.h>
#include <utils.h>
#include <idt.h>
#include <timer.h>
#include <keyboard.h>
#include <string.h>
#include <stdbool.h>

void start_services()
{
    // Starting interrupts
    init_idt();

    // Starting timer
    init_timer();


    // Starting Dynamic Memory Managment
    init_dmem();
}
void execute(char input[])
{
    if (strcmp(input, "help") == 0)
    {
        kprint_colored("Aster Operating System", 0x06);
        kprint(" available built-in commands: \n");
        kprint_colored(" help", 0x09); kprint("  get a list of built-in commands\n");
        kprint_colored(" halt", 0x09); kprint("  halt the kernel\n");
    }
    else if (strcmp(input, "") == 0);
    else
    {
        kprint_colored("ash: error: Unknown command, or filename.", 0x0C);
    }
    kprint_colored("\nash", 0xA);
    kprint("-(asteros)-");
    kprint_colored("[0:\\]", 0x0D);
    kprint_colored("&", 0x0F);
}