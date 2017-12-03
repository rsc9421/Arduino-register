void setup() {
 DDRB|=0b00100000;
 DDRC|=0b00000000;//pc0 entrada
 PORTC|=0b00000001;//habilita pull up en pc0
}

void loop() {
if(!(PINC & 0b00000001)){PORTB|=0b00100000;}
else PORTB&=~(0b00100000);
}
