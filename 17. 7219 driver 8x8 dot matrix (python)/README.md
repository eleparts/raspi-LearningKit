# MAX7219 driver 8x8 dot matrix

## GPIO pin-outs

The breakout board has an two headers to allow daisy-chaining:  

| Board Pin | Name | Remarks | RPi Pin | RPi Function (#BCM) |
|--------:|:-----|:--------|--------:|--------------|
| 1 | VCC | +5V Power | 2, 4 | 5V0 |
| 2 | GND | Ground | 6 | GND |
| 3 | DIN | Data In | 19 | GPIO 10 (MOSI) |
| 4 | CS | Chip Select | 24 | GPIO 8 (SPI CS0) |
| 5 | CLK | Clock | 23 | GPIO 11 (SPI CLK) |

