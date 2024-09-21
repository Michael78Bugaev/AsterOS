#include <common.h>

enum msg_type
{
    INFO = 0,
    WARN = 1,
    ERR = 2,
    CERR = 3
};

void	kprint_rick_and_morty();
void	kprint_colored(u8 *str, u8 attr);
void syscall(u8 *msg, int type);
void print_hex(uint32_t num);