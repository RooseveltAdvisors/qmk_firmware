#define SERIAL_USART_TX_PIN GP1
#define SERIAL_USART_RX_PIN GP0
#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_PIO_USE_PIO0

// PMW3360 sensor CPI (100-12000, step 100).
// 800 matches Svalboard Vial firmware EEPROM default (dpi_choices[] index 3).
#define PMW33XX_CPI 800