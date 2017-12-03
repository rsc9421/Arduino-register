void setup() {
TCCR1A=0;TCCR1B=0;
DDRB|=0b00100000;
TCCR1B|=0b00000100;
TCNT1 = 0;
}

void loop() {
if(TCNT1>=62499){PORTB^=(1<<PB5);TCNT1=0;}
//PORTB^=(1<<PB5);delay(500);
}
