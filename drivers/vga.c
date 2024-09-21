#include <stdint.h>
#include <stddef.h>
#include <vga.h>
#include <lowlevel_io.h>

uint32_t *VGA_MEMORY = (uint32_t*)0xA0000;

// VGA mode 0x12 (640x480x16)
void set_vga_mode_640x480x8() {
    // Set MISC register
    port_byte_out(VGA_MISC_WRITE, 0x63);

    // Set SEQ registers
    port_byte_out(VGA_SEQ_INDEX, 0x00); port_byte_out(VGA_SEQ_DATA, 0x03);
    port_byte_out(VGA_SEQ_INDEX, 0x01); port_byte_out(VGA_SEQ_DATA, 0x01);
    port_byte_out(VGA_SEQ_INDEX, 0x02); port_byte_out(VGA_SEQ_DATA, 0x0F);
    port_byte_out(VGA_SEQ_INDEX, 0x03); port_byte_out(VGA_SEQ_DATA, 0x00);
    port_byte_out(VGA_SEQ_INDEX, 0x04); port_byte_out(VGA_SEQ_DATA, 0x06);

    // Set CRTC registers
    port_byte_out(VGA_CRTC_INDEX, 0x00); port_byte_out(VGA_CRTC_DATA, 0x5F);
    port_byte_out(VGA_CRTC_INDEX, 0x01); port_byte_out(VGA_CRTC_DATA, 0x4F);
    port_byte_out(VGA_CRTC_INDEX, 0x02); port_byte_out(VGA_CRTC_DATA, 0x50);
    port_byte_out(VGA_CRTC_INDEX, 0x03); port_byte_out(VGA_CRTC_DATA, 0x82);
    port_byte_out(VGA_CRTC_INDEX, 0x04); port_byte_out(VGA_CRTC_DATA, 0x54);
    port_byte_out(VGA_CRTC_INDEX, 0x05); port_byte_out(VGA_CRTC_DATA, 0x80);
    port_byte_out(VGA_CRTC_INDEX, 0x06); port_byte_out(VGA_CRTC_DATA, 0x0B);
    port_byte_out(VGA_CRTC_INDEX, 0x07); port_byte_out(VGA_CRTC_DATA, 0x3E);
    port_byte_out(VGA_CRTC_INDEX, 0x09); port_byte_out(VGA_CRTC_DATA, 0x40);
    port_byte_out(VGA_CRTC_INDEX, 0x10); port_byte_out(VGA_CRTC_DATA, 0x00);
    port_byte_out(VGA_CRTC_INDEX, 0x11); port_byte_out(VGA_CRTC_DATA, 0x00);
    port_byte_out(VGA_CRTC_INDEX, 0x12); port_byte_out(VGA_CRTC_DATA, 0x0F);
    port_byte_out(VGA_CRTC_INDEX, 0x13); port_byte_out(VGA_CRTC_DATA, 0x00);
    port_byte_out(VGA_CRTC_INDEX, 0x14); port_byte_out(VGA_CRTC_DATA, 0x00);
    port_byte_out(VGA_CRTC_INDEX, 0x15); port_byte_out(VGA_CRTC_DATA, 0x00);
    port_byte_out(VGA_CRTC_INDEX, 0x16); port_byte_out(VGA_CRTC_DATA, 0x9C);
    port_byte_out(VGA_CRTC_INDEX, 0x17); port_byte_out(VGA_CRTC_DATA, 0x0E);

    // Set GC registers
    port_byte_out(VGA_GC_INDEX, 0x00); port_byte_out(VGA_GC_DATA, 0x00);
    port_byte_out(VGA_GC_INDEX, 0x01); port_byte_out(VGA_GC_DATA, 0x00);
    port_byte_out(VGA_GC_INDEX, 0x02); port_byte_out(VGA_GC_DATA, 0x00);
    port_byte_out(VGA_GC_INDEX, 0x03); port_byte_out(VGA_GC_DATA, 0x00);
    port_byte_out(VGA_GC_INDEX, 0x04); port_byte_out(VGA_GC_DATA, 0x00);
    port_byte_out(VGA_GC_INDEX, 0x05); port_byte_out(VGA_GC_DATA, 0x40);
    port_byte_out(VGA_GC_INDEX, 0x06); port_byte_out(VGA_GC_DATA, 0x05);
    port_byte_out(VGA_GC_INDEX, 0x07); port_byte_out(VGA_GC_DATA, 0x0F);
    port_byte_out(VGA_GC_INDEX, 0x08); port_byte_out(VGA_GC_DATA, 0xFF);

    // Set AC registers
    port_byte_out(VGA_AC_INDEX, 0x00); port_byte_out(VGA_AC_WRITE, 0x00);
    port_byte_out(VGA_AC_INDEX, 0x01); port_byte_out(VGA_AC_WRITE, 0x01);
    port_byte_out(VGA_AC_INDEX, 0x02); port_byte_out(VGA_AC_WRITE, 0x02);
    port_byte_out(VGA_AC_INDEX, 0x03); port_byte_out(VGA_AC_WRITE, 0x03);
    port_byte_out(VGA_AC_INDEX, 0x04); port_byte_out(VGA_AC_WRITE, 0x04);
    port_byte_out(VGA_AC_INDEX, 0x05); port_byte_out(VGA_AC_WRITE, 0x05);
    port_byte_out(VGA_AC_INDEX, 0x06); port_byte_out(VGA_AC_WRITE, 0x06);
    port_byte_out(VGA_AC_INDEX, 0x07); port_byte_out(VGA_AC_WRITE, 0x07);
    port_byte_out(VGA_AC_INDEX, 0x08); port_byte_out(VGA_AC_WRITE, 0x08);
    port_byte_out(VGA_AC_INDEX, 0x09); port_byte_out(VGA_AC_WRITE, 0x09);
    port_byte_out(VGA_AC_INDEX, 0x0A); port_byte_out(VGA_AC_WRITE, 0x0A);
    port_byte_out(VGA_AC_INDEX, 0x0B); port_byte_out(VGA_AC_WRITE, 0x0B);
    port_byte_out(VGA_AC_INDEX, 0x0C); port_byte_out(VGA_AC_WRITE, 0x0C);
    port_byte_out(VGA_AC_INDEX, 0x0D); port_byte_out(VGA_AC_WRITE, 0x0D);
    port_byte_out(VGA_AC_INDEX, 0x0E); port_byte_out(VGA_AC_WRITE, 0x0E);
    port_byte_out(VGA_AC_INDEX, 0x0F); port_byte_out(VGA_AC_WRITE, 0x0F);
    port_byte_out(VGA_AC_INDEX, 0x10); port_byte_out(VGA_AC_WRITE, 0x41);
    port_byte_out(VGA_AC_INDEX, 0x11); port_byte_out(VGA_AC_WRITE, 0x00);
    port_byte_out(VGA_AC_INDEX, 0x12); port_byte_out(VGA_AC_WRITE, 0x0F);
    port_byte_out(VGA_AC_INDEX, 0x13); port_byte_out(VGA_AC_WRITE, 0x00);
    port_byte_out(VGA_AC_INDEX, 0x14); port_byte_out(VGA_AC_WRITE, 0x00);

    // Unlock CRTC registers
    port_byte_out(VGA_CRTC_INDEX, 0x11);
    uint8_t temp = port_byte_in(VGA_CRTC_DATA) & ~0x80;
    port_byte_out(VGA_CRTC_DATA, temp);

    // Set CRTC registers
    port_byte_out(VGA_CRTC_INDEX, 0x00); port_byte_out(VGA_CRTC_DATA, 0x5F);
    port_byte_out(VGA_CRTC_INDEX, 0x01); port_byte_out(VGA_CRTC_DATA, 0x4F);
    port_byte_out(VGA_CRTC_INDEX, 0x02); port_byte_out(VGA_CRTC_DATA, 0x50);
    port_byte_out(VGA_CRTC_INDEX, 0x03); port_byte_out(VGA_CRTC_DATA, 0x82);
    port_byte_out(VGA_CRTC_INDEX, 0x04); port_byte_out(VGA_CRTC_DATA, 0x54);
    port_byte_out(VGA_CRTC_INDEX, 0x05); port_byte_out(VGA_CRTC_DATA, 0x80);
    port_byte_out(VGA_CRTC_INDEX, 0x06); port_byte_out(VGA_CRTC_DATA, 0x0B);
    port_byte_out(VGA_CRTC_INDEX, 0x07); port_byte_out(VGA_CRTC_DATA, 0x3E);
    port_byte_out(VGA_CRTC_INDEX, 0x09); port_byte_out(VGA_CRTC_DATA, 0x40);
    port_byte_out(VGA_CRTC_INDEX, 0x10); port_byte_out(VGA_CRTC_DATA, 0x00);
    port_byte_out(VGA_CRTC_INDEX, 0x11); port_byte_out(VGA_CRTC_DATA, 0x00);
    port_byte_out(VGA_CRTC_INDEX, 0x12); port_byte_out(VGA_CRTC_DATA, 0x0F);
    port_byte_out(VGA_CRTC_INDEX, 0x13); port_byte_out(VGA_CRTC_DATA, 0x00);
    port_byte_out(VGA_CRTC_INDEX, 0x14); port_byte_out(VGA_CRTC_DATA, 0x00);
    port_byte_out(VGA_CRTC_INDEX, 0x15); port_byte_out(VGA_CRTC_DATA, 0x00);
    port_byte_out(VGA_CRTC_INDEX, 0x16); port_byte_out(VGA_CRTC_DATA, 0x9C);
    port_byte_out(VGA_CRTC_INDEX, 0x17); port_byte_out(VGA_CRTC_DATA, 0x0E);

    // Lock CRTC registers
    port_byte_out(VGA_CRTC_INDEX, 0x11);
    temp = port_byte_in(VGA_CRTC_DATA) | 0x80;
    port_byte_out(VGA_CRTC_DATA, temp);
}

// Function to draw a pixel in the framebuffer
void draw_pixel(uint8_t x, uint8_t y, uint8_t color) {
    uint16_t offset = y * 640 + x;
    uint8_t bank = offset / 65536;
    uint16_t segment_offset = offset % 65536;

    set_bank(bank);
    uint8_t* video_memory = (uint8_t*)0xA0000 + segment_offset;
    *video_memory = color & 0xFF;
    *(video_memory + 1) = (color >> 8) & 0xFF;
}

// Function to clear the screen
void clear_vga_screen(uint8_t color) {
    for (int y = 0; y < 480; y++) {
        for (int x = 0; x < 640; x++) {
            draw_pixel(x, y, color);
        }
    }
}
// Функция для переключения банков памяти
void set_bank(uint8_t bank) {
    port_byte_out(0x3CD, bank); // Порт для переключения банков в режиме 640x480x16
}
