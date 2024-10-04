/*------------------------------------------------------------------------------
*	Guide:	01-KERNEL
*	File:	ex01 / drivers / screen.h
*	Title:	Заголовочный файл для screen.c
* ------------------------------------------------------------------------------
*	Description:
* ----------------------------------------------------------------------------*/


#include <common.h>
#include <stdint.h>

#define VIDEO_ADDRESS 0xb8000	// Адрес начала VGA для печати символов
#define MAX_ROWS 25 		// макс. строк
#define MAX_COLS 80				// макс. столбцов

#define WHITE_ON_BLACK 0x07		// 0x0 == white fg, 0xf == black bg

// Адреса I/O портов для взаимодействия с экраном.
#define REG_SCREEN_CTRL 0x3d4	// этот порт для описания данных
#define REG_SCREEN_DATA 0x3d5	// а этот порт для самих данных

void	kprint(uint8_t *str);
void    kprint_int(int num);
void    kprint_int_colored(int num, uint8_t attr);
void	putchar(uint8_t character, uint8_t attribute_byte);
void	clear_screen();
void	write(uint8_t character, uint8_t attribute_byte, uint16_t offset);
void	scroll_line();
uint16_t		get_cursor();
void	set_cursor(uint16_t pos);
uint8_t get_cursor_x();
uint8_t get_cursor_y();
void set_cursor_xy(uint8_t x, uint8_t y);
void draw_text(uint8_t x, uint8_t y, uint8_t *str, uint8_t attr);
void draw_text_int(uint8_t x, uint8_t y, int str, uint8_t attr);
void disable_cursor();
void kprint_timetick();