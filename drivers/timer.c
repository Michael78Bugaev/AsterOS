#include <stdint.h>
#include <utils.h>
#include <idt.h>
#include <lowlevel_io.h>
#include <screen.h>
#include <timer.h>

uint64_t ticks;
const uint32_t freq = 100;

void onIrq0(struct InterruptRegisters *regs)
{
    ticks += 1;
    //int old = get_cursor();
    //set_cursor(0);//                                                                                \n"
    //kprint_colored(" AsterOS 0.01     Beta version                                                  \n", 0x1F);
    //set_cursor(old);
    //set_cursor(10);
    //kprint_int_colored(ticks, 0x9F);
}

void init_timer()
{
    syscall("Setting up timer...\n", 0);
    ticks = 0;
    irq_install_handler(0, &onIrq0);

    // 119318.16666 Mz
    uint32_t divisor = 1193180 / freq;
    port_byte_out(0x43, 0x36);
    port_byte_out(0x40, (uint8_t)(divisor & 0xFF));
    port_byte_out(0x40, (uint8_t)((divisor >> 8) & 0xFF));
}
void sleep(int ms) {
    uint64_t target_ticks = ticks + (ms * freq / 1000);
    while (ticks < target_ticks) {
        // Do nothing, just wait for the timer to tick
    }
}

uint64_t get_ticks() { return ticks; }