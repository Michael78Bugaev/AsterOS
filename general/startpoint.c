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

char current_dir[512] = "0:\\";

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
        kprint_colored(" clear", 0x09); kprint("  clear the screen\n");
        kprint_colored(" mem", 0x09); kprint("  print the memory");

    }
    else if (strcmp(input, "") == 0);
    else if (strcmp(input, "halt") == 0)
    {
        syscall("System halted. Exit code: ", 0x03);
        print_hex(2048);
        set_cursor(0);
        halt();

    }
    else if (strcmp(input, "vga") == 0)
    {
        clear_screen();
        for (int i = 0; i < 256; i++)
        {
            putchar(i, 0x07);
        }
        kprint("╬");
    }
    else if (strcmp(input, "clear"))
    {
        clear_screen();
    }
    else if (strcmp(input, "mem"))
    {

    }
    else if (startsWith(input, '#') == 0);
    else
    {
        kprint_colored("ash: error: Unknown command, or filename.", 0x0C);
    }
    kprint_colored("\nash", 0xA);
    kprint("-(asteros)-");
    kprint_colored("[", 0x0D);
    kprint_colored(current_dir, 0x0D);
    kprint_colored("]", 0x0D);
    kprint_colored(">&", 0x0F);
}