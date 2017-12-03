void setup() {
UCSR0B=0;UCSR0A=0;UCSR0C=0;
UCSR0B|=0b00011000;//habilitar RX y TX
UCSR0C|=0b00000110;//modo asincrono, sin paridad
//stop bit=1, data bit=8
UBRR0=8;//115200 baudios
//formula=>UBRR0=fosc/(16*baudios) si esta en modo asincrono
}

void loop() {
while(!(UCSR0A&0b00100000));
UDR0='b';
delay(500);
}

