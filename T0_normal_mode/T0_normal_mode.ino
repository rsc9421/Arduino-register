uint16_t tmr(float useg){

return ((16000000/1024)*(useg/1000000))-1;
}
  uint8_t a=0;
void setup() {
TCCR0A=0;TCCR0B=0;
DDRB|=0b00100000;
TCCR0B|=0b00000101;
TCNT0=0;
}

void loop() {
if(TCNT0==tmr(10000)){a++;TCNT0=0;}
if(a==100){PORTB^=0b00100000;a=0;}

}
