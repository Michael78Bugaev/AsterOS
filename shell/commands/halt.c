#include <ash_commands.h>
#include <screen.h>
#include <utils.h>

int ash_halt()
{
    set_cursor(0);//                                                                                "
    kprint_colored(" System halted | User interrupt      AsterOS      Now you can turn off computer ", 0x4F);
    halt();
}