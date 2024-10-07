#include <ash.h>
#include <string.h>
#include <screen.h>
#include <keyboard.h>
#include <ash_commands.h>

void ash(char arg[])
{
    if (startsWith(arg, '#') == 0);
    else if (strcmp(arg, 0) == 0);
    if (strcmp(arg, "clear") == 0)
    {
        int ex = ash_clear();
        if (ex == 0);
        else exit(ex, arg);
    }
    else if (strcmp(arg, "help") == 0)
    {
        int ex = ash_help();
        if (ex == 0);
        else exit(ex, arg);
    }
    else if (strcmp(arg, "mem") == 0)
    {
        int ex = ash_mem();
        if (ex == 0);
        else exit(ex, arg);
    }
    else if (strcmp(arg, "halt") == 0)
    {
        ash_halt();
    }
    else if (strcmp(arg, "mname") == 0)
    {
        ash_mname();
    }
    else if (strcmp(arg, "1/0") == 0)
    {
        kprint(1/0);
    }
    else
    {
        kprint("ash: unknown '");
        kprint(arg);
        kprint("' command\n");
    }
}

void exit(int exitcode, char com_name[])
{
    kprint("ash: error: program '");
    kprint(com_name);
    kprint("' exited with code ");
    kprint_int(exitcode);
    kprint("\n");
}