# Atmega1284p-USART

This program basically prints out characters typed in the serial terminal.
******SETTINGS********
9600 baud rate for this chip (Atmega1284p)

configurations include 
- Uart0 of Atmega1284p
- 8 data bit
- 2 stop bits
- Baud rate calculation [ 2MHz(FOSC)/16/9600(BAUD)-1 ]
- U2X0=1 for double speed mode
