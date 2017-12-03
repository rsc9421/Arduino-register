//este codigo funciona pero es ineficiente :D por favor usar 
//las funciones de los timer para generar pwm por hardware
//para una frecuencia f>60hz el led destallara tan rapido que el
//ojo humano no lo podra ver, por ej una f=100hz
//T=1/f=1/100=0.01s=10000us=T(on)+T(off)=4000+6000=>duty=40%
#include <avr/io.h>
#include <avr/interrupt.h>
char a=0;
unsigned int tmr(float tmr1){//tmr1 en microsegundos
  tmr1=tmr1/1000000;
  tmr1=1/tmr1;
  return 16000000/(1024*tmr1) -1; }
void setup() {
TCCR0B=0;TCCR0A=0;TIMSK0=0;
DDRD|=0b01000000;//PD6 como salida
TCCR0B|=0b00000101;//CTC mode
TCCR0A|=0b00000010;//1024 prescaler y start timer
TIMSK0|=0b00000010;
OCR0A=tmr(10);
}

void loop() {
  // put your main code here, to run repeatedly:

}
ISR(TIMER0_COMPA_vect){
  a=!a;
  if(a){OCR0A=tmr(4000);PORTD|=0b01000000;}
  if(!a){OCR0A=tmr(6000);PORTD&=0b10111111;}
  }
