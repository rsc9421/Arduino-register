//+info http://www.ermicro.com/blog/?p=1971
#include <avr/io.h>
#include <avr/interrupt.h>
//este modo es especialmente usado para controlar 
//motores y audio, comparado con el modo fast
//este modo trabaja a la mitad de frecuencia
//frecuencia en modo phase correct
//Fpwm=fosc/(512*prescaler)
//30.6=16000000/(512*1024)
void setup() {
TCCR0A=0;TCCR0B=0;
DDRD|=0b01000000;
TCCR0A|=0b10000001;//modo no invertido y phase correct 
TCCR0B|=0b00000101;//prescaler 1024 y start timer
OCR0A=45;//cualquier valor de 0-255
}

void loop() {
  //no hace nada, pwm es puro hardware en avr :D
}
