#include <common.h>
#include <stdint.h>

void init_timer();
void onIrq0(struct InterruptRegisters *regs);
void sleep(int ms);
uint64_t get_ticks();