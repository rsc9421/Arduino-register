#include <avr/io.h>
#include <avr/interrupt.h>
unsigned int tmr(float tmr1){
  tmr1=tmr1/1000000;
  tmr1=1/tmr1;
  return 16000000/(1024*tmr1) -1; }
volatile int a=0;
void setup() {
TCCR0A=0;TCCR0B=0;TIMSK0=0;
DDRB|=0b00100000;
TCCR0A|=0b00000010;//ctc
TCCR0B|=0b00000101;//1024 prescaler
TIMSK0|=0b00000010;//habilitar interrupcion 0CR0A
OCR0A=tmr(10000);
//sei();
SREG|=0b10000000;
}

void loop() {
  // put your main code here, to run repeatedly:

}
ISR(TIMER0_COMPA_vect){//cada vez que TCNT0=OCR0A se produce 
  //esta interrupcion
  a++;
  if(a==50){PORTB^=0b00100000;a=0;}
  }
