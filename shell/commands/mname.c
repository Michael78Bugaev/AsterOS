#include <ash_commands.h>
#include <screen.h>
#include <utils.h>
#include <sysconfig.h>

int ash_mname()
{
    kprint(ASTER_NAME);
    kprint(" ");
    kprint(ASTER_VERSION);
    kprint(ASTER_PREFIX);
    kprint(" ");
    kprint_int(ASTER_YEAR);
    kprint("\n");
}