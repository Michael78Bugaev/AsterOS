/*------------------------------------------------------------------------------
*	Guide:	01-KERNEL
*	File:	ex01 / drivers / screen.c
*	Title:	Функции работы с экраном
* ------------------------------------------------------------------------------
*	Description:
* ----------------------------------------------------------------------------*/


#include <screen.h>
#include <lowlevel_io.h>
#include <common.h>
#include <utils.h>
#include <stdint.h>


void	kprint(uint8_t *str)
{
	/* Функция печати строки */
	
	// uint8_t *str: указатель на строку (на первый символ строки). Строка должна
	// быть null-terminated.

	while (*str)
	{
		putchar(*str, 0x07);
		str++;
	}
}

void kprint_int(int num) {
    // Convert the integer to a string
    char str[12]; // 12 characters should be enough for a 32-bit integer
    int i = 0;
    if (num == 0) {
        str[i++] = '0';
    } else {
        if (num < 0) {
            str[i++] = '-';
            num = -num;
        }
        while (num > 0) {
            str[i++] = (num % 10) + '0';
            num /= 10;
        }
    }
    str[i] = '\0'; // null-terminate the string

    // Reverse the string
    int start = 0;
    int end = i - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }

    // Print the string
    kprint((uint8_t *)str);
}
void kprint_int_colored(int num, uint8_t attr) {
    // Convert the integer to a string
    char str[12]; // 12 characters should be enough for a 32-bit integer
    int i = 0;
    if (num == 0) {
        str[i++] = '0';
    } else {
        if (num < 0) {
            str[i++] = '-';
            num = -num;
        }
        while (num > 0) {
            str[i++] = (num % 10) + '0';
            num /= 10;
        }
    }
    str[i] = '\0'; // null-terminate the string

    // Reverse the string
    int start = 0;
    int end = i - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }

    // Print the string
    kprint_colored((uint8_t *)str, attr);
}

void	putchar(uint8_t character, uint8_t attribute_byte)
{
	/* Более высокоуровневая функция печати символа */

	// uint8_t character: байт, соответствующий символу
	// uint8_t attribute_byte: байт, соответствующий цвету текста/фона символа

	uint16_t offset;

	offset = get_cursor();
	if (character == '\n')
	{
		// Переводим строку.
		if ((offset / 2 / MAX_COLS) == (MAX_ROWS - 1)) 
			scroll_line();
		else
			set_cursor((offset - offset % (MAX_COLS*2)) + MAX_COLS*2);
	}
	else if (character == '\b')
	{
		uint8_t x = get_cursor_x(), y = get_cursor_y();
		if (x > 0 && x != 0)
		{
			set_cursor_xy(x - 2, y);
			putchar(' ', 0x07);
			set_cursor_xy(x-2, y);
		}
	}
	else 
	{
		if (offset == (MAX_COLS * MAX_ROWS * 2)) scroll_line();
		write(character, attribute_byte, offset);
		set_cursor(offset+2);
	}
}

void	scroll_line()
{
	/* Функция скроллинга */

	uint8_t i = 1;		// Начинаем со второй строки.
	uint16_t last_line;	// Начало последней строки.

	while (i < MAX_ROWS)
	{
		memcpy(
			(uint8_t *)(VIDEO_ADDRESS + (MAX_COLS * i * 2)),
			(uint8_t *)(VIDEO_ADDRESS + (MAX_COLS * (i-1) * 2)),
			(MAX_COLS*2)
		);
		i++;
	}

	last_line = (MAX_COLS*MAX_ROWS*2) - MAX_COLS*2;
	i = 0;
	while (i < MAX_COLS)
	{
		write('\0', WHITE_ON_BLACK, (last_line + i * 2));
		i++;
	}
	set_cursor(last_line);
}

void	clear_screen()
{
	/* Функция очистки экрана */

	uint16_t	offset = 0;
	while (offset < (MAX_ROWS * MAX_COLS * 2))
	{
		write('\0', WHITE_ON_BLACK, offset);
		offset += 2;
	}
	set_cursor(0);
}

void	write(uint8_t character, uint8_t attribute_byte, uint16_t offset)
{
	/* Функция печати символа на экран с помощью VGA по адресу 0xb8000 */

	// uint8_t character: байт, соответствующий символу
	// uint8_t attribute_byte: байт, соответствующий цвету текста/фона символа
	// uint16_t offset: смещение (позиция), по которому нужно распечатать символ
	
	uint8_t *vga = (uint8_t *) VIDEO_ADDRESS;
	vga[offset] = character;
	vga[offset + 1] = attribute_byte;
}

uint16_t		get_cursor()
{
	/* Функция, возвращающая позицию курсора (char offset). */

	port_byte_out(REG_SCREEN_CTRL, 14);				// Запрашиваем верхний байт
	uint8_t high_byte = port_byte_in(REG_SCREEN_DATA);	// Принимаем его
	port_byte_out(REG_SCREEN_CTRL, 15);				// Запрашиваем нижний байт
	uint8_t low_byte = port_byte_in(REG_SCREEN_DATA);	// Принимаем и его
	// Возвращаем смещение умножая его на 2, т.к. порты возвращают смещение в
	// клетках экрана (cell offset), а нам нужно в символах (char offset), т.к.
	// на каждый символ у нас 2 байта
	return (((high_byte << 8) + low_byte) * 2);
}

void	set_cursor(uint16_t pos)
{
	/* Функция, устаналивающая курсор по смещнию (позиции) pos */
	/* Поиграться с битами можно тут http://bitwisecmd.com/ */

	// конвертируем в cell offset (в позицию по клеткам, а не символам)
	pos /= 2;

	// Указываем, что будем передавать верхний байт
	port_byte_out(REG_SCREEN_CTRL, 14);
	// Передаем верхний байт
	port_byte_out(REG_SCREEN_DATA, (uint8_t)(pos >> 8));
	// Указываем, что будем передавать нижний байт
	port_byte_out(REG_SCREEN_CTRL, 15);
	// Передаем нижний байт
	port_byte_out(REG_SCREEN_DATA, (uint8_t)(pos & 0xff));
}

uint8_t get_cursor_x()
{	/* Функция, возвращающая позицию курсора (x, y). */

    port_byte_out(REG_SCREEN_CTRL, 14);				// Запрашиваем верхний байт
    uint8_t high_byte = port_byte_in(REG_SCREEN_DATA);	// Принимаем его
    port_byte_out(REG_SCREEN_CTRL, 15);				// Запрашиваем нижний байт
    uint8_t low_byte = port_byte_in(REG_SCREEN_DATA);	// Принимаем и его

    uint16_t offset = ((high_byte << 8) + low_byte) * 2;
    return offset % MAX_COLS;
}
uint8_t get_cursor_y()
{
	/* Функция, возвращающая позицию курсора (x, y). */

    port_byte_out(REG_SCREEN_CTRL, 14);				// Запрашиваем верхний байт
    uint8_t high_byte = port_byte_in(REG_SCREEN_DATA);	// Принимаем его
    port_byte_out(REG_SCREEN_CTRL, 15);				// Запрашиваем нижний байт
    uint8_t low_byte = port_byte_in(REG_SCREEN_DATA);	// Принимаем и его

    uint16_t offset = ((high_byte << 8) + low_byte) * 2;
    return offset / MAX_COLS;
}
void set_cursor_xy(uint8_t x, uint8_t y)
{
	/* Функция, устаналивающая курсор по координатам (x, y) */

    uint16_t offset = y * MAX_COLS + x;
    offset /= 2; // convert to cell offset

    // Указываем, что будем передавать верхний байт
    port_byte_out(REG_SCREEN_CTRL, 14);
    // Передаем верхний байт
    port_byte_out(REG_SCREEN_DATA, (uint8_t)(offset >> 8));
    // Указываем, что будем передавать нижний байт
    port_byte_out(REG_SCREEN_CTRL, 15);
    // Передаем нижний байт
    port_byte_out(REG_SCREEN_DATA, (uint8_t)(offset & 0xff));
}
void draw_text(uint8_t x, uint8_t y, uint8_t *str, uint8_t attr)
{
	uint16_t old_offs = get_cursor();

	set_cursor_xy(x, y);
	kprint_colored(str, attr);

	set_cursor(old_offs);
}
void draw_text_int(uint8_t x, uint8_t y, int str, uint8_t attr)
{
	uint16_t old_offs = get_cursor();
	set_cursor_xy(x, y);
	kprint_int_colored(str, attr);
	set_cursor(old_offs);
}
void kprint_float_colored(float num, int decimal_places, uint8_t color) {
    int int_part = (int)num;
    float frac_part = num - int_part;

    char buffer[32];

    // Print the integer part
    //itoa(int_part, buffer, 10);
    kprint_colored(buffer, color);

    // Print the decimal point
    kprint_colored(".", color);

    // Print the fractional part
    for (int i = 0; i < decimal_places; i++) {
        frac_part *= 10;
        int digit = (int)frac_part;
        frac_part -= digit;
        char digit_str[2] = { '0' + digit, '\0' };
        kprint_colored(digit_str, color);
    }
}