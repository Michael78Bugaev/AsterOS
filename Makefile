CFG_FILE = .config

include ${CFG_FILE}

run: ${OPEROS_FILE}
	chmod 777 ${OPEROS_FILE}
	@qemu-system-i386 -fda ${OPEROS_FILE}

${OPEROS_FILE}: $(BUILD_DIR)bootsect.bin $(BUILD_DIR)kernel.bin
	@cat $(BUILD_DIR)bootsect.bin $(BUILD_DIR)kernel.bin > ${OPEROS_FILE}

$(BUILD_DIR)bootsect.bin:
	@$(ASM) $(BOOT_DIR)bootsect.asm $(ASM_FLAGS_BIN) -o $(BUILD_DIR)bootsect.bin 

$(BUILD_DIR)kernel.bin: $(BUILD_DIR)kernel_entry.o $(BUILD_DIR)kernel.o $(BUILD_DIR)idts.o
	@$(LD) -o $(BUILD_DIR)kernel.bin -Ttext 0x1000 $(BUILD_DIR)kernel_entry.o $(BUILD_DIR)idts.o $(O_FILES) --oformat binary

$(BUILD_DIR)kernel_entry.o:
	@$(ASM) $(BOOT_DIR)kernel_entry.asm  $(ASM_FLAGS_ELF) -o $(BUILD_DIR)kernel_entry.o

$(BUILD_DIR)idts.o:
	@$(ASM) $(BOOT_DIR)idt.asm $(ASM_FLAGS_ELF) -o $@

$(BUILD_DIR)kernel.o:
	@$(CC) ${CFLAGS} $(C_FILES)

clean:
	rm $(BUILD_DIR)*.bin $(BUILD_DIR)*.o