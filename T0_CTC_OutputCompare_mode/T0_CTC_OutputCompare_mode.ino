#include <avr/io.h>
#include <avr/interrupt.h>
unsigned int tmr(float tmr1){//tmr1 en microsegundos
  tmr1=tmr1/1000000;
  tmr1=1/tmr1;
  return 16000000/(1024*tmr1) -1; }
volatile int a=0;
void setup() {
TCCR0A=0;TCCR0B=0;
DDRD|=0b01000000;//PD6 como salida
TCCR0A|=0b01000010;//toggle pin OC0A y CTC modo
TCCR0B|=0b00000101;//1024 prescaler y start timer
OCR0A=255;
}

void loop() {
  // put your main code here, to run repeatedly:

}

