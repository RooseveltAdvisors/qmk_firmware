#define SERIAL_USART_TX_PIN GP1
#define SERIAL_USART_RX_PIN GP0
#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_PIO_USE_PIO0

// PMW3360 sensor CPI (100-12000, step 100). Default is 1600.
// 2000 gives snappier traversal while staying precise.
#define PMW33XX_CPI 2000

// Faster SPI clock: 125MHz / 32 = ~3.9MHz (PMW3360 max is 4MHz).
// Default divisor is 64 (~1.95MHz). Halving the divisor halves SPI
// transaction time, freeing more slave CPU for USART handling.
#define PMW33XX_SPI_DIVISOR 32