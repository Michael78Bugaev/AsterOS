#include <stdint.h>
#include <utils.h>
#include <idt.h>
#include <lowlevel_io.h>
#include <screen.h>
#include <timer.h>

uint64_t ticks;
const uint32_t freq = 1000;

void onIrq0(struct InterruptRegisters *regs)
{
    ticks += 1;
    //draw_text_int(0, 0, ticks, 0x3F);
    //int old = get_cursor();
    //set_cursor(0);//                                                                                \n"
    //kprint_colored(" AsterOS 0.01     Beta version                                                  \n", 0x1F);
    //set_cursor(old);
    //set_cursor(10);
    //kprint_int_colored(ticks, 0x9F);
}

void init_timer()
{
    // 119318.16666 Mz
    uint32_t divisor = 1193180 / freq;
    syscall("dtime: Setting up timer...\n", 0);
    syscall("On ", 0);
    print_hex(divisor);
    kprint(" (");
    kprint_int(divisor);
    kprint(")\n");
    ticks = 0;
    irq_install_handler(0, &onIrq0);

    port_byte_out(0x43, 0x36);
    port_byte_out(0x40, (uint8_t)(divisor & 0xFF));
    port_byte_out(0x40, (uint8_t)((divisor >> 8) & 0xFF));
}
void sleep(int ms) {
    uint64_t start = get_ticks();
    uint64_t target = start + (ms * freq / 1000);

    if (get_ticks() < target)
        sleep(target);
}

uint64_t get_ticks() { return ticks; }