/* * TEST-USART.c * * Created: 8/30/2017 12:14:36 PM * Author : madiv */ #include <avr/io.h>
#define FOSC 1000000 // Clock Speed#define BAUD 4800#define MYUBRR (((FOSC / (BAUD * 16UL))) - 1)
void USART_Init( unsigned int ubrr);void USART_Transmit( unsigned char data );unsigned char USART_Receive( void );
//char String[]="12345--Hello world--"; 
int main( void ){	USART_Init(MYUBRR);	while (1)	{		USART_Transmit(USART_Receive());	}	return 0;}
void USART_Init( unsigned int ubrr){	/*Set baud rate */	UBRR0H = (unsigned char)(ubrr>>8);	UBRR0L = (unsigned char)ubrr;	/* Enable receiver and transmitter */	UCSR0B = (1<<RXEN0)|(1<<TXEN0);	/* Set frame format: 8data, 2stop bit */	UCSR0C = (1<<USBS0)|(3<<UCSZ00);}
void USART_Transmit( unsigned char data ){	/* Wait for empty transmit buffer */	while ( !( UCSR0A & (1<<UDRE0)) );	;	/* Put data into buffer, sends the data */	UDR0 = data;}
unsigned char USART_Receive( void ){	/* Wait for data to be received */	while ( !(UCSR0A & (1<<RXC0)));	/* Get and return received data from buffer */	return UDR0;}