#include <ash_commands.h>
#include <screen.h>

int ash_help()
{
    kprint(" available built-in commands: \n");
    kprint_colored(" help", 0x09); kprint ("  get a list of built-in commands\n");
    kprint_colored(" halt", 0x09); kprint ("  halt the kernel\n");
    kprint_colored(" clear", 0x09); kprint("  clear the screen\n");
    kprint_colored(" mem", 0x09); kprint  ("  print the memory\n");
    kprint_colored(" mname", 0x09); kprint ("  print the system version\n");

    return 0;
}