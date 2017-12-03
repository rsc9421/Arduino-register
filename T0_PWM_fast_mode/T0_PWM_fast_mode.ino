#include <avr/io.h>
#include <avr/interrupt.h>
//modo fast pwm permite manejar frecuencias mas altas
//frecuencia en modo fast pwm
//Fpwm=fosc/(512*prescaler)
//61.2=16000000/(256*1024)
void setup() {
TCCR0A=0;TCCR0B=0;
DDRD|=0b01000000;
TCCR0A|=0b10000011;//modo no invertido y fast pwm
TCCR0B|=0b00000101;//prescaler 1024 y start timer
OCR0A=45;
}

void loop() {
//for(i=0;i<256;i++){OCR0A=i;delay(30);}
//for(i=255;i>-1;i--){OCR0A=i;delay(30);}
//descomentar para ver que pasa :D
}
