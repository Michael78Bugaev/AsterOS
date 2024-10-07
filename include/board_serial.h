#ifndef BOARD_SERIAL_H
#define BOARD_SERIAL_H

#include <stdint.h>

typedef enum {
    SERIAL_PORT_0,
    SERIAL_PORT_1,
    SERIAL_PORT_2,
    SERIAL_PORT_3,
    // Add more serial ports as needed
} serial_port_e;

typedef enum {
    SERIAL_BAUD_RATE_9600,
    SERIAL_BAUD_RATE_19200,
    SERIAL_BAUD_RATE_38400,
    SERIAL_BAUD_RATE_57600,
    SERIAL_BAUD_RATE_115200,
    // Add more baud rates as needed
} serial_baud_rate_e;

typedef enum {
    SERIAL_DATA_BITS_5,
    SERIAL_DATA_BITS_6,
    SERIAL_DATA_BITS_7,
    SERIAL_DATA_BITS_8,
    // Add more data bits as needed
} serial_data_bits_e;

typedef enum {
    SERIAL_PARITY_NONE,
    SERIAL_PARITY_EVEN,
    SERIAL_PARITY_ODD,
    // Add more parity modes as needed
} serial_parity_e;

typedef enum {
    SERIAL_STOP_BITS_1,
    SERIAL_STOP_BITS_2,
    // Add more stop bits as needed
} serial_stop_bits_e;

typedef struct {
    uint8_t (*init)(serial_port_e port, serial_baud_rate_e baud_rate, serial_data_bits_e data_bits, serial_parity_e parity, serial_stop_bits_e stop_bits);
    uint8_t (*write)(serial_port_e port, const uint8_t* buffer, uint32_t count);
    uint8_t (*read)(serial_port_e port, uint8_t* buffer, uint32_t count);
    uint8_t (*get_status)(serial_port_e port);
} serial_interface_t;

#endif  // BOARD_SERIAL_H