void setup() {
/*
UCSR0B=0;UCSR0A=0;UCSR0C=0;
UCSR0B|=0b00011000;
UCSR0C|=0b00000110;
UBRR0=8;
*/
Serial.begin(250000);
ADCSRA=0;ADMUX=0;
ADMUX|=0b01000000;//canal=ADC0, Vref=AVcc
ADCSRA|=0b10001111;//ADC enable, prescaler=128
ADCSRA|=0b01000000;
}

void loop() {


}
ISR(ADC_vect){
Serial.println(ADC);
ADCSRA|=0b01000000;
  }
