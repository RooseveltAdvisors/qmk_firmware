#define SERIAL_USART_TX_PIN GP1
#define SERIAL_USART_RX_PIN GP0
#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_PIO_USE_PIO0

// PMW3360 sensor CPI (100-12000, step 100). Default is 1600.
// 2000 gives snappier traversal while staying precise.
#define PMW33XX_CPI 2000