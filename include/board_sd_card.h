#ifndef BOARD_SD_CARD_H
#define BOARD_SD_CARD_H

#include <sd_protocol.h>

u8 board_sd_card_get_status(void);

u8 board_sd_card_init(sd_card* sd);

#endif  // BOARD_SD_CARD_H