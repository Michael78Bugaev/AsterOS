; ------------------------------------------------------------------------------
; Guide:	00-BOOT-SECTOR
; File:		ex08 / gdt.asm
; Title:	Определяем GDT (глобальная таблица дескрипторов)
; ------------------------------------------------------------------------------
; Description:
; 	Способ, которым процессор переводит логический адрес в физический, в
; 	32-битном защищенном режиме отличается от 16-битного реального режима.
; 	Вместо того, чтобы умножить значение регистра сегмента на 16 и прибавить к
; 	этому "смещение" (offset), регистр сегмента становится индексом 
; 	определенного дескриптора сегмента в GDT.
; 	Дескриптор сегмента - это 8-битная структура, которая определяет свойства
; 	этого сегмента:
; 		- Base address (32 bits), определяющий откуда сегмент начинается в
; 		физической памяти.
; 		- Segment Limit (20 bits), определяющий размер сегмента
;		- Различные флаги, которые устанавливают каким образом процессор будет
; 		"относиться" к сегментам, например уровень привилегий и т.д.
;
; 	Флаги:
;	* 1-ые флаги:
; 		- present flag (флаг присутствия). Если его значение "1", то это 
;		указывает, что сегмент присутствует в памяти (это нужно для виртуальной 
;		памяти)
;		- privilege flag (флаг привилегии). Значение "0" - самый высокий уровень
;		привилегии
;		- descriptor type (тип дескриптора). "1" - для сегмента кода или 
;		сегмента данных
; 	* Флаги типа:
;		- code (флаг кода). "1" - для кода, "0" - для даннных
;		- conformig (флаг подчинения). "0" - чтобы код в другом сегменте с
;		более низким уровнем привилегий не смог вызвать код из этого сегмента - 
;		это ключ к защите памяти (memory protection).
;		- readable (читаемость). "1" - если читаемый, "0" - только исполняемый.
;		- writable. Разрешает сегменту данных быть записываемым, в противном
;		случае, он будет доступен только для чтения.
;		- accessed (флаг доступа). Этот флаг устанавливается, когда происходит
; 		обращение к сегменту.
;		- expand down. Флаг (бит), позволяющий сегменту расширяться вниз.
;	* 2-ые флаги:
;		- granulariy (гранулярность). "0" - байтовая гранулярность, лимит
; 		задается в байтах, если "1" - страничная гранулярность, в 4кб блоках.
;		Если выбрать страничную гранулярность и установить значение лимита как
;		0xfffff, то лимит умножится на 16*16*16 (4кб), и лимит станет 0xfffff000
; 		позволяя нашему сегменту занять 4гб места в памяти.
;		- 32-bit default. "1" - т.к. наш сегмент будет содержать 32-битный код.
;		- 64-bit code segment. "0" - т.к. не используется на 32-битных 
;		процессорах.
;		- AVL (available). Определяет доступность сегмента для использования 
;		системным программным обеспечением (используются только ОС).
; ------------------------------------------------------------------------------

gdt_start:					; Эта пустая метка нужно для того чтобы удобнее
							; посчитать размер GDT для ее дескриптора 
							; (end - start)

gdt_null:					; Необходимый нулевой дескриптор для GDT
	dd 0x0					; dd - define double (двойное слово, т.е. 4 байта)
	dd 0x0

gdt_code:					; Определяем дескриптор сегмента кода
	dw 0xffff				; Limit (bits 0-15)
	dw 0x0					; Base (bits 0-15)
	db 0x0					; Base (bits 16-23)
	db 10011010b			; Первые флаги + флаги типа (смотрим по битам)
							; present: 1, privilege: 00, descriptor type: 1
							; code: 1, conforming: 0, readable: 1, accessed: 0
	db 11001111b			; Вторые флаги + длина сегмента (bits 16-19):
							; granularity: 1, 32-bit default: 1,
							; 64-bit default: 0, AVL: 0
	db 0x0					; Base (bits 24-31)

gdt_data:					; Определяем дескриптор сегмента кода
	dw 0xffff				; Limit (bits 0-15)
	dw 0x0					; Base (bits 0-15)
	db 0x0					; Base (bits 16-23)
	db 10010010b			; Первые флаги + флаги типа (смотрим по битам)
	db 11001111b			; Вторые флаги + длина сегмента (bits 16-19)
	db 0x0					; Base (bits 24-31)

gdt_end:					; Пустая метка


gdt_descriptor:						; дескриптор GDT
	dw gdt_end - gdt_start - 1		; Размер GDT
	dd gdt_start					; Адрес начала GDT


CODE_SEG equ gdt_code - gdt_start	; Определяем некоторые константы. 
DATA_SEG equ gdt_data - gdt_start	; Они понадобятся для регистров сегментов в
									; 32-битном защищенном режиме. Например,
									; когда мы установим регистр DS = 0x10 (т.е
									; 16 байтов) в этом режиме, процессор
									; поймет что мы хотим использовать сегмент,
									; находящийся в смещении 0x10 в нашем GDT,
									; т.е. в нашем случае это сегмент данных
									; (0x0 -> NULL, 0x08 -> сегмент кода,
									; 0x10 -> сегмент данных)