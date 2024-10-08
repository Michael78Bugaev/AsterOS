; ------------------------------------------------------------------------------
; Guide:	01-KERNEL
; File:		ex00 / bootsect.asm
; Title:	Программа загрузочного сектора, которая загружает ядро, написанное
;			на C в 32-битный защищенный режим.
; ------------------------------------------------------------------------------
; Description:
; ------------------------------------------------------------------------------


[org 0x7c00]

KERNEL_OFFSET equ 0x1000	; Смещение в памяти, из которого мы загрузим ядро
	;Set 80x50 text mode...
	;mov ax, 4F02h
	;mov bx, 10Ah

	mov ax, 0x1112
	int 10h


	mov [BOOT_DRIVE], dl	; BIOS stores our boot drive in DL , so it ’s
							; best to remember this for later. (Remember that
							; the BIOS sets us the boot drive in 'dl' on boot)
	mov bp, 0x9000			; Устанавливаем стек
	mov sp, bp

	mov bx, MSG_REAL_MODE	; Печатаем сообщение
	call print_string

	call load_kernel		; Загружаем ядро
	call switch_to_pm		; Переключаемся в Защищенный Режим
	jmp $

%include "./boot/print_string.asm"		; ф. печати строки
%include "./boot/print_hex.asm"		    ; ф. печати 16-ричного числа
%include "./boot/disk_load.asm"		    ; ф. чтения диска
%include "./boot/print_string_pm.asm"	; ф. печати строки (32PM)
%include "./boot/switch.asm"			; ф. переключения в 32PM
%include "./boot/gdt.asm"				; таблица GDT

[bits 16]

load_kernel:
	mov bx, MSG_LOAD_KERNEL
	call print_string		; Печатаем сообщение о том, то мы загружаем ядро
							; Устанавливаем параметры для функции disk_load:
	mov bx, KERNEL_OFFSET	; Загрузим данные в место памяти по		TODO: disk_load main lookup
							; смещению KERNEL_OFFSET
	mov dh, 30				; Загрузим много секторов. *
	mov dl, [BOOT_DRIVE]	; Загрузим данные из BOOT_DRIVE (Возвращаем BOOT_DRIVE)
	call disk_load			; Вызываем функцию disk_load
	ret


[bits 32]					; Сюда мы попадем после переключения в 32PM

BEGIN_PM:
	mov ebx, MSG_PROT_MODE
	call print_string_pm	; Печатаем сообщение об успешной загрузке в 32PM
	call KERNEL_OFFSET		; Переходим в адрес, по которому загрузился код ядра
	jmp $


BOOT_DRIVE:			db 0
MSG_REAL_MODE:		db "Starting AsterOS...", 0
MSG_PROT_MODE:		db "Aster", 0
MSG_LOAD_KERNEL:	db "", 0

times 510-($-$$) db 0
dw 0xaa55

; ------
; * - Забавный факт: если загрузить меньше секторов, то мы столкнемся со
; странными ошибками когда будем писать ядро на Си. Например, аргументы
; функции могут быть повреждены, а строки "обрезаны".
