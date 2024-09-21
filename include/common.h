/*------------------------------------------------------------------------------
*	Guide:	01-KERNEL
*	File:	ex01 / common.h
*	Title:	Всякие удобные константы, типы и функции
* ------------------------------------------------------------------------------
*	Description:
* ----------------------------------------------------------------------------*/
#include <stdint.h>

#ifndef COMMON_H
#define COMMON_H

// Указанная размерность характерна только для архитектуры x86
// Подробнее про типы данных: https://metanit.com/cpp/c/2.3.php

typedef unsigned int	u32;	// беззнаковое целое число размером 32 бита
typedef 		 int	s32; 	// целое число 32 бита со знаком
typedef unsigned short	u16;	// и т.д.
typedef 		 short	s16;
typedef unsigned char	u8;
typedef 		 char	s8;

void	memcpy(u8 *dest, u8 *src, u32 bytes);

struct InterruptRegisters
{
    uint32_t cr2;
    uint32_t ds;
    uint32_t edi, esi, ebp, esp, ebx, edx, ecx, eax;
    uint32_t int_no, err_code;
    uint32_t eip, csm, eflags, useresp, ss;
};

void halt();
void memset(void *dest, char val, uint32_t count);


#endif
