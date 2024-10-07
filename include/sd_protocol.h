#ifndef SD_PROTOCOL_H
#define SD_PROTOCOL_H

#include <stdint.h>
#include <stdbool.h>

typedef enum {
    SD_CARD_TYPE_SD,
    SD_CARD_TYPE_SDHC,
    SD_CARD_TYPE_SDXC
} sd_card_type_t;

typedef enum {
    SD_CARD_STATUS_READY,
    SD_CARD_STATUS_INITIALIZING,
    SD_CARD_STATUS_INITIALIZED,
    SD_CARD_STATUS_ERROR
} sd_card_status_t;

typedef enum {
    SD_CARD_CMD_GO_IDLE_STATE = 0,
    SD_CARD_CMD_SEND_OP_COND = 1,
    SD_CARD_CMD_SEND_IF_COND = 8,
    SD_CARD_CMD_SEND_CSD = 9,
    SD_CARD_CMD_SEND_CID = 10,
    SD_CARD_CMD_STOP_TRANSMISSION = 12,
    SD_CARD_CMD_SEND_STATUS = 13,
    SD_CARD_CMD_SET_BLOCKLEN = 16,
    SD_CARD_CMD_READ_SINGLE_BLOCK = 17,
    SD_CARD_CMD_READ_MULTIPLE_BLOCK = 18,
    SD_CARD_CMD_WRITE_SINGLE_BLOCK = 24,
    SD_CARD_CMD_WRITE_MULTIPLE_BLOCK = 25,
    SD_CARD_CMD_PROGRAM_CSD = 27,
    SD_CARD_CMD_SET_WRITE_PROT = 28,
    SD_CARD_CMD_CLR_WRITE_PROT = 29,
    SD_CARD_CMD_SEND_WRITE_PROT = 30,
    SD_CARD_CMD_SD_SEND_OP_COND = 41,
    SD_CARD_CMD_SET_CLR_CARD_DETECT = 42,
    SD_CARD_CMD_SEND_SCR = 51
} sd_card_command_t;

typedef enum {
    SD_CARD_RESPONSE_R1,
    SD_CARD_RESPONSE_R1b,
    SD_CARD_RESPONSE_R2,
    SD_CARD_RESPONSE_R3,
    SD_CARD_RESPONSE_R4,
    SD_CARD_RESPONSE_R5,
    SD_CARD_RESPONSE_R6,
    SD_CARD_RESPONSE_R7
} sd_card_response_t;

typedef struct {
    uint8_t  cs_pin;      // Chip select pin
    uint8_t  clk_pin;     // Clock pin
    uint8_t  mosi_pin;    // Master out slave in pin
    uint8_t  miso_pin;    // Master in slave out pin
    sd_card_type_t card_type;   // Type of SD card (SD, SDHC, SDXC)
    sd_card_status_t card_status; // Status of the SD card (initialized, ready, etc.)
    uint32_t card_size;         // Size of the SD card in bytes
    uint16_t card_block_size;   // Block size of the SD card in bytes
    bool card_is_initialized;   // Flag indicating if the SD card is initialized
    bool card_is_write_protected; // Flag indicating if the SD card is write-protected
    uint8_t  card_cid[16];      // Card identification number
    uint8_t  card_csd[16];      // Card-specific data
    uint8_t  card_scr[8];       // SD card configuration register
    uint8_t  card_ocr;          // Operating condition register
    uint8_t  card_rca;          // Relative card address
    uint8_t  card_dsr;          // Driver stage register
    uint8_t  card_erase_count;  // Erase count
    uint8_t  card_erase_size;   // Erase size
    uint8_t  card_write_protect; // Write protection
    uint8_t  card_lock_stat;    // Lock status
    uint8_t  card_vol_stat;     // Volume status
    uint8_t  card_switch_stat;  // Switch status
    uint8_t  card_erase_stat;   // Erase status
    uint8_t  card_wp_grp_size;  // Write protect group size
    uint8_t  card_wp_grp_enable; // Write protect group enable
    uint8_t  card_manufacturer; // Manufacturer ID
    uint8_t  card_ocr_bits;     // OCR bits
    uint8_t  card_scr_bits;     // SCR bits
    uint8_t  card_cs_pin_state; // Chip select pin state
    uint8_t  card_clk_pin_state; // Clock pin state
    uint8_t  card_mosi_pin_state; // Master out slave in pin state
    uint8_t  card_miso_pin_state; // Master in slave out pin state
} sd_card;

#endif  // SD_PROTOCOL_H