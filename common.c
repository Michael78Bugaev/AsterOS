/*------------------------------------------------------------------------------
*	Guide:	01-KERNEL
*	File:	ex01 / common.c
*	Title:	Всякие удобные константы, типы и функции
* ------------------------------------------------------------------------------
*	Description:
* ----------------------------------------------------------------------------*/


#include <common.h>
#include <stdint.h>

void	memcpy(u8 *src, u8 *dest, u32 bytes)
{
	u32 i;

	i = 0;
	while (i < bytes)
	{
		dest[i] = src[i];
		i++;
	}
}
void halt()
{
	while (1);
}
void memset(void *dest, char val, uint32_t count)
{
	char *temp = (char*)dest;
	for (; count != 0; count--)
	{
		*temp++ = val;
	}
}